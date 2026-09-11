#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_82413E90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10556(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// clrlwi r3,r11,29
	ctx.r3.u64 = r11.u32 & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82413E90) {
	__imp__sub_82413E90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82413E9C) {
	__imp__sub_82413E9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413EA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm r11,r4,8,24,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFF;
	// rlwinm r9,r4,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r10,r4,16,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFF;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// std r10,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r10.u64);
	// lfd f12,-8(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// std r11,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r11.u64);
	// lfd f11,-8(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// li r12,15
	r12.s64 = 15;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// rldicr r12,r12,33,30
	r12.u64 = __builtin_rotateleft64(r12.u64, 33) & 0xFFFFFFFE00000000;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f11,10472(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10472, temp.u32);
	// fmuls f11,f10,f0
	ctx.f11.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f11,10468(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10468, temp.u32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f12,10464(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10464, temp.u32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,10476(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10476, temp.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82413EA0) {
	__imp__sub_82413EA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413F30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,10468(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10468);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,10472(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10472);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,10464(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10464);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,10476(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10476);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,15360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f11,f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f10,f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f0,f9,f0,f13
	f0.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f13.f64));
	// fctidz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctidz f13,f11
	ctx.f13.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctidz f13,f10
	ctx.f13.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, f0.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r9,-4(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// rlwimi r10,r9,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r10,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r3,r11,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82413F30) {
	__imp__sub_82413F30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,10680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10680);
	// li r12,1
	r12.s64 = 1;
	// rlwimi r11,r4,10,21,21
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 10) & 0x400) | (r11.u64 & 0xFFFFFFFFFFFFFBFF);
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10680, r11.u32);
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82413FA0) {
	__imp__sub_82413FA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82413FC4) {
	__imp__sub_82413FC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413FC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10680);
	// rlwinm r3,r11,22,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82413FC8) {
	__imp__sub_82413FC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82413FD4) {
	__imp__sub_82413FD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82413FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f13,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,52,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 52) & 0xFFFFFFFFFFFFFFFF;
	// lfs f0,-17876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17876);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// sth r11,10606(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10606, r11.u16);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82413FD8) {
	__imp__sub_82413FD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414014) {
	__imp__sub_82414014(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,10606(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10606);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,12424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12424);
	f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414018) {
	__imp__sub_82414018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,23932(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23932);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8241405c
	if (cr6.eq) goto loc_8241405C;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// b 0x82414060
	goto loc_82414060;
loc_8241405C:
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_82414060:
	// stw r11,23932(r3)
	PPC_STORE_U32(ctx.r3.u32 + 23932, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414048) {
	__imp__sub_82414048(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,23932(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23932);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414068) {
	__imp__sub_82414068(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414074) {
	__imp__sub_82414074(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12456(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12456);
	// stw r4,11876(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11876, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241408c
	if (!cr6.eq) goto loc_8241408C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8241408C:
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,1,30,30
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 1) & 0x2) | (r11.u64 & 0xFFFFFFFFFFFFFFFD);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414078) {
	__imp__sub_82414078(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824140B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11876(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11876);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824140B0) {
	__imp__sub_824140B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824140B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,2,29,29
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 2) & 0x4) | (r11.u64 & 0xFFFFFFFFFFFFFFFB);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824140B8) {
	__imp__sub_824140B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824140D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824140D4) {
	__imp__sub_824140D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824140D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824140D8) {
	__imp__sub_824140D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824140E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824140E4) {
	__imp__sub_824140E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824140E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,4,25,27
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 4) & 0x70) | (r11.u64 & 0xFFFFFFFFFFFFFF8F);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824140E8) {
	__imp__sub_824140E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241410C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241410C) {
	__imp__sub_8241410C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,28,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414110) {
	__imp__sub_82414110(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241411C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241411C) {
	__imp__sub_8241411C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414120) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12456(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12456);
	// stw r4,11880(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11880, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82414134
	if (!cr6.eq) goto loc_82414134;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82414134:
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,0,31,31
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x1) | (r11.u64 & 0xFFFFFFFFFFFFFFFE);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414120) {
	__imp__sub_82414120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414158) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11880);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414158) {
	__imp__sub_82414158(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,7,24,24
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 7) & 0x80) | (r11.u64 & 0xFFFFFFFFFFFFFF7F);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414160) {
	__imp__sub_82414160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414184) {
	__imp__sub_82414184(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414188) {
	__imp__sub_82414188(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414194) {
	__imp__sub_82414194(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,8,21,23
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0x700) | (r11.u64 & 0xFFFFFFFFFFFFF8FF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414198) {
	__imp__sub_82414198(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824141B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824141B4) {
	__imp__sub_824141B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824141B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,24,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824141B8) {
	__imp__sub_824141B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824141C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824141C4) {
	__imp__sub_824141C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824141C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,11,18,20
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 11) & 0x3800) | (r11.u64 & 0xFFFFFFFFFFFFC7FF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824141C8) {
	__imp__sub_824141C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824141EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824141EC) {
	__imp__sub_824141EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824141F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,21,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824141F0) {
	__imp__sub_824141F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824141FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824141FC) {
	__imp__sub_824141FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,17,12,14
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 17) & 0xE0000) | (r11.u64 & 0xFFFFFFFFFFF1FFFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414200) {
	__imp__sub_82414200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414224) {
	__imp__sub_82414224(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414228) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,15,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414228) {
	__imp__sub_82414228(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414234) {
	__imp__sub_82414234(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,14,15,17
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 14) & 0x1C000) | (r11.u64 & 0xFFFFFFFFFFFE3FFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414238) {
	__imp__sub_82414238(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414254) {
	__imp__sub_82414254(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,18,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414258) {
	__imp__sub_82414258(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414264) {
	__imp__sub_82414264(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414268) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,20,9,11
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 20) & 0x700000) | (r11.u64 & 0xFFFFFFFFFF8FFFFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414268) {
	__imp__sub_82414268(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414284) {
	__imp__sub_82414284(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414288) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,12,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414288) {
	__imp__sub_82414288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414294) {
	__imp__sub_82414294(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,23,6,8
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 23) & 0x3800000) | (r11.u64 & 0xFFFFFFFFFC7FFFFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414298) {
	__imp__sub_82414298(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824142BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824142BC) {
	__imp__sub_824142BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824142C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,9,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824142C0) {
	__imp__sub_824142C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824142CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824142CC) {
	__imp__sub_824142CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824142D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,29,0,2
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 29) & 0xE0000000) | (r11.u64 & 0xFFFFFFFF1FFFFFFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824142D0) {
	__imp__sub_824142D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824142F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824142F4) {
	__imp__sub_824142F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824142F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,3,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824142F8) {
	__imp__sub_824142F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414304) {
	__imp__sub_82414304(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414308) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,26,3,5
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 26) & 0x1C000000) | (r11.u64 & 0xFFFFFFFFE3FFFFFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414308) {
	__imp__sub_82414308(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414324) {
	__imp__sub_82414324(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414328) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,6,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414328) {
	__imp__sub_82414328(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414334) {
	__imp__sub_82414334(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414338) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stb r4,10499(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10499, ctx.r4.u8);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,4096
	r11.u64 = r11.u64 | 268435456;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414338) {
	__imp__sub_82414338(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241434C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241434C) {
	__imp__sub_8241434C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414350) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10499(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10499);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414350) {
	__imp__sub_82414350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stb r4,10498(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10498, ctx.r4.u8);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,4096
	r11.u64 = r11.u64 | 268435456;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414358) {
	__imp__sub_82414358(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241436C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241436C) {
	__imp__sub_8241436C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414370) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10498(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10498);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414370) {
	__imp__sub_82414370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stb r4,10497(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10497, ctx.r4.u8);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,4096
	r11.u64 = r11.u64 | 268435456;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414378) {
	__imp__sub_82414378(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241438C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241438C) {
	__imp__sub_8241438C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414390) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10497(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10497);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414390) {
	__imp__sub_82414390(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414398) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stb r4,10495(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10495, ctx.r4.u8);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,8192
	r11.u64 = r11.u64 | 536870912;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414398) {
	__imp__sub_82414398(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824143AC) {
	__imp__sub_824143AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143B0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10495(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10495);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824143B0) {
	__imp__sub_824143B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stb r4,10494(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10494, ctx.r4.u8);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,8192
	r11.u64 = r11.u64 | 536870912;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824143B8) {
	__imp__sub_824143B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824143CC) {
	__imp__sub_824143CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143D0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10494(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10494);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824143D0) {
	__imp__sub_824143D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stb r4,10493(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10493, ctx.r4.u8);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,8192
	r11.u64 = r11.u64 | 536870912;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824143D8) {
	__imp__sub_824143D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824143EC) {
	__imp__sub_824143EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143F0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10493(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10493);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824143F0) {
	__imp__sub_824143F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824143F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister temp{};
	// lwz r11,10564(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10564);
	// subfic r10,r4,0
	xer.ca = ctx.r4.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r4.s64;
	// li r12,1
	r12.s64 = 1;
	// rlwinm r11,r11,0,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFC0;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// or r11,r11,r4
	r11.u64 = r11.u64 | ctx.r4.u64;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// stw r11,10564(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10564, r11.u32);
	// rldicr r12,r12,44,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 44) & 0xFFFFFFFFFFFFFFFF;
	// stw r10,10420(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10420, ctx.r10.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824143F8) {
	__imp__sub_824143F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10564(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10564);
	// clrlwi r3,r11,26
	ctx.r3.u64 = r11.u32 & 0x3F;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414438) {
	__imp__sub_82414438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414444) {
	__imp__sub_82414444(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414448) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11856(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11856);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414448) {
	__imp__sub_82414448(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414450) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f13,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,15000(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15000);
	f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82414484
	if (!cr6.eq) goto loc_82414484;
	// lfs f12,10836(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10836);
	ctx.f12.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// beq cr6,0x82414488
	if (cr6.eq) goto loc_82414488;
loc_82414484:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82414488:
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// rlwimi r11,r10,11,20,20
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 11) & 0x800) | (r11.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, r11.u32);
	// bne cr6,0x824144ac
	if (!cr6.eq) goto loc_824144AC;
	// lfs f12,10844(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10844);
	ctx.f12.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// beq cr6,0x824144b0
	if (cr6.eq) goto loc_824144B0;
loc_824144AC:
	// li r10,1
	ctx.r10.s64 = 1;
loc_824144B0:
	// li r12,1
	r12.s64 = 1;
	// stfs f13,10832(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10832, temp.u32);
	// rlwimi r11,r10,12,19,19
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 12) & 0x1000) | (r11.u64 & 0xFFFFFFFFFFFFEFFF);
	// stfs f13,10840(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10840, temp.u32);
	// rldicr r12,r12,45,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 45) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, r11.u32);
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// rldicr r12,r12,43,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 43) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414450) {
	__imp__sub_82414450(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824144F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824144F4) {
	__imp__sub_824144F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824144F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,10832(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10832);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-4728(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4728);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824144F8) {
	__imp__sub_824144F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414514) {
	__imp__sub_82414514(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414518) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,10832(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10832);
	ctx.f12.f64 = double(temp.f32);
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f13,28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bne cr6,0x82414540
	if (!cr6.eq) goto loc_82414540;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x82414544
	if (cr6.eq) goto loc_82414544;
loc_82414540:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82414544:
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// lfs f12,10840(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10840);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// rlwimi r11,r10,11,20,20
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 11) & 0x800) | (r11.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, r11.u32);
	// bne cr6,0x82414568
	if (!cr6.eq) goto loc_82414568;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x8241456c
	if (cr6.eq) goto loc_8241456C;
loc_82414568:
	// li r10,1
	ctx.r10.s64 = 1;
loc_8241456C:
	// li r12,1
	r12.s64 = 1;
	// stfs f13,10836(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10836, temp.u32);
	// rlwimi r11,r10,12,19,19
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 12) & 0x1000) | (r11.u64 & 0xFFFFFFFFFFFFEFFF);
	// stfs f13,10844(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10844, temp.u32);
	// rldicr r12,r12,44,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 44) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, r11.u32);
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// li r12,1
	r12.s64 = 1;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// rldicr r12,r12,42,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 42) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414518) {
	__imp__sub_82414518(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824145B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,10836(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10836);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824145B0) {
	__imp__sub_824145B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824145C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwimi r11,r4,15,16,16
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 15) & 0x8000) | (r11.u64 & 0xFFFFFFFFFFFF7FFF);
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824145C0) {
	__imp__sub_824145C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824145DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824145DC) {
	__imp__sub_824145DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824145E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwinm r3,r11,17,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824145E0) {
	__imp__sub_824145E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824145EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824145EC) {
	__imp__sub_824145EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824145F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// stw r11,10752(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10752, r11.u32);
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// oris r11,r11,8
	r11.u64 = r11.u64 | 524288;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824145F0) {
	__imp__sub_824145F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414608) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10752(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10752);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414608) {
	__imp__sub_82414608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414610) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,12440(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12440);
	// stw r4,11860(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11860, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82414624
	if (!cr6.eq) goto loc_82414624;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82414624:
	// lwz r11,10460(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10460);
	// li r12,1
	r12.s64 = 1;
	// rlwimi r4,r11,0,0,27
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFFFF0) | (ctx.r4.u64 & 0xFFFFFFFF0000000F);
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// stw r4,10460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10460, ctx.r4.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414610) {
	__imp__sub_82414610(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414648) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11860(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11860);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414648) {
	__imp__sub_82414648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414650) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,12444(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12444);
	// stw r4,11864(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11864, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82414664
	if (!cr6.eq) goto loc_82414664;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82414664:
	// lwz r11,10460(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10460);
	// li r12,1
	r12.s64 = 1;
	// rlwimi r11,r4,4,24,27
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 4) & 0xF0) | (r11.u64 & 0xFFFFFFFFFFFFFF0F);
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10460, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414650) {
	__imp__sub_82414650(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414688) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11864(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11864);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414688) {
	__imp__sub_82414688(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414690) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,12448(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12448);
	// stw r4,11868(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11868, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824146a4
	if (!cr6.eq) goto loc_824146A4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_824146A4:
	// lwz r11,10460(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10460);
	// li r12,1
	r12.s64 = 1;
	// rlwimi r11,r4,8,20,23
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xF00) | (r11.u64 & 0xFFFFFFFFFFFFF0FF);
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10460, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414690) {
	__imp__sub_82414690(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824146C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11868(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11868);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824146C8) {
	__imp__sub_824146C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824146D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,12452(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12452);
	// stw r4,11872(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11872, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824146e4
	if (!cr6.eq) goto loc_824146E4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_824146E4:
	// lwz r11,10460(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10460);
	// li r12,1
	r12.s64 = 1;
	// rlwimi r11,r4,12,16,19
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 12) & 0xF000) | (r11.u64 & 0xFFFFFFFFFFFF0FFF);
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10460, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824146D0) {
	__imp__sub_824146D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414708) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11872(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11872);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414708) {
	__imp__sub_82414708(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414710) {
	PPC_FUNC_PROLOGUE();
	// stw r4,11884(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11884, ctx.r4.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414710) {
	__imp__sub_82414710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414718) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11884(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11884);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414718) {
	__imp__sub_82414718(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// li r12,1
	r12.s64 = 1;
	// stfs f0,11892(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 11892, temp.u32);
	// lfs f13,-17876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17876);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r12,r12,54,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 54) & 0xFFFFFFFFFFFFFFFF;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sth r11,10598(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10598, r11.u16);
	// sth r11,10596(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10596, r11.u16);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414720) {
	__imp__sub_82414720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,11892(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 11892);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414768) {
	__imp__sub_82414768(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414778) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// li r12,1
	r12.s64 = 1;
	// stfs f0,11896(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 11896, temp.u32);
	// lfs f13,15000(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15000);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r12,r12,53,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 53) & 0xFFFFFFFFFFFFFFFF;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// sth r11,10602(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10602, r11.u16);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414778) {
	__imp__sub_82414778(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824147B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,11896(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 11896);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824147B8) {
	__imp__sub_824147B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824147C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// li r12,1
	r12.s64 = 1;
	// stfs f0,11900(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 11900, temp.u32);
	// lfs f13,15000(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15000);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r12,r12,53,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 53) & 0xFFFFFFFFFFFFFFFF;
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// sth r11,10600(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10600, r11.u16);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824147C8) {
	__imp__sub_824147C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,11900(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 11900);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414808) {
	__imp__sub_82414808(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r11,r11,0,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// or r11,r11,r4
	r11.u64 = r11.u64 | ctx.r4.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414818) {
	__imp__sub_82414818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414838) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r11,0,28,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414838) {
	__imp__sub_82414838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241485C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241485C) {
	__imp__sub_8241485C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414860) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r11,r11,0,24,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF0FF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414860) {
	__imp__sub_82414860(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414884) {
	__imp__sub_82414884(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFFFFF000;
	// rlwinm r11,r11,0,20,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFF0FFF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414888) {
	__imp__sub_82414888(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824148AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824148AC) {
	__imp__sub_824148AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824148B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,0,16,11
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824148B0) {
	__imp__sub_824148B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824148D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824148D4) {
	__imp__sub_824148D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824148D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,20,0,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 20) & 0xFFF00000;
	// rlwinm r11,r11,0,12,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFF0FFFFF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824148D8) {
	__imp__sub_824148D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824148FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824148FC) {
	__imp__sub_824148FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF000000;
	// rlwinm r11,r11,0,8,3
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFF0FFFFFF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414900) {
	__imp__sub_82414900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414924) {
	__imp__sub_82414924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414928) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwimi r11,r4,28,0,3
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 28) & 0xF0000000) | (r11.u64 & 0xFFFFFFFF0FFFFFFF);
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	r11.u64 = r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414928) {
	__imp__sub_82414928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414944) {
	__imp__sub_82414944(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r11,r11,0,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// or r11,r11,r4
	r11.u64 = r11.u64 | ctx.r4.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414948) {
	__imp__sub_82414948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r11,0,28,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414968) {
	__imp__sub_82414968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241498C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241498C) {
	__imp__sub_8241498C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r11,r11,0,24,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF0FF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414990) {
	__imp__sub_82414990(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824149B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824149B4) {
	__imp__sub_824149B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824149B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFFFFF000;
	// rlwinm r11,r11,0,20,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFF0FFF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824149B8) {
	__imp__sub_824149B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824149DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824149DC) {
	__imp__sub_824149DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824149E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,0,16,11
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824149E0) {
	__imp__sub_824149E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414A04) {
	__imp__sub_82414A04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,20,0,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 20) & 0xFFF00000;
	// rlwinm r11,r11,0,12,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFF0FFFFF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414A08) {
	__imp__sub_82414A08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414A2C) {
	__imp__sub_82414A2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF000000;
	// rlwinm r11,r11,0,8,3
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFF0FFFFFF;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414A30) {
	__imp__sub_82414A30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414A54) {
	__imp__sub_82414A54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwimi r11,r4,28,0,3
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 28) & 0xF0000000) | (r11.u64 & 0xFFFFFFFF0FFFFFFF);
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	r11.u64 = r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414A58) {
	__imp__sub_82414A58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414A74) {
	__imp__sub_82414A74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// clrlwi r3,r11,28
	ctx.r3.u64 = r11.u32 & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414A78) {
	__imp__sub_82414A78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414A84) {
	__imp__sub_82414A84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,28,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414A88) {
	__imp__sub_82414A88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414A94) {
	__imp__sub_82414A94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414A98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,24,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414A98) {
	__imp__sub_82414A98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414AA4) {
	__imp__sub_82414AA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,20,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414AA8) {
	__imp__sub_82414AA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414AB4) {
	__imp__sub_82414AB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,10540(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10540);
	// clrlwi r3,r11,28
	ctx.r3.u64 = r11.u32 & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414AB8) {
	__imp__sub_82414AB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414AC4) {
	__imp__sub_82414AC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,12,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414AC8) {
	__imp__sub_82414AC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414AD4) {
	__imp__sub_82414AD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,10540(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10540);
	// clrlwi r3,r11,28
	ctx.r3.u64 = r11.u32 & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414AD8) {
	__imp__sub_82414AD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414AE4) {
	__imp__sub_82414AE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10540(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,4,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414AE8) {
	__imp__sub_82414AE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414AF4) {
	__imp__sub_82414AF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414AF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// clrlwi r3,r11,28
	ctx.r3.u64 = r11.u32 & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414AF8) {
	__imp__sub_82414AF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414B04) {
	__imp__sub_82414B04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,28,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414B08) {
	__imp__sub_82414B08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414B14) {
	__imp__sub_82414B14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,24,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414B18) {
	__imp__sub_82414B18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414B24) {
	__imp__sub_82414B24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,20,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414B28) {
	__imp__sub_82414B28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414B34) {
	__imp__sub_82414B34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,10544(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10544);
	// clrlwi r3,r11,28
	ctx.r3.u64 = r11.u32 & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414B38) {
	__imp__sub_82414B38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414B44) {
	__imp__sub_82414B44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,12,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414B48) {
	__imp__sub_82414B48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414B54) {
	__imp__sub_82414B54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,10544(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10544);
	// clrlwi r3,r11,28
	ctx.r3.u64 = r11.u32 & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414B58) {
	__imp__sub_82414B58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414B64) {
	__imp__sub_82414B64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10544(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,4,28,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414B68) {
	__imp__sub_82414B68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414B74) {
	__imp__sub_82414B74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414B78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r11,1087
	r11.s64 = 1087;
	// bne cr6,0x82414b88
	if (!cr6.eq) goto loc_82414B88;
	// li r11,1024
	r11.s64 = 1024;
loc_82414B88:
	// stw r11,10572(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10572, r11.u32);
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// lwz r10,10564(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10564);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// rlwimi r10,r11,16,15,15
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 16) & 0x10000) | (ctx.r10.u64 & 0xFFFFFFFFFFFEFFFF);
	// stw r10,10564(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10564, ctx.r10.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414B78) {
	__imp__sub_82414B78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10572(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10572);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414BB8) {
	__imp__sub_82414BB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414BC4) {
	__imp__sub_82414BC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414BC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r10,12440(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12440);
	// stw r4,12028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12028, ctx.r4.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r11,r9,16,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x82414c00
	if (cr6.eq) goto loc_82414C00;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x82414c00
	if (cr6.eq) goto loc_82414C00;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x82414c00
	if (cr6.eq) goto loc_82414C00;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_82414C00:
	// rlwinm r11,r9,13,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1;
	// xor. r11,r11,r4
	r11.u64 = r11.u64 ^ ctx.r4.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// lwz r7,28(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// li r12,1
	r12.s64 = 1;
	// rlwinm r9,r7,16,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xF;
	// rlwinm r8,r7,15,29,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0x7;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// addi r8,r8,-3
	ctx.r8.s64 = ctx.r8.s64 + -3;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// and r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 & r11.u64;
	// andc r11,r9,r11
	r11.u64 = ctx.r9.u64 & ~r11.u64;
	// rlwinm r9,r7,0,16,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// rldicr r12,r12,56,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r11,r11,16,12,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xF0000;
	// or r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 | r11.u64;
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// lwz r10,10372(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10372);
	// rlwinm r10,r10,0,16,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,10372(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10372, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414BC8) {
	__imp__sub_82414BC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414C6C) {
	__imp__sub_82414C6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414C70) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12028(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414C70) {
	__imp__sub_82414C70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414C78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r10,12444(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12444);
	// stw r4,12032(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12032, ctx.r4.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r11,r9,16,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x82414cb0
	if (cr6.eq) goto loc_82414CB0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x82414cb0
	if (cr6.eq) goto loc_82414CB0;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x82414cb0
	if (cr6.eq) goto loc_82414CB0;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_82414CB0:
	// rlwinm r11,r9,13,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1;
	// xor. r11,r11,r4
	r11.u64 = r11.u64 ^ ctx.r4.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// lwz r7,28(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// li r12,1
	r12.s64 = 1;
	// rlwinm r9,r7,16,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xF;
	// rlwinm r8,r7,15,29,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0x7;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// addi r8,r8,-3
	ctx.r8.s64 = ctx.r8.s64 + -3;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// and r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 & r11.u64;
	// andc r11,r9,r11
	r11.u64 = ctx.r9.u64 & ~r11.u64;
	// rlwinm r9,r7,0,16,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// rldicr r12,r12,54,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 54) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r11,r11,16,12,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xF0000;
	// or r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 | r11.u64;
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// lwz r10,10380(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10380);
	// rlwinm r10,r10,0,16,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,10380(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10380, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414C78) {
	__imp__sub_82414C78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414D1C) {
	__imp__sub_82414D1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414D20) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12032(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12032);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414D20) {
	__imp__sub_82414D20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414D28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r10,12448(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12448);
	// stw r4,12036(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12036, ctx.r4.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r11,r9,16,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x82414d60
	if (cr6.eq) goto loc_82414D60;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x82414d60
	if (cr6.eq) goto loc_82414D60;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x82414d60
	if (cr6.eq) goto loc_82414D60;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_82414D60:
	// rlwinm r11,r9,13,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1;
	// xor. r11,r11,r4
	r11.u64 = r11.u64 ^ ctx.r4.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// lwz r7,28(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// li r12,1
	r12.s64 = 1;
	// rlwinm r9,r7,16,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xF;
	// rlwinm r8,r7,15,29,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0x7;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// addi r8,r8,-3
	ctx.r8.s64 = ctx.r8.s64 + -3;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// and r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 & r11.u64;
	// andc r11,r9,r11
	r11.u64 = ctx.r9.u64 & ~r11.u64;
	// rlwinm r9,r7,0,16,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// rldicr r12,r12,53,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 53) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r11,r11,16,12,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xF0000;
	// or r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 | r11.u64;
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// lwz r10,10384(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10384);
	// rlwinm r10,r10,0,16,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,10384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10384, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414D28) {
	__imp__sub_82414D28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414DCC) {
	__imp__sub_82414DCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414DD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12036(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12036);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414DD0) {
	__imp__sub_82414DD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414DD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r10,12452(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12452);
	// stw r4,12040(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12040, ctx.r4.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r11,r9,16,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x82414e10
	if (cr6.eq) goto loc_82414E10;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x82414e10
	if (cr6.eq) goto loc_82414E10;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x82414e10
	if (cr6.eq) goto loc_82414E10;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_82414E10:
	// rlwinm r11,r9,13,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1;
	// xor. r11,r11,r4
	r11.u64 = r11.u64 ^ ctx.r4.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// lwz r7,28(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// li r12,1
	r12.s64 = 1;
	// rlwinm r9,r7,16,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xF;
	// rlwinm r8,r7,15,29,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0x7;
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
	// addi r8,r8,-3
	ctx.r8.s64 = ctx.r8.s64 + -3;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// and r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 & r11.u64;
	// andc r11,r9,r11
	r11.u64 = ctx.r9.u64 & ~r11.u64;
	// rlwinm r9,r7,0,16,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r11,r8
	r11.u64 = r11.u64 | ctx.r8.u64;
	// rldicr r12,r12,52,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 52) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r11,r11,16,12,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xF0000;
	// or r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 | r11.u64;
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// lwz r10,10388(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10388);
	// rlwinm r10,r10,0,16,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// stw r11,10388(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10388, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414DD8) {
	__imp__sub_82414DD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414E7C) {
	__imp__sub_82414E7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414E80) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12040(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12040);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414E80) {
	__imp__sub_82414E80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414E88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,10624(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10624, temp.u32);
	// li r12,1
	r12.s64 = 1;
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// rldicr r12,r12,47,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 47) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	r11.u64 = ctx.r10.u64 | r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414E88) {
	__imp__sub_82414E88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414EAC) {
	__imp__sub_82414EAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414EB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,10624(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10624);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414EB0) {
	__imp__sub_82414EB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414EC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,10620(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10620, temp.u32);
	// li r12,1
	r12.s64 = 1;
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// rldicr r12,r12,48,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 48) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	r11.u64 = ctx.r10.u64 | r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414EC0) {
	__imp__sub_82414EC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414EE4) {
	__imp__sub_82414EE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414EE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,10620(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10620);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414EE8) {
	__imp__sub_82414EE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414EF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,10616(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10616);
	// li r12,1
	r12.s64 = 1;
	// rlwimi r4,r11,0,0,29
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFFFFC) | (ctx.r4.u64 & 0xFFFFFFFF00000003);
	// rldicr r12,r12,49,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 49) & 0xFFFFFFFFFFFFFFFF;
	// stw r4,10616(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10616, ctx.r4.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414EF8) {
	__imp__sub_82414EF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414F1C) {
	__imp__sub_82414F1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10616(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10616);
	// clrlwi r3,r11,30
	ctx.r3.u64 = r11.u32 & 0x3;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414F20) {
	__imp__sub_82414F20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414F2C) {
	__imp__sub_82414F2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,10688(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10688);
	// li r12,1
	r12.s64 = 1;
	// rlwimi r4,r11,0,0,30
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFFFFE) | (ctx.r4.u64 & 0xFFFFFFFF00000001);
	// rldicr r12,r12,35,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 35) & 0xFFFFFFFFFFFFFFFF;
	// stw r4,10688(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10688, ctx.r4.u32);
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414F30) {
	__imp__sub_82414F30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414F54) {
	__imp__sub_82414F54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10688(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10688);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414F58) {
	__imp__sub_82414F58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414F64) {
	__imp__sub_82414F64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwimi r11,r4,21,10,10
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 21) & 0x200000) | (r11.u64 & 0xFFFFFFFFFFDFFFFF);
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414F68) {
	__imp__sub_82414F68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414F84) {
	__imp__sub_82414F84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwinm r3,r11,11,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414F88) {
	__imp__sub_82414F88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414F94) {
	__imp__sub_82414F94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414F98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	// li r12,1
	r12.s64 = 1;
	// stw r4,10456(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10456, ctx.r4.u32);
	// ld r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// rldicr r12,r12,38,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 38) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	r11.u64 = ctx.r10.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414F98) {
	__imp__sub_82414F98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414FB4) {
	__imp__sub_82414FB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414FB8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10456);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414FB8) {
	__imp__sub_82414FB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10556(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r11,r4,4,27,27
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 4) & 0x10) | (r11.u64 & 0xFFFFFFFFFFFFFFEF);
	// stw r11,10556(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10556, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	r11.u64 = r11.u64 | 512;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414FC0) {
	__imp__sub_82414FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414FDC) {
	__imp__sub_82414FDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414FE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10556(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwinm r3,r11,28,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414FE0) {
	__imp__sub_82414FE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82414FEC) {
	__imp__sub_82414FEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82414FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10556(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r11,r4,24,0,7
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 24) & 0xFF000000) | (r11.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r11,10556(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10556, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	r11.u64 = r11.u64 | 512;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82414FF0) {
	__imp__sub_82414FF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241500C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241500C) {
	__imp__sub_8241500C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,10556(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10556);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rlwimi r11,r10,0,24,29
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFC) | (r11.u64 & 0xFFFFFFFFFFFFFF03);
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415010) {
	__imp__sub_82415010(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82415024) {
	__imp__sub_82415024(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415028) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,10700(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10700, temp.u32);
	// li r12,1
	r12.s64 = 1;
	// ld r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,32,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	r11.u64 = ctx.r10.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415028) {
	__imp__sub_82415028(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241504C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241504C) {
	__imp__sub_8241504C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415050) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10700(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10700);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415050) {
	__imp__sub_82415050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,10692(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10692, temp.u32);
	// li r12,1
	r12.s64 = 1;
	// ld r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,34,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 34) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	r11.u64 = ctx.r10.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415058) {
	__imp__sub_82415058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241507C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241507C) {
	__imp__sub_8241507C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415080) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10692);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415080) {
	__imp__sub_82415080(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,10704(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10704, temp.u32);
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// oris r11,r11,32768
	r11.u64 = r11.u64 | 2147483648;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415088) {
	__imp__sub_82415088(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824150A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824150A4) {
	__imp__sub_824150A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824150A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10704(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10704);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824150A8) {
	__imp__sub_824150A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824150B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,10696(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10696, temp.u32);
	// li r12,1
	r12.s64 = 1;
	// ld r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,33,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 33) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	r11.u64 = ctx.r10.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824150B0) {
	__imp__sub_824150B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824150D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824150D4) {
	__imp__sub_824150D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824150D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10696(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10696);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824150D8) {
	__imp__sub_824150D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824150E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r11,r4,20,9,11
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 20) & 0x700000) | (r11.u64 & 0xFFFFFFFFFF8FFFFF);
	// stw r11,11852(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11852, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824150E0) {
	__imp__sub_824150E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824150FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824150FC) {
	__imp__sub_824150FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwinm r3,r11,12,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415100) {
	__imp__sub_82415100(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241510C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241510C) {
	__imp__sub_8241510C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// lbz r10,10943(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10943);
	// rlwimi r11,r4,17,12,14
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 17) & 0xE0000) | (r11.u64 & 0xFFFFFFFFFFF1FFFF);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,11852(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11852, r11.u32);
	// bne 0x82415148
	if (!cr0.eq) goto loc_82415148;
	// rlwinm r11,r11,0,12,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xE0000;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82415148
	if (!cr6.eq) goto loc_82415148;
	// ld r11,40(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// li r12,-257
	r12.s64 = -257;
	// and r11,r11,r12
	r11.u64 = r11.u64 & r12.u64;
	// b 0x82415150
	goto loc_82415150;
