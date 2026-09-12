#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82569F80"))) PPC_WEAK_FUNC(sub_82569F80);
PPC_FUNC_IMPL(__imp__sub_82569F80) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82569F84"))) PPC_WEAK_FUNC(sub_82569F84);
PPC_FUNC_IMPL(__imp__sub_82569F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82569F88"))) PPC_WEAK_FUNC(sub_82569F88);
PPC_FUNC_IMPL(__imp__sub_82569F88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82569F98"))) PPC_WEAK_FUNC(sub_82569F98);
PPC_FUNC_IMPL(__imp__sub_82569F98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82569FA8"))) PPC_WEAK_FUNC(sub_82569FA8);
PPC_FUNC_IMPL(__imp__sub_82569FA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82569FB8"))) PPC_WEAK_FUNC(sub_82569FB8);
PPC_FUNC_IMPL(__imp__sub_82569FB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82569FC8"))) PPC_WEAK_FUNC(sub_82569FC8);
PPC_FUNC_IMPL(__imp__sub_82569FC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82569FD8"))) PPC_WEAK_FUNC(sub_82569FD8);
PPC_FUNC_IMPL(__imp__sub_82569FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82569FE8"))) PPC_WEAK_FUNC(sub_82569FE8);
PPC_FUNC_IMPL(__imp__sub_82569FE8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-4908
	ctx.r10.s64 = r11.s64 + -4908;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256a020
	if (cr6.eq) goto loc_8256A020;
	// bl 0x8256ac60
	ctx.lr = 0x8256A020;
	sub_8256AC60(ctx, base);
loc_8256A020:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256a038
	if (cr6.eq) goto loc_8256A038;
	// bl 0x82130588
	ctx.lr = 0x8256A034;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256A038:
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

__attribute__((alias("__imp__sub_8256A050"))) PPC_WEAK_FUNC(sub_8256A050);
PPC_FUNC_IMPL(__imp__sub_8256A050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-4508
	ctx.r10.s64 = r11.s64 + -4508;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8256A060"))) PPC_WEAK_FUNC(sub_8256A060);
PPC_FUNC_IMPL(__imp__sub_8256A060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r10.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256A078"))) PPC_WEAK_FUNC(sub_8256A078);
PPC_FUNC_IMPL(__imp__sub_8256A078) {
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
	ctx.lr = 0x8256A080;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r28,1
	r28.s64 = 1;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r10,392(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 392);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8256a118
	if (cr6.lt) goto loc_8256A118;
	// li r27,0
	r27.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
	// mr r28,r27
	r28.u64 = r27.u64;
	// bl 0x822a7c08
	ctx.lr = 0x8256A0B4;
	sub_822A7C08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256a114
	if (!cr6.eq) goto loc_8256A114;
loc_8256A0C0:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256a114
	if (!cr6.eq) goto loc_8256A114;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x82330c88
	ctx.lr = 0x8256A0D8;
	sub_82330C88(ctx, base);
	// lwz r11,392(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 392);
	// subf. r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8256a0f0
	if (cr0.lt) goto loc_8256A0F0;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8256a0f4
	if (cr6.lt) goto loc_8256A0F4;
loc_8256A0F0:
	// li r28,1
	r28.s64 = 1;
loc_8256A0F4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x8256A108;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8256a0c0
	if (cr6.eq) goto loc_8256A0C0;
loc_8256A114:
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
loc_8256A118:
	// lwz r11,56(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8256a14c
	if (!cr6.eq) goto loc_8256A14C;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256a14c
	if (cr6.eq) goto loc_8256A14C;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// li r10,288
	ctx.r10.s64 = 288;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,1
	ctx.r8.s64 = 1;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r29,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,56(r29)
	PPC_STORE_U32(r29.u32 + 56, ctx.r8.u32);
loc_8256A14C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256A154"))) PPC_WEAK_FUNC(sub_8256A154);
PPC_FUNC_IMPL(__imp__sub_8256A154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A158"))) PPC_WEAK_FUNC(sub_8256A158);
PPC_FUNC_IMPL(__imp__sub_8256A158) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8256a18c
	if (cr6.eq) goto loc_8256A18C;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8256a18c
	if (cr6.eq) goto loc_8256A18C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,136(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
loc_8256A18C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256A194"))) PPC_WEAK_FUNC(sub_8256A194);
PPC_FUNC_IMPL(__imp__sub_8256A194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A198"))) PPC_WEAK_FUNC(sub_8256A198);
PPC_FUNC_IMPL(__imp__sub_8256A198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8256a784
	if (cr6.eq) goto loc_8256A784;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lfs f12,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lfs f11,292(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f9,296(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,288(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 288);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f30,f6,f6,f4
	f30.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// bne cr6,0x8256a36c
	if (!cr6.eq) goto loc_8256A36C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// fcmpu cr6,f30,f12
	cr6.compare(f30.f64, ctx.f12.f64);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// bgt cr6,0x8256a290
	if (cr6.gt) goto loc_8256A290;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8256a290
	if (cr6.lt) goto loc_8256A290;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8256a290
	if (cr6.eq) goto loc_8256A290;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8256a290
	if (cr6.eq) goto loc_8256A290;
	// lfs f0,136(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8256a290
	if (!cr6.gt) goto loc_8256A290;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256A27C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8256a290
	if (cr6.eq) goto loc_8256A290;
	// li r11,2
	r11.s64 = 2;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// b 0x8256a784
	goto loc_8256A784;
loc_8256A290:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8256a33c
	if (!cr6.eq) goto loc_8256A33C;
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bgt cr6,0x8256a33c
	if (cr6.gt) goto loc_8256A33C;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8256a33c
	if (cr6.lt) goto loc_8256A33C;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r9,2288
	ctx.r7.s64 = ctx.r9.s64 + 2288;
	// lfs f13,264(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 264);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,260(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 260);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,2288(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2288);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,256(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 256);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f11,f0,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f10.f64));
	// fmadds f7,f9,f13,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f12
	cr6.compare(ctx.f7.f64, ctx.f12.f64);
	// bge cr6,0x8256a33c
	if (!cr6.lt) goto loc_8256A33C;
	// lfs f0,44(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x8256a318
	if (!cr6.eq) goto loc_8256A318;
	// lfs f0,40(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8256a33c
	if (cr6.eq) goto loc_8256A33C;
loc_8256A318:
	// lfs f0,40(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x8256a330
	if (!cr6.eq) goto loc_8256A330;
	// li r11,4
	r11.s64 = 4;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// b 0x8256a784
	goto loc_8256A784;
loc_8256A330:
	// li r11,3
	r11.s64 = 3;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// b 0x8256a784
	goto loc_8256A784;
loc_8256A33C:
	// lfs f0,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bgt cr6,0x8256a35c
	if (cr6.gt) goto loc_8256A35C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8256a784
	if (cr6.lt) goto loc_8256A784;
loc_8256A35C:
	// li r11,0
	r11.s64 = 0;
	// stfs f31,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// b 0x8256a784
	goto loc_8256A784;
loc_8256A36C:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x8256a550
	if (!cr6.eq) goto loc_8256A550;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256A384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256a550
	if (cr6.eq) goto loc_8256A550;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r10,304
	r11.s64 = ctx.r10.s64 + 304;
	// addi r6,r9,2288
	ctx.r6.s64 = ctx.r9.s64 + 2288;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r3,32
	ctx.r3.s64 = 32;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r30,r1,144
	r30.s64 = ctx.r1.s64 + 144;
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// lvx128 v62,r11,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r5,336
	ctx.r5.s64 = 336;
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v13,99
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x9C));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v59,v13,135
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v13.u32), 0x78));
	// lvx128 v12,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v0,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// stvx128 v12,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// stvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r4,2528
	ctx.r3.s64 = ctx.r4.s64 + 2528;
	// lvx128 v58,r10,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v57,v58,135
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x78));
	// vmulfp128 v10,v57,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vpermwi128 v9,v58,99
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x9C));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// vor128 v8,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// addi r9,r11,2240
	ctx.r9.s64 = r11.s64 + 2240;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r8,-31648
	ctx.r5.s64 = ctx.r8.s64 + -31648;
	// addi r4,r6,-31664
	ctx.r4.s64 = ctx.r6.s64 + -31664;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v7,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r9,44
	ctx.r9.s64 = 44;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v11,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// vnmsubfp v6,v9,v0,v10
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// addi r30,r6,2256
	r30.s64 = ctx.r6.s64 + 2256;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// vmsum3fp128 v56,v6,v6
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v6.f32), 0xEF));
	// vrsqrtefp128 v55,v56
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v5,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vcmpeqfp128 v4,v55,v62
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v3,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vsel v0,v3,v7,v4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// vmulfp128 v2,v0,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v1,v63,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v31,v5,v2,v11
	simde_mm_store_ps(v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v30,v31,v1,v0
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v63,v6,v30
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(v30.f32)));
	// vpermwi128 v54,v63,99
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v29,v63,135
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmulfp128 v28,v59,v54
	simde_mm_store_ps(v28.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v54.f32)));
	// vnmsubfp v27,v8,v29,v28
	simde_mm_store_ps(v27.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(v28.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v27,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v53,r7,r9
	temp.u32 = ctx.r7.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v26,v53,0
	simde_mm_store_si128((simde__m128i*)v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// vmaddfp v25,v13,v26,v12
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v26.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v25,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,128(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,164(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 164);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8256A4C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,128(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,172(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 172);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8256A4E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8256a508
	if (cr6.eq) goto loc_8256A508;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x8256a508
	if (cr6.lt) goto loc_8256A508;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x825617e8
	ctx.lr = 0x8256A508;
	sub_825617E8(ctx, base);
loc_8256A508:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256A51C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,128(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8256A534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8256A54C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8256a784
	goto loc_8256A784;
loc_8256A550:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8256a680
	if (!cr6.eq) goto loc_8256A680;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256A570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256a680
	if (cr6.eq) goto loc_8256A680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r10,r10,2288
	ctx.r10.s64 = ctx.r10.s64 + 2288;
	// lfs f13,328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 328);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,324(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 324);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f9,320(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 320);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32680(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32680);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f11,f0,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f10.f64));
	// fmadds f7,f9,f13,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f12
	cr6.compare(ctx.f7.f64, ctx.f12.f64);
	// bgt cr6,0x8256a770
	if (cr6.gt) goto loc_8256A770;
	// lwz r3,128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lfs f0,132(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 132);
	f0.f64 = double(temp.f32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fabs f31,f0
	f31.u64 = f0.u64 & ~0x8000000000000000;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,192(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f12,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lwz r7,140(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 140);
	// fmuls f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v52,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v51,v52,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// vmulfp128 v1,v63,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v51.f32)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8256A604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,336
	ctx.r5.s64 = 336;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lfs f9,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v50,r3,r5
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lfs f8,192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 192);
	ctx.f8.f64 = double(temp.f32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// fmuls f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// lwz r8,152(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// fmuls f6,f7,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 * f31.f64));
	// fneg f5,f6
	ctx.f5.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v49,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vmulfp128 v1,v50,v48
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v48.f32)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8256A658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8256a784
	if (cr6.eq) goto loc_8256A784;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x8256a784
	if (cr6.lt) goto loc_8256A784;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x825617e8
	ctx.lr = 0x8256A67C;
	sub_825617E8(ctx, base);
	// b 0x8256a784
	goto loc_8256A784;
loc_8256A680:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8256a784
	if (!cr6.eq) goto loc_8256A784;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,292(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 292);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f8,296(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 296);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// lfs f6,288(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 288);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f12,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fcmpu cr6,f2,f11
	cr6.compare(ctx.f2.f64, ctx.f11.f64);
	// bgt cr6,0x8256a770
	if (cr6.gt) goto loc_8256A770;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8256a770
	if (cr6.eq) goto loc_8256A770;
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x8256a770
	if (cr6.eq) goto loc_8256A770;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,136(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8256a770
	if (!cr6.gt) goto loc_8256A770;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,132(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 132);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f13,36(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bne cr6,0x8256a714
	if (!cr6.eq) goto loc_8256A714;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_8256A714:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,8884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8256a784
	if (!cr6.gt) goto loc_8256A784;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r3,128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// addi r6,r7,2288
	ctx.r6.s64 = ctx.r7.s64 + 2288;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,112(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 112);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v47,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v46,v47,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// vmulfp128 v1,v63,v46
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v46.f32)));
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8256A76C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8256a784
	goto loc_8256A784;
loc_8256A770:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256A784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256A784:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_8256A7A4"))) PPC_WEAK_FUNC(sub_8256A7A4);
PPC_FUNC_IMPL(__imp__sub_8256A7A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A7A8"))) PPC_WEAK_FUNC(sub_8256A7A8);
PPC_FUNC_IMPL(__imp__sub_8256A7A8) {
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
	// bl 0x825640f8
	ctx.lr = 0x8256A7C0;
	sub_825640F8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// lfs f0,-332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	f0.f64 = double(temp.f32);
	// lfs f13,-1684(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1684);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-4484
	ctx.r5.s64 = ctx.r6.s64 + -4484;
	// lfs f12,30712(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-16776(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -16776);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f11,36(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f10,40(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
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

__attribute__((alias("__imp__sub_8256A824"))) PPC_WEAK_FUNC(sub_8256A824);
PPC_FUNC_IMPL(__imp__sub_8256A824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A828"))) PPC_WEAK_FUNC(sub_8256A828);
PPC_FUNC_IMPL(__imp__sub_8256A828) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23468(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23468);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256A834"))) PPC_WEAK_FUNC(sub_8256A834);
PPC_FUNC_IMPL(__imp__sub_8256A834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A838"))) PPC_WEAK_FUNC(sub_8256A838);
PPC_FUNC_IMPL(__imp__sub_8256A838) {
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
	// bl 0x825641a0
	ctx.lr = 0x8256A850;
	sub_825641A0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-4484
	ctx.r10.s64 = r11.s64 + -4484;
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

__attribute__((alias("__imp__sub_8256A874"))) PPC_WEAK_FUNC(sub_8256A874);
PPC_FUNC_IMPL(__imp__sub_8256A874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A878"))) PPC_WEAK_FUNC(sub_8256A878);
PPC_FUNC_IMPL(__imp__sub_8256A878) {
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x8256A88C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256a8a8
	if (cr6.eq) goto loc_8256A8A8;
	// bl 0x8256a7a8
	ctx.lr = 0x8256A898;
	sub_8256A7A8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8256A8A8:
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

__attribute__((alias("__imp__sub_8256A8BC"))) PPC_WEAK_FUNC(sub_8256A8BC);
PPC_FUNC_IMPL(__imp__sub_8256A8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A8C0"))) PPC_WEAK_FUNC(sub_8256A8C0);
PPC_FUNC_IMPL(__imp__sub_8256A8C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r9,-4508
	ctx.r7.s64 = ctx.r9.s64 + -4508;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256A8FC"))) PPC_WEAK_FUNC(sub_8256A8FC);
PPC_FUNC_IMPL(__imp__sub_8256A8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A900"))) PPC_WEAK_FUNC(sub_8256A900);
PPC_FUNC_IMPL(__imp__sub_8256A900) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-4508
	ctx.r10.s64 = r11.s64 + -4508;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8256A92C;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256a944
	if (cr6.eq) goto loc_8256A944;
	// bl 0x82130588
	ctx.lr = 0x8256A940;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256A944:
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

__attribute__((alias("__imp__sub_8256A95C"))) PPC_WEAK_FUNC(sub_8256A95C);
PPC_FUNC_IMPL(__imp__sub_8256A95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A960"))) PPC_WEAK_FUNC(sub_8256A960);
PPC_FUNC_IMPL(__imp__sub_8256A960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// lfs f0,28(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lfs f12,32(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// stfs f11,52(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256A984"))) PPC_WEAK_FUNC(sub_8256A984);
PPC_FUNC_IMPL(__imp__sub_8256A984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256A988"))) PPC_WEAK_FUNC(sub_8256A988);
PPC_FUNC_IMPL(__imp__sub_8256A988) {
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
	ctx.lr = 0x8256A990;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23468
	r31.s64 = r11.s64 + -23468;
	// lwz r11,-23468(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23468);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256aafc
	if (!cr6.eq) goto loc_8256AAFC;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8256A9B0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256a9c4
	if (cr6.eq) goto loc_8256A9C4;
	// bl 0x821d5408
	ctx.lr = 0x8256A9C0;
	sub_821D5408(ctx, base);
	// b 0x8256a9c8
	goto loc_8256A9C8;
loc_8256A9C4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8256A9C8:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-4468
	ctx.r7.s64 = ctx.r10.s64 + -4468;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32169
	ctx.r8.s64 = -2108227584;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-22408
	ctx.r4.s64 = ctx.r8.s64 + -22408;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r8,r3,8544
	ctx.r8.s64 = ctx.r3.s64 + 8544;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r10,36
	ctx.r10.s64 = 36;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// addi r10,r9,8568
	ctx.r10.s64 = ctx.r9.s64 + 8568;
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lis r30,-32114
	r30.s64 = -2104623104;
	// li r9,40
	ctx.r9.s64 = 40;
	// addi r6,r7,8592
	ctx.r6.s64 = ctx.r7.s64 + 8592;
	// addi r29,r4,8616
	r29.s64 = ctx.r4.s64 + 8616;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// addi r3,r3,8640
	ctx.r3.s64 = ctx.r3.s64 + 8640;
	// addi r5,r5,8664
	ctx.r5.s64 = ctx.r5.s64 + 8664;
	// lwz r4,-23488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23488);
	// li r11,44
	r11.s64 = 44;
	// li r8,24
	ctx.r8.s64 = 24;
	// li r7,28
	ctx.r7.s64 = 28;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8256aa94
	if (!cr6.eq) goto loc_8256AA94;
	// bl 0x82564488
	ctx.lr = 0x8256AA90;
	sub_82564488(ctx, base);
	// lwz r4,-23488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23488);
loc_8256AA94:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8256AAA0;
	sub_821D4458(ctx, base);
	// lwz r11,-23488(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23488);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8256AAB8;
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
	ctx.lr = 0x8256AAD4;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,8688
	ctx.r4.s64 = ctx.r8.s64 + 8688;
	// bl 0x821d4b00
	ctx.lr = 0x8256AAE4;
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
	ctx.lr = 0x8256AAFC;
	sub_821C0548(ctx, base);
loc_8256AAFC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8256AB04"))) PPC_WEAK_FUNC(sub_8256AB04);
PPC_FUNC_IMPL(__imp__sub_8256AB04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256AB08"))) PPC_WEAK_FUNC(sub_8256AB08);
PPC_FUNC_IMPL(__imp__sub_8256AB08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-4448
	ctx.r10.s64 = r11.s64 + -4448;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8256AB18"))) PPC_WEAK_FUNC(sub_8256AB18);
PPC_FUNC_IMPL(__imp__sub_8256AB18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-4448
	ctx.r9.s64 = r11.s64 + -4448;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256AB30"))) PPC_WEAK_FUNC(sub_8256AB30);
PPC_FUNC_IMPL(__imp__sub_8256AB30) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-4448
	ctx.r10.s64 = r11.s64 + -4448;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8256AB5C;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256ab74
	if (cr6.eq) goto loc_8256AB74;
	// bl 0x82130588
	ctx.lr = 0x8256AB70;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256AB74:
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

__attribute__((alias("__imp__sub_8256AB8C"))) PPC_WEAK_FUNC(sub_8256AB8C);
PPC_FUNC_IMPL(__imp__sub_8256AB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256AB90"))) PPC_WEAK_FUNC(sub_8256AB90);
PPC_FUNC_IMPL(__imp__sub_8256AB90) {
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
	// bl 0x821d2970
	ctx.lr = 0x8256ABB0;
	sub_821D2970(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,-4432
	ctx.r8.s64 = r11.s64 + -4432;
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - r30.s64;
loc_8256ABD0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8256abd0
	if (!cr6.eq) goto loc_8256ABD0;
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

__attribute__((alias("__imp__sub_8256AC00"))) PPC_WEAK_FUNC(sub_8256AC00);
PPC_FUNC_IMPL(__imp__sub_8256AC00) {
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
	ctx.lr = 0x8256AC18;
	sub_821D2970(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-4432
	ctx.r10.s64 = r11.s64 + -4432;
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

__attribute__((alias("__imp__sub_8256AC3C"))) PPC_WEAK_FUNC(sub_8256AC3C);
PPC_FUNC_IMPL(__imp__sub_8256AC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256AC40"))) PPC_WEAK_FUNC(sub_8256AC40);
PPC_FUNC_IMPL(__imp__sub_8256AC40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-4432
	ctx.r10.s64 = r11.s64 + -4432;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2810
	sub_821D2810(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8256AC50"))) PPC_WEAK_FUNC(sub_8256AC50);
PPC_FUNC_IMPL(__imp__sub_8256AC50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256AC60"))) PPC_WEAK_FUNC(sub_8256AC60);
PPC_FUNC_IMPL(__imp__sub_8256AC60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// bne 0x8256aca4
	if (!cr0.eq) goto loc_8256ACA4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256AC90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_8256ACA4:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256ACB8"))) PPC_WEAK_FUNC(sub_8256ACB8);
PPC_FUNC_IMPL(__imp__sub_8256ACB8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-4432
	ctx.r10.s64 = r11.s64 + -4432;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2810
	ctx.lr = 0x8256ACE4;
	sub_821D2810(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256acfc
	if (cr6.eq) goto loc_8256ACFC;
	// bl 0x82130588
	ctx.lr = 0x8256ACF8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256ACFC:
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

__attribute__((alias("__imp__sub_8256AD14"))) PPC_WEAK_FUNC(sub_8256AD14);
PPC_FUNC_IMPL(__imp__sub_8256AD14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256AD18"))) PPC_WEAK_FUNC(sub_8256AD18);
PPC_FUNC_IMPL(__imp__sub_8256AD18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,-4124
	ctx.r6.s64 = ctx.r7.s64 + -4124;
	// lfs f0,-12084(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12084);
	f0.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f13,-9152(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -9152);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stfs f13,24(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256AD60"))) PPC_WEAK_FUNC(sub_8256AD60);
PPC_FUNC_IMPL(__imp__sub_8256AD60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256AD70"))) PPC_WEAK_FUNC(sub_8256AD70);
PPC_FUNC_IMPL(__imp__sub_8256AD70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-4124
	ctx.r10.s64 = r11.s64 + -4124;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8256AD80"))) PPC_WEAK_FUNC(sub_8256AD80);
PPC_FUNC_IMPL(__imp__sub_8256AD80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,20(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f11,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,24(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256ADA8"))) PPC_WEAK_FUNC(sub_8256ADA8);
PPC_FUNC_IMPL(__imp__sub_8256ADA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8256ADB0;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9cc
	ctx.lr = 0x8256ADB8;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// lwz r31,128(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r26,r31,272
	r26.s64 = r31.s64 + 272;
	// beq cr6,0x8256b194
	if (cr6.eq) goto loc_8256B194;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r27,r29,4
	r27.s64 = r29.s64 + 4;
	// lfs f30,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lfs f25,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	f25.f64 = double(temp.f32);
	// fcmpu cr6,f11,f30
	cr6.compare(ctx.f11.f64, f30.f64);
	// lfs f26,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f26.f64 = double(temp.f32);
	// ble cr6,0x8256b070
	if (!cr6.gt) goto loc_8256B070;
	// lfs f0,296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,312(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f5,344(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 344);
	ctx.f5.f64 = double(temp.f32);
	// lfs f10,292(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 292);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 * f0.f64));
	// lfs f9,308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 308);
	ctx.f9.f64 = double(temp.f32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f6,328(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 328);
	ctx.f6.f64 = double(temp.f32);
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lfs f8,288(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 288);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// lfs f7,304(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 304);
	ctx.f7.f64 = double(temp.f32);
	// addi r28,r10,29952
	r28.s64 = ctx.r10.s64 + 29952;
	// lfs f2,324(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 324);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,340(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 340);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,320(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// lfs f6,336(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 336);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f9,f10,f12
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f12.f64));
	// lfs f28,8884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f28.f64 = double(temp.f32);
	// fmadds f3,f1,f10,f3
	ctx.f3.f64 = double(float(ctx.f1.f64 * ctx.f10.f64 + ctx.f3.f64));
	// lfs f27,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f27.f64 = double(temp.f32);
	// fmadds f4,f2,f10,f4
	ctx.f4.f64 = double(float(ctx.f2.f64 * ctx.f10.f64 + ctx.f4.f64));
	// fmadds f0,f7,f8,f5
	f0.f64 = double(float(ctx.f7.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f29,f8,f6,f3
	f29.f64 = double(float(ctx.f8.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f31,f8,f13,f4
	f31.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f4.f64));
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f28
	cr6.compare(ctx.f12.f64, f28.f64);
	// ble cr6,0x8256af20
	if (!cr6.gt) goto loc_8256AF20;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x8256ae98
	if (!cr6.lt) goto loc_8256AE98;
	// fmr f13,f27
	ctx.f13.f64 = f27.f64;
	// b 0x8256aeac
	goto loc_8256AEAC;
loc_8256AE98:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8256aea8
	if (!cr6.gt) goto loc_8256AEA8;
	// fmr f13,f26
	ctx.f13.f64 = f26.f64;
	// b 0x8256aeac
	goto loc_8256AEAC;
loc_8256AEA8:
	// fmr f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f30.f64;
loc_8256AEAC:
	// lfs f10,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// fabs f9,f0
	ctx.f9.u64 = f0.u64 & ~0x8000000000000000;
	// fmuls f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f7,32(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,48(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	ctx.f6.f64 = double(temp.f32);
	// lfs f13,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f5,f9,f0
	ctx.f5.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fneg f4,f8
	ctx.f4.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// fnmsubs f3,f0,f7,f4
	ctx.f3.f64 = double(float(-(f0.f64 * ctx.f7.f64 - ctx.f4.f64)));
	// fnmsubs f1,f5,f6,f3
	ctx.f1.f64 = double(float(-(ctx.f5.f64 * ctx.f6.f64 - ctx.f3.f64)));
	// fabs f2,f1
	ctx.f2.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fmuls f13,f2,f13
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x8256aef0
	if (!cr6.gt) goto loc_8256AEF0;
	// lfs f13,12(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
loc_8256AEF0:
	// fcmpu cr6,f12,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f26.f64);
	// bge cr6,0x8256aefc
	if (!cr6.lt) goto loc_8256AEFC;
	// fmuls f1,f1,f12
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
loc_8256AEFC:
	// fcmpu cr6,f11,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, f26.f64);
	// beq cr6,0x8256af08
	if (cr6.eq) goto loc_8256AF08;
	// fmuls f1,f11,f1
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
loc_8256AF08:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256AF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256AF20:
	// fabs f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// ble cr6,0x8256afc8
	if (!cr6.gt) goto loc_8256AFC8;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bge cr6,0x8256af3c
	if (!cr6.lt) goto loc_8256AF3C;
	// fmr f0,f27
	f0.f64 = f27.f64;
	// b 0x8256af50
	goto loc_8256AF50;
loc_8256AF3C:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x8256af4c
	if (!cr6.gt) goto loc_8256AF4C;
	// fmr f0,f26
	f0.f64 = f26.f64;
	// b 0x8256af50
	goto loc_8256AF50;
loc_8256AF4C:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_8256AF50:
	// lfs f12,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fabs f11,f31
	ctx.f11.u64 = f31.u64 & ~0x8000000000000000;
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f9,36(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f7,f11,f31
	ctx.f7.f64 = double(float(ctx.f11.f64 * f31.f64));
	// fneg f6,f10
	ctx.f6.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fnmsubs f5,f9,f31,f6
	ctx.f5.f64 = double(float(-(ctx.f9.f64 * f31.f64 - ctx.f6.f64)));
	// fnmsubs f1,f7,f8,f5
	ctx.f1.f64 = double(float(-(ctx.f7.f64 * ctx.f8.f64 - ctx.f5.f64)));
	// fabs f4,f1
	ctx.f4.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fcmpu cr6,f3,f13
	cr6.compare(ctx.f3.f64, ctx.f13.f64);
	// ble cr6,0x8256af94
	if (!cr6.gt) goto loc_8256AF94;
	// lfs f0,12(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f31
	f0.f64 = double(float(f0.f64 * f31.f64));
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
loc_8256AF94:
	// fcmpu cr6,f13,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f26.f64);
	// bge cr6,0x8256afa0
	if (!cr6.lt) goto loc_8256AFA0;
	// fmuls f1,f1,f13
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
loc_8256AFA0:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// beq cr6,0x8256afb0
	if (cr6.eq) goto loc_8256AFB0;
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64));
loc_8256AFB0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256AFC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256AFC8:
	// fabs f13,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f29.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f28
	cr6.compare(ctx.f13.f64, f28.f64);
	// ble cr6,0x8256b070
	if (!cr6.gt) goto loc_8256B070;
	// fcmpu cr6,f29,f30
	cr6.compare(f29.f64, f30.f64);
	// bge cr6,0x8256afe4
	if (!cr6.lt) goto loc_8256AFE4;
	// fmr f0,f27
	f0.f64 = f27.f64;
	// b 0x8256aff8
	goto loc_8256AFF8;
loc_8256AFE4:
	// fcmpu cr6,f29,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f29.f64, f30.f64);
	// ble cr6,0x8256aff4
	if (!cr6.gt) goto loc_8256AFF4;
	// fmr f0,f26
	f0.f64 = f26.f64;
	// b 0x8256aff8
	goto loc_8256AFF8;
loc_8256AFF4:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_8256AFF8:
	// lfs f12,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fabs f11,f29
	ctx.f11.u64 = f29.u64 & ~0x8000000000000000;
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f9,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f7,f11,f29
	ctx.f7.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fneg f6,f10
	ctx.f6.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fnmsubs f5,f9,f29,f6
	ctx.f5.f64 = double(float(-(ctx.f9.f64 * f29.f64 - ctx.f6.f64)));
	// fnmsubs f1,f7,f8,f5
	ctx.f1.f64 = double(float(-(ctx.f7.f64 * ctx.f8.f64 - ctx.f5.f64)));
	// fabs f4,f1
	ctx.f4.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fcmpu cr6,f3,f13
	cr6.compare(ctx.f3.f64, ctx.f13.f64);
	// ble cr6,0x8256b03c
	if (!cr6.gt) goto loc_8256B03C;
	// lfs f0,12(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f29
	f0.f64 = double(float(f0.f64 * f29.f64));
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
loc_8256B03C:
	// fcmpu cr6,f13,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f26.f64);
	// bge cr6,0x8256b048
	if (!cr6.lt) goto loc_8256B048;
	// fmuls f1,f1,f13
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
loc_8256B048:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// beq cr6,0x8256b058
	if (cr6.eq) goto loc_8256B058;
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64));
loc_8256B058:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B070:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-31384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f25,f0
	cr6.compare(f25.f64, f0.f64);
	// ble cr6,0x8256b14c
	if (!cr6.gt) goto loc_8256B14C;
	// fmuls f0,f25,f25
	f0.f64 = double(float(f25.f64 * f25.f64));
	// lfs f13,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r10,320
	ctx.r10.s64 = 320;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fneg f9,f10
	ctx.f9.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v127,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// ble cr6,0x8256b11c
	if (!cr6.gt) goto loc_8256B11C;
	// bl 0x8255ad28
	ctx.lr = 0x8256B0C8;
	sub_8255AD28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8256b11c
	if (cr6.eq) goto loc_8256B11C;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fdivs f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 / ctx.f9.f64));
	// fsubs f7,f26,f8
	ctx.f7.f64 = double(float(f26.f64 - ctx.f8.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v127,v127,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v59.f32)));
loc_8256B11C:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// bge cr6,0x8256b134
	if (!cr6.lt) goto loc_8256B134;
	// lvlx128 v58,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v127,v127,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v57.f32)));
loc_8256B134:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B14C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B14C:
	// fcmpu cr6,f25,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(f25.f64, f26.f64);
	// ble cr6,0x8256b194
	if (!cr6.gt) goto loc_8256B194;
	// lfs f0,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	f0.f64 = double(temp.f32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f13,20(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lvx128 v56,r0,r26
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,128(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// fmuls f11,f12,f25
	ctx.f11.f64 = double(float(ctx.f12.f64 * f25.f64));
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v55,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmulfp128 v1,v56,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v54.f32)));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8256B194;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B194:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba18
	ctx.lr = 0x8256B1A8;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8256B1AC"))) PPC_WEAK_FUNC(sub_8256B1AC);
PPC_FUNC_IMPL(__imp__sub_8256B1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B1B0"))) PPC_WEAK_FUNC(sub_8256B1B0);
PPC_FUNC_IMPL(__imp__sub_8256B1B0) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-4124
	ctx.r10.s64 = r11.s64 + -4124;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8256B1DC;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256b1f4
	if (cr6.eq) goto loc_8256B1F4;
	// bl 0x82130588
	ctx.lr = 0x8256B1F0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256B1F4:
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

__attribute__((alias("__imp__sub_8256B20C"))) PPC_WEAK_FUNC(sub_8256B20C);
PPC_FUNC_IMPL(__imp__sub_8256B20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B210"))) PPC_WEAK_FUNC(sub_8256B210);
PPC_FUNC_IMPL(__imp__sub_8256B210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,30712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f12,3732(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// addi r11,r11,-13164
	r11.s64 = r11.s64 + -13164;
	// lfs f11,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f12,20(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f11,24(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// lfs f0,-332(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -332);
	f0.f64 = double(temp.f32);
	// lfs f13,31308(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-12084(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12084);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-9152(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -9152);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f12,56(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f11,64(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f10,68(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B294"))) PPC_WEAK_FUNC(sub_8256B294);
PPC_FUNC_IMPL(__imp__sub_8256B294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B298"))) PPC_WEAK_FUNC(sub_8256B298);
PPC_FUNC_IMPL(__imp__sub_8256B298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r7,r1,28
	ctx.r7.s64 = ctx.r1.s64 + 28;
	// stfs f1,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 28, temp.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,28
	ctx.r8.s64 = ctx.r1.s64 + 28;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// lvlx128 v61,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r4,r1,28
	ctx.r4.s64 = ctx.r1.s64 + 28;
	// lvx128 v0,r5,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r6,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v9,v13,v12,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vspltw128 v11,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvlx128 v60,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// stvx128 v9,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r5,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r6,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v8,v59,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v7,v8,v11,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v7,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r5,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r6,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v6,v58,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v5,v6,v10,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v5,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,64(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	f0.f64 = double(temp.f32);
	// lfs f13,64(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f1,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + f0.f64));
	// stfs f11,64(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f10,68(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,68(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 68);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f1,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f1.f64 + ctx.f10.f64));
	// stfs f7,68(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B334"))) PPC_WEAK_FUNC(sub_8256B334);
PPC_FUNC_IMPL(__imp__sub_8256B334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B338"))) PPC_WEAK_FUNC(sub_8256B338);
PPC_FUNC_IMPL(__imp__sub_8256B338) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-3804
	ctx.r9.s64 = ctx.r10.s64 + -3804;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B370"))) PPC_WEAK_FUNC(sub_8256B370);
PPC_FUNC_IMPL(__imp__sub_8256B370) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-3804
	ctx.r10.s64 = r11.s64 + -3804;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256b3b0
	if (cr6.eq) goto loc_8256B3B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B3B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B3B0:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256b3d0
	if (cr6.eq) goto loc_8256B3D0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B3D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B3D0:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256b3f0
	if (cr6.eq) goto loc_8256B3F0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B3F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B3F0:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256b410
	if (cr6.eq) goto loc_8256B410;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B410:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256b430
	if (cr6.eq) goto loc_8256B430;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B430:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256b450
	if (cr6.eq) goto loc_8256B450;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B450:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256b470
	if (cr6.eq) goto loc_8256B470;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B470:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256b490
	if (cr6.eq) goto loc_8256B490;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B490;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B490:
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

__attribute__((alias("__imp__sub_8256B4A4"))) PPC_WEAK_FUNC(sub_8256B4A4);
PPC_FUNC_IMPL(__imp__sub_8256B4A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B4A8"))) PPC_WEAK_FUNC(sub_8256B4A8);
PPC_FUNC_IMPL(__imp__sub_8256B4A8) {
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
	// bl 0x8256b370
	ctx.lr = 0x8256B4C8;
	sub_8256B370(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256b4e0
	if (cr6.eq) goto loc_8256B4E0;
	// bl 0x82130588
	ctx.lr = 0x8256B4DC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256B4E0:
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

__attribute__((alias("__imp__sub_8256B4F8"))) PPC_WEAK_FUNC(sub_8256B4F8);
PPC_FUNC_IMPL(__imp__sub_8256B4F8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-3500
	ctx.r10.s64 = r11.s64 + -3500;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x8256B520;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8256B528;
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

__attribute__((alias("__imp__sub_8256B53C"))) PPC_WEAK_FUNC(sub_8256B53C);
PPC_FUNC_IMPL(__imp__sub_8256B53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B540"))) PPC_WEAK_FUNC(sub_8256B540);
PPC_FUNC_IMPL(__imp__sub_8256B540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8256B550"))) PPC_WEAK_FUNC(sub_8256B550);
PPC_FUNC_IMPL(__imp__sub_8256B550) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-3500
	ctx.r10.s64 = r11.s64 + -3500;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x8256B580;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8256B588;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256b5a0
	if (cr6.eq) goto loc_8256B5A0;
	// bl 0x82130588
	ctx.lr = 0x8256B59C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256B5A0:
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

__attribute__((alias("__imp__sub_8256B5B8"))) PPC_WEAK_FUNC(sub_8256B5B8);
PPC_FUNC_IMPL(__imp__sub_8256B5B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-1
	r11.s64 = -65536;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B5C4"))) PPC_WEAK_FUNC(sub_8256B5C4);
PPC_FUNC_IMPL(__imp__sub_8256B5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B5C8"))) PPC_WEAK_FUNC(sub_8256B5C8);
PPC_FUNC_IMPL(__imp__sub_8256B5C8) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82590248
	ctx.lr = 0x8256B5F0;
	sub_82590248(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x8256B604;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8256b66c
	if (cr6.eq) goto loc_8256B66C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-29944
	ctx.r4.s64 = r11.s64 + -29944;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x8256B624;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8256b64c
	if (cr6.eq) goto loc_8256B64C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B64C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256B64C:
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
	ctx.lr = 0x8256B664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0260
	ctx.lr = 0x8256B66C;
	sub_821D0260(ctx, base);
loc_8256B66C:
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

__attribute__((alias("__imp__sub_8256B684"))) PPC_WEAK_FUNC(sub_8256B684);
PPC_FUNC_IMPL(__imp__sub_8256B684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B688"))) PPC_WEAK_FUNC(sub_8256B688);
PPC_FUNC_IMPL(__imp__sub_8256B688) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x8256B6B0;
	sub_82130000(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B6C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8256B6DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,112(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 112);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8256B6F0;
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

__attribute__((alias("__imp__sub_8256B708"))) PPC_WEAK_FUNC(sub_8256B708);
PPC_FUNC_IMPL(__imp__sub_8256B708) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256B734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r11,r30,-1
	xer.ca = r30.u32 > 0;
	r11.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// ble 0x8256b764
	if (!cr0.gt) goto loc_8256B764;
loc_8256B744:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8256b764
	if (cr6.eq) goto loc_8256B764;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bgt 0x8256b744
	if (cr0.gt) goto loc_8256B744;
loc_8256B764:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
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

__attribute__((alias("__imp__sub_8256B784"))) PPC_WEAK_FUNC(sub_8256B784);
PPC_FUNC_IMPL(__imp__sub_8256B784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B788"))) PPC_WEAK_FUNC(sub_8256B788);
PPC_FUNC_IMPL(__imp__sub_8256B788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B7AC"))) PPC_WEAK_FUNC(sub_8256B7AC);
PPC_FUNC_IMPL(__imp__sub_8256B7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B7B0"))) PPC_WEAK_FUNC(sub_8256B7B0);
PPC_FUNC_IMPL(__imp__sub_8256B7B0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v3,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v1.f32)));
	// lvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v2,v1
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v1.f32)));
	// vsubfp128 v63,v59,v62
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// addi r11,r1,-32
	r11.s64 = ctx.r1.s64 + -32;
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lfs f11,-3408(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3408);
	ctx.f11.f64 = double(temp.f32);
	// vpermwi128 v58,v60,135
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x78));
	// vpermwi128 v0,v60,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x9C));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v57,v63,99
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// lfs f10,-28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	ctx.f10.f64 = double(temp.f32);
	// vpermwi128 v13,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lfs f9,-24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-32(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f8.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v12,v58,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v57.f32)));
	// vnmsubfp v11,v0,v13,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-28(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-32(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	f0.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmadds f6,f10,f13,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmadds f10,f12,f9,f6
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fcmpu cr6,f10,f11
	cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// bge cr6,0x8256b830
	if (!cr6.lt) goto loc_8256B830;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8256B830:
	// vsubfp128 v63,v62,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v1.f32)));
	// addi r11,r1,-32
	r11.s64 = ctx.r1.s64 + -32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-28(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,-32(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmadds f6,f11,f13,f7
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f7.f64));
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f9,f0,f6
	f0.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f6.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8256b8dc
	if (cr6.lt) goto loc_8256B8DC;
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bgt cr6,0x8256b8dc
	if (cr6.gt) goto loc_8256B8DC;
	// vpermwi128 v56,v63,99
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// vpermwi128 v55,v61,135
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x78));
	// lfs f12,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lfs f11,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f11.f64 = double(temp.f32);
	// vpermwi128 v13,v61,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x9C));
	// lfs f9,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f9.f64 = double(temp.f32);
	// vmulfp128 v12,v55,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f5,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f7.f64));
	// fmadds f4,f11,f5,f6
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f5.f64 + ctx.f6.f64));
	// fmadds f12,f9,f8,f4
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x8256b8cc
	if (cr6.lt) goto loc_8256B8CC;
	// fadds f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bgt cr6,0x8256b8cc
	if (cr6.gt) goto loc_8256B8CC;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8256B8CC:
	// li r11,3
	r11.s64 = 3;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
loc_8256B8DC:
	// li r11,2
	r11.s64 = 2;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B8EC"))) PPC_WEAK_FUNC(sub_8256B8EC);
PPC_FUNC_IMPL(__imp__sub_8256B8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B8F0"))) PPC_WEAK_FUNC(sub_8256B8F0);
PPC_FUNC_IMPL(__imp__sub_8256B8F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lhz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lhz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// rotlwi r7,r10,4
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// rotlwi r6,r9,4
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 4);
	// rotlwi r10,r8,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 4);
	// lvx128 v3,r7,r11
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r6,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r10,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8256b7b0
	ctx.lr = 0x8256B930;
	sub_8256B7B0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B940"))) PPC_WEAK_FUNC(sub_8256B940);
PPC_FUNC_IMPL(__imp__sub_8256B940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v1,v2
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vsubfp128 v60,v3,v2
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v2.f32)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r10,r11,-31664
	ctx.r10.s64 = r11.s64 + -31664;
	// vaddfp128 v59,v61,v61
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v58,v62,135
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// vpermwi128 v57,v60,99
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x9C));
	// vpermwi128 v12,v62,99
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vpermwi128 v11,v60,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x78));
	// vrefp128 v0,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v59.f32)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vmulfp128 v9,v57,v58
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// vnmsubfp v6,v0,v10,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v7,v11,v12,v9
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v0,v6,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v56,v7,v5
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B994"))) PPC_WEAK_FUNC(sub_8256B994);
PPC_FUNC_IMPL(__imp__sub_8256B994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256B998"))) PPC_WEAK_FUNC(sub_8256B998);
PPC_FUNC_IMPL(__imp__sub_8256B998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vsubfp128 v63,v1,v2
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v2.f32)));
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// vsubfp128 v62,v3,v2
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v2.f32)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,14884(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v60,v62,99
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vpermwi128 v0,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v13,v62,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// vmulfp128 v12,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f7,0(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256B9F0"))) PPC_WEAK_FUNC(sub_8256B9F0);
PPC_FUNC_IMPL(__imp__sub_8256B9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vsubfp128 v63,v1,v2
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v2.f32)));
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// vsubfp128 v62,v3,v2
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v2.f32)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,14884(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v60,v62,99
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vpermwi128 v0,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v13,v62,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// vmulfp128 v12,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-8(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f7,0(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256BA48"))) PPC_WEAK_FUNC(sub_8256BA48);
PPC_FUNC_IMPL(__imp__sub_8256BA48) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister v31{};
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
	// bl 0x823d91f4
	ctx.lr = 0x8256BA50;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// vsubfp128 v127,v1,v2
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vsubfp128 v126,v3,v2
	simde_mm_store_ps(v126.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v2.f32)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// vor v7,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
	// addi r28,r11,-31664
	r28.s64 = r11.s64 + -31664;
	// vor v6,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// li r27,16
	r27.s64 = 16;
	// vor v5,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lvx128 v13,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v1,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v3,r30,r27
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// vaddfp128 v60,v62,v62
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32)));
	// fmr f31,f1
	ctx.fpscr.disableFlushModeUnconditional();
	f31.f64 = ctx.f1.f64;
	// vsubfp128 v125,v3,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v125.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v61.f32)));
	// vpermwi128 v59,v127,135
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// vpermwi128 v58,v126,99
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x9C));
	// vpermwi128 v12,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// vpermwi128 v11,v126,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x78));
	// vmulfp128 v9,v58,v59
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// vrefp128 v0,v60
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v60.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vor128 v2,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// vnmsubfp v4,v11,v12,v9
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v13,v0,v10,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v31,v0,v13,v0
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v4,v31
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(v31.f32)));
	// bl 0x82619ae0
	ctx.lr = 0x8256BB00;
	sub_82619AE0(ctx, base);
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bne cr6,0x8256bbbc
	if (!cr6.eq) goto loc_8256BBBC;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8256bbbc
	if (cr6.gt) goto loc_8256BBBC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8256bbb4
	if (cr6.eq) goto loc_8256BBB4;
	// lvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v56,v127,135
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// vspltw128 v55,v57,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lvx128 v13,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v54,v126,99
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x9C));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// vpermwi128 v12,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// lvx128 v53,r0,r30
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v11,v126,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x78));
	// li r10,32
	ctx.r10.s64 = 32;
	// vaddfp128 v52,v55,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v55.f32)));
	// li r9,48
	ctx.r9.s64 = 48;
	// vmulfp128 v10,v54,v56
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v56.f32)));
	// lfs f13,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lvlx128 v51,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r11,0
	r11.s64 = 0;
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// sth r11,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r11.u16);
	// stfs f12,68(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// sth r8,78(r31)
	PPC_STORE_U16(r31.u32 + 78, ctx.r8.u16);
	// vmaddfp128 v53,v125,v50,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v50.f32)), simde_mm_load_ps(v53.f32)));
	// stb r7,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r7.u8);
	// sth r11,82(r31)
	PPC_STORE_U16(r31.u32 + 82, r11.u16);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// vrefp128 v0,v52
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v52.f32)));
	// vor128 v9,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vnmsubfp v8,v11,v12,v10
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v53,r31,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v6,v0,v9,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v0,v6,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v49,v8,v5
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v49,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8256BBB4:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8256bbc0
	goto loc_8256BBC0;
loc_8256BBBC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8256BBC0:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_8256BBE4"))) PPC_WEAK_FUNC(sub_8256BBE4);
PPC_FUNC_IMPL(__imp__sub_8256BBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256BBE8"))) PPC_WEAK_FUNC(sub_8256BBE8);
PPC_FUNC_IMPL(__imp__sub_8256BBE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lhz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lhz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// rotlwi r7,r10,4
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// rotlwi r6,r9,4
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 4);
	// rotlwi r10,r8,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 4);
	// lvx128 v3,r7,r11
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r6,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r10,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8256ba48
	ctx.lr = 0x8256BC28;
	sub_8256BA48(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256BC38"))) PPC_WEAK_FUNC(sub_8256BC38);
PPC_FUNC_IMPL(__imp__sub_8256BC38) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v31{};
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
	// bl 0x823d91f4
	ctx.lr = 0x8256BC40;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// vsubfp128 v127,v1,v2
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vsubfp128 v126,v3,v2
	simde_mm_store_ps(v126.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v2.f32)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// vor v7,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
	// addi r28,r11,-31664
	r28.s64 = r11.s64 + -31664;
	// vor v6,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// li r27,16
	r27.s64 = 16;
	// vor v5,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lvx128 v13,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v1,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v3,r30,r27
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// vaddfp128 v60,v62,v62
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32)));
	// li r3,0
	ctx.r3.s64 = 0;
	// vsubfp128 v125,v3,v61
	simde_mm_store_ps(v125.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v61.f32)));
	// fmr f30,f1
	ctx.fpscr.disableFlushModeUnconditional();
	f30.f64 = ctx.f1.f64;
	// vpermwi128 v59,v127,135
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// vpermwi128 v58,v126,99
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x9C));
	// vpermwi128 v12,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// vpermwi128 v11,v126,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x78));
	// vmulfp128 v9,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// vrefp128 v0,v60
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v60.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vor128 v2,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// vnmsubfp v4,v11,v12,v9
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v13,v0,v10,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v31,v0,v13,v0
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v4,v31
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(v31.f32)));
	// bl 0x82619cc8
	ctx.lr = 0x8256BCFC;
	sub_82619CC8(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lfs f12,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8256bde4
	if (cr6.eq) goto loc_8256BDE4;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bge cr6,0x8256bd24
	if (!cr6.lt) goto loc_8256BD24;
	// fcmpu cr6,f12,f30
	cr6.compare(ctx.f12.f64, f30.f64);
	// bgt cr6,0x8256bde4
	if (cr6.gt) goto loc_8256BDE4;
loc_8256BD24:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8256bddc
	if (cr6.eq) goto loc_8256BDDC;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lvlx128 v57,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// vmaddfp128 v0,v125,v56,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v56.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// ble cr6,0x8256bd64
	if (!cr6.gt) goto loc_8256BD64;
	// lfs f0,208(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x8256bd68
	goto loc_8256BD68;
loc_8256BD64:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8256BD68:
	// lvx128 v55,r0,r29
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v54,v127,135
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// vspltw128 v53,v55,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v13,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v52,v126,99
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x9C));
	// vpermwi128 v12,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// li r9,32
	ctx.r9.s64 = 32;
	// vpermwi128 v11,v126,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x78));
	// li r8,48
	ctx.r8.s64 = 48;
	// vaddfp128 v51,v53,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v53.f32)));
	// li r7,2
	ctx.r7.s64 = 2;
	// vmulfp128 v10,v52,v54
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v54.f32)));
	// fneg f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f12,64(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// sth r11,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r11.u16);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// sth r7,78(r31)
	PPC_STORE_U16(r31.u32 + 78, ctx.r7.u16);
	// stb r10,80(r31)
	PPC_STORE_U8(r31.u32 + 80, ctx.r10.u8);
	// sth r11,82(r31)
	PPC_STORE_U16(r31.u32 + 82, r11.u16);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// vrefp128 v0,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v51.f32)));
	// vor128 v9,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// vnmsubfp v8,v11,v12,v10
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v6,v0,v9,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v0,v6,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v50,v8,v5
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v50,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8256BDDC:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8256bde8
	goto loc_8256BDE8;
loc_8256BDE4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8256BDE8:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256BE10"))) PPC_WEAK_FUNC(sub_8256BE10);
PPC_FUNC_IMPL(__imp__sub_8256BE10) {
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
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lhz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lhz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// rotlwi r7,r10,4
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// rotlwi r6,r9,4
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 4);
	// rotlwi r10,r8,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 4);
	// lvx128 v1,r7,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r6,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r10,r11
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8256bc38
	ctx.lr = 0x8256BE50;
	sub_8256BC38(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256BE60"))) PPC_WEAK_FUNC(sub_8256BE60);
PPC_FUNC_IMPL(__imp__sub_8256BE60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vsubfp128 v63,v1,v2
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v2.f32)));
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// vsubfp128 v62,v3,v2
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v2.f32)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// sth r4,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r4.u16);
	// sth r5,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, ctx.r5.u16);
	// sth r6,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r6.u16);
	// lfs f12,14884(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v60,v62,99
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vpermwi128 v0,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v13,v62,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// vmulfp128 v12,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-8(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f7,0(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256BEC4"))) PPC_WEAK_FUNC(sub_8256BEC4);
PPC_FUNC_IMPL(__imp__sub_8256BEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256BEC8"))) PPC_WEAK_FUNC(sub_8256BEC8);
PPC_FUNC_IMPL(__imp__sub_8256BEC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// vsubfp128 v63,v8,v4
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vmsum3fp128 v62,v3,v5
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v5.f32), 0xEF));
	// vmsum3fp128 v61,v1,v5
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v5.f32), 0xEF));
	// li r11,16
	r11.s64 = 16;
	// vmsum3fp128 v60,v3,v6
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v6.f32), 0xEF));
	// li r10,32
	ctx.r10.s64 = 32;
	// vmsum3fp128 v59,v1,v6
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v6.f32), 0xEF));
	// li r9,48
	ctx.r9.s64 = 48;
	// vmsum3fp128 v58,v3,v7
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v7.f32), 0xEF));
	// vmsum3fp128 v57,v1,v7
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v7.f32), 0xEF));
	// vmsum3fp128 v54,v2,v5
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v5.f32), 0xEF));
	// vmsum3fp128 v53,v2,v6
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v6.f32), 0xEF));
	// vmsum3fp128 v52,v2,v7
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v7.f32), 0xEF));
	// vmsum3fp128 v56,v3,v63
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v55,v1,v63
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v51,v2,v63
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmrghw128 v50,v61,v62
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v49,v59,v60
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v48,v57,v58
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v46,v50,v54
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v45,v49,v53
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v44,v48,v52
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v47,v55,v56
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// stvx128 v46,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v43,v47,v51
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// stvx128 v43,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256BF3C"))) PPC_WEAK_FUNC(sub_8256BF3C);
PPC_FUNC_IMPL(__imp__sub_8256BF3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256BF40"))) PPC_WEAK_FUNC(sub_8256BF40);
PPC_FUNC_IMPL(__imp__sub_8256BF40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r6,r4,16
	ctx.r6.u64 = ctx.r4.u32 & 0xFFFF;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r6,65535
	cr6.compare<uint32_t>(ctx.r6.u32, 65535, xer);
	// stw r8,756(r10)
	PPC_STORE_U32(ctx.r10.u32 + 756, ctx.r8.u32);
	// bne cr6,0x8256bf94
	if (!cr6.eq) goto loc_8256BF94;
	// lis r7,0
	ctx.r7.s64 = 0;
	// addi r11,r10,628
	r11.s64 = ctx.r10.s64 + 628;
	// addi r9,r10,372
	ctx.r9.s64 = ctx.r10.s64 + 372;
	// li r10,64
	ctx.r10.s64 = 64;
	// ori r7,r7,65535
	ctx.r7.u64 = ctx.r7.u64 | 65535;
loc_8256BF6C:
	// sth r7,-384(r11)
	PPC_STORE_U16(r11.u32 + -384, ctx.r7.u16);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// sth r8,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r8.u16);
	// sth r8,-522(r11)
	PPC_STORE_U16(r11.u32 + -522, ctx.r8.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x8256bf6c
	if (!cr0.eq) goto loc_8256BF6C;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8256BF94:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r10,244
	ctx.r9.s64 = ctx.r10.s64 + 244;
	// addi r8,r10,372
	ctx.r8.s64 = ctx.r10.s64 + 372;
loc_8256BFA0:
	// lhz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// bne cr6,0x8256bfb8
	if (!cr6.eq) goto loc_8256BFB8;
	// lwz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r4,r5
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, xer);
	// beq cr6,0x8256bfe4
	if (cr6.eq) goto loc_8256BFE4;
loc_8256BFB8:
	// cmplwi cr6,r7,65535
	cr6.compare<uint32_t>(ctx.r7.u32, 65535, xer);
	// beq cr6,0x8256bff0
	if (cr6.eq) goto loc_8256BFF0;
	// lhz r7,-138(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + -138);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8256bff0
	if (cr6.eq) goto loc_8256BFF0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// blt cr6,0x8256bfa0
	if (cr6.lt) goto loc_8256BFA0;
	// li r11,-1
	r11.s64 = -1;
loc_8256BFE4:
	// stw r11,756(r10)
	PPC_STORE_U32(ctx.r10.u32 + 756, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8256BFF0:
	// addi r9,r11,122
	ctx.r9.s64 = r11.s64 + 122;
	// stw r11,756(r10)
	PPC_STORE_U32(ctx.r10.u32 + 756, r11.u32);
	// addi r8,r11,93
	ctx.r8.s64 = r11.s64 + 93;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// sthx r6,r7,r10
	PPC_STORE_U16(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u16);
	// stwx r5,r4,r10
	PPC_STORE_U32(ctx.r4.u32 + ctx.r10.u32, ctx.r5.u32);
	// ble cr6,0x8256c040
	if (!cr6.gt) goto loc_8256C040;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r11,r11,314
	r11.s64 = r11.s64 + 314;
	// addi r8,r9,314
	ctx.r8.s64 = ctx.r9.s64 + 314;
	// addi r7,r9,53
	ctx.r7.s64 = ctx.r9.s64 + 53;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r6,r10
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r10.u32);
	// lhzx r9,r5,r10
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r10.u32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// sthx r3,r4,r10
	PPC_STORE_U16(ctx.r4.u32 + ctx.r10.u32, ctx.r3.u16);
loc_8256C040:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C048"))) PPC_WEAK_FUNC(sub_8256C048);
PPC_FUNC_IMPL(__imp__sub_8256C048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,756(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 756);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8256c064
	if (cr6.eq) goto loc_8256C064;
	// addi r11,r11,53
	r11.s64 = r11.s64 + 53;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
loc_8256C064:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,16
	ctx.r3.u64 = r11.u32 & 0xFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C070"))) PPC_WEAK_FUNC(sub_8256C070);
PPC_FUNC_IMPL(__imp__sub_8256C070) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-3092
	ctx.r9.s64 = r11.s64 + -3092;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stb r10,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r10.u8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8256c0b0
	if (cr6.eq) goto loc_8256C0B0;
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// b 0x8256c0d4
	goto loc_8256C0D4;
loc_8256C0B0:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x8256C0B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256c0cc
	if (cr6.eq) goto loc_8256C0CC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825be510
	ctx.lr = 0x8256C0C8;
	sub_825BE510(ctx, base);
	// b 0x8256c0d0
	goto loc_8256C0D0;
loc_8256C0CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8256C0D0:
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
loc_8256C0D4:
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

__attribute__((alias("__imp__sub_8256C0F0"))) PPC_WEAK_FUNC(sub_8256C0F0);
PPC_FUNC_IMPL(__imp__sub_8256C0F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C104"))) PPC_WEAK_FUNC(sub_8256C104);
PPC_FUNC_IMPL(__imp__sub_8256C104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256C108"))) PPC_WEAK_FUNC(sub_8256C108);
PPC_FUNC_IMPL(__imp__sub_8256C108) {
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
	ctx.lr = 0x8256C110;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x8256c148
	if (cr6.lt) goto loc_8256C148;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256C148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256C148:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825be628
	ctx.lr = 0x8256C158;
	sub_825BE628(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8256C160"))) PPC_WEAK_FUNC(sub_8256C160);
PPC_FUNC_IMPL(__imp__sub_8256C160) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x825be5b8
	sub_825BE5B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8256C168"))) PPC_WEAK_FUNC(sub_8256C168);
PPC_FUNC_IMPL(__imp__sub_8256C168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r10,r11,2272
	ctx.r10.s64 = r11.s64 + 2272;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C17C"))) PPC_WEAK_FUNC(sub_8256C17C);
PPC_FUNC_IMPL(__imp__sub_8256C17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256C180"))) PPC_WEAK_FUNC(sub_8256C180);
PPC_FUNC_IMPL(__imp__sub_8256C180) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-3092
	ctx.r10.s64 = r11.s64 + -3092;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256c1c8
	if (cr6.eq) goto loc_8256C1C8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256C1C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256C1C8:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256c1e0
	if (cr6.eq) goto loc_8256C1E0;
	// bl 0x82130588
	ctx.lr = 0x8256C1DC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256C1E0:
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

__attribute__((alias("__imp__sub_8256C1F8"))) PPC_WEAK_FUNC(sub_8256C1F8);
PPC_FUNC_IMPL(__imp__sub_8256C1F8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-3004
	ctx.r10.s64 = r11.s64 + -3004;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x8256C220;
	sub_82130588(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8256C228;
	sub_82130588(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x8256C230;
	sub_82130588(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r9,-3092
	ctx.r8.s64 = ctx.r9.s64 + -3092;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// beq cr6,0x8256c25c
	if (cr6.eq) goto loc_8256C25C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256C25C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256C25C:
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

__attribute__((alias("__imp__sub_8256C270"))) PPC_WEAK_FUNC(sub_8256C270);
PPC_FUNC_IMPL(__imp__sub_8256C270) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lhz r9,26(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 24);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8256c2e8
	if (!cr6.lt) goto loc_8256C2E8;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// clrlwi r7,r5,16
	ctx.r7.u64 = ctx.r5.u32 & 0xFFFF;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// bge cr6,0x8256c2ac
	if (!cr6.lt) goto loc_8256C2AC;
	// sth r4,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r4.u16);
	// sth r5,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r5.u16);
	// b 0x8256c2b4
	goto loc_8256C2B4;
loc_8256C2AC:
	// sth r5,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r5.u16);
	// sth r4,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r4.u16);
loc_8256C2B4:
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 24);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 24);
	// rotlwi r9,r10,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r6,24(r11)
	PPC_STORE_U16(r11.u32 + 24, ctx.r6.u16);
	// blr 
	return;
loc_8256C2E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C2F0"))) PPC_WEAK_FUNC(sub_8256C2F0);
PPC_FUNC_IMPL(__imp__sub_8256C2F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// rlwinm r10,r6,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1FFFE;
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r8,16
	ctx.r8.s64 = 16;
	// sthx r11,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, r11.u16);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// stvx128 v63,r5,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// sth r6,32(r4)
	PPC_STORE_U16(ctx.r4.u32 + 32, ctx.r6.u16);
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C36C"))) PPC_WEAK_FUNC(sub_8256C36C);
PPC_FUNC_IMPL(__imp__sub_8256C36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256C370"))) PPC_WEAK_FUNC(sub_8256C370);
PPC_FUNC_IMPL(__imp__sub_8256C370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vsubfp128 v60,v62,v63
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8256C3C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C3D4"))) PPC_WEAK_FUNC(sub_8256C3D4);
PPC_FUNC_IMPL(__imp__sub_8256C3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256C3D8"))) PPC_WEAK_FUNC(sub_8256C3D8);
PPC_FUNC_IMPL(__imp__sub_8256C3D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r4,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FFFE;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// lhzx r11,r10,r11
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r11.u32);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// stvx128 v63,r6,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r4,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C414"))) PPC_WEAK_FUNC(sub_8256C414);
PPC_FUNC_IMPL(__imp__sub_8256C414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256C418"))) PPC_WEAK_FUNC(sub_8256C418);
PPC_FUNC_IMPL(__imp__sub_8256C418) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vsubfp128 v60,v62,v63
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lwz r7,40(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8256C46C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C47C"))) PPC_WEAK_FUNC(sub_8256C47C);
PPC_FUNC_IMPL(__imp__sub_8256C47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256C480"))) PPC_WEAK_FUNC(sub_8256C480);
PPC_FUNC_IMPL(__imp__sub_8256C480) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8256C488;
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256c4fc
	if (cr6.eq) goto loc_8256C4FC;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r30,16
	r30.s64 = 16;
loc_8256C4A8:
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r29,0(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,0(r5)
	r29.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r31,r31,r11
	r31.u64 = r31.u64 + r11.u64;
	// lvx128 v62,r31,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r31,r31,r11
	r31.u64 = r31.u64 + r11.u64;
	// lwz r29,0(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// lhz r31,32(r31)
	r31.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// stwx r31,r29,r9
	PPC_STORE_U32(r29.u32 + ctx.r9.u32, r31.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lhz r31,28(r3)
	r31.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// cmpw cr6,r8,r31
	cr6.compare<int32_t>(ctx.r8.s32, r31.s32, xer);
	// blt cr6,0x8256c4a8
	if (cr6.lt) goto loc_8256C4A8;
loc_8256C4FC:
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// sth r11,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, r11.u16);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8256C508"))) PPC_WEAK_FUNC(sub_8256C508);
PPC_FUNC_IMPL(__imp__sub_8256C508) {
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
	// bl 0x8256c1f8
	ctx.lr = 0x8256C528;
	sub_8256C1F8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256c540
	if (cr6.eq) goto loc_8256C540;
	// bl 0x82130588
	ctx.lr = 0x8256C53C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256C540:
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

__attribute__((alias("__imp__sub_8256C558"))) PPC_WEAK_FUNC(sub_8256C558);
PPC_FUNC_IMPL(__imp__sub_8256C558) {
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
	ctx.lr = 0x8256C560;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8256c070
	ctx.lr = 0x8256C580;
	sub_8256C070(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r30,0
	r30.s64 = 0;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// addi r10,r11,-2916
	ctx.r10.s64 = r11.s64 + -2916;
	// stb r30,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r30.u8);
	// rlwinm r29,r28,1,15,30
	r29.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0x1FFFE;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130528
	ctx.lr = 0x8256C5A4;
	sub_82130528(ctx, base);
	// li r9,-1
	ctx.r9.s64 = -1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// bl 0x823d9890
	ctx.lr = 0x8256C5C0;
	sub_823D9890(ctx, base);
	// rlwinm r11,r27,30,18,31
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 30) & 0x3FFF;
	// lis r8,8191
	ctx.r8.s64 = 536805376;
	// mr r29,r11
	r29.u64 = r11.u64;
	// sth r11,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r11.u16);
	// ori r7,r8,65535
	ctx.r7.u64 = ctx.r8.u64 | 65535;
	// rlwinm r3,r29,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// ble cr6,0x8256c5e4
	if (!cr6.gt) goto loc_8256C5E4;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8256C5E4:
	// bl 0x82130528
	ctx.lr = 0x8256C5E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256c628
	if (cr6.eq) goto loc_8256C628;
	// addic. r10,r29,-1
	xer.ca = r29.u32 > 0;
	ctx.r10.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// blt 0x8256c610
	if (cr0.lt) goto loc_8256C610;
loc_8256C5FC:
	// sth r30,0(r11)
	PPC_STORE_U16(r11.u32 + 0, r30.u16);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r30,2(r11)
	PPC_STORE_U16(r11.u32 + 2, r30.u16);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bge 0x8256c5fc
	if (!cr0.lt) goto loc_8256C5FC;
loc_8256C610:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// sth r30,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r30.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8256C628:
	// mr r11,r30
	r11.u64 = r30.u64;
	// sth r30,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r30.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256C640"))) PPC_WEAK_FUNC(sub_8256C640);
PPC_FUNC_IMPL(__imp__sub_8256C640) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-2916
	ctx.r10.s64 = r11.s64 + -2916;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8256C668;
	sub_82130588(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x8256C670;
	sub_82130588(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r9,-3092
	ctx.r8.s64 = ctx.r9.s64 + -3092;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// beq cr6,0x8256c69c
	if (cr6.eq) goto loc_8256C69C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256C69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256C69C:
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

__attribute__((alias("__imp__sub_8256C6B0"))) PPC_WEAK_FUNC(sub_8256C6B0);
PPC_FUNC_IMPL(__imp__sub_8256C6B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lhz r9,34(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 34);
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x8256c728
	if (!cr6.lt) goto loc_8256C728;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// clrlwi r7,r5,16
	ctx.r7.u64 = ctx.r5.u32 & 0xFFFF;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// bge cr6,0x8256c6ec
	if (!cr6.lt) goto loc_8256C6EC;
	// sth r4,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r4.u16);
	// sth r5,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r5.u16);
	// b 0x8256c6f4
	goto loc_8256C6F4;
loc_8256C6EC:
	// sth r5,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r5.u16);
	// sth r4,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r4.u16);
loc_8256C6F4:
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// rotlwi r9,r10,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r6,32(r11)
	PPC_STORE_U16(r11.u32 + 32, ctx.r6.u16);
	// blr 
	return;
loc_8256C728:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C730"))) PPC_WEAK_FUNC(sub_8256C730);
PPC_FUNC_IMPL(__imp__sub_8256C730) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r9,r6,1,15,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0x1FFFE;
	// li r8,1
	ctx.r8.s64 = 1;
	// clrlwi r11,r6,16
	r11.u64 = ctx.r6.u32 & 0xFFFF;
	// sthx r8,r9,r10
	PPC_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u16);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// ble cr6,0x8256c754
	if (!cr6.gt) goto loc_8256C754;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
loc_8256C754:
	// lhz r11,24(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C764"))) PPC_WEAK_FUNC(sub_8256C764);
PPC_FUNC_IMPL(__imp__sub_8256C764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256C768"))) PPC_WEAK_FUNC(sub_8256C768);
PPC_FUNC_IMPL(__imp__sub_8256C768) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r4,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FFFE;
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// sthx r9,r10,r11
	PPC_STORE_U16(ctx.r10.u32 + r11.u32, ctx.r9.u16);
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// bne cr6,0x8256c7bc
	if (!cr6.eq) goto loc_8256C7BC;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x8256c7bc
	if (!cr6.gt) goto loc_8256C7BC;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
loc_8256C794:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8256c7bc
	if (!cr6.eq) goto loc_8256C7BC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bgt cr6,0x8256c794
	if (cr6.gt) goto loc_8256C794;
loc_8256C7BC:
	// lhz r11,24(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C7D0"))) PPC_WEAK_FUNC(sub_8256C7D0);
PPC_FUNC_IMPL(__imp__sub_8256C7D0) {
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
	ctx.lr = 0x8256C7D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8256c818
	if (!cr6.gt) goto loc_8256C818;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
loc_8256C7F0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8256C80C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8256c7f0
	if (!cr0.eq) goto loc_8256C7F0;
loc_8256C818:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8256C820"))) PPC_WEAK_FUNC(sub_8256C820);
PPC_FUNC_IMPL(__imp__sub_8256C820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8256C828;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r30,r7,16
	r30.u64 = ctx.r7.u32 & 0xFFFF;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8256c87c
	if (!cr6.gt) goto loc_8256C87C;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// subf r28,r4,r5
	r28.s64 = ctx.r5.s64 - ctx.r4.s64;
loc_8256C848:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// add r5,r28,r31
	ctx.r5.u64 = r28.u64 + r31.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8256C86C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x8256c848
	if (!cr0.eq) goto loc_8256C848;
loc_8256C87C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256C884"))) PPC_WEAK_FUNC(sub_8256C884);
PPC_FUNC_IMPL(__imp__sub_8256C884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256C888"))) PPC_WEAK_FUNC(sub_8256C888);
PPC_FUNC_IMPL(__imp__sub_8256C888) {
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
	// bl 0x8256c640
	ctx.lr = 0x8256C8A8;
	sub_8256C640(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256c8c0
	if (cr6.eq) goto loc_8256C8C0;
	// bl 0x82130588
	ctx.lr = 0x8256C8BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256C8C0:
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

__attribute__((alias("__imp__sub_8256C8D8"))) PPC_WEAK_FUNC(sub_8256C8D8);
PPC_FUNC_IMPL(__imp__sub_8256C8D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r7,r5,31
	ctx.r7.u64 = ctx.r5.u32 & 0x1;
	// lvx128 v63,r4,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f12,31492(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31492);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	f0.f64 = double(temp.f32);
	// bne cr6,0x8256c910
	if (!cr6.eq) goto loc_8256C910;
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// b 0x8256c914
	goto loc_8256C914;
loc_8256C910:
	// fmuls f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8256C914:
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r10,r5,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	// fadds f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f0,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8256c938
	if (!cr6.eq) goto loc_8256C938;
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// b 0x8256c93c
	goto loc_8256C93C;
loc_8256C938:
	// fmuls f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8256C93C:
	// lfs f11,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r11,r5,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	// fadds f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f10,36(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lfs f0,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8256c960
	if (!cr6.eq) goto loc_8256C960;
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// b 0x8256c964
	goto loc_8256C964;
loc_8256C960:
	// fmuls f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8256C964:
	// lfs f12,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f11,40(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// lfs f10,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f9,44(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256C980"))) PPC_WEAK_FUNC(sub_8256C980);
PPC_FUNC_IMPL(__imp__sub_8256C980) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,6(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// beq cr6,0x8256c9ac
	if (cr6.eq) goto loc_8256C9AC;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r10,r4
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_8256C9AC:
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8256c9d0
	if (cr6.eq) goto loc_8256C9D0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r10,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_8256C9D0:
	// lhz r11,10(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8256c9f4
	if (cr6.eq) goto loc_8256C9F4;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r10,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_8256C9F4:
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8256ca18
	if (cr6.eq) goto loc_8256CA18;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r10,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_8256CA18:
	// lhz r11,14(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8256ca3c
	if (cr6.eq) goto loc_8256CA3C;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r10,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_8256CA3C:
	// lhz r11,16(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8256ca60
	if (cr6.eq) goto loc_8256CA60;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r10,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_8256CA60:
	// lhz r11,18(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 18);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8256ca84
	if (cr6.eq) goto loc_8256CA84;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r10,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
loc_8256CA84:
	// lhz r11,20(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lfsx f0,r10,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CAAC"))) PPC_WEAK_FUNC(sub_8256CAAC);
PPC_FUNC_IMPL(__imp__sub_8256CAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256CAB0"))) PPC_WEAK_FUNC(sub_8256CAB0);
PPC_FUNC_IMPL(__imp__sub_8256CAB0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8256CAB8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82575220
	ctx.lr = 0x8256CAC4;
	sub_82575220(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,80
	ctx.r10.s64 = 80;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-2832
	ctx.r8.s64 = r11.s64 + -2832;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r6,10240
	ctx.r6.s64 = 10240;
	// stw r7,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r7.u32);
	// stb r30,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r30.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r6.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// lis r5,-32114
	ctx.r5.s64 = -2104623104;
	// addi r29,r31,104
	r29.s64 = r31.s64 + 104;
	// addi r3,r5,-23428
	ctx.r3.s64 = ctx.r5.s64 + -23428;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c0750
	ctx.lr = 0x8256CB14;
	sub_821C0750(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8256cb28
	if (!cr6.eq) goto loc_8256CB28;
	// li r11,5
	r11.s64 = 5;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8256CB28:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r29,r31,108
	r29.s64 = r31.s64 + 108;
	// addi r3,r11,-23448
	ctx.r3.s64 = r11.s64 + -23448;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c0750
	ctx.lr = 0x8256CB3C;
	sub_821C0750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8256cb50
	if (!cr6.eq) goto loc_8256CB50;
	// li r11,4
	r11.s64 = 4;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_8256CB50:
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r30.u32);
	// sth r30,128(r31)
	PPC_STORE_U16(r31.u32 + 128, r30.u16);
	// sth r30,130(r31)
	PPC_STORE_U16(r31.u32 + 130, r30.u16);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8256CB84"))) PPC_WEAK_FUNC(sub_8256CB84);
PPC_FUNC_IMPL(__imp__sub_8256CB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256CB88"))) PPC_WEAK_FUNC(sub_8256CB88);
PPC_FUNC_IMPL(__imp__sub_8256CB88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-2832
	ctx.r10.s64 = r11.s64 + -2832;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82575288
	sub_82575288(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8256CB98"))) PPC_WEAK_FUNC(sub_8256CB98);
PPC_FUNC_IMPL(__imp__sub_8256CB98) {
	PPC_FUNC_PROLOGUE();
	// sth r4,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CBA0"))) PPC_WEAK_FUNC(sub_8256CBA0);
PPC_FUNC_IMPL(__imp__sub_8256CBA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r1,32
	r11.s64 = ctx.r1.s64 + 32;
	// vspltisw128 v63,1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r10,r1,48
	ctx.r10.s64 = ctx.r1.s64 + 48;
	// vaddfp128 v62,v1,v2
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v2.f32)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,80
	ctx.r8.s64 = 80;
	// vcuxwfp128 v61,v63,1
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v63.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v2,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,48(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 48);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,32(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,56(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,40(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,52(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,36(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f7,f0,f13
	ctx.f7.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// vmulfp128 v60,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// fsubs f6,f12,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fsubs f5,f8,f7
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// stvx128 v60,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f4,f5,f8,f7
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f8.f64 : ctx.f7.f64;
	// fsubs f3,f4,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f6.f64));
	// fsel f2,f3,f4,f6
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f6.f64;
	// fmuls f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f1,96(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CC10"))) PPC_WEAK_FUNC(sub_8256CC10);
PPC_FUNC_IMPL(__imp__sub_8256CC10) {
	PPC_FUNC_PROLOGUE();
	// sth r4,128(r3)
	PPC_STORE_U16(ctx.r3.u32 + 128, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CC18"))) PPC_WEAK_FUNC(sub_8256CC18);
PPC_FUNC_IMPL(__imp__sub_8256CC18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CC28"))) PPC_WEAK_FUNC(sub_8256CC28);
PPC_FUNC_IMPL(__imp__sub_8256CC28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r9,-1
	ctx.r9.s64 = -1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// ori r7,r8,3
	ctx.r7.u64 = ctx.r8.u64 | 3;
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// rlwinm r5,r6,0,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF0;
	// sth r9,8(r5)
	PPC_STORE_U16(ctx.r5.u32 + 8, ctx.r9.u16);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CC60"))) PPC_WEAK_FUNC(sub_8256CC60);
PPC_FUNC_IMPL(__imp__sub_8256CC60) {
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
	// bl 0x821c8fe0
	ctx.lr = 0x8256CC8C;
	sub_821C8FE0(ctx, base);
	// stb r30,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r30.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8256CC98;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_8256CCB0"))) PPC_WEAK_FUNC(sub_8256CCB0);
PPC_FUNC_IMPL(__imp__sub_8256CCB0) {
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
	ctx.lr = 0x8256CCB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r11,-23388
	r29.s64 = r11.s64 + -23388;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8256CCD4;
	sub_821C8FE0(ctx, base);
	// lhz r11,48(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// lwz r30,64(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256cd04
	if (cr6.lt) goto loc_8256CD04;
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x8256CCF4;
	sub_821C9030(ctx, base);
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8256CD04:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x8256CD10;
	sub_821C8FE0(ctx, base);
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lhzx r30,r10,r11
	r30.u64 = PPC_LOAD_U16(ctx.r10.u32 + r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x8256CD24;
	sub_821C9030(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
	// bl 0x821c9030
	ctx.lr = 0x8256CD38;
	sub_821C9030(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8256CD44"))) PPC_WEAK_FUNC(sub_8256CD44);
PPC_FUNC_IMPL(__imp__sub_8256CD44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256CD48"))) PPC_WEAK_FUNC(sub_8256CD48);
PPC_FUNC_IMPL(__imp__sub_8256CD48) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// bl 0x821c8fe0
	ctx.lr = 0x8256CD6C;
	sub_821C8FE0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r10,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r10.u8);
	// bl 0x821c9030
	ctx.lr = 0x8256CD7C;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_8256CD90"))) PPC_WEAK_FUNC(sub_8256CD90);
PPC_FUNC_IMPL(__imp__sub_8256CD90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,42(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 42);
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addis r8,r11,1
	ctx.r8.s64 = r11.s64 + 65536;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r6,r7,1,15,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1FFFE;
	// sth r7,42(r3)
	PPC_STORE_U16(ctx.r3.u32 + 42, ctx.r7.u16);
	// sthx r4,r6,r9
	PPC_STORE_U16(ctx.r6.u32 + ctx.r9.u32, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CDB4"))) PPC_WEAK_FUNC(sub_8256CDB4);
PPC_FUNC_IMPL(__imp__sub_8256CDB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256CDB8"))) PPC_WEAK_FUNC(sub_8256CDB8);
PPC_FUNC_IMPL(__imp__sub_8256CDB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// li r7,0
	ctx.r7.s64 = 0;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// addi r8,r6,6
	ctx.r8.s64 = ctx.r6.s64 + 6;
loc_8256CDD4:
	// lhz r11,0(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8256ce00
	if (cr6.eq) goto loc_8256CE00;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// lbz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 4);
	// and r11,r4,r5
	r11.u64 = ctx.r4.u64 & ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256ce60
	if (!cr6.eq) goto loc_8256CE60;
loc_8256CE00:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// cmpwi cr6,r7,8
	cr6.compare<int32_t>(ctx.r7.s32, 8, xer);
	// blt cr6,0x8256cdd4
	if (cr6.lt) goto loc_8256CDD4;
	// lhz r11,26(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 26);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8256ce4c
	if (cr6.eq) goto loc_8256CE4C;
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// li r9,1
	ctx.r9.s64 = 1;
loc_8256CE24:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// slw r4,r9,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// beq cr6,0x8256ce60
	if (cr6.eq) goto loc_8256CE60;
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8256ce24
	if (!cr6.eq) goto loc_8256CE24;
loc_8256CE4C:
	// lbz r11,4(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// andc r10,r11,r5
	ctx.r10.u64 = r11.u64 & ~ctx.r5.u64;
	// stb r10,4(r6)
	PPC_STORE_U8(ctx.r6.u32 + 4, ctx.r10.u8);
	// blr 
	return;
loc_8256CE60:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CE68"))) PPC_WEAK_FUNC(sub_8256CE68);
PPC_FUNC_IMPL(__imp__sub_8256CE68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
	// lhz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// addic. r11,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	r11.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8256cea8
	if (cr0.lt) goto loc_8256CEA8;
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_8256CE90:
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x8256cea8
	if (cr6.eq) goto loc_8256CEA8;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// bge 0x8256ce90
	if (!cr0.lt) goto loc_8256CE90;
loc_8256CEA8:
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhz r8,-2(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + -2);
	// sthx r8,r11,r10
	PPC_STORE_U16(r11.u32 + ctx.r10.u32, ctx.r8.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256CEC4"))) PPC_WEAK_FUNC(sub_8256CEC4);
PPC_FUNC_IMPL(__imp__sub_8256CEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256CEC8"))) PPC_WEAK_FUNC(sub_8256CEC8);
PPC_FUNC_IMPL(__imp__sub_8256CEC8) {
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
	ctx.lr = 0x8256CED0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lhz r11,102(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 102);
	// lwz r10,112(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// lhzx r29,r9,r10
	r29.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x8256cf60
	if (cr6.eq) goto loc_8256CF60;
	// li r27,1
	r27.s64 = 1;
loc_8256CEFC:
	// lwz r11,112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// lhzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + r11.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// rlwinm r4,r9,0,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// beq cr6,0x8256cf30
	if (cr6.eq) goto loc_8256CF30;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r10,0,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// dcbt r0,r9
loc_8256CF30:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// slw r5,r27,r10
	ctx.r5.u64 = ctx.r10.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r10.u8 & 0x3F));
	// bl 0x82574ff8
	ctx.lr = 0x8256CF44;
	sub_82574FF8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8256cf6c
	if (!cr6.eq) goto loc_8256CF6C;
	// lhz r29,0(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bne cr6,0x8256cefc
	if (!cr6.eq) goto loc_8256CEFC;
loc_8256CF60:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8256CF6C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256CF78"))) PPC_WEAK_FUNC(sub_8256CF78);
PPC_FUNC_IMPL(__imp__sub_8256CF78) {
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
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// lhz r8,26(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 26);
	// rotlwi r11,r8,3
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// sth r8,102(r30)
	PPC_STORE_U16(r30.u32 + 102, ctx.r8.u16);
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r4,r7,0,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x8256cfe4
	if (cr6.eq) goto loc_8256CFE4;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r8,r9,0,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// dcbt r0,r8
loc_8256CFE4:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r9,r11,30
	ctx.r9.u64 = r11.u32 & 0x3;
	// slw r5,r10,r9
	ctx.r5.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// bl 0x82574ff8
	ctx.lr = 0x8256CFFC;
	sub_82574FF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8256d010
	if (cr6.eq) goto loc_8256D010;
	// lhz r3,102(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 102);
	// b 0x8256d01c
	goto loc_8256D01C;
loc_8256D010:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256cec8
	ctx.lr = 0x8256D01C;
	sub_8256CEC8(ctx, base);
loc_8256D01C:
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

__attribute__((alias("__imp__sub_8256D034"))) PPC_WEAK_FUNC(sub_8256D034);
PPC_FUNC_IMPL(__imp__sub_8256D034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256D038"))) PPC_WEAK_FUNC(sub_8256D038);
PPC_FUNC_IMPL(__imp__sub_8256D038) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,25952(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 25952);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8256d068
	if (!cr6.gt) goto loc_8256D068;
	// addi r11,r3,25184
	r11.s64 = ctx.r3.s64 + 25184;
loc_8256D04C:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r4,r8
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, xer);
	// beq cr6,0x8256d070
	if (cr6.eq) goto loc_8256D070;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8256d04c
	if (cr6.lt) goto loc_8256D04C;
loc_8256D068:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8256D070:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256D078"))) PPC_WEAK_FUNC(sub_8256D078);
PPC_FUNC_IMPL(__imp__sub_8256D078) {
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
	ctx.lr = 0x8256D080;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825788a8
	ctx.lr = 0x8256D08C;
	sub_825788A8(ctx, base);
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d0bc
	if (!cr6.gt) goto loc_8256D0BC;
	// addi r30,r31,22672
	r30.s64 = r31.s64 + 22672;
loc_8256D0A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825788a8
	ctx.lr = 0x8256D0A8;
	sub_825788A8(ctx, base);
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d0a0
	if (cr6.lt) goto loc_8256D0A0;
loc_8256D0BC:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d0ec
	if (!cr6.gt) goto loc_8256D0EC;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
loc_8256D0D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825788a8
	ctx.lr = 0x8256D0D8;
	sub_825788A8(ctx, base);
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d0d0
	if (cr6.lt) goto loc_8256D0D0;
loc_8256D0EC:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d11c
	if (!cr6.gt) goto loc_8256D11C;
	// addi r30,r31,22864
	r30.s64 = r31.s64 + 22864;
loc_8256D100:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825788a8
	ctx.lr = 0x8256D108;
	sub_825788A8(ctx, base);
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d100
	if (cr6.lt) goto loc_8256D100;
loc_8256D11C:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d14c
	if (!cr6.gt) goto loc_8256D14C;
	// addi r30,r31,23088
	r30.s64 = r31.s64 + 23088;
loc_8256D130:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825788a8
	ctx.lr = 0x8256D138;
	sub_825788A8(ctx, base);
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,288
	r30.s64 = r30.s64 + 288;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d130
	if (cr6.lt) goto loc_8256D130;
loc_8256D14C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8256D154"))) PPC_WEAK_FUNC(sub_8256D154);
PPC_FUNC_IMPL(__imp__sub_8256D154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256D158"))) PPC_WEAK_FUNC(sub_8256D158);
PPC_FUNC_IMPL(__imp__sub_8256D158) {
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
	ctx.lr = 0x8256D160;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d1c8
	if (!cr6.gt) goto loc_8256D1C8;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// addi r27,r31,23392
	r27.s64 = r31.s64 + 23392;
loc_8256D18C:
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d1b4
	if (cr6.eq) goto loc_8256D1B4;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8256D1A8;
	sub_8257DC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// or r28,r11,r10
	r28.u64 = r11.u64 | ctx.r10.u64;
loc_8256D1B4:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d18c
	if (cr6.lt) goto loc_8256D18C;
loc_8256D1C8:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d21c
	if (!cr6.gt) goto loc_8256D21C;
	// addi r30,r31,22672
	r30.s64 = r31.s64 + 22672;
	// addi r27,r31,23520
	r27.s64 = r31.s64 + 23520;
loc_8256D1E0:
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d208
	if (cr6.eq) goto loc_8256D208;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8256D1FC;
	sub_8257DC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// or r28,r11,r10
	r28.u64 = r11.u64 | ctx.r10.u64;
loc_8256D208:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d1e0
	if (cr6.lt) goto loc_8256D1E0;
loc_8256D21C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d270
	if (!cr6.gt) goto loc_8256D270;
	// addi r30,r31,22864
	r30.s64 = r31.s64 + 22864;
	// addi r27,r31,23521
	r27.s64 = r31.s64 + 23521;
loc_8256D234:
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d25c
	if (cr6.eq) goto loc_8256D25C;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8256D250;
	sub_8257DC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// or r28,r11,r10
	r28.u64 = r11.u64 | ctx.r10.u64;
loc_8256D25C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d234
	if (cr6.lt) goto loc_8256D234;
loc_8256D270:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d2c4
	if (!cr6.gt) goto loc_8256D2C4;
	// addi r30,r31,23088
	r30.s64 = r31.s64 + 23088;
	// addi r27,r31,23522
	r27.s64 = r31.s64 + 23522;
loc_8256D288:
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d2b0
	if (cr6.eq) goto loc_8256D2B0;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8256D2A4;
	sub_8257DC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// or r28,r11,r10
	r28.u64 = r11.u64 | ctx.r10.u64;
loc_8256D2B0:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,288
	r30.s64 = r30.s64 + 288;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d288
	if (cr6.lt) goto loc_8256D288;
loc_8256D2C4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8256D2D0"))) PPC_WEAK_FUNC(sub_8256D2D0);
PPC_FUNC_IMPL(__imp__sub_8256D2D0) {
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
	ctx.lr = 0x8256D2D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d328
	if (!cr6.gt) goto loc_8256D328;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_8256D2FC:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d314
	if (cr6.eq) goto loc_8256D314;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82475b38
	ctx.lr = 0x8256D310;
	sub_82475B38(ctx, base);
	// add r27,r3,r27
	r27.u64 = ctx.r3.u64 + r27.u64;
loc_8256D314:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d2fc
	if (cr6.lt) goto loc_8256D2FC;
loc_8256D328:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d36c
	if (!cr6.gt) goto loc_8256D36C;
	// addi r29,r31,22672
	r29.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_8256D340:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d358
	if (cr6.eq) goto loc_8256D358;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82475b38
	ctx.lr = 0x8256D354;
	sub_82475B38(ctx, base);
	// add r27,r3,r27
	r27.u64 = ctx.r3.u64 + r27.u64;
loc_8256D358:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d340
	if (cr6.lt) goto loc_8256D340;
loc_8256D36C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d3b0
	if (!cr6.gt) goto loc_8256D3B0;
	// addi r29,r31,22864
	r29.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_8256D384:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d39c
	if (cr6.eq) goto loc_8256D39C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82475b38
	ctx.lr = 0x8256D398;
	sub_82475B38(ctx, base);
	// add r27,r3,r27
	r27.u64 = ctx.r3.u64 + r27.u64;
loc_8256D39C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d384
	if (cr6.lt) goto loc_8256D384;
loc_8256D3B0:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d3f4
	if (!cr6.gt) goto loc_8256D3F4;
	// addi r29,r31,23088
	r29.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_8256D3C8:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d3e0
	if (cr6.eq) goto loc_8256D3E0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82475b38
	ctx.lr = 0x8256D3DC;
	sub_82475B38(ctx, base);
	// add r27,r3,r27
	r27.u64 = ctx.r3.u64 + r27.u64;
loc_8256D3E0:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d3c8
	if (cr6.lt) goto loc_8256D3C8;
loc_8256D3F4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256D400"))) PPC_WEAK_FUNC(sub_8256D400);
PPC_FUNC_IMPL(__imp__sub_8256D400) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,2448(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2448);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8256d430
	if (!cr6.gt) goto loc_8256D430;
	// addi r11,r3,1680
	r11.s64 = ctx.r3.s64 + 1680;
loc_8256D414:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r4,r8
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, xer);
	// beq cr6,0x8256d438
	if (cr6.eq) goto loc_8256D438;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8256d414
	if (cr6.lt) goto loc_8256D414;
loc_8256D430:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8256D438:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256D440"))) PPC_WEAK_FUNC(sub_8256D440);
PPC_FUNC_IMPL(__imp__sub_8256D440) {
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
	ctx.lr = 0x8256D448;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d498
	if (!cr6.gt) goto loc_8256D498;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_8256D46C:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d484
	if (cr6.eq) goto loc_8256D484;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825789c0
	ctx.lr = 0x8256D484;
	sub_825789C0(ctx, base);
loc_8256D484:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d46c
	if (cr6.lt) goto loc_8256D46C;
loc_8256D498:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d4dc
	if (!cr6.gt) goto loc_8256D4DC;
	// addi r29,r31,22672
	r29.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_8256D4B0:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d4c8
	if (cr6.eq) goto loc_8256D4C8;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825789c0
	ctx.lr = 0x8256D4C8;
	sub_825789C0(ctx, base);
loc_8256D4C8:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d4b0
	if (cr6.lt) goto loc_8256D4B0;
loc_8256D4DC:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d520
	if (!cr6.gt) goto loc_8256D520;
	// addi r29,r31,22864
	r29.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_8256D4F4:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d50c
	if (cr6.eq) goto loc_8256D50C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825789c0
	ctx.lr = 0x8256D50C;
	sub_825789C0(ctx, base);
loc_8256D50C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d4f4
	if (cr6.lt) goto loc_8256D4F4;
loc_8256D520:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d564
	if (!cr6.gt) goto loc_8256D564;
	// addi r29,r31,23088
	r29.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_8256D538:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d550
	if (cr6.eq) goto loc_8256D550;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825789c0
	ctx.lr = 0x8256D550;
	sub_825789C0(ctx, base);
loc_8256D550:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d538
	if (cr6.lt) goto loc_8256D538;
loc_8256D564:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256D56C"))) PPC_WEAK_FUNC(sub_8256D56C);
PPC_FUNC_IMPL(__imp__sub_8256D56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256D570"))) PPC_WEAK_FUNC(sub_8256D570);
PPC_FUNC_IMPL(__imp__sub_8256D570) {
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
	ctx.lr = 0x8256D578;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d5d8
	if (!cr6.gt) goto loc_8256D5D8;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_8256D5A4:
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d5c4
	if (cr6.eq) goto loc_8256D5C4;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82578a38
	ctx.lr = 0x8256D5C4;
	sub_82578A38(ctx, base);
loc_8256D5C4:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d5a4
	if (cr6.lt) goto loc_8256D5A4;
loc_8256D5D8:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d624
	if (!cr6.gt) goto loc_8256D624;
	// addi r30,r31,22672
	r30.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_8256D5F0:
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d610
	if (cr6.eq) goto loc_8256D610;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82578a38
	ctx.lr = 0x8256D610;
	sub_82578A38(ctx, base);
loc_8256D610:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d5f0
	if (cr6.lt) goto loc_8256D5F0;
loc_8256D624:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d670
	if (!cr6.gt) goto loc_8256D670;
	// addi r30,r31,22864
	r30.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_8256D63C:
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d65c
	if (cr6.eq) goto loc_8256D65C;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82578a38
	ctx.lr = 0x8256D65C;
	sub_82578A38(ctx, base);
loc_8256D65C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d63c
	if (cr6.lt) goto loc_8256D63C;
loc_8256D670:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d6bc
	if (!cr6.gt) goto loc_8256D6BC;
	// addi r30,r31,23088
	r30.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_8256D688:
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d6a8
	if (cr6.eq) goto loc_8256D6A8;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82578a38
	ctx.lr = 0x8256D6A8;
	sub_82578A38(ctx, base);
loc_8256D6A8:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,288
	r30.s64 = r30.s64 + 288;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256d688
	if (cr6.lt) goto loc_8256D688;
loc_8256D6BC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8256D6C4"))) PPC_WEAK_FUNC(sub_8256D6C4);
PPC_FUNC_IMPL(__imp__sub_8256D6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256D6C8"))) PPC_WEAK_FUNC(sub_8256D6C8);
PPC_FUNC_IMPL(__imp__sub_8256D6C8) {
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
	ctx.lr = 0x8256D6D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d720
	if (!cr6.gt) goto loc_8256D720;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_8256D6F4:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d70c
	if (cr6.eq) goto loc_8256D70C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82578ab0
	ctx.lr = 0x8256D70C;
	sub_82578AB0(ctx, base);
loc_8256D70C:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d6f4
	if (cr6.lt) goto loc_8256D6F4;
loc_8256D720:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d764
	if (!cr6.gt) goto loc_8256D764;
	// addi r29,r31,22672
	r29.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_8256D738:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d750
	if (cr6.eq) goto loc_8256D750;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82578ab0
	ctx.lr = 0x8256D750;
	sub_82578AB0(ctx, base);
loc_8256D750:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d738
	if (cr6.lt) goto loc_8256D738;
loc_8256D764:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d7a8
	if (!cr6.gt) goto loc_8256D7A8;
	// addi r29,r31,22864
	r29.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_8256D77C:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d794
	if (cr6.eq) goto loc_8256D794;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82578ab0
	ctx.lr = 0x8256D794;
	sub_82578AB0(ctx, base);
loc_8256D794:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d77c
	if (cr6.lt) goto loc_8256D77C;
loc_8256D7A8:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d7ec
	if (!cr6.gt) goto loc_8256D7EC;
	// addi r29,r31,23088
	r29.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_8256D7C0:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d7d8
	if (cr6.eq) goto loc_8256D7D8;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82578ab0
	ctx.lr = 0x8256D7D8;
	sub_82578AB0(ctx, base);
loc_8256D7D8:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d7c0
	if (cr6.lt) goto loc_8256D7C0;
loc_8256D7EC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256D7F4"))) PPC_WEAK_FUNC(sub_8256D7F4);
PPC_FUNC_IMPL(__imp__sub_8256D7F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256D7F8"))) PPC_WEAK_FUNC(sub_8256D7F8);
PPC_FUNC_IMPL(__imp__sub_8256D7F8) {
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
	ctx.lr = 0x8256D800;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d854
	if (!cr6.gt) goto loc_8256D854;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_8256D820:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d840
	if (cr6.eq) goto loc_8256D840;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82575b48
	ctx.lr = 0x8256D834;
	sub_82575B48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256d944
	if (!cr6.eq) goto loc_8256D944;
loc_8256D840:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d820
	if (cr6.lt) goto loc_8256D820;
loc_8256D854:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d8a0
	if (!cr6.gt) goto loc_8256D8A0;
	// addi r29,r31,22672
	r29.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_8256D86C:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d88c
	if (cr6.eq) goto loc_8256D88C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82575b48
	ctx.lr = 0x8256D880;
	sub_82575B48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256d944
	if (!cr6.eq) goto loc_8256D944;
loc_8256D88C:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d86c
	if (cr6.lt) goto loc_8256D86C;
loc_8256D8A0:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d8ec
	if (!cr6.gt) goto loc_8256D8EC;
	// addi r29,r31,22864
	r29.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_8256D8B8:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d8d8
	if (cr6.eq) goto loc_8256D8D8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82575b48
	ctx.lr = 0x8256D8CC;
	sub_82575B48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256d944
	if (!cr6.eq) goto loc_8256D944;
loc_8256D8D8:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d8b8
	if (cr6.lt) goto loc_8256D8B8;
loc_8256D8EC:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d938
	if (!cr6.gt) goto loc_8256D938;
	// addi r29,r31,23088
	r29.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_8256D904:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d924
	if (cr6.eq) goto loc_8256D924;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82575b48
	ctx.lr = 0x8256D918;
	sub_82575B48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256d944
	if (!cr6.eq) goto loc_8256D944;
loc_8256D924:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d904
	if (cr6.lt) goto loc_8256D904;
loc_8256D938:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8256D944:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8256D950"))) PPC_WEAK_FUNC(sub_8256D950);
PPC_FUNC_IMPL(__imp__sub_8256D950) {
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
	ctx.lr = 0x8256D958;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d9a0
	if (!cr6.gt) goto loc_8256D9A0;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_8256D978:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d98c
	if (cr6.eq) goto loc_8256D98C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82578dd8
	ctx.lr = 0x8256D98C;
	sub_82578DD8(ctx, base);
loc_8256D98C:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d978
	if (cr6.lt) goto loc_8256D978;
loc_8256D9A0:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256d9e0
	if (!cr6.gt) goto loc_8256D9E0;
	// addi r29,r31,22672
	r29.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_8256D9B8:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256d9cc
	if (cr6.eq) goto loc_8256D9CC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82578dd8
	ctx.lr = 0x8256D9CC;
	sub_82578DD8(ctx, base);
loc_8256D9CC:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d9b8
	if (cr6.lt) goto loc_8256D9B8;
loc_8256D9E0:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256da20
	if (!cr6.gt) goto loc_8256DA20;
	// addi r29,r31,22864
	r29.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_8256D9F8:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256da0c
	if (cr6.eq) goto loc_8256DA0C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82578dd8
	ctx.lr = 0x8256DA0C;
	sub_82578DD8(ctx, base);
loc_8256DA0C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256d9f8
	if (cr6.lt) goto loc_8256D9F8;
loc_8256DA20:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256da60
	if (!cr6.gt) goto loc_8256DA60;
	// addi r29,r31,23088
	r29.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_8256DA38:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256da4c
	if (cr6.eq) goto loc_8256DA4C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82578dd8
	ctx.lr = 0x8256DA4C;
	sub_82578DD8(ctx, base);
loc_8256DA4C:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256da38
	if (cr6.lt) goto loc_8256DA38;
loc_8256DA60:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8256DA68"))) PPC_WEAK_FUNC(sub_8256DA68);
PPC_FUNC_IMPL(__imp__sub_8256DA68) {
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
	// bl 0x823d91f4
	ctx.lr = 0x8256DA70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r11,r31,23552
	r11.s64 = r31.s64 + 23552;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,23684
	ctx.r7.s64 = 23684;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,96
	ctx.r6.s64 = 96;
	// lvx128 v61,r27,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,112
	ctx.r5.s64 = 112;
	// vsubfp128 v60,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v59,r27,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r27,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,0
	r30.s64 = 0;
	// vmsum3fp128 v57,v59,v60
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v56,v58,v60
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v55,v62,v60
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmrghw128 v54,v57,v57
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v53,v55,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v52,v53,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vor128 v49,v52,v52
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,23376(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// lvlx128 v51,r31,r7
	temp.u32 = r31.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vsubfp128 v48,v49,v50
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vaddfp128 v47,v49,v50
	simde_mm_store_ps(v47.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v48,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x8256db2c
	if (!cr6.gt) goto loc_8256DB2C;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_8256DB00:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256db18
	if (cr6.eq) goto loc_8256DB18;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82575cc0
	ctx.lr = 0x8256DB18;
	sub_82575CC0(ctx, base);
loc_8256DB18:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256db00
	if (cr6.lt) goto loc_8256DB00;
loc_8256DB2C:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256db70
	if (!cr6.gt) goto loc_8256DB70;
	// addi r29,r31,22672
	r29.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_8256DB44:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256db5c
	if (cr6.eq) goto loc_8256DB5C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82577730
	ctx.lr = 0x8256DB5C;
	sub_82577730(ctx, base);
loc_8256DB5C:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256db44
	if (cr6.lt) goto loc_8256DB44;
loc_8256DB70:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256dbb4
	if (!cr6.gt) goto loc_8256DBB4;
	// addi r29,r31,22864
	r29.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_8256DB88:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256dba0
	if (cr6.eq) goto loc_8256DBA0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82576308
	ctx.lr = 0x8256DBA0;
	sub_82576308(ctx, base);
loc_8256DBA0:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256db88
	if (cr6.lt) goto loc_8256DB88;
loc_8256DBB4:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256dbf8
	if (!cr6.gt) goto loc_8256DBF8;
	// addi r29,r31,23088
	r29.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_8256DBCC:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256dbe4
	if (cr6.eq) goto loc_8256DBE4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82576778
	ctx.lr = 0x8256DBE4;
	sub_82576778(ctx, base);
loc_8256DBE4:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256dbcc
	if (cr6.lt) goto loc_8256DBCC;
loc_8256DBF8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256DC00"))) PPC_WEAK_FUNC(sub_8256DC00);
PPC_FUNC_IMPL(__imp__sub_8256DC00) {
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
	// bl 0x823d91f4
	ctx.lr = 0x8256DC08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r11,r31,23552
	r11.s64 = r31.s64 + 23552;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// addi r6,r10,2384
	ctx.r6.s64 = ctx.r10.s64 + 2384;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r27,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,23684
	ctx.r4.s64 = 23684;
	// addi r3,r5,2352
	ctx.r3.s64 = ctx.r5.s64 + 2352;
	// lvx128 v59,r27,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v62,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v58,r27,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v55,v61,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v56,v58,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// li r10,96
	ctx.r10.s64 = 96;
	// vmrglw128 v54,v62,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// li r9,112
	ctx.r9.s64 = 112;
	// vmrglw128 v53,v58,v59
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v51,v63,v55
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// li r30,0
	r30.s64 = 0;
	// vmrglw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v50,v57,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v49,v54,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmsum4fp128 v48,v51,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v46,v51,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmsum4fp128 v47,v51,v49
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmrghw128 v45,v48,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v44,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vor128 v40,v43,v43
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_load_si128((simde__m128i*)v43.u8));
	// stvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,23376(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// lvlx128 v42,r31,r4
	temp.u32 = r31.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// vspltw128 v41,v42,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xFF));
	// vsubfp128 v39,v40,v41
	simde_mm_store_ps(v39.f32, simde_mm_sub_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v41.f32)));
	// vaddfp128 v38,v40,v41
	simde_mm_store_ps(v38.f32, simde_mm_add_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v41.f32)));
	// stvx128 v39,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x8256dcfc
	if (!cr6.gt) goto loc_8256DCFC;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_8256DCD0:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256dce8
	if (cr6.eq) goto loc_8256DCE8;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82575d40
	ctx.lr = 0x8256DCE8;
	sub_82575D40(ctx, base);
loc_8256DCE8:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256dcd0
	if (cr6.lt) goto loc_8256DCD0;
loc_8256DCFC:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256dd40
	if (!cr6.gt) goto loc_8256DD40;
	// addi r29,r31,22672
	r29.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_8256DD14:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256dd2c
	if (cr6.eq) goto loc_8256DD2C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825777e0
	ctx.lr = 0x8256DD2C;
	sub_825777E0(ctx, base);
loc_8256DD2C:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256dd14
	if (cr6.lt) goto loc_8256DD14;
loc_8256DD40:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256dd84
	if (!cr6.gt) goto loc_8256DD84;
	// addi r29,r31,22864
	r29.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_8256DD58:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256dd70
	if (cr6.eq) goto loc_8256DD70;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82576410
	ctx.lr = 0x8256DD70;
	sub_82576410(ctx, base);
loc_8256DD70:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256dd58
	if (cr6.lt) goto loc_8256DD58;
loc_8256DD84:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256ddc8
	if (!cr6.gt) goto loc_8256DDC8;
	// addi r29,r31,23088
	r29.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_8256DD9C:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256ddb4
	if (cr6.eq) goto loc_8256DDB4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82576830
	ctx.lr = 0x8256DDB4;
	sub_82576830(ctx, base);
loc_8256DDB4:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8256dd9c
	if (cr6.lt) goto loc_8256DD9C;
loc_8256DDC8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8256DDD0"))) PPC_WEAK_FUNC(sub_8256DDD0);
PPC_FUNC_IMPL(__imp__sub_8256DDD0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// li r11,48
	r11.s64 = 48;
	// lfs f0,23552(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 23552);
	f0.f64 = double(temp.f32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lfs f13,23560(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 23560);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23684(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 23684);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,23556(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 23556);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// lvx128 v63,r4,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f0,f6
	ctx.f5.f64 = double(float(f0.f64 - ctx.f6.f64));
	// fsubs f4,f13,f8
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// fmuls f3,f5,f5
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fsubs f2,f10,f7
	ctx.f2.f64 = double(float(ctx.f10.f64 - ctx.f7.f64));
	// fmuls f1,f9,f9
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f0,f4,f4,f3
	f0.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f3.f64));
	// fmadds f13,f2,f2,f0
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + f0.f64));
	// fcmpu cr6,f1,f13
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// blt cr6,0x8256de30
	if (cr6.lt) goto loc_8256DE30;
	// li r11,0
	r11.s64 = 0;
loc_8256DE30:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256DE38"))) PPC_WEAK_FUNC(sub_8256DE38);
PPC_FUNC_IMPL(__imp__sub_8256DE38) {
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
	ctx.lr = 0x8256DE40;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256dea8
	if (!cr6.gt) goto loc_8256DEA8;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// addi r27,r31,23392
	r27.s64 = r31.s64 + 23392;
loc_8256DE6C:
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256de94
	if (cr6.eq) goto loc_8256DE94;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82578e08
	ctx.lr = 0x8256DE88;
	sub_82578E08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// or r28,r11,r10
	r28.u64 = r11.u64 | ctx.r10.u64;
loc_8256DE94:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,176
	r30.s64 = r30.s64 + 176;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256de6c
	if (cr6.lt) goto loc_8256DE6C;
loc_8256DEA8:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256defc
	if (!cr6.gt) goto loc_8256DEFC;
	// addi r30,r31,22672
	r30.s64 = r31.s64 + 22672;
	// addi r27,r31,23520
	r27.s64 = r31.s64 + 23520;
loc_8256DEC0:
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256dee8
	if (cr6.eq) goto loc_8256DEE8;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82579678
	ctx.lr = 0x8256DEDC;
	sub_82579678(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// or r28,r11,r10
	r28.u64 = r11.u64 | ctx.r10.u64;
loc_8256DEE8:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256dec0
	if (cr6.lt) goto loc_8256DEC0;
loc_8256DEFC:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256df50
	if (!cr6.gt) goto loc_8256DF50;
	// addi r30,r31,22864
	r30.s64 = r31.s64 + 22864;
	// addi r27,r31,23521
	r27.s64 = r31.s64 + 23521;
loc_8256DF14:
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256df3c
	if (cr6.eq) goto loc_8256DF3C;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8257a648
	ctx.lr = 0x8256DF30;
	sub_8257A648(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// or r28,r11,r10
	r28.u64 = r11.u64 | ctx.r10.u64;
loc_8256DF3C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,224
	r30.s64 = r30.s64 + 224;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256df14
	if (cr6.lt) goto loc_8256DF14;
loc_8256DF50:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256dfa4
	if (!cr6.gt) goto loc_8256DFA4;
	// addi r30,r31,23088
	r30.s64 = r31.s64 + 23088;
	// addi r27,r31,23522
	r27.s64 = r31.s64 + 23522;
loc_8256DF68:
	// lbzx r11,r27,r29
	r11.u64 = PPC_LOAD_U8(r27.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256df90
	if (cr6.eq) goto loc_8256DF90;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8257c988
	ctx.lr = 0x8256DF84;
	sub_8257C988(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// or r28,r11,r10
	r28.u64 = r11.u64 | ctx.r10.u64;
loc_8256DF90:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,288
	r30.s64 = r30.s64 + 288;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8256df68
	if (cr6.lt) goto loc_8256DF68;
loc_8256DFA4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8256DFB0"))) PPC_WEAK_FUNC(sub_8256DFB0);
PPC_FUNC_IMPL(__imp__sub_8256DFB0) {
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
	ctx.lr = 0x8256DFB8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// li r30,0
	r30.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256e038
	if (!cr6.gt) goto loc_8256E038;
	// addi r29,r31,204
	r29.s64 = r31.s64 + 204;
	// addi r23,r31,23392
	r23.s64 = r31.s64 + 23392;
loc_8256DFEC:
	// lbzx r11,r23,r28
	r11.u64 = PPC_LOAD_U8(r23.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256e024
	if (cr6.eq) goto loc_8256E024;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// lhz r10,58(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r29,-60
	ctx.r3.s64 = r29.s64 + -60;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// sth r10,-2(r29)
	PPC_STORE_U16(r29.u32 + -2, ctx.r10.u16);
	// bl 0x82579490
	ctx.lr = 0x8256E020;
	sub_82579490(ctx, base);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
loc_8256E024:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8256dfec
	if (cr6.lt) goto loc_8256DFEC;
loc_8256E038:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256e09c
	if (!cr6.gt) goto loc_8256E09C;
	// addi r29,r31,22732
	r29.s64 = r31.s64 + 22732;
	// addi r23,r31,23520
	r23.s64 = r31.s64 + 23520;
loc_8256E050:
	// lbzx r11,r23,r28
	r11.u64 = PPC_LOAD_U8(r23.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256e088
	if (cr6.eq) goto loc_8256E088;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// lhz r10,58(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r29,-60
	ctx.r3.s64 = r29.s64 + -60;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// sth r10,-2(r29)
	PPC_STORE_U16(r29.u32 + -2, ctx.r10.u16);
	// bl 0x8257a0a0
	ctx.lr = 0x8256E084;
	sub_8257A0A0(ctx, base);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
loc_8256E088:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8256e050
	if (cr6.lt) goto loc_8256E050;
loc_8256E09C:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256e100
	if (!cr6.gt) goto loc_8256E100;
	// addi r29,r31,22924
	r29.s64 = r31.s64 + 22924;
	// addi r23,r31,23521
	r23.s64 = r31.s64 + 23521;
loc_8256E0B4:
	// lbzx r11,r23,r28
	r11.u64 = PPC_LOAD_U8(r23.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256e0ec
	if (cr6.eq) goto loc_8256E0EC;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// lhz r10,58(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r29,-60
	ctx.r3.s64 = r29.s64 + -60;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// sth r10,-2(r29)
	PPC_STORE_U16(r29.u32 + -2, ctx.r10.u16);
	// bl 0x8257c088
	ctx.lr = 0x8256E0E8;
	sub_8257C088(ctx, base);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
loc_8256E0EC:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8256e0b4
	if (cr6.lt) goto loc_8256E0B4;
loc_8256E100:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8256e164
	if (!cr6.gt) goto loc_8256E164;
	// addi r29,r31,23148
	r29.s64 = r31.s64 + 23148;
	// addi r23,r31,23522
	r23.s64 = r31.s64 + 23522;
loc_8256E118:
	// lbzx r11,r23,r28
	r11.u64 = PPC_LOAD_U8(r23.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256e150
	if (cr6.eq) goto loc_8256E150;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// lhz r10,58(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r29,-60
	ctx.r3.s64 = r29.s64 + -60;
	// sth r11,0(r29)
	PPC_STORE_U16(r29.u32 + 0, r11.u16);
	// sth r10,-2(r29)
	PPC_STORE_U16(r29.u32 + -2, ctx.r10.u16);
	// bl 0x821a5cc0
	ctx.lr = 0x8256E14C;
	sub_821A5CC0(ctx, base);
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
loc_8256E150:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8256e118
	if (cr6.lt) goto loc_8256E118;
loc_8256E164:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8256E170"))) PPC_WEAK_FUNC(sub_8256E170);
PPC_FUNC_IMPL(__imp__sub_8256E170) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,58(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 58);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sth r11,58(r3)
	PPC_STORE_U16(ctx.r3.u32 + 58, r11.u16);
	// lbz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// blt cr6,0x8256e214
	if (cr6.lt) goto loc_8256E214;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// ble cr6,0x8256e1e4
	if (!cr6.gt) goto loc_8256E1E4;
	// cmpwi cr6,r10,10
	cr6.compare<int32_t>(ctx.r10.s32, 10, xer);
	// bne cr6,0x8256e214
	if (!cr6.eq) goto loc_8256E214;
	// lhz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 56);
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8256e214
	if (!cr6.lt) goto loc_8256E214;
	// lwz r11,756(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 756);
	// lhz r10,58(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 58);
	// addi r11,r11,314
	r11.s64 = r11.s64 + 314;
	// lwz r9,100(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 100);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r8,r5
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r5.u32);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r9.u32);
	// rotlwi r11,r5,4
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 4);
	// sth r5,60(r3)
	PPC_STORE_U16(ctx.r3.u32 + 60, ctx.r5.u16);
	// lwz r10,140(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 140);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_8256E1E4:
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// lhz r11,60(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 60);
	// lhz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 56);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// sth r8,60(r3)
	PPC_STORE_U16(ctx.r3.u32 + 60, ctx.r8.u16);
	// bge cr6,0x8256e214
	if (!cr6.lt) goto loc_8256E214;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r10,140(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 140);
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_8256E214:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256E21C"))) PPC_WEAK_FUNC(sub_8256E21C);
PPC_FUNC_IMPL(__imp__sub_8256E21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256E220"))) PPC_WEAK_FUNC(sub_8256E220);
PPC_FUNC_IMPL(__imp__sub_8256E220) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r3,23536
	r11.s64 = ctx.r3.s64 + 23536;
	// lwz r7,23376(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23376);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r6,r10,-31568
	ctx.r6.s64 = ctx.r10.s64 + -31568;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x8256e294
	if (!cr6.gt) goto loc_8256E294;
	// addi r10,r3,240
	ctx.r10.s64 = ctx.r3.s64 + 240;
	// addi r7,r3,23392
	ctx.r7.s64 = ctx.r3.s64 + 23392;
loc_8256E254:
	// lbzx r4,r7,r9
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8256e280
	if (cr6.eq) goto loc_8256E280;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lvx128 v61,r10,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v13,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v12,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8256E280:
	// lwz r4,23376(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23376);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,176
	ctx.r10.s64 = ctx.r10.s64 + 176;
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// blt cr6,0x8256e254
	if (cr6.lt) goto loc_8256E254;
loc_8256E294:
	// lwz r10,23380(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23380);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8256e2e0
	if (!cr6.gt) goto loc_8256E2E0;
	// addi r10,r3,22816
	ctx.r10.s64 = ctx.r3.s64 + 22816;
	// addi r7,r3,23520
	ctx.r7.s64 = ctx.r3.s64 + 23520;
loc_8256E2AC:
	// lbzx r4,r7,r9
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8256e2cc
	if (cr6.eq) goto loc_8256E2CC;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8256E2CC:
	// lwz r4,23380(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23380);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,192
	ctx.r10.s64 = ctx.r10.s64 + 192;
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// blt cr6,0x8256e2ac
	if (cr6.lt) goto loc_8256E2AC;
loc_8256E2E0:
	// lwz r10,23384(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23384);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8256e338
	if (!cr6.gt) goto loc_8256E338;
	// addi r10,r3,23008
	ctx.r10.s64 = ctx.r3.s64 + 23008;
	// addi r7,r3,23521
	ctx.r7.s64 = ctx.r3.s64 + 23521;
loc_8256E2F8:
	// lbzx r4,r7,r9
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8256e324
	if (cr6.eq) goto loc_8256E324;
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lvx128 v56,r10,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v13,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// lvx128 v12,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8256E324:
	// lwz r4,23384(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23384);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,224
	ctx.r10.s64 = ctx.r10.s64 + 224;
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// blt cr6,0x8256e2f8
	if (cr6.lt) goto loc_8256E2F8;
loc_8256E338:
	// lwz r10,23388(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23388);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8256e384
	if (!cr6.gt) goto loc_8256E384;
	// addi r10,r3,23280
	ctx.r10.s64 = ctx.r3.s64 + 23280;
	// addi r7,r3,23522
	ctx.r7.s64 = ctx.r3.s64 + 23522;
loc_8256E350:
	// lbzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8256e370
	if (cr6.eq) goto loc_8256E370;
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v53,v54,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8256E370:
	// lwz r6,23388(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23388);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,288
	ctx.r10.s64 = ctx.r10.s64 + 288;
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// blt cr6,0x8256e350
	if (cr6.lt) goto loc_8256E350;
loc_8256E384:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8256e3b4
	if (!cr6.gt) goto loc_8256E3B4;
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 / ctx.f12.f64));
	// stfs f11,-16(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// b 0x8256e3c0
	goto loc_8256E3C0;
loc_8256E3B4:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
loc_8256E3C0:
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v51,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vmulfp128 v49,v52,v50
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256E3DC"))) PPC_WEAK_FUNC(sub_8256E3DC);
PPC_FUNC_IMPL(__imp__sub_8256E3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256E3E0"))) PPC_WEAK_FUNC(sub_8256E3E0);
PPC_FUNC_IMPL(__imp__sub_8256E3E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// li r10,32
	ctx.r10.s64 = 32;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// vspltisw128 v50,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_set1_epi32(int(0x0)));
	// li r8,16
	ctx.r8.s64 = 16;
	// vslw128 v56,v63,v63
	v56.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v56.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v56.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v56.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// addi r7,r9,-31472
	ctx.r7.s64 = ctx.r9.s64 + -31472;
	// vslw128 v49,v63,v63
	v49.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v49.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v49.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v49.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// lvx128 v48,r3,r10
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v47,v63,v63
	v47.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v47.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v47.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v47.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vmrghw128 v39,v62,v48
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v36,v62,v48
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vandc128 v44,v62,v56
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvx128 v45,r3,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v43,v48,v49
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v48.u8)));
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v46,v48,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vor128 v40,v60,v60
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vmsum3fp128 v42,v45,v60
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vandc128 v41,v45,v47
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v45.u8)));
	// vmsum3fp128 v57,v62,v60
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vaddfp128 v60,v44,v61
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v61.f32)));
	// vaddfp128 v58,v43,v61
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v61.f32)));
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// vmrghw128 v38,v45,v40
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// vaddfp128 v59,v41,v61
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v61.f32)));
	// vmrglw128 v37,v45,v40
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// addi r4,r5,2384
	ctx.r4.s64 = ctx.r5.s64 + 2384;
	// vslw128 v35,v63,v63
	v35.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v35.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v35.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v35.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// vslw128 v34,v63,v63
	v34.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v34.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v34.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v34.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vmrghw128 v56,v39,v38
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// lvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v55,v39,v38
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// addi r11,r3,2352
	r11.s64 = ctx.r3.s64 + 2352;
	// vmrghw128 v54,v36,v37
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v32,v60,v2
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v2.f32), 0xEF));
	// vmsum3fp128 v61,v58,v2
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(ctx.v2.f32), 0xEF));
	// vmrghw128 v52,v60,v58
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrglw128 v45,v60,v58
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmsum3fp128 v49,v59,v2
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v2.f32), 0xEF));
	// vmrghw128 v47,v59,v53
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v33,v57,v46
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v46,v59,v53
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v53,v52,v47
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v48,v42,v33
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v51,v45,v46
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrglw128 v52,v52,v47
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmsum3fp128 v42,v53,v1
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v1.f32), 0xEF));
	// vmrghw128 v44,v33,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmsum3fp128 v40,v51,v1
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v1.f32), 0xEF));
	// vmsum3fp128 v41,v52,v1
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v1.f32), 0xEF));
	// vsubfp128 v43,v50,v44
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v44.f32)));
	// vmrghw128 v39,v32,v61
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v38,v49,v39
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v37,v39,v38
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vand128 v61,v43,v62
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vaddfp128 v50,v37,v1
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(ctx.v1.f32)));
	// vmrghw128 v49,v42,v40
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmsum3fp128 v36,v54,v61
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vandc128 v35,v61,v35
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vmsum3fp128 v33,v56,v61
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmrghw128 v47,v41,v49
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmsum3fp128 v32,v55,v61
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vand128 v48,v35,v62
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vmrghw128 v46,v49,v47
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vand128 v45,v50,v62
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vaddfp128 v44,v46,v2
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vor128 v42,v45,v57
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vmrghw128 v43,v33,v36
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vcmpgtfp128 v40,v42,v48
	simde_mm_store_ps(v40.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v48.f32)));
	// vmrghw128 v41,v32,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v39,v43,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vandc128 v38,v39,v34
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v39.u8)));
	// vand128 v37,v40,v62
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vand128 v36,v44,v62
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vand128 v35,v38,v62
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vor128 v34,v36,v57
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vcmpgtfp128 v33,v34,v35
	simde_mm_store_ps(v33.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v35.f32)));
	// vand128 v50,v37,v33
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)v33.u8)));
	// vand128 v32,v50,v62
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpequw128. v49,v32,v62
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v49.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8256e558
	if (!cr6.eq) goto loc_8256E558;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8256E558:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vpermwi128 v45,v1,79
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xB0));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vpermwi128 v48,v61,79
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xB0));
	// addi r9,r1,-80
	ctx.r9.s64 = ctx.r1.s64 + -80;
	// vpermwi128 v47,v61,179
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x4C));
	// addi r8,r1,-80
	ctx.r8.s64 = ctx.r1.s64 + -80;
	// vpermwi128 v46,v61,231
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x18));
	// addi r7,r1,-80
	ctx.r7.s64 = ctx.r1.s64 + -80;
	// vmsum3fp128 v40,v51,v45
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// vmsum3fp128 v39,v53,v45
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// lfs f13,14192(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// vmsum3fp128 v34,v52,v45
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v45.f32), 0xEF));
	// stfs f13,-80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// vpermwi128 v44,v2,231
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), 0x18));
	// stfs f0,-76(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// vspltw128 v42,v60,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// stfs f0,-72(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// vspltw128 v43,v58,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvx128 v38,r0,r9
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v47,v38
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v38.f32)));
	// stfs f0,-80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// vmulfp128 v12,v44,v42
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v42.f32)));
	// stfs f0,-76(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// vmrghw128 v42,v39,v40
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// stfs f13,-72(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// vmulfp128 v13,v44,v43
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v43.f32)));
	// lvx128 v36,r0,r8
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v47,v46,v36
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v36.f32)));
	// stfs f0,-80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// vmrghw128 v36,v34,v42
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// stfs f13,-76(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// vmsum3fp128 v38,v54,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// stfs f0,-72(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// vmsum3fp128 v34,v56,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lvx128 v33,r0,r7
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v32,v48,v33
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v33.f32)));
	// vmsum3fp128 v49,v54,v32
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v32.f32), 0xEF));
	// vspltw128 v41,v59,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vmsum3fp128 v48,v56,v32
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v32.f32), 0xEF));
	// vpermwi128 v0,v2,179
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), 0x4C));
	// vmsum3fp128 v46,v55,v32
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v32.f32), 0xEF));
	// vpermwi128 v37,v1,231
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x18));
	// vspltw128 v10,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xAA));
	// vmsum3fp128 v33,v55,v61
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmulfp128 v11,v44,v41
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v41.f32)));
	// vpermwi128 v35,v1,179
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x4C));
	// vspltw128 v8,v59,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xAA));
	// vmsum3fp128 v32,v54,v47
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v47.f32), 0xEF));
	// vmsum3fp128 v45,v51,v37
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v37.f32), 0xEF));
	// vspltw128 v9,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vmsum3fp128 v44,v53,v37
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v37.f32), 0xEF));
	// vmaddfp v7,v0,v10,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vpermwi128 v13,v2,79
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), 0xB0));
	// vmsum3fp128 v43,v51,v35
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v35.f32), 0xEF));
	// vspltw128 v2,v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x55));
	// vmsum3fp128 v41,v53,v35
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v35.f32), 0xEF));
	// vmsum3fp128 v61,v56,v47
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v47.f32), 0xEF));
	// vmrghw128 v51,v34,v38
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmaddfp v6,v0,v9,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vslw128 v40,v63,v63
	v40.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v40.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v40.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v40.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vspltw128 v4,v58,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// vslw128 v39,v63,v63
	v39.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v39.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v39.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v39.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vspltw128 v3,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vmrghw128 v60,v42,v36
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmaddfp v5,v0,v8,v11
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmrghw128 v59,v48,v49
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmaddfp v1,v13,v4,v7
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmrghw128 v56,v46,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v46,v33,v51
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v58,v44,v45
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmaddfp v31,v13,v3,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmrghw128 v53,v59,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v44,v51,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v54,v41,v43
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmaddfp v30,v13,v2,v5
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmrghw128 v48,v61,v32
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vandc128 v49,v53,v40
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vandc128 v43,v44,v39
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v44.u8)));
	// vand128 v45,v49,v62
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vmsum3fp128 v42,v52,v37
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v37.f32), 0xEF));
	// vslw128 v41,v63,v63
	v41.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v41.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v41.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v41.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vmsum3fp128 v40,v52,v35
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v35.f32), 0xEF));
	// vaddfp128 v39,v1,v60
	simde_mm_store_ps(v39.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v60.f32)));
	// vmsum3fp128 v38,v55,v47
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v47.f32), 0xEF));
	// vand128 v37,v43,v62
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vand128 v36,v39,v62
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vmrghw128 v35,v42,v58
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v34,v40,v54
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vor128 v33,v36,v57
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vmrghw128 v32,v38,v48
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v63,v58,v35
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v61,v54,v34
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vcmpgtfp128 v60,v33,v45
	simde_mm_store_ps(v60.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v45.f32)));
	// vmrghw128 v59,v48,v32
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vaddfp128 v58,v31,v63
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v56,v30,v61
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v61.f32)));
	// vandc128 v55,v59,v41
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vand128 v54,v55,v62
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vand128 v53,v58,v62
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vand128 v52,v56,v62
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vor128 v51,v53,v57
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vor128 v49,v52,v57
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vcmpgtfp128 v48,v51,v54
	simde_mm_store_ps(v48.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v54.f32)));
	// vcmpgtfp128 v47,v49,v37
	simde_mm_store_ps(v47.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v37.f32)));
	// vand128 v46,v50,v48
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v48.u8)));
	// vand128 v45,v46,v47
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v47.u8)));
	// vand128 v44,v45,v60
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vand128 v43,v44,v62
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpequw128. v42,v43,v62
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v42.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r3,r6,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256E720"))) PPC_WEAK_FUNC(sub_8256E720);
PPC_FUNC_IMPL(__imp__sub_8256E720) {
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
	ctx.lr = 0x8256E728;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8256c070
	ctx.lr = 0x8256E744;
	sub_8256C070(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,1365
	ctx.r10.s64 = 89456640;
	// sth r28,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r28.u16);
	// addi r9,r11,-3004
	ctx.r9.s64 = r11.s64 + -3004;
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// li r29,0
	r29.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// ori r8,r10,21845
	ctx.r8.u64 = ctx.r10.u64 | 21845;
	// sth r29,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r29.u16);
	// li r28,-1
	r28.s64 = -1;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bgt cr6,0x8256e784
	if (cr6.gt) goto loc_8256E784;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// b 0x8256e788
	goto loc_8256E788;
loc_8256E784:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_8256E788:
	// bl 0x82130528
	ctx.lr = 0x8256E78C;
	sub_82130528(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// rotlwi r3,r11,1
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 1);
	// bl 0x82130528
	ctx.lr = 0x8256E79C;
	sub_82130528(ctx, base);
	// rlwinm r11,r30,30,18,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 30) & 0x3FFF;
	// lis r10,8191
	ctx.r10.s64 = 536805376;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r30,r11
	r30.u64 = r11.u64;
	// sth r11,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r11.u16);
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r30,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x8256e7c4
	if (!cr6.gt) goto loc_8256E7C4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_8256E7C4:
	// bl 0x82130528
	ctx.lr = 0x8256E7C8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256e808
	if (cr6.eq) goto loc_8256E808;
	// addic. r10,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r10.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// blt 0x8256e7f0
	if (cr0.lt) goto loc_8256E7F0;
loc_8256E7DC:
	// sth r29,0(r11)
	PPC_STORE_U16(r11.u32 + 0, r29.u16);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r29,2(r11)
	PPC_STORE_U16(r11.u32 + 2, r29.u16);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bge 0x8256e7dc
	if (!cr0.lt) goto loc_8256E7DC;
loc_8256E7F0:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// sth r29,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r29.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8256E808:
	// mr r11,r29
	r11.u64 = r29.u64;
	// sth r29,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r29.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8256E820"))) PPC_WEAK_FUNC(sub_8256E820);
PPC_FUNC_IMPL(__imp__sub_8256E820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,0
	r11.s64 = 0;
	// lhz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r4,r4,1,15,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x1FFFE;
	// ori r9,r11,65535
	ctx.r9.u64 = r11.u64 | 65535;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r5,16
	ctx.r5.s64 = 16;
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sth r11,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, r11.u16);
	// rlwinm r8,r11,1,15,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1FFFE;
	// lhzx r31,r4,r7
	r31.u64 = PPC_LOAD_U16(ctx.r4.u32 + ctx.r7.u32);
	// rotlwi r7,r31,1
	ctx.r7.u64 = __builtin_rotateleft32(r31.u32, 1);
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// add r7,r31,r7
	ctx.r7.u64 = r31.u64 + ctx.r7.u64;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r7,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r6,32(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// sth r6,32(r10)
	PPC_STORE_U16(ctx.r10.u32 + 32, ctx.r6.u16);
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// sthx r9,r4,r5
	PPC_STORE_U16(ctx.r4.u32 + ctx.r5.u32, ctx.r9.u16);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lhz r11,28(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// rotlwi r9,r10,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// sthx r31,r9,r4
	PPC_STORE_U16(ctx.r9.u32 + ctx.r4.u32, r31.u16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256E8C0"))) PPC_WEAK_FUNC(sub_8256E8C0);
PPC_FUNC_IMPL(__imp__sub_8256E8C0) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-2788
	ctx.r10.s64 = r11.s64 + -2788;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8256c1f8
	ctx.lr = 0x8256E8EC;
	sub_8256C1F8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256e904
	if (cr6.eq) goto loc_8256E904;
	// bl 0x82130588
	ctx.lr = 0x8256E900;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256E904:
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

__attribute__((alias("__imp__sub_8256E91C"))) PPC_WEAK_FUNC(sub_8256E91C);
PPC_FUNC_IMPL(__imp__sub_8256E91C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256E920"))) PPC_WEAK_FUNC(sub_8256E920);
PPC_FUNC_IMPL(__imp__sub_8256E920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8256E928;
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// bl 0x8256e720
	ctx.lr = 0x8256E954;
	sub_8256E720(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// addi r10,r11,-2700
	ctx.r10.s64 = r11.s64 + -2700;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r5,2039
	ctx.r5.s64 = 2039;
	// li r4,2039
	ctx.r4.s64 = 2039;
	// bl 0x825c0ff0
	ctx.lr = 0x8256E974;
	sub_825C0FF0(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v126,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f2
	ctx.f11.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsubs f12,f13,f3
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f3.f64));
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fsel f1,f10,f11,f12
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f11.f64 : ctx.f12.f64;
	// bl 0x825c1088
	ctx.lr = 0x8256E9B4;
	sub_825C1088(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8256E9D0"))) PPC_WEAK_FUNC(sub_8256E9D0);
PPC_FUNC_IMPL(__imp__sub_8256E9D0) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-2700
	ctx.r10.s64 = r11.s64 + -2700;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8256c1f8
	ctx.lr = 0x8256E9FC;
	sub_8256C1F8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256ea14
	if (cr6.eq) goto loc_8256EA14;
	// bl 0x82130588
	ctx.lr = 0x8256EA10;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256EA14:
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

__attribute__((alias("__imp__sub_8256EA2C"))) PPC_WEAK_FUNC(sub_8256EA2C);
PPC_FUNC_IMPL(__imp__sub_8256EA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256EA30"))) PPC_WEAK_FUNC(sub_8256EA30);
PPC_FUNC_IMPL(__imp__sub_8256EA30) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-2612
	ctx.r10.s64 = r11.s64 + -2612;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8256c1f8
	ctx.lr = 0x8256EA5C;
	sub_8256C1F8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256ea74
	if (cr6.eq) goto loc_8256EA74;
	// bl 0x82130588
	ctx.lr = 0x8256EA70;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256EA74:
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

__attribute__((alias("__imp__sub_8256EA8C"))) PPC_WEAK_FUNC(sub_8256EA8C);
PPC_FUNC_IMPL(__imp__sub_8256EA8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256EA90"))) PPC_WEAK_FUNC(sub_8256EA90);
PPC_FUNC_IMPL(__imp__sub_8256EA90) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-2832
	ctx.r10.s64 = r11.s64 + -2832;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82575288
	ctx.lr = 0x8256EABC;
	sub_82575288(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256ead4
	if (cr6.eq) goto loc_8256EAD4;
	// bl 0x82130588
	ctx.lr = 0x8256EAD0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8256EAD4:
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

__attribute__((alias("__imp__sub_8256EAEC"))) PPC_WEAK_FUNC(sub_8256EAEC);
PPC_FUNC_IMPL(__imp__sub_8256EAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256EAF0"))) PPC_WEAK_FUNC(sub_8256EAF0);
PPC_FUNC_IMPL(__imp__sub_8256EAF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r22{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8256EAF8;
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,-208
	r31.s64 = ctx.r1.s64 + -208;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,96
	r11.s64 = 96;
	// li r26,0
	r26.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// stw r26,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r26.u32);
	// lwz r3,144(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// lvlx128 v63,r30,r11
	temp.u32 = r30.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stw r26,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r26.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r26,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r26.u32);
	// sth r26,112(r31)
	PPC_STORE_U16(r31.u32 + 112, r26.u16);
	// vspltw128 v127,v63,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// beq cr6,0x8256ec2c
	if (cr6.eq) goto loc_8256EC2C;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x8256ec0c
	if (!cr6.eq) goto loc_8256EC0C;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8256ec04
	if (!cr6.eq) goto loc_8256EC04;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256EB68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,144(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8256EB7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r7,r3,4,12,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFF0;
	// sth r3,112(r31)
	PPC_STORE_U16(r31.u32 + 112, ctx.r3.u16);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// rlwinm r12,r6,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8256EB90;
	sub_823DBFF4(ctx, base);
	// lwz r5,0(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// neg r4,r7
	ctx.r4.s64 = -ctx.r7.s64;
	// stwux r5,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r4,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// bl 0x823dbff4
	ctx.lr = 0x8256EBAC;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// rlwinm r9,r3,2,14,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FFFC;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stw r7,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r7.u32);
	// bl 0x823dbff4
	ctx.lr = 0x8256EBCC;
	sub_823DBFF4(ctx, base);
	// lwz r3,0(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// addi r7,r31,112
	ctx.r7.s64 = r31.s64 + 112;
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// addi r6,r31,116
	ctx.r6.s64 = r31.s64 + 116;
	// addi r5,r31,120
	ctx.r5.s64 = r31.s64 + 120;
	// addi r4,r31,124
	ctx.r4.s64 = r31.s64 + 124;
	// stwux r3,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r1.u32 = ea;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stw r10,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8256EC04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256EC04:
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
loc_8256EC0C:
	// lwz r3,144(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256ec2c
	if (cr6.eq) goto loc_8256EC2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256EC2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256EC2C:
	// lwz r11,140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8256edac
	if (cr6.gt) goto loc_8256EDAC;
	// lis r12,-32169
	r12.s64 = -2108227584;
	// addi r12,r12,-5040
	r12.s64 = r12.s64 + -5040;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8256EC64;
	case 1:
		goto loc_8256ECB0;
	case 2:
		goto loc_8256ECEC;
	case 3:
		goto loc_8256ED1C;
	case 4:
		goto loc_8256ED68;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-5020(r22)
	r18.u64 = PPC_LOAD_U32(r22.u32 + -5020);
	// lwz r18,-4944(r22)
	r18.u64 = PPC_LOAD_U32(r22.u32 + -4944);
	// lwz r18,-4884(r22)
	r18.u64 = PPC_LOAD_U32(r22.u32 + -4884);
	// lwz r18,-4836(r22)
	r18.u64 = PPC_LOAD_U32(r22.u32 + -4836);
	// lwz r18,-4760(r22)
	r18.u64 = PPC_LOAD_U32(r22.u32 + -4760);
loc_8256EC64:
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x8256EC6C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256eca4
	if (cr6.eq) goto loc_8256ECA4;
	// li r11,80
	r11.s64 = 80;
	// lwz r10,100(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lhz r5,38(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 38);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// lvx128 v62,r30,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v62,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v127.f32)));
	// vsubfp128 v1,v62,v127
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v127.f32)));
	// bl 0x825c1ae0
	ctx.lr = 0x8256EC9C;
	sub_825C1AE0(ctx, base);
	// stw r3,144(r30)
	PPC_STORE_U32(r30.u32 + 144, ctx.r3.u32);
	// b 0x8256edac
	goto loc_8256EDAC;
loc_8256ECA4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r3,144(r30)
	PPC_STORE_U32(r30.u32 + 144, ctx.r3.u32);
	// b 0x8256edac
	goto loc_8256EDAC;
loc_8256ECB0:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8256ECB8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8256eda4
	if (cr6.eq) goto loc_8256EDA4;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lhz r4,38(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 38);
	// clrlwi r5,r11,16
	ctx.r5.u64 = r11.u32 & 0xFFFF;
	// bl 0x8256e720
	ctx.lr = 0x8256ECD8;
	sub_8256E720(ctx, base);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r9,r10,-2788
	ctx.r9.s64 = ctx.r10.s64 + -2788;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// b 0x8256eda8
	goto loc_8256EDA8;
loc_8256ECEC:
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x8256ECF4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256eca4
	if (cr6.eq) goto loc_8256ECA4;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lhz r5,38(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 38);
	// clrlwi r6,r11,16
	ctx.r6.u64 = r11.u32 & 0xFFFF;
	// bl 0x8256c558
	ctx.lr = 0x8256ED14;
	sub_8256C558(ctx, base);
	// stw r3,144(r30)
	PPC_STORE_U32(r30.u32 + 144, ctx.r3.u32);
	// b 0x8256edac
	goto loc_8256EDAC;
loc_8256ED1C:
	// li r3,7288
	ctx.r3.s64 = 7288;
	// bl 0x82130528
	ctx.lr = 0x8256ED24;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256eca4
	if (cr6.eq) goto loc_8256ECA4;
	// li r29,80
	r29.s64 = 80;
	// lwz r10,100(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lhz r4,38(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 38);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// clrlwi r5,r10,16
	ctx.r5.u64 = ctx.r10.u32 & 0xFFFF;
	// lvx128 v61,r30,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,8752(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8752);
	// vaddfp128 v2,v61,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	// lwz r7,8748(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8748);
	// vsubfp128 v1,v61,v127
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	// bl 0x8256e920
	ctx.lr = 0x8256ED60;
	sub_8256E920(ctx, base);
	// stw r3,144(r30)
	PPC_STORE_U32(r30.u32 + 144, ctx.r3.u32);
	// b 0x8256edac
	goto loc_8256EDAC;
loc_8256ED68:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8256ED70;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8256eda4
	if (cr6.eq) goto loc_8256EDA4;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lhz r4,38(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 38);
	// clrlwi r5,r11,16
	ctx.r5.u64 = r11.u32 & 0xFFFF;
	// bl 0x8256e720
	ctx.lr = 0x8256ED90;
	sub_8256E720(ctx, base);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r9,r10,-2612
	ctx.r9.s64 = ctx.r10.s64 + -2612;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// b 0x8256eda8
	goto loc_8256EDA8;
loc_8256EDA4:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8256EDA8:
	// stw r11,144(r30)
	PPC_STORE_U32(r30.u32 + 144, r11.u32);
loc_8256EDAC:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8256eddc
	if (!cr6.eq) goto loc_8256EDDC;
	// lwz r3,144(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// lhz r7,112(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 112);
	// lwz r6,116(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256EDDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256EDDC:
	// addi r1,r31,208
	ctx.r1.s64 = r31.s64 + 208;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8256EDEC"))) PPC_WEAK_FUNC(sub_8256EDEC);
PPC_FUNC_IMPL(__imp__sub_8256EDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256EDF0"))) PPC_WEAK_FUNC(sub_8256EDF0);
PPC_FUNC_IMPL(__imp__sub_8256EDF0) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8256EDF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825752d0
	ctx.lr = 0x8256EE04;
	sub_825752D0(ctx, base);
	// lhz r11,38(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// rotlwi r3,r11,3
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 3);
	// bl 0x82130528
	ctx.lr = 0x8256EE10;
	sub_82130528(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
	// lhz r10,38(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// rotlwi r3,r10,1
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// bl 0x82130528
	ctx.lr = 0x8256EE20;
	sub_82130528(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
	// lhz r9,38(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// rotlwi r3,r9,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// bl 0x82130528
	ctx.lr = 0x8256EE30;
	sub_82130528(ctx, base);
	// lhz r8,38(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// li r29,0
	r29.s64 = 0;
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// beq cr6,0x8256ee88
	if (cr6.eq) goto loc_8256EE88;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
loc_8256EE50:
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// ori r5,r6,3
	ctx.r5.u64 = ctx.r6.u64 | 3;
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// lwz r4,116(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// sthx r7,r8,r4
	PPC_STORE_U16(ctx.r8.u32 + ctx.r4.u32, ctx.r7.u16);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// lhz r3,38(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8256ee50
	if (cr6.lt) goto loc_8256EE50;
loc_8256EE88:
	// lhz r11,40(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 40);
	// rotlwi r3,r11,1
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 1);
	// bl 0x82130528
	ctx.lr = 0x8256EE94;
	sub_82130528(ctx, base);
	// lis r10,1365
	ctx.r10.s64 = 89456640;
	// lhz r30,128(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// ori r9,r10,21845
	ctx.r9.u64 = ctx.r10.u64 | 21845;
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// bgt cr6,0x8256eec8
	if (cr6.gt) goto loc_8256EEC8;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-17
	ctx.r10.s64 = -17;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// ble cr6,0x8256eecc
	if (!cr6.gt) goto loc_8256EECC;
loc_8256EEC8:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8256EECC:
	// bl 0x82130528
	ctx.lr = 0x8256EED0;
	sub_82130528(ctx, base);
	// li r28,32
	r28.s64 = 32;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256ef5c
	if (cr6.eq) goto loc_8256EF5C;
	// addi r8,r3,16
	ctx.r8.s64 = ctx.r3.s64 + 16;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// addic. r9,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r9.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// blt 0x8256ef54
	if (cr0.lt) goto loc_8256EF54;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r11,r6,65535
	r11.u64 = ctx.r6.u64 | 65535;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8256EF04:
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stb r29,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, r29.u8);
	// stb r29,5(r10)
	PPC_STORE_U8(ctx.r10.u32 + 5, r29.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// sth r11,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, r11.u16);
	// sth r11,8(r10)
	PPC_STORE_U16(ctx.r10.u32 + 8, r11.u16);
	// sth r11,10(r10)
	PPC_STORE_U16(ctx.r10.u32 + 10, r11.u16);
	// sth r11,12(r10)
	PPC_STORE_U16(ctx.r10.u32 + 12, r11.u16);
	// sth r11,14(r10)
	PPC_STORE_U16(ctx.r10.u32 + 14, r11.u16);
	// sth r11,16(r10)
	PPC_STORE_U16(ctx.r10.u32 + 16, r11.u16);
	// sth r11,18(r10)
	PPC_STORE_U16(ctx.r10.u32 + 18, r11.u16);
	// sth r11,20(r10)
	PPC_STORE_U16(ctx.r10.u32 + 20, r11.u16);
	// sth r11,22(r10)
	PPC_STORE_U16(ctx.r10.u32 + 22, r11.u16);
	// stb r29,24(r10)
	PPC_STORE_U8(ctx.r10.u32 + 24, r29.u8);
	// stb r29,25(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25, r29.u8);
	// sth r11,26(r10)
	PPC_STORE_U16(ctx.r10.u32 + 26, r11.u16);
	// stvx128 v63,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, r29.u32);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// bge 0x8256ef04
	if (!cr0.lt) goto loc_8256EF04;
loc_8256EF54:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// b 0x8256ef60
	goto loc_8256EF60;
loc_8256EF5C:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8256EF60:
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// lhz r11,128(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// rotlwi r3,r11,1
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 1);
	// bl 0x82130528
	ctx.lr = 0x8256EF70;
	sub_82130528(ctx, base);
	// lhz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8256efa8
	if (cr6.eq) goto loc_8256EFA8;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8256EF88:
	// lwz r9,136(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sthx r8,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// lhz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x8256ef88
	if (cr6.lt) goto loc_8256EF88;
loc_8256EFA8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256eaf0
	ctx.lr = 0x8256EFB8;
	sub_8256EAF0(ctx, base);
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x8256EFC0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256efe4
	if (cr6.eq) goto loc_8256EFE4;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lhz r5,38(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// clrlwi r6,r11,16
	ctx.r6.u64 = r11.u32 & 0xFFFF;
	// bl 0x8256c558
	ctx.lr = 0x8256EFE0;
	sub_8256C558(ctx, base);
	// b 0x8256efe8
	goto loc_8256EFE8;
loc_8256EFE4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8256EFE8:
	// lhz r11,130(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 130);
	// li r8,96
	ctx.r8.s64 = 96;
	// lwz r7,136(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r6,80
	ctx.r6.s64 = 80;
	// rotlwi r5,r11,1
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 1);
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhzx r9,r5,r7
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r7.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// sth r4,130(r31)
	PPC_STORE_U16(r31.u32 + 130, ctx.r4.u16);
	// lvlx128 v62,r31,r8
	temp.u32 = r31.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// add r8,r11,r9
	ctx.r8.u64 = r11.u64 + ctx.r9.u64;
	// vrlimi128 v63,v61,1,1
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 147), 1));
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// stvx128 v63,r7,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8256F040"))) PPC_WEAK_FUNC(sub_8256F040);
PPC_FUNC_IMPL(__imp__sub_8256F040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82575368
	ctx.lr = 0x8256F058;
	sub_82575368(ctx, base);
	// lhz r9,38(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256f0ac
	if (cr6.eq) goto loc_8256F0AC;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_8256F074:
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// ori r4,r5,3
	ctx.r4.u64 = ctx.r5.u64 | 3;
	// stw r4,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r4.u32);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// sthx r6,r3,r7
	PPC_STORE_U16(ctx.r3.u32 + ctx.r7.u32, ctx.r6.u16);
	// addi r7,r7,2
	ctx.r7.s64 = ctx.r7.s64 + 2;
	// lhz r9,38(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8256f074
	if (cr6.lt) goto loc_8256F074;
loc_8256F0AC:
	// lhz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256f0e0
	if (cr6.eq) goto loc_8256F0E0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8256F0C0:
	// lwz r8,136(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sthx r7,r9,r8
	PPC_STORE_U16(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// lhz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x8256f0c0
	if (cr6.lt) goto loc_8256F0C0;
loc_8256F0E0:
	// lhz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,0
	ctx.r7.s64 = 0;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// ori r11,r7,65535
	r11.u64 = ctx.r7.u64 | 65535;
	// addi r9,r5,1
	ctx.r9.s64 = ctx.r5.s64 + 1;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// blt cr6,0x8256f24c
	if (cr6.lt) goto loc_8256F24C;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r9,0,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// add r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 + ctx.r8.u64;
	// rlwinm r7,r9,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r8,r4,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
loc_8256F11C:
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r6,r8,-144
	ctx.r6.s64 = ctx.r8.s64 + -144;
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stb r10,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, ctx.r10.u8);
	// stb r10,5(r9)
	PPC_STORE_U8(ctx.r9.u32 + 5, ctx.r10.u8);
	// sth r11,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, r11.u16);
	// sth r11,8(r9)
	PPC_STORE_U16(ctx.r9.u32 + 8, r11.u16);
	// sth r11,10(r9)
	PPC_STORE_U16(ctx.r9.u32 + 10, r11.u16);
	// sth r11,12(r9)
	PPC_STORE_U16(ctx.r9.u32 + 12, r11.u16);
	// sth r11,14(r9)
	PPC_STORE_U16(ctx.r9.u32 + 14, r11.u16);
	// sth r11,16(r9)
	PPC_STORE_U16(ctx.r9.u32 + 16, r11.u16);
	// sth r11,18(r9)
	PPC_STORE_U16(ctx.r9.u32 + 18, r11.u16);
	// sth r11,20(r9)
	PPC_STORE_U16(ctx.r9.u32 + 20, r11.u16);
	// sth r11,22(r9)
	PPC_STORE_U16(ctx.r9.u32 + 22, r11.u16);
	// stb r10,24(r9)
	PPC_STORE_U8(ctx.r9.u32 + 24, ctx.r10.u8);
	// stb r10,25(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25, ctx.r10.u8);
	// sth r11,26(r9)
	PPC_STORE_U16(ctx.r9.u32 + 26, r11.u16);
	// stw r10,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r10.u32);
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stfs f0,-48(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -48, temp.u32);
	// stb r10,-44(r9)
	PPC_STORE_U8(ctx.r9.u32 + -44, ctx.r10.u8);
	// stb r10,-43(r9)
	PPC_STORE_U8(ctx.r9.u32 + -43, ctx.r10.u8);
	// addi r8,r8,-192
	ctx.r8.s64 = ctx.r8.s64 + -192;
	// sth r11,-42(r9)
	PPC_STORE_U16(ctx.r9.u32 + -42, r11.u16);
	// sth r11,-40(r9)
	PPC_STORE_U16(ctx.r9.u32 + -40, r11.u16);
	// sth r11,-38(r9)
	PPC_STORE_U16(ctx.r9.u32 + -38, r11.u16);
	// sth r11,-36(r9)
	PPC_STORE_U16(ctx.r9.u32 + -36, r11.u16);
	// sth r11,-34(r9)
	PPC_STORE_U16(ctx.r9.u32 + -34, r11.u16);
	// sth r11,-32(r9)
	PPC_STORE_U16(ctx.r9.u32 + -32, r11.u16);
	// sth r11,-30(r9)
	PPC_STORE_U16(ctx.r9.u32 + -30, r11.u16);
	// sth r11,-28(r9)
	PPC_STORE_U16(ctx.r9.u32 + -28, r11.u16);
	// sth r11,-26(r9)
	PPC_STORE_U16(ctx.r9.u32 + -26, r11.u16);
	// stb r10,-24(r9)
	PPC_STORE_U8(ctx.r9.u32 + -24, ctx.r10.u8);
	// stb r10,-23(r9)
	PPC_STORE_U8(ctx.r9.u32 + -23, ctx.r10.u8);
	// sth r11,-22(r9)
	PPC_STORE_U16(ctx.r9.u32 + -22, r11.u16);
	// stw r10,-20(r9)
	PPC_STORE_U32(ctx.r9.u32 + -20, ctx.r10.u32);
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// stfs f0,48(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 48, temp.u32);
	// stb r10,52(r9)
	PPC_STORE_U8(ctx.r9.u32 + 52, ctx.r10.u8);
	// stb r10,53(r9)
	PPC_STORE_U8(ctx.r9.u32 + 53, ctx.r10.u8);
	// sth r11,54(r9)
	PPC_STORE_U16(ctx.r9.u32 + 54, r11.u16);
	// sth r11,56(r9)
	PPC_STORE_U16(ctx.r9.u32 + 56, r11.u16);
	// sth r11,58(r9)
	PPC_STORE_U16(ctx.r9.u32 + 58, r11.u16);
	// sth r11,60(r9)
	PPC_STORE_U16(ctx.r9.u32 + 60, r11.u16);
	// sth r11,62(r9)
	PPC_STORE_U16(ctx.r9.u32 + 62, r11.u16);
	// sth r11,64(r9)
	PPC_STORE_U16(ctx.r9.u32 + 64, r11.u16);
	// sth r11,66(r9)
	PPC_STORE_U16(ctx.r9.u32 + 66, r11.u16);
	// sth r11,68(r9)
	PPC_STORE_U16(ctx.r9.u32 + 68, r11.u16);
	// sth r11,70(r9)
	PPC_STORE_U16(ctx.r9.u32 + 70, r11.u16);
	// stb r10,72(r9)
	PPC_STORE_U8(ctx.r9.u32 + 72, ctx.r10.u8);
	// stb r10,73(r9)
	PPC_STORE_U8(ctx.r9.u32 + 73, ctx.r10.u8);
	// sth r11,74(r9)
	PPC_STORE_U16(ctx.r9.u32 + 74, r11.u16);
	// stw r10,76(r9)
	PPC_STORE_U32(ctx.r9.u32 + 76, ctx.r10.u32);
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stb r10,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, ctx.r10.u8);
	// stb r10,5(r9)
	PPC_STORE_U8(ctx.r9.u32 + 5, ctx.r10.u8);
	// sth r11,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, r11.u16);
	// sth r11,8(r9)
	PPC_STORE_U16(ctx.r9.u32 + 8, r11.u16);
	// sth r11,10(r9)
	PPC_STORE_U16(ctx.r9.u32 + 10, r11.u16);
	// sth r11,12(r9)
	PPC_STORE_U16(ctx.r9.u32 + 12, r11.u16);
	// sth r11,14(r9)
	PPC_STORE_U16(ctx.r9.u32 + 14, r11.u16);
	// sth r11,16(r9)
	PPC_STORE_U16(ctx.r9.u32 + 16, r11.u16);
	// sth r11,18(r9)
	PPC_STORE_U16(ctx.r9.u32 + 18, r11.u16);
	// sth r11,20(r9)
	PPC_STORE_U16(ctx.r9.u32 + 20, r11.u16);
	// sth r11,22(r9)
	PPC_STORE_U16(ctx.r9.u32 + 22, r11.u16);
	// stb r10,24(r9)
	PPC_STORE_U8(ctx.r9.u32 + 24, ctx.r10.u8);
	// stb r10,25(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25, ctx.r10.u8);
	// sth r11,26(r9)
	PPC_STORE_U16(ctx.r9.u32 + 26, r11.u16);
	// stw r10,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r10.u32);
	// bne 0x8256f11c
	if (!cr0.eq) goto loc_8256F11C;
loc_8256F24C:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x8256f2b4
	if (cr6.lt) goto loc_8256F2B4;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
loc_8256F260:
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r8,r8,-48
	ctx.r8.s64 = ctx.r8.s64 + -48;
	// stfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stb r10,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, ctx.r10.u8);
	// stb r10,5(r9)
	PPC_STORE_U8(ctx.r9.u32 + 5, ctx.r10.u8);
	// sth r11,6(r9)
	PPC_STORE_U16(ctx.r9.u32 + 6, r11.u16);
	// sth r11,8(r9)
	PPC_STORE_U16(ctx.r9.u32 + 8, r11.u16);
	// sth r11,10(r9)
	PPC_STORE_U16(ctx.r9.u32 + 10, r11.u16);
	// sth r11,12(r9)
	PPC_STORE_U16(ctx.r9.u32 + 12, r11.u16);
	// sth r11,14(r9)
	PPC_STORE_U16(ctx.r9.u32 + 14, r11.u16);
	// sth r11,16(r9)
	PPC_STORE_U16(ctx.r9.u32 + 16, r11.u16);
	// sth r11,18(r9)
	PPC_STORE_U16(ctx.r9.u32 + 18, r11.u16);
	// sth r11,20(r9)
	PPC_STORE_U16(ctx.r9.u32 + 20, r11.u16);
	// sth r11,22(r9)
	PPC_STORE_U16(ctx.r9.u32 + 22, r11.u16);
	// stb r10,24(r9)
	PPC_STORE_U8(ctx.r9.u32 + 24, ctx.r10.u8);
	// stb r10,25(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25, ctx.r10.u8);
	// sth r11,26(r9)
	PPC_STORE_U16(ctx.r9.u32 + 26, r11.u16);
	// stw r10,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r10.u32);
	// bge 0x8256f260
	if (!cr0.lt) goto loc_8256F260;
loc_8256F2B4:
	// sth r10,130(r31)
	PPC_STORE_U16(r31.u32 + 130, ctx.r10.u16);
	// li r11,96
	r11.s64 = 96;
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,80
	ctx.r7.s64 = 80;
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// li r6,32
	ctx.r6.s64 = 32;
	// lhz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// rotlwi r10,r5,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// sth r8,130(r31)
	PPC_STORE_U16(r31.u32 + 130, ctx.r8.u16);
	// add r4,r5,r10
	ctx.r4.u64 = ctx.r5.u64 + ctx.r10.u64;
	// lvlx128 v62,r31,r11
	temp.u32 = r31.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v63,v61,1,1
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 147), 1));
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256F310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8256F324;
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

__attribute__((alias("__imp__sub_8256F338"))) PPC_WEAK_FUNC(sub_8256F338);
PPC_FUNC_IMPL(__imp__sub_8256F338) {
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
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256f370
	if (cr6.eq) goto loc_8256F370;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256F370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256F370:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8256f390
	if (cr6.eq) goto loc_8256F390;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256F390;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8256F390:
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82130588
	ctx.lr = 0x8256F398;
	sub_82130588(ctx, base);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// li r30,0
	r30.s64 = 0;
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256f3b4
	if (cr6.eq) goto loc_8256F3B4;
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bl 0x82130588
	ctx.lr = 0x8256F3B4;
	sub_82130588(ctx, base);
loc_8256F3B4:
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// sth r30,130(r31)
	PPC_STORE_U16(r31.u32 + 130, r30.u16);
	// sth r30,128(r31)
	PPC_STORE_U16(r31.u32 + 128, r30.u16);
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x82130588
	ctx.lr = 0x8256F3C8;
	sub_82130588(ctx, base);
	// stw r30,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r30.u32);
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// bl 0x82130588
	ctx.lr = 0x8256F3D4;
	sub_82130588(ctx, base);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// bl 0x82130588
	ctx.lr = 0x8256F3E0;
	sub_82130588(ctx, base);
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x82130588
	ctx.lr = 0x8256F3EC;
	sub_82130588(ctx, base);
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575330
	ctx.lr = 0x8256F3F8;
	sub_82575330(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r10,-23452(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x8256f40c
	if (!cr6.eq) goto loc_8256F40C;
	// stw r30,-23452(r11)
	PPC_STORE_U32(r11.u32 + -23452, r30.u32);
loc_8256F40C:
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

__attribute__((alias("__imp__sub_8256F424"))) PPC_WEAK_FUNC(sub_8256F424);
PPC_FUNC_IMPL(__imp__sub_8256F424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256F428"))) PPC_WEAK_FUNC(sub_8256F428);
PPC_FUNC_IMPL(__imp__sub_8256F428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCVRegister vTemp{};
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
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// li r9,16
	ctx.r9.s64 = 16;
	// vspltisw128 v63,1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x1)));
	// li r10,32
	ctx.r10.s64 = 32;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// lwz r4,12(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// vcuxwfp128 v60,v63,1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v63.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vslw128 v59,v62,v62
	v59.u32[0] = v62.u32[0] << (v62.u8[0] & 0x1F);
	v59.u32[1] = v62.u32[1] << (v62.u8[4] & 0x1F);
	v59.u32[2] = v62.u32[2] << (v62.u8[8] & 0x1F);
	v59.u32[3] = v62.u32[3] << (v62.u8[12] & 0x1F);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v58,v62,v62
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lvx128 v56,r11,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkd3d128 v55,v61,4
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v55 = vTemp;
	// lvx128 v46,r11,r7
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v45,v57,v54
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lvx128 v53,r4,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v52,v57,v59
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// lvx128 v51,r4,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v50,v56,v59
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// vaddfp128 v49,v51,v53
	simde_mm_store_ps(v49.f32, simde_mm_add_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v53.f32)));
	// vandc128 v48,v54,v59
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// vsubfp128 v47,v51,v53
	simde_mm_store_ps(v47.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v53.f32)));
	// vpkd3d128 v58,v62,0,1,0
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v62.f32[0] < 3.0f ? 3.0f : (v62.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v62.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v62.f32[1] < 3.0f ? 3.0f : (v62.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v62.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v62.f32[2] < 3.0f ? 3.0f : (v62.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v62.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v62.f32[3] < 3.0f ? 3.0f : (v62.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v62.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	v58.u32[0] = temp.u32;
	// vmrghw128 v44,v56,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vmrghw128 v43,v50,v61
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
	// vmrghw128 v42,v52,v48
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// vmrglw128 v40,v57,v54
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vmrglw128 v38,v50,v61
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrglw128 v37,v52,v48
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vpermwi128 v41,v55,171
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x54));
	// vmrglw128 v39,v56,v46
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v36,v45,v44
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v32,v42,v43
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmulfp128 v35,v49,v60
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v60.f32)));
	// vmrghw128 v63,v37,v38
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmulfp128 v33,v47,v60
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v60.f32)));
	// vmrghw128 v34,v40,v39
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrglw128 v62,v45,v44
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrglw128 v61,v42,v43
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vand128 v60,v35,v58
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vmsum3fp128 v59,v32,v33
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vmsum3fp128 v58,v63,v33
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vmsum3fp128 v57,v61,v33
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vor128 v56,v60,v41
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v41.u8)));
	// vmsum4fp128 v55,v34,v56
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v56.f32), 0xFF));
	// vmsum4fp128 v54,v36,v56
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v56.f32), 0xFF));
	// vmsum4fp128 v53,v62,v56
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v56.f32), 0xFF));
	// vmrghw128 v52,v59,v58
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v51,v52,v57
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v50,v54,v55
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v49,v50,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vaddfp128 v48,v51,v49
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)));
	// vsubfp128 v47,v49,v51
	simde_mm_store_ps(v47.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v51.f32)));
	// stvx128 v48,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8256F548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8256F55C"))) PPC_WEAK_FUNC(sub_8256F55C);
PPC_FUNC_IMPL(__imp__sub_8256F55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256F560"))) PPC_WEAK_FUNC(sub_8256F560);
PPC_FUNC_IMPL(__imp__sub_8256F560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8256F568;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8256F590;
	sub_821C8FE0(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lbz r9,-23456(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -23456);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8256f748
	if (cr6.eq) goto loc_8256F748;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lwz r11,8756(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8756);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// ble cr6,0x8256f748
	if (!cr6.gt) goto loc_8256F748;
	// rlwinm r10,r28,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8256F5C0;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r7,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x8256F5D8;
	sub_823DBFF4(ctx, base);
	// lwz r6,0(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stwux r6,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r1.u32 = ea;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x8256f6f8
	if (!cr6.gt) goto loc_8256F6F8;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// vspltisw128 v60,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x1)));
	// subf r4,r29,r27
	ctx.r4.s64 = r27.s64 - r29.s64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// vupkd3d128 v59,v61,4
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v59 = vTemp;
	// li r8,16
	ctx.r8.s64 = 16;
	// vslw128 v62,v63,v63
	v62.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v62.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v62.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v62.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// li r9,32
	ctx.r9.s64 = 32;
	// vcuxwfp128 v60,v60,1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v60.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// li r30,48
	r30.s64 = 48;
	// vpermwi128 v59,v59,171
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x54));
loc_8256F624:
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// vor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r11,r5,16
	r11.s64 = ctx.r5.s64 + 16;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// vpkd3d128 v58,v63,0,1,0
	ctx.fpscr.enableFlushMode();
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v63.f32[0] < 3.0f ? 3.0f : (v63.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v63.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v63.f32[1] < 3.0f ? 3.0f : (v63.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v63.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v63.f32[2] < 3.0f ? 3.0f : (v63.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v63.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v63.f32[3] < 3.0f ? 3.0f : (v63.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v63.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	v58.u32[0] = temp.u32;
	// lwz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v55,v57,v62
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// lvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v53,v56,v62
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// lwz r3,12(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// vandc128 v52,v54,v62
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// vmrghw128 v50,v57,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lvx128 v51,r11,r30
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v43,v57,v54
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v49,v56,v51
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrglw128 v45,v56,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// lvx128 v46,r3,r9
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v47,v55,v52
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// lvx128 v44,r3,r8
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v53,v61
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vaddfp128 v42,v44,v46
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v46.f32)));
	// vmrglw128 v39,v55,v52
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vsubfp128 v40,v44,v46
	simde_mm_store_ps(v40.f32, simde_mm_sub_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v46.f32)));
	// vmrglw128 v41,v53,v61
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v37,v43,v45
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v36,v47,v48
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v38,v50,v49
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v35,v39,v41
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrglw128 v34,v50,v49
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrglw128 v33,v47,v48
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmulfp128 v32,v42,v60
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v60.f32)));
	// vmulfp128 v57,v40,v60
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v60.f32)));
	// vand128 v56,v32,v58
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vmsum3fp128 v55,v36,v57
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vmsum3fp128 v54,v35,v57
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vmsum3fp128 v53,v33,v57
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vor128 v52,v56,v59
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmsum4fp128 v51,v37,v52
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v50,v38,v52
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v49,v34,v52
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmrghw128 v48,v55,v54
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v47,v48,v53
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v46,v50,v51
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v45,v46,v49
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vaddfp128 v44,v47,v45
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v45.f32)));
	// vsubfp128 v43,v45,v47
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v44,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8256f624
	if (!cr0.eq) goto loc_8256F624;
loc_8256F6F8:
	// lwz r10,144(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 144);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r11,148(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 148);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r3,148(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 148);
	// lwz r4,-2288(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -2288);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,68(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8256F728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,148(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 148);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// lwz r3,144(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 144);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x8256f89c
	goto loc_8256F89C;
loc_8256F748:
	// rlwinm r10,r28,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// rlwinm r12,r9,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8256F758;
	sub_823DBFF4(ctx, base);
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r7,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x8256F770;
	sub_823DBFF4(ctx, base);
	// lwz r6,0(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stwux r6,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r1.u32 = ea;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x8256f890
	if (!cr6.gt) goto loc_8256F890;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// vspltisw128 v42,1
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_set1_epi32(int(0x1)));
	// subf r29,r4,r5
	r29.s64 = ctx.r5.s64 - ctx.r4.s64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// vupkd3d128 v41,v61,4
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v41 = vTemp;
	// li r8,16
	ctx.r8.s64 = 16;
	// vslw128 v62,v63,v63
	v62.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v62.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v62.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v62.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// li r9,32
	ctx.r9.s64 = 32;
	// vcuxwfp128 v60,v42,1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v42.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// li r30,48
	r30.s64 = 48;
	// vpermwi128 v59,v41,171
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0x54));
loc_8256F7BC:
	// lwz r3,0(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// vor128 v40,v63,v63
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// vpkd3d128 v40,v63,0,1,0
	ctx.fpscr.enableFlushMode();
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v63.f32[0] < 3.0f ? 3.0f : (v63.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v63.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v63.f32[1] < 3.0f ? 3.0f : (v63.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v63.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v63.f32[2] < 3.0f ? 3.0f : (v63.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v63.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v63.f32[3] < 3.0f ? 3.0f : (v63.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v63.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	v40.u32[0] = temp.u32;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r11,r8
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v37,v39,v62
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v39.u8)));
	// lvx128 v36,r11,r9
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v35,v38,v62
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v38.u8)));
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// vandc128 v34,v36,v62
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v36.u8)));
	// vmrghw128 v32,v39,v36
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// lvx128 v33,r11,r30
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v52,v39,v36
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrghw128 v58,v38,v33
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrglw128 v54,v38,v33
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// lvx128 v55,r3,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v37,v34
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// lvx128 v53,r3,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v35,v61
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vaddfp128 v51,v53,v55
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v55.f32)));
	// vmrglw128 v48,v37,v34
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vsubfp128 v49,v53,v55
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v55.f32)));
	// vmrglw128 v50,v35,v61
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v46,v52,v54
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v45,v56,v57
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v47,v32,v58
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v44,v48,v50
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v43,v32,v58
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrglw128 v42,v56,v57
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmulfp128 v41,v51,v60
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v60.f32)));
	// vmulfp128 v39,v49,v60
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v60.f32)));
	// vand128 v38,v41,v40
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)v40.u8)));
	// vmsum3fp128 v37,v45,v39
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v39.f32), 0xEF));
	// vmsum3fp128 v36,v44,v39
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v39.f32), 0xEF));
	// vmsum3fp128 v35,v42,v39
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v39.f32), 0xEF));
	// vor128 v34,v38,v59
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmsum4fp128 v33,v46,v34
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v34.f32), 0xFF));
	// vmsum4fp128 v32,v47,v34
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v34.f32), 0xFF));
	// vmsum4fp128 v58,v43,v34
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v34.f32), 0xFF));
	// vmrghw128 v57,v37,v36
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v56,v57,v35
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v55,v32,v33
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v54,v55,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vaddfp128 v53,v56,v54
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v54.f32)));
	// vsubfp128 v52,v54,v56
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v53,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8256f7bc
	if (!cr0.eq) goto loc_8256F7BC;
loc_8256F890:
	// lwz r3,144(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 144);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
loc_8256F89C:
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// clrlwi r7,r28,16
	ctx.r7.u64 = r28.u32 & 0xFFFF;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8256F8AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8256F8B4;
	sub_821C9030(ctx, base);
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8256F8BC"))) PPC_WEAK_FUNC(sub_8256F8BC);
PPC_FUNC_IMPL(__imp__sub_8256F8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256F8C0"))) PPC_WEAK_FUNC(sub_8256F8C0);
PPC_FUNC_IMPL(__imp__sub_8256F8C0) {
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
	ctx.lr = 0x8256F8C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8256F8E8;
	sub_821C8FE0(ctx, base);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8256F904;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8256f948
	if (!cr6.gt) goto loc_8256F948;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
loc_8256F91C:
	// lhz r8,42(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r5,116(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// clrlwi r3,r6,16
	ctx.r3.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r8,r3,1,15,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1FFFE;
	// sth r3,42(r31)
	PPC_STORE_U16(r31.u32 + 42, ctx.r3.u16);
	// sthx r7,r8,r5
	PPC_STORE_U16(ctx.r8.u32 + ctx.r5.u32, ctx.r7.u16);
	// bne 0x8256f91c
	if (!cr0.eq) goto loc_8256F91C;
loc_8256F948:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8256F950;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8256F958"))) PPC_WEAK_FUNC(sub_8256F958);
PPC_FUNC_IMPL(__imp__sub_8256F958) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// bl 0x821c8fe0
	ctx.lr = 0x8256F97C;
	sub_821C8FE0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// bl 0x8256ccb0
	ctx.lr = 0x8256F98C;
	sub_8256CCB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8256F998;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_8256F9B0"))) PPC_WEAK_FUNC(sub_8256F9B0);
PPC_FUNC_IMPL(__imp__sub_8256F9B0) {
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
	ctx.lr = 0x8256F9B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r4,8191
	cr6.compare<int32_t>(ctx.r4.s32, 8191, xer);
	// beq cr6,0x8256fa48
	if (cr6.eq) goto loc_8256FA48;
loc_8256F9D4:
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,132(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// add r8,r4,r11
	ctx.r8.u64 = ctx.r4.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// bne cr6,0x8256fa10
	if (!cr6.eq) goto loc_8256FA10;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// and r10,r11,r28
	ctx.r10.u64 = r11.u64 & r28.u64;
	// or r9,r11,r28
	ctx.r9.u64 = r11.u64 | r28.u64;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stb r9,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r9.u8);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r30,r6,1
	r30.u64 = ctx.r6.u64 ^ 1;
loc_8256FA10:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256fa24
	if (!cr6.eq) goto loc_8256FA24;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256cdb8
	ctx.lr = 0x8256FA24;
	sub_8256CDB8(ctx, base);
loc_8256FA24:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lhz r4,22(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256fa40
	if (cr6.eq) goto loc_8256FA40;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8256fa48
	if (!cr6.eq) goto loc_8256FA48;
loc_8256FA40:
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// bne cr6,0x8256f9d4
	if (!cr6.eq) goto loc_8256F9D4;
loc_8256FA48:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8256FA50"))) PPC_WEAK_FUNC(sub_8256FA50);
PPC_FUNC_IMPL(__imp__sub_8256FA50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r10,26
	r11.s64 = ctx.r10.s64 + 26;
	// lhz r9,26(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// beq cr6,0x8256fa90
	if (cr6.eq) goto loc_8256FA90;
	// lwz r9,112(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
loc_8256FA78:
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lhz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// bne cr6,0x8256fa78
	if (!cr6.eq) goto loc_8256FA78;
loc_8256FA90:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lwz r8,112(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rotlwi r7,r9,3
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// lhzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r8.u32);
	// sth r6,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r6.u16);
	// lbz r11,25(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25);
	// addi r5,r11,255
	ctx.r5.s64 = r11.s64 + 255;
	// stb r5,25(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256FAB4"))) PPC_WEAK_FUNC(sub_8256FAB4);
PPC_FUNC_IMPL(__imp__sub_8256FAB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256FAB8"))) PPC_WEAK_FUNC(sub_8256FAB8);
PPC_FUNC_IMPL(__imp__sub_8256FAB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lfs f1,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lhz r11,26(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 26);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
loc_8256FAE4:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lhz r11,0(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// rlwinm r7,r9,0,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,12(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f1,f13,f1,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// bne cr6,0x8256fae4
	if (!cr6.eq) goto loc_8256FAE4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256FB18"))) PPC_WEAK_FUNC(sub_8256FB18);
PPC_FUNC_IMPL(__imp__sub_8256FB18) {
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
	// bl 0x823d91cc
	ctx.lr = 0x8256FB20;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r5,3
	ctx.r7.s64 = ctx.r5.s64 + 3;
	// add r3,r4,r10
	ctx.r3.u64 = ctx.r4.u64 + ctx.r10.u64;
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r11,130(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 130);
	// rlwinm r9,r3,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,136(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r26,r30,132
	r26.s64 = r30.s64 + 132;
	// rotlwi r6,r11,1
	ctx.r6.u64 = __builtin_rotateleft32(r11.u32, 1);
	// lwz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lhzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r8.u32);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// rotlwi r11,r3,1
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// sth r9,130(r30)
	PPC_STORE_U16(r30.u32 + 130, ctx.r9.u16);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// add r4,r27,r11
	ctx.r4.u64 = r27.u64 + r11.u64;
	// sthx r27,r7,r6
	PPC_STORE_U16(ctx.r7.u32 + ctx.r6.u32, r27.u16);
	// lbz r11,24(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 24);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// rlwinm r25,r4,4,0,27
	r25.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stb r3,24(r6)
	PPC_STORE_U8(ctx.r6.u32 + 24, ctx.r3.u8);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// add r31,r10,r25
	r31.u64 = ctx.r10.u64 + r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r8,22(r31)
	PPC_STORE_U16(r31.u32 + 22, ctx.r8.u16);
	// bl 0x8256c8d8
	ctx.lr = 0x8256FB9C;
	sub_8256C8D8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r4,r30,112
	ctx.r4.s64 = r30.s64 + 112;
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f12,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// li r21,0
	r21.s64 = 0;
	// addi r3,r6,26
	ctx.r3.s64 = ctx.r6.s64 + 26;
	// addi r19,r6,44
	r19.s64 = ctx.r6.s64 + 44;
	// li r28,48
	r28.s64 = 48;
	// li r29,32
	r29.s64 = 32;
	// li r20,16
	r20.s64 = 16;
	// li r30,1
	r30.s64 = 1;
	// addi r24,r11,-2816
	r24.s64 = r11.s64 + -2816;
	// addi r23,r10,2352
	r23.s64 = ctx.r10.s64 + 2352;
	// addi r22,r9,2384
	r22.s64 = ctx.r9.s64 + 2384;
loc_8256FBE4:
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lfs f0,0(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// fmuls f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * ctx.f12.f64));
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r8,r10,0,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r10,12(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bgt cr6,0x8256fd70
	if (cr6.gt) goto loc_8256FD70;
	// lhz r7,2(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// rlwinm r7,r7,19,13,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 19) & 0x7FFFF;
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// bne cr6,0x8256fd70
	if (!cr6.eq) goto loc_8256FD70;
	// lhz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// rlwinm r18,r11,3,13,28
	r18.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x7FFF8;
	// sth r7,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r7.u16);
	// lbz r11,25(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 25);
	// addi r11,r11,255
	r11.s64 = r11.s64 + 255;
	// stb r11,25(r6)
	PPC_STORE_U8(ctx.r6.u32 + 25, r11.u8);
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// lhz r17,26(r11)
	r17.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// sthx r17,r18,r7
	PPC_STORE_U16(r18.u32 + ctx.r7.u32, r17.u16);
	// lbz r7,25(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 25);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// sth r9,26(r11)
	PPC_STORE_U16(r11.u32 + 26, ctx.r9.u16);
	// stb r7,25(r11)
	PPC_STORE_U8(r11.u32 + 25, ctx.r7.u8);
	// lfs f11,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bgt cr6,0x8256fd30
	if (cr6.gt) goto loc_8256FD30;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r11,r8,16
	r11.s64 = ctx.r8.s64 + 16;
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r23
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r24
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,12(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v59,v58
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v55,r11,r20
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v59,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v53,v55,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// lvx128 v52,r7,r28
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v51,v55,v57
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vand128 v50,v52,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v49,v56,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v48,v54,v51
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vor128 v47,v62,v50
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v50.u8)));
	// vmrghw128 v46,v56,v53
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v45,v47,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmsum4fp128 v44,v47,v48
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v48.f32), 0xFF));
	// vmsum4fp128 v43,v47,v46
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v46.f32), 0xFF));
	// vmrghw128 v42,v45,v47
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v41,v43,v44
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v40,v41,v42
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vcmpgtfp128 v39,v40,v60
	simde_mm_store_ps(v39.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v60.f32)));
	// vand128 v38,v39,v61
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vspltw128 v37,v38,1
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xAA));
	// vspltw128 v36,v38,0
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xFF));
	// vspltw128 v35,v38,2
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x55));
	// vor128 v34,v36,v37
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v37.u8)));
	// vor128 v33,v34,v35
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v35.u8)));
	// stvewx128 v33,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, v33.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// slw r8,r30,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (r30.u32 << (ctx.r8.u8 & 0x3F));
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// rlwimi r8,r11,13,0,18
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 13) & 0xFFFFE000) | (ctx.r8.u64 & 0xFFFFFFFF00001FFF);
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
loc_8256FD30:
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// fsubs f11,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// clrlwi r7,r21,24
	ctx.r7.u64 = r21.u32 & 0xFF;
	// rlwinm r9,r8,0,0,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFE000;
	// or r8,r9,r27
	ctx.r8.u64 = ctx.r9.u64 | r27.u64;
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// slw r9,r30,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (r30.u32 << (ctx.r10.u8 & 0x3F));
	// fsel f13,f11,f13,f0
	ctx.f13.f64 = ctx.f11.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// or r8,r9,r7
	ctx.r8.u64 = ctx.r9.u64 | ctx.r7.u64;
	// clrlwi r21,r8,24
	r21.u64 = ctx.r8.u32 & 0xFF;
	// b 0x8256fd74
	goto loc_8256FD74;
loc_8256FD70:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
loc_8256FD74:
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8256fbe4
	if (!cr6.eq) goto loc_8256FBE4;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,28(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// li r9,15
	ctx.r9.s64 = 15;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// slw r8,r9,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// andc r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 & ~ctx.r8.u64;
	// stw r7,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r7.u32);
	// stfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stb r21,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r21.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8256FDAC"))) PPC_WEAK_FUNC(sub_8256FDAC);
PPC_FUNC_IMPL(__imp__sub_8256FDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8256FDB0"))) PPC_WEAK_FUNC(sub_8256FDB0);
PPC_FUNC_IMPL(__imp__sub_8256FDB0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8256FDB8;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + r11.u64;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// addi r7,r9,-2816
	ctx.r7.s64 = ctx.r9.s64 + -2816;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// li r5,32
	ctx.r5.s64 = 32;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addi r29,r1,-96
	r29.s64 = ctx.r1.s64 + -96;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r3,132
	r31.s64 = ctx.r3.s64 + 132;
	// addi r27,r9,22
	r27.s64 = ctx.r9.s64 + 22;
	// addi r8,r9,26
	ctx.r8.s64 = ctx.r9.s64 + 26;
	// lhz r6,22(r9)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + 22);
	// lvx128 v62,r9,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// add r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 + ctx.r10.u64;
	// rlwinm r30,r10,4,0,27
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r30,r11
	ctx.r7.u64 = r30.u64 + r11.u64;
	// lvx128 v61,r7,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128 v60,v62,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// vand128 v59,v60,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vspltw128 v58,v59,1
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xAA));
	// vspltw128 v57,v59,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vspltw128 v56,v59,2
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x55));
	// vor128 v55,v57,v58
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vor128 v54,v55,v56
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// stvewx128 v54,r0,r29
	ea = (r29.u32) & ~0x3;
	PPC_STORE_U32(ea, v54.u32[3 - ((ea & 0xF) >> 2)]);
	// lhz r5,26(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 26);
	// lwz r26,-96(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + -96);
	// cmplwi cr6,r5,65535
	cr6.compare<uint32_t>(ctx.r5.u32, 65535, xer);
	// beq cr6,0x8256fed0
	if (cr6.eq) goto loc_8256FED0;
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r28,r26,13,0,18
	r28.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 13) & 0xFFFFE000;
	// slw r29,r10,r11
	r29.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
loc_8256FE48:
	// lhz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rotlwi r10,r5,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 3);
	// rotlwi r25,r5,3
	r25.u64 = __builtin_rotateleft32(ctx.r5.u32, 3);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// sth r10,0(r8)
	PPC_STORE_U16(ctx.r8.u32 + 0, ctx.r10.u16);
	// lbz r10,25(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 25);
	// addi r5,r10,255
	ctx.r5.s64 = ctx.r10.s64 + 255;
	// stb r5,25(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25, ctx.r5.u8);
	// lwz r5,112(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// lhz r23,26(r10)
	r23.u64 = PPC_LOAD_U16(ctx.r10.u32 + 26);
	// sthx r23,r25,r5
	PPC_STORE_U16(r25.u32 + ctx.r5.u32, r23.u16);
	// lbz r5,25(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// stb r5,25(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25, ctx.r5.u8);
	// sth r24,26(r10)
	PPC_STORE_U16(ctx.r10.u32 + 26, r24.u16);
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// rlwinm r5,r10,0,0,18
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFE000;
	// or r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 | ctx.r6.u64;
	// sth r10,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r10.u16);
	// lwz r10,28(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// stw r10,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r10.u32);
	// lhz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// clrlwi r10,r5,19
	ctx.r10.u64 = ctx.r5.u32 & 0x1FFF;
	// or r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 | r28.u64;
	// sth r5,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r5.u16);
	// lhz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// cmplwi cr6,r5,65535
	cr6.compare<uint32_t>(ctx.r5.u32, 65535, xer);
	// bne cr6,0x8256fe48
	if (!cr6.eq) goto loc_8256FE48;
loc_8256FED0:
	// addi r11,r26,3
	r11.s64 = r26.s64 + 3;
	// lis r10,0
	ctx.r10.s64 = 0;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r11,r10,65535
	r11.u64 = ctx.r10.u64 | 65535;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// sthx r11,r8,r7
	PPC_STORE_U16(ctx.r8.u32 + ctx.r7.u32, r11.u16);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// lbz r11,24(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 24);
	// addi r4,r11,255
	ctx.r4.s64 = r11.s64 + 255;
	// stb r4,24(r7)
	PPC_STORE_U8(ctx.r7.u32 + 24, ctx.r4.u8);
	// stw r6,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r6.u32);
	// sth r5,0(r27)
	PPC_STORE_U16(r27.u32 + 0, ctx.r5.u16);
	// lwz r9,136(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// lhz r7,130(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 130);
	// add r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 + ctx.r10.u64;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r4,r5,1,15,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1FFFE;
	// sth r5,130(r3)
	PPC_STORE_U16(ctx.r3.u32 + 130, ctx.r5.u16);
	// sthx r8,r4,r9
	PPC_STORE_U16(ctx.r4.u32 + ctx.r9.u32, ctx.r8.u16);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8256FF28"))) PPC_WEAK_FUNC(sub_8256FF28);
PPC_FUNC_IMPL(__imp__sub_8256FF28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r22{};
	PPCRegister r23{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,4(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// lwz r10,96(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 96);
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8256ff64
	if (!cr6.eq) goto loc_8256FF64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8256FF64:
	// lwz r11,80(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x825704b0
	if (cr6.gt) goto loc_825704B0;
	// lis r12,-32169
	r12.s64 = -2108227584;
	// addi r12,r12,-120
	r12.s64 = r12.s64 + -120;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8256FFA0;
	case 1:
		goto loc_8257005C;
	case 2:
		goto loc_825701E8;
	case 3:
		goto loc_825702BC;
	case 4:
		goto loc_8257039C;
	case 5:
		goto loc_82570448;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-96(r22)
	r18.u64 = PPC_LOAD_U32(r22.u32 + -96);
	// lwz r18,92(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 92);
	// lwz r18,488(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 488);
	// lwz r18,700(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 700);
	// lwz r18,924(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 924);
	// lwz r18,1096(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 1096);
loc_8256FFA0:
	// li r11,32
	r11.s64 = 32;
	// lvlx128 v63,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r10,-31504
	ctx.r8.s64 = ctx.r10.s64 + -31504;
	// lvx128 v59,r4,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// vspltw128 v58,v59,3
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x0));
	// vsubfp128 v62,v60,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lvx128 v0,r5,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r7,2384
	ctx.r5.s64 = ctx.r7.s64 + 2384;
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2352
	ctx.r4.s64 = ctx.r6.s64 + 2352;
	// vaddfp128 v13,v61,v58
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v57,v62,v62
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmaddfp v12,v13,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v55,v12,v12
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vand128 v56,v57,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v54,v56,v61
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vand128 v53,v55,v63
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpgefp128. v52,v54,v53
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v53.f32)));
	cr6.setFromMask(simde_mm_load_ps(v52.f32), 0xF);
	// mfocrf r3,2
	ctx.r3.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// not r11,r3
	r11.u64 = ~ctx.r3.u64;
	// rlwinm r3,r11,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825704b4
	if (cr6.eq) goto loc_825704B4;
	// vspltisw128 v51,-1
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vaddfp128 v50,v0,v13
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vslw128 v49,v51,v51
	v49.u32[0] = v51.u32[0] << (v51.u8[0] & 0x1F);
	v49.u32[1] = v51.u32[1] << (v51.u8[4] & 0x1F);
	v49.u32[2] = v51.u32[2] << (v51.u8[8] & 0x1F);
	v49.u32[3] = v51.u32[3] << (v51.u8[12] & 0x1F);
	// vandc128 v48,v62,v49
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vand128 v47,v48,v63
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v46,v50,v63
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v45,v47,v61
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vcmpgefp128. v44,v45,v46
	simde_mm_store_ps(v44.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32)));
	cr6.setFromMask(simde_mm_load_ps(v44.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// not r10,r11
	ctx.r10.u64 = ~r11.u64;
	// rlwinm r3,r10,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8257005C:
	// li r10,32
	ctx.r10.s64 = 32;
	// lvlx128 v43,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v42,v43,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v41,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,1
	r11.s64 = 1;
	// lvx128 v63,r4,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v40,v63,3
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vor128 v39,v63,v63
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lvx128 v60,r5,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaxfp128 v38,v62,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v38.f32, simde_mm_max_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// vminfp128 v37,v62,v60
	simde_mm_store_ps(v37.f32, simde_mm_min_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// vaddfp128 v58,v40,v42
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v42.f32)));
	// vsubfp128 v36,v39,v58
	simde_mm_store_ps(v36.f32, simde_mm_sub_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v58.f32)));
	// vaddfp128 v35,v39,v58
	simde_mm_store_ps(v35.f32, simde_mm_add_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v58.f32)));
	// vcmpgefp128 v34,v36,v38
	simde_mm_store_ps(v34.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v38.f32)));
	// vcmpgefp128 v33,v37,v35
	simde_mm_store_ps(v33.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v35.f32)));
	// vor128 v32,v33,v34
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)v34.u8)));
	// vspltw128 v61,v32,1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0xAA));
	// vspltw128 v59,v32,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0xFF));
	// vspltw128 v57,v32,2
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0x55));
	// vor128 v56,v59,v61
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vor128 v55,v56,v57
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vcmpequw128. v54,v55,v41
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	cr6.setFromMask(simde_mm_load_ps(v54.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825701c8
	if (cr6.eq) goto loc_825701C8;
	// vsubfp128 v61,v62,v63
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vsubfp128 v60,v60,v62
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// li r11,0
	r11.s64 = 0;
	// vslw128 v53,v63,v63
	v53.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v53.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v53.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v53.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vslw128 v52,v63,v63
	v52.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v52.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v52.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v52.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vslw128 v51,v63,v63
	v51.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v51.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v51.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v51.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vspltw128 v56,v61,1
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vspltw128 v59,v60,1
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vspltw128 v62,v60,2
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vspltw128 v57,v61,2
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vandc128 v50,v59,v53
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vandc128 v49,v62,v52
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vmulfp128 v0,v56,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v13,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vaddfp128 v48,v49,v50
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vnmsubfp v11,v12,v13,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v47,v48,v58
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v58.f32)));
	// vandc128 v46,v11,v51
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vcmpgtfp128. v45,v46,v47
	simde_mm_store_ps(v45.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v47.f32)));
	cr6.setFromMask(simde_mm_load_ps(v45.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825701c4
	if (!cr6.eq) goto loc_825701C4;
	// vspltw128 v60,v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vslw128 v44,v63,v63
	v44.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v44.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v44.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v44.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vslw128 v43,v63,v63
	v43.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v43.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v43.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v43.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vspltw128 v61,v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vor128 v0,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vslw128 v42,v63,v63
	v42.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v42.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v42.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v42.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vmulfp128 v13,v57,v60
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vandc128 v41,v60,v44
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vandc128 v40,v62,v43
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// vaddfp128 v39,v40,v41
	simde_mm_store_ps(v39.f32, simde_mm_add_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v41.f32)));
	// vnmsubfp v11,v0,v12,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v38,v39,v58
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v58.f32)));
	// vandc128 v37,v11,v42
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vcmpgtfp128. v36,v37,v38
	simde_mm_store_ps(v36.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v38.f32)));
	cr6.setFromMask(simde_mm_load_ps(v36.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825701c4
	if (!cr6.eq) goto loc_825701C4;
	// vslw128 v35,v63,v63
	v35.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v35.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v35.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v35.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vmulfp128 v0,v61,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// vslw128 v34,v63,v63
	v34.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v34.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v34.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v34.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vor128 v13,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vandc128 v33,v60,v35
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vandc128 v32,v59,v34
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vslw128 v63,v63,v63
	v63.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	v63.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	v63.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	v63.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// vaddfp128 v62,v32,v33
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v33.f32)));
	// vnmsubfp v11,v12,v13,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v61,v62,v58
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32)));
	// vandc128 v60,v11,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)));
	// vcmpgtfp128. v59,v60,v61
	simde_mm_store_ps(v59.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825701c8
	if (cr6.eq) goto loc_825701C8;
loc_825701C4:
	// li r11,1
	r11.s64 = 1;
loc_825701C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_825701E8:
	// li r11,32
	r11.s64 = 32;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,16(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v63,r4,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,-2800(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -2800);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// fmadds f7,f0,f12,f13
	ctx.f7.f64 = double(float(f0.f64 * ctx.f12.f64 + ctx.f13.f64));
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f6,f10,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fmuls f5,f6,f6
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fmuls f4,f7,f7
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fmadds f3,f8,f8,f5
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fcmpu cr6,f3,f4
	cr6.compare(ctx.f3.f64, ctx.f4.f64);
	// blt cr6,0x82570254
	if (cr6.lt) goto loc_82570254;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82570254:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x825704b4
	if (!cr6.eq) goto loc_825704B4;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f10,f12
	ctx.f10.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// bge cr6,0x825702a0
	if (!cr6.lt) goto loc_825702A0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f11,f13
	ctx.f12.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fabs f11,f12
	ctx.f11.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// blt cr6,0x825702a4
	if (cr6.lt) goto loc_825702A4;
loc_825702A0:
	// li r11,0
	r11.s64 = 0;
loc_825702A4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_825702BC:
	// li r11,32
	r11.s64 = 32;
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f0,44(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	f0.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lfs f1,36(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v57,r4,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,144
	r31.s64 = ctx.r1.s64 + 144;
	// lfs f7,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f7.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// stvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fadds f4,f7,f12
	ctx.f4.f64 = double(float(ctx.f7.f64 + ctx.f12.f64));
	// lfs f10,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f10.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f8,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f6.f64 = double(temp.f32);
	// lvlx128 v56,r5,r11
	temp.u32 = ctx.r5.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lvx128 v12,r5,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f0,f9,f12
	f0.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fadds f5,f6,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f12.f64));
	// fadds f3,f11,f12
	ctx.f3.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f4,104(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fsubs f2,f10,f12
	ctx.f2.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// stfs f5,100(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fsubs f13,f8,f12
	ctx.f13.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// stfs f3,96(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261cb10
	ctx.lr = 0x82570388;
	sub_8261CB10(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8257039C:
	// li r11,32
	r11.s64 = 32;
	// lfs f0,44(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	f0.f64 = double(temp.f32);
	// li r10,48
	ctx.r10.s64 = 48;
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r8,16
	ctx.r8.s64 = 16;
	// lvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v54,r4,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r5,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// vsubfp128 v53,v63,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v54.f32)));
	// lvx128 v52,r5,r8
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lvx128 v51,r5,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r8,2384
	ctx.r9.s64 = ctx.r8.s64 + 2384;
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stvx128 v52,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f12,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r11,64
	r11.s64 = 64;
	// stvx128 v51,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v50,r5,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v1,v50,v62
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvx128 v2,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8256e3e0
	ctx.lr = 0x82570434;
	sub_8256E3E0(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82570448:
	// li r11,44
	r11.s64 = 44;
	// vspltisw128 v49,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_set1_epi32(int(0x0)));
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v48,r0,r5
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v48,v49,1,1
	simde_mm_store_ps(v48.f32, simde_mm_blend_ps(simde_mm_load_ps(v48.f32), simde_mm_permute_ps(simde_mm_load_ps(v49.f32), 147), 1));
	// lvlx128 v47,r4,r11
	temp.u32 = ctx.r4.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v46,v47,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// lvx128 v45,r4,r10
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v43,v48,24
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xE7));
	// vsubfp128 v44,v45,v46
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v44.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32)));
	// vpermwi128 v42,v44,24
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xE7));
	// vcmpgtfp128. v41,v43,v42
	simde_mm_store_ps(v41.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v42.f32)));
	cr6.setFromMask(simde_mm_load_ps(v41.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// vaddfp128 v40,v46,v45
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v45.f32)));
	// vpermwi128 v39,v40,24
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xE7));
	// vcmpgefp128. v38,v39,v43
	simde_mm_store_ps(v38.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v43.f32)));
	cr6.setFromMask(simde_mm_load_ps(v38.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r9,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// rlwinm r6,r8,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// and r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 & ctx.r7.u64;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_825704B0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_825704B4:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825704C8"))) PPC_WEAK_FUNC(sub_825704C8);
PPC_FUNC_IMPL(__imp__sub_825704C8) {
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
	// bl 0x823d91f4
	ctx.lr = 0x825704D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,23536
	ctx.r9.s64 = 23536;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// lwz r8,23376(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,23552
	r11.s64 = r31.s64 + 23552;
	// lvx128 v62,r27,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,23684
	ctx.r5.s64 = 23684;
	// lvx128 v61,r31,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,96
	ctx.r4.s64 = 96;
	// vsubfp128 v60,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v59,r27,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r27,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,112
	ctx.r3.s64 = 112;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// vmsum3fp128 v57,v59,v60
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v56,v58,v60
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v55,v63,v60
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmrghw128 v54,v57,v57
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v53,v55,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v52,v53,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vor128 v51,v52,v52
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v50,r31,r5
	temp.u32 = r31.u32 + ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vsubfp128 v48,v52,v49
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v49.f32)));
	// vaddfp128 v47,v51,v49
	simde_mm_store_ps(v47.f32, simde_mm_add_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)));
	// stvx128 v48,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x82570590
	if (!cr6.gt) goto loc_82570590;
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// addi r28,r31,23392
	r28.s64 = r31.s64 + 23392;
loc_82570564:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8257057c
	if (cr6.eq) goto loc_8257057C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82575c38
	ctx.lr = 0x8257057C;
	sub_82575C38(ctx, base);
loc_8257057C:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,176
	r29.s64 = r29.s64 + 176;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82570564
	if (cr6.lt) goto loc_82570564;
loc_82570590:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825705d4
	if (!cr6.gt) goto loc_825705D4;
	// addi r29,r31,22672
	r29.s64 = r31.s64 + 22672;
	// addi r28,r31,23520
	r28.s64 = r31.s64 + 23520;
loc_825705A8:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825705c0
	if (cr6.eq) goto loc_825705C0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82577680
	ctx.lr = 0x825705C0;
	sub_82577680(ctx, base);
loc_825705C0:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x825705a8
	if (cr6.lt) goto loc_825705A8;
loc_825705D4:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82570618
	if (!cr6.gt) goto loc_82570618;
	// addi r29,r31,22864
	r29.s64 = r31.s64 + 22864;
	// addi r28,r31,23521
	r28.s64 = r31.s64 + 23521;
loc_825705EC:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82570604
	if (cr6.eq) goto loc_82570604;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825761f8
	ctx.lr = 0x82570604;
	sub_825761F8(ctx, base);
loc_82570604:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x825705ec
	if (cr6.lt) goto loc_825705EC;
loc_82570618:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8257065c
	if (!cr6.gt) goto loc_8257065C;
	// addi r29,r31,23088
	r29.s64 = r31.s64 + 23088;
	// addi r28,r31,23522
	r28.s64 = r31.s64 + 23522;
loc_82570630:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82570648
	if (cr6.eq) goto loc_82570648;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825766b0
	ctx.lr = 0x82570648;
	sub_825766B0(ctx, base);
loc_82570648:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,288
	r29.s64 = r29.s64 + 288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82570630
	if (cr6.lt) goto loc_82570630;
loc_8257065C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82570664"))) PPC_WEAK_FUNC(sub_82570664);
PPC_FUNC_IMPL(__imp__sub_82570664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82570668"))) PPC_WEAK_FUNC(sub_82570668);
PPC_FUNC_IMPL(__imp__sub_82570668) {
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
	// li r11,0
	r11.s64 = 0;
	// stw r11,23688(r31)
	PPC_STORE_U32(r31.u32 + 23688, r11.u32);
	// bl 0x8256e220
	ctx.lr = 0x82570688;
	sub_8256E220(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,23376(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,23684(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 23684, temp.u32);
	// ble cr6,0x82570754
	if (!cr6.gt) goto loc_82570754;
	// addi r10,r31,264
	ctx.r10.s64 = r31.s64 + 264;
	// addi r8,r31,23392
	ctx.r8.s64 = r31.s64 + 23392;
loc_825706AC:
	// lbzx r11,r8,r9
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82570740
	if (cr6.eq) goto loc_82570740;
	// lfs f0,-20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -20);
	f0.f64 = double(temp.f32);
	// addi r11,r31,23536
	r11.s64 = r31.s64 + 23536;
	// lfs f13,23540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23540);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,-16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,23544(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23544);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,-24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,23536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23536);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f5,23684(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23684);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f3,f9,f9,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f4.f64));
	// fmadds f2,f6,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fsubs f0,f5,f1
	f0.f64 = double(float(ctx.f5.f64 - ctx.f1.f64));
	// fsel f13,f0,f5,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f5.f64 : ctx.f1.f64;
	// stfs f13,23684(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 23684, temp.u32);
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,23544(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23544);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,23536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23536);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,23540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23540);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fsubs f5,f12,f11
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmuls f4,f6,f6
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fsubs f3,f10,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// fmadds f2,f5,f5,f4
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fmadds f1,f3,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f2.f64));
	// fsqrts f0,f1
	f0.f64 = double(float(sqrt(ctx.f1.f64)));
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f13,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stfs f11,23684(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 23684, temp.u32);
loc_82570740:
	// lwz r11,23376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23376);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,176
	ctx.r10.s64 = ctx.r10.s64 + 176;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blt cr6,0x825706ac
	if (cr6.lt) goto loc_825706AC;
loc_82570754:
	// lwz r11,23380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825707d8
	if (!cr6.gt) goto loc_825707D8;
	// addi r11,r31,22824
	r11.s64 = r31.s64 + 22824;
	// addi r9,r31,23520
	ctx.r9.s64 = r31.s64 + 23520;
loc_8257076C:
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825707c4
	if (cr6.eq) goto loc_825707C4;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,23540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23540);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,23544(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23544);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,23536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23536);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,23684(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23684);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f12,f12
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f2,f9,f9,f3
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f3.f64));
	// fmadds f1,f6,f6,f2
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f2.f64));
	// fsqrts f0,f1
	f0.f64 = double(float(sqrt(ctx.f1.f64)));
	// fadds f13,f0,f5
	ctx.f13.f64 = double(float(f0.f64 + ctx.f5.f64));
	// fsubs f12,f4,f13
	ctx.f12.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fsel f11,f12,f4,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// stfs f11,23684(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 23684, temp.u32);
loc_825707C4:
	// lwz r8,23380(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23380);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x8257076c
	if (cr6.lt) goto loc_8257076C;
loc_825707D8:
	// lwz r11,23384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825708a4
	if (!cr6.gt) goto loc_825708A4;
	// addi r11,r31,23032
	r11.s64 = r31.s64 + 23032;
	// addi r8,r31,23521
	ctx.r8.s64 = r31.s64 + 23521;
loc_825707F0:
	// lbzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82570890
	if (cr6.eq) goto loc_82570890;
	// lfs f0,-20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20);
	f0.f64 = double(temp.f32);
	// addi r10,r31,23536
	ctx.r10.s64 = r31.s64 + 23536;
	// lfs f13,23540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23540);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,-16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,23544(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23544);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,-24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,23536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23536);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,23684(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23684);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f12,f12
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f2,f9,f9,f3
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f3.f64));
	// fmadds f1,f6,f6,f2
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f2.f64));
	// fsqrts f0,f1
	f0.f64 = double(float(sqrt(ctx.f1.f64)));
	// fadds f13,f0,f5
	ctx.f13.f64 = double(float(f0.f64 + ctx.f5.f64));
	// fsubs f12,f4,f13
	ctx.f12.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fsel f11,f12,f4,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// stfs f11,23684(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 23684, temp.u32);
	// lfs f1,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f4,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f8,23540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23540);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// lfs f10,23544(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23544);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f2,f4,f10
	ctx.f2.f64 = double(float(ctx.f4.f64 - ctx.f10.f64));
	// lfs f9,23536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23536);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f3,f6,f6
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fsubs f0,f1,f9
	f0.f64 = double(float(ctx.f1.f64 - ctx.f9.f64));
	// fmadds f13,f2,f2,f3
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f3.f64));
	// fmadds f12,f0,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * f0.f64 + ctx.f13.f64));
	// fsqrts f10,f12
	ctx.f10.f64 = double(float(sqrt(ctx.f12.f64)));
	// fadds f9,f10,f5
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f5.f64));
	// fsubs f8,f11,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// fsel f7,f8,f11,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f11.f64 : ctx.f9.f64;
	// stfs f7,23684(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 23684, temp.u32);
loc_82570890:
	// lwz r10,23384(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 23384);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,224
	r11.s64 = r11.s64 + 224;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x825707f0
	if (cr6.lt) goto loc_825707F0;
loc_825708A4:
	// lwz r11,23388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82570940
	if (!cr6.gt) goto loc_82570940;
	// addi r11,r31,23288
	r11.s64 = r31.s64 + 23288;
	// addi r9,r31,23522
	ctx.r9.s64 = r31.s64 + 23522;
loc_825708BC:
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8257092c
	if (cr6.eq) goto loc_8257092C;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,23540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23540);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,23544(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23544);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,76(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 76);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f11,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmuls f7,f9,f9
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// lfs f6,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,23536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23536);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f3,f6,f5
	ctx.f3.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// lfs f2,80(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,23684(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 23684);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f0,f12,f12
	f0.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f13,f4,f4,f7
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f7.f64));
	// fmadds f12,f8,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + f0.f64));
	// fmadds f11,f2,f2,f13
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f13.f64));
	// fmadds f10,f3,f3,f12
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f12.f64));
	// fsqrts f9,f11
	ctx.f9.f64 = double(float(sqrt(ctx.f11.f64)));
	// fsqrts f8,f10
	ctx.f8.f64 = double(float(sqrt(ctx.f10.f64)));
	// fadds f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// fsubs f6,f1,f7
	ctx.f6.f64 = double(float(ctx.f1.f64 - ctx.f7.f64));
	// fsel f5,f6,f1,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f1.f64 : ctx.f7.f64;
	// stfs f5,23684(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 23684, temp.u32);
loc_8257092C:
	// lwz r8,23388(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23388);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,288
	r11.s64 = r11.s64 + 288;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x825708bc
	if (cr6.lt) goto loc_825708BC;
loc_82570940:
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

__attribute__((alias("__imp__sub_82570954"))) PPC_WEAK_FUNC(sub_82570954);
PPC_FUNC_IMPL(__imp__sub_82570954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82570958"))) PPC_WEAK_FUNC(sub_82570958);
PPC_FUNC_IMPL(__imp__sub_82570958) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,23376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23376);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825709b0
	if (!cr6.gt) goto loc_825709B0;
	// addi r11,r3,216
	r11.s64 = ctx.r3.s64 + 216;
	// addi r9,r3,23392
	ctx.r9.s64 = ctx.r3.s64 + 23392;
loc_82570970:
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8257099c
	if (cr6.eq) goto loc_8257099C;
	// lwz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// lwz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// or r8,r4,r6
	ctx.r8.u64 = ctx.r4.u64 | ctx.r6.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_8257099C:
	// lwz r8,23376(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23376);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,176
	r11.s64 = r11.s64 + 176;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82570970
	if (cr6.lt) goto loc_82570970;
loc_825709B0:
	// lwz r11,23380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23380);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82570a08
	if (!cr6.gt) goto loc_82570A08;
	// addi r11,r3,22744
	r11.s64 = ctx.r3.s64 + 22744;
	// addi r9,r3,23520
	ctx.r9.s64 = ctx.r3.s64 + 23520;
loc_825709C8:
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825709f4
	if (cr6.eq) goto loc_825709F4;
	// lwz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// lwz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// or r8,r4,r6
	ctx.r8.u64 = ctx.r4.u64 | ctx.r6.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_825709F4:
	// lwz r8,23380(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23380);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x825709c8
	if (cr6.lt) goto loc_825709C8;
loc_82570A08:
	// lwz r11,23384(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23384);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82570a60
	if (!cr6.gt) goto loc_82570A60;
	// addi r11,r3,22936
	r11.s64 = ctx.r3.s64 + 22936;
	// addi r9,r3,23521
	ctx.r9.s64 = ctx.r3.s64 + 23521;
loc_82570A20:
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82570a4c
	if (cr6.eq) goto loc_82570A4C;
	// lwz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// lwz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// or r8,r4,r6
	ctx.r8.u64 = ctx.r4.u64 | ctx.r6.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_82570A4C:
	// lwz r8,23384(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23384);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,224
	r11.s64 = r11.s64 + 224;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82570a20
	if (cr6.lt) goto loc_82570A20;
loc_82570A60:
	// lwz r11,23388(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23388);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r11,r3,23160
	r11.s64 = ctx.r3.s64 + 23160;
	// addi r9,r3,23522
	ctx.r9.s64 = ctx.r3.s64 + 23522;
loc_82570A78:
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82570aa4
	if (cr6.eq) goto loc_82570AA4;
	// lwz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// lwz r4,-4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// or r8,r4,r6
	ctx.r8.u64 = ctx.r4.u64 | ctx.r6.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_82570AA4:
	// lwz r8,23388(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23388);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,288
	r11.s64 = r11.s64 + 288;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82570a78
	if (cr6.lt) goto loc_82570A78;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82570ABC"))) PPC_WEAK_FUNC(sub_82570ABC);
PPC_FUNC_IMPL(__imp__sub_82570ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82570AC0"))) PPC_WEAK_FUNC(sub_82570AC0);
PPC_FUNC_IMPL(__imp__sub_82570AC0) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82570AC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// sth r28,58(r30)
	PPC_STORE_U16(r30.u32 + 58, r28.u16);
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x82570c24
	if (cr6.lt) goto loc_82570C24;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// ble cr6,0x82570c00
	if (!cr6.gt) goto loc_82570C00;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x82570c24
	if (!cr6.eq) goto loc_82570C24;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256bf40
	ctx.lr = 0x82570B0C;
	sub_8256BF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82570b98
	if (cr6.eq) goto loc_82570B98;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,23684
	r11.s64 = 23684;
	// li r10,23552
	ctx.r10.s64 = 23552;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,80
	ctx.r8.s64 = 80;
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
	// li r7,16
	ctx.r7.s64 = 16;
	// lvlx128 v61,r30,r11
	temp.u32 = r30.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r6,32
	ctx.r6.s64 = 32;
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// li r5,48
	ctx.r5.s64 = 48;
	// li r11,64
	r11.s64 = 64;
	// lvx128 v59,r30,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v59,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r28.u32);
	// stvx128 v59,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82570B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82570B98:
	// lwz r11,756(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 756);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82570bb4
	if (cr6.eq) goto loc_82570BB4;
	// addi r11,r11,53
	r11.s64 = r11.s64 + 53;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r10,r31
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r31.u32);
	// b 0x82570bb8
	goto loc_82570BB8;
loc_82570BB4:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82570BB8:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sth r28,58(r30)
	PPC_STORE_U16(r30.u32 + 58, r28.u16);
	// sth r11,56(r30)
	PPC_STORE_U16(r30.u32 + 56, r11.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82570c24
	if (cr6.eq) goto loc_82570C24;
	// lwz r11,756(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 756);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r9,r11,314
	ctx.r9.s64 = r11.s64 + 314;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + r31.u32);
	// rotlwi r6,r7,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// lhzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + ctx.r10.u32);
	// rotlwi r10,r5,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 4);
	// sth r5,60(r30)
	PPC_STORE_U16(r30.u32 + 60, ctx.r5.u16);
	// lwz r11,140(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82570C00:
	// lwz r11,204(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 204);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// sth r10,56(r30)
	PPC_STORE_U16(r30.u32 + 56, ctx.r10.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82570c24
	if (cr6.eq) goto loc_82570C24;
	// sth r28,60(r30)
	PPC_STORE_U16(r30.u32 + 60, r28.u16);
	// lwz r3,140(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82570C24:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82570C30"))) PPC_WEAK_FUNC(sub_82570C30);
PPC_FUNC_IMPL(__imp__sub_82570C30) {
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
	// bl 0x821c8fe0
	ctx.lr = 0x82570C5C;
	sub_821C8FE0(ctx, base);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r7,r30,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// li r10,1
	ctx.r10.s64 = 1;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwimi r9,r10,0,30,31
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x3) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFC);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// bl 0x8256ce68
	ctx.lr = 0x82570C84;
	sub_8256CE68(ctx, base);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// li r6,2
	ctx.r6.s64 = 2;
	// add r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 + r11.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lhz r7,2(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// clrlwi r4,r7,19
	ctx.r4.u64 = ctx.r7.u32 & 0x1FFF;
	// bl 0x8256f9b0
	ctx.lr = 0x82570CA0;
	sub_8256F9B0(ctx, base);
	// lhz r11,46(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// lhz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addis r11,r4,1
	r11.s64 = ctx.r4.s64 + 65536;
	// sth r6,46(r31)
	PPC_STORE_U16(r31.u32 + 46, ctx.r6.u16);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sth r11,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r11.u16);
	// bl 0x821c9030
	ctx.lr = 0x82570CC4;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_82570CE0"))) PPC_WEAK_FUNC(sub_82570CE0);
PPC_FUNC_IMPL(__imp__sub_82570CE0) {
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
	// bl 0x823d91e0
	ctx.lr = 0x82570CE8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// vspltisw128 v53,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lwz r30,132(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lfs f11,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r27,r4,16
	r27.u64 = ctx.r4.u32 & 0xFFFF;
	// addi r28,r31,44
	r28.s64 = r31.s64 + 44;
	// li r23,32
	r23.s64 = 32;
	// lfs f10,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f10.f64 = double(temp.f32);
loc_82570D30:
	// lbz r26,24(r31)
	r26.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// mr r25,r27
	r25.u64 = r27.u64;
	// lhz r27,22(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82570d70
	if (!cr6.eq) goto loc_82570D70;
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// lwz r10,108(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 108);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82570d70
	if (cr6.gt) goto loc_82570D70;
	// lbz r11,68(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82570d70
	if (!cr6.eq) goto loc_82570D70;
	// clrlwi r4,r25,16
	ctx.r4.u64 = r25.u32 & 0xFFFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256fdb0
	ctx.lr = 0x82570D6C;
	sub_8256FDB0(ctx, base);
	// b 0x82570de0
	goto loc_82570DE0;
loc_82570D70:
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// bne cr6,0x82570dd0
	if (!cr6.eq) goto loc_82570DD0;
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82570d9c
	if (cr6.eq) goto loc_82570D9C;
	// clrlwi r4,r25,16
	ctx.r4.u64 = r25.u32 & 0xFFFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256fab8
	ctx.lr = 0x82570D94;
	sub_8256FAB8(ctx, base);
	// fmr f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f1.f64;
	// b 0x82570da0
	goto loc_82570DA0;
loc_82570D9C:
	// fmr f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f11.f64;
loc_82570DA0:
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x82570dcc
	if (!cr6.lt) goto loc_82570DCC;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82570dcc
	if (cr6.eq) goto loc_82570DCC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256c980
	ctx.lr = 0x82570DC4;
	sub_8256C980(ctx, base);
	// fsubs f0,f1,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// fsel f12,f0,f1,f12
	ctx.f12.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : ctx.f12.f64;
loc_82570DCC:
	// stfs f12,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_82570DD0:
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// clrlwi r4,r25,16
	ctx.r4.u64 = r25.u32 & 0xFFFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256cdb8
	ctx.lr = 0x82570DE0;
	sub_8256CDB8(ctx, base);
loc_82570DE0:
	// rlwinm r11,r27,1,15,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0x1FFFE;
	// lwz r30,132(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// clrlwi r10,r27,16
	ctx.r10.u64 = r27.u32 & 0xFFFF;
	// lvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v63,v53,1,1
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v53.f32), 147), 1));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// vpermwi128 v62,v63,24
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xE7));
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// addi r28,r31,44
	r28.s64 = r31.s64 + 44;
	// lvx128 v61,r31,r23
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v60,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vsubfp128 v58,v61,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// vpermwi128 v57,v58,24
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xE7));
	// vcmpgtfp128. v56,v62,v57
	simde_mm_store_ps(v56.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32)));
	cr6.setFromMask(simde_mm_load_ps(v56.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// vaddfp128 v55,v59,v61
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32)));
	// vpermwi128 v54,v55,24
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xE7));
	// vcmpgefp128. v52,v54,v62
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v62.f32)));
	cr6.setFromMask(simde_mm_load_ps(v52.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82570d30
	if (cr6.eq) goto loc_82570D30;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// bgt cr6,0x82570d30
	if (cr6.gt) goto loc_82570D30;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82570E5C"))) PPC_WEAK_FUNC(sub_82570E5C);
PPC_FUNC_IMPL(__imp__sub_82570E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82570E60"))) PPC_WEAK_FUNC(sub_82570E60);
PPC_FUNC_IMPL(__imp__sub_82570E60) {
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
	// bl 0x823d91ec
	ctx.lr = 0x82570E68;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + r11.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f8,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f8.f64 = double(temp.f32);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// addi r30,r31,132
	r30.s64 = r31.s64 + 132;
	// addi r10,r11,44
	ctx.r10.s64 = r11.s64 + 44;
	// lfs f0,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f8
	ctx.f13.f64 = double(float(f0.f64 * ctx.f8.f64));
	// fcmpu cr6,f1,f13
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bgt cr6,0x82570fac
	if (cr6.gt) goto loc_82570FAC;
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r26,32
	r26.s64 = 32;
	// addi r27,r9,-2816
	r27.s64 = ctx.r9.s64 + -2816;
	// lfs f7,-3104(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -3104);
	ctx.f7.f64 = double(temp.f32);
loc_82570EC4:
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r11,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v61,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vspltw128 v59,v60,1
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v57,v60,2
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vor128 v56,v58,v59
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vor128 v55,v56,v57
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// stvewx128 v55,r0,r9
	ea = (ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, v55.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r8,r5,3
	ctx.r8.s64 = ctx.r5.s64 + 3;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r3,r7,r11
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + r11.u32);
	// cmplwi cr6,r3,65535
	cr6.compare<uint32_t>(ctx.r3.u32, 65535, xer);
	// bne cr6,0x82570f64
	if (!cr6.eq) goto loc_82570F64;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,104(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// srw r6,r9,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// clrlwi r9,r6,28
	ctx.r9.u64 = ctx.r6.u32 & 0xF;
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r3,r7
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, xer);
	// blt cr6,0x82570fc0
	if (cr6.lt) goto loc_82570FC0;
	// lbz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82570fc0
	if (!cr6.eq) goto loc_82570FC0;
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f7
	ctx.f13.f64 = double(float(f0.f64 * ctx.f7.f64));
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x82570fc0
	if (!cr6.gt) goto loc_82570FC0;
	// lhz r10,130(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 130);
	// lhz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 128);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x82570fc0
	if (!cr6.lt) goto loc_82570FC0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256fb18
	ctx.lr = 0x82570F64;
	sub_8256FB18(ctx, base);
loc_82570F64:
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,44
	ctx.r10.s64 = r11.s64 + 44;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 - ctx.f1.f64));
	// or r8,r9,r29
	ctx.r8.u64 = ctx.r9.u64 | r29.u64;
	// stb r8,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r8.u8);
	// fsel f12,f13,f0,f1
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f1.f64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f11,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f8
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fcmpu cr6,f1,f10
	cr6.compare(ctx.f1.f64, ctx.f10.f64);
	// ble cr6,0x82570ec4
	if (!cr6.gt) goto loc_82570EC4;
loc_82570FAC:
	// li r11,-1
	r11.s64 = -1;
	// clrlwi r3,r4,16
	ctx.r3.u64 = ctx.r4.u32 & 0xFFFF;
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82570FC0:
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// li r8,1
	ctx.r8.s64 = 1;
	// clrlwi r3,r4,16
	ctx.r3.u64 = ctx.r4.u32 & 0xFFFF;
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// stw r5,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r5.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82570FE8"))) PPC_WEAK_FUNC(sub_82570FE8);
PPC_FUNC_IMPL(__imp__sub_82570FE8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82570FF0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// lfs f10,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
loc_82571014:
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// lwz r28,132(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// rlwinm r11,r11,1,15,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1FFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r28
	r31.u64 = r11.u64 + r28.u64;
	// lbz r27,24(r31)
	r27.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// lhz r26,22(r31)
	r26.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82571070
	if (!cr6.eq) goto loc_82571070;
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// lwz r10,108(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 108);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82571070
	if (cr6.gt) goto loc_82571070;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82571070
	if (cr6.eq) goto loc_82571070;
	// lbz r11,68(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82571070
	if (!cr6.eq) goto loc_82571070;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256fdb0
	ctx.lr = 0x8257106C;
	sub_8256FDB0(ctx, base);
	// b 0x825710e0
	goto loc_825710E0;
loc_82571070:
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// bgt cr6,0x825710d0
	if (cr6.gt) goto loc_825710D0;
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8257109c
	if (cr6.eq) goto loc_8257109C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256fab8
	ctx.lr = 0x82571094;
	sub_8256FAB8(ctx, base);
	// fmr f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f1.f64;
	// b 0x825710a0
	goto loc_825710A0;
loc_8257109C:
	// fmr f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f11.f64;
loc_825710A0:
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x825710cc
	if (!cr6.lt) goto loc_825710CC;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x825710cc
	if (cr6.eq) goto loc_825710CC;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256c980
	ctx.lr = 0x825710C4;
	sub_8256C980(ctx, base);
	// fsubs f0,f1,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// fsel f12,f0,f1,f12
	ctx.f12.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : ctx.f12.f64;
loc_825710CC:
	// stfs f12,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_825710D0:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256cdb8
	ctx.lr = 0x825710E0;
	sub_8256CDB8(ctx, base);
loc_825710E0:
	// clrlwi r10,r26,16
	ctx.r10.u64 = r26.u32 & 0xFFFF;
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bne cr6,0x82571014
	if (!cr6.eq) goto loc_82571014;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_825710F8"))) PPC_WEAK_FUNC(sub_825710F8);
PPC_FUNC_IMPL(__imp__sub_825710F8) {
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
	ctx.lr = 0x82571100;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r9,132(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 132);
	// addi r11,r11,52
	r11.s64 = r11.s64 + 52;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r10,r31
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r31.u32);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r27,r11,r9
	r27.u64 = r11.u64 + ctx.r9.u64;
loc_82571134:
	// lbz r11,24(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825711e4
	if (cr6.eq) goto loc_825711E4;
loc_82571140:
	// addi r11,r28,3
	r11.s64 = r28.s64 + 3;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
loc_8257114C:
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// bge cr6,0x825711e4
	if (!cr6.lt) goto loc_825711E4;
	// lhz r30,0(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r30,65535
	cr6.compare<uint32_t>(r30.u32, 65535, xer);
	// bne cr6,0x8257116c
	if (!cr6.eq) goto loc_8257116C;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x8257114c
	goto loc_8257114C;
loc_8257116C:
	// rlwinm r9,r30,1,15,30
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0x1FFFE;
	// lwz r10,132(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 132);
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8256ff28
	ctx.lr = 0x82571194;
	sub_8256FF28(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825711a8
	if (!cr6.eq) goto loc_825711A8;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// b 0x82571140
	goto loc_82571140;
loc_825711A8:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// stb r28,140(r9)
	PPC_STORE_U8(ctx.r9.u32 + 140, r28.u8);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r11,52
	ctx.r8.s64 = r11.s64 + 52;
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r30,r7,r31
	PPC_STORE_U16(ctx.r7.u32 + r31.u32, r30.u16);
	// lbz r6,25(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 25);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82571238
	if (!cr6.eq) goto loc_82571238;
	// li r28,0
	r28.s64 = 0;
	// mr r27,r29
	r27.u64 = r29.u64;
	// b 0x82571140
	goto loc_82571140;
loc_825711E4:
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 160);
loc_825711E8:
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82571244
	if (cr6.eq) goto loc_82571244;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// addi r8,r11,52
	ctx.r8.s64 = r11.s64 + 52;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lbz r11,140(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 140);
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// lhzx r11,r7,r31
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + r31.u32);
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// beq cr6,0x825711e8
	if (cr6.eq) goto loc_825711E8;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// lwz r10,132(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 132);
	// rlwinm r11,r11,1,15,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1FFFE;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r27,r11,r10
	r27.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82571134
	goto loc_82571134;
loc_82571238:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82571244:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82571250"))) PPC_WEAK_FUNC(sub_82571250);
PPC_FUNC_IMPL(__imp__sub_82571250) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8256cec8
	ctx.lr = 0x82571270;
	sub_8256CEC8(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82571284
	if (cr6.eq) goto loc_82571284;
loc_8257127C:
	// sth r3,102(r31)
	PPC_STORE_U16(r31.u32 + 102, ctx.r3.u16);
	// b 0x825712d0
	goto loc_825712D0;
loc_82571284:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825710f8
	ctx.lr = 0x82571290;
	sub_825710F8(ctx, base);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r5,65535
	cr6.compare<uint32_t>(ctx.r5.u32, 65535, xer);
	// beq cr6,0x825712cc
	if (cr6.eq) goto loc_825712CC;
loc_8257129C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8256cf78
	ctx.lr = 0x825712A8;
	sub_8256CF78(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8257127c
	if (!cr6.eq) goto loc_8257127C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825710f8
	ctx.lr = 0x825712C0;
	sub_825710F8(ctx, base);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r5,65535
	cr6.compare<uint32_t>(ctx.r5.u32, 65535, xer);
	// bne cr6,0x8257129c
	if (!cr6.eq) goto loc_8257129C;
loc_825712CC:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_825712D0:
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

__attribute__((alias("__imp__sub_825712E8"))) PPC_WEAK_FUNC(sub_825712E8);
PPC_FUNC_IMPL(__imp__sub_825712E8) {
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
	// bl 0x82571250
	ctx.lr = 0x82571300;
	sub_82571250(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82571334
	if (cr6.eq) goto loc_82571334;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r3,r10,0,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
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
loc_82571334:
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

__attribute__((alias("__imp__sub_8257134C"))) PPC_WEAK_FUNC(sub_8257134C);
PPC_FUNC_IMPL(__imp__sub_8257134C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82571350"))) PPC_WEAK_FUNC(sub_82571350);
PPC_FUNC_IMPL(__imp__sub_82571350) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82571358;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd524
	ctx.lr = 0x82571364;
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
	// bgt cr6,0x82571d8c
	if (cr6.gt) goto loc_82571D8C;
	// lis r12,-32169
	r12.s64 = -2108227584;
	// addi r12,r12,5024
	r12.s64 = r12.s64 + 5024;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_825713D4;
	case 1:
		goto loc_825713D4;
	case 2:
		goto loc_82571D8C;
	case 3:
		goto loc_825713D4;
	case 4:
		goto loc_825713E8;
	case 5:
		goto loc_825713E8;
	case 6:
		goto loc_82571D8C;
	case 7:
		goto loc_82571D8C;
	case 8:
		goto loc_82571B20;
	case 9:
		goto loc_82571D8C;
	case 10:
		goto loc_82571450;
	case 11:
		goto loc_82571D8C;
	case 12:
		goto loc_82571C60;
	default:
		__builtin_unreachable();
	}
	// lwz r18,5076(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 5076);
	// lwz r18,5076(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 5076);
	// lwz r18,7564(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 7564);
	// lwz r18,5076(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 5076);
	// lwz r18,5096(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 5096);
	// lwz r18,5096(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 5096);
	// lwz r18,7564(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 7564);
	// lwz r18,7564(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 7564);
	// lwz r18,6944(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 6944);
	// lwz r18,7564(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 7564);
	// lwz r18,5200(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 5200);
	// lwz r18,7564(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 7564);
	// lwz r18,7264(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 7264);
loc_825713D4:
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256de38
	ctx.lr = 0x825713E4;
	sub_8256DE38(ctx, base);
	// b 0x82571d8c
	goto loc_82571D8C;
loc_825713E8:
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
	// ble cr6,0x82571430
	if (!cr6.gt) goto loc_82571430;
loc_82571400:
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
	// bl 0x8256dfb0
	ctx.lr = 0x82571420;
	sub_8256DFB0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,16
	r28.s64 = r28.s64 + 16;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x82571400
	if (cr6.lt) goto loc_82571400;
loc_82571430:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bne cr6,0x82571d8c
	if (!cr6.eq) goto loc_82571D8C;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256de38
	ctx.lr = 0x8257144C;
	sub_8256DE38(ctx, base);
	// b 0x82571d8c
	goto loc_82571D8C;
loc_82571450:
	// lwz r11,176(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82571d8c
	if (cr6.eq) goto loc_82571D8C;
	// lbz r11,25956(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25956);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82571478
	if (cr6.eq) goto loc_82571478;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x82571478
	if (cr6.eq) goto loc_82571478;
	// lhz r6,8(r19)
	ctx.r6.u64 = PPC_LOAD_U16(r19.u32 + 8);
	// b 0x8257147c
	goto loc_8257147C;
loc_82571478:
	// li r6,-1
	ctx.r6.s64 = -1;
loc_8257147C:
	// addi r23,r31,23696
	r23.s64 = r31.s64 + 23696;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82570ac0
	ctx.lr = 0x82571490;
	sub_82570AC0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82571504
	if (cr6.eq) goto loc_82571504;
loc_8257149C:
	// lbz r11,25976(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25976);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82571504
	if (cr6.eq) goto loc_82571504;
	// lwz r3,25968(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 25968);
	// lwz r11,25972(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 25972);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825714cc
	if (cr6.eq) goto loc_825714CC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825714C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x825714dc
	goto loc_825714DC;
loc_825714CC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825714DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825714DC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82571504
	if (!cr6.eq) goto loc_82571504;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256e170
	ctx.lr = 0x825714F8;
	sub_8256E170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8257149c
	if (!cr6.eq) goto loc_8257149C;
loc_82571504:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r28,0
	r28.s64 = 0;
	// lbz r10,-23460(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23460);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8257153c
	if (!cr6.eq) goto loc_8257153C;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r11,r1,106
	r11.s64 = ctx.r1.s64 + 106;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
loc_82571528:
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
	// bne 0x82571528
	if (!cr0.eq) goto loc_82571528;
loc_8257153C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82571d8c
	if (cr6.eq) goto loc_82571D8C;
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
loc_82571558:
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825715c8
	if (!cr6.eq) goto loc_825715C8;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82204be0
	ctx.lr = 0x8257157C;
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
	// bl 0x8256dfb0
	ctx.lr = 0x825715C4;
	sub_8256DFB0(ctx, base);
	// b 0x82571ab4
	goto loc_82571AB4;
loc_825715C8:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82571680
	if (!cr6.eq) goto loc_82571680;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82582c08
	ctx.lr = 0x825715DC;
	sub_82582C08(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// bl 0x822030e0
	ctx.lr = 0x825715EC;
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
	// bl 0x8256da68
	ctx.lr = 0x82571630;
	sub_8256DA68(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256de38
	ctx.lr = 0x82571640;
	sub_8256DE38(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8257165c
	if (cr6.eq) goto loc_8257165C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d158
	ctx.lr = 0x8257165C;
	sub_8256D158(ctx, base);
loc_8257165C:
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256dc00
	ctx.lr = 0x82571668;
	sub_8256DC00(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82582fd0
	ctx.lr = 0x82571674;
	sub_82582FD0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x825824f8
	ctx.lr = 0x8257167C;
	sub_825824F8(ctx, base);
	// b 0x82571ab4
	goto loc_82571AB4;
loc_82571680:
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8257184c
	if (!cr6.eq) goto loc_8257184C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lhz r24,8(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x822030e0
	ctx.lr = 0x8257169C;
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
	ctx.lr = 0x825716B4;
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
	ctx.lr = 0x825716C8;
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
	ctx.lr = 0x825716E4;
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
	// bne cr6,0x825717d8
	if (!cr6.eq) goto loc_825717D8;
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
loc_825717D8:
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
	// bl 0x8256da68
	ctx.lr = 0x825717FC;
	sub_8256DA68(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256de38
	ctx.lr = 0x8257180C;
	sub_8256DE38(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82571828
	if (cr6.eq) goto loc_82571828;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d158
	ctx.lr = 0x82571828;
	sub_8256D158(ctx, base);
loc_82571828:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256dc00
	ctx.lr = 0x82571834;
	sub_8256DC00(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82582fd0
	ctx.lr = 0x82571840;
	sub_82582FD0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82581548
	ctx.lr = 0x82571848;
	sub_82581548(ctx, base);
	// b 0x82571ab4
	goto loc_82571AB4;
loc_8257184C:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82571ab4
	if (!cr6.eq) goto loc_82571AB4;
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
	ctx.lr = 0x82571870;
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
	ctx.lr = 0x82571888;
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
	ctx.lr = 0x825718A0;
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
	ctx.lr = 0x825718B8;
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
	ctx.lr = 0x825719BC;
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
	ctx.lr = 0x82571A5C;
	sub_82580018(ctx, base);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256da68
	ctx.lr = 0x82571A68;
	sub_8256DA68(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,752
	ctx.r4.s64 = ctx.r1.s64 + 752;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256de38
	ctx.lr = 0x82571A78;
	sub_8256DE38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82571a94
	if (cr6.eq) goto loc_82571A94;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d158
	ctx.lr = 0x82571A94;
	sub_8256D158(ctx, base);
loc_82571A94:
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256dc00
	ctx.lr = 0x82571AA0;
	sub_8256DC00(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x82582fd0
	ctx.lr = 0x82571AAC;
	sub_82582FD0(ctx, base);
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x8257fe30
	ctx.lr = 0x82571AB4;
	sub_8257FE30(ctx, base);
loc_82571AB4:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256e170
	ctx.lr = 0x82571AC4;
	sub_8256E170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82571d8c
	if (cr6.eq) goto loc_82571D8C;
	// lbz r11,25976(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25976);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82571558
	if (cr6.eq) goto loc_82571558;
	// lwz r3,25968(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 25968);
	// lwz r11,25972(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 25972);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82571b00
	if (cr6.eq) goto loc_82571B00;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82571AFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82571b10
	goto loc_82571B10;
loc_82571B00:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82571B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82571B10:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82571ab4
	if (cr6.eq) goto loc_82571AB4;
	// b 0x82571558
	goto loc_82571558;
loc_82571B20:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825771a0
	ctx.lr = 0x82571B2C;
	sub_825771A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r25,16
	r25.s64 = 16;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x82571c3c
	if (cr6.eq) goto loc_82571C3C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r28,0
	r28.s64 = 0;
	// addi r26,r11,-31472
	r26.s64 = r11.s64 + -31472;
loc_82571B48:
	// lhz r11,164(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82571b80
	if (cr6.eq) goto loc_82571B80;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82571b80
	if (cr6.lt) goto loc_82571B80;
	// lwz r11,156(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 156);
	// lwz r10,144(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 144);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// bge cr6,0x82571b80
	if (!cr6.lt) goto loc_82571B80;
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82571b88
	goto loc_82571B88;
loc_82571B80:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_82571B88:
	// lwz r27,0(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82571c20
	if (cr6.eq) goto loc_82571C20;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82203400
	ctx.lr = 0x82571BA8;
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
	// bl 0x82571350
	ctx.lr = 0x82571BF4;
	sub_82571350(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82571c20
	if (cr6.eq) goto loc_82571C20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82570958
	ctx.lr = 0x82571C08;
	sub_82570958(ctx, base);
	// clrlwi r4,r30,16
	ctx.r4.u64 = r30.u32 & 0xFFFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d440
	ctx.lr = 0x82571C14;
	sub_8256D440(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d6c8
	ctx.lr = 0x82571C20;
	sub_8256D6C8(ctx, base);
loc_82571C20:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575b68
	ctx.lr = 0x82571C30;
	sub_82575B68(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x82571b48
	if (!cr6.eq) goto loc_82571B48;
loc_82571C3C:
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
	// b 0x82571d84
	goto loc_82571D84;
loc_82571C60:
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
	// ble cr6,0x82571d84
	if (!cr6.gt) goto loc_82571D84;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r25,r28
	r25.u64 = r28.u64;
	// mr r24,r28
	r24.u64 = r28.u64;
loc_82571C84:
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// lwzx r28,r11,r24
	r28.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82571d6c
	if (cr6.eq) goto loc_82571D6C;
	// lwz r11,148(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 148);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82571cc4
	if (cr6.eq) goto loc_82571CC4;
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// and r9,r10,r21
	ctx.r9.u64 = ctx.r10.u64 & r21.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82571d6c
	if (cr6.eq) goto loc_82571D6C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// and r10,r11,r20
	ctx.r10.u64 = r11.u64 & r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82571d6c
	if (cr6.eq) goto loc_82571D6C;
loc_82571CC4:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8256da68
	ctx.lr = 0x82571CD8;
	sub_8256DA68(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256ddd0
	ctx.lr = 0x82571CE4;
	sub_8256DDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82571d4c
	if (!cr6.eq) goto loc_82571D4C;
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
	// bl 0x82571350
	ctx.lr = 0x82571D08;
	sub_82571350(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82571d4c
	if (cr6.eq) goto loc_82571D4C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82570958
	ctx.lr = 0x82571D1C;
	sub_82570958(ctx, base);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d570
	ctx.lr = 0x82571D30;
	sub_8256D570(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d158
	ctx.lr = 0x82571D40;
	sub_8256D158(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82571d84
	if (!cr6.eq) goto loc_82571D84;
loc_82571D4C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256dc00
	ctx.lr = 0x82571D58;
	sub_8256DC00(ctx, base);
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x82571d6c
	if (!cr6.eq) goto loc_82571D6C;
	// lhz r11,146(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 146);
	// add r23,r11,r23
	r23.u64 = r11.u64 + r23.u64;
loc_82571D6C:
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
	// blt cr6,0x82571c84
	if (cr6.lt) goto loc_82571C84;
loc_82571D84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d950
	ctx.lr = 0x82571D8C;
	sub_8256D950(ctx, base);
loc_82571D8C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256d7f8
	ctx.lr = 0x82571D94;
	sub_8256D7F8(ctx, base);
	// addi r1,r1,1536
	ctx.r1.s64 = ctx.r1.s64 + 1536;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd7bc
	ctx.lr = 0x82571DA0;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82571DA8"))) PPC_WEAK_FUNC(sub_82571DA8);
PPC_FUNC_IMPL(__imp__sub_82571DA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,23688(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 23688);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82571dd4
	if (!cr6.eq) goto loc_82571DD4;
	// bl 0x82570668
	ctx.lr = 0x82571DD4;
	sub_82570668(ctx, base);
loc_82571DD4:
	// lwz r11,23688(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 23688);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82571ed8
	if (cr6.eq) goto loc_82571ED8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82571e3c
	if (cr6.eq) goto loc_82571E3C;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x82571f08
	if (!cr6.eq) goto loc_82571F08;
	// addi r11,r30,23568
	r11.s64 = r30.s64 + 23568;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r7,23632
	ctx.r7.s64 = 23632;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,64
	ctx.r6.s64 = 64;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,4
	ctx.r5.s64 = 4;
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r30,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r5.u32);
	// stvx128 v59,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82571f08
	goto loc_82571F08;
loc_82571E3C:
	// li r9,23664
	ctx.r9.s64 = 23664;
	// lfs f0,23684(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 23684);
	f0.f64 = double(temp.f32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f13,23680(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 23680);
	ctx.f13.f64 = double(temp.f32);
	// li r8,23648
	ctx.r8.s64 = 23648;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r7,r10,2240
	ctx.r7.s64 = ctx.r10.s64 + 2240;
	// lvx128 v58,r30,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// vor128 v56,v58,v58
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lvx128 v57,r30,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,-31664
	ctx.r4.s64 = ctx.r6.s64 + -31664;
	// stvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,-31648
	ctx.r8.s64 = ctx.r10.s64 + -31648;
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// vmsum3fp128 v55,v56,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,2528
	ctx.r3.s64 = ctx.r5.s64 + 2528;
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,3
	ctx.r9.s64 = 3;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v54,v55
	simde_mm_store_ps(v54.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v55.f32))));
	// vor128 v12,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vcmpeqfp128 v11,v54,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v53,v56,v6
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// stfs f13,32(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// b 0x82571f08
	goto loc_82571F08;
loc_82571ED8:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,23684(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 23684);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r10,23536
	ctx.r10.s64 = 23536;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,0
	ctx.r8.s64 = 0;
	// lvlx128 v52,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v51,v52,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// lvx128 v50,r30,r10
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stvx128 v50,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82571F08:
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

__attribute__((alias("__imp__sub_82571F20"))) PPC_WEAK_FUNC(sub_82571F20);
PPC_FUNC_IMPL(__imp__sub_82571F20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82571F28;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd524
	ctx.lr = 0x82571F34;
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
	// bgt cr6,0x82572994
	if (cr6.gt) goto loc_82572994;
	// lis r12,-32169
	r12.s64 = -2108227584;
	// addi r12,r12,8048
	r12.s64 = r12.s64 + 8048;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82571FA4;
	case 1:
		goto loc_82571FA4;
	case 2:
		goto loc_82572994;
	case 3:
		goto loc_82571FA4;
	case 4:
		goto loc_82571FB8;
	case 5:
		goto loc_82571FB8;
	case 6:
		goto loc_82572994;
	case 7:
		goto loc_82572994;
	case 8:
		goto loc_825726F0;
	case 9:
		goto loc_82572994;
	case 10:
		goto loc_82572020;
	case 11:
		goto loc_82572994;
	case 12:
		goto loc_8257284C;
	default:
		__builtin_unreachable();
	}
	// lwz r18,8100(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 8100);
	// lwz r18,8100(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 8100);
	// lwz r18,10644(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 10644);
	// lwz r18,8100(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 8100);
	// lwz r18,8120(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 8120);
	// lwz r18,8120(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 8120);
	// lwz r18,10644(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 10644);
	// lwz r18,10644(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 10644);
	// lwz r18,9968(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 9968);
	// lwz r18,10644(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 10644);
	// lwz r18,8224(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 8224);
	// lwz r18,10644(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 10644);
	// lwz r18,10316(r23)
	r18.u64 = PPC_LOAD_U32(r23.u32 + 10316);
loc_82571FA4:
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82579678
	ctx.lr = 0x82571FB4;
	sub_82579678(ctx, base);
	// b 0x82572994
	goto loc_82572994;
loc_82571FB8:
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
	// ble cr6,0x82572000
	if (!cr6.gt) goto loc_82572000;
loc_82571FD0:
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
	// bl 0x8257a0a0
	ctx.lr = 0x82571FF0;
	sub_8257A0A0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r28,r28,16
	r28.s64 = r28.s64 + 16;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x82571fd0
	if (cr6.lt) goto loc_82571FD0;
loc_82572000:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bne cr6,0x82572994
	if (!cr6.eq) goto loc_82572994;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82579678
	ctx.lr = 0x8257201C;
	sub_82579678(ctx, base);
	// b 0x82572994
	goto loc_82572994;
loc_82572020:
	// lwz r11,176(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82572994
	if (cr6.eq) goto loc_82572994;
	// lbz r11,2452(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82572048
	if (cr6.eq) goto loc_82572048;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x82572048
	if (cr6.eq) goto loc_82572048;
	// lhz r6,8(r19)
	ctx.r6.u64 = PPC_LOAD_U16(r19.u32 + 8);
	// b 0x8257204c
	goto loc_8257204C;
loc_82572048:
	// li r6,-1
	ctx.r6.s64 = -1;
loc_8257204C:
	// addi r23,r31,192
	r23.s64 = r31.s64 + 192;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82577950
	ctx.lr = 0x82572060;
	sub_82577950(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825720d4
	if (cr6.eq) goto loc_825720D4;
loc_8257206C:
	// lbz r11,2472(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2472);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825720d4
	if (cr6.eq) goto loc_825720D4;
	// lwz r3,2464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2464);
	// lwz r11,2468(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2468);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8257209c
	if (cr6.eq) goto loc_8257209C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82572098;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x825720ac
	goto loc_825720AC;
loc_8257209C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825720AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825720AC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825720d4
	if (!cr6.eq) goto loc_825720D4;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256e170
	ctx.lr = 0x825720C8;
	sub_8256E170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8257206c
	if (!cr6.eq) goto loc_8257206C;
loc_825720D4:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r28,0
	r28.s64 = 0;
	// lbz r10,-23460(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23460);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8257210c
	if (!cr6.eq) goto loc_8257210C;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r11,r1,106
	r11.s64 = ctx.r1.s64 + 106;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r9,r9,65535
	ctx.r9.u64 = ctx.r9.u64 | 65535;
loc_825720F8:
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
	// bne 0x825720f8
	if (!cr0.eq) goto loc_825720F8;
loc_8257210C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82572994
	if (cr6.eq) goto loc_82572994;
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
loc_82572128:
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82572198
	if (!cr6.eq) goto loc_82572198;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82204be0
	ctx.lr = 0x8257214C;
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
	// bl 0x8257a0a0
	ctx.lr = 0x82572194;
	sub_8257A0A0(ctx, base);
	// b 0x82572684
	goto loc_82572684;
loc_82572198:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82572250
	if (!cr6.eq) goto loc_82572250;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82582c08
	ctx.lr = 0x825721AC;
	sub_82582C08(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// bl 0x822030e0
	ctx.lr = 0x825721BC;
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
	// bl 0x82577730
	ctx.lr = 0x82572200;
	sub_82577730(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82579678
	ctx.lr = 0x82572210;
	sub_82579678(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8257222c
	if (cr6.eq) goto loc_8257222C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x8257222C;
	sub_8257DC50(ctx, base);
loc_8257222C:
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825777e0
	ctx.lr = 0x82572238;
	sub_825777E0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82582fd0
	ctx.lr = 0x82572244;
	sub_82582FD0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x825824f8
	ctx.lr = 0x8257224C;
	sub_825824F8(ctx, base);
	// b 0x82572684
	goto loc_82572684;
loc_82572250:
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8257241c
	if (!cr6.eq) goto loc_8257241C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lhz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lhz r24,8(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x822030e0
	ctx.lr = 0x8257226C;
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
	ctx.lr = 0x82572284;
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
	ctx.lr = 0x82572298;
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
	ctx.lr = 0x825722B4;
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
	// bne cr6,0x825723a8
	if (!cr6.eq) goto loc_825723A8;
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
loc_825723A8:
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
	// bl 0x82577730
	ctx.lr = 0x825723CC;
	sub_82577730(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82579678
	ctx.lr = 0x825723DC;
	sub_82579678(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825723f8
	if (cr6.eq) goto loc_825723F8;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x825723F8;
	sub_8257DC50(ctx, base);
loc_825723F8:
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825777e0
	ctx.lr = 0x82572404;
	sub_825777E0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82582fd0
	ctx.lr = 0x82572410;
	sub_82582FD0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82581548
	ctx.lr = 0x82572418;
	sub_82581548(ctx, base);
	// b 0x82572684
	goto loc_82572684;
loc_8257241C:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82572684
	if (!cr6.eq) goto loc_82572684;
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
	ctx.lr = 0x82572440;
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
	ctx.lr = 0x82572458;
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
	ctx.lr = 0x82572470;
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
	ctx.lr = 0x82572488;
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
	ctx.lr = 0x8257258C;
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
	ctx.lr = 0x8257262C;
	sub_82580018(ctx, base);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82577730
	ctx.lr = 0x82572638;
	sub_82577730(ctx, base);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r1,752
	ctx.r4.s64 = ctx.r1.s64 + 752;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82579678
	ctx.lr = 0x82572648;
	sub_82579678(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82572664
	if (cr6.eq) goto loc_82572664;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x82572664;
	sub_8257DC50(ctx, base);
loc_82572664:
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825777e0
	ctx.lr = 0x82572670;
	sub_825777E0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x82582fd0
	ctx.lr = 0x8257267C;
	sub_82582FD0(ctx, base);
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x8257fe30
	ctx.lr = 0x82572684;
	sub_8257FE30(ctx, base);
loc_82572684:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256e170
	ctx.lr = 0x82572694;
	sub_8256E170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82572994
	if (cr6.eq) goto loc_82572994;
	// lbz r11,2472(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2472);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82572128
	if (cr6.eq) goto loc_82572128;
	// lwz r3,2464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2464);
	// lwz r11,2468(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2468);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825726d0
	if (cr6.eq) goto loc_825726D0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825726CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x825726e0
	goto loc_825726E0;
loc_825726D0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825726E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825726E0:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82572684
	if (cr6.eq) goto loc_82572684;
	// b 0x82572128
	goto loc_82572128;
loc_825726F0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825771a0
	ctx.lr = 0x825726FC;
	sub_825771A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r25,16
	r25.s64 = 16;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x82572828
	if (cr6.eq) goto loc_82572828;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r28,0
	r28.s64 = 0;
	// addi r26,r11,-31472
	r26.s64 = r11.s64 + -31472;
loc_82572718:
	// lhz r11,164(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82572750
	if (cr6.eq) goto loc_82572750;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82572750
	if (cr6.lt) goto loc_82572750;
	// lwz r11,156(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 156);
	// lwz r10,144(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 144);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// bge cr6,0x82572750
	if (!cr6.lt) goto loc_82572750;
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82572758
	goto loc_82572758;
loc_82572750:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_82572758:
	// lwz r27,0(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8257280c
	if (cr6.eq) goto loc_8257280C;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82203400
	ctx.lr = 0x82572778;
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
	// bl 0x82571f20
	ctx.lr = 0x825727C4;
	sub_82571F20(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8257280c
	if (cr6.eq) goto loc_8257280C;
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
	ctx.lr = 0x82572800;
	sub_825789C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578ab0
	ctx.lr = 0x8257280C;
	sub_82578AB0(ctx, base);
loc_8257280C:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575b68
	ctx.lr = 0x8257281C;
	sub_82575B68(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x82572718
	if (!cr6.eq) goto loc_82572718;
loc_82572828:
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
	// b 0x8257298c
	goto loc_8257298C;
loc_8257284C:
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
	// ble cr6,0x8257298c
	if (!cr6.gt) goto loc_8257298C;
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r25,r28
	r25.u64 = r28.u64;
	// mr r24,r28
	r24.u64 = r28.u64;
loc_82572870:
	// lwz r11,128(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// lwzx r28,r11,r24
	r28.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82572974
	if (cr6.eq) goto loc_82572974;
	// lwz r11,148(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 148);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x825728b0
	if (cr6.eq) goto loc_825728B0;
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// and r9,r10,r21
	ctx.r9.u64 = ctx.r10.u64 & r21.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82572974
	if (cr6.eq) goto loc_82572974;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// and r10,r11,r20
	ctx.r10.u64 = r11.u64 & r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82572974
	if (cr6.eq) goto loc_82572974;
loc_825728B0:
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82577730
	ctx.lr = 0x825728C4;
	sub_82577730(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825778c8
	ctx.lr = 0x825728D0;
	sub_825778C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82572954
	if (!cr6.eq) goto loc_82572954;
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
	// bl 0x82571f20
	ctx.lr = 0x825728F4;
	sub_82571F20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82572954
	if (cr6.eq) goto loc_82572954;
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
	ctx.lr = 0x82572938;
	sub_82578A38(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x82572948;
	sub_8257DC50(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8257298c
	if (!cr6.eq) goto loc_8257298C;
loc_82572954:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825777e0
	ctx.lr = 0x82572960;
	sub_825777E0(ctx, base);
	// lbz r11,4(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 4);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bne cr6,0x82572974
	if (!cr6.eq) goto loc_82572974;
	// lhz r11,146(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 146);
	// add r23,r11,r23
	r23.u64 = r11.u64 + r23.u64;
loc_82572974:
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
	// blt cr6,0x82572870
	if (cr6.lt) goto loc_82572870;
loc_8257298C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82578dd8
	ctx.lr = 0x82572994;
	sub_82578DD8(ctx, base);
loc_82572994:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82575b48
	ctx.lr = 0x8257299C;
	sub_82575B48(ctx, base);
	// addi r1,r1,1536
	ctx.r1.s64 = ctx.r1.s64 + 1536;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd7bc
	ctx.lr = 0x825729A8;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_825729B0"))) PPC_WEAK_FUNC(sub_825729B0);
PPC_FUNC_IMPL(__imp__sub_825729B0) {
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
	// bl 0x823d91fc
	ctx.lr = 0x825729B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r8,44
	ctx.r8.s64 = 44;
	// vor128 v62,v1,v1
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// li r7,32
	ctx.r7.s64 = 32;
	// rlwinm r10,r4,3,13,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0x7FFF8;
	// clrlwi r29,r4,16
	r29.u64 = ctx.r4.u32 & 0xFFFF;
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// vrlimi128 v62,v63,1,1
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// li r6,1
	ctx.r6.s64 = 1;
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// vpermwi128 v57,v62,24
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xE7));
	// lvlx128 v61,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvx128 v59,r9,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// vsubfp128 v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// clrlwi r4,r5,30
	ctx.r4.u64 = ctx.r5.u32 & 0x3;
	// slw r3,r6,r4
	ctx.r3.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r4.u8 & 0x3F));
	// vpermwi128 v56,v58,24
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xE7));
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// vcmpgtfp128. v55,v57,v56
	simde_mm_store_ps(v55.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// vaddfp128 v54,v60,v59
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	// vpermwi128 v53,v54,24
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xE7));
	// vcmpgefp128. v52,v53,v57
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v57.f32)));
	cr6.setFromMask(simde_mm_load_ps(v52.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & r11.u64;
	// rlwinm r7,r8,0,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82572af0
	if (cr6.eq) goto loc_82572AF0;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// clrlwi r7,r10,16
	ctx.r7.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// or r6,r9,r7
	ctx.r6.u64 = ctx.r9.u64 | ctx.r7.u64;
	// stb r6,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r6.u8);
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// fsubs f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 - ctx.f1.f64));
	// fsel f12,f13,f0,f1
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f1.f64;
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// bl 0x82570e60
	ctx.lr = 0x82572A84;
	sub_82570E60(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// rlwinm r5,r29,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lhz r9,26(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// sthx r9,r5,r4
	PPC_STORE_U16(ctx.r5.u32 + ctx.r4.u32, ctx.r9.u16);
	// lbz r9,25(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 25);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r29,26(r11)
	PPC_STORE_U16(r11.u32 + 26, r29.u16);
	// stb r7,25(r11)
	PPC_STORE_U8(r11.u32 + 25, ctx.r7.u8);
	// lhz r5,2(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// rlwinm r4,r5,0,0,18
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFE000;
	// or r3,r4,r10
	ctx.r3.u64 = ctx.r4.u64 | ctx.r10.u64;
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r11,2(r30)
	PPC_STORE_U16(r30.u32 + 2, r11.u16);
	// beq cr6,0x82572ae4
	if (cr6.eq) goto loc_82572AE4;
	// rlwimi r11,r8,13,0,18
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 13) & 0xFFFFE000) | (r11.u64 & 0xFFFFFFFF00001FFF);
	// sth r11,2(r30)
	PPC_STORE_U16(r30.u32 + 2, r11.u16);
loc_82572AE4:
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_82572AF0:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lhz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// rlwinm r3,r11,0,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// ori r9,r10,8191
	ctx.r9.u64 = ctx.r10.u64 | 8191;
	// sth r9,2(r30)
	PPC_STORE_U16(r30.u32 + 2, ctx.r9.u16);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,72(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82572B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,8191
	ctx.r3.s64 = 8191;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82572B20"))) PPC_WEAK_FUNC(sub_82572B20);
PPC_FUNC_IMPL(__imp__sub_82572B20) {
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
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r30,r4,3,13,28
	r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0x7FFF8;
	// clrlwi r5,r4,16
	ctx.r5.u64 = ctx.r4.u32 & 0xFFFF;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// clrlwi r4,r11,19
	ctx.r4.u64 = r11.u32 & 0x1FFF;
	// cmpwi cr6,r4,8191
	cr6.compare<int32_t>(ctx.r4.s32, 8191, xer);
	// beq cr6,0x82572bb8
	if (cr6.eq) goto loc_82572BB8;
	// bl 0x8256fa50
	ctx.lr = 0x82572B58;
	sub_8256FA50(ctx, base);
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + r11.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f0,14884(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f13,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bgt cr6,0x82572ba0
	if (cr6.gt) goto loc_82572BA0;
	// lhz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r7,r10,21,11,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1FFFFC;
	// slw r6,r9,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// subf r5,r6,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r6.s64;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
loc_82572BA0:
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r8,r10,30
	ctx.r8.u64 = ctx.r10.u32 & 0x3;
	// slw r6,r9,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// bl 0x82570fe8
	ctx.lr = 0x82572BB8;
	sub_82570FE8(ctx, base);
loc_82572BB8:
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

__attribute__((alias("__imp__sub_82572BD0"))) PPC_WEAK_FUNC(sub_82572BD0);
PPC_FUNC_IMPL(__imp__sub_82572BD0) {
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
	ctx.lr = 0x82572BD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r29,132(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8256ff28
	ctx.lr = 0x82572BF4;
	sub_8256FF28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82572c34
	if (cr6.eq) goto loc_82572C34;
	// li r11,0
	r11.s64 = 0;
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// sth r11,104(r31)
	PPC_STORE_U16(r31.u32 + 104, r11.u16);
	// lbz r10,25(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 25);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82572c28
	if (!cr6.eq) goto loc_82572C28;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825710f8
	ctx.lr = 0x82572C24;
	sub_825710F8(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
loc_82572C28:
	// clrlwi r3,r11,16
	ctx.r3.u64 = r11.u32 & 0xFFFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82572C34:
	// li r11,-1
	r11.s64 = -1;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82572C48"))) PPC_WEAK_FUNC(sub_82572C48);
PPC_FUNC_IMPL(__imp__sub_82572C48) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82572bd0
	ctx.lr = 0x82572C68;
	sub_82572BD0(ctx, base);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r5,65535
	cr6.compare<uint32_t>(ctx.r5.u32, 65535, xer);
	// beq cr6,0x82572ca4
	if (cr6.eq) goto loc_82572CA4;
loc_82572C74:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8256cf78
	ctx.lr = 0x82572C80;
	sub_8256CF78(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x82572cc0
	if (!cr6.eq) goto loc_82572CC0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825710f8
	ctx.lr = 0x82572C98;
	sub_825710F8(ctx, base);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r5,65535
	cr6.compare<uint32_t>(ctx.r5.u32, 65535, xer);
	// bne cr6,0x82572c74
	if (!cr6.eq) goto loc_82572C74;
loc_82572CA4:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82572CA8:
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
loc_82572CC0:
	// sth r3,102(r31)
	PPC_STORE_U16(r31.u32 + 102, ctx.r3.u16);
	// b 0x82572ca8
	goto loc_82572CA8;
}

__attribute__((alias("__imp__sub_82572CC8"))) PPC_WEAK_FUNC(sub_82572CC8);
PPC_FUNC_IMPL(__imp__sub_82572CC8) {
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
	// bl 0x82572c48
	ctx.lr = 0x82572CE0;
	sub_82572C48(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82572d14
	if (cr6.eq) goto loc_82572D14;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r3,r10,0,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
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
loc_82572D14:
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

__attribute__((alias("__imp__sub_82572D2C"))) PPC_WEAK_FUNC(sub_82572D2C);
PPC_FUNC_IMPL(__imp__sub_82572D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82572D30"))) PPC_WEAK_FUNC(sub_82572D30);
PPC_FUNC_IMPL(__imp__sub_82572D30) {
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
	ctx.lr = 0x82572D38;
	// addi r31,r1,-368
	r31.s64 = ctx.r1.s64 + -368;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// bl 0x82203388
	ctx.lr = 0x82572D68;
	sub_82203388(ctx, base);
	// lbz r11,25957(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 25957);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82572d94
	if (!cr6.eq) goto loc_82572D94;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82571da8
	ctx.lr = 0x82572D80;
	sub_82571DA8(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// stw r24,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r24.u32);
	// stw r28,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r28.u32);
	// stw r23,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r23.u32);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
loc_82572D94:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256d078
	ctx.lr = 0x82572D9C;
	sub_8256D078(ctx, base);
	// mr r25,r27
	r25.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82572db0
	if (!cr6.eq) goto loc_82572DB0;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r25,-23452(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + -23452);
loc_82572DB0:
	// lwz r11,23796(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 23796);
	// li r22,0
	r22.s64 = 0;
	// mr r21,r22
	r21.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82572dfc
	if (!cr6.eq) goto loc_82572DFC;
	// li r12,-8192
	r12.s64 = -8192;
	// bl 0x823dbff4
	ctx.lr = 0x82572DCC;
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
	ctx.lr = 0x82572DE0;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r8,4096
	ctx.r8.s64 = 4096;
	// stw r10,23796(r29)
	PPC_STORE_U32(r29.u32 + 23796, ctx.r10.u32);
	// li r21,1
	r21.s64 = 1;
	// sth r8,23800(r29)
	PPC_STORE_U16(r29.u32 + 23800, ctx.r8.u16);
	// stb r22,23930(r29)
	PPC_STORE_U8(r29.u32 + 23930, r22.u8);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
loc_82572DFC:
	// lbz r11,25957(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 25957);
	// mr r26,r22
	r26.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82572e24
	if (!cr6.eq) goto loc_82572E24;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82572cc8
	ctx.lr = 0x82572E18;
	sub_82572CC8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,25440(r29)
	PPC_STORE_U32(r29.u32 + 25440, r30.u32);
	// b 0x82572e28
	goto loc_82572E28;
loc_82572E24:
	// lwz r30,25440(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 25440);
loc_82572E28:
	// addi r11,r29,25440
	r11.s64 = r29.s64 + 25440;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82572f50
	if (cr6.eq) goto loc_82572F50;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_82572E38:
	// cmplw cr6,r30,r20
	cr6.compare<uint32_t>(r30.u32, r20.u32, xer);
	// beq cr6,0x82572ecc
	if (cr6.eq) goto loc_82572ECC;
	// lwz r3,25960(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 25960);
	// lwz r11,25964(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 25964);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82572e60
	if (cr6.eq) goto loc_82572E60;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82572E5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82572e6c
	goto loc_82572E6C;
loc_82572E60:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82572E6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82572E6C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82572ecc
	if (cr6.eq) goto loc_82572ECC;
	// addi r28,r30,16
	r28.s64 = r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x825704c8
	ctx.lr = 0x82572E88;
	sub_825704C8(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82571350
	ctx.lr = 0x82572EA4;
	sub_82571350(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82572ecc
	if (cr6.eq) goto loc_82572ECC;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256d158
	ctx.lr = 0x82572EC0;
	sub_8256D158(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82572f50
	if (!cr6.eq) goto loc_82572F50;
loc_82572ECC:
	// lbz r11,25957(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 25957);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82572f34
	if (!cr6.eq) goto loc_82572F34;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82571250
	ctx.lr = 0x82572EE4;
	sub_82571250(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x82572f08
	if (cr6.eq) goto loc_82572F08;
	// lwz r11,112(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 112);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r30,r10,0,0,27
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// b 0x82572f0c
	goto loc_82572F0C;
loc_82572F08:
	// mr r30,r22
	r30.u64 = r22.u64;
loc_82572F0C:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpwi cr6,r26,127
	cr6.compare<int32_t>(r26.s32, 127, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// blt cr6,0x82572f24
	if (cr6.lt) goto loc_82572F24;
	// li r11,127
	r11.s64 = 127;
loc_82572F24:
	// addi r11,r11,6360
	r11.s64 = r11.s64 + 6360;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, r30.u32);
	// b 0x82572f48
	goto loc_82572F48;
loc_82572F34:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpwi cr6,r26,128
	cr6.compare<int32_t>(r26.s32, 128, xer);
	// bge cr6,0x82572f50
	if (!cr6.lt) goto loc_82572F50;
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
loc_82572F48:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82572e38
	if (!cr6.eq) goto loc_82572E38;
loc_82572F50:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82572f68
	if (cr6.eq) goto loc_82572F68;
	// stw r22,23796(r29)
	PPC_STORE_U32(r29.u32 + 23796, r22.u32);
	// sth r22,23800(r29)
	PPC_STORE_U16(r29.u32 + 23800, r22.u16);
	// stb r22,23930(r29)
	PPC_STORE_U8(r29.u32 + 23930, r22.u8);
loc_82572F68:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256d2d0
	ctx.lr = 0x82572F70;
	sub_8256D2D0(ctx, base);
	// lbz r10,244(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 244);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82572f8c
	if (cr6.eq) goto loc_82572F8C;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23388
	ctx.r3.s64 = r11.s64 + -23388;
	// bl 0x821c8f70
	ctx.lr = 0x82572F8C;
	sub_821C8F70(ctx, base);
loc_82572F8C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r31,368
	ctx.r1.s64 = r31.s64 + 368;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82572F98"))) PPC_WEAK_FUNC(sub_82572F98);
PPC_FUNC_IMPL(__imp__sub_82572F98) {
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
	ctx.lr = 0x82572FA0;
	// addi r31,r1,-368
	r31.s64 = ctx.r1.s64 + -368;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// bl 0x82203388
	ctx.lr = 0x82572FD0;
	sub_82203388(ctx, base);
	// lbz r11,2453(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2453);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82572ffc
	if (!cr6.eq) goto loc_82572FFC;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825760c8
	ctx.lr = 0x82572FE8;
	sub_825760C8(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// stw r24,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r24.u32);
	// stw r28,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r28.u32);
	// stw r23,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r23.u32);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
loc_82572FFC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825788a8
	ctx.lr = 0x82573004;
	sub_825788A8(ctx, base);
	// mr r25,r27
	r25.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82573018
	if (!cr6.eq) goto loc_82573018;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r25,-23452(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + -23452);
loc_82573018:
	// lwz r11,292(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 292);
	// li r22,0
	r22.s64 = 0;
	// mr r21,r22
	r21.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82573064
	if (!cr6.eq) goto loc_82573064;
	// li r12,-8192
	r12.s64 = -8192;
	// bl 0x823dbff4
	ctx.lr = 0x82573034;
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
	ctx.lr = 0x82573048;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r8,4096
	ctx.r8.s64 = 4096;
	// stw r10,292(r29)
	PPC_STORE_U32(r29.u32 + 292, ctx.r10.u32);
	// li r21,1
	r21.s64 = 1;
	// sth r8,296(r29)
	PPC_STORE_U16(r29.u32 + 296, ctx.r8.u16);
	// stb r22,426(r29)
	PPC_STORE_U8(r29.u32 + 426, r22.u8);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
loc_82573064:
	// lbz r11,2453(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2453);
	// mr r26,r22
	r26.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8257308c
	if (!cr6.eq) goto loc_8257308C;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82572cc8
	ctx.lr = 0x82573080;
	sub_82572CC8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,1936(r29)
	PPC_STORE_U32(r29.u32 + 1936, r30.u32);
	// b 0x82573090
	goto loc_82573090;
loc_8257308C:
	// lwz r30,1936(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 1936);
loc_82573090:
	// addi r11,r29,1936
	r11.s64 = r29.s64 + 1936;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825731b8
	if (cr6.eq) goto loc_825731B8;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_825730A0:
	// cmplw cr6,r30,r20
	cr6.compare<uint32_t>(r30.u32, r20.u32, xer);
	// beq cr6,0x82573134
	if (cr6.eq) goto loc_82573134;
	// lwz r3,2456(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 2456);
	// lwz r11,2460(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 2460);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825730c8
	if (cr6.eq) goto loc_825730C8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825730C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x825730d4
	goto loc_825730D4;
loc_825730C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x825730D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825730D4:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82573134
	if (cr6.eq) goto loc_82573134;
	// addi r28,r30,16
	r28.s64 = r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82577680
	ctx.lr = 0x825730F0;
	sub_82577680(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82571f20
	ctx.lr = 0x8257310C;
	sub_82571F20(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82573134
	if (cr6.eq) goto loc_82573134;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8257dc50
	ctx.lr = 0x82573128;
	sub_8257DC50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825731b8
	if (!cr6.eq) goto loc_825731B8;
loc_82573134:
	// lbz r11,2453(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 2453);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8257319c
	if (!cr6.eq) goto loc_8257319C;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82571250
	ctx.lr = 0x8257314C;
	sub_82571250(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x82573170
	if (cr6.eq) goto loc_82573170;
	// lwz r11,112(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 112);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r30,r10,0,0,27
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// b 0x82573174
	goto loc_82573174;
loc_82573170:
	// mr r30,r22
	r30.u64 = r22.u64;
loc_82573174:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpwi cr6,r26,127
	cr6.compare<int32_t>(r26.s32, 127, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// blt cr6,0x8257318c
	if (cr6.lt) goto loc_8257318C;
	// li r11,127
	r11.s64 = 127;
loc_8257318C:
	// addi r11,r11,484
	r11.s64 = r11.s64 + 484;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, r30.u32);
	// b 0x825731b0
	goto loc_825731B0;
loc_8257319C:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpwi cr6,r26,128
	cr6.compare<int32_t>(r26.s32, 128, xer);
	// bge cr6,0x825731b8
	if (!cr6.lt) goto loc_825731B8;
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
loc_825731B0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x825730a0
	if (!cr6.eq) goto loc_825730A0;
loc_825731B8:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825731d0
	if (cr6.eq) goto loc_825731D0;
	// stw r22,292(r29)
	PPC_STORE_U32(r29.u32 + 292, r22.u32);
	// sth r22,296(r29)
	PPC_STORE_U16(r29.u32 + 296, r22.u16);
	// stb r22,426(r29)
	PPC_STORE_U8(r29.u32 + 426, r22.u8);
loc_825731D0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82475b38
	ctx.lr = 0x825731D8;
	sub_82475B38(ctx, base);
	// lbz r10,244(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 244);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825731f4
	if (cr6.eq) goto loc_825731F4;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23388
	ctx.r3.s64 = r11.s64 + -23388;
	// bl 0x821c8f70
	ctx.lr = 0x825731F4;
	sub_821C8F70(ctx, base);
loc_825731F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r31,368
	ctx.r1.s64 = r31.s64 + 368;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82573200"))) PPC_WEAK_FUNC(sub_82573200);
PPC_FUNC_IMPL(__imp__sub_82573200) {
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
	// bl 0x823d91ec
	ctx.lr = 0x82573208;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lhz r9,42(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// addi r26,r3,2384
	r26.s64 = ctx.r3.s64 + 2384;
	// lwz r4,116(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// li r5,0
	ctx.r5.s64 = 0;
	// rotlwi r8,r9,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// lwz r7,112(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// li r25,16
	r25.s64 = 16;
	// li r27,32
	r27.s64 = 32;
	// lhzx r4,r8,r4
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r4.u32);
	// sth r6,42(r31)
	PPC_STORE_U16(r31.u32 + 42, ctx.r6.u16);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// rotlwi r8,r4,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// add r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// sth r4,8(r10)
	PPC_STORE_U16(ctx.r10.u32 + 8, ctx.r4.u16);
	// addi r7,r6,2352
	ctx.r7.s64 = ctx.r6.s64 + 2352;
	// li r6,48
	ctx.r6.s64 = 48;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r3,r3,28
	ctx.r3.u64 = ctx.r3.u32 & 0xF;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// stw r3,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r3.u32);
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r3,r8,0,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// or r8,r3,r29
	ctx.r8.u64 = ctx.r3.u64 | r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stbx r5,r9,r30
	PPC_STORE_U8(ctx.r9.u32 + r30.u32, ctx.r5.u8);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lvx128 v59,r11,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r25
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v60,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// vmrghw128 v57,v58,v59
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v55,v60,v61
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrglw128 v54,v58,v59
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v53,v56,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v52,v56,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v51,v55,v54
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// lfs f1,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v50,r7,r6
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v49,v50,v63
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v48,v62,v49
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// vmsum4fp128 v47,v48,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// vmsum4fp128 v46,v48,v51
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmsum4fp128 v45,v48,v52
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmrghw128 v44,v47,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v43,v45,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v1,v43,v44
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// bl 0x825729b0
	ctx.lr = 0x82573308;
	sub_825729B0(ctx, base);
	// cmplwi cr6,r29,1
	cr6.compare<uint32_t>(r29.u32, 1, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// blt cr6,0x82573348
	if (cr6.lt) goto loc_82573348;
	// beq cr6,0x82573334
	if (cr6.eq) goto loc_82573334;
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// bge cr6,0x82573370
	if (!cr6.lt) goto loc_82573370;
	// lhz r11,44(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,44(r31)
	PPC_STORE_U16(r31.u32 + 44, r11.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82573334:
	// lhz r11,46(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,46(r31)
	PPC_STORE_U16(r31.u32 + 46, r11.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82573348:
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, r28.u32);
	// lwz r8,124(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lhz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// rotlwi r6,r7,1
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// sthx r30,r6,r8
	PPC_STORE_U16(ctx.r6.u32 + ctx.r8.u32, r30.u16);
	// lhz r11,48(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,48(r31)
	PPC_STORE_U16(r31.u32 + 48, ctx.r5.u16);
loc_82573370:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82573378"))) PPC_WEAK_FUNC(sub_82573378);
PPC_FUNC_IMPL(__imp__sub_82573378) {
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
	ctx.lr = 0x82573380;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x825733A8;
	sub_821C8FE0(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82573200
	ctx.lr = 0x825733BC;
	sub_82573200(ctx, base);
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825733dc
	if (!cr6.eq) goto loc_825733DC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256f428
	ctx.lr = 0x825733DC;
	sub_8256F428(ctx, base);
loc_825733DC:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// clrlwi r6,r30,16
	ctx.r6.u64 = r30.u32 & 0xFFFF;
	// addi r4,r11,2272
	ctx.r4.s64 = r11.s64 + 2272;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82573400;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82573408;
	sub_821C9030(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82573414"))) PPC_WEAK_FUNC(sub_82573414);
PPC_FUNC_IMPL(__imp__sub_82573414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82573418"))) PPC_WEAK_FUNC(sub_82573418);
PPC_FUNC_IMPL(__imp__sub_82573418) {
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
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8257346c
	if (cr6.lt) goto loc_8257346C;
	// beq cr6,0x82573458
	if (cr6.eq) goto loc_82573458;
	// lhz r11,44(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 44);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,44(r3)
	PPC_STORE_U16(ctx.r3.u32 + 44, ctx.r10.u16);
	// b 0x82573480
	goto loc_82573480;
loc_82573458:
	// lhz r11,46(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 46);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,46(r3)
	PPC_STORE_U16(ctx.r3.u32 + 46, ctx.r10.u16);
	// b 0x82573480
	goto loc_82573480;
loc_8257346C:
	// bl 0x8256ce68
	ctx.lr = 0x82573470;
	sub_8256CE68(ctx, base);
	// lhz r11,48(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,48(r3)
	PPC_STORE_U16(ctx.r3.u32 + 48, ctx.r10.u16);
loc_82573480:
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// clrlwi r4,r4,16
	ctx.r4.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwinm r10,r11,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lfs f1,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82572b20
	ctx.lr = 0x8257349C;
	sub_82572B20(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825734AC"))) PPC_WEAK_FUNC(sub_825734AC);
PPC_FUNC_IMPL(__imp__sub_825734AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825734B0"))) PPC_WEAK_FUNC(sub_825734B0);
PPC_FUNC_IMPL(__imp__sub_825734B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x825734B8;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x825734EC;
	sub_821C8FE0(ctx, base);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r28,r24,3,0,28
	r28.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 3) & 0xFFFFFFF8;
	// vspltisw128 v63,1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x1)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// add r25,r28,r11
	r25.u64 = r28.u64 + r11.u64;
	// addi r7,r8,2384
	ctx.r7.s64 = ctx.r8.s64 + 2384;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// vcuxwfp128 v61,v63,1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v63.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r4,r6,2352
	ctx.r4.s64 = ctx.r6.s64 + 2352;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// li r27,32
	r27.s64 = 32;
	// li r10,16
	ctx.r10.s64 = 16;
	// rlwinm r26,r3,0,0,27
	r26.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r11,r26,16
	r11.s64 = r26.s64 + 16;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r31,112
	r29.s64 = r31.s64 + 112;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lvx128 v60,r11,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v59,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lwz r8,4(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v59,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v55,v56,v58
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// vmrglw128 v53,v56,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// lwz r6,12(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// vmrglw128 v51,v57,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v49,v57,v55
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// vmrghw128 v48,v54,v53
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// lvx128 v52,r6,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v50,v52,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v47,r4,r27
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r4,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v45,v46,v47
	simde_mm_store_ps(v45.f32, simde_mm_sub_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v47.f32)));
	// lfs f31,8(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	f31.f64 = double(temp.f32);
	// vor128 v44,v62,v50
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v50.u8)));
	// vaddfp128 v43,v46,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v43.f32, simde_mm_add_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v47.f32)));
	// vmsum4fp128 v42,v44,v51
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmsum4fp128 v41,v44,v48
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v48.f32), 0xFF));
	// vmsum4fp128 v40,v44,v49
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmulfp128 v63,v45,v61
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v61.f32)));
	// vmulfp128 v62,v43,v61
	simde_mm_store_ps(v62.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v61.f32)));
	// vmrghw128 v39,v42,v44
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v38,v40,v41
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v126,v38,v39
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// stvx128 v126,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x825736e4
	if (cr6.eq) goto loc_825736E4;
	// vor128 v37,v58,v58
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// lvx128 v35,r30,r9
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v32,v59,v59
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// lvx128 v58,r0,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r30,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v53,v60,v58
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// lvx128 v54,r30,r27
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v52,v60,v56
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vsubfp128 v33,v35,v37
	simde_mm_store_ps(v33.f32, simde_mm_sub_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v37.f32)));
	// vmsum3fp128 v48,v60,v54
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v55,v32,v58
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// lvx128 v51,r11,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v50,v32,v56
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vspltisw128 v36,-1
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vmsum3fp128 v46,v32,v54
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vaddfp128 v59,v62,v63
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmsum3fp128 v44,v51,v58
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vsubfp128 v45,v62,v63
	simde_mm_store_ps(v45.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmsum3fp128 v43,v51,v56
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vspltisw128 v34,0
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_set1_epi32(int(0x0)));
	// vmsum3fp128 v42,v51,v54
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vor128 v49,v36,v36
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v36.u8));
	// vslw128 v57,v36,v36
	v57.u32[0] = v36.u32[0] << (v36.u8[0] & 0x1F);
	v57.u32[1] = v36.u32[1] << (v36.u8[4] & 0x1F);
	v57.u32[2] = v36.u32[2] << (v36.u8[8] & 0x1F);
	v57.u32[3] = v36.u32[3] << (v36.u8[12] & 0x1F);
	// vupkd3d128 v47,v34,4
	temp.f32 = 3.0f;
	temp.s32 += v34.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v34.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v47 = vTemp;
	// vpkd3d128 v49,v36,0,1,0
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v36.f32[0] < 3.0f ? 3.0f : (v36.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v36.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v36.f32[1] < 3.0f ? 3.0f : (v36.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v36.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v36.f32[2] < 3.0f ? 3.0f : (v36.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v36.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v36.f32[3] < 3.0f ? 3.0f : (v36.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v36.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	v49.u32[0] = temp.u32;
	// vmsum3fp128 v40,v60,v33
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vmsum3fp128 v39,v32,v33
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vpermwi128 v41,v47,171
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x54));
	// vmsum3fp128 v38,v51,v33
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vand128 v37,v62,v49
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// vmrghw128 v35,v55,v53
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v33,v50,v52
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vor128 v36,v37,v41
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)v41.u8)));
	// vmrghw128 v32,v46,v48
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v62,v35,v44
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v60,v33,v43
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v58,v32,v42
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vandc128 v55,v62,v57
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vandc128 v54,v60,v57
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vandc128 v53,v58,v57
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vmrghw128 v52,v62,v58
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v49,v62,v58
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v56,v39,v40
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrghw128 v50,v54,v34
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v48,v55,v53
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrglw128 v46,v54,v34
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v51,v56,v38
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrglw128 v44,v55,v53
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v42,v48,v50
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v35,v48,v50
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v47,v60,v51
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrglw128 v43,v60,v51
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v40,v44,v46
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmsum3fp128 v38,v42,v63
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v60,v35,v63
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmrghw128 v41,v52,v47
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v39,v49,v43
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrglw128 v37,v52,v47
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmsum3fp128 v33,v40,v63
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum4fp128 v34,v41,v36
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v36.f32), 0xFF));
	// vmsum4fp128 v32,v39,v36
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v36.f32), 0xFF));
	// vmsum4fp128 v62,v37,v36
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v36.f32), 0xFF));
	// vmrghw128 v58,v38,v33
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v57,v34,v32
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v56,v58,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v55,v57,v62
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vaddfp128 v54,v55,v56
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// vsubfp128 v53,v55,v56
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// vmaxfp128 v52,v59,v54
	simde_mm_store_ps(v52.f32, simde_mm_max_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v54.f32)));
	// vminfp128 v51,v45,v53
	simde_mm_store_ps(v51.f32, simde_mm_min_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v53.f32)));
	// vaddfp128 v50,v52,v51
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v51.f32)));
	// vmulfp128 v62,v50,v61
	simde_mm_store_ps(v62.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v61.f32)));
	// vsubfp128 v63,v52,v62
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v62.f32)));
loc_825736E4:
	// vspltisw128 v49,-1
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v47,r11,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r11,r27
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v45,r11,r9
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v44,v48,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vslw128 v43,v49,v49
	v43.u32[0] = v49.u32[0] << (v49.u8[0] & 0x1F);
	v43.u32[1] = v49.u32[1] << (v49.u8[4] & 0x1F);
	v43.u32[2] = v49.u32[2] << (v49.u8[8] & 0x1F);
	v43.u32[3] = v49.u32[3] << (v49.u8[12] & 0x1F);
	// vmrghw128 v42,v47,v45
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vor128 v41,v49,v49
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vupkd3d128 v40,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v40 = vTemp;
	// vmrglw128 v39,v47,v45
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vmrglw128 v38,v48,v46
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// vandc128 v37,v48,v43
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v48.u8)));
	// vmrghw128 v36,v44,v42
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vandc128 v35,v47,v43
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v47.u8)));
	// vpkd3d128 v41,v49,0,1,0
	ctx.fpscr.enableFlushMode();
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v49.f32[0] < 3.0f ? 3.0f : (v49.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v49.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v49.f32[1] < 3.0f ? 3.0f : (v49.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v49.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v49.f32[2] < 3.0f ? 3.0f : (v49.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v49.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v49.f32[3] < 3.0f ? 3.0f : (v49.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v49.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	v41.u32[0] = temp.u32;
	// vandc128 v34,v46,v43
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v46.u8)));
	// vpermwi128 v33,v40,171
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x54));
	// vmrghw128 v32,v38,v39
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// clrlwi r23,r24,16
	r23.u64 = r24.u32 & 0xFFFF;
	// vmrglw128 v61,v44,v42
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v60,v35,v127
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vand128 v59,v62,v41
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v41.u8)));
	// vmrghw128 v58,v37,v34
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// vmrglw128 v57,v35,v127
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrglw128 v56,v37,v34
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vor128 v55,v59,v33
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v33.u8)));
	// vmrghw128 v54,v58,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v53,v58,v60
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v52,v56,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v51,v36,v55
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v55.f32), 0xFF));
	// vmsum4fp128 v50,v32,v55
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v55.f32), 0xFF));
	// vmsum3fp128 v49,v54,v63
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v48,v52,v63
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum4fp128 v47,v61,v55
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v55.f32), 0xFF));
	// vmsum3fp128 v46,v53,v63
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmrghw128 v45,v51,v50
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v44,v49,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v43,v45,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v44,v46
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vaddfp128 v41,v42,v43
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v43.f32)));
	// vsubfp128 v40,v43,v42
	simde_mm_store_ps(v40.f32, simde_mm_sub_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v42.f32)));
	// stvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825737B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825737e4
	if (cr6.eq) goto loc_825737E4;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825737E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825737E4:
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lbz r10,10201(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10201);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82573b30
	if (cr6.eq) goto loc_82573B30;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// li r10,44
	ctx.r10.s64 = 44;
	// vor128 v63,v126,v126
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// addi r22,r31,132
	r22.s64 = r31.s64 + 132;
	// lvlx128 v39,r11,r10
	temp.u32 = r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v63,v127,1,1
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v127.f32), 147), 1));
	// vspltw128 v38,v39,0
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xFF));
	// lvx128 v37,r11,r27
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v36,v63,24
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xE7));
	// vsubfp128 v35,v37,v38
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v35.f32, simde_mm_sub_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v38.f32)));
	// vpermwi128 v34,v35,24
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0xE7));
	// vcmpgtfp128. v33,v36,v34
	simde_mm_store_ps(v33.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v34.f32)));
	cr6.setFromMask(simde_mm_load_ps(v33.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// vaddfp128 v32,v38,v37
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v37.f32)));
	// vpermwi128 v62,v32,24
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0xE7));
	// vcmpgefp128. v61,v62,v36
	simde_mm_store_ps(v61.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v36.f32)));
	cr6.setFromMask(simde_mm_load_ps(v61.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// rlwinm r6,r7,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x825738a4
	if (!cr6.eq) goto loc_825738A4;
	// lhz r11,2(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 2);
	// clrlwi r10,r11,19
	ctx.r10.u64 = r11.u32 & 0x1FFF;
	// cmplwi cr6,r10,8191
	cr6.compare<uint32_t>(ctx.r10.u32, 8191, xer);
	// beq cr6,0x82573b30
	if (cr6.eq) goto loc_82573B30;
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r3,r10,-2532
	ctx.r3.s64 = ctx.r10.s64 + -2532;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82130000
	ctx.lr = 0x82573870;
	sub_82130000(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82572b20
	ctx.lr = 0x82573880;
	sub_82572B20(ctx, base);
	// lhz r9,2(r25)
	ctx.r9.u64 = PPC_LOAD_U16(r25.u32 + 2);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// ori r8,r9,8191
	ctx.r8.u64 = ctx.r9.u64 | 8191;
	// sth r8,2(r25)
	PPC_STORE_U16(r25.u32 + 2, ctx.r8.u16);
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r6,72(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 72);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x825738A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82573b30
	goto loc_82573B30;
loc_825738A4:
	// lhz r8,2(r25)
	ctx.r8.u64 = PPC_LOAD_U16(r25.u32 + 2);
	// addi r30,r25,2
	r30.s64 = r25.s64 + 2;
	// clrlwi r4,r8,19
	ctx.r4.u64 = ctx.r8.u32 & 0x1FFF;
	// cmpwi cr6,r4,8191
	cr6.compare<int32_t>(ctx.r4.s32, 8191, xer);
	// bne cr6,0x825738d0
	if (!cr6.eq) goto loc_825738D0;
	// vor128 v1,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825729b0
	ctx.lr = 0x825738CC;
	sub_825729B0(ctx, base);
	// b 0x82573b30
	goto loc_82573B30;
loc_825738D0:
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// vpermwi128 v60,v63,24
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xE7));
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,44
	ctx.r10.s64 = r11.s64 + 44;
	// lvx128 v63,r11,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v59,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vsubfp128 v57,v63,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// vpermwi128 v56,v57,24
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xE7));
	// vcmpgtfp128. v55,v60,v56
	simde_mm_store_ps(v55.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v56.f32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// vaddfp128 v54,v58,v63
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32)));
	// vpermwi128 v53,v54,24
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xE7));
	// vcmpgefp128. v52,v53,v60
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v52.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// and r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 & ctx.r9.u64;
	// li r27,1
	r27.s64 = 1;
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82573944
	if (cr6.eq) goto loc_82573944;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x8257393c
	if (!cr6.gt) goto loc_8257393C;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x82573944
	if (!cr6.eq) goto loc_82573944;
loc_8257393C:
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// b 0x82573948
	goto loc_82573948;
loc_82573944:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82573948:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// lfs f0,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f31,f12
	cr6.compare(f31.f64, ctx.f12.f64);
	// ble cr6,0x82573968
	if (!cr6.gt) goto loc_82573968;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82573968:
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r9,r8,19,13,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 19) & 0x7FFFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// beq cr6,0x82573a60
	if (cr6.eq) goto loc_82573A60;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82573b30
	if (cr6.eq) goto loc_82573B30;
	// vcmpgtfp128 v51,v126,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v63.f32)));
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r10,-2816
	ctx.r7.s64 = ctx.r10.s64 + -2816;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v50,v51,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vspltw128 v49,v50,1
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xAA));
	// vspltw128 v48,v50,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vspltw128 v47,v50,2
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x55));
	// vor128 v46,v48,v49
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// vor128 v45,v46,v47
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v47.u8)));
	// stvewx128 v45,r0,r8
	ea = (ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, v45.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x825739d8
	if (!cr6.eq) goto loc_825739D8;
	// addi r8,r10,3
	ctx.r8.s64 = ctx.r10.s64 + 3;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r7,r11
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + r11.u32);
	// cmplwi cr6,r6,65535
	cr6.compare<uint32_t>(ctx.r6.u32, 65535, xer);
	// beq cr6,0x82573b30
	if (cr6.eq) goto loc_82573B30;
loc_825739D8:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r7,r10,3
	ctx.r7.s64 = ctx.r10.s64 + 3;
	// slw r6,r27,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r6,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r6.s64;
	// stw r8,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r8.u32);
	// lhzx r3,r5,r11
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r5.u32 + r11.u32);
	// cmplwi cr6,r3,65535
	cr6.compare<uint32_t>(ctx.r3.u32, 65535, xer);
	// bne cr6,0x82573a3c
	if (!cr6.eq) goto loc_82573A3C;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,104(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// srw r6,r8,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r9.u8 & 0x3F));
	// clrlwi r8,r6,28
	ctx.r8.u64 = ctx.r6.u32 & 0xF;
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r5,r7
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r7.s32, xer);
	// bge cr6,0x82573a3c
	if (!cr6.lt) goto loc_82573A3C;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// slw r9,r27,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// rlwimi r8,r10,13,0,18
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 13) & 0xFFFFE000) | (ctx.r8.u64 & 0xFFFFFFFF00001FFF);
	// sth r8,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r8.u16);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r6,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r6.u32);
	// b 0x82573b30
	goto loc_82573B30;
loc_82573A3C:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256fa50
	ctx.lr = 0x82573A48;
	sub_8256FA50(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// slw r7,r27,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// b 0x82573ac0
	goto loc_82573AC0;
loc_82573A60:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82573a7c
	if (cr6.eq) goto loc_82573A7C;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// slw r8,r27,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r10.u8 & 0x3F));
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
loc_82573A7C:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256fa50
	ctx.lr = 0x82573A88;
	sub_8256FA50(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// slw r7,r27,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (r27.u32 << (ctx.r9.u8 & 0x3F));
	// bl 0x82570ce0
	ctx.lr = 0x82573AA8;
	sub_82570CE0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// add r7,r28,r11
	ctx.r7.u64 = r28.u64 + r11.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// clrlwi r11,r6,30
	r11.u64 = ctx.r6.u32 & 0x3;
	// slw r7,r27,r11
	ctx.r7.u64 = r11.u8 & 0x20 ? 0 : (r27.u32 << (r11.u8 & 0x3F));
loc_82573AC0:
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82570e60
	ctx.lr = 0x82573AD4;
	sub_82570E60(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// lwz r9,0(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lhz r5,26(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 26);
	// sthx r5,r28,r7
	PPC_STORE_U16(r28.u32 + ctx.r7.u32, ctx.r5.u16);
	// lbz r9,25(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 25);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// sth r23,26(r11)
	PPC_STORE_U16(r11.u32 + 26, r23.u16);
	// stb r4,25(r11)
	PPC_STORE_U8(r11.u32 + 25, ctx.r4.u8);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rlwinm r9,r11,0,0,18
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFE000;
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// beq cr6,0x82573b30
	if (cr6.eq) goto loc_82573B30;
	// rlwimi r11,r8,13,0,18
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 13) & 0xFFFFE000) | (r11.u64 & 0xFFFFFFFF00001FFF);
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
loc_82573B30:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82573B38;
	sub_821C9030(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82573B54"))) PPC_WEAK_FUNC(sub_82573B54);
PPC_FUNC_IMPL(__imp__sub_82573B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82573B58"))) PPC_WEAK_FUNC(sub_82573B58);
PPC_FUNC_IMPL(__imp__sub_82573B58) {
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
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91e8
	ctx.lr = 0x82573B60;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// lbz r10,10201(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10201);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82573ba4
	if (!cr6.eq) goto loc_82573BA4;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825734b0
	ctx.lr = 0x82573B94;
	sub_825734B0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_82573BA4:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// bl 0x821c8fe0
	ctx.lr = 0x82573BB4;
	sub_821C8FE0(ctx, base);
	// lwz r10,112(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 112);
	// rlwinm r11,r25,3,0,28
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,132(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,44(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	f0.f64 = double(temp.f32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r27,r10,0,0,27
	r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f31,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x82573c10
	if (!cr6.gt) goto loc_82573C10;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r10,-2360
	ctx.r3.s64 = ctx.r10.s64 + -2360;
	// bl 0x82130000
	ctx.lr = 0x82573C04;
	sub_82130000(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// addi r3,r9,-2472
	ctx.r3.s64 = ctx.r9.s64 + -2472;
	// bl 0x82130000
	ctx.lr = 0x82573C10;
	sub_82130000(ctx, base);
loc_82573C10:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// addi r26,r31,2
	r26.s64 = r31.s64 + 2;
	// clrlwi r4,r11,19
	ctx.r4.u64 = r11.u32 & 0x1FFF;
	// cmpwi cr6,r4,8191
	cr6.compare<int32_t>(ctx.r4.s32, 8191, xer);
	// beq cr6,0x82573ed0
	if (cr6.eq) goto loc_82573ED0;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r31,132(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f10,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f10.f64 = double(temp.f32);
	// add r28,r11,r31
	r28.u64 = r11.u64 + r31.u64;
	// lfsx f12,r11,r31
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f31,f12
	cr6.compare(f31.f64, ctx.f12.f64);
	// ble cr6,0x82573c90
	if (!cr6.gt) goto loc_82573C90;
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82573d98
	if (cr6.eq) goto loc_82573D98;
loc_82573C58:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,132(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x82573d98
	if (!cr6.gt) goto loc_82573D98;
	// lhz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 22);
	// stfs f31,0(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x82573c58
	if (!cr6.eq) goto loc_82573C58;
	// b 0x82573d98
	goto loc_82573D98;
loc_82573C90:
	// fcmpu cr6,f31,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, ctx.f12.f64);
	// bge cr6,0x82573d98
	if (!cr6.lt) goto loc_82573D98;
	// fcmpu cr6,f30,f12
	cr6.compare(f30.f64, ctx.f12.f64);
	// bne cr6,0x82573d98
	if (!cr6.eq) goto loc_82573D98;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,25(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 25);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f9,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f9.f64 = double(temp.f32);
	// beq cr6,0x82573cc4
	if (cr6.eq) goto loc_82573CC4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256fab8
	ctx.lr = 0x82573CBC;
	sub_8256FAB8(ctx, base);
	// fmr f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f1.f64;
	// b 0x82573cc8
	goto loc_82573CC8;
loc_82573CC4:
	// fmr f11,f9
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f9.f64;
loc_82573CC8:
	// lfs f0,44(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 44);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bge cr6,0x82573cf8
	if (!cr6.lt) goto loc_82573CF8;
	// lbz r11,24(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82573cf8
	if (cr6.eq) goto loc_82573CF8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8256c980
	ctx.lr = 0x82573CF0;
	sub_8256C980(ctx, base);
	// fsubs f0,f1,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// fsel f11,f0,f1,f11
	ctx.f11.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : ctx.f11.f64;
loc_82573CF8:
	// fcmpu cr6,f11,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// bge cr6,0x82573d98
	if (!cr6.lt) goto loc_82573D98;
	// lhz r4,22(r28)
	ctx.r4.u64 = PPC_LOAD_U16(r28.u32 + 22);
	// stfs f11,0(r28)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// beq cr6,0x82573d98
	if (cr6.eq) goto loc_82573D98;
loc_82573D10:
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r30,132(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lfsx f0,r11,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + r30.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bne cr6,0x82573d98
	if (!cr6.eq) goto loc_82573D98;
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82573d4c
	if (cr6.eq) goto loc_82573D4C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8256fab8
	ctx.lr = 0x82573D44;
	sub_8256FAB8(ctx, base);
	// fmr f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f1.f64;
	// b 0x82573d50
	goto loc_82573D50;
loc_82573D4C:
	// fmr f12,f9
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f9.f64;
loc_82573D50:
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x82573d80
	if (!cr6.lt) goto loc_82573D80;
	// lbz r11,24(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82573d80
	if (cr6.eq) goto loc_82573D80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8256c980
	ctx.lr = 0x82573D78;
	sub_8256C980(ctx, base);
	// fsubs f0,f1,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// fsel f12,f0,f1,f12
	ctx.f12.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : ctx.f12.f64;
loc_82573D80:
	// fsubs f0,f11,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lhz r4,22(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// fsel f13,f0,f11,f12
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f11.f64 : ctx.f12.f64;
	// stfs f13,0(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// bne cr6,0x82573d10
	if (!cr6.eq) goto loc_82573D10;
loc_82573D98:
	// lfs f0,44(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 44);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// fmuls f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 * ctx.f10.f64));
	// ble cr6,0x82573ddc
	if (!cr6.gt) goto loc_82573DDC;
	// fcmpu cr6,f30,f13
	cr6.compare(f30.f64, ctx.f13.f64);
	// bgt cr6,0x82573ed0
	if (cr6.gt) goto loc_82573ED0;
	// fmuls f0,f0,f10
	f0.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x82573ed0
	if (!cr6.gt) goto loc_82573ED0;
	// lhz r11,0(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,28(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// rlwinm r8,r11,21,11,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1FFFFC;
	// slw r7,r10,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r8.u8 & 0x3F));
	// subf r6,r7,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r6,28(r28)
	PPC_STORE_U32(r28.u32 + 28, ctx.r6.u32);
	// b 0x82573ed0
	goto loc_82573ED0;
loc_82573DDC:
	// fcmpu cr6,f30,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, ctx.f13.f64);
	// ble cr6,0x82573ed0
	if (!cr6.gt) goto loc_82573ED0;
	// fmuls f0,f0,f10
	f0.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bgt cr6,0x82573ed0
	if (cr6.gt) goto loc_82573ED0;
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// addi r11,r27,16
	r11.s64 = r27.s64 + 16;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r4,r7,2384
	ctx.r4.s64 = ctx.r7.s64 + 2384;
	// lwz r5,12(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// li r6,16
	ctx.r6.s64 = 16;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// addi r7,r3,2352
	ctx.r7.s64 = ctx.r3.s64 + 2352;
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v62,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v59,r11,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v55,v62,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v57,r5,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v59,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vand128 v54,v57,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v53,v59,v61
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r8,-2816
	ctx.r6.s64 = ctx.r8.s64 + -2816;
	// lvx128 v51,r28,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// vmrglw128 v52,v58,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// li r4,1
	ctx.r4.s64 = 1;
	// vor128 v49,v63,v54
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// vmrghw128 v50,v58,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v48,v55,v53
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// addi r11,r28,28
	r11.s64 = r28.s64 + 28;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v47,v49,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v46,v49,v48
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32), 0xFF));
	// vmsum4fp128 v45,v49,v50
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmrghw128 v44,v47,v49
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v43,v45,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v43,v44
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vcmpgtfp128 v41,v42,v51
	simde_mm_store_ps(v41.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v51.f32)));
	// vand128 v40,v41,v63
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vspltw128 v39,v40,1
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xAA));
	// vspltw128 v38,v40,0
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// vspltw128 v37,v40,2
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x55));
	// vor128 v36,v38,v39
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)v39.u8)));
	// vor128 v35,v36,v37
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v37.u8)));
	// stvewx128 v35,r0,r5
	ea = (ctx.r5.u32) & ~0x3;
	PPC_STORE_U32(ea, v35.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r9,28(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r8,r4,r3
	ctx.r8.u64 = ctx.r3.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r3.u8 & 0x3F));
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r9,28(r28)
	PPC_STORE_U32(r28.u32 + 28, ctx.r9.u32);
	// lhz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U16(r26.u32 + 0);
	// rlwimi r8,r10,13,0,18
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 13) & 0xFFFFE000) | (ctx.r8.u64 & 0xFFFFFFFF00001FFF);
	// sth r8,0(r26)
	PPC_STORE_U16(r26.u32 + 0, ctx.r8.u16);
loc_82573ED0:
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825734b0
	ctx.lr = 0x82573EE0;
	sub_825734B0(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x82573EE8;
	sub_821C9030(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82573EF8"))) PPC_WEAK_FUNC(sub_82573EF8);
PPC_FUNC_IMPL(__imp__sub_82573EF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCVRegister v119{};
	PPCVRegister v120{};
	PPCVRegister v121{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dd50c
	ctx.lr = 0x82573F10;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltisw128 v63,1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x1)));
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// li r8,32
	ctx.r8.s64 = 32;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// li r9,16
	ctx.r9.s64 = 16;
	// vcuxwfp128 v60,v63,1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v63.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// vor128 v59,v62,v62
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lwz r4,144(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r7,48
	ctx.r7.s64 = 48;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// vupkd3d128 v58,v61,4
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v58 = vTemp;
	// vslw128 v57,v62,v62
	v57.u32[0] = v62.u32[0] << (v62.u8[0] & 0x1F);
	v57.u32[1] = v62.u32[1] << (v62.u8[4] & 0x1F);
	v57.u32[2] = v62.u32[2] << (v62.u8[8] & 0x1F);
	v57.u32[3] = v62.u32[3] << (v62.u8[12] & 0x1F);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// vpkd3d128 v59,v62,0,1,0
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v62.f32[0] < 3.0f ? 3.0f : (v62.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v62.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v62.f32[1] < 3.0f ? 3.0f : (v62.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v62.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v62.f32[2] < 3.0f ? 3.0f : (v62.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v62.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v62.f32[3] < 3.0f ? 3.0f : (v62.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v62.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	v59.u32[0] = temp.u32;
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// vpermwi128 v56,v58,171
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x54));
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// vpermwi128 v127,v58,234
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x15));
	// vpermwi128 v126,v58,186
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x45));
	// rlwinm r10,r6,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF0;
	// vpermwi128 v125,v58,174
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x51));
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// lwz r6,76(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v53,v55,v57
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// lvx128 v52,r11,r8
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vandc128 v51,v54,v57
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lvx128 v50,r11,r7
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v49,v55,v52
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vandc128 v48,v52,v57
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vmrghw128 v47,v54,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v46,v54,v50
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v45,v55,v52
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// lvx128 v44,r5,r8
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v43,v51,v61
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// lvx128 v42,r5,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v41,v49,v47
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vaddfp128 v40,v42,v44
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v44.f32)));
	// vmrglw128 v35,v51,v61
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vsubfp128 v37,v42,v44
	simde_mm_store_ps(v37.f32, simde_mm_sub_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v44.f32)));
	// vmrghw128 v38,v45,v46
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrglw128 v39,v49,v47
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v36,v53,v48
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrglw128 v34,v53,v48
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v124,v36,v43
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrglw128 v123,v36,v43
	simde_mm_store_si128((simde__m128i*)v123.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v122,v34,v35
	simde_mm_store_si128((simde__m128i*)v122.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmulfp128 v33,v40,v60
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v60.f32)));
	// vmulfp128 v121,v37,v60
	simde_mm_store_ps(v121.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v60.f32)));
	// vand128 v32,v33,v59
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vor128 v63,v32,v56
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// vmsum4fp128 v62,v38,v63
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// vmsum4fp128 v61,v41,v63
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// vmsum4fp128 v60,v39,v63
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// vmrghw128 v59,v61,v62
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v120,v59,v60
	simde_mm_store_si128((simde__m128i*)v120.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82574018;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v119,r0,r11
	simde_mm_store_si128((simde__m128i*)v119.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82203388
	ctx.lr = 0x8257402C;
	sub_82203388(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vmsum3fp128 v58,v123,v121
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v123.f32), simde_mm_load_ps(v121.f32), 0xEF));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vmsum3fp128 v57,v122,v121
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(v121.f32), 0xEF));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// vmsum3fp128 v56,v124,v121
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v121.f32), 0xEF));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,4
	ctx.r5.s64 = 4;
	// stvx128 v126,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v55,v56,v57
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// li r3,6
	ctx.r3.s64 = 6;
	// li r11,1
	r11.s64 = 1;
	// stvx128 v125,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v120,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v120.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// stw r5,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// vmrghw128 v54,v55,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// stb r11,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vaddfp128 v53,v54,v119
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v119.f32)));
	// stvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82572c48
	ctx.lr = 0x82574090;
	sub_82572C48(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x825740dc
	if (cr6.eq) goto loc_825740DC;
loc_8257409C:
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// beq cr6,0x825740c4
	if (cr6.eq) goto loc_825740C4;
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// clrlwi r4,r30,16
	ctx.r4.u64 = r30.u32 & 0xFFFF;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825740C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825740C4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82571250
	ctx.lr = 0x825740D0;
	sub_82571250(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8257409c
	if (!cr6.eq) goto loc_8257409C;
loc_825740DC:
	// lbz r10,244(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 244);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825740f4
	if (cr6.eq) goto loc_825740F4;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-23388
	ctx.r3.s64 = r11.s64 + -23388;
	// bl 0x821c8f70
	ctx.lr = 0x825740F4;
	sub_821C8F70(ctx, base);
loc_825740F4:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dd7a4
	ctx.lr = 0x82574100;
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

__attribute__((alias("__imp__sub_82574114"))) PPC_WEAK_FUNC(sub_82574114);
PPC_FUNC_IMPL(__imp__sub_82574114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82574118"))) PPC_WEAK_FUNC(sub_82574118);
PPC_FUNC_IMPL(__imp__sub_82574118) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r31,144
	ctx.r9.s64 = r31.s64 + 144;
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// li r10,127
	ctx.r10.s64 = 127;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// addi r11,r9,36
	r11.s64 = ctx.r9.s64 + 36;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
loc_82574160:
	// stw r30,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stw r30,28(r11)
	PPC_STORE_U32(r11.u32 + 28, r30.u32);
	// stw r30,32(r11)
	PPC_STORE_U32(r11.u32 + 32, r30.u32);
	// stw r30,36(r11)
	PPC_STORE_U32(r11.u32 + 36, r30.u32);
	// stw r30,40(r11)
	PPC_STORE_U32(r11.u32 + 40, r30.u32);
	// addi r11,r11,176
	r11.s64 = r11.s64 + 176;
	// bge 0x82574160
	if (!cr0.lt) goto loc_82574160;
	// stw r30,22704(r31)
	PPC_STORE_U32(r31.u32 + 22704, r30.u32);
	// addi r11,r31,22672
	r11.s64 = r31.s64 + 22672;
	// stw r30,22708(r31)
	PPC_STORE_U32(r31.u32 + 22708, r30.u32);
	// addi r10,r31,22864
	ctx.r10.s64 = r31.s64 + 22864;
	// stw r30,22736(r31)
	PPC_STORE_U32(r31.u32 + 22736, r30.u32);
	// addi r8,r11,64
	ctx.r8.s64 = r11.s64 + 64;
	// stw r30,22740(r31)
	PPC_STORE_U32(r31.u32 + 22740, r30.u32);
	// stw r30,22744(r31)
	PPC_STORE_U32(r31.u32 + 22744, r30.u32);
	// addi r11,r11,72
	r11.s64 = r11.s64 + 72;
	// stw r30,22748(r31)
	PPC_STORE_U32(r31.u32 + 22748, r30.u32);
	// stw r30,22896(r31)
	PPC_STORE_U32(r31.u32 + 22896, r30.u32);
	// addi r9,r31,23088
	ctx.r9.s64 = r31.s64 + 23088;
	// stw r30,22900(r31)
	PPC_STORE_U32(r31.u32 + 22900, r30.u32);
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// stw r30,22928(r31)
	PPC_STORE_U32(r31.u32 + 22928, r30.u32);
	// addi r11,r10,72
	r11.s64 = ctx.r10.s64 + 72;
	// stw r30,22932(r31)
	PPC_STORE_U32(r31.u32 + 22932, r30.u32);
	// stw r30,22936(r31)
	PPC_STORE_U32(r31.u32 + 22936, r30.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r30,22940(r31)
	PPC_STORE_U32(r31.u32 + 22940, r30.u32);
	// stw r30,23120(r31)
	PPC_STORE_U32(r31.u32 + 23120, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,23124(r31)
	PPC_STORE_U32(r31.u32 + 23124, r30.u32);
	// addi r3,r31,23392
	ctx.r3.s64 = r31.s64 + 23392;
	// stw r30,23152(r31)
	PPC_STORE_U32(r31.u32 + 23152, r30.u32);
	// addi r11,r9,64
	r11.s64 = ctx.r9.s64 + 64;
	// stw r30,23156(r31)
	PPC_STORE_U32(r31.u32 + 23156, r30.u32);
	// stw r30,23160(r31)
	PPC_STORE_U32(r31.u32 + 23160, r30.u32);
	// addi r11,r9,72
	r11.s64 = ctx.r9.s64 + 72;
	// stw r30,23164(r31)
	PPC_STORE_U32(r31.u32 + 23164, r30.u32);
	// stw r30,23376(r31)
	PPC_STORE_U32(r31.u32 + 23376, r30.u32);
	// stw r30,23380(r31)
	PPC_STORE_U32(r31.u32 + 23380, r30.u32);
	// stw r30,23384(r31)
	PPC_STORE_U32(r31.u32 + 23384, r30.u32);
	// stw r30,23388(r31)
	PPC_STORE_U32(r31.u32 + 23388, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x82574210;
	sub_823D9890(ctx, base);
	// stb r30,23520(r31)
	PPC_STORE_U8(r31.u32 + 23520, r30.u8);
	// stb r30,23521(r31)
	PPC_STORE_U8(r31.u32 + 23521, r30.u8);
	// li r11,-1
	r11.s64 = -1;
	// stb r30,23522(r31)
	PPC_STORE_U8(r31.u32 + 23522, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r11,23688(r31)
	PPC_STORE_U32(r31.u32 + 23688, r11.u32);
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

__attribute__((alias("__imp__sub_82574244"))) PPC_WEAK_FUNC(sub_82574244);
PPC_FUNC_IMPL(__imp__sub_82574244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82574248"))) PPC_WEAK_FUNC(sub_82574248);
PPC_FUNC_IMPL(__imp__sub_82574248) {
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
	// stw r4,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82574278;
	sub_821C8FE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,140(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// bl 0x82573418
	ctx.lr = 0x82574284;
	sub_82573418(ctx, base);
	// clrlwi r30,r30,24
	r30.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x825742ac
	if (!cr6.eq) goto loc_825742AC;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825742AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_825742AC:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825742C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,140(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lis r8,0
	ctx.r8.s64 = 0;
	// rlwinm r11,r7,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r10,r8,65535
	ctx.r10.u64 = ctx.r8.u64 | 65535;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// ori r5,r6,3
	ctx.r5.u64 = ctx.r6.u64 | 3;
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
	// rlwinm r3,r4,0,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFF0;
	// sth r10,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r10.u16);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// bne cr6,0x8257432c
	if (!cr6.eq) goto loc_8257432C;
	// lhz r11,42(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// lwz r9,140(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// clrlwi r5,r8,16
	ctx.r5.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r4,r5,1,15,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x1FFFE;
	// sth r5,42(r31)
	PPC_STORE_U16(r31.u32 + 42, ctx.r5.u16);
	// sthx r9,r4,r7
	PPC_STORE_U16(ctx.r4.u32 + ctx.r7.u32, ctx.r9.u16);
loc_8257432C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82574334;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_8257434C"))) PPC_WEAK_FUNC(sub_8257434C);
PPC_FUNC_IMPL(__imp__sub_8257434C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82574350"))) PPC_WEAK_FUNC(sub_82574350);
PPC_FUNC_IMPL(__imp__sub_82574350) {
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
	ctx.lr = 0x82574358;
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
	// bl 0x821c8fe0
	ctx.lr = 0x82574378;
	sub_821C8FE0(ctx, base);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r4,r7,0,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// stwx r29,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, r29.u32);
	// lwz r9,124(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lhz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// rotlwi r4,r7,1
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// sthx r30,r4,r9
	PPC_STORE_U16(ctx.r4.u32 + ctx.r9.u32, r30.u16);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// clrlwi r4,r10,19
	ctx.r4.u64 = ctx.r10.u32 & 0x1FFF;
	// bl 0x8256f9b0
	ctx.lr = 0x825743CC;
	sub_8256F9B0(ctx, base);
	// lhz r7,46(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// lhz r11,48(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// addis r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 65536;
	// lwz r6,144(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// sth r9,48(r31)
	PPC_STORE_U16(r31.u32 + 48, ctx.r9.u16);
	// sth r5,46(r31)
	PPC_STORE_U16(r31.u32 + 46, ctx.r5.u16);
	// lbz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r6.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82574404
	if (cr6.eq) goto loc_82574404;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82573ef8
	ctx.lr = 0x82574404;
	sub_82573EF8(ctx, base);
loc_82574404:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8257440C;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82574418"))) PPC_WEAK_FUNC(sub_82574418);
PPC_FUNC_IMPL(__imp__sub_82574418) {
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
	ctx.lr = 0x82574420;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -12288);
	// ld r12,-16384(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16384);
	// stwu r1,-19056(r1)
	ea = -19056 + ctx.r1.u32;
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
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82574464;
	sub_821C8FE0(ctx, base);
	// li r7,4096
	ctx.r7.s64 = 4096;
	// addi r6,r1,2592
	ctx.r6.s64 = ctx.r1.s64 + 2592;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// addi r4,r1,10784
	ctx.r4.s64 = ctx.r1.s64 + 10784;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822c67b8
	ctx.lr = 0x8257447C;
	sub_822C67B8(ctx, base);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8257ddd8
	ctx.lr = 0x82574490;
	sub_8257DDD8(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// lwz r8,19140(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19140);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822c6110
	ctx.lr = 0x825744B4;
	sub_822C6110(ctx, base);
	// lbz r9,506(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 506);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825744cc
	if (cr6.eq) goto loc_825744CC;
	// lwz r3,372(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// bl 0x82130588
	ctx.lr = 0x825744CC;
	sub_82130588(ctx, base);
loc_825744CC:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82130000
	ctx.lr = 0x825744D4;
	sub_82130000(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x825744DC;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,19056
	ctx.r1.s64 = ctx.r1.s64 + 19056;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_825744E8"))) PPC_WEAK_FUNC(sub_825744E8);
PPC_FUNC_IMPL(__imp__sub_825744E8) {
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
	ctx.lr = 0x825744F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x82574118
	ctx.lr = 0x82574504;
	sub_82574118(ctx, base);
	// addi r29,r31,23696
	r29.s64 = r31.s64 + 23696;
	// li r30,0
	r30.s64 = 0;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,23796(r31)
	PPC_STORE_U32(r31.u32 + 23796, r30.u32);
	// addi r3,r29,628
	ctx.r3.s64 = r29.s64 + 628;
	// sth r30,23800(r31)
	PPC_STORE_U16(r31.u32 + 23800, r30.u16);
	// stw r30,24452(r31)
	PPC_STORE_U32(r31.u32 + 24452, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x82574528;
	sub_823D9890(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,106
	ctx.r3.s64 = r29.s64 + 106;
	// bl 0x823d9890
	ctx.lr = 0x82574538;
	sub_823D9890(ctx, base);
	// stb r30,23930(r31)
	PPC_STORE_U8(r31.u32 + 23930, r30.u8);
	// addi r3,r31,25184
	ctx.r3.s64 = r31.s64 + 25184;
	// stw r30,25960(r31)
	PPC_STORE_U32(r31.u32 + 25960, r30.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r30,25964(r31)
	PPC_STORE_U32(r31.u32 + 25964, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,25968(r31)
	PPC_STORE_U32(r31.u32 + 25968, r30.u32);
	// addi r11,r31,25960
	r11.s64 = r31.s64 + 25960;
	// stw r30,25972(r31)
	PPC_STORE_U32(r31.u32 + 25972, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x82574560;
	sub_823D9890(ctx, base);
	// addi r3,r31,25440
	ctx.r3.s64 = r31.s64 + 25440;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82574570;
	sub_823D9890(ctx, base);
	// stw r30,25952(r31)
	PPC_STORE_U32(r31.u32 + 25952, r30.u32);
	// stb r30,25956(r31)
	PPC_STORE_U8(r31.u32 + 25956, r30.u8);
	// lis r11,-32169
	r11.s64 = -2108227584;
	// stb r30,25957(r31)
	PPC_STORE_U8(r31.u32 + 25957, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,25976(r31)
	PPC_STORE_U8(r31.u32 + 25976, r30.u8);
	// addi r10,r11,-12232
	ctx.r10.s64 = r11.s64 + -12232;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x82574594;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r11,-1
	r11.s64 = -1;
	// li r8,7
	ctx.r8.s64 = 7;
	// std r9,25960(r31)
	PPC_STORE_U64(r31.u32 + 25960, ctx.r9.u64);
	// stw r28,23796(r31)
	PPC_STORE_U32(r31.u32 + 23796, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r27,23800(r31)
	PPC_STORE_U16(r31.u32 + 23800, r27.u16);
	// stb r30,23930(r31)
	PPC_STORE_U8(r31.u32 + 23930, r30.u8);
	// stw r30,25980(r31)
	PPC_STORE_U32(r31.u32 + 25980, r30.u32);
	// stw r11,25984(r31)
	PPC_STORE_U32(r31.u32 + 25984, r11.u32);
	// stw r11,25988(r31)
	PPC_STORE_U32(r31.u32 + 25988, r11.u32);
	// stb r8,25992(r31)
	PPC_STORE_U8(r31.u32 + 25992, ctx.r8.u8);
	// stw r30,25996(r31)
	PPC_STORE_U32(r31.u32 + 25996, r30.u32);
	// stw r30,26000(r31)
	PPC_STORE_U32(r31.u32 + 26000, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_825745D8"))) PPC_WEAK_FUNC(sub_825745D8);
PPC_FUNC_IMPL(__imp__sub_825745D8) {
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
	ctx.lr = 0x825745E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,224
	r29.s64 = r31.s64 + 224;
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
	// stw r30,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r30.u32);
	// sth r30,328(r31)
	PPC_STORE_U16(r31.u32 + 328, r30.u16);
	// stw r30,980(r31)
	PPC_STORE_U32(r31.u32 + 980, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x82574634;
	sub_823D9890(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,106
	ctx.r3.s64 = r29.s64 + 106;
	// bl 0x823d9890
	ctx.lr = 0x82574644;
	sub_823D9890(ctx, base);
	// stb r30,458(r31)
	PPC_STORE_U8(r31.u32 + 458, r30.u8);
	// addi r3,r31,1712
	ctx.r3.s64 = r31.s64 + 1712;
	// stw r30,2488(r31)
	PPC_STORE_U32(r31.u32 + 2488, r30.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r30,2492(r31)
	PPC_STORE_U32(r31.u32 + 2492, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,2496(r31)
	PPC_STORE_U32(r31.u32 + 2496, r30.u32);
	// addi r11,r31,2488
	r11.s64 = r31.s64 + 2488;
	// stw r30,2500(r31)
	PPC_STORE_U32(r31.u32 + 2500, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x8257466C;
	sub_823D9890(ctx, base);
	// addi r3,r31,1968
	ctx.r3.s64 = r31.s64 + 1968;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8257467C;
	sub_823D9890(ctx, base);
	// stw r30,2480(r31)
	PPC_STORE_U32(r31.u32 + 2480, r30.u32);
	// stb r30,2484(r31)
	PPC_STORE_U8(r31.u32 + 2484, r30.u8);
	// lis r11,-32224
	r11.s64 = -2111832064;
	// stb r30,2485(r31)
	PPC_STORE_U8(r31.u32 + 2485, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,2504(r31)
	PPC_STORE_U8(r31.u32 + 2504, r30.u8);
	// addi r10,r11,19360
	ctx.r10.s64 = r11.s64 + 19360;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x825746A0;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r11,-1
	r11.s64 = -1;
	// li r8,7
	ctx.r8.s64 = 7;
	// std r9,2488(r31)
	PPC_STORE_U64(r31.u32 + 2488, ctx.r9.u64);
	// stw r28,324(r31)
	PPC_STORE_U32(r31.u32 + 324, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r27,328(r31)
	PPC_STORE_U16(r31.u32 + 328, r27.u16);
	// stb r30,458(r31)
	PPC_STORE_U8(r31.u32 + 458, r30.u8);
	// stw r30,2508(r31)
	PPC_STORE_U32(r31.u32 + 2508, r30.u32);
	// stw r11,2512(r31)
	PPC_STORE_U32(r31.u32 + 2512, r11.u32);
	// stw r11,2516(r31)
	PPC_STORE_U32(r31.u32 + 2516, r11.u32);
	// stb r8,2520(r31)
	PPC_STORE_U8(r31.u32 + 2520, ctx.r8.u8);
	// stw r30,2524(r31)
	PPC_STORE_U32(r31.u32 + 2524, r30.u32);
	// stw r30,2528(r31)
	PPC_STORE_U32(r31.u32 + 2528, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_825746E4"))) PPC_WEAK_FUNC(sub_825746E4);
PPC_FUNC_IMPL(__imp__sub_825746E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825746E8"))) PPC_WEAK_FUNC(sub_825746E8);
PPC_FUNC_IMPL(__imp__sub_825746E8) {
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
	ctx.lr = 0x825746F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,192
	r29.s64 = r31.s64 + 192;
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
	// stw r30,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r30.u32);
	// sth r30,296(r31)
	PPC_STORE_U16(r31.u32 + 296, r30.u16);
	// stw r30,948(r31)
	PPC_STORE_U32(r31.u32 + 948, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x82574744;
	sub_823D9890(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,106
	ctx.r3.s64 = r29.s64 + 106;
	// bl 0x823d9890
	ctx.lr = 0x82574754;
	sub_823D9890(ctx, base);
	// stb r30,426(r31)
	PPC_STORE_U8(r31.u32 + 426, r30.u8);
	// addi r3,r31,1680
	ctx.r3.s64 = r31.s64 + 1680;
	// stw r30,2456(r31)
	PPC_STORE_U32(r31.u32 + 2456, r30.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r30,2460(r31)
	PPC_STORE_U32(r31.u32 + 2460, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,2464(r31)
	PPC_STORE_U32(r31.u32 + 2464, r30.u32);
	// addi r11,r31,2456
	r11.s64 = r31.s64 + 2456;
	// stw r30,2468(r31)
	PPC_STORE_U32(r31.u32 + 2468, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x8257477C;
	sub_823D9890(ctx, base);
	// addi r3,r31,1936
	ctx.r3.s64 = r31.s64 + 1936;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8257478C;
	sub_823D9890(ctx, base);
	// stw r30,2448(r31)
	PPC_STORE_U32(r31.u32 + 2448, r30.u32);
	// stb r30,2452(r31)
	PPC_STORE_U8(r31.u32 + 2452, r30.u8);
	// lis r11,-32169
	r11.s64 = -2108227584;
	// stb r30,2453(r31)
	PPC_STORE_U8(r31.u32 + 2453, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,2472(r31)
	PPC_STORE_U8(r31.u32 + 2472, r30.u8);
	// addi r10,r11,-11264
	ctx.r10.s64 = r11.s64 + -11264;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x825747B0;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r11,-1
	r11.s64 = -1;
	// li r8,7
	ctx.r8.s64 = 7;
	// std r9,2456(r31)
	PPC_STORE_U64(r31.u32 + 2456, ctx.r9.u64);
	// stw r28,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r27,296(r31)
	PPC_STORE_U16(r31.u32 + 296, r27.u16);
	// stb r30,426(r31)
	PPC_STORE_U8(r31.u32 + 426, r30.u8);
	// stw r30,2476(r31)
	PPC_STORE_U32(r31.u32 + 2476, r30.u32);
	// stw r11,2480(r31)
	PPC_STORE_U32(r31.u32 + 2480, r11.u32);
	// stw r11,2484(r31)
	PPC_STORE_U32(r31.u32 + 2484, r11.u32);
	// stb r8,2488(r31)
	PPC_STORE_U8(r31.u32 + 2488, ctx.r8.u8);
	// stw r30,2492(r31)
	PPC_STORE_U32(r31.u32 + 2492, r30.u32);
	// stw r30,2496(r31)
	PPC_STORE_U32(r31.u32 + 2496, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_825747F4"))) PPC_WEAK_FUNC(sub_825747F4);
PPC_FUNC_IMPL(__imp__sub_825747F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825747F8"))) PPC_WEAK_FUNC(sub_825747F8);
PPC_FUNC_IMPL(__imp__sub_825747F8) {
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
	ctx.lr = 0x82574800;
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
	// bl 0x821c8fe0
	ctx.lr = 0x82574820;
	sub_821C8FE0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x82574248
	ctx.lr = 0x82574830;
	sub_82574248(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82574838;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82574840"))) PPC_WEAK_FUNC(sub_82574840);
PPC_FUNC_IMPL(__imp__sub_82574840) {
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
	ctx.lr = 0x82574848;
	// lis r12,-1
	r12.s64 = -65536;
	// ori r12,r12,22976
	r12.u64 = r12.u64 | 22976;
	// bl 0x823dbff4
	ctx.lr = 0x82574854;
	sub_823DBFF4(ctx, base);
	// stwux r1,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8257487C;
	sub_821C8FE0(ctx, base);
	// li r7,4096
	ctx.r7.s64 = 4096;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// addi r4,r1,8288
	ctx.r4.s64 = ctx.r1.s64 + 8288;
	// addi r3,r1,16480
	ctx.r3.s64 = ctx.r1.s64 + 16480;
	// bl 0x825744e8
	ctx.lr = 0x82574894;
	sub_825744E8(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x825748fc
	if (!cr6.gt) goto loc_825748FC;
	// subf r29,r31,r29
	r29.s64 = r29.s64 - r31.s64;
loc_825748A4:
	// lis r11,0
	r11.s64 = 0;
	// ori r11,r11,39856
	r11.u64 = r11.u64 | 39856;
	// lwzx r11,r1,r11
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwzx r5,r29,r31
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r25,r11
	r25.u64 = r11.u64;
	// lis r12,0
	r12.s64 = 0;
	// ori r12,r12,39856
	r12.u64 = r12.u64 | 39856;
	// stwx r10,r1,r12
	PPC_STORE_U32(ctx.r1.u32 + r12.u32, ctx.r10.u32);
	// addi r11,r1,16624
	r11.s64 = ctx.r1.s64 + 16624;
	// mulli r10,r25,176
	ctx.r10.s64 = r25.s64 * 176;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x8257ddd8
	ctx.lr = 0x825748E0;
	sub_8257DDD8(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r9,r9,39872
	ctx.r9.u64 = ctx.r9.u64 | 39872;
	// add r9,r1,r9
	ctx.r9.u64 = ctx.r1.u64 + ctx.r9.u64;
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stbx r28,r25,r9
	PPC_STORE_U8(r25.u32 + ctx.r9.u32, r28.u8);
	// bne 0x825748a4
	if (!cr0.eq) goto loc_825748A4;
loc_825748FC:
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r8,0
	ctx.r8.s64 = 0;
	// ori r8,r8,42668
	ctx.r8.u64 = ctx.r8.u64 | 42668;
	// lwzx r8,r1,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + ctx.r8.u32);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r7,r7,42663
	ctx.r7.u64 = ctx.r7.u64 | 42663;
	// lbzx r7,r1,r7
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + ctx.r7.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r6,r6,42652
	ctx.r6.u64 = ctx.r6.u64 | 42652;
	// lwzx r6,r1,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + ctx.r6.u32);
	// addi r3,r1,16480
	ctx.r3.s64 = ctx.r1.s64 + 16480;
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r5,r5,42644
	ctx.r5.u64 = ctx.r5.u64 | 42644;
	// lwzx r5,r1,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + ctx.r5.u32);
	// bl 0x82572d30
	ctx.lr = 0x82574940;
	sub_82572D30(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x8257494c
	if (cr6.gt) goto loc_8257494C;
	// li r28,0
	r28.s64 = 0;
loc_8257494C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r10,r10,40410
	ctx.r10.u64 = ctx.r10.u64 | 40410;
	// lbzx r10,r1,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + ctx.r10.u32);
	// clrlwi r29,r28,24
	r29.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82574974
	if (cr6.eq) goto loc_82574974;
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,40276
	ctx.r3.u64 = ctx.r3.u64 | 40276;
	// lwzx r3,r1,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + ctx.r3.u32);
	// bl 0x82130588
	ctx.lr = 0x82574974;
	sub_82130588(ctx, base);
loc_82574974:
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,39568
	ctx.r3.u64 = ctx.r3.u64 | 39568;
	// add r3,r1,r3
	ctx.r3.u64 = ctx.r1.u64 + ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x82574984;
	sub_82130000(ctx, base);
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,39344
	ctx.r3.u64 = ctx.r3.u64 | 39344;
	// add r3,r1,r3
	ctx.r3.u64 = ctx.r1.u64 + ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x82574994;
	sub_82130000(ctx, base);
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,39152
	ctx.r3.u64 = ctx.r3.u64 | 39152;
	// add r3,r1,r3
	ctx.r3.u64 = ctx.r1.u64 + ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x825749A4;
	sub_82130000(ctx, base);
	// lis r31,0
	r31.s64 = 0;
	// ori r31,r31,39152
	r31.u64 = r31.u64 | 39152;
	// add r31,r1,r31
	r31.u64 = ctx.r1.u64 + r31.u64;
	// li r30,127
	r30.s64 = 127;
loc_825749B4:
	// addi r31,r31,-176
	r31.s64 = r31.s64 + -176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x825749C0;
	sub_82130000(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x825749b4
	if (!cr0.lt) goto loc_825749B4;
	// addi r3,r1,16480
	ctx.r3.s64 = ctx.r1.s64 + 16480;
	// bl 0x82130000
	ctx.lr = 0x825749D0;
	sub_82130000(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x825749D8;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_825749E4"))) PPC_WEAK_FUNC(sub_825749E4);
PPC_FUNC_IMPL(__imp__sub_825749E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825749E8"))) PPC_WEAK_FUNC(sub_825749E8);
PPC_FUNC_IMPL(__imp__sub_825749E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x825749F0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -12288);
	// ld r12,-16384(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16384);
	// stwu r1,-19168(r1)
	ea = -19168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82574A50;
	sub_821C8FE0(ctx, base);
	// li r7,4096
	ctx.r7.s64 = 4096;
	// addi r6,r1,2672
	ctx.r6.s64 = ctx.r1.s64 + 2672;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// addi r4,r1,10864
	ctx.r4.s64 = ctx.r1.s64 + 10864;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x825745d8
	ctx.lr = 0x82574A68;
	sub_825745D8(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r7,19292(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19292);
	// clrlwi r8,r25,24
	ctx.r8.u64 = r25.u32 & 0xFF;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v126,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// beq cr6,0x82574aa0
	if (cr6.eq) goto loc_82574AA0;
	// bl 0x8257df80
	ctx.lr = 0x82574A9C;
	sub_8257DF80(ctx, base);
	// b 0x82574aa4
	goto loc_82574AA4;
loc_82574AA0:
	// bl 0x8257df18
	ctx.lr = 0x82574AA4;
	sub_8257DF18(ctx, base);
loc_82574AA4:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r8,19300(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19300);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8220dbd8
	ctx.lr = 0x82574AC8;
	sub_8220DBD8(ctx, base);
	// lbz r10,586(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 586);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82574ae0
	if (cr6.eq) goto loc_82574AE0;
	// lwz r3,452(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 452);
	// bl 0x82130588
	ctx.lr = 0x82574AE0;
	sub_82130588(ctx, base);
loc_82574AE0:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82130000
	ctx.lr = 0x82574AE8;
	sub_82130000(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82574AF0;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,19168
	ctx.r1.s64 = ctx.r1.s64 + 19168;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82574B10"))) PPC_WEAK_FUNC(sub_82574B10);
PPC_FUNC_IMPL(__imp__sub_82574B10) {
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
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82574B18;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -12288);
	// ld r12,-16384(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16384);
	// stwu r1,-19152(r1)
	ea = -19152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82574B74;
	sub_821C8FE0(ctx, base);
	// li r7,4096
	ctx.r7.s64 = 4096;
	// addi r6,r1,2672
	ctx.r6.s64 = ctx.r1.s64 + 2672;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// addi r4,r1,10864
	ctx.r4.s64 = ctx.r1.s64 + 10864;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x825745d8
	ctx.lr = 0x82574B8C;
	sub_825745D8(ctx, base);
	// vaddfp128 v63,v127,v126
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v126.f32)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lbz r7,19279(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 19279);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f31.f64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lwz r7,19284(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19284);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82574bc8
	if (cr6.eq) goto loc_82574BC8;
	// bl 0x8257df80
	ctx.lr = 0x82574BC4;
	sub_8257DF80(ctx, base);
	// b 0x82574bcc
	goto loc_82574BCC;
loc_82574BC8:
	// bl 0x8257df18
	ctx.lr = 0x82574BCC;
	sub_8257DF18(ctx, base);
loc_82574BCC:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r8,19292(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19292);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8220dbd8
	ctx.lr = 0x82574BF0;
	sub_8220DBD8(ctx, base);
	// lbz r10,586(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 586);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82574c08
	if (cr6.eq) goto loc_82574C08;
	// lwz r3,452(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 452);
	// bl 0x82130588
	ctx.lr = 0x82574C08;
	sub_82130588(ctx, base);
loc_82574C08:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82130000
	ctx.lr = 0x82574C10;
	sub_82130000(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82574C18;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,19152
	ctx.r1.s64 = ctx.r1.s64 + 19152;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82574C38"))) PPC_WEAK_FUNC(sub_82574C38);
PPC_FUNC_IMPL(__imp__sub_82574C38) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,260(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// lwz r30,252(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// lvx128 v2,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lvx128 v1,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r9,247(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 247);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// bl 0x825749e8
	ctx.lr = 0x82574C84;
	sub_825749E8(ctx, base);
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

__attribute__((alias("__imp__sub_82574C9C"))) PPC_WEAK_FUNC(sub_82574C9C);
PPC_FUNC_IMPL(__imp__sub_82574C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82574CA0"))) PPC_WEAK_FUNC(sub_82574CA0);
PPC_FUNC_IMPL(__imp__sub_82574CA0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82574CA8;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -12288);
	// ld r12,-16384(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16384);
	// stwu r1,-19072(r1)
	ea = -19072 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-23388
	ctx.r4.s64 = r11.s64 + -23388;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82574CF0;
	sub_821C8FE0(ctx, base);
	// li r7,4096
	ctx.r7.s64 = 4096;
	// addi r6,r1,2608
	ctx.r6.s64 = ctx.r1.s64 + 2608;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// addi r4,r1,10800
	ctx.r4.s64 = ctx.r1.s64 + 10800;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825746e8
	ctx.lr = 0x82574D08;
	sub_825746E8(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,19156(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19156);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8257def0
	ctx.lr = 0x82574D20;
	sub_8257DEF0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// lwz r8,19164(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 19164);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82572f98
	ctx.lr = 0x82574D44;
	sub_82572F98(ctx, base);
	// lbz r9,522(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 522);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82574d5c
	if (cr6.eq) goto loc_82574D5C;
	// lwz r3,388(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// bl 0x82130588
	ctx.lr = 0x82574D5C;
	sub_82130588(ctx, base);
loc_82574D5C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82130000
	ctx.lr = 0x82574D64;
	sub_82130000(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82574D6C;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,19072
	ctx.r1.s64 = ctx.r1.s64 + 19072;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

