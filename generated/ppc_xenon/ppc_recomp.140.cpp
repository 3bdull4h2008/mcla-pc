#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_826BC988"))) PPC_WEAK_FUNC(sub_826BC988);
PPC_FUNC_IMPL(__imp__sub_826BC988) {
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
	// li r11,0
	r11.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// bl 0x8238ee08
	ctx.lr = 0x826BC9B8;
	sub_8238EE08(ctx, base);
	// stw r30,8256(r31)
	PPC_STORE_U32(r31.u32 + 8256, r30.u32);
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

__attribute__((alias("__imp__sub_826BC9D4"))) PPC_WEAK_FUNC(sub_826BC9D4);
PPC_FUNC_IMPL(__imp__sub_826BC9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BC9D8"))) PPC_WEAK_FUNC(sub_826BC9D8);
PPC_FUNC_IMPL(__imp__sub_826BC9D8) {
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
	// beq cr6,0x826bca28
	if (cr6.eq) goto loc_826BCA28;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r4,r30,4
	ctx.r4.s64 = r30.s64 + 4;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x826BCA0C;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r30,80
	ctx.r4.s64 = r30.s64 + 80;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x8238ee58
	ctx.lr = 0x826BCA20;
	sub_8238EE58(ctx, base);
	// lwz r10,8256(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8256);
	// stw r10,8256(r31)
	PPC_STORE_U32(r31.u32 + 8256, ctx.r10.u32);
loc_826BCA28:
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

__attribute__((alias("__imp__sub_826BCA44"))) PPC_WEAK_FUNC(sub_826BCA44);
PPC_FUNC_IMPL(__imp__sub_826BCA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BCA48"))) PPC_WEAK_FUNC(sub_826BCA48);
PPC_FUNC_IMPL(__imp__sub_826BCA48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,3
	r11.s64 = 196608;
	// ori r11,r11,3392
	r11.u64 = r11.u64 | 3392;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// b 0x8238d3f8
	sub_8238D3F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826BCA58"))) PPC_WEAK_FUNC(sub_826BCA58);
PPC_FUNC_IMPL(__imp__sub_826BCA58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27308
	ctx.r10.s64 = r11.s64 + -27308;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r3,r8,1
	ctx.r3.u64 = ctx.r8.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCA74"))) PPC_WEAK_FUNC(sub_826BCA74);
PPC_FUNC_IMPL(__imp__sub_826BCA74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BCA78"))) PPC_WEAK_FUNC(sub_826BCA78);
PPC_FUNC_IMPL(__imp__sub_826BCA78) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x826BCA98;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bcad8
	if (cr6.eq) goto loc_826BCAD8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r31,664(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// lhz r10,14(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lhz r9,18(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r30,r9
	r30.s64 = ctx.r9.s16;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// bge cr6,0x826bcad8
	if (!cr6.lt) goto loc_826BCAD8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,23868
	ctx.r3.s64 = r11.s64 + 23868;
	// bl 0x821e6800
	ctx.lr = 0x826BCAD0;
	sub_821E6800(ctx, base);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// sth r10,18(r31)
	PPC_STORE_U16(r31.u32 + 18, ctx.r10.u16);
loc_826BCAD8:
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

__attribute__((alias("__imp__sub_826BCAF0"))) PPC_WEAK_FUNC(sub_826BCAF0);
PPC_FUNC_IMPL(__imp__sub_826BCAF0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,8468(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8468);
	f0.f64 = double(temp.f32);
	// lfs f13,8492(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8492);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// blt cr6,0x826bcb0c
	if (cr6.lt) goto loc_826BCB0C;
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_826BCB0C:
	// lfs f13,8484(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8484);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// blt cr6,0x826bcb24
	if (cr6.lt) goto loc_826BCB24;
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_826BCB24:
	// lfs f13,8480(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8480);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// blt cr6,0x826bcb3c
	if (cr6.lt) goto loc_826BCB3C;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_826BCB3C:
	// lfs f13,8476(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8476);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// blt cr6,0x826bcb54
	if (cr6.lt) goto loc_826BCB54;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_826BCB54:
	// lfs f13,8472(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8472);
	ctx.f13.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCB70"))) PPC_WEAK_FUNC(sub_826BCB70);
PPC_FUNC_IMPL(__imp__sub_826BCB70) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bcc2c
	if (cr6.eq) goto loc_826BCC2C;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x826bcbcc
	if (cr6.eq) goto loc_826BCBCC;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826bcbe8
	if (!cr6.gt) goto loc_826BCBE8;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x826bcbdc
	goto loc_826BCBDC;
loc_826BCBCC:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826bcbe8
	if (!cr6.gt) goto loc_826BCBE8;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_826BCBDC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826bcbec
	if (!cr6.eq) goto loc_826BCBEC;
loc_826BCBE8:
	// li r11,0
	r11.s64 = 0;
loc_826BCBEC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bcc2c
	if (cr6.eq) goto loc_826BCC2C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x826BCC00;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8238efe8
	ctx.lr = 0x826BCC10;
	sub_8238EFE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8238efe8
	ctx.lr = 0x826BCC1C;
	sub_8238EFE8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// bl 0x826bcaf0
	ctx.lr = 0x826BCC28;
	sub_826BCAF0(ctx, base);
	// b 0x826bcc3c
	goto loc_826BCC3C;
loc_826BCC2C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-15440
	ctx.r3.s64 = r11.s64 + -15440;
	// bl 0x82130000
	ctx.lr = 0x826BCC38;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BCC3C:
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

__attribute__((alias("__imp__sub_826BCC58"))) PPC_WEAK_FUNC(sub_826BCC58);
PPC_FUNC_IMPL(__imp__sub_826BCC58) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,628
	ctx.r10.s64 = ctx.r3.s64 + 628;
loc_826BCC6C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bccb0
	if (cr6.eq) goto loc_826BCCB0;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x826bccb0
	if (cr6.eq) goto loc_826BCCB0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,200
	ctx.r10.s64 = ctx.r10.s64 + 200;
	// cmpwi cr6,r11,40
	cr6.compare<int32_t>(r11.s32, 40, xer);
	// blt cr6,0x826bcc6c
	if (cr6.lt) goto loc_826BCC6C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-15336
	ctx.r3.s64 = r11.s64 + -15336;
	// bl 0x82130000
	ctx.lr = 0x826BCC9C;
	sub_82130000(ctx, base);
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
loc_826BCCB0:
	// mulli r10,r11,200
	ctx.r10.s64 = r11.s64 * 200;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,1000
	ctx.r8.s64 = r11.s64 + 1000;
	// addi r3,r10,456
	ctx.r3.s64 = ctx.r10.s64 + 456;
	// stw r9,628(r10)
	PPC_STORE_U32(ctx.r10.u32 + 628, ctx.r9.u32);
	// stw r8,620(r10)
	PPC_STORE_U32(ctx.r10.u32 + 620, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCCDC"))) PPC_WEAK_FUNC(sub_826BCCDC);
PPC_FUNC_IMPL(__imp__sub_826BCCDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BCCE0"))) PPC_WEAK_FUNC(sub_826BCCE0);
PPC_FUNC_IMPL(__imp__sub_826BCCE0) {
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
	ctx.lr = 0x826BCCE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r29,460
	r31.s64 = r29.s64 + 460;
loc_826BCCFC:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826bcd20
	if (cr6.eq) goto loc_826BCD20;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dd800
	ctx.lr = 0x826BCD18;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826bcd3c
	if (cr6.eq) goto loc_826BCD3C;
loc_826BCD20:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,200
	r31.s64 = r31.s64 + 200;
	// cmpwi cr6,r30,40
	cr6.compare<int32_t>(r30.s32, 40, xer);
	// blt cr6,0x826bccfc
	if (cr6.lt) goto loc_826BCCFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826BCD3C:
	// mulli r11,r30,200
	r11.s64 = r30.s64 * 200;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r3,r11,456
	ctx.r3.s64 = r11.s64 + 456;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826BCD50"))) PPC_WEAK_FUNC(sub_826BCD50);
PPC_FUNC_IMPL(__imp__sub_826BCD50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,620
	ctx.r10.s64 = ctx.r3.s64 + 620;
loc_826BCD58:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x826bcd7c
	if (cr6.eq) goto loc_826BCD7C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,200
	ctx.r10.s64 = ctx.r10.s64 + 200;
	// cmpwi cr6,r11,40
	cr6.compare<int32_t>(r11.s32, 40, xer);
	// blt cr6,0x826bcd58
	if (cr6.lt) goto loc_826BCD58;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826BCD7C:
	// mulli r11,r11,200
	r11.s64 = r11.s64 * 200;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,456
	ctx.r3.s64 = r11.s64 + 456;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCD8C"))) PPC_WEAK_FUNC(sub_826BCD8C);
PPC_FUNC_IMPL(__imp__sub_826BCD8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BCD90"))) PPC_WEAK_FUNC(sub_826BCD90);
PPC_FUNC_IMPL(__imp__sub_826BCD90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27428
	ctx.r10.s64 = r11.s64 + -27428;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bcdcc
	if (!cr6.eq) goto loc_826BCDCC;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x826bcdcc
	if (cr6.eq) goto loc_826BCDCC;
	// lis r11,1
	r11.s64 = 65536;
	// add r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 + ctx.r3.u64;
	// ori r9,r11,25984
	ctx.r9.u64 = r11.u64 | 25984;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r3,r6,1
	ctx.r3.u64 = ctx.r6.u64 ^ 1;
	// blr 
	return;
loc_826BCDCC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCDD4"))) PPC_WEAK_FUNC(sub_826BCDD4);
PPC_FUNC_IMPL(__imp__sub_826BCDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BCDD8"))) PPC_WEAK_FUNC(sub_826BCDD8);
PPC_FUNC_IMPL(__imp__sub_826BCDD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27468
	ctx.r10.s64 = r11.s64 + -27468;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bcdf4
	if (cr6.eq) goto loc_826BCDF4;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_826BCDF4:
	// mulli r11,r4,38
	r11.s64 = ctx.r4.s64 * 38;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// ori r8,r10,26004
	ctx.r8.u64 = ctx.r10.u64 | 26004;
	// lbzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r3,r5,1
	ctx.r3.u64 = ctx.r5.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCE1C"))) PPC_WEAK_FUNC(sub_826BCE1C);
PPC_FUNC_IMPL(__imp__sub_826BCE1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BCE20"))) PPC_WEAK_FUNC(sub_826BCE20);
PPC_FUNC_IMPL(__imp__sub_826BCE20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,38
	r11.s64 = ctx.r4.s64 * 38;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// ori r8,r10,26346
	ctx.r8.u64 = ctx.r10.u64 | 26346;
	// lbzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r3,r5,1
	ctx.r3.u64 = ctx.r5.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCE48"))) PPC_WEAK_FUNC(sub_826BCE48);
PPC_FUNC_IMPL(__imp__sub_826BCE48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27388
	ctx.r10.s64 = r11.s64 + -27388;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bce64
	if (cr6.eq) goto loc_826BCE64;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_826BCE64:
	// lis r11,1
	r11.s64 = 65536;
	// ori r10,r11,26688
	ctx.r10.u64 = r11.u64 | 26688;
	// lbzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCE80"))) PPC_WEAK_FUNC(sub_826BCE80);
PPC_FUNC_IMPL(__imp__sub_826BCE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,1
	ctx.r10.s64 = 65536;
	// add r11,r4,r3
	r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	// ori r8,r10,25984
	ctx.r8.u64 = ctx.r10.u64 | 25984;
	// li r9,1
	ctx.r9.s64 = 1;
	// stbx r9,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCE98"))) PPC_WEAK_FUNC(sub_826BCE98);
PPC_FUNC_IMPL(__imp__sub_826BCE98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mulli r11,r4,38
	r11.s64 = ctx.r4.s64 * 38;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// ori r8,r10,26004
	ctx.r8.u64 = ctx.r10.u64 | 26004;
	// li r7,1
	ctx.r7.s64 = 1;
	// stbx r7,r9,r8
	PPC_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCEB8"))) PPC_WEAK_FUNC(sub_826BCEB8);
PPC_FUNC_IMPL(__imp__sub_826BCEB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mulli r11,r4,38
	r11.s64 = ctx.r4.s64 * 38;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// ori r8,r10,26346
	ctx.r8.u64 = ctx.r10.u64 | 26346;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// bne cr6,0x826bcee0
	if (!cr6.eq) goto loc_826BCEE0;
	// li r7,0
	ctx.r7.s64 = 0;
loc_826BCEE0:
	// stbx r7,r9,r8
	PPC_STORE_U8(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BCEE8"))) PPC_WEAK_FUNC(sub_826BCEE8);
PPC_FUNC_IMPL(__imp__sub_826BCEE8) {
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
	// bl 0x82387a18
	ctx.lr = 0x826BCF08;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bcf8c
	if (!cr6.eq) goto loc_826BCF8C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826bcf2c
	if (!cr6.eq) goto loc_826BCF2C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-15144
	ctx.r3.s64 = r11.s64 + -15144;
	// bl 0x82130000
	ctx.lr = 0x826BCF28;
	sub_82130000(ctx, base);
	// b 0x826bcf8c
	goto loc_826BCF8C;
loc_826BCF2C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x826BCF38;
	sub_821C9790(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,26692
	r11.s64 = r11.s64 + 26692;
loc_826BCF44:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x826bcf6c
	if (cr6.eq) goto loc_826BCF6C;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826bcf80
	if (cr6.eq) goto loc_826BCF80;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r9,250
	cr6.compare<int32_t>(ctx.r9.s32, 250, xer);
	// blt cr6,0x826bcf44
	if (cr6.lt) goto loc_826BCF44;
	// b 0x826bcf8c
	goto loc_826BCF8C;
loc_826BCF6C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-15240
	ctx.r3.s64 = r11.s64 + -15240;
	// bl 0x82130000
	ctx.lr = 0x826BCF7C;
	sub_82130000(ctx, base);
	// b 0x826bcf8c
	goto loc_826BCF8C;
loc_826BCF80:
	// addi r11,r9,23057
	r11.s64 = ctx.r9.s64 + 23057;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r3.u32);
loc_826BCF8C:
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

__attribute__((alias("__imp__sub_826BCFA4"))) PPC_WEAK_FUNC(sub_826BCFA4);
PPC_FUNC_IMPL(__imp__sub_826BCFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BCFA8"))) PPC_WEAK_FUNC(sub_826BCFA8);
PPC_FUNC_IMPL(__imp__sub_826BCFA8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-4324
	ctx.r5.s64 = r11.s64 + -4324;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,8496
	ctx.r6.s64 = r31.s64 + 8496;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x826BCFE4;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-4332
	ctx.r5.s64 = ctx.r10.s64 + -4332;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,8512
	ctx.r6.s64 = r31.s64 + 8512;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x826BD004;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-4340
	ctx.r5.s64 = ctx.r9.s64 + -4340;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,8528
	ctx.r6.s64 = r31.s64 + 8528;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x826BD024;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-4352
	ctx.r5.s64 = ctx.r7.s64 + -4352;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,8544
	ctx.r6.s64 = r31.s64 + 8544;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826BD044;
	sub_824DF200(ctx, base);
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

__attribute__((alias("__imp__sub_826BD05C"))) PPC_WEAK_FUNC(sub_826BD05C);
PPC_FUNC_IMPL(__imp__sub_826BD05C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BD060"))) PPC_WEAK_FUNC(sub_826BD060);
PPC_FUNC_IMPL(__imp__sub_826BD060) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x826bd0e8
	if (!cr6.lt) goto loc_826BD0E8;
	// lis r10,10922
	ctx.r10.s64 = 715784192;
	// ori r10,r10,43691
	ctx.r10.u64 = ctx.r10.u64 | 43691;
loc_826BD078:
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mulhw r9,r5,r10
	ctx.r9.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32)) >> 32;
	// srawi r9,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
	// mulhw r8,r4,r10
	ctx.r8.s64 = (int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32)) >> 32;
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// srawi r8,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// rlwinm r6,r9,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r7,r9,r6
	ctx.r7.u64 = ctx.r9.u64 + ctx.r6.u64;
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// subf r8,r6,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r6.s64;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r7,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r7.s64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// stwx r9,r4,r3
	PPC_STORE_U32(ctx.r4.u32 + ctx.r3.u32, ctx.r9.u32);
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x826bd078
	if (cr6.lt) goto loc_826BD078;
loc_826BD0E8:
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stw r10,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826bd10c
	if (!cr6.eq) goto loc_826BD10C;
	// li r11,11
	r11.s64 = 11;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// blr 
	return;
loc_826BD10C:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BD118"))) PPC_WEAK_FUNC(sub_826BD118);
PPC_FUNC_IMPL(__imp__sub_826BD118) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-15072
	ctx.r10.s64 = r11.s64 + -15072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826c6010
	ctx.lr = 0x826BD144;
	sub_826C6010(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826bd15c
	if (cr6.eq) goto loc_826BD15C;
	// bl 0x82130588
	ctx.lr = 0x826BD158;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826BD15C:
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

__attribute__((alias("__imp__sub_826BD174"))) PPC_WEAK_FUNC(sub_826BD174);
PPC_FUNC_IMPL(__imp__sub_826BD174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BD178"))) PPC_WEAK_FUNC(sub_826BD178);
PPC_FUNC_IMPL(__imp__sub_826BD178) {
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
	ctx.lr = 0x826BD180;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,11(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd248
	if (cr6.eq) goto loc_826BD248;
	// rlwinm r3,r28,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r31,r28,16
	r31.u64 = r28.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x826BD1A4;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd1c8
	if (cr6.eq) goto loc_826BD1C8;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_826BD1BC:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x826bd1bc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826BD1BC;
loc_826BD1C8:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd238
	if (cr6.eq) goto loc_826BD238;
	// li r8,0
	ctx.r8.s64 = 0;
loc_826BD1DC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r11,r8,r11
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd224
	if (cr6.eq) goto loc_826BD224;
loc_826BD1EC:
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r9,r11,40
	ctx.r9.s64 = r11.s64 + 40;
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// twllei r31,0
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// divwu r4,r5,r31
	ctx.r4.u32 = ctx.r5.u32 / r31.u32;
	// mullw r3,r4,r31
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r31.s32);
	// subf r10,r3,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stwx r6,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r6.u32);
	// bne cr6,0x826bd1ec
	if (!cr6.eq) goto loc_826BD1EC;
loc_826BD224:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x826bd1dc
	if (cr6.lt) goto loc_826BD1DC;
loc_826BD238:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826BD244;
	sub_82130588(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_826BD248:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826BD250"))) PPC_WEAK_FUNC(sub_826BD250);
PPC_FUNC_IMPL(__imp__sub_826BD250) {
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
	ctx.lr = 0x826BD258;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,11(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd320
	if (cr6.eq) goto loc_826BD320;
	// rlwinm r3,r28,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r31,r28,16
	r31.u64 = r28.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x826BD27C;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd2a0
	if (cr6.eq) goto loc_826BD2A0;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_826BD294:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x826bd294
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826BD294;
loc_826BD2A0:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd310
	if (cr6.eq) goto loc_826BD310;
	// li r8,0
	ctx.r8.s64 = 0;
loc_826BD2B4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r11,r8,r11
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd2fc
	if (cr6.eq) goto loc_826BD2FC;
loc_826BD2C4:
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r9,r11,268
	ctx.r9.s64 = r11.s64 + 268;
	// lwz r11,268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// twllei r31,0
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// divwu r4,r5,r31
	ctx.r4.u32 = ctx.r5.u32 / r31.u32;
	// mullw r3,r4,r31
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r31.s32);
	// subf r10,r3,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stwx r6,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r6.u32);
	// bne cr6,0x826bd2c4
	if (!cr6.eq) goto loc_826BD2C4;
loc_826BD2FC:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x826bd2b4
	if (cr6.lt) goto loc_826BD2B4;
loc_826BD310:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826BD31C;
	sub_82130588(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_826BD320:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826BD328"))) PPC_WEAK_FUNC(sub_826BD328);
PPC_FUNC_IMPL(__imp__sub_826BD328) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x826BD330;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826b95b0
	ctx.lr = 0x826BD348;
	sub_826B95B0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826bd708
	if (cr6.eq) goto loc_826BD708;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r27,r11,-14768
	r27.s64 = r11.s64 + -14768;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826c5850
	ctx.lr = 0x826BD364;
	sub_826C5850(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-14784
	ctx.r4.s64 = r11.s64 + -14784;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826bbc30
	ctx.lr = 0x826BD378;
	sub_826BBC30(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r10,-14796
	ctx.r3.s64 = ctx.r10.s64 + -14796;
	// bl 0x826c5850
	ctx.lr = 0x826BD388;
	sub_826C5850(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd3d8
	if (cr6.eq) goto loc_826BD3D8;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826bd3d8
	if (!cr6.eq) goto loc_826BD3D8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bd3d8
	if (cr6.eq) goto loc_826BD3D8;
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826bd3d8
	if (!cr6.eq) goto loc_826BD3D8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826bd3d8
	if (cr6.eq) goto loc_826BD3D8;
	// lbz r11,80(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd3d8
	if (cr6.eq) goto loc_826BD3D8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x826c6fc0
	ctx.lr = 0x826BD3D8;
	sub_826C6FC0(ctx, base);
loc_826BD3D8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r28,r11,-14808
	r28.s64 = r11.s64 + -14808;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826c5850
	ctx.lr = 0x826BD3E8;
	sub_826C5850(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-14824
	ctx.r3.s64 = r11.s64 + -14824;
	// bl 0x826c5850
	ctx.lr = 0x826BD3F8;
	sub_826C5850(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,-14840
	ctx.r4.s64 = ctx.r10.s64 + -14840;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826bbc30
	ctx.lr = 0x826BD40C;
	sub_826BBC30(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd460
	if (cr6.eq) goto loc_826BD460;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826bd460
	if (!cr6.eq) goto loc_826BD460;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826bd460
	if (cr6.eq) goto loc_826BD460;
	// lwz r11,656(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826bd460
	if (!cr6.eq) goto loc_826BD460;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bd460
	if (cr6.eq) goto loc_826BD460;
	// lbz r11,80(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd460
	if (cr6.eq) goto loc_826BD460;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c6fc0
	ctx.lr = 0x826BD460;
	sub_826C6FC0(ctx, base);
loc_826BD460:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826c5850
	ctx.lr = 0x826BD468;
	sub_826C5850(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-14856
	ctx.r4.s64 = r11.s64 + -14856;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826bbc30
	ctx.lr = 0x826BD47C;
	sub_826BBC30(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r10,-14872
	ctx.r3.s64 = ctx.r10.s64 + -14872;
	// bl 0x826c5850
	ctx.lr = 0x826BD48C;
	sub_826C5850(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd4dc
	if (cr6.eq) goto loc_826BD4DC;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826bd4dc
	if (!cr6.eq) goto loc_826BD4DC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bd4dc
	if (cr6.eq) goto loc_826BD4DC;
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826bd4dc
	if (!cr6.eq) goto loc_826BD4DC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826bd4dc
	if (cr6.eq) goto loc_826BD4DC;
	// lbz r11,80(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd4dc
	if (cr6.eq) goto loc_826BD4DC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x826c6fc0
	ctx.lr = 0x826BD4DC;
	sub_826C6FC0(ctx, base);
loc_826BD4DC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826c5850
	ctx.lr = 0x826BD4E4;
	sub_826C5850(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826c5850
	ctx.lr = 0x826BD4F0;
	sub_826C5850(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r11,-14884
	ctx.r3.s64 = r11.s64 + -14884;
	// bl 0x826c5850
	ctx.lr = 0x826BD500;
	sub_826C5850(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-14900
	ctx.r4.s64 = ctx.r10.s64 + -14900;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826bbc30
	ctx.lr = 0x826BD514;
	sub_826BBC30(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd57c
	if (cr6.eq) goto loc_826BD57C;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826bd57c
	if (!cr6.eq) goto loc_826BD57C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c68a0
	ctx.lr = 0x826BD538;
	sub_826C68A0(ctx, base);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x826bd57c
	if (!cr6.eq) goto loc_826BD57C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826bd57c
	if (cr6.eq) goto loc_826BD57C;
	// lwz r11,656(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826bd57c
	if (!cr6.eq) goto loc_826BD57C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826bd57c
	if (cr6.eq) goto loc_826BD57C;
	// lbz r11,80(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd57c
	if (cr6.eq) goto loc_826BD57C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826c6fc0
	ctx.lr = 0x826BD57C;
	sub_826C6FC0(ctx, base);
loc_826BD57C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14908
	ctx.r3.s64 = r11.s64 + -14908;
	// bl 0x826c5850
	ctx.lr = 0x826BD588;
	sub_826C5850(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-14924
	ctx.r4.s64 = ctx.r10.s64 + -14924;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826bbc30
	ctx.lr = 0x826BD59C;
	sub_826BBC30(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd5d8
	if (cr6.eq) goto loc_826BD5D8;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826bd5d8
	if (!cr6.eq) goto loc_826BD5D8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bd5d8
	if (cr6.eq) goto loc_826BD5D8;
	// lbz r11,80(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd5d8
	if (cr6.eq) goto loc_826BD5D8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6fc0
	ctx.lr = 0x826BD5D8;
	sub_826C6FC0(ctx, base);
loc_826BD5D8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r30,r11,-14944
	r30.s64 = r11.s64 + -14944;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c5850
	ctx.lr = 0x826BD5E8;
	sub_826C5850(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-14960
	ctx.r3.s64 = r11.s64 + -14960;
	// bl 0x826c5850
	ctx.lr = 0x826BD5F8;
	sub_826C5850(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-14976
	ctx.r4.s64 = ctx.r10.s64 + -14976;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826bbc30
	ctx.lr = 0x826BD60C;
	sub_826BBC30(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd660
	if (cr6.eq) goto loc_826BD660;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826bd660
	if (!cr6.eq) goto loc_826BD660;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826bd660
	if (cr6.eq) goto loc_826BD660;
	// lwz r11,656(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826bd660
	if (!cr6.eq) goto loc_826BD660;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bd660
	if (cr6.eq) goto loc_826BD660;
	// lbz r11,80(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd660
	if (cr6.eq) goto loc_826BD660;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826c6fc0
	ctx.lr = 0x826BD660;
	sub_826C6FC0(ctx, base);
loc_826BD660:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c5850
	ctx.lr = 0x826BD668;
	sub_826C5850(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-15000
	ctx.r3.s64 = r11.s64 + -15000;
	// bl 0x826c5850
	ctx.lr = 0x826BD678;
	sub_826C5850(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r10,-15012
	ctx.r3.s64 = ctx.r10.s64 + -15012;
	// bl 0x826c5850
	ctx.lr = 0x826BD688;
	sub_826C5850(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r9,-15028
	ctx.r4.s64 = ctx.r9.s64 + -15028;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826bbc30
	ctx.lr = 0x826BD69C;
	sub_826BBC30(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bd708
	if (cr6.eq) goto loc_826BD708;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826bd708
	if (!cr6.eq) goto loc_826BD708;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826bd708
	if (cr6.eq) goto loc_826BD708;
	// lwz r11,656(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x826bd708
	if (!cr6.eq) goto loc_826BD708;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826bd708
	if (cr6.eq) goto loc_826BD708;
	// lwz r11,656(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 656);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826bd708
	if (!cr6.eq) goto loc_826BD708;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bd708
	if (cr6.eq) goto loc_826BD708;
	// lbz r11,80(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd708
	if (cr6.eq) goto loc_826BD708;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826c6fc0
	ctx.lr = 0x826BD708;
	sub_826C6FC0(ctx, base);
loc_826BD708:
	// lis r11,0
	r11.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// ori r22,r11,50208
	r22.u64 = r11.u64 | 50208;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// add r26,r21,r22
	r26.u64 = r21.u64 + r22.u64;
	// mr r24,r23
	r24.u64 = r23.u64;
	// mr r29,r23
	r29.u64 = r23.u64;
	// mr r31,r26
	r31.u64 = r26.u64;
	// li r25,5
	r25.s64 = 5;
	// li r27,-1
	r27.s64 = -1;
	// addi r28,r11,-15068
	r28.s64 = r11.s64 + -15068;
loc_826BD734:
	// addi r30,r31,8109
	r30.s64 = r31.s64 + 8109;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x826BD744;
	sub_821C9790(ctx, base);
	// lwz r11,8104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd780
	if (cr6.eq) goto loc_826BD780;
	// bl 0x82396fb8
	ctx.lr = 0x826BD754;
	sub_82396FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826bd780
	if (!cr6.eq) goto loc_826BD780;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x826BD768;
	sub_82130000(ctx, base);
	// stb r23,-76(r31)
	PPC_STORE_U8(r31.u32 + -76, r23.u8);
	// stw r27,-80(r31)
	PPC_STORE_U32(r31.u32 + -80, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238ee08
	ctx.lr = 0x826BD778;
	sub_8238EE08(ctx, base);
	// li r29,1
	r29.s64 = 1;
	// stw r27,8176(r31)
	PPC_STORE_U32(r31.u32 + 8176, r27.u32);
loc_826BD780:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r31,r31,8272
	r31.s64 = r31.s64 + 8272;
	// bne 0x826bd734
	if (!cr0.eq) goto loc_826BD734;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd864
	if (cr6.eq) goto loc_826BD864;
	// mr r29,r23
	r29.u64 = r23.u64;
	// mr r31,r26
	r31.u64 = r26.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
loc_826BD7A4:
	// lwz r11,8104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd810
	if (cr6.eq) goto loc_826BD810;
	// cmpw cr6,r24,r29
	cr6.compare<int32_t>(r24.s32, r29.s32, xer);
	// beq cr6,0x826bd808
	if (cr6.eq) goto loc_826BD808;
	// addi r11,r30,-80
	r11.s64 = r30.s64 + -80;
	// addi r10,r31,-80
	ctx.r10.s64 = r31.s64 + -80;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x826bd7f4
	if (cr6.eq) goto loc_826BD7F4;
	// addi r4,r31,-76
	ctx.r4.s64 = r31.s64 + -76;
	// addi r3,r30,-76
	ctx.r3.s64 = r30.s64 + -76;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x826BD7D8;
	sub_823DA950(ctx, base);
	// lwz r11,-80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -80);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,-80(r30)
	PPC_STORE_U32(r30.u32 + -80, r11.u32);
	// bl 0x8238ee58
	ctx.lr = 0x826BD7EC;
	sub_8238EE58(ctx, base);
	// lwz r10,8176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8176);
	// stw r10,8176(r30)
	PPC_STORE_U32(r30.u32 + 8176, ctx.r10.u32);
loc_826BD7F4:
	// stb r23,-76(r31)
	PPC_STORE_U8(r31.u32 + -76, r23.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,-80(r31)
	PPC_STORE_U32(r31.u32 + -80, r27.u32);
	// bl 0x8238ee08
	ctx.lr = 0x826BD804;
	sub_8238EE08(ctx, base);
	// stw r27,8176(r31)
	PPC_STORE_U32(r31.u32 + 8176, r27.u32);
loc_826BD808:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r30,r30,8272
	r30.s64 = r30.s64 + 8272;
loc_826BD810:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,8272
	r31.s64 = r31.s64 + 8272;
	// cmpwi cr6,r29,5
	cr6.compare<int32_t>(r29.s32, 5, xer);
	// blt cr6,0x826bd7a4
	if (cr6.lt) goto loc_826BD7A4;
	// cmpwi cr6,r24,5
	cr6.compare<int32_t>(r24.s32, 5, xer);
	// bge cr6,0x826bd864
	if (!cr6.lt) goto loc_826BD864;
	// mulli r11,r24,8272
	r11.s64 = r24.s64 * 8272;
	// add r11,r11,r21
	r11.u64 = r11.u64 + r21.u64;
	// subfic r30,r24,5
	xer.ca = r24.u32 <= 5;
	r30.s64 = 5 - r24.s64;
	// add r31,r11,r22
	r31.u64 = r11.u64 + r22.u64;
loc_826BD838:
	// lwz r11,8104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bd858
	if (cr6.eq) goto loc_826BD858;
	// stb r23,-76(r31)
	PPC_STORE_U8(r31.u32 + -76, r23.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,-80(r31)
	PPC_STORE_U32(r31.u32 + -80, r27.u32);
	// bl 0x8238ee08
	ctx.lr = 0x826BD854;
	sub_8238EE08(ctx, base);
	// stw r27,8176(r31)
	PPC_STORE_U32(r31.u32 + 8176, r27.u32);
loc_826BD858:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8272
	r31.s64 = r31.s64 + 8272;
	// bne 0x826bd838
	if (!cr0.eq) goto loc_826BD838;
loc_826BD864:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_826BD86C"))) PPC_WEAK_FUNC(sub_826BD86C);
PPC_FUNC_IMPL(__imp__sub_826BD86C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BD870"))) PPC_WEAK_FUNC(sub_826BD870);
PPC_FUNC_IMPL(__imp__sub_826BD870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r4,436(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 436);
	// b 0x82727908
	sub_82727908(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826BD890"))) PPC_WEAK_FUNC(sub_826BD890);
PPC_FUNC_IMPL(__imp__sub_826BD890) {
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82387a18
	ctx.lr = 0x826BD8B0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bd8d0
	if (!cr6.eq) goto loc_826BD8D0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c4748
	ctx.lr = 0x826BD8D0;
	sub_826C4748(ctx, base);
loc_826BD8D0:
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

__attribute__((alias("__imp__sub_826BD8E8"))) PPC_WEAK_FUNC(sub_826BD8E8);
PPC_FUNC_IMPL(__imp__sub_826BD8E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,27784
	ctx.r8.u64 = ctx.r9.u64 | 27784;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BD908"))) PPC_WEAK_FUNC(sub_826BD908);
PPC_FUNC_IMPL(__imp__sub_826BD908) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-27308
	ctx.r9.s64 = r11.s64 + -27308;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BD92C"))) PPC_WEAK_FUNC(sub_826BD92C);
PPC_FUNC_IMPL(__imp__sub_826BD92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BD930"))) PPC_WEAK_FUNC(sub_826BD930);
PPC_FUNC_IMPL(__imp__sub_826BD930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,27785
	ctx.r8.u64 = ctx.r9.u64 | 27785;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BD950"))) PPC_WEAK_FUNC(sub_826BD950);
PPC_FUNC_IMPL(__imp__sub_826BD950) {
	PPC_FUNC_PROLOGUE();
	// b 0x826bca78
	sub_826BCA78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826BD954"))) PPC_WEAK_FUNC(sub_826BD954);
PPC_FUNC_IMPL(__imp__sub_826BD954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BD958"))) PPC_WEAK_FUNC(sub_826BD958);
PPC_FUNC_IMPL(__imp__sub_826BD958) {
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
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826BD98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826BD99C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_826BD9B8"))) PPC_WEAK_FUNC(sub_826BD9B8);
PPC_FUNC_IMPL(__imp__sub_826BD9B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,1
	r11.s64 = 65536;
	// li r8,0
	ctx.r8.s64 = 0;
	// ori r10,r11,27756
	ctx.r10.u64 = r11.u64 | 27756;
	// lwzx r5,r3,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826bda28
	if (!cr6.gt) goto loc_826BDA28;
	// addis r7,r3,1
	ctx.r7.s64 = ctx.r3.s64 + 65536;
	// lis r11,10922
	r11.s64 = 715784192;
	// addi r7,r7,27700
	ctx.r7.s64 = ctx.r7.s64 + 27700;
	// ori r9,r11,43691
	ctx.r9.u64 = r11.u64 | 43691;
	// lwz r6,52(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
loc_826BD9E4:
	// add r11,r6,r8
	r11.u64 = ctx.r6.u64 + ctx.r8.u64;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// mulhw r11,r3,r9
	r11.s64 = (int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32)) >> 32;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r3,r7
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x826bda30
	if (cr6.eq) goto loc_826BDA30;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// blt cr6,0x826bd9e4
	if (cr6.lt) goto loc_826BD9E4;
loc_826BDA28:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_826BDA30:
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDA38"))) PPC_WEAK_FUNC(sub_826BDA38);
PPC_FUNC_IMPL(__imp__sub_826BDA38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27368
	ctx.r10.s64 = r11.s64 + -27368;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bdaa0
	if (!cr6.eq) goto loc_826BDAA0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,27784
	ctx.r9.u64 = ctx.r10.u64 | 27784;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826bdaa0
	if (!cr6.eq) goto loc_826BDAA0;
	// addis r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,26692
	ctx.r10.s64 = ctx.r10.s64 + 26692;
loc_826BDA74:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bda98
	if (cr6.eq) goto loc_826BDA98;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x826bdaa0
	if (cr6.eq) goto loc_826BDAA0;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r9,250
	cr6.compare<int32_t>(ctx.r9.s32, 250, xer);
	// blt cr6,0x826bda74
	if (cr6.lt) goto loc_826BDA74;
loc_826BDA98:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826BDAA0:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDAA8"))) PPC_WEAK_FUNC(sub_826BDAA8);
PPC_FUNC_IMPL(__imp__sub_826BDAA8) {
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
	ctx.lr = 0x826BDAB0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826BDAD0;
	sub_8238EC00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826bdb6c
	if (!cr6.gt) goto loc_826BDB6C;
	// li r29,0
	r29.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// li r26,1
	r26.s64 = 1;
loc_826BDAF0:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpw cr6,r10,r27
	cr6.compare<int32_t>(ctx.r10.s32, r27.s32, xer);
	// beq cr6,0x826bdb0c
	if (cr6.eq) goto loc_826BDB0C;
	// cmpwi cr6,r27,6
	cr6.compare<int32_t>(r27.s32, 6, xer);
	// bne cr6,0x826bdb54
	if (!cr6.eq) goto loc_826BDB54;
loc_826BDB0C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// slw r9,r26,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (r26.u32 << (ctx.r10.u8 & 0x3F));
	// and r8,r9,r25
	ctx.r8.u64 = ctx.r9.u64 & r25.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x826bdb28
	if (!cr6.eq) goto loc_826BDB28;
	// cmpwi cr6,r25,-1
	cr6.compare<int32_t>(r25.s32, -1, xer);
	// bne cr6,0x826bdb54
	if (!cr6.eq) goto loc_826BDB54;
loc_826BDB28:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// slw r10,r26,r11
	ctx.r10.u64 = r11.u8 & 0x20 ? 0 : (r26.u32 << (r11.u8 & 0x3F));
	// and r9,r10,r24
	ctx.r9.u64 = ctx.r10.u64 & r24.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826bdb44
	if (!cr6.eq) goto loc_826BDB44;
	// cmpwi cr6,r24,-1
	cr6.compare<int32_t>(r24.s32, -1, xer);
	// bne cr6,0x826bdb54
	if (!cr6.eq) goto loc_826BDB54;
loc_826BDB44:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwzx r4,r11,r29
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x826bcee8
	ctx.lr = 0x826BDB54;
	sub_826BCEE8(ctx, base);
loc_826BDB54:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,160
	r30.s64 = r30.s64 + 160;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x826bdaf0
	if (cr6.lt) goto loc_826BDAF0;
loc_826BDB6C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826BDB74"))) PPC_WEAK_FUNC(sub_826BDB74);
PPC_FUNC_IMPL(__imp__sub_826BDB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDB78"))) PPC_WEAK_FUNC(sub_826BDB78);
PPC_FUNC_IMPL(__imp__sub_826BDB78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bdb90
	if (!cr6.eq) goto loc_826BDB90;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826BDB90:
	// lwz r11,368(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x826bdba8
	if (cr6.gt) goto loc_826BDBA8;
	// li r11,0
	r11.s64 = 0;
loc_826BDBA8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDBB0"))) PPC_WEAK_FUNC(sub_826BDBB0);
PPC_FUNC_IMPL(__imp__sub_826BDBB0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r10,-14748
	ctx.r4.s64 = ctx.r10.s64 + -14748;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826BDBEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r6,r11,13
	ctx.r6.s64 = r11.s64 + 13;
	// lwz r10,-10020(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10020);
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r9,r5,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// cmpw cr6,r3,r9
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, xer);
	// ble cr6,0x826bdc30
	if (!cr6.gt) goto loc_826BDC30;
	// subf r9,r9,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r9.s64;
	// li r8,10
	ctx.r8.s64 = 10;
	// addi r7,r11,65
	ctx.r7.s64 = r11.s64 + 65;
	// divw r6,r9,r8
	ctx.r6.s32 = ctx.r9.s32 / ctx.r8.s32;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r4,r6,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r6.s64;
	// stwx r4,r5,r10
	PPC_STORE_U32(ctx.r5.u32 + ctx.r10.u32, ctx.r4.u32);
	// b 0x826bdc48
	goto loc_826BDC48;
loc_826BDC30:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826bdc48
	if (cr6.eq) goto loc_826BDC48;
	// addi r11,r11,65
	r11.s64 = r11.s64 + 65;
	// addi r9,r3,-15
	ctx.r9.s64 = ctx.r3.s64 + -15;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r9.u32);
loc_826BDC48:
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

__attribute__((alias("__imp__sub_826BDC60"))) PPC_WEAK_FUNC(sub_826BDC60);
PPC_FUNC_IMPL(__imp__sub_826BDC60) {
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
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x826BDC78;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bdcb0
	if (cr6.eq) goto loc_826BDCB0;
	// bl 0x826c5af0
	ctx.lr = 0x826BDC88;
	sub_826C5AF0(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,-15072
	ctx.r9.s64 = r11.s64 + -15072;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,-10004(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10004, r31.u32);
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
loc_826BDCB0:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10004(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10004, r11.u32);
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

__attribute__((alias("__imp__sub_826BDCD0"))) PPC_WEAK_FUNC(sub_826BDCD0);
PPC_FUNC_IMPL(__imp__sub_826BDCD0) {
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
	ctx.lr = 0x826BDCD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bdd30
	if (cr6.eq) goto loc_826BDD30;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_826BDCF8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bdd1c
	if (cr6.eq) goto loc_826BDD1C;
loc_826BDD08:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,268(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// bl 0x82130588
	ctx.lr = 0x826BDD14;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826bdd08
	if (!cr6.eq) goto loc_826BDD08;
loc_826BDD1C:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x826bdcf8
	if (cr6.lt) goto loc_826BDCF8;
loc_826BDD30:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826BDD38;
	sub_82130588(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826BDD4C"))) PPC_WEAK_FUNC(sub_826BDD4C);
PPC_FUNC_IMPL(__imp__sub_826BDD4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDD50"))) PPC_WEAK_FUNC(sub_826BDD50);
PPC_FUNC_IMPL(__imp__sub_826BDD50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bdd9c
	if (cr6.eq) goto loc_826BDD9C;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
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
	// beq cr6,0x826bdd9c
	if (cr6.eq) goto loc_826BDD9C;
loc_826BDD84:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x826bdda4
	if (cr6.eq) goto loc_826BDDA4;
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bdd84
	if (!cr6.eq) goto loc_826BDD84;
loc_826BDD9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826BDDA4:
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDDAC"))) PPC_WEAK_FUNC(sub_826BDDAC);
PPC_FUNC_IMPL(__imp__sub_826BDDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDDB0"))) PPC_WEAK_FUNC(sub_826BDDB0);
PPC_FUNC_IMPL(__imp__sub_826BDDB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bddfc
	if (cr6.eq) goto loc_826BDDFC;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
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
	// beq cr6,0x826bddfc
	if (cr6.eq) goto loc_826BDDFC;
loc_826BDDE4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x826bde04
	if (cr6.eq) goto loc_826BDE04;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bdde4
	if (!cr6.eq) goto loc_826BDDE4;
loc_826BDDFC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826BDE04:
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDE0C"))) PPC_WEAK_FUNC(sub_826BDE0C);
PPC_FUNC_IMPL(__imp__sub_826BDE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDE10"))) PPC_WEAK_FUNC(sub_826BDE10);
PPC_FUNC_IMPL(__imp__sub_826BDE10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bde5c
	if (cr6.eq) goto loc_826BDE5C;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
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
	// beq cr6,0x826bde5c
	if (cr6.eq) goto loc_826BDE5C;
loc_826BDE44:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// beq cr6,0x826bde64
	if (cr6.eq) goto loc_826BDE64;
	// lwz r11,268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bde44
	if (!cr6.eq) goto loc_826BDE44;
loc_826BDE5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826BDE64:
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDE6C"))) PPC_WEAK_FUNC(sub_826BDE6C);
PPC_FUNC_IMPL(__imp__sub_826BDE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDE70"))) PPC_WEAK_FUNC(sub_826BDE70);
PPC_FUNC_IMPL(__imp__sub_826BDE70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bdebc
	if (cr6.eq) goto loc_826BDEBC;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
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
	// beq cr6,0x826bdebc
	if (cr6.eq) goto loc_826BDEBC;
loc_826BDEA4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// beq cr6,0x826bdec4
	if (cr6.eq) goto loc_826BDEC4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bdea4
	if (!cr6.eq) goto loc_826BDEA4;
loc_826BDEBC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826BDEC4:
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDECC"))) PPC_WEAK_FUNC(sub_826BDECC);
PPC_FUNC_IMPL(__imp__sub_826BDECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDED0"))) PPC_WEAK_FUNC(sub_826BDED0);
PPC_FUNC_IMPL(__imp__sub_826BDED0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826bcc58
	ctx.lr = 0x826BDEF0;
	sub_826BCC58(ctx, base);
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

__attribute__((alias("__imp__sub_826BDF0C"))) PPC_WEAK_FUNC(sub_826BDF0C);
PPC_FUNC_IMPL(__imp__sub_826BDF0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDF10"))) PPC_WEAK_FUNC(sub_826BDF10);
PPC_FUNC_IMPL(__imp__sub_826BDF10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,-10020(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r10,r9,620
	ctx.r10.s64 = ctx.r9.s64 + 620;
loc_826BDF28:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// beq cr6,0x826bdf54
	if (cr6.eq) goto loc_826BDF54;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,200
	ctx.r10.s64 = ctx.r10.s64 + 200;
	// cmpwi cr6,r11,40
	cr6.compare<int32_t>(r11.s32, 40, xer);
	// blt cr6,0x826bdf28
	if (cr6.lt) goto loc_826BDF28;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_826BDF54:
	// mulli r11,r11,200
	r11.s64 = r11.s64 * 200;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,456
	r11.s64 = r11.s64 + 456;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDF6C"))) PPC_WEAK_FUNC(sub_826BDF6C);
PPC_FUNC_IMPL(__imp__sub_826BDF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDF70"))) PPC_WEAK_FUNC(sub_826BDF70);
PPC_FUNC_IMPL(__imp__sub_826BDF70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,-10020(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// addi r8,r11,65
	ctx.r8.s64 = r11.s64 + 65;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r7,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bdfac
	if (cr6.eq) goto loc_826BDFAC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_826BDFAC:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,100(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 100);
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BDFC4"))) PPC_WEAK_FUNC(sub_826BDFC4);
PPC_FUNC_IMPL(__imp__sub_826BDFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BDFC8"))) PPC_WEAK_FUNC(sub_826BDFC8);
PPC_FUNC_IMPL(__imp__sub_826BDFC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,-10020(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// addi r5,r11,25
	ctx.r5.s64 = r11.s64 + 25;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r4,r8
	PPC_STORE_U32(ctx.r4.u32 + ctx.r8.u32, ctx.r6.u32);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r10,r10,65
	ctx.r10.s64 = ctx.r10.s64 + 65;
	// lwz r11,-10020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stwx r6,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE028"))) PPC_WEAK_FUNC(sub_826BE028);
PPC_FUNC_IMPL(__imp__sub_826BE028) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x826bdbb0
	sub_826BDBB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826BE03C"))) PPC_WEAK_FUNC(sub_826BE03C);
PPC_FUNC_IMPL(__imp__sub_826BE03C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE040"))) PPC_WEAK_FUNC(sub_826BE040);
PPC_FUNC_IMPL(__imp__sub_826BE040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r8,r10,26688
	ctx.r8.u64 = ctx.r10.u64 | 26688;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// stbx r9,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE05C"))) PPC_WEAK_FUNC(sub_826BE05C);
PPC_FUNC_IMPL(__imp__sub_826BE05C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE060"))) PPC_WEAK_FUNC(sub_826BE060);
PPC_FUNC_IMPL(__imp__sub_826BE060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x826bdaa8
	sub_826BDAA8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826BE07C"))) PPC_WEAK_FUNC(sub_826BE07C);
PPC_FUNC_IMPL(__imp__sub_826BE07C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE080"))) PPC_WEAK_FUNC(sub_826BE080);
PPC_FUNC_IMPL(__imp__sub_826BE080) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,27785
	ctx.r9.u64 = ctx.r10.u64 | 27785;
	// lwz r10,-10020(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826be0b0
	if (cr6.eq) goto loc_826BE0B0;
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
loc_826BE0B0:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,27692
	ctx.r8.u64 = ctx.r9.u64 | 27692;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbzx r11,r7,r8
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE0E4"))) PPC_WEAK_FUNC(sub_826BE0E4);
PPC_FUNC_IMPL(__imp__sub_826BE0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE0E8"))) PPC_WEAK_FUNC(sub_826BE0E8);
PPC_FUNC_IMPL(__imp__sub_826BE0E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// li r7,1
	ctx.r7.s64 = 1;
	// ori r6,r8,27692
	ctx.r6.u64 = ctx.r8.u64 | 27692;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stbx r7,r5,r6
	PPC_STORE_U8(ctx.r5.u32 + ctx.r6.u32, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE110"))) PPC_WEAK_FUNC(sub_826BE110);
PPC_FUNC_IMPL(__imp__sub_826BE110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826be130
	if (!cr6.eq) goto loc_826BE130;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_826BE130:
	// lwz r11,368(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x826be148
	if (cr6.gt) goto loc_826BE148;
	// li r11,0
	r11.s64 = 0;
loc_826BE148:
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
}

__attribute__((alias("__imp__sub_826BE15C"))) PPC_WEAK_FUNC(sub_826BE15C);
PPC_FUNC_IMPL(__imp__sub_826BE15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE160"))) PPC_WEAK_FUNC(sub_826BE160);
PPC_FUNC_IMPL(__imp__sub_826BE160) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// ori r9,r10,4
	ctx.r9.u64 = ctx.r10.u64 | 4;
	// stw r9,368(r11)
	PPC_STORE_U32(r11.u32 + 368, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE180"))) PPC_WEAK_FUNC(sub_826BE180);
PPC_FUNC_IMPL(__imp__sub_826BE180) {
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
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826be200
	if (cr6.eq) goto loc_826BE200;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826bcb70
	ctx.lr = 0x826BE1B0;
	sub_826BCB70(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x826be1d8
	if (!cr6.eq) goto loc_826BE1D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_826BE1D8:
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x826be1e4
	if (!cr6.eq) goto loc_826BE1E4;
	// li r3,3
	ctx.r3.s64 = 3;
loc_826BE1E4:
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
loc_826BE200:
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

__attribute__((alias("__imp__sub_826BE220"))) PPC_WEAK_FUNC(sub_826BE220);
PPC_FUNC_IMPL(__imp__sub_826BE220) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,27760
	ctx.r8.u64 = ctx.r9.u64 | 27760;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE240"))) PPC_WEAK_FUNC(sub_826BE240);
PPC_FUNC_IMPL(__imp__sub_826BE240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,27761
	ctx.r8.u64 = ctx.r9.u64 | 27761;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE260"))) PPC_WEAK_FUNC(sub_826BE260);
PPC_FUNC_IMPL(__imp__sub_826BE260) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,27764
	ctx.r8.u64 = ctx.r9.u64 | 27764;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE280"))) PPC_WEAK_FUNC(sub_826BE280);
PPC_FUNC_IMPL(__imp__sub_826BE280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,27760
	ctx.r8.u64 = ctx.r9.u64 | 27760;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10020(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// stbx r4,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE2AC"))) PPC_WEAK_FUNC(sub_826BE2AC);
PPC_FUNC_IMPL(__imp__sub_826BE2AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE2B0"))) PPC_WEAK_FUNC(sub_826BE2B0);
PPC_FUNC_IMPL(__imp__sub_826BE2B0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be2f4
	if (cr6.eq) goto loc_826BE2F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826BE2D8;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,444
	ctx.r3.s64 = r31.s64 + 444;
	// bl 0x826bdd50
	ctx.lr = 0x826BE2E8;
	sub_826BDD50(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x826be2f8
	if (!cr6.eq) goto loc_826BE2F8;
loc_826BE2F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BE2F8:
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

__attribute__((alias("__imp__sub_826BE30C"))) PPC_WEAK_FUNC(sub_826BE30C);
PPC_FUNC_IMPL(__imp__sub_826BE30C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE310"))) PPC_WEAK_FUNC(sub_826BE310);
PPC_FUNC_IMPL(__imp__sub_826BE310) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be368
	if (cr6.eq) goto loc_826BE368;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826BE338;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,444
	ctx.r3.s64 = r31.s64 + 444;
	// bl 0x826bdd50
	ctx.lr = 0x826BE348;
	sub_826BDD50(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be368
	if (cr6.eq) goto loc_826BE368;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
loc_826BE368:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_826BE380"))) PPC_WEAK_FUNC(sub_826BE380);
PPC_FUNC_IMPL(__imp__sub_826BE380) {
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
	ctx.lr = 0x826BE388;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// lis r11,1
	r11.s64 = 65536;
	// addi r28,r28,27756
	r28.s64 = r28.s64 + 27756;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ori r29,r11,27700
	r29.u64 = r11.u64 | 27700;
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x826be41c
	if (!cr6.gt) goto loc_826BE41C;
	// add r3,r31,r29
	ctx.r3.u64 = r31.u64 + r29.u64;
	// lis r11,10922
	r11.s64 = 715784192;
	// ori r9,r11,43691
	ctx.r9.u64 = r11.u64 | 43691;
	// lwz r8,52(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
loc_826BE3C8:
	// add r11,r8,r4
	r11.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// mulhw r5,r6,r9
	ctx.r5.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32)) >> 32;
	// srawi r11,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	r11.s64 = ctx.r5.s32 >> 1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r10,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r5,r3
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x826be410
	if (cr6.eq) goto loc_826BE410;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r4,r7
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, xer);
	// blt cr6,0x826be3c8
	if (cr6.lt) goto loc_826BE3C8;
	// b 0x826be41c
	goto loc_826BE41C;
loc_826BE410:
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x826be41c
	if (cr6.eq) goto loc_826BE41C;
	// bl 0x826bd060
	ctx.lr = 0x826BE41C;
	sub_826BD060(ctx, base);
loc_826BE41C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// subfic r10,r11,12
	xer.ca = r11.u32 <= 12;
	ctx.r10.s64 = 12 - r11.s64;
	// add r11,r31,r29
	r11.u64 = r31.u64 + r29.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826be454
	if (!cr6.eq) goto loc_826BE454;
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r9.u32);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// cmpwi cr6,r10,12
	cr6.compare<int32_t>(ctx.r10.s32, 12, xer);
	// bne cr6,0x826be454
	if (!cr6.eq) goto loc_826BE454;
	// stw r27,52(r11)
	PPC_STORE_U32(r11.u32 + 52, r27.u32);
loc_826BE454:
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmpwi cr6,r10,12
	cr6.compare<int32_t>(ctx.r10.s32, 12, xer);
	// beq cr6,0x826be490
	if (cr6.eq) goto loc_826BE490;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r10,12
	cr6.compare<int32_t>(ctx.r10.s32, 12, xer);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// bne cr6,0x826be478
	if (!cr6.eq) goto loc_826BE478;
	// stw r27,48(r11)
	PPC_STORE_U32(r11.u32 + 48, r27.u32);
loc_826BE478:
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r8.u32);
loc_826BE490:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826BE498"))) PPC_WEAK_FUNC(sub_826BE498);
PPC_FUNC_IMPL(__imp__sub_826BE498) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826BE4B8;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8456
	ctx.r3.s64 = r31.s64 + 8456;
	// bl 0x826bddb0
	ctx.lr = 0x826BE4C8;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be4e8
	if (cr6.eq) goto loc_826BE4E8;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
loc_826BE4E8:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_826BE500"))) PPC_WEAK_FUNC(sub_826BE500);
PPC_FUNC_IMPL(__imp__sub_826BE500) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x826BE528;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8456
	ctx.r3.s64 = r31.s64 + 8456;
	// bl 0x826bddb0
	ctx.lr = 0x826BE538;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be554
	if (cr6.eq) goto loc_826BE554;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be554
	if (cr6.eq) goto loc_826BE554;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826cd1e8
	ctx.lr = 0x826BE554;
	sub_826CD1E8(ctx, base);
loc_826BE554:
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

__attribute__((alias("__imp__sub_826BE56C"))) PPC_WEAK_FUNC(sub_826BE56C);
PPC_FUNC_IMPL(__imp__sub_826BE56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE570"))) PPC_WEAK_FUNC(sub_826BE570);
PPC_FUNC_IMPL(__imp__sub_826BE570) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,8748
	ctx.r3.s64 = ctx.r3.s64 + 8748;
	// bl 0x826bde10
	ctx.lr = 0x826BE58C;
	sub_826BDE10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE59C"))) PPC_WEAK_FUNC(sub_826BE59C);
PPC_FUNC_IMPL(__imp__sub_826BE59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE5A0"))) PPC_WEAK_FUNC(sub_826BE5A0);
PPC_FUNC_IMPL(__imp__sub_826BE5A0) {
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
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// addi r3,r11,8748
	ctx.r3.s64 = r11.s64 + 8748;
	// bl 0x826bde10
	ctx.lr = 0x826BE5C4;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x826be5d4
	if (!cr6.eq) goto loc_826BE5D4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BE5D4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BE5E4"))) PPC_WEAK_FUNC(sub_826BE5E4);
PPC_FUNC_IMPL(__imp__sub_826BE5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE5E8"))) PPC_WEAK_FUNC(sub_826BE5E8);
PPC_FUNC_IMPL(__imp__sub_826BE5E8) {
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// li r30,0
	r30.s64 = 0;
	// bl 0x826bde10
	ctx.lr = 0x826BE614;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be6b4
	if (cr6.eq) goto loc_826BE6B4;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// lis r10,0
	ctx.r10.s64 = 0;
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// ori r8,r10,58312
	ctx.r8.u64 = ctx.r10.u64 | 58312;
	// lwz r7,16952(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16952);
	// lwzx r6,r31,r8
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// beq cr6,0x826be650
	if (cr6.eq) goto loc_826BE650;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_826BE650:
	// lis r11,1
	r11.s64 = 65536;
	// ori r10,r11,1048
	ctx.r10.u64 = r11.u64 | 1048;
	// lwzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826be668
	if (cr6.eq) goto loc_826BE668;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_826BE668:
	// lis r11,1
	r11.s64 = 65536;
	// ori r10,r11,9320
	ctx.r10.u64 = r11.u64 | 9320;
	// lwzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826be680
	if (cr6.eq) goto loc_826BE680;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_826BE680:
	// lis r11,1
	r11.s64 = 65536;
	// ori r10,r11,17592
	ctx.r10.u64 = r11.u64 | 17592;
	// lwzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826be698
	if (cr6.eq) goto loc_826BE698;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_826BE698:
	// lis r11,1
	r11.s64 = 65536;
	// ori r10,r11,25864
	ctx.r10.u64 = r11.u64 | 25864;
	// lwzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826be6b8
	if (cr6.eq) goto loc_826BE6B8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// b 0x826be6b8
	goto loc_826BE6B8;
loc_826BE6B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826BE6B8:
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

__attribute__((alias("__imp__sub_826BE6D0"))) PPC_WEAK_FUNC(sub_826BE6D0);
PPC_FUNC_IMPL(__imp__sub_826BE6D0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826be708
	if (cr6.eq) goto loc_826BE708;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826be5e8
	ctx.lr = 0x826BE6F8;
	sub_826BE5E8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826BE708:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14736
	ctx.r3.s64 = r11.s64 + -14736;
	// bl 0x82130000
	ctx.lr = 0x826BE714;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_826BE728"))) PPC_WEAK_FUNC(sub_826BE728);
PPC_FUNC_IMPL(__imp__sub_826BE728) {
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x826bde10
	ctx.lr = 0x826BE754;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be7bc
	if (cr6.eq) goto loc_826BE7BC;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,16952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16952);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826be788
	if (cr6.eq) goto loc_826BE788;
	// lwz r10,17024(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17024);
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// bne cr6,0x826be788
	if (!cr6.eq) goto loc_826BE788;
	// addi r3,r11,8848
	ctx.r3.s64 = r11.s64 + 8848;
	// b 0x826be7c0
	goto loc_826BE7C0;
loc_826BE788:
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-7152
	r11.s64 = r11.s64 + -7152;
loc_826BE794:
	// lwz r9,-72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -72);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826be7ac
	if (cr6.eq) goto loc_826BE7AC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// beq cr6,0x826be7d8
	if (cr6.eq) goto loc_826BE7D8;
loc_826BE7AC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8272
	r11.s64 = r11.s64 + 8272;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// blt cr6,0x826be794
	if (cr6.lt) goto loc_826BE794;
loc_826BE7BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BE7C0:
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
loc_826BE7D8:
	// mulli r11,r10,8272
	r11.s64 = ctx.r10.s64 * 8272;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,-15328
	ctx.r3.s64 = ctx.r3.s64 + -15328;
	// b 0x826be7c0
	goto loc_826BE7C0;
}

__attribute__((alias("__imp__sub_826BE7EC"))) PPC_WEAK_FUNC(sub_826BE7EC);
PPC_FUNC_IMPL(__imp__sub_826BE7EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE7F0"))) PPC_WEAK_FUNC(sub_826BE7F0);
PPC_FUNC_IMPL(__imp__sub_826BE7F0) {
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
	ctx.lr = 0x826BE7F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x826bde10
	ctx.lr = 0x826BE818;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826be934
	if (cr6.eq) goto loc_826BE934;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x826be884
	if (!cr6.eq) goto loc_826BE884;
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// add r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r30,8848
	ctx.r3.s64 = r30.s64 + 8848;
	// stw r28,8768(r30)
	PPC_STORE_U32(r30.u32 + 8768, r28.u32);
	// bl 0x8238ee58
	ctx.lr = 0x826BE848;
	sub_8238EE58(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r29,8109
	ctx.r4.s64 = r29.s64 + 8109;
	// addi r3,r30,8772
	ctx.r3.s64 = r30.s64 + 8772;
	// bl 0x823db670
	ctx.lr = 0x826BE858;
	sub_823DB670(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,25960
	r11.s64 = r11.s64 + 25960;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r10.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bge 0x826be874
	if (!cr0.lt) goto loc_826BE874;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
loc_826BE874:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r3,17024(r30)
	PPC_STORE_U32(r30.u32 + 17024, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826BE884:
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// li r28,3
	r28.s64 = 3;
	// addi r30,r30,9408
	r30.s64 = r30.s64 + 9408;
loc_826BE890:
	// lwz r11,8184(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826be8a8
	if (cr6.eq) goto loc_826BE8A8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r30,8272
	ctx.r3.s64 = r30.s64 + 8272;
	// bl 0x826bc9d8
	ctx.lr = 0x826BE8A8;
	sub_826BC9D8(ctx, base);
loc_826BE8A8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,-8272
	r30.s64 = r30.s64 + -8272;
	// bge 0x826be890
	if (!cr0.lt) goto loc_826BE890;
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r30,-15408
	r30.s64 = r30.s64 + -15408;
	// li r27,-1
	r27.s64 = -1;
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
	// stb r28,4(r30)
	PPC_STORE_U8(r30.u32 + 4, r28.u8);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// bl 0x8238ee08
	ctx.lr = 0x826BE8D4;
	sub_8238EE08(ctx, base);
	// stw r27,8256(r30)
	PPC_STORE_U32(r30.u32 + 8256, r27.u32);
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r3,-15328
	ctx.r3.s64 = ctx.r3.s64 + -15328;
	// bl 0x8238ee58
	ctx.lr = 0x826BE8EC;
	sub_8238EE58(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r29,8109
	ctx.r4.s64 = r29.s64 + 8109;
	// addi r3,r3,-15404
	ctx.r3.s64 = ctx.r3.s64 + -15404;
	// bl 0x823db670
	ctx.lr = 0x826BE900;
	sub_823DB670(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,25960
	r11.s64 = r11.s64 + 25960;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r10.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bge 0x826be91c
	if (!cr0.lt) goto loc_826BE91C;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
loc_826BE91C:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,58384
	ctx.r9.u64 = ctx.r10.u64 | 58384;
	// stwx r3,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826BE934:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14560
	ctx.r3.s64 = r11.s64 + -14560;
	// bl 0x82130000
	ctx.lr = 0x826BE940;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826BE94C"))) PPC_WEAK_FUNC(sub_826BE94C);
PPC_FUNC_IMPL(__imp__sub_826BE94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BE950"))) PPC_WEAK_FUNC(sub_826BE950);
PPC_FUNC_IMPL(__imp__sub_826BE950) {
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
	ctx.lr = 0x826BE958;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x826bde10
	ctx.lr = 0x826BE978;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bea9c
	if (cr6.eq) goto loc_826BEA9C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bne cr6,0x826be9e8
	if (!cr6.eq) goto loc_826BE9E8;
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// add r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	// li r28,0
	r28.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r30,8848
	ctx.r3.s64 = r30.s64 + 8848;
	// stw r28,8768(r30)
	PPC_STORE_U32(r30.u32 + 8768, r28.u32);
	// bl 0x82390b18
	ctx.lr = 0x826BE9AC;
	sub_82390B18(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r30,8772
	ctx.r3.s64 = r30.s64 + 8772;
	// bl 0x823db670
	ctx.lr = 0x826BE9BC;
	sub_823DB670(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,25960
	r11.s64 = r11.s64 + 25960;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r10.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bge 0x826be9d8
	if (!cr0.lt) goto loc_826BE9D8;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
loc_826BE9D8:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r3,17024(r30)
	PPC_STORE_U32(r30.u32 + 17024, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826BE9E8:
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// li r28,3
	r28.s64 = 3;
	// addi r30,r30,9408
	r30.s64 = r30.s64 + 9408;
loc_826BE9F4:
	// lwz r11,8184(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bea0c
	if (cr6.eq) goto loc_826BEA0C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r30,8272
	ctx.r3.s64 = r30.s64 + 8272;
	// bl 0x826bc9d8
	ctx.lr = 0x826BEA0C;
	sub_826BC9D8(ctx, base);
loc_826BEA0C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,-8272
	r30.s64 = r30.s64 + -8272;
	// bge 0x826be9f4
	if (!cr0.lt) goto loc_826BE9F4;
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r30,-15408
	r30.s64 = r30.s64 + -15408;
	// li r27,-1
	r27.s64 = -1;
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
	// stb r28,4(r30)
	PPC_STORE_U8(r30.u32 + 4, r28.u8);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// bl 0x8238ee08
	ctx.lr = 0x826BEA38;
	sub_8238EE08(ctx, base);
	// stw r27,8256(r30)
	PPC_STORE_U32(r30.u32 + 8256, r27.u32);
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r3,-15328
	ctx.r3.s64 = ctx.r3.s64 + -15328;
	// bl 0x82390b18
	ctx.lr = 0x826BEA54;
	sub_82390B18(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r3,-15404
	ctx.r3.s64 = ctx.r3.s64 + -15404;
	// bl 0x823db670
	ctx.lr = 0x826BEA68;
	sub_823DB670(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,25960
	r11.s64 = r11.s64 + 25960;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r10.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bge 0x826bea84
	if (!cr0.lt) goto loc_826BEA84;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
loc_826BEA84:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,58384
	ctx.r9.u64 = ctx.r10.u64 | 58384;
	// stwx r3,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826BEA9C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14400
	ctx.r3.s64 = r11.s64 + -14400;
	// bl 0x82130000
	ctx.lr = 0x826BEAA8;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826BEAB4"))) PPC_WEAK_FUNC(sub_826BEAB4);
PPC_FUNC_IMPL(__imp__sub_826BEAB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BEAB8"))) PPC_WEAK_FUNC(sub_826BEAB8);
PPC_FUNC_IMPL(__imp__sub_826BEAB8) {
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
	ctx.lr = 0x826BEAC0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x826bde10
	ctx.lr = 0x826BEADC;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bec04
	if (cr6.eq) goto loc_826BEC04;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,16952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16952);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826beb18
	if (cr6.eq) goto loc_826BEB18;
	// lwz r10,17024(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17024);
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// bne cr6,0x826beb18
	if (!cr6.eq) goto loc_826BEB18;
	// addi r3,r11,8768
	ctx.r3.s64 = r11.s64 + 8768;
	// bl 0x826bc988
	ctx.lr = 0x826BEB10;
	sub_826BC988(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826BEB18:
	// li r26,0
	r26.s64 = 0;
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// mr r30,r26
	r30.u64 = r26.u64;
	// addi r11,r11,-7152
	r11.s64 = r11.s64 + -7152;
loc_826BEB28:
	// lwz r10,-72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -72);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826beb40
	if (cr6.eq) goto loc_826BEB40;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r29
	cr6.compare<int32_t>(ctx.r10.s32, r29.s32, xer);
	// beq cr6,0x826beb58
	if (cr6.eq) goto loc_826BEB58;
loc_826BEB40:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,8272
	r11.s64 = r11.s64 + 8272;
	// cmpwi cr6,r30,5
	cr6.compare<int32_t>(r30.s32, 5, xer);
	// blt cr6,0x826beb28
	if (cr6.lt) goto loc_826BEB28;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826BEB58:
	// mulli r11,r30,8272
	r11.s64 = r30.s64 * 8272;
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
	// li r28,-1
	r28.s64 = -1;
	// addis r31,r29,1
	r31.s64 = r29.s64 + 65536;
	// addi r31,r31,-15408
	r31.s64 = r31.s64 + -15408;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// stb r26,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r26.u8);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// bl 0x8238ee08
	ctx.lr = 0x826BEB7C;
	sub_8238EE08(ctx, base);
	// cmpwi cr6,r30,5
	cr6.compare<int32_t>(r30.s32, 5, xer);
	// stw r28,8256(r31)
	PPC_STORE_U32(r31.u32 + 8256, r28.u32);
	// bge cr6,0x826bec10
	if (!cr6.lt) goto loc_826BEC10;
	// addis r31,r29,1
	r31.s64 = r29.s64 + 65536;
	// subfic r27,r30,5
	xer.ca = r30.u32 <= 5;
	r27.s64 = 5 - r30.s64;
	// addi r31,r31,-23600
	r31.s64 = r31.s64 + -23600;
loc_826BEB94:
	// lwz r11,16376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16376);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bebf0
	if (cr6.eq) goto loc_826BEBF0;
	// addi r30,r31,8192
	r30.s64 = r31.s64 + 8192;
	// addi r11,r31,-80
	r11.s64 = r31.s64 + -80;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x826bebdc
	if (cr6.eq) goto loc_826BEBDC;
	// addi r4,r31,8196
	ctx.r4.s64 = r31.s64 + 8196;
	// addi r3,r31,-76
	ctx.r3.s64 = r31.s64 + -76;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x826BEBC0;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r31,8272
	ctx.r4.s64 = r31.s64 + 8272;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-80(r31)
	PPC_STORE_U32(r31.u32 + -80, r11.u32);
	// bl 0x8238ee58
	ctx.lr = 0x826BEBD4;
	sub_8238EE58(ctx, base);
	// lwz r10,16448(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16448);
	// stw r10,8176(r31)
	PPC_STORE_U32(r31.u32 + 8176, ctx.r10.u32);
loc_826BEBDC:
	// stb r26,8196(r31)
	PPC_STORE_U8(r31.u32 + 8196, r26.u8);
	// addi r3,r31,8272
	ctx.r3.s64 = r31.s64 + 8272;
	// stw r28,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r28.u32);
	// bl 0x8238ee08
	ctx.lr = 0x826BEBEC;
	sub_8238EE08(ctx, base);
	// stw r28,16448(r31)
	PPC_STORE_U32(r31.u32 + 16448, r28.u32);
loc_826BEBF0:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r31,r31,8272
	r31.s64 = r31.s64 + 8272;
	// bne 0x826beb94
	if (!cr0.eq) goto loc_826BEB94;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826BEC04:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14232
	ctx.r3.s64 = r11.s64 + -14232;
	// bl 0x82130000
	ctx.lr = 0x826BEC10;
	sub_82130000(ctx, base);
loc_826BEC10:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826BEC18"))) PPC_WEAK_FUNC(sub_826BEC18);
PPC_FUNC_IMPL(__imp__sub_826BEC18) {
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x826bde10
	ctx.lr = 0x826BEC44;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826becac
	if (cr6.eq) goto loc_826BECAC;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,16952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16952);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826bec78
	if (cr6.eq) goto loc_826BEC78;
	// lwz r10,17024(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17024);
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// bne cr6,0x826bec78
	if (!cr6.eq) goto loc_826BEC78;
	// lwz r3,8768(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8768);
	// b 0x826becbc
	goto loc_826BECBC;
loc_826BEC78:
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-7152
	r11.s64 = r11.s64 + -7152;
loc_826BEC84:
	// lwz r9,-72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -72);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826bec9c
	if (cr6.eq) goto loc_826BEC9C;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// beq cr6,0x826becd4
	if (cr6.eq) goto loc_826BECD4;
loc_826BEC9C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8272
	r11.s64 = r11.s64 + 8272;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// blt cr6,0x826bec84
	if (cr6.lt) goto loc_826BEC84;
loc_826BECAC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14056
	ctx.r3.s64 = r11.s64 + -14056;
	// bl 0x82130000
	ctx.lr = 0x826BECB8;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
loc_826BECBC:
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
loc_826BECD4:
	// mulli r11,r10,8272
	r11.s64 = ctx.r10.s64 * 8272;
	// lis r10,0
	ctx.r10.s64 = 0;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// ori r8,r10,50128
	ctx.r8.u64 = ctx.r10.u64 | 50128;
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// b 0x826becbc
	goto loc_826BECBC;
}

__attribute__((alias("__imp__sub_826BECEC"))) PPC_WEAK_FUNC(sub_826BECEC);
PPC_FUNC_IMPL(__imp__sub_826BECEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BECF0"))) PPC_WEAK_FUNC(sub_826BECF0);
PPC_FUNC_IMPL(__imp__sub_826BECF0) {
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
	ctx.lr = 0x826BECF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x826bde10
	ctx.lr = 0x826BED18;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bedd4
	if (cr6.eq) goto loc_826BEDD4;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x826bed4c
	if (!cr6.eq) goto loc_826BED4C;
	// mulli r10,r11,8272
	ctx.r10.s64 = r11.s64 * 8272;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// lwz r9,16952(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16952);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826bed4c
	if (cr6.eq) goto loc_826BED4C;
	// lwz r3,17024(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17024);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826BED4C:
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r10,-7224
	ctx.r10.s64 = ctx.r10.s64 + -7224;
	// lwz r8,16952(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16952);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r9,r6,1
	ctx.r9.u64 = ctx.r6.u64 ^ 1;
loc_826BED70:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826bed88
	if (cr6.eq) goto loc_826BED88;
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// beq cr6,0x826bedb8
	if (cr6.eq) goto loc_826BEDB8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_826BED88:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8272
	ctx.r10.s64 = ctx.r10.s64 + 8272;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// blt cr6,0x826bed70
	if (cr6.lt) goto loc_826BED70;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,-13776
	ctx.r3.s64 = r11.s64 + -13776;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x826BEDAC;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826BEDB8:
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// lis r10,0
	ctx.r10.s64 = 0;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// ori r8,r10,58384
	ctx.r8.u64 = ctx.r10.u64 | 58384;
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826BEDD4:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-13864
	ctx.r3.s64 = r11.s64 + -13864;
	// bl 0x82130000
	ctx.lr = 0x826BEDE4;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826BEDF0"))) PPC_WEAK_FUNC(sub_826BEDF0);
PPC_FUNC_IMPL(__imp__sub_826BEDF0) {
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
	ctx.lr = 0x826BEDF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x826bde10
	ctx.lr = 0x826BEE18;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bee84
	if (cr6.eq) goto loc_826BEE84;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// mulli r11,r11,8272
	r11.s64 = r11.s64 * 8272;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,16952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16952);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826bee50
	if (cr6.eq) goto loc_826BEE50;
	// lwz r10,17024(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17024);
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// bne cr6,0x826bee50
	if (!cr6.eq) goto loc_826BEE50;
	// addi r3,r11,8772
	ctx.r3.s64 = r11.s64 + 8772;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826BEE50:
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-7152
	r11.s64 = r11.s64 + -7152;
loc_826BEE5C:
	// lwz r9,-72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -72);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826bee74
	if (cr6.eq) goto loc_826BEE74;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// beq cr6,0x826beea0
	if (cr6.eq) goto loc_826BEEA0;
loc_826BEE74:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8272
	r11.s64 = r11.s64 + 8272;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// blt cr6,0x826bee5c
	if (cr6.lt) goto loc_826BEE5C;
loc_826BEE84:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-13576
	ctx.r3.s64 = r11.s64 + -13576;
	// bl 0x82130000
	ctx.lr = 0x826BEE94;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826BEEA0:
	// mulli r11,r10,8272
	r11.s64 = ctx.r10.s64 * 8272;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,-15404
	ctx.r3.s64 = ctx.r3.s64 + -15404;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826BEEB8"))) PPC_WEAK_FUNC(sub_826BEEB8);
PPC_FUNC_IMPL(__imp__sub_826BEEB8) {
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
	ctx.lr = 0x826BEEC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r31,-10020(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bef28
	if (cr6.eq) goto loc_826BEF28;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// bl 0x826bde10
	ctx.lr = 0x826BEEEC;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bef10
	if (cr6.eq) goto loc_826BEF10;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,25952
	ctx.r9.u64 = ctx.r10.u64 | 25952;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stbx r29,r8,r9
	PPC_STORE_U8(ctx.r8.u32 + ctx.r9.u32, r29.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826BEF10:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-13392
	ctx.r3.s64 = r11.s64 + -13392;
	// bl 0x82130000
	ctx.lr = 0x826BEF20;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826BEF28:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-13296
	ctx.r3.s64 = r11.s64 + -13296;
	// bl 0x82130000
	ctx.lr = 0x826BEF34;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826BEF3C"))) PPC_WEAK_FUNC(sub_826BEF3C);
PPC_FUNC_IMPL(__imp__sub_826BEF3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BEF40"))) PPC_WEAK_FUNC(sub_826BEF40);
PPC_FUNC_IMPL(__imp__sub_826BEF40) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// bl 0x826bde10
	ctx.lr = 0x826BEF6C;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bef8c
	if (cr6.eq) goto loc_826BEF8C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,25952
	ctx.r9.u64 = ctx.r10.u64 | 25952;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// lbzx r3,r8,r9
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// b 0x826befa0
	goto loc_826BEFA0;
loc_826BEF8C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,-13200
	ctx.r3.s64 = r11.s64 + -13200;
	// bl 0x82130000
	ctx.lr = 0x826BEF9C;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BEFA0:
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

__attribute__((alias("__imp__sub_826BEFB8"))) PPC_WEAK_FUNC(sub_826BEFB8);
PPC_FUNC_IMPL(__imp__sub_826BEFB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,1
	r11.s64 = 65536;
	// add r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 + ctx.r3.u64;
	// ori r11,r11,25980
	r11.u64 = r11.u64 | 25980;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// stbx r5,r10,r9
	PPC_STORE_U8(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u8);
	// lbzx r7,r3,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826befe4
	if (!cr6.eq) goto loc_826BEFE4;
	// li r11,0
	r11.s64 = 0;
loc_826BEFE4:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,25981
	ctx.r9.u64 = ctx.r10.u64 | 25981;
	// lbzx r8,r3,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826beffc
	if (!cr6.eq) goto loc_826BEFFC;
	// li r11,0
	r11.s64 = 0;
loc_826BEFFC:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,25982
	ctx.r9.u64 = ctx.r10.u64 | 25982;
	// lbzx r8,r3,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826bf014
	if (!cr6.eq) goto loc_826BF014;
	// li r11,0
	r11.s64 = 0;
loc_826BF014:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,25983
	ctx.r9.u64 = ctx.r10.u64 | 25983;
	// lbzx r8,r3,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826bf02c
	if (!cr6.eq) goto loc_826BF02C;
	// li r11,0
	r11.s64 = 0;
loc_826BF02C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-13016
	ctx.r4.s64 = ctx.r10.s64 + -13016;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826BF060"))) PPC_WEAK_FUNC(sub_826BF060);
PPC_FUNC_IMPL(__imp__sub_826BF060) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826BF064"))) PPC_WEAK_FUNC(sub_826BF064);
PPC_FUNC_IMPL(__imp__sub_826BF064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BF068"))) PPC_WEAK_FUNC(sub_826BF068);
PPC_FUNC_IMPL(__imp__sub_826BF068) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,-12796
	ctx.r10.s64 = r11.s64 + -12796;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826BF08C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826bf0b0
	if (cr6.eq) goto loc_826BF0B0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf08c
	if (cr6.eq) goto loc_826BF08C;
loc_826BF0B0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf44c
	if (cr6.eq) goto loc_826BF44C;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-12820
	ctx.r10.s64 = ctx.r10.s64 + -12820;
loc_826BF0C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826bf0e8
	if (cr6.eq) goto loc_826BF0E8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf0c4
	if (cr6.eq) goto loc_826BF0C4;
loc_826BF0E8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf44c
	if (cr6.eq) goto loc_826BF44C;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-12848
	ctx.r10.s64 = ctx.r10.s64 + -12848;
loc_826BF0FC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826bf120
	if (cr6.eq) goto loc_826BF120;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf0fc
	if (cr6.eq) goto loc_826BF0FC;
loc_826BF120:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf40c
	if (cr6.eq) goto loc_826BF40C;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-12876
	ctx.r10.s64 = ctx.r10.s64 + -12876;
loc_826BF134:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826bf158
	if (cr6.eq) goto loc_826BF158;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf134
	if (cr6.eq) goto loc_826BF134;
loc_826BF158:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf40c
	if (cr6.eq) goto loc_826BF40C;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-12896
	ctx.r10.s64 = ctx.r10.s64 + -12896;
loc_826BF16C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826bf190
	if (cr6.eq) goto loc_826BF190;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf16c
	if (cr6.eq) goto loc_826BF16C;
loc_826BF190:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf3cc
	if (cr6.eq) goto loc_826BF3CC;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-12916
	ctx.r10.s64 = ctx.r10.s64 + -12916;
loc_826BF1A4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826bf1c8
	if (cr6.eq) goto loc_826BF1C8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf1a4
	if (cr6.eq) goto loc_826BF1A4;
loc_826BF1C8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf3cc
	if (cr6.eq) goto loc_826BF3CC;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-12944
	ctx.r10.s64 = ctx.r10.s64 + -12944;
loc_826BF1DC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826bf200
	if (cr6.eq) goto loc_826BF200;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf1dc
	if (cr6.eq) goto loc_826BF1DC;
loc_826BF200:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf38c
	if (cr6.eq) goto loc_826BF38C;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,24432
	ctx.r10.s64 = ctx.r10.s64 + 24432;
loc_826BF214:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826bf238
	if (cr6.eq) goto loc_826BF238;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf214
	if (cr6.eq) goto loc_826BF214;
loc_826BF238:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826bf38c
	if (cr6.eq) goto loc_826BF38C;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-29168
	ctx.r10.s64 = r11.s64 + -29168;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf434
	if (!cr6.eq) goto loc_826BF434;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396110
	ctx.lr = 0x826BF25C;
	sub_82396110(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bf2c8
	if (cr6.eq) goto loc_826BF2C8;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27428
	ctx.r10.s64 = r11.s64 + -27428;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf2a0
	if (!cr6.eq) goto loc_826BF2A0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,25999
	ctx.r9.u64 = ctx.r10.u64 | 25999;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// b 0x826bf2a4
	goto loc_826BF2A4;
loc_826BF2A0:
	// li r11,1
	r11.s64 = 1;
loc_826BF2A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bf498
	if (cr6.eq) goto loc_826BF498;
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826BF2C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396130
	ctx.lr = 0x826BF2D0;
	sub_82396130(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bf314
	if (cr6.eq) goto loc_826BF314;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27428
	ctx.r10.s64 = r11.s64 + -27428;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf2a0
	if (!cr6.eq) goto loc_826BF2A0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,25994
	ctx.r9.u64 = ctx.r10.u64 | 25994;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// b 0x826bf2a4
	goto loc_826BF2A4;
loc_826BF314:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396158
	ctx.lr = 0x826BF31C;
	sub_82396158(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bf360
	if (cr6.eq) goto loc_826BF360;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27428
	ctx.r10.s64 = r11.s64 + -27428;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf2a0
	if (!cr6.eq) goto loc_826BF2A0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,25989
	ctx.r9.u64 = ctx.r10.u64 | 25989;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// b 0x826bf2a4
	goto loc_826BF2A4;
loc_826BF360:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82396180
	ctx.lr = 0x826BF368;
	sub_82396180(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bf498
	if (cr6.eq) goto loc_826BF498;
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826BF38C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-12960
	ctx.r4.s64 = ctx.r10.s64 + -12960;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x826BF3A0;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bf498
	if (cr6.eq) goto loc_826BF498;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826bf498
	if (!cr6.gt) goto loc_826BF498;
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826BF3CC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-12976
	ctx.r4.s64 = ctx.r10.s64 + -12976;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x826BF3E0;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bf498
	if (cr6.eq) goto loc_826BF498;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826bf498
	if (!cr6.gt) goto loc_826BF498;
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826BF40C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-12992
	ctx.r4.s64 = ctx.r10.s64 + -12992;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x826BF420;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bf498
	if (cr6.eq) goto loc_826BF498;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826bf498
	if (!cr6.gt) goto loc_826BF498;
loc_826BF434:
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826BF44C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-13008
	ctx.r3.s64 = ctx.r10.s64 + -13008;
	// lwz r31,-10020(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x821c9790
	ctx.lr = 0x826BF464;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8456
	ctx.r3.s64 = r31.s64 + 8456;
	// bl 0x826bddb0
	ctx.lr = 0x826BF474;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bf498
	if (cr6.eq) goto loc_826BF498;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bf498
	if (cr6.eq) goto loc_826BF498;
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x826bf49c
	if (cr6.gt) goto loc_826BF49C;
loc_826BF498:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BF49C:
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

__attribute__((alias("__imp__sub_826BF4B0"))) PPC_WEAK_FUNC(sub_826BF4B0);
PPC_FUNC_IMPL(__imp__sub_826BF4B0) {
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826bf4f4
	if (!cr6.eq) goto loc_826BF4F4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-12768
	ctx.r3.s64 = r11.s64 + -12768;
	// bl 0x82130000
	ctx.lr = 0x826BF4DC;
	sub_82130000(ctx, base);
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
loc_826BF4F4:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826BF4FC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826bda38
	ctx.lr = 0x826BF508;
	sub_826BDA38(ctx, base);
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

__attribute__((alias("__imp__sub_826BF51C"))) PPC_WEAK_FUNC(sub_826BF51C);
PPC_FUNC_IMPL(__imp__sub_826BF51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BF520"))) PPC_WEAK_FUNC(sub_826BF520);
PPC_FUNC_IMPL(__imp__sub_826BF520) {
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
	ctx.lr = 0x826BF528;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf550
	if (!cr6.eq) goto loc_826BF550;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x826BF550;
	sub_82608A98(ctx, base);
loc_826BF550:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x826bf580
	if (!cr6.eq) goto loc_826BF580;
	// bl 0x821c9438
	ctx.lr = 0x826BF574;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826bd178
	ctx.lr = 0x826BF580;
	sub_826BD178(ctx, base);
loc_826BF580:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r3,44
	ctx.r3.s64 = 44;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r11,0
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r29,r6,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r29,r9
	r28.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x826BF5AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bf5e8
	if (cr6.eq) goto loc_826BF5E8;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826BF5CC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826bf5cc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826BF5CC;
	// stw r28,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r28.u32);
	// b 0x826bf5ec
	goto loc_826BF5EC;
loc_826BF5E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826BF5EC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r3,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826BF604"))) PPC_WEAK_FUNC(sub_826BF604);
PPC_FUNC_IMPL(__imp__sub_826BF604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BF608"))) PPC_WEAK_FUNC(sub_826BF608);
PPC_FUNC_IMPL(__imp__sub_826BF608) {
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
	ctx.lr = 0x826BF610;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf638
	if (!cr6.eq) goto loc_826BF638;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x826BF638;
	sub_82608A98(ctx, base);
loc_826BF638:
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x826bf668
	if (!cr6.eq) goto loc_826BF668;
	// bl 0x821c9438
	ctx.lr = 0x826BF65C;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826bd250
	ctx.lr = 0x826BF668;
	sub_826BD250(ctx, base);
loc_826BF668:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r3,272
	ctx.r3.s64 = 272;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// twllei r11,0
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r29,r6,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r29,r9
	r28.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x826BF694;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826bf6c0
	if (cr6.eq) goto loc_826BF6C0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// li r5,264
	ctx.r5.s64 = 264;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x826BF6B8;
	sub_823DA950(ctx, base);
	// stw r28,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r28.u32);
	// b 0x826bf6c4
	goto loc_826BF6C4;
loc_826BF6C0:
	// li r31,0
	r31.s64 = 0;
loc_826BF6C4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r31,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, r31.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826BF6DC"))) PPC_WEAK_FUNC(sub_826BF6DC);
PPC_FUNC_IMPL(__imp__sub_826BF6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BF6E0"))) PPC_WEAK_FUNC(sub_826BF6E0);
PPC_FUNC_IMPL(__imp__sub_826BF6E0) {
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
	ctx.lr = 0x826BF6E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf710
	if (!cr6.eq) goto loc_826BF710;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x826BF710;
	sub_82608A98(ctx, base);
loc_826BF710:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x826bf740
	if (!cr6.eq) goto loc_826BF740;
	// bl 0x821c9438
	ctx.lr = 0x826BF734;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82217a98
	ctx.lr = 0x826BF740;
	sub_82217A98(ctx, base);
loc_826BF740:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r3,12
	ctx.r3.s64 = 12;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r11,0
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r30,r6,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r30,r9
	r29.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x826BF76C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826bf790
	if (cr6.eq) goto loc_826BF790;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lbz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// stb r9,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r9.u8);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// b 0x826bf794
	goto loc_826BF794;
loc_826BF790:
	// li r11,0
	r11.s64 = 0;
loc_826BF794:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r11,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r9
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826BF7AC"))) PPC_WEAK_FUNC(sub_826BF7AC);
PPC_FUNC_IMPL(__imp__sub_826BF7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826BF7B0"))) PPC_WEAK_FUNC(sub_826BF7B0);
PPC_FUNC_IMPL(__imp__sub_826BF7B0) {
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
	ctx.lr = 0x826BF7B8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r24,0
	r24.s64 = 0;
	// li r10,11
	ctx.r10.s64 = 11;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// addi r8,r30,356
	ctx.r8.s64 = r30.s64 + 356;
	// lbz r11,356(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 356);
	// addi r9,r30,8444
	ctx.r9.s64 = r30.s64 + 8444;
	// stw r24,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r24,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r24.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// lbz r7,357(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 357);
	// stb r7,1(r31)
	PPC_STORE_U8(r31.u32 + 1, ctx.r7.u8);
	// lbz r6,358(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 358);
	// stb r6,2(r31)
	PPC_STORE_U8(r31.u32 + 2, ctx.r6.u8);
	// lbz r5,359(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 359);
	// stb r5,3(r31)
	PPC_STORE_U8(r31.u32 + 3, ctx.r5.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stbx r10,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r10.u8);
	// lhz r10,8450(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 8450);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r27,r7,4
	r27.s64 = ctx.r7.s64 + 4;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// bl 0x82237920
	ctx.lr = 0x826BF83C;
	sub_82237920(ctx, base);
	// lwz r28,92(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826bf908
	if (cr6.eq) goto loc_826BF908;
	// lwz r25,96(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r26,88(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_826BF850:
	// lwz r29,4(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// add r3,r27,r31
	ctx.r3.u64 = r27.u64 + r31.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r29,48
	ctx.r4.s64 = r29.s64 + 48;
	// bl 0x823da950
	ctx.lr = 0x826BF864;
	sub_823DA950(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r10,32(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r9,4
	r11.s64 = ctx.r9.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r8,36(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// stwx r8,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r8.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r7,4
	r11.s64 = ctx.r7.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r6,40(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// stwx r6,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r6.u32);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r5,4
	r11.s64 = ctx.r5.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r4,44(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// stwx r4,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r4.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r27,r3,4
	r27.s64 = ctx.r3.s64 + 4;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// lwz r28,8(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x826bf850
	if (!cr6.eq) goto loc_826BF850;
	// lhz r9,4(r25)
	ctx.r9.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r26,1
	ctx.r10.s64 = r26.s64 + 1;
loc_826BF8D8:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x826bf900
	if (!cr6.lt) goto loc_826BF900;
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r28,r8,r11
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826bf8d8
	if (cr6.eq) goto loc_826BF8D8;
	// b 0x826bf850
	goto loc_826BF850;
loc_826BF900:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x826bf850
	if (!cr6.eq) goto loc_826BF850;
loc_826BF908:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826bab00
	ctx.lr = 0x826BF91C;
	sub_826BAB00(ctx, base);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10004(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10004);
	// bl 0x826c4a68
	ctx.lr = 0x826BF934;
	sub_826C4A68(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,8584
	ctx.r3.s64 = r30.s64 + 8584;
	// bl 0x826cdf30
	ctx.lr = 0x826BF944;
	sub_826CDF30(ctx, base);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addis r6,r30,1
	ctx.r6.s64 = r30.s64 + 65536;
	// ori r8,r10,25958
	ctx.r8.u64 = ctx.r10.u64 | 25958;
	// addi r6,r6,25952
	ctx.r6.s64 = ctx.r6.s64 + 25952;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// lhzx r7,r30,r8
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + ctx.r8.u32);
	// stwx r7,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r7.u32);
	// lhz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r7,r5,4
	ctx.r7.s64 = ctx.r5.s64 + 4;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// ble cr6,0x826bfa10
	if (!cr6.gt) goto loc_826BFA10;
	// lwz r8,0(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
loc_826BF980:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf9a0
	if (!cr6.eq) goto loc_826BF9A0;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x826bf980
	if (cr6.lt) goto loc_826BF980;
	// b 0x826bfa10
	goto loc_826BFA10;
loc_826BF9A0:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// stwx r10,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r10.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r7,4
	ctx.r10.s64 = ctx.r7.s64 + 4;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stbx r8,r10,r31
	PPC_STORE_U8(ctx.r10.u32 + r31.u32, ctx.r8.u8);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r7,r5,1
	ctx.r7.s64 = ctx.r5.s64 + 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf9a0
	if (!cr6.eq) goto loc_826BF9A0;
	// lhz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r6.u32 + 4);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
loc_826BF9E0:
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// bge cr6,0x826bfa08
	if (!cr6.lt) goto loc_826BFA08;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bf9e0
	if (cr6.eq) goto loc_826BF9E0;
	// b 0x826bf9a0
	goto loc_826BF9A0;
loc_826BFA08:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bf9a0
	if (!cr6.eq) goto loc_826BF9A0;
loc_826BFA10:
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r11,25968
	ctx.r9.u64 = r11.u64 | 25968;
	// ori r6,r10,25969
	ctx.r6.u64 = ctx.r10.u64 | 25969;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r3,r5,25970
	ctx.r3.u64 = ctx.r5.u64 | 25970;
	// lbzx r9,r30,r9
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + ctx.r9.u32);
	// ori r5,r4,25971
	ctx.r5.u64 = ctx.r4.u64 | 25971;
	// li r11,20
	r11.s64 = 20;
	// addis r8,r30,1
	ctx.r8.s64 = r30.s64 + 65536;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// addi r8,r8,25972
	ctx.r8.s64 = ctx.r8.s64 + 25972;
	// stbx r9,r7,r31
	PPC_STORE_U8(ctx.r7.u32 + r31.u32, ctx.r9.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r4,1
	ctx.r9.s64 = ctx.r4.s64 + 1;
	// lbzx r7,r30,r6
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + ctx.r6.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stbx r7,r9,r31
	PPC_STORE_U8(ctx.r9.u32 + r31.u32, ctx.r7.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r4,1
	ctx.r9.s64 = ctx.r4.s64 + 1;
	// lbzx r6,r30,r3
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + ctx.r3.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stbx r6,r9,r31
	PPC_STORE_U8(ctx.r9.u32 + r31.u32, ctx.r6.u8);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbzx r3,r30,r5
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + ctx.r5.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stbx r3,r9,r31
	PPC_STORE_U8(ctx.r9.u32 + r31.u32, ctx.r3.u8);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stwx r11,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, r11.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r6,4
	r11.s64 = ctx.r6.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_826BFAA0:
	// lbzx r9,r8,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r10,20
	cr6.compare<int32_t>(ctx.r10.s32, 20, xer);
	// stbx r9,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r9.u8);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// blt cr6,0x826bfaa0
	if (cr6.lt) goto loc_826BFAA0;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r8,9
	ctx.r8.s64 = 9;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// li r10,38
	ctx.r10.s64 = 38;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addis r11,r30,1
	r11.s64 = r30.s64 + 65536;
	// stwx r10,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, ctx.r10.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,26334
	r11.s64 = r11.s64 + 26334;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_826BFAF4:
	// li r9,38
	ctx.r9.s64 = 38;
loc_826BFAF8:
	// lbz r7,-342(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + -342);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stbx r7,r10,r31
	PPC_STORE_U8(ctx.r10.u32 + r31.u32, ctx.r7.u8);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stbx r6,r10,r31
	PPC_STORE_U8(ctx.r10.u32 + r31.u32, ctx.r6.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r4,1
	ctx.r10.s64 = ctx.r4.s64 + 1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bne 0x826bfaf8
	if (!cr0.eq) goto loc_826BFAF8;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x826bfaf4
	if (!cr0.eq) goto loc_826BFAF4;
	// lis r11,1
	r11.s64 = 65536;
	// addis r9,r30,1
	ctx.r9.s64 = r30.s64 + 65536;
	// ori r7,r11,26676
	ctx.r7.u64 = r11.u64 | 26676;
	// li r8,250
	ctx.r8.s64 = 250;
	// addi r9,r9,26680
	ctx.r9.s64 = ctx.r9.s64 + 26680;
	// lbzx r6,r30,r7
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + ctx.r7.u32);
	// stbx r6,r10,r31
	PPC_STORE_U8(ctx.r10.u32 + r31.u32, ctx.r6.u8);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_826BFB5C:
	// lbz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stbx r7,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r7.u8);
	// lbz r6,1(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// stb r6,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// lbz r5,2(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// lbz r4,3(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 3);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stb r4,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r4.u8);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bne 0x826bfb5c
	if (!cr0.eq) goto loc_826BFB5C;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r10,27680
	ctx.r8.u64 = ctx.r10.u64 | 27680;
	// ori r7,r9,27681
	ctx.r7.u64 = ctx.r9.u64 | 27681;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r3,r6,27682
	ctx.r3.u64 = ctx.r6.u64 | 27682;
	// lbzx r10,r30,r8
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + ctx.r8.u32);
	// ori r6,r9,27684
	ctx.r6.u64 = ctx.r9.u64 | 27684;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// addi r4,r30,248
	ctx.r4.s64 = r30.s64 + 248;
	// ori r8,r5,27683
	ctx.r8.u64 = ctx.r5.u64 | 27683;
	// li r5,80
	ctx.r5.s64 = 80;
	// stbx r10,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r10.u8);
	// lbzx r10,r30,r7
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + ctx.r7.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stbx r10,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r10.u8);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbzx r9,r30,r3
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + ctx.r3.u32);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stbx r9,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r9.u8);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbzx r10,r30,r8
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + ctx.r8.u32);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stbx r10,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r10.u8);
	// lbzx r9,r30,r6
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + ctx.r6.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stbx r9,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r9.u8);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r7,1
	r11.s64 = ctx.r7.s64 + 1;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x826BFC34;
	sub_823DA950(ctx, base);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addis r4,r30,1
	ctx.r4.s64 = r30.s64 + 65536;
	// addi r11,r6,80
	r11.s64 = ctx.r6.s64 + 80;
	// addi r4,r4,27688
	ctx.r4.s64 = ctx.r4.s64 + 27688;
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x823da950
	ctx.lr = 0x826BFC54;
	sub_823DA950(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r11,0
	r11.s64 = 0;
	// addi r3,r3,25948
	ctx.r3.s64 = ctx.r3.s64 + 25948;
	// addi r10,r10,60
	ctx.r10.s64 = ctx.r10.s64 + 60;
	// ori r29,r11,41360
	r29.u64 = r11.u64 | 41360;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addis r4,r30,1
	ctx.r4.s64 = r30.s64 + 65536;
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r4,-15420
	ctx.r4.s64 = ctx.r4.s64 + -15420;
	// stbx r9,r10,r31
	PPC_STORE_U8(ctx.r10.u32 + r31.u32, ctx.r9.u8);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,2(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,3(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x826BFCB4;
	sub_823DA950(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,424(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 424);
	// mr r28,r24
	r28.u64 = r24.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r29,8(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826bfcfc
	if (cr6.eq) goto loc_826BFCFC;
loc_826BFCD4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82727ab8
	ctx.lr = 0x826BFCDC;
	sub_82727AB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bfcec
	if (!cr6.eq) goto loc_826BFCEC;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_826BFCEC:
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826bfcd4
	if (!cr6.eq) goto loc_826BFCD4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_826BFCFC:
	// stwx r28,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r28.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r9,424(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 424);
	// lwz r27,8(r9)
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826bfdf0
	if (cr6.eq) goto loc_826BFDF0;
loc_826BFD1C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82727ab8
	ctx.lr = 0x826BFD24;
	sub_82727AB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bfde4
	if (!cr6.eq) goto loc_826BFDE4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82618698
	ctx.lr = 0x826BFD38;
	sub_82618698(ctx, base);
	// bl 0x82554d48
	ctx.lr = 0x826BFD3C;
	sub_82554D48(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,24(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r9,4
	r11.s64 = ctx.r9.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r10,28(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_826BFD60:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826bfd60
	if (!cr6.eq) goto loc_826BFD60;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r29,r10,0
	r29.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r29,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r29.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r9,4
	r11.s64 = ctx.r9.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwz r4,28(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// bl 0x823da950
	ctx.lr = 0x826BFD9C;
	sub_823DA950(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r29,r8
	r11.u64 = r29.u64 + ctx.r8.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r29,88(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 88);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stwx r29,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r29.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r7,4
	r11.s64 = ctx.r7.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwz r10,80(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// lwz r6,92(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 92);
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bl 0x823da950
	ctx.lr = 0x826BFDD8;
	sub_823DA950(ctx, base);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r4,r29,r5
	ctx.r4.u64 = r29.u64 + ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
loc_826BFDE4:
	// lwz r27,4(r27)
	r27.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x826bfd1c
	if (!cr6.eq) goto loc_826BFD1C;
loc_826BFDF0:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r10,r11,-28304
	ctx.r10.s64 = r11.s64 + -28304;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826bffb8
	if (cr6.eq) goto loc_826BFFB8;
	// lwz r11,428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 428);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826bffb8
	if (cr6.eq) goto loc_826BFFB8;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// mr r29,r24
	r29.u64 = r24.u64;
	// ori r9,r10,18928
	ctx.r9.u64 = ctx.r10.u64 | 18928;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r28,8(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826bfe54
	if (cr6.eq) goto loc_826BFE54;
loc_826BFE30:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82727ab8
	ctx.lr = 0x826BFE38;
	sub_82727AB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bfe48
	if (!cr6.eq) goto loc_826BFE48;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_826BFE48:
	// lwz r28,4(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x826bfe30
	if (!cr6.eq) goto loc_826BFE30;
loc_826BFE54:
	// li r6,60
	ctx.r6.s64 = 60;
	// lwz r3,-10004(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10004);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826c4590
	ctx.lr = 0x826BFE68;
	sub_826C4590(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bgt cr6,0x826bfe94
	if (cr6.gt) goto loc_826BFE94;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x826bfe94
	if (cr6.gt) goto loc_826BFE94;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r11,r24
	r11.u64 = r24.u64;
	// lis r3,3
	ctx.r3.s64 = 196608;
	// ori r3,r3,3392
	ctx.r3.u64 = ctx.r3.u64 | 3392;
	// stwx r11,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_826BFE94:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,1
	r11.s64 = 1;
	// li r6,60
	ctx.r6.s64 = 60;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stwx r11,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r11.u32);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,-10004(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10004);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x826c4a68
	ctx.lr = 0x826BFEC0;
	sub_826C4A68(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stwx r29,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, r29.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r7,428(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 428);
	// addi r6,r8,4
	ctx.r6.s64 = ctx.r8.s64 + 4;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lwz r28,8(r7)
	r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826bffb8
	if (cr6.eq) goto loc_826BFFB8;
loc_826BFEE4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82727ab8
	ctx.lr = 0x826BFEEC;
	sub_82727AB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826bffac
	if (!cr6.eq) goto loc_826BFFAC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618698
	ctx.lr = 0x826BFF00;
	sub_82618698(ctx, base);
	// bl 0x82554d48
	ctx.lr = 0x826BFF04;
	sub_82554D48(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r9,4
	r11.s64 = ctx.r9.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r10,28(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_826BFF28:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826bff28
	if (!cr6.eq) goto loc_826BFF28;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r30,r10,0
	r30.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stwx r30,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r30.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r9,4
	r11.s64 = ctx.r9.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwz r4,28(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// bl 0x823da950
	ctx.lr = 0x826BFF64;
	sub_823DA950(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r30,r8
	r11.u64 = r30.u64 + ctx.r8.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r30,88(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 88);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stwx r30,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r30.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r7,4
	r11.s64 = ctx.r7.s64 + 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwz r10,80(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// lwz r6,92(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bl 0x823da950
	ctx.lr = 0x826BFFA0;
	sub_823DA950(ctx, base);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r4,r30,r5
	ctx.r4.u64 = r30.u64 + ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
loc_826BFFAC:
	// lwz r28,4(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x826bfee4
	if (!cr6.eq) goto loc_826BFEE4;
loc_826BFFB8:
	// lis r3,3
	ctx.r3.s64 = 196608;
	// ori r3,r3,3392
	ctx.r3.u64 = ctx.r3.u64 | 3392;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826BFFC8"))) PPC_WEAK_FUNC(sub_826BFFC8);
PPC_FUNC_IMPL(__imp__sub_826BFFC8) {
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
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x826bcce0
	ctx.lr = 0x826BFFF0;
	sub_826BCCE0(ctx, base);
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

__attribute__((alias("__imp__sub_826C000C"))) PPC_WEAK_FUNC(sub_826C000C);
PPC_FUNC_IMPL(__imp__sub_826C000C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0010"))) PPC_WEAK_FUNC(sub_826C0010);
PPC_FUNC_IMPL(__imp__sub_826C0010) {
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
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,436(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 436);
	// bl 0x82727908
	ctx.lr = 0x826C004C;
	sub_82727908(ctx, base);
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

__attribute__((alias("__imp__sub_826C0068"))) PPC_WEAK_FUNC(sub_826C0068);
PPC_FUNC_IMPL(__imp__sub_826C0068) {
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
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,440(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 440);
	// bl 0x82727908
	ctx.lr = 0x826C00A4;
	sub_82727908(ctx, base);
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

__attribute__((alias("__imp__sub_826C00C0"))) PPC_WEAK_FUNC(sub_826C00C0);
PPC_FUNC_IMPL(__imp__sub_826C00C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r11,-27328
	ctx.r8.s64 = r11.s64 + -27328;
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c00ec
	if (cr6.eq) goto loc_826C00EC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// b 0x826c00f0
	goto loc_826C00F0;
loc_826C00EC:
	// li r11,0
	r11.s64 = 0;
loc_826C00F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C0110"))) PPC_WEAK_FUNC(sub_826C0110);
PPC_FUNC_IMPL(__imp__sub_826C0110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826c8b00
	sub_826C8B00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C011C"))) PPC_WEAK_FUNC(sub_826C011C);
PPC_FUNC_IMPL(__imp__sub_826C011C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0120"))) PPC_WEAK_FUNC(sub_826C0120);
PPC_FUNC_IMPL(__imp__sub_826C0120) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10020(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// addi r3,r11,8748
	ctx.r3.s64 = r11.s64 + 8748;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x826bde10
	ctx.lr = 0x826C0154;
	sub_826BDE10(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x826c0168
	if (!cr6.eq) goto loc_826C0168;
	// li r11,0
	r11.s64 = 0;
loc_826C0168:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_826C0180"))) PPC_WEAK_FUNC(sub_826C0180);
PPC_FUNC_IMPL(__imp__sub_826C0180) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10020(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// addi r3,r11,8748
	ctx.r3.s64 = r11.s64 + 8748;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x826bde10
	ctx.lr = 0x826C01B4;
	sub_826BDE10(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,132
	r11.s64 = ctx.r3.s64 + 132;
	// bne cr6,0x826c01c8
	if (!cr6.eq) goto loc_826C01C8;
	// li r11,0
	r11.s64 = 0;
loc_826C01C8:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_826C01E0"))) PPC_WEAK_FUNC(sub_826C01E0);
PPC_FUNC_IMPL(__imp__sub_826C01E0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c022c
	if (cr6.eq) goto loc_826C022C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826be5e8
	ctx.lr = 0x826C0210;
	sub_826BE5E8(ctx, base);
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
loc_826C022C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14736
	ctx.r3.s64 = r11.s64 + -14736;
	// bl 0x82130000
	ctx.lr = 0x826C0238;
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

__attribute__((alias("__imp__sub_826C0258"))) PPC_WEAK_FUNC(sub_826C0258);
PPC_FUNC_IMPL(__imp__sub_826C0258) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c02a8
	if (cr6.eq) goto loc_826C02A8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826be728
	ctx.lr = 0x826C028C;
	sub_826BE728(ctx, base);
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
loc_826C02A8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14648
	ctx.r3.s64 = r11.s64 + -14648;
	// bl 0x82130000
	ctx.lr = 0x826C02B4;
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

__attribute__((alias("__imp__sub_826C02D4"))) PPC_WEAK_FUNC(sub_826C02D4);
PPC_FUNC_IMPL(__imp__sub_826C02D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C02D8"))) PPC_WEAK_FUNC(sub_826C02D8);
PPC_FUNC_IMPL(__imp__sub_826C02D8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// beq cr6,0x826c032c
	if (cr6.eq) goto loc_826C032C;
	// bl 0x826be7f0
	ctx.lr = 0x826C0310;
	sub_826BE7F0(ctx, base);
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
loc_826C032C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14480
	ctx.r3.s64 = r11.s64 + -14480;
	// bl 0x82130000
	ctx.lr = 0x826C0338;
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

__attribute__((alias("__imp__sub_826C0358"))) PPC_WEAK_FUNC(sub_826C0358);
PPC_FUNC_IMPL(__imp__sub_826C0358) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// beq cr6,0x826c03ac
	if (cr6.eq) goto loc_826C03AC;
	// bl 0x826be950
	ctx.lr = 0x826C0390;
	sub_826BE950(ctx, base);
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
loc_826C03AC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14320
	ctx.r3.s64 = r11.s64 + -14320;
	// bl 0x82130000
	ctx.lr = 0x826C03B8;
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

__attribute__((alias("__imp__sub_826C03D8"))) PPC_WEAK_FUNC(sub_826C03D8);
PPC_FUNC_IMPL(__imp__sub_826C03D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c03fc
	if (cr6.eq) goto loc_826C03FC;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x826beab8
	sub_826BEAB8(ctx, base);
	return;
loc_826C03FC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-14144
	ctx.r3.s64 = r11.s64 + -14144;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C0408"))) PPC_WEAK_FUNC(sub_826C0408);
PPC_FUNC_IMPL(__imp__sub_826C0408) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c0458
	if (cr6.eq) goto loc_826C0458;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826bec18
	ctx.lr = 0x826C043C;
	sub_826BEC18(ctx, base);
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
loc_826C0458:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-13952
	ctx.r3.s64 = r11.s64 + -13952;
	// bl 0x82130000
	ctx.lr = 0x826C0464;
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

__attribute__((alias("__imp__sub_826C0484"))) PPC_WEAK_FUNC(sub_826C0484);
PPC_FUNC_IMPL(__imp__sub_826C0484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0488"))) PPC_WEAK_FUNC(sub_826C0488);
PPC_FUNC_IMPL(__imp__sub_826C0488) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// beq cr6,0x826c04d8
	if (cr6.eq) goto loc_826C04D8;
	// bl 0x826becf0
	ctx.lr = 0x826C04BC;
	sub_826BECF0(ctx, base);
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
loc_826C04D8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-13656
	ctx.r3.s64 = r11.s64 + -13656;
	// bl 0x82130000
	ctx.lr = 0x826C04E4;
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

__attribute__((alias("__imp__sub_826C0504"))) PPC_WEAK_FUNC(sub_826C0504);
PPC_FUNC_IMPL(__imp__sub_826C0504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0508"))) PPC_WEAK_FUNC(sub_826C0508);
PPC_FUNC_IMPL(__imp__sub_826C0508) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// beq cr6,0x826c0558
	if (cr6.eq) goto loc_826C0558;
	// bl 0x826bedf0
	ctx.lr = 0x826C053C;
	sub_826BEDF0(ctx, base);
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
loc_826C0558:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-13480
	ctx.r3.s64 = r11.s64 + -13480;
	// bl 0x82130000
	ctx.lr = 0x826C0564;
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

__attribute__((alias("__imp__sub_826C0584"))) PPC_WEAK_FUNC(sub_826C0584);
PPC_FUNC_IMPL(__imp__sub_826C0584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0588"))) PPC_WEAK_FUNC(sub_826C0588);
PPC_FUNC_IMPL(__imp__sub_826C0588) {
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
	// b 0x826beeb8
	sub_826BEEB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C05A8"))) PPC_WEAK_FUNC(sub_826C05A8);
PPC_FUNC_IMPL(__imp__sub_826C05A8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x826c05dc
	if (cr6.eq) goto loc_826C05DC;
	// bl 0x826bef40
	ctx.lr = 0x826C05D8;
	sub_826BEF40(ctx, base);
	// b 0x826c05ec
	goto loc_826C05EC;
loc_826C05DC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-13104
	ctx.r3.s64 = r11.s64 + -13104;
	// bl 0x82130000
	ctx.lr = 0x826C05E8;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C05EC:
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

__attribute__((alias("__imp__sub_826C060C"))) PPC_WEAK_FUNC(sub_826C060C);
PPC_FUNC_IMPL(__imp__sub_826C060C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0610"))) PPC_WEAK_FUNC(sub_826C0610);
PPC_FUNC_IMPL(__imp__sub_826C0610) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10020(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r3,25964
	ctx.r3.s64 = ctx.r3.s64 + 25964;
	// bl 0x826bde70
	ctx.lr = 0x826C0648;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c0658
	if (cr6.eq) goto loc_826C0658;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// b 0x826c065c
	goto loc_826C065C;
loc_826C0658:
	// li r11,0
	r11.s64 = 0;
loc_826C065C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_826C067C"))) PPC_WEAK_FUNC(sub_826C067C);
PPC_FUNC_IMPL(__imp__sub_826C067C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0680"))) PPC_WEAK_FUNC(sub_826C0680);
PPC_FUNC_IMPL(__imp__sub_826C0680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// b 0x826befb8
	sub_826BEFB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C06A8"))) PPC_WEAK_FUNC(sub_826C06A8);
PPC_FUNC_IMPL(__imp__sub_826C06A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// ori r7,r8,25976
	ctx.r7.u64 = ctx.r8.u64 | 25976;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r11,r4,1
	r11.u64 = ctx.r4.u64 ^ 1;
	// stbx r11,r3,r7
	PPC_STORE_U8(ctx.r3.u32 + ctx.r7.u32, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C06DC"))) PPC_WEAK_FUNC(sub_826C06DC);
PPC_FUNC_IMPL(__imp__sub_826C06DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C06E0"))) PPC_WEAK_FUNC(sub_826C06E0);
PPC_FUNC_IMPL(__imp__sub_826C06E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// b 0x826bcee8
	sub_826BCEE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C06FC"))) PPC_WEAK_FUNC(sub_826C06FC);
PPC_FUNC_IMPL(__imp__sub_826C06FC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C0700"))) PPC_WEAK_FUNC(sub_826C0700);
PPC_FUNC_IMPL(__imp__sub_826C0700) {
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
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c0734
	if (cr6.eq) goto loc_826C0734;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826bf4b0
	ctx.lr = 0x826C0730;
	sub_826BF4B0(ctx, base);
	// b 0x826c0738
	goto loc_826C0738;
loc_826C0734:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C0738:
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

__attribute__((alias("__imp__sub_826C0758"))) PPC_WEAK_FUNC(sub_826C0758);
PPC_FUNC_IMPL(__imp__sub_826C0758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x826be380
	sub_826BE380(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C076C"))) PPC_WEAK_FUNC(sub_826C076C);
PPC_FUNC_IMPL(__imp__sub_826C076C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0770"))) PPC_WEAK_FUNC(sub_826C0770);
PPC_FUNC_IMPL(__imp__sub_826C0770) {
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
	ctx.lr = 0x826C0778;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c07c4
	if (cr6.eq) goto loc_826C07C4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x826C07A0;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,444
	ctx.r3.s64 = r30.s64 + 444;
	// bl 0x826bdd50
	ctx.lr = 0x826C07B0;
	sub_826BDD50(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c07c4
	if (cr6.eq) goto loc_826C07C4;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c0800
	if (!cr6.eq) goto loc_826C0800;
loc_826C07C4:
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x823db670
	ctx.lr = 0x826C07D8;
	sub_823DB670(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x826C07E4;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,444
	ctx.r3.s64 = r30.s64 + 444;
	// bl 0x826bf520
	ctx.lr = 0x826C07F8;
	sub_826BF520(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
loc_826C0800:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-12696
	ctx.r3.s64 = r11.s64 + -12696;
	// bl 0x82130000
	ctx.lr = 0x826C080C;
	sub_82130000(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826C0814"))) PPC_WEAK_FUNC(sub_826C0814);
PPC_FUNC_IMPL(__imp__sub_826C0814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0818"))) PPC_WEAK_FUNC(sub_826C0818);
PPC_FUNC_IMPL(__imp__sub_826C0818) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r31,-10020(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// beq cr6,0x826c0870
	if (cr6.eq) goto loc_826C0870;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826C0840;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,444
	ctx.r3.s64 = r31.s64 + 444;
	// bl 0x826bdd50
	ctx.lr = 0x826C0850;
	sub_826BDD50(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c0870
	if (cr6.eq) goto loc_826C0870;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
loc_826C0870:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_826C0888"))) PPC_WEAK_FUNC(sub_826C0888);
PPC_FUNC_IMPL(__imp__sub_826C0888) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x826C0890;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r19,r11,30576
	r19.s64 = r11.s64 + 30576;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// addi r4,r10,-16884
	ctx.r4.s64 = ctx.r10.s64 + -16884;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821ca540
	ctx.lr = 0x826C08B0;
	sub_821CA540(ctx, base);
	// li r18,0
	r18.s64 = 0;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r20,r18
	r20.u64 = r18.u64;
	// addi r21,r4,-30140
	r21.s64 = ctx.r4.s64 + -30140;
	// addi r25,r5,-29924
	r25.s64 = ctx.r5.s64 + -29924;
	// addi r28,r6,9848
	r28.s64 = ctx.r6.s64 + 9848;
	// addi r27,r7,-29624
	r27.s64 = ctx.r7.s64 + -29624;
	// addi r29,r8,-12544
	r29.s64 = ctx.r8.s64 + -12544;
	// addi r24,r9,-12560
	r24.s64 = ctx.r9.s64 + -12560;
	// addi r23,r10,-32764
	r23.s64 = ctx.r10.s64 + -32764;
	// addi r22,r11,-12572
	r22.s64 = r11.s64 + -12572;
loc_826C08F8:
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x826C090C;
	sub_82137A08(ctx, base);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// bl 0x821ca6a8
	ctx.lr = 0x826C0924;
	sub_821CA6A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x826c0a8c
	if (cr6.eq) goto loc_826C0A8C;
	// stw r25,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// stw r18,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, r18.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cf7b8
	ctx.lr = 0x826C0948;
	sub_821CF7B8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cff40
	ctx.lr = 0x826C0958;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0a80
	if (cr6.eq) goto loc_826C0A80;
	// addi r30,r17,8456
	r30.s64 = r17.s64 + 8456;
loc_826C0968:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cfe20
	ctx.lr = 0x826C0974;
	sub_821CFE20(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821d0898
	ctx.lr = 0x826C0980;
	sub_821D0898(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cfe20
	ctx.lr = 0x826C098C;
	sub_821CFE20(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cfaa8
	ctx.lr = 0x826C099C;
	sub_821CFAA8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9790
	ctx.lr = 0x826C09A8;
	sub_821C9790(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0a10
	if (cr6.eq) goto loc_826C0A10;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// twllei r11,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0a10
	if (cr6.eq) goto loc_826C0A10;
loc_826C09D8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x826c09f4
	if (cr6.eq) goto loc_826C09F4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c09d8
	if (!cr6.eq) goto loc_826C09D8;
	// b 0x826c0a10
	goto loc_826C0A10;
loc_826C09F4:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0a10
	if (cr6.eq) goto loc_826C0A10;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// bne cr6,0x826c0a38
	if (!cr6.eq) goto loc_826C0A38;
loc_826C0A10:
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x826C0A18;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c0a30
	if (cr6.eq) goto loc_826C0A30;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x826cd288
	ctx.lr = 0x826C0A28;
	sub_826CD288(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x826c0a34
	goto loc_826C0A34;
loc_826C0A30:
	// mr r31,r18
	r31.u64 = r18.u64;
loc_826C0A34:
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
loc_826C0A38:
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826cd370
	ctx.lr = 0x826C0A44;
	sub_826CD370(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82389998
	ctx.lr = 0x826C0A5C;
	sub_82389998(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821d0260
	ctx.lr = 0x826C0A64;
	sub_821D0260(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cff40
	ctx.lr = 0x826C0A74;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c0968
	if (!cr6.eq) goto loc_826C0968;
loc_826C0A80:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be610
	ctx.lr = 0x826C0A88;
	sub_821BE610(ctx, base);
	// stw r21,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r21.u32);
loc_826C0A8C:
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// cmpwi cr6,r20,5
	cr6.compare<int32_t>(r20.s32, 5, xer);
	// blt cr6,0x826c08f8
	if (cr6.lt) goto loc_826C08F8;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826C0AA0;
	sub_821C9A90(ctx, base);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_826C0AA8"))) PPC_WEAK_FUNC(sub_826C0AA8);
PPC_FUNC_IMPL(__imp__sub_826C0AA8) {
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
	ctx.lr = 0x826C0AB0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,8456
	r31.s64 = ctx.r3.s64 + 8456;
	// li r30,0
	r30.s64 = 0;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// bl 0x82237920
	ctx.lr = 0x826C0AD0;
	sub_82237920(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0b4c
	if (cr6.eq) goto loc_826C0B4C;
loc_826C0ADC:
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,80(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x822b7bd0
	ctx.lr = 0x826C0AF4;
	sub_822B7BD0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826cd318
	ctx.lr = 0x826C0AFC;
	sub_826CD318(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826C0B04;
	sub_82130588(ctx, base);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826c0b38
	if (!cr6.gt) goto loc_826C0B38;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_826C0B1C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c0b38
	if (!cr6.eq) goto loc_826C0B38;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x826c0b1c
	if (cr6.lt) goto loc_826C0B1C;
loc_826C0B38:
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c0adc
	if (!cr6.eq) goto loc_826C0ADC;
loc_826C0B4C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826C0B54"))) PPC_WEAK_FUNC(sub_826C0B54);
PPC_FUNC_IMPL(__imp__sub_826C0B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0B58"))) PPC_WEAK_FUNC(sub_826C0B58);
PPC_FUNC_IMPL(__imp__sub_826C0B58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x826C0B60;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r3,8748
	r30.s64 = ctx.r3.s64 + 8748;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, r31.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x826bde10
	ctx.lr = 0x826C0B8C;
	sub_826BDE10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826c0bcc
	if (!cr6.eq) goto loc_826C0BCC;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r27,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r27.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x823db670
	ctx.lr = 0x826C0BAC;
	sub_823DB670(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,228
	ctx.r3.s64 = ctx.r1.s64 + 228;
	// bl 0x823db670
	ctx.lr = 0x826C0BBC;
	sub_823DB670(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,444
	ctx.r4.s64 = ctx.r1.s64 + 444;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826bf608
	ctx.lr = 0x826C0BCC;
	sub_826BF608(ctx, base);
loc_826C0BCC:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826C0BD4"))) PPC_WEAK_FUNC(sub_826C0BD4);
PPC_FUNC_IMPL(__imp__sub_826C0BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0BD8"))) PPC_WEAK_FUNC(sub_826C0BD8);
PPC_FUNC_IMPL(__imp__sub_826C0BD8) {
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
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stb r31,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r31.u8);
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// addis r30,r11,1
	r30.s64 = r11.s64 + 65536;
	// addi r30,r30,25964
	r30.s64 = r30.s64 + 25964;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826bde70
	ctx.lr = 0x826C0C14;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c0c24
	if (cr6.eq) goto loc_826C0C24;
	// stb r31,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r31.u8);
	// b 0x826c0c34
	goto loc_826C0C34;
loc_826C0C24:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826bf6e0
	ctx.lr = 0x826C0C34;
	sub_826BF6E0(ctx, base);
loc_826C0C34:
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

__attribute__((alias("__imp__sub_826C0C4C"))) PPC_WEAK_FUNC(sub_826C0C4C);
PPC_FUNC_IMPL(__imp__sub_826C0C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0C50"))) PPC_WEAK_FUNC(sub_826C0C50);
PPC_FUNC_IMPL(__imp__sub_826C0C50) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,-12428
	ctx.r3.s64 = r11.s64 + -12428;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x826C0C88;
	sub_82727908(ctx, base);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// stw r3,436(r30)
	PPC_STORE_U32(r30.u32 + 436, ctx.r3.u32);
	// addi r9,r10,-28304
	ctx.r9.s64 = ctx.r10.s64 + -28304;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r8,r11,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826c0cc8
	if (cr6.eq) goto loc_826C0CC8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,-12456
	ctx.r3.s64 = r11.s64 + -12456;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x826C0CC4;
	sub_82727908(ctx, base);
	// stw r3,440(r30)
	PPC_STORE_U32(r30.u32 + 440, ctx.r3.u32);
loc_826C0CC8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c6580
	ctx.lr = 0x826C0CD4;
	sub_826C6580(ctx, base);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x826C0CDC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c0cf8
	if (cr6.eq) goto loc_826C0CF8;
	// bl 0x826cb938
	ctx.lr = 0x826C0CEC;
	sub_826CB938(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// stw r31,24996(r11)
	PPC_STORE_U32(r11.u32 + 24996, r31.u32);
	// b 0x826c0d04
	goto loc_826C0D04;
loc_826C0CF8:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// stw r11,24996(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24996, r11.u32);
loc_826C0D04:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c0888
	ctx.lr = 0x826C0D0C;
	sub_826C0888(ctx, base);
	// addi r3,r30,8596
	ctx.r3.s64 = r30.s64 + 8596;
	// bl 0x826d0168
	ctx.lr = 0x826C0D14;
	sub_826D0168(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r11,27787
	ctx.r9.u64 = r11.u64 | 27787;
	// ori r8,r10,27788
	ctx.r8.u64 = ctx.r10.u64 | 27788;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stbx r7,r30,r9
	PPC_STORE_U8(r30.u32 + ctx.r9.u32, ctx.r7.u8);
	// stbx r6,r30,r8
	PPC_STORE_U8(r30.u32 + ctx.r8.u32, ctx.r6.u8);
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

__attribute__((alias("__imp__sub_826C0D4C"))) PPC_WEAK_FUNC(sub_826C0D4C);
PPC_FUNC_IMPL(__imp__sub_826C0D4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C0D50"))) PPC_WEAK_FUNC(sub_826C0D50);
PPC_FUNC_IMPL(__imp__sub_826C0D50) {
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
	ctx.lr = 0x826C0D58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32112
	r28.s64 = -2104492032;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,24996(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 24996);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c0d80
	if (cr6.eq) goto loc_826C0D80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cbdd8
	ctx.lr = 0x826C0D78;
	sub_826CBDD8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x826C0D80;
	sub_82130588(ctx, base);
loc_826C0D80:
	// li r29,0
	r29.s64 = 0;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,24996(r28)
	PPC_STORE_U32(r28.u32 + 24996, r11.u32);
	// lwz r3,-10004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10004);
	// bl 0x826c6158
	ctx.lr = 0x826C0D98;
	sub_826C6158(ctx, base);
	// lwz r3,-10004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10004);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c0db8
	if (cr6.eq) goto loc_826C0DB8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C0DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826C0DB8:
	// mr r11,r29
	r11.u64 = r29.u64;
	// stw r11,-10004(r30)
	PPC_STORE_U32(r30.u32 + -10004, r11.u32);
	// lwz r3,436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 436);
	// bl 0x821f8480
	ctx.lr = 0x826C0DC8;
	sub_821F8480(ctx, base);
	// stw r29,436(r31)
	PPC_STORE_U32(r31.u32 + 436, r29.u32);
	// lwz r3,440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 440);
	// bl 0x821f8480
	ctx.lr = 0x826C0DD4;
	sub_821F8480(ctx, base);
	// stw r29,440(r31)
	PPC_STORE_U32(r31.u32 + 440, r29.u32);
	// addi r3,r31,8596
	ctx.r3.s64 = r31.s64 + 8596;
	// bl 0x826cff48
	ctx.lr = 0x826C0DE0;
	sub_826CFF48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c0aa8
	ctx.lr = 0x826C0DE8;
	sub_826C0AA8(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r11,27787
	ctx.r9.u64 = r11.u64 | 27787;
	// ori r8,r10,27788
	ctx.r8.u64 = ctx.r10.u64 | 27788;
	// stbx r29,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r29.u8);
	// stbx r29,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r29.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826C0E08"))) PPC_WEAK_FUNC(sub_826C0E08);
PPC_FUNC_IMPL(__imp__sub_826C0E08) {
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
	ctx.lr = 0x826C0E10;
	// addi r31,r1,-320
	r31.s64 = ctx.r1.s64 + -320;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r23,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r23.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lbz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r11,r26,356
	r11.s64 = r26.s64 + 356;
	// stb r8,356(r26)
	PPC_STORE_U8(r26.u32 + 356, ctx.r8.u8);
	// mr r22,r23
	r22.u64 = r23.u64;
	// lbz r7,1(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// stb r7,357(r26)
	PPC_STORE_U8(r26.u32 + 357, ctx.r7.u8);
	// lbz r6,2(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// stb r6,358(r26)
	PPC_STORE_U8(r26.u32 + 358, ctx.r6.u8);
	// lbz r5,3(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// stb r5,359(r26)
	PPC_STORE_U8(r26.u32 + 359, ctx.r5.u8);
	// lbz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r3,11
	cr6.compare<uint32_t>(ctx.r3.u32, 11, xer);
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// beq cr6,0x826c0e94
	if (cr6.eq) goto loc_826C0E94;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-12392
	ctx.r3.s64 = r11.s64 + -12392;
	// bl 0x82130000
	ctx.lr = 0x826C0E78;
	sub_82130000(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-12404
	ctx.r4.s64 = ctx.r9.s64 + -12404;
	// lwz r3,-10224(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826C0E90;
	sub_8268B770(ctx, base);
	// li r22,1
	r22.s64 = 1;
loc_826C0E94:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,27784
	ctx.r9.u64 = ctx.r10.u64 | 27784;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c0ec0
	if (!cr6.eq) goto loc_826C0EC0;
	// bl 0x82387a18
	ctx.lr = 0x826C0EB4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0ec4
	if (cr6.eq) goto loc_826C0EC4;
loc_826C0EC0:
	// li r22,1
	r22.s64 = 1;
loc_826C0EC4:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c1580
	if (!cr6.eq) goto loc_826C1580;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r29,r10,4
	r29.s64 = ctx.r10.s64 + 4;
	// lwzx r11,r10,r30
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// stw r29,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r29.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826c1020
	if (!cr6.gt) goto loc_826C1020;
	// addi r27,r26,8444
	r27.s64 = r26.s64 + 8444;
	// mr r25,r11
	r25.u64 = r11.u64;
	// b 0x826c0ef8
	goto loc_826C0EF8;
loc_826C0EF4:
	// lwz r29,80(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 80);
loc_826C0EF8:
	// add r4,r29,r30
	ctx.r4.u64 = r29.u64 + r30.u64;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x823da950
	ctx.lr = 0x826C0F08;
	sub_823DA950(ctx, base);
	// addi r11,r29,32
	r11.s64 = r29.s64 + 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x821c9790
	ctx.lr = 0x826C0F1C;
	sub_821C9790(ctx, base);
	// lhz r11,4(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0f64
	if (cr6.eq) goto loc_826C0F64;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// twllei r11,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0f64
	if (cr6.eq) goto loc_826C0F64;
loc_826C0F4C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x826c0f84
	if (cr6.eq) goto loc_826C0F84;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c0f4c
	if (!cr6.eq) goto loc_826C0F4C;
loc_826C0F64:
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x826C0F6C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c0fcc
	if (cr6.eq) goto loc_826C0FCC;
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// bl 0x826cd288
	ctx.lr = 0x826C0F7C;
	sub_826CD288(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x826c0fd0
	goto loc_826C0FD0;
loc_826C0F84:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c0f64
	if (cr6.eq) goto loc_826C0F64;
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826c0f64
	if (cr6.eq) goto loc_826C0F64;
	// mr r29,r23
	r29.u64 = r23.u64;
loc_826C0FA0:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r5,r11,r30
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// bl 0x826cd170
	ctx.lr = 0x826C0FBC;
	sub_826CD170(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x826c0fa0
	if (cr6.lt) goto loc_826C0FA0;
	// b 0x826c1018
	goto loc_826C1018;
loc_826C0FCC:
	// mr r28,r23
	r28.u64 = r23.u64;
loc_826C0FD0:
	// stw r28,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r28.u32);
	// mr r29,r23
	r29.u64 = r23.u64;
loc_826C0FD8:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r5,r11,r30
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// bl 0x826cd170
	ctx.lr = 0x826C0FF4;
	sub_826CD170(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x826c0fd8
	if (cr6.lt) goto loc_826C0FD8;
	// lwz r11,80(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// addi r5,r31,92
	ctx.r5.s64 = r31.s64 + 92;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// bl 0x82389998
	ctx.lr = 0x826C1018;
	sub_82389998(ctx, base);
loc_826C1018:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bne 0x826c0ef4
	if (!cr0.eq) goto loc_826C0EF4;
loc_826C1020:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r31,80
	ctx.r5.s64 = r31.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826bacf0
	ctx.lr = 0x826C1034;
	sub_826BACF0(ctx, base);
	// lis r24,-32121
	r24.s64 = -2105081856;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// addi r5,r31,80
	ctx.r5.s64 = r31.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10004(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10004);
	// bl 0x826c5db8
	ctx.lr = 0x826C104C;
	sub_826C5DB8(ctx, base);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// addi r5,r31,80
	ctx.r5.s64 = r31.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r26,8584
	ctx.r3.s64 = r26.s64 + 8584;
	// bl 0x826cdff8
	ctx.lr = 0x826C1060;
	sub_826CDFF8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826c110c
	if (!cr6.gt) goto loc_826C110C;
	// addi r9,r26,-12
	ctx.r9.s64 = r26.s64 + -12;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// addis r29,r9,1
	r29.s64 = ctx.r9.s64 + 65536;
	// addi r29,r29,25964
	r29.s64 = r29.s64 + 25964;
loc_826C1088:
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lbzx r8,r9,r30
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r30.u32);
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// stw r7,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r7.u32);
	// stb r8,84(r31)
	PPC_STORE_U8(r31.u32 + 84, ctx.r8.u8);
	// beq cr6,0x826c10f0
	if (cr6.eq) goto loc_826C10F0;
	// divwu r9,r10,r11
	ctx.r9.u32 = ctx.r10.u32 / r11.u32;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// twllei r11,0
	// mullw r6,r9,r11
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r5,r6,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r6.s64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r7
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c10f0
	if (cr6.eq) goto loc_826C10F0;
loc_826C10D8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// beq cr6,0x826c13ec
	if (cr6.eq) goto loc_826C13EC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c10d8
	if (!cr6.eq) goto loc_826C10D8;
loc_826C10F0:
	// addi r5,r31,84
	ctx.r5.s64 = r31.s64 + 84;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826bf6e0
	ctx.lr = 0x826C1100;
	sub_826BF6E0(ctx, base);
loc_826C1100:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bne 0x826c1088
	if (!cr0.eq) goto loc_826C1088;
loc_826C110C:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lbzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// ori r8,r10,25968
	ctx.r8.u64 = ctx.r10.u64 | 25968;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// ori r5,r7,25969
	ctx.r5.u64 = ctx.r7.u64 | 25969;
	// ori r4,r6,25970
	ctx.r4.u64 = ctx.r6.u64 | 25970;
	// stbx r9,r26,r8
	PPC_STORE_U8(r26.u32 + ctx.r8.u32, ctx.r9.u8);
	// lis r3,1
	ctx.r3.s64 = 65536;
	// lbzx r8,r11,r30
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// ori r9,r3,25971
	ctx.r9.u64 = ctx.r3.u64 | 25971;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// stbx r8,r26,r5
	PPC_STORE_U8(r26.u32 + ctx.r5.u32, ctx.r8.u8);
	// lbzx r7,r11,r30
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stbx r7,r26,r4
	PPC_STORE_U8(r26.u32 + ctx.r4.u32, ctx.r7.u8);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lbzx r6,r11,r30
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stbx r6,r26,r9
	PPC_STORE_U8(r26.u32 + ctx.r9.u32, ctx.r6.u8);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// ble cr6,0x826c11a8
	if (!cr6.gt) goto loc_826C11A8;
	// addis r8,r26,1
	ctx.r8.s64 = r26.s64 + 65536;
	// addi r8,r8,25972
	ctx.r8.s64 = ctx.r8.s64 + 25972;
loc_826C118C:
	// lbzx r7,r11,r30
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stbx r7,r8,r10
	PPC_STORE_U8(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826c118c
	if (cr6.lt) goto loc_826C118C;
loc_826C11A8:
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwzx r7,r11,r30
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// ble cr6,0x826c121c
	if (!cr6.gt) goto loc_826C121C;
	// addis r8,r26,1
	ctx.r8.s64 = r26.s64 + 65536;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// addi r8,r8,26334
	ctx.r8.s64 = ctx.r8.s64 + 26334;
loc_826C11D4:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x826c1210
	if (!cr6.gt) goto loc_826C1210;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_826C11E4:
	// lbzx r5,r9,r30
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + r30.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// stb r5,-342(r11)
	PPC_STORE_U8(r11.u32 + -342, ctx.r5.u8);
	// lbzx r4,r9,r30
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + r30.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r4,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r4.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// bne 0x826c11e4
	if (!cr0.eq) goto loc_826C11E4;
loc_826C1210:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r8,r8,38
	ctx.r8.s64 = ctx.r8.s64 + 38;
	// bne 0x826c11d4
	if (!cr0.eq) goto loc_826C11D4;
loc_826C121C:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lbzx r8,r9,r30
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r30.u32);
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// ori r7,r10,26676
	ctx.r7.u64 = ctx.r10.u64 | 26676;
	// addis r10,r26,1
	ctx.r10.s64 = r26.s64 + 65536;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// li r9,250
	ctx.r9.s64 = 250;
	// addi r10,r10,26680
	ctx.r10.s64 = ctx.r10.s64 + 26680;
	// stbx r8,r26,r7
	PPC_STORE_U8(r26.u32 + ctx.r7.u32, ctx.r8.u8);
loc_826C1240:
	// lbzx r8,r11,r30
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// add r7,r11,r30
	ctx.r7.u64 = r11.u64 + r30.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// lbz r6,1(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// stb r6,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// lbz r5,2(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// stb r5,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r5.u8);
	// lbz r4,3(r7)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + 3);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stb r4,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r4.u8);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x826c1240
	if (!cr0.eq) goto loc_826C1240;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lbzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// ori r8,r10,27680
	ctx.r8.u64 = ctx.r10.u64 | 27680;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// ori r4,r7,27681
	ctx.r4.u64 = ctx.r7.u64 | 27681;
	// ori r10,r6,27682
	ctx.r10.u64 = ctx.r6.u64 | 27682;
	// stbx r9,r26,r8
	PPC_STORE_U8(r26.u32 + ctx.r8.u32, ctx.r9.u8);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// ori r7,r9,27683
	ctx.r7.u64 = ctx.r9.u64 | 27683;
	// lbzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stbx r9,r26,r4
	PPC_STORE_U8(r26.u32 + ctx.r4.u32, ctx.r9.u8);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// ori r6,r8,27684
	ctx.r6.u64 = ctx.r8.u64 | 27684;
	// addi r3,r26,248
	ctx.r3.s64 = r26.s64 + 248;
	// li r5,80
	ctx.r5.s64 = 80;
	// lbzx r8,r11,r30
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stbx r8,r26,r10
	PPC_STORE_U8(r26.u32 + ctx.r10.u32, ctx.r8.u8);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lbzx r4,r11,r30
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stbx r4,r26,r7
	PPC_STORE_U8(r26.u32 + ctx.r7.u32, ctx.r4.u8);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lbzx r11,r11,r30
	r11.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// stw r29,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r29.u32);
	// add r4,r29,r30
	ctx.r4.u64 = r29.u64 + r30.u64;
	// stbx r11,r26,r6
	PPC_STORE_U8(r26.u32 + ctx.r6.u32, r11.u8);
	// bl 0x823da950
	ctx.lr = 0x826C1300;
	sub_823DA950(ctx, base);
	// addi r29,r29,80
	r29.s64 = r29.s64 + 80;
	// addis r3,r26,1
	ctx.r3.s64 = r26.s64 + 65536;
	// stw r29,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r29.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// add r4,r29,r30
	ctx.r4.u64 = r29.u64 + r30.u64;
	// addi r3,r3,27688
	ctx.r3.s64 = ctx.r3.s64 + 27688;
	// bl 0x823da950
	ctx.lr = 0x826C131C;
	sub_823DA950(ctx, base);
	// addis r10,r26,1
	ctx.r10.s64 = r26.s64 + 65536;
	// addi r11,r29,60
	r11.s64 = r29.s64 + 60;
	// addi r10,r10,25948
	ctx.r10.s64 = ctx.r10.s64 + 25948;
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// addi r29,r11,4
	r29.s64 = r11.s64 + 4;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lbzx r7,r11,r30
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + r30.u32);
	// addis r3,r26,1
	ctx.r3.s64 = r26.s64 + 65536;
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// ori r28,r8,41360
	r28.u64 = ctx.r8.u64 | 41360;
	// lbz r6,1(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 1);
	// addi r3,r3,-15420
	ctx.r3.s64 = ctx.r3.s64 + -15420;
	// stb r6,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// add r4,r29,r30
	ctx.r4.u64 = r29.u64 + r30.u64;
	// lbz r11,2(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stb r11,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, r11.u8);
	// lbz r9,3(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 3);
	// stw r29,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r29.u32);
	// stb r9,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r9.u8);
	// bl 0x823da950
	ctx.lr = 0x826C1374;
	sub_823DA950(ctx, base);
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// ble cr6,0x826c1458
	if (!cr6.gt) goto loc_826C1458;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
loc_826C1394:
	// lwzx r27,r11,r30
	r27.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// add r4,r28,r30
	ctx.r4.u64 = r28.u64 + r30.u64;
	// lwzx r29,r11,r30
	r29.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x826C13BC;
	sub_823DA950(ctx, base);
	// addi r9,r31,96
	ctx.r9.s64 = r31.s64 + 96;
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stbx r23,r29,r9
	PPC_STORE_U8(r29.u32 + ctx.r9.u32, r23.u8);
	// lwzx r29,r11,r30
	r29.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// bne cr6,0x826c1400
	if (!cr6.eq) goto loc_826C1400;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x826c1430
	goto loc_826C1430;
loc_826C13EC:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c10f0
	if (cr6.eq) goto loc_826C10F0;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// b 0x826c1100
	goto loc_826C1100;
loc_826C1400:
	// neg r11,r29
	r11.s64 = -r29.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826C140C;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + r30.u64;
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823da950
	ctx.lr = 0x826C1428;
	sub_823DA950(ctx, base);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_826C1430:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// lwz r4,424(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 424);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82727908
	ctx.lr = 0x826C1444;
	sub_82727908(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// bne 0x826c1394
	if (!cr0.eq) goto loc_826C1394;
loc_826C1458:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r10,r11,-28304
	ctx.r10.s64 = r11.s64 + -28304;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c1580
	if (cr6.eq) goto loc_826C1580;
	// lwz r11,428(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 428);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c1580
	if (cr6.eq) goto loc_826C1580;
	// lis r11,2
	r11.s64 = 131072;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// ori r11,r11,18928
	r11.u64 = r11.u64 | 18928;
	// ori r9,r10,18932
	ctx.r9.u64 = ctx.r10.u64 | 18932;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lwzx r8,r30,r11
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// bne cr6,0x826c1580
	if (!cr6.eq) goto loc_826C1580;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// lwz r3,-10004(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10004);
	// addi r5,r31,80
	ctx.r5.s64 = r31.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826c5db8
	ctx.lr = 0x826C14B4;
	sub_826C5DB8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826c1580
	if (!cr6.gt) goto loc_826C1580;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
loc_826C14D0:
	// lwzx r27,r11,r30
	r27.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// add r4,r28,r30
	ctx.r4.u64 = r28.u64 + r30.u64;
	// lwzx r29,r11,r30
	r29.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x826C14F8;
	sub_823DA950(ctx, base);
	// addi r9,r31,96
	ctx.r9.s64 = r31.s64 + 96;
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stbx r23,r29,r9
	PPC_STORE_U8(r29.u32 + ctx.r9.u32, r23.u8);
	// lwzx r29,r11,r30
	r29.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// bne cr6,0x826c1528
	if (!cr6.eq) goto loc_826C1528;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x826c1558
	goto loc_826C1558;
loc_826C1528:
	// neg r11,r29
	r11.s64 = -r29.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826C1534;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r10,r30
	ctx.r4.u64 = ctx.r10.u64 + r30.u64;
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823da950
	ctx.lr = 0x826C1550;
	sub_823DA950(ctx, base);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_826C1558:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// lwz r4,428(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 428);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82727908
	ctx.lr = 0x826C156C;
	sub_82727908(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// bne 0x826c14d0
	if (!cr0.eq) goto loc_826C14D0;
loc_826C1580:
	// addi r3,r26,-12
	ctx.r3.s64 = r26.s64 + -12;
	// bl 0x826bd328
	ctx.lr = 0x826C1588;
	sub_826BD328(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// lis r3,3
	ctx.r3.s64 = 196608;
	// ori r10,r11,27777
	ctx.r10.u64 = r11.u64 | 27777;
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r3,r3,3392
	ctx.r3.u64 = ctx.r3.u64 | 3392;
	// stbx r9,r26,r10
	PPC_STORE_U8(r26.u32 + ctx.r10.u32, ctx.r9.u8);
	// addi r1,r31,320
	ctx.r1.s64 = r31.s64 + 320;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_826C15A8"))) PPC_WEAK_FUNC(sub_826C15A8);
PPC_FUNC_IMPL(__imp__sub_826C15A8) {
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
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r30,-10020(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c1604
	if (cr6.eq) goto loc_826C1604;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826C15E0;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,444
	ctx.r3.s64 = r30.s64 + 444;
	// bl 0x826bdd50
	ctx.lr = 0x826C15F0;
	sub_826BDD50(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c1608
	if (cr6.eq) goto loc_826C1608;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// b 0x826c160c
	goto loc_826C160C;
loc_826C1604:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_826C1608:
	// li r11,0
	r11.s64 = 0;
loc_826C160C:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_826C1628"))) PPC_WEAK_FUNC(sub_826C1628);
PPC_FUNC_IMPL(__imp__sub_826C1628) {
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
	// bl 0x826c0818
	ctx.lr = 0x826C1648;
	sub_826C0818(ctx, base);
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

__attribute__((alias("__imp__sub_826C1664"))) PPC_WEAK_FUNC(sub_826C1664);
PPC_FUNC_IMPL(__imp__sub_826C1664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C1668"))) PPC_WEAK_FUNC(sub_826C1668);
PPC_FUNC_IMPL(__imp__sub_826C1668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c1690
	if (cr6.eq) goto loc_826C1690;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x826c0b58
	sub_826C0B58(ctx, base);
	return;
loc_826C1690:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-12536
	ctx.r3.s64 = r11.s64 + -12536;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C169C"))) PPC_WEAK_FUNC(sub_826C169C);
PPC_FUNC_IMPL(__imp__sub_826C169C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C16A0"))) PPC_WEAK_FUNC(sub_826C16A0);
PPC_FUNC_IMPL(__imp__sub_826C16A0) {
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
	// b 0x826c0bd8
	sub_826C0BD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C16C0"))) PPC_WEAK_FUNC(sub_826C16C0);
PPC_FUNC_IMPL(__imp__sub_826C16C0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x826C16C8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x826C16D4;
	sub_824E0648(ctx, base);
	// addi r23,r31,12
	r23.s64 = r31.s64 + 12;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8238d410
	ctx.lr = 0x826C16E0;
	sub_8238D410(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r9,r10,-21868
	ctx.r9.s64 = ctx.r10.s64 + -21868;
	// addi r24,r11,-28440
	r24.s64 = r11.s64 + -28440;
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
	// addi r29,r31,64
	r29.s64 = r31.s64 + 64;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x826C1708;
	sub_823DB670(ctx, base);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r5,r8,-12116
	ctx.r5.s64 = ctx.r8.s64 + -12116;
	// addi r4,r7,-12160
	ctx.r4.s64 = ctx.r7.s64 + -12160;
	// addi r11,r6,-12172
	r11.s64 = ctx.r6.s64 + -12172;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stw r4,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r4.u32);
	// addi r3,r31,340
	ctx.r3.s64 = r31.s64 + 340;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// bl 0x826c8650
	ctx.lr = 0x826C1734;
	sub_826C8650(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r27,r31,456
	r27.s64 = r31.s64 + 456;
	// stw r30,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r30.u32);
	// li r28,39
	r28.s64 = 39;
	// stw r30,368(r31)
	PPC_STORE_U32(r31.u32 + 368, r30.u32);
	// stw r30,436(r31)
	PPC_STORE_U32(r31.u32 + 436, r30.u32);
	// stw r30,440(r31)
	PPC_STORE_U32(r31.u32 + 440, r30.u32);
	// sth r30,450(r31)
	PPC_STORE_U16(r31.u32 + 450, r30.u16);
	// sth r30,448(r31)
	PPC_STORE_U16(r31.u32 + 448, r30.u16);
	// stw r30,444(r31)
	PPC_STORE_U32(r31.u32 + 444, r30.u32);
	// stb r30,455(r31)
	PPC_STORE_U8(r31.u32 + 455, r30.u8);
loc_826C1760:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826d0418
	ctx.lr = 0x826C1768;
	sub_826D0418(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,200
	r27.s64 = r27.s64 + 200;
	// bge 0x826c1760
	if (!cr0.lt) goto loc_826C1760;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// sth r30,8462(r31)
	PPC_STORE_U16(r31.u32 + 8462, r30.u16);
	// sth r30,8460(r31)
	PPC_STORE_U16(r31.u32 + 8460, r30.u16);
	// addi r3,r31,8596
	ctx.r3.s64 = r31.s64 + 8596;
	// stw r30,8456(r31)
	PPC_STORE_U32(r31.u32 + 8456, r30.u32);
	// stb r30,8467(r31)
	PPC_STORE_U8(r31.u32 + 8467, r30.u8);
	// stw r30,8564(r31)
	PPC_STORE_U32(r31.u32 + 8564, r30.u32);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r30,8568(r31)
	PPC_STORE_U32(r31.u32 + 8568, r30.u32);
	// stfs f0,8468(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8468, temp.u32);
	// stw r30,8572(r31)
	PPC_STORE_U32(r31.u32 + 8572, r30.u32);
	// stw r30,8576(r31)
	PPC_STORE_U32(r31.u32 + 8576, r30.u32);
	// stw r30,8580(r31)
	PPC_STORE_U32(r31.u32 + 8580, r30.u32);
	// stw r30,8584(r31)
	PPC_STORE_U32(r31.u32 + 8584, r30.u32);
	// stw r30,8588(r31)
	PPC_STORE_U32(r31.u32 + 8588, r30.u32);
	// stw r30,8592(r31)
	PPC_STORE_U32(r31.u32 + 8592, r30.u32);
	// bl 0x826cf9c0
	ctx.lr = 0x826C17B8;
	sub_826CF9C0(ctx, base);
	// addi r27,r31,8768
	r27.s64 = r31.s64 + 8768;
	// sth r30,8754(r31)
	PPC_STORE_U16(r31.u32 + 8754, r30.u16);
	// li r26,4
	r26.s64 = 4;
	// sth r30,8752(r31)
	PPC_STORE_U16(r31.u32 + 8752, r30.u16);
	// addi r28,r27,80
	r28.s64 = r27.s64 + 80;
	// stw r30,8748(r31)
	PPC_STORE_U32(r31.u32 + 8748, r30.u32);
	// li r25,-1
	r25.s64 = -1;
	// stb r30,8759(r31)
	PPC_STORE_U8(r31.u32 + 8759, r30.u8);
loc_826C17D8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238f550
	ctx.lr = 0x826C17E0;
	sub_8238F550(ctx, base);
	// stb r30,-76(r28)
	PPC_STORE_U8(r28.u32 + -76, r30.u8);
	// stw r25,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r25.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238ee08
	ctx.lr = 0x826C17F0;
	sub_8238EE08(ctx, base);
	// stw r25,8176(r28)
	PPC_STORE_U32(r28.u32 + 8176, r25.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r27,r27,8272
	r27.s64 = r27.s64 + 8272;
	// addi r28,r28,8272
	r28.s64 = r28.s64 + 8272;
	// bge 0x826c17d8
	if (!cr0.lt) goto loc_826C17D8;
	// addis r27,r31,1
	r27.s64 = r31.s64 + 65536;
	// li r26,4
	r26.s64 = 4;
	// addi r27,r27,-15408
	r27.s64 = r27.s64 + -15408;
	// addi r28,r27,80
	r28.s64 = r27.s64 + 80;
loc_826C1814:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238f550
	ctx.lr = 0x826C181C;
	sub_8238F550(ctx, base);
	// stb r30,-76(r28)
	PPC_STORE_U8(r28.u32 + -76, r30.u8);
	// stw r25,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r25.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238ee08
	ctx.lr = 0x826C182C;
	sub_8238EE08(ctx, base);
	// stw r25,8176(r28)
	PPC_STORE_U32(r28.u32 + 8176, r25.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r27,r27,8272
	r27.s64 = r27.s64 + 8272;
	// addi r28,r28,8272
	r28.s64 = r28.s64 + 8272;
	// bge 0x826c1814
	if (!cr0.lt) goto loc_826C1814;
	// lis r11,1
	r11.s64 = 65536;
	// addis r8,r31,1
	ctx.r8.s64 = r31.s64 + 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r11,25960
	ctx.r9.u64 = r11.u64 | 25960;
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// addi r8,r8,25964
	ctx.r8.s64 = ctx.r8.s64 + 25964;
	// ori r7,r10,26688
	ctx.r7.u64 = ctx.r10.u64 | 26688;
	// addi r6,r6,27700
	ctx.r6.s64 = ctx.r6.s64 + 27700;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r30,6(r8)
	PPC_STORE_U16(ctx.r8.u32 + 6, r30.u16);
	// addi r28,r28,27768
	r28.s64 = r28.s64 + 27768;
	// sth r30,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, r30.u16);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r30,11(r8)
	PPC_STORE_U8(ctx.r8.u32 + 11, r30.u8);
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// stw r30,56(r6)
	PPC_STORE_U32(ctx.r6.u32 + 56, r30.u32);
	// stw r30,52(r6)
	PPC_STORE_U32(ctx.r6.u32 + 52, r30.u32);
	// stw r30,48(r6)
	PPC_STORE_U32(ctx.r6.u32 + 48, r30.u32);
	// bl 0x821ce460
	ctx.lr = 0x826C189C;
	sub_821CE460(ctx, base);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// addis r27,r31,1
	r27.s64 = r31.s64 + 65536;
	// addis r26,r31,1
	r26.s64 = r31.s64 + 65536;
	// ori r11,r5,27786
	r11.u64 = ctx.r5.u64 | 27786;
	// ori r10,r4,27787
	ctx.r10.u64 = ctx.r4.u64 | 27787;
	// ori r9,r3,27789
	ctx.r9.u64 = ctx.r3.u64 | 27789;
	// addi r27,r27,27784
	r27.s64 = r27.s64 + 27784;
	// addi r26,r26,27785
	r26.s64 = r26.s64 + 27785;
	// stbx r30,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r30.u8);
	// stbx r30,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r30.u8);
	// stbx r30,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r30.u8);
	// stb r30,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r30.u8);
	// stb r30,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r30.u8);
	// bl 0x826bdc60
	ctx.lr = 0x826C18DC;
	sub_826BDC60(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ce210
	ctx.lr = 0x826C18E8;
	sub_821CE210(ctx, base);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// addi r6,r8,-27448
	ctx.r6.s64 = ctx.r8.s64 + -27448;
	// addi r5,r7,-27408
	ctx.r5.s64 = ctx.r7.s64 + -27408;
	// lis r4,-32111
	ctx.r4.s64 = -2104426496;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// addi r6,r4,-27348
	ctx.r6.s64 = ctx.r4.s64 + -27348;
	// addi r10,r10,-12192
	ctx.r10.s64 = ctx.r10.s64 + -12192;
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r8,r8,-12208
	ctx.r8.s64 = ctx.r8.s64 + -12208;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// xori r11,r4,1
	r11.u64 = ctx.r4.u64 ^ 1;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r11,360(r31)
	PPC_STORE_U32(r31.u32 + 360, r11.u32);
	// addi r3,r3,-12224
	ctx.r3.s64 = ctx.r3.s64 + -12224;
	// addi r9,r9,-12240
	ctx.r9.s64 = ctx.r9.s64 + -12240;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,8496
	ctx.r3.s64 = 8496;
	// xori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 ^ 1;
	// lfs f0,27536(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27536);
	f0.f64 = double(temp.f32);
	// lfs f13,-3072(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -3072);
	ctx.f13.f64 = double(temp.f32);
	// li r9,8512
	ctx.r9.s64 = 8512;
	// stb r8,0(r27)
	PPC_STORE_U8(r27.u32 + 0, ctx.r8.u8);
	// li r7,8528
	ctx.r7.s64 = 8528;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// li r5,8544
	ctx.r5.s64 = 8544;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lfs f12,-6172(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -6172);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f11,-332(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -332);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// xori r4,r11,1
	ctx.r4.u64 = r11.u64 ^ 1;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stb r4,0(r26)
	PPC_STORE_U8(r26.u32 + 0, ctx.r4.u8);
	// stvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,1
	ctx.r9.s64 = 65536;
	// stvx128 v61,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,1
	ctx.r7.s64 = 65536;
	// ori r9,r9,25978
	ctx.r9.u64 = ctx.r9.u64 | 25978;
	// stvx128 v60,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,8472(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8472, temp.u32);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stfs f13,8476(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8476, temp.u32);
	// lis r4,1
	ctx.r4.s64 = 65536;
	// stfs f12,8480(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8480, temp.u32);
	// ori r7,r7,25980
	ctx.r7.u64 = ctx.r7.u64 | 25980;
	// lfs f10,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// stbx r30,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r30.u8);
	// lfs f9,-3164(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -3164);
	ctx.f9.f64 = double(temp.f32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stfs f11,8484(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 8484, temp.u32);
	// ori r8,r8,25979
	ctx.r8.u64 = ctx.r8.u64 | 25979;
	// stfs f10,8488(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 8488, temp.u32);
	// ori r6,r6,25981
	ctx.r6.u64 = ctx.r6.u64 | 25981;
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// ori r5,r5,25982
	ctx.r5.u64 = ctx.r5.u64 | 25982;
	// stfs f9,8492(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 8492, temp.u32);
	// ori r4,r4,25983
	ctx.r4.u64 = ctx.r4.u64 | 25983;
	// stw r30,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r30.u32);
	// lis r11,1
	r11.s64 = 65536;
	// stw r30,392(r31)
	PPC_STORE_U32(r31.u32 + 392, r30.u32);
	// lis r3,1
	ctx.r3.s64 = 65536;
	// stbx r30,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r30.u8);
	// lis r28,1
	r28.s64 = 65536;
	// stbx r30,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r30.u8);
	// ori r10,r10,25976
	ctx.r10.u64 = ctx.r10.u64 | 25976;
	// stbx r30,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r30.u8);
	// ori r11,r11,25977
	r11.u64 = r11.u64 | 25977;
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// ori r3,r3,27760
	ctx.r3.u64 = ctx.r3.u64 | 27760;
	// stw r30,396(r31)
	PPC_STORE_U32(r31.u32 + 396, r30.u32);
	// ori r9,r28,27761
	ctx.r9.u64 = r28.u64 | 27761;
	// stw r30,400(r31)
	PPC_STORE_U32(r31.u32 + 400, r30.u32);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// li r7,7
	ctx.r7.s64 = 7;
	// stbx r30,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r30.u8);
	// li r6,2
	ctx.r6.s64 = 2;
	// stbx r30,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r30.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r7,372(r31)
	PPC_STORE_U32(r31.u32 + 372, ctx.r7.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r6,380(r31)
	PPC_STORE_U32(r31.u32 + 380, ctx.r6.u32);
	// stw r5,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r5.u32);
	// addi r11,r31,24
	r11.s64 = r31.s64 + 24;
	// stw r4,376(r31)
	PPC_STORE_U32(r31.u32 + 376, ctx.r4.u32);
	// stbx r30,r31,r3
	PPC_STORE_U8(r31.u32 + ctx.r3.u32, r30.u8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stbx r30,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r30.u8);
	// lwz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lhz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// sth r9,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r9.u16);
	// lbz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 6);
	// stb r8,30(r31)
	PPC_STORE_U8(r31.u32 + 30, ctx.r8.u8);
loc_826C1AA0:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c1aa0
	if (!cr6.eq) goto loc_826C1AA0;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// ori r8,r10,3392
	ctx.r8.u64 = ctx.r10.u64 | 3392;
	// li r7,11
	ctx.r7.s64 = 11;
	// stw r9,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r9.u32);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stb r7,60(r31)
	PPC_STORE_U8(r31.u32 + 60, ctx.r7.u8);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r6,r3,-14596
	ctx.r6.s64 = ctx.r3.s64 + -14596;
	// addi r5,r11,-14960
	ctx.r5.s64 = r11.s64 + -14960;
	// lwz r3,2832(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2832);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x82202c00
	ctx.lr = 0x826C1AF0;
	sub_82202C00(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r10,-15816
	ctx.r5.s64 = ctx.r10.s64 + -15816;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1B0C;
	sub_8268B960(ctx, base);
	// stw r3,8592(r31)
	PPC_STORE_U32(r31.u32 + 8592, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r9,-19968
	ctx.r5.s64 = ctx.r9.s64 + -19968;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1B28;
	sub_8268B960(ctx, base);
	// stw r3,8564(r31)
	PPC_STORE_U32(r31.u32 + 8564, ctx.r3.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r8,-20036
	ctx.r5.s64 = ctx.r8.s64 + -20036;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1B44;
	sub_8268B960(ctx, base);
	// stw r3,8560(r31)
	PPC_STORE_U32(r31.u32 + 8560, ctx.r3.u32);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r7,-12260
	ctx.r5.s64 = ctx.r7.s64 + -12260;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1B60;
	sub_8268B960(ctx, base);
	// stw r3,8568(r31)
	PPC_STORE_U32(r31.u32 + 8568, ctx.r3.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r5,-18544
	ctx.r5.s64 = ctx.r5.s64 + -18544;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1B7C;
	sub_8268B960(ctx, base);
	// stw r3,8572(r31)
	PPC_STORE_U32(r31.u32 + 8572, ctx.r3.u32);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r4,-12276
	ctx.r5.s64 = ctx.r4.s64 + -12276;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1B98;
	sub_8268B960(ctx, base);
	// stw r3,8576(r31)
	PPC_STORE_U32(r31.u32 + 8576, ctx.r3.u32);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r3,-12296
	ctx.r5.s64 = ctx.r3.s64 + -12296;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1BB4;
	sub_8268B960(ctx, base);
	// stw r3,8580(r31)
	PPC_STORE_U32(r31.u32 + 8580, ctx.r3.u32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-16832
	ctx.r5.s64 = r11.s64 + -16832;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1BD0;
	sub_8268B960(ctx, base);
	// stw r3,8584(r31)
	PPC_STORE_U32(r31.u32 + 8584, ctx.r3.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r3,-10224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r10,-12316
	ctx.r5.s64 = ctx.r10.s64 + -12316;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8268b960
	ctx.lr = 0x826C1BEC;
	sub_8268B960(ctx, base);
	// stw r3,8588(r31)
	PPC_STORE_U32(r31.u32 + 8588, ctx.r3.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e06e0
	ctx.lr = 0x826C1BFC;
	sub_824E06E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0558
	ctx.lr = 0x826C1C04;
	sub_824E0558(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r5,1000
	ctx.r5.s64 = 1000;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,26692
	ctx.r3.s64 = ctx.r3.s64 + 26692;
	// bl 0x823d9890
	ctx.lr = 0x826C1C18;
	sub_823D9890(ctx, base);
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// li r5,160
	ctx.r5.s64 = 160;
	// addi r9,r9,27692
	ctx.r9.s64 = ctx.r9.s64 + 27692;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// stw r30,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r30.u32);
	// stb r30,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r30.u8);
	// bl 0x823d9890
	ctx.lr = 0x826C1C38;
	sub_823D9890(ctx, base);
	// li r5,80
	ctx.r5.s64 = 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,260
	ctx.r3.s64 = r31.s64 + 260;
	// bl 0x823d9890
	ctx.lr = 0x826C1C48;
	sub_823D9890(ctx, base);
	// addis r8,r31,1
	ctx.r8.s64 = r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r8,r8,25984
	ctx.r8.s64 = ctx.r8.s64 + 25984;
	// li r5,342
	ctx.r5.s64 = 342;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,26004
	ctx.r3.s64 = ctx.r3.s64 + 26004;
	// std r30,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, r30.u64);
	// std r30,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, r30.u64);
	// stw r30,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x826C1C70;
	sub_823D9890(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r5,342
	ctx.r5.s64 = 342;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,26346
	ctx.r3.s64 = ctx.r3.s64 + 26346;
	// bl 0x823d9890
	ctx.lr = 0x826C1C84;
	sub_823D9890(ctx, base);
	// addis r7,r31,1
	ctx.r7.s64 = r31.s64 + 65536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r7,25952
	ctx.r7.s64 = ctx.r7.s64 + 25952;
	// stw r30,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r30.u32);
	// stb r30,4(r7)
	PPC_STORE_U8(ctx.r7.u32 + 4, r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826C1CA0"))) PPC_WEAK_FUNC(sub_826C1CA0);
PPC_FUNC_IMPL(__imp__sub_826C1CA0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x826c1e68
	sub_826C1E68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C1CA8"))) PPC_WEAK_FUNC(sub_826C1CA8);
PPC_FUNC_IMPL(__imp__sub_826C1CA8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-64
	ctx.r3.s64 = ctx.r3.s64 + -64;
	// b 0x826c1e68
	sub_826C1E68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C1CB0"))) PPC_WEAK_FUNC(sub_826C1CB0);
PPC_FUNC_IMPL(__imp__sub_826C1CB0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826C1CB8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r11,-12116
	ctx.r8.s64 = r11.s64 + -12116;
	// addi r7,r10,-12160
	ctx.r7.s64 = ctx.r10.s64 + -12160;
	// lwz r5,8592(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8592);
	// addi r6,r9,-12172
	ctx.r6.s64 = ctx.r9.s64 + -12172;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r6,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r6.u32);
	// addi r30,r31,64
	r30.s64 = r31.s64 + 64;
	// addi r26,r31,12
	r26.s64 = r31.s64 + 12;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D00;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,8564(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8564);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D10;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,8560(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8560);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D20;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,8568(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8568);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D30;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,8572(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8572);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D40;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,8576(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8576);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D50;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,8580(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8580);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D60;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,8584(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8584);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D70;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,8588(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8588);
	// bl 0x8268b6d0
	ctx.lr = 0x826C1D80;
	sub_8268B6D0(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,25964
	ctx.r3.s64 = ctx.r3.s64 + 25964;
	// bl 0x82608de8
	ctx.lr = 0x826C1D8C;
	sub_82608DE8(ctx, base);
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// li r27,4
	r27.s64 = 4;
	// addi r29,r29,-24176
	r29.s64 = r29.s64 + -24176;
	// addis r11,r29,1
	r11.s64 = r29.s64 + 65536;
	// addi r11,r11,-15408
	r11.s64 = r11.s64 + -15408;
	// addi r28,r11,80
	r28.s64 = r11.s64 + 80;
loc_826C1DA4:
	// addi r28,r28,-8272
	r28.s64 = r28.s64 + -8272;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238ed78
	ctx.lr = 0x826C1DB0;
	sub_8238ED78(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// bge 0x826c1da4
	if (!cr0.lt) goto loc_826C1DA4;
	// addi r11,r29,8768
	r11.s64 = r29.s64 + 8768;
	// li r28,4
	r28.s64 = 4;
	// addi r29,r11,80
	r29.s64 = r11.s64 + 80;
loc_826C1DC4:
	// addi r29,r29,-8272
	r29.s64 = r29.s64 + -8272;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238ed78
	ctx.lr = 0x826C1DD0;
	sub_8238ED78(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x826c1dc4
	if (!cr0.lt) goto loc_826C1DC4;
	// addi r3,r31,8748
	ctx.r3.s64 = r31.s64 + 8748;
	// bl 0x826bdcd0
	ctx.lr = 0x826C1DE0;
	sub_826BDCD0(ctx, base);
	// addi r3,r31,8596
	ctx.r3.s64 = r31.s64 + 8596;
	// bl 0x826cfac0
	ctx.lr = 0x826C1DE8;
	sub_826CFAC0(ctx, base);
	// addi r3,r31,8456
	ctx.r3.s64 = r31.s64 + 8456;
	// bl 0x82608de8
	ctx.lr = 0x826C1DF0;
	sub_82608DE8(ctx, base);
	// addi r29,r31,8456
	r29.s64 = r31.s64 + 8456;
	// li r28,39
	r28.s64 = 39;
loc_826C1DF8:
	// addi r29,r29,-200
	r29.s64 = r29.s64 + -200;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826d0460
	ctx.lr = 0x826C1E04;
	sub_826D0460(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x826c1df8
	if (!cr0.lt) goto loc_826C1DF8;
	// addi r3,r31,444
	ctx.r3.s64 = r31.s64 + 444;
	// bl 0x821bef98
	ctx.lr = 0x826C1E14;
	sub_821BEF98(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-21856
	ctx.r9.s64 = r11.s64 + -21856;
	// addi r8,r10,-21868
	ctx.r8.s64 = ctx.r10.s64 + -21868;
	// stw r9,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r9.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// bl 0x8238d010
	ctx.lr = 0x826C1E34;
	sub_8238D010(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0430
	ctx.lr = 0x826C1E3C;
	sub_824E0430(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826C1E44"))) PPC_WEAK_FUNC(sub_826C1E44);
PPC_FUNC_IMPL(__imp__sub_826C1E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C1E48"))) PPC_WEAK_FUNC(sub_826C1E48);
PPC_FUNC_IMPL(__imp__sub_826C1E48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x826c0770
	sub_826C0770(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C1E64"))) PPC_WEAK_FUNC(sub_826C1E64);
PPC_FUNC_IMPL(__imp__sub_826C1E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C1E68"))) PPC_WEAK_FUNC(sub_826C1E68);
PPC_FUNC_IMPL(__imp__sub_826C1E68) {
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
	// bl 0x826c1cb0
	ctx.lr = 0x826C1E88;
	sub_826C1CB0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c1ea0
	if (cr6.eq) goto loc_826C1EA0;
	// bl 0x82130588
	ctx.lr = 0x826C1E9C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826C1EA0:
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

__attribute__((alias("__imp__sub_826C1EB8"))) PPC_WEAK_FUNC(sub_826C1EB8);
PPC_FUNC_IMPL(__imp__sub_826C1EB8) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,8528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8528);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x826c20e0
	if (cr6.eq) goto loc_826C20E0;
	// lwz r11,8496(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8496);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x826c20e0
	if (cr6.eq) goto loc_826C20E0;
	// lwz r11,8500(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8500);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x826c1f64
	if (!cr6.eq) goto loc_826C1F64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,27784
	ctx.r9.u64 = ctx.r10.u64 | 27784;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c2144
	if (!cr6.eq) goto loc_826C2144;
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x826c2144
	if (!cr6.eq) goto loc_826C2144;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,-12084
	ctx.r3.s64 = r11.s64 + -12084;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x826C1F44;
	sub_82727908(ctx, base);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r7,304(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r8,r10,27725
	ctx.r8.u64 = ctx.r10.u64 | 27725;
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,304(r31)
	PPC_STORE_U32(r31.u32 + 304, ctx.r6.u32);
	// stbx r9,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, ctx.r9.u8);
	// b 0x826c2144
	goto loc_826C2144;
loc_826C1F64:
	// lwz r11,8504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8504);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x826c200c
	if (!cr6.eq) goto loc_826C200C;
	// bl 0x82387a18
	ctx.lr = 0x826C1F74;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c1fa4
	if (cr6.eq) goto loc_826C1FA4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826C1F88;
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
	ctx.lr = 0x826C1F9C;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// b 0x826c1fa8
	goto loc_826C1FA8;
loc_826C1FA4:
	// li r11,0
	r11.s64 = 0;
loc_826C1FA8:
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c1fcc
	if (cr6.eq) goto loc_826C1FCC;
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x826C1FBC;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c1fcc
	if (cr6.eq) goto loc_826C1FCC;
	// li r30,1
	r30.s64 = 1;
loc_826C1FCC:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c2144
	if (!cr6.eq) goto loc_826C2144;
	// lbz r11,292(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 292);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c2144
	if (cr6.eq) goto loc_826C2144;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-14960
	ctx.r4.s64 = ctx.r10.s64 + -14960;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826C2008;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826c2144
	goto loc_826C2144;
loc_826C200C:
	// lwz r11,8508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8508);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x826c2064
	if (!cr6.eq) goto loc_826C2064;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c2144
	if (cr6.eq) goto loc_826C2144;
	// lwz r11,3140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c2144
	if (!cr6.eq) goto loc_826C2144;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x826c2144
	if (cr6.lt) goto loc_826C2144;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826C2044;
	sub_8238EC00(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r31,-64
	ctx.r3.s64 = r31.s64 + -64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,36(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// lwzx r4,r8,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// bl 0x826bcee8
	ctx.lr = 0x826C2060;
	sub_826BCEE8(ctx, base);
	// b 0x826c2144
	goto loc_826C2144;
loc_826C2064:
	// lwz r11,8512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8512);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x826c2094
	if (cr6.eq) goto loc_826C2094;
	// lwz r11,8516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8516);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x826c2094
	if (cr6.eq) goto loc_826C2094;
	// lwz r11,8520(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8520);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x826c2094
	if (cr6.eq) goto loc_826C2094;
	// lwz r11,8524(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8524);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x826c2144
	if (!cr6.eq) goto loc_826C2144;
loc_826C2094:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// li r30,0
	r30.s64 = 0;
	// addi r4,r10,-17848
	ctx.r4.s64 = ctx.r10.s64 + -17848;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x826C20AC;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c20b8
	if (cr6.eq) goto loc_826C20B8;
	// addi r30,r3,92
	r30.s64 = ctx.r3.s64 + 92;
loc_826C20B8:
	// bl 0x82256058
	ctx.lr = 0x826C20BC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c2144
	if (cr6.eq) goto loc_826C2144;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c2144
	if (cr6.eq) goto loc_826C2144;
	// lwz r4,3108(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3108);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r31,-64
	ctx.r3.s64 = r31.s64 + -64;
	// bl 0x826be500
	ctx.lr = 0x826C20DC;
	sub_826BE500(ctx, base);
	// b 0x826c2144
	goto loc_826C2144;
loc_826C20E0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,27784
	ctx.r9.u64 = ctx.r10.u64 | 27784;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c2144
	if (!cr6.eq) goto loc_826C2144;
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// addi r30,r30,27725
	r30.s64 = r30.s64 + 27725;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c2144
	if (!cr6.eq) goto loc_826C2144;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,-12084
	ctx.r3.s64 = r11.s64 + -12084;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x826C2130;
	sub_82727908(ctx, base);
	// lwz r9,304(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stb r10,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r10.u8);
	// stw r8,304(r31)
	PPC_STORE_U32(r31.u32 + 304, ctx.r8.u32);
loc_826C2144:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_826C2160"))) PPC_WEAK_FUNC(sub_826C2160);
PPC_FUNC_IMPL(__imp__sub_826C2160) {
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
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,7752
	ctx.r4.s64 = r11.s64 + 7752;
	// addi r3,r10,-10656
	ctx.r3.s64 = ctx.r10.s64 + -10656;
	// bl 0x82554798
	ctx.lr = 0x826C2180;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,5544
	ctx.r4.s64 = ctx.r9.s64 + 5544;
	// addi r3,r8,-10688
	ctx.r3.s64 = ctx.r8.s64 + -10688;
	// bl 0x82554798
	ctx.lr = 0x826C2194;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,5672
	ctx.r4.s64 = ctx.r7.s64 + 5672;
	// addi r3,r6,-10716
	ctx.r3.s64 = ctx.r6.s64 + -10716;
	// bl 0x82554798
	ctx.lr = 0x826C21A8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-8496
	ctx.r4.s64 = ctx.r5.s64 + -8496;
	// addi r3,r3,-10748
	ctx.r3.s64 = ctx.r3.s64 + -10748;
	// bl 0x82554798
	ctx.lr = 0x826C21BC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-56
	ctx.r4.s64 = r11.s64 + -56;
	// addi r3,r10,-10772
	ctx.r3.s64 = ctx.r10.s64 + -10772;
	// bl 0x82554798
	ctx.lr = 0x826C21D0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-8432
	ctx.r4.s64 = ctx.r9.s64 + -8432;
	// addi r3,r8,-10792
	ctx.r3.s64 = ctx.r8.s64 + -10792;
	// bl 0x82554798
	ctx.lr = 0x826C21E4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,16
	ctx.r4.s64 = ctx.r7.s64 + 16;
	// addi r3,r6,-10816
	ctx.r3.s64 = ctx.r6.s64 + -10816;
	// bl 0x82554798
	ctx.lr = 0x826C21F8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,104
	ctx.r4.s64 = ctx.r5.s64 + 104;
	// addi r3,r3,-10844
	ctx.r3.s64 = ctx.r3.s64 + -10844;
	// bl 0x82554798
	ctx.lr = 0x826C220C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-10008
	ctx.r4.s64 = r11.s64 + -10008;
	// addi r3,r10,-10868
	ctx.r3.s64 = ctx.r10.s64 + -10868;
	// bl 0x82554798
	ctx.lr = 0x826C2220;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,192
	ctx.r4.s64 = ctx.r9.s64 + 192;
	// addi r3,r8,-10892
	ctx.r3.s64 = ctx.r8.s64 + -10892;
	// bl 0x82554798
	ctx.lr = 0x826C2234;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-9976
	ctx.r4.s64 = ctx.r7.s64 + -9976;
	// addi r3,r6,-10920
	ctx.r3.s64 = ctx.r6.s64 + -10920;
	// bl 0x82554798
	ctx.lr = 0x826C2248;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-9936
	ctx.r4.s64 = ctx.r5.s64 + -9936;
	// addi r3,r3,-10948
	ctx.r3.s64 = ctx.r3.s64 + -10948;
	// bl 0x82554798
	ctx.lr = 0x826C225C;
	sub_82554798(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,17552
	ctx.r4.s64 = r11.s64 + 17552;
	// addi r3,r10,-10972
	ctx.r3.s64 = ctx.r10.s64 + -10972;
	// bl 0x82554798
	ctx.lr = 0x826C2270;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,272
	ctx.r4.s64 = ctx.r9.s64 + 272;
	// addi r3,r8,-10992
	ctx.r3.s64 = ctx.r8.s64 + -10992;
	// bl 0x82554798
	ctx.lr = 0x826C2284;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,288
	ctx.r4.s64 = ctx.r7.s64 + 288;
	// addi r3,r6,-11016
	ctx.r3.s64 = ctx.r6.s64 + -11016;
	// bl 0x82554798
	ctx.lr = 0x826C2298;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,384
	ctx.r4.s64 = ctx.r5.s64 + 384;
	// addi r3,r3,-11044
	ctx.r3.s64 = ctx.r3.s64 + -11044;
	// bl 0x82554798
	ctx.lr = 0x826C22AC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,5736
	ctx.r4.s64 = r11.s64 + 5736;
	// addi r3,r10,-11072
	ctx.r3.s64 = ctx.r10.s64 + -11072;
	// bl 0x82554798
	ctx.lr = 0x826C22C0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,480
	ctx.r4.s64 = ctx.r9.s64 + 480;
	// addi r3,r8,-11104
	ctx.r3.s64 = ctx.r8.s64 + -11104;
	// bl 0x82554798
	ctx.lr = 0x826C22D4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,600
	ctx.r4.s64 = ctx.r7.s64 + 600;
	// addi r3,r6,-11132
	ctx.r3.s64 = ctx.r6.s64 + -11132;
	// bl 0x82554798
	ctx.lr = 0x826C22E8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,728
	ctx.r4.s64 = ctx.r5.s64 + 728;
	// addi r3,r3,-11160
	ctx.r3.s64 = ctx.r3.s64 + -11160;
	// bl 0x82554798
	ctx.lr = 0x826C22FC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,856
	ctx.r4.s64 = r11.s64 + 856;
	// addi r3,r10,-11192
	ctx.r3.s64 = ctx.r10.s64 + -11192;
	// bl 0x82554798
	ctx.lr = 0x826C2310;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,984
	ctx.r4.s64 = ctx.r9.s64 + 984;
	// addi r3,r8,-11224
	ctx.r3.s64 = ctx.r8.s64 + -11224;
	// bl 0x82554798
	ctx.lr = 0x826C2324;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,1032
	ctx.r4.s64 = ctx.r7.s64 + 1032;
	// addi r3,r6,-11256
	ctx.r3.s64 = ctx.r6.s64 + -11256;
	// bl 0x82554798
	ctx.lr = 0x826C2338;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,1160
	ctx.r4.s64 = ctx.r5.s64 + 1160;
	// addi r3,r3,-11280
	ctx.r3.s64 = ctx.r3.s64 + -11280;
	// bl 0x82554798
	ctx.lr = 0x826C234C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,1288
	ctx.r4.s64 = r11.s64 + 1288;
	// addi r3,r10,-11312
	ctx.r3.s64 = ctx.r10.s64 + -11312;
	// bl 0x82554798
	ctx.lr = 0x826C2360;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,1416
	ctx.r4.s64 = ctx.r9.s64 + 1416;
	// addi r3,r8,-11348
	ctx.r3.s64 = ctx.r8.s64 + -11348;
	// bl 0x82554798
	ctx.lr = 0x826C2374;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,1448
	ctx.r4.s64 = ctx.r7.s64 + 1448;
	// addi r3,r6,-11380
	ctx.r3.s64 = ctx.r6.s64 + -11380;
	// bl 0x82554798
	ctx.lr = 0x826C2388;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,5792
	ctx.r4.s64 = ctx.r5.s64 + 5792;
	// addi r3,r3,-11416
	ctx.r3.s64 = ctx.r3.s64 + -11416;
	// bl 0x82554798
	ctx.lr = 0x826C239C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,1552
	ctx.r4.s64 = r11.s64 + 1552;
	// addi r3,r10,-11452
	ctx.r3.s64 = ctx.r10.s64 + -11452;
	// bl 0x82554798
	ctx.lr = 0x826C23B0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,1664
	ctx.r4.s64 = ctx.r9.s64 + 1664;
	// addi r3,r8,-11484
	ctx.r3.s64 = ctx.r8.s64 + -11484;
	// bl 0x82554798
	ctx.lr = 0x826C23C4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,1704
	ctx.r4.s64 = ctx.r7.s64 + 1704;
	// addi r3,r6,-11516
	ctx.r3.s64 = ctx.r6.s64 + -11516;
	// bl 0x82554798
	ctx.lr = 0x826C23D8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-8336
	ctx.r4.s64 = ctx.r5.s64 + -8336;
	// addi r3,r3,-11548
	ctx.r3.s64 = ctx.r3.s64 + -11548;
	// bl 0x82554798
	ctx.lr = 0x826C23EC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// addi r4,r11,-8248
	ctx.r4.s64 = r11.s64 + -8248;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r3,r10,-11580
	ctx.r3.s64 = ctx.r10.s64 + -11580;
	// bl 0x82554798
	ctx.lr = 0x826C2400;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-8152
	ctx.r4.s64 = ctx.r9.s64 + -8152;
	// addi r3,r8,-11616
	ctx.r3.s64 = ctx.r8.s64 + -11616;
	// bl 0x82554798
	ctx.lr = 0x826C2414;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-8128
	ctx.r4.s64 = ctx.r7.s64 + -8128;
	// addi r3,r6,-11644
	ctx.r3.s64 = ctx.r6.s64 + -11644;
	// bl 0x82554798
	ctx.lr = 0x826C2428;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,1760
	ctx.r4.s64 = ctx.r5.s64 + 1760;
	// addi r3,r3,-11664
	ctx.r3.s64 = ctx.r3.s64 + -11664;
	// bl 0x82554798
	ctx.lr = 0x826C243C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-8096
	ctx.r4.s64 = r11.s64 + -8096;
	// addi r3,r10,-11696
	ctx.r3.s64 = ctx.r10.s64 + -11696;
	// bl 0x82554798
	ctx.lr = 0x826C2450;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,1792
	ctx.r4.s64 = ctx.r9.s64 + 1792;
	// addi r3,r8,-11720
	ctx.r3.s64 = ctx.r8.s64 + -11720;
	// bl 0x82554798
	ctx.lr = 0x826C2464;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-8064
	ctx.r4.s64 = ctx.r7.s64 + -8064;
	// addi r3,r6,-11752
	ctx.r3.s64 = ctx.r6.s64 + -11752;
	// bl 0x82554798
	ctx.lr = 0x826C2478;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-7960
	ctx.r4.s64 = ctx.r5.s64 + -7960;
	// addi r3,r3,-11780
	ctx.r3.s64 = ctx.r3.s64 + -11780;
	// bl 0x82554798
	ctx.lr = 0x826C248C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-7920
	ctx.r4.s64 = r11.s64 + -7920;
	// addi r3,r10,-11808
	ctx.r3.s64 = ctx.r10.s64 + -11808;
	// bl 0x82554798
	ctx.lr = 0x826C24A0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-7840
	ctx.r4.s64 = ctx.r9.s64 + -7840;
	// addi r3,r8,-11832
	ctx.r3.s64 = ctx.r8.s64 + -11832;
	// bl 0x82554798
	ctx.lr = 0x826C24B4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,1880
	ctx.r4.s64 = ctx.r7.s64 + 1880;
	// addi r3,r6,-11860
	ctx.r3.s64 = ctx.r6.s64 + -11860;
	// bl 0x82554798
	ctx.lr = 0x826C24C8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-7808
	ctx.r4.s64 = ctx.r5.s64 + -7808;
	// addi r3,r3,-11896
	ctx.r3.s64 = ctx.r3.s64 + -11896;
	// bl 0x82554798
	ctx.lr = 0x826C24DC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,-7648
	ctx.r4.s64 = r11.s64 + -7648;
	// addi r3,r10,-11920
	ctx.r3.s64 = ctx.r10.s64 + -11920;
	// bl 0x82554798
	ctx.lr = 0x826C24F0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-7616
	ctx.r4.s64 = ctx.r9.s64 + -7616;
	// addi r3,r8,-11948
	ctx.r3.s64 = ctx.r8.s64 + -11948;
	// bl 0x82554798
	ctx.lr = 0x826C2504;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-7584
	ctx.r4.s64 = ctx.r7.s64 + -7584;
	// addi r3,r6,-11976
	ctx.r3.s64 = ctx.r6.s64 + -11976;
	// bl 0x82554798
	ctx.lr = 0x826C2518;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-7552
	ctx.r4.s64 = ctx.r5.s64 + -7552;
	// addi r3,r3,-12004
	ctx.r3.s64 = ctx.r3.s64 + -12004;
	// bl 0x82554798
	ctx.lr = 0x826C252C;
	sub_82554798(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32148
	ctx.r10.s64 = -2106851328;
	// addi r3,r11,-12028
	ctx.r3.s64 = r11.s64 + -12028;
	// addi r4,r10,-9904
	ctx.r4.s64 = ctx.r10.s64 + -9904;
	// bl 0x82554798
	ctx.lr = 0x826C2540;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-9896
	ctx.r4.s64 = ctx.r9.s64 + -9896;
	// addi r3,r8,-12056
	ctx.r3.s64 = ctx.r8.s64 + -12056;
	// bl 0x82554798
	ctx.lr = 0x826C2554;
	sub_82554798(ctx, base);
	// bl 0x826c6270
	ctx.lr = 0x826C2558;
	sub_826C6270(ctx, base);
	// bl 0x826d0990
	ctx.lr = 0x826C255C;
	sub_826D0990(ctx, base);
	// bl 0x826cc0c0
	ctx.lr = 0x826C2560;
	sub_826CC0C0(ctx, base);
	// bl 0x826d01a8
	ctx.lr = 0x826C2564;
	sub_826D01A8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C2574"))) PPC_WEAK_FUNC(sub_826C2574);
PPC_FUNC_IMPL(__imp__sub_826C2574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C2578"))) PPC_WEAK_FUNC(sub_826C2578);
PPC_FUNC_IMPL(__imp__sub_826C2578) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r3,-27288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -27288);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c25ac
	if (cr6.eq) goto loc_826C25AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C25AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826C25AC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-27288(r31)
	PPC_STORE_U32(r31.u32 + -27288, r11.u32);
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

__attribute__((alias("__imp__sub_826C25C8"))) PPC_WEAK_FUNC(sub_826C25C8);
PPC_FUNC_IMPL(__imp__sub_826C25C8) {
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
	ctx.lr = 0x826C25D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821f1f40
	ctx.lr = 0x826C25E0;
	sub_821F1F40(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826c263c
	if (!cr6.eq) goto loc_826C263C;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r11,-27280(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27280);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c2624
	if (!cr6.eq) goto loc_826C2624;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r11,-27280(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27280, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-11824
	ctx.r4.s64 = ctx.r9.s64 + -11824;
	// bl 0x821f1f40
	ctx.lr = 0x826C2618;
	sub_821F1F40(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r31,-27284(r30)
	PPC_STORE_U32(r30.u32 + -27284, r31.u32);
	// b 0x826c2628
	goto loc_826C2628;
loc_826C2624:
	// lwz r31,-27284(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -27284);
loc_826C2628:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-10080
	ctx.r3.s64 = r11.s64 + -10080;
	// bl 0x82130000
	ctx.lr = 0x826C2638;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826C263C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826C2644"))) PPC_WEAK_FUNC(sub_826C2644);
PPC_FUNC_IMPL(__imp__sub_826C2644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C2648"))) PPC_WEAK_FUNC(sub_826C2648);
PPC_FUNC_IMPL(__imp__sub_826C2648) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-27288(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r3,60(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8213c218
	sub_8213C218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C2664"))) PPC_WEAK_FUNC(sub_826C2664);
PPC_FUNC_IMPL(__imp__sub_826C2664) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C2668"))) PPC_WEAK_FUNC(sub_826C2668);
PPC_FUNC_IMPL(__imp__sub_826C2668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r11,r11,-10000
	r11.s64 = r11.s64 + -10000;
	// addi r8,r11,3
	ctx.r8.s64 = r11.s64 + 3;
loc_826C2680:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x826c26a0
	if (!cr0.eq) goto loc_826C26A0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x826c2680
	if (!cr6.eq) goto loc_826C2680;
loc_826C26A0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r11,18
	r11.s64 = 18;
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C26B4"))) PPC_WEAK_FUNC(sub_826C26B4);
PPC_FUNC_IMPL(__imp__sub_826C26B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C26B8"))) PPC_WEAK_FUNC(sub_826C26B8);
PPC_FUNC_IMPL(__imp__sub_826C26B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,60(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8213c218
	sub_8213C218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C26CC"))) PPC_WEAK_FUNC(sub_826C26CC);
PPC_FUNC_IMPL(__imp__sub_826C26CC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C26D0"))) PPC_WEAK_FUNC(sub_826C26D0);
PPC_FUNC_IMPL(__imp__sub_826C26D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r11,-27288(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27288);
	// lwz r9,2252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821f1498
	sub_821F1498(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C26FC"))) PPC_WEAK_FUNC(sub_826C26FC);
PPC_FUNC_IMPL(__imp__sub_826C26FC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C2700"))) PPC_WEAK_FUNC(sub_826C2700);
PPC_FUNC_IMPL(__imp__sub_826C2700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// b 0x821f3468
	sub_821F3468(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C2718"))) PPC_WEAK_FUNC(sub_826C2718);
PPC_FUNC_IMPL(__imp__sub_826C2718) {
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
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r6,r5,144
	ctx.r6.s64 = ctx.r5.s64 + 144;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r11,144
	ctx.r5.s64 = r11.s64 + 144;
	// lwz r3,-27288(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27288);
	// bl 0x821f3628
	ctx.lr = 0x826C2740;
	sub_821F3628(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c2764
	if (cr6.eq) goto loc_826C2764;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r3,2260(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C2764:
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

__attribute__((alias("__imp__sub_826C2778"))) PPC_WEAK_FUNC(sub_826C2778);
PPC_FUNC_IMPL(__imp__sub_826C2778) {
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
	ctx.lr = 0x826C2780;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32125
	r29.s64 = -2105344000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-26232(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -26232);
	// bl 0x821c7d28
	ctx.lr = 0x826C27A4;
	sub_821C7D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c27b8
	if (cr6.eq) goto loc_826C27B8;
	// lwz r30,-26236(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + -26236);
loc_826C27B8:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,-26232(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -26232);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7d28
	ctx.lr = 0x826C27C8;
	sub_821C7D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c27d8
	if (cr6.eq) goto loc_826C27D8;
	// lwz r31,-26236(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -26236);
loc_826C27D8:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// bl 0x821f3730
	ctx.lr = 0x826C27F0;
	sub_821F3730(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826C27F8"))) PPC_WEAK_FUNC(sub_826C27F8);
PPC_FUNC_IMPL(__imp__sub_826C27F8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x821f32d0
	ctx.lr = 0x826C2828;
	sub_821F32D0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c2850
	if (cr6.eq) goto loc_826C2850;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r3,2260(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C2850:
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

__attribute__((alias("__imp__sub_826C2864"))) PPC_WEAK_FUNC(sub_826C2864);
PPC_FUNC_IMPL(__imp__sub_826C2864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C2868"))) PPC_WEAK_FUNC(sub_826C2868);
PPC_FUNC_IMPL(__imp__sub_826C2868) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// b 0x821f2060
	sub_821F2060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C2878"))) PPC_WEAK_FUNC(sub_826C2878);
PPC_FUNC_IMPL(__imp__sub_826C2878) {
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
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c289c
	if (cr6.eq) goto loc_826C289C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r11,r11,-9972
	r11.s64 = r11.s64 + -9972;
	// b 0x826c28a4
	goto loc_826C28A4;
loc_826C289C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r11,r11,-9996
	r11.s64 = r11.s64 + -9996;
loc_826C28A4:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r6,r4,144
	ctx.r6.s64 = ctx.r4.s64 + 144;
	// addi r5,r3,144
	ctx.r5.s64 = ctx.r3.s64 + 144;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,-27288(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27288);
	// bl 0x821f3628
	ctx.lr = 0x826C28BC;
	sub_821F3628(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c28e0
	if (cr6.eq) goto loc_826C28E0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r3,2260(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C28E0:
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

__attribute__((alias("__imp__sub_826C28F4"))) PPC_WEAK_FUNC(sub_826C28F4);
PPC_FUNC_IMPL(__imp__sub_826C28F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C28F8"))) PPC_WEAK_FUNC(sub_826C28F8);
PPC_FUNC_IMPL(__imp__sub_826C28F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// bl 0x823d91f0
	ctx.lr = 0x826C2900;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,-12012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -12012);
	// li r31,0
	r31.s64 = 0;
	// lfs f0,64(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 64);
	f0.f64 = double(temp.f32);
	// lfs f13,2244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 2244);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x826c2a44
	if (cr6.lt) goto loc_826C2A44;
	// bl 0x82256058
	ctx.lr = 0x826C2938;
	sub_82256058(ctx, base);
	// bl 0x82256168
	ctx.lr = 0x826C293C;
	sub_82256168(ctx, base);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x826c299c
	if (cr6.gt) goto loc_826C299C;
	// lis r12,-32148
	r12.s64 = -2106851328;
	// addi r12,r12,10592
	r12.s64 = r12.s64 + 10592;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826C297C;
	case 1:
		goto loc_826C297C;
	case 2:
		goto loc_826C299C;
	case 3:
		goto loc_826C299C;
	case 4:
		goto loc_826C299C;
	case 5:
		goto loc_826C297C;
	case 6:
		goto loc_826C2988;
	default:
		__builtin_unreachable();
	}
	// lwz r19,10620(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10620);
	// lwz r19,10620(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10620);
	// lwz r19,10652(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10652);
	// lwz r19,10652(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10652);
	// lwz r19,10652(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10652);
	// lwz r19,10620(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10620);
	// lwz r19,10632(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10632);
loc_826C297C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-9840
	ctx.r3.s64 = r11.s64 + -9840;
	// b 0x826c29f8
	goto loc_826C29F8;
loc_826C2988:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x826c2a80
	if (cr6.eq) goto loc_826C2A80;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-9856
	ctx.r3.s64 = r11.s64 + -9856;
	// b 0x826c29f8
	goto loc_826C29F8;
loc_826C299C:
	// cmplwi cr6,r26,3
	cr6.compare<uint32_t>(r26.u32, 3, xer);
	// bgt cr6,0x826c2a44
	if (cr6.gt) goto loc_826C2A44;
	// lis r12,-32148
	r12.s64 = -2106851328;
	// addi r12,r12,10684
	r12.s64 = r12.s64 + 10684;
	// rlwinm r0,r26,2,0,29
	r0.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r26.u64) {
	case 0:
		goto loc_826C29CC;
	case 1:
		goto loc_826C29D8;
	case 2:
		goto loc_826C29E4;
	case 3:
		goto loc_826C29F0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,10700(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10700);
	// lwz r19,10712(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10712);
	// lwz r19,10724(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10724);
	// lwz r19,10736(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 10736);
loc_826C29CC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-9888
	ctx.r3.s64 = r11.s64 + -9888;
	// b 0x826c29f8
	goto loc_826C29F8;
loc_826C29D8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-9920
	ctx.r3.s64 = r11.s64 + -9920;
	// b 0x826c29f8
	goto loc_826C29F8;
loc_826C29E4:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-9952
	ctx.r3.s64 = r11.s64 + -9952;
	// b 0x826c29f8
	goto loc_826C29F8;
loc_826C29F0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,24592
	ctx.r3.s64 = r11.s64 + 24592;
loc_826C29F8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826c2718
	ctx.lr = 0x826C2A04;
	sub_826C2718(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c2a44
	if (cr6.eq) goto loc_826C2A44;
	// lwz r11,-12012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -12012);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f2,15000(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15000);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-17876(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -17876);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,2244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 2244);
	f31.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x826C2A2C;
	sub_82145080(ctx, base);
	// fadds f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f31.f64));
	// stfs f0,64(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 64, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_826C2A44:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x826c2a80
	if (cr6.eq) goto loc_826C2A80;
	// li r4,99
	ctx.r4.s64 = 99;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82145020
	ctx.lr = 0x826C2A58;
	sub_82145020(ctx, base);
	// cmpwi cr6,r3,80
	cr6.compare<int32_t>(ctx.r3.s32, 80, xer);
	// ble cr6,0x826c2a80
	if (!cr6.gt) goto loc_826C2A80;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826C2A80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826C2A80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826C2A90"))) PPC_WEAK_FUNC(sub_826C2A90);
PPC_FUNC_IMPL(__imp__sub_826C2A90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x826c2aa8
	if (!cr6.lt) goto loc_826C2AA8;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_826C2AA8:
	// subfc r11,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	r11.s64 = ctx.r10.s64 - r11.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C2AB8"))) PPC_WEAK_FUNC(sub_826C2AB8);
PPC_FUNC_IMPL(__imp__sub_826C2AB8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-10132
	ctx.r10.s64 = r11.s64 + -10132;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821f49d8
	ctx.lr = 0x826C2AE4;
	sub_821F49D8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c2afc
	if (cr6.eq) goto loc_826C2AFC;
	// bl 0x82130588
	ctx.lr = 0x826C2AF8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826C2AFC:
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

__attribute__((alias("__imp__sub_826C2B14"))) PPC_WEAK_FUNC(sub_826C2B14);
PPC_FUNC_IMPL(__imp__sub_826C2B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C2B18"))) PPC_WEAK_FUNC(sub_826C2B18);
PPC_FUNC_IMPL(__imp__sub_826C2B18) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821f3938
	ctx.lr = 0x826C2B34;
	sub_821F3938(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r31,0
	r31.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-10132
	ctx.r9.s64 = r11.s64 + -10132;
	// stw r31,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r31.u32);
	// stw r10,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r10.u32);
	// li r4,12
	ctx.r4.s64 = 12;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r31,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r31.u32);
	// stw r31,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r31.u32);
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
	// stw r31,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r31.u32);
	// bl 0x82145020
	ctx.lr = 0x826C2B6C;
	sub_82145020(ctx, base);
	// stb r3,68(r30)
	PPC_STORE_U8(r30.u32 + 68, ctx.r3.u8);
	// li r4,70
	ctx.r4.s64 = 70;
	// li r3,65
	ctx.r3.s64 = 65;
	// bl 0x82145020
	ctx.lr = 0x826C2B7C;
	sub_82145020(ctx, base);
	// stb r3,69(r30)
	PPC_STORE_U8(r30.u32 + 69, ctx.r3.u8);
	// li r4,69
	ctx.r4.s64 = 69;
	// li r3,65
	ctx.r3.s64 = 65;
	// bl 0x82145020
	ctx.lr = 0x826C2B8C;
	sub_82145020(ctx, base);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// stw r31,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r5,70(r30)
	PPC_STORE_U8(r30.u32 + 70, ctx.r5.u8);
	// lwz r4,24(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x826C2BAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C2BC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_826C2BDC"))) PPC_WEAK_FUNC(sub_826C2BDC);
PPC_FUNC_IMPL(__imp__sub_826C2BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C2BE0"))) PPC_WEAK_FUNC(sub_826C2BE0);
PPC_FUNC_IMPL(__imp__sub_826C2BE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r5,-27288(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -27288);
	// lwz r3,60(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c2c18
	if (cr6.eq) goto loc_826C2C18;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x826C2C14;
	sub_8213C218(ctx, base);
	// lwz r5,-27288(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -27288);
loc_826C2C18:
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r31,1
	r31.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// lwz r3,-12012(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12012);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r11,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r11.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// addi r5,r5,60
	ctx.r5.s64 = ctx.r5.s64 + 60;
	// stb r31,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r31.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x825495a8
	ctx.lr = 0x826C2C68;
	sub_825495A8(ctx, base);
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

__attribute__((alias("__imp__sub_826C2C80"))) PPC_WEAK_FUNC(sub_826C2C80);
PPC_FUNC_IMPL(__imp__sub_826C2C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// b 0x821f2a60
	sub_821F2A60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C2C8C"))) PPC_WEAK_FUNC(sub_826C2C8C);
PPC_FUNC_IMPL(__imp__sub_826C2C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C2C90"))) PPC_WEAK_FUNC(sub_826C2C90);
PPC_FUNC_IMPL(__imp__sub_826C2C90) {
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
	ctx.lr = 0x826C2C98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x82700880
	ctx.lr = 0x826C2CB8;
	sub_82700880(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c2d0c
	if (cr6.eq) goto loc_826C2D0C;
	// bl 0x82224ac8
	ctx.lr = 0x826C2CC8;
	sub_82224AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c2cf0
	if (cr6.eq) goto loc_826C2CF0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r11,-9724
	ctx.r3.s64 = r11.s64 + -9724;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x826c2718
	ctx.lr = 0x826C2CE8;
	sub_826C2718(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826C2CF0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,-9756
	ctx.r3.s64 = r11.s64 + -9756;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x826c2718
	ctx.lr = 0x826C2D04;
	sub_826C2718(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826C2D0C:
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bgt cr6,0x826c2d20
	if (cr6.gt) goto loc_826C2D20;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,-9776
	ctx.r4.s64 = r11.s64 + -9776;
	// b 0x826c2d48
	goto loc_826C2D48;
loc_826C2D20:
	// lwz r11,3096(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x826c2d40
	if (!cr6.gt) goto loc_826C2D40;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826c2d40
	if (cr6.lt) goto loc_826C2D40;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,-9796
	ctx.r4.s64 = r11.s64 + -9796;
	// b 0x826c2d48
	goto loc_826C2D48;
loc_826C2D40:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,-9820
	ctx.r4.s64 = r11.s64 + -9820;
loc_826C2D48:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r6,r28,144
	ctx.r6.s64 = r28.s64 + 144;
	// addi r5,r27,144
	ctx.r5.s64 = r27.s64 + 144;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// bl 0x821f3628
	ctx.lr = 0x826C2D5C;
	sub_821F3628(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c2d78
	if (cr6.eq) goto loc_826C2D78;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r3,2260(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826C2D78:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826C2D84"))) PPC_WEAK_FUNC(sub_826C2D84);
PPC_FUNC_IMPL(__imp__sub_826C2D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C2D88"))) PPC_WEAK_FUNC(sub_826C2D88);
PPC_FUNC_IMPL(__imp__sub_826C2D88) {
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
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x82130528
	ctx.lr = 0x826C2D9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c2dc0
	if (cr6.eq) goto loc_826C2DC0;
	// bl 0x826c2b18
	ctx.lr = 0x826C2DA8;
	sub_826C2B18(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-27288(r11)
	PPC_STORE_U32(r11.u32 + -27288, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C2DC0:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-27288(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27288, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C2DDC"))) PPC_WEAK_FUNC(sub_826C2DDC);
PPC_FUNC_IMPL(__imp__sub_826C2DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C2DE0"))) PPC_WEAK_FUNC(sub_826C2DE0);
PPC_FUNC_IMPL(__imp__sub_826C2DE0) {
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
	ctx.lr = 0x826C2DE8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r9,-9600
	ctx.r5.s64 = ctx.r9.s64 + -9600;
	// addi r6,r10,-9584
	ctx.r6.s64 = ctx.r10.s64 + -9584;
	// addi r10,r8,-9616
	ctx.r10.s64 = ctx.r8.s64 + -9616;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// addi r9,r7,-9632
	ctx.r9.s64 = ctx.r7.s64 + -9632;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826C2E38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826C2E54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826c2ff4
	if (cr6.eq) goto loc_826C2FF4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r11,-9652
	r29.s64 = r11.s64 + -9652;
	// addi r25,r10,-9660
	r25.s64 = ctx.r10.s64 + -9660;
	// addi r27,r9,-9676
	r27.s64 = ctx.r9.s64 + -9676;
	// addi r26,r8,-9692
	r26.s64 = ctx.r8.s64 + -9692;
	// addi r28,r7,-10052
	r28.s64 = ctx.r7.s64 + -10052;
loc_826C2E90:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_826C2EA4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826c2ec8
	if (cr6.eq) goto loc_826C2EC8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c2ea4
	if (cr6.eq) goto loc_826C2EA4;
loc_826C2EC8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c2ed8
	if (!cr6.eq) goto loc_826C2ED8;
	// stw r8,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r8.u32);
	// b 0x826c2fe0
	goto loc_826C2FE0;
loc_826C2ED8:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_826C2EE0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826c2f04
	if (cr6.eq) goto loc_826C2F04;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c2ee0
	if (cr6.eq) goto loc_826C2EE0;
loc_826C2F04:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c2f14
	if (!cr6.eq) goto loc_826C2F14;
	// stw r8,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r8.u32);
	// b 0x826c2fe0
	goto loc_826C2FE0;
loc_826C2F14:
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_826C2F1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826c2f40
	if (cr6.eq) goto loc_826C2F40;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c2f1c
	if (cr6.eq) goto loc_826C2F1C;
loc_826C2F40:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c2f50
	if (!cr6.eq) goto loc_826C2F50;
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
	// b 0x826c2fe0
	goto loc_826C2FE0;
loc_826C2F50:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821c7d28
	ctx.lr = 0x826C2F5C;
	sub_821C7D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c2fe0
	if (cr6.eq) goto loc_826C2FE0;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r5,0
	ctx.r5.s64 = 0;
	// add r6,r30,r11
	ctx.r6.u64 = r30.u64 + r11.u64;
	// stw r6,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r6.u32);
	// lhz r11,12(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c2fe0
	if (cr6.eq) goto loc_826C2FE0;
	// li r7,0
	ctx.r7.s64 = 0;
loc_826C2F88:
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// add r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 + r11.u64;
	// lwzx r11,r7,r11
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
loc_826C2F98:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
	// beq cr6,0x826c2fbc
	if (cr6.eq) goto loc_826C2FBC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c2f98
	if (cr6.eq) goto loc_826C2F98;
loc_826C2FBC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c2fc8
	if (!cr6.eq) goto loc_826C2FC8;
	// stw r8,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r8.u32);
loc_826C2FC8:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,24
	ctx.r7.s64 = ctx.r7.s64 + 24;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// blt cr6,0x826c2f88
	if (cr6.lt) goto loc_826C2F88;
loc_826C2FE0:
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x826c2e90
	if (cr6.lt) goto loc_826C2E90;
loc_826C2FF4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826C2FFC"))) PPC_WEAK_FUNC(sub_826C2FFC);
PPC_FUNC_IMPL(__imp__sub_826C2FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3000"))) PPC_WEAK_FUNC(sub_826C3000);
PPC_FUNC_IMPL(__imp__sub_826C3000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826C3008;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x821c9790
	ctx.lr = 0x826C3028;
	sub_821C9790(ctx, base);
	// lhz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826c305c
	if (cr6.eq) goto loc_826C305C;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de288
	ctx.lr = 0x826C3050;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x826c3060
	if (!cr6.eq) goto loc_826C3060;
loc_826C305C:
	// li r11,0
	r11.s64 = 0;
loc_826C3060:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x826c34f4
	if (cr6.gt) goto loc_826C34F4;
	// lis r12,-32148
	r12.s64 = -2106851328;
	// addi r12,r12,12420
	r12.s64 = r12.s64 + 12420;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826C30A8;
	case 1:
		goto loc_826C30F0;
	case 2:
		goto loc_826C3148;
	case 3:
		goto loc_826C318C;
	case 4:
		goto loc_826C322C;
	case 5:
		goto loc_826C32EC;
	case 6:
		goto loc_826C33AC;
	case 7:
		goto loc_826C3414;
	case 8:
		goto loc_826C347C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,12456(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12456);
	// lwz r19,12528(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12528);
	// lwz r19,12616(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12616);
	// lwz r19,12684(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12684);
	// lwz r19,12844(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12844);
	// lwz r19,13036(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 13036);
	// lwz r19,13228(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 13228);
	// lwz r19,13332(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 13332);
	// lwz r19,13436(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 13436);
loc_826C30A8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,-9408
	ctx.r5.s64 = r11.s64 + -9408;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C30BC;
	sub_82137A08(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r10,r30,264
	ctx.r10.s64 = r30.s64 + 264;
	// addi r11,r9,-10164
	r11.s64 = ctx.r9.s64 + -10164;
	// li r9,7
	ctx.r9.s64 = 7;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826C30D0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826c30d0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826C30D0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C30F0:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C3100;
	sub_82137A08(ctx, base);
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x826c3120
	if (cr6.eq) goto loc_826C3120;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// addi r10,r11,11232
	ctx.r10.s64 = r11.s64 + 11232;
	// stw r10,432(r30)
	PPC_STORE_U32(r30.u32 + 432, ctx.r10.u32);
loc_826C3120:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-9436
	ctx.r3.s64 = r11.s64 + -9436;
	// bl 0x821c9790
	ctx.lr = 0x826C3130;
	sub_821C9790(ctx, base);
	// stw r3,436(r30)
	PPC_STORE_U32(r30.u32 + 436, ctx.r3.u32);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,408(r30)
	PPC_STORE_U32(r30.u32 + 408, ctx.r10.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C3148:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C3158;
	sub_82137A08(ctx, base);
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x826c3178
	if (cr6.eq) goto loc_826C3178;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// addi r10,r11,9800
	ctx.r10.s64 = r11.s64 + 9800;
	// stw r10,432(r30)
	PPC_STORE_U32(r30.u32 + 432, ctx.r10.u32);
loc_826C3178:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,408(r30)
	PPC_STORE_U32(r30.u32 + 408, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C318C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,-9452
	ctx.r5.s64 = r11.s64 + -9452;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C31A0;
	sub_82137A08(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,-12348(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c31e8
	if (!cr6.eq) goto loc_826C31E8;
	// bl 0x82256058
	ctx.lr = 0x826C31BC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c31e0
	if (cr6.eq) goto loc_826C31E0;
	// bl 0x82256058
	ctx.lr = 0x826C31C8;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826c31e0
	if (cr0.eq) goto loc_826C31E0;
	// bl 0x82256058
	ctx.lr = 0x826C31D4;
	sub_82256058(ctx, base);
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c31e8
	if (!cr6.eq) goto loc_826C31E8;
loc_826C31E0:
	// li r11,0
	r11.s64 = 0;
	// b 0x826c31ec
	goto loc_826C31EC;
loc_826C31E8:
	// li r11,1
	r11.s64 = 1;
loc_826C31EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c3218
	if (!cr6.eq) goto loc_826C3218;
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// stb r10,68(r31)
	PPC_STORE_U8(r31.u32 + 68, ctx.r10.u8);
	// cmplwi cr6,r10,12
	cr6.compare<uint32_t>(ctx.r10.u32, 12, xer);
	// ble cr6,0x826c3218
	if (!cr6.gt) goto loc_826C3218;
	// li r11,1
	r11.s64 = 1;
	// stb r11,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r11.u8);
loc_826C3218:
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,424(r30)
	PPC_STORE_U32(r30.u32 + 424, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C322C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c32bc
	if (cr6.eq) goto loc_826C32BC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c3284
	if (!cr6.eq) goto loc_826C3284;
	// bl 0x82256058
	ctx.lr = 0x826C3258;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c327c
	if (cr6.eq) goto loc_826C327C;
	// bl 0x82256058
	ctx.lr = 0x826C3264;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826c327c
	if (cr0.eq) goto loc_826C327C;
	// bl 0x82256058
	ctx.lr = 0x826C3270;
	sub_82256058(ctx, base);
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c3284
	if (!cr6.eq) goto loc_826C3284;
loc_826C327C:
	// li r11,0
	r11.s64 = 0;
	// b 0x826c3288
	goto loc_826C3288;
loc_826C3284:
	// li r11,1
	r11.s64 = 1;
loc_826C3288:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c32b4
	if (!cr6.eq) goto loc_826C32B4;
	// lbz r11,69(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,69(r31)
	PPC_STORE_U8(r31.u32 + 69, ctx.r9.u8);
	// cmpwi cr6,r9,70
	cr6.compare<int32_t>(ctx.r9.s32, 70, xer);
	// ble cr6,0x826c32b4
	if (!cr6.gt) goto loc_826C32B4;
	// li r11,65
	r11.s64 = 65;
	// stb r11,69(r31)
	PPC_STORE_U8(r31.u32 + 69, r11.u8);
loc_826C32B4:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// b 0x826c32c0
	goto loc_826C32C0;
loc_826C32BC:
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
loc_826C32C0:
	// lbz r9,69(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r5,r10,-9476
	ctx.r5.s64 = ctx.r10.s64 + -9476;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C32E0;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C32EC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c337c
	if (cr6.eq) goto loc_826C337C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c3344
	if (!cr6.eq) goto loc_826C3344;
	// bl 0x82256058
	ctx.lr = 0x826C3318;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c333c
	if (cr6.eq) goto loc_826C333C;
	// bl 0x82256058
	ctx.lr = 0x826C3324;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826c333c
	if (cr0.eq) goto loc_826C333C;
	// bl 0x82256058
	ctx.lr = 0x826C3330;
	sub_82256058(ctx, base);
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c3344
	if (!cr6.eq) goto loc_826C3344;
loc_826C333C:
	// li r11,0
	r11.s64 = 0;
	// b 0x826c3348
	goto loc_826C3348;
loc_826C3344:
	// li r11,1
	r11.s64 = 1;
loc_826C3348:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c3374
	if (!cr6.eq) goto loc_826C3374;
	// lbz r11,69(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,69(r31)
	PPC_STORE_U8(r31.u32 + 69, ctx.r9.u8);
	// cmpwi cr6,r9,70
	cr6.compare<int32_t>(ctx.r9.s32, 70, xer);
	// ble cr6,0x826c3374
	if (!cr6.gt) goto loc_826C3374;
	// li r11,65
	r11.s64 = 65;
	// stb r11,69(r31)
	PPC_STORE_U8(r31.u32 + 69, r11.u8);
loc_826C3374:
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
	// b 0x826c3380
	goto loc_826C3380;
loc_826C337C:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
loc_826C3380:
	// lbz r9,69(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r5,r10,-9500
	ctx.r5.s64 = ctx.r10.s64 + -9500;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C33A0;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C33AC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c33c4
	if (cr6.eq) goto loc_826C33C4;
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// b 0x826c33e8
	goto loc_826C33E8;
loc_826C33C4:
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,70(r31)
	PPC_STORE_U8(r31.u32 + 70, ctx.r9.u8);
	// cmpwi cr6,r9,69
	cr6.compare<int32_t>(ctx.r9.s32, 69, xer);
	// ble cr6,0x826c33e4
	if (!cr6.gt) goto loc_826C33E4;
	// li r11,65
	r11.s64 = 65;
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
loc_826C33E4:
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
loc_826C33E8:
	// lbz r9,70(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r5,r10,-9532
	ctx.r5.s64 = ctx.r10.s64 + -9532;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C3408;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C3414:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c342c
	if (cr6.eq) goto loc_826C342C;
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// b 0x826c3450
	goto loc_826C3450;
loc_826C342C:
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,70(r31)
	PPC_STORE_U8(r31.u32 + 70, ctx.r9.u8);
	// cmpwi cr6,r9,69
	cr6.compare<int32_t>(ctx.r9.s32, 69, xer);
	// ble cr6,0x826c344c
	if (!cr6.gt) goto loc_826C344C;
	// li r11,65
	r11.s64 = 65;
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
loc_826C344C:
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
loc_826C3450:
	// lbz r9,70(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r5,r10,-9568
	ctx.r5.s64 = ctx.r10.s64 + -9568;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C3470;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C347C:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r10,-26992
	ctx.r5.s64 = ctx.r10.s64 + -26992;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82137a08
	ctx.lr = 0x826C34A0;
	sub_82137A08(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,-26224(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -26224);
	// bl 0x8215b4d0
	ctx.lr = 0x826C34B0;
	sub_8215B4D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c34d4
	if (cr6.eq) goto loc_826C34D4;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r5,-26224(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -26224);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C34C8;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C34D4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,-26228(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -26228);
	// bl 0x82137a08
	ctx.lr = 0x826C34E8;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C34F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826C3500"))) PPC_WEAK_FUNC(sub_826C3500);
PPC_FUNC_IMPL(__imp__sub_826C3500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,2260(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C352C"))) PPC_WEAK_FUNC(sub_826C352C);
PPC_FUNC_IMPL(__imp__sub_826C352C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3530"))) PPC_WEAK_FUNC(sub_826C3530);
PPC_FUNC_IMPL(__imp__sub_826C3530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-12012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r11,2260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c3568
	if (cr6.eq) goto loc_826C3568;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x826c3568
	if (!cr6.eq) goto loc_826C3568;
	// lwz r11,2256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2256);
	// lwz r10,420(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826c356c
	if (cr6.eq) goto loc_826C356C;
loc_826C3568:
	// li r11,0
	r11.s64 = 0;
loc_826C356C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C357C"))) PPC_WEAK_FUNC(sub_826C357C);
PPC_FUNC_IMPL(__imp__sub_826C357C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3580"))) PPC_WEAK_FUNC(sub_826C3580);
PPC_FUNC_IMPL(__imp__sub_826C3580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821f1d58
	sub_821F1D58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826C3598"))) PPC_WEAK_FUNC(sub_826C3598);
PPC_FUNC_IMPL(__imp__sub_826C3598) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x826c2c90
	ctx.lr = 0x826C35C4;
	sub_826C2C90(ctx, base);
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

__attribute__((alias("__imp__sub_826C35E0"))) PPC_WEAK_FUNC(sub_826C35E0);
PPC_FUNC_IMPL(__imp__sub_826C35E0) {
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
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// bl 0x826c2878
	ctx.lr = 0x826C3618;
	sub_826C2878(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_826C3634"))) PPC_WEAK_FUNC(sub_826C3634);
PPC_FUNC_IMPL(__imp__sub_826C3634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3638"))) PPC_WEAK_FUNC(sub_826C3638);
PPC_FUNC_IMPL(__imp__sub_826C3638) {
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
	ctx.lr = 0x826C3640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x826C3654;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// stb r28,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r28.u8);
	// bl 0x82130528
	ctx.lr = 0x826C3674;
	sub_82130528(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-9408
	ctx.r3.s64 = ctx.r10.s64 + -9408;
	// bl 0x821c9790
	ctx.lr = 0x826C3690;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C36A4;
	sub_824787B0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r8,-9284
	ctx.r3.s64 = ctx.r8.s64 + -9284;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C36C0;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C36D4;
	sub_824787B0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,-9304
	ctx.r3.s64 = ctx.r6.s64 + -9304;
	// stw r27,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r27.u32);
	// stw r28,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r28.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C36F0;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C3704;
	sub_824787B0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r11,2
	r11.s64 = 2;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-9452
	ctx.r3.s64 = ctx.r10.s64 + -9452;
	// stw r27,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r27.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C3724;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C3738;
	sub_824787B0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,3
	ctx.r8.s64 = 3;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,-9324
	ctx.r3.s64 = ctx.r7.s64 + -9324;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C3758;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C376C;
	sub_824787B0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,-9344
	ctx.r3.s64 = ctx.r3.s64 + -9344;
	// stw r27,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r27.u32);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C378C;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C37A0;
	sub_824787B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,5
	ctx.r10.s64 = 5;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,-9372
	ctx.r3.s64 = ctx.r9.s64 + -9372;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C37C0;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C37D4;
	sub_824787B0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r7,6
	ctx.r7.s64 = 6;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,-9400
	ctx.r3.s64 = ctx.r6.s64 + -9400;
	// stw r27,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C37F4;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C3808;
	sub_824787B0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r11,7
	r11.s64 = 7;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-9856
	ctx.r3.s64 = ctx.r10.s64 + -9856;
	// stw r27,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r27.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C3828;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C383C;
	sub_824787B0(ctx, base);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c3878
	if (!cr6.eq) goto loc_826C3878;
	// lhz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c3874
	if (cr6.eq) goto loc_826C3874;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r6,r11,10896
	ctx.r6.s64 = r11.s64 + 10896;
	// bl 0x823dcf08
	ctx.lr = 0x826C3874;
	sub_823DCF08(ctx, base);
loc_826C3874:
	// stb r28,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r28.u8);
loc_826C3878:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826C3880"))) PPC_WEAK_FUNC(sub_826C3880);
PPC_FUNC_IMPL(__imp__sub_826C3880) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x821f3468
	ctx.lr = 0x826C38B0;
	sub_821F3468(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_826C38D0"))) PPC_WEAK_FUNC(sub_826C38D0);
PPC_FUNC_IMPL(__imp__sub_826C38D0) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x821f3628
	ctx.lr = 0x826C3900;
	sub_821F3628(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c3930
	if (cr6.eq) goto loc_826C3930;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2260);
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
loc_826C3930:
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

__attribute__((alias("__imp__sub_826C394C"))) PPC_WEAK_FUNC(sub_826C394C);
PPC_FUNC_IMPL(__imp__sub_826C394C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3950"))) PPC_WEAK_FUNC(sub_826C3950);
PPC_FUNC_IMPL(__imp__sub_826C3950) {
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
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27288);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r5,r11,144
	ctx.r5.s64 = r11.s64 + 144;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r10,144
	ctx.r6.s64 = ctx.r10.s64 + 144;
	// bl 0x821f3628
	ctx.lr = 0x826C3988;
	sub_821F3628(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c39b8
	if (cr6.eq) goto loc_826C39B8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2260);
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
loc_826C39B8:
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

__attribute__((alias("__imp__sub_826C39D4"))) PPC_WEAK_FUNC(sub_826C39D4);
PPC_FUNC_IMPL(__imp__sub_826C39D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C39D8"))) PPC_WEAK_FUNC(sub_826C39D8);
PPC_FUNC_IMPL(__imp__sub_826C39D8) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x826c2778
	ctx.lr = 0x826C3A00;
	sub_826C2778(ctx, base);
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

__attribute__((alias("__imp__sub_826C3A1C"))) PPC_WEAK_FUNC(sub_826C3A1C);
PPC_FUNC_IMPL(__imp__sub_826C3A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3A20"))) PPC_WEAK_FUNC(sub_826C3A20);
PPC_FUNC_IMPL(__imp__sub_826C3A20) {
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
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27288);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r5,r11,144
	ctx.r5.s64 = r11.s64 + 144;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r10,144
	ctx.r6.s64 = ctx.r10.s64 + 144;
	// bl 0x821f3730
	ctx.lr = 0x826C3A58;
	sub_821F3730(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_826C3A74"))) PPC_WEAK_FUNC(sub_826C3A74);
PPC_FUNC_IMPL(__imp__sub_826C3A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3A78"))) PPC_WEAK_FUNC(sub_826C3A78);
PPC_FUNC_IMPL(__imp__sub_826C3A78) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x821f32d0
	ctx.lr = 0x826C3AB4;
	sub_821F32D0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c3ae8
	if (cr6.eq) goto loc_826C3AE8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2260);
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
loc_826C3AE8:
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

__attribute__((alias("__imp__sub_826C3B04"))) PPC_WEAK_FUNC(sub_826C3B04);
PPC_FUNC_IMPL(__imp__sub_826C3B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3B08"))) PPC_WEAK_FUNC(sub_826C3B08);
PPC_FUNC_IMPL(__imp__sub_826C3B08) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x821f2060
	ctx.lr = 0x826C3B30;
	sub_821F2060(ctx, base);
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

__attribute__((alias("__imp__sub_826C3B4C"))) PPC_WEAK_FUNC(sub_826C3B4C);
PPC_FUNC_IMPL(__imp__sub_826C3B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3B50"))) PPC_WEAK_FUNC(sub_826C3B50);
PPC_FUNC_IMPL(__imp__sub_826C3B50) {
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
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,14464
	ctx.r4.s64 = r11.s64 + 14464;
	// addi r3,r10,-8836
	ctx.r3.s64 = ctx.r10.s64 + -8836;
	// bl 0x82554798
	ctx.lr = 0x826C3B70;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,14544
	ctx.r4.s64 = ctx.r9.s64 + 14544;
	// addi r3,r8,-8872
	ctx.r3.s64 = ctx.r8.s64 + -8872;
	// bl 0x82554798
	ctx.lr = 0x826C3B84;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,14672
	ctx.r4.s64 = ctx.r7.s64 + 14672;
	// addi r3,r6,-8908
	ctx.r3.s64 = ctx.r6.s64 + -8908;
	// bl 0x82554798
	ctx.lr = 0x826C3B98;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,13568
	ctx.r4.s64 = ctx.r5.s64 + 13568;
	// addi r3,r3,-8944
	ctx.r3.s64 = ctx.r3.s64 + -8944;
	// bl 0x82554798
	ctx.lr = 0x826C3BAC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,9936
	ctx.r4.s64 = r11.s64 + 9936;
	// addi r3,r10,-8964
	ctx.r3.s64 = ctx.r10.s64 + -8964;
	// bl 0x82554798
	ctx.lr = 0x826C3BC0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,14808
	ctx.r4.s64 = ctx.r9.s64 + 14808;
	// addi r3,r8,-8996
	ctx.r3.s64 = ctx.r8.s64 + -8996;
	// bl 0x82554798
	ctx.lr = 0x826C3BD4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,14880
	ctx.r4.s64 = ctx.r7.s64 + 14880;
	// addi r3,r6,-9032
	ctx.r3.s64 = ctx.r6.s64 + -9032;
	// bl 0x82554798
	ctx.lr = 0x826C3BE8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,14968
	ctx.r4.s64 = ctx.r5.s64 + 14968;
	// addi r3,r3,-9068
	ctx.r3.s64 = ctx.r3.s64 + -9068;
	// bl 0x82554798
	ctx.lr = 0x826C3BFC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,13616
	ctx.r4.s64 = r11.s64 + 13616;
	// addi r3,r10,-9104
	ctx.r3.s64 = ctx.r10.s64 + -9104;
	// bl 0x82554798
	ctx.lr = 0x826C3C10;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,11392
	ctx.r4.s64 = ctx.r9.s64 + 11392;
	// addi r3,r8,-9140
	ctx.r3.s64 = ctx.r8.s64 + -9140;
	// bl 0x82554798
	ctx.lr = 0x826C3C24;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,15112
	ctx.r4.s64 = ctx.r7.s64 + 15112;
	// addi r3,r6,-9168
	ctx.r3.s64 = ctx.r6.s64 + -9168;
	// bl 0x82554798
	ctx.lr = 0x826C3C38;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,13696
	ctx.r4.s64 = ctx.r5.s64 + 13696;
	// addi r3,r3,-9196
	ctx.r3.s64 = ctx.r3.s64 + -9196;
	// bl 0x82554798
	ctx.lr = 0x826C3C4C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,13720
	ctx.r4.s64 = r11.s64 + 13720;
	// addi r3,r10,-9228
	ctx.r3.s64 = ctx.r10.s64 + -9228;
	// bl 0x82554798
	ctx.lr = 0x826C3C60;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,13792
	ctx.r4.s64 = ctx.r9.s64 + 13792;
	// addi r3,r8,-9264
	ctx.r3.s64 = ctx.r8.s64 + -9264;
	// bl 0x82554798
	ctx.lr = 0x826C3C74;
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

__attribute__((alias("__imp__sub_826C3C84"))) PPC_WEAK_FUNC(sub_826C3C84);
PPC_FUNC_IMPL(__imp__sub_826C3C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3C88"))) PPC_WEAK_FUNC(sub_826C3C88);
PPC_FUNC_IMPL(__imp__sub_826C3C88) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x821378b8
	ctx.lr = 0x826C3CA4;
	sub_821378B8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-8808
	ctx.r3.s64 = r11.s64 + -8808;
	// bl 0x821378b8
	ctx.lr = 0x826C3CB4;
	sub_821378B8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r11,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r11.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r11.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r11.u8);
	// bl 0x821f1138
	ctx.lr = 0x826C3CE0;
	sub_821F1138(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x826c3d14
	if (!cr6.eq) goto loc_826C3D14;
	// bl 0x821d2aa0
	ctx.lr = 0x826C3CF4;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x826C3CFC;
	sub_821D2AA0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_826C3D14:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x826C3D2C;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x826C3D34;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_826C3D4C"))) PPC_WEAK_FUNC(sub_826C3D4C);
PPC_FUNC_IMPL(__imp__sub_826C3D4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826C3D50"))) PPC_WEAK_FUNC(sub_826C3D50);
PPC_FUNC_IMPL(__imp__sub_826C3D50) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-8448
	ctx.r9.s64 = r11.s64 + -8448;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826c3d84
	if (cr6.eq) goto loc_826C3D84;
	// bl 0x82130588
	ctx.lr = 0x826C3D80;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826C3D84:
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

__attribute__((alias("__imp__sub_826C3D98"))) PPC_WEAK_FUNC(sub_826C3D98);
PPC_FUNC_IMPL(__imp__sub_826C3D98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,13
	r11.s64 = ctx.r4.s64 + 13;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826C3DA8"))) PPC_WEAK_FUNC(sub_826C3DA8);
PPC_FUNC_IMPL(__imp__sub_826C3DA8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618670
	ctx.lr = 0x826C3DCC;
	sub_82618670(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// and r7,r9,r3
	ctx.r7.u64 = ctx.r9.u64 & ctx.r3.u64;
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// lwzx r4,r8,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stwx r10,r3,r5
	PPC_STORE_U32(ctx.r3.u32 + ctx.r5.u32, ctx.r10.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_826C3E34"))) PPC_WEAK_FUNC(sub_826C3E34);
PPC_FUNC_IMPL(__imp__sub_826C3E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