loc_82415148:
	// ld r11,40(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
loc_82415150:
	// std r11,40(r3)
	PPC_STORE_U64(ctx.r3.u32 + 40, r11.u64);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415110) {
	__imp__sub_82415110(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82415164) {
	__imp__sub_82415164(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwinm r3,r11,15,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x7;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415168) {
	__imp__sub_82415168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82415174) {
	__imp__sub_82415174(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10560(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwimi r11,r4,3,28,28
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 3) & 0x8) | (r11.u64 & 0xFFFFFFFFFFFFFFF7);
	// stw r11,10560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10560, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415178) {
	__imp__sub_82415178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82415194) {
	__imp__sub_82415194(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10560(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwinm r3,r11,29,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415198) {
	__imp__sub_82415198(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824151A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824151A4) {
	__imp__sub_824151A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824151A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10560(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwimi r11,r4,2,29,29
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 2) & 0x4) | (r11.u64 & 0xFFFFFFFFFFFFFFFB);
	// stw r11,10560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10560, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824151A8) {
	__imp__sub_824151A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824151C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824151C4) {
	__imp__sub_824151C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824151C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10560(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824151C8) {
	__imp__sub_824151C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824151D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824151D4) {
	__imp__sub_824151D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824151D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10560(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwimi r11,r4,5,26,26
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 5) & 0x20) | (r11.u64 & 0xFFFFFFFFFFFFFFDF);
	// stw r11,10560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10560, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824151D8) {
	__imp__sub_824151D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824151F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824151F4) {
	__imp__sub_824151F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824151F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10560(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824151F8) {
	__imp__sub_824151F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82415204) {
	__imp__sub_82415204(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415208) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stb r4,10562(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10562, ctx.r4.u8);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	r11.u64 = r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415208) {
	__imp__sub_82415208(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8241521C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8241521C) {
	__imp__sub_8241521C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415220) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10562(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10562);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415220) {
	__imp__sub_82415220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415228) {
	PPC_FUNC_PROLOGUE();
	// stw r4,13596(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13596, ctx.r4.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415228) {
	__imp__sub_82415228(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415230) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,13596(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13596);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415230) {
	__imp__sub_82415230(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82415238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r11,r4,23,2,8
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 23) & 0x3F800000) | (r11.u64 & 0xFFFFFFFFC07FFFFF);
	// stw r11,11852(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11852, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82415238) {
	__imp__sub_82415238(ctx, base);
}

