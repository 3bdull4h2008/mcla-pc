#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82414268"))) PPC_WEAK_FUNC(sub_82414268);
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

__attribute__((alias("__imp__sub_82414284"))) PPC_WEAK_FUNC(sub_82414284);
PPC_FUNC_IMPL(__imp__sub_82414284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414288"))) PPC_WEAK_FUNC(sub_82414288);
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

__attribute__((alias("__imp__sub_82414294"))) PPC_WEAK_FUNC(sub_82414294);
PPC_FUNC_IMPL(__imp__sub_82414294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414298"))) PPC_WEAK_FUNC(sub_82414298);
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

__attribute__((alias("__imp__sub_824142BC"))) PPC_WEAK_FUNC(sub_824142BC);
PPC_FUNC_IMPL(__imp__sub_824142BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824142C0"))) PPC_WEAK_FUNC(sub_824142C0);
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

__attribute__((alias("__imp__sub_824142CC"))) PPC_WEAK_FUNC(sub_824142CC);
PPC_FUNC_IMPL(__imp__sub_824142CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824142D0"))) PPC_WEAK_FUNC(sub_824142D0);
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

__attribute__((alias("__imp__sub_824142F4"))) PPC_WEAK_FUNC(sub_824142F4);
PPC_FUNC_IMPL(__imp__sub_824142F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824142F8"))) PPC_WEAK_FUNC(sub_824142F8);
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

__attribute__((alias("__imp__sub_82414304"))) PPC_WEAK_FUNC(sub_82414304);
PPC_FUNC_IMPL(__imp__sub_82414304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414308"))) PPC_WEAK_FUNC(sub_82414308);
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

__attribute__((alias("__imp__sub_82414324"))) PPC_WEAK_FUNC(sub_82414324);
PPC_FUNC_IMPL(__imp__sub_82414324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414328"))) PPC_WEAK_FUNC(sub_82414328);
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

__attribute__((alias("__imp__sub_82414334"))) PPC_WEAK_FUNC(sub_82414334);
PPC_FUNC_IMPL(__imp__sub_82414334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414338"))) PPC_WEAK_FUNC(sub_82414338);
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

__attribute__((alias("__imp__sub_8241434C"))) PPC_WEAK_FUNC(sub_8241434C);
PPC_FUNC_IMPL(__imp__sub_8241434C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414350"))) PPC_WEAK_FUNC(sub_82414350);
PPC_FUNC_IMPL(__imp__sub_82414350) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10499(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10499);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414358"))) PPC_WEAK_FUNC(sub_82414358);
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

__attribute__((alias("__imp__sub_8241436C"))) PPC_WEAK_FUNC(sub_8241436C);
PPC_FUNC_IMPL(__imp__sub_8241436C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414370"))) PPC_WEAK_FUNC(sub_82414370);
PPC_FUNC_IMPL(__imp__sub_82414370) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10498(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10498);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414378"))) PPC_WEAK_FUNC(sub_82414378);
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

__attribute__((alias("__imp__sub_8241438C"))) PPC_WEAK_FUNC(sub_8241438C);
PPC_FUNC_IMPL(__imp__sub_8241438C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414390"))) PPC_WEAK_FUNC(sub_82414390);
PPC_FUNC_IMPL(__imp__sub_82414390) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10497(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10497);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414398"))) PPC_WEAK_FUNC(sub_82414398);
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

__attribute__((alias("__imp__sub_824143AC"))) PPC_WEAK_FUNC(sub_824143AC);
PPC_FUNC_IMPL(__imp__sub_824143AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824143B0"))) PPC_WEAK_FUNC(sub_824143B0);
PPC_FUNC_IMPL(__imp__sub_824143B0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10495(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10495);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824143B8"))) PPC_WEAK_FUNC(sub_824143B8);
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

__attribute__((alias("__imp__sub_824143CC"))) PPC_WEAK_FUNC(sub_824143CC);
PPC_FUNC_IMPL(__imp__sub_824143CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824143D0"))) PPC_WEAK_FUNC(sub_824143D0);
PPC_FUNC_IMPL(__imp__sub_824143D0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10494(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10494);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824143D8"))) PPC_WEAK_FUNC(sub_824143D8);
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

__attribute__((alias("__imp__sub_824143EC"))) PPC_WEAK_FUNC(sub_824143EC);
PPC_FUNC_IMPL(__imp__sub_824143EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824143F0"))) PPC_WEAK_FUNC(sub_824143F0);
PPC_FUNC_IMPL(__imp__sub_824143F0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10493(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10493);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824143F8"))) PPC_WEAK_FUNC(sub_824143F8);
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

__attribute__((alias("__imp__sub_82414438"))) PPC_WEAK_FUNC(sub_82414438);
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

__attribute__((alias("__imp__sub_82414444"))) PPC_WEAK_FUNC(sub_82414444);
PPC_FUNC_IMPL(__imp__sub_82414444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414448"))) PPC_WEAK_FUNC(sub_82414448);
PPC_FUNC_IMPL(__imp__sub_82414448) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11856(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11856);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414450"))) PPC_WEAK_FUNC(sub_82414450);
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

__attribute__((alias("__imp__sub_824144F4"))) PPC_WEAK_FUNC(sub_824144F4);
PPC_FUNC_IMPL(__imp__sub_824144F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824144F8"))) PPC_WEAK_FUNC(sub_824144F8);
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

__attribute__((alias("__imp__sub_82414514"))) PPC_WEAK_FUNC(sub_82414514);
PPC_FUNC_IMPL(__imp__sub_82414514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414518"))) PPC_WEAK_FUNC(sub_82414518);
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

__attribute__((alias("__imp__sub_824145B0"))) PPC_WEAK_FUNC(sub_824145B0);
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

__attribute__((alias("__imp__sub_824145C0"))) PPC_WEAK_FUNC(sub_824145C0);
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

__attribute__((alias("__imp__sub_824145DC"))) PPC_WEAK_FUNC(sub_824145DC);
PPC_FUNC_IMPL(__imp__sub_824145DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824145E0"))) PPC_WEAK_FUNC(sub_824145E0);
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

__attribute__((alias("__imp__sub_824145EC"))) PPC_WEAK_FUNC(sub_824145EC);
PPC_FUNC_IMPL(__imp__sub_824145EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824145F0"))) PPC_WEAK_FUNC(sub_824145F0);
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

__attribute__((alias("__imp__sub_82414608"))) PPC_WEAK_FUNC(sub_82414608);
PPC_FUNC_IMPL(__imp__sub_82414608) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10752(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10752);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414610"))) PPC_WEAK_FUNC(sub_82414610);
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

__attribute__((alias("__imp__sub_82414648"))) PPC_WEAK_FUNC(sub_82414648);
PPC_FUNC_IMPL(__imp__sub_82414648) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11860(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11860);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414650"))) PPC_WEAK_FUNC(sub_82414650);
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

__attribute__((alias("__imp__sub_82414688"))) PPC_WEAK_FUNC(sub_82414688);
PPC_FUNC_IMPL(__imp__sub_82414688) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11864(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11864);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414690"))) PPC_WEAK_FUNC(sub_82414690);
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

__attribute__((alias("__imp__sub_824146C8"))) PPC_WEAK_FUNC(sub_824146C8);
PPC_FUNC_IMPL(__imp__sub_824146C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11868(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11868);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824146D0"))) PPC_WEAK_FUNC(sub_824146D0);
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

__attribute__((alias("__imp__sub_82414708"))) PPC_WEAK_FUNC(sub_82414708);
PPC_FUNC_IMPL(__imp__sub_82414708) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11872(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11872);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414710"))) PPC_WEAK_FUNC(sub_82414710);
PPC_FUNC_IMPL(__imp__sub_82414710) {
	PPC_FUNC_PROLOGUE();
	// stw r4,11884(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11884, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414718"))) PPC_WEAK_FUNC(sub_82414718);
PPC_FUNC_IMPL(__imp__sub_82414718) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11884(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11884);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414720"))) PPC_WEAK_FUNC(sub_82414720);
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

__attribute__((alias("__imp__sub_82414768"))) PPC_WEAK_FUNC(sub_82414768);
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

__attribute__((alias("__imp__sub_82414778"))) PPC_WEAK_FUNC(sub_82414778);
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

__attribute__((alias("__imp__sub_824147B8"))) PPC_WEAK_FUNC(sub_824147B8);
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

__attribute__((alias("__imp__sub_824147C8"))) PPC_WEAK_FUNC(sub_824147C8);
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

__attribute__((alias("__imp__sub_82414808"))) PPC_WEAK_FUNC(sub_82414808);
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

__attribute__((alias("__imp__sub_82414818"))) PPC_WEAK_FUNC(sub_82414818);
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

__attribute__((alias("__imp__sub_82414838"))) PPC_WEAK_FUNC(sub_82414838);
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

__attribute__((alias("__imp__sub_8241485C"))) PPC_WEAK_FUNC(sub_8241485C);
PPC_FUNC_IMPL(__imp__sub_8241485C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414860"))) PPC_WEAK_FUNC(sub_82414860);
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

__attribute__((alias("__imp__sub_82414884"))) PPC_WEAK_FUNC(sub_82414884);
PPC_FUNC_IMPL(__imp__sub_82414884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414888"))) PPC_WEAK_FUNC(sub_82414888);
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

__attribute__((alias("__imp__sub_824148AC"))) PPC_WEAK_FUNC(sub_824148AC);
PPC_FUNC_IMPL(__imp__sub_824148AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824148B0"))) PPC_WEAK_FUNC(sub_824148B0);
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

__attribute__((alias("__imp__sub_824148D4"))) PPC_WEAK_FUNC(sub_824148D4);
PPC_FUNC_IMPL(__imp__sub_824148D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824148D8"))) PPC_WEAK_FUNC(sub_824148D8);
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

__attribute__((alias("__imp__sub_824148FC"))) PPC_WEAK_FUNC(sub_824148FC);
PPC_FUNC_IMPL(__imp__sub_824148FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414900"))) PPC_WEAK_FUNC(sub_82414900);
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

__attribute__((alias("__imp__sub_82414924"))) PPC_WEAK_FUNC(sub_82414924);
PPC_FUNC_IMPL(__imp__sub_82414924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414928"))) PPC_WEAK_FUNC(sub_82414928);
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

__attribute__((alias("__imp__sub_82414944"))) PPC_WEAK_FUNC(sub_82414944);
PPC_FUNC_IMPL(__imp__sub_82414944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414948"))) PPC_WEAK_FUNC(sub_82414948);
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

__attribute__((alias("__imp__sub_82414968"))) PPC_WEAK_FUNC(sub_82414968);
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

__attribute__((alias("__imp__sub_8241498C"))) PPC_WEAK_FUNC(sub_8241498C);
PPC_FUNC_IMPL(__imp__sub_8241498C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414990"))) PPC_WEAK_FUNC(sub_82414990);
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

__attribute__((alias("__imp__sub_824149B4"))) PPC_WEAK_FUNC(sub_824149B4);
PPC_FUNC_IMPL(__imp__sub_824149B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824149B8"))) PPC_WEAK_FUNC(sub_824149B8);
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

__attribute__((alias("__imp__sub_824149DC"))) PPC_WEAK_FUNC(sub_824149DC);
PPC_FUNC_IMPL(__imp__sub_824149DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824149E0"))) PPC_WEAK_FUNC(sub_824149E0);
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

__attribute__((alias("__imp__sub_82414A04"))) PPC_WEAK_FUNC(sub_82414A04);
PPC_FUNC_IMPL(__imp__sub_82414A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414A08"))) PPC_WEAK_FUNC(sub_82414A08);
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

__attribute__((alias("__imp__sub_82414A2C"))) PPC_WEAK_FUNC(sub_82414A2C);
PPC_FUNC_IMPL(__imp__sub_82414A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414A30"))) PPC_WEAK_FUNC(sub_82414A30);
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

__attribute__((alias("__imp__sub_82414A54"))) PPC_WEAK_FUNC(sub_82414A54);
PPC_FUNC_IMPL(__imp__sub_82414A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414A58"))) PPC_WEAK_FUNC(sub_82414A58);
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

__attribute__((alias("__imp__sub_82414A74"))) PPC_WEAK_FUNC(sub_82414A74);
PPC_FUNC_IMPL(__imp__sub_82414A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414A78"))) PPC_WEAK_FUNC(sub_82414A78);
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

__attribute__((alias("__imp__sub_82414A84"))) PPC_WEAK_FUNC(sub_82414A84);
PPC_FUNC_IMPL(__imp__sub_82414A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414A88"))) PPC_WEAK_FUNC(sub_82414A88);
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

__attribute__((alias("__imp__sub_82414A94"))) PPC_WEAK_FUNC(sub_82414A94);
PPC_FUNC_IMPL(__imp__sub_82414A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414A98"))) PPC_WEAK_FUNC(sub_82414A98);
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

__attribute__((alias("__imp__sub_82414AA4"))) PPC_WEAK_FUNC(sub_82414AA4);
PPC_FUNC_IMPL(__imp__sub_82414AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414AA8"))) PPC_WEAK_FUNC(sub_82414AA8);
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

__attribute__((alias("__imp__sub_82414AB4"))) PPC_WEAK_FUNC(sub_82414AB4);
PPC_FUNC_IMPL(__imp__sub_82414AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414AB8"))) PPC_WEAK_FUNC(sub_82414AB8);
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

__attribute__((alias("__imp__sub_82414AC4"))) PPC_WEAK_FUNC(sub_82414AC4);
PPC_FUNC_IMPL(__imp__sub_82414AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414AC8"))) PPC_WEAK_FUNC(sub_82414AC8);
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

__attribute__((alias("__imp__sub_82414AD4"))) PPC_WEAK_FUNC(sub_82414AD4);
PPC_FUNC_IMPL(__imp__sub_82414AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414AD8"))) PPC_WEAK_FUNC(sub_82414AD8);
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

__attribute__((alias("__imp__sub_82414AE4"))) PPC_WEAK_FUNC(sub_82414AE4);
PPC_FUNC_IMPL(__imp__sub_82414AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414AE8"))) PPC_WEAK_FUNC(sub_82414AE8);
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

__attribute__((alias("__imp__sub_82414AF4"))) PPC_WEAK_FUNC(sub_82414AF4);
PPC_FUNC_IMPL(__imp__sub_82414AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414AF8"))) PPC_WEAK_FUNC(sub_82414AF8);
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

__attribute__((alias("__imp__sub_82414B04"))) PPC_WEAK_FUNC(sub_82414B04);
PPC_FUNC_IMPL(__imp__sub_82414B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414B08"))) PPC_WEAK_FUNC(sub_82414B08);
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

__attribute__((alias("__imp__sub_82414B14"))) PPC_WEAK_FUNC(sub_82414B14);
PPC_FUNC_IMPL(__imp__sub_82414B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414B18"))) PPC_WEAK_FUNC(sub_82414B18);
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

__attribute__((alias("__imp__sub_82414B24"))) PPC_WEAK_FUNC(sub_82414B24);
PPC_FUNC_IMPL(__imp__sub_82414B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414B28"))) PPC_WEAK_FUNC(sub_82414B28);
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

__attribute__((alias("__imp__sub_82414B34"))) PPC_WEAK_FUNC(sub_82414B34);
PPC_FUNC_IMPL(__imp__sub_82414B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414B38"))) PPC_WEAK_FUNC(sub_82414B38);
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

__attribute__((alias("__imp__sub_82414B44"))) PPC_WEAK_FUNC(sub_82414B44);
PPC_FUNC_IMPL(__imp__sub_82414B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414B48"))) PPC_WEAK_FUNC(sub_82414B48);
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

__attribute__((alias("__imp__sub_82414B54"))) PPC_WEAK_FUNC(sub_82414B54);
PPC_FUNC_IMPL(__imp__sub_82414B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414B58"))) PPC_WEAK_FUNC(sub_82414B58);
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

__attribute__((alias("__imp__sub_82414B64"))) PPC_WEAK_FUNC(sub_82414B64);
PPC_FUNC_IMPL(__imp__sub_82414B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414B68"))) PPC_WEAK_FUNC(sub_82414B68);
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

__attribute__((alias("__imp__sub_82414B74"))) PPC_WEAK_FUNC(sub_82414B74);
PPC_FUNC_IMPL(__imp__sub_82414B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414B78"))) PPC_WEAK_FUNC(sub_82414B78);
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

__attribute__((alias("__imp__sub_82414BB8"))) PPC_WEAK_FUNC(sub_82414BB8);
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

__attribute__((alias("__imp__sub_82414BC4"))) PPC_WEAK_FUNC(sub_82414BC4);
PPC_FUNC_IMPL(__imp__sub_82414BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414BC8"))) PPC_WEAK_FUNC(sub_82414BC8);
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

__attribute__((alias("__imp__sub_82414C6C"))) PPC_WEAK_FUNC(sub_82414C6C);
PPC_FUNC_IMPL(__imp__sub_82414C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414C70"))) PPC_WEAK_FUNC(sub_82414C70);
PPC_FUNC_IMPL(__imp__sub_82414C70) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12028(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414C78"))) PPC_WEAK_FUNC(sub_82414C78);
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

__attribute__((alias("__imp__sub_82414D1C"))) PPC_WEAK_FUNC(sub_82414D1C);
PPC_FUNC_IMPL(__imp__sub_82414D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414D20"))) PPC_WEAK_FUNC(sub_82414D20);
PPC_FUNC_IMPL(__imp__sub_82414D20) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12032(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12032);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414D28"))) PPC_WEAK_FUNC(sub_82414D28);
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

__attribute__((alias("__imp__sub_82414DCC"))) PPC_WEAK_FUNC(sub_82414DCC);
PPC_FUNC_IMPL(__imp__sub_82414DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414DD0"))) PPC_WEAK_FUNC(sub_82414DD0);
PPC_FUNC_IMPL(__imp__sub_82414DD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12036(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12036);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414DD8"))) PPC_WEAK_FUNC(sub_82414DD8);
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

__attribute__((alias("__imp__sub_82414E7C"))) PPC_WEAK_FUNC(sub_82414E7C);
PPC_FUNC_IMPL(__imp__sub_82414E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414E80"))) PPC_WEAK_FUNC(sub_82414E80);
PPC_FUNC_IMPL(__imp__sub_82414E80) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12040(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12040);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414E88"))) PPC_WEAK_FUNC(sub_82414E88);
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

__attribute__((alias("__imp__sub_82414EAC"))) PPC_WEAK_FUNC(sub_82414EAC);
PPC_FUNC_IMPL(__imp__sub_82414EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414EB0"))) PPC_WEAK_FUNC(sub_82414EB0);
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

__attribute__((alias("__imp__sub_82414EC0"))) PPC_WEAK_FUNC(sub_82414EC0);
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

__attribute__((alias("__imp__sub_82414EE4"))) PPC_WEAK_FUNC(sub_82414EE4);
PPC_FUNC_IMPL(__imp__sub_82414EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414EE8"))) PPC_WEAK_FUNC(sub_82414EE8);
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

__attribute__((alias("__imp__sub_82414EF8"))) PPC_WEAK_FUNC(sub_82414EF8);
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

__attribute__((alias("__imp__sub_82414F1C"))) PPC_WEAK_FUNC(sub_82414F1C);
PPC_FUNC_IMPL(__imp__sub_82414F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414F20"))) PPC_WEAK_FUNC(sub_82414F20);
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

__attribute__((alias("__imp__sub_82414F2C"))) PPC_WEAK_FUNC(sub_82414F2C);
PPC_FUNC_IMPL(__imp__sub_82414F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414F30"))) PPC_WEAK_FUNC(sub_82414F30);
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

__attribute__((alias("__imp__sub_82414F54"))) PPC_WEAK_FUNC(sub_82414F54);
PPC_FUNC_IMPL(__imp__sub_82414F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414F58"))) PPC_WEAK_FUNC(sub_82414F58);
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

__attribute__((alias("__imp__sub_82414F64"))) PPC_WEAK_FUNC(sub_82414F64);
PPC_FUNC_IMPL(__imp__sub_82414F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414F68"))) PPC_WEAK_FUNC(sub_82414F68);
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

__attribute__((alias("__imp__sub_82414F84"))) PPC_WEAK_FUNC(sub_82414F84);
PPC_FUNC_IMPL(__imp__sub_82414F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414F88"))) PPC_WEAK_FUNC(sub_82414F88);
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

__attribute__((alias("__imp__sub_82414F94"))) PPC_WEAK_FUNC(sub_82414F94);
PPC_FUNC_IMPL(__imp__sub_82414F94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414F98"))) PPC_WEAK_FUNC(sub_82414F98);
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

__attribute__((alias("__imp__sub_82414FB4"))) PPC_WEAK_FUNC(sub_82414FB4);
PPC_FUNC_IMPL(__imp__sub_82414FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414FB8"))) PPC_WEAK_FUNC(sub_82414FB8);
PPC_FUNC_IMPL(__imp__sub_82414FB8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10456);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414FC0"))) PPC_WEAK_FUNC(sub_82414FC0);
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

__attribute__((alias("__imp__sub_82414FDC"))) PPC_WEAK_FUNC(sub_82414FDC);
PPC_FUNC_IMPL(__imp__sub_82414FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414FE0"))) PPC_WEAK_FUNC(sub_82414FE0);
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

__attribute__((alias("__imp__sub_82414FEC"))) PPC_WEAK_FUNC(sub_82414FEC);
PPC_FUNC_IMPL(__imp__sub_82414FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414FF0"))) PPC_WEAK_FUNC(sub_82414FF0);
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

__attribute__((alias("__imp__sub_8241500C"))) PPC_WEAK_FUNC(sub_8241500C);
PPC_FUNC_IMPL(__imp__sub_8241500C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415010"))) PPC_WEAK_FUNC(sub_82415010);
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

__attribute__((alias("__imp__sub_82415024"))) PPC_WEAK_FUNC(sub_82415024);
PPC_FUNC_IMPL(__imp__sub_82415024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415028"))) PPC_WEAK_FUNC(sub_82415028);
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

__attribute__((alias("__imp__sub_8241504C"))) PPC_WEAK_FUNC(sub_8241504C);
PPC_FUNC_IMPL(__imp__sub_8241504C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415050"))) PPC_WEAK_FUNC(sub_82415050);
PPC_FUNC_IMPL(__imp__sub_82415050) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10700(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10700);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415058"))) PPC_WEAK_FUNC(sub_82415058);
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

__attribute__((alias("__imp__sub_8241507C"))) PPC_WEAK_FUNC(sub_8241507C);
PPC_FUNC_IMPL(__imp__sub_8241507C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415080"))) PPC_WEAK_FUNC(sub_82415080);
PPC_FUNC_IMPL(__imp__sub_82415080) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10692);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415088"))) PPC_WEAK_FUNC(sub_82415088);
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

__attribute__((alias("__imp__sub_824150A4"))) PPC_WEAK_FUNC(sub_824150A4);
PPC_FUNC_IMPL(__imp__sub_824150A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824150A8"))) PPC_WEAK_FUNC(sub_824150A8);
PPC_FUNC_IMPL(__imp__sub_824150A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10704(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10704);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824150B0"))) PPC_WEAK_FUNC(sub_824150B0);
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

__attribute__((alias("__imp__sub_824150D4"))) PPC_WEAK_FUNC(sub_824150D4);
PPC_FUNC_IMPL(__imp__sub_824150D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824150D8"))) PPC_WEAK_FUNC(sub_824150D8);
PPC_FUNC_IMPL(__imp__sub_824150D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10696(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10696);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824150E0"))) PPC_WEAK_FUNC(sub_824150E0);
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

__attribute__((alias("__imp__sub_824150FC"))) PPC_WEAK_FUNC(sub_824150FC);
PPC_FUNC_IMPL(__imp__sub_824150FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415100"))) PPC_WEAK_FUNC(sub_82415100);
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

__attribute__((alias("__imp__sub_8241510C"))) PPC_WEAK_FUNC(sub_8241510C);
PPC_FUNC_IMPL(__imp__sub_8241510C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415110"))) PPC_WEAK_FUNC(sub_82415110);
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

__attribute__((alias("__imp__sub_82415164"))) PPC_WEAK_FUNC(sub_82415164);
PPC_FUNC_IMPL(__imp__sub_82415164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415168"))) PPC_WEAK_FUNC(sub_82415168);
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

__attribute__((alias("__imp__sub_82415174"))) PPC_WEAK_FUNC(sub_82415174);
PPC_FUNC_IMPL(__imp__sub_82415174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415178"))) PPC_WEAK_FUNC(sub_82415178);
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

__attribute__((alias("__imp__sub_82415194"))) PPC_WEAK_FUNC(sub_82415194);
PPC_FUNC_IMPL(__imp__sub_82415194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415198"))) PPC_WEAK_FUNC(sub_82415198);
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

__attribute__((alias("__imp__sub_824151A4"))) PPC_WEAK_FUNC(sub_824151A4);
PPC_FUNC_IMPL(__imp__sub_824151A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824151A8"))) PPC_WEAK_FUNC(sub_824151A8);
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

__attribute__((alias("__imp__sub_824151C4"))) PPC_WEAK_FUNC(sub_824151C4);
PPC_FUNC_IMPL(__imp__sub_824151C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824151C8"))) PPC_WEAK_FUNC(sub_824151C8);
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

__attribute__((alias("__imp__sub_824151D4"))) PPC_WEAK_FUNC(sub_824151D4);
PPC_FUNC_IMPL(__imp__sub_824151D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824151D8"))) PPC_WEAK_FUNC(sub_824151D8);
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

__attribute__((alias("__imp__sub_824151F4"))) PPC_WEAK_FUNC(sub_824151F4);
PPC_FUNC_IMPL(__imp__sub_824151F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824151F8"))) PPC_WEAK_FUNC(sub_824151F8);
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

__attribute__((alias("__imp__sub_82415204"))) PPC_WEAK_FUNC(sub_82415204);
PPC_FUNC_IMPL(__imp__sub_82415204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415208"))) PPC_WEAK_FUNC(sub_82415208);
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

__attribute__((alias("__imp__sub_8241521C"))) PPC_WEAK_FUNC(sub_8241521C);
PPC_FUNC_IMPL(__imp__sub_8241521C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415220"))) PPC_WEAK_FUNC(sub_82415220);
PPC_FUNC_IMPL(__imp__sub_82415220) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10562(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10562);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415228"))) PPC_WEAK_FUNC(sub_82415228);
PPC_FUNC_IMPL(__imp__sub_82415228) {
	PPC_FUNC_PROLOGUE();
	// stw r4,13596(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13596, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415230"))) PPC_WEAK_FUNC(sub_82415230);
PPC_FUNC_IMPL(__imp__sub_82415230) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,13596(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13596);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415238"))) PPC_WEAK_FUNC(sub_82415238);
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

__attribute__((alias("__imp__sub_82415248"))) PPC_WEAK_FUNC(sub_82415248);
PPC_FUNC_IMPL(__imp__sub_82415248) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwinm r3,r11,9,25,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x7F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415254"))) PPC_WEAK_FUNC(sub_82415254);
PPC_FUNC_IMPL(__imp__sub_82415254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415258"))) PPC_WEAK_FUNC(sub_82415258);
PPC_FUNC_IMPL(__imp__sub_82415258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82415260;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lbz r9,11924(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11924);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r8,7088
	ctx.r8.s64 = ctx.r8.s64 + 7088;
	// rlwinm r7,r5,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// lwz r31,12(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r30,1
	r30.s64 = 1;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// rlwinm r6,r6,22,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 22) & 0x1;
	// lwzx r8,r9,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwimi r29,r7,11,20,20
	r29.u64 = (__builtin_rotateleft32(ctx.r7.u32, 11) & 0x800) | (r29.u64 & 0xFFFFFFFFFFFFF7FF);
	// or r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
	// rldicr r6,r30,63,63
	ctx.r6.u64 = __builtin_rotateleft64(r30.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// clrldi r8,r4,32
	ctx.r8.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// srd r8,r6,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r8.u8 & 0x7F));
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r31,r9,21,9,10
	r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 21) & 0x600000) | (r31.u64 & 0xFFFFFFFFFF9FFFFF);
	// rlwimi r31,r9,21,4,6
	r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 21) & 0xE000000) | (r31.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// lbz r9,12002(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12002);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 0);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// rlwinm r10,r9,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwimi r6,r7,31,13,31
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FFFF) | (ctx.r6.u64 & 0xFFFFFFFFFFF80000);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwimi r6,r7,31,1,11
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FF00000) | (ctx.r6.u64 & 0xFFFFFFFF800FFFFF);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// rlwinm r7,r6,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFF;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwimi r10,r29,0,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(r29.u32, 0) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	r11.u64 = ctx.r8.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82415320"))) PPC_WEAK_FUNC(sub_82415320);
PPC_FUNC_IMPL(__imp__sub_82415320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r11,r10,21,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// rlwinm r10,r9,11,21,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0x7FF;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & r11.u64;
	// not r11,r11
	r11.u64 = ~r11.u64;
	// rlwimi r10,r11,0,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// clrlwi r3,r10,29
	ctx.r3.u64 = ctx.r10.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415354"))) PPC_WEAK_FUNC(sub_82415354);
PPC_FUNC_IMPL(__imp__sub_82415354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415358"))) PPC_WEAK_FUNC(sub_82415358);
PPC_FUNC_IMPL(__imp__sub_82415358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12002(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,31,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rldicr r5,r5,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r30,r31,31,13,31
	r30.u64 = (__builtin_rotateleft32(r31.u32, 31) & 0x7FFFF) | (r30.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r30,r31,31,1,11
	r30.u64 = (__builtin_rotateleft32(r31.u32, 31) & 0x7FF00000) | (r30.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r31,r30,13,20,31
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 13) & 0xFFF;
	// srd r7,r5,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r7.u8 & 0x7F));
	// and r9,r31,r9
	ctx.r9.u64 = r31.u64 & ctx.r9.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r11,12002
	ctx.r9.s64 = r11.s64 + 12002;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12002(r11)
	PPC_STORE_U8(r11.u32 + 12002, ctx.r6.u8);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r7,r11
	r11.u64 = ctx.r7.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824153EC"))) PPC_WEAK_FUNC(sub_824153EC);
PPC_FUNC_IMPL(__imp__sub_824153EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824153F0"))) PPC_WEAK_FUNC(sub_824153F0);
PPC_FUNC_IMPL(__imp__sub_824153F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12002(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// rlwinm r3,r11,31,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415400"))) PPC_WEAK_FUNC(sub_82415400);
PPC_FUNC_IMPL(__imp__sub_82415400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82415408;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lbz r9,11924(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11924);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r8,7088
	ctx.r8.s64 = ctx.r8.s64 + 7088;
	// rlwinm r7,r5,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// lwz r31,12(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r30,1
	r30.s64 = 1;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// rlwinm r6,r6,21,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 21) & 0x1;
	// lwzx r8,r9,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwimi r29,r7,10,21,21
	r29.u64 = (__builtin_rotateleft32(ctx.r7.u32, 10) & 0x400) | (r29.u64 & 0xFFFFFFFFFFFFFBFF);
	// or r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
	// rldicr r6,r30,63,63
	ctx.r6.u64 = __builtin_rotateleft64(r30.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// clrldi r8,r4,32
	ctx.r8.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// srd r8,r6,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r8.u8 & 0x7F));
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r31,r9,19,11,12
	r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 19) & 0x180000) | (r31.u64 & 0xFFFFFFFFFFE7FFFF);
	// rlwimi r31,r9,19,4,6
	r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 19) & 0xE000000) | (r31.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// lbz r9,12002(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12002);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(r31.u32, 0);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// rlwinm r10,r9,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwimi r6,r7,31,13,31
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FFFF) | (ctx.r6.u64 & 0xFFFFFFFFFFF80000);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwimi r6,r7,31,1,11
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FF00000) | (ctx.r6.u64 & 0xFFFFFFFF800FFFFF);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// rlwinm r7,r6,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFF;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwimi r10,r29,0,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(r29.u32, 0) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	r11.u64 = ctx.r8.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824154C8"))) PPC_WEAK_FUNC(sub_824154C8);
PPC_FUNC_IMPL(__imp__sub_824154C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r11,r10,22,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// rlwinm r10,r9,13,19,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1FFF;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & r11.u64;
	// not r11,r11
	r11.u64 = ~r11.u64;
	// rlwimi r10,r11,0,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// clrlwi r3,r10,29
	ctx.r3.u64 = ctx.r10.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824154FC"))) PPC_WEAK_FUNC(sub_824154FC);
PPC_FUNC_IMPL(__imp__sub_824154FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415500"))) PPC_WEAK_FUNC(sub_82415500);
PPC_FUNC_IMPL(__imp__sub_82415500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12002(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// li r8,1
	ctx.r8.s64 = 1;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rldicr r31,r8,63,63
	r31.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r5,r30,31,13,31
	ctx.r5.u64 = (__builtin_rotateleft32(r30.u32, 31) & 0x7FFFF) | (ctx.r5.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r5,r30,31,1,11
	ctx.r5.u64 = (__builtin_rotateleft32(r30.u32, 31) & 0x7FF00000) | (ctx.r5.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r30,r7,32
	r30.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r7,r5,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 13) & 0xFFF;
	// srd r5,r31,r30
	ctx.r5.u64 = r30.u8 & 0x40 ? 0 : (r31.u64 >> (r30.u8 & 0x7F));
	// and r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 & ctx.r9.u64;
	// addi r9,r11,12002
	ctx.r9.s64 = r11.s64 + 12002;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12002(r11)
	PPC_STORE_U8(r11.u32 + 12002, ctx.r6.u8);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r5,r11
	r11.u64 = ctx.r5.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241558C"))) PPC_WEAK_FUNC(sub_8241558C);
PPC_FUNC_IMPL(__imp__sub_8241558C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415590"))) PPC_WEAK_FUNC(sub_82415590);
PPC_FUNC_IMPL(__imp__sub_82415590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12002(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824155A0"))) PPC_WEAK_FUNC(sub_824155A0);
PPC_FUNC_IMPL(__imp__sub_824155A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwimi r8,r5,23,7,8
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 23) & 0x1800000) | (ctx.r8.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824155DC"))) PPC_WEAK_FUNC(sub_824155DC);
PPC_FUNC_IMPL(__imp__sub_824155DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824155E0"))) PPC_WEAK_FUNC(sub_824155E0);
PPC_FUNC_IMPL(__imp__sub_824155E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1164(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1164);
	// rlwinm r3,r11,9,30,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824155F4"))) PPC_WEAK_FUNC(sub_824155F4);
PPC_FUNC_IMPL(__imp__sub_824155F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824155F8"))) PPC_WEAK_FUNC(sub_824155F8);
PPC_FUNC_IMPL(__imp__sub_824155F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12002(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,30,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rldicr r5,r5,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r30,r31,31,13,31
	r30.u64 = (__builtin_rotateleft32(r31.u32, 31) & 0x7FFFF) | (r30.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r30,r31,31,1,11
	r30.u64 = (__builtin_rotateleft32(r31.u32, 31) & 0x7FF00000) | (r30.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r31,r30,13,20,31
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 13) & 0xFFF;
	// srd r7,r5,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r7.u8 & 0x7F));
	// and r9,r31,r9
	ctx.r9.u64 = r31.u64 & ctx.r9.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r11,12002
	ctx.r9.s64 = r11.s64 + 12002;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12002(r11)
	PPC_STORE_U8(r11.u32 + 12002, ctx.r6.u8);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r7,r11
	r11.u64 = ctx.r7.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241568C"))) PPC_WEAK_FUNC(sub_8241568C);
PPC_FUNC_IMPL(__imp__sub_8241568C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415690"))) PPC_WEAK_FUNC(sub_82415690);
PPC_FUNC_IMPL(__imp__sub_82415690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12002(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12002);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824156A0"))) PPC_WEAK_FUNC(sub_824156A0);
PPC_FUNC_IMPL(__imp__sub_824156A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm. r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x824156c0
	if (!cr0.eq) goto loc_824156C0;
	// rlwinm. r10,r10,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824156fc
	if (cr0.eq) goto loc_824156FC;
loc_824156C0:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,7088
	ctx.r10.s64 = ctx.r10.s64 + 7088;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// li r6,1
	ctx.r6.s64 = 1;
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rldicr r6,r6,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// srd r8,r6,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r7.u8 & 0x7F));
	// rlwimi r9,r10,25,4,6
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 25) & 0xE000000) | (ctx.r9.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	r11.u64 = ctx.r8.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
loc_824156FC:
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,11924(r11)
	PPC_STORE_U8(r11.u32 + 11924, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415708"))) PPC_WEAK_FUNC(sub_82415708);
PPC_FUNC_IMPL(__imp__sub_82415708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,11924(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 11924);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415714"))) PPC_WEAK_FUNC(sub_82415714);
PPC_FUNC_IMPL(__imp__sub_82415714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415718"))) PPC_WEAK_FUNC(sub_82415718);
PPC_FUNC_IMPL(__imp__sub_82415718) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r5,36(r1)
	PPC_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lfs f0,7156(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7156);
	f0.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r10,r10,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// srd r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r9.u8 & 0x7F));
	// lfs f13,36(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwimi r8,r9,5,23,26
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x1E0) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFE1F);
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415774"))) PPC_WEAK_FUNC(sub_82415774);
PPC_FUNC_IMPL(__imp__sub_82415774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415778"))) PPC_WEAK_FUNC(sub_82415778);
PPC_FUNC_IMPL(__imp__sub_82415778) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,1172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1172);
	// lfs f0,12424(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12424);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r11,23,0,8
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 23) & 0xFF800000;
	// srawi r11,r11,28
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xFFFFFFF) != 0);
	r11.s64 = r11.s32 >> 28;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824157BC"))) PPC_WEAK_FUNC(sub_824157BC);
PPC_FUNC_IMPL(__imp__sub_824157BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824157C0"))) PPC_WEAK_FUNC(sub_824157C0);
PPC_FUNC_IMPL(__imp__sub_824157C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r5,36(r1)
	PPC_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lfs f0,-10992(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -10992);
	f0.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r10,r10,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// srd r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r9.u8 & 0x7F));
	// lfs f13,36(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwimi r8,r9,12,10,19
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 12) & 0x3FF000) | (ctx.r8.u64 & 0xFFFFFFFFFFC00FFF);
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241581C"))) PPC_WEAK_FUNC(sub_8241581C);
PPC_FUNC_IMPL(__imp__sub_8241581C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415820"))) PPC_WEAK_FUNC(sub_82415820);
PPC_FUNC_IMPL(__imp__sub_82415820) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lwz r11,1168(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1168);
	// lfs f0,7160(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7160);
	f0.f64 = double(temp.f32);
	// rlwinm r11,r11,10,0,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// srawi r11,r11,22
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FFFFF) != 0);
	r11.s64 = r11.s32 >> 22;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
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

__attribute__((alias("__imp__sub_82415860"))) PPC_WEAK_FUNC(sub_82415860);
PPC_FUNC_IMPL(__imp__sub_82415860) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,3136
	r11.s64 = ctx.r4.s64 + 3136;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824158c0
	if (cr6.eq) goto loc_824158C0;
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r11,r11,30,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0xF;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// bgt cr6,0x82415894
	if (cr6.gt) goto loc_82415894;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_82415894:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwimi r9,r11,2,26,29
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 2) & 0x3C) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFC3);
	// rldicr r11,r7,63,63
	r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// clrldi r10,r8,32
	ctx.r10.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// srd r11,r11,r10
	r11.u64 = ctx.r10.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r10.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
loc_824158C0:
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,11950(r11)
	PPC_STORE_U8(r11.u32 + 11950, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824158CC"))) PPC_WEAK_FUNC(sub_824158CC);
PPC_FUNC_IMPL(__imp__sub_824158CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824158D0"))) PPC_WEAK_FUNC(sub_824158D0);
PPC_FUNC_IMPL(__imp__sub_824158D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,11950(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 11950);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824158DC"))) PPC_WEAK_FUNC(sub_824158DC);
PPC_FUNC_IMPL(__imp__sub_824158DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824158E0"))) PPC_WEAK_FUNC(sub_824158E0);
PPC_FUNC_IMPL(__imp__sub_824158E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,3136
	r11.s64 = ctx.r4.s64 + 3136;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82415940
	if (cr6.eq) goto loc_82415940;
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r11,r11,26,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0xF;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// blt cr6,0x82415914
	if (cr6.lt) goto loc_82415914;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_82415914:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwimi r9,r11,6,22,25
	ctx.r9.u64 = (__builtin_rotateleft32(r11.u32, 6) & 0x3C0) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFC3F);
	// rldicr r11,r7,63,63
	r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// clrldi r10,r8,32
	ctx.r10.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// srd r11,r11,r10
	r11.u64 = ctx.r10.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r10.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
loc_82415940:
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,11976(r11)
	PPC_STORE_U8(r11.u32 + 11976, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241594C"))) PPC_WEAK_FUNC(sub_8241594C);
PPC_FUNC_IMPL(__imp__sub_8241594C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415950"))) PPC_WEAK_FUNC(sub_82415950);
PPC_FUNC_IMPL(__imp__sub_82415950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,11976(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 11976);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241595C"))) PPC_WEAK_FUNC(sub_8241595C);
PPC_FUNC_IMPL(__imp__sub_8241595C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82415960"))) PPC_WEAK_FUNC(sub_82415960);
PPC_FUNC_IMPL(__imp__sub_82415960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// cntlzw r10,r5
	ctx.r10.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// li r8,1
	ctx.r8.s64 = 1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r8,r8,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r7,r7,0,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// srd r9,r8,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r9.u8 & 0x7F));
	// or r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 | ctx.r7.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824159AC"))) PPC_WEAK_FUNC(sub_824159AC);
PPC_FUNC_IMPL(__imp__sub_824159AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824159B0"))) PPC_WEAK_FUNC(sub_824159B0);
PPC_FUNC_IMPL(__imp__sub_824159B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mulli r11,r4,24
	r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r11,1172(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1172);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// subfic r11,r11,0
	xer.ca = r11.u32 <= 0;
	r11.s64 = 0 - r11.s64;
	// subfe r3,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r3.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824159CC"))) PPC_WEAK_FUNC(sub_824159CC);
PPC_FUNC_IMPL(__imp__sub_824159CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824159D0"))) PPC_WEAK_FUNC(sub_824159D0);
PPC_FUNC_IMPL(__imp__sub_824159D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lwzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwimi r9,r5,10,19,21
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 10) & 0x1C00) | (ctx.r9.u64 & 0xFFFFFFFFFFFFE3FF);
	// li r8,1
	ctx.r8.s64 = 1;
	// stwx r9,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// clrldi r11,r10,32
	r11.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r10,r8,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r11,r10,r11
	r11.u64 = r11.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (r11.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415A08"))) PPC_WEAK_FUNC(sub_82415A08);
PPC_FUNC_IMPL(__imp__sub_82415A08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// rlwinm r3,r11,22,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82415A1C"))) PPC_WEAK_FUNC(sub_82415A1C);
PPC_FUNC_IMPL(__imp__sub_82415A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

