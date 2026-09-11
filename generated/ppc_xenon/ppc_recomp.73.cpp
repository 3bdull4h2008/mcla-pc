#include "ppc_recomp_shared.h"

__attribute__((alias("__imp____restvmx_120"))) PPC_WEAK_FUNC(__restvmx_120);
PPC_FUNC_IMPL(__imp____restvmx_120) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v120{};
	PPCVRegister v121{};
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	// li r11,-128
	r11.s64 = -128;
	// lvx128 v120,r11,r12
	simde_mm_store_si128((simde__m128i*)v120.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	r11.s64 = -112;
	// lvx128 v121,r11,r12
	simde_mm_store_si128((simde__m128i*)v121.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	r11.s64 = -96;
	// lvx128 v122,r11,r12
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	r11.s64 = -80;
	// lvx128 v123,r11,r12
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	r11.s64 = -64;
	// lvx128 v124,r11,r12
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	r11.s64 = -48;
	// lvx128 v125,r11,r12
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	r11.s64 = -32;
	// lvx128 v126,r11,r12
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	r11.s64 = -16;
	// lvx128 v127,r11,r12
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_121"))) PPC_WEAK_FUNC(__restvmx_121);
PPC_FUNC_IMPL(__imp____restvmx_121) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v121{};
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	// li r11,-112
	r11.s64 = -112;
	// lvx128 v121,r11,r12
	simde_mm_store_si128((simde__m128i*)v121.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	r11.s64 = -96;
	// lvx128 v122,r11,r12
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	r11.s64 = -80;
	// lvx128 v123,r11,r12
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	r11.s64 = -64;
	// lvx128 v124,r11,r12
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	r11.s64 = -48;
	// lvx128 v125,r11,r12
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	r11.s64 = -32;
	// lvx128 v126,r11,r12
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	r11.s64 = -16;
	// lvx128 v127,r11,r12
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_122"))) PPC_WEAK_FUNC(__restvmx_122);
PPC_FUNC_IMPL(__imp____restvmx_122) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	// li r11,-96
	r11.s64 = -96;
	// lvx128 v122,r11,r12
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	r11.s64 = -80;
	// lvx128 v123,r11,r12
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	r11.s64 = -64;
	// lvx128 v124,r11,r12
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	r11.s64 = -48;
	// lvx128 v125,r11,r12
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	r11.s64 = -32;
	// lvx128 v126,r11,r12
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	r11.s64 = -16;
	// lvx128 v127,r11,r12
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_123"))) PPC_WEAK_FUNC(__restvmx_123);
PPC_FUNC_IMPL(__imp____restvmx_123) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	// li r11,-80
	r11.s64 = -80;
	// lvx128 v123,r11,r12
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	r11.s64 = -64;
	// lvx128 v124,r11,r12
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	r11.s64 = -48;
	// lvx128 v125,r11,r12
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	r11.s64 = -32;
	// lvx128 v126,r11,r12
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	r11.s64 = -16;
	// lvx128 v127,r11,r12
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_124"))) PPC_WEAK_FUNC(__restvmx_124);
PPC_FUNC_IMPL(__imp____restvmx_124) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	// li r11,-64
	r11.s64 = -64;
	// lvx128 v124,r11,r12
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	r11.s64 = -48;
	// lvx128 v125,r11,r12
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	r11.s64 = -32;
	// lvx128 v126,r11,r12
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	r11.s64 = -16;
	// lvx128 v127,r11,r12
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_125"))) PPC_WEAK_FUNC(__restvmx_125);
PPC_FUNC_IMPL(__imp____restvmx_125) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	// li r11,-48
	r11.s64 = -48;
	// lvx128 v125,r11,r12
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	r11.s64 = -32;
	// lvx128 v126,r11,r12
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	r11.s64 = -16;
	// lvx128 v127,r11,r12
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_126"))) PPC_WEAK_FUNC(__restvmx_126);
PPC_FUNC_IMPL(__imp____restvmx_126) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	// li r11,-32
	r11.s64 = -32;
	// lvx128 v126,r11,r12
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	r11.s64 = -16;
	// lvx128 v127,r11,r12
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_127"))) PPC_WEAK_FUNC(__restvmx_127);
PPC_FUNC_IMPL(__imp____restvmx_127) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v127{};
	// li r11,-16
	r11.s64 = -16;
	// lvx128 v127,r11,r12
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r12.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DD7F0"))) PPC_WEAK_FUNC(sub_823DD7F0);
PPC_FUNC_IMPL(__imp__sub_823DD7F0) {
	PPC_FUNC_PROLOGUE();
	// li r5,10
	ctx.r5.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823ddf20
	sub_823DDF20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DD7FC"))) PPC_WEAK_FUNC(sub_823DD7FC);
PPC_FUNC_IMPL(__imp__sub_823DD7FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DD800"))) PPC_WEAK_FUNC(sub_823DD800);
PPC_FUNC_IMPL(__imp__sub_823DD800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr1{};
	PPCRegister r0{};
	uint32_t ea{};
	// mr. r0,r5
	r0.u64 = ctx.r5.u64;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// ble 0x823dd844
	if (!cr0.gt) goto loc_823DD844;
	// lbz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmpwi cr1,r8,0
	cr1.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subfc. r3,r7,r8
	xer.ca = ctx.r8.u32 >= ctx.r7.u32;
	ctx.r3.s64 = ctx.r8.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bdnzf 4*cr1+eq,0x823dd828
	--ctr.u64;
	if (ctr.u32 != 0 && !cr1.eq) goto loc_823DD828;
	// blr 
	return;
loc_823DD828:
	// bnelr 
	if (!cr0.eq) return;
	// lbzu r8,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// cmpwi cr1,r8,0
	cr1.compare<int32_t>(ctx.r8.s32, 0, xer);
	// subfc. r3,r7,r8
	xer.ca = ctx.r8.u32 >= ctx.r7.u32;
	ctx.r3.s64 = ctx.r8.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bdnzf 4*cr1+eq,0x823dd828
	--ctr.u64;
	if (ctr.u32 != 0 && !cr1.eq) goto loc_823DD828;
	// blr 
	return;
loc_823DD844:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DD84C"))) PPC_WEAK_FUNC(sub_823DD84C);
PPC_FUNC_IMPL(__imp__sub_823DD84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DD850"))) PPC_WEAK_FUNC(sub_823DD850);
PPC_FUNC_IMPL(__imp__sub_823DD850) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr1{};
	uint32_t ea{};
	// lbz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmpwi r4,0
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq 0x823dd874
	if (cr0.eq) goto loc_823DD874;
loc_823DD85C:
	// cmpwi cr1,r6,0
	cr1.compare<int32_t>(ctx.r6.s32, 0, xer);
	// cmpw r6,r4
	cr0.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, xer);
	// beq cr1,0x823dd884
	if (cr1.eq) goto loc_823DD884;
	// beq 0x823dd888
	if (cr0.eq) goto loc_823DD888;
	// lbzu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// b 0x823dd85c
	goto loc_823DD85C;
loc_823DD874:
	// cmpwi r6,0
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq 0x823dd888
	if (cr0.eq) goto loc_823DD888;
	// lbzu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// b 0x823dd874
	goto loc_823DD874;
loc_823DD884:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DD888:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DD88C"))) PPC_WEAK_FUNC(sub_823DD88C);
PPC_FUNC_IMPL(__imp__sub_823DD88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DD890"))) PPC_WEAK_FUNC(sub_823DD890);
PPC_FUNC_IMPL(__imp__sub_823DD890) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9536(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9536);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823DD8A0;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cntlzw r11,r27
	r11.u64 = r27.u32 == 0 ? 32 : __builtin_clz(r27.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823dd8f4
	if (!cr6.eq) goto loc_823DD8F4;
loc_823DD8C8:
	// bl 0x823e1000
	ctx.lr = 0x823DD8CC;
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
	ctx.lr = 0x823DD8EC;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823dda10
	goto loc_823DDA10;
loc_823DD8F4:
	// bl 0x823e1160
	ctx.lr = 0x823DD8F8;
	sub_823E1160(ctx, base);
	// addi r30,r3,32
	r30.s64 = ctx.r3.s64 + 32;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823dd9d0
	if (!cr0.eq) goto loc_823DD9D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD910;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823dd960
	if (cr6.eq) goto loc_823DD960;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD920;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823dd960
	if (cr6.eq) goto loc_823DD960;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD930;
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
	ctx.lr = 0x823DD948;
	sub_823E3DE0(ctx, base);
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// rlwinm r9,r3,6,21,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r28,r11,-17448
	r28.s64 = r11.s64 + -17448;
	// b 0x823dd974
	goto loc_823DD974;
loc_823DD960:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r28,r10,-17448
	r28.s64 = ctx.r10.s64 + -17448;
	// addi r29,r11,-23104
	r29.s64 = r11.s64 + -23104;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_823DD974:
	// lbz r11,40(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rlwinm. r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823dd8c8
	if (!cr0.eq) goto loc_823DD8C8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD988;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823dd9c4
	if (cr6.eq) goto loc_823DD9C4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD998;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823dd9c4
	if (cr6.eq) goto loc_823DD9C4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD9A8;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823e3de0
	ctx.lr = 0x823DD9B8;
	sub_823E3DE0(ctx, base);
	// lwzx r10,r30,r29
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
loc_823DD9C4:
	// lbz r11,40(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 40);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823dd8c8
	if (!cr0.eq) goto loc_823DD8C8;
loc_823DD9D0:
	// bl 0x823e1160
	ctx.lr = 0x823DD9D4;
	sub_823E1160(ctx, base);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e1340
	ctx.lr = 0x823DD9E0;
	sub_823E1340(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82457b48
	ctx.lr = 0x823DD9EC;
	sub_82457B48(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,7044
	ctx.r3.s64 = r11.s64 + 7044;
	// bl 0x82457b48
	ctx.lr = 0x823DD9F8;
	sub_82457B48(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	r12.s64 = r31.s64 + 144;
	// bl 0x823dda18
	ctx.lr = 0x823DDA0C;
	sub_823DDA18(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823DDA10:
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823DD898"))) PPC_WEAK_FUNC(sub_823DD898);
PPC_FUNC_IMPL(__imp__sub_823DD898) {
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
	ctx.lr = 0x823DD8A0;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cntlzw r11,r27
	r11.u64 = r27.u32 == 0 ? 32 : __builtin_clz(r27.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823dd8f4
	if (!cr6.eq) goto loc_823DD8F4;
loc_823DD8C8:
	// bl 0x823e1000
	ctx.lr = 0x823DD8CC;
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
	ctx.lr = 0x823DD8EC;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823dda10
	goto loc_823DDA10;
loc_823DD8F4:
	// bl 0x823e1160
	ctx.lr = 0x823DD8F8;
	sub_823E1160(ctx, base);
	// addi r30,r3,32
	r30.s64 = ctx.r3.s64 + 32;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823dd9d0
	if (!cr0.eq) goto loc_823DD9D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD910;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823dd960
	if (cr6.eq) goto loc_823DD960;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD920;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823dd960
	if (cr6.eq) goto loc_823DD960;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD930;
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
	ctx.lr = 0x823DD948;
	sub_823E3DE0(ctx, base);
	// lwzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// rlwinm r9,r3,6,21,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r28,r11,-17448
	r28.s64 = r11.s64 + -17448;
	// b 0x823dd974
	goto loc_823DD974;
loc_823DD960:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// addi r28,r10,-17448
	r28.s64 = ctx.r10.s64 + -17448;
	// addi r29,r11,-23104
	r29.s64 = r11.s64 + -23104;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_823DD974:
	// lbz r11,40(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rlwinm. r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823dd8c8
	if (!cr0.eq) goto loc_823DD8C8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD988;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823dd9c4
	if (cr6.eq) goto loc_823DD9C4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD998;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823dd9c4
	if (cr6.eq) goto loc_823DD9C4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823DD9A8;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823e3de0
	ctx.lr = 0x823DD9B8;
	sub_823E3DE0(ctx, base);
	// lwzx r10,r30,r29
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// rlwinm r11,r3,6,21,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
loc_823DD9C4:
	// lbz r11,40(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 40);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823dd8c8
	if (!cr0.eq) goto loc_823DD8C8;
loc_823DD9D0:
	// bl 0x823e1160
	ctx.lr = 0x823DD9D4;
	sub_823E1160(ctx, base);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e1340
	ctx.lr = 0x823DD9E0;
	sub_823E1340(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82457b48
	ctx.lr = 0x823DD9EC;
	sub_82457B48(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,7044
	ctx.r3.s64 = r11.s64 + 7044;
	// bl 0x82457b48
	ctx.lr = 0x823DD9F8;
	sub_82457B48(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,144
	r12.s64 = r31.s64 + 144;
	// bl 0x823dda18
	ctx.lr = 0x823DDA0C;
	sub_823DDA18(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823DDA10:
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823DDA18"))) PPC_WEAK_FUNC(sub_823DDA18);
PPC_FUNC_IMPL(__imp__sub_823DDA18) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823e1160
	ctx.lr = 0x823DDA28;
	sub_823E1160(ctx, base);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e13d0
	ctx.lr = 0x823DDA34;
	sub_823E13D0(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DDA44"))) PPC_WEAK_FUNC(sub_823DDA44);
PPC_FUNC_IMPL(__imp__sub_823DDA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DDA48"))) PPC_WEAK_FUNC(sub_823DDA48);
PPC_FUNC_IMPL(__imp__sub_823DDA48) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823DDA68:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823dda68
	if (!cr6.eq) goto loc_823DDA68;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bne cr6,0x823ddab8
	if (!cr6.eq) goto loc_823DDAB8;
loc_823DDA8C:
	// bl 0x823e1000
	ctx.lr = 0x823DDA90;
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
	ctx.lr = 0x823DDAB0;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823ddaf8
	goto loc_823DDAF8;
loc_823DDAB8:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823dda8c
	if (cr6.eq) goto loc_823DDA8C;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// li r6,73
	ctx.r6.s64 = 73;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bgt cr6,0x823ddae8
	if (cr6.gt) goto loc_823DDAE8;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
loc_823DDAE8:
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823DDAF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823DDAF8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DDB08"))) PPC_WEAK_FUNC(sub_823DDB08);
PPC_FUNC_IMPL(__imp__sub_823DDB08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r10,-32194
	ctx.r10.s64 = -2109865984;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r3,r10,16088
	ctx.r3.s64 = ctx.r10.s64 + 16088;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x823dda48
	ctx.lr = 0x823DDB54;
	sub_823DDA48(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DDB64"))) PPC_WEAK_FUNC(sub_823DDB64);
PPC_FUNC_IMPL(__imp__sub_823DDB64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DDB68"))) PPC_WEAK_FUNC(sub_823DDB68);
PPC_FUNC_IMPL(__imp__sub_823DDB68) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x823ddbac
	if (!cr6.eq) goto loc_823DDBAC;
loc_823DDB80:
	// bl 0x823e1000
	ctx.lr = 0x823DDB84;
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
	ctx.lr = 0x823DDBA4;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823ddc0c
	goto loc_823DDC0C;
loc_823DDBAC:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ddb80
	if (cr6.eq) goto loc_823DDB80;
	// lis r11,32767
	r11.s64 = 2147418112;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r10,66
	ctx.r10.s64 = 66;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x823e1668
	ctx.lr = 0x823DDBD8;
	sub_823E1668(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// blt 0x823ddbfc
	if (cr0.lt) goto loc_823DDBFC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// b 0x823ddc08
	goto loc_823DDC08;
loc_823DDBFC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e3a68
	ctx.lr = 0x823DDC08;
	sub_823E3A68(ctx, base);
loc_823DDC08:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823DDC0C:
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

__attribute__((alias("__imp__sub_823DDC20"))) PPC_WEAK_FUNC(sub_823DDC20);
PPC_FUNC_IMPL(__imp__sub_823DDC20) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x823ddb68
	sub_823DDB68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DDC2C"))) PPC_WEAK_FUNC(sub_823DDC2C);
PPC_FUNC_IMPL(__imp__sub_823DDC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DDC30"))) PPC_WEAK_FUNC(sub_823DDC30);
PPC_FUNC_IMPL(__imp__sub_823DDC30) {
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
	ctx.lr = 0x823DDC38;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x823ddc58
	if (cr6.eq) goto loc_823DDC58;
	// stw r25,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r25.u32);
loc_823DDC58:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x823ddc88
	if (!cr6.eq) goto loc_823DDC88;
loc_823DDC60:
	// bl 0x823e1000
	ctx.lr = 0x823DDC64;
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
	ctx.lr = 0x823DDC84;
	sub_823E02A8(ctx, base);
	// b 0x823ddf14
	goto loc_823DDF14;
loc_823DDC88:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x823ddca0
	if (cr6.eq) goto loc_823DDCA0;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x823ddc60
	if (cr6.lt) goto loc_823DDC60;
	// cmpwi cr6,r28,36
	cr6.compare<int32_t>(r28.s32, 36, xer);
	// bgt cr6,0x823ddc60
	if (cr6.gt) goto loc_823DDC60;
loc_823DDCA0:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lbz r31,0(r25)
	r31.u64 = PPC_LOAD_U8(r25.u32 + 0);
	// li r26,0
	r26.s64 = 0;
	// addi r29,r25,1
	r29.s64 = r25.s64 + 1;
	// addi r30,r11,-18352
	r30.s64 = r11.s64 + -18352;
	// lwz r10,-18352(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -18352);
loc_823DDCB8:
	// lwz r11,172(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x823ddcdc
	if (!cr6.gt) goto loc_823DDCDC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
	// bl 0x823e5100
	ctx.lr = 0x823DDCD4;
	sub_823E5100(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823ddcec
	goto loc_823DDCEC;
loc_823DDCDC:
	// lwz r11,200(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// rlwinm r9,r31,1,23,30
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0x1FE;
	// lhzx r11,r9,r11
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + r11.u32);
	// rlwinm r3,r11,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
loc_823DDCEC:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823ddd00
	if (cr6.eq) goto loc_823DDD00;
	// lbz r31,0(r29)
	r31.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// b 0x823ddcb8
	goto loc_823DDCB8;
loc_823DDD00:
	// extsb r11,r31
	r11.s64 = r31.s8;
	// cmpwi cr6,r11,45
	cr6.compare<int32_t>(r11.s32, 45, xer);
	// bne cr6,0x823ddd14
	if (!cr6.eq) goto loc_823DDD14;
	// ori r24,r24,2
	r24.u64 = r24.u64 | 2;
	// b 0x823ddd1c
	goto loc_823DDD1C;
loc_823DDD14:
	// cmpwi cr6,r11,43
	cr6.compare<int32_t>(r11.s32, 43, xer);
	// bne cr6,0x823ddd24
	if (!cr6.eq) goto loc_823DDD24;
loc_823DDD1C:
	// lbz r31,0(r29)
	r31.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_823DDD24:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x823ddf08
	if (cr6.lt) goto loc_823DDF08;
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// beq cr6,0x823ddf08
	if (cr6.eq) goto loc_823DDF08;
	// cmpwi cr6,r28,36
	cr6.compare<int32_t>(r28.s32, 36, xer);
	// bgt cr6,0x823ddf08
	if (cr6.gt) goto loc_823DDF08;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x823ddd80
	if (!cr6.eq) goto loc_823DDD80;
	// extsb r11,r31
	r11.s64 = r31.s8;
	// cmpwi cr6,r11,48
	cr6.compare<int32_t>(r11.s32, 48, xer);
	// beq cr6,0x823ddd58
	if (cr6.eq) goto loc_823DDD58;
	// li r28,10
	r28.s64 = 10;
	// b 0x823dddb8
	goto loc_823DDDB8;
loc_823DDD58:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,120
	cr6.compare<int32_t>(r11.s32, 120, xer);
	// beq cr6,0x823ddd78
	if (cr6.eq) goto loc_823DDD78;
	// cmpwi cr6,r11,88
	cr6.compare<int32_t>(r11.s32, 88, xer);
	// beq cr6,0x823ddd78
	if (cr6.eq) goto loc_823DDD78;
	// li r28,8
	r28.s64 = 8;
	// b 0x823dddb8
	goto loc_823DDDB8;
loc_823DDD78:
	// li r28,16
	r28.s64 = 16;
	// b 0x823ddd88
	goto loc_823DDD88;
loc_823DDD80:
	// cmpwi cr6,r28,16
	cr6.compare<int32_t>(r28.s32, 16, xer);
	// bne cr6,0x823dddb8
	if (!cr6.eq) goto loc_823DDDB8;
loc_823DDD88:
	// extsb r11,r31
	r11.s64 = r31.s8;
	// cmpwi cr6,r11,48
	cr6.compare<int32_t>(r11.s32, 48, xer);
	// bne cr6,0x823dddb8
	if (!cr6.eq) goto loc_823DDDB8;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,120
	cr6.compare<int32_t>(r11.s32, 120, xer);
	// beq cr6,0x823dddac
	if (cr6.eq) goto loc_823DDDAC;
	// cmpwi cr6,r11,88
	cr6.compare<int32_t>(r11.s32, 88, xer);
	// bne cr6,0x823dddb8
	if (!cr6.eq) goto loc_823DDDB8;
loc_823DDDAC:
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// lbz r31,1(r29)
	r31.u64 = PPC_LOAD_U8(r29.u32 + 1);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
loc_823DDDB8:
	// li r27,-1
	r27.s64 = -1;
	// lwz r8,200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// twllei r28,0
	// divwu r9,r27,r28
	ctx.r9.u32 = r27.u32 / r28.u32;
loc_823DDDC8:
	// rlwinm r11,r31,1,23,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0x1FE;
	// lhzx r11,r11,r8
	r11.u64 = PPC_LOAD_U16(r11.u32 + ctx.r8.u32);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823ddde4
	if (cr0.eq) goto loc_823DDDE4;
	// extsb r11,r31
	r11.s64 = r31.s8;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// b 0x823dde0c
	goto loc_823DDE0C;
loc_823DDDE4:
	// andi. r11,r11,259
	r11.u64 = r11.u64 & 259;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823dde4c
	if (cr0.eq) goto loc_823DDE4C;
	// extsb r11,r31
	r11.s64 = r31.s8;
	// cmpwi cr6,r11,97
	cr6.compare<int32_t>(r11.s32, 97, xer);
	// blt cr6,0x823dde08
	if (cr6.lt) goto loc_823DDE08;
	// cmpwi cr6,r11,122
	cr6.compare<int32_t>(r11.s32, 122, xer);
	// bgt cr6,0x823dde08
	if (cr6.gt) goto loc_823DDE08;
	// addi r11,r11,-32
	r11.s64 = r11.s64 + -32;
loc_823DDE08:
	// addi r11,r11,-55
	r11.s64 = r11.s64 + -55;
loc_823DDE0C:
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// bge cr6,0x823dde4c
	if (!cr6.lt) goto loc_823DDE4C;
	// ori r24,r24,8
	r24.u64 = r24.u64 | 8;
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// blt cr6,0x823dde6c
	if (cr6.lt) goto loc_823DDE6C;
	// bne cr6,0x823dde40
	if (!cr6.eq) goto loc_823DDE40;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// twllei r28,0
	// divwu r7,r10,r28
	ctx.r7.u32 = ctx.r10.u32 / r28.u32;
	// mullw r7,r7,r28
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(r28.s32);
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x823dde6c
	if (!cr6.gt) goto loc_823DDE6C;
loc_823DDE40:
	// ori r24,r24,4
	r24.u64 = r24.u64 | 4;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x823dde74
	if (!cr6.eq) goto loc_823DDE74;
loc_823DDE4C:
	// rlwinm. r11,r24,0,28,28
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// bne 0x823dde80
	if (!cr0.eq) goto loc_823DDE80;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x823dde64
	if (cr6.eq) goto loc_823DDE64;
	// mr r29,r25
	r29.u64 = r25.u64;
loc_823DDE64:
	// li r26,0
	r26.s64 = 0;
	// b 0x823ddee8
	goto loc_823DDEE8;
loc_823DDE6C:
	// mullw r10,r26,r28
	ctx.r10.s64 = int64_t(r26.s32) * int64_t(r28.s32);
	// add r26,r10,r11
	r26.u64 = ctx.r10.u64 + r11.u64;
loc_823DDE74:
	// lbz r31,0(r29)
	r31.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// b 0x823dddc8
	goto loc_823DDDC8;
loc_823DDE80:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// rlwinm. r11,r24,0,29,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lis r30,-32768
	r30.s64 = -2147483648;
	// ori r31,r10,65535
	r31.u64 = ctx.r10.u64 | 65535;
	// bne 0x823ddebc
	if (!cr0.eq) goto loc_823DDEBC;
	// clrlwi. r11,r24,31
	r11.u64 = r24.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823ddee8
	if (!cr0.eq) goto loc_823DDEE8;
	// rlwinm. r11,r24,0,30,30
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823ddeac
	if (cr0.eq) goto loc_823DDEAC;
	// cmplw cr6,r26,r30
	cr6.compare<uint32_t>(r26.u32, r30.u32, xer);
	// bgt cr6,0x823ddebc
	if (cr6.gt) goto loc_823DDEBC;
loc_823DDEAC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823ddee8
	if (!cr6.eq) goto loc_823DDEE8;
	// cmplw cr6,r26,r31
	cr6.compare<uint32_t>(r26.u32, r31.u32, xer);
	// ble cr6,0x823ddee8
	if (!cr6.gt) goto loc_823DDEE8;
loc_823DDEBC:
	// bl 0x823e1000
	ctx.lr = 0x823DDEC0;
	sub_823E1000(ctx, base);
	// li r11,34
	r11.s64 = 34;
	// clrlwi. r10,r24,31
	ctx.r10.u64 = r24.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// beq 0x823dded8
	if (cr0.eq) goto loc_823DDED8;
	// mr r26,r27
	r26.u64 = r27.u64;
	// b 0x823ddee8
	goto loc_823DDEE8;
loc_823DDED8:
	// rlwinm. r11,r24,0,30,30
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r26,r30
	r26.u64 = r30.u64;
	// bne 0x823ddee8
	if (!cr0.eq) goto loc_823DDEE8;
	// mr r26,r31
	r26.u64 = r31.u64;
loc_823DDEE8:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x823ddef4
	if (cr6.eq) goto loc_823DDEF4;
	// stw r29,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r29.u32);
loc_823DDEF4:
	// rlwinm. r11,r24,0,30,30
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823ddf00
	if (cr0.eq) goto loc_823DDF00;
	// neg r26,r26
	r26.s64 = -r26.s64;
loc_823DDF00:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// b 0x823ddf18
	goto loc_823DDF18;
loc_823DDF08:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x823ddf14
	if (cr6.eq) goto loc_823DDF14;
	// stw r25,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r25.u32);
loc_823DDF14:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DDF18:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823DDF20"))) PPC_WEAK_FUNC(sub_823DDF20);
PPC_FUNC_IMPL(__imp__sub_823DDF20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r3,r10,-18352
	ctx.r3.s64 = ctx.r10.s64 + -18352;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x823ddc30
	sub_823DDC30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DDF40"))) PPC_WEAK_FUNC(sub_823DDF40);
PPC_FUNC_IMPL(__imp__sub_823DDF40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r3,r10,-18352
	ctx.r3.s64 = ctx.r10.s64 + -18352;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x823ddc30
	sub_823DDC30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DDF60"))) PPC_WEAK_FUNC(sub_823DDF60);
PPC_FUNC_IMPL(__imp__sub_823DDF60) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823ddfb0
	if (!cr6.eq) goto loc_823DDFB0;
	// bl 0x823e1000
	ctx.lr = 0x823DDF84;
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
	ctx.lr = 0x823DDFA4;
	sub_823E02A8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f1,-17600(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// b 0x823de040
	goto loc_823DE040;
loc_823DDFB0:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r30,r11,-18352
	r30.s64 = r11.s64 + -18352;
	// lwz r11,-18352(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18352);
loc_823DDFBC:
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x823ddfe0
	if (!cr6.gt) goto loc_823DDFE0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lbz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x823e5100
	ctx.lr = 0x823DDFD8;
	sub_823E5100(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823ddff4
	goto loc_823DDFF4;
loc_823DDFE0:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// lwz r9,200(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// lhzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r3,r10,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
loc_823DDFF4:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823de004
	if (cr6.eq) goto loc_823DE004;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// b 0x823ddfbc
	goto loc_823DDFBC;
loc_823DE004:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823DE008:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823de008
	if (!cr6.eq) goto loc_823DE008;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823e5130
	ctx.lr = 0x823DE03C;
	sub_823E5130(ctx, base);
	// lfd f1,16(r3)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
loc_823DE040:
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

__attribute__((alias("__imp__sub_823DE058"))) PPC_WEAK_FUNC(sub_823DE058);
PPC_FUNC_IMPL(__imp__sub_823DE058) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823ddf60
	sub_823DDF60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DE060"))) PPC_WEAK_FUNC(sub_823DE060);
PPC_FUNC_IMPL(__imp__sub_823DE060) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823de0b4
	if (!cr6.eq) goto loc_823DE0B4;
loc_823DE088:
	// bl 0x823e1000
	ctx.lr = 0x823DE08C;
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
	ctx.lr = 0x823DE0AC;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823de138
	goto loc_823DE138;
loc_823DE0B4:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823de0c4
	if (cr6.eq) goto loc_823DE0C4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823de088
	if (cr6.eq) goto loc_823DE088;
loc_823DE0C4:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bgt cr6,0x823de0dc
	if (cr6.gt) goto loc_823DE0DC;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
loc_823DE0DC:
	// li r10,66
	ctx.r10.s64 = 66;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823e1668
	ctx.lr = 0x823DE0FC;
	sub_823E1668(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823de134
	if (cr6.eq) goto loc_823DE134;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// blt 0x823de128
	if (cr0.lt) goto loc_823DE128;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// b 0x823de134
	goto loc_823DE134;
loc_823DE128:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e3a68
	ctx.lr = 0x823DE134;
	sub_823E3A68(ctx, base);
loc_823DE134:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823DE138:
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

__attribute__((alias("__imp__sub_823DE150"))) PPC_WEAK_FUNC(sub_823DE150);
PPC_FUNC_IMPL(__imp__sub_823DE150) {
	PPC_FUNC_PROLOGUE();
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x823de060
	sub_823DE060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DE15C"))) PPC_WEAK_FUNC(sub_823DE15C);
PPC_FUNC_IMPL(__imp__sub_823DE15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE160"))) PPC_WEAK_FUNC(sub_823DE160);
PPC_FUNC_IMPL(__imp__sub_823DE160) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x823db2f8
	ctx.lr = 0x823DE180;
	sub_823DB2F8(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,32
	r11.s64 = 32;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_823DE190:
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x823de190
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DE190;
	// li r9,1
	ctx.r9.s64 = 1;
loc_823DE1A0:
	// lbz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rlwinm r10,r8,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r7,r8,29
	ctx.r7.u64 = ctx.r8.u32 & 0x7;
	// cmplwi r8,0
	cr0.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// slw r8,r9,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stbx r8,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r8.u8);
	// bne 0x823de1a0
	if (!cr0.eq) goto loc_823DE1A0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bne cr6,0x823de1ec
	if (!cr6.eq) goto loc_823DE1EC;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// b 0x823de1ec
	goto loc_823DE1EC;
loc_823DE1E0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823de20c
	if (cr6.eq) goto loc_823DE20C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_823DE1EC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r10,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r6,r10,29
	ctx.r6.u64 = ctx.r10.u32 & 0x7;
	// slw r6,r9,r6
	ctx.r6.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r6.u8 & 0x3F));
	// lbzx r8,r7,r8
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// and. r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 & ctx.r8.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x823de1e0
	if (!cr0.eq) goto loc_823DE1E0;
loc_823DE20C:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// b 0x823de240
	goto loc_823DE240;
loc_823DE218:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// rlwinm r6,r8,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r8,r8,29
	ctx.r8.u64 = ctx.r8.u32 & 0x7;
	// slw r8,r9,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// lbzx r7,r6,r7
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r7.u32);
	// and. r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 & ctx.r7.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x823de24c
	if (!cr0.eq) goto loc_823DE24C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
loc_823DE240:
	// cmplwi r8,0
	cr0.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne 0x823de218
	if (!cr0.eq) goto loc_823DE218;
	// b 0x823de258
	goto loc_823DE258;
loc_823DE24C:
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_823DE258:
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq cr6,0x823de26c
	if (cr6.eq) goto loc_823DE26C;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_823DE26C:
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

__attribute__((alias("__imp__sub_823DE284"))) PPC_WEAK_FUNC(sub_823DE284);
PPC_FUNC_IMPL(__imp__sub_823DE284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE288"))) PPC_WEAK_FUNC(sub_823DE288);
PPC_FUNC_IMPL(__imp__sub_823DE288) {
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
	ctx.lr = 0x823DE290;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// addi r11,r5,-1
	r11.s64 = ctx.r5.s64 + -1;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mullw r11,r11,r30
	r11.s64 = int64_t(r11.s32) * int64_t(r30.s32);
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// add r24,r11,r4
	r24.u64 = r11.u64 + ctx.r4.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x823de2f0
	if (!cr6.eq) goto loc_823DE2F0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823de2f0
	if (cr6.eq) goto loc_823DE2F0;
loc_823DE2C0:
	// bl 0x823e1000
	ctx.lr = 0x823DE2C4;
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
	ctx.lr = 0x823DE2E4;
	sub_823E02A8(ctx, base);
loc_823DE2E4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DE2E8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823DE2F0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823de2c0
	if (cr6.eq) goto loc_823DE2C0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823de2c0
	if (cr6.eq) goto loc_823DE2C0;
	// cmplw cr6,r4,r24
	cr6.compare<uint32_t>(ctx.r4.u32, r24.u32, xer);
	// bgt cr6,0x823de2e4
	if (cr6.gt) goto loc_823DE2E4;
loc_823DE308:
	// rlwinm. r28,r5,31,1,31
	r28.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// beq 0x823de378
	if (cr0.eq) goto loc_823DE378;
	// clrlwi. r27,r5,31
	r27.u64 = ctx.r5.u32 & 0x1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne 0x823de320
	if (!cr0.eq) goto loc_823DE320;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
loc_823DE320:
	// mullw r11,r11,r30
	r11.s64 = int64_t(r11.s32) * int64_t(r30.s32);
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r26
	ctr.u64 = r26.u64;
	// bctrl 
	ctx.lr = 0x823DE338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823de370
	if (cr0.eq) goto loc_823DE370;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x823de35c
	if (!cr6.lt) goto loc_823DE35C;
	// subf r24,r30,r31
	r24.s64 = r31.s64 - r30.s64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x823de360
	if (!cr6.eq) goto loc_823DE360;
	// addi r5,r28,-1
	ctx.r5.s64 = r28.s64 + -1;
	// b 0x823de364
	goto loc_823DE364;
loc_823DE35C:
	// add r29,r31,r30
	r29.u64 = r31.u64 + r30.u64;
loc_823DE360:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_823DE364:
	// cmplw cr6,r29,r24
	cr6.compare<uint32_t>(r29.u32, r24.u32, xer);
	// ble cr6,0x823de308
	if (!cr6.gt) goto loc_823DE308;
	// b 0x823de2e4
	goto loc_823DE2E4;
loc_823DE370:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x823de2e8
	goto loc_823DE2E8;
loc_823DE378:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823de2e4
	if (cr6.eq) goto loc_823DE2E4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mtctr r26
	ctr.u64 = r26.u64;
	// bctrl 
	ctx.lr = 0x823DE390;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne 0x823de2e8
	if (!cr0.eq) goto loc_823DE2E8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// b 0x823de2e8
	goto loc_823DE2E8;
}

__attribute__((alias("__imp__sub_823DE3A4"))) PPC_WEAK_FUNC(sub_823DE3A4);
PPC_FUNC_IMPL(__imp__sub_823DE3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE3A8"))) PPC_WEAK_FUNC(sub_823DE3A8);
PPC_FUNC_IMPL(__imp__sub_823DE3A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_823DE3AC:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne 0x823de3ac
	if (!cr0.eq) goto loc_823DE3AC;
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE3CC"))) PPC_WEAK_FUNC(sub_823DE3CC);
PPC_FUNC_IMPL(__imp__sub_823DE3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE3D0"))) PPC_WEAK_FUNC(sub_823DE3D0);
PPC_FUNC_IMPL(__imp__sub_823DE3D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823de428
	if (cr6.eq) goto loc_823DE428;
loc_823DE3D8:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r10,-65
	r11.s64 = ctx.r10.s64 + -65;
	// cmplwi cr6,r11,25
	cr6.compare<uint32_t>(r11.u32, 25, xer);
	// bgt cr6,0x823de3f0
	if (cr6.gt) goto loc_823DE3F0;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
loc_823DE3F0:
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r9,r11,-65
	ctx.r9.s64 = r11.s64 + -65;
	// cmplwi cr6,r9,25
	cr6.compare<uint32_t>(ctx.r9.u32, 25, xer);
	// bgt cr6,0x823de408
	if (cr6.gt) goto loc_823DE408;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
loc_823DE408:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x823de420
	if (cr0.eq) goto loc_823DE420;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823de420
	if (cr6.eq) goto loc_823DE420;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x823de3d8
	if (cr6.eq) goto loc_823DE3D8;
loc_823DE420:
	// subf r3,r11,r10
	ctx.r3.s64 = ctx.r10.s64 - r11.s64;
	// blr 
	return;
loc_823DE428:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE430"))) PPC_WEAK_FUNC(sub_823DE430);
PPC_FUNC_IMPL(__imp__sub_823DE430) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823de478
	if (!cr6.eq) goto loc_823DE478;
loc_823DE448:
	// bl 0x823e1000
	ctx.lr = 0x823DE44C;
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
	ctx.lr = 0x823DE46C;
	sub_823E02A8(ctx, base);
	// lis r3,32767
	ctx.r3.s64 = 2147418112;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// b 0x823de4c0
	goto loc_823DE4C0;
loc_823DE478:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823de448
	if (cr6.eq) goto loc_823DE448;
	// lis r11,32767
	r11.s64 = 2147418112;
	// ori r31,r11,65535
	r31.u64 = r11.u64 | 65535;
	// cmplw cr6,r5,r31
	cr6.compare<uint32_t>(ctx.r5.u32, r31.u32, xer);
	// ble cr6,0x823de4bc
	if (!cr6.gt) goto loc_823DE4BC;
	// bl 0x823e1000
	ctx.lr = 0x823DE494;
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
	ctx.lr = 0x823DE4B4;
	sub_823E02A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x823de4c0
	goto loc_823DE4C0;
loc_823DE4BC:
	// bl 0x823de3d0
	ctx.lr = 0x823DE4C0;
	sub_823DE3D0(ctx, base);
loc_823DE4C0:
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

__attribute__((alias("__imp__sub_823DE4D4"))) PPC_WEAK_FUNC(sub_823DE4D4);
PPC_FUNC_IMPL(__imp__sub_823DE4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE4D8"))) PPC_WEAK_FUNC(sub_823DE4D8);
PPC_FUNC_IMPL(__imp__sub_823DE4D8) {
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
	// bne cr6,0x823de518
	if (!cr6.eq) goto loc_823DE518;
	// bl 0x823e1000
	ctx.lr = 0x823DE4F0;
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
	ctx.lr = 0x823DE510;
	sub_823E02A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823de554
	goto loc_823DE554;
loc_823DE518:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x823de54c
	goto loc_823DE54C;
loc_823DE524:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,97
	cr6.compare<int32_t>(ctx.r10.s32, 97, xer);
	// blt cr6,0x823de544
	if (cr6.lt) goto loc_823DE544;
	// cmpwi cr6,r10,122
	cr6.compare<int32_t>(ctx.r10.s32, 122, xer);
	// bgt cr6,0x823de544
	if (cr6.gt) goto loc_823DE544;
	// addi r10,r10,-32
	ctx.r10.s64 = ctx.r10.s64 + -32;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_823DE544:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
loc_823DE54C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823de524
	if (!cr6.eq) goto loc_823DE524;
loc_823DE554:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE564"))) PPC_WEAK_FUNC(sub_823DE564);
PPC_FUNC_IMPL(__imp__sub_823DE564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE568"))) PPC_WEAK_FUNC(sub_823DE568);
PPC_FUNC_IMPL(__imp__sub_823DE568) {
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
	ctx.lr = 0x823DE570;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r11,r11,-11508
	r11.s64 = r11.s64 + -11508;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823de5dc
	if (cr6.eq) goto loc_823DE5DC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823DE598:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823de598
	if (!cr6.eq) goto loc_823DE598;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2610
	ctx.lr = 0x823DE5C0;
	sub_823E2610(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x823de5e4
	if (cr0.eq) goto loc_823DE5E4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x823e2530
	ctx.lr = 0x823DE5D8;
	sub_823E2530(ctx, base);
	// b 0x823de5e4
	goto loc_823DE5E4;
loc_823DE5DC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_823DE5E4:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823DE5F8"))) PPC_WEAK_FUNC(sub_823DE5F8);
PPC_FUNC_IMPL(__imp__sub_823DE5F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-11528
	ctx.r3.s64 = r11.s64 + -11528;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE610"))) PPC_WEAK_FUNC(sub_823DE610);
PPC_FUNC_IMPL(__imp__sub_823DE610) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823de568
	ctx.lr = 0x823DE630;
	sub_823DE568(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,-11508
	r11.s64 = r11.s64 + -11508;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_823DE654"))) PPC_WEAK_FUNC(sub_823DE654);
PPC_FUNC_IMPL(__imp__sub_823DE654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE658"))) PPC_WEAK_FUNC(sub_823DE658);
PPC_FUNC_IMPL(__imp__sub_823DE658) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-11508
	r11.s64 = r11.s64 + -11508;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x823e2c38
	sub_823E2C38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DE678"))) PPC_WEAK_FUNC(sub_823DE678);
PPC_FUNC_IMPL(__imp__sub_823DE678) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE67C"))) PPC_WEAK_FUNC(sub_823DE67C);
PPC_FUNC_IMPL(__imp__sub_823DE67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE680"))) PPC_WEAK_FUNC(sub_823DE680);
PPC_FUNC_IMPL(__imp__sub_823DE680) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r11,r11,-11508
	r11.s64 = r11.s64 + -11508;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823de6bc
	if (cr6.eq) goto loc_823DE6BC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x823e2c38
	ctx.lr = 0x823DE6BC;
	sub_823E2C38(ctx, base);
loc_823DE6BC:
	// clrlwi. r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823de6cc
	if (cr0.eq) goto loc_823DE6CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823DE6CC;
	sub_82130588(ctx, base);
loc_823DE6CC:
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

__attribute__((alias("__imp__sub_823DE6E8"))) PPC_WEAK_FUNC(sub_823DE6E8);
PPC_FUNC_IMPL(__imp__sub_823DE6E8) {
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823de568
	ctx.lr = 0x823DE708;
	sub_823DE568(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,-11508
	r11.s64 = r11.s64 + -11508;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_823DE72C"))) PPC_WEAK_FUNC(sub_823DE72C);
PPC_FUNC_IMPL(__imp__sub_823DE72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE730"))) PPC_WEAK_FUNC(sub_823DE730);
PPC_FUNC_IMPL(__imp__sub_823DE730) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9560(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9560);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823de7c0
	if (cr6.eq) goto loc_823DE7C0;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823de77c
	if (cr6.eq) goto loc_823DE77C;
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823de7e0
	goto loc_823DE7E0;
loc_823DE77C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,-11428
	ctx.r4.s64 = r11.s64 + -11428;
	// bl 0x823de6e8
	ctx.lr = 0x823DE78C;
	sub_823DE6E8(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,10092
	ctx.r4.s64 = r11.s64 + 10092;
	// bl 0x823e5b70
	ctx.lr = 0x823DE79C;
	sub_823E5B70(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,-11464
	ctx.r4.s64 = r11.s64 + -11464;
	// bl 0x823de6e8
	ctx.lr = 0x823DE7B0;
	sub_823DE6E8(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,10092
	ctx.r4.s64 = r11.s64 + 10092;
	// bl 0x823e5b70
	ctx.lr = 0x823DE7C0;
	sub_823E5B70(ctx, base);
loc_823DE7C0:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,-11500
	ctx.r4.s64 = r11.s64 + -11500;
	// bl 0x823de610
	ctx.lr = 0x823DE7D0;
	sub_823DE610(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,10076
	ctx.r4.s64 = r11.s64 + 10076;
	// bl 0x823e5b70
	ctx.lr = 0x823DE7E0;
	sub_823E5B70(ctx, base);
loc_823DE7E0:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE738"))) PPC_WEAK_FUNC(sub_823DE738);
PPC_FUNC_IMPL(__imp__sub_823DE738) {
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
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823de7c0
	if (cr6.eq) goto loc_823DE7C0;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823de77c
	if (cr6.eq) goto loc_823DE77C;
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823de7e0
	goto loc_823DE7E0;
loc_823DE77C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,-11428
	ctx.r4.s64 = r11.s64 + -11428;
	// bl 0x823de6e8
	ctx.lr = 0x823DE78C;
	sub_823DE6E8(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,10092
	ctx.r4.s64 = r11.s64 + 10092;
	// bl 0x823e5b70
	ctx.lr = 0x823DE79C;
	sub_823E5B70(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,-11464
	ctx.r4.s64 = r11.s64 + -11464;
	// bl 0x823de6e8
	ctx.lr = 0x823DE7B0;
	sub_823DE6E8(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,10092
	ctx.r4.s64 = r11.s64 + 10092;
	// bl 0x823e5b70
	ctx.lr = 0x823DE7C0;
	sub_823E5B70(ctx, base);
loc_823DE7C0:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,-11500
	ctx.r4.s64 = r11.s64 + -11500;
	// bl 0x823de610
	ctx.lr = 0x823DE7D0;
	sub_823DE610(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// addi r4,r11,10076
	ctx.r4.s64 = r11.s64 + 10076;
	// bl 0x823e5b70
	ctx.lr = 0x823DE7E0;
	sub_823E5B70(ctx, base);
loc_823DE7E0:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE7F4"))) PPC_WEAK_FUNC(sub_823DE7F4);
PPC_FUNC_IMPL(__imp__sub_823DE7F4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,5
	r11.u64 = r11.u64 | 5;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE818"))) PPC_WEAK_FUNC(sub_823DE818);
PPC_FUNC_IMPL(__imp__sub_823DE818) {
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
	ctx.lr = 0x823DE820;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r11,r11,-11508
	r11.s64 = r11.s64 + -11508;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// beq cr6,0x823de8a4
	if (cr6.eq) goto loc_823DE8A4;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823de89c
	if (cr6.eq) goto loc_823DE89C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_823DE858:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823de858
	if (!cr6.eq) goto loc_823DE858;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2610
	ctx.lr = 0x823DE880;
	sub_823E2610(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x823de8ac
	if (cr0.eq) goto loc_823DE8AC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x823e2530
	ctx.lr = 0x823DE898;
	sub_823E2530(ctx, base);
	// b 0x823de8ac
	goto loc_823DE8AC;
loc_823DE89C:
	// li r11,0
	r11.s64 = 0;
	// b 0x823de8a8
	goto loc_823DE8A8;
loc_823DE8A4:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
loc_823DE8A8:
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_823DE8AC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823DE8B8"))) PPC_WEAK_FUNC(sub_823DE8B8);
PPC_FUNC_IMPL(__imp__sub_823DE8B8) {
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
	// bl 0x823de818
	ctx.lr = 0x823DE8D0;
	sub_823DE818(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,-11508
	r11.s64 = r11.s64 + -11508;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_823DE8F4"))) PPC_WEAK_FUNC(sub_823DE8F4);
PPC_FUNC_IMPL(__imp__sub_823DE8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DE8F8"))) PPC_WEAK_FUNC(sub_823DE8F8);
PPC_FUNC_IMPL(__imp__sub_823DE8F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823de9e8
	if (cr6.eq) goto loc_823DE9E8;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_823DE91C:
	// lwz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// beq cr6,0x823de974
	if (cr6.eq) goto loc_823DE974;
	// addi r10,r5,8
	ctx.r10.s64 = ctx.r5.s64 + 8;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_823DE934:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r30,0(r10)
	r30.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - r30.s64;
	// beq 0x823de958
	if (cr0.eq) goto loc_823DE958;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823de934
	if (cr6.eq) goto loc_823DE934;
loc_823DE958:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823de974
	if (cr0.eq) goto loc_823DE974;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r31
	cr6.compare<uint32_t>(ctx.r7.u32, r31.u32, xer);
	// blt cr6,0x823de91c
	if (cr6.lt) goto loc_823DE91C;
	// b 0x823de9e8
	goto loc_823DE9E8;
loc_823DE974:
	// addi r8,r7,1
	ctx.r8.s64 = ctx.r7.s64 + 1;
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// bge cr6,0x823de9e8
	if (!cr6.lt) goto loc_823DE9E8;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r6
	ctx.r7.u64 = r11.u64 + ctx.r6.u64;
loc_823DE988:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// rlwinm. r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823de9e8
	if (!cr0.eq) goto loc_823DE9E8;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x823de9ec
	if (cr6.eq) goto loc_823DE9EC;
	// addi r10,r4,8
	ctx.r10.s64 = ctx.r4.s64 + 8;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_823DE9AC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq 0x823de9d0
	if (cr0.eq) goto loc_823DE9D0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823de9ac
	if (cr6.eq) goto loc_823DE9AC;
loc_823DE9D0:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823de9ec
	if (cr0.eq) goto loc_823DE9EC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// blt cr6,0x823de988
	if (cr6.lt) goto loc_823DE988;
loc_823DE9E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DE9EC:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DE9F8"))) PPC_WEAK_FUNC(sub_823DE9F8);
PPC_FUNC_IMPL(__imp__sub_823DE9F8) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823DEA00;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823deb98
	if (cr6.eq) goto loc_823DEB98;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_823DEA30:
	// subf r11,r30,r4
	r11.s64 = ctx.r4.s64 - r30.s64;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// ble cr6,0x823dea94
	if (!cr6.gt) goto loc_823DEA94;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// beq cr6,0x823dea80
	if (cr6.eq) goto loc_823DEA80;
	// addi r10,r7,8
	ctx.r10.s64 = ctx.r7.s64 + 8;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_823DEA54:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r25,0(r10)
	r25.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r25,r9
	ctx.r9.s64 = ctx.r9.s64 - r25.s64;
	// beq 0x823dea78
	if (cr0.eq) goto loc_823DEA78;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823dea54
	if (cr6.eq) goto loc_823DEA54;
loc_823DEA78:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x823dea94
	if (!cr0.eq) goto loc_823DEA94;
loc_823DEA80:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x823deb24
	if (!cr6.eq) goto loc_823DEB24;
	// lwz r31,4(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
loc_823DEA94:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// beq cr6,0x823dead4
	if (cr6.eq) goto loc_823DEAD4;
	// addi r10,r5,8
	ctx.r10.s64 = ctx.r5.s64 + 8;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
loc_823DEAA8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r25,0(r10)
	r25.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r25,r9
	ctx.r9.s64 = ctx.r9.s64 - r25.s64;
	// beq 0x823deacc
	if (cr0.eq) goto loc_823DEACC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823deaa8
	if (cr6.eq) goto loc_823DEAA8;
loc_823DEACC:
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x823deb10
	if (!cr0.eq) goto loc_823DEB10;
loc_823DEAD4:
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823deaf4
	if (cr6.lt) goto loc_823DEAF4;
	// lwzx r10,r11,r27
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// lwz r9,16(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
loc_823DEAF4:
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bne cr6,0x823deb10
	if (!cr6.eq) goto loc_823DEB10;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823deb44
	if (!cr6.eq) goto loc_823DEB44;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
loc_823DEB10:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r4,r29
	cr6.compare<uint32_t>(ctx.r4.u32, r29.u32, xer);
	// blt cr6,0x823dea30
	if (cr6.lt) goto loc_823DEA30;
	// b 0x823deb98
	goto loc_823DEB98;
loc_823DEB24:
	// lwz r11,20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// clrlwi. r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823deb98
	if (!cr0.eq) goto loc_823DEB98;
	// lwz r11,20(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823deb98
	if (!cr0.eq) goto loc_823DEB98;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// b 0x823deb9c
	goto loc_823DEB9C;
loc_823DEB44:
	// subf r11,r30,r4
	r11.s64 = ctx.r4.s64 - r30.s64;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bgt cr6,0x823deb8c
	if (cr6.gt) goto loc_823DEB8C;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823deb74
	if (!cr0.eq) goto loc_823DEB74;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823deb9c
	if (!cr6.eq) goto loc_823DEB9C;
loc_823DEB64:
	// lwz r11,20(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
loc_823DEB68:
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823deb98
	if (!cr0.eq) goto loc_823DEB98;
	// b 0x823deb9c
	goto loc_823DEB9C;
loc_823DEB74:
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// b 0x823deb68
	goto loc_823DEB68;
loc_823DEB8C:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// clrlwi. r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823deb64
	if (cr0.eq) goto loc_823DEB64;
loc_823DEB98:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DEB9C:
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823DEBA0"))) PPC_WEAK_FUNC(sub_823DEBA0);
PPC_FUNC_IMPL(__imp__sub_823DEBA0) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x823DEBA8;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// li r26,0
	r26.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// li r22,0
	r22.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// lwz r27,8(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r29,-1
	r29.s64 = -1;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r25,1
	r25.s64 = 1;
	// li r24,-1
	r24.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823ded9c
	if (cr6.eq) goto loc_823DED9C;
loc_823DEBE0:
	// subf r10,r29,r30
	ctx.r10.s64 = r30.s64 - r29.s64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// ble cr6,0x823dec4c
	if (!cr6.gt) goto loc_823DEC4C;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// beq cr6,0x823dec30
	if (cr6.eq) goto loc_823DEC30;
	// addi r9,r7,8
	ctx.r9.s64 = ctx.r7.s64 + 8;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
loc_823DEC04:
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r21,0(r9)
	r21.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi r4,0
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// subf r4,r21,r4
	ctx.r4.s64 = ctx.r4.s64 - r21.s64;
	// beq 0x823dec28
	if (cr0.eq) goto loc_823DEC28;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823dec04
	if (cr6.eq) goto loc_823DEC04;
loc_823DEC28:
	// cmpwi r4,0
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x823dec4c
	if (!cr0.eq) goto loc_823DEC4C;
loc_823DEC30:
	// lwz r10,20(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// clrlwi. r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823dec40
	if (!cr0.eq) goto loc_823DEC40;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
loc_823DEC40:
	// lwz r28,4(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_823DEC4C:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// beq cr6,0x823dec8c
	if (cr6.eq) goto loc_823DEC8C;
	// addi r9,r5,8
	ctx.r9.s64 = ctx.r5.s64 + 8;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
loc_823DEC60:
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r21,0(r9)
	r21.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmpwi r4,0
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// subf r4,r21,r4
	ctx.r4.s64 = ctx.r4.s64 - r21.s64;
	// beq 0x823dec84
	if (cr0.eq) goto loc_823DEC84;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823dec60
	if (cr6.eq) goto loc_823DEC60;
loc_823DEC84:
	// cmpwi r4,0
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x823ded8c
	if (!cr0.eq) goto loc_823DED8C;
loc_823DEC8C:
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x823decac
	if (cr6.lt) goto loc_823DECAC;
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwz r4,16(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwzx r9,r9,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823DECAC:
	// lwz r10,8(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bne cr6,0x823ded8c
	if (!cr6.eq) goto loc_823DED8C;
	// subf r10,r29,r30
	ctx.r10.s64 = r30.s64 - r29.s64;
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// bgt cr6,0x823ded78
	if (cr6.gt) goto loc_823DED78;
	// clrlwi. r9,r25,24
	ctx.r9.u64 = r25.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823ded8c
	if (cr0.eq) goto loc_823DED8C;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm. r9,r9,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x823decfc
	if (!cr0.eq) goto loc_823DECFC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x823decf4
	if (!cr6.eq) goto loc_823DECF4;
	// lwz r10,20(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823decf4
	if (cr0.eq) goto loc_823DECF4;
	// li r25,0
	r25.s64 = 0;
loc_823DECF4:
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x823ded24
	goto loc_823DED24;
loc_823DECFC:
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// clrlwi. r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823ded1c
	if (cr0.eq) goto loc_823DED1C;
	// li r25,0
	r25.s64 = 0;
loc_823DED1C:
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// rlwinm r10,r10,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
loc_823DED24:
	// clrlwi. r9,r25,24
	ctx.r9.u64 = r25.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823ded8c
	if (cr0.eq) goto loc_823DED8C;
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823ded8c
	if (cr0.eq) goto loc_823DED8C;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x823ded54
	if (cr6.lt) goto loc_823DED54;
	// lwzx r9,r10,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwzx r9,r9,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823DED54:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq cr6,0x823ded6c
	if (cr6.eq) goto loc_823DED6C;
	// cmpw cr6,r24,r10
	cr6.compare<int32_t>(r24.s32, ctx.r10.s32, xer);
	// bne cr6,0x823dedc8
	if (!cr6.eq) goto loc_823DEDC8;
loc_823DED6C:
	// mr r26,r31
	r26.u64 = r31.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// b 0x823ded8c
	goto loc_823DED8C;
loc_823DED78:
	// lwz r10,20(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// andi. r10,r10,5
	ctx.r10.u64 = ctx.r10.u64 & 5;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne 0x823ded8c
	if (!cr0.eq) goto loc_823DED8C;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
loc_823DED8C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// blt cr6,0x823debe0
	if (cr6.lt) goto loc_823DEBE0;
loc_823DED9C:
	// clrlwi. r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823dedb4
	if (cr0.eq) goto loc_823DEDB4;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823dedb4
	if (cr6.eq) goto loc_823DEDB4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// b 0x823dedcc
	goto loc_823DEDCC;
loc_823DEDB4:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x823dedc8
	if (cr6.eq) goto loc_823DEDC8;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bne cr6,0x823dedcc
	if (!cr6.eq) goto loc_823DEDCC;
loc_823DEDC8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DEDCC:
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_823DEDD0"))) PPC_WEAK_FUNC(sub_823DEDD0);
PPC_FUNC_IMPL(__imp__sub_823DEDD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9584(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9584);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823DEDE0;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823def38
	if (cr6.eq) {
		// ERROR 823DEF38
		return;
	}
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r30,r8,r3
	r30.s64 = ctx.r3.s64 - ctx.r8.s64;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// beq cr6,0x823dee3c
	if (cr6.eq) goto loc_823DEE3C;
	// subf r10,r10,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r10.s64;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r30,r10,r30
	r30.s64 = r30.s64 - ctx.r10.s64;
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
loc_823DEE3C:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// subf r8,r4,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r4.s64;
	// subf r6,r30,r8
	ctx.r6.s64 = ctx.r8.s64 - r30.s64;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi. r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x823dee64
	if (!cr0.eq) goto loc_823DEE64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823de8f8
	ctx.lr = 0x823DEE60;
	sub_823DE8F8(ctx, base);
	// b 0x823dee88
	goto loc_823DEE88;
loc_823DEE64:
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// bne 0x823dee84
	if (!cr0.eq) goto loc_823DEE84;
	// bl 0x823de9f8
	ctx.lr = 0x823DEE80;
	sub_823DE9F8(ctx, base);
	// b 0x823dee88
	goto loc_823DEE88;
loc_823DEE84:
	// bl 0x823deba0
	ctx.lr = 0x823DEE88;
	sub_823DEBA0(ctx, base);
loc_823DEE88:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823deec8
	if (cr6.eq) goto loc_823DEEC8;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823deeb4
	if (cr6.lt) goto loc_823DEEB4;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
loc_823DEEB4:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// b 0x823deefc
	goto loc_823DEEFC;
loc_823DEEC8:
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// beq cr6,0x823deefc
	if (cr6.eq) goto loc_823DEEFC;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r11,-11392
	ctx.r4.s64 = r11.s64 + -11392;
	// bl 0x823de610
	ctx.lr = 0x823DEEE8;
	sub_823DE610(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r11,10220
	ctx.r4.s64 = r11.s64 + 10220;
	// bl 0x823e5b70
	ctx.lr = 0x823DEEF8;
	sub_823E5B70(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_823DEEFC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823def34
	// ERROR 823DEF34
	return;
}

__attribute__((alias("__imp__sub_823DEDD8"))) PPC_WEAK_FUNC(sub_823DEDD8);
PPC_FUNC_IMPL(__imp__sub_823DEDD8) {
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
	ctx.lr = 0x823DEDE0;
	// addi r31,r1,-144
	r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823def38
	if (cr6.eq) goto loc_823DEF38;
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r30,r8,r3
	r30.s64 = ctx.r3.s64 - ctx.r8.s64;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// beq cr6,0x823dee3c
	if (cr6.eq) goto loc_823DEE3C;
	// subf r10,r10,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r10.s64;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r30,r10,r30
	r30.s64 = r30.s64 - ctx.r10.s64;
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
loc_823DEE3C:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// subf r8,r4,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r4.s64;
	// subf r6,r30,r8
	ctx.r6.s64 = ctx.r8.s64 - r30.s64;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi. r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x823dee64
	if (!cr0.eq) goto loc_823DEE64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823de8f8
	ctx.lr = 0x823DEE60;
	sub_823DE8F8(ctx, base);
	// b 0x823dee88
	goto loc_823DEE88;
loc_823DEE64:
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// bne 0x823dee84
	if (!cr0.eq) goto loc_823DEE84;
	// bl 0x823de9f8
	ctx.lr = 0x823DEE80;
	sub_823DE9F8(ctx, base);
	// b 0x823dee88
	goto loc_823DEE88;
loc_823DEE84:
	// bl 0x823deba0
	ctx.lr = 0x823DEE88;
	sub_823DEBA0(ctx, base);
loc_823DEE88:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823deec8
	if (cr6.eq) goto loc_823DEEC8;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823deeb4
	if (cr6.lt) goto loc_823DEEB4;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
loc_823DEEB4:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// b 0x823deefc
	goto loc_823DEEFC;
loc_823DEEC8:
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// beq cr6,0x823deefc
	if (cr6.eq) goto loc_823DEEFC;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r11,-11392
	ctx.r4.s64 = r11.s64 + -11392;
	// bl 0x823de610
	ctx.lr = 0x823DEEE8;
	sub_823DE610(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r11,10220
	ctx.r4.s64 = r11.s64 + 10220;
	// bl 0x823e5b70
	ctx.lr = 0x823DEEF8;
	sub_823E5B70(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_823DEEFC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823def34
	goto loc_823DEF34;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r11,-11464
	ctx.r4.s64 = r11.s64 + -11464;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// bl 0x823de6e8
	ctx.lr = 0x823DEF24;
	sub_823DE6E8(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r11,10092
	ctx.r4.s64 = r11.s64 + 10092;
	// bl 0x823e5b70
	ctx.lr = 0x823DEF34;
	sub_823E5B70(ctx, base);
loc_823DEF34:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823DEF38:
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823DEF0C"))) PPC_WEAK_FUNC(sub_823DEF0C);
PPC_FUNC_IMPL(__imp__sub_823DEF0C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r11,-11464
	ctx.r4.s64 = r11.s64 + -11464;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// bl 0x823de6e8
	ctx.lr = 0x823DEF24;
	sub_823DE6E8(ctx, base);
	// lis r11,-32240
	r11.s64 = -2112880640;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// addi r4,r11,10092
	ctx.r4.s64 = r11.s64 + 10092;
	// bl 0x823e5b70
	ctx.lr = 0x823DEF34;
	sub_823E5B70(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r31,144
	ctx.r1.s64 = r31.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823DEF40"))) PPC_WEAK_FUNC(sub_823DEF40);
PPC_FUNC_IMPL(__imp__sub_823DEF40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,5
	r11.u64 = r11.u64 | 5;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DEF64"))) PPC_WEAK_FUNC(sub_823DEF64);
PPC_FUNC_IMPL(__imp__sub_823DEF64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DEF68"))) PPC_WEAK_FUNC(sub_823DEF68);
PPC_FUNC_IMPL(__imp__sub_823DEF68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r3,-97
	r11.s64 = ctx.r3.s64 + -97;
	// cmplwi cr6,r11,25
	cr6.compare<uint32_t>(r11.u32, 25, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// addi r3,r3,-32
	ctx.r3.s64 = ctx.r3.s64 + -32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DEF7C"))) PPC_WEAK_FUNC(sub_823DEF7C);
PPC_FUNC_IMPL(__imp__sub_823DEF7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DEF80"))) PPC_WEAK_FUNC(sub_823DEF80);
PPC_FUNC_IMPL(__imp__sub_823DEF80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// b 0x823def94
	goto loc_823DEF94;
loc_823DEF84:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823defa4
	if (cr6.eq) goto loc_823DEFA4;
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// addi r4,r4,2
	ctx.r4.s64 = ctx.r4.s64 + 2;
loc_823DEF94:
	// lhz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// subf. r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823def84
	if (cr0.eq) goto loc_823DEF84;
loc_823DEFA4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x823defb4
	if (!cr6.lt) goto loc_823DEFB4;
	// li r11,-1
	r11.s64 = -1;
	// b 0x823defbc
	goto loc_823DEFBC;
loc_823DEFB4:
	// ble cr6,0x823defbc
	if (!cr6.gt) goto loc_823DEFBC;
	// li r11,1
	r11.s64 = 1;
loc_823DEFBC:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DEFC4"))) PPC_WEAK_FUNC(sub_823DEFC4);
PPC_FUNC_IMPL(__imp__sub_823DEFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DEFC8"))) PPC_WEAK_FUNC(sub_823DEFC8);
PPC_FUNC_IMPL(__imp__sub_823DEFC8) {
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
	// bne cr6,0x823df008
	if (!cr6.eq) goto loc_823DF008;
	// bl 0x823e1000
	ctx.lr = 0x823DEFE0;
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
	ctx.lr = 0x823DF000;
	sub_823E02A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823df044
	goto loc_823DF044;
loc_823DF008:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x823df03c
	goto loc_823DF03C;
loc_823DF014:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,65
	cr6.compare<int32_t>(ctx.r10.s32, 65, xer);
	// blt cr6,0x823df034
	if (cr6.lt) goto loc_823DF034;
	// cmpwi cr6,r10,90
	cr6.compare<int32_t>(ctx.r10.s32, 90, xer);
	// bgt cr6,0x823df034
	if (cr6.gt) goto loc_823DF034;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_823DF034:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
loc_823DF03C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823df014
	if (!cr6.eq) goto loc_823DF014;
loc_823DF044:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF054"))) PPC_WEAK_FUNC(sub_823DF054);
PPC_FUNC_IMPL(__imp__sub_823DF054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF058"))) PPC_WEAK_FUNC(sub_823DF058);
PPC_FUNC_IMPL(__imp__sub_823DF058) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r3,-65
	r11.s64 = ctx.r3.s64 + -65;
	// cmplwi cr6,r11,25
	cr6.compare<uint32_t>(r11.u32, 25, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF06C"))) PPC_WEAK_FUNC(sub_823DF06C);
PPC_FUNC_IMPL(__imp__sub_823DF06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF070"))) PPC_WEAK_FUNC(sub_823DF070);
PPC_FUNC_IMPL(__imp__sub_823DF070) {
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
	// bl 0x823db2f8
	ctx.lr = 0x823DF088;
	sub_823DB2F8(ctx, base);
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r31.u32);
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

__attribute__((alias("__imp__sub_823DF0A0"))) PPC_WEAK_FUNC(sub_823DF0A0);
PPC_FUNC_IMPL(__imp__sub_823DF0A0) {
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
	// bl 0x823db2f8
	ctx.lr = 0x823DF0B0;
	sub_823DB2F8(ctx, base);
	// lis r11,3
	r11.s64 = 196608;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// ori r11,r11,17405
	r11.u64 = r11.u64 | 17405;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// addis r11,r11,39
	r11.s64 = r11.s64 + 2555904;
	// addi r11,r11,-24893
	r11.s64 = r11.s64 + -24893;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// rlwinm r3,r11,16,17,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x7FFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF0E0"))) PPC_WEAK_FUNC(sub_823DF0E0);
PPC_FUNC_IMPL(__imp__sub_823DF0E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x823df0f0
	if (!cr6.eq) goto loc_823DF0F0;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_823DF0F0:
	// addic. r11,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	r11.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823df120
	if (cr0.eq) goto loc_823DF120;
loc_823DF0F8:
	// lhz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823df120
	if (cr0.eq) goto loc_823DF120;
	// lhz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823df120
	if (!cr6.eq) goto loc_823DF120;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// addi r4,r4,2
	ctx.r4.s64 = ctx.r4.s64 + 2;
	// bne 0x823df0f8
	if (!cr0.eq) goto loc_823DF0F8;
loc_823DF120:
	// lhz r11,0(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// lhz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 0);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF130"))) PPC_WEAK_FUNC(sub_823DF130);
PPC_FUNC_IMPL(__imp__sub_823DF130) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823DF138;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r28
	r31.u64 = r28.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823df158
	if (cr6.eq) goto loc_823DF158;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
loc_823DF158:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823df190
	if (!cr6.eq) goto loc_823DF190;
	// bl 0x823e1000
	ctx.lr = 0x823DF164;
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
	ctx.lr = 0x823DF184;
	sub_823E02A8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f1,-17600(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// b 0x823df2bc
	goto loc_823DF2BC;
loc_823DF190:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r30,r11,-18352
	r30.s64 = r11.s64 + -18352;
	// lwz r11,-18352(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18352);
loc_823DF19C:
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x823df1c0
	if (!cr6.gt) goto loc_823DF1C0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lbz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x823e5100
	ctx.lr = 0x823DF1B8;
	sub_823E5100(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823df1d4
	goto loc_823DF1D4;
loc_823DF1C0:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// lwz r9,200(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// lhzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r3,r10,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
loc_823DF1D4:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823df1e4
	if (cr6.eq) goto loc_823DF1E4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// b 0x823df19c
	goto loc_823DF19C;
loc_823DF1E4:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823DF1E8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823df1e8
	if (!cr6.eq) goto loc_823DF1E8;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823e5130
	ctx.lr = 0x823DF21C;
	sub_823E5130(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823df230
	if (cr6.eq) goto loc_823DF230;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823DF230:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// andi. r10,r11,576
	ctx.r10.u64 = r11.u64 & 576;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823df258
	if (cr0.eq) goto loc_823DF258;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lfd f31,-17600(r11)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// beq cr6,0x823df2b8
	if (cr6.eq) goto loc_823DF2B8;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// b 0x823df2b8
	goto loc_823DF2B8;
loc_823DF258:
	// andi. r10,r11,129
	ctx.r10.u64 = r11.u64 & 129;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823df288
	if (cr0.eq) goto loc_823DF288;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,45
	cr6.compare<uint32_t>(r11.u32, 45, xer);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// bne cr6,0x823df280
	if (!cr6.eq) goto loc_823DF280;
	// lfd f0,-8816(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + -8816);
	// fneg f31,f0
	f31.u64 = f0.u64 ^ 0x8000000000000000;
	// b 0x823df2a4
	goto loc_823DF2A4;
loc_823DF280:
	// lfd f31,-8816(r11)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(r11.u32 + -8816);
	// b 0x823df2a4
	goto loc_823DF2A4;
loc_823DF288:
	// rlwinm. r11,r11,0,23,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823df2b4
	if (cr0.eq) goto loc_823DF2B4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f0,16(r3)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// lfd f31,-17600(r11)
	f31.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x823df2b4
	if (!cr6.eq) goto loc_823DF2B4;
loc_823DF2A4:
	// bl 0x823e1000
	ctx.lr = 0x823DF2A8;
	sub_823E1000(ctx, base);
	// li r11,34
	r11.s64 = 34;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// b 0x823df2b8
	goto loc_823DF2B8;
loc_823DF2B4:
	// lfd f31,16(r3)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
loc_823DF2B8:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_823DF2BC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823DF2C8"))) PPC_WEAK_FUNC(sub_823DF2C8);
PPC_FUNC_IMPL(__imp__sub_823DF2C8) {
	PPC_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x823df130
	sub_823DF130(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DF2D0"))) PPC_WEAK_FUNC(sub_823DF2D0);
PPC_FUNC_IMPL(__imp__sub_823DF2D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-18576
	r11.s64 = r11.s64 + -18576;
	// lwz r11,200(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// lhzx r11,r10,r11
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r11.u32);
	// rlwinm r3,r11,0,29,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF2EC"))) PPC_WEAK_FUNC(sub_823DF2EC);
PPC_FUNC_IMPL(__imp__sub_823DF2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF2F0"))) PPC_WEAK_FUNC(sub_823DF2F0);
PPC_FUNC_IMPL(__imp__sub_823DF2F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-18576
	r11.s64 = r11.s64 + -18576;
	// lwz r11,200(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// lhzx r11,r10,r11
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r11.u32);
	// rlwinm r3,r11,0,24,24
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF30C"))) PPC_WEAK_FUNC(sub_823DF30C);
PPC_FUNC_IMPL(__imp__sub_823DF30C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF310"))) PPC_WEAK_FUNC(sub_823DF310);
PPC_FUNC_IMPL(__imp__sub_823DF310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-18576
	r11.s64 = r11.s64 + -18576;
	// lwz r11,200(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// lhzx r11,r10,r11
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r11.u32);
	// rlwinm r3,r11,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF32C"))) PPC_WEAK_FUNC(sub_823DF32C);
PPC_FUNC_IMPL(__imp__sub_823DF32C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF330"))) PPC_WEAK_FUNC(sub_823DF330);
PPC_FUNC_IMPL(__imp__sub_823DF330) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-18576
	r11.s64 = r11.s64 + -18576;
	// lwz r11,200(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// lhzx r11,r10,r11
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r11.u32);
	// andi. r3,r11,263
	ctx.r3.u64 = r11.u64 & 263;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF34C"))) PPC_WEAK_FUNC(sub_823DF34C);
PPC_FUNC_IMPL(__imp__sub_823DF34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF350"))) PPC_WEAK_FUNC(sub_823DF350);
PPC_FUNC_IMPL(__imp__sub_823DF350) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9608(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9608);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x823e2a08
	ctx.lr = 0x823DF37C;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823df3dc
	if (cr6.eq) goto loc_823DF3DC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r9,r11,-10648
	ctx.r9.s64 = r11.s64 + -10648;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
loc_823DF39C:
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823df3cc
	if (cr6.eq) goto loc_823DF3CC;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x823df3c0
	if (cr6.eq) goto loc_823DF3C0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823df39c
	goto loc_823DF39C;
loc_823DF3C0:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x823e2c38
	ctx.lr = 0x823DF3CC;
	sub_823E2C38(ctx, base);
loc_823DF3CC:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x823e2c38
	ctx.lr = 0x823DF3D4;
	sub_823E2C38(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_823DF3DC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	r12.s64 = r31.s64 + 112;
	// bl 0x823df400
	ctx.lr = 0x823DF3E8;
	sub_823DF400(ctx, base);
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_823DF358"))) PPC_WEAK_FUNC(sub_823DF358);
PPC_FUNC_IMPL(__imp__sub_823DF358) {
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
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x823e2a08
	ctx.lr = 0x823DF37C;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823df3dc
	if (cr6.eq) goto loc_823DF3DC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r9,r11,-10648
	ctx.r9.s64 = r11.s64 + -10648;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
loc_823DF39C:
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823df3cc
	if (cr6.eq) goto loc_823DF3CC;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x823df3c0
	if (cr6.eq) goto loc_823DF3C0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823df39c
	goto loc_823DF39C;
loc_823DF3C0:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x823e2c38
	ctx.lr = 0x823DF3CC;
	sub_823E2C38(ctx, base);
loc_823DF3CC:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x823e2c38
	ctx.lr = 0x823DF3D4;
	sub_823E2C38(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_823DF3DC:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	r12.s64 = r31.s64 + 112;
	// bl 0x823df400
	ctx.lr = 0x823DF3E8;
	sub_823DF400(ctx, base);
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_823DF400"))) PPC_WEAK_FUNC(sub_823DF400);
PPC_FUNC_IMPL(__imp__sub_823DF400) {
	PPC_FUNC_PROLOGUE();
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
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x823e28a8
	ctx.lr = 0x823DF414;
	sub_823E28A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF424"))) PPC_WEAK_FUNC(sub_823DF424);
PPC_FUNC_IMPL(__imp__sub_823DF424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF428"))) PPC_WEAK_FUNC(sub_823DF428);
PPC_FUNC_IMPL(__imp__sub_823DF428) {
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
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x823DF448;
	sub_823DF058(ctx, base);
	// cmpwi cr6,r3,101
	cr6.compare<int32_t>(ctx.r3.s32, 101, xer);
	// beq cr6,0x823df464
	if (cr6.eq) goto loc_823DF464;
loc_823DF450:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lbz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// bl 0x823df2d0
	ctx.lr = 0x823DF45C;
	sub_823DF2D0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823df450
	if (!cr0.eq) goto loc_823DF450;
loc_823DF464:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x823DF470;
	sub_823DF058(ctx, base);
	// cmpwi cr6,r3,120
	cr6.compare<int32_t>(ctx.r3.s32, 120, xer);
	// bne cr6,0x823df47c
	if (!cr6.eq) goto loc_823DF47C;
	// addi r31,r31,2
	r31.s64 = r31.s64 + 2;
loc_823DF47C:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// lwz r11,-17324(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17324);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// lbz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// stb r9,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r9.u8);
loc_823DF498:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823df498
	if (!cr6.eq) goto loc_823DF498;
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

__attribute__((alias("__imp__sub_823DF4C8"))) PPC_WEAK_FUNC(sub_823DF4C8);
PPC_FUNC_IMPL(__imp__sub_823DF4C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb. r11,r11
	r11.s64 = r11.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r9,-17324(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17324);
	// beq 0x823df500
	if (cr0.eq) goto loc_823DF500;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lbz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
loc_823DF4E8:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x823df500
	if (cr6.eq) goto loc_823DF500;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb. r11,r11
	r11.s64 = r11.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823df4e8
	if (!cr0.eq) goto loc_823DF4E8;
loc_823DF500:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823df528
	goto loc_823DF528;
loc_823DF514:
	// cmpwi cr6,r10,101
	cr6.compare<int32_t>(ctx.r10.s32, 101, xer);
	// beq cr6,0x823df534
	if (cr6.eq) goto loc_823DF534;
	// cmpwi cr6,r10,69
	cr6.compare<int32_t>(ctx.r10.s32, 69, xer);
	// beq cr6,0x823df534
	if (cr6.eq) goto loc_823DF534;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_823DF528:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb. r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823df514
	if (!cr0.eq) goto loc_823DF514;
loc_823DF534:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823DF538:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r8,48
	cr6.compare<uint32_t>(ctx.r8.u32, 48, xer);
	// beq cr6,0x823df538
	if (cr6.eq) goto loc_823DF538;
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// lbz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bne cr6,0x823df560
	if (!cr6.eq) goto loc_823DF560;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_823DF560:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi r9,0
	cr0.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// bne 0x823df560
	if (!cr0.eq) goto loc_823DF560;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF57C"))) PPC_WEAK_FUNC(sub_823DF57C);
PPC_FUNC_IMPL(__imp__sub_823DF57C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF580"))) PPC_WEAK_FUNC(sub_823DF580);
PPC_FUNC_IMPL(__imp__sub_823DF580) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f13,0(r3)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfd f0,-17600(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DF5A0"))) PPC_WEAK_FUNC(sub_823DF5A0);
PPC_FUNC_IMPL(__imp__sub_823DF5A0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823df5d8
	if (cr6.eq) goto loc_823DF5D8;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x823e5c00
	ctx.lr = 0x823DF5CC;
	sub_823E5C00(ctx, base);
	// ld r11,88(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r11.u64);
	// b 0x823df5e8
	goto loc_823DF5E8;
loc_823DF5D8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823e5ca8
	ctx.lr = 0x823DF5E0;
	sub_823E5CA8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823DF5E8:
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

__attribute__((alias("__imp__sub_823DF5FC"))) PPC_WEAK_FUNC(sub_823DF5FC);
PPC_FUNC_IMPL(__imp__sub_823DF5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF600"))) PPC_WEAK_FUNC(sub_823DF600);
PPC_FUNC_IMPL(__imp__sub_823DF600) {
	PPC_FUNC_PROLOGUE();
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x823df5a0
	sub_823DF5A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DF608"))) PPC_WEAK_FUNC(sub_823DF608);
PPC_FUNC_IMPL(__imp__sub_823DF608) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823df428
	sub_823DF428(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DF610"))) PPC_WEAK_FUNC(sub_823DF610);
PPC_FUNC_IMPL(__imp__sub_823DF610) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823df4c8
	sub_823DF4C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DF618"))) PPC_WEAK_FUNC(sub_823DF618);
PPC_FUNC_IMPL(__imp__sub_823DF618) {
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
	ctx.lr = 0x823DF620;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823df66c
	if (!cr6.eq) goto loc_823DF66C;
	// bl 0x823e1000
	ctx.lr = 0x823DF644;
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
	ctx.lr = 0x823DF664;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823df884
	goto loc_823DF884;
loc_823DF66C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x823df6a0
	if (!cr6.eq) goto loc_823DF6A0;
	// bl 0x823e1000
	ctx.lr = 0x823DF678;
	sub_823E1000(ctx, base);
	// li r31,22
	r31.s64 = 22;
loc_823DF67C:
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
	ctx.lr = 0x823DF698;
	sub_823E02A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x823df884
	goto loc_823DF884;
loc_823DF6A0:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// mr r11,r31
	r11.u64 = r31.u64;
	// bgt cr6,0x823df6b0
	if (cr6.gt) goto loc_823DF6B0;
	// li r11,0
	r11.s64 = 0;
loc_823DF6B0:
	// addi r11,r11,9
	r11.s64 = r11.s64 + 9;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bgt cr6,0x823df6c8
	if (cr6.gt) goto loc_823DF6C8;
	// bl 0x823e1000
	ctx.lr = 0x823DF6C0;
	sub_823E1000(ctx, base);
	// li r31,34
	r31.s64 = 34;
	// b 0x823df67c
	goto loc_823DF67C;
loc_823DF6C8:
	// extsb. r28,r8
	r28.s64 = ctx.r8.s8;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// beq 0x823df718
	if (cr0.eq) goto loc_823DF718;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,-45
	r11.s64 = r11.s64 + -45;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// ble cr6,0x823df718
	if (!cr6.gt) goto loc_823DF718;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823DF6F0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823df6f0
	if (!cr6.eq) goto loc_823DF6F0;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// bl 0x823db5b0
	ctx.lr = 0x823DF718;
	sub_823DB5B0(ctx, base);
loc_823DF718:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r26,45
	r26.s64 = 45;
	// cmpwi cr6,r10,45
	cr6.compare<int32_t>(ctx.r10.s32, 45, xer);
	// bne cr6,0x823df734
	if (!cr6.eq) goto loc_823DF734;
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// stb r26,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r26.u8);
loc_823DF734:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x823df760
	if (!cr6.gt) goto loc_823DF760;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwz r9,-17324(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17324);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lbz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
loc_823DF760:
	// cntlzw r10,r28
	ctx.r10.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// bne cr6,0x823df780
	if (!cr6.eq) goto loc_823DF780;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x823df788
	goto loc_823DF788;
loc_823DF780:
	// subf r11,r31,r30
	r11.s64 = r30.s64 - r31.s64;
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
loc_823DF788:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,-11372
	ctx.r5.s64 = r11.s64 + -11372;
	// bl 0x823e2530
	ctx.lr = 0x823DF798;
	sub_823E2530(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823df7b8
	if (cr0.eq) goto loc_823DF7B8;
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
	// bl 0x823e02f0
	ctx.lr = 0x823DF7B8;
	sub_823E02F0(ctx, base);
loc_823DF7B8:
	// addi r3,r31,2
	ctx.r3.s64 = r31.s64 + 2;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x823df7cc
	if (cr6.eq) goto loc_823DF7CC;
	// li r11,69
	r11.s64 = 69;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
loc_823DF7CC:
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r11,48
	cr6.compare<uint32_t>(r11.u32, 48, xer);
	// beq cr6,0x823df858
	if (cr6.eq) goto loc_823DF858;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x823df7f4
	if (!cr0.lt) goto loc_823DF7F4;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// stb r26,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r26.u8);
loc_823DF7F4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// blt cr6,0x823df820
	if (cr6.lt) goto loc_823DF820;
	// li r7,100
	ctx.r7.s64 = 100;
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// divw r9,r11,r7
	ctx.r9.s32 = r11.s32 / ctx.r7.s32;
	// divw r7,r11,r7
	ctx.r7.s32 = r11.s32 / ctx.r7.s32;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mulli r8,r7,100
	ctx.r8.s64 = ctx.r7.s64 * 100;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
loc_823DF820:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x823df84c
	if (cr6.lt) goto loc_823DF84C;
	// li r7,10
	ctx.r7.s64 = 10;
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// divw r9,r11,r7
	ctx.r9.s32 = r11.s32 / ctx.r7.s32;
	// divw r7,r11,r7
	ctx.r7.s32 = r11.s32 / ctx.r7.s32;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mulli r8,r7,10
	ctx.r8.s64 = ctx.r7.s64 * 10;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
loc_823DF84C:
	// lbz r9,1(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// stb r11,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, r11.u8);
loc_823DF858:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-9940(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9940);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823df880
	if (cr0.eq) goto loc_823DF880;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,48
	cr6.compare<uint32_t>(r11.u32, 48, xer);
	// bne cr6,0x823df880
	if (!cr6.eq) goto loc_823DF880;
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x823db5b0
	ctx.lr = 0x823DF880;
	sub_823DB5B0(ctx, base);
loc_823DF880:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DF884:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823DF88C"))) PPC_WEAK_FUNC(sub_823DF88C);
PPC_FUNC_IMPL(__imp__sub_823DF88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF890"))) PPC_WEAK_FUNC(sub_823DF890);
PPC_FUNC_IMPL(__imp__sub_823DF890) {
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
	ctx.lr = 0x823DF898;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// ld r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r6,22
	ctx.r6.s64 = 22;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x823e5fb8
	ctx.lr = 0x823DF8C4;
	sub_823E5FB8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823df8f8
	if (!cr6.eq) goto loc_823DF8F8;
loc_823DF8CC:
	// bl 0x823e1000
	ctx.lr = 0x823DF8D0;
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
	ctx.lr = 0x823DF8F0;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823df99c
	goto loc_823DF99C;
loc_823DF8F8:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823df8cc
	if (cr6.eq) goto loc_823DF8CC;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// bne cr6,0x823df914
	if (!cr6.eq) goto loc_823DF914;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x823df938
	goto loc_823DF938;
loc_823DF914:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x823df924
	if (cr6.gt) goto loc_823DF924;
	// li r11,0
	r11.s64 = 0;
loc_823DF924:
	// addi r10,r9,-45
	ctx.r10.s64 = ctx.r9.s64 + -45;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// subf r10,r10,r29
	ctx.r10.s64 = r29.s64 - ctx.r10.s64;
	// subf r4,r11,r10
	ctx.r4.s64 = ctx.r10.s64 - r11.s64;
loc_823DF938:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bgt cr6,0x823df948
	if (cr6.gt) goto loc_823DF948;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823DF948:
	// addi r11,r9,-45
	r11.s64 = ctx.r9.s64 + -45;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r5,r30,1
	ctx.r5.s64 = r30.s64 + 1;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823e5d50
	ctx.lr = 0x823DF968;
	sub_823E5D50(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823df97c
	if (cr0.eq) goto loc_823DF97C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// b 0x823df99c
	goto loc_823DF99C;
loc_823DF97C:
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823df618
	ctx.lr = 0x823DF99C;
	sub_823DF618(ctx, base);
loc_823DF99C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823DF9A4"))) PPC_WEAK_FUNC(sub_823DF9A4);
PPC_FUNC_IMPL(__imp__sub_823DF9A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DF9A8"))) PPC_WEAK_FUNC(sub_823DF9A8);
PPC_FUNC_IMPL(__imp__sub_823DF9A8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823DF9B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,48
	r28.s64 = 48;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r30,1023
	r30.s64 = 1023;
	// li r26,0
	r26.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge cr6,0x823df9d8
	if (!cr6.lt) goto loc_823DF9D8;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
loc_823DF9D8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823dfa0c
	if (!cr6.eq) goto loc_823DFA0C;
	// bl 0x823e1000
	ctx.lr = 0x823DF9E4;
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
	ctx.lr = 0x823DFA04;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823dfde4
	goto loc_823DFDE4;
loc_823DFA0C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x823dfa40
	if (!cr6.eq) goto loc_823DFA40;
	// bl 0x823e1000
	ctx.lr = 0x823DFA18;
	sub_823E1000(ctx, base);
	// li r31,22
	r31.s64 = 22;
loc_823DFA1C:
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
	ctx.lr = 0x823DFA38;
	sub_823E02A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x823dfde4
	goto loc_823DFDE4;
loc_823DFA40:
	// addi r11,r6,11
	r11.s64 = ctx.r6.s64 + 11;
	// stb r26,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r26.u8);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bgt cr6,0x823dfa5c
	if (cr6.gt) goto loc_823DFA5C;
	// bl 0x823e1000
	ctx.lr = 0x823DFA54;
	sub_823E1000(ctx, base);
	// li r31,34
	r31.s64 = 34;
	// b 0x823dfa1c
	goto loc_823DFA1C;
loc_823DFA5C:
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,20,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFE;
	// cmpldi cr6,r10,4094
	cr6.compare<uint64_t>(ctx.r10.u64, 4094, xer);
	// bne cr6,0x823dfb04
	if (!cr6.eq) goto loc_823DFB04;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// bne cr6,0x823dfa7c
	if (!cr6.eq) goto loc_823DFA7C;
	// li r5,-1
	ctx.r5.s64 = -1;
	// b 0x823dfa80
	goto loc_823DFA80;
loc_823DFA7C:
	// addi r5,r5,-2
	ctx.r5.s64 = ctx.r5.s64 + -2;
loc_823DFA80:
	// addi r30,r31,2
	r30.s64 = r31.s64 + 2;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823df890
	ctx.lr = 0x823DFA94;
	sub_823DF890(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823dfaa4
	if (cr0.eq) goto loc_823DFAA4;
	// stb r26,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r26.u8);
	// b 0x823dfde4
	goto loc_823DFDE4;
loc_823DFAA4:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,45
	cr6.compare<uint32_t>(r11.u32, 45, xer);
	// bne cr6,0x823dfab8
	if (!cr6.eq) goto loc_823DFAB8;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_823DFAB8:
	// subfic r10,r29,0
	xer.ca = r29.u32 <= 0;
	ctx.r10.s64 = 0 - r29.s64;
	// stb r28,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r28.u8);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// rlwinm r10,r10,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFE0;
	// li r4,101
	ctx.r4.s64 = 101;
	// addi r11,r10,120
	r11.s64 = ctx.r10.s64 + 120;
	// stb r11,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r11.u8);
	// bl 0x823db6d0
	ctx.lr = 0x823DFAE0;
	sub_823DB6D0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x823dfde0
	if (cr0.eq) goto loc_823DFDE0;
	// subfic r11,r29,0
	xer.ca = r29.u32 <= 0;
	r11.s64 = 0 - r29.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r11,0,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r11,r11,112
	r11.s64 = r11.s64 + 112;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// stb r26,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, r26.u8);
	// b 0x823dfde0
	goto loc_823DFDE0;
loc_823DFB04:
	// clrldi r11,r11,63
	r11.u64 = r11.u64 & 0x1;
	// li r27,45
	r27.s64 = 45;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x823dfb1c
	if (cr6.eq) goto loc_823DFB1C;
	// stb r27,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r27.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_823DFB1C:
	// subfic r10,r29,0
	xer.ca = r29.u32 <= 0;
	ctx.r10.s64 = 0 - r29.s64;
	// stb r28,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r28.u8);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r9,r29,0
	xer.ca = r29.u32 <= 0;
	ctx.r9.s64 = 0 - r29.s64;
	// rlwinm r10,r10,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFE0;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r8,r10,120
	ctx.r8.s64 = ctx.r10.s64 + 120;
	// rlwinm r10,r9,0,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFE0;
	// stb r8,1(r31)
	PPC_STORE_U8(r31.u32 + 1, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// ld r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r10,97
	ctx.r10.s64 = ctx.r10.s64 + 97;
	// rlwinm r9,r9,0,20,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFE;
	// addi r5,r10,-58
	ctx.r5.s64 = ctx.r10.s64 + -58;
	// cmpldi cr6,r9,0
	cr6.compare<uint64_t>(ctx.r9.u64, 0, xer);
	// bne cr6,0x823dfb88
	if (!cr6.eq) goto loc_823DFB88;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rldicr r10,r10,0,51
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 0) & 0xFFFFFFFFFFFFF000;
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// bne cr6,0x823dfb80
	if (!cr6.eq) goto loc_823DFB80;
	// mr r30,r26
	r30.u64 = r26.u64;
	// b 0x823dfb94
	goto loc_823DFB94;
loc_823DFB80:
	// li r30,1022
	r30.s64 = 1022;
	// b 0x823dfb94
	goto loc_823DFB94;
loc_823DFB88:
	// li r10,49
	ctx.r10.s64 = 49;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_823DFB94:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x823dfbac
	if (!cr6.eq) goto loc_823DFBAC;
	// stb r26,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r26.u8);
	// b 0x823dfbc0
	goto loc_823DFBC0;
loc_823DFBAC:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r11,-17324(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17324);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
loc_823DFBC0:
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rldicr r11,r11,0,51
	r11.u64 = __builtin_rotateleft64(r11.u64, 0) & 0xFFFFFFFFFFFFF000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// ble cr6,0x823dfcb8
	if (!cr6.gt) goto loc_823DFCB8;
	// li r10,15
	ctx.r10.s64 = 15;
	// rldicr r10,r10,48,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 48) & 0xFFFF000000000000;
loc_823DFBD8:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x823dfc30
	if (!cr6.gt) goto loc_823DFC30;
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// rldicl r11,r11,52,12
	r11.u64 = __builtin_rotateleft64(r11.u64, 52) & 0xFFFFFFFFFFFFF;
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// srd r11,r11,r9
	r11.u64 = ctx.r9.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r9.u8 & 0x7F));
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r9,57
	cr6.compare<uint32_t>(ctx.r9.u32, 57, xer);
	// ble cr6,0x823dfc14
	if (!cr6.gt) goto loc_823DFC14;
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
loc_823DFC14:
	// addi r9,r7,-4
	ctx.r9.s64 = ctx.r7.s64 + -4;
	// stb r11,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r11.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// extsh. r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// rldicl r10,r10,60,4
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 60) & 0xFFFFFFFFFFFFFFF;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// bge 0x823dfbd8
	if (!cr0.lt) goto loc_823DFBD8;
loc_823DFC30:
	// extsh. r11,r7
	r11.s64 = ctx.r7.s16;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x823dfcb8
	if (cr0.lt) goto loc_823DFCB8;
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// rldicl r11,r11,52,12
	r11.u64 = __builtin_rotateleft64(r11.u64, 52) & 0xFFFFFFFFFFFFF;
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// srd r11,r11,r9
	r11.u64 = ctx.r9.u8 & 0x40 ? 0 : (r11.u64 >> (ctx.r9.u8 & 0x7F));
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// ble cr6,0x823dfcb8
	if (!cr6.gt) goto loc_823DFCB8;
	// addi r11,r8,-1
	r11.s64 = ctx.r8.s64 + -1;
loc_823DFC5C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,102
	cr6.compare<int32_t>(ctx.r10.s32, 102, xer);
	// beq cr6,0x823dfc74
	if (cr6.eq) goto loc_823DFC74;
	// cmpwi cr6,r10,70
	cr6.compare<int32_t>(ctx.r10.s32, 70, xer);
	// bne cr6,0x823dfc80
	if (!cr6.eq) goto loc_823DFC80;
loc_823DFC74:
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// b 0x823dfc5c
	goto loc_823DFC5C;
loc_823DFC80:
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x823dfcac
	if (cr6.eq) goto loc_823DFCAC;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,57
	cr6.compare<int32_t>(ctx.r10.s32, 57, xer);
	// bne cr6,0x823dfca0
	if (!cr6.eq) goto loc_823DFCA0;
	// addi r10,r5,58
	ctx.r10.s64 = ctx.r5.s64 + 58;
	// b 0x823dfca4
	goto loc_823DFCA4;
loc_823DFCA0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_823DFCA4:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// b 0x823dfcb8
	goto loc_823DFCB8;
loc_823DFCAC:
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r10,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r10.u8);
loc_823DFCB8:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x823dfce4
	if (!cr6.gt) goto loc_823DFCE4;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq 0x823dfce0
	if (cr0.eq) goto loc_823DFCE0;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_823DFCD4:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x823dfcd4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DFCD4;
loc_823DFCE0:
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
loc_823DFCE4:
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823dfcf4
	if (!cr6.eq) goto loc_823DFCF4;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
loc_823DFCF4:
	// subfic r11,r29,0
	xer.ca = r29.u32 <= 0;
	r11.s64 = 0 - r29.s64;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r11,0,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r11,r11,112
	r11.s64 = r11.s64 + 112;
	// stb r11,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, r11.u8);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rldicl r11,r11,63,53
	r11.u64 = __builtin_rotateleft64(r11.u64, 63) & 0x7FF;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// blt cr6,0x823dfd2c
	if (cr6.lt) goto loc_823DFD2C;
	// li r9,43
	ctx.r9.s64 = 43;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// b 0x823dfd34
	goto loc_823DFD34;
loc_823DFD2C:
	// stb r27,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r27.u8);
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_823DFD34:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpdi cr6,r11,1000
	cr6.compare<int64_t>(r11.s64, 1000, xer);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// stb r28,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r28.u8);
	// blt cr6,0x823dfd74
	if (cr6.lt) goto loc_823DFD74;
	// li r9,1000
	ctx.r9.s64 = 1000;
	// divd r7,r11,r9
	ctx.r7.s64 = r11.s64 / ctx.r9.s64;
	// divd r6,r11,r9
	ctx.r6.s64 = r11.s64 / ctx.r9.s64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mulli r7,r6,1000
	ctx.r7.s64 = ctx.r6.s64 * 1000;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bne cr6,0x823dfd7c
	if (!cr6.eq) goto loc_823DFD7C;
loc_823DFD74:
	// cmpdi cr6,r11,100
	cr6.compare<int64_t>(r11.s64, 100, xer);
	// blt cr6,0x823dfda0
	if (cr6.lt) goto loc_823DFDA0;
loc_823DFD7C:
	// li r9,100
	ctx.r9.s64 = 100;
	// divd r7,r11,r9
	ctx.r7.s64 = r11.s64 / ctx.r9.s64;
	// divd r6,r11,r9
	ctx.r6.s64 = r11.s64 / ctx.r9.s64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mulli r7,r6,100
	ctx.r7.s64 = ctx.r6.s64 * 100;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_823DFDA0:
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bne cr6,0x823dfdb0
	if (!cr6.eq) goto loc_823DFDB0;
	// cmpdi cr6,r11,10
	cr6.compare<int64_t>(r11.s64, 10, xer);
	// blt cr6,0x823dfdd4
	if (cr6.lt) goto loc_823DFDD4;
loc_823DFDB0:
	// li r9,10
	ctx.r9.s64 = 10;
	// divd r8,r11,r9
	ctx.r8.s64 = r11.s64 / ctx.r9.s64;
	// divd r7,r11,r9
	ctx.r7.s64 = r11.s64 / ctx.r9.s64;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mulli r8,r7,10
	ctx.r8.s64 = ctx.r7.s64 * 10;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_823DFDD4:
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// stb r26,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, r26.u8);
loc_823DFDE0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DFDE4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823DFDEC"))) PPC_WEAK_FUNC(sub_823DFDEC);
PPC_FUNC_IMPL(__imp__sub_823DFDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DFDF0"))) PPC_WEAK_FUNC(sub_823DFDF0);
PPC_FUNC_IMPL(__imp__sub_823DFDF0) {
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
	ctx.lr = 0x823DFDF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// bne cr6,0x823dfe40
	if (!cr6.eq) goto loc_823DFE40;
loc_823DFE14:
	// bl 0x823e1000
	ctx.lr = 0x823DFE18;
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
	ctx.lr = 0x823DFE38;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823dffac
	goto loc_823DFFAC;
loc_823DFE40:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823dfe14
	if (cr6.eq) goto loc_823DFE14;
	// extsb. r26,r7
	r26.s64 = ctx.r7.s8;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// li r28,48
	r28.s64 = 48;
	// beq 0x823dfe80
	if (cr0.eq) goto loc_823DFE80;
	// cmpw cr6,r10,r27
	cr6.compare<int32_t>(ctx.r10.s32, r27.s32, xer);
	// bne cr6,0x823dfe80
	if (!cr6.eq) goto loc_823DFE80;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,-45
	r11.s64 = r11.s64 + -45;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
loc_823DFE80:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,45
	cr6.compare<int32_t>(r11.s32, 45, xer);
	// bne cr6,0x823dfe98
	if (!cr6.eq) goto loc_823DFE98;
	// addi r30,r3,1
	r30.s64 = ctx.r3.s64 + 1;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
loc_823DFE98:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x823dfee0
	if (cr6.gt) goto loc_823DFEE0;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823DFEA8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823dfea8
	if (!cr6.eq) goto loc_823DFEA8;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r31,r30,1
	r31.s64 = r30.s64 + 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// bl 0x823db5b0
	ctx.lr = 0x823DFED8;
	sub_823DB5B0(ctx, base);
	// stb r28,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r28.u8);
	// b 0x823dfee4
	goto loc_823DFEE4;
loc_823DFEE0:
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
loc_823DFEE4:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x823dffa8
	if (!cr6.gt) goto loc_823DFFA8;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823DFEF0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823dfef0
	if (!cr6.eq) goto loc_823DFEF0;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r30,r31,1
	r30.s64 = r31.s64 + 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// bl 0x823db5b0
	ctx.lr = 0x823DFF20;
	sub_823DB5B0(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r11,-17324(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17324);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x823dffa8
	if (!cr6.lt) goto loc_823DFFA8;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x823dff50
	if (cr6.eq) goto loc_823DFF50;
	// neg r27,r11
	r27.s64 = -r11.s64;
	// b 0x823dff60
	goto loc_823DFF60;
loc_823DFF50:
	// neg r11,r11
	r11.s64 = -r11.s64;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x823dff60
	if (cr6.lt) goto loc_823DFF60;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_823DFF60:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x823dff98
	if (cr6.eq) goto loc_823DFF98;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823DFF6C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823dff6c
	if (!cr6.eq) goto loc_823DFF6C;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// add r3,r30,r27
	ctx.r3.u64 = r30.u64 + r27.u64;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// bl 0x823db5b0
	ctx.lr = 0x823DFF98;
	sub_823DB5B0(ctx, base);
loc_823DFF98:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,48
	ctx.r4.s64 = 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x823DFFA8;
	sub_823D9890(ctx, base);
loc_823DFFA8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DFFAC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823DFFB4"))) PPC_WEAK_FUNC(sub_823DFFB4);
PPC_FUNC_IMPL(__imp__sub_823DFFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DFFB8"))) PPC_WEAK_FUNC(sub_823DFFB8);
PPC_FUNC_IMPL(__imp__sub_823DFFB8) {
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
	ctx.lr = 0x823DFFC0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// ld r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r6,22
	ctx.r6.s64 = 22;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x823e5fb8
	ctx.lr = 0x823DFFE8;
	sub_823E5FB8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823e001c
	if (!cr6.eq) goto loc_823E001C;
loc_823DFFF0:
	// bl 0x823e1000
	ctx.lr = 0x823DFFF4;
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
	ctx.lr = 0x823E0014;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823e0098
	goto loc_823E0098;
loc_823E001C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823dfff0
	if (cr6.eq) goto loc_823DFFF0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// bne cr6,0x823e0038
	if (!cr6.eq) goto loc_823E0038;
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x823e0048
	goto loc_823E0048;
loc_823E0038:
	// addi r10,r11,-45
	ctx.r10.s64 = r11.s64 + -45;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// subf r4,r10,r29
	ctx.r4.s64 = r29.s64 - ctx.r10.s64;
loc_823E0048:
	// addi r10,r11,-45
	ctx.r10.s64 = r11.s64 + -45;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// add r5,r11,r30
	ctx.r5.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823e5d50
	ctx.lr = 0x823E0068;
	sub_823E5D50(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e007c
	if (cr0.eq) goto loc_823E007C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// b 0x823e0098
	goto loc_823E0098;
loc_823E007C:
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dfdf0
	ctx.lr = 0x823E0098;
	sub_823DFDF0(ctx, base);
loc_823E0098:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823E00A0"))) PPC_WEAK_FUNC(sub_823E00A0);
PPC_FUNC_IMPL(__imp__sub_823E00A0) {
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
	ctx.lr = 0x823E00A8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// ld r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r6,22
	ctx.r6.s64 = 22;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// bl 0x823e5fb8
	ctx.lr = 0x823E00D4;
	sub_823E5FB8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823e0108
	if (!cr6.eq) goto loc_823E0108;
loc_823E00DC:
	// bl 0x823e1000
	ctx.lr = 0x823E00E0;
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
	ctx.lr = 0x823E0100;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823e01e4
	goto loc_823E01E4;
loc_823E0108:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823e00dc
	if (cr6.eq) goto loc_823E00DC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r11,r11,-45
	r11.s64 = r11.s64 + -45;
	// addi r29,r10,-1
	r29.s64 = ctx.r10.s64 + -1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// add r28,r11,r30
	r28.u64 = r11.u64 + r30.u64;
	// beq cr6,0x823e013c
	if (cr6.eq) goto loc_823E013C;
	// subf r4,r11,r31
	ctx.r4.s64 = r31.s64 - r11.s64;
loc_823E013C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e5d50
	ctx.lr = 0x823E014C;
	sub_823E5D50(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e0160
	if (cr0.eq) goto loc_823E0160;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r11.u8);
	// b 0x823e01e4
	goto loc_823E01E4;
loc_823E0160:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823e0178
	if (cr6.lt) goto loc_823E0178;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823E0178:
	// cmpwi cr6,r11,-4
	cr6.compare<int32_t>(r11.s32, -4, xer);
	// blt cr6,0x823e01c4
	if (cr6.lt) goto loc_823E01C4;
	// cmpw cr6,r11,r27
	cr6.compare<int32_t>(r11.s32, r27.s32, xer);
	// bge cr6,0x823e01c4
	if (!cr6.lt) goto loc_823E01C4;
	// extsb. r11,r10
	r11.s64 = ctx.r10.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e01a4
	if (cr0.eq) goto loc_823E01A4;
loc_823E0190:
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e0190
	if (!cr6.eq) goto loc_823E0190;
	// stb r11,-2(r28)
	PPC_STORE_U8(r28.u32 + -2, r11.u8);
loc_823E01A4:
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dfdf0
	ctx.lr = 0x823E01C0;
	sub_823DFDF0(ctx, base);
	// b 0x823e01e4
	goto loc_823E01E4;
loc_823E01C4:
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823df618
	ctx.lr = 0x823E01E4;
	sub_823DF618(ctx, base);
loc_823E01E4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823E01EC"))) PPC_WEAK_FUNC(sub_823E01EC);
PPC_FUNC_IMPL(__imp__sub_823E01EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E01F0"))) PPC_WEAK_FUNC(sub_823E01F0);
PPC_FUNC_IMPL(__imp__sub_823E01F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmpwi cr6,r11,101
	cr6.compare<int32_t>(r11.s32, 101, xer);
	// beq cr6,0x823e0238
	if (cr6.eq) goto loc_823E0238;
	// cmpwi cr6,r11,69
	cr6.compare<int32_t>(r11.s32, 69, xer);
	// beq cr6,0x823e0238
	if (cr6.eq) goto loc_823E0238;
	// cmpwi cr6,r11,102
	cr6.compare<int32_t>(r11.s32, 102, xer);
	// bne cr6,0x823e0220
	if (!cr6.eq) goto loc_823E0220;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// b 0x823dffb8
	sub_823DFFB8(ctx, base);
	return;
loc_823E0220:
	// cmpwi cr6,r11,97
	cr6.compare<int32_t>(r11.s32, 97, xer);
	// beq cr6,0x823e0234
	if (cr6.eq) goto loc_823E0234;
	// cmpwi cr6,r11,65
	cr6.compare<int32_t>(r11.s32, 65, xer);
	// beq cr6,0x823e0234
	if (cr6.eq) goto loc_823E0234;
	// b 0x823e00a0
	sub_823E00A0(ctx, base);
	return;
loc_823E0234:
	// b 0x823df9a8
	sub_823DF9A8(ctx, base);
	return;
loc_823E0238:
	// b 0x823df890
	sub_823DF890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823E023C"))) PPC_WEAK_FUNC(sub_823E023C);
PPC_FUNC_IMPL(__imp__sub_823E023C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0240"))) PPC_WEAK_FUNC(sub_823E0240);
PPC_FUNC_IMPL(__imp__sub_823E0240) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// cmpwi cr6,r11,101
	cr6.compare<int32_t>(r11.s32, 101, xer);
	// beq cr6,0x823e028c
	if (cr6.eq) goto loc_823E028C;
	// cmpwi cr6,r11,69
	cr6.compare<int32_t>(r11.s32, 69, xer);
	// beq cr6,0x823e028c
	if (cr6.eq) goto loc_823E028C;
	// cmpwi cr6,r11,102
	cr6.compare<int32_t>(r11.s32, 102, xer);
	// bne cr6,0x823e026c
	if (!cr6.eq) goto loc_823E026C;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x823dffb8
	sub_823DFFB8(ctx, base);
	return;
loc_823E026C:
	// cmpwi cr6,r11,97
	cr6.compare<int32_t>(r11.s32, 97, xer);
	// beq cr6,0x823e0284
	if (cr6.eq) goto loc_823E0284;
	// cmpwi cr6,r11,65
	cr6.compare<int32_t>(r11.s32, 65, xer);
	// beq cr6,0x823e0284
	if (cr6.eq) goto loc_823E0284;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x823e00a0
	sub_823E00A0(ctx, base);
	return;
loc_823E0284:
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x823df9a8
	sub_823DF9A8(ctx, base);
	return;
loc_823E028C:
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x823df890
	sub_823DF890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823E0294"))) PPC_WEAK_FUNC(sub_823E0294);
PPC_FUNC_IMPL(__imp__sub_823E0294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0298"))) PPC_WEAK_FUNC(sub_823E0298);
PPC_FUNC_IMPL(__imp__sub_823E0298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32107
	r11.s64 = -2104164352;
	// stw r3,-22840(r11)
	PPC_STORE_U32(r11.u32 + -22840, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E02A4"))) PPC_WEAK_FUNC(sub_823E02A4);
PPC_FUNC_IMPL(__imp__sub_823E02A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E02A8"))) PPC_WEAK_FUNC(sub_823E02A8);
PPC_FUNC_IMPL(__imp__sub_823E02A8) {
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
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r11,-22840(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -22840);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x823e02d0
	if (cr0.eq) goto loc_823E02D0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E02CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823e02dc
	goto loc_823E02DC;
loc_823E02D0:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823e6060
	ctx.lr = 0x823E02D8;
	sub_823E6060(ctx, base);
	// twi 31,r0,22
loc_823E02DC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E02EC"))) PPC_WEAK_FUNC(sub_823E02EC);
PPC_FUNC_IMPL(__imp__sub_823E02EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E02F0"))) PPC_WEAK_FUNC(sub_823E02F0);
PPC_FUNC_IMPL(__imp__sub_823E02F0) {
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
	// stwu r1,-2816(r1)
	ea = -2816 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,2624
	ctx.r5.s64 = 2624;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823d9890
	ctx.lr = 0x823E030C;
	sub_823D9890(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,10
	ctx.r10.s64 = 10;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823E031C:
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x823e031c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823E031C;
	// lwz r10,2808(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2808);
	// lis r11,-16384
	r11.s64 = -1073741824;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,13
	r11.u64 = r11.u64 | 13;
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
	ctx.lr = 0x823E0354;
	sub_82131E30(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82131f00
	ctx.lr = 0x823E035C;
	sub_82131F00(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e036c
	if (!cr0.eq) goto loc_823E036C;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823e6060
	ctx.lr = 0x823E036C;
	sub_823E6060(ctx, base);
loc_823E036C:
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x827bd4b4
	ctx.lr = 0x823E0374;
	__imp__KeBugCheck(ctx, base);
}

__attribute__((alias("__imp__sub_823E0374"))) PPC_WEAK_FUNC(sub_823E0374);
PPC_FUNC_IMPL(__imp__sub_823E0374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0378"))) PPC_WEAK_FUNC(sub_823E0378);
PPC_FUNC_IMPL(__imp__sub_823E0378) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9632(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9632);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823E0388;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r29,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r29.u32);
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
	// bl 0x823e2a08
	ctx.lr = 0x823E03A8;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x823e0f88
	ctx.lr = 0x823E03B0;
	sub_823E0F88(ctx, base);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x823e0ef0
	ctx.lr = 0x823E03B8;
	sub_823E0EF0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e03d8
	if (cr0.eq) goto loc_823E03D8;
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
	// bl 0x823e02f0
	ctx.lr = 0x823E03D8;
	sub_823E02F0(ctx, base);
loc_823E03D8:
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x823e0e20
	ctx.lr = 0x823E03E0;
	sub_823E0E20(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e0400
	if (cr0.eq) goto loc_823E0400;
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
	// bl 0x823e02f0
	ctx.lr = 0x823E0400;
	sub_823E02F0(ctx, base);
loc_823E0400:
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x823e0e88
	ctx.lr = 0x823E0408;
	sub_823E0E88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e0428
	if (cr0.eq) goto loc_823E0428;
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
	// bl 0x823e02f0
	ctx.lr = 0x823E0428;
	sub_823E02F0(ctx, base);
loc_823E0428:
	// bl 0x823e6070
	ctx.lr = 0x823E042C;
	sub_823E6070(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r30,r11,-10640
	r30.s64 = r11.s64 + -10640;
	// addi r7,r8,-19780
	ctx.r7.s64 = ctx.r8.s64 + -19780;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// stw r11,172(r30)
	PPC_STORE_U32(r30.u32 + 172, r11.u32);
	// stw r10,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r9,-19780(r8)
	PPC_STORE_U32(ctx.r8.u32 + -19780, ctx.r9.u32);
	// beq cr6,0x823e046c
	if (cr6.eq) goto loc_823E046C;
	// bl 0x823e2c38
	ctx.lr = 0x823E0464;
	sub_823E2C38(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,176(r30)
	PPC_STORE_U32(r30.u32 + 176, r11.u32);
loc_823E046C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82457b88
	ctx.lr = 0x823E0474;
	sub_82457B88(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823e04e8
	if (cr6.eq) goto loc_823E04E8;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// mulli r9,r10,60
	ctx.r9.s64 = ctx.r10.s64 * 60;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// lhz r10,70(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 70);
	// stw r11,172(r30)
	PPC_STORE_U32(r30.u32 + 172, r11.u32);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,84(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// beq 0x823e04ac
	if (cr0.eq) goto loc_823E04AC;
	// mulli r10,r11,60
	ctx.r10.s64 = r11.s64 * 60;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
loc_823E04AC:
	// lhz r10,154(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 154);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823e04dc
	if (cr0.eq) goto loc_823E04DC;
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823e04dc
	if (cr6.eq) goto loc_823E04DC;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// li r10,1
	ctx.r10.s64 = 1;
	// mulli r11,r11,60
	r11.s64 = r11.s64 * 60;
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// b 0x823e04ec
	goto loc_823E04EC;
loc_823E04DC:
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
	// b 0x823e04ec
	goto loc_823E04EC;
loc_823E04E8:
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E04EC:
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// bl 0x823e0f78
	ctx.lr = 0x823E04F4;
	sub_823E0F78(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r30,84(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x823e0f58
	ctx.lr = 0x823E0500;
	sub_823E0F58(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r30,88(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x823e0f68
	ctx.lr = 0x823E050C;
	sub_823E0F68(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823e0524
	ctx.lr = 0x823E051C;
	sub_823E0524(ctx, base);
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E0380"))) PPC_WEAK_FUNC(sub_823E0380);
PPC_FUNC_IMPL(__imp__sub_823E0380) {
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
	ctx.lr = 0x823E0388;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r29,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r29.u32);
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
	// bl 0x823e2a08
	ctx.lr = 0x823E03A8;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x823e0f88
	ctx.lr = 0x823E03B0;
	sub_823E0F88(ctx, base);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x823e0ef0
	ctx.lr = 0x823E03B8;
	sub_823E0EF0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e03d8
	if (cr0.eq) goto loc_823E03D8;
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
	// bl 0x823e02f0
	ctx.lr = 0x823E03D8;
	sub_823E02F0(ctx, base);
loc_823E03D8:
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// bl 0x823e0e20
	ctx.lr = 0x823E03E0;
	sub_823E0E20(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e0400
	if (cr0.eq) goto loc_823E0400;
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
	// bl 0x823e02f0
	ctx.lr = 0x823E0400;
	sub_823E02F0(ctx, base);
loc_823E0400:
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x823e0e88
	ctx.lr = 0x823E0408;
	sub_823E0E88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e0428
	if (cr0.eq) goto loc_823E0428;
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
	// bl 0x823e02f0
	ctx.lr = 0x823E0428;
	sub_823E02F0(ctx, base);
loc_823E0428:
	// bl 0x823e6070
	ctx.lr = 0x823E042C;
	sub_823E6070(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r30,r11,-10640
	r30.s64 = r11.s64 + -10640;
	// addi r7,r8,-19780
	ctx.r7.s64 = ctx.r8.s64 + -19780;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// stw r11,172(r30)
	PPC_STORE_U32(r30.u32 + 172, r11.u32);
	// stw r10,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r9,-19780(r8)
	PPC_STORE_U32(ctx.r8.u32 + -19780, ctx.r9.u32);
	// beq cr6,0x823e046c
	if (cr6.eq) goto loc_823E046C;
	// bl 0x823e2c38
	ctx.lr = 0x823E0464;
	sub_823E2C38(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,176(r30)
	PPC_STORE_U32(r30.u32 + 176, r11.u32);
loc_823E046C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82457b88
	ctx.lr = 0x823E0474;
	sub_82457B88(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823e04e8
	if (cr6.eq) goto loc_823E04E8;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// mulli r9,r10,60
	ctx.r9.s64 = ctx.r10.s64 * 60;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// lhz r10,70(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 70);
	// stw r11,172(r30)
	PPC_STORE_U32(r30.u32 + 172, r11.u32);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,84(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// beq 0x823e04ac
	if (cr0.eq) goto loc_823E04AC;
	// mulli r10,r11,60
	ctx.r10.s64 = r11.s64 * 60;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
loc_823E04AC:
	// lhz r10,154(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 154);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823e04dc
	if (cr0.eq) goto loc_823E04DC;
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823e04dc
	if (cr6.eq) goto loc_823E04DC;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// li r10,1
	ctx.r10.s64 = 1;
	// mulli r11,r11,60
	r11.s64 = r11.s64 * 60;
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// b 0x823e04ec
	goto loc_823E04EC;
loc_823E04DC:
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
	// b 0x823e04ec
	goto loc_823E04EC;
loc_823E04E8:
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E04EC:
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// bl 0x823e0f78
	ctx.lr = 0x823E04F4;
	sub_823E0F78(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r30,84(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x823e0f58
	ctx.lr = 0x823E0500;
	sub_823E0F58(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r30,88(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// bl 0x823e0f68
	ctx.lr = 0x823E050C;
	sub_823E0F68(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823e0524
	ctx.lr = 0x823E051C;
	sub_823E0524(ctx, base);
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E0524"))) PPC_WEAK_FUNC(sub_823E0524);
PPC_FUNC_IMPL(__imp__sub_823E0524) {
	PPC_FUNC_PROLOGUE();
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
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x823e28a8
	ctx.lr = 0x823E0538;
	sub_823E28A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0548"))) PPC_WEAK_FUNC(sub_823E0548);
PPC_FUNC_IMPL(__imp__sub_823E0548) {
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
	ctx.lr = 0x823E0550;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bne cr6,0x823e0680
	if (!cr6.eq) goto loc_823E0680;
	// srawi r9,r30,2
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x3) != 0);
	ctx.r9.s64 = r30.s32 >> 2;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r31,400
	r31.s64 = 400;
	// subf. r28,r5,r30
	r28.s64 = r30.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// li r4,100
	ctx.r4.s64 = 100;
	// addi r27,r11,-17268
	r27.s64 = r11.s64 + -17268;
	// addi r26,r9,-17320
	r26.s64 = ctx.r9.s64 + -17320;
	// bne 0x823e05a4
	if (!cr0.eq) goto loc_823E05A4;
	// divw r11,r30,r4
	r11.s32 = r30.s32 / ctx.r4.s32;
	// mulli r11,r11,100
	r11.s64 = r11.s64 * 100;
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e05c4
	if (!cr0.eq) goto loc_823E05C4;
loc_823E05A4:
	// addi r11,r30,1900
	r11.s64 = r30.s64 + 1900;
	// divw r9,r11,r31
	ctx.r9.s32 = r11.s32 / r31.s32;
	// mulli r9,r9,400
	ctx.r9.s64 = ctx.r9.s64 * 400;
	// subf. r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e05c4
	if (cr0.eq) goto loc_823E05C4;
	// rlwinm r29,r6,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r29,r27
	r11.u64 = r29.u64 + r27.u64;
	// b 0x823e05cc
	goto loc_823E05CC;
loc_823E05C4:
	// rlwinm r29,r6,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r29,r26
	r11.u64 = r29.u64 + r26.u64;
loc_823E05CC:
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addi r11,r30,-1
	r11.s64 = r30.s64 + -1;
	// addi r9,r30,299
	ctx.r9.s64 = r30.s64 + 299;
	// divw r6,r11,r4
	ctx.r6.s32 = r11.s32 / ctx.r4.s32;
	// divw r9,r9,r31
	ctx.r9.s32 = ctx.r9.s32 / r31.s32;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// mulli r6,r30,365
	ctx.r6.s64 = r30.s64 * 365;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// li r6,7
	ctx.r6.s64 = 7;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r9,r9,-25563
	ctx.r9.s64 = ctx.r9.s64 + -25563;
	// divw r6,r9,r6
	ctx.r6.s32 = ctx.r9.s32 / ctx.r6.s32;
	// mulli r6,r6,7
	ctx.r6.s64 = ctx.r6.s64 * 7;
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// mulli r6,r7,7
	ctx.r6.s64 = ctx.r7.s64 * 7;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// subf r9,r9,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r9.s64;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// bgt cr6,0x823e0630
	if (cr6.gt) goto loc_823E0630;
	// addi r11,r11,-7
	r11.s64 = r11.s64 + -7;
loc_823E0630:
	// cmpwi cr6,r7,5
	cr6.compare<int32_t>(ctx.r7.s32, 5, xer);
	// bne cr6,0x823e06e4
	if (!cr6.eq) goto loc_823E06E4;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x823e0650
	if (!cr6.eq) goto loc_823E0650;
	// divw r9,r30,r4
	ctx.r9.s32 = r30.s32 / ctx.r4.s32;
	// mulli r9,r9,100
	ctx.r9.s64 = ctx.r9.s64 * 100;
	// subf. r9,r9,r30
	ctx.r9.s64 = r30.s64 - ctx.r9.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x823e066c
	if (!cr0.eq) goto loc_823E066C;
loc_823E0650:
	// addi r9,r30,1900
	ctx.r9.s64 = r30.s64 + 1900;
	// divw r8,r9,r31
	ctx.r8.s32 = ctx.r9.s32 / r31.s32;
	// mulli r8,r8,400
	ctx.r8.s64 = ctx.r8.s64 * 400;
	// subf. r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823e066c
	if (cr0.eq) goto loc_823E066C;
	// lwzx r9,r29,r27
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r27.u32);
	// b 0x823e0670
	goto loc_823E0670;
loc_823E066C:
	// lwzx r9,r29,r26
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r26.u32);
loc_823E0670:
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x823e06e4
	if (!cr6.gt) goto loc_823E06E4;
	// addi r11,r11,-7
	r11.s64 = r11.s64 + -7;
	// b 0x823e06e4
	goto loc_823E06E4;
loc_823E0680:
	// srawi r11,r30,2
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x3) != 0);
	r11.s64 = r30.s32 >> 2;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e06a8
	if (!cr0.eq) goto loc_823E06A8;
	// li r11,100
	r11.s64 = 100;
	// divw r11,r30,r11
	r11.s32 = r30.s32 / r11.s32;
	// mulli r11,r11,100
	r11.s64 = r11.s64 * 100;
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e06cc
	if (!cr0.eq) goto loc_823E06CC;
loc_823E06A8:
	// addi r11,r30,1900
	r11.s64 = r30.s64 + 1900;
	// li r8,400
	ctx.r8.s64 = 400;
	// divw r8,r11,r8
	ctx.r8.s32 = r11.s32 / ctx.r8.s32;
	// mulli r8,r8,400
	ctx.r8.s64 = ctx.r8.s64 * 400;
	// subf. r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e06cc
	if (cr0.eq) goto loc_823E06CC;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r8,r8,-17268
	ctx.r8.s64 = ctx.r8.s64 + -17268;
	// b 0x823e06d4
	goto loc_823E06D4;
loc_823E06CC:
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r8,r8,-17320
	ctx.r8.s64 = ctx.r8.s64 + -17320;
loc_823E06D4:
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,-4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_823E06E4:
	// lwz r7,228(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// mulli r10,r10,60
	ctx.r10.s64 = ctx.r10.s64 * 60;
	// lwz r8,236(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// lwz r9,244(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// mulli r10,r10,60
	ctx.r10.s64 = ctx.r10.s64 * 60;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// mulli r10,r10,1000
	ctx.r10.s64 = ctx.r10.s64 * 1000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bne cr6,0x823e0728
	if (!cr6.eq) goto loc_823E0728;
	// addi r8,r7,-19780
	ctx.r8.s64 = ctx.r7.s64 + -19780;
	// stw r30,-19780(r7)
	PPC_STORE_U32(ctx.r7.u32 + -19780, r30.u32);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// b 0x823e07b4
	goto loc_823E07B4;
loc_823E0728:
	// addi r31,r7,-19780
	r31.s64 = ctx.r7.s64 + -19780;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// bl 0x823e0e88
	ctx.lr = 0x823E073C;
	sub_823E0E88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e075c
	if (cr0.eq) goto loc_823E075C;
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
	// bl 0x823e02f0
	ctx.lr = 0x823E075C;
	sub_823E02F0(ctx, base);
loc_823E075C:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mulli r10,r10,1000
	ctx.r10.s64 = ctx.r10.s64 * 1000;
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bge 0x823e0788
	if (!cr0.lt) goto loc_823E0788;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addis r11,r11,1318
	r11.s64 = r11.s64 + 86376448;
	// addi r11,r11,23552
	r11.s64 = r11.s64 + 23552;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x823e07a8
	goto loc_823E07A8;
loc_823E0788:
	// lis r10,1318
	ctx.r10.s64 = 86376448;
	// ori r10,r10,23552
	ctx.r10.u64 = ctx.r10.u64 | 23552;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x823e07b0
	if (cr6.lt) goto loc_823E07B0;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
loc_823E07A8:
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_823E07B0:
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_823E07B4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823E07BC"))) PPC_WEAK_FUNC(sub_823E07BC);
PPC_FUNC_IMPL(__imp__sub_823E07BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E07C0"))) PPC_WEAK_FUNC(sub_823E07C0);
PPC_FUNC_IMPL(__imp__sub_823E07C0) {
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
	ctx.lr = 0x823E07C8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823e0e20
	ctx.lr = 0x823E07E0;
	sub_823E0E20(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e0800
	if (cr0.eq) goto loc_823E0800;
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
	// bl 0x823e02f0
	ctx.lr = 0x823E0800;
	sub_823E02F0(ctx, base);
loc_823E0800:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e0814
	if (!cr6.eq) goto loc_823E0814;
loc_823E080C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823e0a64
	goto loc_823E0A64;
loc_823E0814:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r28,r11,-19780
	r28.s64 = r11.s64 + -19780;
	// lwz r11,-19780(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -19780);
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// bne cr6,0x823e0838
	if (!cr6.eq) goto loc_823E0838;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// beq cr6,0x823e09c0
	if (cr6.eq) goto loc_823E09C0;
loc_823E0838:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,-10640
	r31.s64 = r11.s64 + -10640;
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823e0964
	if (cr6.eq) goto loc_823E0964;
	// lhz r11,152(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 152);
	// lhz r3,164(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 164);
	// lhz r29,162(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 162);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x823e089c
	if (!cr0.eq) goto loc_823E089C;
	// lhz r4,166(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 166);
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r6,158(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 158);
	// lhz r11,154(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 154);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// lhz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 160);
	// stw r4,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// lhz r8,156(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 156);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bl 0x823e0548
	ctx.lr = 0x823E0898;
	sub_823E0548(ctx, base);
	// b 0x823e08d0
	goto loc_823E08D0;
loc_823E089C:
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r9,166(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 166);
	// li r7,0
	ctx.r7.s64 = 0;
	// lhz r11,158(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 158);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lhz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 160);
	// lhz r6,154(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 154);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// bl 0x823e0548
	ctx.lr = 0x823E08D0;
	sub_823E0548(ctx, base);
loc_823E08D0:
	// lhz r11,68(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 68);
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// bne 0x823e0924
	if (!cr0.eq) goto loc_823E0924;
	// lhz r3,78(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 78);
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r6,74(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 74);
	// li r4,1
	ctx.r4.s64 = 1;
	// lhz r29,82(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// lhz r27,80(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lhz r11,70(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 70);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// lhz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// bl 0x823e0548
	ctx.lr = 0x823E0920;
	sub_823E0548(ctx, base);
	// b 0x823e09c0
	goto loc_823E09C0;
loc_823E0924:
	// lhz r9,82(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r29,80(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// li r7,0
	ctx.r7.s64 = 0;
	// lhz r27,78(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 78);
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r11,74(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 74);
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// lhz r6,70(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 70);
	// bl 0x823e0548
	ctx.lr = 0x823E0960;
	sub_823E0548(ctx, base);
	// b 0x823e09c0
	goto loc_823E09C0;
loc_823E0964:
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e0548
	ctx.lr = 0x823E0990;
	sub_823E0548(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// li r6,10
	ctx.r6.s64 = 10;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e0548
	ctx.lr = 0x823E09C0;
	sub_823E0548(ctx, base);
loc_823E09C0:
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x823e09f8
	if (!cr6.lt) goto loc_823E09F8;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x823e080c
	if (cr6.lt) goto loc_823E080C;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bgt cr6,0x823e080c
	if (cr6.gt) goto loc_823E080C;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x823e0a18
	if (!cr6.gt) goto loc_823E0A18;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x823e0a18
	if (!cr6.lt) goto loc_823E0A18;
	// b 0x823e0a60
	goto loc_823E0A60;
loc_823E09F8:
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823e0a60
	if (cr6.lt) goto loc_823E0A60;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x823e0a60
	if (cr6.gt) goto loc_823E0A60;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x823e0a18
	if (!cr6.gt) goto loc_823E0A18;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x823e080c
	if (cr6.lt) goto loc_823E080C;
loc_823E0A18:
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mulli r11,r8,60
	r11.s64 = ctx.r8.s64 * 60;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mulli r11,r11,60
	r11.s64 = r11.s64 * 60;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mulli r11,r11,1000
	r11.s64 = r11.s64 * 1000;
	// bne cr6,0x823e0a50
	if (!cr6.eq) goto loc_823E0A50;
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x823e0a60
	if (!cr6.lt) goto loc_823E0A60;
	// b 0x823e080c
	goto loc_823E080C;
loc_823E0A50:
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x823e0a64
	if (!cr6.lt) goto loc_823E0A64;
loc_823E0A60:
	// li r3,1
	ctx.r3.s64 = 1;
loc_823E0A64:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823E0A6C"))) PPC_WEAK_FUNC(sub_823E0A6C);
PPC_FUNC_IMPL(__imp__sub_823E0A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0A70"))) PPC_WEAK_FUNC(sub_823E0A70);
PPC_FUNC_IMPL(__imp__sub_823E0A70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9656(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9656);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r11,-10460(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10460);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e0ad4
	if (!cr6.eq) goto loc_823E0AD4;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823e2a08
	ctx.lr = 0x823E0AA8;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,-10460(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10460);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e0ac8
	if (!cr6.eq) goto loc_823E0AC8;
	// bl 0x823e0380
	ctx.lr = 0x823E0ABC;
	sub_823E0380(ctx, base);
	// lwz r11,-10460(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10460);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-10460(r30)
	PPC_STORE_U32(r30.u32 + -10460, r11.u32);
loc_823E0AC8:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	r12.s64 = r31.s64 + 112;
	// bl 0x823e0aec
	ctx.lr = 0x823E0AD4;
	sub_823E0AEC(ctx, base);
loc_823E0AD4:
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_823E0A78"))) PPC_WEAK_FUNC(sub_823E0A78);
PPC_FUNC_IMPL(__imp__sub_823E0A78) {
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
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r11,-10460(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10460);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e0ad4
	if (!cr6.eq) goto loc_823E0AD4;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823e2a08
	ctx.lr = 0x823E0AA8;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwz r11,-10460(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10460);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e0ac8
	if (!cr6.eq) goto loc_823E0AC8;
	// bl 0x823e0380
	ctx.lr = 0x823E0ABC;
	sub_823E0380(ctx, base);
	// lwz r11,-10460(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10460);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-10460(r30)
	PPC_STORE_U32(r30.u32 + -10460, r11.u32);
loc_823E0AC8:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	r12.s64 = r31.s64 + 112;
	// bl 0x823e0aec
	ctx.lr = 0x823E0AD4;
	sub_823E0AEC(ctx, base);
loc_823E0AD4:
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_823E0AEC"))) PPC_WEAK_FUNC(sub_823E0AEC);
PPC_FUNC_IMPL(__imp__sub_823E0AEC) {
	PPC_FUNC_PROLOGUE();
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
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823e28a8
	ctx.lr = 0x823E0B00;
	sub_823E28A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0B10"))) PPC_WEAK_FUNC(sub_823E0B10);
PPC_FUNC_IMPL(__imp__sub_823E0B10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9680(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9680);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823e2a08
	ctx.lr = 0x823E0B3C;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e07c0
	ctx.lr = 0x823E0B48;
	sub_823E07C0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	r12.s64 = r31.s64 + 112;
	// bl 0x823e0b74
	ctx.lr = 0x823E0B58;
	sub_823E0B74(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_823E0B18"))) PPC_WEAK_FUNC(sub_823E0B18);
PPC_FUNC_IMPL(__imp__sub_823E0B18) {
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
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823e2a08
	ctx.lr = 0x823E0B3C;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e07c0
	ctx.lr = 0x823E0B48;
	sub_823E07C0(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,112
	r12.s64 = r31.s64 + 112;
	// bl 0x823e0b74
	ctx.lr = 0x823E0B58;
	sub_823E0B74(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_823E0B74"))) PPC_WEAK_FUNC(sub_823E0B74);
PPC_FUNC_IMPL(__imp__sub_823E0B74) {
	PPC_FUNC_PROLOGUE();
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
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823e28a8
	ctx.lr = 0x823E0B88;
	sub_823E28A8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0B98"))) PPC_WEAK_FUNC(sub_823E0B98);
PPC_FUNC_IMPL(__imp__sub_823E0B98) {
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
	ctx.lr = 0x823E0BA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823e0be4
	if (!cr6.eq) goto loc_823E0BE4;
loc_823E0BB8:
	// bl 0x823e1000
	ctx.lr = 0x823E0BBC;
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
	ctx.lr = 0x823E0BDC;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823e0e14
	goto loc_823E0E14;
loc_823E0BE4:
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x823E0BF4;
	sub_823D9890(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823e0bb8
	if (cr6.eq) goto loc_823E0BB8;
	// ld r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// cmpdi cr6,r8,0
	cr6.compare<int64_t>(ctx.r8.s64, 0, xer);
	// bge cr6,0x823e0c20
	if (!cr6.lt) goto loc_823E0C20;
	// bl 0x823e1000
	ctx.lr = 0x823E0C0C;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,22
	ctx.r10.s64 = 22;
	// li r3,22
	ctx.r3.s64 = 22;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e0e14
	goto loc_823E0E14;
loc_823E0C20:
	// lis r11,-27840
	r11.s64 = -1824522240;
	// li r10,7
	ctx.r10.s64 = 7;
	// ori r11,r11,28671
	r11.u64 = r11.u64 | 28671;
	// rldimi r11,r10,32,0
	r11.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (r11.u64 & 0xFFFFFFFF);
	// cmpd cr6,r8,r11
	cr6.compare<int64_t>(ctx.r8.s64, r11.s64, xer);
	// bgt cr6,0x823e0bb8
	if (cr6.gt) goto loc_823E0BB8;
	// lis r11,481
	r11.s64 = 31522816;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r7,r11,13184
	ctx.r7.u64 = r11.u64 | 13184;
	// ori r9,r10,20864
	ctx.r9.u64 = ctx.r10.u64 | 20864;
	// divd r11,r8,r7
	r11.s64 = ctx.r8.s64 / ctx.r7.s64;
	// li r3,400
	ctx.r3.s64 = 400;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// li r4,100
	ctx.r4.s64 = 100;
	// addi r11,r11,70
	r11.s64 = r11.s64 + 70;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// addi r6,r11,299
	ctx.r6.s64 = r11.s64 + 299;
	// divw r5,r10,r4
	ctx.r5.s32 = ctx.r10.s32 / ctx.r4.s32;
	// divw r6,r6,r3
	ctx.r6.s32 = ctx.r6.s32 / ctx.r3.s32;
	// srawi r28,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	r28.s64 = ctx.r10.s32 >> 2;
	// subf r5,r5,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r5.s64;
	// addze r6,r28
	temp.s64 = r28.s64 + xer.ca;
	xer.ca = temp.u32 < r28.u32;
	ctx.r6.s64 = temp.s64;
	// addi r28,r11,-70
	r28.s64 = r11.s64 + -70;
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// extsw r5,r28
	ctx.r5.s64 = r28.s32;
	// addi r28,r6,-17
	r28.s64 = ctx.r6.s64 + -17;
	// mulli r6,r5,365
	ctx.r6.s64 = ctx.r5.s64 * 365;
	// extsw r5,r28
	ctx.r5.s64 = r28.s32;
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// mulld r6,r6,r9
	ctx.r6.s64 = ctx.r6.s64 * ctx.r9.s64;
	// subf r8,r6,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r6.s64;
	// cmpdi cr6,r8,0
	cr6.compare<int64_t>(ctx.r8.s64, 0, xer);
	// bge cr6,0x823e0cec
	if (!cr6.lt) goto loc_823E0CEC;
	// srawi r11,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	r11.s64 = ctx.r10.s32 >> 2;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// addze r7,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r7.s64 = temp.s64;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf. r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e0cd0
	if (!cr0.eq) goto loc_823E0CD0;
	// divw r10,r11,r4
	ctx.r10.s32 = r11.s32 / ctx.r4.s32;
	// mulli r10,r10,100
	ctx.r10.s64 = ctx.r10.s64 * 100;
	// subf. r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e0ce4
	if (!cr0.eq) goto loc_823E0CE4;
loc_823E0CD0:
	// addi r10,r11,1900
	ctx.r10.s64 = r11.s64 + 1900;
	// divw r7,r10,r3
	ctx.r7.s32 = ctx.r10.s32 / ctx.r3.s32;
	// mulli r7,r7,400
	ctx.r7.s64 = ctx.r7.s64 * 400;
	// subf. r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e0d28
	if (!cr0.eq) goto loc_823E0D28;
loc_823E0CE4:
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// b 0x823e0d24
	goto loc_823E0D24;
loc_823E0CEC:
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf. r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e0d10
	if (!cr0.eq) goto loc_823E0D10;
	// divw r10,r11,r4
	ctx.r10.s32 = r11.s32 / ctx.r4.s32;
	// mulli r10,r10,100
	ctx.r10.s64 = ctx.r10.s64 * 100;
	// subf. r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e0d24
	if (!cr0.eq) goto loc_823E0D24;
loc_823E0D10:
	// addi r10,r11,1900
	ctx.r10.s64 = r11.s64 + 1900;
	// divw r7,r10,r3
	ctx.r7.s32 = ctx.r10.s32 / ctx.r3.s32;
	// mulli r7,r7,400
	ctx.r7.s64 = ctx.r7.s64 * 400;
	// subf. r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e0d28
	if (!cr0.eq) goto loc_823E0D28;
loc_823E0D24:
	// li r30,1
	r30.s64 = 1;
loc_823E0D28:
	// divd r10,r8,r9
	ctx.r10.s64 = ctx.r8.s64 / ctx.r9.s64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// extsw r11,r10
	r11.s64 = ctx.r10.s32;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// mulld r11,r10,r9
	r11.s64 = ctx.r10.s64 * ctx.r9.s64;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
	// beq cr6,0x823e0d58
	if (cr6.eq) goto loc_823E0D58;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r7,r11,-17320
	ctx.r7.s64 = r11.s64 + -17320;
	// b 0x823e0d60
	goto loc_823E0D60;
loc_823E0D58:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r7,r11,-17268
	ctx.r7.s64 = r11.s64 + -17268;
loc_823E0D60:
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r5,r8
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r8.s32, xer);
	// bge cr6,0x823e0d90
	if (!cr6.lt) goto loc_823E0D90;
	// rotlwi r5,r8,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
loc_823E0D7C:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// blt cr6,0x823e0d7c
	if (cr6.lt) goto loc_823E0D7C;
loc_823E0D90:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// li r10,3600
	ctx.r10.s64 = 3600;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// divd r10,r6,r10
	ctx.r10.s64 = ctx.r6.s64 / ctx.r10.s64;
	// li r5,60
	ctx.r5.s64 = 60;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// li r30,0
	r30.s64 = 0;
	// mulli r3,r3,3600
	ctx.r3.s64 = ctx.r3.s64 * 3600;
	// subf r6,r3,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r3.s64;
	// li r3,0
	ctx.r3.s64 = 0;
	// divd r5,r6,r5
	ctx.r5.s64 = ctx.r6.s64 / ctx.r5.s64;
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// extsw r5,r5
	ctx.r5.s64 = ctx.r5.s32;
	// lwzx r11,r11,r7
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// mulli r7,r5,60
	ctx.r7.s64 = ctx.r5.s64 * 60;
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// subf r8,r7,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r7.s64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// divd r11,r11,r9
	r11.s64 = r11.s64 / ctx.r9.s64;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// divw r10,r11,r4
	ctx.r10.s32 = r11.s32 / ctx.r4.s32;
	// mulli r10,r10,7
	ctx.r10.s64 = ctx.r10.s64 * 7;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
loc_823E0E14:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823E0E1C"))) PPC_WEAK_FUNC(sub_823E0E1C);
PPC_FUNC_IMPL(__imp__sub_823E0E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0E20"))) PPC_WEAK_FUNC(sub_823E0E20);
PPC_FUNC_IMPL(__imp__sub_823E0E20) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823e0e64
	if (!cr6.eq) goto loc_823E0E64;
	// bl 0x823e1000
	ctx.lr = 0x823E0E3C;
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
	ctx.lr = 0x823E0E5C;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823e0e74
	goto loc_823E0E74;
loc_823E0E64:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-19748(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -19748);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_823E0E74:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0E84"))) PPC_WEAK_FUNC(sub_823E0E84);
PPC_FUNC_IMPL(__imp__sub_823E0E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0E88"))) PPC_WEAK_FUNC(sub_823E0E88);
PPC_FUNC_IMPL(__imp__sub_823E0E88) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823e0ecc
	if (!cr6.eq) goto loc_823E0ECC;
	// bl 0x823e1000
	ctx.lr = 0x823E0EA4;
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
	ctx.lr = 0x823E0EC4;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823e0edc
	goto loc_823E0EDC;
loc_823E0ECC:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-19744(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -19744);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_823E0EDC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0EEC"))) PPC_WEAK_FUNC(sub_823E0EEC);
PPC_FUNC_IMPL(__imp__sub_823E0EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0EF0"))) PPC_WEAK_FUNC(sub_823E0EF0);
PPC_FUNC_IMPL(__imp__sub_823E0EF0) {
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
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823e0f34
	if (!cr6.eq) goto loc_823E0F34;
	// bl 0x823e1000
	ctx.lr = 0x823E0F0C;
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
	ctx.lr = 0x823E0F2C;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823e0f44
	goto loc_823E0F44;
loc_823E0F34:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-19752(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -19752);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_823E0F44:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0F54"))) PPC_WEAK_FUNC(sub_823E0F54);
PPC_FUNC_IMPL(__imp__sub_823E0F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0F58"))) PPC_WEAK_FUNC(sub_823E0F58);
PPC_FUNC_IMPL(__imp__sub_823E0F58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r11,-19748
	ctx.r3.s64 = r11.s64 + -19748;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0F64"))) PPC_WEAK_FUNC(sub_823E0F64);
PPC_FUNC_IMPL(__imp__sub_823E0F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0F68"))) PPC_WEAK_FUNC(sub_823E0F68);
PPC_FUNC_IMPL(__imp__sub_823E0F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r11,-19744
	ctx.r3.s64 = r11.s64 + -19744;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0F74"))) PPC_WEAK_FUNC(sub_823E0F74);
PPC_FUNC_IMPL(__imp__sub_823E0F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0F78"))) PPC_WEAK_FUNC(sub_823E0F78);
PPC_FUNC_IMPL(__imp__sub_823E0F78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r11,-19752
	ctx.r3.s64 = r11.s64 + -19752;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0F84"))) PPC_WEAK_FUNC(sub_823E0F84);
PPC_FUNC_IMPL(__imp__sub_823E0F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0F88"))) PPC_WEAK_FUNC(sub_823E0F88);
PPC_FUNC_IMPL(__imp__sub_823E0F88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r11,-19608
	ctx.r3.s64 = r11.s64 + -19608;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E0F94"))) PPC_WEAK_FUNC(sub_823E0F94);
PPC_FUNC_IMPL(__imp__sub_823E0F94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E0F98"))) PPC_WEAK_FUNC(sub_823E0F98);
PPC_FUNC_IMPL(__imp__sub_823E0F98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-19600
	ctx.r9.s64 = ctx.r10.s64 + -19600;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_823E0FA8:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r3,r8
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r8.u32, xer);
	// beq cr6,0x823e0fd8
	if (cr6.eq) goto loc_823E0FD8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r11,45
	cr6.compare<uint32_t>(r11.u32, 45, xer);
	// blt cr6,0x823e0fa8
	if (cr6.lt) goto loc_823E0FA8;
	// addi r11,r3,-19
	r11.s64 = ctx.r3.s64 + -19;
	// cmplwi cr6,r11,17
	cr6.compare<uint32_t>(r11.u32, 17, xer);
	// bgt cr6,0x823e0fe8
	if (cr6.gt) goto loc_823E0FE8;
	// li r3,13
	ctx.r3.s64 = 13;
	// blr 
	return;
loc_823E0FD8:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
loc_823E0FE8:
	// addi r11,r3,-188
	r11.s64 = ctx.r3.s64 + -188;
	// subfic r11,r11,14
	xer.ca = r11.u32 <= 14;
	r11.s64 = 14 - r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r11,0,28,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xE;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E1000"))) PPC_WEAK_FUNC(sub_823E1000);
PPC_FUNC_IMPL(__imp__sub_823E1000) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823db208
	ctx.lr = 0x823E1010;
	sub_823DB208(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e1024
	if (!cr0.eq) goto loc_823E1024;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r11,-19240
	ctx.r3.s64 = r11.s64 + -19240;
	// b 0x823e1028
	goto loc_823E1028;
loc_823E1024:
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
loc_823E1028:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E1038"))) PPC_WEAK_FUNC(sub_823E1038);
PPC_FUNC_IMPL(__imp__sub_823E1038) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823db208
	ctx.lr = 0x823E1048;
	sub_823DB208(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e105c
	if (!cr0.eq) goto loc_823E105C;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r11,-19236
	ctx.r3.s64 = r11.s64 + -19236;
	// b 0x823e1060
	goto loc_823E1060;
loc_823E105C:
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
loc_823E1060:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E1070"))) PPC_WEAK_FUNC(sub_823E1070);
PPC_FUNC_IMPL(__imp__sub_823E1070) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823db208
	ctx.lr = 0x823E108C;
	sub_823DB208(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r31,r11,-19240
	r31.s64 = r11.s64 + -19240;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// beq 0x823e10a4
	if (cr0.eq) goto loc_823E10A4;
	// addi r11,r3,12
	r11.s64 = ctx.r3.s64 + 12;
loc_823E10A4:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// bl 0x823db208
	ctx.lr = 0x823E10AC;
	sub_823DB208(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// beq 0x823e10bc
	if (cr0.eq) goto loc_823E10BC;
	// addi r7,r3,8
	ctx.r7.s64 = ctx.r3.s64 + 8;
loc_823E10BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e0f98
	ctx.lr = 0x823E10C4;
	sub_823E0F98(ctx, base);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_823E10E0"))) PPC_WEAK_FUNC(sub_823E10E0);
PPC_FUNC_IMPL(__imp__sub_823E10E0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x823db208
	ctx.lr = 0x823E10F4;
	sub_823DB208(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x823e1114
	if (!cr0.eq) goto loc_823E1114;
	// bl 0x823e1000
	ctx.lr = 0x823E1100;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e114c
	goto loc_823E114C;
loc_823E1114:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e1148
	if (!cr6.eq) goto loc_823E1148;
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x823e2610
	ctx.lr = 0x823E1128;
	sub_823E2610(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e1148
	if (!cr0.eq) goto loc_823E1148;
	// bl 0x823e1000
	ctx.lr = 0x823E113C;
	sub_823E1000(ctx, base);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_823E1148:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_823E114C:
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

__attribute__((alias("__imp__sub_823E1160"))) PPC_WEAK_FUNC(sub_823E1160);
PPC_FUNC_IMPL(__imp__sub_823E1160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r3,r11,-19232
	ctx.r3.s64 = r11.s64 + -19232;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E116C"))) PPC_WEAK_FUNC(sub_823E116C);
PPC_FUNC_IMPL(__imp__sub_823E116C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E1170"))) PPC_WEAK_FUNC(sub_823E1170);
PPC_FUNC_IMPL(__imp__sub_823E1170) {
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
	// lis r31,-32107
	r31.s64 = -2104164352;
	// lwz r3,-22844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -22844);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823e119c
	if (!cr6.eq) goto loc_823E119C;
	// li r3,512
	ctx.r3.s64 = 512;
	// b 0x823e11a8
	goto loc_823E11A8;
loc_823E119C:
	// cmpwi cr6,r3,20
	cr6.compare<int32_t>(ctx.r3.s32, 20, xer);
	// bge cr6,0x823e11ac
	if (!cr6.lt) goto loc_823E11AC;
	// li r3,20
	ctx.r3.s64 = 20;
loc_823E11A8:
	// stw r3,-22844(r31)
	PPC_STORE_U32(r31.u32 + -22844, ctx.r3.u32);
loc_823E11AC:
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x823e24c8
	ctx.lr = 0x823E11B4;
	sub_823E24C8(ctx, base);
	// lis r30,-32107
	r30.s64 = -2104164352;
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,-22848(r30)
	PPC_STORE_U32(r30.u32 + -22848, ctx.r3.u32);
	// bne 0x823e11ec
	if (!cr0.eq) goto loc_823E11EC;
	// li r11,20
	r11.s64 = 20;
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r11,-22844(r31)
	PPC_STORE_U32(r31.u32 + -22844, r11.u32);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x823e24c8
	ctx.lr = 0x823E11D8;
	sub_823E24C8(ctx, base);
	// stw r3,-22848(r30)
	PPC_STORE_U32(r30.u32 + -22848, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e11ec
	if (!cr0.eq) goto loc_823E11EC;
	// li r3,26
	ctx.r3.s64 = 26;
	// b 0x823e1278
	goto loc_823E1278;
loc_823E11EC:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-19232
	ctx.r9.s64 = r11.s64 + -19232;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// b 0x823e1204
	goto loc_823E1204;
loc_823E1200:
	// lwz r3,-22848(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -22848);
loc_823E1204:
	// stwx r11,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, r11.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r8,r9,640
	ctx.r8.s64 = ctx.r9.s64 + 640;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x823e1200
	if (cr6.lt) goto loc_823E1200;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,16
	ctx.r8.s64 = ctx.r9.s64 + 16;
	// addi r7,r10,-23104
	ctx.r7.s64 = ctx.r10.s64 + -23104;
loc_823E122C:
	// srawi r10,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = r11.s32 >> 5;
	// rlwinm r6,r11,6,21,25
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0x7C0;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// lwzx r10,r10,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x823e1258
	if (cr6.eq) goto loc_823E1258;
	// cmpwi cr6,r10,-2
	cr6.compare<int32_t>(ctx.r10.s32, -2, xer);
	// beq cr6,0x823e1258
	if (cr6.eq) goto loc_823E1258;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823e1260
	if (!cr6.eq) goto loc_823E1260;
loc_823E1258:
	// li r10,-2
	ctx.r10.s64 = -2;
	// stw r10,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
loc_823E1260:
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// addi r10,r9,112
	ctx.r10.s64 = ctx.r9.s64 + 112;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// blt cr6,0x823e122c
	if (cr6.lt) goto loc_823E122C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823E1278:
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

__attribute__((alias("__imp__sub_823E1290"))) PPC_WEAK_FUNC(sub_823E1290);
PPC_FUNC_IMPL(__imp__sub_823E1290) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823e6460
	ctx.lr = 0x823E12A0;
	sub_823E6460(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r11,-10688(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -10688);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x823e12b4
	if (cr0.eq) goto loc_823E12B4;
	// bl 0x823e6088
	ctx.lr = 0x823E12B4;
	sub_823E6088(ctx, base);
loc_823E12B4:
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lwz r3,-22848(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -22848);
	// bl 0x823e2c38
	ctx.lr = 0x823E12C0;
	sub_823E2C38(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E12D0"))) PPC_WEAK_FUNC(sub_823E12D0);
PPC_FUNC_IMPL(__imp__sub_823E12D0) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r11,-19232
	r11.s64 = r11.s64 + -19232;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x823e1320
	if (cr6.lt) goto loc_823E1320;
	// addi r10,r11,608
	ctx.r10.s64 = r11.s64 + 608;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bgt cr6,0x823e1320
	if (cr6.gt) goto loc_823E1320;
	// subf r11,r11,r31
	r11.s64 = r31.s64 - r11.s64;
	// srawi r11,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	r11.s64 = r11.s32 >> 5;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x823e2a08
	ctx.lr = 0x823E1310;
	sub_823E2A08(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// ori r11,r11,32768
	r11.u64 = r11.u64 | 32768;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x823e1328
	goto loc_823E1328;
loc_823E1320:
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x827bcf64
	ctx.lr = 0x823E1328;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_823E1328:
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

__attribute__((alias("__imp__sub_823E133C"))) PPC_WEAK_FUNC(sub_823E133C);
PPC_FUNC_IMPL(__imp__sub_823E133C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E1340"))) PPC_WEAK_FUNC(sub_823E1340);
PPC_FUNC_IMPL(__imp__sub_823E1340) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,20
	cr6.compare<int32_t>(ctx.r3.s32, 20, xer);
	// bge cr6,0x823e1374
	if (!cr6.lt) goto loc_823E1374;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x823e2a08
	ctx.lr = 0x823E1364;
	sub_823E2A08(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// ori r11,r11,32768
	r11.u64 = r11.u64 | 32768;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x823e137c
	goto loc_823E137C;
loc_823E1374:
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x827bcf64
	ctx.lr = 0x823E137C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_823E137C:
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

__attribute__((alias("__imp__sub_823E1390"))) PPC_WEAK_FUNC(sub_823E1390);
PPC_FUNC_IMPL(__imp__sub_823E1390) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-19232
	r11.s64 = r11.s64 + -19232;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x823e13c8
	if (cr6.lt) goto loc_823E13C8;
	// addi r10,r11,608
	ctx.r10.s64 = r11.s64 + 608;
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// bgt cr6,0x823e13c8
	if (cr6.gt) goto loc_823E13C8;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// rlwinm r10,r10,0,17,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// srawi r11,r11,5
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1F) != 0);
	r11.s64 = r11.s32 >> 5;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// b 0x823e28a8
	sub_823E28A8(ctx, base);
	return;
loc_823E13C8:
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// b 0x827bcf54
	__imp__RtlLeaveCriticalSection(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823E13D0"))) PPC_WEAK_FUNC(sub_823E13D0);
PPC_FUNC_IMPL(__imp__sub_823E13D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r3,20
	cr6.compare<int32_t>(ctx.r3.s32, 20, xer);
	// bge cr6,0x823e13ec
	if (!cr6.lt) goto loc_823E13EC;
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// rlwinm r11,r11,0,17,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// b 0x823e28a8
	sub_823E28A8(ctx, base);
	return;
loc_823E13EC:
	// addi r3,r4,32
	ctx.r3.s64 = ctx.r4.s64 + 32;
	// b 0x827bcf54
	__imp__RtlLeaveCriticalSection(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823E13F4"))) PPC_WEAK_FUNC(sub_823E13F4);
PPC_FUNC_IMPL(__imp__sub_823E13F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E13F8"))) PPC_WEAK_FUNC(sub_823E13F8);
PPC_FUNC_IMPL(__imp__sub_823E13F8) {
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
	ctx.lr = 0x823E1400;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E140C;
	sub_823E3DE0(ctx, base);
	// bl 0x821a5cc0
	ctx.lr = 0x823E1410;
	sub_821A5CC0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e14c4
	if (cr0.eq) goto loc_823E14C4;
	// bl 0x823e1160
	ctx.lr = 0x823E141C;
	sub_823E1160(ctx, base);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x823e1430
	if (!cr6.eq) goto loc_823E1430;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x823e1444
	goto loc_823E1444;
loc_823E1430:
	// bl 0x823e1160
	ctx.lr = 0x823E1434;
	sub_823E1160(ctx, base);
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x823e14c4
	if (!cr6.eq) goto loc_823E14C4;
	// li r10,1
	ctx.r10.s64 = 1;
loc_823E1444:
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lwz r11,-10456(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10456);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-10456(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10456, r11.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// andi. r11,r11,268
	r11.u64 = r11.u64 & 268;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e14c4
	if (!cr0.eq) goto loc_823E14C4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// rlwinm r29,r10,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r11,-10452
	r30.s64 = r11.s64 + -10452;
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e149c
	if (!cr6.eq) goto loc_823E149C;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// bl 0x823e2610
	ctx.lr = 0x823E1484;
	sub_823E2610(ctx, base);
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// bne 0x823e149c
	if (!cr0.eq) goto loc_823E149C;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// b 0x823e14a0
	goto loc_823E14A0;
loc_823E149C:
	// li r10,4096
	ctx.r10.s64 = 4096;
loc_823E14A0:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// ori r11,r11,4354
	r11.u64 = r11.u64 | 4354;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x823e14c8
	goto loc_823E14C8;
loc_823E14C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823E14C8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E14D0"))) PPC_WEAK_FUNC(sub_823E14D0);
PPC_FUNC_IMPL(__imp__sub_823E14D0) {
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
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823e1520
	if (cr6.eq) goto loc_823E1520;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm. r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e1520
	if (cr0.eq) goto loc_823E1520;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e6170
	ctx.lr = 0x823E1500;
	sub_823E6170(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r11,r11,0,24,22
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
	// rlwinm r11,r11,0,20,18
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFEFFF;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_823E1520:
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

__attribute__((alias("__imp__sub_823E1534"))) PPC_WEAK_FUNC(sub_823E1534);
PPC_FUNC_IMPL(__imp__sub_823E1534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E1538"))) PPC_WEAK_FUNC(sub_823E1538);
PPC_FUNC_IMPL(__imp__sub_823E1538) {
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
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e1568
	if (cr0.eq) goto loc_823E1568;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823e15ac
	if (cr6.eq) goto loc_823E15AC;
loc_823E1568:
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// blt 0x823e1594
	if (cr0.lt) goto loc_823E1594;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// b 0x823e159c
	goto loc_823E159C;
loc_823E1594:
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823e3a68
	ctx.lr = 0x823E159C;
	sub_823E3A68(ctx, base);
loc_823E159C:
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x823e15ac
	if (!cr6.eq) goto loc_823E15AC;
	// li r11,-1
	r11.s64 = -1;
	// b 0x823e15b4
	goto loc_823E15B4;
loc_823E15AC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_823E15B4:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_823E15CC"))) PPC_WEAK_FUNC(sub_823E15CC);
PPC_FUNC_IMPL(__imp__sub_823E15CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E15D0"))) PPC_WEAK_FUNC(sub_823E15D0);
PPC_FUNC_IMPL(__imp__sub_823E15D0) {
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
	ctx.lr = 0x823E15D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e1658
	if (cr0.eq) goto loc_823E1658;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e1658
	if (!cr6.eq) goto loc_823E1658;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x823e1660
	goto loc_823E1660;
loc_823E1614:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lbz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// bl 0x823e1538
	ctx.lr = 0x823E1628;
	sub_823E1538(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x823e1658
	if (!cr6.eq) goto loc_823E1658;
	// bl 0x823e1000
	ctx.lr = 0x823E163C;
	sub_823E1000(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,42
	cr6.compare<int32_t>(r11.s32, 42, xer);
	// bne cr6,0x823e1660
	if (!cr6.eq) goto loc_823E1660;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r3,63
	ctx.r3.s64 = 63;
	// bl 0x823e1538
	ctx.lr = 0x823E1658;
	sub_823E1538(ctx, base);
loc_823E1658:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bgt cr6,0x823e1614
	if (cr6.gt) goto loc_823E1614;
loc_823E1660:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823E1668"))) PPC_WEAK_FUNC(sub_823E1668);
PPC_FUNC_IMPL(__imp__sub_823E1668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x823E1670;
	// stwu r1,-1328(r1)
	ea = -1328 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	r27.s64 = 0;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// mr r25,r27
	r25.u64 = r27.u64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// mr r16,r27
	r16.u64 = r27.u64;
	// bne cr6,0x823e16d0
	if (!cr6.eq) goto loc_823E16D0;
loc_823E16A4:
	// bl 0x823e1000
	ctx.lr = 0x823E16A8;
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
	ctx.lr = 0x823E16C8;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e21d4
	goto loc_823E21D4;
loc_823E16D0:
	// lwz r11,12(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// rlwinm. r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e179c
	if (!cr0.eq) goto loc_823E179C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E16E4;
	sub_823E3DE0(ctx, base);
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// addi r30,r11,-23104
	r30.s64 = r11.s64 + -23104;
	// addi r29,r10,-17448
	r29.s64 = ctx.r10.s64 + -17448;
	// beq cr6,0x823e1734
	if (cr6.eq) goto loc_823E1734;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E1704;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823e1734
	if (cr6.eq) goto loc_823E1734;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E1714;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823e3de0
	ctx.lr = 0x823E1724;
	sub_823E3DE0(ctx, base);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x823e1738
	goto loc_823E1738;
loc_823E1734:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823E1738:
	// lbz r11,40(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// rlwinm. r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e16a4
	if (!cr0.eq) goto loc_823E16A4;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E174C;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823e178c
	if (cr6.eq) goto loc_823E178C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E175C;
	sub_823E3DE0(ctx, base);
	// cmpwi cr6,r3,-2
	cr6.compare<int32_t>(ctx.r3.s32, -2, xer);
	// beq cr6,0x823e178c
	if (cr6.eq) goto loc_823E178C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E176C;
	sub_823E3DE0(ctx, base);
	// srawi r11,r3,5
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	r11.s64 = ctx.r3.s32 >> 5;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823e3de0
	ctx.lr = 0x823E177C;
	sub_823E3DE0(ctx, base);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// rlwinm r10,r3,6,21,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0x7C0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x823e1790
	goto loc_823E1790;
loc_823E178C:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823E1790:
	// lbz r11,40(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e16a4
	if (!cr0.eq) goto loc_823E16A4;
loc_823E179C:
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x823e16a4
	if (cr6.eq) goto loc_823E16A4;
	// bl 0x823e1160
	ctx.lr = 0x823E17A8;
	sub_823E1160(ctx, base);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// beq cr6,0x823e21a0
	if (cr6.eq) goto loc_823E21A0;
	// bl 0x823e1160
	ctx.lr = 0x823E17B8;
	sub_823E1160(ctx, base);
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// beq cr6,0x823e21a0
	if (cr6.eq) goto loc_823E21A0;
	// lbz r29,0(r18)
	r29.u64 = PPC_LOAD_U8(r18.u32 + 0);
	// mr r24,r27
	r24.u64 = r27.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// extsb. r8,r29
	ctx.r8.s64 = r29.s8;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// mr r15,r27
	r15.u64 = r27.u64;
	// beq 0x823e2198
	if (cr0.eq) goto loc_823E2198;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r20,112(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lwz r28,112(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r14,-32250
	r14.s64 = -2113536000;
	// lis r19,-32250
	r19.s64 = -2113536000;
	// addi r22,r11,-18352
	r22.s64 = r11.s64 + -18352;
	// addi r21,r10,-19820
	r21.s64 = ctx.r10.s64 + -19820;
	// addi r17,r9,-11264
	r17.s64 = ctx.r9.s64 + -11264;
loc_823E1810:
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// blt cr6,0x823e2198
	if (cr6.lt) goto loc_823E2198;
	// cmpwi cr6,r8,32
	cr6.compare<int32_t>(ctx.r8.s32, 32, xer);
	// blt cr6,0x823e183c
	if (cr6.lt) goto loc_823E183C;
	// cmpwi cr6,r8,120
	cr6.compare<int32_t>(ctx.r8.s32, 120, xer);
	// bgt cr6,0x823e183c
	if (cr6.gt) goto loc_823E183C;
	// add r11,r8,r17
	r11.u64 = ctx.r8.u64 + r17.u64;
	// lbz r11,-32(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -32);
	// clrlwi r11,r11,28
	r11.u64 = r11.u32 & 0xF;
	// b 0x823e1840
	goto loc_823E1840;
loc_823E183C:
	// li r11,0
	r11.s64 = 0;
loc_823E1840:
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbzx r11,r11,r17
	r11.u64 = PPC_LOAD_U8(r11.u32 + r17.u32);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// srawi r11,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	r11.s64 = r11.s32 >> 4;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x823e2184
	if (cr6.gt) goto loc_823E2184;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r12,-32250
	r12.s64 = -2113536000;
	// addi r12,r12,-11056
	r12.s64 = r12.s64 + -11056;
	// rlwinm r0,r11,1,0,30
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r0,r12,r0
	r0.u64 = PPC_LOAD_U16(r12.u32 + r0.u32);
	// lis r12,-32194
	r12.s64 = -2109865984;
	// addi r12,r12,6288
	r12.s64 = r12.s64 + 6288;
	// add r12,r12,r0
	r12.u64 = r12.u64 + r0.u64;
	// mtctr r12
	ctr.u64 = r12.u64;
	// nop 
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_823E1A5C;
	case 1:
		goto loc_823E1890;
	case 2:
		goto loc_823E18B0;
	case 3:
		goto loc_823E1900;
	case 4:
		goto loc_823E194C;
	case 5:
		goto loc_823E1954;
	case 6:
		goto loc_823E198C;
	case 7:
		goto loc_823E1AAC;
	default:
		__builtin_unreachable();
	}
loc_823E1890:
	// li r27,0
	r27.s64 = 0;
	// li r25,-1
	r25.s64 = -1;
	// mr r20,r27
	r20.u64 = r27.u64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// mr r16,r27
	r16.u64 = r27.u64;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// b 0x823e2184
	goto loc_823E2184;
loc_823E18B0:
	// cmpwi cr6,r8,32
	cr6.compare<int32_t>(ctx.r8.s32, 32, xer);
	// beq cr6,0x823e18f8
	if (cr6.eq) goto loc_823E18F8;
	// cmpwi cr6,r8,35
	cr6.compare<int32_t>(ctx.r8.s32, 35, xer);
	// beq cr6,0x823e18f0
	if (cr6.eq) goto loc_823E18F0;
	// cmpwi cr6,r8,43
	cr6.compare<int32_t>(ctx.r8.s32, 43, xer);
	// beq cr6,0x823e18e8
	if (cr6.eq) goto loc_823E18E8;
	// cmpwi cr6,r8,45
	cr6.compare<int32_t>(ctx.r8.s32, 45, xer);
	// beq cr6,0x823e18e0
	if (cr6.eq) goto loc_823E18E0;
	// cmpwi cr6,r8,48
	cr6.compare<int32_t>(ctx.r8.s32, 48, xer);
	// bne cr6,0x823e2184
	if (!cr6.eq) goto loc_823E2184;
	// ori r27,r27,8
	r27.u64 = r27.u64 | 8;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E18E0:
	// ori r27,r27,4
	r27.u64 = r27.u64 | 4;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E18E8:
	// ori r27,r27,1
	r27.u64 = r27.u64 | 1;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E18F0:
	// ori r27,r27,128
	r27.u64 = r27.u64 | 128;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E18F8:
	// ori r27,r27,2
	r27.u64 = r27.u64 | 2;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E1900:
	// cmpwi cr6,r8,42
	cr6.compare<int32_t>(ctx.r8.s32, 42, xer);
	// bne cr6,0x823e1934
	if (!cr6.eq) goto loc_823E1934;
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// bge cr6,0x823e2184
	if (!cr6.lt) goto loc_823E2184;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// ori r27,r27,4
	r27.u64 = r27.u64 | 4;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// b 0x823e1944
	goto loc_823E1944;
loc_823E1934:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mulli r11,r11,10
	r11.s64 = r11.s64 * 10;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
loc_823E1944:
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// b 0x823e2184
	goto loc_823E2184;
loc_823E194C:
	// li r25,0
	r25.s64 = 0;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E1954:
	// cmpwi cr6,r8,42
	cr6.compare<int32_t>(ctx.r8.s32, 42, xer);
	// bne cr6,0x823e197c
	if (!cr6.eq) goto loc_823E197C;
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// lwz r25,4(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bge cr6,0x823e2184
	if (!cr6.lt) goto loc_823E2184;
	// li r25,-1
	r25.s64 = -1;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E197C:
	// mulli r11,r25,10
	r11.s64 = r25.s64 * 10;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r25,r11,-48
	r25.s64 = r11.s64 + -48;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E198C:
	// cmpwi cr6,r8,73
	cr6.compare<int32_t>(ctx.r8.s32, 73, xer);
	// beq cr6,0x823e19dc
	if (cr6.eq) goto loc_823E19DC;
	// cmpwi cr6,r8,104
	cr6.compare<int32_t>(ctx.r8.s32, 104, xer);
	// beq cr6,0x823e19d4
	if (cr6.eq) goto loc_823E19D4;
	// cmpwi cr6,r8,108
	cr6.compare<int32_t>(ctx.r8.s32, 108, xer);
	// beq cr6,0x823e19b4
	if (cr6.eq) goto loc_823E19B4;
	// cmpwi cr6,r8,119
	cr6.compare<int32_t>(ctx.r8.s32, 119, xer);
	// bne cr6,0x823e2184
	if (!cr6.eq) goto loc_823E2184;
	// ori r27,r27,2048
	r27.u64 = r27.u64 | 2048;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E19B4:
	// lbz r11,0(r18)
	r11.u64 = PPC_LOAD_U8(r18.u32 + 0);
	// cmplwi cr6,r11,108
	cr6.compare<uint32_t>(r11.u32, 108, xer);
	// bne cr6,0x823e19cc
	if (!cr6.eq) goto loc_823E19CC;
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// ori r27,r27,4096
	r27.u64 = r27.u64 | 4096;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E19CC:
	// ori r27,r27,16
	r27.u64 = r27.u64 | 16;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E19D4:
	// ori r27,r27,32
	r27.u64 = r27.u64 | 32;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E19DC:
	// lbz r11,0(r18)
	r11.u64 = PPC_LOAD_U8(r18.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,54
	cr6.compare<int32_t>(r11.s32, 54, xer);
	// bne cr6,0x823e1a04
	if (!cr6.eq) goto loc_823E1A04;
	// lbz r10,1(r18)
	ctx.r10.u64 = PPC_LOAD_U8(r18.u32 + 1);
	// cmplwi cr6,r10,52
	cr6.compare<uint32_t>(ctx.r10.u32, 52, xer);
	// bne cr6,0x823e1a04
	if (!cr6.eq) goto loc_823E1A04;
	// addi r18,r18,2
	r18.s64 = r18.s64 + 2;
	// ori r27,r27,32768
	r27.u64 = r27.u64 | 32768;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E1A04:
	// cmpwi cr6,r11,51
	cr6.compare<int32_t>(r11.s32, 51, xer);
	// bne cr6,0x823e1a24
	if (!cr6.eq) goto loc_823E1A24;
	// lbz r10,1(r18)
	ctx.r10.u64 = PPC_LOAD_U8(r18.u32 + 1);
	// cmplwi cr6,r10,50
	cr6.compare<uint32_t>(ctx.r10.u32, 50, xer);
	// bne cr6,0x823e1a24
	if (!cr6.eq) goto loc_823E1A24;
	// addi r18,r18,2
	r18.s64 = r18.s64 + 2;
	// rlwinm r27,r27,0,17,15
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0xFFFFFFFFFFFF7FFF;
	// b 0x823e2184
	goto loc_823E2184;
loc_823E1A24:
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x823e2184
	if (cr6.eq) goto loc_823E2184;
	// cmpwi cr6,r11,105
	cr6.compare<int32_t>(r11.s32, 105, xer);
	// beq cr6,0x823e2184
	if (cr6.eq) goto loc_823E2184;
	// cmpwi cr6,r11,111
	cr6.compare<int32_t>(r11.s32, 111, xer);
	// beq cr6,0x823e2184
	if (cr6.eq) goto loc_823E2184;
	// cmpwi cr6,r11,117
	cr6.compare<int32_t>(r11.s32, 117, xer);
	// beq cr6,0x823e2184
	if (cr6.eq) goto loc_823E2184;
	// cmpwi cr6,r11,120
	cr6.compare<int32_t>(r11.s32, 120, xer);
	// beq cr6,0x823e2184
	if (cr6.eq) goto loc_823E2184;
	// cmpwi cr6,r11,88
	cr6.compare<int32_t>(r11.s32, 88, xer);
	// beq cr6,0x823e2184
	if (cr6.eq) goto loc_823E2184;
	// li r11,0
	r11.s64 = 0;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
loc_823E1A5C:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// clrlwi r3,r29,24
	ctx.r3.u64 = r29.u32 & 0xFF;
	// li r16,0
	r16.s64 = 0;
	// bl 0x823e26d8
	ctx.lr = 0x823E1A6C;
	sub_823E26D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e1a94
	if (cr0.eq) goto loc_823E1A94;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823e1538
	ctx.lr = 0x823E1A84;
	sub_823E1538(ctx, base);
	// lbz r29,0(r18)
	r29.u64 = PPC_LOAD_U8(r18.u32 + 0);
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// cmplwi r29,0
	cr0.compare<uint32_t>(r29.u32, 0, xer);
	// beq 0x823e16a4
	if (cr0.eq) goto loc_823E16A4;
loc_823E1A94:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823e1538
	ctx.lr = 0x823E1AA4;
	sub_823E1538(ctx, base);
	// lwz r24,80(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x823e2184
	goto loc_823E2184;
loc_823E1AAC:
	// addi r11,r8,-65
	r11.s64 = ctx.r8.s64 + -65;
	// cmplwi cr6,r11,55
	cr6.compare<uint32_t>(r11.u32, 55, xer);
	// bgt cr6,0x823e1fb0
	if (cr6.gt) goto loc_823E1FB0;
	// lis r12,-32250
	r12.s64 = -2113536000;
	// addi r12,r12,-11168
	r12.s64 = r12.s64 + -11168;
	// rlwinm r0,r11,1,0,30
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r0,r12,r0
	r0.u64 = PPC_LOAD_U16(r12.u32 + r0.u32);
	// lis r12,-32194
	r12.s64 = -2109865984;
	// addi r12,r12,6880
	r12.s64 = r12.s64 + 6880;
	// add r12,r12,r0
	r12.u64 = r12.u64 + r0.u64;
	// mtctr r12
	ctr.u64 = r12.u64;
	// nop 
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_823E1CBC;
	case 1:
		goto loc_823E1FB0;
	case 2:
		goto loc_823E1AE0;
	case 3:
		goto loc_823E1FB0;
	case 4:
		goto loc_823E1CBC;
	case 5:
		goto loc_823E1FB0;
	case 6:
		goto loc_823E1CBC;
	case 7:
		goto loc_823E1FB0;
	case 8:
		goto loc_823E1FB0;
	case 9:
		goto loc_823E1FB0;
	case 10:
		goto loc_823E1FB0;
	case 11:
		goto loc_823E1FB0;
	case 12:
		goto loc_823E1FB0;
	case 13:
		goto loc_823E1FB0;
	case 14:
		goto loc_823E1FB0;
	case 15:
		goto loc_823E1FB0;
	case 16:
		goto loc_823E1FB0;
	case 17:
		goto loc_823E1FB0;
	case 18:
		goto loc_823E1BC8;
	case 19:
		goto loc_823E1FB0;
	case 20:
		goto loc_823E1FB0;
	case 21:
		goto loc_823E1FB0;
	case 22:
		goto loc_823E1FB0;
	case 23:
		goto loc_823E1DFC;
	case 24:
		goto loc_823E1FB0;
	case 25:
		goto loc_823E1B4C;
	case 26:
		goto loc_823E1FB0;
	case 27:
		goto loc_823E1FB0;
	case 28:
		goto loc_823E1FB0;
	case 29:
		goto loc_823E1FB0;
	case 30:
		goto loc_823E1FB0;
	case 31:
		goto loc_823E1FB0;
	case 32:
		goto loc_823E1CC8;
	case 33:
		goto loc_823E1FB0;
	case 34:
		goto loc_823E1AF0;
	case 35:
		goto loc_823E1DEC;
	case 36:
		goto loc_823E1CC8;
	case 37:
		goto loc_823E1CC8;
	case 38:
		goto loc_823E1CC8;
	case 39:
		goto loc_823E1FB0;
	case 40:
		goto loc_823E1DEC;
	case 41:
		goto loc_823E1FB0;
	case 42:
		goto loc_823E1FB0;
	case 43:
		goto loc_823E1FB0;
	case 44:
		goto loc_823E1FB0;
	case 45:
		goto loc_823E1C80;
	case 46:
		goto loc_823E1E34;
	case 47:
		goto loc_823E1DF8;
	case 48:
		goto loc_823E1FB0;
	case 49:
		goto loc_823E1FB0;
	case 50:
		goto loc_823E1BD8;
	case 51:
		goto loc_823E1FB0;
	case 52:
		goto loc_823E1DF0;
	case 53:
		goto loc_823E1FB0;
	case 54:
		goto loc_823E1FB0;
	case 55:
		goto loc_823E1E04;
	default:
		__builtin_unreachable();
	}
loc_823E1AE0:
	// andi. r11,r27,2096
	r11.u64 = r27.u64 & 2096;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e1af0
	if (!cr0.eq) goto loc_823E1AF0;
	// ori r27,r27,2048
	r27.u64 = r27.u64 | 2048;
loc_823E1AF0:
	// andi. r11,r27,2064
	r11.u64 = r27.u64 & 2064;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// beq 0x823e1b30
	if (cr0.eq) goto loc_823E1B30;
	// li r5,512
	ctx.r5.s64 = 512;
	// lhz r6,6(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823e6588
	ctx.lr = 0x823E1B1C;
	sub_823E6588(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e1b40
	if (cr0.eq) goto loc_823E1B40;
	// li r11,1
	r11.s64 = 1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// b 0x823e1b40
	goto loc_823E1B40;
loc_823E1B30:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stb r11,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r11.u8);
loc_823E1B40:
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
	// b 0x823e1fb0
	goto loc_823E1FB0;
loc_823E1B4C:
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e1b9c
	if (cr6.eq) goto loc_823E1B9C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823e1b9c
	if (cr6.eq) goto loc_823E1B9C;
	// rlwinm. r9,r27,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// beq 0x823e1b90
	if (cr0.eq) goto loc_823E1B90;
	// lha r11,0(r11)
	r11.s64 = int16_t(PPC_LOAD_U16(r11.u32 + 0));
	// li r16,1
	r16.s64 = 1;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// addze r7,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r7.s64 = temp.s64;
	// b 0x823e1fac
	goto loc_823E1FAC;
loc_823E1B90:
	// lha r7,0(r11)
	ctx.r7.s64 = int16_t(PPC_LOAD_U16(r11.u32 + 0));
	// li r16,0
	r16.s64 = 0;
	// b 0x823e1fac
	goto loc_823E1FAC;
loc_823E1B9C:
	// lwz r28,-11276(r19)
	r28.u64 = PPC_LOAD_U32(r19.u32 + -11276);
	// mr r11,r28
	r11.u64 = r28.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_823E1BA8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e1ba8
	if (!cr6.eq) goto loc_823E1BA8;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
loc_823E1BBC:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r7,r11,0
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 0);
	// b 0x823e1fac
	goto loc_823E1FAC;
loc_823E1BC8:
	// andi. r11,r27,2096
	r11.u64 = r27.u64 & 2096;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e1bd8
	if (!cr0.eq) goto loc_823E1BD8;
	// ori r27,r27,2048
	r27.u64 = r27.u64 | 2048;
loc_823E1BD8:
	// cmpwi cr6,r25,-1
	cr6.compare<int32_t>(r25.s32, -1, xer);
	// bne cr6,0x823e1bec
	if (!cr6.eq) goto loc_823E1BEC;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// b 0x823e1bf0
	goto loc_823E1BF0;
loc_823E1BEC:
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_823E1BF0:
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// andi. r9,r27,2064
	ctx.r9.u64 = r27.u64 & 2064;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// lwz r28,4(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq 0x823e1c4c
	if (cr0.eq) goto loc_823E1C4C;
	// bne cr6,0x823e1c18
	if (!cr6.eq) goto loc_823E1C18;
	// lwz r28,-11272(r14)
	r28.u64 = PPC_LOAD_U32(r14.u32 + -11272);
loc_823E1C18:
	// li r16,1
	r16.s64 = 1;
	// mr r11,r28
	r11.u64 = r28.u64;
	// b 0x823e1c38
	goto loc_823E1C38;
loc_823E1C24:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi r9,0
	cr0.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq 0x823e1c40
	if (cr0.eq) goto loc_823E1C40;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_823E1C38:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823e1c24
	if (!cr6.eq) goto loc_823E1C24;
loc_823E1C40:
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// srawi r7,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r7.s64 = r11.s32 >> 1;
	// b 0x823e1fac
	goto loc_823E1FAC;
loc_823E1C4C:
	// bne cr6,0x823e1c54
	if (!cr6.eq) goto loc_823E1C54;
	// lwz r28,-11276(r19)
	r28.u64 = PPC_LOAD_U32(r19.u32 + -11276);
loc_823E1C54:
	// mr r11,r28
	r11.u64 = r28.u64;
	// b 0x823e1c70
	goto loc_823E1C70;
loc_823E1C5C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823e1c78
	if (cr6.eq) goto loc_823E1C78;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_823E1C70:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823e1c5c
	if (!cr6.eq) goto loc_823E1C5C;
loc_823E1C78:
	// subf r7,r28,r11
	ctx.r7.s64 = r11.s64 - r28.s64;
	// b 0x823e1fac
	goto loc_823E1FAC;
loc_823E1C80:
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823d9860
	ctx.lr = 0x823E1C94;
	sub_823D9860(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e16a4
	if (cr0.eq) goto loc_823E16A4;
	// rlwinm. r11,r27,0,26,26
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e1cac
	if (cr0.eq) goto loc_823E1CAC;
	// sth r24,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r24.u16);
	// b 0x823e1cb0
	goto loc_823E1CB0;
loc_823E1CAC:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_823E1CB0:
	// li r11,1
	r11.s64 = 1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// b 0x823e2170
	goto loc_823E2170;
loc_823E1CBC:
	// addi r11,r8,32
	r11.s64 = ctx.r8.s64 + 32;
	// li r20,1
	r20.s64 = 1;
	// extsb r29,r11
	r29.s64 = r11.s8;
loc_823E1CC8:
	// ori r27,r27,64
	r27.u64 = r27.u64 | 64;
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
	// li r30,512
	r30.s64 = 512;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bge cr6,0x823e1ce4
	if (!cr6.lt) goto loc_823E1CE4;
	// li r25,6
	r25.s64 = 6;
	// b 0x823e1d34
	goto loc_823E1D34;
loc_823E1CE4:
	// bne cr6,0x823e1cfc
	if (!cr6.eq) goto loc_823E1CFC;
	// extsb r11,r29
	r11.s64 = r29.s8;
	// cmpwi cr6,r11,103
	cr6.compare<int32_t>(r11.s32, 103, xer);
	// bne cr6,0x823e1d34
	if (!cr6.eq) goto loc_823E1D34;
	// li r25,1
	r25.s64 = 1;
	// b 0x823e1d34
	goto loc_823E1D34;
loc_823E1CFC:
	// cmpwi cr6,r25,512
	cr6.compare<int32_t>(r25.s32, 512, xer);
	// ble cr6,0x823e1d08
	if (!cr6.gt) goto loc_823E1D08;
	// li r25,512
	r25.s64 = 512;
loc_823E1D08:
	// cmpwi cr6,r25,163
	cr6.compare<int32_t>(r25.s32, 163, xer);
	// ble cr6,0x823e1d34
	if (!cr6.gt) goto loc_823E1D34;
	// addi r31,r25,349
	r31.s64 = r25.s64 + 349;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2610
	ctx.lr = 0x823E1D1C;
	sub_823E2610(ctx, base);
	// mr. r15,r3
	r15.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r15.s32, 0, xer);
	// beq 0x823e1d30
	if (cr0.eq) goto loc_823E1D30;
	// mr r28,r15
	r28.u64 = r15.u64;
	// mr r30,r31
	r30.u64 = r31.u64;
	// b 0x823e1d34
	goto loc_823E1D34;
loc_823E1D30:
	// li r25,163
	r25.s64 = 163;
loc_823E1D34:
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// lwz r10,24(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 24);
	// extsb r31,r29
	r31.s64 = r29.s8;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// mr r8,r20
	ctx.r8.u64 = r20.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823E1D74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm. r30,r27,0,24,24
	r30.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x823e1d98
	if (cr0.eq) goto loc_823E1D98;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bne cr6,0x823e1d98
	if (!cr6.eq) goto loc_823E1D98;
	// lwz r11,36(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 36);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E1D98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823E1D98:
	// cmpwi cr6,r31,103
	cr6.compare<int32_t>(r31.s32, 103, xer);
	// bne cr6,0x823e1dbc
	if (!cr6.eq) goto loc_823E1DBC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x823e1dbc
	if (!cr6.eq) goto loc_823E1DBC;
	// lwz r11,32(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E1DBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823E1DBC:
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,45
	cr6.compare<uint32_t>(r11.u32, 45, xer);
	// bne cr6,0x823e1dd0
	if (!cr6.eq) goto loc_823E1DD0;
	// ori r27,r27,256
	r27.u64 = r27.u64 | 256;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_823E1DD0:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823E1DD4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823e1dd4
	if (!cr6.eq) goto loc_823E1DD4;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// b 0x823e1bbc
	goto loc_823E1BBC;
loc_823E1DEC:
	// ori r27,r27,64
	r27.u64 = r27.u64 | 64;
loc_823E1DF0:
	// li r8,10
	ctx.r8.s64 = 10;
	// b 0x823e1e44
	goto loc_823E1E44;
loc_823E1DF8:
	// li r25,8
	r25.s64 = 8;
loc_823E1DFC:
	// li r11,7
	r11.s64 = 7;
	// b 0x823e1e08
	goto loc_823E1E08;
loc_823E1E04:
	// li r11,39
	r11.s64 = 39;
loc_823E1E08:
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// rlwinm. r10,r27,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// li r8,16
	ctx.r8.s64 = 16;
	// beq 0x823e1e44
	if (cr0.eq) goto loc_823E1E44;
	// addi r11,r11,81
	r11.s64 = r11.s64 + 81;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r11,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, r11.u8);
	// stb r10,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r10.u8);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// b 0x823e1e44
	goto loc_823E1E44;
loc_823E1E34:
	// rlwinm. r11,r27,0,24,24
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r8,8
	ctx.r8.s64 = 8;
	// beq 0x823e1e44
	if (cr0.eq) goto loc_823E1E44;
	// ori r27,r27,512
	r27.u64 = r27.u64 | 512;
loc_823E1E44:
	// rlwinm. r11,r27,0,16,16
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e1e54
	if (!cr0.eq) goto loc_823E1E54;
	// rlwinm. r11,r27,0,19,19
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e1e68
	if (cr0.eq) goto loc_823E1E68;
loc_823E1E54:
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// ld r11,0(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// b 0x823e1eb8
	goto loc_823E1EB8;
loc_823E1E68:
	// rlwinm. r11,r27,0,26,26
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e1e98
	if (cr0.eq) goto loc_823E1E98;
	// rlwinm. r11,r27,0,25,25
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// beq 0x823e1e90
	if (cr0.eq) goto loc_823E1E90;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// b 0x823e1eb8
	goto loc_823E1EB8;
loc_823E1E90:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// b 0x823e1eb8
	goto loc_823E1EB8;
loc_823E1E98:
	// rlwinm. r11,r27,0,25,25
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r11,r26,7
	r11.s64 = r26.s64 + 7;
	// rlwinm r11,r11,0,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
	// beq 0x823e1eb4
	if (cr0.eq) goto loc_823E1EB4;
	// lwa r11,4(r11)
	r11.s64 = int32_t(PPC_LOAD_U32(r11.u32 + 4));
	// b 0x823e1eb8
	goto loc_823E1EB8;
loc_823E1EB4:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_823E1EB8:
	// rlwinm. r10,r27,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e1ed0
	if (cr0.eq) goto loc_823E1ED0;
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// bge cr6,0x823e1ed0
	if (!cr6.lt) goto loc_823E1ED0;
	// neg r11,r11
	r11.s64 = -r11.s64;
	// ori r27,r27,256
	r27.u64 = r27.u64 | 256;
loc_823E1ED0:
	// rlwinm. r10,r27,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x8000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e1ee4
	if (!cr0.eq) goto loc_823E1EE4;
	// rlwinm. r10,r27,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x1000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e1ee4
	if (!cr0.eq) goto loc_823E1EE4;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
loc_823E1EE4:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bge cr6,0x823e1ef4
	if (!cr6.lt) goto loc_823E1EF4;
	// li r25,1
	r25.s64 = 1;
	// b 0x823e1f04
	goto loc_823E1F04;
loc_823E1EF4:
	// rlwinm r27,r27,0,29,27
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r25,512
	cr6.compare<int32_t>(r25.s32, 512, xer);
	// ble cr6,0x823e1f04
	if (!cr6.gt) goto loc_823E1F04;
	// li r25,512
	r25.s64 = 512;
loc_823E1F04:
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// bne cr6,0x823e1f14
	if (!cr6.eq) goto loc_823E1F14;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_823E1F14:
	// addi r9,r1,655
	ctx.r9.s64 = ctx.r1.s64 + 655;
loc_823E1F18:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// addi r25,r25,-1
	r25.s64 = r25.s64 + -1;
	// bgt cr6,0x823e1f2c
	if (cr6.gt) goto loc_823E1F2C;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x823e1f70
	if (cr6.eq) goto loc_823E1F70;
loc_823E1F2C:
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// divdu r7,r11,r10
	ctx.r7.u64 = r11.u64 / ctx.r10.u64;
	// tdllei r10,0
	// mulld r7,r7,r10
	ctx.r7.s64 = ctx.r7.s64 * ctx.r10.s64;
	// subf r7,r7,r11
	ctx.r7.s64 = r11.s64 - ctx.r7.s64;
	// divdu r11,r11,r10
	r11.u64 = r11.u64 / ctx.r10.u64;
	// tdllei r10,0
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpwi cr6,r10,57
	cr6.compare<int32_t>(ctx.r10.s32, 57, xer);
	// ble cr6,0x823e1f60
	if (!cr6.gt) goto loc_823E1F60;
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
loc_823E1F60:
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x823e1f18
	goto loc_823E1F18;
loc_823E1F70:
	// addi r11,r1,655
	r11.s64 = ctx.r1.s64 + 655;
	// rlwinm. r10,r27,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x200;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subf r7,r9,r11
	ctx.r7.s64 = r11.s64 - ctx.r9.s64;
	// addi r28,r9,1
	r28.s64 = ctx.r9.s64 + 1;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// beq 0x823e1fb0
	if (cr0.eq) goto loc_823E1FB0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x823e1f9c
	if (cr6.eq) goto loc_823E1F9C;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,48
	cr6.compare<uint32_t>(r11.u32, 48, xer);
	// beq cr6,0x823e1fb0
	if (cr6.eq) goto loc_823E1FB0;
loc_823E1F9C:
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// li r11,48
	r11.s64 = 48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
loc_823E1FAC:
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
loc_823E1FB0:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e2170
	if (!cr6.eq) goto loc_823E2170;
	// rlwinm. r11,r27,0,25,25
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e2000
	if (cr0.eq) goto loc_823E2000;
	// rlwinm. r11,r27,0,23,23
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x100;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e1fd4
	if (cr0.eq) goto loc_823E1FD4;
	// li r11,45
	r11.s64 = 45;
	// b 0x823e1fe0
	goto loc_823E1FE0;
loc_823E1FD4:
	// clrlwi. r11,r27,31
	r11.u64 = r27.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e1ff0
	if (cr0.eq) goto loc_823E1FF0;
	// li r11,43
	r11.s64 = 43;
loc_823E1FE0:
	// li r30,1
	r30.s64 = 1;
	// stb r11,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r11.u8);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// b 0x823e2004
	goto loc_823E2004;
loc_823E1FF0:
	// rlwinm. r11,r27,0,30,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e2000
	if (cr0.eq) goto loc_823E2000;
	// li r11,32
	r11.s64 = 32;
	// b 0x823e1fe0
	goto loc_823E1FE0;
loc_823E2000:
	// lwz r30,92(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_823E2004:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm. r10,r27,0,28,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0xC;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// subf r29,r30,r11
	r29.s64 = r11.s64 - r30.s64;
	// bne 0x823e204c
	if (!cr0.eq) goto loc_823E204C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x823e204c
	if (!cr6.gt) goto loc_823E204C;
loc_823E2024:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// bl 0x823e1538
	ctx.lr = 0x823E2038;
	sub_823E1538(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x823e204c
	if (cr6.eq) goto loc_823E204C;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x823e2024
	if (cr6.gt) goto loc_823E2024;
loc_823E204C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x823e15d0
	ctx.lr = 0x823E2060;
	sub_823E15D0(ctx, base);
	// rlwinm. r11,r27,0,28,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e20a4
	if (cr0.eq) goto loc_823E20A4;
	// rlwinm. r11,r27,0,29,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e20a4
	if (!cr0.eq) goto loc_823E20A4;
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x823e20a4
	if (!cr6.gt) goto loc_823E20A4;
loc_823E207C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// bl 0x823e1538
	ctx.lr = 0x823E2090;
	sub_823E1538(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x823e20a4
	if (cr6.eq) goto loc_823E20A4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x823e207c
	if (cr6.gt) goto loc_823E207C;
loc_823E20A4:
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r16,0
	cr6.compare<int32_t>(r16.s32, 0, xer);
	// beq cr6,0x823e2118
	if (cr6.eq) goto loc_823E2118;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x823e2118
	if (!cr6.gt) goto loc_823E2118;
	// mr r30,r28
	r30.u64 = r28.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
loc_823E20C0:
	// li r5,6
	ctx.r5.s64 = 6;
	// lhz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// bl 0x823e6588
	ctx.lr = 0x823E20DC;
	sub_823E6588(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e210c
	if (!cr0.eq) goto loc_823E210C;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823e210c
	if (cr6.eq) goto loc_823E210C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x823e15d0
	ctx.lr = 0x823E2100;
	sub_823E15D0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x823e20c0
	if (!cr6.eq) goto loc_823E20C0;
	// b 0x823e2128
	goto loc_823E2128;
loc_823E210C:
	// li r24,-1
	r24.s64 = -1;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// b 0x823e212c
	goto loc_823E212C;
loc_823E2118:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e15d0
	ctx.lr = 0x823E2128;
	sub_823E15D0(ctx, base);
loc_823E2128:
	// lwz r24,80(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823E212C:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// blt cr6,0x823e2170
	if (cr6.lt) goto loc_823E2170;
	// rlwinm. r11,r27,0,29,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e2170
	if (cr0.eq) goto loc_823E2170;
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x823e2170
	if (!cr6.gt) goto loc_823E2170;
loc_823E2148:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// bl 0x823e1538
	ctx.lr = 0x823E215C;
	sub_823E1538(ctx, base);
	// lwz r24,80(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r24,-1
	cr6.compare<int32_t>(r24.s32, -1, xer);
	// beq cr6,0x823e2170
	if (cr6.eq) goto loc_823E2170;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x823e2148
	if (cr6.gt) goto loc_823E2148;
loc_823E2170:
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x823e2184
	if (cr6.eq) goto loc_823E2184;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823e2c38
	ctx.lr = 0x823E2180;
	sub_823E2C38(ctx, base);
	// li r15,0
	r15.s64 = 0;
loc_823E2184:
	// lbz r29,0(r18)
	r29.u64 = PPC_LOAD_U8(r18.u32 + 0);
	// extsb. r8,r29
	ctx.r8.s64 = r29.s8;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x823e2198
	if (cr0.eq) goto loc_823E2198;
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x823e1810
	goto loc_823E1810;
loc_823E2198:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// b 0x823e21d4
	goto loc_823E21D4;
loc_823E21A0:
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// li r4,512
	ctx.r4.s64 = 512;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x823de150
	ctx.lr = 0x823E21B4;
	sub_823DE150(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x823e21c8
	if (!cr6.eq) goto loc_823E21C8;
	// li r31,511
	r31.s64 = 511;
	// stb r27,1167(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1167, r27.u8);
loc_823E21C8:
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x82457b48
	ctx.lr = 0x823E21D0;
	sub_82457B48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823E21D4:
	// addi r1,r1,1328
	ctx.r1.s64 = ctx.r1.s64 + 1328;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_823E21DC"))) PPC_WEAK_FUNC(sub_823E21DC);
PPC_FUNC_IMPL(__imp__sub_823E21DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E21E0"))) PPC_WEAK_FUNC(sub_823E21E0);
PPC_FUNC_IMPL(__imp__sub_823E21E0) {
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
	ctx.lr = 0x823E21E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823e2208
	if (!cr6.eq) goto loc_823E2208;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2610
	ctx.lr = 0x823E2204;
	sub_823E2610(ctx, base);
	// b 0x823e2294
	goto loc_823E2294;
loc_823E2208:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823e221c
	if (!cr6.eq) goto loc_823E221C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e2c38
	ctx.lr = 0x823E2218;
	sub_823E2C38(ctx, base);
	// b 0x823e2290
	goto loc_823E2290;
loc_823E221C:
	// li r29,-4096
	r29.s64 = -4096;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bgt cr6,0x823e2278
	if (cr6.gt) goto loc_823E2278;
	// lis r27,-32115
	r27.s64 = -2104688640;
loc_823E222C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823e2238
	if (!cr6.eq) goto loc_823E2238;
	// li r31,1
	r31.s64 = 1;
loc_823E2238:
	// bl 0x82135d28
	ctx.lr = 0x823E223C;
	sub_82135D28(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x82135440
	ctx.lr = 0x823E224C;
	sub_82135440(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823e22c8
	if (!cr0.eq) goto loc_823E22C8;
	// lwz r11,-9936(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -9936);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823e22b4
	if (cr6.eq) goto loc_823E22B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2bf0
	ctx.lr = 0x823E2268;
	sub_823E2BF0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e229c
	if (cr0.eq) goto loc_823E229C;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// ble cr6,0x823e222c
	if (!cr6.gt) goto loc_823E222C;
loc_823E2278:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2bf0
	ctx.lr = 0x823E2280;
	sub_823E2BF0(ctx, base);
	// bl 0x823e1000
	ctx.lr = 0x823E2284;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_823E2290:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823E2294:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823E229C:
	// bl 0x823e1000
	ctx.lr = 0x823E22A0;
	sub_823E1000(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82135db0
	ctx.lr = 0x823E22A8;
	sub_82135DB0(ctx, base);
	// bl 0x823e0f98
	ctx.lr = 0x823E22AC;
	sub_823E0F98(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x823e2290
	goto loc_823E2290;
loc_823E22B4:
	// bl 0x823e1000
	ctx.lr = 0x823E22B8;
	sub_823E1000(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82135db0
	ctx.lr = 0x823E22C0;
	sub_82135DB0(ctx, base);
	// bl 0x823e0f98
	ctx.lr = 0x823E22C4;
	sub_823E0F98(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_823E22C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// b 0x823e2294
	goto loc_823E2294;
}

__attribute__((alias("__imp__sub_823E22D0"))) PPC_WEAK_FUNC(sub_823E22D0);
PPC_FUNC_IMPL(__imp__sub_823E22D0) {
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
	ctx.lr = 0x823E22D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823e232c
	if (cr6.eq) goto loc_823E232C;
	// li r11,-4096
	r11.s64 = -4096;
	// twllei r4,0
	// divwu r11,r11,r4
	r11.u32 = r11.u32 / ctx.r4.u32;
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// bge cr6,0x823e232c
	if (!cr6.lt) goto loc_823E232C;
	// bl 0x823e1000
	ctx.lr = 0x823E2304;
	sub_823E1000(ctx, base);
	// li r11,12
	r11.s64 = 12;
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
	ctx.lr = 0x823E2324;
	sub_823E02A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823e2374
	goto loc_823E2374;
loc_823E232C:
	// mullw r30,r4,r5
	r30.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823e2344
	if (cr6.eq) goto loc_823E2344;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2380
	ctx.lr = 0x823E2340;
	sub_823E2380(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_823E2344:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e21e0
	ctx.lr = 0x823E2350;
	sub_823E21E0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x823e2370
	if (cr0.eq) goto loc_823E2370;
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// bge cr6,0x823e2370
	if (!cr6.lt) goto loc_823E2370;
	// subf r5,r29,r30
	ctx.r5.s64 = r30.s64 - r29.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r3,r29,r31
	ctx.r3.u64 = r29.u64 + r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x823E2370;
	sub_823D9890(ctx, base);
loc_823E2370:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823E2374:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E237C"))) PPC_WEAK_FUNC(sub_823E237C);
PPC_FUNC_IMPL(__imp__sub_823E237C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2380"))) PPC_WEAK_FUNC(sub_823E2380);
PPC_FUNC_IMPL(__imp__sub_823E2380) {
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
	// bne cr6,0x823e23c8
	if (!cr6.eq) goto loc_823E23C8;
	// bl 0x823e1000
	ctx.lr = 0x823E23A0;
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
	ctx.lr = 0x823E23C0;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823e23d8
	goto loc_823E23D8;
loc_823E23C8:
	// bl 0x82135d28
	ctx.lr = 0x823E23CC;
	sub_82135D28(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82133b00
	ctx.lr = 0x823E23D8;
	sub_82133B00(ctx, base);
loc_823E23D8:
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

__attribute__((alias("__imp__sub_823E23EC"))) PPC_WEAK_FUNC(sub_823E23EC);
PPC_FUNC_IMPL(__imp__sub_823E23EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E23F0"))) PPC_WEAK_FUNC(sub_823E23F0);
PPC_FUNC_IMPL(__imp__sub_823E23F0) {
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
	ctx.lr = 0x823E23F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r30,-4096
	r30.s64 = -4096;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823e2448
	if (cr6.eq) goto loc_823E2448;
	// divwu r11,r30,r3
	r11.u32 = r30.u32 / ctx.r3.u32;
	// twllei r3,0
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bge cr6,0x823e2448
	if (!cr6.lt) goto loc_823E2448;
	// bl 0x823e1000
	ctx.lr = 0x823E2420;
	sub_823E1000(ctx, base);
	// li r11,12
	r11.s64 = 12;
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
	ctx.lr = 0x823E2440;
	sub_823E02A8(ctx, base);
loc_823E2440:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823e24bc
	goto loc_823E24BC;
loc_823E2448:
	// mullw. r31,r3,r4
	r31.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x823e2454
	if (!cr0.eq) goto loc_823E2454;
	// li r31,1
	r31.s64 = 1;
loc_823E2454:
	// lis r29,-32115
	r29.s64 = -2104688640;
loc_823E2458:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bgt cr6,0x823e247c
	if (cr6.gt) goto loc_823E247C;
	// bl 0x82135d28
	ctx.lr = 0x823E2468;
	sub_82135D28(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82134860
	ctx.lr = 0x823E2474;
	sub_82134860(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e24bc
	if (!cr0.eq) goto loc_823E24BC;
loc_823E247C:
	// lwz r11,-9936(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -9936);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823e24ac
	if (cr6.eq) goto loc_823E24AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2bf0
	ctx.lr = 0x823E2490;
	sub_823E2BF0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e2458
	if (!cr0.eq) goto loc_823E2458;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823e2440
	if (cr6.eq) goto loc_823E2440;
	// li r11,12
	r11.s64 = 12;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x823e2440
	goto loc_823E2440;
loc_823E24AC:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823e24bc
	if (cr6.eq) goto loc_823E24BC;
	// li r11,12
	r11.s64 = 12;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_823E24BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823E24C4"))) PPC_WEAK_FUNC(sub_823E24C4);
PPC_FUNC_IMPL(__imp__sub_823E24C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E24C8"))) PPC_WEAK_FUNC(sub_823E24C8);
PPC_FUNC_IMPL(__imp__sub_823E24C8) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x823e23f0
	ctx.lr = 0x823E24EC;
	sub_823E23F0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x823e2514
	if (!cr0.eq) goto loc_823E2514;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x823e2514
	if (cr6.eq) goto loc_823E2514;
	// bl 0x823e1000
	ctx.lr = 0x823E2504;
	sub_823E1000(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x823e2514
	if (cr0.eq) goto loc_823E2514;
	// bl 0x823e1000
	ctx.lr = 0x823E2510;
	sub_823E1000(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
loc_823E2514:
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

__attribute__((alias("__imp__sub_823E2530"))) PPC_WEAK_FUNC(sub_823E2530);
PPC_FUNC_IMPL(__imp__sub_823E2530) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823e2550
	if (cr6.eq) goto loc_823E2550;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x823e257c
	if (!cr6.eq) goto loc_823E257C;
loc_823E2550:
	// bl 0x823e1000
	ctx.lr = 0x823E2554;
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
	ctx.lr = 0x823E2574;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823e25fc
	goto loc_823E25FC;
loc_823E257C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x823e25b8
	if (!cr6.eq) goto loc_823E25B8;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// bl 0x823e1000
	ctx.lr = 0x823E2590;
	sub_823E1000(ctx, base);
	// li r31,22
	r31.s64 = 22;
loc_823E2594:
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
	ctx.lr = 0x823E25B0;
	sub_823E02A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x823e25fc
	goto loc_823E25FC;
loc_823E25B8:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_823E25BC:
	// lbz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beq 0x823e25dc
	if (cr0.eq) goto loc_823E25DC;
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne 0x823e25bc
	if (!cr0.eq) goto loc_823E25BC;
loc_823E25DC:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x823e25f8
	if (!cr6.eq) goto loc_823E25F8;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// bl 0x823e1000
	ctx.lr = 0x823E25F0;
	sub_823E1000(ctx, base);
	// li r31,34
	r31.s64 = 34;
	// b 0x823e2594
	goto loc_823E2594;
loc_823E25F8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823E25FC:
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

__attribute__((alias("__imp__sub_823E2610"))) PPC_WEAK_FUNC(sub_823E2610);
PPC_FUNC_IMPL(__imp__sub_823E2610) {
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
	ctx.lr = 0x823E2618;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,-4096
	r11.s64 = -4096;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bgt cr6,0x823e26b4
	if (cr6.gt) goto loc_823E26B4;
	// lis r28,-32115
	r28.s64 = -2104688640;
loc_823E2630:
	// bl 0x82135d28
	ctx.lr = 0x823E2634;
	sub_82135D28(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e2650
	if (!cr0.eq) goto loc_823E2650;
	// bl 0x823e2788
	ctx.lr = 0x823E2640;
	sub_823E2788(ctx, base);
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x823e2740
	ctx.lr = 0x823E2648;
	sub_823E2740(ctx, base);
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x823daec8
	ctx.lr = 0x823E2650;
	sub_823DAEC8(ctx, base);
loc_823E2650:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r31,r30
	r31.u64 = r30.u64;
	// bne cr6,0x823e2660
	if (!cr6.eq) goto loc_823E2660;
	// li r31,1
	r31.s64 = 1;
loc_823E2660:
	// bl 0x82135d28
	ctx.lr = 0x823E2664;
	sub_82135D28(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82134860
	ctx.lr = 0x823E2670;
	sub_82134860(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x823e26ac
	if (!cr0.eq) goto loc_823E26AC;
	// lwz r11,-9936(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -9936);
	// li r31,12
	r31.s64 = 12;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823e269c
	if (cr6.eq) goto loc_823E269C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e2bf0
	ctx.lr = 0x823E2690;
	sub_823E2BF0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e2630
	if (!cr0.eq) goto loc_823E2630;
	// b 0x823e26a4
	goto loc_823E26A4;
loc_823E269C:
	// bl 0x823e1000
	ctx.lr = 0x823E26A0;
	sub_823E1000(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
loc_823E26A4:
	// bl 0x823e1000
	ctx.lr = 0x823E26A8;
	sub_823E1000(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
loc_823E26AC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// b 0x823e26d0
	goto loc_823E26D0;
loc_823E26B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823e2bf0
	ctx.lr = 0x823E26BC;
	sub_823E2BF0(ctx, base);
	// bl 0x823e1000
	ctx.lr = 0x823E26C0;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_823E26D0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823E26D8"))) PPC_WEAK_FUNC(sub_823E26D8);
PPC_FUNC_IMPL(__imp__sub_823E26D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r3,1,23,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1FE;
	// lwz r11,-18352(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18352);
	// lwz r11,200(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// lhzx r11,r10,r11
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + r11.u32);
	// rlwinm r3,r11,0,0,16
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E26F4"))) PPC_WEAK_FUNC(sub_823E26F4);
PPC_FUNC_IMPL(__imp__sub_823E26F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E26F8"))) PPC_WEAK_FUNC(sub_823E26F8);
PPC_FUNC_IMPL(__imp__sub_823E26F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_823E26F8:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r10,-65
	r11.s64 = ctx.r10.s64 + -65;
	// cmplwi cr6,r11,25
	cr6.compare<uint32_t>(r11.u32, 25, xer);
	// bgt cr6,0x823e2710
	if (cr6.gt) goto loc_823E2710;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
loc_823E2710:
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r9,r11,-65
	ctx.r9.s64 = r11.s64 + -65;
	// cmplwi cr6,r9,25
	cr6.compare<uint32_t>(ctx.r9.u32, 25, xer);
	// bgt cr6,0x823e2728
	if (cr6.gt) goto loc_823E2728;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
loc_823E2728:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823e2738
	if (cr6.eq) goto loc_823E2738;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x823e26f8
	if (cr6.eq) goto loc_823E26F8;
loc_823E2738:
	// subf r3,r11,r10
	ctx.r3.s64 = ctx.r10.s64 - r11.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2740"))) PPC_WEAK_FUNC(sub_823E2740);
PPC_FUNC_IMPL(__imp__sub_823E2740) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-18344
	ctx.r9.s64 = ctx.r10.s64 + -18344;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_823E2750:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// beq cr6,0x823e276c
	if (cr6.eq) goto loc_823E276C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r11,23
	cr6.compare<uint32_t>(r11.u32, 23, xer);
	// blt cr6,0x823e2750
	if (cr6.lt) goto loc_823E2750;
loc_823E276C:
	// cmplwi cr6,r11,23
	cr6.compare<uint32_t>(r11.u32, 23, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x82457b48
	sub_82457B48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823E2784"))) PPC_WEAK_FUNC(sub_823E2784);
PPC_FUNC_IMPL(__imp__sub_823E2784) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2788"))) PPC_WEAK_FUNC(sub_823E2788);
PPC_FUNC_IMPL(__imp__sub_823E2788) {
	PPC_FUNC_PROLOGUE();
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
	// li r3,252
	ctx.r3.s64 = 252;
	// bl 0x823e2740
	ctx.lr = 0x823E279C;
	sub_823E2740(ctx, base);
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x823e2740
	ctx.lr = 0x823E27A4;
	sub_823E2740(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E27B4"))) PPC_WEAK_FUNC(sub_823E27B4);
PPC_FUNC_IMPL(__imp__sub_823E27B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E27B8"))) PPC_WEAK_FUNC(sub_823E27B8);
PPC_FUNC_IMPL(__imp__sub_823E27B8) {
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
	ctx.lr = 0x823E27C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r30,r10,-18160
	r30.s64 = ctx.r10.s64 + -18160;
	// addi r28,r11,-10408
	r28.s64 = r11.s64 + -10408;
	// mr r31,r30
	r31.u64 = r30.u64;
	// li r29,0
	r29.s64 = 0;
loc_823E27DC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x823e2804
	if (!cr6.eq) goto loc_823E2804;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// rotlwi r3,r28,0
	ctx.r3.u64 = __builtin_rotateleft32(r28.u32, 0);
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r28,r28,28
	r28.s64 = r28.s64 + 28;
	// bl 0x823e2b30
	ctx.lr = 0x823E27FC;
	sub_823E2B30(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823e2824
	if (cr0.eq) goto loc_823E2824;
loc_823E2804:
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// addi r11,r30,288
	r11.s64 = r30.s64 + 288;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823e27dc
	if (cr6.lt) goto loc_823E27DC;
	// li r3,1
	ctx.r3.s64 = 1;
loc_823E281C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823E2824:
	// rlwinm r11,r29,3,0,28
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r10,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r10.u32);
	// b 0x823e281c
	goto loc_823E281C;
}

__attribute__((alias("__imp__sub_823E2838"))) PPC_WEAK_FUNC(sub_823E2838);
PPC_FUNC_IMPL(__imp__sub_823E2838) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r30,r11,-18160
	r30.s64 = r11.s64 + -18160;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_823E2858:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823e287c
	if (cr6.eq) goto loc_823E287C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823e287c
	if (cr6.eq) goto loc_823E287C;
	// bl 0x823e2c38
	ctx.lr = 0x823E2874;
	sub_823E2C38(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E287C:
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// addi r11,r30,288
	r11.s64 = r30.s64 + 288;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823e2858
	if (cr6.lt) goto loc_823E2858;
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

__attribute__((alias("__imp__sub_823E28A4"))) PPC_WEAK_FUNC(sub_823E28A4);
PPC_FUNC_IMPL(__imp__sub_823E28A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E28A8"))) PPC_WEAK_FUNC(sub_823E28A8);
PPC_FUNC_IMPL(__imp__sub_823E28A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-18160
	r11.s64 = r11.s64 + -18160;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x827bcf54
	__imp__RtlLeaveCriticalSection(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823E28BC"))) PPC_WEAK_FUNC(sub_823E28BC);
PPC_FUNC_IMPL(__imp__sub_823E28BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E28C0"))) PPC_WEAK_FUNC(sub_823E28C0);
PPC_FUNC_IMPL(__imp__sub_823E28C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9704(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9704);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823E28D0;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// bl 0x82135d28
	ctx.lr = 0x823E28E8;
	sub_82135D28(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e2904
	if (!cr0.eq) goto loc_823E2904;
	// bl 0x823e2788
	ctx.lr = 0x823E28F4;
	sub_823E2788(ctx, base);
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x823e2740
	ctx.lr = 0x823E28FC;
	sub_823E2740(ctx, base);
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x823daec8
	ctx.lr = 0x823E2904;
	sub_823DAEC8(ctx, base);
loc_823E2904:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r29,r30,3,0,28
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r30,r11,-18160
	r30.s64 = r11.s64 + -18160;
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e2924
	if (cr6.eq) goto loc_823E2924;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823e29b4
	goto loc_823E29B4;
loc_823E2924:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x823e2610
	ctx.lr = 0x823E292C;
	sub_823E2610(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bne 0x823e294c
	if (!cr0.eq) goto loc_823E294C;
	// bl 0x823e1000
	ctx.lr = 0x823E2938;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e29b4
	goto loc_823E29B4;
loc_823E294C:
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x823e2a08
	ctx.lr = 0x823E2954;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bne cr6,0x823e29a0
	if (!cr6.eq) goto loc_823E29A0;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// bl 0x823e2b30
	ctx.lr = 0x823E2970;
	sub_823E2B30(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e2998
	if (!cr0.eq) goto loc_823E2998;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e2c38
	ctx.lr = 0x823E2980;
	sub_823E2C38(ctx, base);
	// bl 0x823e1000
	ctx.lr = 0x823E2984;
	sub_823E1000(ctx, base);
	// li r11,12
	r11.s64 = 12;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// b 0x823e29a4
	goto loc_823E29A4;
loc_823E2998:
	// stwx r28,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r28.u32);
	// b 0x823e29a4
	goto loc_823E29A4;
loc_823E29A0:
	// bl 0x823e2c38
	ctx.lr = 0x823E29A4;
	sub_823E2C38(ctx, base);
loc_823E29A4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823e29d8
	ctx.lr = 0x823E29B0;
	sub_823E29D8(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E29B4:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823E28C8"))) PPC_WEAK_FUNC(sub_823E28C8);
PPC_FUNC_IMPL(__imp__sub_823E28C8) {
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
	ctx.lr = 0x823E28D0;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// bl 0x82135d28
	ctx.lr = 0x823E28E8;
	sub_82135D28(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823e2904
	if (!cr0.eq) goto loc_823E2904;
	// bl 0x823e2788
	ctx.lr = 0x823E28F4;
	sub_823E2788(ctx, base);
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x823e2740
	ctx.lr = 0x823E28FC;
	sub_823E2740(ctx, base);
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x823daec8
	ctx.lr = 0x823E2904;
	sub_823DAEC8(ctx, base);
loc_823E2904:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r29,r30,3,0,28
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r30,r11,-18160
	r30.s64 = r11.s64 + -18160;
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e2924
	if (cr6.eq) goto loc_823E2924;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823e29b4
	goto loc_823E29B4;
loc_823E2924:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x823e2610
	ctx.lr = 0x823E292C;
	sub_823E2610(ctx, base);
	// mr. r28,r3
	r28.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bne 0x823e294c
	if (!cr0.eq) goto loc_823E294C;
	// bl 0x823e1000
	ctx.lr = 0x823E2938;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823e29b4
	goto loc_823E29B4;
loc_823E294C:
	// li r3,10
	ctx.r3.s64 = 10;
	// bl 0x823e2a08
	ctx.lr = 0x823E2954;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bne cr6,0x823e29a0
	if (!cr6.eq) goto loc_823E29A0;
	// li r4,4000
	ctx.r4.s64 = 4000;
	// bl 0x823e2b30
	ctx.lr = 0x823E2970;
	sub_823E2B30(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e2998
	if (!cr0.eq) goto loc_823E2998;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e2c38
	ctx.lr = 0x823E2980;
	sub_823E2C38(ctx, base);
	// bl 0x823e1000
	ctx.lr = 0x823E2984;
	sub_823E1000(ctx, base);
	// li r11,12
	r11.s64 = 12;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// b 0x823e29a4
	goto loc_823E29A4;
loc_823E2998:
	// stwx r28,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r28.u32);
	// b 0x823e29a4
	goto loc_823E29A4;
loc_823E29A0:
	// bl 0x823e2c38
	ctx.lr = 0x823E29A4;
	sub_823E2C38(ctx, base);
loc_823E29A4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823e29d8
	ctx.lr = 0x823E29B0;
	sub_823E29D8(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_823E29B4:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823E29BC"))) PPC_WEAK_FUNC(sub_823E29BC);
PPC_FUNC_IMPL(__imp__sub_823E29BC) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	uint32_t ea{};
	// std r30,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r30,r11,-18160
	r30.s64 = r11.s64 + -18160;
	// b 0x823e29e8
	goto loc_823E29E8;
	// std r30,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_823E29E8:
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// bl 0x827bcf54
	ctx.lr = 0x823E29F0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r30,-8(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// lwz r12,-16(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E29D8"))) PPC_WEAK_FUNC(sub_823E29D8);
PPC_FUNC_IMPL(__imp__sub_823E29D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	uint32_t ea{};
	// std r30,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r30.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// bl 0x827bcf54
	ctx.lr = 0x823E29F0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r30,-8(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// lwz r12,-16(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2A04"))) PPC_WEAK_FUNC(sub_823E2A04);
PPC_FUNC_IMPL(__imp__sub_823E2A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2A08"))) PPC_WEAK_FUNC(sub_823E2A08);
PPC_FUNC_IMPL(__imp__sub_823E2A08) {
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r31,r3,3,0,28
	r31.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r30,r11,-18160
	r30.s64 = r11.s64 + -18160;
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e2a48
	if (!cr6.eq) goto loc_823E2A48;
	// bl 0x823e28c8
	ctx.lr = 0x823E2A38;
	sub_823E28C8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e2a48
	if (!cr0.eq) goto loc_823E2A48;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x823dae80
	ctx.lr = 0x823E2A48;
	sub_823DAE80(ctx, base);
loc_823E2A48:
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x827bcf64
	ctx.lr = 0x823E2A50;
	__imp__RtlEnterCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_823E2A68"))) PPC_WEAK_FUNC(sub_823E2A68);
PPC_FUNC_IMPL(__imp__sub_823E2A68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9728(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9728);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r31,r1,-96
	r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x823db2f8
	ctx.lr = 0x823E2A88;
	sub_823DB2F8(ctx, base);
	// lwz r11,108(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e2ab0
	if (cr6.eq) goto loc_823E2AB0;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E2AA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_823E2AB0:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,324
	ctx.r3.u64 = ctx.r3.u64 | 324;
	// bl 0x827bd4b4
	ctx.lr = 0x823E2ABC;
	__imp__KeBugCheck(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2A70"))) PPC_WEAK_FUNC(sub_823E2A70);
PPC_FUNC_IMPL(__imp__sub_823E2A70) {
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
	// addi r31,r1,-96
	r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x823db2f8
	ctx.lr = 0x823E2A88;
	sub_823DB2F8(ctx, base);
	// lwz r11,108(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823e2ab0
	if (cr6.eq) goto loc_823E2AB0;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E2AA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
loc_823E2AB0:
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// ori r3,r3,324
	ctx.r3.u64 = ctx.r3.u64 | 324;
	// bl 0x827bd4b4
	ctx.lr = 0x823E2ABC;
	__imp__KeBugCheck(ctx, base);
}

__attribute__((alias("__imp__sub_823E2ABC"))) PPC_WEAK_FUNC(sub_823E2ABC);
PPC_FUNC_IMPL(__imp__sub_823E2ABC) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2AC8"))) PPC_WEAK_FUNC(sub_823E2AC8);
PPC_FUNC_IMPL(__imp__sub_823E2AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32194
	r11.s64 = -2109865984;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r11,r11,10864
	r11.s64 = r11.s64 + 10864;
	// stw r11,-10016(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10016, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2ADC"))) PPC_WEAK_FUNC(sub_823E2ADC);
PPC_FUNC_IMPL(__imp__sub_823E2ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2AE0"))) PPC_WEAK_FUNC(sub_823E2AE0);
PPC_FUNC_IMPL(__imp__sub_823E2AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,-10012(r11)
	PPC_STORE_U32(r11.u32 + -10012, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2AEC"))) PPC_WEAK_FUNC(sub_823E2AEC);
PPC_FUNC_IMPL(__imp__sub_823E2AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2AF0"))) PPC_WEAK_FUNC(sub_823E2AF0);
PPC_FUNC_IMPL(__imp__sub_823E2AF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,-10008(r11)
	PPC_STORE_U32(r11.u32 + -10008, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2AFC"))) PPC_WEAK_FUNC(sub_823E2AFC);
PPC_FUNC_IMPL(__imp__sub_823E2AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2B00"))) PPC_WEAK_FUNC(sub_823E2B00);
PPC_FUNC_IMPL(__imp__sub_823E2B00) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x827bcff4
	ctx.lr = 0x823E2B10;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2B24"))) PPC_WEAK_FUNC(sub_823E2B24);
PPC_FUNC_IMPL(__imp__sub_823E2B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2B28"))) PPC_WEAK_FUNC(sub_823E2B28);
PPC_FUNC_IMPL(__imp__sub_823E2B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9752(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9752);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,-10008(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10008);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e2b60
	if (!cr6.eq) goto loc_823E2B60;
	// lis r11,-32194
	r11.s64 = -2109865984;
	// addi r11,r11,11008
	r11.s64 = r11.s64 + 11008;
	// stw r11,-10008(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10008, r11.u32);
loc_823E2B60:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E2B74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823e2ba8
	// ERROR 823E2BA8
	return;
}

__attribute__((alias("__imp__sub_823E2B30"))) PPC_WEAK_FUNC(sub_823E2B30);
PPC_FUNC_IMPL(__imp__sub_823E2B30) {
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
	// addi r31,r1,-112
	r31.s64 = ctx.r1.s64 + -112;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,-10008(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10008);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823e2b60
	if (!cr6.eq) goto loc_823E2B60;
	// lis r11,-32194
	r11.s64 = -2109865984;
	// addi r11,r11,11008
	r11.s64 = r11.s64 + 11008;
	// stw r11,-10008(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10008, r11.u32);
loc_823E2B60:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E2B74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823e2ba8
	goto loc_823E2BA8;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,23
	r11.u64 = r11.u64 | 23;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bne cr6,0x823e2ba0
	if (!cr6.eq) goto loc_823E2BA0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82135d38
	ctx.lr = 0x823E2BA0;
	sub_82135D38(ctx, base);
loc_823E2BA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
loc_823E2BA8:
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2B88"))) PPC_WEAK_FUNC(sub_823E2B88);
PPC_FUNC_IMPL(__imp__sub_823E2B88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,23
	r11.u64 = r11.u64 | 23;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bne cr6,0x823e2ba0
	if (!cr6.eq) goto loc_823E2BA0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82135d38
	ctx.lr = 0x823E2BA0;
	sub_82135D38(ctx, base);
loc_823E2BA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// addi r1,r31,112
	ctx.r1.s64 = r31.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2BBC"))) PPC_WEAK_FUNC(sub_823E2BBC);
PPC_FUNC_IMPL(__imp__sub_823E2BBC) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,23
	r11.u64 = r11.u64 | 23;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2BE0"))) PPC_WEAK_FUNC(sub_823E2BE0);
PPC_FUNC_IMPL(__imp__sub_823E2BE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r3,-10004(r11)
	PPC_STORE_U32(r11.u32 + -10004, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2BEC"))) PPC_WEAK_FUNC(sub_823E2BEC);
PPC_FUNC_IMPL(__imp__sub_823E2BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2BF0"))) PPC_WEAK_FUNC(sub_823E2BF0);
PPC_FUNC_IMPL(__imp__sub_823E2BF0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-10004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// cmplwi r11,0
	cr0.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x823e2c20
	if (cr0.eq) goto loc_823E2C20;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E2C14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne 0x823e2c24
	if (!cr0.eq) goto loc_823E2C24;
loc_823E2C20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823E2C24:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2C34"))) PPC_WEAK_FUNC(sub_823E2C34);
PPC_FUNC_IMPL(__imp__sub_823E2C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2C38"))) PPC_WEAK_FUNC(sub_823E2C38);
PPC_FUNC_IMPL(__imp__sub_823E2C38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// beq cr6,0x823e2c80
	if (cr6.eq) goto loc_823E2C80;
	// bl 0x82135d28
	ctx.lr = 0x823E2C58;
	sub_82135D28(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82135150
	ctx.lr = 0x823E2C64;
	sub_82135150(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e2c80
	if (!cr0.eq) goto loc_823E2C80;
	// bl 0x823e1000
	ctx.lr = 0x823E2C70;
	sub_823E1000(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82135db0
	ctx.lr = 0x823E2C78;
	sub_82135DB0(ctx, base);
	// bl 0x823e0f98
	ctx.lr = 0x823E2C7C;
	sub_823E0F98(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_823E2C80:
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

__attribute__((alias("__imp__sub_823E2C94"))) PPC_WEAK_FUNC(sub_823E2C94);
PPC_FUNC_IMPL(__imp__sub_823E2C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2C98"))) PPC_WEAK_FUNC(sub_823E2C98);
PPC_FUNC_IMPL(__imp__sub_823E2C98) {
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
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823e2ccc
	if (cr6.eq) goto loc_823E2CCC;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r10,-12600(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12600);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823e2cf0
	if (cr6.eq) goto loc_823E2CF0;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E2CC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823e2cf0
	goto loc_823E2CF0;
loc_823E2CCC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r10,-12596(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12596);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823e2ce8
	if (cr6.eq) goto loc_823E2CE8;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823E2CE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823E2CE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823db3e8
	ctx.lr = 0x823E2CF0;
	sub_823DB3E8(ctx, base);
loc_823E2CF0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2D00"))) PPC_WEAK_FUNC(sub_823E2D00);
PPC_FUNC_IMPL(__imp__sub_823E2D00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// stfd f1,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// addi r10,r4,1022
	ctx.r10.s64 = ctx.r4.s64 + 1022;
	// andi. r11,r11,32783
	r11.u64 = r11.u64 & 32783;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// sth r11,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, r11.u16);
	// lfd f1,-16(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2D28"))) PPC_WEAK_FUNC(sub_823E2D28);
PPC_FUNC_IMPL(__imp__sub_823E2D28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r11,r11,28,21,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x7FF;
	// addi r11,r11,-1022
	r11.s64 = r11.s64 + -1022;
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2D40"))) PPC_WEAK_FUNC(sub_823E2D40);
PPC_FUNC_IMPL(__imp__sub_823E2D40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// stfd f1,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// lhz r10,-16(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// stfd f1,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// rlwinm r11,r11,28,21,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x7FF;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// andi. r10,r10,32783
	ctx.r10.u64 = ctx.r10.u64 & 32783;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// sth r11,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, r11.u16);
	// lfd f1,-16(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2D74"))) PPC_WEAK_FUNC(sub_823E2D74);
PPC_FUNC_IMPL(__imp__sub_823E2D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2D78"))) PPC_WEAK_FUNC(sub_823E2D78);
PPC_FUNC_IMPL(__imp__sub_823E2D78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,32752
	r11.s64 = 2146435072;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lwz r10,16(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r9,20(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823e2da0
	if (!cr6.eq) goto loc_823E2DA0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e2dbc
	if (!cr6.eq) goto loc_823E2DBC;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_823E2DA0:
	// lis r11,-16
	r11.s64 = -1048576;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823e2dbc
	if (!cr6.eq) goto loc_823E2DBC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823e2dbc
	if (!cr6.eq) goto loc_823E2DBC;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_823E2DBC:
	// lhz r11,16(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r11,r11,0,17,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x7FF8;
	// cmplwi cr6,r11,32760
	cr6.compare<uint32_t>(r11.u32, 32760, xer);
	// bne cr6,0x823e2dd4
	if (!cr6.eq) goto loc_823E2DD4;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_823E2DD4:
	// cmplwi cr6,r11,32752
	cr6.compare<uint32_t>(r11.u32, 32752, xer);
	// bne cr6,0x823e2df4
	if (!cr6.eq) goto loc_823E2DF4;
	// clrlwi. r11,r10,13
	r11.u64 = ctx.r10.u32 & 0x7FFFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e2dec
	if (!cr0.eq) goto loc_823E2DEC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823e2df4
	if (cr6.eq) goto loc_823E2DF4;
loc_823E2DEC:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_823E2DF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2DFC"))) PPC_WEAK_FUNC(sub_823E2DFC);
PPC_FUNC_IMPL(__imp__sub_823E2DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2E00"))) PPC_WEAK_FUNC(sub_823E2E00);
PPC_FUNC_IMPL(__imp__sub_823E2E00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lfd f0,-17600(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bne cr6,0x823e2e1c
	if (!cr6.eq) goto loc_823E2E1C;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x823e2eec
	goto loc_823E2EEC;
loc_823E2E1C:
	// lhz r10,16(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm. r11,r10,0,17,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7FF0;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// bne 0x823e2ec8
	if (!cr0.eq) goto loc_823E2EC8;
	// lwz r7,16(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r9,20(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// clrlwi. r8,r7,12
	ctx.r8.u64 = ctx.r7.u32 & 0xFFFFF;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x823e2e44
	if (!cr0.eq) goto loc_823E2E44;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823e2ec8
	if (cr6.eq) goto loc_823E2EC8;
loc_823E2E44:
	// li r8,-1021
	ctx.r8.s64 = -1021;
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// li r6,1
	ctx.r6.s64 = 1;
	// blt cr6,0x823e2e58
	if (cr6.lt) goto loc_823E2E58;
	// li r6,0
	ctx.r6.s64 = 0;
loc_823E2E58:
	// rlwinm. r11,r5,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x823e2e90
	if (!cr0.eq) goto loc_823E2E90;
loc_823E2E60:
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm. r11,r9,0,0,0
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r7,16(r1)
	PPC_STORE_U32(ctx.r1.u32 + 16, ctx.r7.u32);
	// beq 0x823e2e78
	if (cr0.eq) goto loc_823E2E78;
	// ori r7,r7,1
	ctx.r7.u64 = ctx.r7.u64 | 1;
	// stw r7,16(r1)
	PPC_STORE_U32(ctx.r1.u32 + 16, ctx.r7.u32);
loc_823E2E78:
	// lhz r10,16(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// rlwinm. r11,r10,0,27,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e2e60
	if (cr0.eq) goto loc_823E2E60;
	// stw r9,20(r1)
	PPC_STORE_U32(ctx.r1.u32 + 20, ctx.r9.u32);
loc_823E2E90:
	// andi. r11,r10,65519
	r11.u64 = ctx.r10.u64 & 65519;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// sth r11,16(r1)
	PPC_STORE_U16(ctx.r1.u32 + 16, r11.u16);
	// beq cr6,0x823e2ea8
	if (cr6.eq) goto loc_823E2EA8;
	// ori r11,r11,32768
	r11.u64 = r11.u64 | 32768;
	// sth r11,16(r1)
	PPC_STORE_U16(ctx.r1.u32 + 16, r11.u16);
loc_823E2EA8:
	// lfd f0,16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 16);
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lhz r11,-16(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// andi. r11,r11,32783
	r11.u64 = r11.u64 & 32783;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// ori r11,r11,16352
	r11.u64 = r11.u64 | 16352;
	// sth r11,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, r11.u16);
	// b 0x823e2ee8
	goto loc_823E2EE8;
loc_823E2EC8:
	// stfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// lhz r10,-16(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// andi. r10,r10,32783
	ctx.r10.u64 = ctx.r10.u64 & 32783;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfd f1,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// ori r10,r10,16352
	ctx.r10.u64 = ctx.r10.u64 | 16352;
	// rlwinm r11,r11,28,20,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFF;
	// sth r10,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, ctx.r10.u16);
	// addi r8,r11,-1022
	ctx.r8.s64 = r11.s64 + -1022;
loc_823E2EE8:
	// lfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
loc_823E2EEC:
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E2EF4"))) PPC_WEAK_FUNC(sub_823E2EF4);
PPC_FUNC_IMPL(__imp__sub_823E2EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E2EF8"))) PPC_WEAK_FUNC(sub_823E2EF8);
PPC_FUNC_IMPL(__imp__sub_823E2EF8) {
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
	ctx.lr = 0x823E2F00;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// stw r3,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r3.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// rlwinm. r4,r5,0,27,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// beq 0x823e2f58
	if (cr0.eq) goto loc_823E2F58;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	r27.s64 = -1073741824;
	// ori r27,r27,143
	r27.u64 = r27.u64 | 143;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// b 0x823e2f5c
	goto loc_823E2F5C;
loc_823E2F58:
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823E2F5C:
	// rlwinm. r11,r5,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e2f7c
	if (cr0.eq) goto loc_823E2F7C;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	r27.s64 = -1073741824;
	// ori r27,r27,147
	r27.u64 = r27.u64 | 147;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_823E2F7C:
	// clrlwi. r11,r5,31
	r11.u64 = ctx.r5.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e2f9c
	if (cr0.eq) goto loc_823E2F9C;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	r27.s64 = -1073741824;
	// ori r27,r27,145
	r27.u64 = r27.u64 | 145;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// oris r10,r10,8192
	ctx.r10.u64 = ctx.r10.u64 | 536870912;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_823E2F9C:
	// rlwinm. r11,r5,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e2fbc
	if (cr0.eq) goto loc_823E2FBC;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	r27.s64 = -1073741824;
	// ori r27,r27,142
	r27.u64 = r27.u64 | 142;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// oris r10,r10,4096
	ctx.r10.u64 = ctx.r10.u64 | 268435456;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_823E2FBC:
	// rlwinm. r11,r5,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e2fdc
	if (cr0.eq) goto loc_823E2FDC;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lis r27,-16384
	r27.s64 = -1073741824;
	// ori r27,r27,144
	r27.u64 = r27.u64 | 144;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_823E2FDC:
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwimi r9,r10,20,4,4
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 20) & 0x8000000) | (ctx.r9.u64 & 0xFFFFFFFFF7FFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwimi r9,r10,24,3,3
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0x10000000) | (ctx.r9.u64 & 0xFFFFFFFFEFFFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwimi r9,r10,23,2,2
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 23) & 0x20000000) | (ctx.r9.u64 & 0xFFFFFFFFDFFFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwimi r9,r10,25,1,1
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 25) & 0x40000000) | (ctx.r9.u64 & 0xFFFFFFFFBFFFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwimi r9,r10,28,0,0
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 28) & 0x80000000) | (ctx.r9.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// bl 0x823e39f0
	ctx.lr = 0x823E3058;
	sub_823E39F0(ctx, base);
	// rlwinm. r11,r3,0,2,2
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3070
	if (cr0.eq) goto loc_823E3070;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_823E3070:
	// rlwinm. r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3088
	if (cr0.eq) goto loc_823E3088;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// oris r10,r10,4096
	ctx.r10.u64 = ctx.r10.u64 | 268435456;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_823E3088:
	// rlwinm. r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e30a0
	if (cr0.eq) goto loc_823E30A0;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// oris r10,r10,8192
	ctx.r10.u64 = ctx.r10.u64 | 536870912;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_823E30A0:
	// rlwinm. r11,r3,0,4,4
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e30b8
	if (cr0.eq) goto loc_823E30B8;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// oris r10,r10,16384
	ctx.r10.u64 = ctx.r10.u64 | 1073741824;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_823E30B8:
	// rlwinm. r11,r3,0,6,6
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e30d0
	if (cr0.eq) goto loc_823E30D0;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_823E30D0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r30,1
	r30.s64 = 1;
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x823e3124
	if (cr6.lt) goto loc_823E3124;
	// beq cr6,0x823e3114
	if (cr6.eq) goto loc_823E3114;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x823e3104
	if (cr6.lt) goto loc_823E3104;
	// bne cr6,0x823e3134
	if (!cr6.eq) goto loc_823E3134;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwimi r10,r30,30,0,1
	ctx.r10.u64 = (__builtin_rotateleft32(r30.u32, 30) & 0xC0000000) | (ctx.r10.u64 & 0xFFFFFFFF3FFFFFFF);
	// b 0x823e3130
	goto loc_823E3130;
loc_823E3104:
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwimi r10,r30,31,0,1
	ctx.r10.u64 = (__builtin_rotateleft32(r30.u32, 31) & 0xC0000000) | (ctx.r10.u64 & 0xFFFFFFFF3FFFFFFF);
	// b 0x823e3130
	goto loc_823E3130;
loc_823E3114:
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// oris r10,r10,49152
	ctx.r10.u64 = ctx.r10.u64 | 3221225472;
	// b 0x823e3130
	goto loc_823E3130;
loc_823E3124:
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r10,r10,2
	ctx.r10.u64 = ctx.r10.u32 & 0x3FFFFFFF;
loc_823E3130:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_823E3134:
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwimi r10,r30,27,2,4
	ctx.r10.u64 = (__builtin_rotateleft32(r30.u32, 27) & 0x38000000) | (ctx.r10.u64 & 0xFFFFFFFFC7FFFFFF);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwimi r10,r28,15,5,16
	ctx.r10.u64 = (__builtin_rotateleft32(r28.u32, 15) & 0x7FF8000) | (ctx.r10.u64 & 0xFFFFFFFFF8007FFF);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// beq cr6,0x823e31b8
	if (cr6.eq) goto loc_823E31B8;
	// rlwinm r10,r10,0,5,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF87FFFFFF;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stfs f0,16(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// rlwinm r10,r10,0,5,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF87FFFFFF;
	// stw r10,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfs f0,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
	// b 0x823e31f8
	goto loc_823E31F8;
loc_823E31B8:
	// rlwimi r10,r30,27,1,4
	ctx.r10.u64 = (__builtin_rotateleft32(r30.u32, 27) & 0x78000000) | (ctx.r10.u64 & 0xFFFFFFFF87FFFFFF);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfd f0,0(r29)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// stfd f0,16(r11)
	PPC_STORE_U64(r11.u32 + 16, f0.u64);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// oris r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 2147483648;
	// stw r10,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// rlwimi r10,r30,27,1,4
	ctx.r10.u64 = (__builtin_rotateleft32(r30.u32, 27) & 0x78000000) | (ctx.r10.u64 & 0xFFFFFFFF87FFFFFF);
	// stw r10,96(r11)
	PPC_STORE_U32(r11.u32 + 96, ctx.r10.u32);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfd f0,0(r26)
	f0.u64 = PPC_LOAD_U64(r26.u32 + 0);
	// stfd f0,80(r11)
	PPC_STORE_U64(r11.u32 + 80, f0.u64);
loc_823E31F8:
	// bl 0x823e6640
	ctx.lr = 0x823E31FC;
	sub_823E6640(ctx, base);
	// addi r6,r1,180
	ctx.r6.s64 = ctx.r1.s64 + 180;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82457d10
	ctx.lr = 0x823E3210;
	sub_82457D10(ctx, base);
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,4,4
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e322c
	if (cr0.eq) goto loc_823E322C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r11,0,25,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF7F;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E322C:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,3,3
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3244
	if (cr0.eq) goto loc_823E3244;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r11,0,28,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E3244:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,2,2
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e325c
	if (cr0.eq) goto loc_823E325C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r11,0,26,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E325C:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,1,1
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3274
	if (cr0.eq) goto loc_823E3274;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r11,0,27,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E3274:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm. r11,r11,0,0,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e328c
	if (cr0.eq) goto loc_823E328C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r11,0,29,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E328C:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r11,r11,2,30,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x823e32d0
	if (cr6.lt) goto loc_823E32D0;
	// beq cr6,0x823e32c4
	if (cr6.eq) goto loc_823E32C4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x823e32b8
	if (cr6.lt) goto loc_823E32B8;
	// bne cr6,0x823e32dc
	if (!cr6.eq) goto loc_823E32DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwimi r11,r30,0,30,31
	r11.u64 = (__builtin_rotateleft32(r30.u32, 0) & 0x3) | (r11.u64 & 0xFFFFFFFFFFFFFFFC);
	// b 0x823e32d8
	goto loc_823E32D8;
loc_823E32B8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwimi r11,r30,1,30,31
	r11.u64 = (__builtin_rotateleft32(r30.u32, 1) & 0x3) | (r11.u64 & 0xFFFFFFFFFFFFFFFC);
	// b 0x823e32d8
	goto loc_823E32D8;
loc_823E32C4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r11,r11,3
	r11.u64 = r11.u64 | 3;
	// b 0x823e32d8
	goto loc_823E32D8;
loc_823E32D0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
loc_823E32D8:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823E32DC:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x823e32f0
	if (cr6.eq) goto loc_823E32F0;
	// lfs f0,80(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// b 0x823e32f8
	goto loc_823E32F8;
loc_823E32F0:
	// lfd f0,80(r10)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 80);
	// stfd f0,0(r26)
	PPC_STORE_U64(r26.u32 + 0, f0.u64);
loc_823E32F8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823E3300"))) PPC_WEAK_FUNC(sub_823E3300);
PPC_FUNC_IMPL(__imp__sub_823E3300) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823E3308;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// rlwinm. r11,r29,0,28,28
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// clrlwi r28,r29,27
	r28.u64 = r29.u32 & 0x1F;
	// beq 0x823e3340
	if (cr0.eq) goto loc_823E3340;
	// rlwinm. r11,r27,0,24,24
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3340
	if (cr0.eq) goto loc_823E3340;
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// bl 0x823e3a24
	ctx.lr = 0x823E3338;
	sub_823E3A24(ctx, base);
	// rlwinm r28,r28,0,29,27
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// b 0x823e3524
	goto loc_823E3524;
loc_823E3340:
	// rlwinm. r11,r29,0,29,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3360
	if (cr0.eq) goto loc_823E3360;
	// rlwinm. r11,r27,0,27,27
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3360
	if (cr0.eq) goto loc_823E3360;
	// lis r3,1024
	ctx.r3.s64 = 67108864;
	// bl 0x823e3a24
	ctx.lr = 0x823E3358;
	sub_823E3A24(ctx, base);
	// rlwinm r28,r28,0,30,28
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// b 0x823e3524
	goto loc_823E3524;
loc_823E3360:
	// clrlwi. r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e342c
	if (cr0.eq) goto loc_823E342C;
	// rlwinm. r11,r27,0,25,25
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e342c
	if (cr0.eq) goto loc_823E342C;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// bl 0x823e3a24
	ctx.lr = 0x823E3378;
	sub_823E3A24(ctx, base);
	// clrlwi r11,r27,30
	r11.u64 = r27.u32 & 0x3;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x823e33f4
	if (cr6.lt) goto loc_823E33F4;
	// beq cr6,0x823e33d4
	if (cr6.eq) goto loc_823E33D4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x823e33b4
	if (cr6.lt) goto loc_823E33B4;
	// bne cr6,0x823e3424
	if (!cr6.eq) goto loc_823E3424;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// lfd f0,-17600(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823e3414
	if (!cr6.gt) goto loc_823E3414;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lfd f0,-17720(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17720);
	// b 0x823e3420
	goto loc_823E3420;
loc_823E33B4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// lfd f0,-17600(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x823e3408
	if (cr6.gt) goto loc_823E3408;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lfd f0,-17720(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17720);
	// b 0x823e341c
	goto loc_823E341C;
loc_823E33D4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// lfd f0,-17600(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lfd f0,-17720(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17720);
	// bgt cr6,0x823e3420
	if (cr6.gt) goto loc_823E3420;
	// b 0x823e341c
	goto loc_823E341C;
loc_823E33F4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f13,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// lfd f0,-17600(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823e3414
	if (!cr6.gt) goto loc_823E3414;
loc_823E3408:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lfd f0,-17736(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17736);
	// b 0x823e3420
	goto loc_823E3420;
loc_823E3414:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lfd f0,-17736(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17736);
loc_823E341C:
	// fneg f0,f0
	ctx.fpscr.disableFlushMode();
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_823E3420:
	// stfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(r30.u32 + 0, f0.u64);
loc_823E3424:
	// rlwinm r28,r28,0,0,30
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFE;
	// b 0x823e3524
	goto loc_823E3524;
loc_823E342C:
	// rlwinm. r11,r29,0,30,30
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3524
	if (cr0.eq) goto loc_823E3524;
	// rlwinm. r11,r27,0,26,26
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3524
	if (cr0.eq) goto loc_823E3524;
	// rlwinm. r11,r29,0,27,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r31,0
	r31.s64 = 0;
	// beq 0x823e344c
	if (cr0.eq) goto loc_823E344C;
	// li r31,1
	r31.s64 = 1;
loc_823E344C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f1,0(r30)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// lfd f31,-17600(r11)
	f31.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x823e350c
	if (cr6.eq) goto loc_823E350C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823e2e00
	ctx.lr = 0x823E3468;
	sub_823E2E00(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfd f1,80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// addi r11,r11,-1536
	r11.s64 = r11.s64 + -1536;
	// cmpwi cr6,r11,-1074
	cr6.compare<int32_t>(r11.s32, -1074, xer);
	// bge cr6,0x823e3488
	if (!cr6.lt) goto loc_823E3488;
	// fmul f0,f1,f31
	f0.f64 = ctx.f1.f64 * f31.f64;
	// li r31,1
	r31.s64 = 1;
	// b 0x823e3504
	goto loc_823E3504;
loc_823E3488:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// li r8,1
	ctx.r8.s64 = 1;
	// blt cr6,0x823e3498
	if (cr6.lt) goto loc_823E3498;
	// li r8,0
	ctx.r8.s64 = 0;
loc_823E3498:
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,-1021
	cr6.compare<int32_t>(r11.s32, -1021, xer);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// ori r10,r10,16
	ctx.r10.u64 = ctx.r10.u64 | 16;
	// sth r10,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// bge cr6,0x823e34f4
	if (!cr6.lt) goto loc_823E34F4;
	// subfic r9,r11,-1021
	xer.ca = r11.u32 <= 4294966275;
	ctx.r9.s64 = -1021 - r11.s64;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823E34BC:
	// clrlwi. r7,r11,31
	ctx.r7.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq 0x823e34d0
	if (cr0.eq) goto loc_823E34D0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x823e34d0
	if (!cr6.eq) goto loc_823E34D0;
	// li r31,1
	r31.s64 = 1;
loc_823E34D0:
	// clrlwi. r7,r10,31
	ctx.r7.u64 = ctx.r10.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// beq 0x823e34e0
	if (cr0.eq) goto loc_823E34E0;
	// oris r11,r11,32768
	r11.u64 = r11.u64 | 2147483648;
loc_823E34E0:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bne 0x823e34bc
	if (!cr0.eq) goto loc_823E34BC;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
loc_823E34F4:
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x823e3504
	if (cr6.eq) goto loc_823E3504;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_823E3504:
	// stfd f0,0(r30)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(r30.u32 + 0, f0.u64);
	// b 0x823e3510
	goto loc_823E3510;
loc_823E350C:
	// li r31,1
	r31.s64 = 1;
loc_823E3510:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x823e3520
	if (cr6.eq) goto loc_823E3520;
	// lis r3,2048
	ctx.r3.s64 = 134217728;
	// bl 0x823e3a24
	ctx.lr = 0x823E3520;
	sub_823E3A24(ctx, base);
loc_823E3520:
	// rlwinm r28,r28,0,31,29
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
loc_823E3524:
	// rlwinm. r11,r29,0,27,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3540
	if (cr0.eq) goto loc_823E3540;
	// rlwinm. r11,r27,0,28,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3540
	if (cr0.eq) goto loc_823E3540;
	// lis r3,512
	ctx.r3.s64 = 33554432;
	// bl 0x823e3a24
	ctx.lr = 0x823E353C;
	sub_823E3A24(ctx, base);
	// rlwinm r28,r28,0,28,26
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_823E3540:
	// cntlzw r11,r28
	r11.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823E3554"))) PPC_WEAK_FUNC(sub_823E3554);
PPC_FUNC_IMPL(__imp__sub_823E3554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E3558"))) PPC_WEAK_FUNC(sub_823E3558);
PPC_FUNC_IMPL(__imp__sub_823E3558) {
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
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x823e3584
	if (cr6.eq) goto loc_823E3584;
	// ble cr6,0x823e3590
	if (!cr6.gt) goto loc_823E3590;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bgt cr6,0x823e3590
	if (cr6.gt) goto loc_823E3590;
	// bl 0x823e1000
	ctx.lr = 0x823E357C;
	sub_823E1000(ctx, base);
	// li r11,34
	r11.s64 = 34;
	// b 0x823e358c
	goto loc_823E358C;
loc_823E3584:
	// bl 0x823e1000
	ctx.lr = 0x823E3588;
	sub_823E1000(ctx, base);
	// li r11,33
	r11.s64 = 33;
loc_823E358C:
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_823E3590:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E35A0"))) PPC_WEAK_FUNC(sub_823E35A0);
PPC_FUNC_IMPL(__imp__sub_823E35A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// rlwinm. r11,r3,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e35b0
	if (cr0.eq) goto loc_823E35B0;
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_823E35B0:
	// rlwinm. r11,r3,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e35c0
	if (cr0.eq) goto loc_823E35C0;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_823E35C0:
	// rlwinm. r11,r3,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e35d0
	if (cr0.eq) goto loc_823E35D0;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_823E35D0:
	// clrlwi. r11,r3,31
	r11.u64 = ctx.r3.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e35e0
	if (cr0.eq) goto loc_823E35E0;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_823E35E0:
	// rlwinm r3,r3,1,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E35E8"))) PPC_WEAK_FUNC(sub_823E35E8);
PPC_FUNC_IMPL(__imp__sub_823E35E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// fmr f31,f3
	f31.f64 = ctx.f3.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stfd f1,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.f1.u64);
	// addi r11,r11,-17696
	r11.s64 = r11.s64 + -17696;
	// stfd f2,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.f2.u64);
	// stfd f31,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, f31.u64);
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823E3624:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x823e36b4
	if (cr6.eq) goto loc_823E36B4;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r8,r11,232
	ctx.r8.s64 = r11.s64 + 232;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x823e3624
	if (cr6.lt) goto loc_823E3624;
	// li r11,0
	r11.s64 = 0;
loc_823E3648:
	// lis r4,-16377
	ctx.r4.s64 = -1073283072;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ori r4,r4,65279
	ctx.r4.u64 = ctx.r4.u64 | 65279;
	// beq cr6,0x823e36c4
	if (cr6.eq) goto loc_823E36C4;
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r9,184(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lwz r8,188(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r7,192(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lwz r6,196(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// bl 0x823e39c0
	ctx.lr = 0x823E3694;
	sub_823E39C0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821a5cc0
	ctx.lr = 0x823E369C;
	sub_821A5CC0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e36ac
	if (!cr0.eq) goto loc_823E36AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3558
	ctx.lr = 0x823E36AC;
	sub_823E3558(ctx, base);
loc_823E36AC:
	// lfd f1,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// b 0x823e36d4
	goto loc_823E36D4;
loc_823E36B4:
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x823e3648
	goto loc_823E3648;
loc_823E36C4:
	// bl 0x823e39c0
	ctx.lr = 0x823E36C8;
	sub_823E39C0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3558
	ctx.lr = 0x823E36D0;
	sub_823E3558(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_823E36D4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_823E36EC"))) PPC_WEAK_FUNC(sub_823E36EC);
PPC_FUNC_IMPL(__imp__sub_823E36EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E36F0"))) PPC_WEAK_FUNC(sub_823E36F0);
PPC_FUNC_IMPL(__imp__sub_823E36F0) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r11,-16684(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -16684);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e373c
	if (!cr6.eq) goto loc_823E373C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfd f2,-17600(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// bl 0x823e35e8
	ctx.lr = 0x823E3738;
	sub_823E35E8(ctx, base);
	// b 0x823e3760
	goto loc_823E3760;
loc_823E373C:
	// bl 0x823e1000
	ctx.lr = 0x823E3740;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,33
	ctx.r10.s64 = 33;
	// lis r4,-16377
	ctx.r4.s64 = -1073283072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,65279
	ctx.r4.u64 = ctx.r4.u64 | 65279;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x823e39c0
	ctx.lr = 0x823E375C;
	sub_823E39C0(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_823E3760:
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

__attribute__((alias("__imp__sub_823E3778"))) PPC_WEAK_FUNC(sub_823E3778);
PPC_FUNC_IMPL(__imp__sub_823E3778) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32129
	r11.s64 = -2105606144;
	// fadd f31,f1,f2
	f31.f64 = ctx.f1.f64 + ctx.f2.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lwz r11,-16684(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -16684);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e37bc
	if (!cr6.eq) goto loc_823E37BC;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e35e8
	ctx.lr = 0x823E37B8;
	sub_823E35E8(ctx, base);
	// b 0x823e37e0
	goto loc_823E37E0;
loc_823E37BC:
	// bl 0x823e1000
	ctx.lr = 0x823E37C0;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,33
	ctx.r10.s64 = 33;
	// lis r4,-16377
	ctx.r4.s64 = -1073283072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r4,65279
	ctx.r4.u64 = ctx.r4.u64 | 65279;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x823e39c0
	ctx.lr = 0x823E37DC;
	sub_823E39C0(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_823E37E0:
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

__attribute__((alias("__imp__sub_823E37F8"))) PPC_WEAK_FUNC(sub_823E37F8);
PPC_FUNC_IMPL(__imp__sub_823E37F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x823E3800;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stfd f2,280(r1)
	PPC_STORE_U64(ctx.r1.u32 + 280, ctx.f2.u64);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r4,r1,280
	ctx.r4.s64 = ctx.r1.s64 + 280;
	// stfd f31,272(r1)
	PPC_STORE_U64(ctx.r1.u32 + 272, f31.u64);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r30,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823e3300
	ctx.lr = 0x823E3830;
	sub_823E3300(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e3868
	if (!cr0.eq) goto loc_823E3868;
	// lwz r11,144(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,280
	ctx.r8.s64 = ctx.r1.s64 + 280;
	// clrlwi r11,r11,1
	r11.u64 = r11.u32 & 0x7FFFFFFF;
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,292
	ctx.r4.s64 = ctx.r1.s64 + 292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823e2ef8
	ctx.lr = 0x823E3864;
	sub_823E2EF8(ctx, base);
	// lwz r30,292(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
loc_823E3868:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e35a0
	ctx.lr = 0x823E3870;
	sub_823E35A0(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r11,-16684(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -16684);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e38a8
	if (!cr6.eq) goto loc_823E38A8;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823e38a8
	if (cr6.eq) goto loc_823E38A8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f3,280(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 280);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfd f2,-17600(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// bl 0x823e35e8
	ctx.lr = 0x823E38A4;
	sub_823E35E8(ctx, base);
	// b 0x823e38c0
	goto loc_823E38C0;
loc_823E38A8:
	// bl 0x823e3558
	ctx.lr = 0x823E38AC;
	sub_823E3558(ctx, base);
	// lis r4,-16377
	ctx.r4.s64 = -1073283072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,65279
	ctx.r4.u64 = ctx.r4.u64 | 65279;
	// bl 0x823e39c0
	ctx.lr = 0x823E38BC;
	sub_823E39C0(ctx, base);
	// lfd f1,280(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 280);
loc_823E38C0:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E38CC"))) PPC_WEAK_FUNC(sub_823E38CC);
PPC_FUNC_IMPL(__imp__sub_823E38CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E38D0"))) PPC_WEAK_FUNC(sub_823E38D0);
PPC_FUNC_IMPL(__imp__sub_823E38D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f30{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823E38D8;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stfd f3,288(r1)
	PPC_STORE_U64(ctx.r1.u32 + 288, ctx.f3.u64);
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// stfd f30,272(r1)
	PPC_STORE_U64(ctx.r1.u32 + 272, f30.u64);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r30,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// bl 0x823e3300
	ctx.lr = 0x823E3910;
	sub_823E3300(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e3950
	if (!cr0.eq) goto loc_823E3950;
	// lwz r11,144(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// stfd f31,128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 128, f31.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r11,r11,5
	r11.u64 = r11.u32 & 0x7FFFFFF;
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// oris r11,r11,34816
	r11.u64 = r11.u64 | 2281701376;
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,300
	ctx.r4.s64 = ctx.r1.s64 + 300;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823e2ef8
	ctx.lr = 0x823E394C;
	sub_823E2EF8(ctx, base);
	// lwz r30,300(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
loc_823E3950:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e35a0
	ctx.lr = 0x823E3958;
	sub_823E35A0(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r11,-16684(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -16684);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823e398c
	if (!cr6.eq) goto loc_823E398C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823e398c
	if (cr6.eq) goto loc_823E398C;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lfd f3,288(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 288);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823e35e8
	ctx.lr = 0x823E3988;
	sub_823E35E8(ctx, base);
	// b 0x823e39a4
	goto loc_823E39A4;
loc_823E398C:
	// bl 0x823e3558
	ctx.lr = 0x823E3990;
	sub_823E3558(ctx, base);
	// lis r4,-16377
	ctx.r4.s64 = -1073283072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,65279
	ctx.r4.u64 = ctx.r4.u64 | 65279;
	// bl 0x823e39c0
	ctx.lr = 0x823E39A0;
	sub_823E39C0(ctx, base);
	// lfd f1,288(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 288);
loc_823E39A4:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823E39B4"))) PPC_WEAK_FUNC(sub_823E39B4);
PPC_FUNC_IMPL(__imp__sub_823E39B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E39B8"))) PPC_WEAK_FUNC(sub_823E39B8);
PPC_FUNC_IMPL(__imp__sub_823E39B8) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E39BC"))) PPC_WEAK_FUNC(sub_823E39BC);
PPC_FUNC_IMPL(__imp__sub_823E39BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E39C0"))) PPC_WEAK_FUNC(sub_823E39C0);
PPC_FUNC_IMPL(__imp__sub_823E39C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	// mffs f0
	f0.u64 = ctx.fpscr.loadFromHost();
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, f0.u64);
	// xori r5,r3,248
	ctx.r5.u64 = ctx.r3.u64 ^ 248;
	// lwz r3,-4(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// and r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 & ctx.r4.u64;
	// andc r6,r3,r4
	ctx.r6.u64 = ctx.r3.u64 & ~ctx.r4.u64;
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// stw r6,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r6.u32);
	// lfd f0,-8(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// xori r3,r3,248
	ctx.r3.u64 = ctx.r3.u64 ^ 248;
	// mtfsf 255,f0
	ctx.fpscr.storeFromGuest(f0.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E39F0"))) PPC_WEAK_FUNC(sub_823E39F0);
PPC_FUNC_IMPL(__imp__sub_823E39F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	// mffs f0
	f0.u64 = ctx.fpscr.loadFromHost();
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, f0.u64);
	// lwz r3,-4(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E3A00"))) PPC_WEAK_FUNC(sub_823E3A00);
PPC_FUNC_IMPL(__imp__sub_823E3A00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	// mffs f0
	f0.u64 = ctx.fpscr.loadFromHost();
	// li r3,4
	ctx.r3.s64 = 4;
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, f0.u64);
	// lwz r5,-4(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// and r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 & ctx.r5.u64;
	// stw r5,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r5.u32);
	// lfd f1,-8(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// mtfsf 255,f1
	ctx.fpscr.storeFromGuest(ctx.f1.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E3A24"))) PPC_WEAK_FUNC(sub_823E3A24);
PPC_FUNC_IMPL(__imp__sub_823E3A24) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	// mffs f0
	f0.u64 = ctx.fpscr.loadFromHost();
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, f0.u64);
	// lwz r5,-4(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// or r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 | ctx.r5.u64;
	// stw r5,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r5.u32);
	// lfd f1,-8(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// mtfsf 255,f1
	ctx.fpscr.storeFromGuest(ctx.f1.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E3A44"))) PPC_WEAK_FUNC(sub_823E3A44);
PPC_FUNC_IMPL(__imp__sub_823E3A44) {
	PPC_FUNC_PROLOGUE();
	// stw r3,-4(r1)
	PPC_STORE_U32(ctx.r1.u32 + -4, ctx.r3.u32);
	// lfd f1,-8(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// mtfsf 255,f1
	ctx.fpscr.storeFromGuest(ctx.f1.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E3A54"))) PPC_WEAK_FUNC(sub_823E3A54);
PPC_FUNC_IMPL(__imp__sub_823E3A54) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	// mffs f0
	f0.u64 = ctx.fpscr.loadFromHost();
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -8, f0.u64);
	// lwz r3,-4(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823E3A64"))) PPC_WEAK_FUNC(sub_823E3A64);
PPC_FUNC_IMPL(__imp__sub_823E3A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823E3A68"))) PPC_WEAK_FUNC(sub_823E3A68);
PPC_FUNC_IMPL(__imp__sub_823E3A68) {
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
	ctx.lr = 0x823E3A70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e3de0
	ctx.lr = 0x823E3A84;
	sub_823E3DE0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// andi. r10,r11,130
	ctx.r10.u64 = r11.u64 & 130;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cmpwi r10,0
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e3abc
	if (!cr0.eq) goto loc_823E3ABC;
	// bl 0x823e1000
	ctx.lr = 0x823E3A9C;
	sub_823E1000(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
loc_823E3AA0:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_823E3AA8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
loc_823E3AAC:
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x823e3c30
	goto loc_823E3C30;
loc_823E3ABC:
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823e3ad0
	if (cr0.eq) goto loc_823E3AD0;
	// bl 0x823e1000
	ctx.lr = 0x823E3AC8;
	sub_823E1000(ctx, base);
	// li r10,34
	ctx.r10.s64 = 34;
	// b 0x823e3aa0
	goto loc_823E3AA0;
loc_823E3AD0:
	// clrlwi. r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq 0x823e3af8
	if (cr0.eq) goto loc_823E3AF8;
	// rlwinm. r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// beq 0x823e3aac
	if (cr0.eq) goto loc_823E3AAC;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_823E3AF8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// rlwinm r11,r11,0,28,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// andi. r10,r11,268
	ctx.r10.u64 = r11.u64 & 268;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// cmpwi r10,0
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823e3b54
	if (!cr0.eq) goto loc_823E3B54;
	// bl 0x823e1160
	ctx.lr = 0x823E3B20;
	sub_823E1160(ctx, base);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x823e3b3c
	if (cr6.eq) goto loc_823E3B3C;
	// bl 0x823e1160
	ctx.lr = 0x823E3B30;
	sub_823E1160(ctx, base);
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x823e3b4c
	if (!cr6.eq) goto loc_823E3B4C;
loc_823E3B3C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x823E3B44;
	sub_821A5CC0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823e3b54
	if (!cr0.eq) goto loc_823E3B54;
loc_823E3B4C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e6cb8
	ctx.lr = 0x823E3B54;
	sub_823E6CB8(ctx, base);
loc_823E3B54:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// andi. r11,r11,264
	r11.u64 = r11.u64 & 264;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// cmpwi r11,0
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3c08
	if (cr0.eq) goto loc_823E3C08;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// subf. r30,r4,r10
	r30.s64 = ctx.r10.s64 - ctx.r4.s64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r4,1
	ctx.r10.s64 = ctx.r4.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// ble 0x823e3b9c
	if (!cr0.gt) goto loc_823E3B9C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823e6b28
	ctx.lr = 0x823E3B94;
	sub_823E6B28(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x823e3bf8
	goto loc_823E3BF8;
loc_823E3B9C:
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x823e3bcc
	if (cr6.eq) goto loc_823E3BCC;
	// cmpwi cr6,r29,-2
	cr6.compare<int32_t>(r29.s32, -2, xer);
	// beq cr6,0x823e3bcc
	if (cr6.eq) goto loc_823E3BCC;
	// srawi r11,r29,5
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x1F) != 0);
	r11.s64 = r29.s32 >> 5;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-23104
	ctx.r10.s64 = ctx.r10.s64 + -23104;
	// rlwinm r11,r29,6,21,25
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 6) & 0x7C0;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x823e3bd4
	goto loc_823E3BD4;
loc_823E3BCC:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r11,r11,-17448
	r11.s64 = r11.s64 + -17448;
loc_823E3BD4:
	// lbz r11,4(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823e3bf8
	if (cr0.eq) goto loc_823E3BF8;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823e6740
	ctx.lr = 0x823E3BF0;
	sub_823E6740(ctx, base);
	// cmpdi cr6,r3,-1
	cr6.compare<int64_t>(ctx.r3.s64, -1, xer);
	// beq cr6,0x823e3aa8
	if (cr6.eq) goto loc_823E3AA8;
loc_823E3BF8:
	// lwz r11,148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// b 0x823e3c20
	goto loc_823E3C20;
loc_823E3C08:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r30,1
	r30.s64 = 1;
	// bl 0x823e6b28
	ctx.lr = 0x823E3C1C;
	sub_823E6B28(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_823E3C20:
	// cmpw cr6,r28,r30
	cr6.compare<int32_t>(r28.s32, r30.s32, xer);
	// bne cr6,0x823e3aa8
	if (!cr6.eq) goto loc_823E3AA8;
	// lwz r11,148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
loc_823E3C30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823E3C38"))) PPC_WEAK_FUNC(sub_823E3C38);
PPC_FUNC_IMPL(__imp__sub_823E3C38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	// stfd f2,24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f2.u64);
	// lwz r11,24(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stfd f1,16(r1)
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lwz r9,16(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	// lwz r8,20(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// lfd f0,-17600(r10)
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + -17600);
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// stw r8,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r8.u32);
	// rlwimi r11,r9,0,1,31
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0x7FFFFFFF) | (r11.u64 & 0xFFFFFFFF80000000);
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r11.u32);
	// lfd f1,-16(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

