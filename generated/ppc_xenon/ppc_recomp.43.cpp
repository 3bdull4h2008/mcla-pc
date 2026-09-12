#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822B9EA0"))) PPC_WEAK_FUNC(sub_822B9EA0);
PPC_FUNC_IMPL(__imp__sub_822B9EA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r10,416(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 416);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b9ecc
	if (cr6.eq) goto loc_822B9ECC;
	// lfs f0,520(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 520);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_822B9ECC:
	// lwz r10,424(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 424);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b9ee4
	if (cr6.eq) goto loc_822B9EE4;
	// lfs f0,520(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 520);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_822B9EE4:
	// lwz r10,412(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 412);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b9efc
	if (cr6.eq) goto loc_822B9EFC;
	// lfs f0,520(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 520);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_822B9EFC:
	// lwz r11,420(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lfs f0,520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 520);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B9F18"))) PPC_WEAK_FUNC(sub_822B9F18);
PPC_FUNC_IMPL(__imp__sub_822B9F18) {
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
	// bl 0x826fd488
	ctx.lr = 0x822B9F38;
	sub_826FD488(ctx, base);
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b9f48
	if (cr6.eq) goto loc_822B9F48;
	// bl 0x8254b768
	ctx.lr = 0x822B9F48;
	sub_8254B768(ctx, base);
loc_822B9F48:
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// stw r30,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r30.u32);
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
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

__attribute__((alias("__imp__sub_822B9F6C"))) PPC_WEAK_FUNC(sub_822B9F6C);
PPC_FUNC_IMPL(__imp__sub_822B9F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9F70"))) PPC_WEAK_FUNC(sub_822B9F70);
PPC_FUNC_IMPL(__imp__sub_822B9F70) {
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
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822b9fa8
	if (!cr6.eq) goto loc_822B9FA8;
	// lwz r3,300(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 300);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b9fa8
	if (cr6.eq) goto loc_822B9FA8;
	// bl 0x8254ca78
	ctx.lr = 0x822B9F98;
	sub_8254CA78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822b9fac
	if (!cr6.eq) goto loc_822B9FAC;
loc_822B9FA8:
	// li r11,0
	r11.s64 = 0;
loc_822B9FAC:
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

__attribute__((alias("__imp__sub_822B9FC0"))) PPC_WEAK_FUNC(sub_822B9FC0);
PPC_FUNC_IMPL(__imp__sub_822B9FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// li r11,192
	r11.s64 = 192;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B9FD0"))) PPC_WEAK_FUNC(sub_822B9FD0);
PPC_FUNC_IMPL(__imp__sub_822B9FD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r9,r11,-31600
	ctx.r9.s64 = r11.s64 + -31600;
	// addi r11,r31,192
	r11.s64 = r31.s64 + 192;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,27644(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x822BA01C;
	sub_823DBAE8(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822BA028;
	sub_823DBBC8(ctx, base);
	// lfs f0,200(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	f0.f64 = double(temp.f32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f12,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f0,f30
	ctx.f11.f64 = double(float(f0.f64 * f30.f64));
	// fmuls f10,f12,f30
	ctx.f10.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmadds f9,f12,f13,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f9,192(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// fmsubs f8,f0,f13,f10
	ctx.f8.f64 = double(float(f0.f64 * ctx.f13.f64 - ctx.f10.f64));
	// stfs f8,200(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
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

__attribute__((alias("__imp__sub_822BA068"))) PPC_WEAK_FUNC(sub_822BA068);
PPC_FUNC_IMPL(__imp__sub_822BA068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,292(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BA070"))) PPC_WEAK_FUNC(sub_822BA070);
PPC_FUNC_IMPL(__imp__sub_822BA070) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822BA078;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d4
	ctx.lr = 0x822BA080;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BA0AC;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v126,r3,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f27,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f27.f64 = double(temp.f32);
	// beq cr6,0x822ba200
	if (cr6.eq) goto loc_822BA200;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,372(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 372);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ba0ec
	if (cr6.eq) goto loc_822BA0EC;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822ba0f0
	if (!cr6.eq) goto loc_822BA0F0;
loc_822BA0EC:
	// li r11,1
	r11.s64 = 1;
loc_822BA0F0:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// lfs f29,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// bne cr6,0x822ba11c
	if (!cr6.eq) goto loc_822BA11C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ba144
	if (cr6.eq) goto loc_822BA144;
loc_822BA114:
	// lwz r11,412(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 412);
	// b 0x822ba148
	goto loc_822BA148;
loc_822BA11C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ba134
	if (cr6.eq) goto loc_822BA134;
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// ble cr6,0x822ba114
	if (!cr6.gt) goto loc_822BA114;
	// lwz r11,420(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 420);
	// b 0x822ba148
	goto loc_822BA148;
loc_822BA134:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bge cr6,0x822ba144
	if (!cr6.lt) goto loc_822BA144;
	// lwz r11,424(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 424);
	// b 0x822ba148
	goto loc_822BA148;
loc_822BA144:
	// lwz r11,416(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 416);
loc_822BA148:
	// li r10,64
	ctx.r10.s64 = 64;
	// lvx128 v126,r11,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x822BA154;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,31492(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31492);
	f30.f64 = double(temp.f32);
	// vsubfp128 v127,v63,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v126.f32)));
	// beq cr6,0x822ba17c
	if (cr6.eq) goto loc_822BA17C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f28,14884(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f28.f64 = double(temp.f32);
	// b 0x822ba180
	goto loc_822BA180;
loc_822BA17C:
	// fmr f28,f30
	ctx.fpscr.disableFlushMode();
	f28.f64 = f30.f64;
loc_822BA180:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r29,300(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x822a8108
	ctx.lr = 0x822BA18C;
	sub_822A8108(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,25176(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 25176);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// li r10,32
	ctx.r10.s64 = 32;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lvlx128 v62,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v127,v60,v61,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)), simde_mm_load_ps(v127.f32)));
	// beq cr6,0x822ba2d8
	if (cr6.eq) goto loc_822BA2D8;
	// lwz r30,300(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BA1C4;
	sub_822A8108(ctx, base);
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,25168(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25168);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsel f11,f13,f29,f0
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? f29.f64 : f0.f64;
	// fsel f10,f31,f11,f27
	ctx.f10.f64 = f31.f64 >= 0.0 ? ctx.f11.f64 : f27.f64;
	// fmuls f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmuls f8,f9,f30
	ctx.f8.f64 = double(float(ctx.f9.f64 * f30.f64));
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v58,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmaddfp128 v127,v59,v57,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v57.f32)), simde_mm_load_ps(v127.f32)));
	// b 0x822ba2d8
	goto loc_822BA2D8;
loc_822BA200:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 336);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f29,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f29.f64 = double(temp.f32);
	// beq cr6,0x822ba220
	if (cr6.eq) goto loc_822BA220;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-28872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28872);
	f0.f64 = double(temp.f32);
	// b 0x822ba224
	goto loc_822BA224;
loc_822BA220:
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = f29.f64;
loc_822BA224:
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// clrlwi r30,r30,24
	r30.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f13,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f28,f0,f13
	f28.f64 = double(float(f0.f64 / ctx.f13.f64));
	// beq cr6,0x822ba248
	if (cr6.eq) goto loc_822BA248;
	// fmr f30,f27
	f30.f64 = f27.f64;
	// b 0x822ba24c
	goto loc_822BA24C;
loc_822BA248:
	// fmr f30,f29
	ctx.fpscr.disableFlushMode();
	f30.f64 = f29.f64;
loc_822BA24C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BA254;
	sub_822A8108(ctx, base);
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f12,f13,f0,f29
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fsel f11,f31,f12,f27
	ctx.f11.f64 = f31.f64 >= 0.0 ? ctx.f12.f64 : f27.f64;
	// fmuls f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 * f30.f64));
	// fmuls f9,f10,f28
	ctx.f9.f64 = double(float(ctx.f10.f64 * f28.f64));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v55,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmulfp128 v127,v56,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v54.f32)));
	// vsubfp128 v126,v126,v127
	simde_mm_store_ps(v126.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// beq cr6,0x822ba2a0
	if (cr6.eq) goto loc_822BA2A0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,14884(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f30.f64 = double(temp.f32);
	// b 0x822ba2a8
	goto loc_822BA2A8;
loc_822BA2A0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,31492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31492);
	f30.f64 = double(temp.f32);
loc_822BA2A8:
	// lwz r30,300(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BA2B4;
	sub_822A8108(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,25176(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25176);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// li r10,32
	ctx.r10.s64 = 32;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v52,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v51,v52,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// lvx128 v53,r3,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v126,v53,v51,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v126.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v51.f32)), simde_mm_load_ps(v126.f32)));
loc_822BA2D8:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8254ab98
	ctx.lr = 0x822BA2E0;
	sub_8254AB98(ctx, base);
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lfs f0,25168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 25168);
	f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f27,136(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x8254e2e0
	ctx.lr = 0x822BA2F8;
	sub_8254E2E0(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x8254ad08
	ctx.lr = 0x822BA304;
	sub_8254AD08(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lwz r11,-23636(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23636);
	// lwz r9,656(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ba324
	if (cr6.eq) goto loc_822BA324;
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x822ba330
	goto loc_822BA330;
loc_822BA324:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_822BA330:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vaddfp128 v50,v126,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// li r29,1
	r29.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,31016(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f29,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f29.f64 = double(temp.f32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// lfs f30,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f30.f64 = double(temp.f32);
	// stvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822BA360:
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// extsw r10,r30
	ctx.r10.s64 = r30.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmuls f28,f11,f30
	f28.f64 = double(float(ctx.f11.f64 * f30.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbae8
	ctx.lr = 0x822BA390;
	sub_823DBAE8(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(ctx.f1.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822BA39C;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fmuls f9,f0,f27
	ctx.f9.f64 = double(float(f0.f64 * f27.f64));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmuls f8,f0,f10
	ctx.f8.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fmsubs f7,f13,f10,f9
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 - ctx.f9.f64));
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f6,f13,f27,f8
	ctx.f6.f64 = double(float(ctx.f13.f64 * f27.f64 + ctx.f8.f64));
	// stfs f6,96(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v49,r0,r9
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v48,v49,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v126.f32)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822BA3FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822ba428
	if (cr6.eq) goto loc_822BA428;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// lvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x822ba360
	if (cr6.lt) goto loc_822BA360;
	// b 0x822ba42c
	goto loc_822BA42C;
loc_822BA428:
	// li r29,0
	r29.s64 = 0;
loc_822BA42C:
	// stfs f29,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x8254e338
	ctx.lr = 0x822BA438;
	sub_8254E338(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8254ab20
	ctx.lr = 0x822BA440;
	sub_8254AB20(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba20
	ctx.lr = 0x822BA460;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822BA464"))) PPC_WEAK_FUNC(sub_822BA464);
PPC_FUNC_IMPL(__imp__sub_822BA464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BA468"))) PPC_WEAK_FUNC(sub_822BA468);
PPC_FUNC_IMPL(__imp__sub_822BA468) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823d91f8
	ctx.lr = 0x822BA470;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r8,r11,29952
	ctx.r8.s64 = r11.s64 + 29952;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r28,1
	r28.s64 = 1;
	// lfs f13,344(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 344);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,340(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// lfs f0,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f31,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f31.f64 = double(temp.f32);
	// lfs f30,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f30.f64 = double(temp.f32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stfs f12,344(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// bne cr6,0x822ba55c
	if (!cr6.eq) goto loc_822BA55C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r30,r31,352
	r30.s64 = r31.s64 + 352;
	// bl 0x822a8108
	ctx.lr = 0x822BA4CC;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 356);
	f0.f64 = double(temp.f32);
	// lfs f13,360(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 360);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,352(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,376(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 376);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f11
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f7,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// lfs f5,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f12
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f12.f64));
	// fmuls f3,f8,f8
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f2,f6,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f9
	cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// bgt cr6,0x822ba544
	if (cr6.gt) goto loc_822BA544;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f0,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x822ba544
	if (cr6.gt) goto loc_822BA544;
	// lfs f0,344(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 344);
	f0.f64 = double(temp.f32);
	// lfs f13,368(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 368);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822ba55c
	if (!cr6.gt) goto loc_822BA55C;
	// stfs f30,344(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stw r28,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r28.u32);
	// b 0x822ba55c
	goto loc_822BA55C;
loc_822BA544:
	// stfs f30,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BA550;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822BA55C:
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822ba61c
	if (!cr6.eq) goto loc_822BA61C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r30,r31,352
	r30.s64 = r31.s64 + 352;
	// bl 0x822a8108
	ctx.lr = 0x822BA578;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 356);
	f0.f64 = double(temp.f32);
	// lfs f13,360(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 360);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,352(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,376(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 376);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f11
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f7,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// lfs f5,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f12
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f12.f64));
	// fmuls f3,f8,f8
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f2,f6,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f9
	cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// bgt cr6,0x822ba5fc
	if (cr6.gt) goto loc_822BA5FC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f0,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x822ba5fc
	if (cr6.gt) goto loc_822BA5FC;
	// lfs f0,344(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 344);
	f0.f64 = double(temp.f32);
	// lfs f13,372(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 372);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822ba5f4
	if (!cr6.gt) goto loc_822BA5F4;
	// li r11,2
	r11.s64 = 2;
	// stfs f30,344(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stw r11,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r11.u32);
	// b 0x822ba618
	goto loc_822BA618;
loc_822BA5F4:
	// stb r28,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r28.u8);
	// b 0x822ba61c
	goto loc_822BA61C;
loc_822BA5FC:
	// stfs f30,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BA608;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// lvx128 v62,r3,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r29.u32);
loc_822BA618:
	// stb r29,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r29.u8);
loc_822BA61C:
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822ba740
	if (!cr6.eq) goto loc_822BA740;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BA630;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// lvx128 v127,r3,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x8254c888
	ctx.lr = 0x822BA640;
	sub_8254C888(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v61,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x822BA65C;
	sub_822A8108(ctx, base);
	// addi r8,r3,32
	ctx.r8.s64 = ctx.r3.s64 + 32;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v59,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x822BA680;
	sub_8216C9C0(ctx, base);
	// lwz r6,332(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x822ba6fc
	if (!cr6.eq) goto loc_822BA6FC;
	// fabs f13,f31
	ctx.f13.u64 = f31.u64 & ~0x8000000000000000;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-28412(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28412);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822ba6e8
	if (!cr6.gt) goto loc_822BA6E8;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BA6AC;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lwz r4,300(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8254c8c0
	ctx.lr = 0x822BA6C0;
	sub_8254C8C0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v56,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x822BA6E0;
	sub_8216C9C0(ctx, base);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// b 0x822ba6ec
	goto loc_822BA6EC;
loc_822BA6E8:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
loc_822BA6EC:
	// mr r11,r28
	r11.u64 = r28.u64;
	// bge cr6,0x822ba6f8
	if (!cr6.lt) goto loc_822BA6F8;
	// li r11,2
	r11.s64 = 2;
loc_822BA6F8:
	// stw r11,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r11.u32);
loc_822BA6FC:
	// fabs f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 & ~0x8000000000000000;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,30280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30280);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822ba73c
	if (!cr6.lt) goto loc_822BA73C;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bge cr6,0x822ba720
	if (!cr6.lt) goto loc_822BA720;
	// li r11,2
	r11.s64 = 2;
loc_822BA720:
	// lwz r10,332(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x822ba73c
	if (!cr6.eq) goto loc_822BA73C;
	// stfs f30,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stw r29,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r29.u32);
	// stw r29,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r29.u32);
	// b 0x822ba740
	goto loc_822BA740;
loc_822BA73C:
	// stb r28,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r28.u8);
loc_822BA740:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_822BA758"))) PPC_WEAK_FUNC(sub_822BA758);
PPC_FUNC_IMPL(__imp__sub_822BA758) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x822BA760;
	// stfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f30.u64);
	// stfd f31,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r31,0(r19)
	r31.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lwz r3,324(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 324);
	// mr r21,r31
	r21.u64 = r31.u64;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// bl 0x82267490
	ctx.lr = 0x822BA79C;
	sub_82267490(ctx, base);
	// lwz r10,0(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r9,228(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 228);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x822ba7bc
	if (!cr6.eq) goto loc_822BA7BC;
	// lwz r11,232(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 232);
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822ba7c0
	if (cr6.eq) goto loc_822BA7C0;
loc_822BA7BC:
	// li r11,0
	r11.s64 = 0;
loc_822BA7C0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// ori r6,r9,64167
	ctx.r6.u64 = ctx.r9.u64 | 64167;
	// lfs f13,14348(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14348);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r7,r11,2192
	ctx.r7.s64 = r11.s64 + 2192;
	// bne cr6,0x822ba8a8
	if (!cr6.eq) goto loc_822BA8A8;
	// lbz r11,380(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ba8a8
	if (cr6.eq) goto loc_822BA8A8;
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r9,r6
	ctx.r10.s64 = ctx.r9.s64 * ctx.r6.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r5,r11,32,32
	ctx.r5.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// clrlwi r11,r11,9
	r11.u64 = r11.u32 & 0x7FFFFF;
	// stw r5,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r5.u32);
	// lfs f0,260(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 260);
	f0.f64 = double(temp.f32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// bge cr6,0x822ba8b0
	if (!cr6.lt) goto loc_822BA8B0;
	// lwz r9,0(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// bge cr6,0x822ba8b0
	if (!cr6.lt) goto loc_822BA8B0;
	// lwz r10,324(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 324);
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,0(r20)
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_822BA854:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x822ba88c
	if (cr6.lt) goto loc_822BA88C;
	// bgt cr6,0x822ba8b0
	if (cr6.gt) goto loc_822BA8B0;
	// lwz r10,328(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 328);
	// lbz r28,11(r11)
	r28.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// srw r10,r28,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (r28.u32 >> (ctx.r10.u8 & 0x3F));
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ba88c
	if (cr6.eq) goto loc_822BA88C;
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822ba8a0
	if (!cr6.eq) goto loc_822BA8A0;
loc_822BA88C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// blt cr6,0x822ba854
	if (cr6.lt) goto loc_822BA854;
	// b 0x822ba8b0
	goto loc_822BA8B0;
loc_822BA8A0:
	// li r30,1
	r30.s64 = 1;
	// b 0x822ba8b0
	goto loc_822BA8B0;
loc_822BA8A8:
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r4,0(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
loc_822BA8B0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// subf r10,r31,r3
	ctx.r10.s64 = ctx.r3.s64 - r31.s64;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// lfs f11,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// blt cr6,0x822baab8
	if (cr6.lt) goto loc_822BAAB8;
	// lwz r10,324(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 324);
	// rlwinm r11,r21,4,0,27
	r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,0(r20)
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,13
	ctx.r10.s64 = r11.s64 + 13;
	// addi r9,r11,29
	ctx.r9.s64 = r11.s64 + 29;
loc_822BA8E0:
	// lwz r11,-13(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822ba950
	if (cr6.lt) goto loc_822BA950;
	// bgt cr6,0x822bab6c
	if (cr6.gt) goto loc_822BAB6C;
	// lwz r11,328(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 328);
	// lbz r31,-2(r10)
	r31.u64 = PPC_LOAD_U8(ctx.r10.u32 + -2);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// srw r11,r31,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ba950
	if (cr6.eq) goto loc_822BA950;
	// lbz r11,380(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ba928
	if (cr6.eq) goto loc_822BA928;
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// clrlwi r31,r30,24
	r31.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x822ba950
	if (!cr6.eq) goto loc_822BA950;
loc_822BA928:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// lfs f0,-9(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -9);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ba94c
	if (cr6.eq) goto loc_822BA94C;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822ba948
	if (cr6.eq) goto loc_822BA948;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x822ba94c
	goto loc_822BA94C;
loc_822BA948:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f11.f64;
loc_822BA94C:
	// fadds f31,f0,f31
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f0.f64 + f31.f64));
loc_822BA950:
	// lwz r11,3(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 3);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822ba9c0
	if (cr6.lt) goto loc_822BA9C0;
	// bgt cr6,0x822bab58
	if (cr6.gt) goto loc_822BAB58;
	// lwz r11,328(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 328);
	// lbz r31,-2(r9)
	r31.u64 = PPC_LOAD_U8(ctx.r9.u32 + -2);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// srw r11,r31,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ba9c0
	if (cr6.eq) goto loc_822BA9C0;
	// lbz r11,380(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ba998
	if (cr6.eq) goto loc_822BA998;
	// lbz r11,0(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r31,r30,24
	r31.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x822ba9c0
	if (!cr6.eq) goto loc_822BA9C0;
loc_822BA998:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// lfs f0,-9(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -9);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ba9bc
	if (cr6.eq) goto loc_822BA9BC;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822ba9b8
	if (cr6.eq) goto loc_822BA9B8;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x822ba9bc
	goto loc_822BA9BC;
loc_822BA9B8:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f11.f64;
loc_822BA9BC:
	// fadds f31,f0,f31
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f0.f64 + f31.f64));
loc_822BA9C0:
	// lwz r11,19(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822baa30
	if (cr6.lt) goto loc_822BAA30;
	// bgt cr6,0x822bab60
	if (cr6.gt) goto loc_822BAB60;
	// lwz r11,328(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 328);
	// lbz r31,14(r9)
	r31.u64 = PPC_LOAD_U8(ctx.r9.u32 + 14);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// srw r11,r31,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822baa30
	if (cr6.eq) goto loc_822BAA30;
	// lbz r11,380(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822baa08
	if (cr6.eq) goto loc_822BAA08;
	// lbz r11,16(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 16);
	// clrlwi r31,r30,24
	r31.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x822baa30
	if (!cr6.eq) goto loc_822BAA30;
loc_822BAA08:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// lfs f0,7(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822baa2c
	if (cr6.eq) goto loc_822BAA2C;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822baa28
	if (cr6.eq) goto loc_822BAA28;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x822baa2c
	goto loc_822BAA2C;
loc_822BAA28:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f11.f64;
loc_822BAA2C:
	// fadds f31,f0,f31
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f0.f64 + f31.f64));
loc_822BAA30:
	// lwz r11,35(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 35);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822baaa0
	if (cr6.lt) goto loc_822BAAA0;
	// bgt cr6,0x822bab68
	if (cr6.gt) goto loc_822BAB68;
	// lwz r11,328(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 328);
	// lbz r31,30(r9)
	r31.u64 = PPC_LOAD_U8(ctx.r9.u32 + 30);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// srw r11,r31,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r31.u32 >> (r11.u8 & 0x3F));
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822baaa0
	if (cr6.eq) goto loc_822BAAA0;
	// lbz r11,380(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822baa78
	if (cr6.eq) goto loc_822BAA78;
	// lbz r11,32(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 32);
	// clrlwi r31,r30,24
	r31.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x822baaa0
	if (!cr6.eq) goto loc_822BAAA0;
loc_822BAA78:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// lfs f0,23(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 23);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822baa9c
	if (cr6.eq) goto loc_822BAA9C;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822baa98
	if (cr6.eq) goto loc_822BAA98;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x822baa9c
	goto loc_822BAA9C;
loc_822BAA98:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f11.f64;
loc_822BAA9C:
	// fadds f31,f0,f31
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f0.f64 + f31.f64));
loc_822BAAA0:
	// addi r21,r21,4
	r21.s64 = r21.s64 + 4;
	// addi r11,r3,-3
	r11.s64 = ctx.r3.s64 + -3;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// blt cr6,0x822ba8e0
	if (cr6.lt) goto loc_822BA8E0;
loc_822BAAB8:
	// cmpw cr6,r21,r3
	cr6.compare<int32_t>(r21.s32, ctx.r3.s32, xer);
	// bge cr6,0x822bab6c
	if (!cr6.lt) goto loc_822BAB6C;
	// lwz r10,324(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 324);
	// rlwinm r11,r21,4,0,27
	r11.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_822BAAD4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x822bab44
	if (cr6.lt) goto loc_822BAB44;
	// bgt cr6,0x822bab6c
	if (cr6.gt) goto loc_822BAB6C;
	// lwz r10,328(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 328);
	// lbz r8,11(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// srw r8,r8,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r10.u8 & 0x3F));
	// clrlwi r10,r8,31
	ctx.r10.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bab44
	if (cr6.eq) goto loc_822BAB44;
	// lbz r10,380(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 380);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bab1c
	if (cr6.eq) goto loc_822BAB1C;
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bne cr6,0x822bab44
	if (!cr6.eq) goto loc_822BAB44;
loc_822BAB1C:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bab40
	if (cr6.eq) goto loc_822BAB40;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822bab3c
	if (cr6.eq) goto loc_822BAB3C;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x822bab40
	goto loc_822BAB40;
loc_822BAB3C:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f11.f64;
loc_822BAB40:
	// fadds f31,f0,f31
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f0.f64 + f31.f64));
loc_822BAB44:
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpw cr6,r21,r3
	cr6.compare<int32_t>(r21.s32, ctx.r3.s32, xer);
	// blt cr6,0x822baad4
	if (cr6.lt) goto loc_822BAAD4;
	// b 0x822bab6c
	goto loc_822BAB6C;
loc_822BAB58:
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// b 0x822bab6c
	goto loc_822BAB6C;
loc_822BAB60:
	// addi r21,r21,2
	r21.s64 = r21.s64 + 2;
	// b 0x822bab6c
	goto loc_822BAB6C;
loc_822BAB68:
	// addi r21,r21,3
	r21.s64 = r21.s64 + 3;
loc_822BAB6C:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x822bad64
	if (!cr6.gt) goto loc_822BAD64;
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// clrldi r10,r5,32
	ctx.r10.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// mulld r11,r11,r6
	r11.s64 = r11.s64 * ctx.r6.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fmuls f13,f9,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// bge cr6,0x822bad64
	if (!cr6.lt) goto loc_822BAD64;
	// lwz r10,324(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 324);
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,0(r20)
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r27,r10,r9
	r27.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,14196(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14196);
	ctx.f12.f64 = double(temp.f32);
loc_822BABD4:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x822bac4c
	if (cr6.lt) goto loc_822BAC4C;
	// bgt cr6,0x822bad64
	if (cr6.gt) goto loc_822BAD64;
	// lwz r10,328(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 328);
	// lbz r9,11(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 11);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// srw r6,r9,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r7.u8 & 0x3F));
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822bac44
	if (cr6.eq) goto loc_822BAC44;
	// lbz r10,380(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 380);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bac1c
	if (cr6.eq) goto loc_822BAC1C;
	// lbz r10,13(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 13);
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x822bac44
	if (!cr6.eq) goto loc_822BAC44;
loc_822BAC1C:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bac40
	if (cr6.eq) goto loc_822BAC40;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822bac3c
	if (cr6.eq) goto loc_822BAC3C;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x822bac40
	goto loc_822BAC40;
loc_822BAC3C:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f11.f64;
loc_822BAC40:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
loc_822BAC44:
	// fcmpu cr6,f13,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x822bac70
	if (cr6.lt) goto loc_822BAC70;
loc_822BAC4C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r27,r27,16
	r27.s64 = r27.s64 + 16;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x822babd4
	if (cr6.lt) goto loc_822BABD4;
	// stw r21,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r21.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_822BAC70:
	// lbz r11,12(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 12);
	// li r26,0
	r26.s64 = 0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// lbz r10,10(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bad64
	if (cr6.eq) goto loc_822BAD64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r23,176
	r29.s64 = r23.s64 + 176;
	// addi r28,r23,184
	r28.s64 = r23.s64 + 184;
	// rlwinm r22,r25,2,26,29
	r22.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0x3C;
	// li r24,16
	r24.s64 = 16;
	// lfs f31,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
loc_822BACA4:
	// lhz r11,8(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,324(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 324);
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82267498
	ctx.lr = 0x822BACBC;
	sub_82267498(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,324(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 324);
	// bl 0x822674b0
	ctx.lr = 0x822BACC8;
	sub_822674B0(ctx, base);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,5
	r11.u64 = __builtin_rotateleft32(r11.u32, 5);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// sth r7,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r7.u16);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lhz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r25,0(r28)
	r25.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// sth r11,4(r28)
	PPC_STORE_U16(r28.u32 + 4, r11.u16);
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r30,r3,2
	r30.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// stvx128 v62,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,324(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 324);
	// bl 0x822674c8
	ctx.lr = 0x822BAD20;
	sub_822674C8(ctx, base);
	// stfs f1,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// fcmpu cr6,f1,f30
	cr6.compare(ctx.f1.f64, f30.f64);
	// bne cr6,0x822bad30
	if (!cr6.eq) goto loc_822BAD30;
	// stfs f31,28(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
loc_822BAD30:
	// lwzx r11,r30,r25
	r11.u64 = PPC_LOAD_U32(r30.u32 + r25.u32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stwx r10,r30,r25
	PPC_STORE_U32(r30.u32 + r25.u32, ctx.r10.u32);
	// lwz r8,0(r20)
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// rlwimi r9,r8,6,19,25
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 6) & 0x1FC0) | (ctx.r9.u64 & 0xFFFFFFFFFFFFE03F);
	// rlwinm r7,r9,0,30,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFC3;
	// or r6,r7,r22
	ctx.r6.u64 = ctx.r7.u64 | r22.u64;
	// stwx r6,r30,r25
	PPC_STORE_U32(r30.u32 + r25.u32, ctx.r6.u32);
	// lbz r5,10(r27)
	ctx.r5.u64 = PPC_LOAD_U8(r27.u32 + 10);
	// cmpw cr6,r26,r5
	cr6.compare<int32_t>(r26.s32, ctx.r5.s32, xer);
	// blt cr6,0x822baca4
	if (cr6.lt) goto loc_822BACA4;
loc_822BAD64:
	// stw r21,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r21.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822BAD78"))) PPC_WEAK_FUNC(sub_822BAD78);
PPC_FUNC_IMPL(__imp__sub_822BAD78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,184(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r10,r4,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,176(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822badc4
	if (cr6.eq) goto loc_822BADC4;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,12
	ctx.r8.s64 = 12;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v62,r11,r8
	temp.u32 = r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822BADC4:
	// lvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BADD0"))) PPC_WEAK_FUNC(sub_822BADD0);
PPC_FUNC_IMPL(__imp__sub_822BADD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,188(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bade4
	if (!cr6.eq) goto loc_822BADE4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822BADE4:
	// lwz r10,216(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x822bae0c
	if (!cr6.eq) goto loc_822BAE0C;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// rlwinm r9,r10,19,0,12
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0xFFF80000;
	// srawi r3,r9,25
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFFFF) != 0);
	ctx.r3.s64 = ctx.r9.s32 >> 25;
	// blr 
	return;
loc_822BAE0C:
	// lwz r11,184(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// rlwinm r8,r9,19,0,12
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0xFFF80000;
	// srawi r3,r8,25
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFFFF) != 0);
	ctx.r3.s64 = ctx.r8.s32 >> 25;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BAE24"))) PPC_WEAK_FUNC(sub_822BAE24);
PPC_FUNC_IMPL(__imp__sub_822BAE24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BAE28"))) PPC_WEAK_FUNC(sub_822BAE28);
PPC_FUNC_IMPL(__imp__sub_822BAE28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,188(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bae3c
	if (!cr6.eq) goto loc_822BAE3C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822BAE3C:
	// lwz r10,216(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x822bae64
	if (!cr6.eq) goto loc_822BAE64;
	// lwz r10,184(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// rlwinm r9,r10,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFC000000;
	// srawi r3,r9,28
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFFFFF) != 0);
	ctx.r3.s64 = ctx.r9.s32 >> 28;
	// blr 
	return;
loc_822BAE64:
	// lwz r11,184(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// rlwinm r8,r9,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0xFC000000;
	// srawi r3,r8,28
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFFFF) != 0);
	ctx.r3.s64 = ctx.r8.s32 >> 28;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BAE7C"))) PPC_WEAK_FUNC(sub_822BAE7C);
PPC_FUNC_IMPL(__imp__sub_822BAE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BAE80"))) PPC_WEAK_FUNC(sub_822BAE80);
PPC_FUNC_IMPL(__imp__sub_822BAE80) {
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
	// lwz r3,324(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// bl 0x82640ad8
	ctx.lr = 0x822BAEA0;
	sub_82640AD8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,324(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// bl 0x82267490
	ctx.lr = 0x822BAEAC;
	sub_82267490(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x822baef8
	if (!cr6.gt) goto loc_822BAEF8;
	// lwz r10,324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
loc_822BAEC4:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// beq cr6,0x822baedc
	if (cr6.eq) goto loc_822BAEDC;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// li r11,0
	r11.s64 = 0;
loc_822BAEDC:
	// lbz r10,10(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 10);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x822baeec
	if (cr6.gt) goto loc_822BAEEC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_822BAEEC:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x822baec4
	if (!cr0.eq) goto loc_822BAEC4;
loc_822BAEF8:
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
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

__attribute__((alias("__imp__sub_822BAF14"))) PPC_WEAK_FUNC(sub_822BAF14);
PPC_FUNC_IMPL(__imp__sub_822BAF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BAF18"))) PPC_WEAK_FUNC(sub_822BAF18);
PPC_FUNC_IMPL(__imp__sub_822BAF18) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822BAF20;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,324(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// bl 0x82640ad8
	ctx.lr = 0x822BAF40;
	sub_82640AD8(ctx, base);
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x822bb0b0
	if (!cr6.lt) goto loc_822BB0B0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r23,0
	r23.s64 = 0;
	// li r27,64
	r27.s64 = 64;
	// li r24,80
	r24.s64 = 80;
	// lfs f30,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f30.f64 = double(temp.f32);
	// li r25,16
	r25.s64 = 16;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r26,1
	r26.s64 = 1;
loc_822BAF74:
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r23.u32);
	// bge cr6,0x822bb068
	if (!cr6.lt) goto loc_822BB068;
loc_822BAF84:
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba758
	ctx.lr = 0x822BAF9C;
	sub_822BA758(ctx, base);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r6,r28
	cr6.compare<int32_t>(ctx.r6.s32, r28.s32, xer);
	// bge cr6,0x822bb068
	if (!cr6.lt) goto loc_822BB068;
	// lwz r10,324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// mulli r9,r6,368
	ctx.r9.s64 = ctx.r6.s64 * 368;
	// lhz r11,180(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// lwz r8,176(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// rotlwi r7,r11,5
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 5);
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r5,180(r31)
	PPC_STORE_U16(r31.u32 + 180, ctx.r5.u16);
	// lhz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// add r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r7,184(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// sth r3,188(r31)
	PPC_STORE_U16(r31.u32 + 188, ctx.r3.u16);
	// lvx128 v63,r11,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r4,330(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 330);
	// addi r10,r31,176
	ctx.r10.s64 = r31.s64 + 176;
	// addi r10,r31,184
	ctx.r10.s64 = r31.s64 + 184;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822bb008
	if (cr6.eq) goto loc_822BB008;
	// lfs f0,172(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 172);
	f0.f64 = double(temp.f32);
	// b 0x822bb00c
	goto loc_822BB00C;
loc_822BB008:
	// lfs f0,168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 168);
	f0.f64 = double(temp.f32);
loc_822BB00C:
	// stfs f0,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lvx128 v62,r11,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r9,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,188(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 188);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// stfs f0,28(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 28, temp.u32);
	// bne cr6,0x822bb02c
	if (!cr6.eq) goto loc_822BB02C;
	// stfs f30,28(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 28, temp.u32);
loc_822BB02C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lbz r9,330(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 330);
	// lwzx r5,r8,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// addi r11,r6,1
	r11.s64 = ctx.r6.s64 + 1;
	// rlwimi r10,r6,4,21,27
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 4) & 0x7F0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF80F);
	// rlwimi r9,r26,1,0,30
	ctx.r9.u64 = (__builtin_rotateleft32(r26.u32, 1) & 0xFFFFFFFE) | (ctx.r9.u64 & 0xFFFFFFFF00000001);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// rlwinm r4,r10,2,19,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x1FFC;
	// rlwinm r3,r5,0,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFE;
	// or r10,r4,r9
	ctx.r10.u64 = ctx.r4.u64 | ctx.r9.u64;
	// rlwinm r3,r3,0,30,18
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFE003;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// or r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 | ctx.r3.u64;
	// stwx r9,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r9.u32);
	// blt cr6,0x822baf84
	if (cr6.lt) goto loc_822BAF84;
loc_822BB068:
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x822bb078
	if (!cr0.lt) goto loc_822BB078;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_822BB078:
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba758
	ctx.lr = 0x822BB098;
	sub_822BA758(ctx, base);
	// lwz r9,224(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// subf r30,r28,r8
	r30.s64 = ctx.r8.s64 - r28.s64;
	// blt cr6,0x822baf74
	if (cr6.lt) goto loc_822BAF74;
loc_822BB0B0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822BB0C0"))) PPC_WEAK_FUNC(sub_822BB0C0);
PPC_FUNC_IMPL(__imp__sub_822BB0C0) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// stb r4,254(r10)
	PPC_STORE_U8(ctx.r10.u32 + 254, ctx.r4.u8);
	// bne cr6,0x822bb0fc
	if (!cr6.eq) goto loc_822BB0FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f13,276(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 276, temp.u32);
	// stfs f0,284(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 284, temp.u32);
	// stfs f0,288(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 288, temp.u32);
loc_822BB0FC:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lwz r7,2192(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r9,r7,r5
	ctx.r9.s64 = ctx.r7.s64 * ctx.r5.s64;
	// lfs f0,14348(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// clrlwi r3,r11,9
	ctx.r3.u64 = r11.u32 & 0x7FFFFF;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stw r9,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, ctx.r9.u32);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,280(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 280, temp.u32);
	// beq cr6,0x822bb188
	if (cr6.eq) goto loc_822BB188;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822bb188
	if (cr6.eq) goto loc_822BB188;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822bb188
	if (cr6.eq) goto loc_822BB188;
	// bl 0x82348880
	ctx.lr = 0x822BB178;
	sub_82348880(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822BB188:
	// li r11,1
	r11.s64 = 1;
	// stb r11,256(r10)
	PPC_STORE_U8(ctx.r10.u32 + 256, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BB1A0"))) PPC_WEAK_FUNC(sub_822BB1A0);
PPC_FUNC_IMPL(__imp__sub_822BB1A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bb1d8
	if (cr6.eq) goto loc_822BB1D8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r9,30848
	ctx.r10.s64 = ctx.r9.s64 + 30848;
loc_822BB1B8:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822bb1e0
	if (cr6.eq) goto loc_822BB1E0;
	// lhz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,30864
	ctx.r10.s64 = ctx.r10.s64 + 30864;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822bb1b8
	if (cr6.lt) goto loc_822BB1B8;
loc_822BB1D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822BB1E0:
	// mulli r11,r11,30864
	r11.s64 = r11.s64 * 30864;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stb r7,30848(r9)
	PPC_STORE_U8(ctx.r9.u32 + 30848, ctx.r7.u8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BB208"))) PPC_WEAK_FUNC(sub_822BB208);
PPC_FUNC_IMPL(__imp__sub_822BB208) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bb240
	if (cr6.eq) goto loc_822BB240;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_822BB224:
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// beq cr6,0x822bb248
	if (cr6.eq) goto loc_822BB248;
	// lhz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,30864
	ctx.r9.s64 = ctx.r9.s64 + 30864;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x822bb224
	if (cr6.lt) goto loc_822BB224;
loc_822BB240:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822BB248:
	// mulli r10,r10,30864
	ctx.r10.s64 = ctx.r10.s64 * 30864;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbz r9,30848(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 30848);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bb240
	if (cr6.eq) goto loc_822BB240;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r9,30848(r10)
	PPC_STORE_U8(ctx.r10.u32 + 30848, ctx.r9.u8);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BB278"))) PPC_WEAK_FUNC(sub_822BB278);
PPC_FUNC_IMPL(__imp__sub_822BB278) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lhz r11,4(r7)
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// ble cr6,0x822bb2bc
	if (!cr6.gt) goto loc_822BB2BC;
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r4,r11
	ctx.r10.s64 = r11.s64 - ctx.r4.s64;
	// li r6,16
	ctx.r6.s64 = 16;
loc_822BB294:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// addi r9,r9,-32
	ctx.r9.s64 = ctx.r9.s64 + -32;
	// addi r8,r11,-32
	ctx.r8.s64 = r11.s64 + -32;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r8,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x822bb294
	if (!cr0.eq) goto loc_822BB294;
loc_822BB2BC:
	// lhz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// sth r9,4(r7)
	PPC_STORE_U16(ctx.r7.u32 + 4, ctx.r9.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BB2D8"))) PPC_WEAK_FUNC(sub_822BB2D8);
PPC_FUNC_IMPL(__imp__sub_822BB2D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lhz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bb318
	if (cr6.eq) goto loc_822BB318;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r9,r9,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822bb320
	if (!cr6.eq) goto loc_822BB320;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// blr 
	return;
loc_822BB318:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_822BB320:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BB330"))) PPC_WEAK_FUNC(sub_822BB330);
PPC_FUNC_IMPL(__imp__sub_822BB330) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lhz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bb384
	if (cr6.eq) goto loc_822BB384;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r9,r9,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822bb36c
	if (cr6.eq) goto loc_822BB36C;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mulli r10,r4,28
	ctx.r10.s64 = ctx.r4.s64 * 28;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_822BB36C:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// mulli r10,r4,28
	ctx.r10.s64 = ctx.r4.s64 * 28;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_822BB384:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// mulli r10,r4,28
	ctx.r10.s64 = ctx.r4.s64 * 28;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BB39C"))) PPC_WEAK_FUNC(sub_822BB39C);
PPC_FUNC_IMPL(__imp__sub_822BB39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BB3A0"))) PPC_WEAK_FUNC(sub_822BB3A0);
PPC_FUNC_IMPL(__imp__sub_822BB3A0) {
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
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bb3d0
	if (cr6.eq) goto loc_822BB3D0;
	// bl 0x821c4458
	ctx.lr = 0x822BB3CC;
	sub_821C4458(ctx, base);
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
loc_822BB3D0:
	// lwz r4,300(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822bb3ec
	if (cr6.eq) goto loc_822BB3EC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,18180
	ctx.r3.s64 = r11.s64 + 18180;
	// bl 0x822bb208
	ctx.lr = 0x822BB3E8;
	sub_822BB208(ctx, base);
	// stw r30,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r30.u32);
loc_822BB3EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd258
	ctx.lr = 0x822BB3F4;
	sub_826FD258(ctx, base);
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

__attribute__((alias("__imp__sub_822BB40C"))) PPC_WEAK_FUNC(sub_822BB40C);
PPC_FUNC_IMPL(__imp__sub_822BB40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BB410"))) PPC_WEAK_FUNC(sub_822BB410);
PPC_FUNC_IMPL(__imp__sub_822BB410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// bl 0x826fc5a8
	ctx.lr = 0x822BB428;
	sub_826FC5A8(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,192
	ctx.r9.s64 = 192;
	// li r11,0
	r11.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r11.u32);
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r11,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r11.u32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,224(r31)
	PPC_STORE_U32(r31.u32 + 224, ctx.r8.u32);
	// stw r11,408(r31)
	PPC_STORE_U32(r31.u32 + 408, r11.u32);
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

__attribute__((alias("__imp__sub_822BB470"))) PPC_WEAK_FUNC(sub_822BB470);
PPC_FUNC_IMPL(__imp__sub_822BB470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,48(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x822a8d98
	ctx.lr = 0x822BB494;
	sub_822A8D98(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r11,-30048
	ctx.r3.s64 = r11.s64 + -30048;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x822BB4A8;
	sub_82130000(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r10,18180
	ctx.r3.s64 = ctx.r10.s64 + 18180;
	// bl 0x822bb1a0
	ctx.lr = 0x822BB4B4;
	sub_822BB1A0(ctx, base);
	// stw r3,300(r31)
	PPC_STORE_U32(r31.u32 + 300, ctx.r3.u32);
	// bl 0x8254ce70
	ctx.lr = 0x822BB4BC;
	sub_8254CE70(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x822BB4CC;
	sub_8255B9A8(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r6,300(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,16
	ctx.r4.s64 = 16;
	// li r11,25168
	r11.s64 = 25168;
	// lfs f0,3732(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r3,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r6,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r11,104(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bb51c
	if (!cr6.eq) goto loc_822BB51C;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r11,r11,-32416
	r11.s64 = r11.s64 + -32416;
loc_822BB51C:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,664(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822bb560
	if (cr6.eq) goto loc_822BB560;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb560
	if (cr6.eq) goto loc_822BB560;
	// lwz r8,300(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,25292(r8)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r8.u32 + 25292, temp.u32);
	// stfs f13,25296(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 25296, temp.u32);
	// stfs f0,25300(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 25300, temp.u32);
loc_822BB560:
	// lwz r11,668(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 668);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822bb594
	if (cr6.eq) goto loc_822BB594;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb594
	if (cr6.eq) goto loc_822BB594;
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,25308(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 25308, temp.u32);
	// stfs f13,25312(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 25312, temp.u32);
	// stfs f0,25316(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 25316, temp.u32);
loc_822BB594:
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822BB5AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r6,300(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,-31128(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31128);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f13,25324(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 25324, temp.u32);
	// lwz r31,48(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f12,25328(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 25328, temp.u32);
	// bl 0x822a8d98
	ctx.lr = 0x822BB5DC;
	sub_822A8D98(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r4,-30100
	ctx.r3.s64 = ctx.r4.s64 + -30100;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x822BB5F0;
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

__attribute__((alias("__imp__sub_822BB608"))) PPC_WEAK_FUNC(sub_822BB608);
PPC_FUNC_IMPL(__imp__sub_822BB608) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,48(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x822a8d98
	ctx.lr = 0x822BB62C;
	sub_822A8D98(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r11,-30008
	ctx.r3.s64 = r11.s64 + -30008;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x822BB640;
	sub_82130000(ctx, base);
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bb658
	if (cr6.eq) goto loc_822BB658;
	// bl 0x821c4458
	ctx.lr = 0x822BB654;
	sub_821C4458(ctx, base);
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
loc_822BB658:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd2b8
	ctx.lr = 0x822BB660;
	sub_826FD2B8(ctx, base);
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb68c
	if (cr6.eq) goto loc_822BB68C;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r10,-32416
	ctx.r8.s64 = ctx.r10.s64 + -32416;
	// addi r3,r9,18180
	ctx.r3.s64 = ctx.r9.s64 + 18180;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lwz r4,300(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x822bb208
	ctx.lr = 0x822BB688;
	sub_822BB208(ctx, base);
	// stw r30,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r30.u32);
loc_822BB68C:
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

__attribute__((alias("__imp__sub_822BB6A4"))) PPC_WEAK_FUNC(sub_822BB6A4);
PPC_FUNC_IMPL(__imp__sub_822BB6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BB6A8"))) PPC_WEAK_FUNC(sub_822BB6A8);
PPC_FUNC_IMPL(__imp__sub_822BB6A8) {
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
	// bl 0x823d91f0
	ctx.lr = 0x822BB6B0;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d8
	ctx.lr = 0x822BB6B8;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f13,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822bb6f4
	if (!cr6.gt) goto loc_822BB6F4;
	// li r30,0
	r30.s64 = 0;
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// b 0x822bbb40
	goto loc_822BBB40;
loc_822BB6F4:
	// bl 0x822a8108
	ctx.lr = 0x822BB6F8;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// lvx128 v127,r3,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x8254c888
	ctx.lr = 0x822BB708;
	sub_8254C888(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v63,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x822BB724;
	sub_822A8108(ctx, base);
	// addi r8,r3,32
	ctx.r8.s64 = ctx.r3.s64 + 32;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v61,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x822BB748;
	sub_8216C9C0(ctx, base);
	// lbz r6,337(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 337);
	// li r27,1
	r27.s64 = 1;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x822bb780
	if (!cr6.eq) goto loc_822BB780;
	// lbz r11,338(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 338);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bb778
	if (!cr6.eq) goto loc_822BB778;
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822bb780
	if (cr6.eq) goto loc_822BB780;
loc_822BB778:
	// mr r11,r30
	r11.u64 = r30.u64;
	// b 0x822bb784
	goto loc_822BB784;
loc_822BB780:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822BB784:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,332(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// li r26,2
	r26.s64 = 2;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f28,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f28.f64 = double(temp.f32);
	// bne cr6,0x822bb80c
	if (!cr6.eq) goto loc_822BB80C;
	// fabs f13,f31
	ctx.f13.u64 = f31.u64 & ~0x8000000000000000;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-28412(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28412);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822bb7f8
	if (!cr6.gt) goto loc_822BB7F8;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BB7BC;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lwz r4,300(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8254c8c0
	ctx.lr = 0x822BB7D0;
	sub_8254C8C0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v58,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x822BB7F0;
	sub_8216C9C0(ctx, base);
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f28.f64);
	// b 0x822bb7fc
	goto loc_822BB7FC;
loc_822BB7F8:
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f28.f64);
loc_822BB7FC:
	// mr r11,r27
	r11.u64 = r27.u64;
	// bge cr6,0x822bb808
	if (!cr6.lt) goto loc_822BB808;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_822BB808:
	// stw r11,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r11.u32);
loc_822BB80C:
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,18204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	f30.f64 = double(temp.f32);
	// bne cr6,0x822bb990
	if (!cr6.eq) goto loc_822BB990;
	// clrlwi r28,r28,24
	r28.u64 = r28.u32 & 0xFF;
	// lis r29,-1
	r29.s64 = -65536;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822bb868
	if (cr6.eq) goto loc_822BB868;
	// fadds f0,f31,f30
	f0.f64 = double(float(f31.f64 + f30.f64));
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsel f1,f31,f31,f0
	ctx.f1.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// bl 0x822ba070
	ctx.lr = 0x822BB84C;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb868
	if (cr6.eq) goto loc_822BB868;
	// stw r27,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r27.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// stb r27,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r27.u8);
	// b 0x822bbb04
	goto loc_822BBB04;
loc_822BB868:
	// fadds f0,f31,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 + f30.f64));
	// lis r7,-256
	ctx.r7.s64 = -16777216;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r7,r7,255
	ctx.r7.u64 = ctx.r7.u64 | 255;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsel f29,f31,f31,f0
	f29.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x822ba070
	ctx.lr = 0x822BB88C;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb8a4
	if (cr6.eq) goto loc_822BB8A4;
	// stw r27,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r27.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// b 0x822bbb00
	goto loc_822BBB00;
loc_822BB8A4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x822bb8e0
	if (!cr6.eq) goto loc_822BB8E0;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba070
	ctx.lr = 0x822BB8C4;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb8e0
	if (cr6.eq) goto loc_822BB8E0;
	// stw r27,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r27.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// stb r27,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r27.u8);
	// b 0x822bbb04
	goto loc_822BBB04;
loc_822BB8E0:
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// lis r7,-256
	ctx.r7.s64 = -16777216;
	// fsubs f13,f31,f30
	ctx.f13.f64 = double(float(f31.f64 - f30.f64));
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r7,r7,65280
	ctx.r7.u64 = ctx.r7.u64 | 65280;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsel f30,f0,f31,f13
	f30.f64 = f0.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x822ba070
	ctx.lr = 0x822BB908;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb924
	if (cr6.eq) goto loc_822BB924;
	// stw r26,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r26.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// stb r27,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r27.u8);
	// b 0x822bbb04
	goto loc_822BBB04;
loc_822BB924:
	// li r7,-16436
	ctx.r7.s64 = -16436;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba070
	ctx.lr = 0x822BB93C;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb954
	if (cr6.eq) goto loc_822BB954;
	// stw r26,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r26.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// b 0x822bbb00
	goto loc_822BBB00;
loc_822BB954:
	// li r7,-256
	ctx.r7.s64 = -256;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba070
	ctx.lr = 0x822BB96C;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// stb r27,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r27.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r30,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r30.u8);
	// beq cr6,0x822bb988
	if (cr6.eq) goto loc_822BB988;
	// stw r27,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r27.u32);
	// b 0x822bbb04
	goto loc_822BBB04;
loc_822BB988:
	// stw r30,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r30.u32);
	// b 0x822bbb04
	goto loc_822BBB04;
loc_822BB990:
	// clrlwi r29,r28,24
	r29.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822bb9dc
	if (cr6.eq) goto loc_822BB9DC;
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// lis r7,-96
	ctx.r7.s64 = -6291456;
	// fsubs f13,f31,f30
	ctx.f13.f64 = double(float(f31.f64 - f30.f64));
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r7,r7,8687
	ctx.r7.u64 = ctx.r7.u64 | 8687;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsel f1,f0,f31,f13
	ctx.f1.f64 = f0.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// bl 0x822ba070
	ctx.lr = 0x822BB9C0;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bb9dc
	if (cr6.eq) goto loc_822BB9DC;
	// stw r26,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r26.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// stb r27,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r27.u8);
	// b 0x822bbb04
	goto loc_822BBB04;
loc_822BB9DC:
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// lis r7,-91
	ctx.r7.s64 = -5963776;
	// fsubs f13,f31,f30
	ctx.f13.f64 = double(float(f31.f64 - f30.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r7,r7,10280
	ctx.r7.u64 = ctx.r7.u64 | 10280;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsel f29,f0,f31,f13
	f29.f64 = f0.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x822ba070
	ctx.lr = 0x822BBA04;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bba1c
	if (cr6.eq) goto loc_822BBA1C;
	// stw r26,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r26.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// b 0x822bbb00
	goto loc_822BBB00;
loc_822BBA1C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x822bba5c
	if (!cr6.eq) goto loc_822BBA5C;
	// lis r7,-96
	ctx.r7.s64 = -6291456;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// ori r7,r7,8687
	ctx.r7.u64 = ctx.r7.u64 | 8687;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba070
	ctx.lr = 0x822BBA40;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bba5c
	if (cr6.eq) goto loc_822BBA5C;
	// stw r26,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r26.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// stb r27,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r27.u8);
	// b 0x822bbb04
	goto loc_822BBB04;
loc_822BBA5C:
	// fadds f0,f31,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 + f30.f64));
	// li r7,-23296
	ctx.r7.s64 = -23296;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsel f30,f31,f31,f0
	f30.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x822ba070
	ctx.lr = 0x822BBA7C;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bba98
	if (cr6.eq) goto loc_822BBA98;
	// stw r27,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r27.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// stb r27,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r27.u8);
	// b 0x822bbb04
	goto loc_822BBB04;
loc_822BBA98:
	// lis r7,-256
	ctx.r7.s64 = -16777216;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r7,r7,62719
	ctx.r7.u64 = ctx.r7.u64 | 62719;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba070
	ctx.lr = 0x822BBAB4;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bbacc
	if (cr6.eq) goto loc_822BBACC;
	// stw r27,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r27.u32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// b 0x822bbb00
	goto loc_822BBB00;
loc_822BBACC:
	// li r7,-1
	ctx.r7.s64 = -1;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba070
	ctx.lr = 0x822BBAE4;
	sub_822BA070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// stb r27,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r27.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bbafc
	if (cr6.eq) goto loc_822BBAFC;
	// stw r26,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r26.u32);
	// b 0x822bbb00
	goto loc_822BBB00;
loc_822BBAFC:
	// stw r30,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r30.u32);
loc_822BBB00:
	// stb r30,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r30.u8);
loc_822BBB04:
	// lbz r11,336(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bbb44
	if (!cr6.eq) goto loc_822BBB44;
	// fabs f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 & ~0x8000000000000000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822bbb44
	if (!cr6.lt) goto loc_822BBB44;
	// fcmpu cr6,f31,f28
	cr6.compare(f31.f64, f28.f64);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bge cr6,0x822bbb34
	if (!cr6.lt) goto loc_822BBB34;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_822BBB34:
	// lwz r10,332(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x822bbb44
	if (!cr6.eq) goto loc_822BBB44;
loc_822BBB40:
	// stw r30,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r30.u32);
loc_822BBB44:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x822BBB58;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822BBB5C"))) PPC_WEAK_FUNC(sub_822BBB5C);
PPC_FUNC_IMPL(__imp__sub_822BBB5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BBB60"))) PPC_WEAK_FUNC(sub_822BBB60);
PPC_FUNC_IMPL(__imp__sub_822BBB60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f0{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91c4
	ctx.lr = 0x822BBB68;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823db9cc
	ctx.lr = 0x822BBB70;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = ctx.f1.f64;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// fmr f28,f2
	f28.f64 = ctx.f2.f64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// lwz r3,-3660(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3660);
	// mr r16,r8
	r16.u64 = ctx.r8.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// bl 0x8226a798
	ctx.lr = 0x822BBBA0;
	sub_8226A798(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bbed8
	if (cr6.eq) goto loc_822BBED8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f26,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f26.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f29,31292(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31292);
	f29.f64 = double(temp.f32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f27,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	f27.f64 = double(temp.f32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f30,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f30.f64 = double(temp.f32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lfs f31,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// li r18,1
	r18.s64 = 1;
	// addi r25,r11,-31664
	r25.s64 = r11.s64 + -31664;
	// addi r24,r10,-31648
	r24.s64 = ctx.r10.s64 + -31648;
	// addi r23,r9,2240
	r23.s64 = ctx.r9.s64 + 2240;
	// addi r22,r8,2528
	r22.s64 = ctx.r8.s64 + 2528;
	// addi r21,r7,2352
	r21.s64 = ctx.r7.s64 + 2352;
	// addi r20,r6,2384
	r20.s64 = ctx.r6.s64 + 2384;
loc_822BBC08:
	// lwz r11,300(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bbed8
	if (cr6.eq) goto loc_822BBED8;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lbz r26,6(r31)
	r26.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x822bbecc
	if (cr6.eq) goto loc_822BBECC;
	// rlwinm r11,r26,27,5,31
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r26,27
	ctx.r10.u64 = r26.u32 & 0x1F;
	// addi r9,r11,102
	ctx.r9.s64 = r11.s64 + 102;
	// slw r8,r18,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r18.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r27
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r27.u32);
	// and r5,r8,r6
	ctx.r5.u64 = ctx.r8.u64 & ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x822bbecc
	if (!cr6.eq) goto loc_822BBECC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BBC60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822BBC78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r30,48
	r29.s64 = r30.s64 + 48;
	// lvx128 v62,r0,r17
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822BBCB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lfs f7,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f11
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f5,8(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// lfs f2,4(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// fsel f8,f12,f0,f13
	ctx.f8.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fmadds f11,f5,f10,f6
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f6.f64));
	// fmadds f10,f7,f1,f3
	ctx.f10.f64 = double(float(ctx.f7.f64 * ctx.f1.f64 + ctx.f3.f64));
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f8,f30,f28
	f0.f64 = double(float(ctx.f8.f64 * f30.f64 + f28.f64));
	// fmadds f13,f2,f9,f11
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f12,f2,f12,f10
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f12.f64 + ctx.f10.f64));
	// fneg f8,f0
	ctx.f8.u64 = f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f13,f8
	cr6.compare(ctx.f13.f64, ctx.f8.f64);
	// blt cr6,0x822bbecc
	if (cr6.lt) goto loc_822BBECC;
	// fcmpu cr6,f12,f25
	cr6.compare(ctx.f12.f64, f25.f64);
	// ble cr6,0x822bbd24
	if (!cr6.gt) goto loc_822BBD24;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822bbecc
	if (cr6.gt) goto loc_822BBECC;
loc_822BBD24:
	// fsubs f0,f25,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f25.f64 - f27.f64));
	// mr r11,r18
	r11.u64 = r18.u64;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x822bbd38
	if (cr6.gt) goto loc_822BBD38;
	// li r11,0
	r11.s64 = 0;
loc_822BBD38:
	// lvx128 v59,r0,r16
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,300(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 300);
	// vsubfp128 v57,v58,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// lfs f13,25424(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 25424);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,25428(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 25428);
	f0.f64 = double(temp.f32);
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fabs f11,f12
	ctx.f11.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bgt cr6,0x822bbecc
	if (cr6.gt) goto loc_822BBECC;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
	// fmuls f12,f13,f13
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f13,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x822bbecc
	if (cr6.gt) goto loc_822BBECC;
	// lwz r11,128(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
loc_822BBD98:
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x822bbdc0
	if (!cr6.lt) goto loc_822BBDC0;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// subf r6,r7,r31
	ctx.r6.s64 = r31.s64 - ctx.r7.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r7,r5,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822bbd98
	if (cr6.eq) goto loc_822BBD98;
loc_822BBDC0:
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bbecc
	if (!cr6.eq) goto loc_822BBECC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f31,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stfs f26,144(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r15,r1,192
	r15.s64 = ctx.r1.s64 + 192;
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stw r11,128(r28)
	PPC_STORE_U32(r28.u32 + 128, r11.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stwx r31,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, r31.u32);
	// lfs f13,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,32(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	f0.f64 = double(temp.f32);
	// fneg f11,f0
	ctx.f11.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lvx128 v60,r0,r22
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r3,300(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 300);
	// lvx128 v0,r0,r23
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v54,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v13,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v59,r0,r24
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cntlzw r10,r26
	ctx.r10.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// lvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lvx128 v61,r0,r21
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v11,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// stfs f29,160(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f29,164(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f29,168(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v53,r0,r4
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stfs f31,180(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v62,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vrsqrtefp128 v55,v56
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v12,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vand128 v52,v56,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stfs f10,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// vand128 v51,v53,v63
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stfs f9,184(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// vor128 v50,v52,v61
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vcmpgtfp128 v5,v50,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// vcmpeqfp128 v10,v55,v60
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v60.f32)));
	// vor128 v9,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vsel v0,v9,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v59,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v12,v8,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v6,v7,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v3,v4,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(v62.f32)));
	// vsel v0,v11,v3,v5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// vsubfp128 v49,v54,v0
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8254b030
	ctx.lr = 0x822BBECC;
	sub_8254B030(ctx, base);
loc_822BBECC:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822bbc08
	if (!cr6.eq) goto loc_822BBC08;
loc_822BBED8:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823dba18
	ctx.lr = 0x822BBEE4;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_822BBEE8"))) PPC_WEAK_FUNC(sub_822BBEE8);
PPC_FUNC_IMPL(__imp__sub_822BBEE8) {
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
	ctx.lr = 0x822BBEF0;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bbf20
	if (cr6.eq) goto loc_822BBF20;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x822bbf2c
	goto loc_822BBF2C;
loc_822BBF20:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
loc_822BBF2C:
	// clrlwi r25,r5,24
	r25.u64 = ctx.r5.u32 & 0xFF;
	// lwz r26,0(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822bbf44
	if (cr6.eq) goto loc_822BBF44;
	// lwz r27,36(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// b 0x822bbf48
	goto loc_822BBF48;
loc_822BBF44:
	// lwz r27,40(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_822BBF48:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822bc350
	if (cr6.eq) goto loc_822BC350;
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// beq cr6,0x822bc350
	if (cr6.eq) goto loc_822BC350;
	// lwz r11,48(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 48);
	// rlwinm r10,r27,22,15,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 22) & 0x1FFFC;
	// clrlwi r28,r27,20
	r28.u64 = r27.u32 & 0xFFF;
	// lwzx r29,r10,r11
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822bb2d8
	ctx.lr = 0x822BBF70;
	sub_822BB2D8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bc350
	if (cr6.eq) goto loc_822BC350;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822bb330
	ctx.lr = 0x822BBF88;
	sub_822BB330(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lhz r10,80(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bbfbc
	if (cr6.eq) goto loc_822BBFBC;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x822bbfc4
	if (!cr6.eq) goto loc_822BBFC4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x822bbfc4
	goto loc_822BBFC4;
loc_822BBFBC:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_822BBFC4:
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r5,r29,16
	ctx.r5.s64 = r29.s64 + 16;
	// bl 0x8254fb60
	ctx.lr = 0x822BBFD4;
	sub_8254FB60(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r30,-1
	r30.s64 = -1;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,0
	r11.s64 = 0;
	// lfs f11,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// lfs f10,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-31380(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31380);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f10,f11
	ctx.f10.f64 = ctx.f11.f64;
	// lfs f9,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f6.f64 = double(temp.f32);
	// blt cr6,0x822bc194
	if (cr6.lt) goto loc_822BC194;
	// addi r7,r3,-3
	ctx.r7.s64 = ctx.r3.s64 + -3;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r1,216
	ctx.r9.s64 = ctx.r1.s64 + 216;
loc_822BC060:
	// lfs f0,-24(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -24);
	f0.f64 = double(temp.f32);
	// fsubs f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f13,-16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f9,f13
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f12,f5,f5,f4
	ctx.f12.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x822bc088
	if (!cr6.lt) goto loc_822BC088;
	// mr r30,r11
	r30.u64 = r11.u64;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
loc_822BC088:
	// fsubs f0,f6,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsubs f13,f7,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f0,f13,f13,f12
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x822bc0a8
	if (!cr6.lt) goto loc_822BC0A8;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_822BC0A8:
	// lfs f0,-8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	f0.f64 = double(temp.f32);
	// fsubs f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f13,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f9,f13
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f12,f5,f5,f4
	ctx.f12.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x822bc0d0
	if (!cr6.lt) goto loc_822BC0D0;
	// addi r30,r10,-1
	r30.s64 = ctx.r10.s64 + -1;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
loc_822BC0D0:
	// fsubs f0,f6,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsubs f13,f7,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f0,f13,f13,f12
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x822bc0f0
	if (!cr6.lt) goto loc_822BC0F0;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_822BC0F0:
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fsubs f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f13,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f9,f13
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f12,f5,f5,f4
	ctx.f12.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x822bc118
	if (!cr6.lt) goto loc_822BC118;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
loc_822BC118:
	// fsubs f0,f6,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsubs f13,f7,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f0,f13,f13,f12
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x822bc138
	if (!cr6.lt) goto loc_822BC138;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_822BC138:
	// lfs f0,24(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	f0.f64 = double(temp.f32);
	// fsubs f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f13,32(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f9,f13
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f12,f5,f5,f4
	ctx.f12.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x822bc160
	if (!cr6.lt) goto loc_822BC160;
	// addi r30,r10,1
	r30.s64 = ctx.r10.s64 + 1;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
loc_822BC160:
	// fsubs f0,f6,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsubs f13,f7,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f0,f13,f13,f12
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x822bc180
	if (!cr6.lt) goto loc_822BC180;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_822BC180:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x822bc060
	if (cr6.lt) goto loc_822BC060;
loc_822BC194:
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bge cr6,0x822bc200
	if (!cr6.lt) goto loc_822BC200;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_822BC1A8:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f9,f13
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f12,f5,f5,f4
	ctx.f12.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x822bc1d0
	if (!cr6.lt) goto loc_822BC1D0;
	// mr r30,r11
	r30.u64 = r11.u64;
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
loc_822BC1D0:
	// fsubs f0,f6,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsubs f13,f7,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f0,f13,f13,f12
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x822bc1f0
	if (!cr6.lt) goto loc_822BC1F0;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_822BC1F0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x822bc1a8
	if (cr6.lt) goto loc_822BC1A8;
loc_822BC200:
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x822bc214
	if (!cr6.eq) goto loc_822BC214;
	// subfic r11,r8,3
	xer.ca = ctx.r8.u32 <= 3;
	r11.s64 = 3 - ctx.r8.s64;
	// subf r31,r30,r11
	r31.s64 = r11.s64 - r30.s64;
	// b 0x822bc248
	goto loc_822BC248;
loc_822BC214:
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,257
	ctx.r10.s64 = 16842752;
	// or r9,r11,r8
	ctx.r9.u64 = r11.u64 | ctx.r8.u64;
	// or r8,r11,r8
	ctx.r8.u64 = r11.u64 | ctx.r8.u64;
	// lis r7,6735
	ctx.r7.s64 = 441384960;
	// ori r6,r10,600
	ctx.r6.u64 = ctx.r10.u64 | 600;
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r8,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r3,r7,46012
	ctx.r3.u64 = ctx.r7.u64 | 46012;
	// sraw r11,r6,r5
	temp.u32 = ctx.r5.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r6.s32 < 0) & (((ctx.r6.s32 >> temp.u32) << temp.u32) != ctx.r6.s32);
	r11.s64 = ctx.r6.s32 >> temp.u32;
	// sraw r10,r3,r4
	temp.u32 = ctx.r4.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	ctx.r10.s64 = ctx.r3.s32 >> temp.u32;
	// clrlwi r30,r11,30
	r30.u64 = r11.u32 & 0x3;
	// clrlwi r31,r10,30
	r31.u64 = ctx.r10.u32 & 0x3;
loc_822BC248:
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8254f388
	ctx.lr = 0x822BC258;
	sub_8254F388(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8254f478
	ctx.lr = 0x822BC268;
	sub_8254F478(ctx, base);
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// rlwinm r8,r31,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r10,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// vsubfp128 v59,v61,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// li r11,1
	r11.s64 = 1;
	// lvx128 v60,r8,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v60,v63
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// lfs f31,3796(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f0.f64 = double(temp.f32);
	// stvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmsubs f9,f13,f0,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * f0.f64 - ctx.f10.f64));
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// blt cr6,0x822bc2d0
	if (cr6.lt) goto loc_822BC2D0;
	// li r11,0
	r11.s64 = 0;
loc_822BC2D0:
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// beq cr6,0x822bc2e4
	if (cr6.eq) goto loc_822BC2E4;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r30,r31
	r30.u64 = r31.u64;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_822BC2E4:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BC2FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bc318
	if (cr6.eq) goto loc_822BC318;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bc31c
	if (!cr6.eq) goto loc_822BC31C;
loc_822BC318:
	// li r11,0
	r11.s64 = 0;
loc_822BC31C:
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lwz r3,300(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 300);
	// rlwinm r9,r31,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// rlwinm r7,r30,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// lvx128 v3,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r9,r8
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r7,r5
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8254adf0
	ctx.lr = 0x822BC350;
	sub_8254ADF0(ctx, base);
loc_822BC350:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822BC35C"))) PPC_WEAK_FUNC(sub_822BC35C);
PPC_FUNC_IMPL(__imp__sub_822BC35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BC360"))) PPC_WEAK_FUNC(sub_822BC360);
PPC_FUNC_IMPL(__imp__sub_822BC360) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822BC368;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bc394
	if (cr6.eq) goto loc_822BC394;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x822bc3a0
	goto loc_822BC3A0;
loc_822BC394:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
loc_822BC3A0:
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r27,16(r4)
	r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822bc4f8
	if (cr6.eq) goto loc_822BC4F8;
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// beq cr6,0x822bc4f8
	if (cr6.eq) goto loc_822BC4F8;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// rlwinm r10,r27,22,15,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 22) & 0x1FFFC;
	// clrlwi r28,r27,20
	r28.u64 = r27.u32 & 0xFFF;
	// lwzx r31,r10,r11
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bb2d8
	ctx.lr = 0x822BC3D0;
	sub_822BB2D8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bc4f8
	if (cr6.eq) goto loc_822BC4F8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bb330
	ctx.lr = 0x822BC3E8;
	sub_822BB330(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bc41c
	if (cr6.eq) goto loc_822BC41C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x822bc424
	if (!cr6.eq) goto loc_822BC424;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x822bc424
	goto loc_822BC424;
loc_822BC41C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_822BC424:
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// bl 0x8254fb60
	ctx.lr = 0x822BC434;
	sub_8254FB60(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8254f478
	ctx.lr = 0x822BC448;
	sub_8254F478(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BC460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bc47c
	if (cr6.eq) goto loc_822BC47C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bc480
	if (!cr6.eq) goto loc_822BC480;
loc_822BC47C:
	// li r11,0
	r11.s64 = 0;
loc_822BC480:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// lwz r3,300(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 300);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lvx128 v3,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lvx128 v2,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822bc4c8
	if (!cr6.eq) goto loc_822BC4C8;
	// bl 0x8254adf0
	ctx.lr = 0x822BC4C0;
	sub_8254ADF0(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// b 0x822bc4d0
	goto loc_822BC4D0;
loc_822BC4C8:
	// bl 0x8254adf0
	ctx.lr = 0x822BC4CC;
	sub_8254ADF0(ctx, base);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
loc_822BC4D0:
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v1,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lwz r3,300(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 300);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lvx128 v3,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8254adf0
	ctx.lr = 0x822BC4F8;
	sub_8254ADF0(ctx, base);
loc_822BC4F8:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822BC504"))) PPC_WEAK_FUNC(sub_822BC504);
PPC_FUNC_IMPL(__imp__sub_822BC504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BC508"))) PPC_WEAK_FUNC(sub_822BC508);
PPC_FUNC_IMPL(__imp__sub_822BC508) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822BC510;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r10,-31616
	ctx.r8.s64 = ctx.r10.s64 + -31616;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,656(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822bc550
	if (cr6.eq) goto loc_822BC550;
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x822bc55c
	goto loc_822BC55C;
loc_822BC550:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
loc_822BC55C:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r30,40(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bc5e4
	if (cr6.eq) goto loc_822BC5E4;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x822bc5e4
	if (cr6.eq) goto loc_822BC5E4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwinm r10,r30,22,15,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 22) & 0x1FFFC;
	// lwzx r28,r10,r11
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822bb2d8
	ctx.lr = 0x822BC58C;
	sub_822BB2D8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bc5a8
	if (cr6.eq) goto loc_822BC5A8;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// clrlwi r4,r30,20
	ctx.r4.u64 = r30.u32 & 0xFFF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8254f478
	ctx.lr = 0x822BC5A8;
	sub_8254F478(ctx, base);
loc_822BC5A8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BC5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bc5dc
	if (cr6.eq) goto loc_822BC5DC;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bc5e0
	if (!cr6.eq) goto loc_822BC5E0;
loc_822BC5DC:
	// li r11,0
	r11.s64 = 0;
loc_822BC5E0:
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
loc_822BC5E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,12(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f12,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f11,20(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f10,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lwz r3,300(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 300);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f8,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f10,144(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f9,148(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f8,152(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v3,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,32(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 32);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,28(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v2,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8254adf0
	ctx.lr = 0x822BC64C;
	sub_8254ADF0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822BC654"))) PPC_WEAK_FUNC(sub_822BC654);
PPC_FUNC_IMPL(__imp__sub_822BC654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BC658"))) PPC_WEAK_FUNC(sub_822BC658);
PPC_FUNC_IMPL(__imp__sub_822BC658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822BC670"))) PPC_WEAK_FUNC(sub_822BC670);
PPC_FUNC_IMPL(__imp__sub_822BC670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822b9fd0
	sub_822B9FD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BC680"))) PPC_WEAK_FUNC(sub_822BC680);
PPC_FUNC_IMPL(__imp__sub_822BC680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,208(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 208, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC694"))) PPC_WEAK_FUNC(sub_822BC694);
PPC_FUNC_IMPL(__imp__sub_822BC694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BC698"))) PPC_WEAK_FUNC(sub_822BC698);
PPC_FUNC_IMPL(__imp__sub_822BC698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,292(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 292, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC6AC"))) PPC_WEAK_FUNC(sub_822BC6AC);
PPC_FUNC_IMPL(__imp__sub_822BC6AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BC6B0"))) PPC_WEAK_FUNC(sub_822BC6B0);
PPC_FUNC_IMPL(__imp__sub_822BC6B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822bc6ec
	if (cr6.eq) goto loc_822BC6EC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r9,r11,18160
	ctx.r9.s64 = r11.s64 + 18160;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822bc6f0
	if (cr6.eq) goto loc_822BC6F0;
loc_822BC6EC:
	// li r11,0
	r11.s64 = 0;
loc_822BC6F0:
	// stb r11,236(r10)
	PPC_STORE_U8(ctx.r10.u32 + 236, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC6F8"))) PPC_WEAK_FUNC(sub_822BC6F8);
PPC_FUNC_IMPL(__imp__sub_822BC6F8) {
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
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822bc740
	if (!cr6.eq) goto loc_822BC740;
	// lwz r3,300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 300);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bc740
	if (cr6.eq) goto loc_822BC740;
	// bl 0x8254ca78
	ctx.lr = 0x822BC730;
	sub_8254CA78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822bc744
	if (!cr6.eq) goto loc_822BC744;
loc_822BC740:
	// li r11,0
	r11.s64 = 0;
loc_822BC744:
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

__attribute__((alias("__imp__sub_822BC764"))) PPC_WEAK_FUNC(sub_822BC764);
PPC_FUNC_IMPL(__imp__sub_822BC764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BC768"))) PPC_WEAK_FUNC(sub_822BC768);
PPC_FUNC_IMPL(__imp__sub_822BC768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,248(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 248, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC77C"))) PPC_WEAK_FUNC(sub_822BC77C);
PPC_FUNC_IMPL(__imp__sub_822BC77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BC780"))) PPC_WEAK_FUNC(sub_822BC780);
PPC_FUNC_IMPL(__imp__sub_822BC780) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r9,300(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 300);
	// stfs f0,25396(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 25396, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC798"))) PPC_WEAK_FUNC(sub_822BC798);
PPC_FUNC_IMPL(__imp__sub_822BC798) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r4,r7,24
	ctx.r4.u64 = ctx.r7.u32 & 0xFF;
	// b 0x822bb0c0
	sub_822BB0C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BC7B8"))) PPC_WEAK_FUNC(sub_822BC7B8);
PPC_FUNC_IMPL(__imp__sub_822BC7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,255(r9)
	PPC_STORE_U8(ctx.r9.u32 + 255, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC7D8"))) PPC_WEAK_FUNC(sub_822BC7D8);
PPC_FUNC_IMPL(__imp__sub_822BC7D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,257(r9)
	PPC_STORE_U8(ctx.r9.u32 + 257, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC7F8"))) PPC_WEAK_FUNC(sub_822BC7F8);
PPC_FUNC_IMPL(__imp__sub_822BC7F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,258(r9)
	PPC_STORE_U8(ctx.r9.u32 + 258, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC818"))) PPC_WEAK_FUNC(sub_822BC818);
PPC_FUNC_IMPL(__imp__sub_822BC818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,338(r9)
	PPC_STORE_U8(ctx.r9.u32 + 338, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BC838"))) PPC_WEAK_FUNC(sub_822BC838);
PPC_FUNC_IMPL(__imp__sub_822BC838) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822BC840;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// bl 0x826fd158
	ctx.lr = 0x822BC850;
	sub_826FD158(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-29956
	ctx.r9.s64 = r11.s64 + -29956;
	// li r30,0
	r30.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r8,r10,-30120
	ctx.r8.s64 = ctx.r10.s64 + -30120;
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
	// addi r3,r31,412
	ctx.r3.s64 = r31.s64 + 412;
	// sth r30,180(r31)
	PPC_STORE_U16(r31.u32 + 180, r30.u16);
	// addi r29,r31,176
	r29.s64 = r31.s64 + 176;
	// sth r30,182(r31)
	PPC_STORE_U16(r31.u32 + 182, r30.u16);
	// addi r28,r31,184
	r28.s64 = r31.s64 + 184;
	// stw r30,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r30.u32);
	// addi r27,r31,308
	r27.s64 = r31.s64 + 308;
	// sth r30,188(r31)
	PPC_STORE_U16(r31.u32 + 188, r30.u16);
	// sth r30,190(r31)
	PPC_STORE_U16(r31.u32 + 190, r30.u16);
	// stw r8,308(r31)
	PPC_STORE_U32(r31.u32 + 308, ctx.r8.u32);
	// stw r30,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r30.u32);
	// stw r30,316(r31)
	PPC_STORE_U32(r31.u32 + 316, r30.u32);
	// stw r30,320(r31)
	PPC_STORE_U32(r31.u32 + 320, r30.u32);
	// stw r30,408(r31)
	PPC_STORE_U32(r31.u32 + 408, r30.u32);
	// bl 0x82398fd8
	ctx.lr = 0x822BC8A8;
	sub_82398FD8(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
	// addi r5,r7,18160
	ctx.r5.s64 = ctx.r7.s64 + 18160;
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// li r11,-1
	r11.s64 = -1;
	// stw r30,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r30.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// lfs f0,14884(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stw r4,224(r31)
	PPC_STORE_U32(r31.u32 + 224, ctx.r4.u32);
	// stfs f0,240(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// stb r30,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r30.u8);
	// stfs f0,244(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 244, temp.u32);
	// stb r30,338(r31)
	PPC_STORE_U8(r31.u32 + 338, r30.u8);
	// stw r11,228(r31)
	PPC_STORE_U32(r31.u32 + 228, r11.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stw r11,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r11.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// cntlzw r6,r10
	ctx.r6.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lfs f13,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,3796(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r9,30
	ctx.r9.s64 = 30;
	// lfs f12,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// lfs f11,27640(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27640);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,248(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stb r30,252(r31)
	PPC_STORE_U8(r31.u32 + 252, r30.u8);
	// stfs f0,260(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// stw r9,264(r31)
	PPC_STORE_U32(r31.u32 + 264, ctx.r9.u32);
	// lfs f10,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// stw r9,268(r31)
	PPC_STORE_U32(r31.u32 + 268, ctx.r9.u32);
	// stfs f0,280(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// stb r4,236(r31)
	PPC_STORE_U8(r31.u32 + 236, ctx.r4.u8);
	// stfs f0,296(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 296, temp.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f0,384(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 384, temp.u32);
	// li r3,352
	ctx.r3.s64 = 352;
	// stfs f13,292(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 292, temp.u32);
	// stb r30,253(r31)
	PPC_STORE_U8(r31.u32 + 253, r30.u8);
	// stfs f0,388(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 388, temp.u32);
	// stb r30,254(r31)
	PPC_STORE_U8(r31.u32 + 254, r30.u8);
	// stfs f0,392(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 392, temp.u32);
	// stb r30,255(r31)
	PPC_STORE_U8(r31.u32 + 255, r30.u8);
	// stfs f0,396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// stb r30,256(r31)
	PPC_STORE_U8(r31.u32 + 256, r30.u8);
	// stfs f0,400(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 400, temp.u32);
	// stb r30,257(r31)
	PPC_STORE_U8(r31.u32 + 257, r30.u8);
	// stfs f0,344(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stb r30,258(r31)
	PPC_STORE_U8(r31.u32 + 258, r30.u8);
	// stfs f12,368(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 368, temp.u32);
	// stfs f11,376(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 376, temp.u32);
	// stw r30,300(r31)
	PPC_STORE_U32(r31.u32 + 300, r30.u32);
	// stfs f10,372(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 372, temp.u32);
	// stw r30,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r30.u32);
	// stw r11,328(r31)
	PPC_STORE_U32(r31.u32 + 328, r11.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// stb r30,380(r31)
	PPC_STORE_U8(r31.u32 + 380, r30.u8);
	// stvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
	// beq cr6,0x822bc9d4
	if (cr6.eq) goto loc_822BC9D4;
	// rlwinm r3,r26,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x822BC9B8;
	sub_82130528(ctx, base);
	// clrlwi r30,r26,16
	r30.u64 = r26.u32 & 0xFFFF;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// rlwinm r3,r26,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r30,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r30.u16);
	// bl 0x82130528
	ctx.lr = 0x822BC9CC;
	sub_82130528(ctx, base);
	// sth r30,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r30.u16);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
loc_822BC9D4:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,132
	ctx.r3.s64 = r31.s64 + 132;
	// bl 0x8254ab60
	ctx.lr = 0x822BC9E0;
	sub_8254AB60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822BC9EC"))) PPC_WEAK_FUNC(sub_822BC9EC);
PPC_FUNC_IMPL(__imp__sub_822BC9EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BC9F0"))) PPC_WEAK_FUNC(sub_822BC9F0);
PPC_FUNC_IMPL(__imp__sub_822BC9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BCA04"))) PPC_WEAK_FUNC(sub_822BCA04);
PPC_FUNC_IMPL(__imp__sub_822BCA04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BCA08"))) PPC_WEAK_FUNC(sub_822BCA08);
PPC_FUNC_IMPL(__imp__sub_822BCA08) {
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
	// addi r10,r11,-29956
	ctx.r10.s64 = r11.s64 + -29956;
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bca40
	if (cr6.eq) goto loc_822BCA40;
	// bl 0x821c4458
	ctx.lr = 0x822BCA38;
	sub_821C4458(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r11.u32);
loc_822BCA40:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,132
	ctx.r3.s64 = r31.s64 + 132;
	// bl 0x8254ab60
	ctx.lr = 0x822BCA4C;
	sub_8254AB60(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-30128
	ctx.r10.s64 = r11.s64 + -30128;
	// stw r10,308(r31)
	PPC_STORE_U32(r31.u32 + 308, ctx.r10.u32);
	// lhz r9,190(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 190);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822bca6c
	if (cr6.eq) goto loc_822BCA6C;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// bl 0x82130588
	ctx.lr = 0x822BCA6C;
	sub_82130588(ctx, base);
loc_822BCA6C:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bca80
	if (cr6.eq) goto loc_822BCA80;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x822BCA80;
	sub_82130588(ctx, base);
loc_822BCA80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fcdb0
	ctx.lr = 0x822BCA88;
	sub_826FCDB0(ctx, base);
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

__attribute__((alias("__imp__sub_822BCA9C"))) PPC_WEAK_FUNC(sub_822BCA9C);
PPC_FUNC_IMPL(__imp__sub_822BCA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BCAA0"))) PPC_WEAK_FUNC(sub_822BCAA0);
PPC_FUNC_IMPL(__imp__sub_822BCAA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826fce08
	ctx.lr = 0x822BCABC;
	sub_826FCE08(ctx, base);
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bcad4
	if (cr6.eq) goto loc_822BCAD4;
	// bl 0x821c4458
	ctx.lr = 0x822BCAD0;
	sub_821C4458(ctx, base);
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
loc_822BCAD4:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// addi r10,r31,176
	ctx.r10.s64 = r31.s64 + 176;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bcaec
	if (!cr6.eq) goto loc_822BCAEC;
	// sth r30,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r30.u16);
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
loc_822BCAEC:
	// sth r30,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, r30.u16);
	// addi r11,r31,184
	r11.s64 = r31.s64 + 184;
	// lhz r10,190(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 190);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bcb08
	if (!cr6.eq) goto loc_822BCB08;
	// sth r30,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r30.u16);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_822BCB08:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// sth r30,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r30.u16);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r30,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r30.u32);
	// stw r30,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r30.u32);
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,224(r31)
	PPC_STORE_U32(r31.u32 + 224, ctx.r8.u32);
	// stfs f0,292(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 292, temp.u32);
	// stb r30,252(r31)
	PPC_STORE_U8(r31.u32 + 252, r30.u8);
	// stfs f13,296(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 296, temp.u32);
	// stw r7,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_822BCB64"))) PPC_WEAK_FUNC(sub_822BCB64);
PPC_FUNC_IMPL(__imp__sub_822BCB64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BCB68"))) PPC_WEAK_FUNC(sub_822BCB68);
PPC_FUNC_IMPL(__imp__sub_822BCB68) {
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
	// li r30,0
	r30.s64 = 0;
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bcb98
	if (cr6.eq) goto loc_822BCB98;
	// bl 0x821c4458
	ctx.lr = 0x822BCB94;
	sub_821C4458(ctx, base);
	// stw r30,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r30.u32);
loc_822BCB98:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// addi r10,r31,176
	ctx.r10.s64 = r31.s64 + 176;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bcbb0
	if (!cr6.eq) goto loc_822BCBB0;
	// sth r30,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r30.u16);
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
loc_822BCBB0:
	// sth r30,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, r30.u16);
	// addi r11,r31,184
	r11.s64 = r31.s64 + 184;
	// lhz r10,190(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 190);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bcbcc
	if (!cr6.eq) goto loc_822BCBCC;
	// sth r30,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r30.u16);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_822BCBCC:
	// sth r30,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r30.u16);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// li r7,352
	ctx.r7.s64 = 352;
	// stw r30,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r30.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r30.u32);
	// li r9,30
	ctx.r9.s64 = 30;
	// stb r30,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r30.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r10.u32);
	// stfs f0,280(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// stw r10,232(r31)
	PPC_STORE_U32(r31.u32 + 232, ctx.r10.u32);
	// stfs f0,260(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// stb r30,337(r31)
	PPC_STORE_U8(r31.u32 + 337, r30.u8);
	// stfs f13,292(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 292, temp.u32);
	// stb r30,338(r31)
	PPC_STORE_U8(r31.u32 + 338, r30.u8);
	// stfs f0,296(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 296, temp.u32);
	// stw r6,224(r31)
	PPC_STORE_U32(r31.u32 + 224, ctx.r6.u32);
	// stfs f0,344(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stb r30,252(r31)
	PPC_STORE_U8(r31.u32 + 252, r30.u8);
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r9,264(r31)
	PPC_STORE_U32(r31.u32 + 264, ctx.r9.u32);
	// stw r9,268(r31)
	PPC_STORE_U32(r31.u32 + 268, ctx.r9.u32);
	// stb r30,254(r31)
	PPC_STORE_U8(r31.u32 + 254, r30.u8);
	// stb r30,255(r31)
	PPC_STORE_U8(r31.u32 + 255, r30.u8);
	// stb r30,257(r31)
	PPC_STORE_U8(r31.u32 + 257, r30.u8);
	// stb r30,258(r31)
	PPC_STORE_U8(r31.u32 + 258, r30.u8);
	// stw r30,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r30.u32);
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// stw r10,328(r31)
	PPC_STORE_U32(r31.u32 + 328, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,340(r31)
	PPC_STORE_U32(r31.u32 + 340, r30.u32);
	// beq cr6,0x822bcc6c
	if (cr6.eq) goto loc_822BCC6C;
	// bl 0x8254ce70
	ctx.lr = 0x822BCC6C;
	sub_8254CE70(ctx, base);
loc_822BCC6C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd818
	ctx.lr = 0x822BCC74;
	sub_826FD818(ctx, base);
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

__attribute__((alias("__imp__sub_822BCC8C"))) PPC_WEAK_FUNC(sub_822BCC8C);
PPC_FUNC_IMPL(__imp__sub_822BCC8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BCC90"))) PPC_WEAK_FUNC(sub_822BCC90);
PPC_FUNC_IMPL(__imp__sub_822BCC90) {
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
	ctx.lr = 0x822BCC98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,188(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bccb4
	if (!cr6.eq) goto loc_822BCCB4;
	// li r30,0
	r30.s64 = 0;
	// b 0x822bccf0
	goto loc_822BCCF0;
loc_822BCCB4:
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x822bccdc
	if (!cr6.eq) goto loc_822BCCDC;
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// rlwinm r9,r10,19,0,12
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0xFFF80000;
	// srawi r30,r9,25
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFFFFF) != 0);
	r30.s64 = ctx.r9.s32 >> 25;
	// b 0x822bccf0
	goto loc_822BCCF0;
loc_822BCCDC:
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// rlwinm r8,r9,19,0,12
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0xFFF80000;
	// srawi r30,r8,25
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFFFFF) != 0);
	r30.s64 = ctx.r8.s32 >> 25;
loc_822BCCF0:
	// lwz r3,324(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// bl 0x82267490
	ctx.lr = 0x822BCCF8;
	sub_82267490(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x822bcfd8
	if (!cr6.gt) goto loc_822BCFD8;
	// lwz r29,324(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// addi r6,r30,1
	ctx.r6.s64 = r30.s64 + 1;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
loc_822BCD14:
	// lwz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bgt cr6,0x822bcfd8
	if (cr6.gt) goto loc_822BCFD8;
	// lbz r11,13(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bcd64
	if (cr6.eq) goto loc_822BCD64;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// beq cr6,0x822bcd7c
	if (cr6.eq) goto loc_822BCD7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bae28
	ctx.lr = 0x822BCD3C;
	sub_822BAE28(ctx, base);
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bge cr6,0x822bcd64
	if (!cr6.lt) goto loc_822BCD64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822bcd64
	if (!cr6.eq) goto loc_822BCD64;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x822bce38
	if (cr6.eq) goto loc_822BCE38;
loc_822BCD64:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// cmpw cr6,r28,r4
	cr6.compare<int32_t>(r28.s32, ctx.r4.s32, xer);
	// blt cr6,0x822bcd14
	if (cr6.lt) goto loc_822BCD14;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822BCD7C:
	// lhz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bcd90
	if (!cr6.eq) goto loc_822BCD90;
	// li r11,0
	r11.s64 = 0;
	// b 0x822bcdc8
	goto loc_822BCDC8;
loc_822BCD90:
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r9,184(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x822bcdb8
	if (!cr6.eq) goto loc_822BCDB8;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// rlwinm r8,r9,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0xFC000000;
	// srawi r11,r8,28
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFFFF) != 0);
	r11.s64 = ctx.r8.s32 >> 28;
	// b 0x822bcdc8
	goto loc_822BCDC8;
loc_822BCDB8:
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// rlwinm r6,r7,26,0,5
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0xFC000000;
	// srawi r11,r6,28
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFFFFF) != 0);
	r11.s64 = ctx.r6.s32 >> 28;
loc_822BCDC8:
	// lwz r9,224(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822bcde8
	if (cr6.lt) goto loc_822BCDE8;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bge cr6,0x822bcfd8
	if (!cr6.lt) goto loc_822BCFD8;
loc_822BCDE8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bcdf8
	if (!cr6.eq) goto loc_822BCDF8;
	// li r11,0
	r11.s64 = 0;
	// b 0x822bce44
	goto loc_822BCE44;
loc_822BCDF8:
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x822bce20
	if (!cr6.eq) goto loc_822BCE20;
	// lwz r9,184(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// rlwinm r9,r10,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFC000000;
	// srawi r11,r9,28
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFFFFF) != 0);
	r11.s64 = ctx.r9.s32 >> 28;
	// b 0x822bce44
	goto loc_822BCE44;
loc_822BCE20:
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// rlwinm r7,r8,26,0,5
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0xFC000000;
	// srawi r11,r7,28
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFFFFF) != 0);
	r11.s64 = ctx.r7.s32 >> 28;
	// b 0x822bce44
	goto loc_822BCE44;
loc_822BCE38:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bae28
	ctx.lr = 0x822BCE40;
	sub_822BAE28(ctx, base);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
loc_822BCE44:
	// stw r11,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r11.u32);
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x822bcfd8
	if (cr6.eq) goto loc_822BCFD8;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// rlwinm r26,r28,4,0,27
	r26.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r30,r26,r11
	r30.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// stw r30,228(r31)
	PPC_STORE_U32(r31.u32 + 228, r30.u32);
	// bl 0x822a8d98
	ctx.lr = 0x822BCE68;
	sub_822A8D98(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r10,-29888
	ctx.r3.s64 = ctx.r10.s64 + -29888;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x822BCE7C;
	sub_82130000(ctx, base);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lhz r9,180(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// li r27,-1
	r27.s64 = -1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x822bcee8
	if (!cr6.lt) goto loc_822BCEE8;
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_822BCEA0:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r10,r8,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0xFC000000;
	// srawi r10,r10,28
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 28;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// bgt cr6,0x822bcee4
	if (cr6.gt) goto loc_822BCEE4;
	// bne cr6,0x822bcecc
	if (!cr6.eq) goto loc_822BCECC;
	// rlwinm r10,r8,19,0,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 19) & 0xFFF80000;
	// lwz r8,228(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// srawi r6,r10,25
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FFFFFF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 25;
	// cmpw cr6,r6,r8
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r8.s32, xer);
	// bge cr6,0x822bcee4
	if (!cr6.lt) goto loc_822BCEE4;
loc_822BCECC:
	// lhz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x822bcea0
	if (cr6.lt) goto loc_822BCEA0;
	// b 0x822bcee8
	goto loc_822BCEE8;
loc_822BCEE4:
	// mr r27,r11
	r27.u64 = r11.u64;
loc_822BCEE8:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// addi r28,r31,176
	r28.s64 = r31.s64 + 176;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bcf18
	if (!cr6.eq) goto loc_822BCF18;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r27,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r27.u16);
	// beq cr6,0x822bcf10
	if (cr6.eq) goto loc_822BCF10;
	// rlwinm r3,r27,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x822BCF0C;
	sub_82130528(ctx, base);
	// b 0x822bcf14
	goto loc_822BCF14;
loc_822BCF10:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822BCF14:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
loc_822BCF18:
	// clrlwi r29,r27,16
	r29.u64 = r27.u32 & 0xFFFF;
	// addi r30,r31,184
	r30.s64 = r31.s64 + 184;
	// sth r29,4(r28)
	PPC_STORE_U16(r28.u32 + 4, r29.u16);
	// lhz r11,190(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 190);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bcf50
	if (!cr6.eq) goto loc_822BCF50;
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822bcf48
	if (cr6.eq) goto loc_822BCF48;
	// rlwinm r3,r27,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x822BCF44;
	sub_82130528(ctx, base);
	// b 0x822bcf4c
	goto loc_822BCF4C;
loc_822BCF48:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822BCF4C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_822BCF50:
	// sth r29,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r29.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,228(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r5,232(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// bl 0x822baf18
	ctx.lr = 0x822BCF64;
	sub_822BAF18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,216(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// bl 0x826fd488
	ctx.lr = 0x822BCF70;
	sub_826FD488(ctx, base);
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bcf80
	if (cr6.eq) goto loc_822BCF80;
	// bl 0x8254b768
	ctx.lr = 0x822BCF80;
	sub_8254B768(ctx, base);
loc_822BCF80:
	// lwz r3,324(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// stw r30,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r30.u32);
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
	// lwz r10,228(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// lbz r11,12(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r10,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r10.u32);
	// bl 0x82640ad8
	ctx.lr = 0x822BCFAC;
	sub_82640AD8(ctx, base);
	// lwz r9,228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// blt cr6,0x822bcfd8
	if (cr6.lt) goto loc_822BCFD8;
	// lwz r3,324(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// bl 0x82640ad8
	ctx.lr = 0x822BCFC0;
	sub_82640AD8(ctx, base);
	// lwz r10,228(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// subf r9,r3,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r3.s64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r9,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r9.u32);
	// stw r8,232(r31)
	PPC_STORE_U32(r31.u32 + 232, ctx.r8.u32);
loc_822BCFD8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822BCFE0"))) PPC_WEAK_FUNC(sub_822BCFE0);
PPC_FUNC_IMPL(__imp__sub_822BCFE0) {
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
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91e4
	ctx.lr = 0x822BCFE8;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9c8
	ctx.lr = 0x822BCFF0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd9c4
	if (cr6.eq) goto loc_822BD9C4;
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bd020
	if (cr6.eq) goto loc_822BD020;
	// bl 0x821c4458
	ctx.lr = 0x822BD01C;
	sub_821C4458(ctx, base);
	// stw r25,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r25.u32);
loc_822BD020:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,248(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 248);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	ctx.f12.f64 = double(temp.f32);
	// mr r28,r25
	r28.u64 = r25.u64;
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f28,f31
	f28.f64 = f31.f64;
	// fmr f27,f31
	f27.f64 = f31.f64;
	// lfs f0,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r29,8(r7)
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f30,108(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r6,20(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fsel f9,f10,f31,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f31.f64 : ctx.f11.f64;
	// lwz r5,20(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// stfs f9,248(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// lfs f0,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// extsh r26,r5
	r26.s64 = ctx.r5.s16;
	// fsubs f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// fsel f6,f7,f31,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f31.f64 : ctx.f8.f64;
	// stfs f6,296(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 296, temp.u32);
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bgt cr6,0x822bd0ac
	if (cr6.gt) goto loc_822BD0AC;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
loc_822BD0AC:
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822bd0d8
	if (cr6.eq) goto loc_822BD0D8;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,96(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lfs f0,180(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 180);
	f0.f64 = double(temp.f32);
	// lfs f13,20(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f2,f0,f13
	ctx.f2.f64 = double(float(f0.f64 / ctx.f13.f64));
	// b 0x822bd0dc
	goto loc_822BD0DC;
loc_822BD0D8:
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
loc_822BD0DC:
	// extsh r27,r26
	r27.s64 = r26.s16;
	// addic. r4,r27,-2
	xer.ca = r27.u32 > 1;
	ctx.r4.s64 = r27.s64 + -2;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge 0x822bd0ec
	if (!cr0.lt) goto loc_822BD0EC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
loc_822BD0EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r23,r1,96
	r23.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,100
	ctx.r8.s64 = ctx.r1.s64 + 100;
	// bl 0x822b9ea0
	ctx.lr = 0x822BD104;
	sub_822B9EA0(ctx, base);
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x8254dcd0
	ctx.lr = 0x822BD118;
	sub_8254DCD0(ctx, base);
	// lbz r4,257(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 257);
	// stb r3,252(r31)
	PPC_STORE_U8(r31.u32 + 252, ctx.r3.u8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822bd140
	if (cr6.eq) goto loc_822BD140;
	// stfs f30,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// mr r28,r25
	r28.u64 = r25.u64;
	// fmr f10,f31
	ctx.f10.f64 = f31.f64;
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// b 0x822bd988
	goto loc_822BD988;
loc_822BD140:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,18060
	ctx.r10.s64 = r11.s64 + 18060;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bd4d4
	if (!cr6.eq) goto loc_822BD4D4;
	// lbz r11,254(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 254);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bd16c
	if (!cr6.eq) goto loc_822BD16C;
	// lfs f0,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 280);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822bd4d4
	if (!cr6.gt) goto loc_822BD4D4;
loc_822BD16C:
	// lfs f29,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f29.f64 = double(temp.f32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// addi r28,r31,276
	r28.s64 = r31.s64 + 276;
	// bl 0x825585a0
	ctx.lr = 0x822BD17C;
	sub_825585A0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f29.f64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f2,-30176(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30176);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x821ce490
	ctx.lr = 0x822BD190;
	sub_821CE490(ctx, base);
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,280(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 280);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,284(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 284);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 - f0.f64));
	// stfs f0,280(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x822bd3e0
	if (!cr6.lt) goto loc_822BD3E0;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822bd3d8
	if (!cr6.lt) goto loc_822BD3D8;
	// lfs f13,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,288(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 288);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822bd1cc
	if (cr6.lt) goto loc_822BD1CC;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822bd3d8
	if (!cr6.lt) goto loc_822BD3D8;
loc_822BD1CC:
	// lbz r11,254(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 254);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd2dc
	if (cr6.eq) goto loc_822BD2DC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8232c638
	ctx.lr = 0x822BD1E0;
	sub_8232C638(ctx, base);
	// lfs f0,256(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822bd308
	if (!cr6.gt) goto loc_822BD308;
	// lis r28,-32122
	r28.s64 = -2105147392;
	// lis r11,23772
	r11.s64 = 1557921792;
	// addi r27,r28,2192
	r27.s64 = r28.s64 + 2192;
	// ori r30,r11,64167
	r30.u64 = r11.u64 | 64167;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r7,2192(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 2192);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mulld r10,r7,r30
	ctx.r10.s64 = ctx.r7.s64 * r30.s64;
	// lfs f13,-29776(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29776);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r10,2192(r28)
	PPC_STORE_U32(r28.u32 + 2192, ctx.r10.u32);
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
	// stfs f0,288(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 288, temp.u32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f9,280(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// lwz r23,16(r29)
	r23.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x8232c638
	ctx.lr = 0x822BD258;
	sub_8232C638(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lfs f29,252(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 252);
	f29.f64 = double(temp.f32);
	// bl 0x82558520
	ctx.lr = 0x822BD268;
	sub_82558520(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f1.f64;
	// bl 0x82558508
	ctx.lr = 0x822BD274;
	sub_82558508(ctx, base);
	// lwz r8,2192(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 2192);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mulld r10,r8,r30
	ctx.r10.s64 = ctx.r8.s64 * r30.s64;
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = ctx.f1.f64;
	// lfs f0,-29780(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29780);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfd f8,112(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// stw r10,2192(r28)
	PPC_STORE_U32(r28.u32 + 2192, ctx.r10.u32);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
	// lfs f13,-13148(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f24,f6,f0,f13
	f24.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f13.f64));
	// bl 0x825584f0
	ctx.lr = 0x822BD2C8;
	sub_825584F0(ctx, base);
	// fsubs f5,f26,f25
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(f26.f64 - f25.f64));
	// fmadds f4,f5,f29,f25
	ctx.f4.f64 = double(float(ctx.f5.f64 * f29.f64 + f25.f64));
	// fsubs f3,f4,f1
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f1.f64));
	// fmadds f2,f3,f24,f1
	ctx.f2.f64 = double(float(ctx.f3.f64 * f24.f64 + ctx.f1.f64));
	// stfs f2,284(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 284, temp.u32);
loc_822BD2DC:
	// fmr f10,f30
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = f30.f64;
loc_822BD2E0:
	// lbz r10,255(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 255);
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// mr r28,r25
	r28.u64 = r25.u64;
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// b 0x822bd988
	goto loc_822BD988;
loc_822BD308:
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2192
	ctx.r7.s64 = ctx.r9.s64 + 2192;
	// ori r30,r8,64167
	r30.u64 = ctx.r8.u64 | 64167;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r3,2192(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2192);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r3,r30
	ctx.r10.s64 = ctx.r3.s64 * r30.s64;
	// lfs f0,14192(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f13,-29784(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29784);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29788(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29788);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// stfs f0,288(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 288, temp.u32);
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f11,-13148(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13148);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f8,280(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r4,2192(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2192);
	// mulld r10,r4,r30
	ctx.r10.s64 = ctx.r4.s64 * r30.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r29,16(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f7,112(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmadds f29,f5,f12,f11
	f29.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f11.f64));
	// bl 0x82558520
	ctx.lr = 0x822BD3BC;
	sub_82558520(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f1.f64;
	// bl 0x825584f0
	ctx.lr = 0x822BD3C8;
	sub_825584F0(ctx, base);
	// fsubs f4,f26,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f26.f64 - ctx.f1.f64));
	// fmadds f3,f4,f29,f1
	ctx.f3.f64 = double(float(ctx.f4.f64 * f29.f64 + ctx.f1.f64));
	// stfs f3,284(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 284, temp.u32);
	// b 0x822bd2dc
	goto loc_822BD2DC;
loc_822BD3D8:
	// fmr f10,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = f31.f64;
	// b 0x822bd2e0
	goto loc_822BD2E0;
loc_822BD3E0:
	// lbz r11,254(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 254);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd2dc
	if (cr6.eq) goto loc_822BD2DC;
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822bd2dc
	if (!cr6.lt) goto loc_822BD2DC;
	// lfs f0,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822bd2dc
	if (!cr6.gt) goto loc_822BD2DC;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2192
	ctx.r7.s64 = ctx.r9.s64 + 2192;
	// ori r30,r8,64167
	r30.u64 = ctx.r8.u64 | 64167;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r3,2192(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2192);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r3,r30
	ctx.r10.s64 = ctx.r3.s64 * r30.s64;
	// lfs f0,14348(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lfs f13,-29792(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29792);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14992(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14992);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f11,112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f8,280(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,2192(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2192);
	// mulld r10,r5,r30
	ctx.r10.s64 = ctx.r5.s64 * r30.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r29,16(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f7,112(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmadds f30,f5,f13,f12
	f30.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f12.f64));
	// bl 0x82558520
	ctx.lr = 0x822BD4A8;
	sub_82558520(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// bl 0x825584f0
	ctx.lr = 0x822BD4B4;
	sub_825584F0(ctx, base);
	// fsubs f4,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f29.f64 - ctx.f1.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fmr f10,f31
	ctx.f10.f64 = f31.f64;
	// lfs f0,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,284(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 284, temp.u32);
	// fmadds f3,f4,f30,f1
	ctx.f3.f64 = double(float(ctx.f4.f64 * f30.f64 + ctx.f1.f64));
	// stfs f3,288(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 288, temp.u32);
	// b 0x822bd2e0
	goto loc_822BD2E0;
loc_822BD4D4:
	// lwz r11,592(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 592);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822bd4f8
	if (!cr6.eq) goto loc_822BD4F8;
	// stfs f30,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmr f10,f30
	ctx.f10.f64 = f30.f64;
	// mr r28,r25
	r28.u64 = r25.u64;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// b 0x822bd988
	goto loc_822BD988;
loc_822BD4F8:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd900
	if (cr6.eq) goto loc_822BD900;
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822bd518
	if (!cr6.eq) goto loc_822BD518;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bb6a8
	ctx.lr = 0x822BD518;
	sub_822BB6A8(ctx, base);
loc_822BD518:
	// lwz r11,340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822bd53c
	if (!cr6.eq) goto loc_822BD53C;
	// lbz r11,336(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bd544
	if (!cr6.eq) goto loc_822BD544;
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822bd544
	if (!cr6.eq) goto loc_822BD544;
loc_822BD53C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba468
	ctx.lr = 0x822BD544;
	sub_822BA468(ctx, base);
loc_822BD544:
	// lbz r10,336(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 336);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822bd878
	if (!cr6.eq) goto loc_822BD878;
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822bd878
	if (!cr6.eq) goto loc_822BD878;
	// lbz r11,380(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd664
	if (cr6.eq) goto loc_822BD664;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lfs f0,416(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 416);
	f0.f64 = double(temp.f32);
	// lfs f13,224(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x822bd664
	if (!cr6.gt) goto loc_822BD664;
	// lfs f13,384(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 384);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x822bd5d8
	if (!cr6.gt) goto loc_822BD5D8;
	// lfs f0,420(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 420);
	f0.f64 = double(temp.f32);
	// lfs f12,424(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 424);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,412(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 412);
	f0.f64 = double(temp.f32);
	// lfs f9,428(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 428);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fdivs f7,f11,f10
	ctx.f7.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fsel f6,f7,f7,f31
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : f31.f64;
	// fsel f5,f7,f7,f31
	ctx.f5.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : f31.f64;
	// fsubs f4,f6,f30
	ctx.f4.f64 = double(float(ctx.f6.f64 - f30.f64));
	// fsel f3,f4,f30,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? f30.f64 : ctx.f5.f64;
	// fmadds f2,f3,f8,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f8.f64 + f0.f64));
	// fsubs f1,f0,f2
	ctx.f1.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f13,f1,f2,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// stfs f13,404(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// b 0x822bd614
	goto loc_822BD614;
loc_822BD5D8:
	// lfs f0,432(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 432);
	f0.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f11,436(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 436);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f0,412(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 412);
	f0.f64 = double(temp.f32);
	// lfs f9,440(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 440);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsubs f7,f12,f13
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fdivs f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 / ctx.f10.f64));
	// fsel f5,f6,f6,f31
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : f31.f64;
	// fsel f4,f6,f6,f31
	ctx.f4.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : f31.f64;
	// fsubs f3,f5,f30
	ctx.f3.f64 = double(float(ctx.f5.f64 - f30.f64));
	// fsel f2,f3,f30,f4
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? f30.f64 : ctx.f4.f64;
	// fmadds f1,f2,f8,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + f0.f64));
	// stfs f1,404(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
loc_822BD614:
	// lfs f13,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,476(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 476);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x822bd63c
	if (!cr6.lt) goto loc_822BD63C;
	// lfs f0,404(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 404);
	f0.f64 = double(temp.f32);
	// lfs f13,472(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 472);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f11,f12,f13,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stfs f11,404(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// b 0x822bd668
	goto loc_822BD668;
loc_822BD63C:
	// lfs f13,484(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 484);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f13
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f11,400(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 400);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// bge cr6,0x822bd668
	if (!cr6.lt) goto loc_822BD668;
	// lfs f13,480(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 480);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,404(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// b 0x822bd668
	goto loc_822BD668;
loc_822BD664:
	// stfs f30,404(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
loc_822BD668:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f13,404(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 404);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f11,f12,f13,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r30,24(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BD694;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// bne cr6,0x822bd7a4
	if (!cr6.eq) goto loc_822BD7A4;
	// lbz r11,236(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd7a4
	if (cr6.eq) goto loc_822BD7A4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822bd7a4
	if (!cr6.gt) goto loc_822BD7A4;
	// lfs f0,248(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 248);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x822bd7a4
	if (!cr6.eq) goto loc_822BD7A4;
	// lbz r11,380(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd708
	if (cr6.eq) goto loc_822BD708;
	// lfs f0,392(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 392);
	f0.f64 = double(temp.f32);
	// lfs f13,456(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822bd7a4
	if (!cr6.gt) goto loc_822BD7A4;
	// lfs f0,396(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	f0.f64 = double(temp.f32);
	// lfs f13,460(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 460);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822bd7a4
	if (!cr6.gt) goto loc_822BD7A4;
	// lfs f0,464(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 464);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f12,388(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x822bd7a4
	if (!cr6.lt) goto loc_822BD7A4;
loc_822BD708:
	// lwz r3,668(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 668);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822bd758
	if (cr6.eq) goto loc_822BD758;
	// bl 0x82345fe0
	ctx.lr = 0x822BD718;
	sub_82345FE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd758
	if (cr6.eq) goto loc_822BD758;
	// lwz r11,664(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822bd73c
	if (cr6.eq) goto loc_822BD73C;
	// lbz r11,32(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bd758
	if (!cr6.eq) goto loc_822BD758;
loc_822BD73C:
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x8254b438
	ctx.lr = 0x822BD744;
	sub_8254B438(ctx, base);
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822bd7a4
	if (!cr6.gt) goto loc_822BD7A4;
	// li r28,4
	r28.s64 = 4;
	// b 0x822bd7a4
	goto loc_822BD7A4;
loc_822BD758:
	// lwz r3,664(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 664);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822bd7a4
	if (cr6.eq) goto loc_822BD7A4;
	// bl 0x82345698
	ctx.lr = 0x822BD768;
	sub_82345698(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd7a4
	if (cr6.eq) goto loc_822BD7A4;
	// lwz r11,668(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 668);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822bd78c
	if (cr6.eq) goto loc_822BD78C;
	// lbz r11,40(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bd7a4
	if (!cr6.eq) goto loc_822BD7A4;
loc_822BD78C:
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x8254b110
	ctx.lr = 0x822BD794;
	sub_8254B110(ctx, base);
	// lfs f0,240(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 240);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822bd7a4
	if (!cr6.gt) goto loc_822BD7A4;
	// li r28,8
	r28.s64 = 8;
loc_822BD7A4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BD7B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822bd8d0
	if (!cr6.eq) goto loc_822BD8D0;
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// lfs f28,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f28.f64 = double(temp.f32);
	// ori r28,r28,1
	r28.u64 = r28.u64 | 1;
	// lfs f1,244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dca68
	ctx.lr = 0x822BD7D4;
	sub_823DCA68(ctx, base);
	// lwz r10,128(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,16
	ctx.r8.s64 = 16;
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r10,208
	r11.s64 = ctx.r10.s64 + 208;
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// addi r10,r10,288
	ctx.r10.s64 = ctx.r10.s64 + 288;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f7,228(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 228);
	ctx.f7.f64 = double(temp.f32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// fneg f6,f7
	ctx.f6.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v60,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmsum3fp128 v59,v61,v62
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// lvx128 v58,r11,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v57,v58,v62
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// lfs f0,14192(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f12,-29800(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29800);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-29804(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -29804);
	ctx.f11.f64 = double(temp.f32);
	// fsel f5,f6,f31,f30
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? f31.f64 : f30.f64;
	// vmrghw128 v56,v59,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// fsel f4,f7,f5,f0
	ctx.f4.f64 = ctx.f7.f64 >= 0.0 ? ctx.f5.f64 : f0.f64;
	// vmrghw128 v55,v57,v56
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v54,v56,v55
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// fmuls f3,f4,f8
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f8.f64));
	// stvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f12,f1,f12
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// fneg f2,f3
	ctx.f2.u64 = ctx.f3.u64 ^ 0x8000000000000000;
	// fmadds f11,f2,f11,f12
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fsubs f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f7,f8,f11,f0
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// fsubs f6,f7,f30
	ctx.f6.f64 = double(float(ctx.f7.f64 - f30.f64));
	// fsel f27,f6,f30,f7
	f27.f64 = ctx.f6.f64 >= 0.0 ? f30.f64 : ctx.f7.f64;
	// b 0x822bd8d8
	goto loc_822BD8D8;
loc_822BD878:
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// fmr f10,f30
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = f30.f64;
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822bd898
	if (!cr6.eq) goto loc_822BD898;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822bd8ac
	goto loc_822BD8AC;
loc_822BD898:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822bd8a8
	if (!cr6.eq) goto loc_822BD8A8;
	// fmr f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f30.f64;
	// b 0x822bd8ac
	goto loc_822BD8AC;
loc_822BD8A8:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_822BD8AC:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bd8bc
	if (cr6.eq) goto loc_822BD8BC;
	// fneg f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// b 0x822bd8dc
	goto loc_822BD8DC;
loc_822BD8BC:
	// lbz r11,337(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 337);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd8dc
	if (cr6.eq) goto loc_822BD8DC;
	// stfs f30,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// b 0x822bd8dc
	goto loc_822BD8DC;
loc_822BD8D0:
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
loc_822BD8D8:
	// lfs f9,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
loc_822BD8DC:
	// lbz r11,336(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bd8f0
	if (cr6.eq) goto loc_822BD8F0;
	// mr r26,r25
	r26.u64 = r25.u64;
	// b 0x822bd988
	goto loc_822BD988;
loc_822BD8F0:
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// bge cr6,0x822bd988
	if (!cr6.lt) goto loc_822BD988;
	// li r26,2
	r26.s64 = 2;
	// b 0x822bd988
	goto loc_822BD988;
loc_822BD900:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lfs f0,-31648(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31648);
	f0.f64 = double(temp.f32);
	// beq cr6,0x822bd91c
	if (cr6.eq) goto loc_822BD91C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822bd964
	if (!cr6.eq) goto loc_822BD964;
loc_822BD91C:
	// lfs f13,224(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822bd964
	if (!cr6.gt) goto loc_822BD964;
	// fmr f10,f30
	ctx.f10.f64 = f30.f64;
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lfs f0,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x822bd984
	if (!cr6.eq) goto loc_822BD984;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r10,22560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 22560);
	// lwz r11,22552(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22552);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x822bd984
	if (!cr0.eq) goto loc_822BD984;
	// li r28,8192
	r28.s64 = 8192;
	// b 0x822bd984
	goto loc_822BD984;
loc_822BD964:
	// lfs f13,572(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 572);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822bd974
	if (!cr6.lt) goto loc_822BD974;
	// li r26,1
	r26.s64 = 1;
loc_822BD974:
	// lfs f10,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stw r25,332(r31)
	PPC_STORE_U32(r31.u32 + 332, r25.u32);
	// lfs f9,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// stb r25,336(r31)
	PPC_STORE_U8(r31.u32 + 336, r25.u8);
loc_822BD984:
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
loc_822BD988:
	// stfs f10,156(r24)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r24.u32 + 156, temp.u32);
	// sth r26,44(r24)
	PPC_STORE_U16(r24.u32 + 44, r26.u16);
	// stfs f13,152(r24)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r24.u32 + 152, temp.u32);
	// stw r28,40(r24)
	PPC_STORE_U32(r24.u32 + 40, r28.u32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// stfs f0,164(r24)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r24.u32 + 164, temp.u32);
	// stfs f27,32(r24)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r24.u32 + 32, temp.u32);
	// stfs f28,36(r24)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r24.u32 + 36, temp.u32);
	// stfs f9,160(r24)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r24.u32 + 160, temp.u32);
	// lfs f13,296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x822bd9c0
	if (cr6.gt) goto loc_822BD9C0;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_822BD9C0:
	// stb r11,169(r24)
	PPC_STORE_U8(r24.u32 + 169, r11.u8);
loc_822BD9C4:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba14
	ctx.lr = 0x822BD9D0;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822BD9D4"))) PPC_WEAK_FUNC(sub_822BD9D4);
PPC_FUNC_IMPL(__imp__sub_822BD9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BD9D8"))) PPC_WEAK_FUNC(sub_822BD9D8);
PPC_FUNC_IMPL(__imp__sub_822BD9D8) {
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
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
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
	ctx.lr = 0x822BD9E0;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9cc
	ctx.lr = 0x822BD9E8;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-3660(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bdfec
	if (cr6.eq) goto loc_822BDFEC;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BDA08;
	sub_822A8108(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r28,r3,48
	r28.s64 = ctx.r3.s64 + 48;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,128(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 128);
	// addi r31,r11,272
	r31.s64 = r11.s64 + 272;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x822BDA34;
	sub_822A8108(ctx, base);
	// addi r7,r3,32
	ctx.r7.s64 = ctx.r3.s64 + 32;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f29,7444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f29.f64 = double(temp.f32);
	// vsubfp128 v1,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// fmr f1,f29
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f29.f64;
	// bl 0x82165300
	ctx.lr = 0x822BDA58;
	sub_82165300(ctx, base);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lwz r4,48(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// fmadds f7,f13,f9,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f31,f12,f8,f7
	f31.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f7.f64));
	// bl 0x8255b9a8
	ctx.lr = 0x822BDA8C;
	sub_8255B9A8(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f30,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	f30.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,300(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// li r7,0
	ctx.r7.s64 = 0;
	// lvx128 v60,r0,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r3,25440
	r31.s64 = ctx.r3.s64 + 25440;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f0,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// stw r7,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r7.u32);
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f27,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f27.f64 = double(temp.f32);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lfs f6,224(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 224);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f28,f5,f6,f0
	f28.f64 = ctx.f5.f64 >= 0.0 ? ctx.f6.f64 : f0.f64;
	// bl 0x8254b020
	ctx.lr = 0x822BDAD8;
	sub_8254B020(ctx, base);
	// lwz r4,408(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// ori r3,r4,16
	ctx.r3.u64 = ctx.r4.u64 | 16;
	// stw r3,408(r30)
	PPC_STORE_U32(r30.u32 + 408, ctx.r3.u32);
	// lwz r10,1032(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// mr r29,r11
	r29.u64 = r11.u64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x822bdfec
	if (!cr6.lt) goto loc_822BDFEC;
	// fdivs f25,f29,f28
	ctx.fpscr.disableFlushMode();
	f25.f64 = double(float(f29.f64 / f28.f64));
	// lfs f29,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f29.f64 = double(temp.f32);
	// lfs f28,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f28.f64 = double(temp.f32);
	// lfs f26,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f26.f64 = double(temp.f32);
loc_822BDB0C:
	// lwz r10,1028(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// srawi r8,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 6;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r6,r7,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r11,r6,r9
	r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// bl 0x8226a6f8
	ctx.lr = 0x822BDB44;
	sub_8226A6F8(ctx, base);
	// lwz r10,300(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r8,25104(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 25104);
	// cmpwi cr6,r8,32
	cr6.compare<int32_t>(ctx.r8.s32, 32, xer);
	// beq cr6,0x822bdba0
	if (cr6.eq) goto loc_822BDBA0;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDBA0;
	sub_822BBB60(ctx, base);
loc_822BDBA0:
	// lwz r11,300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bdc1c
	if (cr6.eq) goto loc_822BDC1C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// bl 0x8226a7c8
	ctx.lr = 0x822BDBC8;
	sub_8226A7C8(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822bdc1c
	if (cr6.eq) goto loc_822BDC1C;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDC1C;
	sub_822BBB60(ctx, base);
loc_822BDC1C:
	// lwz r11,300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bdc94
	if (cr6.eq) goto loc_822BDC94;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8226a7c8
	ctx.lr = 0x822BDC40;
	sub_8226A7C8(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822bdc94
	if (cr6.eq) goto loc_822BDC94;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDC94;
	sub_822BBB60(ctx, base);
loc_822BDC94:
	// lwz r11,300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bdd10
	if (cr6.eq) goto loc_822BDD10;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// bl 0x8226a7c8
	ctx.lr = 0x822BDCBC;
	sub_8226A7C8(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822bdd10
	if (cr6.eq) goto loc_822BDD10;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDD10;
	sub_822BBB60(ctx, base);
loc_822BDD10:
	// lwz r11,300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bdd88
	if (cr6.eq) goto loc_822BDD88;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8226a7c8
	ctx.lr = 0x822BDD34;
	sub_8226A7C8(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822bdd88
	if (cr6.eq) goto loc_822BDD88;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDD88;
	sub_822BBB60(ctx, base);
loc_822BDD88:
	// lwz r11,300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bde00
	if (cr6.eq) goto loc_822BDE00;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8226a7c8
	ctx.lr = 0x822BDDAC;
	sub_8226A7C8(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822bde00
	if (cr6.eq) goto loc_822BDE00;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDE00;
	sub_822BBB60(ctx, base);
loc_822BDE00:
	// lwz r11,300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bde7c
	if (cr6.eq) goto loc_822BDE7C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// bl 0x8226a7c8
	ctx.lr = 0x822BDE28;
	sub_8226A7C8(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822bde7c
	if (cr6.eq) goto loc_822BDE7C;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDE7C;
	sub_822BBB60(ctx, base);
loc_822BDE7C:
	// lwz r11,300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bdef4
	if (cr6.eq) goto loc_822BDEF4;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8226a7c8
	ctx.lr = 0x822BDEA0;
	sub_8226A7C8(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822bdef4
	if (cr6.eq) goto loc_822BDEF4;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDEF4;
	sub_822BBB60(ctx, base);
loc_822BDEF4:
	// lwz r11,300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// lwz r10,25104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 25104);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// beq cr6,0x822bdf70
	if (cr6.eq) goto loc_822BDF70;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r3,-3660(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -3660);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// bl 0x8226a7c8
	ctx.lr = 0x822BDF1C;
	sub_8226A7C8(ctx, base);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822bdf70
	if (cr6.eq) goto loc_822BDF70;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// bl 0x822bbb60
	ctx.lr = 0x822BDF70;
	sub_822BBB60(ctx, base);
loc_822BDF70:
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lwz r10,1028(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// lwz r9,300(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 300);
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lfs f0,25400(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 25400);
	f0.f64 = double(temp.f32);
	// srawi r7,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 6;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r5,r6,6,0,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f28,f13
	ctx.f12.f64 = double(float(f28.f64 - ctx.f13.f64));
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f29,f11
	ctx.f10.f64 = double(float(f29.f64 - ctx.f11.f64));
	// lfs f9,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f26,f9
	ctx.f8.f64 = double(float(f26.f64 - ctx.f9.f64));
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f10,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f5,f8,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fsqrts f4,f5
	ctx.f4.f64 = double(float(sqrt(ctx.f5.f64)));
	// fmadds f27,f4,f25,f27
	f27.f64 = double(float(ctx.f4.f64 * f25.f64 + f27.f64));
	// fcmpu cr6,f27,f0
	cr6.compare(f27.f64, f0.f64);
	// bgt cr6,0x822bdfec
	if (cr6.gt) goto loc_822BDFEC;
	// lwz r10,1032(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x822bdb0c
	if (cr6.lt) goto loc_822BDB0C;
loc_822BDFEC:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba18
	ctx.lr = 0x822BDFF8;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822BDFFC"))) PPC_WEAK_FUNC(sub_822BDFFC);
PPC_FUNC_IMPL(__imp__sub_822BDFFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BE000"))) PPC_WEAK_FUNC(sub_822BE000);
PPC_FUNC_IMPL(__imp__sub_822BE000) {
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
	// bl 0x823d91f0
	ctx.lr = 0x822BE008;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dd534
	ctx.lr = 0x822BE010;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826fcf10
	ctx.lr = 0x822BE01C;
	sub_826FCF10(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lwz r28,20(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// cmpwi cr6,r11,96
	cr6.compare<int32_t>(r11.s32, 96, xer);
	// blt cr6,0x822be03c
	if (cr6.lt) goto loc_822BE03C;
	// li r28,64
	r28.s64 = 64;
	// li r26,1
	r26.s64 = 1;
loc_822BE03C:
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// lwz r9,22552(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 22552);
	// subfic r8,r9,128
	xer.ca = ctx.r9.u32 <= 128;
	ctx.r8.s64 = 128 - ctx.r9.s64;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// bgt cr6,0x822be42c
	if (cr6.gt) goto loc_822BE42C;
	// lwz r30,12(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822be104
	if (cr6.eq) goto loc_822BE104;
loc_822BE064:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x822be0e8
	if (cr6.lt) goto loc_822BE0E8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822be0d8
	if (!cr6.eq) goto loc_822BE0D8;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x822be0c8
	if (!cr6.eq) goto loc_822BE0C8;
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x8254b828
	ctx.lr = 0x822BE088;
	sub_8254B828(ctx, base);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x822be0b0
	if (!cr6.lt) goto loc_822BE0B0;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r10,22560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 22560);
	// lwz r11,22552(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22552);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822be0c8
	if (!cr6.eq) goto loc_822BE0C8;
loc_822BE0B0:
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x8254b828
	ctx.lr = 0x822BE0B8;
	sub_8254B828(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bbee8
	ctx.lr = 0x822BE0C8;
	sub_822BBEE8(ctx, base);
loc_822BE0C8:
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r30
	r29.u64 = r30.u64;
	// bl 0x822bc508
	ctx.lr = 0x822BE0D8;
	sub_822BC508(ctx, base);
loc_822BE0D8:
	// lwz r30,48(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x822be064
	if (!cr6.eq) goto loc_822BE064;
loc_822BE0E8:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822be104
	if (cr6.eq) goto loc_822BE104;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r29,4
	ctx.r4.s64 = r29.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bbee8
	ctx.lr = 0x822BE100;
	sub_822BBEE8(ctx, base);
	// b 0x822be134
	goto loc_822BE134;
loc_822BE104:
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r10,22560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 22560);
	// lwz r11,22552(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22552);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x822be134
	if (!cr0.eq) goto loc_822BE134;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822be134
	if (!cr6.eq) goto loc_822BE134;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bc360
	ctx.lr = 0x822BE134;
	sub_822BC360(ctx, base);
loc_822BE134:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// lwz r30,220(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822be27c
	if (cr6.eq) goto loc_822BE27C;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r8,r10,-31568
	ctx.r8.s64 = ctx.r10.s64 + -31568;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,176
	ctx.r3.s64 = r31.s64 + 176;
	// lwz r6,22532(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 22532);
	// lwz r5,22544(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 22544);
	// lvx128 v126,r0,r8
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,22536(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 22536);
	// subf r10,r5,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r5.s64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rotlwi r29,r7,0
	r29.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// subf r8,r29,r5
	ctx.r8.s64 = ctx.r5.s64 - r29.s64;
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// add r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 + ctx.r7.u64;
	// srawi r8,r5,7
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7F) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 7;
	// add r7,r10,r6
	ctx.r7.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addze r6,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r6.s64 = temp.s64;
	// srawi r10,r7,7
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7F) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 7;
	// rlwinm r8,r6,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// addze r6,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r6.s64 = temp.s64;
	// subf r5,r8,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r8.s64;
	// rlwinm r8,r6,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// mulli r10,r5,176
	ctx.r10.s64 = ctx.r5.s64 * 176;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// mulli r8,r7,176
	ctx.r8.s64 = ctx.r7.s64 * 176;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v60
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// vmulfp128 v125,v61,v126
	simde_mm_store_ps(v125.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v126.f32)));
	// vmulfp128 v124,v58,v126
	simde_mm_store_ps(v124.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v126.f32)));
	// vsubfp128 v127,v124,v125
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v125.f32)));
	// bl 0x822bb278
	ctx.lr = 0x822BE1F8;
	sub_822BB278(ctx, base);
	// vaddfp128 v57,v124,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v125.f32)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r11,r31,184
	r11.s64 = r31.s64 + 184;
	// lfs f0,31016(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31016);
	f0.f64 = double(temp.f32);
	// vmulfp128 v56,v57,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v126.f32)));
	// stvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,12(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lhz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// ble cr6,0x822be244
	if (!cr6.gt) goto loc_822BE244;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - r30.s64;
loc_822BE228:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// lwz r7,-4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// bne 0x822be228
	if (!cr0.eq) goto loc_822BE228;
loc_822BE244:
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r3,r4,0,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFC;
	// stwx r3,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r3.u32);
	// lfs f1,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r11.u32);
	// b 0x822be400
	goto loc_822BE400;
loc_822BE27C:
	// lhz r11,180(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x822be33c
	if (!cr6.lt) goto loc_822BE33C;
	// addi r8,r30,1
	ctx.r8.s64 = r30.s64 + 1;
	// lwz r6,184(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// li r9,16
	ctx.r9.s64 = 16;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,12
	ctx.r7.s64 = 12;
	// lwzx r10,r11,r6
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// clrlwi r5,r10,31
	ctx.r5.u64 = ctx.r10.u32 & 0x1;
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822be2d8
	if (cr6.eq) goto loc_822BE2D8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v55,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v54,r11,r7
	temp.u32 = r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vmaddfp v13,v13,v12,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// b 0x822be2dc
	goto loc_822BE2DC;
loc_822BE2D8:
	// lvx128 v13,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822BE2DC:
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x822be2e8
	if (!cr0.lt) goto loc_822BE2E8;
	// li r11,0
	r11.s64 = 0;
loc_822BE2E8:
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r4,r5,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822be320
	if (cr6.eq) goto loc_822BE320;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v12,v53,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v52,r11,r7
	temp.u32 = r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// vmaddfp v0,v12,v11,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// b 0x822be324
	goto loc_822BE324;
loc_822BE320:
	// lvx128 v0,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822BE324:
	// rlwinm r11,r30,5,0,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// vsubfp128 v127,v13,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)));
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f1,28(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// stw r8,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r8.u32);
	// b 0x822be400
	goto loc_822BE400;
loc_822BE33C:
	// lbz r11,258(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 258);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822be3ec
	if (cr6.eq) goto loc_822BE3EC;
	// lwz r8,184(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r7,12
	ctx.r7.s64 = 12;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822be384
	if (cr6.eq) goto loc_822BE384;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r11,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v51,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v50,r11,r7
	temp.u32 = r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmaddfp v13,v13,v12,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// b 0x822be388
	goto loc_822BE388;
loc_822BE384:
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822BE388:
	// addic. r10,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r10.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge 0x822be394
	if (!cr0.lt) goto loc_822BE394;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822BE394:
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x822be3cc
	if (cr6.eq) goto loc_822BE3CC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r10,r9
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v12,v49,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v48,r10,r7
	temp.u32 = ctx.r10.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v48,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vmaddfp v0,v12,v11,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// b 0x822be3d0
	goto loc_822BE3D0;
loc_822BE3CC:
	// lvx128 v0,r10,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822BE3D0:
	// rlwinm r10,r30,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// vsubfp128 v127,v13,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)));
	// li r9,0
	ctx.r9.s64 = 0;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lfs f1,28(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// stw r9,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r9.u32);
	// b 0x822be400
	goto loc_822BE400;
loc_822BE3EC:
	// li r11,192
	r11.s64 = 192;
	// lfs f1,208(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	ctx.f1.f64 = double(temp.f32);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// stw r10,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r10.u32);
	// lvx128 v127,r31,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822BE400:
	// lwz r9,184(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// rlwinm r11,r30,5,0,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 5) & 0xFFFFFFE0;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x8254cfa0
	ctx.lr = 0x822BE424;
	sub_8254CFA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd488
	ctx.lr = 0x822BE42C;
	sub_826FD488(ctx, base);
loc_822BE42C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dd7cc
	ctx.lr = 0x822BE438;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822BE43C"))) PPC_WEAK_FUNC(sub_822BE43C);
PPC_FUNC_IMPL(__imp__sub_822BE43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BE440"))) PPC_WEAK_FUNC(sub_822BE440);
PPC_FUNC_IMPL(__imp__sub_822BE440) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// li r9,192
	ctx.r9.s64 = 192;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BE478"))) PPC_WEAK_FUNC(sub_822BE478);
PPC_FUNC_IMPL(__imp__sub_822BE478) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822BE480;
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822be4c4
	if (!cr6.eq) goto loc_822BE4C4;
	// li r3,640
	ctx.r3.s64 = 640;
	// bl 0x82130528
	ctx.lr = 0x822BE4A8;
	sub_82130528(ctx, base);
	// li r29,20
	r29.s64 = 20;
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// li r3,80
	ctx.r3.s64 = 80;
	// sth r29,182(r31)
	PPC_STORE_U16(r31.u32 + 182, r29.u16);
	// bl 0x82130528
	ctx.lr = 0x822BE4BC;
	sub_82130528(ctx, base);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// sth r29,190(r31)
	PPC_STORE_U16(r31.u32 + 190, r29.u16);
loc_822BE4C4:
	// lhz r11,180(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// addi r10,r31,176
	ctx.r10.s64 = r31.s64 + 176;
	// addi r10,r31,184
	ctx.r10.s64 = r31.s64 + 184;
	// lwz r9,176(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rotlwi r11,r11,5
	r11.u64 = __builtin_rotateleft32(r11.u32, 5);
	// sth r10,180(r31)
	PPC_STORE_U16(r31.u32 + 180, ctx.r10.u16);
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lhz r11,188(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 188);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r7,188(r31)
	PPC_STORE_U16(r31.u32 + 188, ctx.r7.u16);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lwzx r5,r11,r10
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r4,r5,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFE;
	// ori r3,r4,2
	ctx.r3.u64 = ctx.r4.u64 | 2;
	// stwx r3,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r3.u32);
	// lhz r9,180(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// rotlwi r9,r9,6
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 6);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// rlwimi r8,r3,0,30,18
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r3.u32, 0) & 0xFFFFFFFFFFFFE003) | (ctx.r8.u64 & 0x1FFC);
	// rlwinm r7,r8,0,30,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFC3;
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822BE538"))) PPC_WEAK_FUNC(sub_822BE538);
PPC_FUNC_IMPL(__imp__sub_822BE538) {
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
	ctx.lr = 0x822BE540;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stw r4,324(r30)
	PPC_STORE_U32(r30.u32 + 324, ctx.r4.u32);
	// stw r5,328(r30)
	PPC_STORE_U32(r30.u32 + 328, ctx.r5.u32);
	// bgt cr6,0x822be55c
	if (cr6.gt) goto loc_822BE55C;
	// li r6,1
	ctx.r6.s64 = 1;
loc_822BE55C:
	// cmpwi cr6,r7,2
	cr6.compare<int32_t>(ctx.r7.s32, 2, xer);
	// stw r6,224(r30)
	PPC_STORE_U32(r30.u32 + 224, ctx.r6.u32);
	// beq cr6,0x822be57c
	if (cr6.eq) goto loc_822BE57C;
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// beq cr6,0x822be57c
	if (cr6.eq) goto loc_822BE57C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// b 0x822be584
	goto loc_822BE584;
loc_822BE57C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	f0.f64 = double(temp.f32);
loc_822BE584:
	// lhz r11,182(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 182);
	// stfs f0,260(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 260, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822be608
	if (!cr6.eq) goto loc_822BE608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822bae80
	ctx.lr = 0x822BE59C;
	sub_822BAE80(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// ble cr6,0x822be5ac
	if (!cr6.gt) goto loc_822BE5AC;
	// li r11,64
	r11.s64 = 64;
loc_822BE5AC:
	// lwz r10,224(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 224);
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// addi r31,r11,16
	r31.s64 = r11.s64 + 16;
	// cmpwi cr6,r31,640
	cr6.compare<int32_t>(r31.s32, 640, xer);
	// ble cr6,0x822be5c4
	if (!cr6.gt) goto loc_822BE5C4;
	// li r31,640
	r31.s64 = 640;
loc_822BE5C4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822be5d8
	if (cr6.eq) goto loc_822BE5D8;
	// rlwinm r3,r31,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x822BE5D4;
	sub_82130528(ctx, base);
	// b 0x822be5dc
	goto loc_822BE5DC;
loc_822BE5D8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822BE5DC:
	// clrlwi r29,r31,16
	r29.u64 = r31.u32 & 0xFFFF;
	// stw r3,176(r30)
	PPC_STORE_U32(r30.u32 + 176, ctx.r3.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// sth r29,182(r30)
	PPC_STORE_U16(r30.u32 + 182, r29.u16);
	// beq cr6,0x822be5fc
	if (cr6.eq) goto loc_822BE5FC;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x822BE5F8;
	sub_82130528(ctx, base);
	// b 0x822be600
	goto loc_822BE600;
loc_822BE5FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822BE600:
	// stw r3,184(r30)
	PPC_STORE_U32(r30.u32 + 184, ctx.r3.u32);
	// sth r29,190(r30)
	PPC_STORE_U16(r30.u32 + 190, r29.u16);
loc_822BE608:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822baf18
	ctx.lr = 0x822BE618;
	sub_822BAF18(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822BE620"))) PPC_WEAK_FUNC(sub_822BE620);
PPC_FUNC_IMPL(__imp__sub_822BE620) {
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
	// bl 0x822bca08
	ctx.lr = 0x822BE640;
	sub_822BCA08(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822be658
	if (cr6.eq) goto loc_822BE658;
	// bl 0x82130588
	ctx.lr = 0x822BE654;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822BE658:
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

__attribute__((alias("__imp__sub_822BE670"))) PPC_WEAK_FUNC(sub_822BE670);
PPC_FUNC_IMPL(__imp__sub_822BE670) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	ctx.lr = 0x822BE678;
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f29.u64);
	// stfd f30,-56(r1)
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
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822beb48
	if (cr6.eq) goto loc_822BEB48;
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822be6c0
	if (cr6.eq) goto loc_822BE6C0;
	// bl 0x821c4458
	ctx.lr = 0x822BE6BC;
	sub_821C4458(ctx, base);
	// stw r28,304(r31)
	PPC_STORE_U32(r31.u32 + 304, r28.u32);
loc_822BE6C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd2f8
	ctx.lr = 0x822BE6C8;
	sub_826FD2F8(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822be6ec
	if (!cr6.eq) goto loc_822BE6EC;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r10,22984(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 22984);
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// beq cr6,0x822be6ec
	if (cr6.eq) goto loc_822BE6EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822be000
	ctx.lr = 0x822BE6EC;
	sub_822BE000(ctx, base);
loc_822BE6EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bd9d8
	ctx.lr = 0x822BE6F4;
	sub_822BD9D8(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r29,r11,2272
	r29.s64 = r11.s64 + 2272;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822be7e8
	if (cr6.eq) goto loc_822BE7E8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822be72c
	if (cr6.eq) goto loc_822BE72C;
	// lfs f30,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	f30.f64 = double(temp.f32);
	// b 0x822be730
	goto loc_822BE730;
loc_822BE72C:
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
loc_822BE730:
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822be740
	if (cr6.eq) goto loc_822BE740;
	// lfs f31,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f31.f64 = double(temp.f32);
loc_822BE740:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r10,288
	ctx.r10.s64 = 288;
	// li r9,272
	ctx.r9.s64 = 272;
	// lfs f29,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 292);
	f29.f64 = double(temp.f32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,128(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 128);
	// lvx128 v127,r7,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r7,r9
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x822BE764;
	sub_822A8108(ctx, base);
	// vor128 v1,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// vor128 v2,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// bl 0x8254d570
	ctx.lr = 0x822BE784;
	sub_8254D570(ctx, base);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,48(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r10,664(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 664);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822be818
	if (cr6.eq) goto loc_822BE818;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r9,r11,18040
	ctx.r9.s64 = r11.s64 + 18040;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822be7dc
	if (!cr6.eq) goto loc_822BE7DC;
	// lbz r11,380(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822be7d0
	if (cr6.eq) goto loc_822BE7D0;
	// lfs f0,468(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f12,388(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x822be7dc
	if (cr6.lt) goto loc_822BE7DC;
loc_822BE7D0:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stb r11,33(r10)
	PPC_STORE_U8(ctx.r10.u32 + 33, r11.u8);
	// b 0x822be818
	goto loc_822BE818;
loc_822BE7DC:
	// li r11,1
	r11.s64 = 1;
	// stb r11,33(r10)
	PPC_STORE_U8(ctx.r10.u32 + 33, r11.u8);
	// b 0x822be818
	goto loc_822BE818;
loc_822BE7E8:
	// lfs f31,292(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 292);
	f31.f64 = double(temp.f32);
	// lvx128 v127,r0,r29
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x822BE7F4;
	sub_822A8108(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vor128 v2,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// lfs f2,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x8254d570
	ctx.lr = 0x822BE818;
	sub_8254D570(ctx, base);
loc_822BE818:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BE820;
	sub_822A8108(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd068
	ctx.lr = 0x822BE82C;
	sub_826FD068(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r30,30
	r30.s64 = 30;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822be84c
	if (cr6.eq) goto loc_822BE84C;
	// stw r30,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r30.u32);
	// b 0x822be8e4
	goto loc_822BE8E4;
loc_822BE84C:
	// lwz r11,268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r11.u32);
	// bgt 0x822be8e4
	if (cr0.gt) goto loc_822BE8E4;
	// stw r30,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r30.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822BE868;
	sub_822A8108(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826fd508
	ctx.lr = 0x822BE8B4;
	sub_826FD508(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822be8e4
	if (cr6.eq) goto loc_822BE8E4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lfs f2,30712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x822BE8E4;
	sub_822A9930(ctx, base);
loc_822BE8E4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x8254c6e0
	ctx.lr = 0x822BE8F4;
	sub_8254C6E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822be908
	if (!cr6.eq) goto loc_822BE908;
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// b 0x822be928
	goto loc_822BE928;
loc_822BE908:
	// lwz r11,264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r11.u32);
	// bgt 0x822be928
	if (cr0.gt) goto loc_822BE928;
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,216(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// bl 0x822b9f18
	ctx.lr = 0x822BE928;
	sub_822B9F18(ctx, base);
loc_822BE928:
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// lbz r9,258(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 258);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r10,22992(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22992);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r11.u32);
	// beq cr6,0x822be978
	if (cr6.eq) goto loc_822BE978;
	// lhz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822be978
	if (cr6.eq) goto loc_822BE978;
	// divw r8,r11,r10
	ctx.r8.s32 = r11.s32 / ctx.r10.s32;
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// subf r5,r7,r11
	ctx.r5.s64 = r11.s64 - ctx.r7.s64;
	// andc r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 & ~ctx.r6.u64;
	// twllei r10,0
	// stw r5,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r5.u32);
	// twlgei r4,-1
loc_822BE978:
	// lwz r11,324(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822be9d8
	if (cr6.eq) goto loc_822BE9D8;
	// lfs f0,452(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 452);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f12,388(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 388);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x822be9d8
	if (!cr6.lt) goto loc_822BE9D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// bl 0x822bae28
	ctx.lr = 0x822BE9A4;
	sub_822BAE28(ctx, base);
	// cmpw cr6,r3,r7
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, xer);
	// bgt cr6,0x822be9d0
	if (cr6.gt) goto loc_822BE9D0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bae28
	ctx.lr = 0x822BE9B4;
	sub_822BAE28(ctx, base);
	// cmpw cr6,r3,r7
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, xer);
	// bne cr6,0x822be9d8
	if (!cr6.eq) goto loc_822BE9D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822badd0
	ctx.lr = 0x822BE9C4;
	sub_822BADD0(ctx, base);
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// ble cr6,0x822be9d8
	if (!cr6.gt) goto loc_822BE9D8;
loc_822BE9D0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bcc90
	ctx.lr = 0x822BE9D8;
	sub_822BCC90(ctx, base);
loc_822BE9D8:
	// lhz r7,180(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// lwz r4,220(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpw cr6,r4,r7
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, xer);
	// bge cr6,0x822bea7c
	if (!cr6.lt) goto loc_822BEA7C;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822be9fc
	if (cr6.eq) goto loc_822BE9FC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822bea7c
	if (!cr6.eq) goto loc_822BEA7C;
loc_822BE9FC:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bad78
	ctx.lr = 0x822BEA08;
	sub_822BAD78(ctx, base);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x822bea40
	if (!cr6.eq) goto loc_822BEA40;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lwz r10,22560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 22560);
	// lwz r11,22552(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22552);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x822bea40
	if (!cr0.eq) goto loc_822BEA40;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// bl 0x822a8108
	ctx.lr = 0x822BEA34;
	sub_822A8108(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// b 0x822bea74
	goto loc_822BEA74;
loc_822BEA40:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x822bea60
	if (!cr6.eq) goto loc_822BEA60;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r7,-1
	ctx.r4.s64 = ctx.r7.s64 + -1;
	// bl 0x822bad78
	ctx.lr = 0x822BEA58;
	sub_822BAD78(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// b 0x822bea70
	goto loc_822BEA70;
loc_822BEA60:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// bl 0x822bad78
	ctx.lr = 0x822BEA6C;
	sub_822BAD78(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
loc_822BEA70:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
loc_822BEA74:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b9e00
	ctx.lr = 0x822BEA7C;
	sub_822B9E00(ctx, base);
loc_822BEA7C:
	// lbz r11,253(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 253);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822beac4
	if (!cr6.eq) goto loc_822BEAC4;
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// bl 0x8254ca78
	ctx.lr = 0x822BEA90;
	sub_8254CA78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822beac4
	if (!cr6.eq) goto loc_822BEAC4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,300(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// addi r10,r11,-24440
	ctx.r10.s64 = r11.s64 + -24440;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822beac0
	if (!cr6.eq) goto loc_822BEAC0;
	// bl 0x8216c7e0
	ctx.lr = 0x822BEAB8;
	sub_8216C7E0(ctx, base);
	// stw r3,304(r31)
	PPC_STORE_U32(r31.u32 + 304, ctx.r3.u32);
	// b 0x822beac4
	goto loc_822BEAC4;
loc_822BEAC0:
	// bl 0x8254dea0
	ctx.lr = 0x822BEAC4;
	sub_8254DEA0(ctx, base);
loc_822BEAC4:
	// lbz r11,256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822beb00
	if (cr6.eq) goto loc_822BEB00;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822beb00
	if (cr6.eq) goto loc_822BEB00;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822beb00
	if (cr6.eq) goto loc_822BEB00;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822beb00
	if (cr6.eq) goto loc_822BEB00;
	// lbz r4,254(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 254);
	// bl 0x82348880
	ctx.lr = 0x822BEAFC;
	sub_82348880(ctx, base);
	// stb r28,256(r31)
	PPC_STORE_U8(r31.u32 + 256, r28.u8);
loc_822BEB00:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822beb48
	if (cr6.eq) goto loc_822BEB48;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822beb48
	if (cr6.eq) goto loc_822BEB48;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// rlwinm r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822beb48
	if (cr6.eq) goto loc_822BEB48;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	f0.f64 = double(temp.f32);
	// lfs f13,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 + f31.f64));
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsel f10,f11,f0,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// stfs f10,296(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 296, temp.u32);
loc_822BEB48:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_822BEB6C"))) PPC_WEAK_FUNC(sub_822BEB6C);
PPC_FUNC_IMPL(__imp__sub_822BEB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BEB70"))) PPC_WEAK_FUNC(sub_822BEB70);
PPC_FUNC_IMPL(__imp__sub_822BEB70) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x822be478
	ctx.lr = 0x822BEBAC;
	sub_822BE478(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BEBBC"))) PPC_WEAK_FUNC(sub_822BEBBC);
PPC_FUNC_IMPL(__imp__sub_822BEBBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BEBC0"))) PPC_WEAK_FUNC(sub_822BEBC0);
PPC_FUNC_IMPL(__imp__sub_822BEBC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822be538
	sub_822BE538(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BEBDC"))) PPC_WEAK_FUNC(sub_822BEBDC);
PPC_FUNC_IMPL(__imp__sub_822BEBDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BEBE0"))) PPC_WEAK_FUNC(sub_822BEBE0);
PPC_FUNC_IMPL(__imp__sub_822BEBE0) {
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
	// lis r11,-32212
	r11.s64 = -2111045632;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-14760
	ctx.r4.s64 = r11.s64 + -14760;
	// addi r3,r10,-29268
	ctx.r3.s64 = ctx.r10.s64 + -29268;
	// bl 0x82554798
	ctx.lr = 0x822BEC00;
	sub_82554798(ctx, base);
	// lis r9,-32212
	ctx.r9.s64 = -2111045632;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-5264
	ctx.r4.s64 = ctx.r9.s64 + -5264;
	// addi r3,r8,-29292
	ctx.r3.s64 = ctx.r8.s64 + -29292;
	// bl 0x82554798
	ctx.lr = 0x822BEC14;
	sub_82554798(ctx, base);
	// lis r7,-32212
	ctx.r7.s64 = -2111045632;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-5184
	ctx.r4.s64 = ctx.r7.s64 + -5184;
	// addi r3,r6,-29316
	ctx.r3.s64 = ctx.r6.s64 + -29316;
	// bl 0x82554798
	ctx.lr = 0x822BEC28;
	sub_82554798(ctx, base);
	// lis r5,-32212
	ctx.r5.s64 = -2111045632;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-7104
	ctx.r4.s64 = ctx.r5.s64 + -7104;
	// addi r3,r3,-29344
	ctx.r3.s64 = ctx.r3.s64 + -29344;
	// bl 0x82554798
	ctx.lr = 0x822BEC3C;
	sub_82554798(ctx, base);
	// lis r11,-32212
	r11.s64 = -2111045632;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-14736
	ctx.r4.s64 = r11.s64 + -14736;
	// addi r3,r10,-29380
	ctx.r3.s64 = ctx.r10.s64 + -29380;
	// bl 0x82554798
	ctx.lr = 0x822BEC50;
	sub_82554798(ctx, base);
	// lis r9,-32212
	ctx.r9.s64 = -2111045632;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-14720
	ctx.r4.s64 = ctx.r9.s64 + -14720;
	// addi r3,r8,-29408
	ctx.r3.s64 = ctx.r8.s64 + -29408;
	// bl 0x82554798
	ctx.lr = 0x822BEC64;
	sub_82554798(ctx, base);
	// lis r7,-32212
	ctx.r7.s64 = -2111045632;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-14696
	ctx.r4.s64 = ctx.r7.s64 + -14696;
	// addi r3,r6,-29432
	ctx.r3.s64 = ctx.r6.s64 + -29432;
	// bl 0x82554798
	ctx.lr = 0x822BEC78;
	sub_82554798(ctx, base);
	// lis r5,-32212
	ctx.r5.s64 = -2111045632;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-14672
	ctx.r4.s64 = ctx.r5.s64 + -14672;
	// addi r3,r3,-29460
	ctx.r3.s64 = ctx.r3.s64 + -29460;
	// bl 0x82554798
	ctx.lr = 0x822BEC8C;
	sub_82554798(ctx, base);
	// lis r11,-32212
	r11.s64 = -2111045632;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-14600
	ctx.r4.s64 = r11.s64 + -14600;
	// addi r3,r10,-29488
	ctx.r3.s64 = ctx.r10.s64 + -29488;
	// bl 0x82554798
	ctx.lr = 0x822BECA0;
	sub_82554798(ctx, base);
	// lis r9,-32212
	ctx.r9.s64 = -2111045632;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-14488
	ctx.r4.s64 = ctx.r9.s64 + -14488;
	// addi r3,r8,-29524
	ctx.r3.s64 = ctx.r8.s64 + -29524;
	// bl 0x82554798
	ctx.lr = 0x822BECB4;
	sub_82554798(ctx, base);
	// lis r7,-32212
	ctx.r7.s64 = -2111045632;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-14464
	ctx.r4.s64 = ctx.r7.s64 + -14464;
	// addi r3,r6,-29552
	ctx.r3.s64 = ctx.r6.s64 + -29552;
	// bl 0x82554798
	ctx.lr = 0x822BECC8;
	sub_82554798(ctx, base);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,0
	ctx.r4.s64 = ctx.r5.s64 + 0;
	// addi r3,r3,-29576
	ctx.r3.s64 = ctx.r3.s64 + -29576;
	// bl 0x82554798
	ctx.lr = 0x822BECDC;
	sub_82554798(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r10,-29600
	ctx.r3.s64 = ctx.r10.s64 + -29600;
	// bl 0x82554798
	ctx.lr = 0x822BECF0;
	sub_82554798(ctx, base);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,0
	ctx.r4.s64 = ctx.r9.s64 + 0;
	// addi r3,r8,-29620
	ctx.r3.s64 = ctx.r8.s64 + -29620;
	// bl 0x82554798
	ctx.lr = 0x822BED04;
	sub_82554798(ctx, base);
	// lis r7,-32212
	ctx.r7.s64 = -2111045632;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-14440
	ctx.r4.s64 = ctx.r7.s64 + -14440;
	// addi r3,r6,-29652
	ctx.r3.s64 = ctx.r6.s64 + -29652;
	// bl 0x82554798
	ctx.lr = 0x822BED18;
	sub_82554798(ctx, base);
	// lis r5,-32212
	ctx.r5.s64 = -2111045632;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-14408
	ctx.r4.s64 = ctx.r5.s64 + -14408;
	// addi r3,r3,-29684
	ctx.r3.s64 = ctx.r3.s64 + -29684;
	// bl 0x82554798
	ctx.lr = 0x822BED2C;
	sub_82554798(ctx, base);
	// lis r11,-32212
	r11.s64 = -2111045632;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-14376
	ctx.r4.s64 = r11.s64 + -14376;
	// addi r3,r10,-29712
	ctx.r3.s64 = ctx.r10.s64 + -29712;
	// bl 0x82554798
	ctx.lr = 0x822BED40;
	sub_82554798(ctx, base);
	// lis r9,-32212
	ctx.r9.s64 = -2111045632;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-14344
	ctx.r4.s64 = ctx.r9.s64 + -14344;
	// addi r3,r8,-29736
	ctx.r3.s64 = ctx.r8.s64 + -29736;
	// bl 0x82554798
	ctx.lr = 0x822BED54;
	sub_82554798(ctx, base);
	// lis r7,-32212
	ctx.r7.s64 = -2111045632;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-14312
	ctx.r4.s64 = ctx.r7.s64 + -14312;
	// addi r3,r6,-29772
	ctx.r3.s64 = ctx.r6.s64 + -29772;
	// bl 0x82554798
	ctx.lr = 0x822BED68;
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

__attribute__((alias("__imp__sub_822BED78"))) PPC_WEAK_FUNC(sub_822BED78);
PPC_FUNC_IMPL(__imp__sub_822BED78) {
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
	ctx.lr = 0x822BED80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mulli r3,r30,30864
	ctx.r3.s64 = r30.s64 * 30864;
	// bl 0x82130528
	ctx.lr = 0x822BED90;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822bedc4
	if (!cr6.gt) goto loc_822BEDC4;
	// mr r31,r28
	r31.u64 = r28.u64;
	// li r29,0
	r29.s64 = 0;
loc_822BEDA4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bedb8
	if (cr6.eq) goto loc_822BEDB8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8254def0
	ctx.lr = 0x822BEDB4;
	sub_8254DEF0(ctx, base);
	// stb r29,30848(r31)
	PPC_STORE_U8(r31.u32 + 30848, r29.u8);
loc_822BEDB8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,30864
	r31.s64 = r31.s64 + 30864;
	// bne 0x822beda4
	if (!cr0.eq) goto loc_822BEDA4;
loc_822BEDC4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822BEDD0"))) PPC_WEAK_FUNC(sub_822BEDD0);
PPC_FUNC_IMPL(__imp__sub_822BEDD0) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// addi r4,r10,-29216
	ctx.r4.s64 = ctx.r10.s64 + -29216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x822BEDFC;
	sub_821CA540(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lis r7,-32114
	ctx.r7.s64 = -2104623104;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,2828(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2828);
	// addi r7,r7,-32416
	ctx.r7.s64 = ctx.r7.s64 + -32416;
	// addi r5,r5,-29224
	ctx.r5.s64 = ctx.r5.s64 + -29224;
	// lwz r6,-32448(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32448);
	// addi r4,r4,-29248
	ctx.r4.s64 = ctx.r4.s64 + -29248;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x821c04b0
	ctx.lr = 0x822BEE2C;
	sub_821C04B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822BEE34;
	sub_821C9A90(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r30,r31,18180
	r30.s64 = r31.s64 + 18180;
	// lwz r3,18180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18180);
	// bl 0x82130588
	ctx.lr = 0x822BEE44;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r11,18180(r31)
	PPC_STORE_U32(r31.u32 + 18180, r11.u32);
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x822bed78
	ctx.lr = 0x822BEE68;
	sub_822BED78(ctx, base);
	// li r11,7
	r11.s64 = 7;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r3,18180(r31)
	PPC_STORE_U32(r31.u32 + 18180, ctx.r3.u32);
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_822BEE94"))) PPC_WEAK_FUNC(sub_822BEE94);
PPC_FUNC_IMPL(__imp__sub_822BEE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BEE98"))) PPC_WEAK_FUNC(sub_822BEE98);
PPC_FUNC_IMPL(__imp__sub_822BEE98) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r30,r31,18180
	r30.s64 = r31.s64 + 18180;
	// lwz r3,18180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18180);
	// bl 0x82130588
	ctx.lr = 0x822BEEBC;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,18180(r31)
	PPC_STORE_U32(r31.u32 + 18180, r11.u32);
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
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

__attribute__((alias("__imp__sub_822BEEF0"))) PPC_WEAK_FUNC(sub_822BEEF0);
PPC_FUNC_IMPL(__imp__sub_822BEEF0) {
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
	// bl 0x8260b730
	ctx.lr = 0x822BEF08;
	sub_8260B730(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r11,776(r31)
	PPC_STORE_U8(r31.u32 + 776, r11.u8);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stb r11,777(r31)
	PPC_STORE_U8(r31.u32 + 777, r11.u8);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stb r11,778(r31)
	PPC_STORE_U8(r31.u32 + 778, r11.u8);
	// stb r11,779(r31)
	PPC_STORE_U8(r31.u32 + 779, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,780(r31)
	PPC_STORE_U8(r31.u32 + 780, r11.u8);
	// lfs f0,-11624(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// stw r11,784(r31)
	PPC_STORE_U32(r31.u32 + 784, r11.u32);
	// lfs f13,31308(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,788(r31)
	PPC_STORE_U8(r31.u32 + 788, r11.u8);
	// lfs f12,-28736(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -28736);
	ctx.f12.f64 = double(temp.f32);
	// stb r11,789(r31)
	PPC_STORE_U8(r31.u32 + 789, r11.u8);
	// stb r11,790(r31)
	PPC_STORE_U8(r31.u32 + 790, r11.u8);
	// stb r11,791(r31)
	PPC_STORE_U8(r31.u32 + 791, r11.u8);
	// stb r11,792(r31)
	PPC_STORE_U8(r31.u32 + 792, r11.u8);
	// stw r11,796(r31)
	PPC_STORE_U32(r31.u32 + 796, r11.u32);
	// stb r11,800(r31)
	PPC_STORE_U8(r31.u32 + 800, r11.u8);
	// stb r11,801(r31)
	PPC_STORE_U8(r31.u32 + 801, r11.u8);
	// stb r11,802(r31)
	PPC_STORE_U8(r31.u32 + 802, r11.u8);
	// stb r11,803(r31)
	PPC_STORE_U8(r31.u32 + 803, r11.u8);
	// stb r11,804(r31)
	PPC_STORE_U8(r31.u32 + 804, r11.u8);
	// stw r11,808(r31)
	PPC_STORE_U32(r31.u32 + 808, r11.u32);
	// stb r11,812(r31)
	PPC_STORE_U8(r31.u32 + 812, r11.u8);
	// stb r11,813(r31)
	PPC_STORE_U8(r31.u32 + 813, r11.u8);
	// stb r11,814(r31)
	PPC_STORE_U8(r31.u32 + 814, r11.u8);
	// stb r11,815(r31)
	PPC_STORE_U8(r31.u32 + 815, r11.u8);
	// stb r11,816(r31)
	PPC_STORE_U8(r31.u32 + 816, r11.u8);
	// stw r11,820(r31)
	PPC_STORE_U32(r31.u32 + 820, r11.u32);
	// stfs f0,832(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 832, temp.u32);
	// stfs f13,836(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 836, temp.u32);
	// stw r11,860(r31)
	PPC_STORE_U32(r31.u32 + 860, r11.u32);
	// stfs f12,840(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 840, temp.u32);
	// stw r11,828(r31)
	PPC_STORE_U32(r31.u32 + 828, r11.u32);
	// stb r11,844(r31)
	PPC_STORE_U8(r31.u32 + 844, r11.u8);
	// stw r11,848(r31)
	PPC_STORE_U32(r31.u32 + 848, r11.u32);
	// stw r11,824(r31)
	PPC_STORE_U32(r31.u32 + 824, r11.u32);
	// stw r11,852(r31)
	PPC_STORE_U32(r31.u32 + 852, r11.u32);
	// stw r11,856(r31)
	PPC_STORE_U32(r31.u32 + 856, r11.u32);
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// stb r11,18268(r7)
	PPC_STORE_U8(ctx.r7.u32 + 18268, r11.u8);
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

__attribute__((alias("__imp__sub_822BEFD0"))) PPC_WEAK_FUNC(sub_822BEFD0);
PPC_FUNC_IMPL(__imp__sub_822BEFD0) {
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
	// lwz r3,848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bf004
	if (cr6.eq) goto loc_822BF004;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82727cc0
	ctx.lr = 0x822BEFF8;
	sub_82727CC0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// bl 0x82727bb0
	ctx.lr = 0x822BF004;
	sub_82727BB0(ctx, base);
loc_822BF004:
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

__attribute__((alias("__imp__sub_822BF018"))) PPC_WEAK_FUNC(sub_822BF018);
PPC_FUNC_IMPL(__imp__sub_822BF018) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822BF020;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r4,-11832(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -11832);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822bf108
	if (cr6.eq) goto loc_822BF108;
	// lwz r11,828(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 828);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bf0c8
	if (cr6.eq) goto loc_822BF0C8;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// li r6,32
	ctx.r6.s64 = 32;
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// addi r30,r1,192
	r30.s64 = ctx.r1.s64 + 192;
	// addi r5,r11,45
	ctx.r5.s64 = r11.s64 + 45;
	// addi r29,r1,208
	r29.s64 = ctx.r1.s64 + 208;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r28,48
	r28.s64 = 48;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822d9f08
	ctx.lr = 0x822BF0A8;
	sub_822D9F08(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// lwz r3,-11832(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -11832);
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822d9f38
	ctx.lr = 0x822BF0C0;
	sub_822D9F38(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_822BF0C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x822d9f08
	ctx.lr = 0x822BF108;
	sub_822D9F08(ctx, base);
loc_822BF108:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822BF110"))) PPC_WEAK_FUNC(sub_822BF110);
PPC_FUNC_IMPL(__imp__sub_822BF110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d4
	ctx.lr = 0x822BF124;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x822BF134;
	sub_822F10D0(ctx, base);
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r11,-7572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lbzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,22080(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 22080);
	// lfs f30,14564(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14564);
	f30.f64 = double(temp.f32);
	// lfs f29,14568(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14568);
	f29.f64 = double(temp.f32);
	// lwz r11,-17936(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -17936);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// bne cr6,0x822bf170
	if (!cr6.eq) goto loc_822BF170;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_822BF170:
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// rlwinm r6,r9,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r7,6928
	ctx.r9.s64 = ctx.r7.s64 + 6928;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r5,r9,8
	ctx.r5.s64 = ctx.r9.s64 + 8;
	// lfsx f28,r6,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	f28.f64 = double(temp.f32);
	// beq cr6,0x822bf190
	if (cr6.eq) goto loc_822BF190;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_822BF190:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,6976
	ctx.r8.s64 = ctx.r10.s64 + 6976;
	// lfsx f27,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	f27.f64 = double(temp.f32);
	// bl 0x821e63f0
	ctx.lr = 0x822BF1A4;
	sub_821E63F0(ctx, base);
	// bl 0x821e6a30
	ctx.lr = 0x822BF1A8;
	sub_821E6A30(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// fdivs f4,f28,f27
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f28.f64 / f27.f64));
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwz r3,-12564(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12564);
	// bl 0x821eb080
	ctx.lr = 0x822BF1C4;
	sub_821EB080(ctx, base);
	// bl 0x8272dc20
	ctx.lr = 0x822BF1C8;
	sub_8272DC20(ctx, base);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lwz r3,-7784(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -7784);
	// bl 0x822ec7c8
	ctx.lr = 0x822BF1D4;
	sub_822EC7C8(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r3,-12012(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -12012);
	// bl 0x821f30b0
	ctx.lr = 0x822BF1E4;
	sub_821F30B0(ctx, base);
	// bl 0x82326e10
	ctx.lr = 0x822BF1E8;
	sub_82326E10(ctx, base);
	// bl 0x82365760
	ctx.lr = 0x822BF1EC;
	sub_82365760(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x822BF1F8;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BF208"))) PPC_WEAK_FUNC(sub_822BF208);
PPC_FUNC_IMPL(__imp__sub_822BF208) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,1164(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1164);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17920(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17920);
	// b 0x82305a00
	sub_82305A00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BF224"))) PPC_WEAK_FUNC(sub_822BF224);
PPC_FUNC_IMPL(__imp__sub_822BF224) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BF228"))) PPC_WEAK_FUNC(sub_822BF228);
PPC_FUNC_IMPL(__imp__sub_822BF228) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bf24c
	if (cr6.eq) goto loc_822BF24C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822bf250
	if (cr6.eq) goto loc_822BF250;
loc_822BF24C:
	// li r11,0
	r11.s64 = 0;
loc_822BF250:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BF258"))) PPC_WEAK_FUNC(sub_822BF258);
PPC_FUNC_IMPL(__imp__sub_822BF258) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r6,r31,788
	ctx.r6.s64 = r31.s64 + 788;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x822BF288;
	sub_8260B740(ctx, base);
	// addi r6,r31,800
	ctx.r6.s64 = r31.s64 + 800;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8260b740
	ctx.lr = 0x822BF2A0;
	sub_8260B740(ctx, base);
	// addi r6,r31,776
	ctx.r6.s64 = r31.s64 + 776;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8260b740
	ctx.lr = 0x822BF2B8;
	sub_8260B740(ctx, base);
	// addi r6,r31,812
	ctx.r6.s64 = r31.s64 + 812;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8260b740
	ctx.lr = 0x822BF2D0;
	sub_8260B740(ctx, base);
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

__attribute__((alias("__imp__sub_822BF2E4"))) PPC_WEAK_FUNC(sub_822BF2E4);
PPC_FUNC_IMPL(__imp__sub_822BF2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BF2E8"))) PPC_WEAK_FUNC(sub_822BF2E8);
PPC_FUNC_IMPL(__imp__sub_822BF2E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822bf310
	if (!cr6.eq) goto loc_822BF310;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
loc_822BF310:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bge cr6,0x822bf358
	if (!cr6.lt) goto loc_822BF358;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r10,r3
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, temp.u32);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f11,8(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// blr 
	return;
loc_822BF358:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x822bf368
	if (!cr6.eq) goto loc_822BF368;
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_822BF368:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r11,r3
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f11,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfsx f11,r11,r3
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, temp.u32);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f10,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stfs f8,8(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BF3AC"))) PPC_WEAK_FUNC(sub_822BF3AC);
PPC_FUNC_IMPL(__imp__sub_822BF3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BF3B0"))) PPC_WEAK_FUNC(sub_822BF3B0);
PPC_FUNC_IMPL(__imp__sub_822BF3B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x823d91e8
	ctx.lr = 0x822BF3B8;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// li r26,16
	r26.s64 = 16;
	// li r27,32
	r27.s64 = 32;
	// li r28,48
	r28.s64 = 48;
	// li r25,64
	r25.s64 = 64;
	// lvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,80
	r29.s64 = 80;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,96
	r30.s64 = 96;
	// lvx128 v62,r24,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,112
	r31.s64 = 112;
	// stvx128 v62,r3,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,128
	ctx.r4.s64 = 128;
	// lvx128 v61,r24,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,144
	ctx.r5.s64 = 144;
	// stvx128 v61,r3,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,160
	ctx.r6.s64 = 160;
	// lvx128 v60,r24,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,176
	ctx.r7.s64 = 176;
	// stvx128 v60,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,192
	ctx.r8.s64 = 192;
	// lvx128 v59,r24,r25
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,208
	ctx.r9.s64 = 208;
	// stvx128 v59,r3,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,224
	ctx.r10.s64 = 224;
	// lvx128 v58,r24,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,240
	r11.s64 = 240;
	// stvx128 v58,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r24,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r24,r31
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r24,r4
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r24,r5
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r24,r6
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r24,r7
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r24,r8
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r24,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r9,r3,r24
	ctx.r9.s64 = r24.s64 - ctx.r3.s64;
	// lvx128 v49,r24,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// lvx128 v48,r24,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,304
	r11.s64 = ctx.r3.s64 + 304;
	// lwz r8,256(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 256);
	// stw r8,256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 256, ctx.r8.u32);
	// lwz r7,260(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 260);
	// stw r7,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, ctx.r7.u32);
	// lwz r6,264(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 264);
	// stw r6,264(r3)
	PPC_STORE_U32(ctx.r3.u32 + 264, ctx.r6.u32);
	// lwz r5,268(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 268);
	// stw r5,268(r3)
	PPC_STORE_U32(ctx.r3.u32 + 268, ctx.r5.u32);
	// lwz r4,272(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 272);
	// stw r4,272(r3)
	PPC_STORE_U32(ctx.r3.u32 + 272, ctx.r4.u32);
	// lwz r8,276(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 276);
	// stw r8,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, ctx.r8.u32);
	// lwz r7,280(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 280);
	// stw r7,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r7.u32);
	// lwz r6,284(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 284);
	// stw r6,284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 284, ctx.r6.u32);
	// lwz r5,288(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 288);
	// lwz r4,288(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	// rlwimi r5,r4,0,1,31
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x7FFFFFFF) | (ctx.r5.u64 & 0xFFFFFFFF80000000);
	// rotlwi r7,r5,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,288(r3)
	PPC_STORE_U32(ctx.r3.u32 + 288, ctx.r5.u32);
	// lwz r8,288(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 288);
	// rlwimi r7,r8,0,1,3
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0x70000000) | (ctx.r7.u64 & 0xFFFFFFFF8FFFFFFF);
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,288(r3)
	PPC_STORE_U32(ctx.r3.u32 + 288, ctx.r7.u32);
	// lwz r6,288(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 288);
	// rlwimi r5,r6,0,4,31
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0xFFFFFFF) | (ctx.r5.u64 & 0xFFFFFFFFF0000000);
	// stw r5,288(r3)
	PPC_STORE_U32(ctx.r3.u32 + 288, ctx.r5.u32);
	// lfs f0,292(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 292);
	f0.f64 = double(temp.f32);
	// stfs f0,292(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// lfs f13,296(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,296(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// lfs f12,300(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 300);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,300(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 300, temp.u32);
loc_822BF50C:
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x822bf50c
	if (!cr0.eq) goto loc_822BF50C;
	// addi r11,r3,560
	r11.s64 = ctx.r3.s64 + 560;
loc_822BF524:
	// lwzx r10,r11,r9
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x822bf524
	if (!cr0.eq) goto loc_822BF524;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822BF53C"))) PPC_WEAK_FUNC(sub_822BF53C);
PPC_FUNC_IMPL(__imp__sub_822BF53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BF540"))) PPC_WEAK_FUNC(sub_822BF540);
PPC_FUNC_IMPL(__imp__sub_822BF540) {
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
	ctx.lr = 0x822BF548;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	r11.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// ori r29,r11,57792
	r29.u64 = r11.u64 | 57792;
	// mullw r3,r30,r29
	ctx.r3.s64 = int64_t(r30.s32) * int64_t(r29.s32);
	// bl 0x82130528
	ctx.lr = 0x822BF560;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822bf58c
	if (!cr6.gt) goto loc_822BF58C;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_822BF570:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bf580
	if (cr6.eq) goto loc_822BF580;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82174240
	ctx.lr = 0x822BF580;
	sub_82174240(ctx, base);
loc_822BF580:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// add r31,r31,r29
	r31.u64 = r31.u64 + r29.u64;
	// bne 0x822bf570
	if (!cr0.eq) goto loc_822BF570;
loc_822BF58C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822BF598"))) PPC_WEAK_FUNC(sub_822BF598);
PPC_FUNC_IMPL(__imp__sub_822BF598) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-28716
	ctx.r9.s64 = r11.s64 + -28716;
	// addi r8,r10,-28728
	ctx.r8.s64 = ctx.r10.s64 + -28728;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// bl 0x821fd178
	ctx.lr = 0x822BF5D0;
	sub_821FD178(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822bf5e8
	if (cr6.eq) goto loc_822BF5E8;
	// bl 0x82130588
	ctx.lr = 0x822BF5E4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822BF5E8:
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

__attribute__((alias("__imp__sub_822BF600"))) PPC_WEAK_FUNC(sub_822BF600);
PPC_FUNC_IMPL(__imp__sub_822BF600) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-28692
	ctx.r9.s64 = r11.s64 + -28692;
	// addi r8,r10,-28708
	ctx.r8.s64 = ctx.r10.s64 + -28708;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// bl 0x82201e10
	ctx.lr = 0x822BF638;
	sub_82201E10(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822bf650
	if (cr6.eq) goto loc_822BF650;
	// bl 0x82130588
	ctx.lr = 0x822BF64C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822BF650:
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

__attribute__((alias("__imp__sub_822BF668"))) PPC_WEAK_FUNC(sub_822BF668);
PPC_FUNC_IMPL(__imp__sub_822BF668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-28552
	ctx.r3.s64 = r11.s64 + -28552;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BF674"))) PPC_WEAK_FUNC(sub_822BF674);
PPC_FUNC_IMPL(__imp__sub_822BF674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BF678"))) PPC_WEAK_FUNC(sub_822BF678);
PPC_FUNC_IMPL(__imp__sub_822BF678) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-28584
	ctx.r9.s64 = r11.s64 + -28584;
	// addi r8,r10,-28596
	ctx.r8.s64 = ctx.r10.s64 + -28596;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// bl 0x826bb0b8
	ctx.lr = 0x822BF6B0;
	sub_826BB0B8(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822bf6c8
	if (cr6.eq) goto loc_822BF6C8;
	// bl 0x82130588
	ctx.lr = 0x822BF6C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822BF6C8:
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

__attribute__((alias("__imp__sub_822BF6E0"))) PPC_WEAK_FUNC(sub_822BF6E0);
PPC_FUNC_IMPL(__imp__sub_822BF6E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-28440
	ctx.r3.s64 = r11.s64 + -28440;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BF6EC"))) PPC_WEAK_FUNC(sub_822BF6EC);
PPC_FUNC_IMPL(__imp__sub_822BF6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BF6F0"))) PPC_WEAK_FUNC(sub_822BF6F0);
PPC_FUNC_IMPL(__imp__sub_822BF6F0) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r11,-28472
	ctx.r8.s64 = r11.s64 + -28472;
	// addi r7,r10,-28516
	ctx.r7.s64 = ctx.r10.s64 + -28516;
	// addi r6,r9,-28528
	ctx.r6.s64 = ctx.r9.s64 + -28528;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r6,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r6.u32);
	// bl 0x826c1cb0
	ctx.lr = 0x822BF734;
	sub_826C1CB0(ctx, base);
	// clrlwi r5,r30,31
	ctx.r5.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822bf74c
	if (cr6.eq) goto loc_822BF74C;
	// bl 0x82130588
	ctx.lr = 0x822BF748;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822BF74C:
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

__attribute__((alias("__imp__sub_822BF764"))) PPC_WEAK_FUNC(sub_822BF764);
PPC_FUNC_IMPL(__imp__sub_822BF764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BF768"))) PPC_WEAK_FUNC(sub_822BF768);
PPC_FUNC_IMPL(__imp__sub_822BF768) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x822bf598
	sub_822BF598(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BF770"))) PPC_WEAK_FUNC(sub_822BF770);
PPC_FUNC_IMPL(__imp__sub_822BF770) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-64
	ctx.r3.s64 = ctx.r3.s64 + -64;
	// b 0x822bf6f0
	sub_822BF6F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BF778"))) PPC_WEAK_FUNC(sub_822BF778);
PPC_FUNC_IMPL(__imp__sub_822BF778) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x822bf600
	sub_822BF600(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BF780"))) PPC_WEAK_FUNC(sub_822BF780);
PPC_FUNC_IMPL(__imp__sub_822BF780) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x822bf6f0
	sub_822BF6F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BF788"))) PPC_WEAK_FUNC(sub_822BF788);
PPC_FUNC_IMPL(__imp__sub_822BF788) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x822bf678
	sub_822BF678(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BF790"))) PPC_WEAK_FUNC(sub_822BF790);
PPC_FUNC_IMPL(__imp__sub_822BF790) {
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
	ctx.lr = 0x822BF798;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,4095
	r11.s64 = 268369920;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// ori r31,r11,65535
	r31.u64 = r11.u64 | 65535;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r28,-1
	r28.s64 = -1;
	// cmplw cr6,r27,r31
	cr6.compare<uint32_t>(r27.u32, r31.u32, xer);
	// rlwinm r3,r27,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x822bf7c4
	if (!cr6.gt) goto loc_822BF7C4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822BF7C4:
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82130550
	ctx.lr = 0x822BF7CC;
	sub_82130550(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// ori r10,r11,52272
	ctx.r10.u64 = r11.u64 | 52272;
	// stwx r3,r29,r10
	PPC_STORE_U32(r29.u32 + ctx.r10.u32, ctx.r3.u32);
	// bgt cr6,0x822bf7f4
	if (cr6.gt) goto loc_822BF7F4;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// li r10,-17
	ctx.r10.s64 = -17;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x822bf7f8
	if (!cr6.gt) goto loc_822BF7F8;
loc_822BF7F4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822BF7F8:
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82130550
	ctx.lr = 0x822BF800;
	sub_82130550(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x822bf844
	if (cr6.eq) goto loc_822BF844;
	// addi r8,r3,16
	ctx.r8.s64 = ctx.r3.s64 + 16;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// addic. r9,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r9.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// blt 0x822bf83c
	if (cr0.lt) goto loc_822BF83C;
loc_822BF820:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bge 0x822bf820
	if (!cr0.lt) goto loc_822BF820;
loc_822BF83C:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// b 0x822bf848
	goto loc_822BF848;
loc_822BF844:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_822BF848:
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// addis r7,r29,1
	ctx.r7.s64 = r29.s64 + 65536;
	// ori r6,r9,52276
	ctx.r6.u64 = ctx.r9.u64 | 52276;
	// addi r7,r7,-13280
	ctx.r7.s64 = ctx.r7.s64 + -13280;
	// ori r5,r8,52260
	ctx.r5.u64 = ctx.r8.u64 | 52260;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r11,r29,r6
	PPC_STORE_U32(r29.u32 + ctx.r6.u32, r11.u32);
	// stw r30,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r30.u32);
	// stwx r27,r29,r5
	PPC_STORE_U32(r29.u32 + ctx.r5.u32, r27.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r10,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822BF880"))) PPC_WEAK_FUNC(sub_822BF880);
PPC_FUNC_IMPL(__imp__sub_822BF880) {
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
	// li r3,868
	ctx.r3.s64 = 868;
	// bl 0x82130528
	ctx.lr = 0x822BF894;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bf8a4
	if (cr6.eq) goto loc_822BF8A4;
	// bl 0x822beef0
	ctx.lr = 0x822BF8A0;
	sub_822BEEF0(ctx, base);
	// b 0x822bf8a8
	goto loc_822BF8A8;
loc_822BF8A4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822BF8A8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,18264(r11)
	PPC_STORE_U32(r11.u32 + 18264, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BF8C0"))) PPC_WEAK_FUNC(sub_822BF8C0);
PPC_FUNC_IMPL(__imp__sub_822BF8C0) {
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
	// lwz r4,852(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 852);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822bf910
	if (cr6.eq) goto loc_822BF910;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// bl 0x822e5108
	ctx.lr = 0x822BF8F0;
	sub_822E5108(ctx, base);
	// lwz r3,852(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 852);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bf910
	if (cr6.eq) goto loc_822BF910;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BF910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822BF910:
	// lwz r3,856(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bf930
	if (cr6.eq) goto loc_822BF930;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BF930;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822BF930:
	// lwz r30,864(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822bf94c
	if (cr6.eq) goto loc_822BF94C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822cbe30
	ctx.lr = 0x822BF944;
	sub_822CBE30(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822BF94C;
	sub_82130588(ctx, base);
loc_822BF94C:
	// lwz r3,860(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// bl 0x82130588
	ctx.lr = 0x822BF954;
	sub_82130588(ctx, base);
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

__attribute__((alias("__imp__sub_822BF96C"))) PPC_WEAK_FUNC(sub_822BF96C);
PPC_FUNC_IMPL(__imp__sub_822BF96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BF970"))) PPC_WEAK_FUNC(sub_822BF970);
PPC_FUNC_IMPL(__imp__sub_822BF970) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r3,r11,29952
	ctx.r3.s64 = r11.s64 + 29952;
	// lwz r11,29952(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 29952);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BF994;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,18352
	ctx.r8.s64 = ctx.r9.s64 + 18352;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,18352(r9)
	PPC_STORE_U32(ctx.r9.u32 + 18352, r11.u32);
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// bl 0x822c4eb8
	ctx.lr = 0x822BF9B0;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x822BF9B8;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bf9cc
	if (cr6.eq) goto loc_822BF9CC;
	// bl 0x822c4eb8
	ctx.lr = 0x822BF9C4;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c5258
	ctx.lr = 0x822BF9CC;
	sub_822C5258(ctx, base);
loc_822BF9CC:
	// bl 0x822c4eb8
	ctx.lr = 0x822BF9D0;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c4ec8
	ctx.lr = 0x822BF9D8;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bf9ec
	if (cr6.eq) goto loc_822BF9EC;
	// bl 0x822c4eb8
	ctx.lr = 0x822BF9E4;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c5258
	ctx.lr = 0x822BF9EC;
	sub_822C5258(ctx, base);
loc_822BF9EC:
	// bl 0x822c4eb8
	ctx.lr = 0x822BF9F0;
	sub_822C4EB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822c4ec8
	ctx.lr = 0x822BF9F8;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bfa0c
	if (cr6.eq) goto loc_822BFA0C;
	// bl 0x822c4eb8
	ctx.lr = 0x822BFA04;
	sub_822C4EB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822c5258
	ctx.lr = 0x822BFA0C;
	sub_822C5258(ctx, base);
loc_822BFA0C:
	// bl 0x822c4eb8
	ctx.lr = 0x822BFA10;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822c4ec8
	ctx.lr = 0x822BFA18;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bfa2c
	if (cr6.eq) goto loc_822BFA2C;
	// bl 0x822c4eb8
	ctx.lr = 0x822BFA24;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822c5258
	ctx.lr = 0x822BFA2C;
	sub_822C5258(ctx, base);
loc_822BFA2C:
	// bl 0x82727618
	ctx.lr = 0x822BFA30;
	sub_82727618(ctx, base);
	// bl 0x821e60c0
	ctx.lr = 0x822BFA34;
	sub_821E60C0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822bfa48
	if (cr6.eq) goto loc_822BFA48;
	// bl 0x821f15c8
	ctx.lr = 0x822BFA48;
	sub_821F15C8(ctx, base);
loc_822BFA48:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BFA58"))) PPC_WEAK_FUNC(sub_822BFA58);
PPC_FUNC_IMPL(__imp__sub_822BFA58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822bfa8c
	if (cr6.eq) goto loc_822BFA8C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822bfa90
	if (cr6.eq) goto loc_822BFA90;
loc_822BFA8C:
	// li r11,0
	r11.s64 = 0;
loc_822BFA90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r31,-32115
	r31.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822bfb10
	if (!cr6.eq) goto loc_822BFB10;
	// lbz r11,776(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 776);
	// lbz r10,778(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 778);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822bfae8
	if (cr6.eq) goto loc_822BFAE8;
	// lbz r10,779(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 779);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822bfaec
	if (cr6.eq) goto loc_822BFAEC;
loc_822BFAE8:
	// li r11,0
	r11.s64 = 0;
loc_822BFAEC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bfb10
	if (cr6.eq) goto loc_822BFB10;
	// lwz r3,-12356(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12356);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BFB10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822BFB10:
	// lwz r3,-12356(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12356);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822BFB24;
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

__attribute__((alias("__imp__sub_822BFB38"))) PPC_WEAK_FUNC(sub_822BFB38);
PPC_FUNC_IMPL(__imp__sub_822BFB38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2836(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x821f8190
	sub_821F8190(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BFB4C"))) PPC_WEAK_FUNC(sub_822BFB4C);
PPC_FUNC_IMPL(__imp__sub_822BFB4C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BFB50"))) PPC_WEAK_FUNC(sub_822BFB50);
PPC_FUNC_IMPL(__imp__sub_822BFB50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822bfb68
	if (cr6.eq) goto loc_822BFB68;
	// lbz r3,14(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 14);
	// blr 
	return;
loc_822BFB68:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BFB70"))) PPC_WEAK_FUNC(sub_822BFB70);
PPC_FUNC_IMPL(__imp__sub_822BFB70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,2836(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x821f8188
	sub_821F8188(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BFB8C"))) PPC_WEAK_FUNC(sub_822BFB8C);
PPC_FUNC_IMPL(__imp__sub_822BFB8C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BFB90"))) PPC_WEAK_FUNC(sub_822BFB90);
PPC_FUNC_IMPL(__imp__sub_822BFB90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2836(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x821f98e0
	sub_821F98E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822BFBA4"))) PPC_WEAK_FUNC(sub_822BFBA4);
PPC_FUNC_IMPL(__imp__sub_822BFBA4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822BFBA8"))) PPC_WEAK_FUNC(sub_822BFBA8);
PPC_FUNC_IMPL(__imp__sub_822BFBA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f28{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d8
	ctx.lr = 0x822BFBC0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fmr f28,f1
	ctx.fpscr.disableFlushModeUnconditional();
	f28.f64 = ctx.f1.f64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x822BFC1C;
	sub_82202EC0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,18264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 18264);
	// stfs f28,832(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 832, temp.u32);
	// stb r30,844(r11)
	PPC_STORE_U8(r11.u32 + 844, r30.u8);
	// lwz r11,18264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 18264);
	// lwz r6,828(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// stb r7,856(r6)
	PPC_STORE_U8(ctx.r6.u32 + 856, ctx.r7.u8);
	// lwz r11,18264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 18264);
	// lwz r5,828(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 828);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r5
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822BFC68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f31.f64);
	// bne cr6,0x822bfc98
	if (!cr6.eq) goto loc_822BFC98;
	// fcmpu cr6,f29,f31
	cr6.compare(f29.f64, f31.f64);
	// bne cr6,0x822bfc98
	if (!cr6.eq) goto loc_822BFC98;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,18264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 18264);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// stfs f0,836(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 836, temp.u32);
	// lfs f0,-28736(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28736);
	f0.f64 = double(temp.f32);
	// stfs f0,840(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 840, temp.u32);
	// b 0x822bfca4
	goto loc_822BFCA4;
loc_822BFC98:
	// lwz r11,18264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 18264);
	// stfs f30,836(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 836, temp.u32);
	// stfs f29,840(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 840, temp.u32);
loc_822BFCA4:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x822BFCB0;
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

__attribute__((alias("__imp__sub_822BFCC4"))) PPC_WEAK_FUNC(sub_822BFCC4);
PPC_FUNC_IMPL(__imp__sub_822BFCC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BFCC8"))) PPC_WEAK_FUNC(sub_822BFCC8);
PPC_FUNC_IMPL(__imp__sub_822BFCC8) {
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
	// li r3,13296
	ctx.r3.s64 = 13296;
	// bl 0x82130528
	ctx.lr = 0x822BFCE0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bfd24
	if (cr6.eq) goto loc_822BFD24;
	// bl 0x821fded8
	ctx.lr = 0x822BFCF0;
	sub_821FDED8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r11,-28716
	ctx.r8.s64 = r11.s64 + -28716;
	// addi r7,r10,-28728
	ctx.r7.s64 = ctx.r10.s64 + -28728;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// stw r31,-10236(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10236, r31.u32);
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
loc_822BFD24:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10236(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10236, r11.u32);
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

__attribute__((alias("__imp__sub_822BFD44"))) PPC_WEAK_FUNC(sub_822BFD44);
PPC_FUNC_IMPL(__imp__sub_822BFD44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BFD48"))) PPC_WEAK_FUNC(sub_822BFD48);
PPC_FUNC_IMPL(__imp__sub_822BFD48) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x822BFD60;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bfd8c
	if (cr6.eq) goto loc_822BFD8C;
	// bl 0x821f7e40
	ctx.lr = 0x822BFD70;
	sub_821F7E40(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r31,2836(r11)
	PPC_STORE_U32(r11.u32 + 2836, r31.u32);
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
loc_822BFD8C:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// stw r11,2836(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2836, r11.u32);
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

__attribute__((alias("__imp__sub_822BFDAC"))) PPC_WEAK_FUNC(sub_822BFDAC);
PPC_FUNC_IMPL(__imp__sub_822BFDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BFDB0"))) PPC_WEAK_FUNC(sub_822BFDB0);
PPC_FUNC_IMPL(__imp__sub_822BFDB0) {
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
	// li r3,10864
	ctx.r3.s64 = 10864;
	// bl 0x82130528
	ctx.lr = 0x822BFDC8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bfe0c
	if (cr6.eq) goto loc_822BFE0C;
	// bl 0x82201d08
	ctx.lr = 0x822BFDD8;
	sub_82201D08(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r8,r11,-28692
	ctx.r8.s64 = r11.s64 + -28692;
	// addi r7,r10,-28708
	ctx.r7.s64 = ctx.r10.s64 + -28708;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// stw r31,2832(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2832, r31.u32);
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
loc_822BFE0C:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// stw r11,2832(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2832, r11.u32);
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

__attribute__((alias("__imp__sub_822BFE2C"))) PPC_WEAK_FUNC(sub_822BFE2C);
PPC_FUNC_IMPL(__imp__sub_822BFE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BFE30"))) PPC_WEAK_FUNC(sub_822BFE30);
PPC_FUNC_IMPL(__imp__sub_822BFE30) {
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
	// li r3,552
	ctx.r3.s64 = 552;
	// bl 0x82130528
	ctx.lr = 0x822BFE48;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bfe8c
	if (cr6.eq) goto loc_822BFE8C;
	// bl 0x826ba578
	ctx.lr = 0x822BFE58;
	sub_826BA578(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r11,-28584
	ctx.r8.s64 = r11.s64 + -28584;
	// addi r7,r10,-28596
	ctx.r7.s64 = ctx.r10.s64 + -28596;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// stw r31,18508(r9)
	PPC_STORE_U32(ctx.r9.u32 + 18508, r31.u32);
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
loc_822BFE8C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,18508(r10)
	PPC_STORE_U32(ctx.r10.u32 + 18508, r11.u32);
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

__attribute__((alias("__imp__sub_822BFEAC"))) PPC_WEAK_FUNC(sub_822BFEAC);
PPC_FUNC_IMPL(__imp__sub_822BFEAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BFEB0"))) PPC_WEAK_FUNC(sub_822BFEB0);
PPC_FUNC_IMPL(__imp__sub_822BFEB0) {
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
	// lis r3,1
	ctx.r3.s64 = 65536;
	// ori r3,r3,27792
	ctx.r3.u64 = ctx.r3.u64 | 27792;
	// bl 0x82130528
	ctx.lr = 0x822BFECC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822bff1c
	if (cr6.eq) goto loc_822BFF1C;
	// bl 0x826c16c0
	ctx.lr = 0x822BFEDC;
	sub_826C16C0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// addi r7,r11,-28472
	ctx.r7.s64 = r11.s64 + -28472;
	// addi r6,r10,-28516
	ctx.r6.s64 = ctx.r10.s64 + -28516;
	// addi r5,r9,-28528
	ctx.r5.s64 = ctx.r9.s64 + -28528;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// stw r5,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r5.u32);
	// stw r31,-10020(r8)
	PPC_STORE_U32(ctx.r8.u32 + -10020, r31.u32);
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
loc_822BFF1C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10020(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10020, r11.u32);
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

__attribute__((alias("__imp__sub_822BFF3C"))) PPC_WEAK_FUNC(sub_822BFF3C);
PPC_FUNC_IMPL(__imp__sub_822BFF3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822BFF40"))) PPC_WEAK_FUNC(sub_822BFF40);
PPC_FUNC_IMPL(__imp__sub_822BFF40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x822BFF48;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,32
	r11.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// stw r3,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r3.u32);
	// addi r8,r4,64
	ctx.r8.s64 = ctx.r4.s64 + 64;
	// stw r4,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r4.u32);
	// addi r7,r3,64
	ctx.r7.s64 = ctx.r3.s64 + 64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// addi r6,r4,128
	ctx.r6.s64 = ctx.r4.s64 + 128;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// addi r5,r3,128
	ctx.r5.s64 = ctx.r3.s64 + 128;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// addi r31,r4,192
	r31.s64 = ctx.r4.s64 + 192;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// addi r30,r3,192
	r30.s64 = ctx.r3.s64 + 192;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// addi r29,r4,256
	r29.s64 = ctx.r4.s64 + 256;
	// addi r28,r3,256
	r28.s64 = ctx.r3.s64 + 256;
	// addi r26,r3,384
	r26.s64 = ctx.r3.s64 + 384;
	// addi r27,r4,384
	r27.s64 = ctx.r4.s64 + 384;
	// addi r25,r4,448
	r25.s64 = ctx.r4.s64 + 448;
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r26.u32);
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// addi r26,r4,512
	r26.s64 = ctx.r4.s64 + 512;
	// stw r25,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r25.u32);
	// addi r27,r3,448
	r27.s64 = ctx.r3.s64 + 448;
	// addi r25,r3,512
	r25.s64 = ctx.r3.s64 + 512;
	// stw r26,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r26.u32);
	// addi r26,r3,576
	r26.s64 = ctx.r3.s64 + 576;
	// stw r27,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r27.u32);
	// stw r25,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r25.u32);
	// addi r27,r4,576
	r27.s64 = ctx.r4.s64 + 576;
	// addi r25,r4,640
	r25.s64 = ctx.r4.s64 + 640;
	// stw r26,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r26.u32);
	// stw r27,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r27.u32);
	// addi r26,r3,640
	r26.s64 = ctx.r3.s64 + 640;
	// lvx128 v62,r4,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r25,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r25.u32);
	// stvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r4,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r8,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r8,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r8,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,320
	ctx.r8.s64 = ctx.r4.s64 + 320;
	// stvx128 v56,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r3,320
	ctx.r7.s64 = ctx.r3.s64 + 320;
	// lvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// lvx128 v54,r6,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r5,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r6,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r5,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r6,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r5,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r31
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r31,r10
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r31,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r31,r9
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r29
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r29,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r28,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r29,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r28,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r29,r9
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r28,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lvx128 v43,r0,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stvx128 v43,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r29,48
	r29.s64 = 48;
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r27,16
	r27.s64 = 16;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r28,32
	r28.s64 = 32;
	// lvx128 v42,r10,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stvx128 v42,r7,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lvx128 v41,r5,r6
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// stvx128 v41,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v40,r7,r8
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stvx128 v40,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,6
	ctx.r9.s64 = 6;
	// stvx128 v39,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r26.u32);
	// lvx128 v38,r11,r27
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r11,r28
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r11,r29
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stvx128 v36,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r11,r27
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r11,r28
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r11,r29
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// stvx128 v32,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// stvx128 v60,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,136(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r27
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// rotlwi r11,r25,0
	r11.u64 = __builtin_rotateleft32(r25.u32, 0);
	// rotlwi r10,r26,0
	ctx.r10.u64 = __builtin_rotateleft32(r26.u32, 0);
loc_822C019C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822c019c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822C019C;
	// lwz r31,268(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r30,260(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// addi r11,r31,664
	r11.s64 = r31.s64 + 664;
	// addi r10,r30,664
	ctx.r10.s64 = r30.s64 + 664;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822C01C8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822c01c8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822C01C8;
	// lwz r10,688(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// li r11,736
	r11.s64 = 736;
	// addi r4,r31,753
	ctx.r4.s64 = r31.s64 + 753;
	// addi r3,r30,753
	ctx.r3.s64 = r30.s64 + 753;
	// li r5,15
	ctx.r5.s64 = 15;
	// stw r10,688(r30)
	PPC_STORE_U32(r30.u32 + 688, ctx.r10.u32);
	// lwz r9,692(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// stw r9,692(r30)
	PPC_STORE_U32(r30.u32 + 692, ctx.r9.u32);
	// lfs f0,696(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 696);
	f0.f64 = double(temp.f32);
	// stfs f0,696(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 696, temp.u32);
	// lfs f13,700(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 700);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,700(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 700, temp.u32);
	// lfs f12,704(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 704);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,704(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 704, temp.u32);
	// lfs f11,708(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 708);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,708(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 708, temp.u32);
	// lfs f10,712(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 712);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,712(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 712, temp.u32);
	// lfs f9,716(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 716);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,716(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 716, temp.u32);
	// lfs f8,720(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 720);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,720(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r30.u32 + 720, temp.u32);
	// lfs f7,724(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 724);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,724(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 724, temp.u32);
	// lfs f6,728(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 728);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,728(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 728, temp.u32);
	// lfs f5,732(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 732);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,732(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r30.u32 + 732, temp.u32);
	// lvx128 v55,r31,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,752(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 752);
	// stb r8,752(r30)
	PPC_STORE_U8(r30.u32 + 752, ctx.r8.u8);
	// bl 0x823da950
	ctx.lr = 0x822C0260;
	sub_823DA950(ctx, base);
	// li r5,768
	ctx.r5.s64 = 768;
	// addi r11,r30,768
	r11.s64 = r30.s64 + 768;
	// li r4,784
	ctx.r4.s64 = 784;
	// li r26,800
	r26.s64 = 800;
	// li r25,816
	r25.s64 = 816;
	// lvx128 v54,r31,r5
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r24,832
	r24.s64 = 832;
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r23,64
	r23.s64 = 64;
	// li r22,848
	r22.s64 = 848;
	// li r21,80
	r21.s64 = 80;
	// li r9,864
	ctx.r9.s64 = 864;
	// li r10,880
	ctx.r10.s64 = 880;
	// li r6,896
	ctx.r6.s64 = 896;
	// li r7,912
	ctx.r7.s64 = 912;
	// li r8,928
	ctx.r8.s64 = 928;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v53,r31,r4
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r31,r26
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r31,r25
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r31,r24
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r11,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r31,r22
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r11,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,976
	r11.s64 = 976;
	// lvx128 v48,r31,r9
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,944
	ctx.r9.s64 = 944;
	// lvx128 v47,r31,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,960
	ctx.r10.s64 = 960;
	// lvx128 v46,r31,r6
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r30,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r31,r7
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r30,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r31,r8
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r31,r9
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r31,r10
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r31,r11
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_822C0320"))) PPC_WEAK_FUNC(sub_822C0320);
PPC_FUNC_IMPL(__imp__sub_822C0320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x822C0328;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9d8
	ctx.lr = 0x822C0330;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// addi r10,r11,-6420
	ctx.r10.s64 = r11.s64 + -6420;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c0970
	if (!cr6.eq) goto loc_822C0970;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
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
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r30,17268(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lfs f0,21528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21528);
	f0.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,31308(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31308);
	f0.f64 = double(temp.f32);
	// li r24,-1
	r24.s64 = -1;
	// lfs f13,-28736(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -28736);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f29,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f29.f64 = double(temp.f32);
	// fmr f30,f31
	f30.f64 = f31.f64;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f29,92(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822c03ec
	if (cr6.eq) goto loc_822C03EC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822C03DC;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822c03f0
	if (!cr6.eq) goto loc_822C03F0;
loc_822C03EC:
	// li r11,0
	r11.s64 = 0;
loc_822C03F0:
	// clrlwi r22,r11,24
	r22.u64 = r11.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x822c0440
	if (cr6.eq) goto loc_822C0440;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822C0410;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x822C0418;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c0438
	if (!cr6.eq) goto loc_822C0438;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x822C042C;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c043c
	if (cr6.eq) goto loc_822C043C;
loc_822C0438:
	// li r31,1
	r31.s64 = 1;
loc_822C043C:
	// lwz r30,17268(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 17268);
loc_822C0440:
	// clrlwi r19,r31,24
	r19.u64 = r31.u32 & 0xFF;
	// li r26,16
	r26.s64 = 16;
	// li r27,32
	r27.s64 = 32;
	// li r28,48
	r28.s64 = 48;
	// lis r21,-32119
	r21.s64 = -2104950784;
	// lis r23,-32120
	r23.s64 = -2105016320;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x822c051c
	if (!cr6.eq) goto loc_822C051C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-10008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10008);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c051c
	if (cr6.eq) goto loc_822C051C;
	// bl 0x823cdc90
	ctx.lr = 0x822C0474;
	sub_823CDC90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c0518
	if (cr6.eq) goto loc_822C0518;
	// lwz r10,-10008(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10008);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r9,-17936(r21)
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + -17936);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lwz r8,-8092(r23)
	ctx.r8.u64 = PPC_LOAD_U32(r23.u32 + -8092);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r9,45
	ctx.r3.s64 = ctx.r9.s64 + 45;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lfs f0,30288(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30288);
	f0.f64 = double(temp.f32);
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r26
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r27
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r28
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwzx r3,r3,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// lfs f13,104(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f28,f13,f0
	f28.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x82171600
	ctx.lr = 0x822C04E8;
	sub_82171600(ctx, base);
	// fdivs f12,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f28.f64 / ctx.f1.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r29,1
	r29.s64 = 1;
	// li r24,5
	r24.s64 = 5;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x822c0614
	if (cr6.eq) goto loc_822C0614;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822C050C;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x822C0510;
	sub_822A5578(ctx, base);
	// stfs f31,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// b 0x822c0614
	goto loc_822C0614;
loc_822C0518:
	// lwz r30,17268(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 17268);
loc_822C051C:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x822c0614
	if (cr6.eq) goto loc_822C0614;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822C0530;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c0614
	if (cr6.eq) goto loc_822C0614;
	// bl 0x822afa10
	ctx.lr = 0x822C0548;
	sub_822AFA10(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r3,r26
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r3,r27
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r3,r28
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// bl 0x822afa30
	ctx.lr = 0x822C0580;
	sub_822AFA30(ctx, base);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// bl 0x822afa50
	ctx.lr = 0x822C058C;
	sub_822AFA50(ctx, base);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// bl 0x822afa60
	ctx.lr = 0x822C0598;
	sub_822AFA60(ctx, base);
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// li r29,1
	r29.s64 = 1;
	// bl 0x822afa40
	ctx.lr = 0x822C05A8;
	sub_822AFA40(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822c05dc
	if (cr6.eq) goto loc_822C05DC;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822c05c8
	if (!cr6.eq) goto loc_822C05C8;
	// li r11,0
	r11.s64 = 0;
loc_822C05C8:
	// lbz r11,123(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 123);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c05dc
	if (cr6.eq) goto loc_822C05DC;
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
	// b 0x822c05e8
	goto loc_822C05E8;
loc_822C05DC:
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// bl 0x822afa40
	ctx.lr = 0x822C05E4;
	sub_822AFA40(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
loc_822C05E8:
	// lwz r11,880(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lwz r4,72(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822C05F8;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822c0608
	if (cr6.eq) goto loc_822C0608;
	// li r11,2
	r11.s64 = 2;
	// b 0x822c0610
	goto loc_822C0610;
loc_822C0608:
	// lwz r11,880(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lwz r11,80(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 80);
loc_822C0610:
	// mr r24,r11
	r24.u64 = r11.u64;
loc_822C0614:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bb5b0
	ctx.lr = 0x822C0628;
	sub_823BB5B0(ctx, base);
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// ori r30,r9,4992
	r30.u64 = ctx.r9.u64 | 4992;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c065c
	if (cr6.eq) goto loc_822C065C;
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c076c
	if (cr6.eq) goto loc_822C076C;
	// lbzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c076c
	if (cr6.eq) goto loc_822C076C;
loc_822C065C:
	// lwz r3,828(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 828);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0714
	if (cr6.eq) goto loc_822C0714;
	// bl 0x82502e18
	ctx.lr = 0x822C066C;
	sub_82502E18(ctx, base);
	// lwz r10,828(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 828);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822C0690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v50,r0,r3
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lbz r4,844(r20)
	ctx.r4.u64 = PPC_LOAD_U8(r20.u32 + 844);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f0,832(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 832);
	f0.f64 = double(temp.f32);
	// lfs f13,836(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 836);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stvx128 v50,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,840(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 840);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v49,r3,r26
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r3,r27
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r3,r28
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stvx128 v47,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822c06fc
	if (cr6.eq) goto loc_822C06FC;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// fmr f30,f29
	f30.f64 = f29.f64;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204058
	ctx.lr = 0x822C06F8;
	sub_82204058(ctx, base);
	// b 0x822c0764
	goto loc_822C0764;
loc_822C06FC:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204058
	ctx.lr = 0x822C0710;
	sub_82204058(ctx, base);
	// b 0x822c0764
	goto loc_822C0764;
loc_822C0714:
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// stfs f31,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r7,r9,2256
	ctx.r7.s64 = ctx.r9.s64 + 2256;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f31,168(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stfs f0,164(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r5,r5,-31616
	ctx.r5.s64 = ctx.r5.s64 + -31616;
	// lvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v45,v63,v46
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v46.f32)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v45,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x822C0764;
	sub_82202EC0(ctx, base);
loc_822C0764:
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// li r24,6
	r24.s64 = 6;
loc_822C076C:
	// lwz r10,-10236(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822c07c4
	if (cr6.eq) goto loc_822C07C4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c0790
	if (cr6.eq) goto loc_822C0790;
	// lbzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c07c4
	if (!cr6.eq) goto loc_822C07C4;
loc_822C0790:
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8220aa68
	ctx.lr = 0x822C07A8;
	sub_8220AA68(ctx, base);
	// lbz r11,844(r20)
	r11.u64 = PPC_LOAD_U8(r20.u32 + 844);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// beq cr6,0x822c07c0
	if (cr6.eq) goto loc_822C07C0;
	// fmr f30,f29
	ctx.fpscr.disableFlushMode();
	f30.f64 = f29.f64;
	// b 0x822c07c4
	goto loc_822C07C4;
loc_822C07C0:
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
loc_822C07C4:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x822c081c
	if (cr6.eq) goto loc_822C081C;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x822c081c
	if (!cr6.eq) goto loc_822C081C;
	// lwz r3,860(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 860);
	// bl 0x823ce098
	ctx.lr = 0x822C07DC;
	sub_823CE098(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,860(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 860);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823cc2e8
	ctx.lr = 0x822C07EC;
	sub_823CC2E8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-10948(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10948);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822c0818
	if (cr6.eq) goto loc_822C0818;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r3,860(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 860);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f1,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ce2c0
	ctx.lr = 0x822C0818;
	sub_823CE2C0(ctx, base);
loc_822C0818:
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
loc_822C081C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c0868
	if (cr6.eq) goto loc_822C0868;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4990
	ctx.r9.u64 = ctx.r10.u64 | 4990;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822c0864
	if (!cr6.eq) goto loc_822C0864;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4994
	ctx.r9.u64 = ctx.r10.u64 | 4994;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822c0864
	if (!cr6.eq) goto loc_822C0864;
	// bl 0x82207e88
	ctx.lr = 0x822C0858;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c0868
	if (cr6.eq) goto loc_822C0868;
loc_822C0864:
	// li r24,6
	r24.s64 = 6;
loc_822C0868:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lwz r3,-8092(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -8092);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// lvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,240
	r11.s64 = ctx.r1.s64 + 240;
	// lvx128 v42,r0,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r8
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stvx128 v44,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822e5188
	ctx.lr = 0x822C08B4;
	sub_822E5188(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// addi r3,r10,18404
	ctx.r3.s64 = ctx.r10.s64 + 18404;
	// bl 0x821c07c0
	ctx.lr = 0x822C08C4;
	sub_821C07C0(ctx, base);
	// lfs f13,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// bne cr6,0x822c08ec
	if (!cr6.eq) goto loc_822C08EC;
	// lwz r3,-8092(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -8092);
	// lfs f3,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// lfs f1,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822e5e10
	ctx.lr = 0x822C08E8;
	sub_822E5E10(ctx, base);
	// b 0x822c0934
	goto loc_822C0934;
loc_822C08EC:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,-17936(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -17936);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r10,-8092(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + -8092);
	// addi r7,r11,45
	ctx.r7.s64 = r11.s64 + 45;
	// lfs f6,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f4,f13,f0
	ctx.f4.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f4,92(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f0,-28432(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -28432);
	f0.f64 = double(temp.f32);
	// lwzx r3,r6,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// fmuls f0,f4,f0
	f0.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fneg f3,f4
	ctx.f3.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// fmr f2,f0
	ctx.f2.f64 = f0.f64;
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// bl 0x8217cc80
	ctx.lr = 0x822C0934;
	sub_8217CC80(ctx, base);
loc_822C0934:
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x822c0940
	if (cr6.eq) goto loc_822C0940;
	// li r24,6
	r24.s64 = 6;
loc_822C0940:
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821e61c8
	ctx.lr = 0x822C0948;
	sub_821E61C8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lbz r10,1757(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1757);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c0968
	if (!cr6.eq) goto loc_822C0968;
	// lwz r11,1744(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1744);
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// beq cr6,0x822c0970
	if (cr6.eq) goto loc_822C0970;
loc_822C0968:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821ed418
	ctx.lr = 0x822C0970;
	sub_821ED418(ctx, base);
loc_822C0970:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba24
	ctx.lr = 0x822C097C;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822C0980"))) PPC_WEAK_FUNC(sub_822C0980);
PPC_FUNC_IMPL(__imp__sub_822C0980) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822C0988;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32130
	r25.s64 = -2105671680;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r11,22080(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 22080);
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8217c658
	ctx.lr = 0x822C09B8;
	sub_8217C658(ctx, base);
	// lis r29,-32119
	r29.s64 = -2104950784;
	// li r11,1
	r11.s64 = 1;
	// lwz r3,-18004(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -18004);
	// lwz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bgt cr6,0x822c09d4
	if (cr6.gt) goto loc_822C09D4;
	// li r11,0
	r11.s64 = 0;
loc_822C09D4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c09f0
	if (cr6.eq) goto loc_822C09F0;
	// bl 0x82304428
	ctx.lr = 0x822C09E4;
	sub_82304428(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_822C09F0:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lbz r9,14546(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 14546);
	// stb r9,393(r10)
	PPC_STORE_U8(ctx.r10.u32 + 393, ctx.r9.u8);
	// lwz r3,-18004(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -18004);
	// bl 0x823045e0
	ctx.lr = 0x822C0A0C;
	sub_823045E0(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r3,-10236(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10236);
	// bl 0x821fd640
	ctx.lr = 0x822C0A18;
	sub_821FD640(ctx, base);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r7,r8,29952
	ctx.r7.s64 = ctx.r8.s64 + 29952;
	// lfs f31,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f31.f64 = double(temp.f32);
	// bl 0x822c4eb8
	ctx.lr = 0x822C0A28;
	sub_822C4EB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822c4ec8
	ctx.lr = 0x822C0A30;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0a48
	if (cr6.eq) goto loc_822C0A48;
	// bl 0x822c4eb8
	ctx.lr = 0x822C0A3C;
	sub_822C4EB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822c5348
	ctx.lr = 0x822C0A48;
	sub_822C5348(ctx, base);
loc_822C0A48:
	// bl 0x822c4eb8
	ctx.lr = 0x822C0A4C;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c4ec8
	ctx.lr = 0x822C0A54;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0a6c
	if (cr6.eq) goto loc_822C0A6C;
	// bl 0x822c4eb8
	ctx.lr = 0x822C0A60;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822c5348
	ctx.lr = 0x822C0A6C;
	sub_822C5348(ctx, base);
loc_822C0A6C:
	// bl 0x822c4eb8
	ctx.lr = 0x822C0A70;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x822C0A78;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0a90
	if (cr6.eq) goto loc_822C0A90;
	// bl 0x822c4eb8
	ctx.lr = 0x822C0A84;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822c5348
	ctx.lr = 0x822C0A90;
	sub_822C5348(ctx, base);
loc_822C0A90:
	// bl 0x822c4eb8
	ctx.lr = 0x822C0A94;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822c4ec8
	ctx.lr = 0x822C0A9C;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0ab4
	if (cr6.eq) goto loc_822C0AB4;
	// bl 0x822c4eb8
	ctx.lr = 0x822C0AA8;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822c5348
	ctx.lr = 0x822C0AB4;
	sub_822C5348(ctx, base);
loc_822C0AB4:
	// lwz r3,864(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 864);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0ac4
	if (cr6.eq) goto loc_822C0AC4;
	// bl 0x822cc5e0
	ctx.lr = 0x822C0AC4;
	sub_822CC5E0(ctx, base);
loc_822C0AC4:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-8252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8252);
	// bl 0x82371368
	ctx.lr = 0x822C0AD0;
	sub_82371368(ctx, base);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r3,-8256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8256);
	// bl 0x8236f910
	ctx.lr = 0x822C0ADC;
	sub_8236F910(ctx, base);
	// lwz r3,-8256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8256);
	// bl 0x8236fce8
	ctx.lr = 0x822C0AE4;
	sub_8236FCE8(ctx, base);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r3,-17920(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17920);
	// bl 0x823061d0
	ctx.lr = 0x822C0AF0;
	sub_823061D0(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r30,r11,-6420
	r30.s64 = r11.s64 + -6420;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c0b0c
	if (!cr6.eq) goto loc_822C0B0C;
	// lwz r3,-8092(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// bl 0x822e6408
	ctx.lr = 0x822C0B0C;
	sub_822E6408(ctx, base);
loc_822C0B0C:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,1164(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1164);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c0b24
	if (!cr6.eq) goto loc_822C0B24;
	// lwz r3,-17920(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17920);
	// bl 0x82305a00
	ctx.lr = 0x822C0B24;
	sub_82305A00(ctx, base);
loc_822C0B24:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c0ba0
	if (!cr6.eq) goto loc_822C0BA0;
	// lwz r3,864(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 864);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0b40
	if (cr6.eq) goto loc_822C0B40;
	// bl 0x822cc8c8
	ctx.lr = 0x822C0B40;
	sub_822CC8C8(ctx, base);
loc_822C0B40:
	// lwz r3,-10236(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10236);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0b50
	if (cr6.eq) goto loc_822C0B50;
	// bl 0x821f7d68
	ctx.lr = 0x822C0B50;
	sub_821F7D68(ctx, base);
loc_822C0B50:
	// lwz r3,-18004(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -18004);
	// bl 0x82304610
	ctx.lr = 0x822C0B58;
	sub_82304610(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c0b6c
	if (cr6.eq) goto loc_822C0B6C;
	// bl 0x82130000
	ctx.lr = 0x822C0B6C;
	sub_82130000(ctx, base);
loc_822C0B6C:
	// lwz r3,-18004(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -18004);
	// bl 0x82304620
	ctx.lr = 0x822C0B74;
	sub_82304620(ctx, base);
	// bl 0x8217fff8
	ctx.lr = 0x822C0B78;
	sub_8217FFF8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e80
	ctx.lr = 0x822C0B84;
	sub_82189E80(ctx, base);
	// lwz r11,22080(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 22080);
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8217c658
	ctx.lr = 0x822C0BA0;
	sub_8217C658(ctx, base);
loc_822C0BA0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822C0BAC"))) PPC_WEAK_FUNC(sub_822C0BAC);
PPC_FUNC_IMPL(__imp__sub_822C0BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C0BB0"))) PPC_WEAK_FUNC(sub_822C0BB0);
PPC_FUNC_IMPL(__imp__sub_822C0BB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x823d91c0
	ctx.lr = 0x822C0BB8;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r30,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, r30.u32);
	// mr r29,r30
	r29.u64 = r30.u64;
	// stw r31,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, r31.u32);
	// subf r27,r30,r31
	r27.s64 = r31.s64 - r30.s64;
	// li r28,64
	r28.s64 = 64;
loc_822C0BD8:
	// add r4,r27,r29
	ctx.r4.u64 = r27.u64 + r29.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822bf3b0
	ctx.lr = 0x822C0BE4;
	sub_822BF3B0(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,816
	r29.s64 = r29.s64 + 816;
	// bne 0x822c0bd8
	if (!cr0.eq) goto loc_822C0BD8;
	// lis r11,0
	r11.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,52224
	r11.u64 = r11.u64 | 52224;
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// ori r11,r9,52240
	r11.u64 = ctx.r9.u64 | 52240;
	// ori r10,r10,52256
	ctx.r10.u64 = ctx.r10.u64 | 52256;
	// mr r28,r11
	r28.u64 = r11.u64;
	// lwzx r5,r31,r8
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// mr r27,r11
	r27.u64 = r11.u64;
	// add r26,r31,r10
	r26.u64 = r31.u64 + ctx.r10.u64;
	// add r25,r30,r10
	r25.u64 = r30.u64 + ctx.r10.u64;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// stwx r5,r30,r7
	PPC_STORE_U32(r30.u32 + ctx.r7.u32, ctx.r5.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r29,r4,52272
	r29.u64 = ctx.r4.u64 | 52272;
	// ori r6,r9,52316
	ctx.r6.u64 = ctx.r9.u64 | 52316;
	// ori r9,r7,52284
	ctx.r9.u64 = ctx.r7.u64 | 52284;
	// lis r11,0
	r11.s64 = 0;
	// ori r3,r3,52276
	ctx.r3.u64 = ctx.r3.u64 | 52276;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r4,r11,52308
	ctx.r4.u64 = r11.u64 | 52308;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r5,r10,52312
	ctx.r5.u64 = ctx.r10.u64 | 52312;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r8,r8,52280
	ctx.r8.u64 = ctx.r8.u64 | 52280;
	// lis r23,0
	r23.s64 = 0;
	// ori r10,r10,52324
	ctx.r10.u64 = ctx.r10.u64 | 52324;
	// lis r24,0
	r24.s64 = 0;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lis r11,0
	r11.s64 = 0;
	// lis r21,0
	r21.s64 = 0;
	// ori r11,r11,52292
	r11.u64 = r11.u64 | 52292;
	// lvx128 v63,r31,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,0
	r28.s64 = 0;
	// stvx128 v63,r30,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r27,0(r26)
	r27.u64 = PPC_LOAD_U64(r26.u32 + 0);
	// std r27,0(r25)
	PPC_STORE_U64(r25.u32 + 0, r27.u64);
	// ori r10,r28,52288
	ctx.r10.u64 = r28.u64 | 52288;
	// ld r22,8(r26)
	r22.u64 = PPC_LOAD_U64(r26.u32 + 8);
	// lis r27,0
	r27.s64 = 0;
	// std r22,8(r25)
	PPC_STORE_U64(r25.u32 + 8, r22.u64);
	// ori r22,r7,52328
	r22.u64 = ctx.r7.u64 | 52328;
	// lwzx r7,r31,r29
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// lis r20,0
	r20.s64 = 0;
	// stwx r7,r30,r29
	PPC_STORE_U32(r30.u32 + r29.u32, ctx.r7.u32);
	// ori r29,r24,52296
	r29.u64 = r24.u64 | 52296;
	// lwzx r7,r31,r3
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	// lis r24,0
	r24.s64 = 0;
	// stwx r7,r30,r3
	PPC_STORE_U32(r30.u32 + ctx.r3.u32, ctx.r7.u32);
	// lfsx f0,r31,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r30,r4
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + ctx.r4.u32, temp.u32);
	// ori r7,r23,52320
	ctx.r7.u64 = r23.u64 | 52320;
	// lfsx f13,r31,r5
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r4,r31,r8
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// stwx r4,r30,r8
	PPC_STORE_U32(r30.u32 + ctx.r8.u32, ctx.r4.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stfsx f13,r30,r5
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + ctx.r5.u32, temp.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lfsx f12,r31,r6
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	ctx.f12.f64 = double(temp.f32);
	// lwzx r5,r31,r9
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// ori r4,r27,52324
	ctx.r4.u64 = r27.u64 | 52324;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// stwx r5,r30,r9
	PPC_STORE_U32(r30.u32 + ctx.r9.u32, ctx.r5.u32);
	// ori r27,r24,52300
	r27.u64 = r24.u64 | 52300;
	// stfsx f12,r30,r6
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + ctx.r6.u32, temp.u32);
	// ori r23,r8,52304
	r23.u64 = ctx.r8.u64 | 52304;
	// lfsx f11,r31,r7
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	ctx.f11.f64 = double(temp.f32);
	// lwzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// stfsx f11,r30,r7
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + ctx.r7.u32, temp.u32);
	// stw r22,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r22.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r28,r11
	r28.u64 = r11.u64;
	// ori r29,r21,52296
	r29.u64 = r21.u64 | 52296;
	// ori r3,r3,52300
	ctx.r3.u64 = ctx.r3.u64 | 52300;
	// ori r24,r20,52304
	r24.u64 = r20.u64 | 52304;
	// lis r8,0
	ctx.r8.s64 = 0;
	// stwx r9,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, ctx.r9.u32);
	// ori r10,r8,52368
	ctx.r10.u64 = ctx.r8.u64 | 52368;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lfsx f10,r31,r4
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	ctx.f10.f64 = double(temp.f32);
	// rotlwi r26,r11,0
	r26.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
	// lwz r10,388(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// ori r11,r6,52496
	r11.u64 = ctx.r6.u64 | 52496;
	// lwz r6,396(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lis r5,0
	ctx.r5.s64 = 0;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r20,r11
	r20.u64 = r11.u64;
	// ori r11,r5,52360
	r11.u64 = ctx.r5.u64 | 52360;
	// stfsx f10,r10,r7
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// rotlwi r25,r22,0
	r25.u64 = __builtin_rotateleft32(r22.u32, 0);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// li r11,48
	r11.s64 = 48;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// ori r11,r5,52432
	r11.u64 = ctx.r5.u64 | 52432;
	// ori r9,r9,52352
	ctx.r9.u64 = ctx.r9.u64 | 52352;
	// mr r18,r11
	r18.u64 = r11.u64;
	// mr r17,r11
	r17.u64 = r11.u64;
	// rotlwi r11,r6,0
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// lwzx r4,r31,r28
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// add r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 + r30.u64;
	// mr r15,r9
	r15.u64 = ctx.r9.u64;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// mr r16,r9
	r16.u64 = ctx.r9.u64;
	// stw r15,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r15.u32);
	// lis r19,0
	r19.s64 = 0;
	// stw r6,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// stwx r4,r10,r26
	PPC_STORE_U32(ctx.r10.u32 + r26.u32, ctx.r4.u32);
	// add r4,r10,r21
	ctx.r4.u64 = ctx.r10.u64 + r21.u64;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// lfsx f9,r11,r25
	temp.u32 = PPC_LOAD_U32(r11.u32 + r25.u32);
	ctx.f9.f64 = double(temp.f32);
	// li r6,48
	ctx.r6.s64 = 48;
	// ori r19,r19,52328
	r19.u64 = r19.u64 | 52328;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// lis r31,0
	r31.s64 = 0;
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// li r10,48
	ctx.r10.s64 = 48;
	// stw r4,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r4.u32);
	// add r8,r22,r8
	ctx.r8.u64 = r22.u64 + ctx.r8.u64;
	// stw r6,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r6.u32);
	// lis r28,0
	r28.s64 = 0;
	// stw r10,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stw r8,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r8.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r14,0
	r14.s64 = 0;
	// lis r15,0
	r15.s64 = 0;
	// ori r4,r7,52332
	ctx.r4.u64 = ctx.r7.u64 | 52332;
	// ori r6,r31,52340
	ctx.r6.u64 = r31.u64 | 52340;
	// ori r7,r28,52344
	ctx.r7.u64 = r28.u64 | 52344;
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// ori r31,r9,52356
	r31.u64 = ctx.r9.u64 | 52356;
	// rotlwi r10,r22,0
	ctx.r10.u64 = __builtin_rotateleft32(r22.u32, 0);
	// lwz r22,88(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwzx r30,r11,r29
	r30.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// ori r5,r5,52336
	ctx.r5.u64 = ctx.r5.u64 | 52336;
	// lwz r11,388(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// ori r8,r14,52348
	ctx.r8.u64 = r14.u64 | 52348;
	// ori r29,r15,52356
	r29.u64 = r15.u64 | 52356;
	// add r9,r11,r20
	ctx.r9.u64 = r11.u64 + r20.u64;
	// li r26,32
	r26.s64 = 32;
	// li r25,32
	r25.s64 = 32;
	// stfsx f9,r11,r19
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + r19.u32, temp.u32);
	// lwz r20,396(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// add r21,r11,r17
	r21.u64 = r11.u64 + r17.u64;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// lfsx f8,r10,r4
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	ctx.f8.f64 = double(temp.f32);
	// lwz r25,112(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stfsx f8,r11,r4
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, temp.u32);
	// lwz r15,96(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lis r17,0
	r17.s64 = 0;
	// stw r21,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r21.u32);
	// add r19,r10,r18
	r19.u64 = ctx.r10.u64 + r18.u64;
	// lwz r21,104(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lis r14,0
	r14.s64 = 0;
	// stwx r30,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r30.u32);
	// mr r28,r11
	r28.u64 = r11.u64;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// lis r30,0
	r30.s64 = 0;
	// lwz r25,116(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stw r15,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r15.u32);
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// lwz r15,124(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r28.u32);
	// lwz r28,128(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// ori r9,r14,52752
	ctx.r9.u64 = r14.u64 | 52752;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r21,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r21.u32);
	// lwz r21,120(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// stw r28,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r28.u32);
	// li r28,32
	r28.s64 = 32;
	// stw r19,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r19.u32);
	// li r19,32
	r19.s64 = 32;
	// stw r4,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r28,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r28.u32);
	// rotlwi r28,r16,0
	r28.u64 = __builtin_rotateleft32(r16.u32, 0);
	// stw r4,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r4.u32);
	// lwz r18,84(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// li r25,48
	r25.s64 = 48;
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r21.u32);
	// li r21,48
	r21.s64 = 48;
	// stw r15,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r15.u32);
	// li r15,16
	r15.s64 = 16;
	// stw r19,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r19.u32);
	// li r19,48
	r19.s64 = 48;
	// stw r26,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r26.u32);
	// li r26,48
	r26.s64 = 48;
	// stw r25,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r25.u32);
	// stw r21,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r21.u32);
	// stw r15,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r15.u32);
	// stw r19,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r19.u32);
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r26,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, r26.u32);
	// stw r4,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r4.u32);
	// lwzx r4,r10,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// stwx r4,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r4.u32);
	// lwzx r3,r10,r24
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r24.u32);
	// stwx r3,r11,r23
	PPC_STORE_U32(r11.u32 + r23.u32, ctx.r3.u32);
	// lwzx r4,r10,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// stwx r4,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.r4.u32);
	// lwzx r3,r10,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// stwx r3,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, ctx.r3.u32);
	// lwzx r6,r10,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stwx r6,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r6.u32);
	// ori r7,r17,52560
	ctx.r7.u64 = r17.u64 | 52560;
	// lwzx r5,r10,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stwx r5,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r5.u32);
	// ori r8,r30,52624
	ctx.r8.u64 = r30.u64 | 52624;
	// lwzx r3,r10,r16
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r16.u32);
	// add r30,r11,r7
	r30.u64 = r11.u64 + ctx.r7.u64;
	// stwx r3,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, ctx.r3.u32);
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// add r31,r11,r8
	r31.u64 = r11.u64 + ctx.r8.u64;
	// stwx r10,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r10.u32);
	// rotlwi r29,r11,0
	r29.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwzx r8,r20,r22
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + r22.u32);
	// stwx r8,r29,r18
	PPC_STORE_U32(r29.u32 + r18.u32, ctx.r8.u32);
	// lwz r29,120(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// li r11,16
	r11.s64 = 16;
	// lwz r28,116(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// li r10,32
	ctx.r10.s64 = 32;
	// lwz r27,112(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lwz r7,156(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lis r22,0
	r22.s64 = 0;
	// lwz r26,164(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// ori r8,r6,53008
	ctx.r8.u64 = ctx.r6.u64 | 53008;
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r25,168(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r24,172(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lvx128 v61,r29,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,104(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r23,176(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lwz r6,396(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// li r16,32
	r16.s64 = 32;
	// lwz r21,388(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// li r15,48
	r15.s64 = 48;
	// add r20,r6,r9
	r20.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lwz r18,388(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// stvx128 v61,r28,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lvx128 v60,r29,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,92(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// add r21,r21,r9
	r21.u64 = r21.u64 + ctx.r9.u64;
	// stw r20,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r20.u32);
	// li r20,32
	r20.s64 = 32;
	// lwz r17,180(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stw r21,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r21.u32);
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// li r9,48
	ctx.r9.s64 = 48;
	// stw r11,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r11.u32);
	// stvx128 v60,r28,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,88(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lvx128 v59,r29,r27
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r27,148(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// li r21,16
	r21.s64 = 16;
	// stw r20,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r20.u32);
	// add r20,r19,r8
	r20.u64 = r19.u64 + ctx.r8.u64;
	// ori r6,r22,52880
	ctx.r6.u64 = r22.u64 | 52880;
	// stw r11,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r11.u32);
	// lis r22,0
	r22.s64 = 0;
	// stw r15,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r15.u32);
	// stvx128 v59,r28,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r28,144(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r8,r18,r8
	ctx.r8.u64 = r18.u64 + ctx.r8.u64;
	// stw r16,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r16.u32);
	// li r19,16
	r19.s64 = 16;
	// stw r20,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r20.u32);
	// ori r5,r5,52816
	ctx.r5.u64 = ctx.r5.u64 | 52816;
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// stw r19,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r19.u32);
	// stvx128 v58,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r29,r27
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,152(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r21,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r21.u32);
	// li r21,48
	r21.s64 = 48;
	// stw r21,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r21.u32);
	// stvx128 v57,r28,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,160(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// lvx128 v56,r29,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r11.u32);
	// stvx128 v56,r28,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r7,r22,52944
	ctx.r7.u64 = r22.u64 | 52944;
	// lvx128 v55,r29,r26
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r28,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r24
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r24,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r23,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r24,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r23,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r24,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r23,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r4
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r26,188(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// stvx128 v50,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r15,212(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// lvx128 v49,r4,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r25,192(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// stvx128 v49,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r22,196(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// lvx128 v48,r4,r10
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r20,204(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// stvx128 v48,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r10,r18,0
	ctx.r10.u64 = __builtin_rotateleft32(r18.u32, 0);
	// lvx128 v47,r4,r9
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r27,r10,r6
	r27.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stvx128 v47,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,396(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lvx128 v46,r0,r3
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r28,r9,r6
	r28.u64 = ctx.r9.u64 + ctx.r6.u64;
	// stvx128 v46,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,184(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lvx128 v45,r3,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// stvx128 v45,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 65536;
	// lvx128 v44,r3,r17
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,-12848
	ctx.r8.s64 = ctx.r8.s64 + -12848;
	// stvx128 v44,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r30,r9,r5
	r30.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r29,r10,r5
	r29.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r8,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r8.u32);
	// addi r4,r4,-12848
	ctx.r4.s64 = ctx.r4.s64 + -12848;
	// lvx128 v43,r3,r26
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r24,r8,0
	r24.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stvx128 v43,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,0
	ctx.r5.s64 = 0;
	// stw r4,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r4.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r27,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r27.u32);
	// rotlwi r23,r4,0
	r23.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// stw r29,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r29.u32);
	// ori r4,r5,53072
	ctx.r4.u64 = ctx.r5.u64 | 53072;
	// lwz r21,200(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// ori r5,r8,53136
	ctx.r5.u64 = ctx.r8.u64 | 53136;
	// lwz r17,208(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r8,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r8.u32);
	// li r18,16
	r18.s64 = 16;
	// lwz r8,396(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lwz r14,172(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// stw r18,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r18.u32);
	// li r18,48
	r18.s64 = 48;
	// lis r16,0
	r16.s64 = 0;
	// stw r28,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r28.u32);
	// stw r18,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r18.u32);
	// add r18,r8,r4
	r18.u64 = ctx.r8.u64 + ctx.r4.u64;
	// ori r6,r6,53200
	ctx.r6.u64 = ctx.r6.u64 | 53200;
	// stw r16,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r16.u32);
	// stw r18,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r18.u32);
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r30.u32);
	// li r27,32
	r27.s64 = 32;
	// lwz r19,128(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r29,32
	r29.s64 = 32;
	// lwz r16,168(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// lwz r28,164(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// lvx128 v42,r0,r24
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,160(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// li r11,32
	r11.s64 = 32;
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// add r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 + ctx.r7.u64;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// stvx128 v42,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r18,212(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r27.u32);
	// stw r29,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r29.u32);
	// stw r10,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// stw r18,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r18.u32);
	// add r18,r8,r5
	r18.u64 = ctx.r8.u64 + ctx.r5.u64;
	// lvx128 v41,r24,r22
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,208(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// stvx128 v41,r23,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,204(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r27,156(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// li r8,16
	ctx.r8.s64 = 16;
	// lwz r26,152(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r25,148(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r22,124(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r21,120(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lvx128 v40,r24,r20
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r20,116(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stvx128 v40,r23,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r19,112(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lvx128 v39,r24,r17
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r17,188(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// stvx128 v39,r23,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r15,388(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// lvx128 v38,r0,r14
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r23,136(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// stvx128 v38,r0,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r24,144(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lvx128 v37,r14,r28
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r16,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r16.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r14,r11
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r16,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r16.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r14,r10
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r16,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r16.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r16,0
	r16.s64 = 0;
	// lvx128 v34,r0,r3
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r3,r9
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r3,r11
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,200(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,196(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,0
	ctx.r9.s64 = 0;
	// lvx128 v60,r3,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,388(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// add r28,r11,r5
	r28.u64 = r11.u64 + ctx.r5.u64;
	// lis r5,0
	ctx.r5.s64 = 0;
	// add r30,r11,r7
	r30.u64 = r11.u64 + ctx.r7.u64;
	// stw r28,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r28.u32);
	// add r29,r11,r4
	r29.u64 = r11.u64 + ctx.r4.u64;
	// lwz r28,184(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// li r11,16
	r11.s64 = 16;
	// ori r4,r9,53456
	ctx.r4.u64 = ctx.r9.u64 | 53456;
	// lwz r9,396(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// stw r11,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r11.u32);
	// stw r28,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r28.u32);
	// lvx128 v59,r3,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,192(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// stvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r31,r5,53328
	r31.u64 = ctx.r5.u64 | 53328;
	// ori r7,r3,53264
	ctx.r7.u64 = ctx.r3.u64 | 53264;
	// stw r11,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r11.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,32
	r11.s64 = 32;
	// stvx128 v58,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r14,r9,r7
	r14.u64 = ctx.r9.u64 + ctx.r7.u64;
	// stw r11,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r11.u32);
	// ori r5,r5,53520
	ctx.r5.u64 = ctx.r5.u64 | 53520;
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// lis r3,0
	ctx.r3.s64 = 0;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// add r15,r15,r7
	r15.u64 = r15.u64 + ctx.r7.u64;
	// lwz r7,388(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// li r10,32
	ctx.r10.s64 = 32;
	// ori r3,r3,53392
	ctx.r3.u64 = ctx.r3.u64 | 53392;
	// li r11,48
	r11.s64 = 48;
	// add r5,r9,r4
	ctx.r5.u64 = ctx.r9.u64 + ctx.r4.u64;
	// stw r6,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r6.u32);
	// add r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 + ctx.r4.u64;
	// stw r15,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r15.u32);
	// stw r14,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r14.u32);
	// ld r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// stw r5,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r5.u32);
	// ld r5,136(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// add r28,r9,r6
	r28.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r14,r7,r6
	r14.u64 = ctx.r7.u64 + ctx.r6.u64;
	// stw r11,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r11.u32);
	// ori r6,r16,53584
	ctx.r6.u64 = r16.u64 | 53584;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// add r16,r7,r3
	r16.u64 = ctx.r7.u64 + ctx.r3.u64;
	// lwz r15,212(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// stw r4,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r4.u32);
	// rotlwi r4,r4,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// lvx128 v57,r15,r27
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r27,r9,r31
	r27.u64 = ctx.r9.u64 + r31.u64;
	// stvx128 v57,r30,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r26,r9,r3
	r26.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r31,r7,r31
	r31.u64 = ctx.r7.u64 + r31.u64;
	// lwz r3,176(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// lvx128 v56,r15,r25
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r25,r9,r5
	r25.u64 = ctx.r9.u64 + ctx.r5.u64;
	// stvx128 v56,r30,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 + ctx.r5.u64;
	// lvx128 v55,r15,r23
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r23,r9,r6
	r23.u64 = ctx.r9.u64 + ctx.r6.u64;
	// stvx128 v55,r30,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,180(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lvx128 v54,r0,r21
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r24,164(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// stvx128 v54,r0,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r23,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r23.u32);
	// lvx128 v53,r21,r19
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r19,200(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// stvx128 v53,r20,r17
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32 + r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r26,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r26.u32);
	// lvx128 v52,r21,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r22,160(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// stvx128 v52,r20,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r15,188(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lvx128 v51,r21,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r21,204(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// stvx128 v51,r20,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r20,0
	r20.s64 = 0;
	// lvx128 v50,r0,r30
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r7,r20,53648
	ctx.r7.u64 = r20.u64 | 53648;
	// stvx128 v50,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r20,192(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lvx128 v49,r30,r8
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r23,156(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// stvx128 v49,r29,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r26,152(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lvx128 v48,r30,r10
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// stvx128 v48,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r17,0
	r17.s64 = 0;
	// lvx128 v47,r30,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,208(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// stvx128 v47,r29,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,168(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// lvx128 v46,r0,r18
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r11.u32);
	// stvx128 v46,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r11.u32);
	// lvx128 v45,r18,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r18,r10
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r18,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r18,196(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// stvx128 v43,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,172(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lvx128 v42,r0,r28
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r16,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r16.u32);
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// stvx128 v42,r0,r14
	simde_mm_store_si128((simde__m128i*)(base + ((r14.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r16,r7
	r16.u64 = ctx.r7.u64;
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v41,r28,r3
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r6.u32);
	// stvx128 v41,r14,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r14.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r5.u32);
	// lvx128 v40,r28,r29
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,208(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// stvx128 v40,r14,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r14.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,388(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// lvx128 v39,r28,r22
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r28,r16,0
	r28.u64 = __builtin_rotateleft32(r16.u32, 0);
	// stvx128 v39,r14,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r14.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r3,r6,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// lvx128 v38,r0,r19
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r5,r6,r5
	ctx.r5.u64 = ctx.r6.u64 + ctx.r5.u64;
	// stvx128 v38,r0,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r6,r28
	ctx.r6.u64 = ctx.r6.u64 + r28.u64;
	// lvx128 v37,r19,r20
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,196(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// stvx128 v37,r18,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r18.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r4.u32);
	// lvx128 v36,r19,r23
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stvx128 v36,r18,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r18.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r8.u32);
	// lvx128 v35,r19,r11
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r4.u32);
	// stvx128 v35,r18,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r18.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lvx128 v34,r0,r27
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r4.u32);
	// stvx128 v34,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,144(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lvx128 v33,r27,r10
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,212(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// stvx128 v33,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r4.u32);
	// lvx128 v32,r27,r9
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r8.u32);
	// stvx128 v32,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r7.u32);
	// lwz r7,396(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// ori r8,r17,53712
	ctx.r8.u64 = r17.u64 | 53712;
	// rotlwi r26,r11,0
	r26.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r25,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r25.u32);
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r3,r3,r8
	ctx.r3.u64 = ctx.r3.u64 + ctx.r8.u64;
	// lwz r8,184(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// add r29,r7,r16
	r29.u64 = ctx.r7.u64 + r16.u64;
	// lwz r7,176(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lvx128 v63,r27,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,192(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,200(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r28,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r28,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r31,r27
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,188(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// stvx128 v59,r28,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,212(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// lvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,180(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stvx128 v58,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r27,r11,0
	r27.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lvx128 v57,r31,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,172(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// stvx128 v57,r28,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r8,r25,0
	ctx.r8.u64 = __builtin_rotateleft32(r25.u32, 0);
	// lvx128 v56,r31,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,156(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// stvx128 v56,r28,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r31,r27
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r28,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r8,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r8,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,136(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lvx128 v51,r8,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r31
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r31,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r5,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r31,r9
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r5,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r31,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r5,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r29
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r29,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r6,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r29,r9
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r6,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r29,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r6,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822bff40
	ctx.lr = 0x822C1664;
	sub_822BFF40(ctx, base);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lwz r31,396(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lwz r30,388(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// ori r11,r6,54704
	r11.u64 = ctx.r6.u64 | 54704;
	// add r4,r31,r11
	ctx.r4.u64 = r31.u64 + r11.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822bff40
	ctx.lr = 0x822C1680;
	sub_822BFF40(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r11,r5,55696
	r11.u64 = ctx.r5.u64 | 55696;
	// add r4,r31,r11
	ctx.r4.u64 = r31.u64 + r11.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822bff40
	ctx.lr = 0x822C1694;
	sub_822BFF40(ctx, base);
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r11,r4,56688
	r11.u64 = ctx.r4.u64 | 56688;
	// add r4,r31,r11
	ctx.r4.u64 = r31.u64 + r11.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822bff40
	ctx.lr = 0x822C16A8;
	sub_822BFF40(ctx, base);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r3,57680
	r11.u64 = ctx.r3.u64 | 57680;
	// ori r10,r10,57684
	ctx.r10.u64 = ctx.r10.u64 | 57684;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// mr r22,r10
	r22.u64 = ctx.r10.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r26,0
	r26.s64 = 0;
	// lis r25,0
	r25.s64 = 0;
	// ori r3,r4,57692
	ctx.r3.u64 = ctx.r4.u64 | 57692;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r29,r5,57688
	r29.u64 = ctx.r5.u64 | 57688;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r4,r26,57696
	ctx.r4.u64 = r26.u64 | 57696;
	// stw r29,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r29.u32);
	// ori r5,r25,57712
	ctx.r5.u64 = r25.u64 | 57712;
	// ori r28,r6,57687
	r28.u64 = ctx.r6.u64 | 57687;
	// ori r27,r7,57686
	r27.u64 = ctx.r7.u64 | 57686;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// ori r11,r9,57685
	r11.u64 = ctx.r9.u64 | 57685;
	// lis r9,0
	ctx.r9.s64 = 0;
	// stw r27,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, r27.u32);
	// mr r26,r11
	r26.u64 = r11.u64;
	// stw r27,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r27.u32);
	// mr r25,r11
	r25.u64 = r11.u64;
	// stw r28,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r28.u32);
	// ori r11,r9,57748
	r11.u64 = ctx.r9.u64 | 57748;
	// stw r28,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r28.u32);
	// lis r24,0
	r24.s64 = 0;
	// stwx r10,r30,r8
	PPC_STORE_U32(r30.u32 + ctx.r8.u32, ctx.r10.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r6,r24,57728
	ctx.r6.u64 = r24.u64 | 57728;
	// mr r20,r11
	r20.u64 = r11.u64;
	// mr r18,r11
	r18.u64 = r11.u64;
	// rotlwi r27,r30,0
	r27.u64 = __builtin_rotateleft32(r30.u32, 0);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// rotlwi r21,r31,0
	r21.u64 = __builtin_rotateleft32(r31.u32, 0);
	// rotlwi r19,r30,0
	r19.u64 = __builtin_rotateleft32(r30.u32, 0);
	// ori r11,r8,57756
	r11.u64 = ctx.r8.u64 | 57756;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lbzx r23,r31,r23
	r23.u64 = PPC_LOAD_U8(r31.u32 + r23.u32);
	// mr r17,r11
	r17.u64 = r11.u64;
	// stbx r23,r30,r22
	PPC_STORE_U8(r30.u32 + r22.u32, r23.u8);
	// mr r15,r11
	r15.u64 = r11.u64;
	// rotlwi r11,r31,0
	r11.u64 = __builtin_rotateleft32(r31.u32, 0);
	// stw r17,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r17.u32);
	// rotlwi r16,r31,0
	r16.u64 = __builtin_rotateleft32(r31.u32, 0);
	// stw r15,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r15.u32);
	// lis r15,0
	r15.s64 = 0;
	// lwz r17,212(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// rotlwi r3,r30,0
	ctx.r3.u64 = __builtin_rotateleft32(r30.u32, 0);
	// lwz r23,200(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// ori r15,r15,57752
	r15.u64 = r15.u64 | 57752;
	// stw r20,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, r20.u32);
	// rotlwi r22,r29,0
	r22.u64 = __builtin_rotateleft32(r29.u32, 0);
	// stw r15,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r15.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lwz r15,208(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r7,r7,57732
	ctx.r7.u64 = ctx.r7.u64 | 57732;
	// stw r18,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r18.u32);
	// ori r8,r10,57736
	ctx.r8.u64 = ctx.r10.u64 | 57736;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r9,57740
	ctx.r9.u64 = ctx.r9.u64 | 57740;
	// ori r10,r10,57744
	ctx.r10.u64 = ctx.r10.u64 | 57744;
	// lis r14,0
	r14.s64 = 0;
	// lis r18,0
	r18.s64 = 0;
	// ori r14,r14,57752
	r14.u64 = r14.u64 | 57752;
	// lis r20,0
	r20.s64 = 0;
	// stw r14,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r14.u32);
	// lis r14,0
	r14.s64 = 0;
	// lbzx r31,r31,r26
	r31.u64 = PPC_LOAD_U8(r31.u32 + r26.u32);
	// lis r30,0
	r30.s64 = 0;
	// lis r26,0
	r26.s64 = 0;
	// stbx r31,r27,r25
	PPC_STORE_U8(r27.u32 + r25.u32, r31.u8);
	// ori r31,r18,57760
	r31.u64 = r18.u64 | 57760;
	// ori r25,r20,57760
	r25.u64 = r20.u64 | 57760;
	// lbzx r27,r21,r17
	r27.u64 = PPC_LOAD_U8(r21.u32 + r17.u32);
	// stbx r27,r19,r15
	PPC_STORE_U8(r19.u32 + r15.u32, r27.u8);
	// lwz r27,204(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lbzx r27,r16,r27
	r27.u64 = PPC_LOAD_U8(r16.u32 + r27.u32);
	// stbx r27,r3,r23
	PPC_STORE_U8(ctx.r3.u32 + r23.u32, r27.u8);
	// lwzx r27,r11,r22
	r27.u64 = PPC_LOAD_U32(r11.u32 + r22.u32);
	// stwx r27,r3,r29
	PPC_STORE_U32(ctx.r3.u32 + r29.u32, r27.u32);
	// lwzx r29,r11,r24
	r29.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// stwx r29,r3,r28
	PPC_STORE_U32(ctx.r3.u32 + r28.u32, r29.u32);
	// lvx128 v42,r11,r4
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r28,192(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lwz r27,212(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// lvx128 v41,r11,r5
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r5,r11,r6
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	// stwx r5,r3,r6
	PPC_STORE_U32(ctx.r3.u32 + ctx.r6.u32, ctx.r5.u32);
	// lwzx r4,r11,r7
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// stwx r4,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.r4.u32);
	// ori r7,r30,57768
	ctx.r7.u64 = r30.u64 | 57768;
	// lwzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// stwx r6,r3,r8
	PPC_STORE_U32(ctx.r3.u32 + ctx.r8.u32, ctx.r6.u32);
	// ori r8,r26,57772
	ctx.r8.u64 = r26.u64 | 57772;
	// lwzx r5,r11,r9
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stwx r5,r3,r9
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r5.u32);
	// lfsx f7,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// stfsx f7,r3,r10
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r10.u32, temp.u32);
	// ori r10,r14,57764
	ctx.r10.u64 = r14.u64 | 57764;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// lfsx f6,r11,r27
	temp.u32 = PPC_LOAD_U32(r11.u32 + r27.u32);
	ctx.f6.f64 = double(temp.f32);
	// lwz r27,208(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// stfsx f6,r3,r27
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + r27.u32, temp.u32);
	// lfsx f5,r11,r28
	temp.u32 = PPC_LOAD_U32(r11.u32 + r28.u32);
	ctx.f5.f64 = double(temp.f32);
	// lwz r28,188(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// stfsx f5,r3,r28
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + r28.u32, temp.u32);
	// lwz r28,184(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lfsx f4,r11,r28
	temp.u32 = PPC_LOAD_U32(r11.u32 + r28.u32);
	ctx.f4.f64 = double(temp.f32);
	// lwz r28,180(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stfsx f4,r3,r28
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + r28.u32, temp.u32);
	// lfsx f3,r11,r31
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	ctx.f3.f64 = double(temp.f32);
	// stfsx f3,r3,r25
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + r25.u32, temp.u32);
	// lfsx f2,r11,r4
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	ctx.f2.f64 = double(temp.f32);
	// ori r9,r9,57776
	ctx.r9.u64 = ctx.r9.u64 | 57776;
	// stfsx f2,r3,r10
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r10.u32, temp.u32);
	// ori r10,r6,57780
	ctx.r10.u64 = ctx.r6.u64 | 57780;
	// lfsx f1,r11,r7
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	ctx.f1.f64 = double(temp.f32);
	// stfsx f1,r3,r7
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, temp.u32);
	// lfsx f0,r11,r8
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r3,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r8.u32, temp.u32);
	// lfsx f13,r11,r9
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfsx f13,r3,r9
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, temp.u32);
	// lfsx f12,r11,r10
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// stfsx f12,r3,r10
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r10.u32, temp.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_822C18D0"))) PPC_WEAK_FUNC(sub_822C18D0);
PPC_FUNC_IMPL(__imp__sub_822C18D0) {
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
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lwz r31,18264(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18264);
	// stw r11,18264(r10)
	PPC_STORE_U32(ctx.r10.u32 + 18264, r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c1908
	if (cr6.eq) goto loc_822C1908;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bf8c0
	ctx.lr = 0x822C1900;
	sub_822BF8C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822C1908;
	sub_82130588(ctx, base);
loc_822C1908:
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

__attribute__((alias("__imp__sub_822C191C"))) PPC_WEAK_FUNC(sub_822C191C);
PPC_FUNC_IMPL(__imp__sub_822C191C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C1920"))) PPC_WEAK_FUNC(sub_822C1920);
PPC_FUNC_IMPL(__imp__sub_822C1920) {
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
	ctx.lr = 0x822C1928;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x822C1934;
	sub_82130000(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-10020(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10020);
	// bl 0x826c0d50
	ctx.lr = 0x822C1940;
	sub_826C0D50(ctx, base);
	// lwz r3,-10020(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c1960
	if (cr6.eq) goto loc_822C1960;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C1960:
	// li r28,0
	r28.s64 = 0;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,-10020(r30)
	PPC_STORE_U32(r30.u32 + -10020, r11.u32);
	// lwz r3,18508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18508);
	// bl 0x826ba860
	ctx.lr = 0x822C1978;
	sub_826BA860(ctx, base);
	// lwz r3,18508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18508);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c1998
	if (cr6.eq) goto loc_822C1998;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C1998:
	// mr r11,r28
	r11.u64 = r28.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// stw r11,18508(r31)
	PPC_STORE_U32(r31.u32 + 18508, r11.u32);
	// lwz r3,18504(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 18504);
	// bl 0x82130000
	ctx.lr = 0x822C19AC;
	sub_82130000(ctx, base);
	// lwz r31,18504(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 18504);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c19c8
	if (cr6.eq) goto loc_822C19C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826b5a88
	ctx.lr = 0x822C19C0;
	sub_826B5A88(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822C19C8;
	sub_82130588(ctx, base);
loc_822C19C8:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,18504(r30)
	PPC_STORE_U32(r30.u32 + 18504, r11.u32);
	// lwz r31,828(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 828);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c19ec
	if (cr6.eq) goto loc_822C19EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82502c08
	ctx.lr = 0x822C19E4;
	sub_82502C08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822C19EC;
	sub_82130588(ctx, base);
loc_822C19EC:
	// stw r28,828(r29)
	PPC_STORE_U32(r29.u32 + 828, r28.u32);
	// bl 0x822c4eb8
	ctx.lr = 0x822C19F4;
	sub_822C4EB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822c4ed8
	ctx.lr = 0x822C1A00;
	sub_822C4ED8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822c4ec8
	ctx.lr = 0x822C1A0C;
	sub_822C4EC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c4f20
	ctx.lr = 0x822C1A28;
	sub_822C4F20(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C1A2C;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822c4ed8
	ctx.lr = 0x822C1A38;
	sub_822C4ED8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822c4ec8
	ctx.lr = 0x822C1A44;
	sub_822C4EC8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822C1A54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c4f20
	ctx.lr = 0x822C1A60;
	sub_822C4F20(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C1A64;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822c4ed8
	ctx.lr = 0x822C1A70;
	sub_822C4ED8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x822C1A7C;
	sub_822C4EC8(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822C1A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c4f20
	ctx.lr = 0x822C1A98;
	sub_822C4F20(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C1A9C;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822c4ed8
	ctx.lr = 0x822C1AA8;
	sub_822C4ED8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c4ec8
	ctx.lr = 0x822C1AB4;
	sub_822C4EC8(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,16(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x822C1AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c4f20
	ctx.lr = 0x822C1AD0;
	sub_822C4F20(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f7cb8
	ctx.lr = 0x822C1ADC;
	sub_821F7CB8(ctx, base);
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c1afc
	if (cr6.eq) goto loc_822C1AFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1AFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C1AFC:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,-10236(r31)
	PPC_STORE_U32(r31.u32 + -10236, r11.u32);
	// bl 0x8260c488
	ctx.lr = 0x822C1B08;
	sub_8260C488(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r3,2832(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c1b2c
	if (cr6.eq) goto loc_822C1B2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1B2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C1B2C:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,2832(r31)
	PPC_STORE_U32(r31.u32 + 2832, r11.u32);
	// lwz r3,848(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c1b54
	if (cr6.eq) goto loc_822C1B54;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C1B54:
	// lwz r31,864(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 864);
	// stw r28,848(r29)
	PPC_STORE_U32(r29.u32 + 848, r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c1b74
	if (cr6.eq) goto loc_822C1B74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822cbe30
	ctx.lr = 0x822C1B6C;
	sub_822CBE30(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822C1B74;
	sub_82130588(ctx, base);
loc_822C1B74:
	// stw r28,864(r29)
	PPC_STORE_U32(r29.u32 + 864, r28.u32);
	// bl 0x822c4eb8
	ctx.lr = 0x822C1B7C;
	sub_822C4EB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822c4ed8
	ctx.lr = 0x822C1B88;
	sub_822C4ED8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822c4ec8
	ctx.lr = 0x822C1B94;
	sub_822C4EC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1BA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c4f20
	ctx.lr = 0x822C1BB0;
	sub_822C4F20(ctx, base);
	// bl 0x822c4e68
	ctx.lr = 0x822C1BB4;
	sub_822C4E68(ctx, base);
	// bl 0x822ccc70
	ctx.lr = 0x822C1BB8;
	sub_822CCC70(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r31,-10224(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c1bd8
	if (cr6.eq) goto loc_822C1BD8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268bee8
	ctx.lr = 0x822C1BD0;
	sub_8268BEE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822C1BD8;
	sub_82130588(ctx, base);
loc_822C1BD8:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,-10224(r30)
	PPC_STORE_U32(r30.u32 + -10224, r11.u32);
	// bl 0x82390ca8
	ctx.lr = 0x822C1BE4;
	sub_82390CA8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C1BEC"))) PPC_WEAK_FUNC(sub_822C1BEC);
PPC_FUNC_IMPL(__imp__sub_822C1BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C1BF0"))) PPC_WEAK_FUNC(sub_822C1BF0);
PPC_FUNC_IMPL(__imp__sub_822C1BF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f31{};
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
	ctx.lr = 0x822C1BF8;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r19,-32114
	r19.s64 = -2104623104;
	// lwz r11,-23636(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c1ce0
	if (cr6.eq) goto loc_822C1CE0;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r3,-23636(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -23636);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C1C28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C1C28:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c1c28
	if (cr6.eq) goto loc_822C1C28;
	// lwz r10,-23636(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + -23636);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// bl 0x825507b0
	ctx.lr = 0x822C1C48;
	sub_825507B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c1ce0
	if (cr6.eq) goto loc_822C1CE0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r31,-32252
	r31.s64 = -2113667072;
	// lfs f31,11364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	f31.f64 = double(temp.f32);
loc_822C1C60:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c1c60
	if (cr6.eq) goto loc_822C1C60;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f0,-29020(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + -29020);
	f0.f64 = double(temp.f32);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fcmpu cr6,f10,f31
	cr6.compare(ctx.f10.f64, f31.f64);
	// bge cr6,0x822c1ce0
	if (!cr6.lt) goto loc_822C1CE0;
	// lwz r3,-23636(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -23636);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1CAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c91b0
	ctx.lr = 0x822C1CB4;
	sub_821C91B0(ctx, base);
	// lwz r3,-23636(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -23636);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822C1CC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-23636(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -23636);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x825507b0
	ctx.lr = 0x822C1CD4;
	sub_825507B0(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822c1c60
	if (!cr6.eq) goto loc_822C1C60;
loc_822C1CE0:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r25,16
	r25.s64 = 16;
	// li r26,32
	r26.s64 = 32;
	// li r27,48
	r27.s64 = 48;
	// li r21,432
	r21.s64 = 432;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// li r22,416
	r22.s64 = 416;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c1ddc
	if (cr6.eq) goto loc_822C1DDC;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r29,0
	r29.s64 = 0;
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c1d24
	if (cr6.eq) goto loc_822C1D24;
	// bl 0x821f92f8
	ctx.lr = 0x822C1D1C;
	sub_821F92F8(ctx, base);
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_822C1D24:
	// lwz r31,264(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// addi r30,r11,264
	r30.s64 = r11.s64 + 264;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c1ddc
	if (cr6.eq) goto loc_822C1DDC;
loc_822C1D34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x822C1D3C;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c1da0
	if (cr6.eq) goto loc_822C1DA0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x822C1D4C;
	sub_822A5578(ctx, base);
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x822c1d94
	if (!cr6.eq) goto loc_822C1D94;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1D6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c1d94
	if (cr6.eq) goto loc_822C1D94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x822C1D80;
	sub_822A5578(ctx, base);
	// lwz r11,116(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x822C1D90;
	sub_8260B990(ctx, base);
	// b 0x822c1da0
	goto loc_822C1DA0;
loc_822C1D94:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7138
	ctx.lr = 0x822C1DA0;
	sub_822A7138(ctx, base);
loc_822C1DA0:
	// addi r11,r31,288
	r11.s64 = r31.s64 + 288;
	// addi r10,r31,352
	ctx.r10.s64 = r31.s64 + 352;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r25
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r31,r21
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,864(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822c1d34
	if (!cr6.eq) goto loc_822C1D34;
loc_822C1DDC:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r20,-32115
	r20.s64 = -2104688640;
	// lwz r11,-5148(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -5148);
	// lwz r9,-12640(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + -12640);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c1ec8
	if (cr6.eq) goto loc_822C1EC8;
	// lbz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c1e10
	if (cr6.eq) goto loc_822C1E10;
	// lbz r10,10(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822c1e14
	if (cr6.eq) goto loc_822C1E14;
loc_822C1E10:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822C1E14:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c1ec8
	if (!cr6.eq) goto loc_822C1EC8;
	// lwz r23,0(r13)
	r23.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r24,72
	r24.s64 = 72;
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
loc_822C1E30:
	// lbzx r9,r24,r23
	ctx.r9.u64 = PPC_LOAD_U8(r24.u32 + r23.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c1e44
	if (cr6.eq) goto loc_822C1E44;
	// lhz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// b 0x822c1e48
	goto loc_822C1E48;
loc_822C1E44:
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
loc_822C1E48:
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// bge cr6,0x822c1ec4
	if (!cr6.lt) goto loc_822C1EC4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c1e60
	if (cr6.eq) goto loc_822C1E60;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822c1e64
	goto loc_822C1E64;
loc_822C1E60:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822C1E64:
	// lwzx r31,r10,r30
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c1eb8
	if (cr6.eq) goto loc_822C1EB8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1E84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r31,288
	r11.s64 = r31.s64 + 288;
	// addi r10,r31,352
	ctx.r10.s64 = r31.s64 + 352;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r25
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r26
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r27
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r31,r21
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r31,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-5148(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -5148);
loc_822C1EB8:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// b 0x822c1e30
	goto loc_822C1E30;
loc_822C1EC4:
	// lwz r9,-12640(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + -12640);
loc_822C1EC8:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c1f74
	if (cr6.eq) goto loc_822C1F74;
	// lbz r11,4(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c1ef4
	if (cr6.eq) goto loc_822C1EF4;
	// lbz r11,10(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822c1ef8
	if (cr6.eq) goto loc_822C1EF8;
loc_822C1EF4:
	// li r11,0
	r11.s64 = 0;
loc_822C1EF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c1f74
	if (!cr6.eq) goto loc_822C1F74;
	// bl 0x82701080
	ctx.lr = 0x822C1F08;
	sub_82701080(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x822c1f74
	if (!cr6.gt) goto loc_822C1F74;
loc_822C1F18:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// bl 0x827010e8
	ctx.lr = 0x822C1F24;
	sub_827010E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1F38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r31,288
	r11.s64 = r31.s64 + 288;
	// addi r10,r31,352
	ctx.r10.s64 = r31.s64 + 352;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r11,r25
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r10,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r11,r26
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r11,r27
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r31,r21
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r31,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x822c1f18
	if (cr6.lt) goto loc_822C1F18;
loc_822C1F74:
	// lwz r11,-23636(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c1f98
	if (cr6.eq) goto loc_822C1F98;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r3,-23636(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -23636);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C1F98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C1F98:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822C1FA4"))) PPC_WEAK_FUNC(sub_822C1FA4);
PPC_FUNC_IMPL(__imp__sub_822C1FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C1FA8"))) PPC_WEAK_FUNC(sub_822C1FA8);
PPC_FUNC_IMPL(__imp__sub_822C1FA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x822C1FB0;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823db9d4
	ctx.lr = 0x822C1FB8;
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// bl 0x8260c4d0
	ctx.lr = 0x822C1FCC;
	sub_8260C4D0(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b990
	ctx.lr = 0x822C1FD8;
	sub_8260B990(ctx, base);
	// lis r17,-32115
	r17.s64 = -2104688640;
	// lwz r3,-12640(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C1FF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x822bfa58
	ctx.lr = 0x822C1FF8;
	sub_822BFA58(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lwz r3,-12440(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12440);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,72(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822C2010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-12640(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// li r18,0
	r18.s64 = 0;
	// lbz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwz r31,-12348(r6)
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12348);
	// beq cr6,0x822c203c
	if (cr6.eq) goto loc_822C203C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822c2040
	if (cr6.eq) goto loc_822C2040;
loc_822C203C:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C2040:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r15,-32121
	r15.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c22a4
	if (!cr6.eq) goto loc_822C22A4;
	// lwz r3,-5008(r15)
	ctx.r3.u64 = PPC_LOAD_U32(r15.u32 + -5008);
	// bl 0x822623e8
	ctx.lr = 0x822C2058;
	sub_822623E8(ctx, base);
	// lbz r11,76(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c20c4
	if (cr6.eq) goto loc_822C20C4;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + r31.u64;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// lbz r6,52(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 52);
	// add r5,r10,r31
	ctx.r5.u64 = ctx.r10.u64 + r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// add r4,r9,r31
	ctx.r4.u64 = ctx.r9.u64 + r31.u64;
	// lbz r3,52(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 52);
	// rlwimi r3,r6,8,16,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFF00) | (ctx.r3.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// lbz r10,52(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 52);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// rlwimi r10,r11,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// lbz r11,52(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 52);
	// rlwimi r11,r10,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// stw r11,7220(r30)
	PPC_STORE_U32(r30.u32 + 7220, r11.u32);
loc_822C20C4:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,7220(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7220);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,7444
	ctx.r10.s64 = r11.s64 + 7444;
	// lfs f13,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f29,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f29.f64 = double(temp.f32);
	// fsel f0,f12,f0,f13
	f0.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f0,7220(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 7220, temp.u32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x822c2110
	if (cr6.eq) goto loc_822C2110;
	// bl 0x82387a18
	ctx.lr = 0x822C20F4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c210c
	if (cr6.eq) goto loc_822C210C;
	// fmr f0,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = f29.f64;
	// stfs f0,7220(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 7220, temp.u32);
	// b 0x822c2110
	goto loc_822C2110;
loc_822C210C:
	// lfs f0,7220(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7220);
	f0.f64 = double(temp.f32);
loc_822C2110:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r27,r11,29952
	r27.s64 = r11.s64 + 29952;
	// addi r11,r10,14192
	r11.s64 = ctx.r10.s64 + 14192;
	// lfs f31,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f31.f64 = double(temp.f32);
	// stfs f0,84(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 84, temp.u32);
	// lbz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c2198
	if (cr6.eq) goto loc_822C2198;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lbz r7,52(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 52);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// add r6,r10,r31
	ctx.r6.u64 = ctx.r10.u64 + r31.u64;
	// lbz r5,52(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 52);
	// rlwimi r5,r7,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// clrlwi r3,r5,16
	ctx.r3.u64 = ctx.r5.u32 & 0xFFFF;
	// lbz r9,52(r6)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + 52);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwimi r9,r3,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// lbz r8,52(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 52);
	// rlwimi r8,r9,8,0,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f1,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// b 0x822c219c
	goto loc_822C219C;
loc_822C2198:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_822C219C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822C21B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c22e4
	if (cr6.eq) goto loc_822C22E4;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lfs f0,84(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 84);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,8,24,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// stb r9,52(r10)
	PPC_STORE_U8(ctx.r10.u32 + 52, ctx.r9.u8);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r8,r11,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r7,r11,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r8,52(r5)
	PPC_STORE_U8(ctx.r5.u32 + 52, ctx.r8.u8);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r7,52(r4)
	PPC_STORE_U8(ctx.r4.u32 + 52, ctx.r7.u8);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r6,52(r3)
	PPC_STORE_U8(ctx.r3.u32 + 52, ctx.r6.u8);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lfs f0,92(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 92);
	f0.f64 = double(temp.f32);
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r11,8,24,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// stb r9,52(r10)
	PPC_STORE_U8(ctx.r10.u32 + 52, ctx.r9.u8);
	// rlwinm r8,r11,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r7,r11,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r8,52(r5)
	PPC_STORE_U8(ctx.r5.u32 + 52, ctx.r8.u8);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r7,52(r4)
	PPC_STORE_U8(ctx.r4.u32 + 52, ctx.r7.u8);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r6,52(r3)
	PPC_STORE_U8(ctx.r3.u32 + 52, ctx.r6.u8);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// b 0x822c22e4
	goto loc_822C22E4;
loc_822C22A4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r27,r11,29952
	r27.s64 = r11.s64 + 29952;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r10,7444
	ctx.r10.s64 = ctx.r10.s64 + 7444;
	// addi r11,r11,14192
	r11.s64 = r11.s64 + 14192;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f29,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f29.f64 = double(temp.f32);
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// stfs f29,84(r27)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r27.u32 + 84, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822C22E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C22E4:
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x822c1bf0
	ctx.lr = 0x822C22EC;
	sub_822C1BF0(ctx, base);
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// fdivs f13,f29,f0
	ctx.f13.f64 = double(float(f29.f64 / f0.f64));
	// stfs f13,12(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 12, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// fmr f28,f0
	f28.f64 = f0.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd910
	ctx.lr = 0x822C230C;
	sub_821BD910(ctx, base);
	// lwz r3,-12640(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C2320;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r9,18444
	ctx.r7.s64 = ctx.r9.s64 + 18444;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lfs f27,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f27.f64 = double(temp.f32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c236c
	if (!cr6.eq) goto loc_822C236C;
	// bl 0x82387a18
	ctx.lr = 0x822C2344;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c236c
	if (!cr6.eq) goto loc_822C236C;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r11,r18
	r11.u64 = r18.u64;
	// addi r8,r9,18352
	ctx.r8.s64 = ctx.r9.s64 + 18352;
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
	// stw r11,18352(r9)
	PPC_STORE_U32(ctx.r9.u32 + 18352, r11.u32);
	// stw r10,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r10.u32);
	// b 0x822c2430
	goto loc_822C2430;
loc_822C236C:
	// extsw r11,r24
	r11.s64 = r24.s32;
	// lfs f13,92(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// lfs f11,-11620(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11620);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fcmpu cr6,f13,f9
	cr6.compare(ctx.f13.f64, ctx.f9.f64);
	// ble cr6,0x822c239c
	if (!cr6.gt) goto loc_822C239C;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
loc_822C239C:
	// extsw r11,r24
	r11.s64 = r24.s32;
	// lfs f0,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 88);
	f0.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f12,84(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r31,r11,18352
	r31.s64 = r11.s64 + 18352;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsel f9,f10,f13,f0
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// fsel f8,f10,f13,f0
	ctx.f8.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// lfd f7,88(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f5,f11
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// fsubs f3,f9,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 - ctx.f4.f64));
	// fsel f2,f3,f4,f8
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f8.f64;
	// fmuls f1,f2,f12
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
	// fdivs f0,f1,f5
	f0.f64 = double(float(ctx.f1.f64 / ctx.f5.f64));
	// fmuls f13,f0,f5
	ctx.f13.f64 = double(float(f0.f64 * ctx.f5.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x822bf2e8
	ctx.lr = 0x822C23F4;
	sub_822BF2E8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822c2420
	if (!cr6.gt) goto loc_822C2420;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f0,f0,f11
	f0.f64 = double(float(f0.f64 / ctx.f11.f64));
	// b 0x822c2424
	goto loc_822C2424;
loc_822C2420:
	// fmr f0,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = f27.f64;
loc_822C2424:
	// stfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// fdivs f0,f29,f0
	f0.f64 = double(float(f29.f64 / f0.f64));
	// stfs f0,12(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 12, temp.u32);
loc_822C2430:
	// lis r19,-32121
	r19.s64 = -2105081856;
	// mr r23,r24
	r23.u64 = r24.u64;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// blt cr6,0x822c266c
	if (cr6.lt) goto loc_822C266C;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lis r26,-32121
	r26.s64 = -2105081856;
loc_822C2448:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ble cr6,0x822c2460
	if (!cr6.gt) goto loc_822C2460;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x822c2468
	goto loc_822C2468;
loc_822C2460:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822C2468:
	// bl 0x821bd910
	ctx.lr = 0x822C246C;
	sub_821BD910(ctx, base);
	// lwz r11,-12640(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f30,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f30.f64 = double(temp.f32);
	// beq cr6,0x822c2490
	if (cr6.eq) goto loc_822C2490;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822c2494
	if (cr6.eq) goto loc_822C2494;
loc_822C2490:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C2494:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2a88
	if (!cr6.eq) goto loc_822C2A88;
	// bl 0x822c4eb8
	ctx.lr = 0x822C24A4;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c4ec8
	ctx.lr = 0x822C24AC;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c24c4
	if (cr6.eq) goto loc_822C24C4;
	// bl 0x822c4eb8
	ctx.lr = 0x822C24B8;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x822c52c8
	ctx.lr = 0x822C24C4;
	sub_822C52C8(ctx, base);
loc_822C24C4:
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2588
	if (cr6.eq) goto loc_822C2588;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// mr r31,r18
	r31.u64 = r18.u64;
	// li r30,8
	r30.s64 = 8;
loc_822C24E0:
	// lbzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c24f4
	if (cr6.eq) goto loc_822C24F4;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x822c24f8
	goto loc_822C24F8;
loc_822C24F4:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_822C24F8:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822c2588
	if (!cr6.lt) goto loc_822C2588;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c252c
	if (cr6.eq) goto loc_822C252C;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822c2550
	if (cr6.lt) goto loc_822C2550;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822c2550
	if (!cr6.lt) goto loc_822C2550;
	// add r11,r30,r3
	r11.u64 = r30.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x822c2548
	goto loc_822C2548;
loc_822C252C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822c2550
	if (cr6.lt) goto loc_822C2550;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822c2550
	if (!cr6.lt) goto loc_822C2550;
	// lwzx r11,r30,r3
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_822C2548:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822c2554
	if (!cr6.eq) goto loc_822C2554;
loc_822C2550:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C2554:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c257c
	if (cr6.eq) goto loc_822C257C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x822C2568;
	sub_822A3998(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C2578;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
loc_822C257C:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// b 0x822c24e0
	goto loc_822C24E0;
loc_822C2588:
	// lwz r11,-5148(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -5148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c261c
	if (cr6.eq) goto loc_822C261C;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// mr r30,r18
	r30.u64 = r18.u64;
	// mr r31,r18
	r31.u64 = r18.u64;
loc_822C25A4:
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c25b8
	if (cr6.eq) goto loc_822C25B8;
	// lhz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// b 0x822c25bc
	goto loc_822C25BC;
loc_822C25B8:
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
loc_822C25BC:
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x822c261c
	if (!cr6.lt) goto loc_822C261C;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c25d4
	if (cr6.eq) goto loc_822C25D4;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822c25d8
	goto loc_822C25D8;
loc_822C25D4:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822C25D8:
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2610
	if (cr6.eq) goto loc_822C2610;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c25f4
	if (cr6.eq) goto loc_822C25F4;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822c25f8
	goto loc_822C25F8;
loc_822C25F4:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822C25F8:
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C260C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-5148(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -5148);
loc_822C2610:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// b 0x822c25a4
	goto loc_822C25A4;
loc_822C261C:
	// lwz r3,-10016(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2664
	if (cr6.eq) goto loc_822C2664;
	// bl 0x82701080
	ctx.lr = 0x822C262C;
	sub_82701080(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r18
	r31.u64 = r18.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822c2664
	if (!cr6.gt) goto loc_822C2664;
loc_822C263C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10016);
	// bl 0x827010e8
	ctx.lr = 0x822C2648;
	sub_827010E8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C2658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x822c263c
	if (cr6.lt) goto loc_822C263C;
loc_822C2664:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// bge 0x822c2448
	if (!cr0.lt) goto loc_822C2448;
loc_822C266C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd910
	ctx.lr = 0x822C267C;
	sub_821BD910(ctx, base);
	// lis r22,-32121
	r22.s64 = -2105081856;
	// lis r11,6
	r11.s64 = 393216;
	// fdivs f0,f29,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 / f28.f64));
	// lis r10,6
	ctx.r10.s64 = 393216;
	// stfs f28,8(r27)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// ori r21,r11,16985
	r21.u64 = r11.u64 | 16985;
	// stfs f0,12(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 12, temp.u32);
	// ori r20,r10,16992
	r20.u64 = ctx.r10.u64 | 16992;
	// lwz r11,-10012(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c26bc
	if (cr6.eq) goto loc_822C26BC;
	// lbzx r10,r11,r21
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r21.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c26bc
	if (cr6.eq) goto loc_822C26BC;
	// add r3,r11,r20
	ctx.r3.u64 = r11.u64 + r20.u64;
	// bl 0x826d9578
	ctx.lr = 0x822C26BC;
	sub_826D9578(ctx, base);
loc_822C26BC:
	// bl 0x822e8ba8
	ctx.lr = 0x822C26C0;
	sub_822E8BA8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2700
	if (cr6.eq) goto loc_822C2700;
	// lwz r11,-12640(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c26f0
	if (cr6.eq) goto loc_822C26F0;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822c26f4
	if (cr6.eq) goto loc_822C26F4;
loc_822C26F0:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C26F4:
	// clrlwi r5,r11,24
	ctx.r5.u64 = r11.u32 & 0xFF;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x826bd890
	ctx.lr = 0x822C2700;
	sub_826BD890(ctx, base);
loc_822C2700:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18504(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18504);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2718
	if (cr6.eq) goto loc_822C2718;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x82130000
	ctx.lr = 0x822C2718;
	sub_82130000(ctx, base);
loc_822C2718:
	// bl 0x822c4eb8
	ctx.lr = 0x822C271C;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x822C2724;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c273c
	if (cr6.eq) goto loc_822C273C;
	// bl 0x822c4eb8
	ctx.lr = 0x822C2730;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x822c52c8
	ctx.lr = 0x822C273C;
	sub_822C52C8(ctx, base);
loc_822C273C:
	// lwz r3,-5008(r15)
	ctx.r3.u64 = PPC_LOAD_U32(r15.u32 + -5008);
	// bl 0x82130000
	ctx.lr = 0x822C2744;
	sub_82130000(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C2748;
	sub_822C4EB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822c4ec8
	ctx.lr = 0x822C2750;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2768
	if (cr6.eq) goto loc_822C2768;
	// bl 0x822c4eb8
	ctx.lr = 0x822C275C;
	sub_822C4EB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x822c52c8
	ctx.lr = 0x822C2768;
	sub_822C52C8(ctx, base);
loc_822C2768:
	// bl 0x822c4eb8
	ctx.lr = 0x822C276C;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822c4ec8
	ctx.lr = 0x822C2774;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c27c0
	if (cr6.eq) goto loc_822C27C0;
	// lwz r11,-12640(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c279c
	if (cr6.eq) goto loc_822C279C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822c27a0
	if (cr6.eq) goto loc_822C27A0;
loc_822C279C:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C27A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c27b0
	if (!cr6.eq) goto loc_822C27B0;
	// lfs f31,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 88);
	f31.f64 = double(temp.f32);
loc_822C27B0:
	// bl 0x822c4eb8
	ctx.lr = 0x822C27B4;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822c52c8
	ctx.lr = 0x822C27C0;
	sub_822C52C8(ctx, base);
loc_822C27C0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r30,r11,-6420
	r30.s64 = r11.s64 + -6420;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2804
	if (!cr6.eq) goto loc_822C2804;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lfs f1,88(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821fc588
	ctx.lr = 0x822C27E4;
	sub_821FC588(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2804
	if (!cr6.eq) goto loc_822C2804;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x822c0320
	ctx.lr = 0x822C27F8;
	sub_822C0320(ctx, base);
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f7d00
	ctx.lr = 0x822C2800;
	sub_821F7D00(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_822C2804:
	// lwz r10,-10012(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + -10012);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2848
	if (cr6.eq) goto loc_822C2848;
	// lbzx r10,r10,r21
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r21.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c2848
	if (!cr6.eq) goto loc_822C2848;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2848
	if (!cr6.eq) goto loc_822C2848;
	// bl 0x822c4eb8
	ctx.lr = 0x822C2828;
	sub_822C4EB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822c4ec8
	ctx.lr = 0x822C2830;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2848
	if (cr6.eq) goto loc_822C2848;
	// bl 0x822c4eb8
	ctx.lr = 0x822C283C;
	sub_822C4EB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x822c52c8
	ctx.lr = 0x822C2848;
	sub_822C52C8(ctx, base);
loc_822C2848:
	// lis r23,-32121
	r23.s64 = -2105081856;
	// lwz r3,-4960(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -4960);
	// bl 0x823c9370
	ctx.lr = 0x822C2854;
	sub_823C9370(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x822bf018
	ctx.lr = 0x822C285C;
	sub_822BF018(ctx, base);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x822C286C;
	sub_82305870(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2888
	if (cr6.eq) goto loc_822C2888;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-6148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// bl 0x822545c8
	ctx.lr = 0x822C2888;
	sub_822545C8(ctx, base);
loc_822C2888:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-29340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c28ac
	if (cr6.eq) goto loc_822C28AC;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c28ac
	if (cr6.eq) goto loc_822C28AC;
	// bl 0x826aaa40
	ctx.lr = 0x822C28AC;
	sub_826AAA40(ctx, base);
loc_822C28AC:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x822C28B8;
	sub_823058F8(ctx, base);
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lwz r11,-4964(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -4964);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c28dc
	if (cr6.eq) goto loc_822C28DC;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r3,108(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822c28dc
	if (cr6.eq) goto loc_822C28DC;
	// bl 0x82730c88
	ctx.lr = 0x822C28DC;
	sub_82730C88(ctx, base);
loc_822C28DC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lis r26,-32120
	r26.s64 = -2105016320;
	// lis r25,-32119
	r25.s64 = -2104950784;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2c60
	if (!cr6.eq) goto loc_822C2C60;
	// lwz r31,-17936(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + -17936);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r10,-8092(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -8092);
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r31,45
	ctx.r8.s64 = r31.s64 + 45;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// lwzx r28,r7,r10
	r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lvx128 v127,r11,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r28,64
	r30.s64 = r28.s64 + 64;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82172428
	ctx.lr = 0x822C2934;
	sub_82172428(ctx, base);
	// addi r27,r30,48
	r27.s64 = r30.s64 + 48;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// addi r7,r30,32
	ctx.r7.s64 = r30.s64 + 32;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82172188
	ctx.lr = 0x822C2954;
	sub_82172188(ctx, base);
	// lwz r11,-17628(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r4,r6,57792
	ctx.r4.u64 = ctx.r6.u64 | 57792;
	// ori r30,r5,52308
	r30.u64 = ctx.r5.u64 | 52308;
	// mullw r10,r31,r4
	ctx.r10.s64 = int64_t(r31.s32) * int64_t(ctx.r4.s32);
	// li r9,7
	ctx.r9.s64 = 7;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
loc_822C297C:
	// stfs f27,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r18,-28(r11)
	PPC_STORE_U32(r11.u32 + -28, r18.u32);
	// stw r18,28(r11)
	PPC_STORE_U32(r11.u32 + 28, r18.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x822c297c
	if (!cr0.eq) goto loc_822C297C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,-17624(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -17624);
	// bl 0x825f3720
	ctx.lr = 0x822C29B0;
	sub_825F3720(ctx, base);
	// lwz r11,-12640(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c29d0
	if (cr6.eq) goto loc_822C29D0;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822c29d4
	if (cr6.eq) goto loc_822C29D4;
loc_822C29D0:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C29D4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2c60
	if (!cr6.eq) goto loc_822C2C60;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822c2be0
	if (cr6.eq) goto loc_822C2BE0;
	// bl 0x822a39c0
	ctx.lr = 0x822C2A24;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c2be0
	if (cr6.eq) goto loc_822C2BE0;
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822C2A38;
	sub_822A39C8(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x822C2A3C;
	sub_822A8108(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r11,32
	r11.s64 = 32;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,-28428(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28428);
	f0.f64 = double(temp.f32);
	// addi r5,r7,-31616
	ctx.r5.s64 = ctx.r7.s64 + -31616;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v58,r3,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v57,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vmaddfp v11,v0,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822c2bec
	goto loc_822C2BEC;
loc_822C2A88:
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2b4c
	if (cr6.eq) goto loc_822C2B4C;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// mr r31,r18
	r31.u64 = r18.u64;
	// li r30,8
	r30.s64 = 8;
loc_822C2AA4:
	// lbzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2ab8
	if (cr6.eq) goto loc_822C2AB8;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x822c2abc
	goto loc_822C2ABC;
loc_822C2AB8:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_822C2ABC:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822c2b4c
	if (!cr6.lt) goto loc_822C2B4C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2af0
	if (cr6.eq) goto loc_822C2AF0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822c2b14
	if (cr6.lt) goto loc_822C2B14;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822c2b14
	if (!cr6.lt) goto loc_822C2B14;
	// add r11,r30,r3
	r11.u64 = r30.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x822c2b0c
	goto loc_822C2B0C;
loc_822C2AF0:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822c2b14
	if (cr6.lt) goto loc_822C2B14;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x822c2b14
	if (!cr6.lt) goto loc_822C2B14;
	// lwzx r11,r30,r3
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_822C2B0C:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822c2b18
	if (!cr6.eq) goto loc_822C2B18;
loc_822C2B14:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C2B18:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c2b40
	if (cr6.eq) goto loc_822C2B40;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x822C2B2C;
	sub_822A3998(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C2B3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
loc_822C2B40:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// b 0x822c2aa4
	goto loc_822C2AA4;
loc_822C2B4C:
	// lwz r11,-5148(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -5148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c2664
	if (cr6.eq) goto loc_822C2664;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// mr r30,r18
	r30.u64 = r18.u64;
	// mr r31,r18
	r31.u64 = r18.u64;
loc_822C2B68:
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c2b7c
	if (cr6.eq) goto loc_822C2B7C;
	// lhz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// b 0x822c2b80
	goto loc_822C2B80;
loc_822C2B7C:
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
loc_822C2B80:
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x822c2664
	if (!cr6.lt) goto loc_822C2664;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c2b98
	if (cr6.eq) goto loc_822C2B98;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822c2b9c
	goto loc_822C2B9C;
loc_822C2B98:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822C2B9C:
	// lwzx r10,r10,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2bd4
	if (cr6.eq) goto loc_822C2BD4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c2bb8
	if (cr6.eq) goto loc_822C2BB8;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822c2bbc
	goto loc_822C2BBC;
loc_822C2BB8:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822C2BBC:
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C2BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-5148(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -5148);
loc_822C2BD4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// b 0x822c2b68
	goto loc_822C2B68;
loc_822C2BE0:
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v56,r0,r27
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822C2BEC:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82172428
	ctx.lr = 0x822C2C04;
	sub_82172428(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82172188
	ctx.lr = 0x822C2C20;
	sub_82172188(ctx, base);
	// lwz r11,-17628(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// li r10,7
	ctx.r10.s64 = 7;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addis r9,r11,2
	ctx.r9.s64 = r11.s64 + 131072;
	// addi r9,r9,-15488
	ctx.r9.s64 = ctx.r9.s64 + -15488;
	// add r11,r9,r30
	r11.u64 = ctx.r9.u64 + r30.u64;
loc_822C2C38:
	// stfs f27,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r18,-28(r11)
	PPC_STORE_U32(r11.u32 + -28, r18.u32);
	// stw r18,28(r11)
	PPC_STORE_U32(r11.u32 + 28, r18.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x822c2c38
	if (!cr0.eq) goto loc_822C2C38;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x825f3178
	ctx.lr = 0x822C2C60;
	sub_825F3178(ctx, base);
loc_822C2C60:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r3,17268(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + 17268);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c2c8c
	if (cr6.eq) goto loc_822C2C8C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822c2ca8
	if (!cr6.gt) goto loc_822C2CA8;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x822c2c9c
	goto loc_822C2C9C;
loc_822C2C8C:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822c2ca8
	if (!cr6.gt) goto loc_822C2CA8;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_822C2C9C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822c2cac
	if (!cr6.eq) goto loc_822C2CAC;
loc_822C2CA8:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C2CAC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c2ccc
	if (cr6.eq) goto loc_822C2CCC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x822C2CC0;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x822C2CC4;
	sub_822A8108(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// b 0x822c2ce0
	goto loc_822C2CE0;
loc_822C2CCC:
	// lwz r11,-17936(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -17936);
	// lwz r10,-8092(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -8092);
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r11,240
	ctx.r4.s64 = r11.s64 + 240;
loc_822C2CE0:
	// lwz r3,-4964(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -4964);
	// bl 0x8272a130
	ctx.lr = 0x822C2CE8;
	sub_8272A130(ctx, base);
	// lwz r11,-10012(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c2d1c
	if (cr6.eq) goto loc_822C2D1C;
	// lbzx r10,r11,r21
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r21.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2d0c
	if (cr6.eq) goto loc_822C2D0C;
	// add r3,r11,r20
	ctx.r3.u64 = r11.u64 + r20.u64;
	// bl 0x826d95b0
	ctx.lr = 0x822C2D08;
	sub_826D95B0(ctx, base);
	// lwz r11,-10012(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10012);
loc_822C2D0C:
	// lis r10,6
	ctx.r10.s64 = 393216;
	// ori r9,r10,16986
	ctx.r9.u64 = ctx.r10.u64 | 16986;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// stbx r8,r11,r21
	PPC_STORE_U8(r11.u32 + r21.u32, ctx.r8.u8);
loc_822C2D1C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-18004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// bl 0x823045b0
	ctx.lr = 0x822C2D28;
	sub_823045B0(ctx, base);
	// lwz r11,-12640(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2d48
	if (cr6.eq) goto loc_822C2D48;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822c2d4c
	if (cr6.eq) goto loc_822C2D4C;
loc_822C2D48:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C2D4C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2d60
	if (!cr6.eq) goto loc_822C2D60;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// b 0x822c2d64
	goto loc_822C2D64;
loc_822C2D60:
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
loc_822C2D64:
	// bl 0x822ecb08
	ctx.lr = 0x822C2D68;
	sub_822ECB08(ctx, base);
	// lwz r3,-4960(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -4960);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2d80
	if (cr6.eq) goto loc_822C2D80;
	// bl 0x823c98a0
	ctx.lr = 0x822C2D78;
	sub_823C98A0(ctx, base);
	// lwz r3,-4960(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -4960);
	// bl 0x823c9360
	ctx.lr = 0x822C2D80;
	sub_823C9360(ctx, base);
loc_822C2D80:
	// lwz r11,-12640(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2da0
	if (cr6.eq) goto loc_822C2DA0;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822c2da4
	if (cr6.eq) goto loc_822C2DA4;
loc_822C2DA0:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_822C2DA4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2db8
	if (!cr6.eq) goto loc_822C2DB8;
	// lwz r3,-5008(r15)
	ctx.r3.u64 = PPC_LOAD_U32(r15.u32 + -5008);
	// bl 0x82260cf0
	ctx.lr = 0x822C2DB8;
	sub_82260CF0(ctx, base);
loc_822C2DB8:
	// lwz r3,864(r16)
	ctx.r3.u64 = PPC_LOAD_U32(r16.u32 + 864);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2dc8
	if (cr6.eq) goto loc_822C2DC8;
	// bl 0x822cc590
	ctx.lr = 0x822C2DC8;
	sub_822CC590(ctx, base);
loc_822C2DC8:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823dba20
	ctx.lr = 0x822C2DDC;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_822C2DE0"))) PPC_WEAK_FUNC(sub_822C2DE0);
PPC_FUNC_IMPL(__imp__sub_822C2DE0) {
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
	ctx.lr = 0x822C2DE8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r29,r10,57792
	r29.u64 = ctx.r10.u64 | 57792;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x822c2e88
	if (!cr6.eq) goto loc_822C2E88;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x822bf540
	ctx.lr = 0x822C2E18;
	sub_822BF540(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c2e54
	if (cr6.eq) goto loc_822C2E54;
	// li r30,0
	r30.s64 = 0;
loc_822C2E2C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mullw r11,r30,r29
	r11.s64 = int64_t(r30.s32) * int64_t(r29.s32);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r27
	ctx.r3.u64 = r11.u64 + r27.u64;
	// bl 0x822c0bb0
	ctx.lr = 0x822C2E40;
	sub_822C0BB0(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x822c2e2c
	if (cr6.lt) goto loc_822C2E2C;
loc_822C2E54:
	// lhz r30,4(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r26,0(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822c2e7c
	if (!cr6.gt) goto loc_822C2E7C;
	// mr r28,r26
	r28.u64 = r26.u64;
loc_822C2E68:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821743b0
	ctx.lr = 0x822C2E70;
	sub_821743B0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// add r28,r28,r29
	r28.u64 = r28.u64 + r29.u64;
	// bne 0x822c2e68
	if (!cr0.eq) goto loc_822C2E68;
loc_822C2E7C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x822C2E84;
	sub_82130588(ctx, base);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
loc_822C2E88:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mullw r10,r11,r29
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822C2EA8"))) PPC_WEAK_FUNC(sub_822C2EA8);
PPC_FUNC_IMPL(__imp__sub_822C2EA8) {
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
	ctx.lr = 0x822C2EB0;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,5
	ctx.r4.s64 = 5;
	// li r3,17000
	ctx.r3.s64 = 17000;
	// bl 0x821bd3c8
	ctx.lr = 0x822C2ED4;
	sub_821BD3C8(ctx, base);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x822C2EDC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c2ef8
	if (cr6.eq) goto loc_822C2EF8;
	// bl 0x8268be38
	ctx.lr = 0x822C2EEC;
	sub_8268BE38(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r31,-10224(r11)
	PPC_STORE_U32(r11.u32 + -10224, r31.u32);
	// b 0x822c2f04
	goto loc_822C2F04;
loc_822C2EF8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10224(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10224, r11.u32);
loc_822C2F04:
	// bl 0x822bfcc8
	ctx.lr = 0x822C2F08;
	sub_822BFCC8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,18332
	ctx.r10.s64 = r11.s64 + 18332;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c2f7c
	if (!cr6.eq) goto loc_822C2F7C;
	// bl 0x822bfd48
	ctx.lr = 0x822C2F20;
	sub_822BFD48(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r3,2836(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2836);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822c2f44
	if (cr6.eq) goto loc_822C2F44;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f1,4400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4400);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821f8038
	ctx.lr = 0x822C2F40;
	sub_821F8038(ctx, base);
	// b 0x822c2f48
	goto loc_822C2F48;
loc_822C2F44:
	// bl 0x821faa98
	ctx.lr = 0x822C2F48;
	sub_821FAA98(ctx, base);
loc_822C2F48:
	// lwz r11,2836(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2836);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c2f7c
	if (cr6.eq) goto loc_822C2F7C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r10,-16376
	ctx.r4.s64 = ctx.r10.s64 + -16376;
	// lwz r31,-17944(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -17944);
	// bl 0x821c2fd8
	ctx.lr = 0x822C2F6C;
	sub_821C2FD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82305690
	ctx.lr = 0x822C2F7C;
	sub_82305690(ctx, base);
loc_822C2F7C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-18004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// bl 0x823047d8
	ctx.lr = 0x822C2F88;
	sub_823047D8(ctx, base);
	// li r27,1
	r27.s64 = 1;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r11,r27
	r11.u64 = r27.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stb r11,-23540(r10)
	PPC_STORE_U8(ctx.r10.u32 + -23540, r11.u8);
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,8368(r8)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8368, temp.u32);
	// lwz r11,18512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 18512);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c303c
	if (cr6.eq) goto loc_822C303C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r5,r11,-6232
	ctx.r5.s64 = r11.s64 + -6232;
	// addi r4,r10,-28384
	ctx.r4.s64 = ctx.r10.s64 + -28384;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x822C2FDC;
	sub_821CA6A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c2fec
	if (cr6.eq) goto loc_822C2FEC;
	// bl 0x821be610
	ctx.lr = 0x822C2FE8;
	sub_821BE610(ctx, base);
	// b 0x822c303c
	goto loc_822C303C;
loc_822C2FEC:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-17856
	ctx.r10.s64 = r11.s64 + -17856;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c300c
	if (cr6.eq) goto loc_822C300C;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x822c3014
	goto loc_822C3014;
loc_822C300C:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	r11.s64 = 0;
loc_822C3014:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3034
	if (cr6.eq) goto loc_822C3034;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r11,-28392
	ctx.r4.s64 = r11.s64 + -28392;
	// bl 0x823d90b0
	ctx.lr = 0x822C302C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822c303c
	if (!cr6.eq) goto loc_822C303C;
loc_822C3034:
	// lwz r3,18512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18512);
	// bl 0x822c3a58
	ctx.lr = 0x822C303C;
	sub_822C3A58(ctx, base);
loc_822C303C:
	// bl 0x822d29a0
	ctx.lr = 0x822C3040;
	sub_822D29A0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822c6fc0
	ctx.lr = 0x822C3048;
	sub_822C6FC0(ctx, base);
	// bl 0x822bfdb0
	ctx.lr = 0x822C304C;
	sub_822BFDB0(ctx, base);
	// bl 0x822d0048
	ctx.lr = 0x822C3050;
	sub_822D0048(ctx, base);
	// bl 0x822c4e28
	ctx.lr = 0x822C3054;
	sub_822C4E28(ctx, base);
	// bl 0x82243780
	ctx.lr = 0x822C3058;
	sub_82243780(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x822C3060;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c3074
	if (cr6.eq) goto loc_822C3074;
	// bl 0x822d2310
	ctx.lr = 0x822C306C;
	sub_822D2310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x822c3078
	goto loc_822C3078;
loc_822C3074:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822C3078:
	// stw r5,852(r28)
	PPC_STORE_U32(r28.u32 + 852, ctx.r5.u32);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r4,1024
	ctx.r4.s64 = 67108864;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// bl 0x822e50d8
	ctx.lr = 0x822C308C;
	sub_822E50D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8260c418
	ctx.lr = 0x822C3094;
	sub_8260C418(ctx, base);
	// lis r10,-32186
	ctx.r10.s64 = -2109341696;
	// addi r3,r10,21944
	ctx.r3.s64 = ctx.r10.s64 + 21944;
	// bl 0x8260c560
	ctx.lr = 0x822C30A0;
	sub_8260C560(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C30A4;
	sub_822C4EB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822c5070
	ctx.lr = 0x822C30AC;
	sub_822C5070(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C30B0;
	sub_822C4EB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822c54d8
	ctx.lr = 0x822C30B8;
	sub_822C54D8(ctx, base);
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82130528
	ctx.lr = 0x822C30C0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c30fc
	if (cr6.eq) goto loc_822C30FC;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f13,84(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,160(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// stw r10,-10952(r7)
	PPC_STORE_U32(ctx.r7.u32 + -10952, ctx.r10.u32);
	// b 0x822c3100
	goto loc_822C3100;
loc_822C30FC:
	// li r11,0
	r11.s64 = 0;
loc_822C3100:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,860(r28)
	PPC_STORE_U32(r28.u32 + 860, r11.u32);
	// li r3,52
	ctx.r3.s64 = 52;
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x822C3118;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c3128
	if (cr6.eq) goto loc_822C3128;
	// bl 0x822d2130
	ctx.lr = 0x822C3124;
	sub_822D2130(ctx, base);
	// b 0x822c312c
	goto loc_822C312C;
loc_822C3128:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C312C:
	// stw r3,856(r28)
	PPC_STORE_U32(r28.u32 + 856, ctx.r3.u32);
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x822C3154;
	sub_8238EC00(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82388908
	ctx.lr = 0x822C3160;
	sub_82388908(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27644(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f30,f13,f0
	f30.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbae8
	ctx.lr = 0x822C3178;
	sub_823DBAE8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822C3184;
	sub_823DBBC8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// li r3,868
	ctx.r3.s64 = 868;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fnmsubs f11,f29,f31,f12
	ctx.f11.f64 = double(float(-(f29.f64 * f31.f64 - ctx.f12.f64)));
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmadds f10,f12,f31,f29
	ctx.f10.f64 = double(float(ctx.f12.f64 * f31.f64 + f29.f64));
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130528
	ctx.lr = 0x822C31BC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c31cc
	if (cr6.eq) goto loc_822C31CC;
	// bl 0x825029b0
	ctx.lr = 0x822C31C8;
	sub_825029B0(ctx, base);
	// b 0x822c31d0
	goto loc_822C31D0;
loc_822C31CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C31D0:
	// stw r3,828(r28)
	PPC_STORE_U32(r28.u32 + 828, ctx.r3.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82502c58
	ctx.lr = 0x822C31E4;
	sub_82502C58(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821fe648
	ctx.lr = 0x822C31F0;
	sub_821FE648(ctx, base);
	// li r3,216
	ctx.r3.s64 = 216;
	// bl 0x82130528
	ctx.lr = 0x822C31F8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c3208
	if (cr6.eq) goto loc_822C3208;
	// bl 0x822cbb30
	ctx.lr = 0x822C3204;
	sub_822CBB30(ctx, base);
	// b 0x822c320c
	goto loc_822C320C;
loc_822C3208:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C320C:
	// stw r3,864(r28)
	PPC_STORE_U32(r28.u32 + 864, ctx.r3.u32);
	// bl 0x822c4eb8
	ctx.lr = 0x822C3214;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c5070
	ctx.lr = 0x822C321C;
	sub_822C5070(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C3220;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c5070
	ctx.lr = 0x822C3228;
	sub_822C5070(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C322C;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c54d8
	ctx.lr = 0x822C3234;
	sub_822C54D8(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C3238;
	sub_822C4EB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822c5070
	ctx.lr = 0x822C3240;
	sub_822C5070(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C3244;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822c5070
	ctx.lr = 0x822C324C;
	sub_822C5070(ctx, base);
	// bl 0x822c4eb8
	ctx.lr = 0x822C3250;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822c54d8
	ctx.lr = 0x822C3258;
	sub_822C54D8(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x822C3260;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c3280
	if (cr6.eq) goto loc_822C3280;
	// bl 0x826b5a70
	ctx.lr = 0x822C3270;
	sub_826B5A70(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r11,18504
	r30.s64 = r11.s64 + 18504;
	// stw r31,18504(r11)
	PPC_STORE_U32(r11.u32 + 18504, r31.u32);
	// b 0x822c3290
	goto loc_822C3290;
loc_822C3280:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r10,18504
	r30.s64 = ctx.r10.s64 + 18504;
	// stw r11,18504(r10)
	PPC_STORE_U32(ctx.r10.u32 + 18504, r11.u32);
loc_822C3290:
	// bl 0x822bfe30
	ctx.lr = 0x822C3294;
	sub_822BFE30(ctx, base);
	// bl 0x822bfeb0
	ctx.lr = 0x822C3298;
	sub_822BFEB0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r29,3
	r29.s64 = 3;
	// addi r10,r11,-5004
	ctx.r10.s64 = r11.s64 + -5004;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c32e8
	if (cr6.eq) goto loc_822C32E8;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-28404
	ctx.r4.s64 = ctx.r10.s64 + -28404;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x822C32C8;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,32684
	ctx.r4.s64 = ctx.r9.s64 + 32684;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// stw r27,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r27.u32);
	// bl 0x823dc018
	ctx.lr = 0x822C32E4;
	sub_823DC018(ctx, base);
	// stw r29,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r29.u32);
loc_822C32E8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r9,r10,18292
	ctx.r9.s64 = ctx.r10.s64 + 18292;
	// addi r3,r11,-28420
	ctx.r3.s64 = r11.s64 + -28420;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3308
	if (cr6.eq) goto loc_822C3308;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_822C3308:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3330
	if (cr6.eq) goto loc_822C3330;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x822C332C;
	sub_82727908(ctx, base);
	// stw r3,848(r28)
	PPC_STORE_U32(r28.u32 + 848, ctx.r3.u32);
loc_822C3330:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x826b5aa0
	ctx.lr = 0x822C3338;
	sub_826B5AA0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826bb368
	ctx.lr = 0x822C3344;
	sub_826BB368(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826c0c50
	ctx.lr = 0x822C3350;
	sub_826C0C50(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822bf258
	ctx.lr = 0x822C3358;
	sub_822BF258(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-12356(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12356);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822C3374;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r11,-17628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c346c
	if (!cr6.eq) goto loc_822C346C;
	// li r3,52
	ctx.r3.s64 = 52;
	// bl 0x82130528
	ctx.lr = 0x822C338C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c339c
	if (cr6.eq) goto loc_822C339C;
	// bl 0x82173500
	ctx.lr = 0x822C3398;
	sub_82173500(ctx, base);
	// b 0x822c33a0
	goto loc_822C33A0;
loc_822C339C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C33A0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r3,-17628(r31)
	PPC_STORE_U32(r31.u32 + -17628, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// li r4,3
	ctx.r4.s64 = 3;
	// lfs f0,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f13,-28424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28424);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,10584(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 10584, temp.u32);
	// stfs f13,-30940(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + -30940, temp.u32);
	// bl 0x822bf540
	ctx.lr = 0x822C33D0;
	sub_822BF540(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r28,0
	r28.s64 = 0;
	// ori r29,r11,57792
	r29.u64 = r11.u64 | 57792;
	// ori r30,r10,57680
	r30.u64 = ctx.r10.u64 | 57680;
loc_822C33EC:
	// lwz r3,-17628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x822c2de0
	ctx.lr = 0x822C33FC;
	sub_822C2DE0(ctx, base);
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// li r5,512
	ctx.r5.s64 = 512;
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mullw r10,r11,r29
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stwx r11,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, r11.u32);
	// lwz r11,-17628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bne cr6,0x822c3430
	if (!cr6.eq) goto loc_822C3430;
	// li r5,1024
	ctx.r5.s64 = 1024;
loc_822C3430:
	// li r4,64
	ctx.r4.s64 = 64;
	// bl 0x822bf790
	ctx.lr = 0x822C3438;
	sub_822BF790(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// blt cr6,0x822c33ec
	if (cr6.lt) goto loc_822C33EC;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-17508
	ctx.r10.s64 = r11.s64 + -17508;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-17628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// beq cr6,0x822c3468
	if (cr6.eq) goto loc_822C3468;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,45(r11)
	PPC_STORE_U8(r11.u32 + 45, ctx.r10.u8);
	// b 0x822c346c
	goto loc_822C346C;
loc_822C3468:
	// stb r27,45(r11)
	PPC_STORE_U8(r11.u32 + 45, r27.u8);
loc_822C346C:
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r11,-17604(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17604);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c34bc
	if (!cr6.eq) goto loc_822C34BC;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x822C3484;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c3498
	if (cr6.eq) goto loc_822C3498;
	// bl 0x82689a10
	ctx.lr = 0x822C3490;
	sub_82689A10(ctx, base);
	// stw r3,-17604(r31)
	PPC_STORE_U32(r31.u32 + -17604, ctx.r3.u32);
	// b 0x822c34a0
	goto loc_822C34A0;
loc_822C3498:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-17604(r31)
	PPC_STORE_U32(r31.u32 + -17604, r11.u32);
loc_822C34A0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r9,r11,-17488
	ctx.r9.s64 = r11.s64 + -17488;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-30011(r10)
	PPC_STORE_U8(ctx.r10.u32 + -30011, r11.u8);
loc_822C34BC:
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r11,-17600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c350c
	if (!cr6.eq) goto loc_822C350C;
	// li r3,704
	ctx.r3.s64 = 704;
	// bl 0x82130528
	ctx.lr = 0x822C34D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c34e8
	if (cr6.eq) goto loc_822C34E8;
	// bl 0x82689bc8
	ctx.lr = 0x822C34E0;
	sub_82689BC8(ctx, base);
	// stw r3,-17600(r31)
	PPC_STORE_U32(r31.u32 + -17600, ctx.r3.u32);
	// b 0x822c34f0
	goto loc_822C34F0;
loc_822C34E8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-17600(r31)
	PPC_STORE_U32(r31.u32 + -17600, r11.u32);
loc_822C34F0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r9,r11,-17568
	ctx.r9.s64 = r11.s64 + -17568;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-17596(r10)
	PPC_STORE_U8(ctx.r10.u32 + -17596, r11.u8);
loc_822C350C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

__attribute__((alias("__imp__sub_822C3520"))) PPC_WEAK_FUNC(sub_822C3520);
PPC_FUNC_IMPL(__imp__sub_822C3520) {
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// beq cr6,0x822c356c
	if (cr6.eq) goto loc_822C356C;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_822C3548:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c3548
	if (!cr6.eq) goto loc_822C3548;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x822C356C;
	sub_821C9650(ctx, base);
loc_822C356C:
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

__attribute__((alias("__imp__sub_822C3584"))) PPC_WEAK_FUNC(sub_822C3584);
PPC_FUNC_IMPL(__imp__sub_822C3584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C3588"))) PPC_WEAK_FUNC(sub_822C3588);
PPC_FUNC_IMPL(__imp__sub_822C3588) {
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
	ctx.lr = 0x822C3590;
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
	// beq cr6,0x822c35f4
	if (cr6.eq) goto loc_822C35F4;
	// lwz r10,-8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// addi r29,r30,-8
	r29.s64 = r30.s64 + -8;
	// mulli r11,r10,1144
	r11.s64 = ctx.r10.s64 * 1144;
	// addic. r31,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r31.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// blt 0x822c35d4
	if (cr0.lt) goto loc_822C35D4;
loc_822C35C0:
	// addi r30,r30,-1144
	r30.s64 = r30.s64 + -1144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821cce58
	ctx.lr = 0x822C35CC;
	sub_821CCE58(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x822c35c0
	if (!cr0.lt) goto loc_822C35C0;
loc_822C35D4:
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c35e8
	if (cr6.eq) goto loc_822C35E8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822C35E8;
	sub_82130588(ctx, base);
loc_822C35E8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822C35F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821cce58
	ctx.lr = 0x822C35FC;
	sub_821CCE58(ctx, base);
	// clrlwi r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3610
	if (cr6.eq) goto loc_822C3610;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822C3610;
	sub_82130588(ctx, base);
loc_822C3610:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C361C"))) PPC_WEAK_FUNC(sub_822C361C);
PPC_FUNC_IMPL(__imp__sub_822C361C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C3620"))) PPC_WEAK_FUNC(sub_822C3620);
PPC_FUNC_IMPL(__imp__sub_822C3620) {
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
	ctx.lr = 0x822C3628;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r11,18568
	ctx.r10.s64 = r11.s64 + 18568;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3650
	if (cr6.eq) goto loc_822C3650;
loc_822C3644:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822C3650:
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c3644
	if (!cr6.eq) goto loc_822C3644;
	// addis r30,r3,2
	r30.s64 = ctx.r3.s64 + 131072;
	// addi r30,r30,40
	r30.s64 = r30.s64 + 40;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822c3644
	if (!cr6.eq) goto loc_822C3644;
	// addis r28,r3,2
	r28.s64 = ctx.r3.s64 + 131072;
	// addi r31,r3,36
	r31.s64 = ctx.r3.s64 + 36;
	// addi r28,r28,36
	r28.s64 = r28.s64 + 36;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lis r5,2
	ctx.r5.s64 = 131072;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// bl 0x823d9890
	ctx.lr = 0x822C3690;
	sub_823D9890(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r4,r10,-27968
	ctx.r4.s64 = ctx.r10.s64 + -27968;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lis r6,2
	ctx.r6.s64 = 131072;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82272e10
	ctx.lr = 0x822C36B0;
	sub_82272E10(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C36B8"))) PPC_WEAK_FUNC(sub_822C36B8);
PPC_FUNC_IMPL(__imp__sub_822C36B8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,128
	ctx.r10.s64 = 128;
	// addi r11,r31,15
	r11.s64 = r31.s64 + 15;
	// subf r9,r31,r30
	ctx.r9.s64 = r30.s64 - r31.s64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// lbz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// stb r5,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r5.u8);
	// lbz r4,13(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// stb r4,13(r31)
	PPC_STORE_U8(r31.u32 + 13, ctx.r4.u8);
	// lbz r3,14(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 14);
	// stb r3,14(r31)
	PPC_STORE_U8(r31.u32 + 14, ctx.r3.u8);
loc_822C3710:
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x822c3710
	if (!cr0.eq) goto loc_822C3710;
	// addi r11,r31,143
	r11.s64 = r31.s64 + 143;
	// li r10,16
	ctx.r10.s64 = 16;
loc_822C372C:
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x822c372c
	if (!cr0.eq) goto loc_822C372C;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,160
	ctx.r3.s64 = r31.s64 + 160;
	// sth r11,164(r31)
	PPC_STORE_U16(r31.u32 + 164, r11.u16);
	// lwz r4,160(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// lhz r5,164(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 164);
	// bl 0x821c9650
	ctx.lr = 0x822C3758;
	sub_821C9650(ctx, base);
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_822C377C"))) PPC_WEAK_FUNC(sub_822C377C);
PPC_FUNC_IMPL(__imp__sub_822C377C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C3780"))) PPC_WEAK_FUNC(sub_822C3780);
PPC_FUNC_IMPL(__imp__sub_822C3780) {
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
	ctx.lr = 0x822C3788;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mulli r3,r30,172
	ctx.r3.s64 = r30.s64 * 172;
	// bl 0x82130528
	ctx.lr = 0x822C3798;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822c3808
	if (!cr6.gt) goto loc_822C3808;
	// mr r29,r30
	r29.u64 = r30.u64;
	// addi r31,r28,166
	r31.s64 = r28.s64 + 166;
	// li r30,0
	r30.s64 = 0;
loc_822C37B0:
	// addic. r11,r31,-166
	xer.ca = r31.u32 > 165;
	r11.s64 = r31.s64 + -166;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x822c37fc
	if (cr0.eq) goto loc_822C37FC;
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r30,-166(r31)
	PPC_STORE_U32(r31.u32 + -166, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,-162(r31)
	PPC_STORE_U32(r31.u32 + -162, r30.u32);
	// addi r3,r31,-151
	ctx.r3.s64 = r31.s64 + -151;
	// stw r30,-158(r31)
	PPC_STORE_U32(r31.u32 + -158, r30.u32);
	// stb r30,-154(r31)
	PPC_STORE_U8(r31.u32 + -154, r30.u8);
	// stb r30,-153(r31)
	PPC_STORE_U8(r31.u32 + -153, r30.u8);
	// stb r30,-152(r31)
	PPC_STORE_U8(r31.u32 + -152, r30.u8);
	// stw r30,-6(r31)
	PPC_STORE_U32(r31.u32 + -6, r30.u32);
	// sth r30,-2(r31)
	PPC_STORE_U16(r31.u32 + -2, r30.u16);
	// sth r30,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r30.u16);
	// bl 0x823d9890
	ctx.lr = 0x822C37EC;
	sub_823D9890(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,-23
	ctx.r3.s64 = r31.s64 + -23;
	// bl 0x823d9890
	ctx.lr = 0x822C37FC;
	sub_823D9890(ctx, base);
loc_822C37FC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,172
	r31.s64 = r31.s64 + 172;
	// bne 0x822c37b0
	if (!cr0.eq) goto loc_822C37B0;
loc_822C3808:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C3814"))) PPC_WEAK_FUNC(sub_822C3814);
PPC_FUNC_IMPL(__imp__sub_822C3814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C3818"))) PPC_WEAK_FUNC(sub_822C3818);
PPC_FUNC_IMPL(__imp__sub_822C3818) {
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
	ctx.lr = 0x822C3820;
	// stwu r1,-832(r1)
	ea = -832 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r5,r11,-6232
	ctx.r5.s64 = r11.s64 + -6232;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x822C384C;
	sub_821CA6A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x822c3860
	if (!cr6.eq) goto loc_822C3860;
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d9240
	return;
loc_822C3860:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x822C3868;
	sub_821D1CD0(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x822C3878;
	sub_821CF7B8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r27,0
	r27.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-27852
	ctx.r4.s64 = r11.s64 + -27852;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r27
	r29.u64 = r27.u64;
	// bl 0x821cff40
	ctx.lr = 0x822C3894;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c38b0
	if (cr6.eq) goto loc_822C38B0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0490
	ctx.lr = 0x822C38AC;
	sub_821D0490(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_822C38B0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-27868
	ctx.r4.s64 = r11.s64 + -27868;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r27
	r30.u64 = r27.u64;
	// bl 0x821cff40
	ctx.lr = 0x822C38C8;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c38e4
	if (cr6.eq) goto loc_822C38E4;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0490
	ctx.lr = 0x822C38E0;
	sub_821D0490(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_822C38E4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-27884
	ctx.r4.s64 = r11.s64 + -27884;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cff40
	ctx.lr = 0x822C38F8;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c390c
	if (cr6.eq) goto loc_822C390C;
	// stb r28,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r28.u8);
loc_822C390C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-27900
	ctx.r4.s64 = r11.s64 + -27900;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cff40
	ctx.lr = 0x822C3920;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c3930
	if (cr6.eq) goto loc_822C3930;
	// stb r28,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r28.u8);
loc_822C3930:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-25240
	ctx.r4.s64 = r11.s64 + -25240;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cff40
	ctx.lr = 0x822C3944;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c3960
	if (cr6.eq) goto loc_822C3960;
	// li r5,127
	ctx.r5.s64 = 127;
	// addi r4,r31,15
	ctx.r4.s64 = r31.s64 + 15;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cfaa8
	ctx.lr = 0x822C3960;
	sub_821CFAA8(ctx, base);
loc_822C3960:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,9848
	ctx.r4.s64 = r11.s64 + 9848;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cff40
	ctx.lr = 0x822C3974;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c39ac
	if (cr6.eq) goto loc_822C39AC;
loc_822C3980:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,127
	ctx.r5.s64 = 127;
	// addi r4,r1,640
	ctx.r4.s64 = ctx.r1.s64 + 640;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cffe8
	ctx.lr = 0x822C3998;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822c3980
	if (cr6.eq) goto loc_822C3980;
	// addi r4,r1,640
	ctx.r4.s64 = ctx.r1.s64 + 640;
	// addi r3,r31,160
	ctx.r3.s64 = r31.s64 + 160;
	// bl 0x822c3520
	ctx.lr = 0x822C39AC;
	sub_822C3520(ctx, base);
loc_822C39AC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-27928
	ctx.r4.s64 = r11.s64 + -27928;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cff40
	ctx.lr = 0x822C39C0;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c39f4
	if (!cr6.eq) goto loc_822C39F4;
	// stb r27,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r27.u8);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r27,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r27.u8);
	// addi r3,r31,160
	ctx.r3.s64 = r31.s64 + 160;
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// bl 0x822c3520
	ctx.lr = 0x822C39E8;
	sub_822C3520(ctx, base);
	// mr r29,r27
	r29.u64 = r27.u64;
	// stb r27,15(r31)
	PPC_STORE_U8(r31.u32 + 15, r27.u8);
	// mr r30,r27
	r30.u64 = r27.u64;
loc_822C39F4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-27948
	ctx.r4.s64 = r11.s64 + -27948;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cff40
	ctx.lr = 0x822C3A08;
	sub_821CFF40(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be610
	ctx.lr = 0x822C3A10;
	sub_821BE610(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-28304
	r11.s64 = r11.s64 + -28304;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// or r9,r10,r29
	ctx.r9.u64 = ctx.r10.u64 | r29.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// or r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 | r30.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822c3a44
	if (cr6.eq) goto loc_822C3A44;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// and r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ctx.r10.u64;
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_822C3A44:
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822C3A58"))) PPC_WEAK_FUNC(sub_822C3A58);
PPC_FUNC_IMPL(__imp__sub_822C3A58) {
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
	ctx.lr = 0x822C3A60;
	// stwu r1,-1008(r1)
	ea = -1008 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r11,18628
	ctx.r10.s64 = r11.s64 + 18628;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822c3cc0
	if (cr6.eq) goto loc_822C3CC0;
	// li r5,511
	ctx.r5.s64 = 511;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x823db670
	ctx.lr = 0x822C3A88;
	sub_823DB670(ctx, base);
	// li r21,0
	r21.s64 = 0;
	// addi r29,r1,384
	r29.s64 = ctx.r1.s64 + 384;
	// mr r31,r21
	r31.u64 = r21.u64;
	// stb r21,895(r1)
	PPC_STORE_U8(ctx.r1.u32 + 895, r21.u8);
	// stw r21,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r21.u32);
	// b 0x822c3aa4
	goto loc_822C3AA4;
loc_822C3AA0:
	// lwz r31,112(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
loc_822C3AA4:
	// li r4,59
	ctx.r4.s64 = 59;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823dd850
	ctx.lr = 0x822C3AB0;
	sub_823DD850(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c3ac0
	if (cr6.eq) goto loc_822C3AC0;
	// stb r21,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r21.u8);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_822C3AC0:
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r8,r31,1
	ctx.r8.s64 = r31.s64 + 1;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r31,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r31.u32);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bne cr6,0x822c3aa0
	if (!cr6.eq) goto loc_822C3AA0;
	// lis r11,57
	r11.s64 = 3735552;
	// li r27,-1
	r27.s64 = -1;
	// ori r10,r11,18790
	ctx.r10.u64 = r11.u64 | 18790;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bgt cr6,0x822c3b14
	if (cr6.gt) goto loc_822C3B14;
	// mulli r11,r31,1144
	r11.s64 = r31.s64 * 1144;
	// li r10,-9
	ctx.r10.s64 = -9;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x822c3b18
	if (!cr6.gt) goto loc_822C3B18;
loc_822C3B14:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_822C3B18:
	// bl 0x82130528
	ctx.lr = 0x822C3B1C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c3b50
	if (cr6.eq) goto loc_822C3B50;
	// addi r28,r3,8
	r28.s64 = ctx.r3.s64 + 8;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// mr r29,r28
	r29.u64 = r28.u64;
	// blt 0x822c3b54
	if (cr0.lt) goto loc_822C3B54;
loc_822C3B38:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821cd750
	ctx.lr = 0x822C3B40;
	sub_821CD750(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,1144
	r29.s64 = r29.s64 + 1144;
	// bge 0x822c3b38
	if (!cr0.lt) goto loc_822C3B38;
	// b 0x822c3b54
	goto loc_822C3B54;
loc_822C3B50:
	// mr r28,r21
	r28.u64 = r21.u64;
loc_822C3B54:
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r28,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r28.u32);
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x822c3b74
	if (!cr6.gt) goto loc_822C3B74;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_822C3B74:
	// bl 0x82130528
	ctx.lr = 0x822C3B78;
	sub_82130528(ctx, base);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822c3cc0
	if (!cr6.gt) goto loc_822C3CC0;
	// mr r22,r11
	r22.u64 = r11.u64;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r21
	r31.u64 = r21.u64;
	// mr r27,r21
	r27.u64 = r21.u64;
	// addi r26,r8,-27780
	r26.s64 = ctx.r8.s64 + -27780;
	// addi r25,r9,-27824
	r25.s64 = ctx.r9.s64 + -27824;
	// addi r24,r10,-27836
	r24.s64 = ctx.r10.s64 + -27836;
	// addi r23,r11,30576
	r23.s64 = r11.s64 + 30576;
loc_822C3BB4:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r28,r31,r11
	r28.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x822C3BD4;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822c3c9c
	if (cr6.eq) goto loc_822C3C9C;
	// bl 0x821bdd08
	ctx.lr = 0x822C3BE4;
	sub_821BDD08(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// bl 0x82130528
	ctx.lr = 0x822C3BEC;
	sub_82130528(ctx, base);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r4,r9,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// bl 0x821be250
	ctx.lr = 0x822C3C0C;
	sub_821BE250(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x822C3C14;
	sub_821BE610(ctx, base);
	// lwz r5,28(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwzx r5,r5,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + r31.u32);
	// bl 0x821cb740
	ctx.lr = 0x822C3C34;
	sub_821CB740(ctx, base);
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// add r3,r11,r27
	ctx.r3.u64 = r11.u64 + r27.u64;
	// bl 0x821cd7a0
	ctx.lr = 0x822C3C50;
	sub_821CD7A0(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822c3c78
	if (cr6.eq) goto loc_822C3C78;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// add r3,r11,r27
	ctx.r3.u64 = r11.u64 + r27.u64;
	// bl 0x821cbf28
	ctx.lr = 0x822C3C6C;
	sub_821CBF28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c3cb0
	if (!cr6.eq) goto loc_822C3CB0;
loc_822C3C78:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x822C3C84;
	sub_82130000(ctx, base);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82130588
	ctx.lr = 0x822C3C90;
	sub_82130588(ctx, base);
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// stwx r21,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r21.u32);
	// b 0x822c3cb0
	goto loc_822C3CB0;
loc_822C3C9C:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stwx r21,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r21.u32);
	// bl 0x82130000
	ctx.lr = 0x822C3CB0;
	sub_82130000(ctx, base);
loc_822C3CB0:
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// addi r27,r27,1144
	r27.s64 = r27.s64 + 1144;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822c3bb4
	if (!cr0.eq) goto loc_822C3BB4;
loc_822C3CC0:
	// addi r1,r1,1008
	ctx.r1.s64 = ctx.r1.s64 + 1008;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_822C3CC8"))) PPC_WEAK_FUNC(sub_822C3CC8);
PPC_FUNC_IMPL(__imp__sub_822C3CC8) {
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
	ctx.lr = 0x822C3CD0;
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
	// bne cr6,0x822c3d68
	if (!cr6.eq) goto loc_822C3D68;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x822c3780
	ctx.lr = 0x822C3CF8;
	sub_822C3780(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c3d34
	if (cr6.eq) goto loc_822C3D34;
	// li r30,0
	r30.s64 = 0;
loc_822C3D0C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r11,r30,172
	r11.s64 = r30.s64 * 172;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r28
	ctx.r3.u64 = r11.u64 + r28.u64;
	// bl 0x822c36b8
	ctx.lr = 0x822C3D20;
	sub_822C36B8(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x822c3d0c
	if (cr6.lt) goto loc_822C3D0C;
loc_822C3D34:
	// lhz r30,4(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822c3d5c
	if (!cr6.gt) goto loc_822C3D5C;
	// addi r29,r27,160
	r29.s64 = r27.s64 + 160;
loc_822C3D48:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822C3D50;
	sub_82130588(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,172
	r29.s64 = r29.s64 + 172;
	// bne 0x822c3d48
	if (!cr0.eq) goto loc_822C3D48;
loc_822C3D5C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x822C3D64;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_822C3D68:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r10,r11,172
	ctx.r10.s64 = r11.s64 * 172;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822C3D88"))) PPC_WEAK_FUNC(sub_822C3D88);
PPC_FUNC_IMPL(__imp__sub_822C3D88) {
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
	ctx.lr = 0x822C3D90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,18608
	ctx.r9.s64 = r11.s64 + 18608;
	// addi r8,r10,-27752
	ctx.r8.s64 = ctx.r10.s64 + -27752;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3dcc
	if (cr6.eq) goto loc_822C3DCC;
	// lis r11,-32123
	r11.s64 = -2105212928;
	// lwz r11,24076(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24076);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3dcc
	if (cr6.eq) goto loc_822C3DCC;
	// bl 0x821c3e70
	ctx.lr = 0x822C3DCC;
	sub_821C3E70(ctx, base);
loc_822C3DCC:
	// addis r31,r29,2
	r31.s64 = r29.s64 + 131072;
	// addi r31,r31,52
	r31.s64 = r31.s64 + 52;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8244eee0
	ctx.lr = 0x822C3DDC;
	sub_8244EEE0(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3e20
	if (cr6.eq) goto loc_822C3E20;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// addi r3,r11,-8
	ctx.r3.s64 = r11.s64 + -8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822c3e1c
	if (cr6.eq) goto loc_822C3E1C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C3E18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c3e20
	goto loc_822C3E20;
loc_822C3E1C:
	// bl 0x82130588
	ctx.lr = 0x822C3E20;
	sub_82130588(ctx, base);
loc_822C3E20:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3e5c
	if (cr6.eq) goto loc_822C3E5C;
	// lwz r10,-8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// addi r3,r11,-8
	ctx.r3.s64 = r11.s64 + -8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822c3e58
	if (cr6.eq) goto loc_822C3E58;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C3E54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c3e5c
	goto loc_822C3E5C;
loc_822C3E58:
	// bl 0x82130588
	ctx.lr = 0x822C3E5C;
	sub_82130588(ctx, base);
loc_822C3E5C:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822c3e90
	if (!cr6.gt) goto loc_822C3E90;
	// li r31,0
	r31.s64 = 0;
loc_822C3E70:
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82130588
	ctx.lr = 0x822C3E7C;
	sub_82130588(ctx, base);
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x822c3e70
	if (cr6.lt) goto loc_822C3E70;
loc_822C3E90:
	// lwz r3,28(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x822C3E98;
	sub_82130588(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,18512(r10)
	PPC_STORE_U32(ctx.r10.u32 + 18512, r11.u32);
	// lhz r31,18(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 18);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822c3edc
	if (cr6.eq) goto loc_822C3EDC;
	// lwz r28,12(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822c3ed4
	if (!cr6.gt) goto loc_822C3ED4;
	// addi r30,r28,160
	r30.s64 = r28.s64 + 160;
loc_822C3EC0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822C3EC8;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,172
	r30.s64 = r30.s64 + 172;
	// bne 0x822c3ec0
	if (!cr0.eq) goto loc_822C3EC0;
loc_822C3ED4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x822C3EDC;
	sub_82130588(ctx, base);
loc_822C3EDC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x822C3EE4;
	sub_821D2028(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C3EEC"))) PPC_WEAK_FUNC(sub_822C3EEC);
PPC_FUNC_IMPL(__imp__sub_822C3EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C3EF0"))) PPC_WEAK_FUNC(sub_822C3EF0);
PPC_FUNC_IMPL(__imp__sub_822C3EF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x822C3EF8;
	// stwu r1,-1200(r1)
	ea = -1200 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// stw r5,1236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1236, ctx.r5.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r25,0
	r25.s64 = 0;
	// stw r3,1228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1228, ctx.r3.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// blt cr6,0x822c3f58
	if (cr6.lt) goto loc_822C3F58;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824500e8
	ctx.lr = 0x822C3F40;
	sub_824500E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822c3f64
	if (cr6.eq) goto loc_822C3F64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-27428
	ctx.r3.s64 = r11.s64 + -27428;
	// bl 0x82130000
	ctx.lr = 0x822C3F58;
	sub_82130000(ctx, base);
loc_822C3F58:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// b 0x823d9210
	return;
loc_822C3F64:
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lis r27,-32252
	r27.s64 = -2113667072;
	// addi r3,r3,-27456
	ctx.r3.s64 = ctx.r3.s64 + -27456;
	// lis r29,-32252
	r29.s64 = -2113667072;
	// lis r30,-32252
	r30.s64 = -2113667072;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r26,2
	r26.s64 = 131072;
	// lis r28,-32129
	r28.s64 = -2105606144;
	// lis r31,-32252
	r31.s64 = -2113667072;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r27,r27,-27500
	r27.s64 = r27.s64 + -27500;
	// addi r29,r29,-27544
	r29.s64 = r29.s64 + -27544;
	// addi r30,r30,-27580
	r30.s64 = r30.s64 + -27580;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// addi r4,r4,-27604
	ctx.r4.s64 = ctx.r4.s64 + -27604;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r29.u32);
	// addi r7,r7,-27636
	ctx.r7.s64 = ctx.r7.s64 + -27636;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// addi r3,r8,-27644
	ctx.r3.s64 = ctx.r8.s64 + -27644;
	// stw r4,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// lis r15,-32121
	r15.s64 = -2105081856;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// ori r17,r26,49
	r17.u64 = r26.u64 | 49;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r24,r28,-28304
	r24.s64 = r28.s64 + -28304;
	// addi r14,r31,-27836
	r14.s64 = r31.s64 + -27836;
	// addi r16,r5,-27676
	r16.s64 = ctx.r5.s64 + -27676;
	// addi r18,r6,-27700
	r18.s64 = ctx.r6.s64 + -27700;
	// addi r21,r9,-27716
	r21.s64 = ctx.r9.s64 + -27716;
	// addi r20,r10,-27732
	r20.s64 = ctx.r10.s64 + -27732;
	// addi r19,r11,-27748
	r19.s64 = r11.s64 + -27748;
loc_822C3FFC:
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130528
	ctx.lr = 0x822C4008;
	sub_82130528(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x824501c8
	ctx.lr = 0x822C4024;
	sub_824501C8(ctx, base);
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822c4360
	if (!cr6.eq) goto loc_822C4360;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c4360
	if (cr6.eq) goto loc_822C4360;
	// addi r4,r26,264
	ctx.r4.s64 = r26.s64 + 264;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// li r5,42
	ctx.r5.s64 = 42;
	// bl 0x823da950
	ctx.lr = 0x822C404C;
	sub_823DA950(ctx, base);
	// addi r22,r26,8
	r22.s64 = r26.s64 + 8;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stb r25,266(r1)
	PPC_STORE_U8(ctx.r1.u32 + 266, r25.u8);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x822C4060;
	sub_82130000(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// bl 0x82130000
	ctx.lr = 0x822C406C;
	sub_82130000(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lwz r4,4(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// bl 0x82130000
	ctx.lr = 0x822C4078;
	sub_82130000(ctx, base);
	// li r27,-1
	r27.s64 = -1;
	// li r28,-1
	r28.s64 = -1;
	// mr r30,r25
	r30.u64 = r25.u64;
	// lhz r31,16(r23)
	r31.u64 = PPC_LOAD_U16(r23.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822c4118
	if (!cr6.gt) goto loc_822C4118;
	// lwz r11,12(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// addi r29,r11,168
	r29.s64 = r11.s64 + 168;
loc_822C4098:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c40f4
	if (cr6.eq) goto loc_822C40F4;
	// addi r4,r11,264
	ctx.r4.s64 = r11.s64 + 264;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r5,42
	ctx.r5.s64 = 42;
	// bl 0x823da950
	ctx.lr = 0x822C40B4;
	sub_823DA950(ctx, base);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stb r25,202(r1)
	PPC_STORE_U8(ctx.r1.u32 + 202, r25.u8);
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
loc_822C40C0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822c40e4
	if (cr6.eq) goto loc_822C40E4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822c40c0
	if (cr6.eq) goto loc_822C40C0;
loc_822C40E4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822c4100
	if (!cr6.eq) goto loc_822C4100;
	// mr r27,r30
	r27.u64 = r30.u64;
	// b 0x822c4100
	goto loc_822C4100;
loc_822C40F4:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bge cr6,0x822c4100
	if (!cr6.lt) goto loc_822C4100;
	// mr r28,r30
	r28.u64 = r30.u64;
loc_822C4100:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,172
	r29.s64 = r29.s64 + 172;
	// cmpw cr6,r30,r31
	cr6.compare<int32_t>(r30.s32, r31.s32, xer);
	// blt cr6,0x822c4098
	if (cr6.lt) goto loc_822C4098;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bge cr6,0x822c4358
	if (!cr6.lt) goto loc_822C4358;
loc_822C4118:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// blt cr6,0x822c4128
	if (cr6.lt) goto loc_822C4128;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_822C4128:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r5,116(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// li r4,15
	ctx.r4.s64 = 15;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82137a08
	ctx.lr = 0x822C413C;
	sub_82137A08(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r3,1228(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1228);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82450188
	ctx.lr = 0x822C415C;
	sub_82450188(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822c4360
	if (!cr6.eq) goto loc_822C4360;
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130000
	ctx.lr = 0x822C4170;
	sub_82130000(ctx, base);
	// lhz r11,16(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 16);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bne cr6,0x822c4188
	if (!cr6.eq) goto loc_822C4188;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r23,12
	ctx.r3.s64 = r23.s64 + 12;
	// bl 0x822c3cc8
	ctx.lr = 0x822C4188;
	sub_822C3CC8(ctx, base);
loc_822C4188:
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// mulli r11,r31,172
	r11.s64 = r31.s64 * 172;
	// li r3,1144
	ctx.r3.s64 = 1144;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82130528
	ctx.lr = 0x822C419C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c41ac
	if (cr6.eq) goto loc_822C41AC;
	// bl 0x821cd750
	ctx.lr = 0x822C41A8;
	sub_821CD750(ctx, base);
	// b 0x822c41b0
	goto loc_822C41B0;
loc_822C41AC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_822C41B0:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,15
	ctx.r4.s64 = 15;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r3,r31,143
	ctx.r3.s64 = r31.s64 + 143;
	// stw r25,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r25.u32);
	// stb r25,15(r31)
	PPC_STORE_U8(r31.u32 + 15, r25.u8);
	// bl 0x82137a08
	ctx.lr = 0x822C41D4;
	sub_82137A08(ctx, base);
	// lbzx r10,r23,r17
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + r17.u32);
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// add r30,r23,r17
	r30.u64 = r23.u64 + r17.u64;
	// lwz r29,0(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r28,4(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// bl 0x82137a08
	ctx.lr = 0x822C41FC;
	sub_82137A08(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822c3818
	ctx.lr = 0x822C420C;
	sub_822C3818(ctx, base);
	// lbz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c434c
	if (!cr6.eq) goto loc_822C434C;
	// lbz r11,14(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14);
	// lwz r10,1236(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c423c
	if (cr6.eq) goto loc_822C423C;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x822c423c
	if (!cr6.lt) goto loc_822C423C;
	// li r11,1
	r11.s64 = 1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_822C423C:
	// lbz r11,13(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c4290
	if (cr6.eq) goto loc_822C4290;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x822c4290
	if (cr6.eq) goto loc_822C4290;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bge cr6,0x822c4264
	if (!cr6.lt) goto loc_822C4264;
	// li r11,2
	r11.s64 = 2;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_822C4264:
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x822C4278;
	sub_82137A08(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,-10244(r15)
	ctx.r3.u64 = PPC_LOAD_U32(r15.u32 + -10244);
	// bl 0x82217618
	ctx.lr = 0x822C4284;
	sub_82217618(ctx, base);
	// stw r29,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r29.u32);
	// stw r28,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r28.u32);
	// b 0x822c4314
	goto loc_822C4314;
loc_822C4290:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// li r4,63
	ctx.r4.s64 = 63;
	// lwz r5,120(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// extsb r7,r11
	ctx.r7.s64 = r11.s8;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x822C42AC;
	sub_82137A08(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821cd7a0
	ctx.lr = 0x822C42C4;
	sub_821CD7A0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c42dc
	if (!cr6.eq) goto loc_822C42DC;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x821bd618
	ctx.lr = 0x822C42DC;
	sub_821BD618(ctx, base);
loc_822C42DC:
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821cbf28
	ctx.lr = 0x822C42E8;
	sub_821CBF28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4304
	if (!cr6.eq) goto loc_822C4304;
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821bd618
	ctx.lr = 0x822C4304;
	sub_821BD618(ctx, base);
loc_822C4304:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130000
	ctx.lr = 0x822C4314;
	sub_82130000(ctx, base);
loc_822C4314:
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821e4958
	ctx.lr = 0x822C4324;
	sub_821E4958(ctx, base);
	// addi r30,r31,160
	r30.s64 = r31.s64 + 160;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822c3520
	ctx.lr = 0x822C4334;
	sub_822C3520(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823888b8
	ctx.lr = 0x822C433C;
	sub_823888B8(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
loc_822C434C:
	// stw r26,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r26.u32);
	// mr r26,r25
	r26.u64 = r25.u64;
	// b 0x822c4360
	goto loc_822C4360;
loc_822C4358:
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x82130000
	ctx.lr = 0x822C4360;
	sub_82130000(ctx, base);
loc_822C4360:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x822C4368;
	sub_82130588(ctx, base);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c3ffc
	if (cr6.eq) goto loc_822C3FFC;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8244eee0
	ctx.lr = 0x822C437C;
	sub_8244EEE0(ctx, base);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_822C4388"))) PPC_WEAK_FUNC(sub_822C4388);
PPC_FUNC_IMPL(__imp__sub_822C4388) {
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
	ctx.lr = 0x822C4390;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r25,r28
	r25.u64 = r28.u64;
	// mr r26,r28
	r26.u64 = r28.u64;
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// mr r27,r28
	r27.u64 = r28.u64;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c4494
	if (cr6.eq) goto loc_822C4494;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_822C43BC:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c447c
	if (cr6.eq) goto loc_822C447C;
	// li r4,0
	ctx.r4.s64 = 0;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r29,r28
	r29.u64 = r28.u64;
	// bl 0x824500f8
	ctx.lr = 0x822C43E0;
	sub_824500F8(ctx, base);
	// cmplwi cr6,r3,1167
	cr6.compare<uint32_t>(ctx.r3.u32, 1167, xer);
	// bne cr6,0x822c43ec
	if (!cr6.eq) goto loc_822C43EC;
	// li r29,1
	r29.s64 = 1;
loc_822C43EC:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c447c
	if (cr6.eq) goto loc_822C447C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r9,13(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// or r26,r10,r26
	r26.u64 = ctx.r10.u64 | r26.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c4428
	if (!cr6.eq) goto loc_822C4428;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r10,14(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c4434
	if (cr6.eq) goto loc_822C4434;
loc_822C4428:
	// cmpwi cr6,r25,3
	cr6.compare<int32_t>(r25.s32, 3, xer);
	// bge cr6,0x822c4434
	if (!cr6.lt) goto loc_822C4434;
	// li r25,3
	r25.s64 = 3;
loc_822C4434:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r3,168(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// bl 0x82130588
	ctx.lr = 0x822C4444;
	sub_82130588(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// stw r28,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, r28.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r3,r9,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	// bl 0x821cbeb0
	ctx.lr = 0x822C445C;
	sub_821CBEB0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,143
	ctx.r3.s64 = r11.s64 + 143;
	// bl 0x824500e0
	ctx.lr = 0x822C4470;
	sub_824500E0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r8,r11,r30
	ctx.r8.u64 = r11.u64 + r30.u64;
	// stb r28,143(r8)
	PPC_STORE_U8(ctx.r8.u32 + 143, r28.u8);
loc_822C447C:
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,172
	r30.s64 = r30.s64 + 172;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x822c43bc
	if (cr6.lt) goto loc_822C43BC;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
loc_822C4494:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6747(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6747);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c44c8
	if (cr6.eq) goto loc_822C44C8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// bl 0x82388598
	ctx.lr = 0x822C44B0;
	sub_82388598(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x822c3ef0
	ctx.lr = 0x822C44C0;
	sub_822C3EF0(ctx, base);
	// lwz r25,80(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// or r26,r3,r26
	r26.u64 = ctx.r3.u64 | r26.u64;
loc_822C44C8:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// cmpwi cr6,r25,3
	cr6.compare<int32_t>(r25.s32, 3, xer);
	// blt cr6,0x822c4500
	if (cr6.lt) goto loc_822C4500;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-27256
	ctx.r3.s64 = r11.s64 + -27256;
	// bl 0x82130000
	ctx.lr = 0x822C44E0;
	sub_82130000(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,45
	ctx.r4.s64 = 45;
	// lwz r11,2832(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2832);
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x822C44FC;
	sub_8268EE10(ctx, base);
	// b 0x822c45c4
	goto loc_822C45C4;
loc_822C4500:
	// cmpwi cr6,r25,2
	cr6.compare<int32_t>(r25.s32, 2, xer);
	// blt cr6,0x822c4528
	if (cr6.lt) goto loc_822C4528;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-27352
	ctx.r3.s64 = r11.s64 + -27352;
	// bl 0x82130000
	ctx.lr = 0x822C4514;
	sub_82130000(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,2832(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2832);
	// stb r9,10852(r11)
	PPC_STORE_U8(r11.u32 + 10852, ctx.r9.u8);
	// b 0x822c45c4
	goto loc_822C45C4;
loc_822C4528:
	// cmpwi cr6,r25,1
	cr6.compare<int32_t>(r25.s32, 1, xer);
	// blt cr6,0x822c45c4
	if (cr6.lt) goto loc_822C45C4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-27396
	ctx.r3.s64 = r11.s64 + -27396;
	// bl 0x82130000
	ctx.lr = 0x822C453C;
	sub_82130000(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_822C4540:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213398
	ctx.lr = 0x822C4550;
	sub_82213398(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// blt cr6,0x822c4540
	if (cr6.lt) goto loc_822C4540;
	// li r31,1
	r31.s64 = 1;
	// lis r30,-32121
	r30.s64 = -2105081856;
loc_822C4564:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82217778
	ctx.lr = 0x822C4570;
	sub_82217778(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// blt cr6,0x822c4564
	if (cr6.lt) goto loc_822C4564;
	// li r31,1
	r31.s64 = 1;
loc_822C4580:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823971d0
	ctx.lr = 0x822C4588;
	sub_823971D0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// blt cr6,0x822c4580
	if (cr6.lt) goto loc_822C4580;
	// bl 0x8239c6f0
	ctx.lr = 0x822C4598;
	sub_8239C6F0(ctx, base);
	// bl 0x82373740
	ctx.lr = 0x822C459C;
	sub_82373740(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// lis r30,-32115
	r30.s64 = -2104688640;
loc_822C45A4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-12040(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12040);
	// bl 0x8239a128
	ctx.lr = 0x822C45B0;
	sub_8239A128(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// blt cr6,0x822c45a4
	if (cr6.lt) goto loc_822C45A4;
	// bl 0x82387b90
	ctx.lr = 0x822C45C0;
	sub_82387B90(ctx, base);
	// bl 0x8238c5a0
	ctx.lr = 0x822C45C4;
	sub_8238C5A0(ctx, base);
loc_822C45C4:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822c4620
	if (cr6.eq) goto loc_822C4620;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,75
	ctx.r4.s64 = 75;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r31,r11,1
	r31.s64 = r11.s64 + 65536;
	// addi r31,r31,16256
	r31.s64 = r31.s64 + 16256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822C45E8;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C45F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822c4620
	if (cr6.eq) goto loc_822C4620;
	// li r4,75
	ctx.r4.s64 = 75;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822C4610;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C4620;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C4620:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822C462C"))) PPC_WEAK_FUNC(sub_822C462C);
PPC_FUNC_IMPL(__imp__sub_822C462C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C4630"))) PPC_WEAK_FUNC(sub_822C4630);
PPC_FUNC_IMPL(__imp__sub_822C4630) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x822C4638;
	// stwu r1,-832(r1)
	ea = -832 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addis r6,r31,2
	ctx.r6.s64 = r31.s64 + 131072;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// addis r29,r31,2
	r29.s64 = r31.s64 + 131072;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// ori r7,r10,36
	ctx.r7.u64 = ctx.r10.u64 | 36;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r6,r6,40
	ctx.r6.s64 = ctx.r6.s64 + 40;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r5,r9,-27752
	ctx.r5.s64 = ctx.r9.s64 + -27752;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// ori r4,r8,48
	ctx.r4.u64 = ctx.r8.u64 | 48;
	// addi r29,r29,49
	r29.s64 = r29.s64 + 49;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r19,r11,18608
	r19.s64 = r11.s64 + 18608;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// sth r30,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r30.u16);
	// sth r30,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r30.u16);
	// li r11,97
	r11.s64 = 97;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// addi r26,r10,18648
	r26.s64 = ctx.r10.s64 + 18648;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// stw r30,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r30.u32);
	// stw r30,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r30.u32);
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
	// lwz r11,4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r31,18512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 18512, r31.u32);
	// beq cr6,0x822c46f8
	if (cr6.eq) goto loc_822C46F8;
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c46f8
	if (cr6.eq) goto loc_822C46F8;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r9,r10,24088
	ctx.r9.s64 = ctx.r10.s64 + 24088;
	// addi r11,r11,3998
	r11.s64 = r11.s64 + 3998;
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
loc_822C46F8:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x821cbea0
	ctx.lr = 0x822C4700;
	sub_821CBEA0(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-6756(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6756);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822c4718
	if (!cr6.eq) goto loc_822C4718;
	// li r11,106
	r11.s64 = 106;
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
loc_822C4718:
	// clrlwi r29,r28,24
	r29.u64 = r28.u32 & 0xFF;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r28,r11,-17856
	r28.s64 = r11.s64 + -17856;
	// bne cr6,0x822c4774
	if (!cr6.eq) goto loc_822C4774;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4748
	if (!cr6.eq) goto loc_822C4748;
	// bl 0x821d6348
	ctx.lr = 0x822C473C;
	sub_821D6348(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c4ac0
	if (cr6.eq) goto loc_822C4AC0;
loc_822C4748:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x822c4774
	if (!cr6.eq) goto loc_822C4774;
	// bl 0x821d6348
	ctx.lr = 0x822C4754;
	sub_821D6348(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4774
	if (!cr6.eq) goto loc_822C4774;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,18528
	ctx.r10.s64 = r11.s64 + 18528;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c478c
	if (cr6.eq) goto loc_822C478C;
loc_822C4774:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,18588
	ctx.r10.s64 = r11.s64 + 18588;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// beq cr6,0x822c4790
	if (cr6.eq) goto loc_822C4790;
loc_822C478C:
	// li r11,1
	r11.s64 = 1;
loc_822C4790:
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x822c4804
	if (!cr6.eq) goto loc_822C4804;
	// lwz r11,4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c47c0
	if (cr6.eq) goto loc_822C47C0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x821c3db0
	ctx.lr = 0x822C47B0;
	sub_821C3DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4804
	if (!cr6.eq) goto loc_822C4804;
	// b 0x822c4800
	goto loc_822C4800;
loc_822C47C0:
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lis r29,-16384
	r29.s64 = -1073741824;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c47d4
	if (!cr6.eq) goto loc_822C47D4;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_822C47D4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-28280
	ctx.r3.s64 = r11.s64 + -28280;
	// bl 0x823dd7f0
	ctx.lr = 0x822C47E0;
	sub_823DD7F0(ctx, base);
	// addi r7,r3,1
	ctx.r7.s64 = ctx.r3.s64 + 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82456e98
	ctx.lr = 0x822C47F8;
	sub_82456E98(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c4804
	if (cr6.eq) goto loc_822C4804;
loc_822C4800:
	// li r27,1
	r27.s64 = 1;
loc_822C4804:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c4820
	if (cr6.eq) goto loc_822C4820;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4848
	if (!cr6.eq) goto loc_822C4848;
loc_822C4820:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c4858
	if (cr6.eq) goto loc_822C4858;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,1
	r11.s64 = 1;
	// addi r4,r10,-27028
	ctx.r4.s64 = ctx.r10.s64 + -27028;
	// stb r11,-12499(r9)
	PPC_STORE_U8(ctx.r9.u32 + -12499, r11.u8);
	// b 0x822c4858
	goto loc_822C4858;
loc_822C4848:
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4858
	if (!cr6.eq) goto loc_822C4858;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
loc_822C4858:
	// li r5,511
	ctx.r5.s64 = 511;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x823db670
	ctx.lr = 0x822C4864;
	sub_823DB670(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// mr r28,r30
	r28.u64 = r30.u64;
	// stb r30,719(r1)
	PPC_STORE_U8(ctx.r1.u32 + 719, r30.u8);
	// addi r29,r1,208
	r29.s64 = ctx.r1.s64 + 208;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// clrlwi r20,r27,24
	r20.u64 = r27.u32 & 0xFF;
	// addi r21,r11,-27036
	r21.s64 = r11.s64 + -27036;
	// b 0x822c488c
	goto loc_822C488C;
loc_822C4888:
	// lwz r28,176(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
loc_822C488C:
	// li r4,59
	ctx.r4.s64 = 59;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823dd850
	ctx.lr = 0x822C4898;
	sub_823DD850(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822c48ac
	if (cr6.eq) goto loc_822C48AC;
	// stb r30,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r30.u8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_822C48AC:
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r9,r28,1
	ctx.r9.s64 = r28.s64 + 1;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// stwx r29,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, r29.u32);
	// bne cr6,0x822c4900
	if (!cr6.eq) goto loc_822C4900;
	// lwz r11,4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4900
	if (!cr6.eq) goto loc_822C4900;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d90b0
	ctx.lr = 0x822C48E0;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822c4900
	if (!cr6.eq) goto loc_822C4900;
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
loc_822C4900:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne cr6,0x822c4888
	if (!cr6.eq) goto loc_822C4888;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x822c493c
	if (!cr6.eq) goto loc_822C493C;
	// lwz r11,4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c493c
	if (!cr6.eq) goto loc_822C493C;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82454628
	ctx.lr = 0x822C493C;
	sub_82454628(ctx, base);
loc_822C493C:
	// lis r11,57
	r11.s64 = 3735552;
	// lwz r29,4(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// ori r10,r11,18790
	ctx.r10.u64 = r11.u64 | 18790;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bgt cr6,0x822c4964
	if (cr6.gt) goto loc_822C4964;
	// mulli r11,r29,1144
	r11.s64 = r29.s64 * 1144;
	// li r10,-9
	ctx.r10.s64 = -9;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x822c4968
	if (!cr6.gt) goto loc_822C4968;
loc_822C4964:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_822C4968:
	// bl 0x82130528
	ctx.lr = 0x822C496C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c49a0
	if (cr6.eq) goto loc_822C49A0;
	// addi r27,r3,8
	r27.s64 = ctx.r3.s64 + 8;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// mr r28,r27
	r28.u64 = r27.u64;
	// blt 0x822c49a4
	if (cr0.lt) goto loc_822C49A4;
loc_822C4988:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821cd750
	ctx.lr = 0x822C4990;
	sub_821CD750(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,1144
	r28.s64 = r28.s64 + 1144;
	// bge 0x822c4988
	if (!cr0.lt) goto loc_822C4988;
	// b 0x822c49a4
	goto loc_822C49A4;
loc_822C49A0:
	// mr r27,r30
	r27.u64 = r30.u64;
loc_822C49A4:
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822c4a8c
	if (!cr6.gt) goto loc_822C4A8C;
	// mr r26,r11
	r26.u64 = r11.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r29,r30
	r29.u64 = r30.u64;
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
	// addi r25,r11,-27056
	r25.s64 = r11.s64 + -27056;
	// addi r24,r10,-27580
	r24.s64 = ctx.r10.s64 + -27580;
	// addi r27,r9,-27836
	r27.s64 = ctx.r9.s64 + -27836;
	// addi r23,r8,-27456
	r23.s64 = ctx.r8.s64 + -27456;
	// addi r22,r7,-27076
	r22.s64 = ctx.r7.s64 + -27076;
loc_822C49E8:
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d90b0
	ctx.lr = 0x822C49F8;
	sub_823D90B0(ctx, base);
	// subfic r10,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r3.s64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r7,r9,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r3,r29,r11
	ctx.r3.u64 = r29.u64 + r11.u64;
	// bl 0x821cd7a0
	ctx.lr = 0x822C4A1C;
	sub_821CD7A0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822c4a44
	if (!cr6.eq) goto loc_822C4A44;
	// bl 0x82135db0
	ctx.lr = 0x822C4A2C;
	sub_82135DB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x822C4A38;
	sub_82130000(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821bd618
	ctx.lr = 0x822C4A44;
	sub_821BD618(ctx, base);
loc_822C4A44:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// add r3,r29,r11
	ctx.r3.u64 = r29.u64 + r11.u64;
	// bl 0x821cbf28
	ctx.lr = 0x822C4A54;
	sub_821CBF28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4a70
	if (!cr6.eq) goto loc_822C4A70;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821bd618
	ctx.lr = 0x822C4A70;
	sub_821BD618(ctx, base);
loc_822C4A70:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x822C4A7C;
	sub_82130000(ctx, base);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r29,r29,1144
	r29.s64 = r29.s64 + 1144;
	// bne 0x822c49e8
	if (!cr0.eq) goto loc_822C49E8;
loc_822C4A8C:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x822c4ac0
	if (!cr6.eq) goto loc_822C4AC0;
	// lwz r11,4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4ac0
	if (!cr6.eq) goto loc_822C4AC0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82452bd0
	ctx.lr = 0x822C4AA8;
	sub_82452BD0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r6,156(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// addi r3,r11,-27144
	ctx.r3.s64 = r11.s64 + -27144;
	// ld r5,144(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// lwz r4,152(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// bl 0x82130000
	ctx.lr = 0x822C4AC0;
	sub_82130000(ctx, base);
loc_822C4AC0:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x824501e0
	ctx.lr = 0x822C4AC8;
	sub_824501E0(ctx, base);
	// lis r11,2
	r11.s64 = 131072;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// ori r10,r11,52
	ctx.r10.u64 = r11.u64 | 52;
	// stwx r3,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// beq cr6,0x822c4ae4
	if (cr6.eq) goto loc_822C4AE4;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x822c4af0
	if (!cr6.eq) goto loc_822C4AF0;
loc_822C4AE4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-27196
	ctx.r3.s64 = r11.s64 + -27196;
	// bl 0x821bd618
	ctx.lr = 0x822C4AF0;
	sub_821BD618(ctx, base);
loc_822C4AF0:
	// li r11,4
	r11.s64 = 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82387860
	ctx.lr = 0x822C4AFC;
	sub_82387860(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// beq cr6,0x822c4b18
	if (cr6.eq) goto loc_822C4B18;
	// bl 0x82387860
	ctx.lr = 0x822C4B0C;
	sub_82387860(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822c4b40
	if (!cr6.eq) goto loc_822C4B40;
loc_822C4B18:
	// bl 0x82387860
	ctx.lr = 0x822C4B1C;
	sub_82387860(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822c4b40
	if (cr6.lt) goto loc_822C4B40;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// bl 0x82387860
	ctx.lr = 0x822C4B30;
	sub_82387860(ctx, base);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x822c3ef0
	ctx.lr = 0x822C4B40;
	sub_822C3EF0(ctx, base);
loc_822C4B40:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-28304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28304);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// beq cr6,0x822c4b70
	if (cr6.eq) goto loc_822C4B70;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r11,r11,-27200
	r11.s64 = r11.s64 + -27200;
	// stw r11,-27856(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27856, r11.u32);
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d9224
	return;
loc_822C4B70:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r11,r11,-27204
	r11.s64 = r11.s64 + -27204;
	// stw r11,-27856(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27856, r11.u32);
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822C4B84"))) PPC_WEAK_FUNC(sub_822C4B84);
PPC_FUNC_IMPL(__imp__sub_822C4B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C4B88"))) PPC_WEAK_FUNC(sub_822C4B88);
PPC_FUNC_IMPL(__imp__sub_822C4B88) {
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
	// bl 0x822c3d88
	ctx.lr = 0x822C4BA8;
	sub_822C3D88(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c4bc0
	if (cr6.eq) goto loc_822C4BC0;
	// bl 0x82130588
	ctx.lr = 0x822C4BBC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822C4BC0:
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

__attribute__((alias("__imp__sub_822C4BD8"))) PPC_WEAK_FUNC(sub_822C4BD8);
PPC_FUNC_IMPL(__imp__sub_822C4BD8) {
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
	ctx.lr = 0x822C4BE0;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// lis r11,2
	r11.s64 = 131072;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r10,r11,52
	ctx.r10.u64 = r11.u64 | 52;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// bl 0x827bd054
	ctx.lr = 0x822C4C0C;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822c4c28
	if (cr6.eq) goto loc_822C4C28;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// bne cr6,0x822c4c28
	if (!cr6.eq) goto loc_822C4C28;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c4388
	ctx.lr = 0x822C4C28;
	sub_822C4388(ctx, base);
loc_822C4C28:
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,40
	r30.s64 = r30.s64 + 40;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x822c4d5c
	if (!cr6.eq) goto loc_822C4D5C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x822C4C48;
	sub_821CE080(ctx, base);
	// lis r11,2
	r11.s64 = 131072;
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// ori r10,r11,36
	ctx.r10.u64 = r11.u64 | 36;
	// lwzx r6,r31,r10
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822c4d5c
	if (cr6.eq) goto loc_822C4D5C;
	// lis r11,2
	r11.s64 = 131072;
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// bgt cr6,0x822c4d5c
	if (cr6.gt) goto loc_822C4D5C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r11,-26836
	ctx.r8.s64 = r11.s64 + -26836;
	// addi r5,r31,36
	ctx.r5.s64 = r31.s64 + 36;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cb740
	ctx.lr = 0x822C4C88;
	sub_821CB740(ctx, base);
	// li r3,1144
	ctx.r3.s64 = 1144;
	// bl 0x82130528
	ctx.lr = 0x822C4C90;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c4ca0
	if (cr6.eq) goto loc_822C4CA0;
	// bl 0x821cd750
	ctx.lr = 0x822C4C9C;
	sub_821CD750(ctx, base);
	// b 0x822c4ca4
	goto loc_822C4CA4;
loc_822C4CA0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822C4CA4:
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821cd7a0
	ctx.lr = 0x822C4CBC;
	sub_821CD7A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4cdc
	if (!cr6.eq) goto loc_822C4CDC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,-27456
	ctx.r3.s64 = r11.s64 + -27456;
	// bl 0x821bd618
	ctx.lr = 0x822C4CD8;
	sub_821BD618(ctx, base);
	// b 0x822c4d5c
	goto loc_822C4D5C;
loc_822C4CDC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r11,-27836
	ctx.r4.s64 = r11.s64 + -27836;
	// bl 0x821cbf28
	ctx.lr = 0x822C4CEC;
	sub_821CBF28(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c4d08
	if (!cr6.eq) goto loc_822C4D08;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-26904
	ctx.r3.s64 = r11.s64 + -26904;
	// bl 0x82130000
	ctx.lr = 0x822C4D04;
	sub_82130000(ctx, base);
	// b 0x822c4d5c
	goto loc_822C4D5C;
loc_822C4D08:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-26928
	ctx.r4.s64 = ctx.r10.s64 + -26928;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82217618
	ctx.lr = 0x822C4D1C;
	sub_82217618(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r9,-26952
	ctx.r3.s64 = ctx.r9.s64 + -26952;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x822C4D3C;
	sub_82727908(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r7,-26976
	ctx.r3.s64 = ctx.r7.s64 + -26976;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x822C4D5C;
	sub_82727908(ctx, base);
loc_822C4D5C:
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,48
	r30.s64 = r30.s64 + 48;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c4db0
	if (!cr6.eq) goto loc_822C4DB0;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6747(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6747);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c4db0
	if (cr6.eq) goto loc_822C4DB0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822C4D88;
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
	ctx.lr = 0x822C4D9C;
	sub_82270170(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c3620
	ctx.lr = 0x822C4DA8;
	sub_822C3620(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r9.u8);
loc_822C4DB0:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C4DB8"))) PPC_WEAK_FUNC(sub_822C4DB8);
PPC_FUNC_IMPL(__imp__sub_822C4DB8) {
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
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r11,-26400
	ctx.r9.s64 = r11.s64 + -26400;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r4,r10,2600
	ctx.r4.s64 = ctx.r10.s64 + 2600;
	// addi r3,r8,18692
	ctx.r3.s64 = ctx.r8.s64 + 18692;
	// bl 0x821c0750
	ctx.lr = 0x822C4DEC;
	sub_821C0750(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// addi r4,r7,2604
	ctx.r4.s64 = ctx.r7.s64 + 2604;
	// addi r3,r6,18672
	ctx.r3.s64 = ctx.r6.s64 + 18672;
	// bl 0x821c0750
	ctx.lr = 0x822C4E00;
	sub_821C0750(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// li r5,44
	ctx.r5.s64 = 44;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x822C4E10;
	sub_823D9890(ctx, base);
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

__attribute__((alias("__imp__sub_822C4E28"))) PPC_WEAK_FUNC(sub_822C4E28);
PPC_FUNC_IMPL(__imp__sub_822C4E28) {
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x822C4E3C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c4e4c
	if (cr6.eq) goto loc_822C4E4C;
	// bl 0x822c4db8
	ctx.lr = 0x822C4E48;
	sub_822C4DB8(ctx, base);
	// b 0x822c4e50
	goto loc_822C4E50;
loc_822C4E4C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C4E50:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,18668(r11)
	PPC_STORE_U32(r11.u32 + 18668, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C4E68"))) PPC_WEAK_FUNC(sub_822C4E68);
PPC_FUNC_IMPL(__imp__sub_822C4E68) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,18668(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18668);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c4e9c
	if (cr6.eq) goto loc_822C4E9C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C4E9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C4E9C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,18668(r31)
	PPC_STORE_U32(r31.u32 + 18668, r11.u32);
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

__attribute__((alias("__imp__sub_822C4EB8"))) PPC_WEAK_FUNC(sub_822C4EB8);
PPC_FUNC_IMPL(__imp__sub_822C4EB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18668(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18668);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C4EC4"))) PPC_WEAK_FUNC(sub_822C4EC4);
PPC_FUNC_IMPL(__imp__sub_822C4EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C4EC8"))) PPC_WEAK_FUNC(sub_822C4EC8);
PPC_FUNC_IMPL(__imp__sub_822C4EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C4ED8"))) PPC_WEAK_FUNC(sub_822C4ED8);
PPC_FUNC_IMPL(__imp__sub_822C4ED8) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822C4F00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r7,-26396
	ctx.r3.s64 = ctx.r7.s64 + -26396;
	// bl 0x82130000
	ctx.lr = 0x822C4F10;
	sub_82130000(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C4F20"))) PPC_WEAK_FUNC(sub_822C4F20);
PPC_FUNC_IMPL(__imp__sub_822C4F20) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C4F54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r8,-26372
	ctx.r3.s64 = ctx.r8.s64 + -26372;
	// bl 0x82130000
	ctx.lr = 0x822C4F64;
	sub_82130000(ctx, base);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x82130000
	ctx.lr = 0x822C4F6C;
	sub_82130000(ctx, base);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c4f98
	if (cr6.eq) goto loc_822C4F98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C4F8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// b 0x822c4fa0
	goto loc_822C4FA0;
loc_822C4F98:
	// li r11,0
	r11.s64 = 0;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
loc_822C4FA0:
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

__attribute__((alias("__imp__sub_822C4FB8"))) PPC_WEAK_FUNC(sub_822C4FB8);
PPC_FUNC_IMPL(__imp__sub_822C4FB8) {
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
	ctx.lr = 0x822C4FD0;
	sub_822D2D00(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-26348
	ctx.r9.s64 = ctx.r10.s64 + -26348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r11.u8);
	// stb r11,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r11.u8);
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

__attribute__((alias("__imp__sub_822C5000"))) PPC_WEAK_FUNC(sub_822C5000);
PPC_FUNC_IMPL(__imp__sub_822C5000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-26300
	ctx.r3.s64 = r11.s64 + -26300;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C500C"))) PPC_WEAK_FUNC(sub_822C500C);
PPC_FUNC_IMPL(__imp__sub_822C500C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C5010"))) PPC_WEAK_FUNC(sub_822C5010);
PPC_FUNC_IMPL(__imp__sub_822C5010) {
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
	// addi r10,r11,-26348
	ctx.r10.s64 = r11.s64 + -26348;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822d2bb8
	ctx.lr = 0x822C503C;
	sub_822D2BB8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c5054
	if (cr6.eq) goto loc_822C5054;
	// bl 0x82130588
	ctx.lr = 0x822C5050;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822C5054:
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

__attribute__((alias("__imp__sub_822C506C"))) PPC_WEAK_FUNC(sub_822C506C);
PPC_FUNC_IMPL(__imp__sub_822C506C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C5070"))) PPC_WEAK_FUNC(sub_822C5070);
PPC_FUNC_IMPL(__imp__sub_822C5070) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822C5078;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822c50b8
	if (cr6.eq) goto loc_822C50B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C50A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-26288
	ctx.r3.s64 = ctx.r9.s64 + -26288;
	// bl 0x821bd618
	ctx.lr = 0x822C50B8;
	sub_821BD618(ctx, base);
loc_822C50B8:
	// cmplwi cr6,r31,8
	cr6.compare<uint32_t>(r31.u32, 8, xer);
	// bgt cr6,0x822c51a4
	if (cr6.gt) goto loc_822C51A4;
	// lis r12,-32212
	r12.s64 = -2111045632;
	// addi r12,r12,20696
	r12.s64 = r12.s64 + 20696;
	// rlwinm r0,r31,2,0,29
	r0.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r31.u64) {
	case 0:
		goto loc_822C50FC;
	case 1:
		goto loc_822C511C;
	case 2:
		goto loc_822C515C;
	case 3:
		goto loc_822C51A4;
	case 4:
		goto loc_822C513C;
	case 5:
		goto loc_822C51A4;
	case 6:
		goto loc_822C51A4;
	case 7:
		goto loc_822C51A4;
	case 8:
		goto loc_822C517C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,20732(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20732);
	// lwz r17,20764(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20764);
	// lwz r17,20828(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20828);
	// lwz r17,20900(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20900);
	// lwz r17,20796(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20796);
	// lwz r17,20900(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20900);
	// lwz r17,20900(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20900);
	// lwz r17,20900(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20900);
	// lwz r17,20860(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 20860);
loc_822C50FC:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x822C5104;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c519c
	if (cr6.eq) goto loc_822C519C;
	// bl 0x822d3e20
	ctx.lr = 0x822C5110;
	sub_822D3E20(ctx, base);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822C511C:
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x822C5124;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c519c
	if (cr6.eq) goto loc_822C519C;
	// bl 0x822c74a0
	ctx.lr = 0x822C5130;
	sub_822C74A0(ctx, base);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822C513C:
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x822C5144;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c519c
	if (cr6.eq) goto loc_822C519C;
	// bl 0x822cba38
	ctx.lr = 0x822C5150;
	sub_822CBA38(ctx, base);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822C515C:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x822C5164;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c519c
	if (cr6.eq) goto loc_822C519C;
	// bl 0x822d3978
	ctx.lr = 0x822C5170;
	sub_822D3978(ctx, base);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822C517C:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x822C5184;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c519c
	if (cr6.eq) goto loc_822C519C;
	// bl 0x822c4fb8
	ctx.lr = 0x822C5190;
	sub_822C4FB8(ctx, base);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822C519C:
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
loc_822C51A4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C51AC"))) PPC_WEAK_FUNC(sub_822C51AC);
PPC_FUNC_IMPL(__imp__sub_822C51AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C51B0"))) PPC_WEAK_FUNC(sub_822C51B0);
PPC_FUNC_IMPL(__imp__sub_822C51B0) {
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C51E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r8,-26244
	ctx.r3.s64 = ctx.r8.s64 + -26244;
	// bl 0x82130000
	ctx.lr = 0x822C51F4;
	sub_82130000(ctx, base);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x82130000
	ctx.lr = 0x822C51FC;
	sub_82130000(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lwz r11,2600(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2600);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x822c5210
	if (cr6.lt) goto loc_822C5210;
	// bl 0x825f0110
	ctx.lr = 0x822C5210;
	sub_825F0110(ctx, base);
loc_822C5210:
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C5224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r9,-26256
	ctx.r5.s64 = ctx.r9.s64 + -26256;
	// li r4,255
	ctx.r4.s64 = 255;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822C523C;
	sub_82137A08(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

__attribute__((alias("__imp__sub_822C5254"))) PPC_WEAK_FUNC(sub_822C5254);
PPC_FUNC_IMPL(__imp__sub_822C5254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C5258"))) PPC_WEAK_FUNC(sub_822C5258);
PPC_FUNC_IMPL(__imp__sub_822C5258) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C528C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822c52ac
	if (cr6.eq) goto loc_822C52AC;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C52AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C52AC:
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

__attribute__((alias("__imp__sub_822C52C4"))) PPC_WEAK_FUNC(sub_822C52C4);
PPC_FUNC_IMPL(__imp__sub_822C52C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C52C8"))) PPC_WEAK_FUNC(sub_822C52C8);
PPC_FUNC_IMPL(__imp__sub_822C52C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C5304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822c5328
	if (cr6.eq) goto loc_822C5328;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C5328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C5328:
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

__attribute__((alias("__imp__sub_822C5344"))) PPC_WEAK_FUNC(sub_822C5344);
PPC_FUNC_IMPL(__imp__sub_822C5344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C5348"))) PPC_WEAK_FUNC(sub_822C5348);
PPC_FUNC_IMPL(__imp__sub_822C5348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C5384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822c53a8
	if (cr6.eq) goto loc_822C53A8;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C53A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C53A8:
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

__attribute__((alias("__imp__sub_822C53C4"))) PPC_WEAK_FUNC(sub_822C53C4);
PPC_FUNC_IMPL(__imp__sub_822C53C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C53C8"))) PPC_WEAK_FUNC(sub_822C53C8);
PPC_FUNC_IMPL(__imp__sub_822C53C8) {
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
	ctx.lr = 0x822C53D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C53F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822c541c
	if (cr6.eq) goto loc_822C541C;
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C541C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C541C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C5424"))) PPC_WEAK_FUNC(sub_822C5424);
PPC_FUNC_IMPL(__imp__sub_822C5424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C5428"))) PPC_WEAK_FUNC(sub_822C5428);
PPC_FUNC_IMPL(__imp__sub_822C5428) {
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
	ctx.lr = 0x822C5430;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,10
	r30.s64 = 10;
	// cmpwi cr6,r27,10
	cr6.compare<int32_t>(r27.s32, 10, xer);
	// bgt cr6,0x822c54d0
	if (cr6.gt) goto loc_822C54D0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r31,r29,44
	r31.s64 = r29.s64 + 44;
	// addi r28,r11,-26396
	r28.s64 = r11.s64 + -26396;
loc_822C5454:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c54c0
	if (cr6.eq) goto loc_822C54C0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C5474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c54c0
	if (cr6.eq) goto loc_822C54C0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C5494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x822C54A0;
	sub_82130000(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822C54B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822c4f20
	ctx.lr = 0x822C54C0;
	sub_822C4F20(ctx, base);
loc_822C54C0:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// bge cr6,0x822c5454
	if (!cr6.lt) goto loc_822C5454;
loc_822C54D0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822C54D8"))) PPC_WEAK_FUNC(sub_822C54D8);
PPC_FUNC_IMPL(__imp__sub_822C54D8) {
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
	ctx.lr = 0x822C54E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822c550c
	if (!cr6.eq) goto loc_822C550C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-26224
	ctx.r3.s64 = r11.s64 + -26224;
	// bl 0x821bd618
	ctx.lr = 0x822C550C;
	sub_821BD618(ctx, base);
loc_822C550C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c51b0
	ctx.lr = 0x822C5518;
	sub_822C51B0(ctx, base);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C552C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822C5540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822C5548"))) PPC_WEAK_FUNC(sub_822C5548);
PPC_FUNC_IMPL(__imp__sub_822C5548) {
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
	// addi r10,r11,-26400
	ctx.r10.s64 = r11.s64 + -26400;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822c5428
	ctx.lr = 0x822C5578;
	sub_822C5428(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822C5580;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c5598
	if (cr6.eq) goto loc_822C5598;
	// bl 0x82130588
	ctx.lr = 0x822C5594;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822C5598:
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

__attribute__((alias("__imp__sub_822C55B0"))) PPC_WEAK_FUNC(sub_822C55B0);
PPC_FUNC_IMPL(__imp__sub_822C55B0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82256058
	ctx.lr = 0x822C55C0;
	sub_82256058(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,17,17
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	// beq cr6,0x822c5618
	if (cr6.eq) goto loc_822C5618;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822c562c
	if (!cr6.eq) goto loc_822C562C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// addi r8,r10,0
	ctx.r8.s64 = ctx.r10.s64 + 0;
	// addi r7,r7,0
	ctx.r7.s64 = ctx.r7.s64 + 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,14
	ctx.r4.s64 = 14;
	// bl 0x821ed368
	ctx.lr = 0x822C5608;
	sub_821ED368(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822C5618:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c562c
	if (cr6.eq) goto loc_822C562C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,14
	ctx.r4.s64 = 14;
	// bl 0x821ec468
	ctx.lr = 0x822C562C;
	sub_821EC468(ctx, base);
loc_822C562C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C563C"))) PPC_WEAK_FUNC(sub_822C563C);
PPC_FUNC_IMPL(__imp__sub_822C563C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C5640"))) PPC_WEAK_FUNC(sub_822C5640);
PPC_FUNC_IMPL(__imp__sub_822C5640) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,2432(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2432);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822c5670
	if (!cr6.gt) goto loc_822C5670;
	// addi r11,r3,1664
	r11.s64 = ctx.r3.s64 + 1664;
loc_822C5654:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r4,r8
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, xer);
	// beq cr6,0x822c5678
	if (cr6.eq) goto loc_822C5678;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x822c5654
	if (cr6.lt) goto loc_822C5654;
loc_822C5670:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_822C5678:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C5680"))) PPC_WEAK_FUNC(sub_822C5680);
PPC_FUNC_IMPL(__imp__sub_822C5680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	PPCRegister f31{};
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
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x822C5688;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd524
	ctx.lr = 0x822C5694;
	// stwu r1,-1536(r1)
	ea = -1536 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x822c60f4
	if (cr6.gt) goto loc_822C60F4;
	// lis r12,-32212
	r12.s64 = -2111045632;
	// addi r12,r12,22224
	r12.s64 = r12.s64 + 22224;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822C5704;
	case 1:
		goto loc_822C5704;
	case 2:
		goto loc_822C60F4;
	case 3:
		goto loc_822C5704;
	case 4:
		goto loc_822C5718;
	case 5:
		goto loc_822C5718;
	case 6:
		goto loc_822C60F4;
	case 7:
		goto loc_822C60F4;
	case 8:
		goto loc_822C5E50;
	case 9:
		goto loc_822C60F4;
	case 10:
		goto loc_822C5780;
	case 11:
		goto loc_822C60F4;
	case 12:
		goto loc_822C5FAC;
	default:
		__builtin_unreachable();
	}
	// lwz r17,22276(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 22276);
	// lwz r17,22276(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 22276);
	// lwz r17,24820(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 24820);
	// lwz r17,22276(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 22276);
	// lwz r17,22296(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 22296);
	// lwz r17,22296(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 22296);
	// lwz r17,24820(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 24820);
	// lwz r17,24820(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 24820);
	// lwz r17,24144(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 24144);
	// lwz r17,24820(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 24820);
	// lwz r17,22400(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 22400);
	// lwz r17,24820(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 24820);
	// lwz r17,24492(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 24492);
loc_822C5704:
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578e08
	ctx.lr = 0x822C5714;
	sub_82578E08(ctx, base);
	// b 0x822c60f4
	goto loc_822C60F4;
loc_822C5718:
	// lwz r27,204(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 204);
	// li r28,0
	r28.s64 = 0;
	// lwz r26,128(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// mr r30,r28
	r30.u64 = r28.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x822c5760
	if (!cr6.gt) goto loc_822C5760;
loc_822C5730:
	// sth r30,60(r31)
	PPC_STORE_U16(r31.u32 + 60, r30.u16);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r11,140(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// bl 0x82579490
	ctx.lr = 0x822C5750;
	sub_82579490(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,16
	r28.s64 = r28.s64 + 16;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x822c5730
	if (cr6.lt) goto loc_822C5730;
loc_822C5760:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bne cr6,0x822c60f4
	if (!cr6.eq) goto loc_822C60F4;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578e08
	ctx.lr = 0x822C577C;
	sub_82578E08(ctx, base);
	// b 0x822c60f4
	goto loc_822C60F4;
loc_822C5780:
	// lwz r11,176(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822c60f4
	if (cr6.eq) goto loc_822C60F4;
	// lbz r11,2436(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c57a8
	if (cr6.eq) goto loc_822C57A8;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x822c57a8
	if (cr6.eq) goto loc_822C57A8;
	// lhz r6,8(r19)
	ctx.r6.u64 = PPC_LOAD_U16(r19.u32 + 8);
	// b 0x822c57ac
	goto loc_822C57AC;
loc_822C57A8:
	// li r6,-1
	ctx.r6.s64 = -1;
loc_822C57AC:
	// addi r23,r31,176
	r23.s64 = r31.s64 + 176;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575e78
	ctx.lr = 0x822C57C0;
	sub_82575E78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822c5834
	if (cr6.eq) goto loc_822C5834;
loc_822C57CC:
	// lbz r11,2456(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2456);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c5834
	if (cr6.eq) goto loc_822C5834;
	// lwz r3,2448(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2448);
	// lwz r11,2452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c57fc
	if (cr6.eq) goto loc_822C57FC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822C57F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c580c
	goto loc_822C580C;
loc_822C57FC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822C580C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C580C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c5834
	if (!cr6.eq) goto loc_822C5834;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575f90
	ctx.lr = 0x822C5828;
	sub_82575F90(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x822c57cc
	if (!cr6.eq) goto loc_822C57CC;
loc_822C5834:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r28,0
	r28.s64 = 0;
	// lbz r10,-23460(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23460);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c586c
	if (!cr6.eq) goto loc_822C586C;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r11,r1,106
	r11.s64 = ctx.r1.s64 + 106;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
loc_822C5858:
	// sth r28,-6(r11)
	PPC_STORE_U16(r11.u32 + -6, r28.u16);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r9,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r9.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x822c5858
	if (!cr0.eq) goto loc_822C5858;
loc_822C586C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822c60f4
	if (cr6.eq) goto loc_822C60F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r26,1
	r26.s64 = 1;
	// li r27,2
	r27.s64 = 2;
	// li r25,4
	r25.s64 = 4;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_822C5888:
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c58f8
	if (!cr6.eq) goto loc_822C58F8;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82204be0
	ctx.lr = 0x822C58AC;
	sub_82204BE0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// sth r28,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r28.u16);
	// sth r26,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r26.u16);
	// sth r27,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, r27.u16);
	// bl 0x82579490
	ctx.lr = 0x822C58F4;
	sub_82579490(ctx, base);
	// b 0x822c5de4
	goto loc_822C5DE4;
loc_822C58F8:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822c59b0
	if (!cr6.eq) goto loc_822C59B0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82582c08
	ctx.lr = 0x822C590C;
	sub_82582C08(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// bl 0x822030e0
	ctx.lr = 0x822C591C;
	sub_822030E0(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
	// vupkd3d128 v61,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v61 = vTemp;
	// addi r7,r1,352
	ctx.r7.s64 = ctx.r1.s64 + 352;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vpermwi128 v60,v61,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// vpermwi128 v59,v61,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v58,v61,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82575cc0
	ctx.lr = 0x822C5960;
	sub_82575CC0(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578e08
	ctx.lr = 0x822C5970;
	sub_82578E08(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822c598c
	if (cr6.eq) goto loc_822C598C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x822C598C;
	sub_8257DC50(ctx, base);
loc_822C598C:
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575d40
	ctx.lr = 0x822C5998;
	sub_82575D40(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82582fd0
	ctx.lr = 0x822C59A4;
	sub_82582FD0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x825824f8
	ctx.lr = 0x822C59AC;
	sub_825824F8(ctx, base);
	// b 0x822c5de4
	goto loc_822C5DE4;
loc_822C59B0:
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x822c5b7c
	if (!cr6.eq) goto loc_822C5B7C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lhz r24,8(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x822030e0
	ctx.lr = 0x822C59CC;
	sub_822030E0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// lvx128 v125,r0,r10
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822030e0
	ctx.lr = 0x822C59E4;
	sub_822030E0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// lvx128 v124,r0,r9
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v127,v124,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v125.f32)));
	// bl 0x825822f0
	ctx.lr = 0x822C59F8;
	sub_825822F0(ctx, base);
	// vmsum3fp128 v126,v127,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v126.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v127.f32), 0xEF));
	// lvlx128 v56,r30,r25
	temp.u32 = r30.u32 + r25.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// vspltw128 v1,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vrsqrtefp128 v57,v126
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// vrefp128 v2,v57
	simde_mm_store_ps(ctx.v2.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v57.f32)));
	// bl 0x82581500
	ctx.lr = 0x822C5A14;
	sub_82581500(ctx, base);
	// vspltisw128 v55,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_set1_epi32(int(0x0)));
	// vor128 v0,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vspltisw128 v54,-1
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// vor128 v13,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vupkd3d128 v63,v55,4
	temp.f32 = 3.0f;
	temp.s32 += v55.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v55.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v63 = vTemp;
	// vor128 v12,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vpermwi128 v53,v55,24
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xE7));
	// vrlimi128 v13,v54,4,0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_permute_ps(simde_mm_load_ps(v54.f32), 228), 4));
	// vpermwi128 v52,v63,234
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// vpermwi128 v51,v63,186
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v50,v63,174
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// vsel v11,v0,v12,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// stvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v49,v11,24
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v11.u32), 0xE7));
	// stvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v48,v49,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v53.f32)));
	cr6.setFromMask(simde_mm_load_ps(v48.f32), 0xF);
	// mfocrf r5,2
	ctx.r5.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r4,r5,0,24,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822c5b08
	if (!cr6.eq) goto loc_822C5B08;
	// vpermwi128 v47,v63,187
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x44));
	// vrsqrtefp128 v0,v126
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// vpermwi128 v46,v127,99
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// vor128 v12,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vpermwi128 v11,v127,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// vspltisw128 v45,1
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// vpermwi128 v44,v47,135
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x78));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// vpermwi128 v10,v47,99
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x9C));
	// vspltw128 v13,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vcuxwfp128 v43,v45,1
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v45.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vmulfp128 v9,v46,v44
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v44.f32)));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v43,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v11,v10,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v5,v12,v8,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v42,v6,v6
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v6.f32), 0xEF));
	// vmaddfp v4,v5,v7,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vrsqrtefp128 v0,v42
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v42.f32))));
	// vor128 v3,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// vmulfp128 v63,v127,v4
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vmulfp128 v1,v0,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v31,v43,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vpermwi128 v41,v63,135
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v2,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v30,v3,v1,v13
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v29,v30,v31,v0
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v63,v6,v29
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(v29.f32)));
	// vpermwi128 v40,v63,99
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v28,v63,135
	simde_mm_store_si128((simde__m128i*)v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmulfp128 v27,v40,v41
	simde_mm_store_ps(v27.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v41.f32)));
	// vnmsubfp v26,v28,v2,v27
	simde_mm_store_ps(v26.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v27.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v26,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822C5B08:
	// vspltisw128 v39,1
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_set1_epi32(int(0x1)));
	// vaddfp128 v38,v125,v124
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v38.f32, simde_mm_add_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v124.f32)));
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vcuxwfp128 v37,v39,1
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v39.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vmulfp128 v36,v38,v37
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v37.f32)));
	// stvx128 v36,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82575cc0
	ctx.lr = 0x822C5B2C;
	sub_82575CC0(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578e08
	ctx.lr = 0x822C5B3C;
	sub_82578E08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c5b58
	if (cr6.eq) goto loc_822C5B58;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x822C5B58;
	sub_8257DC50(ctx, base);
loc_822C5B58:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575d40
	ctx.lr = 0x822C5B64;
	sub_82575D40(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82582fd0
	ctx.lr = 0x822C5B70;
	sub_82582FD0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82581548
	ctx.lr = 0x822C5B78;
	sub_82581548(ctx, base);
	// b 0x822c5de4
	goto loc_822C5DE4;
loc_822C5B7C:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x822c5de4
	if (!cr6.eq) goto loc_822C5DE4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lhz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// lhz r24,6(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r22,8(r30)
	r22.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// lhz r30,10(r30)
	r30.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// bl 0x822030e0
	ctx.lr = 0x822C5BA0;
	sub_822030E0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822030e0
	ctx.lr = 0x822C5BB8;
	sub_822030E0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// lvx128 v125,r0,r9
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822030e0
	ctx.lr = 0x822C5BD0;
	sub_822030E0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// lvx128 v124,r0,r8
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822030e0
	ctx.lr = 0x822C5BE8;
	sub_822030E0(ctx, base);
	// lvx128 v35,r0,r3
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v34,1
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_set1_epi32(int(0x1)));
	// vaddfp128 v33,v125,v35
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v33.f32, simde_mm_add_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v35.f32)));
	// vspltisw128 v123,0
	simde_mm_store_si128((simde__m128i*)v123.u32, simde_mm_set1_epi32(int(0x0)));
	// vaddfp128 v32,v126,v35
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v35.f32)));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// vaddfp128 v63,v124,v35
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v35.f32)));
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// vcuxwfp128 v122,v34,1
	simde_mm_store_ps(v122.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v34.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// vaddfp128 v61,v126,v125
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v125.f32)));
	// vupkd3d128 v62,v123,4
	temp.f32 = 3.0f;
	temp.s32 += v123.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v123.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// vspltw128 v127,v62,3
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x0));
	// vsubfp128 v60,v33,v126
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v126.f32)));
	// vor128 v11,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vsubfp128 v59,v32,v125
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v125.f32)));
	// vor128 v10,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vsubfp128 v58,v63,v126
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v126.f32)));
	// vor128 v9,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vor128 v57,v122,v122
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_load_si128((simde__m128i*)v122.u8));
	// vaddfp128 v56,v61,v124
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v124.f32)));
	// vmulfp128 v40,v57,v57
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32)));
	// vsubfp128 v55,v60,v124
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v124.f32)));
	// vsubfp128 v54,v59,v124
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v124.f32)));
	// vsubfp128 v53,v58,v125
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v125.f32)));
	// vaddfp128 v52,v56,v35
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v35.f32)));
	// vmulfp128 v51,v57,v55
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v55.f32)));
	// vmulfp128 v50,v57,v54
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v54.f32)));
	// vmulfp128 v49,v57,v53
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v53.f32)));
	// vmsum3fp128 v126,v51,v51
	simde_mm_store_ps(v126.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmsum3fp128 v125,v50,v50
	simde_mm_store_ps(v125.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vmsum3fp128 v124,v49,v49
	simde_mm_store_ps(v124.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vrsqrtefp128 v0,v126
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// vor128 v48,v126,v126
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vrsqrtefp128 v13,v125
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v125.f32))));
	// vor128 v47,v125,v125
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// vrsqrtefp128 v12,v124
	simde_mm_store_ps(ctx.v12.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v124.f32))));
	// vor128 v46,v124,v124
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// vmulfp128 v45,v0,v0
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v44,v13,v13
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v8,v122,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v122,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v43,v12,v12
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v6,v122,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vnmsubfp128 v11,v48,v45,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v45.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v10,v47,v44,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v44.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v9,v46,v43,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v43.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v11,v8,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v4,v10,v7,v13
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v3,v9,v6,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v42,v51,v5
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v5.f32)));
	// vmulfp128 v41,v50,v4
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vmulfp128 v39,v49,v3
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(ctx.v3.f32)));
	// stvx128 v42,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v38,v40,v52
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v52.f32)));
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// stvx128 v39,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825807e0
	ctx.lr = 0x822C5CEC;
	sub_825807E0(ctx, base);
	// vrsqrtefp128 v0,v124
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v124.f32))));
	// vrsqrtefp128 v13,v126
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// vor128 v37,v124,v124
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// vrsqrtefp128 v12,v125
	simde_mm_store_ps(ctx.v12.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v125.f32))));
	// vor128 v36,v126,v126
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vor128 v2,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vcmpeqfp128 v1,v124,v123
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v123.f32)));
	// vor128 v31,v127,v127
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// vcmpeqfp128 v30,v126,v123
	simde_mm_store_ps(v30.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v123.f32)));
	// vor128 v35,v125,v125
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// vcmpeqfp128 v29,v125,v123
	simde_mm_store_ps(v29.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v123.f32)));
	// vor128 v28,v127,v127
	simde_mm_store_si128((simde__m128i*)v28.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// vor128 v27,v123,v123
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// vor128 v26,v123,v123
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// vor128 v25,v123,v123
	simde_mm_store_si128((simde__m128i*)v25.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// vmulfp128 v34,v0,v0
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v33,v13,v13
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v32,v12,v12
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v24,v122,v0
	simde_mm_store_ps(v24.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v23,v122,v13
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v22,v122,v12
	simde_mm_store_ps(v22.f32, simde_mm_mul_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vnmsubfp128 v2,v37,v34,v2
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v34.f32)), simde_mm_load_ps(ctx.v2.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v31,v36,v33,v31
	simde_mm_store_ps(v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v33.f32)), simde_mm_load_ps(v31.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v28,v35,v32,v28
	simde_mm_store_ps(v28.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v32.f32)), simde_mm_load_ps(v28.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v21,v2,v24,v0
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v24.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v20,v31,v23,v13
	simde_mm_store_ps(v20.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v23.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v19,v28,v22,v12
	simde_mm_store_ps(v19.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(v22.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v18,v124,v21
	simde_mm_store_ps(v18.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v21.f32)));
	// vmulfp128 v17,v126,v20
	simde_mm_store_ps(v17.f32, simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v20.f32)));
	// vmulfp128 v16,v125,v19
	simde_mm_store_ps(v16.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v19.f32)));
	// vsel v15,v18,v27,v1
	simde_mm_store_si128((simde__m128i*)v15.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v27.u8))));
	// vsel v14,v17,v26,v30
	simde_mm_store_si128((simde__m128i*)v14.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)v17.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)v26.u8))));
	// vsel v0,v16,v25,v29
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)v16.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)v25.u8))));
	// vmrghw128 v63,v14,v15
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v15.u32), simde_mm_load_si128((simde__m128i*)v14.u32)));
	// vmrghw128 v62,v63,v0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82580018
	ctx.lr = 0x822C5D8C;
	sub_82580018(ctx, base);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575cc0
	ctx.lr = 0x822C5D98;
	sub_82575CC0(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,752
	ctx.r4.s64 = ctx.r1.s64 + 752;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578e08
	ctx.lr = 0x822C5DA8;
	sub_82578E08(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c5dc4
	if (cr6.eq) goto loc_822C5DC4;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x822C5DC4;
	sub_8257DC50(ctx, base);
loc_822C5DC4:
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575d40
	ctx.lr = 0x822C5DD0;
	sub_82575D40(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x82582fd0
	ctx.lr = 0x822C5DDC;
	sub_82582FD0(ctx, base);
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x8257fe30
	ctx.lr = 0x822C5DE4;
	sub_8257FE30(ctx, base);
loc_822C5DE4:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575f90
	ctx.lr = 0x822C5DF4;
	sub_82575F90(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822c60f4
	if (cr6.eq) goto loc_822C60F4;
	// lbz r11,2456(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2456);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c5888
	if (cr6.eq) goto loc_822C5888;
	// lwz r3,2448(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2448);
	// lwz r11,2452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c5e30
	if (cr6.eq) goto loc_822C5E30;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822C5E2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c5e40
	goto loc_822C5E40;
loc_822C5E30:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822C5E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C5E40:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c5de4
	if (cr6.eq) goto loc_822C5DE4;
	// b 0x822c5888
	goto loc_822C5888;
loc_822C5E50:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576028
	ctx.lr = 0x822C5E5C;
	sub_82576028(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r25,16
	r25.s64 = 16;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x822c5f88
	if (cr6.eq) goto loc_822C5F88;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r28,0
	r28.s64 = 0;
	// addi r26,r11,-31472
	r26.s64 = r11.s64 + -31472;
loc_822C5E78:
	// lhz r11,164(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c5eb0
	if (cr6.eq) goto loc_822C5EB0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822c5eb0
	if (cr6.lt) goto loc_822C5EB0;
	// lwz r11,156(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 156);
	// lwz r10,144(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 144);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// bge cr6,0x822c5eb0
	if (!cr6.lt) goto loc_822C5EB0;
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x822c5eb8
	goto loc_822C5EB8;
loc_822C5EB0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_822C5EB8:
	// lwz r27,0(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822c5f6c
	if (cr6.eq) goto loc_822C5F6C;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82203400
	ctx.lr = 0x822C5ED8;
	sub_82203400(ctx, base);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v61,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v63,v60,v63
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822c5680
	ctx.lr = 0x822C5F24;
	sub_822C5680(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822c5f6c
	if (cr6.eq) goto loc_822C5F6C;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// clrlwi r4,r30,16
	ctx.r4.u64 = r30.u32 & 0xFFFF;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r7,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r7.u32);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// stw r5,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r5.u32);
	// bl 0x825789c0
	ctx.lr = 0x822C5F60;
	sub_825789C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578ab0
	ctx.lr = 0x822C5F6C;
	sub_82578AB0(ctx, base);
loc_822C5F6C:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576078
	ctx.lr = 0x822C5F7C;
	sub_82576078(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x822c5e78
	if (!cr6.eq) goto loc_822C5E78;
loc_822C5F88:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r11,-31488
	ctx.r10.s64 = r11.s64 + -31488;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v59,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822c60ec
	goto loc_822C60EC;
loc_822C5FAC:
	// lhz r22,146(r29)
	r22.u64 = PPC_LOAD_U16(r29.u32 + 146);
	// li r28,0
	r28.s64 = 0;
	// mr r27,r28
	r27.u64 = r28.u64;
	// mr r23,r22
	r23.u64 = r22.u64;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x822c60ec
	if (!cr6.gt) goto loc_822C60EC;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r25,r28
	r25.u64 = r28.u64;
	// mr r24,r28
	r24.u64 = r28.u64;
loc_822C5FD0:
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// lwzx r28,r11,r24
	r28.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822c60d4
	if (cr6.eq) goto loc_822C60D4;
	// lwz r11,148(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 148);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822c6010
	if (cr6.eq) goto loc_822C6010;
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// and r9,r10,r21
	ctx.r9.u64 = ctx.r10.u64 & r21.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822c60d4
	if (cr6.eq) goto loc_822C60D4;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// and r10,r11,r20
	ctx.r10.u64 = r11.u64 & r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c60d4
	if (cr6.eq) goto loc_822C60D4;
loc_822C6010:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82575cc0
	ctx.lr = 0x822C6024;
	sub_82575CC0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82577518
	ctx.lr = 0x822C6030;
	sub_82577518(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c60b4
	if (!cr6.eq) goto loc_822C60B4;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c5680
	ctx.lr = 0x822C6054;
	sub_822C5680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c60b4
	if (cr6.eq) goto loc_822C60B4;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// or r8,r11,r10
	ctx.r8.u64 = r11.u64 | ctx.r10.u64;
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// or r11,r7,r9
	r11.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// bl 0x82578a38
	ctx.lr = 0x822C6098;
	sub_82578A38(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x822C60A8;
	sub_8257DC50(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c60ec
	if (!cr6.eq) goto loc_822C60EC;
loc_822C60B4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575d40
	ctx.lr = 0x822C60C0;
	sub_82575D40(ctx, base);
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x822c60d4
	if (!cr6.eq) goto loc_822C60D4;
	// lhz r11,146(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 146);
	// add r23,r11,r23
	r23.u64 = r11.u64 + r23.u64;
loc_822C60D4:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// addi r26,r26,64
	r26.s64 = r26.s64 + 64;
	// cmpw cr6,r27,r22
	cr6.compare<int32_t>(r27.s32, r22.s32, xer);
	// blt cr6,0x822c5fd0
	if (cr6.lt) goto loc_822C5FD0;
loc_822C60EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578dd8
	ctx.lr = 0x822C60F4;
	sub_82578DD8(ctx, base);
loc_822C60F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575b48
	ctx.lr = 0x822C60FC;
	sub_82575B48(ctx, base);
	// addi r1,r1,1536
	ctx.r1.s64 = ctx.r1.s64 + 1536;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd7bc
	ctx.lr = 0x822C6108;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822C6110"))) PPC_WEAK_FUNC(sub_822C6110);
PPC_FUNC_IMPL(__imp__sub_822C6110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x822C6118;
	// addi r31,r1,-368
	r31.s64 = ctx.r1.s64 + -368;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// bl 0x82203388
	ctx.lr = 0x822C6148;
	sub_82203388(ctx, base);
	// lbz r11,2437(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2437);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c6174
	if (!cr6.eq) goto loc_822C6174;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82575c10
	ctx.lr = 0x822C6160;
	sub_82575C10(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// stw r23,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r23.u32);
	// stw r28,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r28.u32);
	// stw r22,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r22.u32);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
loc_822C6174:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825788a8
	ctx.lr = 0x822C617C;
	sub_825788A8(ctx, base);
	// mr r24,r27
	r24.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x822c6190
	if (!cr6.eq) goto loc_822C6190;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r24,-23452(r11)
	r24.u64 = PPC_LOAD_U32(r11.u32 + -23452);
loc_822C6190:
	// lwz r11,276(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 276);
	// li r21,0
	r21.s64 = 0;
	// mr r20,r21
	r20.u64 = r21.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c61dc
	if (!cr6.eq) goto loc_822C61DC;
	// li r12,-8192
	r12.s64 = -8192;
	// bl 0x823dbff4
	ctx.lr = 0x822C61AC;
	sub_823DBFF4(ctx, base);
	// lwz r11,0(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// stwux r11,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r1.u32 = ea;
	// li r12,-8192
	r12.s64 = -8192;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x822C61C0;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r8,4096
	ctx.r8.s64 = 4096;
	// stw r10,276(r30)
	PPC_STORE_U32(r30.u32 + 276, ctx.r10.u32);
	// li r20,1
	r20.s64 = 1;
	// sth r8,280(r30)
	PPC_STORE_U16(r30.u32 + 280, ctx.r8.u16);
	// stb r21,410(r30)
	PPC_STORE_U8(r30.u32 + 410, r21.u8);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
loc_822C61DC:
	// lbz r11,2437(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2437);
	// mr r26,r21
	r26.u64 = r21.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c6204
	if (!cr6.eq) goto loc_822C6204;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82572cc8
	ctx.lr = 0x822C61F8;
	sub_82572CC8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r29,1920(r30)
	PPC_STORE_U32(r30.u32 + 1920, r29.u32);
	// b 0x822c6208
	goto loc_822C6208;
loc_822C6204:
	// lwz r29,1920(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 1920);
loc_822C6208:
	// addi r11,r30,1920
	r11.s64 = r30.s64 + 1920;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822c6328
	if (cr6.eq) goto loc_822C6328;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_822C6218:
	// cmplw cr6,r29,r19
	cr6.compare<uint32_t>(r29.u32, r19.u32, xer);
	// beq cr6,0x822c62c8
	if (cr6.eq) goto loc_822C62C8;
	// lwz r3,2440(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2440);
	// lwz r11,2444(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2444);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c6240
	if (cr6.eq) goto loc_822C6240;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822C623C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c624c
	goto loc_822C624C;
loc_822C6240:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822C624C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822C624C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c62c8
	if (cr6.eq) goto loc_822C62C8;
	// addi r27,r29,16
	r27.s64 = r29.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82575c38
	ctx.lr = 0x822C6268;
	sub_82575C38(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,12(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82577678
	ctx.lr = 0x822C627C;
	sub_82577678(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c62c8
	if (!cr6.eq) goto loc_822C62C8;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822c5680
	ctx.lr = 0x822C62A0;
	sub_822C5680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c62c8
	if (cr6.eq) goto loc_822C62C8;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8257dc50
	ctx.lr = 0x822C62BC;
	sub_8257DC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c6328
	if (!cr6.eq) goto loc_822C6328;
loc_822C62C8:
	// lbz r11,2437(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2437);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c630c
	if (!cr6.eq) goto loc_822C630C;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x825712e8
	ctx.lr = 0x822C62E0;
	sub_825712E8(ctx, base);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpwi cr6,r26,127
	cr6.compare<int32_t>(r26.s32, 127, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// blt cr6,0x822c62fc
	if (cr6.lt) goto loc_822C62FC;
	// li r11,127
	r11.s64 = 127;
loc_822C62FC:
	// addi r11,r11,480
	r11.s64 = r11.s64 + 480;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, r29.u32);
	// b 0x822c6320
	goto loc_822C6320;
loc_822C630C:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpwi cr6,r26,128
	cr6.compare<int32_t>(r26.s32, 128, xer);
	// bge cr6,0x822c6328
	if (!cr6.lt) goto loc_822C6328;
	// lwz r29,0(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 0);
loc_822C6320:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x822c6218
	if (!cr6.eq) goto loc_822C6218;
loc_822C6328:
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c6340
	if (cr6.eq) goto loc_822C6340;
	// stw r21,276(r30)
	PPC_STORE_U32(r30.u32 + 276, r21.u32);
	// sth r21,280(r30)
	PPC_STORE_U16(r30.u32 + 280, r21.u16);
	// stb r21,410(r30)
	PPC_STORE_U8(r30.u32 + 410, r21.u8);
loc_822C6340:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82475b38
	ctx.lr = 0x822C6348;
	sub_82475B38(ctx, base);
	// lbz r10,244(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 244);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c6364
	if (cr6.eq) goto loc_822C6364;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23388
	ctx.r3.s64 = r11.s64 + -23388;
	// bl 0x821c8f70
	ctx.lr = 0x822C6364;
	sub_821C8F70(ctx, base);
loc_822C6364:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r31,368
	ctx.r1.s64 = r31.s64 + 368;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822C6370"))) PPC_WEAK_FUNC(sub_822C6370);
PPC_FUNC_IMPL(__imp__sub_822C6370) {
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
	ctx.lr = 0x822C6378;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x822C639C;
	sub_821C8FE0(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r28,r10,-30432
	r28.s64 = ctx.r10.s64 + -30432;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8257ddd8
	ctx.lr = 0x822C63B8;
	sub_8257DDD8(ctx, base);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,-23452(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23452);
	// bl 0x822c6110
	ctx.lr = 0x822C63E0;
	sub_822C6110(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x822C63EC;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C63F8"))) PPC_WEAK_FUNC(sub_822C63F8);
PPC_FUNC_IMPL(__imp__sub_822C63F8) {
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
	ctx.lr = 0x822C6400;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x822C6424;
	sub_821C8FE0(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r28,r10,-30432
	r28.s64 = ctx.r10.s64 + -30432;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8257de68
	ctx.lr = 0x822C6440;
	sub_8257DE68(ctx, base);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,-23452(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23452);
	// bl 0x822c6110
	ctx.lr = 0x822C6468;
	sub_822C6110(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x822C6474;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C6480"))) PPC_WEAK_FUNC(sub_822C6480);
PPC_FUNC_IMPL(__imp__sub_822C6480) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x822C6488;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// addi r26,r11,19856
	r26.s64 = r11.s64 + 19856;
	// lwz r11,-27928(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -27928);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c64d0
	if (!cr6.eq) goto loc_822C64D0;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,-27928(r31)
	PPC_STORE_U32(r31.u32 + -27928, r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r10,-25808
	ctx.r4.s64 = ctx.r10.s64 + -25808;
	// bl 0x82144a20
	ctx.lr = 0x822C64C8;
	sub_82144A20(ctx, base);
	// lwz r11,-27928(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -27928);
	// stw r3,-27932(r28)
	PPC_STORE_U32(r28.u32 + -27932, ctx.r3.u32);
loc_822C64D0:
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// lis r25,-32120
	r25.s64 = -2105016320;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822c64fc
	if (!cr6.eq) goto loc_822C64FC;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,-27928(r31)
	PPC_STORE_U32(r31.u32 + -27928, r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r10,-25828
	ctx.r4.s64 = ctx.r10.s64 + -25828;
	// bl 0x82144a20
	ctx.lr = 0x822C64F8;
	sub_82144A20(ctx, base);
	// stw r3,-27936(r25)
	PPC_STORE_U32(r25.u32 + -27936, ctx.r3.u32);
loc_822C64FC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r30,r11,-12352
	r30.s64 = r11.s64 + -12352;
	// addi r8,r10,2256
	ctx.r8.s64 = ctx.r10.s64 + 2256;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lvx128 v62,r30,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,0
	r31.s64 = 0;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lfs f31,27636(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27636);
	f31.f64 = double(temp.f32);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f0,224(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 + f31.f64));
	// stfs f0,228(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r31,238(r1)
	PPC_STORE_U16(ctx.r1.u32 + 238, r31.u16);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stb r31,240(r1)
	PPC_STORE_U8(ctx.r1.u32 + 240, r31.u8);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r31,242(r1)
	PPC_STORE_U16(ctx.r1.u32 + 242, r31.u16);
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r31.u32);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r7,236(r1)
	PPC_STORE_U16(ctx.r1.u32 + 236, ctx.r7.u16);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r27,r31
	r27.u64 = r31.u64;
	// mr r29,r31
	r29.u64 = r31.u64;
	// bl 0x822c63f8
	ctx.lr = 0x822C65B0;
	sub_822C63F8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x822c65c0
	if (!cr6.gt) goto loc_822C65C0;
	// lwz r27,-27932(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + -27932);
	// li r29,1
	r29.s64 = 1;
loc_822C65C0:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lwz r11,-12564(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -12564);
	// addi r24,r1,96
	r24.s64 = ctx.r1.s64 + 96;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stb r29,1075(r11)
	PPC_STORE_U8(r11.u32 + 1075, r29.u8);
	// lvx128 v63,r30,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822c6370
	ctx.lr = 0x822C6614;
	sub_822C6370(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x822c66a4
	if (!cr6.gt) goto loc_822C66A4;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r4,232(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// lwz r3,-23464(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23464);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C6638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,60(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lwz r30,0(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// beq cr6,0x822c6658
	if (cr6.eq) goto loc_822C6658;
	// lbz r11,230(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 230);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c6678
	if (cr6.eq) goto loc_822C6678;
loc_822C6658:
	// lbz r11,230(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 230);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c6678
	if (cr6.eq) goto loc_822C6678;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,231(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 231);
	// bl 0x82144a28
	ctx.lr = 0x822C6674;
	sub_82144A28(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_822C6678:
	// lbz r11,235(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 235);
	// li r29,1
	r29.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822c66a4
	if (cr6.eq) goto loc_822C66A4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,236(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// lwz r31,-12564(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -12564);
	// bl 0x82144a28
	ctx.lr = 0x822C669C;
	sub_82144A28(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// b 0x822c66ac
	goto loc_822C66AC;
loc_822C66A4:
	// lwz r11,-12564(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -12564);
	// stw r31,144(r11)
	PPC_STORE_U32(r11.u32 + 144, r31.u32);
loc_822C66AC:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x822c66d0
	if (!cr6.eq) goto loc_822C66D0;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822c66dc
	if (!cr6.eq) goto loc_822C66DC;
	// lwz r11,-27936(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -27936);
	// stw r11,-12528(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12528, r11.u32);
	// b 0x822c66e0
	goto loc_822C66E0;
loc_822C66D0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r11,-12528(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12528, r11.u32);
	// b 0x822c66e0
	goto loc_822C66E0;
loc_822C66DC:
	// lwz r11,-12528(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12528);
loc_822C66E0:
	// lwz r8,10(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r7,18(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 18);
	// addi r6,r9,29952
	ctx.r6.s64 = ctx.r9.s64 + 29952;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,-12508(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12508);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f10,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// bge cr6,0x822c6728
	if (!cr6.lt) goto loc_822C6728;
	// fmadds f13,f12,f10,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f13.f64));
	// stfs f13,-12508(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12508, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822c6748
	if (!cr6.gt) goto loc_822C6748;
	// b 0x822c6740
	goto loc_822C6740;
loc_822C6728:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822c6748
	if (!cr6.gt) goto loc_822C6748;
	// fnmsubs f13,f12,f10,f13
	ctx.f13.f64 = double(float(-(ctx.f12.f64 * ctx.f10.f64 - ctx.f13.f64)));
	// stfs f13,-12508(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12508, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822c6748
	if (!cr6.lt) goto loc_822C6748;
loc_822C6740:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
	// stfs f13,-12508(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12508, temp.u32);
loc_822C6748:
	// lwz r8,14(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,18(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 18);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,-12504(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12504);
	f0.f64 = double(temp.f32);
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x822c6784
	if (!cr6.lt) goto loc_822C6784;
	// fmadds f0,f11,f10,f0
	f0.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + f0.f64));
	// stfs f0,-12504(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12504, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x822c67a4
	if (!cr6.gt) goto loc_822C67A4;
	// b 0x822c679c
	goto loc_822C679C;
loc_822C6784:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x822c67a4
	if (!cr6.gt) goto loc_822C67A4;
	// fnmsubs f0,f11,f10,f0
	f0.f64 = double(float(-(ctx.f11.f64 * ctx.f10.f64 - f0.f64)));
	// stfs f0,-12504(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12504, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x822c67a4
	if (!cr6.lt) goto loc_822C67A4;
loc_822C679C:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
	// stfs f0,-12504(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12504, temp.u32);
loc_822C67A4:
	// stfs f13,6444(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 6444, temp.u32);
	// stfs f0,6448(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 6448, temp.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822C67B8"))) PPC_WEAK_FUNC(sub_822C67B8);
PPC_FUNC_IMPL(__imp__sub_822C67B8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822C67C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,176
	r29.s64 = r31.s64 + 176;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// addi r3,r29,628
	ctx.r3.s64 = r29.s64 + 628;
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// stw r30,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r30.u32);
	// sth r30,280(r31)
	PPC_STORE_U16(r31.u32 + 280, r30.u16);
	// stw r30,932(r31)
	PPC_STORE_U32(r31.u32 + 932, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x822C6814;
	sub_823D9890(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,106
	ctx.r3.s64 = r29.s64 + 106;
	// bl 0x823d9890
	ctx.lr = 0x822C6824;
	sub_823D9890(ctx, base);
	// stb r30,410(r31)
	PPC_STORE_U8(r31.u32 + 410, r30.u8);
	// addi r3,r31,1664
	ctx.r3.s64 = r31.s64 + 1664;
	// stw r30,2440(r31)
	PPC_STORE_U32(r31.u32 + 2440, r30.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r30,2444(r31)
	PPC_STORE_U32(r31.u32 + 2444, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,2448(r31)
	PPC_STORE_U32(r31.u32 + 2448, r30.u32);
	// addi r11,r31,2440
	r11.s64 = r31.s64 + 2440;
	// stw r30,2452(r31)
	PPC_STORE_U32(r31.u32 + 2452, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x822C684C;
	sub_823D9890(ctx, base);
	// addi r3,r31,1920
	ctx.r3.s64 = r31.s64 + 1920;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x822C685C;
	sub_823D9890(ctx, base);
	// stw r30,2432(r31)
	PPC_STORE_U32(r31.u32 + 2432, r30.u32);
	// stb r30,2436(r31)
	PPC_STORE_U8(r31.u32 + 2436, r30.u8);
	// lis r11,-32212
	r11.s64 = -2111045632;
	// stb r30,2437(r31)
	PPC_STORE_U8(r31.u32 + 2437, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,2456(r31)
	PPC_STORE_U8(r31.u32 + 2456, r30.u8);
	// addi r10,r11,22080
	ctx.r10.s64 = r11.s64 + 22080;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x822C6880;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r11,-1
	r11.s64 = -1;
	// li r8,7
	ctx.r8.s64 = 7;
	// std r9,2440(r31)
	PPC_STORE_U64(r31.u32 + 2440, ctx.r9.u64);
	// stw r28,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r27,280(r31)
	PPC_STORE_U16(r31.u32 + 280, r27.u16);
	// stb r30,410(r31)
	PPC_STORE_U8(r31.u32 + 410, r30.u8);
	// stw r30,2460(r31)
	PPC_STORE_U32(r31.u32 + 2460, r30.u32);
	// stw r11,2464(r31)
	PPC_STORE_U32(r31.u32 + 2464, r11.u32);
	// stw r11,2468(r31)
	PPC_STORE_U32(r31.u32 + 2468, r11.u32);
	// stb r8,2472(r31)
	PPC_STORE_U8(r31.u32 + 2472, ctx.r8.u8);
	// stw r30,2476(r31)
	PPC_STORE_U32(r31.u32 + 2476, r30.u32);
	// stw r30,2480(r31)
	PPC_STORE_U32(r31.u32 + 2480, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822C68C4"))) PPC_WEAK_FUNC(sub_822C68C4);
PPC_FUNC_IMPL(__imp__sub_822C68C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C68C8"))) PPC_WEAK_FUNC(sub_822C68C8);
PPC_FUNC_IMPL(__imp__sub_822C68C8) {
	PPC_FUNC_PROLOGUE();
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C68D8"))) PPC_WEAK_FUNC(sub_822C68D8);
PPC_FUNC_IMPL(__imp__sub_822C68D8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12352(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12352);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C6908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8268c6d8
	ctx.lr = 0x822C6914;
	sub_8268C6D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r6,-1
	ctx.r6.s64 = -1;
	// bl 0x8268ee10
	ctx.lr = 0x822C6928;
	sub_8268EE10(ctx, base);
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

__attribute__((alias("__imp__sub_822C6940"))) PPC_WEAK_FUNC(sub_822C6940);
PPC_FUNC_IMPL(__imp__sub_822C6940) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12636(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12636);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C696C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_822C6988"))) PPC_WEAK_FUNC(sub_822C6988);
PPC_FUNC_IMPL(__imp__sub_822C6988) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,68
	ctx.r3.s64 = ctx.r3.s64 + 68;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C6990"))) PPC_WEAK_FUNC(sub_822C6990);
PPC_FUNC_IMPL(__imp__sub_822C6990) {
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
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// addi r8,r10,-27388
	ctx.r8.s64 = ctx.r10.s64 + -27388;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r7,r9,-27352
	ctx.r7.s64 = ctx.r9.s64 + -27352;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r4,r4,-25080
	ctx.r4.s64 = ctx.r4.s64 + -25080;
	// lwzx r5,r5,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// lwzx r6,r6,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x822C69E0;
	sub_82130000(ctx, base);
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// cmpwi cr6,r3,10
	cr6.compare<int32_t>(ctx.r3.s32, 10, xer);
	// beq cr6,0x822c6a24
	if (cr6.eq) goto loc_822C6A24;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// cmpwi cr6,r10,10
	cr6.compare<int32_t>(ctx.r10.s32, 10, xer);
	// bne cr6,0x822c6a0c
	if (!cr6.eq) goto loc_822C6A0C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
loc_822C6A0C:
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r8.u32);
loc_822C6A24:
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

__attribute__((alias("__imp__sub_822C6A3C"))) PPC_WEAK_FUNC(sub_822C6A3C);
PPC_FUNC_IMPL(__imp__sub_822C6A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C6A40"))) PPC_WEAK_FUNC(sub_822C6A40);
PPC_FUNC_IMPL(__imp__sub_822C6A40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822C6A54"))) PPC_WEAK_FUNC(sub_822C6A54);
PPC_FUNC_IMPL(__imp__sub_822C6A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C6A58"))) PPC_WEAK_FUNC(sub_822C6A58);
PPC_FUNC_IMPL(__imp__sub_822C6A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822C6A60;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822c6c3c
	if (cr6.eq) goto loc_822C6C3C;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
	// li r24,0
	r24.s64 = 0;
	// addi r26,r8,-24980
	r26.s64 = ctx.r8.s64 + -24980;
	// addi r25,r9,-25012
	r25.s64 = ctx.r9.s64 + -25012;
	// addi r28,r10,-25036
	r28.s64 = ctx.r10.s64 + -25036;
	// addi r27,r11,-27352
	r27.s64 = r11.s64 + -27352;
loc_822C6A9C:
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lwz r11,44(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,48(r29)
	PPC_STORE_U32(r29.u32 + 48, ctx.r10.u32);
	// stw r11,44(r29)
	PPC_STORE_U32(r29.u32 + 44, r11.u32);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x822c6ac0
	if (!cr6.eq) goto loc_822C6AC0;
	// stw r24,44(r29)
	PPC_STORE_U32(r29.u32 + 44, r24.u32);
loc_822C6AC0:
	// lwz r11,44(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r29
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r9,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// bl 0x82130000
	ctx.lr = 0x822C6AE0;
	sub_82130000(ctx, base);
	// cmplwi cr6,r30,19
	cr6.compare<uint32_t>(r30.u32, 19, xer);
	// bgt cr6,0x822c6c28
	if (cr6.gt) goto loc_822C6C28;
	// lis r12,-32212
	r12.s64 = -2111045632;
	// addi r12,r12,27392
	r12.s64 = r12.s64 + 27392;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r30.u64) {
	case 0:
		goto loc_822C6B50;
	case 1:
		goto loc_822C6B58;
	case 2:
		goto loc_822C6B58;
	case 3:
		goto loc_822C6B74;
	case 4:
		goto loc_822C6B58;
	case 5:
		goto loc_822C6B58;
	case 6:
		goto loc_822C6C28;
	case 7:
		goto loc_822C6B58;
	case 8:
		goto loc_822C6B80;
	case 9:
		goto loc_822C6C30;
	case 10:
		goto loc_822C6B9C;
	case 11:
		goto loc_822C6C30;
	case 12:
		goto loc_822C6BB8;
	case 13:
		goto loc_822C6C30;
	case 14:
		goto loc_822C6BD4;
	case 15:
		goto loc_822C6BF0;
	case 16:
		goto loc_822C6BD4;
	case 17:
		goto loc_822C6C28;
	case 18:
		goto loc_822C6C30;
	case 19:
		goto loc_822C6C0C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,27472(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27472);
	// lwz r17,27480(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27480);
	// lwz r17,27480(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27480);
	// lwz r17,27508(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27508);
	// lwz r17,27480(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27480);
	// lwz r17,27480(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27480);
	// lwz r17,27688(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27688);
	// lwz r17,27480(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27480);
	// lwz r17,27520(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27520);
	// lwz r17,27696(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27696);
	// lwz r17,27548(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27548);
	// lwz r17,27696(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27696);
	// lwz r17,27576(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27576);
	// lwz r17,27696(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27696);
	// lwz r17,27604(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27604);
	// lwz r17,27632(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27632);
	// lwz r17,27604(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27604);
	// lwz r17,27688(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27688);
	// lwz r17,27696(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27696);
	// lwz r17,27660(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 27660);
loc_822C6B50:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// b 0x822c6c2c
	goto loc_822C6C2C;
loc_822C6B58:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6B70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c6c30
	goto loc_822C6C30;
loc_822C6B74:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822befd0
	ctx.lr = 0x822C6B7C;
	sub_822BEFD0(ctx, base);
	// b 0x822c6c30
	goto loc_822C6C30;
loc_822C6B80:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c6c30
	goto loc_822C6C30;
loc_822C6B9C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c6c30
	goto loc_822C6C30;
loc_822C6BB8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c6c30
	goto loc_822C6C30;
loc_822C6BD4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6BEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c6c30
	goto loc_822C6C30;
loc_822C6BF0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6C08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c6c30
	goto loc_822C6C30;
loc_822C6C0C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6C24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822c6c30
	goto loc_822C6C30;
loc_822C6C28:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_822C6C2C:
	// bl 0x821bd618
	ctx.lr = 0x822C6C30;
	sub_821BD618(ctx, base);
loc_822C6C30:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822c6a9c
	if (!cr6.eq) goto loc_822C6A9C;
loc_822C6C3C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6C50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822C6C58"))) PPC_WEAK_FUNC(sub_822C6C58);
PPC_FUNC_IMPL(__imp__sub_822C6C58) {
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
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12636(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12636);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6C88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12636(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12636);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822C6C9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822bf970
	ctx.lr = 0x822C6CA4;
	sub_822BF970(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// addi r6,r7,-27888
	ctx.r6.s64 = ctx.r7.s64 + -27888;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822c6ce0
	if (cr6.eq) goto loc_822C6CE0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,19
	ctx.r4.s64 = 19;
	// lwz r3,-12356(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12356);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822C6CD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// b 0x822c6ce8
	goto loc_822C6CE8;
loc_822C6CE0:
	// li r11,2
	r11.s64 = 2;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_822C6CE8:
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

__attribute__((alias("__imp__sub_822C6D00"))) PPC_WEAK_FUNC(sub_822C6D00);
PPC_FUNC_IMPL(__imp__sub_822C6D00) {
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
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12636(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12636);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822C6D30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12636(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12636);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822C6D44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_822C6D64"))) PPC_WEAK_FUNC(sub_822C6D64);
PPC_FUNC_IMPL(__imp__sub_822C6D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C6D68"))) PPC_WEAK_FUNC(sub_822C6D68);
PPC_FUNC_IMPL(__imp__sub_822C6D68) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-25108
	ctx.r9.s64 = r11.s64 + -25108;
	// addi r8,r10,-21856
	ctx.r8.s64 = ctx.r10.s64 + -21856;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r8,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r8.u32);
	// bl 0x82390c98
	ctx.lr = 0x822C6DA0;
	sub_82390C98(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822c6db8
	if (cr6.eq) goto loc_822C6DB8;
	// bl 0x82130588
	ctx.lr = 0x822C6DB4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822C6DB8:
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

__attribute__((alias("__imp__sub_822C6DD0"))) PPC_WEAK_FUNC(sub_822C6DD0);
PPC_FUNC_IMPL(__imp__sub_822C6DD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-27388
	ctx.r8.s64 = ctx.r10.s64 + -27388;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r6,-24916
	ctx.r4.s64 = ctx.r6.s64 + -24916;
	// lwzx r6,r9,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x822C6E18;
	sub_82130000(ctx, base);
	// addi r11,r30,-1
	r11.s64 = r30.s64 + -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x822c6e88
	if (cr6.gt) goto loc_822C6E88;
	// lis r12,-32212
	r12.s64 = -2111045632;
	// addi r12,r12,28220
	r12.s64 = r12.s64 + 28220;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822C6E5C;
	case 1:
		goto loc_822C6E7C;
	case 2:
		goto loc_822C6E68;
	case 3:
		goto loc_822C6E94;
	case 4:
		goto loc_822C6E94;
	case 5:
		goto loc_822C6E74;
	case 6:
		goto loc_822C6E94;
	case 7:
		goto loc_822C6E94;
	default:
		__builtin_unreachable();
	}
	// lwz r17,28252(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 28252);
	// lwz r17,28284(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 28284);
	// lwz r17,28264(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 28264);
	// lwz r17,28308(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 28308);
	// lwz r17,28308(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 28308);
	// lwz r17,28276(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 28276);
	// lwz r17,28308(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 28308);
	// lwz r17,28308(r12)
	r17.u64 = PPC_LOAD_U32(r12.u32 + 28308);
loc_822C6E5C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c6940
	ctx.lr = 0x822C6E64;
	sub_822C6940(ctx, base);
	// b 0x822c6e94
	goto loc_822C6E94;
loc_822C6E68:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c6d00
	ctx.lr = 0x822C6E70;
	sub_822C6D00(ctx, base);
	// b 0x822c6e94
	goto loc_822C6E94;
loc_822C6E74:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822befd0
	ctx.lr = 0x822C6E7C;
	sub_822BEFD0(ctx, base);
loc_822C6E7C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822c6c58
	ctx.lr = 0x822C6E84;
	sub_822C6C58(ctx, base);
	// b 0x822c6e94
	goto loc_822C6E94;
loc_822C6E88:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-24956
	ctx.r3.s64 = r11.s64 + -24956;
	// bl 0x821bd618
	ctx.lr = 0x822C6E94;
	sub_821BD618(ctx, base);
loc_822C6E94:
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
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

__attribute__((alias("__imp__sub_822C6EB0"))) PPC_WEAK_FUNC(sub_822C6EB0);
PPC_FUNC_IMPL(__imp__sub_822C6EB0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,-12352(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12352);
	// lwz r31,0(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822C6EE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8268c6d8
	ctx.lr = 0x822C6EF0;
	sub_8268C6D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r6,-1
	ctx.r6.s64 = -1;
	// bl 0x8268ee10
	ctx.lr = 0x822C6F04;
	sub_8268EE10(ctx, base);
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

__attribute__((alias("__imp__sub_822C6F1C"))) PPC_WEAK_FUNC(sub_822C6F1C);
PPC_FUNC_IMPL(__imp__sub_822C6F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C6F20"))) PPC_WEAK_FUNC(sub_822C6F20);
PPC_FUNC_IMPL(__imp__sub_822C6F20) {
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
	// bl 0x82390d08
	ctx.lr = 0x822C6F40;
	sub_82390D08(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-25108
	ctx.r9.s64 = r11.s64 + -25108;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r4,r10,22412
	ctx.r4.s64 = ctx.r10.s64 + 22412;
	// addi r10,r8,1728
	ctx.r10.s64 = ctx.r8.s64 + 1728;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// addi r9,r7,1632
	ctx.r9.s64 = ctx.r7.s64 + 1632;
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// addi r8,r6,-25120
	ctx.r8.s64 = ctx.r6.s64 + -25120;
	// stw r5,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r5.u32);
	// stw r4,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// stw r8,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r8.u32);
	// bl 0x822c6dd0
	ctx.lr = 0x822C6FA4;
	sub_822C6DD0(ctx, base);
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

__attribute__((alias("__imp__sub_822C6FC0"))) PPC_WEAK_FUNC(sub_822C6FC0);
PPC_FUNC_IMPL(__imp__sub_822C6FC0) {
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
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x822C6FDC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822c6ff0
	if (cr6.eq) goto loc_822C6FF0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822c6f20
	ctx.lr = 0x822C6FEC;
	sub_822C6F20(ctx, base);
	// b 0x822c6ff4
	goto loc_822C6FF4;
loc_822C6FF0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822C6FF4:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,-12356(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12356, ctx.r3.u32);
	// stw r3,-12352(r11)
	PPC_STORE_U32(r11.u32 + -12352, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822C7018"))) PPC_WEAK_FUNC(sub_822C7018);
PPC_FUNC_IMPL(__imp__sub_822C7018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32212
	r11.s64 = -2111045632;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,28336
	ctx.r4.s64 = r11.s64 + 28336;
	// addi r3,r10,-24880
	ctx.r3.s64 = ctx.r10.s64 + -24880;
	// b 0x82554798
	sub_82554798(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822C702C"))) PPC_WEAK_FUNC(sub_822C702C);
PPC_FUNC_IMPL(__imp__sub_822C702C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822C7030"))) PPC_WEAK_FUNC(sub_822C7030);
PPC_FUNC_IMPL(__imp__sub_822C7030) {
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
	ctx.lr = 0x822C7038;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x823db670
	ctx.lr = 0x822C7060;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821fd7c0
	ctx.lr = 0x822C7074;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,468(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// stb r11,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, r11.u8);
	// stw r11,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// stw r29,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r29.u32);
	// lwz r11,10248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// stw r11,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, r11.u32);
	// bne cr6,0x822c7130
	if (!cr6.eq) goto loc_822C7130;
	// lwz r11,10244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10244);
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,10244(r31)
	PPC_STORE_U32(r31.u32 + 10244, ctx.r8.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// stw r9,92(r11)
	PPC_STORE_U32(r11.u32 + 92, ctx.r9.u32);
	// beq cr6,0x822c70d8
	if (cr6.eq) goto loc_822C70D8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// b 0x822c70e0
	goto loc_822C70E0;
loc_822C70D8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r11,3992(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 3992);
loc_822C70E0:
	// sth r11,92(r30)
	PPC_STORE_U16(r30.u32 + 92, r11.u16);
	// li r11,2
	r11.s64 = 2;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r11,156(r30)
	PPC_STORE_U32(r30.u32 + 156, r11.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r29,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r29.u32);
	// addi r3,r1,324
	ctx.r3.s64 = ctx.r1.s64 + 324;
	// bl 0x823db670
	ctx.lr = 0x822C7100;
	sub_823DB670(ctx, base);
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// addi r4,r1,324
	ctx.r4.s64 = ctx.r1.s64 + 324;
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x822C7114;
	sub_823DA950(ctx, base);
	// stw r30,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r30.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r4,10248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821fcf28
	ctx.lr = 0x822C712C;
	sub_821FCF28(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822C7130:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822C7138"))) PPC_WEAK_FUNC(sub_822C7138);
PPC_FUNC_IMPL(__imp__sub_822C7138) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x822c7030
	ctx.lr = 0x822C7150;
	sub_822C7030(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r11.u32);
	// beq cr6,0x822c716c
	if (cr6.eq) goto loc_822C716C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// b 0x822c7174
	goto loc_822C7174;
loc_822C716C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r11,3992(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 3992);
loc_822C7174:
	// sth r11,92(r3)
	PPC_STORE_U16(ctx.r3.u32 + 92, r11.u16);
	// li r11,2
	r11.s64 = 2;
	// stw r11,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, r11.u32);
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

__attribute__((alias("__imp__sub_822C7194"))) PPC_WEAK_FUNC(sub_822C7194);
PPC_FUNC_IMPL(__imp__sub_822C7194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

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

