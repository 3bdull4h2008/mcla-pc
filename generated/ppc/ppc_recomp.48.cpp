#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_822D67F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-14374(r10)
	PPC_STORE_U8(ctx.r10.u32 + -14374, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D67F0) {
	__imp__sub_822D67F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D6800) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822D6808;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r30,r7,-11984
	r30.s64 = ctx.r7.s64 + -11984;
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lbz r11,-14348(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + -14348);
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r29,16
	r29.s64 = 16;
	// addi r5,r5,-14348
	ctx.r5.s64 = ctx.r5.s64 + -14348;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r6,-14368
	ctx.r8.s64 = ctx.r6.s64 + -14368;
	// lbz r10,-14352(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + -14352);
	// lbz r9,-14444(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + -14444);
	// li r28,32
	r28.s64 = 32;
	// lwz r7,-14448(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + -14448);
	// li r27,48
	r27.s64 = 48;
	// lvx128 v62,r30,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,64
	r31.s64 = 64;
	// stb r11,1(r5)
	PPC_STORE_U8(ctx.r5.u32 + 1, r11.u8);
	// li r26,80
	r26.s64 = 80;
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r4,r4,-14352
	ctx.r4.s64 = ctx.r4.s64 + -14352;
	// li r29,96
	r29.s64 = 96;
	// lvx128 v61,r30,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,-14444
	ctx.r3.s64 = ctx.r3.s64 + -14444;
	// lvx128 v60,r30,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,112
	r11.s64 = 112;
	// stvx128 v63,r30,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r30,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stw r8,-14368(r6)
	PPC_STORE_U32(ctx.r6.u32 + -14368, ctx.r8.u32);
	// stb r10,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r10.u8);
	// stvx128 v61,r30,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r9,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r9.u8);
	// stvx128 v60,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x822d68bc
	if (!cr6.lt) goto loc_822D68BC;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-14389(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -14389);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d68bc
	if (cr6.eq) goto loc_822D68BC;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,-14360(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14360);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x822d68c4
	goto loc_822D68C4;
loc_822D68BC:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
loc_822D68C4:
	// stw r11,-14360(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14360, r11.u32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,3528
	ctx.r9.s64 = r11.s64 + 3528;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lfs f0,-14404(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -14404);
	f0.f64 = double(temp.f32);
	// lbz r6,28(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 28);
	// stfs f0,3672(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 3672, temp.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stb r11,3676(r7)
	PPC_STORE_U8(ctx.r7.u32 + 3676, r11.u8);
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822D6800) {
	__imp__sub_822D6800(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D68F8) {
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
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r10,-13000
	ctx.r3.s64 = ctx.r10.s64 + -13000;
	// addi r4,r11,3644
	ctx.r4.s64 = r11.s64 + 3644;
	// li r11,-1
	r11.s64 = -1;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d693c
	if (!cr6.eq) goto loc_822D693C;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-13020
	ctx.r3.s64 = r11.s64 + -13020;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d6948
	if (cr6.eq) goto loc_822D6948;
loc_822D693C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// bl 0x821c0750
	ctx.lr = 0x822D6948;
	sub_821C0750(ctx, base);
loc_822D6948:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-14340
	ctx.r9.s64 = r11.s64 + -14340;
	// addi r8,r10,-14260
	ctx.r8.s64 = ctx.r10.s64 + -14260;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-14392
	r11.s64 = r11.s64 + -14392;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 ^ 1;
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// beq cr6,0x822d6988
	if (cr6.eq) goto loc_822D6988;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_822D6988:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D68F8) {
	__imp__sub_822D68F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D6998) {
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
	ctx.lr = 0x822D69A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x822d69dc
	if (!cr6.gt) goto loc_822D69DC;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_822D69B8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D69D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// bne 0x822d69b8
	if (!cr0.eq) goto loc_822D69B8;
loc_822D69DC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822D69E4;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822D6998) {
	__imp__sub_822D6998(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D69EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D69EC) {
	__imp__sub_822D69EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D69F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lhz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 84);
	// li r31,0
	r31.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822d6a34
	if (!cr6.gt) goto loc_822D6A34;
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
loc_822D6A14:
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r30,r4
	cr6.compare<uint32_t>(r30.u32, ctx.r4.u32, xer);
	// bne cr6,0x822d6a24
	if (!cr6.eq) goto loc_822D6A24;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_822D6A24:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822d6a14
	if (cr6.lt) goto loc_822D6A14;
loc_822D6A34:
	// stw r31,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r31.u32);
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// stw r31,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r31.u32);
	// beq cr6,0x822d6a6c
	if (cr6.eq) goto loc_822D6A6C;
	// addi r10,r5,11
	ctx.r10.s64 = ctx.r5.s64 + 11;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
loc_822D6A6C:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D69F0) {
	__imp__sub_822D69F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D6A78) {
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
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822D6AA8;
	sub_82137A08(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r7,240(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 240);
	// addi r5,r10,-13440
	ctx.r5.s64 = ctx.r10.s64 + -13440;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82137a08
	ctx.lr = 0x822D6AC4;
	sub_82137A08(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x822D6ACC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d6aec
	if (cr6.eq) goto loc_822D6AEC;
	// bl 0x821e2748
	ctx.lr = 0x822D6ADC;
	sub_821E2748(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x822d6af0
	goto loc_822D6AF0;
loc_822D6AEC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822D6AF0:
	// stw r3,248(r30)
	PPC_STORE_U32(r30.u32 + 248, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-13444
	ctx.r5.s64 = r11.s64 + -13444;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x821e2940
	ctx.lr = 0x822D6B0C;
	sub_821E2940(ctx, base);
	// lis r31,-32130
	r31.s64 = -2105671680;
	// lwz r11,3680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3680);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822d6b50
	if (!cr6.eq) goto loc_822D6B50;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-13460
	ctx.r3.s64 = r11.s64 + -13460;
	// bl 0x821881b8
	ctx.lr = 0x822D6B28;
	sub_821881B8(ctx, base);
	// stw r3,3680(r31)
	PPC_STORE_U32(r31.u32 + 3680, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-13488
	ctx.r3.s64 = ctx.r10.s64 + -13488;
	// bl 0x821881b8
	ctx.lr = 0x822D6B38;
	sub_821881B8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r3,3684(r9)
	PPC_STORE_U32(ctx.r9.u32 + 3684, ctx.r3.u32);
	// stw r11,-14356(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14356, r11.u32);
	// b 0x822d6b5c
	goto loc_822D6B5C;
loc_822D6B50:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-14356(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14356, r11.u32);
loc_822D6B5C:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
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

PPC_WEAK_FUNC(sub_822D6A78) {
	__imp__sub_822D6A78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D6B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D6B74) {
	__imp__sub_822D6B74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D6B78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	PPCRegister temp{};
	PPCVRegister vTemp{};
	// li r11,16
	r11.s64 = 16;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// vspltw128 v60,v1,2
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x55));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// vspltw128 v59,v1,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xFF));
	// addi r8,r10,-13536
	ctx.r8.s64 = ctx.r10.s64 + -13536;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r9,-13520
	ctx.r7.s64 = ctx.r9.s64 + -13520;
	// lvx128 v58,r4,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v62,2
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v56,v58,2
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmrghw128 v54,v59,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v53,v61,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v52,v61,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v51,v55,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v49,v54,v63
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v48,v55,v57
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v47,v52,v63
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v46,v51,v63
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v45,v53,v63
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v44,v48,v63
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vsubfp128 v55,v47,v49
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v49.f32)));
	// vspltw128 v60,v59,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vsubfp128 v56,v46,v49
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v49.f32)));
	// vsubfp128 v54,v45,v49
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v49.f32)));
	// vsubfp128 v57,v44,v49
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v49.f32)));
	// vspltw128 v43,v55,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vsubfp128 v62,v56,v55
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v55.f32)));
	// vspltw128 v0,v55,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x55));
	// vspltw128 v42,v62,2
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v42,v43
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v43.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpgtfp128. v41,v0,v63
	simde_mm_store_ps(v41.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v41.f32), 0xF);
	// mfocrf r6,2
	ctx.r6.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r6,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d6c50
	if (cr6.eq) goto loc_822D6C50;
	// vmsum3fp128 v40,v62,v62
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmulfp128 v39,v0,v0
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vupkd3d128 v38,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v38 = vTemp;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltw128 v13,v38,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x0));
	// vrefp128 v0,v40
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v40.f32)));
	// vor128 v12,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v49,v39,v9
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(ctx.v9.f32)));
	// b 0x822d6c58
	goto loc_822D6C58;
loc_822D6C50:
	// vor128 v49,v63,v63
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltisw128 v61,1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x1)));
loc_822D6C58:
	// vsubfp128 v62,v55,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v54.f32)));
	// vspltw128 v37,v54,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vspltw128 v0,v54,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x55));
	// vmulfp128 v60,v61,v60
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v36,v62,2
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v36,v37
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v37.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpgtfp128. v35,v0,v63
	simde_mm_store_ps(v35.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v35.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6cb8
	if (cr6.eq) goto loc_822D6CB8;
	// vmsum3fp128 v34,v62,v62
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmulfp128 v33,v0,v0
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vupkd3d128 v32,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v32 = vTemp;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltw128 v13,v32,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0x0));
	// vrefp128 v0,v34
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v34.f32)));
	// vor128 v12,v34,v34
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v34.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v51,v33,v9
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(ctx.v9.f32)));
	// b 0x822d6cc0
	goto loc_822D6CC0;
loc_822D6CB8:
	// vor128 v51,v63,v63
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltisw128 v61,1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x1)));
loc_822D6CC0:
	// vsubfp128 v62,v54,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v58,v57,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v0,v57,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x55));
	// vor128 v53,v61,v60
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vspltw128 v60,v59,2
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x55));
	// vspltw128 v52,v62,2
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v52,v58
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v58.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpgtfp128. v48,v0,v63
	simde_mm_store_ps(v48.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v48.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6d24
	if (cr6.eq) goto loc_822D6D24;
	// vmsum3fp128 v47,v62,v62
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmulfp128 v46,v0,v0
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vupkd3d128 v45,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v45 = vTemp;
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltw128 v13,v45,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0x0));
	// vrefp128 v0,v47
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v47.f32)));
	// vor128 v12,v47,v47
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v52,v46,v9
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(ctx.v9.f32)));
	// b 0x822d6d2c
	goto loc_822D6D2C;
loc_822D6D24:
	// vor128 v52,v63,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltisw128 v61,1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x1)));
loc_822D6D2C:
	// vsubfp128 v62,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// vspltw128 v44,v56,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vspltw128 v0,v56,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x55));
	// vmulfp128 v61,v61,v60
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v60,v59,1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xAA));
	// vspltw128 v43,v62,2
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v12,v43,v44
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v44.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpgtfp128. v42,v0,v63
	simde_mm_store_ps(v42.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v42.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6d90
	if (cr6.eq) goto loc_822D6D90;
	// vmsum3fp128 v41,v62,v62
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmulfp128 v40,v0,v0
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vupkd3d128 v39,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v39 = vTemp;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltw128 v13,v39,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0x0));
	// vrefp128 v0,v41
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v41.f32)));
	// vor128 v12,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v40,v9
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(ctx.v9.f32)));
	// b 0x822d6d98
	goto loc_822D6D98;
loc_822D6D90:
	// vor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vspltisw128 v62,1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x1)));
loc_822D6D98:
	// vmulfp128 v38,v62,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v37,v59,3
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x0));
	// vor128 v36,v38,v61
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vor128 v62,v53,v36
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v36.u8)));
	// vcmpequw128. v35,v62,v37
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	cr6.setFromMask(simde_mm_load_ps(v35.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6dc4
	if (cr6.eq) goto loc_822D6DC4;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6DC4:
	// vspltw128 v34,v50,0
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vcmpequw128. v33,v62,v34
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	cr6.setFromMask(simde_mm_load_ps(v33.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6e20
	if (cr6.eq) goto loc_822D6E20;
	// vmsum3fp128 v32,v55,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vspltisw128 v62,1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x1)));
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
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v60,v62,1
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v62.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x0));
	// vrsqrtefp128 v0,v32
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v32.f32))));
	// vor128 v11,v32,v32
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v32.u8));
	// vcmpeqfp128 v10,v32,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v32,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6E20:
	// vspltw128 v59,v50,1
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xAA));
	// vcmpequw128. v55,v62,v59
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	cr6.setFromMask(simde_mm_load_ps(v55.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6e7c
	if (cr6.eq) goto loc_822D6E7C;
	// vmsum3fp128 v54,v56,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v56.f32), 0xEF));
	// vspltisw128 v53,1
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v52,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v52 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v51,v53,1
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v53.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v52,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0x0));
	// vrsqrtefp128 v0,v54
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v54.f32))));
	// vor128 v11,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vcmpeqfp128 v10,v54,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v51,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v54,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6E7C:
	// vspltw128 v48,v50,2
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x55));
	// vcmpequw128. v47,v62,v48
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	cr6.setFromMask(simde_mm_load_ps(v47.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6ed8
	if (cr6.eq) goto loc_822D6ED8;
	// vmsum3fp128 v46,v57,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vspltisw128 v45,1
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v44,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v44 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v43,v45,1
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v45.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v44,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0x0));
	// vrsqrtefp128 v0,v46
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v46.f32))));
	// vor128 v11,v46,v46
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vcmpeqfp128 v10,v46,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v43,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v46,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6ED8:
	// vspltw128 v42,v50,3
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x0));
	// vcmpequw128. v41,v62,v42
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	cr6.setFromMask(simde_mm_load_ps(v41.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d6f34
	if (cr6.eq) goto loc_822D6F34;
	// vmsum3fp128 v40,v54,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vspltisw128 v39,1
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v38,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v38 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v37,v39,1
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v39.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v38,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x0));
	// vrsqrtefp128 v0,v40
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v40.f32))));
	// vor128 v11,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// vcmpeqfp128 v10,v40,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v37,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v40,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822D6F34:
	// vmaxfp128 v36,v58,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v36.f32, simde_mm_max_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v52.f32)));
	// vspltisw128 v35,1
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_set1_epi32(int(0x1)));
	// vmaxfp128 v34,v51,v49
	simde_mm_store_ps(v34.f32, simde_mm_max_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32)));
	// vupkd3d128 v33,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v33 = vTemp;
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vcuxwfp128 v32,v35,1
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v35.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// vspltw128 v12,v33,3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0x0));
	// vmaxfp128 v62,v34,v36
	simde_mm_store_ps(v62.f32, simde_mm_max_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v36.f32)));
	// vrsqrtefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v62.f32))));
	// vor128 v11,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vcmpeqfp128 v10,v62,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v32,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v11,v9,v12
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v62,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel v4,v5,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// stvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D6B78) {
	__imp__sub_822D6B78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D6F80) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822D6F88;
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lvx128 v1,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c148
	ctx.lr = 0x822D6FB0;
	sub_8217C148(ctx, base);
	// lis r28,64
	r28.s64 = 4194304;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ori r28,r28,3
	r28.u64 = r28.u64 | 3;
	// beq cr6,0x822d710c
	if (cr6.eq) goto loc_822D710C;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x822d6fd0
	if (!cr6.eq) goto loc_822D6FD0;
	// li r28,2
	r28.s64 = 2;
loc_822D6FD0:
	// lfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// lis r31,-32119
	r31.s64 = -2104950784;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// lwz r3,-17628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// bl 0x82175f20
	ctx.lr = 0x822D6FF0;
	sub_82175F20(ctx, base);
	// lis r29,1024
	r29.s64 = 67108864;
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// lis r26,4096
	r26.s64 = 268435456;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// beq cr6,0x822d7014
	if (cr6.eq) goto loc_822D7014;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d7018
	if (!cr6.eq) goto loc_822D7018;
loc_822D7014:
	// li r11,0
	r11.s64 = 0;
loc_822D7018:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d710c
	if (cr6.eq) goto loc_822D710C;
	// li r11,208
	r11.s64 = 208;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// li r10,224
	ctx.r10.s64 = 224;
	// lwz r3,-17628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lvx128 v63,r27,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,0
	ctx.r7.s64 = 0;
	// lvx128 v62,r27,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v63,v127,1,1
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v127.f32), 147), 1));
	// vrlimi128 v62,v127,1,1
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v127.f32), 147), 1));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82175508
	ctx.lr = 0x822D7068;
	sub_82175508(ctx, base);
	// rlwinm r8,r3,0,5,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// beq cr6,0x822d7084
	if (cr6.eq) goto loc_822D7084;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d7088
	if (!cr6.eq) goto loc_822D7088;
loc_822D7084:
	// li r11,0
	r11.s64 = 0;
loc_822D7088:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d710c
	if (cr6.eq) goto loc_822D710C;
	// lhz r11,196(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d70f8
	if (cr6.eq) goto loc_822D70F8;
	// clrlwi r6,r11,16
	ctx.r6.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822d70b4
	if (cr6.eq) goto loc_822D70B4;
	// lwz r5,192(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 192);
	// b 0x822d70b8
	goto loc_822D70B8;
loc_822D70B4:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822D70B8:
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r3,-17628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17628);
	// bl 0x82175ad8
	ctx.lr = 0x822D70CC;
	sub_82175AD8(ctx, base);
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// beq cr6,0x822d70e8
	if (cr6.eq) goto loc_822D70E8;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d70ec
	if (!cr6.eq) goto loc_822D70EC;
loc_822D70E8:
	// li r11,0
	r11.s64 = 0;
loc_822D70EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d710c
	if (cr6.eq) goto loc_822D710C;
loc_822D70F8:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d923c
	return;
