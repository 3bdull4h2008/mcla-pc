#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82739C34"))) PPC_WEAK_FUNC(sub_82739C34);
PPC_FUNC_IMPL(__imp__sub_82739C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739C38"))) PPC_WEAK_FUNC(sub_82739C38);
PPC_FUNC_IMPL(__imp__sub_82739C38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x82739c70
	if (!cr6.eq) goto loc_82739C70;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-5852(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5852);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82739c60
	if (cr6.lt) goto loc_82739C60;
	// li r11,0
	r11.s64 = 0;
loc_82739C60:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82739c74
	if (!cr6.eq) goto loc_82739C74;
loc_82739C70:
	// li r11,0
	r11.s64 = 0;
loc_82739C74:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// ori r8,r9,16948
	ctx.r8.u64 = ctx.r9.u64 | 16948;
	// lwz r10,-10012(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// or r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 | r11.u64;
	// clrlwi r3,r6,24
	ctx.r3.u64 = ctx.r6.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739C94"))) PPC_WEAK_FUNC(sub_82739C94);
PPC_FUNC_IMPL(__imp__sub_82739C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739C98"))) PPC_WEAK_FUNC(sub_82739C98);
PPC_FUNC_IMPL(__imp__sub_82739C98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x82739ce4
	if (!cr6.eq) goto loc_82739CE4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f0,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f13,-5852(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5852);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82739cd0
	if (cr6.lt) goto loc_82739CD0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f12,-5856(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82739cd4
	if (cr6.lt) goto loc_82739CD4;
loc_82739CD0:
	// li r11,0
	r11.s64 = 0;
loc_82739CD4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82739ce8
	if (!cr6.eq) goto loc_82739CE8;
loc_82739CE4:
	// li r11,0
	r11.s64 = 0;
loc_82739CE8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// ori r7,r9,16948
	ctx.r7.u64 = ctx.r9.u64 | 16948;
	// lwz r11,-10012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// lbzx r6,r11,r7
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// and r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 & ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739D10"))) PPC_WEAK_FUNC(sub_82739D10);
PPC_FUNC_IMPL(__imp__sub_82739D10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x82739d54
	if (!cr6.eq) goto loc_82739D54;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f12,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f0,-5856(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,-5852(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5852);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x82739d44
	if (!cr6.lt) goto loc_82739D44;
	// li r11,0
	r11.s64 = 0;
loc_82739D44:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82739d58
	if (cr6.eq) goto loc_82739D58;
loc_82739D54:
	// li r11,1
	r11.s64 = 1;
loc_82739D58:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// ori r7,r9,16948
	ctx.r7.u64 = ctx.r9.u64 | 16948;
	// lwz r11,-10012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// lbzx r6,r11,r7
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// and r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 & ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739D80"))) PPC_WEAK_FUNC(sub_82739D80);
PPC_FUNC_IMPL(__imp__sub_82739D80) {
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
	// li r31,0
	r31.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82739ecc
	if (cr6.eq) goto loc_82739ECC;
	// lhz r9,172(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 172);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82739ecc
	if (!cr6.gt) goto loc_82739ECC;
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
loc_82739DB8:
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r6,r4
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r4.u32, xer);
	// beq cr6,0x82739dd8
	if (cr6.eq) goto loc_82739DD8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82739db8
	if (cr6.lt) goto loc_82739DB8;
	// b 0x82739ecc
	goto loc_82739ECC;
loc_82739DD8:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82739ecc
	if (cr6.lt) goto loc_82739ECC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r7,160(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// lfs f12,-5856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-5852(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -5852);
	f0.f64 = double(temp.f32);
	// bne cr6,0x82739e2c
	if (!cr6.eq) goto loc_82739E2C;
	// lfs f13,164(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82739e18
	if (cr6.lt) goto loc_82739E18;
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// blt cr6,0x82739e1c
	if (cr6.lt) goto loc_82739E1C;
loc_82739E18:
	// li r11,0
	r11.s64 = 0;
loc_82739E1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82739e30
	if (!cr6.eq) goto loc_82739E30;
loc_82739E2C:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82739E30:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// ori r6,r8,16948
	ctx.r6.u64 = ctx.r8.u64 | 16948;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lbzx r8,r11,r6
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r6.u32);
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r6,r11,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// and r31,r6,r9
	r31.u64 = ctx.r6.u64 & ctx.r9.u64;
	// bne cr6,0x82739e80
	if (!cr6.eq) goto loc_82739E80;
	// lfs f13,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82739e70
	if (cr6.lt) goto loc_82739E70;
	// li r11,0
	r11.s64 = 0;
loc_82739E70:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82739e84
	if (!cr6.eq) goto loc_82739E84;
loc_82739E80:
	// li r11,0
	r11.s64 = 0;
loc_82739E84:
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | r11.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// bne cr6,0x82739ec0
	if (!cr6.eq) goto loc_82739EC0;
	// fadds f0,f12,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 + f0.f64));
	// lfs f13,164(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82739eb0
	if (!cr6.lt) goto loc_82739EB0;
	// li r11,0
	r11.s64 = 0;
loc_82739EB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82739ec4
	if (cr6.eq) goto loc_82739EC4;
loc_82739EC0:
	// li r11,1
	r11.s64 = 1;
loc_82739EC4:
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// and r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 & r11.u64;
loc_82739ECC:
	// lwz r11,288(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 288);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82739f5c
	if (cr6.eq) goto loc_82739F5C;
	// lwz r5,292(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 292);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82739f5c
	if (cr6.eq) goto loc_82739F5C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// beq cr6,0x82739f08
	if (cr6.eq) goto loc_82739F08;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// b 0x82739f0c
	goto loc_82739F0C;
loc_82739F08:
	// fmr f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = f0.f64;
loc_82739F0C:
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82739f20
	if (cr6.eq) goto loc_82739F20;
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
	// b 0x82739f24
	goto loc_82739F24;
loc_82739F20:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f0.f64;
loc_82739F24:
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82739f34
	if (cr6.eq) goto loc_82739F34;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
loc_82739F34:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82739F5C;
	sub_8218A6E0(ctx, base);
loc_82739F5C:
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

__attribute__((alias("__imp__sub_82739F70"))) PPC_WEAK_FUNC(sub_82739F70);
PPC_FUNC_IMPL(__imp__sub_82739F70) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82739F78;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82489d40
	ctx.lr = 0x82739F94;
	sub_82489D40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273a16c
	if (!cr6.eq) goto loc_8273A16C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v63,2
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x2)));
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r7,112
	ctx.r7.s64 = 112;
	// vcuxwfp128 v62,v63,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r6,64
	ctx.r6.s64 = 64;
	// lwz r3,-26876(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -26876);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v1,r31,r6
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// vrlimi128 v1,v62,1,1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 147), 1));
	// lvx128 v58,r11,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c1d8
	ctx.lr = 0x8273A000;
	sub_8217C1D8(ctx, base);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// beq cr6,0x8273a028
	if (cr6.eq) goto loc_8273A028;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,-1540(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1540);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f10,f11
	cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// ble cr6,0x8273a044
	if (!cr6.gt) goto loc_8273A044;
loc_8273A028:
	// fmuls f10,f12,f12
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f11,-12988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12988);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f8,f0,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * f0.f64 + ctx.f9.f64));
	// fcmpu cr6,f8,f11
	cr6.compare(ctx.f8.f64, ctx.f11.f64);
	// bgt cr6,0x8273a16c
	if (cr6.gt) goto loc_8273A16C;
loc_8273A044:
	// lfs f11,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lfs f9,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f0,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bgt cr6,0x8273a16c
	if (cr6.gt) goto loc_8273A16C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8273a13c
	if (cr6.eq) goto loc_8273A13C;
	// lhz r10,172(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 172);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8273a13c
	if (!cr6.gt) goto loc_8273A13C;
	// lwz r11,168(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 168);
loc_8273A080:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// beq cr6,0x8273a0a0
	if (cr6.eq) goto loc_8273A0A0;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x8273a080
	if (cr6.lt) goto loc_8273A080;
	// b 0x8273a13c
	goto loc_8273A13C;
loc_8273A0A0:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8273a13c
	if (cr6.lt) goto loc_8273A13C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82739d10
	ctx.lr = 0x8273A0B4;
	sub_82739D10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a0e4
	if (cr6.eq) goto loc_8273A0E4;
	// lis r30,-1
	r30.s64 = -65536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r31,160
	ctx.r5.s64 = r31.s64 + 160;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82739948
	ctx.lr = 0x8273A0D8;
	sub_82739948(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r31,176
	ctx.r5.s64 = r31.s64 + 176;
	// b 0x8273a160
	goto loc_8273A160;
loc_8273A0E4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82739c98
	ctx.lr = 0x8273A0F0;
	sub_82739C98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a124
	if (cr6.eq) goto loc_8273A124;
	// lis r3,-32
	ctx.r3.s64 = -2097152;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// ori r3,r3,32832
	ctx.r3.u64 = ctx.r3.u64 | 32832;
	// addi r5,r31,192
	ctx.r5.s64 = r31.s64 + 192;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82739948
	ctx.lr = 0x8273A114;
	sub_82739948(ctx, base);
	// lis r3,-32
	ctx.r3.s64 = -2097152;
	// addi r5,r31,208
	ctx.r5.s64 = r31.s64 + 208;
	// ori r3,r3,32832
	ctx.r3.u64 = ctx.r3.u64 | 32832;
	// b 0x8273a160
	goto loc_8273A160;
loc_8273A124:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82739c38
	ctx.lr = 0x8273A130;
	sub_82739C38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a16c
	if (cr6.eq) goto loc_8273A16C;
loc_8273A13C:
	// lis r3,-256
	ctx.r3.s64 = -16777216;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r31,224
	ctx.r5.s64 = r31.s64 + 224;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r3,r3,65280
	ctx.r3.u64 = ctx.r3.u64 | 65280;
	// bl 0x82739948
	ctx.lr = 0x8273A154;
	sub_82739948(ctx, base);
	// lis r3,-256
	ctx.r3.s64 = -16777216;
	// addi r5,r31,240
	ctx.r5.s64 = r31.s64 + 240;
	// ori r3,r3,65280
	ctx.r3.u64 = ctx.r3.u64 | 65280;
loc_8273A160:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82739948
	ctx.lr = 0x8273A16C;
	sub_82739948(ctx, base);
loc_8273A16C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273A178"))) PPC_WEAK_FUNC(sub_8273A178);
PPC_FUNC_IMPL(__imp__sub_8273A178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8273A180;
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r9,r10,16948
	ctx.r9.u64 = ctx.r10.u64 | 16948;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273a1c4
	if (cr6.eq) goto loc_8273A1C4;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d924c
	return;
loc_8273A1C4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273A1D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8273A1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8273A20C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273A22C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v63,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v127.f32)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,164(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r10,r3,2528
	ctx.r10.s64 = ctx.r3.s64 + 2528;
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r6,r9,-31664
	ctx.r6.s64 = ctx.r9.s64 + -31664;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r11,-31648
	ctx.r7.s64 = r11.s64 + -31648;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-5852(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -5852);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
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
	// vmulfp128 v59,v63,v6
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8273a2d0
	if (cr6.lt) goto loc_8273A2D0;
	// li r11,0
	r11.s64 = 0;
loc_8273A2D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a304
	if (cr6.eq) goto loc_8273A304;
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273a304
	if (cr6.lt) goto loc_8273A304;
	// lhz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 48);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8273a304
	if (!cr6.lt) goto loc_8273A304;
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8273a30c
	goto loc_8273A30C;
loc_8273A304:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r11,r11,2272
	r11.s64 = r11.s64 + 2272;
loc_8273A30C:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f8,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-5848(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5848);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x8273a348
	if (cr6.gt) goto loc_8273A348;
	// li r11,0
	r11.s64 = 0;
loc_8273A348:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8273A35C"))) PPC_WEAK_FUNC(sub_8273A35C);
PPC_FUNC_IMPL(__imp__sub_8273A35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A360"))) PPC_WEAK_FUNC(sub_8273A360);
PPC_FUNC_IMPL(__imp__sub_8273A360) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// ori r9,r10,16948
	ctx.r9.u64 = ctx.r10.u64 | 16948;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273a384
	if (cr6.eq) goto loc_8273A384;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8273A384:
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r9,r11,2240
	ctx.r9.s64 = r11.s64 + 2240;
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r10,r5,-31648
	ctx.r10.s64 = ctx.r5.s64 + -31648;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// li r11,1
	r11.s64 = 1;
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-5852(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// vcmpeqfp128 v11,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
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
	// vmulfp128 v59,v63,v6
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8273a424
	if (cr6.lt) goto loc_8273A424;
	// li r11,0
	r11.s64 = 0;
loc_8273A424:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a458
	if (cr6.eq) goto loc_8273A458;
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273a458
	if (cr6.lt) goto loc_8273A458;
	// lhz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8273a458
	if (!cr6.lt) goto loc_8273A458;
	// lwz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8273a460
	goto loc_8273A460;
loc_8273A458:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r11,r11,2272
	r11.s64 = r11.s64 + 2272;
loc_8273A460:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f13,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f8,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-5848(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5848);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x8273a49c
	if (cr6.gt) goto loc_8273A49C;
	// li r11,0
	r11.s64 = 0;
loc_8273A49C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273A4A4"))) PPC_WEAK_FUNC(sub_8273A4A4);
PPC_FUNC_IMPL(__imp__sub_8273A4A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A4A8"))) PPC_WEAK_FUNC(sub_8273A4A8);
PPC_FUNC_IMPL(__imp__sub_8273A4A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lhz r10,148(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 148);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lfs f0,-5856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	f0.f64 = double(temp.f32);
	// lfs f13,-5852(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r9.u32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,164(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// beq cr6,0x8273a4f8
	if (cr6.eq) goto loc_8273A4F8;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8273A4DC:
	// lwz r8,144(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r7,148(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 148);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8273a4dc
	if (cr6.lt) goto loc_8273A4DC;
loc_8273A4F8:
	// lhz r11,156(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a530
	if (cr6.eq) goto loc_8273A530;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8273A514:
	// lwz r8,152(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r7,156(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8273a514
	if (cr6.lt) goto loc_8273A514;
loc_8273A530:
	// li r11,-1
	r11.s64 = -1;
	// stb r9,180(r3)
	PPC_STORE_U8(ctx.r3.u32 + 180, ctx.r9.u8);
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273A540"))) PPC_WEAK_FUNC(sub_8273A540);
PPC_FUNC_IMPL(__imp__sub_8273A540) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8273A548;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,80
	r11.s64 = 80;
	// lfs f0,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f11,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f10,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lvx128 v62,r31,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,-31400(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31400);
	f30.f64 = double(temp.f32);
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmadds f8,f11,f12,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fmadds f7,f10,f31,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f31
	cr6.compare(ctx.f7.f64, f31.f64);
	// ble cr6,0x8273a5f0
	if (!cr6.gt) goto loc_8273A5F0;
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// lfs f9,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f9,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f7,f0,f0,f8
	ctx.f7.f64 = double(float(f0.f64 * f0.f64 + ctx.f8.f64));
	// fsqrts f0,f7
	f0.f64 = double(float(sqrt(ctx.f7.f64)));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8273a5f0
	if (cr6.eq) goto loc_8273A5F0;
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f10,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f12,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f11.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fnmsubs f7,f10,f13,f8
	ctx.f7.f64 = double(float(-(ctx.f10.f64 * ctx.f13.f64 - ctx.f8.f64)));
	// fdivs f30,f7,f0
	f30.f64 = double(float(ctx.f7.f64 / f0.f64));
loc_8273A5F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273e210
	ctx.lr = 0x8273A5F8;
	sub_8273E210(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8273a750
	if (cr6.lt) goto loc_8273A750;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273a640
	if (!cr6.eq) goto loc_8273A640;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x8273a750
	if (cr6.eq) goto loc_8273A750;
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r9,r30,r9
	ctx.r9.u64 = r30.u64 + ctx.r9.u64;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8273A640:
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f12,-5852(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8273a6b4
	if (!cr6.lt) goto loc_8273A6B4;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bne cr6,0x8273a684
	if (!cr6.eq) goto loc_8273A684;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a750
	if (cr6.eq) goto loc_8273A750;
	// stfs f31,164(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8273A684:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r9,r30,r9
	ctx.r9.u64 = r30.u64 + ctx.r9.u64;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
	// lfs f0,-5852(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8273A6B4:
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lfs f13,-5856(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -5856);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8273a708
	if (!cr6.lt) goto loc_8273A708;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f12,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,164(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r8,r30,r9
	ctx.r8.u64 = r30.u64 + ctx.r9.u64;
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r8.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8273A708:
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// add r4,r30,r9
	ctx.r4.u64 = r30.u64 + ctx.r9.u64;
	// lfs f11,-29232(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f11.f64 = double(temp.f32);
	// stwx r4,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r4.u32);
	// lfs f10,164(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,-5852(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-5860(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -5860);
	f0.f64 = double(temp.f32);
	// lfs f13,-5856(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -5856);
	ctx.f13.f64 = double(temp.f32);
	// fadds f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fadds f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f12.f64));
	// fsubs f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f11.f64));
	// fsubs f6,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f7.f64));
	// fsel f5,f6,f10,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f10.f64 : ctx.f7.f64;
	// stfs f5,164(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
loc_8273A750:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273A764"))) PPC_WEAK_FUNC(sub_8273A764);
PPC_FUNC_IMPL(__imp__sub_8273A764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A768"))) PPC_WEAK_FUNC(sub_8273A768);
PPC_FUNC_IMPL(__imp__sub_8273A768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,-21536(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -21536);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273A77C"))) PPC_WEAK_FUNC(sub_8273A77C);
PPC_FUNC_IMPL(__imp__sub_8273A77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A780"))) PPC_WEAK_FUNC(sub_8273A780);
PPC_FUNC_IMPL(__imp__sub_8273A780) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,-21536(r10)
	PPC_STORE_U8(ctx.r10.u32 + -21536, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273A7A0"))) PPC_WEAK_FUNC(sub_8273A7A0);
PPC_FUNC_IMPL(__imp__sub_8273A7A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a82c
	if (cr6.eq) goto loc_8273A82C;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x822499f8
	ctx.lr = 0x8273A7D8;
	sub_822499F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273a82c
	if (cr6.eq) goto loc_8273A82C;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r11,2384
	ctx.r10.s64 = r11.s64 + 2384;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v59,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8273a82c
	if (!cr6.eq) goto loc_8273A82C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8273e210
	ctx.lr = 0x8273A818;
	sub_8273E210(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8273a82c
	if (cr6.lt) goto loc_8273A82C;
	// li r11,0
	r11.s64 = 0;
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// stb r11,180(r31)
	PPC_STORE_U8(r31.u32 + 180, r11.u8);
loc_8273A82C:
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

__attribute__((alias("__imp__sub_8273A844"))) PPC_WEAK_FUNC(sub_8273A844);
PPC_FUNC_IMPL(__imp__sub_8273A844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A848"))) PPC_WEAK_FUNC(sub_8273A848);
PPC_FUNC_IMPL(__imp__sub_8273A848) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8273A850;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// li r24,72
	r24.s64 = 72;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// li r31,0
	r31.s64 = 0;
	// lfs f31,11712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11712);
	f31.f64 = double(temp.f32);
	// li r29,8
	r29.s64 = 8;
	// lis r28,-32253
	r28.s64 = -2113732608;
loc_8273A888:
	// lbzx r10,r24,r25
	ctx.r10.u64 = PPC_LOAD_U8(r24.u32 + r25.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273a89c
	if (cr6.eq) goto loc_8273A89C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x8273a8a0
	goto loc_8273A8A0;
loc_8273A89C:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_8273A8A0:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x8273a970
	if (!cr6.lt) goto loc_8273A970;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273a8d4
	if (cr6.eq) goto loc_8273A8D4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8273a8f8
	if (cr6.lt) goto loc_8273A8F8;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x8273a8f8
	if (!cr6.lt) goto loc_8273A8F8;
	// add r11,r29,r3
	r11.u64 = r29.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x8273a8f0
	goto loc_8273A8F0;
loc_8273A8D4:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8273a8f8
	if (cr6.lt) goto loc_8273A8F8;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x8273a8f8
	if (!cr6.lt) goto loc_8273A8F8;
	// lwzx r11,r29,r3
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_8273A8F0:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8273a8fc
	if (!cr6.eq) goto loc_8273A8FC;
loc_8273A8F8:
	// li r11,0
	r11.s64 = 0;
loc_8273A8FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a950
	if (cr6.eq) goto loc_8273A950;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x8273A910;
	sub_822A3998(ctx, base);
	// lwz r3,640(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 640);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273a94c
	if (cr6.eq) goto loc_8273A94C;
	// bl 0x822452f8
	ctx.lr = 0x8273A920;
	sub_822452F8(ctx, base);
	// cmplw cr6,r3,r26
	cr6.compare<uint32_t>(ctx.r3.u32, r26.u32, xer);
	// bne cr6,0x8273a94c
	if (!cr6.eq) goto loc_8273A94C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8273A934;
	sub_822A3998(ctx, base);
	// lfs f0,-18988(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -18988);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f31
	f0.f64 = double(float(f0.f64 * f31.f64));
	// lfs f13,644(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 644);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x8273a95c
	if (cr6.lt) goto loc_8273A95C;
loc_8273A94C:
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
loc_8273A950:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// b 0x8273a888
	goto loc_8273A888;
loc_8273A95C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8273A970:
	// li r11,0
	r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8273c1b8
	ctx.lr = 0x8273A988;
	sub_8273C1B8(ctx, base);
	// lwz r10,352(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8273abac
	if (!cr6.gt) goto loc_8273ABAC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// lis r27,-32130
	r27.s64 = -2105671680;
	// lfs f30,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	f30.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8273A9B0:
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplw cr6,r30,r23
	cr6.compare<uint32_t>(r30.u32, r23.u32, xer);
	// beq cr6,0x8273ab98
	if (cr6.eq) goto loc_8273AB98;
	// lwz r11,448(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 448);
	// lbz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273ab98
	if (!cr6.eq) goto loc_8273AB98;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
	// lwz r4,188(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273aa30
	if (cr6.eq) goto loc_8273AA30;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8273a178
	ctx.lr = 0x8273AA04;
	sub_8273A178(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273ab98
	if (!cr6.eq) goto loc_8273AB98;
	// lfs f0,412(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 412);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8273aa24
	if (cr6.eq) goto loc_8273AA24;
	// li r11,0
	r11.s64 = 0;
loc_8273AA24:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
loc_8273AA30:
	// lbz r11,500(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 500);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273aa64
	if (cr6.eq) goto loc_8273AA64;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273aa64
	if (cr6.eq) goto loc_8273AA64;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273aa64
	if (cr6.eq) goto loc_8273AA64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// b 0x8273aab8
	goto loc_8273AAB8;
loc_8273AA64:
	// lbzx r11,r24,r25
	r11.u64 = PPC_LOAD_U8(r24.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273aa84
	if (cr6.eq) goto loc_8273AA84;
	// lwz r11,22080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// b 0x8273aab4
	goto loc_8273AAB4;
loc_8273AA84:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273aaac
	if (cr6.eq) goto loc_8273AAAC;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273aaac
	if (cr6.eq) goto loc_8273AAAC;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273aaac
	if (cr6.eq) goto loc_8273AAAC;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x8273aab0
	goto loc_8273AAB0;
loc_8273AAAC:
	// addi r11,r30,112
	r11.s64 = r30.s64 + 112;
loc_8273AAB0:
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_8273AAB4:
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
loc_8273AAB8:
	// lfs f13,88(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,116(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,120(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f13,f10,f9
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,112(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,60(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 60);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 * f30.f64));
	// fmadds f4,f8,f0,f11
	ctx.f4.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f3,f7,f13,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f4.f64));
	// fabs f2,f3
	ctx.f2.u64 = ctx.f3.u64 & ~0x8000000000000000;
	// fcmpu cr6,f2,f5
	cr6.compare(ctx.f2.f64, ctx.f5.f64);
	// bge cr6,0x8273ab2c
	if (!cr6.lt) goto loc_8273AB2C;
	// lfs f12,100(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lfs f10,104(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,96(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,64(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f30
	ctx.f7.f64 = double(float(ctx.f8.f64 * f30.f64));
	// fmadds f6,f10,f0,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f5,f9,f13,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f7
	cr6.compare(ctx.f4.f64, ctx.f7.f64);
	// blt cr6,0x8273ab30
	if (cr6.lt) goto loc_8273AB30;
loc_8273AB2C:
	// li r11,0
	r11.s64 = 0;
loc_8273AB30:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ab98
	if (cr6.eq) goto loc_8273AB98;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
	// lwz r31,192(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822452f8
	ctx.lr = 0x8273AB5C;
	sub_822452F8(ctx, base);
	// cmplw cr6,r3,r26
	cr6.compare<uint32_t>(ctx.r3.u32, r26.u32, xer);
	// bne cr6,0x8273ab74
	if (!cr6.eq) goto loc_8273AB74;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8273a178
	ctx.lr = 0x8273AB70;
	sub_8273A178(ctx, base);
	// b 0x8273ab8c
	goto loc_8273AB8C;
loc_8273AB74:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826ddd90
	ctx.lr = 0x8273AB80;
	sub_826DDD90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8273a360
	ctx.lr = 0x8273AB8C;
	sub_8273A360(ctx, base);
loc_8273AB8C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
loc_8273AB98:
	// lwz r11,352(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8273a9b0
	if (cr6.lt) goto loc_8273A9B0;
loc_8273ABAC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8273ABC0"))) PPC_WEAK_FUNC(sub_8273ABC0);
PPC_FUNC_IMPL(__imp__sub_8273ABC0) {
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
	ctx.lr = 0x8273ABC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lfs f0,-5860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5860);
	f0.f64 = double(temp.f32);
	// ori r7,r9,16980
	ctx.r7.u64 = ctx.r9.u64 | 16980;
	// lfs f13,-5856(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5856);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lwz r11,-10012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10012);
	// ori r5,r8,16977
	ctx.r5.u64 = ctx.r8.u64 | 16977;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,-5852(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -5852);
	f0.f64 = double(temp.f32);
	// lwzx r30,r11,r7
	r30.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// lbzx r29,r11,r5
	r29.u64 = PPC_LOAD_U8(r11.u32 + ctx.r5.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// bge cr6,0x8273ac24
	if (!cr6.lt) goto loc_8273AC24;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273aca8
	if (!cr6.eq) goto loc_8273ACA8;
loc_8273AC24:
	// lbz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 180);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273ac40
	if (!cr6.eq) goto loc_8273AC40;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// blt cr6,0x8273ac44
	if (cr6.lt) goto loc_8273AC44;
loc_8273AC40:
	// li r11,1
	r11.s64 = 1;
loc_8273AC44:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ac58
	if (cr6.eq) goto loc_8273AC58;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273aca8
	if (!cr6.eq) goto loc_8273ACA8;
loc_8273AC58:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r9,-21536(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -21536);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8273aca8
	if (!cr6.eq) goto loc_8273ACA8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273ac80
	if (!cr6.eq) goto loc_8273AC80;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// blt cr6,0x8273ac84
	if (cr6.lt) goto loc_8273AC84;
loc_8273AC80:
	// li r11,1
	r11.s64 = 1;
loc_8273AC84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273acb4
	if (cr6.eq) goto loc_8273ACB4;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273acb4
	if (cr6.lt) goto loc_8273ACB4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8273ACA8:
	// stfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8273ACB4:
	// lfs f13,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f1
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// stfs f12,164(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x8273ace0
	if (!cr6.gt) goto loc_8273ACE0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273a848
	ctx.lr = 0x8273ACD4;
	sub_8273A848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273acf4
	if (cr6.eq) goto loc_8273ACF4;
loc_8273ACE0:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lfs f13,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-21532(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21532);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8273adec
	if (!cr6.gt) goto loc_8273ADEC;
loc_8273ACF4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r30,1500
	cr6.compare<int32_t>(r30.s32, 1500, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// bge cr6,0x8273ad48
	if (!cr6.lt) goto loc_8273AD48;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ad48
	if (cr6.eq) goto loc_8273AD48;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8273AD24;
	sub_822A3998(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8273AD34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273e210
	ctx.lr = 0x8273AD40;
	sub_8273E210(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// b 0x8273ad90
	goto loc_8273AD90;
loc_8273AD48:
	// lhz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 148);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273ad8c
	if (cr6.eq) goto loc_8273AD8C;
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
loc_8273AD68:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// ble cr6,0x8273ad7c
	if (!cr6.gt) goto loc_8273AD7C;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_8273AD7C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x8273ad68
	if (cr6.lt) goto loc_8273AD68;
loc_8273AD8C:
	// stw r7,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r7.u32);
loc_8273AD90:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273adc4
	if (cr6.lt) goto loc_8273ADC4;
	// lhz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 156);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8273adc4
	if (!cr6.lt) goto loc_8273ADC4;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lwz r10,-10012(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10012);
	// lwz r8,152(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r6,r9,16952
	ctx.r6.u64 = ctx.r9.u64 | 16952;
	// lfsx f0,r10,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r7,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, temp.u32);
loc_8273ADC4:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273adec
	if (cr6.lt) goto loc_8273ADEC;
	// lhz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 148);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8273adec
	if (!cr6.lt) goto loc_8273ADEC;
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,0
	ctx.r8.s64 = 0;
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8273ADEC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273ADF4"))) PPC_WEAK_FUNC(sub_8273ADF4);
PPC_FUNC_IMPL(__imp__sub_8273ADF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273ADF8"))) PPC_WEAK_FUNC(sub_8273ADF8);
PPC_FUNC_IMPL(__imp__sub_8273ADF8) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x8273ae5c
	if (cr6.eq) goto loc_8273AE5C;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x822499f8
	ctx.lr = 0x8273AE44;
	sub_822499F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273ae5c
	if (cr6.eq) goto loc_8273AE5C;
	// li r11,-1
	r11.s64 = -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, r11.u32);
	// stb r10,180(r3)
	PPC_STORE_U8(ctx.r3.u32 + 180, ctx.r10.u8);
loc_8273AE5C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273AE6C"))) PPC_WEAK_FUNC(sub_8273AE6C);
PPC_FUNC_IMPL(__imp__sub_8273AE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273AE70"))) PPC_WEAK_FUNC(sub_8273AE70);
PPC_FUNC_IMPL(__imp__sub_8273AE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f11,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8273a7a0
	ctx.lr = 0x8273AEC4;
	sub_8273A7A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273AED4"))) PPC_WEAK_FUNC(sub_8273AED4);
PPC_FUNC_IMPL(__imp__sub_8273AED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273AED8"))) PPC_WEAK_FUNC(sub_8273AED8);
PPC_FUNC_IMPL(__imp__sub_8273AED8) {
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
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,-22680
	ctx.r4.s64 = r11.s64 + -22680;
	// addi r3,r10,-11012
	ctx.r3.s64 = ctx.r10.s64 + -11012;
	// bl 0x82554798
	ctx.lr = 0x8273AEF8;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,-22656
	ctx.r4.s64 = ctx.r9.s64 + -22656;
	// addi r3,r8,-11052
	ctx.r3.s64 = ctx.r8.s64 + -11052;
	// bl 0x82554798
	ctx.lr = 0x8273AF0C;
	sub_82554798(ctx, base);
	// lis r7,-32140
	ctx.r7.s64 = -2106327040;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,-21000
	ctx.r4.s64 = ctx.r7.s64 + -21000;
	// addi r3,r6,-11096
	ctx.r3.s64 = ctx.r6.s64 + -11096;
	// bl 0x82554798
	ctx.lr = 0x8273AF20;
	sub_82554798(ctx, base);
	// lis r5,-32140
	ctx.r5.s64 = -2106327040;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,-20880
	ctx.r4.s64 = ctx.r5.s64 + -20880;
	// addi r3,r3,-11140
	ctx.r3.s64 = ctx.r3.s64 + -11140;
	// bl 0x82554798
	ctx.lr = 0x8273AF34;
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

__attribute__((alias("__imp__sub_8273AF44"))) PPC_WEAK_FUNC(sub_8273AF44);
PPC_FUNC_IMPL(__imp__sub_8273AF44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273AF48"))) PPC_WEAK_FUNC(sub_8273AF48);
PPC_FUNC_IMPL(__imp__sub_8273AF48) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8273AF50;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-816(r1)
	ea = -816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r28,48(r30)
	r28.u64 = PPC_LOAD_U16(r30.u32 + 48);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8273b65c
	if (cr6.eq) goto loc_8273B65C;
	// addi r21,r30,168
	r21.s64 = r30.s64 + 168;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82504778
	ctx.lr = 0x8273AF80;
	sub_82504778(ctx, base);
	// clrlwi r27,r28,16
	r27.u64 = r28.u32 & 0xFFFF;
	// li r22,0
	r22.s64 = 0;
	// stw r3,168(r30)
	PPC_STORE_U32(r30.u32 + 168, ctx.r3.u32);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// sth r27,174(r30)
	PPC_STORE_U16(r30.u32 + 174, r27.u16);
	// ble cr6,0x8273afc0
	if (!cr6.gt) goto loc_8273AFC0;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8273AF9C:
	// lhz r8,4(r21)
	ctx.r8.u64 = PPC_LOAD_U16(r21.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r9,0(r21)
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r21)
	PPC_STORE_U16(r21.u32 + 4, ctx.r7.u16);
	// stwx r22,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r22.u32);
	// bne 0x8273af9c
	if (!cr0.eq) goto loc_8273AF9C;
loc_8273AFC0:
	// rlwinm r29,r28,2,0,29
	r29.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r30,144
	r31.s64 = r30.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130528
	ctx.lr = 0x8273AFD0;
	sub_82130528(ctx, base);
	// sth r27,150(r30)
	PPC_STORE_U16(r30.u32 + 150, r27.u16);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stw r3,144(r30)
	PPC_STORE_U32(r30.u32 + 144, ctx.r3.u32);
	// ble cr6,0x8273b008
	if (!cr6.gt) goto loc_8273B008;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8273AFE4:
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r22,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r22.u32);
	// bne 0x8273afe4
	if (!cr0.eq) goto loc_8273AFE4;
loc_8273B008:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r31,r30,152
	r31.s64 = r30.s64 + 152;
	// bl 0x82130528
	ctx.lr = 0x8273B014;
	sub_82130528(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// sth r27,158(r30)
	PPC_STORE_U16(r30.u32 + 158, r27.u16);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// stw r3,152(r30)
	PPC_STORE_U32(r30.u32 + 152, ctx.r3.u32);
	// cmpwi cr6,r28,4
	cr6.compare<int32_t>(r28.s32, 4, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// blt cr6,0x8273b0b8
	if (cr6.lt) goto loc_8273B0B8;
	// addi r11,r28,-4
	r11.s64 = r28.s64 + -4;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_8273B040:
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r6.u16);
	// stfsx f31,r8,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// rotlwi r8,r4,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// sth r3,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r3.u16);
	// stfsx f31,r8,r9
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r6.u16);
	// stfsx f31,r8,r9
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// rotlwi r8,r4,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// sth r3,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r3.u16);
	// stfsx f31,r8,r9
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, temp.u32);
	// bne 0x8273b040
	if (!cr0.eq) goto loc_8273B040;
loc_8273B0B8:
	// cmpw cr6,r7,r28
	cr6.compare<int32_t>(ctx.r7.s32, r28.s32, xer);
	// bge cr6,0x8273b0e8
	if (!cr6.lt) goto loc_8273B0E8;
	// subf r11,r7,r28
	r11.s64 = r28.s64 - ctx.r7.s64;
loc_8273B0C4:
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stfsx f31,r8,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, temp.u32);
	// bne 0x8273b0c4
	if (!cr0.eq) goto loc_8273B0C4;
loc_8273B0E8:
	// li r7,80
	ctx.r7.s64 = 80;
	// lfs f0,132(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 132);
	f0.f64 = double(temp.f32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lvx128 v62,r30,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,-1
	ctx.r10.s64 = -1;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r22,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r22.u32);
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r29,-32114
	r29.s64 = -2104623104;
	// li r31,-1
	r31.s64 = -1;
	// sth r10,236(r1)
	PPC_STORE_U16(ctx.r1.u32 + 236, ctx.r10.u16);
	// lfs f0,27640(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f31,224(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// li r7,2048
	ctx.r7.s64 = 2048;
	// sth r22,238(r1)
	PPC_STORE_U16(ctx.r1.u32 + 238, r22.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r22,240(r1)
	PPC_STORE_U8(ctx.r1.u32 + 240, r22.u8);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// sth r22,242(r1)
	PPC_STORE_U16(ctx.r1.u32 + 242, r22.u16);
	// stw r22,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r22.u32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-23452(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -23452);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// bl 0x82574418
	ctx.lr = 0x8273B1B0;
	sub_82574418(ctx, base);
	// lwz r8,160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273b65c
	if (cr6.eq) goto loc_8273B65C;
	// li r11,1
	r11.s64 = 1;
	// lfs f13,64(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stb r11,420(r1)
	PPC_STORE_U8(ctx.r1.u32 + 420, r11.u8);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r20,r11,-23388
	r20.s64 = r11.s64 + -23388;
	// lfs f0,27532(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27532);
	f0.f64 = double(temp.f32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821c8f08
	ctx.lr = 0x8273B1F0;
	sub_821C8F08(ctx, base);
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r28,7
	r28.s64 = 7;
	// stw r31,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, r31.u32);
	// stw r22,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r22.u32);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// stw r8,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r8.u32);
	// stw r31,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, r31.u32);
	// stw r28,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r28.u32);
	// stb r22,356(r1)
	PPC_STORE_U8(ctx.r1.u32 + 356, r22.u8);
	// bl 0x82130000
	ctx.lr = 0x8273B218;
	sub_82130000(ctx, base);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// lwz r3,-23452(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -23452);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r25,r22
	r25.u64 = r22.u64;
	// lvlx128 v61,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r22,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r22.u32);
	// stw r31,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, r31.u32);
	// stw r28,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r28.u32);
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82572c48
	ctx.lr = 0x8273B250;
	sub_82572C48(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,358(r1)
	PPC_STORE_U16(ctx.r1.u32 + 358, ctx.r3.u16);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8273b2d8
	if (cr6.eq) goto loc_8273B2D8;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r26,r1,432
	r26.s64 = ctx.r1.s64 + 432;
	// addi r28,r10,24092
	r28.s64 = ctx.r10.s64 + 24092;
	// addi r27,r9,-7492
	r27.s64 = ctx.r9.s64 + -7492;
loc_8273B274:
	// lwz r10,-23452(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -23452);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,112(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r3,r10,0,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dedd8
	ctx.lr = 0x8273B2A0;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273b2bc
	if (cr6.eq) goto loc_8273B2BC;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpwi cr6,r25,64
	cr6.compare<int32_t>(r25.s32, 64, xer);
	// beq cr6,0x8273b2d8
	if (cr6.eq) goto loc_8273B2D8;
loc_8273B2BC:
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// lwz r3,-23452(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -23452);
	// bl 0x82571250
	ctx.lr = 0x8273B2C8;
	sub_82571250(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,358(r1)
	PPC_STORE_U16(ctx.r1.u32 + 358, ctx.r3.u16);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8273b274
	if (!cr6.eq) goto loc_8273B274;
loc_8273B2D8:
	// lhz r11,48(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 48);
	// mullw r23,r11,r25
	r23.s64 = int64_t(r11.s32) * int64_t(r25.s32);
	// bl 0x821bbea8
	ctx.lr = 0x8273B2E4;
	sub_821BBEA8(ctx, base);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// rlwinm r3,r23,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// cmplw cr6,r23,r9
	cr6.compare<uint32_t>(r23.u32, ctx.r9.u32, xer);
	// ble cr6,0x8273b2fc
	if (!cr6.gt) goto loc_8273B2FC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8273B2FC:
	// bl 0x82130528
	ctx.lr = 0x8273B300;
	sub_82130528(ctx, base);
	// lhz r11,48(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 48);
	// mr r26,r22
	r26.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273b4a8
	if (cr6.eq) goto loc_8273B4A8;
	// mr r28,r22
	r28.u64 = r22.u64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// rlwinm r24,r25,2,0,29
	r24.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8273B320:
	// mr r29,r22
	r29.u64 = r22.u64;
	// cmpwi cr6,r25,4
	cr6.compare<int32_t>(r25.s32, 4, xer);
	// blt cr6,0x8273b424
	if (cr6.lt) goto loc_8273B424;
	// addi r10,r25,-4
	ctx.r10.s64 = r25.s64 + -4;
	// addi r11,r1,436
	r11.s64 = ctx.r1.s64 + 436;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r31,r10,1
	r31.s64 = ctx.r10.s64 + 1;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// rlwinm r29,r31,2,0,29
	r29.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
loc_8273B344:
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// lwz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lfs f0,52(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,56(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,48(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f10,f11,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmadds f6,f8,f9,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f7.f64));
	// stfs f6,0(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f5,56(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,48(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,52(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	ctx.f3.f64 = double(temp.f32);
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lfs f0,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 * f0.f64));
	// lfs f2,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f12,f5,f2,f13
	ctx.f12.f64 = double(float(ctx.f5.f64 * ctx.f2.f64 + ctx.f13.f64));
	// lfs f1,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f11,f4,f1,f12
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f11,4(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f10,52(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lfs f7,56(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 56);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f10,f5
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// fmadds f3,f7,f8,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f8.f64 + ctx.f4.f64));
	// lfs f9,48(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f2,f9,f6,f3
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f6.f64 + ctx.f3.f64));
	// stfs f2,8(r10)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfs f1,52(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lfs f0,56(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,48(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fmadds f8,f0,f13,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f7,f12,f11,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f8.f64));
	// stfs f7,12(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8273b344
	if (!cr0.eq) goto loc_8273B344;
loc_8273B424:
	// cmpw cr6,r29,r25
	cr6.compare<int32_t>(r29.s32, r25.s32, xer);
	// bge cr6,0x8273b48c
	if (!cr6.lt) goto loc_8273B48C;
	// add r11,r28,r29
	r11.u64 = r28.u64 + r29.u64;
	// addi r8,r1,432
	ctx.r8.s64 = ctx.r1.s64 + 432;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r6,r11,r3
	ctx.r6.u64 = r11.u64 + ctx.r3.u64;
	// subf r8,r29,r25
	ctx.r8.s64 = r25.s64 - r29.s64;
loc_8273B448:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lfs f0,52(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,56(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// stfs f6,0(r6)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x8273b448
	if (!cr0.eq) goto loc_8273B448;
loc_8273B48C:
	// lhz r11,48(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 48);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// add r28,r28,r25
	r28.u64 = r28.u64 + r25.u64;
	// add r27,r27,r24
	r27.u64 = r27.u64 + r24.u64;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8273b320
	if (cr6.lt) goto loc_8273B320;
loc_8273B4A8:
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x8273b638
	if (!cr6.gt) goto loc_8273B638;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f11,-1684(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-31068(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31068);
	ctx.f12.f64 = double(temp.f32);
loc_8273B4C4:
	// lhz r11,48(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 48);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x8273b638
	if (!cr6.lt) goto loc_8273B638;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r11,r22
	r11.u64 = r22.u64;
	// cmpwi cr6,r23,4
	cr6.compare<int32_t>(r23.s32, 4, xer);
	// blt cr6,0x8273b54c
	if (cr6.lt) goto loc_8273B54C;
	// addi r8,r23,-3
	ctx.r8.s64 = r23.s64 + -3;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
loc_8273B4EC:
	// lfs f13,-8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8273b500
	if (!cr6.gt) goto loc_8273B500;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8273B500:
	// lfs f13,-4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8273b514
	if (!cr6.gt) goto loc_8273B514;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
loc_8273B514:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8273b528
	if (!cr6.gt) goto loc_8273B528;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
loc_8273B528:
	// lfs f13,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8273b53c
	if (!cr6.gt) goto loc_8273B53C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// addi r10,r11,3
	ctx.r10.s64 = r11.s64 + 3;
loc_8273B53C:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8273b4ec
	if (cr6.lt) goto loc_8273B4EC;
loc_8273B54C:
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// bge cr6,0x8273b580
	if (!cr6.lt) goto loc_8273B580;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
loc_8273B55C:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8273b570
	if (!cr6.gt) goto loc_8273B570;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8273B570:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// blt cr6,0x8273b55c
	if (cr6.lt) goto loc_8273B55C;
loc_8273B580:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8273b638
	if (cr6.lt) goto loc_8273B638;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// stfsx f12,r11,r3
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x8273b630
	if (cr6.lt) goto loc_8273B630;
	// divw r9,r10,r25
	ctx.r9.s32 = ctx.r10.s32 / r25.s32;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// mullw r8,r9,r25
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r25.s32);
	// subf r5,r8,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r8.s64;
	// rotlwi r7,r10,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,432
	ctx.r8.s64 = ctx.r1.s64 + 432;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// addi r11,r7,-1
	r11.s64 = ctx.r7.s64 + -1;
	// andc r7,r25,r4
	ctx.r7.u64 = r25.u64 & ~ctx.r4.u64;
	// andc r5,r25,r11
	ctx.r5.u64 = r25.u64 & ~r11.u64;
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// twllei r25,0
	// divw r10,r10,r25
	ctx.r10.s32 = ctx.r10.s32 / r25.s32;
	// twllei r25,0
	// twlgei r5,-1
	// twlgei r7,-1
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273b630
	if (cr6.eq) goto loc_8273B630;
	// lwz r7,0(r21)
	ctx.r7.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r7,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x8273b630
	if (!cr6.eq) goto loc_8273B630;
	// lfs f0,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,132(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f11
	cr6.compare(ctx.f9.f64, ctx.f11.f64);
	// bge cr6,0x8273b630
	if (!cr6.lt) goto loc_8273B630;
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stwx r22,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r22.u32);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stwx r11,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, r11.u32);
	// lwz r5,0(r21)
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lwzx r4,r5,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// stw r30,296(r4)
	PPC_STORE_U32(ctx.r4.u32 + 296, r30.u32);
loc_8273B630:
	// cmpw cr6,r6,r25
	cr6.compare<int32_t>(ctx.r6.s32, r25.s32, xer);
	// blt cr6,0x8273b4c4
	if (cr6.lt) goto loc_8273B4C4;
loc_8273B638:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273b644
	if (cr6.eq) goto loc_8273B644;
	// bl 0x82130588
	ctx.lr = 0x8273B644;
	sub_82130588(ctx, base);
loc_8273B644:
	// bl 0x821bbf00
	ctx.lr = 0x8273B648;
	sub_821BBF00(ctx, base);
	// lbz r10,420(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 420);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273b65c
	if (cr6.eq) goto loc_8273B65C;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x821c8f70
	ctx.lr = 0x8273B65C;
	sub_821C8F70(ctx, base);
loc_8273B65C:
	// addi r1,r1,816
	ctx.r1.s64 = ctx.r1.s64 + 816;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8273B670"))) PPC_WEAK_FUNC(sub_8273B670);
PPC_FUNC_IMPL(__imp__sub_8273B670) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,-5840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5840);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8273b6d4
	if (!cr6.lt) goto loc_8273B6D4;
	// lwz r11,164(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8273b6d4
	if (!cr6.eq) goto loc_8273B6D4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-27139(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -27139);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273b6a4
	if (cr6.eq) goto loc_8273B6A4;
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_8273B6A4:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-27138(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -27138);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273b6c0
	if (cr6.eq) goto loc_8273B6C0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,-22568(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -22568);
	// blr 
	return;
loc_8273B6C0:
	// lwz r11,152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8273b6d4
	if (!cr6.eq) goto loc_8273B6D4;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,-15156(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -15156);
loc_8273B6D4:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273B6DC"))) PPC_WEAK_FUNC(sub_8273B6DC);
PPC_FUNC_IMPL(__imp__sub_8273B6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273B6E0"))) PPC_WEAK_FUNC(sub_8273B6E0);
PPC_FUNC_IMPL(__imp__sub_8273B6E0) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8273c248
	ctx.lr = 0x8273B704;
	sub_8273C248(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,160(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
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

__attribute__((alias("__imp__sub_8273B730"))) PPC_WEAK_FUNC(sub_8273B730);
PPC_FUNC_IMPL(__imp__sub_8273B730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,-1
	r11.s64 = -1;
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273B73C"))) PPC_WEAK_FUNC(sub_8273B73C);
PPC_FUNC_IMPL(__imp__sub_8273B73C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273B740"))) PPC_WEAK_FUNC(sub_8273B740);
PPC_FUNC_IMPL(__imp__sub_8273B740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x8273B748;
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// ori r9,r10,16948
	ctx.r9.u64 = ctx.r10.u64 | 16948;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273b7ac
	if (cr6.eq) goto loc_8273B7AC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,-5840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5840);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273b7a0
	if (cr6.lt) goto loc_8273B7A0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r9,r10
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	f31.f64 = double(temp.f32);
	// b 0x8273b8d4
	goto loc_8273B8D4;
loc_8273B7A0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f31,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f31.f64 = double(temp.f32);
	// b 0x8273b8d4
	goto loc_8273B8D4;
loc_8273B7AC:
	// lis r10,6
	ctx.r10.s64 = 393216;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// ori r9,r10,16976
	ctx.r9.u64 = ctx.r10.u64 | 16976;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273b8c4
	if (cr6.eq) goto loc_8273B8C4;
	// bl 0x8273b670
	ctx.lr = 0x8273B7C8;
	sub_8273B670(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x8273b800
	if (cr6.eq) goto loc_8273B800;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8273b81c
	if (!cr6.gt) goto loc_8273B81C;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x8273b810
	goto loc_8273B810;
loc_8273B800:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8273b81c
	if (!cr6.gt) goto loc_8273B81C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_8273B810:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8273b820
	if (!cr6.eq) goto loc_8273B820;
loc_8273B81C:
	// li r11,0
	r11.s64 = 0;
loc_8273B820:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273b868
	if (cr6.eq) goto loc_8273B868;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x8273B834;
	sub_822A3998(ctx, base);
	// bl 0x822a8148
	ctx.lr = 0x8273B838;
	sub_822A8148(ctx, base);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f0,14836(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14836);
	f0.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// bge cr6,0x8273b868
	if (!cr6.lt) goto loc_8273B868;
loc_8273B860:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x8273b8cc
	goto loc_8273B8CC;
loc_8273B868:
	// cmplwi cr6,r30,5
	cr6.compare<uint32_t>(r30.u32, 5, xer);
	// bgt cr6,0x8273b860
	if (cr6.gt) goto loc_8273B860;
	// lis r12,-32140
	r12.s64 = -2106327040;
	// addi r12,r12,-18296
	r12.s64 = r12.s64 + -18296;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r30.u64) {
	case 0:
		goto loc_8273B8A0;
	case 1:
		goto loc_8273B8AC;
	case 2:
		goto loc_8273B8AC;
	case 3:
		goto loc_8273B8B8;
	case 4:
		goto loc_8273B8B8;
	case 5:
		goto loc_8273B8B8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-18272(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + -18272);
	// lwz r19,-18260(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + -18260);
	// lwz r19,-18260(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + -18260);
	// lwz r19,-18248(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + -18248);
	// lwz r19,-18248(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + -18248);
	// lwz r19,-18248(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + -18248);
loc_8273B8A0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// b 0x8273b8d4
	goto loc_8273B8D4;
loc_8273B8AC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f31,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f31.f64 = double(temp.f32);
	// b 0x8273b8d4
	goto loc_8273B8D4;
loc_8273B8B8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f31,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f31.f64 = double(temp.f32);
	// b 0x8273b8d4
	goto loc_8273B8D4;
loc_8273B8C4:
	// bl 0x8273b670
	ctx.lr = 0x8273B8C8;
	sub_8273B670(ctx, base);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
loc_8273B8CC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfsx f31,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	f31.f64 = double(temp.f32);
loc_8273B8D4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// bl 0x8224d270
	ctx.lr = 0x8273B8EC;
	sub_8224D270(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8273b94c
	if (!cr6.gt) goto loc_8273B94C;
loc_8273B8FC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8224d6f8
	ctx.lr = 0x8273B908;
	sub_8224D6F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273B91C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8273b940
	if (!cr6.eq) goto loc_8273B940;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273B93C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fadds f30,f1,f30
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64 + f30.f64));
loc_8273B940:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x8273b8fc
	if (cr6.lt) goto loc_8273B8FC;
loc_8273B94C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fmuls f0,f30,f0
	f0.f64 = double(float(f30.f64 * f0.f64));
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fmuls f1,f13,f29
	ctx.f1.f64 = double(float(ctx.f13.f64 * f29.f64));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-64(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273B974"))) PPC_WEAK_FUNC(sub_8273B974);
PPC_FUNC_IMPL(__imp__sub_8273B974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273B978"))) PPC_WEAK_FUNC(sub_8273B978);
PPC_FUNC_IMPL(__imp__sub_8273B978) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
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
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f1,-31384(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8273B9AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f30,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bne cr6,0x8273b9cc
	if (!cr6.eq) goto loc_8273B9CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,29500(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29500);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8273ba74
	goto loc_8273BA74;
loc_8273B9CC:
	// li r11,0
	r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273c1b8
	ctx.lr = 0x8273B9E4;
	sub_8273C1B8(ctx, base);
	// lwz r11,352(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f12,f31
	f0.f64 = double(float(ctx.f12.f64 / f31.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8273ba18
	if (!cr6.lt) goto loc_8273BA18;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x8273ba68
	goto loc_8273BA68;
loc_8273BA18:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8273ba68
	if (!cr6.gt) goto loc_8273BA68;
	// fmr f13,f30
	ctx.f13.f64 = f30.f64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8273ba48
	if (!cr6.gt) goto loc_8273BA48;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
loc_8273BA30:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lfs f11,412(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 412);
	ctx.f11.f64 = double(temp.f32);
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// bne 0x8273ba30
	if (!cr0.eq) goto loc_8273BA30;
loc_8273BA48:
	// fdivs f12,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,23364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 23364);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x8273ba68
	if (!cr6.lt) goto loc_8273BA68;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8273BA68:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,11364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8273BA74:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
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

__attribute__((alias("__imp__sub_8273BA90"))) PPC_WEAK_FUNC(sub_8273BA90);
PPC_FUNC_IMPL(__imp__sub_8273BA90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,-5840(r10)
	PPC_STORE_U32(ctx.r10.u32 + -5840, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273BAA4"))) PPC_WEAK_FUNC(sub_8273BAA4);
PPC_FUNC_IMPL(__imp__sub_8273BAA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273BAA8"))) PPC_WEAK_FUNC(sub_8273BAA8);
PPC_FUNC_IMPL(__imp__sub_8273BAA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-5840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5840);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273BABC"))) PPC_WEAK_FUNC(sub_8273BABC);
PPC_FUNC_IMPL(__imp__sub_8273BABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273BAC0"))) PPC_WEAK_FUNC(sub_8273BAC0);
PPC_FUNC_IMPL(__imp__sub_8273BAC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273baf0
	if (cr6.eq) goto loc_8273BAF0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,48
	ctx.r3.s64 = r11.s64 + 48;
	// blr 
	return;
loc_8273BAF0:
	// lbz r11,500(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 500);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273bb28
	if (cr6.eq) goto loc_8273BB28;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273bb28
	if (cr6.eq) goto loc_8273BB28;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273bb28
	if (cr6.eq) goto loc_8273BB28;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r3,r11,48
	ctx.r3.s64 = r11.s64 + 48;
	// blr 
	return;
loc_8273BB28:
	// addi r11,r3,112
	r11.s64 = ctx.r3.s64 + 112;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r3,r11,48
	ctx.r3.s64 = r11.s64 + 48;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273BB38"))) PPC_WEAK_FUNC(sub_8273BB38);
PPC_FUNC_IMPL(__imp__sub_8273BB38) {
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
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,-17776
	ctx.r4.s64 = r11.s64 + -17776;
	// addi r3,r10,-10624
	ctx.r3.s64 = ctx.r10.s64 + -10624;
	// bl 0x82554798
	ctx.lr = 0x8273BB58;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,-17752
	ctx.r4.s64 = ctx.r9.s64 + -17752;
	// addi r3,r8,-10660
	ctx.r3.s64 = ctx.r8.s64 + -10660;
	// bl 0x82554798
	ctx.lr = 0x8273BB6C;
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

__attribute__((alias("__imp__sub_8273BB7C"))) PPC_WEAK_FUNC(sub_8273BB7C);
PPC_FUNC_IMPL(__imp__sub_8273BB7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273BB80"))) PPC_WEAK_FUNC(sub_8273BB80);
PPC_FUNC_IMPL(__imp__sub_8273BB80) {
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
	ctx.lr = 0x8273BB88;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r25,0,30,30
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273bc18
	if (cr6.eq) goto loc_8273BC18;
	// lwz r10,-16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// addi r26,r31,-16
	r26.s64 = r31.s64 + -16;
	// mulli r11,r10,112
	r11.s64 = ctx.r10.s64 * 112;
	// addic. r30,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r30.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// blt 0x8273bbf8
	if (cr0.lt) goto loc_8273BBF8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r29,r11,-19596
	r29.s64 = r11.s64 + -19596;
	// addi r28,r10,-19568
	r28.s64 = ctx.r10.s64 + -19568;
	// addi r27,r9,-19540
	r27.s64 = ctx.r9.s64 + -19540;
loc_8273BBD0:
	// addi r31,r31,-112
	r31.s64 = r31.s64 + -112;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// stw r28,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r28.u32);
	// bl 0x82586680
	ctx.lr = 0x8273BBE4;
	sub_82586680(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8273BBF0;
	sub_821D2028(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8273bbd0
	if (!cr0.lt) goto loc_8273BBD0;
loc_8273BBF8:
	// clrlwi r11,r25,31
	r11.u64 = r25.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273bc0c
	if (cr6.eq) goto loc_8273BC0C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x8273BC0C;
	sub_82130588(ctx, base);
loc_8273BC0C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8273BC18:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-19540
	ctx.r9.s64 = r11.s64 + -19540;
	// addi r8,r10,-19568
	ctx.r8.s64 = ctx.r10.s64 + -19568;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
	// bl 0x82586680
	ctx.lr = 0x8273BC38;
	sub_82586680(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-19596
	ctx.r6.s64 = ctx.r7.s64 + -19596;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// bl 0x821d2028
	ctx.lr = 0x8273BC4C;
	sub_821D2028(ctx, base);
	// clrlwi r5,r25,31
	ctx.r5.u64 = r25.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8273bc60
	if (cr6.eq) goto loc_8273BC60;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8273BC60;
	sub_82130588(ctx, base);
loc_8273BC60:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8273BC6C"))) PPC_WEAK_FUNC(sub_8273BC6C);
PPC_FUNC_IMPL(__imp__sub_8273BC6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273BC70"))) PPC_WEAK_FUNC(sub_8273BC70);
PPC_FUNC_IMPL(__imp__sub_8273BC70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8273bcf0
	if (cr6.lt) goto loc_8273BCF0;
	// beq cr6,0x8273bcbc
	if (cr6.eq) goto loc_8273BCBC;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8273bc88
	if (cr6.lt) goto loc_8273BC88;
	// b 0x82246260
	sub_82246260(ctx, base);
	return;
loc_8273BC88:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,-16(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -16);
	// addi r3,r5,-16
	ctx.r3.s64 = ctx.r5.s64 + -16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273bcb8
	if (cr6.eq) goto loc_8273BCB8;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8273BCB8:
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
loc_8273BCBC:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,-16(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -16);
	// addi r3,r5,-16
	ctx.r3.s64 = ctx.r5.s64 + -16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273bcec
	if (cr6.eq) goto loc_8273BCEC;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8273BCEC:
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
loc_8273BCF0:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,-16(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -16);
	// addi r3,r5,-16
	ctx.r3.s64 = ctx.r5.s64 + -16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273bd20
	if (cr6.eq) goto loc_8273BD20;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8273BD20:
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8273BD24"))) PPC_WEAK_FUNC(sub_8273BD24);
PPC_FUNC_IMPL(__imp__sub_8273BD24) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273BD28"))) PPC_WEAK_FUNC(sub_8273BD28);
PPC_FUNC_IMPL(__imp__sub_8273BD28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// ble cr6,0x8273bd74
	if (!cr6.gt) goto loc_8273BD74;
loc_8273BD3C:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bge cr6,0x8273bd74
	if (!cr6.lt) goto loc_8273BD74;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// srawi r7,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	r11.s64 = temp.s64;
	// bgt cr6,0x8273bd3c
	if (cr6.gt) goto loc_8273BD3C;
loc_8273BD74:
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273BD80"))) PPC_WEAK_FUNC(sub_8273BD80);
PPC_FUNC_IMPL(__imp__sub_8273BD80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8273BD88;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,-192
	r31.s64 = ctx.r1.s64 + -192;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273BDB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 28);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8273BDD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r6,28(r29)
	ctx.r6.u64 = PPC_LOAD_U16(r29.u32 + 28);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lwz r5,32(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lhzx r9,r10,r5
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r5.u32);
	// rotlwi r10,r9,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// add r28,r10,r11
	r28.u64 = ctx.r10.u64 + r11.u64;
	// lhz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// rlwinm r12,r6,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8273BE14;
	sub_823DBFF4(ctx, base);
	// lwz r5,0(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stwux r5,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r1.u32 = ea;
	// addi r21,r1,80
	r21.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x8273bf84
	if (!cr6.gt) goto loc_8273BF84;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r27,0
	r27.s64 = 0;
	// mr r24,r21
	r24.u64 = r21.u64;
	// addi r22,r11,2384
	r22.s64 = r11.s64 + 2384;
loc_8273BE40:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r11,r27
	r30.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8273BE5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lvx128 v127,r0,r23
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8273BE74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// beq cr6,0x8273bf68
	if (cr6.eq) goto loc_8273BF68;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x8273bf68
	if (cr6.eq) goto loc_8273BF68;
	// lbz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 4);
	// rlwinm r11,r10,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273bee4
	if (!cr6.eq) goto loc_8273BEE4;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273bed4
	if (cr6.eq) goto loc_8273BED4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8273bed8
	if (!cr6.eq) goto loc_8273BED8;
loc_8273BED4:
	// li r11,0
	r11.s64 = 0;
loc_8273BED8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273bf68
	if (!cr6.eq) goto loc_8273BF68;
loc_8273BEE4:
	// rlwinm r11,r10,0,25,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273bf20
	if (!cr6.eq) goto loc_8273BF20;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273bf10
	if (cr6.eq) goto loc_8273BF10;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8273bf14
	if (!cr6.eq) goto loc_8273BF14;
loc_8273BF10:
	// li r11,0
	r11.s64 = 0;
loc_8273BF14:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273bf68
	if (!cr6.eq) goto loc_8273BF68;
loc_8273BF20:
	// rlwinm r11,r10,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273bf5c
	if (!cr6.eq) goto loc_8273BF5C;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273bf4c
	if (cr6.eq) goto loc_8273BF4C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,0,26,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8273bf50
	if (!cr6.eq) goto loc_8273BF50;
loc_8273BF4C:
	// li r11,0
	r11.s64 = 0;
loc_8273BF50:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273bf68
	if (cr6.eq) goto loc_8273BF68;
loc_8273BF5C:
	// stw r30,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r30.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
loc_8273BF68:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8273be40
	if (cr6.lt) goto loc_8273BE40;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8273bf98
	if (!cr6.eq) goto loc_8273BF98;
loc_8273BF84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d922c
	return;
loc_8273BF98:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// twllei r29,0
	// lwz r4,2192(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r4,r5
	ctx.r10.s64 = ctx.r4.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r3,r11,1
	ctx.r3.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// divw r7,r3,r29
	ctx.r7.s32 = ctx.r3.s32 / r29.s32;
	// rotlwi r9,r3,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// mullw r5,r7,r29
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(r29.s32);
	// subf r4,r5,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r5.s64;
	// addi r3,r9,-1
	ctx.r3.s64 = ctx.r9.s64 + -1;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r9,r29,r3
	ctx.r9.u64 = r29.u64 & ~ctx.r3.u64;
	// twlgei r9,-1
	// lwzx r3,r10,r21
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r21.u32);
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8273C000"))) PPC_WEAK_FUNC(sub_8273C000);
PPC_FUNC_IMPL(__imp__sub_8273C000) {
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
	ctx.lr = 0x8273C008;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82246138
	ctx.lr = 0x8273C014;
	sub_82246138(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82203388
	ctx.lr = 0x8273C020;
	sub_82203388(ctx, base);
	// li r11,6
	r11.s64 = 6;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r11.u32);
	// stw r10,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// lis r31,-32114
	r31.s64 = -2104623104;
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-23452(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23452);
	// bl 0x82572c48
	ctx.lr = 0x8273C048;
	sub_82572C48(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,182(r1)
	PPC_STORE_U16(ctx.r1.u32 + 182, ctx.r3.u16);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8273c0bc
	if (cr6.eq) goto loc_8273C0BC;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r30,r10,24092
	r30.s64 = ctx.r10.s64 + 24092;
	// addi r29,r9,-7492
	r29.s64 = ctx.r9.s64 + -7492;
loc_8273C068:
	// lwz r10,-23452(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -23452);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,112(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r3,r10,0,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dedd8
	ctx.lr = 0x8273C094;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273c0a0
	if (cr6.eq) goto loc_8273C0A0;
	// bl 0x82737bd8
	ctx.lr = 0x8273C0A0;
	sub_82737BD8(ctx, base);
loc_8273C0A0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-23452(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23452);
	// bl 0x82571250
	ctx.lr = 0x8273C0AC;
	sub_82571250(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,182(r1)
	PPC_STORE_U16(ctx.r1.u32 + 182, ctx.r3.u16);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8273c068
	if (!cr6.eq) goto loc_8273C068;
loc_8273C0BC:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x822460e0
	ctx.lr = 0x8273C0CC;
	sub_822460E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8273c104
	if (!cr6.gt) goto loc_8273C104;
loc_8273C0D4:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mullw r11,r9,r31
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r31.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8273af48
	ctx.lr = 0x8273C0EC;
	sub_8273AF48(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x822460e0
	ctx.lr = 0x8273C0FC;
	sub_822460E0(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x8273c0d4
	if (cr6.lt) goto loc_8273C0D4;
loc_8273C104:
	// lbz r10,244(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 244);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273c11c
	if (cr6.eq) goto loc_8273C11C;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23388
	ctx.r3.s64 = r11.s64 + -23388;
	// bl 0x821c8f70
	ctx.lr = 0x8273C11C;
	sub_821C8F70(ctx, base);
loc_8273C11C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273C124"))) PPC_WEAK_FUNC(sub_8273C124);
PPC_FUNC_IMPL(__imp__sub_8273C124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273C128"))) PPC_WEAK_FUNC(sub_8273C128);
PPC_FUNC_IMPL(__imp__sub_8273C128) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x82130000
	ctx.lr = 0x8273C14C;
	sub_82130000(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x822460e0
	ctx.lr = 0x8273C15C;
	sub_822460E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8273c198
	if (!cr6.gt) goto loc_8273C198;
loc_8273C164:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mullw r10,r10,r31
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r31.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x8273abc0
	ctx.lr = 0x8273C180;
	sub_8273ABC0(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x822460e0
	ctx.lr = 0x8273C190;
	sub_822460E0(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x8273c164
	if (cr6.lt) goto loc_8273C164;
loc_8273C198:
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

__attribute__((alias("__imp__sub_8273C1B4"))) PPC_WEAK_FUNC(sub_8273C1B4);
PPC_FUNC_IMPL(__imp__sub_8273C1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273C1B8"))) PPC_WEAK_FUNC(sub_8273C1B8);
PPC_FUNC_IMPL(__imp__sub_8273C1B8) {
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
	ctx.lr = 0x8273C1C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
loc_8273C1D0:
	// lhz r11,24(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 24);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273c208
	if (cr6.eq) goto loc_8273C208;
	// li r31,0
	r31.s64 = 0;
loc_8273C1E4:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x8273e108
	ctx.lr = 0x8273C1F4;
	sub_8273E108(ctx, base);
	// lhz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 24);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x8273c1e4
	if (cr6.lt) goto loc_8273C1E4;
loc_8273C208:
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8273c22c
	if (cr6.eq) goto loc_8273C22C;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273c22c
	if (cr6.eq) goto loc_8273C22C;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8273c1b8
	ctx.lr = 0x8273C22C;
	sub_8273C1B8(ctx, base);
loc_8273C22C:
	// lwz r29,12(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8273c240
	if (cr6.eq) goto loc_8273C240;
	// li r27,1
	r27.s64 = 1;
	// b 0x8273c1d0
	goto loc_8273C1D0;
loc_8273C240:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8273C248"))) PPC_WEAK_FUNC(sub_8273C248);
PPC_FUNC_IMPL(__imp__sub_8273C248) {
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
	ctx.lr = 0x8273C250;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r11,24(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 24);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// beq cr6,0x8273c2e0
	if (cr6.eq) goto loc_8273C2E0;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_8273C280:
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r11,r29
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8273C29C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lhz r5,24(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 24);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// cmpw cr6,r30,r5
	cr6.compare<int32_t>(r30.s32, ctx.r5.s32, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// blt cr6,0x8273c280
	if (cr6.lt) goto loc_8273C280;
loc_8273C2E0:
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8273c334
	if (cr6.eq) goto loc_8273C334;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273c334
	if (cr6.eq) goto loc_8273C334;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273c248
	ctx.lr = 0x8273C304;
	sub_8273C248(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r5.u32);
loc_8273C334:
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8273c380
	if (cr6.eq) goto loc_8273C380;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273c248
	ctx.lr = 0x8273C34C;
	sub_8273C248(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r5.u32);
loc_8273C380:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8273C38C"))) PPC_WEAK_FUNC(sub_8273C38C);
PPC_FUNC_IMPL(__imp__sub_8273C38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273C390"))) PPC_WEAK_FUNC(sub_8273C390);
PPC_FUNC_IMPL(__imp__sub_8273C390) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8273C39C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// bge cr6,0x8273c3dc
	if (!cr6.lt) goto loc_8273C3DC;
loc_8273C3BC:
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// blt cr6,0x8273c3bc
	if (cr6.lt) goto loc_8273C3BC;
loc_8273C3DC:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bne cr6,0x8273c39c
	if (!cr6.eq) goto loc_8273C39C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273C3F0"))) PPC_WEAK_FUNC(sub_8273C3F0);
PPC_FUNC_IMPL(__imp__sub_8273C3F0) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8273c464
	if (!cr6.lt) goto loc_8273C464;
loc_8273C418:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bge cr6,0x8273c43c
	if (!cr6.lt) goto loc_8273C43C;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_8273C43C:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// stwx r10,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r10.u32);
	// blt cr6,0x8273c418
	if (cr6.lt) goto loc_8273C418;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
loc_8273C464:
	// bne cr6,0x8273c480
	if (!cr6.eq) goto loc_8273C480;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 + ctx.r3.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// lwz r11,-4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stwx r11,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, r11.u32);
loc_8273C480:
	// bl 0x8273bd28
	ctx.lr = 0x8273C484;
	sub_8273BD28(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8273C498"))) PPC_WEAK_FUNC(sub_8273C498);
PPC_FUNC_IMPL(__imp__sub_8273C498) {
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
	ctx.lr = 0x8273C4A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273c4cc
	if (cr6.eq) goto loc_8273C4CC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x8273C4C0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
loc_8273C4CC:
	// lwz r4,4(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273c4ec
	if (cr6.eq) goto loc_8273C4EC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x8273C4E0;
	sub_8217D890(ctx, base);
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,4(r26)
	PPC_STORE_U32(r26.u32 + 4, ctx.r10.u32);
loc_8273C4EC:
	// lwz r28,0(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8273c5d4
	if (cr6.eq) goto loc_8273C5D4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r27,r11,-26560
	r27.s64 = r11.s64 + -26560;
loc_8273C500:
	// lwz r30,4(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8273c564
	if (cr6.eq) goto loc_8273C564;
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d828
	ctx.lr = 0x8273C51C;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8273c544
	if (cr6.eq) goto loc_8273C544;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x8273c558
	goto loc_8273C558;
loc_8273C544:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2378
	ctx.lr = 0x8273C554;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_8273C558:
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
loc_8273C564:
	// lwz r30,8(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8273c5c8
	if (cr6.eq) goto loc_8273C5C8;
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d828
	ctx.lr = 0x8273C580;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8273c5a8
	if (cr6.eq) goto loc_8273C5A8;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x8273c5bc
	goto loc_8273C5BC;
loc_8273C5A8:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2378
	ctx.lr = 0x8273C5B8;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_8273C5BC:
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r11.u32);
loc_8273C5C8:
	// lwz r28,4(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8273c500
	if (!cr6.eq) goto loc_8273C500;
loc_8273C5D4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8273C5E0"))) PPC_WEAK_FUNC(sub_8273C5E0);
PPC_FUNC_IMPL(__imp__sub_8273C5E0) {
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
	ctx.lr = 0x8273C5E8;
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
	// srawi r28,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r28.s64 = r11.s32 >> 2;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x8273c65c
	if (cr6.lt) goto loc_8273C65C;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// lwzx r6,r11,r29
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8273c3f0
	ctx.lr = 0x8273C62C;
	sub_8273C3F0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8273c65c
	if (cr6.eq) goto loc_8273C65C;
loc_8273C634:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8273c3f0
	ctx.lr = 0x8273C654;
	sub_8273C3F0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x8273c634
	if (!cr6.eq) goto loc_8273C634;
loc_8273C65C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8273C664"))) PPC_WEAK_FUNC(sub_8273C664);
PPC_FUNC_IMPL(__imp__sub_8273C664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273C668"))) PPC_WEAK_FUNC(sub_8273C668);
PPC_FUNC_IMPL(__imp__sub_8273C668) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8273c248
	ctx.lr = 0x8273C684;
	sub_8273C248(ctx, base);
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

__attribute__((alias("__imp__sub_8273C69C"))) PPC_WEAK_FUNC(sub_8273C69C);
PPC_FUNC_IMPL(__imp__sub_8273C69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273C6A0"))) PPC_WEAK_FUNC(sub_8273C6A0);
PPC_FUNC_IMPL(__imp__sub_8273C6A0) {
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
	// lhz r11,174(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 174);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273c6c8
	if (cr6.eq) goto loc_8273C6C8;
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// bl 0x82130588
	ctx.lr = 0x8273C6C8;
	sub_82130588(ctx, base);
loc_8273C6C8:
	// lhz r11,158(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273c6dc
	if (cr6.eq) goto loc_8273C6DC;
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// bl 0x82130588
	ctx.lr = 0x8273C6DC;
	sub_82130588(ctx, base);
loc_8273C6DC:
	// lhz r11,150(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 150);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273c6f0
	if (cr6.eq) goto loc_8273C6F0;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// bl 0x82130588
	ctx.lr = 0x8273C6F0;
	sub_82130588(ctx, base);
loc_8273C6F0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-18736
	ctx.r10.s64 = r11.s64 + -18736;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82246f48
	ctx.lr = 0x8273C704;
	sub_82246F48(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8273C718"))) PPC_WEAK_FUNC(sub_8273C718);
PPC_FUNC_IMPL(__imp__sub_8273C718) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8273C720;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8273d098
	if (cr6.lt) goto loc_8273D098;
	// beq cr6,0x8273cc04
	if (cr6.eq) goto loc_8273CC04;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8273c748
	if (cr6.lt) goto loc_8273C748;
	// bl 0x82247060
	ctx.lr = 0x8273C740;
	sub_82247060(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9210
	return;
loc_8273C748:
	// lis r11,341
	r11.s64 = 22347776;
	// li r10,192
	ctx.r10.s64 = 192;
	// ori r9,r11,21845
	ctx.r9.u64 = r11.u64 | 21845;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8273c77c
	if (cr6.gt) goto loc_8273C77C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-17
	ctx.r10.s64 = -17;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r9,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// ble cr6,0x8273c780
	if (!cr6.gt) goto loc_8273C780;
loc_8273C77C:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8273C780:
	// bl 0x82130528
	ctx.lr = 0x8273C784;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273d314
	if (cr6.eq) goto loc_8273D314;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addi r11,r31,-1
	r11.s64 = r31.s64 + -1;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r27,-32253
	r27.s64 = -2113732608;
	// addi r6,r9,-10272
	ctx.r6.s64 = ctx.r9.s64 + -10272;
	// addi r9,r5,2256
	ctx.r9.s64 = ctx.r5.s64 + 2256;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r28,54
	r28.s64 = 54;
	// li r29,70
	r29.s64 = 70;
	// li r30,86
	r30.s64 = 86;
	// li r31,102
	r31.s64 = 102;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r15,r11
	r15.u64 = r11.u64;
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// addi r5,r27,-18876
	ctx.r5.s64 = r27.s64 + -18876;
	// blt cr6,0x8273cb24
	if (cr6.lt) goto loc_8273CB24;
	// rlwinm r27,r4,0,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r11,r7,26
	r11.s64 = ctx.r7.s64 + 26;
	// subf r15,r27,r15
	r15.s64 = r15.s64 - r27.s64;
	// rlwinm r4,r4,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// li r22,246
	r22.s64 = 246;
	// li r23,262
	r23.s64 = 262;
	// li r24,278
	r24.s64 = 278;
	// li r16,294
	r16.s64 = 294;
	// li r25,438
	r25.s64 = 438;
	// li r26,454
	r26.s64 = 454;
	// li r17,470
	r17.s64 = 470;
	// li r18,486
	r18.s64 = 486;
	// li r27,630
	r27.s64 = 630;
	// li r19,646
	r19.s64 = 646;
	// li r20,662
	r20.s64 = 662;
	// li r21,678
	r21.s64 = 678;
loc_8273C824:
	// stw r10,-22(r11)
	PPC_STORE_U32(r11.u32 + -22, ctx.r10.u32);
	// stw r10,-18(r11)
	PPC_STORE_U32(r11.u32 + -18, ctx.r10.u32);
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
	// stfs f0,2(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2, temp.u32);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// stw r8,6(r11)
	PPC_STORE_U32(r11.u32 + 6, ctx.r8.u32);
	// stw r10,10(r11)
	PPC_STORE_U32(r11.u32 + 10, ctx.r10.u32);
	// stw r10,14(r11)
	PPC_STORE_U32(r11.u32 + 14, ctx.r10.u32);
	// stw r10,18(r11)
	PPC_STORE_U32(r11.u32 + 18, ctx.r10.u32);
	// sth r10,22(r11)
	PPC_STORE_U16(r11.u32 + 22, ctx.r10.u16);
	// sth r10,24(r11)
	PPC_STORE_U16(r11.u32 + 24, ctx.r10.u16);
	// stfs f0,34(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 34, temp.u32);
	// stfs f0,38(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 38, temp.u32);
	// stb r10,50(r11)
	PPC_STORE_U8(r11.u32 + 50, ctx.r10.u8);
	// stfs f0,42(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 42, temp.u32);
	// stfs f0,46(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 46, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,30(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 30, temp.u32);
	// stfs f0,26(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 26, temp.u32);
	// lwz r14,-22(r11)
	r14.u64 = PPC_LOAD_U32(r11.u32 + -22);
	// ori r14,r14,4
	r14.u64 = r14.u64 | 4;
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r14,-22(r11)
	PPC_STORE_U32(r11.u32 + -22, r14.u32);
	// stw r10,118(r11)
	PPC_STORE_U32(r11.u32 + 118, ctx.r10.u32);
	// sth r10,122(r11)
	PPC_STORE_U16(r11.u32 + 122, ctx.r10.u16);
	// sth r10,124(r11)
	PPC_STORE_U16(r11.u32 + 124, ctx.r10.u16);
	// stw r10,126(r11)
	PPC_STORE_U32(r11.u32 + 126, ctx.r10.u32);
	// sth r10,130(r11)
	PPC_STORE_U16(r11.u32 + 130, ctx.r10.u16);
	// sth r10,132(r11)
	PPC_STORE_U16(r11.u32 + 132, ctx.r10.u16);
	// stfs f0,138(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 138, temp.u32);
	// stw r10,134(r11)
	PPC_STORE_U32(r11.u32 + 134, ctx.r10.u32);
	// stw r10,142(r11)
	PPC_STORE_U32(r11.u32 + 142, ctx.r10.u32);
	// sth r10,146(r11)
	PPC_STORE_U16(r11.u32 + 146, ctx.r10.u16);
	// sth r10,148(r11)
	PPC_STORE_U16(r11.u32 + 148, ctx.r10.u16);
	// stw r10,170(r11)
	PPC_STORE_U32(r11.u32 + 170, ctx.r10.u32);
	// stw r8,150(r11)
	PPC_STORE_U32(r11.u32 + 150, ctx.r8.u32);
	// stb r10,154(r11)
	PPC_STORE_U8(r11.u32 + 154, ctx.r10.u8);
	// stw r10,174(r11)
	PPC_STORE_U32(r11.u32 + 174, ctx.r10.u32);
	// stw r10,178(r11)
	PPC_STORE_U32(r11.u32 + 178, ctx.r10.u32);
	// stw r10,182(r11)
	PPC_STORE_U32(r11.u32 + 182, ctx.r10.u32);
	// stw r10,186(r11)
	PPC_STORE_U32(r11.u32 + 186, ctx.r10.u32);
	// sth r10,190(r11)
	PPC_STORE_U16(r11.u32 + 190, ctx.r10.u16);
	// sth r10,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r10.u16);
	// stfs f0,194(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 194, temp.u32);
	// stw r5,166(r11)
	PPC_STORE_U32(r11.u32 + 166, ctx.r5.u32);
	// stw r8,198(r11)
	PPC_STORE_U32(r11.u32 + 198, ctx.r8.u32);
	// stw r10,202(r11)
	PPC_STORE_U32(r11.u32 + 202, ctx.r10.u32);
	// stw r10,206(r11)
	PPC_STORE_U32(r11.u32 + 206, ctx.r10.u32);
	// stw r10,210(r11)
	PPC_STORE_U32(r11.u32 + 210, ctx.r10.u32);
	// sth r10,214(r11)
	PPC_STORE_U16(r11.u32 + 214, ctx.r10.u16);
	// sth r10,216(r11)
	PPC_STORE_U16(r11.u32 + 216, ctx.r10.u16);
	// stfs f0,226(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 226, temp.u32);
	// stfs f0,230(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 230, temp.u32);
	// stb r10,242(r11)
	PPC_STORE_U8(r11.u32 + 242, ctx.r10.u8);
	// stfs f0,234(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 234, temp.u32);
	// stfs f0,238(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 238, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,222(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 222, temp.u32);
	// stfs f0,218(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 218, temp.u32);
	// lwz r14,170(r11)
	r14.u64 = PPC_LOAD_U32(r11.u32 + 170);
	// ori r14,r14,4
	r14.u64 = r14.u64 | 4;
	// stw r6,166(r11)
	PPC_STORE_U32(r11.u32 + 166, ctx.r6.u32);
	// stw r14,170(r11)
	PPC_STORE_U32(r11.u32 + 170, r14.u32);
	// stw r10,310(r11)
	PPC_STORE_U32(r11.u32 + 310, ctx.r10.u32);
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// sth r10,314(r11)
	PPC_STORE_U16(r11.u32 + 314, ctx.r10.u16);
	// sth r10,316(r11)
	PPC_STORE_U16(r11.u32 + 316, ctx.r10.u16);
	// stw r10,318(r11)
	PPC_STORE_U32(r11.u32 + 318, ctx.r10.u32);
	// sth r10,322(r11)
	PPC_STORE_U16(r11.u32 + 322, ctx.r10.u16);
	// sth r10,324(r11)
	PPC_STORE_U16(r11.u32 + 324, ctx.r10.u16);
	// stfs f0,330(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 330, temp.u32);
	// stw r10,326(r11)
	PPC_STORE_U32(r11.u32 + 326, ctx.r10.u32);
	// stw r10,334(r11)
	PPC_STORE_U32(r11.u32 + 334, ctx.r10.u32);
	// sth r10,338(r11)
	PPC_STORE_U16(r11.u32 + 338, ctx.r10.u16);
	// sth r10,340(r11)
	PPC_STORE_U16(r11.u32 + 340, ctx.r10.u16);
	// stw r10,362(r11)
	PPC_STORE_U32(r11.u32 + 362, ctx.r10.u32);
	// stw r8,342(r11)
	PPC_STORE_U32(r11.u32 + 342, ctx.r8.u32);
	// stb r10,346(r11)
	PPC_STORE_U8(r11.u32 + 346, ctx.r10.u8);
	// stw r10,366(r11)
	PPC_STORE_U32(r11.u32 + 366, ctx.r10.u32);
	// stw r10,370(r11)
	PPC_STORE_U32(r11.u32 + 370, ctx.r10.u32);
	// stw r10,374(r11)
	PPC_STORE_U32(r11.u32 + 374, ctx.r10.u32);
	// stw r10,378(r11)
	PPC_STORE_U32(r11.u32 + 378, ctx.r10.u32);
	// sth r10,382(r11)
	PPC_STORE_U16(r11.u32 + 382, ctx.r10.u16);
	// sth r10,384(r11)
	PPC_STORE_U16(r11.u32 + 384, ctx.r10.u16);
	// stfs f0,386(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 386, temp.u32);
	// stw r5,358(r11)
	PPC_STORE_U32(r11.u32 + 358, ctx.r5.u32);
	// stw r8,390(r11)
	PPC_STORE_U32(r11.u32 + 390, ctx.r8.u32);
	// stw r10,394(r11)
	PPC_STORE_U32(r11.u32 + 394, ctx.r10.u32);
	// stw r10,398(r11)
	PPC_STORE_U32(r11.u32 + 398, ctx.r10.u32);
	// stw r10,402(r11)
	PPC_STORE_U32(r11.u32 + 402, ctx.r10.u32);
	// sth r10,406(r11)
	PPC_STORE_U16(r11.u32 + 406, ctx.r10.u16);
	// sth r10,408(r11)
	PPC_STORE_U16(r11.u32 + 408, ctx.r10.u16);
	// stfs f0,418(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 418, temp.u32);
	// stfs f0,422(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 422, temp.u32);
	// stb r10,434(r11)
	PPC_STORE_U8(r11.u32 + 434, ctx.r10.u8);
	// stfs f0,426(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 426, temp.u32);
	// stfs f0,430(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 430, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r17
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,414(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 414, temp.u32);
	// stfs f0,410(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 410, temp.u32);
	// lwz r14,362(r11)
	r14.u64 = PPC_LOAD_U32(r11.u32 + 362);
	// ori r14,r14,4
	r14.u64 = r14.u64 | 4;
	// stw r6,358(r11)
	PPC_STORE_U32(r11.u32 + 358, ctx.r6.u32);
	// stw r14,362(r11)
	PPC_STORE_U32(r11.u32 + 362, r14.u32);
	// stw r10,502(r11)
	PPC_STORE_U32(r11.u32 + 502, ctx.r10.u32);
	// sth r10,506(r11)
	PPC_STORE_U16(r11.u32 + 506, ctx.r10.u16);
	// sth r10,508(r11)
	PPC_STORE_U16(r11.u32 + 508, ctx.r10.u16);
	// stw r10,510(r11)
	PPC_STORE_U32(r11.u32 + 510, ctx.r10.u32);
	// sth r10,514(r11)
	PPC_STORE_U16(r11.u32 + 514, ctx.r10.u16);
	// sth r10,516(r11)
	PPC_STORE_U16(r11.u32 + 516, ctx.r10.u16);
	// stfs f0,522(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 522, temp.u32);
	// stw r10,518(r11)
	PPC_STORE_U32(r11.u32 + 518, ctx.r10.u32);
	// stw r10,526(r11)
	PPC_STORE_U32(r11.u32 + 526, ctx.r10.u32);
	// sth r10,530(r11)
	PPC_STORE_U16(r11.u32 + 530, ctx.r10.u16);
	// sth r10,532(r11)
	PPC_STORE_U16(r11.u32 + 532, ctx.r10.u16);
	// stw r8,534(r11)
	PPC_STORE_U32(r11.u32 + 534, ctx.r8.u32);
	// stb r10,538(r11)
	PPC_STORE_U8(r11.u32 + 538, ctx.r10.u8);
	// stw r10,554(r11)
	PPC_STORE_U32(r11.u32 + 554, ctx.r10.u32);
	// stw r10,558(r11)
	PPC_STORE_U32(r11.u32 + 558, ctx.r10.u32);
	// stw r10,562(r11)
	PPC_STORE_U32(r11.u32 + 562, ctx.r10.u32);
	// stw r10,566(r11)
	PPC_STORE_U32(r11.u32 + 566, ctx.r10.u32);
	// stw r10,570(r11)
	PPC_STORE_U32(r11.u32 + 570, ctx.r10.u32);
	// sth r10,574(r11)
	PPC_STORE_U16(r11.u32 + 574, ctx.r10.u16);
	// sth r10,576(r11)
	PPC_STORE_U16(r11.u32 + 576, ctx.r10.u16);
	// stfs f0,578(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 578, temp.u32);
	// stw r5,550(r11)
	PPC_STORE_U32(r11.u32 + 550, ctx.r5.u32);
	// stw r8,582(r11)
	PPC_STORE_U32(r11.u32 + 582, ctx.r8.u32);
	// stw r10,586(r11)
	PPC_STORE_U32(r11.u32 + 586, ctx.r10.u32);
	// stw r10,590(r11)
	PPC_STORE_U32(r11.u32 + 590, ctx.r10.u32);
	// stw r10,594(r11)
	PPC_STORE_U32(r11.u32 + 594, ctx.r10.u32);
	// sth r10,598(r11)
	PPC_STORE_U16(r11.u32 + 598, ctx.r10.u16);
	// sth r10,600(r11)
	PPC_STORE_U16(r11.u32 + 600, ctx.r10.u16);
	// stfs f0,610(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 610, temp.u32);
	// stfs f0,614(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 614, temp.u32);
	// stb r10,626(r11)
	PPC_STORE_U8(r11.u32 + 626, ctx.r10.u8);
	// stfs f0,618(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 618, temp.u32);
	// stfs f0,622(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 622, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,768
	ctx.r7.s64 = ctx.r7.s64 + 768;
	// stvx128 v63,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,606(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 606, temp.u32);
	// stfs f0,602(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 602, temp.u32);
	// lwz r14,554(r11)
	r14.u64 = PPC_LOAD_U32(r11.u32 + 554);
	// ori r14,r14,4
	r14.u64 = r14.u64 | 4;
	// stw r6,550(r11)
	PPC_STORE_U32(r11.u32 + 550, ctx.r6.u32);
	// stw r14,554(r11)
	PPC_STORE_U32(r11.u32 + 554, r14.u32);
	// stw r10,694(r11)
	PPC_STORE_U32(r11.u32 + 694, ctx.r10.u32);
	// sth r10,698(r11)
	PPC_STORE_U16(r11.u32 + 698, ctx.r10.u16);
	// sth r10,700(r11)
	PPC_STORE_U16(r11.u32 + 700, ctx.r10.u16);
	// stw r10,702(r11)
	PPC_STORE_U32(r11.u32 + 702, ctx.r10.u32);
	// sth r10,706(r11)
	PPC_STORE_U16(r11.u32 + 706, ctx.r10.u16);
	// sth r10,708(r11)
	PPC_STORE_U16(r11.u32 + 708, ctx.r10.u16);
	// stfs f0,714(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 714, temp.u32);
	// stw r10,710(r11)
	PPC_STORE_U32(r11.u32 + 710, ctx.r10.u32);
	// stw r10,718(r11)
	PPC_STORE_U32(r11.u32 + 718, ctx.r10.u32);
	// sth r10,722(r11)
	PPC_STORE_U16(r11.u32 + 722, ctx.r10.u16);
	// sth r10,724(r11)
	PPC_STORE_U16(r11.u32 + 724, ctx.r10.u16);
	// stw r8,726(r11)
	PPC_STORE_U32(r11.u32 + 726, ctx.r8.u32);
	// stb r10,730(r11)
	PPC_STORE_U8(r11.u32 + 730, ctx.r10.u8);
	// addi r11,r11,768
	r11.s64 = r11.s64 + 768;
	// bne 0x8273c824
	if (!cr0.eq) goto loc_8273C824;
loc_8273CB24:
	// cmpwi cr6,r15,0
	cr6.compare<int32_t>(r15.s32, 0, xer);
	// blt cr6,0x8273d318
	if (cr6.lt) goto loc_8273D318;
	// addi r11,r7,26
	r11.s64 = ctx.r7.s64 + 26;
loc_8273CB30:
	// stw r10,-22(r11)
	PPC_STORE_U32(r11.u32 + -22, ctx.r10.u32);
	// addic. r15,r15,-1
	xer.ca = r15.u32 > 0;
	r15.s64 = r15.s64 + -1;
	cr0.compare<int32_t>(r15.s32, 0, xer);
	// stw r10,-18(r11)
	PPC_STORE_U32(r11.u32 + -18, ctx.r10.u32);
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
	// stfs f0,2(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2, temp.u32);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// stw r8,6(r11)
	PPC_STORE_U32(r11.u32 + 6, ctx.r8.u32);
	// stw r10,10(r11)
	PPC_STORE_U32(r11.u32 + 10, ctx.r10.u32);
	// stw r10,14(r11)
	PPC_STORE_U32(r11.u32 + 14, ctx.r10.u32);
	// stw r10,18(r11)
	PPC_STORE_U32(r11.u32 + 18, ctx.r10.u32);
	// sth r10,22(r11)
	PPC_STORE_U16(r11.u32 + 22, ctx.r10.u16);
	// sth r10,24(r11)
	PPC_STORE_U16(r11.u32 + 24, ctx.r10.u16);
	// stfs f0,34(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 34, temp.u32);
	// stfs f0,38(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 38, temp.u32);
	// stb r10,50(r11)
	PPC_STORE_U8(r11.u32 + 50, ctx.r10.u8);
	// stfs f0,42(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 42, temp.u32);
	// stfs f0,46(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 46, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,30(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 30, temp.u32);
	// stfs f0,26(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 26, temp.u32);
	// lwz r4,-22(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -22);
	// ori r4,r4,4
	ctx.r4.u64 = ctx.r4.u64 | 4;
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r4,-22(r11)
	PPC_STORE_U32(r11.u32 + -22, ctx.r4.u32);
	// addi r7,r7,192
	ctx.r7.s64 = ctx.r7.s64 + 192;
	// stw r10,118(r11)
	PPC_STORE_U32(r11.u32 + 118, ctx.r10.u32);
	// sth r10,122(r11)
	PPC_STORE_U16(r11.u32 + 122, ctx.r10.u16);
	// sth r10,124(r11)
	PPC_STORE_U16(r11.u32 + 124, ctx.r10.u16);
	// stw r10,126(r11)
	PPC_STORE_U32(r11.u32 + 126, ctx.r10.u32);
	// sth r10,130(r11)
	PPC_STORE_U16(r11.u32 + 130, ctx.r10.u16);
	// sth r10,132(r11)
	PPC_STORE_U16(r11.u32 + 132, ctx.r10.u16);
	// stfs f0,138(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 138, temp.u32);
	// stw r10,134(r11)
	PPC_STORE_U32(r11.u32 + 134, ctx.r10.u32);
	// stw r10,142(r11)
	PPC_STORE_U32(r11.u32 + 142, ctx.r10.u32);
	// sth r10,146(r11)
	PPC_STORE_U16(r11.u32 + 146, ctx.r10.u16);
	// sth r10,148(r11)
	PPC_STORE_U16(r11.u32 + 148, ctx.r10.u16);
	// stw r8,150(r11)
	PPC_STORE_U32(r11.u32 + 150, ctx.r8.u32);
	// stb r10,154(r11)
	PPC_STORE_U8(r11.u32 + 154, ctx.r10.u8);
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// bge 0x8273cb30
	if (!cr0.lt) goto loc_8273CB30;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9210
	return;
loc_8273CC04:
	// lis r11,372
	r11.s64 = 24379392;
	// li r10,176
	ctx.r10.s64 = 176;
	// ori r9,r11,23831
	ctx.r9.u64 = r11.u64 | 23831;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8273cc30
	if (cr6.gt) goto loc_8273CC30;
	// mulli r11,r31,176
	r11.s64 = r31.s64 * 176;
	// li r10,-17
	ctx.r10.s64 = -17;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8273cc34
	if (!cr6.gt) goto loc_8273CC34;
loc_8273CC30:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8273CC34:
	// bl 0x82130528
	ctx.lr = 0x8273CC38;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273d314
	if (cr6.eq) goto loc_8273D314;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// addi r4,r31,-1
	ctx.r4.s64 = r31.s64 + -1;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r31,r4,1
	r31.s64 = ctx.r4.s64 + 1;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// addi r6,r6,-18876
	ctx.r6.s64 = ctx.r6.s64 + -18876;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// addi r5,r5,-10220
	ctx.r5.s64 = ctx.r5.s64 + -10220;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x8273cfc8
	if (cr6.lt) goto loc_8273CFC8;
	// rlwinm r3,r31,0,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r11,r7,26
	r11.s64 = ctx.r7.s64 + 26;
	// rlwinm r31,r31,30,2,31
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
loc_8273CCB4:
	// stw r10,-22(r11)
	PPC_STORE_U32(r11.u32 + -22, ctx.r10.u32);
	// li r4,54
	ctx.r4.s64 = 54;
	// stw r10,-18(r11)
	PPC_STORE_U32(r11.u32 + -18, ctx.r10.u32);
	// li r3,70
	ctx.r3.s64 = 70;
	// stw r10,-14(r11)
	PPC_STORE_U32(r11.u32 + -14, ctx.r10.u32);
	// li r31,86
	r31.s64 = 86;
	// stw r10,-10(r11)
	PPC_STORE_U32(r11.u32 + -10, ctx.r10.u32);
	// li r30,102
	r30.s64 = 102;
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// li r29,230
	r29.s64 = 230;
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// li r28,246
	r28.s64 = 246;
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// stfs f0,2(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2, temp.u32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// li r27,262
	r27.s64 = 262;
	// stw r8,6(r11)
	PPC_STORE_U32(r11.u32 + 6, ctx.r8.u32);
	// li r26,278
	r26.s64 = 278;
	// stw r10,10(r11)
	PPC_STORE_U32(r11.u32 + 10, ctx.r10.u32);
	// li r25,454
	r25.s64 = 454;
	// stw r10,14(r11)
	PPC_STORE_U32(r11.u32 + 14, ctx.r10.u32);
	// stw r10,18(r11)
	PPC_STORE_U32(r11.u32 + 18, ctx.r10.u32);
	// sth r10,22(r11)
	PPC_STORE_U16(r11.u32 + 22, ctx.r10.u16);
	// sth r10,24(r11)
	PPC_STORE_U16(r11.u32 + 24, ctx.r10.u16);
	// stfs f0,38(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 38, temp.u32);
	// stfs f0,42(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 42, temp.u32);
	// stb r10,50(r11)
	PPC_STORE_U8(r11.u32 + 50, ctx.r10.u8);
	// stfs f0,46(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 46, temp.u32);
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// stfs f0,34(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 34, temp.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,118(r11)
	PPC_STORE_U32(r11.u32 + 118, ctx.r10.u32);
	// stfs f0,30(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 30, temp.u32);
	// stfs f0,26(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 26, temp.u32);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// stfs f0,122(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 122, temp.u32);
	// stw r8,126(r11)
	PPC_STORE_U32(r11.u32 + 126, ctx.r8.u32);
	// stw r10,134(r11)
	PPC_STORE_U32(r11.u32 + 134, ctx.r10.u32);
	// stw r8,138(r11)
	PPC_STORE_U32(r11.u32 + 138, ctx.r8.u32);
	// stw r10,154(r11)
	PPC_STORE_U32(r11.u32 + 154, ctx.r10.u32);
	// lwz r7,-22(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -22);
	// ori r4,r7,2
	ctx.r4.u64 = ctx.r7.u64 | 2;
	// stw r4,-22(r11)
	PPC_STORE_U32(r11.u32 + -22, ctx.r4.u32);
	// stw r10,158(r11)
	PPC_STORE_U32(r11.u32 + 158, ctx.r10.u32);
	// stw r10,162(r11)
	PPC_STORE_U32(r11.u32 + 162, ctx.r10.u32);
	// stw r10,166(r11)
	PPC_STORE_U32(r11.u32 + 166, ctx.r10.u32);
	// stw r10,170(r11)
	PPC_STORE_U32(r11.u32 + 170, ctx.r10.u32);
	// sth r10,174(r11)
	PPC_STORE_U16(r11.u32 + 174, ctx.r10.u16);
	// sth r10,176(r11)
	PPC_STORE_U16(r11.u32 + 176, ctx.r10.u16);
	// stfs f0,178(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 178, temp.u32);
	// stw r8,182(r11)
	PPC_STORE_U32(r11.u32 + 182, ctx.r8.u32);
	// stw r6,150(r11)
	PPC_STORE_U32(r11.u32 + 150, ctx.r6.u32);
	// stw r10,186(r11)
	PPC_STORE_U32(r11.u32 + 186, ctx.r10.u32);
	// stw r10,190(r11)
	PPC_STORE_U32(r11.u32 + 190, ctx.r10.u32);
	// stw r10,194(r11)
	PPC_STORE_U32(r11.u32 + 194, ctx.r10.u32);
	// sth r10,198(r11)
	PPC_STORE_U16(r11.u32 + 198, ctx.r10.u16);
	// sth r10,200(r11)
	PPC_STORE_U16(r11.u32 + 200, ctx.r10.u16);
	// stfs f0,210(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 210, temp.u32);
	// stfs f0,214(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 214, temp.u32);
	// stb r10,226(r11)
	PPC_STORE_U8(r11.u32 + 226, ctx.r10.u8);
	// stfs f0,218(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 218, temp.u32);
	// stfs f0,222(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 222, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,294(r11)
	PPC_STORE_U32(r11.u32 + 294, ctx.r10.u32);
	// stfs f0,206(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 206, temp.u32);
	// stfs f0,202(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 202, temp.u32);
	// lwz r3,154(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 154);
	// stfs f0,298(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 298, temp.u32);
	// stw r10,330(r11)
	PPC_STORE_U32(r11.u32 + 330, ctx.r10.u32);
	// li r7,406
	ctx.r7.s64 = 406;
	// ori r4,r3,2
	ctx.r4.u64 = ctx.r3.u64 | 2;
	// stw r8,302(r11)
	PPC_STORE_U32(r11.u32 + 302, ctx.r8.u32);
	// stw r5,150(r11)
	PPC_STORE_U32(r11.u32 + 150, ctx.r5.u32);
	// li r3,422
	ctx.r3.s64 = 422;
	// stw r10,310(r11)
	PPC_STORE_U32(r11.u32 + 310, ctx.r10.u32);
	// li r31,438
	r31.s64 = 438;
	// stw r8,314(r11)
	PPC_STORE_U32(r11.u32 + 314, ctx.r8.u32);
	// rotlwi r29,r25,0
	r29.u64 = __builtin_rotateleft32(r25.u32, 0);
	// stw r4,154(r11)
	PPC_STORE_U32(r11.u32 + 154, ctx.r4.u32);
	// rotlwi r28,r10,0
	r28.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,334(r11)
	PPC_STORE_U32(r11.u32 + 334, ctx.r10.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r10,338(r11)
	PPC_STORE_U32(r11.u32 + 338, ctx.r10.u32);
	// stw r10,342(r11)
	PPC_STORE_U32(r11.u32 + 342, ctx.r10.u32);
	// stw r10,346(r11)
	PPC_STORE_U32(r11.u32 + 346, ctx.r10.u32);
	// sth r10,350(r11)
	PPC_STORE_U16(r11.u32 + 350, ctx.r10.u16);
	// sth r10,352(r11)
	PPC_STORE_U16(r11.u32 + 352, ctx.r10.u16);
	// stfs f0,354(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 354, temp.u32);
	// stw r6,326(r11)
	PPC_STORE_U32(r11.u32 + 326, ctx.r6.u32);
	// stw r8,358(r11)
	PPC_STORE_U32(r11.u32 + 358, ctx.r8.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,362(r11)
	PPC_STORE_U32(r11.u32 + 362, ctx.r10.u32);
	// stw r10,366(r11)
	PPC_STORE_U32(r11.u32 + 366, ctx.r10.u32);
	// stw r10,370(r11)
	PPC_STORE_U32(r11.u32 + 370, ctx.r10.u32);
	// sth r10,374(r11)
	PPC_STORE_U16(r11.u32 + 374, ctx.r10.u16);
	// sth r10,376(r11)
	PPC_STORE_U16(r11.u32 + 376, ctx.r10.u16);
	// stfs f0,386(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 386, temp.u32);
	// stb r10,402(r11)
	PPC_STORE_U8(r11.u32 + 402, ctx.r10.u8);
	// stfs f0,390(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 390, temp.u32);
	// stfs f0,394(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 394, temp.u32);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f0,398(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 398, temp.u32);
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addic r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,470(r11)
	PPC_STORE_U32(r11.u32 + 470, r28.u32);
	// stfs f0,382(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 382, temp.u32);
	// stfs f0,378(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 378, temp.u32);
	// lwz r3,330(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 330);
	// ori r9,r3,2
	ctx.r9.u64 = ctx.r3.u64 | 2;
	// stfs f0,474(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 474, temp.u32);
	// stw r30,506(r11)
	PPC_STORE_U32(r11.u32 + 506, r30.u32);
	// stw r8,478(r11)
	PPC_STORE_U32(r11.u32 + 478, ctx.r8.u32);
	// stw r9,330(r11)
	PPC_STORE_U32(r11.u32 + 330, ctx.r9.u32);
	// stw r5,326(r11)
	PPC_STORE_U32(r11.u32 + 326, ctx.r5.u32);
	// stw r10,486(r11)
	PPC_STORE_U32(r11.u32 + 486, ctx.r10.u32);
	// stw r8,490(r11)
	PPC_STORE_U32(r11.u32 + 490, ctx.r8.u32);
	// stw r10,510(r11)
	PPC_STORE_U32(r11.u32 + 510, ctx.r10.u32);
	// stw r10,514(r11)
	PPC_STORE_U32(r11.u32 + 514, ctx.r10.u32);
	// stw r10,518(r11)
	PPC_STORE_U32(r11.u32 + 518, ctx.r10.u32);
	// stw r10,522(r11)
	PPC_STORE_U32(r11.u32 + 522, ctx.r10.u32);
	// sth r10,526(r11)
	PPC_STORE_U16(r11.u32 + 526, ctx.r10.u16);
	// sth r10,528(r11)
	PPC_STORE_U16(r11.u32 + 528, ctx.r10.u16);
	// stfs f0,530(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 530, temp.u32);
	// stw r8,534(r11)
	PPC_STORE_U32(r11.u32 + 534, ctx.r8.u32);
	// stw r6,502(r11)
	PPC_STORE_U32(r11.u32 + 502, ctx.r6.u32);
	// stw r10,538(r11)
	PPC_STORE_U32(r11.u32 + 538, ctx.r10.u32);
	// stw r10,542(r11)
	PPC_STORE_U32(r11.u32 + 542, ctx.r10.u32);
	// stw r10,546(r11)
	PPC_STORE_U32(r11.u32 + 546, ctx.r10.u32);
	// sth r10,550(r11)
	PPC_STORE_U16(r11.u32 + 550, ctx.r10.u16);
	// sth r10,552(r11)
	PPC_STORE_U16(r11.u32 + 552, ctx.r10.u16);
	// stfs f0,562(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 562, temp.u32);
	// stfs f0,566(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 566, temp.u32);
	// stb r10,578(r11)
	PPC_STORE_U8(r11.u32 + 578, ctx.r10.u8);
	// stfs f0,570(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 570, temp.u32);
	// rotlwi r9,r4,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stfs f0,574(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 574, temp.u32);
	// li r4,582
	ctx.r4.s64 = 582;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r31,598
	r31.s64 = 598;
	// li r29,614
	r29.s64 = 614;
	// li r28,630
	r28.s64 = 630;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,704
	ctx.r7.s64 = ctx.r3.s64 + 704;
	// stvx128 v63,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r30,r27,0
	r30.u64 = __builtin_rotateleft32(r27.u32, 0);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi r30,0
	cr0.compare<uint32_t>(r30.u32, 0, xer);
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,646(r11)
	PPC_STORE_U32(r11.u32 + 646, ctx.r10.u32);
	// stfs f0,558(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 558, temp.u32);
	// stfs f0,554(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 554, temp.u32);
	// lwz r4,506(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 506);
	// ori r3,r4,2
	ctx.r3.u64 = ctx.r4.u64 | 2;
	// stfs f0,650(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 650, temp.u32);
	// stw r8,654(r11)
	PPC_STORE_U32(r11.u32 + 654, ctx.r8.u32);
	// stw r3,506(r11)
	PPC_STORE_U32(r11.u32 + 506, ctx.r3.u32);
	// stw r10,662(r11)
	PPC_STORE_U32(r11.u32 + 662, ctx.r10.u32);
	// stw r5,502(r11)
	PPC_STORE_U32(r11.u32 + 502, ctx.r5.u32);
	// stw r8,666(r11)
	PPC_STORE_U32(r11.u32 + 666, ctx.r8.u32);
	// addi r11,r11,704
	r11.s64 = r11.s64 + 704;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bne 0x8273ccb4
	if (!cr0.eq) goto loc_8273CCB4;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
loc_8273CFC8:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8273d318
	if (cr6.lt) goto loc_8273D318;
	// addi r11,r7,26
	r11.s64 = ctx.r7.s64 + 26;
	// li r28,102
	r28.s64 = 102;
	// li r29,86
	r29.s64 = 86;
	// li r30,70
	r30.s64 = 70;
	// li r31,54
	r31.s64 = 54;
loc_8273CFE4:
	// stw r10,-22(r11)
	PPC_STORE_U32(r11.u32 + -22, ctx.r10.u32);
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r10,-18(r11)
	PPC_STORE_U32(r11.u32 + -18, ctx.r10.u32);
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
	// stfs f0,2(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2, temp.u32);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r8,6(r11)
	PPC_STORE_U32(r11.u32 + 6, ctx.r8.u32);
	// stw r10,10(r11)
	PPC_STORE_U32(r11.u32 + 10, ctx.r10.u32);
	// stw r10,14(r11)
	PPC_STORE_U32(r11.u32 + 14, ctx.r10.u32);
	// stw r10,18(r11)
	PPC_STORE_U32(r11.u32 + 18, ctx.r10.u32);
	// sth r10,22(r11)
	PPC_STORE_U16(r11.u32 + 22, ctx.r10.u16);
	// sth r10,24(r11)
	PPC_STORE_U16(r11.u32 + 24, ctx.r10.u16);
	// stfs f0,34(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 34, temp.u32);
	// stfs f0,38(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 38, temp.u32);
	// stb r10,50(r11)
	PPC_STORE_U8(r11.u32 + 50, ctx.r10.u8);
	// stfs f0,42(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 42, temp.u32);
	// stfs f0,46(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 46, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,118(r11)
	PPC_STORE_U32(r11.u32 + 118, ctx.r10.u32);
	// stfs f0,30(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 30, temp.u32);
	// stfs f0,26(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 26, temp.u32);
	// stw r8,126(r11)
	PPC_STORE_U32(r11.u32 + 126, ctx.r8.u32);
	// stfs f0,122(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 122, temp.u32);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// stw r10,134(r11)
	PPC_STORE_U32(r11.u32 + 134, ctx.r10.u32);
	// addi r7,r7,176
	ctx.r7.s64 = ctx.r7.s64 + 176;
	// stw r8,138(r11)
	PPC_STORE_U32(r11.u32 + 138, ctx.r8.u32);
	// lwz r27,-22(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + -22);
	// ori r27,r27,2
	r27.u64 = r27.u64 | 2;
	// stw r27,-22(r11)
	PPC_STORE_U32(r11.u32 + -22, r27.u32);
	// addi r11,r11,176
	r11.s64 = r11.s64 + 176;
	// bge 0x8273cfe4
	if (!cr0.lt) goto loc_8273CFE4;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9210
	return;
loc_8273D098:
	// lis r11,585
	r11.s64 = 38338560;
	// li r10,112
	ctx.r10.s64 = 112;
	// ori r9,r11,9362
	ctx.r9.u64 = r11.u64 | 9362;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8273d0c4
	if (cr6.gt) goto loc_8273D0C4;
	// mulli r11,r31,112
	r11.s64 = r31.s64 * 112;
	// li r10,-17
	ctx.r10.s64 = -17;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x8273d0c8
	if (!cr6.gt) goto loc_8273D0C8;
loc_8273D0C4:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8273D0C8:
	// bl 0x82130528
	ctx.lr = 0x8273D0CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273d314
	if (cr6.eq) goto loc_8273D314;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addi r4,r31,-1
	ctx.r4.s64 = r31.s64 + -1;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// addi r31,r4,1
	r31.s64 = ctx.r4.s64 + 1;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// addi r7,r7,-18980
	ctx.r7.s64 = ctx.r7.s64 + -18980;
	// addi r6,r6,-19568
	ctx.r6.s64 = ctx.r6.s64 + -19568;
	// addi r5,r11,-11948
	ctx.r5.s64 = r11.s64 + -11948;
	// blt cr6,0x8273d298
	if (cr6.lt) goto loc_8273D298;
	// rlwinm r30,r31,0,0,29
	r30.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r11,r8,64
	r11.s64 = ctx.r8.s64 + 64;
	// rlwinm r31,r31,30,2,31
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r4,r30,r4
	ctx.r4.s64 = ctx.r4.s64 - r30.s64;
loc_8273D128:
	// stw r10,-60(r11)
	PPC_STORE_U32(r11.u32 + -60, ctx.r10.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// stw r10,-56(r11)
	PPC_STORE_U32(r11.u32 + -56, ctx.r10.u32);
	// stfs f0,-52(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -52, temp.u32);
	// stw r10,-12(r11)
	PPC_STORE_U32(r11.u32 + -12, ctx.r10.u32);
	// stw r7,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r7.u32);
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// sth r9,12(r11)
	PPC_STORE_U16(r11.u32 + 12, ctx.r9.u16);
	// stb r9,14(r11)
	PPC_STORE_U8(r11.u32 + 14, ctx.r9.u8);
	// stb r10,15(r11)
	PPC_STORE_U8(r11.u32 + 15, ctx.r10.u8);
	// stw r6,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, ctx.r6.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// sth r10,20(r11)
	PPC_STORE_U16(r11.u32 + 20, ctx.r10.u16);
	// lwz r30,-60(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -60);
	// ori r30,r30,1
	r30.u64 = r30.u64 | 1;
	// stw r30,-60(r11)
	PPC_STORE_U32(r11.u32 + -60, r30.u32);
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r8,r8,448
	ctx.r8.s64 = ctx.r8.s64 + 448;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stb r10,40(r11)
	PPC_STORE_U8(r11.u32 + 40, ctx.r10.u8);
	// stw r10,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r10.u32);
	// stfs f0,60(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// stw r10,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r10.u32);
	// stw r7,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r7.u32);
	// stw r10,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r10.u32);
	// stw r10,112(r11)
	PPC_STORE_U32(r11.u32 + 112, ctx.r10.u32);
	// stfs f0,116(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// stfs f0,120(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// sth r9,124(r11)
	PPC_STORE_U16(r11.u32 + 124, ctx.r9.u16);
	// stb r9,126(r11)
	PPC_STORE_U8(r11.u32 + 126, ctx.r9.u8);
	// stb r10,127(r11)
	PPC_STORE_U8(r11.u32 + 127, ctx.r10.u8);
	// stw r6,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r6.u32);
	// stw r10,128(r11)
	PPC_STORE_U32(r11.u32 + 128, ctx.r10.u32);
	// sth r10,132(r11)
	PPC_STORE_U16(r11.u32 + 132, ctx.r10.u16);
	// stw r5,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r5.u32);
	// lwz r30,52(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// ori r30,r30,1
	r30.u64 = r30.u64 | 1;
	// stw r30,52(r11)
	PPC_STORE_U32(r11.u32 + 52, r30.u32);
	// stw r10,144(r11)
	PPC_STORE_U32(r11.u32 + 144, ctx.r10.u32);
	// stw r10,148(r11)
	PPC_STORE_U32(r11.u32 + 148, ctx.r10.u32);
	// stw r10,164(r11)
	PPC_STORE_U32(r11.u32 + 164, ctx.r10.u32);
	// stb r10,152(r11)
	PPC_STORE_U8(r11.u32 + 152, ctx.r10.u8);
	// stw r10,168(r11)
	PPC_STORE_U32(r11.u32 + 168, ctx.r10.u32);
	// stfs f0,172(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 172, temp.u32);
	// stw r10,212(r11)
	PPC_STORE_U32(r11.u32 + 212, ctx.r10.u32);
	// stw r7,216(r11)
	PPC_STORE_U32(r11.u32 + 216, ctx.r7.u32);
	// stw r10,220(r11)
	PPC_STORE_U32(r11.u32 + 220, ctx.r10.u32);
	// stw r10,224(r11)
	PPC_STORE_U32(r11.u32 + 224, ctx.r10.u32);
	// stfs f0,228(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 228, temp.u32);
	// stfs f0,232(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 232, temp.u32);
	// sth r9,236(r11)
	PPC_STORE_U16(r11.u32 + 236, ctx.r9.u16);
	// stb r9,238(r11)
	PPC_STORE_U8(r11.u32 + 238, ctx.r9.u8);
	// stb r10,239(r11)
	PPC_STORE_U8(r11.u32 + 239, ctx.r10.u8);
	// stw r6,208(r11)
	PPC_STORE_U32(r11.u32 + 208, ctx.r6.u32);
	// stw r10,240(r11)
	PPC_STORE_U32(r11.u32 + 240, ctx.r10.u32);
	// sth r10,244(r11)
	PPC_STORE_U16(r11.u32 + 244, ctx.r10.u16);
	// lwz r30,164(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// ori r30,r30,1
	r30.u64 = r30.u64 | 1;
	// stw r5,160(r11)
	PPC_STORE_U32(r11.u32 + 160, ctx.r5.u32);
	// stw r30,164(r11)
	PPC_STORE_U32(r11.u32 + 164, r30.u32);
	// stw r10,256(r11)
	PPC_STORE_U32(r11.u32 + 256, ctx.r10.u32);
	// stw r10,260(r11)
	PPC_STORE_U32(r11.u32 + 260, ctx.r10.u32);
	// stw r10,276(r11)
	PPC_STORE_U32(r11.u32 + 276, ctx.r10.u32);
	// stb r10,264(r11)
	PPC_STORE_U8(r11.u32 + 264, ctx.r10.u8);
	// stw r10,280(r11)
	PPC_STORE_U32(r11.u32 + 280, ctx.r10.u32);
	// stfs f0,284(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 284, temp.u32);
	// stw r10,324(r11)
	PPC_STORE_U32(r11.u32 + 324, ctx.r10.u32);
	// stw r7,328(r11)
	PPC_STORE_U32(r11.u32 + 328, ctx.r7.u32);
	// stw r10,332(r11)
	PPC_STORE_U32(r11.u32 + 332, ctx.r10.u32);
	// stw r10,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r10.u32);
	// stfs f0,340(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 340, temp.u32);
	// stfs f0,344(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 344, temp.u32);
	// sth r9,348(r11)
	PPC_STORE_U16(r11.u32 + 348, ctx.r9.u16);
	// stb r9,350(r11)
	PPC_STORE_U8(r11.u32 + 350, ctx.r9.u8);
	// stb r10,351(r11)
	PPC_STORE_U8(r11.u32 + 351, ctx.r10.u8);
	// stw r6,320(r11)
	PPC_STORE_U32(r11.u32 + 320, ctx.r6.u32);
	// stw r10,352(r11)
	PPC_STORE_U32(r11.u32 + 352, ctx.r10.u32);
	// sth r10,356(r11)
	PPC_STORE_U16(r11.u32 + 356, ctx.r10.u16);
	// lwz r30,276(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// ori r30,r30,1
	r30.u64 = r30.u64 | 1;
	// stw r5,272(r11)
	PPC_STORE_U32(r11.u32 + 272, ctx.r5.u32);
	// stw r30,276(r11)
	PPC_STORE_U32(r11.u32 + 276, r30.u32);
	// stw r10,368(r11)
	PPC_STORE_U32(r11.u32 + 368, ctx.r10.u32);
	// stw r10,372(r11)
	PPC_STORE_U32(r11.u32 + 372, ctx.r10.u32);
	// stb r10,376(r11)
	PPC_STORE_U8(r11.u32 + 376, ctx.r10.u8);
	// addi r11,r11,448
	r11.s64 = r11.s64 + 448;
	// bne 0x8273d128
	if (!cr0.eq) goto loc_8273D128;
loc_8273D298:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8273d318
	if (cr6.lt) goto loc_8273D318;
	// addi r11,r8,64
	r11.s64 = ctx.r8.s64 + 64;
loc_8273D2A4:
	// stw r10,-60(r11)
	PPC_STORE_U32(r11.u32 + -60, ctx.r10.u32);
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r10,-56(r11)
	PPC_STORE_U32(r11.u32 + -56, ctx.r10.u32);
	// stfs f0,-52(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -52, temp.u32);
	// stw r10,-12(r11)
	PPC_STORE_U32(r11.u32 + -12, ctx.r10.u32);
	// stw r7,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r7.u32);
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// sth r10,20(r11)
	PPC_STORE_U16(r11.u32 + 20, ctx.r10.u16);
	// sth r9,12(r11)
	PPC_STORE_U16(r11.u32 + 12, ctx.r9.u16);
	// stb r9,14(r11)
	PPC_STORE_U8(r11.u32 + 14, ctx.r9.u8);
	// stb r10,15(r11)
	PPC_STORE_U8(r11.u32 + 15, ctx.r10.u8);
	// stw r6,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, ctx.r6.u32);
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r8,r8,112
	ctx.r8.s64 = ctx.r8.s64 + 112;
	// lwz r31,-60(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -60);
	// ori r31,r31,1
	r31.u64 = r31.u64 | 1;
	// stw r31,-60(r11)
	PPC_STORE_U32(r11.u32 + -60, r31.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stb r10,40(r11)
	PPC_STORE_U8(r11.u32 + 40, ctx.r10.u8);
	// addi r11,r11,112
	r11.s64 = r11.s64 + 112;
	// bge 0x8273d2a4
	if (!cr0.lt) goto loc_8273D2A4;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9210
	return;
loc_8273D314:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8273D318:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8273D320"))) PPC_WEAK_FUNC(sub_8273D320);
PPC_FUNC_IMPL(__imp__sub_8273D320) {
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
	ctx.lr = 0x8273D328;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r23,0,30,30
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d3f4
	if (cr6.eq) goto loc_8273D3F4;
	// lwz r10,-16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// addi r24,r31,-16
	r24.s64 = r31.s64 + -16;
	// mulli r11,r10,176
	r11.s64 = ctx.r10.s64 * 176;
	// addic. r29,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r29.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// blt 0x8273d3d4
	if (cr0.lt) goto loc_8273D3D4;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,26
	r30.s64 = r31.s64 + 26;
	// addi r26,r10,-19596
	r26.s64 = ctx.r10.s64 + -19596;
	// addi r25,r9,-18912
	r25.s64 = ctx.r9.s64 + -18912;
	// addi r28,r8,-18876
	r28.s64 = ctx.r8.s64 + -18876;
	// addi r27,r11,-18576
	r27.s64 = r11.s64 + -18576;
loc_8273D37C:
	// addi r31,r31,-176
	r31.s64 = r31.s64 + -176;
	// addi r30,r30,-176
	r30.s64 = r30.s64 + -176;
	// addi r3,r30,118
	ctx.r3.s64 = r30.s64 + 118;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x8273D390;
	sub_821D2AA0(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// lhz r11,24(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d3a8
	if (cr6.eq) goto loc_8273D3A8;
	// lwz r3,18(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 18);
	// bl 0x82130588
	ctx.lr = 0x8273D3A8;
	sub_82130588(ctx, base);
loc_8273D3A8:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d3c0
	if (cr6.eq) goto loc_8273D3C0;
	// lwz r3,-6(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -6);
	// bl 0x82130588
	ctx.lr = 0x8273D3C0;
	sub_82130588(ctx, base);
loc_8273D3C0:
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8273D3CC;
	sub_821D2028(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x8273d37c
	if (!cr0.lt) goto loc_8273D37C;
loc_8273D3D4:
	// clrlwi r11,r23,31
	r11.u64 = r23.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d3e8
	if (cr6.eq) goto loc_8273D3E8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82130588
	ctx.lr = 0x8273D3E8;
	sub_82130588(ctx, base);
loc_8273D3E8:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_8273D3F4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// addi r10,r11,-18576
	ctx.r10.s64 = r11.s64 + -18576;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x8273D408;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82246f48
	ctx.lr = 0x8273D410;
	sub_82246F48(ctx, base);
	// clrlwi r9,r23,31
	ctx.r9.u64 = r23.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273d424
	if (cr6.eq) goto loc_8273D424;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8273D424;
	sub_82130588(ctx, base);
loc_8273D424:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8273D430"))) PPC_WEAK_FUNC(sub_8273D430);
PPC_FUNC_IMPL(__imp__sub_8273D430) {
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
	ctx.lr = 0x8273D438;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r24,0,30,30
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d534
	if (cr6.eq) goto loc_8273D534;
	// lwz r11,-16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// addi r25,r31,-16
	r25.s64 = r31.s64 + -16;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r29,r11,-1
	xer.ca = r11.u32 > 0;
	r29.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	// blt 0x8273d514
	if (cr0.lt) goto loc_8273D514;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r31,r30,158
	r31.s64 = r30.s64 + 158;
	// addi r28,r11,-19596
	r28.s64 = r11.s64 + -19596;
	// addi r27,r10,-18912
	r27.s64 = ctx.r10.s64 + -18912;
	// addi r26,r9,-18876
	r26.s64 = ctx.r9.s64 + -18876;
loc_8273D48C:
	// addi r31,r31,-192
	r31.s64 = r31.s64 + -192;
	// addi r30,r30,-192
	r30.s64 = r30.s64 + -192;
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d4a8
	if (cr6.eq) goto loc_8273D4A8;
	// lwz r3,10(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10);
	// bl 0x82130588
	ctx.lr = 0x8273D4A8;
	sub_82130588(ctx, base);
loc_8273D4A8:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d4bc
	if (cr6.eq) goto loc_8273D4BC;
	// lwz r3,-6(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -6);
	// bl 0x82130588
	ctx.lr = 0x8273D4BC;
	sub_82130588(ctx, base);
loc_8273D4BC:
	// lhz r11,-8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + -8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d4d0
	if (cr6.eq) goto loc_8273D4D0;
	// lwz r3,-14(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14);
	// bl 0x82130588
	ctx.lr = 0x8273D4D0;
	sub_82130588(ctx, base);
loc_8273D4D0:
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// lhz r11,-108(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + -108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d4e8
	if (cr6.eq) goto loc_8273D4E8;
	// lwz r3,-114(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -114);
	// bl 0x82130588
	ctx.lr = 0x8273D4E8;
	sub_82130588(ctx, base);
loc_8273D4E8:
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// lhz r11,-132(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + -132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d500
	if (cr6.eq) goto loc_8273D500;
	// lwz r3,-138(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -138);
	// bl 0x82130588
	ctx.lr = 0x8273D500;
	sub_82130588(ctx, base);
loc_8273D500:
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8273D50C;
	sub_821D2028(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x8273d48c
	if (!cr0.lt) goto loc_8273D48C;
loc_8273D514:
	// clrlwi r11,r24,31
	r11.u64 = r24.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d528
	if (cr6.eq) goto loc_8273D528;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x8273D528;
	sub_82130588(ctx, base);
loc_8273D528:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8273D534:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273c6a0
	ctx.lr = 0x8273D53C;
	sub_8273C6A0(ctx, base);
	// clrlwi r11,r24,31
	r11.u64 = r24.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d550
	if (cr6.eq) goto loc_8273D550;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8273D550;
	sub_82130588(ctx, base);
loc_8273D550:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8273D55C"))) PPC_WEAK_FUNC(sub_8273D55C);
PPC_FUNC_IMPL(__imp__sub_8273D55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273D560"))) PPC_WEAK_FUNC(sub_8273D560);
PPC_FUNC_IMPL(__imp__sub_8273D560) {
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
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r10,r11,196
	ctx.r10.s64 = r11.s64 + 196;
	// addi r9,r11,180
	ctx.r9.s64 = r11.s64 + 180;
	// lwz r31,196(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8273d5a4
	if (!cr6.eq) goto loc_8273D5A4;
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
loc_8273D5A4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r31,r8
	cr6.compare<uint32_t>(r31.u32, ctx.r8.u32, xer);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// bne cr6,0x8273d5c0
	if (!cr6.eq) goto loc_8273D5C0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
loc_8273D5C0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d5d4
	if (cr6.eq) goto loc_8273D5D4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8273D5D4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d5e8
	if (cr6.eq) goto loc_8273D5E8;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8273D5E8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d624
	if (cr6.eq) goto loc_8273D624;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273d61c
	if (cr6.eq) goto loc_8273D61C;
	// stw r31,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r31.u32);
loc_8273D61C:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// b 0x8273d628
	goto loc_8273D628;
loc_8273D624:
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r31.u32);
loc_8273D628:
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r31.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273D640;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
}

__attribute__((alias("__imp__sub_8273D658"))) PPC_WEAK_FUNC(sub_8273D658);
PPC_FUNC_IMPL(__imp__sub_8273D658) {
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
	ctx.lr = 0x8273D660;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273d7cc
	if (cr6.eq) goto loc_8273D7CC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r29,r11,-6024
	r29.s64 = r11.s64 + -6024;
	// addi r6,r10,-5996
	ctx.r6.s64 = ctx.r10.s64 + -5996;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r30,-1
	r30.s64 = -1;
	// bl 0x823dedd8
	ctx.lr = 0x8273D69C;
	sub_823DEDD8(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273d6d8
	if (cr6.eq) goto loc_8273D6D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273D6BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// bne cr6,0x8273d6d8
	if (!cr6.eq) goto loc_8273D6D8;
	// mr r30,r27
	r30.u64 = r27.u64;
	// b 0x8273d710
	goto loc_8273D710;
loc_8273D6D8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r6,r11,-5960
	ctx.r6.s64 = r11.s64 + -5960;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x8273D6F4;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273d704
	if (cr6.eq) goto loc_8273D704;
	// li r30,1
	r30.s64 = 1;
	// b 0x8273d710
	goto loc_8273D710;
loc_8273D704:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-10172
	ctx.r3.s64 = r11.s64 + -10172;
	// bl 0x821bd618
	ctx.lr = 0x8273D710;
	sub_821BD618(ctx, base);
loc_8273D710:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r31,r11,180
	r31.s64 = r11.s64 + 180;
	// lwz r9,88(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// addi r30,r11,196
	r30.s64 = r11.s64 + 196;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8273D734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r3,r8
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r8.u32, xer);
	// bne cr6,0x8273d748
	if (!cr6.eq) goto loc_8273D748;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8273D748:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bne cr6,0x8273d75c
	if (!cr6.eq) goto loc_8273D75C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_8273D75C:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d770
	if (cr6.eq) goto loc_8273D770;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8273D770:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d784
	if (cr6.eq) goto loc_8273D784;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8273D784:
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r27.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d7c4
	if (cr6.eq) goto loc_8273D7C4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273d7b4
	if (cr6.eq) goto loc_8273D7B4;
	// stw r3,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r3.u32);
loc_8273D7B4:
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8273D7C4:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
loc_8273D7CC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8273D7D4"))) PPC_WEAK_FUNC(sub_8273D7D4);
PPC_FUNC_IMPL(__imp__sub_8273D7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273D7D8"))) PPC_WEAK_FUNC(sub_8273D7D8);
PPC_FUNC_IMPL(__imp__sub_8273D7D8) {
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
	ctx.lr = 0x8273D7E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x8273D7EC;
	sub_82130000(ctx, base);
	// addi r30,r31,196
	r30.s64 = r31.s64 + 196;
	// li r28,2
	r28.s64 = 2;
	// li r29,0
	r29.s64 = 0;
loc_8273D7F8:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273d8e4
	if (cr6.eq) goto loc_8273D8E4;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// bne cr6,0x8273d818
	if (!cr6.eq) goto loc_8273D818;
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
loc_8273D818:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d82c
	if (cr6.eq) goto loc_8273D82C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8273D82C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d840
	if (cr6.eq) goto loc_8273D840;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8273D840:
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// beq cr6,0x8273d8e4
	if (cr6.eq) goto loc_8273D8E4;
loc_8273D850:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273D864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273d884
	if (cr6.eq) goto loc_8273D884;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273D884;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8273D884:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273d8d8
	if (cr6.eq) goto loc_8273D8D8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bne cr6,0x8273d8a8
	if (!cr6.eq) goto loc_8273D8A8;
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
loc_8273D8A8:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273d8bc
	if (cr6.eq) goto loc_8273D8BC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_8273D8BC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273d8d0
	if (cr6.eq) goto loc_8273D8D0;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_8273D8D0:
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r29.u32);
loc_8273D8D8:
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273d850
	if (!cr6.eq) goto loc_8273D850;
loc_8273D8E4:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x8273d7f8
	if (!cr0.eq) goto loc_8273D7F8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273D8F8"))) PPC_WEAK_FUNC(sub_8273D8F8);
PPC_FUNC_IMPL(__imp__sub_8273D8F8) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bge cr6,0x8273d94c
	if (!cr6.lt) goto loc_8273D94C;
	// subf. r5,r31,r9
	ctx.r5.s64 = ctx.r9.s64 - r31.s64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble 0x8273d944
	if (!cr0.gt) goto loc_8273D944;
	// subf r11,r5,r9
	r11.s64 = ctx.r9.s64 - ctx.r5.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db5b0
	ctx.lr = 0x8273D944;
	sub_823DB5B0(ctx, base);
loc_8273D944:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// b 0x8273d984
	goto loc_8273D984;
loc_8273D94C:
	// addi r11,r9,-4
	r11.s64 = ctx.r9.s64 + -4;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// bge cr6,0x8273d980
	if (!cr6.lt) goto loc_8273D980;
loc_8273D960:
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// blt cr6,0x8273d960
	if (cr6.lt) goto loc_8273D960;
loc_8273D980:
	// stw r30,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r30.u32);
loc_8273D984:
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

__attribute__((alias("__imp__sub_8273D99C"))) PPC_WEAK_FUNC(sub_8273D99C);
PPC_FUNC_IMPL(__imp__sub_8273D99C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273D9A0"))) PPC_WEAK_FUNC(sub_8273D9A0);
PPC_FUNC_IMPL(__imp__sub_8273D9A0) {
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
	// bl 0x82249528
	ctx.lr = 0x8273D9C0;
	sub_82249528(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-10272
	ctx.r10.s64 = r11.s64 + -10272;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,144(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273d9ec
	if (cr6.eq) goto loc_8273D9EC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8273D9E0;
	sub_8217D890(ctx, base);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r10.u32);
loc_8273D9EC:
	// lwz r4,152(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273da0c
	if (cr6.eq) goto loc_8273DA0C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8273DA00;
	sub_8217D890(ctx, base);
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r10.u32);
loc_8273DA0C:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,168
	ctx.r3.s64 = r31.s64 + 168;
	// bl 0x82249380
	ctx.lr = 0x8273DA1C;
	sub_82249380(ctx, base);
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

__attribute__((alias("__imp__sub_8273DA38"))) PPC_WEAK_FUNC(sub_8273DA38);
PPC_FUNC_IMPL(__imp__sub_8273DA38) {
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
	ctx.lr = 0x8273DA40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// blt cr6,0x8273daf8
	if (cr6.lt) goto loc_8273DAF8;
	// beq cr6,0x8273daa0
	if (cr6.eq) goto loc_8273DAA0;
	// cmplwi cr6,r5,3
	cr6.compare<uint32_t>(ctx.r5.u32, 3, xer);
	// blt cr6,0x8273da6c
	if (cr6.lt) goto loc_8273DA6C;
	// bl 0x822496d0
	ctx.lr = 0x8273DA64;
	sub_822496D0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8273DA6C:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8273db3c
	if (!cr6.gt) goto loc_8273DB3C;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
loc_8273DA78:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273da8c
	if (cr6.eq) goto loc_8273DA8C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273d9a0
	ctx.lr = 0x8273DA8C;
	sub_8273D9A0(ctx, base);
loc_8273DA8C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// bne 0x8273da78
	if (!cr0.eq) goto loc_8273DA78;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8273DAA0:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8273db3c
	if (!cr6.gt) goto loc_8273DB3C;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r30,r10,-18576
	r30.s64 = ctx.r10.s64 + -18576;
	// addi r29,r11,-10220
	r29.s64 = r11.s64 + -10220;
loc_8273DABC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273dae4
	if (cr6.eq) goto loc_8273DAE4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82249528
	ctx.lr = 0x8273DAD0;
	sub_82249528(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x821d2aa8
	ctx.lr = 0x8273DAE0;
	sub_821D2AA8(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_8273DAE4:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,176
	r31.s64 = r31.s64 + 176;
	// bne 0x8273dabc
	if (!cr0.eq) goto loc_8273DABC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8273DAF8:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8273db3c
	if (!cr6.gt) goto loc_8273DB3C;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// addi r29,r11,-11948
	r29.s64 = r11.s64 + -11948;
loc_8273DB0C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273db30
	if (cr6.eq) goto loc_8273DB30;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82245c68
	ctx.lr = 0x8273DB20;
	sub_82245C68(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x8273c498
	ctx.lr = 0x8273DB30;
	sub_8273C498(ctx, base);
loc_8273DB30:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,112
	r31.s64 = r31.s64 + 112;
	// bne 0x8273db0c
	if (!cr0.eq) goto loc_8273DB0C;
loc_8273DB3C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8273DB44"))) PPC_WEAK_FUNC(sub_8273DB44);
PPC_FUNC_IMPL(__imp__sub_8273DB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273DB48"))) PPC_WEAK_FUNC(sub_8273DB48);
PPC_FUNC_IMPL(__imp__sub_8273DB48) {
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
	ctx.lr = 0x8273DB50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// subf r11,r30,r4
	r11.s64 = ctx.r4.s64 - r30.s64;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// ble cr6,0x8273dba4
	if (!cr6.gt) goto loc_8273DBA4;
	// addi r29,r30,-4
	r29.s64 = r30.s64 + -4;
loc_8273DB70:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r11,-4
	r31.s64 = r11.s64 + -4;
	// lwzx r6,r29,r11
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// srawi r5,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	ctx.r5.s64 = r31.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, ctx.r10.u32);
	// bl 0x8273c3f0
	ctx.lr = 0x8273DB94;
	sub_8273C3F0(ctx, base);
	// rlwinm r9,r31,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFC;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x8273db70
	if (cr6.gt) goto loc_8273DB70;
loc_8273DBA4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273DBAC"))) PPC_WEAK_FUNC(sub_8273DBAC);
PPC_FUNC_IMPL(__imp__sub_8273DBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273DBB0"))) PPC_WEAK_FUNC(sub_8273DBB0);
PPC_FUNC_IMPL(__imp__sub_8273DBB0) {
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
	// bl 0x8224c100
	ctx.lr = 0x8273DBC8;
	sub_8224C100(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-10120
	ctx.r9.s64 = ctx.r10.s64 + -10120;
	// addi r10,r31,212
	ctx.r10.s64 = r31.s64 + 212;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// stw r11,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r11.u32);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
	// stb r11,176(r31)
	PPC_STORE_U8(r31.u32 + 176, r11.u8);
	// stb r11,177(r31)
	PPC_STORE_U8(r31.u32 + 177, r11.u8);
	// stb r11,178(r31)
	PPC_STORE_U8(r31.u32 + 178, r11.u8);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// stw r11,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8273DC28"))) PPC_WEAK_FUNC(sub_8273DC28);
PPC_FUNC_IMPL(__imp__sub_8273DC28) {
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
	ctx.lr = 0x8273DC30;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// blt cr6,0x8273dd48
	if (cr6.lt) goto loc_8273DD48;
	// rlwinm r6,r30,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r11,r6
	r11.s64 = -ctx.r6.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8273DC58;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x8273dcd8
	if (!cr6.gt) goto loc_8273DCD8;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
loc_8273DC78:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273dcc8
	if (cr6.eq) goto loc_8273DCC8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bne cr6,0x8273dc98
	if (!cr6.eq) goto loc_8273DC98;
	// stw r7,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r7.u32);
loc_8273DC98:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273dcac
	if (cr6.eq) goto loc_8273DCAC;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r5,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
loc_8273DCAC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273dcc0
	if (cr6.eq) goto loc_8273DCC0;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
loc_8273DCC0:
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
loc_8273DCC8:
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8273dc78
	if (!cr0.eq) goto loc_8273DC78;
loc_8273DCD8:
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// add r4,r6,r29
	ctx.r4.u64 = ctx.r6.u64 + r29.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// lbz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// bl 0x8278f5b0
	ctx.lr = 0x8273DCF0;
	sub_8278F5B0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8273dd48
	if (!cr6.gt) goto loc_8273DD48;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
loc_8273DD00:
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273dd34
	if (cr6.eq) goto loc_8273DD34;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273dd2c
	if (cr6.eq) goto loc_8273DD2C;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
loc_8273DD2C:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x8273dd38
	goto loc_8273DD38;
loc_8273DD34:
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8273DD38:
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8273dd00
	if (!cr0.eq) goto loc_8273DD00;
loc_8273DD48:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273DD50"))) PPC_WEAK_FUNC(sub_8273DD50);
PPC_FUNC_IMPL(__imp__sub_8273DD50) {
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
	ctx.lr = 0x8273DD58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x8273DD64;
	sub_82130000(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822460e0
	ctx.lr = 0x8273DD74;
	sub_822460E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8273ddac
	if (!cr6.gt) goto loc_8273DDAC;
loc_8273DD7C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x8273a4a8
	ctx.lr = 0x8273DD94;
	sub_8273A4A8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x822460e0
	ctx.lr = 0x8273DDA4;
	sub_822460E0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8273dd7c
	if (cr6.lt) goto loc_8273DD7C;
loc_8273DDAC:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822460e0
	ctx.lr = 0x8273DDBC;
	sub_822460E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8273ddf4
	if (!cr6.gt) goto loc_8273DDF4;
loc_8273DDC4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,140(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mullw r11,r9,r30
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r30.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8273b730
	ctx.lr = 0x8273DDDC;
	sub_8273B730(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x822460e0
	ctx.lr = 0x8273DDEC;
	sub_822460E0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8273ddc4
	if (cr6.lt) goto loc_8273DDC4;
loc_8273DDF4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x822460e0
	ctx.lr = 0x8273DE04;
	sub_822460E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8273de4c
	if (!cr6.gt) goto loc_8273DE4C;
loc_8273DE0C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,136(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mullw r11,r9,r30
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r30.s32);
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8273DE34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x822460e0
	ctx.lr = 0x8273DE44;
	sub_822460E0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8273de0c
	if (cr6.lt) goto loc_8273DE0C;
loc_8273DE4C:
	// addi r30,r31,180
	r30.s64 = r31.s64 + 180;
	// li r29,2
	r29.s64 = 2;
loc_8273DE54:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273de74
	if (cr6.eq) goto loc_8273DE74;
loc_8273DE64:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273de64
	if (!cr6.eq) goto loc_8273DE64;
loc_8273DE74:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273dc28
	ctx.lr = 0x8273DE80;
	sub_8273DC28(ctx, base);
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// subfic r3,r31,256
	xer.ca = r31.u32 <= 256;
	ctx.r3.s64 = 256 - r31.s64;
	// bl 0x8273dc28
	ctx.lr = 0x8273DE8C;
	sub_8273DC28(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x8273de54
	if (!cr0.eq) goto loc_8273DE54;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8273DEA0"))) PPC_WEAK_FUNC(sub_8273DEA0);
PPC_FUNC_IMPL(__imp__sub_8273DEA0) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8273DEA8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x8273DEB4;
	sub_82130000(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r4,r11,-5840
	ctx.r4.s64 = r11.s64 + -5840;
	// addi r3,r10,-6220
	ctx.r3.s64 = ctx.r10.s64 + -6220;
	// bl 0x821c0750
	ctx.lr = 0x8273DEC8;
	sub_821C0750(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r27,0
	r27.s64 = 0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stw r27,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r27.u32);
	// lis r11,16256
	r11.s64 = 1065353216;
	// stw r27,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r27.u32);
	// addi r31,r28,196
	r31.s64 = r28.s64 + 196;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,256
	r29.s64 = 256;
loc_8273DF1C:
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x8273DF24;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273df38
	if (cr6.eq) goto loc_8273DF38;
	// bl 0x82737e80
	ctx.lr = 0x8273DF30;
	sub_82737E80(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8273df3c
	goto loc_8273DF3C;
loc_8273DF38:
	// mr r30,r27
	r30.u64 = r27.u64;
loc_8273DF3C:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r30,124
	ctx.r3.s64 = r30.s64 + 124;
	// bl 0x825867f8
	ctx.lr = 0x8273DF5C;
	sub_825867F8(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r30,112
	r11.s64 = r30.s64 + 112;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273df90
	if (cr6.eq) goto loc_8273DF90;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273df88
	if (cr6.eq) goto loc_8273DF88;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
loc_8273DF88:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x8273df94
	goto loc_8273DF94;
loc_8273DF90:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8273DF94:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x8273df1c
	if (!cr0.eq) goto loc_8273DF1C;
	// addi r30,r28,204
	r30.s64 = r28.s64 + 204;
	// li r29,256
	r29.s64 = 256;
loc_8273DFA8:
	// li r3,320
	ctx.r3.s64 = 320;
	// bl 0x82130528
	ctx.lr = 0x8273DFB0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273dfc0
	if (cr6.eq) goto loc_8273DFC0;
	// bl 0x82738040
	ctx.lr = 0x8273DFBC;
	sub_82738040(ctx, base);
	// b 0x8273dfc4
	goto loc_8273DFC4;
loc_8273DFC0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8273DFC4:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r11,r3,112
	r11.s64 = ctx.r3.s64 + 112;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273dff8
	if (cr6.eq) goto loc_8273DFF8;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273dff0
	if (cr6.eq) goto loc_8273DFF0;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
loc_8273DFF0:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x8273dffc
	goto loc_8273DFFC;
loc_8273DFF8:
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_8273DFFC:
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x8273dfa8
	if (!cr0.eq) goto loc_8273DFA8;
	// addi r29,r28,212
	r29.s64 = r28.s64 + 212;
	// li r30,2
	r30.s64 = 2;
loc_8273E010:
	// addi r4,r31,-16
	ctx.r4.s64 = r31.s64 + -16;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8273dc28
	ctx.lr = 0x8273E01C;
	sub_8273DC28(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x8273dc28
	ctx.lr = 0x8273E028;
	sub_8273DC28(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x8273e010
	if (!cr0.eq) goto loc_8273E010;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8273E040"))) PPC_WEAK_FUNC(sub_8273E040);
PPC_FUNC_IMPL(__imp__sub_8273E040) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,96(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// beqlr cr6
	if (cr6.eq) return;
loc_8273E05C:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273e0a4
	if (cr6.eq) goto loc_8273E0A4;
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273e08c
	if (cr6.eq) goto loc_8273E08C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// b 0x8273e098
	goto loc_8273E098;
loc_8273E08C:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_8273E098:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_8273E0A4:
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273e05c
	if (!cr6.eq) goto loc_8273E05C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273E0B4"))) PPC_WEAK_FUNC(sub_8273E0B4);
PPC_FUNC_IMPL(__imp__sub_8273E0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273E0B8"))) PPC_WEAK_FUNC(sub_8273E0B8);
PPC_FUNC_IMPL(__imp__sub_8273E0B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,96(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273e0f0
	if (cr6.eq) goto loc_8273E0F0;
loc_8273E0C4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273e0e4
	if (cr6.eq) goto loc_8273E0E4;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8273e0f8
	if (cr6.eq) goto loc_8273E0F8;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
loc_8273E0E4:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273e0c4
	if (!cr6.eq) goto loc_8273E0C4;
loc_8273E0F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8273E0F8:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273E108"))) PPC_WEAK_FUNC(sub_8273E108);
PPC_FUNC_IMPL(__imp__sub_8273E108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,96(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8273E114:
	// lwz r11,256(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8273e150
	if (cr6.eq) goto loc_8273E150;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,256(r4)
	PPC_STORE_U32(ctx.r4.u32 + 256, ctx.r8.u32);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// stwx r5,r9,r4
	PPC_STORE_U32(ctx.r9.u32 + ctx.r4.u32, ctx.r5.u32);
loc_8273E150:
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273e114
	if (!cr6.eq) goto loc_8273E114;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273E160"))) PPC_WEAK_FUNC(sub_8273E160);
PPC_FUNC_IMPL(__imp__sub_8273E160) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r10,r3,96
	ctx.r10.s64 = ctx.r3.s64 + 96;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273e198
	if (cr6.eq) goto loc_8273E198;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273e18c
	if (cr6.eq) goto loc_8273E18C;
	// stw r4,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r4.u32);
loc_8273E18C:
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// blr 
	return;
loc_8273E198:
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273E1A4"))) PPC_WEAK_FUNC(sub_8273E1A4);
PPC_FUNC_IMPL(__imp__sub_8273E1A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273E1A8"))) PPC_WEAK_FUNC(sub_8273E1A8);
PPC_FUNC_IMPL(__imp__sub_8273E1A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,96(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// addi r11,r3,96
	r11.s64 = ctx.r3.s64 + 96;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x8273e1c0
	if (!cr6.eq) goto loc_8273E1C0;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_8273E1C0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bne cr6,0x8273e1d4
	if (!cr6.eq) goto loc_8273E1D4;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8273E1D4:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273e1e8
	if (cr6.eq) goto loc_8273E1E8;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8273E1E8:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273e1fc
	if (cr6.eq) goto loc_8273E1FC;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8273E1FC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273E20C"))) PPC_WEAK_FUNC(sub_8273E20C);
PPC_FUNC_IMPL(__imp__sub_8273E20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273E210"))) PPC_WEAK_FUNC(sub_8273E210);
PPC_FUNC_IMPL(__imp__sub_8273E210) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,-1392
	ctx.r10.s64 = r11.s64 + -1392;
	// li r3,-1
	ctx.r3.s64 = -1;
	// li r11,0
	r11.s64 = 0;
	// lhz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 48);
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// vsubfp128 v59,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// blelr cr6
	if (!cr6.gt) return;
	// vspltisw128 v61,-1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// li r7,80
	ctx.r7.s64 = 80;
	// vor128 v11,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vspltisw128 v60,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v58,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v58 = vTemp;
	// lwz r10,44(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// vrlimi128 v13,v61,4,0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 228), 4));
	// lvx128 v57,r9,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcuxwfp128 v61,v60,1
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v60.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v58,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x0));
	// vsel v10,v11,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vsubfp128 v56,v10,v57
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v57.f32)));
	// vmsum3fp128 v55,v56,v56
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vrsqrtefp128 v0,v55
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v55.f32))));
	// vor128 v9,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v61,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v9,v8,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v6,v7,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v60,v56,v5
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v5.f32)));
loc_8273E298:
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v10,v11,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmsum3fp128 v54,v10,v10
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v10.f32), 0xEF));
	// vrsqrtefp128 v0,v54
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v54.f32))));
	// vor128 v9,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v61,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v9,v8,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v6,v7,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v53,v10,v5
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v5.f32)));
	// vmsum3fp128 v62,v60,v53
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vcmpgtfp128. v52,v62,v59
	simde_mm_store_ps(v52.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v59.f32)));
	cr6.setFromMask(simde_mm_load_ps(v52.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r9,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8273e2e4
	if (cr6.eq) goto loc_8273E2E4;
	// vor128 v59,v62,v62
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_8273E2E4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8273e298
	if (cr6.lt) goto loc_8273E298;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273E2F8"))) PPC_WEAK_FUNC(sub_8273E2F8);
PPC_FUNC_IMPL(__imp__sub_8273E2F8) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f28{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8273E300;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d8
	ctx.lr = 0x8273E308;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,112
	r11.s64 = 112;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r10,8224
	ctx.r10.s64 = 8224;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r8,8240
	ctx.r8.s64 = 8240;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stvx128 v63,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r31,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v127,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r29,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,716(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 716);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dccf0
	ctx.lr = 0x8273E350;
	sub_823DCCF0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,8208(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 8208, temp.u32);
	// lfs f1,712(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 712);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dccf0
	ctx.lr = 0x8273E360;
	sub_823DCCF0(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// stfs f11,8212(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 8212, temp.u32);
	// lfs f13,8264(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8264);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8208(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8208);
	ctx.f12.f64 = double(temp.f32);
	// fadds f30,f13,f12
	f30.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// lfs f10,8268(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8268);
	ctx.f10.f64 = double(temp.f32);
	// fadds f31,f10,f11
	f31.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8273E384;
	sub_823DBBC8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8273E390;
	sub_823DBBC8(ctx, base);
	// frsp f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbae8
	ctx.lr = 0x8273E39C;
	sub_823DBAE8(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x8273E3A8;
	sub_823DBAE8(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f9,8256(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8256);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// fneg f8,f9
	ctx.f8.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lfs f7,8260(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8260);
	ctx.f7.f64 = double(temp.f32);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// fneg f6,f7
	ctx.f6.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// fneg f5,f29
	ctx.f5.u64 = f29.u64 ^ 0x8000000000000000;
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f0,180(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r9,r31,64
	ctx.r9.s64 = r31.s64 + 64;
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
	// stvx128 v127,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r29,r30,r6
	r29.s64 = ctx.r6.s64 - r30.s64;
	// stfs f0,224(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// frsp f4,f1
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r9,48
	ctx.r4.s64 = ctx.r9.s64 + 48;
	// lfs f12,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r9,16
	ctx.r3.s64 = ctx.r9.s64 + 16;
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r9,32
	r31.s64 = ctx.r9.s64 + 32;
	// stfs f0,228(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// subf r30,r30,r5
	r30.s64 = ctx.r5.s64 - r30.s64;
	// stfs f6,232(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fneg f3,f28
	ctx.f3.u64 = f28.u64 ^ 0x8000000000000000;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// stfs f30,104(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f29,112(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r26,32
	r26.s64 = 32;
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r27,48
	r27.s64 = 48;
	// stfs f30,120(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r28,16
	r28.s64 = 16;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r6,r8,2352
	ctx.r6.s64 = ctx.r8.s64 + 2352;
	// stfs f28,148(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r5,r7,2384
	ctx.r5.s64 = ctx.r7.s64 + 2384;
	// stfs f4,152(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f3,164(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f4,168(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
loc_8273E4A0:
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r9,r26
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v49,v60,v60
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvx128 v58,r9,r27
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r9,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v60,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v55,v57,v58
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v54,v60,v59
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v53,v57,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lvx128 v52,r0,r31
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// vand128 v50,v51,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v48,r0,r4
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r3
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v47,v56,v55
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v44,v56,v55
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// vmrghw128 v45,v54,v53
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// addi r25,r1,180
	r25.s64 = ctx.r1.s64 + 180;
	// vor128 v43,v62,v50
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v50.u8)));
	// vmrghw128 v42,v49,v52
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v41,v46,v48
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// addi r24,r1,84
	r24.s64 = ctx.r1.s64 + 84;
	// vmrglw128 v39,v46,v48
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrglw128 v38,v49,v52
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// lvx128 v40,r0,r7
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v37,v43,v47
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v47.f32), 0xFF));
	// vmsum4fp128 v36,v43,v45
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v45.f32), 0xFF));
	// vmrghw128 v35,v42,v41
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmsum4fp128 v34,v43,v44
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmrglw128 v33,v42,v41
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v32,v38,v39
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmsum3fp128 v63,v40,v35
	simde_mm_store_ps(v63.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v35.f32), 0xEF));
	// vmsum3fp128 v62,v40,v33
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vmsum3fp128 v61,v40,v32
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v32.f32), 0xEF));
	// vmrghw128 v60,v37,v43
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v59,v34,v36
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v58,v59,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v57,v63,v61
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v56,v62,v57
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f0,r10,r25
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r25.u32);
	f0.f64 = double(temp.f32);
	// vmrghw128 v55,v57,v56
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lfsx f13,r29,r11
	temp.u32 = PPC_LOAD_U32(r29.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f11,r30,r11
	temp.u32 = PPC_LOAD_U32(r30.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfsx f9,r10,r24
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r24.u32);
	ctx.f9.f64 = double(temp.f32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// fmuls f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f9.f64));
	// stfs f10,-8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// cmpwi cr6,r10,96
	cr6.compare<int32_t>(ctx.r10.s32, 96, xer);
	// fmadds f7,f13,f11,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f6,4(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// blt cr6,0x8273e4a0
	if (cr6.lt) goto loc_8273E4A0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba24
	ctx.lr = 0x8273E5B8;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8273E5BC"))) PPC_WEAK_FUNC(sub_8273E5BC);
PPC_FUNC_IMPL(__imp__sub_8273E5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273E5C0"))) PPC_WEAK_FUNC(sub_8273E5C0);
PPC_FUNC_IMPL(__imp__sub_8273E5C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
	// li r7,-20
	ctx.r7.s64 = -20;
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r11,2256
	r11.s64 = r11.s64 + 2256;
loc_8273E5E0:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r8.u32);
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bge 0x8273e5e0
	if (!cr0.lt) goto loc_8273E5E0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,8212(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8212, temp.u32);
	// li r7,8224
	ctx.r7.s64 = 8224;
	// stfs f0,8208(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8208, temp.u32);
	// li r6,8240
	ctx.r6.s64 = 8240;
	// stfs f0,8264(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8264, temp.u32);
	// stfs f0,8268(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8268, temp.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f0,8256(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8256, temp.u32);
	// stw r8,8192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8192, ctx.r8.u32);
	// stvx128 v63,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r8,8272(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8272, ctx.r8.u8);
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,8384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8384, ctx.r4.u32);
	// lfs f0,31020(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31020);
	f0.f64 = double(temp.f32);
	// addi r10,r5,-31600
	ctx.r10.s64 = ctx.r5.s64 + -31600;
	// stfs f0,8260(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8260, temp.u32);
	// lfs f0,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	f0.f64 = double(temp.f32);
	// stfs f0,8288(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8288, temp.u32);
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,8292(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8292, temp.u32);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8296(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8296, temp.u32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f0,f13,f10
	ctx.f9.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f8,f12,f11,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f8,8300(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8300, temp.u32);
	// lfs f0,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	f0.f64 = double(temp.f32);
	// stfs f0,8304(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8304, temp.u32);
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,8308(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8308, temp.u32);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8312(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8312, temp.u32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f7,f0,f13
	ctx.f7.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f6,f0,f13,f7
	ctx.f6.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmadds f5,f12,f11,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f6.f64));
	// stfs f5,8316(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8316, temp.u32);
	// lfs f0,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	f0.f64 = double(temp.f32);
	// stfs f0,8320(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8320, temp.u32);
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,8324(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8324, temp.u32);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8328(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8328, temp.u32);
	// lfs f11,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f4,f0,f13
	ctx.f4.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmadds f3,f0,f13,f4
	ctx.f3.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f4.f64));
	// fmadds f2,f12,f11,f3
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f2,8332(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8332, temp.u32);
	// lfs f0,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	f0.f64 = double(temp.f32);
	// stfs f0,8336(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8336, temp.u32);
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,8340(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8340, temp.u32);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8344(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8344, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f1
	f0.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f1.f64));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f13,f12,f11,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + f0.f64));
	// stfs f13,8348(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8348, temp.u32);
	// lfs f0,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	f0.f64 = double(temp.f32);
	// stfs f0,8352(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8352, temp.u32);
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,8356(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8356, temp.u32);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8360(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8360, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f12,f11,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f10.f64));
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f0,f13,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f8,8364(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8364, temp.u32);
	// lfs f0,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	f0.f64 = double(temp.f32);
	// stfs f0,8368(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8368, temp.u32);
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,8372(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8372, temp.u32);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8376(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8376, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f7,f0,f13
	ctx.f7.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f6,f0,f13,f7
	ctx.f6.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f7.f64));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-31600(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31600);
	f0.f64 = double(temp.f32);
	// fmadds f5,f12,f0,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f6.f64));
	// stfs f5,8380(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8380, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273E7D4"))) PPC_WEAK_FUNC(sub_8273E7D4);
PPC_FUNC_IMPL(__imp__sub_8273E7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273E7D8"))) PPC_WEAK_FUNC(sub_8273E7D8);
PPC_FUNC_IMPL(__imp__sub_8273E7D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,8192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8192, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273E7E4"))) PPC_WEAK_FUNC(sub_8273E7E4);
PPC_FUNC_IMPL(__imp__sub_8273E7E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273E7E8"))) PPC_WEAK_FUNC(sub_8273E7E8);
PPC_FUNC_IMPL(__imp__sub_8273E7E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8273E7F0;
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -176, f29.u64);
	// stfd f30,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-192
	r12.s64 = -192;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-1760(r1)
	ea = -1760 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r7,r30,8288
	ctx.r7.s64 = r30.s64 + 8288;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// li r11,6
	r11.s64 = 6;
loc_8273E830:
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v61.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// clrlwi r4,r8,24
	ctx.r4.u64 = ctx.r8.u32 & 0xFF;
	// rlwinm r3,r6,25,7,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0x1FFFFFF;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// and r8,r3,r4
	ctx.r8.u64 = ctx.r3.u64 & ctx.r4.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// clrlwi r8,r8,31
	ctx.r8.u64 = ctx.r8.u32 & 0x1;
	// bne 0x8273e830
	if (!cr0.eq) goto loc_8273E830;
	// lwz r11,8384(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8384);
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// subf r9,r20,r11
	ctx.r9.s64 = r11.s64 - r20.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// and r4,r6,r10
	ctx.r4.u64 = ctx.r6.u64 & ctx.r10.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8273ecf8
	if (!cr6.eq) goto loc_8273ECF8;
	// addi r18,r26,16
	r18.s64 = r26.s64 + 16;
	// lvx128 v60,r0,r26
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,8304
	r11.s64 = 8304;
	// addi r17,r26,32
	r17.s64 = r26.s64 + 32;
	// li r10,8320
	ctx.r10.s64 = 8320;
	// addi r16,r26,48
	r16.s64 = r26.s64 + 48;
	// lvx128 v59,r0,r18
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,8336
	ctx.r9.s64 = 8336;
	// stvx128 v59,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r15,r26,64
	r15.s64 = r26.s64 + 64;
	// lvx128 v58,r0,r17
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,8352
	ctx.r8.s64 = 8352;
	// stvx128 v58,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r14,r26,80
	r14.s64 = r26.s64 + 80;
	// lvx128 v57,r0,r16
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,8368
	ctx.r7.s64 = 8368;
	// stvx128 v57,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r19,0
	r19.s64 = 0;
	// lvx128 v56,r0,r15
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// stvx128 v56,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r14
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r30,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r20,8384(r30)
	PPC_STORE_U32(r30.u32 + 8384, r20.u32);
	// stw r19,8192(r30)
	PPC_STORE_U32(r30.u32 + 8192, r19.u32);
	// ble cr6,0x8273ecf8
	if (!cr6.gt) goto loc_8273ECF8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// li r22,16
	r22.s64 = 16;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r23,32
	r23.s64 = 32;
	// lfs f29,-31068(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31068);
	f29.f64 = double(temp.f32);
	// lfs f30,-31400(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31400);
	f30.f64 = double(temp.f32);
loc_8273E910:
	// lwz r25,0(r21)
	r25.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8224d270
	ctx.lr = 0x8273E924;
	sub_8224D270(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// fmr f12,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f30.f64;
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f13,f30
	ctx.f13.f64 = f30.f64;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmr f0,f30
	f0.f64 = f30.f64;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmr f9,f29
	ctx.f9.f64 = f29.f64;
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmr f10,f29
	ctx.f10.f64 = f29.f64;
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmr f11,f29
	ctx.f11.f64 = f29.f64;
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x8273e9c4
	if (!cr6.gt) goto loc_8273E9C4;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8273E974:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8224d6f8
	ctx.lr = 0x8273E980;
	sub_8224D6F8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lvx128 v54,r3,r22
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r3,r23
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpw cr6,r31,r24
	cr6.compare<int32_t>(r31.s32, r24.s32, xer);
	// vminfp128 v127,v127,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_min_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v54.f32)));
	// vmaxfp128 v126,v126,v53
	simde_mm_store_ps(v126.f32, simde_mm_max_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v53.f32)));
	// blt cr6,0x8273e974
	if (cr6.lt) goto loc_8273E974;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
loc_8273E9C4:
	// lvx128 v62,r0,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,63
	ctx.r7.s64 = 63;
	// lfs f8,12(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f10,164(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f10,180(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f11,184(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f9,192(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f9,208(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f11,216(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f9,224(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f10,228(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f0,232(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f9,240(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f10,244(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f11,248(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
loc_8273EA38:
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vmsum3fp128 v52,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// li r10,0
	ctx.r10.s64 = 0;
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f8
	ctx.f13.f64 = double(float(f0.f64 - ctx.f8.f64));
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x8273ea64
	if (cr6.gt) goto loc_8273EA64;
	// li r11,0
	r11.s64 = 0;
loc_8273EA64:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ea74
	if (cr6.eq) goto loc_8273EA74;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8273EA74:
	// lvx128 v51,r0,r18
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vmsum3fp128 v50,v51,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lfs f0,12(r18)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r18.u32 + 12);
	f0.f64 = double(temp.f32);
	// stvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x8273eaa0
	if (cr6.gt) goto loc_8273EAA0;
	// li r11,0
	r11.s64 = 0;
loc_8273EAA0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273eab0
	if (cr6.eq) goto loc_8273EAB0;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
loc_8273EAB0:
	// lvx128 v49,r0,r17
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vmsum3fp128 v48,v49,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lfs f0,12(r17)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 12);
	f0.f64 = double(temp.f32);
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x8273eadc
	if (cr6.gt) goto loc_8273EADC;
	// li r11,0
	r11.s64 = 0;
loc_8273EADC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273eaec
	if (cr6.eq) goto loc_8273EAEC;
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
loc_8273EAEC:
	// lvx128 v47,r0,r16
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vmsum3fp128 v46,v47,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lfs f0,12(r16)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r16.u32 + 12);
	f0.f64 = double(temp.f32);
	// stvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x8273eb18
	if (cr6.gt) goto loc_8273EB18;
	// li r11,0
	r11.s64 = 0;
loc_8273EB18:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273eb28
	if (cr6.eq) goto loc_8273EB28;
	// ori r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 8;
loc_8273EB28:
	// lvx128 v45,r0,r15
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vmsum3fp128 v44,v45,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lfs f0,12(r15)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r15.u32 + 12);
	f0.f64 = double(temp.f32);
	// stvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x8273eb54
	if (cr6.gt) goto loc_8273EB54;
	// li r11,0
	r11.s64 = 0;
loc_8273EB54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273eb64
	if (cr6.eq) goto loc_8273EB64;
	// ori r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 16;
loc_8273EB64:
	// lvx128 v43,r0,r14
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vmsum3fp128 v42,v43,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lfs f0,12(r14)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 12);
	f0.f64 = double(temp.f32);
	// stvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x8273eb90
	if (cr6.gt) goto loc_8273EB90;
	// li r11,0
	r11.s64 = 0;
loc_8273EB90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273eba0
	if (cr6.eq) goto loc_8273EBA0;
	// ori r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 | 32;
loc_8273EBA0:
	// and r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 & ctx.r7.u64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x8273ebc0
	if (cr6.eq) goto loc_8273EBC0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmpwi cr6,r8,8
	cr6.compare<int32_t>(ctx.r8.s32, 8, xer);
	// blt cr6,0x8273ea38
	if (cr6.lt) goto loc_8273EA38;
	// b 0x8273ece8
	goto loc_8273ECE8;
loc_8273EBC0:
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x8273ece8
	if (!cr6.gt) goto loc_8273ECE8;
loc_8273EBCC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8224d6f8
	ctx.lr = 0x8273EBD8;
	sub_8224D6F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r28,r26
	r28.u64 = r26.u64;
loc_8273EBE4:
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// addi r5,r1,528
	ctx.r5.s64 = ctx.r1.s64 + 528;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822450a0
	ctx.lr = 0x8273EBFC;
	sub_822450A0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8273eccc
	if (!cr6.gt) goto loc_8273ECCC;
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// addi r8,r1,528
	ctx.r8.s64 = ctx.r1.s64 + 528;
loc_8273EC10:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
loc_8273EC1C:
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// beq cr6,0x8273ec60
	if (cr6.eq) goto loc_8273EC60;
	// lvx128 v41,r0,r8
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,256
	r11.s64 = ctx.r1.s64 + 256;
	// lvx128 v40,r0,r9
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v39,v40,v41
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v41.f32), 0xEF));
	// lfs f0,12(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	f0.f64 = double(temp.f32);
	// stvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f13,256(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x8273ec54
	if (cr6.gt) goto loc_8273EC54;
	// li r11,0
	r11.s64 = 0;
loc_8273EC54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273ec74
	if (!cr6.eq) goto loc_8273EC74;
loc_8273EC60:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmpwi cr6,r10,6
	cr6.compare<int32_t>(ctx.r10.s32, 6, xer);
	// blt cr6,0x8273ec1c
	if (cr6.lt) goto loc_8273EC1C;
	// b 0x8273ec78
	goto loc_8273EC78;
loc_8273EC74:
	// li r6,1
	ctx.r6.s64 = 1;
loc_8273EC78:
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273ecb8
	if (!cr6.eq) goto loc_8273ECB8;
	// lwz r11,8192(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8192);
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// add r11,r10,r30
	r11.u64 = ctx.r10.u64 + r30.u64;
	// stw r9,8192(r30)
	PPC_STORE_U32(r30.u32 + 8192, ctx.r9.u32);
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
	// lvx128 v38,r0,r8
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// lwz r6,8192(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8192);
	// cmpwi cr6,r6,256
	cr6.compare<int32_t>(ctx.r6.s32, 256, xer);
	// beq cr6,0x8273ecf8
	if (cr6.eq) goto loc_8273ECF8;
loc_8273ECB8:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r5,r3
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r3.s32, xer);
	// blt cr6,0x8273ec10
	if (cr6.lt) goto loc_8273EC10;
loc_8273ECCC:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,16
	r28.s64 = r28.s64 + 16;
	// cmpwi cr6,r29,6
	cr6.compare<int32_t>(r29.s32, 6, xer);
	// blt cr6,0x8273ebe4
	if (cr6.lt) goto loc_8273EBE4;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r27,r24
	cr6.compare<int32_t>(r27.s32, r24.s32, xer);
	// blt cr6,0x8273ebcc
	if (cr6.lt) goto loc_8273EBCC;
loc_8273ECE8:
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// cmpw cr6,r19,r20
	cr6.compare<int32_t>(r19.s32, r20.s32, xer);
	// blt cr6,0x8273e910
	if (cr6.lt) goto loc_8273E910;
loc_8273ECF8:
	// addi r1,r1,1760
	ctx.r1.s64 = ctx.r1.s64 + 1760;
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-192
	r0.s64 = -192;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_8273ED1C"))) PPC_WEAK_FUNC(sub_8273ED1C);
PPC_FUNC_IMPL(__imp__sub_8273ED1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273ED20"))) PPC_WEAK_FUNC(sub_8273ED20);
PPC_FUNC_IMPL(__imp__sub_8273ED20) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8273ed38
	if (!cr6.eq) goto loc_8273ED38;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8273ED38:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// li r3,-1
	ctx.r3.s64 = -1;
	// bltlr cr6
	if (cr6.lt) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273ED4C"))) PPC_WEAK_FUNC(sub_8273ED4C);
PPC_FUNC_IMPL(__imp__sub_8273ED4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273ED50"))) PPC_WEAK_FUNC(sub_8273ED50);
PPC_FUNC_IMPL(__imp__sub_8273ED50) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8273ed68
	if (!cr6.eq) goto loc_8273ED68;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8273ED68:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// li r3,1
	ctx.r3.s64 = 1;
	// bgtlr cr6
	if (cr6.gt) return;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273ED7C"))) PPC_WEAK_FUNC(sub_8273ED7C);
PPC_FUNC_IMPL(__imp__sub_8273ED7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273ED80"))) PPC_WEAK_FUNC(sub_8273ED80);
PPC_FUNC_IMPL(__imp__sub_8273ED80) {
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
	// rlwinm r3,r31,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x8273ED9C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8273edcc
	if (!cr6.gt) goto loc_8273EDCC;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
loc_8273EDB0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273edc0
	if (cr6.eq) goto loc_8273EDC0;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8273EDC0:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8273edb0
	if (!cr0.eq) goto loc_8273EDB0;
loc_8273EDCC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8273EDE0"))) PPC_WEAK_FUNC(sub_8273EDE0);
PPC_FUNC_IMPL(__imp__sub_8273EDE0) {
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
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8273EE04;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8273ee3c
	if (!cr6.gt) goto loc_8273EE3C;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8273EE1C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ee30
	if (cr6.eq) goto loc_8273EE30;
	// stfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
loc_8273EE30:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x8273ee1c
	if (!cr0.eq) goto loc_8273EE1C;
loc_8273EE3C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8273EE50"))) PPC_WEAK_FUNC(sub_8273EE50);
PPC_FUNC_IMPL(__imp__sub_8273EE50) {
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
	// rlwinm r3,r31,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x8273EE6C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8273ee9c
	if (!cr6.gt) goto loc_8273EE9C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r10,-2
	ctx.r10.s64 = -2;
loc_8273EE80:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ee90
	if (cr6.eq) goto loc_8273EE90;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8273EE90:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8273ee80
	if (!cr0.eq) goto loc_8273EE80;
loc_8273EE9C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8273EEB0"))) PPC_WEAK_FUNC(sub_8273EEB0);
PPC_FUNC_IMPL(__imp__sub_8273EEB0) {
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
	ctx.lr = 0x8273EEB8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,-1
	r27.s64 = -1;
	// li r28,-1
	r28.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ef30
	if (cr6.eq) goto loc_8273EF30;
	// li r29,0
	r29.s64 = 0;
	// lis r26,-32121
	r26.s64 = -2105081856;
loc_8273EEE0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,-10020(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10020);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x826bd9b8
	ctx.lr = 0x8273EEF4;
	sub_826BD9B8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8273ef2c
	if (cr6.eq) goto loc_8273EF2C;
	// cmpw cr6,r28,r3
	cr6.compare<int32_t>(r28.s32, ctx.r3.s32, xer);
	// bgt cr6,0x8273ef0c
	if (cr6.gt) goto loc_8273EF0C;
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// bne cr6,0x8273ef14
	if (!cr6.eq) goto loc_8273EF14;
loc_8273EF0C:
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r30
	r27.u64 = r30.u64;
loc_8273EF14:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8273eee0
	if (cr6.lt) goto loc_8273EEE0;
	// b 0x8273ef30
	goto loc_8273EF30;
loc_8273EF2C:
	// mr r27,r30
	r27.u64 = r30.u64;
loc_8273EF30:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r27,3,0,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8273EF48"))) PPC_WEAK_FUNC(sub_8273EF48);
PPC_FUNC_IMPL(__imp__sub_8273EF48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273EF5C"))) PPC_WEAK_FUNC(sub_8273EF5C);
PPC_FUNC_IMPL(__imp__sub_8273EF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273EF60"))) PPC_WEAK_FUNC(sub_8273EF60);
PPC_FUNC_IMPL(__imp__sub_8273EF60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lbzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273EF70"))) PPC_WEAK_FUNC(sub_8273EF70);
PPC_FUNC_IMPL(__imp__sub_8273EF70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// stbx r5,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273EF80"))) PPC_WEAK_FUNC(sub_8273EF80);
PPC_FUNC_IMPL(__imp__sub_8273EF80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lhz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// twllei r8,0
	// ori r6,r7,64167
	ctx.r6.u64 = ctx.r7.u64 | 64167;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// addis r5,r11,1
	ctx.r5.s64 = r11.s64 + 65536;
	// addi r5,r5,27768
	ctx.r5.s64 = ctx.r5.s64 + 27768;
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mulld r10,r4,r6
	ctx.r10.s64 = ctx.r4.s64 * ctx.r6.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r9,r11,1
	ctx.r9.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// rldicl r4,r11,32,32
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// divw r6,r9,r8
	ctx.r6.s32 = ctx.r9.s32 / ctx.r8.s32;
	// stw r4,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r4.u32);
	// mullw r11,r6,r8
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// rlwinm r9,r7,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// andc r4,r8,r6
	ctx.r4.u64 = ctx.r8.u64 & ~ctx.r6.u64;
	// lwz r3,4(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// twlgei r4,-1
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273EFF0"))) PPC_WEAK_FUNC(sub_8273EFF0);
PPC_FUNC_IMPL(__imp__sub_8273EFF0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8273eeb0
	sub_8273EEB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8273EFF4"))) PPC_WEAK_FUNC(sub_8273EFF4);
PPC_FUNC_IMPL(__imp__sub_8273EFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273EFF8"))) PPC_WEAK_FUNC(sub_8273EFF8);
PPC_FUNC_IMPL(__imp__sub_8273EFF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8273F010:
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stbx r9,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lhz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8273f010
	if (cr6.lt) goto loc_8273F010;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273F030"))) PPC_WEAK_FUNC(sub_8273F030);
PPC_FUNC_IMPL(__imp__sub_8273F030) {
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
	// bne cr6,0x8273f0bc
	if (!cr6.eq) goto loc_8273F0BC;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x8273ed80
	ctx.lr = 0x8273F068;
	sub_8273ED80(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273f0b0
	if (cr6.eq) goto loc_8273F0B0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8273F07C:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
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
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// blt cr6,0x8273f07c
	if (cr6.lt) goto loc_8273F07C;
loc_8273F0B0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8273F0B8;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_8273F0BC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,3
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 3);
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

__attribute__((alias("__imp__sub_8273F0EC"))) PPC_WEAK_FUNC(sub_8273F0EC);
PPC_FUNC_IMPL(__imp__sub_8273F0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273F0F0"))) PPC_WEAK_FUNC(sub_8273F0F0);
PPC_FUNC_IMPL(__imp__sub_8273F0F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rotlwi r9,r9,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplw cr6,r5,r9
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r9.u32, xer);
	// beq cr6,0x8273f134
	if (cr6.eq) goto loc_8273F134;
	// subf r8,r5,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r5.s64;
loc_8273F114:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r6,r8,r11
	ctx.r6.u64 = ctx.r8.u64 + r11.u64;
	// stwx r7,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r7.u32);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stw r3,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r3.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x8273f114
	if (!cr6.eq) goto loc_8273F114;
loc_8273F134:
	// subf r11,r4,r5
	r11.s64 = ctx.r5.s64 - ctx.r4.s64;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// srawi r8,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	ctx.r8.s64 = r11.s32 >> 3;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// sth r7,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r7.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273F150"))) PPC_WEAK_FUNC(sub_8273F150);
PPC_FUNC_IMPL(__imp__sub_8273F150) {
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
	ctx.lr = 0x8273F158;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8273F174;
	sub_8238EC00(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x8273F190;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82389668
	ctx.lr = 0x8273F1A0;
	sub_82389668(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273f1f8
	if (cr6.eq) goto loc_8273F1F8;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8273f1e4
	if (!cr6.gt) goto loc_8273F1E4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_8273F1C8:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// beq cr6,0x8273f200
	if (cr6.eq) goto loc_8273F200;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8273f1c8
	if (cr6.lt) goto loc_8273F1C8;
loc_8273F1E4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273f030
	ctx.lr = 0x8273F1F0;
	sub_8273F030(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_8273F1F8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8273F200:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-9184
	ctx.r3.s64 = r11.s64 + -9184;
	// bl 0x82130000
	ctx.lr = 0x8273F210;
	sub_82130000(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8273F218"))) PPC_WEAK_FUNC(sub_8273F218);
PPC_FUNC_IMPL(__imp__sub_8273F218) {
	PPC_FUNC_PROLOGUE();
	// b 0x8273f150
	sub_8273F150(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8273F21C"))) PPC_WEAK_FUNC(sub_8273F21C);
PPC_FUNC_IMPL(__imp__sub_8273F21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273F220"))) PPC_WEAK_FUNC(sub_8273F220);
PPC_FUNC_IMPL(__imp__sub_8273F220) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8273F228;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// add r5,r11,r4
	ctx.r5.u64 = r11.u64 + ctx.r4.u64;
	// bl 0x8273f0f0
	ctx.lr = 0x8273F250;
	sub_8273F0F0(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8273F25C;
	sub_8238EC00(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8273f334
	if (!cr6.gt) goto loc_8273F334;
	// li r26,0
	r26.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// li r23,1
	r23.s64 = 1;
loc_8273F280:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r31,r27,r11
	r31.u64 = r27.u64 + r11.u64;
	// lbz r11,96(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273f2a4
	if (cr6.eq) goto loc_8273F2A4;
	// bl 0x82387e18
	ctx.lr = 0x8273F298;
	sub_82387E18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273f31c
	if (cr6.eq) goto loc_8273F31C;
loc_8273F2A4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpw cr6,r11,r24
	cr6.compare<int32_t>(r11.s32, r24.s32, xer);
	// beq cr6,0x8273f2b8
	if (cr6.eq) goto loc_8273F2B8;
	// cmpwi cr6,r24,6
	cr6.compare<int32_t>(r24.s32, 6, xer);
	// bne cr6,0x8273f31c
	if (!cr6.eq) goto loc_8273F31C;
loc_8273F2B8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// slw r10,r23,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (r23.u32 << (r11.u8 & 0x3F));
	// and r9,r10,r22
	ctx.r9.u64 = ctx.r10.u64 & r22.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8273f2d4
	if (!cr6.eq) goto loc_8273F2D4;
	// cmpwi cr6,r22,-1
	cr6.compare<int32_t>(r22.s32, -1, xer);
	// bne cr6,0x8273f31c
	if (!cr6.eq) goto loc_8273F31C;
loc_8273F2D4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// slw r10,r23,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (r23.u32 << (r11.u8 & 0x3F));
	// and r9,r10,r21
	ctx.r9.u64 = ctx.r10.u64 & r21.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8273f2f0
	if (!cr6.eq) goto loc_8273F2F0;
	// cmpwi cr6,r21,-1
	cr6.compare<int32_t>(r21.s32, -1, xer);
	// bne cr6,0x8273f31c
	if (!cr6.eq) goto loc_8273F31C;
loc_8273F2F0:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r3,-10020(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10020);
	// lwzx r4,r11,r26
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// bl 0x826bf4b0
	ctx.lr = 0x8273F300;
	sub_826BF4B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273f31c
	if (cr6.eq) goto loc_8273F31C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8273f030
	ctx.lr = 0x8273F318;
	sub_8273F030(ctx, base);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
loc_8273F31C:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,160
	r27.s64 = r27.s64 + 160;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8273f280
	if (cr6.lt) goto loc_8273F280;
loc_8273F334:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273f3d4
	if (!cr6.eq) goto loc_8273F3D4;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-28196
	ctx.r9.s64 = r11.s64 + -28196;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r3,r8,-9072
	ctx.r3.s64 = ctx.r8.s64 + -9072;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x8273F35C;
	sub_82130000(ctx, base);
	// lwz r11,-10020(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10020);
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addis r5,r11,1
	ctx.r5.s64 = r11.s64 + 65536;
	// ori r10,r7,64167
	ctx.r10.u64 = ctx.r7.u64 | 64167;
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// addi r5,r5,27768
	ctx.r5.s64 = ctx.r5.s64 + 27768;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// twllei r8,0
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mulld r10,r9,r10
	ctx.r10.s64 = ctx.r9.s64 * ctx.r10.s64;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r6,r11,32,32
	ctx.r6.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// clrlwi r10,r11,1
	ctx.r10.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r6,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r6.u32);
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r9,r10,r8
	ctx.r9.s32 = ctx.r10.s32 / ctx.r8.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r9,r8
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// andc r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// subf r11,r6,r10
	r11.s64 = ctx.r10.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x8273f030
	ctx.lr = 0x8273F3CC;
	sub_8273F030(ctx, base);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r10.u64);
loc_8273F3D4:
	// lhz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8273F3E0"))) PPC_WEAK_FUNC(sub_8273F3E0);
PPC_FUNC_IMPL(__imp__sub_8273F3E0) {
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
	ctx.lr = 0x8273F3E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// sth r29,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r29.u16);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273f420
	if (cr6.eq) goto loc_8273F420;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273ede0
	ctx.lr = 0x8273F418;
	sub_8273EDE0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x8273f424
	goto loc_8273F424;
loc_8273F420:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_8273F424:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x8273F42C;
	sub_822A8108(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r30,r3,48
	r30.s64 = ctx.r3.s64 + 48;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8273F43C;
	sub_8238EC00(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273f4c8
	if (cr6.eq) goto loc_8273F4C8;
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_8273F454:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r6,44(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r9,r7,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// addi r7,r9,48
	ctx.r7.s64 = ctx.r9.s64 + 48;
	// lfs f12,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f10,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// stfs f6,4(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// blt cr6,0x8273f454
	if (cr6.lt) goto loc_8273F454;
loc_8273F4C8:
	// clrlwi r30,r27,16
	r30.u64 = r27.u32 & 0xFFFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x8273f4d8
	if (!cr6.lt) goto loc_8273F4D8;
loc_8273F4D8:
	// lis r11,-32140
	r11.s64 = -2106327040;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r6,r11,-4832
	ctx.r6.s64 = r11.s64 + -4832;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823dcf08
	ctx.lr = 0x8273F4EC;
	sub_823DCF08(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8273f520
	if (!cr6.gt) goto loc_8273F520;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8273F500:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// stw r7,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r7.u32);
	// bne 0x8273f500
	if (!cr0.eq) goto loc_8273F500;
loc_8273F520:
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273f534
	if (cr6.eq) goto loc_8273F534;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x8273F534;
	sub_82130588(ctx, base);
loc_8273F534:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8273F53C"))) PPC_WEAK_FUNC(sub_8273F53C);
PPC_FUNC_IMPL(__imp__sub_8273F53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273F540"))) PPC_WEAK_FUNC(sub_8273F540);
PPC_FUNC_IMPL(__imp__sub_8273F540) {
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
	PPCRegister f0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8273F548;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r22,0
	r22.s64 = 0;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
	// mr r29,r22
	r29.u64 = r22.u64;
	// sth r22,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r22.u16);
	// lhz r31,4(r25)
	r31.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273f590
	if (cr6.eq) goto loc_8273F590;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273ede0
	ctx.lr = 0x8273F588;
	sub_8273EDE0(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// b 0x8273f594
	goto loc_8273F594;
loc_8273F590:
	// mr r21,r22
	r21.u64 = r22.u64;
loc_8273F594:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r20,r31,16
	r20.u64 = r31.u32 & 0xFFFF;
	// bl 0x822a8108
	ctx.lr = 0x8273F5A0;
	sub_822A8108(ctx, base);
	// addi r31,r3,48
	r31.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x8273F5AC;
	sub_822A8108(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r28,r10,2528
	r28.s64 = ctx.r10.s64 + 2528;
	// addi r30,r11,2240
	r30.s64 = r11.s64 + 2240;
	// lvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vmsum3fp128 v60,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r27,r11,-31648
	r27.s64 = r11.s64 + -31648;
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r10,-31664
	r26.s64 = ctx.r10.s64 + -31664;
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r23,-1
	r23.s64 = -1;
	// lvx128 v13,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-27856(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27856);
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v59,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v62,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v63,v6
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8238ec00
	ctx.lr = 0x8273F630;
	sub_8238EC00(ctx, base);
	// lhz r5,4(r25)
	ctx.r5.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8273f758
	if (cr6.eq) goto loc_8273F758;
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
loc_8273F650:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r9,44(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpw cr6,r9,r24
	cr6.compare<int32_t>(ctx.r9.s32, r24.s32, xer);
	// beq cr6,0x8273f688
	if (cr6.eq) goto loc_8273F688;
	// cmpwi cr6,r24,6
	cr6.compare<int32_t>(r24.s32, 6, xer);
	// bne cr6,0x8273f744
	if (!cr6.eq) goto loc_8273F744;
loc_8273F688:
	// lvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r9,r29,16
	ctx.r9.u64 = r29.u32 & 0xFFFF;
	// lvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r29,1,15,30
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0x1FFFE;
	// vsubfp128 v63,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r21
	r11.u64 = r11.u64 + r21.u64;
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// clrlwi r29,r4,16
	r29.u64 = ctx.r4.u32 & 0xFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lfs f11,8(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// vmsum3fp128 v55,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,0(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// vrsqrtefp128 v54,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v55.f32))));
	// vor128 v12,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// fsubs f6,f11,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmuls f5,f7,f7
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// vcmpeqfp128 v11,v54,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// fmadds f4,f6,f6,f5
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// fsqrts f3,f4
	ctx.f3.f64 = double(float(sqrt(ctx.f4.f64)));
	// stfs f3,4(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v62,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v53,v63,v6
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v53,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f2
	ctx.f10.f64 = double(float(f0.f64 * ctx.f2.f64));
	// fmadds f9,f13,f1,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f10.f64));
	// fmadds f8,f12,f11,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f8,8(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
loc_8273F744:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// blt cr6,0x8273f650
	if (cr6.lt) goto loc_8273F650;
loc_8273F758:
	// clrlwi r30,r29,16
	r30.u64 = r29.u32 & 0xFFFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x8273f768
	if (!cr6.lt) goto loc_8273F768;
loc_8273F768:
	// lis r11,-32140
	r11.s64 = -2106327040;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r6,r11,-4784
	ctx.r6.s64 = r11.s64 + -4784;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823dcf08
	ctx.lr = 0x8273F77C;
	sub_823DCF08(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r28,r22
	r28.u64 = r22.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8273f804
	if (!cr6.gt) goto loc_8273F804;
	// mr r31,r21
	r31.u64 = r21.u64;
loc_8273F790:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8273f7d8
	if (!cr6.gt) goto loc_8273F7D8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,-10020(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10020);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x826bd9b8
	ctx.lr = 0x8273F7B8;
	sub_826BD9B8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8273f7ec
	if (cr6.eq) goto loc_8273F7EC;
	// cmpw cr6,r3,r22
	cr6.compare<int32_t>(ctx.r3.s32, r22.s32, xer);
	// blt cr6,0x8273f7d0
	if (cr6.lt) goto loc_8273F7D0;
	// cmpwi cr6,r23,-1
	cr6.compare<int32_t>(r23.s32, -1, xer);
	// bne cr6,0x8273f7d8
	if (!cr6.eq) goto loc_8273F7D8;
loc_8273F7D0:
	// lwz r23,0(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
loc_8273F7D8:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// cmpw cr6,r28,r30
	cr6.compare<int32_t>(r28.s32, r30.s32, xer);
	// blt cr6,0x8273f790
	if (cr6.lt) goto loc_8273F790;
	// b 0x8273f7fc
	goto loc_8273F7FC;
loc_8273F7EC:
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r23,r10,r21
	r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + r21.u32);
loc_8273F7FC:
	// cmpwi cr6,r23,-1
	cr6.compare<int32_t>(r23.s32, -1, xer);
	// bne cr6,0x8273f8e0
	if (!cr6.eq) goto loc_8273F8E0;
loc_8273F804:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8273f87c
	if (cr6.eq) goto loc_8273F87C;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-8904
	ctx.r3.s64 = r11.s64 + -8904;
	// bl 0x82130000
	ctx.lr = 0x8273F824;
	sub_82130000(ctx, base);
	// lwz r11,-10020(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10020);
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// addis r9,r11,1
	ctx.r9.s64 = r11.s64 + 65536;
	// addi r9,r9,27768
	ctx.r9.s64 = ctx.r9.s64 + 27768;
	// ori r8,r10,64167
	ctx.r8.u64 = ctx.r10.u64 | 64167;
	// twllei r30,0
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mulld r10,r7,r8
	ctx.r10.s64 = ctx.r7.s64 * ctx.r8.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// divw r4,r6,r30
	ctx.r4.s32 = ctx.r6.s32 / r30.s32;
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// mullw r8,r4,r30
	ctx.r8.s64 = int64_t(ctx.r4.s32) * int64_t(r30.s32);
	// andc r10,r30,r3
	ctx.r10.u64 = r30.u64 & ~ctx.r3.u64;
	// subf r23,r8,r6
	r23.s64 = ctx.r6.s64 - ctx.r8.s64;
	// twlgei r10,-1
	// b 0x8273f8e0
	goto loc_8273F8E0;
loc_8273F87C:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-8992
	ctx.r3.s64 = r11.s64 + -8992;
	// bl 0x82130000
	ctx.lr = 0x8273F888;
	sub_82130000(ctx, base);
	// lwz r11,-10020(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10020);
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lhz r9,4(r25)
	ctx.r9.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// addis r8,r11,1
	ctx.r8.s64 = r11.s64 + 65536;
	// ori r7,r10,64167
	ctx.r7.u64 = ctx.r10.u64 | 64167;
	// addi r8,r8,27768
	ctx.r8.s64 = ctx.r8.s64 + 27768;
	// twllei r9,0
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mulld r11,r6,r7
	r11.s64 = ctx.r6.s64 * ctx.r7.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r5,r11,1
	ctx.r5.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// rldicl r7,r11,32,32
	ctx.r7.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r3,r5,r9
	ctx.r3.s32 = ctx.r5.s32 / ctx.r9.s32;
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mullw r4,r3,r9
	ctx.r4.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// andc r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// subf r23,r4,r5
	r23.s64 = ctx.r5.s64 - ctx.r4.s64;
	// twlgei r6,-1
loc_8273F8E0:
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// rlwinm r11,r23,3,0,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r9,r20,16
	ctx.r9.u64 = r20.u32 & 0xFFFF;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r31,4(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// beq cr6,0x8273f904
	if (cr6.eq) goto loc_8273F904;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82130588
	ctx.lr = 0x8273F904;
	sub_82130588(ctx, base);
loc_8273F904:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8273F914"))) PPC_WEAK_FUNC(sub_8273F914);
PPC_FUNC_IMPL(__imp__sub_8273F914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273F918"))) PPC_WEAK_FUNC(sub_8273F918);
PPC_FUNC_IMPL(__imp__sub_8273F918) {
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
	ctx.lr = 0x8273F920;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r21,0
	r21.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r21.u32);
	// clrlwi r20,r28,16
	r20.u64 = r28.u32 & 0xFFFF;
	// sth r21,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r21.u16);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8273f95c
	if (cr6.eq) goto loc_8273F95C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273ee50
	ctx.lr = 0x8273F954;
	sub_8273EE50(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8273f960
	goto loc_8273F960;
loc_8273F95C:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_8273F960:
	// li r26,-1
	r26.s64 = -1;
	// stw r23,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r23.u32);
	// li r27,1
	r27.s64 = 1;
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
	// mr r24,r21
	r24.u64 = r21.u64;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273fb18
	if (cr6.eq) goto loc_8273FB18;
	// mr r31,r21
	r31.u64 = r21.u64;
	// addi r25,r30,12
	r25.s64 = r30.s64 + 12;
	// lis r22,-32121
	r22.s64 = -2105081856;
loc_8273F98C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r4,r23
	cr6.compare<int32_t>(ctx.r4.s32, r23.s32, xer);
	// beq cr6,0x8273fb04
	if (cr6.eq) goto loc_8273FB04;
	// lwz r3,-10020(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10020);
	// bl 0x826bd9b8
	ctx.lr = 0x8273F9A8;
	sub_826BD9B8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x8273fa50
	if (!cr6.eq) goto loc_8273FA50;
	// mr r11,r27
	r11.u64 = r27.u64;
	// cmpw cr6,r27,r28
	cr6.compare<int32_t>(r27.s32, r28.s32, xer);
	// bge cr6,0x8273fa44
	if (!cr6.lt) goto loc_8273FA44;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_8273F9C0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,-2
	cr6.compare<int32_t>(ctx.r9.s32, -2, xer);
	// beq cr6,0x8273fa28
	if (cr6.eq) goto loc_8273FA28;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bgt cr6,0x8273f9f0
	if (cr6.gt) goto loc_8273F9F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// blt cr6,0x8273f9c0
	if (cr6.lt) goto loc_8273F9C0;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// b 0x8273fafc
	goto loc_8273FAFC;
loc_8273F9F0:
	// addi r10,r28,-1
	ctx.r10.s64 = r28.s64 + -1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8273fa28
	if (!cr6.gt) goto loc_8273FA28;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// add r10,r8,r30
	ctx.r10.u64 = ctx.r8.u64 + r30.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_8273FA0C:
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// bne 0x8273fa0c
	if (!cr0.eq) goto loc_8273FA0C;
loc_8273FA28:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r31,r10
	ctx.r10.u64 = r31.u64 + ctx.r10.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_8273FA44:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// b 0x8273fafc
	goto loc_8273FAFC;
loc_8273FA50:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// cmpw cr6,r27,r28
	cr6.compare<int32_t>(r27.s32, r28.s32, xer);
	// bge cr6,0x8273fb00
	if (!cr6.lt) goto loc_8273FB00;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
loc_8273FA60:
	// lwz r11,-4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8273fae0
	if (cr6.eq) goto loc_8273FAE0;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x8273facc
	if (!cr6.gt) goto loc_8273FACC;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// ble cr6,0x8273facc
	if (!cr6.gt) goto loc_8273FACC;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// ble cr6,0x8273fab8
	if (!cr6.gt) goto loc_8273FAB8;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r10,r8,r11
	ctx.r10.s64 = r11.s64 - ctx.r8.s64;
	// add r11,r9,r30
	r11.u64 = ctx.r9.u64 + r30.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
loc_8273FA9C:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// bne 0x8273fa9c
	if (!cr0.eq) goto loc_8273FA9C;
loc_8273FAB8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// stw r10,-4(r7)
	PPC_STORE_U32(ctx.r7.u32 + -4, ctx.r10.u32);
loc_8273FACC:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// cmpw cr6,r8,r28
	cr6.compare<int32_t>(ctx.r8.s32, r28.s32, xer);
	// blt cr6,0x8273fa60
	if (cr6.lt) goto loc_8273FA60;
	// b 0x8273fafc
	goto loc_8273FAFC;
loc_8273FAE0:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r31,r10
	ctx.r10.u64 = r31.u64 + ctx.r10.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_8273FAFC:
	// cmpw cr6,r27,r28
	cr6.compare<int32_t>(r27.s32, r28.s32, xer);
loc_8273FB00:
	// beq cr6,0x8273fb18
	if (cr6.eq) goto loc_8273FB18;
loc_8273FB04:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x8273f98c
	if (cr6.lt) goto loc_8273F98C;
loc_8273FB18:
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273fb74
	if (!cr6.eq) goto loc_8273FB74;
	// sth r20,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r20.u16);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8273fb6c
	if (cr6.eq) goto loc_8273FB6C;
	// rlwinm r3,r28,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x8273FB38;
	sub_82130528(ctx, base);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x8273fb64
	if (!cr6.gt) goto loc_8273FB64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_8273FB48:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273fb58
	if (cr6.eq) goto loc_8273FB58;
	// stb r21,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r21.u8);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_8273FB58:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8273fb48
	if (!cr0.eq) goto loc_8273FB48;
loc_8273FB64:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fb70
	goto loc_8273FB70;
loc_8273FB6C:
	// mr r11,r21
	r11.u64 = r21.u64;
loc_8273FB70:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8273FB74:
	// clrlwi r11,r20,16
	r11.u64 = r20.u32 & 0xFFFF;
	// sth r20,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r20.u16);
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273fbb8
	if (cr6.eq) goto loc_8273FBB8;
	// mr r11,r21
	r11.u64 = r21.u64;
loc_8273FB8C:
	// stb r21,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r21.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stdx r7,r8,r11
	PPC_STORE_U64(ctx.r8.u32 + r11.u32, ctx.r7.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// lhz r6,4(r29)
	ctx.r6.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x8273fb8c
	if (cr6.lt) goto loc_8273FB8C;
loc_8273FBB8:
	// clrlwi r11,r20,16
	r11.u64 = r20.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273fbcc
	if (cr6.eq) goto loc_8273FBCC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8273FBCC;
	sub_82130588(ctx, base);
loc_8273FBCC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8273FBD4"))) PPC_WEAK_FUNC(sub_8273FBD4);
PPC_FUNC_IMPL(__imp__sub_8273FBD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273FBD8"))) PPC_WEAK_FUNC(sub_8273FBD8);
PPC_FUNC_IMPL(__imp__sub_8273FBD8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8273f220
	sub_8273F220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8273FBDC"))) PPC_WEAK_FUNC(sub_8273FBDC);
PPC_FUNC_IMPL(__imp__sub_8273FBDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273FBE0"))) PPC_WEAK_FUNC(sub_8273FBE0);
PPC_FUNC_IMPL(__imp__sub_8273FBE0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8273f3e0
	sub_8273F3E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8273FBE4"))) PPC_WEAK_FUNC(sub_8273FBE4);
PPC_FUNC_IMPL(__imp__sub_8273FBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273FBE8"))) PPC_WEAK_FUNC(sub_8273FBE8);
PPC_FUNC_IMPL(__imp__sub_8273FBE8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8273f540
	sub_8273F540(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8273FBEC"))) PPC_WEAK_FUNC(sub_8273FBEC);
PPC_FUNC_IMPL(__imp__sub_8273FBEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273FBF0"))) PPC_WEAK_FUNC(sub_8273FBF0);
PPC_FUNC_IMPL(__imp__sub_8273FBF0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8273f918
	sub_8273F918(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8273FBF4"))) PPC_WEAK_FUNC(sub_8273FBF4);
PPC_FUNC_IMPL(__imp__sub_8273FBF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273FBF8"))) PPC_WEAK_FUNC(sub_8273FBF8);
PPC_FUNC_IMPL(__imp__sub_8273FBF8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273fc44
	if (cr6.eq) goto loc_8273FC44;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// add r5,r11,r4
	ctx.r5.u64 = r11.u64 + ctx.r4.u64;
	// bl 0x8273f0f0
	ctx.lr = 0x8273FC28;
	sub_8273F0F0(ctx, base);
	// lhz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273fc3c
	if (cr6.eq) goto loc_8273FC3C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8273FC3C;
	sub_82130588(ctx, base);
loc_8273FC3C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8273FC44;
	sub_82130588(ctx, base);
loc_8273FC44:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8273FC58"))) PPC_WEAK_FUNC(sub_8273FC58);
PPC_FUNC_IMPL(__imp__sub_8273FC58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-21524
	ctx.r10.s64 = r11.s64 + -21524;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273fc78
	if (cr6.eq) goto loc_8273FC78;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-8484
	ctx.r3.s64 = r11.s64 + -8484;
	// blr 
	return;
loc_8273FC78:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,17384
	ctx.r3.s64 = r11.s64 + 17384;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273FC84"))) PPC_WEAK_FUNC(sub_8273FC84);
PPC_FUNC_IMPL(__imp__sub_8273FC84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273FC88"))) PPC_WEAK_FUNC(sub_8273FC88);
PPC_FUNC_IMPL(__imp__sub_8273FC88) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x8273FCA4;
	sub_824E0648(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r6,r11,-8452
	ctx.r6.s64 = r11.s64 + -8452;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lfs f0,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f13,31304(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31304);
	ctx.f13.f64 = double(temp.f32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lfs f0,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// lfs f13,-26872(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -26872);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lfs f0,11368(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11368);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lfs f13,-29484(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29484);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,-29924(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29924);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f13,60(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// lfs f12,14988(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f12,28(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// bl 0x8237c370
	ctx.lr = 0x8273FD40;
	sub_8237C370(ctx, base);
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// bl 0x8237c370
	ctx.lr = 0x8273FD48;
	sub_8237C370(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r5,304
	ctx.r5.s64 = 304;
	// li r3,96
	ctx.r3.s64 = 96;
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130528
	ctx.lr = 0x8273FD5C;
	sub_82130528(ctx, base);
	// li r5,96
	ctx.r5.s64 = 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,320(r31)
	PPC_STORE_U32(r31.u32 + 320, ctx.r3.u32);
	// bl 0x823d9890
	ctx.lr = 0x8273FD6C;
	sub_823D9890(ctx, base);
	// li r3,104
	ctx.r3.s64 = 104;
	// bl 0x82130528
	ctx.lr = 0x8273FD74;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fd88
	if (cr6.eq) goto loc_8273FD88;
	// bl 0x8237cbd8
	ctx.lr = 0x8273FD80;
	sub_8237CBD8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fd8c
	goto loc_8273FD8C;
loc_8273FD88:
	// li r11,0
	r11.s64 = 0;
loc_8273FD8C:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,240
	ctx.r3.s64 = 240;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FD9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fdb0
	if (cr6.eq) goto loc_8273FDB0;
	// bl 0x8237ccb8
	ctx.lr = 0x8273FDA8;
	sub_8237CCB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fdb4
	goto loc_8273FDB4;
loc_8273FDB0:
	// li r11,0
	r11.s64 = 0;
loc_8273FDB4:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,240
	ctx.r3.s64 = 240;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FDC4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fdd8
	if (cr6.eq) goto loc_8273FDD8;
	// bl 0x8237d048
	ctx.lr = 0x8273FDD0;
	sub_8237D048(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fddc
	goto loc_8273FDDC;
loc_8273FDD8:
	// li r11,0
	r11.s64 = 0;
loc_8273FDDC:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,336
	ctx.r3.s64 = 336;
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FDEC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fe00
	if (cr6.eq) goto loc_8273FE00;
	// bl 0x8237d0a0
	ctx.lr = 0x8273FDF8;
	sub_8237D0A0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fe04
	goto loc_8273FE04;
loc_8273FE00:
	// li r11,0
	r11.s64 = 0;
loc_8273FE04:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,336
	ctx.r3.s64 = 336;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FE14;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fe28
	if (cr6.eq) goto loc_8273FE28;
	// bl 0x8237d490
	ctx.lr = 0x8273FE20;
	sub_8237D490(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fe2c
	goto loc_8273FE2C;
loc_8273FE28:
	// li r11,0
	r11.s64 = 0;
loc_8273FE2C:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,108
	ctx.r3.s64 = 108;
	// stw r11,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FE3C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fe50
	if (cr6.eq) goto loc_8273FE50;
	// bl 0x8237d508
	ctx.lr = 0x8273FE48;
	sub_8237D508(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fe54
	goto loc_8273FE54;
loc_8273FE50:
	// li r11,0
	r11.s64 = 0;
loc_8273FE54:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,108
	ctx.r3.s64 = 108;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FE64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fe78
	if (cr6.eq) goto loc_8273FE78;
	// bl 0x8237d640
	ctx.lr = 0x8273FE70;
	sub_8237D640(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fe7c
	goto loc_8273FE7C;
loc_8273FE78:
	// li r11,0
	r11.s64 = 0;
loc_8273FE7C:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,4976
	ctx.r3.s64 = 4976;
	// stw r11,56(r10)
	PPC_STORE_U32(ctx.r10.u32 + 56, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FE8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fea0
	if (cr6.eq) goto loc_8273FEA0;
	// bl 0x8237d6a0
	ctx.lr = 0x8273FE98;
	sub_8237D6A0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fea4
	goto loc_8273FEA4;
loc_8273FEA0:
	// li r11,0
	r11.s64 = 0;
loc_8273FEA4:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,4976
	ctx.r3.s64 = 4976;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FEB4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fec8
	if (cr6.eq) goto loc_8273FEC8;
	// bl 0x8237dd10
	ctx.lr = 0x8273FEC0;
	sub_8237DD10(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fecc
	goto loc_8273FECC;
loc_8273FEC8:
	// li r11,0
	r11.s64 = 0;
loc_8273FECC:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,544
	ctx.r3.s64 = 544;
	// stw r11,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FEDC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273fef0
	if (cr6.eq) goto loc_8273FEF0;
	// bl 0x8237dd60
	ctx.lr = 0x8273FEE8;
	sub_8237DD60(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273fef4
	goto loc_8273FEF4;
loc_8273FEF0:
	// li r11,0
	r11.s64 = 0;
loc_8273FEF4:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,544
	ctx.r3.s64 = 544;
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FF04;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273ff18
	if (cr6.eq) goto loc_8273FF18;
	// bl 0x8237e290
	ctx.lr = 0x8273FF10;
	sub_8237E290(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273ff1c
	goto loc_8273FF1C;
loc_8273FF18:
	// li r11,0
	r11.s64 = 0;
loc_8273FF1C:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,4976
	ctx.r3.s64 = 4976;
	// stw r11,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FF2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273ff40
	if (cr6.eq) goto loc_8273FF40;
	// bl 0x8237e7f0
	ctx.lr = 0x8273FF38;
	sub_8237E7F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273ff44
	goto loc_8273FF44;
loc_8273FF40:
	// li r11,0
	r11.s64 = 0;
loc_8273FF44:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,4976
	ctx.r3.s64 = 4976;
	// stw r11,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FF54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273ff68
	if (cr6.eq) goto loc_8273FF68;
	// bl 0x8237e9d8
	ctx.lr = 0x8273FF60;
	sub_8237E9D8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273ff6c
	goto loc_8273FF6C;
loc_8273FF68:
	// li r11,0
	r11.s64 = 0;
loc_8273FF6C:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,192
	ctx.r3.s64 = 192;
	// stw r11,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FF7C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273ff90
	if (cr6.eq) goto loc_8273FF90;
	// bl 0x8237ea28
	ctx.lr = 0x8273FF88;
	sub_8237EA28(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273ff94
	goto loc_8273FF94;
loc_8273FF90:
	// li r11,0
	r11.s64 = 0;
loc_8273FF94:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,192
	ctx.r3.s64 = 192;
	// stw r11,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FFA4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273ffb8
	if (cr6.eq) goto loc_8273FFB8;
	// bl 0x8237eb78
	ctx.lr = 0x8273FFB0;
	sub_8237EB78(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273ffbc
	goto loc_8273FFBC;
loc_8273FFB8:
	// li r11,0
	r11.s64 = 0;
loc_8273FFBC:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,104
	ctx.r3.s64 = 104;
	// stw r11,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FFCC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273ffe0
	if (cr6.eq) goto loc_8273FFE0;
	// bl 0x8237e4c8
	ctx.lr = 0x8273FFD8;
	sub_8237E4C8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8273ffe4
	goto loc_8273FFE4;
loc_8273FFE0:
	// li r11,0
	r11.s64 = 0;
loc_8273FFE4:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,104
	ctx.r3.s64 = 104;
	// stw r11,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8273FFF4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740008
	if (cr6.eq) goto loc_82740008;
	// bl 0x8237e580
	ctx.lr = 0x82740000;
	sub_8237E580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8274000c
	goto loc_8274000C;
loc_82740008:
	// li r11,0
	r11.s64 = 0;
loc_8274000C:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,108
	ctx.r3.s64 = 108;
	// stw r11,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8274001C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740030
	if (cr6.eq) goto loc_82740030;
	// bl 0x8237e5d8
	ctx.lr = 0x82740028;
	sub_8237E5D8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82740034
	goto loc_82740034;
loc_82740030:
	// li r11,0
	r11.s64 = 0;
loc_82740034:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,108
	ctx.r3.s64 = 108;
	// stw r11,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x82740044;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740058
	if (cr6.eq) goto loc_82740058;
	// bl 0x8237e6d8
	ctx.lr = 0x82740050;
	sub_8237E6D8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8274005c
	goto loc_8274005C;
loc_82740058:
	// li r11,0
	r11.s64 = 0;
loc_8274005C:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,104
	ctx.r3.s64 = 104;
	// stw r11,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x8274006C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740080
	if (cr6.eq) goto loc_82740080;
	// bl 0x8237e730
	ctx.lr = 0x82740078;
	sub_8237E730(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82740084
	goto loc_82740084;
loc_82740080:
	// li r11,0
	r11.s64 = 0;
loc_82740084:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,104
	ctx.r3.s64 = 104;
	// stw r11,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x82740094;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827400a8
	if (cr6.eq) goto loc_827400A8;
	// bl 0x8237e790
	ctx.lr = 0x827400A0;
	sub_8237E790(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x827400ac
	goto loc_827400AC;
loc_827400A8:
	// li r11,0
	r11.s64 = 0;
loc_827400AC:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r3,544
	ctx.r3.s64 = 544;
	// stw r11,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x827400BC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827400d0
	if (cr6.eq) goto loc_827400D0;
	// bl 0x8237e2f0
	ctx.lr = 0x827400C8;
	sub_8237E2F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x827400d4
	goto loc_827400D4;
loc_827400D0:
	// li r11,0
	r11.s64 = 0;
loc_827400D4:
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
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

__attribute__((alias("__imp__sub_827400F8"))) PPC_WEAK_FUNC(sub_827400F8);
PPC_FUNC_IMPL(__imp__sub_827400F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-8420
	ctx.r3.s64 = r11.s64 + -8420;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82740104"))) PPC_WEAK_FUNC(sub_82740104);
PPC_FUNC_IMPL(__imp__sub_82740104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82740108"))) PPC_WEAK_FUNC(sub_82740108);
PPC_FUNC_IMPL(__imp__sub_82740108) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r31,0
	r31.s64 = 0;
	// addi r10,r11,-8452
	ctx.r10.s64 = r11.s64 + -8452;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
loc_82740130:
	// lwz r11,320(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740154
	if (cr6.eq) goto loc_82740154;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82740154;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82740154:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r31,96
	cr6.compare<int32_t>(r31.s32, 96, xer);
	// blt cr6,0x82740130
	if (cr6.lt) goto loc_82740130;
	// lwz r3,320(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 320);
	// bl 0x82130588
	ctx.lr = 0x82740168;
	sub_82130588(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e0430
	ctx.lr = 0x82740170;
	sub_824E0430(ctx, base);
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

__attribute__((alias("__imp__sub_82740188"))) PPC_WEAK_FUNC(sub_82740188);
PPC_FUNC_IMPL(__imp__sub_82740188) {
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
	// li r3,336
	ctx.r3.s64 = 336;
	// bl 0x82130528
	ctx.lr = 0x8274019C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827401c0
	if (cr6.eq) goto loc_827401C0;
	// bl 0x8273fc88
	ctx.lr = 0x827401A8;
	sub_8273FC88(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-21528(r11)
	PPC_STORE_U32(r11.u32 + -21528, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_827401C0:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21528(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21528, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827401DC"))) PPC_WEAK_FUNC(sub_827401DC);
PPC_FUNC_IMPL(__imp__sub_827401DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827401E0"))) PPC_WEAK_FUNC(sub_827401E0);
PPC_FUNC_IMPL(__imp__sub_827401E0) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,11672
	ctx.r4.s64 = r11.s64 + 11672;
	// bl 0x824e06e0
	ctx.lr = 0x82740200;
	sub_824E06E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0558
	ctx.lr = 0x82740208;
	sub_824E0558(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8274021C"))) PPC_WEAK_FUNC(sub_8274021C);
PPC_FUNC_IMPL(__imp__sub_8274021C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82740220"))) PPC_WEAK_FUNC(sub_82740220);
PPC_FUNC_IMPL(__imp__sub_82740220) {
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
	ctx.lr = 0x82740228;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-8268
	ctx.r5.s64 = r11.s64 + -8268;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,304
	ctx.r6.s64 = r31.s64 + 304;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82740254;
	sub_824DF200(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-8276
	ctx.r5.s64 = ctx.r10.s64 + -8276;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82740274;
	sub_824DF200(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-8284
	ctx.r5.s64 = ctx.r9.s64 + -8284;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82740294;
	sub_824DF200(ctx, base);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-8292
	ctx.r5.s64 = ctx.r8.s64 + -8292;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x827402B4;
	sub_824DF200(ctx, base);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-8308
	ctx.r5.s64 = ctx.r7.s64 + -8308;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x827402D4;
	sub_824DF200(ctx, base);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-8324
	ctx.r5.s64 = ctx.r6.s64 + -8324;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x827402F4;
	sub_824DF200(ctx, base);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-8344
	ctx.r5.s64 = ctx.r5.s64 + -8344;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,40
	ctx.r6.s64 = r31.s64 + 40;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740314;
	sub_824DF200(ctx, base);
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-8364
	ctx.r5.s64 = ctx.r4.s64 + -8364;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,48
	ctx.r6.s64 = r31.s64 + 48;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740334;
	sub_824DF200(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-8384
	ctx.r5.s64 = r11.s64 + -8384;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,56
	ctx.r6.s64 = r31.s64 + 56;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740354;
	sub_824DF200(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-8404
	ctx.r5.s64 = ctx.r10.s64 + -8404;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,64
	ctx.r6.s64 = r31.s64 + 64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82740374;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-20468
	ctx.r5.s64 = ctx.r9.s64 + -20468;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,80
	ctx.r6.s64 = r31.s64 + 80;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82740394;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-20480
	ctx.r5.s64 = ctx.r8.s64 + -20480;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x827403B4;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-20492
	ctx.r5.s64 = ctx.r7.s64 + -20492;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x827403D4;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-20512
	ctx.r5.s64 = ctx.r6.s64 + -20512;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x827403F4;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-20536
	ctx.r5.s64 = ctx.r5.s64 + -20536;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,136
	ctx.r6.s64 = r31.s64 + 136;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740414;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-20564
	ctx.r5.s64 = ctx.r4.s64 + -20564;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740434;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-20592
	ctx.r5.s64 = r11.s64 + -20592;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,152
	ctx.r6.s64 = r31.s64 + 152;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740454;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20616
	ctx.r5.s64 = ctx.r10.s64 + -20616;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740474;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-20632
	ctx.r5.s64 = ctx.r9.s64 + -20632;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,168
	ctx.r6.s64 = r31.s64 + 168;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82740494;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-20648
	ctx.r5.s64 = ctx.r7.s64 + -20648;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,172
	ctx.r6.s64 = r31.s64 + 172;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x827404B4;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r6,-20664
	ctx.r5.s64 = ctx.r6.s64 + -20664;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r31,176
	ctx.r6.s64 = r31.s64 + 176;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x827404D4;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-20676
	ctx.r5.s64 = ctx.r5.s64 + -20676;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,192
	ctx.r6.s64 = r31.s64 + 192;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x827404F4;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-20688
	ctx.r5.s64 = ctx.r4.s64 + -20688;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,208
	ctx.r6.s64 = r31.s64 + 208;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82740514;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-20700
	ctx.r5.s64 = r11.s64 + -20700;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82740534;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20720
	ctx.r5.s64 = ctx.r10.s64 + -20720;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,240
	ctx.r6.s64 = r31.s64 + 240;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740554;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-20744
	ctx.r5.s64 = ctx.r9.s64 + -20744;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,248
	ctx.r6.s64 = r31.s64 + 248;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740574;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-20772
	ctx.r5.s64 = ctx.r8.s64 + -20772;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,256
	ctx.r6.s64 = r31.s64 + 256;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x82740594;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-20800
	ctx.r5.s64 = ctx.r7.s64 + -20800;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,264
	ctx.r6.s64 = r31.s64 + 264;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x827405B4;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-20824
	ctx.r5.s64 = ctx.r6.s64 + -20824;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,272
	ctx.r6.s64 = r31.s64 + 272;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x827405D4;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r5,-20840
	ctx.r5.s64 = ctx.r5.s64 + -20840;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,280
	ctx.r6.s64 = r31.s64 + 280;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x827405F4;
	sub_824DF200(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r4,-20856
	ctx.r5.s64 = ctx.r4.s64 + -20856;
	// addi r6,r31,284
	ctx.r6.s64 = r31.s64 + 284;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82740614;
	sub_824DF200(ctx, base);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r3,-20872
	ctx.r5.s64 = ctx.r3.s64 + -20872;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,288
	ctx.r6.s64 = r31.s64 + 288;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82740634;
	sub_824DF200(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r27,r11,-32160
	r27.s64 = r11.s64 + -32160;
loc_82740640:
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82740684
	if (cr6.eq) goto loc_82740684;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwzx r4,r29,r27
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r27.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwz r28,0(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x824dfaf8
	ctx.lr = 0x8274066C;
	sub_824DFAF8(ctx, base);
	// lwz r9,320(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,60(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// lwzx r3,r29,r9
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82740684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82740684:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r29,96
	cr6.compare<int32_t>(r29.s32, 96, xer);
	// blt cr6,0x82740640
	if (cr6.lt) goto loc_82740640;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82740698"))) PPC_WEAK_FUNC(sub_82740698);
PPC_FUNC_IMPL(__imp__sub_82740698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lbz r11,-21424(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + -21424);
	// lbz r10,-5340(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + -5340);
	// stb r11,-5340(r8)
	PPC_STORE_U8(ctx.r8.u32 + -5340, r11.u8);
	// stb r10,-21424(r9)
	PPC_STORE_U8(ctx.r9.u32 + -21424, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827406B4"))) PPC_WEAK_FUNC(sub_827406B4);
PPC_FUNC_IMPL(__imp__sub_827406B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827406B8"))) PPC_WEAK_FUNC(sub_827406B8);
PPC_FUNC_IMPL(__imp__sub_827406B8) {
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
	// bl 0x82740108
	ctx.lr = 0x827406D8;
	sub_82740108(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827406f0
	if (cr6.eq) goto loc_827406F0;
	// bl 0x82130588
	ctx.lr = 0x827406EC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827406F0:
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

__attribute__((alias("__imp__sub_82740708"))) PPC_WEAK_FUNC(sub_82740708);
PPC_FUNC_IMPL(__imp__sub_82740708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-12
	r11.s64 = r11.s64 + -12;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274071C"))) PPC_WEAK_FUNC(sub_8274071C);
PPC_FUNC_IMPL(__imp__sub_8274071C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82740720"))) PPC_WEAK_FUNC(sub_82740720);
PPC_FUNC_IMPL(__imp__sub_82740720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82740730"))) PPC_WEAK_FUNC(sub_82740730);
PPC_FUNC_IMPL(__imp__sub_82740730) {
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
	ctx.lr = 0x82740738;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82606158
	ctx.lr = 0x82740748;
	sub_82606158(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r28,22
	r31.s64 = r28.s64 + 22;
loc_82740754:
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,-2
	ctx.r4.s64 = r31.s64 + -2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823dd800
	ctx.lr = 0x82740764;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82740778
	if (!cr6.eq) goto loc_82740778;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,58
	cr6.compare<uint32_t>(r11.u32, 58, xer);
	// beq cr6,0x827407c0
	if (cr6.eq) goto loc_827407C0;
loc_82740778:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,256
	r31.s64 = r31.s64 + 256;
	// cmpwi cr6,r30,6
	cr6.compare<int32_t>(r30.s32, 6, xer);
	// blt cr6,0x82740754
	if (cr6.lt) goto loc_82740754;
	// addi r3,r28,20
	ctx.r3.s64 = r28.s64 + 20;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82740790:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82740790
	if (!cr6.eq) goto loc_82740790;
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// ble cr6,0x827407b8
	if (!cr6.gt) goto loc_827407B8;
	// addi r3,r28,23
	ctx.r3.s64 = r28.s64 + 23;
loc_827407B8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827407C0:
	// rlwinm r11,r30,8,0,23
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r3,r11,23
	ctx.r3.s64 = r11.s64 + 23;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827407D4"))) PPC_WEAK_FUNC(sub_827407D4);
PPC_FUNC_IMPL(__imp__sub_827407D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827407D8"))) PPC_WEAK_FUNC(sub_827407D8);
PPC_FUNC_IMPL(__imp__sub_827407D8) {
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
	ctx.lr = 0x827407E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// li r30,0
	r30.s64 = 0;
	// addi r8,r9,-7920
	ctx.r8.s64 = ctx.r9.s64 + -7920;
	// li r29,13
	r29.s64 = 13;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r5,1536
	ctx.r5.s64 = 1536;
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r3,r11,20
	ctx.r3.s64 = r11.s64 + 20;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r29,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r29.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x8274084C;
	sub_823D9890(ctx, base);
	// addi r11,r31,1608
	r11.s64 = r31.s64 + 1608;
	// stb r30,1604(r31)
	PPC_STORE_U8(r31.u32 + 1604, r30.u8);
	// li r5,1536
	ctx.r5.s64 = 1536;
	// stw r30,1608(r31)
	PPC_STORE_U32(r31.u32 + 1608, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,1612(r31)
	PPC_STORE_U32(r31.u32 + 1612, r29.u32);
	// addi r3,r11,20
	ctx.r3.s64 = r11.s64 + 20;
	// stw r30,1616(r31)
	PPC_STORE_U32(r31.u32 + 1616, r30.u32);
	// stw r30,1620(r31)
	PPC_STORE_U32(r31.u32 + 1620, r30.u32);
	// stw r30,1624(r31)
	PPC_STORE_U32(r31.u32 + 1624, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x82740878;
	sub_823D9890(ctx, base);
	// stb r30,3164(r31)
	PPC_STORE_U8(r31.u32 + 3164, r30.u8);
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82130528
	ctx.lr = 0x82740884;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740894
	if (cr6.eq) goto loc_82740894;
	// bl 0x824f5c00
	ctx.lr = 0x82740890;
	sub_824F5C00(ctx, base);
	// b 0x82740898
	goto loc_82740898;
loc_82740894:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82740898:
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82130528
	ctx.lr = 0x827408A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827408b4
	if (cr6.eq) goto loc_827408B4;
	// bl 0x824f5c00
	ctx.lr = 0x827408B0;
	sub_824F5C00(ctx, base);
	// b 0x827408b8
	goto loc_827408B8;
loc_827408B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_827408B8:
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x827408C4;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827408e8
	if (cr6.eq) goto loc_827408E8;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_827408E8:
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827408F4"))) PPC_WEAK_FUNC(sub_827408F4);
PPC_FUNC_IMPL(__imp__sub_827408F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827408F8"))) PPC_WEAK_FUNC(sub_827408F8);
PPC_FUNC_IMPL(__imp__sub_827408F8) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-7920
	ctx.r10.s64 = r11.s64 + -7920;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740928
	if (cr6.eq) goto loc_82740928;
	// bl 0x82130588
	ctx.lr = 0x82740928;
	sub_82130588(ctx, base);
loc_82740928:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82740930;
	sub_82130588(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82740938;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82740940;
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

__attribute__((alias("__imp__sub_82740954"))) PPC_WEAK_FUNC(sub_82740954);
PPC_FUNC_IMPL(__imp__sub_82740954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82740958"))) PPC_WEAK_FUNC(sub_82740958);
PPC_FUNC_IMPL(__imp__sub_82740958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r20{};
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
	ctx.lr = 0x82740960;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226ce68
	ctx.lr = 0x82740974;
	sub_8226CE68(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82740e34
	if (cr6.gt) goto loc_82740E34;
	// lis r12,-32140
	r12.s64 = -2106327040;
	// addi r12,r12,2464
	r12.s64 = r12.s64 + 2464;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_827409C4;
	case 1:
		goto loc_82740A28;
	case 2:
		goto loc_82740B84;
	case 3:
		goto loc_82740BF0;
	case 4:
		goto loc_82740E34;
	case 5:
		goto loc_82740E34;
	case 6:
		goto loc_82740C54;
	case 7:
		goto loc_82740CF8;
	case 8:
		goto loc_82740D88;
	default:
		__builtin_unreachable();
	}
	// lwz r19,2500(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 2500);
	// lwz r19,2600(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 2600);
	// lwz r19,2948(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 2948);
	// lwz r19,3056(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 3056);
	// lwz r19,3636(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 3636);
	// lwz r19,3636(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 3636);
	// lwz r19,3156(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 3156);
	// lwz r19,3320(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 3320);
	// lwz r19,3464(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 3464);
loc_827409C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x827409CC;
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
	ctx.lr = 0x827409E0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lwz r29,16(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r27,12(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r28,r31,24
	r28.s64 = r31.s64 + 24;
	// bl 0x824e7110
	ctx.lr = 0x827409F4;
	sub_824E7110(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-7296
	ctx.r4.s64 = ctx.r9.s64 + -7296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// bl 0x824f6ea0
	ctx.lr = 0x82740A18;
	sub_824F6EA0(ctx, base);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740A28:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82740e34
	if (cr6.eq) goto loc_82740E34;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x82740b68
	if (!cr6.eq) goto loc_82740B68;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,1556
	ctx.r9.s64 = 1556;
	// addi r8,r31,1608
	ctx.r8.s64 = r31.s64 + 1608;
	// addi r29,r31,28
	r29.s64 = r31.s64 + 28;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// addi r28,r31,32
	r28.s64 = r31.s64 + 32;
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82740b14
	if (!cr6.eq) goto loc_82740B14;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82740A6C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82740A80;
	sub_82270170(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82740A8C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82740A9C;
	sub_82270170(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r25,16(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// lwz r27,8(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r24,r31,20
	r24.s64 = r31.s64 + 20;
	// bl 0x824e7118
	ctx.lr = 0x82740AB4;
	sub_824E7118(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r3,r26,16
	ctx.r3.s64 = r26.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82740AC0;
	sub_824E7110(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r24,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r24.u32);
	// addi r4,r9,-7296
	ctx.r4.s64 = ctx.r9.s64 + -7296;
	// stw r25,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r25.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// stb r11,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// bl 0x824f7308
	ctx.lr = 0x82740B04;
	sub_824F7308(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740B14:
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// addi r4,r7,-7296
	ctx.r4.s64 = ctx.r7.s64 + -7296;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// stb r3,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r3.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f7468
	ctx.lr = 0x82740B58;
	sub_824F7468(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740B68:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-7344
	ctx.r3.s64 = r11.s64 + -7344;
	// bl 0x82130000
	ctx.lr = 0x82740B74;
	sub_82130000(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740B84:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82740e34
	if (cr6.eq) goto loc_82740E34;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82740bcc
	if (!cr6.eq) goto loc_82740BCC;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-7388
	ctx.r3.s64 = r11.s64 + -7388;
	// bl 0x82130000
	ctx.lr = 0x82740BA8;
	sub_82130000(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r9,-7544
	ctx.r3.s64 = ctx.r9.s64 + -7544;
	// lwz r4,40(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// bl 0x82130000
	ctx.lr = 0x82740BBC;
	sub_82130000(ctx, base);
	// li r11,5
	r11.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740BCC:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-7588
	ctx.r3.s64 = r11.s64 + -7588;
	// bl 0x82130000
	ctx.lr = 0x82740BD8;
	sub_82130000(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// li r11,5
	r11.s64 = 5;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740BF0:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82740e34
	if (cr6.eq) goto loc_82740E34;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82740c38
	if (!cr6.eq) goto loc_82740C38;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-7632
	ctx.r3.s64 = r11.s64 + -7632;
	// bl 0x82130000
	ctx.lr = 0x82740C14;
	sub_82130000(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r9,-7544
	ctx.r3.s64 = ctx.r9.s64 + -7544;
	// lwz r4,40(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// bl 0x82130000
	ctx.lr = 0x82740C28;
	sub_82130000(ctx, base);
	// li r11,5
	r11.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740C38:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-7588
	ctx.r3.s64 = r11.s64 + -7588;
	// bl 0x82130000
	ctx.lr = 0x82740C44;
	sub_82130000(ctx, base);
	// li r11,5
	r11.s64 = 5;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740C54:
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// li r11,0
	r11.s64 = 0;
	// li r9,13
	ctx.r9.s64 = 13;
	// li r5,1536
	ctx.r5.s64 = 1536;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r9.u32);
	// addi r3,r10,20
	ctx.r3.s64 = ctx.r10.s64 + 20;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// bl 0x823d9890
	ctx.lr = 0x82740C84;
	sub_823D9890(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82740C8C;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,-10240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82740CA0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lwz r29,16(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r27,12(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r28,r31,24
	r28.s64 = r31.s64 + 24;
	// bl 0x824e7110
	ctx.lr = 0x82740CB4;
	sub_824E7110(ctx, base);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-7296
	ctx.r4.s64 = ctx.r6.s64 + -7296;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// bl 0x824f6ea0
	ctx.lr = 0x82740CD8;
	sub_824F6EA0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// subfic r4,r5,0
	xer.ca = ctx.r5.u32 <= 0;
	ctx.r4.s64 = 0 - ctx.r5.s64;
	// subfe r3,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + xer.ca < xer.ca);
	ctx.r3.u64 = ~ctx.r4.u64 + ctx.r4.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r3,0,31,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740CF8:
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82740e34
	if (cr6.eq) goto loc_82740E34;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82740d78
	if (!cr6.eq) goto loc_82740D78;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,1558
	ctx.r10.s64 = 1558;
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// ble cr6,0x82740d68
	if (!cr6.gt) goto loc_82740D68;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r8,r31,20
	ctx.r8.s64 = r31.s64 + 20;
	// addi r7,r31,44
	ctx.r7.s64 = r31.s64 + 44;
	// li r6,1558
	ctx.r6.s64 = 1558;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,40(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// bl 0x824f7578
	ctx.lr = 0x82740D48;
	sub_824F7578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r8,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r7,r11,11
	ctx.r7.s64 = r11.s64 + 11;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740D68:
	// li r11,12
	r11.s64 = 12;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740D78:
	// li r11,11
	r11.s64 = 11;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740D88:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82740e34
	if (cr6.eq) goto loc_82740E34;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82740e20
	if (!cr6.eq) goto loc_82740E20;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-7676
	ctx.r3.s64 = r11.s64 + -7676;
	// bl 0x82130000
	ctx.lr = 0x82740DAC;
	sub_82130000(ctx, base);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r9,-7544
	ctx.r3.s64 = ctx.r9.s64 + -7544;
	// lwz r4,40(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// bl 0x82130000
	ctx.lr = 0x82740DC0;
	sub_82130000(ctx, base);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r3,r8,-7712
	ctx.r3.s64 = ctx.r8.s64 + -7712;
	// bl 0x82130000
	ctx.lr = 0x82740DD0;
	sub_82130000(ctx, base);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r7,-7748
	ctx.r3.s64 = ctx.r7.s64 + -7748;
	// bl 0x82130000
	ctx.lr = 0x82740DE0;
	sub_82130000(ctx, base);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r3,r6,-7788
	ctx.r3.s64 = ctx.r6.s64 + -7788;
	// bl 0x82130000
	ctx.lr = 0x82740DF0;
	sub_82130000(ctx, base);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r3,r5,-7832
	ctx.r3.s64 = ctx.r5.s64 + -7832;
	// bl 0x82130000
	ctx.lr = 0x82740E00;
	sub_82130000(ctx, base);
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// addi r3,r3,-7872
	ctx.r3.s64 = ctx.r3.s64 + -7872;
	// bl 0x82130000
	ctx.lr = 0x82740E10;
	sub_82130000(ctx, base);
	// li r11,10
	r11.s64 = 10;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82740E20:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-7916
	ctx.r3.s64 = r11.s64 + -7916;
	// bl 0x82130000
	ctx.lr = 0x82740E2C;
	sub_82130000(ctx, base);
	// li r11,10
	r11.s64 = 10;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82740E34:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82740E3C"))) PPC_WEAK_FUNC(sub_82740E3C);
PPC_FUNC_IMPL(__imp__sub_82740E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82740E40"))) PPC_WEAK_FUNC(sub_82740E40);
PPC_FUNC_IMPL(__imp__sub_82740E40) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-7920
	ctx.r10.s64 = r11.s64 + -7920;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740e78
	if (cr6.eq) goto loc_82740E78;
	// bl 0x82130588
	ctx.lr = 0x82740E78;
	sub_82130588(ctx, base);
loc_82740E78:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82740E80;
	sub_82130588(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82740E88;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82740E90;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82740ea8
	if (cr6.eq) goto loc_82740EA8;
	// bl 0x82130588
	ctx.lr = 0x82740EA4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82740EA8:
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

__attribute__((alias("__imp__sub_82740EC0"))) PPC_WEAK_FUNC(sub_82740EC0);
PPC_FUNC_IMPL(__imp__sub_82740EC0) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-7260
	ctx.r9.s64 = r11.s64 + -7260;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r3,-3660(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3660);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740ef8
	if (cr6.eq) goto loc_82740EF8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226a930
	ctx.lr = 0x82740EF8;
	sub_8226A930(ctx, base);
loc_82740EF8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82740F00;
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

__attribute__((alias("__imp__sub_82740F14"))) PPC_WEAK_FUNC(sub_82740F14);
PPC_FUNC_IMPL(__imp__sub_82740F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82740F18"))) PPC_WEAK_FUNC(sub_82740F18);
PPC_FUNC_IMPL(__imp__sub_82740F18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-7260
	ctx.r9.s64 = ctx.r10.s64 + -7260;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r8,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r8.u16);
	// stb r4,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82740F40"))) PPC_WEAK_FUNC(sub_82740F40);
PPC_FUNC_IMPL(__imp__sub_82740F40) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-7260
	ctx.r9.s64 = r11.s64 + -7260;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r3,-3660(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3660);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82740f80
	if (cr6.eq) goto loc_82740F80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226a930
	ctx.lr = 0x82740F80;
	sub_8226A930(ctx, base);
loc_82740F80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82740F88;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82740fa0
	if (cr6.eq) goto loc_82740FA0;
	// bl 0x82130588
	ctx.lr = 0x82740F9C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82740FA0:
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

__attribute__((alias("__imp__sub_82740FB8"))) PPC_WEAK_FUNC(sub_82740FB8);
PPC_FUNC_IMPL(__imp__sub_82740FB8) {
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
	// bl 0x8258ba00
	ctx.lr = 0x82740FD0;
	sub_8258BA00(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-6912
	ctx.r10.s64 = r11.s64 + -6912;
	// li r4,128
	ctx.r4.s64 = 128;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x825898f0
	ctx.lr = 0x82740FE8;
	sub_825898F0(ctx, base);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,10224(r9)
	PPC_STORE_U32(ctx.r9.u32 + 10224, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8274100C"))) PPC_WEAK_FUNC(sub_8274100C);
PPC_FUNC_IMPL(__imp__sub_8274100C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82741010"))) PPC_WEAK_FUNC(sub_82741010);
PPC_FUNC_IMPL(__imp__sub_82741010) {
	PPC_FUNC_PROLOGUE();
	// b 0x82588490
	sub_82588490(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82741014"))) PPC_WEAK_FUNC(sub_82741014);
PPC_FUNC_IMPL(__imp__sub_82741014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82741018"))) PPC_WEAK_FUNC(sub_82741018);
PPC_FUNC_IMPL(__imp__sub_82741018) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-6912
	ctx.r10.s64 = r11.s64 + -6912;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8258a938
	ctx.lr = 0x82741044;
	sub_8258A938(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274105c
	if (cr6.eq) goto loc_8274105C;
	// bl 0x82130588
	ctx.lr = 0x82741058;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8274105C:
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

__attribute__((alias("__imp__sub_82741074"))) PPC_WEAK_FUNC(sub_82741074);
PPC_FUNC_IMPL(__imp__sub_82741074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82741078"))) PPC_WEAK_FUNC(sub_82741078);
PPC_FUNC_IMPL(__imp__sub_82741078) {
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
	ctx.lr = 0x82741080;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x82741094;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827411e0
	if (!cr6.eq) goto loc_827411E0;
	// lis r29,-32114
	r29.s64 = -2104623104;
loc_827410A4:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r7,165(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 165);
	// rlwinm r6,r7,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x827411c0
	if (cr6.eq) goto loc_827411C0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a7c28
	ctx.lr = 0x827410CC;
	sub_822A7C28(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827411c0
	if (cr6.eq) goto loc_827411C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827410E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x8274110c
	if (cr6.eq) goto loc_8274110C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82741104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x827411c0
	if (!cr6.eq) goto loc_827411C0;
loc_8274110C:
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x827411c0
	if (cr6.eq) goto loc_827411C0;
	// lwz r11,-23452(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23452);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x827411c0
	if (!cr6.eq) goto loc_827411C0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82342598
	ctx.lr = 0x82741140;
	sub_82342598(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x827411c0
	if (!cr6.eq) goto loc_827411C0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,12
	cr6.compare<uint32_t>(ctx.r10.u32, 12, xer);
	// bne cr6,0x827411c0
	if (!cr6.eq) goto loc_827411C0;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82741178
	if (cr6.eq) goto loc_82741178;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x827411c0
	if (!cr6.eq) goto loc_827411C0;
loc_82741178:
	// lhz r11,146(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 146);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x827411c0
	if (!cr6.gt) goto loc_827411C0;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
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
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827411c0
	if (cr6.eq) goto loc_827411C0;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// lwz r3,160(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 160);
	// bl 0x825a2e00
	ctx.lr = 0x827411C0;
	sub_825A2E00(ctx, base);
loc_827411C0:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x827411D4;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827410a4
	if (cr6.eq) goto loc_827410A4;
loc_827411E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827411E8"))) PPC_WEAK_FUNC(sub_827411E8);
PPC_FUNC_IMPL(__imp__sub_827411E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f13,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fabs f0,f13
	f0.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lfs f12,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x82741260
	if (!cr6.gt) goto loc_82741260;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f7,f0,f13
	ctx.f7.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fdivs f6,f0,f8
	ctx.f6.f64 = double(float(f0.f64 / ctx.f8.f64));
	// fmuls f5,f12,f7
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f7.f64));
	// fmuls f4,f11,f7
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
	// fdivs f3,f5,f10
	ctx.f3.f64 = double(float(ctx.f5.f64 / ctx.f10.f64));
	// fdivs f2,f4,f9
	ctx.f2.f64 = double(float(ctx.f4.f64 / ctx.f9.f64));
	// fmuls f1,f3,f3
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f3.f64));
	// fmadds f13,f2,f2,f1
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f1.f64));
	// fmadds f12,f6,f6,f13
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f13.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// fdivs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 / ctx.f11.f64));
	// stfs f10,0(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fmuls f9,f10,f5
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// stfs f9,4(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fmuls f8,f10,f4
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f4.f64));
	// stfs f8,8(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
loc_82741260:
	// lfs f0,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x827412bc
	if (!cr6.gt) goto loc_827412BC;
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fdivs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 / f0.f64));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f11,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 / ctx.f10.f64));
	// fdivs f8,f12,f11
	ctx.f8.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fmuls f7,f9,f9
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f6,f8,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fsqrts f5,f6
	ctx.f5.f64 = double(float(sqrt(ctx.f6.f64)));
	// fdivs f4,f0,f5
	ctx.f4.f64 = double(float(f0.f64 / ctx.f5.f64));
	// stfs f4,4(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fmuls f3,f4,f12
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// stfs f3,8(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
loc_827412BC:
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f0,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827412D4"))) PPC_WEAK_FUNC(sub_827412D4);
PPC_FUNC_IMPL(__imp__sub_827412D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827412D8"))) PPC_WEAK_FUNC(sub_827412D8);
PPC_FUNC_IMPL(__imp__sub_827412D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
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
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x827412E0;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9c8
	ctx.lr = 0x827412E8;
	// li r12,-224
	r12.s64 = -224;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-192
	r12.s64 = -192;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r19,0
	r19.s64 = 0;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827413bc
	if (cr6.eq) goto loc_827413BC;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,72
	r26.s64 = 72;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r1,160
	r29.s64 = ctx.r1.s64 + 160;
	// addi r30,r1,240
	r30.s64 = ctx.r1.s64 + 240;
loc_8274132C:
	// lbzx r11,r26,r27
	r11.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82741340
	if (cr6.eq) goto loc_82741340;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x82741344
	goto loc_82741344;
loc_82741340:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_82741344:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x827413bc
	if (!cr6.lt) goto loc_827413BC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a39f0
	ctx.lr = 0x82741354;
	sub_822A39F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827413b0
	if (cr6.eq) goto loc_827413B0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8274136C;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827413b0
	if (cr6.eq) goto loc_827413B0;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// rlwinm r8,r9,0,28,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827413b0
	if (cr6.eq) goto loc_827413B0;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x82332098
	ctx.lr = 0x827413A0;
	sub_82332098(ctx, base);
	// stb r3,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r3.u8);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_827413B0:
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// b 0x8274132c
	goto loc_8274132C;
loc_827413BC:
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lwz r8,-5148(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + -5148);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82741484
	if (cr6.eq) goto loc_82741484;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// rlwinm r9,r19,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// li r26,72
	r26.s64 = 72;
	// li r28,0
	r28.s64 = 0;
	// add r30,r19,r11
	r30.u64 = r19.u64 + r11.u64;
	// li r29,0
	r29.s64 = 0;
	// add r31,r9,r10
	r31.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_827413F0:
	// lbzx r10,r26,r27
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82741404
	if (cr6.eq) goto loc_82741404;
	// lhz r11,20(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 20);
	// b 0x82741408
	goto loc_82741408;
loc_82741404:
	// lhz r11,12(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 12);
loc_82741408:
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x82741484
	if (!cr6.lt) goto loc_82741484;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82741420
	if (cr6.eq) goto loc_82741420;
	// lwz r11,16(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// b 0x82741424
	goto loc_82741424;
loc_82741420:
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
loc_82741424:
	// lwzx r11,r11,r29
	r11.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82741478
	if (cr6.eq) goto loc_82741478;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82741478
	if (cr6.eq) goto loc_82741478;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// rlwinm r7,r9,0,28,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82741478
	if (cr6.eq) goto loc_82741478;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82332098
	ctx.lr = 0x82741464;
	sub_82332098(ctx, base);
	// stb r3,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r3.u8);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// lwz r8,-5148(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + -5148);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82741478:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// b 0x827413f0
	goto loc_827413F0;
loc_82741484:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,-28880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28880);
	f0.f64 = double(temp.f32);
	// lfs f13,-6176(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6176);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// lfs f12,-15752(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -15752);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-332(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -332);
	ctx.f11.f64 = double(temp.f32);
	// lfs f24,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f24.f64 = double(temp.f32);
	// lfs f10,32680(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 32680);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f24,100(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ble cr6,0x827417e4
	if (!cr6.gt) goto loc_827417E4;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r20,r11,-1
	r20.s64 = r11.s64 + -1;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f25,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f25.f64 = double(temp.f32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfd f27,32224(r8)
	f27.u64 = PPC_LOAD_U64(ctx.r8.u32 + 32224);
	// lfd f28,21560(r7)
	f28.u64 = PPC_LOAD_U64(ctx.r7.u32 + 21560);
	// li r27,1
	r27.s64 = 1;
	// lfs f26,14196(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14196);
	f26.f64 = double(temp.f32);
	// addi r24,r1,240
	r24.s64 = ctx.r1.s64 + 240;
	// lfs f29,10012(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 10012);
	f29.f64 = double(temp.f32);
	// mr r21,r19
	r21.u64 = r19.u64;
	// lfs f30,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	f30.f64 = double(temp.f32);
	// li r22,256
	r22.s64 = 256;
	// li r25,32
	r25.s64 = 32;
	// li r26,16
	r26.s64 = 16;
	// addi r23,r11,2256
	r23.s64 = r11.s64 + 2256;
loc_8274153C:
	// lbzx r10,r20,r27
	ctx.r10.u64 = PPC_LOAD_U8(r20.u32 + r27.u32);
	// add r11,r20,r27
	r11.u64 = r20.u64 + r27.u64;
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// beq cr6,0x8274155c
	if (cr6.eq) goto loc_8274155C;
	// stvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82741560
	goto loc_82741560;
loc_8274155C:
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82741560:
	// cmpw cr6,r27,r19
	cr6.compare<int32_t>(r27.s32, r19.s32, xer);
	// bge cr6,0x827417d4
	if (!cr6.lt) goto loc_827417D4;
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// addi r30,r24,4
	r30.s64 = r24.s64 + 4;
	// subf r29,r27,r19
	r29.s64 = r19.s64 - r27.s64;
loc_82741574:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,16(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r7,20(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x827417c4
	if (cr6.eq) goto loc_827417C4;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// and r8,r11,r10
	ctx.r8.u64 = r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827417c4
	if (cr6.eq) goto loc_827417C4;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// beq cr6,0x827415c8
	if (cr6.eq) goto loc_827415C8;
	// stvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x827415cc
	goto loc_827415CC;
loc_827415C8:
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827415CC:
	// lvx128 v63,r31,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r9,r22
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v62,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v63,v62,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f31,f10
	f31.f64 = double(float(sqrt(ctx.f10.f64)));
	// fdivs f9,f30,f31
	ctx.f9.f64 = double(float(f30.f64 / f31.f64));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// vmulfp128 v63,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// bge cr6,0x827417c4
	if (!cr6.lt) goto loc_827417C4;
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// vspltisw128 v59,-1
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r10,r9,208
	ctx.r10.s64 = ctx.r9.s64 + 208;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// vslw128 v58,v59,v59
	v58.u32[0] = v59.u32[0] << (v59.u8[0] & 0x1F);
	v58.u32[1] = v59.u32[1] << (v59.u8[4] & 0x1F);
	v58.u32[2] = v59.u32[2] << (v59.u8[8] & 0x1F);
	v58.u32[3] = v59.u32[3] << (v59.u8[12] & 0x1F);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v56,v59,v59
	v56.u32[0] = v59.u32[0] << (v59.u8[0] & 0x1F);
	v56.u32[1] = v59.u32[1] << (v59.u8[4] & 0x1F);
	v56.u32[2] = v59.u32[2] << (v59.u8[8] & 0x1F);
	v56.u32[3] = v59.u32[3] << (v59.u8[12] & 0x1F);
	// lvx128 v55,r11,r25
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v54,v57,v63
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v53,v55,v63
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v52,r11,r26
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v51,v52,v63
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r10,r25
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v48,v50,v63
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v47,v49,v63
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v46,r10,r26
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v45,v46,v63
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// vmrghw128 v44,v54,v53
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v43,v48,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v42,v51,v44
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v41,v45,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v40,v44,v42
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v39,v43,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vandc128 v38,v40,v58
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v40.u8)));
	// vandc128 v37,v39,v56
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v39.u8)));
	// stvx128 v38,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x827411e8
	ctx.lr = 0x827416A4;
	sub_827411E8(ctx, base);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x827411e8
	ctx.lr = 0x827416B4;
	sub_827411E8(ctx, base);
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// lfs f12,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// lfs f0,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f0.f64 = double(temp.f32);
	// fmuls f9,f0,f0
	ctx.f9.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f0.f64 = double(temp.f32);
	// fmadds f8,f13,f13,f10
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f7,f0,f0,f9
	ctx.f7.f64 = double(float(f0.f64 * f0.f64 + ctx.f9.f64));
	// fsqrts f6,f8
	ctx.f6.f64 = double(float(sqrt(ctx.f8.f64)));
	// fmadds f5,f12,f12,f7
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fsqrts f4,f5
	ctx.f4.f64 = double(float(sqrt(ctx.f5.f64)));
	// fadds f12,f4,f6
	ctx.f12.f64 = double(float(ctx.f4.f64 + ctx.f6.f64));
	// fcmpu cr6,f31,f12
	cr6.compare(f31.f64, ctx.f12.f64);
	// bge cr6,0x827417c4
	if (!cr6.lt) goto loc_827417C4;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f0,f13,f13,f10
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// ble cr6,0x82741764
	if (!cr6.gt) goto loc_82741764;
	// frsqrte f13,f0
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// fneg f11,f0
	ctx.f11.u64 = f0.u64 ^ 0x8000000000000000;
	// fmul f10,f13,f13
	ctx.f10.f64 = ctx.f13.f64 * ctx.f13.f64;
	// fmul f9,f13,f27
	ctx.f9.f64 = ctx.f13.f64 * f27.f64;
	// fnmsub f8,f10,f0,f28
	ctx.f8.f64 = -(ctx.f10.f64 * f0.f64 - f28.f64);
	// fmadd f7,f8,f9,f13
	ctx.f7.f64 = ctx.f8.f64 * ctx.f9.f64 + ctx.f13.f64;
	// fmul f6,f7,f7
	ctx.f6.f64 = ctx.f7.f64 * ctx.f7.f64;
	// fmul f5,f7,f27
	ctx.f5.f64 = ctx.f7.f64 * f27.f64;
	// fnmsub f4,f6,f0,f28
	ctx.f4.f64 = -(ctx.f6.f64 * f0.f64 - f28.f64);
	// fmadd f3,f4,f5,f7
	ctx.f3.f64 = ctx.f4.f64 * ctx.f5.f64 + ctx.f7.f64;
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fsel f1,f11,f25,f2
	ctx.f1.f64 = ctx.f11.f64 >= 0.0 ? f25.f64 : ctx.f2.f64;
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v36,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v35,v36,0
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0xFF));
	// vmulfp128 v62,v62,v35
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v35.f32)));
loc_82741764:
	// fsubs f0,f12,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 - f31.f64));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,108(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// fmuls f13,f0,f24
	ctx.f13.f64 = double(float(f0.f64 * f24.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v34,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v33,v34,0
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// vmulfp128 v125,v62,v33
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v125.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v33.f32)));
	// vor128 v1,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827417A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// vspltisw128 v32,0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,108(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	// vsubfp128 v1,v32,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v125.f32)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827417C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827417C4:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// bne 0x82741574
	if (!cr0.eq) goto loc_82741574;
loc_827417D4:
	// addic. r21,r21,-1
	xer.ca = r21.u32 > 0;
	r21.s64 = r21.s64 + -1;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// bne 0x8274153c
	if (!cr0.eq) goto loc_8274153C;
loc_827417E4:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// li r0,-224
	r0.s64 = -224;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-192
	r0.s64 = -192;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba14
	ctx.lr = 0x82741808;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8274180C"))) PPC_WEAK_FUNC(sub_8274180C);
PPC_FUNC_IMPL(__imp__sub_8274180C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82741810"))) PPC_WEAK_FUNC(sub_82741810);
PPC_FUNC_IMPL(__imp__sub_82741810) {
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
	// bl 0x8258a300
	ctx.lr = 0x82741828;
	sub_8258A300(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827412d8
	ctx.lr = 0x82741830;
	sub_827412D8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82741844"))) PPC_WEAK_FUNC(sub_82741844);
PPC_FUNC_IMPL(__imp__sub_82741844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82741848"))) PPC_WEAK_FUNC(sub_82741848);
PPC_FUNC_IMPL(__imp__sub_82741848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r11.u16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274185C"))) PPC_WEAK_FUNC(sub_8274185C);
PPC_FUNC_IMPL(__imp__sub_8274185C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82741860"))) PPC_WEAK_FUNC(sub_82741860);
PPC_FUNC_IMPL(__imp__sub_82741860) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82741868;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82741908
	if (cr6.eq) goto loc_82741908;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lis r25,-32112
	r25.s64 = -2104492032;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// ori r24,r10,65535
	r24.u64 = ctx.r10.u64 | 65535;
loc_827418A0:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// add r31,r11,r28
	r31.u64 = r11.u64 + r28.u64;
	// add r27,r10,r29
	r27.u64 = ctx.r10.u64 + r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r11,r11,r28
	r11.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827418C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827418e0
	if (cr6.eq) goto loc_827418E0;
	// stfs f31,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-2288(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -2288);
	// bl 0x82588338
	ctx.lr = 0x827418E0;
	sub_82588338(ctx, base);
loc_827418E0:
	// lhz r11,8(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x827418f0
	if (cr6.eq) goto loc_827418F0;
	// sth r24,8(r27)
	PPC_STORE_U16(r27.u32 + 8, r24.u16);
loc_827418F0:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// addi r28,r28,24
	r28.s64 = r28.s64 + 24;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x827418a0
	if (cr6.lt) goto loc_827418A0;
loc_82741908:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21496(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21496, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82741920"))) PPC_WEAK_FUNC(sub_82741920);
PPC_FUNC_IMPL(__imp__sub_82741920) {
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
	ctx.lr = 0x82741928;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827419d4
	if (cr6.eq) goto loc_827419D4;
	// li r29,0
	r29.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lis r27,-32112
	r27.s64 = -2104492032;
	// lis r28,-32111
	r28.s64 = -2104426496;
loc_82741950:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x827419bc
	if (cr6.eq) goto loc_827419BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274197C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827419bc
	if (!cr6.eq) goto loc_827419BC;
	// lwz r11,-21496(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -21496);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r3,-2288(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -2288);
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + r30.u64;
	// stw r11,-21496(r28)
	PPC_STORE_U32(r28.u32 + -21496, r11.u32);
	// bl 0x82588338
	ctx.lr = 0x827419A4;
	sub_82588338(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-2288(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -2288);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// bl 0x8258b6c8
	ctx.lr = 0x827419BC;
	sub_8258B6C8(ctx, base);
loc_827419BC:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x82741950
	if (cr6.lt) goto loc_82741950;
loc_827419D4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827419DC"))) PPC_WEAK_FUNC(sub_827419DC);
PPC_FUNC_IMPL(__imp__sub_827419DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827419E0"))) PPC_WEAK_FUNC(sub_827419E0);
PPC_FUNC_IMPL(__imp__sub_827419E0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827419E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82741a28
	if (!cr6.gt) goto loc_82741A28;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_82741A0C:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x82741a28
	if (cr6.eq) goto loc_82741A28;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x82741a0c
	if (cr6.lt) goto loc_82741A0C;
loc_82741A28:
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x82741b0c
	if (!cr6.lt) goto loc_82741B0C;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r29,r9,3,0,28
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// lwz r11,-21496(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21496);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-21496(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21496, r11.u32);
	// stw r5,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r5.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// lwzx r7,r11,r29
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82741A70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,16
	ctx.r8.s64 = 16;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r5,r30,r11
	ctx.r5.u64 = r30.u64 + r11.u64;
	// li r9,32
	ctx.r9.s64 = 32;
	// rlwinm r30,r5,4,0,27
	r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// li r10,48
	ctx.r10.s64 = 48;
	// lis r27,-32112
	r27.s64 = -2104492032;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r28,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r28,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r28,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// lwz r3,-2288(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -2288);
	// bl 0x8258b598
	ctx.lr = 0x82741AC8;
	sub_8258B598(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// lwz r3,-2288(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -2288);
	// bl 0x825882f0
	ctx.lr = 0x82741AD8;
	sub_825882F0(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82741afc
	if (!cr6.eq) goto loc_82741AFC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-2288(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -2288);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// bl 0x8258b6c8
	ctx.lr = 0x82741AFC;
	sub_8258B6C8(ctx, base);
loc_82741AFC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82741B0C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82741B18"))) PPC_WEAK_FUNC(sub_82741B18);
PPC_FUNC_IMPL(__imp__sub_82741B18) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82741B20;
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f29.u64);
	// stfd f30,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd534
	ctx.lr = 0x82741B34;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// lis r11,819
	r11.s64 = 53673984;
	// clrlwi r26,r4,16
	r26.u64 = ctx.r4.u32 & 0xFFFF;
	// ori r10,r11,13107
	ctx.r10.u64 = r11.u64 | 13107;
	// li r28,-1
	r28.s64 = -1;
	// sth r4,0(r21)
	PPC_STORE_U16(r21.u32 + 0, ctx.r4.u16);
	// cmplw cr6,r26,r10
	cr6.compare<uint32_t>(r26.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82741b74
	if (cr6.gt) goto loc_82741B74;
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,-17
	ctx.r10.s64 = -17;
	// add r9,r26,r11
	ctx.r9.u64 = r26.u64 + r11.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// ble cr6,0x82741b78
	if (!cr6.gt) goto loc_82741B78;
loc_82741B74:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82741B78:
	// bl 0x82130528
	ctx.lr = 0x82741B7C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82741bb0
	if (cr6.eq) goto loc_82741BB0;
	// addi r29,r3,16
	r29.s64 = ctx.r3.s64 + 16;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// addic. r31,r26,-1
	xer.ca = r26.u32 > 0;
	r31.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// mr r30,r29
	r30.u64 = r29.u64;
	// blt 0x82741bb4
	if (cr0.lt) goto loc_82741BB4;
loc_82741B98:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82595558
	ctx.lr = 0x82741BA0;
	sub_82595558(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// bge 0x82741b98
	if (!cr0.lt) goto loc_82741B98;
	// b 0x82741bb4
	goto loc_82741BB4;
loc_82741BB0:
	// li r29,0
	r29.s64 = 0;
loc_82741BB4:
	// lis r11,2730
	r11.s64 = 178913280;
	// stw r29,4(r21)
	PPC_STORE_U32(r21.u32 + 4, r29.u32);
	// ori r10,r11,43690
	ctx.r10.u64 = r11.u64 | 43690;
	// cmplw cr6,r26,r10
	cr6.compare<uint32_t>(r26.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82741be4
	if (cr6.gt) goto loc_82741BE4;
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-5
	ctx.r10.s64 = -5;
	// add r9,r26,r11
	ctx.r9.u64 = r26.u64 + r11.u64;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// ble cr6,0x82741be8
	if (!cr6.gt) goto loc_82741BE8;
loc_82741BE4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82741BE8:
	// bl 0x82130528
	ctx.lr = 0x82741BEC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82741c20
	if (cr6.eq) goto loc_82741C20;
	// addi r29,r3,4
	r29.s64 = ctx.r3.s64 + 4;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// addic. r31,r26,-1
	xer.ca = r26.u32 > 0;
	r31.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// mr r30,r29
	r30.u64 = r29.u64;
	// blt 0x82741c24
	if (cr0.lt) goto loc_82741C24;
loc_82741C08:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82742748
	ctx.lr = 0x82741C10;
	sub_82742748(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bge 0x82741c08
	if (!cr0.lt) goto loc_82741C08;
	// b 0x82741c24
	goto loc_82741C24;
loc_82741C20:
	// li r29,0
	r29.s64 = 0;
loc_82741C24:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// stw r29,8(r21)
	PPC_STORE_U32(r21.u32 + 8, r29.u32);
	// ble cr6,0x82741d5c
	if (!cr6.gt) goto loc_82741D5C;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r27,0
	r27.s64 = 0;
	// vupkd3d128 v63,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v63 = vTemp;
	// li r28,0
	r28.s64 = 0;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r22,16
	r22.s64 = 16;
	// lfs f29,14196(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14196);
	f29.f64 = double(temp.f32);
	// li r23,32
	r23.s64 = 32;
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// li r24,48
	r24.s64 = 48;
	// vpermwi128 v126,v63,234
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// vpermwi128 v125,v63,186
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v124,v63,174
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
loc_82741C70:
	// lwz r11,4(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 4);
	// li r3,160
	ctx.r3.s64 = 160;
	// lwz r10,8(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 8);
	// add r30,r11,r28
	r30.u64 = r11.u64 + r28.u64;
	// add r25,r27,r10
	r25.u64 = r27.u64 + ctx.r10.u64;
	// bl 0x82130528
	ctx.lr = 0x82741C88;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82741ca0
	if (cr6.eq) goto loc_82741CA0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x82582c08
	ctx.lr = 0x82741C98;
	sub_82582C08(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x82741ca4
	goto loc_82741CA4;
loc_82741CA0:
	// li r29,0
	r29.s64 = 0;
loc_82741CA4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x82582570
	ctx.lr = 0x82741CB0;
	sub_82582570(ctx, base);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x82741CB8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82741ccc
	if (cr6.eq) goto loc_82741CCC;
	// bl 0x8258f4a8
	ctx.lr = 0x82741CC4;
	sub_8258F4A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82741cd0
	goto loc_82741CD0;
loc_82741CCC:
	// li r31,0
	r31.s64 = 0;
loc_82741CD0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8258e6b8
	ctx.lr = 0x82741CDC;
	sub_8258E6B8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82741CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82741D18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82595580
	ctx.lr = 0x82741D28;
	sub_82595580(ctx, base);
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r11,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82582fd0
	ctx.lr = 0x82741D48;
	sub_82582FD0(ctx, base);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// stw r30,4(r25)
	PPC_STORE_U32(r25.u32 + 4, r30.u32);
	// addi r28,r28,80
	r28.s64 = r28.s64 + 80;
	// addi r27,r27,24
	r27.s64 = r27.s64 + 24;
	// bne 0x82741c70
	if (!cr0.eq) goto loc_82741C70;
loc_82741D5C:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd7cc
	ctx.lr = 0x82741D68;
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

__attribute__((alias("__imp__sub_82741D78"))) PPC_WEAK_FUNC(sub_82741D78);
PPC_FUNC_IMPL(__imp__sub_82741D78) {
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
	ctx.lr = 0x82741D80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r11,r28,0,30,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82741dec
	if (cr6.eq) goto loc_82741DEC;
	// lwz r11,-4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// addi r29,r30,-4
	r29.s64 = r30.s64 + -4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// blt 0x82741dcc
	if (cr0.lt) goto loc_82741DCC;
loc_82741DB8:
	// addi r30,r30,-24
	r30.s64 = r30.s64 + -24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82741e18
	ctx.lr = 0x82741DC4;
	sub_82741E18(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x82741db8
	if (!cr0.lt) goto loc_82741DB8;
loc_82741DCC:
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82741de0
	if (cr6.eq) goto loc_82741DE0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82741DE0;
	sub_82130588(ctx, base);
loc_82741DE0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82741DEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82741e18
	ctx.lr = 0x82741DF4;
	sub_82741E18(ctx, base);
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82741e08
	if (cr6.eq) goto loc_82741E08;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82741E08;
	sub_82130588(ctx, base);
loc_82741E08:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82741E14"))) PPC_WEAK_FUNC(sub_82741E14);
PPC_FUNC_IMPL(__imp__sub_82741E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82741E18"))) PPC_WEAK_FUNC(sub_82741E18);
PPC_FUNC_IMPL(__imp__sub_82741E18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,31072
	ctx.r10.s64 = r11.s64 + 31072;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82741E28"))) PPC_WEAK_FUNC(sub_82741E28);
PPC_FUNC_IMPL(__imp__sub_82741E28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lfs f0,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f30,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f30.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f10,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// fmadds f8,f9,f31,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64 + f0.f64));
	// stfs f8,12(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82741E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82741ee8
	if (cr6.eq) goto loc_82741EE8;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x82741ee8
	if (cr6.eq) goto loc_82741EE8;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f13,f31,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f31.f64 + f0.f64));
	// stfs f1,8(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82582570
	ctx.lr = 0x82741EB8;
	sub_82582570(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lhz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwz r3,-23452(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23452);
	// bl 0x82573b58
	ctx.lr = 0x82741ED4;
	sub_82573B58(ctx, base);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lwz r3,-2288(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -2288);
	// lhz r4,8(r7)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + 8);
	// bl 0x825880d8
	ctx.lr = 0x82741EE8;
	sub_825880D8(ctx, base);
loc_82741EE8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_82741F04"))) PPC_WEAK_FUNC(sub_82741F04);
PPC_FUNC_IMPL(__imp__sub_82741F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82741F08"))) PPC_WEAK_FUNC(sub_82741F08);
PPC_FUNC_IMPL(__imp__sub_82741F08) {
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
	PPCRegister f0{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
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
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x82741F10;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823db9d0
	ctx.lr = 0x82741F18;
	// addi r12,r1,-192
	r12.s64 = ctx.r1.s64 + -192;
	// bl 0x823dd534
	ctx.lr = 0x82741F20;
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x8274272c
	if (cr6.eq) goto loc_8274272C;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r18,4(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274272c
	if (cr6.eq) goto loc_8274272C;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8274272c
	if (cr6.eq) goto loc_8274272C;
	// lwz r10,16(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 16);
	// li r28,0
	r28.s64 = 0;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82741f80
	if (cr6.eq) goto loc_82741F80;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r11,1
	r11.s64 = 1;
	// lwz r10,20(r18)
	ctx.r10.u64 = PPC_LOAD_U32(r18.u32 + 20);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82741f84
	if (!cr6.eq) goto loc_82741F84;
loc_82741F80:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82741F84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274272c
	if (cr6.eq) goto loc_8274272C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82741FA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// bne cr6,0x82741fd8
	if (!cr6.eq) goto loc_82741FD8;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lwz r3,448(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82741FC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82741fd8
	if (cr6.eq) goto loc_82741FD8;
	// lwz r29,128(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// b 0x82741fdc
	goto loc_82741FDC;
loc_82741FD8:
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82741FDC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82742014
	if (cr6.eq) goto loc_82742014;
	// lwz r3,452(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8274200c
	if (cr6.eq) goto loc_8274200C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82742000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82742014
	if (cr6.eq) goto loc_82742014;
loc_8274200C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82742018
	goto loc_82742018;
loc_82742014:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82742018:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274272c
	if (!cr6.eq) goto loc_8274272C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82742048
	if (cr6.eq) goto loc_82742048;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826e94e8
	ctx.lr = 0x82742034;
	sub_826E94E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82742048
	if (!cr6.eq) goto loc_82742048;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826ea0a8
	ctx.lr = 0x82742048;
	sub_826EA0A8(ctx, base);
loc_82742048:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8274272c
	if (!cr6.gt) goto loc_8274272C;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r29,48
	r29.s64 = 48;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r21,r11,2384
	r21.s64 = r11.s64 + 2384;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// li r24,32
	r24.s64 = 32;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// li r23,16
	r23.s64 = 16;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lwz r19,12(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lvx128 v62,r0,r21
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// addi r4,r6,2352
	ctx.r4.s64 = ctx.r6.s64 + 2352;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r24
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,2256
	ctx.r3.s64 = ctx.r5.s64 + 2256;
	// lwz r10,12(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lvx128 v59,r11,r29
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r23
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v63,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v56,v58,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// vmrglw128 v54,v63,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v55,v58,v59
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v53,r10,r29
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// vand128 v52,v53,v62
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vmrglw128 v51,v57,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v50,v57,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// vmrghw128 v49,v54,v55
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r28.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v48,v61,v52
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// lfs f29,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f29.f64 = double(temp.f32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f29,224(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// sth r4,236(r1)
	PPC_STORE_U16(ctx.r1.u32 + 236, ctx.r4.u16);
	// stfs f29,228(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// vmsum4fp128 v47,v48,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v46,v48,v49
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// vmsum4fp128 v45,v48,v50
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r28,238(r1)
	PPC_STORE_U16(ctx.r1.u32 + 238, r28.u16);
	// stb r28,240(r1)
	PPC_STORE_U8(ctx.r1.u32 + 240, r28.u8);
	// sth r28,242(r1)
	PPC_STORE_U16(ctx.r1.u32 + 242, r28.u16);
	// stw r28,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r28.u32);
	// vmrghw128 v44,v47,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v43,v45,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v127,v43,v44
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82742154;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274272c
	if (cr6.eq) goto loc_8274272C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r20,r11,24064
	r20.s64 = r11.s64 + 24064;
	// addi r22,r10,24092
	r22.s64 = ctx.r10.s64 + 24092;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82742188;
	sub_823DEDD8(ctx, base);
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x8274221c
	if (cr6.eq) goto loc_8274221C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x8274221c
	if (!cr6.eq) goto loc_8274221C;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x827421BC;
	sub_823DEDD8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r6,r11,-17052
	ctx.r6.s64 = r11.s64 + -17052;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x827421DC;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827421fc
	if (cr6.eq) goto loc_827421FC;
	// lwz r11,80(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 80);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lfs f1,784(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82334da8
	ctx.lr = 0x827421F8;
	sub_82334DA8(ctx, base);
	// b 0x8274272c
	goto loc_8274272C;
loc_827421FC:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274272c
	if (cr6.eq) goto loc_8274272C;
	// lwz r11,80(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 80);
	// lwz r3,128(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lfs f1,784(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826e9738
	ctx.lr = 0x82742218;
	sub_826E9738(ctx, base);
	// b 0x8274272c
	goto loc_8274272C;
loc_8274221C:
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x825754d0
	ctx.lr = 0x82742228;
	sub_825754D0(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// lis r17,-32112
	r17.s64 = -2104492032;
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// lwz r10,-23452(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23452);
	// lwz r10,112(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x827422a0
	if (!cr6.eq) goto loc_827422A0;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x827422a0
	if (cr6.eq) goto loc_827422A0;
	// lwz r10,-2288(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + -2288);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,112(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x827422a0
	if (!cr6.eq) goto loc_827422A0;
	// lwz r10,120(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827422a0
	if (cr6.eq) goto loc_827422A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// b 0x827422ac
	goto loc_827422AC;
loc_827422A0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
loc_827422AC:
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827422C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// addi r27,r10,2528
	r27.s64 = ctx.r10.s64 + 2528;
	// lfs f12,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r11,2240
	r28.s64 = r11.s64 + 2240;
	// lfs f11,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v42,r0,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vsubfp128 v63,v127,v42
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v42.f32)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r26,r11,-31648
	r26.s64 = r11.s64 + -31648;
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r25,r10,-31664
	r25.s64 = ctx.r10.s64 + -31664;
	// lvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v41,v63,v63
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v40,v41
	simde_mm_store_ps(v40.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v41.f32))));
	// vor128 v12,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vcmpeqfp128 v11,v40,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v62,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v39,v63,v6
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v39,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// fmadds f5,f12,f9,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fadds f0,f5,f11
	f0.f64 = double(float(ctx.f5.f64 + ctx.f11.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x8274272c
	if (!cr6.gt) goto loc_8274272C;
	// lfs f13,8(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// vspltisw128 v126,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// fmr f28,f30
	f28.f64 = f30.f64;
	// lfs f13,18204(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f10,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lvx128 v38,r0,r9
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v37,v126,v38
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v37.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v38.f32)));
	// lfs f12,31308(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// lfs f27,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f27.f64 = double(temp.f32);
	// fmuls f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stvx128 v37,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fmuls f26,f6,f12
	f26.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// bne cr6,0x82742458
	if (!cr6.eq) goto loc_82742458;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v36,r30,r29
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v35,r11,r23
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f9.f64));
	// lfs f11,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f7,f11,f13,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f8.f64));
	// lfs f10,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f31,f12,f10,f7
	f31.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stvx128 v36,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f1,f31
	ctx.f1.u64 = f31.u64 ^ 0x8000000000000000;
	// lfs f6,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fsel f0,f1,f29,f30
	f0.f64 = ctx.f1.f64 >= 0.0 ? f29.f64 : f30.f64;
	// fmadds f2,f6,f13,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f3.f64));
	// fsel f13,f31,f0,f27
	ctx.f13.f64 = f31.f64 >= 0.0 ? f0.f64 : f27.f64;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v34,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v33,v34,0
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// vmulfp128 v32,v35,v33
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v33.f32)));
	// fnmadds f28,f5,f12,f2
	ctx.fpscr.disableFlushModeUnconditional();
	f28.f64 = double(float(-(ctx.f5.f64 * ctx.f12.f64 + ctx.f2.f64)));
	// stvx128 v32,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82742458:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// lfd f2,22960(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + 22960);
	// bl 0x823dc480
	ctx.lr = 0x82742468;
	sub_823DC480(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lhz r6,242(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 242);
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// lvx128 v61,r0,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r30.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v60,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// lvx128 v13,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r6.u32);
	// stfs f26,288(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lwz r5,40(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vcmpeqfp128 v11,v59,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
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
	// vmulfp128 v58,v63,v6
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827424E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f29,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f29,116(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stfs f29,120(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v127,r3,r29
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r3,r24
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v56,v57,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v55,v56,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v126.f32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// stvx128 v127,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827426d4
	if (!cr6.eq) goto loc_827426D4;
	// fneg f0,f31
	ctx.fpscr.disableFlushModeUnconditional();
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lvx128 v54,r10,r24
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f13,f0,f29,f30
	ctx.f13.f64 = f0.f64 >= 0.0 ? f29.f64 : f30.f64;
	// fsel f31,f31,f13,f27
	f31.f64 = f31.f64 >= 0.0 ? ctx.f13.f64 : f27.f64;
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f31,f12
	ctx.f11.f64 = double(float(f31.f64 * ctx.f12.f64));
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r11,r23
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r11,r24
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v49,v53
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v50,v52,v51
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrglw128 v47,v52,v51
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrglw128 v46,v49,v53
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v45,v50,v48
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrglw128 v44,v50,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v43,v47,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmsum3fp128 v42,v63,v45
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// vmsum3fp128 v41,v63,v44
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v44.f32), 0xEF));
	// vmsum3fp128 v40,v63,v43
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v43.f32), 0xEF));
	// vmrghw128 v39,v42,v40
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v38,v41,v39
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v37,v39,v38
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// stvx128 v37,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,0(r18)
	ctx.r6.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// lwz r5,28(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827425B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// fneg f10,f28
	ctx.f10.u64 = f28.u64 ^ 0x8000000000000000;
	// lvlx128 v36,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v35,v36,0
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0xFF));
	// lvx128 v34,r0,r3
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f9,f10,f29,f30
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f29.f64 : f30.f64;
	// vmulfp128 v33,v34,v35
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v35.f32)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fsel f8,f28,f9,f27
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.f64 = f28.f64 >= 0.0 ? ctx.f9.f64 : f27.f64;
	// stvx128 v33,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r18)
	ctx.r7.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// lvx128 v32,r11,r24
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r23
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r9,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 * f31.f64));
	// lfs f4,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// vmrghw128 v126,v63,v32
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrglw128 v59,v63,v32
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lfs f7,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// vmrghw128 v125,v61,v62
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// vmrglw128 v58,v61,v62
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v57,v126,v125
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// vmrghw128 v56,v59,v58
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// fmuls f2,f7,f6
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f3,f4,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f6.f64));
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f1,f5,f6
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f6.f64));
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v55,v127,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vmsum3fp128 v54,v127,v57
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vmrghw128 v124,v54,v55
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8274267C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// vmrglw128 v53,v126,v125
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// lvx128 v52,r0,r3
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// vmsum3fp128 v51,v127,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vmrghw128 v50,v51,v124
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v49,v124,v50
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v124.u32)));
	// vmulfp128 v127,v49,v52
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v52.f32)));
	// bl 0x823dedd8
	ctx.lr = 0x827426AC;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827426f0
	if (cr6.eq) goto loc_827426F0;
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x827426f0
	if (cr6.eq) goto loc_827426F0;
	// lwz r11,80(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 80);
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lfs f1,784(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82334ec0
	ctx.lr = 0x827426D0;
	sub_82334EC0(ctx, base);
	// b 0x827426f0
	goto loc_827426F0;
loc_827426D4:
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// lvlx128 v48,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// lvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v45,v46,v47
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v45,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827426F0:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-2288(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + -2288);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lhz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x8258d8b8
	ctx.lr = 0x82742704;
	sub_8258D8B8(ctx, base);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lwz r3,-2288(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + -2288);
	// lhz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x8258d938
	ctx.lr = 0x82742714;
	sub_8258D938(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274272C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274272C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// addi r12,r1,-192
	r12.s64 = ctx.r1.s64 + -192;
	// bl 0x823dd7cc
	ctx.lr = 0x8274273C;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823dba1c
	ctx.lr = 0x82742744;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82742748"))) PPC_WEAK_FUNC(sub_82742748);
PPC_FUNC_IMPL(__imp__sub_82742748) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,31072
	ctx.r10.s64 = r11.s64 + 31072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x82742770;
	sub_821B5A60(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,-6304
	ctx.r8.s64 = ctx.r9.s64 + -6304;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_827427A4"))) PPC_WEAK_FUNC(sub_827427A4);
PPC_FUNC_IMPL(__imp__sub_827427A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827427A8"))) PPC_WEAK_FUNC(sub_827427A8);
PPC_FUNC_IMPL(__imp__sub_827427A8) {
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
	// bne cr6,0x827427bc
	if (!cr6.eq) goto loc_827427BC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_827427BC:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x827427d4
	if (cr6.gt) goto loc_827427D4;
	// li r11,0
	r11.s64 = 0;
loc_827427D4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827427DC"))) PPC_WEAK_FUNC(sub_827427DC);
PPC_FUNC_IMPL(__imp__sub_827427DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827427E0"))) PPC_WEAK_FUNC(sub_827427E0);
PPC_FUNC_IMPL(__imp__sub_827427E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// b 0x82582570
	sub_82582570(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82742808"))) PPC_WEAK_FUNC(sub_82742808);
PPC_FUNC_IMPL(__imp__sub_82742808) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// bl 0x823d91f8
	ctx.lr = 0x82742810;
	// stwu r1,-2656(r1)
	ea = -2656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r5,4(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r7,32
	ctx.r7.s64 = 32;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r6,r6,2384
	ctx.r6.s64 = ctx.r6.s64 + 2384;
	// lwz r28,12(r5)
	r28.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// lis r29,-32122
	r29.s64 = -2105147392;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r10,r4,16
	ctx.r10.s64 = ctx.r4.s64 + 16;
	// addi r5,r29,2352
	ctx.r5.s64 = r29.s64 + 2352;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v59,v62,v61
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lvx128 v58,r11,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v58,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v55,r10,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v62,v61
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v56,v58,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v53,r10,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v52,r4,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v51,v59,v57
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vand128 v50,v52,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v49,v59,v57
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v48,v54,v56
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// lvx128 v46,r10,r7
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vor128 v45,v62,v50
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v50.u8)));
	// vmsum4fp128 v44,v45,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmsum4fp128 v43,v45,v48
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v48.f32), 0xFF));
	// vmsum4fp128 v42,v45,v49
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmrghw128 v41,v44,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v40,v42,v43
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v39,v40,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vsubfp128 v38,v39,v55
	simde_mm_store_ps(v38.f32, simde_mm_sub_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v55.f32)));
	// vmsum3fp128 v37,v53,v38
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v38.f32), 0xEF));
	// vmsum3fp128 v36,v46,v38
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v38.f32), 0xEF));
	// vmsum3fp128 v35,v47,v38
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v38.f32), 0xEF));
	// vmrghw128 v34,v37,v37
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v33,v35,v36
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v32,v33,v34
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// stvx128 v32,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825de400
	ctx.lr = 0x827428E8;
	sub_825DE400(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8257def0
	ctx.lr = 0x82742900;
	sub_8257DEF0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825de310
	ctx.lr = 0x82742910;
	sub_825DE310(ctx, base);
	// lbz r10,522(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 522);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82742940
	if (!cr6.eq) goto loc_82742940;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274292c
	if (cr6.eq) goto loc_8274292C;
	// lwz r3,388(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// bl 0x82130588
	ctx.lr = 0x8274292C;
	sub_82130588(ctx, base);
loc_8274292C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82130000
	ctx.lr = 0x82742934;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,2656
	ctx.r1.s64 = ctx.r1.s64 + 2656;
	// b 0x823d9248
	return;
loc_82742940:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82742950
	if (cr6.eq) goto loc_82742950;
	// lwz r3,388(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// bl 0x82130588
	ctx.lr = 0x82742950;
	sub_82130588(ctx, base);
loc_82742950:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82130000
	ctx.lr = 0x82742958;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,2656
	ctx.r1.s64 = ctx.r1.s64 + 2656;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82742964"))) PPC_WEAK_FUNC(sub_82742964);
PPC_FUNC_IMPL(__imp__sub_82742964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742968"))) PPC_WEAK_FUNC(sub_82742968);
PPC_FUNC_IMPL(__imp__sub_82742968) {
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
	// li r3,560
	ctx.r3.s64 = 560;
	// bl 0x82130528
	ctx.lr = 0x82742988;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827429a0
	if (cr6.eq) goto loc_827429A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822bc838
	ctx.lr = 0x82742998;
	sub_822BC838(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x827429a4
	goto loc_827429A4;
loc_827429A0:
	// li r31,0
	r31.s64 = 0;
loc_827429A4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827429BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_827429D8"))) PPC_WEAK_FUNC(sub_827429D8);
PPC_FUNC_IMPL(__imp__sub_827429D8) {
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
	ctx.lr = 0x827429E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130528
	ctx.lr = 0x827429F8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82742a0c
	if (cr6.eq) goto loc_82742A0C;
	// bl 0x822b9658
	ctx.lr = 0x82742A04;
	sub_822B9658(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82742a10
	goto loc_82742A10;
loc_82742A0C:
	// li r31,0
	r31.s64 = 0;
loc_82742A10:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82742A28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82742A38"))) PPC_WEAK_FUNC(sub_82742A38);
PPC_FUNC_IMPL(__imp__sub_82742A38) {
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
	// bl 0x82742968
	ctx.lr = 0x82742A58;
	sub_82742968(ctx, base);
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

__attribute__((alias("__imp__sub_82742A74"))) PPC_WEAK_FUNC(sub_82742A74);
PPC_FUNC_IMPL(__imp__sub_82742A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742A78"))) PPC_WEAK_FUNC(sub_82742A78);
PPC_FUNC_IMPL(__imp__sub_82742A78) {
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
	ctx.lr = 0x82742A80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,1712
	ctx.r3.s64 = 1712;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130528
	ctx.lr = 0x82742A98;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82742aac
	if (cr6.eq) goto loc_82742AAC;
	// bl 0x82744ae0
	ctx.lr = 0x82742AA4;
	sub_82744AE0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82742ab0
	goto loc_82742AB0;
loc_82742AAC:
	// li r31,0
	r31.s64 = 0;
loc_82742AB0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82742AC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82742AD8"))) PPC_WEAK_FUNC(sub_82742AD8);
PPC_FUNC_IMPL(__imp__sub_82742AD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,136(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82742AF4"))) PPC_WEAK_FUNC(sub_82742AF4);
PPC_FUNC_IMPL(__imp__sub_82742AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742AF8"))) PPC_WEAK_FUNC(sub_82742AF8);
PPC_FUNC_IMPL(__imp__sub_82742AF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,68(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82742B10"))) PPC_WEAK_FUNC(sub_82742B10);
PPC_FUNC_IMPL(__imp__sub_82742B10) {
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
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,10712
	ctx.r4.s64 = r11.s64 + 10712;
	// addi r3,r10,-5756
	ctx.r3.s64 = ctx.r10.s64 + -5756;
	// bl 0x82554798
	ctx.lr = 0x82742B30;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,10808
	ctx.r4.s64 = ctx.r9.s64 + 10808;
	// addi r3,r8,-5788
	ctx.r3.s64 = ctx.r8.s64 + -5788;
	// bl 0x82554798
	ctx.lr = 0x82742B44;
	sub_82554798(ctx, base);
	// lis r7,-32140
	ctx.r7.s64 = -2106327040;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,10872
	ctx.r4.s64 = ctx.r7.s64 + 10872;
	// addi r3,r6,-5824
	ctx.r3.s64 = ctx.r6.s64 + -5824;
	// bl 0x82554798
	ctx.lr = 0x82742B58;
	sub_82554798(ctx, base);
	// lis r5,-32140
	ctx.r5.s64 = -2106327040;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,11000
	ctx.r4.s64 = ctx.r5.s64 + 11000;
	// addi r3,r3,-5856
	ctx.r3.s64 = ctx.r3.s64 + -5856;
	// bl 0x82554798
	ctx.lr = 0x82742B6C;
	sub_82554798(ctx, base);
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,11000
	ctx.r4.s64 = r11.s64 + 11000;
	// addi r3,r10,-5884
	ctx.r3.s64 = ctx.r10.s64 + -5884;
	// bl 0x82554798
	ctx.lr = 0x82742B80;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,11000
	ctx.r4.s64 = ctx.r9.s64 + 11000;
	// addi r3,r8,-5916
	ctx.r3.s64 = ctx.r8.s64 + -5916;
	// bl 0x82554798
	ctx.lr = 0x82742B94;
	sub_82554798(ctx, base);
	// lis r7,-32140
	ctx.r7.s64 = -2106327040;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,10968
	ctx.r4.s64 = ctx.r7.s64 + 10968;
	// addi r3,r6,-5944
	ctx.r3.s64 = ctx.r6.s64 + -5944;
	// bl 0x82554798
	ctx.lr = 0x82742BA8;
	sub_82554798(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82742BAC;
	sub_82130000(ctx, base);
	// bl 0x822bebe0
	ctx.lr = 0x82742BB0;
	sub_822BEBE0(ctx, base);
	// bl 0x82746a58
	ctx.lr = 0x82742BB4;
	sub_82746A58(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82742BC4"))) PPC_WEAK_FUNC(sub_82742BC4);
PPC_FUNC_IMPL(__imp__sub_82742BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742BC8"))) PPC_WEAK_FUNC(sub_82742BC8);
PPC_FUNC_IMPL(__imp__sub_82742BC8) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r3,-21492(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -21492);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82742bfc
	if (cr6.eq) goto loc_82742BFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82742BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82742BFC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21492(r31)
	PPC_STORE_U32(r31.u32 + -21492, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82742C18"))) PPC_WEAK_FUNC(sub_82742C18);
PPC_FUNC_IMPL(__imp__sub_82742C18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-21492(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21492);
	// stb r10,53(r11)
	PPC_STORE_U8(r11.u32 + 53, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82742C2C"))) PPC_WEAK_FUNC(sub_82742C2C);
PPC_FUNC_IMPL(__imp__sub_82742C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742C30"))) PPC_WEAK_FUNC(sub_82742C30);
PPC_FUNC_IMPL(__imp__sub_82742C30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// addi r8,r11,64
	ctx.r8.s64 = r11.s64 + 64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// li r3,200
	ctx.r3.s64 = 200;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// stb r9,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r9.u8);
	// lbz r7,65(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 65);
	// stb r7,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r7.u8);
	// lbz r6,66(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 66);
	// stb r6,2(r4)
	PPC_STORE_U8(ctx.r4.u32 + 2, ctx.r6.u8);
	// lbz r5,67(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 67);
	// stb r5,3(r4)
	PPC_STORE_U8(ctx.r4.u32 + 3, ctx.r5.u8);
	// lbz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 60);
	// stb r10,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r10.u8);
	// lbz r9,61(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 61);
	// stb r9,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, ctx.r9.u8);
	// lbz r8,62(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 62);
	// stb r8,6(r4)
	PPC_STORE_U8(ctx.r4.u32 + 6, ctx.r8.u8);
	// lbz r7,63(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 63);
	// stb r7,7(r4)
	PPC_STORE_U8(ctx.r4.u32 + 7, ctx.r7.u8);
	// lbz r6,56(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 56);
	// stb r6,8(r4)
	PPC_STORE_U8(ctx.r4.u32 + 8, ctx.r6.u8);
	// lbz r5,57(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 57);
	// stb r5,9(r4)
	PPC_STORE_U8(ctx.r4.u32 + 9, ctx.r5.u8);
	// lbz r10,58(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 58);
	// stb r10,10(r4)
	PPC_STORE_U8(ctx.r4.u32 + 10, ctx.r10.u8);
	// lbz r9,59(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 59);
	// stb r9,11(r4)
	PPC_STORE_U8(ctx.r4.u32 + 11, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82742CA8"))) PPC_WEAK_FUNC(sub_82742CA8);
PPC_FUNC_IMPL(__imp__sub_82742CA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,200
	ctx.r3.s64 = 200;
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
	// addi r10,r11,60
	ctx.r10.s64 = r11.s64 + 60;
	// addi r10,r11,56
	ctx.r10.s64 = r11.s64 + 56;
	// stb r9,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r9.u8);
	// lbz r8,1(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r8,65(r11)
	PPC_STORE_U8(r11.u32 + 65, ctx.r8.u8);
	// lbz r7,2(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r7,66(r11)
	PPC_STORE_U8(r11.u32 + 66, ctx.r7.u8);
	// lbz r6,3(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r6,67(r11)
	PPC_STORE_U8(r11.u32 + 67, ctx.r6.u8);
	// lbz r5,4(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// stb r5,60(r11)
	PPC_STORE_U8(r11.u32 + 60, ctx.r5.u8);
	// lbz r10,5(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// stb r10,61(r11)
	PPC_STORE_U8(r11.u32 + 61, ctx.r10.u8);
	// lbz r9,6(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// stb r9,62(r11)
	PPC_STORE_U8(r11.u32 + 62, ctx.r9.u8);
	// lbz r8,7(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// stb r8,63(r11)
	PPC_STORE_U8(r11.u32 + 63, ctx.r8.u8);
	// lbz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// stb r7,56(r11)
	PPC_STORE_U8(r11.u32 + 56, ctx.r7.u8);
	// lbz r6,9(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// stb r6,57(r11)
	PPC_STORE_U8(r11.u32 + 57, ctx.r6.u8);
	// lbz r5,10(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// stb r5,58(r11)
	PPC_STORE_U8(r11.u32 + 58, ctx.r5.u8);
	// lbz r4,11(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// stb r4,59(r11)
	PPC_STORE_U8(r11.u32 + 59, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82742D20"))) PPC_WEAK_FUNC(sub_82742D20);
PPC_FUNC_IMPL(__imp__sub_82742D20) {
	PPC_FUNC_PROLOGUE();
	// b 0x8238d3f8
	sub_8238D3F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82742D24"))) PPC_WEAK_FUNC(sub_82742D24);
PPC_FUNC_IMPL(__imp__sub_82742D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742D28"))) PPC_WEAK_FUNC(sub_82742D28);
PPC_FUNC_IMPL(__imp__sub_82742D28) {
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
	ctx.lr = 0x82742D30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82742d84
	if (!cr6.gt) goto loc_82742D84;
	// addi r11,r29,20
	r11.s64 = r29.s64 + 20;
loc_82742D50:
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x82742d70
	if (!cr6.eq) goto loc_82742D70;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82742d70
	if (cr6.eq) goto loc_82742D70;
	// lbz r8,52(r28)
	ctx.r8.u64 = PPC_LOAD_U8(r28.u32 + 52);
	// stb r8,380(r10)
	PPC_STORE_U8(ctx.r10.u32 + 380, ctx.r8.u8);
loc_82742D70:
	// lwz r10,3080(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x82742d50
	if (cr6.lt) goto loc_82742D50;
loc_82742D84:
	// lbz r11,52(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82742dec
	if (cr6.eq) goto loc_82742DEC;
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82742dec
	if (!cr6.gt) goto loc_82742DEC;
	// addi r31,r29,20
	r31.s64 = r29.s64 + 20;
loc_82742DA4:
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82742dd8
	if (!cr6.eq) goto loc_82742DD8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82742dd8
	if (cr6.eq) goto loc_82742DD8;
	// lwz r10,60(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// addi r3,r11,412
	ctx.r3.s64 = r11.s64 + 412;
	// li r5,140
	ctx.r5.s64 = 140;
	// mulli r11,r10,140
	r11.s64 = ctx.r10.s64 * 140;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r4,r11,76
	ctx.r4.s64 = r11.s64 + 76;
	// bl 0x823da950
	ctx.lr = 0x82742DD8;
	sub_823DA950(ctx, base);
loc_82742DD8:
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82742da4
	if (cr6.lt) goto loc_82742DA4;
loc_82742DEC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82742DF4"))) PPC_WEAK_FUNC(sub_82742DF4);
PPC_FUNC_IMPL(__imp__sub_82742DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742DF8"))) PPC_WEAK_FUNC(sub_82742DF8);
PPC_FUNC_IMPL(__imp__sub_82742DF8) {
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
	ctx.lr = 0x82742E00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8238d410
	ctx.lr = 0x82742E0C;
	sub_8238D410(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r11,-21468
	ctx.r9.s64 = r11.s64 + -21468;
	// addi r8,r10,-5396
	ctx.r8.s64 = ctx.r10.s64 + -5396;
	// li r30,0
	r30.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r27,2
	r27.s64 = 2;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r28,r31,76
	r28.s64 = r31.s64 + 76;
	// li r29,10
	r29.s64 = 10;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stb r30,53(r31)
	PPC_STORE_U8(r31.u32 + 53, r30.u8);
	// stb r30,54(r31)
	PPC_STORE_U8(r31.u32 + 54, r30.u8);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stb r5,52(r31)
	PPC_STORE_U8(r31.u32 + 52, ctx.r5.u8);
	// stw r27,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r27.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r7.u32);
loc_82742E60:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82398fd8
	ctx.lr = 0x82742E68;
	sub_82398FD8(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,140
	r28.s64 = r28.s64 + 140;
	// bge 0x82742e60
	if (!cr0.lt) goto loc_82742E60;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// stw r30,1872(r31)
	PPC_STORE_U32(r31.u32 + 1872, r30.u32);
	// addi r10,r31,12
	ctx.r10.s64 = r31.s64 + 12;
	// addi r8,r9,-5416
	ctx.r8.s64 = ctx.r9.s64 + -5416;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwz r7,-5416(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + -5416);
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r6,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r6.u32);
	// lwz r5,8(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r5,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r5.u32);
	// lhz r4,12(r8)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + 12);
	// sth r4,24(r31)
	PPC_STORE_U16(r31.u32 + 24, ctx.r4.u16);
loc_82742EA8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82742ea8
	if (!cr6.eq) goto loc_82742EA8;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stb r27,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r27.u8);
	// li r10,200
	ctx.r10.s64 = 200;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r6,r6,-14596
	ctx.r6.s64 = ctx.r6.s64 + -14596;
	// addi r5,r5,-14960
	ctx.r5.s64 = ctx.r5.s64 + -14960;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,2832(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2832);
	// bl 0x82202c00
	ctx.lr = 0x82742EF0;
	sub_82202C00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82742EFC"))) PPC_WEAK_FUNC(sub_82742EFC);
PPC_FUNC_IMPL(__imp__sub_82742EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742F00"))) PPC_WEAK_FUNC(sub_82742F00);
PPC_FUNC_IMPL(__imp__sub_82742F00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-21492(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21492);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,52(r11)
	PPC_STORE_U8(r11.u32 + 52, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82742F24"))) PPC_WEAK_FUNC(sub_82742F24);
PPC_FUNC_IMPL(__imp__sub_82742F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82742F28"))) PPC_WEAK_FUNC(sub_82742F28);
PPC_FUNC_IMPL(__imp__sub_82742F28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	// lwz r8,64(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,5
	r11.s64 = 5;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82742f9c
	if (cr6.eq) goto loc_82742F9C;
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// bne cr6,0x82742f54
	if (!cr6.eq) goto loc_82742F54;
	// li r10,14
	ctx.r10.s64 = 14;
	// li r11,10
	r11.s64 = 10;
	// b 0x82742f8c
	goto loc_82742F8C;
loc_82742F54:
	// cmpwi cr6,r5,2
	cr6.compare<int32_t>(ctx.r5.s32, 2, xer);
	// bne cr6,0x82742f68
	if (!cr6.eq) goto loc_82742F68;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r11,8
	r11.s64 = 8;
	// b 0x82742f8c
	goto loc_82742F8C;
loc_82742F68:
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bne cr6,0x82742f7c
	if (!cr6.eq) goto loc_82742F7C;
	// li r10,6
	ctx.r10.s64 = 6;
	// li r11,7
	r11.s64 = 7;
	// b 0x82742f8c
	goto loc_82742F8C;
loc_82742F7C:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x82742f8c
	if (!cr6.eq) goto loc_82742F8C;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r11,4
	r11.s64 = 4;
loc_82742F8C:
	// lwz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bge cr6,0x82742ff8
	if (!cr6.lt) goto loc_82742FF8;
	// b 0x82742ff4
	goto loc_82742FF4;
loc_82742F9C:
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// bne cr6,0x82742fb0
	if (!cr6.eq) goto loc_82742FB0;
	// li r10,-4
	ctx.r10.s64 = -4;
	// li r11,5
	r11.s64 = 5;
	// b 0x82742fe8
	goto loc_82742FE8;
loc_82742FB0:
	// cmpwi cr6,r5,2
	cr6.compare<int32_t>(ctx.r5.s32, 2, xer);
	// bne cr6,0x82742fc4
	if (!cr6.eq) goto loc_82742FC4;
	// li r10,-6
	ctx.r10.s64 = -6;
	// li r11,4
	r11.s64 = 4;
	// b 0x82742fe8
	goto loc_82742FE8;
loc_82742FC4:
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// bne cr6,0x82742fd8
	if (!cr6.eq) goto loc_82742FD8;
	// li r10,-9
	ctx.r10.s64 = -9;
	// li r11,1
	r11.s64 = 1;
	// b 0x82742fe8
	goto loc_82742FE8;
loc_82742FD8:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x82742fe8
	if (!cr6.eq) goto loc_82742FE8;
	// li r10,-14
	ctx.r10.s64 = -14;
	// li r11,0
	r11.s64 = 0;
loc_82742FE8:
	// lwz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x82742ff8
	if (!cr6.gt) goto loc_82742FF8;
loc_82742FF4:
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
loc_82742FF8:
	// cmpwi cr6,r8,18
	cr6.compare<int32_t>(ctx.r8.s32, 18, xer);
	// blt cr6,0x8274306c
	if (cr6.lt) goto loc_8274306C;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lis r10,14563
	ctx.r10.s64 = 954400768;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// ori r6,r10,36409
	ctx.r6.u64 = ctx.r10.u64 | 36409;
	// mulhw r5,r7,r6
	ctx.r5.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32)) >> 32;
	// srawi r10,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 2;
	// addic. r9,r9,1
	xer.ca = ctx.r9.u32 > 4294967294;
	ctx.r9.s64 = ctx.r9.s64 + 1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r10,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// addi r8,r10,-18
	ctx.r8.s64 = ctx.r10.s64 + -18;
	// stw r8,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r8.u32);
	// bge 0x82743054
	if (!cr0.lt) goto loc_82743054;
	// li r11,0
	r11.s64 = 0;
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// blr 
	return;
loc_82743054:
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bgt cr6,0x827430c4
	if (cr6.gt) goto loc_827430C4;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// blr 
	return;
loc_8274306C:
	// cmpwi cr6,r8,-18
	cr6.compare<int32_t>(ctx.r8.s32, -18, xer);
	// bgt cr6,0x827430d0
	if (cr6.gt) goto loc_827430D0;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lis r10,-14564
	ctx.r10.s64 = -954466304;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// ori r6,r10,29127
	ctx.r6.u64 = ctx.r10.u64 | 29127;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// mulhw r5,r7,r6
	ctx.r5.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32)) >> 32;
	// srawi r10,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 2;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r10,r4,-18
	ctx.r10.s64 = ctx.r4.s64 * -18;
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// addi r8,r10,18
	ctx.r8.s64 = ctx.r10.s64 + 18;
	// stw r8,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r8.u32);
	// blt cr6,0x827430c4
	if (cr6.lt) goto loc_827430C4;
	// cmpwi cr6,r9,10
	cr6.compare<int32_t>(ctx.r9.s32, 10, xer);
	// li r11,10
	r11.s64 = 10;
	// bgt cr6,0x827430c4
	if (cr6.gt) goto loc_827430C4;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_827430C4:
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// blr 
	return;
loc_827430D0:
	// stw r8,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827430D8"))) PPC_WEAK_FUNC(sub_827430D8);
PPC_FUNC_IMPL(__imp__sub_827430D8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x827430E0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x82256058
	ctx.lr = 0x827430F0;
	sub_82256058(ctx, base);
	// addi r31,r3,8
	r31.s64 = ctx.r3.s64 + 8;
	// bl 0x82256058
	ctx.lr = 0x827430F8;
	sub_82256058(ctx, base);
	// bl 0x823eaef8
	ctx.lr = 0x827430FC;
	sub_823EAEF8(ctx, base);
	// rlwinm r11,r27,1,0,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	// lwz r31,32(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x82640ad8
	ctx.lr = 0x82743118;
	sub_82640AD8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82743134
	if (cr6.lt) goto loc_82743134;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_82743134:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x822a8108
	ctx.lr = 0x8274313C;
	sub_822A8108(ctx, base);
	// lbz r11,54(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 54);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827433fc
	if (cr6.eq) goto loc_827433FC;
	// addi r21,r29,-1
	r21.s64 = r29.s64 + -1;
	// cmpw cr6,r31,r21
	cr6.compare<int32_t>(r31.s32, r21.s32, xer);
	// bge cr6,0x827433fc
	if (!cr6.lt) goto loc_827433FC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r21,4
	cr6.compare<int32_t>(r21.s32, 4, xer);
	// lfs f0,-31380(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31380);
	f0.f64 = double(temp.f32);
	// blt cr6,0x82743354
	if (cr6.lt) goto loc_82743354;
	// addi r11,r27,50
	r11.s64 = r27.s64 + 50;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// addi r8,r21,-4
	ctx.r8.s64 = r21.s64 + -4;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// subfic r6,r11,-296
	xer.ca = r11.u32 <= 4294967000;
	ctx.r6.s64 = -296 - r11.s64;
	// subfic r4,r11,68
	xer.ca = r11.u32 <= 68;
	ctx.r4.s64 = 68 - r11.s64;
	// subfic r3,r11,72
	xer.ca = r11.u32 <= 72;
	ctx.r3.s64 = 72 - r11.s64;
	// subfic r31,r11,436
	xer.ca = r11.u32 <= 436;
	r31.s64 = 436 - r11.s64;
	// subfic r30,r11,440
	xer.ca = r11.u32 <= 440;
	r30.s64 = 440 - r11.s64;
	// subfic r29,r11,804
	xer.ca = r11.u32 <= 804;
	r29.s64 = 804 - r11.s64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// subfic r28,r11,808
	xer.ca = r11.u32 <= 808;
	r28.s64 = 808 - r11.s64;
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// subfic r25,r11,64
	xer.ca = r11.u32 <= 64;
	r25.s64 = 64 - r11.s64;
	// subfic r24,r11,432
	xer.ca = r11.u32 <= 432;
	r24.s64 = 432 - r11.s64;
	// subfic r23,r11,800
	xer.ca = r11.u32 <= 800;
	r23.s64 = 800 - r11.s64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// subfic r22,r11,1168
	xer.ca = r11.u32 <= 1168;
	r22.s64 = 1168 - r11.s64;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
loc_827431C0:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827431d8
	if (cr6.eq) goto loc_827431D8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x827431dc
	if (!cr6.eq) goto loc_827431DC;
loc_827431D8:
	// li r11,1
	r11.s64 = 1;
loc_827431DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82743224
	if (cr6.eq) goto loc_82743224;
	// lfsx f13,r8,r25
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r25.u32);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r6,r10
	r11.u64 = ctx.r6.u64 + ctx.r10.u64;
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfsx f10,r6,r10
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsubs f1,f0,f2
	ctx.f1.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f0,f1,f2,f0
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
loc_82743224:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8274323c
	if (cr6.eq) goto loc_8274323C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82743240
	if (!cr6.eq) goto loc_82743240;
loc_8274323C:
	// li r11,1
	r11.s64 = 1;
loc_82743240:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82743284
	if (cr6.eq) goto loc_82743284;
	// lfsx f13,r8,r24
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r24.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfsx f10,r3,r10
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfsx f7,r4,r10
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsubs f1,f0,f2
	ctx.f1.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f0,f1,f2,f0
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
loc_82743284:
	// lwz r11,368(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 368);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8274329c
	if (cr6.eq) goto loc_8274329C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x827432a0
	if (!cr6.eq) goto loc_827432A0;
loc_8274329C:
	// li r11,1
	r11.s64 = 1;
loc_827432A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827432e4
	if (cr6.eq) goto loc_827432E4;
	// lfsx f13,r8,r23
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r23.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfsx f10,r30,r10
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfsx f7,r31,r10
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsubs f1,f0,f2
	ctx.f1.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f0,f1,f2,f0
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
loc_827432E4:
	// lwz r11,736(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827432fc
	if (cr6.eq) goto loc_827432FC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82743300
	if (!cr6.eq) goto loc_82743300;
loc_827432FC:
	// li r11,1
	r11.s64 = 1;
loc_82743300:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82743344
	if (cr6.eq) goto loc_82743344;
	// lfsx f13,r8,r22
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r22.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfsx f10,r10,r28
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfsx f7,r29,r10
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsubs f1,f0,f2
	ctx.f1.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f0,f1,f2,f0
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
loc_82743344:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r8,r8,1472
	ctx.r8.s64 = ctx.r8.s64 + 1472;
	// addi r10,r10,1472
	ctx.r10.s64 = ctx.r10.s64 + 1472;
	// bne 0x827431c0
	if (!cr0.eq) goto loc_827431C0;
loc_82743354:
	// cmpw cr6,r5,r21
	cr6.compare<int32_t>(ctx.r5.s32, r21.s32, xer);
	// bge cr6,0x827433f0
	if (!cr6.lt) goto loc_827433F0;
	// addi r11,r27,50
	r11.s64 = r27.s64 + 50;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// mulli r8,r5,368
	ctx.r8.s64 = ctx.r5.s64 * 368;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subfic r8,r11,72
	xer.ca = r11.u32 <= 72;
	ctx.r8.s64 = 72 - r11.s64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// subfic r7,r11,64
	xer.ca = r11.u32 <= 64;
	ctx.r7.s64 = 64 - r11.s64;
	// subf r6,r5,r21
	ctx.r6.s64 = r21.s64 - ctx.r5.s64;
loc_82743380:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82743398
	if (cr6.eq) goto loc_82743398;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8274339c
	if (!cr6.eq) goto loc_8274339C;
loc_82743398:
	// li r11,1
	r11.s64 = 1;
loc_8274339C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827433e4
	if (cr6.eq) goto loc_827433E4;
	// lfsx f13,r10,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r8,r10
	r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfsx f10,r8,r10
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsubs f1,f0,f2
	ctx.f1.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f0,f1,f2,f0
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
loc_827433E4:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// bne 0x82743380
	if (!cr0.eq) goto loc_82743380;
loc_827433F0:
	// fsqrts f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(sqrt(f0.f64)));
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_827433FC:
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// mulli r10,r31,368
	ctx.r10.s64 = r31.s64 * 368;
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
	// lfs f11,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82743448"))) PPC_WEAK_FUNC(sub_82743448);
PPC_FUNC_IMPL(__imp__sub_82743448) {
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
	ctx.lr = 0x82743450;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// bl 0x82640ad8
	ctx.lr = 0x82743474;
	sub_82640AD8(ctx, base);
	// lwz r9,3116(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3116);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bgt cr6,0x82743484
	if (cr6.gt) goto loc_82743484;
	// li r9,1
	ctx.r9.s64 = 1;
loc_82743484:
	// rlwinm r11,r29,1,0,30
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// mullw r5,r9,r3
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r7,36(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r10,32(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mullw r9,r9,r3
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// mullw r11,r7,r3
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r3.s32);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// addi r6,r5,-1
	ctx.r6.s64 = ctx.r5.s64 + -1;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_827434D0:
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// blt cr6,0x827434e0
	if (cr6.lt) goto loc_827434E0;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
loc_827434E0:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82743520
	if (!cr6.lt) goto loc_82743520;
	// divw r10,r11,r3
	ctx.r10.s32 = r11.s32 / ctx.r3.s32;
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mullw r4,r10,r3
	ctx.r4.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// subf r10,r4,r11
	ctx.r10.s64 = r11.s64 - ctx.r4.s64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addi r4,r10,404
	ctx.r4.s64 = ctx.r10.s64 + 404;
	// andc r10,r3,r9
	ctx.r10.u64 = ctx.r3.u64 & ~ctx.r9.u64;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// twllei r3,0
	// twlgei r10,-1
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfsx f0,r9,r28
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r28.u32);
	f0.f64 = double(temp.f32);
	// fsubs f31,f31,f0
	f31.f64 = double(float(f31.f64 - f0.f64));
	// b 0x827434d0
	goto loc_827434D0;
loc_82743520:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82743524:
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// blt cr6,0x82743534
	if (cr6.lt) goto loc_82743534;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
loc_82743534:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82743574
	if (!cr6.lt) goto loc_82743574;
	// divw r10,r11,r3
	ctx.r10.s32 = r11.s32 / ctx.r3.s32;
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mullw r8,r10,r3
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// subf r10,r8,r11
	ctx.r10.s64 = r11.s64 - ctx.r8.s64;
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// addi r10,r10,404
	ctx.r10.s64 = ctx.r10.s64 + 404;
	// andc r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 & ~ctx.r4.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// twllei r3,0
	// twlgei r9,-1
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfsx f0,r8,r28
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// b 0x82743524
	goto loc_82743524;
loc_82743574:
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// bge cr6,0x82743598
	if (!cr6.lt) goto loc_82743598;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827430d8
	ctx.lr = 0x82743588;
	sub_827430D8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82743598:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827435A8"))) PPC_WEAK_FUNC(sub_827435A8);
PPC_FUNC_IMPL(__imp__sub_827435A8) {
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
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827435B0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x82640ad8
	ctx.lr = 0x827435D0;
	sub_82640AD8(ctx, base);
	// lwz r9,3116(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 3116);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bgt cr6,0x827435e4
	if (cr6.gt) goto loc_827435E4;
	// li r9,1
	ctx.r9.s64 = 1;
loc_827435E4:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r28,r9,r10
	r28.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add. r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne 0x82743668
	if (!cr0.eq) goto loc_82743668;
	// li r11,192
	r11.s64 = 192;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x82743624;
	sub_822A8108(ctx, base);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82743668:
	// li r8,192
	ctx.r8.s64 = 192;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r5,-1
	ctx.r6.s64 = ctx.r5.s64 + -1;
	// li r11,0
	r11.s64 = 0;
	// addi r4,r28,-1
	ctx.r4.s64 = r28.s64 + -1;
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,64(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f9,72(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f10
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fsubs f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 - f0.f64));
	// lfs f6,68(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fmadds f4,f7,f7,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f8.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fsqrts f31,f3
	f31.f64 = double(float(sqrt(ctx.f3.f64)));
loc_827436BC:
	// cmpw cr6,r6,r4
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, xer);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// blt cr6,0x827436cc
	if (cr6.lt) goto loc_827436CC;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
loc_827436CC:
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bge cr6,0x8274370c
	if (!cr6.lt) goto loc_8274370C;
	// divw r7,r11,r10
	ctx.r7.s32 = r11.s32 / ctx.r10.s32;
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mullw r7,r7,r10
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// subf r7,r7,r11
	ctx.r7.s64 = r11.s64 - ctx.r7.s64;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r7,r7,404
	ctx.r7.s64 = ctx.r7.s64 + 404;
	// andc r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 & ~ctx.r8.u64;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// twllei r10,0
	// twlgei r8,-1
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfsx f0,r7,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r27.u32);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// b 0x827436bc
	goto loc_827436BC;
loc_8274370C:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82743784
	if (!cr6.gt) goto loc_82743784;
	// cmpw cr6,r5,r28
	cr6.compare<int32_t>(ctx.r5.s32, r28.s32, xer);
	// bge cr6,0x82743784
	if (!cr6.lt) goto loc_82743784;
	// divw r8,r6,r10
	ctx.r8.s32 = ctx.r6.s32 / ctx.r10.s32;
	// rotlwi r11,r6,1
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// subf r4,r7,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r7.s64;
	// twllei r10,0
	// andc r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r5.u64;
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// twlgei r10,-1
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// bl 0x822a8108
	ctx.lr = 0x82743748;
	sub_822A8108(ctx, base);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fadds f31,f2,f31
	f31.f64 = double(float(ctx.f2.f64 + f31.f64));
loc_82743784:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82743794"))) PPC_WEAK_FUNC(sub_82743794);
PPC_FUNC_IMPL(__imp__sub_82743794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82743798"))) PPC_WEAK_FUNC(sub_82743798);
PPC_FUNC_IMPL(__imp__sub_82743798) {
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
	ctx.lr = 0x827437A0;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82640ad8
	ctx.lr = 0x827437C0;
	sub_82640AD8(ctx, base);
	// lwz r10,3116(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 3116);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bgt cr6,0x827437d0
	if (cr6.gt) goto loc_827437D0;
	// li r10,1
	ctx.r10.s64 = 1;
loc_827437D0:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r27,r10,r3
	r27.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r4,r27,-1
	ctx.r4.s64 = r27.s64 + -1;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r9,36(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lwz r28,32(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// mullw r11,r9,r3
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// add r30,r11,r28
	r30.u64 = r11.u64 + r28.u64;
	// subf r8,r30,r4
	ctx.r8.s64 = ctx.r4.s64 - r30.s64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// blt cr6,0x827438f0
	if (cr6.lt) goto loc_827438F0;
	// addi r5,r4,-3
	ctx.r5.s64 = ctx.r4.s64 + -3;
	// addi r10,r30,2
	ctx.r10.s64 = r30.s64 + 2;
loc_82743818:
	// divw r9,r11,r3
	ctx.r9.s32 = r11.s32 / ctx.r3.s32;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// mullw r6,r9,r3
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// subf r9,r6,r11
	ctx.r9.s64 = r11.s64 - ctx.r6.s64;
	// divw r8,r7,r3
	ctx.r8.s32 = ctx.r7.s32 / ctx.r3.s32;
	// addi r6,r9,404
	ctx.r6.s64 = ctx.r9.s64 + 404;
	// mullw r9,r8,r3
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r3.s32);
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r9,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r9.s64;
	// divw r6,r10,r3
	ctx.r6.s32 = ctx.r10.s32 / ctx.r3.s32;
	// addi r9,r9,404
	ctx.r9.s64 = ctx.r9.s64 + 404;
	// mullw r6,r6,r3
	ctx.r6.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r3.s32);
	// lfsx f0,r8,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r6,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r6.s64;
	// addi r25,r10,1
	r25.s64 = ctx.r10.s64 + 1;
	// addi r6,r9,404
	ctx.r6.s64 = ctx.r9.s64 + 404;
	// divw r9,r25,r3
	ctx.r9.s32 = r25.s32 / ctx.r3.s32;
	// lfsx f12,r8,r31
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// mullw r6,r9,r3
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// lfsx f10,r8,r31
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	ctx.f10.f64 = double(temp.f32);
	// subf r9,r6,r25
	ctx.r9.s64 = r25.s64 - ctx.r6.s64;
	// fadds f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f10.f64));
	// rotlwi r6,r11,1
	ctx.r6.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r24,r9,404
	r24.s64 = ctx.r9.s64 + 404;
	// rotlwi r8,r10,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// rotlwi r9,r25,1
	ctx.r9.u64 = __builtin_rotateleft32(r25.u32, 1);
	// rlwinm r25,r24,2,0,29
	r25.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r6,r3,r6
	ctx.r6.u64 = ctx.r3.u64 & ~ctx.r6.u64;
	// lfsx f8,r25,r31
	temp.u32 = PPC_LOAD_U32(r25.u32 + r31.u32);
	ctx.f8.f64 = double(temp.f32);
	// andc r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 & ~ctx.r7.u64;
	// fadds f31,f9,f8
	f31.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// andc r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 & ~ctx.r8.u64;
	// andc r9,r3,r9
	ctx.r9.u64 = ctx.r3.u64 & ~ctx.r9.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// twllei r3,0
	// twllei r3,0
	// twllei r3,0
	// twllei r3,0
	// twlgei r6,-1
	// twlgei r7,-1
	// twlgei r8,-1
	// twlgei r9,-1
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// blt cr6,0x82743818
	if (cr6.lt) goto loc_82743818;
loc_827438F0:
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bge cr6,0x82743934
	if (!cr6.lt) goto loc_82743934;
loc_827438F8:
	// divw r10,r11,r3
	ctx.r10.s32 = r11.s32 / ctx.r3.s32;
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mullw r8,r10,r3
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// subf r10,r8,r11
	ctx.r10.s64 = r11.s64 - ctx.r8.s64;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// addi r6,r10,404
	ctx.r6.s64 = ctx.r10.s64 + 404;
	// andc r5,r3,r7
	ctx.r5.u64 = ctx.r3.u64 & ~ctx.r7.u64;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// twllei r3,0
	// twlgei r5,-1
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// lfsx f0,r10,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// blt cr6,0x827438f8
	if (cr6.lt) goto loc_827438F8;
loc_82743934:
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// bge cr6,0x827439a0
	if (!cr6.lt) goto loc_827439A0;
	// cmpw cr6,r28,r3
	cr6.compare<int32_t>(r28.s32, ctx.r3.s32, xer);
	// bge cr6,0x827439a0
	if (!cr6.lt) goto loc_827439A0;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// mulli r11,r28,368
	r11.s64 = r28.s64 * 368;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x822a8108
	ctx.lr = 0x82743958;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fadds f1,f2,f31
	ctx.f1.f64 = double(float(ctx.f2.f64 + f31.f64));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_827439A0:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_827439B0"))) PPC_WEAK_FUNC(sub_827439B0);
PPC_FUNC_IMPL(__imp__sub_827439B0) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-5396
	ctx.r10.s64 = r11.s64 + -5396;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8238d010
	ctx.lr = 0x827439DC;
	sub_8238D010(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827439f4
	if (cr6.eq) goto loc_827439F4;
	// bl 0x82130588
	ctx.lr = 0x827439F0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827439F4:
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

__attribute__((alias("__imp__sub_82743A0C"))) PPC_WEAK_FUNC(sub_82743A0C);
PPC_FUNC_IMPL(__imp__sub_82743A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82743A10"))) PPC_WEAK_FUNC(sub_82743A10);
PPC_FUNC_IMPL(__imp__sub_82743A10) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82743A18;
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r24,r11,30576
	r24.s64 = r11.s64 + 30576;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r10,-5336
	ctx.r4.s64 = ctx.r10.s64 + -5336;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821ca540
	ctx.lr = 0x82743A38;
	sub_821CA540(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82398fd8
	ctx.lr = 0x82743A40;
	sub_82398FD8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r25,76
	r30.s64 = r25.s64 + 76;
	// lis r27,-32115
	r27.s64 = -2104688640;
	// lis r26,-32125
	r26.s64 = -2105344000;
	// addi r29,r10,5276
	r29.s64 = ctx.r10.s64 + 5276;
	// addi r28,r11,-5356
	r28.s64 = r11.s64 + -5356;
loc_82743A60:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82137a08
	ctx.lr = 0x82743A74;
	sub_82137A08(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r6,-12044(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -12044);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lwz r3,2828(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 2828);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// bl 0x821c04b0
	ctx.lr = 0x82743A90;
	sub_821C04B0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,140
	r30.s64 = r30.s64 + 140;
	// cmpwi cr6,r31,10
	cr6.compare<int32_t>(r31.s32, 10, xer);
	// ble cr6,0x82743a60
	if (!cr6.gt) goto loc_82743A60;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r10,r25,124
	ctx.r10.s64 = r25.s64 + 124;
	// addi r11,r25,192
	r11.s64 = r25.s64 + 192;
	// li r9,11
	ctx.r9.s64 = 11;
	// lfs f0,3732(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,-1684(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -1684);
	ctx.f13.f64 = double(temp.f32);
loc_82743ABC:
	// lfs f12,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f9,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f10,8(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// stfs f8,0(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f7,16(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// addi r10,r10,140
	ctx.r10.s64 = ctx.r10.s64 + 140;
	// lfs f5,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// lfs f6,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,-4(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stfs f2,0(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f3,4(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f6,8(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f5,12(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f4,16(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// addi r11,r11,140
	r11.s64 = r11.s64 + 140;
	// bne 0x82743abc
	if (!cr0.eq) goto loc_82743ABC;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82743B28;
	sub_821C9A90(ctx, base);
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82743B30"))) PPC_WEAK_FUNC(sub_82743B30);
PPC_FUNC_IMPL(__imp__sub_82743B30) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82743B38;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r3.u32);
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// bl 0x82256058
	ctx.lr = 0x82743B4C;
	sub_82256058(ctx, base);
	// addi r27,r3,8
	r27.s64 = ctx.r3.s64 + 8;
	// bl 0x82256058
	ctx.lr = 0x82743B54;
	sub_82256058(ctx, base);
	// bl 0x823eaef8
	ctx.lr = 0x82743B58;
	sub_823EAEF8(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,3080(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 3080);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// li r29,-2
	r29.s64 = -2;
	// li r31,0
	r31.s64 = 0;
	// lwz r25,-21492(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + -21492);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82743c20
	if (!cr6.gt) goto loc_82743C20;
	// addi r30,r27,8
	r30.s64 = r27.s64 + 8;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_82743B84:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82743bac
	if (cr6.eq) goto loc_82743BAC;
	// lwz r3,-10020(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10020);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x826bcb70
	ctx.lr = 0x82743B9C;
	sub_826BCB70(ctx, base);
	// lwz r11,3100(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bne cr6,0x82743bc4
	if (!cr6.eq) goto loc_82743BC4;
loc_82743BAC:
	// lwz r11,3080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3080);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82743b84
	if (cr6.lt) goto loc_82743B84;
	// b 0x82743c20
	goto loc_82743C20;
loc_82743BC4:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// lwz r31,8(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8238ea78
	ctx.lr = 0x82743BE0;
	sub_8238EA78(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82743BF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,3100(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// bl 0x8238ea78
	ctx.lr = 0x82743C04;
	sub_8238EA78(ctx, base);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r7,-5272
	ctx.r3.s64 = ctx.r7.s64 + -5272;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82743C1C;
	sub_82130000(ctx, base);
	// li r26,1
	r26.s64 = 1;
loc_82743C20:
	// clrlwi r31,r26,24
	r31.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82743c44
	if (!cr6.eq) goto loc_82743C44;
	// lwz r3,3100(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// bl 0x8238ea78
	ctx.lr = 0x82743C34;
	sub_8238EA78(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-5320
	ctx.r3.s64 = r11.s64 + -5320;
	// bl 0x82130000
	ctx.lr = 0x82743C44;
	sub_82130000(ctx, base);
loc_82743C44:
	// lwz r11,3100(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x82743c78
	if (cr6.gt) goto loc_82743C78;
	// lwz r11,56(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 56);
loc_82743C54:
	// lwz r10,68(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 68);
	// subf. r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x82743c68
	if (!cr0.lt) goto loc_82743C68;
	// li r11,0
	r11.s64 = 0;
	// b 0x82743ca4
	goto loc_82743CA4;
loc_82743C68:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// ble cr6,0x82743ca4
	if (!cr6.gt) goto loc_82743CA4;
	// li r11,10
	r11.s64 = 10;
	// b 0x82743ca4
	goto loc_82743CA4;
loc_82743C78:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82743ca0
	if (cr6.eq) goto loc_82743CA0;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// lwz r11,56(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// bge cr6,0x82743c54
	if (!cr6.lt) goto loc_82743C54;
	// lwz r10,72(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 72);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x82743c68
	if (!cr0.lt) goto loc_82743C68;
	// li r11,0
	r11.s64 = 0;
	// b 0x82743ca4
	goto loc_82743CA4;
loc_82743CA0:
	// lwz r11,56(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 56);
loc_82743CA4:
	// stw r11,60(r25)
	PPC_STORE_U32(r25.u32 + 60, r11.u32);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r4,r1,196
	ctx.r4.s64 = ctx.r1.s64 + 196;
	// addi r3,r11,-21488
	ctx.r3.s64 = r11.s64 + -21488;
	// bl 0x821c0750
	ctx.lr = 0x82743CB8;
	sub_821C0750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82743ce8
	if (cr6.eq) goto loc_82743CE8;
	// lwz r11,196(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82743cd8
	if (!cr6.lt) goto loc_82743CD8;
	// li r11,0
	r11.s64 = 0;
	// b 0x82743ce4
	goto loc_82743CE4;
loc_82743CD8:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// ble cr6,0x82743ce4
	if (!cr6.gt) goto loc_82743CE4;
	// li r11,10
	r11.s64 = 10;
loc_82743CE4:
	// stw r11,60(r25)
	PPC_STORE_U32(r25.u32 + 60, r11.u32);
loc_82743CE8:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// beq cr6,0x82743d08
	if (cr6.eq) goto loc_82743D08;
	// lwz r10,2616(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2616);
	// stw r10,60(r25)
	PPC_STORE_U32(r25.u32 + 60, ctx.r10.u32);
	// b 0x82743d10
	goto loc_82743D10;
loc_82743D08:
	// lwz r10,60(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 60);
	// stw r10,2616(r11)
	PPC_STORE_U32(r11.u32 + 2616, ctx.r10.u32);
loc_82743D10:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82742d28
	ctx.lr = 0x82743D1C;
	sub_82742D28(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82640ad8
	ctx.lr = 0x82743D24;
	sub_82640AD8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addic. r11,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	r11.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r3,1872(r25)
	PPC_STORE_U32(r25.u32 + 1872, ctx.r3.u32);
	// lfs f13,31020(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31020);
	ctx.f13.f64 = double(temp.f32);
	// ble 0x82743da8
	if (!cr0.gt) goto loc_82743DA8;
	// clrlwi r7,r22,24
	ctx.r7.u64 = r22.u32 & 0xFF;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r25,1616
	ctx.r8.s64 = r25.s64 + 1616;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_82743D48:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82743d58
	if (cr6.eq) goto loc_82743D58;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
	// b 0x82743d94
	goto loc_82743D94;
loc_82743D58:
	// lwz r11,4(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,68(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f12,436(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 436);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f10,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,440(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 440);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,432(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 432);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f0,f2
	f0.f64 = double(float(sqrt(ctx.f2.f64)));
loc_82743D94:
	// stfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// bne 0x82743d48
	if (!cr0.eq) goto loc_82743D48;
loc_82743DA8:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82743e14
	if (!cr6.gt) goto loc_82743E14;
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82743dc4
	if (cr6.eq) goto loc_82743DC4;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
	// b 0x82743e08
	goto loc_82743E08;
loc_82743DC4:
	// lwz r11,4(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// mulli r10,r3,368
	ctx.r10.s64 = ctx.r3.s64 * 368;
	// lfs f0,68(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,-304
	ctx.r10.s64 = r11.s64 + -304;
	// lfs f11,-300(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -300);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,-296(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -296);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,-304(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -304);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f0,f3
	f0.f64 = double(float(sqrt(ctx.f3.f64)));
loc_82743E08:
	// addi r11,r3,403
	r11.s64 = ctx.r3.s64 + 403;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r10,r25
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r25.u32, temp.u32);
loc_82743E14:
	// li r11,1
	r11.s64 = 1;
	// stb r22,54(r25)
	PPC_STORE_U8(r25.u32 + 54, r22.u8);
	// stb r11,53(r25)
	PPC_STORE_U8(r25.u32 + 53, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82743E28"))) PPC_WEAK_FUNC(sub_82743E28);
PPC_FUNC_IMPL(__imp__sub_82743E28) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82743E30;
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f29.u64);
	// stfd f30,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lbz r11,53(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 53);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274408c
	if (cr6.eq) goto loc_8274408C;
	// bl 0x82256058
	ctx.lr = 0x82743E54;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274408c
	if (cr6.eq) goto loc_8274408C;
	// bl 0x82256058
	ctx.lr = 0x82743E60;
	sub_82256058(ctx, base);
	// addi r28,r3,8
	r28.s64 = ctx.r3.s64 + 8;
	// bl 0x82256058
	ctx.lr = 0x82743E68;
	sub_82256058(ctx, base);
	// bl 0x823eaef8
	ctx.lr = 0x82743E6C;
	sub_823EAEF8(ctx, base);
	// lbz r11,52(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 52);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274408c
	if (cr6.eq) goto loc_8274408C;
	// lwz r6,3080(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// li r26,-1
	r26.s64 = -1;
	// li r22,0
	r22.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x8274408c
	if (!cr6.gt) goto loc_8274408C;
	// li r9,-192
	ctx.r9.s64 = -192;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r28,8
	r11.s64 = r28.s64 + 8;
	// subfic r7,r28,-8
	xer.ca = r28.u32 <= 4294967288;
	ctx.r7.s64 = -8 - r28.s64;
loc_82743EA4:
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r5,2
	cr6.compare<int32_t>(ctx.r5.s32, 2, xer);
	// beq cr6,0x82743ee4
	if (cr6.eq) goto loc_82743EE4;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// beq cr6,0x82743edc
	if (cr6.eq) goto loc_82743EDC;
	// add r5,r9,r28
	ctx.r5.u64 = ctx.r9.u64 + r28.u64;
	// lwz r4,164(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// lwz r3,172(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 172);
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// bge cr6,0x82743ee4
	if (!cr6.lt) goto loc_82743EE4;
loc_82743EDC:
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// add r9,r7,r11
	ctx.r9.u64 = ctx.r7.u64 + r11.u64;
loc_82743EE4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x82743ea4
	if (cr6.lt) goto loc_82743EA4;
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// beq cr6,0x8274408c
	if (cr6.eq) goto loc_8274408C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827430d8
	ctx.lr = 0x82743F08;
	sub_827430D8(ctx, base);
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8274408c
	if (!cr6.gt) goto loc_8274408C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r31,r28,20
	r31.s64 = r28.s64 + 20;
	// lfs f30,-31380(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31380);
	f30.f64 = double(temp.f32);
loc_82743F28:
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// addi r25,r31,152
	r25.s64 = r31.s64 + 152;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82744078
	if (!cr6.eq) goto loc_82744078;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82744078
	if (cr6.eq) goto loc_82744078;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82743448
	ctx.lr = 0x82743F60;
	sub_82743448(ctx, base);
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f1.f64;
	// add r9,r26,r11
	ctx.r9.u64 = r26.u64 + r11.u64;
	// rlwinm r11,r9,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// add r8,r11,r28
	ctx.r8.u64 = r11.u64 + r28.u64;
	// stfs f1,388(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 388, temp.u32);
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r6,172(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 172);
	// subf. r11,r6,r7
	r11.s64 = ctx.r7.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82743fa4
	if (!cr0.gt) goto loc_82743FA4;
	// addi r11,r11,129
	r11.s64 = r11.s64 + 129;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r9,r10
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f1
	f0.f64 = double(float(f0.f64 + ctx.f1.f64));
	// b 0x82743fc0
	goto loc_82743FC0;
loc_82743FA4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82743fc0
	if (!cr6.lt) goto loc_82743FC0;
	// subfic r11,r11,121
	xer.ca = r11.u32 <= 121;
	r11.s64 = 121 - r11.s64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// fsubs f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 - f0.f64));
loc_82743FC0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stfs f0,384(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 384, temp.u32);
	// bl 0x827435a8
	ctx.lr = 0x82743FDC;
	sub_827435A8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stfs f1,392(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 392, temp.u32);
	// bl 0x82743798
	ctx.lr = 0x82743FF8;
	sub_82743798(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = f30.f64;
	// stfs f1,396(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 396, temp.u32);
	// ble cr6,0x82744070
	if (!cr6.gt) goto loc_82744070;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// mr r30,r22
	r30.u64 = r22.u64;
loc_82744014:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822a8108
	ctx.lr = 0x8274401C;
	sub_822A8108(ctx, base);
	// addi r21,r3,48
	r21.s64 = ctx.r3.s64 + 48;
	// lwz r3,-164(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -164);
	// bl 0x822a8108
	ctx.lr = 0x82744028;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 4);
	f0.f64 = double(temp.f32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lfs f13,8(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lfs f12,0(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsubs f2,f31,f3
	ctx.f2.f64 = double(float(f31.f64 - ctx.f3.f64));
	// fsel f31,f2,f3,f31
	f31.f64 = ctx.f2.f64 >= 0.0 ? ctx.f3.f64 : f31.f64;
	// bne 0x82744014
	if (!cr0.eq) goto loc_82744014;
loc_82744070:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f31,400(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 400, temp.u32);
loc_82744078:
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82743f28
	if (cr6.lt) goto loc_82743F28;
loc_8274408C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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

__attribute__((alias("__imp__sub_827440A0"))) PPC_WEAK_FUNC(sub_827440A0);
PPC_FUNC_IMPL(__imp__sub_827440A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// clrlwi r5,r10,24
	ctx.r5.u64 = ctx.r10.u32 & 0xFF;
	// b 0x82743b30
	sub_82743B30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827440D8"))) PPC_WEAK_FUNC(sub_827440D8);
PPC_FUNC_IMPL(__imp__sub_827440D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21492(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21492);
	// b 0x82743a10
	sub_82743A10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827440E4"))) PPC_WEAK_FUNC(sub_827440E4);
PPC_FUNC_IMPL(__imp__sub_827440E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827440E8"))) PPC_WEAK_FUNC(sub_827440E8);
PPC_FUNC_IMPL(__imp__sub_827440E8) {
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
	// li r3,1876
	ctx.r3.s64 = 1876;
	// bl 0x82130528
	ctx.lr = 0x827440FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274410c
	if (cr6.eq) goto loc_8274410C;
	// bl 0x82742df8
	ctx.lr = 0x82744108;
	sub_82742DF8(ctx, base);
	// b 0x82744110
	goto loc_82744110;
loc_8274410C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82744110:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r11,r11,-21492
	r11.s64 = r11.s64 + -21492;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// bl 0x82743a10
	ctx.lr = 0x82744120;
	sub_82743A10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82744130"))) PPC_WEAK_FUNC(sub_82744130);
PPC_FUNC_IMPL(__imp__sub_82744130) {
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
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,16544
	ctx.r4.s64 = r11.s64 + 16544;
	// addi r3,r10,-5060
	ctx.r3.s64 = ctx.r10.s64 + -5060;
	// bl 0x82554798
	ctx.lr = 0x82744150;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,11288
	ctx.r4.s64 = ctx.r9.s64 + 11288;
	// addi r3,r8,-5088
	ctx.r3.s64 = ctx.r8.s64 + -5088;
	// bl 0x82554798
	ctx.lr = 0x82744164;
	sub_82554798(ctx, base);
	// lis r7,-32140
	ctx.r7.s64 = -2106327040;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,12032
	ctx.r4.s64 = ctx.r7.s64 + 12032;
	// addi r3,r6,-5124
	ctx.r3.s64 = ctx.r6.s64 + -5124;
	// bl 0x82554798
	ctx.lr = 0x82744178;
	sub_82554798(ctx, base);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,0
	ctx.r4.s64 = ctx.r5.s64 + 0;
	// addi r3,r3,-5152
	ctx.r3.s64 = ctx.r3.s64 + -5152;
	// bl 0x82554798
	ctx.lr = 0x8274418C;
	sub_82554798(ctx, base);
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,16600
	ctx.r4.s64 = r11.s64 + 16600;
	// addi r3,r10,-5180
	ctx.r3.s64 = ctx.r10.s64 + -5180;
	// bl 0x82554798
	ctx.lr = 0x827441A0;
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

__attribute__((alias("__imp__sub_827441B0"))) PPC_WEAK_FUNC(sub_827441B0);
PPC_FUNC_IMPL(__imp__sub_827441B0) {
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
	// bl 0x82350510
	ctx.lr = 0x827441C8;
	sub_82350510(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-4704
	ctx.r10.s64 = r11.s64 + -4704;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_827441EC"))) PPC_WEAK_FUNC(sub_827441EC);
PPC_FUNC_IMPL(__imp__sub_827441EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827441F0"))) PPC_WEAK_FUNC(sub_827441F0);
PPC_FUNC_IMPL(__imp__sub_827441F0) {
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
	// bl 0x823eaef8
	ctx.lr = 0x8274420C;
	sub_823EAEF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,8032
	ctx.r3.s64 = 8032;
	// bl 0x82130528
	ctx.lr = 0x82744218;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274426c
	if (cr6.eq) goto loc_8274426C;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8235af90
	ctx.lr = 0x82744230;
	sub_8235AF90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// bne cr6,0x82744240
	if (!cr6.eq) goto loc_82744240;
loc_8274423C:
	// li r11,0
	r11.s64 = 0;
loc_82744240:
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// bl 0x82357b80
	ctx.lr = 0x8274424C;
	sub_82357B80(ctx, base);
	// li r3,2176
	ctx.r3.s64 = 2176;
	// bl 0x82130528
	ctx.lr = 0x82744254;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82744274
	if (cr6.eq) goto loc_82744274;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8233d908
	ctx.lr = 0x82744264;
	sub_8233D908(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// b 0x8274427c
	goto loc_8274427C;
loc_8274426C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8274423c
	goto loc_8274423C;
loc_82744274:
	// li r11,0
	r11.s64 = 0;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
loc_8274427C:
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

__attribute__((alias("__imp__sub_82744294"))) PPC_WEAK_FUNC(sub_82744294);
PPC_FUNC_IMPL(__imp__sub_82744294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82744298"))) PPC_WEAK_FUNC(sub_82744298);
PPC_FUNC_IMPL(__imp__sub_82744298) {
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
	// bl 0x823eaef8
	ctx.lr = 0x827442AC;
	sub_823EAEF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,172
	ctx.r3.s64 = 172;
	// bl 0x82130528
	ctx.lr = 0x827442B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827442e0
	if (cr6.eq) goto loc_827442E0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822b9530
	ctx.lr = 0x827442C8;
	sub_822B9530(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_827442E0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_827442FC"))) PPC_WEAK_FUNC(sub_827442FC);
PPC_FUNC_IMPL(__imp__sub_827442FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82744300"))) PPC_WEAK_FUNC(sub_82744300);
PPC_FUNC_IMPL(__imp__sub_82744300) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82365298
	sub_82365298(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82744308"))) PPC_WEAK_FUNC(sub_82744308);
PPC_FUNC_IMPL(__imp__sub_82744308) {
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
	// bl 0x82350570
	ctx.lr = 0x82744328;
	sub_82350570(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82744340
	if (cr6.eq) goto loc_82744340;
	// bl 0x82130588
	ctx.lr = 0x8274433C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82744340:
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

__attribute__((alias("__imp__sub_82744358"))) PPC_WEAK_FUNC(sub_82744358);
PPC_FUNC_IMPL(__imp__sub_82744358) {
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
	ctx.lr = 0x82744360;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8274436C;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r11,-16
	r28.s64 = r11.s64 + -16;
	// bne cr6,0x82744384
	if (!cr6.eq) goto loc_82744384;
	// li r28,0
	r28.s64 = 0;
loc_82744384:
	// li r3,832
	ctx.r3.s64 = 832;
	// bl 0x82130528
	ctx.lr = 0x8274438C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827443a0
	if (cr6.eq) goto loc_827443A0;
	// bl 0x8232c238
	ctx.lr = 0x82744398;
	sub_8232C238(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x827443a4
	goto loc_827443A4;
loc_827443A0:
	// li r31,0
	r31.s64 = 0;
loc_827443A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,92(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// bl 0x8221cfe8
	ctx.lr = 0x827443B0;
	sub_8221CFE8(ctx, base);
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// stw r31,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x82360f90
	ctx.lr = 0x827443C8;
	sub_82360F90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,16(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// lwz r5,28(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// bl 0x8232ceb0
	ctx.lr = 0x827443E4;
	sub_8232CEB0(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8232cf88
	ctx.lr = 0x827443F4;
	sub_8232CF88(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8232cff0
	ctx.lr = 0x82744404;
	sub_8232CFF0(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8255a4e8
	ctx.lr = 0x82744414;
	sub_8255A4E8(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8255a490
	ctx.lr = 0x82744424;
	sub_8255A490(ctx, base);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lis r27,-32115
	r27.s64 = -2104688640;
	// lwz r11,76(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82744440
	if (!cr6.eq) goto loc_82744440;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82744450
	goto loc_82744450;
loc_82744440:
	// lwz r10,-12120(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -12120);
	// mulli r11,r11,104
	r11.s64 = r11.s64 * 104;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823964a8
	ctx.lr = 0x82744450;
	sub_823964A8(ctx, base);
loc_82744450:
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subfic r7,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// lbzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// cntlzw r10,r6
	ctx.r10.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r11,r5,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r8,r11,264
	ctx.r8.s64 = r11.s64 + 264;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r28
	ctx.r5.u64 = r11.u64 + r28.u64;
	// bl 0x8232d068
	ctx.lr = 0x82744498;
	sub_8232D068(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8255a710
	ctx.lr = 0x827444A8;
	sub_8255A710(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8232d408
	ctx.lr = 0x827444B8;
	sub_8232D408(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8232d460
	ctx.lr = 0x827444C8;
	sub_8232D460(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8232d8c8
	ctx.lr = 0x827444D0;
	sub_8232D8C8(ctx, base);
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x827444D8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827444ec
	if (cr6.eq) goto loc_827444EC;
	// bl 0x82345540
	ctx.lr = 0x827444E4;
	sub_82345540(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x827444f0
	goto loc_827444F0;
loc_827444EC:
	// li r28,0
	r28.s64 = 0;
loc_827444F0:
	// lwz r11,92(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r6,196(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// bl 0x823455a8
	ctx.lr = 0x82744508;
	sub_823455A8(ctx, base);
	// stw r28,664(r31)
	PPC_STORE_U32(r31.u32 + 664, r28.u32);
	// li r28,0
	r28.s64 = 0;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r11,76(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82744528
	if (!cr6.eq) goto loc_82744528;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82744538
	goto loc_82744538;
loc_82744528:
	// lwz r10,-12120(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -12120);
	// mulli r11,r11,104
	r11.s64 = r11.s64 * 104;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823960f8
	ctx.lr = 0x82744538;
	sub_823960F8(ctx, base);
loc_82744538:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274457c
	if (!cr6.eq) goto loc_8274457C;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x8274454C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82744560
	if (cr6.eq) goto loc_82744560;
	// bl 0x82345cc8
	ctx.lr = 0x82744558;
	sub_82345CC8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x82744564
	goto loc_82744564;
loc_82744560:
	// li r28,0
	r28.s64 = 0;
loc_82744564:
	// lwz r11,92(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r6,200(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// bl 0x82345da0
	ctx.lr = 0x8274457C;
	sub_82345DA0(ctx, base);
loc_8274457C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,668(r31)
	PPC_STORE_U32(r31.u32 + 668, r28.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82744594;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827445A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,2256
	ctx.r4.s64 = ctx.r7.s64 + 2256;
	// bl 0x82558290
	ctx.lr = 0x827445B8;
	sub_82558290(ctx, base);
	// li r30,-16385
	r30.s64 = -16385;
	// li r6,6
	ctx.r6.s64 = 6;
	// stw r30,376(r31)
	PPC_STORE_U32(r31.u32 + 376, r30.u32);
	// stb r6,384(r31)
	PPC_STORE_U8(r31.u32 + 384, ctx.r6.u8);
	// lwz r5,28(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwz r31,4(r5)
	r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827445fc
	if (cr6.eq) goto loc_827445FC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8258e660
	ctx.lr = 0x827445E8;
	sub_8258E660(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8258e620
	ctx.lr = 0x827445F8;
	sub_8258E620(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
loc_827445FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82744604"))) PPC_WEAK_FUNC(sub_82744604);
PPC_FUNC_IMPL(__imp__sub_82744604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82744608"))) PPC_WEAK_FUNC(sub_82744608);
PPC_FUNC_IMPL(__imp__sub_82744608) {
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
	ctx.lr = 0x82744610;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8274461C;
	sub_823EAEF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x82744628;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274463c
	if (cr6.eq) goto loc_8274463C;
	// bl 0x823505e0
	ctx.lr = 0x82744634;
	sub_823505E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82744640
	goto loc_82744640;
loc_8274463C:
	// li r31,0
	r31.s64 = 0;
loc_82744640:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,80(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82744660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82350630
	ctx.lr = 0x8274466C;
	sub_82350630(ctx, base);
	// stw r31,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82744678"))) PPC_WEAK_FUNC(sub_82744678);
PPC_FUNC_IMPL(__imp__sub_82744678) {
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
	ctx.lr = 0x82744680;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r5,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r5.u32);
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// stw r4,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x82744698;
	sub_82130000(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827446AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827446C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x827446C8;
	sub_82130000(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827446DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x827446F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82744704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82744718;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8274472C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x82744734;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x82130528
	ctx.lr = 0x82744740;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82744754
	if (cr6.eq) goto loc_82744754;
	// bl 0x82562638
	ctx.lr = 0x8274474C;
	sub_82562638(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82744758
	goto loc_82744758;
loc_82744754:
	// li r30,0
	r30.s64 = 0;
loc_82744758:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addi r5,r11,8
	ctx.r5.s64 = r11.s64 + 8;
	// bl 0x826e32d0
	ctx.lr = 0x8274476C;
	sub_826E32D0(ctx, base);
	// stw r30,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82744608
	ctx.lr = 0x82744778;
	sub_82744608(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b6e90
	ctx.lr = 0x82744780;
	sub_822B6E90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x82744788;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x82744794;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827447a8
	if (cr6.eq) goto loc_827447A8;
	// bl 0x8232afd8
	ctx.lr = 0x827447A0;
	sub_8232AFD8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x827447ac
	goto loc_827447AC;
loc_827447A8:
	// li r30,0
	r30.s64 = 0;
loc_827447AC:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8232bb38
	ctx.lr = 0x827447BC;
	sub_8232BB38(ctx, base);
	// stw r30,68(r29)
	PPC_STORE_U32(r29.u32 + 68, r30.u32);
	// bl 0x82562c80
	ctx.lr = 0x827447C4;
	sub_82562C80(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827447e4
	if (cr6.eq) goto loc_827447E4;
	// bl 0x82562c80
	ctx.lr = 0x827447D0;
	sub_82562C80(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827447E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827447E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x827447EC;
	sub_823EAEF8(ctx, base);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x82744800
	if (!cr6.eq) goto loc_82744800;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82744800:
	// bl 0x82352ef0
	ctx.lr = 0x82744804;
	sub_82352EF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8274480C;
	sub_823EAEF8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274481C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x82744824;
	sub_823EAEF8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274482C"))) PPC_WEAK_FUNC(sub_8274482C);
PPC_FUNC_IMPL(__imp__sub_8274482C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82744830"))) PPC_WEAK_FUNC(sub_82744830);
PPC_FUNC_IMPL(__imp__sub_82744830) {
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
	ctx.lr = 0x82744838;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,496
	ctx.r3.s64 = 496;
	// bl 0x82130528
	ctx.lr = 0x82744848;
	sub_82130528(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82744860
	if (cr6.eq) goto loc_82744860;
	// bl 0x82330e20
	ctx.lr = 0x82744858;
	sub_82330E20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82744864
	goto loc_82744864;
loc_82744860:
	// mr r30,r27
	r30.u64 = r27.u64;
loc_82744864:
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// li r3,112
	ctx.r3.s64 = 112;
	// stw r11,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r11.u32);
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// stw r10,80(r30)
	PPC_STORE_U32(r30.u32 + 80, ctx.r10.u32);
	// lwz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// stw r9,132(r30)
	PPC_STORE_U32(r30.u32 + 132, ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x82744884;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82744898
	if (cr6.eq) goto loc_82744898;
	// bl 0x823318e8
	ctx.lr = 0x82744890;
	sub_823318E8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x8274489c
	goto loc_8274489C;
loc_82744898:
	// mr r29,r27
	r29.u64 = r27.u64;
loc_8274489C:
	// stw r30,80(r29)
	PPC_STORE_U32(r29.u32 + 80, r30.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r29,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x827448AC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827448e4
	if (cr6.eq) goto loc_827448E4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,31072
	ctx.r10.s64 = r11.s64 + 31072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x827448CC;
	sub_821B5A60(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r8,r9,31116
	ctx.r8.s64 = ctx.r9.s64 + 31116;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// b 0x827448e8
	goto loc_827448E8;
loc_827448E4:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_827448E8:
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// stw r11,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r11.u32);
	// stw r27,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r27.u32);
	// stw r30,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82744900"))) PPC_WEAK_FUNC(sub_82744900);
PPC_FUNC_IMPL(__imp__sub_82744900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,-5460(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5460);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x82744918
	if (!cr6.eq) goto loc_82744918;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82744918:
	// b 0x822b9d98
	sub_822B9D98(ctx, base);
	return;
}

