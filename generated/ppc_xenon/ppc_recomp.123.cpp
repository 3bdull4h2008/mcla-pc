#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8260B4C0"))) PPC_WEAK_FUNC(sub_8260B4C0);
PPC_FUNC_IMPL(__imp__sub_8260B4C0) {
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
	// bl 0x8260b420
	ctx.lr = 0x8260B4E0;
	sub_8260B420(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260b4f8
	if (cr6.eq) goto loc_8260B4F8;
	// bl 0x82130588
	ctx.lr = 0x8260B4F4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8260B4F8:
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

__attribute__((alias("__imp__sub_8260B510"))) PPC_WEAK_FUNC(sub_8260B510);
PPC_FUNC_IMPL(__imp__sub_8260B510) {
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
	// bl 0x8260b310
	ctx.lr = 0x8260B530;
	sub_8260B310(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r31,52
	ctx.r4.s64 = r31.s64 + 52;
	// addi r10,r11,-30660
	ctx.r10.s64 = r11.s64 + -30660;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8260b398
	ctx.lr = 0x8260B54C;
	sub_8260B398(ctx, base);
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8260b56c
	if (cr6.eq) goto loc_8260B56C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8260B560;
	sub_8217D890(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r10.u32);
loc_8260B56C:
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

__attribute__((alias("__imp__sub_8260B588"))) PPC_WEAK_FUNC(sub_8260B588);
PPC_FUNC_IMPL(__imp__sub_8260B588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lbz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x8260b5f8
	if (cr6.gt) goto loc_8260B5F8;
	// lis r12,-32159
	r12.s64 = -2107572224;
	// addi r12,r12,-19020
	r12.s64 = r12.s64 + -19020;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8260B5C8;
	case 1:
		goto loc_8260B5D0;
	case 2:
		goto loc_8260B5D8;
	case 3:
		goto loc_8260B5E8;
	case 4:
		goto loc_8260B5F0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-19000(0)
	r19.u64 = PPC_LOAD_U32(-19000);
	// lwz r19,-18992(0)
	r19.u64 = PPC_LOAD_U32(-18992);
	// lwz r19,-18984(0)
	r19.u64 = PPC_LOAD_U32(-18984);
	// lwz r19,-18968(0)
	r19.u64 = PPC_LOAD_U32(-18968);
	// lwz r19,-18960(0)
	r19.u64 = PPC_LOAD_U32(-18960);
loc_8260B5C8:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x8260b310
	sub_8260B310(ctx, base);
	return;
loc_8260B5D0:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x8260b510
	sub_8260B510(ctx, base);
	return;
loc_8260B5D8:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,-30740
	ctx.r10.s64 = r11.s64 + -30740;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
loc_8260B5E8:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x8260aea8
	sub_8260AEA8(ctx, base);
	return;
loc_8260B5F0:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x8260af70
	sub_8260AF70(ctx, base);
	return;
loc_8260B5F8:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-30636
	ctx.r3.s64 = r11.s64 + -30636;
	// b 0x821bd618
	sub_821BD618(ctx, base);
	return;
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260B608"))) PPC_WEAK_FUNC(sub_8260B608);
PPC_FUNC_IMPL(__imp__sub_8260B608) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-30600
	ctx.r10.s64 = r11.s64 + -30600;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8260B634;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8260b64c
	if (cr6.eq) goto loc_8260B64C;
	// bl 0x82130588
	ctx.lr = 0x8260B648;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8260B64C:
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

__attribute__((alias("__imp__sub_8260B664"))) PPC_WEAK_FUNC(sub_8260B664);
PPC_FUNC_IMPL(__imp__sub_8260B664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260B668"))) PPC_WEAK_FUNC(sub_8260B668);
PPC_FUNC_IMPL(__imp__sub_8260B668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,128
	r11.s64 = 128;
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,19(r3)
	PPC_STORE_U8(ctx.r3.u32 + 19, r11.u8);
	// stb r11,18(r3)
	PPC_STORE_U8(ctx.r3.u32 + 18, r11.u8);
	// stb r11,17(r3)
	PPC_STORE_U8(ctx.r3.u32 + 17, r11.u8);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8260B69C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8260b69c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8260B69C;
	// li r11,512
	r11.s64 = 512;
	// addi r10,r3,36
	ctx.r10.s64 = ctx.r3.s64 + 36;
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, r11.u16);
	// sth r11,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, r11.u16);
	// sth r11,40(r3)
	PPC_STORE_U16(ctx.r3.u32 + 40, r11.u16);
	// sth r11,42(r3)
	PPC_STORE_U16(ctx.r3.u32 + 42, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260B6C4"))) PPC_WEAK_FUNC(sub_8260B6C4);
PPC_FUNC_IMPL(__imp__sub_8260B6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260B6C8"))) PPC_WEAK_FUNC(sub_8260B6C8);
PPC_FUNC_IMPL(__imp__sub_8260B6C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r4,45(r3)
	PPC_STORE_U8(ctx.r3.u32 + 45, ctx.r4.u8);
	// stb r11,46(r3)
	PPC_STORE_U8(ctx.r3.u32 + 46, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260B6D8"))) PPC_WEAK_FUNC(sub_8260B6D8);
PPC_FUNC_IMPL(__imp__sub_8260B6D8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x8260b6f8
	if (cr6.lt) goto loc_8260B6F8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8260b6fc
	if (!cr6.gt) goto loc_8260B6FC;
loc_8260B6F8:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
loc_8260B6FC:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r4,29
	ctx.r10.s64 = ctx.r4.s64 + 29;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f0,-18104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18104);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lhz r7,-10(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// sthx r7,r8,r3
	PPC_STORE_U16(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u16);
	// stb r9,46(r3)
	PPC_STORE_U8(ctx.r3.u32 + 46, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260B72C"))) PPC_WEAK_FUNC(sub_8260B72C);
PPC_FUNC_IMPL(__imp__sub_8260B72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260B730"))) PPC_WEAK_FUNC(sub_8260B730);
PPC_FUNC_IMPL(__imp__sub_8260B730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260B740"))) PPC_WEAK_FUNC(sub_8260B740);
PPC_FUNC_IMPL(__imp__sub_8260B740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// rlwinm r9,r7,24,0,7
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFF000000;
	// or r7,r9,r5
	ctx.r7.u64 = ctx.r9.u64 | ctx.r5.u64;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r4,r5,r10
	PPC_STORE_U32(ctx.r5.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r4,r11,66
	ctx.r4.s64 = r11.s64 + 66;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r3,r10
	PPC_STORE_U32(ctx.r3.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,130
	r11.s64 = r11.s64 + 130;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260B78C"))) PPC_WEAK_FUNC(sub_8260B78C);
PPC_FUNC_IMPL(__imp__sub_8260B78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260B790"))) PPC_WEAK_FUNC(sub_8260B790);
PPC_FUNC_IMPL(__imp__sub_8260B790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// oris r8,r6,65280
	ctx.r8.u64 = ctx.r6.u64 | 4278190080;
	// oris r9,r5,65280
	ctx.r9.u64 = ctx.r5.u64 | 4278190080;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r4,r5,r10
	PPC_STORE_U32(ctx.r5.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r3,r11,66
	ctx.r3.s64 = r11.s64 + 66;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r11,130
	ctx.r9.s64 = r11.s64 + 130;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r4,r3,r10
	PPC_STORE_U32(ctx.r3.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,66
	r11.s64 = r11.s64 + 66;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r11,130
	ctx.r8.s64 = r11.s64 + 130;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260B814"))) PPC_WEAK_FUNC(sub_8260B814);
PPC_FUNC_IMPL(__imp__sub_8260B814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260B818"))) PPC_WEAK_FUNC(sub_8260B818);
PPC_FUNC_IMPL(__imp__sub_8260B818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r8,r3,8
	ctx.r8.s64 = ctx.r3.s64 + 8;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lwz r9,256(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 256);
	// li r11,0
	r11.s64 = 0;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// clrlwi r9,r9,8
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFFFF;
	// cmplwi cr6,r10,15
	cr6.compare<uint32_t>(ctx.r10.u32, 15, xer);
	// bgt cr6,0x8260b958
	if (cr6.gt) goto loc_8260B958;
	// lis r12,-32159
	r12.s64 = -2107572224;
	// addi r12,r12,-18336
	r12.s64 = r12.s64 + -18336;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_8260B94C;
	case 1:
		goto loc_8260B954;
	case 2:
		goto loc_8260B954;
	case 3:
		goto loc_8260B94C;
	case 4:
		goto loc_8260B94C;
	case 5:
		goto loc_8260B8A0;
	case 6:
		goto loc_8260B94C;
	case 7:
		goto loc_8260B94C;
	case 8:
		goto loc_8260B94C;
	case 9:
		goto loc_8260B8B4;
	case 10:
		goto loc_8260B958;
	case 11:
		goto loc_8260B958;
	case 12:
		goto loc_8260B958;
	case 13:
		goto loc_8260B94C;
	case 14:
		goto loc_8260B954;
	case 15:
		goto loc_8260B954;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18272(0)
	r19.u64 = PPC_LOAD_U32(-18272);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18252(0)
	r19.u64 = PPC_LOAD_U32(-18252);
	// lwz r19,-18088(0)
	r19.u64 = PPC_LOAD_U32(-18088);
	// lwz r19,-18088(0)
	r19.u64 = PPC_LOAD_U32(-18088);
	// lwz r19,-18088(0)
	r19.u64 = PPC_LOAD_U32(-18088);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
loc_8260B8A0:
	// lbz r10,21792(r6)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r6.u32 + 21792);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8260b958
	if (cr6.eq) goto loc_8260B958;
	// li r11,0
	r11.s64 = 0;
	// b 0x8260b958
	goto loc_8260B958;
loc_8260B8B4:
	// cmplwi cr6,r9,29
	cr6.compare<uint32_t>(ctx.r9.u32, 29, xer);
	// bgt cr6,0x8260b958
	if (cr6.gt) goto loc_8260B958;
	// lis r12,-32159
	r12.s64 = -2107572224;
	// addi r12,r12,-18220
	r12.s64 = r12.s64 + -18220;
	// rlwinm r0,r9,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r9.u64) {
	case 0:
		goto loc_8260B954;
	case 1:
		goto loc_8260B954;
	case 2:
		goto loc_8260B954;
	case 3:
		goto loc_8260B954;
	case 4:
		goto loc_8260B94C;
	case 5:
		goto loc_8260B94C;
	case 6:
		goto loc_8260B94C;
	case 7:
		goto loc_8260B94C;
	case 8:
		goto loc_8260B94C;
	case 9:
		goto loc_8260B94C;
	case 10:
		goto loc_8260B94C;
	case 11:
		goto loc_8260B94C;
	case 12:
		goto loc_8260B94C;
	case 13:
		goto loc_8260B94C;
	case 14:
		goto loc_8260B94C;
	case 15:
		goto loc_8260B94C;
	case 16:
		goto loc_8260B94C;
	case 17:
		goto loc_8260B94C;
	case 18:
		goto loc_8260B94C;
	case 19:
		goto loc_8260B94C;
	case 20:
		goto loc_8260B954;
	case 21:
		goto loc_8260B954;
	case 22:
		goto loc_8260B94C;
	case 23:
		goto loc_8260B94C;
	case 24:
		goto loc_8260B94C;
	case 25:
		goto loc_8260B94C;
	case 26:
		goto loc_8260B94C;
	case 27:
		goto loc_8260B94C;
	case 28:
		goto loc_8260B94C;
	case 29:
		goto loc_8260B94C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18092(0)
	r19.u64 = PPC_LOAD_U32(-18092);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
	// lwz r19,-18100(0)
	r19.u64 = PPC_LOAD_U32(-18100);
loc_8260B94C:
	// li r11,0
	r11.s64 = 0;
	// b 0x8260b958
	goto loc_8260B958;
loc_8260B954:
	// li r11,128
	r11.s64 = 128;
loc_8260B958:
	// lwz r10,512(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 512);
}

__attribute__((alias("__imp__sub_8260B990"))) PPC_WEAK_FUNC(sub_8260B990);
PPC_FUNC_IMPL(__imp__sub_8260B990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x8260B998;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823db9d4
	ctx.lr = 0x8260B9A0;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lbz r11,21640(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 21640);
	// lwz r9,0(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// stb r6,21640(r10)
	PPC_STORE_U8(ctx.r10.u32 + 21640, ctx.r6.u8);
	// ble cr6,0x8260ba58
	if (!cr6.gt) goto loc_8260BA58;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// addi r8,r23,520
	ctx.r8.s64 = r23.s64 + 520;
loc_8260B9D8:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// beq cr6,0x8260ba44
	if (cr6.eq) goto loc_8260BA44;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stb r29,2(r11)
	PPC_STORE_U8(r11.u32 + 2, r29.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r10,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r10.u8);
	// beq cr6,0x8260ba40
	if (cr6.eq) goto loc_8260BA40;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// stb r3,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r3.u8);
	// cmplwi cr6,r3,64
	cr6.compare<uint32_t>(ctx.r3.u32, 64, xer);
	// bge cr6,0x8260ba20
	if (!cr6.lt) goto loc_8260BA20;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
loc_8260BA20:
	// rlwinm r3,r10,3,21,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x7F8;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stbx r29,r3,r9
	PPC_STORE_U8(ctx.r3.u32 + ctx.r9.u32, r29.u8);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// rotlwi r9,r9,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
loc_8260BA40:
	// stb r6,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r6.u8);
loc_8260BA44:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x8260b9d8
	if (cr6.lt) goto loc_8260B9D8;
loc_8260BA58:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r26,r29
	r26.u64 = r29.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8260c404
	if (!cr6.gt) goto loc_8260C404;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f30,-30588(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -30588);
	f30.f64 = double(temp.f32);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f28,-32032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -32032);
	f28.f64 = double(temp.f32);
	// lfs f31,31956(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31956);
	f31.f64 = double(temp.f32);
	// li r25,1
	r25.s64 = 1;
	// lfs f29,18892(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 18892);
	f29.f64 = double(temp.f32);
	// lis r16,-32112
	r16.s64 = -2104492032;
	// lfs f27,15360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 15360);
	f27.f64 = double(temp.f32);
	// lis r15,-32112
	r15.s64 = -2104492032;
	// lis r24,-32112
	r24.s64 = -2104492032;
	// lis r22,-32112
	r22.s64 = -2104492032;
	// lis r21,-32112
	r21.s64 = -2104492032;
	// lis r20,-32122
	r20.s64 = -2105147392;
	// lis r19,-32112
	r19.s64 = -2104492032;
	// lis r18,-32122
	r18.s64 = -2105147392;
	// lis r17,-32112
	r17.s64 = -2104492032;
	// lis r27,-32112
	r27.s64 = -2104492032;
	// addi r30,r11,21384
	r30.s64 = r11.s64 + 21384;
	// addi r28,r10,21816
	r28.s64 = ctx.r10.s64 + 21816;
loc_8260BACC:
	// addi r10,r26,66
	ctx.r10.s64 = r26.s64 + 66;
	// mr r11,r29
	r11.u64 = r29.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r23
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r23.u32);
	// srawi r10,r8,24
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFFF) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 24;
	// clrlwi r9,r8,8
	ctx.r9.u64 = ctx.r8.u32 & 0xFFFFFF;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x8260baf0
	if (!cr6.eq) goto loc_8260BAF0;
	// lwz r10,4(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 4);
loc_8260BAF0:
	// addi r8,r26,2
	ctx.r8.s64 = r26.s64 + 2;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r7,r23
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + r23.u32);
	// cmplwi cr6,r8,15
	cr6.compare<uint32_t>(ctx.r8.u32, 15, xer);
	// bgt cr6,0x8260c39c
	if (cr6.gt) goto loc_8260C39C;
	// lis r12,-32159
	r12.s64 = -2107572224;
	// addi r12,r12,-17636
	r12.s64 = r12.s64 + -17636;
	// rlwinm r0,r8,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r8.u64) {
	case 0:
		goto loc_8260BB5C;
	case 1:
		goto loc_8260BC28;
	case 2:
		goto loc_8260BCA0;
	case 3:
		goto loc_8260BCC8;
	case 4:
		goto loc_8260BD24;
	case 5:
		goto loc_8260BCE0;
	case 6:
		goto loc_8260BD3C;
	case 7:
		goto loc_8260BD5C;
	case 8:
		goto loc_8260BD7C;
	case 9:
		goto loc_8260BDB4;
	case 10:
		goto loc_8260C39C;
	case 11:
		goto loc_8260C39C;
	case 12:
		goto loc_8260C39C;
	case 13:
		goto loc_8260BBC0;
	case 14:
		goto loc_8260BB7C;
	case 15:
		goto loc_8260BBD8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-17572(0)
	r19.u64 = PPC_LOAD_U32(-17572);
	// lwz r19,-17368(0)
	r19.u64 = PPC_LOAD_U32(-17368);
	// lwz r19,-17248(0)
	r19.u64 = PPC_LOAD_U32(-17248);
	// lwz r19,-17208(0)
	r19.u64 = PPC_LOAD_U32(-17208);
	// lwz r19,-17116(0)
	r19.u64 = PPC_LOAD_U32(-17116);
	// lwz r19,-17184(0)
	r19.u64 = PPC_LOAD_U32(-17184);
	// lwz r19,-17092(0)
	r19.u64 = PPC_LOAD_U32(-17092);
	// lwz r19,-17060(0)
	r19.u64 = PPC_LOAD_U32(-17060);
	// lwz r19,-17028(0)
	r19.u64 = PPC_LOAD_U32(-17028);
	// lwz r19,-16972(0)
	r19.u64 = PPC_LOAD_U32(-16972);
	// lwz r19,-15460(0)
	r19.u64 = PPC_LOAD_U32(-15460);
	// lwz r19,-15460(0)
	r19.u64 = PPC_LOAD_U32(-15460);
	// lwz r19,-15460(0)
	r19.u64 = PPC_LOAD_U32(-15460);
	// lwz r19,-17472(0)
	r19.u64 = PPC_LOAD_U32(-17472);
	// lwz r19,-17540(0)
	r19.u64 = PPC_LOAD_U32(-17540);
	// lwz r19,-17448(0)
	r19.u64 = PPC_LOAD_U32(-17448);
loc_8260BB5C:
	// lwz r11,22584(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22584);
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lbzx r9,r10,r28
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r28.u32);
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BB7C:
	// lwz r11,22584(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22584);
	// rlwinm r10,r9,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// lbzx r8,r10,r28
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r28.u32);
	// lbzx r7,r9,r28
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + r28.u32);
	// subfic r6,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r8.s64;
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// subfe r4,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// rlwinm r11,r4,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	// xori r10,r3,1
	ctx.r10.u64 = ctx.r3.u64 ^ 1;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8260bbc8
	if (!cr6.eq) goto loc_8260BBC8;
loc_8260BBC0:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BBC8:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8260c24c
	if (!cr6.eq) goto loc_8260C24C;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BBD8:
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// rlwinm r8,r9,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// slw r6,r25,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r8.u8 & 0x3F));
	// lwzx r5,r11,r10
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// slw r4,r25,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r7.u8 & 0x3F));
	// and r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 & ctx.r5.u64;
	// and r11,r4,r5
	r11.u64 = ctx.r4.u64 & ctx.r5.u64;
	// subfic r10,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r3.s64;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfe r8,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r6,r8,0,30,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// or r11,r6,r5
	r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8260bbc8
	if (!cr6.eq) goto loc_8260BBC8;
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BC28:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8260bc64
	if (!cr6.eq) goto loc_8260BC64;
	// lwz r11,21772(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 21772);
	// lfs f0,2756(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r18.u32 + 2756);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f9,f10,f27
	ctx.f9.f64 = double(float(ctx.f10.f64 * f27.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f8.u64);
	// lbz r11,95(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BC64:
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x8260c39c
	if (!cr6.eq) goto loc_8260C39C;
	// lwz r11,21784(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 21784);
	// lfs f0,2764(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 2764);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f9,f10,f27
	ctx.f9.f64 = double(float(ctx.f10.f64 * f27.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f8.u64);
	// lbz r11,95(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BCA0:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8260bcb4
	if (!cr6.eq) goto loc_8260BCB4;
	// lwz r11,21796(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 21796);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260BCB4:
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x8260c39c
	if (!cr6.eq) goto loc_8260C39C;
	// lwz r11,21776(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 21776);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260BCC8:
	// lwz r11,21788(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 21788);
	// and r10,r11,r9
	ctx.r10.u64 = r11.u64 & ctx.r9.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8260bbc0
	if (!cr6.eq) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BCE0:
	// lbz r8,21792(r15)
	ctx.r8.u64 = PPC_LOAD_U8(r15.u32 + 21792);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8260c39c
	if (cr6.eq) goto loc_8260C39C;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8260bd08
	if (!cr6.eq) goto loc_8260BD08;
	// lwz r11,21800(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 21800);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BD08:
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x8260c39c
	if (!cr6.eq) goto loc_8260C39C;
	// lwz r11,21800(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 21800);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BD24:
	// lwz r11,21788(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 21788);
	// and r10,r11,r9
	ctx.r10.u64 = r11.u64 & ctx.r9.u64;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BD3C:
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplw cr6,r7,r9
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, xer);
	// bne cr6,0x8260bbc0
	if (!cr6.eq) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BD5C:
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// subfic r6,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BD7C:
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r30,20
	r11.s64 = r30.s64 + 20;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbzx r11,r8,r11
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8260c39c
	if (!cr6.eq) goto loc_8260C39C;
	// addi r11,r30,8
	r11.s64 = r30.s64 + 8;
	// slw r9,r25,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r25.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// subfic r6,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BDB4:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8260bdcc
	if (!cr6.eq) goto loc_8260BDCC;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,16
	ctx.r10.s64 = r30.s64 + 16;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BDCC:
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x8260bde4
	if (!cr6.eq) goto loc_8260BDE4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,17
	ctx.r10.s64 = r30.s64 + 17;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BDE4:
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x8260bdfc
	if (!cr6.eq) goto loc_8260BDFC;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,18
	ctx.r10.s64 = r30.s64 + 18;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BDFC:
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// bne cr6,0x8260be14
	if (!cr6.eq) goto loc_8260BE14;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,19
	ctx.r10.s64 = r30.s64 + 19;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BE14:
	// cmplwi cr6,r9,4
	cr6.compare<uint32_t>(ctx.r9.u32, 4, xer);
	// bne cr6,0x8260be54
	if (!cr6.eq) goto loc_8260BE54;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x8260BE2C;
	sub_8221CBF8(ctx, base);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8260BE3C;
	sub_8221CBA0(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BE54:
	// cmplwi cr6,r9,5
	cr6.compare<uint32_t>(ctx.r9.u32, 5, xer);
	// bne cr6,0x8260be94
	if (!cr6.eq) goto loc_8260BE94;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x8260BE6C;
	sub_8221CBF8(ctx, base);
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f28.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8260BE7C;
	sub_8221CBA0(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BE94:
	// cmplwi cr6,r9,6
	cr6.compare<uint32_t>(ctx.r9.u32, 6, xer);
	// bne cr6,0x8260bed4
	if (!cr6.eq) goto loc_8260BED4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8260BEAC;
	sub_8221CBA0(ctx, base);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x8260BEBC;
	sub_8221CBF8(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BED4:
	// cmplwi cr6,r9,7
	cr6.compare<uint32_t>(ctx.r9.u32, 7, xer);
	// bne cr6,0x8260bf14
	if (!cr6.eq) goto loc_8260BF14;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8260BEEC;
	sub_8221CBA0(ctx, base);
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f28.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x8260BEFC;
	sub_8221CBF8(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BF14:
	// cmplwi cr6,r9,8
	cr6.compare<uint32_t>(ctx.r9.u32, 8, xer);
	// bne cr6,0x8260bf4c
	if (!cr6.eq) goto loc_8260BF4C;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x8260BF2C;
	sub_8221CBF8(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8260BF3C;
	sub_8221CBA0(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BF4C:
	// cmplwi cr6,r9,9
	cr6.compare<uint32_t>(ctx.r9.u32, 9, xer);
	// bne cr6,0x8260bf84
	if (!cr6.eq) goto loc_8260BF84;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x8260BF64;
	sub_8221CBF8(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8260BF74;
	sub_8221CBA0(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BF84:
	// cmplwi cr6,r9,10
	cr6.compare<uint32_t>(ctx.r9.u32, 10, xer);
	// bne cr6,0x8260bfbc
	if (!cr6.eq) goto loc_8260BFBC;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x8260BF9C;
	sub_8221CBF8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8260BFAC;
	sub_8221CBA0(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BFBC:
	// cmplwi cr6,r9,11
	cr6.compare<uint32_t>(ctx.r9.u32, 11, xer);
	// bne cr6,0x8260bff4
	if (!cr6.eq) goto loc_8260BFF4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x8260BFD4;
	sub_8221CBF8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8260BFE4;
	sub_8221CBA0(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260BFF4:
	// cmplwi cr6,r9,12
	cr6.compare<uint32_t>(ctx.r9.u32, 12, xer);
	// bne cr6,0x8260c034
	if (!cr6.eq) goto loc_8260C034;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cca8
	ctx.lr = 0x8260C00C;
	sub_8221CCA8(ctx, base);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cc50
	ctx.lr = 0x8260C01C;
	sub_8221CC50(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C034:
	// cmplwi cr6,r9,13
	cr6.compare<uint32_t>(ctx.r9.u32, 13, xer);
	// bne cr6,0x8260c074
	if (!cr6.eq) goto loc_8260C074;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cca8
	ctx.lr = 0x8260C04C;
	sub_8221CCA8(ctx, base);
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f28.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cc50
	ctx.lr = 0x8260C05C;
	sub_8221CC50(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C074:
	// cmplwi cr6,r9,14
	cr6.compare<uint32_t>(ctx.r9.u32, 14, xer);
	// bne cr6,0x8260c0b4
	if (!cr6.eq) goto loc_8260C0B4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cc50
	ctx.lr = 0x8260C08C;
	sub_8221CC50(ctx, base);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cca8
	ctx.lr = 0x8260C09C;
	sub_8221CCA8(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C0B4:
	// cmplwi cr6,r9,15
	cr6.compare<uint32_t>(ctx.r9.u32, 15, xer);
	// bne cr6,0x8260c0f4
	if (!cr6.eq) goto loc_8260C0F4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cc50
	ctx.lr = 0x8260C0CC;
	sub_8221CC50(ctx, base);
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f28.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cca8
	ctx.lr = 0x8260C0DC;
	sub_8221CCA8(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C0F4:
	// cmplwi cr6,r9,16
	cr6.compare<uint32_t>(ctx.r9.u32, 16, xer);
	// bne cr6,0x8260c12c
	if (!cr6.eq) goto loc_8260C12C;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cca8
	ctx.lr = 0x8260C10C;
	sub_8221CCA8(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cc50
	ctx.lr = 0x8260C11C;
	sub_8221CC50(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C12C:
	// cmplwi cr6,r9,17
	cr6.compare<uint32_t>(ctx.r9.u32, 17, xer);
	// bne cr6,0x8260c164
	if (!cr6.eq) goto loc_8260C164;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cca8
	ctx.lr = 0x8260C144;
	sub_8221CCA8(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cc50
	ctx.lr = 0x8260C154;
	sub_8221CC50(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C164:
	// cmplwi cr6,r9,18
	cr6.compare<uint32_t>(ctx.r9.u32, 18, xer);
	// bne cr6,0x8260c19c
	if (!cr6.eq) goto loc_8260C19C;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cca8
	ctx.lr = 0x8260C17C;
	sub_8221CCA8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cc50
	ctx.lr = 0x8260C18C;
	sub_8221CC50(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C19C:
	// cmplwi cr6,r9,19
	cr6.compare<uint32_t>(ctx.r9.u32, 19, xer);
	// bne cr6,0x8260c1d4
	if (!cr6.eq) goto loc_8260C1D4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cca8
	ctx.lr = 0x8260C1B4;
	sub_8221CCA8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8260bbc0
	if (!cr6.gt) goto loc_8260BBC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221cc50
	ctx.lr = 0x8260C1C4;
	sub_8221CC50(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bge cr6,0x8260bbc0
	if (!cr6.lt) goto loc_8260BBC0;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C1D4:
	// cmplwi cr6,r9,20
	cr6.compare<uint32_t>(ctx.r9.u32, 20, xer);
	// bne cr6,0x8260c210
	if (!cr6.eq) goto loc_8260C210;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r11,r9,0,16,18
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xE000;
	// rlwinm r11,r11,0,18,16
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFBFFF;
	// cmplwi cr6,r11,32768
	cr6.compare<uint32_t>(r11.u32, 32768, xer);
	// bne cr6,0x8260c200
	if (!cr6.eq) goto loc_8260C200;
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C200:
	// cmpwi cr6,r11,8192
	cr6.compare<int32_t>(r11.s32, 8192, xer);
	// bne cr6,0x8260c24c
	if (!cr6.eq) goto loc_8260C24C;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C210:
	// cmplwi cr6,r9,21
	cr6.compare<uint32_t>(ctx.r9.u32, 21, xer);
	// bne cr6,0x8260c254
	if (!cr6.eq) goto loc_8260C254;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r11,r9,0,17,19
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x7000;
	// rlwinm r11,r11,0,19,17
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFDFFF;
	// cmpwi cr6,r11,4096
	cr6.compare<int32_t>(r11.s32, 4096, xer);
	// bne cr6,0x8260c23c
	if (!cr6.eq) goto loc_8260C23C;
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C23C:
	// cmpwi cr6,r11,16384
	cr6.compare<int32_t>(r11.s32, 16384, xer);
	// bne cr6,0x8260c24c
	if (!cr6.eq) goto loc_8260C24C;
	// li r11,255
	r11.s64 = 255;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C24C:
	// li r11,128
	r11.s64 = 128;
	// b 0x8260c39c
	goto loc_8260C39C;
loc_8260C254:
	// cmplwi cr6,r9,22
	cr6.compare<uint32_t>(ctx.r9.u32, 22, xer);
	// bne cr6,0x8260c27c
	if (!cr6.eq) goto loc_8260C27C;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,17
	ctx.r10.s64 = r30.s64 + 17;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// bge cr6,0x8260c394
	if (!cr6.lt) goto loc_8260C394;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r11,r11,255
	xer.ca = r11.u32 <= 255;
	r11.s64 = 255 - r11.s64;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260C27C:
	// cmplwi cr6,r9,23
	cr6.compare<uint32_t>(ctx.r9.u32, 23, xer);
	// bne cr6,0x8260c2a4
	if (!cr6.eq) goto loc_8260C2A4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,17
	ctx.r10.s64 = r30.s64 + 17;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// ble cr6,0x8260c394
	if (!cr6.gt) goto loc_8260C394;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-255
	r11.s64 = r11.s64 + -255;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260C2A4:
	// cmplwi cr6,r9,24
	cr6.compare<uint32_t>(ctx.r9.u32, 24, xer);
	// bne cr6,0x8260c2cc
	if (!cr6.eq) goto loc_8260C2CC;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,16
	ctx.r10.s64 = r30.s64 + 16;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// bge cr6,0x8260c394
	if (!cr6.lt) goto loc_8260C394;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r11,r11,255
	xer.ca = r11.u32 <= 255;
	r11.s64 = 255 - r11.s64;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260C2CC:
	// cmplwi cr6,r9,25
	cr6.compare<uint32_t>(ctx.r9.u32, 25, xer);
	// bne cr6,0x8260c2f4
	if (!cr6.eq) goto loc_8260C2F4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,16
	ctx.r10.s64 = r30.s64 + 16;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// ble cr6,0x8260c394
	if (!cr6.gt) goto loc_8260C394;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-255
	r11.s64 = r11.s64 + -255;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260C2F4:
	// cmplwi cr6,r9,26
	cr6.compare<uint32_t>(ctx.r9.u32, 26, xer);
	// bne cr6,0x8260c31c
	if (!cr6.eq) goto loc_8260C31C;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,19
	ctx.r10.s64 = r30.s64 + 19;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// bge cr6,0x8260c394
	if (!cr6.lt) goto loc_8260C394;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r11,r11,255
	xer.ca = r11.u32 <= 255;
	r11.s64 = 255 - r11.s64;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260C31C:
	// cmplwi cr6,r9,27
	cr6.compare<uint32_t>(ctx.r9.u32, 27, xer);
	// bne cr6,0x8260c344
	if (!cr6.eq) goto loc_8260C344;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,19
	ctx.r10.s64 = r30.s64 + 19;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// ble cr6,0x8260c394
	if (!cr6.gt) goto loc_8260C394;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-255
	r11.s64 = r11.s64 + -255;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260C344:
	// cmplwi cr6,r9,28
	cr6.compare<uint32_t>(ctx.r9.u32, 28, xer);
	// bne cr6,0x8260c36c
	if (!cr6.eq) goto loc_8260C36C;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,18
	ctx.r10.s64 = r30.s64 + 18;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// bge cr6,0x8260c394
	if (!cr6.lt) goto loc_8260C394;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r11,r11,255
	xer.ca = r11.u32 <= 255;
	r11.s64 = 255 - r11.s64;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260C36C:
	// cmplwi cr6,r9,29
	cr6.compare<uint32_t>(ctx.r9.u32, 29, xer);
	// bne cr6,0x8260c39c
	if (!cr6.eq) goto loc_8260C39C;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,18
	ctx.r10.s64 = r30.s64 + 18;
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// ble cr6,0x8260c394
	if (!cr6.gt) goto loc_8260C394;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-255
	r11.s64 = r11.s64 + -255;
	// b 0x8260c398
	goto loc_8260C398;
loc_8260C394:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8260C398:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8260C39C:
	// addi r10,r26,130
	ctx.r10.s64 = r26.s64 + 130;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r23
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + r23.u32);
	// lbz r8,2(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// xor r9,r8,r7
	ctx.r9.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x8260c3c0
	if (!cr6.lt) goto loc_8260C3C0;
	// neg r9,r9
	ctx.r9.s64 = -ctx.r9.s64;
loc_8260C3C0:
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge cr6,0x8260c3d0
	if (!cr6.lt) goto loc_8260C3D0;
	// neg r8,r8
	ctx.r8.s64 = -ctx.r8.s64;
loc_8260C3D0:
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x8260c3f4
	if (!cr6.lt) goto loc_8260C3F4;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stb r11,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, r11.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8260c3f4
	if (cr6.eq) goto loc_8260C3F4;
	// lbz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// rotlwi r8,r10,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// stbx r11,r8,r9
	PPC_STORE_U8(ctx.r8.u32 + ctx.r9.u32, r11.u8);
loc_8260C3F4:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8260bacc
	if (cr6.lt) goto loc_8260BACC;
loc_8260C404:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823dba20
	ctx.lr = 0x8260C410;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8260C414"))) PPC_WEAK_FUNC(sub_8260C414);
PPC_FUNC_IMPL(__imp__sub_8260C414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260C418"))) PPC_WEAK_FUNC(sub_8260C418);
PPC_FUNC_IMPL(__imp__sub_8260C418) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r8,21662(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 21662);
	// stb r3,21661(r31)
	PPC_STORE_U8(r31.u32 + 21661, ctx.r3.u8);
	// stb r10,21660(r9)
	PPC_STORE_U8(ctx.r9.u32 + 21660, ctx.r10.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8260c458
	if (cr6.eq) goto loc_8260C458;
	// bl 0x82614c28
	ctx.lr = 0x8260C454;
	sub_82614C28(ctx, base);
	// lbz r3,21661(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 21661);
loc_8260C458:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lbz r10,-17683(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17683);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8260c46c
	if (cr6.eq) goto loc_8260C46C;
	// bl 0x82130000
	ctx.lr = 0x8260C46C;
	sub_82130000(ctx, base);
loc_8260C46C:
	// bl 0x826150c0
	ctx.lr = 0x8260C470;
	sub_826150C0(ctx, base);
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

__attribute__((alias("__imp__sub_8260C484"))) PPC_WEAK_FUNC(sub_8260C484);
PPC_FUNC_IMPL(__imp__sub_8260C484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260C488"))) PPC_WEAK_FUNC(sub_8260C488);
PPC_FUNC_IMPL(__imp__sub_8260C488) {
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
	// bl 0x82615180
	ctx.lr = 0x8260C498;
	sub_82615180(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lbz r10,-17683(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17683);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8260c4ac
	if (cr6.eq) goto loc_8260C4AC;
	// bl 0x82130000
	ctx.lr = 0x8260C4AC;
	sub_82130000(ctx, base);
loc_8260C4AC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,21662(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21662);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8260c4c0
	if (cr6.eq) goto loc_8260C4C0;
	// bl 0x82130000
	ctx.lr = 0x8260C4C0;
	sub_82130000(ctx, base);
loc_8260C4C0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260C4D0"))) PPC_WEAK_FUNC(sub_8260C4D0);
PPC_FUNC_IMPL(__imp__sub_8260C4D0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,21662(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21662);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8260c4f8
	if (cr6.eq) goto loc_8260C4F8;
	// bl 0x82614c38
	ctx.lr = 0x8260C4F8;
	sub_82614C38(ctx, base);
loc_8260C4F8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lbz r10,-17683(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17683);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8260c50c
	if (cr6.eq) goto loc_8260C50C;
	// bl 0x82614c70
	ctx.lr = 0x8260C50C;
	sub_82614C70(ctx, base);
loc_8260C50C:
	// bl 0x826150f0
	ctx.lr = 0x8260C510;
	sub_826150F0(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x8260C514;
	sub_82130000(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r30,r11,21644
	r30.s64 = r11.s64 + 21644;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_8260C520:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260c534
	if (cr6.eq) goto loc_8260C534;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260C534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260C534:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8260c520
	if (cr6.lt) goto loc_8260C520;
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

__attribute__((alias("__imp__sub_8260C55C"))) PPC_WEAK_FUNC(sub_8260C55C);
PPC_FUNC_IMPL(__imp__sub_8260C55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260C560"))) PPC_WEAK_FUNC(sub_8260C560);
PPC_FUNC_IMPL(__imp__sub_8260C560) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r10,r11,21644
	ctx.r10.s64 = r11.s64 + 21644;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8260C56C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r3
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r3.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r10,16
	ctx.r9.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8260c56c
	if (cr6.lt) goto loc_8260C56C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8260C590:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8260c5bc
	if (cr6.eq) goto loc_8260C5BC;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8260c590
	if (cr6.lt) goto loc_8260C590;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-30304
	ctx.r3.s64 = r11.s64 + -30304;
	// b 0x821bd618
	sub_821BD618(ctx, base);
	return;
loc_8260C5BC:
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260C5C8"))) PPC_WEAK_FUNC(sub_8260C5C8);
PPC_FUNC_IMPL(__imp__sub_8260C5C8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// fcmpu cr6,f1,f2
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, ctx.f2.f64);
	// ble cr6,0x8260c5e8
	if (!cr6.gt) goto loc_8260C5E8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f13,f1,f2
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f2
	ctx.f12.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fdivs f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// blr 
	return;
loc_8260C5E8:
	// fneg f0,f2
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8260c60c
	if (!cr6.lt) goto loc_8260C60C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f13,f1,f2
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f2
	ctx.f12.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fdivs f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// blr 
	return;
loc_8260C60C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260C618"))) PPC_WEAK_FUNC(sub_8260C618);
PPC_FUNC_IMPL(__imp__sub_8260C618) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f13,-8(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fmadds f9,f12,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f10.f64));
	// fsqrts f0,f9
	f0.f64 = double(float(sqrt(ctx.f9.f64)));
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x8260c660
	if (!cr6.lt) goto loc_8260C660;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,0(r5)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stfs f1,0(r4)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f1,0(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
loc_8260C660:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f0.f64;
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x8260c684
	if (cr6.eq) goto loc_8260C684;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8260c684
	if (!cr6.gt) goto loc_8260C684;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
loc_8260C684:
	// fsubs f12,f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f1.f64));
	// addi r11,r1,-32
	r11.s64 = ctx.r1.s64 + -32;
	// fsubs f11,f13,f1
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f1,f12,f11
	ctx.f1.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fdivs f10,f1,f0
	ctx.f10.f64 = double(float(ctx.f1.f64 / f0.f64));
	// stfs f10,-32(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvlx128 v62,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v60,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,-12(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,0(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f9,0(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f8,0(r5)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260C6D4"))) PPC_WEAK_FUNC(sub_8260C6D4);
PPC_FUNC_IMPL(__imp__sub_8260C6D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260C6D8"))) PPC_WEAK_FUNC(sub_8260C6D8);
PPC_FUNC_IMPL(__imp__sub_8260C6D8) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8260c618
	ctx.lr = 0x8260C6FC;
	sub_8260C618(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260C70C"))) PPC_WEAK_FUNC(sub_8260C70C);
PPC_FUNC_IMPL(__imp__sub_8260C70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260C710"))) PPC_WEAK_FUNC(sub_8260C710);
PPC_FUNC_IMPL(__imp__sub_8260C710) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister v56{};
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
	// bl 0x823d91e4
	ctx.lr = 0x8260C718;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r8,r11,-29824
	ctx.r8.s64 = r11.s64 + -29824;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f13,-31384(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31384);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lis r31,-32247
	r31.s64 = -2113339392;
	// stfs f13,60(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lfs f13,-29840(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29840);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r10,-29856
	ctx.r4.s64 = ctx.r10.s64 + -29856;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lfs f12,-26224(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -26224);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lis r30,-32254
	r30.s64 = -2113798144;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r29,-32254
	r29.s64 = -2113798144;
	// lis r28,-32250
	r28.s64 = -2113536000;
	// stfs f12,56(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// stfs f12,68(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lis r27,-32255
	r27.s64 = -2113863680;
	// stfs f13,136(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// addi r6,r6,12736
	ctx.r6.s64 = ctx.r6.s64 + 12736;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r31,-29872
	ctx.r8.s64 = r31.s64 + -29872;
	// stvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r11,-29888
	r26.s64 = r11.s64 + -29888;
	// lfs f13,-11620(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -11620);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r9,-29904
	ctx.r9.s64 = ctx.r9.s64 + -29904;
	// lfs f12,-1684(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -1684);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r7,-29920
	ctx.r7.s64 = ctx.r7.s64 + -29920;
	// lfs f11,-26540(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26540);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r5,-29936
	ctx.r5.s64 = ctx.r5.s64 + -29936;
	// lfs f10,-6172(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -6172);
	ctx.f10.f64 = double(temp.f32);
	// li r31,160
	r31.s64 = 160;
	// lfs f9,-32032(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -32032);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// stfs f0,88(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// li r11,0
	r11.s64 = 0;
	// stfs f0,92(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// li r4,176
	ctx.r4.s64 = 176;
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// li r10,192
	ctx.r10.s64 = 192;
	// stfs f0,100(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// li r6,208
	ctx.r6.s64 = 208;
	// stfs f0,72(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// li r30,224
	r30.s64 = 224;
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// li r29,240
	r29.s64 = 240;
	// stfs f13,116(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// li r28,1
	r28.s64 = 1;
	// stfs f12,120(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// li r27,6
	r27.s64 = 6;
	// stfs f0,124(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// li r25,2
	r25.s64 = 2;
	// stfs f11,128(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// lis r24,-32256
	r24.s64 = -2113929216;
	// stfs f10,140(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// lis r23,-32255
	r23.s64 = -2113863680;
	// stfs f9,144(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// lvx128 v60,r0,r26
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stvx128 v59,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stvx128 v58,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stvx128 v57,r3,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,14992(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 14992);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-31376(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -31376);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,32(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f11,36(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lfs f13,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,17032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	ctx.f10.f64 = double(temp.f32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f10,44(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r28,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r28.u32);
	// lfs f12,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// stw r27,272(r3)
	PPC_STORE_U32(ctx.r3.u32 + 272, r27.u32);
	// lfs f11,11368(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11368);
	ctx.f11.f64 = double(temp.f32);
	// stb r11,148(r3)
	PPC_STORE_U8(ctx.r3.u32 + 148, r11.u8);
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stb r11,132(r3)
	PPC_STORE_U8(ctx.r3.u32 + 132, r11.u8);
	// stfs f12,276(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// stw r25,284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 284, r25.u32);
	// stfs f11,292(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// stfs f13,296(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// stfs f13,300(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 300, temp.u32);
	// stfs f13,304(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 304, temp.u32);
	// stfs f13,308(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 308, temp.u32);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8260C8DC"))) PPC_WEAK_FUNC(sub_8260C8DC);
PPC_FUNC_IMPL(__imp__sub_8260C8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260C8E0"))) PPC_WEAK_FUNC(sub_8260C8E0);
PPC_FUNC_IMPL(__imp__sub_8260C8E0) {
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
	ctx.lr = 0x8260C8E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// beq cr6,0x8260c90c
	if (cr6.eq) goto loc_8260C90C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x8260C90C;
	sub_821CA540(ctx, base);
loc_8260C90C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r28,r10,-28588
	r28.s64 = ctx.r10.s64 + -28588;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8260C938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
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
	ctx.lr = 0x8260C96C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-28600
	ctx.r4.s64 = ctx.r10.s64 + -28600;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260C984;
	sub_8218A568(ctx, base);
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,25112
	ctx.r4.s64 = ctx.r8.s64 + 25112;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260C9A0;
	sub_8218A568(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-28620
	ctx.r4.s64 = ctx.r4.s64 + -28620;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260C9BC;
	sub_8218A568(ctx, base);
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r3,-28636
	ctx.r4.s64 = ctx.r3.s64 + -28636;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260C9D8;
	sub_8218A568(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-28644
	ctx.r4.s64 = ctx.r9.s64 + -28644;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260C9F4;
	sub_8218A568(ctx, base);
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-28664
	ctx.r4.s64 = ctx.r8.s64 + -28664;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CA10;
	sub_8218A568(ctx, base);
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-28676
	ctx.r4.s64 = ctx.r4.s64 + -28676;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CA2C;
	sub_8218A568(ctx, base);
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,360
	ctx.r4.s64 = r11.s64 + 360;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CA48;
	sub_8218A568(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-28692
	ctx.r4.s64 = ctx.r9.s64 + -28692;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CA64;
	sub_8218A568(ctx, base);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-5612
	ctx.r4.s64 = ctx.r6.s64 + -5612;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CA80;
	sub_8218A568(ctx, base);
	// stw r3,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-10872
	ctx.r4.s64 = ctx.r4.s64 + -10872;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CA9C;
	sub_8218A568(ctx, base);
	// stw r3,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-28704
	ctx.r4.s64 = ctx.r10.s64 + -28704;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CAB8;
	sub_8218A568(ctx, base);
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-5636
	ctx.r4.s64 = ctx.r9.s64 + -5636;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CAD4;
	sub_8218A568(ctx, base);
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-28720
	ctx.r4.s64 = ctx.r6.s64 + -28720;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CAF0;
	sub_8218A568(ctx, base);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-28736
	ctx.r4.s64 = ctx.r4.s64 + -28736;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CB0C;
	sub_8218A568(ctx, base);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-28752
	ctx.r4.s64 = ctx.r10.s64 + -28752;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CB28;
	sub_8218A568(ctx, base);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-25164
	ctx.r4.s64 = ctx.r9.s64 + -25164;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CB44;
	sub_8218A568(ctx, base);
	// stw r3,1496(r31)
	PPC_STORE_U32(r31.u32 + 1496, ctx.r3.u32);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-28764
	ctx.r4.s64 = ctx.r6.s64 + -28764;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CB60;
	sub_8218A568(ctx, base);
	// stw r3,1500(r31)
	PPC_STORE_U32(r31.u32 + 1500, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-28772
	ctx.r4.s64 = ctx.r4.s64 + -28772;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CB7C;
	sub_8218A568(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// stw r3,1516(r31)
	PPC_STORE_U32(r31.u32 + 1516, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-28780
	ctx.r4.s64 = ctx.r10.s64 + -28780;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CB98;
	sub_8218A568(ctx, base);
	// stw r3,1556(r31)
	PPC_STORE_U32(r31.u32 + 1556, ctx.r3.u32);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-28788
	ctx.r4.s64 = ctx.r8.s64 + -28788;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CBB4;
	sub_8218A568(ctx, base);
	// stw r3,1504(r31)
	PPC_STORE_U32(r31.u32 + 1504, ctx.r3.u32);
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-28808
	ctx.r4.s64 = ctx.r6.s64 + -28808;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CBD0;
	sub_8218A568(ctx, base);
	// stw r3,1508(r31)
	PPC_STORE_U32(r31.u32 + 1508, ctx.r3.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-28816
	ctx.r4.s64 = ctx.r4.s64 + -28816;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CBEC;
	sub_8218A568(ctx, base);
	// stw r3,1512(r31)
	PPC_STORE_U32(r31.u32 + 1512, ctx.r3.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-28832
	ctx.r4.s64 = ctx.r10.s64 + -28832;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CC08;
	sub_8218A568(ctx, base);
	// stw r3,1520(r31)
	PPC_STORE_U32(r31.u32 + 1520, ctx.r3.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-28840
	ctx.r4.s64 = ctx.r9.s64 + -28840;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CC24;
	sub_8218A568(ctx, base);
	// stw r3,1524(r31)
	PPC_STORE_U32(r31.u32 + 1524, ctx.r3.u32);
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-28852
	ctx.r4.s64 = ctx.r6.s64 + -28852;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CC40;
	sub_8218A568(ctx, base);
	// stw r3,1528(r31)
	PPC_STORE_U32(r31.u32 + 1528, ctx.r3.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-28872
	ctx.r4.s64 = ctx.r4.s64 + -28872;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CC5C;
	sub_8218A568(ctx, base);
	// stw r3,1560(r31)
	PPC_STORE_U32(r31.u32 + 1560, ctx.r3.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-28892
	ctx.r4.s64 = ctx.r10.s64 + -28892;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CC78;
	sub_8218A568(ctx, base);
	// stw r3,1564(r31)
	PPC_STORE_U32(r31.u32 + 1564, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-5200
	ctx.r4.s64 = ctx.r9.s64 + -5200;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CC94;
	sub_8218A568(ctx, base);
	// stw r3,1536(r31)
	PPC_STORE_U32(r31.u32 + 1536, ctx.r3.u32);
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-28912
	ctx.r4.s64 = ctx.r6.s64 + -28912;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CCB0;
	sub_8218A568(ctx, base);
	// stw r3,1532(r31)
	PPC_STORE_U32(r31.u32 + 1532, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-28928
	ctx.r4.s64 = ctx.r10.s64 + -28928;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CCCC;
	sub_8218A568(ctx, base);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stw r3,1540(r31)
	PPC_STORE_U32(r31.u32 + 1540, ctx.r3.u32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// addi r4,r8,-28944
	ctx.r4.s64 = ctx.r8.s64 + -28944;
	// bl 0x8218a568
	ctx.lr = 0x8260CCE8;
	sub_8218A568(ctx, base);
	// stw r3,1552(r31)
	PPC_STORE_U32(r31.u32 + 1552, ctx.r3.u32);
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-28964
	ctx.r4.s64 = ctx.r6.s64 + -28964;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CD04;
	sub_8218A568(ctx, base);
	// stw r3,1544(r31)
	PPC_STORE_U32(r31.u32 + 1544, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-28984
	ctx.r4.s64 = ctx.r4.s64 + -28984;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CD20;
	sub_8218A568(ctx, base);
	// stw r3,1572(r31)
	PPC_STORE_U32(r31.u32 + 1572, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-29004
	ctx.r4.s64 = ctx.r10.s64 + -29004;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CD3C;
	sub_8218A568(ctx, base);
	// stw r3,1576(r31)
	PPC_STORE_U32(r31.u32 + 1576, ctx.r3.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-29020
	ctx.r4.s64 = ctx.r9.s64 + -29020;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CD58;
	sub_8218A568(ctx, base);
	// stw r3,1580(r31)
	PPC_STORE_U32(r31.u32 + 1580, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-10852
	ctx.r4.s64 = ctx.r6.s64 + -10852;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CD74;
	sub_8218A568(ctx, base);
	// stw r3,1584(r31)
	PPC_STORE_U32(r31.u32 + 1584, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-29036
	ctx.r4.s64 = ctx.r4.s64 + -29036;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CD90;
	sub_8218A568(ctx, base);
	// stw r3,1588(r31)
	PPC_STORE_U32(r31.u32 + 1588, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-29052
	ctx.r4.s64 = ctx.r10.s64 + -29052;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CDAC;
	sub_8218A568(ctx, base);
	// stw r3,1592(r31)
	PPC_STORE_U32(r31.u32 + 1592, ctx.r3.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-29072
	ctx.r4.s64 = ctx.r9.s64 + -29072;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CDC8;
	sub_8218A568(ctx, base);
	// stw r3,1612(r31)
	PPC_STORE_U32(r31.u32 + 1612, ctx.r3.u32);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-29084
	ctx.r4.s64 = ctx.r6.s64 + -29084;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CDE4;
	sub_8218A568(ctx, base);
	// stw r3,1596(r31)
	PPC_STORE_U32(r31.u32 + 1596, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-10260
	ctx.r4.s64 = ctx.r4.s64 + -10260;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CE00;
	sub_8218A568(ctx, base);
	// stw r3,1600(r31)
	PPC_STORE_U32(r31.u32 + 1600, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-29092
	ctx.r4.s64 = ctx.r10.s64 + -29092;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CE1C;
	sub_8218A568(ctx, base);
	// stw r3,1604(r31)
	PPC_STORE_U32(r31.u32 + 1604, ctx.r3.u32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-29100
	ctx.r4.s64 = ctx.r8.s64 + -29100;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CE38;
	sub_8218A568(ctx, base);
	// stw r3,1608(r31)
	PPC_STORE_U32(r31.u32 + 1608, ctx.r3.u32);
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-29132
	ctx.r4.s64 = ctx.r6.s64 + -29132;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CE54;
	sub_8218A568(ctx, base);
	// stw r3,1616(r31)
	PPC_STORE_U32(r31.u32 + 1616, ctx.r3.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-29148
	ctx.r4.s64 = ctx.r4.s64 + -29148;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260CE70;
	sub_8218A568(ctx, base);
	// stw r3,1700(r31)
	PPC_STORE_U32(r31.u32 + 1700, ctx.r3.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-8396
	ctx.r4.s64 = ctx.r10.s64 + -8396;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CE8C;
	sub_8218B688(ctx, base);
	// stw r3,3328(r31)
	PPC_STORE_U32(r31.u32 + 3328, ctx.r3.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-29168
	ctx.r4.s64 = ctx.r9.s64 + -29168;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CEA8;
	sub_8218B688(ctx, base);
	// stw r3,3332(r31)
	PPC_STORE_U32(r31.u32 + 3332, ctx.r3.u32);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,16
	ctx.r4.s64 = ctx.r6.s64 + 16;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CEC4;
	sub_8218B688(ctx, base);
	// stw r3,3264(r31)
	PPC_STORE_U32(r31.u32 + 3264, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-29180
	ctx.r4.s64 = ctx.r4.s64 + -29180;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CEE0;
	sub_8218B688(ctx, base);
	// stw r3,3268(r31)
	PPC_STORE_U32(r31.u32 + 3268, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-29192
	ctx.r4.s64 = ctx.r10.s64 + -29192;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CEFC;
	sub_8218B688(ctx, base);
	// stw r3,3272(r31)
	PPC_STORE_U32(r31.u32 + 3272, ctx.r3.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-29200
	ctx.r4.s64 = ctx.r9.s64 + -29200;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CF18;
	sub_8218B688(ctx, base);
	// stw r3,3276(r31)
	PPC_STORE_U32(r31.u32 + 3276, ctx.r3.u32);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-29220
	ctx.r4.s64 = ctx.r6.s64 + -29220;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CF34;
	sub_8218B688(ctx, base);
	// stw r3,3280(r31)
	PPC_STORE_U32(r31.u32 + 3280, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-29236
	ctx.r4.s64 = ctx.r4.s64 + -29236;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CF50;
	sub_8218B688(ctx, base);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// stw r3,3360(r31)
	PPC_STORE_U32(r31.u32 + 3360, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-29256
	ctx.r4.s64 = r11.s64 + -29256;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CF6C;
	sub_8218B688(ctx, base);
	// stw r3,3336(r31)
	PPC_STORE_U32(r31.u32 + 3336, ctx.r3.u32);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-29272
	ctx.r4.s64 = ctx.r8.s64 + -29272;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CF88;
	sub_8218B688(ctx, base);
	// stw r3,3340(r31)
	PPC_STORE_U32(r31.u32 + 3340, ctx.r3.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-29296
	ctx.r4.s64 = ctx.r7.s64 + -29296;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CFA4;
	sub_8218B688(ctx, base);
	// stw r3,3284(r31)
	PPC_STORE_U32(r31.u32 + 3284, ctx.r3.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-29324
	ctx.r4.s64 = ctx.r4.s64 + -29324;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CFC0;
	sub_8218B688(ctx, base);
	// stw r3,3288(r31)
	PPC_STORE_U32(r31.u32 + 3288, ctx.r3.u32);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-29352
	ctx.r4.s64 = r11.s64 + -29352;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CFDC;
	sub_8218B688(ctx, base);
	// stw r3,3292(r31)
	PPC_STORE_U32(r31.u32 + 3292, ctx.r3.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-29380
	ctx.r4.s64 = ctx.r9.s64 + -29380;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260CFF8;
	sub_8218B688(ctx, base);
	// stw r3,3296(r31)
	PPC_STORE_U32(r31.u32 + 3296, ctx.r3.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-29400
	ctx.r4.s64 = ctx.r7.s64 + -29400;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260D014;
	sub_8218A568(ctx, base);
	// stw r3,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, ctx.r3.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-29408
	ctx.r4.s64 = ctx.r4.s64 + -29408;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D030;
	sub_8218B688(ctx, base);
	// stw r3,3300(r31)
	PPC_STORE_U32(r31.u32 + 3300, ctx.r3.u32);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-29416
	ctx.r4.s64 = r11.s64 + -29416;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D04C;
	sub_8218B688(ctx, base);
	// stw r3,3304(r31)
	PPC_STORE_U32(r31.u32 + 3304, ctx.r3.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-29428
	ctx.r4.s64 = ctx.r9.s64 + -29428;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D068;
	sub_8218B688(ctx, base);
	// stw r3,3308(r31)
	PPC_STORE_U32(r31.u32 + 3308, ctx.r3.u32);
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-29440
	ctx.r4.s64 = ctx.r7.s64 + -29440;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D084;
	sub_8218B688(ctx, base);
	// stw r3,3312(r31)
	PPC_STORE_U32(r31.u32 + 3312, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-29460
	ctx.r4.s64 = ctx.r10.s64 + -29460;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D0A0;
	sub_8218B688(ctx, base);
	// stw r3,3320(r31)
	PPC_STORE_U32(r31.u32 + 3320, ctx.r3.u32);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-29480
	ctx.r4.s64 = ctx.r8.s64 + -29480;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260D0BC;
	sub_8218A568(ctx, base);
	// stw r3,3400(r31)
	PPC_STORE_U32(r31.u32 + 3400, ctx.r3.u32);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-29504
	ctx.r4.s64 = ctx.r6.s64 + -29504;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260D0D8;
	sub_8218A568(ctx, base);
	// stw r3,3404(r31)
	PPC_STORE_U32(r31.u32 + 3404, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-29528
	ctx.r4.s64 = ctx.r4.s64 + -29528;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D0F4;
	sub_8218B688(ctx, base);
	// stw r3,3372(r31)
	PPC_STORE_U32(r31.u32 + 3372, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-29552
	ctx.r4.s64 = ctx.r10.s64 + -29552;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D110;
	sub_8218B688(ctx, base);
	// stw r3,3380(r31)
	PPC_STORE_U32(r31.u32 + 3380, ctx.r3.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-29580
	ctx.r4.s64 = ctx.r9.s64 + -29580;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D12C;
	sub_8218B688(ctx, base);
	// stw r3,3376(r31)
	PPC_STORE_U32(r31.u32 + 3376, ctx.r3.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-29608
	ctx.r4.s64 = ctx.r7.s64 + -29608;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D148;
	sub_8218B688(ctx, base);
	// stw r3,3384(r31)
	PPC_STORE_U32(r31.u32 + 3384, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-29628
	ctx.r4.s64 = ctx.r4.s64 + -29628;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D164;
	sub_8218B688(ctx, base);
	// stw r3,3324(r31)
	PPC_STORE_U32(r31.u32 + 3324, ctx.r3.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-29648
	ctx.r4.s64 = r11.s64 + -29648;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D180;
	sub_8218B688(ctx, base);
	// stw r3,3388(r31)
	PPC_STORE_U32(r31.u32 + 3388, ctx.r3.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-29660
	ctx.r4.s64 = ctx.r9.s64 + -29660;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260D19C;
	sub_8218A568(ctx, base);
	// stw r3,3396(r31)
	PPC_STORE_U32(r31.u32 + 3396, ctx.r3.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-29680
	ctx.r4.s64 = ctx.r7.s64 + -29680;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8260D1B8;
	sub_8218B688(ctx, base);
	// stw r3,3392(r31)
	PPC_STORE_U32(r31.u32 + 3392, ctx.r3.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-29708
	ctx.r4.s64 = ctx.r4.s64 + -29708;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260D1D4;
	sub_8218A568(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stw r3,3248(r31)
	PPC_STORE_U32(r31.u32 + 3248, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-5176
	ctx.r4.s64 = ctx.r10.s64 + -5176;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260D1F0;
	sub_8218A568(ctx, base);
	// stw r3,3256(r31)
	PPC_STORE_U32(r31.u32 + 3256, ctx.r3.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-29724
	ctx.r4.s64 = ctx.r9.s64 + -29724;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8260D20C;
	sub_8218A568(ctx, base);
	// stw r3,3260(r31)
	PPC_STORE_U32(r31.u32 + 3260, ctx.r3.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260d220
	if (cr6.eq) goto loc_8260D220;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8260D220;
	sub_821C9A90(ctx, base);
loc_8260D220:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,21672(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 21672);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8260d234
	if (!cr6.eq) goto loc_8260D234;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_8260D234:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x8260D23C;
	sub_821CA540(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r28,r11,-18100
	r28.s64 = r11.s64 + -18100;
	// addi r4,r10,-29736
	ctx.r4.s64 = ctx.r10.s64 + -29736;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca778
	ctx.lr = 0x8260D258;
	sub_821CA778(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8260d28c
	if (cr6.eq) goto loc_8260D28C;
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-29752
	ctx.r4.s64 = r11.s64 + -29752;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260D288;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
loc_8260D28C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,-29764
	ctx.r4.s64 = r11.s64 + -29764;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca778
	ctx.lr = 0x8260D2A0;
	sub_821CA778(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8260d2d0
	if (cr6.eq) goto loc_8260D2D0;
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-29780
	ctx.r4.s64 = r11.s64 + -29780;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260D2CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
loc_8260D2D0:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lwz r5,100(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r4,r11,-29792
	ctx.r4.s64 = r11.s64 + -29792;
	// bl 0x82182150
	ctx.lr = 0x8260D2E4;
	sub_82182150(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// addi r4,r10,-29808
	ctx.r4.s64 = ctx.r10.s64 + -29808;
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x82182150
	ctx.lr = 0x8260D2F8;
	sub_82182150(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8260D300;
	sub_821C9A90(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8260D308"))) PPC_WEAK_FUNC(sub_8260D308);
PPC_FUNC_IMPL(__imp__sub_8260D308) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8260D310;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x82180430
	ctx.lr = 0x8260D32C;
	sub_82180430(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r24,1
	r24.s64 = 1;
	// li r22,0
	r22.s64 = 0;
	// li r23,5
	r23.s64 = 5;
	// stb r24,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r24.u8);
	// li r25,4
	r25.s64 = 4;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r22.u32);
	// stw r24,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r24.u32);
	// cmpwi cr6,r27,720
	cr6.compare<int32_t>(r27.s32, 720, xer);
	// stw r23,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r23.u32);
	// stb r24,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r24.u8);
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// lwz r31,-25232(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// bgt cr6,0x8260d36c
	if (cr6.gt) goto loc_8260D36C;
	// cmpwi cr6,r26,576
	cr6.compare<int32_t>(r26.s32, 576, xer);
	// ble cr6,0x8260d37c
	if (!cr6.gt) goto loc_8260D37C;
loc_8260D36C:
	// srawi r11,r27,1
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x1) != 0);
	r11.s64 = r27.s32 >> 1;
	// addze r27,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r27.s64 = temp.s64;
	// srawi r10,r26,1
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1) != 0);
	ctx.r10.s64 = r26.s32 >> 1;
	// addze r26,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r26.s64 = temp.s64;
loc_8260D37C:
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// srawi r11,r27,1
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x1) != 0);
	r11.s64 = r27.s32 >> 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addze r29,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r29.s64 = temp.s64;
	// srawi r8,r26,1
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x1) != 0);
	ctx.r8.s64 = r26.s32 >> 1;
	// addi r4,r9,-28444
	ctx.r4.s64 = ctx.r9.s64 + -28444;
	// addze r28,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	r28.s64 = temp.s64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r8,32
	ctx.r8.s64 = 32;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260D3C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// stw r23,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r23.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// addi r24,r10,-28456
	r24.s64 = ctx.r10.s64 + -28456;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260D404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r3,64(r30)
	PPC_STORE_U32(r30.u32 + 64, ctx.r3.u32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// stw r9,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r22,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r22.u32);
	// addi r4,r8,-28472
	ctx.r4.s64 = ctx.r8.s64 + -28472;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,32
	ctx.r8.s64 = 32;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260D444;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r27,-32124
	r27.s64 = -2105278464;
	// mr r11,r22
	r11.u64 = r22.u64;
	// stw r3,56(r30)
	PPC_STORE_U32(r30.u32 + 56, ctx.r3.u32);
	// stw r23,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r23.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r26,-24876(r27)
	r26.u64 = PPC_LOAD_U32(r27.u32 + -24876);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r11,-24876(r27)
	PPC_STORE_U32(r27.u32 + -24876, r11.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260D48C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r9,-28484
	ctx.r4.s64 = ctx.r9.s64 + -28484;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260D4C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,68(r30)
	PPC_STORE_U32(r30.u32 + 68, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// stw r23,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r23.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// addi r4,r10,-28496
	ctx.r4.s64 = ctx.r10.s64 + -28496;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,32
	ctx.r8.s64 = 32;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260D504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,44(r30)
	PPC_STORE_U32(r30.u32 + 44, ctx.r3.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8260d514
	if (cr6.eq) goto loc_8260D514;
	// stw r26,-24876(r27)
	PPC_STORE_U32(r27.u32 + -24876, r26.u32);
loc_8260D514:
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// stw r25,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r25.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r22,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r22.u32);
	// addi r4,r11,-28508
	ctx.r4.s64 = r11.s64 + -28508;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,128
	ctx.r7.s64 = 128;
	// li r6,128
	ctx.r6.s64 = 128;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260D550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-28520
	ctx.r4.s64 = ctx.r8.s64 + -28520;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,64
	ctx.r7.s64 = 64;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260D584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-28532
	ctx.r4.s64 = ctx.r8.s64 + -28532;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260D5B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-28540
	ctx.r4.s64 = ctx.r8.s64 + -28540;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260D5EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
	// lwz r29,-24876(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + -24876);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// stw r22,-24876(r27)
	PPC_STORE_U32(r27.u32 + -24876, r22.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-28548
	ctx.r4.s64 = ctx.r10.s64 + -28548;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260D628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r3.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-28576
	ctx.r4.s64 = r11.s64 + -28576;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260D65C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,40(r30)
	PPC_STORE_U32(r30.u32 + 40, ctx.r3.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8260d66c
	if (cr6.eq) goto loc_8260D66C;
	// stw r29,-24876(r27)
	PPC_STORE_U32(r27.u32 + -24876, r29.u32);
loc_8260D66C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8260D674"))) PPC_WEAK_FUNC(sub_8260D674);
PPC_FUNC_IMPL(__imp__sub_8260D674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260D678"))) PPC_WEAK_FUNC(sub_8260D678);
PPC_FUNC_IMPL(__imp__sub_8260D678) {
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
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
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
	// bl 0x823d91e8
	ctx.lr = 0x8260D680;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9c4
	ctx.lr = 0x8260D688;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f29,f2
	f29.f64 = ctx.f2.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// fmr f27,f4
	f27.f64 = ctx.f4.f64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// fmr f26,f5
	f26.f64 = ctx.f5.f64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8260d6c8
	if (!cr6.eq) goto loc_8260D6C8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r27,r11,20360
	r27.s64 = r11.s64 + 20360;
loc_8260D6C8:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x8260d6d4
	if (!cr6.eq) goto loc_8260D6D4;
	// lwz r28,136(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 136);
loc_8260D6D4:
	// lwz r11,388(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// lis r26,-32124
	r26.s64 = -2105278464;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// mr r25,r11
	r25.u64 = r11.u64;
	// beq cr6,0x8260d72c
	if (cr6.eq) goto loc_8260D72C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8260d6fc
	if (!cr6.eq) goto loc_8260D6FC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82183c58
	ctx.lr = 0x8260D6F8;
	sub_82183C58(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
loc_8260D6FC:
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260D72C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260D72C:
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260D744;
	sub_82189CE0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x8260d830
	if (cr6.eq) goto loc_8260D830;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260D768;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// frsp f25,f13
	f25.f64 = double(float(ctx.f13.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8260D790;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f12,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lwz r4,28(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// frsp f24,f11
	f24.f64 = double(float(ctx.f11.f64));
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8260D7B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// lfd f10,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// fdivs f23,f31,f8
	f23.f64 = double(float(f31.f64 / ctx.f8.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260D7E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// stfs f23,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f7,112(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// stfs f24,136(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f25,140(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1496);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// fdivs f4,f31,f5
	ctx.f4.f64 = double(float(f31.f64 / ctx.f5.f64));
	// stfs f4,128(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260D830;
	sub_8218A6E0(ctx, base);
loc_8260D830:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// fmr f9,f31
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f31.f64;
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// stw r24,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r24.u32);
	// fmr f5,f26
	ctx.f5.f64 = f26.f64;
	// fmr f4,f27
	ctx.f4.f64 = f27.f64;
	// lfs f7,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// bl 0x82194b58
	ctx.lr = 0x8260D86C;
	sub_82194B58(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,-25360(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25360);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260D888;
	sub_82189CE0(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8260d8b8
	if (cr6.eq) goto loc_8260D8B8;
	// neg r11,r25
	r11.s64 = -r25.s64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r11,3428(r31)
	PPC_STORE_U32(r31.u32 + 3428, r11.u32);
	// addi r5,r31,3412
	ctx.r5.s64 = r31.s64 + 3412;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260D8B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260D8B8:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba10
	ctx.lr = 0x8260D8C4;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8260D8C8"))) PPC_WEAK_FUNC(sub_8260D8C8);
PPC_FUNC_IMPL(__imp__sub_8260D8C8) {
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
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r30,-25232(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8260d914
	if (!cr6.eq) goto loc_8260D914;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260D90C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// b 0x8260d918
	goto loc_8260D918;
loc_8260D914:
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
loc_8260D918:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r10,r11,21676
	ctx.r10.s64 = r11.s64 + 21676;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260d938
	if (cr6.eq) goto loc_8260D938;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82189e80
	ctx.lr = 0x8260D938;
	sub_82189E80(ctx, base);
loc_8260D938:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x8217f768
	ctx.lr = 0x8260D944;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x8260D950;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x8260D95C;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8260D968;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8260D974;
	sub_8217F768(ctx, base);
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8260d9a0
	if (!cr6.eq) goto loc_8260D9A0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260D998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// b 0x8260d9a4
	goto loc_8260D9A4;
loc_8260D9A0:
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
loc_8260D9A4:
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

__attribute__((alias("__imp__sub_8260D9BC"))) PPC_WEAK_FUNC(sub_8260D9BC);
PPC_FUNC_IMPL(__imp__sub_8260D9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260D9C0"))) PPC_WEAK_FUNC(sub_8260D9C0);
PPC_FUNC_IMPL(__imp__sub_8260D9C0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260D9F0;
	sub_82189CE0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,3308(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3308);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r30,0
	r30.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f4,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f3,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f5,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260DA34;
	sub_8260D678(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,-25360(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + -25360);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260DA50;
	sub_82189CE0(ctx, base);
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

__attribute__((alias("__imp__sub_8260DA68"))) PPC_WEAK_FUNC(sub_8260DA68);
PPC_FUNC_IMPL(__imp__sub_8260DA68) {
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
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
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
	// bl 0x823d91f4
	ctx.lr = 0x8260DA70;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9bc
	ctx.lr = 0x8260DA78;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lbz r11,340(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 340);
	// lwz r5,1508(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1508);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bne cr6,0x8260dad0
	if (!cr6.eq) goto loc_8260DAD0;
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 308);
	f0.f64 = double(temp.f32);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// lfs f13,256(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f11,260(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,264(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	ctx.f10.f64 = double(temp.f32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f12,236(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f11,228(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f10,232(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// b 0x8260daf8
	goto loc_8260DAF8;
loc_8260DAD0:
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 280);
	f0.f64 = double(temp.f32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lfs f13,268(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f11,272(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 272);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,276(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 276);
	ctx.f10.f64 = double(temp.f32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f12,172(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f11,164(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f10,168(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
loc_8260DAF8:
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260DB00;
	sub_8218A6E0(ctx, base);
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 304);
	f0.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1512(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x8260DB30;
	sub_8218A6E0(ctx, base);
	// lfs f12,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 348);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1560);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260DB5C;
	sub_8218A6E0(ctx, base);
	// lfs f11,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1564(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1564);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260DB88;
	sub_8218A6E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r6,3336(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3336);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r30,0
	r30.s64 = 0;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f30,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f30.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f29,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f29.f64 = double(temp.f32);
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260DBD8;
	sub_8260D678(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r6,3340(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3340);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// fmr f4,f30
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f30.f64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260DC0C;
	sub_8260D678(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8260DC20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f10,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f28,f9
	f28.f64 = double(float(ctx.f9.f64));
	// lwz r4,24(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8260DC48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r3,r3
	ctx.r3.s64 = ctx.r3.s32;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// std r3,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r3.u64);
	// lfd f8,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// frsp f27,f7
	f27.f64 = double(float(ctx.f7.f64));
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260DC74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f6,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// fdivs f26,f31,f4
	f26.f64 = double(float(f31.f64 / ctx.f4.f64));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8260DCA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r5,r3
	ctx.r5.s64 = ctx.r3.s32;
	// stfs f26,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f3,112(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// stfs f27,136(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// stfs f28,140(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1496);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// fdivs f0,f31,f1
	f0.f64 = double(float(f31.f64 / ctx.f1.f64));
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260DCEC;
	sub_8218A6E0(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,3284(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3284);
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// fmr f4,f30
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f30.f64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260DD20;
	sub_8260D678(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260DD34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f28,f12
	f28.f64 = double(float(ctx.f12.f64));
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8260DD5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f11,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// frsp f27,f10
	f27.f64 = double(float(ctx.f10.f64));
	// lwz r4,28(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8260DD88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r3,r3
	ctx.r3.s64 = ctx.r3.s32;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// std r3,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r3.u64);
	// lfd f9,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// fdivs f26,f31,f7
	f26.f64 = double(float(f31.f64 / ctx.f7.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260DDB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// stfs f26,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// stfs f27,200(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f28,204(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,1496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1496);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lfd f6,112(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fdivs f3,f31,f4
	ctx.f3.f64 = double(float(f31.f64 / ctx.f4.f64));
	// stfs f3,192(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260DE04;
	sub_8218A6E0(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r6,3288(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3288);
	// fmr f4,f30
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f30.f64;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260DE38;
	sub_8260D678(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8260DE4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r5,r3
	ctx.r5.s64 = ctx.r3.s32;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f2,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f28,f1
	f28.f64 = double(float(ctx.f1.f64));
	// lwz r11,24(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260DE74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f27,f13
	f27.f64 = double(float(ctx.f13.f64));
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8260DE9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// std r7,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f12,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// fdivs f26,f31,f10
	f26.f64 = double(float(f31.f64 / ctx.f10.f64));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8260DEC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// stfs f26,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// std r4,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r4.u64);
	// lfd f9,112(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// stfs f27,152(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stfs f28,156(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1496);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// fdivs f6,f31,f7
	ctx.f6.f64 = double(float(f31.f64 / ctx.f7.f64));
	// stfs f6,144(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260DF14;
	sub_8218A6E0(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r6,3288(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3288);
	// fmr f4,f30
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f30.f64;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260DF48;
	sub_8260D678(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260DF5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f5,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f28,f4
	f28.f64 = double(float(ctx.f4.f64));
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8260DF84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f3,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f27,f2
	f27.f64 = double(float(ctx.f2.f64));
	// lwz r4,28(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8260DFAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r3,r3
	ctx.r3.s64 = ctx.r3.s32;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// std r3,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r3.u64);
	// lfd f1,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// fdivs f26,f31,f13
	f26.f64 = double(float(f31.f64 / ctx.f13.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260DFDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stfs f28,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lwz r5,1496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1496);
	// stfs f26,180(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f27,184(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// fdivs f9,f31,f10
	ctx.f9.f64 = double(float(f31.f64 / ctx.f10.f64));
	// stfs f9,176(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260E028;
	sub_8218A6E0(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,3288(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3288);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// fmr f4,f30
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f30.f64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260E05C;
	sub_8260D678(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8260E070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r5,r3
	ctx.r5.s64 = ctx.r3.s32;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f8,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// fdivs f28,f31,f6
	f28.f64 = double(float(f31.f64 / ctx.f6.f64));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260E09C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f5,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// fdivs f27,f31,f3
	f27.f64 = double(float(f31.f64 / ctx.f3.f64));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8260E0C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// std r7,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f2,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f26,f1
	f26.f64 = double(float(ctx.f1.f64));
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8260E0F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stfs f28,212(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// std r4,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r4.u64);
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// stfs f27,208(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,216(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f26,220(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260E128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8260E144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,284(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lwz r6,20364(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20364);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// bge cr6,0x8260e1e0
	if (!cr6.lt) goto loc_8260E1E0;
	// extsw r10,r29
	ctx.r10.s64 = r29.s32;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r7,r11,21712
	ctx.r7.s64 = r11.s64 + 21712;
	// lwz r11,21712(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21712);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// std r4,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r4.u64);
	// lfd f11,112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lfd f0,21560(r5)
	f0.u64 = PPC_LOAD_U64(ctx.r5.u32 + 21560);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fsub f12,f13,f0
	ctx.f12.f64 = ctx.f13.f64 - f0.f64;
	// fcmpu cr6,f10,f12
	cr6.compare(ctx.f10.f64, ctx.f12.f64);
	// bge cr6,0x8260e1b0
	if (!cr6.lt) goto loc_8260E1B0;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lwz r11,21716(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 21716);
	// addi r8,r6,1
	ctx.r8.s64 = ctx.r6.s64 + 1;
	// stw r8,20364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20364, ctx.r8.u32);
	// b 0x8260e1fc
	goto loc_8260E1FC;
loc_8260E1B0:
	// lwz r11,21716(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 21716);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r6,20364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20364, ctx.r6.u32);
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// stw r11,21716(r8)
	PPC_STORE_U32(ctx.r8.u32 + 21716, r11.u32);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8260e200
	if (cr6.lt) goto loc_8260E200;
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r11,21716(r8)
	PPC_STORE_U32(ctx.r8.u32 + 21716, r11.u32);
	// b 0x8260e200
	goto loc_8260E200;
loc_8260E1E0:
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stw r11,20364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20364, r11.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r7,r10,21712
	ctx.r7.s64 = ctx.r10.s64 + 21712;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stw r11,21716(r8)
	PPC_STORE_U32(ctx.r8.u32 + 21716, r11.u32);
loc_8260E1FC:
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
loc_8260E200:
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lwz r5,1496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1496);
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// std r10,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f12,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// li r9,5
	ctx.r9.s64 = 5;
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// li r8,1
	ctx.r8.s64 = 1;
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f26,f11,f28
	f26.f64 = double(float(ctx.f11.f64 * f28.f64));
	// fmuls f25,f9,f27
	f25.f64 = double(float(ctx.f9.f64 * f27.f64));
	// bl 0x8218a6e0
	ctx.lr = 0x8260E254;
	sub_8218A6E0(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lfs f0,3732(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f13,-13148(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// fmsubs f8,f25,f0,f13
	ctx.f8.f64 = double(float(f25.f64 * f0.f64 - ctx.f13.f64));
	// fnmsubs f7,f26,f0,f13
	ctx.f7.f64 = double(float(-(f26.f64 * f0.f64 - ctx.f13.f64)));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f26,f8,f27
	f26.f64 = double(float(ctx.f8.f64 + f27.f64));
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// fadds f25,f7,f28
	f25.f64 = double(float(ctx.f7.f64 + f28.f64));
	// fsubs f27,f8,f27
	f27.f64 = double(float(ctx.f8.f64 - f27.f64));
	// fsubs f24,f7,f28
	f24.f64 = double(float(ctx.f7.f64 - f28.f64));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260E2B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260E2C8;
	sub_82189CE0(ctx, base);
	// lwz r9,3264(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3264);
	// lis r28,-32126
	r28.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// fmr f9,f31
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f31.f64;
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// lwz r11,20360(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20360);
	// lfs f28,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f28.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f7,f28
	ctx.f7.f64 = f28.f64;
	// fmr f6,f28
	ctx.f6.f64 = f28.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// bl 0x82194b58
	ctx.lr = 0x8260E310;
	sub_82194B58(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,-25360(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -25360);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260E32C;
	sub_82189CE0(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8260E340;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// std r6,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r6.u64);
	// lfd f6,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f23,f5
	f23.f64 = double(float(ctx.f5.f64));
	// lwz r4,24(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8260E368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r3,r3
	ctx.r3.s64 = ctx.r3.s32;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// std r3,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r3.u64);
	// lfd f4,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// frsp f22,f3
	f22.f64 = double(float(ctx.f3.f64));
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260E394;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// std r8,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// lfd f2,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// fdivs f21,f31,f0
	f21.f64 = double(float(f31.f64 / f0.f64));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8260E3C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r5,r3
	ctx.r5.s64 = ctx.r3.s32;
	// stfs f21,244(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// std r5,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r5.u64);
	// lfd f13,120(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stfs f22,248(r1)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f23,252(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1496);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// fdivs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 / ctx.f11.f64));
	// stfs f10,240(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260E40C;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260E424;
	sub_82189CE0(ctx, base);
	// lwz r11,20360(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20360);
	// fmr f7,f28
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = f28.f64;
	// lwz r4,3292(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 3292);
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f6,f28
	ctx.f6.f64 = f28.f64;
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// fmr f4,f24
	ctx.f4.f64 = f24.f64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f3,f27
	ctx.f3.f64 = f27.f64;
	// stw r4,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// fmr f2,f25
	ctx.f2.f64 = f25.f64;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// bl 0x82194b58
	ctx.lr = 0x8260E460;
	sub_82194B58(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260E478;
	sub_82189CE0(ctx, base);
	// stw r30,3428(r31)
	PPC_STORE_U32(r31.u32 + 3428, r30.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r5,r31,3412
	ctx.r5.s64 = r31.s64 + 3412;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260E49C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r10,r8,29952
	ctx.r10.s64 = ctx.r8.s64 + 29952;
	// lwz r5,1500(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1500);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x8260E4D0;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1516(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1516);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r11,284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f9,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x8260E510;
	sub_8218A6E0(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfd f1,-32664(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r9.u32 + -32664);
	// bl 0x823db788
	ctx.lr = 0x8260E51C;
	sub_823DB788(ctx, base);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// lfs f5,288(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 288);
	ctx.f5.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,1504(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1504);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// fdivs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 / ctx.f5.f64));
	// stfs f4,112(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x8260E550;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260E568;
	sub_82189CE0(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,3296(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// fmr f5,f29
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f29.f64;
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260E59C;
	sub_8260D678(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260E5B4;
	sub_82189CE0(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba08
	ctx.lr = 0x8260E5C0;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8260E5C4"))) PPC_WEAK_FUNC(sub_8260E5C4);
PPC_FUNC_IMPL(__imp__sub_8260E5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260E5C8"))) PPC_WEAK_FUNC(sub_8260E5C8);
PPC_FUNC_IMPL(__imp__sub_8260E5C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// addi r8,r3,1712
	ctx.r8.s64 = ctx.r3.s64 + 1712;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// addi r7,r4,64
	ctx.r7.s64 = ctx.r4.s64 + 64;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r4,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r4,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,1776
	ctx.r8.s64 = ctx.r3.s64 + 1776;
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r7,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r7,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r7,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r4,128
	ctx.r7.s64 = ctx.r4.s64 + 128;
	// stvx128 v56,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,1840
	ctx.r8.s64 = ctx.r3.s64 + 1840;
	// lvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r7,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r7,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r7,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r4,192
	ctx.r7.s64 = ctx.r4.s64 + 192;
	// stvx128 v52,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,1904
	ctx.r8.s64 = ctx.r3.s64 + 1904;
	// lvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r7,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r7,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r7,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r4,256
	ctx.r7.s64 = ctx.r4.s64 + 256;
	// stvx128 v48,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,1968
	ctx.r8.s64 = ctx.r3.s64 + 1968;
	// lvx128 v47,r0,r7
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r7,r9
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r7,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r7,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2032
	ctx.r7.s64 = ctx.r3.s64 + 2032;
	// stvx128 v44,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,320
	ctx.r8.s64 = ctx.r4.s64 + 320;
	// lvx128 v43,r0,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r8,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r8,r10
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r8,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,384
	ctx.r8.s64 = ctx.r4.s64 + 384;
	// stvx128 v40,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2096
	ctx.r7.s64 = ctx.r3.s64 + 2096;
	// lvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r8,r9
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r8,r10
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r8,r11
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,448
	ctx.r8.s64 = ctx.r4.s64 + 448;
	// stvx128 v36,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2160
	ctx.r7.s64 = ctx.r3.s64 + 2160;
	// lvx128 v35,r0,r8
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r8,r9
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r8,r10
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r8,r11
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,512
	ctx.r8.s64 = ctx.r4.s64 + 512;
	// stvx128 v32,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2224
	ctx.r7.s64 = ctx.r3.s64 + 2224;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r8,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r8,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r8,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,576
	ctx.r8.s64 = ctx.r4.s64 + 576;
	// stvx128 v60,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2288
	ctx.r7.s64 = ctx.r3.s64 + 2288;
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r8,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r8,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r8,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,640
	ctx.r8.s64 = ctx.r4.s64 + 640;
	// stvx128 v56,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2352
	ctx.r7.s64 = ctx.r3.s64 + 2352;
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r8,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r8,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r8,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,704
	ctx.r8.s64 = ctx.r4.s64 + 704;
	// stvx128 v52,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2416
	ctx.r7.s64 = ctx.r3.s64 + 2416;
	// lvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r8,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r8,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r8,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,768
	ctx.r8.s64 = ctx.r4.s64 + 768;
	// stvx128 v48,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2480
	ctx.r7.s64 = ctx.r3.s64 + 2480;
	// lvx128 v47,r0,r8
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r8,r9
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r8,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r8,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,832
	ctx.r8.s64 = ctx.r4.s64 + 832;
	// stvx128 v44,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2544
	ctx.r7.s64 = ctx.r3.s64 + 2544;
	// lvx128 v43,r0,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r8,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r8,r10
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r8,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,896
	ctx.r8.s64 = ctx.r4.s64 + 896;
	// stvx128 v40,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2608
	ctx.r7.s64 = ctx.r3.s64 + 2608;
	// lvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r8,r9
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r8,r10
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r8,r11
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,960
	ctx.r8.s64 = ctx.r4.s64 + 960;
	// stvx128 v36,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2672
	ctx.r7.s64 = ctx.r3.s64 + 2672;
	// lvx128 v35,r0,r8
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r8,r9
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r8,r10
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r8,r11
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,1024
	ctx.r8.s64 = ctx.r4.s64 + 1024;
	// stvx128 v32,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2736
	ctx.r7.s64 = ctx.r3.s64 + 2736;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r8,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r8,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r8,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,1088
	ctx.r8.s64 = ctx.r4.s64 + 1088;
	// stvx128 v60,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2800
	ctx.r7.s64 = ctx.r3.s64 + 2800;
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r8,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r8,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r8,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,1152
	ctx.r8.s64 = ctx.r4.s64 + 1152;
	// stvx128 v56,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2864
	ctx.r7.s64 = ctx.r3.s64 + 2864;
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r8,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r8,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r8,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,1216
	ctx.r8.s64 = ctx.r4.s64 + 1216;
	// stvx128 v52,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2928
	ctx.r7.s64 = ctx.r3.s64 + 2928;
	// lvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r8,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r8,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r8,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,1280
	ctx.r8.s64 = ctx.r4.s64 + 1280;
	// stvx128 v48,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,2992
	ctx.r7.s64 = ctx.r3.s64 + 2992;
	// lvx128 v47,r0,r8
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r8,r9
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r8,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r8,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,1344
	ctx.r8.s64 = ctx.r4.s64 + 1344;
	// stvx128 v44,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,3056
	ctx.r7.s64 = ctx.r3.s64 + 3056;
	// lvx128 v43,r0,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r8,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r8,r10
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r8,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,1408
	ctx.r8.s64 = ctx.r4.s64 + 1408;
	// stvx128 v40,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,3120
	ctx.r7.s64 = ctx.r3.s64 + 3120;
	// lvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r8,r9
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r8,r10
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r8,r11
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,1472
	ctx.r8.s64 = ctx.r4.s64 + 1472;
	// stvx128 v36,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,3184
	ctx.r7.s64 = ctx.r3.s64 + 3184;
	// lvx128 v35,r0,r8
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r8,r9
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r8,r10
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r8,r11
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260E994"))) PPC_WEAK_FUNC(sub_8260E994);
PPC_FUNC_IMPL(__imp__sub_8260E994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260E998"))) PPC_WEAK_FUNC(sub_8260E998);
PPC_FUNC_IMPL(__imp__sub_8260E998) {
	PPC_FUNC_PROLOGUE();
	// stw r4,3252(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3252, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260E9A0"))) PPC_WEAK_FUNC(sub_8260E9A0);
PPC_FUNC_IMPL(__imp__sub_8260E9A0) {
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
	ctx.lr = 0x8260E9A8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,516(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 516);
	f0.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r5,3404(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3404);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260E9E0;
	sub_8218A6E0(ctx, base);
	// lfs f13,512(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 512);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,3400(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3400);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260EA0C;
	sub_8218A6E0(ctx, base);
	// bl 0x821789d8
	ctx.lr = 0x8260EA10;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260ea28
	if (cr6.eq) goto loc_8260EA28;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r29,17008(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x8260ea30
	goto loc_8260EA30;
loc_8260EA28:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r29,17016(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_8260EA30:
	// bl 0x821789d8
	ctx.lr = 0x8260EA34;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260ea4c
	if (cr6.eq) goto loc_8260EA4C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r30,17004(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x8260ea54
	goto loc_8260EA54;
loc_8260EA4C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r30,17012(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_8260EA54:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260EA68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// frsp f31,f13
	f31.f64 = double(float(ctx.f13.f64));
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8260EA90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r29
	ctx.r6.s64 = r29.s32;
	// extsw r5,r30
	ctx.r5.s64 = r30.s32;
	// stfs f31,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f11,112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// std r4,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r4.u64);
	// lfd f10,112(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// li r9,5
	ctx.r9.s64 = 5;
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// stfs f6,136(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// stfs f4,132(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,3260(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3260);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// stfs f5,128(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260EB00;
	sub_8218A6E0(ctx, base);
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,-26876(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -26876);
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// bl 0x8217c088
	ctx.lr = 0x8260EB14;
	sub_8217C088(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,9
	ctx.r9.s64 = 9;
	// lwz r5,3248(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3248);
	// li r8,24
	ctx.r8.s64 = 24;
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r31,1712
	ctx.r6.s64 = r31.s64 + 1712;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260EB38;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,3252(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3252);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,3256(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3256);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260EB50;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,3396(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3396);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260EB68;
	sub_82189CE0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r6,3392(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3392);
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r11,0
	r11.s64 = 0;
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f5,17032(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f4,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260EBAC;
	sub_8260D678(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8260EBB8"))) PPC_WEAK_FUNC(sub_8260EBB8);
PPC_FUNC_IMPL(__imp__sub_8260EBB8) {
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
	PPCRegister f29{};
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
	// bl 0x823d91f4
	ctx.lr = 0x8260EBC0;
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f29.u64);
	// stfd f30,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821789d8
	ctx.lr = 0x8260EBD8;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r28,-32131
	r28.s64 = -2105737216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260ebf4
	if (cr6.eq) goto loc_8260EBF4;
	// lwz r30,17008(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17008);
	// b 0x8260ebf8
	goto loc_8260EBF8;
loc_8260EBF4:
	// lwz r30,17016(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 17016);
loc_8260EBF8:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260EC0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r27,0
	r27.s64 = 0;
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bgt cr6,0x8260ec20
	if (cr6.gt) goto loc_8260EC20;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
loc_8260EC20:
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e38
	ctx.lr = 0x8260EC28;
	sub_82189E38(ctx, base);
	// bl 0x821789d8
	ctx.lr = 0x8260EC2C;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260ec40
	if (cr6.eq) goto loc_8260EC40;
	// lwz r30,17008(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17008);
	// b 0x8260ec44
	goto loc_8260EC44;
loc_8260EC40:
	// lwz r30,17016(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 17016);
loc_8260EC44:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260EC58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bgt cr6,0x8260ec68
	if (cr6.gt) goto loc_8260EC68;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
loc_8260EC68:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e38
	ctx.lr = 0x8260EC70;
	sub_82189E38(ctx, base);
	// lfs f0,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 344);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r5,1556(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1556);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r30,-25232(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// bl 0x8218a6e0
	ctx.lr = 0x8260ECA4;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1520(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1520);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260ECC8;
	sub_8218A6E0(ctx, base);
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1524(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260ECF4;
	sub_8218A6E0(ctx, base);
	// lfs f12,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 312);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1528(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1528);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260ED20;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r29,r31,240
	r29.s64 = r31.s64 + 240;
	// lwz r5,1536(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1536);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x8260ED48;
	sub_8218A6E0(ctx, base);
	// lwz r9,316(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x8260efac
	if (!cr6.eq) goto loc_8260EFAC;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8260ED68;
	sub_8217C088(ctx, base);
	// lwz r11,-26876(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821cec00
	ctx.lr = 0x8260EDB4;
	sub_821CEC00(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,9
	ctx.r9.s64 = 9;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260EDD8;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1536(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1536);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260EDFC;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,88(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,168(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260EE14;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,1596(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1596);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,1632
	ctx.r6.s64 = r31.s64 + 1632;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260EE38;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,140(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260EE50;
	sub_82189CE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8260da68
	ctx.lr = 0x8260EE58;
	sub_8260DA68(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,172(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260EE70;
	sub_82189CE0(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8260EEA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8260eec0
	if (cr6.eq) goto loc_8260EEC0;
	// lbz r11,1622(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1622);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260eec0
	if (cr6.eq) goto loc_8260EEC0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c3048
	ctx.lr = 0x8260EEC0;
	sub_821C3048(ctx, base);
loc_8260EEC0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r5,r31,3412
	ctx.r5.s64 = r31.s64 + 3412;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260EEE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1708(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1708);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,432
	ctx.r6.s64 = r31.s64 + 432;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260EF04;
	sub_8218A6E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8260d9c0
	ctx.lr = 0x8260EF0C;
	sub_8260D9C0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260EF24;
	sub_82189CE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8260e9a0
	ctx.lr = 0x8260EF2C;
	sub_8260E9A0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r7,140(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r6,3300(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3300);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lfs f31,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f31.f64 = double(temp.f32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// lfs f29,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f29.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260EF78;
	sub_8260D678(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r7,140(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,3304(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3304);
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// fmr f4,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f31.f64;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmr f5,f29
	ctx.f5.f64 = f29.f64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260EFAC;
	sub_8260D678(ctx, base);
loc_8260EFAC:
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e60
	ctx.lr = 0x8260EFB4;
	sub_82189E60(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e60
	ctx.lr = 0x8260EFBC;
	sub_82189E60(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8260EFD0"))) PPC_WEAK_FUNC(sub_8260EFD0);
PPC_FUNC_IMPL(__imp__sub_8260EFD0) {
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
	// bl 0x8217fff8
	ctx.lr = 0x8260EFE0;
	sub_8217FFF8(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r10,r11,21676
	ctx.r10.s64 = r11.s64 + 21676;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260f000
	if (cr6.eq) goto loc_8260F000;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82189e80
	ctx.lr = 0x8260F000;
	sub_82189E80(ctx, base);
loc_8260F000:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x8217f768
	ctx.lr = 0x8260F00C;
	sub_8217F768(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260F01C"))) PPC_WEAK_FUNC(sub_8260F01C);
PPC_FUNC_IMPL(__imp__sub_8260F01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260F020"))) PPC_WEAK_FUNC(sub_8260F020);
PPC_FUNC_IMPL(__imp__sub_8260F020) {
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
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lwz r3,21664(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 21664);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8260f054
	if (cr6.eq) goto loc_8260F054;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260F054;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F054:
	// li r11,0
	r11.s64 = 0;
	// stw r11,21664(r31)
	PPC_STORE_U32(r31.u32 + 21664, r11.u32);
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

__attribute__((alias("__imp__sub_8260F070"))) PPC_WEAK_FUNC(sub_8260F070);
PPC_FUNC_IMPL(__imp__sub_8260F070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8260F078;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9c8
	ctx.lr = 0x8260F080;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f29,f2
	f29.f64 = ctx.f2.f64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// fmr f27,f4
	f27.f64 = ctx.f4.f64;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260F0B8;
	sub_82189CE0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260F0CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// frsp f26,f13
	f26.f64 = double(float(ctx.f13.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8260F0F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f12,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lwz r4,28(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// frsp f25,f11
	f25.f64 = double(float(ctx.f11.f64));
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8260F11C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r3,r3
	ctx.r3.s64 = ctx.r3.s32;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r3,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r3.u64);
	// lfd f10,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// fdivs f24,f31,f8
	f24.f64 = double(float(f31.f64 / ctx.f8.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8260F150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// stfs f24,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f7,112(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// stfs f25,136(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f26,140(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1496);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// fdivs f4,f31,f5
	ctx.f4.f64 = double(float(f31.f64 / ctx.f5.f64));
	// stfs f4,128(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260F19C;
	sub_8218A6E0(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f7,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// li r11,-1
	r11.s64 = -1;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r29.u32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f4,f27
	ctx.f4.f64 = f27.f64;
	// lfs f5,17032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// bl 0x82194b58
	ctx.lr = 0x8260F1DC;
	sub_82194B58(ctx, base);
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,-25360(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25360);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260F1F8;
	sub_82189CE0(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba14
	ctx.lr = 0x8260F204;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8260F208"))) PPC_WEAK_FUNC(sub_8260F208);
PPC_FUNC_IMPL(__imp__sub_8260F208) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f25{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9cc
	ctx.lr = 0x8260F21C;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lfs f28,-28408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28408);
	f28.f64 = double(temp.f32);
	// lfs f31,24548(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24548);
	f31.f64 = double(temp.f32);
	// fmr f4,f28
	ctx.f4.f64 = f28.f64;
	// lfs f30,-32524(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32524);
	f30.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lwz r5,3264(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3264);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lfs f2,100(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8260f070
	ctx.lr = 0x8260F25C;
	sub_8260F070(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,3268(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3268);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f29,-28412(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -28412);
	f29.f64 = double(temp.f32);
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// bl 0x8260f070
	ctx.lr = 0x8260F284;
	sub_8260F070(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lwz r5,3268(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f27,-28416(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -28416);
	f27.f64 = double(temp.f32);
	// fmr f4,f27
	ctx.f4.f64 = f27.f64;
	// bl 0x8260f070
	ctx.lr = 0x8260F2AC;
	sub_8260F070(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r5,3268(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f26,-28420(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28420);
	f26.f64 = double(temp.f32);
	// fmr f4,f26
	ctx.f4.f64 = f26.f64;
	// bl 0x8260f070
	ctx.lr = 0x8260F2D4;
	sub_8260F070(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r5,3268(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f26
	ctx.f2.f64 = f26.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f25,-28424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28424);
	f25.f64 = double(temp.f32);
	// fmr f4,f25
	ctx.f4.f64 = f25.f64;
	// bl 0x8260f070
	ctx.lr = 0x8260F2FC;
	sub_8260F070(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f2,f28
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f28.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,3264(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3264);
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f28,31492(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31492);
	f28.f64 = double(temp.f32);
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// bl 0x8260f070
	ctx.lr = 0x8260F324;
	sub_8260F070(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,3264(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3264);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// fmr f4,f27
	ctx.f4.f64 = f27.f64;
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// bl 0x8260f070
	ctx.lr = 0x8260F344;
	sub_8260F070(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lwz r5,3268(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3268);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f25
	ctx.f2.f64 = f25.f64;
	// lfs f29,-28428(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -28428);
	f29.f64 = double(temp.f32);
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8260f070
	ctx.lr = 0x8260F36C;
	sub_8260F070(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lwz r5,3268(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f4,-28432(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -28432);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8260f070
	ctx.lr = 0x8260F390;
	sub_8260F070(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,3264(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 3264);
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// fmr f4,f25
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f25.f64;
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// fmr f2,f26
	ctx.f2.f64 = f26.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8260f070
	ctx.lr = 0x8260F3B0;
	sub_8260F070(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba18
	ctx.lr = 0x8260F3BC;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260F3CC"))) PPC_WEAK_FUNC(sub_8260F3CC);
PPC_FUNC_IMPL(__imp__sub_8260F3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260F3D0"))) PPC_WEAK_FUNC(sub_8260F3D0);
PPC_FUNC_IMPL(__imp__sub_8260F3D0) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,-28400
	ctx.r10.s64 = r11.s64 + -28400;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8260f400
	if (cr6.eq) goto loc_8260F400;
	// bl 0x82130588
	ctx.lr = 0x8260F400;
	sub_82130588(ctx, base);
loc_8260F400:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8260f410
	if (cr6.eq) goto loc_8260F410;
	// bl 0x82130588
	ctx.lr = 0x8260F410;
	sub_82130588(ctx, base);
loc_8260F410:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8260f420
	if (cr6.eq) goto loc_8260F420;
	// bl 0x82130588
	ctx.lr = 0x8260F420;
	sub_82130588(ctx, base);
loc_8260F420:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8260f440
	if (cr6.eq) goto loc_8260F440;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260F440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F440:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8260F448;
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

__attribute__((alias("__imp__sub_8260F45C"))) PPC_WEAK_FUNC(sub_8260F45C);
PPC_FUNC_IMPL(__imp__sub_8260F45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260F460"))) PPC_WEAK_FUNC(sub_8260F460);
PPC_FUNC_IMPL(__imp__sub_8260F460) {
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
	ctx.lr = 0x8260F468;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f4b4
	if (cr6.eq) goto loc_8260F4B4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F488;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f4b0
	if (!cr6.eq) goto loc_8260F4B0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f4b0
	if (cr6.eq) goto loc_8260F4B0;
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
	ctx.lr = 0x8260F4B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F4B0:
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
loc_8260F4B4:
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f4f4
	if (cr6.eq) goto loc_8260F4F4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F4C8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f4f0
	if (!cr6.eq) goto loc_8260F4F0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f4f0
	if (cr6.eq) goto loc_8260F4F0;
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
	ctx.lr = 0x8260F4F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F4F0:
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
loc_8260F4F4:
	// lwz r30,24(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f534
	if (cr6.eq) goto loc_8260F534;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F508;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f530
	if (!cr6.eq) goto loc_8260F530;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f530
	if (cr6.eq) goto loc_8260F530;
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
	ctx.lr = 0x8260F530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F530:
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
loc_8260F534:
	// lwz r30,28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f574
	if (cr6.eq) goto loc_8260F574;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F548;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f570
	if (!cr6.eq) goto loc_8260F570;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f570
	if (cr6.eq) goto loc_8260F570;
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
	ctx.lr = 0x8260F570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F570:
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
loc_8260F574:
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f5b4
	if (cr6.eq) goto loc_8260F5B4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F588;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f5b0
	if (!cr6.eq) goto loc_8260F5B0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f5b0
	if (cr6.eq) goto loc_8260F5B0;
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
	ctx.lr = 0x8260F5B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F5B0:
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
loc_8260F5B4:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f5f4
	if (cr6.eq) goto loc_8260F5F4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F5C8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f5f0
	if (!cr6.eq) goto loc_8260F5F0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f5f0
	if (cr6.eq) goto loc_8260F5F0;
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
	ctx.lr = 0x8260F5F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F5F0:
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
loc_8260F5F4:
	// lwz r30,40(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f634
	if (cr6.eq) goto loc_8260F634;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F608;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f630
	if (!cr6.eq) goto loc_8260F630;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f630
	if (cr6.eq) goto loc_8260F630;
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
	ctx.lr = 0x8260F630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F630:
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
loc_8260F634:
	// lwz r30,44(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f674
	if (cr6.eq) goto loc_8260F674;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F648;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f670
	if (!cr6.eq) goto loc_8260F670;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f670
	if (cr6.eq) goto loc_8260F670;
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
	ctx.lr = 0x8260F670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F670:
	// stw r29,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r29.u32);
loc_8260F674:
	// lwz r30,56(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f6b4
	if (cr6.eq) goto loc_8260F6B4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F688;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f6b0
	if (!cr6.eq) goto loc_8260F6B0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f6b0
	if (cr6.eq) goto loc_8260F6B0;
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
	ctx.lr = 0x8260F6B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F6B0:
	// stw r29,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r29.u32);
loc_8260F6B4:
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f6f4
	if (cr6.eq) goto loc_8260F6F4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F6C8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f6f0
	if (!cr6.eq) goto loc_8260F6F0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f6f0
	if (cr6.eq) goto loc_8260F6F0;
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
	ctx.lr = 0x8260F6F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F6F0:
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
loc_8260F6F4:
	// lwz r30,64(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f734
	if (cr6.eq) goto loc_8260F734;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F708;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f730
	if (!cr6.eq) goto loc_8260F730;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f730
	if (cr6.eq) goto loc_8260F730;
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
	ctx.lr = 0x8260F730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F730:
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
loc_8260F734:
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f774
	if (cr6.eq) goto loc_8260F774;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F748;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f770
	if (!cr6.eq) goto loc_8260F770;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f770
	if (cr6.eq) goto loc_8260F770;
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
	ctx.lr = 0x8260F770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F770:
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
loc_8260F774:
	// lwz r30,124(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f7b4
	if (cr6.eq) goto loc_8260F7B4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F788;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f7b0
	if (!cr6.eq) goto loc_8260F7B0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f7b0
	if (cr6.eq) goto loc_8260F7B0;
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
	ctx.lr = 0x8260F7B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F7B0:
	// stw r29,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r29.u32);
loc_8260F7B4:
	// lwz r30,100(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f7f4
	if (cr6.eq) goto loc_8260F7F4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F7C8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f7f0
	if (!cr6.eq) goto loc_8260F7F0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f7f0
	if (cr6.eq) goto loc_8260F7F0;
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
	ctx.lr = 0x8260F7F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F7F0:
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
loc_8260F7F4:
	// lwz r30,104(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f834
	if (cr6.eq) goto loc_8260F834;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8260F808;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8260f830
	if (!cr6.eq) goto loc_8260F830;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8260f830
	if (cr6.eq) goto loc_8260F830;
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
	ctx.lr = 0x8260F830;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8260F830:
	// stw r29,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r29.u32);
loc_8260F834:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8260F83C"))) PPC_WEAK_FUNC(sub_8260F83C);
PPC_FUNC_IMPL(__imp__sub_8260F83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260F840"))) PPC_WEAK_FUNC(sub_8260F840);
PPC_FUNC_IMPL(__imp__sub_8260F840) {
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
	ctx.lr = 0x8260F848;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r28,r11,-17676
	r28.s64 = r11.s64 + -17676;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r28
	r31.u64 = r28.u64;
	// addi r25,r10,-18164
	r25.s64 = ctx.r10.s64 + -18164;
	// addi r29,r11,9572
	r29.s64 = r11.s64 + 9572;
loc_8260F874:
	// lwz r11,108(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8260f890
	if (cr6.lt) goto loc_8260F890;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bge cr6,0x8260f890
	if (!cr6.lt) goto loc_8260F890;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x8260f894
	goto loc_8260F894;
loc_8260F890:
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
loc_8260F894:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8260F8A4;
	sub_82137A08(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8260F8AC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8260f8d0
	if (cr6.eq) goto loc_8260F8D0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8260f8ac
	if (cr6.eq) goto loc_8260F8AC;
loc_8260F8D0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8260f8fc
	if (cr6.eq) goto loc_8260F8FC;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r28,12
	r11.s64 = r28.s64 + 12;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8260f874
	if (cr6.lt) goto loc_8260F874;
	// li r11,1
	r11.s64 = 1;
	// stw r11,108(r26)
	PPC_STORE_U32(r26.u32 + 108, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
loc_8260F8FC:
	// stw r30,108(r26)
	PPC_STORE_U32(r26.u32 + 108, r30.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8260F908"))) PPC_WEAK_FUNC(sub_8260F908);
PPC_FUNC_IMPL(__imp__sub_8260F908) {
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
	ctx.lr = 0x8260F910;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-28400
	ctx.r10.s64 = r11.s64 + -28400;
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// bl 0x8260c710
	ctx.lr = 0x8260F93C;
	sub_8260C710(ctx, base);
	// addi r3,r31,528
	ctx.r3.s64 = r31.s64 + 528;
	// li r29,2
	r29.s64 = 2;
loc_8260F944:
	// bl 0x8260c710
	ctx.lr = 0x8260F948;
	sub_8260C710(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r3,r3,320
	ctx.r3.s64 = ctx.r3.s64 + 320;
	// bge 0x8260f944
	if (!cr0.lt) goto loc_8260F944;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-256
	ctx.r7.s64 = -16777216;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stfs f0,3412(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3412, temp.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stfs f0,3416(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3416, temp.u32);
	// stw r7,3420(r31)
	PPC_STORE_U32(r31.u32 + 3420, ctx.r7.u32);
	// stw r30,3424(r31)
	PPC_STORE_U32(r31.u32 + 3424, r30.u32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r30,3428(r31)
	PPC_STORE_U32(r31.u32 + 3428, r30.u32);
	// lfs f13,30712(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,3432(r31)
	PPC_STORE_U8(r31.u32 + 3432, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,3433(r31)
	PPC_STORE_U8(r31.u32 + 3433, r30.u8);
	// stb r30,3434(r31)
	PPC_STORE_U8(r31.u32 + 3434, r30.u8);
	// stb r11,3435(r31)
	PPC_STORE_U8(r31.u32 + 3435, r11.u8);
	// stb r11,3436(r31)
	PPC_STORE_U8(r31.u32 + 3436, r11.u8);
	// stfs f0,1492(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1492, temp.u32);
	// stfs f13,196(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// stw r30,1496(r31)
	PPC_STORE_U32(r31.u32 + 1496, r30.u32);
	// stw r30,1500(r31)
	PPC_STORE_U32(r31.u32 + 1500, r30.u32);
	// stw r30,1516(r31)
	PPC_STORE_U32(r31.u32 + 1516, r30.u32);
	// stw r30,1504(r31)
	PPC_STORE_U32(r31.u32 + 1504, r30.u32);
	// stw r30,1508(r31)
	PPC_STORE_U32(r31.u32 + 1508, r30.u32);
	// stw r30,1512(r31)
	PPC_STORE_U32(r31.u32 + 1512, r30.u32);
	// stw r30,1520(r31)
	PPC_STORE_U32(r31.u32 + 1520, r30.u32);
	// stw r30,1524(r31)
	PPC_STORE_U32(r31.u32 + 1524, r30.u32);
	// stw r30,1528(r31)
	PPC_STORE_U32(r31.u32 + 1528, r30.u32);
	// stw r30,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r30.u32);
	// stb r30,122(r31)
	PPC_STORE_U8(r31.u32 + 122, r30.u8);
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
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
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r30.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// stw r6,3408(r31)
	PPC_STORE_U32(r31.u32 + 3408, ctx.r6.u32);
	// stb r30,1488(r31)
	PPC_STORE_U8(r31.u32 + 1488, r30.u8);
	// stw r5,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r5.u32);
	// stb r11,1621(r31)
	PPC_STORE_U8(r31.u32 + 1621, r11.u8);
	// stb r30,1623(r31)
	PPC_STORE_U8(r31.u32 + 1623, r30.u8);
	// stb r11,121(r31)
	PPC_STORE_U8(r31.u32 + 121, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8260FA50"))) PPC_WEAK_FUNC(sub_8260FA50);
PPC_FUNC_IMPL(__imp__sub_8260FA50) {
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
	// bl 0x8260f3d0
	ctx.lr = 0x8260FA70;
	sub_8260F3D0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260fa88
	if (cr6.eq) goto loc_8260FA88;
	// bl 0x82130588
	ctx.lr = 0x8260FA84;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8260FA88:
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

__attribute__((alias("__imp__sub_8260FAA0"))) PPC_WEAK_FUNC(sub_8260FAA0);
PPC_FUNC_IMPL(__imp__sub_8260FAA0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8260FAA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821789d8
	ctx.lr = 0x8260FAB4;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r28,-32131
	r28.s64 = -2105737216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260fad0
	if (cr6.eq) goto loc_8260FAD0;
	// lwz r30,17008(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17008);
	// b 0x8260fad4
	goto loc_8260FAD4;
loc_8260FAD0:
	// lwz r30,17016(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 17016);
loc_8260FAD4:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260FAE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r27,0
	r27.s64 = 0;
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bgt cr6,0x8260fafc
	if (cr6.gt) goto loc_8260FAFC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
loc_8260FAFC:
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e38
	ctx.lr = 0x8260FB04;
	sub_82189E38(ctx, base);
	// bl 0x821789d8
	ctx.lr = 0x8260FB08;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260fb1c
	if (cr6.eq) goto loc_8260FB1C;
	// lwz r30,17008(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17008);
	// b 0x8260fb20
	goto loc_8260FB20;
loc_8260FB1C:
	// lwz r30,17016(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 17016);
loc_8260FB20:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8260FB34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bgt cr6,0x8260fb44
	if (cr6.gt) goto loc_8260FB44;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
loc_8260FB44:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e38
	ctx.lr = 0x8260FB4C;
	sub_82189E38(ctx, base);
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r30,92(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bne cr6,0x8260fba0
	if (!cr6.eq) goto loc_8260FBA0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r6,3328(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3328);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f4,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f3,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f5,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260FB9C;
	sub_8260D678(ctx, base);
	// b 0x8260ff24
	goto loc_8260FF24;
loc_8260FBA0:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8260fbec
	if (!cr6.eq) goto loc_8260FBEC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r6,3332(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3332);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f4,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f3,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f5,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260FBE8;
	sub_8260D678(ctx, base);
	// b 0x8260ff24
	goto loc_8260FF24;
loc_8260FBEC:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8260ff24
	if (!cr6.eq) goto loc_8260FF24;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8260FC08;
	sub_8217C088(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260FC20;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,56(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260FC38;
	sub_82189CE0(ctx, base);
	// lbz r9,340(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 340);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8260fd80
	if (!cr6.eq) goto loc_8260FD80;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,504(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 504);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8260fd3c
	if (!cr6.gt) goto loc_8260FD3C;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260FC74;
	sub_82189CE0(ctx, base);
	// lfs f0,500(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	f0.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260FCA0;
	sub_8218A6E0(ctx, base);
	// lfs f13,504(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 504);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,188(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260FCCC;
	sub_8218A6E0(ctx, base);
	// lfs f12,508(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 508);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,192(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260FCF8;
	sub_8218A6E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r6,3320(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3320);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f4,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f3,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f5,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260FD38;
	sub_8260D678(ctx, base);
	// b 0x8260fef4
	goto loc_8260FEF4;
loc_8260FD3C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r6,3312(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3312);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f4,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f3,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// lfs f5,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260FD7C;
	sub_8260D678(ctx, base);
	// b 0x8260ff0c
	goto loc_8260FF0C;
loc_8260FD80:
	// lfs f0,324(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 324);
	f0.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,1540(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1540);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260FDAC;
	sub_8218A6E0(ctx, base);
	// lfs f13,328(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 328);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1544(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1544);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260FDD8;
	sub_8218A6E0(ctx, base);
	// lfs f12,336(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 336);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1552(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1552);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260FE04;
	sub_8218A6E0(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lfs f11,332(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 332);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,21720(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21720);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	f0.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f0,21720(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 21720, temp.u32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// blt cr6,0x8260fe40
	if (cr6.lt) goto loc_8260FE40;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,21720(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 21720, temp.u32);
loc_8260FE40:
	// lwz r5,1500(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1500);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8260fe70
	if (cr6.eq) goto loc_8260FE70;
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260FE70;
	sub_8218A6E0(ctx, base);
loc_8260FE70:
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 300);
	f0.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,1524(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1524);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8260FE9C;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260FEB4;
	sub_82189CE0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r7,132(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r6,3324(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3324);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f4,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f3,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// lfs f5,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// bl 0x8260d678
	ctx.lr = 0x8260FEF4;
	sub_8260D678(ctx, base);
loc_8260FEF4:
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260FF0C;
	sub_82189CE0(ctx, base);
loc_8260FF0C:
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8260FF24;
	sub_82189CE0(ctx, base);
loc_8260FF24:
	// lbz r11,356(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 356);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8260ff38
	if (cr6.eq) goto loc_8260FF38;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8260f208
	ctx.lr = 0x8260FF38;
	sub_8260F208(ctx, base);
loc_8260FF38:
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e60
	ctx.lr = 0x8260FF40;
	sub_82189E60(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e60
	ctx.lr = 0x8260FF48;
	sub_82189E60(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8260FF50"))) PPC_WEAK_FUNC(sub_8260FF50);
PPC_FUNC_IMPL(__imp__sub_8260FF50) {
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
	// li r3,3440
	ctx.r3.s64 = 3440;
	// bl 0x82130528
	ctx.lr = 0x8260FF64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8260ff88
	if (cr6.eq) goto loc_8260FF88;
	// bl 0x8260f908
	ctx.lr = 0x8260FF70;
	sub_8260F908(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// stw r3,21664(r11)
	PPC_STORE_U32(r11.u32 + 21664, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8260FF88:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// stw r11,21664(r10)
	PPC_STORE_U32(ctx.r10.u32 + 21664, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8260FFA4"))) PPC_WEAK_FUNC(sub_8260FFA4);
PPC_FUNC_IMPL(__imp__sub_8260FFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8260FFA8"))) PPC_WEAK_FUNC(sub_8260FFA8);
PPC_FUNC_IMPL(__imp__sub_8260FFA8) {
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
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8260FFB0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,2828(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// bl 0x821c0210
	ctx.lr = 0x8260FFD8;
	sub_821C0210(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82610030
	if (cr6.eq) goto loc_82610030;
	// lwz r28,0(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,-27772
	ctx.r10.s64 = r11.s64 + -27772;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
loc_8260FFF4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82610018
	if (cr6.eq) goto loc_82610018;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8260fff4
	if (cr6.eq) goto loc_8260FFF4;
loc_82610018:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8261003c
	if (cr6.eq) goto loc_8261003C;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-27872
	ctx.r3.s64 = r11.s64 + -27872;
	// bl 0x82130000
	ctx.lr = 0x82610030;
	sub_82130000(ctx, base);
loc_82610030:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
loc_8261003C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-17952
	ctx.r4.s64 = r11.s64 + -17952;
	// bl 0x821c7490
	ctx.lr = 0x8261004C;
	sub_821C7490(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610058
	if (cr6.eq) goto loc_82610058;
	// bl 0x821c64f0
	ctx.lr = 0x82610058;
	sub_821C64F0(ctx, base);
loc_82610058:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-27896
	ctx.r4.s64 = r11.s64 + -27896;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x8261006C;
	sub_821C82A8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r31,r11,9792
	r31.s64 = r11.s64 + 9792;
	// beq cr6,0x826100a4
	if (cr6.eq) goto loc_826100A4;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610094
	if (cr6.eq) goto loc_82610094;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610098
	goto loc_82610098;
loc_82610094:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82610098:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,48
	ctx.r5.s64 = r29.s64 + 48;
	// bl 0x823ddb08
	ctx.lr = 0x826100A4;
	sub_823DDB08(ctx, base);
loc_826100A4:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-27916
	ctx.r4.s64 = r11.s64 + -27916;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826100B8;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826100e4
	if (cr6.eq) goto loc_826100E4;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826100d4
	if (cr6.eq) goto loc_826100D4;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826100d8
	goto loc_826100D8;
loc_826100D4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826100D8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,52
	ctx.r5.s64 = r29.s64 + 52;
	// bl 0x823ddb08
	ctx.lr = 0x826100E4;
	sub_823DDB08(ctx, base);
loc_826100E4:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-27932
	ctx.r4.s64 = r11.s64 + -27932;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826100F8;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610124
	if (cr6.eq) goto loc_82610124;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610114
	if (cr6.eq) goto loc_82610114;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610118
	goto loc_82610118;
loc_82610114:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82610118:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,100
	ctx.r5.s64 = r29.s64 + 100;
	// bl 0x823ddb08
	ctx.lr = 0x82610124;
	sub_823DDB08(ctx, base);
loc_82610124:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-27944
	ctx.r4.s64 = r11.s64 + -27944;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610138;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610164
	if (cr6.eq) goto loc_82610164;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610154
	if (cr6.eq) goto loc_82610154;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610158
	goto loc_82610158;
loc_82610154:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82610158:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,56
	ctx.r5.s64 = r29.s64 + 56;
	// bl 0x823ddb08
	ctx.lr = 0x82610164;
	sub_823DDB08(ctx, base);
loc_82610164:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-27968
	ctx.r4.s64 = r11.s64 + -27968;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610178;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826101a4
	if (cr6.eq) goto loc_826101A4;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610194
	if (cr6.eq) goto loc_82610194;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610198
	goto loc_82610198;
loc_82610194:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82610198:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,60
	ctx.r5.s64 = r29.s64 + 60;
	// bl 0x823ddb08
	ctx.lr = 0x826101A4;
	sub_823DDB08(ctx, base);
loc_826101A4:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-27988
	ctx.r4.s64 = r11.s64 + -27988;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826101B8;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826101e4
	if (cr6.eq) goto loc_826101E4;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826101d4
	if (cr6.eq) goto loc_826101D4;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826101d8
	goto loc_826101D8;
loc_826101D4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826101D8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,64
	ctx.r5.s64 = r29.s64 + 64;
	// bl 0x823ddb08
	ctx.lr = 0x826101E4;
	sub_823DDB08(ctx, base);
loc_826101E4:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28008
	ctx.r4.s64 = r11.s64 + -28008;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826101F8;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610224
	if (cr6.eq) goto loc_82610224;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610214
	if (cr6.eq) goto loc_82610214;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610218
	goto loc_82610218;
loc_82610214:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82610218:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,72
	ctx.r5.s64 = r29.s64 + 72;
	// bl 0x823ddb08
	ctx.lr = 0x82610224;
	sub_823DDB08(ctx, base);
loc_82610224:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28032
	ctx.r4.s64 = r11.s64 + -28032;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610238;
	sub_821C82A8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,32684
	r30.s64 = r11.s64 + 32684;
	// beq cr6,0x8261026c
	if (cr6.eq) goto loc_8261026C;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261025c
	if (cr6.eq) goto loc_8261025C;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610260
	goto loc_82610260;
loc_8261025C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82610260:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r29,76
	ctx.r5.s64 = r29.s64 + 76;
	// bl 0x823ddb08
	ctx.lr = 0x8261026C;
	sub_823DDB08(ctx, base);
loc_8261026C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28048
	ctx.r4.s64 = r11.s64 + -28048;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610280;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826102ac
	if (cr6.eq) goto loc_826102AC;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261029c
	if (cr6.eq) goto loc_8261029C;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826102a0
	goto loc_826102A0;
loc_8261029C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826102A0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,68
	ctx.r5.s64 = r29.s64 + 68;
	// bl 0x823ddb08
	ctx.lr = 0x826102AC;
	sub_823DDB08(ctx, base);
loc_826102AC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28056
	ctx.r4.s64 = r11.s64 + -28056;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826102C0;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826102ec
	if (cr6.eq) goto loc_826102EC;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826102dc
	if (cr6.eq) goto loc_826102DC;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826102e0
	goto loc_826102E0;
loc_826102DC:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826102E0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,80
	ctx.r5.s64 = r29.s64 + 80;
	// bl 0x823ddb08
	ctx.lr = 0x826102EC;
	sub_823DDB08(ctx, base);
loc_826102EC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28072
	ctx.r4.s64 = r11.s64 + -28072;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610300;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261032c
	if (cr6.eq) goto loc_8261032C;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261031c
	if (cr6.eq) goto loc_8261031C;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610320
	goto loc_82610320;
loc_8261031C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82610320:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,84
	ctx.r5.s64 = r29.s64 + 84;
	// bl 0x823ddb08
	ctx.lr = 0x8261032C;
	sub_823DDB08(ctx, base);
loc_8261032C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28084
	ctx.r4.s64 = r11.s64 + -28084;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610340;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610368
	if (cr6.eq) goto loc_82610368;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261035c
	if (cr6.eq) goto loc_8261035C;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610360
	goto loc_82610360;
loc_8261035C:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82610360:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82610368:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28100
	ctx.r4.s64 = r11.s64 + -28100;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x8261037C;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826103a8
	if (cr6.eq) goto loc_826103A8;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610398
	if (cr6.eq) goto loc_82610398;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x8261039c
	goto loc_8261039C;
loc_82610398:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8261039C:
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826103A8:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28112
	ctx.r4.s64 = r11.s64 + -28112;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826103BC;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826103e8
	if (cr6.eq) goto loc_826103E8;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826103d8
	if (cr6.eq) goto loc_826103D8;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826103dc
	goto loc_826103DC;
loc_826103D8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826103DC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,88
	ctx.r5.s64 = r29.s64 + 88;
	// bl 0x823ddb08
	ctx.lr = 0x826103E8;
	sub_823DDB08(ctx, base);
loc_826103E8:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28132
	ctx.r4.s64 = r11.s64 + -28132;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826103FC;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610428
	if (cr6.eq) goto loc_82610428;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610418
	if (cr6.eq) goto loc_82610418;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x8261041c
	goto loc_8261041C;
loc_82610418:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8261041C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,92
	ctx.r5.s64 = r29.s64 + 92;
	// bl 0x823ddb08
	ctx.lr = 0x82610428;
	sub_823DDB08(ctx, base);
loc_82610428:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28136
	ctx.r4.s64 = r11.s64 + -28136;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x8261043C;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610468
	if (cr6.eq) goto loc_82610468;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610458
	if (cr6.eq) goto loc_82610458;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x8261045c
	goto loc_8261045C;
loc_82610458:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8261045C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,96
	ctx.r5.s64 = r29.s64 + 96;
	// bl 0x823ddb08
	ctx.lr = 0x82610468;
	sub_823DDB08(ctx, base);
loc_82610468:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28152
	ctx.r4.s64 = r11.s64 + -28152;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x8261047C;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826104a8
	if (cr6.eq) goto loc_826104A8;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610498
	if (cr6.eq) goto loc_82610498;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x8261049c
	goto loc_8261049C;
loc_82610498:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8261049C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,116
	ctx.r5.s64 = r29.s64 + 116;
	// bl 0x823ddb08
	ctx.lr = 0x826104A8;
	sub_823DDB08(ctx, base);
loc_826104A8:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28172
	ctx.r4.s64 = r11.s64 + -28172;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826104BC;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826104e8
	if (cr6.eq) goto loc_826104E8;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826104d8
	if (cr6.eq) goto loc_826104D8;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826104dc
	goto loc_826104DC;
loc_826104D8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826104DC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,120
	ctx.r5.s64 = r29.s64 + 120;
	// bl 0x823ddb08
	ctx.lr = 0x826104E8;
	sub_823DDB08(ctx, base);
loc_826104E8:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28184
	ctx.r4.s64 = r11.s64 + -28184;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826104FC;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610528
	if (cr6.eq) goto loc_82610528;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610518
	if (cr6.eq) goto loc_82610518;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x8261051c
	goto loc_8261051C;
loc_82610518:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8261051C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,124
	ctx.r5.s64 = r29.s64 + 124;
	// bl 0x823ddb08
	ctx.lr = 0x82610528;
	sub_823DDB08(ctx, base);
loc_82610528:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28944
	ctx.r4.s64 = r11.s64 + -28944;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x8261053C;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610568
	if (cr6.eq) goto loc_82610568;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610558
	if (cr6.eq) goto loc_82610558;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x8261055c
	goto loc_8261055C;
loc_82610558:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8261055C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,128
	ctx.r5.s64 = r29.s64 + 128;
	// bl 0x823ddb08
	ctx.lr = 0x82610568;
	sub_823DDB08(ctx, base);
loc_82610568:
	// lbz r11,4(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826105b4
	if (cr6.eq) goto loc_826105B4;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28192
	ctx.r4.s64 = r11.s64 + -28192;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610588;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826105b4
	if (cr6.eq) goto loc_826105B4;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826105a4
	if (cr6.eq) goto loc_826105A4;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826105a8
	goto loc_826105A8;
loc_826105A4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826105A8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,136
	ctx.r5.s64 = r29.s64 + 136;
	// bl 0x823ddb08
	ctx.lr = 0x826105B4;
	sub_823DDB08(ctx, base);
loc_826105B4:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28216
	ctx.r4.s64 = r11.s64 + -28216;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826105C8;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826105f4
	if (cr6.eq) goto loc_826105F4;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826105e4
	if (cr6.eq) goto loc_826105E4;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826105e8
	goto loc_826105E8;
loc_826105E4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826105E8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,140
	ctx.r5.s64 = r29.s64 + 140;
	// bl 0x823ddb08
	ctx.lr = 0x826105F4;
	sub_823DDB08(ctx, base);
loc_826105F4:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28244
	ctx.r4.s64 = r11.s64 + -28244;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610608;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610634
	if (cr6.eq) goto loc_82610634;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610624
	if (cr6.eq) goto loc_82610624;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610628
	goto loc_82610628;
loc_82610624:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82610628:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r29,144
	ctx.r5.s64 = r29.s64 + 144;
	// bl 0x823ddb08
	ctx.lr = 0x82610634;
	sub_823DDB08(ctx, base);
loc_82610634:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28260
	ctx.r4.s64 = r11.s64 + -28260;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610648;
	sub_821C82A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826106ac
	if (cr6.eq) goto loc_826106AC;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82610668
	if (cr6.eq) goto loc_82610668;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// b 0x8261066c
	goto loc_8261066C;
loc_82610668:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8261066C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,9572
	ctx.r4.s64 = r11.s64 + 9572;
	// bl 0x823ddb08
	ctx.lr = 0x8261067C;
	sub_823DDB08(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8260f840
	ctx.lr = 0x82610688;
	sub_8260F840(ctx, base);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8261069c
	if (cr6.eq) goto loc_8261069C;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// b 0x826106a0
	goto loc_826106A0;
loc_8261069C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826106A0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r29,108
	ctx.r5.s64 = r29.s64 + 108;
	// bl 0x823ddb08
	ctx.lr = 0x826106AC;
	sub_823DDB08(ctx, base);
loc_826106AC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28276
	ctx.r4.s64 = r11.s64 + -28276;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826106C0;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826106ec
	if (cr6.eq) goto loc_826106EC;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826106dc
	if (cr6.eq) goto loc_826106DC;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826106e0
	goto loc_826106E0;
loc_826106DC:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_826106E0:
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826106EC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28288
	ctx.r4.s64 = r11.s64 + -28288;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610700;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261072c
	if (cr6.eq) goto loc_8261072C;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261071c
	if (cr6.eq) goto loc_8261071C;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610720
	goto loc_82610720;
loc_8261071C:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82610720:
	// li r10,160
	ctx.r10.s64 = 160;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261072C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28300
	ctx.r4.s64 = r11.s64 + -28300;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610740;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261076c
	if (cr6.eq) goto loc_8261076C;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261075c
	if (cr6.eq) goto loc_8261075C;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610760
	goto loc_82610760;
loc_8261075C:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82610760:
	// li r10,176
	ctx.r10.s64 = 176;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261076C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28316
	ctx.r4.s64 = r11.s64 + -28316;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610780;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826107ac
	if (cr6.eq) goto loc_826107AC;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261079c
	if (cr6.eq) goto loc_8261079C;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826107a0
	goto loc_826107A0;
loc_8261079C:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_826107A0:
	// li r10,192
	ctx.r10.s64 = 192;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826107AC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28332
	ctx.r4.s64 = r11.s64 + -28332;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826107C0;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826107ec
	if (cr6.eq) goto loc_826107EC;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826107dc
	if (cr6.eq) goto loc_826107DC;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826107e0
	goto loc_826107E0;
loc_826107DC:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_826107E0:
	// li r10,208
	ctx.r10.s64 = 208;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826107EC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28356
	ctx.r4.s64 = r11.s64 + -28356;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610800;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261082c
	if (cr6.eq) goto loc_8261082C;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261081c
	if (cr6.eq) goto loc_8261081C;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610820
	goto loc_82610820;
loc_8261081C:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82610820:
	// li r10,224
	ctx.r10.s64 = 224;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261082C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28376
	ctx.r4.s64 = r11.s64 + -28376;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x82610840;
	sub_821C82A8(ctx, base);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82610854
	if (cr6.eq) goto loc_82610854;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x82610858
	goto loc_82610858;
loc_82610854:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82610858:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r31,r10,-13576
	r31.s64 = ctx.r10.s64 + -13576;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_82610864:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82610888
	if (cr6.eq) goto loc_82610888;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82610864
	if (cr6.eq) goto loc_82610864;
loc_82610888:
	// li r30,1
	r30.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8261089c
	if (!cr6.eq) goto loc_8261089C;
	// stb r30,148(r29)
	PPC_STORE_U8(r29.u32 + 148, r30.u8);
	// b 0x826108a0
	goto loc_826108A0;
loc_8261089C:
	// stb r26,148(r29)
	PPC_STORE_U8(r29.u32 + 148, r26.u8);
loc_826108A0:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28396
	ctx.r4.s64 = r11.s64 + -28396;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c82a8
	ctx.lr = 0x826108B4;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610910
	if (cr6.eq) goto loc_82610910;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826108d0
	if (cr6.eq) goto loc_826108D0;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// b 0x826108d4
	goto loc_826108D4;
loc_826108D0:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_826108D4:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_826108D8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826108fc
	if (cr6.eq) goto loc_826108FC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826108d8
	if (cr6.eq) goto loc_826108D8;
loc_826108FC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8261090c
	if (!cr6.eq) goto loc_8261090C;
	// stb r30,132(r29)
	PPC_STORE_U8(r29.u32 + 132, r30.u8);
	// b 0x82610910
	goto loc_82610910;
loc_8261090C:
	// stb r26,132(r29)
	PPC_STORE_U8(r29.u32 + 132, r26.u8);
loc_82610910:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c5c70
	ctx.lr = 0x82610918;
	sub_821C5C70(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x82610920;
	sub_82130588(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8261092C"))) PPC_WEAK_FUNC(sub_8261092C);
PPC_FUNC_IMPL(__imp__sub_8261092C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82610930"))) PPC_WEAK_FUNC(sub_82610930);
PPC_FUNC_IMPL(__imp__sub_82610930) {
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
	ctx.lr = 0x82610938;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,320
	ctx.r3.s64 = 320;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x8261094C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82610960
	if (cr6.eq) goto loc_82610960;
	// bl 0x8260c710
	ctx.lr = 0x82610958;
	sub_8260C710(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82610964
	goto loc_82610964;
loc_82610960:
	// li r31,0
	r31.s64 = 0;
loc_82610964:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8260ffa8
	ctx.lr = 0x82610974;
	sub_8260FFA8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82610994
	if (cr6.eq) goto loc_82610994;
	// addi r3,r29,208
	ctx.r3.s64 = r29.s64 + 208;
	// li r5,320
	ctx.r5.s64 = 320;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x82610994;
	sub_823DA950(ctx, base);
loc_82610994:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8261099C;
	sub_82130588(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826109A8"))) PPC_WEAK_FUNC(sub_826109A8);
PPC_FUNC_IMPL(__imp__sub_826109A8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91f0
	ctx.lr = 0x826109B0;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r27,1
	r27.s64 = 1;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r30.u32);
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lfs f0,460(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 460);
	f0.f64 = double(temp.f32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x826109f0
	if (cr6.gt) goto loc_826109F0;
	// li r11,0
	r11.s64 = 0;
loc_826109F0:
	// lbz r10,1621(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1621);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r27,1623(r31)
	PPC_STORE_U8(r31.u32 + 1623, r27.u8);
	// stb r11,1622(r31)
	PPC_STORE_U8(r31.u32 + 1622, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82611000
	if (cr6.eq) goto loc_82611000;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r26,r10,27,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// ble cr6,0x82610b8c
	if (!cr6.gt) goto loc_82610B8C;
	// li r11,20
	r11.s64 = 20;
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610A2C;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r3,20
	ctx.r3.s64 = 20;
	// std r10,228(r1)
	PPC_STORE_U64(ctx.r1.u32 + 228, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x82610A44;
	sub_8217F768(ctx, base);
	// li r9,27
	ctx.r9.s64 = 27;
	// li r3,27
	ctx.r3.s64 = 27;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610A54;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r3,27
	ctx.r3.s64 = 27;
	// std r8,236(r1)
	PPC_STORE_U64(ctx.r1.u32 + 236, ctx.r8.u64);
	// bl 0x8217f768
	ctx.lr = 0x82610A6C;
	sub_8217F768(ctx, base);
	// li r7,26
	ctx.r7.s64 = 26;
	// li r3,26
	ctx.r3.s64 = 26;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610A7C;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,255
	ctx.r4.s64 = 255;
	// ld r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r3,26
	ctx.r3.s64 = 26;
	// std r6,244(r1)
	PPC_STORE_U64(ctx.r1.u32 + 244, ctx.r6.u64);
	// bl 0x8217f768
	ctx.lr = 0x82610A94;
	sub_8217F768(ctx, base);
	// li r5,25
	ctx.r5.s64 = 25;
	// li r3,25
	ctx.r3.s64 = 25;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610AA4;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ld r11,112(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r3,25
	ctx.r3.s64 = 25;
	// std r11,252(r1)
	PPC_STORE_U64(ctx.r1.u32 + 252, r11.u64);
	// bl 0x8217f768
	ctx.lr = 0x82610ABC;
	sub_8217F768(ctx, base);
	// li r10,24
	ctx.r10.s64 = 24;
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610ACC;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,7
	ctx.r4.s64 = 7;
	// ld r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r3,24
	ctx.r3.s64 = 24;
	// std r9,260(r1)
	PPC_STORE_U64(ctx.r1.u32 + 260, ctx.r9.u64);
	// bl 0x8217f768
	ctx.lr = 0x82610AE4;
	sub_8217F768(ctx, base);
	// li r8,23
	ctx.r8.s64 = 23;
	// li r3,23
	ctx.r3.s64 = 23;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610AF4;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r3,23
	ctx.r3.s64 = 23;
	// std r7,268(r1)
	PPC_STORE_U64(ctx.r1.u32 + 268, ctx.r7.u64);
	// bl 0x8217f768
	ctx.lr = 0x82610B0C;
	sub_8217F768(ctx, base);
	// li r6,21
	ctx.r6.s64 = 21;
	// li r3,21
	ctx.r3.s64 = 21;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610B1C;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r5,112(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r3,21
	ctx.r3.s64 = 21;
	// std r5,276(r1)
	PPC_STORE_U64(ctx.r1.u32 + 276, ctx.r5.u64);
	// bl 0x8217f768
	ctx.lr = 0x82610B34;
	sub_8217F768(ctx, base);
	// li r4,22
	ctx.r4.s64 = 22;
	// li r3,22
	ctx.r3.s64 = 22;
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610B44;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r11,112(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r3,22
	ctx.r3.s64 = 22;
	// std r11,284(r1)
	PPC_STORE_U64(ctx.r1.u32 + 284, r11.u64);
	// bl 0x8217f768
	ctx.lr = 0x82610B5C;
	sub_8217F768(ctx, base);
	// li r10,11
	ctx.r10.s64 = 11;
	// li r3,11
	ctx.r3.s64 = 11;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610B6C;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r30,9
	r30.s64 = 9;
	// ld r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r9,292(r1)
	PPC_STORE_U64(ctx.r1.u32 + 292, ctx.r9.u64);
	// li r3,11
	ctx.r3.s64 = 11;
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r30.u32);
	// bl 0x8217f768
	ctx.lr = 0x82610B8C;
	sub_8217F768(ctx, base);
loc_82610B8C:
	// li r11,28
	r11.s64 = 28;
	// li r3,28
	ctx.r3.s64 = 28;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82610B9C;
	sub_8217FED0(ctx, base);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// rlwinm r9,r30,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r1,228
	ctx.r8.s64 = ctx.r1.s64 + 228;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,28
	ctx.r3.s64 = 28;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// stdx r10,r9,r8
	PPC_STORE_U64(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u64);
	// lwz r7,224(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// stw r6,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r6.u32);
	// bl 0x8217f768
	ctx.lr = 0x82610BC8;
	sub_8217F768(ctx, base);
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r5,-31280
	ctx.r4.s64 = ctx.r5.s64 + -31280;
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82610BDC;
	sub_8217C088(ctx, base);
	// lwz r11,-26876(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r1,400
	ctx.r7.s64 = ctx.r1.s64 + 400;
	// addi r6,r1,416
	ctx.r6.s64 = ctx.r1.s64 + 416;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821cec00
	ctx.lr = 0x82610C28;
	sub_821CEC00(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,9
	ctx.r9.s64 = 9;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610C4C;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1572(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1572);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,368
	ctx.r6.s64 = r31.s64 + 368;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610C70;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1576(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1576);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,384
	ctx.r6.s64 = r31.s64 + 384;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610C94;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r30,r31,400
	r30.s64 = r31.s64 + 400;
	// lwz r5,1580(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1580);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82610CBC;
	sub_8218A6E0(ctx, base);
	// lwz r5,1588(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1588);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v59,r0,r30
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f10,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f0,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f31,7444(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fdivs f8,f31,f12
	ctx.f8.f64 = double(float(f31.f64 / ctx.f12.f64));
	// stfs f8,184(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// fneg f7,f11
	ctx.f7.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f7,188(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// fdivs f6,f0,f9
	ctx.f6.f64 = double(float(f0.f64 / ctx.f9.f64));
	// fdivs f5,f31,f9
	ctx.f5.f64 = double(float(f31.f64 / ctx.f9.f64));
	// stfs f5,176(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fneg f4,f6
	ctx.f4.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// stfs f4,180(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610D34;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1592(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1592);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,416
	ctx.r6.s64 = r31.s64 + 416;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82610D58;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,1584(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1584);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,448
	ctx.r6.s64 = r31.s64 + 448;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610D7C;
	sub_8218A6E0(ctx, base);
	// addi r11,r31,1632
	r11.s64 = r31.s64 + 1632;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lwz r5,1596(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1596);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// vxor128 v57,v58,v58
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_setzero_si128());
	// vsubfp128 v56,v57,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610DB8;
	sub_8218A6E0(ctx, base);
	// lfs f3,1648(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1648);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,1652(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1652);
	ctx.f2.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lfs f1,1656(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1656);
	ctx.f1.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// stfs f31,172(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f3,160(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f2,164(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f1,168(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,1600(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610DF8;
	sub_8218A6E0(ctx, base);
	// lwz r5,1604(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1604);
	// lfs f0,1668(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1668);
	f0.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f13,1672(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1672);
	ctx.f13.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f31,204(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f12,1664(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1664);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stfs f13,200(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stfs f12,192(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610E38;
	sub_8218A6E0(ctx, base);
	// lfs f10,1688(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1688);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,1680(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1680);
	ctx.f9.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lfs f11,1684(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1684);
	ctx.f11.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f9,128(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f31,140(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,1608(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1608);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610E78;
	sub_8218A6E0(ctx, base);
	// lfs f8,456(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f7,f31,f8
	ctx.f7.f64 = double(float(f31.f64 / ctx.f8.f64));
	// lfs f6,452(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 452);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,460(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 460);
	ctx.f5.f64 = double(temp.f32);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stfs f30,144(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// stfs f5,156(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f7,152(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lwz r5,1612(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1612);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// fmuls f4,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// stfs f4,148(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82610EC0;
	sub_8218A6E0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r5,168(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610ED8;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,172(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610EF0;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610F08;
	sub_82189CE0(ctx, base);
	// lwz r11,-26876(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// lfs f3,400(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 400);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,116(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// addi r11,r26,843
	r11.s64 = r26.s64 + 843;
	// fcmpu cr6,f2,f3
	cr6.compare(ctx.f2.f64, ctx.f3.f64);
	// bgt cr6,0x82610f24
	if (cr6.gt) goto loc_82610F24;
	// addi r11,r26,845
	r11.s64 = r26.s64 + 845;
loc_82610F24:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,168(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f4,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f4.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// lfs f5,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// bl 0x8260d678
	ctx.lr = 0x82610F68;
	sub_8260D678(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,-25360(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -25360);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610F84;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,140(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610F9C;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610FB4;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610FCC;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,168(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610FE4;
	sub_82189CE0(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r6,-25360(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,172(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82610FFC;
	sub_82189CE0(ctx, base);
	// stb r27,1620(r31)
	PPC_STORE_U8(r31.u32 + 1620, r27.u8);
loc_82611000:
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82491668
	ctx.lr = 0x82611008;
	sub_82491668(ctx, base);
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82611018"))) PPC_WEAK_FUNC(sub_82611018);
PPC_FUNC_IMPL(__imp__sub_82611018) {
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
	ctx.lr = 0x82611020;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-27324
	ctx.r4.s64 = r11.s64 + -27324;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82611048;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826110cc
	if (cr6.eq) goto loc_826110CC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82611070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82611088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,103
	cr6.compare<int32_t>(ctx.r5.s32, 103, xer);
	// bne cr6,0x826110bc
	if (!cr6.eq) goto loc_826110BC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826110B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
loc_826110BC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r11,-27368
	ctx.r3.s64 = r11.s64 + -27368;
	// bl 0x82130000
	ctx.lr = 0x826110CC;
	sub_82130000(ctx, base);
loc_826110CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826110D8"))) PPC_WEAK_FUNC(sub_826110D8);
PPC_FUNC_IMPL(__imp__sub_826110D8) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,4(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// bl 0x821cfe80
	ctx.lr = 0x82611104;
	sub_821CFE80(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82611124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82611140
	if (cr6.eq) goto loc_82611140;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-29628
	ctx.r4.s64 = r11.s64 + -29628;
	// bl 0x821d0898
	ctx.lr = 0x82611140;
	sub_821D0898(ctx, base);
loc_82611140:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

__attribute__((alias("__imp__sub_82611158"))) PPC_WEAK_FUNC(sub_82611158);
PPC_FUNC_IMPL(__imp__sub_82611158) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82612c70
	sub_82612C70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82611160"))) PPC_WEAK_FUNC(sub_82611160);
PPC_FUNC_IMPL(__imp__sub_82611160) {
	PPC_FUNC_PROLOGUE();
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82612d38
	sub_82612D38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8261116C"))) PPC_WEAK_FUNC(sub_8261116C);
PPC_FUNC_IMPL(__imp__sub_8261116C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82611170"))) PPC_WEAK_FUNC(sub_82611170);
PPC_FUNC_IMPL(__imp__sub_82611170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,76(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82611180"))) PPC_WEAK_FUNC(sub_82611180);
PPC_FUNC_IMPL(__imp__sub_82611180) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-27436
	ctx.r10.s64 = r11.s64 + -27436;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2810
	ctx.lr = 0x826111AC;
	sub_821D2810(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826111c4
	if (cr6.eq) goto loc_826111C4;
	// bl 0x82130588
	ctx.lr = 0x826111C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826111C4:
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

__attribute__((alias("__imp__sub_826111DC"))) PPC_WEAK_FUNC(sub_826111DC);
PPC_FUNC_IMPL(__imp__sub_826111DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826111E0"))) PPC_WEAK_FUNC(sub_826111E0);
PPC_FUNC_IMPL(__imp__sub_826111E0) {
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
	ctx.lr = 0x826111E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,8(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82611230
	if (cr6.eq) goto loc_82611230;
	// li r31,0
	r31.s64 = 0;
loc_82611204:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8261121C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x82611204
	if (cr6.lt) goto loc_82611204;
loc_82611230:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82611238"))) PPC_WEAK_FUNC(sub_82611238);
PPC_FUNC_IMPL(__imp__sub_82611238) {
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
	ctx.lr = 0x82611240;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,8(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82611290
	if (cr6.eq) goto loc_82611290;
	// li r30,0
	r30.s64 = 0;
loc_82611260:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8261127C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// blt cr6,0x82611260
	if (cr6.lt) goto loc_82611260;
loc_82611290:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82611298"))) PPC_WEAK_FUNC(sub_82611298);
PPC_FUNC_IMPL(__imp__sub_82611298) {
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
	// bl 0x821d2970
	ctx.lr = 0x826112B0;
	sub_821D2970(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-27308
	ctx.r9.s64 = ctx.r10.s64 + -27308;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// bl 0x82613700
	ctx.lr = 0x826112D0;
	sub_82613700(ctx, base);
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

__attribute__((alias("__imp__sub_826112E8"))) PPC_WEAK_FUNC(sub_826112E8);
PPC_FUNC_IMPL(__imp__sub_826112E8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,-27308
	ctx.r10.s64 = r11.s64 + -27308;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82611324
	if (cr6.eq) goto loc_82611324;
	// bl 0x821b4cb0
	ctx.lr = 0x8261131C;
	sub_821B4CB0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_82611324:
	// addi r4,r31,120
	ctx.r4.s64 = r31.s64 + 120;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d31f8
	ctx.lr = 0x82611330;
	sub_821D31F8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d3170
	ctx.lr = 0x82611338;
	sub_821D3170(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82611358
	if (cr6.eq) goto loc_82611358;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82611358;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82611358:
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82613458
	ctx.lr = 0x82611364;
	sub_82613458(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d3188
	ctx.lr = 0x8261136C;
	sub_821D3188(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2f58
	ctx.lr = 0x82611374;
	sub_821D2F58(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826134b0
	ctx.lr = 0x8261137C;
	sub_826134B0(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-27436
	ctx.r10.s64 = r11.s64 + -27436;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2810
	ctx.lr = 0x82611390;
	sub_821D2810(ctx, base);
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

__attribute__((alias("__imp__sub_826113A8"))) PPC_WEAK_FUNC(sub_826113A8);
PPC_FUNC_IMPL(__imp__sub_826113A8) {
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
	ctx.lr = 0x826113B0;
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r5,r11,-13284
	ctx.r5.s64 = r11.s64 + -13284;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x826113E0;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8261143c
	if (cr6.eq) goto loc_8261143C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x826113F4;
	sub_821D1CD0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x82611404;
	sub_821CF7B8(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82611424;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x82611430;
	sub_821BE610(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x823d9244
	return;
loc_8261143C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82611448"))) PPC_WEAK_FUNC(sub_82611448);
PPC_FUNC_IMPL(__imp__sub_82611448) {
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
	ctx.lr = 0x82611450;
	// lis r12,-1
	r12.s64 = -65536;
	// ori r12,r12,11648
	r12.u64 = r12.u64 | 11648;
	// bl 0x823dbff4
	ctx.lr = 0x8261145C;
	sub_823DBFF4(ctx, base);
	// stwux r1,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x82614ac0
	ctx.lr = 0x82611478;
	sub_82614AC0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82611484
	if (!cr6.eq) goto loc_82611484;
	// addi r31,r1,128
	r31.s64 = ctx.r1.s64 + 128;
loc_82611484:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82611600
	if (cr6.eq) goto loc_82611600;
	// lis r11,-32182
	r11.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,-13328
	ctx.r4.s64 = r11.s64 + -13328;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x826114AC;
	sub_821C2FB0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r8,-20884
	ctx.r4.s64 = ctx.r8.s64 + -20884;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// ld r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// rldicr r8,r7,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x826114D8;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r4,-13312
	ctx.r4.s64 = ctx.r4.s64 + -13312;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x826114F4;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r4,r9,1788
	ctx.r4.s64 = ctx.r9.s64 + 1788;
	// addi r5,r10,-15576
	ctx.r5.s64 = ctx.r10.s64 + -15576;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x82611524;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r4,-13344
	ctx.r4.s64 = ctx.r4.s64 + -13344;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x82611540;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r29,r10,2068
	r29.s64 = ctx.r10.s64 + 2068;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x82611570;
	sub_82614440(ctx, base);
	// lis r4,-32159
	ctx.r4.s64 = -2107572224;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r4,4464
	ctx.r4.s64 = ctx.r4.s64 + 4464;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x8261158C;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-27220
	ctx.r5.s64 = ctx.r10.s64 + -27220;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x826115B8;
	sub_82614440(ctx, base);
	// lis r4,-32182
	ctx.r4.s64 = -2109079552;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r4,-13296
	ctx.r4.s64 = ctx.r4.s64 + -13296;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x826115D4;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r10,1780
	ctx.r4.s64 = ctx.r10.s64 + 1780;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r8,r8,32,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82614440
	ctx.lr = 0x82611600;
	sub_82614440(ctx, base);
loc_82611600:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r3,r11,21744
	ctx.r3.s64 = r11.s64 + 21744;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82611624
	if (cr6.eq) goto loc_82611624;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821c0750
	ctx.lr = 0x82611624;
	sub_821C0750(ctx, base);
loc_82611624:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r10,r11,21724
	ctx.r10.s64 = r11.s64 + 21724;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82611698
	if (!cr6.eq) goto loc_82611698;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82611698
	if (cr6.eq) goto loc_82611698;
	// addi r4,r30,120
	ctx.r4.s64 = r30.s64 + 120;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d31f8
	ctx.lr = 0x82611650;
	sub_821D31F8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rlwinm r4,r11,10,0,21
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// bl 0x821d3070
	ctx.lr = 0x82611660;
	sub_821D3070(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82614588
	ctx.lr = 0x82611670;
	sub_82614588(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d30e8
	ctx.lr = 0x8261167C;
	sub_821D30E8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d2f58
	ctx.lr = 0x82611684;
	sub_821D2F58(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82614a50
	ctx.lr = 0x8261168C;
	sub_82614A50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// b 0x823d9248
	return;
loc_82611698:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82614588
	ctx.lr = 0x826116A8;
	sub_82614588(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82614a50
	ctx.lr = 0x826116B4;
	sub_82614A50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826116C0"))) PPC_WEAK_FUNC(sub_826116C0);
PPC_FUNC_IMPL(__imp__sub_826116C0) {
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
	// lwz r30,4(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// bl 0x821cfe80
	ctx.lr = 0x826116F0;
	sub_821CFE80(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-24728(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24728);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8261170C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r7,-29628
	ctx.r4.s64 = ctx.r7.s64 + -29628;
	// bl 0x821d0898
	ctx.lr = 0x82611720;
	sub_821D0898(ctx, base);
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

__attribute__((alias("__imp__sub_82611738"))) PPC_WEAK_FUNC(sub_82611738);
PPC_FUNC_IMPL(__imp__sub_82611738) {
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
	ctx.lr = 0x82611740;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,4(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// bl 0x821d0898
	ctx.lr = 0x8261175C;
	sub_821D0898(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,20400(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20400);
	// bl 0x82613970
	ctx.lr = 0x82611778;
	sub_82613970(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82612c28
	ctx.lr = 0x82611784;
	sub_82612C28(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r9,-29628
	ctx.r4.s64 = ctx.r9.s64 + -29628;
	// bl 0x821d0898
	ctx.lr = 0x82611794;
	sub_821D0898(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8261179C"))) PPC_WEAK_FUNC(sub_8261179C);
PPC_FUNC_IMPL(__imp__sub_8261179C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826117A0"))) PPC_WEAK_FUNC(sub_826117A0);
PPC_FUNC_IMPL(__imp__sub_826117A0) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826117DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-25064
	ctx.r4.s64 = ctx.r8.s64 + -25064;
	// bl 0x823db730
	ctx.lr = 0x826117EC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82611838
	if (cr6.eq) goto loc_82611838;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,2068
	ctx.r5.s64 = r11.s64 + 2068;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca6a8
	ctx.lr = 0x82611814;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82611838
	if (cr6.eq) goto loc_82611838;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821b9888
	ctx.lr = 0x8261182C;
	sub_821B9888(ctx, base);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x82611838;
	sub_821BE610(ctx, base);
loc_82611838:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

__attribute__((alias("__imp__sub_82611850"))) PPC_WEAK_FUNC(sub_82611850);
PPC_FUNC_IMPL(__imp__sub_82611850) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82611884;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-25064
	ctx.r4.s64 = ctx.r9.s64 + -25064;
	// bl 0x823db730
	ctx.lr = 0x82611894;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826118e0
	if (cr6.eq) goto loc_826118E0;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-27208
	ctx.r5.s64 = r11.s64 + -27208;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca6a8
	ctx.lr = 0x826118BC;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826118e0
	if (cr6.eq) goto loc_826118E0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821b89c8
	ctx.lr = 0x826118D8;
	sub_821B89C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x826118E0;
	sub_821BE610(ctx, base);
loc_826118E0:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

__attribute__((alias("__imp__sub_826118F8"))) PPC_WEAK_FUNC(sub_826118F8);
PPC_FUNC_IMPL(__imp__sub_826118F8) {
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
	ctx.lr = 0x82611900;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// addi r7,r11,2384
	ctx.r7.s64 = r11.s64 + 2384;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lfs f30,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f30.f64 = double(temp.f32);
	// li r8,16
	ctx.r8.s64 = 16;
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r4,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v62,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// addi r11,r6,2352
	r11.s64 = ctx.r6.s64 + 2352;
	// lvx128 v58,r4,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v58,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vand128 v55,v61,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v54,v62,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v53,v58,v59
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vor128 v51,v63,v55
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// vmrghw128 v50,v57,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v49,v54,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f31,3796(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmsum4fp128 v48,v51,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v47,v51,v49
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmsum4fp128 v46,v51,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmrghw128 v45,v48,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v44,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217c328
	ctx.lr = 0x826119C4;
	sub_8217C328(ctx, base);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82611a0c
	if (cr6.eq) goto loc_82611A0C;
	// lfs f0,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
loc_826119E0:
	// lfs f12,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bgt cr6,0x826119f8
	if (cr6.gt) goto loc_826119F8;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82611a10
	if (!cr6.eq) goto loc_82611A10;
loc_826119F8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// blt cr6,0x826119e0
	if (cr6.lt) goto loc_826119E0;
	// b 0x82611a10
	goto loc_82611A10;
loc_82611A0C:
	// li r10,3
	ctx.r10.s64 = 3;
loc_82611A10:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stb r10,0(r28)
	PPC_STORE_U8(r28.u32 + 0, ctx.r10.u8);
	// beq cr6,0x82611a2c
	if (cr6.eq) goto loc_82611A2C;
	// fsubs f0,f13,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 - f30.f64));
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fsel f12,f13,f31,f0
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : f0.f64;
	// stfs f12,0(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_82611A2C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82611A3C"))) PPC_WEAK_FUNC(sub_82611A3C);
PPC_FUNC_IMPL(__imp__sub_82611A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82611A40"))) PPC_WEAK_FUNC(sub_82611A40);
PPC_FUNC_IMPL(__imp__sub_82611A40) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82611A48;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lfs f30,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f30.f64 = double(temp.f32);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x821ce9d8
	ctx.lr = 0x82611AA0;
	sub_821CE9D8(ctx, base);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lfs f3,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// lfs f1,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217c328
	ctx.lr = 0x82611ABC;
	sub_8217C328(ctx, base);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82611b04
	if (cr6.eq) goto loc_82611B04;
	// lfs f0,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
loc_82611AD8:
	// lfs f12,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bgt cr6,0x82611af0
	if (cr6.gt) goto loc_82611AF0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82611b08
	if (!cr6.eq) goto loc_82611B08;
loc_82611AF0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// blt cr6,0x82611ad8
	if (cr6.lt) goto loc_82611AD8;
	// b 0x82611b08
	goto loc_82611B08;
loc_82611B04:
	// li r10,3
	ctx.r10.s64 = 3;
loc_82611B08:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stb r10,0(r28)
	PPC_STORE_U8(r28.u32 + 0, ctx.r10.u8);
	// beq cr6,0x82611b24
	if (cr6.eq) goto loc_82611B24;
	// fsubs f0,f13,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 - f30.f64));
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fsel f12,f13,f31,f0
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : f0.f64;
	// stfs f12,0(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_82611B24:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82611B34"))) PPC_WEAK_FUNC(sub_82611B34);
PPC_FUNC_IMPL(__imp__sub_82611B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82611B38"))) PPC_WEAK_FUNC(sub_82611B38);
PPC_FUNC_IMPL(__imp__sub_82611B38) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82611B40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// bl 0x821789d8
	ctx.lr = 0x82611B50;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82611c40
	if (cr6.eq) goto loc_82611C40;
	// lhz r11,16(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 16);
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82611c40
	if (cr6.eq) goto loc_82611C40;
	// li r26,0
	r26.s64 = 0;
loc_82611B70:
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// li r28,0
	r28.s64 = 0;
	// lwzx r30,r26,r11
	r30.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// lhz r10,140(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 140);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82611c2c
	if (cr6.eq) goto loc_82611C2C;
	// li r29,0
	r29.s64 = 0;
loc_82611B8C:
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lwz r10,136(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// lwz r8,132(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r29
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// lwzx r5,r7,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + r27.u32);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwzx r3,r3,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	// bl 0x82595ce8
	ctx.lr = 0x82611BBC;
	sub_82595CE8(ctx, base);
	// lhz r11,108(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 108);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82611bf0
	if (cr6.eq) goto loc_82611BF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82611BEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82611c18
	goto loc_82611C18;
loc_82611BF0:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82611c18
	if (cr6.eq) goto loc_82611C18;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82611C18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82611C18:
	// lhz r11,140(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 140);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82611b8c
	if (cr6.lt) goto loc_82611B8C;
loc_82611C2C:
	// lhz r11,16(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 16);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82611b70
	if (cr6.lt) goto loc_82611B70;
loc_82611C40:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82611C48"))) PPC_WEAK_FUNC(sub_82611C48);
PPC_FUNC_IMPL(__imp__sub_82611C48) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82611C50;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82613f08
	ctx.lr = 0x82611C64;
	sub_82613F08(ctx, base);
	// lhz r11,16(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82611d5c
	if (cr6.eq) goto loc_82611D5C;
	// li r23,0
	r23.s64 = 0;
loc_82611C7C:
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// li r26,0
	r26.s64 = 0;
	// lwzx r29,r11,r23
	r29.u64 = PPC_LOAD_U32(r11.u32 + r23.u32);
	// lhz r10,140(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82611d48
	if (cr6.eq) goto loc_82611D48;
	// li r28,0
	r28.s64 = 0;
loc_82611C98:
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// lwz r10,136(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// lwz r8,132(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r28,r10
	r31.u64 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	// lwzx r5,r7,r24
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + r24.u32);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwzx r3,r3,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	// bl 0x82595ce8
	ctx.lr = 0x82611CC8;
	sub_82595CE8(ctx, base);
	// lhz r11,108(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 108);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82611d1c
	if (cr6.eq) goto loc_82611D1C;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82611d34
	if (cr6.eq) goto loc_82611D34;
loc_82611CF0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82611D0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// blt cr6,0x82611cf0
	if (cr6.lt) goto loc_82611CF0;
	// b 0x82611d34
	goto loc_82611D34;
loc_82611D1C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82611D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82611D34:
	// lhz r11,140(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x82611c98
	if (cr6.lt) goto loc_82611C98;
loc_82611D48:
	// lhz r11,16(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 16);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// cmpw cr6,r22,r11
	cr6.compare<int32_t>(r22.s32, r11.s32, xer);
	// blt cr6,0x82611c7c
	if (cr6.lt) goto loc_82611C7C;
loc_82611D5C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82611D64"))) PPC_WEAK_FUNC(sub_82611D64);
PPC_FUNC_IMPL(__imp__sub_82611D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82611D68"))) PPC_WEAK_FUNC(sub_82611D68);
PPC_FUNC_IMPL(__imp__sub_82611D68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82613b20
	sub_82613B20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82611D8C"))) PPC_WEAK_FUNC(sub_82611D8C);
PPC_FUNC_IMPL(__imp__sub_82611D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82611D90"))) PPC_WEAK_FUNC(sub_82611D90);
PPC_FUNC_IMPL(__imp__sub_82611D90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82613148
	sub_82613148(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82611DB0"))) PPC_WEAK_FUNC(sub_82611DB0);
PPC_FUNC_IMPL(__imp__sub_82611DB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82613200
	sub_82613200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82611DD4"))) PPC_WEAK_FUNC(sub_82611DD4);
PPC_FUNC_IMPL(__imp__sub_82611DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82611DD8"))) PPC_WEAK_FUNC(sub_82611DD8);
PPC_FUNC_IMPL(__imp__sub_82611DD8) {
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
	ctx.lr = 0x82611DE0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82611E00;
	sub_8217C088(ctx, base);
	// addi r10,r31,16
	ctx.r10.s64 = r31.s64 + 16;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r24,r9,r26
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + r26.u32);
	// lhz r8,4(r24)
	ctx.r8.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// addic. r28,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	r28.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// blt 0x82611eb0
	if (cr0.lt) goto loc_82611EB0;
	// rlwinm r25,r28,2,0,29
	r25.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r22,1
	r22.s64 = 1;
loc_82611E20:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82611e48
	if (cr6.eq) goto loc_82611E48;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// rlwinm r10,r28,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r28,27
	ctx.r9.u64 = r28.u32 & 0x1F;
	// slw r8,r22,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r22.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82611ea4
	if (cr6.eq) goto loc_82611EA4;
loc_82611E48:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwzx r29,r11,r25
	r29.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// lhz r10,26(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 26);
	// addic. r31,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r31.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// blt 0x82611ea4
	if (cr0.lt) goto loc_82611EA4;
	// rlwinm r30,r31,1,0,30
	r30.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
loc_82611E60:
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// beq cr6,0x82611e8c
	if (cr6.eq) goto loc_82611E8C;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r10,8(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lhzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + r30.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lbz r5,9(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 9);
	// cmpw cr6,r5,r27
	cr6.compare<int32_t>(ctx.r5.s32, r27.s32, xer);
	// bne cr6,0x82611e98
	if (!cr6.eq) goto loc_82611E98;
loc_82611E8C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82190b98
	ctx.lr = 0x82611E98;
	sub_82190B98(ctx, base);
loc_82611E98:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,-2
	r30.s64 = r30.s64 + -2;
	// bge 0x82611e60
	if (!cr0.lt) goto loc_82611E60;
loc_82611EA4:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r25,r25,-4
	r25.s64 = r25.s64 + -4;
	// bge 0x82611e20
	if (!cr0.lt) goto loc_82611E20;
loc_82611EB0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82611EB8"))) PPC_WEAK_FUNC(sub_82611EB8);
PPC_FUNC_IMPL(__imp__sub_82611EB8) {
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
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91c4
	ctx.lr = 0x82611EC0;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r15,r7
	r15.u64 = ctx.r7.u64;
	// mr r21,r8
	r21.u64 = ctx.r8.u64;
	// li r16,32
	r16.s64 = 32;
	// li r17,48
	r17.s64 = 48;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// li r18,16
	r18.s64 = 16;
	// beq cr6,0x82611f24
	if (cr6.eq) goto loc_82611F24;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r30,r16
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r30,r17
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r30,r18
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82611f5c
	goto loc_82611F5C;
loc_82611F24:
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v57,r24,r18
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
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
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v56,v58,234
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x15));
	// vpermwi128 v55,v58,186
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x45));
	// vpermwi128 v54,v58,174
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x51));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82611F5C:
	// lis r25,-32124
	r25.s64 = -2105278464;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-26876(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82611F6C;
	sub_8217C088(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r28,-2
	r28.s64 = -2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r19,r10,r23
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + r23.u32);
	// lhz r9,4(r19)
	ctx.r9.u64 = PPC_LOAD_U16(r19.u32 + 4);
	// addic. r20,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r20.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// blt 0x82612128
	if (cr0.lt) goto loc_82612128;
	// rlwinm r22,r20,2,0,29
	r22.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
loc_82611F8C:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwzx r31,r22,r11
	r31.u64 = PPC_LOAD_U32(r22.u32 + r11.u32);
	// lhz r10,26(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// lbz r27,23(r31)
	r27.u64 = PPC_LOAD_U8(r31.u32 + 23);
	// addic. r29,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r29.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8261211c
	if (cr0.lt) goto loc_8261211C;
	// rlwinm r26,r29,1,0,30
	r26.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
loc_82611FA8:
	// cmpwi cr6,r21,-1
	cr6.compare<int32_t>(r21.s32, -1, xer);
	// beq cr6,0x82611fd4
	if (cr6.eq) goto loc_82611FD4;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,8(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// lhzx r9,r11,r26
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + r26.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lbz r5,9(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 9);
	// cmpw cr6,r5,r21
	cr6.compare<int32_t>(ctx.r5.s32, r21.s32, xer);
	// bne cr6,0x82612110
	if (!cr6.eq) goto loc_82612110;
loc_82611FD4:
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82612018
	if (cr6.eq) goto loc_82612018;
	// clrlwi r11,r15,31
	r11.u64 = r15.u32 & 0x1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82612110
	if (cr6.eq) goto loc_82612110;
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x82612004
	if (cr6.eq) goto loc_82612004;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-26876(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82612000;
	sub_8217C088(ctx, base);
	// li r28,-1
	r28.s64 = -1;
loc_82612004:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82190bb8
	ctx.lr = 0x82612014;
	sub_82190BB8(ctx, base);
	// b 0x82612110
	goto loc_82612110;
loc_82612018:
	// rlwinm r11,r15,0,30,30
	r11.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82612110
	if (cr6.eq) goto loc_82612110;
	// cmpw cr6,r27,r28
	cr6.compare<int32_t>(r27.s32, r28.s32, xer);
	// beq cr6,0x82612104
	if (cr6.eq) goto loc_82612104;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r28,r27
	r28.u64 = r27.u64;
	// bl 0x821a1768
	ctx.lr = 0x82612040;
	sub_821A1768(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826120f8
	if (cr6.eq) goto loc_826120F8;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v12,r30,r17
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v13,r30,r16
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v53,v63,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v52,v62,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v51,v61,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v11,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// vmulfp128 v10,v0,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v53.f32)));
	// vspltw128 v9,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmulfp128 v8,v0,v52
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vspltw128 v7,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v6,v0,v51
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// vspltw128 v5,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vmaddfp v4,v0,v11,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v3,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// lvx128 v0,r30,r18
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v2,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v1,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// vspltw128 v31,v61,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vmaddfp v29,v0,v9,v10
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v28,v0,v7,v8
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v27,v0,v5,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v26,v0,v3,v4
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v25,v13,v2,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v13,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v13,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v13,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v25,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826120F8:
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,-26876(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82612104;
	sub_8217C088(ctx, base);
loc_82612104:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82190b98
	ctx.lr = 0x82612110;
	sub_82190B98(ctx, base);
loc_82612110:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r26,r26,-2
	r26.s64 = r26.s64 + -2;
	// bge 0x82611fa8
	if (!cr0.lt) goto loc_82611FA8;
loc_8261211C:
	// addic. r20,r20,-1
	xer.ca = r20.u32 > 0;
	r20.s64 = r20.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// addi r22,r22,-4
	r22.s64 = r22.s64 + -4;
	// bge 0x82611f8c
	if (!cr0.lt) goto loc_82611F8C;
loc_82612128:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_82612130"))) PPC_WEAK_FUNC(sub_82612130);
PPC_FUNC_IMPL(__imp__sub_82612130) {
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
	// bl 0x826112e8
	ctx.lr = 0x82612150;
	sub_826112E8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82612168
	if (cr6.eq) goto loc_82612168;
	// bl 0x82130588
	ctx.lr = 0x82612164;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82612168:
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

__attribute__((alias("__imp__sub_82612180"))) PPC_WEAK_FUNC(sub_82612180);
PPC_FUNC_IMPL(__imp__sub_82612180) {
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
	ctx.lr = 0x82612188;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x82612198;
	sub_821D2970(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// addi r10,r11,-27436
	ctx.r10.s64 = r11.s64 + -27436;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82323c38
	ctx.lr = 0x826121B0;
	sub_82323C38(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// addi r8,r9,-27308
	ctx.r8.s64 = ctx.r9.s64 + -27308;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x82323cb8
	ctx.lr = 0x826121C4;
	sub_82323CB8(ctx, base);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82613ad0
	ctx.lr = 0x826121D4;
	sub_82613AD0(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82612210
	if (cr6.eq) goto loc_82612210;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82612c28
	ctx.lr = 0x826121E8;
	sub_82612C28(ctx, base);
	// addi r30,r31,64
	r30.s64 = r31.s64 + 64;
	// li r29,4
	r29.s64 = 4;
loc_826121F0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82612204
	if (cr6.eq) goto loc_82612204;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82612a30
	ctx.lr = 0x82612204;
	sub_82612A30(ctx, base);
loc_82612204:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x826121f0
	if (!cr0.eq) goto loc_826121F0;
loc_82612210:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8261221C"))) PPC_WEAK_FUNC(sub_8261221C);
PPC_FUNC_IMPL(__imp__sub_8261221C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82612220"))) PPC_WEAK_FUNC(sub_82612220);
PPC_FUNC_IMPL(__imp__sub_82612220) {
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
	ctx.lr = 0x82612228;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821d2970
	ctx.lr = 0x8261223C;
	sub_821D2970(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// addi r10,r11,-27308
	ctx.r10.s64 = r11.s64 + -27308;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82323cb8
	ctx.lr = 0x82612254;
	sub_82323CB8(ctx, base);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82613ad0
	ctx.lr = 0x82612264;
	sub_82613AD0(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x826122a0
	if (cr6.eq) goto loc_826122A0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82612c28
	ctx.lr = 0x82612278;
	sub_82612C28(ctx, base);
	// addi r30,r31,64
	r30.s64 = r31.s64 + 64;
	// li r29,4
	r29.s64 = 4;
loc_82612280:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82612294
	if (cr6.eq) goto loc_82612294;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82612a30
	ctx.lr = 0x82612294;
	sub_82612A30(ctx, base);
loc_82612294:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82612280
	if (!cr0.eq) goto loc_82612280;
loc_826122A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826122AC"))) PPC_WEAK_FUNC(sub_826122AC);
PPC_FUNC_IMPL(__imp__sub_826122AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826122B0"))) PPC_WEAK_FUNC(sub_826122B0);
PPC_FUNC_IMPL(__imp__sub_826122B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82612180
	sub_82612180(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826122BC"))) PPC_WEAK_FUNC(sub_826122BC);
PPC_FUNC_IMPL(__imp__sub_826122BC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826122C0"))) PPC_WEAK_FUNC(sub_826122C0);
PPC_FUNC_IMPL(__imp__sub_826122C0) {
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
	ctx.lr = 0x826122C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r30,r11
	r30.u64 = r11.u64;
	// beq cr6,0x82612310
	if (cr6.eq) goto loc_82612310;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-17804
	ctx.r5.s64 = r11.s64 + -17804;
	// li r6,9
	ctx.r6.s64 = 9;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x821fdd50
	ctx.lr = 0x82612304;
	sub_821FDD50(ctx, base);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x822d7720
	ctx.lr = 0x8261230C;
	sub_822D7720(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82612310:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-11208
	ctx.r5.s64 = r11.s64 + -11208;
	// li r6,102
	ctx.r6.s64 = 102;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822dc760
	ctx.lr = 0x8261232C;
	sub_822DC760(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8261233c
	if (cr6.eq) goto loc_8261233C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d7720
	ctx.lr = 0x8261233C;
	sub_822D7720(ctx, base);
loc_8261233C:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82612348"))) PPC_WEAK_FUNC(sub_82612348);
PPC_FUNC_IMPL(__imp__sub_82612348) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x82612354
	if (!cr6.lt) goto loc_82612354;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_82612354:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x82612374
	if (!cr6.eq) goto loc_82612374;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82179288
	sub_82179288(ctx, base);
	return;
loc_82612374:
	// subfic r3,r4,128
	xer.ca = ctx.r4.u32 <= 128;
	ctx.r3.s64 = 128 - ctx.r4.s64;
	// b 0x82179288
	sub_82179288(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8261237C"))) PPC_WEAK_FUNC(sub_8261237C);
PPC_FUNC_IMPL(__imp__sub_8261237C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82612380"))) PPC_WEAK_FUNC(sub_82612380);
PPC_FUNC_IMPL(__imp__sub_82612380) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-26892
	ctx.r10.s64 = r11.s64 + -26892;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826123AC;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826123c4
	if (cr6.eq) goto loc_826123C4;
	// bl 0x82130588
	ctx.lr = 0x826123C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826123C4:
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

__attribute__((alias("__imp__sub_826123DC"))) PPC_WEAK_FUNC(sub_826123DC);
PPC_FUNC_IMPL(__imp__sub_826123DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826123E0"))) PPC_WEAK_FUNC(sub_826123E0);
PPC_FUNC_IMPL(__imp__sub_826123E0) {
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
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826123F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// beq cr6,0x82612430
	if (cr6.eq) goto loc_82612430;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r8,96
	ctx.r8.s64 = 96;
	// addi r9,r11,-26892
	ctx.r9.s64 = r11.s64 + -26892;
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r3,21764(r10)
	PPC_STORE_U32(ctx.r10.u32 + 21764, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82612430:
	// li r11,0
	r11.s64 = 0;
	// stw r11,21764(r10)
	PPC_STORE_U32(ctx.r10.u32 + 21764, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82612448"))) PPC_WEAK_FUNC(sub_82612448);
PPC_FUNC_IMPL(__imp__sub_82612448) {
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
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x82612484
	if (!cr6.eq) goto loc_82612484;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-26592
	ctx.r4.s64 = ctx.r10.s64 + -26592;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x82612480;
	sub_8218B688(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_82612484:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187f40
	ctx.lr = 0x82612494;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826124f0
	if (cr6.eq) goto loc_826124F0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82187b88
	ctx.lr = 0x826124A8;
	sub_82187B88(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82178430
	ctx.lr = 0x826124B0;
	sub_82178430(ctx, base);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x82177bf8
	ctx.lr = 0x826124C4;
	sub_82177BF8(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82177ca0
	ctx.lr = 0x826124CC;
	sub_82177CA0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82179588
	ctx.lr = 0x826124E0;
	sub_82179588(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82177c50
	ctx.lr = 0x826124E8;
	sub_82177C50(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82187ba8
	ctx.lr = 0x826124F0;
	sub_82187BA8(ctx, base);
loc_826124F0:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82187bd0
	ctx.lr = 0x826124F8;
	sub_82187BD0(ctx, base);
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

__attribute__((alias("__imp__sub_8261250C"))) PPC_WEAK_FUNC(sub_8261250C);
PPC_FUNC_IMPL(__imp__sub_8261250C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82612510"))) PPC_WEAK_FUNC(sub_82612510);
PPC_FUNC_IMPL(__imp__sub_82612510) {
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
	// bl 0x823d91f0
	ctx.lr = 0x82612518;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r11,r31,2
	r11.s64 = r31.s64 + 2;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mullw r10,r11,r30
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r30.s32);
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,-2
	ctx.r3.s64 = r11.s64 + -2;
	// bl 0x821b3250
	ctx.lr = 0x82612540;
	sub_821B3250(ctx, base);
	// stw r3,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r3.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82612554;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82612604
	if (!cr6.gt) goto loc_82612604;
	// addi r29,r30,-2
	r29.s64 = r30.s64 + -2;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
loc_82612570:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826125b4
	if (!cr6.gt) goto loc_826125B4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// add r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 + ctx.r3.u64;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8261258C:
	// sth r9,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r9.u16);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// sth r7,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r7.u16);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// bne 0x8261258c
	if (!cr0.eq) goto loc_8261258C;
loc_826125B4:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sthx r6,r9,r3
	PPC_STORE_U16(ctx.r9.u32 + ctx.r3.u32, ctx.r6.u16);
	// cmpw cr6,r4,r29
	cr6.compare<int32_t>(ctx.r4.s32, r29.s32, xer);
	// sthx r10,r7,r3
	PPC_STORE_U16(ctx.r7.u32 + ctx.r3.u32, ctx.r10.u16);
	// beq cr6,0x826125f0
	if (cr6.eq) goto loc_826125F0;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sthx r10,r9,r3
	PPC_STORE_U16(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u16);
	// sthx r10,r8,r3
	PPC_STORE_U16(ctx.r8.u32 + ctx.r3.u32, ctx.r10.u16);
loc_826125F0:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + r31.u64;
	// add r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 + r31.u64;
	// cmpw cr6,r4,r30
	cr6.compare<int32_t>(ctx.r4.s32, r30.s32, xer);
	// blt cr6,0x82612570
	if (cr6.lt) goto loc_82612570;
loc_82612604:
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82612618;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82612620"))) PPC_WEAK_FUNC(sub_82612620);
PPC_FUNC_IMPL(__imp__sub_82612620) {
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
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
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
	// bl 0x823d91e4
	ctx.lr = 0x82612628;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9c4
	ctx.lr = 0x82612630;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// addi r24,r25,1
	r24.s64 = r25.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mullw r3,r24,r29
	ctx.r3.s64 = int64_t(r24.s32) * int64_t(r29.s32);
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x821b4838
	ctx.lr = 0x8261265C;
	sub_821B4838(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821b34f0
	ctx.lr = 0x82612674;
	sub_821B34F0(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x8261283c
	if (!cr6.gt) goto loc_8261283C;
	// extsw r11,r25
	r11.s64 = r25.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f26,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f26.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// frsp f25,f13
	f25.f64 = double(float(ctx.f13.f64));
	// lfs f27,18204(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 18204);
	f27.f64 = double(temp.f32);
loc_826126B0:
	// extsw r11,r28
	r11.s64 = r28.s32;
	// li r30,0
	r30.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f30,f12,f25
	f30.f64 = double(float(ctx.f12.f64 / f25.f64));
	// ble cr6,0x82612830
	if (!cr6.gt) goto loc_82612830;
	// extsw r11,r29
	r11.s64 = r29.s32;
	// clrlwi r26,r23,24
	r26.u64 = r23.u32 & 0xFF;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f28,f13
	f28.f64 = double(float(ctx.f13.f64));
loc_826126EC:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f29,f12,f28
	f29.f64 = double(float(ctx.f12.f64 / f28.f64));
	// fmuls f24,f29,f27
	f24.f64 = double(float(f29.f64 * f27.f64));
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82612710;
	sub_823DBAE8(ctx, base);
	// frsp f23,f1
	ctx.fpscr.disableFlushMode();
	f23.f64 = double(float(ctx.f1.f64));
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8261271C;
	sub_823DBBC8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f30,132(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// stfs f23,136(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x823dbae8
	ctx.lr = 0x82612734;
	sub_823DBAE8(ctx, base);
	// frsp f23,f1
	ctx.fpscr.disableFlushMode();
	f23.f64 = double(float(ctx.f1.f64));
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82612740;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// stfs f10,144(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// stfs f23,152(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// bl 0x823dbbc8
	ctx.lr = 0x82612758;
	sub_823DBBC8(ctx, base);
	// frsp f23,f1
	ctx.fpscr.disableFlushMode();
	f23.f64 = double(float(ctx.f1.f64));
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// bl 0x823dbae8
	ctx.lr = 0x82612764;
	sub_823DBAE8(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// stfs f9,192(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f31,196(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stfs f23,200(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// beq cr6,0x826127bc
	if (cr6.eq) goto loc_826127BC;
	// cmpw cr6,r28,r25
	cr6.compare<int32_t>(r28.s32, r25.s32, xer);
	// bne cr6,0x826127bc
	if (!cr6.eq) goto loc_826127BC;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f31,176(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f26,180(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stfs f31,184(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f31,160(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f30,164(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,168(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826127BC:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821b3cc0
	ctx.lr = 0x826127CC;
	sub_821B3CC0(ctx, base);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821b3de8
	ctx.lr = 0x826127DC;
	sub_821B3DE8(ctx, base);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821b40d0
	ctx.lr = 0x826127F0;
	sub_821B40D0(ctx, base);
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f29
	ctx.f12.f64 = double(float(f0.f64 * f29.f64));
	// fmuls f11,f30,f13
	ctx.f11.f64 = double(float(f30.f64 * ctx.f13.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821b3f08
	ctx.lr = 0x82612820;
	sub_821B3F08(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x826126ec
	if (cr6.lt) goto loc_826126EC;
loc_82612830:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r24
	cr6.compare<int32_t>(r28.s32, r24.s32, xer);
	// blt cr6,0x826126b0
	if (cr6.lt) goto loc_826126B0;
loc_8261283C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r10,r11,-9216
	ctx.r10.s64 = r11.s64 + -9216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// beq cr6,0x8261287c
	if (cr6.eq) goto loc_8261287C;
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261287c
	if (cr6.eq) goto loc_8261287C;
	// lbz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 124);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8261287c
	if (!cr6.eq) goto loc_8261287C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261287C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8261287C:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba10
	ctx.lr = 0x82612888;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8261288C"))) PPC_WEAK_FUNC(sub_8261288C);
PPC_FUNC_IMPL(__imp__sub_8261288C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82612890"))) PPC_WEAK_FUNC(sub_82612890);
PPC_FUNC_IMPL(__imp__sub_82612890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82612898;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x8218fe20
	ctx.lr = 0x826128BC;
	sub_8218FE20(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821902b0
	ctx.lr = 0x826128D0;
	sub_821902B0(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821904a8
	ctx.lr = 0x826128E0;
	sub_821904A8(ctx, base);
	// li r6,6
	ctx.r6.s64 = 6;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82190640
	ctx.lr = 0x826128F4;
	sub_82190640(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82190640
	ctx.lr = 0x82612908;
	sub_82190640(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82187150
	ctx.lr = 0x82612920;
	sub_82187150(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82612510
	ctx.lr = 0x82612934;
	sub_82612510(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82612958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8261298C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82612620
	ctx.lr = 0x826129B8;
	sub_82612620(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826129C4"))) PPC_WEAK_FUNC(sub_826129C4);
PPC_FUNC_IMPL(__imp__sub_826129C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826129C8"))) PPC_WEAK_FUNC(sub_826129C8);
PPC_FUNC_IMPL(__imp__sub_826129C8) {
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
	ctx.lr = 0x826129D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82612a24
	if (cr6.eq) goto loc_82612A24;
	// li r31,0
	r31.s64 = 0;
loc_826129F4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82612a10
	if (cr6.eq) goto loc_82612A10;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82190ae0
	ctx.lr = 0x82612A0C;
	sub_82190AE0(ctx, base);
	// or r28,r3,r28
	r28.u64 = ctx.r3.u64 | r28.u64;
loc_82612A10:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826129f4
	if (cr6.lt) goto loc_826129F4;
loc_82612A24:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82612A30"))) PPC_WEAK_FUNC(sub_82612A30);
PPC_FUNC_IMPL(__imp__sub_82612A30) {
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
	ctx.lr = 0x82612A38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82612a84
	if (cr6.eq) goto loc_82612A84;
	// li r31,0
	r31.s64 = 0;
loc_82612A58:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82612a70
	if (cr6.eq) goto loc_82612A70;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82190b28
	ctx.lr = 0x82612A70;
	sub_82190B28(ctx, base);
loc_82612A70:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82612a58
	if (cr6.lt) goto loc_82612A58;
loc_82612A84:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82612A8C"))) PPC_WEAK_FUNC(sub_82612A8C);
PPC_FUNC_IMPL(__imp__sub_82612A8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82612A90"))) PPC_WEAK_FUNC(sub_82612A90);
PPC_FUNC_IMPL(__imp__sub_82612A90) {
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
	ctx.lr = 0x82612A98;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82612aec
	if (cr6.eq) goto loc_82612AEC;
	// li r31,0
	r31.s64 = 0;
loc_82612AB4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82612ad8
	if (cr6.eq) goto loc_82612AD8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82612AD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82612AD8:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82612ab4
	if (cr6.lt) goto loc_82612AB4;
loc_82612AEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82192618
	ctx.lr = 0x82612AF4;
	sub_82192618(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82612AFC"))) PPC_WEAK_FUNC(sub_82612AFC);
PPC_FUNC_IMPL(__imp__sub_82612AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82612B00"))) PPC_WEAK_FUNC(sub_82612B00);
PPC_FUNC_IMPL(__imp__sub_82612B00) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-25064
	ctx.r10.s64 = ctx.r10.s64 + -25064;
loc_82612B30:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82612b54
	if (cr6.eq) goto loc_82612B54;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82612b30
	if (cr6.eq) goto loc_82612B30;
loc_82612B54:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82612b80
	if (cr6.eq) goto loc_82612B80;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-24780(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24780);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82612B7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82612b84
	goto loc_82612B84;
loc_82612B80:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82612B84:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82612BA8"))) PPC_WEAK_FUNC(sub_82612BA8);
PPC_FUNC_IMPL(__imp__sub_82612BA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// bge cr6,0x82612bd8
	if (!cr6.lt) goto loc_82612BD8;
	// addi r11,r4,20
	r11.s64 = ctx.r4.s64 + 20;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
loc_82612BBC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82612be0
	if (!cr6.eq) goto loc_82612BE0;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// blt cr6,0x82612bbc
	if (cr6.lt) goto loc_82612BBC;
loc_82612BD8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_82612BE0:
	// addi r11,r4,20
	r11.s64 = ctx.r4.s64 + 20;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82612BF0"))) PPC_WEAK_FUNC(sub_82612BF0);
PPC_FUNC_IMPL(__imp__sub_82612BF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
loc_82612BF8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82612c1c
	if (!cr6.eq) goto loc_82612C1C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x82612bf8
	if (cr6.lt) goto loc_82612BF8;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82612C1C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82612C24"))) PPC_WEAK_FUNC(sub_82612C24);
PPC_FUNC_IMPL(__imp__sub_82612C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82612C28"))) PPC_WEAK_FUNC(sub_82612C28);
PPC_FUNC_IMPL(__imp__sub_82612C28) {
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
	ctx.lr = 0x82612C30;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r31,r3,48
	r31.s64 = ctx.r3.s64 + 48;
	// li r30,4
	r30.s64 = 4;
loc_82612C40:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82612c58
	if (cr6.eq) goto loc_82612C58;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826129c8
	ctx.lr = 0x82612C54;
	sub_826129C8(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
loc_82612C58:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82612c40
	if (!cr0.eq) goto loc_82612C40;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82612C6C"))) PPC_WEAK_FUNC(sub_82612C6C);
PPC_FUNC_IMPL(__imp__sub_82612C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82612C70"))) PPC_WEAK_FUNC(sub_82612C70);
PPC_FUNC_IMPL(__imp__sub_82612C70) {
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
	ctx.lr = 0x82612C78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// addi r8,r31,12
	ctx.r8.s64 = r31.s64 + 12;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// rlwinm r7,r31,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r5,3,0,28
	r26.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,-26876(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// lwzx r25,r7,r9
	r25.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lwzx r30,r6,r11
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// bl 0x8217c088
	ctx.lr = 0x82612CB0;
	sub_8217C088(ctx, base);
	// lhz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82612d30
	if (cr6.eq) goto loc_82612D30;
	// li r28,0
	r28.s64 = 0;
	// li r24,1
	r24.s64 = 1;
loc_82612CC8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82612d1c
	if (cr6.eq) goto loc_82612D1C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82612d00
	if (cr6.eq) goto loc_82612D00;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rlwinm r10,r31,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r31,27
	ctx.r9.u64 = r31.u32 & 0x1F;
	// slw r8,r24,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r24.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82612d1c
	if (cr6.eq) goto loc_82612D1C;
loc_82612D00:
	// lwzx r11,r25,r26
	r11.u64 = PPC_LOAD_U32(r25.u32 + r26.u32);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82612d1c
	if (cr6.eq) goto loc_82612D1C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82178ac8
	ctx.lr = 0x82612D1C;
	sub_82178AC8(ctx, base);
loc_82612D1C:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82612cc8
	if (cr6.lt) goto loc_82612CC8;
loc_82612D30:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82612D38"))) PPC_WEAK_FUNC(sub_82612D38);
PPC_FUNC_IMPL(__imp__sub_82612D38) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x82612D40;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mr r19,r9
	r19.u64 = ctx.r9.u64;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r7,12
	ctx.r9.s64 = ctx.r7.s64 + 12;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r6,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// li r16,32
	r16.s64 = 32;
	// li r17,48
	r17.s64 = 48;
	// lwzx r21,r7,r3
	r21.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// li r22,-2
	r22.s64 = -2;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// add r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	// li r18,16
	r18.s64 = 16;
	// beq cr6,0x82612dbc
	if (cr6.eq) goto loc_82612DBC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r28,r16
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r28,r17
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r28,r18
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82612df4
	goto loc_82612DF4;
loc_82612DBC:
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v57,r20,r18
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
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
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v56,v58,234
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x15));
	// vpermwi128 v55,v58,186
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x45));
	// vpermwi128 v54,v58,174
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x51));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82612DF4:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82612f7c
	if (!cr6.eq) goto loc_82612F7C;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82613140
	if (cr6.eq) goto loc_82613140;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82613140
	if (cr6.eq) goto loc_82613140;
	// lbz r11,25(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82612e7c
	if (cr6.eq) goto loc_82612E7C;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82612E3C;
	sub_8217C088(ctx, base);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// lhz r9,26(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r29,0(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x82613140
	if (cr6.eq) goto loc_82613140;
	// li r26,1
	r26.s64 = 1;
loc_82612E58:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// slw r4,r26,r31
	ctx.r4.u64 = r31.u8 & 0x20 ? 0 : (r26.u32 << (r31.u8 & 0x3F));
	// bl 0x82178ac8
	ctx.lr = 0x82612E64;
	sub_82178AC8(ctx, base);
	// lhz r11,26(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 26);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82612e58
	if (cr6.lt) goto loc_82612E58;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9218
	return;
loc_82612E7C:
	// lbz r5,23(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 23);
	// cmpwi cr6,r5,-2
	cr6.compare<int32_t>(ctx.r5.s32, -2, xer);
	// beq cr6,0x82612f5c
	if (cr6.eq) goto loc_82612F5C;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x821a1768
	ctx.lr = 0x82612E94;
	sub_821A1768(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82612f4c
	if (cr6.eq) goto loc_82612F4C;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v12,r28,r17
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v13,r28,r16
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v53,v63,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v52,v62,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v51,v61,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v11,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// vmulfp128 v10,v0,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v53.f32)));
	// vspltw128 v9,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmulfp128 v8,v0,v52
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vspltw128 v7,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v6,v0,v51
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// vspltw128 v5,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vmaddfp v4,v0,v11,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v3,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// lvx128 v0,r28,r18
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v2,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v1,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// vspltw128 v31,v61,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vmaddfp v29,v0,v9,v10
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v28,v0,v7,v8
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v27,v0,v5,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v26,v0,v3,v4
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v25,v13,v2,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v13,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v13,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v13,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v25,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82612F4C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82612F5C;
	sub_8217C088(ctx, base);
loc_82612F5C:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82613140
	if (cr6.eq) goto loc_82613140;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82178ac8
	ctx.lr = 0x82612F74;
	sub_82178AC8(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9218
	return;
loc_82612F7C:
	// lhz r11,4(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 4);
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613140
	if (cr6.eq) goto loc_82613140;
	// li r27,0
	r27.s64 = 0;
	// li r26,1
	r26.s64 = 1;
	// lis r23,-32124
	r23.s64 = -2105278464;
loc_82612F98:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lwzx r29,r27,r11
	r29.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8261312c
	if (cr6.eq) goto loc_8261312C;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x82612fd0
	if (cr6.eq) goto loc_82612FD0;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// rlwinm r10,r24,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r24,27
	ctx.r9.u64 = r24.u32 & 0x1F;
	// slw r8,r26,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r26.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8261312c
	if (cr6.eq) goto loc_8261312C;
loc_82612FD0:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r10,r11,r27
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8261312c
	if (cr6.eq) goto loc_8261312C;
	// lbz r11,25(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 25);
	// lbz r5,23(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 23);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613040
	if (cr6.eq) goto loc_82613040;
	// cmpwi cr6,r22,-1
	cr6.compare<int32_t>(r22.s32, -1, xer);
	// beq cr6,0x82613008
	if (cr6.eq) goto loc_82613008;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-26876(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82613004;
	sub_8217C088(ctx, base);
	// li r22,-1
	r22.s64 = -1;
loc_82613008:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// lhz r10,26(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 26);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwzx r30,r11,r27
	r30.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// beq cr6,0x8261312c
	if (cr6.eq) goto loc_8261312C;
loc_82613020:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// slw r4,r26,r31
	ctx.r4.u64 = r31.u8 & 0x20 ? 0 : (r26.u32 << (r31.u8 & 0x3F));
	// bl 0x82178ac8
	ctx.lr = 0x8261302C;
	sub_82178AC8(ctx, base);
	// lhz r11,26(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 26);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82613020
	if (cr6.lt) goto loc_82613020;
	// b 0x8261312c
	goto loc_8261312C;
loc_82613040:
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// bl 0x821a1768
	ctx.lr = 0x82613050;
	sub_821A1768(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82613108
	if (cr6.eq) goto loc_82613108;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// lvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lvx128 v12,r28,r17
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// lvx128 v13,r28,r16
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v50,v63,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v49,v62,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v48,v61,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v11,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// vmulfp128 v10,v0,v50
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v50.f32)));
	// vspltw128 v9,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmulfp128 v8,v0,v49
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v49.f32)));
	// vspltw128 v7,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v6,v0,v48
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v48.f32)));
	// vspltw128 v5,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vmaddfp v4,v0,v11,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v3,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// lvx128 v0,r28,r18
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v2,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v1,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// vspltw128 v31,v61,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vmaddfp v29,v0,v9,v10
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v28,v0,v7,v8
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v27,v0,v5,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v26,v0,v3,v4
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v25,v13,v2,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v13,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v13,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v13,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v25,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82613108:
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lwz r3,-26876(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82613114;
	sub_8217C088(ctx, base);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r3,r11,r27
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261312c
	if (cr6.eq) goto loc_8261312C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82178ac8
	ctx.lr = 0x8261312C;
	sub_82178AC8(ctx, base);
loc_8261312C:
	// lhz r11,4(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82612f98
	if (cr6.lt) goto loc_82612F98;
loc_82613140:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82613148"))) PPC_WEAK_FUNC(sub_82613148);
PPC_FUNC_IMPL(__imp__sub_82613148) {
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
	ctx.lr = 0x82613150;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// addi r9,r31,12
	ctx.r9.s64 = r31.s64 + 12;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r3,-26876(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// lwzx r30,r8,r11
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// bl 0x8217c088
	ctx.lr = 0x82613184;
	sub_8217C088(ctx, base);
	// lhz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826131f8
	if (cr6.eq) goto loc_826131F8;
	// li r29,0
	r29.s64 = 0;
	// li r24,1
	r24.s64 = 1;
loc_8261319C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826131e4
	if (cr6.eq) goto loc_826131E4;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x826131d4
	if (cr6.eq) goto loc_826131D4;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// rlwinm r10,r31,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r31,27
	ctx.r9.u64 = r31.u32 & 0x1F;
	// slw r8,r24,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r24.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826131e4
	if (cr6.eq) goto loc_826131E4;
loc_826131D4:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82190bd8
	ctx.lr = 0x826131E4;
	sub_82190BD8(ctx, base);
loc_826131E4:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8261319c
	if (cr6.lt) goto loc_8261319C;
loc_826131F8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82613200"))) PPC_WEAK_FUNC(sub_82613200);
PPC_FUNC_IMPL(__imp__sub_82613200) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91c8
	ctx.lr = 0x82613208;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r11,r27,12
	r11.s64 = r27.s64 + 12;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r20,r9
	r20.u64 = ctx.r9.u64;
	// li r16,32
	r16.s64 = 32;
	// lwzx r21,r10,r3
	r21.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// li r17,48
	r17.s64 = 48;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// li r19,16
	r19.s64 = 16;
	// beq cr6,0x82613278
	if (cr6.eq) goto loc_82613278;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r31,r16
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r31,r17
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lvx128 v60,r31,r19
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826132b0
	goto loc_826132B0;
loc_82613278:
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v57,r26,r19
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
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
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v56,v58,234
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x15));
	// vpermwi128 v55,v58,186
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x45));
	// vpermwi128 v54,v58,174
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x51));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826132B0:
	// lhz r11,4(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 4);
	// li r29,-2
	r29.s64 = -2;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613450
	if (cr6.eq) goto loc_82613450;
	// li r23,0
	r23.s64 = 0;
	// li r18,1
	r18.s64 = 1;
	// lis r22,-32124
	r22.s64 = -2105278464;
loc_826132D0:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lwzx r30,r23,r11
	r30.u64 = PPC_LOAD_U32(r23.u32 + r11.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8261343c
	if (cr6.eq) goto loc_8261343C;
	// lbz r5,23(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 23);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8261330c
	if (cr6.eq) goto loc_8261330C;
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// rlwinm r10,r28,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r28,27
	ctx.r9.u64 = r28.u32 & 0x1F;
	// slw r8,r18,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8261343c
	if (cr6.eq) goto loc_8261343C;
loc_8261330C:
	// lbz r11,25(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261334c
	if (cr6.eq) goto loc_8261334C;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x82613330
	if (cr6.eq) goto loc_82613330;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,-26876(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8261332C;
	sub_8217C088(ctx, base);
	// li r29,-1
	r29.s64 = -1;
loc_82613330:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82190e18
	ctx.lr = 0x82613348;
	sub_82190E18(ctx, base);
	// b 0x8261343c
	goto loc_8261343C;
loc_8261334C:
	// cmpw cr6,r5,r29
	cr6.compare<int32_t>(ctx.r5.s32, r29.s32, xer);
	// beq cr6,0x82613428
	if (cr6.eq) goto loc_82613428;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821a1768
	ctx.lr = 0x82613364;
	sub_821A1768(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8261341c
	if (cr6.eq) goto loc_8261341C;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v0,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v12,r31,r17
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v13,r31,r16
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v53,v63,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v52,v62,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v51,v61,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v11,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vmulfp128 v10,v0,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v53.f32)));
	// vspltw128 v9,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmulfp128 v8,v0,v52
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vspltw128 v7,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v6,v0,v51
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// vspltw128 v5,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vmaddfp v4,v0,v11,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vspltw128 v3,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// lvx128 v0,r31,r19
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v2,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v1,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// vspltw128 v31,v61,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vmaddfp v29,v0,v9,v10
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v28,v0,v7,v8
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v27,v0,v5,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v26,v0,v3,v4
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v25,v13,v2,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v13,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v13,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v13,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v25,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8261341C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-26876(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82613428;
	sub_8217C088(ctx, base);
loc_82613428:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82190bd8
	ctx.lr = 0x8261343C;
	sub_82190BD8(ctx, base);
loc_8261343C:
	// lhz r11,4(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x826132d0
	if (cr6.lt) goto loc_826132D0;
loc_82613450:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82613458"))) PPC_WEAK_FUNC(sub_82613458);
PPC_FUNC_IMPL(__imp__sub_82613458) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82613460;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,48
	r31.s64 = ctx.r3.s64 + 48;
	// li r30,4
	r30.s64 = 4;
	// li r28,0
	r28.s64 = 0;
loc_82613470:
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82613494
	if (cr6.eq) goto loc_82613494;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82612a90
	ctx.lr = 0x82613484;
	sub_82612A90(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82192618
	ctx.lr = 0x8261348C;
	sub_82192618(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82613494;
	sub_82130588(ctx, base);
loc_82613494:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82613470
	if (!cr0.eq) goto loc_82613470;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826134AC"))) PPC_WEAK_FUNC(sub_826134AC);
PPC_FUNC_IMPL(__imp__sub_826134AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826134B0"))) PPC_WEAK_FUNC(sub_826134B0);
PPC_FUNC_IMPL(__imp__sub_826134B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82613458
	sub_82613458(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826134B4"))) PPC_WEAK_FUNC(sub_826134B4);
PPC_FUNC_IMPL(__imp__sub_826134B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826134B8"))) PPC_WEAK_FUNC(sub_826134B8);
PPC_FUNC_IMPL(__imp__sub_826134B8) {
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
	ctx.lr = 0x826134C0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r11,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r11.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r31,4(r25)
	PPC_STORE_U16(r25.u32 + 4, r31.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82613500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82613588
	if (!cr6.gt) goto loc_82613588;
	// li r23,0
	r23.s64 = 0;
	// mr r24,r31
	r24.u64 = r31.u64;
	// mr r26,r23
	r26.u64 = r23.u64;
loc_82613518:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// add. r31,r26,r11
	r31.u64 = r26.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8261357c
	if (cr0.eq) goto loc_8261357C;
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r27,r28
	r30.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82613578
	if (cr6.eq) goto loc_82613578;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82613578
	if (cr6.eq) goto loc_82613578;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8261354C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82613578
	if (cr6.eq) goto loc_82613578;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82613560;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r28
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// bl 0x82191798
	ctx.lr = 0x82613574;
	sub_82191798(ctx, base);
	// b 0x8261357c
	goto loc_8261357C;
loc_82613578:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_8261357C:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x82613518
	if (!cr0.eq) goto loc_82613518;
loc_82613588:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82613590"))) PPC_WEAK_FUNC(sub_82613590);
PPC_FUNC_IMPL(__imp__sub_82613590) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x826134b8
	ctx.lr = 0x826135B4;
	sub_826134B8(ctx, base);
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823d9890
	ctx.lr = 0x826135C4;
	sub_823D9890(ctx, base);
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

__attribute__((alias("__imp__sub_826135E0"))) PPC_WEAK_FUNC(sub_826135E0);
PPC_FUNC_IMPL(__imp__sub_826135E0) {
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
	ctx.lr = 0x826135E8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r26,3
	r26.s64 = 3;
	// li r24,0
	r24.s64 = 0;
loc_82613604:
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82613660
	if (cr6.eq) goto loc_82613660;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82613660
	if (cr6.eq) goto loc_82613660;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82613628;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82613660
	if (cr6.eq) goto loc_82613660;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8261363C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82613664
	if (cr6.eq) goto loc_82613664;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x823248d0
	ctx.lr = 0x8261365C;
	sub_823248D0(ctx, base);
	// b 0x82613664
	goto loc_82613664;
loc_82613660:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_82613664:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bge 0x82613604
	if (!cr0.lt) goto loc_82613604;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8261367C"))) PPC_WEAK_FUNC(sub_8261367C);
PPC_FUNC_IMPL(__imp__sub_8261367C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613680"))) PPC_WEAK_FUNC(sub_82613680);
PPC_FUNC_IMPL(__imp__sub_82613680) {
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
	ctx.lr = 0x82613688;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826136f0
	if (!cr6.gt) goto loc_826136F0;
	// addi r28,r26,6
	r28.s64 = r26.s64 + 6;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
loc_826136A0:
	// lhz r30,0(r28)
	r30.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826136e4
	if (cr6.eq) goto loc_826136E4;
	// lwz r29,-6(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + -6);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826136dc
	if (!cr6.gt) goto loc_826136DC;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_826136BC:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826136d0
	if (cr6.eq) goto loc_826136D0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826136D0;
	sub_82130588(ctx, base);
loc_826136D0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x826136bc
	if (!cr0.eq) goto loc_826136BC;
loc_826136DC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826136E4;
	sub_82130588(ctx, base);
loc_826136E4:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x826136a0
	if (!cr0.eq) goto loc_826136A0;
loc_826136F0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x826136F8;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82613700"))) PPC_WEAK_FUNC(sub_82613700);
PPC_FUNC_IMPL(__imp__sub_82613700) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f31,4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f31,8(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f31,20(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f31,24(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f31,32(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f31,36(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f31,40(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// bl 0x826135e0
	ctx.lr = 0x8261374C;
	sub_826135E0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f31,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// stw r9,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r9.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r9,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r9.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r9,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r9.u32);
loc_8261376C:
	// stw r9,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, ctx.r9.u32);
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8261376c
	if (!cr0.eq) goto loc_8261376C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_826137A0"))) PPC_WEAK_FUNC(sub_826137A0);
PPC_FUNC_IMPL(__imp__sub_826137A0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x826137A8;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r30,1
	r30.s64 = 1;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// slw r11,r30,r28
	r11.u64 = r28.u8 & 0x20 ? 0 : (r30.u32 << (r28.u8 & 0x3F));
	// and r10,r11,r8
	ctx.r10.u64 = r11.u64 & ctx.r8.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82613930
	if (cr6.eq) goto loc_82613930;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821d0898
	ctx.lr = 0x826137E0;
	sub_821D0898(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-25064
	ctx.r4.s64 = r11.s64 + -25064;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821cfe80
	ctx.lr = 0x826137F4;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82613904
	if (!cr6.eq) goto loc_82613904;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261381C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r25,r30
	r25.u64 = r30.u64;
	// bl 0x823dd7f0
	ctx.lr = 0x82613828;
	sub_823DD7F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82613840
	if (cr6.eq) goto loc_82613840;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dd7f0
	ctx.lr = 0x82613838;
	sub_823DD7F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
loc_82613840:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82613868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8261387c
	if (cr6.eq) goto loc_8261387C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82613590
	ctx.lr = 0x82613878;
	sub_82613590(ctx, base);
	// b 0x82613880
	goto loc_82613880;
loc_8261387C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82613880:
	// addi r11,r28,12
	r11.s64 = r28.s64 + 12;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stwx r3,r29,r26
	PPC_STORE_U32(r29.u32 + r26.u32, ctx.r3.u32);
	// ble cr6,0x82613904
	if (!cr6.gt) goto loc_82613904;
	// clrlwi r25,r25,24
	r25.u64 = r25.u32 & 0xFF;
loc_8261389C:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x826138e0
	if (!cr6.eq) goto loc_826138E0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826138C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826138DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_826138E0:
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// lwzx r3,r29,r26
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r26.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82612b00
	ctx.lr = 0x826138F8;
	sub_82612B00(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x8261389c
	if (cr6.lt) goto loc_8261389C;
loc_82613904:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8261391C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r28,16
	ctx.r9.s64 = r28.s64 + 16;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r8,r26
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r8.u32 + r26.u32, temp.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
loc_82613930:
	// bl 0x821bbea8
	ctx.lr = 0x82613934;
	sub_821BBEA8(ctx, base);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82613700
	ctx.lr = 0x8261393C;
	sub_82613700(ctx, base);
	// li r8,-1
	ctx.r8.s64 = -1;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x826137a0
	ctx.lr = 0x82613958;
	sub_826137A0(ctx, base);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82613458
	ctx.lr = 0x82613960;
	sub_82613458(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x82613964;
	sub_821BBF00(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8261396C"))) PPC_WEAK_FUNC(sub_8261396C);
PPC_FUNC_IMPL(__imp__sub_8261396C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613970"))) PPC_WEAK_FUNC(sub_82613970);
PPC_FUNC_IMPL(__imp__sub_82613970) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82613978;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r11,-4476
	ctx.r5.s64 = r11.s64 + -4476;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x826137a0
	ctx.lr = 0x826139A4;
	sub_826137A0(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-26280
	ctx.r5.s64 = ctx.r10.s64 + -26280;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x826137a0
	ctx.lr = 0x826139C4;
	sub_826137A0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-4460
	ctx.r5.s64 = ctx.r9.s64 + -4460;
	// li r6,2
	ctx.r6.s64 = 2;
	// bl 0x826137a0
	ctx.lr = 0x826139E4;
	sub_826137A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r8,-26288
	ctx.r5.s64 = ctx.r8.s64 + -26288;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826137a0
	ctx.lr = 0x82613A04;
	sub_826137A0(ctx, base);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,31624
	ctx.r4.s64 = ctx.r7.s64 + 31624;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82613A18;
	sub_821CFE80(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82613a44
	if (cr6.eq) goto loc_82613A44;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82613A40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82613a4c
	goto loc_82613A4C;
loc_82613A44:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82613A4C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-26296
	ctx.r4.s64 = ctx.r10.s64 + -26296;
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82613A68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,96(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 96, temp.u32);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,12928
	ctx.r4.s64 = ctx.r8.s64 + 12928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82613A80;
	sub_821CFE80(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82613ac4
	if (cr6.eq) goto loc_82613AC4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82613AA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82613AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82613AC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82613ACC"))) PPC_WEAK_FUNC(sub_82613ACC);
PPC_FUNC_IMPL(__imp__sub_82613ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613AD0"))) PPC_WEAK_FUNC(sub_82613AD0);
PPC_FUNC_IMPL(__imp__sub_82613AD0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x826135e0
	ctx.lr = 0x82613AF4;
	sub_826135E0(ctx, base);
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821d2aa8
	ctx.lr = 0x82613B00;
	sub_821D2AA8(ctx, base);
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

__attribute__((alias("__imp__sub_82613B1C"))) PPC_WEAK_FUNC(sub_82613B1C);
PPC_FUNC_IMPL(__imp__sub_82613B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613B20"))) PPC_WEAK_FUNC(sub_82613B20);
PPC_FUNC_IMPL(__imp__sub_82613B20) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82613B28;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lhz r5,10(r16)
	ctx.r5.u64 = PPC_LOAD_U16(r16.u32 + 10);
	// mr r20,r8
	r20.u64 = ctx.r8.u64;
	// mr r19,r9
	r19.u64 = ctx.r9.u64;
	// addi r22,r16,4
	r22.s64 = r16.s64 + 4;
	// li r27,0
	r27.s64 = 0;
	// li r31,4
	r31.s64 = 4;
	// cmplwi cr6,r5,4
	cr6.compare<uint32_t>(ctx.r5.u32, 4, xer);
	// beq cr6,0x82613b8c
	if (cr6.eq) goto loc_82613B8C;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r4,0(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// bl 0x82613680
	ctx.lr = 0x82613B6C;
	sub_82613680(ctx, base);
	// stw r27,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r27.u32);
	// sth r27,4(r22)
	PPC_STORE_U16(r22.u32 + 4, r27.u16);
	// li r4,4
	ctx.r4.s64 = 4;
	// sth r27,6(r22)
	PPC_STORE_U16(r22.u32 + 6, r27.u16);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821b5998
	ctx.lr = 0x82613B84;
	sub_821B5998(ctx, base);
	// stw r3,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r3.u32);
	// sth r31,6(r22)
	PPC_STORE_U16(r22.u32 + 6, r31.u16);
loc_82613B8C:
	// lhz r11,6(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82613bac
	if (!cr6.eq) goto loc_82613BAC;
	// sth r31,6(r22)
	PPC_STORE_U16(r22.u32 + 6, r31.u16);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821b5998
	ctx.lr = 0x82613BA8;
	sub_821B5998(ctx, base);
	// stw r3,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r3.u32);
loc_82613BAC:
	// mr r23,r27
	r23.u64 = r27.u64;
	// sth r31,4(r22)
	PPC_STORE_U16(r22.u32 + 4, r31.u16);
	// mr r18,r27
	r18.u64 = r27.u64;
	// addi r17,r30,48
	r17.s64 = r30.s64 + 48;
loc_82613BBC:
	// lwz r26,0(r17)
	r26.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82613d34
	if (cr6.eq) goto loc_82613D34;
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// add r31,r18,r11
	r31.u64 = r18.u64 + r11.u64;
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmpw cr6,r5,r25
	cr6.compare<int32_t>(ctx.r5.s32, r25.s32, xer);
	// beq cr6,0x82613c18
	if (cr6.eq) goto loc_82613C18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821b5db8
	ctx.lr = 0x82613BE8;
	sub_821B5DB8(ctx, base);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// sth r27,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r27.u16);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// sth r27,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r27.u16);
	// beq cr6,0x82613c0c
	if (cr6.eq) goto loc_82613C0C;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821b5998
	ctx.lr = 0x82613C08;
	sub_821B5998(ctx, base);
	// b 0x82613c10
	goto loc_82613C10;
loc_82613C0C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82613C10:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r25,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r25.u16);
loc_82613C18:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82613c48
	if (!cr6.eq) goto loc_82613C48;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// sth r25,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r25.u16);
	// beq cr6,0x82613c40
	if (cr6.eq) goto loc_82613C40;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821b5998
	ctx.lr = 0x82613C3C;
	sub_821B5998(ctx, base);
	// b 0x82613c44
	goto loc_82613C44;
loc_82613C40:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82613C44:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_82613C48:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r24,3,0,28
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 3) & 0xFFFFFFF8;
	// sth r25,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r25.u16);
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// lhz r8,4(r26)
	ctx.r8.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// lhz r7,6(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplw cr6,r7,r8
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, xer);
	// beq cr6,0x82613ca0
	if (cr6.eq) goto loc_82613CA0;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82613C70;
	sub_82130588(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// lhz r31,4(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82613c94
	if (cr6.eq) goto loc_82613C94;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82613C90;
	sub_82130528(ctx, base);
	// b 0x82613c98
	goto loc_82613C98;
loc_82613C94:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82613C98:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
loc_82613CA0:
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r31,4(r26)
	r31.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82613cd0
	if (!cr6.eq) goto loc_82613CD0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// beq cr6,0x82613cc8
	if (cr6.eq) goto loc_82613CC8;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82613CC4;
	sub_82130528(ctx, base);
	// b 0x82613ccc
	goto loc_82613CCC;
loc_82613CC8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82613CCC:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_82613CD0:
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// mr r28,r27
	r28.u64 = r27.u64;
	// lhz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82613d34
	if (cr6.eq) goto loc_82613D34;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_82613CE8:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82613d20
	if (cr6.eq) goto loc_82613D20;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r9,r19
	ctx.r9.u64 = r19.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x821911f8
	ctx.lr = 0x82613D1C;
	sub_821911F8(ctx, base);
	// stwx r3,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r3.u32);
loc_82613D20:
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82613ce8
	if (cr6.lt) goto loc_82613CE8;
loc_82613D34:
	// addi r18,r18,8
	r18.s64 = r18.s64 + 8;
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r17,r17,4
	r17.s64 = r17.s64 + 4;
	// cmpwi cr6,r18,32
	cr6.compare<int32_t>(r18.s32, 32, xer);
	// blt cr6,0x82613bbc
	if (cr6.lt) goto loc_82613BBC;
	// li r11,1
	r11.s64 = 1;
	// lwz r10,12(r16)
	ctx.r10.u64 = PPC_LOAD_U32(r16.u32 + 12);
	// slw r9,r11,r24
	ctx.r9.u64 = r24.u8 & 0x20 ? 0 : (r11.u32 << (r24.u8 & 0x3F));
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,12(r16)
	PPC_STORE_U32(r16.u32 + 12, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82613D64"))) PPC_WEAK_FUNC(sub_82613D64);
PPC_FUNC_IMPL(__imp__sub_82613D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613D68"))) PPC_WEAK_FUNC(sub_82613D68);
PPC_FUNC_IMPL(__imp__sub_82613D68) {
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
	ctx.lr = 0x82613D70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,16(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613dac
	if (cr6.eq) goto loc_82613DAC;
	// li r31,0
	r31.s64 = 0;
loc_82613D8C:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82615238
	ctx.lr = 0x82613D98;
	sub_82615238(ctx, base);
	// lhz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x82613d8c
	if (cr6.lt) goto loc_82613D8C;
loc_82613DAC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82613DB4"))) PPC_WEAK_FUNC(sub_82613DB4);
PPC_FUNC_IMPL(__imp__sub_82613DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613DB8"))) PPC_WEAK_FUNC(sub_82613DB8);
PPC_FUNC_IMPL(__imp__sub_82613DB8) {
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
	ctx.lr = 0x82613DC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,16(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613dfc
	if (cr6.eq) goto loc_82613DFC;
	// li r31,0
	r31.s64 = 0;
loc_82613DDC:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82615198
	ctx.lr = 0x82613DE8;
	sub_82615198(ctx, base);
	// lhz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x82613ddc
	if (cr6.lt) goto loc_82613DDC;
loc_82613DFC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82613E04"))) PPC_WEAK_FUNC(sub_82613E04);
PPC_FUNC_IMPL(__imp__sub_82613E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613E08"))) PPC_WEAK_FUNC(sub_82613E08);
PPC_FUNC_IMPL(__imp__sub_82613E08) {
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
	ctx.lr = 0x82613E10;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,16(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613e4c
	if (cr6.eq) goto loc_82613E4C;
	// li r31,0
	r31.s64 = 0;
loc_82613E2C:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x826151e8
	ctx.lr = 0x82613E38;
	sub_826151E8(ctx, base);
	// lhz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x82613e2c
	if (cr6.lt) goto loc_82613E2C;
loc_82613E4C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82613E54"))) PPC_WEAK_FUNC(sub_82613E54);
PPC_FUNC_IMPL(__imp__sub_82613E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613E58"))) PPC_WEAK_FUNC(sub_82613E58);
PPC_FUNC_IMPL(__imp__sub_82613E58) {
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
	ctx.lr = 0x82613E60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,16(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613e9c
	if (cr6.eq) goto loc_82613E9C;
	// li r31,0
	r31.s64 = 0;
loc_82613E7C:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82615288
	ctx.lr = 0x82613E88;
	sub_82615288(ctx, base);
	// lhz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x82613e7c
	if (cr6.lt) goto loc_82613E7C;
loc_82613E9C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82613EA4"))) PPC_WEAK_FUNC(sub_82613EA4);
PPC_FUNC_IMPL(__imp__sub_82613EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613EA8"))) PPC_WEAK_FUNC(sub_82613EA8);
PPC_FUNC_IMPL(__imp__sub_82613EA8) {
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
	ctx.lr = 0x82613EB0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lhz r11,16(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613efc
	if (cr6.eq) goto loc_82613EFC;
	// li r30,0
	r30.s64 = 0;
loc_82613ED0:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82613efc
	if (!cr6.eq) goto loc_82613EFC;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x826152d8
	ctx.lr = 0x82613EE8;
	sub_826152D8(ctx, base);
	// lhz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x82613ed0
	if (cr6.lt) goto loc_82613ED0;
loc_82613EFC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82613F04"))) PPC_WEAK_FUNC(sub_82613F04);
PPC_FUNC_IMPL(__imp__sub_82613F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613F08"))) PPC_WEAK_FUNC(sub_82613F08);
PPC_FUNC_IMPL(__imp__sub_82613F08) {
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
	ctx.lr = 0x82613F10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,16(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613f5c
	if (cr6.eq) goto loc_82613F5C;
	// li r31,0
	r31.s64 = 0;
loc_82613F30:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82615330
	ctx.lr = 0x82613F3C;
	sub_82615330(ctx, base);
	// cmplw cr6,r29,r3
	cr6.compare<uint32_t>(r29.u32, ctx.r3.u32, xer);
	// bgt cr6,0x82613f48
	if (cr6.gt) goto loc_82613F48;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_82613F48:
	// lhz r11,16(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 16);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82613f30
	if (cr6.lt) goto loc_82613F30;
loc_82613F5C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82613F68"))) PPC_WEAK_FUNC(sub_82613F68);
PPC_FUNC_IMPL(__imp__sub_82613F68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613fb4
	if (cr6.eq) goto loc_82613FB4;
	// lhz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// twllei r11,0
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r5,r9
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82613fb4
	if (cr6.eq) goto loc_82613FB4;
loc_82613F9C:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82613fbc
	if (cr6.eq) goto loc_82613FBC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82613f9c
	if (!cr6.eq) goto loc_82613F9C;
loc_82613FB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82613FBC:
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82613FC4"))) PPC_WEAK_FUNC(sub_82613FC4);
PPC_FUNC_IMPL(__imp__sub_82613FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82613FC8"))) PPC_WEAK_FUNC(sub_82613FC8);
PPC_FUNC_IMPL(__imp__sub_82613FC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// sth r4,126(r1)
	PPC_STORE_U16(ctx.r1.u32 + 126, ctx.r4.u16);
	// addi r4,r1,126
	ctx.r4.s64 = ctx.r1.s64 + 126;
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x82613f68
	ctx.lr = 0x82613FEC;
	sub_82613F68(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82614008
	if (cr6.eq) goto loc_82614008;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82614008
	if (cr6.eq) goto loc_82614008;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82615520
	ctx.lr = 0x82614008;
	sub_82615520(ctx, base);
loc_82614008:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261401C"))) PPC_WEAK_FUNC(sub_8261401C);
PPC_FUNC_IMPL(__imp__sub_8261401C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82614020"))) PPC_WEAK_FUNC(sub_82614020);
PPC_FUNC_IMPL(__imp__sub_82614020) {
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
	ctx.lr = 0x82614028;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r29,0
	r29.s64 = 0;
	// addi r9,r11,-25996
	ctx.r9.s64 = r11.s64 + -25996;
	// lhz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 16);
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82614084
	if (cr6.eq) goto loc_82614084;
	// li r31,0
	r31.s64 = 0;
loc_82614050:
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwzx r30,r11,r31
	r30.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82614070
	if (cr6.eq) goto loc_82614070;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82615390
	ctx.lr = 0x82614068;
	sub_82615390(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82614070;
	sub_82130588(ctx, base);
loc_82614070:
	// lhz r11,16(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 16);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82614050
	if (cr6.lt) goto loc_82614050;
loc_82614084:
	// lhz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 24);
	// addi r29,r28,20
	r29.s64 = r28.s64 + 20;
	// li r30,0
	r30.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826140bc
	if (!cr6.gt) goto loc_826140BC;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_826140A0:
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826140bc
	if (!cr6.eq) goto loc_826140BC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x826140a0
	if (cr6.lt) goto loc_826140A0;
loc_826140BC:
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826140ec
	if (!cr6.gt) goto loc_826140EC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_826140CC:
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826140f4
	if (!cr6.eq) goto loc_826140F4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x826140cc
	if (cr6.lt) goto loc_826140CC;
	// b 0x8261415c
	goto loc_8261415C;
loc_826140EC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8261415c
	if (cr6.eq) goto loc_8261415C;
loc_826140F4:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82614114
	if (cr6.eq) goto loc_82614114;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82614114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82614114:
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826140f4
	if (!cr6.eq) goto loc_826140F4;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_8261412C:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82614154
	if (!cr6.lt) goto loc_82614154;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r30,r11,r8
	r30.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8261412c
	if (cr6.eq) goto loc_8261412C;
	// b 0x826140f4
	goto loc_826140F4;
loc_82614154:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826140f4
	if (!cr6.eq) goto loc_826140F4;
loc_8261415C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82608de8
	ctx.lr = 0x82614164;
	sub_82608DE8(ctx, base);
	// lhz r11,18(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614178
	if (cr6.eq) goto loc_82614178;
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82614178;
	sub_82130588(ctx, base);
loc_82614178:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,-25308
	ctx.r10.s64 = r11.s64 + -25308;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x821d2810
	ctx.lr = 0x8261418C;
	sub_821D2810(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82614194"))) PPC_WEAK_FUNC(sub_82614194);
PPC_FUNC_IMPL(__imp__sub_82614194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82614198"))) PPC_WEAK_FUNC(sub_82614198);
PPC_FUNC_IMPL(__imp__sub_82614198) {
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
	ctx.lr = 0x826141A0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826141c8
	if (cr6.eq) goto loc_826141C8;
	// bl 0x8217d890
	ctx.lr = 0x826141BC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_826141C8:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614258
	if (cr6.eq) goto loc_82614258;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_826141E8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82614240
	if (cr6.eq) goto loc_82614240;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82614240
	if (cr6.eq) goto loc_82614240;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82614214;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82614240
	if (cr6.eq) goto loc_82614240;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82614228;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x826154d8
	ctx.lr = 0x8261423C;
	sub_826154D8(ctx, base);
	// b 0x82614244
	goto loc_82614244;
loc_82614240:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82614244:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x826141e8
	if (cr6.lt) goto loc_826141E8;
loc_82614258:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82614264"))) PPC_WEAK_FUNC(sub_82614264);
PPC_FUNC_IMPL(__imp__sub_82614264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82614268"))) PPC_WEAK_FUNC(sub_82614268);
PPC_FUNC_IMPL(__imp__sub_82614268) {
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
	// bl 0x82614020
	ctx.lr = 0x82614288;
	sub_82614020(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826142a0
	if (cr6.eq) goto loc_826142A0;
	// bl 0x82130588
	ctx.lr = 0x8261429C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826142A0:
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

__attribute__((alias("__imp__sub_826142B8"))) PPC_WEAK_FUNC(sub_826142B8);
PPC_FUNC_IMPL(__imp__sub_826142B8) {
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
	ctx.lr = 0x826142C0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x826142D0;
	sub_821D2970(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,-25996
	ctx.r10.s64 = r11.s64 + -25996;
	// addi r3,r23,12
	ctx.r3.s64 = r23.s64 + 12;
	// stw r10,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82614198
	ctx.lr = 0x826142EC;
	sub_82614198(ctx, base);
	// addi r31,r23,20
	r31.s64 = r23.s64 + 20;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee798
	ctx.lr = 0x82614304;
	sub_825EE798(ctx, base);
	// li r22,0
	r22.s64 = 0;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// bl 0x82237920
	ctx.lr = 0x8261431C;
	sub_82237920(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82237920
	ctx.lr = 0x82614324;
	sub_82237920(ctx, base);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826143e8
	if (cr6.eq) goto loc_826143E8;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r24,60
	r24.s64 = 60;
	// lwz r26,88(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r28,80(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82614340:
	// lwzx r30,r24,r25
	r30.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82614394
	if (cr6.eq) goto loc_82614394;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82614394
	if (cr6.eq) goto loc_82614394;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82614368;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82614394
	if (cr6.eq) goto loc_82614394;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8261437C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r24,r25
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + r25.u32);
	// bl 0x826155f8
	ctx.lr = 0x82614390;
	sub_826155F8(ctx, base);
	// b 0x82614398
	goto loc_82614398;
loc_82614394:
	// stw r22,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r22.u32);
loc_82614398:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826143e8
	if (cr6.eq) goto loc_826143E8;
	// lwz r29,8(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82614340
	if (!cr6.eq) goto loc_82614340;
	// lhz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
loc_826143B8:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x826143e0
	if (!cr6.lt) goto loc_826143E0;
	// lwz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r29,r11,r8
	r29.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826143b8
	if (cr6.eq) goto loc_826143B8;
	// b 0x82614340
	goto loc_82614340;
loc_826143E0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82614340
	if (!cr6.eq) goto loc_82614340;
loc_826143E8:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_826143F4"))) PPC_WEAK_FUNC(sub_826143F4);
PPC_FUNC_IMPL(__imp__sub_826143F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826143F8"))) PPC_WEAK_FUNC(sub_826143F8);
PPC_FUNC_IMPL(__imp__sub_826143F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x826142b8
	sub_826142B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82614404"))) PPC_WEAK_FUNC(sub_82614404);
PPC_FUNC_IMPL(__imp__sub_82614404) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82614408"))) PPC_WEAK_FUNC(sub_82614408);
PPC_FUNC_IMPL(__imp__sub_82614408) {
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
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x821c2f70
	ctx.lr = 0x82614424;
	sub_821C2F70(ctx, base);
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

__attribute__((alias("__imp__sub_8261443C"))) PPC_WEAK_FUNC(sub_8261443C);
PPC_FUNC_IMPL(__imp__sub_8261443C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82614440"))) PPC_WEAK_FUNC(sub_82614440);
PPC_FUNC_IMPL(__imp__sub_82614440) {
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
	ctx.lr = 0x82614448;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r6,288(r1)
	PPC_STORE_U64(ctx.r1.u32 + 288, ctx.r6.u64);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// std r7,296(r1)
	PPC_STORE_U64(ctx.r1.u32 + 296, ctx.r7.u64);
	// li r5,128
	ctx.r5.s64 = 128;
	// std r8,304(r1)
	PPC_STORE_U64(ctx.r1.u32 + 304, ctx.r8.u64);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// bl 0x82183870
	ctx.lr = 0x82614470;
	sub_82183870(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// ori r10,r11,53712
	ctx.r10.u64 = r11.u64 | 53712;
	// lwzx r6,r31,r10
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x826144e4
	if (!cr6.gt) goto loc_826144E4;
	// addi r7,r31,8
	ctx.r7.s64 = r31.s64 + 8;
loc_8261448C:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_82614494:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x826144b8
	if (cr6.eq) goto loc_826144B8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82614494
	if (cr6.eq) goto loc_82614494;
loc_826144B8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826144d4
	if (cr6.eq) goto loc_826144D4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,3836
	ctx.r7.s64 = ctx.r7.s64 + 3836;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8261448c
	if (cr6.lt) goto loc_8261448C;
	// b 0x826144e4
	goto loc_826144E4;
loc_826144D4:
	// mulli r11,r8,3836
	r11.s64 = ctx.r8.s64 * 3836;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addic. r11,r11,8
	xer.ca = r11.u32 > 4294967287;
	r11.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82614530
	if (!cr0.eq) goto loc_82614530;
loc_826144E4:
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addis r6,r11,1
	ctx.r6.s64 = r11.s64 + 65536;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r6,r6,-11832
	ctx.r6.s64 = ctx.r6.s64 + -11832;
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mulli r8,r9,3836
	ctx.r8.s64 = ctx.r9.s64 * 3836;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// subf r9,r7,r11
	ctx.r9.s64 = r11.s64 - ctx.r7.s64;
loc_82614510:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stbx r8,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bne cr6,0x82614510
	if (!cr6.eq) goto loc_82614510;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r29,128(r11)
	PPC_STORE_U8(r11.u32 + 128, r29.u8);
	// stb r10,129(r11)
	PPC_STORE_U8(r11.u32 + 129, ctx.r10.u8);
loc_82614530:
	// lwz r10,3832(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 3832);
	// addi r9,r11,132
	ctx.r9.s64 = r11.s64 + 132;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// mulli r10,r10,148
	ctx.r10.s64 = ctx.r10.s64 * 148;
	// stw r8,3832(r11)
	PPC_STORE_U32(r11.u32 + 3832, ctx.r8.u32);
	// add r31,r10,r9
	r31.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82183870
	ctx.lr = 0x82614558;
	sub_82183870(ctx, base);
	// addi r10,r31,128
	ctx.r10.s64 = r31.s64 + 128;
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82614568:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82614568
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82614568;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82614584"))) PPC_WEAK_FUNC(sub_82614584);
PPC_FUNC_IMPL(__imp__sub_82614584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82614588"))) PPC_WEAK_FUNC(sub_82614588);
PPC_FUNC_IMPL(__imp__sub_82614588) {
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
	ctx.lr = 0x82614590;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addis r17,r19,1
	r17.s64 = r19.s64 + 65536;
	// addi r17,r17,-11824
	r17.s64 = r17.s64 + -11824;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82614a04
	if (cr6.eq) goto loc_82614A04;
	// li r20,0
	r20.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r20.u32);
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// stw r20,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r20.u32);
	// ble cr6,0x826145e4
	if (!cr6.gt) goto loc_826145E4;
	// addi r11,r19,137
	r11.s64 = r19.s64 + 137;
loc_826145CC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r20,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r20.u8);
	// lwz r9,0(r17)
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// addi r11,r11,3836
	r11.s64 = r11.s64 + 3836;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826145cc
	if (cr6.lt) goto loc_826145CC;
loc_826145E4:
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// clrlwi r16,r5,24
	r16.u64 = ctx.r5.u32 & 0xFF;
	// addi r18,r9,-25940
	r18.s64 = ctx.r9.s64 + -25940;
	// addi r21,r8,-25984
	r21.s64 = ctx.r8.s64 + -25984;
	// addi r24,r7,11856
	r24.s64 = ctx.r7.s64 + 11856;
	// addi r23,r6,-25064
	r23.s64 = ctx.r6.s64 + -25064;
	// addi r22,r10,-29624
	r22.s64 = ctx.r10.s64 + -29624;
	// addi r25,r11,-29628
	r25.s64 = r11.s64 + -29628;
loc_82614618:
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x8261463c
	if (cr6.eq) goto loc_8261463C;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82614630;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82614a04
	if (!cr6.eq) goto loc_82614A04;
loc_8261463C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82614658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82614a04
	if (cr6.eq) goto loc_82614A04;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82183870
	ctx.lr = 0x82614670;
	sub_82183870(ctx, base);
	// lwz r6,0(r17)
	ctx.r6.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r30,r20
	r30.u64 = r20.u64;
	// mr r8,r20
	ctx.r8.u64 = r20.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x826146dc
	if (!cr6.gt) goto loc_826146DC;
	// addi r7,r19,8
	ctx.r7.s64 = r19.s64 + 8;
loc_82614688:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_82614690:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x826146b4
	if (cr6.eq) goto loc_826146B4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82614690
	if (cr6.eq) goto loc_82614690;
loc_826146B4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826146d0
	if (cr6.eq) goto loc_826146D0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,3836
	ctx.r7.s64 = ctx.r7.s64 + 3836;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x82614688
	if (cr6.lt) goto loc_82614688;
	// b 0x826146dc
	goto loc_826146DC;
loc_826146D0:
	// mulli r11,r8,3836
	r11.s64 = ctx.r8.s64 * 3836;
	// add r11,r11,r19
	r11.u64 = r11.u64 + r19.u64;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
loc_826146DC:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x826146EC;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r26,r9,1
	r26.u64 = ctx.r9.u64 ^ 1;
	// beq cr6,0x8261494c
	if (cr6.eq) goto loc_8261494C;
	// lbz r11,128(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 128);
	// mr r28,r20
	r28.u64 = r20.u64;
	// mr r31,r20
	r31.u64 = r20.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,129(r30)
	PPC_STORE_U8(r30.u32 + 129, ctx.r9.u8);
	// bne cr6,0x82614728
	if (!cr6.eq) goto loc_82614728;
	// li r31,1
	r31.s64 = 1;
loc_82614728:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82614738;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82614930
	if (!cr6.eq) goto loc_82614930;
	// clrlwi r27,r31,24
	r27.u64 = r31.u32 & 0xFF;
loc_82614748:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8261475c
	if (cr6.eq) goto loc_8261475C;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82614930
	if (!cr6.eq) goto loc_82614930;
loc_8261475C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82614778;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82614930
	if (cr6.eq) goto loc_82614930;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r28,1
	r28.s64 = 1;
	// bl 0x82183870
	ctx.lr = 0x82614794;
	sub_82183870(ctx, base);
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_8261479C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826147c0
	if (cr6.eq) goto loc_826147C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8261479c
	if (cr6.eq) goto loc_8261479C;
loc_826147C0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82614930
	if (cr6.eq) goto loc_82614930;
	// lwz r11,3832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3832);
	// mr r31,r20
	r31.u64 = r20.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8261487c
	if (!cr6.gt) goto loc_8261487C;
	// addi r8,r30,132
	ctx.r8.s64 = r30.s64 + 132;
loc_826147DC:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826147E4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82614808
	if (cr6.eq) goto loc_82614808;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826147e4
	if (cr6.eq) goto loc_826147E4;
loc_82614808:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8261485c
	if (cr6.eq) goto loc_8261485C;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82614818:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x8261483c
	if (cr6.eq) goto loc_8261483C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82614818
	if (cr6.eq) goto loc_82614818;
loc_8261483C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8261485c
	if (cr6.eq) goto loc_8261485C;
	// lwz r11,3832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3832);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r8,r8,148
	ctx.r8.s64 = ctx.r8.s64 + 148;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x826147dc
	if (cr6.lt) goto loc_826147DC;
	// b 0x8261487c
	goto loc_8261487C;
loc_8261485C:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// mulli r11,r31,148
	r11.s64 = r31.s64 * 148;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,260
	ctx.r3.s64 = r11.s64 + 260;
	// bl 0x821c3048
	ctx.lr = 0x8261487C;
	sub_821C3048(ctx, base);
loc_8261487C:
	// lwz r11,3832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3832);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bne cr6,0x82614914
	if (!cr6.eq) goto loc_82614914;
	// lbz r11,4(r19)
	r11.u64 = PPC_LOAD_U8(r19.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826148a4
	if (cr6.eq) goto loc_826148A4;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82130000
	ctx.lr = 0x826148A4;
	sub_82130000(ctx, base);
loc_826148A4:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x826148B4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614914
	if (cr6.eq) goto loc_82614914;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x826148D0;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82614914
	if (!cr6.eq) goto loc_82614914;
loc_826148DC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826148F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82614908;
	sub_821CFE80(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826148dc
	if (cr6.eq) goto loc_826148DC;
loc_82614914:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82614924;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614748
	if (cr6.eq) goto loc_82614748;
loc_82614930:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82614618
	if (!cr6.gt) goto loc_82614618;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x82614948;
	sub_821CFE80(ctx, base);
	// b 0x82614618
	goto loc_82614618;
loc_8261494C:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x8261495C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82614984
	if (!cr6.eq) goto loc_82614984;
	// lbz r11,4(r19)
	r11.u64 = PPC_LOAD_U8(r19.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614984
	if (cr6.eq) goto loc_82614984;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82130000
	ctx.lr = 0x82614984;
	sub_82130000(ctx, base);
loc_82614984:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x82614618
	if (cr6.eq) goto loc_82614618;
loc_8261498C:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x8261499C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826149b0
	if (cr6.eq) goto loc_826149B0;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// b 0x826149f8
	goto loc_826149F8;
loc_826149B0:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cfe80
	ctx.lr = 0x826149C0;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826149d4
	if (cr6.eq) goto loc_826149D4;
	// addi r26,r26,-1
	r26.s64 = r26.s64 + -1;
	// b 0x826149f8
	goto loc_826149F8;
loc_826149D4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826149F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82614618
	if (cr6.eq) goto loc_82614618;
loc_826149F8:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x8261498c
	if (!cr6.eq) goto loc_8261498C;
	// b 0x82614618
	goto loc_82614618;
loc_82614A04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82614A10"))) PPC_WEAK_FUNC(sub_82614A10);
PPC_FUNC_IMPL(__imp__sub_82614A10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addis r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 65536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r9,r9,-11824
	ctx.r9.s64 = ctx.r9.s64 + -11824;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82614a48
	if (!cr6.gt) goto loc_82614A48;
	// addi r10,r3,3840
	ctx.r10.s64 = ctx.r3.s64 + 3840;
loc_82614A30:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r10,3836
	ctx.r10.s64 = ctx.r10.s64 + 3836;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82614a30
	if (cr6.lt) goto loc_82614A30;
loc_82614A48:
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82614A50"))) PPC_WEAK_FUNC(sub_82614A50);
PPC_FUNC_IMPL(__imp__sub_82614A50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,-25888
	ctx.r10.s64 = r11.s64 + -25888;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82614A60"))) PPC_WEAK_FUNC(sub_82614A60);
PPC_FUNC_IMPL(__imp__sub_82614A60) {
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
	ctx.lr = 0x82614A68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,13
	r30.s64 = 13;
	// addi r31,r28,132
	r31.s64 = r28.s64 + 132;
	// li r29,0
	r29.s64 = 0;
loc_82614A7C:
	// lis r11,-32159
	r11.s64 = -2107572224;
	// li r5,25
	ctx.r5.s64 = 25;
	// addi r6,r11,17416
	ctx.r6.s64 = r11.s64 + 17416;
	// li r4,148
	ctx.r4.s64 = 148;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821305f0
	ctx.lr = 0x82614A94;
	sub_821305F0(ctx, base);
	// stw r29,3700(r31)
	PPC_STORE_U32(r31.u32 + 3700, r29.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,3836
	r31.s64 = r31.s64 + 3836;
	// bge 0x82614a7c
	if (!cr0.lt) goto loc_82614A7C;
	// lis r11,0
	r11.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// ori r10,r11,53704
	ctx.r10.u64 = r11.u64 | 53704;
	// stwx r29,r28,r10
	PPC_STORE_U32(r28.u32 + ctx.r10.u32, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82614ABC"))) PPC_WEAK_FUNC(sub_82614ABC);
PPC_FUNC_IMPL(__imp__sub_82614ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82614AC0"))) PPC_WEAK_FUNC(sub_82614AC0);
PPC_FUNC_IMPL(__imp__sub_82614AC0) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-25888
	ctx.r10.s64 = r11.s64 + -25888;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82614a60
	ctx.lr = 0x82614AE8;
	sub_82614A60(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r9,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_82614B08"))) PPC_WEAK_FUNC(sub_82614B08);
PPC_FUNC_IMPL(__imp__sub_82614B08) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-25888
	ctx.r10.s64 = r11.s64 + -25888;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82614B34;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82614b4c
	if (cr6.eq) goto loc_82614B4C;
	// bl 0x82130588
	ctx.lr = 0x82614B48;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82614B4C:
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

__attribute__((alias("__imp__sub_82614B64"))) PPC_WEAK_FUNC(sub_82614B64);
PPC_FUNC_IMPL(__imp__sub_82614B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82614B68"))) PPC_WEAK_FUNC(sub_82614B68);
PPC_FUNC_IMPL(__imp__sub_82614B68) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82614B84;
	sub_82130588(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82614B8C;
	sub_82130588(ctx, base);
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

__attribute__((alias("__imp__sub_82614BA0"))) PPC_WEAK_FUNC(sub_82614BA0);
PPC_FUNC_IMPL(__imp__sub_82614BA0) {
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
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82614bdc
	if (cr6.eq) goto loc_82614BDC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82614BD0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82614BDC:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82614bfc
	if (cr6.eq) goto loc_82614BFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82614BF0;
	sub_8217D890(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_82614BFC:
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

__attribute__((alias("__imp__sub_82614C18"))) PPC_WEAK_FUNC(sub_82614C18);
PPC_FUNC_IMPL(__imp__sub_82614C18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82614ba0
	sub_82614BA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82614C24"))) PPC_WEAK_FUNC(sub_82614C24);
PPC_FUNC_IMPL(__imp__sub_82614C24) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82614C28"))) PPC_WEAK_FUNC(sub_82614C28);
PPC_FUNC_IMPL(__imp__sub_82614C28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,1
	r11.s64 = 1;
	// stb r11,21792(r10)
	PPC_STORE_U8(ctx.r10.u32 + 21792, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82614C38"))) PPC_WEAK_FUNC(sub_82614C38);
PPC_FUNC_IMPL(__imp__sub_82614C38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// lis r3,-32112
	ctx.r3.s64 = -2104492032;
	// lwz r11,21808(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 21808);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,21788(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 21788);
	// lwz r8,21804(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 21804);
	// stw r9,21808(r7)
	PPC_STORE_U32(ctx.r7.u32 + 21808, ctx.r9.u32);
	// stw r11,21800(r4)
	PPC_STORE_U32(ctx.r4.u32 + 21800, r11.u32);
	// stw r10,21780(r3)
	PPC_STORE_U32(ctx.r3.u32 + 21780, ctx.r10.u32);
	// stw r8,21788(r6)
	PPC_STORE_U32(ctx.r6.u32 + 21788, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82614C70"))) PPC_WEAK_FUNC(sub_82614C70);
PPC_FUNC_IMPL(__imp__sub_82614C70) {
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
	ctx.lr = 0x82614C78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x8275cc50
	ctx.lr = 0x82614C8C;
	sub_8275CC50(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r31,r11,22328
	r31.s64 = r11.s64 + 22328;
	// bne cr6,0x82614cfc
	if (!cr6.eq) goto loc_82614CFC;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r28,128
	r28.s64 = 128;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,20560
	r30.s64 = r11.s64 + 20560;
loc_82614CAC:
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lbzx r11,r10,r30
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r30.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82614ce4
	if (cr6.eq) goto loc_82614CE4;
	// lhz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82614cd4
	if (cr6.eq) goto loc_82614CD4;
	// stbx r28,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, r28.u8);
	// b 0x82614ce4
	goto loc_82614CE4;
loc_82614CD4:
	// rlwinm r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82614ce4
	if (cr6.eq) goto loc_82614CE4;
	// stbx r29,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, r29.u8);
loc_82614CE4:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x8275cc50
	ctx.lr = 0x82614CF4;
	sub_8275CC50(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82614cac
	if (cr6.eq) goto loc_82614CAC;
loc_82614CFC:
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r10,r11,21816
	ctx.r10.s64 = r11.s64 + 21816;
	// li r5,256
	ctx.r5.s64 = 256;
	// lwz r11,22584(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22584);
	// xori r31,r11,1
	r31.u64 = r11.u64 ^ 1;
	// rlwinm r11,r31,8,0,23
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFFFFFF00;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x823da950
	ctx.lr = 0x82614D24;
	sub_823DA950(ctx, base);
	// stw r31,22584(r30)
	PPC_STORE_U32(r30.u32 + 22584, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82614D30"))) PPC_WEAK_FUNC(sub_82614D30);
PPC_FUNC_IMPL(__imp__sub_82614D30) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82614D38;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8260b668
	ctx.lr = 0x82614D44;
	sub_8260B668(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r10,r11,21384
	ctx.r10.s64 = r11.s64 + 21384;
	// subf r9,r10,r31
	ctx.r9.s64 = r31.s64 - ctx.r10.s64;
	// srawi r29,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	r29.s64 = ctx.r9.s32 >> 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8275cb78
	ctx.lr = 0x82614D60;
	sub_8275CB78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82614d78
	if (cr6.eq) goto loc_82614D78;
	// li r11,0
	r11.s64 = 0;
	// stb r11,44(r31)
	PPC_STORE_U8(r31.u32 + 44, r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
loc_82614D78:
	// li r30,1
	r30.s64 = 1;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stb r30,44(r31)
	PPC_STORE_U8(r31.u32 + 44, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8275cb70
	ctx.lr = 0x82614D90;
	sub_8275CB70(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82614e20
	if (!cr6.eq) goto loc_82614E20;
	// lbz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x82614e20
	if (!cr6.eq) goto loc_82614E20;
	// lbz r11,113(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 113);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x82614e14
	if (cr6.gt) goto loc_82614E14;
	// lis r12,-32159
	r12.s64 = -2107572224;
	// addi r12,r12,19916
	r12.s64 = r12.s64 + 19916;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82614DE4;
	case 1:
		goto loc_82614DFC;
	case 2:
		goto loc_82614E04;
	case 3:
		goto loc_82614DEC;
	case 4:
		goto loc_82614DF4;
	case 5:
		goto loc_82614E0C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,19940(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19940);
	// lwz r19,19964(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19964);
	// lwz r19,19972(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19972);
	// lwz r19,19948(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19948);
	// lwz r19,19956(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19956);
	// lwz r19,19980(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19980);
loc_82614DE4:
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
	// b 0x82614e14
	goto loc_82614E14;
loc_82614DEC:
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// b 0x82614e14
	goto loc_82614E14;
loc_82614DF4:
	// li r11,2
	r11.s64 = 2;
	// b 0x82614e10
	goto loc_82614E10;
loc_82614DFC:
	// li r11,3
	r11.s64 = 3;
	// b 0x82614e10
	goto loc_82614E10;
loc_82614E04:
	// li r11,4
	r11.s64 = 4;
	// b 0x82614e10
	goto loc_82614E10;
loc_82614E0C:
	// li r11,5
	r11.s64 = 5;
loc_82614E10:
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
loc_82614E14:
	// lhz r11,114(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// stb r10,47(r31)
	PPC_STORE_U8(r31.u32 + 47, ctx.r10.u8);
loc_82614E20:
	// lhz r11,104(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// lhz r10,106(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 106);
	// lhz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 108);
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// lhz r7,110(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 110);
	// extsh r6,r10
	ctx.r6.s64 = ctx.r10.s16;
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// lhz r11,100(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// srawi r4,r8,8
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 8;
	// extsh r3,r7
	ctx.r3.s64 = ctx.r7.s16;
	// srawi r10,r6,8
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 8;
	// srawi r7,r5,8
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 8;
	// srawi r6,r3,8
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 8;
	// rlwinm r5,r11,0,19,19
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// addi r9,r4,128
	ctx.r9.s64 = ctx.r4.s64 + 128;
	// not r7,r3
	ctx.r7.u64 = ~ctx.r3.u64;
	// addi r6,r11,128
	ctx.r6.s64 = r11.s64 + 128;
	// stb r9,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r9.u8);
	// not r4,r10
	ctx.r4.u64 = ~ctx.r10.u64;
	// stb r7,17(r31)
	PPC_STORE_U8(r31.u32 + 17, ctx.r7.u8);
	// stb r6,18(r31)
	PPC_STORE_U8(r31.u32 + 18, ctx.r6.u8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stb r4,19(r31)
	PPC_STORE_U8(r31.u32 + 19, ctx.r4.u8);
	// beq cr6,0x82614ea4
	if (cr6.eq) goto loc_82614EA4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82614EA4:
	// rlwinm r11,r8,0,18,18
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614ebc
	if (cr6.eq) goto loc_82614EBC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82614EBC:
	// rlwinm r11,r8,0,17,17
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614ed4
	if (cr6.eq) goto loc_82614ED4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82614ED4:
	// rlwinm r11,r8,0,16,16
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614eec
	if (cr6.eq) goto loc_82614EEC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82614EEC:
	// rlwinm r11,r8,0,23,23
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614f04
	if (cr6.eq) goto loc_82614F04;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82614F04:
	// rlwinm r11,r8,0,22,22
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614f1c
	if (cr6.eq) goto loc_82614F1C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82614F1C:
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// lbz r7,102(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 102);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// lbz r11,20816(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20816);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// subfc r5,r6,r9
	xer.ca = ctx.r9.u32 >= ctx.r6.u32;
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// subfe r9,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// clrlwi r4,r9,24
	ctx.r4.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82614f58
	if (cr6.eq) goto loc_82614F58;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// lbz r11,20816(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20816);
loc_82614F58:
	// lbz r10,103(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 103);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// subfc r6,r11,r9
	xer.ca = ctx.r9.u32 >= r11.u32;
	ctx.r6.s64 = ctx.r9.s64 - r11.s64;
	// subfe r11,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82614f88
	if (cr6.eq) goto loc_82614F88;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,2
	ctx.r9.u64 = r11.u64 | 2;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82614F88:
	// rlwinm r11,r8,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614fa0
	if (cr6.eq) goto loc_82614FA0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,2048
	ctx.r9.u64 = r11.u64 | 2048;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82614FA0:
	// rlwinm r11,r8,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614fb8
	if (cr6.eq) goto loc_82614FB8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,256
	ctx.r9.u64 = r11.u64 | 256;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82614FB8:
	// rlwinm r11,r8,0,25,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614fd0
	if (cr6.eq) goto loc_82614FD0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,512
	ctx.r9.u64 = r11.u64 | 512;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82614FD0:
	// rlwinm r11,r8,0,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82614fe8
	if (cr6.eq) goto loc_82614FE8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,1024
	ctx.r9.u64 = r11.u64 | 1024;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82614FE8:
	// clrlwi r11,r8,31
	r11.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615000
	if (cr6.eq) goto loc_82615000;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,4096
	ctx.r9.u64 = r11.u64 | 4096;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82615000:
	// rlwinm r11,r8,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615018
	if (cr6.eq) goto loc_82615018;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,16384
	ctx.r9.u64 = r11.u64 | 16384;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82615018:
	// rlwinm r11,r8,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615030
	if (cr6.eq) goto loc_82615030;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,32768
	ctx.r9.u64 = r11.u64 | 32768;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82615030:
	// rlwinm r11,r8,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615048
	if (cr6.eq) goto loc_82615048;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r11,8192
	ctx.r9.u64 = r11.u64 | 8192;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
loc_82615048:
	// lbz r11,46(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 46);
	// stb r7,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r7.u8);
	// stb r10,21(r31)
	PPC_STORE_U8(r31.u32 + 21, ctx.r10.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826150b4
	if (cr6.eq) goto loc_826150B4;
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826150b4
	if (cr6.eq) goto loc_826150B4;
	// lbz r10,45(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 45);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8261507c
	if (cr6.eq) goto loc_8261507C;
	// lhz r11,58(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// b 0x82615080
	goto loc_82615080;
loc_8261507C:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82615080:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
	// beq cr6,0x82615094
	if (cr6.eq) goto loc_82615094;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// b 0x82615098
	goto loc_82615098;
loc_82615094:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82615098:
	// sth r11,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, r11.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8275cb88
	ctx.lr = 0x826150A8;
	sub_8275CB88(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826150b4
	if (!cr6.eq) goto loc_826150B4;
	// stb r28,46(r31)
	PPC_STORE_U8(r31.u32 + 46, r28.u8);
loc_826150B4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826150BC"))) PPC_WEAK_FUNC(sub_826150BC);
PPC_FUNC_IMPL(__imp__sub_826150BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826150C0"))) PPC_WEAK_FUNC(sub_826150C0);
PPC_FUNC_IMPL(__imp__sub_826150C0) {
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
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x824501e0
	ctx.lr = 0x826150D4;
	sub_824501E0(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// stw r3,22588(r11)
	PPC_STORE_U32(r11.u32 + 22588, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826150EC"))) PPC_WEAK_FUNC(sub_826150EC);
PPC_FUNC_IMPL(__imp__sub_826150EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826150F0"))) PPC_WEAK_FUNC(sub_826150F0);
PPC_FUNC_IMPL(__imp__sub_826150F0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,22588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 22588);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82615144
	if (cr6.eq) goto loc_82615144;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x827bd054
	ctx.lr = 0x82615124;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82615144
	if (cr6.eq) goto loc_82615144;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// stb r11,21380(r10)
	PPC_STORE_U8(ctx.r10.u32 + 21380, r11.u8);
loc_82615144:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r30,r11,21384
	r30.s64 = r11.s64 + 21384;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_82615150:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82614d30
	ctx.lr = 0x82615158;
	sub_82614D30(ctx, base);
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// addi r11,r30,256
	r11.s64 = r30.s64 + 256;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82615150
	if (cr6.lt) goto loc_82615150;
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

__attribute__((alias("__imp__sub_82615180"))) PPC_WEAK_FUNC(sub_82615180);
PPC_FUNC_IMPL(__imp__sub_82615180) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,22588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 22588);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8244eee0
	sub_8244EEE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82615194"))) PPC_WEAK_FUNC(sub_82615194);
PPC_FUNC_IMPL(__imp__sub_82615194) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82615198"))) PPC_WEAK_FUNC(sub_82615198);
PPC_FUNC_IMPL(__imp__sub_82615198) {
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
	ctx.lr = 0x826151A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,140(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826151dc
	if (cr6.eq) goto loc_826151DC;
	// li r31,0
	r31.s64 = 0;
loc_826151BC:
	// lwz r11,136(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82615680
	ctx.lr = 0x826151C8;
	sub_82615680(ctx, base);
	// lhz r10,140(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x826151bc
	if (cr6.lt) goto loc_826151BC;
loc_826151DC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826151E4"))) PPC_WEAK_FUNC(sub_826151E4);
PPC_FUNC_IMPL(__imp__sub_826151E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826151E8"))) PPC_WEAK_FUNC(sub_826151E8);
PPC_FUNC_IMPL(__imp__sub_826151E8) {
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
	ctx.lr = 0x826151F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,140(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261522c
	if (cr6.eq) goto loc_8261522C;
	// li r31,0
	r31.s64 = 0;
loc_8261520C:
	// lwz r11,136(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x826156c8
	ctx.lr = 0x82615218;
	sub_826156C8(ctx, base);
	// lhz r10,140(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x8261520c
	if (cr6.lt) goto loc_8261520C;
loc_8261522C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82615234"))) PPC_WEAK_FUNC(sub_82615234);
PPC_FUNC_IMPL(__imp__sub_82615234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615238"))) PPC_WEAK_FUNC(sub_82615238);
PPC_FUNC_IMPL(__imp__sub_82615238) {
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
	ctx.lr = 0x82615240;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,140(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261527c
	if (cr6.eq) goto loc_8261527C;
	// li r31,0
	r31.s64 = 0;
loc_8261525C:
	// lwz r11,136(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82615710
	ctx.lr = 0x82615268;
	sub_82615710(ctx, base);
	// lhz r10,140(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x8261525c
	if (cr6.lt) goto loc_8261525C;
loc_8261527C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82615284"))) PPC_WEAK_FUNC(sub_82615284);
PPC_FUNC_IMPL(__imp__sub_82615284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615288"))) PPC_WEAK_FUNC(sub_82615288);
PPC_FUNC_IMPL(__imp__sub_82615288) {
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
	ctx.lr = 0x82615290;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,140(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826152cc
	if (cr6.eq) goto loc_826152CC;
	// li r31,0
	r31.s64 = 0;
loc_826152AC:
	// lwz r11,136(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82615620
	ctx.lr = 0x826152B8;
	sub_82615620(ctx, base);
	// lhz r10,140(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x826152ac
	if (cr6.lt) goto loc_826152AC;
loc_826152CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826152D4"))) PPC_WEAK_FUNC(sub_826152D4);
PPC_FUNC_IMPL(__imp__sub_826152D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826152D8"))) PPC_WEAK_FUNC(sub_826152D8);
PPC_FUNC_IMPL(__imp__sub_826152D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// lhz r7,140(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 140);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// li r10,0
	ctx.r10.s64 = 0;
loc_826152F4:
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r9,136(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 136);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// lwzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lhz r5,108(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 108);
	// subfic r4,r5,0
	xer.ca = ctx.r5.u32 <= 0;
	ctx.r4.s64 = 0 - ctx.r5.s64;
	// subfe r3,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + xer.ca < xer.ca);
	ctx.r3.u64 = ~ctx.r4.u64 + ctx.r4.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r3,31
	ctx.r3.u64 = ctx.r3.u32 & 0x1;
	// blt cr6,0x826152f4
	if (cr6.lt) goto loc_826152F4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261532C"))) PPC_WEAK_FUNC(sub_8261532C);
PPC_FUNC_IMPL(__imp__sub_8261532C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615330"))) PPC_WEAK_FUNC(sub_82615330);
PPC_FUNC_IMPL(__imp__sub_82615330) {
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
	ctx.lr = 0x82615338;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,140(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615384
	if (cr6.eq) goto loc_82615384;
	// li r31,0
	r31.s64 = 0;
loc_82615358:
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x821a8aa0
	ctx.lr = 0x82615364;
	sub_821A8AA0(ctx, base);
	// cmplw cr6,r29,r3
	cr6.compare<uint32_t>(r29.u32, ctx.r3.u32, xer);
	// bgt cr6,0x82615370
	if (cr6.gt) goto loc_82615370;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_82615370:
	// lhz r11,140(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 140);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82615358
	if (cr6.lt) goto loc_82615358;
loc_82615384:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82615390"))) PPC_WEAK_FUNC(sub_82615390);
PPC_FUNC_IMPL(__imp__sub_82615390) {
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
	ctx.lr = 0x82615398;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,140(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826153e8
	if (cr6.eq) goto loc_826153E8;
	// li r31,0
	r31.s64 = 0;
loc_826153B4:
	// lwz r11,136(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// lwzx r30,r11,r31
	r30.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826153d4
	if (cr6.eq) goto loc_826153D4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82615868
	ctx.lr = 0x826153CC;
	sub_82615868(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x826153D4;
	sub_82130588(ctx, base);
loc_826153D4:
	// lhz r11,140(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 140);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x826153b4
	if (cr6.lt) goto loc_826153B4;
loc_826153E8:
	// lhz r11,142(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 142);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826153fc
	if (cr6.eq) goto loc_826153FC;
	// lwz r3,136(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// bl 0x82130588
	ctx.lr = 0x826153FC;
	sub_82130588(ctx, base);
loc_826153FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82615404"))) PPC_WEAK_FUNC(sub_82615404);
PPC_FUNC_IMPL(__imp__sub_82615404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615408"))) PPC_WEAK_FUNC(sub_82615408);
PPC_FUNC_IMPL(__imp__sub_82615408) {
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
	ctx.lr = 0x82615410;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82615438
	if (cr6.eq) goto loc_82615438;
	// bl 0x8217d890
	ctx.lr = 0x8261542C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82615438:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826154c8
	if (cr6.eq) goto loc_826154C8;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_82615458:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826154b0
	if (cr6.eq) goto loc_826154B0;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826154b0
	if (cr6.eq) goto loc_826154B0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82615484;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826154b0
	if (cr6.eq) goto loc_826154B0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82615498;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x82615c88
	ctx.lr = 0x826154AC;
	sub_82615C88(ctx, base);
	// b 0x826154b4
	goto loc_826154B4;
loc_826154B0:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_826154B4:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82615458
	if (cr6.lt) goto loc_82615458;
loc_826154C8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826154D4"))) PPC_WEAK_FUNC(sub_826154D4);
PPC_FUNC_IMPL(__imp__sub_826154D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826154D8"))) PPC_WEAK_FUNC(sub_826154D8);
PPC_FUNC_IMPL(__imp__sub_826154D8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82615508
	if (cr6.eq) goto loc_82615508;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r31,136
	ctx.r3.s64 = r31.s64 + 136;
	// bl 0x82615408
	ctx.lr = 0x82615500;
	sub_82615408(ctx, base);
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x821b5a60
	ctx.lr = 0x82615508;
	sub_821B5A60(ctx, base);
loc_82615508:
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

__attribute__((alias("__imp__sub_8261551C"))) PPC_WEAK_FUNC(sub_8261551C);
PPC_FUNC_IMPL(__imp__sub_8261551C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615520"))) PPC_WEAK_FUNC(sub_82615520);
PPC_FUNC_IMPL(__imp__sub_82615520) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82615528;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,76(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615574
	if (cr6.eq) goto loc_82615574;
	// li r30,0
	r30.s64 = 0;
loc_8261554C:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x826157b8
	ctx.lr = 0x82615560;
	sub_826157B8(ctx, base);
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8261554c
	if (cr6.lt) goto loc_8261554C;
loc_82615574:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82615580"))) PPC_WEAK_FUNC(sub_82615580);
PPC_FUNC_IMPL(__imp__sub_82615580) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-24540
	ctx.r10.s64 = r11.s64 + -24540;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,78(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 78);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826155bc
	if (cr6.eq) goto loc_826155BC;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82130588
	ctx.lr = 0x826155BC;
	sub_82130588(ctx, base);
loc_826155BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x826155C4;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826155dc
	if (cr6.eq) goto loc_826155DC;
	// bl 0x82130588
	ctx.lr = 0x826155D8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826155DC:
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

__attribute__((alias("__imp__sub_826155F4"))) PPC_WEAK_FUNC(sub_826155F4);
PPC_FUNC_IMPL(__imp__sub_826155F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826155F8"))) PPC_WEAK_FUNC(sub_826155F8);
PPC_FUNC_IMPL(__imp__sub_826155F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r10,r11,-24540
	ctx.r10.s64 = r11.s64 + -24540;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// b 0x82249380
	sub_82249380(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82615618"))) PPC_WEAK_FUNC(sub_82615618);
PPC_FUNC_IMPL(__imp__sub_82615618) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261561C"))) PPC_WEAK_FUNC(sub_8261561C);
PPC_FUNC_IMPL(__imp__sub_8261561C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615620"))) PPC_WEAK_FUNC(sub_82615620);
PPC_FUNC_IMPL(__imp__sub_82615620) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r11,108(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 108);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82615650
	if (!cr6.eq) goto loc_82615650;
	// lwz r11,96(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_82615650:
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-21846
	ctx.r10.s64 = -1431699456;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// ori r8,r10,43691
	ctx.r8.u64 = ctx.r10.u64 | 43691;
	// mulhwu r7,r9,r8
	ctx.r7.u64 = (uint64_t(ctx.r9.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r11.u32);
	// rlwinm r11,r7,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// stw r5,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82615680"))) PPC_WEAK_FUNC(sub_82615680);
PPC_FUNC_IMPL(__imp__sub_82615680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r11,108(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 108);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826156C0"))) PPC_WEAK_FUNC(sub_826156C0);
PPC_FUNC_IMPL(__imp__sub_826156C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826156C4"))) PPC_WEAK_FUNC(sub_826156C4);
PPC_FUNC_IMPL(__imp__sub_826156C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826156C8"))) PPC_WEAK_FUNC(sub_826156C8);
PPC_FUNC_IMPL(__imp__sub_826156C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r11,108(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 108);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82615708"))) PPC_WEAK_FUNC(sub_82615708);
PPC_FUNC_IMPL(__imp__sub_82615708) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8261570C"))) PPC_WEAK_FUNC(sub_8261570C);
PPC_FUNC_IMPL(__imp__sub_8261570C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615710"))) PPC_WEAK_FUNC(sub_82615710);
PPC_FUNC_IMPL(__imp__sub_82615710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lhz r11,108(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 108);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826157a4
	if (!cr6.eq) goto loc_826157A4;
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x826157a4
	if (cr6.eq) goto loc_826157A4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821b34f0
	ctx.lr = 0x8261575C;
	sub_821B34F0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821b4260
	ctx.lr = 0x82615764;
	sub_821B4260(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r10,r11,-9216
	ctx.r10.s64 = r11.s64 + -9216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// beq cr6,0x826157a4
	if (cr6.eq) goto loc_826157A4;
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826157a4
	if (cr6.eq) goto loc_826157A4;
	// lbz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826157a4
	if (!cr6.eq) goto loc_826157A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826157A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826157A4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826157B4"))) PPC_WEAK_FUNC(sub_826157B4);
PPC_FUNC_IMPL(__imp__sub_826157B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826157B8"))) PPC_WEAK_FUNC(sub_826157B8);
PPC_FUNC_IMPL(__imp__sub_826157B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r11,108(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 108);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82615834
	if (cr6.eq) goto loc_82615834;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// li r8,0
	ctx.r8.s64 = 0;
loc_826157E0:
	// lwz r11,104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// lwzx r11,r8,r11
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8261581c
	if (cr6.eq) goto loc_8261581C;
	// rlwinm r10,r4,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8261581c
	if (cr6.eq) goto loc_8261581C;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// rlwinm r9,r4,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,9
	ctx.r10.s64 = ctx.r10.s64 + 9;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, temp.u32);
loc_8261581C:
	// lhz r11,108(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 108);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x826157e0
	if (cr6.lt) goto loc_826157E0;
	// blr 
	return;
loc_82615834:
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82615c98
	sub_82615C98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82615864"))) PPC_WEAK_FUNC(sub_82615864);
PPC_FUNC_IMPL(__imp__sub_82615864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615868"))) PPC_WEAK_FUNC(sub_82615868);
PPC_FUNC_IMPL(__imp__sub_82615868) {
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
	ctx.lr = 0x82615870;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826158c0
	if (cr6.eq) goto loc_826158C0;
	// li r30,0
	r30.s64 = 0;
loc_8261588C:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwzx r29,r30,r11
	r29.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826158ac
	if (cr6.eq) goto loc_826158AC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826164d8
	ctx.lr = 0x826158A4;
	sub_826164D8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826158AC;
	sub_82130588(ctx, base);
loc_826158AC:
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8261588c
	if (cr6.lt) goto loc_8261588C;
loc_826158C0:
	// lhz r11,84(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 84);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261590c
	if (cr6.eq) goto loc_8261590C;
	// li r30,0
	r30.s64 = 0;
loc_826158D4:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826158f8
	if (cr6.eq) goto loc_826158F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826158F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826158F8:
	// lhz r11,84(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 84);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826158d4
	if (cr6.lt) goto loc_826158D4;
loc_8261590C:
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x82615914;
	sub_82130588(ctx, base);
	// lhz r11,108(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 108);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615948
	if (cr6.eq) goto loc_82615948;
	// li r30,0
	r30.s64 = 0;
loc_82615928:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82130588
	ctx.lr = 0x82615934;
	sub_82130588(ctx, base);
	// lhz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 108);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82615928
	if (cr6.lt) goto loc_82615928;
loc_82615948:
	// lhz r11,110(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 110);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261595c
	if (cr6.eq) goto loc_8261595C;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x82130588
	ctx.lr = 0x8261595C;
	sub_82130588(ctx, base);
loc_8261595C:
	// lhz r11,86(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615970
	if (cr6.eq) goto loc_82615970;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x82615970;
	sub_82130588(ctx, base);
loc_82615970:
	// lhz r11,74(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 74);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615984
	if (cr6.eq) goto loc_82615984;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82130588
	ctx.lr = 0x82615984;
	sub_82130588(ctx, base);
loc_82615984:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8261598C"))) PPC_WEAK_FUNC(sub_8261598C);
PPC_FUNC_IMPL(__imp__sub_8261598C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615990"))) PPC_WEAK_FUNC(sub_82615990);
PPC_FUNC_IMPL(__imp__sub_82615990) {
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
	ctx.lr = 0x82615998;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826159c0
	if (cr6.eq) goto loc_826159C0;
	// bl 0x8217d890
	ctx.lr = 0x826159B4;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_826159C0:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615a50
	if (cr6.eq) goto loc_82615A50;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_826159E0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82615a38
	if (cr6.eq) goto loc_82615A38;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82615a38
	if (cr6.eq) goto loc_82615A38;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82615A0C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82615a38
	if (cr6.eq) goto loc_82615A38;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82615A20;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x82616550
	ctx.lr = 0x82615A34;
	sub_82616550(ctx, base);
	// b 0x82615a3c
	goto loc_82615A3C;
loc_82615A38:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82615A3C:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x826159e0
	if (cr6.lt) goto loc_826159E0;
loc_82615A50:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82615A5C"))) PPC_WEAK_FUNC(sub_82615A5C);
PPC_FUNC_IMPL(__imp__sub_82615A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615A60"))) PPC_WEAK_FUNC(sub_82615A60);
PPC_FUNC_IMPL(__imp__sub_82615A60) {
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
	ctx.lr = 0x82615A68;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82615a90
	if (cr6.eq) goto loc_82615A90;
	// bl 0x8217d890
	ctx.lr = 0x82615A84;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82615A90:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615b20
	if (cr6.eq) goto loc_82615B20;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_82615AB0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82615b08
	if (cr6.eq) goto loc_82615B08;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82615b08
	if (cr6.eq) goto loc_82615B08;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82615ADC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82615b08
	if (cr6.eq) goto loc_82615B08;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82615AF0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x821b4828
	ctx.lr = 0x82615B04;
	sub_821B4828(ctx, base);
	// b 0x82615b0c
	goto loc_82615B0C;
loc_82615B08:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82615B0C:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82615ab0
	if (cr6.lt) goto loc_82615AB0;
loc_82615B20:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82615B2C"))) PPC_WEAK_FUNC(sub_82615B2C);
PPC_FUNC_IMPL(__imp__sub_82615B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615B30"))) PPC_WEAK_FUNC(sub_82615B30);
PPC_FUNC_IMPL(__imp__sub_82615B30) {
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
	ctx.lr = 0x82615B38;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82615b60
	if (cr6.eq) goto loc_82615B60;
	// bl 0x8217d890
	ctx.lr = 0x82615B54;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82615B60:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615bf0
	if (cr6.eq) goto loc_82615BF0;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_82615B80:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82615bd8
	if (cr6.eq) goto loc_82615BD8;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82615bd8
	if (cr6.eq) goto loc_82615BD8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82615BAC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82615bd8
	if (cr6.eq) goto loc_82615BD8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82615BC0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x821a11d8
	ctx.lr = 0x82615BD4;
	sub_821A11D8(ctx, base);
	// b 0x82615bdc
	goto loc_82615BDC;
loc_82615BD8:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_82615BDC:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82615b80
	if (cr6.lt) goto loc_82615B80;
loc_82615BF0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82615BFC"))) PPC_WEAK_FUNC(sub_82615BFC);
PPC_FUNC_IMPL(__imp__sub_82615BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615C00"))) PPC_WEAK_FUNC(sub_82615C00);
PPC_FUNC_IMPL(__imp__sub_82615C00) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82615990
	ctx.lr = 0x82615C28;
	sub_82615990(ctx, base);
	// addi r3,r31,76
	ctx.r3.s64 = r31.s64 + 76;
	// bl 0x821b5a60
	ctx.lr = 0x82615C30;
	sub_821B5A60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82615a60
	ctx.lr = 0x82615C40;
	sub_82615A60(ctx, base);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x821b48f0
	ctx.lr = 0x82615C48;
	sub_821B48F0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82615b30
	ctx.lr = 0x82615C68;
	sub_82615B30(ctx, base);
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

__attribute__((alias("__imp__sub_82615C84"))) PPC_WEAK_FUNC(sub_82615C84);
PPC_FUNC_IMPL(__imp__sub_82615C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615C88"))) PPC_WEAK_FUNC(sub_82615C88);
PPC_FUNC_IMPL(__imp__sub_82615C88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82615c00
	sub_82615C00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82615C94"))) PPC_WEAK_FUNC(sub_82615C94);
PPC_FUNC_IMPL(__imp__sub_82615C94) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82615C98"))) PPC_WEAK_FUNC(sub_82615C98);
PPC_FUNC_IMPL(__imp__sub_82615C98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// stfs f1,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615d08
	if (cr6.eq) goto loc_82615D08;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// bne cr6,0x82615d08
	if (!cr6.eq) goto loc_82615D08;
	// lbz r11,6(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615d00
	if (cr6.eq) goto loc_82615D00;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8218fe68
	ctx.lr = 0x82615CEC;
	sub_8218FE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82615d00
	if (cr6.eq) goto loc_82615D00;
	// li r11,2
	r11.s64 = 2;
	// b 0x82615d0c
	goto loc_82615D0C;
loc_82615D00:
	// li r11,1
	r11.s64 = 1;
	// b 0x82615d0c
	goto loc_82615D0C;
loc_82615D08:
	// li r11,0
	r11.s64 = 0;
loc_82615D0C:
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r9,r1,140
	ctx.r9.s64 = ctx.r1.s64 + 140;
	// addi r8,r10,20872
	ctx.r8.s64 = ctx.r10.s64 + 20872;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v1,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82615D38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82615D50"))) PPC_WEAK_FUNC(sub_82615D50);
PPC_FUNC_IMPL(__imp__sub_82615D50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x82615D58;
	// lhz r16,36(r3)
	r16.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// lwz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmpwi cr6,r16,0
	cr6.compare<int32_t>(r16.s32, 0, xer);
	// beq cr6,0x82615f70
	if (cr6.eq) goto loc_82615F70;
	// lwz r17,8(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r11,r16,-3
	xer.ca = r16.u32 > 2;
	r11.s64 = r16.s64 + -3;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r19,16(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r20,0
	r20.s64 = 0;
	// lwz r18,32(r3)
	r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// ble 0x82615efc
	if (!cr0.gt) goto loc_82615EFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r9,r19,8
	ctx.r9.s64 = r19.s64 + 8;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r17,8
	ctx.r10.s64 = r17.s64 + 8;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// addi r11,r18,16
	r11.s64 = r18.s64 + 16;
	// subf r26,r18,r19
	r26.s64 = r19.s64 - r18.s64;
	// rlwinm r20,r3,2,0,29
	r20.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// li r21,24
	r21.s64 = 24;
	// li r22,-4
	r22.s64 = -4;
	// li r23,4
	r23.s64 = 4;
	// li r24,8
	r24.s64 = 8;
	// li r25,16
	r25.s64 = 16;
	// li r27,-8
	r27.s64 = -8;
loc_82615DB8:
	// dcbt r0,r11
	// dcbt r10,r21
	// add r7,r26,r11
	ctx.r7.u64 = r26.u64 + r11.u64;
	// dcbt r0,r7
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r7,r6,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 + ctx.r8.u64;
	// dcbt r0,r5
	// lvlx128 v63,r9,r27
	temp.u32 = ctx.r9.u32 + r27.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r4,-16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// lvlx128 v62,r9,r22
	temp.u32 = ctx.r9.u32 + r22.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v61,v63,v0
	simde_mm_store_si128((simde__m128i*)v61.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v63.s8), simde_mm_load_si128((simde__m128i*)v63.s8))));
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v59,v62,v0
	simde_mm_store_si128((simde__m128i*)v59.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v62.s8), simde_mm_load_si128((simde__m128i*)v62.s8))));
	// lvlx128 v58,r9,r23
	temp.u32 = ctx.r9.u32 + r23.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v57,v60,v0
	simde_mm_store_si128((simde__m128i*)v57.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v60.s8), simde_mm_load_si128((simde__m128i*)v60.s8))));
	// lvlx128 v56,r10,r27
	temp.u32 = ctx.r10.u32 + r27.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v55,v58,v0
	simde_mm_store_si128((simde__m128i*)v55.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v58.s8), simde_mm_load_si128((simde__m128i*)v58.s8))));
	// lvlx128 v54,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v53,v56,v96
	simde_mm_store_si128((simde__m128i*)v53.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v56.s16), simde_mm_load_si128((simde__m128i*)v56.s16))));
	// lvlx128 v52,r10,r24
	temp.u32 = ctx.r10.u32 + r24.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v51,v61,v96
	simde_mm_store_si128((simde__m128i*)v51.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v61.s16), simde_mm_load_si128((simde__m128i*)v61.s16))));
	// lvlx128 v50,r10,r25
	temp.u32 = ctx.r10.u32 + r25.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// rlwinm r7,r4,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// vupkhsb128 v49,v54,v96
	simde_mm_store_si128((simde__m128i*)v49.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v54.s16), simde_mm_load_si128((simde__m128i*)v54.s16))));
	// lwz r6,-12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// vupkhsb128 v48,v59,v96
	simde_mm_store_si128((simde__m128i*)v48.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v59.s16), simde_mm_load_si128((simde__m128i*)v59.s16))));
	// lwz r5,-8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// vupkhsb128 v47,v57,v96
	simde_mm_store_si128((simde__m128i*)v47.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v57.s16), simde_mm_load_si128((simde__m128i*)v57.s16))));
	// lwz r31,-4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// vupkhsb128 v46,v52,v96
	simde_mm_store_si128((simde__m128i*)v46.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v52.s16), simde_mm_load_si128((simde__m128i*)v52.s16))));
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// vupkhsb128 v45,v50,v96
	simde_mm_store_si128((simde__m128i*)v45.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v50.s16), simde_mm_load_si128((simde__m128i*)v50.s16))));
	// rlwinm r7,r6,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// vupkhsb128 v44,v55,v96
	simde_mm_store_si128((simde__m128i*)v44.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v55.s16), simde_mm_load_si128((simde__m128i*)v55.s16))));
	// vcsxwfp128 v0,v53,12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v53.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// vcsxwfp128 v13,v51,7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v51.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// rlwinm r6,r5,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// vcsxwfp128 v12,v49,12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v49.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// rlwinm r5,r31,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// vcsxwfp128 v11,v48,7
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v48.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// vcsxwfp128 v10,v46,12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v46.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// vcsxwfp128 v9,v47,7
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v47.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// add r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 + ctx.r8.u64;
	// vcsxwfp128 v8,v45,12
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v45.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// addi r28,r4,16
	r28.s64 = ctx.r4.s64 + 16;
	// vcsxwfp128 v7,v44,7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v44.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// addi r31,r7,16
	r31.s64 = ctx.r7.s64 + 16;
	// addi r30,r6,16
	r30.s64 = ctx.r6.s64 + 16;
	// lvx128 v6,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r5,16
	r29.s64 = ctx.r5.s64 + 16;
	// lvx128 v5,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lvx128 v3,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v31,r0,r31
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v2,v0,v1,v6
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvx128 v30,r0,r30
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v29,v13,v1,v3
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// lvx128 v28,r0,r5
	simde_mm_store_si128((simde__m128i*)v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v27,v12,v1,v5
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// lvx128 v26,r0,r29
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v25,v11,v1,v31
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v31.f32)));
	// vmaddfp v24,v10,v1,v4
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// vmaddfp v23,v9,v1,v30
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v30.f32)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vmaddfp v22,v8,v1,v28
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v21,v7,v1,v26
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v26.f32)));
	// stvx128 v2,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v29,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v27,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x82615db8
	if (!cr0.eq) goto loc_82615DB8;
loc_82615EFC:
	// cmpw cr6,r20,r16
	cr6.compare<int32_t>(r20.s32, r16.s32, xer);
	// bge cr6,0x82615f70
	if (!cr6.lt) goto loc_82615F70;
	// rlwinm r11,r20,3,0,28
	r11.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r20,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r17
	ctx.r7.u64 = r11.u64 + r17.u64;
	// add r11,r10,r19
	r11.u64 = ctx.r10.u64 + r19.u64;
	// subf r5,r19,r18
	ctx.r5.s64 = r18.s64 - r19.s64;
	// subf r9,r20,r16
	ctx.r9.s64 = r16.s64 - r20.s64;
loc_82615F1C:
	// lvlx128 v43,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwzx r10,r5,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// vupkhsb128 v42,v43,v0
	simde_mm_store_si128((simde__m128i*)v42.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v43.s8), simde_mm_load_si128((simde__m128i*)v43.s8))));
	// lvlx128 v41,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v40,v41,v96
	simde_mm_store_si128((simde__m128i*)v40.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v41.s16), simde_mm_load_si128((simde__m128i*)v41.s16))));
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// vupkhsb128 v39,v42,v96
	simde_mm_store_si128((simde__m128i*)v39.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v42.s16), simde_mm_load_si128((simde__m128i*)v42.s16))));
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// vcsxwfp128 v0,v40,12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v40.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// vcsxwfp128 v13,v39,7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v39.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// lvx128 v12,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v10,v0,v1,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v9,v13,v1,v11
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// stvx128 v10,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x82615f1c
	if (!cr0.eq) goto loc_82615F1C;
loc_82615F70:
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82615F74"))) PPC_WEAK_FUNC(sub_82615F74);
PPC_FUNC_IMPL(__imp__sub_82615F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82615F78"))) PPC_WEAK_FUNC(sub_82615F78);
PPC_FUNC_IMPL(__imp__sub_82615F78) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82615F80;
	// lhz r25,36(r3)
	r25.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x826160d4
	if (cr6.eq) goto loc_826160D4;
	// lwz r27,8(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r11,r25,-3
	xer.ca = r25.u32 > 2;
	r11.s64 = r25.s64 + -3;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r26,32(r3)
	r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r28,0
	r28.s64 = 0;
	// ble 0x82616084
	if (!cr0.gt) goto loc_82616084;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r27,8
	ctx.r10.s64 = r27.s64 + 8;
	// rlwinm r8,r11,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r26,16
	r11.s64 = r26.s64 + 16;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// li r29,24
	r29.s64 = 24;
	// rlwinm r28,r8,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r30,-8
	r30.s64 = -8;
	// li r31,8
	r31.s64 = 8;
	// li r3,16
	ctx.r3.s64 = 16;
loc_82615FCC:
	// dcbt r0,r11
	// dcbt r10,r29
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r7,r7,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 + ctx.r9.u64;
	// dcbt r0,r6
	// lvlx128 v63,r10,r30
	temp.u32 = ctx.r10.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r5,-16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// vupkhsb128 v62,v63,v96
	simde_mm_store_si128((simde__m128i*)v62.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v63.s16), simde_mm_load_si128((simde__m128i*)v63.s16))));
	// lwz r4,-12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// rlwinm r7,r5,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r5,-8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// rlwinm r6,r4,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// vcsxwfp128 v0,v62,12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v62.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// rlwinm r5,r5,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r4,r4,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r5,r9
	ctx.r5.u64 = ctx.r5.u64 + ctx.r9.u64;
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r4,r4,r9
	ctx.r4.u64 = ctx.r4.u64 + ctx.r9.u64;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// vmaddfp v12,v0,v1,v13
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v60,v61,v96
	simde_mm_store_si128((simde__m128i*)v60.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v61.s16), simde_mm_load_si128((simde__m128i*)v61.s16))));
	// vcsxwfp128 v10,v60,12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v60.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// vmaddfp v9,v10,v1,v11
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// stvx128 v9,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v59,r10,r31
	temp.u32 = ctx.r10.u32 + r31.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v58,v59,v96
	simde_mm_store_si128((simde__m128i*)v58.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v59.s16), simde_mm_load_si128((simde__m128i*)v59.s16))));
	// vcsxwfp128 v7,v58,12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v58.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// vmaddfp v6,v7,v1,v8
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// stvx128 v6,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v57,r10,r3
	temp.u32 = ctx.r10.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v56,v57,v96
	simde_mm_store_si128((simde__m128i*)v56.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v57.s16), simde_mm_load_si128((simde__m128i*)v57.s16))));
	// vcsxwfp128 v4,v56,12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v56.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vmaddfp v3,v4,v1,v5
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v3,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x82615fcc
	if (!cr0.eq) goto loc_82615FCC;
loc_82616084:
	// cmpw cr6,r28,r25
	cr6.compare<int32_t>(r28.s32, r25.s32, xer);
	// bge cr6,0x826160d4
	if (!cr6.lt) goto loc_826160D4;
	// rlwinm r10,r28,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r27
	ctx.r8.u64 = ctx.r10.u64 + r27.u64;
	// add r10,r11,r26
	ctx.r10.u64 = r11.u64 + r26.u64;
	// subf r11,r28,r25
	r11.s64 = r25.s64 - r28.s64;
loc_826160A0:
	// lvlx128 v55,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// vupkhsb128 v54,v55,v96
	simde_mm_store_si128((simde__m128i*)v54.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v55.s16), simde_mm_load_si128((simde__m128i*)v55.s16))));
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r7,r7,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// vcsxwfp128 v0,v54,12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v54.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v12,v0,v1,v13
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x826160a0
	if (!cr0.eq) goto loc_826160A0;
loc_826160D4:
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826160D8"))) PPC_WEAK_FUNC(sub_826160D8);
PPC_FUNC_IMPL(__imp__sub_826160D8) {
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
	PPCVRegister v14{};
	PPCVRegister v15{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x826160E0;
	// lhz r30,36(r3)
	r30.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// lwz r31,8(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stw r30,-176(r1)
	PPC_STORE_U32(ctx.r1.u32 + -176, r30.u32);
	// beq cr6,0x8261641c
	if (cr6.eq) goto loc_8261641C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r9,r30,-3
	xer.ca = r30.u32 > 2;
	ctx.r9.s64 = r30.s64 + -3;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r5,32(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,-172(r1)
	PPC_STORE_U32(ctx.r1.u32 + -172, r11.u32);
	// stw r7,-168(r1)
	PPC_STORE_U32(ctx.r1.u32 + -168, ctx.r7.u32);
	// stw r6,-164(r1)
	PPC_STORE_U32(ctx.r1.u32 + -164, ctx.r6.u32);
	// stw r5,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, ctx.r5.u32);
	// ble 0x8261637c
	if (!cr0.gt) goto loc_8261637C;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// addi r8,r6,12
	ctx.r8.s64 = ctx.r6.s64 + 12;
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r7,8
	ctx.r10.s64 = ctx.r7.s64 + 8;
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// rlwinm r4,r3,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r5,16
	r11.s64 = ctx.r5.s64 + 16;
	// subf r21,r6,r7
	r21.s64 = ctx.r7.s64 - ctx.r6.s64;
	// stw r4,-156(r1)
	PPC_STORE_U32(ctx.r1.u32 + -156, ctx.r4.u32);
	// subf r20,r5,r6
	r20.s64 = ctx.r6.s64 - ctx.r5.s64;
	// subf r19,r7,r6
	r19.s64 = ctx.r6.s64 - ctx.r7.s64;
	// li r14,-4
	r14.s64 = -4;
	// li r15,8
	r15.s64 = 8;
	// li r16,16
	r16.s64 = 16;
	// li r17,4
	r17.s64 = 4;
	// li r22,-8
	r22.s64 = -8;
	// li r18,-12
	r18.s64 = -12;
loc_82616168:
	// dcbt r0,r11
	// li r7,24
	ctx.r7.s64 = 24;
	// dcbt r9,r7
	// add r7,r20,r11
	ctx.r7.u64 = r20.u64 + r11.u64;
	// add r6,r7,r21
	ctx.r6.u64 = ctx.r7.u64 + r21.u64;
	// dcbt r0,r6
	// dcbt r0,r7
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 + ctx.r6.u64;
	// rlwinm r7,r5,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r7,r31
	ctx.r4.u64 = ctx.r7.u64 + r31.u64;
	// dcbt r0,r4
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r7,-12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// lvlx128 v62,r10,r14
	temp.u32 = ctx.r10.u32 + r14.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r6,-8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lvlx128 v61,r10,r17
	temp.u32 = ctx.r10.u32 + r17.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// vupkhsb128 v60,v63,v0
	simde_mm_store_si128((simde__m128i*)v60.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v63.s8), simde_mm_load_si128((simde__m128i*)v63.s8))));
	// lvlx128 v59,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v58,v62,v0
	simde_mm_store_si128((simde__m128i*)v58.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v62.s8), simde_mm_load_si128((simde__m128i*)v62.s8))));
	// lvlx128 v57,r9,r15
	temp.u32 = ctx.r9.u32 + r15.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v56,v61,v0
	simde_mm_store_si128((simde__m128i*)v56.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v61.s8), simde_mm_load_si128((simde__m128i*)v61.s8))));
	// lvlx128 v55,r9,r16
	temp.u32 = ctx.r9.u32 + r16.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// vupkhsb128 v54,v59,v96
	simde_mm_store_si128((simde__m128i*)v54.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v59.s16), simde_mm_load_si128((simde__m128i*)v59.s16))));
	// rlwinm r30,r6,1,0,30
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// vupkhsb128 v53,v57,v96
	simde_mm_store_si128((simde__m128i*)v53.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v57.s16), simde_mm_load_si128((simde__m128i*)v57.s16))));
	// rlwinm r29,r5,1,0,30
	r29.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// vupkhsb128 v52,v55,v96
	simde_mm_store_si128((simde__m128i*)v52.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v55.s16), simde_mm_load_si128((simde__m128i*)v55.s16))));
	// vupkhsb128 v51,v58,v96
	simde_mm_store_si128((simde__m128i*)v51.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v58.s16), simde_mm_load_si128((simde__m128i*)v58.s16))));
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// vupkhsb128 v50,v60,v96
	simde_mm_store_si128((simde__m128i*)v50.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v60.s16), simde_mm_load_si128((simde__m128i*)v60.s16))));
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + r30.u64;
	// vupkhsb128 v49,v56,v96
	simde_mm_store_si128((simde__m128i*)v49.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v56.s16), simde_mm_load_si128((simde__m128i*)v56.s16))));
	// add r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 + r29.u64;
	// rlwinm r7,r7,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// vcsxwfp128 v0,v54,12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v54.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// rlwinm r6,r6,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// vcsxwfp128 v13,v53,12
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v53.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// rlwinm r5,r5,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// vcsxwfp128 v12,v52,12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v52.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// vcsxwfp128 v11,v51,7
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v51.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// add r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 + r31.u64;
	// vcsxwfp128 v10,v50,7
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v50.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + r31.u64;
	// vcsxwfp128 v9,v49,7
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v49.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// add r5,r5,r31
	ctx.r5.u64 = ctx.r5.u64 + r31.u64;
	// lwz r4,-16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// addi r30,r7,16
	r30.s64 = ctx.r7.s64 + 16;
	// addi r29,r6,16
	r29.s64 = ctx.r6.s64 + 16;
	// lvlx128 v48,r10,r22
	temp.u32 = ctx.r10.u32 + r22.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r28,r5,16
	r28.s64 = ctx.r5.s64 + 16;
	// vupkhsb128 v47,v48,v0
	simde_mm_store_si128((simde__m128i*)v47.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v48.s8), simde_mm_load_si128((simde__m128i*)v48.s8))));
	// rlwinm r27,r4,1,0,30
	r27.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v8,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r4,r4,r27
	ctx.r4.u64 = ctx.r4.u64 + r27.u64;
	// lvx128 v6,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsb128 v46,v47,v96
	simde_mm_store_si128((simde__m128i*)v46.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v47.s16), simde_mm_load_si128((simde__m128i*)v47.s16))));
	// lvx128 v4,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v3,v0,v1,v8
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// lvx128 v2,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v31,v13,v1,v7
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// lvlx128 v45,r19,r10
	temp.u32 = r19.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp v30,v12,v1,v5
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// lvlx128 v44,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp v29,v11,v1,v6
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvlx128 v43,r8,r18
	temp.u32 = ctx.r8.u32 + r18.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp v28,v10,v1,v4
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// lvlx128 v42,r8,r22
	temp.u32 = ctx.r8.u32 + r22.u32;
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v41,v45,v0
	simde_mm_store_si128((simde__m128i*)v41.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v45.s8), simde_mm_load_si128((simde__m128i*)v45.s8))));
	// lvlx128 v40,r9,r22
	temp.u32 = ctx.r9.u32 + r22.u32;
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp v27,v9,v1,v2
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vupkhsb128 v39,v44,v0
	simde_mm_store_si128((simde__m128i*)v39.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v44.s8), simde_mm_load_si128((simde__m128i*)v44.s8))));
	// rlwinm r4,r4,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// vupkhsb128 v38,v43,v0
	simde_mm_store_si128((simde__m128i*)v38.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v43.s8), simde_mm_load_si128((simde__m128i*)v43.s8))));
	// vupkhsb128 v37,v42,v0
	simde_mm_store_si128((simde__m128i*)v37.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v42.s8), simde_mm_load_si128((simde__m128i*)v42.s8))));
	// vupkhsb128 v36,v40,v96
	simde_mm_store_si128((simde__m128i*)v36.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v40.s16), simde_mm_load_si128((simde__m128i*)v40.s16))));
	// vupkhsb128 v35,v38,v96
	simde_mm_store_si128((simde__m128i*)v35.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v38.s16), simde_mm_load_si128((simde__m128i*)v38.s16))));
	// vcsxwfp128 v26,v46,7
	simde_mm_store_ps(v26.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v46.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupkhsb128 v34,v37,v96
	simde_mm_store_si128((simde__m128i*)v34.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v37.s16), simde_mm_load_si128((simde__m128i*)v37.s16))));
	// vcsxwfp128 v25,v36,12
	simde_mm_store_ps(v25.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v36.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// vupkhsb128 v33,v41,v96
	simde_mm_store_si128((simde__m128i*)v33.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v41.s16), simde_mm_load_si128((simde__m128i*)v41.s16))));
	// add r4,r4,r31
	ctx.r4.u64 = ctx.r4.u64 + r31.u64;
	// vupkhsb128 v32,v39,v96
	simde_mm_store_si128((simde__m128i*)v32.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v39.s16), simde_mm_load_si128((simde__m128i*)v39.s16))));
	// addi r27,r7,32
	r27.s64 = ctx.r7.s64 + 32;
	// vcsxwfp128 v24,v35,7
	simde_mm_store_ps(v24.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v35.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// addi r24,r4,16
	r24.s64 = ctx.r4.s64 + 16;
	// vcsxwfp128 v23,v34,7
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v34.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// addi r23,r4,32
	r23.s64 = ctx.r4.s64 + 32;
	// vcsxwfp128 v22,v33,7
	simde_mm_store_ps(v22.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v33.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// addi r26,r6,32
	r26.s64 = ctx.r6.s64 + 32;
	// vcsxwfp128 v21,v32,7
	simde_mm_store_ps(v21.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v32.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// addi r25,r5,32
	r25.s64 = ctx.r5.s64 + 32;
	// lvx128 v20,r0,r4
	simde_mm_store_si128((simde__m128i*)v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lvx128 v19,r0,r24
	simde_mm_store_si128((simde__m128i*)v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v18,r0,r23
	simde_mm_store_si128((simde__m128i*)v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lvx128 v17,r0,r27
	simde_mm_store_si128((simde__m128i*)v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lvx128 v16,r0,r26
	simde_mm_store_si128((simde__m128i*)v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v15,v26,v1,v19
	simde_mm_store_ps(v15.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v19.f32)));
	// vmaddfp v14,v25,v1,v20
	simde_mm_store_ps(v14.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v25.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v20.f32)));
	// lvx128 v0,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// vmaddfp v13,v24,v1,v18
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v24.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v18.f32)));
	// vmaddfp v12,v23,v1,v17
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v23.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v17.f32)));
	// vmaddfp v11,v22,v1,v16
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v22.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v16.f32)));
	// vmaddfp v10,v21,v1,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v21.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v15,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v14,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v14.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v3,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v29,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v31,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v28,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v27,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x82616168
	if (!cr0.eq) goto loc_82616168;
	// lwz r30,-176(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -176);
	// lwz r11,-172(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -172);
	// lwz r7,-168(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -168);
	// lwz r6,-164(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -164);
	// lwz r5,-160(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -160);
	// lwz r10,-156(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -156);
loc_8261637C:
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// bge cr6,0x8261641c
	if (!cr6.lt) goto loc_8261641C;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + r11.u64;
	// add r11,r4,r7
	r11.u64 = ctx.r4.u64 + ctx.r7.u64;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// subf r4,r7,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r7.s64;
	// subf r9,r10,r30
	ctx.r9.s64 = r30.s64 - ctx.r10.s64;
loc_826163A0:
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwzx r10,r5,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// lvlx128 v62,r11,r4
	temp.u32 = r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkhsb128 v61,v63,v0
	simde_mm_store_si128((simde__m128i*)v61.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v63.s8), simde_mm_load_si128((simde__m128i*)v63.s8))));
	// vupkhsb128 v60,v62,v0
	simde_mm_store_si128((simde__m128i*)v60.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v62.s8), simde_mm_load_si128((simde__m128i*)v62.s8))));
	// lvlx128 v59,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// vupkhsb128 v58,v59,v96
	simde_mm_store_si128((simde__m128i*)v58.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v59.s16), simde_mm_load_si128((simde__m128i*)v59.s16))));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// vupkhsb128 v57,v61,v96
	simde_mm_store_si128((simde__m128i*)v57.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v61.s16), simde_mm_load_si128((simde__m128i*)v61.s16))));
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// vupkhsb128 v56,v60,v96
	simde_mm_store_si128((simde__m128i*)v56.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v60.s16), simde_mm_load_si128((simde__m128i*)v60.s16))));
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// vcsxwfp128 v0,v58,12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v58.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x39800000)))));
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// vcsxwfp128 v13,v57,7
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v57.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// vcsxwfp128 v12,v56,7
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v56.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// addi r6,r10,32
	ctx.r6.s64 = ctx.r10.s64 + 32;
	// lvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v1,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v7,v13,v1,v10
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v6,v12,v1,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v8,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v7,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v6,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x826163a0
	if (!cr0.eq) goto loc_826163A0;
loc_8261641C:
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82616420"))) PPC_WEAK_FUNC(sub_82616420);
PPC_FUNC_IMPL(__imp__sub_82616420) {
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
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8261645c
	if (cr6.eq) goto loc_8261645C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82616450;
	sub_8217D890(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_8261645C:
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8261647c
	if (cr6.eq) goto loc_8261647C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82616470;
	sub_8217D890(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_8261647C:
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8261649c
	if (cr6.eq) goto loc_8261649C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82616490;
	sub_8217D890(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
loc_8261649C:
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826164bc
	if (cr6.eq) goto loc_826164BC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x826164B0;
	sub_8217D890(ctx, base);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
loc_826164BC:
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

__attribute__((alias("__imp__sub_826164D8"))) PPC_WEAK_FUNC(sub_826164D8);
PPC_FUNC_IMPL(__imp__sub_826164D8) {
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
	// lhz r11,38(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82616500
	if (cr6.eq) goto loc_82616500;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x82616500;
	sub_82130588(ctx, base);
loc_82616500:
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82616514
	if (cr6.eq) goto loc_82616514;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x82616514;
	sub_82130588(ctx, base);
loc_82616514:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82616528
	if (cr6.eq) goto loc_82616528;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x82616528;
	sub_82130588(ctx, base);
loc_82616528:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8261653c
	if (cr6.eq) goto loc_8261653C;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8261653C;
	sub_82130588(ctx, base);
loc_8261653C:
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

__attribute__((alias("__imp__sub_82616550"))) PPC_WEAK_FUNC(sub_82616550);
PPC_FUNC_IMPL(__imp__sub_82616550) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82616420
	sub_82616420(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8261655C"))) PPC_WEAK_FUNC(sub_8261655C);
PPC_FUNC_IMPL(__imp__sub_8261655C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

