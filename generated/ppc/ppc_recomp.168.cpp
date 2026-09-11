#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_827A7B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7B34) {
	__imp__sub_827A7B34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f8
	ctx.lr = 0x827A7B40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214a0a0
	ctx.lr = 0x827A7B54;
	sub_8214A0A0(ctx, base);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x821433e8
	ctx.lr = 0x827A7B5C;
	sub_821433E8(ctx, base);
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// bl 0x8214cea0
	ctx.lr = 0x827A7B64;
	sub_8214CEA0(ctx, base);
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// bl 0x8215fec8
	ctx.lr = 0x827A7B6C;
	sub_8215FEC8(ctx, base);
	// addi r3,r31,700
	ctx.r3.s64 = r31.s64 + 700;
	// bl 0x8214dee8
	ctx.lr = 0x827A7B74;
	sub_8214DEE8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f12,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r11,14124
	ctx.r9.s64 = r11.s64 + 14124;
	// addi r8,r10,14164
	ctx.r8.s64 = ctx.r10.s64 + 14164;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r9,1260(r31)
	PPC_STORE_U32(r31.u32 + 1260, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,1300(r31)
	PPC_STORE_U32(r31.u32 + 1300, r11.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r10,1304(r31)
	PPC_STORE_U32(r31.u32 + 1304, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r29,848
	r29.s64 = 848;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,14188(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14188);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f12,14184(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14184);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stw r8,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, ctx.r8.u32);
	// li r28,832
	r28.s64 = 832;
	// stb r9,1308(r31)
	PPC_STORE_U8(r31.u32 + 1308, ctx.r9.u8);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,14100
	ctx.r7.s64 = ctx.r7.s64 + 14100;
	// addi r6,r6,14144
	ctx.r6.s64 = ctx.r6.s64 + 14144;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r5,14084
	ctx.r5.s64 = ctx.r5.s64 + 14084;
	// stvx128 v63,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r4,14064
	ctx.r4.s64 = ctx.r4.s64 + 14064;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,255
	r11.s64 = 255;
	// stfs f13,1248(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1248, temp.u32);
	// li r10,96
	ctx.r10.s64 = 96;
	// stfs f0,1252(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1252, temp.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// stfs f12,1256(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1256, temp.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r7,1268(r31)
	PPC_STORE_U32(r31.u32 + 1268, ctx.r7.u32);
	// stw r6,1272(r31)
	PPC_STORE_U32(r31.u32 + 1272, ctx.r6.u32);
	// stvx128 v63,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,1276(r31)
	PPC_STORE_U32(r31.u32 + 1276, ctx.r5.u32);
	// addi r3,r31,1344
	ctx.r3.s64 = r31.s64 + 1344;
	// stw r4,1280(r31)
	PPC_STORE_U32(r31.u32 + 1280, ctx.r4.u32);
	// stw r11,1284(r31)
	PPC_STORE_U32(r31.u32 + 1284, r11.u32);
	// stw r10,1292(r31)
	PPC_STORE_U32(r31.u32 + 1292, ctx.r10.u32);
	// stw r9,1288(r31)
	PPC_STORE_U32(r31.u32 + 1288, ctx.r9.u32);
	// stw r8,1296(r31)
	PPC_STORE_U32(r31.u32 + 1296, ctx.r8.u32);
	// bl 0x8215f8d0
	ctx.lr = 0x827A7C68;
	sub_8215F8D0(ctx, base);
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r3,r9,-30760
	ctx.r3.s64 = ctx.r9.s64 + -30760;
	// bl 0x823d9a98
	ctx.lr = 0x827A7C74;
	sub_823D9A98(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_827A7B38) {
	__imp__sub_827A7B38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7C7C) {
	__imp__sub_827A7C7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,14252
	ctx.r5.s64 = r11.s64 + 14252;
	// addi r3,r10,19816
	ctx.r3.s64 = ctx.r10.s64 + 19816;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7C80) {
	__imp__sub_827A7C80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7C9C) {
	__imp__sub_827A7C9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,14260
	ctx.r5.s64 = r11.s64 + 14260;
	// addi r3,r10,19796
	ctx.r3.s64 = ctx.r10.s64 + 19796;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7CA0) {
	__imp__sub_827A7CA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7CBC) {
	__imp__sub_827A7CBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7CC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,14268
	ctx.r5.s64 = r11.s64 + 14268;
	// addi r3,r10,19836
	ctx.r3.s64 = ctx.r10.s64 + 19836;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7CC0) {
	__imp__sub_827A7CC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7CDC) {
	__imp__sub_827A7CDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7CE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,14284
	ctx.r5.s64 = r11.s64 + 14284;
	// addi r3,r10,26592
	ctx.r3.s64 = ctx.r10.s64 + 26592;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7CE0) {
	__imp__sub_827A7CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7CFC) {
	__imp__sub_827A7CFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,26624
	ctx.r3.s64 = r11.s64 + 26624;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821ce460
	sub_821CE460(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7D00) {
	__imp__sub_827A7D00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7D14) {
	__imp__sub_827A7D14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,17036
	ctx.r5.s64 = r11.s64 + 17036;
	// addi r3,r10,26664
	ctx.r3.s64 = ctx.r10.s64 + 26664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7D18) {
	__imp__sub_827A7D18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7D34) {
	__imp__sub_827A7D34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,17860
	ctx.r5.s64 = r11.s64 + 17860;
	// addi r3,r10,26696
	ctx.r3.s64 = ctx.r10.s64 + 26696;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7D38) {
	__imp__sub_827A7D38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7D54) {
	__imp__sub_827A7D54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,28736
	ctx.r5.s64 = r11.s64 + 28736;
	// addi r3,r10,27088
	ctx.r3.s64 = ctx.r10.s64 + 27088;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7D58) {
	__imp__sub_827A7D58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7D74) {
	__imp__sub_827A7D74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r5,r11,28752
	ctx.r5.s64 = r11.s64 + 28752;
	// addi r3,r10,27108
	ctx.r3.s64 = ctx.r10.s64 + 27108;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7D78) {
	__imp__sub_827A7D78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7D94) {
	__imp__sub_827A7D94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7D98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r4,r11,-32172
	ctx.r4.s64 = r11.s64 + -32172;
	// addi r3,r10,-31096
	ctx.r3.s64 = ctx.r10.s64 + -31096;
	// b 0x821ce1d0
	sub_821CE1D0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7D98) {
	__imp__sub_827A7D98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7DAC) {
	__imp__sub_827A7DAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7DB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-31060
	ctx.r5.s64 = r11.s64 + -31060;
	// addi r3,r10,-30920
	ctx.r3.s64 = ctx.r10.s64 + -30920;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7DB0) {
	__imp__sub_827A7DB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7DCC) {
	__imp__sub_827A7DCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7DD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28840
	ctx.r5.s64 = r11.s64 + -28840;
	// addi r3,r10,-28248
	ctx.r3.s64 = ctx.r10.s64 + -28248;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7DD0) {
	__imp__sub_827A7DD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7DEC) {
	__imp__sub_827A7DEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7DF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28828
	ctx.r5.s64 = r11.s64 + -28828;
	// addi r3,r10,-28308
	ctx.r3.s64 = ctx.r10.s64 + -28308;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7DF0) {
	__imp__sub_827A7DF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7E0C) {
	__imp__sub_827A7E0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28816
	ctx.r5.s64 = r11.s64 + -28816;
	// addi r3,r10,-28388
	ctx.r3.s64 = ctx.r10.s64 + -28388;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7E10) {
	__imp__sub_827A7E10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7E2C) {
	__imp__sub_827A7E2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28812
	ctx.r5.s64 = r11.s64 + -28812;
	// addi r3,r10,-28468
	ctx.r3.s64 = ctx.r10.s64 + -28468;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7E30) {
	__imp__sub_827A7E30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7E4C) {
	__imp__sub_827A7E4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28800
	ctx.r5.s64 = r11.s64 + -28800;
	// addi r3,r10,-28348
	ctx.r3.s64 = ctx.r10.s64 + -28348;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7E50) {
	__imp__sub_827A7E50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7E6C) {
	__imp__sub_827A7E6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28792
	ctx.r5.s64 = r11.s64 + -28792;
	// addi r3,r10,-28408
	ctx.r3.s64 = ctx.r10.s64 + -28408;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7E70) {
	__imp__sub_827A7E70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7E8C) {
	__imp__sub_827A7E8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7E90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28784
	ctx.r5.s64 = r11.s64 + -28784;
	// addi r3,r10,-28368
	ctx.r3.s64 = ctx.r10.s64 + -28368;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7E90) {
	__imp__sub_827A7E90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7EAC) {
	__imp__sub_827A7EAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7EB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28772
	ctx.r5.s64 = r11.s64 + -28772;
	// addi r3,r10,-28268
	ctx.r3.s64 = ctx.r10.s64 + -28268;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7EB0) {
	__imp__sub_827A7EB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7ECC) {
	__imp__sub_827A7ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7ED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28760
	ctx.r5.s64 = r11.s64 + -28760;
	// addi r3,r10,-28448
	ctx.r3.s64 = ctx.r10.s64 + -28448;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7ED0) {
	__imp__sub_827A7ED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7EEC) {
	__imp__sub_827A7EEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7EF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28744
	ctx.r5.s64 = r11.s64 + -28744;
	// addi r3,r10,-28288
	ctx.r3.s64 = ctx.r10.s64 + -28288;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7EF0) {
	__imp__sub_827A7EF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7F0C) {
	__imp__sub_827A7F0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28728
	ctx.r5.s64 = r11.s64 + -28728;
	// addi r3,r10,-28328
	ctx.r3.s64 = ctx.r10.s64 + -28328;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7F10) {
	__imp__sub_827A7F10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7F2C) {
	__imp__sub_827A7F2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28712
	ctx.r5.s64 = r11.s64 + -28712;
	// addi r3,r10,-28488
	ctx.r3.s64 = ctx.r10.s64 + -28488;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7F30) {
	__imp__sub_827A7F30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7F4C) {
	__imp__sub_827A7F4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28696
	ctx.r5.s64 = r11.s64 + -28696;
	// addi r3,r10,-28508
	ctx.r3.s64 = ctx.r10.s64 + -28508;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7F50) {
	__imp__sub_827A7F50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7F6C) {
	__imp__sub_827A7F6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28684
	ctx.r5.s64 = r11.s64 + -28684;
	// addi r3,r10,-28528
	ctx.r3.s64 = ctx.r10.s64 + -28528;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7F70) {
	__imp__sub_827A7F70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7F8C) {
	__imp__sub_827A7F8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7F90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-28672
	ctx.r5.s64 = r11.s64 + -28672;
	// addi r3,r10,-28428
	ctx.r3.s64 = ctx.r10.s64 + -28428;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7F90) {
	__imp__sub_827A7F90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7FAC) {
	__imp__sub_827A7FAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r5,r11,11728
	ctx.r5.s64 = r11.s64 + 11728;
	// addi r4,r10,-27692
	ctx.r4.s64 = ctx.r10.s64 + -27692;
	// addi r3,r9,-27208
	ctx.r3.s64 = ctx.r9.s64 + -27208;
	// li r6,5258
	ctx.r6.s64 = 5258;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7FB0) {
	__imp__sub_827A7FB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7FD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27668
	ctx.r5.s64 = r11.s64 + -27668;
	// addi r3,r10,-27152
	ctx.r3.s64 = ctx.r10.s64 + -27152;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7FD0) {
	__imp__sub_827A7FD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A7FEC) {
	__imp__sub_827A7FEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A7FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27664
	ctx.r5.s64 = r11.s64 + -27664;
	// addi r3,r10,-27172
	ctx.r3.s64 = ctx.r10.s64 + -27172;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A7FF0) {
	__imp__sub_827A7FF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A800C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A800C) {
	__imp__sub_827A800C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27648
	ctx.r5.s64 = r11.s64 + -27648;
	// addi r3,r10,-27316
	ctx.r3.s64 = ctx.r10.s64 + -27316;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8010) {
	__imp__sub_827A8010(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A802C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A802C) {
	__imp__sub_827A802C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27644
	ctx.r5.s64 = r11.s64 + -27644;
	// addi r3,r10,-27576
	ctx.r3.s64 = ctx.r10.s64 + -27576;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8030) {
	__imp__sub_827A8030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A804C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A804C) {
	__imp__sub_827A804C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27628
	ctx.r5.s64 = r11.s64 + -27628;
	// addi r3,r10,-27376
	ctx.r3.s64 = ctx.r10.s64 + -27376;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8050) {
	__imp__sub_827A8050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A806C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A806C) {
	__imp__sub_827A806C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27612
	ctx.r5.s64 = r11.s64 + -27612;
	// addi r3,r10,-27336
	ctx.r3.s64 = ctx.r10.s64 + -27336;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8070) {
	__imp__sub_827A8070(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A808C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A808C) {
	__imp__sub_827A808C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27604
	ctx.r5.s64 = r11.s64 + -27604;
	// addi r3,r10,-27616
	ctx.r3.s64 = ctx.r10.s64 + -27616;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8090) {
	__imp__sub_827A8090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A80AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A80AC) {
	__imp__sub_827A80AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A80B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27592
	ctx.r5.s64 = r11.s64 + -27592;
	// addi r3,r10,-27456
	ctx.r3.s64 = ctx.r10.s64 + -27456;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A80B0) {
	__imp__sub_827A80B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A80CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A80CC) {
	__imp__sub_827A80CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A80D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27576
	ctx.r5.s64 = r11.s64 + -27576;
	// addi r3,r10,-27396
	ctx.r3.s64 = ctx.r10.s64 + -27396;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A80D0) {
	__imp__sub_827A80D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A80EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A80EC) {
	__imp__sub_827A80EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A80F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27560
	ctx.r5.s64 = r11.s64 + -27560;
	// addi r3,r10,-27436
	ctx.r3.s64 = ctx.r10.s64 + -27436;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A80F0) {
	__imp__sub_827A80F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A810C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A810C) {
	__imp__sub_827A810C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27548
	ctx.r5.s64 = r11.s64 + -27548;
	// addi r3,r10,-27192
	ctx.r3.s64 = ctx.r10.s64 + -27192;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8110) {
	__imp__sub_827A8110(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A812C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A812C) {
	__imp__sub_827A812C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8130) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27544
	ctx.r5.s64 = r11.s64 + -27544;
	// addi r3,r10,-27596
	ctx.r3.s64 = ctx.r10.s64 + -27596;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8130) {
	__imp__sub_827A8130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A814C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A814C) {
	__imp__sub_827A814C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27536
	ctx.r5.s64 = r11.s64 + -27536;
	// addi r3,r10,-27416
	ctx.r3.s64 = ctx.r10.s64 + -27416;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8150) {
	__imp__sub_827A8150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A816C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A816C) {
	__imp__sub_827A816C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-27528
	ctx.r5.s64 = r11.s64 + -27528;
	// addi r3,r10,-27356
	ctx.r3.s64 = ctx.r10.s64 + -27356;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8170) {
	__imp__sub_827A8170(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A818C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A818C) {
	__imp__sub_827A818C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8190) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-27296
	ctx.r3.s64 = r11.s64 + -27296;
	// bl 0x8218c110
	ctx.lr = 0x827A81A8;
	sub_8218C110(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30656
	ctx.r3.s64 = ctx.r10.s64 + -30656;
	// bl 0x823d9a98
	ctx.lr = 0x827A81B4;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8190) {
	__imp__sub_827A8190(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A81C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A81C4) {
	__imp__sub_827A81C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A81C8) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r11,-25584
	ctx.r3.s64 = r11.s64 + -25584;
	// bl 0x8218f308
	ctx.lr = 0x827A81E4;
	sub_8218F308(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30640
	ctx.r3.s64 = ctx.r10.s64 + -30640;
	// bl 0x823d9a98
	ctx.lr = 0x827A81F0;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A81C8) {
	__imp__sub_827A81C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r5,r11,17496
	ctx.r5.s64 = r11.s64 + 17496;
	// addi r4,r10,-24468
	ctx.r4.s64 = ctx.r10.s64 + -24468;
	// addi r3,r9,-25220
	ctx.r3.s64 = ctx.r9.s64 + -25220;
	// li r6,5406
	ctx.r6.s64 = 5406;
	// b 0x821d22e8
	sub_821D22E8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8200) {
	__imp__sub_827A8200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8220) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-24436
	ctx.r5.s64 = r11.s64 + -24436;
	// addi r3,r10,-25064
	ctx.r3.s64 = ctx.r10.s64 + -25064;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8220) {
	__imp__sub_827A8220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A823C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A823C) {
	__imp__sub_827A823C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8240) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r31,r11,-25200
	r31.s64 = r11.s64 + -25200;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x8218c110
	ctx.lr = 0x827A8260;
	sub_8218C110(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// stb r11,112(r31)
	PPC_STORE_U8(r31.u32 + 112, r11.u8);
	// addi r3,r10,-30632
	ctx.r3.s64 = ctx.r10.s64 + -30632;
	// bl 0x823d9a98
	ctx.lr = 0x827A8274;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827A8240) {
	__imp__sub_827A8240(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8288) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// addi r5,r10,-25032
	ctx.r5.s64 = ctx.r10.s64 + -25032;
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
	// stw r11,24(r5)
	PPC_STORE_U32(ctx.r5.u32 + 24, r11.u32);
	// lis r4,-32132
	ctx.r4.s64 = -2105802752;
	// stw r10,20(r5)
	PPC_STORE_U32(ctx.r5.u32 + 20, ctx.r10.u32);
	// stw r9,16(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16, ctx.r9.u32);
	// stw r8,52(r5)
	PPC_STORE_U32(ctx.r5.u32 + 52, ctx.r8.u32);
	// addi r3,r4,-30568
	ctx.r3.s64 = ctx.r4.s64 + -30568;
	// stw r7,48(r5)
	PPC_STORE_U32(ctx.r5.u32 + 48, ctx.r7.u32);
	// stw r6,44(r5)
	PPC_STORE_U32(ctx.r5.u32 + 44, ctx.r6.u32);
	// stw r11,80(r5)
	PPC_STORE_U32(ctx.r5.u32 + 80, r11.u32);
	// stw r10,76(r5)
	PPC_STORE_U32(ctx.r5.u32 + 76, ctx.r10.u32);
	// stw r9,72(r5)
	PPC_STORE_U32(ctx.r5.u32 + 72, ctx.r9.u32);
	// stw r8,108(r5)
	PPC_STORE_U32(ctx.r5.u32 + 108, ctx.r8.u32);
	// stw r7,104(r5)
	PPC_STORE_U32(ctx.r5.u32 + 104, ctx.r7.u32);
	// stw r6,100(r5)
	PPC_STORE_U32(ctx.r5.u32 + 100, ctx.r6.u32);
	// stw r11,136(r5)
	PPC_STORE_U32(ctx.r5.u32 + 136, r11.u32);
	// stw r10,132(r5)
	PPC_STORE_U32(ctx.r5.u32 + 132, ctx.r10.u32);
	// stw r9,128(r5)
	PPC_STORE_U32(ctx.r5.u32 + 128, ctx.r9.u32);
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8288) {
	__imp__sub_827A8288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A82F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30560
	ctx.r3.s64 = r11.s64 + -30560;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A82F0) {
	__imp__sub_827A82F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A82FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A82FC) {
	__imp__sub_827A82FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8300) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30528
	ctx.r3.s64 = r11.s64 + -30528;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8300) {
	__imp__sub_827A8300(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A830C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A830C) {
	__imp__sub_827A830C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30496
	ctx.r3.s64 = r11.s64 + -30496;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8310) {
	__imp__sub_827A8310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A831C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A831C) {
	__imp__sub_827A831C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30480
	ctx.r3.s64 = r11.s64 + -30480;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8320) {
	__imp__sub_827A8320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A832C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A832C) {
	__imp__sub_827A832C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-21520
	ctx.r5.s64 = r11.s64 + -21520;
	// addi r3,r10,-24800
	ctx.r3.s64 = ctx.r10.s64 + -24800;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8330) {
	__imp__sub_827A8330(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A834C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A834C) {
	__imp__sub_827A834C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8350) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-24760
	ctx.r3.s64 = r11.s64 + -24760;
	// bl 0x82187008
	ctx.lr = 0x827A8368;
	sub_82187008(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30464
	ctx.r3.s64 = ctx.r10.s64 + -30464;
	// bl 0x823d9a98
	ctx.lr = 0x827A8374;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8350) {
	__imp__sub_827A8350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8384) {
	__imp__sub_827A8384(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30456
	ctx.r3.s64 = r11.s64 + -30456;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8388) {
	__imp__sub_827A8388(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8394) {
	__imp__sub_827A8394(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8398) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-19512
	ctx.r5.s64 = r11.s64 + -19512;
	// addi r3,r10,-23180
	ctx.r3.s64 = ctx.r10.s64 + -23180;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8398) {
	__imp__sub_827A8398(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A83B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A83B4) {
	__imp__sub_827A83B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A83B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30440
	ctx.r3.s64 = r11.s64 + -30440;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A83B8) {
	__imp__sub_827A83B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A83C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A83C4) {
	__imp__sub_827A83C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A83C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30432
	ctx.r3.s64 = r11.s64 + -30432;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A83C8) {
	__imp__sub_827A83C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A83D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A83D4) {
	__imp__sub_827A83D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A83D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r7,r11,-17992
	ctx.r7.s64 = r11.s64 + -17992;
	// li r8,95
	ctx.r8.s64 = 95;
	// addi r11,r7,8
	r11.s64 = ctx.r7.s64 + 8;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_827A83F4:
	// stw r9,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r9.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// sth r10,20(r11)
	PPC_STORE_U16(r11.u32 + 20, ctx.r10.u16);
	// sth r10,22(r11)
	PPC_STORE_U16(r11.u32 + 22, ctx.r10.u16);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bge 0x827a83f4
	if (!cr0.lt) goto loc_827A83F4;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// stw r9,3072(r7)
	PPC_STORE_U32(ctx.r7.u32 + 3072, ctx.r9.u32);
	// addi r3,r11,-30408
	ctx.r3.s64 = r11.s64 + -30408;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A83D8) {
	__imp__sub_827A83D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8428) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-14916
	ctx.r3.s64 = r11.s64 + -14916;
	// bl 0x821c8ed8
	ctx.lr = 0x827A8440;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30424
	ctx.r3.s64 = ctx.r10.s64 + -30424;
	// bl 0x823d9a98
	ctx.lr = 0x827A844C;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8428) {
	__imp__sub_827A8428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A845C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A845C) {
	__imp__sub_827A845C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,-15568
	ctx.r5.s64 = r11.s64 + -15568;
	// addi r3,r10,-13392
	ctx.r3.s64 = ctx.r10.s64 + -13392;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8460) {
	__imp__sub_827A8460(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A847C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A847C) {
	__imp__sub_827A847C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8480) {
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
	// lis r11,-32176
	r11.s64 = -2108686336;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,15128
	ctx.r5.s64 = r11.s64 + 15128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A84A8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,25336
	r11.s64 = ctx.r7.s64 + 25336;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8480) {
	__imp__sub_827A8480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A84F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A84F4) {
	__imp__sub_827A84F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A84F8) {
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
	// lis r11,-32184
	r11.s64 = -2109210624;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-17552
	ctx.r5.s64 = r11.s64 + -17552;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A8520;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,25384
	r11.s64 = ctx.r7.s64 + 25384;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A84F8) {
	__imp__sub_827A84F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A856C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A856C) {
	__imp__sub_827A856C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8570) {
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
	// lis r11,-32184
	r11.s64 = -2109210624;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-17552
	ctx.r5.s64 = r11.s64 + -17552;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A8598;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,25432
	r11.s64 = ctx.r7.s64 + 25432;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8570) {
	__imp__sub_827A8570(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A85E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A85E4) {
	__imp__sub_827A85E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A85E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,25480
	ctx.r10.s64 = r11.s64 + 25480;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
loc_827A85F8:
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// blt cr6,0x827a85f8
	if (cr6.lt) goto loc_827A85F8;
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// addi r3,r9,-30296
	ctx.r3.s64 = ctx.r9.s64 + -30296;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A85E8) {
	__imp__sub_827A85E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8624) {
	__imp__sub_827A8624(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8628) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,25648
	ctx.r10.s64 = r11.s64 + 25648;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
loc_827A8638:
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// blt cr6,0x827a8638
	if (cr6.lt) goto loc_827A8638;
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// addi r3,r9,-30280
	ctx.r3.s64 = ctx.r9.s64 + -30280;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8628) {
	__imp__sub_827A8628(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8664) {
	__imp__sub_827A8664(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8668) {
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
	// lis r11,-32184
	r11.s64 = -2109210624;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-17552
	ctx.r5.s64 = r11.s64 + -17552;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A8690;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,27680
	r11.s64 = ctx.r7.s64 + 27680;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8668) {
	__imp__sub_827A8668(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A86DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A86DC) {
	__imp__sub_827A86DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A86E0) {
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
	// lis r11,-32229
	r11.s64 = -2112159744;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-19592
	ctx.r5.s64 = r11.s64 + -19592;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A8708;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,27728
	r11.s64 = ctx.r7.s64 + 27728;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A86E0) {
	__imp__sub_827A86E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8754) {
	__imp__sub_827A8754(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8758) {
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
	// lis r11,-32229
	r11.s64 = -2112159744;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-13408
	ctx.r5.s64 = r11.s64 + -13408;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A8780;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,27996
	r11.s64 = ctx.r7.s64 + 27996;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8758) {
	__imp__sub_827A8758(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A87CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A87CC) {
	__imp__sub_827A87CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A87D0) {
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
	// lis r11,-32229
	r11.s64 = -2112159744;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-13408
	ctx.r5.s64 = r11.s64 + -13408;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A87F8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,28316
	r11.s64 = ctx.r7.s64 + 28316;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A87D0) {
	__imp__sub_827A87D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8844) {
	__imp__sub_827A8844(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8848) {
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
	// lis r11,-32176
	r11.s64 = -2108686336;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,15128
	ctx.r5.s64 = r11.s64 + 15128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A8870;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,28644
	r11.s64 = ctx.r7.s64 + 28644;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8848) {
	__imp__sub_827A8848(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A88BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A88BC) {
	__imp__sub_827A88BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A88C0) {
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
	// lis r11,-32184
	r11.s64 = -2109210624;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-17552
	ctx.r5.s64 = r11.s64 + -17552;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A88E8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,28692
	r11.s64 = ctx.r7.s64 + 28692;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A88C0) {
	__imp__sub_827A88C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8934) {
	__imp__sub_827A8934(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8938) {
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
	// lis r11,-32229
	r11.s64 = -2112159744;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-12168
	ctx.r5.s64 = r11.s64 + -12168;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A8960;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,28836
	r11.s64 = ctx.r7.s64 + 28836;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8938) {
	__imp__sub_827A8938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A89AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A89AC) {
	__imp__sub_827A89AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A89B0) {
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
	// lis r11,-32228
	r11.s64 = -2112094208;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-18336
	ctx.r5.s64 = r11.s64 + -18336;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827A89D8;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r11,r7,29740
	r11.s64 = ctx.r7.s64 + 29740;
	// lwz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// stw r3,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r3.u32);
	// stw r4,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A89B0) {
	__imp__sub_827A89B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8A24) {
	__imp__sub_827A8A24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8A28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r7,r8,29788
	ctx.r7.s64 = ctx.r8.s64 + 29788;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8A28) {
	__imp__sub_827A8A28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8A48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r7,r8,29796
	ctx.r7.s64 = ctx.r8.s64 + 29796;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8A48) {
	__imp__sub_827A8A48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8A68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// addi r7,r8,29804
	ctx.r7.s64 = ctx.r8.s64 + 29804;
	// lwz r11,22972(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22972);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// stw r10,22972(r9)
	PPC_STORE_U32(ctx.r9.u32 + 22972, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8A68) {
	__imp__sub_827A8A68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8A88) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-11804
	ctx.r3.s64 = r11.s64 + -11804;
	// bl 0x821c8ed8
	ctx.lr = 0x827A8AA0;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30264
	ctx.r3.s64 = ctx.r10.s64 + -30264;
	// bl 0x823d9a98
	ctx.lr = 0x827A8AAC;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8A88) {
	__imp__sub_827A8A88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8ABC) {
	__imp__sub_827A8ABC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r5,r11,4224
	ctx.r5.s64 = r11.s64 + 4224;
	// addi r3,r10,-11772
	ctx.r3.s64 = ctx.r10.s64 + -11772;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8AC0) {
	__imp__sub_827A8AC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8ADC) {
	__imp__sub_827A8ADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,4236
	ctx.r5.s64 = r11.s64 + 4236;
	// addi r3,r10,-27392
	ctx.r3.s64 = ctx.r10.s64 + -27392;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8AE0) {
	__imp__sub_827A8AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8AFC) {
	__imp__sub_827A8AFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8B00) {
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
	ctx.lr = 0x827A8B08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32123
	r11.s64 = -2105212928;
	// li r30,1
	r30.s64 = 1;
	// addi r11,r11,-27368
	r11.s64 = r11.s64 + -27368;
	// li r29,0
	r29.s64 = 0;
	// addi r31,r11,24940
	r31.s64 = r11.s64 + 24940;
loc_827A8B20:
	// addi r3,r31,-44
	ctx.r3.s64 = r31.s64 + -44;
	// bl 0x821c8ed8
	ctx.lr = 0x827A8B28;
	sub_821C8ED8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x827A8B30;
	sub_821C9060(ctx, base);
	// stw r29,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r29.u32);
	// stw r29,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, r29.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r29,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, r29.u32);
	// addi r31,r31,24948
	r31.s64 = r31.s64 + 24948;
	// bge 0x827a8b20
	if (!cr0.lt) goto loc_827A8B20;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30248
	ctx.r3.s64 = r11.s64 + -30248;
	// bl 0x823d9a98
	ctx.lr = 0x827A8B58;
	sub_823D9A98(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827A8B00) {
	__imp__sub_827A8B00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8B60) {
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
	ctx.lr = 0x827A8B68;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r30,1
	r30.s64 = 1;
	// addi r11,r11,-11752
	r11.s64 = r11.s64 + -11752;
	// li r29,0
	r29.s64 = 0;
	// addi r31,r11,24940
	r31.s64 = r11.s64 + 24940;
loc_827A8B80:
	// addi r3,r31,-44
	ctx.r3.s64 = r31.s64 + -44;
	// bl 0x821c8ed8
	ctx.lr = 0x827A8B88;
	sub_821C8ED8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x827A8B90;
	sub_821C9060(ctx, base);
	// stw r29,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r29.u32);
	// stw r29,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, r29.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r29,-12(r31)
	PPC_STORE_U32(r31.u32 + -12, r29.u32);
	// addi r31,r31,24948
	r31.s64 = r31.s64 + 24948;
	// bge 0x827a8b80
	if (!cr0.lt) goto loc_827A8B80;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30152
	ctx.r3.s64 = r11.s64 + -30152;
	// bl 0x823d9a98
	ctx.lr = 0x827A8BB8;
	sub_823D9A98(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_827A8B60) {
	__imp__sub_827A8B60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8BC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,4300
	ctx.r5.s64 = r11.s64 + 4300;
	// addi r3,r10,22872
	ctx.r3.s64 = ctx.r10.s64 + 22872;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8BC0) {
	__imp__sub_827A8BC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8BDC) {
	__imp__sub_827A8BDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8BE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,4316
	ctx.r5.s64 = r11.s64 + 4316;
	// addi r3,r10,22812
	ctx.r3.s64 = ctx.r10.s64 + 22812;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8BE0) {
	__imp__sub_827A8BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8BFC) {
	__imp__sub_827A8BFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,4328
	ctx.r5.s64 = r11.s64 + 4328;
	// addi r3,r10,22852
	ctx.r3.s64 = ctx.r10.s64 + 22852;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8C00) {
	__imp__sub_827A8C00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8C1C) {
	__imp__sub_827A8C1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,4340
	ctx.r5.s64 = r11.s64 + 4340;
	// addi r3,r10,22832
	ctx.r3.s64 = ctx.r10.s64 + 22832;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8C20) {
	__imp__sub_827A8C20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8C3C) {
	__imp__sub_827A8C3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8C40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,4356
	ctx.r5.s64 = r11.s64 + 4356;
	// addi r3,r10,22792
	ctx.r3.s64 = ctx.r10.s64 + 22792;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8C40) {
	__imp__sub_827A8C40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8C5C) {
	__imp__sub_827A8C5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8C60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
loc_827A8C60:
	// mftb r8
	ctx.r8.u64 = __rdtsc();
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827a8c60
	if (cr6.eq) goto loc_827A8C60;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// addi r5,r11,29952
	ctx.r5.s64 = r11.s64 + 29952;
	// lfs f13,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f12,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32132
	ctx.r4.s64 = -2105802752;
	// lfs f0,4400(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4400);
	f0.f64 = double(temp.f32);
	// stfs f13,80(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 80, temp.u32);
	// std r8,64(r5)
	PPC_STORE_U64(ctx.r5.u32 + 64, ctx.r8.u64);
	// stfs f12,84(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 84, temp.u32);
	// stb r11,72(r5)
	PPC_STORE_U8(ctx.r5.u32 + 72, r11.u8);
	// stfs f0,88(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 88, temp.u32);
	// stb r10,73(r5)
	PPC_STORE_U8(ctx.r5.u32 + 73, ctx.r10.u8);
	// stfs f0,92(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 92, temp.u32);
	// stw r9,76(r5)
	PPC_STORE_U32(ctx.r5.u32 + 76, ctx.r9.u32);
	// stfs f0,96(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 96, temp.u32);
	// addi r3,r4,-30056
	ctx.r3.s64 = ctx.r4.s64 + -30056;
	// stfs f0,100(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 100, temp.u32);
	// stfs f0,104(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 104, temp.u32);
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8C60) {
	__imp__sub_827A8C60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8CD4) {
	__imp__sub_827A8CD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8CD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-30016
	ctx.r3.s64 = r11.s64 + -30016;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8CD8) {
	__imp__sub_827A8CD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8CE4) {
	__imp__sub_827A8CE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8CE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,4508
	ctx.r5.s64 = r11.s64 + 4508;
	// addi r3,r10,22916
	ctx.r3.s64 = ctx.r10.s64 + 22916;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8CE8) {
	__imp__sub_827A8CE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8D04) {
	__imp__sub_827A8D04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8D08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,5296
	ctx.r5.s64 = r11.s64 + 5296;
	// addi r3,r10,22976
	ctx.r3.s64 = ctx.r10.s64 + 22976;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8D08) {
	__imp__sub_827A8D08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8D24) {
	__imp__sub_827A8D24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8D28) {
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
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r3,r11,23016
	ctx.r3.s64 = r11.s64 + 23016;
	// bl 0x821c8ed8
	ctx.lr = 0x827A8D40;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-30008
	ctx.r3.s64 = ctx.r10.s64 + -30008;
	// bl 0x823d9a98
	ctx.lr = 0x827A8D4C;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8D28) {
	__imp__sub_827A8D28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8D5C) {
	__imp__sub_827A8D5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8D60) {
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
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r3,r11,23052
	ctx.r3.s64 = r11.s64 + 23052;
	// bl 0x821c8ed8
	ctx.lr = 0x827A8D78;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29992
	ctx.r3.s64 = ctx.r10.s64 + -29992;
	// bl 0x823d9a98
	ctx.lr = 0x827A8D84;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8D60) {
	__imp__sub_827A8D60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8D94) {
	__imp__sub_827A8D94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8D98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,23088
	ctx.r9.s64 = ctx.r10.s64 + 23088;
	// stw r11,23088(r10)
	PPC_STORE_U32(ctx.r10.u32 + 23088, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8D98) {
	__imp__sub_827A8D98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8DBC) {
	__imp__sub_827A8DBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8DC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32123
	r11.s64 = -2105212928;
	// li r5,640
	ctx.r5.s64 = 640;
	// addi r3,r11,23432
	ctx.r3.s64 = r11.s64 + 23432;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9890
	sub_823D9890(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8DC0) {
	__imp__sub_827A8DC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8DD4) {
	__imp__sub_827A8DD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32123
	r11.s64 = -2105212928;
	// li r5,320
	ctx.r5.s64 = 320;
	// addi r3,r11,23112
	ctx.r3.s64 = r11.s64 + 23112;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9890
	sub_823D9890(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8DD8) {
	__imp__sub_827A8DD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8DEC) {
	__imp__sub_827A8DEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8DF0) {
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
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r3,r11,24108
	ctx.r3.s64 = r11.s64 + 24108;
	// bl 0x821c8ed8
	ctx.lr = 0x827A8E08;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29976
	ctx.r3.s64 = ctx.r10.s64 + -29976;
	// bl 0x823d9a98
	ctx.lr = 0x827A8E14;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8DF0) {
	__imp__sub_827A8DF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8E24) {
	__imp__sub_827A8E24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8E28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// addi r5,r11,9220
	ctx.r5.s64 = r11.s64 + 9220;
	// addi r3,r10,24088
	ctx.r3.s64 = ctx.r10.s64 + 24088;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8E28) {
	__imp__sub_827A8E28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8E44) {
	__imp__sub_827A8E44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8E48) {
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
	// lis r11,-32123
	r11.s64 = -2105212928;
	// li r31,255
	r31.s64 = 255;
	// addi r11,r11,24224
	r11.s64 = r11.s64 + 24224;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
loc_827A8E6C:
	// li r5,148
	ctx.r5.s64 = 148;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x827A8E7C;
	sub_823D9890(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,160
	r30.s64 = r30.s64 + 160;
	// bge 0x827a8e6c
	if (!cr0.lt) goto loc_827A8E6C;
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29960
	ctx.r3.s64 = r11.s64 + -29960;
	// bl 0x823d9a98
	ctx.lr = 0x827A8E94;
	sub_823D9A98(ctx, base);
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

PPC_WEAK_FUNC(sub_827A8E48) {
	__imp__sub_827A8E48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8EAC) {
	__imp__sub_827A8EAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8EB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29952
	ctx.r3.s64 = r11.s64 + -29952;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8EB0) {
	__imp__sub_827A8EB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8EBC) {
	__imp__sub_827A8EBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8EC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29928
	ctx.r3.s64 = r11.s64 + -29928;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8EC0) {
	__imp__sub_827A8EC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8ECC) {
	__imp__sub_827A8ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8ED0) {
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
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,1812
	ctx.r3.s64 = r11.s64 + 1812;
	// bl 0x821c8ed8
	ctx.lr = 0x827A8EE8;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29944
	ctx.r3.s64 = ctx.r10.s64 + -29944;
	// bl 0x823d9a98
	ctx.lr = 0x827A8EF4;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8ED0) {
	__imp__sub_827A8ED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8F04) {
	__imp__sub_827A8F04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r5,r11,10504
	ctx.r5.s64 = r11.s64 + 10504;
	// addi r3,r10,1792
	ctx.r3.s64 = ctx.r10.s64 + 1792;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8F08) {
	__imp__sub_827A8F08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8F24) {
	__imp__sub_827A8F24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29920
	ctx.r3.s64 = r11.s64 + -29920;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8F28) {
	__imp__sub_827A8F28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8F34) {
	__imp__sub_827A8F34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29872
	ctx.r3.s64 = r11.s64 + -29872;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8F38) {
	__imp__sub_827A8F38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8F44) {
	__imp__sub_827A8F44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29896
	ctx.r3.s64 = r11.s64 + -29896;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8F48) {
	__imp__sub_827A8F48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8F54) {
	__imp__sub_827A8F54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r5,r11,11684
	ctx.r5.s64 = r11.s64 + 11684;
	// addi r3,r10,2128
	ctx.r3.s64 = ctx.r10.s64 + 2128;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8F58) {
	__imp__sub_827A8F58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8F74) {
	__imp__sub_827A8F74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r5,r11,11704
	ctx.r5.s64 = r11.s64 + 11704;
	// addi r3,r10,2148
	ctx.r3.s64 = ctx.r10.s64 + 2148;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8F78) {
	__imp__sub_827A8F78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8F94) {
	__imp__sub_827A8F94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8F98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_827A8F98:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827a8f98
	if (cr6.eq) goto loc_827A8F98;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// std r11,2168(r10)
	PPC_STORE_U64(ctx.r10.u32 + 2168, r11.u64);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8F98) {
	__imp__sub_827A8F98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8FB4) {
	__imp__sub_827A8FB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8FB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r5,r11,12124
	ctx.r5.s64 = r11.s64 + 12124;
	// addi r3,r10,2208
	ctx.r3.s64 = ctx.r10.s64 + 2208;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821c06c8
	sub_821C06C8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A8FB8) {
	__imp__sub_827A8FB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A8FD4) {
	__imp__sub_827A8FD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A8FD8) {
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
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,2208
	ctx.r3.s64 = ctx.r10.s64 + 2208;
	// bl 0x821c0750
	ctx.lr = 0x827A8FFC;
	sub_821C0750(ctx, base);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,2192
	ctx.r8.s64 = ctx.r9.s64 + 2192;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r11,8(r8)
	PPC_STORE_U8(ctx.r8.u32 + 8, r11.u8);
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 12, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r11,16,16,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// rlwinm r4,r11,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r6,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// xor r11,r3,r11
	r11.u64 = ctx.r3.u64 ^ r11.u64;
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A8FD8) {
	__imp__sub_827A8FD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9050) {
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
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,2208
	ctx.r3.s64 = ctx.r10.s64 + 2208;
	// bl 0x821c0750
	ctx.lr = 0x827A9074;
	sub_821C0750(ctx, base);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,2176
	ctx.r8.s64 = ctx.r9.s64 + 2176;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r11,8(r8)
	PPC_STORE_U8(ctx.r8.u32 + 8, r11.u8);
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 12, temp.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r11,16,16,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// rlwinm r4,r11,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r6,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// xor r11,r3,r11
	r11.u64 = ctx.r3.u64 ^ r11.u64;
	// stw r10,2176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2176, ctx.r10.u32);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9050) {
	__imp__sub_827A9050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A90C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// addi r8,r10,2288
	ctx.r8.s64 = ctx.r10.s64 + 2288;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A90C8) {
	__imp__sub_827A90C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A90E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A90E4) {
	__imp__sub_827A90E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A90E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2512
	ctx.r9.s64 = r11.s64 + 2512;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A90E8) {
	__imp__sub_827A90E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9108) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2560
	ctx.r9.s64 = r11.s64 + 2560;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,2560(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2560, temp.u32);
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9108) {
	__imp__sub_827A9108(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2608
	ctx.r9.s64 = r11.s64 + 2608;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,2608(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2608, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9128) {
	__imp__sub_827A9128(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9148) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2656
	ctx.r9.s64 = r11.s64 + 2656;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,2656(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2656, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9148) {
	__imp__sub_827A9148(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f0,-12788(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,2544(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 2544, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9168) {
	__imp__sub_827A9168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A917C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A917C) {
	__imp__sub_827A917C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9180) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2496
	ctx.r9.s64 = r11.s64 + 2496;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9180) {
	__imp__sub_827A9180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2592
	ctx.r9.s64 = r11.s64 + 2592;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9198) {
	__imp__sub_827A9198(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A91B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2640
	ctx.r9.s64 = r11.s64 + 2640;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A91B0) {
	__imp__sub_827A91B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A91C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2576
	ctx.r9.s64 = r11.s64 + 2576;
	// lfs f0,-12788(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12788);
	f0.f64 = double(temp.f32);
	// stfs f0,2576(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2576, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A91C8) {
	__imp__sub_827A91C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A91EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A91EC) {
	__imp__sub_827A91EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A91F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2528
	ctx.r9.s64 = r11.s64 + 2528;
	// lfs f0,-12780(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12780);
	f0.f64 = double(temp.f32);
	// stfs f0,2528(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2528, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A91F0) {
	__imp__sub_827A91F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A9214) {
	__imp__sub_827A9214(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,2624
	ctx.r9.s64 = r11.s64 + 2624;
	// lfs f0,-12784(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12784);
	f0.f64 = double(temp.f32);
	// stfs f0,2624(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2624, temp.u32);
	// stfs f0,4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f0,8(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// stfs f0,12(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9218) {
	__imp__sub_827A9218(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A923C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A923C) {
	__imp__sub_827A923C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2512
	ctx.r9.s64 = r11.s64 + 2512;
	// addi r8,r10,2416
	ctx.r8.s64 = ctx.r10.s64 + 2416;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9240) {
	__imp__sub_827A9240(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A925C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A925C) {
	__imp__sub_827A925C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9260) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2560
	ctx.r9.s64 = r11.s64 + 2560;
	// addi r8,r10,2320
	ctx.r8.s64 = ctx.r10.s64 + 2320;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9260) {
	__imp__sub_827A9260(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A927C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A927C) {
	__imp__sub_827A927C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2608
	ctx.r9.s64 = r11.s64 + 2608;
	// addi r8,r10,2432
	ctx.r8.s64 = ctx.r10.s64 + 2432;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9280) {
	__imp__sub_827A9280(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A929C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A929C) {
	__imp__sub_827A929C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A92A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2656
	ctx.r9.s64 = r11.s64 + 2656;
	// addi r8,r10,2384
	ctx.r8.s64 = ctx.r10.s64 + 2384;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A92A0) {
	__imp__sub_827A92A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A92BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A92BC) {
	__imp__sub_827A92BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A92C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2544
	ctx.r9.s64 = r11.s64 + 2544;
	// addi r8,r10,2480
	ctx.r8.s64 = ctx.r10.s64 + 2480;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A92C0) {
	__imp__sub_827A92C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A92DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A92DC) {
	__imp__sub_827A92DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A92E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2496
	ctx.r9.s64 = r11.s64 + 2496;
	// addi r8,r10,2400
	ctx.r8.s64 = ctx.r10.s64 + 2400;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A92E0) {
	__imp__sub_827A92E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A92FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A92FC) {
	__imp__sub_827A92FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9300) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2592
	ctx.r9.s64 = r11.s64 + 2592;
	// addi r8,r10,2336
	ctx.r8.s64 = ctx.r10.s64 + 2336;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9300) {
	__imp__sub_827A9300(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A931C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A931C) {
	__imp__sub_827A931C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2640
	ctx.r9.s64 = r11.s64 + 2640;
	// addi r8,r10,2368
	ctx.r8.s64 = ctx.r10.s64 + 2368;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9320) {
	__imp__sub_827A9320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A933C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A933C) {
	__imp__sub_827A933C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9340) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2576
	ctx.r9.s64 = r11.s64 + 2576;
	// addi r8,r10,2464
	ctx.r8.s64 = ctx.r10.s64 + 2464;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9340) {
	__imp__sub_827A9340(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A935C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A935C) {
	__imp__sub_827A935C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9360) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,-31680
	ctx.r9.s64 = r11.s64 + -31680;
	// addi r8,r10,2352
	ctx.r8.s64 = ctx.r10.s64 + 2352;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9360) {
	__imp__sub_827A9360(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A937C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A937C) {
	__imp__sub_827A937C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A9380) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2528
	ctx.r9.s64 = r11.s64 + 2528;
	// addi r8,r10,2448
	ctx.r8.s64 = ctx.r10.s64 + 2448;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A9380) {
	__imp__sub_827A9380(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A939C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A939C) {
	__imp__sub_827A939C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A93A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2624
	ctx.r9.s64 = r11.s64 + 2624;
	// addi r8,r10,2304
	ctx.r8.s64 = ctx.r10.s64 + 2304;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A93A0) {
	__imp__sub_827A93A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A93BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A93BC) {
	__imp__sub_827A93BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A93C0) {
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
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2772
	ctx.r3.s64 = r11.s64 + 2772;
	// bl 0x821c8ed8
	ctx.lr = 0x827A93D8;
	sub_821C8ED8(ctx, base);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// addi r3,r10,-29840
	ctx.r3.s64 = ctx.r10.s64 + -29840;
	// bl 0x823d9a98
	ctx.lr = 0x827A93E4;
	sub_823D9A98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_827A93C0) {
	__imp__sub_827A93C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A93F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_827A93F4) {
	__imp__sub_827A93F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_827A93F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-29824
	ctx.r3.s64 = r11.s64 + -29824;
	// b 0x823d9a98
	sub_823D9A98(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_827A93F8) {
	__imp__sub_827A93F8(ctx, base);
}

