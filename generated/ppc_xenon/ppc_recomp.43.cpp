#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822AA310"))) PPC_WEAK_FUNC(sub_822AA310);
PPC_FUNC_IMPL(__imp__sub_822AA310) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822AA318;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,340(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24100(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24100);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822aa39c
	if (!cr6.lt) goto loc_822AA39C;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r5,r11,2272
	ctx.r5.s64 = r11.s64 + 2272;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r4,r29,224
	ctx.r4.s64 = r29.s64 + 224;
	// lfs f2,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x822AA360;
	sub_822A9930(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,40(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822AA374;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822aa5b0
	if (cr6.eq) goto loc_822AA5B0;
	// lwz r3,880(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 880);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822aa5b0
	if (cr6.eq) goto loc_822AA5B0;
	// bl 0x822b34b0
	ctx.lr = 0x822AA390;
	sub_822B34B0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822AA39C:
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r30,1
	r30.s64 = 1;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,44(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822aa3c8
	if (!cr6.gt) goto loc_822AA3C8;
	// li r30,0
	r30.s64 = 0;
	// b 0x822aa570
	goto loc_822AA570;
loc_822AA3C8:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82562740
	ctx.lr = 0x822AA3D0;
	sub_82562740(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa3e4
	if (cr6.eq) goto loc_822AA3E4;
	// li r30,0
	r30.s64 = 0;
	// b 0x822aa570
	goto loc_822AA570;
loc_822AA3E4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AA3F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x822aa408
	if (cr6.eq) goto loc_822AA408;
	// li r30,0
	r30.s64 = 0;
	// b 0x822aa570
	goto loc_822AA570;
loc_822AA408:
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822aa424
	if (!cr6.gt) goto loc_822AA424;
	// li r30,0
	r30.s64 = 0;
	// b 0x822aa570
	goto loc_822AA570;
loc_822AA424:
	// lfs f0,340(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 340);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,276(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,344(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 344);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,280(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 280);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,336(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 336);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,272(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 272);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f0
	cr6.compare(ctx.f3.f64, f0.f64);
	// bge cr6,0x822aa46c
	if (!cr6.lt) goto loc_822AA46C;
	// li r30,0
	r30.s64 = 0;
	// b 0x822aa570
	goto loc_822AA570;
loc_822AA46C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// lfs f0,-25180(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -25180);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x822aa530
	if (cr6.lt) goto loc_822AA530;
	// addi r8,r10,-2
	ctx.r8.s64 = ctx.r10.s64 + -2;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r6,r11,0,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r11,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// subf r10,r6,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r6.s64;
loc_822AA4A4:
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,464(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 464);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa4c4
	if (cr6.eq) goto loc_822AA4C4;
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822aa4c4
	if (!cr6.gt) goto loc_822AA4C4;
	// li r30,0
	r30.s64 = 0;
loc_822AA4C4:
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r11,464(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 464);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa4e4
	if (cr6.eq) goto loc_822AA4E4;
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822aa4e4
	if (!cr6.gt) goto loc_822AA4E4;
	// li r30,0
	r30.s64 = 0;
loc_822AA4E4:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,464(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 464);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa504
	if (cr6.eq) goto loc_822AA504;
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822aa504
	if (!cr6.gt) goto loc_822AA504;
	// li r30,0
	r30.s64 = 0;
loc_822AA504:
	// lwz r11,-4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// lwz r11,464(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 464);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa524
	if (cr6.eq) goto loc_822AA524;
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822aa524
	if (!cr6.gt) goto loc_822AA524;
	// li r30,0
	r30.s64 = 0;
loc_822AA524:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// bne 0x822aa4a4
	if (!cr0.eq) goto loc_822AA4A4;
loc_822AA530:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x822aa570
	if (cr6.lt) goto loc_822AA570;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_822AA544:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,464(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 464);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822aa564
	if (cr6.eq) goto loc_822AA564;
	// lfs f13,40(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822aa564
	if (!cr6.gt) goto loc_822AA564;
	// li r30,0
	r30.s64 = 0;
loc_822AA564:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x822aa544
	if (!cr0.lt) goto loc_822AA544;
loc_822AA570:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa5b0
	if (cr6.eq) goto loc_822AA5B0;
	// addi r11,r29,288
	r11.s64 = r29.s64 + 288;
	// addi r10,r29,224
	ctx.r10.s64 = r29.s64 + 224;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822AA5B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822AA5BC"))) PPC_WEAK_FUNC(sub_822AA5BC);
PPC_FUNC_IMPL(__imp__sub_822AA5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AA5C0"))) PPC_WEAK_FUNC(sub_822AA5C0);
PPC_FUNC_IMPL(__imp__sub_822AA5C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x822aa8c0
	if (cr6.gt) goto loc_822AA8C0;
	// lis r12,-32213
	r12.s64 = -2111111168;
	// addi r12,r12,-23048
	r12.s64 = r12.s64 + -23048;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822AA60C;
	case 1:
		goto loc_822AA694;
	case 2:
		goto loc_822AA8C0;
	case 3:
		goto loc_822AA728;
	case 4:
		goto loc_822AA7C8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-23028(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23028);
	// lwz r17,-22892(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22892);
	// lwz r17,-22336(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22336);
	// lwz r17,-22744(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22744);
	// lwz r17,-22584(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22584);
loc_822AA60C:
	// lbz r11,17(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa8c0
	if (cr6.eq) goto loc_822AA8C0;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,30
	ctx.r8.s64 = 30;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r10,-292(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -292);
	// stw r9,656(r31)
	PPC_STORE_U32(r31.u32 + 656, ctx.r9.u32);
	// stb r7,17(r31)
	PPC_STORE_U8(r31.u32 + 17, ctx.r7.u8);
	// stw r8,664(r31)
	PPC_STORE_U32(r31.u32 + 664, ctx.r8.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// beq cr6,0x822aa650
	if (cr6.eq) goto loc_822AA650;
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// b 0x822aa664
	goto loc_822AA664;
loc_822AA650:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// bne cr6,0x822aa664
	if (!cr6.eq) goto loc_822AA664;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822AA664:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// addi r3,r10,24272
	ctx.r3.s64 = ctx.r10.s64 + 24272;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r5,44(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// bl 0x82130000
	ctx.lr = 0x822AA680;
	sub_82130000(ctx, base);
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
loc_822AA694:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822aa6bc
	if (!cr6.gt) goto loc_822AA6BC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
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
loc_822AA6BC:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa6d0
	if (cr6.eq) goto loc_822AA6D0;
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// b 0x822aa6e4
	goto loc_822AA6E4;
loc_822AA6D0:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// bne cr6,0x822aa6e4
	if (!cr6.eq) goto loc_822AA6E4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822AA6E4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// addi r3,r10,24228
	ctx.r3.s64 = ctx.r10.s64 + 24228;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r5,44(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// bl 0x82130000
	ctx.lr = 0x822AA700;
	sub_82130000(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,128(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 128);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822AA714;
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
loc_822AA728:
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa8c0
	if (cr6.eq) goto loc_822AA8C0;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,656(r31)
	PPC_STORE_U32(r31.u32 + 656, ctx.r10.u32);
	// stw r9,668(r31)
	PPC_STORE_U32(r31.u32 + 668, ctx.r9.u32);
	// stb r8,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r8.u8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r4,r10,-16
	ctx.r4.s64 = ctx.r10.s64 + -16;
	// bne cr6,0x822aa764
	if (!cr6.eq) goto loc_822AA764;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822AA764:
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// bl 0x822e6c80
	ctx.lr = 0x822AA76C;
	sub_822E6C80(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r7,140(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa784
	if (cr6.eq) goto loc_822AA784;
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// b 0x822aa798
	goto loc_822AA798;
loc_822AA784:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// bne cr6,0x822aa798
	if (!cr6.eq) goto loc_822AA798;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822AA798:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// addi r3,r10,24172
	ctx.r3.s64 = ctx.r10.s64 + 24172;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r5,44(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// bl 0x82130000
	ctx.lr = 0x822AA7B4;
	sub_82130000(ctx, base);
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
loc_822AA7C8:
	// lwz r11,668(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 668);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x822aa89c
	if (cr6.gt) goto loc_822AA89C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822aa7ec
	if (!cr6.eq) goto loc_822AA7EC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AA7EC:
	// bl 0x82351778
	ctx.lr = 0x822AA7F0;
	sub_82351778(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa874
	if (cr6.eq) goto loc_822AA874;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822aa814
	if (!cr6.eq) goto loc_822AA814;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AA814:
	// bl 0x82351800
	ctx.lr = 0x822AA818;
	sub_82351800(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r7,140(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aa830
	if (cr6.eq) goto loc_822AA830;
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// b 0x822aa844
	goto loc_822AA844;
loc_822AA830:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// bne cr6,0x822aa844
	if (!cr6.eq) goto loc_822AA844;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822AA844:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// addi r3,r10,24104
	ctx.r3.s64 = ctx.r10.s64 + 24104;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r5,44(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// bl 0x82130000
	ctx.lr = 0x822AA860;
	sub_82130000(ctx, base);
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
loc_822AA874:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AA888;
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
loc_822AA89C:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r9,668(r31)
	PPC_STORE_U32(r31.u32 + 668, ctx.r9.u32);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822aa8bc
	if (!cr6.eq) goto loc_822AA8BC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AA8BC:
	// bl 0x82351800
	ctx.lr = 0x822AA8C0;
	sub_82351800(ctx, base);
loc_822AA8C0:
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

__attribute__((alias("__imp__sub_822AA8D4"))) PPC_WEAK_FUNC(sub_822AA8D4);
PPC_FUNC_IMPL(__imp__sub_822AA8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AA8D8"))) PPC_WEAK_FUNC(sub_822AA8D8);
PPC_FUNC_IMPL(__imp__sub_822AA8D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,672(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,-4960(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4960);
	// b 0x823c9be0
	sub_823C9BE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AA8FC"))) PPC_WEAK_FUNC(sub_822AA8FC);
PPC_FUNC_IMPL(__imp__sub_822AA8FC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AA900"))) PPC_WEAK_FUNC(sub_822AA900);
PPC_FUNC_IMPL(__imp__sub_822AA900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r4,672(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// stb r5,676(r3)
	PPC_STORE_U8(ctx.r3.u32 + 676, ctx.r5.u8);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// b 0x823c9be0
	sub_823C9BE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AA924"))) PPC_WEAK_FUNC(sub_822AA924);
PPC_FUNC_IMPL(__imp__sub_822AA924) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AA928"))) PPC_WEAK_FUNC(sub_822AA928);
PPC_FUNC_IMPL(__imp__sub_822AA928) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17708
	ctx.r10.s64 = r11.s64 + 17708;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822aa954
	if (!cr6.eq) goto loc_822AA954;
	// lwz r4,672(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// ble cr6,0x822aa954
	if (!cr6.gt) goto loc_822AA954;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// b 0x823c9920
	sub_823C9920(ctx, base);
	return;
loc_822AA954:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AA95C"))) PPC_WEAK_FUNC(sub_822AA95C);
PPC_FUNC_IMPL(__imp__sub_822AA95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AA960"))) PPC_WEAK_FUNC(sub_822AA960);
PPC_FUNC_IMPL(__imp__sub_822AA960) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-3660(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3660);
	// bl 0x8226a930
	ctx.lr = 0x822AA984;
	sub_8226A930(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aa9a0
	if (cr6.eq) goto loc_822AA9A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AA9A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AA9A0:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aa9bc
	if (cr6.eq) goto loc_822AA9BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AA9BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AA9BC:
	// lwz r4,672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822aa9f8
	if (cr6.lt) goto loc_822AA9F8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823c98b0
	ctx.lr = 0x822AA9D4;
	sub_823C98B0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,672(r31)
	PPC_STORE_U32(r31.u32 + 672, ctx.r10.u32);
	// stb r9,178(r31)
	PPC_STORE_U8(r31.u32 + 178, ctx.r9.u8);
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
loc_822AA9F8:
	// li r11,0
	r11.s64 = 0;
	// stb r11,178(r31)
	PPC_STORE_U8(r31.u32 + 178, r11.u8);
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

__attribute__((alias("__imp__sub_822AAA14"))) PPC_WEAK_FUNC(sub_822AAA14);
PPC_FUNC_IMPL(__imp__sub_822AAA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AAA18"))) PPC_WEAK_FUNC(sub_822AAA18);
PPC_FUNC_IMPL(__imp__sub_822AAA18) {
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
	ctx.lr = 0x822AAA20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aaa3c
	if (cr6.eq) goto loc_822AAA3C;
	// addi r29,r10,8109
	r29.s64 = ctx.r10.s64 + 8109;
	// b 0x822aaa50
	goto loc_822AAA50;
loc_822AAA3C:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r11,8109
	r29.s64 = r11.s64 + 8109;
	// bne cr6,0x822aaa50
	if (!cr6.eq) goto loc_822AAA50;
	// li r29,0
	r29.s64 = 0;
loc_822AAA50:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aaa5c
	if (cr6.eq) goto loc_822AAA5C;
	// addi r29,r10,8109
	r29.s64 = ctx.r10.s64 + 8109;
loc_822AAA5C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82224ac8
	ctx.lr = 0x822AAA64;
	sub_82224AC8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822aaa84
	if (!cr6.eq) goto loc_822AAA84;
	// lbz r10,25(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822aaa88
	if (!cr6.eq) goto loc_822AAA88;
loc_822AAA84:
	// li r28,1
	r28.s64 = 1;
loc_822AAA88:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822aaaa0
	if (!cr6.eq) goto loc_822AAAA0;
	// lbz r11,26(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 26);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aaaa4
	if (cr6.eq) goto loc_822AAAA4;
loc_822AAAA0:
	// li r7,1
	ctx.r7.s64 = 1;
loc_822AAAA4:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822aaaec
	if (!cr6.eq) goto loc_822AAAEC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,17436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17436);
	// addi r30,r10,-288
	r30.s64 = ctx.r10.s64 + -288;
	// addi r27,r9,-12136
	r27.s64 = ctx.r9.s64 + -12136;
	// bl 0x823610b0
	ctx.lr = 0x822AAAD4;
	sub_823610B0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x822AAAE8;
	sub_823DEDD8(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
loc_822AAAEC:
	// lwz r30,64(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82360ea0
	ctx.lr = 0x822AAAF8;
	sub_82360EA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aab30
	if (cr6.eq) goto loc_822AAB30;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82360ee8
	ctx.lr = 0x822AAB0C;
	sub_82360EE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aab30
	if (cr6.eq) goto loc_822AAB30;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82360ef0
	ctx.lr = 0x822AAB20;
	sub_82360EF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822aab34
	if (!cr6.eq) goto loc_822AAB34;
loc_822AAB30:
	// li r11,0
	r11.s64 = 0;
loc_822AAB34:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aace8
	if (cr6.eq) goto loc_822AACE8;
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822aaba4
	if (cr6.eq) goto loc_822AABA4;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8238efe0
	ctx.lr = 0x822AAB54;
	sub_8238EFE0(ctx, base);
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aab68
	if (cr6.eq) goto loc_822AAB68;
	// addi r29,r3,8109
	r29.s64 = ctx.r3.s64 + 8109;
	// b 0x822aab7c
	goto loc_822AAB7C;
loc_822AAB68:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r11,8109
	r29.s64 = r11.s64 + 8109;
	// bne cr6,0x822aab7c
	if (!cr6.eq) goto loc_822AAB7C;
	// li r29,0
	r29.s64 = 0;
loc_822AAB7C:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aab98
	if (cr6.eq) goto loc_822AAB98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AAB98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AAB98:
	// li r11,0
	r11.s64 = 0;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// b 0x822aabd4
	goto loc_822AABD4;
loc_822AABA4:
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822aabd4
	if (cr6.lt) goto loc_822AABD4;
	// bl 0x82387b90
	ctx.lr = 0x822AABB4;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mulli r10,r30,8176
	ctx.r10.s64 = r30.s64 * 8176;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r4,r11,1360
	ctx.r4.s64 = r11.s64 + 1360;
	// bl 0x8238efe0
	ctx.lr = 0x822AABCC;
	sub_8238EFE0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_822AABD4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822aac34
	if (!cr6.eq) goto loc_822AAC34;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,24484
	ctx.r3.s64 = r11.s64 + 24484;
	// bl 0x823db730
	ctx.lr = 0x822AABF0;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822aac28
	if (cr6.eq) goto loc_822AAC28;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,24460
	ctx.r3.s64 = r11.s64 + 24460;
	// bl 0x823db730
	ctx.lr = 0x822AAC08;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822aac28
	if (cr6.eq) goto loc_822AAC28;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,24432
	ctx.r3.s64 = r11.s64 + 24432;
	// bl 0x823db730
	ctx.lr = 0x822AAC20;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822aac34
	if (!cr6.eq) goto loc_822AAC34;
loc_822AAC28:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2145(r11)
	PPC_STORE_U8(r11.u32 + 2145, ctx.r10.u8);
loc_822AAC34:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aac48
	if (cr6.eq) goto loc_822AAC48;
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// b 0x822aac5c
	goto loc_822AAC5C;
loc_822AAC48:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// bne cr6,0x822aac5c
	if (!cr6.eq) goto loc_822AAC5C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_822AAC5C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// addi r3,r10,24376
	ctx.r3.s64 = ctx.r10.s64 + 24376;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r5,44(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// bl 0x82130000
	ctx.lr = 0x822AAC78;
	sub_82130000(ctx, base);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x82360f98
	ctx.lr = 0x822AAC80;
	sub_82360F98(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// bne cr6,0x822aacac
	if (!cr6.eq) goto loc_822AACAC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,24320
	ctx.r3.s64 = r11.s64 + 24320;
	// bl 0x82130000
	ctx.lr = 0x822AAC9C;
	sub_82130000(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82364520
	ctx.lr = 0x822AACA4;
	sub_82364520(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// b 0x822aacb0
	goto loc_822AACB0;
loc_822AACAC:
	// addi r29,r3,8
	r29.s64 = ctx.r3.s64 + 8;
loc_822AACB0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82361650
	ctx.lr = 0x822AACC0;
	sub_82361650(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x82361198
	ctx.lr = 0x822AACCC;
	sub_82361198(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,3
	r11.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r11.u32);
	// lwz r9,120(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822AACE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AACE8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822AACF0"))) PPC_WEAK_FUNC(sub_822AACF0);
PPC_FUNC_IMPL(__imp__sub_822AACF0) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822aad20
	if (!cr6.eq) goto loc_822AAD20;
	// lwz r4,836(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 836);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// ble cr6,0x822aad20
	if (!cr6.gt) goto loc_822AAD20;
	// bl 0x822a8360
	ctx.lr = 0x822AAD20;
	sub_822A8360(ctx, base);
loc_822AAD20:
	// lbz r9,832(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 832);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stb r9,689(r31)
	PPC_STORE_U8(r31.u32 + 689, ctx.r9.u8);
	// beq cr6,0x822aad64
	if (cr6.eq) goto loc_822AAD64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aad64
	if (cr6.eq) goto loc_822AAD64;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aad64
	if (cr6.eq) goto loc_822AAD64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822aad60
	if (!cr6.eq) goto loc_822AAD60;
	// li r11,0
	r11.s64 = 0;
loc_822AAD60:
	// stb r9,597(r11)
	PPC_STORE_U8(r11.u32 + 597, ctx.r9.u8);
loc_822AAD64:
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

__attribute__((alias("__imp__sub_822AAD78"))) PPC_WEAK_FUNC(sub_822AAD78);
PPC_FUNC_IMPL(__imp__sub_822AAD78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r3,768
	ctx.r3.s64 = ctx.r3.s64 + 768;
	// b 0x82137a08
	sub_82137A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AAD90"))) PPC_WEAK_FUNC(sub_822AAD90);
PPC_FUNC_IMPL(__imp__sub_822AAD90) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822aae30
	if (cr6.eq) goto loc_822AAE30;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822aae30
	if (cr6.eq) goto loc_822AAE30;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822aade8
	if (!cr6.eq) goto loc_822AADE8;
	// li r3,8176
	ctx.r3.s64 = 8176;
	// bl 0x82130528
	ctx.lr = 0x822AADD0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aade0
	if (cr6.eq) goto loc_822AADE0;
	// bl 0x8238f550
	ctx.lr = 0x822AADDC;
	sub_8238F550(ctx, base);
	// b 0x822aade4
	goto loc_822AADE4;
loc_822AADE0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AADE4:
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
loc_822AADE8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82390b18
	ctx.lr = 0x822AADF8;
	sub_82390B18(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r31,768
	ctx.r3.s64 = r31.s64 + 768;
	// bl 0x82137a08
	ctx.lr = 0x822AAE10;
	sub_82137A08(ctx, base);
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822aae30
	if (cr6.eq) goto loc_822AAE30;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x822aae30
	if (cr6.eq) goto loc_822AAE30;
	// li r11,1
	r11.s64 = 1;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// stb r11,17(r31)
	PPC_STORE_U8(r31.u32 + 17, r11.u8);
loc_822AAE30:
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

__attribute__((alias("__imp__sub_822AAE48"))) PPC_WEAK_FUNC(sub_822AAE48);
PPC_FUNC_IMPL(__imp__sub_822AAE48) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822aaee8
	if (cr6.eq) goto loc_822AAEE8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822aaee8
	if (cr6.eq) goto loc_822AAEE8;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822aaea0
	if (!cr6.eq) goto loc_822AAEA0;
	// li r3,8176
	ctx.r3.s64 = 8176;
	// bl 0x82130528
	ctx.lr = 0x822AAE88;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aae98
	if (cr6.eq) goto loc_822AAE98;
	// bl 0x8238f550
	ctx.lr = 0x822AAE94;
	sub_8238F550(ctx, base);
	// b 0x822aae9c
	goto loc_822AAE9C;
loc_822AAE98:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AAE9C:
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
loc_822AAEA0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x8238efe0
	ctx.lr = 0x822AAEAC;
	sub_8238EFE0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r6,r11,24500
	ctx.r6.s64 = r11.s64 + 24500;
	// addi r5,r10,9572
	ctx.r5.s64 = ctx.r10.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r31,768
	ctx.r3.s64 = r31.s64 + 768;
	// bl 0x82137a08
	ctx.lr = 0x822AAEC8;
	sub_82137A08(ctx, base);
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822aaee8
	if (cr6.eq) goto loc_822AAEE8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x822aaee8
	if (cr6.eq) goto loc_822AAEE8;
	// li r11,1
	r11.s64 = 1;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// stb r11,17(r31)
	PPC_STORE_U8(r31.u32 + 17, r11.u8);
loc_822AAEE8:
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

__attribute__((alias("__imp__sub_822AAF00"))) PPC_WEAK_FUNC(sub_822AAF00);
PPC_FUNC_IMPL(__imp__sub_822AAF00) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aaf84
	if (cr6.eq) goto loc_822AAF84;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aaf48
	if (cr6.eq) goto loc_822AAF48;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822aaf3c
	if (cr6.eq) goto loc_822AAF3C;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822aaf4c
	goto loc_822AAF4C;
loc_822AAF3C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// b 0x822aaf4c
	goto loc_822AAF4C;
loc_822AAF48:
	// addi r11,r3,288
	r11.s64 = ctx.r3.s64 + 288;
loc_822AAF4C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// lwz r11,-10012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// addi r3,r11,8536
	ctx.r3.s64 = r11.s64 + 8536;
	// bl 0x826db9d0
	ctx.lr = 0x822AAF60;
	sub_826DB9D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822aaf70
	if (!cr6.eq) goto loc_822AAF70;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,24516
	ctx.r3.s64 = r11.s64 + 24516;
loc_822AAF70:
	// bl 0x8238e818
	ctx.lr = 0x822AAF74;
	sub_8238E818(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822AAF84:
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

__attribute__((alias("__imp__sub_822AAF98"))) PPC_WEAK_FUNC(sub_822AAF98);
PPC_FUNC_IMPL(__imp__sub_822AAF98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r11,r3,500
	r11.s64 = ctx.r3.s64 + 500;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_822AAFAC:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r9,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x822aafac
	if (!cr0.eq) goto loc_822AAFAC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AAFC4"))) PPC_WEAK_FUNC(sub_822AAFC4);
PPC_FUNC_IMPL(__imp__sub_822AAFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AAFC8"))) PPC_WEAK_FUNC(sub_822AAFC8);
PPC_FUNC_IMPL(__imp__sub_822AAFC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,492
	ctx.r10.s64 = ctx.r3.s64 + 492;
loc_822AAFD0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822aafe4
	if (cr6.eq) goto loc_822AAFE4;
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x822aaffc
	if (cr6.eq) goto loc_822AAFFC;
loc_822AAFE4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x822aafd0
	if (cr6.lt) goto loc_822AAFD0;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822AAFFC:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822ab01c
	if (cr6.eq) goto loc_822AB01C;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lfs f0,496(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 496);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
loc_822AB01C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AB024"))) PPC_WEAK_FUNC(sub_822AB024);
PPC_FUNC_IMPL(__imp__sub_822AB024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB028"))) PPC_WEAK_FUNC(sub_822AB028);
PPC_FUNC_IMPL(__imp__sub_822AB028) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r11,-1
	r11.s64 = -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,24528(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24528);
	f0.f64 = double(temp.f32);
	// addi r10,r7,500
	ctx.r10.s64 = ctx.r7.s64 + 500;
loc_822AB044:
	// lwz r8,-8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x822ab0e4
	if (cr6.eq) goto loc_822AB0E4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822ab078
	if (cr6.eq) goto loc_822AB078;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822ab06c
	if (cr6.lt) goto loc_822AB06C;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822ab084
	if (!cr6.gt) goto loc_822AB084;
loc_822AB06C:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// b 0x822ab084
	goto loc_822AB084;
loc_822AB078:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge cr6,0x822ab084
	if (!cr6.lt) goto loc_822AB084;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
loc_822AB084:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// blt cr6,0x822ab044
	if (cr6.lt) goto loc_822AB044;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x822ab0a0
	if (cr6.lt) goto loc_822AB0A0;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_822AB0A0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822ab0e4
	if (cr6.lt) goto loc_822AB0E4;
	// addi r10,r11,41
	ctx.r10.s64 = r11.s64 + 41;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,30712(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	f0.f64 = double(temp.f32);
	// stfs f1,496(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 496, temp.u32);
	// stfs f0,500(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 500, temp.u32);
	// stwx r4,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r4.u32);
	// blr 
	return;
loc_822AB0E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AB0EC"))) PPC_WEAK_FUNC(sub_822AB0EC);
PPC_FUNC_IMPL(__imp__sub_822AB0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB0F0"))) PPC_WEAK_FUNC(sub_822AB0F0);
PPC_FUNC_IMPL(__imp__sub_822AB0F0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r4,r11,24692
	ctx.r4.s64 = r11.s64 + 24692;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dd800
	ctx.lr = 0x822AB120;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ab144
	if (!cr6.eq) goto loc_822AB144;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,24632
	ctx.r3.s64 = r11.s64 + 24632;
	// bl 0x82130000
	ctx.lr = 0x822AB138;
	sub_82130000(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r31,r11,24616
	r31.s64 = r11.s64 + 24616;
	// b 0x822ab178
	goto loc_822AB178;
loc_822AB144:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r4,r11,24600
	ctx.r4.s64 = r11.s64 + 24600;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dd800
	ctx.lr = 0x822AB158;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ab178
	if (!cr6.eq) goto loc_822AB178;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,24548
	ctx.r3.s64 = r11.s64 + 24548;
	// bl 0x82130000
	ctx.lr = 0x822AB170;
	sub_82130000(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r31,r11,24532
	r31.s64 = r11.s64 + 24532;
loc_822AB178:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r30,144
	ctx.r3.s64 = r30.s64 + 144;
	// bl 0x82137a08
	ctx.lr = 0x822AB190;
	sub_82137A08(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ab1b4
	if (cr6.eq) goto loc_822AB1B4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,23892
	ctx.r4.s64 = r11.s64 + 23892;
	// bl 0x823d90b0
	ctx.lr = 0x822AB1A8;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822ab1b8
	if (!cr6.eq) goto loc_822AB1B8;
loc_822AB1B4:
	// li r11,0
	r11.s64 = 0;
loc_822AB1B8:
	// stb r11,177(r30)
	PPC_STORE_U8(r30.u32 + 177, r11.u8);
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

__attribute__((alias("__imp__sub_822AB1D4"))) PPC_WEAK_FUNC(sub_822AB1D4);
PPC_FUNC_IMPL(__imp__sub_822AB1D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB1D8"))) PPC_WEAK_FUNC(sub_822AB1D8);
PPC_FUNC_IMPL(__imp__sub_822AB1D8) {
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
	// beq cr6,0x822ab240
	if (cr6.eq) goto loc_822AB240;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a8360
	ctx.lr = 0x822AB1FC;
	sub_822A8360(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a88f8
	ctx.lr = 0x822AB204;
	sub_822A88F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ab240
	if (cr6.eq) goto loc_822AB240;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ab240
	if (cr6.eq) goto loc_822AB240;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,908(r31)
	PPC_STORE_U8(r31.u32 + 908, r11.u8);
	// bl 0x822a5578
	ctx.lr = 0x822AB22C;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ab240
	if (cr6.eq) goto loc_822AB240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x822AB23C;
	sub_822A5578(ctx, base);
	// bl 0x822a2370
	ctx.lr = 0x822AB240;
	sub_822A2370(ctx, base);
loc_822AB240:
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

__attribute__((alias("__imp__sub_822AB254"))) PPC_WEAK_FUNC(sub_822AB254);
PPC_FUNC_IMPL(__imp__sub_822AB254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB258"))) PPC_WEAK_FUNC(sub_822AB258);
PPC_FUNC_IMPL(__imp__sub_822AB258) {
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
	ctx.lr = 0x822AB260;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ab30c
	if (cr6.eq) goto loc_822AB30C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r29,1
	r29.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ab2a0
	if (cr6.eq) goto loc_822AB2A0;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822ab2a0
	if (cr6.eq) goto loc_822AB2A0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8232c788
	ctx.lr = 0x822AB294;
	sub_8232C788(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r11.u32);
	// b 0x822ab2a4
	goto loc_822AB2A4;
loc_822AB2A0:
	// stw r29,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r29.u32);
loc_822AB2A4:
	// lwz r30,48(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ab30c
	if (cr6.eq) goto loc_822AB30C;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ab2d8
	if (cr6.eq) goto loc_822AB2D8;
	// lwz r3,84(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// bl 0x8233e1b0
	ctx.lr = 0x822AB2C8;
	sub_8233E1B0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,656(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 656, temp.u32);
loc_822AB2D8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a88f8
	ctx.lr = 0x822AB2E0;
	sub_822A88F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ab30c
	if (cr6.eq) goto loc_822AB30C;
	// stb r29,908(r31)
	PPC_STORE_U8(r31.u32 + 908, r29.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x822AB2F8;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ab30c
	if (cr6.eq) goto loc_822AB30C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x822AB308;
	sub_822A5578(ctx, base);
	// bl 0x822a0f10
	ctx.lr = 0x822AB30C;
	sub_822A0F10(ctx, base);
loc_822AB30C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822AB314"))) PPC_WEAK_FUNC(sub_822AB314);
PPC_FUNC_IMPL(__imp__sub_822AB314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB318"))) PPC_WEAK_FUNC(sub_822AB318);
PPC_FUNC_IMPL(__imp__sub_822AB318) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822AB320;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ab630
	if (cr6.eq) goto loc_822AB630;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ab630
	if (cr6.eq) goto loc_822AB630;
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822ab630
	if (cr6.eq) goto loc_822AB630;
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822ab630
	if (cr6.eq) goto loc_822AB630;
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ab368
	if (cr6.eq) goto loc_822AB368;
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822ab630
	if (!cr6.eq) goto loc_822AB630;
loc_822AB368:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,27632(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27632);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822ab384
	if (!cr6.gt) goto loc_822AB384;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
loc_822AB384:
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ab3b8
	if (cr6.eq) goto loc_822AB3B8;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f0,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f13,224(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,-11624(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11624);
	f0.f64 = double(temp.f32);
	// fabs f11,f12
	ctx.f11.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x822ab3b8
	if (!cr6.gt) goto loc_822AB3B8;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
loc_822AB3B8:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r7,48
	ctx.r7.s64 = 48;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ab518
	if (cr6.eq) goto loc_822AB518;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ab3e4
	if (cr6.eq) goto loc_822AB3E4;
	// addi r11,r8,272
	r11.s64 = ctx.r8.s64 + 272;
	// b 0x822ab3ec
	goto loc_822AB3EC;
loc_822AB3E4:
	// lwz r11,28(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822AB3EC:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvx128 v60,r11,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822ab40c
	if (cr6.eq) goto loc_822AB40C;
	// addi r11,r8,272
	r11.s64 = ctx.r8.s64 + 272;
	// b 0x822ab414
	goto loc_822AB414;
loc_822AB40C:
	// lwz r11,28(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822AB414:
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ab428
	if (cr6.eq) goto loc_822AB428;
	// addi r11,r9,272
	r11.s64 = ctx.r9.s64 + 272;
	// b 0x822ab430
	goto loc_822AB430;
loc_822AB428:
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822AB430:
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v60,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vsubfp128 v63,v62,v63
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r5,r11,2528
	ctx.r5.s64 = r11.s64 + 2528;
	// addi r4,r10,2240
	ctx.r4.s64 = ctx.r10.s64 + 2240;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r11,r11,-31648
	r11.s64 = r11.s64 + -31648;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,-31664
	ctx.r10.s64 = ctx.r10.s64 + -31664;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vor128 v0,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// addi r30,r1,112
	r30.s64 = ctx.r1.s64 + 112;
	// vor128 v13,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32253
	r11.s64 = -2113732608;
	// vmsum3fp128 v58,v63,v63
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v12,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v57,v59
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v11,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// lfs f0,-9160(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9160);
	f0.f64 = double(temp.f32);
	// vcmpeqfp128 v10,v57,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v9,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vrsqrtefp128 v56,v58
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vor128 v8,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vsel v0,v9,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vcmpeqfp128 v7,v56,v61
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v6,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v62,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v6,v13,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vnmsubfp v3,v11,v5,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v2,v13,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v1,v62,v13
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v31,v3,v4,v0
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v30,v8,v2,v12
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v55,v60,v31
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v31.f32)));
	// vmaddfp v29,v30,v1,v13
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v55,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v54,v63,v29
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v29.f32)));
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v54,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmadds f6,f13,f10,f7
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f5,f12,f9,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// ble cr6,0x822ab518
	if (!cr6.gt) goto loc_822AB518;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
loc_822AB518:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ab620
	if (cr6.eq) goto loc_822AB620;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r11,2256
	ctx.r4.s64 = r11.s64 + 2256;
	// li r3,72
	ctx.r3.s64 = 72;
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// addi r30,r1,192
	r30.s64 = ctx.r1.s64 + 192;
	// lis r29,-32256
	r29.s64 = -2113929216;
	// lis r28,-32256
	r28.s64 = -2113929216;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbzx r10,r3,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// stw r6,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,3796(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r5,220(r1)
	PPC_STORE_U16(ctx.r1.u32 + 220, ctx.r5.u16);
	// lfs f13,14884(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// sth r6,222(r1)
	PPC_STORE_U16(ctx.r1.u32 + 222, ctx.r6.u16);
	// stfs f0,208(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stb r6,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, ctx.r6.u8);
	// stfs f0,212(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// sth r6,226(r1)
	PPC_STORE_U16(ctx.r1.u32 + 226, ctx.r6.u16);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r6,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r6.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// beq cr6,0x822ab5a4
	if (cr6.eq) goto loc_822AB5A4;
	// addi r11,r9,272
	r11.s64 = ctx.r9.s64 + 272;
	// b 0x822ab5ac
	goto loc_822AB5AC;
loc_822AB5A4:
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822AB5AC:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v53,r11,r7
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v63,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v53.f32)));
	// beq cr6,0x822ab5cc
	if (cr6.eq) goto loc_822AB5CC;
	// addi r11,r8,272
	r11.s64 = ctx.r8.s64 + 272;
	// b 0x822ab5d4
	goto loc_822AB5D4;
loc_822AB5CC:
	// lwz r11,28(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822AB5D4:
	// lvx128 v52,r11,r7
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// vaddfp128 v51,v63,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v52.f32)));
	// addi r30,r1,112
	r30.s64 = ctx.r1.s64 + 112;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-23452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v51,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x822AB618;
	sub_82574418(ctx, base);
	// cntlzw r4,r3
	ctx.r4.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
loc_822AB620:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stb r3,113(r11)
	PPC_STORE_U8(r11.u32 + 113, ctx.r3.u8);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9248
	return;
loc_822AB630:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822AB63C"))) PPC_WEAK_FUNC(sub_822AB63C);
PPC_FUNC_IMPL(__imp__sub_822AB63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB640"))) PPC_WEAK_FUNC(sub_822AB640);
PPC_FUNC_IMPL(__imp__sub_822AB640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r3,144
	ctx.r4.s64 = ctx.r3.s64 + 144;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// b 0x82218310
	sub_82218310(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AB650"))) PPC_WEAK_FUNC(sub_822AB650);
PPC_FUNC_IMPL(__imp__sub_822AB650) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// lwz r4,672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822ab6cc
	if (cr6.lt) goto loc_822AB6CC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823c9940
	ctx.lr = 0x822AB67C;
	sub_823C9940(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ab6b4
	if (cr6.eq) goto loc_822AB6B4;
	// addi r11,r31,704
	r11.s64 = r31.s64 + 704;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822AB6B4:
	// addi r3,r31,704
	ctx.r3.s64 = r31.s64 + 704;
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
loc_822AB6CC:
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

__attribute__((alias("__imp__sub_822AB6E4"))) PPC_WEAK_FUNC(sub_822AB6E4);
PPC_FUNC_IMPL(__imp__sub_822AB6E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB6E8"))) PPC_WEAK_FUNC(sub_822AB6E8);
PPC_FUNC_IMPL(__imp__sub_822AB6E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r5,672(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// b 0x823c9930
	sub_823C9930(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AB700"))) PPC_WEAK_FUNC(sub_822AB700);
PPC_FUNC_IMPL(__imp__sub_822AB700) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AB704"))) PPC_WEAK_FUNC(sub_822AB704);
PPC_FUNC_IMPL(__imp__sub_822AB704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB708"))) PPC_WEAK_FUNC(sub_822AB708);
PPC_FUNC_IMPL(__imp__sub_822AB708) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x822ab720
	if (!cr6.lt) goto loc_822AB720;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x822ab72c
	goto loc_822AB72C;
loc_822AB720:
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// ble cr6,0x822ab72c
	if (!cr6.gt) goto loc_822AB72C;
	// li r4,3
	ctx.r4.s64 = 3;
loc_822AB72C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r9,r4,531
	ctx.r9.s64 = ctx.r4.s64 + 531;
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// li r6,96
	ctx.r6.s64 = 96;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lfs f13,8500(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8500);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8504(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8504);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,108(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AB77C"))) PPC_WEAK_FUNC(sub_822AB77C);
PPC_FUNC_IMPL(__imp__sub_822AB77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB780"))) PPC_WEAK_FUNC(sub_822AB780);
PPC_FUNC_IMPL(__imp__sub_822AB780) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ab818
	if (cr6.eq) goto loc_822AB818;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10020(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10020);
	// bl 0x826bcb70
	ctx.lr = 0x822AB7B0;
	sub_826BCB70(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x822ab7c0
	if (!cr6.lt) goto loc_822AB7C0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822ab7cc
	goto loc_822AB7CC;
loc_822AB7C0:
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// ble cr6,0x822ab7cc
	if (!cr6.gt) goto loc_822AB7CC;
	// li r3,3
	ctx.r3.s64 = 3;
loc_822AB7CC:
	// lwz r11,-10020(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10020);
	// addi r9,r3,531
	ctx.r9.s64 = ctx.r3.s64 + 531;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,96
	ctx.r6.s64 = 96;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// lfs f13,8500(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8500);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8504(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8504);
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
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// b 0x822ab81c
	goto loc_822AB81C;
loc_822AB818:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AB81C:
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

__attribute__((alias("__imp__sub_822AB834"))) PPC_WEAK_FUNC(sub_822AB834);
PPC_FUNC_IMPL(__imp__sub_822AB834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB838"))) PPC_WEAK_FUNC(sub_822AB838);
PPC_FUNC_IMPL(__imp__sub_822AB838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ab950
	if (cr6.eq) goto loc_822AB950;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ab950
	if (cr6.eq) goto loc_822AB950;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r11,-31280
	ctx.r9.s64 = r11.s64 + -31280;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r9,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r9,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v60,r9,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,27644(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x8216c890
	ctx.lr = 0x822AB8C8;
	sub_8216C890(ctx, base);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v60,v62,99
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// lvlx128 v59,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vpermwi128 v0,v62,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v13,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vmulfp128 v12,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// vmulfp128 v56,v63,v58
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r5,2272
	ctx.r6.s64 = ctx.r5.s64 + 2272;
	// lfs f2,30712(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f1,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vnmsubfp v11,v13,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a9930
	ctx.lr = 0x822AB950;
	sub_822A9930(ctx, base);
loc_822AB950:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_822AB96C"))) PPC_WEAK_FUNC(sub_822AB96C);
PPC_FUNC_IMPL(__imp__sub_822AB96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AB970"))) PPC_WEAK_FUNC(sub_822AB970);
PPC_FUNC_IMPL(__imp__sub_822AB970) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r0{};
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
	// bl 0x823d91e4
	ctx.lr = 0x822AB978;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82740f18
	ctx.lr = 0x822AB998;
	sub_82740F18(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// vspltisw128 v126,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r11,23916
	ctx.r9.s64 = r11.s64 + 23916;
	// stb r30,32(r31)
	PPC_STORE_U8(r31.u32 + 32, r30.u8);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r11,r31,608
	r11.s64 = r31.s64 + 608;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stb r30,112(r31)
	PPC_STORE_U8(r31.u32 + 112, r30.u8);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// addi r5,r8,2256
	ctx.r5.s64 = ctx.r8.s64 + 2256;
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stb r30,466(r31)
	PPC_STORE_U8(r31.u32 + 466, r30.u8);
	// stb r30,467(r31)
	PPC_STORE_U8(r31.u32 + 467, r30.u8);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stb r30,468(r31)
	PPC_STORE_U8(r31.u32 + 468, r30.u8);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r30,484(r31)
	PPC_STORE_U32(r31.u32 + 484, r30.u32);
	// li r29,1
	r29.s64 = 1;
	// sth r30,488(r31)
	PPC_STORE_U16(r31.u32 + 488, r30.u16);
	// li r28,16
	r28.s64 = 16;
	// li r3,20
	ctx.r3.s64 = 20;
	// vupkd3d128 v127,v126,4
	temp.f32 = 3.0f;
	temp.s32 += v126.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v126.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v127 = vTemp;
	// lfs f31,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r7,r31,192
	ctx.r7.s64 = r31.s64 + 192;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r6,r31,208
	ctx.r6.s64 = r31.s64 + 208;
	// addi r10,r31,484
	ctx.r10.s64 = r31.s64 + 484;
	// vpermwi128 v62,v127,234
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x15));
	// li r26,32
	r26.s64 = 32;
	// vpermwi128 v61,v127,186
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x45));
	// li r27,48
	r27.s64 = 48;
	// vpermwi128 v60,v127,174
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x51));
	// li r25,432
	r25.s64 = 432;
	// vpermwi128 v59,v127,234
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x15));
	// li r24,448
	r24.s64 = 448;
	// vpermwi128 v58,v127,186
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x45));
	// addi r10,r31,288
	ctx.r10.s64 = r31.s64 + 288;
	// vpermwi128 v57,v127,174
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x51));
	// addi r9,r31,352
	ctx.r9.s64 = r31.s64 + 352;
	// vpermwi128 v56,v127,234
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x15));
	// vpermwi128 v55,v127,186
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x45));
	// li r23,416
	r23.s64 = 416;
	// vpermwi128 v54,v127,174
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x51));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,640(r31)
	PPC_STORE_U32(r31.u32 + 640, r30.u32);
	// stfs f31,644(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 644, temp.u32);
	// stb r30,652(r31)
	PPC_STORE_U8(r31.u32 + 652, r30.u8);
	// stfs f31,648(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 648, temp.u32);
	// stw r8,672(r31)
	PPC_STORE_U32(r31.u32 + 672, ctx.r8.u32);
	// stb r30,676(r31)
	PPC_STORE_U8(r31.u32 + 676, r30.u8);
	// addi r11,r31,224
	r11.s64 = r31.s64 + 224;
	// stw r3,684(r31)
	PPC_STORE_U32(r31.u32 + 684, ctx.r3.u32);
	// stb r30,688(r31)
	PPC_STORE_U8(r31.u32 + 688, r30.u8);
	// stb r29,689(r31)
	PPC_STORE_U8(r31.u32 + 689, r29.u8);
	// stb r29,690(r31)
	PPC_STORE_U8(r31.u32 + 690, r29.u8);
	// stb r30,691(r31)
	PPC_STORE_U8(r31.u32 + 691, r30.u8);
	// stw r8,692(r31)
	PPC_STORE_U32(r31.u32 + 692, ctx.r8.u32);
	// stw r30,832(r31)
	PPC_STORE_U32(r31.u32 + 832, r30.u32);
	// stw r30,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r30.u32);
	// stb r30,840(r31)
	PPC_STORE_U8(r31.u32 + 840, r30.u8);
	// stb r30,845(r31)
	PPC_STORE_U8(r31.u32 + 845, r30.u8);
	// stb r30,850(r31)
	PPC_STORE_U8(r31.u32 + 850, r30.u8);
	// stb r30,854(r31)
	PPC_STORE_U8(r31.u32 + 854, r30.u8);
	// stw r4,680(r31)
	PPC_STORE_U32(r31.u32 + 680, ctx.r4.u32);
	// lvx128 v53,r0,r7
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v52,v53,v53
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_setzero_si128());
	// stvx128 v52,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r6
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v50,v51,v51
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_setzero_si128());
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// li r4,8
	ctx.r4.s64 = 8;
	// stvx128 v50,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// stvx128 v126,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r9,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r9,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r9,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,464(r31)
	PPC_STORE_U8(r31.u32 + 464, r30.u8);
	// stfs f31,588(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// stfs f31,592(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 592, temp.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stfs f31,76(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stvx128 v126,r31,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// lfs f0,24716(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24716);
	f0.f64 = double(temp.f32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// lfs f13,24712(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24712);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r30.u32);
	// lfs f12,24708(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 24708);
	ctx.f12.f64 = double(temp.f32);
	// stw r30,660(r31)
	PPC_STORE_U32(r31.u32 + 660, r30.u32);
	// stw r30,664(r31)
	PPC_STORE_U32(r31.u32 + 664, r30.u32);
	// stw r4,668(r31)
	PPC_STORE_U32(r31.u32 + 668, ctx.r4.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r8,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r8.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
	// stb r30,144(r31)
	PPC_STORE_U8(r31.u32 + 144, r30.u8);
	// stb r29,176(r31)
	PPC_STORE_U8(r31.u32 + 176, r29.u8);
	// stb r30,178(r31)
	PPC_STORE_U8(r31.u32 + 178, r30.u8);
	// stb r30,177(r31)
	PPC_STORE_U8(r31.u32 + 177, r30.u8);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// stb r30,17(r31)
	PPC_STORE_U8(r31.u32 + 17, r30.u8);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// stb r30,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r30.u8);
	// stb r30,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r30.u8);
	// stb r30,26(r31)
	PPC_STORE_U8(r31.u32 + 26, r30.u8);
	// lwz r11,-292(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -292);
	// stb r30,465(r31)
	PPC_STORE_U8(r31.u32 + 465, r30.u8);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stfs f0,472(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 472, temp.u32);
	// stfs f13,476(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 476, temp.u32);
	// stfs f12,480(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// lwz r3,484(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 484);
	// bl 0x82130588
	ctx.lr = 0x822ABBC4;
	sub_82130588(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// sth r5,490(r31)
	PPC_STORE_U16(r31.u32 + 490, ctx.r5.u16);
	// li r3,4
	ctx.r3.s64 = 4;
	// sth r29,488(r31)
	PPC_STORE_U16(r31.u32 + 488, r29.u16);
	// bl 0x82130528
	ctx.lr = 0x822ABBD8;
	sub_82130528(ctx, base);
	// stw r3,484(r31)
	PPC_STORE_U32(r31.u32 + 484, ctx.r3.u32);
	// lhz r11,488(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 488);
	// li r4,0
	ctx.r4.s64 = 0;
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x822ABBEC;
	sub_8244D150(ctx, base);
	// addi r11,r31,500
	r11.s64 = r31.s64 + 500;
	// li r10,8
	ctx.r10.s64 = 8;
loc_822ABBF4:
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r30,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x822abbf4
	if (!cr0.eq) goto loc_822ABBF4;
	// vpermwi128 v49,v127,234
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x15));
	// addi r11,r31,704
	r11.s64 = r31.s64 + 704;
	// vpermwi128 v48,v127,186
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x45));
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// vpermwi128 v47,v127,174
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x51));
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,768(r31)
	PPC_STORE_U8(r31.u32 + 768, r30.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822ABC54"))) PPC_WEAK_FUNC(sub_822ABC54);
PPC_FUNC_IMPL(__imp__sub_822ABC54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ABC58"))) PPC_WEAK_FUNC(sub_822ABC58);
PPC_FUNC_IMPL(__imp__sub_822ABC58) {
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
	// bl 0x822a9268
	ctx.lr = 0x822ABC78;
	sub_822A9268(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abc90
	if (cr6.eq) goto loc_822ABC90;
	// bl 0x82130588
	ctx.lr = 0x822ABC8C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822ABC90:
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

__attribute__((alias("__imp__sub_822ABCA8"))) PPC_WEAK_FUNC(sub_822ABCA8);
PPC_FUNC_IMPL(__imp__sub_822ABCA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// stw r11,680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 680, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822abcc4
	if (cr6.eq) goto loc_822ABCC4;
	// li r11,1
	r11.s64 = 1;
	// stw r11,680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 680, r11.u32);
loc_822ABCC4:
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abcdc
	if (cr6.eq) goto loc_822ABCDC;
	// lwz r11,680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 680);
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// stw r10,680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 680, ctx.r10.u32);
loc_822ABCDC:
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abcf4
	if (cr6.eq) goto loc_822ABCF4;
	// lwz r11,680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 680);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stw r10,680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 680, ctx.r10.u32);
loc_822ABCF4:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// b 0x822a93a8
	sub_822A93A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ABD08"))) PPC_WEAK_FUNC(sub_822ABD08);
PPC_FUNC_IMPL(__imp__sub_822ABD08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ABD0C"))) PPC_WEAK_FUNC(sub_822ABD0C);
PPC_FUNC_IMPL(__imp__sub_822ABD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ABD10"))) PPC_WEAK_FUNC(sub_822ABD10);
PPC_FUNC_IMPL(__imp__sub_822ABD10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,204(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// stfs f0,192(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// stfs f13,196(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// stfs f12,200(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// b 0x822a9788
	sub_822A9788(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ABD34"))) PPC_WEAK_FUNC(sub_822ABD34);
PPC_FUNC_IMPL(__imp__sub_822ABD34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ABD38"))) PPC_WEAK_FUNC(sub_822ABD38);
PPC_FUNC_IMPL(__imp__sub_822ABD38) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x822ABD40;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// lwz r11,672(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 672);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822abd8c
	if (cr6.lt) goto loc_822ABD8C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822ABD68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,24832
	ctx.r3.s64 = ctx.r9.s64 + 24832;
	// bl 0x82130000
	ctx.lr = 0x822ABD78;
	sub_82130000(ctx, base);
	// lwz r3,-4960(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// lwz r4,672(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 672);
	// bl 0x823c98b0
	ctx.lr = 0x822ABD84;
	sub_823C98B0(ctx, base);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r8,672(r28)
	PPC_STORE_U32(r28.u32 + 672, ctx.r8.u32);
loc_822ABD8C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17708
	ctx.r10.s64 = r11.s64 + 17708;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ac160
	if (!cr6.eq) goto loc_822AC160;
	// lbz r11,176(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ac160
	if (cr6.eq) goto loc_822AC160;
	// lbz r11,25(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abdcc
	if (cr6.eq) goto loc_822ABDCC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a7d90
	ctx.lr = 0x822ABDC0;
	sub_822A7D90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ac160
	if (cr6.eq) goto loc_822AC160;
loc_822ABDCC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r20,48(r28)
	r20.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// beq cr6,0x822ac160
	if (cr6.eq) goto loc_822AC160;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17628
	ctx.r10.s64 = r11.s64 + 17628;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abe1c
	if (cr6.eq) goto loc_822ABE1C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,24532
	ctx.r4.s64 = r11.s64 + 24532;
	// b 0x822abe50
	goto loc_822ABE50;
loc_822ABE1C:
	// addi r11,r28,144
	r11.s64 = r28.s64 + 144;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822ABE24:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822abe24
	if (!cr6.eq) goto loc_822ABE24;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822abe58
	if (!cr6.eq) goto loc_822ABE58;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,24616
	ctx.r4.s64 = r11.s64 + 24616;
loc_822ABE50:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822ab0f0
	ctx.lr = 0x822ABE58;
	sub_822AB0F0(ctx, base);
loc_822ABE58:
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abe6c
	if (cr6.eq) goto loc_822ABE6C;
	// addi r10,r11,8109
	ctx.r10.s64 = r11.s64 + 8109;
	// b 0x822abe80
	goto loc_822ABE80;
loc_822ABE6C:
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,8109
	ctx.r10.s64 = r11.s64 + 8109;
	// bne cr6,0x822abe80
	if (!cr6.eq) goto loc_822ABE80;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_822ABE80:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,24808
	r11.s64 = r11.s64 + 24808;
loc_822ABE88:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822abeac
	if (cr6.eq) goto loc_822ABEAC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822abe88
	if (cr6.eq) goto loc_822ABE88;
loc_822ABEAC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cntlzw r10,r9
	ctx.r10.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r9,r11,17452
	ctx.r9.s64 = r11.s64 + 17452;
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abedc
	if (cr6.eq) goto loc_822ABEDC;
	// lbz r11,177(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 177);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bne cr6,0x822abee0
	if (!cr6.eq) goto loc_822ABEE0;
loc_822ABEDC:
	// li r11,1
	r11.s64 = 1;
loc_822ABEE0:
	// lwz r9,28(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 28);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822ac160
	if (cr6.eq) goto loc_822AC160;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ac160
	if (cr6.eq) goto loc_822AC160;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ac160
	if (cr6.eq) goto loc_822AC160;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r9.u32);
	// stw r10,672(r28)
	PPC_STORE_U32(r28.u32 + 672, ctx.r10.u32);
	// bl 0x82224ac8
	ctx.lr = 0x822ABF28;
	sub_82224AC8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r31,r11,17492
	r31.s64 = r11.s64 + 17492;
	// beq cr6,0x822abf4c
	if (cr6.eq) goto loc_822ABF4C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abf50
	if (cr6.eq) goto loc_822ABF50;
loc_822ABF4C:
	// mr r30,r27
	r30.u64 = r27.u64;
loc_822ABF50:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822ABF64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822abf80
	if (cr6.eq) goto loc_822ABF80;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r21,1
	r21.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abf84
	if (cr6.eq) goto loc_822ABF84;
loc_822ABF80:
	// mr r21,r27
	r21.u64 = r27.u64;
loc_822ABF84:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82332098
	ctx.lr = 0x822ABF8C;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abfb0
	if (cr6.eq) goto loc_822ABFB0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r31,1
	r31.s64 = 1;
	// addi r10,r11,17572
	ctx.r10.s64 = r11.s64 + 17572;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822abfb4
	if (cr6.eq) goto loc_822ABFB4;
loc_822ABFB0:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822ABFB4:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823315c0
	ctx.lr = 0x822ABFBC;
	sub_823315C0(ctx, base);
	// lbz r11,177(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 177);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// clrlwi r9,r25,24
	ctx.r9.u64 = r25.u32 & 0xFF;
	// rlwinm r24,r10,27,31,31
	r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822abfe4
	if (cr6.eq) goto loc_822ABFE4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,14248
	ctx.r4.s64 = r11.s64 + 14248;
	// b 0x822abfec
	goto loc_822ABFEC;
loc_822ABFE4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,24804
	ctx.r4.s64 = r11.s64 + 24804;
loc_822ABFEC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,24788
	ctx.r3.s64 = r11.s64 + 24788;
	// bl 0x82130000
	ctx.lr = 0x822ABFF8;
	sub_82130000(ctx, base);
	// clrlwi r23,r30,24
	r23.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x822ac060
	if (!cr6.eq) goto loc_822AC060;
	// lbz r11,178(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 178);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ac060
	if (!cr6.eq) goto loc_822AC060;
	// clrlwi r26,r31,24
	r26.u64 = r31.u32 & 0xFF;
	// lwz r3,-4960(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// addi r31,r28,144
	r31.s64 = r28.s64 + 144;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// beq cr6,0x822ac044
	if (cr6.eq) goto loc_822AC044;
	// bl 0x823c9b60
	ctx.lr = 0x822AC02C;
	sub_823C9B60(ctx, base);
	// lwz r11,-4960(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9b90
	ctx.lr = 0x822AC040;
	sub_823C9B90(ctx, base);
	// b 0x822ac0ac
	goto loc_822AC0AC;
loc_822AC044:
	// bl 0x823c9b00
	ctx.lr = 0x822AC048;
	sub_823C9B00(ctx, base);
	// lwz r11,-4960(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9b30
	ctx.lr = 0x822AC05C;
	sub_823C9B30(ctx, base);
	// b 0x822ac0ac
	goto loc_822AC0AC;
loc_822AC060:
	// clrlwi r26,r31,24
	r26.u64 = r31.u32 & 0xFF;
	// lwz r3,-4960(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// addi r31,r28,144
	r31.s64 = r28.s64 + 144;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// beq cr6,0x822ac094
	if (cr6.eq) goto loc_822AC094;
	// bl 0x823c99e0
	ctx.lr = 0x822AC07C;
	sub_823C99E0(ctx, base);
	// lwz r11,-4960(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9a10
	ctx.lr = 0x822AC090;
	sub_823C9A10(ctx, base);
	// b 0x822ac0ac
	goto loc_822AC0AC;
loc_822AC094:
	// bl 0x823c9980
	ctx.lr = 0x822AC098;
	sub_823C9980(ctx, base);
	// lwz r11,-4960(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c99b0
	ctx.lr = 0x822AC0AC;
	sub_823C99B0(ctx, base);
loc_822AC0AC:
	// lwz r11,60(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ac0c8
	if (!cr6.eq) goto loc_822AC0C8;
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ac0cc
	if (cr6.eq) goto loc_822AC0CC;
loc_822AC0C8:
	// addi r27,r11,8109
	r27.s64 = r11.s64 + 8109;
loc_822AC0CC:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82332098
	ctx.lr = 0x822AC0D4;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x8239e458
	ctx.lr = 0x822AC100;
	sub_8239E458(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ac140
	if (cr6.eq) goto loc_822AC140;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822ac140
	if (cr6.eq) goto loc_822AC140;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,-4960(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -4960);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r5,676(r28)
	ctx.r5.u64 = PPC_LOAD_U8(r28.u32 + 676);
	// lwz r4,672(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 672);
	// bl 0x823c9c58
	ctx.lr = 0x822AC130;
	sub_823C9C58(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x822AC138;
	sub_82130588(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9228
	return;
loc_822AC140:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// addi r3,r11,24720
	ctx.r3.s64 = r11.s64 + 24720;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x822AC158;
	sub_82130000(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x822AC160;
	sub_82130588(ctx, base);
loc_822AC160:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_822AC168"))) PPC_WEAK_FUNC(sub_822AC168);
PPC_FUNC_IMPL(__imp__sub_822AC168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r31,608
	r11.s64 = r31.s64 + 608;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r30,0
	r30.s64 = 0;
	// stb r30,691(r31)
	PPC_STORE_U8(r31.u32 + 691, r30.u8);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,644(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 644, temp.u32);
	// stb r30,652(r31)
	PPC_STORE_U8(r31.u32 + 652, r30.u8);
	// stfs f31,648(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 648, temp.u32);
	// stw r30,640(r31)
	PPC_STORE_U32(r31.u32 + 640, r30.u32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822ac1d4
	if (cr6.lt) goto loc_822AC1D4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823c9910
	ctx.lr = 0x822AC1D4;
	sub_823C9910(ctx, base);
loc_822AC1D4:
	// li r11,20
	r11.s64 = 20;
	// stb r30,676(r31)
	PPC_STORE_U8(r31.u32 + 676, r30.u8);
	// stb r30,688(r31)
	PPC_STORE_U8(r31.u32 + 688, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,684(r31)
	PPC_STORE_U32(r31.u32 + 684, r11.u32);
	// bl 0x822a9788
	ctx.lr = 0x822AC1EC;
	sub_822A9788(ctx, base);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ac208
	if (cr6.eq) goto loc_822AC208;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AC208:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ac238
	if (cr6.eq) goto loc_822AC238;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822AC238;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AC238:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stb r30,468(r31)
	PPC_STORE_U8(r31.u32 + 468, r30.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ac2f0
	if (cr6.eq) goto loc_822AC2F0;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f30,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f30.f64 = double(temp.f32);
	// bl 0x82331300
	ctx.lr = 0x822AC254;
	sub_82331300(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stfs f30,40(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 40, temp.u32);
	// stfs f30,36(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 36, temp.u32);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x82342718
	ctx.lr = 0x822AC270;
	sub_82342718(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// bl 0x82331d28
	ctx.lr = 0x822AC27C;
	sub_82331D28(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822ac29c
	if (cr6.eq) goto loc_822AC29C;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x82331d18
	ctx.lr = 0x822AC290;
	sub_82331D18(ctx, base);
	// bl 0x822a5948
	ctx.lr = 0x822AC294;
	sub_822A5948(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x822AC298;
	sub_822A5578(ctx, base);
	// stfs f30,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
loc_822AC29C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8360
	ctx.lr = 0x822AC2A8;
	sub_822A8360(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3660(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3660);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ac2c0
	if (cr6.eq) goto loc_822AC2C0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226a930
	ctx.lr = 0x822AC2C0;
	sub_8226A930(ctx, base);
loc_822AC2C0:
	// lhz r11,488(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 488);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,484(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 484);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x822AC2D4;
	sub_8244D150(ctx, base);
	// addi r11,r31,500
	r11.s64 = r31.s64 + 500;
	// li r10,8
	ctx.r10.s64 = 8;
loc_822AC2DC:
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r30,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x822ac2dc
	if (!cr0.eq) goto loc_822AC2DC;
loc_822AC2F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_822AC310"))) PPC_WEAK_FUNC(sub_822AC310);
PPC_FUNC_IMPL(__imp__sub_822AC310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// bl 0x823d91fc
	ctx.lr = 0x822AC318;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r31,608
	r11.s64 = r31.s64 + 608;
	// li r29,16
	r29.s64 = 16;
	// li r30,0
	r30.s64 = 0;
	// stb r30,691(r31)
	PPC_STORE_U8(r31.u32 + 691, r30.u8);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,644(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 644, temp.u32);
	// stb r30,652(r31)
	PPC_STORE_U8(r31.u32 + 652, r30.u8);
	// stfs f31,648(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 648, temp.u32);
	// stw r30,640(r31)
	PPC_STORE_U32(r31.u32 + 640, r30.u32);
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822ac378
	if (cr6.lt) goto loc_822AC378;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823c9910
	ctx.lr = 0x822AC378;
	sub_823C9910(ctx, base);
loc_822AC378:
	// li r11,20
	r11.s64 = 20;
	// stb r30,676(r31)
	PPC_STORE_U8(r31.u32 + 676, r30.u8);
	// stb r30,688(r31)
	PPC_STORE_U8(r31.u32 + 688, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,684(r31)
	PPC_STORE_U32(r31.u32 + 684, r11.u32);
	// bl 0x822a9788
	ctx.lr = 0x822AC390;
	sub_822A9788(ctx, base);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ac3ac
	if (cr6.eq) goto loc_822AC3AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC3AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AC3AC:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ac3dc
	if (cr6.eq) goto loc_822AC3DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC3C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822AC3DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AC3DC:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stb r30,468(r31)
	PPC_STORE_U8(r31.u32 + 468, r30.u8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ac47c
	if (cr6.eq) goto loc_822AC47C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC3FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8360
	ctx.lr = 0x822AC408;
	sub_822A8360(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,-3660(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3660);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ac420
	if (cr6.eq) goto loc_822AC420;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226a930
	ctx.lr = 0x822AC420;
	sub_8226A930(ctx, base);
loc_822AC420:
	// lhz r11,488(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 488);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,484(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 484);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x822AC434;
	sub_8244D150(ctx, base);
	// addi r11,r31,500
	r11.s64 = r31.s64 + 500;
	// li r10,8
	ctx.r10.s64 = 8;
loc_822AC43C:
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r30,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x822ac43c
	if (!cr0.eq) goto loc_822AC43C;
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
	// addi r11,r31,704
	r11.s64 = r31.s64 + 704;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// vpermwi128 v62,v63,234
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// vpermwi128 v61,v63,186
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v60,v63,174
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822AC47C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822AC490"))) PPC_WEAK_FUNC(sub_822AC490);
PPC_FUNC_IMPL(__imp__sub_822AC490) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x822AC498;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r22,1
	r22.s64 = 1;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// li r21,0
	r21.s64 = 0;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r28,48(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 48);
	// stb r22,691(r24)
	PPC_STORE_U8(r24.u32 + 691, r22.u8);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC4C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ac4e4
	if (cr6.eq) goto loc_822AC4E4;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r21,880(r24)
	r21.u64 = PPC_LOAD_U32(r24.u32 + 880);
	// bl 0x822a5578
	ctx.lr = 0x822AC4E0;
	sub_822A5578(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_822AC4E4:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82562740
	ctx.lr = 0x822AC4F0;
	sub_82562740(ctx, base);
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822ac50c
	if (cr6.eq) goto loc_822AC50C;
	// addi r11,r28,272
	r11.s64 = r28.s64 + 272;
	// b 0x822ac514
	goto loc_822AC514;
loc_822AC50C:
	// lwz r11,28(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822AC514:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r22
	r11.u64 = r22.u64;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822ac530
	if (!cr6.gt) goto loc_822AC530;
	// li r11,0
	r11.s64 = 0;
loc_822AC530:
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// clrlwi r31,r9,24
	r31.u64 = ctx.r9.u32 & 0xFF;
	// bl 0x82332098
	ctx.lr = 0x822AC544;
	sub_82332098(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822ac56c
	if (cr6.eq) goto loc_822AC56C;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// mr r11,r22
	r11.u64 = r22.u64;
	// rlwinm r9,r10,0,27,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1C;
	// rlwinm r9,r9,0,29,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822ac570
	if (!cr6.eq) goto loc_822AC570;
loc_822AC56C:
	// li r11,0
	r11.s64 = 0;
loc_822AC570:
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// clrlwi r25,r30,24
	r25.u64 = r30.u32 & 0xFF;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// clrlwi r23,r9,24
	r23.u64 = ctx.r9.u32 & 0xFF;
	// bne cr6,0x822ac59c
	if (!cr6.eq) goto loc_822AC59C;
	// lwz r3,20(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC59C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AC59C:
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// li r30,0
	r30.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// bne cr6,0x822ac5bc
	if (!cr6.eq) goto loc_822AC5BC;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822AC5BC:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,4120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822ac5d8
	if (!cr6.gt) goto loc_822AC5D8;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
	// b 0x822ac5dc
	goto loc_822AC5DC;
loc_822AC5D8:
	// fmr f10,f13
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f13.f64;
loc_822AC5DC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// bne cr6,0x822ac5ec
	if (!cr6.eq) goto loc_822AC5EC;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822AC5EC:
	// lfs f13,4116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822ac600
	if (!cr6.gt) goto loc_822AC600;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// b 0x822ac604
	goto loc_822AC604;
loc_822AC600:
	// fmr f11,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f13.f64;
loc_822AC604:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// bne cr6,0x822ac614
	if (!cr6.eq) goto loc_822AC614;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822AC614:
	// lfs f13,4124(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4124);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822ac628
	if (!cr6.gt) goto loc_822AC628;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// b 0x822ac62c
	goto loc_822AC62C;
loc_822AC628:
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
loc_822AC62C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822ac63c
	if (!cr6.eq) goto loc_822AC63C;
	// li r11,0
	r11.s64 = 0;
loc_822AC63C:
	// lfs f13,4112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822ac64c
	if (cr6.gt) goto loc_822AC64C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_822AC64C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,-28880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28880);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// ble cr6,0x822ac660
	if (!cr6.gt) goto loc_822AC660;
	// mr r30,r22
	r30.u64 = r22.u64;
loc_822AC660:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,32692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32692);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bgt cr6,0x822ac678
	if (cr6.gt) goto loc_822AC678;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822ac67c
	if (!cr6.gt) goto loc_822AC67C;
loc_822AC678:
	// mr r26,r22
	r26.u64 = r22.u64;
loc_822AC67C:
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x822ac688
	if (!cr6.gt) goto loc_822AC688;
	// mr r29,r22
	r29.u64 = r22.u64;
loc_822AC688:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822ac6a8
	if (cr6.eq) goto loc_822AC6A8;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC6A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822ac6bc
	goto loc_822AC6BC;
loc_822AC6A8:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ac6bc
	if (cr6.eq) goto loc_822AC6BC;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x8255f408
	ctx.lr = 0x822AC6BC;
	sub_8255F408(ctx, base);
loc_822AC6BC:
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822ac6d0
	if (!cr6.eq) goto loc_822AC6D0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AC6D0:
	// bl 0x82353b58
	ctx.lr = 0x822AC6D4;
	sub_82353B58(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822ac6e8
	if (cr6.eq) goto loc_822AC6E8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,92(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 92, temp.u32);
loc_822AC6E8:
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822ac704
	if (cr6.eq) goto loc_822AC704;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AC704:
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// lwz r31,132(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 132);
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// lis r6,20971
	ctx.r6.s64 = 1374355456;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// ori r9,r7,64167
	ctx.r9.u64 = ctx.r7.u64 | 64167;
	// ori r10,r6,34079
	ctx.r10.u64 = ctx.r6.u64 | 34079;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r11,r11,2176
	r11.s64 = r11.s64 + 2176;
	// beq cr6,0x822ac778
	if (cr6.eq) goto loc_822AC778;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r7,r6,r9
	ctx.r7.s64 = ctx.r6.s64 * ctx.r9.s64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// clrlwi r5,r8,1
	ctx.r5.u64 = ctx.r8.u32 & 0x7FFFFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// rldicl r6,r8,32,32
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// mulhw r3,r5,r10
	ctx.r3.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32)) >> 32;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// srawi r7,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 5;
	// rlwinm r8,r7,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mulli r3,r4,100
	ctx.r3.s64 = ctx.r4.s64 * 100;
	// subf r8,r3,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r3.s64;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,90
	cr6.compare<int32_t>(ctx.r8.s32, 90, xer);
	// ble cr6,0x822ac778
	if (!cr6.gt) goto loc_822AC778;
	// stb r22,1768(r31)
	PPC_STORE_U8(r31.u32 + 1768, r22.u8);
	// stb r22,1816(r31)
	PPC_STORE_U8(r31.u32 + 1816, r22.u8);
loc_822AC778:
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822ac7cc
	if (cr6.eq) goto loc_822AC7CC;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r7,r6,r9
	ctx.r7.s64 = ctx.r6.s64 * ctx.r9.s64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// clrlwi r5,r8,1
	ctx.r5.u64 = ctx.r8.u32 & 0x7FFFFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// rldicl r6,r8,32,32
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// mulhw r3,r5,r10
	ctx.r3.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32)) >> 32;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// srawi r7,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 5;
	// rlwinm r8,r7,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// add r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mulli r3,r4,100
	ctx.r3.s64 = ctx.r4.s64 * 100;
	// subf r8,r3,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r3.s64;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,90
	cr6.compare<int32_t>(ctx.r8.s32, 90, xer);
	// ble cr6,0x822ac7cc
	if (!cr6.gt) goto loc_822AC7CC;
	// stb r22,1864(r31)
	PPC_STORE_U8(r31.u32 + 1864, r22.u8);
loc_822AC7CC:
	// clrlwi r8,r26,24
	ctx.r8.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822ac828
	if (cr6.eq) goto loc_822AC828;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r9,r5,r9
	ctx.r9.s64 = ctx.r5.s64 * ctx.r9.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r4,r10,1
	ctx.r4.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// mulhw r3,r4,r7
	ctx.r3.s64 = (int64_t(ctx.r4.s32) * int64_t(ctx.r7.s32)) >> 32;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// srawi r9,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 5;
	// rlwinm r8,r9,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mulli r10,r11,100
	ctx.r10.s64 = r11.s64 * 100;
	// subf r11,r10,r4
	r11.s64 = ctx.r4.s64 - ctx.r10.s64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmpwi cr6,r9,90
	cr6.compare<int32_t>(ctx.r9.s32, 90, xer);
	// ble cr6,0x822ac828
	if (!cr6.gt) goto loc_822AC828;
	// stb r22,1912(r31)
	PPC_STORE_U8(r31.u32 + 1912, r22.u8);
	// stb r22,1720(r31)
	PPC_STORE_U8(r31.u32 + 1720, r22.u8);
loc_822AC828:
	// lwz r3,84(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// bl 0x8233e1b0
	ctx.lr = 0x822AC830;
	sub_8233E1B0(ctx, base);
	// clrlwi r29,r23,24
	r29.u64 = r23.u32 & 0xFF;
	// or r11,r25,r29
	r11.u64 = r25.u64 | r29.u64;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ac858
	if (cr6.eq) goto loc_822AC858;
	// li r30,10
	r30.s64 = 10;
loc_822AC848:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822a7e28
	ctx.lr = 0x822AC850;
	sub_822A7E28(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x822ac848
	if (!cr0.eq) goto loc_822AC848;
loc_822AC858:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x822ac89c
	if (cr6.eq) goto loc_822AC89C;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x822b34b0
	ctx.lr = 0x822AC868;
	sub_822B34B0(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822ac89c
	if (cr6.eq) goto loc_822AC89C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822AC888;
	sub_82207EF0(ctx, base);
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822AC89C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AC89C:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC8B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ac93c
	if (cr6.eq) goto loc_822AC93C;
	// bl 0x82387a18
	ctx.lr = 0x822AC8C0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ac93c
	if (cr6.eq) goto loc_822AC93C;
	// lbz r11,1720(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1720);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lbz r10,1912(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1912);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// lbz r11,1816(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1816);
	// lbz r9,1864(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1864);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// lbz r10,1768(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1768);
	// lwz r11,-10240(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// lbz r9,1672(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1672);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cntlzw r7,r7
	ctx.r7.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// cntlzw r5,r5
	ctx.r5.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// cntlzw r4,r4
	ctx.r4.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// cntlzw r11,r8
	r11.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r10,r9
	ctx.r10.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r9,r7,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r8,r6,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// rlwinm r7,r5,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// rlwinm r6,r4,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// rlwinm r5,r11,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x8227b920
	ctx.lr = 0x822AC93C;
	sub_8227B920(ctx, base);
loc_822AC93C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_822AC944"))) PPC_WEAK_FUNC(sub_822AC944);
PPC_FUNC_IMPL(__imp__sub_822AC944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AC948"))) PPC_WEAK_FUNC(sub_822AC948);
PPC_FUNC_IMPL(__imp__sub_822AC948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822AC950;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d4
	ctx.lr = 0x822AC958;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r11,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x822AC974;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822acea8
	if (!cr6.eq) goto loc_822ACEA8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r26,48
	r26.s64 = 48;
	// lfs f29,24924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24924);
	f29.f64 = double(temp.f32);
	// lfs f30,21600(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21600);
	f30.f64 = double(temp.f32);
	// lfs f28,24920(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24920);
	f28.f64 = double(temp.f32);
	// lfs f27,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f27.f64 = double(temp.f32);
loc_822AC9A4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822a7c28
	ctx.lr = 0x822AC9AC;
	sub_822A7C28(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AC9C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r3,-3
	r11.s64 = ctx.r3.s64 + -3;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x822ace88
	if (cr6.gt) goto loc_822ACE88;
	// lis r12,-32213
	r12.s64 = -2111111168;
	// addi r12,r12,-13844
	r12.s64 = r12.s64 + -13844;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822ACA10;
	case 1:
		goto loc_822ACB10;
	case 2:
		goto loc_822ACB10;
	case 3:
		goto loc_822ACBA4;
	case 4:
		goto loc_822ACE88;
	case 5:
		goto loc_822ACC38;
	case 6:
		goto loc_822ACB10;
	case 7:
		goto loc_822ACB10;
	case 8:
		goto loc_822ACB10;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-13808(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13808);
	// lwz r17,-13552(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13552);
	// lwz r17,-13552(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13552);
	// lwz r17,-13404(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13404);
	// lwz r17,-12664(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12664);
	// lwz r17,-13256(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13256);
	// lwz r17,-13552(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13552);
	// lwz r17,-13552(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13552);
	// lwz r17,-13552(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13552);
loc_822ACA10:
	// lwz r11,80(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// mr r31,r28
	r31.u64 = r28.u64;
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r11,84(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// addic. r10,r11,256
	xer.ca = r11.u32 > 4294967039;
	ctx.r10.s64 = r11.s64 + 256;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x822ace88
	if (cr0.eq) goto loc_822ACE88;
	// lfs f0,420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 420);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bne cr6,0x822ace88
	if (!cr6.eq) goto loc_822ACE88;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82489da8
	ctx.lr = 0x822ACA4C;
	sub_82489DA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aca7c
	if (cr6.eq) goto loc_822ACA7C;
loc_822ACA54:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82489da8
	ctx.lr = 0x822ACA5C;
	sub_82489DA8(ctx, base);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// beq cr6,0x822aca7c
	if (cr6.eq) goto loc_822ACA7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82489da8
	ctx.lr = 0x822ACA6C;
	sub_82489DA8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82489da8
	ctx.lr = 0x822ACA74;
	sub_82489DA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822aca54
	if (!cr6.eq) goto loc_822ACA54;
loc_822ACA7C:
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r27,492
	r11.s64 = r27.s64 + 492;
loc_822ACAA8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822acabc
	if (cr6.eq) goto loc_822ACABC;
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// beq cr6,0x822acb08
	if (cr6.eq) goto loc_822ACB08;
loc_822ACABC:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// blt cr6,0x822acaa8
	if (cr6.lt) goto loc_822ACAA8;
	// li r11,0
	r11.s64 = 0;
loc_822ACAD0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ace88
	if (!cr6.eq) goto loc_822ACE88;
	// lwz r11,484(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 484);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,48(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lfs f1,224(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822ab028
	ctx.lr = 0x822ACB04;
	sub_822AB028(ctx, base);
	// b 0x822ace88
	goto loc_822ACE88;
loc_822ACB08:
	// li r11,1
	r11.s64 = 1;
	// b 0x822acad0
	goto loc_822ACAD0;
loc_822ACB10:
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r27,492
	r11.s64 = r27.s64 + 492;
loc_822ACB3C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822acb50
	if (cr6.eq) goto loc_822ACB50;
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// beq cr6,0x822acb9c
	if (cr6.eq) goto loc_822ACB9C;
loc_822ACB50:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// blt cr6,0x822acb3c
	if (cr6.lt) goto loc_822ACB3C;
	// li r11,0
	r11.s64 = 0;
loc_822ACB64:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ace88
	if (!cr6.eq) goto loc_822ACE88;
	// lwz r11,484(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 484);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,48(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lfs f1,224(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822ab028
	ctx.lr = 0x822ACB98;
	sub_822AB028(ctx, base);
	// b 0x822ace88
	goto loc_822ACE88;
loc_822ACB9C:
	// li r11,1
	r11.s64 = 1;
	// b 0x822acb64
	goto loc_822ACB64;
loc_822ACBA4:
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r27,492
	r11.s64 = r27.s64 + 492;
loc_822ACBD0:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822acbe4
	if (cr6.eq) goto loc_822ACBE4;
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// beq cr6,0x822acc30
	if (cr6.eq) goto loc_822ACC30;
loc_822ACBE4:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// blt cr6,0x822acbd0
	if (cr6.lt) goto loc_822ACBD0;
	// li r11,0
	r11.s64 = 0;
loc_822ACBF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ace88
	if (!cr6.eq) goto loc_822ACE88;
	// lfs f1,224(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f28
	cr6.compare(ctx.f1.f64, f28.f64);
	// ble cr6,0x822ace88
	if (!cr6.gt) goto loc_822ACE88;
	// lwz r11,484(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 484);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bl 0x822ab028
	ctx.lr = 0x822ACC2C;
	sub_822AB028(ctx, base);
	// b 0x822ace88
	goto loc_822ACE88;
loc_822ACC30:
	// li r11,1
	r11.s64 = 1;
	// b 0x822acbf8
	goto loc_822ACBF8;
loc_822ACC38:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r27,492
	r11.s64 = r27.s64 + 492;
loc_822ACC40:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822acc54
	if (cr6.eq) goto loc_822ACC54;
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// beq cr6,0x822acce8
	if (cr6.eq) goto loc_822ACCE8;
loc_822ACC54:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// blt cr6,0x822acc40
	if (cr6.lt) goto loc_822ACC40;
	// li r11,0
	r11.s64 = 0;
loc_822ACC68:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ace88
	if (!cr6.eq) goto loc_822ACE88;
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r5,28(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r11,80(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lwz r30,128(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822ace88
	if (cr6.eq) goto loc_822ACE88;
	// lfs f13,224(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,224(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bgt cr6,0x822accd4
	if (cr6.gt) goto loc_822ACCD4;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x822ace88
	if (!cr6.gt) goto loc_822ACE88;
loc_822ACCD4:
	// li r11,0
	r11.s64 = 0;
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x822accf0
	if (!cr6.lt) goto loc_822ACCF0;
	// li r11,1
	r11.s64 = 1;
	// b 0x822acdc8
	goto loc_822ACDC8;
loc_822ACCE8:
	// li r11,1
	r11.s64 = 1;
	// b 0x822acc68
	goto loc_822ACC68;
loc_822ACCF0:
	// fcmpu cr6,f13,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f29.f64);
	// ble cr6,0x822acdc8
	if (!cr6.gt) goto loc_822ACDC8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822a8108
	ctx.lr = 0x822ACD00;
	sub_822A8108(ctx, base);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lvx128 v63,r3,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822acd38
	if (cr6.eq) goto loc_822ACD38;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822acd2c
	if (cr6.eq) goto loc_822ACD2C;
	// addi r9,r11,272
	ctx.r9.s64 = r11.s64 + 272;
	// b 0x822acd3c
	goto loc_822ACD3C;
loc_822ACD2C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// b 0x822acd3c
	goto loc_822ACD3C;
loc_822ACD38:
	// addi r9,r30,288
	ctx.r9.s64 = r30.s64 + 288;
loc_822ACD3C:
	// lvx128 v62,r9,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,128(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 128);
	// lwz r10,128(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 128);
	// lfs f12,276(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 276);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,280(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 280);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,276(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,272(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f8.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f7,272(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	ctx.f7.f64 = double(temp.f32);
	// vsubfp128 v60,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f5.f64 = double(temp.f32);
	// lfs f6,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f6.f64 = double(temp.f32);
	// lfs f1,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f12,f12,f1
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f1.f64));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f10,f10,f5,f12
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f5.f64 + ctx.f12.f64));
	// lfs f3,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f5,f11,f4
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f4.f64));
	// fmadds f3,f9,f3,f5
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f3.f64 + ctx.f5.f64));
	// fmadds f4,f8,f6,f10
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f6.f64 + ctx.f10.f64));
	// fmadds f12,f7,f2,f3
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f2.f64 + ctx.f3.f64));
	// fdivs f1,f4,f13
	ctx.f1.f64 = double(float(ctx.f4.f64 / ctx.f13.f64));
	// fdivs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 / f0.f64));
	// fcmpu cr6,f1,f11
	cr6.compare(ctx.f1.f64, ctx.f11.f64);
	// bgt cr6,0x822acdc4
	if (cr6.gt) goto loc_822ACDC4;
	// li r11,0
	r11.s64 = 0;
loc_822ACDC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_822ACDC8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822acde4
	if (cr6.eq) goto loc_822ACDE4;
	// mr r31,r27
	r31.u64 = r27.u64;
	// fmr f31,f13
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f13.f64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// b 0x822acdf8
	goto loc_822ACDF8;
loc_822ACDE4:
	// mr r31,r30
	r31.u64 = r30.u64;
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// mr r29,r28
	r29.u64 = r28.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
loc_822ACDF8:
	// lbz r11,465(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 465);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ace14
	if (cr6.eq) goto loc_822ACE14;
	// lwz r11,484(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 484);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,2
	ctx.r9.u64 = ctx.r10.u64 | 2;
	// b 0x822ace44
	goto loc_822ACE44;
loc_822ACE14:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822ACE28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,484(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 484);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,4
	ctx.r9.u64 = ctx.r10.u64 | 4;
	// bne cr6,0x822ace44
	if (!cr6.eq) goto loc_822ACE44;
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
loc_822ACE44:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,160(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822ACE68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,160(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822ACE88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822ACE88:
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x822ACE9C;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ac9a4
	if (cr6.eq) goto loc_822AC9A4;
loc_822ACEA8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba20
	ctx.lr = 0x822ACEB4;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822ACEB8"))) PPC_WEAK_FUNC(sub_822ACEB8);
PPC_FUNC_IMPL(__imp__sub_822ACEB8) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x822ab028
	sub_822AB028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ACEC0"))) PPC_WEAK_FUNC(sub_822ACEC0);
PPC_FUNC_IMPL(__imp__sub_822ACEC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,17892
	r11.s64 = r11.s64 + 17892;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x822acef0
	if (cr6.eq) goto loc_822ACEF0;
	// lwz r10,804(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x822acef4
	goto loc_822ACEF4;
loc_822ACEF0:
	// lwz r10,400(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_822ACEF4:
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x822acf0c
	if (cr6.lt) goto loc_822ACF0C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822ACF0C:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822acf2c
	if (cr6.eq) goto loc_822ACF2C;
	// addi r10,r9,101
	ctx.r10.s64 = ctx.r9.s64 + 101;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// blr 
	return;
loc_822ACF2C:
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ACF40"))) PPC_WEAK_FUNC(sub_822ACF40);
PPC_FUNC_IMPL(__imp__sub_822ACF40) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x822b6238
	ctx.lr = 0x822ACF68;
	sub_822B6238(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822ACF84"))) PPC_WEAK_FUNC(sub_822ACF84);
PPC_FUNC_IMPL(__imp__sub_822ACF84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ACF88"))) PPC_WEAK_FUNC(sub_822ACF88);
PPC_FUNC_IMPL(__imp__sub_822ACF88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,140(r10)
	PPC_STORE_U32(ctx.r10.u32 + 140, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ACF9C"))) PPC_WEAK_FUNC(sub_822ACF9C);
PPC_FUNC_IMPL(__imp__sub_822ACF9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ACFA0"))) PPC_WEAK_FUNC(sub_822ACFA0);
PPC_FUNC_IMPL(__imp__sub_822ACFA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822acfc0
	if (cr6.eq) goto loc_822ACFC0;
	// lwz r11,140(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822ACFC0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ACFCC"))) PPC_WEAK_FUNC(sub_822ACFCC);
PPC_FUNC_IMPL(__imp__sub_822ACFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ACFD0"))) PPC_WEAK_FUNC(sub_822ACFD0);
PPC_FUNC_IMPL(__imp__sub_822ACFD0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ad020
	if (cr6.eq) goto loc_822AD020;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AD004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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
loc_822AD020:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
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
}

__attribute__((alias("__imp__sub_822AD040"))) PPC_WEAK_FUNC(sub_822AD040);
PPC_FUNC_IMPL(__imp__sub_822AD040) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
	// bne cr6,0x822ad05c
	if (!cr6.eq) goto loc_822AD05C;
	// li r11,0
	r11.s64 = 0;
loc_822AD05C:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD064"))) PPC_WEAK_FUNC(sub_822AD064);
PPC_FUNC_IMPL(__imp__sub_822AD064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD068"))) PPC_WEAK_FUNC(sub_822AD068);
PPC_FUNC_IMPL(__imp__sub_822AD068) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,176(r11)
	PPC_STORE_U8(r11.u32 + 176, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD090"))) PPC_WEAK_FUNC(sub_822AD090);
PPC_FUNC_IMPL(__imp__sub_822AD090) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,26(r11)
	PPC_STORE_U8(r11.u32 + 26, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD0B8"))) PPC_WEAK_FUNC(sub_822AD0B8);
PPC_FUNC_IMPL(__imp__sub_822AD0B8) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ad0e4
	if (cr6.eq) goto loc_822AD0E4;
	// bl 0x822a7cc8
	ctx.lr = 0x822AD0E0;
	sub_822A7CC8(ctx, base);
	// b 0x822ad0e8
	goto loc_822AD0E8;
loc_822AD0E4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AD0E8:
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

__attribute__((alias("__imp__sub_822AD108"))) PPC_WEAK_FUNC(sub_822AD108);
PPC_FUNC_IMPL(__imp__sub_822AD108) {
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
	// bl 0x822a8710
	ctx.lr = 0x822AD128;
	sub_822A8710(ctx, base);
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

__attribute__((alias("__imp__sub_822AD148"))) PPC_WEAK_FUNC(sub_822AD148);
PPC_FUNC_IMPL(__imp__sub_822AD148) {
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
	// beq cr6,0x822ad190
	if (cr6.eq) goto loc_822AD190;
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822ad190
	if (cr6.eq) goto loc_822AD190;
	// bl 0x8238f998
	ctx.lr = 0x822AD17C;
	sub_8238F998(ctx, base);
	// bl 0x823964a8
	ctx.lr = 0x822AD180;
	sub_823964A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822ad194
	if (!cr6.eq) goto loc_822AD194;
loc_822AD190:
	// li r11,0
	r11.s64 = 0;
loc_822AD194:
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

__attribute__((alias("__imp__sub_822AD1B4"))) PPC_WEAK_FUNC(sub_822AD1B4);
PPC_FUNC_IMPL(__imp__sub_822AD1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD1B8"))) PPC_WEAK_FUNC(sub_822AD1B8);
PPC_FUNC_IMPL(__imp__sub_822AD1B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822a87a8
	sub_822A87A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AD1C4"))) PPC_WEAK_FUNC(sub_822AD1C4);
PPC_FUNC_IMPL(__imp__sub_822AD1C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD1C8"))) PPC_WEAK_FUNC(sub_822AD1C8);
PPC_FUNC_IMPL(__imp__sub_822AD1C8) {
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
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822AD1E8"))) PPC_WEAK_FUNC(sub_822AD1E8);
PPC_FUNC_IMPL(__imp__sub_822AD1E8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD1EC"))) PPC_WEAK_FUNC(sub_822AD1EC);
PPC_FUNC_IMPL(__imp__sub_822AD1EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD1F0"))) PPC_WEAK_FUNC(sub_822AD1F0);
PPC_FUNC_IMPL(__imp__sub_822AD1F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822ab1d8
	sub_822AB1D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AD1FC"))) PPC_WEAK_FUNC(sub_822AD1FC);
PPC_FUNC_IMPL(__imp__sub_822AD1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD200"))) PPC_WEAK_FUNC(sub_822AD200);
PPC_FUNC_IMPL(__imp__sub_822AD200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822ab258
	sub_822AB258(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AD20C"))) PPC_WEAK_FUNC(sub_822AD20C);
PPC_FUNC_IMPL(__imp__sub_822AD20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD210"))) PPC_WEAK_FUNC(sub_822AD210);
PPC_FUNC_IMPL(__imp__sub_822AD210) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x822a8360
	sub_822A8360(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AD228"))) PPC_WEAK_FUNC(sub_822AD228);
PPC_FUNC_IMPL(__imp__sub_822AD228) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD22C"))) PPC_WEAK_FUNC(sub_822AD22C);
PPC_FUNC_IMPL(__imp__sub_822AD22C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD230"))) PPC_WEAK_FUNC(sub_822AD230);
PPC_FUNC_IMPL(__imp__sub_822AD230) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r4,r10,2272
	ctx.r4.s64 = ctx.r10.s64 + 2272;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// b 0x8255a1b0
	sub_8255A1B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AD260"))) PPC_WEAK_FUNC(sub_822AD260);
PPC_FUNC_IMPL(__imp__sub_822AD260) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD264"))) PPC_WEAK_FUNC(sub_822AD264);
PPC_FUNC_IMPL(__imp__sub_822AD264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD268"))) PPC_WEAK_FUNC(sub_822AD268);
PPC_FUNC_IMPL(__imp__sub_822AD268) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ad2b8
	if (cr6.eq) goto loc_822AD2B8;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ad2b0
	if (cr6.eq) goto loc_822AD2B0;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822ad2b0
	if (cr6.eq) goto loc_822AD2B0;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8232c788
	ctx.lr = 0x822AD2A8;
	sub_8232C788(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// b 0x822ad2b4
	goto loc_822AD2B4;
loc_822AD2B0:
	// li r11,2
	r11.s64 = 2;
loc_822AD2B4:
	// stw r11,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r11.u32);
loc_822AD2B8:
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

__attribute__((alias("__imp__sub_822AD2CC"))) PPC_WEAK_FUNC(sub_822AD2CC);
PPC_FUNC_IMPL(__imp__sub_822AD2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD2D0"))) PPC_WEAK_FUNC(sub_822AD2D0);
PPC_FUNC_IMPL(__imp__sub_822AD2D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad340
	if (cr6.eq) goto loc_822AD340;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ad31c
	if (cr6.eq) goto loc_822AD31C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ad31c
	if (cr6.eq) goto loc_822AD31C;
	// lwz r11,592(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// rlwinm r11,r11,0,28,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822AD31C:
	// li r11,0
	r11.s64 = 0;
	// rlwinm r11,r11,0,30,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// rlwinm r11,r11,0,28,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822AD340:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD354"))) PPC_WEAK_FUNC(sub_822AD354);
PPC_FUNC_IMPL(__imp__sub_822AD354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD358"))) PPC_WEAK_FUNC(sub_822AD358);
PPC_FUNC_IMPL(__imp__sub_822AD358) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad3a0
	if (cr6.eq) goto loc_822AD3A0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ad38c
	if (cr6.eq) goto loc_822AD38C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ad38c
	if (cr6.eq) goto loc_822AD38C;
	// lwz r11,592(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822ad3a0
	if (!cr6.eq) goto loc_822AD3A0;
loc_822AD38C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822AD3A0:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD3B4"))) PPC_WEAK_FUNC(sub_822AD3B4);
PPC_FUNC_IMPL(__imp__sub_822AD3B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD3B8"))) PPC_WEAK_FUNC(sub_822AD3B8);
PPC_FUNC_IMPL(__imp__sub_822AD3B8) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ad3f0
	if (cr6.eq) goto loc_822AD3F0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AD3EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822ad3f4
	goto loc_822AD3F4;
loc_822AD3F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AD3F4:
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

__attribute__((alias("__imp__sub_822AD414"))) PPC_WEAK_FUNC(sub_822AD414);
PPC_FUNC_IMPL(__imp__sub_822AD414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD418"))) PPC_WEAK_FUNC(sub_822AD418);
PPC_FUNC_IMPL(__imp__sub_822AD418) {
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
	// bl 0x822a88f8
	ctx.lr = 0x822AD438;
	sub_822A88F8(ctx, base);
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

__attribute__((alias("__imp__sub_822AD458"))) PPC_WEAK_FUNC(sub_822AD458);
PPC_FUNC_IMPL(__imp__sub_822AD458) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad4a4
	if (cr6.eq) goto loc_822AD4A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad4a4
	if (cr6.eq) goto loc_822AD4A4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r10,578(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 578);
	// li r11,1
	r11.s64 = 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt cr6,0x822ad490
	if (cr6.gt) goto loc_822AD490;
	// li r11,0
	r11.s64 = 0;
loc_822AD490:
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
loc_822AD4A4:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD4B8"))) PPC_WEAK_FUNC(sub_822AD4B8);
PPC_FUNC_IMPL(__imp__sub_822AD4B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad508
	if (cr6.eq) goto loc_822AD508;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad508
	if (cr6.eq) goto loc_822AD508;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822ad4f4
	if (cr6.gt) goto loc_822AD4F4;
	// li r11,0
	r11.s64 = 0;
loc_822AD4F4:
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
loc_822AD508:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD51C"))) PPC_WEAK_FUNC(sub_822AD51C);
PPC_FUNC_IMPL(__imp__sub_822AD51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD520"))) PPC_WEAK_FUNC(sub_822AD520);
PPC_FUNC_IMPL(__imp__sub_822AD520) {
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
	// bl 0x822a8988
	ctx.lr = 0x822AD540;
	sub_822A8988(ctx, base);
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

__attribute__((alias("__imp__sub_822AD55C"))) PPC_WEAK_FUNC(sub_822AD55C);
PPC_FUNC_IMPL(__imp__sub_822AD55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD560"))) PPC_WEAK_FUNC(sub_822AD560);
PPC_FUNC_IMPL(__imp__sub_822AD560) {
	PPC_FUNC_PROLOGUE();
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
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// bl 0x822a8b50
	ctx.lr = 0x822AD580;
	sub_822A8B50(ctx, base);
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stfs f1,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD598"))) PPC_WEAK_FUNC(sub_822AD598);
PPC_FUNC_IMPL(__imp__sub_822AD598) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822a8c20
	ctx.lr = 0x822AD5BC;
	sub_822A8C20(ctx, base);
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

__attribute__((alias("__imp__sub_822AD5D8"))) PPC_WEAK_FUNC(sub_822AD5D8);
PPC_FUNC_IMPL(__imp__sub_822AD5D8) {
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
	// bl 0x822ab318
	ctx.lr = 0x822AD600;
	sub_822AB318(ctx, base);
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

__attribute__((alias("__imp__sub_822AD620"))) PPC_WEAK_FUNC(sub_822AD620);
PPC_FUNC_IMPL(__imp__sub_822AD620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,88(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822AD63C"))) PPC_WEAK_FUNC(sub_822AD63C);
PPC_FUNC_IMPL(__imp__sub_822AD63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD640"))) PPC_WEAK_FUNC(sub_822AD640);
PPC_FUNC_IMPL(__imp__sub_822AD640) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ad69c
	if (cr6.eq) goto loc_822AD69C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AD674;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ad69c
	if (cr6.eq) goto loc_822AD69C;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822ad69c
	if (cr6.eq) goto loc_822AD69C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822AD69C;
	sub_822B0F10(ctx, base);
loc_822AD69C:
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

__attribute__((alias("__imp__sub_822AD6B0"))) PPC_WEAK_FUNC(sub_822AD6B0);
PPC_FUNC_IMPL(__imp__sub_822AD6B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,624(r11)
	PPC_STORE_U32(r11.u32 + 624, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD6DC"))) PPC_WEAK_FUNC(sub_822AD6DC);
PPC_FUNC_IMPL(__imp__sub_822AD6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD6E0"))) PPC_WEAK_FUNC(sub_822AD6E0);
PPC_FUNC_IMPL(__imp__sub_822AD6E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,660(r11)
	PPC_STORE_U32(r11.u32 + 660, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD6FC"))) PPC_WEAK_FUNC(sub_822AD6FC);
PPC_FUNC_IMPL(__imp__sub_822AD6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD700"))) PPC_WEAK_FUNC(sub_822AD700);
PPC_FUNC_IMPL(__imp__sub_822AD700) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,660(r11)
	PPC_STORE_U32(r11.u32 + 660, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD71C"))) PPC_WEAK_FUNC(sub_822AD71C);
PPC_FUNC_IMPL(__imp__sub_822AD71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD720"))) PPC_WEAK_FUNC(sub_822AD720);
PPC_FUNC_IMPL(__imp__sub_822AD720) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,660(r11)
	PPC_STORE_U32(r11.u32 + 660, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD73C"))) PPC_WEAK_FUNC(sub_822AD73C);
PPC_FUNC_IMPL(__imp__sub_822AD73C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD740"))) PPC_WEAK_FUNC(sub_822AD740);
PPC_FUNC_IMPL(__imp__sub_822AD740) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,660(r10)
	PPC_STORE_U32(ctx.r10.u32 + 660, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD75C"))) PPC_WEAK_FUNC(sub_822AD75C);
PPC_FUNC_IMPL(__imp__sub_822AD75C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD760"))) PPC_WEAK_FUNC(sub_822AD760);
PPC_FUNC_IMPL(__imp__sub_822AD760) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad780
	if (cr6.eq) goto loc_822AD780;
	// lwz r11,660(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 660);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822AD780:
	// li r11,2
	r11.s64 = 2;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD78C"))) PPC_WEAK_FUNC(sub_822AD78C);
PPC_FUNC_IMPL(__imp__sub_822AD78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD790"))) PPC_WEAK_FUNC(sub_822AD790);
PPC_FUNC_IMPL(__imp__sub_822AD790) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad7b0
	if (cr6.eq) goto loc_822AD7B0;
	// lwz r11,656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822AD7B0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD7BC"))) PPC_WEAK_FUNC(sub_822AD7BC);
PPC_FUNC_IMPL(__imp__sub_822AD7BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD7C0"))) PPC_WEAK_FUNC(sub_822AD7C0);
PPC_FUNC_IMPL(__imp__sub_822AD7C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad7f0
	if (cr6.eq) goto loc_822AD7F0;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822AD7F0:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD804"))) PPC_WEAK_FUNC(sub_822AD804);
PPC_FUNC_IMPL(__imp__sub_822AD804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD808"))) PPC_WEAK_FUNC(sub_822AD808);
PPC_FUNC_IMPL(__imp__sub_822AD808) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// extsb r4,r9
	ctx.r4.s64 = ctx.r9.s8;
	// addi r3,r11,20
	ctx.r3.s64 = r11.s64 + 20;
	// b 0x82398380
	sub_82398380(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AD82C"))) PPC_WEAK_FUNC(sub_822AD82C);
PPC_FUNC_IMPL(__imp__sub_822AD82C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD830"))) PPC_WEAK_FUNC(sub_822AD830);
PPC_FUNC_IMPL(__imp__sub_822AD830) {
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
	// beq cr6,0x822ad87c
	if (cr6.eq) goto loc_822AD87C;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r9,60(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 60);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
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
loc_822AD87C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,24928
	ctx.r3.s64 = r11.s64 + 24928;
	// bl 0x82130000
	ctx.lr = 0x822AD888;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
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
}

__attribute__((alias("__imp__sub_822AD8A8"))) PPC_WEAK_FUNC(sub_822AD8A8);
PPC_FUNC_IMPL(__imp__sub_822AD8A8) {
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
	// beq cr6,0x822ad8f4
	if (cr6.eq) goto loc_822AD8F4;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r9,59(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 59);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
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
loc_822AD8F4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,24992
	ctx.r3.s64 = r11.s64 + 24992;
	// bl 0x82130000
	ctx.lr = 0x822AD900;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
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
}

__attribute__((alias("__imp__sub_822AD920"))) PPC_WEAK_FUNC(sub_822AD920);
PPC_FUNC_IMPL(__imp__sub_822AD920) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad968
	if (cr6.eq) goto loc_822AD968;
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x822AD94C;
	sub_8238EFE8(ctx, base);
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
loc_822AD968:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25064
	ctx.r3.s64 = r11.s64 + 25064;
	// bl 0x82130000
	ctx.lr = 0x822AD974;
	sub_82130000(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_822AD998"))) PPC_WEAK_FUNC(sub_822AD998);
PPC_FUNC_IMPL(__imp__sub_822AD998) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad9c4
	if (cr6.eq) goto loc_822AD9C4;
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ad9c4
	if (cr6.eq) goto loc_822AD9C4;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822AD9C4:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AD9D4"))) PPC_WEAK_FUNC(sub_822AD9D4);
PPC_FUNC_IMPL(__imp__sub_822AD9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AD9D8"))) PPC_WEAK_FUNC(sub_822AD9D8);
PPC_FUNC_IMPL(__imp__sub_822AD9D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822aae48
	sub_822AAE48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AD9E8"))) PPC_WEAK_FUNC(sub_822AD9E8);
PPC_FUNC_IMPL(__imp__sub_822AD9E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ada08
	if (cr6.eq) goto loc_822ADA08;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822ADA08:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ADA14"))) PPC_WEAK_FUNC(sub_822ADA14);
PPC_FUNC_IMPL(__imp__sub_822ADA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ADA18"))) PPC_WEAK_FUNC(sub_822ADA18);
PPC_FUNC_IMPL(__imp__sub_822ADA18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ADA30"))) PPC_WEAK_FUNC(sub_822ADA30);
PPC_FUNC_IMPL(__imp__sub_822ADA30) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822ADA5C;
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

__attribute__((alias("__imp__sub_822ADA78"))) PPC_WEAK_FUNC(sub_822ADA78);
PPC_FUNC_IMPL(__imp__sub_822ADA78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// lhz r10,14(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// lhz r8,18(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// sth r10,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r10.u16);
	// lwz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lbz r8,1943(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1943);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,23868
	ctx.r3.s64 = r11.s64 + 23868;
	// b 0x821e6800
	sub_821E6800(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ADACC"))) PPC_WEAK_FUNC(sub_822ADACC);
PPC_FUNC_IMPL(__imp__sub_822ADACC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ADAD0"))) PPC_WEAK_FUNC(sub_822ADAD0);
PPC_FUNC_IMPL(__imp__sub_822ADAD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stb r9,689(r11)
	PPC_STORE_U8(r11.u32 + 689, ctx.r9.u8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822adb30
	if (!cr6.eq) goto loc_822ADB30;
	// li r11,0
	r11.s64 = 0;
loc_822ADB30:
	// stb r9,597(r11)
	PPC_STORE_U8(r11.u32 + 597, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ADB38"))) PPC_WEAK_FUNC(sub_822ADB38);
PPC_FUNC_IMPL(__imp__sub_822ADB38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stb r9,690(r11)
	PPC_STORE_U8(r11.u32 + 690, ctx.r9.u8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822adb98
	if (!cr6.eq) goto loc_822ADB98;
	// li r11,0
	r11.s64 = 0;
loc_822ADB98:
	// stb r9,598(r11)
	PPC_STORE_U8(r11.u32 + 598, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ADBA0"))) PPC_WEAK_FUNC(sub_822ADBA0);
PPC_FUNC_IMPL(__imp__sub_822ADBA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adbd0
	if (cr6.eq) goto loc_822ADBD0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adbd0
	if (cr6.eq) goto loc_822ADBD0;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// blr 
	return;
loc_822ADBD0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ADBE4"))) PPC_WEAK_FUNC(sub_822ADBE4);
PPC_FUNC_IMPL(__imp__sub_822ADBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ADBE8"))) PPC_WEAK_FUNC(sub_822ADBE8);
PPC_FUNC_IMPL(__imp__sub_822ADBE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adc1c
	if (cr6.eq) goto loc_822ADC1C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adc1c
	if (cr6.eq) goto loc_822ADC1C;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,24(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// blr 
	return;
loc_822ADC1C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ADC30"))) PPC_WEAK_FUNC(sub_822ADC30);
PPC_FUNC_IMPL(__imp__sub_822ADC30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adc7c
	if (cr6.eq) goto loc_822ADC7C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adc70
	if (cr6.eq) goto loc_822ADC70;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822adc64
	if (cr6.eq) goto loc_822ADC64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// b 0x82342780
	sub_82342780(ctx, base);
	return;
loc_822ADC64:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25296
	ctx.r3.s64 = r11.s64 + 25296;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822ADC70:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25216
	ctx.r3.s64 = r11.s64 + 25216;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822ADC7C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25136
	ctx.r3.s64 = r11.s64 + 25136;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ADC88"))) PPC_WEAK_FUNC(sub_822ADC88);
PPC_FUNC_IMPL(__imp__sub_822ADC88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adcd4
	if (cr6.eq) goto loc_822ADCD4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adcc8
	if (cr6.eq) goto loc_822ADCC8;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adcbc
	if (cr6.eq) goto loc_822ADCBC;
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,24(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// blr 
	return;
loc_822ADCBC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25296
	ctx.r3.s64 = r11.s64 + 25296;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822ADCC8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25216
	ctx.r3.s64 = r11.s64 + 25216;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822ADCD4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25136
	ctx.r3.s64 = r11.s64 + 25136;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ADCE0"))) PPC_WEAK_FUNC(sub_822ADCE0);
PPC_FUNC_IMPL(__imp__sub_822ADCE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822add2c
	if (cr6.eq) goto loc_822ADD2C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822add20
	if (cr6.eq) goto loc_822ADD20;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822add14
	if (cr6.eq) goto loc_822ADD14;
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// blr 
	return;
loc_822ADD14:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25536
	ctx.r3.s64 = r11.s64 + 25536;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822ADD20:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25456
	ctx.r3.s64 = r11.s64 + 25456;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822ADD2C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25376
	ctx.r3.s64 = r11.s64 + 25376;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ADD38"))) PPC_WEAK_FUNC(sub_822ADD38);
PPC_FUNC_IMPL(__imp__sub_822ADD38) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822add88
	if (cr6.eq) goto loc_822ADD88;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822add88
	if (cr6.eq) goto loc_822ADD88;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822add94
	if (cr6.lt) goto loc_822ADD94;
	// li r11,1
	r11.s64 = 1;
	// b 0x822add98
	goto loc_822ADD98;
loc_822ADD88:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25616
	ctx.r3.s64 = r11.s64 + 25616;
	// bl 0x82130000
	ctx.lr = 0x822ADD94;
	sub_82130000(ctx, base);
loc_822ADD94:
	// li r11,0
	r11.s64 = 0;
loc_822ADD98:
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

__attribute__((alias("__imp__sub_822ADDB8"))) PPC_WEAK_FUNC(sub_822ADDB8);
PPC_FUNC_IMPL(__imp__sub_822ADDB8) {
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
	// b 0x822a8ac8
	sub_822A8AC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ADDC8"))) PPC_WEAK_FUNC(sub_822ADDC8);
PPC_FUNC_IMPL(__imp__sub_822ADDC8) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ade18
	if (cr6.eq) goto loc_822ADE18;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ade18
	if (cr6.eq) goto loc_822ADE18;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822ade24
	if (cr6.gt) goto loc_822ADE24;
	// li r11,1
	r11.s64 = 1;
	// b 0x822ade28
	goto loc_822ADE28;
loc_822ADE18:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25688
	ctx.r3.s64 = r11.s64 + 25688;
	// bl 0x82130000
	ctx.lr = 0x822ADE24;
	sub_82130000(ctx, base);
loc_822ADE24:
	// li r11,0
	r11.s64 = 0;
loc_822ADE28:
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

__attribute__((alias("__imp__sub_822ADE48"))) PPC_WEAK_FUNC(sub_822ADE48);
PPC_FUNC_IMPL(__imp__sub_822ADE48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beq cr6,0x822ade80
	if (cr6.eq) goto loc_822ADE80;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ade80
	if (cr6.eq) goto loc_822ADE80;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stb r10,33(r11)
	PPC_STORE_U8(r11.u32 + 33, ctx.r10.u8);
	// blr 
	return;
loc_822ADE80:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25760
	ctx.r3.s64 = r11.s64 + 25760;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ADE8C"))) PPC_WEAK_FUNC(sub_822ADE8C);
PPC_FUNC_IMPL(__imp__sub_822ADE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ADE90"))) PPC_WEAK_FUNC(sub_822ADE90);
PPC_FUNC_IMPL(__imp__sub_822ADE90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,656(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 656, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ADEBC"))) PPC_WEAK_FUNC(sub_822ADEBC);
PPC_FUNC_IMPL(__imp__sub_822ADEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ADEC0"))) PPC_WEAK_FUNC(sub_822ADEC0);
PPC_FUNC_IMPL(__imp__sub_822ADEC0) {
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
	// bl 0x822aaf00
	ctx.lr = 0x822ADEE0;
	sub_822AAF00(ctx, base);
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

__attribute__((alias("__imp__sub_822ADEFC"))) PPC_WEAK_FUNC(sub_822ADEFC);
PPC_FUNC_IMPL(__imp__sub_822ADEFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ADF00"))) PPC_WEAK_FUNC(sub_822ADF00);
PPC_FUNC_IMPL(__imp__sub_822ADF00) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adf60
	if (cr6.eq) goto loc_822ADF60;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adf60
	if (cr6.eq) goto loc_822ADF60;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,668(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adf60
	if (cr6.eq) goto loc_822ADF60;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
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
loc_822ADF60:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25832
	ctx.r3.s64 = r11.s64 + 25832;
	// bl 0x82130000
	ctx.lr = 0x822ADF6C;
	sub_82130000(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_822ADF90"))) PPC_WEAK_FUNC(sub_822ADF90);
PPC_FUNC_IMPL(__imp__sub_822ADF90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r9,r7,1
	ctx.r9.u64 = ctx.r7.u64 ^ 1;
	// beq cr6,0x822adfec
	if (cr6.eq) goto loc_822ADFEC;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822adfec
	if (cr6.eq) goto loc_822ADFEC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lhz r9,576(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 576);
	// beq cr6,0x822adfe0
	if (cr6.eq) goto loc_822ADFE0;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// sth r8,576(r11)
	PPC_STORE_U16(r11.u32 + 576, ctx.r8.u16);
	// blr 
	return;
loc_822ADFE0:
	// andc r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// sth r8,576(r11)
	PPC_STORE_U16(r11.u32 + 576, ctx.r8.u16);
	// blr 
	return;
loc_822ADFEC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25904
	ctx.r3.s64 = r11.s64 + 25904;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ADFF8"))) PPC_WEAK_FUNC(sub_822ADFF8);
PPC_FUNC_IMPL(__imp__sub_822ADFF8) {
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
	// beq cr6,0x822ae050
	if (cr6.eq) goto loc_822AE050;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae050
	if (cr6.eq) goto loc_822AE050;
	// lwz r3,132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// bl 0x8238f998
	ctx.lr = 0x822AE030;
	sub_8238F998(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
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
loc_822AE050:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
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
}

__attribute__((alias("__imp__sub_822AE070"))) PPC_WEAK_FUNC(sub_822AE070);
PPC_FUNC_IMPL(__imp__sub_822AE070) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae0a0
	if (cr6.eq) goto loc_822AE0A0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae0a0
	if (cr6.eq) goto loc_822AE0A0;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stfs f0,52(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 52, temp.u32);
	// blr 
	return;
loc_822AE0A0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25968
	ctx.r3.s64 = r11.s64 + 25968;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AE0AC"))) PPC_WEAK_FUNC(sub_822AE0AC);
PPC_FUNC_IMPL(__imp__sub_822AE0AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE0B0"))) PPC_WEAK_FUNC(sub_822AE0B0);
PPC_FUNC_IMPL(__imp__sub_822AE0B0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae108
	if (cr6.eq) goto loc_822AE108;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae108
	if (cr6.eq) goto loc_822AE108;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,52(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
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
loc_822AE108:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26040
	ctx.r3.s64 = r11.s64 + 26040;
	// bl 0x82130000
	ctx.lr = 0x822AE114;
	sub_82130000(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,14988(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_822AE138"))) PPC_WEAK_FUNC(sub_822AE138);
PPC_FUNC_IMPL(__imp__sub_822AE138) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae190
	if (cr6.eq) goto loc_822AE190;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae190
	if (cr6.eq) goto loc_822AE190;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,32(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
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
loc_822AE190:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26112
	ctx.r3.s64 = r11.s64 + 26112;
	// bl 0x82130000
	ctx.lr = 0x822AE19C;
	sub_82130000(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_822AE1C0"))) PPC_WEAK_FUNC(sub_822AE1C0);
PPC_FUNC_IMPL(__imp__sub_822AE1C0) {
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
	// beq cr6,0x822ae214
	if (cr6.eq) goto loc_822AE214;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae214
	if (cr6.eq) goto loc_822AE214;
	// lwz r3,132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// bl 0x8238f6b0
	ctx.lr = 0x822AE1F8;
	sub_8238F6B0(ctx, base);
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
loc_822AE214:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26184
	ctx.r3.s64 = r11.s64 + 26184;
	// bl 0x82130000
	ctx.lr = 0x822AE220;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
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
}

__attribute__((alias("__imp__sub_822AE240"))) PPC_WEAK_FUNC(sub_822AE240);
PPC_FUNC_IMPL(__imp__sub_822AE240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,16(r9)
	PPC_STORE_U8(ctx.r9.u32 + 16, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE254"))) PPC_WEAK_FUNC(sub_822AE254);
PPC_FUNC_IMPL(__imp__sub_822AE254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE258"))) PPC_WEAK_FUNC(sub_822AE258);
PPC_FUNC_IMPL(__imp__sub_822AE258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,17(r9)
	PPC_STORE_U8(ctx.r9.u32 + 17, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE26C"))) PPC_WEAK_FUNC(sub_822AE26C);
PPC_FUNC_IMPL(__imp__sub_822AE26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE270"))) PPC_WEAK_FUNC(sub_822AE270);
PPC_FUNC_IMPL(__imp__sub_822AE270) {
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
	// beq cr6,0x822ae2bc
	if (cr6.eq) goto loc_822AE2BC;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r9,8108(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 8108);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
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
loc_822AE2BC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26280
	ctx.r3.s64 = r11.s64 + 26280;
	// bl 0x82130000
	ctx.lr = 0x822AE2C8;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
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
}

__attribute__((alias("__imp__sub_822AE2E8"))) PPC_WEAK_FUNC(sub_822AE2E8);
PPC_FUNC_IMPL(__imp__sub_822AE2E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae334
	if (cr6.eq) goto loc_822AE334;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae340
	if (cr6.eq) goto loc_822AE340;
	// addic. r11,r11,20
	xer.ca = r11.u32 > 4294967275;
	r11.s64 = r11.s64 + 20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x822ae340
	if (cr0.eq) goto loc_822AE340;
	// lbz r11,22(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// b 0x822ae344
	goto loc_822AE344;
loc_822AE334:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26368
	ctx.r3.s64 = r11.s64 + 26368;
	// bl 0x82130000
	ctx.lr = 0x822AE340;
	sub_82130000(ctx, base);
loc_822AE340:
	// li r11,0
	r11.s64 = 0;
loc_822AE344:
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

__attribute__((alias("__imp__sub_822AE364"))) PPC_WEAK_FUNC(sub_822AE364);
PPC_FUNC_IMPL(__imp__sub_822AE364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE368"))) PPC_WEAK_FUNC(sub_822AE368);
PPC_FUNC_IMPL(__imp__sub_822AE368) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 32);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE380"))) PPC_WEAK_FUNC(sub_822AE380);
PPC_FUNC_IMPL(__imp__sub_822AE380) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822AE39C"))) PPC_WEAK_FUNC(sub_822AE39C);
PPC_FUNC_IMPL(__imp__sub_822AE39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE3A0"))) PPC_WEAK_FUNC(sub_822AE3A0);
PPC_FUNC_IMPL(__imp__sub_822AE3A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823318d0
	sub_823318D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AE3C0"))) PPC_WEAK_FUNC(sub_822AE3C0);
PPC_FUNC_IMPL(__imp__sub_822AE3C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE3C4"))) PPC_WEAK_FUNC(sub_822AE3C4);
PPC_FUNC_IMPL(__imp__sub_822AE3C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE3C8"))) PPC_WEAK_FUNC(sub_822AE3C8);
PPC_FUNC_IMPL(__imp__sub_822AE3C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82331858
	sub_82331858(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AE3E8"))) PPC_WEAK_FUNC(sub_822AE3E8);
PPC_FUNC_IMPL(__imp__sub_822AE3E8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE3EC"))) PPC_WEAK_FUNC(sub_822AE3EC);
PPC_FUNC_IMPL(__imp__sub_822AE3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE3F0"))) PPC_WEAK_FUNC(sub_822AE3F0);
PPC_FUNC_IMPL(__imp__sub_822AE3F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,5
	ctx.r10.s64 = 5;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,684(r9)
	PPC_STORE_U32(ctx.r9.u32 + 684, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE404"))) PPC_WEAK_FUNC(sub_822AE404);
PPC_FUNC_IMPL(__imp__sub_822AE404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE408"))) PPC_WEAK_FUNC(sub_822AE408);
PPC_FUNC_IMPL(__imp__sub_822AE408) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,1955(r11)
	PPC_STORE_U8(r11.u32 + 1955, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE434"))) PPC_WEAK_FUNC(sub_822AE434);
PPC_FUNC_IMPL(__imp__sub_822AE434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE438"))) PPC_WEAK_FUNC(sub_822AE438);
PPC_FUNC_IMPL(__imp__sub_822AE438) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,1955(r11)
	PPC_STORE_U8(r11.u32 + 1955, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE464"))) PPC_WEAK_FUNC(sub_822AE464);
PPC_FUNC_IMPL(__imp__sub_822AE464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE468"))) PPC_WEAK_FUNC(sub_822AE468);
PPC_FUNC_IMPL(__imp__sub_822AE468) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae4c8
	if (cr6.eq) goto loc_822AE4C8;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae4bc
	if (cr6.eq) goto loc_822AE4BC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
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
loc_822AE4BC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26508
	ctx.r3.s64 = r11.s64 + 26508;
	// b 0x822ae4d0
	goto loc_822AE4D0;
loc_822AE4C8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26444
	ctx.r3.s64 = r11.s64 + 26444;
loc_822AE4D0:
	// bl 0x82130000
	ctx.lr = 0x822AE4D4;
	sub_82130000(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_822AE4F8"))) PPC_WEAK_FUNC(sub_822AE4F8);
PPC_FUNC_IMPL(__imp__sub_822AE4F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ae514
	if (cr6.eq) goto loc_822AE514;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, r11.u32);
	// blr 
	return;
loc_822AE514:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,25760
	ctx.r3.s64 = r11.s64 + 25760;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AE520"))) PPC_WEAK_FUNC(sub_822AE520);
PPC_FUNC_IMPL(__imp__sub_822AE520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,128(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE538"))) PPC_WEAK_FUNC(sub_822AE538);
PPC_FUNC_IMPL(__imp__sub_822AE538) {
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
	// beq cr6,0x822ae55c
	if (cr6.eq) goto loc_822AE55C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_822AE55C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26568
	ctx.r3.s64 = r11.s64 + 26568;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AE568"))) PPC_WEAK_FUNC(sub_822AE568);
PPC_FUNC_IMPL(__imp__sub_822AE568) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae5a4
	if (cr6.eq) goto loc_822AE5A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ae5a4
	if (cr6.eq) goto loc_822AE5A4;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ae5a4
	if (cr6.eq) goto loc_822AE5A4;
	// lbz r11,113(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 113);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822AE5A4:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE5B8"))) PPC_WEAK_FUNC(sub_822AE5B8);
PPC_FUNC_IMPL(__imp__sub_822AE5B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae5f4
	if (cr6.eq) goto loc_822AE5F4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ae5f4
	if (cr6.eq) goto loc_822AE5F4;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ae5f4
	if (cr6.eq) goto loc_822AE5F4;
	// lbz r11,114(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 114);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822AE5F4:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE608"))) PPC_WEAK_FUNC(sub_822AE608);
PPC_FUNC_IMPL(__imp__sub_822AE608) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae658
	if (cr6.eq) goto loc_822AE658;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ae658
	if (cr6.eq) goto loc_822AE658;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ae658
	if (cr6.eq) goto loc_822AE658;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,31016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_822AE658:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE668"))) PPC_WEAK_FUNC(sub_822AE668);
PPC_FUNC_IMPL(__imp__sub_822AE668) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ae6a8
	if (cr6.eq) goto loc_822AE6A8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b5a48
	ctx.lr = 0x822AE6A0;
	sub_822B5A48(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
loc_822AE6A8:
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

__attribute__((alias("__imp__sub_822AE6C0"))) PPC_WEAK_FUNC(sub_822AE6C0);
PPC_FUNC_IMPL(__imp__sub_822AE6C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822ab708
	sub_822AB708(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AE6D0"))) PPC_WEAK_FUNC(sub_822AE6D0);
PPC_FUNC_IMPL(__imp__sub_822AE6D0) {
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
	// bl 0x822ab780
	ctx.lr = 0x822AE6F0;
	sub_822AB780(ctx, base);
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

__attribute__((alias("__imp__sub_822AE70C"))) PPC_WEAK_FUNC(sub_822AE70C);
PPC_FUNC_IMPL(__imp__sub_822AE70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE710"))) PPC_WEAK_FUNC(sub_822AE710);
PPC_FUNC_IMPL(__imp__sub_822AE710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,112(r11)
	PPC_STORE_U8(r11.u32 + 112, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE738"))) PPC_WEAK_FUNC(sub_822AE738);
PPC_FUNC_IMPL(__imp__sub_822AE738) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae758
	if (cr6.eq) goto loc_822AE758;
	// lwz r11,116(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822AE758:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE764"))) PPC_WEAK_FUNC(sub_822AE764);
PPC_FUNC_IMPL(__imp__sub_822AE764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE768"))) PPC_WEAK_FUNC(sub_822AE768);
PPC_FUNC_IMPL(__imp__sub_822AE768) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f0,27644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// beq cr6,0x822ae7b4
	if (cr6.eq) goto loc_822AE7B4;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
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
	// stfs f0,204(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// bl 0x822a9788
	ctx.lr = 0x822AE7B4;
	sub_822A9788(ctx, base);
loc_822AE7B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE7C4"))) PPC_WEAK_FUNC(sub_822AE7C4);
PPC_FUNC_IMPL(__imp__sub_822AE7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE7C8"))) PPC_WEAK_FUNC(sub_822AE7C8);
PPC_FUNC_IMPL(__imp__sub_822AE7C8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x822AE7D0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ae7f8
	if (cr6.eq) goto loc_822AE7F8;
	// lwz r11,656(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 656);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x822ae7fc
	goto loc_822AE7FC;
loc_822AE7F8:
	// li r11,0
	r11.s64 = 0;
loc_822AE7FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aeafc
	if (cr6.eq) goto loc_822AEAFC;
	// lwz r4,672(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 672);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822aeb40
	if (cr6.lt) goto loc_822AEB40;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// bl 0x823c98b0
	ctx.lr = 0x822AE820;
	sub_823C98B0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// stw r11,672(r30)
	PPC_STORE_U32(r30.u32 + 672, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x822ae848
	if (!cr6.eq) goto loc_822AE848;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// bl 0x822ab0f0
	ctx.lr = 0x822AE840;
	sub_822AB0F0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_822AE848:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-27520
	ctx.r9.s64 = r11.s64 + -27520;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x822ab0f0
	ctx.lr = 0x822AE85C;
	sub_822AB0F0(ctx, base);
	// lwz r24,48(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x822aeb40
	if (cr6.eq) goto loc_822AEB40;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae87c
	if (cr6.eq) goto loc_822AE87C;
	// addi r10,r11,8109
	ctx.r10.s64 = r11.s64 + 8109;
	// b 0x822ae890
	goto loc_822AE890;
loc_822AE87C:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,8109
	ctx.r10.s64 = r11.s64 + 8109;
	// bne cr6,0x822ae890
	if (!cr6.eq) goto loc_822AE890;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822AE890:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,24808
	r11.s64 = r11.s64 + 24808;
loc_822AE898:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822ae8bc
	if (cr6.eq) goto loc_822AE8BC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822ae898
	if (cr6.eq) goto loc_822AE898;
loc_822AE8BC:
	// lwz r11,28(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822aeb40
	if (cr6.eq) goto loc_822AEB40;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822aeb40
	if (cr6.eq) goto loc_822AEB40;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r8.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,672(r30)
	PPC_STORE_U32(r30.u32 + 672, ctx.r10.u32);
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822AE920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822ae950
	if (cr6.eq) goto loc_822AE950;
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822ae950
	if (!cr6.eq) goto loc_822AE950;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// addi r10,r11,17492
	ctx.r10.s64 = r11.s64 + 17492;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae954
	if (cr6.eq) goto loc_822AE954;
loc_822AE950:
	// li r29,0
	r29.s64 = 0;
loc_822AE954:
	// lbz r11,177(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 177);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r27,r10,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x823315c0
	ctx.lr = 0x822AE968;
	sub_823315C0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82332098
	ctx.lr = 0x822AE974;
	sub_82332098(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ae998
	if (cr6.eq) goto loc_822AE998;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r25,1
	r25.s64 = 1;
	// addi r10,r11,17572
	ctx.r10.s64 = r11.s64 + 17572;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae99c
	if (cr6.eq) goto loc_822AE99C;
loc_822AE998:
	// li r25,0
	r25.s64 = 0;
loc_822AE99C:
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae9b0
	if (cr6.eq) goto loc_822AE9B0;
	// addi r31,r11,8109
	r31.s64 = r11.s64 + 8109;
	// b 0x822ae9c4
	goto loc_822AE9C4;
loc_822AE9B0:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,8109
	r31.s64 = r11.s64 + 8109;
	// bne cr6,0x822ae9c4
	if (!cr6.eq) goto loc_822AE9C4;
	// li r31,0
	r31.s64 = 0;
loc_822AE9C4:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82332098
	ctx.lr = 0x822AE9CC;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x8239e458
	ctx.lr = 0x822AE9F8;
	sub_8239E458(ctx, base);
	// clrlwi r26,r29,24
	r26.u64 = r29.u32 & 0xFF;
	// addi r31,r30,144
	r31.s64 = r30.s64 + 144;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// clrlwi r27,r25,24
	r27.u64 = r25.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// beq cr6,0x822aea54
	if (cr6.eq) goto loc_822AEA54;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822aea38
	if (cr6.eq) goto loc_822AEA38;
	// bl 0x823c99e0
	ctx.lr = 0x822AEA20;
	sub_823C99E0(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9a10
	ctx.lr = 0x822AEA34;
	sub_823C9A10(ctx, base);
	// b 0x822aea90
	goto loc_822AEA90;
loc_822AEA38:
	// bl 0x823c9980
	ctx.lr = 0x822AEA3C;
	sub_823C9980(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c99b0
	ctx.lr = 0x822AEA50;
	sub_823C99B0(ctx, base);
	// b 0x822aea90
	goto loc_822AEA90;
loc_822AEA54:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822aea78
	if (cr6.eq) goto loc_822AEA78;
	// bl 0x823c9b60
	ctx.lr = 0x822AEA60;
	sub_823C9B60(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9b90
	ctx.lr = 0x822AEA74;
	sub_823C9B90(ctx, base);
	// b 0x822aea90
	goto loc_822AEA90;
loc_822AEA78:
	// bl 0x823c9b00
	ctx.lr = 0x822AEA7C;
	sub_823C9B00(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9b30
	ctx.lr = 0x822AEA90;
	sub_823C9B30(ctx, base);
loc_822AEA90:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822aead4
	if (cr6.eq) goto loc_822AEAD4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aead4
	if (cr6.eq) goto loc_822AEAD4;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r5,676(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 676);
	// lwz r4,672(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 672);
	// bl 0x823c9c58
	ctx.lr = 0x822AEAC4;
	sub_823C9C58(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x822AEACC;
	sub_82130588(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_822AEAD4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// addi r3,r11,24720
	ctx.r3.s64 = r11.s64 + 24720;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x822AEAEC;
	sub_82130000(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x822AEAF4;
	sub_82130588(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_822AEAFC:
	// lwz r11,672(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 672);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822aeb40
	if (!cr6.lt) goto loc_822AEB40;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x822aeb28
	if (!cr6.eq) goto loc_822AEB28;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// bl 0x822ab0f0
	ctx.lr = 0x822AEB20;
	sub_822AB0F0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_822AEB28:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-27520
	ctx.r9.s64 = r11.s64 + -27520;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x822ab0f0
	ctx.lr = 0x822AEB40;
	sub_822AB0F0(ctx, base);
loc_822AEB40:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822AEB48"))) PPC_WEAK_FUNC(sub_822AEB48);
PPC_FUNC_IMPL(__imp__sub_822AEB48) {
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
	ctx.lr = 0x822AEBC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
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

__attribute__((alias("__imp__sub_822AEBE0"))) PPC_WEAK_FUNC(sub_822AEBE0);
PPC_FUNC_IMPL(__imp__sub_822AEBE0) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AEC04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,26672
	ctx.r3.s64 = ctx.r9.s64 + 26672;
	// bl 0x82130000
	ctx.lr = 0x822AEC14;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822abd38
	ctx.lr = 0x822AEC1C;
	sub_822ABD38(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x822AEC28;
	sub_8255B9A8(ctx, base);
	// lfs f0,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	f0.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fabs f10,f13
	ctx.f10.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lfs f11,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fabs f7,f9
	ctx.f7.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// addi r11,r31,472
	r11.s64 = r31.s64 + 472;
	// lfs f0,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fsubs f6,f10,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsubs f5,f7,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fsel f4,f6,f10,f12
	ctx.f4.f64 = ctx.f6.f64 >= 0.0 ? ctx.f10.f64 : ctx.f12.f64;
	// stfs f4,476(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 476, temp.u32);
	// fsel f3,f5,f7,f8
	ctx.f3.f64 = ctx.f5.f64 >= 0.0 ? ctx.f7.f64 : ctx.f8.f64;
	// stfs f3,472(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 472, temp.u32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// fmuls f13,f1,f1
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fmadds f12,f2,f2,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f13.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// stfs f11,480(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// lfs f10,472(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 472);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,476(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 476);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f8,472(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 472, temp.u32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f7,476(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 476, temp.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lbz r9,689(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 689);
	// beq cr6,0x822aecdc
	if (cr6.eq) goto loc_822AECDC;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aecdc
	if (cr6.eq) goto loc_822AECDC;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aecdc
	if (cr6.eq) goto loc_822AECDC;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822aecd8
	if (!cr6.eq) goto loc_822AECD8;
	// li r11,0
	r11.s64 = 0;
loc_822AECD8:
	// stb r9,597(r11)
	PPC_STORE_U8(r11.u32 + 597, ctx.r9.u8);
loc_822AECDC:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lbz r9,690(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 690);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822aed1c
	if (cr6.eq) goto loc_822AED1C;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aed1c
	if (cr6.eq) goto loc_822AED1C;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aed1c
	if (cr6.eq) goto loc_822AED1C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822aed18
	if (!cr6.eq) goto loc_822AED18;
	// li r11,0
	r11.s64 = 0;
loc_822AED18:
	// stb r9,598(r11)
	PPC_STORE_U8(r11.u32 + 598, ctx.r9.u8);
loc_822AED1C:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aed38
	if (cr6.eq) goto loc_822AED38;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AED38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AED38:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a93a8
	ctx.lr = 0x822AED44;
	sub_822A93A8(ctx, base);
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

__attribute__((alias("__imp__sub_822AED58"))) PPC_WEAK_FUNC(sub_822AED58);
PPC_FUNC_IMPL(__imp__sub_822AED58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aed74
	if (cr6.eq) goto loc_822AED74;
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x822aed78
	goto loc_822AED78;
loc_822AED74:
	// li r11,0
	r11.s64 = 0;
loc_822AED78:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822abd38
	sub_822ABD38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AED88"))) PPC_WEAK_FUNC(sub_822AED88);
PPC_FUNC_IMPL(__imp__sub_822AED88) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AED8C"))) PPC_WEAK_FUNC(sub_822AED8C);
PPC_FUNC_IMPL(__imp__sub_822AED8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AED90"))) PPC_WEAK_FUNC(sub_822AED90);
PPC_FUNC_IMPL(__imp__sub_822AED90) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x822ab0f0
	ctx.lr = 0x822AEDBC;
	sub_822AB0F0(ctx, base);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
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

__attribute__((alias("__imp__sub_822AEDD8"))) PPC_WEAK_FUNC(sub_822AEDD8);
PPC_FUNC_IMPL(__imp__sub_822AEDD8) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x822ab0f0
	sub_822AB0F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AEDF0"))) PPC_WEAK_FUNC(sub_822AEDF0);
PPC_FUNC_IMPL(__imp__sub_822AEDF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AEDF4"))) PPC_WEAK_FUNC(sub_822AEDF4);
PPC_FUNC_IMPL(__imp__sub_822AEDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AEDF8"))) PPC_WEAK_FUNC(sub_822AEDF8);
PPC_FUNC_IMPL(__imp__sub_822AEDF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f0,27644(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27644);
	f0.f64 = double(temp.f32);
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r5,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r5.u32);
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f13,8(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// lfs f10,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// fmuls f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822aeeac
	if (cr6.eq) goto loc_822AEEAC;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
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
	// stfs f0,204(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// bl 0x822a9788
	ctx.lr = 0x822AEEAC;
	sub_822A9788(ctx, base);
loc_822AEEAC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AEEBC"))) PPC_WEAK_FUNC(sub_822AEEBC);
PPC_FUNC_IMPL(__imp__sub_822AEEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AEEC0"))) PPC_WEAK_FUNC(sub_822AEEC0);
PPC_FUNC_IMPL(__imp__sub_822AEEC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwx r7,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u32);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// beq cr6,0x822aef6c
	if (cr6.eq) goto loc_822AEF6C;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aef60
	if (cr6.eq) goto loc_822AEF60;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822aef4c
	if (cr6.eq) goto loc_822AEF4C;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822aef54
	goto loc_822AEF54;
loc_822AEF4C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822AEF54:
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822AEF60:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26796
	ctx.r3.s64 = r11.s64 + 26796;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822AEF6C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26732
	ctx.r3.s64 = r11.s64 + 26732;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AEF78"))) PPC_WEAK_FUNC(sub_822AEF78);
PPC_FUNC_IMPL(__imp__sub_822AEF78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32213
	r11.s64 = -2111111168;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-29424
	ctx.r3.s64 = r11.s64 + -29424;
	// b 0x822aeb48
	sub_822AEB48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AEF88"))) PPC_WEAK_FUNC(sub_822AEF88);
PPC_FUNC_IMPL(__imp__sub_822AEF88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwx r7,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u32);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822af038
	if (cr6.eq) goto loc_822AF038;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822af020
	if (cr6.eq) goto loc_822AF020;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822AF020:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822AF038:
	// addi r11,r10,288
	r11.s64 = ctx.r10.s64 + 288;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF04C"))) PPC_WEAK_FUNC(sub_822AF04C);
PPC_FUNC_IMPL(__imp__sub_822AF04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AF050"))) PPC_WEAK_FUNC(sub_822AF050);
PPC_FUNC_IMPL(__imp__sub_822AF050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822aad90
	sub_822AAD90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AF060"))) PPC_WEAK_FUNC(sub_822AF060);
PPC_FUNC_IMPL(__imp__sub_822AF060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r10,2048
	ctx.r10.s64 = 2048;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// stb r9,32(r8)
	PPC_STORE_U8(ctx.r8.u32 + 32, ctx.r9.u8);
	// lwz r7,28(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,20(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// stw r5,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r5.u32);
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,376(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 376);
	// stw r7,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r7.u32);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r10,376(r6)
	PPC_STORE_U32(ctx.r6.u32 + 376, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF0B0"))) PPC_WEAK_FUNC(sub_822AF0B0);
PPC_FUNC_IMPL(__imp__sub_822AF0B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r7,36(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// stb r10,32(r9)
	PPC_STORE_U8(ctx.r9.u32 + 32, ctx.r10.u8);
	// lwz r6,28(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r7,20(r5)
	PPC_STORE_U32(ctx.r5.u32 + 20, ctx.r7.u32);
	// lwz r4,48(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,40(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// stw r11,376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 376, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF0E8"))) PPC_WEAK_FUNC(sub_822AF0E8);
PPC_FUNC_IMPL(__imp__sub_822AF0E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822ae7c8
	sub_822AE7C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AF0F8"))) PPC_WEAK_FUNC(sub_822AF0F8);
PPC_FUNC_IMPL(__imp__sub_822AF0F8) {
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
	// lfs f2,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,8(r11)
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
	// bl 0x822ab838
	ctx.lr = 0x822AF138;
	sub_822AB838(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF148"))) PPC_WEAK_FUNC(sub_822AF148);
PPC_FUNC_IMPL(__imp__sub_822AF148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
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
	// beqlr cr6
	if (cr6.eq) return;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// li r9,96
	ctx.r9.s64 = 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,108(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 108, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF194"))) PPC_WEAK_FUNC(sub_822AF194);
PPC_FUNC_IMPL(__imp__sub_822AF194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AF198"))) PPC_WEAK_FUNC(sub_822AF198);
PPC_FUNC_IMPL(__imp__sub_822AF198) {
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
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-12608
	ctx.r4.s64 = r11.s64 + -12608;
	// addi r3,r10,29228
	ctx.r3.s64 = ctx.r10.s64 + 29228;
	// bl 0x82554798
	ctx.lr = 0x822AF1B8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-12480
	ctx.r4.s64 = ctx.r9.s64 + -12480;
	// addi r3,r8,29208
	ctx.r3.s64 = ctx.r8.s64 + 29208;
	// bl 0x82554798
	ctx.lr = 0x822AF1CC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-12408
	ctx.r4.s64 = ctx.r7.s64 + -12408;
	// addi r3,r6,29192
	ctx.r3.s64 = ctx.r6.s64 + 29192;
	// bl 0x82554798
	ctx.lr = 0x822AF1E0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-12384
	ctx.r4.s64 = ctx.r5.s64 + -12384;
	// addi r3,r3,29176
	ctx.r3.s64 = ctx.r3.s64 + 29176;
	// bl 0x82554798
	ctx.lr = 0x822AF1F4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-12336
	ctx.r4.s64 = r11.s64 + -12336;
	// addi r3,r10,29160
	ctx.r3.s64 = ctx.r10.s64 + 29160;
	// bl 0x82554798
	ctx.lr = 0x822AF208;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-12224
	ctx.r4.s64 = ctx.r9.s64 + -12224;
	// addi r3,r8,29132
	ctx.r3.s64 = ctx.r8.s64 + 29132;
	// bl 0x82554798
	ctx.lr = 0x822AF21C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4720
	ctx.r4.s64 = ctx.r7.s64 + -4720;
	// addi r3,r6,29100
	ctx.r3.s64 = ctx.r6.s64 + 29100;
	// bl 0x82554798
	ctx.lr = 0x822AF230;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-4648
	ctx.r4.s64 = ctx.r5.s64 + -4648;
	// addi r3,r3,29076
	ctx.r3.s64 = ctx.r3.s64 + 29076;
	// bl 0x82554798
	ctx.lr = 0x822AF244;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-12184
	ctx.r4.s64 = r11.s64 + -12184;
	// addi r3,r10,29044
	ctx.r3.s64 = ctx.r10.s64 + 29044;
	// bl 0x82554798
	ctx.lr = 0x822AF258;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-12144
	ctx.r4.s64 = ctx.r9.s64 + -12144;
	// addi r3,r8,29016
	ctx.r3.s64 = ctx.r8.s64 + 29016;
	// bl 0x82554798
	ctx.lr = 0x822AF26C;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,12560
	ctx.r4.s64 = ctx.r7.s64 + 12560;
	// addi r3,r6,28996
	ctx.r3.s64 = ctx.r6.s64 + 28996;
	// bl 0x82554798
	ctx.lr = 0x822AF280;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-12104
	ctx.r4.s64 = ctx.r5.s64 + -12104;
	// addi r3,r3,28976
	ctx.r3.s64 = ctx.r3.s64 + 28976;
	// bl 0x82554798
	ctx.lr = 0x822AF294;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-12024
	ctx.r4.s64 = r11.s64 + -12024;
	// addi r3,r10,28952
	ctx.r3.s64 = ctx.r10.s64 + 28952;
	// bl 0x82554798
	ctx.lr = 0x822AF2A8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-11960
	ctx.r4.s64 = ctx.r9.s64 + -11960;
	// addi r3,r8,28932
	ctx.r3.s64 = ctx.r8.s64 + 28932;
	// bl 0x82554798
	ctx.lr = 0x822AF2BC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4616
	ctx.r4.s64 = ctx.r7.s64 + -4616;
	// addi r3,r6,28900
	ctx.r3.s64 = ctx.r6.s64 + 28900;
	// bl 0x82554798
	ctx.lr = 0x822AF2D0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-11848
	ctx.r4.s64 = ctx.r5.s64 + -11848;
	// addi r3,r3,28856
	ctx.r3.s64 = ctx.r3.s64 + 28856;
	// bl 0x82554798
	ctx.lr = 0x822AF2E4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-11832
	ctx.r4.s64 = r11.s64 + -11832;
	// addi r3,r10,28844
	ctx.r3.s64 = ctx.r10.s64 + 28844;
	// bl 0x82554798
	ctx.lr = 0x822AF2F8;
	sub_82554798(ctx, base);
	// lis r9,-32151
	ctx.r9.s64 = -2107047936;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,3664
	ctx.r4.s64 = ctx.r9.s64 + 3664;
	// addi r3,r8,28816
	ctx.r3.s64 = ctx.r8.s64 + 28816;
	// bl 0x82554798
	ctx.lr = 0x822AF30C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-11792
	ctx.r4.s64 = ctx.r7.s64 + -11792;
	// addi r3,r6,28800
	ctx.r3.s64 = ctx.r6.s64 + 28800;
	// bl 0x82554798
	ctx.lr = 0x822AF320;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-11776
	ctx.r4.s64 = ctx.r5.s64 + -11776;
	// addi r3,r3,28780
	ctx.r3.s64 = ctx.r3.s64 + 28780;
	// bl 0x82554798
	ctx.lr = 0x822AF334;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-11760
	ctx.r4.s64 = r11.s64 + -11760;
	// addi r3,r10,28752
	ctx.r3.s64 = ctx.r10.s64 + 28752;
	// bl 0x82554798
	ctx.lr = 0x822AF348;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-11728
	ctx.r4.s64 = ctx.r9.s64 + -11728;
	// addi r3,r8,28732
	ctx.r3.s64 = ctx.r8.s64 + 28732;
	// bl 0x82554798
	ctx.lr = 0x822AF35C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-11672
	ctx.r4.s64 = ctx.r7.s64 + -11672;
	// addi r3,r6,28708
	ctx.r3.s64 = ctx.r6.s64 + 28708;
	// bl 0x82554798
	ctx.lr = 0x822AF370;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-11568
	ctx.r4.s64 = ctx.r5.s64 + -11568;
	// addi r3,r3,28692
	ctx.r3.s64 = ctx.r3.s64 + 28692;
	// bl 0x82554798
	ctx.lr = 0x822AF384;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-11432
	ctx.r4.s64 = r11.s64 + -11432;
	// addi r3,r10,28672
	ctx.r3.s64 = ctx.r10.s64 + 28672;
	// bl 0x82554798
	ctx.lr = 0x822AF398;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-11336
	ctx.r4.s64 = ctx.r9.s64 + -11336;
	// addi r3,r8,28656
	ctx.r3.s64 = ctx.r8.s64 + 28656;
	// bl 0x82554798
	ctx.lr = 0x822AF3AC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-11240
	ctx.r4.s64 = ctx.r7.s64 + -11240;
	// addi r3,r6,28636
	ctx.r3.s64 = ctx.r6.s64 + 28636;
	// bl 0x82554798
	ctx.lr = 0x822AF3C0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-11176
	ctx.r4.s64 = ctx.r5.s64 + -11176;
	// addi r3,r3,28616
	ctx.r3.s64 = ctx.r3.s64 + 28616;
	// bl 0x82554798
	ctx.lr = 0x822AF3D4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-11080
	ctx.r4.s64 = r11.s64 + -11080;
	// addi r3,r10,28592
	ctx.r3.s64 = ctx.r10.s64 + 28592;
	// bl 0x82554798
	ctx.lr = 0x822AF3E8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10976
	ctx.r4.s64 = ctx.r9.s64 + -10976;
	// addi r3,r8,28576
	ctx.r3.s64 = ctx.r8.s64 + 28576;
	// bl 0x82554798
	ctx.lr = 0x822AF3FC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4416
	ctx.r4.s64 = ctx.r7.s64 + -4416;
	// addi r3,r6,28556
	ctx.r3.s64 = ctx.r6.s64 + 28556;
	// bl 0x82554798
	ctx.lr = 0x822AF410;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10912
	ctx.r4.s64 = ctx.r5.s64 + -10912;
	// addi r3,r3,28532
	ctx.r3.s64 = ctx.r3.s64 + 28532;
	// bl 0x82554798
	ctx.lr = 0x822AF424;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// addi r4,r11,-10856
	ctx.r4.s64 = r11.s64 + -10856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,28504
	ctx.r3.s64 = ctx.r10.s64 + 28504;
	// bl 0x82554798
	ctx.lr = 0x822AF438;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10792
	ctx.r4.s64 = ctx.r9.s64 + -10792;
	// addi r3,r8,28480
	ctx.r3.s64 = ctx.r8.s64 + 28480;
	// bl 0x82554798
	ctx.lr = 0x822AF44C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4232
	ctx.r4.s64 = ctx.r7.s64 + -4232;
	// addi r3,r6,28456
	ctx.r3.s64 = ctx.r6.s64 + 28456;
	// bl 0x82554798
	ctx.lr = 0x822AF460;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10720
	ctx.r4.s64 = ctx.r5.s64 + -10720;
	// addi r3,r3,28440
	ctx.r3.s64 = ctx.r3.s64 + 28440;
	// bl 0x82554798
	ctx.lr = 0x822AF474;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-10688
	ctx.r4.s64 = r11.s64 + -10688;
	// addi r3,r10,28416
	ctx.r3.s64 = ctx.r10.s64 + 28416;
	// bl 0x82554798
	ctx.lr = 0x822AF488;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10576
	ctx.r4.s64 = ctx.r9.s64 + -10576;
	// addi r3,r8,28388
	ctx.r3.s64 = ctx.r8.s64 + 28388;
	// bl 0x82554798
	ctx.lr = 0x822AF49C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4216
	ctx.r4.s64 = ctx.r7.s64 + -4216;
	// addi r3,r6,28368
	ctx.r3.s64 = ctx.r6.s64 + 28368;
	// bl 0x82554798
	ctx.lr = 0x822AF4B0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10528
	ctx.r4.s64 = ctx.r5.s64 + -10528;
	// addi r3,r3,28340
	ctx.r3.s64 = ctx.r3.s64 + 28340;
	// bl 0x82554798
	ctx.lr = 0x822AF4C4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-10496
	ctx.r4.s64 = r11.s64 + -10496;
	// addi r3,r10,28312
	ctx.r3.s64 = ctx.r10.s64 + 28312;
	// bl 0x82554798
	ctx.lr = 0x822AF4D8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10464
	ctx.r4.s64 = ctx.r9.s64 + -10464;
	// addi r3,r8,28284
	ctx.r3.s64 = ctx.r8.s64 + 28284;
	// bl 0x82554798
	ctx.lr = 0x822AF4EC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-10432
	ctx.r4.s64 = ctx.r7.s64 + -10432;
	// addi r3,r6,28256
	ctx.r3.s64 = ctx.r6.s64 + 28256;
	// bl 0x82554798
	ctx.lr = 0x822AF500;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10400
	ctx.r4.s64 = ctx.r5.s64 + -10400;
	// addi r3,r3,28228
	ctx.r3.s64 = ctx.r3.s64 + 28228;
	// bl 0x82554798
	ctx.lr = 0x822AF514;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-10352
	ctx.r4.s64 = r11.s64 + -10352;
	// addi r3,r10,28208
	ctx.r3.s64 = ctx.r10.s64 + 28208;
	// bl 0x82554798
	ctx.lr = 0x822AF528;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10304
	ctx.r4.s64 = ctx.r9.s64 + -10304;
	// addi r3,r8,28188
	ctx.r3.s64 = ctx.r8.s64 + 28188;
	// bl 0x82554798
	ctx.lr = 0x822AF53C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-10232
	ctx.r4.s64 = ctx.r7.s64 + -10232;
	// addi r3,r6,28168
	ctx.r3.s64 = ctx.r6.s64 + 28168;
	// bl 0x82554798
	ctx.lr = 0x822AF550;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10192
	ctx.r4.s64 = ctx.r5.s64 + -10192;
	// addi r3,r3,28148
	ctx.r3.s64 = ctx.r3.s64 + 28148;
	// bl 0x82554798
	ctx.lr = 0x822AF564;
	sub_82554798(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32213
	ctx.r10.s64 = -2111111168;
	// addi r3,r11,28120
	ctx.r3.s64 = r11.s64 + 28120;
	// addi r4,r10,-10072
	ctx.r4.s64 = ctx.r10.s64 + -10072;
	// bl 0x82554798
	ctx.lr = 0x822AF578;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-9952
	ctx.r4.s64 = ctx.r9.s64 + -9952;
	// addi r3,r8,28092
	ctx.r3.s64 = ctx.r8.s64 + 28092;
	// bl 0x82554798
	ctx.lr = 0x822AF58C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-9832
	ctx.r4.s64 = ctx.r7.s64 + -9832;
	// addi r3,r6,28068
	ctx.r3.s64 = ctx.r6.s64 + 28068;
	// bl 0x82554798
	ctx.lr = 0x822AF5A0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-4016
	ctx.r4.s64 = ctx.r5.s64 + -4016;
	// addi r3,r3,28052
	ctx.r3.s64 = ctx.r3.s64 + 28052;
	// bl 0x82554798
	ctx.lr = 0x822AF5B4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-9768
	ctx.r4.s64 = r11.s64 + -9768;
	// addi r3,r10,28028
	ctx.r3.s64 = ctx.r10.s64 + 28028;
	// bl 0x82554798
	ctx.lr = 0x822AF5C8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-9752
	ctx.r4.s64 = ctx.r9.s64 + -9752;
	// addi r3,r8,28008
	ctx.r3.s64 = ctx.r8.s64 + 28008;
	// bl 0x82554798
	ctx.lr = 0x822AF5DC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-9704
	ctx.r4.s64 = ctx.r7.s64 + -9704;
	// addi r3,r6,27992
	ctx.r3.s64 = ctx.r6.s64 + 27992;
	// bl 0x82554798
	ctx.lr = 0x822AF5F0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-9680
	ctx.r4.s64 = ctx.r5.s64 + -9680;
	// addi r3,r3,27976
	ctx.r3.s64 = ctx.r3.s64 + 27976;
	// bl 0x82554798
	ctx.lr = 0x822AF604;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-9608
	ctx.r4.s64 = r11.s64 + -9608;
	// addi r3,r10,27956
	ctx.r3.s64 = ctx.r10.s64 + 27956;
	// bl 0x82554798
	ctx.lr = 0x822AF618;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-9520
	ctx.r4.s64 = ctx.r9.s64 + -9520;
	// addi r3,r8,27936
	ctx.r3.s64 = ctx.r8.s64 + 27936;
	// bl 0x82554798
	ctx.lr = 0x822AF62C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-9416
	ctx.r4.s64 = ctx.r7.s64 + -9416;
	// addi r3,r6,27916
	ctx.r3.s64 = ctx.r6.s64 + 27916;
	// bl 0x82554798
	ctx.lr = 0x822AF640;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-9312
	ctx.r4.s64 = ctx.r5.s64 + -9312;
	// addi r3,r3,27892
	ctx.r3.s64 = ctx.r3.s64 + 27892;
	// bl 0x82554798
	ctx.lr = 0x822AF654;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-9240
	ctx.r4.s64 = r11.s64 + -9240;
	// addi r3,r10,27868
	ctx.r3.s64 = ctx.r10.s64 + 27868;
	// bl 0x82554798
	ctx.lr = 0x822AF668;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-9168
	ctx.r4.s64 = ctx.r9.s64 + -9168;
	// addi r3,r8,27836
	ctx.r3.s64 = ctx.r8.s64 + 27836;
	// bl 0x82554798
	ctx.lr = 0x822AF67C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-9080
	ctx.r4.s64 = ctx.r7.s64 + -9080;
	// addi r3,r6,27804
	ctx.r3.s64 = ctx.r6.s64 + 27804;
	// bl 0x82554798
	ctx.lr = 0x822AF690;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-8992
	ctx.r4.s64 = ctx.r5.s64 + -8992;
	// addi r3,r3,27772
	ctx.r3.s64 = ctx.r3.s64 + 27772;
	// bl 0x82554798
	ctx.lr = 0x822AF6A4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-8904
	ctx.r4.s64 = r11.s64 + -8904;
	// addi r3,r10,27752
	ctx.r3.s64 = ctx.r10.s64 + 27752;
	// bl 0x82554798
	ctx.lr = 0x822AF6B8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-8776
	ctx.r4.s64 = ctx.r9.s64 + -8776;
	// addi r3,r8,27728
	ctx.r3.s64 = ctx.r8.s64 + 27728;
	// bl 0x82554798
	ctx.lr = 0x822AF6CC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-8760
	ctx.r4.s64 = ctx.r7.s64 + -8760;
	// addi r3,r6,27704
	ctx.r3.s64 = ctx.r6.s64 + 27704;
	// bl 0x82554798
	ctx.lr = 0x822AF6E0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-8632
	ctx.r4.s64 = ctx.r5.s64 + -8632;
	// addi r3,r3,27684
	ctx.r3.s64 = ctx.r3.s64 + 27684;
	// bl 0x82554798
	ctx.lr = 0x822AF6F4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-8560
	ctx.r4.s64 = r11.s64 + -8560;
	// addi r3,r10,27652
	ctx.r3.s64 = ctx.r10.s64 + 27652;
	// bl 0x82554798
	ctx.lr = 0x822AF708;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-8512
	ctx.r4.s64 = ctx.r9.s64 + -8512;
	// addi r3,r8,27624
	ctx.r3.s64 = ctx.r8.s64 + 27624;
	// bl 0x82554798
	ctx.lr = 0x822AF71C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-8448
	ctx.r4.s64 = ctx.r7.s64 + -8448;
	// addi r3,r6,27604
	ctx.r3.s64 = ctx.r6.s64 + 27604;
	// bl 0x82554798
	ctx.lr = 0x822AF730;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-8304
	ctx.r4.s64 = ctx.r5.s64 + -8304;
	// addi r3,r3,27584
	ctx.r3.s64 = ctx.r3.s64 + 27584;
	// bl 0x82554798
	ctx.lr = 0x822AF744;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-8200
	ctx.r4.s64 = r11.s64 + -8200;
	// addi r3,r10,27560
	ctx.r3.s64 = ctx.r10.s64 + 27560;
	// bl 0x82554798
	ctx.lr = 0x822AF758;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-8080
	ctx.r4.s64 = ctx.r9.s64 + -8080;
	// addi r3,r8,27540
	ctx.r3.s64 = ctx.r8.s64 + 27540;
	// bl 0x82554798
	ctx.lr = 0x822AF76C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-8016
	ctx.r4.s64 = ctx.r7.s64 + -8016;
	// addi r3,r6,27520
	ctx.r3.s64 = ctx.r6.s64 + 27520;
	// bl 0x82554798
	ctx.lr = 0x822AF780;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-7880
	ctx.r4.s64 = ctx.r5.s64 + -7880;
	// addi r3,r3,27492
	ctx.r3.s64 = ctx.r3.s64 + 27492;
	// bl 0x82554798
	ctx.lr = 0x822AF794;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-7744
	ctx.r4.s64 = r11.s64 + -7744;
	// addi r3,r10,27464
	ctx.r3.s64 = ctx.r10.s64 + 27464;
	// bl 0x82554798
	ctx.lr = 0x822AF7A8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-7616
	ctx.r4.s64 = ctx.r9.s64 + -7616;
	// addi r3,r8,27448
	ctx.r3.s64 = ctx.r8.s64 + 27448;
	// bl 0x82554798
	ctx.lr = 0x822AF7BC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-7592
	ctx.r4.s64 = ctx.r7.s64 + -7592;
	// addi r3,r6,27432
	ctx.r3.s64 = ctx.r6.s64 + 27432;
	// bl 0x82554798
	ctx.lr = 0x822AF7D0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-7568
	ctx.r4.s64 = ctx.r5.s64 + -7568;
	// addi r3,r3,27408
	ctx.r3.s64 = ctx.r3.s64 + 27408;
	// bl 0x82554798
	ctx.lr = 0x822AF7E4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-7448
	ctx.r4.s64 = r11.s64 + -7448;
	// addi r3,r10,27376
	ctx.r3.s64 = ctx.r10.s64 + 27376;
	// bl 0x82554798
	ctx.lr = 0x822AF7F8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-7320
	ctx.r4.s64 = ctx.r9.s64 + -7320;
	// addi r3,r8,27352
	ctx.r3.s64 = ctx.r8.s64 + 27352;
	// bl 0x82554798
	ctx.lr = 0x822AF80C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4000
	ctx.r4.s64 = ctx.r7.s64 + -4000;
	// addi r3,r6,27328
	ctx.r3.s64 = ctx.r6.s64 + 27328;
	// bl 0x82554798
	ctx.lr = 0x822AF820;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-3920
	ctx.r4.s64 = ctx.r5.s64 + -3920;
	// addi r3,r3,27304
	ctx.r3.s64 = ctx.r3.s64 + 27304;
	// bl 0x82554798
	ctx.lr = 0x822AF834;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-7296
	ctx.r4.s64 = r11.s64 + -7296;
	// addi r3,r10,27284
	ctx.r3.s64 = ctx.r10.s64 + 27284;
	// bl 0x82554798
	ctx.lr = 0x822AF848;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-7264
	ctx.r4.s64 = ctx.r9.s64 + -7264;
	// addi r3,r8,27264
	ctx.r3.s64 = ctx.r8.s64 + 27264;
	// bl 0x82554798
	ctx.lr = 0x822AF85C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-7224
	ctx.r4.s64 = ctx.r7.s64 + -7224;
	// addi r3,r6,27248
	ctx.r3.s64 = ctx.r6.s64 + 27248;
	// bl 0x82554798
	ctx.lr = 0x822AF870;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-7184
	ctx.r4.s64 = ctx.r5.s64 + -7184;
	// addi r3,r3,27224
	ctx.r3.s64 = ctx.r3.s64 + 27224;
	// bl 0x82554798
	ctx.lr = 0x822AF884;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-7160
	ctx.r4.s64 = r11.s64 + -7160;
	// addi r3,r10,27204
	ctx.r3.s64 = ctx.r10.s64 + 27204;
	// bl 0x82554798
	ctx.lr = 0x822AF898;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-7112
	ctx.r4.s64 = ctx.r9.s64 + -7112;
	// addi r3,r8,27184
	ctx.r3.s64 = ctx.r8.s64 + 27184;
	// bl 0x82554798
	ctx.lr = 0x822AF8AC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-7064
	ctx.r4.s64 = ctx.r7.s64 + -7064;
	// addi r3,r6,27168
	ctx.r3.s64 = ctx.r6.s64 + 27168;
	// bl 0x82554798
	ctx.lr = 0x822AF8C0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-6920
	ctx.r4.s64 = ctx.r5.s64 + -6920;
	// addi r3,r3,27140
	ctx.r3.s64 = ctx.r3.s64 + 27140;
	// bl 0x82554798
	ctx.lr = 0x822AF8D4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-6880
	ctx.r4.s64 = r11.s64 + -6880;
	// addi r3,r10,27112
	ctx.r3.s64 = ctx.r10.s64 + 27112;
	// bl 0x82554798
	ctx.lr = 0x822AF8E8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-3864
	ctx.r4.s64 = ctx.r9.s64 + -3864;
	// addi r3,r8,27084
	ctx.r3.s64 = ctx.r8.s64 + 27084;
	// bl 0x82554798
	ctx.lr = 0x822AF8FC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-6856
	ctx.r4.s64 = ctx.r7.s64 + -6856;
	// addi r3,r6,27068
	ctx.r3.s64 = ctx.r6.s64 + 27068;
	// bl 0x82554798
	ctx.lr = 0x822AF910;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-6808
	ctx.r4.s64 = ctx.r5.s64 + -6808;
	// addi r3,r3,27052
	ctx.r3.s64 = ctx.r3.s64 + 27052;
	// bl 0x82554798
	ctx.lr = 0x822AF924;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-6728
	ctx.r4.s64 = r11.s64 + -6728;
	// addi r3,r10,27036
	ctx.r3.s64 = ctx.r10.s64 + 27036;
	// bl 0x82554798
	ctx.lr = 0x822AF938;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-6648
	ctx.r4.s64 = ctx.r9.s64 + -6648;
	// addi r3,r8,27012
	ctx.r3.s64 = ctx.r8.s64 + 27012;
	// bl 0x82554798
	ctx.lr = 0x822AF94C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-3848
	ctx.r4.s64 = ctx.r7.s64 + -3848;
	// addi r3,r6,26996
	ctx.r3.s64 = ctx.r6.s64 + 26996;
	// bl 0x82554798
	ctx.lr = 0x822AF960;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-6552
	ctx.r4.s64 = ctx.r5.s64 + -6552;
	// addi r3,r3,26976
	ctx.r3.s64 = ctx.r3.s64 + 26976;
	// bl 0x82554798
	ctx.lr = 0x822AF974;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-3768
	ctx.r4.s64 = r11.s64 + -3768;
	// addi r3,r10,26956
	ctx.r3.s64 = ctx.r10.s64 + 26956;
	// bl 0x82554798
	ctx.lr = 0x822AF988;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-6464
	ctx.r4.s64 = ctx.r9.s64 + -6464;
	// addi r3,r8,26924
	ctx.r3.s64 = ctx.r8.s64 + 26924;
	// bl 0x82554798
	ctx.lr = 0x822AF99C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-6448
	ctx.r4.s64 = ctx.r7.s64 + -6448;
	// addi r3,r6,26896
	ctx.r3.s64 = ctx.r6.s64 + 26896;
	// bl 0x82554798
	ctx.lr = 0x822AF9B0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-6384
	ctx.r4.s64 = ctx.r5.s64 + -6384;
	// addi r3,r3,26880
	ctx.r3.s64 = ctx.r3.s64 + 26880;
	// bl 0x82554798
	ctx.lr = 0x822AF9C4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-6344
	ctx.r4.s64 = r11.s64 + -6344;
	// addi r3,r10,26860
	ctx.r3.s64 = ctx.r10.s64 + 26860;
	// bl 0x82554798
	ctx.lr = 0x822AF9D8;
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

__attribute__((alias("__imp__sub_822AF9E8"))) PPC_WEAK_FUNC(sub_822AF9E8);
PPC_FUNC_IMPL(__imp__sub_822AF9E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822afa00
	if (cr6.lt) goto loc_822AFA00;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x822afa04
	if (cr6.lt) goto loc_822AFA04;
loc_822AFA00:
	// li r11,0
	r11.s64 = 0;
loc_822AFA04:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA0C"))) PPC_WEAK_FUNC(sub_822AFA0C);
PPC_FUNC_IMPL(__imp__sub_822AFA0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AFA10"))) PPC_WEAK_FUNC(sub_822AFA10);
PPC_FUNC_IMPL(__imp__sub_822AFA10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r3,r11,80
	ctx.r3.s64 = r11.s64 + 80;
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA30"))) PPC_WEAK_FUNC(sub_822AFA30);
PPC_FUNC_IMPL(__imp__sub_822AFA30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,168(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA40"))) PPC_WEAK_FUNC(sub_822AFA40);
PPC_FUNC_IMPL(__imp__sub_822AFA40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,180(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 180);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA50"))) PPC_WEAK_FUNC(sub_822AFA50);
PPC_FUNC_IMPL(__imp__sub_822AFA50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,172(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA60"))) PPC_WEAK_FUNC(sub_822AFA60);
PPC_FUNC_IMPL(__imp__sub_822AFA60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822afa78
	if (cr6.eq) goto loc_822AFA78;
	// lfs f1,84(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822AFA78:
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 176);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA84"))) PPC_WEAK_FUNC(sub_822AFA84);
PPC_FUNC_IMPL(__imp__sub_822AFA84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AFA88"))) PPC_WEAK_FUNC(sub_822AFA88);
PPC_FUNC_IMPL(__imp__sub_822AFA88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822afa9c
	if (cr6.eq) goto loc_822AFA9C;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822afaa8
	if (!cr6.eq) goto loc_822AFAA8;
loc_822AFA9C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	f0.f64 = double(temp.f32);
	// fmuls f2,f2,f0
	ctx.f2.f64 = double(float(ctx.f2.f64 * f0.f64));
loc_822AFAA8:
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// b 0x823147f0
	sub_823147F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AFAB0"))) PPC_WEAK_FUNC(sub_822AFAB0);
PPC_FUNC_IMPL(__imp__sub_822AFAB0) {
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
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// bl 0x82388580
	ctx.lr = 0x822AFAD8;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822afaf4
	if (cr6.lt) goto loc_822AFAF4;
	// bl 0x82387ba0
	ctx.lr = 0x822AFAEC;
	sub_82387BA0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82398568
	ctx.lr = 0x822AFAF4;
	sub_82398568(ctx, base);
loc_822AFAF4:
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

__attribute__((alias("__imp__sub_822AFB0C"))) PPC_WEAK_FUNC(sub_822AFB0C);
PPC_FUNC_IMPL(__imp__sub_822AFB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AFB10"))) PPC_WEAK_FUNC(sub_822AFB10);
PPC_FUNC_IMPL(__imp__sub_822AFB10) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822AFB18;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// bl 0x82388580
	ctx.lr = 0x822AFB30;
	sub_82388580(ctx, base);
	// lwz r28,8(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x821789d8
	ctx.lr = 0x822AFB38;
	sub_821789D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822afb50
	if (cr6.eq) goto loc_822AFB50;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r29,17004(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x822afb58
	goto loc_822AFB58;
loc_822AFB50:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r29,17012(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_822AFB58:
	// bl 0x821789d8
	ctx.lr = 0x822AFB5C;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822afb74
	if (cr6.eq) goto loc_822AFB74;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r30,17008(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x822afb7c
	goto loc_822AFB7C;
loc_822AFB74:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r30,17016(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_822AFB7C:
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x822afc98
	if (cr6.eq) goto loc_822AFC98;
	// li r3,992
	ctx.r3.s64 = 992;
	// bl 0x82130528
	ctx.lr = 0x822AFB8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822afb9c
	if (cr6.eq) goto loc_822AFB9C;
	// bl 0x8217d5e8
	ctx.lr = 0x822AFB98;
	sub_8217D5E8(ctx, base);
	// b 0x822afba0
	goto loc_822AFBA0;
loc_822AFB9C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AFBA0:
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217ce70
	ctx.lr = 0x822AFBB0;
	sub_8217CE70(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lfs f1,29824(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29824);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217ce78
	ctx.lr = 0x822AFBC0;
	sub_8217CE78(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f2,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217d120
	ctx.lr = 0x822AFBEC;
	sub_8217D120(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e910
	ctx.lr = 0x822AFBF8;
	sub_8271E910(ctx, base);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r29,r31,44
	r29.s64 = r31.s64 + 44;
	// li r30,5
	r30.s64 = 5;
	// stb r7,92(r6)
	PPC_STORE_U8(ctx.r6.u32 + 92, ctx.r7.u8);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lfs f0,704(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 704);
	f0.f64 = double(temp.f32);
	// stfs f0,88(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 88, temp.u32);
	// lfs f13,708(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 708);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 84, temp.u32);
loc_822AFC24:
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC30;
	sub_8271EED8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822afc24
	if (!cr0.eq) goto loc_822AFC24;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC48;
	sub_8271EED8(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC54;
	sub_8271EED8(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC60;
	sub_8271EED8(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC6C;
	sub_8271EED8(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC78;
	sub_8271EED8(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f4,84(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,88(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,168(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217d460
	ctx.lr = 0x822AFC98;
	sub_8217D460(ctx, base);
loc_822AFC98:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822AFCA4"))) PPC_WEAK_FUNC(sub_822AFCA4);
PPC_FUNC_IMPL(__imp__sub_822AFCA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AFCA8"))) PPC_WEAK_FUNC(sub_822AFCA8);
PPC_FUNC_IMPL(__imp__sub_822AFCA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822afcc8
	if (cr6.eq) goto loc_822AFCC8;
	// addi r3,r11,80
	ctx.r3.s64 = r11.s64 + 80;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_822AFCC8:
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFCD0"))) PPC_WEAK_FUNC(sub_822AFCD0);
PPC_FUNC_IMPL(__imp__sub_822AFCD0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822AFCD8;
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
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AFD04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822aff04
	if (cr6.eq) goto loc_822AFF04;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822afe44
	if (cr6.eq) goto loc_822AFE44;
	// bl 0x8271eb28
	ctx.lr = 0x822AFD28;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822afd40
	if (cr6.eq) goto loc_822AFD40;
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// beq cr6,0x822afd40
	if (cr6.eq) goto loc_822AFD40;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// bne cr6,0x822aff04
	if (!cr6.eq) goto loc_822AFF04;
loc_822AFD40:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82316148
	ctx.lr = 0x822AFD4C;
	sub_82316148(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aff04
	if (cr6.eq) goto loc_822AFF04;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x822afd70
	if (!cr6.lt) goto loc_822AFD70;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lfs f31,160(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 160);
	f31.f64 = double(temp.f32);
loc_822AFD70:
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x822afe20
	if (cr6.eq) goto loc_822AFE20;
	// cmpwi cr6,r30,14
	cr6.compare<int32_t>(r30.s32, 14, xer);
	// ble cr6,0x822afda0
	if (!cr6.gt) goto loc_822AFDA0;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// bgt cr6,0x822afda0
	if (cr6.gt) goto loc_822AFDA0;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e930
	ctx.lr = 0x822AFD94;
	sub_8271E930(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822AFDA0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 592);
	// rlwinm r7,r8,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822aff04
	if (!cr6.eq) goto loc_822AFF04;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822AFDE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32123
	ctx.r8.s64 = -2105212928;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r6,r8,23088
	ctx.r6.s64 = ctx.r8.s64 + 23088;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// ld r7,23088(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 23088);
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r8,8(r6)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// bl 0x8271e9a0
	ctx.lr = 0x822AFE14;
	sub_8271E9A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822AFE20:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_setzero_si128());
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822AFE44:
	// bl 0x8271eb28
	ctx.lr = 0x822AFE48;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822afef8
	if (cr6.eq) goto loc_822AFEF8;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,784(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 784);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822afe84
	if (cr6.eq) goto loc_822AFE84;
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,784(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// mulli r10,r8,112
	ctx.r10.s64 = ctx.r8.s64 * 112;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,824(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 824);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x822afe88
	if (cr6.gt) goto loc_822AFE88;
loc_822AFE84:
	// lfs f0,160(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	f0.f64 = double(temp.f32);
loc_822AFE88:
	// fsel f31,f31,f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,4
	r30.s64 = 4;
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x822afea4
	if (!cr6.gt) goto loc_822AFEA4;
	// li r30,3
	r30.s64 = 3;
loc_822AFEA4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822afec0
	if (!cr6.eq) goto loc_822AFEC0;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x8271f230
	ctx.lr = 0x822AFEC0;
	sub_8271F230(ctx, base);
loc_822AFEC0:
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r9,r10,23088
	ctx.r9.s64 = ctx.r10.s64 + 23088;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r8,r11,11
	ctx.r8.s64 = r11.s64 + 11;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// ld r7,23088(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// lwz r4,16(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// rldicr r9,r4,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r4,r6,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// bl 0x8271e9a0
	ctx.lr = 0x822AFEF8;
	sub_8271E9A0(ctx, base);
loc_822AFEF8:
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82316148
	ctx.lr = 0x822AFF04;
	sub_82316148(ctx, base);
loc_822AFF04:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822AFF10"))) PPC_WEAK_FUNC(sub_822AFF10);
PPC_FUNC_IMPL(__imp__sub_822AFF10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,17
	cr6.compare<int32_t>(ctx.r10.s32, 17, xer);
	// beq cr6,0x822b0358
	if (cr6.eq) goto loc_822B0358;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822AFF40;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822affa0
	if (cr6.eq) goto loc_822AFFA0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lbz r9,82(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 82);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822affa0
	if (!cr6.eq) goto loc_822AFFA0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82562740
	ctx.lr = 0x822AFF70;
	sub_82562740(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822affa0
	if (!cr6.eq) goto loc_822AFFA0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822ab650
	ctx.lr = 0x822AFF84;
	sub_822AB650(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822affb8
	if (cr6.eq) goto loc_822AFFB8;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822ab650
	ctx.lr = 0x822AFF94;
	sub_822AB650(ctx, base);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stw r3,144(r11)
	PPC_STORE_U32(r11.u32 + 144, ctx.r3.u32);
	// b 0x822affb8
	goto loc_822AFFB8;
loc_822AFFA0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r8,r11,304
	ctx.r8.s64 = r11.s64 + 304;
	// stw r8,144(r10)
	PPC_STORE_U32(ctx.r10.u32 + 144, ctx.r8.u32);
loc_822AFFB8:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AFFCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,208(r8)
	PPC_STORE_U32(ctx.r8.u32 + 208, ctx.r9.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r6,56(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// bne cr6,0x822b000c
	if (!cr6.eq) goto loc_822B000C;
	// rotlwi r3,r7,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// bl 0x8271f3b0
	ctx.lr = 0x822AFFF4;
	sub_8271F3B0(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B000C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B000C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x822B0024;
	sub_822AFCD0(ctx, base);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r8,448
	ctx.r8.s64 = 448;
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,304(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 304);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r6,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b0230
	if (cr6.eq) goto loc_822B0230;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b0230
	if (cr6.eq) goto loc_822B0230;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lbz r9,82(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 82);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b0230
	if (!cr6.eq) goto loc_822B0230;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// rlwinm r7,r9,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822b00f8
	if (cr6.eq) goto loc_822B00F8;
loc_822B009C:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B00B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B00C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32123
	ctx.r7.s64 = -2105212928;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r11,r7,23088
	r11.s64 = ctx.r7.s64 + 23088;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r5,3
	ctx.r5.s64 = 3;
	// lfs f1,14884(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ld r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// rldicr r9,r10,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,23088(r7)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r7.u32 + 23088);
	// bl 0x8271e9a0
	ctx.lr = 0x822B00F4;
	sub_8271E9A0(ctx, base);
	// b 0x822b027c
	goto loc_822B027C;
loc_822B00F8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r10,-6148(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -6148);
	// lbz r9,157(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 157);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b027c
	if (!cr6.eq) goto loc_822B027C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x822b009c
	if (!cr6.gt) goto loc_822B009C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r7,0(r13)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r5,r10,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r7.u32);
	// lvx128 v62,r9,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// beq cr6,0x822b0160
	if (cr6.eq) goto loc_822B0160;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822b0168
	goto loc_822B0168;
loc_822B0160:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822B0168:
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,276(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,280(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 280);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f7,272(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f10,f9,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f5,f8,f7,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bgt cr6,0x822b019c
	if (cr6.gt) goto loc_822B019C;
	// li r11,-1
	r11.s64 = -1;
loc_822B019C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f11,304(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// fmuls f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,36(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822B01E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B01FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r6,r10,23088
	ctx.r6.s64 = ctx.r10.s64 + 23088;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r5,3
	ctx.r5.s64 = 3;
	// ld r7,23088(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// ld r8,8(r6)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x8271e9a0
	ctx.lr = 0x822B022C;
	sub_8271E9A0(ctx, base);
	// b 0x822b027c
	goto loc_822B027C;
loc_822B0230:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B0244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B0258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e930
	ctx.lr = 0x822B0264;
	sub_8271E930(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f3,11360(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,17032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B027C;
	sub_82207EF0(ctx, base);
loc_822B027C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a93a8
	ctx.lr = 0x822B0288;
	sub_822A93A8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82314790
	ctx.lr = 0x822B0290;
	sub_82314790(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,988
	ctx.r3.s64 = r11.s64 + 988;
	// bl 0x822eb078
	ctx.lr = 0x822B029C;
	sub_822EB078(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b02c0
	if (cr6.eq) goto loc_822B02C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x821ec468
	ctx.lr = 0x822B02C0;
	sub_821EC468(ctx, base);
loc_822B02C0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lbz r9,82(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 82);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b0310
	if (cr6.eq) goto loc_822B0310;
	// bl 0x82387a18
	ctx.lr = 0x822B02DC;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b02f4
	if (!cr6.eq) goto loc_822B02F4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,1064
	ctx.r3.s64 = r11.s64 + 1064;
	// bl 0x822eb400
	ctx.lr = 0x822B02F4;
	sub_822EB400(ctx, base);
loc_822B02F4:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,208(r11)
	PPC_STORE_U32(r11.u32 + 208, ctx.r10.u32);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f1,216(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 216);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,212(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 212);
	ctx.f2.f64 = double(temp.f32);
	// b 0x822b0330
	goto loc_822B0330;
loc_822B0310:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822b0358
	if (cr6.eq) goto loc_822B0358;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f1,216(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 216);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,212(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 212);
	ctx.f2.f64 = double(temp.f32);
loc_822B0330:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b0344
	if (cr6.eq) goto loc_822B0344;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822b0350
	if (!cr6.eq) goto loc_822B0350;
loc_822B0344:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	f0.f64 = double(temp.f32);
	// fmuls f2,f2,f0
	ctx.f2.f64 = double(float(ctx.f2.f64 * f0.f64));
loc_822B0350:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823147f0
	ctx.lr = 0x822B0358;
	sub_823147F0(ctx, base);
loc_822B0358:
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

__attribute__((alias("__imp__sub_822B036C"))) PPC_WEAK_FUNC(sub_822B036C);
PPC_FUNC_IMPL(__imp__sub_822B036C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B0370"))) PPC_WEAK_FUNC(sub_822B0370);
PPC_FUNC_IMPL(__imp__sub_822B0370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d4
	ctx.lr = 0x822B0388;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b03b4
	if (cr6.eq) goto loc_822B03B4;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,54320
	ctx.r9.u64 = ctx.r10.u64 | 54320;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0530
	if (!cr6.eq) goto loc_822B0530;
loc_822B03B4:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b0530
	if (cr6.eq) goto loc_822B0530;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B03C8;
	sub_82388598(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r31,r11,21384
	r31.s64 = r11.s64 + 21384;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r31,18
	ctx.r8.s64 = r31.s64 + 18;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f30,-28876(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28876);
	f30.f64 = double(temp.f32);
	// lbzx r3,r10,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// lfs f29,1068(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 1068);
	f29.f64 = double(temp.f32);
	// lfs f31,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f31.f64 = double(temp.f32);
	// lfs f27,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f27.f64 = double(temp.f32);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 - f30.f64));
	// fmuls f0,f11,f29
	f0.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822b0424
	if (!cr6.lt) goto loc_822B0424;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x822b0430
	goto loc_822B0430;
loc_822B0424:
	// fcmpu cr6,f0,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f27.f64);
	// ble cr6,0x822b0430
	if (!cr6.gt) goto loc_822B0430;
	// fmr f0,f27
	f0.f64 = f27.f64;
loc_822B0430:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// lfs f2,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8260c5c8
	ctx.lr = 0x822B0440;
	sub_8260C5C8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// bl 0x82388598
	ctx.lr = 0x822B044C;
	sub_82388598(ctx, base);
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r9,r31,19
	ctx.r9.s64 = r31.s64 + 19;
	// lbzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 - f30.f64));
	// fmuls f0,f11,f29
	f0.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822b0480
	if (!cr6.lt) goto loc_822B0480;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x822b048c
	goto loc_822B048C;
loc_822B0480:
	// fcmpu cr6,f0,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f27.f64);
	// ble cr6,0x822b048c
	if (!cr6.gt) goto loc_822B048C;
	// fmr f0,f27
	f0.f64 = f27.f64;
loc_822B048C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// lfs f2,-28880(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28880);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8260c5c8
	ctx.lr = 0x822B049C;
	sub_8260C5C8(ctx, base);
	// lwz r10,128(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,244(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 244);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822b04e4
	if (cr6.eq) goto loc_822B04E4;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// bne cr6,0x822b04cc
	if (!cr6.eq) goto loc_822B04CC;
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// bgt cr6,0x822b04e0
	if (cr6.gt) goto loc_822B04E0;
loc_822B04CC:
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x822b04e4
	if (!cr6.eq) goto loc_822B04E4;
	// fcmpu cr6,f28,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f0.f64);
	// bge cr6,0x822b04e4
	if (!cr6.lt) goto loc_822B04E4;
loc_822B04E0:
	// fmr f28,f0
	ctx.fpscr.disableFlushMode();
	f28.f64 = f0.f64;
loc_822B04E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x822b052c
	if (!cr6.lt) goto loc_822B052C;
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// beq cr6,0x822b0530
	if (cr6.eq) goto loc_822B0530;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// lfs f12,200(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 200);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-31384(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31384);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f28
	ctx.f11.f64 = double(float(f0.f64 * f28.f64));
	// fmadds f10,f11,f13,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f10,200(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 200, temp.u32);
	// b 0x822b0530
	goto loc_822B0530;
loc_822B052C:
	// stfs f0,200(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 200, temp.u32);
loc_822B0530:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba20
	ctx.lr = 0x822B053C;
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

__attribute__((alias("__imp__sub_822B0550"))) PPC_WEAK_FUNC(sub_822B0550);
PPC_FUNC_IMPL(__imp__sub_822B0550) {
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
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0578
	if (cr6.eq) goto loc_822B0578;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0578;
	sub_8213C218(ctx, base);
loc_822B0578:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b058c
	if (cr6.eq) goto loc_822B058C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B058C;
	sub_8213C218(ctx, base);
loc_822B058C:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b05a0
	if (cr6.eq) goto loc_822B05A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B05A0;
	sub_8213C218(ctx, base);
loc_822B05A0:
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

__attribute__((alias("__imp__sub_822B05B4"))) PPC_WEAK_FUNC(sub_822B05B4);
PPC_FUNC_IMPL(__imp__sub_822B05B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B05B8"))) PPC_WEAK_FUNC(sub_822B05B8);
PPC_FUNC_IMPL(__imp__sub_822B05B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stb r10,101(r31)
	PPC_STORE_U8(r31.u32 + 101, ctx.r10.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stfs f0,224(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 224, temp.u32);
	// lwz r7,96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// std r6,772(r7)
	PPC_STORE_U64(ctx.r7.u32 + 772, ctx.r6.u64);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0624
	if (cr6.eq) goto loc_822B0624;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0624;
	sub_8213C218(ctx, base);
loc_822B0624:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0638
	if (cr6.eq) goto loc_822B0638;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0638;
	sub_8213C218(ctx, base);
loc_822B0638:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b064c
	if (cr6.eq) goto loc_822B064C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B064C;
	sub_8213C218(ctx, base);
loc_822B064C:
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

__attribute__((alias("__imp__sub_822B0660"))) PPC_WEAK_FUNC(sub_822B0660);
PPC_FUNC_IMPL(__imp__sub_822B0660) {
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822B0668;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9c0
	ctx.lr = 0x822B0670;
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// lbz r11,908(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// bl 0x822a5578
	ctx.lr = 0x822B06A8;
	sub_822A5578(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r30,116(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b0ee0
	if (cr6.eq) goto loc_822B0EE0;
	// li r4,67
	ctx.r4.s64 = 67;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B06C4;
	sub_822A4BB8(ctx, base);
	// li r4,66
	ctx.r4.s64 = 66;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B06D4;
	sub_822A4BB8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lfs f30,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	f30.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B06E8;
	sub_8260C5C8(ctx, base);
	// li r4,64
	ctx.r4.s64 = 64;
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f1.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B06F8;
	sub_822A4BB8(ctx, base);
	// li r4,65
	ctx.r4.s64 = 65;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B0708;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B0714;
	sub_8260C5C8(ctx, base);
	// lbz r10,101(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f1.f64;
	// lis r27,-32130
	r27.s64 = -2105671680;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b08a0
	if (!cr6.eq) goto loc_822B08A0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stfs f30,-256(r27)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r27.u32 + -256, temp.u32);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b07d4
	if (cr6.eq) goto loc_822B07D4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b07cc
	if (!cr6.eq) goto loc_822B07CC;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x8271eb28
	ctx.lr = 0x822B0758;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b07cc
	if (!cr6.eq) goto loc_822B07CC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8271f3b0
	ctx.lr = 0x822B076C;
	sub_8271F3B0(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B0784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r7,48(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r6,56(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// bne cr6,0x822b07cc
	if (!cr6.eq) goto loc_822B07CC;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x8271eb28
	ctx.lr = 0x822B07A0;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b07cc
	if (!cr6.eq) goto loc_822B07CC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8271f3b0
	ctx.lr = 0x822B07B4;
	sub_8271F3B0(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B07CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B07CC:
	// li r11,1
	r11.s64 = 1;
	// stb r11,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r11.u8);
loc_822B07D4:
	// lbz r11,101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822b08a0
	if (!cr6.eq) goto loc_822B08A0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b081c
	if (!cr6.eq) goto loc_822B081C;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822abca8
	ctx.lr = 0x822B080C;
	sub_822ABCA8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8271e930
	ctx.lr = 0x822B0818;
	sub_8271E930(ctx, base);
	// b 0x822b0878
	goto loc_822B0878;
loc_822B081C:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b0850
	if (!cr6.eq) goto loc_822B0850;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822abca8
	ctx.lr = 0x822B0840;
	sub_822ABCA8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8271e930
	ctx.lr = 0x822B084C;
	sub_8271E930(ctx, base);
	// b 0x822b0878
	goto loc_822B0878;
loc_822B0850:
	// lis r11,-32123
	r11.s64 = -2105212928;
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r10,r11,23088
	ctx.r10.s64 = r11.s64 + 23088;
	// lfs f1,160(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// ld r7,23088(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 23088);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ld r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// rldicr r9,r9,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x8271e9a0
	ctx.lr = 0x822B0878;
	sub_8271E9A0(ctx, base);
loc_822B0878:
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B0884;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b08a0
	if (cr6.eq) goto loc_822B08A0;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,576(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f0,14980(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14980);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 20, temp.u32);
loc_822B08A0:
	// lbz r11,101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// li r4,69
	ctx.r4.s64 = 69;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B08B8;
	sub_822A4BB8(ctx, base);
	// li r4,68
	ctx.r4.s64 = 68;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B08C8;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B08D4;
	sub_8260C5C8(ctx, base);
	// li r4,70
	ctx.r4.s64 = 70;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = ctx.f1.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B08E4;
	sub_822A4BB8(ctx, base);
	// li r4,71
	ctx.r4.s64 = 71;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B08F4;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B0900;
	sub_8260C5C8(ctx, base);
	// li r4,73
	ctx.r4.s64 = 73;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B0910;
	sub_822A4BB8(ctx, base);
	// li r4,72
	ctx.r4.s64 = 72;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B0920;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B092C;
	sub_8260C5C8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f26,f31
	cr6.compare(f26.f64, f31.f64);
	// bne cr6,0x822b0954
	if (!cr6.eq) goto loc_822B0954;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// bne cr6,0x822b0954
	if (!cr6.eq) goto loc_822B0954;
	// fcmpu cr6,f25,f31
	cr6.compare(f25.f64, f31.f64);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822b0958
	if (cr6.eq) goto loc_822B0958;
loc_822B0954:
	// li r11,0
	r11.s64 = 0;
loc_822B0958:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// bne cr6,0x822b0970
	if (!cr6.eq) goto loc_822B0970;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822b0974
	if (cr6.eq) goto loc_822B0974;
loc_822B0970:
	// li r11,1
	r11.s64 = 1;
loc_822B0974:
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x82388598
	ctx.lr = 0x822B0980;
	sub_82388598(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r30,r11,21384
	r30.s64 = r11.s64 + 21384;
	// addi r9,r30,44
	ctx.r9.s64 = r30.s64 + 44;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b0a24
	if (cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B09A4;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0a24
	if (!cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B09C4;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0a24
	if (!cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B09E4;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0a24
	if (!cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B0A04;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0a24
	if (!cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B0A24;
	sub_82388598(ctx, base);
loc_822B0A24:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b0a38
	if (cr6.eq) goto loc_822B0A38;
	// stfs f30,-256(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r27.u32 + -256, temp.u32);
	// b 0x822b0a44
	goto loc_822B0A44;
loc_822B0A38:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,-256(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + -256, temp.u32);
loc_822B0A44:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// li r29,16
	r29.s64 = 16;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r30,240
	r30.s64 = 240;
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lwz r9,668(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// rlwinm r6,r9,0,26,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// lvx128 v127,r11,r30
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r10,r29
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stvx128 v126,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822b0aa4
	if (cr6.eq) goto loc_822B0AA4;
	// rlwinm r7,r9,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// bne cr6,0x822b0a90
	if (!cr6.eq) goto loc_822B0A90;
	// fcmpu cr6,f27,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f31.f64);
	// blt cr6,0x822b0b1c
	if (cr6.lt) goto loc_822B0B1C;
loc_822B0A90:
	// rlwinm r9,r9,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x822b0aa4
	if (!cr6.eq) goto loc_822B0AA4;
	// fcmpu cr6,f27,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f31.f64);
	// bgt cr6,0x822b0b1c
	if (cr6.gt) goto loc_822B0B1C;
loc_822B0AA4:
	// fcmpu cr6,f27,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f31.f64);
	// beq cr6,0x822b0b20
	if (cr6.eq) goto loc_822B0B20;
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmuls f11,f0,f27
	ctx.f11.f64 = double(float(f0.f64 * f27.f64));
	// lfs f10,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f12,-28872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28872);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,29940(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29940);
	f0.f64 = double(temp.f32);
	// lfs f13,29936(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 29936);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f27,f11,f12
	f27.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fadds f9,f10,f27
	ctx.f9.f64 = double(float(ctx.f10.f64 + f27.f64));
	// stfs f9,24(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// lwz r6,96(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r11,576(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 576);
	// lfs f8,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsel f6,f7,f8,f0
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsel f5,f7,f8,f0
	ctx.f5.f64 = ctx.f7.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsubs f4,f6,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fsel f3,f4,f13,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f13.f64 : ctx.f5.f64;
	// stfs f3,24(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f12,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// beq cr6,0x822b0b1c
	if (cr6.eq) goto loc_822B0B1C;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bne cr6,0x822b0b20
	if (!cr6.eq) goto loc_822B0B20;
loc_822B0B1C:
	// fmr f27,f31
	ctx.fpscr.disableFlushMode();
	f27.f64 = f31.f64;
loc_822B0B20:
	// lwz r11,668(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822b0b68
	if (cr6.eq) goto loc_822B0B68;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// bne cr6,0x822b0b4c
	if (!cr6.eq) goto loc_822B0B4C;
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// ble cr6,0x822b0b4c
	if (!cr6.gt) goto loc_822B0B4C;
	// fmr f26,f31
	f26.f64 = f31.f64;
	// b 0x822b0b90
	goto loc_822B0B90;
loc_822B0B4C:
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x822b0b68
	if (!cr6.eq) goto loc_822B0B68;
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// bge cr6,0x822b0b68
	if (!cr6.lt) goto loc_822B0B68;
	// fmr f26,f31
	f26.f64 = f31.f64;
	// b 0x822b0b90
	goto loc_822B0B90;
loc_822B0B68:
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// beq cr6,0x822b0b90
	if (cr6.eq) goto loc_822B0B90;
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fmuls f13,f0,f26
	ctx.f13.f64 = double(float(f0.f64 * f26.f64));
	// lfs f12,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f26,f13,f0
	f26.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fadds f11,f12,f26
	ctx.f11.f64 = double(float(ctx.f12.f64 + f26.f64));
	// stfs f11,20(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
loc_822B0B90:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822b0c28
	if (!cr6.eq) goto loc_822B0C28;
	// fcmpu cr6,f25,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f25.f64, f31.f64);
	// beq cr6,0x822b0c2c
	if (cr6.eq) goto loc_822B0C2C;
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 * f25.f64));
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f0,32668(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32668);
	f0.f64 = double(temp.f32);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f25,f13,f0
	f25.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fadds f11,f25,f12
	ctx.f11.f64 = double(float(f25.f64 + ctx.f12.f64));
	// stfs f11,28(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lfs f9,748(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 748);
	ctx.f9.f64 = double(temp.f32);
	// lwz r11,576(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 576);
	// lfs f10,744(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 744);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// lfs f6,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f6.f64 = double(temp.f32);
	// fabs f5,f8
	ctx.f5.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// fsubs f4,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fsel f3,f4,f6,f7
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f6.f64 : ctx.f7.f64;
	// fsubs f2,f3,f8
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f8.f64));
	// fsel f1,f2,f8,f3
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f8.f64 : ctx.f3.f64;
	// stfs f1,28(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// lwz r7,96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r6,576(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 576);
	// lfs f0,28(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,224(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 224, temp.u32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r5,576(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f13,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f5
	cr6.compare(ctx.f12.f64, ctx.f5.f64);
	// bne cr6,0x822b0c2c
	if (!cr6.eq) goto loc_822B0C2C;
loc_822B0C28:
	// fmr f25,f31
	ctx.fpscr.disableFlushMode();
	f25.f64 = f31.f64;
loc_822B0C2C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f10,88(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,772
	r11.s64 = r11.s64 + 772;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f9,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f9.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fmuls f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// clrlwi r5,r28,24
	ctx.r5.u64 = r28.u32 & 0xFF;
	// lfs f0,29932(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29932);
	f0.f64 = double(temp.f32);
	// lfs f13,23884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 23884);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lfs f12,29928(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 29928);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,26468(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 26468);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f29,f8,f29
	f29.f64 = double(float(ctx.f8.f64 * f29.f64));
	// fmuls f28,f8,f28
	f28.f64 = double(float(ctx.f8.f64 * f28.f64));
	// fadds f5,f7,f29
	ctx.f5.f64 = double(float(ctx.f7.f64 + f29.f64));
	// fsubs f4,f6,f28
	ctx.f4.f64 = double(float(ctx.f6.f64 - f28.f64));
	// fsubs f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsubs f2,f4,f13
	ctx.f2.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fsel f1,f3,f5,f0
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f5.f64 : f0.f64;
	// fsel f13,f2,f4,f13
	ctx.f13.f64 = ctx.f2.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// fsubs f8,f1,f12
	ctx.f8.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// fsubs f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fsel f0,f8,f12,f1
	f0.f64 = ctx.f8.f64 >= 0.0 ? ctx.f12.f64 : ctx.f1.f64;
	// fsel f13,f7,f11,f13
	ctx.f13.f64 = ctx.f7.f64 >= 0.0 ? ctx.f11.f64 : ctx.f13.f64;
	// beq cr6,0x822b0cbc
	if (cr6.eq) goto loc_822B0CBC;
	// fmuls f11,f13,f9
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// fmuls f12,f0,f9
	ctx.f12.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmuls f8,f11,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// fmuls f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fsubs f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// fsubs f0,f0,f9
	f0.f64 = double(float(f0.f64 - ctx.f9.f64));
loc_822B0CBC:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// lfd f0,29920(r10)
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 29920);
	// fabs f11,f0
	ctx.f11.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bne cr6,0x822b0ce8
	if (!cr6.eq) goto loc_822B0CE8;
	// fmr f29,f31
	f29.f64 = f31.f64;
loc_822B0CE8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fabs f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lfd f0,3456(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + 3456);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bne cr6,0x822b0d04
	if (!cr6.eq) goto loc_822B0D04;
	// fmr f28,f31
	f28.f64 = f31.f64;
loc_822B0D04:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lfd f2,29912(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r10.u32 + 29912);
	// lfs f1,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dc480
	ctx.lr = 0x822B0D1C;
	sub_823DC480(ctx, base);
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// frsp f24,f1
	ctx.fpscr.disableFlushMode();
	f24.f64 = double(float(ctx.f1.f64));
	// lwz r7,576(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 576);
	// lfs f23,20(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	f23.f64 = double(temp.f32);
	// lfs f30,24(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	f30.f64 = double(temp.f32);
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// bl 0x823dbae8
	ctx.lr = 0x822B0D38;
	sub_823DBAE8(ctx, base);
	// frsp f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822B0D44;
	sub_823DBBC8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// lfs f0,17032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f22
	ctx.f12.f64 = double(float(ctx.f13.f64 * f22.f64));
	// fmuls f11,f12,f24
	ctx.f11.f64 = double(float(ctx.f12.f64 * f24.f64));
	// fmuls f23,f11,f0
	f23.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x822B0D64;
	sub_823DBBC8(ctx, base);
	// frsp f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822B0D70;
	sub_823DBBC8(ctx, base);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lwz r4,576(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 576);
	// stfs f31,16(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stfs f23,240(r3)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r3.u32 + 240, temp.u32);
	// fmuls f9,f10,f22
	ctx.f9.f64 = double(float(ctx.f10.f64 * f22.f64));
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// fmuls f8,f9,f24
	ctx.f8.f64 = double(float(ctx.f9.f64 * f24.f64));
	// stfs f8,248(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 248, temp.u32);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r28,668(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 668);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B0DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x822b0de8
	if (!cr6.eq) goto loc_822B0DE8;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822b0de8
	if (cr6.eq) goto loc_822B0DE8;
	// stvx128 v127,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// stvx128 v126,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f0.f64 = double(temp.f32);
	// stfs f0,224(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 224, temp.u32);
loc_822B0DE8:
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// bne cr6,0x822b0e20
	if (!cr6.eq) goto loc_822B0E20;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// bne cr6,0x822b0e20
	if (!cr6.eq) goto loc_822B0E20;
	// fcmpu cr6,f29,f31
	cr6.compare(f29.f64, f31.f64);
	// bne cr6,0x822b0e20
	if (!cr6.eq) goto loc_822B0E20;
	// fcmpu cr6,f28,f31
	cr6.compare(f28.f64, f31.f64);
	// bne cr6,0x822b0e20
	if (!cr6.eq) goto loc_822B0E20;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0e3c
	if (cr6.eq) goto loc_822B0E3C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0E1C;
	sub_8213C218(ctx, base);
	// b 0x822b0e3c
	goto loc_822B0E3C;
loc_822B0E20:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// addi r4,r31,144
	ctx.r4.s64 = r31.s64 + 144;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b0e3c
	if (!cr6.eq) goto loc_822B0E3C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,29888
	ctx.r3.s64 = r11.s64 + 29888;
	// bl 0x821e6810
	ctx.lr = 0x822B0E3C;
	sub_821E6810(ctx, base);
loc_822B0E3C:
	// fcmpu cr6,f25,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f25.f64, f31.f64);
	// ble cr6,0x822b0e78
	if (!cr6.gt) goto loc_822B0E78;
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0e58
	if (cr6.eq) goto loc_822B0E58;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0E58;
	sub_8213C218(ctx, base);
loc_822B0E58:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// addi r4,r31,152
	ctx.r4.s64 = r31.s64 + 152;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,29864
	ctx.r3.s64 = r11.s64 + 29864;
	// bl 0x821e6810
	ctx.lr = 0x822B0E74;
	sub_821E6810(ctx, base);
	// b 0x822b0ef0
	goto loc_822B0EF0;
loc_822B0E78:
	// fcmpu cr6,f25,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f25.f64, f31.f64);
	// bge cr6,0x822b0eb4
	if (!cr6.lt) goto loc_822B0EB4;
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0e94
	if (cr6.eq) goto loc_822B0E94;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0E94;
	sub_8213C218(ctx, base);
loc_822B0E94:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r4,r31,148
	ctx.r4.s64 = r31.s64 + 148;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,29840
	ctx.r3.s64 = r11.s64 + 29840;
	// bl 0x821e6810
	ctx.lr = 0x822B0EB0;
	sub_821E6810(ctx, base);
	// b 0x822b0ef0
	goto loc_822B0EF0;
loc_822B0EB4:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0ec8
	if (cr6.eq) goto loc_822B0EC8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0EC8;
	sub_8213C218(ctx, base);
loc_822B0EC8:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0ef0
	if (cr6.eq) goto loc_822B0EF0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0EDC;
	sub_8213C218(ctx, base);
	// b 0x822b0ef0
	goto loc_822B0EF0;
loc_822B0EE0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,-256(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -256, temp.u32);
loc_822B0EF0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba0c
	ctx.lr = 0x822B0F0C;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822B0F10"))) PPC_WEAK_FUNC(sub_822B0F10);
PPC_FUNC_IMPL(__imp__sub_822B0F10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822b0f50
	if (!cr6.eq) goto loc_822B0F50;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822B0F50:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82351cb0
	ctx.lr = 0x822B0F58;
	sub_82351CB0(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822b0fa0
	if (!cr6.eq) goto loc_822B0FA0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822abca8
	ctx.lr = 0x822B0F7C;
	sub_822ABCA8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B0F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822b0fe8
	goto loc_822B0FE8;
loc_822B0FA0:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bne cr6,0x822b0fdc
	if (!cr6.eq) goto loc_822B0FDC;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x822abca8
	ctx.lr = 0x822B0FB8;
	sub_822ABCA8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B0FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822b0fe8
	goto loc_822B0FE8;
loc_822B0FDC:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x822abca8
	ctx.lr = 0x822B0FE8;
	sub_822ABCA8(ctx, base);
loc_822B0FE8:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-228
	ctx.r6.s64 = ctx.r10.s64 + -228;
	// addi r5,r9,-252
	ctx.r5.s64 = ctx.r9.s64 + -252;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x823dedd8
	ctx.lr = 0x822B100C;
	sub_823DEDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822b1038
	if (cr6.eq) goto loc_822B1038;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B1038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B1038:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x822b105c
	if (!cr6.eq) goto loc_822B105C;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x8271e930
	ctx.lr = 0x822B1058;
	sub_8271E930(ctx, base);
	// b 0x822b10c8
	goto loc_822B10C8;
loc_822B105C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// ld r7,23088(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x822b10a0
	if (!cr6.gt) goto loc_822B10A0;
	// addi r9,r10,23088
	ctx.r9.s64 = ctx.r10.s64 + 23088;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r8,r11,11
	ctx.r8.s64 = r11.s64 + 11;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,16(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// rldicr r9,r4,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r4,r6,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// b 0x822b10c4
	goto loc_822B10C4;
loc_822B10A0:
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// addi r8,r10,23088
	ctx.r8.s64 = ctx.r10.s64 + 23088;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,16(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwzx r11,r6,r31
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// rldicr r9,r4,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lfs f1,160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
loc_822B10C4:
	// bl 0x8271e9a0
	ctx.lr = 0x822B10C8;
	sub_8271E9A0(ctx, base);
loc_822B10C8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a93a8
	ctx.lr = 0x822B10D4;
	sub_822A93A8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// addi r3,r10,29944
	ctx.r3.s64 = ctx.r10.s64 + 29944;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82130000
	ctx.lr = 0x822B10F4;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_822B1110"))) PPC_WEAK_FUNC(sub_822B1110);
PPC_FUNC_IMPL(__imp__sub_822B1110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B1140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r4,68(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B1158;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r4,72(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B116C;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B1180;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x8271eef0
	ctx.lr = 0x822B1194;
	sub_8271EEF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r31,80(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lis r11,26214
	r11.s64 = 1717960704;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r8,r11,26215
	ctx.r8.u64 = r11.u64 | 26215;
loc_822B11AC:
	// addic. r11,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	r11.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r9,5
	ctx.r9.s64 = 5;
	// blt 0x822b11bc
	if (cr0.lt) goto loc_822B11BC;
	// li r9,0
	ctx.r9.s64 = 0;
loc_822B11BC:
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// mulhw r6,r7,r8
	ctx.r6.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32)) >> 32;
	// srawi r11,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	r11.s64 = ctx.r6.s32 >> 1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r5,r7
	r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// add. r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq 0x822b11ac
	if (cr0.eq) goto loc_822B11AC;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x822b11ac
	if (cr6.eq) goto loc_822B11AC;
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// beq cr6,0x822b11ac
	if (cr6.eq) goto loc_822B11AC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822afab0
	ctx.lr = 0x822B11FC;
	sub_822AFAB0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x822b1224
	if (cr6.eq) goto loc_822B1224;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// beq cr6,0x822b1224
	if (cr6.eq) goto loc_822B1224;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b1224
	if (cr6.eq) goto loc_822B1224;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r31,3
	r31.s64 = 3;
	// bne cr6,0x822b1228
	if (!cr6.eq) goto loc_822B1228;
loc_822B1224:
	// li r31,4
	r31.s64 = 4;
loc_822B1228:
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B1248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822B125C;
	sub_822B0F10(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-12252(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12252);
	// bl 0x821ec4e8
	ctx.lr = 0x822B1268;
	sub_821EC4E8(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// addi r4,r5,17840
	ctx.r4.s64 = ctx.r5.s64 + 17840;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B1294;
	sub_82207EF0(ctx, base);
loc_822B1294:
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

__attribute__((alias("__imp__sub_822B12AC"))) PPC_WEAK_FUNC(sub_822B12AC);
PPC_FUNC_IMPL(__imp__sub_822B12AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B12B0"))) PPC_WEAK_FUNC(sub_822B12B0);
PPC_FUNC_IMPL(__imp__sub_822B12B0) {
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
	ctx.lr = 0x822B12B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x822B12C4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822b12d8
	if (!cr6.eq) goto loc_822B12D8;
loc_822B12CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822B12D8:
	// lwz r4,72(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B12E4;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b12cc
	if (!cr6.eq) goto loc_822B12CC;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b12cc
	if (cr6.eq) goto loc_822B12CC;
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822b12cc
	if (cr6.eq) goto loc_822B12CC;
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b12cc
	if (cr6.eq) goto loc_822B12CC;
	// lwz r11,592(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 592);
	// rlwinm r10,r11,0,26,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3C;
	// rlwinm r10,r10,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b136c
	if (cr6.eq) goto loc_822B136C;
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,17
	cr6.compare<int32_t>(ctx.r10.s32, 17, xer);
	// beq cr6,0x822b136c
	if (cr6.eq) goto loc_822B136C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82332098
	ctx.lr = 0x822B133C;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b136c
	if (cr6.eq) goto loc_822B136C;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lbz r10,82(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 82);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b136c
	if (!cr6.eq) goto loc_822B136C;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82562740
	ctx.lr = 0x822B1360;
	sub_82562740(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b12cc
	if (cr6.eq) goto loc_822B12CC;
loc_822B136C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r3,r10,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B1384"))) PPC_WEAK_FUNC(sub_822B1384);
PPC_FUNC_IMPL(__imp__sub_822B1384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B1388"))) PPC_WEAK_FUNC(sub_822B1388);
PPC_FUNC_IMPL(__imp__sub_822B1388) {
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
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b13cc
	if (cr6.eq) goto loc_822B13CC;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b13cc
	if (cr6.eq) goto loc_822B13CC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B13BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b13d0
	if (!cr6.eq) goto loc_822B13D0;
loc_822B13CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822B13D0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B13E0"))) PPC_WEAK_FUNC(sub_822B13E0);
PPC_FUNC_IMPL(__imp__sub_822B13E0) {
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
	// lwz r4,132(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B13F8;
	sub_8271EB28(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

