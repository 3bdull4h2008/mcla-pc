#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82745370"))) PPC_WEAK_FUNC(sub_82745370);
PPC_FUNC_IMPL(__imp__sub_82745370) {
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
	PPCRegister f27{};
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
	// bl 0x823d91d8
	ctx.lr = 0x82745378;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d4
	ctx.lr = 0x82745380;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82745580
	if (cr6.eq) goto loc_82745580;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82745580
	if (cr6.eq) goto loc_82745580;
	// lwz r11,1708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1708);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82745574
	if (cr6.eq) goto loc_82745574;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82745574
	if (cr6.eq) goto loc_82745574;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmr f29,f0
	f29.f64 = f0.f64;
	// fmr f28,f0
	f28.f64 = f0.f64;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// lwz r28,8(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r7,144(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// lwz r11,664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f13,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,20(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 20, temp.u32);
	// beq cr6,0x82745414
	if (cr6.eq) goto loc_82745414;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82745414
	if (cr6.eq) goto loc_82745414;
	// lwz r11,664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 664);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f29,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f29.f64 = double(temp.f32);
	// lfs f28,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f28.f64 = double(temp.f32);
loc_82745414:
	// lwz r11,668(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 668);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8274543c
	if (cr6.eq) goto loc_8274543C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8274543c
	if (cr6.eq) goto loc_8274543C;
	// lwz r11,668(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 668);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f31,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f31.f64 = double(temp.f32);
	// lfs f30,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f30.f64 = double(temp.f32);
loc_8274543C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// extsh r29,r9
	r29.s64 = ctx.r9.s16;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bgt cr6,0x8274546c
	if (cr6.gt) goto loc_8274546C;
	// li r29,2
	r29.s64 = 2;
loc_8274546C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r27,4(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x82745480;
	sub_822A8108(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r26,r1,172
	r26.s64 = ctx.r1.s64 + 172;
	// addi r25,r1,168
	r25.s64 = ctx.r1.s64 + 168;
	// addi r24,r1,164
	r24.s64 = ctx.r1.s64 + 164;
	// lvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// addi r23,r1,160
	r23.s64 = ctx.r1.s64 + 160;
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// lwz r28,128(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// lwz r22,104(r6)
	r22.u64 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	// bl 0x822a8108
	ctx.lr = 0x827454C0;
	sub_822A8108(ctx, base);
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// addi r20,r1,176
	r20.s64 = ctx.r1.s64 + 176;
	// addi r28,r28,272
	r28.s64 = r28.s64 + 272;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,44(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x827454E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-31128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31128);
	f0.f64 = double(temp.f32);
	// fmuls f27,f1,f0
	f27.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x822b9e60
	ctx.lr = 0x827454F4;
	sub_822B9E60(ctx, base);
	// extsh r11,r29
	r11.s64 = r29.s16;
	// fmr f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lfs f2,1676(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1676);
	ctx.f2.f64 = double(temp.f32);
	// addi r6,r11,-2
	ctx.r6.s64 = r11.s64 + -2;
	// lfs f1,1680(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1680);
	ctx.f1.f64 = double(temp.f32);
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// fmr f5,f28
	ctx.f5.f64 = f28.f64;
	// stw r20,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r20.u32);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// stw r21,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r21.u32);
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// stw r23,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r23.u32);
	// fmr f8,f27
	ctx.f8.f64 = f27.f64;
	// stw r24,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r24.u32);
	// stw r25,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r25.u32);
	// stw r26,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r26.u32);
	// bl 0x8254a280
	ctx.lr = 0x82745540;
	sub_8254A280(ctx, base);
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f0.f64 = double(temp.f32);
	// sth r29,44(r30)
	PPC_STORE_U16(r30.u32 + 44, r29.u16);
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,152(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 152, temp.u32);
	// stfs f13,156(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 156, temp.u32);
	// stfs f12,160(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 160, temp.u32);
	// stfs f11,164(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 164, temp.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba20
	ctx.lr = 0x82745570;
	// b 0x823d9228
	return;
loc_82745574:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bcfe0
	ctx.lr = 0x82745580;
	sub_822BCFE0(ctx, base);
loc_82745580:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba20
	ctx.lr = 0x8274558C;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82745590"))) PPC_WEAK_FUNC(sub_82745590);
PPC_FUNC_IMPL(__imp__sub_82745590) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82745598;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x82687930
	ctx.lr = 0x827455B0;
	sub_82687930(ctx, base);
	// lwz r4,1700(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1700);
	// lfs f1,1704(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1704);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827455D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// addi r5,r7,2240
	ctx.r5.s64 = ctx.r7.s64 + 2240;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// vmsum3fp128 v60,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r10,r4,-31648
	ctx.r10.s64 = ctx.r4.s64 + -31648;
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8148
	ctx.lr = 0x82745644;
	sub_822A8148(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f9,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r3,-10012(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10012);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f31,f8,f12,f7
	f31.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// bl 0x826d6a48
	ctx.lr = 0x82745678;
	sub_826D6A48(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// lfs f30,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f30.f64 = double(temp.f32);
	// beq cr6,0x82745780
	if (cr6.eq) goto loc_82745780;
	// addi r10,r11,35
	ctx.r10.s64 = r11.s64 + 35;
	// lwz r11,-10012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10012);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lfs f1,1704(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1704);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r5,1700(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1700);
	// addi r8,r9,-5456
	ctx.r8.s64 = ctx.r9.s64 + -5456;
	// addis r9,r11,3
	ctx.r9.s64 = r11.s64 + 196608;
	// addis r4,r11,6
	ctx.r4.s64 = r11.s64 + 393216;
	// addi r9,r9,29452
	ctx.r9.s64 = ctx.r9.s64 + 29452;
	// add r7,r10,r31
	ctx.r7.u64 = ctx.r10.u64 + r31.u64;
	// addi r4,r4,16704
	ctx.r4.s64 = ctx.r4.s64 + 16704;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x8224c590
	ctx.lr = 0x827456C8;
	sub_8224C590(ctx, base);
	// lwz r8,412(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82745708
	if (!cr6.eq) goto loc_82745708;
	// li r11,4
	r11.s64 = 4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
	// bl 0x822a8108
	ctx.lr = 0x827456E4;
	sub_822A8108(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x827456EC;
	sub_822A8108(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x827456F4;
	sub_822A8108(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82745708:
	// fneg f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f31.u64 ^ 0x8000000000000000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r11,-1
	r11.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// sth r30,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r30.u16);
	// lfs f0,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stb r30,124(r1)
	PPC_STORE_U8(ctx.r1.u32 + 124, r30.u8);
	// fsel f12,f13,f30,f31
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f30.f64 : f31.f64;
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8224c408
	ctx.lr = 0x8274574C;
	sub_8224C408(ctx, base);
	// stw r30,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r30.u32);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8224f818
	ctx.lr = 0x8274575C;
	sub_8224F818(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x826df430
	ctx.lr = 0x82745770;
	sub_826DF430(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r8,-18952
	ctx.r7.s64 = ctx.r8.s64 + -18952;
	// stw r7,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r7.u32);
	// stw r7,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r7.u32);
loc_82745780:
	// lfs f0,1664(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1664);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8274579c
	if (!cr6.gt) goto loc_8274579C;
	// lbz r10,496(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 496);
	// stfs f0,484(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
	// stb r9,496(r1)
	PPC_STORE_U8(ctx.r1.u32 + 496, ctx.r9.u8);
loc_8274579C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,1668(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1668);
	f0.f64 = double(temp.f32);
	// lfs f13,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x827457c0
	if (!cr6.gt) goto loc_827457C0;
	// lbz r10,496(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 496);
	// stfs f0,492(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,496(r1)
	PPC_STORE_U8(ctx.r1.u32 + 496, ctx.r9.u8);
loc_827457C0:
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// lwz r3,-10012(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10012);
	// bl 0x826d4b70
	ctx.lr = 0x827457CC;
	sub_826D4B70(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stw r3,1652(r31)
	PPC_STORE_U32(r31.u32 + 1652, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827457EC"))) PPC_WEAK_FUNC(sub_827457EC);
PPC_FUNC_IMPL(__imp__sub_827457EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827457F0"))) PPC_WEAK_FUNC(sub_827457F0);
PPC_FUNC_IMPL(__imp__sub_827457F0) {
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
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82744bb8
	ctx.lr = 0x82745810;
	sub_82744BB8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8274582C"))) PPC_WEAK_FUNC(sub_8274582C);
PPC_FUNC_IMPL(__imp__sub_8274582C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82745830"))) PPC_WEAK_FUNC(sub_82745830);
PPC_FUNC_IMPL(__imp__sub_82745830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,1708(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1708);
	// addi r8,r11,-6
	ctx.r8.s64 = r11.s64 + -6;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82745854"))) PPC_WEAK_FUNC(sub_82745854);
PPC_FUNC_IMPL(__imp__sub_82745854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82745858"))) PPC_WEAK_FUNC(sub_82745858);
PPC_FUNC_IMPL(__imp__sub_82745858) {
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
	// stfs f0,1664(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 1664, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274586C"))) PPC_WEAK_FUNC(sub_8274586C);
PPC_FUNC_IMPL(__imp__sub_8274586C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82745870"))) PPC_WEAK_FUNC(sub_82745870);
PPC_FUNC_IMPL(__imp__sub_82745870) {
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
	// stfs f0,1668(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 1668, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82745884"))) PPC_WEAK_FUNC(sub_82745884);
PPC_FUNC_IMPL(__imp__sub_82745884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82745888"))) PPC_WEAK_FUNC(sub_82745888);
PPC_FUNC_IMPL(__imp__sub_82745888) {
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
	// stb r6,1660(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1660, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827458A8"))) PPC_WEAK_FUNC(sub_827458A8);
PPC_FUNC_IMPL(__imp__sub_827458A8) {
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
	// beq cr6,0x827458c8
	if (cr6.eq) goto loc_827458C8;
	// lwz r11,1656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1656);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_827458C8:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827458D4"))) PPC_WEAK_FUNC(sub_827458D4);
PPC_FUNC_IMPL(__imp__sub_827458D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827458D8"))) PPC_WEAK_FUNC(sub_827458D8);
PPC_FUNC_IMPL(__imp__sub_827458D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x827458F4;
	sub_822A8108(ctx, base);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x82745914;
	sub_822A8108(ctx, base);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82744d98
	ctx.lr = 0x8274592C;
	sub_82744D98(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82745940
	if (cr6.eq) goto loc_82745940;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745590
	ctx.lr = 0x82745940;
	sub_82745590(ctx, base);
loc_82745940:
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

__attribute__((alias("__imp__sub_82745954"))) PPC_WEAK_FUNC(sub_82745954);
PPC_FUNC_IMPL(__imp__sub_82745954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82745958"))) PPC_WEAK_FUNC(sub_82745958);
PPC_FUNC_IMPL(__imp__sub_82745958) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82745960;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f13,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f12,11368(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11368);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f11,31304(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31304);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,21588(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 21588);
	ctx.f10.f64 = double(temp.f32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lfs f31,31292(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31292);
	f31.f64 = double(temp.f32);
	// li r22,0
	r22.s64 = 0;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r25,r31,1704
	r25.s64 = r31.s64 + 1704;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// ori r29,r9,16704
	r29.u64 = ctx.r9.u64 | 16704;
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// stfs f10,160(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// li r23,48
	r23.s64 = 48;
	// li r24,32
	r24.s64 = 32;
	// addi r26,r11,-31600
	r26.s64 = r11.s64 + -31600;
loc_827459E8:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r11,-10012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10012);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x8224a4f8
	ctx.lr = 0x82745A1C;
	sub_8224A4F8(ctx, base);
	// stw r3,1700(r31)
	PPC_STORE_U32(r31.u32 + 1700, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82745a7c
	if (cr6.eq) goto loc_82745A7C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v1,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82165300
	ctx.lr = 0x82745A38;
	sub_82165300(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745208
	ctx.lr = 0x82745A48;
	sub_82745208(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r30,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r30,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82744fc8
	ctx.lr = 0x82745A70;
	sub_82744FC8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82745aa4
	if (!cr6.eq) goto loc_82745AA4;
loc_82745A7C:
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r22,5
	cr6.compare<int32_t>(r22.s32, 5, xer);
	// blt cr6,0x827459e8
	if (cr6.lt) goto loc_827459E8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_82745AA4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
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

__attribute__((alias("__imp__sub_82745ABC"))) PPC_WEAK_FUNC(sub_82745ABC);
PPC_FUNC_IMPL(__imp__sub_82745ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82745AC0"))) PPC_WEAK_FUNC(sub_82745AC0);
PPC_FUNC_IMPL(__imp__sub_82745AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,1700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1700);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82745af0
	if (!cr6.eq) goto loc_82745AF0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82745b78
	goto loc_82745B78;
loc_82745AF0:
	// lwz r4,1700(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1700);
	// lfs f1,1704(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1704);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82745B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r9,-31600
	ctx.r7.s64 = ctx.r9.s64 + -31600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,31292(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x82745B3C;
	sub_82165300(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745208
	ctx.lr = 0x82745B4C;
	sub_82745208(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v62,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82745B78:
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

__attribute__((alias("__imp__sub_82745B90"))) PPC_WEAK_FUNC(sub_82745B90);
PPC_FUNC_IMPL(__imp__sub_82745B90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x82745BBC;
	sub_822A8108(ctx, base);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v127,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x82745BDC;
	sub_822A8108(ctx, base);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82744d98
	ctx.lr = 0x82745BF4;
	sub_82744D98(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82745da0
	if (cr6.eq) goto loc_82745DA0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82745c44
	if (cr6.eq) goto loc_82745C44;
	// lwz r3,1700(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1700);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f31,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f31.f64 = double(temp.f32);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82745C2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmuls f13,f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lfs f0,-3072(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -3072);
	f0.f64 = double(temp.f32);
	// fmsubs f12,f31,f31,f13
	ctx.f12.f64 = double(float(f31.f64 * f31.f64 - ctx.f13.f64));
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// b 0x82745c4c
	goto loc_82745C4C;
loc_82745C44:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82745C4C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f30,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f30.f64 = double(temp.f32);
	// fmuls f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 * f30.f64));
	// lfs f31,11368(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11368);
	f31.f64 = double(temp.f32);
	// fsubs f11,f31,f12
	ctx.f11.f64 = double(float(f31.f64 - ctx.f12.f64));
	// fsel f10,f11,f31,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f31.f64 : ctx.f12.f64;
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsel f1,f9,f10,f0
	ctx.f1.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// bl 0x82744e98
	ctx.lr = 0x82745C7C;
	sub_82744E98(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82745da0
	if (cr6.eq) goto loc_82745DA0;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745ac0
	ctx.lr = 0x82745C94;
	sub_82745AC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82745da0
	if (cr6.eq) goto loc_82745DA0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82744e98
	ctx.lr = 0x82745CAC;
	sub_82744E98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82745da0
	if (cr6.eq) goto loc_82745DA0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745ac0
	ctx.lr = 0x82745CC4;
	sub_82745AC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82745da0
	if (cr6.eq) goto loc_82745DA0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bcb68
	ctx.lr = 0x82745CD8;
	sub_822BCB68(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822be478
	ctx.lr = 0x82745CEC;
	sub_822BE478(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822be478
	ctx.lr = 0x82745CFC;
	sub_822BE478(ctx, base);
	// lwz r3,1700(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1700);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82745D10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ba068
	ctx.lr = 0x82745D18;
	sub_822BA068(ctx, base);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v127,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822b9fc0
	ctx.lr = 0x82745D38;
	sub_822B9FC0(ctx, base);
	// lwz r3,1700(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1700);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,68(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 68);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82745D4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221d030
	ctx.lr = 0x82745D54;
	sub_8221D030(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x82745D5C;
	sub_822A8108(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,184(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,1696(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 1696, temp.u32);
	// b 0x82745da4
	goto loc_82745DA4;
loc_82745DA0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82745DA4:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_82745DC8"))) PPC_WEAK_FUNC(sub_82745DC8);
PPC_FUNC_IMPL(__imp__sub_82745DC8) {
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
	ctx.lr = 0x82745DD0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,1648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// bne cr6,0x82745ed4
	if (!cr6.eq) goto loc_82745ED4;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// stw r10,1648(r31)
	PPC_STORE_U32(r31.u32 + 1648, ctx.r10.u32);
	// bne cr6,0x82745eac
	if (!cr6.eq) goto loc_82745EAC;
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// lbz r9,1660(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1660);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r11,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, r11.u32);
	// beq cr6,0x82745e20
	if (cr6.eq) goto loc_82745E20;
	// lwz r9,1584(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1584);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82745e20
	if (cr6.lt) goto loc_82745E20;
	// stw r10,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, ctx.r10.u32);
loc_82745E20:
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// lwz r9,1584(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1584);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x82745e90
	if (!cr6.lt) goto loc_82745E90;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82745e48
	if (!cr6.eq) goto loc_82745E48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827458d8
	ctx.lr = 0x82745E40;
	sub_827458D8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82745E48:
	// stw r29,1700(r31)
	PPC_STORE_U32(r31.u32 + 1700, r29.u32);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r27,r31,1704
	r27.s64 = r31.s64 + 1704;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x82745E60;
	sub_822A8108(ctx, base);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82745E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745590
	ctx.lr = 0x82745E88;
	sub_82745590(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82745E90:
	// stw r10,1584(r31)
	PPC_STORE_U32(r31.u32 + 1584, ctx.r10.u32);
	// li r11,6
	r11.s64 = 6;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
	// stw r10,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82745EAC:
	// cmpwi cr6,r4,5
	cr6.compare<int32_t>(ctx.r4.s32, 5, xer);
	// bne cr6,0x82745ecc
	if (!cr6.eq) goto loc_82745ECC;
	// lwz r11,1708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1708);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x82745ed4
	if (!cr6.eq) goto loc_82745ED4;
	// stw r10,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82745ECC:
	// li r11,4
	r11.s64 = 4;
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
loc_82745ED4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82745EDC"))) PPC_WEAK_FUNC(sub_82745EDC);
PPC_FUNC_IMPL(__imp__sub_82745EDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82745EE0"))) PPC_WEAK_FUNC(sub_82745EE0);
PPC_FUNC_IMPL(__imp__sub_82745EE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// bl 0x82744bb8
	ctx.lr = 0x82745F04;
	sub_82744BB8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82745fb8
	if (cr6.eq) goto loc_82745FB8;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745958
	ctx.lr = 0x82745F24;
	sub_82745958(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82745fb8
	if (cr6.eq) goto loc_82745FB8;
	// lwz r3,1700(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1700);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82745F44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,1664(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1664);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82745f5c
	if (!cr6.gt) goto loc_82745F5C;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_82745F5C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lfs f1,7444(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r6,2272
	ctx.r6.s64 = ctx.r6.s64 + 2272;
	// lfs f2,30712(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a9930
	ctx.lr = 0x82745FB0;
	sub_822A9930(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82745fc4
	goto loc_82745FC4;
loc_82745FB8:
	// li r11,4
	r11.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
loc_82745FC4:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82745FE0"))) PPC_WEAK_FUNC(sub_82745FE0);
PPC_FUNC_IMPL(__imp__sub_82745FE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x827458d8
	sub_827458D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82745FEC"))) PPC_WEAK_FUNC(sub_82745FEC);
PPC_FUNC_IMPL(__imp__sub_82745FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82745FF0"))) PPC_WEAK_FUNC(sub_82745FF0);
PPC_FUNC_IMPL(__imp__sub_82745FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// li r9,560
	ctx.r9.s64 = 560;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stw r8,1584(r5)
	PPC_STORE_U32(ctx.r5.u32 + 1584, ctx.r8.u32);
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
	// stvx128 v63,r5,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,1656(r5)
	PPC_STORE_U32(ctx.r5.u32 + 1656, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82746038"))) PPC_WEAK_FUNC(sub_82746038);
PPC_FUNC_IMPL(__imp__sub_82746038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,1632
	ctx.r10.s64 = 1632;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
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
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r5,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827460A4"))) PPC_WEAK_FUNC(sub_827460A4);
PPC_FUNC_IMPL(__imp__sub_827460A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827460A8"))) PPC_WEAK_FUNC(sub_827460A8);
PPC_FUNC_IMPL(__imp__sub_827460A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r10,r11,560
	ctx.r10.s64 = r11.s64 + 560;
	// lwz r9,1584(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 1584);
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stw r5,1584(r11)
	PPC_STORE_U32(r11.u32 + 1584, ctx.r5.u32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,1656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1656);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x82746100
	if (!cr6.lt) goto loc_82746100;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82746100:
	// stw r10,1656(r11)
	PPC_STORE_U32(r11.u32 + 1656, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82746108"))) PPC_WEAK_FUNC(sub_82746108);
PPC_FUNC_IMPL(__imp__sub_82746108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82744bb8
	ctx.lr = 0x82746124;
	sub_82744BB8(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x8274612C;
	sub_822A8108(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x82746174;
	sub_822A8108(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lwz r11,-10012(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274620c
	if (cr6.eq) goto loc_8274620C;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd068
	ctx.lr = 0x82746190;
	sub_826FD068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274620c
	if (cr6.eq) goto loc_8274620C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745b90
	ctx.lr = 0x827461A4;
	sub_82745B90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827461b8
	if (cr6.eq) goto loc_827461B8;
	// li r11,1
	r11.s64 = 1;
	// b 0x82746210
	goto loc_82746210;
loc_827461B8:
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8274620c
	if (cr6.lt) goto loc_8274620C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bcb68
	ctx.lr = 0x827461CC;
	sub_822BCB68(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r31,560
	ctx.r4.s64 = r31.s64 + 560;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822be478
	ctx.lr = 0x827461E0;
	sub_822BE478(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822ba068
	ctx.lr = 0x827461F4;
	sub_822BA068(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8221d030
	ctx.lr = 0x82746200;
	sub_8221D030(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, ctx.r9.u32);
	// b 0x82746214
	goto loc_82746214;
loc_8274620C:
	// li r11,4
	r11.s64 = 4;
loc_82746210:
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
loc_82746214:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

__attribute__((alias("__imp__sub_8274622C"))) PPC_WEAK_FUNC(sub_8274622C);
PPC_FUNC_IMPL(__imp__sub_8274622C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82746230"))) PPC_WEAK_FUNC(sub_82746230);
PPC_FUNC_IMPL(__imp__sub_82746230) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x8274624C;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82745ee0
	ctx.lr = 0x8274625C;
	sub_82745EE0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82746270
	if (cr6.eq) goto loc_82746270;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745590
	ctx.lr = 0x82746270;
	sub_82745590(ctx, base);
loc_82746270:
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

__attribute__((alias("__imp__sub_82746284"))) PPC_WEAK_FUNC(sub_82746284);
PPC_FUNC_IMPL(__imp__sub_82746284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82746288"))) PPC_WEAK_FUNC(sub_82746288);
PPC_FUNC_IMPL(__imp__sub_82746288) {
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
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// addi r11,r11,35
	r11.s64 = r11.s64 + 35;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82745ee0
	ctx.lr = 0x827462B4;
	sub_82745EE0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274632c
	if (cr6.eq) goto loc_8274632C;
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r9,1660(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1660);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r11,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, r11.u32);
	// beq cr6,0x827462ec
	if (cr6.eq) goto loc_827462EC;
	// lwz r9,1584(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1584);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x827462ec
	if (cr6.lt) goto loc_827462EC;
	// stw r10,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, ctx.r10.u32);
loc_827462EC:
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// lwz r9,1584(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1584);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x82746318
	if (!cr6.lt) goto loc_82746318;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745590
	ctx.lr = 0x82746304;
	sub_82745590(ctx, base);
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
loc_82746318:
	// stw r10,1584(r31)
	PPC_STORE_U32(r31.u32 + 1584, ctx.r10.u32);
	// li r11,6
	r11.s64 = 6;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
	// stw r10,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, ctx.r10.u32);
loc_8274632C:
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

__attribute__((alias("__imp__sub_82746340"))) PPC_WEAK_FUNC(sub_82746340);
PPC_FUNC_IMPL(__imp__sub_82746340) {
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
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
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
	// bl 0x823d91f8
	ctx.lr = 0x82746348;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9ac
	ctx.lr = 0x82746350;
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,1708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1708);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x8274642c
	if (!cr6.eq) goto loc_8274642C;
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827463ec
	if (cr6.eq) goto loc_827463EC;
	// addi r11,r11,35
	r11.s64 = r11.s64 + 35;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82745ee0
	ctx.lr = 0x8274638C;
	sub_82745EE0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827469bc
	if (cr6.eq) goto loc_827469BC;
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r9,1660(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1660);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r11,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, r11.u32);
	// beq cr6,0x827463c4
	if (cr6.eq) goto loc_827463C4;
	// lwz r9,1584(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1584);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x827463c4
	if (cr6.lt) goto loc_827463C4;
	// stw r10,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, ctx.r10.u32);
loc_827463C4:
	// lwz r11,1656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// lwz r9,1584(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1584);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82746420
	if (cr6.lt) goto loc_82746420;
	// stw r10,1584(r31)
	PPC_STORE_U32(r31.u32 + 1584, ctx.r10.u32);
	// li r11,6
	r11.s64 = 6;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
	// stw r10,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, ctx.r10.u32);
	// b 0x827469bc
	goto loc_827469BC;
loc_827463EC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f0,192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 192);
	f0.f64 = double(temp.f32);
	// lfs f13,196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 196);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,200(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 200);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82745ee0
	ctx.lr = 0x82746414;
	sub_82745EE0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827469bc
	if (cr6.eq) goto loc_827469BC;
loc_82746420:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745590
	ctx.lr = 0x82746428;
	sub_82745590(ctx, base);
	// b 0x827469bc
	goto loc_827469BC;
loc_8274642C:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274652c
	if (!cr6.eq) goto loc_8274652C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82746520
	if (cr6.eq) goto loc_82746520;
	// lhz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827464ac
	if (cr6.eq) goto loc_827464AC;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// li r9,-32
	ctx.r9.s64 = -32;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r8,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x82746470;
	sub_822A8108(ctx, base);
	// addi r6,r3,48
	ctx.r6.s64 = ctx.r3.s64 + 48;
	// lfs f0,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	f0.f64 = double(temp.f32);
	// lfs f13,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f13,f3
	ctx.f13.f64 = double(float(sqrt(ctx.f3.f64)));
	// b 0x827464b4
	goto loc_827464B4;
loc_827464AC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
loc_827464B4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,1696(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1696);
	f0.f64 = double(temp.f32);
	// lfs f12,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 + ctx.f12.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x827464ec
	if (!cr6.gt) goto loc_827464EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745b90
	ctx.lr = 0x827464D4;
	sub_82745B90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827464f8
	if (!cr6.eq) goto loc_827464F8;
	// li r11,4
	r11.s64 = 4;
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
	// b 0x827469bc
	goto loc_827469BC;
loc_827464EC:
	// fsubs f12,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,1696(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 1696, temp.u32);
loc_827464F8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822be670
	ctx.lr = 0x82746500;
	sub_822BE670(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b9f70
	ctx.lr = 0x82746508;
	sub_822B9F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827469bc
	if (cr6.eq) goto loc_827469BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745590
	ctx.lr = 0x8274651C;
	sub_82745590(ctx, base);
	// b 0x827469bc
	goto loc_827469BC;
loc_82746520:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82746524:
	// bl 0x82746230
	ctx.lr = 0x82746528;
	sub_82746230(ctx, base);
	// b 0x827469bc
	goto loc_827469BC;
loc_8274652C:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82746570
	if (!cr6.eq) goto loc_82746570;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82746524
	if (cr6.eq) goto loc_82746524;
	// bl 0x82745b90
	ctx.lr = 0x8274654C;
	sub_82745B90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82746564
	if (cr6.eq) goto loc_82746564;
	// li r11,1
	r11.s64 = 1;
	// stw r11,1708(r31)
	PPC_STORE_U32(r31.u32 + 1708, r11.u32);
	// b 0x827469bc
	goto loc_827469BC;
loc_82746564:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822be670
	ctx.lr = 0x8274656C;
	sub_822BE670(ctx, base);
	// b 0x827469bc
	goto loc_827469BC;
loc_82746570:
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x82746994
	if (!cr6.eq) goto loc_82746994;
	// lwz r30,1648(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,412(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 412);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82746614
	if (cr6.eq) goto loc_82746614;
	// lwz r11,188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82746614
	if (cr6.eq) goto loc_82746614;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827465b4
	if (cr6.eq) goto loc_827465B4;
	// lwz r4,188(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// b 0x827465b8
	goto loc_827465B8;
loc_827465B4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_827465B8:
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827465cc
	if (cr6.eq) goto loc_827465CC;
	// lfs f1,208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	ctx.f1.f64 = double(temp.f32);
	// b 0x827465d0
	goto loc_827465D0;
loc_827465CC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_827465D0:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827465E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82745208
	ctx.lr = 0x82746608;
	sub_82745208(ctx, base);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8274663c
	goto loc_8274663C;
loc_82746614:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8273bac0
	ctx.lr = 0x8274661C;
	sub_8273BAC0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826ddd90
	ctx.lr = 0x82746630;
	sub_826DDD90(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8274663C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f24,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f24.f64 = double(temp.f32);
	// stfs f24,144(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f22,31292(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31292);
	f22.f64 = double(temp.f32);
	// fmr f1,f22
	ctx.f1.f64 = f22.f64;
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x82746670;
	sub_82165300(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827468f0
	if (cr6.eq) goto loc_827468F0;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8274669c
	if (cr6.eq) goto loc_8274669C;
	// addi r30,r11,272
	r30.s64 = r11.s64 + 272;
	// b 0x827466a4
	goto loc_827466A4;
loc_8274669C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
loc_827466A4:
	// li r9,48
	ctx.r9.s64 = 48;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r11,r30,32
	r11.s64 = r30.s64 + 32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v59,r30,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v127,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v59.f32)));
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v56,v60,v57
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v57.f32)));
	// lfs f0,31016(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f28,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f28.f64 = double(temp.f32);
	// stvx128 v56,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f29,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f29.f64 = double(temp.f32);
	// fmuls f13,f29,f29
	ctx.f13.f64 = double(float(f29.f64 * f29.f64));
	// fmadds f12,f28,f28,f13
	ctx.f12.f64 = double(float(f28.f64 * f28.f64 + ctx.f13.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x827466fc
	if (!cr6.gt) goto loc_827466FC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82746108
	ctx.lr = 0x827466F8;
	sub_82746108(ctx, base);
	// b 0x8274697c
	goto loc_8274697C;
loc_827466FC:
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r7,104(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// lfs f0,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lwz r11,128(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 128);
	// lfs f10,48(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f8,276(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 276);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// lfs f6,280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,272(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f5.f64 = double(temp.f32);
	// fcmpu cr6,f30,f9
	cr6.compare(f30.f64, ctx.f9.f64);
	// fmadds f4,f12,f6,f7
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f6.f64 + ctx.f7.f64));
	// fnmadds f23,f5,f11,f4
	f23.f64 = double(float(-(ctx.f5.f64 * ctx.f11.f64 + ctx.f4.f64)));
	// ble cr6,0x827468e0
	if (!cr6.gt) goto loc_827468E0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r28,r10,29952
	r28.s64 = ctx.r10.s64 + 29952;
	// addi r29,r31,1616
	r29.s64 = r31.s64 + 1616;
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// fsubs f11,f0,f30
	ctx.f11.f64 = double(float(f0.f64 - f30.f64));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f12,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f21,f13,f30
	f21.f64 = double(float(ctx.f13.f64 * f30.f64));
	// fsel f20,f11,f0,f30
	f20.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : f30.f64;
	// fmuls f19,f20,f12
	f19.f64 = double(float(f20.f64 * ctx.f12.f64));
	// bl 0x8216c9c0
	ctx.lr = 0x82746784;
	sub_8216C9C0(ctx, base);
	// lfs f10,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fmr f18,f1
	f18.f64 = ctx.f1.f64;
	// fmuls f9,f10,f28
	ctx.f9.f64 = double(float(ctx.f10.f64 * f28.f64));
	// lfs f8,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f27,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f27.f64 = double(temp.f32);
	// fmr f2,f19
	ctx.f2.f64 = f19.f64;
	// lfs f7,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f8,f27,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 * f27.f64 + ctx.f9.f64));
	// fmadds f5,f29,f7,f6
	ctx.f5.f64 = double(float(f29.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fneg f1,f5
	ctx.f1.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// bl 0x823dcdd8
	ctx.lr = 0x827467B0;
	sub_823DCDD8(ctx, base);
	// lfs f26,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f26.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f25,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f25.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f26,96(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// frsp f17,f1
	f17.f64 = double(float(ctx.f1.f64));
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmr f1,f22
	ctx.f1.f64 = f22.f64;
	// stfs f25,104(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f24,112(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x827467E8;
	sub_82165300(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8148
	ctx.lr = 0x827467F0;
	sub_822A8148(ctx, base);
	// lfs f22,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f22.f64 = double(temp.f32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8148
	ctx.lr = 0x827467FC;
	sub_822A8148(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f22,120(r1)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// lfs f4,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,112(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v1,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x82746824;
	sub_82165300(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8254ad68
	ctx.lr = 0x82746830;
	sub_8254AD68(ctx, base);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f3,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f3.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lfs f2,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmuls f0,f2,f3
	f0.f64 = double(float(ctx.f2.f64 * ctx.f3.f64));
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,48(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,1688(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1688);
	ctx.f9.f64 = double(temp.f32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// fmadds f8,f12,f13,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + f0.f64));
	// lwz r9,128(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lfs f7,292(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 292);
	ctx.f7.f64 = double(temp.f32);
	// fdivs f6,f7,f20
	ctx.f6.f64 = double(float(ctx.f7.f64 / f20.f64));
	// fmadds f5,f10,f11,f8
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fsubs f31,f9,f6
	f31.f64 = double(float(ctx.f9.f64 - ctx.f6.f64));
	// fmuls f24,f1,f5
	f24.f64 = double(float(ctx.f1.f64 * ctx.f5.f64));
	// bl 0x8254ad68
	ctx.lr = 0x82746884;
	sub_8254AD68(ctx, base);
	// fadds f4,f24,f17
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f24.f64 + f17.f64));
	// fadds f3,f4,f18
	ctx.f3.f64 = double(float(ctx.f4.f64 + f18.f64));
	// fdivs f1,f1,f21
	ctx.f1.f64 = double(float(ctx.f1.f64 / f21.f64));
	// lfs f2,1672(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1672);
	ctx.f2.f64 = double(temp.f32);
	// fdivs f9,f3,f19
	ctx.f9.f64 = double(float(ctx.f3.f64 / f19.f64));
	// lfs f0,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	f0.f64 = double(temp.f32);
	// fmuls f12,f28,f25
	ctx.f12.f64 = double(float(f28.f64 * f25.f64));
	// stfs f1,1688(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1688, temp.u32);
	// fsubs f11,f30,f2
	ctx.f11.f64 = double(float(f30.f64 - ctx.f2.f64));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// fsubs f10,f2,f23
	ctx.f10.f64 = double(float(ctx.f2.f64 - f23.f64));
	// lfs f13,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fadds f7,f9,f1
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f1.f64));
	// fmadds f8,f0,f27,f12
	ctx.f8.f64 = double(float(f0.f64 * f27.f64 + ctx.f12.f64));
	// fadds f5,f7,f31
	ctx.f5.f64 = double(float(ctx.f7.f64 + f31.f64));
	// stfs f5,1680(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 1680, temp.u32);
	// lfs f0,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmadds f6,f29,f26,f8
	ctx.f6.f64 = double(float(f29.f64 * f26.f64 + ctx.f8.f64));
	// fdivs f4,f11,f0
	ctx.f4.f64 = double(float(ctx.f11.f64 / f0.f64));
	// fmadds f3,f6,f13,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f4.f64));
	// fadds f2,f3,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f10.f64));
	// stfs f2,1676(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 1676, temp.u32);
	// b 0x8274697c
	goto loc_8274697C;
loc_827468E0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3800);
	f0.f64 = double(temp.f32);
	// stfs f0,1676(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1676, temp.u32);
	// b 0x8274697c
	goto loc_8274697C;
loc_827468F0:
	// li r11,1
	r11.s64 = 1;
	// stb r11,464(r10)
	PPC_STORE_U8(ctx.r10.u32 + 464, r11.u8);
	// lwz r3,1648(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// bl 0x82794ee8
	ctx.lr = 0x82746900;
	sub_82794EE8(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r11,288
	r11.s64 = r11.s64 + 288;
	// lvx128 v55,r0,r3
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// fneg f0,f30
	ctx.fpscr.disableFlushMode();
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// li r30,32
	r30.s64 = 32;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r3,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r3,r30
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r3,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,1648(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// lvlx128 v54,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v127,v54,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// bl 0x82794ee8
	ctx.lr = 0x82746950;
	sub_82794EE8(ctx, base);
	// lvx128 v50,r3,r30
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// vmulfp128 v49,v50,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v127.f32)));
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,432
	ctx.r5.s64 = 432;
	// addi r4,r7,2272
	ctx.r4.s64 = ctx.r7.s64 + 2272;
	// li r3,448
	ctx.r3.s64 = 448;
	// stvx128 v49,r6,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8274697C:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stfs f30,1672(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 1672, temp.u32);
	// li r10,1616
	ctx.r10.s64 = 1616;
	// lvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x827469bc
	goto loc_827469BC;
loc_82746994:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,1680(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1680, temp.u32);
	// bne cr6,0x827469b0
	if (!cr6.eq) goto loc_827469B0;
	// stfs f0,1676(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1676, temp.u32);
	// b 0x827469bc
	goto loc_827469BC;
loc_827469B0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,3800(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3800);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,1676(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1676, temp.u32);
loc_827469BC:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9f8
	ctx.lr = 0x827469D0;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827469D4"))) PPC_WEAK_FUNC(sub_827469D4);
PPC_FUNC_IMPL(__imp__sub_827469D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827469D8"))) PPC_WEAK_FUNC(sub_827469D8);
PPC_FUNC_IMPL(__imp__sub_827469D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82746108
	sub_82746108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827469E4"))) PPC_WEAK_FUNC(sub_827469E4);
PPC_FUNC_IMPL(__imp__sub_827469E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827469E8"))) PPC_WEAK_FUNC(sub_827469E8);
PPC_FUNC_IMPL(__imp__sub_827469E8) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x82746A08;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82745ee0
	ctx.lr = 0x82746A18;
	sub_82745EE0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82746a2c
	if (cr6.eq) goto loc_82746A2C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82745590
	ctx.lr = 0x82746A2C;
	sub_82745590(ctx, base);
loc_82746A2C:
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

__attribute__((alias("__imp__sub_82746A40"))) PPC_WEAK_FUNC(sub_82746A40);
PPC_FUNC_IMPL(__imp__sub_82746A40) {
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
	// b 0x82746288
	sub_82746288(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82746A54"))) PPC_WEAK_FUNC(sub_82746A54);
PPC_FUNC_IMPL(__imp__sub_82746A54) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82746A58"))) PPC_WEAK_FUNC(sub_82746A58);
PPC_FUNC_IMPL(__imp__sub_82746A58) {
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
	// addi r4,r11,27096
	ctx.r4.s64 = r11.s64 + 27096;
	// addi r3,r10,-3912
	ctx.r3.s64 = ctx.r10.s64 + -3912;
	// bl 0x82554798
	ctx.lr = 0x82746A78;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,24544
	ctx.r4.s64 = ctx.r9.s64 + 24544;
	// addi r3,r8,-3948
	ctx.r3.s64 = ctx.r8.s64 + -3948;
	// bl 0x82554798
	ctx.lr = 0x82746A8C;
	sub_82554798(ctx, base);
	// lis r7,-32140
	ctx.r7.s64 = -2106327040;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,27112
	ctx.r4.s64 = ctx.r7.s64 + 27112;
	// addi r3,r6,-3984
	ctx.r3.s64 = ctx.r6.s64 + -3984;
	// bl 0x82554798
	ctx.lr = 0x82746AA0;
	sub_82554798(ctx, base);
	// lis r5,-32140
	ctx.r5.s64 = -2106327040;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,22512
	ctx.r4.s64 = ctx.r5.s64 + 22512;
	// addi r3,r3,-4016
	ctx.r3.s64 = ctx.r3.s64 + -4016;
	// bl 0x82554798
	ctx.lr = 0x82746AB4;
	sub_82554798(ctx, base);
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,24560
	ctx.r4.s64 = r11.s64 + 24560;
	// addi r3,r10,-4048
	ctx.r3.s64 = ctx.r10.s64 + -4048;
	// bl 0x82554798
	ctx.lr = 0x82746AC8;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,22576
	ctx.r4.s64 = ctx.r9.s64 + 22576;
	// addi r3,r8,-4080
	ctx.r3.s64 = ctx.r8.s64 + -4080;
	// bl 0x82554798
	ctx.lr = 0x82746ADC;
	sub_82554798(ctx, base);
	// lis r7,-32140
	ctx.r7.s64 = -2106327040;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,24632
	ctx.r4.s64 = ctx.r7.s64 + 24632;
	// addi r3,r6,-4104
	ctx.r3.s64 = ctx.r6.s64 + -4104;
	// bl 0x82554798
	ctx.lr = 0x82746AF0;
	sub_82554798(ctx, base);
	// lis r5,-32140
	ctx.r5.s64 = -2106327040;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,22616
	ctx.r4.s64 = ctx.r5.s64 + 22616;
	// addi r3,r3,-4128
	ctx.r3.s64 = ctx.r3.s64 + -4128;
	// bl 0x82554798
	ctx.lr = 0x82746B04;
	sub_82554798(ctx, base);
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,22640
	ctx.r4.s64 = r11.s64 + 22640;
	// addi r3,r10,-4156
	ctx.r3.s64 = ctx.r10.s64 + -4156;
	// bl 0x82554798
	ctx.lr = 0x82746B18;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,24744
	ctx.r4.s64 = ctx.r9.s64 + 24744;
	// addi r3,r8,-4184
	ctx.r3.s64 = ctx.r8.s64 + -4184;
	// bl 0x82554798
	ctx.lr = 0x82746B2C;
	sub_82554798(ctx, base);
	// lis r7,-32140
	ctx.r7.s64 = -2106327040;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,22664
	ctx.r4.s64 = ctx.r7.s64 + 22664;
	// addi r3,r6,-4212
	ctx.r3.s64 = ctx.r6.s64 + -4212;
	// bl 0x82554798
	ctx.lr = 0x82746B40;
	sub_82554798(ctx, base);
	// lis r5,-32140
	ctx.r5.s64 = -2106327040;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,22696
	ctx.r4.s64 = ctx.r5.s64 + 22696;
	// addi r3,r3,-4256
	ctx.r3.s64 = ctx.r3.s64 + -4256;
	// bl 0x82554798
	ctx.lr = 0x82746B54;
	sub_82554798(ctx, base);
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,27200
	ctx.r4.s64 = r11.s64 + 27200;
	// addi r3,r10,-4296
	ctx.r3.s64 = ctx.r10.s64 + -4296;
	// bl 0x82554798
	ctx.lr = 0x82746B68;
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

__attribute__((alias("__imp__sub_82746B78"))) PPC_WEAK_FUNC(sub_82746B78);
PPC_FUNC_IMPL(__imp__sub_82746B78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82746B80;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9bc
	ctx.lr = 0x82746B88;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,-1
	r11.s64 = -1;
	// stfs f31,92(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f31,96(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// addi r29,r31,1412
	r29.s64 = r31.s64 + 1412;
	// stfs f31,100(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// stfs f31,104(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stb r30,193(r31)
	PPC_STORE_U8(r31.u32 + 193, r30.u8);
	// stb r30,289(r31)
	PPC_STORE_U8(r31.u32 + 289, r30.u8);
	// lfs f28,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f28.f64 = double(temp.f32);
	// stb r30,385(r31)
	PPC_STORE_U8(r31.u32 + 385, r30.u8);
	// lfs f29,15000(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15000);
	f29.f64 = double(temp.f32);
	// stb r30,481(r31)
	PPC_STORE_U8(r31.u32 + 481, r30.u8);
	// lfs f30,14988(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14988);
	f30.f64 = double(temp.f32);
	// stb r30,577(r31)
	PPC_STORE_U8(r31.u32 + 577, r30.u8);
	// stb r30,673(r31)
	PPC_STORE_U8(r31.u32 + 673, r30.u8);
	// stb r30,769(r31)
	PPC_STORE_U8(r31.u32 + 769, r30.u8);
	// stb r30,865(r31)
	PPC_STORE_U8(r31.u32 + 865, r30.u8);
	// stw r11,924(r31)
	PPC_STORE_U32(r31.u32 + 924, r11.u32);
	// stw r11,988(r31)
	PPC_STORE_U32(r31.u32 + 988, r11.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(r31.u32 + 1052, r11.u32);
	// stw r11,1116(r31)
	PPC_STORE_U32(r31.u32 + 1116, r11.u32);
	// stw r11,1180(r31)
	PPC_STORE_U32(r31.u32 + 1180, r11.u32);
	// stw r11,1244(r31)
	PPC_STORE_U32(r31.u32 + 1244, r11.u32);
	// stw r11,1308(r31)
	PPC_STORE_U32(r31.u32 + 1308, r11.u32);
	// stw r11,1372(r31)
	PPC_STORE_U32(r31.u32 + 1372, r11.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r30,880(r31)
	PPC_STORE_U32(r31.u32 + 880, r30.u32);
	// stb r30,920(r31)
	PPC_STORE_U8(r31.u32 + 920, r30.u8);
	// stb r30,921(r31)
	PPC_STORE_U8(r31.u32 + 921, r30.u8);
	// stw r30,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r30.u32);
	// stb r30,984(r31)
	PPC_STORE_U8(r31.u32 + 984, r30.u8);
	// stb r30,985(r31)
	PPC_STORE_U8(r31.u32 + 985, r30.u8);
	// stw r30,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, r30.u32);
	// stb r30,1048(r31)
	PPC_STORE_U8(r31.u32 + 1048, r30.u8);
	// stb r30,1049(r31)
	PPC_STORE_U8(r31.u32 + 1049, r30.u8);
	// stw r30,1072(r31)
	PPC_STORE_U32(r31.u32 + 1072, r30.u32);
	// stb r30,1112(r31)
	PPC_STORE_U8(r31.u32 + 1112, r30.u8);
	// stb r30,1113(r31)
	PPC_STORE_U8(r31.u32 + 1113, r30.u8);
	// stw r30,1136(r31)
	PPC_STORE_U32(r31.u32 + 1136, r30.u32);
	// stb r30,1176(r31)
	PPC_STORE_U8(r31.u32 + 1176, r30.u8);
	// stb r30,1177(r31)
	PPC_STORE_U8(r31.u32 + 1177, r30.u8);
	// stw r30,1200(r31)
	PPC_STORE_U32(r31.u32 + 1200, r30.u32);
	// stb r30,1240(r31)
	PPC_STORE_U8(r31.u32 + 1240, r30.u8);
	// stb r30,1241(r31)
	PPC_STORE_U8(r31.u32 + 1241, r30.u8);
	// stw r30,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, r30.u32);
	// stb r30,1304(r31)
	PPC_STORE_U8(r31.u32 + 1304, r30.u8);
	// stb r30,1305(r31)
	PPC_STORE_U8(r31.u32 + 1305, r30.u8);
	// stw r30,1328(r31)
	PPC_STORE_U32(r31.u32 + 1328, r30.u32);
	// stb r30,1368(r31)
	PPC_STORE_U8(r31.u32 + 1368, r30.u8);
	// stb r30,1369(r31)
	PPC_STORE_U8(r31.u32 + 1369, r30.u8);
loc_82746C74:
	// stfs f30,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f31,4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f31,8(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f31,12(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f31,16(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stfs f29,20(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stfs f28,24(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// addi r11,r11,28
	r11.s64 = r11.s64 + 28;
	// bge 0x82746c74
	if (!cr0.lt) goto loc_82746C74;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r27,r11,-3380
	r27.s64 = r11.s64 + -3380;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -24728);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82746CC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
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
	ctx.lr = 0x82746CFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-23544
	ctx.r4.s64 = ctx.r10.s64 + -23544;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82746D14;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-3396
	ctx.r4.s64 = ctx.r8.s64 + -3396;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82746D30;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-3412
	ctx.r4.s64 = ctx.r4.s64 + -3412;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82746D4C;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r3,-3424
	ctx.r4.s64 = ctx.r3.s64 + -3424;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82746D68;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-3436
	ctx.r4.s64 = ctx.r9.s64 + -3436;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82746D84;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-3448
	ctx.r4.s64 = ctx.r8.s64 + -3448;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x82746DA0;
	sub_8218B688(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lwz r3,-24728(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -24728);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r27,r6,-3468
	r27.s64 = ctx.r6.s64 + -3468;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82746DCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
	ctx.lr = 0x82746E00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-3480
	ctx.r4.s64 = ctx.r10.s64 + -3480;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82746E18;
	sub_8218A568(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-3492
	ctx.r4.s64 = ctx.r8.s64 + -3492;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82746E34;
	sub_8218A568(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// lfs f0,29992(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 29992);
	f0.f64 = double(temp.f32);
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lfs f0,14908(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14908);
	f0.f64 = double(temp.f32);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lfs f13,-3496(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -3496);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// lfs f12,14900(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14900);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32245
	ctx.r4.s64 = -2113208320;
	// lfs f11,-10992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -10992);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,17344(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17344);
	f0.f64 = double(temp.f32);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stfs f12,104(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// stfs f11,40(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lfs f13,17340(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17340);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17336(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17336);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f12,56(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// lfs f0,17332(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17332);
	f0.f64 = double(temp.f32);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lfs f13,17328(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17328);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lfs f12,17324(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17324);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f12,72(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// lfs f0,3732(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,27532(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27532);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,27640(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 27640);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-3500(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3500);
	ctx.f10.f64 = double(temp.f32);
	// stfs f31,1408(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1408, temp.u32);
	// stfs f0,1392(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1392, temp.u32);
	// stfs f13,1396(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// stfs f12,1400(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1400, temp.u32);
	// stfs f11,1404(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 1404, temp.u32);
	// stfs f30,0(r29)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// stfs f31,1420(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1420, temp.u32);
	// stfs f31,1424(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1424, temp.u32);
	// stfs f31,1416(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1416, temp.u32);
	// stfs f31,1472(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1472, temp.u32);
	// stfs f28,1436(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 1436, temp.u32);
	// stfs f29,1432(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 1432, temp.u32);
	// lfs f9,-6172(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -6172);
	ctx.f9.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f8,-15956(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -15956);
	ctx.f8.f64 = double(temp.f32);
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// lfs f7,-3504(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -3504);
	ctx.f7.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,-3072(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -3072);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// stfs f30,1444(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 1444, temp.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lfs f0,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lfs f6,-3508(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -3508);
	ctx.f6.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f5,-3512(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3512);
	ctx.f5.f64 = double(temp.f32);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lfs f4,29976(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29976);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,-3516(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3516);
	ctx.f3.f64 = double(temp.f32);
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// lfs f2,-3520(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -3520);
	ctx.f2.f64 = double(temp.f32);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// lfs f12,-3524(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3524);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f1,3728(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3728);
	ctx.f1.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f31,-3528(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -3528);
	f31.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lfs f27,-3532(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -3532);
	f27.f64 = double(temp.f32);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lfs f11,-25180(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -25180);
	ctx.f11.f64 = double(temp.f32);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lfs f26,23092(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 23092);
	f26.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f25,-13008(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13008);
	f25.f64 = double(temp.f32);
	// lfs f24,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f24.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f23,-3536(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -3536);
	f23.f64 = double(temp.f32);
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// lfs f22,-3540(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3540);
	f22.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f21,-3544(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -3544);
	f21.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stfs f0,1464(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1464, temp.u32);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// stfs f0,1492(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1492, temp.u32);
	// stfs f0,1520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1520, temp.u32);
	// stfs f0,1576(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1576, temp.u32);
	// stfs f0,1604(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1604, temp.u32);
	// lfs f0,12424(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12424);
	f0.f64 = double(temp.f32);
	// stfs f10,1428(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 1428, temp.u32);
	// stfs f9,1440(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 1440, temp.u32);
	// stfs f8,1448(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 1448, temp.u32);
	// stfs f7,1452(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 1452, temp.u32);
	// stfs f13,1456(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1456, temp.u32);
	// stfs f6,1460(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 1460, temp.u32);
	// stfs f5,1468(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 1468, temp.u32);
	// stfs f4,1476(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 1476, temp.u32);
	// stfs f3,1480(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 1480, temp.u32);
	// stfs f13,1484(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1484, temp.u32);
	// stfs f2,1488(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 1488, temp.u32);
	// stfs f12,1496(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1496, temp.u32);
	// stfs f1,1504(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1504, temp.u32);
	// stfs f12,1508(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1508, temp.u32);
	// stfs f31,1500(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1500, temp.u32);
	// stfs f13,1512(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1512, temp.u32);
	// stfs f27,1516(r31)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r31.u32 + 1516, temp.u32);
	// stfs f11,1524(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 1524, temp.u32);
	// stfs f26,1532(r31)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r31.u32 + 1532, temp.u32);
	// stfs f25,1536(r31)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r31.u32 + 1536, temp.u32);
	// stfs f30,1528(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 1528, temp.u32);
	// stfs f11,1540(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 1540, temp.u32);
	// stfs f28,1548(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 1548, temp.u32);
	// stfs f29,1544(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 1544, temp.u32);
	// stfs f24,1552(r31)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r31.u32 + 1552, temp.u32);
	// stfs f23,1560(r31)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(r31.u32 + 1560, temp.u32);
	// stfs f22,1564(r31)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(r31.u32 + 1564, temp.u32);
	// stfs f21,1556(r31)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(r31.u32 + 1556, temp.u32);
	// stfs f13,1596(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1596, temp.u32);
	// stfs f29,1572(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 1572, temp.u32);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lfs f13,-3548(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -3548);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3552(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3552);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-4948(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4948);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-3556(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3556);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,1568(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1568, temp.u32);
	// lfs f9,24608(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24608);
	ctx.f9.f64 = double(temp.f32);
	// stfs f13,1580(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1580, temp.u32);
	// stfs f12,1588(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1588, temp.u32);
	// stfs f11,1592(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 1592, temp.u32);
	// stfs f10,1584(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 1584, temp.u32);
	// stfs f9,1600(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 1600, temp.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba08
	ctx.lr = 0x827470A4;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827470A8"))) PPC_WEAK_FUNC(sub_827470A8);
PPC_FUNC_IMPL(__imp__sub_827470A8) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827470dc
	if (cr6.eq) goto loc_827470DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827470DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827470DC:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827470fc
	if (cr6.eq) goto loc_827470FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827470FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827470FC:
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

__attribute__((alias("__imp__sub_82747110"))) PPC_WEAK_FUNC(sub_82747110);
PPC_FUNC_IMPL(__imp__sub_82747110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82747118;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9c0
	ctx.lr = 0x82747120;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,128
	ctx.r4.s64 = 128;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x82747130;
	sub_8217BB68(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f24,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f24.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f28,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f28.f64 = double(temp.f32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f25,-3360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3360);
	f25.f64 = double(temp.f32);
	// lis r3,255
	ctx.r3.s64 = 16711680;
	// lfs f26,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	f26.f64 = double(temp.f32);
	// lfs f27,32680(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 32680);
	f27.f64 = double(temp.f32);
	// li r31,0
	r31.s64 = 0;
	// lfs f31,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// ori r30,r3,65535
	r30.u64 = ctx.r3.u64 | 65535;
	// lfs f30,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f23,-7864(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -7864);
	f23.f64 = double(temp.f32);
loc_8274717C:
	// extsw r11,r31
	r11.s64 = r31.s32;
	// fmr f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f30.f64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f23
	f0.f64 = double(float(ctx.f11.f64 * f23.f64));
	// beq cr6,0x827471a8
	if (cr6.eq) goto loc_827471A8;
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// bne cr6,0x827471ac
	if (!cr6.eq) goto loc_827471AC;
loc_827471A8:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_827471AC:
	// fsubs f12,f30,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f30.f64 - f0.f64));
	// fmuls f11,f13,f24
	ctx.f11.f64 = double(float(ctx.f13.f64 * f24.f64));
	// fmuls f22,f0,f28
	f22.f64 = double(float(f0.f64 * f28.f64));
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmadds f10,f12,f27,f26
	ctx.f10.f64 = double(float(ctx.f12.f64 * f27.f64 + f26.f64));
	// fctiwz f9,f11
	ctx.f9.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f9.u64);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rlwinm r10,r11,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF000000;
	// fmuls f29,f10,f25
	f29.f64 = double(float(ctx.f10.f64 * f25.f64));
	// or r29,r10,r30
	r29.u64 = ctx.r10.u64 | r30.u64;
	// fmr f3,f22
	ctx.f3.f64 = f22.f64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmuls f1,f29,f28
	ctx.f1.f64 = double(float(f29.f64 * f28.f64));
	// bl 0x8217bc28
	ctx.lr = 0x827471FC;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmr f8,f30
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f30.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// fmr f3,f22
	ctx.f3.f64 = f22.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82747224;
	sub_8217BC28(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,32
	cr6.compare<int32_t>(r31.s32, 32, xer);
	// blt cr6,0x8274717c
	if (cr6.lt) goto loc_8274717C;
	// li r31,0
	r31.s64 = 0;
loc_82747234:
	// extsw r11,r31
	r11.s64 = r31.s32;
	// fmr f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f30.f64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// lfd f0,104(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f23
	f0.f64 = double(float(ctx.f11.f64 * f23.f64));
	// beq cr6,0x82747260
	if (cr6.eq) goto loc_82747260;
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// bne cr6,0x82747264
	if (!cr6.eq) goto loc_82747264;
loc_82747260:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_82747264:
	// fsubs f12,f30,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f30.f64 - f0.f64));
	// fmuls f13,f13,f24
	ctx.f13.f64 = double(float(ctx.f13.f64 * f24.f64));
	// fmuls f29,f0,f28
	f29.f64 = double(float(f0.f64 * f28.f64));
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// fmadds f10,f12,f27,f26
	ctx.f10.f64 = double(float(ctx.f12.f64 * f27.f64 + f26.f64));
	// fctiwz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r10,r11,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF000000;
	// fmuls f22,f10,f25
	f22.f64 = double(float(ctx.f10.f64 * f25.f64));
	// or r29,r10,r30
	r29.u64 = ctx.r10.u64 | r30.u64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmuls f2,f22,f28
	ctx.f2.f64 = double(float(f22.f64 * f28.f64));
	// bl 0x8217bc28
	ctx.lr = 0x827472B4;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmr f8,f30
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f30.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// fmr f2,f22
	ctx.f2.f64 = f22.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// bl 0x8217bc28
	ctx.lr = 0x827472DC;
	sub_8217BC28(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,32
	cr6.compare<int32_t>(r31.s32, 32, xer);
	// blt cr6,0x82747234
	if (cr6.lt) goto loc_82747234;
	// bl 0x8217bc98
	ctx.lr = 0x827472EC;
	sub_8217BC98(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba0c
	ctx.lr = 0x827472F8;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827472FC"))) PPC_WEAK_FUNC(sub_827472FC);
PPC_FUNC_IMPL(__imp__sub_827472FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82747300"))) PPC_WEAK_FUNC(sub_82747300);
PPC_FUNC_IMPL(__imp__sub_82747300) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
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
	// bl 0x823d91fc
	ctx.lr = 0x82747308;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9a8
	ctx.lr = 0x82747310;
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,256
	ctx.r4.s64 = 256;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x82747328;
	sub_8217BB68(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f21,-3352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3352);
	f21.f64 = double(temp.f32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f22,15360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15360);
	f22.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f23,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f23.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f24,-3356(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -3356);
	f24.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f25,23948(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 23948);
	f25.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f26,-13148(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -13148);
	f26.f64 = double(temp.f32);
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// lfs f27,3732(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	f27.f64 = double(temp.f32);
	// lfs f28,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f28.f64 = double(temp.f32);
	// li r31,0
	r31.s64 = 0;
	// lfs f31,3796(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f31.f64 = double(temp.f32);
	// ori r30,r9,65535
	r30.u64 = ctx.r9.u64 | 65535;
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f19,1068(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 1068);
	f19.f64 = double(temp.f32);
loc_8274738C:
	// extsw r11,r31
	r11.s64 = r31.s32;
	// fmr f20,f30
	ctx.fpscr.disableFlushMode();
	f20.f64 = f30.f64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f29,f12,f19
	f29.f64 = double(float(ctx.f12.f64 * f19.f64));
	// beq cr6,0x827473b8
	if (cr6.eq) goto loc_827473B8;
	// cmpwi cr6,r31,127
	cr6.compare<int32_t>(r31.s32, 127, xer);
	// bne cr6,0x827473bc
	if (!cr6.eq) goto loc_827473BC;
loc_827473B8:
	// fmr f20,f31
	ctx.fpscr.disableFlushMode();
	f20.f64 = f31.f64;
loc_827473BC:
	// fsubs f13,f29,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f29.f64 - f28.f64));
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmuls f18,f29,f25
	f18.f64 = double(float(f29.f64 * f25.f64));
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fmr f1,f18
	ctx.f1.f64 = f18.f64;
	// fnmsubs f11,f12,f27,f30
	ctx.f11.f64 = double(float(-(ctx.f12.f64 * f27.f64 - f30.f64)));
	// fmuls f17,f11,f26
	f17.f64 = double(float(ctx.f11.f64 * f26.f64));
	// bl 0x823dbae8
	ctx.lr = 0x827473DC;
	sub_823DBAE8(ctx, base);
	// frsp f16,f1
	ctx.fpscr.disableFlushMode();
	f16.f64 = double(float(ctx.f1.f64));
	// fmr f1,f18
	ctx.f1.f64 = f18.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x827473E8;
	sub_823DBBC8(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// fmuls f29,f29,f23
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(f29.f64 * f23.f64));
	// stfs f24,128(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// frsp f10,f1
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f9,f16,f31
	ctx.f9.f64 = double(float(f16.f64 * f31.f64));
	// stfs f29,136(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// fmuls f3,f20,f22
	ctx.f3.f64 = double(float(f20.f64 * f22.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmuls f2,f10,f31
	ctx.f2.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fmsubs f1,f10,f17,f9
	ctx.f1.f64 = double(float(ctx.f10.f64 * f17.f64 - ctx.f9.f64));
	// stfs f1,144(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fctiwz f0,f3
	f0.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f0,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, f0.u64);
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rlwinm r7,r8,24,0,7
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF000000;
	// fmadds f13,f17,f16,f2
	ctx.f13.f64 = double(float(f17.f64 * f16.f64 + ctx.f2.f64));
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v127,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// or r29,r7,r30
	r29.u64 = ctx.r7.u64 | r30.u64;
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lfs f2,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x82747470;
	sub_8217BC28(ctx, base);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f21,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f31,164(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// stfs f29,168(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v127,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f7,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f7.f64 = f31.f64;
	// lfs f3,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// lfs f2,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x827474B8;
	sub_8217BC28(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// blt cr6,0x8274738c
	if (cr6.lt) goto loc_8274738C;
	// bl 0x8217bc98
	ctx.lr = 0x827474C8;
	sub_8217BC98(ctx, base);
	// li r4,256
	ctx.r4.s64 = 256;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x827474D4;
	sub_8217BB68(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_827474D8:
	// extsw r11,r31
	r11.s64 = r31.s32;
	// fmr f20,f30
	ctx.fpscr.disableFlushMode();
	f20.f64 = f30.f64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// lfd f0,104(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f29,f12,f19
	f29.f64 = double(float(ctx.f12.f64 * f19.f64));
	// beq cr6,0x82747504
	if (cr6.eq) goto loc_82747504;
	// cmpwi cr6,r31,127
	cr6.compare<int32_t>(r31.s32, 127, xer);
	// bne cr6,0x82747508
	if (!cr6.eq) goto loc_82747508;
loc_82747504:
	// fmr f20,f31
	ctx.fpscr.disableFlushMode();
	f20.f64 = f31.f64;
loc_82747508:
	// fsubs f13,f29,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f29.f64 - f28.f64));
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmuls f18,f29,f25
	f18.f64 = double(float(f29.f64 * f25.f64));
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fmr f1,f18
	ctx.f1.f64 = f18.f64;
	// fnmsubs f11,f12,f27,f30
	ctx.f11.f64 = double(float(-(ctx.f12.f64 * f27.f64 - f30.f64)));
	// fmuls f17,f11,f26
	f17.f64 = double(float(ctx.f11.f64 * f26.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82747528;
	sub_823DBAE8(ctx, base);
	// frsp f16,f1
	ctx.fpscr.disableFlushMode();
	f16.f64 = double(float(ctx.f1.f64));
	// fmr f1,f18
	ctx.f1.f64 = f18.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82747534;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// fmuls f3,f20,f22
	ctx.f3.f64 = double(float(f20.f64 * f22.f64));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// fmuls f9,f16,f31
	ctx.f9.f64 = double(float(f16.f64 * f31.f64));
	// stfs f31,160(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fmuls f29,f29,f23
	f29.f64 = double(float(f29.f64 * f23.f64));
	// stfs f24,164(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f29,168(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmuls f2,f10,f31
	ctx.f2.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fctiwz f0,f3
	f0.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fmsubs f1,f10,f17,f9
	ctx.f1.f64 = double(float(ctx.f10.f64 * f17.f64 - ctx.f9.f64));
	// stfs f1,144(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmadds f13,f16,f17,f2
	ctx.f13.f64 = double(float(f16.f64 * f17.f64 + ctx.f2.f64));
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v127,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r7,r8,24,0,7
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF000000;
	// lfs f3,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// or r29,r7,r30
	r29.u64 = ctx.r7.u64 | r30.u64;
	// lfs f2,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// bl 0x8217bc28
	ctx.lr = 0x827475BC;
	sub_8217BC28(ctx, base);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f21,132(r1)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// stfs f29,136(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// lvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v127,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x82747604;
	sub_8217BC28(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// blt cr6,0x827474d8
	if (cr6.lt) goto loc_827474D8;
	// bl 0x8217bc98
	ctx.lr = 0x82747614;
	sub_8217BC98(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9f4
	ctx.lr = 0x82747628;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274762C"))) PPC_WEAK_FUNC(sub_8274762C);
PPC_FUNC_IMPL(__imp__sub_8274762C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82747630"))) PPC_WEAK_FUNC(sub_82747630);
PPC_FUNC_IMPL(__imp__sub_82747630) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// stb r10,193(r9)
	PPC_STORE_U8(ctx.r9.u32 + 193, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274764C"))) PPC_WEAK_FUNC(sub_8274764C);
PPC_FUNC_IMPL(__imp__sub_8274764C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82747650"))) PPC_WEAK_FUNC(sub_82747650);
PPC_FUNC_IMPL(__imp__sub_82747650) {
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
	ctx.lr = 0x82747658;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r11,r3,920
	r11.s64 = ctx.r3.s64 + 920;
loc_82747674:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274769c
	if (cr6.eq) goto loc_8274769C;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x82747674
	if (cr6.lt) goto loc_82747674;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8274769C:
	// rlwinm r11,r30,6,0,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// add r31,r11,r3
	r31.u64 = r11.u64 + ctx.r3.u64;
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// addi r8,r30,14
	ctx.r8.s64 = r30.s64 + 14;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r11,r8,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// stb r7,920(r31)
	PPC_STORE_U8(r31.u32 + 920, ctx.r7.u8);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lfs f0,24(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	f0.f64 = double(temp.f32);
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// stfs f0,912(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 912, temp.u32);
	// addi r4,r6,-3328
	ctx.r4.s64 = ctx.r6.s64 + -3328;
	// lfs f0,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f1
	f0.f64 = double(float(f0.f64 + ctx.f1.f64));
	// stw r5,880(r31)
	PPC_STORE_U32(r31.u32 + 880, ctx.r5.u32);
	// stfs f0,916(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 916, temp.u32);
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,1
	ctx.r5.s64 = 1;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130000
	ctx.lr = 0x827476F0;
	sub_82130000(ctx, base);
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-3348
	ctx.r4.s64 = ctx.r4.s64 + -3348;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x82747704;
	sub_82130000(ctx, base);
	// rlwinm r3,r29,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 8) & 0xFFFFFF00;
	// stb r27,921(r31)
	PPC_STORE_U8(r31.u32 + 921, r27.u8);
	// stw r26,928(r31)
	PPC_STORE_U32(r31.u32 + 928, r26.u32);
	// or r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 | r30.u64;
	// stw r29,924(r31)
	PPC_STORE_U32(r31.u32 + 924, r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82747720"))) PPC_WEAK_FUNC(sub_82747720);
PPC_FUNC_IMPL(__imp__sub_82747720) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// rlwinm r11,r4,6,18,25
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0x3FC0;
	// srawi r10,r4,8
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 8;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r9,924(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 924);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// lfs f0,24(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	f0.f64 = double(temp.f32);
	// stb r9,920(r11)
	PPC_STORE_U8(r11.u32 + 920, ctx.r9.u8);
	// stfs f0,916(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 916, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274775C"))) PPC_WEAK_FUNC(sub_8274775C);
PPC_FUNC_IMPL(__imp__sub_8274775C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82747760"))) PPC_WEAK_FUNC(sub_82747760);
PPC_FUNC_IMPL(__imp__sub_82747760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f30
	ctx.f1.f64 = double(float(ctx.f13.f64 * f30.f64));
	// bl 0x8261e060
	ctx.lr = 0x827477A8;
	sub_8261E060(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fmsubs f10,f1,f0,f31
	ctx.f10.f64 = double(float(ctx.f1.f64 * f0.f64 - f31.f64));
	// fmadds f9,f10,f12,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f11.f64));
	// stfs f9,8(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// lfs f8,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f1,f8,f30
	ctx.f1.f64 = double(float(ctx.f8.f64 * f30.f64));
	// bl 0x8261e060
	ctx.lr = 0x827477D8;
	sub_8261E060(ctx, base);
	// lfs f7,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fnmsubs f6,f1,f7,f31
	ctx.f6.f64 = double(float(-(ctx.f1.f64 * ctx.f7.f64 - f31.f64)));
	// lfs f5,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// stfs f4,12(r30)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-40(r1)
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

__attribute__((alias("__imp__sub_8274780C"))) PPC_WEAK_FUNC(sub_8274780C);
PPC_FUNC_IMPL(__imp__sub_8274780C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82747810"))) PPC_WEAK_FUNC(sub_82747810);
PPC_FUNC_IMPL(__imp__sub_82747810) {
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
	PPCRegister f0{};
	PPCRegister f14{};
	PPCRegister f15{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
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
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91e0
	ctx.lr = 0x82747818;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9a0
	ctx.lr = 0x82747820;
	// stwu r1,-2032(r1)
	ea = -2032 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r9,32
	ctx.r9.s64 = 32;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r11,48
	r11.s64 = 48;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lvlx128 v59,r31,r10
	temp.u32 = r31.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// vspltw128 v8,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// mr r28,r30
	r28.u64 = r30.u64;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r24,r1,176
	r24.s64 = ctx.r1.s64 + 176;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// lvx128 v62,r8,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,20
	ctx.r7.s64 = 20;
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r27,52
	r27.s64 = 52;
	// lvx128 v61,r8,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,24
	r26.s64 = 24;
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r25,56
	r25.s64 = 56;
	// lvx128 v60,r8,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,208
	r23.s64 = ctx.r1.s64 + 208;
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r22,r1,80
	r22.s64 = ctx.r1.s64 + 80;
	// lvx128 v6,r28,r11
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r31,64
	ctx.r5.s64 = r31.s64 + 64;
	// lvx128 v5,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lvx128 v12,r6,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v11,r30,r10
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r6,r9
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r30,r9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v58,r31,r11
	temp.u32 = r31.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v7,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvx128 v0,r8,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v8,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v3,v5,v7,v6
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// lvlx128 v57,r31,r7
	temp.u32 = r31.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v56,r31,r27
	temp.u32 = r31.u32 + r27.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v4,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v2,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lvlx128 v55,r31,r26
	temp.u32 = r31.u32 + r26.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v54,r31,r25
	temp.u32 = r31.u32 + r25.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v30,v55,0
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vspltw128 v29,v54,0
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vmaddfp v28,v12,v4,v1
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v31,v11,v2,v3
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v0,v10,v30,v28
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v13,v9,v29,v31
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(v31.f32)));
	// stvx128 v0,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v53,v0,v13
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82747924;
	sub_82202EC0(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lwz r3,-26876(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -26876);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v52,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v51,v52,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// vmulfp128 v49,v50,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// stvx128 v49,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c088
	ctx.lr = 0x8274798C;
	sub_8217C088(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f13,-3308(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3308);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	f0.f64 = double(temp.f32);
	// lfs f12,-15956(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -15956);
	ctx.f12.f64 = double(temp.f32);
	// lfs f31,40(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 40);
	f31.f64 = double(temp.f32);
	// fsubs f0,f0,f1
	f0.f64 = double(float(f0.f64 - ctx.f1.f64));
	// fmsubs f21,f0,f13,f31
	f21.f64 = double(float(f0.f64 * ctx.f13.f64 - f31.f64));
	// fmuls f1,f21,f12
	ctx.f1.f64 = double(float(f21.f64 * ctx.f12.f64));
	// bl 0x8261e060
	ctx.lr = 0x827479C0;
	sub_8261E060(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,32680(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 32680);
	f0.f64 = double(temp.f32);
	// lfs f13,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30712(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 30712);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f30,f1,f0,f13
	f30.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// fmuls f1,f21,f12
	ctx.f1.f64 = double(float(f21.f64 * ctx.f12.f64));
	// bl 0x8261e060
	ctx.lr = 0x827479E4;
	sub_8261E060(ctx, base);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// stfs f30,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f21,112(r1)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f0,-32032(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -32032);
	f0.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f13,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmadds f13,f1,f0,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82747A2C;
	sub_8218A6E0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82747aa4
	if (cr6.eq) goto loc_82747AA4;
	// li r6,192
	ctx.r6.s64 = 192;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v48,r11,r6
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stvx128 v48,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82747A6C;
	sub_8218A6E0(ctx, base);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r3,208
	ctx.r3.s64 = 208;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r1,224
	r31.s64 = ctx.r1.s64 + 224;
	// lwz r5,20(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v47,r10,r3
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stvx128 v47,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82747AA4;
	sub_8218A6E0(ctx, base);
loc_82747AA4:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,-3296
	ctx.r9.s64 = r11.s64 + -3296;
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r7,2240
	ctx.r5.s64 = ctx.r7.s64 + 2240;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// vmsum4fp128 v46,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,-31664
	r11.s64 = ctx.r4.s64 + -31664;
	// addi r3,r6,-31648
	ctx.r3.s64 = ctx.r6.s64 + -31648;
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,240
	r30.s64 = ctx.r1.s64 + 240;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,-31384(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	f31.f64 = double(temp.f32);
	// lfs f29,14980(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14980);
	f29.f64 = double(temp.f32);
	// vrsqrtefp128 v45,v46
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v46.f32))));
	// vor128 v12,v46,v46
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vcmpeqfp128 v11,v45,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v45,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v45.u8));
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
	// vmulfp128 v44,v63,v6
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v44,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lfs f28,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f28.f64 = double(temp.f32);
	// lfs f27,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f27.f64 = double(temp.f32);
	// lfs f26,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f26.f64 = double(temp.f32);
	// lfs f30,7160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7160);
	f30.f64 = double(temp.f32);
	// lfs f25,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f25.f64 = double(temp.f32);
loc_82747B4C:
	// extsw r11,r31
	r11.s64 = r31.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmuls f1,f11,f29
	ctx.f1.f64 = double(float(ctx.f11.f64 * f29.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82747B6C;
	sub_823DBAE8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,33
	cr6.compare<int32_t>(r31.s32, 33, xer);
	// fmuls f9,f25,f10
	ctx.f9.f64 = double(float(f25.f64 * ctx.f10.f64));
	// fmuls f7,f27,f10
	ctx.f7.f64 = double(float(f27.f64 * ctx.f10.f64));
	// fmuls f8,f26,f10
	ctx.f8.f64 = double(float(f26.f64 * ctx.f10.f64));
	// fmuls f6,f28,f10
	ctx.f6.f64 = double(float(f28.f64 * ctx.f10.f64));
	// fmuls f5,f9,f31
	ctx.f5.f64 = double(float(ctx.f9.f64 * f31.f64));
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f3,f7,f31
	ctx.f3.f64 = double(float(ctx.f7.f64 * f31.f64));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmuls f4,f8,f31
	ctx.f4.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f4,84(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f2,f6,f31
	ctx.f2.f64 = double(float(ctx.f6.f64 * f31.f64));
	// stfs f2,92(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// blt cr6,0x82747b4c
	if (cr6.lt) goto loc_82747B4C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,33
	ctx.r8.s64 = 33;
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82747BE0;
	sub_8218A6E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f22,12428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12428);
	f22.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f23,12424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12424);
	f23.f64 = double(temp.f32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfs f16,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	f16.f64 = double(temp.f32);
	// li r28,0
	r28.s64 = 0;
	// lfs f17,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f17.f64 = double(temp.f32);
	// addi r26,r29,92
	r26.s64 = r29.s64 + 92;
	// lfs f20,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f20.f64 = double(temp.f32);
	// addi r27,r1,776
	r27.s64 = ctx.r1.s64 + 776;
	// lfs f18,23948(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 23948);
	f18.f64 = double(temp.f32);
	// li r25,64
	r25.s64 = 64;
	// lfs f19,-28916(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -28916);
	f19.f64 = double(temp.f32);
loc_82747C30:
	// extsw r11,r28
	r11.s64 = r28.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f30,f12,f19
	f30.f64 = double(float(ctx.f12.f64 * f19.f64));
	// fmuls f1,f30,f18
	ctx.f1.f64 = double(float(f30.f64 * f18.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82747C50;
	sub_823DBAE8(ctx, base);
	// fsubs f11,f30,f17
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f30.f64 - f17.f64));
	// mr r31,r26
	r31.u64 = r26.u64;
	// frsp f28,f1
	f28.f64 = double(float(ctx.f1.f64));
	// li r30,2
	r30.s64 = 2;
	// fmr f25,f20
	f25.f64 = f20.f64;
	// fmr f24,f20
	f24.f64 = f20.f64;
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fnmsubs f29,f10,f16,f31
	f29.f64 = double(float(-(ctx.f10.f64 * f16.f64 - f31.f64)));
loc_82747C70:
	// lfs f27,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f27.f64 = double(temp.f32);
	// fsubs f0,f31,f27
	f0.f64 = double(float(f31.f64 - f27.f64));
	// fmuls f13,f27,f30
	ctx.f13.f64 = double(float(f27.f64 * f30.f64));
	// fmuls f12,f0,f21
	ctx.f12.f64 = double(float(f0.f64 * f21.f64));
	// fmuls f11,f12,f23
	ctx.f11.f64 = double(float(ctx.f12.f64 * f23.f64));
	// fneg f26,f11
	f26.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fmadds f1,f13,f22,f26
	ctx.f1.f64 = double(float(ctx.f13.f64 * f22.f64 + f26.f64));
	// bl 0x8261e060
	ctx.lr = 0x82747C90;
	sub_8261E060(ctx, base);
	// lfs f10,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fmadds f1,f27,f28,f26
	ctx.f1.f64 = double(float(f27.f64 * f28.f64 + f26.f64));
	// fmadds f25,f9,f29,f25
	f25.f64 = double(float(ctx.f9.f64 * f29.f64 + f25.f64));
	// bl 0x8261e060
	ctx.lr = 0x82747CA4;
	sub_8261E060(ctx, base);
	// lfs f8,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// fmuls f7,f1,f8
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// fmadds f24,f7,f29,f24
	f24.f64 = double(float(ctx.f7.f64 * f29.f64 + f24.f64));
	// bne 0x82747c70
	if (!cr0.eq) goto loc_82747C70;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// extsw r11,r28
	r11.s64 = r28.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f28,f12,f19
	f28.f64 = double(float(ctx.f12.f64 * f19.f64));
	// fmuls f1,f28,f18
	ctx.f1.f64 = double(float(f28.f64 * f18.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82747CE0;
	sub_823DBAE8(ctx, base);
	// fsubs f11,f28,f17
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f28.f64 - f17.f64));
	// mr r31,r26
	r31.u64 = r26.u64;
	// frsp f26,f1
	f26.f64 = double(float(ctx.f1.f64));
	// li r30,2
	r30.s64 = 2;
	// fmr f30,f20
	f30.f64 = f20.f64;
	// fmr f29,f20
	f29.f64 = f20.f64;
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fnmsubs f27,f10,f16,f31
	f27.f64 = double(float(-(ctx.f10.f64 * f16.f64 - f31.f64)));
loc_82747D00:
	// lfs f15,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f15.f64 = double(temp.f32);
	// fsubs f0,f31,f15
	f0.f64 = double(float(f31.f64 - f15.f64));
	// fmuls f13,f15,f28
	ctx.f13.f64 = double(float(f15.f64 * f28.f64));
	// fmuls f12,f0,f21
	ctx.f12.f64 = double(float(f0.f64 * f21.f64));
	// fmuls f11,f12,f23
	ctx.f11.f64 = double(float(ctx.f12.f64 * f23.f64));
	// fneg f14,f11
	f14.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fmadds f1,f13,f22,f14
	ctx.f1.f64 = double(float(ctx.f13.f64 * f22.f64 + f14.f64));
	// bl 0x8261e060
	ctx.lr = 0x82747D20;
	sub_8261E060(ctx, base);
	// lfs f10,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// fmadds f1,f15,f26,f14
	ctx.f1.f64 = double(float(f15.f64 * f26.f64 + f14.f64));
	// fmadds f30,f9,f27,f30
	f30.f64 = double(float(ctx.f9.f64 * f27.f64 + f30.f64));
	// bl 0x8261e060
	ctx.lr = 0x82747D34;
	sub_8261E060(ctx, base);
	// lfs f8,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// fmuls f7,f1,f8
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// fmadds f29,f7,f27,f29
	f29.f64 = double(float(ctx.f7.f64 * f27.f64 + f29.f64));
	// bne 0x82747d00
	if (!cr0.eq) goto loc_82747D00;
	// stfs f25,-8(r27)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r27.u32 + -8, temp.u32);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// stfs f24,-4(r27)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r27.u32 + -4, temp.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stfs f30,0(r27)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// stfs f29,4(r27)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r27.u32 + 4, temp.u32);
	// addi r27,r27,16
	r27.s64 = r27.s64 + 16;
	// bne 0x82747c30
	if (!cr0.eq) goto loc_82747C30;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,64
	ctx.r8.s64 = 64;
	// lwz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,768
	ctx.r6.s64 = ctx.r1.s64 + 768;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82747D90;
	sub_8218A6E0(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187f40
	ctx.lr = 0x82747DA4;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82747dd0
	if (cr6.eq) goto loc_82747DD0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187b88
	ctx.lr = 0x82747DB8;
	sub_82187B88(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82747110
	ctx.lr = 0x82747DC0;
	sub_82747110(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187ba8
	ctx.lr = 0x82747DC8;
	sub_82187BA8(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187bd0
	ctx.lr = 0x82747DD0;
	sub_82187BD0(ctx, base);
loc_82747DD0:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r6,36(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187f40
	ctx.lr = 0x82747DE4;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82747e10
	if (cr6.eq) goto loc_82747E10;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187b88
	ctx.lr = 0x82747DF8;
	sub_82187B88(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82747300
	ctx.lr = 0x82747E00;
	sub_82747300(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187ba8
	ctx.lr = 0x82747E08;
	sub_82187BA8(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82187bd0
	ctx.lr = 0x82747E10;
	sub_82187BD0(ctx, base);
loc_82747E10:
	// addi r1,r1,2032
	ctx.r1.s64 = ctx.r1.s64 + 2032;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9ec
	ctx.lr = 0x82747E1C;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82747E20"))) PPC_WEAK_FUNC(sub_82747E20);
PPC_FUNC_IMPL(__imp__sub_82747E20) {
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
	PPCRegister f0{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	ctx.lr = 0x82747E28;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d0
	ctx.lr = 0x82747E30;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x82747e54
	if (!cr6.eq) goto loc_82747E54;
	// li r11,0
	r11.s64 = 0;
loc_82747E54:
	// addi r11,r11,4576
	r11.s64 = r11.s64 + 4576;
	// li r28,16
	r28.s64 = 16;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v63,r27,r28
	temp.u32 = r27.u32 + r28.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r6,48
	ctx.r6.s64 = 48;
	// stvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lvx128 v13,r11,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v10,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// stvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,20
	ctx.r4.s64 = 20;
	// lvx128 v12,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,24
	ctx.r10.s64 = 24;
	// stvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// lvx128 v11,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvlx128 v62,r27,r4
	temp.u32 = r27.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r3,20
	ctx.r3.s64 = 20;
	// vspltw128 v9,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvlx128 v61,r27,r10
	temp.u32 = r27.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v8,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v0,v13,v9,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v7,v12,v8,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v7,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217fed0
	ctx.lr = 0x82747ED0;
	sub_8217FED0(ctx, base);
	// cntlzw r8,r3
	ctx.r8.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// li r3,20
	ctx.r3.s64 = 20;
	// xori r25,r7,1
	r25.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8217f768
	ctx.lr = 0x82747EE8;
	sub_8217F768(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lbz r5,41(r27)
	ctx.r5.u64 = PPC_LOAD_U8(r27.u32 + 41);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lfs f26,14192(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f26.f64 = double(temp.f32);
	// beq cr6,0x82747f44
	if (cr6.eq) goto loc_82747F44;
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// stfs f26,100(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f26,96(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvlx128 v59,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v53,v56,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// vmulfp128 v54,v55,v58
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v53,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82747F44:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82747F54;
	sub_8217C088(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f13,32(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,36(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f10,1396(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1396);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,3796
	r11.s64 = r11.s64 + 3796;
	// lfs f9,1400(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1400);
	ctx.f9.f64 = double(temp.f32);
	// addi r10,r10,7444
	ctx.r10.s64 = ctx.r10.s64 + 7444;
	// lfs f0,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f27,f0,f13
	f27.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// lfs f30,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f30.f64 = double(temp.f32);
	// fsubs f8,f27,f11
	ctx.f8.f64 = double(float(f27.f64 - ctx.f11.f64));
	// fdivs f0,f27,f10
	f0.f64 = double(float(f27.f64 / ctx.f10.f64));
	// fcmpu cr6,f27,f11
	cr6.compare(f27.f64, ctx.f11.f64);
	// fdivs f13,f8,f9
	ctx.f13.f64 = double(float(ctx.f8.f64 / ctx.f9.f64));
	// bge cr6,0x82747fd8
	if (!cr6.lt) goto loc_82747FD8;
	// fsel f13,f0,f0,f31
	ctx.f13.f64 = f0.f64 >= 0.0 ? f0.f64 : f31.f64;
	// lfs f0,14980(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14980);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 - f30.f64));
	// fsel f11,f12,f30,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f30.f64 : ctx.f13.f64;
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x82747FC0;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fadds f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 + f30.f64));
	// fnmsubs f28,f9,f0,f30
	f28.f64 = double(float(-(ctx.f9.f64 * f0.f64 - f30.f64)));
	// b 0x82748004
	goto loc_82748004;
loc_82747FD8:
	// fsel f13,f13,f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f31.f64;
	// lfs f0,14980(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14980);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 - f30.f64));
	// fsel f11,f12,f30,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f30.f64 : ctx.f13.f64;
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x82747FF0;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fadds f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 + f30.f64));
	// fmuls f28,f9,f0
	f28.f64 = double(float(ctx.f9.f64 * f0.f64));
loc_82748004:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187f40
	ctx.lr = 0x82748018;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827481a4
	if (cr6.eq) goto loc_827481A4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r29,-1
	r29.s64 = -1;
	// addi r30,r31,1412
	r30.s64 = r31.s64 + 1412;
	// li r26,112
	r26.s64 = 112;
	// lfs f29,27552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27552);
	f29.f64 = double(temp.f32);
loc_82748034:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82747760
	ctx.lr = 0x82748044;
	sub_82747760(ctx, base);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f28
	ctx.f12.f64 = double(float(f0.f64 * f28.f64));
	// lfs f11,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f13,f28
	ctx.f10.f64 = double(float(ctx.f13.f64 * f28.f64));
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f9,132(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82748090;
	sub_8218A6E0(ctx, base);
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827480cc
	if (cr6.eq) goto loc_827480CC;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v52,r11,r26
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stvx128 v52,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x827480CC;
	sub_8218A6E0(ctx, base);
loc_827480CC:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187b88
	ctx.lr = 0x827480D8;
	sub_82187B88(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x827480E4;
	sub_8217BB68(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmr f8,f31
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f31.f64;
	// fmr f7,f26
	ctx.f7.f64 = f26.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8274810C;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmr f8,f30
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f30.f64;
	// fmr f7,f26
	ctx.f7.f64 = f26.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82748134;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmr f8,f31
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f31.f64;
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8274815C;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// fmr f8,f30
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f30.f64;
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8217bc28
	ctx.lr = 0x82748184;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x82748188;
	sub_8217BC98(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187ba8
	ctx.lr = 0x82748190;
	sub_82187BA8(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,28
	r30.s64 = r30.s64 + 28;
	// bne 0x82748034
	if (!cr0.eq) goto loc_82748034;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187bd0
	ctx.lr = 0x827481A4;
	sub_82187BD0(ctx, base);
loc_827481A4:
	// clrlwi r4,r25,24
	ctx.r4.u64 = r25.u32 & 0xFF;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8217f768
	ctx.lr = 0x827481B0;
	sub_8217F768(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba1c
	ctx.lr = 0x827481BC;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_827481C0"))) PPC_WEAK_FUNC(sub_827481C0);
PPC_FUNC_IMPL(__imp__sub_827481C0) {
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
	// bl 0x823d91e0
	ctx.lr = 0x827481C8;
	// stfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f29.u64);
	// stfd f30,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f29,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f29.f64 = double(temp.f32);
	// addi r31,r29,116
	r31.s64 = r29.s64 + 116;
	// lfs f31,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f31.f64 = double(temp.f32);
	// li r23,8
	r23.s64 = 8;
	// lfs f30,-3280(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -3280);
	f30.f64 = double(temp.f32);
	// li r25,60
	r25.s64 = 60;
	// li r26,12
	r26.s64 = 12;
	// li r27,44
	r27.s64 = 44;
	// li r28,1
	r28.s64 = 1;
	// li r24,0
	r24.s64 = 0;
	// addi r22,r11,29952
	r22.s64 = r11.s64 + 29952;
loc_82748218:
	// lbz r11,77(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 77);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827482c4
	if (cr6.eq) goto loc_827482C4;
	// addi r30,r31,-4
	r30.s64 = r31.s64 + -4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82747810
	ctx.lr = 0x82748234;
	sub_82747810(ctx, base);
	// lbz r11,76(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827482ac
	if (cr6.eq) goto loc_827482AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// lvx128 v63,r31,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r31,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r28,161(r1)
	PPC_STORE_U8(ctx.r1.u32 + 161, r28.u8);
	// lvx128 v61,r31,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stb r24,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r24.u8);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f11,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f9,f12,f31
	ctx.f9.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmuls f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64));
	// stfs f10,144(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f9,152(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// bl 0x82747810
	ctx.lr = 0x827482AC;
	sub_82747810(ctx, base);
loc_827482AC:
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 24);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fcmpu cr6,f12,f29
	cr6.compare(ctx.f12.f64, f29.f64);
	// ble cr6,0x827482c4
	if (!cr6.gt) goto loc_827482C4;
	// stb r24,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r24.u8);
loc_827482C4:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// bne 0x82748218
	if (!cr0.eq) goto loc_82748218;
	// addi r31,r29,912
	r31.s64 = r29.s64 + 912;
	// li r30,8
	r30.s64 = 8;
loc_827482D8:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274831c
	if (cr6.eq) goto loc_8274831C;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,-36
	ctx.r4.s64 = r11.s64 + -36;
	// bl 0x82747e20
	ctx.lr = 0x827482F4;
	sub_82747E20(ctx, base);
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f0,24(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 24);
	f0.f64 = double(temp.f32);
	// lfs f9,1400(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 1400);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fadds f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// fcmpu cr6,f11,f8
	cr6.compare(ctx.f11.f64, ctx.f8.f64);
	// ble cr6,0x8274831c
	if (!cr6.gt) goto loc_8274831C;
	// stb r24,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r24.u8);
loc_8274831C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// bne 0x827482d8
	if (!cr0.eq) goto loc_827482D8;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8274833C"))) PPC_WEAK_FUNC(sub_8274833C);
PPC_FUNC_IMPL(__imp__sub_8274833C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82748340"))) PPC_WEAK_FUNC(sub_82748340);
PPC_FUNC_IMPL(__imp__sub_82748340) {
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
	ctx.lr = 0x82748348;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r11,r3,193
	r11.s64 = ctx.r3.s64 + 193;
loc_8274836C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82748394
	if (cr6.eq) goto loc_82748394;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x8274836c
	if (cr6.lt) goto loc_8274836C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_82748394:
	// addi r11,r30,2
	r11.s64 = r30.s64 + 2;
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r6,r8,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r5,r7,29952
	ctx.r5.s64 = ctx.r7.s64 + 29952;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r10,160
	ctx.r10.s64 = 160;
	// stb r4,193(r11)
	PPC_STORE_U8(r11.u32 + 193, ctx.r4.u8);
	// li r8,128
	ctx.r8.s64 = 128;
	// stbx r29,r6,r3
	PPC_STORE_U8(ctx.r6.u32 + ctx.r3.u32, r29.u8);
	// li r7,176
	ctx.r7.s64 = 176;
	// lfs f0,24(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	f0.f64 = double(temp.f32);
	// stw r26,144(r11)
	PPC_STORE_U32(r11.u32 + 144, r26.u32);
	// stfs f0,112(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// stw r27,116(r11)
	PPC_STORE_U32(r11.u32 + 116, r27.u32);
	// lvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lvx128 v62,r0,r25
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r10,-3276
	ctx.r4.s64 = ctx.r10.s64 + -3276;
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// stvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,196(r11)
	PPC_STORE_U32(r11.u32 + 196, r28.u32);
	// lwz r3,-4916(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4916);
	// bl 0x824804d0
	ctx.lr = 0x8274841C;
	sub_824804D0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827484c8
	if (cr6.eq) goto loc_827484C8;
	// li r11,192
	r11.s64 = 192;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// clrlwi r7,r29,24
	ctx.r7.u64 = r29.u32 & 0xFF;
	// lvx128 v60,r28,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f13,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// li r9,416
	ctx.r9.s64 = 416;
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,272
	ctx.r10.s64 = 272;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f13,408(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 408, temp.u32);
	// stfs f0,400(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 400, temp.u32);
	// stfs f12,404(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// beq cr6,0x82748498
	if (cr6.eq) goto loc_82748498;
	// lwz r11,276(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,128(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 128);
	// lvx128 v59,r7,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8247a128
	ctx.lr = 0x82748490;
	sub_8247A128(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// b 0x827484b8
	goto loc_827484B8;
loc_82748498:
	// lwz r11,284(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,128(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 128);
	// lvx128 v58,r7,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8247a128
	ctx.lr = 0x827484B4;
	sub_8247A128(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
loc_827484B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8247a178
	ctx.lr = 0x827484C0;
	sub_8247A178(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8247a838
	ctx.lr = 0x827484C8;
	sub_8247A838(ctx, base);
loc_827484C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_827484D4"))) PPC_WEAK_FUNC(sub_827484D4);
PPC_FUNC_IMPL(__imp__sub_827484D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827484D8"))) PPC_WEAK_FUNC(sub_827484D8);
PPC_FUNC_IMPL(__imp__sub_827484D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v29{};
	PPCVRegister v30{};
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
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// rlwinm r11,r5,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f12,40(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// addi r7,r8,29952
	ctx.r7.s64 = ctx.r8.s64 + 29952;
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
	// li r9,16
	ctx.r9.s64 = 16;
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lwz r4,116(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// lfs f11,112(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lwz r8,144(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lfs f0,24(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	f0.f64 = double(temp.f32);
	// lvlx128 v63,r10,r3
	temp.u32 = ctx.r10.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lvlx128 v62,r10,r3
	temp.u32 = ctx.r10.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvlx128 v57,r10,r9
	temp.u32 = ctx.r10.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvx128 v59,r4,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v12,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lvx128 v58,r8,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,24
	ctx.r6.s64 = 24;
	// vmulfp128 v0,v59,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32)));
	// lvlx128 v56,r10,r9
	temp.u32 = ctx.r10.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmulfp128 v13,v58,v60
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v11,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lfs f0,-3308(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -3308);
	f0.f64 = double(temp.f32);
	// lis r30,-32250
	r30.s64 = -2113536000;
	// lvx128 v9,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lvx128 v10,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// fmsubs f9,f10,f0,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64 - ctx.f12.f64));
	// li r7,32
	ctx.r7.s64 = 32;
	// lvlx128 v55,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r8,48
	ctx.r8.s64 = 48;
	// lvlx128 v54,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v8,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vspltw128 v7,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lfs f13,7160(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7160);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v6,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lvx128 v5,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,-32
	ctx.r7.s64 = ctx.r1.s64 + -32;
	// vmaddfp v4,v10,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lvx128 v53,r3,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v3,v9,v11,v13
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v52,r11,r8
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// vmaddfp v2,v6,v8,v4
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v1,v5,v7,v3
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// fsel f7,f8,f8,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsel f6,f8,f8,f0
	ctx.f6.f64 = ctx.f8.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsubs f5,f7,f13
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// vaddfp128 v0,v53,v2
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vaddfp128 v51,v52,v1
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v1.f32)));
	// fsel f4,f5,f13,f6
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f6.f64;
	// stfs f4,-32(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvlx128 v50,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v30,v50,0
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vsubfp128 v31,v51,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v31.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v29,v31,v30,v0
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v29,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82748608"))) PPC_WEAK_FUNC(sub_82748608);
PPC_FUNC_IMPL(__imp__sub_82748608) {
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
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91ec
	ctx.lr = 0x82748610;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d4
	ctx.lr = 0x82748618;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lfs f3,11364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	ctx.f3.f64 = double(temp.f32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r27,-1
	r27.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// addi r26,r31,193
	r26.s64 = r31.s64 + 193;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82748650:
	// lbz r11,0(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827486b8
	if (cr6.eq) goto loc_827486B8;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827484d8
	ctx.lr = 0x8274866C;
	sub_827484D8(ctx, base);
	// lfs f0,52(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f13,56(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f12,48(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f2,f6,f6,f4
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f0,f2
	f0.f64 = double(float(sqrt(ctx.f2.f64)));
	// fcmpu cr6,f0,f3
	cr6.compare(f0.f64, ctx.f3.f64);
	// bge cr6,0x827486b8
	if (!cr6.lt) goto loc_827486B8;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// fmr f3,f0
	ctx.f3.f64 = f0.f64;
	// mr r27,r30
	r27.u64 = r30.u64;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827486B8:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r26,r26,96
	r26.s64 = r26.s64 + 96;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x82748650
	if (cr6.lt) goto loc_82748650;
	// cmpwi cr6,r27,-1
	cr6.compare<int32_t>(r27.s32, -1, xer);
	// beq cr6,0x82748824
	if (cr6.eq) goto loc_82748824;
	// rlwinm r11,r27,1,0,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f11,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// add r9,r27,r11
	ctx.r9.u64 = r27.u64 + r11.u64;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lfs f0,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f13,-3308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3308);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f10,112(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f0,7160(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7160);
	f0.f64 = double(temp.f32);
	// lfs f31,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f31.f64 = double(temp.f32);
	// lfs f12,30712(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 30712);
	ctx.f12.f64 = double(temp.f32);
	// lfs f29,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f29.f64 = double(temp.f32);
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmsubs f8,f9,f13,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 - ctx.f11.f64));
	// fmuls f28,f8,f0
	f28.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fadds f7,f28,f31
	ctx.f7.f64 = double(float(f28.f64 + f31.f64));
	// fmuls f1,f28,f12
	ctx.f1.f64 = double(float(f28.f64 * ctx.f12.f64));
	// fmsubs f6,f7,f31,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 * f31.f64 - f31.f64));
	// fabs f5,f6
	ctx.f5.u64 = ctx.f6.u64 & ~0x8000000000000000;
	// fnmsubs f27,f5,f29,f30
	f27.f64 = double(float(-(ctx.f5.f64 * f29.f64 - f30.f64)));
	// bl 0x8261e060
	ctx.lr = 0x82748748;
	sub_8261E060(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f0,-32032(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -32032);
	f0.f64 = double(temp.f32);
	// lfs f13,31308(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-15956(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -15956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f4,f1,f0,f13
	ctx.f4.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// stfs f4,88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmuls f1,f28,f12
	ctx.f1.f64 = double(float(f28.f64 * ctx.f12.f64));
	// bl 0x8261e060
	ctx.lr = 0x82748770;
	sub_8261E060(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// addi r11,r1,92
	r11.s64 = ctx.r1.s64 + 92;
	// lvlx128 v63,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r10,64
	ctx.r10.s64 = 64;
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// lfs f13,17032(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,32680(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32680);
	f0.f64 = double(temp.f32);
	// li r7,48
	ctx.r7.s64 = 48;
	// fmadds f3,f1,f0,f13
	ctx.f3.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// stfs f3,92(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvlx128 v61,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v63,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vmulfp128 v57,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// lvlx128 v56,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// vspltw128 v55,v56,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// fsel f2,f27,f27,f0
	ctx.f2.f64 = f27.f64 >= 0.0 ? f27.f64 : f0.f64;
	// lvx128 v54,r31,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v0,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// li r3,1
	ctx.r3.s64 = 1;
	// vmulfp128 v13,v54,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// vmulfp128 v12,v57,v58
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// fsubs f1,f2,f30
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(ctx.f2.f64 - f30.f64));
	// fsel f0,f1,f30,f2
	f0.f64 = ctx.f1.f64 >= 0.0 ? f30.f64 : ctx.f2.f64;
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvlx128 v53,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// vmaddfp v11,v13,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v51,v11,v52
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v52.f32)));
	// stvx128 v51,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,4(r28)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f29
	ctx.f12.f64 = double(float(ctx.f13.f64 + f29.f64));
	// stfs f12,4(r28)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r28.u32 + 4, temp.u32);
	// b 0x82748828
	goto loc_82748828;
loc_82748824:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82748828:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba20
	ctx.lr = 0x8274883C;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82748840"))) PPC_WEAK_FUNC(sub_82748840);
PPC_FUNC_IMPL(__imp__sub_82748840) {
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
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82748884
	if (cr6.eq) goto loc_82748884;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,612(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 612);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,612(r11)
	PPC_STORE_U32(r11.u32 + 612, ctx.r9.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8247a8d0
	ctx.lr = 0x82748878;
	sub_8247A8D0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
loc_82748884:
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

__attribute__((alias("__imp__sub_82748898"))) PPC_WEAK_FUNC(sub_82748898);
PPC_FUNC_IMPL(__imp__sub_82748898) {
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
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827488f8
	if (cr6.eq) goto loc_827488F8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,612(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 612);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,612(r11)
	PPC_STORE_U32(r11.u32 + 612, ctx.r9.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,136(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827488ec
	if (cr6.eq) goto loc_827488EC;
	// rotlwi r3,r8,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827488EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827488EC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
loc_827488F8:
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

__attribute__((alias("__imp__sub_8274890C"))) PPC_WEAK_FUNC(sub_8274890C);
PPC_FUNC_IMPL(__imp__sub_8274890C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82748910"))) PPC_WEAK_FUNC(sub_82748910);
PPC_FUNC_IMPL(__imp__sub_82748910) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82748918;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d4
	ctx.lr = 0x82748920;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// fmr f29,f2
	f29.f64 = ctx.f2.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f31,f3
	f31.f64 = ctx.f3.f64;
	// fmr f28,f4
	f28.f64 = ctx.f4.f64;
	// fmr f27,f5
	f27.f64 = ctx.f5.f64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82748a48
	if (cr6.eq) goto loc_82748A48;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x82748a40
	if (!cr6.eq) goto loc_82748A40;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748974
	if (cr6.lt) goto loc_82748974;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f30,r9,r10
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82748974:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748990
	if (cr6.lt) goto loc_82748990;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f29,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82748990:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// blt cr6,0x827489cc
	if (cr6.lt) goto loc_827489CC;
	// fsel f12,f31,f31,f0
	ctx.f12.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// fsel f11,f31,f31,f0
	ctx.f11.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f9,f10,f13,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// stfsx f9,r9,r10
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_827489CC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x827489e8
	if (cr6.lt) goto loc_827489E8;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f28,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_827489E8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748a04
	if (cr6.lt) goto loc_82748A04;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f27,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82748A04:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748c38
	if (cr6.lt) goto loc_82748C38;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82748a20
	if (cr6.eq) goto loc_82748A20;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
loc_82748A20:
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba20
	ctx.lr = 0x82748A3C;
	// b 0x823d924c
	return;
loc_82748A40:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82748840
	ctx.lr = 0x82748A48;
	sub_82748840(ctx, base);
loc_82748A48:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// bl 0x8247fee0
	ctx.lr = 0x82748A60;
	sub_8247FEE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82748c38
	if (cr6.eq) goto loc_82748C38;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// bl 0x8247a128
	ctx.lr = 0x82748A78;
	sub_8247A128(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82748c10
	if (cr6.eq) goto loc_82748C10;
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82748c10
	if (cr6.eq) goto loc_82748C10;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r4,r11,-2920
	ctx.r4.s64 = r11.s64 + -2920;
	// bl 0x8247bc80
	ctx.lr = 0x82748AA0;
	sub_8247BC80(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r4,r9,-2928
	ctx.r4.s64 = ctx.r9.s64 + -2928;
	// lwz r8,136(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// lwz r3,256(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 256);
	// bl 0x8247bc80
	ctx.lr = 0x82748ABC;
	sub_8247BC80(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r6,-2936
	ctx.r4.s64 = ctx.r6.s64 + -2936;
	// lwz r5,136(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 136);
	// lwz r3,256(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 256);
	// bl 0x8247bc80
	ctx.lr = 0x82748AD8;
	sub_8247BC80(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r4,-2948
	ctx.r4.s64 = ctx.r4.s64 + -2948;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// bl 0x8247bc80
	ctx.lr = 0x82748AF4;
	sub_8247BC80(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r4,r9,-24932
	ctx.r4.s64 = ctx.r9.s64 + -24932;
	// lwz r8,136(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// lwz r3,256(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 256);
	// bl 0x8247bc80
	ctx.lr = 0x82748B10;
	sub_8247BC80(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r7,-2952
	ctx.r4.s64 = ctx.r7.s64 + -2952;
	// lwz r5,136(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 136);
	// lwz r3,256(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 256);
	// bl 0x8247bc80
	ctx.lr = 0x82748B2C;
	sub_8247BC80(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748b4c
	if (cr6.lt) goto loc_82748B4C;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f30,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82748B4C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748b68
	if (cr6.lt) goto loc_82748B68;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f29,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82748B68:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748ba4
	if (cr6.lt) goto loc_82748BA4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,109
	ctx.r7.s64 = r11.s64 + 109;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f12,f31,f31,f0
	ctx.f12.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsel f11,f31,f31,f0
	ctx.f11.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f9,f10,f13,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// stfsx f9,r6,r9
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r9.u32, temp.u32);
loc_82748BA4:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748bc0
	if (cr6.lt) goto loc_82748BC0;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f28,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82748BC0:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748bdc
	if (cr6.lt) goto loc_82748BDC;
	// addi r11,r11,109
	r11.s64 = r11.s64 + 109;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f27,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
loc_82748BDC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82748c20
	if (cr6.lt) goto loc_82748C20;
	// clrlwi r7,r29,24
	ctx.r7.u64 = r29.u32 & 0xFF;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,109
	ctx.r8.s64 = r11.s64 + 109;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfsx f12,r6,r9
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r9.u32, temp.u32);
	// b 0x82748c20
	goto loc_82748C20;
loc_82748C10:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82748C20:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r30,1
	r30.s64 = 1;
	// stb r30,628(r11)
	PPC_STORE_U8(r11.u32 + 628, r30.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8247a838
	ctx.lr = 0x82748C34;
	sub_8247A838(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
loc_82748C38:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba20
	ctx.lr = 0x82748C44;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82748C48"))) PPC_WEAK_FUNC(sub_82748C48);
PPC_FUNC_IMPL(__imp__sub_82748C48) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	ctx.lr = 0x82748C50;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d8
	ctx.lr = 0x82748C58;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r28,320
	ctx.r10.s64 = r28.s64 + 320;
	// addi r11,r30,64
	r11.s64 = r30.s64 + 64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,48
	ctx.r9.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,14192(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82748cd0
	if (cr6.eq) goto loc_82748CD0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v58,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v56,v59,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82748CD0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,552(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 552);
	ctx.f13.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x82748d04
	if (!cr6.gt) goto loc_82748D04;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r30,96
	r11.s64 = r30.s64 + 96;
	// lvlx128 v54,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v52,v55,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82748D04:
	// li r11,128
	r11.s64 = 128;
	// lvx128 v51,r0,r27
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,464(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 464);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8274918c
	if (cr6.eq) goto loc_8274918C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f30,52(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 52);
	f30.f64 = double(temp.f32);
	// lfs f29,48(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 48);
	f29.f64 = double(temp.f32);
	// bl 0x82564e28
	ctx.lr = 0x82748D2C;
	sub_82564E28(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82748d3c
	if (!cr6.lt) goto loc_82748D3C;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// b 0x82748d50
	goto loc_82748D50;
loc_82748D3C:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f28,84(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	f28.f64 = double(temp.f32);
	// bl 0x82564e28
	ctx.lr = 0x82748D4C;
	sub_82564E28(ctx, base);
	// fdivs f13,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 / f28.f64));
loc_82748D50:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r7,r31,24
	ctx.r7.u64 = r31.u32 & 0xFF;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f10,32680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	ctx.f10.f64 = double(temp.f32);
	// beq cr6,0x82748de0
	if (cr6.eq) goto loc_82748DE0;
	// lfs f0,296(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 296);
	f0.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,-17876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17876);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x82748de0
	if (!cr6.lt) goto loc_82748DE0;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lhz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 44);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// lwz r11,-21428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21428);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x82748f1c
	if (!cr6.lt) goto loc_82748F1C;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
loc_82748DA4:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82748dbc
	if (cr6.eq) goto loc_82748DBC;
	// li r11,10
	r11.s64 = 10;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
loc_82748DBC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,420(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 420);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,-26224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26224);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x82748f24
	if (cr6.gt) goto loc_82748F24;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// b 0x82748f4c
	goto loc_82748F4C;
loc_82748DE0:
	// lfs f0,-7888(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -7888);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x82748ee0
	if (!cr6.lt) goto loc_82748EE0;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// li r8,10
	ctx.r8.s64 = 10;
	// bgt cr6,0x82748e48
	if (cr6.gt) goto loc_82748E48;
	// lfs f0,520(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82748e90
	if (!cr6.gt) goto loc_82748E90;
	// lbz r11,529(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 529);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82748e90
	if (cr6.eq) goto loc_82748E90;
	// lwz r11,-21428(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21428);
	// lhz r10,46(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 46);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// bge cr6,0x82748ed8
	if (!cr6.lt) goto loc_82748ED8;
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r4,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82748e94
	if (cr6.eq) goto loc_82748E94;
	// stw r8,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r8.u32);
	// b 0x82748e90
	goto loc_82748E90;
loc_82748E48:
	// fcmpu cr6,f13,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f30.f64);
	// ble cr6,0x82748e90
	if (!cr6.gt) goto loc_82748E90;
	// lfs f0,520(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82748e90
	if (!cr6.gt) goto loc_82748E90;
	// lwz r11,-21428(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21428);
	// lhz r10,46(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 46);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// bge cr6,0x82748ed8
	if (!cr6.lt) goto loc_82748ED8;
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r4,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82748e94
	if (cr6.eq) goto loc_82748E94;
	// li r11,0
	r11.s64 = 0;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
loc_82748E90:
	// lwz r11,-21428(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21428);
loc_82748E94:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82748ea8
	if (!cr6.eq) goto loc_82748EA8;
	// lfs f0,520(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x82748dbc
	if (!cr6.gt) goto loc_82748DBC;
loc_82748EA8:
	// lhz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 44);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x82748f1c
	if (!cr6.lt) goto loc_82748F1C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82748dbc
	if (cr6.eq) goto loc_82748DBC;
	// stw r8,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r8.u32);
	// b 0x82748dbc
	goto loc_82748DBC;
loc_82748ED8:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82748e94
	goto loc_82748E94;
loc_82748EE0:
	// lfs f0,520(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82748dbc
	if (!cr6.gt) goto loc_82748DBC;
	// lbz r11,529(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 529);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82748dbc
	if (cr6.eq) goto loc_82748DBC;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lhz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 44);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// lwz r11,-21428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21428);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x82748f1c
	if (!cr6.lt) goto loc_82748F1C;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// b 0x82748da4
	goto loc_82748DA4;
loc_82748F1C:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82748dbc
	goto loc_82748DBC;
loc_82748F24:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f11,31236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31236);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// blt cr6,0x82748f3c
	if (cr6.lt) goto loc_82748F3C;
	// fmr f4,f0
	ctx.f4.f64 = f0.f64;
	// b 0x82748f4c
	goto loc_82748F4C;
loc_82748F3C:
	// fsubs f12,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,-2904(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2904);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f4,f12,f13
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
loc_82748F4C:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82748f74
	if (cr6.eq) goto loc_82748F74;
	// lwz r11,372(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 372);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82748f70
	if (cr6.eq) goto loc_82748F70;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82748f74
	if (!cr6.eq) goto loc_82748F74;
loc_82748F70:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82748F74:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82748f88
	if (!cr6.eq) goto loc_82748F88;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-15468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15468);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,40(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 40, temp.u32);
loc_82748F88:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827490d8
	if (cr6.eq) goto loc_827490D8;
	// lfs f13,520(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 520);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f29
	ctx.f12.f64 = double(float(f0.f64 - f29.f64));
	// fsubs f9,f13,f29
	ctx.f9.f64 = double(float(ctx.f13.f64 - f29.f64));
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f13,-26236(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26236);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-2908(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -2908);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 / ctx.f12.f64));
	// fsel f7,f8,f8,f31
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f8.f64 : f31.f64;
	// fsubs f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 - f0.f64));
	// fsel f1,f6,f0,f7
	ctx.f1.f64 = ctx.f6.f64 >= 0.0 ? f0.f64 : ctx.f7.f64;
	// stfs f1,32(r30)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 32, temp.u32);
	// lfs f12,-7888(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -7888);
	ctx.f12.f64 = double(temp.f32);
	// lfs f5,296(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 296);
	ctx.f5.f64 = double(temp.f32);
	// fabs f3,f5
	ctx.f3.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fmuls f2,f3,f13
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fsubs f13,f12,f10
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fsel f12,f2,f2,f31
	ctx.f12.f64 = ctx.f2.f64 >= 0.0 ? ctx.f2.f64 : f31.f64;
	// fsel f10,f2,f2,f31
	ctx.f10.f64 = ctx.f2.f64 >= 0.0 ? ctx.f2.f64 : f31.f64;
	// fmuls f9,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fsubs f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f7,f8,f0,f10
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f0.f64 : ctx.f10.f64;
	// fmadds f6,f7,f9,f1
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f9.f64 + ctx.f1.f64));
	// stfs f6,36(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 36, temp.u32);
	// beq cr6,0x82749064
	if (cr6.eq) goto loc_82749064;
	// lfs f13,296(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f10,292(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 292);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,12424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12424);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f10,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f11.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fmuls f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fsel f6,f7,f7,f31
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : f31.f64;
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f13,f5,f0,f6
	ctx.f13.f64 = ctx.f5.f64 >= 0.0 ? f0.f64 : ctx.f6.f64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x82749058
	if (!cr6.gt) goto loc_82749058;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r8,r11,29952
	ctx.r8.s64 = r11.s64 + 29952;
	// lfs f10,-5380(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -5380);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fnmsubs f12,f11,f10,f12
	ctx.f12.f64 = double(float(-(ctx.f11.f64 * ctx.f10.f64 - ctx.f12.f64)));
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f10,f11,f12,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// stfs f10,40(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 40, temp.u32);
	// b 0x82749064
	goto loc_82749064;
loc_82749058:
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x82749064
	if (!cr6.lt) goto loc_82749064;
	// stfs f13,40(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 40, temp.u32);
loc_82749064:
	// lfs f13,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f10,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,-5388(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5388);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f10,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f11.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f13,f7
	ctx.f13.f64 = double(float(sqrt(ctx.f7.f64)));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x82749098
	if (cr6.gt) goto loc_82749098;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x827490b4
	goto loc_827490B4;
loc_82749098:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f11,-5384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5384);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bge cr6,0x827490b4
	if (!cr6.lt) goto loc_827490B4;
	// fsubs f0,f13,f12
	f0.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
loc_827490B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f3,40(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,36(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 36);
	ctx.f2.f64 = double(temp.f32);
	// fmr f5,f0
	ctx.f5.f64 = f0.f64;
	// bl 0x82748910
	ctx.lr = 0x827490C8;
	sub_82748910(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x827490D4;
	// b 0x823d9244
	return;
loc_827490D8:
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x827490fc
	if (cr6.gt) goto loc_827490FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82748840
	ctx.lr = 0x827490EC;
	sub_82748840(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x827490F8;
	// b 0x823d9244
	return;
loc_827490FC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274918c
	if (cr6.eq) goto loc_8274918C;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274918c
	if (cr6.eq) goto loc_8274918C;
	// lfs f13,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f10,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,-5388(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5388);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f10,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f11.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f13,f7
	ctx.f13.f64 = double(float(sqrt(ctx.f7.f64)));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bgt cr6,0x82749148
	if (cr6.gt) goto loc_82749148;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82749164
	goto loc_82749164;
loc_82749148:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f11,-5384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5384);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bge cr6,0x82749164
	if (!cr6.lt) goto loc_82749164;
	// fsubs f0,f13,f12
	f0.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
loc_82749164:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f3,40(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,36(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 36);
	ctx.f2.f64 = double(temp.f32);
	// lwz r4,52(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lfs f1,32(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// fmr f5,f0
	ctx.f5.f64 = f0.f64;
	// bl 0x82748910
	ctx.lr = 0x82749180;
	sub_82748910(ctx, base);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r11.u32);
loc_8274918C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x82749198;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274919C"))) PPC_WEAK_FUNC(sub_8274919C);
PPC_FUNC_IMPL(__imp__sub_8274919C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827491A0"))) PPC_WEAK_FUNC(sub_827491A0);
PPC_FUNC_IMPL(__imp__sub_827491A0) {
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
	// addi r10,r11,-2896
	ctx.r10.s64 = r11.s64 + -2896;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,38(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827491d4
	if (cr6.eq) goto loc_827491D4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x827491D4;
	sub_82130588(ctx, base);
loc_827491D4:
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827491e8
	if (cr6.eq) goto loc_827491E8;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x827491E8;
	sub_82130588(ctx, base);
loc_827491E8:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827491fc
	if (cr6.eq) goto loc_827491FC;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x827491FC;
	sub_82130588(ctx, base);
loc_827491FC:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82749210
	if (cr6.eq) goto loc_82749210;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82749210;
	sub_82130588(ctx, base);
loc_82749210:
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

__attribute__((alias("__imp__sub_82749224"))) PPC_WEAK_FUNC(sub_82749224);
PPC_FUNC_IMPL(__imp__sub_82749224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82749228"))) PPC_WEAK_FUNC(sub_82749228);
PPC_FUNC_IMPL(__imp__sub_82749228) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82749230;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r22,r11,30576
	r22.s64 = r11.s64 + 30576;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-232
	ctx.r4.s64 = ctx.r10.s64 + -232;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821ca540
	ctx.lr = 0x82749250;
	sub_821CA540(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r5,r9,-32764
	ctx.r5.s64 = ctx.r9.s64 + -32764;
	// addi r4,r8,-2876
	ctx.r4.s64 = ctx.r8.s64 + -2876;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x82749270;
	sub_821CA6A8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82749484
	if (cr6.eq) goto loc_82749484;
	// li r3,548
	ctx.r3.s64 = 548;
	// bl 0x82130528
	ctx.lr = 0x82749284;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274947c
	if (cr6.eq) goto loc_8274947C;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r4,r11,-2892
	ctx.r4.s64 = r11.s64 + -2892;
	// bl 0x821d1ce8
	ctx.lr = 0x8274929C;
	sub_821D1CE8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274947c
	if (cr6.eq) goto loc_8274947C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827492C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82749464
	if (cr6.eq) goto loc_82749464;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r26,r28,8
	r26.s64 = r28.s64 + 8;
	// addi r25,r28,16
	r25.s64 = r28.s64 + 16;
	// addi r24,r28,24
	r24.s64 = r28.s64 + 24;
	// addi r27,r28,32
	r27.s64 = r28.s64 + 32;
	// addi r29,r11,-25064
	r29.s64 = r11.s64 + -25064;
loc_827492E0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db730
	ctx.lr = 0x827492EC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82749308
	if (cr6.eq) goto loc_82749308;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x82749300;
	sub_821C9790(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8274930c
	goto loc_8274930C;
loc_82749308:
	// li r30,0
	r30.s64 = 0;
loc_8274930C:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8262e420
	ctx.lr = 0x82749318;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8274933C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db730
	ctx.lr = 0x82749348;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82749364
	if (cr6.eq) goto loc_82749364;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x8274935C;
	sub_821C9790(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82749368
	goto loc_82749368;
loc_82749364:
	// li r30,0
	r30.s64 = 0;
loc_82749368:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8262e420
	ctx.lr = 0x82749374;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82749398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db730
	ctx.lr = 0x827493A4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827493c0
	if (cr6.eq) goto loc_827493C0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x827493B8;
	sub_821C9790(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x827493c4
	goto loc_827493C4;
loc_827493C0:
	// li r30,0
	r30.s64 = 0;
loc_827493C4:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8262e420
	ctx.lr = 0x827493D0;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827493F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db730
	ctx.lr = 0x82749400;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8274941c
	if (cr6.eq) goto loc_8274941C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x82749414;
	sub_821C9790(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82749420
	goto loc_82749420;
loc_8274941C:
	// li r30,0
	r30.s64 = 0;
loc_82749420:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x8274942C;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8274945C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x827492e0
	if (!cr6.eq) goto loc_827492E0;
loc_82749464:
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
	ctx.lr = 0x8274947C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274947C:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821be610
	ctx.lr = 0x82749484;
	sub_821BE610(ctx, base);
loc_82749484:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8274948C;
	sub_821C9A90(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82749494"))) PPC_WEAK_FUNC(sub_82749494);
PPC_FUNC_IMPL(__imp__sub_82749494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82749498"))) PPC_WEAK_FUNC(sub_82749498);
PPC_FUNC_IMPL(__imp__sub_82749498) {
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
	// bl 0x827491a0
	ctx.lr = 0x827494B8;
	sub_827491A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827494d0
	if (cr6.eq) goto loc_827494D0;
	// bl 0x82130588
	ctx.lr = 0x827494CC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827494D0:
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

__attribute__((alias("__imp__sub_827494E8"))) PPC_WEAK_FUNC(sub_827494E8);
PPC_FUNC_IMPL(__imp__sub_827494E8) {
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
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x827494FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82749568
	if (cr6.eq) goto loc_82749568;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-2896
	ctx.r9.s64 = ctx.r10.s64 + -2896;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r10,r10,-21428
	ctx.r10.s64 = ctx.r10.s64 + -21428;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// sth r11,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, r11.u16);
	// sth r11,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, r11.u16);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// sth r11,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, r11.u16);
	// sth r11,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, r11.u16);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, r11.u16);
	// sth r11,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, r11.u16);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// bl 0x82749228
	ctx.lr = 0x82749558;
	sub_82749228(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82749568:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,-21428
	ctx.r10.s64 = r11.s64 + -21428;
	// stw r3,-21428(r11)
	PPC_STORE_U32(r11.u32 + -21428, ctx.r3.u32);
	// bl 0x82749228
	ctx.lr = 0x8274957C;
	sub_82749228(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274958C"))) PPC_WEAK_FUNC(sub_8274958C);
PPC_FUNC_IMPL(__imp__sub_8274958C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82749590"))) PPC_WEAK_FUNC(sub_82749590);
PPC_FUNC_IMPL(__imp__sub_82749590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,64
	ctx.r9.s64 = 64;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r7,2240
	ctx.r5.s64 = ctx.r7.s64 + 2240;
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v58,v62,v62
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r3,-31648
	ctx.r9.s64 = ctx.r3.s64 + -31648;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,-31664
	ctx.r8.s64 = ctx.r10.s64 + -31664;
	// vor128 v0,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vor128 v13,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,5
	ctx.r5.s64 = 5;
	// lbz r10,-5340(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + -5340);
	// vrsqrtefp128 v57,v59
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v11,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vrsqrtefp128 v56,v58
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// vcmpeqfp128 v9,v57,v60
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vor128 v8,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vcmpeqfp128 v7,v56,v60
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v60.f32)));
	// vor128 v6,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vsel v13,v6,v13,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v13,v13
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v3,v61,v0
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v2,v61,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v1,v11,v5,v12
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v31,v10,v4,v12
	simde_mm_store_ps(v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v30,v1,v3,v0
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v29,v31,v2,v13
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v55,v63,v30
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v30.f32)));
	// vmulfp128 v54,v62,v29
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v29.f32)));
	// stvx128 v55,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822ee490
	ctx.lr = 0x82749698;
	sub_822EE490(ctx, base);
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

__attribute__((alias("__imp__sub_827496B0"))) PPC_WEAK_FUNC(sub_827496B0);
PPC_FUNC_IMPL(__imp__sub_827496B0) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827496B8;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// stw r4,320(r3)
	PPC_STORE_U32(ctx.r3.u32 + 320, ctx.r4.u32);
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// lfs f13,28(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r7,2176
	ctx.r5.s64 = ctx.r7.s64 + 2176;
	// lfs f12,32(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// ori r11,r6,64167
	r11.u64 = ctx.r6.u64 | 64167;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lwz r8,2176(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2176);
	// mulld r9,r8,r11
	ctx.r9.s64 = ctx.r8.s64 * r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f0,14348(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14348);
	f0.f64 = double(temp.f32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// clrlwi r4,r10,9
	ctx.r4.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r4,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r4.u64);
	// lfd f10,-64(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stw r9,2176(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2176, ctx.r9.u32);
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// lwz r8,320(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmadds f6,f7,f0,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stfs f6,8(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r6,2176(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2176);
	// mulld r9,r6,r11
	ctx.r9.s64 = ctx.r6.s64 * r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f5,36(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,40(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f1,f4,f5
	ctx.f1.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// clrlwi r8,r10,9
	ctx.r8.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r8,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r8.u64);
	// lfd f3,-64(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f13,f2
	ctx.f13.f64 = double(float(ctx.f2.f64));
	// stw r9,2176(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2176, ctx.r9.u32);
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// lwz r6,320(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// fmuls f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// fmadds f11,f12,f0,f5
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f5.f64));
	// stfs f11,4(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r4,2176(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2176);
	// mulld r9,r4,r11
	ctx.r9.s64 = ctx.r4.s64 * r11.s64;
	// lfs f10,44(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f9,48(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rldicl r8,r10,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// clrlwi r10,r10,9
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFF;
	// stw r9,2176(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2176, ctx.r9.u32);
	// stw r8,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r8.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lwz r9,320(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// std r8,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r8.u64);
	// lfd f8,-64(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// fsubs f6,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fmuls f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// fmadds f3,f4,f0,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f10.f64));
	// stfs f3,16(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lfs f2,52(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// lwz r6,2176(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2176);
	// lfs f1,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// mulld r9,r6,r11
	ctx.r9.s64 = ctx.r6.s64 * r11.s64;
	// fsubs f13,f1,f2
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r6,r10,9
	ctx.r6.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// std r6,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r6.u64);
	// lfd f12,-64(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// stw r11,2176(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2176, r11.u32);
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r6,320(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// li r31,176
	r31.s64 = 176;
	// li r30,192
	r30.s64 = 192;
	// li r29,208
	r29.s64 = 208;
	// li r28,224
	r28.s64 = 224;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmadds f8,f9,f0,f2
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f2.f64));
	// stfs f8,0(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r27,2176(r7)
	r27.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2176);
	// mulld r10,r27,r4
	ctx.r10.s64 = r27.s64 * ctx.r4.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f7,20(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,24(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r6,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r6.u64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,2176(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2176, ctx.r10.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// lwz r4,320(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 320);
	// lfd f4,-64(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmuls f1,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f2.f64));
	// fmadds f13,f1,f0,f7
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f7.f64));
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lfs f12,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lfs f11,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lwz r6,2176(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2176);
	// mulld r10,r6,r8
	ctx.r10.s64 = ctx.r6.s64 * ctx.r8.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r8,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r8.u64);
	// lfd f9,-64(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// stw r10,2176(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2176, ctx.r10.u32);
	// fmuls f6,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f7.f64));
	// fmadds f5,f6,f0,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f12.f64));
	// stfs f5,20(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lbz r11,-21424(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + -21424);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r6,r7,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v63,r6,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,-21424(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + -21424);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r11,r3
	ctx.r4.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r4,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,-21424(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + -21424);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,-21424(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + -21424);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r11,r3
	ctx.r7.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r7,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,-21424(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + -21424);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r3
	ctx.r5.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r5,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82749960"))) PPC_WEAK_FUNC(sub_82749960);
PPC_FUNC_IMPL(__imp__sub_82749960) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82749968;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x825788a8
	ctx.lr = 0x8274997C;
	sub_825788A8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274998c
	if (cr6.eq) goto loc_8274998C;
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// b 0x827499c4
	goto loc_827499C4;
loc_8274998C:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
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
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827499C4:
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v57,r11,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v56,r11,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82575c38
	ctx.lr = 0x82749A0C;
	sub_82575C38(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r7,2468(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 2468);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,2464(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2464);
	// bl 0x822c5680
	ctx.lr = 0x82749A24;
	sub_822C5680(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82749a40
	if (cr6.eq) goto loc_82749A40;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8257dc50
	ctx.lr = 0x82749A40;
	sub_8257DC50(ctx, base);
loc_82749A40:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82475b38
	ctx.lr = 0x82749A48;
	sub_82475B38(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82749A50"))) PPC_WEAK_FUNC(sub_82749A50);
PPC_FUNC_IMPL(__imp__sub_82749A50) {
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
	ctx.lr = 0x82749A58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,176
	r29.s64 = r31.s64 + 176;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// addi r3,r29,628
	ctx.r3.s64 = r29.s64 + 628;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r30.u32);
	// sth r30,280(r31)
	PPC_STORE_U16(r31.u32 + 280, r30.u16);
	// stw r30,932(r31)
	PPC_STORE_U32(r31.u32 + 932, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x82749AA4;
	sub_823D9890(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,106
	ctx.r3.s64 = r29.s64 + 106;
	// bl 0x823d9890
	ctx.lr = 0x82749AB4;
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
	ctx.lr = 0x82749ADC;
	sub_823D9890(ctx, base);
	// addi r3,r31,1920
	ctx.r3.s64 = r31.s64 + 1920;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82749AEC;
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
	ctx.lr = 0x82749B10;
	sub_82130000(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,2460(r31)
	PPC_STORE_U32(r31.u32 + 2460, r30.u32);
	// stw r11,2464(r31)
	PPC_STORE_U32(r31.u32 + 2464, r11.u32);
	// stw r11,2468(r31)
	PPC_STORE_U32(r31.u32 + 2468, r11.u32);
	// stb r9,2472(r31)
	PPC_STORE_U8(r31.u32 + 2472, ctx.r9.u8);
	// stw r30,2476(r31)
	PPC_STORE_U32(r31.u32 + 2476, r30.u32);
	// stw r30,2480(r31)
	PPC_STORE_U32(r31.u32 + 2480, r30.u32);
	// std r8,2440(r31)
	PPC_STORE_U64(r31.u32 + 2440, ctx.r8.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82749B48"))) PPC_WEAK_FUNC(sub_82749B48);
PPC_FUNC_IMPL(__imp__sub_82749B48) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91c0
	ctx.lr = 0x82749B50;
	// stfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// addi r12,r1,-176
	r12.s64 = ctx.r1.s64 + -176;
	// bl 0x823dd52c
	ctx.lr = 0x82749B60;
	// stwu r1,-3072(r1)
	ea = -3072 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f13,f1,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + f0.f64));
	// lfs f11,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f0,f11,f1
	f0.f64 = double(float(ctx.f11.f64 - ctx.f1.f64));
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f12,4(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// fcmpu cr6,f12,f10
	cr6.compare(ctx.f12.f64, ctx.f10.f64);
	// bgt cr6,0x82749ba4
	if (cr6.gt) goto loc_82749BA4;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x82749bb0
	if (!cr6.lt) goto loc_82749BB0;
loc_82749BA4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,320(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// bl 0x827496b0
	ctx.lr = 0x82749BB0;
	sub_827496B0(ctx, base);
loc_82749BB0:
	// vspltisw128 v123,0
	simde_mm_store_si128((simde__m128i*)v123.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// li r10,4
	ctx.r10.s64 = 4;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vupkd3d128 v61,v123,4
	temp.f32 = 3.0f;
	temp.s32 += v123.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v123.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v61 = vTemp;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvlx128 v59,r11,r10
	temp.u32 = r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvlx128 v57,r11,r9
	temp.u32 = r11.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v59,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vpermwi128 v63,v61,234
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// vpermwi128 v62,v61,186
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vpermwi128 v61,v61,174
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// vspltw128 v55,v57,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// vmulfp128 v54,v63,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// vmulfp128 v53,v62,v56
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v123,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v52,v61,v55
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,27644(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27644);
	f31.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// stvx128 v54,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82227e98
	ctx.lr = 0x82749C44;
	sub_82227E98(ctx, base);
	// lfs f13,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f1,f13,f31
	ctx.f1.f64 = double(float(ctx.f13.f64 * f31.f64));
	// bl 0x82214d90
	ctx.lr = 0x82749C54;
	sub_82214D90(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f12,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// li r19,48
	r19.s64 = 48;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r15,16
	r15.s64 = 16;
	// lvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r16,32
	r16.s64 = 32;
	// vspltw128 v51,v63,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// li r30,0
	r30.s64 = 0;
	// vspltw128 v50,v62,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v49,v61,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lfs f0,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f0.f64 = double(temp.f32);
	// vspltw128 v11,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v3,r11,r19
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r11,r15
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r31,32
	r26.s64 = r31.s64 + 32;
	// lvx128 v12,r11,r16
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,80
	ctx.r3.s64 = 80;
	// vspltw128 v10,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// li r10,64
	ctx.r10.s64 = 64;
	// vmulfp128 v9,v0,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// mr r29,r30
	r29.u64 = r30.u64;
	// vspltw128 v8,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v7,v0,v50
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v50.f32)));
	// vspltw128 v6,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vmulfp128 v5,v0,v49
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v49.f32)));
	// vspltw128 v4,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// fmuls f10,f12,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// vspltw128 v2,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vmaddfp v31,v0,v11,v3
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vspltw128 v1,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vspltw128 v30,v60,1
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vmaddfp v29,v13,v10,v9
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// fneg f9,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// vmaddfp v28,v13,v8,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vspltw128 v27,v60,2
	simde_mm_store_si128((simde__m128i*)v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vmaddfp v26,v13,v6,v5
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// vmaddfp v25,v13,v30,v31
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v31.f32)));
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f10,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stfs f9,160(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r22,r26,16
	r22.s64 = r26.s64 + 16;
	// lfs f13,-3164(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3164);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f12,-13148(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13148);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lfs f11,14880(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14880);
	ctx.f11.f64 = double(temp.f32);
	// addi r21,r26,32
	r21.s64 = r26.s64 + 32;
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r20,r31,144
	r20.s64 = r31.s64 + 144;
	// vmaddfp v24,v12,v4,v29
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(v29.f32)));
	// addi r25,r1,160
	r25.s64 = ctx.r1.s64 + 160;
	// vmaddfp v23,v12,v2,v28
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v28.f32)));
	// ori r27,r8,65535
	r27.u64 = ctx.r8.u64 | 65535;
	// vmaddfp v22,v12,v1,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v26.f32)));
	// lis r28,-32111
	r28.s64 = -2104426496;
	// vmaddfp v21,v12,v27,v25
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v27.f32)), simde_mm_load_ps(v25.f32)));
	// addi r18,r11,2352
	r18.s64 = r11.s64 + 2352;
	// addi r24,r9,2256
	r24.s64 = ctx.r9.s64 + 2256;
	// fmadds f7,f8,f13,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmadds f6,f8,f0,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f9.f64));
	// stfs f6,168(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmadds f5,f8,f12,f9
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stvx128 v24,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stvx128 v23,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r31,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r17,r10,2384
	r17.s64 = ctx.r10.s64 + 2384;
	// stvx128 v21,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82749DA0:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v48,r0,r26
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v47,r0,r22
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v46,r0,r21
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v123,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82227e98
	ctx.lr = 0x82749DDC;
	sub_82227E98(ctx, base);
	// lbz r11,-21424(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + -21424);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// lvlx128 v45,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stvx128 v0,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v45,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// lvx128 v44,r0,r20
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,-21424(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + -21424);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v42,v43,v44
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v44.f32)));
	// stvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,-21424(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + -21424);
	// lvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v11,r7,r31
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r30.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v10,v0,v13,v11
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// stfs f30,288(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,292(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r27,300(r1)
	PPC_STORE_U16(ctx.r1.u32 + 300, r27.u16);
	// sth r30,302(r1)
	PPC_STORE_U16(ctx.r1.u32 + 302, r30.u16);
	// stb r30,304(r1)
	PPC_STORE_U8(ctx.r1.u32 + 304, r30.u8);
	// sth r30,306(r1)
	PPC_STORE_U16(ctx.r1.u32 + 306, r30.u16);
	// stw r30,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r30.u32);
	// beq cr6,0x8274a054
	if (cr6.eq) goto loc_8274A054;
	// lwz r10,28(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 28);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// lwz r14,12(r5)
	r14.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stvx128 v11,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r11
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r11,r15
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r11,r16
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,132(r14)
	ctx.r4.u64 = PPC_LOAD_U32(r14.u32 + 132);
	// lvx128 v38,r11,r19
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v9,v38,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xFF));
	// lvx128 v8,r4,r19
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v37,v41,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xFF));
	// lvx128 v13,r4,r15
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v36,v40,0
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// lvx128 v12,r4,r16
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v35,v39,0
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xFF));
	// lvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v7,v38,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xAA));
	// vmulfp128 v6,v0,v37
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v37.f32)));
	// vspltw128 v5,v41,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xAA));
	// vmaddfp v4,v0,v9,v8
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vspltw128 v3,v40,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xAA));
	// vmulfp128 v2,v0,v36
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v36.f32)));
	// vspltw128 v1,v39,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xAA));
	// vmulfp128 v31,v0,v35
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v35.f32)));
	// vspltw128 v34,v38,2
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x55));
	// vmaddfp v30,v13,v5,v6
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vspltw128 v33,v41,2
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0x55));
	// vspltw128 v32,v40,2
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x55));
	// vspltw128 v63,v39,2
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0x55));
	// vmaddfp v29,v13,v7,v4
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v28,v13,v3,v2
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v27,v13,v1,v31
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v31.f32)));
	// vmaddfp128 v30,v12,v33,v30
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v33.f32)), simde_mm_load_ps(v30.f32)));
	// vmaddfp128 v29,v12,v34,v29
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v34.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp128 v28,v12,v32,v28
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v32.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp128 v27,v12,v63,v27
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v63.f32)), simde_mm_load_ps(v27.f32)));
	// vor128 v126,v30,v30
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v30.u8));
	// vor128 v127,v29,v29
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)v29.u8));
	// vor128 v125,v28,v28
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_load_si128((simde__m128i*)v28.u8));
	// vor128 v124,v27,v27
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_load_si128((simde__m128i*)v27.u8));
	// vsubfp128 v62,v11,v127
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v127.f32)));
	// vsubfp128 v61,v10,v127
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v127.f32)));
	// vmsum3fp128 v60,v125,v62
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmsum3fp128 v59,v124,v62
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmsum3fp128 v58,v126,v62
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmsum3fp128 v57,v125,v61
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmsum3fp128 v56,v124,v61
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmsum3fp128 v55,v126,v61
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmrghw128 v54,v60,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v53,v58,v59
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v52,v57,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v51,v55,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v50,v53,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v49,v51,v52
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// stvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82749a50
	ctx.lr = 0x82749FA0;
	sub_82749A50(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x8257ddd8
	ctx.lr = 0x82749FB4;
	sub_8257DDD8(ctx, base);
	// lwz r11,128(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 128);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82749960
	ctx.lr = 0x82749FC8;
	sub_82749960(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8274a038
	if (cr6.eq) goto loc_8274A038;
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lvx128 v63,r0,r17
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v126,v124
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// lvx128 v62,r0,r18
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v47,v125,v127
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), simde_mm_load_si128((simde__m128i*)v125.u32)));
	// lbz r11,-21424(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + -21424);
	// vmrglw128 v46,v125,v127
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), simde_mm_load_si128((simde__m128i*)v125.u32)));
	// vmrglw128 v45,v126,v124
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// lvx128 v44,r0,r10
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v43,v44,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v42,v48,v47
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v41,v48,v47
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// vmrghw128 v40,v45,v46
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// vor128 v39,v62,v43
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// vmsum4fp128 v38,v39,v42
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v42.f32), 0xFF));
	// vmsum4fp128 v37,v39,v41
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v41.f32), 0xFF));
	// vmsum4fp128 v36,v39,v40
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32), 0xFF));
	// vmrghw128 v35,v38,v39
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v34,v37,v36
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v33,v34,v35
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// stvx128 v33,r8,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8274A038:
	// lbz r10,730(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 730);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274a04c
	if (cr6.eq) goto loc_8274A04C;
	// lwz r3,596(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 596);
	// bl 0x82130588
	ctx.lr = 0x8274A04C;
	sub_82130588(ctx, base);
loc_8274A04C:
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x82130000
	ctx.lr = 0x8274A054;
	sub_82130000(ctx, base);
loc_8274A054:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpwi cr6,r29,5
	cr6.compare<int32_t>(r29.s32, 5, xer);
	// blt cr6,0x82749da0
	if (cr6.lt) goto loc_82749DA0;
	// addi r1,r1,3072
	ctx.r1.s64 = ctx.r1.s64 + 3072;
	// addi r12,r1,-176
	r12.s64 = ctx.r1.s64 + -176;
	// bl 0x823dd7c4
	ctx.lr = 0x8274A070;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8274A07C"))) PPC_WEAK_FUNC(sub_8274A07C);
PPC_FUNC_IMPL(__imp__sub_8274A07C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A080"))) PPC_WEAK_FUNC(sub_8274A080);
PPC_FUNC_IMPL(__imp__sub_8274A080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274A088;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274A0A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8274A0C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x8218de38
	ctx.lr = 0x8274A0E0;
	sub_8218DE38(ctx, base);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,76(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274A104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// srawi r8,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 3;
	// lwz r7,96(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addze r6,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r6.s64 = temp.s64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mullw r5,r6,r9
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// mullw r5,r5,r7
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// bl 0x823da950
	ctx.lr = 0x8274A12C;
	sub_823DA950(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274A144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218d848
	ctx.lr = 0x8274A150;
	sub_8218D848(ctx, base);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bne 0x8274a170
	if (!cr0.eq) goto loc_8274A170;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218cd10
	ctx.lr = 0x8274A168;
	sub_8218CD10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8274A170;
	sub_82130588(ctx, base);
loc_8274A170:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274A17C"))) PPC_WEAK_FUNC(sub_8274A17C);
PPC_FUNC_IMPL(__imp__sub_8274A17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A180"))) PPC_WEAK_FUNC(sub_8274A180);
PPC_FUNC_IMPL(__imp__sub_8274A180) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-2004
	ctx.r10.s64 = r11.s64 + -2004;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x8274A1B0;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8274A1B8;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274a1d0
	if (cr6.eq) goto loc_8274A1D0;
	// bl 0x82130588
	ctx.lr = 0x8274A1CC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8274A1D0:
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

__attribute__((alias("__imp__sub_8274A1E8"))) PPC_WEAK_FUNC(sub_8274A1E8);
PPC_FUNC_IMPL(__imp__sub_8274A1E8) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274a210
	if (cr6.eq) goto loc_8274A210;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274A210;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274A210:
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

__attribute__((alias("__imp__sub_8274A224"))) PPC_WEAK_FUNC(sub_8274A224);
PPC_FUNC_IMPL(__imp__sub_8274A224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A228"))) PPC_WEAK_FUNC(sub_8274A228);
PPC_FUNC_IMPL(__imp__sub_8274A228) {
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
	ctx.lr = 0x8274A230;
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
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a280
	if (cr6.eq) goto loc_8274A280;
	// li r29,0
	r29.s64 = 0;
loc_8274A250:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823db730
	ctx.lr = 0x8274A264;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8274a28c
	if (cr6.eq) goto loc_8274A28C;
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8274a250
	if (cr6.lt) goto loc_8274A250;
loc_8274A280:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8274A28C:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mulli r11,r6,224
	r11.s64 = ctx.r6.s64 * 224;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274A2BC"))) PPC_WEAK_FUNC(sub_8274A2BC);
PPC_FUNC_IMPL(__imp__sub_8274A2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A2C0"))) PPC_WEAK_FUNC(sub_8274A2C0);
PPC_FUNC_IMPL(__imp__sub_8274A2C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,16(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 16);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// blt cr6,0x8274a2d4
	if (cr6.lt) goto loc_8274A2D4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8274A2D4:
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274A2E4"))) PPC_WEAK_FUNC(sub_8274A2E4);
PPC_FUNC_IMPL(__imp__sub_8274A2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A2E8"))) PPC_WEAK_FUNC(sub_8274A2E8);
PPC_FUNC_IMPL(__imp__sub_8274A2E8) {
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
	ctx.lr = 0x8274A2F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274a31c
	if (cr6.eq) goto loc_8274A31C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8217d890
	ctx.lr = 0x8274A310;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_8274A31C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a368
	if (cr6.eq) goto loc_8274A368;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r11,-2004
	r28.s64 = r11.s64 + -2004;
loc_8274A338:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add. r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274a354
	if (cr0.eq) goto loc_8274A354;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x821d2aa8
	ctx.lr = 0x8274A354;
	sub_821D2AA8(ctx, base);
loc_8274A354:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8274a338
	if (cr6.lt) goto loc_8274A338;
loc_8274A368:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274A374"))) PPC_WEAK_FUNC(sub_8274A374);
PPC_FUNC_IMPL(__imp__sub_8274A374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A378"))) PPC_WEAK_FUNC(sub_8274A378);
PPC_FUNC_IMPL(__imp__sub_8274A378) {
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
	ctx.lr = 0x8274A380;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-1972
	ctx.r10.s64 = r11.s64 + -1972;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274a3b4
	if (cr6.eq) goto loc_8274A3B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274A3B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274A3B4:
	// li r30,0
	r30.s64 = 0;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// lwz r29,12(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8274a3d8
	if (cr6.eq) goto loc_8274A3D8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821b8cf0
	ctx.lr = 0x8274A3D0;
	sub_821B8CF0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8274A3D8;
	sub_82130588(ctx, base);
loc_8274A3D8:
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r5,22(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// bl 0x826da2a0
	ctx.lr = 0x8274A3F0;
	sub_826DA2A0(ctx, base);
	// clrlwi r5,r30,16
	ctx.r5.u64 = r30.u32 & 0xFFFF;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// sth r30,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r30.u16);
	// sth r30,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r30.u16);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8274a414
	if (cr6.eq) goto loc_8274A414;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826da2a0
	ctx.lr = 0x8274A414;
	sub_826DA2A0(ctx, base);
loc_8274A414:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x8274A41C;
	sub_821D2810(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274A424"))) PPC_WEAK_FUNC(sub_8274A424);
PPC_FUNC_IMPL(__imp__sub_8274A424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A428"))) PPC_WEAK_FUNC(sub_8274A428);
PPC_FUNC_IMPL(__imp__sub_8274A428) {
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
	// bl 0x8274a378
	ctx.lr = 0x8274A448;
	sub_8274A378(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a460
	if (cr6.eq) goto loc_8274A460;
	// bl 0x82130588
	ctx.lr = 0x8274A45C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8274A460:
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

__attribute__((alias("__imp__sub_8274A478"))) PPC_WEAK_FUNC(sub_8274A478);
PPC_FUNC_IMPL(__imp__sub_8274A478) {
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
	// bl 0x821d2970
	ctx.lr = 0x8274A498;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-1972
	ctx.r10.s64 = r11.s64 + -1972;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82323d38
	ctx.lr = 0x8274A4AC;
	sub_82323D38(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x82323cb8
	ctx.lr = 0x8274A4B4;
	sub_82323CB8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8274a2e8
	ctx.lr = 0x8274A4C4;
	sub_8274A2E8(ctx, base);
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

__attribute__((alias("__imp__sub_8274A4E0"))) PPC_WEAK_FUNC(sub_8274A4E0);
PPC_FUNC_IMPL(__imp__sub_8274A4E0) {
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
	ctx.lr = 0x8274A4E8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-1956
	ctx.r10.s64 = r11.s64 + -1956;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274a51c
	if (cr6.eq) goto loc_8274A51C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274A51C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274A51C:
	// li r24,0
	r24.s64 = 0;
	// stw r24,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r24.u32);
	// mr r29,r24
	r29.u64 = r24.u64;
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a5dc
	if (cr6.eq) goto loc_8274A5DC;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r28,r24
	r28.u64 = r24.u64;
	// addi r27,r10,-1888
	r27.s64 = ctx.r10.s64 + -1888;
	// addi r26,r9,-1912
	r26.s64 = ctx.r9.s64 + -1912;
	// addi r25,r11,-1944
	r25.s64 = r11.s64 + -1944;
loc_8274A550:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r30,r11,r28
	r30.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8274a574
	if (!cr6.eq) goto loc_8274A574;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lhz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x8274A570;
	sub_82130000(ctx, base);
	// b 0x8274a59c
	goto loc_8274A59C;
loc_8274A574:
	// lwz r4,44(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8274a59c
	if (cr6.eq) goto loc_8274A59C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x8274A590;
	sub_82130000(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,28(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82130000
	ctx.lr = 0x8274A59C;
	sub_82130000(ctx, base);
loc_8274A59C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r3,r11,r28
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274a5c0
	if (cr6.eq) goto loc_8274A5C0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274A5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274A5C0:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwx r24,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r24.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lhz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8274a550
	if (cr6.lt) goto loc_8274A550;
loc_8274A5DC:
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a5f0
	if (cr6.eq) goto loc_8274A5F0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x8274A5F0;
	sub_82130588(ctx, base);
loc_8274A5F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x8274A5F8;
	sub_821D2810(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8274A600"))) PPC_WEAK_FUNC(sub_8274A600);
PPC_FUNC_IMPL(__imp__sub_8274A600) {
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
	ctx.lr = 0x8274A608;
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
	// beq cr6,0x8274a630
	if (cr6.eq) goto loc_8274A630;
	// bl 0x8217d890
	ctx.lr = 0x8274A624;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_8274A630:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a6c0
	if (cr6.eq) goto loc_8274A6C0;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_8274A650:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274a6a8
	if (cr6.eq) goto loc_8274A6A8;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8274a6a8
	if (cr6.eq) goto loc_8274A6A8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8274A67C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8274a6a8
	if (cr6.eq) goto loc_8274A6A8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8274A690;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x82504be0
	ctx.lr = 0x8274A6A4;
	sub_82504BE0(ctx, base);
	// b 0x8274a6ac
	goto loc_8274A6AC;
loc_8274A6A8:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_8274A6AC:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x8274a650
	if (cr6.lt) goto loc_8274A650;
loc_8274A6C0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8274A6CC"))) PPC_WEAK_FUNC(sub_8274A6CC);
PPC_FUNC_IMPL(__imp__sub_8274A6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A6D0"))) PPC_WEAK_FUNC(sub_8274A6D0);
PPC_FUNC_IMPL(__imp__sub_8274A6D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8274a478
	sub_8274A478(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8274A6DC"))) PPC_WEAK_FUNC(sub_8274A6DC);
PPC_FUNC_IMPL(__imp__sub_8274A6DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274A6E0"))) PPC_WEAK_FUNC(sub_8274A6E0);
PPC_FUNC_IMPL(__imp__sub_8274A6E0) {
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
	ctx.lr = 0x8274A6F8;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-1868
	ctx.r10.s64 = r11.s64 + -1868;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82323d38
	ctx.lr = 0x8274A70C;
	sub_82323D38(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x82323cb8
	ctx.lr = 0x8274A714;
	sub_82323CB8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82323eb8
	ctx.lr = 0x8274A71C;
	sub_82323EB8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// sth r11,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r11.u16);
	// sth r11,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r11.u16);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// sth r11,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r11.u16);
	// sth r11,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r11.u16);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// sth r11,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r11.u16);
	// sth r11,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r11.u16);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
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

__attribute__((alias("__imp__sub_8274A768"))) PPC_WEAK_FUNC(sub_8274A768);
PPC_FUNC_IMPL(__imp__sub_8274A768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21420(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21420);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274A774"))) PPC_WEAK_FUNC(sub_8274A774);
PPC_FUNC_IMPL(__imp__sub_8274A774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A778"))) PPC_WEAK_FUNC(sub_8274A778);
PPC_FUNC_IMPL(__imp__sub_8274A778) {
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
	ctx.lr = 0x8274A780;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-1868
	ctx.r10.s64 = r11.s64 + -1868;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274a7b4
	if (cr6.eq) goto loc_8274A7B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274A7B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274A7B4:
	// li r29,0
	r29.s64 = 0;
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274a7dc
	if (cr6.eq) goto loc_8274A7DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8274A7DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8274A7DC:
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274a7fc
	if (cr6.eq) goto loc_8274A7FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b8cf0
	ctx.lr = 0x8274A7F4;
	sub_821B8CF0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8274A7FC;
	sub_82130588(ctx, base);
loc_8274A7FC:
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// lhz r11,42(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a814
	if (cr6.eq) goto loc_8274A814;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x82130588
	ctx.lr = 0x8274A814;
	sub_82130588(ctx, base);
loc_8274A814:
	// lhz r11,34(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a828
	if (cr6.eq) goto loc_8274A828;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x8274A828;
	sub_82130588(ctx, base);
loc_8274A828:
	// lhz r30,26(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274a860
	if (cr6.eq) goto loc_8274A860;
	// lwz r28,20(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8274a858
	if (!cr6.gt) goto loc_8274A858;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_8274A844:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x8274A84C;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8274a844
	if (!cr0.eq) goto loc_8274A844;
loc_8274A858:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x8274A860;
	sub_82130588(ctx, base);
loc_8274A860:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2810
	ctx.lr = 0x8274A868;
	sub_821D2810(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274A870"))) PPC_WEAK_FUNC(sub_8274A870);
PPC_FUNC_IMPL(__imp__sub_8274A870) {
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
	ctx.lr = 0x8274A890;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-1868
	ctx.r10.s64 = r11.s64 + -1868;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82323d38
	ctx.lr = 0x8274A8A4;
	sub_82323D38(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x82323cb8
	ctx.lr = 0x8274A8AC;
	sub_82323CB8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82323eb8
	ctx.lr = 0x8274A8B4;
	sub_82323EB8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x826050f8
	ctx.lr = 0x8274A8C4;
	sub_826050F8(ctx, base);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274a8e4
	if (cr6.eq) goto loc_8274A8E4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8274A8D8;
	sub_8217D890(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
loc_8274A8E4:
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274a904
	if (cr6.eq) goto loc_8274A904;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8274A8F8;
	sub_8217D890(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
loc_8274A904:
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

__attribute__((alias("__imp__sub_8274A920"))) PPC_WEAK_FUNC(sub_8274A920);
PPC_FUNC_IMPL(__imp__sub_8274A920) {
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
	// bl 0x8274a4e0
	ctx.lr = 0x8274A940;
	sub_8274A4E0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274a958
	if (cr6.eq) goto loc_8274A958;
	// bl 0x82130588
	ctx.lr = 0x8274A954;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8274A958:
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

__attribute__((alias("__imp__sub_8274A970"))) PPC_WEAK_FUNC(sub_8274A970);
PPC_FUNC_IMPL(__imp__sub_8274A970) {
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
	ctx.lr = 0x8274A984;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274a9a0
	if (cr6.eq) goto loc_8274A9A0;
	// bl 0x8274a6e0
	ctx.lr = 0x8274A990;
	sub_8274A6E0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8274A9A0:
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

__attribute__((alias("__imp__sub_8274A9B4"))) PPC_WEAK_FUNC(sub_8274A9B4);
PPC_FUNC_IMPL(__imp__sub_8274A9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274A9B8"))) PPC_WEAK_FUNC(sub_8274A9B8);
PPC_FUNC_IMPL(__imp__sub_8274A9B8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-21420
	r31.s64 = r11.s64 + -21420;
	// lwz r11,-21420(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21420);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274aac8
	if (!cr6.eq) goto loc_8274AAC8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8274A9E8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274a9fc
	if (cr6.eq) goto loc_8274A9FC;
	// bl 0x821d5408
	ctx.lr = 0x8274A9F8;
	sub_821D5408(ctx, base);
	// b 0x8274aa00
	goto loc_8274AA00;
loc_8274A9FC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8274AA00:
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-2000
	ctx.r7.s64 = ctx.r10.s64 + -2000;
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
	// lis r8,-32139
	ctx.r8.s64 = -2106261504;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-22160
	ctx.r4.s64 = ctx.r8.s64 + -22160;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r3,-5296
	ctx.r9.s64 = ctx.r3.s64 + -5296;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r10,20
	ctx.r10.s64 = 20;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8274AA74;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8274AA84;
	sub_821D4100(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x821d41d0
	ctx.lr = 0x8274AAA0;
	sub_821D41D0(ctx, base);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,-5304
	ctx.r4.s64 = ctx.r5.s64 + -5304;
	// bl 0x821d4b00
	ctx.lr = 0x8274AAB0;
	sub_821D4B00(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,2828(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x8274AAC8;
	sub_821C0548(ctx, base);
loc_8274AAC8:
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

__attribute__((alias("__imp__sub_8274AAE0"))) PPC_WEAK_FUNC(sub_8274AAE0);
PPC_FUNC_IMPL(__imp__sub_8274AAE0) {
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
	// bl 0x8274a778
	ctx.lr = 0x8274AB00;
	sub_8274A778(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ab18
	if (cr6.eq) goto loc_8274AB18;
	// bl 0x82130588
	ctx.lr = 0x8274AB14;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8274AB18:
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

__attribute__((alias("__imp__sub_8274AB30"))) PPC_WEAK_FUNC(sub_8274AB30);
PPC_FUNC_IMPL(__imp__sub_8274AB30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8274a870
	sub_8274A870(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8274AB3C"))) PPC_WEAK_FUNC(sub_8274AB3C);
PPC_FUNC_IMPL(__imp__sub_8274AB3C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274AB40"))) PPC_WEAK_FUNC(sub_8274AB40);
PPC_FUNC_IMPL(__imp__sub_8274AB40) {
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
	// beq cr6,0x8274ab8c
	if (cr6.eq) goto loc_8274AB8C;
	// bl 0x821d2970
	ctx.lr = 0x8274AB68;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-1956
	ctx.r10.s64 = r11.s64 + -1956;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8236f840
	ctx.lr = 0x8274AB7C;
	sub_8236F840(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x8274a600
	ctx.lr = 0x8274AB8C;
	sub_8274A600(ctx, base);
loc_8274AB8C:
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

__attribute__((alias("__imp__sub_8274ABA4"))) PPC_WEAK_FUNC(sub_8274ABA4);
PPC_FUNC_IMPL(__imp__sub_8274ABA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274ABA8"))) PPC_WEAK_FUNC(sub_8274ABA8);
PPC_FUNC_IMPL(__imp__sub_8274ABA8) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274ABAC"))) PPC_WEAK_FUNC(sub_8274ABAC);
PPC_FUNC_IMPL(__imp__sub_8274ABAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274ABB0"))) PPC_WEAK_FUNC(sub_8274ABB0);
PPC_FUNC_IMPL(__imp__sub_8274ABB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r31.u64);
	// mflr r31
	r31.u64 = ctx.lr;
	// stwu r1,-80(r1)
	ea = -80 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x827bdca4
	ctx.lr = 0x8274ABC8;
	__imp__RtlUnwind(ctx, base);
	// mtlr r31
	ctx.lr = r31.u64;
	// ld r31,8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 8);
	// addi r1,r1,80
	ctx.r1.s64 = ctx.r1.s64 + 80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274ABD8"))) PPC_WEAK_FUNC(sub_8274ABD8);
PPC_FUNC_IMPL(__imp__sub_8274ABD8) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8274ac1c
	if (!cr6.eq) goto loc_8274AC1C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8274ac24
	if (!cr6.eq) goto loc_8274AC24;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8274ac2c
	if (!cr6.eq) goto loc_8274AC2C;
loc_8274AC04:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274AC08:
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
loc_8274AC1C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274ac2c
	if (cr6.eq) goto loc_8274AC2C;
loc_8274AC24:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8274ac58
	if (!cr6.eq) goto loc_8274AC58;
loc_8274AC2C:
	// bl 0x823e1000
	ctx.lr = 0x8274AC30;
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
	ctx.lr = 0x8274AC50;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8274ac08
	goto loc_8274AC08;
loc_8274AC58:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8274ac6c
	if (!cr6.eq) goto loc_8274AC6C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// b 0x8274ac04
	goto loc_8274AC04;
loc_8274AC6C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8274aca8
	if (!cr6.eq) goto loc_8274ACA8;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// bl 0x823e1000
	ctx.lr = 0x8274AC80;
	sub_823E1000(ctx, base);
	// li r31,22
	r31.s64 = 22;
loc_8274AC84:
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x8274ACA0;
	sub_823E02A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x8274ac08
	goto loc_8274AC08;
loc_8274ACA8:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// bne cr6,0x8274ace0
	if (!cr6.eq) goto loc_8274ACE0;
loc_8274ACBC:
	// lbz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi r7,0
	cr0.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beq 0x8274ad14
	if (cr0.eq) goto loc_8274AD14;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8274acbc
	if (!cr0.eq) goto loc_8274ACBC;
	// b 0x8274ad14
	goto loc_8274AD14;
loc_8274ACE0:
	// lbz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi r7,0
	cr0.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beq 0x8274ad08
	if (cr0.eq) goto loc_8274AD08;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8274ad08
	if (cr0.eq) goto loc_8274AD08;
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne 0x8274ace0
	if (!cr0.eq) goto loc_8274ACE0;
loc_8274AD08:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8274ad14
	if (!cr6.eq) goto loc_8274AD14;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
loc_8274AD14:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8274ac04
	if (!cr6.eq) goto loc_8274AC04;
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// bne cr6,0x8274ad34
	if (!cr6.eq) goto loc_8274AD34;
	// add r11,r10,r4
	r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// li r3,80
	ctx.r3.s64 = 80;
	// stb r8,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r8.u8);
	// b 0x8274ac08
	goto loc_8274AC08;
loc_8274AD34:
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// bl 0x823e1000
	ctx.lr = 0x8274AD3C;
	sub_823E1000(ctx, base);
	// li r31,34
	r31.s64 = 34;
	// b 0x8274ac84
	goto loc_8274AC84;
}

__attribute__((alias("__imp__sub_8274AD44"))) PPC_WEAK_FUNC(sub_8274AD44);
PPC_FUNC_IMPL(__imp__sub_8274AD44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274AD48"))) PPC_WEAK_FUNC(sub_8274AD48);
PPC_FUNC_IMPL(__imp__sub_8274AD48) {
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
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274ad6c
	if (cr6.eq) goto loc_8274AD6C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8274ad98
	if (!cr6.eq) goto loc_8274AD98;
loc_8274AD6C:
	// bl 0x823e1000
	ctx.lr = 0x8274AD70;
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
	ctx.lr = 0x8274AD90;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8274ae44
	goto loc_8274AE44;
loc_8274AD98:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8274adac
	if (!cr6.eq) goto loc_8274ADAC;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// b 0x8274ad6c
	goto loc_8274AD6C;
loc_8274ADAC:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8274ADB0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274adc8
	if (cr6.eq) goto loc_8274ADC8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x8274adb0
	if (!cr0.eq) goto loc_8274ADB0;
loc_8274ADC8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8274ae04
	if (!cr6.eq) goto loc_8274AE04;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// bl 0x823e1000
	ctx.lr = 0x8274ADDC;
	sub_823E1000(ctx, base);
	// li r31,22
	r31.s64 = 22;
loc_8274ADE0:
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x8274ADFC;
	sub_823E02A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x8274ae44
	goto loc_8274AE44;
loc_8274AE04:
	// lbz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi r9,0
	cr0.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beq 0x8274ae24
	if (cr0.eq) goto loc_8274AE24;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8274ae04
	if (!cr0.eq) goto loc_8274AE04;
loc_8274AE24:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8274ae40
	if (!cr6.eq) goto loc_8274AE40;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// bl 0x823e1000
	ctx.lr = 0x8274AE38;
	sub_823E1000(ctx, base);
	// li r31,34
	r31.s64 = 34;
	// b 0x8274ade0
	goto loc_8274ADE0;
loc_8274AE40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274AE44:
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

__attribute__((alias("__imp__sub_8274AE58"))) PPC_WEAK_FUNC(sub_8274AE58);
PPC_FUNC_IMPL(__imp__sub_8274AE58) {
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
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8274ae98
	if (!cr6.eq) goto loc_8274AE98;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8274aea0
	if (!cr6.eq) goto loc_8274AEA0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8274aea8
	if (!cr6.eq) goto loc_8274AEA8;
loc_8274AE80:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274AE84:
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
loc_8274AE98:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274aea8
	if (cr6.eq) goto loc_8274AEA8;
loc_8274AEA0:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8274aed4
	if (!cr6.eq) goto loc_8274AED4;
loc_8274AEA8:
	// bl 0x823e1000
	ctx.lr = 0x8274AEAC;
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
	ctx.lr = 0x8274AECC;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8274ae84
	goto loc_8274AE84;
loc_8274AED4:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8274aef0
	if (cr6.eq) goto loc_8274AEF0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8274aef0
	if (!cr6.eq) goto loc_8274AEF0;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// b 0x8274aea8
	goto loc_8274AEA8;
loc_8274AEF0:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_8274AEF8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274af10
	if (cr6.eq) goto loc_8274AF10;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x8274aef8
	if (!cr0.eq) goto loc_8274AEF8;
loc_8274AF10:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8274af4c
	if (!cr6.eq) goto loc_8274AF4C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// bl 0x823e1000
	ctx.lr = 0x8274AF24;
	sub_823E1000(ctx, base);
	// li r31,22
	r31.s64 = 22;
loc_8274AF28:
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x8274AF44;
	sub_823E02A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x8274ae84
	goto loc_8274AE84;
loc_8274AF4C:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// bne cr6,0x8274af7c
	if (!cr6.eq) goto loc_8274AF7C;
loc_8274AF58:
	// lbz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi r8,0
	cr0.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beq 0x8274afb8
	if (cr0.eq) goto loc_8274AFB8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8274af58
	if (!cr0.eq) goto loc_8274AF58;
	// b 0x8274afb8
	goto loc_8274AFB8;
loc_8274AF7C:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8274afb4
	if (cr6.eq) goto loc_8274AFB4;
loc_8274AF84:
	// lbz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi r8,0
	cr0.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beq 0x8274afac
	if (cr0.eq) goto loc_8274AFAC;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8274afac
	if (cr0.eq) goto loc_8274AFAC;
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne 0x8274af84
	if (!cr0.eq) goto loc_8274AF84;
loc_8274AFAC:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8274afb8
	if (!cr6.eq) goto loc_8274AFB8;
loc_8274AFB4:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
loc_8274AFB8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8274ae80
	if (!cr6.eq) goto loc_8274AE80;
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// bne cr6,0x8274afd8
	if (!cr6.eq) goto loc_8274AFD8;
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// li r3,80
	ctx.r3.s64 = 80;
	// stb r9,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r9.u8);
	// b 0x8274ae84
	goto loc_8274AE84;
loc_8274AFD8:
	// stb r9,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r9.u8);
	// bl 0x823e1000
	ctx.lr = 0x8274AFE0;
	sub_823E1000(ctx, base);
	// li r31,34
	r31.s64 = 34;
	// b 0x8274af28
	goto loc_8274AF28;
}

__attribute__((alias("__imp__sub_8274AFE8"))) PPC_WEAK_FUNC(sub_8274AFE8);
PPC_FUNC_IMPL(__imp__sub_8274AFE8) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274AFEC"))) PPC_WEAK_FUNC(sub_8274AFEC);
PPC_FUNC_IMPL(__imp__sub_8274AFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274AFF0"))) PPC_WEAK_FUNC(sub_8274AFF0);
PPC_FUNC_IMPL(__imp__sub_8274AFF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr7{};
	uint32_t ea{};
	// lbz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
loc_8274AFFC:
	// cmpwi cr7,r6,0
	cr7.compare<int32_t>(ctx.r6.s32, 0, xer);
	// subf. r3,r6,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr7,0x8274b018
	if (cr7.eq) goto loc_8274B018;
	// bne 0x8274b018
	if (!cr0.eq) goto loc_8274B018;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// b 0x8274affc
	goto loc_8274AFFC;
loc_8274B018:
	// beqlr 
	if (cr0.eq) return;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bltlr 
	if (cr0.lt) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274B02C"))) PPC_WEAK_FUNC(sub_8274B02C);
PPC_FUNC_IMPL(__imp__sub_8274B02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274B030"))) PPC_WEAK_FUNC(sub_8274B030);
PPC_FUNC_IMPL(__imp__sub_8274B030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-2816(r1)
	ea = -2816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,-5088(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5088);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b058
	if (cr0.eq) goto loc_8274B058;
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x823e2740
	ctx.lr = 0x8274B058;
	sub_823E2740(ctx, base);
loc_8274B058:
	// bl 0x8274b0e0
	ctx.lr = 0x8274B05C;
	sub_8274B0E0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8274b06c
	if (cr0.eq) goto loc_8274B06C;
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x8274b0f8
	ctx.lr = 0x8274B06C;
	sub_8274B0F8(ctx, base);
loc_8274B06C:
	// lwz r11,-5088(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5088);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b0d8
	if (cr0.eq) goto loc_8274B0D8;
	// li r5,2624
	ctx.r5.s64 = 2624;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823d9890
	ctx.lr = 0x8274B088;
	sub_823D9890(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,10
	ctx.r10.s64 = 10;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8274B098:
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x8274b098
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8274B098;
	// lwz r10,2808(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2808);
	// lis r11,16384
	r11.s64 = 1073741824;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,21
	r11.u64 = r11.u64 | 21;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82131e30
	ctx.lr = 0x8274B0D0;
	sub_82131E30(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82131f00
	ctx.lr = 0x8274B0D8;
	sub_82131F00(ctx, base);
loc_8274B0D8:
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x823db0b0
	ctx.lr = 0x8274B0E0;
	sub_823DB0B0(ctx, base);
}

__attribute__((alias("__imp__sub_8274B0E0"))) PPC_WEAK_FUNC(sub_8274B0E0);
PPC_FUNC_IMPL(__imp__sub_8274B0E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21408(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21408);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274B0EC"))) PPC_WEAK_FUNC(sub_8274B0EC);
PPC_FUNC_IMPL(__imp__sub_8274B0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274B0F0"))) PPC_WEAK_FUNC(sub_8274B0F0);
PPC_FUNC_IMPL(__imp__sub_8274B0F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r16,10032(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 10032);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8274B100;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r29,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r29.u32);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r29,11
	cr6.compare<int32_t>(r29.s32, 11, xer);
	// mr r28,r26
	r28.u64 = r26.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// stw r28,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r28.u32);
	// stw r27,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r27.u32);
	// bgt cr6,0x8274b1d4
	if (cr6.gt) goto loc_8274B1D4;
	// beq cr6,0x8274b150
	if (cr6.eq) goto loc_8274B150;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// beq cr6,0x8274b168
	if (cr6.eq) goto loc_8274B168;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// beq cr6,0x8274b150
	if (cr6.eq) goto loc_8274B150;
	// cmpwi cr6,r29,6
	cr6.compare<int32_t>(r29.s32, 6, xer);
	// beq cr6,0x8274b214
	if (cr6.eq) goto loc_8274B214;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// bne cr6,0x8274b1ec
	if (!cr6.eq) goto loc_8274B1EC;
loc_8274B150:
	// bl 0x823db208
	ctx.lr = 0x8274B154;
	sub_823DB208(ctx, base);
	// mr. r27,r3
	r27.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// stw r27,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r27.u32);
	// bne 0x8274b178
	if (!cr0.eq) goto loc_8274B178;
loc_8274B160:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8274b390
	goto loc_8274B390;
loc_8274B168:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r30,r11,-21416
	r30.s64 = r11.s64 + -21416;
	// lwz r11,-21416(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21416);
	// b 0x8274b24c
	goto loc_8274B24C;
loc_8274B178:
	// lwz r10,92(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 92);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lwz r8,-17740(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17740);
loc_8274B188:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// beq cr6,0x8274b1a8
	if (cr6.eq) goto loc_8274B1A8;
	// mulli r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 * 12;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8274b188
	if (cr6.lt) goto loc_8274B188;
loc_8274B1A8:
	// mulli r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 * 12;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274b1c4
	if (!cr6.lt) goto loc_8274B1C4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// beq cr6,0x8274b1c8
	if (cr6.eq) goto loc_8274B1C8;
loc_8274B1C4:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8274B1C8:
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8274b254
	goto loc_8274B254;
loc_8274B1D4:
	// cmpwi cr6,r29,15
	cr6.compare<int32_t>(r29.s32, 15, xer);
	// beq cr6,0x8274b23c
	if (cr6.eq) goto loc_8274B23C;
	// cmpwi cr6,r29,21
	cr6.compare<int32_t>(r29.s32, 21, xer);
	// beq cr6,0x8274b228
	if (cr6.eq) goto loc_8274B228;
	// cmpwi cr6,r29,22
	cr6.compare<int32_t>(r29.s32, 22, xer);
	// beq cr6,0x8274b214
	if (cr6.eq) goto loc_8274B214;
loc_8274B1EC:
	// bl 0x823e1000
	ctx.lr = 0x8274B1F0;
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
	ctx.lr = 0x8274B210;
	sub_823E02A8(ctx, base);
	// b 0x8274b160
	goto loc_8274B160;
loc_8274B214:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r11,r11,-21416
	r11.s64 = r11.s64 + -21416;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8274b24c
	goto loc_8274B24C;
loc_8274B228:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r11,r11,-21416
	r11.s64 = r11.s64 + -21416;
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x8274b24c
	goto loc_8274B24C;
loc_8274B23C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r11,r11,-21416
	r11.s64 = r11.s64 + -21416;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
loc_8274B24C:
	// li r28,1
	r28.s64 = 1;
	// stw r28,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r28.u32);
loc_8274B254:
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8274b38c
	if (cr6.eq) goto loc_8274B38C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274b270
	if (!cr6.eq) goto loc_8274B270;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x823db0b0
	ctx.lr = 0x8274B270;
	sub_823DB0B0(ctx, base);
loc_8274B270:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8274b280
	if (cr6.eq) goto loc_8274B280;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e2a08
	ctx.lr = 0x8274B280;
	sub_823E2A08(ctx, base);
loc_8274B280:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// beq cr6,0x8274b2a0
	if (cr6.eq) goto loc_8274B2A0;
	// cmpwi cr6,r29,11
	cr6.compare<int32_t>(r29.s32, 11, xer);
	// beq cr6,0x8274b2a0
	if (cr6.eq) goto loc_8274B2A0;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// bne cr6,0x8274b2c4
	if (!cr6.eq) goto loc_8274B2C4;
loc_8274B2A0:
	// lwz r11,96(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 96);
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stw r26,96(r27)
	PPC_STORE_U32(r27.u32 + 96, r26.u32);
	// bne cr6,0x8274b314
	if (!cr6.eq) goto loc_8274B314;
	// lwz r11,100(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 100);
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r10,100(r27)
	PPC_STORE_U32(r27.u32 + 100, ctx.r10.u32);
loc_8274B2C4:
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// bne cr6,0x8274b314
	if (!cr6.eq) goto loc_8274B314;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// lwz r10,-17752(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17752);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
loc_8274B2E0:
	// lwz r9,-17748(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + -17748);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8274b318
	if (!cr6.lt) goto loc_8274B318;
	// lwz r9,92(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 92);
	// mulli r10,r11,12
	ctx.r10.s64 = r11.s64 * 12;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r26,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r26.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// lwz r10,-17752(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17752);
	// b 0x8274b2e0
	goto loc_8274B2E0;
loc_8274B314:
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
loc_8274B318:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x8274b3b8
	ctx.lr = 0x8274B324;
	sub_8274B3B8(ctx, base);
	// lwz r30,180(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bne cr6,0x8274b34c
	if (!cr6.eq) goto loc_8274B34C;
	// lwz r29,88(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r4,100(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274B348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8274b35c
	goto loc_8274B35C;
loc_8274B34C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274B358;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r29,88(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 88);
loc_8274B35C:
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// beq cr6,0x8274b374
	if (cr6.eq) goto loc_8274B374;
	// cmpwi cr6,r30,11
	cr6.compare<int32_t>(r30.s32, 11, xer);
	// beq cr6,0x8274b374
	if (cr6.eq) goto loc_8274B374;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x8274b38c
	if (!cr6.eq) goto loc_8274B38C;
loc_8274B374:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// stw r11,96(r29)
	PPC_STORE_U32(r29.u32 + 96, r11.u32);
	// bne cr6,0x8274b38c
	if (!cr6.eq) goto loc_8274B38C;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// stw r11,100(r29)
	PPC_STORE_U32(r29.u32 + 100, r11.u32);
loc_8274B38C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274B390:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274B0F8"))) PPC_WEAK_FUNC(sub_8274B0F8);
PPC_FUNC_IMPL(__imp__sub_8274B0F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8274B100;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r29,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r29.u32);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r29,11
	cr6.compare<int32_t>(r29.s32, 11, xer);
	// mr r28,r26
	r28.u64 = r26.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// stw r28,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r28.u32);
	// stw r27,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r27.u32);
	// bgt cr6,0x8274b1d4
	if (cr6.gt) goto loc_8274B1D4;
	// beq cr6,0x8274b150
	if (cr6.eq) goto loc_8274B150;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// beq cr6,0x8274b168
	if (cr6.eq) goto loc_8274B168;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// beq cr6,0x8274b150
	if (cr6.eq) goto loc_8274B150;
	// cmpwi cr6,r29,6
	cr6.compare<int32_t>(r29.s32, 6, xer);
	// beq cr6,0x8274b214
	if (cr6.eq) goto loc_8274B214;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// bne cr6,0x8274b1ec
	if (!cr6.eq) goto loc_8274B1EC;
loc_8274B150:
	// bl 0x823db208
	ctx.lr = 0x8274B154;
	sub_823DB208(ctx, base);
	// mr. r27,r3
	r27.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// stw r27,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r27.u32);
	// bne 0x8274b178
	if (!cr0.eq) goto loc_8274B178;
loc_8274B160:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8274b390
	goto loc_8274B390;
loc_8274B168:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r30,r11,-21416
	r30.s64 = r11.s64 + -21416;
	// lwz r11,-21416(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21416);
	// b 0x8274b24c
	goto loc_8274B24C;
loc_8274B178:
	// lwz r10,92(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 92);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lwz r8,-17740(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17740);
loc_8274B188:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// beq cr6,0x8274b1a8
	if (cr6.eq) goto loc_8274B1A8;
	// mulli r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 * 12;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8274b188
	if (cr6.lt) goto loc_8274B188;
loc_8274B1A8:
	// mulli r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 * 12;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274b1c4
	if (!cr6.lt) goto loc_8274B1C4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// beq cr6,0x8274b1c8
	if (cr6.eq) goto loc_8274B1C8;
loc_8274B1C4:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8274B1C8:
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8274b254
	goto loc_8274B254;
loc_8274B1D4:
	// cmpwi cr6,r29,15
	cr6.compare<int32_t>(r29.s32, 15, xer);
	// beq cr6,0x8274b23c
	if (cr6.eq) goto loc_8274B23C;
	// cmpwi cr6,r29,21
	cr6.compare<int32_t>(r29.s32, 21, xer);
	// beq cr6,0x8274b228
	if (cr6.eq) goto loc_8274B228;
	// cmpwi cr6,r29,22
	cr6.compare<int32_t>(r29.s32, 22, xer);
	// beq cr6,0x8274b214
	if (cr6.eq) goto loc_8274B214;
loc_8274B1EC:
	// bl 0x823e1000
	ctx.lr = 0x8274B1F0;
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
	ctx.lr = 0x8274B210;
	sub_823E02A8(ctx, base);
	// b 0x8274b160
	goto loc_8274B160;
loc_8274B214:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r11,r11,-21416
	r11.s64 = r11.s64 + -21416;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8274b24c
	goto loc_8274B24C;
loc_8274B228:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r11,r11,-21416
	r11.s64 = r11.s64 + -21416;
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x8274b24c
	goto loc_8274B24C;
loc_8274B23C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r11,r11,-21416
	r11.s64 = r11.s64 + -21416;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
loc_8274B24C:
	// li r28,1
	r28.s64 = 1;
	// stw r28,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r28.u32);
loc_8274B254:
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8274b38c
	if (cr6.eq) goto loc_8274B38C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274b270
	if (!cr6.eq) goto loc_8274B270;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x823db0b0
	ctx.lr = 0x8274B270;
	sub_823DB0B0(ctx, base);
loc_8274B270:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8274b280
	if (cr6.eq) goto loc_8274B280;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e2a08
	ctx.lr = 0x8274B280;
	sub_823E2A08(ctx, base);
loc_8274B280:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// beq cr6,0x8274b2a0
	if (cr6.eq) goto loc_8274B2A0;
	// cmpwi cr6,r29,11
	cr6.compare<int32_t>(r29.s32, 11, xer);
	// beq cr6,0x8274b2a0
	if (cr6.eq) goto loc_8274B2A0;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// bne cr6,0x8274b2c4
	if (!cr6.eq) goto loc_8274B2C4;
loc_8274B2A0:
	// lwz r11,96(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 96);
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stw r26,96(r27)
	PPC_STORE_U32(r27.u32 + 96, r26.u32);
	// bne cr6,0x8274b314
	if (!cr6.eq) goto loc_8274B314;
	// lwz r11,100(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 100);
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r10,100(r27)
	PPC_STORE_U32(r27.u32 + 100, ctx.r10.u32);
loc_8274B2C4:
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// bne cr6,0x8274b314
	if (!cr6.eq) goto loc_8274B314;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// lwz r10,-17752(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17752);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
loc_8274B2E0:
	// lwz r9,-17748(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + -17748);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8274b318
	if (!cr6.lt) goto loc_8274B318;
	// lwz r9,92(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 92);
	// mulli r10,r11,12
	ctx.r10.s64 = r11.s64 * 12;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r26,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r26.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// lwz r10,-17752(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17752);
	// b 0x8274b2e0
	goto loc_8274B2E0;
loc_8274B314:
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
loc_8274B318:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,160
	r12.s64 = r31.s64 + 160;
	// bl 0x8274b3b8
	ctx.lr = 0x8274B324;
	sub_8274B3B8(ctx, base);
	// lwz r30,180(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bne cr6,0x8274b34c
	if (!cr6.eq) goto loc_8274B34C;
	// lwz r29,88(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r4,100(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274B348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8274b35c
	goto loc_8274B35C;
loc_8274B34C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274B358;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r29,88(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 88);
loc_8274B35C:
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// beq cr6,0x8274b374
	if (cr6.eq) goto loc_8274B374;
	// cmpwi cr6,r30,11
	cr6.compare<int32_t>(r30.s32, 11, xer);
	// beq cr6,0x8274b374
	if (cr6.eq) goto loc_8274B374;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x8274b38c
	if (!cr6.eq) goto loc_8274B38C;
loc_8274B374:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// stw r11,96(r29)
	PPC_STORE_U32(r29.u32 + 96, r11.u32);
	// bne cr6,0x8274b38c
	if (!cr6.eq) goto loc_8274B38C;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// stw r11,100(r29)
	PPC_STORE_U32(r29.u32 + 100, r11.u32);
loc_8274B38C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8274B390:
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274B398"))) PPC_WEAK_FUNC(sub_8274B398);
PPC_FUNC_IMPL(__imp__sub_8274B398) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,84(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// b 0x8274b3d0
	goto loc_8274B3D0;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_8274B3D0:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8274b3e0
	if (cr6.eq) goto loc_8274B3E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e28a8
	ctx.lr = 0x8274B3E0;
	sub_823E28A8(ctx, base);
loc_8274B3E0:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r28,-16(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274B3B8"))) PPC_WEAK_FUNC(sub_8274B3B8);
PPC_FUNC_IMPL(__imp__sub_8274B3B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-160
	r31.s64 = r12.s64 + -160;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8274b3e0
	if (cr6.eq) goto loc_8274B3E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e28a8
	ctx.lr = 0x8274B3E0;
	sub_823E28A8(ctx, base);
loc_8274B3E0:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r28,-16(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274B3F8"))) PPC_WEAK_FUNC(sub_8274B3F8);
PPC_FUNC_IMPL(__imp__sub_8274B3F8) {
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
	// li r11,0
	r11.s64 = 0;
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,5
	ctx.r4.s64 = 327680;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r4,r4,32782
	ctx.r4.u64 = ctx.r4.u64 | 32782;
	// li r3,252
	ctx.r3.s64 = 252;
	// bl 0x827bd0d4
	ctx.lr = 0x8274B42C;
	__imp__XMsgInProcessCall(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274B440"))) PPC_WEAK_FUNC(sub_8274B440);
PPC_FUNC_IMPL(__imp__sub_8274B440) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8274B448;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// mr r22,r10
	r22.u64 = ctx.r10.u64;
	// cmplwi cr6,r29,4
	cr6.compare<uint32_t>(r29.u32, 4, xer);
	// bge cr6,0x8274b5dc
	if (!cr6.lt) goto loc_8274B5DC;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8274b5dc
	if (cr6.eq) goto loc_8274B5DC;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274b5dc
	if (cr6.eq) goto loc_8274B5DC;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8274b5dc
	if (cr6.eq) goto loc_8274B5DC;
	// li r11,-1
	r11.s64 = -1;
	// rlwinm r10,r31,0,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFC0;
	// stw r11,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r11.u32);
	// rlwinm. r10,r10,0,24,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFC0FF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8274b5dc
	if (!cr0.eq) goto loc_8274B5DC;
	// rlwinm. r10,r31,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8274b4b0
	if (cr0.eq) goto loc_8274B4B0;
	// rlwinm. r11,r31,0,26,26
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b5dc
	if (cr0.eq) goto loc_8274B5DC;
loc_8274B4B0:
	// rlwinm. r11,r31,0,27,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b4c0
	if (cr0.eq) goto loc_8274B4C0;
	// rlwinm. r9,r31,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8274b5dc
	if (cr0.eq) goto loc_8274B5DC;
loc_8274B4C0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274b4d0
	if (cr6.eq) goto loc_8274B4D0;
	// rlwinm. r11,r31,0,26,26
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b5dc
	if (cr0.eq) goto loc_8274B5DC;
loc_8274B4D0:
	// clrlwi. r11,r31,31
	r11.u64 = r31.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b4e4
	if (cr0.eq) goto loc_8274B4E4;
	// andi. r11,r31,44
	r11.u64 = r31.u64 & 44;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x8274b5dc
	if (cr0.eq) goto loc_8274B5DC;
loc_8274B4E4:
	// rlwinm. r11,r31,0,20,23
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xF00;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b524
	if (cr0.eq) goto loc_8274B524;
	// andi. r9,r31,10
	ctx.r9.u64 = r31.u64 & 10;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// cmplwi r9,0
	cr0.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq 0x8274b5dc
	if (cr0.eq) goto loc_8274B5DC;
	// rlwinm. r9,r31,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8274b514
	if (!cr0.eq) goto loc_8274B514;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274b514
	if (cr6.eq) goto loc_8274B514;
	// rlwinm r10,r31,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x400;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274b5dc
	if (!cr6.eq) goto loc_8274B5DC;
loc_8274B514:
	// rlwinm. r11,r31,0,22,22
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x200;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b524
	if (cr0.eq) goto loc_8274B524;
	// rlwinm. r11,r31,0,20,20
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274b5dc
	if (!cr0.eq) goto loc_8274B5DC;
loc_8274B524:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x827bdbf4
	ctx.lr = 0x8274B52C;
	__imp__XamSessionCreateHandle(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8274b5e0
	if (!cr0.eq) goto loc_8274B5E0;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,0(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// bl 0x827bdbe4
	ctx.lr = 0x8274B548;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8274b5e0
	if (!cr0.eq) goto loc_8274B5E0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// li r7,28
	ctx.r7.s64 = 28;
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r23,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r23.u32);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// stw r24,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r24.u32);
	// ori r4,r4,16
	ctx.r4.u64 = ctx.r4.u64 | 16;
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r26.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r27,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r27.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274B58C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274b59c
	if (!cr0.lt) goto loc_8274B59C;
	// li r30,1627
	r30.s64 = 1627;
	// b 0x8274b5cc
	goto loc_8274B5CC;
loc_8274B59C:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8274b5b8
	if (!cr6.eq) goto loc_8274B5B8;
	// bl 0x82135d90
	ctx.lr = 0x8274B5A8;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r30,r11,1627
	r30.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// b 0x8274b5bc
	goto loc_8274B5BC;
loc_8274B5B8:
	// li r30,997
	r30.s64 = 997;
loc_8274B5BC:
	// cmplwi cr6,r30,997
	cr6.compare<uint32_t>(r30.u32, 997, xer);
	// beq cr6,0x8274b5e0
	if (cr6.eq) goto loc_8274B5E0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274b5e0
	if (cr6.eq) goto loc_8274B5E0;
loc_8274B5CC:
	// lwz r3,0(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// bl 0x8244eee0
	ctx.lr = 0x8274B5D4;
	sub_8244EEE0(ctx, base);
	// stw r28,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r28.u32);
	// b 0x8274b5e0
	goto loc_8274B5E0;
loc_8274B5DC:
	// li r30,87
	r30.s64 = 87;
loc_8274B5E0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8274B5EC"))) PPC_WEAK_FUNC(sub_8274B5EC);
PPC_FUNC_IMPL(__imp__sub_8274B5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274B5F0"))) PPC_WEAK_FUNC(sub_8274B5F0);
PPC_FUNC_IMPL(__imp__sub_8274B5F0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8274B5F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// rlwinm. r11,r31,0,22,22
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x200;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b624
	if (cr0.eq) goto loc_8274B624;
	// rlwinm. r11,r31,0,20,20
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274b624
	if (cr0.eq) goto loc_8274B624;
	// li r30,87
	r30.s64 = 87;
	// b 0x8274b69c
	goto loc_8274B69C;
loc_8274B624:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274B62C;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8274b69c
	if (!cr0.eq) goto loc_8274B69C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ori r4,r4,24
	ctx.r4.u64 = ctx.r4.u64 | 24;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274B664;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274b674
	if (!cr0.lt) goto loc_8274B674;
	// li r30,1627
	r30.s64 = 1627;
	// b 0x8274b694
	goto loc_8274B694;
loc_8274B674:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8274b690
	if (!cr6.eq) goto loc_8274B690;
	// bl 0x82135d90
	ctx.lr = 0x8274B680;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r30,r11,1627
	r30.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// b 0x8274b694
	goto loc_8274B694;
loc_8274B690:
	// li r30,997
	r30.s64 = 997;
loc_8274B694:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274B69C;
	__imp__ObDereferenceObject(ctx, base);
loc_8274B69C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274B6A8"))) PPC_WEAK_FUNC(sub_8274B6A8);
PPC_FUNC_IMPL(__imp__sub_8274B6A8) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274B6C8;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274b738
	if (!cr0.eq) goto loc_8274B738;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	r11.s64 = 0;
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// ori r4,r4,17
	ctx.r4.u64 = ctx.r4.u64 | 17;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274B700;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274b710
	if (!cr0.lt) goto loc_8274B710;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274b730
	goto loc_8274B730;
loc_8274B710:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274b72c
	if (!cr6.eq) goto loc_8274B72C;
	// bl 0x82135d90
	ctx.lr = 0x8274B71C;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274b730
	goto loc_8274B730;
loc_8274B72C:
	// li r31,997
	r31.s64 = 997;
loc_8274B730:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274B738;
	__imp__ObDereferenceObject(ctx, base);
loc_8274B738:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8274B754"))) PPC_WEAK_FUNC(sub_8274B754);
PPC_FUNC_IMPL(__imp__sub_8274B754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274B758"))) PPC_WEAK_FUNC(sub_8274B758);
PPC_FUNC_IMPL(__imp__sub_8274B758) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8274B760;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274B77C;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274b7f4
	if (!cr0.eq) goto loc_8274B7F4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// li r7,20
	ctx.r7.s64 = 20;
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// ori r4,r4,18
	ctx.r4.u64 = ctx.r4.u64 | 18;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274B7BC;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274b7cc
	if (!cr0.lt) goto loc_8274B7CC;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274b7ec
	goto loc_8274B7EC;
loc_8274B7CC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274b7e8
	if (!cr6.eq) goto loc_8274B7E8;
	// bl 0x82135d90
	ctx.lr = 0x8274B7D8;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274b7ec
	goto loc_8274B7EC;
loc_8274B7E8:
	// li r31,997
	r31.s64 = 997;
loc_8274B7EC:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274B7F4;
	__imp__ObDereferenceObject(ctx, base);
loc_8274B7F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274B800"))) PPC_WEAK_FUNC(sub_8274B800);
PPC_FUNC_IMPL(__imp__sub_8274B800) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8274B808;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274B824;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274b89c
	if (!cr0.eq) goto loc_8274B89C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// li r7,20
	ctx.r7.s64 = 20;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// ori r4,r4,18
	ctx.r4.u64 = ctx.r4.u64 | 18;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274B864;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274b874
	if (!cr0.lt) goto loc_8274B874;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274b894
	goto loc_8274B894;
loc_8274B874:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274b890
	if (!cr6.eq) goto loc_8274B890;
	// bl 0x82135d90
	ctx.lr = 0x8274B880;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274b894
	goto loc_8274B894;
loc_8274B890:
	// li r31,997
	r31.s64 = 997;
loc_8274B894:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274B89C;
	__imp__ObDereferenceObject(ctx, base);
loc_8274B89C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274B8A8"))) PPC_WEAK_FUNC(sub_8274B8A8);
PPC_FUNC_IMPL(__imp__sub_8274B8A8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8274B8B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274B8C8;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274b940
	if (!cr0.eq) goto loc_8274B940;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	r11.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// li r7,20
	ctx.r7.s64 = 20;
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// ori r4,r4,19
	ctx.r4.u64 = ctx.r4.u64 | 19;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274B908;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274b918
	if (!cr0.lt) goto loc_8274B918;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274b938
	goto loc_8274B938;
loc_8274B918:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274b934
	if (!cr6.eq) goto loc_8274B934;
	// bl 0x82135d90
	ctx.lr = 0x8274B924;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274b938
	goto loc_8274B938;
loc_8274B934:
	// li r31,997
	r31.s64 = 997;
loc_8274B938:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274B940;
	__imp__ObDereferenceObject(ctx, base);
loc_8274B940:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274B94C"))) PPC_WEAK_FUNC(sub_8274B94C);
PPC_FUNC_IMPL(__imp__sub_8274B94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274B950"))) PPC_WEAK_FUNC(sub_8274B950);
PPC_FUNC_IMPL(__imp__sub_8274B950) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8274B958;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274B970;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274b9e8
	if (!cr0.eq) goto loc_8274B9E8;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	r11.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// li r7,20
	ctx.r7.s64 = 20;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// ori r4,r4,19
	ctx.r4.u64 = ctx.r4.u64 | 19;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274B9B0;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274b9c0
	if (!cr0.lt) goto loc_8274B9C0;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274b9e0
	goto loc_8274B9E0;
loc_8274B9C0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274b9dc
	if (!cr6.eq) goto loc_8274B9DC;
	// bl 0x82135d90
	ctx.lr = 0x8274B9CC;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274b9e0
	goto loc_8274B9E0;
loc_8274B9DC:
	// li r31,997
	r31.s64 = 997;
loc_8274B9E0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274B9E8;
	__imp__ObDereferenceObject(ctx, base);
loc_8274B9E8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274B9F4"))) PPC_WEAK_FUNC(sub_8274B9F4);
PPC_FUNC_IMPL(__imp__sub_8274B9F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274B9F8"))) PPC_WEAK_FUNC(sub_8274B9F8);
PPC_FUNC_IMPL(__imp__sub_8274B9F8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8274BA00;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274bab8
	if (cr6.eq) goto loc_8274BAB8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,3592
	cr6.compare<uint32_t>(r11.u32, 3592, xer);
	// blt cr6,0x8274bab8
	if (cr6.lt) goto loc_8274BAB8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BA34;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x8274bac4
	if (!cr0.eq) goto loc_8274BAC4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,300
	ctx.r10.s64 = 300;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// std r26,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r26.u64);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// ori r4,r4,26
	ctx.r4.u64 = ctx.r4.u64 | 26;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274BA7C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274ba8c
	if (!cr0.lt) goto loc_8274BA8C;
	// li r29,1627
	r29.s64 = 1627;
	// b 0x8274baac
	goto loc_8274BAAC;
loc_8274BA8C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8274baa8
	if (!cr6.eq) goto loc_8274BAA8;
	// bl 0x82135d90
	ctx.lr = 0x8274BA98;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r29,r11,1627
	r29.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// b 0x8274baac
	goto loc_8274BAAC;
loc_8274BAA8:
	// li r29,997
	r29.s64 = 997;
loc_8274BAAC:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BAB4;
	__imp__ObDereferenceObject(ctx, base);
	// b 0x8274bac4
	goto loc_8274BAC4;
loc_8274BAB8:
	// li r11,3592
	r11.s64 = 3592;
	// li r29,122
	r29.s64 = 122;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_8274BAC4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274BAD0"))) PPC_WEAK_FUNC(sub_8274BAD0);
PPC_FUNC_IMPL(__imp__sub_8274BAD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274BAD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BAEC;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274bb5c
	if (!cr0.eq) goto loc_8274BB5C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// ori r4,r4,20
	ctx.r4.u64 = ctx.r4.u64 | 20;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274BB24;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274bb34
	if (!cr0.lt) goto loc_8274BB34;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274bb54
	goto loc_8274BB54;
loc_8274BB34:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274bb50
	if (!cr6.eq) goto loc_8274BB50;
	// bl 0x82135d90
	ctx.lr = 0x8274BB40;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274bb54
	goto loc_8274BB54;
loc_8274BB50:
	// li r31,997
	r31.s64 = 997;
loc_8274BB54:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BB5C;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BB5C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274BB68"))) PPC_WEAK_FUNC(sub_8274BB68);
PPC_FUNC_IMPL(__imp__sub_8274BB68) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BB88;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274bbf8
	if (!cr0.eq) goto loc_8274BBF8;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	r11.s64 = 0;
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// ori r4,r4,21
	ctx.r4.u64 = ctx.r4.u64 | 21;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274BBC0;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274bbd0
	if (!cr0.lt) goto loc_8274BBD0;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274bbf0
	goto loc_8274BBF0;
loc_8274BBD0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274bbec
	if (!cr6.eq) goto loc_8274BBEC;
	// bl 0x82135d90
	ctx.lr = 0x8274BBDC;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274bbf0
	goto loc_8274BBF0;
loc_8274BBEC:
	// li r31,997
	r31.s64 = 997;
loc_8274BBF0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BBF8;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BBF8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8274BC14"))) PPC_WEAK_FUNC(sub_8274BC14);
PPC_FUNC_IMPL(__imp__sub_8274BC14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274BC18"))) PPC_WEAK_FUNC(sub_8274BC18);
PPC_FUNC_IMPL(__imp__sub_8274BC18) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8274BC20;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,260(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// mulli r11,r5,1326
	r11.s64 = ctx.r5.s64 * 1326;
	// addi r27,r11,8
	r27.s64 = r11.s64 + 8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x8274bcec
	if (cr6.lt) goto loc_8274BCEC;
	// lwz r11,268(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274bcec
	if (cr6.eq) goto loc_8274BCEC;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// li r7,36
	ctx.r7.s64 = 36;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// ori r4,r4,28
	ctx.r4.u64 = ctx.r4.u64 | 28;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// sth r29,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r29.u16);
	// sth r8,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, ctx.r8.u16);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lwz r28,276(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274BCA8;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274bcc8
	if (!cr0.lt) goto loc_8274BCC8;
	// lis r11,-32747
	r11.s64 = -2146107392;
	// ori r11,r11,20999
	r11.u64 = r11.u64 | 20999;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// beq cr6,0x8274bcec
	if (cr6.eq) goto loc_8274BCEC;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// b 0x8274bcf4
	goto loc_8274BCF4;
loc_8274BCC8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8274bce4
	if (!cr6.eq) goto loc_8274BCE4;
	// bl 0x82135d90
	ctx.lr = 0x8274BCD4;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r3,r11,1627
	ctx.r3.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// b 0x8274bcf4
	goto loc_8274BCF4;
loc_8274BCE4:
	// li r3,997
	ctx.r3.s64 = 997;
	// b 0x8274bcf4
	goto loc_8274BCF4;
loc_8274BCEC:
	// li r3,122
	ctx.r3.s64 = 122;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
loc_8274BCF4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274BCFC"))) PPC_WEAK_FUNC(sub_8274BCFC);
PPC_FUNC_IMPL(__imp__sub_8274BCFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274BD00"))) PPC_WEAK_FUNC(sub_8274BD00);
PPC_FUNC_IMPL(__imp__sub_8274BD00) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BD20;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274bd84
	if (!cr0.eq) goto loc_8274BD84;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// li r7,24
	ctx.r7.s64 = 24;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// ori r4,r4,38
	ctx.r4.u64 = ctx.r4.u64 | 38;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274BD4C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274bd5c
	if (!cr0.lt) goto loc_8274BD5C;
	// li r31,1627
	r31.s64 = 1627;
	// b 0x8274bd7c
	goto loc_8274BD7C;
loc_8274BD5C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274bd78
	if (!cr6.eq) goto loc_8274BD78;
	// bl 0x82135d90
	ctx.lr = 0x8274BD68;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r31,r11,1627
	r31.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// b 0x8274bd7c
	goto loc_8274BD7C;
loc_8274BD78:
	// li r31,997
	r31.s64 = 997;
loc_8274BD7C:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BD84;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BD84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8274BDA0"))) PPC_WEAK_FUNC(sub_8274BDA0);
PPC_FUNC_IMPL(__imp__sub_8274BDA0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8274BDA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// rldicl r11,r31,16,48
	r11.u64 = __builtin_rotateleft64(r31.u64, 16) & 0xFFFF;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// clrlwi r10,r11,28
	ctx.r10.u64 = r11.u32 & 0xF;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,9
	cr6.compare<uint32_t>(ctx.r10.u32, 9, xer);
	// bne cr6,0x8274bdd8
	if (!cr6.eq) goto loc_8274BDD8;
	// rlwinm. r11,r11,0,24,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC0;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274be50
	if (!cr0.eq) goto loc_8274BE50;
loc_8274BDD8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BDE0;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8274be50
	if (!cr0.eq) goto loc_8274BE50;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// std r31,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r31.u64);
	// li r7,24
	ctx.r7.s64 = 24;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r27.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ori r4,r4,37
	ctx.r4.u64 = ctx.r4.u64 | 37;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x827bd0b4
	ctx.lr = 0x8274BE18;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274be28
	if (!cr0.lt) goto loc_8274BE28;
	// li r30,1627
	r30.s64 = 1627;
	// b 0x8274be48
	goto loc_8274BE48;
loc_8274BE28:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8274be44
	if (!cr6.eq) goto loc_8274BE44;
	// bl 0x82135d90
	ctx.lr = 0x8274BE34;
	sub_82135D90(ctx, base);
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// andi. r30,r11,1627
	r30.u64 = r11.u64 & 1627;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// b 0x8274be48
	goto loc_8274BE48;
loc_8274BE44:
	// li r30,997
	r30.s64 = 997;
loc_8274BE48:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8274BE50;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BE50:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274BE5C"))) PPC_WEAK_FUNC(sub_8274BE5C);
PPC_FUNC_IMPL(__imp__sub_8274BE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274BE60"))) PPC_WEAK_FUNC(sub_8274BE60);
PPC_FUNC_IMPL(__imp__sub_8274BE60) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8274be90
	if (!cr6.gt) goto loc_8274BE90;
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r3,r11,32775
	ctx.r3.u64 = r11.u64 | 2147942400;
loc_8274BE90:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// bl 0x82135d40
	ctx.lr = 0x8274BE98;
	sub_82135D40(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274bea8
	if (cr6.eq) goto loc_8274BEA8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
loc_8274BEA8:
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

__attribute__((alias("__imp__sub_8274BEC0"))) PPC_WEAK_FUNC(sub_8274BEC0);
PPC_FUNC_IMPL(__imp__sub_8274BEC0) {
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
	ctx.lr = 0x8274BEC8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x827bd0c4
	ctx.lr = 0x8274BEE8;
	__imp__XamGetSystemVersion(ctx, base);
	// lis r11,8204
	r11.s64 = 537657344;
	// ori r11,r11,59648
	r11.u64 = r11.u64 | 59648;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x8274bf1c
	if (!cr6.lt) goto loc_8274BF1C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// li r29,1627
	r29.s64 = 1627;
	// ori r3,r3,1627
	ctx.r3.u64 = ctx.r3.u64 | 1627;
	// bl 0x82135d40
	ctx.lr = 0x8274BF08;
	sub_82135D40(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274bfd4
	if (cr6.eq) goto loc_8274BFD4;
	// lis r11,-32761
	r11.s64 = -2147024896;
	// ori r11,r11,1627
	r11.u64 = r11.u64 | 1627;
	// b 0x8274bf50
	goto loc_8274BF50;
loc_8274BF1C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x8274bf58
	if (!cr6.lt) goto loc_8274BF58;
	// li r11,128
	r11.s64 = 128;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// li r29,122
	r29.s64 = 122;
	// ori r3,r3,122
	ctx.r3.u64 = ctx.r3.u64 | 122;
	// bl 0x82135d40
	ctx.lr = 0x8274BF40;
	sub_82135D40(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274bfd4
	if (cr6.eq) goto loc_8274BFD4;
	// lis r11,-32761
	r11.s64 = -2147024896;
	// ori r11,r11,122
	r11.u64 = r11.u64 | 122;
loc_8274BF50:
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// b 0x8274bfd4
	goto loc_8274BFD4;
loc_8274BF58:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274BF64;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x8274bfd4
	if (!cr0.eq) goto loc_8274BFD4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// li r7,24
	ctx.r7.s64 = 24;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// ori r4,r4,29
	ctx.r4.u64 = ctx.r4.u64 | 29;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274BFA4;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274bfc8
	if (cr0.lt) goto loc_8274BFC8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8274bfd0
	if (!cr6.eq) goto loc_8274BFD0;
	// bl 0x82135d90
	ctx.lr = 0x8274BFB8;
	sub_82135D90(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274bfc8
	if (cr0.lt) goto loc_8274BFC8;
	// mr r29,r30
	r29.u64 = r30.u64;
	// b 0x8274bfd4
	goto loc_8274BFD4;
loc_8274BFC8:
	// li r29,1627
	r29.s64 = 1627;
	// b 0x8274bfd4
	goto loc_8274BFD4;
loc_8274BFD0:
	// li r29,997
	r29.s64 = 997;
loc_8274BFD4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274bfe4
	if (cr6.eq) goto loc_8274BFE4;
	// bl 0x827bce64
	ctx.lr = 0x8274BFE4;
	__imp__ObDereferenceObject(ctx, base);
loc_8274BFE4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274BFF0"))) PPC_WEAK_FUNC(sub_8274BFF0);
PPC_FUNC_IMPL(__imp__sub_8274BFF0) {
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
	ctx.lr = 0x8274BFF8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x827bd0c4
	ctx.lr = 0x8274C01C;
	__imp__XamGetSystemVersion(ctx, base);
	// lis r11,8204
	r11.s64 = 537657344;
	// ori r11,r11,59648
	r11.u64 = r11.u64 | 59648;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x8274c044
	if (!cr6.lt) goto loc_8274C044;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// bl 0x8274be60
	ctx.lr = 0x8274C040;
	sub_8274BE60(ctx, base);
	// b 0x8274c0cc
	goto loc_8274C0CC;
loc_8274C044:
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bdbe4
	ctx.lr = 0x8274C050;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274c0cc
	if (!cr0.eq) goto loc_8274C0CC;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// li r7,24
	ctx.r7.s64 = 24;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// ori r4,r4,30
	ctx.r4.u64 = ctx.r4.u64 | 30;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r3,251
	ctx.r3.s64 = 251;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// bl 0x827bd0b4
	ctx.lr = 0x8274C094;
	__imp__XMsgStartIORequest(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274c0a8
	if (!cr0.lt) goto loc_8274C0A8;
loc_8274C0A0:
	// li r11,1627
	r11.s64 = 1627;
	// b 0x8274c0c8
	goto loc_8274C0C8;
loc_8274C0A8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274c0c4
	if (!cr6.eq) goto loc_8274C0C4;
	// bl 0x82135d90
	ctx.lr = 0x8274C0B4;
	sub_82135D90(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274c0a0
	if (cr0.lt) goto loc_8274C0A0;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// b 0x8274c0cc
	goto loc_8274C0CC;
loc_8274C0C4:
	// li r11,997
	r11.s64 = 997;
loc_8274C0C8:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_8274C0CC:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c0dc
	if (cr6.eq) goto loc_8274C0DC;
	// bl 0x827bce64
	ctx.lr = 0x8274C0DC;
	__imp__ObDereferenceObject(ctx, base);
loc_8274C0DC:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274C0E8"))) PPC_WEAK_FUNC(sub_8274C0E8);
PPC_FUNC_IMPL(__imp__sub_8274C0E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
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
	// li r11,0
	r11.s64 = 0;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,5
	ctx.r4.s64 = 327680;
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// ori r4,r4,32821
	ctx.r4.u64 = ctx.r4.u64 | 32821;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// li r3,252
	ctx.r3.s64 = 252;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// bl 0x827bd0d4
	ctx.lr = 0x8274C130;
	__imp__XMsgInProcessCall(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274c140
	if (cr0.lt) goto loc_8274C140;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8274c170
	goto loc_8274C170;
loc_8274C140:
	// lis r11,-32761
	r11.s64 = -2147024896;
	// ori r11,r11,87
	r11.u64 = r11.u64 | 87;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bne cr6,0x8274c158
	if (!cr6.eq) goto loc_8274C158;
	// li r3,87
	ctx.r3.s64 = 87;
	// b 0x8274c170
	goto loc_8274C170;
loc_8274C158:
	// lis r11,-32761
	r11.s64 = -2147024896;
	// ori r11,r11,122
	r11.u64 = r11.u64 | 122;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r3,122
	ctx.r3.s64 = 122;
	// beq cr6,0x8274c170
	if (cr6.eq) goto loc_8274C170;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8274C170:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274C180"))) PPC_WEAK_FUNC(sub_8274C180);
PPC_FUNC_IMPL(__imp__sub_8274C180) {
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
	ctx.lr = 0x8274C188;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8274c1e0
	if (cr6.eq) goto loc_8274C1E0;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8274C1B4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8274c1b4
	if (!cr6.eq) goto loc_8274C1B4;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r30,r11,0
	r30.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r30,199
	cr6.compare<uint32_t>(r30.u32, 199, xer);
	// ble cr6,0x8274c1e4
	if (!cr6.gt) goto loc_8274C1E4;
loc_8274C1D8:
	// li r31,87
	r31.s64 = 87;
	// b 0x8274c2d4
	goto loc_8274C2D4;
loc_8274C1E0:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8274C1E4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c1d8
	if (cr6.eq) goto loc_8274C1D8;
	// cmplwi cr6,r27,1000
	cr6.compare<uint32_t>(r27.u32, 1000, xer);
	// bgt cr6,0x8274c1d8
	if (cr6.gt) goto loc_8274C1D8;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8274c1d8
	if (cr6.eq) goto loc_8274C1D8;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// li r7,212
	ctx.r7.s64 = 212;
	// ori r6,r6,32826
	ctx.r6.u64 = ctx.r6.u64 | 32826;
	// ori r5,r5,32825
	ctx.r5.u64 = ctx.r5.u64 | 32825;
	// li r4,252
	ctx.r4.s64 = 252;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x827bd094
	ctx.lr = 0x8274C228;
	__imp__XamCreateEnumeratorHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274c2b4
	if (!cr0.eq) goto loc_8274C2B4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bd0e4
	ctx.lr = 0x8274C23C;
	__imp__XamGetPrivateEnumStructureFromHandle(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274c2b4
	if (!cr0.eq) goto loc_8274C2B4;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8274c254
	if (cr6.eq) goto loc_8274C254;
	// mulli r11,r27,208
	r11.s64 = r27.s64 * 208;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8274C254:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r31,r11,24
	r31.s64 = r11.s64 + 24;
	// beq cr6,0x8274c274
	if (cr6.eq) goto loc_8274C274;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x8274C274;
	sub_823DA950(ctx, base);
loc_8274C274:
	// mulli r11,r27,215
	r11.s64 = r27.s64 * 215;
	// stbx r28,r30,r31
	PPC_STORE_U8(r30.u32 + r31.u32, r28.u8);
	// stw r28,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r28.u32);
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// addi r5,r31,208
	ctx.r5.s64 = r31.s64 + 208;
	// stw r4,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r4.u32);
	// lis r3,6144
	ctx.r3.s64 = 402653184;
	// bl 0x827bd354
	ctx.lr = 0x8274C294;
	__imp__XamAlloc(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274c2a4
	if (!cr0.lt) goto loc_8274C2A4;
	// li r31,8
	r31.s64 = 8;
	// b 0x8274c2b4
	goto loc_8274C2B4;
loc_8274C2A4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r31,r28
	r31.u64 = r28.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
loc_8274C2B4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c2c4
	if (cr6.eq) goto loc_8274C2C4;
	// bl 0x8244eee0
	ctx.lr = 0x8274C2C4;
	sub_8244EEE0(ctx, base);
loc_8274C2C4:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c2d4
	if (cr6.eq) goto loc_8274C2D4;
	// bl 0x827bce64
	ctx.lr = 0x8274C2D4;
	__imp__ObDereferenceObject(ctx, base);
loc_8274C2D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8274C2E0"))) PPC_WEAK_FUNC(sub_8274C2E0);
PPC_FUNC_IMPL(__imp__sub_8274C2E0) {
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
	ctx.lr = 0x8274C2E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c31c
	if (cr6.eq) goto loc_8274C31C;
	// lbz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x8274c31c
	if (cr0.eq) goto loc_8274C31C;
	// li r11,0
	r11.s64 = 0;
loc_8274C30C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8274c30c
	if (cr6.lt) goto loc_8274C30C;
loc_8274C31C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r28,r11,-5036
	r28.s64 = r11.s64 + -5036;
	// lbz r4,-5036(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + -5036);
	// cmplwi r4,0
	cr0.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq 0x8274c3ac
	if (cr0.eq) goto loc_8274C3AC;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
loc_8274C338:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c38c
	if (cr6.eq) goto loc_8274C38C;
	// lbz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi r7,0
	cr0.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq 0x8274c38c
	if (cr0.eq) goto loc_8274C38C;
	// mulli r11,r8,12
	r11.s64 = ctx.r8.s64 * 12;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lbzx r9,r11,r5
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + ctx.r5.u32);
	// li r11,0
	r11.s64 = 0;
loc_8274C360:
	// mulli r3,r11,12
	ctx.r3.s64 = r11.s64 * 12;
	// lbzx r3,r3,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274c374
	if (!cr6.eq) goto loc_8274C374;
	// li r6,1
	ctx.r6.s64 = 1;
loc_8274C374:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x8274c360
	if (cr6.lt) goto loc_8274C360;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x8274c398
	if (!cr6.eq) goto loc_8274C398;
loc_8274C38C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
loc_8274C398:
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// blt cr6,0x8274c338
	if (cr6.lt) goto loc_8274C338;
loc_8274C3AC:
	// lis r11,24714
	r11.s64 = 1619656704;
	// li r3,8
	ctx.r3.s64 = 8;
	// ori r31,r11,8194
	r31.u64 = r11.u64 | 8194;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130b50
	ctx.lr = 0x8274C3C0;
	sub_82130B50(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x8274c504
	if (cr0.eq) goto loc_8274C504;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c3d8
	if (cr6.eq) goto loc_8274C3D8;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
loc_8274C3D8:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
	// mulli r3,r11,12
	ctx.r3.s64 = r11.s64 * 12;
	// bl 0x82130b50
	ctx.lr = 0x8274C3F8;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// beq 0x8274c4d8
	if (cr0.eq) goto loc_8274C4D8;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c430
	if (cr6.eq) goto loc_8274C430;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// lwz r4,4(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274c430
	if (cr6.eq) goto loc_8274C430;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mulli r5,r11,12
	ctx.r5.s64 = r11.s64 * 12;
	// bl 0x823da950
	ctx.lr = 0x8274C430;
	sub_823DA950(ctx, base);
loc_8274C430:
	// lbz r26,0(r28)
	r26.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi r26,0
	cr0.compare<uint32_t>(r26.u32, 0, xer);
	// beq 0x8274c504
	if (cr0.eq) goto loc_8274C504;
	// lwz r28,4(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r30,0
	r30.s64 = 0;
loc_8274C444:
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274c498
	if (cr6.eq) goto loc_8274C498;
	// lbz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi r8,0
	cr0.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq 0x8274c498
	if (cr0.eq) goto loc_8274C498;
	// mulli r11,r30,12
	r11.s64 = r30.s64 * 12;
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lbzx r9,r11,r28
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// li r11,0
	r11.s64 = 0;
loc_8274C46C:
	// mulli r6,r11,12
	ctx.r6.s64 = r11.s64 * 12;
	// lbzx r6,r6,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// cmplw cr6,r6,r9
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274c480
	if (!cr6.eq) goto loc_8274C480;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8274C480:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x8274c46c
	if (cr6.lt) goto loc_8274C46C;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x8274c4c0
	if (!cr6.eq) goto loc_8274C4C0;
loc_8274C498:
	// clrlwi r31,r31,24
	r31.u64 = r31.u32 & 0xFF;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mulli r11,r30,12
	r11.s64 = r30.s64 * 12;
	// mulli r10,r31,12
	ctx.r10.s64 = r31.s64 * 12;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r4,r11,r28
	ctx.r4.u64 = r11.u64 + r28.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x823da950
	ctx.lr = 0x8274C4B8;
	sub_823DA950(ctx, base);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
loc_8274C4C0:
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// blt cr6,0x8274c444
	if (cr6.lt) goto loc_8274C444;
	// b 0x8274c504
	goto loc_8274C504;
loc_8274C4D8:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c4f4
	if (cr6.eq) goto loc_8274C4F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x8274C4EC;
	sub_821310F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_8274C4F4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821310f8
	ctx.lr = 0x8274C500;
	sub_821310F8(ctx, base);
	// li r29,0
	r29.s64 = 0;
loc_8274C504:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274C510"))) PPC_WEAK_FUNC(sub_8274C510);
PPC_FUNC_IMPL(__imp__sub_8274C510) {
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
	ctx.lr = 0x8274C518;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r9,8(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x8274c2e0
	ctx.lr = 0x8274C548;
	sub_8274C2E0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274c560
	if (!cr0.eq) goto loc_8274C560;
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x8274c60c
	goto loc_8274C60C;
loc_8274C560:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bge cr6,0x8274c574
	if (!cr6.lt) goto loc_8274C574;
	// li r11,4
	r11.s64 = 4;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
loc_8274C574:
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8274c588
	if (!cr6.lt) goto loc_8274C588;
	// li r11,3
	r11.s64 = 3;
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
loc_8274C588:
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// b 0x8274c5a0
	goto loc_8274C5A0;
loc_8274C590:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274c5a8
	if (!cr6.eq) goto loc_8274C5A8;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
loc_8274C5A0:
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// blt cr6,0x8274c590
	if (cr6.lt) goto loc_8274C590;
loc_8274C5A8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274C5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8274c60c
	if (!cr0.lt) goto loc_8274C60C;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c60c
	if (cr6.eq) goto loc_8274C60C;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r31,r3,4
	r31.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274c600
	if (cr6.eq) goto loc_8274C600;
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x8274C5F4;
	sub_821310F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8274C600:
	// lis r4,24714
	ctx.r4.s64 = 1619656704;
	// ori r4,r4,8194
	ctx.r4.u64 = ctx.r4.u64 | 8194;
	// bl 0x821310f8
	ctx.lr = 0x8274C60C;
	sub_821310F8(ctx, base);
loc_8274C60C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274C618"))) PPC_WEAK_FUNC(sub_8274C618);
PPC_FUNC_IMPL(__imp__sub_8274C618) {
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
	ctx.lr = 0x8274C620;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x8244d150
	ctx.lr = 0x8274C644;
	sub_8244D150(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8274ebc0
	ctx.lr = 0x8274C65C;
	sub_8274EBC0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8274c688
	if (!cr0.lt) goto loc_8274C688;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274c688
	if (cr6.eq) goto loc_8274C688;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274C680;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8274C688:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274C694"))) PPC_WEAK_FUNC(sub_8274C694);
PPC_FUNC_IMPL(__imp__sub_8274C694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274C698"))) PPC_WEAK_FUNC(sub_8274C698);
PPC_FUNC_IMPL(__imp__sub_8274C698) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8274c618
	sub_8274C618(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8274C6A4"))) PPC_WEAK_FUNC(sub_8274C6A4);
PPC_FUNC_IMPL(__imp__sub_8274C6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274C6A8"))) PPC_WEAK_FUNC(sub_8274C6A8);
PPC_FUNC_IMPL(__imp__sub_8274C6A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,10
	r11.s64 = 10;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274c6c8
	if (!cr6.eq) goto loc_8274C6C8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,-4928
	r11.s64 = r11.s64 + -4928;
	// b 0x8274c6d0
	goto loc_8274C6D0;
loc_8274C6C8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,-4960
	r11.s64 = r11.s64 + -4960;
loc_8274C6D0:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274C6D8"))) PPC_WEAK_FUNC(sub_8274C6D8);
PPC_FUNC_IMPL(__imp__sub_8274C6D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274C6EC"))) PPC_WEAK_FUNC(sub_8274C6EC);
PPC_FUNC_IMPL(__imp__sub_8274C6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274C6F0"))) PPC_WEAK_FUNC(sub_8274C6F0);
PPC_FUNC_IMPL(__imp__sub_8274C6F0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8244d150
	ctx.lr = 0x8274C720;
	sub_8244D150(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x8274f578
	ctx.lr = 0x8274C730;
	sub_8274F578(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8274c750
	if (!cr0.lt) goto loc_8274C750;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_8274C750:
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// addi r11,r30,44
	r11.s64 = r30.s64 + 44;
	// lwz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274c76c
	if (cr6.eq) goto loc_8274C76C;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// b 0x8274c770
	goto loc_8274C770;
loc_8274C76C:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_8274C770:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
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

__attribute__((alias("__imp__sub_8274C78C"))) PPC_WEAK_FUNC(sub_8274C78C);
PPC_FUNC_IMPL(__imp__sub_8274C78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274C790"))) PPC_WEAK_FUNC(sub_8274C790);
PPC_FUNC_IMPL(__imp__sub_8274C790) {
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
	ctx.lr = 0x8274C798;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
loc_8274C7AC:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274c7fc
	if (cr6.eq) goto loc_8274C7FC;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8274c7fc
	if (cr6.eq) goto loc_8274C7FC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274c7ec
	if (cr6.eq) goto loc_8274C7EC;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274c7e0
	if (!cr6.eq) goto loc_8274C7E0;
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
loc_8274C7E0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
loc_8274C7EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274c6f0
	ctx.lr = 0x8274C7F4;
	sub_8274C6F0(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x8274c7ac
	goto loc_8274C7AC;
loc_8274C7FC:
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r29,r31,44
	r29.s64 = r31.s64 + 44;
loc_8274C804:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274c940
	if (cr6.eq) goto loc_8274C940;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8274c940
	if (cr6.eq) goto loc_8274C940;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274c848
	if (cr6.eq) goto loc_8274C848;
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bne cr6,0x8274c83c
	if (!cr6.eq) goto loc_8274C83C;
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
loc_8274C83C:
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stw r28,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r28.u32);
loc_8274C848:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8274c930
	if (!cr6.eq) goto loc_8274C930;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lbz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r10,140(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 140);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8274c874
	if (cr6.eq) goto loc_8274C874;
	// stb r10,60(r31)
	PPC_STORE_U8(r31.u32 + 60, ctx.r10.u8);
loc_8274C874:
	// lhz r10,62(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// cmplwi cr6,r10,4096
	cr6.compare<uint32_t>(ctx.r10.u32, 4096, xer);
	// ble cr6,0x8274c884
	if (!cr6.gt) goto loc_8274C884;
	// sth r28,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r28.u16);
loc_8274C884:
	// lhz r10,-2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lbz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// li r7,259
	ctx.r7.s64 = 259;
	// rlwimi r10,r8,12,0,19
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 12) & 0xFFFFF000) | (ctx.r10.u64 & 0xFFFFFFFF00000FFF);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// lhz r10,62(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// rlwimi r8,r10,1,20,30
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 1) & 0xFFE) | (ctx.r8.u64 & 0xFFFFFFFFFFFFF001);
	// sth r8,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r8.u16);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r10,62(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 62);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,62(r31)
	PPC_STORE_U16(r31.u32 + 62, ctx.r10.u16);
	// lhz r10,-2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + -2);
	// lwz r8,196(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// rlwinm r8,r8,0,12,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xF0000;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwimi r10,r9,27,31,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 27) & 0x1) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFE);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// stw r28,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r28.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274c904
	if (cr6.eq) goto loc_8274C904;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// b 0x8274c908
	goto loc_8274C908;
loc_8274C904:
	// stw r4,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r4.u32);
loc_8274C908:
	// stw r4,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r4.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r8,1268(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 1268);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// stw r10,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r10.u32);
	// b 0x8274c938
	goto loc_8274C938;
loc_8274C930:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274c6f0
	ctx.lr = 0x8274C938;
	sub_8274C6F0(ctx, base);
loc_8274C938:
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x8274c804
	goto loc_8274C804;
loc_8274C940:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274C94C"))) PPC_WEAK_FUNC(sub_8274C94C);
PPC_FUNC_IMPL(__imp__sub_8274C94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274C950"))) PPC_WEAK_FUNC(sub_8274C950);
PPC_FUNC_IMPL(__imp__sub_8274C950) {
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
	ctx.lr = 0x8274C958;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// mr r23,r25
	r23.u64 = r25.u64;
	// mr r26,r25
	r26.u64 = r25.u64;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// lwz r24,64(r29)
	r24.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// bl 0x82750430
	ctx.lr = 0x8274C978;
	sub_82750430(ctx, base);
	// addi r28,r29,44
	r28.s64 = r29.s64 + 44;
	// lwz r31,44(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8274c990
	if (!cr6.eq) goto loc_8274C990;
	// mr r30,r25
	r30.u64 = r25.u64;
	// b 0x8274c9a8
	goto loc_8274C9A8;
loc_8274C990:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274c9a8
	if (cr6.eq) goto loc_8274C9A8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// bne cr6,0x8274c9c4
	if (!cr6.eq) goto loc_8274C9C4;
loc_8274C9A8:
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274c9c4
	if (!cr6.eq) goto loc_8274C9C4;
	// li r11,1
	r11.s64 = 1;
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// stw r11,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r11.u32);
	// bl 0x823ea478
	ctx.lr = 0x8274C9C4;
	sub_823EA478(ctx, base);
loc_8274C9C4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274caa8
	if (cr6.eq) goto loc_8274CAA8;
loc_8274C9CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8274caa8
	if (cr6.eq) goto loc_8274CAA8;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// bge cr6,0x8274caa8
	if (!cr6.lt) goto loc_8274CAA8;
	// addi r27,r29,52
	r27.s64 = r29.s64 + 52;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8274f988
	ctx.lr = 0x8274C9F0;
	sub_8274F988(ctx, base);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bge cr6,0x8274caa8
	if (!cr6.lt) goto loc_8274CAA8;
	// li r11,259
	r11.s64 = 259;
	// li r5,88
	ctx.r5.s64 = 88;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274CA14;
	sub_8244D150(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r31.u32);
	// bl 0x823ea320
	ctx.lr = 0x8274CA38;
	sub_823EA320(ctx, base);
	// mr. r23,r3
	r23.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// blt 0x8274caa0
	if (cr0.lt) goto loc_8274CAA0;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ca68
	if (cr6.eq) goto loc_8274CA68;
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274ca5c
	if (!cr6.eq) goto loc_8274CA5C;
	// stw r25,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r25.u32);
loc_8274CA5C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// stw r25,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r25.u32);
loc_8274CA68:
	// stw r25,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r25.u32);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274ca80
	if (cr6.eq) goto loc_8274CA80;
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// b 0x8274ca84
	goto loc_8274CA84;
loc_8274CA80:
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
loc_8274CA84:
	// stw r31,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r31.u32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274caa8
	if (cr6.eq) goto loc_8274CAA8;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x8274c9cc
	goto loc_8274C9CC;
loc_8274CAA0:
	// mr r23,r25
	r23.u64 = r25.u64;
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
loc_8274CAA8:
	// lwz r11,64(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274cadc
	if (!cr6.eq) goto loc_8274CADC;
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// bne cr6,0x8274cadc
	if (!cr6.eq) goto loc_8274CADC;
	// addi r3,r29,52
	ctx.r3.s64 = r29.s64 + 52;
	// bl 0x8274f988
	ctx.lr = 0x8274CAC4;
	sub_8274F988(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// blt cr6,0x8274cadc
	if (cr6.lt) goto loc_8274CADC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// bl 0x823ea3d8
	ctx.lr = 0x8274CAD8;
	sub_823EA3D8(ctx, base);
	// stw r25,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r25.u32);
loc_8274CADC:
	// lwz r4,52(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// addi r31,r29,52
	r31.s64 = r29.s64 + 52;
	// b 0x8274cb2c
	goto loc_8274CB2C;
loc_8274CAE8:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r11,259
	cr6.compare<int32_t>(r11.s32, 259, xer);
	// beq cr6,0x8274cb34
	if (cr6.eq) goto loc_8274CB34;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274cb20
	if (cr6.eq) goto loc_8274CB20;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274cb14
	if (!cr6.eq) goto loc_8274CB14;
	// stw r25,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r25.u32);
loc_8274CB14:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r25,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r25.u32);
loc_8274CB20:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8274c6f0
	ctx.lr = 0x8274CB28;
	sub_8274C6F0(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_8274CB2C:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8274cae8
	if (!cr6.eq) goto loc_8274CAE8;
loc_8274CB34:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8274CB40"))) PPC_WEAK_FUNC(sub_8274CB40);
PPC_FUNC_IMPL(__imp__sub_8274CB40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274cb50
	if (!cr6.eq) goto loc_8274CB50;
	// b 0x8274c950
	sub_8274C950(ctx, base);
	return;
loc_8274CB50:
	// b 0x8274c790
	sub_8274C790(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8274CB54"))) PPC_WEAK_FUNC(sub_8274CB54);
PPC_FUNC_IMPL(__imp__sub_8274CB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274CB58"))) PPC_WEAK_FUNC(sub_8274CB58);
PPC_FUNC_IMPL(__imp__sub_8274CB58) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8274ede8
	ctx.lr = 0x8274CB70;
	sub_8274EDE8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274cbdc
	if (cr0.lt) goto loc_8274CBDC;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274cbb0
	if (!cr6.eq) goto loc_8274CBB0;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// b 0x8274cba8
	goto loc_8274CBA8;
loc_8274CB8C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8274CBA8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274cb8c
	if (!cr6.eq) goto loc_8274CB8C;
loc_8274CBB0:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274cbdc
	if (!cr6.eq) goto loc_8274CBDC;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274cbdc
	if (cr6.eq) goto loc_8274CBDC;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823ea420
	ctx.lr = 0x8274CBDC;
	sub_823EA420(ctx, base);
loc_8274CBDC:
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

__attribute__((alias("__imp__sub_8274CBF0"))) PPC_WEAK_FUNC(sub_8274CBF0);
PPC_FUNC_IMPL(__imp__sub_8274CBF0) {
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
	ctx.lr = 0x8274CBF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r5.u32);
	// lwz r11,24(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,28,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x2;
	// xori r6,r10,2
	ctx.r6.u64 = ctx.r10.u64 ^ 2;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// add r3,r11,r6
	ctx.r3.u64 = r11.u64 + ctx.r6.u64;
	// bl 0x8274fc70
	ctx.lr = 0x8274CC3C;
	sub_8274FC70(ctx, base);
	// mr. r27,r3
	r27.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// blt 0x8274ccb4
	if (cr0.lt) goto loc_8274CCB4;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274cc98
	if (!cr6.gt) goto loc_8274CC98;
	// li r30,0
	r30.s64 = 0;
loc_8274CC58:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mullw r10,r10,r29
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r29.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stwx r11,r30,r9
	PPC_STORE_U32(r30.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// bl 0x8274c6f0
	ctx.lr = 0x8274CC84;
	sub_8274C6F0(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274cc58
	if (cr6.lt) goto loc_8274CC58;
loc_8274CC98:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274ccb4
	if (!cr6.eq) goto loc_8274CCB4;
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82750928
	ctx.lr = 0x8274CCB0;
	sub_82750928(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8274CCB4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274CCC0"))) PPC_WEAK_FUNC(sub_8274CCC0);
PPC_FUNC_IMPL(__imp__sub_8274CCC0) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274cd40
	if (cr6.eq) goto loc_8274CD40;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274cd0c
	if (!cr6.eq) goto loc_8274CD0C;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274cd04
	if (cr6.eq) goto loc_8274CD04;
	// bl 0x823ea140
	ctx.lr = 0x8274CD00;
	sub_823EA140(ctx, base);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
loc_8274CD04:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x827503b8
	ctx.lr = 0x8274CD0C;
	sub_827503B8(ctx, base);
loc_8274CD0C:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274cd28
	if (cr6.eq) goto loc_8274CD28;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821310f8
	ctx.lr = 0x8274CD24;
	sub_821310F8(ctx, base);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
loc_8274CD28:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8274fb28
	ctx.lr = 0x8274CD30;
	sub_8274FB28(ctx, base);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// bl 0x821310f8
	ctx.lr = 0x8274CD40;
	sub_821310F8(ctx, base);
loc_8274CD40:
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

__attribute__((alias("__imp__sub_8274CD58"))) PPC_WEAK_FUNC(sub_8274CD58);
PPC_FUNC_IMPL(__imp__sub_8274CD58) {
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
	ctx.lr = 0x8274CD60;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r26,0
	r26.s64 = 0;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// ori r3,r3,10
	ctx.r3.u64 = ctx.r3.u64 | 10;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8274cd90
	if (cr6.eq) goto loc_8274CD90;
	// stw r26,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r26.u32);
loc_8274CD90:
	// lwz r29,52(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 52);
	// b 0x8274ce38
	goto loc_8274CE38;
loc_8274CD98:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8274ce34
	if (cr6.eq) goto loc_8274CE34;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// subf r8,r30,r8
	ctx.r8.s64 = ctx.r8.s64 - r30.s64;
	// addi r31,r9,2
	r31.s64 = ctx.r9.s64 + 2;
	// cmplw cr6,r31,r8
	cr6.compare<uint32_t>(r31.u32, ctx.r8.u32, xer);
	// bgt cr6,0x8274ce6c
	if (cr6.gt) goto loc_8274CE6C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// add r3,r30,r27
	ctx.r3.u64 = r30.u64 + r27.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r11,-2
	ctx.r4.s64 = r11.s64 + -2;
	// bl 0x823da950
	ctx.lr = 0x8274CDE0;
	sub_823DA950(ctx, base);
	// add r30,r31,r30
	r30.u64 = r31.u64 + r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8274cdfc
	if (cr6.eq) goto loc_8274CDFC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_8274CDFC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r9,r31,-2
	ctx.r9.s64 = r31.s64 + -2;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274ce1c
	if (!cr6.lt) goto loc_8274CE1C;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274CE1C:
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274ce38
	if (!cr6.eq) goto loc_8274CE38;
	// stw r26,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r26.u32);
loc_8274CE34:
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
loc_8274CE38:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8274cd98
	if (!cr6.eq) goto loc_8274CD98;
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,32(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,1268(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 1268);
	// slw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// andc r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ~ctx.r10.u64;
	// stw r10,1268(r11)
	PPC_STORE_U32(r11.u32 + 1268, ctx.r10.u32);
loc_8274CE60:
	// stw r30,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8274CE6C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8274ce60
	if (!cr6.eq) goto loc_8274CE60;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// mr r30,r31
	r30.u64 = r31.u64;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x8274ce60
	goto loc_8274CE60;
}

__attribute__((alias("__imp__sub_8274CE84"))) PPC_WEAK_FUNC(sub_8274CE84);
PPC_FUNC_IMPL(__imp__sub_8274CE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274CE88"))) PPC_WEAK_FUNC(sub_8274CE88);
PPC_FUNC_IMPL(__imp__sub_8274CE88) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8274CE90;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32768
	r11.s64 = -2147483648;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// ori r26,r11,16385
	r26.u64 = r11.u64 | 16385;
	// lwz r10,36(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8274cfc0
	if (cr6.eq) goto loc_8274CFC0;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274CEC0;
	sub_8244D150(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r31,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r31.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r31,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r31.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8244d150
	ctx.lr = 0x8274CEE8;
	sub_8244D150(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r30,1
	r30.s64 = 1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8244d150
	ctx.lr = 0x8274CF08;
	sub_8244D150(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8244d150
	ctx.lr = 0x8274CF24;
	sub_8244D150(ctx, base);
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// addi r11,r1,104
	r11.s64 = ctx.r1.s64 + 104;
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
	// addi r28,r29,60
	r28.s64 = r29.s64 + 60;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274cf54
	if (cr6.eq) goto loc_8274CF54;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8274cfbc
	if (cr6.eq) goto loc_8274CFBC;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x823ea218
	ctx.lr = 0x8274CF50;
	sub_823EA218(ctx, base);
	// b 0x8274cfb8
	goto loc_8274CFB8;
loc_8274CF54:
	// li r5,92
	ctx.r5.s64 = 92;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8244d150
	ctx.lr = 0x8274CF64;
	sub_8244D150(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// li r10,16000
	ctx.r10.s64 = 16000;
	// stw r29,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r29.u32);
	// addi r11,r11,-14632
	r11.s64 = r11.s64 + -14632;
	// stb r30,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r30.u8);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r30.u8);
	// stw r11,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r11.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stb r30,169(r1)
	PPC_STORE_U8(ctx.r1.u32 + 169, r30.u8);
	// stb r30,170(r1)
	PPC_STORE_U8(ctx.r1.u32 + 170, r30.u8);
	// stb r31,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r31.u8);
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r31.u32);
	// stw r9,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
	// stw r31,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r31.u32);
	// stw r31,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r31.u32);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// stb r11,171(r1)
	PPC_STORE_U8(ctx.r1.u32 + 171, r11.u8);
	// bl 0x823eaa90
	ctx.lr = 0x8274CFB8;
	sub_823EAA90(ctx, base);
loc_8274CFB8:
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_8274CFBC:
	// stw r30,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r30.u32);
loc_8274CFC0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274CFCC"))) PPC_WEAK_FUNC(sub_8274CFCC);
PPC_FUNC_IMPL(__imp__sub_8274CFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274CFD0"))) PPC_WEAK_FUNC(sub_8274CFD0);
PPC_FUNC_IMPL(__imp__sub_8274CFD0) {
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
	ctx.lr = 0x8274CFD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,36(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274d004
	if (!cr6.eq) goto loc_8274D004;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// b 0x8274d068
	goto loc_8274D068;
loc_8274D004:
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r31,r11,2
	r31.s64 = r11.s64 + 2;
	// divwu. r27,r10,r31
	r27.u32 = ctx.r10.u32 / r31.u32;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// twllei r31,0
	// beq 0x8274d068
	if (cr0.eq) goto loc_8274D068;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
loc_8274D02C:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,68(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 68);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x827506a8
	ctx.lr = 0x8274D03C;
	sub_827506A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274d068
	if (cr0.lt) goto loc_8274D068;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8274d068
	if (cr6.eq) goto loc_8274D068;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r28,r28,r31
	r28.u64 = r28.u64 + r31.u64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// blt cr6,0x8274d02c
	if (cr6.lt) goto loc_8274D02C;
loc_8274D068:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274D070"))) PPC_WEAK_FUNC(sub_8274D070);
PPC_FUNC_IMPL(__imp__sub_8274D070) {
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
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274d0a8
	if (!cr6.eq) goto loc_8274D0A8;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274d0a8
	if (!cr6.eq) goto loc_8274D0A8;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82750870
	ctx.lr = 0x8274D0A8;
	sub_82750870(ctx, base);
loc_8274D0A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274edc0
	ctx.lr = 0x8274D0B0;
	sub_8274EDC0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8274d0c0
	if (!cr0.lt) goto loc_8274D0C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274cb58
	ctx.lr = 0x8274D0C0;
	sub_8274CB58(ctx, base);
loc_8274D0C0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
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

__attribute__((alias("__imp__sub_8274D0DC"))) PPC_WEAK_FUNC(sub_8274D0DC);
PPC_FUNC_IMPL(__imp__sub_8274D0DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D0E0"))) PPC_WEAK_FUNC(sub_8274D0E0);
PPC_FUNC_IMPL(__imp__sub_8274D0E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8274D0E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,72
	ctx.r3.s64 = 72;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x82130b50
	ctx.lr = 0x8274D110;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8274d190
	if (cr0.eq) goto loc_8274D190;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// addi r11,r11,-5028
	r11.s64 = r11.s64 + -5028;
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// bne cr6,0x8274d168
	if (!cr6.eq) goto loc_8274D168;
	// lwz r4,72(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d170
	if (cr6.eq) goto loc_8274D170;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274D164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8274d170
	goto loc_8274D170;
loc_8274D168:
	// li r11,255
	r11.s64 = 255;
	// stb r11,60(r31)
	PPC_STORE_U8(r31.u32 + 60, r11.u8);
loc_8274D170:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130b50
	ctx.lr = 0x8274D184;
	sub_82130B50(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274d1a4
	if (!cr0.eq) goto loc_8274D1A4;
loc_8274D190:
	// lis r27,-32761
	r27.s64 = -2147024896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r27,r27,14
	r27.u64 = r27.u64 | 14;
	// bl 0x8274ccc0
	ctx.lr = 0x8274D1A0;
	sub_8274CCC0(ctx, base);
	// li r31,0
	r31.s64 = 0;
loc_8274D1A4:
	// stw r31,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r31.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274D1B4"))) PPC_WEAK_FUNC(sub_8274D1B4);
PPC_FUNC_IMPL(__imp__sub_8274D1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D1B8"))) PPC_WEAK_FUNC(sub_8274D1B8);
PPC_FUNC_IMPL(__imp__sub_8274D1B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	// clrlwi. r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne 0x8274d1c8
	if (!cr0.eq) goto loc_8274D1C8;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8274d0e0
	sub_8274D0E0(ctx, base);
	return;
loc_8274D1C8:
	// b 0x8274d0e0
	sub_8274D0E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8274D1CC"))) PPC_WEAK_FUNC(sub_8274D1CC);
PPC_FUNC_IMPL(__imp__sub_8274D1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D1D0"))) PPC_WEAK_FUNC(sub_8274D1D0);
PPC_FUNC_IMPL(__imp__sub_8274D1D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r3,r11,-11848
	ctx.r3.s64 = r11.s64 + -11848;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274D1DC"))) PPC_WEAK_FUNC(sub_8274D1DC);
PPC_FUNC_IMPL(__imp__sub_8274D1DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D1E0"))) PPC_WEAK_FUNC(sub_8274D1E0);
PPC_FUNC_IMPL(__imp__sub_8274D1E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d1f0
	if (cr6.eq) goto loc_8274D1F0;
	// li r11,6172
	r11.s64 = 6172;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
loc_8274D1F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274D1F8"))) PPC_WEAK_FUNC(sub_8274D1F8);
PPC_FUNC_IMPL(__imp__sub_8274D1F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
loc_8274D1FC:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8274d1fc
	if (!cr0.eq) goto loc_8274D1FC;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274D220"))) PPC_WEAK_FUNC(sub_8274D220);
PPC_FUNC_IMPL(__imp__sub_8274D220) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
loc_8274D224:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8274d224
	if (!cr0.eq) goto loc_8274D224;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274D248"))) PPC_WEAK_FUNC(sub_8274D248);
PPC_FUNC_IMPL(__imp__sub_8274D248) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d260
	if (cr6.eq) goto loc_8274D260;
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// sth r10,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r10.u16);
loc_8274D260:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274D268"))) PPC_WEAK_FUNC(sub_8274D268);
PPC_FUNC_IMPL(__imp__sub_8274D268) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32761
	r11.s64 = -2147024896;
	// clrlwi. r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ori r11,r11,87
	r11.u64 = r11.u64 | 87;
	// bne 0x8274d284
	if (!cr0.eq) goto loc_8274D284;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
loc_8274D284:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274D28C"))) PPC_WEAK_FUNC(sub_8274D28C);
PPC_FUNC_IMPL(__imp__sub_8274D28C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D290"))) PPC_WEAK_FUNC(sub_8274D290);
PPC_FUNC_IMPL(__imp__sub_8274D290) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d2a0
	if (cr6.eq) goto loc_8274D2A0;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
loc_8274D2A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274D2A8"))) PPC_WEAK_FUNC(sub_8274D2A8);
PPC_FUNC_IMPL(__imp__sub_8274D2A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8274D2B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r4,6172
	ctx.r4.s64 = 6172;
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8274D2DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274d2fc
	if (!cr0.eq) goto loc_8274D2FC;
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
loc_8274D2EC:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8274D2FC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-4988
	r11.s64 = r11.s64 + -4988;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// b 0x8274d2ec
	goto loc_8274D2EC;
}

__attribute__((alias("__imp__sub_8274D31C"))) PPC_WEAK_FUNC(sub_8274D31C);
PPC_FUNC_IMPL(__imp__sub_8274D31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D320"))) PPC_WEAK_FUNC(sub_8274D320);
PPC_FUNC_IMPL(__imp__sub_8274D320) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8274D328;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274d470
	if (cr6.eq) goto loc_8274D470;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823eaf00
	ctx.lr = 0x8274D358;
	sub_823EAF00(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274d470
	if (cr0.lt) goto loc_8274D470;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r27,r24
	r27.u64 = r24.u64;
	// mr r28,r24
	r28.u64 = r24.u64;
	// addi r31,r30,6156
	r31.s64 = r30.s64 + 6156;
	// addi r26,r30,12
	r26.s64 = r30.s64 + 12;
	// lfs f31,6332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6332);
	f31.f64 = double(temp.f32);
	// subfic r25,r30,-5044
	xer.ca = r30.u32 <= 4294962252;
	r25.s64 = -5044 - r30.s64;
loc_8274D37C:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r10,r25,r31
	ctx.r10.u64 = r25.u64 + r31.u64;
	// lwzx r29,r10,r11
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8274d450
	if (cr6.eq) goto loc_8274D450;
	// lwz r11,196(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 196);
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8274d450
	if (!cr6.eq) goto loc_8274D450;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 184);
	f0.f64 = double(temp.f32);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r9,256
	ctx.r9.s64 = 256;
	// add r10,r27,r10
	ctx.r10.u64 = r27.u64 + ctx.r10.u64;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// rlwinm r10,r10,9,0,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0xFFFFFE00;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_8274D3C4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * f31.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r8,32767
	cr6.compare<int32_t>(ctx.r8.s32, 32767, xer);
	// blt cr6,0x8274d3ec
	if (cr6.lt) goto loc_8274D3EC;
	// li r8,32767
	ctx.r8.s64 = 32767;
	// b 0x8274d3f8
	goto loc_8274D3F8;
loc_8274D3EC:
	// cmpwi cr6,r8,-32768
	cr6.compare<int32_t>(ctx.r8.s32, -32768, xer);
	// bgt cr6,0x8274d3f8
	if (cr6.gt) goto loc_8274D3F8;
	// li r8,-32738
	ctx.r8.s64 = -32738;
loc_8274D3F8:
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8274d3c4
	if (!cr0.eq) goto loc_8274D3C4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8274d454
	if (cr6.lt) goto loc_8274D454;
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,768
	ctx.r6.s64 = 768;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r29,200
	ctx.r3.s64 = r29.s64 + 200;
	// bl 0x82751ca8
	ctx.lr = 0x8274D43C;
	sub_82751CA8(ctx, base);
	// li r5,256
	ctx.r5.s64 = 256;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82750ec0
	ctx.lr = 0x8274D44C;
	sub_82750EC0(ctx, base);
	// b 0x8274d454
	goto loc_8274D454;
loc_8274D450:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_8274D454:
	// addi r28,r28,1024
	r28.s64 = r28.s64 + 1024;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r27,r27,3
	r27.s64 = r27.s64 + 3;
	// addi r26,r26,1536
	r26.s64 = r26.s64 + 1536;
	// cmplwi cr6,r28,4096
	cr6.compare<uint32_t>(r28.u32, 4096, xer);
	// blt cr6,0x8274d37c
	if (cr6.lt) goto loc_8274D37C;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8274D470:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8274D47C"))) PPC_WEAK_FUNC(sub_8274D47C);
PPC_FUNC_IMPL(__imp__sub_8274D47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D480"))) PPC_WEAK_FUNC(sub_8274D480);
PPC_FUNC_IMPL(__imp__sub_8274D480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,1092(r11)
	PPC_STORE_U32(r11.u32 + 1092, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274D490"))) PPC_WEAK_FUNC(sub_8274D490);
PPC_FUNC_IMPL(__imp__sub_8274D490) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8274D498;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x8244d150
	ctx.lr = 0x8274D4C4;
	sub_8244D150(ctx, base);
	// li r11,127
	r11.s64 = 127;
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r28.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r11,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8244d150
	ctx.lr = 0x8274D4E0;
	sub_8244D150(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stb r31,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r31.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244d150
	ctx.lr = 0x8274D4FC;
	sub_8244D150(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,161
	r11.s64 = ctx.r1.s64 + 161;
	// li r27,2
	r27.s64 = 2;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8274D510:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stfs f0,3(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 3, temp.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r27,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r27.u8);
	// stb r9,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r9.u8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8274d510
	if (cr6.lt) goto loc_8274D510;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x8274D540;
	sub_8244D150(ctx, base);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// li r30,4
	r30.s64 = 4;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274D560;
	sub_8244D150(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8244d150
	ctx.lr = 0x8274D57C;
	sub_8244D150(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r29,1
	r29.s64 = 1;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// stb r29,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8244d150
	ctx.lr = 0x8274D59C;
	sub_8244D150(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r11,44(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// ori r25,r10,48000
	r25.u64 = ctx.r10.u64 | 48000;
	// stw r28,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r28.u32);
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stb r31,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r31.u8);
	// stb r30,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, r30.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r25,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r25.u32);
	// stb r29,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r29.u8);
	// stb r30,137(r1)
	PPC_STORE_U8(ctx.r1.u32 + 137, r30.u8);
	// stb r27,138(r1)
	PPC_STORE_U8(ctx.r1.u32 + 138, r27.u8);
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r31.u32);
	// beq cr6,0x8274d620
	if (cr6.eq) goto loc_8274D620;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x8274d618
	if (cr0.eq) goto loc_8274D618;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8274D5F4:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwzx r8,r8,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stwx r8,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x8274d5f4
	if (cr6.lt) goto loc_8274D5F4;
loc_8274D618:
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// b 0x8274d624
	goto loc_8274D624;
loc_8274D620:
	// lbz r11,104(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 104);
loc_8274D624:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rlwinm r11,r11,2,22,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FC;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// stb r10,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r10.u8);
	// addi r27,r28,56
	r27.s64 = r28.s64 + 56;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stwx r8,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r8.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823eaaf0
	ctx.lr = 0x8274D650;
	sub_823EAAF0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8274d740
	if (cr0.lt) goto loc_8274D740;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8244d150
	ctx.lr = 0x8274D668;
	sub_8244D150(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,161
	r11.s64 = ctx.r1.s64 + 161;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_8274D678:
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stfs f0,3(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 3, temp.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r9.u8);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8274d678
	if (cr6.lt) goto loc_8274D678;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x8274D6A8;
	sub_8244D150(ctx, base);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274D6C4;
	sub_8244D150(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8244d150
	ctx.lr = 0x8274D6E4;
	sub_8244D150(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stb r29,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r29.u8);
	// li r5,92
	ctx.r5.s64 = 92;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x8244d150
	ctx.lr = 0x8274D700;
	sub_8244D150(ctx, base);
	// lis r11,-32139
	r11.s64 = -2106261504;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stw r28,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r28.u32);
	// addi r11,r11,-11136
	r11.s64 = r11.s64 + -11136;
	// stb r31,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, r31.u8);
	// stb r30,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, r30.u8);
	// addi r4,r28,64
	ctx.r4.s64 = r28.s64 + 64;
	// stw r25,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r25.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stb r29,249(r1)
	PPC_STORE_U8(ctx.r1.u32 + 249, r29.u8);
	// stb r30,250(r1)
	PPC_STORE_U8(ctx.r1.u32 + 250, r30.u8);
	// stb r29,251(r1)
	PPC_STORE_U8(ctx.r1.u32 + 251, r29.u8);
	// stb r29,256(r1)
	PPC_STORE_U8(ctx.r1.u32 + 256, r29.u8);
	// stw r10,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r10.u32);
	// stw r11,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r11.u32);
	// bl 0x823eaa90
	ctx.lr = 0x8274D740;
	sub_823EAA90(ctx, base);
loc_8274D740:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8274D748"))) PPC_WEAK_FUNC(sub_8274D748);
PPC_FUNC_IMPL(__imp__sub_8274D748) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8274D750;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// bne cr6,0x8274d7d0
	if (!cr6.eq) goto loc_8274D7D0;
	// addi r10,r5,344
	ctx.r10.s64 = ctx.r5.s64 + 344;
	// lwz r31,1320(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 1320);
	// addi r7,r11,1328
	ctx.r7.s64 = r11.s64 + 1328;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r11,1376
	r29.s64 = r11.s64 + 1376;
	// addi r8,r11,1112
	ctx.r8.s64 = r11.s64 + 1112;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r11,4
	r11.s64 = 4;
loc_8274D788:
	// lwz r30,0(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274d7a4
	if (cr6.eq) goto loc_8274D7A4;
	// lwz r30,0(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274d7a4
	if (cr6.eq) goto loc_8274D7A4;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
loc_8274D7A4:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// bne 0x8274d788
	if (!cr0.eq) goto loc_8274D788;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8274d7e0
	if (cr6.eq) goto loc_8274D7E0;
	// divwu r11,r31,r4
	r11.u32 = r31.u32 / ctx.r4.u32;
	// twllei r4,0
	// mullw r11,r11,r4
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r4.s32);
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
	// b 0x8274d7e0
	goto loc_8274D7E0;
loc_8274D7D0:
	// li r31,0
	r31.s64 = 0;
	// addi r7,r11,1424
	ctx.r7.s64 = r11.s64 + 1424;
	// addi r29,r11,1832
	r29.s64 = r11.s64 + 1832;
	// li r10,34
	ctx.r10.s64 = 34;
loc_8274D7E0:
	// mulli r11,r10,12
	r11.s64 = ctx.r10.s64 * 12;
	// add r28,r11,r7
	r28.u64 = r11.u64 + ctx.r7.u64;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// cmplw cr6,r7,r28
	cr6.compare<uint32_t>(ctx.r7.u32, r28.u32, xer);
	// bge cr6,0x8274d814
	if (!cr6.lt) goto loc_8274D814;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_8274D7F8:
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + r11.u64;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// neg r4,r4
	ctx.r4.s64 = -ctx.r4.s64;
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// blt cr6,0x8274d7f8
	if (cr6.lt) goto loc_8274D7F8;
loc_8274D814:
	// li r30,0
	r30.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274d898
	if (cr6.eq) goto loc_8274D898;
loc_8274D824:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8274d888
	if (cr6.eq) goto loc_8274D888;
	// add r11,r4,r31
	r11.u64 = ctx.r4.u64 + r31.u64;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// divwu r9,r11,r10
	ctx.r9.u32 = r11.u32 / ctx.r10.u32;
	// twllei r10,0
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// mulli r9,r11,3
	ctx.r9.s64 = r11.s64 * 3;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// mulli r11,r11,12
	r11.s64 = r11.s64 * 12;
	// rlwinm r27,r9,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwzx r27,r27,r29
	r27.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// lwzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmpw cr6,r9,r27
	cr6.compare<int32_t>(ctx.r9.s32, r27.s32, xer);
	// bge cr6,0x8274d87c
	if (!cr6.lt) goto loc_8274D87C;
	// addic. r9,r9,1
	xer.ca = ctx.r9.u32 > 4294967294;
	ctx.r9.s64 = ctx.r9.s64 + 1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// ble 0x8274d87c
	if (!cr0.gt) goto loc_8274D87C;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
loc_8274D87C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// blt cr6,0x8274d824
	if (cr6.lt) goto loc_8274D824;
loc_8274D888:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8274d898
	if (cr6.eq) goto loc_8274D898;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8274d814
	if (!cr6.eq) goto loc_8274D814;
loc_8274D898:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// cmplw cr6,r7,r28
	cr6.compare<uint32_t>(ctx.r7.u32, r28.u32, xer);
	// bge cr6,0x8274d8d0
	if (!cr6.lt) goto loc_8274D8D0;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_8274D8A8:
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x8274d8bc
	if (!cr6.lt) goto loc_8274D8BC;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
loc_8274D8BC:
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// add r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// blt cr6,0x8274d8a8
	if (cr6.lt) goto loc_8274D8A8;
loc_8274D8D0:
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274D8D4"))) PPC_WEAK_FUNC(sub_8274D8D4);
PPC_FUNC_IMPL(__imp__sub_8274D8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D8D8"))) PPC_WEAK_FUNC(sub_8274D8D8);
PPC_FUNC_IMPL(__imp__sub_8274D8D8) {
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
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8274d93c
	if (cr6.lt) goto loc_8274D93C;
	// beq cr6,0x8274d918
	if (cr6.eq) goto loc_8274D918;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// blt cr6,0x8274d90c
	if (cr6.lt) goto loc_8274D90C;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274d944
	goto loc_8274D944;
loc_8274D90C:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x827bcf54
	ctx.lr = 0x8274D914;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x8274d944
	goto loc_8274D944;
loc_8274D918:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x827bd4a4
	ctx.lr = 0x8274D920;
	__imp__RtlTryEnterCriticalSection(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x8274d930
	if (!cr6.eq) goto loc_8274D930;
	// li r31,0
	r31.s64 = 0;
	// b 0x8274d944
	goto loc_8274D944;
loc_8274D930:
	// lis r31,-32768
	r31.s64 = -2147483648;
	// ori r31,r31,16388
	r31.u64 = r31.u64 | 16388;
	// b 0x8274d944
	goto loc_8274D944;
loc_8274D93C:
	// addi r3,r3,1272
	ctx.r3.s64 = ctx.r3.s64 + 1272;
	// bl 0x827bcf64
	ctx.lr = 0x8274D944;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8274D944:
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

__attribute__((alias("__imp__sub_8274D95C"))) PPC_WEAK_FUNC(sub_8274D95C);
PPC_FUNC_IMPL(__imp__sub_8274D95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D960"))) PPC_WEAK_FUNC(sub_8274D960);
PPC_FUNC_IMPL(__imp__sub_8274D960) {
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
	ctx.lr = 0x8274D968;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r27,r31,1272
	r27.s64 = r31.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274D988;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,278
	r11.s64 = r30.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8274d9a8
	if (!cr6.eq) goto loc_8274D9A8;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274d9b8
	goto loc_8274D9B8;
loc_8274D9A8:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82751270
	ctx.lr = 0x8274D9B4;
	sub_82751270(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274D9B8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274D9C0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274D9CC"))) PPC_WEAK_FUNC(sub_8274D9CC);
PPC_FUNC_IMPL(__imp__sub_8274D9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274D9D0"))) PPC_WEAK_FUNC(sub_8274D9D0);
PPC_FUNC_IMPL(__imp__sub_8274D9D0) {
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
	ctx.lr = 0x8274D9D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r27,r31,1272
	r27.s64 = r31.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274D9F8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,278
	r11.s64 = r30.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8274da18
	if (!cr6.eq) goto loc_8274DA18;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274da28
	goto loc_8274DA28;
loc_8274DA18:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x827512e8
	ctx.lr = 0x8274DA24;
	sub_827512E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274DA28:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DA30;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274DA3C"))) PPC_WEAK_FUNC(sub_8274DA3C);
PPC_FUNC_IMPL(__imp__sub_8274DA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274DA40"))) PPC_WEAK_FUNC(sub_8274DA40);
PPC_FUNC_IMPL(__imp__sub_8274DA40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,1324
	r11.s64 = ctx.r3.s64 + 1324;
loc_8274DA44:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// stwcx. r4,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r4.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8274da44
	if (!cr0.eq) goto loc_8274DA44;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274DA64"))) PPC_WEAK_FUNC(sub_8274DA64);
PPC_FUNC_IMPL(__imp__sub_8274DA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274DA68"))) PPC_WEAK_FUNC(sub_8274DA68);
PPC_FUNC_IMPL(__imp__sub_8274DA68) {
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
	ctx.lr = 0x8274DA70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,1272
	r29.s64 = r31.s64 + 1272;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274DA88;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274dabc
	if (cr6.eq) goto loc_8274DABC;
	// addi r10,r31,1096
	ctx.r10.s64 = r31.s64 + 1096;
loc_8274DA9C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8274dabc
	if (!cr6.eq) goto loc_8274DABC;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x8274da9c
	if (cr6.lt) goto loc_8274DA9C;
loc_8274DABC:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x8274dad0
	if (!cr6.eq) goto loc_8274DAD0;
	// lis r30,-32768
	r30.s64 = -2147483648;
	// ori r30,r30,16389
	r30.u64 = r30.u64 | 16389;
	// b 0x8274db0c
	goto loc_8274DB0C;
loc_8274DAD0:
	// addi r11,r11,274
	r11.s64 = r11.s64 + 274;
	// addi r9,r30,278
	ctx.r9.s64 = r30.s64 + 278;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r8,r10,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// stwx r8,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r8.u32);
	// stwx r9,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r9.u32);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82751870
	ctx.lr = 0x8274DAFC;
	sub_82751870(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x8274db0c
	if (cr0.lt) goto loc_8274DB0C;
	// li r11,1
	r11.s64 = 1;
	// stw r11,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r11.u32);
loc_8274DB0C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DB14;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274DB20"))) PPC_WEAK_FUNC(sub_8274DB20);
PPC_FUNC_IMPL(__imp__sub_8274DB20) {
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
	ctx.lr = 0x8274DB28;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,1272
	r29.s64 = r31.s64 + 1272;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274DB40;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,278
	r11.s64 = r30.s64 + 278;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274db90
	if (cr6.eq) goto loc_8274DB90;
	// addi r9,r31,1096
	ctx.r9.s64 = r31.s64 + 1096;
loc_8274DB64:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8274db84
	if (cr6.eq) goto loc_8274DB84;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8274db64
	if (cr6.lt) goto loc_8274DB64;
	// b 0x8274db90
	goto loc_8274DB90;
loc_8274DB84:
	// addi r11,r10,274
	r11.s64 = ctx.r10.s64 + 274;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r3.u32);
loc_8274DB90:
	// bl 0x82751150
	ctx.lr = 0x8274DB94;
	sub_82751150(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DB9C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274DBA8"))) PPC_WEAK_FUNC(sub_8274DBA8);
PPC_FUNC_IMPL(__imp__sub_8274DBA8) {
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
	ctx.lr = 0x8274DBB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,1272
	r30.s64 = r31.s64 + 1272;
	// li r28,0
	r28.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274DBCC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r29,278
	r11.s64 = r29.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274dbe8
	if (cr6.eq) goto loc_8274DBE8;
	// bl 0x82750ae0
	ctx.lr = 0x8274DBE4;
	sub_82750AE0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8274DBE8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DBF0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274DBFC"))) PPC_WEAK_FUNC(sub_8274DBFC);
PPC_FUNC_IMPL(__imp__sub_8274DBFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274DC00"))) PPC_WEAK_FUNC(sub_8274DC00);
PPC_FUNC_IMPL(__imp__sub_8274DC00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r4,278
	r11.s64 = ctx.r4.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274dc28
	if (cr6.eq) goto loc_8274DC28;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274dc28
	if (cr6.eq) goto loc_8274DC28;
	// lwz r3,144(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// blr 
	return;
loc_8274DC28:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274DC30"))) PPC_WEAK_FUNC(sub_8274DC30);
PPC_FUNC_IMPL(__imp__sub_8274DC30) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,1268(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1268);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274DC38"))) PPC_WEAK_FUNC(sub_8274DC38);
PPC_FUNC_IMPL(__imp__sub_8274DC38) {
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
	ctx.lr = 0x8274DC40;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r26,r31,1272
	r26.s64 = r31.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274DC64;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r30,278
	r11.s64 = r30.s64 + 278;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8274dc84
	if (!cr6.eq) goto loc_8274DC84;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274dca0
	goto loc_8274DCA0;
loc_8274DC84:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,-1840(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -1840);
	// bl 0x82751670
	ctx.lr = 0x8274DC9C;
	sub_82751670(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274DCA0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274DCA8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274DCB4"))) PPC_WEAK_FUNC(sub_8274DCB4);
PPC_FUNC_IMPL(__imp__sub_8274DCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274DCB8"))) PPC_WEAK_FUNC(sub_8274DCB8);
PPC_FUNC_IMPL(__imp__sub_8274DCB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274dcec
	if (cr6.eq) goto loc_8274DCEC;
	// addi r10,r3,1128
	ctx.r10.s64 = ctx.r3.s64 + 1128;
loc_8274DCCC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// ld r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// cmpld cr6,r4,r8
	cr6.compare<uint64_t>(ctx.r4.u64, ctx.r8.u64, xer);
	// beq cr6,0x8274dcec
	if (cr6.eq) goto loc_8274DCEC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x8274dccc
	if (cr6.lt) goto loc_8274DCCC;
loc_8274DCEC:
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x8274dd04
	if (!cr6.lt) goto loc_8274DD04;
	// addi r11,r11,282
	r11.s64 = r11.s64 + 282;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// blr 
	return;
loc_8274DD04:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274DD0C"))) PPC_WEAK_FUNC(sub_8274DD0C);
PPC_FUNC_IMPL(__imp__sub_8274DD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274DD10"))) PPC_WEAK_FUNC(sub_8274DD10);
PPC_FUNC_IMPL(__imp__sub_8274DD10) {
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
	ctx.lr = 0x8274DD18;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r24,r28,1376
	r24.s64 = r28.s64 + 1376;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r22,0
	r22.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x8274DD38;
	sub_8244D150(ctx, base);
	// addi r31,r28,1112
	r31.s64 = r28.s64 + 1112;
	// mr r30,r24
	r30.u64 = r24.u64;
	// li r29,4
	r29.s64 = 4;
loc_8274DD44:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274dd58
	if (cr6.eq) goto loc_8274DD58;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x827516c8
	ctx.lr = 0x8274DD58;
	sub_827516C8(ctx, base);
loc_8274DD58:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// bne 0x8274dd44
	if (!cr0.eq) goto loc_8274DD44;
	// addi r23,r28,1832
	r23.s64 = r28.s64 + 1832;
	// li r5,408
	ctx.r5.s64 = 408;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8244d150
	ctx.lr = 0x8274DD7C;
	sub_8244D150(ctx, base);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// mr r27,r22
	r27.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274dec4
	if (!cr6.gt) goto loc_8274DEC4;
	// addi r31,r28,1128
	r31.s64 = r28.s64 + 1128;
	// mr r25,r23
	r25.u64 = r23.u64;
	// li r26,-1
	r26.s64 = -1;
loc_8274DD98:
	// lwz r11,1308(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1308);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8274de94
	if (!cr6.eq) goto loc_8274DE94;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r27
	r29.u64 = r27.u64;
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8274dde8
	if (cr6.eq) goto loc_8274DDE8;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r30,36
	r11.s64 = r30.s64 + 36;
	// li r8,4
	ctx.r8.s64 = 4;
loc_8274DDC4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8274ddd4
	if (cr6.lt) goto loc_8274DDD4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8274DDD4:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8274ddc4
	if (!cr0.eq) goto loc_8274DDC4;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// b 0x8274ddec
	goto loc_8274DDEC;
loc_8274DDE8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8274DDEC:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// addi r5,r27,1
	ctx.r5.s64 = r27.s64 + 1;
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bge cr6,0x8274de94
	if (!cr6.lt) goto loc_8274DE94;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r6,r31,4
	ctx.r6.s64 = r31.s64 + 4;
loc_8274DE04:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r26
	r11.u64 = r26.u64;
	// li r8,4
	ctx.r8.s64 = 4;
	// addi r9,r10,36
	ctx.r9.s64 = ctx.r10.s64 + 36;
loc_8274DE14:
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x8274de24
	if (cr6.lt) goto loc_8274DE24;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_8274DE24:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8274de14
	if (!cr0.eq) goto loc_8274DE14;
	// ld r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x8274de4c
	if (cr6.eq) goto loc_8274DE4C;
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bge cr6,0x8274de4c
	if (!cr6.lt) goto loc_8274DE4C;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_8274DE4C:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r5,r4
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, xer);
	// blt cr6,0x8274de04
	if (cr6.lt) goto loc_8274DE04;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// beq cr6,0x8274de94
	if (cr6.eq) goto loc_8274DE94;
	// addi r11,r29,282
	r11.s64 = r29.s64 + 282;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// xor r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 ^ r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// xor r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// stwx r10,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// xor r11,r11,r10
	r11.u64 = r11.u64 ^ ctx.r10.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8274DE94:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8274deac
	if (cr6.eq) goto loc_8274DEAC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82752bc0
	ctx.lr = 0x8274DEAC;
	sub_82752BC0(ctx, base);
loc_8274DEAC:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r25,r25,12
	r25.s64 = r25.s64 + 12;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8274dd98
	if (cr6.lt) goto loc_8274DD98;
loc_8274DEC4:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r22,1308(r28)
	PPC_STORE_U32(r28.u32 + 1308, r22.u32);
	// addi r11,r28,1328
	r11.s64 = r28.s64 + 1328;
	// addi r10,r10,-4368
	ctx.r10.s64 = ctx.r10.s64 + -4368;
	// addi r8,r11,48
	ctx.r8.s64 = r11.s64 + 48;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// lwz r7,12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bge cr6,0x8274df24
	if (!cr6.lt) goto loc_8274DF24;
	// addi r6,r24,48
	ctx.r6.s64 = r24.s64 + 48;
	// subf r5,r11,r24
	ctx.r5.s64 = r24.s64 - r11.s64;
loc_8274DEF0:
	// add r10,r5,r11
	ctx.r10.u64 = ctx.r5.u64 + r11.u64;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// bge cr6,0x8274df18
	if (!cr6.lt) goto loc_8274DF18;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stwx r10,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r10.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x8274def0
	if (cr6.lt) goto loc_8274DEF0;
loc_8274DF18:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274df24
	if (cr6.eq) goto loc_8274DF24;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
loc_8274DF24:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r11,r11,-4960
	r11.s64 = r11.s64 + -4960;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x8274d748
	ctx.lr = 0x8274DF40;
	sub_8274D748(ctx, base);
	// cmplw cr6,r3,r22
	cr6.compare<uint32_t>(ctx.r3.u32, r22.u32, xer);
	// ble cr6,0x8274df4c
	if (!cr6.gt) goto loc_8274DF4C;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
loc_8274DF4C:
	// lwz r11,1324(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1324);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274df60
	if (!cr6.eq) goto loc_8274DF60;
	// li r11,2
	r11.s64 = 2;
	// stw r11,1324(r28)
	PPC_STORE_U32(r28.u32 + 1324, r11.u32);
loc_8274DF60:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r6,1324(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 1324);
	// addi r30,r23,408
	r30.s64 = r23.s64 + 408;
	// addi r10,r11,-4928
	ctx.r10.s64 = r11.s64 + -4928;
	// addi r31,r28,1424
	r31.s64 = r28.s64 + 1424;
	// mr r11,r23
	r11.u64 = r23.u64;
	// cmplw cr6,r23,r30
	cr6.compare<uint32_t>(r23.u32, r30.u32, xer);
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// bge cr6,0x8274dfa8
	if (!cr6.lt) goto loc_8274DFA8;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
loc_8274DF88:
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// ble cr6,0x8274df9c
	if (!cr6.gt) goto loc_8274DF9C;
	// li r9,1
	ctx.r9.s64 = 1;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
loc_8274DF9C:
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// blt cr6,0x8274df88
	if (cr6.lt) goto loc_8274DF88;
loc_8274DFA8:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8274d748
	ctx.lr = 0x8274DFB4;
	sub_8274D748(ctx, base);
	// addi r10,r31,408
	ctx.r10.s64 = r31.s64 + 408;
	// mr r11,r23
	r11.u64 = r23.u64;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bge cr6,0x8274dff0
	if (!cr6.lt) goto loc_8274DFF0;
	// subf r8,r23,r31
	ctx.r8.s64 = r31.s64 - r23.s64;
loc_8274DFC8:
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bge cr6,0x8274dff0
	if (!cr6.lt) goto loc_8274DFF0;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// lwzx r7,r7,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stwx r7,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r7.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// add r9,r11,r8
	ctx.r9.u64 = r11.u64 + ctx.r8.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x8274dfc8
	if (cr6.lt) goto loc_8274DFC8;
loc_8274DFF0:
	// cmplw cr6,r3,r22
	cr6.compare<uint32_t>(ctx.r3.u32, r22.u32, xer);
	// ble cr6,0x8274dffc
	if (!cr6.gt) goto loc_8274DFFC;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
loc_8274DFFC:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8274e010
	if (cr6.eq) goto loc_8274E010;
	// lwz r11,1320(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1320);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1320(r28)
	PPC_STORE_U32(r28.u32 + 1320, r11.u32);
loc_8274E010:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8274E01C"))) PPC_WEAK_FUNC(sub_8274E01C);
PPC_FUNC_IMPL(__imp__sub_8274E01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E020"))) PPC_WEAK_FUNC(sub_8274E020);
PPC_FUNC_IMPL(__imp__sub_8274E020) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8274E028;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274E048;
	sub_8244D150(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// bl 0x8244d150
	ctx.lr = 0x8274E06C;
	sub_8244D150(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r30,1
	r30.s64 = 1;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x8274E08C;
	sub_8244D150(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r11.u8);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8244d150
	ctx.lr = 0x8274E0AC;
	sub_8244D150(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stb r30,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r30.u8);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// lwz r11,56(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274e108
	if (cr6.eq) goto loc_8274E108;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8274e0e0
	if (!cr0.eq) goto loc_8274E0E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82750ae0
	ctx.lr = 0x8274E0D8;
	sub_82750AE0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8274e0f8
	if (!cr0.eq) goto loc_8274E0F8;
loc_8274E0E0:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// rlwinm. r11,r11,0,12,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8274e0f8
	if (cr0.eq) goto loc_8274E0F8;
	// lfs f0,184(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x8274e0fc
	goto loc_8274E0FC;
loc_8274E0F8:
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_8274E0FC:
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x823ea270
	ctx.lr = 0x8274E108;
	sub_823EA270(ctx, base);
loc_8274E108:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274E114"))) PPC_WEAK_FUNC(sub_8274E114);
PPC_FUNC_IMPL(__imp__sub_8274E114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E118"))) PPC_WEAK_FUNC(sub_8274E118);
PPC_FUNC_IMPL(__imp__sub_8274E118) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8274e14c
	if (cr6.eq) goto loc_8274E14C;
	// addi r9,r3,1128
	ctx.r9.s64 = ctx.r3.s64 + 1128;
loc_8274E12C:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// ld r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// cmpld cr6,r4,r8
	cr6.compare<uint64_t>(ctx.r4.u64, ctx.r8.u64, xer);
	// beq cr6,0x8274e14c
	if (cr6.eq) goto loc_8274E14C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8274e12c
	if (cr6.lt) goto loc_8274E12C;
loc_8274E14C:
	// lwz r10,12(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// mulli r11,r11,3
	r11.s64 = r11.s64 * 3;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,458
	ctx.r10.s64 = r11.s64 + 458;
	// addi r11,r11,356
	r11.s64 = r11.s64 + 356;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8274E17C"))) PPC_WEAK_FUNC(sub_8274E17C);
PPC_FUNC_IMPL(__imp__sub_8274E17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E180"))) PPC_WEAK_FUNC(sub_8274E180);
PPC_FUNC_IMPL(__imp__sub_8274E180) {
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
	ctx.lr = 0x8274E188;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8274e2e8
	if (cr6.eq) goto loc_8274E2E8;
	// lwz r11,1264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// li r28,0
	r28.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8274e1e0
	if (cr6.eq) goto loc_8274E1E0;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8274e1e0
	if (cr6.eq) goto loc_8274E1E0;
	// lwz r3,1304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1304);
	// bl 0x82458230
	ctx.lr = 0x8274E1BC;
	sub_82458230(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// lwz r3,1264(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r11,1300(r31)
	PPC_STORE_U32(r31.u32 + 1300, r11.u32);
	// bl 0x82135db8
	ctx.lr = 0x8274E1D0;
	sub_82135DB8(ctx, base);
	// stw r28,1300(r31)
	PPC_STORE_U32(r31.u32 + 1300, r28.u32);
	// lwz r3,1264(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// bl 0x8244eee0
	ctx.lr = 0x8274E1DC;
	sub_8244EEE0(ctx, base);
	// stw r30,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, r30.u32);
loc_8274E1E0:
	// lwz r3,1304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1304);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e1fc
	if (cr6.eq) goto loc_8274E1FC;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8274e1fc
	if (cr6.eq) goto loc_8274E1FC;
	// bl 0x8244eee0
	ctx.lr = 0x8274E1F8;
	sub_8244EEE0(ctx, base);
	// stw r30,1304(r31)
	PPC_STORE_U32(r31.u32 + 1304, r30.u32);
loc_8274E1FC:
	// lwz r3,1312(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1312);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e218
	if (cr6.eq) goto loc_8274E218;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8274e218
	if (cr6.eq) goto loc_8274E218;
	// bl 0x8244eee0
	ctx.lr = 0x8274E214;
	sub_8244EEE0(ctx, base);
	// stw r30,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, r30.u32);
loc_8274E218:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e228
	if (cr6.eq) goto loc_8274E228;
	// bl 0x823ea140
	ctx.lr = 0x8274E228;
	sub_823EA140(ctx, base);
loc_8274E228:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e23c
	if (cr6.eq) goto loc_8274E23C;
	// bl 0x823ea140
	ctx.lr = 0x8274E238;
	sub_823EA140(ctx, base);
	// stw r28,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r28.u32);
loc_8274E23C:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e250
	if (cr6.eq) goto loc_8274E250;
	// bl 0x823ea140
	ctx.lr = 0x8274E24C;
	sub_823EA140(ctx, base);
	// stw r28,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r28.u32);
loc_8274E250:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274e284
	if (!cr6.gt) goto loc_8274E284;
	// addi r30,r31,1096
	r30.s64 = r31.s64 + 1096;
loc_8274E264:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82751778
	ctx.lr = 0x8274E26C;
	sub_82751778(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274e264
	if (cr6.lt) goto loc_8274E264;
loc_8274E284:
	// addi r30,r31,1112
	r30.s64 = r31.s64 + 1112;
	// li r29,4
	r29.s64 = 4;
loc_8274E28C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82751778
	ctx.lr = 0x8274E294;
	sub_82751778(ctx, base);
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8274e28c
	if (!cr0.eq) goto loc_8274E28C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274e2d8
	if (!cr6.gt) goto loc_8274E2D8;
	// addi r30,r31,1128
	r30.s64 = r31.s64 + 1128;
loc_8274E2B8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x827526b0
	ctx.lr = 0x8274E2C0;
	sub_827526B0(ctx, base);
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274e2b8
	if (cr6.lt) goto loc_8274E2B8;
loc_8274E2D8:
	// lis r4,24970
	ctx.r4.s64 = 1636433920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// bl 0x821310f8
	ctx.lr = 0x8274E2E8;
	sub_821310F8(ctx, base);
loc_8274E2E8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274E2F0"))) PPC_WEAK_FUNC(sub_8274E2F0);
PPC_FUNC_IMPL(__imp__sub_8274E2F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
loc_8274E304:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	reserved.u32 = *(uint32_t*)(base + r11.u32);
	ctx.r10.u64 = __builtin_bswap32(reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + r11.u32), reserved.s32, __builtin_bswap32(ctx.r10.s32));
	cr0.so = xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8274e304
	if (!cr0.eq) goto loc_8274E304;
	// mr r31,r10
	r31.u64 = ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8274e330
	if (!cr6.eq) goto loc_8274E330;
	// bl 0x8274e180
	ctx.lr = 0x8274E330;
	sub_8274E180(ctx, base);
loc_8274E330:
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

__attribute__((alias("__imp__sub_8274E348"))) PPC_WEAK_FUNC(sub_8274E348);
PPC_FUNC_IMPL(__imp__sub_8274E348) {
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
	ctx.lr = 0x8274E350;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r26,r31,1272
	r26.s64 = r31.s64 + 1272;
	// mr r28,r27
	r28.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E36C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,1300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1300);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x8274e4a4
	if (cr6.eq) goto loc_8274E4A4;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// lwz r3,1312(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1312);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd054
	ctx.lr = 0x8274E38C;
	__imp__XNotifyGetNext(ctx, base);
	// li r30,1
	r30.s64 = 1;
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8274e3d0
	if (cr0.eq) goto loc_8274E3D0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x8274e3cc
	if (cr6.eq) goto loc_8274E3CC;
	// cmplwi cr6,r11,14
	cr6.compare<uint32_t>(r11.u32, 14, xer);
	// beq cr6,0x8274e3cc
	if (cr6.eq) goto loc_8274E3CC;
	// lis r10,1024
	ctx.r10.s64 = 67108864;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8274e3cc
	if (cr6.eq) goto loc_8274E3CC;
	// lis r10,1024
	ctx.r10.s64 = 67108864;
	// ori r10,r10,3
	ctx.r10.u64 = ctx.r10.u64 | 3;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8274e3d0
	if (!cr6.eq) goto loc_8274E3D0;
loc_8274E3CC:
	// stw r30,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r30.u32);
loc_8274E3D0:
	// lwz r11,1092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1092);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8274e42c
	if (!cr6.eq) goto loc_8274E42C;
	// li r5,88
	ctx.r5.s64 = 88;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8244d150
	ctx.lr = 0x8274E3EC;
	sub_8244D150(ctx, base);
	// li r11,1024
	r11.s64 = 1024;
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x823ea320
	ctx.lr = 0x8274E41C;
	sub_823EA320(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x823ea3d8
	ctx.lr = 0x8274E428;
	sub_823EA3D8(ctx, base);
	// stw r30,1092(r31)
	PPC_STORE_U32(r31.u32 + 1092, r30.u32);
loc_8274E42C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dd10
	ctx.lr = 0x8274E434;
	sub_8274DD10(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r30,r31,1112
	r30.s64 = r31.s64 + 1112;
	// li r29,4
	r29.s64 = 4;
loc_8274E440:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e450
	if (cr6.eq) goto loc_8274E450;
	// bl 0x82751360
	ctx.lr = 0x8274E450;
	sub_82751360(ctx, base);
loc_8274E450:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8274e440
	if (!cr0.eq) goto loc_8274E440;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274e4a0
	if (!cr6.gt) goto loc_8274E4A0;
	// addi r30,r31,1128
	r30.s64 = r31.s64 + 1128;
loc_8274E470:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8274e48c
	if (cr6.eq) goto loc_8274E48C;
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8274e48c
	if (cr6.eq) goto loc_8274E48C;
	// bl 0x82752798
	ctx.lr = 0x8274E48C;
	sub_82752798(ctx, base);
loc_8274E48C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8274e470
	if (cr6.lt) goto loc_8274E470;
loc_8274E4A0:
	// stw r27,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r27.u32);
loc_8274E4A4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E4AC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cntlzw r11,r28
	r11.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274E4BC"))) PPC_WEAK_FUNC(sub_8274E4BC);
PPC_FUNC_IMPL(__imp__sub_8274E4BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E4C0"))) PPC_WEAK_FUNC(sub_8274E4C0);
PPC_FUNC_IMPL(__imp__sub_8274E4C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E4C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E4E8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E4F4;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e508
	if (!cr0.eq) goto loc_8274E508;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e518
	goto loc_8274E518;
loc_8274E508:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752848
	ctx.lr = 0x8274E514;
	sub_82752848(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E518:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E520;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274E52C"))) PPC_WEAK_FUNC(sub_8274E52C);
PPC_FUNC_IMPL(__imp__sub_8274E52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E530"))) PPC_WEAK_FUNC(sub_8274E530);
PPC_FUNC_IMPL(__imp__sub_8274E530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E538;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E558;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E564;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e578
	if (!cr0.eq) goto loc_8274E578;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e588
	goto loc_8274E588;
loc_8274E578:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x827528c0
	ctx.lr = 0x8274E584;
	sub_827528C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E588:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E590;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274E59C"))) PPC_WEAK_FUNC(sub_8274E59C);
PPC_FUNC_IMPL(__imp__sub_8274E59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E5A0"))) PPC_WEAK_FUNC(sub_8274E5A0);
PPC_FUNC_IMPL(__imp__sub_8274E5A0) {
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
	ctx.lr = 0x8274E5A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r26,r30,1272
	r26.s64 = r30.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E5CC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244d150
	ctx.lr = 0x8274E5DC;
	sub_8244D150(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8274dcb8
	ctx.lr = 0x8274E5E8;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e5fc
	if (!cr0.eq) goto loc_8274E5FC;
	// lis r29,-32768
	r29.s64 = -2147483648;
	// ori r29,r29,16389
	r29.u64 = r29.u64 | 16389;
	// b 0x8274e694
	goto loc_8274E694;
loc_8274E5FC:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82752938
	ctx.lr = 0x8274E614;
	sub_82752938(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x8274e694
	if (cr0.lt) goto loc_8274E694;
	// lis r12,-1057
	r12.s64 = -69271552;
	// lis r11,-5413
	r11.s64 = -354746368;
	// ori r12,r12,221
	r12.u64 = r12.u64 | 221;
	// lis r10,-1057
	ctx.r10.s64 = -69271552;
	// rldicr r12,r12,32,31
	r12.u64 = __builtin_rotateleft64(r12.u64, 32) & 0xFFFFFFFF00000000;
	// ori r11,r11,61168
	r11.u64 = r11.u64 | 61168;
	// oris r12,r12,60123
	r12.u64 = r12.u64 | 3940220928;
	// ori r10,r10,221
	ctx.r10.u64 = ctx.r10.u64 | 221;
	// ori r12,r12,61168
	r12.u64 = r12.u64 | 61168;
	// rldimi r11,r10,32,0
	r11.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (r11.u64 & 0xFFFFFFFF);
	// and r9,r31,r12
	ctx.r9.u64 = r31.u64 & r12.u64;
	// cmpld cr6,r9,r11
	cr6.compare<uint64_t>(ctx.r9.u64, r11.u64, xer);
	// beq cr6,0x8274e694
	if (cr6.eq) goto loc_8274E694;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r30,1112
	r11.s64 = r30.s64 + 1112;
loc_8274E658:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8274e678
	if (cr6.eq) goto loc_8274E678;
	// lwz r9,196(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// rlwinm r9,r9,0,12,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0000;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8274e68c
	if (cr6.eq) goto loc_8274E68C;
loc_8274E678:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// blt cr6,0x8274e658
	if (cr6.lt) goto loc_8274E658;
	// b 0x8274e694
	goto loc_8274E694;
loc_8274E68C:
	// li r11,1
	r11.s64 = 1;
	// stw r11,1316(r30)
	PPC_STORE_U32(r30.u32 + 1316, r11.u32);
loc_8274E694:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E69C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8274E6A8"))) PPC_WEAK_FUNC(sub_8274E6A8);
PPC_FUNC_IMPL(__imp__sub_8274E6A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8274E6B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,1272
	r30.s64 = r31.s64 + 1272;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E6C8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E6D4;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e6e8
	if (!cr0.eq) goto loc_8274E6E8;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e6f0
	goto loc_8274E6F0;
loc_8274E6E8:
	// bl 0x827529d8
	ctx.lr = 0x8274E6EC;
	sub_827529D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E6F0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E6F8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8274E704"))) PPC_WEAK_FUNC(sub_8274E704);
PPC_FUNC_IMPL(__imp__sub_8274E704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E708"))) PPC_WEAK_FUNC(sub_8274E708);
PPC_FUNC_IMPL(__imp__sub_8274E708) {
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
	ctx.lr = 0x8274E710;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E72C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8274e7b0
	if (!cr6.gt) goto loc_8274E7B0;
	// addi r9,r31,1128
	ctx.r9.s64 = r31.s64 + 1128;
loc_8274E744:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x8274e79c
	if (cr6.eq) goto loc_8274E79C;
	// lis r12,-1057
	r12.s64 = -69271552;
	// lis r8,-5413
	ctx.r8.s64 = -354746368;
	// ori r12,r12,221
	r12.u64 = r12.u64 | 221;
	// lis r7,-1057
	ctx.r7.s64 = -69271552;
	// rldicr r12,r12,32,31
	r12.u64 = __builtin_rotateleft64(r12.u64, 32) & 0xFFFFFFFF00000000;
	// ori r8,r8,61168
	ctx.r8.u64 = ctx.r8.u64 | 61168;
	// oris r12,r12,60123
	r12.u64 = r12.u64 | 3940220928;
	// ori r7,r7,221
	ctx.r7.u64 = ctx.r7.u64 | 221;
	// ori r12,r12,61168
	r12.u64 = r12.u64 | 61168;
	// rldimi r8,r7,32,0
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r8.u64 & 0xFFFFFFFF);
	// and r6,r11,r12
	ctx.r6.u64 = r11.u64 & r12.u64;
	// cmpld cr6,r6,r8
	cr6.compare<uint64_t>(ctx.r6.u64, ctx.r8.u64, xer);
	// beq cr6,0x8274e79c
	if (cr6.eq) goto loc_8274E79C;
	// std r11,0(r29)
	PPC_STORE_U64(r29.u32 + 0, r11.u64);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_8274E79C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8274e744
	if (cr6.lt) goto loc_8274E744;
loc_8274E7B0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E7B8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274E7C4"))) PPC_WEAK_FUNC(sub_8274E7C4);
PPC_FUNC_IMPL(__imp__sub_8274E7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E7C8"))) PPC_WEAK_FUNC(sub_8274E7C8);
PPC_FUNC_IMPL(__imp__sub_8274E7C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8274E7D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r29,r31,1272
	r29.s64 = r31.s64 + 1272;
	// li r30,0
	r30.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E7EC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E7F8;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x8274e808
	if (cr0.eq) goto loc_8274E808;
	// bl 0x82752b00
	ctx.lr = 0x8274E804;
	sub_82752B00(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8274E808:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E810;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274E81C"))) PPC_WEAK_FUNC(sub_8274E81C);
PPC_FUNC_IMPL(__imp__sub_8274E81C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E820"))) PPC_WEAK_FUNC(sub_8274E820);
PPC_FUNC_IMPL(__imp__sub_8274E820) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8274E828;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r29,r31,1272
	r29.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E844;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E850;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e864
	if (!cr0.eq) goto loc_8274E864;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e870
	goto loc_8274E870;
loc_8274E864:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752028
	ctx.lr = 0x8274E86C;
	sub_82752028(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E870:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E878;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8274E884"))) PPC_WEAK_FUNC(sub_8274E884);
PPC_FUNC_IMPL(__imp__sub_8274E884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E888"))) PPC_WEAK_FUNC(sub_8274E888);
PPC_FUNC_IMPL(__imp__sub_8274E888) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E890;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// addi r25,r31,1272
	r25.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E8BC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E8C8;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e8dc
	if (!cr0.eq) goto loc_8274E8DC;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e8f8
	goto loc_8274E8F8;
loc_8274E8DC:
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752130
	ctx.lr = 0x8274E8F4;
	sub_82752130(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E8F8:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E900;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8274E90C"))) PPC_WEAK_FUNC(sub_8274E90C);
PPC_FUNC_IMPL(__imp__sub_8274E90C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E910"))) PPC_WEAK_FUNC(sub_8274E910);
PPC_FUNC_IMPL(__imp__sub_8274E910) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E918;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E938;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E944;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e958
	if (!cr0.eq) goto loc_8274E958;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e968
	goto loc_8274E968;
loc_8274E958:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752ad8
	ctx.lr = 0x8274E964;
	sub_82752AD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E968:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E970;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274E97C"))) PPC_WEAK_FUNC(sub_8274E97C);
PPC_FUNC_IMPL(__imp__sub_8274E97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E980"))) PPC_WEAK_FUNC(sub_8274E980);
PPC_FUNC_IMPL(__imp__sub_8274E980) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8274E988;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r28,r31,1272
	r28.s64 = r31.s64 + 1272;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x827bcf64
	ctx.lr = 0x8274E9A8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8274dcb8
	ctx.lr = 0x8274E9B4;
	sub_8274DCB8(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8274e9c8
	if (!cr0.eq) goto loc_8274E9C8;
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,87
	r31.u64 = r31.u64 | 87;
	// b 0x8274e9d8
	goto loc_8274E9D8;
loc_8274E9C8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82752a60
	ctx.lr = 0x8274E9D4;
	sub_82752A60(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8274E9D8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827bcf54
	ctx.lr = 0x8274E9E0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8274E9EC"))) PPC_WEAK_FUNC(sub_8274E9EC);
PPC_FUNC_IMPL(__imp__sub_8274E9EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8274E9F0"))) PPC_WEAK_FUNC(sub_8274E9F0);
PPC_FUNC_IMPL(__imp__sub_8274E9F0) {
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
	// lis r11,-2
	r11.s64 = -131072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r11,r11,31072
	r11.u64 = r11.u64 | 31072;
	// li r5,0
	ctx.r5.s64 = 0;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8275cef0
	ctx.lr = 0x8274EA24;
	sub_8275CEF0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x8274ea34
	if (!cr0.eq) goto loc_8274EA34;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fe98
	ctx.lr = 0x8274EA34;
	sub_8244FE98(ctx, base);
loc_8274EA34:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8275ce80
	ctx.lr = 0x8274EA50;
	sub_8275CE80(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8274ea60
	if (!cr0.eq) goto loc_8274EA60;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fe98
	ctx.lr = 0x8274EA60;
	sub_8244FE98(ctx, base);
loc_8274EA60:
	// lwz r3,1304(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1304);
	// bl 0x8244ee00
	ctx.lr = 0x8274EA68;
	sub_8244EE00(ctx, base);
	// b 0x8274ea7c
	goto loc_8274EA7C;
loc_8274EA6C:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x82135db8
	ctx.lr = 0x8274EA74;
	sub_82135DB8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8274e348
	ctx.lr = 0x8274EA7C;
	sub_8274E348(ctx, base);
loc_8274EA7C:
	// lwz r11,1300(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1300);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8274ea6c
	if (!cr6.eq) goto loc_8274EA6C;
	// bl 0x8275ce40
	ctx.lr = 0x8274EA90;
	sub_8275CE40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244eee0
	ctx.lr = 0x8274EA98;
	sub_8244EEE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244fe98
	ctx.lr = 0x8274EAA0;
	sub_8244FE98(ctx, base);
}

__attribute__((alias("__imp__sub_8274EAA0"))) PPC_WEAK_FUNC(sub_8274EAA0);
PPC_FUNC_IMPL(__imp__sub_8274EAA0) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8274EAA8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8274ebbc
	if (!cr6.eq) goto loc_8274EBBC;
	// lis r11,-32139
	r11.s64 = -2106261504;
	// lis r10,-32139
	ctx.r10.s64 = -2106261504;
	// addi r11,r11,-11784
	r11.s64 = r11.s64 + -11784;
	// lis r9,-32139
	ctx.r9.s64 = -2106261504;
	// lis r8,-32139
	ctx.r8.s64 = -2106261504;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// addi r10,r10,-7440
	ctx.r10.s64 = ctx.r10.s64 + -7440;
	// addi r9,r9,-10024
	ctx.r9.s64 = ctx.r9.s64 + -10024;
	// addi r11,r8,-9888
	r11.s64 = ctx.r8.s64 + -9888;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r7,-32139
	ctx.r7.s64 = -2106261504;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lis r6,-32139
	ctx.r6.s64 = -2106261504;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// lis r5,-32139
	ctx.r5.s64 = -2106261504;
	// addi r10,r7,-9776
	ctx.r10.s64 = ctx.r7.s64 + -9776;
	// addi r9,r6,-6976
	ctx.r9.s64 = ctx.r6.s64 + -6976;
	// addi r11,r5,-6864
	r11.s64 = ctx.r5.s64 + -6864;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// lis r4,-32139
	ctx.r4.s64 = -2106261504;
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lis r31,-32139
	r31.s64 = -2106261504;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lis r30,-32139
	r30.s64 = -2106261504;
	// addi r10,r4,-9664
	ctx.r10.s64 = ctx.r4.s64 + -9664;
	// addi r9,r31,-9624
	ctx.r9.s64 = r31.s64 + -9624;
	// addi r11,r30,-9440
	r11.s64 = r30.s64 + -9440;
	// stw r10,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r10.u32);
	// lis r29,-32139
	r29.s64 = -2106261504;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// lis r28,-32139
	r28.s64 = -2106261504;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// lis r27,-32139
	r27.s64 = -2106261504;
	// addi r10,r29,-6752
	ctx.r10.s64 = r29.s64 + -6752;
	// addi r9,r28,-6488
	ctx.r9.s64 = r28.s64 + -6488;
	// addi r11,r27,-6392
	r11.s64 = r27.s64 + -6392;
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// lis r26,-32139
	r26.s64 = -2106261504;
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// lis r25,-32139
	r25.s64 = -2106261504;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// lis r24,-32139
	r24.s64 = -2106261504;
	// addi r10,r26,-9304
	ctx.r10.s64 = r26.s64 + -9304;
	// addi r9,r25,-9216
	ctx.r9.s64 = r25.s64 + -9216;
	// addi r11,r24,-6200
	r11.s64 = r24.s64 + -6200;
	// stw r10,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// lis r23,-32139
	r23.s64 = -2106261504;
	// stw r9,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r9.u32);
	// lis r22,-32139
	r22.s64 = -2106261504;
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// lis r21,-32139
	r21.s64 = -2106261504;
	// addi r10,r23,-6112
	ctx.r10.s64 = r23.s64 + -6112;
	// addi r9,r22,-6008
	ctx.r9.s64 = r22.s64 + -6008;
	// addi r11,r21,-9168
	r11.s64 = r21.s64 + -9168;
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// lis r20,-32139
	r20.s64 = -2106261504;
	// stw r9,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r9.u32);
	// lis r19,-32139
	r19.s64 = -2106261504;
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// lis r18,-32139
	r18.s64 = -2106261504;
	// addi r10,r20,-9160
	ctx.r10.s64 = r20.s64 + -9160;
	// addi r9,r19,-5872
	ctx.r9.s64 = r19.s64 + -5872;
	// addi r11,r18,-5760
	r11.s64 = r18.s64 + -5760;
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// stw r9,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
loc_8274EBBC:
	// b 0x823d9220
	return;
}