loc_822D710C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_822D6F80) {
	__imp__sub_822D6F80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7120) {
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
	ctx.lr = 0x822D7128;
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// lhz r11,292(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// rlwinm r10,r11,0,21,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7FE;
	// rlwinm r10,r10,0,28,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC0F;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d7264
	if (cr6.eq) goto loc_822D7264;
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d7264
	if (!cr6.eq) goto loc_822D7264;
	// lfs f0,268(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 268);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// blt cr6,0x822d7174
	if (cr6.lt) goto loc_822D7174;
	// lbz r11,295(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 295);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d7264
	if (cr6.eq) goto loc_822D7264;
loc_822D7174:
	// addi r29,r31,208
	r29.s64 = r31.s64 + 208;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d61a8
	ctx.lr = 0x822D7184;
	sub_822D61A8(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c278
	ctx.lr = 0x822D7198;
	sub_8217C278(ctx, base);
	// addi r6,r3,-2
	ctx.r6.s64 = ctx.r3.s64 + -2;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r4,22080(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22080);
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// lwz r3,-17628(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17628);
	// xori r26,r11,1
	r26.u64 = r11.u64 ^ 1;
	// bl 0x821751a8
	ctx.lr = 0x822D71C8;
	sub_821751A8(ctx, base);
	// li r10,224
	ctx.r10.s64 = 224;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v1,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r31,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82174678
	ctx.lr = 0x822D71DC;
	sub_82174678(ctx, base);
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82174ba0
	ctx.lr = 0x822D71F4;
	sub_82174BA0(ctx, base);
	// lwz r9,248(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r4,292(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lhz r25,36(r8)
	r25.u64 = PPC_LOAD_U16(ctx.r8.u32 + 36);
	// bl 0x822df830
	ctx.lr = 0x822D7210;
	sub_822DF830(ctx, base);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// lhz r5,292(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822df918
	ctx.lr = 0x822D7238;
	sub_822DF918(ctx, base);
	// lwz r6,248(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// rotlwi r11,r25,4
	r11.u64 = __builtin_rotateleft32(r25.u32, 4);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r7,r7,-13248
	ctx.r7.s64 = ctx.r7.s64 + -13248;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r6,24(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x822e0228
	ctx.lr = 0x822D7264;
	sub_822E0228(ctx, base);
loc_822D7264:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_822D7120) {
	__imp__sub_822D7120(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D726C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D726C) {
	__imp__sub_822D726C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7270) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r31,-7572(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lbz r10,14546(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d72c4
	if (!cr6.eq) goto loc_822D72C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D729C;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822d72bc
	if (cr6.gt) goto loc_822D72BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D72B0;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822d72c4
	if (!cr6.lt) goto loc_822D72C4;
loc_822D72BC:
	// li r11,1
	r11.s64 = 1;
	// b 0x822d72c8
	goto loc_822D72C8;
loc_822D72C4:
	// li r11,0
	r11.s64 = 0;
loc_822D72C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d72f0
	if (cr6.eq) goto loc_822D72F0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,3684(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3684);
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
loc_822D72F0:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,3680(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3680);
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

PPC_WEAK_FUNC(sub_822D7270) {
	__imp__sub_822D7270(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D730C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D730C) {
	__imp__sub_822D730C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7310) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,252(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d7330
	if (!cr6.eq) goto loc_822D7330;
	// lwz r11,248(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// blr 
	return;
loc_822D7330:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D7310) {
	__imp__sub_822D7310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7338) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x822D7340;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// bl 0x822d69f0
	ctx.lr = 0x822D7364;
	sub_822D69F0(ctx, base);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r30,88(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// beq cr6,0x822d7388
	if (cr6.eq) goto loc_822D7388;
	// addi r11,r25,5
	r11.s64 = r25.s64 + 5;
	// rlwinm r10,r25,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r29,r10,r26
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// lwzx r28,r9,r26
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + r26.u32);
loc_822D7388:
	// bl 0x821908a8
	ctx.lr = 0x822D738C;
	sub_821908A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822d746c
	if (cr6.eq) goto loc_822D746C;
	// bl 0x82190880
	ctx.lr = 0x822D739C;
	sub_82190880(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x822d740c
	if (!cr6.eq) goto loc_822D740C;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x822d75c0
	if (!cr6.lt) goto loc_822D75C0;
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r27,r27,16
	r27.u64 = r27.u32 & 0xFFFF;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
	// add r29,r10,r29
	r29.u64 = ctx.r10.u64 + r29.u64;
	// subf r31,r31,r30
	r31.s64 = r30.s64 - r31.s64;
loc_822D73C8:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// and r10,r11,r27
	ctx.r10.u64 = r11.u64 & r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d73f4
	if (cr6.eq) goto loc_822D73F4;
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r4,r10,0,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// bl 0x8219a7d0
	ctx.lr = 0x822D73F4;
	sub_8219A7D0(ctx, base);
loc_822D73F4:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x822d73c8
	if (!cr0.eq) goto loc_822D73C8;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_822D740C:
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x822d75c0
	if (!cr6.lt) goto loc_822D75C0;
	// rlwinm r10,r31,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r27,r27,16
	r27.u64 = r27.u32 & 0xFFFF;
	// add r28,r10,r28
	r28.u64 = ctx.r10.u64 + r28.u64;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// subf r31,r31,r30
	r31.s64 = r30.s64 - r31.s64;
loc_822D742C:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// and r10,r11,r27
	ctx.r10.u64 = r11.u64 & r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d7454
	if (cr6.eq) goto loc_822D7454;
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x8219a7d0
	ctx.lr = 0x822D7454;
	sub_8219A7D0(ctx, base);
loc_822D7454:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x822d742c
	if (!cr0.eq) goto loc_822D742C;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_822D746C:
	// bl 0x82190880
	ctx.lr = 0x822D7470;
	sub_82190880(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d7534
	if (!cr6.eq) goto loc_822D7534;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x822d75c0
	if (!cr6.lt) goto loc_822D75C0;
	// rlwinm r10,r31,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r24,r27,16
	r24.u64 = r27.u32 & 0xFFFF;
	// add r27,r10,r28
	r27.u64 = ctx.r10.u64 + r28.u64;
	// add r26,r11,r29
	r26.u64 = r11.u64 + r29.u64;
	// subf r25,r31,r30
	r25.s64 = r30.s64 - r31.s64;
loc_822D7498:
	// lhz r11,0(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 0);
	// and r10,r11,r24
	ctx.r10.u64 = r11.u64 & r24.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d751c
	if (cr6.eq) goto loc_822D751C;
	// ld r11,0(r27)
	r11.u64 = PPC_LOAD_U64(r27.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r30,r10,0,0,28
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187f40
	ctx.lr = 0x822D74CC;
	sub_82187F40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x822d7514
	if (!cr6.gt) goto loc_822D7514;
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_822D74E0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187b88
	ctx.lr = 0x822D74EC;
	sub_82187B88(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D7500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187ba8
	ctx.lr = 0x822D7508;
	sub_82187BA8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x822d74e0
	if (cr6.lt) goto loc_822D74E0;
loc_822D7514:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187bd0
	ctx.lr = 0x822D751C;
	sub_82187BD0(ctx, base);
loc_822D751C:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,2
	r26.s64 = r26.s64 + 2;
	// addi r27,r27,8
	r27.s64 = r27.s64 + 8;
	// bne 0x822d7498
	if (!cr0.eq) goto loc_822D7498;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_822D7534:
	// bl 0x82190880
	ctx.lr = 0x822D7538;
	sub_82190880(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x82187f40
	ctx.lr = 0x822D754C;
	sub_82187F40(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82187b88
	ctx.lr = 0x822D7558;
	sub_82187B88(ctx, base);
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// bge cr6,0x822d75b0
	if (!cr6.lt) goto loc_822D75B0;
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// clrlwi r27,r27,16
	r27.u64 = r27.u32 & 0xFFFF;
	// add r29,r10,r29
	r29.u64 = ctx.r10.u64 + r29.u64;
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// subf r31,r31,r30
	r31.s64 = r30.s64 - r31.s64;
loc_822D757C:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// and r10,r11,r27
	ctx.r10.u64 = r11.u64 & r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d75a0
	if (cr6.eq) goto loc_822D75A0;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D75A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D75A0:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x822d757c
	if (!cr0.eq) goto loc_822D757C;
loc_822D75B0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82187ba8
	ctx.lr = 0x822D75B8;
	sub_82187BA8(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82187bd0
	ctx.lr = 0x822D75C0;
	sub_82187BD0(ctx, base);
loc_822D75C0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_822D7338) {
	__imp__sub_822D7338(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D75C8) {
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
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x822d761c
	if (cr6.eq) goto loc_822D761C;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x822d7610
	if (cr6.eq) goto loc_822D7610;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7610
	if (cr6.eq) goto loc_822D7610;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D7610;
	sub_82130588(ctx, base);
loc_822D7610:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82540c38
	ctx.lr = 0x822D761C;
	sub_82540C38(ctx, base);
loc_822D761C:
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

PPC_WEAK_FUNC(sub_822D75C8) {
	__imp__sub_822D75C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7638) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_822D7638:
	// lhz r11,20(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// li r8,0
	ctx.r8.s64 = 0;
	// addic. r9,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r9.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt 0x822d7688
	if (cr0.lt) goto loc_822D7688;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
loc_822D764C:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// beq cr6,0x822d7680
	if (cr6.eq) goto loc_822D7680;
	// bge cr6,0x822d7670
	if (!cr6.lt) goto loc_822D7670;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// b 0x822d7674
	goto loc_822D7674;
loc_822D7670:
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
loc_822D7674:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x822d764c
	if (!cr6.gt) goto loc_822D764C;
	// b 0x822d7688
	goto loc_822D7688;
loc_822D7680:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822d7698
	if (!cr6.eq) goto loc_822D7698;
loc_822D7688:
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d7638
	if (!cr6.eq) goto loc_822D7638;
	// blr 
	return;
loc_822D7698:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D7638) {
	__imp__sub_822D7638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D76A8) {
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
	ctx.lr = 0x822D76B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d76dc
	if (cr6.eq) goto loc_822D76DC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D76D0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_822D76DC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7714
	if (cr6.eq) goto loc_822D7714;
	// li r30,0
	r30.s64 = 0;
loc_822D76F0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x822db7a8
	ctx.lr = 0x822D7700;
	sub_822DB7A8(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822d76f0
	if (cr6.lt) goto loc_822D76F0;
loc_822D7714:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822D76A8) {
	__imp__sub_822D76A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7720) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r31,-24880(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -24880);
	// stw r3,-24880(r11)
	PPC_STORE_U32(r11.u32 + -24880, ctx.r3.u32);
	// beq cr6,0x822d7750
	if (cr6.eq) goto loc_822D7750;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
loc_822D7750:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x822d7784
	if (cr6.eq) goto loc_822D7784;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// bne 0x822d7784
	if (!cr0.eq) goto loc_822D7784;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D7780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D7784:
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

PPC_WEAK_FUNC(sub_822D7720) {
	__imp__sub_822D7720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7798) {
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
	ctx.lr = 0x822D77A0;
	// stwu r1,-1712(r1)
	ea = -1712 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// sth r28,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, r28.u16);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// sth r28,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r28.u16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821e5fd0
	ctx.lr = 0x822D77D4;
	sub_821E5FD0(ctx, base);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// li r29,60
	r29.s64 = 60;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// stb r28,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r28.u8);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822d7840
	if (cr6.eq) goto loc_822D7840;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82490d00
	ctx.lr = 0x822D7824;
	sub_82490D00(ctx, base);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
loc_822D7840:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r10,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822D7798) {
	__imp__sub_822D7798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D7854) {
	__imp__sub_822D7854(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7858) {
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
	ctx.lr = 0x822D7860;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d78c4
	if (cr6.eq) goto loc_822D78C4;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822d78c4
	if (cr6.eq) goto loc_822D78C4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D7894;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d78c4
	if (cr6.eq) goto loc_822D78C4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D78A8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82491010
	ctx.lr = 0x822D78BC;
	sub_82491010(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822D78C4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822D7858) {
	__imp__sub_822D7858(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D78D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D78D4) {
	__imp__sub_822D78D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D78D8) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r10,-13384
	ctx.r9.s64 = ctx.r10.s64 + -13384;
	// lbz r8,-14373(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -14373);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d7934
	if (cr6.eq) goto loc_822D7934;
	// lhz r11,36(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7934
	if (cr6.eq) goto loc_822D7934;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-13416
	ctx.r3.s64 = ctx.r10.s64 + -13416;
	// lwz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lwz r5,240(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 240);
	// lwz r4,244(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 244);
	// bl 0x82130000
	ctx.lr = 0x822D7934;
	sub_82130000(ctx, base);
loc_822D7934:
	// addi r31,r30,32
	r31.s64 = r30.s64 + 32;
	// lhz r5,38(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 38);
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d6998
	ctx.lr = 0x822D7948;
	sub_822D6998(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r11.u32);
	// sth r11,36(r30)
	PPC_STORE_U16(r30.u32 + 36, r11.u16);
	// sth r11,38(r30)
	PPC_STORE_U16(r30.u32 + 38, r11.u16);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x822D7960;
	sub_82130588(ctx, base);
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x822D7968;
	sub_82130588(ctx, base);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d7988
	if (cr6.eq) goto loc_822D7988;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D7988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D7988:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d79a8
	if (cr6.eq) goto loc_822D79A8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D79A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D79A8:
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822d79c0
	if (cr6.eq) goto loc_822D79C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822d6998
	ctx.lr = 0x822D79C0;
	sub_822D6998(ctx, base);
loc_822D79C0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2810
	ctx.lr = 0x822D79C8;
	sub_821D2810(ctx, base);
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

PPC_WEAK_FUNC(sub_822D78D8) {
	__imp__sub_822D78D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D79E0) {
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
	ctx.lr = 0x822D79E8;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,-12720(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12720);
	// lbz r10,6212(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6212);
	// stb r10,-14389(r31)
	PPC_STORE_U8(r31.u32 + -14389, ctx.r10.u8);
	// stb r8,6212(r11)
	PPC_STORE_U8(r11.u32 + 6212, ctx.r8.u8);
	// lwz r3,-12720(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12720);
	// bl 0x821d33b0
	ctx.lr = 0x822D7A18;
	sub_821D33B0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lbz r6,-14389(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + -14389);
	// addi r27,r11,3628
	r27.s64 = r11.s64 + 3628;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stfs f1,3652(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r7.u32 + 3652, temp.u32);
	// lfs f13,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x822d7a68
	if (cr6.eq) goto loc_822D7A68;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,3660(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3660);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d7a98
	if (!cr6.lt) goto loc_822D7A98;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,12(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3804(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3804);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f13,f12,f11,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f13,8(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822d7ac0
	if (!cr6.gt) goto loc_822D7AC0;
	// b 0x822d7abc
	goto loc_822D7ABC;
loc_822D7A68:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,3656(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3656);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d7a98
	if (!cr6.lt) goto loc_822D7A98;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,12(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3804(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3804);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f13,f12,f11,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f13,8(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822d7ac0
	if (!cr6.gt) goto loc_822D7AC0;
	// b 0x822d7abc
	goto loc_822D7ABC;
loc_822D7A98:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822d7ac0
	if (!cr6.gt) goto loc_822D7AC0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,12(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3804(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3804);
	ctx.f11.f64 = double(temp.f32);
	// fnmsubs f13,f12,f11,f13
	ctx.f13.f64 = double(float(-(ctx.f12.f64 * ctx.f11.f64 - ctx.f13.f64)));
	// stfs f13,8(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d7ac0
	if (!cr6.lt) goto loc_822D7AC0;
loc_822D7ABC:
	// stfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
loc_822D7AC0:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r29,-32130
	r29.s64 = -2105671680;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lbz r11,-14375(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -14375);
	// addi r31,r10,-14240
	r31.s64 = ctx.r10.s64 + -14240;
	// lwz r8,22080(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 22080);
	// addi r7,r9,-14444
	ctx.r7.s64 = ctx.r9.s64 + -14444;
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7b48
	if (cr6.eq) goto loc_822D7B48;
	// rlwinm r11,r8,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	f0.f64 = double(temp.f32);
	// lfs f13,120(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f12,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r11,240
	ctx.r9.s64 = r11.s64 + 240;
	// lfs f11,11368(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11368);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 244);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f8,248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 248);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// lfs f6,240(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 240);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f12,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fcmpu cr6,f1,f11
	cr6.compare(ctx.f1.f64, ctx.f11.f64);
	// ble cr6,0x822d7b48
	if (!cr6.gt) goto loc_822D7B48;
	// li r11,1
	r11.s64 = 1;
	// stb r11,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, r11.u8);
loc_822D7B48:
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lbz r11,-14374(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + -14374);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7b68
	if (cr6.eq) goto loc_822D7B68;
	// li r11,1
	r11.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,1(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1, r11.u8);
	// stb r9,-14374(r6)
	PPC_STORE_U8(ctx.r6.u32 + -14374, ctx.r9.u8);
loc_822D7B68:
	// addi r11,r8,45
	r11.s64 = ctx.r8.s64 + 45;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x822bff40
	ctx.lr = 0x822D7B7C;
	sub_822BFF40(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// addi r30,r11,-12976
	r30.s64 = r11.s64 + -12976;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,22080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 22080);
	// addi r8,r11,45
	ctx.r8.s64 = r11.s64 + 45;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x822bff40
	ctx.lr = 0x822D7BA0;
	sub_822BFF40(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,11364(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11364);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217ce78
	ctx.lr = 0x822D7BB4;
	sub_8217CE78(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f30,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8217ce70
	ctx.lr = 0x822D7BC8;
	sub_8217CE70(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8217ce78
	ctx.lr = 0x822D7BD4;
	sub_8217CE78(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8217ce70
	ctx.lr = 0x822D7BE0;
	sub_8217CE70(ctx, base);
	// li r4,112
	ctx.r4.s64 = 112;
	// li r3,96
	ctx.r3.s64 = 96;
	// lvlx128 v58,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,80
	ctx.r9.s64 = 80;
	// lvx128 v62,r31,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vor128 v59,v62,v62
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v59,v63,v57,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)), simde_mm_load_ps(v59.f32)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x822D7C44;
	sub_8217CE80(ctx, base);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// addi r3,r4,-14348
	ctx.r3.s64 = ctx.r4.s64 + -14348;
	// lbz r11,1(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7c68
	if (cr6.eq) goto loc_822D7C68;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-11984
	r11.s64 = r11.s64 + -11984;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// b 0x822d7c6c
	goto loc_822D7C6C;
loc_822D7C68:
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
loc_822D7C6C:
	// li r10,32
	ctx.r10.s64 = 32;
	// lvlx128 v56,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r9,48
	ctx.r9.s64 = 48;
	// vspltw128 v12,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v0,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v54,r11,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x822D7CC8;
	sub_8217CE80(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r5,r8,-14368
	ctx.r5.s64 = ctx.r8.s64 + -14368;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-14428(r7)
	PPC_STORE_U32(ctx.r7.u32 + -14428, r11.u32);
	// stw r10,-14372(r6)
	PPC_STORE_U32(ctx.r6.u32 + -14372, ctx.r10.u32);
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822D79E0) {
	__imp__sub_822D79E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D7D00) {
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
	PPCVRegister v117{};
	PPCVRegister v118{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x822D7D08;
	// stfd f29,-152(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -152, f29.u64);
	// stfd f30,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, f30.u64);
	// stfd f31,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// addi r12,r1,-160
	r12.s64 = ctx.r1.s64 + -160;
	// bl 0x823dd4fc
	ctx.lr = 0x822D7D1C;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stfs f2,708(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 708, temp.u32);
	// li r11,0
	r11.s64 = 0;
	// fmr f31,f3
	f31.f64 = ctx.f3.f64;
	// addi r21,r30,208
	r21.s64 = r30.s64 + 208;
	// fmr f30,f4
	f30.f64 = ctx.f4.f64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// fmr f29,f5
	f29.f64 = ctx.f5.f64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// sth r11,292(r30)
	PPC_STORE_U16(r30.u32 + 292, r11.u16);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// mr r18,r5
	r18.u64 = ctx.r5.u64;
	// bl 0x822d6240
	ctx.lr = 0x822D7D54;
	sub_822D6240(ctx, base);
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v59,r0,r21
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r7,r9,-31568
	ctx.r7.s64 = ctx.r9.s64 + -31568;
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// lvx128 v58,r21,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// vsubfp128 v57,v58,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// addi r3,r5,2240
	ctx.r3.s64 = ctx.r5.s64 + 2240;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r4,-31648
	ctx.r9.s64 = ctx.r4.s64 + -31648;
	// addi r8,r11,-31664
	ctx.r8.s64 = r11.s64 + -31664;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// addi r5,r7,-13504
	ctx.r5.s64 = ctx.r7.s64 + -13504;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r17,r30,268
	r17.s64 = r30.s64 + 268;
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,-12736
	ctx.r4.s64 = ctx.r6.s64 + -12736;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v53,v57,v62
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v56,r0,r17
	temp.u32 = r17.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r20,r11,3677
	r20.s64 = r11.s64 + 3677;
	// addi r11,r1,708
	r11.s64 = ctx.r1.s64 + 708;
	// vspltw128 v125,v56,0
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// li r10,-41
	ctx.r10.s64 = -41;
	// vspltw128 v123,v63,0
	simde_mm_store_si128((simde__m128i*)v123.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v124,r0,r4
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v122,r0,r3
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// vor128 v126,v122,v122
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v122.u8));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvlx128 v55,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v54,r20,r10
	temp.u32 = r20.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r24,0
	r24.s64 = 0;
	// vspltw128 v118,v54,0
	simde_mm_store_si128((simde__m128i*)v118.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stvx128 v125,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v117,v55,0
	simde_mm_store_si128((simde__m128i*)v117.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// stvx128 v123,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v119,v63,3
	simde_mm_store_si128((simde__m128i*)v119.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vmsum3fp128 v52,v53,v53
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vaddfp128 v51,v53,v59
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v120,v63,1
	simde_mm_store_si128((simde__m128i*)v120.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// vspltw128 v121,v63,2
	simde_mm_store_si128((simde__m128i*)v121.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vrsqrtefp128 v50,v52
	simde_mm_store_ps(v50.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v52.f32))));
	// vor128 v12,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vcmpeqfp128 v11,v50,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v49,v52,v6
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsel128 v124,v51,v49,v124
	// stvx128 v124,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r11,-14240
	r28.s64 = r11.s64 + -14240;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// li r22,112
	r22.s64 = 112;
	// li r23,96
	r23.s64 = 96;
	// addi r27,r10,-12976
	r27.s64 = ctx.r10.s64 + -12976;
	// addi r26,r11,-14352
	r26.s64 = r11.s64 + -14352;
	// addi r25,r9,-14348
	r25.s64 = ctx.r9.s64 + -14348;
loc_822D7E84:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x822d7eb0
	if (!cr6.eq) goto loc_822D7EB0;
	// lbz r11,1(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7ea8
	if (cr6.eq) goto loc_822D7EA8;
	// lbz r11,1(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7ec8
	if (cr6.eq) goto loc_822D7EC8;
loc_822D7EA8:
	// mr r31,r28
	r31.u64 = r28.u64;
	// b 0x822d7ecc
	goto loc_822D7ECC;
loc_822D7EB0:
	// lbz r11,1(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7fb0
	if (cr6.eq) goto loc_822D7FB0;
	// lbz r11,1(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d7fb0
	if (cr6.eq) goto loc_822D7FB0;
loc_822D7EC8:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822D7ECC:
	// lvx128 v48,r31,r23
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v0,v122,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v122.u32), 0xAA));
	// vspltw128 v47,v48,1
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xAA));
	// lvx128 v127,r31,r22
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v13,v127,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0xAA));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vcmpgtfp128 v12,v47,v121
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v121.f32)));
	// vsel v11,v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vrlimi128 v126,v11,4,1
	simde_mm_store_ps(v126.f32, simde_mm_blend_ps(simde_mm_load_ps(v126.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v11.f32), 147), 4));
	// vor128 v1,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// bl 0x8217c148
	ctx.lr = 0x822D7EF8;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822d7f04
	if (cr6.eq) goto loc_822D7F04;
	// li r29,1
	r29.s64 = 1;
loc_822D7F04:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x822d6b78
	ctx.lr = 0x822D7F14;
	sub_822D6B78(ctx, base);
	// lvx128 v3,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x822d7f44
	if (!cr6.eq) goto loc_822D7F44;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// beq cr6,0x822d7f40
	if (cr6.eq) goto loc_822D7F40;
	// li r11,112
	r11.s64 = 112;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lvx128 v1,r28,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822d6b78
	ctx.lr = 0x822D7F38;
	sub_822D6B78(ctx, base);
	// lvx128 v125,r0,r3
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822d7f44
	goto loc_822D7F44;
loc_822D7F40:
	// vor128 v125,v3,v3
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
loc_822D7F44:
	// vcmpgtfp128. v46,v3,v119
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v119.f32)));
	cr6.setFromMask(simde_mm_load_ps(v46.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d7f64
	if (cr6.eq) goto loc_822D7F64;
	// vcmpgtfp128 v0,v120,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v120.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vor128 v13,v120,v120
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v120.u8));
	// vsel v3,v3,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
loc_822D7F64:
	// vcmpgtfp128. v45,v3,v118
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v118.f32)));
	cr6.setFromMask(simde_mm_load_ps(v45.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d7f7c
	if (cr6.eq) goto loc_822D7F7C;
	// li r29,0
	r29.s64 = 0;
loc_822D7F7C:
	// vcmpgtfp128 v0,v123,v3
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v123.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vor128 v13,v123,v123
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v123.u8));
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// vsel v12,v13,v3,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// vor128 v123,v12,v12
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// beq cr6,0x822d7fa4
	if (cr6.eq) goto loc_822D7FA4;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D7FA4:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// cmpwi cr6,r24,2
	cr6.compare<int32_t>(r24.s32, 2, xer);
	// blt cr6,0x822d7e84
	if (cr6.lt) goto loc_822D7E84;
loc_822D7FB0:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stvx128 v125,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,252(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 252);
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v123,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// lfs f0,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// stfs f0,260(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 260, temp.u32);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stfs f13,0(r17)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
	// lfs f13,-14400(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14400);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// rlwinm r10,r9,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bge cr6,0x822d8020
	if (!cr6.lt) goto loc_822D8020;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d8020
	if (!cr6.eq) goto loc_822D8020;
	// lwz r9,-41(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + -41);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d8020
	if (!cr6.lt) goto loc_822D8020;
	// stfs f0,-14400(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -14400, temp.u32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// stw r11,-14436(r9)
	PPC_STORE_U32(ctx.r9.u32 + -14436, r11.u32);
loc_822D8020:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfs f0,260(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 260);
	f0.f64 = double(temp.f32);
	// lfs f13,-14404(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14404);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822d8060
	if (!cr6.lt) goto loc_822D8060;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d8060
	if (!cr6.eq) goto loc_822D8060;
	// lhz r9,292(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d8060
	if (cr6.eq) goto loc_822D8060;
	// stfs f0,-14404(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -14404, temp.u32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// stw r11,-14432(r9)
	PPC_STORE_U32(ctx.r9.u32 + -14432, r11.u32);
loc_822D8060:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfs f0,260(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 260);
	f0.f64 = double(temp.f32);
	// lfs f13,-14440(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14440);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822d80ac
	if (!cr6.gt) goto loc_822D80AC;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d808c
	if (!cr6.eq) goto loc_822D808C;
	// lwz r9,252(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 252);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x822d80ac
	if (!cr6.eq) goto loc_822D80AC;
loc_822D808C:
	// lhz r9,292(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822d80ac
	if (!cr6.eq) goto loc_822D80AC;
	// stfs f0,-14440(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -14440, temp.u32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// stw r11,-14448(r9)
	PPC_STORE_U32(ctx.r9.u32 + -14448, r11.u32);
loc_822D80AC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfs f0,260(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 260);
	f0.f64 = double(temp.f32);
	// lfs f13,-14396(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -14396);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822d80ec
	if (!cr6.gt) goto loc_822D80EC;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d80ec
	if (cr6.eq) goto loc_822D80EC;
	// lhz r10,292(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d80ec
	if (cr6.eq) goto loc_822D80EC;
	// stfs f0,-14396(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -14396, temp.u32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 244);
	// stw r11,-14424(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14424, r11.u32);
loc_822D80EC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8330
	if (cr6.eq) goto loc_822D8330;
	// lbz r11,0(r20)
	r11.u64 = PPC_LOAD_U8(r20.u32 + 0);
	// li r31,224
	r31.s64 = 224;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8140
	if (cr6.eq) goto loc_822D8140;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lvx128 v1,r0,r21
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r30,r31
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82174678
	ctx.lr = 0x822D811C;
	sub_82174678(ctx, base);
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821749d0
	ctx.lr = 0x822D812C;
	sub_821749D0(ctx, base);
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// rlwinm r10,r3,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// sth r9,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r9.u16);
	// b 0x822d815c
	goto loc_822D815C;
loc_822D8140:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d6f80
	ctx.lr = 0x822D8150;
	sub_822D6F80(ctx, base);
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// or r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 | r11.u64;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D815C:
	// vcmpgtfp128. v44,v117,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v44.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v117.f32), simde_mm_load_ps(v125.f32)));
	cr6.setFromMask(simde_mm_load_ps(v44.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d8200
	if (cr6.eq) goto loc_822D8200;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vspltisw128 v43,-1
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// vspltw128 v42,v124,3
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), 0x0));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r8,240
	ctx.r8.s64 = 240;
	// vslw128 v41,v43,v43
	v41.u32[0] = v43.u32[0] << (v43.u8[0] & 0x1F);
	v41.u32[1] = v43.u32[1] << (v43.u8[4] & 0x1F);
	v41.u32[2] = v43.u32[2] << (v43.u8[8] & 0x1F);
	v41.u32[3] = v43.u32[3] << (v43.u8[12] & 0x1F);
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v40,r0,r9
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v39,r11,r31
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r11,r8
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v37,v39,v40
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32), 0xEF));
	// vmsum3fp128 v36,v39,v38
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v38.f32), 0xEF));
	// vsubfp128 v63,v37,v36
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v36.f32)));
	// vandc128 v35,v63,v41
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vsubfp128 v34,v35,v42
	simde_mm_store_ps(v34.f32, simde_mm_sub_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v42.f32)));
	// vcmpgtfp128. v33,v119,v34
	simde_mm_store_ps(v33.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v119.f32), simde_mm_load_ps(v34.f32)));
	cr6.setFromMask(simde_mm_load_ps(v33.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r6,r7,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822d81dc
	if (cr6.eq) goto loc_822D81DC;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,12
	ctx.r10.u64 = r11.u64 | 12;
	// b 0x822d81fc
	goto loc_822D81FC;
loc_822D81DC:
	// vcmpgtfp128. v32,v119,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v32.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v119.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v32.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// bne cr6,0x822d81fc
	if (!cr6.eq) goto loc_822D81FC;
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
loc_822D81FC:
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D8200:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// vor128 v1,v124,v124
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// lwz r11,-12284(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12284);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// bl 0x8217c148
	ctx.lr = 0x822D8214;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822d8228
	if (cr6.eq) goto loc_822D8228;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,1024
	ctx.r10.u64 = r11.u64 | 1024;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D8228:
	// lfs f0,0(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822d82a4
	if (!cr6.lt) goto loc_822D82A4;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// ori r9,r11,240
	ctx.r9.u64 = r11.u64 | 240;
	// sth r9,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r9.u16);
	// lwz r31,-7572(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// lbz r8,14546(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822d8284
	if (!cr6.eq) goto loc_822D8284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D825C;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822d827c
	if (cr6.gt) goto loc_822D827C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D8270;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822d8284
	if (!cr6.lt) goto loc_822D8284;
loc_822D827C:
	// li r11,1
	r11.s64 = 1;
	// b 0x822d8288
	goto loc_822D8288;
loc_822D8284:
	// li r11,0
	r11.s64 = 0;
loc_822D8288:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d82a4
	if (cr6.eq) goto loc_822D82A4;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// rlwinm r10,r10,0,28,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D82A4:
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d8324
	if (cr6.eq) goto loc_822D8324;
	// lfs f0,0(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x822d82cc
	if (!cr6.lt) goto loc_822D82CC;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// ori r10,r11,256
	ctx.r10.u64 = r11.u64 | 256;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D82CC:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x822d82e0
	if (!cr6.lt) goto loc_822D82E0;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,2048
	ctx.r10.u64 = r11.u64 | 2048;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D82E0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8324
	if (cr6.eq) goto loc_822D8324;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8324
	if (cr6.eq) goto loc_822D8324;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x822d8324
	if (!cr6.lt) goto loc_822D8324;
	// lhz r11,292(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 292);
	// ori r10,r11,512
	ctx.r10.u64 = r11.u64 | 512;
	// sth r10,292(r30)
	PPC_STORE_U16(r30.u32 + 292, ctx.r10.u16);
loc_822D8324:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d6540
	ctx.lr = 0x822D832C;
	sub_822D6540(ctx, base);
	// bl 0x822d6498
	ctx.lr = 0x822D8330;
	sub_822D6498(ctx, base);
loc_822D8330:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// addi r12,r1,-160
	r12.s64 = ctx.r1.s64 + -160;
	// bl 0x823dd794
	ctx.lr = 0x822D833C;
	// lfd f29,-152(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f30,-144(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_822D7D00) {
	__imp__sub_822D7D00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D834C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D834C) {
	__imp__sub_822D834C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8350) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x822D8358;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x82130000
	ctx.lr = 0x822D8378;
	sub_82130000(ctx, base);
	// lis r21,-32120
	r21.s64 = -2105016320;
	// lwz r31,-7572(r21)
	r31.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lbz r10,14546(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d83bc
	if (!cr6.eq) goto loc_822D83BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D8394;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822d83b4
	if (cr6.gt) goto loc_822D83B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D83A8;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822d83bc
	if (!cr6.lt) goto loc_822D83BC;
loc_822D83B4:
	// li r11,1
	r11.s64 = 1;
	// b 0x822d83c0
	goto loc_822D83C0;
loc_822D83BC:
	// li r11,0
	r11.s64 = 0;
loc_822D83C0:
	// rlwinm r10,r30,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2000;
	// clrlwi r22,r11,24
	r22.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822d879c
	if (!cr6.eq) goto loc_822D879C;
	// rlwinm r11,r30,0,17,17
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d878c
	if (!cr6.eq) goto loc_822D878C;
	// lis r12,258
	r12.s64 = 16908288;
	// ori r12,r12,6652
	r12.u64 = r12.u64 | 6652;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d875c
	if (cr6.eq) goto loc_822D875C;
	// bl 0x821908a8
	ctx.lr = 0x822D83F4;
	sub_821908A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d840c
	if (!cr6.eq) goto loc_822D840C;
	// rlwinm r11,r30,0,28,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d840c
	if (cr6.eq) goto loc_822D840C;
	// bl 0x8233a5a0
	ctx.lr = 0x822D840C;
	sub_8233A5A0(ctx, base);
loc_822D840C:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D8420;
	sub_822D7338(ctx, base);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d69f0
	ctx.lr = 0x822D8438;
	sub_822D69F0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822d846c
	if (cr6.eq) goto loc_822D846C;
	// rlwinm r11,r30,0,7,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FFFFFC;
	// rlwinm r11,r11,0,28,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFF00000F;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d846c
	if (cr6.eq) goto loc_822D846C;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D846C;
	sub_822D7338(ctx, base);
loc_822D846C:
	// rlwinm r29,r30,0,23,27
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822d848c
	if (cr6.eq) goto loc_822D848C;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D848C;
	sub_822D7338(ctx, base);
loc_822D848C:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d69f0
	ctx.lr = 0x822D84A4;
	sub_822D69F0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// addi r26,r11,3624
	r26.s64 = r11.s64 + 3624;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822d8590
	if (cr6.eq) goto loc_822D8590;
	// rlwinm r11,r30,0,19,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8590
	if (cr6.eq) goto loc_822D8590;
	// lbz r11,54(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 54);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8534
	if (cr6.eq) goto loc_822D8534;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822d8534
	if (cr6.eq) goto loc_822D8534;
	// bl 0x82190880
	ctx.lr = 0x822D84E8;
	sub_82190880(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x822D84F4;
	sub_82190870(ctx, base);
	// lwz r3,-14472(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d8504
	if (cr6.eq) goto loc_822D8504;
	// bl 0x822dacf0
	ctx.lr = 0x822D8504;
	sub_822DACF0(ctx, base);
loc_822D8504:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D8518;
	sub_822D7338(ctx, base);
	// lwz r3,-14472(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d8528
	if (cr6.eq) goto loc_822D8528;
	// bl 0x822dacc8
	ctx.lr = 0x822D8528;
	sub_822DACC8(ctx, base);
loc_822D8528:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82190870
	ctx.lr = 0x822D8530;
	sub_82190870(ctx, base);
	// b 0x822d8590
	goto loc_822D8590;
loc_822D8534:
	// lis r29,-32120
	r29.s64 = -2105016320;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822D8550;
	sub_823112C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822D8558;
	sub_82190890(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D8570;
	sub_822D7338(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82190890
	ctx.lr = 0x822D8578;
	sub_82190890(ctx, base);
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822D8590;
	sub_823112C0(ctx, base);
loc_822D8590:
	// lbz r11,-4(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d85d0
	if (cr6.eq) goto loc_822D85D0;
	// lfs f13,268(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d85d0
	if (!cr6.lt) goto loc_822D85D0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822D85B4;
	sub_82190890(ctx, base);
	// lwz r11,-14472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -14472);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822daac8
	ctx.lr = 0x822D85C8;
	sub_822DAAC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82190890
	ctx.lr = 0x822D85D0;
	sub_82190890(ctx, base);
loc_822D85D0:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d69f0
	ctx.lr = 0x822D85E8;
	sub_822D69F0(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822d87b0
	if (cr6.eq) goto loc_822D87B0;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r26,-32120
	r26.s64 = -2105016320;
	// addi r10,r11,-14420
	ctx.r10.s64 = r11.s64 + -14420;
	// lwz r3,-14344(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -14344);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8218f8d0
	ctx.lr = 0x822D8610;
	sub_8218F8D0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822D8618;
	sub_82190890(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x82190880
	ctx.lr = 0x822D8620;
	sub_82190880(ctx, base);
	// lis r12,258
	r12.s64 = 16908288;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// ori r12,r12,12
	r12.u64 = r12.u64 | 12;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// and r29,r30,r12
	r29.u64 = r30.u64 & r12.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822d86a8
	if (cr6.eq) goto loc_822D86A8;
	// rlwinm r11,r30,0,28,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8660
	if (cr6.eq) goto loc_822D8660;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x822D8654;
	sub_822F7338(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8233a5a0
	ctx.lr = 0x822D865C;
	sub_8233A5A0(ctx, base);
	// b 0x822d8688
	goto loc_822D8688;
loc_822D8660:
	// rlwinm r11,r30,0,7,14
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FE0000;
	// rlwinm r11,r11,0,14,7
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFF03FFFF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8694
	if (cr6.eq) goto loc_822D8694;
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8688
	if (!cr6.eq) goto loc_822D8688;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x822D8688;
	sub_822F7338(ctx, base);
loc_822D8688:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x822D8694;
	sub_822F74F0(ctx, base);
loc_822D8694:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x822D86A4;
	sub_822F3918(ctx, base);
	// b 0x822d86c0
	goto loc_822D86C0;
loc_822D86A8:
	// rlwinm r11,r30,0,19,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FE0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d86c0
	if (cr6.eq) goto loc_822D86C0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x822D86C0;
	sub_82190870(ctx, base);
loc_822D86C0:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D86D4;
	sub_822D7338(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x822d8734
	if (cr6.eq) goto loc_822D8734;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x822D86E8;
	sub_822F74F0(ctx, base);
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8704
	if (!cr6.eq) goto loc_822D8704;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822f7338
	ctx.lr = 0x822D8700;
	sub_822F7338(ctx, base);
	// b 0x822d870c
	goto loc_822D870C;
loc_822D8704:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822f7480
	ctx.lr = 0x822D870C;
	sub_822F7480(ctx, base);
loc_822D870C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-7572(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -7572);
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x822D871C;
	sub_822F3918(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82190890
	ctx.lr = 0x822D8724;
	sub_82190890(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r3,-14344(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -14344);
	// lwz r4,-14408(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14408);
	// bl 0x8218f8d0
	ctx.lr = 0x822D8734;
	sub_8218F8D0(ctx, base);
loc_822D8734:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822d8744
	if (cr6.eq) goto loc_822D8744;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82190890
	ctx.lr = 0x822D8744;
	sub_82190890(ctx, base);
loc_822D8744:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x822d87b0
	if (cr6.eq) goto loc_822D87B0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82190870
	ctx.lr = 0x822D8754;
	sub_82190870(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
loc_822D875C:
	// rlwinm r11,r30,0,11,13
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1C0000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d87b0
	if (cr6.eq) goto loc_822D87B0;
	// lis r11,4
	r11.s64 = 262144;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x822d879c
	if (cr6.eq) goto loc_822D879C;
	// lis r11,8
	r11.s64 = 524288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x822d8794
	if (cr6.eq) goto loc_822D8794;
	// lis r11,16
	r11.s64 = 1048576;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x822d87b0
	if (!cr6.eq) goto loc_822D87B0;
loc_822D878C:
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x822d87a0
	goto loc_822D87A0;
loc_822D8794:
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x822d87a0
	goto loc_822D87A0;
loc_822D879C:
	// li r5,1
	ctx.r5.s64 = 1;
loc_822D87A0:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822d7338
	ctx.lr = 0x822D87B0;
	sub_822D7338(ctx, base);
loc_822D87B0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_822D8350) {
	__imp__sub_822D8350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D87B8) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822D87C0;
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// addi r23,r11,3648
	r23.s64 = r11.s64 + 3648;
	// bne cr6,0x822d87fc
	if (!cr6.eq) goto loc_822D87FC;
	// lfs f13,268(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-32(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822d8bac
	if (cr6.gt) goto loc_822D8BAC;
loc_822D87FC:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,3676(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3676);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d8818
	if (!cr6.eq) goto loc_822D8818;
	// lbz r11,295(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 295);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d8830
	if (cr6.eq) goto loc_822D8830;
loc_822D8818:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,268(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3664(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3664);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822d8834
	if (cr6.lt) goto loc_822D8834;
loc_822D8830:
	// li r11,0
	r11.s64 = 0;
loc_822D8834:
	// rlwinm r10,r26,0,21,30
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x7FE;
	// lwz r9,252(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 252);
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,30,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFC03;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 ^ 1;
	// bne cr6,0x822d8884
	if (!cr6.eq) goto loc_822D8884;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8884
	if (cr6.eq) goto loc_822D8884;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8884
	if (!cr6.eq) goto loc_822D8884;
	// lbz r11,296(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 296);
	// rlwinm r7,r11,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822d8888
	if (!cr6.eq) goto loc_822D8888;
loc_822D8884:
	// li r11,0
	r11.s64 = 0;
loc_822D8888:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r25,-32120
	r25.s64 = -2105016320;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d88bc
	if (!cr6.eq) goto loc_822D88BC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d88b4
	if (!cr6.eq) goto loc_822D88B4;
	// lwz r11,-14380(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -14380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d88bc
	if (!cr6.eq) goto loc_822D88BC;
loc_822D88B4:
	// li r11,0
	r11.s64 = 0;
	// b 0x822d88c0
	goto loc_822D88C0;
loc_822D88BC:
	// li r11,1
	r11.s64 = 1;
loc_822D88C0:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x822d88ec
	if (!cr6.eq) goto loc_822D88EC;
	// lbz r11,295(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 295);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x822d88ec
	if (cr6.eq) goto loc_822D88EC;
	// rlwinm r11,r26,0,11,20
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x1FF800;
	// rlwinm r11,r11,0,19,14
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFE1FFF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822d88f0
	if (!cr6.eq) goto loc_822D88F0;
loc_822D88EC:
	// li r11,0
	r11.s64 = 0;
loc_822D88F0:
	// lis r27,-32120
	r27.s64 = -2105016320;
	// rlwinm r7,r26,0,23,27
	ctx.r7.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x1F0;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// beq cr6,0x822d891c
	if (cr6.eq) goto loc_822D891C;
	// lbz r11,370(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 370);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d891c
	if (cr6.eq) goto loc_822D891C;
	// li r30,1
	r30.s64 = 1;
	// li r31,0
	r31.s64 = 0;
loc_822D891C:
	// rlwinm r11,r26,0,7,7
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x1000000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d8968
	if (cr6.eq) goto loc_822D8968;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r7,-14391(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + -14391);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822d8958
	if (!cr6.eq) goto loc_822D8958;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x822d8958
	if (!cr6.eq) goto loc_822D8958;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,268(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3668(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3668);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822d895c
	if (cr6.lt) goto loc_822D895C;
loc_822D8958:
	// li r11,0
	r11.s64 = 0;
loc_822D895C:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r30,r11,27,31,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
loc_822D8968:
	// rlwinm r11,r26,0,28,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822d89a8
	if (cr6.eq) goto loc_822D89A8;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x822d898c
	if (!cr6.eq) goto loc_822D898C;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8990
	if (!cr6.eq) goto loc_822D8990;
loc_822D898C:
	// li r31,0
	r31.s64 = 0;
loc_822D8990:
	// lbz r11,393(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 393);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d89a8
	if (cr6.eq) goto loc_822D89A8;
	// li r31,1
	r31.s64 = 1;
	// li r30,0
	r30.s64 = 0;
loc_822D89A8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r28,r10,24
	r28.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f29,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmr f31,f0
	f31.f64 = f0.f64;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// beq cr6,0x822d8a3c
	if (cr6.eq) goto loc_822D8A3C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f12,288(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 288);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,3720(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3720);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// blt cr6,0x822d89e4
	if (cr6.lt) goto loc_822D89E4;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
loc_822D89E4:
	// fcmpu cr6,f13,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f29.f64);
	// bge cr6,0x822d89fc
	if (!cr6.lt) goto loc_822D89FC;
	// lbz r11,295(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 295);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x822d89fc
	if (cr6.eq) goto loc_822D89FC;
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 - ctx.f12.f64));
loc_822D89FC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lfs f13,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fsubs f9,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fsubs f8,f0,f10
	ctx.f8.f64 = double(float(f0.f64 - ctx.f10.f64));
	// fsel f7,f9,f9,f29
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// fsel f31,f8,f10,f0
	f31.f64 = ctx.f8.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fnmsubs f30,f7,f13,f0
	f30.f64 = double(float(-(ctx.f7.f64 * ctx.f13.f64 - f0.f64)));
	// bl 0x822e59e8
	ctx.lr = 0x822D8A2C;
	sub_822E59E8(ctx, base);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822e5ad0
	ctx.lr = 0x822D8A38;
	sub_822E5AD0(ctx, base);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
loc_822D8A3C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8a50
	if (!cr6.eq) goto loc_822D8A50;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822d8a6c
	if (cr6.eq) goto loc_822D8A6C;
loc_822D8A50:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// clrlwi r5,r24,16
	ctx.r5.u64 = r24.u32 & 0xFFFF;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822d8350
	ctx.lr = 0x822D8A68;
	sub_822D8350(ctx, base);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
loc_822D8A6C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d8a80
	if (!cr6.eq) goto loc_822D8A80;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822d8bac
	if (cr6.eq) goto loc_822D8BAC;
loc_822D8A80:
	// lwz r11,-14380(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -14380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8b88
	if (cr6.eq) goto loc_822D8B88;
	// lis r12,20
	r12.s64 = 1310720;
	// ori r12,r12,24576
	r12.u64 = r12.u64 | 24576;
	// and r11,r26,r12
	r11.u64 = r26.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d8b88
	if (!cr6.eq) goto loc_822D8B88;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822d8ad4
	if (cr6.eq) goto loc_822D8AD4;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x822e5ad0
	ctx.lr = 0x822D8AB0;
	sub_822E5AD0(ctx, base);
	// lbz r11,-27(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + -27);
	// lfs f0,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r3,12
	ctx.r3.s64 = 12;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8ac8
	if (cr6.eq) goto loc_822D8AC8;
	// fmuls f0,f0,f31
	f0.f64 = double(float(f0.f64 * f31.f64));
loc_822D8AC8:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x822D8AD4;
	sub_8217F768(ctx, base);
loc_822D8AD4:
	// lwz r11,-14380(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -14380);
	// lwz r10,244(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 244);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r31,8(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwzx r29,r8,r7
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// beq cr6,0x822d8b88
	if (cr6.eq) goto loc_822D8B88;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822d8b88
	if (cr6.eq) goto loc_822D8B88;
	// li r30,-1
	r30.s64 = -1;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// bne cr6,0x822d8b58
	if (!cr6.eq) goto loc_822D8B58;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822D8B20;
	sub_8217C088(ctx, base);
	// bl 0x82187bf0
	ctx.lr = 0x822D8B24;
	sub_82187BF0(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-7572(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x822D8B34;
	sub_82205248(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d8b4c
	if (cr6.eq) goto loc_822D8B4C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,3684(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3684);
	// b 0x822d8b54
	goto loc_822D8B54;
loc_822D8B4C:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,3680(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3680);
loc_822D8B54:
	// bl 0x82187be0
	ctx.lr = 0x822D8B58;
	sub_82187BE0(ctx, base);
loc_822D8B58:
	// lis r11,8
	r11.s64 = 524288;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r10,r26,r11
	ctx.r10.s64 = r11.s64 - r26.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r5,r9,28,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x2;
	// bl 0x82190bd8
	ctx.lr = 0x822D8B78;
	sub_82190BD8(ctx, base);
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// bne cr6,0x822d8b88
	if (!cr6.eq) goto loc_822D8B88;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82187be0
	ctx.lr = 0x822D8B88;
	sub_82187BE0(ctx, base);
loc_822D8B88:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822d8bac
	if (cr6.eq) goto loc_822D8BAC;
	// li r3,12
	ctx.r3.s64 = 12;
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x822D8BA0;
	sub_8217F768(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// bl 0x822e62c0
	ctx.lr = 0x822D8BAC;
	sub_822E62C0(ctx, base);
loc_822D8BAC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_822D87B8) {
	__imp__sub_822D87B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8BC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,252(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d8be0
	if (!cr6.eq) goto loc_822D8BE0;
	// lwz r11,248(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// b 0x822d7638
	sub_822D7638(ctx, base);
	return;
loc_822D8BE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D8BC0) {
	__imp__sub_822D8BC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8BE8) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d8c1c
	if (cr6.eq) goto loc_822D8C1C;
	// bl 0x8217d890
	ctx.lr = 0x822D8C10;
	sub_8217D890(ctx, base);
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r10.u32);
loc_822D8C1C:
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// bl 0x821b5a60
	ctx.lr = 0x822D8C24;
	sub_821B5A60(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,295(r31)
	PPC_STORE_U8(r31.u32 + 295, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stb r11,296(r31)
	PPC_STORE_U8(r31.u32 + 296, r11.u8);
	// bl 0x822d68f8
	ctx.lr = 0x822D8C40;
	sub_822D68F8(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lbz r8,-14373(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + -14373);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822d8c5c
	if (cr6.eq) goto loc_822D8C5C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-13372
	ctx.r3.s64 = r11.s64 + -13372;
	// bl 0x82130000
	ctx.lr = 0x822D8C5C;
	sub_82130000(ctx, base);
loc_822D8C5C:
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

PPC_WEAK_FUNC(sub_822D8BE8) {
	__imp__sub_822D8BE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8C74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D8C74) {
	__imp__sub_822D8C74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8C78) {
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
	ctx.lr = 0x822D8C80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,4
	r30.s64 = 4;
	// addi r31,r29,128
	r31.s64 = r29.s64 + 128;
loc_822D8C90:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8ca8
	if (cr6.eq) goto loc_822D8CA8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D8CA8;
	sub_82130588(ctx, base);
loc_822D8CA8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822d8c90
	if (!cr0.lt) goto loc_822D8C90;
	// lhz r11,86(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 86);
	// addi r31,r29,80
	r31.s64 = r29.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8cc8
	if (cr6.eq) goto loc_822D8CC8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D8CC8;
	sub_82130588(ctx, base);
loc_822D8CC8:
	// li r30,4
	r30.s64 = 4;
loc_822D8CCC:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8ce4
	if (cr6.eq) goto loc_822D8CE4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D8CE4;
	sub_82130588(ctx, base);
loc_822D8CE4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822d8ccc
	if (!cr0.lt) goto loc_822D8CCC;
	// addi r31,r29,40
	r31.s64 = r29.s64 + 40;
	// li r30,4
	r30.s64 = 4;
loc_822D8CF4:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8d0c
	if (cr6.eq) goto loc_822D8D0C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822D8D0C;
	sub_82130588(ctx, base);
loc_822D8D0C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822d8cf4
	if (!cr0.lt) goto loc_822D8CF4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822D8C78) {
	__imp__sub_822D8C78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D8D1C) {
	__imp__sub_822D8D1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8D20) {
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
	// bl 0x822d78d8
	ctx.lr = 0x822D8D40;
	sub_822D78D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8d58
	if (cr6.eq) goto loc_822D8D58;
	// bl 0x82130588
	ctx.lr = 0x822D8D54;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822D8D58:
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

PPC_WEAK_FUNC(sub_822D8D20) {
	__imp__sub_822D8D20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8D70) {
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
	ctx.lr = 0x822D8D78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x822D8D84;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d8da8
	if (cr6.eq) goto loc_822D8DA8;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-13236
	ctx.r4.s64 = ctx.r10.s64 + -13236;
	// lwz r5,-25360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// bl 0x8218fad0
	ctx.lr = 0x822D8DA0;
	sub_8218FAD0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x822d8dac
	goto loc_822D8DAC;
loc_822D8DA8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_822D8DAC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r11,r11,-14344
	r11.s64 = r11.s64 + -14344;
	// addi r4,r10,-13256
	ctx.r4.s64 = ctx.r10.s64 + -13256;
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x822D8DCC;
	sub_82182150(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,-13280
	ctx.r3.s64 = ctx.r9.s64 + -13280;
	// lwz r31,-14388(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -14388);
	// bl 0x821c9790
	ctx.lr = 0x822D8DE4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d7638
	ctx.lr = 0x822D8DF0;
	sub_822D7638(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r31,-14388(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -14388);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,-13304
	ctx.r3.s64 = ctx.r7.s64 + -13304;
	// stw r11,-14420(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14420, r11.u32);
	// addi r29,r8,-14420
	r29.s64 = ctx.r8.s64 + -14420;
	// bl 0x821c9790
	ctx.lr = 0x822D8E14;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d7638
	ctx.lr = 0x822D8E20;
	sub_822D7638(ctx, base);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r31,-14388(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -14388);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,-13332
	ctx.r3.s64 = ctx.r6.s64 + -13332;
	// bl 0x821c9790
	ctx.lr = 0x822D8E38;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d7638
	ctx.lr = 0x822D8E44;
	sub_822D7638(ctx, base);
	// stw r3,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822D8D70) {
	__imp__sub_822D8D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8E50) {
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
	ctx.lr = 0x822D8E58;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r30,-7572(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lwz r31,-14428(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14428);
	// lbz r9,14546(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 14546);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822d8eac
	if (!cr6.eq) goto loc_822D8EAC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D8E84;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822d8ea4
	if (cr6.gt) goto loc_822D8EA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822D8E98;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822d8eac
	if (!cr6.lt) goto loc_822D8EAC;
loc_822D8EA4:
	// li r11,1
	r11.s64 = 1;
	// b 0x822d8eb0
	goto loc_822D8EB0;
loc_822D8EAC:
	// li r11,0
	r11.s64 = 0;
loc_822D8EB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r8,r10,-14420
	ctx.r8.s64 = ctx.r10.s64 + -14420;
	// rlwinm r7,r9,29,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x4;
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// xori r5,r7,4
	ctx.r5.u64 = ctx.r7.u64 ^ 4;
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// lwz r3,-14344(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -14344);
	// stw r4,-14408(r6)
	PPC_STORE_U32(ctx.r6.u32 + -14408, ctx.r4.u32);
	// bl 0x8218f8d0
	ctx.lr = 0x822D8EE0;
	sub_8218F8D0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d66e8
	ctx.lr = 0x822D8EE8;
	sub_822D66E8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d8f6c
	if (cr6.eq) goto loc_822D8F6C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r27,-32120
	r27.s64 = -2105016320;
	// addi r30,r11,3624
	r30.s64 = r11.s64 + 3624;
loc_822D8F00:
	// lhz r11,292(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// and r10,r11,r28
	ctx.r10.u64 = r11.u64 & r28.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822d8f60
	if (cr6.eq) goto loc_822D8F60;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d87b8
	ctx.lr = 0x822D8F20;
	sub_822D87B8(ctx, base);
	// lbz r11,-4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d8f60
	if (cr6.eq) goto loc_822D8F60;
	// lfs f13,268(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d8f60
	if (!cr6.lt) goto loc_822D8F60;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822D8F44;
	sub_82190890(ctx, base);
	// lwz r11,-14472(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -14472);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822daac8
	ctx.lr = 0x822D8F58;
	sub_822DAAC8(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82190890
	ctx.lr = 0x822D8F60;
	sub_82190890(ctx, base);
loc_822D8F60:
	// lwz r31,276(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822d8f00
	if (!cr6.eq) goto loc_822D8F00;
loc_822D8F6C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822D8E50) {
	__imp__sub_822D8E50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D8F74) {
	__imp__sub_822D8F74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822d8be8
	sub_822D8BE8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822D8F78) {
	__imp__sub_822D8F78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8F84) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D8F84) {
	__imp__sub_822D8F84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D8F88) {
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
	ctx.lr = 0x822D8F90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r3,r31,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x822D8FA0;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822d9068
	if (!cr6.gt) goto loc_822D9068;
	// mr r30,r25
	r30.u64 = r25.u64;
	// mr r27,r31
	r27.u64 = r31.u64;
	// li r26,0
	r26.s64 = 0;
loc_822D8FB8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d905c
	if (cr6.eq) goto loc_822D905C;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// lwzx r31,r29,r28
	r31.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822d900c
	if (cr6.eq) goto loc_822D900C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D8FE0;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d900c
	if (cr6.eq) goto loc_822D900C;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d9010
	if (cr6.eq) goto loc_822D9010;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D8FFC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x822d9010
	goto loc_822D9010;
loc_822D900C:
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
loc_822D9010:
	// lwzx r29,r29,r28
	r29.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822d9058
	if (cr6.eq) goto loc_822D9058;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82187a38
	ctx.lr = 0x822D902C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d9058
	if (cr6.eq) goto loc_822D9058;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d905c
	if (cr6.eq) goto loc_822D905C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D9048;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x822d905c
	goto loc_822D905C;
loc_822D9058:
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
loc_822D905C:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x822d8fb8
	if (!cr0.eq) goto loc_822D8FB8;
loc_822D9068:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_822D8F88) {
	__imp__sub_822D8F88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D9074) {
	__imp__sub_822D9074(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9078) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d8e50
	sub_822D8E50(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822D9078) {
	__imp__sub_822D9078(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D907C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D907C) {
	__imp__sub_822D907C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9080) {
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
	// lwz r3,240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// bl 0x82130588
	ctx.lr = 0x822D90A0;
	sub_82130588(ctx, base);
	// lwz r30,248(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d90c8
	if (cr6.eq) goto loc_822D90C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82765168
	ctx.lr = 0x822D90B8;
	sub_82765168(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2a40
	ctx.lr = 0x822D90C0;
	sub_821E2A40(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822D90C8;
	sub_82130588(ctx, base);
loc_822D90C8:
	// lhz r11,198(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 198);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d90dc
	if (cr6.eq) goto loc_822D90DC;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x82130588
	ctx.lr = 0x822D90DC;
	sub_82130588(ctx, base);
loc_822D90DC:
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

PPC_WEAK_FUNC(sub_822D9080) {
	__imp__sub_822D9080(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D90F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D90F4) {
	__imp__sub_822D90F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D90F8) {
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
	ctx.lr = 0x822D9100;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// addi r27,r31,16
	r27.s64 = r31.s64 + 16;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// addi r26,r31,24
	r26.s64 = r31.s64 + 24;
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// addi r25,r31,32
	r25.s64 = r31.s64 + 32;
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// addi r29,r31,40
	r29.s64 = r31.s64 + 40;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// addi r23,r31,80
	r23.s64 = r31.s64 + 80;
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// sth r30,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r30.u16);
	// sth r30,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r30.u16);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// sth r30,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r30.u16);
	// sth r30,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r30.u16);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// sth r30,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r30.u16);
	// sth r30,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r30.u16);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// sth r30,44(r31)
	PPC_STORE_U16(r31.u32 + 44, r30.u16);
	// sth r30,46(r31)
	PPC_STORE_U16(r31.u32 + 46, r30.u16);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// sth r30,52(r31)
	PPC_STORE_U16(r31.u32 + 52, r30.u16);
	// sth r30,54(r31)
	PPC_STORE_U16(r31.u32 + 54, r30.u16);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// sth r30,60(r31)
	PPC_STORE_U16(r31.u32 + 60, r30.u16);
	// sth r30,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r30.u16);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// sth r30,68(r31)
	PPC_STORE_U16(r31.u32 + 68, r30.u16);
	// sth r30,70(r31)
	PPC_STORE_U16(r31.u32 + 70, r30.u16);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// sth r30,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r30.u16);
	// sth r30,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r30.u16);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// sth r30,84(r31)
	PPC_STORE_U16(r31.u32 + 84, r30.u16);
	// sth r30,86(r31)
	PPC_STORE_U16(r31.u32 + 86, r30.u16);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// sth r30,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r30.u16);
	// sth r30,94(r31)
	PPC_STORE_U16(r31.u32 + 94, r30.u16);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// sth r30,100(r31)
	PPC_STORE_U16(r31.u32 + 100, r30.u16);
	// sth r30,102(r31)
	PPC_STORE_U16(r31.u32 + 102, r30.u16);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// sth r30,108(r31)
	PPC_STORE_U16(r31.u32 + 108, r30.u16);
	// sth r30,110(r31)
	PPC_STORE_U16(r31.u32 + 110, r30.u16);
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// sth r30,116(r31)
	PPC_STORE_U16(r31.u32 + 116, r30.u16);
	// sth r30,118(r31)
	PPC_STORE_U16(r31.u32 + 118, r30.u16);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// sth r30,124(r31)
	PPC_STORE_U16(r31.u32 + 124, r30.u16);
	// sth r30,126(r31)
	PPC_STORE_U16(r31.u32 + 126, r30.u16);
	// beq cr6,0x822d92b0
	if (cr6.eq) goto loc_822D92B0;
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x822D91F8;
	sub_82130528(ctx, base);
	// li r24,512
	r24.s64 = 512;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r4,512
	ctx.r4.s64 = 512;
	// sth r24,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r24.u16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d8f88
	ctx.lr = 0x822D9210;
	sub_822D8F88(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// sth r24,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r24.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D9220;
	sub_82130528(ctx, base);
	// li r29,128
	r29.s64 = 128;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// sth r29,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r29.u16);
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822d8f88
	ctx.lr = 0x822D9238;
	sub_822D8F88(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// sth r29,54(r31)
	PPC_STORE_U16(r31.u32 + 54, r29.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D9248;
	sub_82130528(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// sth r29,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r29.u16);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822d8f88
	ctx.lr = 0x822D925C;
	sub_822D8F88(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// sth r29,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r29.u16);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822D926C;
	sub_82130528(ctx, base);
	// li r28,32
	r28.s64 = 32;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// sth r28,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r28.u16);
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x822d8f88
	ctx.lr = 0x822D9284;
	sub_822D8F88(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// sth r28,70(r31)
	PPC_STORE_U16(r31.u32 + 70, r28.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D9294;
	sub_82130528(ctx, base);
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// sth r29,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r29.u16);
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822d8f88
	ctx.lr = 0x822D92A8;
	sub_822D8F88(ctx, base);
	// sth r29,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r29.u16);
	// b 0x822d9370
	goto loc_822D9370;
loc_822D92B0:
	// li r3,10240
	ctx.r3.s64 = 10240;
	// bl 0x82130528
	ctx.lr = 0x822D92B8;
	sub_82130528(ctx, base);
	// li r24,5120
	r24.s64 = 5120;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r4,5120
	ctx.r4.s64 = 5120;
	// sth r24,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r24.u16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d8f88
	ctx.lr = 0x822D92D0;
	sub_822D8F88(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// sth r24,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r24.u16);
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x822D92E0;
	sub_82130528(ctx, base);
	// li r24,512
	r24.s64 = 512;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// sth r24,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r24.u16);
	// li r4,512
	ctx.r4.s64 = 512;
	// bl 0x822d8f88
	ctx.lr = 0x822D92F8;
	sub_822D8F88(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// sth r24,54(r31)
	PPC_STORE_U16(r31.u32 + 54, r24.u16);
	// li r3,2048
	ctx.r3.s64 = 2048;
	// bl 0x82130528
	ctx.lr = 0x822D9308;
	sub_82130528(ctx, base);
	// li r29,1024
	r29.s64 = 1024;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// sth r29,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r29.u16);
	// li r4,1024
	ctx.r4.s64 = 1024;
	// bl 0x822d8f88
	ctx.lr = 0x822D9320;
	sub_822D8F88(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// sth r29,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r29.u16);
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D9330;
	sub_82130528(ctx, base);
	// li r29,128
	r29.s64 = 128;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// sth r29,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r29.u16);
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822d8f88
	ctx.lr = 0x822D9348;
	sub_822D8F88(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// sth r29,70(r31)
	PPC_STORE_U16(r31.u32 + 70, r29.u16);
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x822D9358;
	sub_82130528(ctx, base);
	// stw r3,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r3.u32);
	// sth r24,6(r25)
	PPC_STORE_U16(r25.u32 + 6, r24.u16);
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// li r4,512
	ctx.r4.s64 = 512;
	// bl 0x822d8f88
	ctx.lr = 0x822D936C;
	sub_822D8F88(ctx, base);
	// sth r24,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r24.u16);
loc_822D9370:
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// addi r27,r31,148
	r27.s64 = r31.s64 + 148;
	// addi r29,r31,92
	r29.s64 = r31.s64 + 92;
	// li r28,5
	r28.s64 = 5;
	// li r26,65
	r26.s64 = 65;
loc_822D9384:
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82130528
	ctx.lr = 0x822D938C;
	sub_82130528(ctx, base);
	// stw r3,-4(r29)
	PPC_STORE_U32(r29.u32 + -4, ctx.r3.u32);
	// sth r26,2(r29)
	PPC_STORE_U16(r29.u32 + 2, r26.u16);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// sth r8,0(r29)
	PPC_STORE_U16(r29.u32 + 0, ctx.r8.u16);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x822d9384
	if (!cr0.eq) goto loc_822D9384;
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822D93CC;
	sub_82130528(ctx, base);
	// li r11,64
	r11.s64 = 64;
	// stw r3,0(r23)
	PPC_STORE_U32(r23.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,6(r23)
	PPC_STORE_U16(r23.u32 + 6, r11.u16);
	// stb r30,193(r31)
	PPC_STORE_U8(r31.u32 + 193, r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_822D90F8) {
	__imp__sub_822D90F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D93E8) {
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
	ctx.lr = 0x822D93F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,5
	r29.s64 = 5;
	// addi r31,r27,46
	r31.s64 = r27.s64 + 46;
	// li r30,0
	r30.s64 = 0;
	// li r28,1
	r28.s64 = 1;
loc_822D9408:
	// lhz r11,-40(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + -40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d941c
	if (!cr6.eq) goto loc_822D941C;
	// sth r30,-40(r31)
	PPC_STORE_U16(r31.u32 + -40, r30.u16);
	// stw r30,-46(r31)
	PPC_STORE_U32(r31.u32 + -46, r30.u32);
loc_822D941C:
	// sth r30,-42(r31)
	PPC_STORE_U16(r31.u32 + -42, r30.u16);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9434
	if (!cr6.eq) goto loc_822D9434;
	// sth r30,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r30.u16);
	// stw r30,-6(r31)
	PPC_STORE_U32(r31.u32 + -6, r30.u32);
loc_822D9434:
	// sth r30,-2(r31)
	PPC_STORE_U16(r31.u32 + -2, r30.u16);
	// lhz r11,48(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9454
	if (!cr6.eq) goto loc_822D9454;
	// sth r28,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r28.u16);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x822D9450;
	sub_82130528(ctx, base);
	// stw r3,42(r31)
	PPC_STORE_U32(r31.u32 + 42, ctx.r3.u32);
loc_822D9454:
	// sth r28,46(r31)
	PPC_STORE_U16(r31.u32 + 46, r28.u16);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x822d9408
	if (!cr0.eq) goto loc_822D9408;
	// lhz r10,86(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 86);
	// addi r11,r27,80
	r11.s64 = r27.s64 + 80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d947c
	if (!cr6.eq) goto loc_822D947C;
	// sth r30,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r30.u16);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_822D947C:
	// sth r30,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r30.u16);
	// stb r30,193(r27)
	PPC_STORE_U8(r27.u32 + 193, r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822D93E8) {
	__imp__sub_822D93E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D948C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D948C) {
	__imp__sub_822D948C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r11,-13248
	ctx.r3.s64 = r11.s64 + -13248;
	// b 0x822d93e8
	sub_822D93E8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822D9490) {
	__imp__sub_822D9490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D949C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D949C) {
	__imp__sub_822D949C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D94A0) {
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
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x822D94D0;
	sub_82137A08(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r30,r11,-14388
	r30.s64 = r11.s64 + -14388;
	// lwz r11,-14388(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14388);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9548
	if (!cr6.eq) goto loc_822D9548;
loc_822D94E4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d94e4
	if (cr6.eq) goto loc_822D94E4;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r7,r10,-13216
	ctx.r7.s64 = ctx.r10.s64 + -13216;
	// addi r5,r9,-13440
	ctx.r5.s64 = ctx.r9.s64 + -13440;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x822D9518;
	sub_82137A08(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-17804
	ctx.r5.s64 = ctx.r8.s64 + -17804;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821fdd50
	ctx.lr = 0x822D9534;
	sub_821FDD50(ctx, base);
loc_822D9534:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9534
	if (cr6.eq) goto loc_822D9534;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_822D9548:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
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

PPC_WEAK_FUNC(sub_822D94A0) {
	__imp__sub_822D94A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9560) {
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
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x822D958C;
	sub_82137A08(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r11,-14384
	r31.s64 = r11.s64 + -14384;
	// addi r30,r10,-13176
	r30.s64 = ctx.r10.s64 + -13176;
	// lwz r3,-14384(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -14384);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d9638
	if (!cr6.eq) goto loc_822D9638;
loc_822D95A8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d95a8
	if (cr6.eq) goto loc_822D95A8;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r10,-14320
	ctx.r8.s64 = ctx.r10.s64 + -14320;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r5,r9,-13204
	ctx.r5.s64 = ctx.r9.s64 + -13204;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,256
	ctx.r4.s64 = 256;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 ^ 1;
	// bl 0x82137a08
	ctx.lr = 0x822D95F0;
	sub_82137A08(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r9,-17804
	ctx.r5.s64 = ctx.r9.s64 + -17804;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821fdd50
	ctx.lr = 0x822D960C;
	sub_821FDD50(ctx, base);
loc_822D960C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d960c
	if (cr6.eq) goto loc_822D960C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822d9638
	if (!cr6.eq) goto loc_822D9638;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x822d96f4
	goto loc_822D96F4;
loc_822D9638:
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d96f4
	if (cr6.eq) goto loc_822D96F4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-14380
	r31.s64 = r11.s64 + -14380;
	// lwz r11,-14380(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14380);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d96f4
	if (!cr6.eq) goto loc_822D96F4;
loc_822D9654:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9654
	if (cr6.eq) goto loc_822D9654;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x822d7720
	ctx.lr = 0x822D966C;
	sub_822D7720(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r5,r11,-13440
	ctx.r5.s64 = r11.s64 + -13440;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x822D9688;
	sub_82137A08(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r10,-13208
	ctx.r5.s64 = ctx.r10.s64 + -13208;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x822d7798
	ctx.lr = 0x822D96A4;
	sub_822D7798(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// lwz r3,-24880(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24880);
	// stw r11,-24880(r9)
	PPC_STORE_U32(ctx.r9.u32 + -24880, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822d96e0
	if (cr6.eq) goto loc_822D96E0;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x822d96e0
	if (!cr0.eq) goto loc_822D96E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D96E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D96E0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d96e0
	if (cr6.eq) goto loc_822D96E0;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_822D96F4:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
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

PPC_WEAK_FUNC(sub_822D9560) {
	__imp__sub_822D9560(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D970C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D970C) {
	__imp__sub_822D970C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9710) {
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
	ctx.lr = 0x822D9718;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x822D9728;
	sub_821D2970(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r31,r27,8
	r31.s64 = r27.s64 + 8;
	// addi r10,r11,-13384
	ctx.r10.s64 = r11.s64 + -13384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// bl 0x82193cc0
	ctx.lr = 0x822D9740;
	sub_82193CC0(ctx, base);
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d975c
	if (cr6.eq) goto loc_822D975C;
	// lwz r10,-24880(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -24880);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,-24880(r30)
	PPC_STORE_U32(r30.u32 + -24880, r11.u32);
loc_822D975C:
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x822d7858
	ctx.lr = 0x822D9764;
	sub_822D7858(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r23,0
	r23.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d9780
	if (cr6.eq) goto loc_822D9780;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r10,-24880(r30)
	PPC_STORE_U32(r30.u32 + -24880, ctx.r10.u32);
	// stw r23,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r23.u32);
loc_822D9780:
	// addi r24,r27,24
	r24.s64 = r27.s64 + 24;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821b5a60
	ctx.lr = 0x822D978C;
	sub_821B5A60(ctx, base);
	// addi r3,r27,28
	ctx.r3.s64 = r27.s64 + 28;
	// bl 0x821b5a60
	ctx.lr = 0x822D9794;
	sub_821B5A60(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r27,32
	ctx.r3.s64 = r27.s64 + 32;
	// bl 0x822d76a8
	ctx.lr = 0x822D97A4;
	sub_822D76A8(ctx, base);
	// lhz r11,36(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 36);
	// mr r25,r23
	r25.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d9874
	if (cr6.eq) goto loc_822D9874;
	// mr r26,r23
	r26.u64 = r23.u64;
loc_822D97B8:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// add. r31,r26,r11
	r31.u64 = r26.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x822d9860
	if (cr0.eq) goto loc_822D9860;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d9810
	if (cr6.eq) goto loc_822D9810;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D97E4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d9810
	if (cr6.eq) goto loc_822D9810;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d9814
	if (cr6.eq) goto loc_822D9814;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D9800;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x822d9814
	goto loc_822D9814;
loc_822D9810:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_822D9814:
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d985c
	if (cr6.eq) goto loc_822D985C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x822D9830;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x822d985c
	if (cr6.eq) goto loc_822D985C;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822d9860
	if (cr6.eq) goto loc_822D9860;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x822D984C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x822d9860
	goto loc_822D9860;
loc_822D985C:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_822D9860:
	// lhz r11,36(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 36);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,8
	r26.s64 = r26.s64 + 8;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x822d97b8
	if (cr6.lt) goto loc_822D97B8;
loc_822D9874:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_822D9710) {
	__imp__sub_822D9710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9880) {
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
	ctx.lr = 0x822D9888;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x822d993c
	if (!cr6.eq) goto loc_822D993C;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,68
	r25.s64 = 68;
	// lwz r24,0(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r30,r31,r25
	PPC_STORE_U32(r31.u32 + r25.u32, r30.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821bc6b8
	ctx.lr = 0x822D98C0;
	sub_821BC6B8(ctx, base);
	// li r28,60
	r28.s64 = 60;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lwzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// li r27,0
	r27.s64 = 0;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// stb r27,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r27.u8);
	// stwx r9,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, ctx.r9.u32);
	// lwz r11,23572(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 23572);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,23572(r29)
	PPC_STORE_U32(r29.u32 + 23572, r11.u32);
	// beq cr6,0x822d9908
	if (cr6.eq) goto loc_822D9908;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x822d9710
	ctx.lr = 0x822D9908;
	sub_822D9710(ctx, base);
loc_822D9908:
	// sth r27,2(r26)
	PPC_STORE_U16(r26.u32 + 2, r27.u16);
	// lis r4,12288
	ctx.r4.s64 = 805306368;
	// sth r27,0(r26)
	PPC_STORE_U16(r26.u32 + 0, r27.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2808
	ctx.lr = 0x822D991C;
	sub_821E2808(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8276d240
	ctx.lr = 0x822D9924;
	sub_8276D240(ctx, base);
	// lwz r11,23572(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 23572);
	// stwx r27,r31,r25
	PPC_STORE_U32(r31.u32 + r25.u32, r27.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r29)
	PPC_STORE_U32(r29.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, r11.u32);
loc_822D993C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_822D9880) {
	__imp__sub_822D9880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D9944) {
	__imp__sub_822D9944(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9948) {
	PPC_FUNC_PROLOGUE();
	// b 0x822d9880
	sub_822D9880(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822D9948) {
	__imp__sub_822D9948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D994C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D994C) {
	__imp__sub_822D994C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9950) {
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
	ctx.lr = 0x822D9958;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lbz r10,-14373(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -14373);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9988
	if (cr6.eq) goto loc_822D9988;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r4,-24880(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -24880);
	// addi r3,r11,-13172
	ctx.r3.s64 = r11.s64 + -13172;
	// bl 0x82130000
	ctx.lr = 0x822D9988;
	sub_82130000(ctx, base);
loc_822D9988:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-14388(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -14388);
	// bl 0x822d7720
	ctx.lr = 0x822D9994;
	sub_822D7720(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// bl 0x822d9880
	ctx.lr = 0x822D99A0;
	sub_822D9880(ctx, base);
	// lwz r3,-24880(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24880);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,-24880(r30)
	PPC_STORE_U32(r30.u32 + -24880, r11.u32);
	// beq cr6,0x822d99d8
	if (cr6.eq) goto loc_822D99D8;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bne 0x822d99d8
	if (!cr0.eq) goto loc_822D99D8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D99D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D99D8:
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 36);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d9a1c
	if (cr6.eq) goto loc_822D9A1C;
	// li r9,0
	ctx.r9.s64 = 0;
loc_822D99F4:
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r9,80
	ctx.r9.s64 = ctx.r9.s64 + 80;
	// stw r31,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r31.u32);
	// lwz r8,248(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lhz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 36);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x822d99f4
	if (cr6.lt) goto loc_822D99F4;
loc_822D9A1C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822D9950) {
	__imp__sub_822D9950(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D9A24) {
	__imp__sub_822D9A24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9A28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822D9A30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12720(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D9A50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// stw r9,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r9.u32);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x822d9d14
	if (cr6.gt) goto loc_822D9D14;
	// lis r12,-32210
	r12.s64 = -2110914560;
	// addi r12,r12,-25980
	r12.s64 = r12.s64 + -25980;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,-25960(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25960);
	// lwz r17,-25808(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25808);
	// lwz r17,-25324(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25324);
	// lwz r17,-25616(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25616);
	// lwz r17,-25456(r13)
	r17.u64 = PPC_LOAD_U32(ctx.r13.u32 + -25456);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-14373(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -14373);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9ad0
	if (cr6.eq) goto loc_822D9AD0;
	// lfs f1,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f1.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r6,248(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// addi r3,r10,-13044
	ctx.r3.s64 = ctx.r10.s64 + -13044;
	// lwz r7,11724(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// bl 0x82130000
	ctx.lr = 0x822D9AD0;
	sub_82130000(ctx, base);
loc_822D9AD0:
	// lwz r3,-12720(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12720);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32210
	ctx.r10.s64 = -2110914560;
	// lfs f13,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// lwz r4,248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,-13048(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13048);
	f0.f64 = double(temp.f32);
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + f0.f64));
	// addi r6,r10,-26288
	ctx.r6.s64 = ctx.r10.s64 + -26288;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D9B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,252(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r10,2
	ctx.r10.s64 = 2;
	// lfs f12,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f12.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f12,264(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stw r9,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r9.u32);
	// stw r8,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r8.u32);
	// b 0x822d9d14
	goto loc_822D9D14;
	// lbz r11,294(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 294);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9d14
	if (!cr6.eq) goto loc_822D9D14;
	// lwz r4,248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lis r11,12288
	r11.s64 = 805306368;
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r8,r9,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// bne cr6,0x822d9b78
	if (!cr6.eq) goto loc_822D9B78;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r10,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r10.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stw r9,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r9.u32);
	// lfs f0,-13052(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13052);
	f0.f64 = double(temp.f32);
	// stfs f0,264(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// b 0x822d9d14
	goto loc_822D9D14;
loc_822D9B78:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	f0.f64 = double(temp.f32);
	// lfs f13,-30576(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30576);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822d9d14
	if (!cr6.gt) goto loc_822D9D14;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lfs f0,260(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	f0.f64 = double(temp.f32);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x822d9d14
	if (cr6.eq) goto loc_822D9D14;
	// lwz r3,-12720(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12720);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32210
	ctx.r10.s64 = -2110914560;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,-13048(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13048);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 + ctx.f13.f64));
	// addi r6,r10,-26288
	ctx.r6.s64 = ctx.r10.s64 + -26288;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D9BE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	f0.f64 = double(temp.f32);
	// stfs f0,264(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// b 0x822d9d14
	goto loc_822D9D14;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lbz r11,-14373(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -14373);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822d9c1c
	if (cr6.eq) goto loc_822D9C1C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r5,248(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// addi r3,r10,-13088
	ctx.r3.s64 = ctx.r10.s64 + -13088;
	// lwz r6,11724(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// bl 0x82130000
	ctx.lr = 0x822D9C1C;
	sub_82130000(ctx, base);
loc_822D9C1C:
	// bl 0x82305ad8
	ctx.lr = 0x822D9C20;
	sub_82305AD8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32137
	r11.s64 = -2106130432;
	// lwz r4,248(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lis r10,-32210
	ctx.r10.s64 = -2110914560;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r11,-11448
	ctx.r6.s64 = r11.s64 + -11448;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r5,r10,-26296
	ctx.r5.s64 = ctx.r10.s64 + -26296;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822D9C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,-14356(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14356);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822d9c60
	if (!cr6.lt) goto loc_822D9C60;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822D9C60:
	// lbz r9,-14373(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + -14373);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stw r4,-14356(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14356, ctx.r4.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822d9c80
	if (cr6.eq) goto loc_822D9C80;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-13108
	ctx.r3.s64 = r11.s64 + -13108;
	// bl 0x82130000
	ctx.lr = 0x822D9C80;
	sub_82130000(ctx, base);
loc_822D9C80:
	// li r10,5
	ctx.r10.s64 = 5;
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// b 0x822d9d0c
	goto loc_822D9D0C;
	// lwz r5,248(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// rlwinm r10,r11,0,2,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822d9d14
	if (!cr6.eq) goto loc_822D9D14;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r30,-14373(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + -14373);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d9ccc
	if (cr6.eq) goto loc_822D9CCC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-13144
	ctx.r3.s64 = ctx.r10.s64 + -13144;
	// lwz r6,11724(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// bl 0x82130000
	ctx.lr = 0x822D9CCC;
	sub_82130000(ctx, base);
loc_822D9CCC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r29,0
	r29.s64 = 0;
	// lwz r10,-14356(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -14356);
	// addic. r4,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r4.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r4,-14356(r11)
	PPC_STORE_U32(r11.u32 + -14356, ctx.r4.u32);
	// bge 0x822d9cec
	if (!cr0.lt) goto loc_822D9CEC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r4,-14356(r11)
	PPC_STORE_U32(r11.u32 + -14356, ctx.r4.u32);
loc_822D9CEC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822d9d00
	if (cr6.eq) goto loc_822D9D00;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-13108
	ctx.r3.s64 = r11.s64 + -13108;
	// bl 0x82130000
	ctx.lr = 0x822D9D00;
	sub_82130000(ctx, base);
loc_822D9D00:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// stw r29,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r29.u32);
	// stb r29,294(r31)
	PPC_STORE_U8(r31.u32 + 294, r29.u8);
loc_822D9D0C:
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// stw r29,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r29.u32);
loc_822D9D14:
	// lwz r3,-12720(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D9D28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822D9A28) {
	__imp__sub_822D9A28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9D30) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r10,-11836(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -11836);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9d64
	if (cr6.eq) goto loc_822D9D64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// addi r3,r11,-12984
	ctx.r3.s64 = r11.s64 + -12984;
	// bl 0x82130000
	ctx.lr = 0x822D9D64;
	sub_82130000(ctx, base);
loc_822D9D64:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d9d88
	if (!cr6.eq) goto loc_822D9D88;
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_822D9D88:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d9d98
	if (!cr6.eq) goto loc_822D9D98;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x822d9da4
	goto loc_822D9DA4;
loc_822D9D98:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822d9dc0
	if (!cr6.eq) goto loc_822D9DC0;
	// li r10,2
	ctx.r10.s64 = 2;
loc_822D9DA4:
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r10.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r11,1
	r11.s64 = 1;
	// stw r8,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r8.u32);
	// stw r9,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r9.u32);
	// stb r11,294(r31)
	PPC_STORE_U8(r31.u32 + 294, r11.u8);
loc_822D9DC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d9a28
	ctx.lr = 0x822D9DC8;
	sub_822D9A28(ctx, base);
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

PPC_WEAK_FUNC(sub_822D9D30) {
	__imp__sub_822D9D30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9DE0) {
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
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822d9e30
	if (!cr6.eq) goto loc_822D9E30;
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r7,r10,-14368
	ctx.r7.s64 = ctx.r10.s64 + -14368;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,-14372(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -14372);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r9,r6,0,5,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x7FFFFE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// stw r10,-14372(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14372, ctx.r10.u32);
loc_822D9E30:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3636(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3636);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822d9ec0
	if (!cr6.lt) goto loc_822D9EC0;
	// lbz r11,294(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 294);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822d9ec0
	if (!cr6.eq) goto loc_822D9EC0;
	// lhz r11,292(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 292);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d9e70
	if (!cr6.eq) goto loc_822D9E70;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-14432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -14432);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822d9ee8
	if (!cr6.lt) goto loc_822D9EE8;
loc_822D9E70:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3652);
	f0.f64 = double(temp.f32);
	// lfs f13,11364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822d9ee8
	if (cr6.lt) goto loc_822D9EE8;
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822d9ee8
	if (!cr6.eq) goto loc_822D9EE8;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-11835(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -11835);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822d9eb4
	if (cr6.eq) goto loc_822D9EB4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r4,244(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// addi r3,r11,-12956
	ctx.r3.s64 = r11.s64 + -12956;
	// bl 0x82130000
	ctx.lr = 0x822D9EB4;
	sub_82130000(ctx, base);
loc_822D9EB4:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822d9ed8
	goto loc_822D9ED8;
loc_822D9EC0:
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x822d9ed4
	if (cr6.eq) goto loc_822D9ED4;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x822d9ee8
	if (!cr6.eq) goto loc_822D9EE8;
loc_822D9ED4:
	// li r10,4
	ctx.r10.s64 = 4;
loc_822D9ED8:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// stw r9,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r9.u32);
loc_822D9EE8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d9a28
	ctx.lr = 0x822D9EF0;
	sub_822D9A28(ctx, base);
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

PPC_WEAK_FUNC(sub_822D9DE0) {
	__imp__sub_822D9DE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822D9F04) {
	__imp__sub_822D9F04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9F08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lbz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 12);
	// li r11,64
	r11.s64 = 64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822d9f24
	if (!cr6.eq) goto loc_822D9F24;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r5,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r4,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822D9F24:
	// lvx128 v62,r4,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,0
	r11.s64 = 0;
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,12(r4)
	PPC_STORE_U8(ctx.r4.u32 + 12, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822D9F08) {
	__imp__sub_822D9F08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822D9F38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822D9F40;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// bl 0x822e11a0
	ctx.lr = 0x822D9F5C;
	sub_822E11A0(ctx, base);
	// bl 0x822e1b58
	ctx.lr = 0x822D9F60;
	sub_822E1B58(ctx, base);
	// bl 0x822e32e0
	ctx.lr = 0x822D9F64;
	sub_822E32E0(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lbz r10,393(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 393);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822da00c
	if (cr6.eq) goto loc_822DA00C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r26,r31,32
	r26.s64 = r31.s64 + 32;
	// li r25,3
	r25.s64 = 3;
	// lis r27,-32120
	r27.s64 = -2105016320;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_822D9F8C:
	// lhz r30,4(r26)
	r30.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822da000
	if (!cr6.gt) goto loc_822DA000;
	// li r29,0
	r29.s64 = 0;
loc_822D9F9C:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822D9FBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x822d9fd8
	if (cr6.eq) goto loc_822D9FD8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822D9FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822D9FD8:
	// lwz r3,-7572(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -7572);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822f10d0
	ctx.lr = 0x822D9FE4;
	sub_822F10D0(ctx, base);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822D9FF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822d9f9c
	if (!cr0.eq) goto loc_822D9F9C;
loc_822DA000:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r26,r26,12
	r26.s64 = r26.s64 + 12;
	// bne 0x822d9f8c
	if (!cr0.eq) goto loc_822D9F8C;
loc_822DA00C:
	// bl 0x822e1158
	ctx.lr = 0x822DA010;
	sub_822E1158(ctx, base);
	// bl 0x822e19b0
	ctx.lr = 0x822DA014;
	sub_822E19B0(ctx, base);
	// bl 0x822e3148
	ctx.lr = 0x822DA018;
	sub_822E3148(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

PPC_WEAK_FUNC(sub_822D9F38) {
	__imp__sub_822D9F38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA02C) {
	__imp__sub_822DA02C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA030) {
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
	ctx.lr = 0x822DA038;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	r11.s64 = 0;
	// addi r29,r3,36
	r29.s64 = ctx.r3.s64 + 36;
	// li r28,3
	r28.s64 = 3;
	// ori r30,r11,65535
	r30.u64 = r11.u64 | 65535;
loc_822DA04C:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822da0a0
	if (cr6.eq) goto loc_822DA0A0;
	// addi r31,r29,-4
	r31.s64 = r29.s64 + -4;
loc_822DA05C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r7,r8,2,14,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FFFC;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da094
	if (cr6.eq) goto loc_822DA094;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DA094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DA094:
	// lhz r11,0(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822da05c
	if (!cr6.eq) goto loc_822DA05C;
loc_822DA0A0:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// bne 0x822da04c
	if (!cr0.eq) goto loc_822DA04C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822DA030) {
	__imp__sub_822DA030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA0B4) {
	__imp__sub_822DA0B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA0B8) {
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
	ctx.lr = 0x822DA0C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r9,r11,-12528
	ctx.r9.s64 = r11.s64 + -12528;
	// lhz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822da130
	if (cr6.eq) goto loc_822DA130;
	// lis r11,0
	r11.s64 = 0;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// ori r30,r11,65535
	r30.u64 = r11.u64 | 65535;
loc_822DA0EC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r7,r8,2,14,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FFFC;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da124
	if (cr6.eq) goto loc_822DA124;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DA124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DA124:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822da0ec
	if (!cr6.eq) goto loc_822DA0EC;
loc_822DA130:
	// lhz r11,10(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822da144
	if (cr6.eq) goto loc_822DA144;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822DA144;
	sub_82130588(ctx, base);
loc_822DA144:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DA0B8) {
	__imp__sub_822DA0B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA14C) {
	__imp__sub_822DA14C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-11828(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -11828);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DA150) {
	__imp__sub_822DA150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA15C) {
	__imp__sub_822DA15C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA160) {
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
	// bl 0x822da0b8
	ctx.lr = 0x822DA180;
	sub_822DA0B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822da198
	if (cr6.eq) goto loc_822DA198;
	// bl 0x82130588
	ctx.lr = 0x822DA194;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DA198:
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

PPC_WEAK_FUNC(sub_822DA160) {
	__imp__sub_822DA160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA1B0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822DA1B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-12516
	ctx.r10.s64 = r11.s64 + -12516;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// bl 0x822da030
	ctx.lr = 0x822DA1D0;
	sub_822DA030(ctx, base);
	// addi r31,r29,64
	r31.s64 = r29.s64 + 64;
	// li r30,2
	r30.s64 = 2;
loc_822DA1D8:
	// addi r31,r31,-12
	r31.s64 = r31.s64 + -12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822da0b8
	ctx.lr = 0x822DA1E4;
	sub_822DA0B8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822da1d8
	if (!cr0.lt) goto loc_822DA1D8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x822DA1F4;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DA1B0) {
	__imp__sub_822DA1B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA1FC) {
	__imp__sub_822DA1FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-11824(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -11824);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DA200) {
	__imp__sub_822DA200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA20C) {
	__imp__sub_822DA20C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA210) {
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
	ctx.lr = 0x822DA218;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822da030
	ctx.lr = 0x822DA224;
	sub_822DA030(ctx, base);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dbe0
	ctx.lr = 0x822DA234;
	sub_8261DBE0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
	// addi r28,r11,-12400
	r28.s64 = r11.s64 + -12400;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DA258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-12424
	ctx.r4.s64 = ctx.r9.s64 + -12424;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dde8
	ctx.lr = 0x822DA26C;
	sub_8261DDE8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r29,r31,40
	r29.s64 = r31.s64 + 40;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r30,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r30.u32);
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822DA290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-12444
	ctx.r4.s64 = ctx.r4.s64 + -12444;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dde8
	ctx.lr = 0x822DA2A4;
	sub_8261DDE8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r30,r31,52
	r30.s64 = r31.s64 + 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r29,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r29.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822DA2C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-12464
	ctx.r4.s64 = ctx.r7.s64 + -12464;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dde8
	ctx.lr = 0x822DA2DC;
	sub_8261DDE8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r30,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r30.u32);
	// bl 0x822e13a0
	ctx.lr = 0x822DA2F0;
	sub_822E13A0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822e23a8
	ctx.lr = 0x822DA2F8;
	sub_822E23A8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822e3a90
	ctx.lr = 0x822DA300;
	sub_822E3A90(ctx, base);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// addi r3,r4,-7536
	ctx.r3.s64 = ctx.r4.s64 + -7536;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x822da32c
	if (cr6.eq) goto loc_822DA32C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-12492
	ctx.r4.s64 = ctx.r10.s64 + -12492;
	// b 0x822da334
	goto loc_822DA334;
loc_822DA32C:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-12508
	ctx.r4.s64 = ctx.r10.s64 + -12508;
loc_822DA334:
	// bl 0x821ca540
	ctx.lr = 0x822DA338;
	sub_821CA540(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r4,-27856(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// lwz r3,2828(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2828);
	// bl 0x821c04b0
	ctx.lr = 0x822DA35C;
	sub_821C04B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822DA364;
	sub_821C9A90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dca8
	ctx.lr = 0x822DA36C;
	sub_8261DCA8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822DA210) {
	__imp__sub_822DA210(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA374) {
	__imp__sub_822DA374(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA378) {
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
	ctx.lr = 0x822DA38C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da3c0
	if (cr6.eq) goto loc_822DA3C0;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-12528
	ctx.r9.s64 = ctx.r10.s64 + -12528;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822DA3C0:
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

PPC_WEAK_FUNC(sub_822DA378) {
	__imp__sub_822DA378(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA3D4) {
	__imp__sub_822DA3D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA3D8) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,-12516
	ctx.r8.s64 = ctx.r10.s64 + -12516;
	// addi r7,r9,-12528
	ctx.r7.s64 = ctx.r9.s64 + -12528;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r10,r31,28
	ctx.r10.s64 = r31.s64 + 28;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// sth r11,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r11.u16);
	// sth r11,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r11.u16);
	// stw r7,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r7.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// sth r11,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r11.u16);
	// sth r11,50(r31)
	PPC_STORE_U16(r31.u32 + 50, r11.u16);
	// stw r7,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r7.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// sth r11,60(r31)
	PPC_STORE_U16(r31.u32 + 60, r11.u16);
	// sth r11,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r11.u16);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// std r11,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r11.u64);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// bl 0x822e10b0
	ctx.lr = 0x822DA454;
	sub_822E10B0(ctx, base);
	// bl 0x822e18d8
	ctx.lr = 0x822DA458;
	sub_822E18D8(ctx, base);
	// bl 0x822e3208
	ctx.lr = 0x822DA45C;
	sub_822E3208(ctx, base);
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

PPC_WEAK_FUNC(sub_822DA3D8) {
	__imp__sub_822DA3D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA474) {
	__imp__sub_822DA474(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA478) {
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
	// bl 0x822da1b0
	ctx.lr = 0x822DA498;
	sub_822DA1B0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822da4b0
	if (cr6.eq) goto loc_822DA4B0;
	// bl 0x82130588
	ctx.lr = 0x822DA4AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DA4B0:
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

PPC_WEAK_FUNC(sub_822DA478) {
	__imp__sub_822DA478(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA4C8) {
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
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x822DA4DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da4f8
	if (cr6.eq) goto loc_822DA4F8;
	// bl 0x822da3d8
	ctx.lr = 0x822DA4E8;
	sub_822DA3D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822DA4F8:
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

PPC_WEAK_FUNC(sub_822DA4C8) {
	__imp__sub_822DA4C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA50C) {
	__imp__sub_822DA50C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA510) {
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
	// addi r31,r11,-11828
	r31.s64 = r11.s64 + -11828;
	// lwz r11,-11828(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -11828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822da644
	if (!cr6.eq) goto loc_822DA644;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822DA540;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da554
	if (cr6.eq) goto loc_822DA554;
	// bl 0x821d5408
	ctx.lr = 0x822DA550;
	sub_821D5408(ctx, base);
	// b 0x822da558
	goto loc_822DA558;
loc_822DA554:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822DA558:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-12388
	ctx.r7.s64 = ctx.r10.s64 + -12388;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32210
	ctx.r8.s64 = -2110914560;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,-23688
	ctx.r4.s64 = ctx.r8.s64 + -23688;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,3816
	ctx.r9.s64 = ctx.r3.s64 + 3816;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-11720(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11720);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822da5d4
	if (!cr6.eq) goto loc_822DA5D4;
	// bl 0x822e0f60
	ctx.lr = 0x822DA5D0;
	sub_822E0F60(ctx, base);
	// lwz r11,-11720(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11720);
loc_822DA5D4:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,3728
	ctx.r9.s64 = ctx.r10.s64 + 3728;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x822DA5F0;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x822DA600;
	sub_821D4100(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x821d41d0
	ctx.lr = 0x822DA61C;
	sub_821D41D0(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,3764
	ctx.r4.s64 = ctx.r6.s64 + 3764;
	// bl 0x821d4b00
	ctx.lr = 0x822DA62C;
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
	ctx.lr = 0x822DA644;
	sub_821C0548(ctx, base);
loc_822DA644:
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

PPC_WEAK_FUNC(sub_822DA510) {
	__imp__sub_822DA510(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA65C) {
	__imp__sub_822DA65C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA660) {
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
	// addi r31,r11,-11824
	r31.s64 = r11.s64 + -11824;
	// lwz r11,-11824(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -11824);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822da794
	if (!cr6.eq) goto loc_822DA794;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822DA690;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822da6a4
	if (cr6.eq) goto loc_822DA6A4;
	// bl 0x821d5408
	ctx.lr = 0x822DA6A0;
	sub_821D5408(ctx, base);
	// b 0x822da6a8
	goto loc_822DA6A8;
loc_822DA6A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822DA6A8:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-12372
	ctx.r7.s64 = ctx.r10.s64 + -12372;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32210
	ctx.r8.s64 = -2110914560;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,-23352
	ctx.r4.s64 = ctx.r8.s64 + -23352;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,3864
	ctx.r9.s64 = ctx.r3.s64 + 3864;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,28
	ctx.r10.s64 = 28;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-11828(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x822da724
	if (!cr6.eq) goto loc_822DA724;
	// bl 0x822da510
	ctx.lr = 0x822DA720;
	sub_822DA510(ctx, base);
	// lwz r11,-11828(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11828);
loc_822DA724:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,3772
	ctx.r9.s64 = ctx.r10.s64 + 3772;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x822DA740;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x822DA750;
	sub_821D4100(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x821d41d0
	ctx.lr = 0x822DA76C;
	sub_821D41D0(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,3808
	ctx.r4.s64 = ctx.r6.s64 + 3808;
	// bl 0x821d4b00
	ctx.lr = 0x822DA77C;
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
	ctx.lr = 0x822DA794;
	sub_821C0548(ctx, base);
loc_822DA794:
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

PPC_WEAK_FUNC(sub_822DA660) {
	__imp__sub_822DA660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA7AC) {
	__imp__sub_822DA7AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA7B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// lfs f0,31304(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31304);
	f0.f64 = double(temp.f32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stfs f0,44(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DA7B0) {
	__imp__sub_822DA7B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA7E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// stfs f1,44(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f31,f0,f1
	f31.f64 = double(float(f0.f64 / ctx.f1.f64));
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// bl 0x823dbaa8
	ctx.lr = 0x822DA838;
	sub_823DBAA8(ctx, base);
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f31,f13
	ctx.f1.f64 = double(float(f31.f64 * ctx.f13.f64));
	// bl 0x823dba38
	ctx.lr = 0x822DA848;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f1,f11,f31
	ctx.f1.f64 = double(float(ctx.f11.f64 * f31.f64));
	// fsubs f10,f30,f12
	ctx.f10.f64 = double(float(f30.f64 - ctx.f12.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823dbaa8
	ctx.lr = 0x822DA868;
	sub_823DBAA8(ctx, base);
	// lfs f8,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f8,f31
	ctx.f1.f64 = double(float(ctx.f8.f64 * f31.f64));
	// bl 0x823dba38
	ctx.lr = 0x822DA878;
	sub_823DBA38(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// lfs f6,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f5.f64 = double(temp.f32);
	// fdivs f1,f6,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 / ctx.f5.f64));
	// fsubs f4,f30,f7
	ctx.f4.f64 = double(float(f30.f64 - ctx.f7.f64));
	// fctiwz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mullw r8,r9,r30
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r30.s32);
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// bl 0x823dba38
	ctx.lr = 0x822DA8AC;
	sub_823DBA38(ctx, base);
	// frsp f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f1.f64));
	// li r7,48
	ctx.r7.s64 = 48;
	// lfs f1,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// fdivs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 / f0.f64));
	// fctiwz f13,f2
	ctx.f13.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f13,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.f13.u32);
	// bl 0x823dba38
	ctx.lr = 0x822DA8CC;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// li r6,52
	ctx.r6.s64 = 52;
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.f11.u32);
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

PPC_WEAK_FUNC(sub_822DA7E8) {
	__imp__sub_822DA7E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA8FC) {
	__imp__sub_822DA8FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822da934
	if (cr6.lt) goto loc_822DA934;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bgt cr6,0x822da934
	if (cr6.gt) goto loc_822DA934;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x822da934
	if (cr6.lt) goto loc_822DA934;
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// bgt cr6,0x822da934
	if (cr6.gt) goto loc_822DA934;
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// blr 
	return;
loc_822DA934:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DA900) {
	__imp__sub_822DA900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA93C) {
	__imp__sub_822DA93C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,-11808
	ctx.r7.s64 = ctx.r8.s64 + -11808;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,-11808(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11808, ctx.r9.u32);
	// stb r11,-11(r7)
	PPC_STORE_U8(ctx.r7.u32 + -11, r11.u8);
	// stw r10,-4(r7)
	PPC_STORE_U32(ctx.r7.u32 + -4, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DA940) {
	__imp__sub_822DA940(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DA964) {
	__imp__sub_822DA964(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DA968) {
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
	// lis r11,2
	r11.s64 = 131072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// beq cr6,0x822da9b4
	if (cr6.eq) goto loc_822DA9B4;
	// lis r11,4
	r11.s64 = 262144;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// beq cr6,0x822da9b4
	if (cr6.eq) goto loc_822DA9B4;
	// rlwinm r11,r31,0,28,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822da9b4
	if (cr6.eq) goto loc_822DA9B4;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82311450
	ctx.lr = 0x822DA9B4;
	sub_82311450(ctx, base);
loc_822DA9B4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r10,-11820(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -11820);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822da9f8
	if (cr6.eq) goto loc_822DA9F8;
	// rlwinm r11,r31,0,19,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822da9dc
	if (cr6.eq) goto loc_822DA9DC;
	// cmpwi cr6,r31,4096
	cr6.compare<int32_t>(r31.s32, 4096, xer);
	// bne cr6,0x822da9f8
	if (!cr6.eq) goto loc_822DA9F8;
loc_822DA9DC:
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// beq cr6,0x822da9f8
	if (cr6.eq) goto loc_822DA9F8;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// beq cr6,0x822da9f8
	if (cr6.eq) goto loc_822DA9F8;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-13430(r10)
	PPC_STORE_U8(ctx.r10.u32 + -13430, r11.u8);
loc_822DA9F8:
	// rlwinm r11,r31,0,19,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822daa1c
	if (cr6.eq) goto loc_822DAA1C;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823112c0
	ctx.lr = 0x822DAA1C;
	sub_823112C0(ctx, base);
loc_822DAA1C:
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822daa4c
	if (cr6.eq) goto loc_822DAA4C;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822daa4c
	if (cr6.eq) goto loc_822DAA4C;
	// lis r12,282
	r12.s64 = 18481152;
	// ori r12,r12,14846
	r12.u64 = r12.u64 | 14846;
	// and r11,r31,r12
	r11.u64 = r31.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822daa4c
	if (cr6.eq) goto loc_822DAA4C;
	// bl 0x82190890
	ctx.lr = 0x822DAA4C;
	sub_82190890(ctx, base);
loc_822DAA4C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822DAA60;
	sub_8217C088(ctx, base);
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

PPC_WEAK_FUNC(sub_822DA968) {
	__imp__sub_822DA968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAA78) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwinm r11,r3,0,19,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822daaa8
	if (cr6.eq) goto loc_822DAAA8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823112c0
	ctx.lr = 0x822DAAA8;
	sub_823112C0(ctx, base);
loc_822DAAA8:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-13430(r10)
	PPC_STORE_U8(ctx.r10.u32 + -13430, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DAA78) {
	__imp__sub_822DAA78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DAAC4) {
	__imp__sub_822DAAC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAAC8) {
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
	ctx.lr = 0x822DAAD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,24(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dabdc
	if (cr6.eq) goto loc_822DABDC;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dabdc
	if (cr6.eq) goto loc_822DABDC;
	// lis r12,282
	r12.s64 = 18481152;
	// ori r12,r12,14846
	r12.u64 = r12.u64 | 14846;
	// and r11,r31,r12
	r11.u64 = r31.u64 & r12.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dabdc
	if (cr6.eq) goto loc_822DABDC;
	// rlwinm r11,r31,0,19,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822dab68
	if (cr6.eq) goto loc_822DAB68;
	// bl 0x8219ab28
	ctx.lr = 0x822DAB1C;
	sub_8219AB28(ctx, base);
	// lis r29,-32120
	r29.s64 = -2105016320;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822DAB38;
	sub_823112C0(ctx, base);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8219adf0
	ctx.lr = 0x822DAB40;
	sub_8219ADF0(ctx, base);
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822DAB58;
	sub_823112C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822DAB60;
	sub_82190890(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822DAB68:
	// rlwinm r11,r31,0,28,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xC;
	// li r29,-1
	r29.s64 = -1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822dab90
	if (cr6.eq) goto loc_822DAB90;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8233a5a0
	ctx.lr = 0x822DAB80;
	sub_8233A5A0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82311450
	ctx.lr = 0x822DAB8C;
	sub_82311450(ctx, base);
	// b 0x822dabbc
	goto loc_822DABBC;
loc_822DAB90:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x822dabbc
	if (!cr6.eq) goto loc_822DABBC;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822DABAC;
	sub_8217C088(ctx, base);
	// bl 0x82187bf0
	ctx.lr = 0x822DABB0;
	sub_82187BF0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x822d7270
	ctx.lr = 0x822DABB8;
	sub_822D7270(ctx, base);
	// bl 0x82187be0
	ctx.lr = 0x822DABBC;
	sub_82187BE0(ctx, base);
loc_822DABBC:
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8219adf0
	ctx.lr = 0x822DABC4;
	sub_8219ADF0(ctx, base);
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x822dabd4
	if (!cr6.eq) goto loc_822DABD4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82187be0
	ctx.lr = 0x822DABD4;
	sub_82187BE0(ctx, base);
loc_822DABD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822DABDC;
	sub_82190890(ctx, base);
loc_822DABDC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DAAC8) {
	__imp__sub_822DAAC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DABE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DABE4) {
	__imp__sub_822DABE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DABE8) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,3528(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// bl 0x822d5468
	ctx.lr = 0x822DAC10;
	sub_822D5468(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822daac8
	ctx.lr = 0x822DAC1C;
	sub_822DAAC8(ctx, base);
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

PPC_WEAK_FUNC(sub_822DABE8) {
	__imp__sub_822DABE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAC34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DAC34) {
	__imp__sub_822DAC34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAC38) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822DAC54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dac64
	if (cr6.eq) goto loc_822DAC64;
	// bl 0x8219acb0
	ctx.lr = 0x822DAC60;
	sub_8219ACB0(ctx, base);
	// b 0x822dac68
	goto loc_822DAC68;
loc_822DAC64:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822DAC68:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,6144
	ctx.r5.s64 = 6144;
	// li r4,3072
	ctx.r4.s64 = 3072;
	// bl 0x8219ad48
	ctx.lr = 0x822DAC7C;
	sub_8219AD48(ctx, base);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822DAC84;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dac94
	if (cr6.eq) goto loc_822DAC94;
	// bl 0x8219acb0
	ctx.lr = 0x822DAC90;
	sub_8219ACB0(ctx, base);
	// b 0x822dac98
	goto loc_822DAC98;
loc_822DAC94:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822DAC98:
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,1025
	ctx.r4.s64 = 1025;
	// bl 0x8219ad48
	ctx.lr = 0x822DACAC;
	sub_8219AD48(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r11.u8);
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

PPC_WEAK_FUNC(sub_822DAC38) {
	__imp__sub_822DAC38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DACC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,24(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dace4
	if (cr6.eq) goto loc_822DACE4;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dace4
	if (cr6.eq) goto loc_822DACE4;
	// b 0x82190890
	sub_82190890(ctx, base);
	return;
loc_822DACE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82190890
	sub_82190890(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822DACC8) {
	__imp__sub_822DACC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DACEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DACEC) {
	__imp__sub_822DACEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DACF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,24(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dad0c
	if (cr6.eq) goto loc_822DAD0C;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dad0c
	if (cr6.eq) goto loc_822DAD0C;
	// b 0x82190890
	sub_82190890(ctx, base);
	return;
loc_822DAD0C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82190890
	sub_82190890(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822DACF0) {
	__imp__sub_822DACF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAD14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DAD14) {
	__imp__sub_822DAD14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAD18) {
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
	// bl 0x822e6e10
	ctx.lr = 0x822DAD38;
	sub_822E6E10(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// addi r10,r11,-12020
	ctx.r10.s64 = r11.s64 + -12020;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x822DAD50;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_822DAD18) {
	__imp__sub_822DAD18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DAD6C) {
	__imp__sub_822DAD6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAD70) {
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
	// addi r9,r11,-11988
	ctx.r9.s64 = r11.s64 + -11988;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822DADA8;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-14472(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14472, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822DADBC;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822dadd4
	if (cr6.eq) goto loc_822DADD4;
	// bl 0x82130588
	ctx.lr = 0x822DADD0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DADD4:
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

PPC_WEAK_FUNC(sub_822DAD70) {
	__imp__sub_822DAD70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DADEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DADEC) {
	__imp__sub_822DADEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DADF0) {
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
	// bl 0x822e6b38
	ctx.lr = 0x822DAE08;
	sub_822E6B38(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,270
	ctx.r10.s64 = 17694720;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-11988
	ctx.r8.s64 = r11.s64 + -11988;
	// ori r7,r10,32766
	ctx.r7.u64 = ctx.r10.u64 | 32766;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822DAE3C;
	sub_822E5138(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r4,r5,-11964
	ctx.r4.s64 = ctx.r5.s64 + -11964;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r11,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r11.u8);
	// stb r11,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r11.u8);
	// sth r11,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r11.u16);
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

PPC_WEAK_FUNC(sub_822DADF0) {
	__imp__sub_822DADF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAE78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-11944
	ctx.r3.s64 = r11.s64 + -11944;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DAE78) {
	__imp__sub_822DAE78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DAE84) {
	__imp__sub_822DAE84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAE88) {
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
	// addi r10,r11,-11964
	ctx.r10.s64 = r11.s64 + -11964;
	// lwz r30,16(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822daec8
	if (cr6.eq) goto loc_822DAEC8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8219ace0
	ctx.lr = 0x822DAEC0;
	sub_8219ACE0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822DAEC8;
	sub_82130588(ctx, base);
loc_822DAEC8:
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822daee4
	if (cr6.eq) goto loc_822DAEE4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8219ace0
	ctx.lr = 0x822DAEDC;
	sub_8219ACE0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822DAEE4;
	sub_82130588(ctx, base);
loc_822DAEE4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-11988
	ctx.r9.s64 = r11.s64 + -11988;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822DAF00;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-14472(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14472, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822DAF14;
	sub_822E6940(ctx, base);
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

PPC_WEAK_FUNC(sub_822DAE88) {
	__imp__sub_822DAE88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DAF2C) {
	__imp__sub_822DAF2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAF30) {
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
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82130000
	ctx.lr = 0x822DAF54;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e6bc0
	ctx.lr = 0x822DAF5C;
	sub_822E6BC0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822daf74
	if (cr6.eq) goto loc_822DAF74;
	// bl 0x82130588
	ctx.lr = 0x822DAF70;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DAF74:
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

PPC_WEAK_FUNC(sub_822DAF30) {
	__imp__sub_822DAF30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DAF8C) {
	__imp__sub_822DAF8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DAF90) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x822DAF98;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x822d7310
	ctx.lr = 0x822DAFB4;
	sub_822D7310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x822e47d0
	ctx.lr = 0x822DAFC8;
	sub_822E47D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822d8bc0
	ctx.lr = 0x822DAFD4;
	sub_822D8BC0(ctx, base);
	// lis r26,-32120
	r26.s64 = -2105016320;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lwz r31,-7572(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// lbz r11,14546(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db01c
	if (!cr6.eq) goto loc_822DB01C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822DAFF4;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822db014
	if (cr6.gt) goto loc_822DB014;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822DB008;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822db01c
	if (!cr6.lt) goto loc_822DB01C;
loc_822DB014:
	// li r11,1
	r11.s64 = 1;
	// b 0x822db020
	goto loc_822DB020;
loc_822DB01C:
	// li r11,0
	r11.s64 = 0;
loc_822DB020:
	// rlwinm r10,r29,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x2000;
	// clrlwi r24,r11,24
	r24.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822db2c4
	if (!cr6.eq) goto loc_822DB2C4;
	// rlwinm r11,r29,0,17,17
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x4000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822db29c
	if (!cr6.eq) goto loc_822DB29C;
	// lis r12,258
	r12.s64 = 16908288;
	// ori r12,r12,6652
	r12.u64 = r12.u64 | 6652;
	// and r11,r29,r12
	r11.u64 = r29.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db26c
	if (cr6.eq) goto loc_822DB26C;
	// bl 0x821908a8
	ctx.lr = 0x822DB054;
	sub_821908A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822db06c
	if (!cr6.eq) goto loc_822DB06C;
	// rlwinm r11,r29,0,28,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db06c
	if (cr6.eq) goto loc_822DB06C;
	// bl 0x8233a5a0
	ctx.lr = 0x822DB06C;
	sub_8233A5A0(ctx, base);
loc_822DB06C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// clrlwi r25,r30,24
	r25.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db090
	if (cr6.eq) goto loc_822DB090;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB090;
	sub_82190BD8(ctx, base);
loc_822DB090:
	// rlwinm r11,r25,0,27,27
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db1a8
	if (cr6.eq) goto loc_822DB1A8;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// addi r10,r11,-14420
	ctx.r10.s64 = r11.s64 + -14420;
	// lwz r3,-14344(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -14344);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8218f8d0
	ctx.lr = 0x822DB0B4;
	sub_8218F8D0(ctx, base);
	// lis r12,258
	r12.s64 = 16908288;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// ori r12,r12,12
	r12.u64 = r12.u64 | 12;
	// li r27,0
	r27.s64 = 0;
	// and r30,r29,r12
	r30.u64 = r29.u64 & r12.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822db134
	if (cr6.eq) goto loc_822DB134;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822DB0D8;
	sub_82190890(ctx, base);
	// rlwinm r11,r29,0,28,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xC;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db100
	if (cr6.eq) goto loc_822DB100;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x822DB0F4;
	sub_822F7338(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8233a5a0
	ctx.lr = 0x822DB0FC;
	sub_8233A5A0(ctx, base);
	// b 0x822db118
	goto loc_822DB118;
loc_822DB100:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db118
	if (!cr6.eq) goto loc_822DB118;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x822DB118;
	sub_822F7338(ctx, base);
loc_822DB118:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x822DB124;
	sub_822F74F0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x822DB134;
	sub_822F3918(ctx, base);
loc_822DB134:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB148;
	sub_82190BD8(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822db198
	if (cr6.eq) goto loc_822DB198;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x822DB15C;
	sub_822F74F0(ctx, base);
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db178
	if (!cr6.eq) goto loc_822DB178;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822f7338
	ctx.lr = 0x822DB174;
	sub_822F7338(ctx, base);
	// b 0x822db180
	goto loc_822DB180;
loc_822DB178:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822f7480
	ctx.lr = 0x822DB180;
	sub_822F7480(ctx, base);
loc_822DB180:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x822DB190;
	sub_822F3918(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82190890
	ctx.lr = 0x822DB198;
	sub_82190890(ctx, base);
loc_822DB198:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-14344(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -14344);
	// lwz r4,-14408(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -14408);
	// bl 0x8218f8d0
	ctx.lr = 0x822DB1A8;
	sub_8218F8D0(ctx, base);
loc_822DB1A8:
	// rlwinm r11,r29,0,23,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db1d4
	if (cr6.eq) goto loc_822DB1D4;
	// rlwinm r11,r25,0,30,30
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db1d4
	if (cr6.eq) goto loc_822DB1D4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB1D4;
	sub_82190BD8(ctx, base);
loc_822DB1D4:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db2e4
	if (!cr6.eq) goto loc_822DB2E4;
	// rlwinm r11,r29,0,19,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// rlwinm r11,r25,0,28,29
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,-8092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822DB218;
	sub_823112C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x822DB220;
	sub_82190890(ctx, base);
	// rlwinm r11,r25,0,29,29
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x4;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db244
	if (cr6.eq) goto loc_822DB244;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB244;
	sub_82190BD8(ctx, base);
loc_822DB244:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82190890
	ctx.lr = 0x822DB24C;
	sub_82190890(ctx, base);
	// lwz r11,-8092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbz r5,369(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 369);
	// bl 0x823112c0
	ctx.lr = 0x822DB264;
	sub_823112C0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_822DB26C:
	// rlwinm r11,r29,0,11,13
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x1C0000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// lis r11,4
	r11.s64 = 262144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// beq cr6,0x822db2c4
	if (cr6.eq) goto loc_822DB2C4;
	// lis r11,8
	r11.s64 = 524288;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// beq cr6,0x822db2b0
	if (cr6.eq) goto loc_822DB2B0;
	// lis r11,16
	r11.s64 = 1048576;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bne cr6,0x822db2e4
	if (!cr6.eq) goto loc_822DB2E4;
loc_822DB29C:
	// rlwinm r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x822db2d4
	goto loc_822DB2D4;
loc_822DB2B0:
	// rlwinm r11,r30,0,29,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x822db2d4
	goto loc_822DB2D4;
loc_822DB2C4:
	// rlwinm r11,r30,0,30,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db2e4
	if (cr6.eq) goto loc_822DB2E4;
	// li r5,1
	ctx.r5.s64 = 1;
loc_822DB2D4:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82190bd8
	ctx.lr = 0x822DB2E4;
	sub_82190BD8(ctx, base);
loc_822DB2E4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_822DAF90) {
	__imp__sub_822DAF90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DB2EC) {
	__imp__sub_822DB2EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB2F0) {
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
	// addi r10,r11,-12004
	ctx.r10.s64 = r11.s64 + -12004;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e6e68
	ctx.lr = 0x822DB31C;
	sub_822E6E68(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822db334
	if (cr6.eq) goto loc_822DB334;
	// bl 0x82130588
	ctx.lr = 0x822DB330;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DB334:
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

PPC_WEAK_FUNC(sub_822DB2F0) {
	__imp__sub_822DB2F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DB34C) {
	__imp__sub_822DB34C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB350) {
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
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x822DB358;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// rlwinm r11,r23,0,22,22
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x200;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db380
	if (cr6.eq) goto loc_822DB380;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-11816(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11816, r11.u32);
loc_822DB380:
	// rlwinm r11,r23,0,23,27
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db600
	if (cr6.eq) goto loc_822DB600;
	// rlwinm r11,r23,0,26,26
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x20;
	// li r24,1
	r24.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822db3d8
	if (!cr6.eq) goto loc_822DB3D8;
	// rlwinm r11,r23,0,25,25
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x40;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db3b4
	if (cr6.eq) goto loc_822DB3B4;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// b 0x822db3d8
	goto loc_822DB3D8;
loc_822DB3B4:
	// rlwinm r11,r23,0,24,24
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x80;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db3c8
	if (cr6.eq) goto loc_822DB3C8;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x822db3d8
	goto loc_822DB3D8;
loc_822DB3C8:
	// rlwinm r11,r23,0,23,23
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x100;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822db3d8
	if (cr6.eq) goto loc_822DB3D8;
	// li r10,3
	ctx.r10.s64 = 3;
loc_822DB3D8:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r27,r11,-11788
	r27.s64 = r11.s64 + -11788;
	// rlwinm r31,r10,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r27,-16
	r11.s64 = r27.s64 + -16;
	// lwz r10,-8092(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8092);
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r30,444(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 444);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// rlwinm r7,r30,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1000;
	// stwx r8,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r8.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822db5d4
	if (cr6.eq) goto loc_822DB5D4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lfs f0,16(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 16);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r8,r11,-30896
	ctx.r8.s64 = r11.s64 + -30896;
	// lfs f13,20(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f12,24(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// stb r24,228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 228, r24.u8);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r26,16
	r11.s64 = r26.s64 + 16;
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f11,192(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,440(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 440);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8268b2f8
	ctx.lr = 0x822DB468;
	sub_8268B2F8(ctx, base);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lfs f10,28(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 28);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f8,16(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f7,20(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	// lfs f6,24(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 + f31.f64));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f7,84(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f9,92(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822db4f4
	if (cr6.eq) goto loc_822DB4F4;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c148
	ctx.lr = 0x822DB4D0;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822db4f4
	if (!cr6.eq) goto loc_822DB4F4;
	// addi r11,r27,16
	r11.s64 = r27.s64 + 16;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_822DB4F4:
	// lis r30,-32130
	r30.s64 = -2105671680;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lis r6,64
	ctx.r6.s64 = 4194304;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r6,r6,3
	ctx.r6.u64 = ctx.r6.u64 | 3;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// bl 0x82175238
	ctx.lr = 0x822DB514;
	sub_82175238(ctx, base);
	// lis r28,1024
	r28.s64 = 67108864;
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// lis r25,4096
	r25.s64 = 268435456;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// beq cr6,0x822db538
	if (cr6.eq) goto loc_822DB538;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne cr6,0x822db53c
	if (!cr6.eq) goto loc_822DB53C;
loc_822DB538:
	// li r11,0
	r11.s64 = 0;
loc_822DB53C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db564
	if (!cr6.eq) goto loc_822DB564;
	// addi r11,r27,32
	r11.s64 = r27.s64 + 32;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_822DB564:
	// lis r8,64
	ctx.r8.s64 = 4194304;
	// lwz r4,22080(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 22080);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,-17628(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17628);
	// ori r8,r8,3
	ctx.r8.u64 = ctx.r8.u64 | 3;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// bl 0x82174d58
	ctx.lr = 0x822DB584;
	sub_82174D58(ctx, base);
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// beq cr6,0x822db5a0
	if (cr6.eq) goto loc_822DB5A0;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne cr6,0x822db5a4
	if (!cr6.eq) goto loc_822DB5A4;
loc_822DB5A0:
	// li r11,0
	r11.s64 = 0;
loc_822DB5A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822db5cc
	if (!cr6.eq) goto loc_822DB5CC;
	// addi r11,r27,48
	r11.s64 = r27.s64 + 48;
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r10.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_822DB5CC:
	// stb r24,228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 228, r24.u8);
	// b 0x822db5f0
	goto loc_822DB5F0;
loc_822DB5D4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// lvx128 v1,r26,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c148
	ctx.lr = 0x822DB5E8;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822db614
	if (cr6.eq) goto loc_822DB614;
loc_822DB5F0:
	// lwzx r10,r31,r27
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r27.u32);
	// add r11,r31,r27
	r11.u64 = r31.u64 + r27.u64;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stwx r11,r31,r27
	PPC_STORE_U32(r31.u32 + r27.u32, r11.u32);
loc_822DB600:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r6,64(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 64);
	// lbz r5,74(r26)
	ctx.r5.u64 = PPC_LOAD_U8(r26.u32 + 74);
	// lwz r3,12(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// bl 0x822daf90
	ctx.lr = 0x822DB614;
	sub_822DAF90(ctx, base);
loc_822DB614:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_822DB350) {
	__imp__sub_822DB350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB620) {
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
	// bl 0x822e6b80
	ctx.lr = 0x822DB640;
	sub_822E6B80(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,270
	ctx.r9.s64 = 17694720;
	// addi r8,r11,-11988
	ctx.r8.s64 = r11.s64 + -11988;
	// ori r7,r9,32766
	ctx.r7.u64 = ctx.r9.u64 | 32766;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r31,-14472(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14472, r31.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822DB674;
	sub_822E5138(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822e6ae8
	ctx.lr = 0x822DB684;
	sub_822E6AE8(ctx, base);
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

PPC_WEAK_FUNC(sub_822DB620) {
	__imp__sub_822DB620(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB6A0) {
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
	// bl 0x822dae88
	ctx.lr = 0x822DB6C0;
	sub_822DAE88(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822db6d8
	if (cr6.eq) goto loc_822DB6D8;
	// bl 0x82130588
	ctx.lr = 0x822DB6D4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DB6D8:
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

PPC_WEAK_FUNC(sub_822DB6A0) {
	__imp__sub_822DB6A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB6F0) {
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
	// beq cr6,0x822db72c
	if (cr6.eq) goto loc_822DB72C;
	// bl 0x822db620
	ctx.lr = 0x822DB710;
	sub_822DB620(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// oris r8,r9,30
	ctx.r8.u64 = ctx.r9.u64 | 1966080;
	// addi r10,r11,-11964
	ctx.r10.s64 = r11.s64 + -11964;
	// ori r8,r8,4576
	ctx.r8.u64 = ctx.r8.u64 | 4576;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
loc_822DB72C:
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

PPC_WEAK_FUNC(sub_822DB6F0) {
	__imp__sub_822DB6F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB740) {
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
	ctx.lr = 0x822DB748;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x822e6fc8
	ctx.lr = 0x822DB758;
	sub_822E6FC8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// addi r10,r11,-12004
	ctx.r10.s64 = r11.s64 + -12004;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822DB76C;
	sub_821B5A60(ctx, base);
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822db79c
	if (cr6.eq) goto loc_822DB79C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e6e10
	ctx.lr = 0x822DB784;
	sub_822E6E10(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r10,r11,-12020
	ctx.r10.s64 = r11.s64 + -12020;
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x822DB79C;
	sub_82130000(ctx, base);
loc_822DB79C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DB740) {
	__imp__sub_822DB740(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB7A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822db740
	sub_822DB740(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822DB7A8) {
	__imp__sub_822DB7A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB7B4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DB7B4) {
	__imp__sub_822DB7B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,32
	ctx.r6.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r8,80
	ctx.r8.s64 = 80;
	// li r9,160
	ctx.r9.s64 = 160;
	// lvx128 v62,r4,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,192
	ctx.r10.s64 = 192;
	// stvx128 v62,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,240
	r11.s64 = 240;
	// lvx128 v61,r4,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,64(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 64);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f13,68(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lwz r7,72(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	// stw r7,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r7.u32);
	// lwz r6,76(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	// stw r6,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r6.u32);
	// lvx128 v59,r4,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lfs f11,100(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,100(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// lfs f10,104(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,104(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// lfs f9,108(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,108(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// lfs f8,112(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,112(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// lfs f7,116(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,116(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// lfs f6,120(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,120(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// lfs f5,124(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,124(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// lfs f4,128(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,128(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// lfs f3,132(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 132);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,132(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// lfs f2,136(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,136(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// lfs f1,140(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 140);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,140(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// lfs f0,144(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	f0.f64 = double(temp.f32);
	// stfs f0,144(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// lfs f13,148(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,148(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// lfs f12,152(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,152(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// lvx128 v58,r4,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,176(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,176(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// lvx128 v57,r4,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,208(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 208);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,208(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// lfs f9,212(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 212);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,212(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// lfs f8,216(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 216);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,216(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 216, temp.u32);
	// lfs f7,220(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 220);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,220(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// lfs f6,224(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 224);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,224(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// lvx128 v56,r4,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,256(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,256(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 256, temp.u32);
	// lfs f4,260(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 260);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,260(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// lfs f3,264(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 264);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,264(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// lfs f2,268(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,268(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 268, temp.u32);
	// lfs f1,272(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 272);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,272(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// lfs f0,276(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 276);
	f0.f64 = double(temp.f32);
	// stfs f0,276(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// lfs f13,280(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,280(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// lfs f12,284(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 284);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,284(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 284, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DB7B8) {
	__imp__sub_822DB7B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20380(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20380);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DB920) {
	__imp__sub_822DB920(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DB92C) {
	__imp__sub_822DB92C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20384(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20384);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DB930) {
	__imp__sub_822DB930(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DB93C) {
	__imp__sub_822DB93C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20388(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20388);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DB940) {
	__imp__sub_822DB940(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DB94C) {
	__imp__sub_822DB94C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20396(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20396);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DB950) {
	__imp__sub_822DB950(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DB95C) {
	__imp__sub_822DB95C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20392(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20392);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DB960) {
	__imp__sub_822DB960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DB96C) {
	__imp__sub_822DB96C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20400);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DB970) {
	__imp__sub_822DB970(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DB97C) {
	__imp__sub_822DB97C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB980) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-11620
	ctx.r9.s64 = r11.s64 + -11620;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822db9b4
	if (cr6.eq) goto loc_822DB9B4;
	// bl 0x82130588
	ctx.lr = 0x822DB9B0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DB9B4:
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

PPC_WEAK_FUNC(sub_822DB980) {
	__imp__sub_822DB980(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DB9C8) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-11608
	ctx.r9.s64 = r11.s64 + -11608;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822db9fc
	if (cr6.eq) goto loc_822DB9FC;
	// bl 0x82130588
	ctx.lr = 0x822DB9F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DB9FC:
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

PPC_WEAK_FUNC(sub_822DB9C8) {
	__imp__sub_822DB9C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBA10) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-11596
	ctx.r9.s64 = r11.s64 + -11596;
	// addi r8,r10,-11608
	ctx.r8.s64 = ctx.r10.s64 + -11608;
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822dba50
	if (cr6.eq) goto loc_822DBA50;
	// bl 0x82130588
	ctx.lr = 0x822DBA4C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBA50:
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

PPC_WEAK_FUNC(sub_822DBA10) {
	__imp__sub_822DBA10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DBA64) {
	__imp__sub_822DBA64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBA68) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-11584
	ctx.r9.s64 = r11.s64 + -11584;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822dba9c
	if (cr6.eq) goto loc_822DBA9C;
	// bl 0x82130588
	ctx.lr = 0x822DBA98;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBA9C:
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

PPC_WEAK_FUNC(sub_822DBA68) {
	__imp__sub_822DBA68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBAB0) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-11572
	ctx.r9.s64 = r11.s64 + -11572;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x822dbae4
	if (cr6.eq) goto loc_822DBAE4;
	// bl 0x82130588
	ctx.lr = 0x822DBAE0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBAE4:
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

PPC_WEAK_FUNC(sub_822DBAB0) {
	__imp__sub_822DBAB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBAF8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r5,r11,-11560
	ctx.r5.s64 = r11.s64 + -11560;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r3,r10,-11572
	ctx.r3.s64 = ctx.r10.s64 + -11572;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r11,r9,-11584
	r11.s64 = ctx.r9.s64 + -11584;
	// addi r10,r8,-11596
	ctx.r10.s64 = ctx.r8.s64 + -11596;
	// stw r3,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r3.u32);
	// addi r9,r7,-11608
	ctx.r9.s64 = ctx.r7.s64 + -11608;
	// stw r11,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r11.u32);
	// addi r8,r6,-11620
	ctx.r8.s64 = ctx.r6.s64 + -11620;
	// stw r10,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r10.u32);
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// stw r9,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r9.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822dbb6c
	if (cr6.eq) goto loc_822DBB6C;
	// bl 0x82130588
	ctx.lr = 0x822DBB68;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBB6C:
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

PPC_WEAK_FUNC(sub_822DBAF8) {
	__imp__sub_822DBAF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBB80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20496(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20496);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DBB80) {
	__imp__sub_822DBB80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DBB8C) {
	__imp__sub_822DBB8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBB90) {
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
	// bl 0x824973c8
	ctx.lr = 0x822DBBB0;
	sub_824973C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dbbc8
	if (cr6.eq) goto loc_822DBBC8;
	// bl 0x82130588
	ctx.lr = 0x822DBBC4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBBC8:
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

PPC_WEAK_FUNC(sub_822DBB90) {
	__imp__sub_822DBB90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBBE0) {
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
	// addi r10,r11,-11536
	ctx.r10.s64 = r11.s64 + -11536;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x822DBC04;
	sub_82130000(ctx, base);
	// addi r3,r31,572
	ctx.r3.s64 = r31.s64 + 572;
	// bl 0x82495d58
	ctx.lr = 0x822DBC0C;
	sub_82495D58(ctx, base);
	// addi r3,r31,532
	ctx.r3.s64 = r31.s64 + 532;
	// bl 0x82495d58
	ctx.lr = 0x822DBC14;
	sub_82495D58(ctx, base);
	// addi r3,r31,492
	ctx.r3.s64 = r31.s64 + 492;
	// bl 0x82495d58
	ctx.lr = 0x822DBC1C;
	sub_82495D58(ctx, base);
	// addi r3,r31,452
	ctx.r3.s64 = r31.s64 + 452;
	// bl 0x82495d58
	ctx.lr = 0x822DBC24;
	sub_82495D58(ctx, base);
	// addi r3,r31,412
	ctx.r3.s64 = r31.s64 + 412;
	// bl 0x82495d58
	ctx.lr = 0x822DBC2C;
	sub_82495D58(ctx, base);
	// addi r3,r31,372
	ctx.r3.s64 = r31.s64 + 372;
	// bl 0x82495d58
	ctx.lr = 0x822DBC34;
	sub_82495D58(ctx, base);
	// addi r3,r31,332
	ctx.r3.s64 = r31.s64 + 332;
	// bl 0x82495d58
	ctx.lr = 0x822DBC3C;
	sub_82495D58(ctx, base);
	// addi r3,r31,292
	ctx.r3.s64 = r31.s64 + 292;
	// bl 0x82495d58
	ctx.lr = 0x822DBC44;
	sub_82495D58(ctx, base);
	// addi r3,r31,252
	ctx.r3.s64 = r31.s64 + 252;
	// bl 0x82495d58
	ctx.lr = 0x822DBC4C;
	sub_82495D58(ctx, base);
	// addi r3,r31,212
	ctx.r3.s64 = r31.s64 + 212;
	// bl 0x82495d58
	ctx.lr = 0x822DBC54;
	sub_82495D58(ctx, base);
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// bl 0x82495d58
	ctx.lr = 0x822DBC5C;
	sub_82495D58(ctx, base);
	// addi r3,r31,124
	ctx.r3.s64 = r31.s64 + 124;
	// bl 0x82495d58
	ctx.lr = 0x822DBC64;
	sub_82495D58(ctx, base);
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x82495d58
	ctx.lr = 0x822DBC6C;
	sub_82495D58(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x82495d58
	ctx.lr = 0x822DBC74;
	sub_82495D58(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82495d58
	ctx.lr = 0x822DBC7C;
	sub_82495D58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822DBC84;
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

PPC_WEAK_FUNC(sub_822DBBE0) {
	__imp__sub_822DBBE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBC98) {
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
	// bl 0x822dbbe0
	ctx.lr = 0x822DBCB8;
	sub_822DBBE0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dbcd0
	if (cr6.eq) goto loc_822DBCD0;
	// bl 0x82130588
	ctx.lr = 0x822DBCCC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DBCD0:
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

PPC_WEAK_FUNC(sub_822DBC98) {
	__imp__sub_822DBC98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBCE8) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r31,36
	ctx.r4.s64 = r31.s64 + 36;
	// bl 0x821be710
	ctx.lr = 0x822DBD14;
	sub_821BE710(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// bl 0x821be710
	ctx.lr = 0x822DBD24;
	sub_821BE710(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,44
	ctx.r4.s64 = r31.s64 + 44;
	// bl 0x821be710
	ctx.lr = 0x822DBD34;
	sub_821BE710(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,28
	ctx.r4.s64 = r31.s64 + 28;
	// bl 0x821be710
	ctx.lr = 0x822DBD44;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,24
	ctx.r4.s64 = r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be710
	ctx.lr = 0x822DBD54;
	sub_821BE710(ctx, base);
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

PPC_WEAK_FUNC(sub_822DBCE8) {
	__imp__sub_822DBCE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DBD6C) {
	__imp__sub_822DBD6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBD70) {
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
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,4288
	ctx.r4.s64 = r31.s64 + 4288;
	// lwz r3,816(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 816);
	// bl 0x8218aef8
	ctx.lr = 0x822DBD98;
	sub_8218AEF8(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// lwz r3,820(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 820);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,4304
	ctx.r4.s64 = r31.s64 + 4304;
	// bl 0x8218aef8
	ctx.lr = 0x822DBDAC;
	sub_8218AEF8(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,824(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 824);
	// addi r4,r31,4320
	ctx.r4.s64 = r31.s64 + 4320;
	// bl 0x8218aef8
	ctx.lr = 0x822DBDC0;
	sub_8218AEF8(ctx, base);
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

PPC_WEAK_FUNC(sub_822DBD70) {
	__imp__sub_822DBD70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DBDD4) {
	__imp__sub_822DBDD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBDD8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r5,r11,5276
	ctx.r5.s64 = r11.s64 + 5276;
	// addi r4,r10,-11468
	ctx.r4.s64 = ctx.r10.s64 + -11468;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x822DBE14;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822dbe54
	if (cr6.eq) goto loc_822DBE54;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,832
	ctx.r4.s64 = r30.s64 + 832;
	// bl 0x821be710
	ctx.lr = 0x822DBE2C;
	sub_821BE710(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r30,840
	ctx.r4.s64 = r30.s64 + 840;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be710
	ctx.lr = 0x822DBE3C;
	sub_821BE710(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,4168
	ctx.r3.s64 = r11.s64 + 4168;
	// bl 0x822dbce8
	ctx.lr = 0x822DBE4C;
	sub_822DBCE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x822DBE54;
	sub_821BE610(ctx, base);
loc_822DBE54:
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

PPC_WEAK_FUNC(sub_822DBDD8) {
	__imp__sub_822DBDD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DBE6C) {
	__imp__sub_822DBE6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,32
	ctx.r6.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r8,80
	ctx.r8.s64 = 80;
	// li r9,160
	ctx.r9.s64 = 160;
	// lvx128 v62,r4,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,192
	ctx.r10.s64 = 192;
	// stvx128 v62,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,240
	r11.s64 = 240;
	// lvx128 v61,r4,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,64(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 64);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f13,68(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lfs f12,72(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,72(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// lfs f11,76(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,76(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// lvx128 v59,r4,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,96(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,96(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lfs f9,100(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,100(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// lfs f8,104(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,104(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// lfs f7,108(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,108(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// lfs f6,112(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,112(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// lfs f5,116(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,116(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// lfs f4,120(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,120(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// lfs f3,124(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,124(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// lfs f2,128(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,128(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// lfs f1,132(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 132);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,132(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// lfs f0,136(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	f0.f64 = double(temp.f32);
	// stfs f0,136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// lfs f13,140(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,140(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// lfs f12,144(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,144(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// lfs f11,148(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,148(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// lfs f10,152(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 152);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,152(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// lvx128 v58,r4,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,176(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 176);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,176(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// lvx128 v57,r4,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,208(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 208);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,208(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// lfs f7,212(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 212);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,212(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// lfs f6,216(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 216);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,216(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 216, temp.u32);
	// lfs f5,220(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 220);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,220(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// lfs f4,224(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 224);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,224(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// lvx128 v56,r4,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,256(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,256(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 256, temp.u32);
	// lfs f2,260(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 260);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,260(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// lfs f1,264(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 264);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,264(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// lfs f0,268(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 268);
	f0.f64 = double(temp.f32);
	// stfs f0,268(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 268, temp.u32);
	// lfs f13,272(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,272(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// lfs f12,276(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 276);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,276(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// lfs f11,280(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 280);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,280(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// lfs f10,284(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 284);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,284(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 284, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DBE70) {
	__imp__sub_822DBE70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DBFD8) {
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
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822dc024
	if (cr6.eq) goto loc_822DC024;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822DBFFC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822dc024
	if (!cr6.eq) goto loc_822DC024;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822dc024
	if (cr6.eq) goto loc_822DC024;
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
	ctx.lr = 0x822DC024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DC024:
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

PPC_WEAK_FUNC(sub_822DBFD8) {
	__imp__sub_822DBFD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC038) {
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
	// addi r9,r11,-11452
	ctx.r9.s64 = r11.s64 + -11452;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822DC070;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-14468(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14468, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822DC084;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822dc09c
	if (cr6.eq) goto loc_822DC09C;
	// bl 0x82130588
	ctx.lr = 0x822DC098;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DC09C:
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

PPC_WEAK_FUNC(sub_822DC038) {
	__imp__sub_822DC038(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DC0B4) {
	__imp__sub_822DC0B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC0B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lhz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 60);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x822dc0ec
	if (!cr6.gt) goto loc_822DC0EC;
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_822DC0D0:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x822dc164
	if (!cr6.lt) goto loc_822DC164;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822dc0d0
	if (cr6.lt) goto loc_822DC0D0;
loc_822DC0EC:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_822DC100:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,-4(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,-16(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,-12(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,-8(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822DC164:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x822dc100
	goto loc_822DC100;
}

PPC_WEAK_FUNC(sub_822DC0B8) {
	__imp__sub_822DC0B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC178) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lhz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 60);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x822dc1ac
	if (!cr6.gt) goto loc_822DC1AC;
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_822DC190:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x822dc224
	if (!cr6.lt) goto loc_822DC224;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822dc190
	if (cr6.lt) goto loc_822DC190;
loc_822DC1AC:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_822DC1C0:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,-4(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,-16(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,-12(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,-8(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822DC224:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x822dc1c0
	goto loc_822DC1C0;
}

PPC_WEAK_FUNC(sub_822DC178) {
	__imp__sub_822DC178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC238) {
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
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x82495d58
	ctx.lr = 0x822DC25C;
	sub_82495D58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822DC264;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dc27c
	if (cr6.eq) goto loc_822DC27C;
	// bl 0x82130588
	ctx.lr = 0x822DC278;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DC27C:
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

PPC_WEAK_FUNC(sub_822DC238) {
	__imp__sub_822DC238(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DC294) {
	__imp__sub_822DC294(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC298) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822DC2A0;
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
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r5,r11,-11428
	ctx.r5.s64 = r11.s64 + -11428;
	// addi r3,r10,-11560
	ctx.r3.s64 = ctx.r10.s64 + -11560;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r11,r9,-11572
	r11.s64 = ctx.r9.s64 + -11572;
	// stw r3,3840(r31)
	PPC_STORE_U32(r31.u32 + 3840, ctx.r3.u32);
	// addi r10,r8,-11584
	ctx.r10.s64 = ctx.r8.s64 + -11584;
	// addi r9,r7,-11596
	ctx.r9.s64 = ctx.r7.s64 + -11596;
	// stw r11,4096(r31)
	PPC_STORE_U32(r31.u32 + 4096, r11.u32);
	// addi r8,r6,-11608
	ctx.r8.s64 = ctx.r6.s64 + -11608;
	// stw r10,4080(r31)
	PPC_STORE_U32(r31.u32 + 4080, ctx.r10.u32);
	// addi r7,r4,-11620
	ctx.r7.s64 = ctx.r4.s64 + -11620;
	// stw r9,3952(r31)
	PPC_STORE_U32(r31.u32 + 3952, ctx.r9.u32);
	// stw r8,4048(r31)
	PPC_STORE_U32(r31.u32 + 4048, ctx.r8.u32);
	// addi r30,r31,3840
	r30.s64 = r31.s64 + 3840;
	// stw r7,3856(r31)
	PPC_STORE_U32(r31.u32 + 3856, ctx.r7.u32);
	// li r29,3
	r29.s64 = 3;
loc_822DC304:
	// addi r30,r30,-80
	r30.s64 = r30.s64 + -80;
	// addi r3,r30,32
	ctx.r3.s64 = r30.s64 + 32;
	// bl 0x82495d58
	ctx.lr = 0x822DC310;
	sub_82495D58(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x822DC318;
	sub_821D2028(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x822dc304
	if (!cr0.lt) goto loc_822DC304;
	// addi r30,r31,3520
	r30.s64 = r31.s64 + 3520;
	// li r29,3
	r29.s64 = 3;
loc_822DC328:
	// addi r30,r30,-656
	r30.s64 = r30.s64 + -656;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822dbbe0
	ctx.lr = 0x822DC334;
	sub_822DBBE0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x822dc328
	if (!cr0.lt) goto loc_822DC328;
	// addi r3,r31,848
	ctx.r3.s64 = r31.s64 + 848;
	// bl 0x824973c8
	ctx.lr = 0x822DC344;
	sub_824973C8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82495150
	ctx.lr = 0x822DC34C;
	sub_82495150(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-11452
	ctx.r9.s64 = r11.s64 + -11452;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822DC368;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-14468(r8)
	PPC_STORE_U32(ctx.r8.u32 + -14468, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822DC37C;
	sub_822E6940(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DC298) {
	__imp__sub_822DC298(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DC384) {
	__imp__sub_822DC384(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC388) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x822DC390;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// addi r10,r11,-7536
	ctx.r10.s64 = r11.s64 + -7536;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r20,r11,30576
	r20.s64 = r11.s64 + 30576;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// beq cr6,0x822dc3c4
	if (cr6.eq) goto loc_822DC3C4;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-11340
	ctx.r4.s64 = ctx.r10.s64 + -11340;
	// b 0x822dc3cc
	goto loc_822DC3CC;
loc_822DC3C4:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-11352
	ctx.r4.s64 = ctx.r10.s64 + -11352;
loc_822DC3CC:
	// bl 0x821ca540
	ctx.lr = 0x822DC3D0;
	sub_821CA540(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x822dbdd8
	ctx.lr = 0x822DC3D8;
	sub_822DBDD8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r21,16
	ctx.r3.s64 = r21.s64 + 16;
	// addi r4,r11,-11360
	ctx.r4.s64 = r11.s64 + -11360;
	// bl 0x82493208
	ctx.lr = 0x822DC3E8;
	sub_82493208(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r22,r11,6912
	r22.s64 = r11.s64 + 6912;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r29,r21,3520
	r29.s64 = r21.s64 + 3520;
	// addi r31,r21,1524
	r31.s64 = r21.s64 + 1524;
	// mr r30,r22
	r30.u64 = r22.u64;
	// lis r23,-32125
	r23.s64 = -2105344000;
	// addi r28,r9,-11516
	r28.s64 = ctx.r9.s64 + -11516;
	// addi r27,r8,-11496
	r27.s64 = ctx.r8.s64 + -11496;
	// addi r26,r7,-11480
	r26.s64 = ctx.r7.s64 + -11480;
	// addi r25,r10,5276
	r25.s64 = ctx.r10.s64 + 5276;
	// addi r24,r11,-11376
	r24.s64 = r11.s64 + -11376;
loc_822DC428:
	// li r5,1024
	ctx.r5.s64 = 1024;
	// lwz r19,0(r30)
	r19.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dbe0
	ctx.lr = 0x822DC43C;
	sub_8261DBE0(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,-628
	ctx.r3.s64 = r31.s64 + -628;
	// bl 0x82497d80
	ctx.lr = 0x822DC448;
	sub_82497D80(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r7,7
	ctx.r7.s64 = 7;
	// addi r6,r31,-4
	ctx.r6.s64 = r31.s64 + -4;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dea0
	ctx.lr = 0x822DC460;
	sub_8261DEA0(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r7,7
	ctx.r7.s64 = 7;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dea0
	ctx.lr = 0x822DC478;
	sub_8261DEA0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r7,9
	ctx.r7.s64 = 9;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261df58
	ctx.lr = 0x822DC490;
	sub_8261DF58(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,2828(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 2828);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// bl 0x821c04b0
	ctx.lr = 0x822DC4AC;
	sub_821C04B0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dca8
	ctx.lr = 0x822DC4B4;
	sub_8261DCA8(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x822DC4C8;
	sub_82137A08(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824981d8
	ctx.lr = 0x822DC4D4;
	sub_824981D8(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r11,r22,16
	r11.s64 = r22.s64 + 16;
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// addi r31,r31,656
	r31.s64 = r31.s64 + 656;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822dc428
	if (cr6.lt) goto loc_822DC428;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r21,848
	ctx.r3.s64 = r21.s64 + 848;
	// addi r4,r11,-11392
	ctx.r4.s64 = r11.s64 + -11392;
	// bl 0x82498258
	ctx.lr = 0x822DC4FC;
	sub_82498258(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r21,3840
	ctx.r3.s64 = r21.s64 + 3840;
	// addi r4,r10,-11408
	ctx.r4.s64 = ctx.r10.s64 + -11408;
	// bl 0x82492918
	ctx.lr = 0x822DC50C;
	sub_82492918(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822DC514;
	sub_821C9A90(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_822DC388) {
	__imp__sub_822DC388(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DC51C) {
	__imp__sub_822DC51C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC520) {
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
	ctx.lr = 0x822DC528;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-2496(r1)
	ea = -2496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,72
	r26.s64 = 72;
	// lis r25,-32130
	r25.s64 = -2105671680;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lis r24,-32119
	r24.s64 = -2104950784;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// lbzx r9,r26,r27
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// lwz r7,22080(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 22080);
	// lwz r8,-17936(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + -17936);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// bne cr6,0x822dc56c
	if (!cr6.eq) goto loc_822DC56C;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_822DC56C:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// rlwinm r6,r11,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r29,r10,6928
	r29.s64 = ctx.r10.s64 + 6928;
	// li r11,1
	r11.s64 = 1;
	// lfsx f31,r6,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r29.u32);
	f31.f64 = double(temp.f32);
loc_822DC580:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// bne cr6,0x822dc590
	if (!cr6.eq) goto loc_822DC590;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_822DC590:
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// lfsx f0,r6,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r29.u32);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	f31.f64 = double(float(f0.f64 + f31.f64));
	// blt cr6,0x822dc580
	if (cr6.lt) goto loc_822DC580;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bne cr6,0x822dc5c8
	if (!cr6.eq) goto loc_822DC5C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f31.f64 = double(temp.f32);
loc_822DC5C8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82491158
	ctx.lr = 0x822DC5D0;
	sub_82491158(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r23,896
	r30.s64 = r23.s64 + 896;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f31,f0,f31
	f31.f64 = double(float(f0.f64 / f31.f64));
loc_822DC5E4:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824976a8
	ctx.lr = 0x822DC5F4;
	sub_824976A8(ctx, base);
	// lbzx r11,r26,r27
	r11.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dc608
	if (cr6.eq) goto loc_822DC608;
	// lwz r11,22080(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 22080);
	// b 0x822dc60c
	goto loc_822DC60C;
loc_822DC608:
	// lwz r11,-17936(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -17936);
loc_822DC60C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// bl 0x824921a8
	ctx.lr = 0x822DC628;
	sub_824921A8(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82493410
	ctx.lr = 0x822DC634;
	sub_82493410(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,656
	r30.s64 = r30.s64 + 656;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x822dc5e4
	if (cr6.lt) goto loc_822DC5E4;
	// addi r5,r1,384
	ctx.r5.s64 = ctx.r1.s64 + 384;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r3,r23,3840
	ctx.r3.s64 = r23.s64 + 3840;
	// bl 0x82491aa0
	ctx.lr = 0x822DC654;
	sub_82491AA0(ctx, base);
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// addi r3,r1,960
	ctx.r3.s64 = ctx.r1.s64 + 960;
	// bl 0x822dbe70
	ctx.lr = 0x822DC660;
	sub_822DBE70(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,1824
	ctx.r3.s64 = ctx.r1.s64 + 1824;
	// bl 0x822dbe70
	ctx.lr = 0x822DC670;
	sub_822DBE70(ctx, base);
	// lfs f0,4192(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 4192);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,1248
	ctx.r3.s64 = ctx.r1.s64 + 1248;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// bl 0x82493458
	ctx.lr = 0x822DC690;
	sub_82493458(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,1536
	ctx.r3.s64 = ctx.r1.s64 + 1536;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82491230
	ctx.lr = 0x822DC6A0;
	sub_82491230(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,2112
	ctx.r3.s64 = ctx.r1.s64 + 2112;
	// bl 0x824921f8
	ctx.lr = 0x822DC6B0;
	sub_824921F8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,672
	ctx.r3.s64 = ctx.r1.s64 + 672;
	// bl 0x822dbe70
	ctx.lr = 0x822DC6BC;
	sub_822DBE70(ctx, base);
	// addi r4,r1,672
	ctx.r4.s64 = ctx.r1.s64 + 672;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822db7b8
	ctx.lr = 0x822DC6C8;
	sub_822DB7B8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,2496
	ctx.r1.s64 = ctx.r1.s64 + 2496;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_822DC520) {
	__imp__sub_822DC520(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DC6DC) {
	__imp__sub_822DC6DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC6E0) {
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
	// bl 0x822e6b80
	ctx.lr = 0x822DC700;
	sub_822E6B80(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// addi r8,r11,-11452
	ctx.r8.s64 = r11.s64 + -11452;
	// ori r7,r9,3
	ctx.r7.u64 = ctx.r9.u64 | 3;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r31,-14468(r10)
	PPC_STORE_U32(ctx.r10.u32 + -14468, r31.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822DC734;
	sub_822E5138(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822e6ae8
	ctx.lr = 0x822DC744;
	sub_822E6AE8(ctx, base);
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

PPC_WEAK_FUNC(sub_822DC6E0) {
	__imp__sub_822DC6E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC760) {
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
	ctx.lr = 0x822DC768;
	// stwu r1,-1712(r1)
	ea = -1712 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// sth r28,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, r28.u16);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// sth r28,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r28.u16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821e5fd0
	ctx.lr = 0x822DC79C;
	sub_821E5FD0(ctx, base);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// li r29,60
	r29.s64 = 60;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// stb r28,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r28.u8);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822dc808
	if (cr6.eq) goto loc_822DC808;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x826122b0
	ctx.lr = 0x822DC7EC;
	sub_826122B0(ctx, base);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
loc_822DC808:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r10,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822DC760) {
	__imp__sub_822DC760(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC81C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DC81C) {
	__imp__sub_822DC81C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DC820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f28{};
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
	ctx.lr = 0x822DC838;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f13,-11292(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11292);
	ctx.f13.f64 = double(temp.f32);
	// lis r31,-32252
	r31.s64 = -2113667072;
	// stfs f13,-112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// addi r8,r1,-96
	ctx.r8.s64 = ctx.r1.s64 + -96;
	// lfs f13,28628(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28628);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f12,-11296(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11296);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r1,-80
	r11.s64 = ctx.r1.s64 + -80;
	// stfs f12,-108(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,-26236(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -26236);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f12,-76(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stfs f13,-88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// lis r30,-32252
	r30.s64 = -2113667072;
	// lfs f13,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r7,-11620
	ctx.r7.s64 = ctx.r7.s64 + -11620;
	// lfs f12,-11300(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -11300);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// stfs f12,-72(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// lis r31,-32254
	r31.s64 = -2113798144;
	// stfs f13,-80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// addi r5,r4,-11584
	ctx.r5.s64 = ctx.r4.s64 + -11584;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// lfs f11,-11304(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11304);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r10,r10,-11560
	ctx.r10.s64 = ctx.r10.s64 + -11560;
	// stfs f11,-92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// addi r6,r6,-11596
	ctx.r6.s64 = ctx.r6.s64 + -11596;
	// stfs f0,-104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// addi r7,r30,-11608
	ctx.r7.s64 = r30.s64 + -11608;
	// stw r6,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r6.u32);
	// addi r10,r10,-11572
	ctx.r10.s64 = ctx.r10.s64 + -11572;
	// stw r7,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r7.u32);
	// stfs f0,-96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// stw r5,240(r3)
	PPC_STORE_U32(ctx.r3.u32 + 240, ctx.r5.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 256, ctx.r10.u32);
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f9,15004(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 15004);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,-92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,64
	ctx.r8.s64 = 64;
	// stvx128 v63,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// li r9,320
	ctx.r9.s64 = 320;
	// lfs f10,-11308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11308);
	ctx.f10.f64 = double(temp.f32);
	// li r7,128
	ctx.r7.s64 = 128;
	// lfs f11,31308(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31308);
	ctx.f11.f64 = double(temp.f32);
	// li r5,144
	ctx.r5.s64 = 144;
	// lfs f8,-6176(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6176);
	ctx.f8.f64 = double(temp.f32);
	// li r31,0
	r31.s64 = 0;
	// stvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,-88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// stfs f10,-96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// stfs f11,-80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// stfs f12,-76(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stfs f13,-72(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// stfs f12,-112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// stfs f12,-108(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// stfs f12,-104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// stfs f9,80(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f8,84(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// addi r8,r1,-96
	ctx.r8.s64 = ctx.r1.s64 + -96;
	// lfs f10,32680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	ctx.f10.f64 = double(temp.f32);
	// addi r6,r1,-80
	ctx.r6.s64 = ctx.r1.s64 + -80;
	// stfs f10,88(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f13,92(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// stfs f13,96(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r30,-32256
	r30.s64 = -2113929216;
	// stvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f9,-12084(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -12084);
	ctx.f9.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f8,-11312(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11312);
	ctx.f8.f64 = double(temp.f32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lfs f7,-32032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -32032);
	ctx.f7.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f6,31296(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 31296);
	ctx.f6.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f5,-11316(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -11316);
	ctx.f5.f64 = double(temp.f32);
	// lis r30,-32256
	r30.s64 = -2113929216;
	// lfs f4,15000(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15000);
	ctx.f4.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r1,-112
	ctx.r7.s64 = ctx.r1.s64 + -112;
	// lfs f3,-6172(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -6172);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,30712(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// stw r31,296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 296, r31.u32);
	// lfs f1,3732(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
	// lfs f30,-26504(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -26504);
	f30.f64 = double(temp.f32);
	// lfs f29,31016(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 31016);
	f29.f64 = double(temp.f32);
	// lfs f28,12428(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12428);
	f28.f64 = double(temp.f32);
	// lvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f9,160(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// stfs f8,164(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// stfs f7,168(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 168, temp.u32);
	// stfs f6,172(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 172, temp.u32);
	// stfs f0,176(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// stfs f12,180(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 180, temp.u32);
	// stfs f5,184(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 184, temp.u32);
	// stfs f4,192(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// stfs f3,196(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// stfs f9,212(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// stfs f2,216(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 216, temp.u32);
	// stfs f10,220(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// stfs f1,224(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// stfs f31,188(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 188, temp.u32);
	// stfs f0,200(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// stfs f30,204(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// stfs f29,272(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// stfs f0,280(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 280, temp.u32);
	// stfs f13,244(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 244, temp.u32);
	// stfs f13,248(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 248, temp.u32);
	// stfs f28,288(r3)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// stfs f0,292(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// stvx128 v58,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,336(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 336, temp.u32);
	// stfs f13,284(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 284, temp.u32);
	// stfs f13,276(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// stfs f0,340(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 340, temp.u32);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x822DCA8C;
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

PPC_WEAK_FUNC(sub_822DC820) {
	__imp__sub_822DC820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DCAA0) {
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
	// bl 0x822dc298
	ctx.lr = 0x822DCAC0;
	sub_822DC298(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dcad8
	if (cr6.eq) goto loc_822DCAD8;
	// bl 0x82130588
	ctx.lr = 0x822DCAD4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DCAD8:
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

PPC_WEAK_FUNC(sub_822DCAA0) {
	__imp__sub_822DCAA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DCAF0) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x822DCAF8;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9d4
	ctx.lr = 0x822DCB00;
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822dcb34
	if (cr6.eq) goto loc_822DCB34;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822dcb38
	if (cr6.eq) goto loc_822DCB38;
loc_822DCB34:
	// li r11,0
	r11.s64 = 0;
loc_822DCB38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822dcb84
	if (!cr6.eq) goto loc_822DCB84;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,828(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 828);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,832(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 832);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,29504(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29504);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmadds f0,f11,f0,f12
	f0.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// stfs f0,828(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 828, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822dcb84
	if (!cr6.gt) goto loc_822DCB84;
	// lwz r11,836(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 836);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,828(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 828, temp.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r11.u32);
loc_822DCB84:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lfs f27,-7600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -7600);
	f27.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x822dc520
	ctx.lr = 0x822DCB9C;
	sub_822DC520(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// stb r10,576(r31)
	PPC_STORE_U8(r31.u32 + 576, ctx.r10.u8);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// addi r3,r11,256
	ctx.r3.s64 = r11.s64 + 256;
	// bl 0x822db7b8
	ctx.lr = 0x822DCBB8;
	sub_822DB7B8(ctx, base);
	// addi r29,r30,576
	r29.s64 = r30.s64 + 576;
	// lfs f1,388(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824984b8
	ctx.lr = 0x822DCBC8;
	sub_824984B8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,308(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824984c8
	ctx.lr = 0x822DCBD4;
	sub_824984C8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 180);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824984d8
	ctx.lr = 0x822DCBE0;
	sub_824984D8(ctx, base);
	// lbz r9,844(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 844);
	// li r22,160
	r22.s64 = 160;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822dcc08
	if (cr6.eq) goto loc_822DCC08;
	// addi r4,r31,848
	ctx.r4.s64 = r31.s64 + 848;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82497610
	ctx.lr = 0x822DCC00;
	sub_82497610(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822DCC08:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,836(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 836);
	// lfs f1,828(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 828);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824920c8
	ctx.lr = 0x822DCC18;
	sub_824920C8(ctx, base);
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,72
	r27.s64 = 72;
	// lis r26,-32130
	r26.s64 = -2105671680;
	// lis r23,-32119
	r23.s64 = -2104950784;
	// lbzx r6,r27,r28
	ctx.r6.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// lwz r7,22080(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 22080);
	// lwz r8,-17936(r23)
	ctx.r8.u64 = PPC_LOAD_U32(r23.u32 + -17936);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// bne cr6,0x822dcc44
	if (!cr6.eq) goto loc_822DCC44;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_822DCC44:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r10,6976
	ctx.r4.s64 = ctx.r10.s64 + 6976;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,1520
	ctx.r10.s64 = r31.s64 + 1520;
	// lfsx f0,r9,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f30,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lfs f31,7444(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fmr f10,f30
	ctx.f10.f64 = f30.f64;
	// fdivs f28,f31,f0
	f28.f64 = double(float(f31.f64 / f0.f64));
	// addi r24,r9,6928
	r24.s64 = ctx.r9.s64 + 6928;
loc_822DCC7C:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// bne cr6,0x822dcc8c
	if (!cr6.eq) goto loc_822DCC8C;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_822DCC8C:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r10,656
	ctx.r10.s64 = ctx.r10.s64 + 656;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// lfsx f13,r5,r24
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r24.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 * f28.f64));
	// fmadds f10,f12,f0,f10
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f10.f64));
	// blt cr6,0x822dcc7c
	if (cr6.lt) goto loc_822DCC7C;
	// fmr f11,f30
	ctx.f11.f64 = f30.f64;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,1524
	ctx.r10.s64 = r31.s64 + 1524;
loc_822DCCC4:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// bne cr6,0x822dccd4
	if (!cr6.eq) goto loc_822DCCD4;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_822DCCD4:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r10,656
	ctx.r10.s64 = ctx.r10.s64 + 656;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// lfsx f13,r5,r24
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r24.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 * f28.f64));
	// fmadds f11,f12,f0,f11
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f11.f64));
	// blt cr6,0x822dccc4
	if (cr6.lt) goto loc_822DCCC4;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f13,f30
	ctx.f13.f64 = f30.f64;
	// addi r11,r31,1540
	r11.s64 = r31.s64 + 1540;
	// fmr f12,f30
	ctx.f12.f64 = f30.f64;
loc_822DCD14:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// bne cr6,0x822dcd24
	if (!cr6.eq) goto loc_822DCD24;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_822DCD24:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f9,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f7,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,656
	r11.s64 = r11.s64 + 656;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// lfsx f6,r5,r24
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r24.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f28
	ctx.f5.f64 = double(float(ctx.f6.f64 * f28.f64));
	// fmadds f0,f9,f5,f0
	f0.f64 = double(float(ctx.f9.f64 * ctx.f5.f64 + f0.f64));
	// fmadds f13,f5,f8,f13
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f8.f64 + ctx.f13.f64));
	// fmadds f12,f7,f5,f12
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f5.f64 + ctx.f12.f64));
	// blt cr6,0x822dcd14
	if (cr6.lt) goto loc_822DCD14;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r10,96
	ctx.r10.s64 = 96;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// stfs f10,80(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f11,84(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dcf10
	if (cr6.eq) goto loc_822DCF10;
	// li r10,384
	ctx.r10.s64 = 384;
	// lfs f0,460(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 460);
	f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r8,368
	ctx.r8.s64 = 368;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,208
	ctx.r6.s64 = 208;
	// lvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,192
	ctx.r5.s64 = 192;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,400
	ctx.r4.s64 = 400;
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,224
	ctx.r3.s64 = 224;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r10,448
	ctx.r10.s64 = 448;
	// stvx128 v60,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,240
	ctx.r9.s64 = 240;
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,416
	ctx.r8.s64 = 416;
	// stvx128 v59,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,256
	ctx.r7.s64 = 256;
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lvx128 v58,r11,r4
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,840(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 840);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 - ctx.f11.f64));
	// stfs f10,236(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 236, temp.u32);
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// lvx128 v57,r11,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// lvx128 v56,r11,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// lwz r5,68(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// stw r5,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r5.u32);
	// lwz r29,-7572(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + -7572);
	// lbz r4,14546(r29)
	ctx.r4.u64 = PPC_LOAD_U8(r29.u32 + 14546);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822dce6c
	if (!cr6.eq) goto loc_822DCE6C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822DCE44;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822dce64
	if (cr6.gt) goto loc_822DCE64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822DCE58;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822dce6c
	if (!cr6.lt) goto loc_822DCE6C;
loc_822DCE64:
	// li r11,1
	r11.s64 = 1;
	// b 0x822dce70
	goto loc_822DCE70;
loc_822DCE6C:
	// li r11,0
	r11.s64 = 0;
loc_822DCE70:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dce84
	if (cr6.eq) goto loc_822DCE84;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x822dce88
	goto loc_822DCE88;
loc_822DCE84:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_822DCE88:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v55,r31,r22
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,368
	ctx.r6.s64 = ctx.r1.s64 + 368;
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,1632
	ctx.r3.s64 = 1632;
	// lfs f0,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// li r10,1648
	ctx.r10.s64 = 1648;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r9,1664
	ctx.r9.s64 = 1664;
	// lfs f13,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,1680
	ctx.r8.s64 = 1680;
	// lfs f12,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// lvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// lvx128 v52,r0,r5
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// lvx128 v51,r0,r4
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822DCF10:
	// stfs f30,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stfs f30,116(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lbzx r25,r27,r28
	r25.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// lwz r27,22080(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 22080);
	// stfs f30,120(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwz r26,-17936(r23)
	r26.u64 = PPC_LOAD_U32(r23.u32 + -17936);
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,3520
	r30.s64 = r31.s64 + 3520;
	// fmr f29,f30
	f29.f64 = f30.f64;
	// li r28,16
	r28.s64 = 16;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822DCF40:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// bne cr6,0x822dcf50
	if (!cr6.eq) goto loc_822DCF50;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_822DCF50:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v50,r30,r28
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfsx f0,r7,r24
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r24.u32);
	f0.f64 = double(temp.f32);
	// fmuls f31,f0,f28
	f31.f64 = double(float(f0.f64 * f28.f64));
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v49,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vmaddfp128 v127,v50,v48,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v48.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822dc0b8
	ctx.lr = 0x822DCF90;
	sub_822DC0B8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmadds f30,f1,f31,f30
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64 * f31.f64 + f30.f64));
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x822dc178
	ctx.lr = 0x822DCFA0;
	sub_822DC178(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// fmadds f29,f1,f31,f29
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64 * f31.f64 + f29.f64));
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x822dcf40
	if (cr6.lt) goto loc_822DCF40;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v47,r31,r22
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r31,4208
	ctx.r8.s64 = r31.s64 + 4208;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82491530
	ctx.lr = 0x822DCFDC;
	sub_82491530(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,4208(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4208);
	f0.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f13,4224(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4224);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4240(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4240);
	ctx.f12.f64 = double(temp.f32);
	// li r9,4288
	ctx.r9.s64 = 4288;
	// lfs f11,4256(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4256);
	ctx.f11.f64 = double(temp.f32);
	// li r7,4304
	ctx.r7.s64 = 4304;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r5,4320
	ctx.r5.s64 = 4320;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,4212(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4212);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4228(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4228);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4244(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4244);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,4260(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4260);
	ctx.f7.f64 = double(temp.f32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f8,88(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f7,92(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v45,r0,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,4216(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4216);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4232(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4232);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,4248(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4248);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,4264(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4264);
	ctx.f3.f64 = double(temp.f32);
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f5,84(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f4,88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f3,92(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v44,r0,r6
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba20
	ctx.lr = 0x822DD080;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_822DCAF0) {
	__imp__sub_822DCAF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DD084) {
	__imp__sub_822DD084(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD088) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822DD090;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,33(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 33);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822dd300
	if (!cr6.eq) goto loc_822DD300;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// bl 0x82178f38
	ctx.lr = 0x822DD0B8;
	sub_82178F38(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x822dd114
	if (cr6.eq) goto loc_822DD114;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822dd0e0
	if (cr6.eq) goto loc_822DD0E0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821796d8
	ctx.lr = 0x822DD0D8;
	sub_821796D8(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x821796d8
	ctx.lr = 0x822DD0E0;
	sub_821796D8(ctx, base);
loc_822DD0E0:
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x821796b0
	ctx.lr = 0x822DD0E8;
	sub_821796B0(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x821796b0
	ctx.lr = 0x822DD0F4;
	sub_821796B0(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dd308
	if (cr6.eq) goto loc_822DD308;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dd308
	if (cr6.eq) goto loc_822DD308;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_822DD114:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82179720
	ctx.lr = 0x822DD12C;
	sub_82179720(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822dd140
	if (cr6.eq) goto loc_822DD140;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_822DD140:
	// lbz r11,32(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822dd1e0
	if (!cr6.eq) goto loc_822DD1E0;
	// li r11,16
	r11.s64 = 16;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822DD160;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,16
	ctx.r3.s64 = 16;
	// std r10,180(r1)
	PPC_STORE_U64(ctx.r1.u32 + 180, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x822DD178;
	sub_8217F768(ctx, base);
	// li r9,6
	ctx.r9.s64 = 6;
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822DD188;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,6
	ctx.r3.s64 = 6;
	// std r8,188(r1)
	PPC_STORE_U64(ctx.r1.u32 + 188, ctx.r8.u64);
	// bl 0x8217f768
	ctx.lr = 0x822DD1A0;
	sub_8217F768(ctx, base);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822DD1B0;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r6,3
	ctx.r6.s64 = 3;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r5,196(r1)
	PPC_STORE_U64(ctx.r1.u32 + 196, ctx.r5.u64);
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r6,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r6.u32);
	// bl 0x8217f768
	ctx.lr = 0x822DD1D0;
	sub_8217F768(ctx, base);
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-28076(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -28076);
	// bl 0x82413340
	ctx.lr = 0x822DD1E0;
	sub_82413340(ctx, base);
loc_822DD1E0:
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// rlwinm r30,r5,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fdivs f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 / ctx.f10.f64));
	// fsel f6,f7,f7,f13
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : ctx.f13.f64;
	// fsubs f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f4,f5,f0,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? f0.f64 : ctx.f6.f64;
	// stfs f4,4(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x82179710
	ctx.lr = 0x822DD244;
	sub_82179710(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lfs f1,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// lfs f3,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v0,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,112
	ctx.r9.s64 = 112;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f0,3732(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3732);
	f0.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,-26876(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -26876);
	// fmadds f2,f1,f0,f3
	ctx.f2.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f3.f64));
	// stfs f2,80(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v12,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v61,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// vmaddfp v0,v0,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vpermwi128 v59,v61,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// vpermwi128 v58,v61,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,8
	ctx.r5.s64 = 8;
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v57,v63,v0
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ee80
	ctx.lr = 0x822DD2D4;
	sub_8217EE80(ctx, base);
	// lwzx r3,r30,r31
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x82179718
	ctx.lr = 0x822DD2DC;
	sub_82179718(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r3,r8,-31280
	ctx.r3.s64 = ctx.r8.s64 + -31280;
	// bl 0x8217d918
	ctx.lr = 0x822DD2E8;
	sub_8217D918(ctx, base);
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// bl 0x82491668
	ctx.lr = 0x822DD300;
	sub_82491668(ctx, base);
loc_822DD300:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_822DD308:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,33(r31)
	PPC_STORE_U8(r31.u32 + 33, ctx.r10.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DD088) {
	__imp__sub_822DD088(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DD324) {
	__imp__sub_822DD324(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD328) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822DD330;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,20
	r11.s64 = 20;
	// li r3,20
	ctx.r3.s64 = 20;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x8217fed0
	ctx.lr = 0x822DD350;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,20
	ctx.r3.s64 = 20;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,116(r1)
	PPC_STORE_U64(ctx.r1.u32 + 116, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x822DD368;
	sub_8217F768(ctx, base);
	// li r9,9
	ctx.r9.s64 = 9;
	// li r3,9
	ctx.r3.s64 = 9;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822DD378;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r4,1
	ctx.r4.s64 = 1;
	// std r7,124(r1)
	PPC_STORE_U64(ctx.r1.u32 + 124, ctx.r7.u64);
	// li r3,9
	ctx.r3.s64 = 9;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// bl 0x8217f768
	ctx.lr = 0x822DD398;
	sub_8217F768(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r4,36
	ctx.r4.s64 = 36;
	// lfs f11,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// lfs f9,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// li r10,112
	ctx.r10.s64 = 112;
	// lvx128 v12,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,15360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 15360);
	f0.f64 = double(temp.f32);
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lvlx128 v63,r31,r4
	temp.u32 = r31.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lwz r11,-26876(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -26876);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f7,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f7,84(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v13,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfs f6,44(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f1,f6,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// fctiwz f4,f12
	ctx.f4.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f4.u64);
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f3,f10
	ctx.f3.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f3.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f2,f8
	ctx.f2.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f2,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f2.u64);
	// lwz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// stvx128 v11,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwimi r8,r6,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// or r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 | r11.u64;
	// rlwimi r4,r10,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// bl 0x822fa7b0
	ctx.lr = 0x822DD440;
	sub_822FA7B0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82491668
	ctx.lr = 0x822DD448;
	sub_82491668(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DD328) {
	__imp__sub_822DD328(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD450) {
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
	ctx.lr = 0x822DD458;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// addi r4,r11,-11020
	ctx.r4.s64 = r11.s64 + -11020;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82492148
	ctx.lr = 0x822DD474;
	sub_82492148(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,-11040
	ctx.r4.s64 = ctx.r10.s64 + -11040;
	// bl 0x82493310
	ctx.lr = 0x822DD484;
	sub_82493310(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,-11064
	ctx.r4.s64 = ctx.r9.s64 + -11064;
	// bl 0x82492e70
	ctx.lr = 0x822DD494;
	sub_82492E70(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,-11084
	ctx.r4.s64 = ctx.r8.s64 + -11084;
	// bl 0x82492fe0
	ctx.lr = 0x822DD4A4;
	sub_82492FE0(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r7,-11100
	ctx.r4.s64 = ctx.r7.s64 + -11100;
	// bl 0x82493098
	ctx.lr = 0x822DD4B4;
	sub_82493098(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r6,-11120
	ctx.r4.s64 = ctx.r6.s64 + -11120;
	// bl 0x82492f28
	ctx.lr = 0x822DD4C4;
	sub_82492F28(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r5,-11140
	ctx.r4.s64 = ctx.r5.s64 + -11140;
	// bl 0x82493150
	ctx.lr = 0x822DD4D4;
	sub_82493150(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822dc388
	ctx.lr = 0x822DD4DC;
	sub_822DC388(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r3,r4,-11148
	ctx.r3.s64 = ctx.r4.s64 + -11148;
	// bl 0x82491130
	ctx.lr = 0x822DD4E8;
	sub_82491130(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// li r10,128
	ctx.r10.s64 = 128;
	// stb r11,789(r31)
	PPC_STORE_U8(r31.u32 + 789, r11.u8);
	// li r9,32
	ctx.r9.s64 = 32;
	// stb r11,790(r31)
	PPC_STORE_U8(r31.u32 + 790, r11.u8);
	// li r8,256
	ctx.r8.s64 = 256;
	// stb r11,796(r31)
	PPC_STORE_U8(r31.u32 + 796, r11.u8);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r11,800(r31)
	PPC_STORE_U32(r31.u32 + 800, r11.u32);
	// stb r11,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r11.u8);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stb r29,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, r29.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r9,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// stb r11,124(r1)
	PPC_STORE_U8(ctx.r1.u32 + 124, r11.u8);
	// stb r11,125(r1)
	PPC_STORE_U8(ctx.r1.u32 + 125, r11.u8);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stb r29,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r29.u8);
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// stb r11,140(r1)
	PPC_STORE_U8(ctx.r1.u32 + 140, r11.u8);
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x82495768
	ctx.lr = 0x822DD554;
	sub_82495768(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r3,-27856(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -27856);
	// addi r4,r6,-11152
	ctx.r4.s64 = ctx.r6.s64 + -11152;
	// bl 0x823db730
	ctx.lr = 0x822DD568;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822dd5a0
	if (cr6.eq) goto loc_822DD5A0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-27856(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -27856);
	// addi r4,r11,-11956
	ctx.r4.s64 = r11.s64 + -11956;
	// bl 0x823db730
	ctx.lr = 0x822DD580;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822dd5a0
	if (cr6.eq) goto loc_822DD5A0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,-27856(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -27856);
	// addi r4,r11,-11160
	ctx.r4.s64 = r11.s64 + -11160;
	// bl 0x823db730
	ctx.lr = 0x822DD598;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822dd678
	if (!cr6.eq) goto loc_822DD678;
loc_822DD5A0:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r30,r10,-11172
	r30.s64 = ctx.r10.s64 + -11172;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822DD5CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,4336(r31)
	PPC_STORE_U32(r31.u32 + 4336, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
	ctx.lr = 0x822DD600;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4336(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4336);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-11188
	ctx.r4.s64 = ctx.r10.s64 + -11188;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822DD618;
	sub_8218A568(ctx, base);
	// stw r3,4344(r31)
	PPC_STORE_U32(r31.u32 + 4344, ctx.r3.u32);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r30,r8,30576
	r30.s64 = ctx.r8.s64 + 30576;
	// addi r4,r7,19848
	ctx.r4.s64 = ctx.r7.s64 + 19848;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x822DD634;
	sub_821CA540(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r6,-11204
	ctx.r4.s64 = ctx.r6.s64 + -11204;
	// bl 0x821ca540
	ctx.lr = 0x822DD644;
	sub_821CA540(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r5,r11,-11208
	ctx.r5.s64 = r11.s64 + -11208;
	// addi r4,r10,-11228
	ctx.r4.s64 = ctx.r10.s64 + -11228;
	// lwz r6,-27448(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + -27448);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r31,4340
	ctx.r3.s64 = r31.s64 + 4340;
	// bl 0x822dc760
	ctx.lr = 0x822DD668;
	sub_822DC760(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822DD670;
	sub_821C9A90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822DD678;
	sub_821C9A90(ctx, base);
loc_822DD678:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,-11248
	ctx.r3.s64 = r11.s64 + -11248;
	// bl 0x8218a4e8
	ctx.lr = 0x822DD688;
	sub_8218A4E8(ctx, base);
	// stw r3,816(r31)
	PPC_STORE_U32(r31.u32 + 816, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r10,-11268
	ctx.r3.s64 = ctx.r10.s64 + -11268;
	// bl 0x8218a4e8
	ctx.lr = 0x822DD69C;
	sub_8218A4E8(ctx, base);
	// stw r3,820(r31)
	PPC_STORE_U32(r31.u32 + 820, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r9,-11288
	ctx.r3.s64 = ctx.r9.s64 + -11288;
	// bl 0x8218a4e8
	ctx.lr = 0x822DD6B0;
	sub_8218A4E8(ctx, base);
	// stw r3,824(r31)
	PPC_STORE_U32(r31.u32 + 824, ctx.r3.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DD450) {
	__imp__sub_822DD450(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD6BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DD6BC) {
	__imp__sub_822DD6BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD6C0) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8217d5e8
	ctx.lr = 0x822DD6DC;
	sub_8217D5E8(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,-26876(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822bff40
	ctx.lr = 0x822DD6F0;
	sub_822BFF40(ctx, base);
	// stw r31,992(r30)
	PPC_STORE_U32(r30.u32 + 992, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8217c658
	ctx.lr = 0x822DD700;
	sub_8217C658(ctx, base);
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

PPC_WEAK_FUNC(sub_822DD6C0) {
	__imp__sub_822DD6C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DD71C) {
	__imp__sub_822DD71C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822DD728;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r31,r30,160
	r31.s64 = r30.s64 + 160;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r29,r10,4168
	r29.s64 = ctx.r10.s64 + 4168;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822dd088
	ctx.lr = 0x822DD754;
	sub_822DD088(ctx, base);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,-7600(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7600);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822dc520
	ctx.lr = 0x822DD774;
	sub_822DC520(ctx, base);
	// addi r5,r3,192
	ctx.r5.s64 = ctx.r3.s64 + 192;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822dd328
	ctx.lr = 0x822DD784;
	sub_822DD328(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DD720) {
	__imp__sub_822DD720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DD78C) {
	__imp__sub_822DD78C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DD790) {
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
	ctx.lr = 0x822DD798;
	// stwu r1,-1280(r1)
	ea = -1280 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r10,4164(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4164);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822dda3c
	if (cr6.eq) goto loc_822DDA3C;
	// bl 0x822dbd70
	ctx.lr = 0x822DD7B8;
	sub_822DBD70(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822dd800
	if (cr6.eq) goto loc_822DD800;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82491140
	ctx.lr = 0x822DD7CC;
	sub_82491140(ctx, base);
	// bl 0x822d5268
	ctx.lr = 0x822DD7D0;
	sub_822D5268(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dd7e0
	if (cr6.eq) goto loc_822DD7E0;
	// bl 0x822d5618
	ctx.lr = 0x822DD7E0;
	sub_822D5618(ctx, base);
loc_822DD7E0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822dda3c
	if (cr6.eq) goto loc_822DDA3C;
	// bl 0x822eff70
	ctx.lr = 0x822DD7F8;
	sub_822EFF70(ctx, base);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9248
	return;
loc_822DD800:
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x822dd97c
	if (!cr6.eq) goto loc_822DD97C;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x822dd6c0
	ctx.lr = 0x822DD810;
	sub_822DD6C0(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10992(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -10992);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821d1de0
	ctx.lr = 0x822DD884;
	sub_821D1DE0(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v63,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v62,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v61,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v10,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r0,r10
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v0,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vmulfp128 v9,v0,v58
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// vmulfp128 v7,v0,v57
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v8,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vmaddfp v29,v0,v10,v30
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(v30.f32)));
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vspltw128 v5,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v3,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v2,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// vspltw128 v1,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// vspltw128 v31,v60,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vmaddfp v28,v13,v8,v11
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// vmaddfp v27,v13,v6,v9
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v26,v13,v5,v7
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v25,v13,v4,v29
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v24,v12,v3,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v12,v2,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v12,v1,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v26.f32)));
	// vmaddfp v21,v12,v31,v25
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v25.f32)));
	// stvx128 v24,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x822DD950;
	sub_8217CE80(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82494258
	ctx.lr = 0x822DD960;
	sub_82494258(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,1216(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1216);
	// bl 0x8217c658
	ctx.lr = 0x822DD96C;
	sub_8217C658(ctx, base);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x8217cb48
	ctx.lr = 0x822DD974;
	sub_8217CB48(ctx, base);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9248
	return;
loc_822DD97C:
	// rlwinm r11,r30,0,14,14
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x20000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822dd998
	if (cr6.eq) goto loc_822DD998;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82494258
	ctx.lr = 0x822DD998;
	sub_82494258(ctx, base);
loc_822DD998:
	// lis r11,2
	r11.s64 = 131072;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x822dda3c
	if (!cr6.eq) goto loc_822DDA3C;
	// lwz r11,4340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4340);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dda3c
	if (cr6.eq) goto loc_822DDA3C;
	// bl 0x82190880
	ctx.lr = 0x822DD9B4;
	sub_82190880(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82187bf0
	ctx.lr = 0x822DD9BC;
	sub_82187BF0(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,21664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dd9d8
	if (cr6.eq) goto loc_822DD9D8;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x822dd9e0
	goto loc_822DD9E0;
loc_822DD9D8:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r6,-25360(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -25360);
loc_822DD9E0:
	// lwz r11,4336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4336);
	// lwz r5,4344(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4344);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822DD9F4;
	sub_82189CE0(ctx, base);
	// lwz r3,4336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4336);
	// bl 0x82190870
	ctx.lr = 0x822DD9FC;
	sub_82190870(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x822DDA04;
	sub_82187BE0(ctx, base);
	// lwz r3,4340(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4340);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822DDA2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82190870
	ctx.lr = 0x822DDA34;
	sub_82190870(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82187be0
	ctx.lr = 0x822DDA3C;
	sub_82187BE0(ctx, base);
loc_822DDA3C:
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822DD790) {
	__imp__sub_822DD790(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DDA44) {
	__imp__sub_822DDA44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDA48) {
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
	ctx.lr = 0x822DDA50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r31,r29,8
	r31.s64 = r29.s64 + 8;
	// addi r10,r11,-10984
	ctx.r10.s64 = r11.s64 + -10984;
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// beq cr6,0x822ddaa0
	if (cr6.eq) goto loc_822DDAA0;
loc_822DDA74:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822dda94
	if (cr6.eq) goto loc_822DDA94;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DDA94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DDA94:
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// bne cr6,0x822dda74
	if (!cr6.eq) goto loc_822DDA74;
loc_822DDAA0:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// beq cr6,0x822ddac0
	if (cr6.eq) goto loc_822DDAC0;
loc_822DDAAC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822DDAB8;
	sub_82130588(ctx, base);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// bne cr6,0x822ddaac
	if (!cr6.eq) goto loc_822DDAAC;
loc_822DDAC0:
	// stw r31,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r31.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r31.u32);
	// bl 0x821d2028
	ctx.lr = 0x822DDAD0;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DDA48) {
	__imp__sub_822DDA48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDAD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20588);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DDAD8) {
	__imp__sub_822DDAD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDAE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DDAE4) {
	__imp__sub_822DDAE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDAE8) {
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
	ctx.lr = 0x822DDAF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r28,r29,8
	r28.s64 = r29.s64 + 8;
	// lwz r31,8(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// beq cr6,0x822ddb70
	if (cr6.eq) goto loc_822DDB70;
loc_822DDB08:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ddb48
	if (cr6.eq) goto loc_822DDB48;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822ddb48
	if (cr6.eq) goto loc_822DDB48;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DDB3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
loc_822DDB48:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822DDB64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// bne cr6,0x822ddb08
	if (!cr6.eq) goto loc_822DDB08;
loc_822DDB70:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822DDAE8) {
	__imp__sub_822DDAE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDB78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// li r11,0
	r11.s64 = 0;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// std r11,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r11.u64);
	// addi r7,r8,-10952
	ctx.r7.s64 = ctx.r8.s64 + -10952;
	// lfs f12,3732(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r31,-32256
	r31.s64 = -2113929216;
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r5,6
	ctx.r5.s64 = 6;
	// lfs f10,-17876(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -17876);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,12428(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12428);
	ctx.f9.f64 = double(temp.f32);
	// lfs f11,10788(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 10788);
	ctx.f11.f64 = double(temp.f32);
	// lfs f8,11360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11360);
	ctx.f8.f64 = double(temp.f32);
	// ld r4,-16(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r4,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r4.u64);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stfs f0,44(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f12,64(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f12,68(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f12,72(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stw r5,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r5.u32);
	// stfs f10,80(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f9,84(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f11,100(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f11,104(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// stfs f0,116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stfs f8,144(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// stfs f13,148(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// stfs f0,160(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// stfs f0,164(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// stfs f0,168(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 168, temp.u32);
	// stfs f0,172(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 172, temp.u32);
	// stfs f0,176(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// stfs f0,180(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 180, temp.u32);
	// stfs f0,184(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 184, temp.u32);
	// stfs f0,188(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 188, temp.u32);
	// stfs f0,192(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// stfs f0,196(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// stfs f0,200(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// stfs f0,204(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// stfs f0,208(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// stfs f0,212(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// stfs f0,216(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 216, temp.u32);
	// stfs f0,220(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// stfs f0,224(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// stfs f0,228(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 228, temp.u32);
	// stfs f0,232(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 232, temp.u32);
	// stfs f0,236(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 236, temp.u32);
	// stw r11,240(r3)
	PPC_STORE_U32(ctx.r3.u32 + 240, r11.u32);
	// stw r11,244(r3)
	PPC_STORE_U32(ctx.r3.u32 + 244, r11.u32);
	// stw r11,248(r3)
	PPC_STORE_U32(ctx.r3.u32 + 248, r11.u32);
	// stb r11,544(r3)
	PPC_STORE_U8(ctx.r3.u32 + 544, r11.u8);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DDB78) {
	__imp__sub_822DDB78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDCA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DDCA4) {
	__imp__sub_822DDCA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDCA8) {
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
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-10912
	ctx.r4.s64 = r11.s64 + -10912;
	// bl 0x8218a568
	ctx.lr = 0x822DDCC8;
	sub_8218A568(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DDCA8) {
	__imp__sub_822DDCA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDCE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DDCE4) {
	__imp__sub_822DDCE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDCE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822DDCF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r6,r29,48
	ctx.r6.s64 = r29.s64 + 48;
	// lwz r5,72(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// bl 0x82189aa0
	ctx.lr = 0x822DDD1C;
	sub_82189AA0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,76(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// addi r6,r29,68
	ctx.r6.s64 = r29.s64 + 68;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189aa0
	ctx.lr = 0x822DDD34;
	sub_82189AA0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,84(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// addi r6,r29,100
	ctx.r6.s64 = r29.s64 + 100;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189aa0
	ctx.lr = 0x822DDD4C;
	sub_82189AA0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,88(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 88);
	// addi r6,r29,104
	ctx.r6.s64 = r29.s64 + 104;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189aa0
	ctx.lr = 0x822DDD64;
	sub_82189AA0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,92(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 92);
	// addi r6,r29,108
	ctx.r6.s64 = r29.s64 + 108;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189aa0
	ctx.lr = 0x822DDD7C;
	sub_82189AA0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,96(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// addi r6,r29,112
	ctx.r6.s64 = r29.s64 + 112;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189aa0
	ctx.lr = 0x822DDD94;
	sub_82189AA0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,120(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// addi r6,r29,216
	ctx.r6.s64 = r29.s64 + 216;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189aa0
	ctx.lr = 0x822DDDAC;
	sub_82189AA0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r5,112(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 112);
	// addi r6,r29,160
	ctx.r6.s64 = r29.s64 + 160;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189aa0
	ctx.lr = 0x822DDDC4;
	sub_82189AA0(ctx, base);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r29,176
	ctx.r6.s64 = r29.s64 + 176;
	// lwz r5,116(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189aa0
	ctx.lr = 0x822DDDDC;
	sub_82189AA0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822DDCE8) {
	__imp__sub_822DDCE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDDE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DDDE4) {
	__imp__sub_822DDDE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDDE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20404(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20404);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DDDE8) {
	__imp__sub_822DDDE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DDDF4) {
	__imp__sub_822DDDF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DDDF8) {
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
	ctx.lr = 0x822DDE00;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,-10124
	ctx.r4.s64 = r11.s64 + -10124;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDE34;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,-10912
	ctx.r4.s64 = ctx.r7.s64 + -10912;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDE5C;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-10148
	ctx.r4.s64 = ctx.r10.s64 + -10148;
	// bl 0x8218a568
	ctx.lr = 0x822DDE74;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,14640
	ctx.r4.s64 = ctx.r9.s64 + 14640;
	// bl 0x8218a568
	ctx.lr = 0x822DDE8C;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r4,r8,-11392
	ctx.r4.s64 = ctx.r8.s64 + -11392;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDEB4;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r4,-10160
	ctx.r4.s64 = ctx.r4.s64 + -10160;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDEDC;
	sub_8218A568(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r4,r8,-10172
	ctx.r4.s64 = ctx.r8.s64 + -10172;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDF04;
	sub_8218A568(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r4,-10188
	ctx.r4.s64 = ctx.r4.s64 + -10188;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDF2C;
	sub_8218A568(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r4,r6,-10208
	ctx.r4.s64 = ctx.r6.s64 + -10208;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDF54;
	sub_8218A568(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-10220
	ctx.r4.s64 = ctx.r4.s64 + -10220;
	// bl 0x8218a568
	ctx.lr = 0x822DDF6C;
	sub_8218A568(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r10,-10236
	ctx.r4.s64 = ctx.r10.s64 + -10236;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDF94;
	sub_8218A568(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r4,-10248
	ctx.r4.s64 = ctx.r4.s64 + -10248;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDFBC;
	sub_8218A568(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r10,-10260
	ctx.r4.s64 = ctx.r10.s64 + -10260;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DDFE4;
	sub_8218A568(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// addi r4,r6,-10280
	ctx.r4.s64 = ctx.r6.s64 + -10280;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE00C;
	sub_8218A568(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-10300
	ctx.r4.s64 = ctx.r9.s64 + -10300;
	// bl 0x8218a568
	ctx.lr = 0x822DE024;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r4,r8,-11480
	ctx.r4.s64 = ctx.r8.s64 + -11480;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE04C;
	sub_8218A568(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r4,-11496
	ctx.r4.s64 = ctx.r4.s64 + -11496;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE074;
	sub_8218A568(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r4,r6,-11516
	ctx.r4.s64 = ctx.r6.s64 + -11516;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE09C;
	sub_8218A568(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r4,-10312
	ctx.r4.s64 = ctx.r4.s64 + -10312;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE0C4;
	sub_8218A568(ctx, base);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r4,r8,-10328
	ctx.r4.s64 = ctx.r8.s64 + -10328;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE0EC;
	sub_8218A568(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r4,r4,-10344
	ctx.r4.s64 = ctx.r4.s64 + -10344;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE114;
	sub_8218A568(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r4,r8,-10356
	ctx.r4.s64 = ctx.r8.s64 + -10356;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE13C;
	sub_8218A568(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r4,-10376
	ctx.r4.s64 = ctx.r4.s64 + -10376;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE164;
	sub_8218A568(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r4,r8,-10400
	ctx.r4.s64 = ctx.r8.s64 + -10400;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE18C;
	sub_8218A568(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r4,r4,-10416
	ctx.r4.s64 = ctx.r4.s64 + -10416;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE1B4;
	sub_8218A568(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r4,r6,-10460
	ctx.r4.s64 = ctx.r6.s64 + -10460;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE1DC;
	sub_8218A568(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r4,-10476
	ctx.r4.s64 = ctx.r4.s64 + -10476;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE204;
	sub_8218A568(ctx, base);
	// stw r3,212(r31)
	PPC_STORE_U32(r31.u32 + 212, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r6,-10512
	ctx.r4.s64 = ctx.r6.s64 + -10512;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE22C;
	sub_8218A568(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r4,r4,-10528
	ctx.r4.s64 = ctx.r4.s64 + -10528;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE254;
	sub_8218A568(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-10544
	ctx.r4.s64 = ctx.r8.s64 + -10544;
	// bl 0x8218a568
	ctx.lr = 0x822DE26C;
	sub_8218A568(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// addi r4,r5,-10564
	ctx.r4.s64 = ctx.r5.s64 + -10564;
	// rlwinm r11,r6,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE294;
	sub_8218A568(ctx, base);
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r10,-10584
	ctx.r4.s64 = ctx.r10.s64 + -10584;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE2BC;
	sub_8218A568(ctx, base);
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// addi r4,r6,-10600
	ctx.r4.s64 = ctx.r6.s64 + -10600;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE2E4;
	sub_8218A568(ctx, base);
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r7,-10620
	ctx.r4.s64 = ctx.r7.s64 + -10620;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE30C;
	sub_8218A568(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// addi r4,r10,-10636
	ctx.r4.s64 = ctx.r10.s64 + -10636;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE334;
	sub_8218A568(ctx, base);
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-10652
	ctx.r4.s64 = ctx.r9.s64 + -10652;
	// bl 0x8218a568
	ctx.lr = 0x822DE34C;
	sub_8218A568(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r4,r8,-10668
	ctx.r4.s64 = ctx.r8.s64 + -10668;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE374;
	sub_8218A568(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r4,r4,-10680
	ctx.r4.s64 = ctx.r4.s64 + -10680;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE39C;
	sub_8218A568(ctx, base);
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r4,r8,-10692
	ctx.r4.s64 = ctx.r8.s64 + -10692;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE3C4;
	sub_8218A568(ctx, base);
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r4,-10712
	ctx.r4.s64 = ctx.r4.s64 + -10712;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE3EC;
	sub_8218A568(ctx, base);
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r4,r8,-10728
	ctx.r4.s64 = ctx.r8.s64 + -10728;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE414;
	sub_8218A568(ctx, base);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r4,-10740
	ctx.r4.s64 = ctx.r4.s64 + -10740;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE43C;
	sub_8218A568(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r4,r6,-10756
	ctx.r4.s64 = ctx.r6.s64 + -10756;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE464;
	sub_8218A568(ctx, base);
	// stw r3,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r4,r4,-10772
	ctx.r4.s64 = ctx.r4.s64 + -10772;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE48C;
	sub_8218A568(ctx, base);
	// stw r3,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r4,r8,-10784
	ctx.r4.s64 = ctx.r8.s64 + -10784;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE4B4;
	sub_8218A568(ctx, base);
	// stw r3,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r3.u32);
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r4,r4,-10796
	ctx.r4.s64 = ctx.r4.s64 + -10796;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x822DE4DC;
	sub_8218A568(ctx, base);
	// stw r3,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-10808
	ctx.r4.s64 = ctx.r8.s64 + -10808;
	// bl 0x8218a568
	ctx.lr = 0x822DE4F4;
	sub_8218A568(ctx, base);
	// stw r3,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-10820
	ctx.r4.s64 = ctx.r7.s64 + -10820;
	// bl 0x8218a568
	ctx.lr = 0x822DE50C;
	sub_8218A568(ctx, base);
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-10832
	ctx.r4.s64 = ctx.r6.s64 + -10832;
	// bl 0x8218a568
	ctx.lr = 0x822DE524;
	sub_8218A568(ctx, base);
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-10852
	ctx.r4.s64 = ctx.r4.s64 + -10852;
	// bl 0x8218a568
	ctx.lr = 0x822DE53C;
	sub_8218A568(ctx, base);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-10864
	ctx.r4.s64 = r11.s64 + -10864;
	// bl 0x8218a568
	ctx.lr = 0x822DE554;
	sub_8218A568(ctx, base);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-10872
	ctx.r4.s64 = ctx.r10.s64 + -10872;
	// bl 0x8218a568
	ctx.lr = 0x822DE56C;
	sub_8218A568(ctx, base);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-10880
	ctx.r4.s64 = ctx.r9.s64 + -10880;
	// bl 0x8218a568
	ctx.lr = 0x822DE584;
	sub_8218A568(ctx, base);
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822DDDF8) {
	__imp__sub_822DDDF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DE590) {
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
	// li r3,216
	ctx.r3.s64 = 216;
	// bl 0x82130528
	ctx.lr = 0x822DE5A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822de5c8
	if (cr6.eq) goto loc_822DE5C8;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-10888
	ctx.r10.s64 = r11.s64 + -10888;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822DE5C8:
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

PPC_WEAK_FUNC(sub_822DE590) {
	__imp__sub_822DE590(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DE5DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DE5DC) {
	__imp__sub_822DE5DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DE5E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,96
	ctx.r10.s64 = 96;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r11,r8,2528
	r11.s64 = ctx.r8.s64 + 2528;
	// lvx128 v61,r3,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v61,99
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x9C));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v59,v63,135
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmulfp128 v0,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// vpermwi128 v12,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v11,v61,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x78));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r7,-31648
	ctx.r9.s64 = ctx.r7.s64 + -31648;
	// vpermwi128 v58,v61,135
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x78));
	// addi r8,r10,-31664
	ctx.r8.s64 = ctx.r10.s64 + -31664;
	// vpermwi128 v10,v61,99
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x9C));
	// vpermwi128 v57,v61,99
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x9C));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// vpermwi128 v9,v61,135
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x78));
	// lfs f13,84(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r7,2240
	ctx.r3.s64 = ctx.r7.s64 + 2240;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v8,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vnmsubfp v7,v12,v11,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor128 v6,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lfs f0,-10992(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -10992);
	f0.f64 = double(temp.f32);
	// vor128 v5,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v56,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v55,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmsum3fp128 v52,v7,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v7.f32), 0xEF));
	// vspltw128 v53,v56,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vrsqrtefp128 v51,v52
	simde_mm_store_ps(v51.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v52.f32))));
	// vor128 v4,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vcmpeqfp128 v3,v51,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v2,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// vsel v0,v2,v8,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// vmulfp128 v1,v0,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v31,v61,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v30,v4,v1,v13
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v29,v30,v31,v0
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v50,v7,v29
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(v29.f32)));
	// vpermwi128 v49,v50,99
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x9C));
	// vpermwi128 v28,v50,135
	simde_mm_store_si128((simde__m128i*)v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x78));
	// vmulfp128 v27,v58,v49
	simde_mm_store_ps(v27.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v49.f32)));
	// vnmsubfp v26,v10,v28,v27
	simde_mm_store_ps(v26.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(v27.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v48,v26,v26
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(v26.f32), 0xEF));
	// vrsqrtefp128 v47,v48
	simde_mm_store_ps(v47.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v48.f32))));
	// vor128 v25,v48,v48
	simde_mm_store_si128((simde__m128i*)v25.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vcmpeqfp128 v24,v47,v62
	simde_mm_store_ps(v24.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v23,v47,v47
	simde_mm_store_si128((simde__m128i*)v23.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vsel v0,v23,v6,v24
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)v23.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vmulfp128 v22,v0,v0
	simde_mm_store_ps(v22.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v21,v61,v0
	simde_mm_store_ps(v21.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v20,v25,v22,v13
	simde_mm_store_ps(v20.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v25.f32), simde_mm_load_ps(v22.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v19,v20,v21,v0
	simde_mm_store_ps(v19.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v20.f32), simde_mm_load_ps(v21.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v46,v26,v19
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(v19.f32)));
	// vpermwi128 v45,v46,135
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x78));
	// vmulfp128 v44,v46,v54
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v54.f32)));
	// vpermwi128 v18,v46,99
	simde_mm_store_si128((simde__m128i*)v18.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x9C));
	// vmulfp128 v17,v45,v57
	simde_mm_store_ps(v17.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v57.f32)));
	// vnmsubfp v16,v18,v9,v17
	simde_mm_store_ps(v16.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v18.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(v17.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v43,v16,v16
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v16.f32), simde_mm_load_ps(v16.f32), 0xEF));
	// vrsqrtefp128 v42,v43
	simde_mm_store_ps(v42.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v43.f32))));
	// vor128 v15,v43,v43
	simde_mm_store_si128((simde__m128i*)v15.u8, simde_mm_load_si128((simde__m128i*)v43.u8));
	// vcmpeqfp128 v14,v42,v62
	simde_mm_store_ps(v14.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v0,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// vsel v0,v0,v5,v14
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vmulfp128 v12,v0,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v11,v61,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v10,v15,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v15.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v10,v11,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v41,v16,v9
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v16.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vmulfp128 v40,v41,v53
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v40,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DE5E0) {
	__imp__sub_822DE5E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DE740) {
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
	// bl 0x823d91f0
	ctx.lr = 0x822DE748;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x82189ce0
	ctx.lr = 0x822DE77C;
	sub_82189CE0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r5,8(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822DE790;
	sub_82189CE0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r5,12(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822DE7A4;
	sub_82189CE0(ctx, base);
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,16(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE7CC;
	sub_8218A6E0(ctx, base);
	// lbz r11,544(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822de820
	if (!cr6.eq) goto loc_822DE820;
	// addi r27,r31,256
	r27.s64 = r31.s64 + 256;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ddce8
	ctx.lr = 0x822DE7F0;
	sub_822DDCE8(ctx, base);
	// lwz r3,244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// lfs f1,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822de814
	if (cr6.eq) goto loc_822DE814;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822DE810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822de820
	goto loc_822DE820;
loc_822DE814:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822DE820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DE820:
	// li r11,128
	r11.s64 = 128;
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	f0.f64 = double(temp.f32);
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,20(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stfs f13,316(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x822DE85C;
	sub_8218A6E0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,24(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r31,256
	ctx.r6.s64 = r31.s64 + 256;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE87C;
	sub_8218A6E0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,28(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r31,272
	ctx.r6.s64 = r31.s64 + 272;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE89C;
	sub_8218A6E0(ctx, base);
	// lfs f12,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 320);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,80(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE8C4;
	sub_8218A6E0(ctx, base);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f11,336(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 336);
	ctx.f11.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f10,340(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 340);
	ctx.f10.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f9,344(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 344);
	ctx.f9.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lfs f31,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	f31.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stfs f31,172(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lwz r5,32(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// stfs f10,164(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stfs f9,168(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x822DE908;
	sub_8218A6E0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,36(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r31,448
	ctx.r6.s64 = r31.s64 + 448;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE928;
	sub_8218A6E0(ctx, base);
	// lfs f8,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,40(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE950;
	sub_8218A6E0(ctx, base);
	// lwz r5,44(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// lfs f7,464(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 464);
	ctx.f7.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE978;
	sub_8218A6E0(ctx, base);
	// lfs f6,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,60(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE9A0;
	sub_8218A6E0(ctx, base);
	// lfs f5,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,64(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 64);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE9C8;
	sub_8218A6E0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,68(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r31,64
	ctx.r6.s64 = r31.s64 + 64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DE9E8;
	sub_8218A6E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f4,520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 520);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,524(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 524);
	ctx.f3.f64 = double(temp.f32);
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f2,528(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 528);
	ctx.f2.f64 = double(temp.f32);
	// addi r26,r1,240
	r26.s64 = ctx.r1.s64 + 240;
	// lwz r5,56(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// lfs f0,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r9,4
	ctx.r9.s64 = 4;
	// lfs f13,32680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	ctx.f13.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// fmadds f12,f4,f0,f13
	ctx.f12.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f13.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f0,f3,f0,f13
	f0.f64 = double(float(ctx.f3.f64 * f0.f64 + ctx.f13.f64));
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f11,-10992(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -10992);
	ctx.f11.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// fmuls f1,f2,f11
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// stvx128 v62,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// fdivs f0,f31,f0
	f0.f64 = double(float(f31.f64 / f0.f64));
	// stfs f0,244(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// fmuls f13,f0,f12
	ctx.f13.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,240(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x822DEA6C;
	sub_8218A6E0(ctx, base);
	// lfs f11,464(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 464);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,304(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 304);
	ctx.f10.f64 = double(temp.f32);
	// lwz r5,72(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// fmuls f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lfs f8,308(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 308);
	ctx.f8.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f7,312(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 312);
	ctx.f7.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f11,236(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f9,224(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r27,r31,304
	r27.s64 = r31.s64 + 304;
	// fmuls f6,f8,f11
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// stfs f6,228(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// fmuls f5,f7,f11
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// stfs f5,232(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x822DEABC;
	sub_8218A6E0(ctx, base);
	// lfs f4,324(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 324);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,76(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEAE4;
	sub_8218A6E0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,52(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r31,288
	ctx.r6.s64 = r31.s64 + 288;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEB04;
	sub_8218A6E0(ctx, base);
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,48(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r31,328
	ctx.r6.s64 = r31.s64 + 328;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEB24;
	sub_8218A6E0(ctx, base);
	// lfs f3,468(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,144(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	ctx.f2.f64 = double(temp.f32);
	// li r9,3
	ctx.r9.s64 = 3;
	// fmuls f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// lfs f0,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,212(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 212);
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x822DEB60;
	sub_8218A6E0(ctx, base);
	// lfs f12,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 356);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,84(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEB88;
	sub_8218A6E0(ctx, base);
	// lfs f11,360(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 360);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,88(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 88);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEBB0;
	sub_8218A6E0(ctx, base);
	// lfs f10,364(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 364);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,92(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 92);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEBD8;
	sub_8218A6E0(ctx, base);
	// lwz r5,96(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 96);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// lfs f9,368(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 368);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEC00;
	sub_8218A6E0(ctx, base);
	// lfs f8,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 392);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,100(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEC28;
	sub_8218A6E0(ctx, base);
	// lfs f7,372(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 372);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,384(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 384);
	ctx.f6.f64 = double(temp.f32);
	// fdivs f5,f31,f7
	ctx.f5.f64 = double(float(f31.f64 / ctx.f7.f64));
	// lfs f4,376(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 376);
	ctx.f4.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f3,380(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 380);
	ctx.f3.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f5,180(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f4,184(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stfs f3,188(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lwz r5,104(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 104);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822DEC6C;
	sub_8218A6E0(ctx, base);
	// lfs f2,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,400(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 400);
	ctx.f1.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f0,404(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 404);
	f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f13,408(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 408);
	ctx.f13.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f2,208(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// stfs f1,212(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stfs f0,216(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// lwz r5,108(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822DECAC;
	sub_8218A6E0(ctx, base);
	// li r11,416
	r11.s64 = 416;
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r5,112(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 112);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,320
	ctx.r6.s64 = ctx.r1.s64 + 320;
	// vaddfp128 v59,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8218a6e0
	ctx.lr = 0x822DECE4;
	sub_8218A6E0(ctx, base);
	// lfs f12,432(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 432);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 + f31.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,116(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DED10;
	sub_8218A6E0(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r5,120(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f0,12428(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12428);
	f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f10,472(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 472);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fmuls f9,f10,f10
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f8,476(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 476);
	ctx.f8.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f0,-10104(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -10104);
	f0.f64 = double(temp.f32);
	// lfs f13,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f7,132(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f0,f9,f13
	f0.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f6,136(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x822DED70;
	sub_8218A6E0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r5,124(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 124);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822DED84;
	sub_82189CE0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r5,132(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 132);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822DED98;
	sub_82189CE0(ctx, base);
	// lfs f5,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,136(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 136);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEDC0;
	sub_8218A6E0(ctx, base);
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,140(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 140);
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEDE0;
	sub_8218A6E0(ctx, base);
	// lfs f4,476(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 476);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,128(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEE08;
	sub_8218A6E0(ctx, base);
	// lfs f3,516(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 516);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,168(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 168);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEE30;
	sub_8218A6E0(ctx, base);
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// vmsum3fp128 v57,v58,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v56,v57
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v57.f32))));
	// vor128 v12,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vcmpeqfp128 v11,v56,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// addi r3,r5,-31648
	ctx.r3.s64 = ctx.r5.s64 + -31648;
	// addi r10,r4,-31664
	ctx.r10.s64 = ctx.r4.s64 + -31664;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// lfs f13,-31384(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31384);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,-12084(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -12084);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// vmaddfp v6,v7,v8,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v55,v58,v6
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v54,v55,v55
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f2,f13,f12
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v53,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v52,v53
	simde_mm_store_ps(v52.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v53.f32))));
	// lvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v4,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// lfs f13,84(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f12,192(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// vcmpeqfp128 v3,v52,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v2,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// stfs f12,196(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// vsel v0,v2,v5,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vmulfp128 v1,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v31,v61,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v30,v4,v1,v13
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v29,v30,v31,v0
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v51,v63,v29
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v29.f32)));
	// stvx128 v51,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dca68
	ctx.lr = 0x822DEF2C;
	sub_823DCA68(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f1,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// lfs f30,-10108(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -10108);
	f30.f64 = double(temp.f32);
	// lfs f29,14884(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	f29.f64 = double(temp.f32);
	// fmadds f10,f11,f30,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 * f30.f64 + f29.f64));
	// stfs f10,200(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// bl 0x823dca68
	ctx.lr = 0x822DEF50;
	sub_823DCA68(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lfs f8,480(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 480);
	ctx.f8.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f7,496(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 496);
	ctx.f7.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f6,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f7,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// lfs f4,504(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 504);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f6,f8
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f8.f64));
	// fmuls f2,f4,f8
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f8.f64));
	// stfs f8,156(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f5,144(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f3,148(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stfs f2,152(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,144(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// fmadds f1,f9,f30,f29
	ctx.f1.f64 = double(float(ctx.f9.f64 * f30.f64 + f29.f64));
	// stfs f1,204(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822DEFA8;
	sub_8218A6E0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x82491060
	ctx.lr = 0x822DEFB4;
	sub_82491060(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,148(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 148);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEFD4;
	sub_8218A6E0(ctx, base);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,156(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 156);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DEFF4;
	sub_8218A6E0(ctx, base);
	// lfs f0,512(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 512);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,160(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 160);
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DF01C;
	sub_8218A6E0(ctx, base);
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822de5e0
	ctx.lr = 0x822DF030;
	sub_822DE5E0(ctx, base);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r5,200(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 200);
	// addi r27,r1,256
	r27.s64 = ctx.r1.s64 + 256;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r26,r1,256
	r26.s64 = ctx.r1.s64 + 256;
	// lvx128 v48,r0,r4
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,4
	ctx.r9.s64 = 4;
	// lvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,1
	ctx.r8.s64 = 1;
	// vaddfp128 v46,v48,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v46.f32, simde_mm_add_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v47.f32)));
	// lvlx128 v50,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// lvx128 v45,r0,r27
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v44,v46,v49
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v49.f32)));
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// vsubfp128 v43,v45,v44
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v44.f32)));
	// stvx128 v43,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8218a6e0
	ctx.lr = 0x822DF08C;
	sub_8218A6E0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,204(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 204);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DF0AC;
	sub_8218A6E0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,208(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DF0CC;
	sub_8218A6E0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r5,152(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 152);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822DF0E0;
	sub_82189CE0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,40(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r5,164(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 164);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822DF0F4;
	sub_82189CE0(ctx, base);
	// lwz r5,172(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 172);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822df11c
	if (cr6.eq) goto loc_822DF11C;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,176
	ctx.r6.s64 = r31.s64 + 176;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DF11C;
	sub_8218A6E0(ctx, base);
loc_822DF11C:
	// lwz r5,176(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822df144
	if (cr6.eq) goto loc_822DF144;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DF144;
	sub_8218A6E0(ctx, base);
loc_822DF144:
	// lwz r5,180(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 180);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822df16c
	if (cr6.eq) goto loc_822DF16C;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,192
	ctx.r6.s64 = r31.s64 + 192;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DF16C;
	sub_8218A6E0(ctx, base);
loc_822DF16C:
	// lwz r5,184(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 184);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822df194
	if (cr6.eq) goto loc_822DF194;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,208
	ctx.r6.s64 = r31.s64 + 208;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DF194;
	sub_8218A6E0(ctx, base);
loc_822DF194:
	// lwz r5,188(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822df1bc
	if (cr6.eq) goto loc_822DF1BC;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x822DF1BC;
	sub_8218A6E0(ctx, base);
loc_822DF1BC:
	// lwz r5,192(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 192);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822df1d8
	if (cr6.eq) goto loc_822DF1D8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,240(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 240);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822DF1D8;
	sub_82189CE0(ctx, base);
loc_822DF1D8:
	// lfs f0,532(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 532);
	f0.f64 = double(temp.f32);
	// li r9,3
	ctx.r9.s64 = 3;
	// lfs f13,536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 536);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// lwz r5,196(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822DF20C;
	sub_8218A6E0(ctx, base);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
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

PPC_WEAK_FUNC(sub_822DE740) {
	__imp__sub_822DE740(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF220) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-10952
	ctx.r10.s64 = r11.s64 + -10952;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r31,40(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df280
	if (cr6.eq) goto loc_822DF280;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822DF258;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822df280
	if (!cr6.eq) goto loc_822DF280;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df280
	if (cr6.eq) goto loc_822DF280;
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
	ctx.lr = 0x822DF280;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DF280:
	// lwz r31,36(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df2bc
	if (cr6.eq) goto loc_822DF2BC;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822DF294;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822df2bc
	if (!cr6.eq) goto loc_822DF2BC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df2bc
	if (cr6.eq) goto loc_822DF2BC;
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
	ctx.lr = 0x822DF2BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DF2BC:
	// lwz r31,32(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df2f8
	if (cr6.eq) goto loc_822DF2F8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822DF2D0;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822df2f8
	if (!cr6.eq) goto loc_822DF2F8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df2f8
	if (cr6.eq) goto loc_822DF2F8;
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
	ctx.lr = 0x822DF2F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DF2F8:
	// lwz r31,28(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df334
	if (cr6.eq) goto loc_822DF334;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822DF30C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822df334
	if (!cr6.eq) goto loc_822DF334;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df334
	if (cr6.eq) goto loc_822DF334;
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
	ctx.lr = 0x822DF334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DF334:
	// lwz r31,24(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df370
	if (cr6.eq) goto loc_822DF370;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822DF348;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822df370
	if (!cr6.eq) goto loc_822DF370;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df370
	if (cr6.eq) goto loc_822DF370;
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
	ctx.lr = 0x822DF370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DF370:
	// lwz r31,20(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df3ac
	if (cr6.eq) goto loc_822DF3AC;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822DF384;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822df3ac
	if (!cr6.eq) goto loc_822DF3AC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822df3ac
	if (cr6.eq) goto loc_822DF3AC;
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
	ctx.lr = 0x822DF3AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822DF3AC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822dda48
	ctx.lr = 0x822DF3B4;
	sub_822DDA48(ctx, base);
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

PPC_WEAK_FUNC(sub_822DF220) {
	__imp__sub_822DF220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DF3CC) {
	__imp__sub_822DF3CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF3D0) {
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
	// bl 0x822df220
	ctx.lr = 0x822DF3F0;
	sub_822DF220(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822df408
	if (cr6.eq) goto loc_822DF408;
	// bl 0x82130588
	ctx.lr = 0x822DF404;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DF408:
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

PPC_WEAK_FUNC(sub_822DF3D0) {
	__imp__sub_822DF3D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF420) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r10,r11,-10092
	ctx.r10.s64 = r11.s64 + -10092;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822ddb78
	ctx.lr = 0x822DF448;
	sub_822DDB78(ctx, base);
	// addi r3,r31,576
	ctx.r3.s64 = r31.s64 + 576;
	// bl 0x82499658
	ctx.lr = 0x822DF450;
	sub_82499658(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r11,696(r31)
	PPC_STORE_U32(r31.u32 + 696, r11.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stw r11,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r11.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,31016(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f0,708(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 708, temp.u32);
	// stw r11,712(r31)
	PPC_STORE_U32(r31.u32 + 712, r11.u32);
	// stw r11,716(r31)
	PPC_STORE_U32(r31.u32 + 716, r11.u32);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,720(r31)
	PPC_STORE_U32(r31.u32 + 720, r11.u32);
	// lfs f13,-10100(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -10100);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,724(r31)
	PPC_STORE_U32(r31.u32 + 724, r11.u32);
	// lfs f12,14988(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,728(r31)
	PPC_STORE_U32(r31.u32 + 728, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,732(r31)
	PPC_STORE_U32(r31.u32 + 732, r11.u32);
	// stfs f0,736(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 736, temp.u32);
	// stfs f13,740(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 740, temp.u32);
	// stw r11,748(r31)
	PPC_STORE_U32(r31.u32 + 748, r11.u32);
	// stfs f12,744(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 744, temp.u32);
	// stw r11,752(r31)
	PPC_STORE_U32(r31.u32 + 752, r11.u32);
	// stw r11,756(r31)
	PPC_STORE_U32(r31.u32 + 756, r11.u32);
	// stw r11,760(r31)
	PPC_STORE_U32(r31.u32 + 760, r11.u32);
	// stw r11,768(r31)
	PPC_STORE_U32(r31.u32 + 768, r11.u32);
	// stb r11,772(r31)
	PPC_STORE_U8(r31.u32 + 772, r11.u8);
	// stb r10,773(r31)
	PPC_STORE_U8(r31.u32 + 773, ctx.r10.u8);
	// stb r10,774(r31)
	PPC_STORE_U8(r31.u32 + 774, ctx.r10.u8);
	// stw r10,776(r31)
	PPC_STORE_U32(r31.u32 + 776, ctx.r10.u32);
	// stb r11,780(r31)
	PPC_STORE_U8(r31.u32 + 780, r11.u8);
	// stw r11,784(r31)
	PPC_STORE_U32(r31.u32 + 784, r11.u32);
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

PPC_WEAK_FUNC(sub_822DF420) {
	__imp__sub_822DF420(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF4EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DF4EC) {
	__imp__sub_822DF4EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF4F0) {
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
	// bl 0x82495150
	ctx.lr = 0x822DF510;
	sub_82495150(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822df528
	if (cr6.eq) goto loc_822DF528;
	// bl 0x82130588
	ctx.lr = 0x822DF524;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822DF528:
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

PPC_WEAK_FUNC(sub_822DF4F0) {
	__imp__sub_822DF4F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF540) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822DF548;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d8
	ctx.lr = 0x822DF550;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822e6b38
	ctx.lr = 0x822DF55C;
	sub_822E6B38(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// addi r9,r11,-11452
	ctx.r9.s64 = r11.s64 + -11452;
	// ori r8,r10,3
	ctx.r8.u64 = ctx.r10.u64 | 3;
	// li r25,1
	r25.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// stw r25,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r25.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,-8092(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822DF590;
	sub_822E5138(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r5,r6,-11428
	ctx.r5.s64 = ctx.r6.s64 + -11428;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// bl 0x822df420
	ctx.lr = 0x822DF5A4;
	sub_822DF420(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// addi r10,r4,-11548
	ctx.r10.s64 = ctx.r4.s64 + -11548;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r10,848(r31)
	PPC_STORE_U32(r31.u32 + 848, ctx.r10.u32);
	// bl 0x82495cf0
	ctx.lr = 0x822DF5BC;
	sub_82495CF0(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r29,r31,896
	r29.s64 = r31.s64 + 896;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r28,3
	r28.s64 = 3;
	// lfs f31,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f31.f64 = double(temp.f32);
	// addi r30,r29,648
	r30.s64 = r29.s64 + 648;
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// addi r27,r11,-11520
	r27.s64 = r11.s64 + -11520;
loc_822DF5E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82497410
	ctx.lr = 0x822DF5E8;
	sub_82497410(ctx, base);
	// stfs f30,-24(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + -24, temp.u32);
	// stfs f30,-20(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + -20, temp.u32);
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// stfs f31,-8(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + -8, temp.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stfs f31,-4(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + -4, temp.u32);
	// addi r29,r29,656
	r29.s64 = r29.s64 + 656;
	// stfs f31,0(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// addi r30,r30,656
	r30.s64 = r30.s64 + 656;
	// bge 0x822df5e0
	if (!cr0.lt) goto loc_822DF5E0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r29,r31,3520
	r29.s64 = r31.s64 + 3520;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f29,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f29.f64 = double(temp.f32);
	// li r28,3
	r28.s64 = 3;
	// lfs f28,-12084(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12084);
	f28.f64 = double(temp.f32);
	// addi r30,r29,24
	r30.s64 = r29.s64 + 24;
	// lfs f30,-6176(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -6176);
	f30.f64 = double(temp.f32);
	// addi r26,r11,-11528
	r26.s64 = r11.s64 + -11528;
loc_822DF644:
	// stfs f30,-8(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + -8, temp.u32);
	// stw r26,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r26.u32);
	// stfs f30,-4(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + -4, temp.u32);
	// addi r27,r30,8
	r27.s64 = r30.s64 + 8;
	// stfs f28,0(r30)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822DF660;
	sub_82495CF0(ctx, base);
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f29,84(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x822DF680;
	sub_82496790(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// bge 0x822df644
	if (!cr0.lt) goto loc_822DF644;
	// addi r3,r31,3840
	ctx.r3.s64 = r31.s64 + 3840;
	// bl 0x822dc820
	ctx.lr = 0x822DF698;
	sub_822DC820(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stfs f31,4192(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4192, temp.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stb r25,844(r31)
	PPC_STORE_U8(r31.u32 + 844, r25.u8);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// stw r11,836(r31)
	PPC_STORE_U32(r31.u32 + 836, r11.u32);
	// lfs f13,4400(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4400);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,4340(r31)
	PPC_STORE_U32(r31.u32 + 4340, r11.u32);
	// lfs f12,-32032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32032);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,828(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 828, temp.u32);
	// stfs f13,832(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 832, temp.u32);
	// stfs f12,840(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 840, temp.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba24
	ctx.lr = 0x822DF6E0;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_822DF540) {
	__imp__sub_822DF540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF6E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DF6E4) {
	__imp__sub_822DF6E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF6E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r26{};
	PPCRegister r27{};
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
	// bl 0x823d91f0
	ctx.lr = 0x822DF6F0;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d8
	ctx.lr = 0x822DF6F8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x822dc6e0
	ctx.lr = 0x822DF704;
	sub_822DC6E0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// addi r10,r11,-11428
	ctx.r10.s64 = r11.s64 + -11428;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// bl 0x822df420
	ctx.lr = 0x822DF718;
	sub_822DF420(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r11,r27,848
	r11.s64 = r27.s64 + 848;
	// addi r8,r9,-11548
	ctx.r8.s64 = ctx.r9.s64 + -11548;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r8,848(r27)
	PPC_STORE_U32(r27.u32 + 848, ctx.r8.u32);
	// bl 0x82495cf0
	ctx.lr = 0x822DF730;
	sub_82495CF0(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r30,r27,896
	r30.s64 = r27.s64 + 896;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r29,3
	r29.s64 = 3;
	// lfs f31,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f31.f64 = double(temp.f32);
	// addi r31,r30,648
	r31.s64 = r30.s64 + 648;
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// addi r28,r11,-11520
	r28.s64 = r11.s64 + -11520;
loc_822DF754:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82497410
	ctx.lr = 0x822DF75C;
	sub_82497410(ctx, base);
	// stfs f30,-24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -24, temp.u32);
	// stfs f30,-20(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -20, temp.u32);
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// stfs f31,-8(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stfs f31,-4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -4, temp.u32);
	// addi r30,r30,656
	r30.s64 = r30.s64 + 656;
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,656
	r31.s64 = r31.s64 + 656;
	// bge 0x822df754
	if (!cr0.lt) goto loc_822DF754;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r30,r27,3520
	r30.s64 = r27.s64 + 3520;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f29,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f29.f64 = double(temp.f32);
	// li r29,3
	r29.s64 = 3;
	// lfs f28,-12084(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12084);
	f28.f64 = double(temp.f32);
	// addi r31,r30,24
	r31.s64 = r30.s64 + 24;
	// lfs f30,-6176(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -6176);
	f30.f64 = double(temp.f32);
	// addi r26,r11,-11528
	r26.s64 = r11.s64 + -11528;
loc_822DF7B8:
	// stfs f30,-8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// stfs f30,-4(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -4, temp.u32);
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// stfs f28,0(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495cf0
	ctx.lr = 0x822DF7D4;
	sub_82495CF0(ctx, base);
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f29,84(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x822DF7F4;
	sub_82496790(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,80
	r30.s64 = r30.s64 + 80;
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// bge 0x822df7b8
	if (!cr0.lt) goto loc_822DF7B8;
	// addi r3,r27,3840
	ctx.r3.s64 = r27.s64 + 3840;
	// bl 0x822dc820
	ctx.lr = 0x822DF80C;
	sub_822DC820(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x822DF81C;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822DF6E8) {
	__imp__sub_822DF6E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF820) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822df6e8
	sub_822DF6E8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822DF820) {
	__imp__sub_822DF820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF82C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DF82C) {
	__imp__sub_822DF82C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// addi r6,r11,-9776
	ctx.r6.s64 = r11.s64 + -9776;
	// rlwinm r5,r4,23,25,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 23) & 0x7F;
	// rlwinm r10,r4,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x1;
	// clrlwi r11,r5,31
	r11.u64 = ctx.r5.u32 & 0x1;
	// rlwinm r9,r4,29,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r8,r4,24,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0x1;
	// rlwinm r7,r4,21,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 21) & 0x1;
	// addi r11,r3,3024
	r11.s64 = ctx.r3.s64 + 3024;
	// bne cr6,0x822df86c
	if (!cr6.eq) goto loc_822DF86C;
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
loc_822DF86C:
	// li r6,3120
	ctx.r6.s64 = 3120;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r5,r10,24
	ctx.r5.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stvx128 v62,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822df894
	if (!cr6.eq) goto loc_822DF894;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// beq cr6,0x822df898
	if (cr6.eq) goto loc_822DF898;
loc_822DF894:
	// addi r11,r3,3008
	r11.s64 = ctx.r3.s64 + 3008;
loc_822DF898:
	// li r9,3104
	ctx.r9.s64 = 3104;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,3088
	ctx.r10.s64 = ctx.r3.s64 + 3088;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// addi r11,r3,3040
	r11.s64 = ctx.r3.s64 + 3040;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822df8c0
	if (!cr6.eq) goto loc_822DF8C0;
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
loc_822DF8C0:
	// li r9,3152
	ctx.r9.s64 = 3152;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r8,r7,24
	ctx.r8.u64 = ctx.r7.u32 & 0xFF;
	// addi r11,r3,3056
	r11.s64 = ctx.r3.s64 + 3056;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stvx128 v60,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822df8e0
	if (!cr6.eq) goto loc_822DF8E0;
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
loc_822DF8E0:
	// li r9,3168
	ctx.r9.s64 = 3168;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stvx128 v59,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,6628(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 6628);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rlwinm r11,r4,0,24,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xF0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,3136
	r11.s64 = 3136;
	// lvx128 v58,r3,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DF830) {
	__imp__sub_822DF830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF918) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// sth r5,7168(r3)
	PPC_STORE_U16(ctx.r3.u32 + 7168, ctx.r5.u16);
	// addi r5,r3,7192
	ctx.r5.s64 = ctx.r3.s64 + 7192;
	// stw r4,7188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 7188, ctx.r4.u32);
	// li r11,48
	r11.s64 = 48;
	// stb r6,7170(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7170, ctx.r6.u8);
loc_822DF92C:
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// stw r6,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r6.u32);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// bne 0x822df92c
	if (!cr0.eq) goto loc_822DF92C;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r8,7172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 7172, ctx.r8.u32);
	// stw r9,7176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 7176, ctx.r9.u32);
	// stw r10,7180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 7180, ctx.r10.u32);
	// stw r11,7184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 7184, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DF918) {
	__imp__sub_822DF918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DF95C) {
	__imp__sub_822DF95C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DF960) {
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
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822DF968;
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
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// vaddfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v58,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// lfs f11,4(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// addi r5,r7,2560
	ctx.r5.s64 = ctx.r7.s64 + 2560;
	// lfs f9,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lhz r10,7168(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 7168);
	// addi r7,r3,2240
	ctx.r7.s64 = ctx.r3.s64 + 2240;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r11,-31664
	ctx.r5.s64 = r11.s64 + -31664;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,-31648
	ctx.r4.s64 = ctx.r6.s64 + -31648;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,3104
	ctx.r3.s64 = 3104;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lis r12,0
	r12.s64 = 0;
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// ori r12,r12,62716
	r12.u64 = r12.u64 | 62716;
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fsubs f8,f0,f11
	ctx.f8.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f7,f13,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fsubs f5,f12,f9
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f9.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v12,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// and r28,r10,r12
	r28.u64 = ctx.r10.u64 & r12.u64;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r31,r3
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,92(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v54,v57,v1
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(ctx.v1.f32)));
	// vspltw128 v126,v1,3
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x0));
	// vsubfp128 v55,v1,v57
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v57.f32)));
	// vmsum3fp128 v52,v54,v54
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vand128 v53,v55,v61
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vmsum3fp128 v51,v53,v53
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vrsqrtefp128 v50,v52
	simde_mm_store_ps(v50.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v52.f32))));
	// vor128 v11,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vrsqrtefp128 v49,v51
	simde_mm_store_ps(v49.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v51.f32))));
	// vor128 v10,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// vcmpeqfp128 v9,v50,v62
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v8,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vcmpeqfp128 v7,v49,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v6,v49,v49
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v6,v13,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v4,v63,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v3,v13,v13
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v2,v63,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v31,v11,v5,v12
	simde_mm_store_ps(v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v30,v10,v3,v12
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v29,v31,v4,v0
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v28,v30,v2,v13
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v48,v52,v29
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v29.f32)));
	// vmulfp128 v47,v51,v28
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v28.f32)));
	// vspltw128 v46,v48,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vsubfp128 v127,v46,v126
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v126.f32)));
	// vspltw128 v45,v47,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// vsubfp128 v125,v45,v126
	simde_mm_store_ps(v125.f32, simde_mm_sub_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v126.f32)));
	// vcmpgtfp128. v44,v56,v127
	simde_mm_store_ps(v44.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v44.f32), 0xF);
	// mfocrf r27,2
	r27.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// li r11,3088
	r11.s64 = 3088;
	// lvx128 v43,r31,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v42,v43,v127
	simde_mm_store_ps(v42.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v42.f32), 0xF);
	// mfocrf r26,2
	r26.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822dfbec
	if (cr6.eq) goto loc_822DFBEC;
	// lbz r11,7170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 7170);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dfb2c
	if (cr6.eq) goto loc_822DFB2C;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8217c148
	ctx.lr = 0x822DFB1C;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822dfbe4
	if (cr6.eq) goto loc_822DFBE4;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822DFB2C:
	// lbz r11,3192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dfb74
	if (cr6.eq) goto loc_822DFB74;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v2,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82174678
	ctx.lr = 0x822DFB48;
	sub_82174678(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r31,7192
	ctx.r3.s64 = r31.s64 + 7192;
	// lbz r8,7170(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 7170);
	// lwz r7,7184(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 7184);
	// lwz r6,7180(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 7180);
	// lwz r4,7172(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 7172);
	// bl 0x821747e8
	ctx.lr = 0x822DFB64;
	sub_821747E8(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// b 0x822dfb84
	goto loc_822DFB84;
loc_822DFB74:
	// addi r3,r31,7192
	ctx.r3.s64 = r31.s64 + 7192;
	// lwz r5,7176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 7176);
	// lwz r4,7172(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 7172);
	// bl 0x82174550
	ctx.lr = 0x822DFB84;
	sub_82174550(ctx, base);
loc_822DFB84:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dfbe4
	if (cr6.eq) goto loc_822DFBE4;
	// li r11,3152
	r11.s64 = 3152;
	// lvx128 v41,r31,r11
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v40,v127,v41
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v40.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v41.f32)));
	cr6.setFromMask(simde_mm_load_ps(v40.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// li r9,3168
	ctx.r9.s64 = 3168;
	// lvx128 v39,r31,r9
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v38,v127,v39
	simde_mm_store_ps(v38.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v39.f32)));
	cr6.setFromMask(simde_mm_load_ps(v38.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// not r7,r10
	ctx.r7.u64 = ~ctx.r10.u64;
	// lhz r6,7168(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 7168);
	// not r5,r8
	ctx.r5.u64 = ~ctx.r8.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwimi r7,r5,3,21,21
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r5.u32, 3) & 0x400) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFBFF);
	// clrlwi r3,r28,16
	ctx.r3.u64 = r28.u32 & 0xFFFF;
	// rlwinm r11,r7,1,20,23
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xF00;
	// rlwinm r11,r11,0,23,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF9FF;
	// lvx128 v1,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// and r10,r11,r6
	ctx.r10.u64 = r11.u64 & ctx.r6.u64;
	// or r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 | ctx.r3.u64;
	// ori r28,r9,2
	r28.u64 = ctx.r9.u64 | 2;
	// b 0x822dfbec
	goto loc_822DFBEC;
loc_822DFBE4:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822DFBEC:
	// li r11,3120
	r11.s64 = 3120;
	// lvx128 v37,r31,r11
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v36,v125,v37
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v36.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v37.f32)));
	cr6.setFromMask(simde_mm_load_ps(v36.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// not r9,r10
	ctx.r9.u64 = ~ctx.r10.u64;
	// clrlwi r8,r28,16
	ctx.r8.u64 = r28.u32 & 0xFFFF;
	// rlwinm r7,r9,2,22,22
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x200;
	// rlwinm r6,r27,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x80;
	// or r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 | ctx.r8.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// clrlwi r30,r5,16
	r30.u64 = ctx.r5.u32 & 0xFFFF;
	// beq cr6,0x822dfcb0
	if (cr6.eq) goto loc_822DFCB0;
	// addi r11,r31,2992
	r11.s64 = r31.s64 + 2992;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v34,v35,v1
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(ctx.v1.f32), 0xEF));
	// vspltw128 v33,v35,3
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0x0));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// vsubfp128 v63,v34,v33
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v33.f32)));
	// vxor128 v32,v63,v63
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_setzero_si128());
	// vsubfp128 v61,v32,v63
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v63.f32)));
	// vmaxfp128 v60,v63,v61
	simde_mm_store_ps(v60.f32, simde_mm_max_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// vsubfp128 v59,v60,v126
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v126.f32)));
	// vcmpgtfp128. v58,v59,v62
	simde_mm_store_ps(v58.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	cr6.setFromMask(simde_mm_load_ps(v58.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822dfc84
	if (cr6.eq) goto loc_822DFC84;
	// vcmpgtfp128. v57,v62,v63
	simde_mm_store_ps(v57.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v57.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// clrlwi r9,r30,16
	ctx.r9.u64 = r30.u32 & 0xFFFF;
	// subfic r8,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r10.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r7,0,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r6,r11,-5
	ctx.r6.s64 = r11.s64 + -5;
	// and r30,r6,r9
	r30.u64 = ctx.r6.u64 & ctx.r9.u64;
loc_822DFC84:
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// bl 0x8217c148
	ctx.lr = 0x822DFC8C;
	sub_8217C148(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r30,r30,r7
	r30.u64 = r30.u64 & ~ctx.r7.u64;
	// b 0x822dfcb8
	goto loc_822DFCB8;
loc_822DFCB0:
	// clrlwi r30,r30,16
	r30.u64 = r30.u32 & 0xFFFF;
	// rlwinm r30,r30,0,30,27
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
loc_822DFCB8:
	// rlwinm r11,r30,0,21,21
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x400;
	// clrlwi r28,r30,16
	r28.u64 = r30.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dfd14
	if (cr6.eq) goto loc_822DFD14;
	// addi r29,r31,2000
	r29.s64 = r31.s64 + 2000;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217c148
	ctx.lr = 0x822DFCD4;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822dfd0c
	if (cr6.eq) goto loc_822DFD0C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3188(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3188);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822dfd14
	if (!cr6.gt) goto loc_822DFD14;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82174c08
	ctx.lr = 0x822DFD00;
	sub_82174C08(ctx, base);
	// lfs f0,3188(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3188);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822dfd14
	if (!cr6.lt) goto loc_822DFD14;
loc_822DFD0C:
	// clrlwi r30,r28,16
	r30.u64 = r28.u32 & 0xFFFF;
	// rlwinm r30,r30,0,22,20
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFFFFFFFBFF;
loc_822DFD14:
	// rlwinm r11,r26,0,24,24
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dfd40
	if (cr6.eq) goto loc_822DFD40;
	// addi r6,r31,3072
	ctx.r6.s64 = r31.s64 + 3072;
	// lwz r3,3184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 3184);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// bl 0x825f3f90
	ctx.lr = 0x822DFD34;
	sub_825F3F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dfd4c
	if (cr6.eq) goto loc_822DFD4C;
loc_822DFD40:
	// clrlwi r3,r30,16
	ctx.r3.u64 = r30.u32 & 0xFFFF;
	// rlwinm r3,r3,0,28,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// b 0x822dffbc
	goto loc_822DFFBC;
loc_822DFD4C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// rlwinm r28,r30,0,24,24
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x80;
	// li r3,976
	ctx.r3.s64 = 976;
	// li r4,960
	ctx.r4.s64 = 960;
	// clrlwi r29,r30,16
	r29.u64 = r30.u32 & 0xFFFF;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,912
	ctx.r5.s64 = 912;
	// li r6,896
	ctx.r6.s64 = 896;
	// li r7,944
	ctx.r7.s64 = 944;
	// li r8,880
	ctx.r8.s64 = 880;
	// li r9,928
	ctx.r9.s64 = 928;
	// li r10,864
	ctx.r10.s64 = 864;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822dfe04
	if (cr6.eq) goto loc_822DFE04;
	// addi r11,r31,6176
	r11.s64 = r31.s64 + 6176;
	// vspltw128 v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v13,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v56,v63,3
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vspltisw128 v55,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r11,r3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v54,-1
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v10,r11,r4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r11,r5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v53,v55,v56
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// vmaddfp v6,v0,v7,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v5,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v5,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v31,v13,v4,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v29,v12,v2,v31
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v31.f32)));
	// vcmpgefp128 v52,v30,v53
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v53.f32)));
	// vcmpgefp128 v51,v29,v53
	simde_mm_store_ps(v51.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v53.f32)));
	// vand128 v50,v51,v52
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vcmpequw128. v49,v50,v54
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	cr6.setFromMask(simde_mm_load_ps(v49.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822dfe04
	if (!cr6.eq) goto loc_822DFE04;
	// clrlwi r30,r29,16
	r30.u64 = r29.u32 & 0xFFFF;
	// rlwinm r30,r30,0,25,23
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
loc_822DFE04:
	// rlwinm r11,r30,0,25,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x40;
	// clrlwi r29,r30,16
	r29.u64 = r30.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dfe94
	if (cr6.eq) goto loc_822DFE94;
	// addi r11,r31,5184
	r11.s64 = r31.s64 + 5184;
	// vspltw128 v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v13,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v48,v63,3
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vspltisw128 v47,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r11,r3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v46,-1
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v10,r11,r4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r11,r5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v45,v47,v48
	simde_mm_store_ps(v45.f32, simde_mm_sub_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v48.f32)));
	// vmaddfp v6,v0,v7,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v5,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v5,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v31,v13,v4,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v29,v12,v2,v31
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v31.f32)));
	// vcmpgefp128 v44,v30,v45
	simde_mm_store_ps(v44.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v45.f32)));
	// vcmpgefp128 v43,v29,v45
	simde_mm_store_ps(v43.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v45.f32)));
	// vand128 v42,v43,v44
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v44.u8)));
	// vcmpequw128. v41,v42,v46
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	cr6.setFromMask(simde_mm_load_ps(v41.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822dfe94
	if (!cr6.eq) goto loc_822DFE94;
	// clrlwi r30,r29,16
	r30.u64 = r29.u32 & 0xFFFF;
	// rlwinm r30,r30,0,26,24
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
loc_822DFE94:
	// rlwinm r11,r30,0,26,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x20;
	// clrlwi r29,r30,16
	r29.u64 = r30.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dff24
	if (cr6.eq) goto loc_822DFF24;
	// addi r11,r31,4192
	r11.s64 = r31.s64 + 4192;
	// vspltw128 v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v13,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v40,v63,3
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vspltisw128 v39,0
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r11,r3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v38,-1
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v10,r11,r4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r11,r5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v37,v39,v40
	simde_mm_store_ps(v37.f32, simde_mm_sub_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32)));
	// vmaddfp v6,v0,v7,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v5,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v5,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v31,v13,v4,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v29,v12,v2,v31
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v31.f32)));
	// vcmpgefp128 v36,v30,v37
	simde_mm_store_ps(v36.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v37.f32)));
	// vcmpgefp128 v35,v29,v37
	simde_mm_store_ps(v35.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v37.f32)));
	// vand128 v34,v35,v36
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v36.u8)));
	// vcmpequw128. v33,v34,v38
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	cr6.setFromMask(simde_mm_load_ps(v33.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822dff24
	if (!cr6.eq) goto loc_822DFF24;
	// clrlwi r30,r29,16
	r30.u64 = r29.u32 & 0xFFFF;
	// rlwinm r30,r30,0,27,25
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
loc_822DFF24:
	// rlwinm r11,r30,0,27,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x10;
	// clrlwi r29,r30,16
	r29.u64 = r30.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822dffb8
	if (cr6.eq) goto loc_822DFFB8;
	// addi r11,r31,3200
	r11.s64 = r31.s64 + 3200;
	// vspltw128 v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v13,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v32,v63,3
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r11,r3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v10,r11,r4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r11,r5
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v32
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v32.f32)));
	// vmaddfp v6,v0,v7,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v5,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r11,r9
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v5,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v31,v13,v4,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v29,v12,v2,v31
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v31.f32)));
	// vcmpgefp128 v60,v30,v61
	simde_mm_store_ps(v60.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v61.f32)));
	// vcmpgefp128 v59,v29,v61
	simde_mm_store_ps(v59.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v61.f32)));
	// vand128 v58,v59,v60
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vcmpequw128. v57,v58,v62
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v57.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822dffb8
	if (!cr6.eq) goto loc_822DFFB8;
	// clrlwi r3,r29,16
	ctx.r3.u64 = r29.u32 & 0xFFFF;
	// rlwinm r3,r3,0,28,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// b 0x822dffbc
	goto loc_822DFFBC;
loc_822DFFB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822DFFBC:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
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
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822DF960) {
	__imp__sub_822DF960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DFFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822DFFDC) {
	__imp__sub_822DFFDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822DFFE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,86(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 86);
	// lhz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 84);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x822e00ac
	if (!cr6.lt) goto loc_822E00AC;
	// lhz r9,92(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 92);
	// addi r11,r3,88
	r11.s64 = ctx.r3.s64 + 88;
	// lhz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// lwz r10,88(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// addi r11,r3,80
	r11.s64 = ctx.r3.s64 + 80;
	// sth r7,92(r3)
	PPC_STORE_U16(ctx.r3.u32 + 92, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r10,96(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// lhz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// lhz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 100);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,100(r3)
	PPC_STORE_U16(ctx.r3.u32 + 100, ctx.r8.u16);
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r10,104(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// lhz r6,20(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// lhz r5,108(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 108);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// sth r11,108(r3)
	PPC_STORE_U16(ctx.r3.u32 + 108, r11.u16);
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// lhz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// lhz r6,116(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 116);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// rotlwi r9,r6,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,116(r3)
	PPC_STORE_U16(ctx.r3.u32 + 116, ctx.r5.u16);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lhz r8,36(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 36);
	// lhz r7,124(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 124);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rotlwi r11,r7,2
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,124(r3)
	PPC_STORE_U16(ctx.r3.u32 + 124, ctx.r6.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lhz r11,84(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 84);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,84(r3)
	PPC_STORE_U16(ctx.r3.u32 + 84, ctx.r9.u16);
	// stwx r4,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r4.u32);
loc_822E00AC:
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r10,148(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x822e00c0
	if (cr6.gt) goto loc_822E00C0;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822E00C0:
	// stw r10,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r10.u32);
	// lwz r11,172(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// lwz r10,152(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x822e00d8
	if (cr6.gt) goto loc_822E00D8;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822E00D8:
	// stw r10,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r10.u32);
	// lwz r11,176(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// lwz r10,156(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x822e00f0
	if (cr6.gt) goto loc_822E00F0;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822E00F0:
	// stw r10,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r10.u32);
	// lwz r11,180(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x822e0108
	if (cr6.gt) goto loc_822E0108;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822E0108:
	// stw r10,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r10.u32);
	// lwz r11,184(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r10,164(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x822e0124
	if (!cr6.gt) goto loc_822E0124;
	// stw r10,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r10.u32);
	// blr 
	return;
loc_822E0124:
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822DFFE0) {
	__imp__sub_822DFFE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E012C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E012C) {
	__imp__sub_822E012C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0130) {
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
	ctx.lr = 0x822E0138;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r10,r31,168
	ctx.r10.s64 = r31.s64 + 168;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
	// ble cr6,0x822e0214
	if (!cr6.gt) goto loc_822E0214;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
loc_822E0174:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822df960
	ctx.lr = 0x822E0180;
	sub_822DF960(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e0204
	if (cr6.eq) goto loc_822E0204;
	// ld r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,3,26,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x38;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// clrlwi r6,r11,29
	ctx.r6.u64 = r11.u32 & 0x7;
	// lhz r11,6(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bge cr6,0x822e01f0
	if (!cr6.lt) goto loc_822E01F0;
	// addi r4,r6,5
	ctx.r4.s64 = ctx.r6.s64 + 5;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// sth r7,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r7.u16);
	// sthx r3,r9,r8
	PPC_STORE_U16(ctx.r9.u32 + ctx.r8.u32, ctx.r3.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r10,r3,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 3);
	// addi r8,r3,1
	ctx.r8.s64 = ctx.r3.s64 + 1;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// stdx r5,r10,r9
	PPC_STORE_U64(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u64);
loc_822E01F0:
	// addi r11,r6,42
	r11.s64 = ctx.r6.s64 + 42;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
loc_822E0204:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,32
	r29.s64 = r29.s64 + 32;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x822e0174
	if (!cr0.eq) goto loc_822E0174;
loc_822E0214:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,7188(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 7188);
	// bl 0x822dffe0
	ctx.lr = 0x822E0220;
	sub_822DFFE0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822E0130) {
	__imp__sub_822E0130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0228) {
	PPC_FUNC_PROLOGUE();
	// b 0x822e0130
	sub_822E0130(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822E0228) {
	__imp__sub_822E0228(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E022C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E022C) {
	__imp__sub_822E022C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0230) {
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
	ctx.lr = 0x822E0238;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// lwz r11,-9052(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -9052);
	// lwz r4,432(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 432);
	// bl 0x822bff40
	ctx.lr = 0x822E0254;
	sub_822BFF40(ctx, base);
	// lis r29,-32130
	r29.s64 = -2105671680;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// lwz r11,22080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 22080);
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x822bff40
	ctx.lr = 0x822E0278;
	sub_822BFF40(ctx, base);
	// lwz r11,22080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 22080);
	// li r8,240
	ctx.r8.s64 = 240;
	// lwz r10,-8092(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v63,r7,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-9052(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -9052);
	// bl 0x82339370
	ctx.lr = 0x822E02A0;
	sub_82339370(ctx, base);
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,48
	ctx.r5.s64 = 48;
	// lvx128 v62,r3,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lvx128 v61,r3,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,3528
	ctx.r10.s64 = r11.s64 + 3528;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,3024
	r11.s64 = r31.s64 + 3024;
	// lfs f11,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f10.f64 = double(temp.f32);
	// lwz r9,-18004(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -18004);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f0.f64 = double(temp.f32);
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f8,f0,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fmadds f7,f10,f11,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f8.f64));
	// stfs f12,2996(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 2996, temp.u32);
	// stfs f13,2992(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 2992, temp.u32);
	// lwz r9,32(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// stfs f11,3000(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 3000, temp.u32);
	// lfs f0,-31068(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31068);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fmadds f6,f9,f13,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f6,3004(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 3004, temp.u32);
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmr f5,f13
	ctx.f5.f64 = ctx.f13.f64;
	// stfs f13,3020(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3020, temp.u32);
	// stfs f5,3016(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 3016, temp.u32);
	// stfs f5,3012(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 3012, temp.u32);
	// stfs f5,3008(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 3008, temp.u32);
	// lfs f13,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fmr f4,f13
	ctx.f4.f64 = ctx.f13.f64;
	// stfs f13,3052(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3052, temp.u32);
	// stfs f4,3048(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 3048, temp.u32);
	// stfs f4,3044(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 3044, temp.u32);
	// stfs f4,3040(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 3040, temp.u32);
	// lfs f13,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fmr f3,f13
	ctx.f3.f64 = ctx.f13.f64;
	// stfs f13,3068(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3068, temp.u32);
	// stfs f3,3064(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 3064, temp.u32);
	// stfs f3,3060(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 3060, temp.u32);
	// stfs f3,3056(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 3056, temp.u32);
	// stfs f0,3036(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3036, temp.u32);
	// stfs f0,3032(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3032, temp.u32);
	// stfs f0,3028(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3028, temp.u32);
	// stfs f0,3024(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3024, temp.u32);
	// beq cr6,0x822e03a0
	if (cr6.eq) goto loc_822E03A0;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822e03a0
	if (cr6.eq) goto loc_822E03A0;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f13,80(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,12(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f12,8(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f12,4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_822E03A0:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lfs f0,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f0.f64 = double(temp.f32);
	// li r10,16
	ctx.r10.s64 = 16;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// stfs f0,3148(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3148, temp.u32);
	// li r9,3072
	ctx.r9.s64 = 3072;
	// stfs f13,3144(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3144, temp.u32);
	// lis r30,-32119
	r30.s64 = -2104950784;
	// stfs f13,3140(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3140, temp.u32);
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// stfs f13,3136(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 3136, temp.u32);
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-11596(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11596);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822e03f0
	if (cr6.eq) goto loc_822E03F0;
	// rotlwi r4,r8,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// b 0x822e03f4
	goto loc_822E03F4;
loc_822E03F0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_822E03F4:
	// addi r3,r31,3200
	ctx.r3.s64 = r31.s64 + 3200;
	// bl 0x822bff40
	ctx.lr = 0x822E03FC;
	sub_822BFF40(ctx, base);
	// lwz r11,-11596(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11596);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e0418
	if (cr6.eq) goto loc_822E0418;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// b 0x822e041c
	goto loc_822E041C;
loc_822E0418:
	// li r4,0
	ctx.r4.s64 = 0;
loc_822E041C:
	// addi r3,r31,4192
	ctx.r3.s64 = r31.s64 + 4192;
	// bl 0x822bff40
	ctx.lr = 0x822E0424;
	sub_822BFF40(ctx, base);
	// lwz r11,-11596(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11596);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e0440
	if (cr6.eq) goto loc_822E0440;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// b 0x822e0444
	goto loc_822E0444;
loc_822E0440:
	// li r4,0
	ctx.r4.s64 = 0;
loc_822E0444:
	// addi r3,r31,5184
	ctx.r3.s64 = r31.s64 + 5184;
	// bl 0x822bff40
	ctx.lr = 0x822E044C;
	sub_822BFF40(ctx, base);
	// lwz r11,-11596(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -11596);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e0468
	if (cr6.eq) goto loc_822E0468;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// b 0x822e046c
	goto loc_822E046C;
loc_822E0468:
	// li r4,0
	ctx.r4.s64 = 0;
loc_822E046C:
	// addi r3,r31,6176
	ctx.r3.s64 = r31.s64 + 6176;
	// bl 0x822bff40
	ctx.lr = 0x822E0474;
	sub_822BFF40(ctx, base);
	// lis r30,-32119
	r30.s64 = -2104950784;
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// lwz r11,-12284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12284);
	// lwz r4,44(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// bl 0x822bff40
	ctx.lr = 0x822E0488;
	sub_822BFF40(ctx, base);
	// lwz r11,-12284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12284);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f0,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	f0.f64 = double(temp.f32);
	// stfs f0,3188(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3188, temp.u32);
	// lwz r11,6628(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 6628);
	// stw r11,3184(r31)
	PPC_STORE_U32(r31.u32 + 3184, r11.u32);
	// lbz r11,3996(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 3996);
	// stb r11,3192(r31)
	PPC_STORE_U8(r31.u32 + 3192, r11.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822E0230) {
	__imp__sub_822E0230(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E04B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E04B4) {
	__imp__sub_822E04B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E04B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e05d0
	if (!cr6.eq) goto loc_822E05D0;
	// lfs f10,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f9,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f12,f10
	ctx.f8.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// lfs f0,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f7,f11,f9
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f6,f10,f0
	ctx.f6.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f5,f9,f13
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fmuls f4,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// fmuls f3,f5,f8
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// fcmpu cr6,f3,f4
	cr6.compare(ctx.f3.f64, ctx.f4.f64);
	// blt cr6,0x822e0504
	if (cr6.lt) goto loc_822E0504;
	// li r9,0
	ctx.r9.s64 = 0;
loc_822E0504:
	// lfs f10,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r4,8
	r11.s64 = ctx.r4.s64 + 8;
	// lfs f9,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f7,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f9,f13
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f5,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f7,f10
	ctx.f4.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fsubs f3,f5,f9
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f9.f64));
	// li r10,1
	ctx.r10.s64 = 1;
	// fmuls f2,f6,f4
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f4.f64));
	// fmuls f1,f8,f3
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f3.f64));
	// fcmpu cr6,f2,f1
	cr6.compare(ctx.f2.f64, ctx.f1.f64);
	// blt cr6,0x822e0540
	if (cr6.lt) goto loc_822E0540;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822E0540:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x822e05c8
	if (cr6.eq) goto loc_822E05C8;
	// lfs f10,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f10
	ctx.f8.f64 = double(float(f0.f64 - ctx.f10.f64));
	// fsubs f7,f13,f9
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fsubs f6,f10,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsubs f5,f9,f11
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// fmuls f4,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// fmuls f3,f5,f8
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// fcmpu cr6,f3,f4
	cr6.compare(ctx.f3.f64, ctx.f4.f64);
	// blt cr6,0x822e0580
	if (cr6.lt) goto loc_822E0580;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822E0580:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f10,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f8,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// li r11,1
	r11.s64 = 1;
	// fmuls f5,f7,f9
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// fmuls f4,f12,f6
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// fcmpu cr6,f5,f4
	cr6.compare(ctx.f5.f64, ctx.f4.f64);
	// blt cr6,0x822e05b8
	if (cr6.lt) goto loc_822E05B8;
	// li r11,0
	r11.s64 = 0;
loc_822E05B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x822e05d0
	if (!cr6.eq) goto loc_822E05D0;
loc_822E05C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822E05D0:
	// lfs f10,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f9,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f0,f10,f8
	f0.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fsubs f13,f7,f9
	ctx.f13.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// lfs f6,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lfs f5,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f12,f4,f6
	ctx.f12.f64 = double(float(ctx.f4.f64 - ctx.f6.f64));
	// lfs f3,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f11,f5,f3
	ctx.f11.f64 = double(float(ctx.f5.f64 - ctx.f3.f64));
	// lfs f7,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f1,f5,f13
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fmuls f8,f10,f12
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmsubs f10,f11,f12,f2
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 - ctx.f2.f64));
	// fmadds f9,f9,f11,f1
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + ctx.f1.f64));
	// fmadds f8,f6,f0,f8
	ctx.f8.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f8.f64));
	// fcmpu cr6,f10,f7
	cr6.compare(ctx.f10.f64, ctx.f7.f64);
	// beq cr6,0x822e0654
	if (cr6.eq) goto loc_822E0654;
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f6,f13,f8
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f5,f0,f10
	ctx.f5.f64 = double(float(f0.f64 / ctx.f10.f64));
	// fmsubs f4,f11,f8,f7
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f8.f64 - ctx.f7.f64));
	// fmsubs f3,f9,f12,f6
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 - ctx.f6.f64));
	// fmuls f2,f4,f5
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f5.f64));
	// stfs f2,0(r5)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fmuls f1,f3,f5
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f5.f64));
	// stfs f1,4(r5)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
loc_822E0654:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822E04B8) {
	__imp__sub_822E04B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E065C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E065C) {
	__imp__sub_822E065C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-11724(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -11724);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822E0660) {
	__imp__sub_822E0660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E066C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E066C) {
	__imp__sub_822E066C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0670) {
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
	// addi r10,r11,-9420
	ctx.r10.s64 = r11.s64 + -9420;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,10(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e06ac
	if (cr6.eq) goto loc_822E06AC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822E06AC;
	sub_82130588(ctx, base);
loc_822E06AC:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e06c4
	if (cr6.eq) goto loc_822E06C4;
	// bl 0x82130588
	ctx.lr = 0x822E06C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E06C4:
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

PPC_WEAK_FUNC(sub_822E0670) {
	__imp__sub_822E0670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E06DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E06DC) {
	__imp__sub_822E06DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E06E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r10,-9408
	ctx.r7.s64 = ctx.r10.s64 + -9408;
	// addi r6,r9,-9420
	ctx.r6.s64 = ctx.r9.s64 + -9420;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// sth r11,56(r3)
	PPC_STORE_U16(ctx.r3.u32 + 56, r11.u16);
	// sth r11,58(r3)
	PPC_STORE_U16(ctx.r3.u32 + 58, r11.u16);
	// stfs f0,60(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822E06E0) {
	__imp__sub_822E06E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E0724) {
	__imp__sub_822E0724(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-11720(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -11720);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822E0728) {
	__imp__sub_822E0728(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E0734) {
	__imp__sub_822E0734(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0738) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r10,-9408
	ctx.r8.s64 = ctx.r10.s64 + -9408;
	// addi r7,r9,-9420
	ctx.r7.s64 = ctx.r9.s64 + -9420;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r7,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r7.u32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// lhz r6,58(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822e0784
	if (cr6.eq) goto loc_822E0784;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x822E0784;
	sub_82130588(ctx, base);
loc_822E0784:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e079c
	if (cr6.eq) goto loc_822E079C;
	// bl 0x82130588
	ctx.lr = 0x822E0798;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822E079C:
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

PPC_WEAK_FUNC(sub_822E0738) {
	__imp__sub_822E0738(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E07B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E07B4) {
	__imp__sub_822E07B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E07B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,32
	r11.s64 = 32;
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// lhz r30,56(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// li r3,0
	ctx.r3.s64 = 0;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// vsubfp128 v62,v1,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v63.f32)));
	// lfs f13,7444(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822e07f8
	if (cr6.eq) goto loc_822E07F8;
	// lfs f13,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
loc_822E07F8:
	// lfs f0,-24(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f8,-32(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f8.f64 = double(temp.f32);
	// addi r8,r30,-1
	ctx.r8.s64 = r30.s64 + -1;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x822e09f0
	if (cr6.lt) goto loc_822E09F0;
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r6,r30,-3
	ctx.r6.s64 = r30.s64 + -3;
	// rlwinm r9,r8,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r7,40
	r11.s64 = ctx.r7.s64 + 40;
	// subfic r5,r7,8
	xer.ca = ctx.r7.u32 <= 8;
	ctx.r5.s64 = 8 - ctx.r7.s64;
loc_822E0824:
	// lfs f12,-32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfsx f11,r9,r7
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	ctx.f11.f64 = double(temp.f32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lfs f10,-40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -40);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f10,f10,f13
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f7,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f11,f7,f13
	ctx.f11.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x822e0858
	if (cr6.gt) goto loc_822E0858;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// blt cr6,0x822e0868
	if (cr6.lt) goto loc_822E0868;
loc_822E0858:
	// fcmpu cr6,f11,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x822e0894
	if (cr6.gt) goto loc_822E0894;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x822e0894
	if (!cr6.lt) goto loc_822E0894;
loc_822E0868:
	// fsubs f7,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f6,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fsubs f5,f11,f12
	ctx.f5.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmuls f4,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fdivs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
	// fadds f2,f3,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f10.f64));
	// fcmpu cr6,f8,f2
	cr6.compare(ctx.f8.f64, ctx.f2.f64);
	// bge cr6,0x822e0894
	if (!cr6.lt) goto loc_822E0894;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_822E0894:
	// lfs f12,-16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f11,-40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -40);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f7,-24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -24);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f11,f10,f13
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f10,f13,f7
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x822e08c4
	if (cr6.gt) goto loc_822E08C4;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// blt cr6,0x822e08d4
	if (cr6.lt) goto loc_822E08D4;
loc_822E08C4:
	// fcmpu cr6,f11,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x822e0900
	if (cr6.gt) goto loc_822E0900;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x822e0900
	if (!cr6.lt) goto loc_822E0900;
loc_822E08D4:
	// fsubs f7,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f6,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fsubs f5,f11,f12
	ctx.f5.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmuls f4,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fdivs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
	// fadds f2,f3,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f10.f64));
	// fcmpu cr6,f8,f2
	cr6.compare(ctx.f8.f64, ctx.f2.f64);
	// bge cr6,0x822e0900
	if (!cr6.lt) goto loc_822E0900;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_822E0900:
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f11,-24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// lfs f7,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f11,f13,f10
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmuls f10,f13,f7
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x822e0930
	if (cr6.gt) goto loc_822E0930;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// blt cr6,0x822e0940
	if (cr6.lt) goto loc_822E0940;
loc_822E0930:
	// fcmpu cr6,f11,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x822e096c
	if (cr6.gt) goto loc_822E096C;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x822e096c
	if (!cr6.lt) goto loc_822E096C;
loc_822E0940:
	// fsubs f7,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f6,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fsubs f5,f11,f12
	ctx.f5.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmuls f4,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fdivs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
	// fadds f2,f3,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f10.f64));
	// fcmpu cr6,f8,f2
	cr6.compare(ctx.f8.f64, ctx.f2.f64);
	// bge cr6,0x822e096c
	if (!cr6.lt) goto loc_822E096C;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_822E096C:
	// lfs f12,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f9,f13,f9
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// fmuls f11,f13,f7
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x822e099c
	if (cr6.gt) goto loc_822E099C;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// blt cr6,0x822e09ac
	if (cr6.lt) goto loc_822E09AC;
loc_822E099C:
	// fcmpu cr6,f11,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x822e09d8
	if (cr6.gt) goto loc_822E09D8;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x822e09d8
	if (!cr6.lt) goto loc_822E09D8;
loc_822E09AC:
	// fsubs f7,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f6,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fsubs f5,f11,f12
	ctx.f5.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmuls f4,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fdivs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
	// fadds f2,f3,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f10.f64));
	// fcmpu cr6,f8,f2
	cr6.compare(ctx.f8.f64, ctx.f2.f64);
	// bge cr6,0x822e09d8
	if (!cr6.lt) goto loc_822E09D8;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_822E09D8:
	// addi r8,r10,3
	ctx.r8.s64 = ctx.r10.s64 + 3;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// add r9,r5,r11
	ctx.r9.u64 = ctx.r5.u64 + r11.u64;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x822e0824
	if (cr6.lt) goto loc_822E0824;
loc_822E09F0:
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// bge cr6,0x822e0a8c
	if (!cr6.lt) goto loc_822E0A8C;
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r11,r10,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r8,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
loc_822E0A08:
	// lfs f12,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// add r8,r7,r9
	ctx.r8.u64 = ctx.r7.u64 + ctx.r9.u64;
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f9,r7,r9
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f9,f9,f13
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// lfs f7,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f11,f7,f13
	ctx.f11.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x822e0a3c
	if (cr6.gt) goto loc_822E0A3C;
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// blt cr6,0x822e0a4c
	if (cr6.lt) goto loc_822E0A4C;
loc_822E0A3C:
	// fcmpu cr6,f11,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x822e0a78
	if (cr6.gt) goto loc_822E0A78;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x822e0a78
	if (!cr6.lt) goto loc_822E0A78;
loc_822E0A4C:
	// fsubs f7,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f6,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fsubs f5,f11,f12
	ctx.f5.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmuls f4,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fdivs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 / ctx.f5.f64));
	// fadds f2,f3,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f10.f64));
	// fcmpu cr6,f8,f2
	cr6.compare(ctx.f8.f64, ctx.f2.f64);
	// bge cr6,0x822e0a78
	if (!cr6.lt) goto loc_822E0A78;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_822E0A78:
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// blt cr6,0x822e0a08
	if (cr6.lt) goto loc_822E0A08;
loc_822E0A8C:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822E07B8) {
	__imp__sub_822E07B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0A98) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822E0AA0;
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f29.u64);
	// stfd f30,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,32
	r11.s64 = 32;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r29,56(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// li r7,0
	ctx.r7.s64 = 0;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v1,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v63.f32)));
	// addi r30,r29,-1
	r30.s64 = r29.s64 + -1;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x822e0b84
	if (!cr6.gt) goto loc_822E0B84;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f30.f64 = double(temp.f32);
	// lfs f29,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f29.f64 = double(temp.f32);
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_822E0AFC:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	f0.f64 = double(temp.f32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + r11.u64;
	// stfs f29,88(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f30,92(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lfsx f13,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfsx f12,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f10,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f0,f12
	ctx.f9.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f8,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f7,108(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x822e04b8
	ctx.lr = 0x822E0B60;
	sub_822E04B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e0b9c
	if (!cr6.eq) goto loc_822E0B9C;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// cmpw cr6,r7,r29
	cr6.compare<int32_t>(ctx.r7.s32, r29.s32, xer);
	// blt cr6,0x822e0afc
	if (cr6.lt) goto loc_822E0AFC;
loc_822E0B84:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_822E0B9C:
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r30,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stfs f29,104(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f30,108(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x822e04b8
	ctx.lr = 0x822E0BF4;
	sub_822E04B8(ctx, base);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

PPC_WEAK_FUNC(sub_822E0A98) {
	__imp__sub_822E0A98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0C0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E0C0C) {
	__imp__sub_822E0C0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0C10) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// blt cr6,0x822e0d24
	if (cr6.lt) goto loc_822E0D24;
	// bne cr6,0x822e0d08
	if (!cr6.eq) goto loc_822E0D08;
	// lhz r11,56(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x822e0d08
	if (cr6.lt) goto loc_822E0D08;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822e07b8
	ctx.lr = 0x822E0C48;
	sub_822E07B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e0c70
	if (cr6.eq) goto loc_822E0C70;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
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
loc_822E0C70:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e07b8
	ctx.lr = 0x822E0C7C;
	sub_822E07B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e0d08
	if (cr6.eq) goto loc_822E0D08;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e0a98
	ctx.lr = 0x822E0C98;
	sub_822E0A98(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f7,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f5,f12,f7
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fsubs f3,f0,f9
	ctx.f3.f64 = double(float(f0.f64 - ctx.f9.f64));
	// lfs f4,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f6,f0,f8
	ctx.f6.f64 = double(float(f0.f64 - ctx.f8.f64));
	// fsubs f2,f13,f4
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f4.f64));
	// fsubs f0,f13,f5
	f0.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
	// fmuls f13,f3,f3
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f3.f64));
	// fmuls f1,f6,f6
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fmadds f11,f0,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f12,f2,f2,f1
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f1.f64));
	// fsqrts f9,f11
	ctx.f9.f64 = double(float(sqrt(ctx.f11.f64)));
	// fsqrts f10,f12
	ctx.f10.f64 = double(float(sqrt(ctx.f12.f64)));
	// fdivs f1,f9,f10
	ctx.f1.f64 = double(float(ctx.f9.f64 / ctx.f10.f64));
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
loc_822E0D08:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
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
loc_822E0D24:
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v63,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v1.f32)));
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822e0d50
	if (!cr6.eq) goto loc_822E0D50;
	// fmr f10,f1
	ctx.f10.f64 = ctx.f1.f64;
	// b 0x822e0d54
	goto loc_822E0D54;
loc_822E0D50:
	// lfs f10,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
loc_822E0D54:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f8,f0,f0
	ctx.f8.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f0.f64 = double(temp.f32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f7,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f9,f7,f0
	ctx.f9.f64 = double(float(ctx.f7.f64 * f0.f64));
	// lfs f11,31292(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31292);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f6,f12,f12,f8
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fsubs f12,f0,f9
	ctx.f12.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fmadds f5,f10,f10,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f6.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// fsqrts f10,f5
	ctx.f10.f64 = double(float(sqrt(ctx.f5.f64)));
	// bge cr6,0x822e0d98
	if (!cr6.lt) goto loc_822E0D98;
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
loc_822E0D98:
	// fcmpu cr6,f10,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f10.f64, f0.f64);
	// bge cr6,0x822e0dc0
	if (!cr6.lt) goto loc_822E0DC0;
	// fcmpu cr6,f10,f9
	cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// ble cr6,0x822e0dbc
	if (!cr6.gt) goto loc_822E0DBC;
	// fsubs f0,f0,f10
	f0.f64 = double(float(f0.f64 - ctx.f10.f64));
	// fdivs f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 / ctx.f12.f64));
	// fsel f11,f12,f12,f1
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : ctx.f1.f64;
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsel f13,f10,f13,f11
	ctx.f13.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
loc_822E0DBC:
	// fmr f1,f13
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f13.f64;
loc_822E0DC0:
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

PPC_WEAK_FUNC(sub_822E0C10) {
	__imp__sub_822E0C10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E0DD4) {
	__imp__sub_822E0DD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0DD8) {
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
	ctx.lr = 0x822E0DEC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e0e20
	if (cr6.eq) goto loc_822E0E20;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-9420
	ctx.r9.s64 = ctx.r10.s64 + -9420;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822E0E20:
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

PPC_WEAK_FUNC(sub_822E0DD8) {
	__imp__sub_822E0DD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822E0E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822E0E34) {
	__imp__sub_822E0E34(ctx, base);
}

