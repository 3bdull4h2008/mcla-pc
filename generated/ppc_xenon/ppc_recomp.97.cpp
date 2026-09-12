#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_824DDD48"))) PPC_WEAK_FUNC(sub_824DDD48);
PPC_FUNC_IMPL(__imp__sub_824DDD48) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ddd8c
	if (!cr6.eq) goto loc_824DDD8C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x824ddd84
	if (cr6.eq) goto loc_824DDD84;
	// bl 0x824dd998
	ctx.lr = 0x824DDD80;
	sub_824DD998(ctx, base);
	// b 0x824ddd88
	goto loc_824DDD88;
loc_824DDD84:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824DDD88:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_824DDD8C:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
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

__attribute__((alias("__imp__sub_824DDDA8"))) PPC_WEAK_FUNC(sub_824DDDA8);
PPC_FUNC_IMPL(__imp__sub_824DDDA8) {
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
	ctx.lr = 0x824DDDB0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r10,r11,8924
	ctx.r10.s64 = r11.s64 + 8924;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824ddc68
	ctx.lr = 0x824DDDD4;
	sub_824DDC68(ctx, base);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDDE4;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDDEC;
	sub_821B5A60(ctx, base);
	// addi r30,r31,68
	r30.s64 = r31.s64 + 68;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDDFC;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDE04;
	sub_821B5A60(ctx, base);
	// addi r30,r31,120
	r30.s64 = r31.s64 + 120;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDE14;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDE1C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,172
	r30.s64 = r31.s64 + 172;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDE2C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDE34;
	sub_821B5A60(ctx, base);
	// addi r30,r31,224
	r30.s64 = r31.s64 + 224;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDE44;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDE4C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,276
	r30.s64 = r31.s64 + 276;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDE5C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDE64;
	sub_821B5A60(ctx, base);
	// addi r30,r31,328
	r30.s64 = r31.s64 + 328;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDE74;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDE7C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,380
	r30.s64 = r31.s64 + 380;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDE8C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDE94;
	sub_821B5A60(ctx, base);
	// addi r30,r31,432
	r30.s64 = r31.s64 + 432;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDEA4;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDEAC;
	sub_821B5A60(ctx, base);
	// addi r30,r31,484
	r30.s64 = r31.s64 + 484;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDEBC;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDEC4;
	sub_821B5A60(ctx, base);
	// addi r30,r31,536
	r30.s64 = r31.s64 + 536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDED4;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDEDC;
	sub_821B5A60(ctx, base);
	// addi r30,r31,588
	r30.s64 = r31.s64 + 588;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDEEC;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDEF4;
	sub_821B5A60(ctx, base);
	// addi r30,r31,640
	r30.s64 = r31.s64 + 640;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDF04;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDF0C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,692
	r30.s64 = r31.s64 + 692;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDF1C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDF24;
	sub_821B5A60(ctx, base);
	// addi r30,r31,744
	r30.s64 = r31.s64 + 744;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDF34;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDF3C;
	sub_821B5A60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824DDF48"))) PPC_WEAK_FUNC(sub_824DDF48);
PPC_FUNC_IMPL(__imp__sub_824DDF48) {
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
	ctx.lr = 0x824DDF50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824ddda8
	ctx.lr = 0x824DDF60;
	sub_824DDDA8(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,796
	r30.s64 = r31.s64 + 796;
	// addi r10,r11,10412
	ctx.r10.s64 = r11.s64 + 10412;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDF7C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDF84;
	sub_821B5A60(ctx, base);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDF94;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDF9C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,900
	r30.s64 = r31.s64 + 900;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDFAC;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDFB4;
	sub_821B5A60(ctx, base);
	// addi r30,r31,952
	r30.s64 = r31.s64 + 952;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDFC4;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDFCC;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1004
	r30.s64 = r31.s64 + 1004;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDFDC;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDFE4;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1056
	r30.s64 = r31.s64 + 1056;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DDFF4;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DDFFC;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1108
	r30.s64 = r31.s64 + 1108;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE00C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE014;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1160
	r30.s64 = r31.s64 + 1160;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE024;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE02C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1212
	r30.s64 = r31.s64 + 1212;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE03C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE044;
	sub_821B5A60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824DE050"))) PPC_WEAK_FUNC(sub_824DE050);
PPC_FUNC_IMPL(__imp__sub_824DE050) {
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
	ctx.lr = 0x824DE058;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824ddda8
	ctx.lr = 0x824DE068;
	sub_824DDDA8(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,796
	r30.s64 = r31.s64 + 796;
	// addi r10,r11,8940
	ctx.r10.s64 = r11.s64 + 8940;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE084;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE08C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE09C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE0A4;
	sub_821B5A60(ctx, base);
	// addi r30,r31,900
	r30.s64 = r31.s64 + 900;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE0B4;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE0BC;
	sub_821B5A60(ctx, base);
	// addi r30,r31,952
	r30.s64 = r31.s64 + 952;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE0CC;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE0D4;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1004
	r30.s64 = r31.s64 + 1004;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE0E4;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE0EC;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1056
	r30.s64 = r31.s64 + 1056;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE0FC;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE104;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1108
	r30.s64 = r31.s64 + 1108;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE114;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE11C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1160
	r30.s64 = r31.s64 + 1160;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE12C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE134;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1212
	r30.s64 = r31.s64 + 1212;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE144;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE14C;
	sub_821B5A60(ctx, base);
	// addi r30,r31,1264
	r30.s64 = r31.s64 + 1264;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82496728
	ctx.lr = 0x824DE15C;
	sub_82496728(ctx, base);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821b5a60
	ctx.lr = 0x824DE164;
	sub_821B5A60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824DE170"))) PPC_WEAK_FUNC(sub_824DE170);
PPC_FUNC_IMPL(__imp__sub_824DE170) {
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
	// li r3,796
	ctx.r3.s64 = 796;
	// bl 0x82130528
	ctx.lr = 0x824DE184;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824de1a0
	if (cr6.eq) goto loc_824DE1A0;
	// bl 0x824b92a8
	ctx.lr = 0x824DE190;
	sub_824B92A8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824DE1A0:
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

__attribute__((alias("__imp__sub_824DE1B4"))) PPC_WEAK_FUNC(sub_824DE1B4);
PPC_FUNC_IMPL(__imp__sub_824DE1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DE1B8"))) PPC_WEAK_FUNC(sub_824DE1B8);
PPC_FUNC_IMPL(__imp__sub_824DE1B8) {
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
	// li r3,1264
	ctx.r3.s64 = 1264;
	// bl 0x82130528
	ctx.lr = 0x824DE1CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824de1e8
	if (cr6.eq) goto loc_824DE1E8;
	// bl 0x824bf908
	ctx.lr = 0x824DE1D8;
	sub_824BF908(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824DE1E8:
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

__attribute__((alias("__imp__sub_824DE1FC"))) PPC_WEAK_FUNC(sub_824DE1FC);
PPC_FUNC_IMPL(__imp__sub_824DE1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DE200"))) PPC_WEAK_FUNC(sub_824DE200);
PPC_FUNC_IMPL(__imp__sub_824DE200) {
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
	// li r3,1316
	ctx.r3.s64 = 1316;
	// bl 0x82130528
	ctx.lr = 0x824DE214;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824de230
	if (cr6.eq) goto loc_824DE230;
	// bl 0x824b97a8
	ctx.lr = 0x824DE220;
	sub_824B97A8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824DE230:
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

__attribute__((alias("__imp__sub_824DE244"))) PPC_WEAK_FUNC(sub_824DE244);
PPC_FUNC_IMPL(__imp__sub_824DE244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DE248"))) PPC_WEAK_FUNC(sub_824DE248);
PPC_FUNC_IMPL(__imp__sub_824DE248) {
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
	ctx.lr = 0x824DE250;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r11,30020
	r28.s64 = r11.s64 + 30020;
	// lwz r11,30020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824de598
	if (!cr6.eq) goto loc_824DE598;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824DE270;
	sub_82130528(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824de284
	if (cr6.eq) goto loc_824DE284;
	// bl 0x821d5408
	ctx.lr = 0x824DE280;
	sub_821D5408(ctx, base);
	// b 0x824de288
	goto loc_824DE288;
loc_824DE284:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824DE288:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r7,r10,24416
	ctx.r7.s64 = ctx.r10.s64 + 24416;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,796
	ctx.r5.s64 = 796;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r8,-32178
	ctx.r8.s64 = -2108817408;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r4,r8,-7824
	ctx.r4.s64 = ctx.r8.s64 + -7824;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r31,r10,-8612
	r31.s64 = ctx.r10.s64 + -8612;
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,16
	ctx.r10.s64 = 16;
	// std r3,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r3.u64);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de304
	if (!cr6.eq) goto loc_824DE304;
	// bl 0x824dda00
	ctx.lr = 0x824DE300;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE304:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,-8576
	r30.s64 = ctx.r10.s64 + -8576;
	// li r10,68
	ctx.r10.s64 = 68;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de328
	if (!cr6.eq) goto loc_824DE328;
	// bl 0x824dda00
	ctx.lr = 0x824DE324;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE328:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-8540
	r31.s64 = ctx.r10.s64 + -8540;
	// li r10,120
	ctx.r10.s64 = 120;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de34c
	if (!cr6.eq) goto loc_824DE34C;
	// bl 0x824dda00
	ctx.lr = 0x824DE348;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE34C:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,-8504
	r30.s64 = ctx.r10.s64 + -8504;
	// li r10,172
	ctx.r10.s64 = 172;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de370
	if (!cr6.eq) goto loc_824DE370;
	// bl 0x824dda00
	ctx.lr = 0x824DE36C;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE370:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-8468
	r31.s64 = ctx.r10.s64 + -8468;
	// li r10,224
	ctx.r10.s64 = 224;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de394
	if (!cr6.eq) goto loc_824DE394;
	// bl 0x824dda00
	ctx.lr = 0x824DE390;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE394:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,-8432
	r30.s64 = ctx.r10.s64 + -8432;
	// li r10,276
	ctx.r10.s64 = 276;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de3b8
	if (!cr6.eq) goto loc_824DE3B8;
	// bl 0x824dda00
	ctx.lr = 0x824DE3B4;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE3B8:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-8396
	r31.s64 = ctx.r10.s64 + -8396;
	// li r10,328
	ctx.r10.s64 = 328;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de3dc
	if (!cr6.eq) goto loc_824DE3DC;
	// bl 0x824dda00
	ctx.lr = 0x824DE3D8;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE3DC:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,-8360
	r30.s64 = ctx.r10.s64 + -8360;
	// li r10,380
	ctx.r10.s64 = 380;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de400
	if (!cr6.eq) goto loc_824DE400;
	// bl 0x824dda00
	ctx.lr = 0x824DE3FC;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE400:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-8324
	r31.s64 = ctx.r10.s64 + -8324;
	// li r10,432
	ctx.r10.s64 = 432;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de424
	if (!cr6.eq) goto loc_824DE424;
	// bl 0x824dda00
	ctx.lr = 0x824DE420;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE424:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,-8288
	r30.s64 = ctx.r10.s64 + -8288;
	// li r10,484
	ctx.r10.s64 = 484;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de448
	if (!cr6.eq) goto loc_824DE448;
	// bl 0x824dda00
	ctx.lr = 0x824DE444;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE448:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-8252
	r31.s64 = ctx.r10.s64 + -8252;
	// li r10,536
	ctx.r10.s64 = 536;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de46c
	if (!cr6.eq) goto loc_824DE46C;
	// bl 0x824dda00
	ctx.lr = 0x824DE468;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE46C:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,-8216
	r30.s64 = ctx.r10.s64 + -8216;
	// li r10,588
	ctx.r10.s64 = 588;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de490
	if (!cr6.eq) goto loc_824DE490;
	// bl 0x824dda00
	ctx.lr = 0x824DE48C;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE490:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-8180
	r31.s64 = ctx.r10.s64 + -8180;
	// li r10,640
	ctx.r10.s64 = 640;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de4b4
	if (!cr6.eq) goto loc_824DE4B4;
	// bl 0x824dda00
	ctx.lr = 0x824DE4B0;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE4B4:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,-8144
	r30.s64 = ctx.r10.s64 + -8144;
	// li r10,692
	ctx.r10.s64 = 692;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de4d8
	if (!cr6.eq) goto loc_824DE4D8;
	// bl 0x824dda00
	ctx.lr = 0x824DE4D4;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE4D8:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-8108
	r31.s64 = ctx.r10.s64 + -8108;
	// li r10,744
	ctx.r10.s64 = 744;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de4fc
	if (!cr6.eq) goto loc_824DE4FC;
	// bl 0x824dda00
	ctx.lr = 0x824DE4F8;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30012);
loc_824DE4FC:
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// addi r9,r11,-7152
	ctx.r9.s64 = r11.s64 + -7152;
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r11,30016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30016);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824de528
	if (!cr6.eq) goto loc_824DE528;
	// bl 0x824ddb30
	ctx.lr = 0x824DE524;
	sub_824DDB30(ctx, base);
	// lwz r11,30016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30016);
loc_824DE528:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,-8072
	ctx.r9.s64 = ctx.r10.s64 + -8072;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x824DE544;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824DE554;
	sub_821D4100(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824DE570;
	sub_821D41D0(ctx, base);
	// lis r6,-32127
	ctx.r6.s64 = -2105475072;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r6,-8000
	ctx.r4.s64 = ctx.r6.s64 + -8000;
	// bl 0x821d4b00
	ctx.lr = 0x824DE580;
	sub_821D4B00(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,2828(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x824DE598;
	sub_821C0548(ctx, base);
loc_824DE598:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824DE5A0"))) PPC_WEAK_FUNC(sub_824DE5A0);
PPC_FUNC_IMPL(__imp__sub_824DE5A0) {
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
	ctx.lr = 0x824DE5A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r30,r11,30024
	r30.s64 = r11.s64 + 30024;
	// lwz r11,30024(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30024);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824de800
	if (!cr6.eq) goto loc_824DE800;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824DE5C8;
	sub_82130528(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824de5dc
	if (cr6.eq) goto loc_824DE5DC;
	// bl 0x821d5408
	ctx.lr = 0x824DE5D8;
	sub_821D5408(ctx, base);
	// b 0x824de5e0
	goto loc_824DE5E0;
loc_824DE5DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824DE5E0:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r7,r10,24440
	ctx.r7.s64 = ctx.r10.s64 + 24440;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,1264
	ctx.r5.s64 = 1264;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r8,-32178
	ctx.r8.s64 = -2108817408;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r4,r8,-7752
	ctx.r4.s64 = ctx.r8.s64 + -7752;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r27,-32115
	r27.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r31,r10,-8036
	r31.s64 = ctx.r10.s64 + -8036;
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,796
	ctx.r10.s64 = 796;
	// std r3,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r3.u64);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de65c
	if (!cr6.eq) goto loc_824DE65C;
	// bl 0x824dda00
	ctx.lr = 0x824DE658;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE65C:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r10,-7932
	r28.s64 = ctx.r10.s64 + -7932;
	// li r10,848
	ctx.r10.s64 = 848;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de680
	if (!cr6.eq) goto loc_824DE680;
	// bl 0x824dda00
	ctx.lr = 0x824DE67C;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE680:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7896
	r29.s64 = ctx.r10.s64 + -7896;
	// li r10,900
	ctx.r10.s64 = 900;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de6a4
	if (!cr6.eq) goto loc_824DE6A4;
	// bl 0x824dda00
	ctx.lr = 0x824DE6A0;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE6A4:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-7860
	r31.s64 = ctx.r10.s64 + -7860;
	// li r10,952
	ctx.r10.s64 = 952;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de6c8
	if (!cr6.eq) goto loc_824DE6C8;
	// bl 0x824dda00
	ctx.lr = 0x824DE6C4;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE6C8:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7824
	r29.s64 = ctx.r10.s64 + -7824;
	// li r10,1004
	ctx.r10.s64 = 1004;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de6ec
	if (!cr6.eq) goto loc_824DE6EC;
	// bl 0x824dda00
	ctx.lr = 0x824DE6E8;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE6EC:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-7788
	r31.s64 = ctx.r10.s64 + -7788;
	// li r10,1056
	ctx.r10.s64 = 1056;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de710
	if (!cr6.eq) goto loc_824DE710;
	// bl 0x824dda00
	ctx.lr = 0x824DE70C;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE710:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7752
	r29.s64 = ctx.r10.s64 + -7752;
	// li r10,1108
	ctx.r10.s64 = 1108;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de734
	if (!cr6.eq) goto loc_824DE734;
	// bl 0x824dda00
	ctx.lr = 0x824DE730;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE734:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-7716
	r31.s64 = ctx.r10.s64 + -7716;
	// li r10,1160
	ctx.r10.s64 = 1160;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de758
	if (!cr6.eq) goto loc_824DE758;
	// bl 0x824dda00
	ctx.lr = 0x824DE754;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE758:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7680
	r29.s64 = ctx.r10.s64 + -7680;
	// li r10,1212
	ctx.r10.s64 = 1212;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de77c
	if (!cr6.eq) goto loc_824DE77C;
	// bl 0x824dda00
	ctx.lr = 0x824DE778;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 30012);
loc_824DE77C:
	// lis r31,-32115
	r31.s64 = -2104688640;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// lwz r4,30020(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 30020);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824de798
	if (!cr6.eq) goto loc_824DE798;
	// bl 0x824de248
	ctx.lr = 0x824DE794;
	sub_824DE248(ctx, base);
	// lwz r4,30020(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 30020);
loc_824DE798:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x824DE7A4;
	sub_821D4458(ctx, base);
	// lwz r11,30020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 30020);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x824DE7BC;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824DE7D8;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r8,-7644
	ctx.r4.s64 = ctx.r8.s64 + -7644;
	// bl 0x821d4b00
	ctx.lr = 0x824DE7E8;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x824DE800;
	sub_821C0548(ctx, base);
loc_824DE800:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824DE808"))) PPC_WEAK_FUNC(sub_824DE808);
PPC_FUNC_IMPL(__imp__sub_824DE808) {
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
	ctx.lr = 0x824DE810;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r30,r11,30028
	r30.s64 = r11.s64 + 30028;
	// lwz r11,30028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824dea8c
	if (!cr6.eq) goto loc_824DEA8C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824DE830;
	sub_82130528(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824de844
	if (cr6.eq) goto loc_824DE844;
	// bl 0x821d5408
	ctx.lr = 0x824DE840;
	sub_821D5408(ctx, base);
	// b 0x824de848
	goto loc_824DE848;
loc_824DE844:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824DE848:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r7,r10,24468
	ctx.r7.s64 = ctx.r10.s64 + 24468;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,1316
	ctx.r5.s64 = 1316;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r8,-32178
	ctx.r8.s64 = -2108817408;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r4,r8,-7680
	ctx.r4.s64 = ctx.r8.s64 + -7680;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r28,-32115
	r28.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r31,r10,-7604
	r31.s64 = ctx.r10.s64 + -7604;
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,796
	ctx.r10.s64 = 796;
	// std r3,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r3.u64);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de8c4
	if (!cr6.eq) goto loc_824DE8C4;
	// bl 0x824dda00
	ctx.lr = 0x824DE8C0;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE8C4:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7568
	r29.s64 = ctx.r10.s64 + -7568;
	// li r10,848
	ctx.r10.s64 = 848;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de8e8
	if (!cr6.eq) goto loc_824DE8E8;
	// bl 0x824dda00
	ctx.lr = 0x824DE8E4;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE8E8:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-7532
	r31.s64 = ctx.r10.s64 + -7532;
	// li r10,900
	ctx.r10.s64 = 900;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de90c
	if (!cr6.eq) goto loc_824DE90C;
	// bl 0x824dda00
	ctx.lr = 0x824DE908;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE90C:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7496
	r29.s64 = ctx.r10.s64 + -7496;
	// li r10,952
	ctx.r10.s64 = 952;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de930
	if (!cr6.eq) goto loc_824DE930;
	// bl 0x824dda00
	ctx.lr = 0x824DE92C;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE930:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-7460
	r31.s64 = ctx.r10.s64 + -7460;
	// li r10,1004
	ctx.r10.s64 = 1004;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de954
	if (!cr6.eq) goto loc_824DE954;
	// bl 0x824dda00
	ctx.lr = 0x824DE950;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE954:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7424
	r29.s64 = ctx.r10.s64 + -7424;
	// li r10,1056
	ctx.r10.s64 = 1056;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de978
	if (!cr6.eq) goto loc_824DE978;
	// bl 0x824dda00
	ctx.lr = 0x824DE974;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE978:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-7388
	r31.s64 = ctx.r10.s64 + -7388;
	// li r10,1108
	ctx.r10.s64 = 1108;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de99c
	if (!cr6.eq) goto loc_824DE99C;
	// bl 0x824dda00
	ctx.lr = 0x824DE998;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE99C:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7352
	r29.s64 = ctx.r10.s64 + -7352;
	// li r10,1160
	ctx.r10.s64 = 1160;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de9c0
	if (!cr6.eq) goto loc_824DE9C0;
	// bl 0x824dda00
	ctx.lr = 0x824DE9BC;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE9C0:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,-7316
	r31.s64 = ctx.r10.s64 + -7316;
	// li r10,1212
	ctx.r10.s64 = 1212;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824de9e4
	if (!cr6.eq) goto loc_824DE9E4;
	// bl 0x824dda00
	ctx.lr = 0x824DE9E0;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DE9E4:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,-7280
	r29.s64 = ctx.r10.s64 + -7280;
	// li r10,1264
	ctx.r10.s64 = 1264;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824dea08
	if (!cr6.eq) goto loc_824DEA08;
	// bl 0x824dda00
	ctx.lr = 0x824DEA04;
	sub_824DDA00(ctx, base);
	// lwz r11,30012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 30012);
loc_824DEA08:
	// lis r31,-32115
	r31.s64 = -2104688640;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// lwz r4,30020(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 30020);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824dea24
	if (!cr6.eq) goto loc_824DEA24;
	// bl 0x824de248
	ctx.lr = 0x824DEA20;
	sub_824DE248(ctx, base);
	// lwz r4,30020(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 30020);
loc_824DEA24:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x824DEA30;
	sub_821D4458(ctx, base);
	// lwz r11,30020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 30020);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x824DEA48;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824DEA64;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r8,-7244
	ctx.r4.s64 = ctx.r8.s64 + -7244;
	// bl 0x821d4b00
	ctx.lr = 0x824DEA74;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x824DEA8C;
	sub_821C0548(ctx, base);
loc_824DEA8C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824DEA94"))) PPC_WEAK_FUNC(sub_824DEA94);
PPC_FUNC_IMPL(__imp__sub_824DEA94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DEA98"))) PPC_WEAK_FUNC(sub_824DEA98);
PPC_FUNC_IMPL(__imp__sub_824DEA98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,30032(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 30032);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824DEAA4"))) PPC_WEAK_FUNC(sub_824DEAA4);
PPC_FUNC_IMPL(__imp__sub_824DEAA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DEAA8"))) PPC_WEAK_FUNC(sub_824DEAA8);
PPC_FUNC_IMPL(__imp__sub_824DEAA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// lwz r7,32(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// lfs f0,14348(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f0.f64 = double(temp.f32);
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// ori r9,r8,64167
	ctx.r9.u64 = ctx.r8.u64 | 64167;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// addi r11,r11,2176
	r11.s64 = r11.s64 + 2176;
	// beq cr6,0x824deb3c
	if (cr6.eq) goto loc_824DEB3C;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f13,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f12,16(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// mulld r7,r6,r9
	ctx.r7.s64 = ctx.r6.s64 * ctx.r9.s64;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// clrlwi r6,r8,9
	ctx.r6.u64 = ctx.r8.u32 & 0x7FFFFF;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rldicl r8,r8,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// std r7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// lfd f10,-32(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// ori r8,r6,1
	ctx.r8.u64 = ctx.r6.u64 | 1;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmadds f6,f7,f0,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stfs f6,16(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
loc_824DEB3C:
	// lwz r8,32(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// rlwinm r7,r8,31,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824deba0
	if (cr6.eq) goto loc_824DEBA0;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f13,20(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f12,20(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// mulld r7,r6,r9
	ctx.r7.s64 = ctx.r6.s64 * ctx.r9.s64;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rldicl r7,r8,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// clrlwi r6,r8,9
	ctx.r6.u64 = ctx.r8.u32 & 0x7FFFFF;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// std r6,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r6.u64);
	// lfd f10,-32(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// ori r7,r8,2
	ctx.r7.u64 = ctx.r8.u64 | 2;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmadds f6,f7,f0,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stfs f6,20(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
loc_824DEBA0:
	// lwz r8,32(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// rlwinm r7,r8,30,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824dedac
	if (cr6.eq) goto loc_824DEDAC;
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r8,r3,24
	ctx.r8.s64 = ctx.r3.s64 + 24;
	// not r8,r7
	ctx.r8.u64 = ~ctx.r7.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// rlwinm r7,r8,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// xor r6,r7,r6
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r6.u64;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r7,r6,r9
	ctx.r7.s64 = ctx.r6.s64 * ctx.r9.s64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// clrlwi r31,r8,9
	r31.u64 = ctx.r8.u32 & 0x7FFFFF;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rldicl r6,r8,32,32
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// std r8,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// lfd f13,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lwz r7,24(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lwz r6,24(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// rlwinm r8,r6,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFF;
	// rlwinm r7,r7,16,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFF;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// lwz r31,24(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// std r6,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r6.u64);
	// lfd f11,-32(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// std r7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// lfd f9,-32(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f5,f10
	ctx.f5.f64 = double(float(ctx.f10.f64));
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmadds f3,f4,f6,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f6.f64 + ctx.f5.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f2.u64);
	// lwz r6,-28(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	// clrlwi r8,r6,24
	ctx.r8.u64 = ctx.r6.u32 & 0xFF;
	// rlwimi r31,r8,16,8,15
	r31.u64 = (__builtin_rotateleft32(ctx.r8.u32, 16) & 0xFF0000) | (r31.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r31,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r31.u32);
	// lwz r7,24(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lwz r6,24(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// rlwinm r8,r6,24,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwinm r7,r7,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFF;
	// rotlwi r6,r31,0
	ctx.r6.u64 = __builtin_rotateleft32(r31.u32, 0);
	// extsw r31,r8
	r31.s64 = ctx.r8.s32;
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// std r31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r31.u64);
	// lfd f1,-32(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// fcfid f13,f1
	ctx.f13.f64 = double(ctx.f1.s64);
	// std r7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// lfd f12,-32(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmadds f8,f9,f6,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f6.f64 + ctx.f10.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f7.u64);
	// lwz r8,-28(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// rlwimi r6,r7,8,16,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// lwz r6,24(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lwz r8,24(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// extsw r8,r7
	ctx.r8.s64 = ctx.r7.s32;
	// subf r7,r7,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r7.s64;
	// std r8,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r8.u64);
	// lfd f3,-24(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// std r6,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r6.u64);
	// lfd f5,-32(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// fcfid f1,f3
	ctx.f1.f64 = double(ctx.f3.s64);
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fmadds f12,f2,f6,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f6.f64 + ctx.f13.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f11.u64);
	// lwz r7,-20(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -20);
	// rlwimi r7,r8,0,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
	// lwz r31,24(r5)
	r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,24(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// rlwinm r6,r6,8,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF;
	// rlwinm r31,r31,8,24,31
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 8) & 0xFF;
	// mulld r8,r8,r9
	ctx.r8.s64 = ctx.r8.s64 * ctx.r9.s64;
	// subf r31,r6,r31
	r31.s64 = r31.s64 - ctx.r6.s64;
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// extsw r31,r31
	r31.s64 = r31.s32;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// std r6,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r6.u64);
	// std r31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r31.u64);
	// lfd f9,-32(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// clrlwi r6,r8,9
	ctx.r6.u64 = ctx.r8.u32 & 0x7FFFFF;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lfd f10,-24(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// std r6,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r6.u64);
	// lfd f7,-24(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fcfid f5,f10
	ctx.f5.f64 = double(ctx.f10.s64);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rldicl r8,r8,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// frsp f3,f8
	ctx.f3.f64 = double(float(ctx.f8.f64));
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// fmuls f1,f2,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f4.f64));
	// fmadds f13,f1,f0,f3
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f3.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f12.u64);
	// lwz r7,-20(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -20);
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// rlwimi r8,r6,24,0,7
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r6.u32, 24) & 0xFF000000) | (ctx.r8.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
loc_824DEDAC:
	// lwz r8,32(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// rlwinm r7,r8,29,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824dee10
	if (cr6.eq) goto loc_824DEE10;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f13,28(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f12,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// mulld r7,r6,r9
	ctx.r7.s64 = ctx.r6.s64 * ctx.r9.s64;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// clrlwi r6,r8,9
	ctx.r6.u64 = ctx.r8.u32 & 0x7FFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// rldicl r7,r8,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// std r6,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r6.u64);
	// lfd f10,-24(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// ori r7,r8,8
	ctx.r7.u64 = ctx.r8.u64 | 8;
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// fmadds f6,f7,f0,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stfs f6,28(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
loc_824DEE10:
	// lwz r8,32(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// rlwinm r7,r8,28,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824dee8c
	if (cr6.eq) goto loc_824DEE8C;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mulld r8,r6,r7
	ctx.r8.s64 = ctx.r6.s64 * ctx.r7.s64;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r5,r1,-32
	ctx.r5.s64 = ctx.r1.s64 + -32;
	// clrlwi r6,r9,9
	ctx.r6.u64 = ctx.r9.u32 & 0x7FFFFF;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rldicl r9,r9,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// std r6,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r6.u64);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lfd f13,-24(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,-32(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// ori r9,r11,16
	ctx.r9.u64 = r11.u64 | 16;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stvx128 v11,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824DEE8C:
	// lwz r11,32(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// neg r6,r8
	ctx.r6.s64 = -ctx.r8.s64;
	// xor r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// rlwinm r3,r5,0,26,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x20;
	// xor r11,r3,r7
	r11.u64 = ctx.r3.u64 ^ ctx.r7.u64;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r7,32(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// rlwinm r6,r7,26,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x1;
	// neg r5,r6
	ctx.r5.s64 = -ctx.r6.s64;
	// xor r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 ^ ctx.r9.u64;
	// rlwinm r3,r4,0,25,25
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x40;
	// xor r11,r3,r8
	r11.u64 = ctx.r3.u64 ^ ctx.r8.u64;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824DEEDC"))) PPC_WEAK_FUNC(sub_824DEEDC);
PPC_FUNC_IMPL(__imp__sub_824DEEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DEEE0"))) PPC_WEAK_FUNC(sub_824DEEE0);
PPC_FUNC_IMPL(__imp__sub_824DEEE0) {
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x824DEEF4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824def58
	if (cr6.eq) goto loc_824DEF58;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// rotlwi r6,r10,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// ori r5,r6,32
	ctx.r5.u64 = ctx.r6.u64 | 32;
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
	// lfs f0,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824DEF58:
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

__attribute__((alias("__imp__sub_824DEF6C"))) PPC_WEAK_FUNC(sub_824DEF6C);
PPC_FUNC_IMPL(__imp__sub_824DEF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DEF70"))) PPC_WEAK_FUNC(sub_824DEF70);
PPC_FUNC_IMPL(__imp__sub_824DEF70) {
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
	ctx.lr = 0x824DEF78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,30032
	r31.s64 = r11.s64 + 30032;
	// lwz r11,30032(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30032);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824df0c8
	if (!cr6.eq) goto loc_824DF0C8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824DEF98;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824defac
	if (cr6.eq) goto loc_824DEFAC;
	// bl 0x821d5408
	ctx.lr = 0x824DEFA8;
	sub_821D5408(ctx, base);
	// b 0x824defb0
	goto loc_824DEFB0;
loc_824DEFAC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824DEFB0:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32178
	r11.s64 = -2108817408;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,24848
	ctx.r7.s64 = ctx.r10.s64 + 24848;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-5480
	ctx.r9.s64 = r11.s64 + -5480;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32178
	ctx.r8.s64 = -2108817408;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-4384
	ctx.r4.s64 = ctx.r8.s64 + -4384;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r7,r3,-7060
	ctx.r7.s64 = ctx.r3.s64 + -7060;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r11,r9,-7000
	r11.s64 = ctx.r9.s64 + -7000;
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r29,r10,-7024
	r29.s64 = ctx.r10.s64 + -7024;
	// addi r28,r8,-6976
	r28.s64 = ctx.r8.s64 + -6976;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r8,20
	ctx.r8.s64 = 20;
	// addi r5,r5,-6952
	ctx.r5.s64 = ctx.r5.s64 + -6952;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// addi r4,r4,-6928
	ctx.r4.s64 = ctx.r4.s64 + -6928;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r7,24
	ctx.r7.s64 = 24;
	// li r6,28
	ctx.r6.s64 = 28;
	// stw r9,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r9.u32);
	// li r11,32
	r11.s64 = 32;
	// stw r7,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r7.u32);
	// stw r6,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r6.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x824DF074;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824DF084;
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
	ctx.lr = 0x824DF0A0;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-6904
	ctx.r4.s64 = ctx.r8.s64 + -6904;
	// bl 0x821d4b00
	ctx.lr = 0x824DF0B0;
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
	ctx.lr = 0x824DF0C8;
	sub_821C0548(ctx, base);
loc_824DF0C8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824DF0D0"))) PPC_WEAK_FUNC(sub_824DF0D0);
PPC_FUNC_IMPL(__imp__sub_824DF0D0) {
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
	// beq cr6,0x824df104
	if (cr6.eq) goto loc_824DF104;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824DF104:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x824DF10C;
	sub_82130588(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821d2aa0
	ctx.lr = 0x824DF114;
	sub_821D2AA0(ctx, base);
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

__attribute__((alias("__imp__sub_824DF128"))) PPC_WEAK_FUNC(sub_824DF128);
PPC_FUNC_IMPL(__imp__sub_824DF128) {
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
	// bl 0x82323db8
	ctx.lr = 0x824DF140;
	sub_82323DB8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stb r11,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r11.u8);
	// stb r11,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r11.u8);
	// stb r11,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r11.u8);
	// stb r11,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r11.u8);
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

__attribute__((alias("__imp__sub_824DF184"))) PPC_WEAK_FUNC(sub_824DF184);
PPC_FUNC_IMPL(__imp__sub_824DF184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DF188"))) PPC_WEAK_FUNC(sub_824DF188);
PPC_FUNC_IMPL(__imp__sub_824DF188) {
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
	// bl 0x82323db8
	ctx.lr = 0x824DF1A8;
	sub_82323DB8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821d2aa8
	ctx.lr = 0x824DF1B4;
	sub_821D2AA8(ctx, base);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824df1d4
	if (cr6.eq) goto loc_824DF1D4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x824DF1C8;
	sub_8217D890(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_824DF1D4:
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

__attribute__((alias("__imp__sub_824DF1F0"))) PPC_WEAK_FUNC(sub_824DF1F0);
PPC_FUNC_IMPL(__imp__sub_824DF1F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x824df188
	sub_824DF188(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824DF1FC"))) PPC_WEAK_FUNC(sub_824DF1FC);
PPC_FUNC_IMPL(__imp__sub_824DF1FC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824DF200"))) PPC_WEAK_FUNC(sub_824DF200);
PPC_FUNC_IMPL(__imp__sub_824DF200) {
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
	ctx.lr = 0x824DF208;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r11,5716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5716);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bge cr6,0x824df24c
	if (!cr6.lt) goto loc_824DF24C;
	// mulli r10,r11,88
	ctx.r10.s64 = r11.s64 * 88;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r3,r10,84
	ctx.r3.s64 = ctx.r10.s64 + 84;
	// stw r11,5716(r31)
	PPC_STORE_U32(r31.u32 + 5716, r11.u32);
	// b 0x824df284
	goto loc_824DF284;
loc_824DF24C:
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82130528
	ctx.lr = 0x824DF254;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824df280
	if (cr6.eq) goto loc_824DF280;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stb r29,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r29.u8);
	// addi r10,r11,25452
	ctx.r10.s64 = r11.s64 + 25452;
	// stw r29,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r29.u32);
	// stw r29,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r29.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r29,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r29.u32);
	// b 0x824df284
	goto loc_824DF284;
loc_824DF280:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_824DF284:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_824DF288:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x824df2b8
	if (cr6.eq) goto loc_824DF2B8;
	// cmpwi cr6,r9,32
	cr6.compare<int32_t>(ctx.r9.s32, 32, xer);
	// beq cr6,0x824df2b0
	if (cr6.eq) goto loc_824DF2B0;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r10.u8);
loc_824DF2B0:
	// cmpwi cr6,r11,63
	cr6.compare<int32_t>(r11.s32, 63, xer);
	// blt cr6,0x824df288
	if (cr6.lt) goto loc_824DF288;
loc_824DF2B8:
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stb r29,12(r11)
	PPC_STORE_U8(r11.u32 + 12, r29.u8);
	// stw r27,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r27.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
	// sth r26,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r26.u16);
	// stw r25,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r25.u32);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824df2f4
	if (!cr6.eq) goto loc_824DF2F4;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_824DF2F4:
	// addi r10,r11,84
	ctx.r10.s64 = r11.s64 + 84;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824df318
	if (cr6.eq) goto loc_824DF318;
loc_824DF304:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r11,84
	ctx.r10.s64 = r11.s64 + 84;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824df304
	if (!cr6.eq) goto loc_824DF304;
loc_824DF318:
	// stw r3,84(r11)
	PPC_STORE_U32(r11.u32 + 84, ctx.r3.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824DF330"))) PPC_WEAK_FUNC(sub_824DF330);
PPC_FUNC_IMPL(__imp__sub_824DF330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x824DF338;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF360;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824df894
	if (cr6.eq) goto loc_824DF894;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r27,-32127
	r27.s64 = -2105475072;
	// addi r26,r10,-29624
	r26.s64 = ctx.r10.s64 + -29624;
	// addi r25,r11,-29628
	r25.s64 = r11.s64 + -29628;
loc_824DF380:
	// lwz r11,-6852(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -6852);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824DF394;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824df894
	if (cr6.eq) goto loc_824DF894;
	// lwz r11,-6852(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -6852);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824DF3B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824df86c
	if (cr6.eq) goto loc_824DF86C;
	// lwz r28,76(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 76);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824df3f8
	if (cr6.eq) goto loc_824DF3F8;
loc_824DF3C4:
	// lwz r11,-6852(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -6852);
	// addi r4,r28,12
	ctx.r4.s64 = r28.s64 + 12;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824DF3D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824df3f0
	if (cr6.eq) goto loc_824DF3F0;
	// lwz r28,84(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x824df3c4
	if (!cr6.eq) goto loc_824DF3C4;
	// b 0x824df3f8
	goto loc_824DF3F8;
loc_824DF3F0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x824df4ac
	if (!cr6.eq) goto loc_824DF4AC;
loc_824DF3F8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,-6852(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + -6852);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824DF428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824df4a0
	if (!cr6.eq) goto loc_824DF4A0;
	// li r31,1
	r31.s64 = 1;
loc_824DF434:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,-6852(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + -6852);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824DF464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824df474
	if (!cr6.eq) goto loc_824DF474;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// b 0x824df494
	goto loc_824DF494;
loc_824DF474:
	// lwz r11,-6852(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -6852);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824DF488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824df494
	if (!cr6.eq) goto loc_824DF494;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_824DF494:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x824df434
	if (!cr6.eq) goto loc_824DF434;
	// b 0x824df86c
	goto loc_824DF86C;
loc_824DF4A0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d0170
	ctx.lr = 0x824DF4A8;
	sub_821D0170(ctx, base);
	// b 0x824df86c
	goto loc_824DF86C;
loc_824DF4AC:
	// lwz r3,76(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lhz r31,8(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,13
	cr6.compare<uint32_t>(r11.u32, 13, xer);
	// bgt cr6,0x824df858
	if (cr6.gt) goto loc_824DF858;
	// lis r12,-32178
	r12.s64 = -2108817408;
	// addi r12,r12,-2852
	r12.s64 = r12.s64 + -2852;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824DF514;
	case 1:
		goto loc_824DF550;
	case 2:
		goto loc_824DF594;
	case 3:
		goto loc_824DF5CC;
	case 4:
		goto loc_824DF604;
	case 5:
		goto loc_824DF63C;
	case 6:
		goto loc_824DF674;
	case 7:
		goto loc_824DF6AC;
	case 8:
		goto loc_824DF6E4;
	case 9:
		goto loc_824DF71C;
	case 10:
		goto loc_824DF754;
	case 11:
		goto loc_824DF790;
	case 12:
		goto loc_824DF7E0;
	case 13:
		goto loc_824DF850;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-2796(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2796);
	// lwz r18,-2736(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2736);
	// lwz r18,-2668(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2668);
	// lwz r18,-2612(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2612);
	// lwz r18,-2556(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2556);
	// lwz r18,-2500(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2500);
	// lwz r18,-2444(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2444);
	// lwz r18,-2388(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2388);
	// lwz r18,-2332(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2332);
	// lwz r18,-2276(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2276);
	// lwz r18,-2220(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2220);
	// lwz r18,-2160(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2160);
	// lwz r18,-2080(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -2080);
	// lwz r18,-1968(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -1968);
loc_824DF514:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
	// lhz r5,10(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 10);
loc_824DF520:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF53C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,10(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 10);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// add r30,r5,r30
	r30.u64 = ctx.r5.u64 + r30.u64;
	// bne cr6,0x824df520
	if (!cr6.eq) goto loc_824DF520;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF550:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF558:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stb r7,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r7.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne cr6,0x824df558
	if (!cr6.eq) goto loc_824DF558;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF594:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF59C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF5B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r3,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r3.u8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne cr6,0x824df59c
	if (!cr6.eq) goto loc_824DF59C;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF5CC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF5D4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF5F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r3,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r3.u8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bne cr6,0x824df5d4
	if (!cr6.eq) goto loc_824DF5D4;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF604:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF60C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// sth r3,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r3.u16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// bne cr6,0x824df60c
	if (!cr6.eq) goto loc_824DF60C;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF63C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF644:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824df644
	if (!cr6.eq) goto loc_824DF644;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF674:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF67C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF698;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824df67c
	if (!cr6.eq) goto loc_824DF67C;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF6AC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF6B4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF6D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824df6b4
	if (!cr6.eq) goto loc_824DF6B4;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF6E4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF6EC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF70C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824df6ec
	if (!cr6.eq) goto loc_824DF6EC;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF71C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF724:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824df724
	if (!cr6.eq) goto loc_824DF724;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF754:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF75C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF778;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213e850
	ctx.lr = 0x824DF780;
	sub_8213E850(ctx, base);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824df75c
	if (!cr6.eq) goto loc_824DF75C;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF790:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF798:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF7B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x824DF7C4;
	sub_8213E850(ctx, base);
	// addi r3,r30,2
	ctx.r3.s64 = r30.s64 + 2;
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x824DF7D0;
	sub_8213E850(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824df798
	if (!cr6.eq) goto loc_824DF798;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF7E0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824df858
	if (cr6.eq) goto loc_824DF858;
loc_824DF7E8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vpkd3d128 v62,v63,5,2,2
	ctx.fpscr.enableFlushMode();
	temp.u32 = (v63.u32[0]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((v63.u32[0]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((v63.u32[0]&0x7FE000)>>13) : 0x0;
	v62.u16[4] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v62.u16[4] |= ((v63.u32[0]&0x80000000)>>16);
	temp.u32 = (v63.u32[1]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((v63.u32[1]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((v63.u32[1]&0x7FE000)>>13) : 0x0;
	v62.u16[5] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v62.u16[5] |= ((v63.u32[1]&0x80000000)>>16);
	temp.u32 = (v63.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((v63.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((v63.u32[2]&0x7FE000)>>13) : 0x0;
	v62.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v62.u16[6] |= ((v63.u32[2]&0x80000000)>>16);
	temp.u32 = (v63.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((v63.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((v63.u32[3]&0x7FE000)>>13) : 0x0;
	v62.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v62.u16[7] |= ((v63.u32[3]&0x80000000)>>16);
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r6,102(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// lhz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 96);
	// lhz r4,98(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 98);
	// lhz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// sth r7,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r7.u16);
	// sth r4,2(r30)
	PPC_STORE_U16(r30.u32 + 2, ctx.r4.u16);
	// sth r5,0(r30)
	PPC_STORE_U16(r30.u32 + 0, ctx.r5.u16);
	// sth r6,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r6.u16);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne cr6,0x824df7e8
	if (!cr6.eq) goto loc_824DF7E8;
	// b 0x824df858
	goto loc_824DF858;
loc_824DF850:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824df330
	ctx.lr = 0x824DF858;
	sub_824DF330(ctx, base);
loc_824DF858:
	// lwz r3,80(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824df86c
	if (cr6.eq) goto loc_824DF86C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c3048
	ctx.lr = 0x824DF86C;
	sub_821C3048(ctx, base);
loc_824DF86C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824df380
	if (!cr6.eq) goto loc_824DF380;
loc_824DF894:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824DF89C"))) PPC_WEAK_FUNC(sub_824DF89C);
PPC_FUNC_IMPL(__imp__sub_824DF89C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DF8A0"))) PPC_WEAK_FUNC(sub_824DF8A0);
PPC_FUNC_IMPL(__imp__sub_824DF8A0) {
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
	ctx.lr = 0x824DF8A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,5720(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 5720);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824df8f4
	if (!cr6.gt) goto loc_824DF8F4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r28,r11,-14360
	r28.s64 = r11.s64 + -14360;
loc_824DF8CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF8E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,5720(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 5720);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x824df8cc
	if (cr6.lt) goto loc_824DF8CC;
loc_824DF8F4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824DF8FC"))) PPC_WEAK_FUNC(sub_824DF8FC);
PPC_FUNC_IMPL(__imp__sub_824DF8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DF900"))) PPC_WEAK_FUNC(sub_824DF900);
PPC_FUNC_IMPL(__imp__sub_824DF900) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,25452
	ctx.r9.s64 = r11.s64 + 25452;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r10,13
	cr6.compare<int32_t>(ctx.r10.s32, 13, xer);
	// bne cr6,0x824df95c
	if (!cr6.eq) goto loc_824DF95C;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824df954
	if (cr6.eq) goto loc_824DF954;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DF954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824DF954:
	// li r11,0
	r11.s64 = 0;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
loc_824DF95C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824df974
	if (cr6.eq) goto loc_824DF974;
	// bl 0x82130588
	ctx.lr = 0x824DF970;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824DF974:
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

__attribute__((alias("__imp__sub_824DF98C"))) PPC_WEAK_FUNC(sub_824DF98C);
PPC_FUNC_IMPL(__imp__sub_824DF98C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824DF990"))) PPC_WEAK_FUNC(sub_824DF990);
PPC_FUNC_IMPL(__imp__sub_824DF990) {
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
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r9,r10,25460
	ctx.r9.s64 = ctx.r10.s64 + 25460;
	// addi r11,r30,84
	r11.s64 = r30.s64 + 84;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r10,63
	ctx.r10.s64 = 63;
	// li r31,0
	r31.s64 = 0;
	// addi r9,r9,25452
	ctx.r9.s64 = ctx.r9.s64 + 25452;
loc_824DF9CC:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stb r31,12(r11)
	PPC_STORE_U8(r11.u32 + 12, r31.u8);
	// stw r31,76(r11)
	PPC_STORE_U32(r11.u32 + 76, r31.u32);
	// stw r31,80(r11)
	PPC_STORE_U32(r11.u32 + 80, r31.u32);
	// stw r31,84(r11)
	PPC_STORE_U32(r11.u32 + 84, r31.u32);
	// addi r11,r11,88
	r11.s64 = r11.s64 + 88;
	// bge 0x824df9cc
	if (!cr0.lt) goto loc_824DF9CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82137a08
	ctx.lr = 0x824DFA04;
	sub_82137A08(ctx, base);
	// stw r31,68(r30)
	PPC_STORE_U32(r30.u32 + 68, r31.u32);
	// stw r31,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// stw r31,5720(r30)
	PPC_STORE_U32(r30.u32 + 5720, r31.u32);
	// stb r31,5724(r30)
	PPC_STORE_U8(r30.u32 + 5724, r31.u8);
	// stw r31,5716(r30)
	PPC_STORE_U32(r30.u32 + 5716, r31.u32);
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

__attribute__((alias("__imp__sub_824DFA38"))) PPC_WEAK_FUNC(sub_824DFA38);
PPC_FUNC_IMPL(__imp__sub_824DFA38) {
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
	ctx.lr = 0x824DFA40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,25460
	ctx.r10.s64 = r11.s64 + 25460;
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824dfa9c
	if (cr6.eq) goto loc_824DFA9C;
	// addi r29,r30,84
	r29.s64 = r30.s64 + 84;
loc_824DFA64:
	// lwz r31,84(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824dfa7c
	if (cr6.lt) goto loc_824DFA7C;
	// addi r11,r30,5716
	r11.s64 = r30.s64 + 5716;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x824dfa90
	if (cr6.lt) goto loc_824DFA90;
loc_824DFA7C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFA90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824DFA90:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dfa64
	if (!cr6.eq) goto loc_824DFA64;
loc_824DFA9C:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r31,r30,5716
	r31.s64 = r30.s64 + 5716;
	// li r29,63
	r29.s64 = 63;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r11,25452
	r30.s64 = r11.s64 + 25452;
loc_824DFAB0:
	// addi r31,r31,-88
	r31.s64 = r31.s64 + -88;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// bne cr6,0x824dfae8
	if (!cr6.eq) goto loc_824DFAE8;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824dfae4
	if (cr6.eq) goto loc_824DFAE4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFAE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824DFAE4:
	// stw r28,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r28.u32);
loc_824DFAE8:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x824dfab0
	if (!cr0.lt) goto loc_824DFAB0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824DFAF8"))) PPC_WEAK_FUNC(sub_824DFAF8);
PPC_FUNC_IMPL(__imp__sub_824DFAF8) {
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
	ctx.lr = 0x824DFB00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,5728
	ctx.r3.s64 = 5728;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82130528
	ctx.lr = 0x824DFB18;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824dfb30
	if (cr6.eq) goto loc_824DFB30;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824df990
	ctx.lr = 0x824DFB28;
	sub_824DF990(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x824dfb34
	goto loc_824DFB34;
loc_824DFB30:
	// li r31,0
	r31.s64 = 0;
loc_824DFB34:
	// lwz r11,5720(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 5720);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// stw r11,5720(r31)
	PPC_STORE_U32(r31.u32 + 5720, r11.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x824DFB5C;
	sub_824DF200(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824DFB68"))) PPC_WEAK_FUNC(sub_824DFB68);
PPC_FUNC_IMPL(__imp__sub_824DFB68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x824DFB70;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r10,25468
	ctx.r4.s64 = ctx.r10.s64 + 25468;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,148(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824DFBA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r28,76(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e0188
	if (cr6.eq) goto loc_824E0188;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r22,8
	r22.s64 = 8;
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r23,-8
	r23.s64 = -8;
	// addi r27,r11,7044
	r27.s64 = r11.s64 + 7044;
	// addi r26,r10,-14360
	r26.s64 = ctx.r10.s64 + -14360;
	// addi r24,r9,25464
	r24.s64 = ctx.r9.s64 + 25464;
loc_824DFBD8:
	// lwz r11,5720(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 5720);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824dfc10
	if (!cr6.gt) goto loc_824DFC10;
loc_824DFBE8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFC00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,5720(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 5720);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x824dfbe8
	if (cr6.lt) goto loc_824DFBE8;
loc_824DFC10:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFC28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r28,12
	ctx.r4.s64 = r28.s64 + 12;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,148(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 148);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824DFC44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,152(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 152);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x824DFC5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,76(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,13
	cr6.compare<uint32_t>(r11.u32, 13, xer);
	// lhz r31,8(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// bgt cr6,0x824e017c
	if (cr6.gt) goto loc_824E017C;
	// lis r12,-32178
	r12.s64 = -2108817408;
	// addi r12,r12,-884
	r12.s64 = r12.s64 + -884;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824DFCC4;
	case 1:
		goto loc_824DFD18;
	case 2:
		goto loc_824DFD64;
	case 3:
		goto loc_824DFDA4;
	case 4:
		goto loc_824DFDF0;
	case 5:
		goto loc_824DFE40;
	case 6:
		goto loc_824DFE8C;
	case 7:
		goto loc_824DFED8;
	case 8:
		goto loc_824DFF24;
	case 9:
		goto loc_824DFF70;
	case 10:
		goto loc_824DFFBC;
	case 11:
		goto loc_824E0040;
	case 12:
		goto loc_824E010C;
	case 13:
		goto loc_824E0170;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-828(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -828);
	// lwz r18,-744(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -744);
	// lwz r18,-668(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -668);
	// lwz r18,-604(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -604);
	// lwz r18,-528(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -528);
	// lwz r18,-448(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -448);
	// lwz r18,-372(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -372);
	// lwz r18,-296(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -296);
	// lwz r18,-220(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -220);
	// lwz r18,-144(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -144);
	// lwz r18,-68(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + -68);
	// lwz r18,64(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 64);
	// lwz r18,268(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 268);
	// lwz r18,368(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 368);
loc_824DFCC4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dfcfc
	if (cr6.eq) goto loc_824DFCFC;
loc_824DFCCC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFCEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,10(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 10);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// bne cr6,0x824dfccc
	if (!cr6.eq) goto loc_824DFCCC;
loc_824DFCFC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFD14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFD18:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dfd48
	if (cr6.eq) goto loc_824DFD48;
loc_824DFD20:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// lbz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFD3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dfd20
	if (!cr6.eq) goto loc_824DFD20;
loc_824DFD48:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFD60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFD64:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dfd88
	if (cr6.eq) goto loc_824DFD88;
loc_824DFD6C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// bl 0x821d02e8
	ctx.lr = 0x824DFD7C;
	sub_821D02E8(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dfd6c
	if (!cr6.eq) goto loc_824DFD6C;
loc_824DFD88:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFDA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFDA4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dfdd4
	if (cr6.eq) goto loc_824DFDD4;
loc_824DFDAC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// lbz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFDC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dfdac
	if (!cr6.eq) goto loc_824DFDAC;
loc_824DFDD4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFDEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFDF0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dfe24
	if (cr6.eq) goto loc_824DFE24;
loc_824DFDF8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// lhz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// extsh r4,r10
	ctx.r4.s64 = ctx.r10.s16;
	// lwz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824DFE18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dfdf8
	if (!cr6.eq) goto loc_824DFDF8;
loc_824DFE24:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFE3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFE40:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dfe70
	if (cr6.eq) goto loc_824DFE70;
loc_824DFE48:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFE64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dfe48
	if (!cr6.eq) goto loc_824DFE48;
loc_824DFE70:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFE88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFE8C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dfebc
	if (cr6.eq) goto loc_824DFEBC;
loc_824DFE94:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,140(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFEB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dfe94
	if (!cr6.eq) goto loc_824DFE94;
loc_824DFEBC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFED8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dff08
	if (cr6.eq) goto loc_824DFF08;
loc_824DFEE0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFEFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dfee0
	if (!cr6.eq) goto loc_824DFEE0;
loc_824DFF08:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFF24:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dff54
	if (cr6.eq) goto loc_824DFF54;
loc_824DFF2C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFF48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dff2c
	if (!cr6.eq) goto loc_824DFF2C;
loc_824DFF54:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFF6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFF70:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824dffa0
	if (cr6.eq) goto loc_824DFFA0;
loc_824DFF78:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFF94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dff78
	if (!cr6.eq) goto loc_824DFF78;
loc_824DFFA0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824DFFB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824DFFBC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e0024
	if (cr6.eq) goto loc_824E0024;
loc_824DFFC4:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824dffdc
	if (!cr6.eq) goto loc_824DFFDC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// b 0x824e0004
	goto loc_824E0004;
loc_824DFFDC:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
loc_824E0004:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,140(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E0018;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824dffc4
	if (!cr6.eq) goto loc_824DFFC4;
loc_824E0024:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E003C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824E0040:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e00f0
	if (cr6.eq) goto loc_824E00F0;
loc_824E0048:
	// lhz r11,2(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e0060
	if (!cr6.eq) goto loc_824E0060;
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
	// b 0x824e0088
	goto loc_824E0088;
loc_824E0060:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
loc_824E0088:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e009c
	if (!cr6.eq) goto loc_824E009C;
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// b 0x824e00c4
	goto loc_824E00C4;
loc_824E009C:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
loc_824E00C4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E00E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824e0048
	if (!cr6.eq) goto loc_824E0048;
loc_824E00F0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E0108;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824E010C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e0154
	if (cr6.eq) goto loc_824E0154;
loc_824E0114:
	// lvrx128 v63,r22,r30
	temp.u32 = r22.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lvlx128 v62,r23,r30
	temp.u32 = r23.u32 + r30.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vor128 v61,v62,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,128(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// vupkd3d128 v60,v61,20
	__builtin_debugtrap();
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824E0148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824e0114
	if (!cr6.eq) goto loc_824E0114;
loc_824E0154:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E016C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e017c
	goto loc_824E017C;
loc_824E0170:
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824dfb68
	ctx.lr = 0x824E017C;
	sub_824DFB68(ctx, base);
loc_824E017C:
	// lwz r28,84(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x824dfbd8
	if (!cr6.eq) goto loc_824DFBD8;
loc_824E0188:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824df8a0
	ctx.lr = 0x824E0194;
	sub_824DF8A0(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,12192
	ctx.r4.s64 = r11.s64 + 12192;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,148(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824E01B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824E01C0"))) PPC_WEAK_FUNC(sub_824E01C0);
PPC_FUNC_IMPL(__imp__sub_824E01C0) {
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
	// bl 0x824dfa38
	ctx.lr = 0x824E01E0;
	sub_824DFA38(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e01f8
	if (cr6.eq) goto loc_824E01F8;
	// bl 0x82130588
	ctx.lr = 0x824E01F4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E01F8:
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

__attribute__((alias("__imp__sub_824E0210"))) PPC_WEAK_FUNC(sub_824E0210);
PPC_FUNC_IMPL(__imp__sub_824E0210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x824E0218;
	// stwu r1,-1216(r1)
	ea = -1216 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821d1ca8
	ctx.lr = 0x824E0230;
	sub_821D1CA8(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r7,r11,25480
	ctx.r7.s64 = r11.s64 + 25480;
	// addi r6,r10,25472
	ctx.r6.s64 = ctx.r10.s64 + 25472;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1828
	ctx.lr = 0x824E0250;
	sub_821D1828(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E026C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824df330
	ctx.lr = 0x824E0278;
	sub_824DF330(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1216
	ctx.r1.s64 = ctx.r1.s64 + 1216;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E0284"))) PPC_WEAK_FUNC(sub_824E0284);
PPC_FUNC_IMPL(__imp__sub_824E0284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0288"))) PPC_WEAK_FUNC(sub_824E0288);
PPC_FUNC_IMPL(__imp__sub_824E0288) {
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
	ctx.lr = 0x824E0290;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// lbz r6,30104(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 30104);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x824E02B4;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824e02c8
	if (!cr6.eq) goto loc_824E02C8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824E02C8:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0210
	ctx.lr = 0x824E02D8;
	sub_824E0210(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x824E02E0;
	sub_821BE610(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E02EC"))) PPC_WEAK_FUNC(sub_824E02EC);
PPC_FUNC_IMPL(__imp__sub_824E02EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E02F0"))) PPC_WEAK_FUNC(sub_824E02F0);
PPC_FUNC_IMPL(__imp__sub_824E02F0) {
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
	ctx.lr = 0x824E02F8;
	// stwu r1,-1216(r1)
	ea = -1216 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x821d1ca8
	ctx.lr = 0x824E0314;
	sub_821D1CA8(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e032c
	if (cr6.eq) goto loc_824E032C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r7,r11,25480
	ctx.r7.s64 = r11.s64 + 25480;
	// b 0x824e0334
	goto loc_824E0334;
loc_824E032C:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r7,r11,25472
	ctx.r7.s64 = r11.s64 + 25472;
loc_824E0334:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1970
	ctx.lr = 0x824E0348;
	sub_821D1970(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E0364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r9,-14360
	ctx.r4.s64 = ctx.r9.s64 + -14360;
	// lwz r7,152(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 152);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824E0380;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824dfb68
	ctx.lr = 0x824E0390;
	sub_824DFB68(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1216
	ctx.r1.s64 = ctx.r1.s64 + 1216;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E039C"))) PPC_WEAK_FUNC(sub_824E039C);
PPC_FUNC_IMPL(__imp__sub_824E039C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E03A0"))) PPC_WEAK_FUNC(sub_824E03A0);
PPC_FUNC_IMPL(__imp__sub_824E03A0) {
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
	ctx.lr = 0x824E03A8;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821ca720
	ctx.lr = 0x824E03D0;
	sub_821CA720(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824e0404
	if (!cr6.eq) goto loc_824E0404;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca2f8
	ctx.lr = 0x824E03F8;
	sub_821CA2F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9240
	return;
loc_824E0404:
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e02f0
	ctx.lr = 0x824E0418;
	sub_824E02F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x824E0420;
	sub_821BE610(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E042C"))) PPC_WEAK_FUNC(sub_824E042C);
PPC_FUNC_IMPL(__imp__sub_824E042C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0430"))) PPC_WEAK_FUNC(sub_824E0430);
PPC_FUNC_IMPL(__imp__sub_824E0430) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,25492
	ctx.r10.s64 = r11.s64 + 25492;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e0468
	if (cr6.eq) goto loc_824E0468;
	// bl 0x82130588
	ctx.lr = 0x824E0460;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_824E0468:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x824E0470;
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

__attribute__((alias("__imp__sub_824E0484"))) PPC_WEAK_FUNC(sub_824E0484);
PPC_FUNC_IMPL(__imp__sub_824E0484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0488"))) PPC_WEAK_FUNC(sub_824E0488);
PPC_FUNC_IMPL(__imp__sub_824E0488) {
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
	ctx.lr = 0x824E0490;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-5840(r1)
	ea = -5840 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E04B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e04c4
	if (!cr6.eq) goto loc_824E04C4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r30,r11,-20156
	r30.s64 = r11.s64 + -20156;
loc_824E04C4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E04D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824df990
	ctx.lr = 0x824E04E4;
	sub_824DF990(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E04FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x824E0510;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32131
	ctx.r5.s64 = -2105737216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r31,r5,30576
	r31.s64 = ctx.r5.s64 + 30576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x824E0524;
	sub_821CA540(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e03a0
	ctx.lr = 0x824E0538;
	sub_824E03A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824E0544;
	sub_821C9A90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824dfa38
	ctx.lr = 0x824E054C;
	sub_824DFA38(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,5840
	ctx.r1.s64 = ctx.r1.s64 + 5840;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E0558"))) PPC_WEAK_FUNC(sub_824E0558);
PPC_FUNC_IMPL(__imp__sub_824E0558) {
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
	ctx.lr = 0x824E0560;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-5856(r1)
	ea = -5856 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E0580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e0594
	if (!cr6.eq) goto loc_824E0594;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r30,r11,-20156
	r30.s64 = r11.s64 + -20156;
loc_824E0594:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824df990
	ctx.lr = 0x824E05A0;
	sub_824DF990(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E05B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E05CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r28,r7,30576
	r28.s64 = ctx.r7.s64 + 30576;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x824E05E0;
	sub_821CA540(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e0288
	ctx.lr = 0x824E05F0;
	sub_824E0288(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x824E0608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824E0610;
	sub_821C9A90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824dfa38
	ctx.lr = 0x824E0618;
	sub_824DFA38(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,5856
	ctx.r1.s64 = ctx.r1.s64 + 5856;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E0624"))) PPC_WEAK_FUNC(sub_824E0624);
PPC_FUNC_IMPL(__imp__sub_824E0624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0628"))) PPC_WEAK_FUNC(sub_824E0628);
PPC_FUNC_IMPL(__imp__sub_824E0628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,1936
	ctx.r3.s64 = r11.s64 + 1936;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E0634"))) PPC_WEAK_FUNC(sub_824E0634);
PPC_FUNC_IMPL(__imp__sub_824E0634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0638"))) PPC_WEAK_FUNC(sub_824E0638);
PPC_FUNC_IMPL(__imp__sub_824E0638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,25524
	ctx.r3.s64 = r11.s64 + 25524;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E0644"))) PPC_WEAK_FUNC(sub_824E0644);
PPC_FUNC_IMPL(__imp__sub_824E0644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0648"))) PPC_WEAK_FUNC(sub_824E0648);
PPC_FUNC_IMPL(__imp__sub_824E0648) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,25492
	ctx.r9.s64 = ctx.r10.s64 + 25492;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E0664"))) PPC_WEAK_FUNC(sub_824E0664);
PPC_FUNC_IMPL(__imp__sub_824E0664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0668"))) PPC_WEAK_FUNC(sub_824E0668);
PPC_FUNC_IMPL(__imp__sub_824E0668) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,25492
	ctx.r10.s64 = r11.s64 + 25492;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e06a8
	if (cr6.eq) goto loc_824E06A8;
	// bl 0x82130588
	ctx.lr = 0x824E06A0;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_824E06A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x824E06B0;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e06c8
	if (cr6.eq) goto loc_824E06C8;
	// bl 0x82130588
	ctx.lr = 0x824E06C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E06C8:
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

__attribute__((alias("__imp__sub_824E06E0"))) PPC_WEAK_FUNC(sub_824E06E0);
PPC_FUNC_IMPL(__imp__sub_824E06E0) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e070c
	if (cr6.eq) goto loc_824E070C;
	// bl 0x82130588
	ctx.lr = 0x824E070C;
	sub_82130588(ctx, base);
loc_824E070C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821378b8
	ctx.lr = 0x824E0714;
	sub_821378B8(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_824E0730"))) PPC_WEAK_FUNC(sub_824E0730);
PPC_FUNC_IMPL(__imp__sub_824E0730) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r10,r11,25492
	ctx.r10.s64 = r11.s64 + 25492;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824e0770
	if (cr6.eq) goto loc_824E0770;
	// bl 0x8217d890
	ctx.lr = 0x824E0764;
	sub_8217D890(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_824E0770:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
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

__attribute__((alias("__imp__sub_824E0790"))) PPC_WEAK_FUNC(sub_824E0790);
PPC_FUNC_IMPL(__imp__sub_824E0790) {
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
	// cmplw cr6,r31,r4
	cr6.compare<uint32_t>(r31.u32, ctx.r4.u32, xer);
	// beq cr6,0x824e07d8
	if (cr6.eq) goto loc_824E07D8;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r30,4(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// beq cr6,0x824e07cc
	if (cr6.eq) goto loc_824E07CC;
	// bl 0x82130588
	ctx.lr = 0x824E07CC;
	sub_82130588(ctx, base);
loc_824E07CC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821378b8
	ctx.lr = 0x824E07D4;
	sub_821378B8(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
loc_824E07D8:
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

__attribute__((alias("__imp__sub_824E07F4"))) PPC_WEAK_FUNC(sub_824E07F4);
PPC_FUNC_IMPL(__imp__sub_824E07F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E07F8"))) PPC_WEAK_FUNC(sub_824E07F8);
PPC_FUNC_IMPL(__imp__sub_824E07F8) {
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
	ctx.lr = 0x824E0800;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// lwz r11,252(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r8,r10,25812
	ctx.r8.s64 = ctx.r10.s64 + 25812;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e0844
	if (!cr6.eq) goto loc_824E0844;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_824E0844:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r30,0
	r30.s64 = 0;
	// addi r9,r10,25820
	ctx.r9.s64 = ctx.r10.s64 + 25820;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x823da950
	ctx.lr = 0x824E086C;
	sub_823DA950(ctx, base);
	// addi r3,r31,120
	ctx.r3.s64 = r31.s64 + 120;
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E087C;
	sub_823DA950(ctx, base);
	// lwz r8,244(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// stw r28,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r28.u32);
	// addi r3,r31,204
	ctx.r3.s64 = r31.s64 + 204;
	// stw r27,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r27.u32);
	// stw r26,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r26.u32);
	// stw r25,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r25.u32);
	// stw r24,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r24.u32);
	// stw r8,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r8.u32);
	// bl 0x82501b00
	ctx.lr = 0x824E08A0;
	sub_82501B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824E08B0"))) PPC_WEAK_FUNC(sub_824E08B0);
PPC_FUNC_IMPL(__imp__sub_824E08B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r8,r11,25812
	ctx.r8.s64 = r11.s64 + 25812;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// bne cr6,0x824e08d4
	if (!cr6.eq) goto loc_824E08D4;
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
loc_824E08D4:
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,25828
	ctx.r8.s64 = ctx.r9.s64 + 25828;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E08FC"))) PPC_WEAK_FUNC(sub_824E08FC);
PPC_FUNC_IMPL(__imp__sub_824E08FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0900"))) PPC_WEAK_FUNC(sub_824E0900);
PPC_FUNC_IMPL(__imp__sub_824E0900) {
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
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r8,r10,25812
	ctx.r8.s64 = ctx.r10.s64 + 25812;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bne cr6,0x824e0938
	if (!cr6.eq) goto loc_824E0938;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_824E0938:
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r9,25836
	ctx.r8.s64 = ctx.r9.s64 + 25836;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x824e8de8
	ctx.lr = 0x824E095C;
	sub_824E8DE8(ctx, base);
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

__attribute__((alias("__imp__sub_824E0974"))) PPC_WEAK_FUNC(sub_824E0974);
PPC_FUNC_IMPL(__imp__sub_824E0974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0978"))) PPC_WEAK_FUNC(sub_824E0978);
PPC_FUNC_IMPL(__imp__sub_824E0978) {
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
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// li r9,9
	ctx.r9.s64 = 9;
	// addi r8,r10,25812
	ctx.r8.s64 = ctx.r10.s64 + 25812;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bne cr6,0x824e09b8
	if (!cr6.eq) goto loc_824E09B8;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_824E09B8:
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r9,25844
	ctx.r8.s64 = ctx.r9.s64 + 25844;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x824f99c0
	ctx.lr = 0x824E09DC;
	sub_824F99C0(ctx, base);
	// addi r3,r31,72
	ctx.r3.s64 = r31.s64 + 72;
	// bl 0x824e6400
	ctx.lr = 0x824E09E4;
	sub_824E6400(ctx, base);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
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

__attribute__((alias("__imp__sub_824E0A04"))) PPC_WEAK_FUNC(sub_824E0A04);
PPC_FUNC_IMPL(__imp__sub_824E0A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0A08"))) PPC_WEAK_FUNC(sub_824E0A08);
PPC_FUNC_IMPL(__imp__sub_824E0A08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r8,r11,25812
	ctx.r8.s64 = r11.s64 + 25812;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// bne cr6,0x824e0a2c
	if (!cr6.eq) goto loc_824E0A2C;
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
loc_824E0A2C:
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,25852
	ctx.r8.s64 = ctx.r9.s64 + 25852;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E0A54"))) PPC_WEAK_FUNC(sub_824E0A54);
PPC_FUNC_IMPL(__imp__sub_824E0A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0A58"))) PPC_WEAK_FUNC(sub_824E0A58);
PPC_FUNC_IMPL(__imp__sub_824E0A58) {
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
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x824e8e30
	ctx.lr = 0x824E0A88;
	sub_824E8E30(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,532(r31)
	PPC_STORE_U32(r31.u32 + 532, r11.u32);
	// stw r11,536(r31)
	PPC_STORE_U32(r31.u32 + 536, r11.u32);
	// std r11,544(r31)
	PPC_STORE_U64(r31.u32 + 544, r11.u64);
	// std r11,552(r31)
	PPC_STORE_U64(r31.u32 + 552, r11.u64);
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

__attribute__((alias("__imp__sub_824E0AB0"))) PPC_WEAK_FUNC(sub_824E0AB0);
PPC_FUNC_IMPL(__imp__sub_824E0AB0) {
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
	ctx.lr = 0x824E0AB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// bl 0x824ea350
	ctx.lr = 0x824E0AE4;
	sub_824EA350(ctx, base);
	// ld r11,208(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 208);
	// ld r10,216(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 216);
	// stw r30,528(r31)
	PPC_STORE_U32(r31.u32 + 528, r30.u32);
	// stw r29,532(r31)
	PPC_STORE_U32(r31.u32 + 532, r29.u32);
	// stw r28,536(r31)
	PPC_STORE_U32(r31.u32 + 536, r28.u32);
	// std r11,544(r31)
	PPC_STORE_U64(r31.u32 + 544, r11.u64);
	// std r10,552(r31)
	PPC_STORE_U64(r31.u32 + 552, ctx.r10.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E0B08"))) PPC_WEAK_FUNC(sub_824E0B08);
PPC_FUNC_IMPL(__imp__sub_824E0B08) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// bl 0x824e6f20
	ctx.lr = 0x824E0B30;
	sub_824E6F20(ctx, base);
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// bl 0x824e6348
	ctx.lr = 0x824E0B38;
	sub_824E6348(ctx, base);
	// addi r3,r31,164
	ctx.r3.s64 = r31.s64 + 164;
	// bl 0x82501a78
	ctx.lr = 0x824E0B40;
	sub_82501A78(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// stw r10,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r10.u32);
	// addi r11,r31,200
	r11.s64 = r31.s64 + 200;
	// stw r9,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r9.u32);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x824e8e30
	ctx.lr = 0x824E0B64;
	sub_824E8E30(ctx, base);
	// stw r30,732(r31)
	PPC_STORE_U32(r31.u32 + 732, r30.u32);
	// stw r30,736(r31)
	PPC_STORE_U32(r31.u32 + 736, r30.u32);
	// std r30,744(r31)
	PPC_STORE_U64(r31.u32 + 744, r30.u64);
	// std r30,752(r31)
	PPC_STORE_U64(r31.u32 + 752, r30.u64);
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

__attribute__((alias("__imp__sub_824E0B8C"))) PPC_WEAK_FUNC(sub_824E0B8C);
PPC_FUNC_IMPL(__imp__sub_824E0B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0B90"))) PPC_WEAK_FUNC(sub_824E0B90);
PPC_FUNC_IMPL(__imp__sub_824E0B90) {
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
	ctx.lr = 0x824E0B98;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E0BC0;
	sub_824E0B08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x821f8730
	ctx.lr = 0x824E0BCC;
	sub_821F8730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824e0d1c
	if (cr6.lt) goto loc_824E0D1C;
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bge cr6,0x824e0d1c
	if (!cr6.lt) goto loc_824E0D1C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x824E0BE4;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x824E0BE8;
	sub_82130000(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82501a88
	ctx.lr = 0x824E0BF0;
	sub_82501A88(ctx, base);
	// clrlwi r23,r3,24
	r23.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x824e0c0c
	if (!cr6.eq) goto loc_824E0C0C;
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823da950
	ctx.lr = 0x824E0C0C;
	sub_823DA950(ctx, base);
loc_824E0C0C:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x824E0C1C;
	sub_823DA950(ctx, base);
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r9,9
	ctx.r9.s64 = 9;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E0C2C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824e0c2c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E0C2C;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x824e0c80
	if (cr6.eq) goto loc_824E0C80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6148
	ctx.lr = 0x824E0C50;
	sub_824E6148(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c98a8
	ctx.lr = 0x824E0C60;
	sub_821C98A8(ctx, base);
	// clrldi r10,r3,32
	ctx.r10.u64 = ctx.r3.u64 & 0xFFFFFFFF;
loc_824E0C64:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824e0c64
	if (cr6.eq) goto loc_824E0C64;
	// rldicr r10,r10,32,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000;
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// b 0x824e0c84
	goto loc_824E0C84;
loc_824E0C80:
	// ld r30,280(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + 280);
loc_824E0C84:
	// stw r22,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r22.u32);
	// addi r11,r31,200
	r11.s64 = r31.s64 + 200;
	// stw r26,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r26.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// stw r25,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r25.u32);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x824ea350
	ctx.lr = 0x824E0CA0;
	sub_824EA350(ctx, base);
	// lwz r11,260(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// lwz r10,268(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// subf r9,r27,r11
	ctx.r9.s64 = r11.s64 - r27.s64;
	// lwz r8,276(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// ld r7,288(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 288);
	// cntlzw r6,r9
	ctx.r6.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// std r30,744(r31)
	PPC_STORE_U64(r31.u32 + 744, r30.u64);
	// stw r11,728(r31)
	PPC_STORE_U32(r31.u32 + 728, r11.u32);
	// rlwinm r11,r6,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stw r10,732(r31)
	PPC_STORE_U32(r31.u32 + 732, ctx.r10.u32);
	// stw r8,736(r31)
	PPC_STORE_U32(r31.u32 + 736, ctx.r8.u32);
	// std r7,752(r31)
	PPC_STORE_U64(r31.u32 + 752, ctx.r7.u64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e0ce8
	if (!cr6.eq) goto loc_824E0CE8;
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// beq cr6,0x824e0cec
	if (cr6.eq) goto loc_824E0CEC;
loc_824E0CE8:
	// li r10,1
	ctx.r10.s64 = 1;
loc_824E0CEC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e0d00
	if (cr6.eq) goto loc_824E0D00;
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// bne cr6,0x824e0d1c
	if (!cr6.eq) goto loc_824E0D1C;
loc_824E0D00:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e0d10
	if (cr6.eq) goto loc_824E0D10;
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// bne cr6,0x824e0d1c
	if (!cr6.eq) goto loc_824E0D1C;
loc_824E0D10:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_824E0D1C:
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e6f20
	ctx.lr = 0x824E0D28;
	sub_824E6F20(ctx, base);
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// bl 0x824e6348
	ctx.lr = 0x824E0D30;
	sub_824E6348(ctx, base);
	// addi r3,r31,164
	ctx.r3.s64 = r31.s64 + 164;
	// bl 0x82501a78
	ctx.lr = 0x824E0D38;
	sub_82501A78(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// stw r10,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r10.u32);
	// addi r11,r31,200
	r11.s64 = r31.s64 + 200;
	// stw r9,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r9.u32);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x824e8e30
	ctx.lr = 0x824E0D5C;
	sub_824E8E30(ctx, base);
	// stw r27,732(r31)
	PPC_STORE_U32(r31.u32 + 732, r27.u32);
	// stw r27,736(r31)
	PPC_STORE_U32(r31.u32 + 736, r27.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// std r27,744(r31)
	PPC_STORE_U64(r31.u32 + 744, r27.u64);
	// std r27,752(r31)
	PPC_STORE_U64(r31.u32 + 752, r27.u64);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E0D78"))) PPC_WEAK_FUNC(sub_824E0D78);
PPC_FUNC_IMPL(__imp__sub_824E0D78) {
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
	// lis r11,8
	r11.s64 = 524288;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r9,r11,44613
	ctx.r9.u64 = r11.u64 | 44613;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// std r10,8(r31)
	PPC_STORE_U64(r31.u32 + 8, ctx.r10.u64);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x824fc050
	ctx.lr = 0x824E0DA8;
	sub_824FC050(ctx, base);
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

__attribute__((alias("__imp__sub_824E0DC0"))) PPC_WEAK_FUNC(sub_824E0DC0);
PPC_FUNC_IMPL(__imp__sub_824E0DC0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0DE0;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E0DE8;
	sub_821C9030(ctx, base);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
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

__attribute__((alias("__imp__sub_824E0E00"))) PPC_WEAK_FUNC(sub_824E0E00);
PPC_FUNC_IMPL(__imp__sub_824E0E00) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0E20;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E0E28;
	sub_821C9030(ctx, base);
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
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

__attribute__((alias("__imp__sub_824E0E40"))) PPC_WEAK_FUNC(sub_824E0E40);
PPC_FUNC_IMPL(__imp__sub_824E0E40) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0E60;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E0E68;
	sub_821C9030(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
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

__attribute__((alias("__imp__sub_824E0E80"))) PPC_WEAK_FUNC(sub_824E0E80);
PPC_FUNC_IMPL(__imp__sub_824E0E80) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0EA0;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r31,752(r31)
	r31.u64 = PPC_LOAD_U64(r31.u32 + 752);
	// bl 0x821c9030
	ctx.lr = 0x824E0EAC;
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

__attribute__((alias("__imp__sub_824E0EC4"))) PPC_WEAK_FUNC(sub_824E0EC4);
PPC_FUNC_IMPL(__imp__sub_824E0EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E0EC8"))) PPC_WEAK_FUNC(sub_824E0EC8);
PPC_FUNC_IMPL(__imp__sub_824E0EC8) {
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
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0EF0;
	sub_821C8FE0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x824e0f00
	if (!cr6.eq) goto loc_824E0F00;
	// lwz r31,212(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// b 0x824e0f04
	goto loc_824E0F04;
loc_824E0F00:
	// lwz r31,216(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 216);
loc_824E0F04:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E0F0C;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_824E0F28"))) PPC_WEAK_FUNC(sub_824E0F28);
PPC_FUNC_IMPL(__imp__sub_824E0F28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x824E0F30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r31,2100
	r30.s64 = r31.s64 + 2100;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0F48;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,212(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// bl 0x821c9030
	ctx.lr = 0x824E0F54;
	sub_821C9030(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0F60;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r31,216(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// bl 0x821c9030
	ctx.lr = 0x824E0F6C;
	sub_821C9030(ctx, base);
	// add r3,r31,r29
	ctx.r3.u64 = r31.u64 + r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E0F78"))) PPC_WEAK_FUNC(sub_824E0F78);
PPC_FUNC_IMPL(__imp__sub_824E0F78) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0F98;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E0FA0;
	sub_821C9030(ctx, base);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
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

__attribute__((alias("__imp__sub_824E0FB8"))) PPC_WEAK_FUNC(sub_824E0FB8);
PPC_FUNC_IMPL(__imp__sub_824E0FB8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E0FD8;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,208(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x821c9030
	ctx.lr = 0x824E0FE4;
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

__attribute__((alias("__imp__sub_824E0FFC"))) PPC_WEAK_FUNC(sub_824E0FFC);
PPC_FUNC_IMPL(__imp__sub_824E0FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1000"))) PPC_WEAK_FUNC(sub_824E1000);
PPC_FUNC_IMPL(__imp__sub_824E1000) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1020;
	sub_821C8FE0(ctx, base);
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r9,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E1038;
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

__attribute__((alias("__imp__sub_824E1050"))) PPC_WEAK_FUNC(sub_824E1050);
PPC_FUNC_IMPL(__imp__sub_824E1050) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1070;
	sub_821C8FE0(ctx, base);
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,-2
	ctx.r10.s64 = r11.s64 + -2;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r9,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E1088;
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

__attribute__((alias("__imp__sub_824E10A0"))) PPC_WEAK_FUNC(sub_824E10A0);
PPC_FUNC_IMPL(__imp__sub_824E10A0) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E10C0;
	sub_821C8FE0(ctx, base);
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824e10d8
	if (cr6.eq) goto loc_824E10D8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r31,0
	r31.s64 = 0;
	// bne cr6,0x824e10dc
	if (!cr6.eq) goto loc_824E10DC;
loc_824E10D8:
	// li r31,1
	r31.s64 = 1;
loc_824E10DC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E10E4;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E10FC"))) PPC_WEAK_FUNC(sub_824E10FC);
PPC_FUNC_IMPL(__imp__sub_824E10FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1100"))) PPC_WEAK_FUNC(sub_824E1100);
PPC_FUNC_IMPL(__imp__sub_824E1100) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1120;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x824e1138
	if (cr6.lt) goto loc_824E1138;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r31,1
	r31.s64 = 1;
	// ble cr6,0x824e113c
	if (!cr6.gt) goto loc_824E113C;
loc_824E1138:
	// li r31,0
	r31.s64 = 0;
loc_824E113C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E1144;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E115C"))) PPC_WEAK_FUNC(sub_824E115C);
PPC_FUNC_IMPL(__imp__sub_824E115C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1160"))) PPC_WEAK_FUNC(sub_824E1160);
PPC_FUNC_IMPL(__imp__sub_824E1160) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1180;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e1198
	if (cr6.lt) goto loc_824E1198;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r31,1
	r31.s64 = 1;
	// ble cr6,0x824e119c
	if (!cr6.gt) goto loc_824E119C;
loc_824E1198:
	// li r31,0
	r31.s64 = 0;
loc_824E119C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E11A4;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E11BC"))) PPC_WEAK_FUNC(sub_824E11BC);
PPC_FUNC_IMPL(__imp__sub_824E11BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E11C0"))) PPC_WEAK_FUNC(sub_824E11C0);
PPC_FUNC_IMPL(__imp__sub_824E11C0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E11E0;
	sub_821C8FE0(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r31,r31,172
	r31.s64 = r31.s64 + 172;
	// bl 0x82130000
	ctx.lr = 0x824E11EC;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x824E11F0;
	sub_82130000(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82501a88
	ctx.lr = 0x824E11F8;
	sub_82501A88(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E1204;
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

__attribute__((alias("__imp__sub_824E121C"))) PPC_WEAK_FUNC(sub_824E121C);
PPC_FUNC_IMPL(__imp__sub_824E121C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1220"))) PPC_WEAK_FUNC(sub_824E1220);
PPC_FUNC_IMPL(__imp__sub_824E1220) {
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
	// addi r4,r3,2100
	ctx.r4.s64 = ctx.r3.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1238;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E1240;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_824E1254"))) PPC_WEAK_FUNC(sub_824E1254);
PPC_FUNC_IMPL(__imp__sub_824E1254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1258"))) PPC_WEAK_FUNC(sub_824E1258);
PPC_FUNC_IMPL(__imp__sub_824E1258) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1278;
	sub_821C8FE0(ctx, base);
	// lwz r11,736(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,0
	ctx.r10.s64 = r11.s64 + 0;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r9,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E1290;
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

__attribute__((alias("__imp__sub_824E12A8"))) PPC_WEAK_FUNC(sub_824E12A8);
PPC_FUNC_IMPL(__imp__sub_824E12A8) {
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
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r30,r31,2100
	r30.s64 = r31.s64 + 2100;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E12D0;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E12DC;
	sub_821C8FE0(ctx, base);
	// lwz r11,736(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,0
	ctx.r10.s64 = r11.s64 + 0;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E12F4;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e1310
	if (!cr6.eq) goto loc_824E1310;
	// lwz r11,740(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 740);
	// li r31,0
	r31.s64 = 0;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e1314
	if (cr6.eq) goto loc_824E1314;
loc_824E1310:
	// li r31,1
	r31.s64 = 1;
loc_824E1314:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E131C;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E1338"))) PPC_WEAK_FUNC(sub_824E1338);
PPC_FUNC_IMPL(__imp__sub_824E1338) {
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
	ctx.lr = 0x824E1340;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1358;
	sub_821C8FE0(ctx, base);
	// lwz r30,8(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824e137c
	if (cr6.eq) goto loc_824E137C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E1374;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_824E137C:
	// stw r29,1972(r31)
	PPC_STORE_U32(r31.u32 + 1972, r29.u32);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// bl 0x824e6a10
	ctx.lr = 0x824E1388;
	sub_824E6A10(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E1390;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E1398"))) PPC_WEAK_FUNC(sub_824E1398);
PPC_FUNC_IMPL(__imp__sub_824E1398) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x824e13f4
	if (!cr6.eq) goto loc_824E13F4;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// li r3,62
	ctx.r3.s64 = 62;
	// beq cr6,0x824e13b4
	if (cr6.eq) goto loc_824E13B4;
	// li r3,46
	ctx.r3.s64 = 46;
loc_824E13B4:
	// clrlwi r10,r5,31
	ctx.r10.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e13c4
	if (cr6.eq) goto loc_824E13C4;
	// ori r3,r3,16
	ctx.r3.u64 = ctx.r3.u64 | 16;
loc_824E13C4:
	// rlwinm r10,r5,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e13d8
	if (cr6.eq) goto loc_824E13D8;
	// rlwinm r3,r3,0,31,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// b 0x824e1418
	goto loc_824E1418;
loc_824E13D8:
	// clrlwi r10,r6,31
	ctx.r10.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e1418
	if (!cr6.eq) goto loc_824E1418;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x824e1418
	if (cr6.eq) goto loc_824E1418;
	// ori r3,r3,768
	ctx.r3.u64 = ctx.r3.u64 | 768;
	// b 0x824e1418
	goto loc_824E1418;
loc_824E13F4:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x824e1404
	if (!cr6.eq) goto loc_824E1404;
	// li r3,32
	ctx.r3.s64 = 32;
	// b 0x824e1418
	goto loc_824E1418;
loc_824E1404:
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// li r3,1798
	ctx.r3.s64 = 1798;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e1418
	if (!cr6.eq) goto loc_824E1418;
	// li r3,0
	ctx.r3.s64 = 0;
loc_824E1418:
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E1434"))) PPC_WEAK_FUNC(sub_824E1434);
PPC_FUNC_IMPL(__imp__sub_824E1434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1438"))) PPC_WEAK_FUNC(sub_824E1438);
PPC_FUNC_IMPL(__imp__sub_824E1438) {
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
	ctx.lr = 0x824E1440;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// bl 0x824e70f0
	ctx.lr = 0x824E1468;
	sub_824E70F0(ctx, base);
	// lbz r27,271(r1)
	r27.u64 = PPC_LOAD_U8(ctx.r1.u32 + 271);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e1398
	ctx.lr = 0x824E1488;
	sub_824E1398(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r26,-1
	r26.s64 = -1;
	// bl 0x821f8730
	ctx.lr = 0x824E1498;
	sub_821F8730(ctx, base);
	// bl 0x824575f8
	ctx.lr = 0x824E149C;
	sub_824575F8(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x824e14bc
	if (cr6.eq) goto loc_824E14BC;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x824e14f0
	if (!cr6.eq) goto loc_824E14F0;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// beq cr6,0x824e14bc
	if (cr6.eq) goto loc_824E14BC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x824e14f0
	if (!cr6.eq) goto loc_824E14F0;
loc_824E14BC:
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x824e14dc
	if (!cr6.eq) goto loc_824E14DC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f8730
	ctx.lr = 0x824E14CC;
	sub_821F8730(ctx, base);
	// bl 0x824e6d68
	ctx.lr = 0x824E14D0;
	sub_824E6D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e14f0
	if (cr6.eq) goto loc_824E14F0;
loc_824E14DC:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// bne cr6,0x824e14fc
	if (!cr6.eq) goto loc_824E14FC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e152c
	if (cr6.eq) goto loc_824E152C;
loc_824E14F0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_824E14FC:
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r30,r9,1
	r30.u64 = ctx.r9.u64 ^ 1;
	// bl 0x821f8730
	ctx.lr = 0x824E1510;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x824e9240
	ctx.lr = 0x824E1520;
	sub_824E9240(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e14f0
	if (cr6.eq) goto loc_824E14F0;
loc_824E152C:
	// lis r11,0
	r11.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r30,r11,32778
	r30.u64 = r11.u64 | 32778;
	// bne cr6,0x824e154c
	if (!cr6.eq) goto loc_824E154C;
	// bl 0x821f8730
	ctx.lr = 0x824E1544;
	sub_821F8730(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x824e1554
	goto loc_824E1554;
loc_824E154C:
	// bl 0x821f8730
	ctx.lr = 0x824E1550;
	sub_821F8730(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
loc_824E1554:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82457550
	ctx.lr = 0x824E155C;
	sub_82457550(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f8730
	ctx.lr = 0x824E1564;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r7,252(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r8,244(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lwz r9,276(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r10,260(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// bl 0x8274b440
	ctx.lr = 0x824E1588;
	sub_8274B440(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824E1590"))) PPC_WEAK_FUNC(sub_824E1590);
PPC_FUNC_IMPL(__imp__sub_824E1590) {
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
	ctx.lr = 0x824E1598;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E15B0;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E15B8;
	sub_821C9030(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x824E15C0;
	sub_821F8730(ctx, base);
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x824e8e58
	ctx.lr = 0x824E15D4;
	sub_824E8E58(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824e1668
	if (!cr6.gt) goto loc_824E1668;
loc_824E15DC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e8f28
	ctx.lr = 0x824E15E8;
	sub_824E8F28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e1654
	if (!cr6.eq) goto loc_824E1654;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e94f0
	ctx.lr = 0x824E1600;
	sub_824E94F0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E1610;
	sub_824E95F8(ctx, base);
	// rlwinm r11,r29,0,0,3
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xF0000000;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e1634
	if (!cr6.eq) goto loc_824E1634;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82457550
	ctx.lr = 0x824E1630;
	sub_82457550(ctx, base);
	// b 0x824e1654
	goto loc_824E1654;
loc_824E1634:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e9740
	ctx.lr = 0x824E1640;
	sub_824E9740(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x824575e8
	ctx.lr = 0x824E1654;
	sub_824575E8(ctx, base);
loc_824E1654:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x824e8e58
	ctx.lr = 0x824E1660;
	sub_824E8E58(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x824e15dc
	if (cr6.lt) goto loc_824E15DC;
loc_824E1668:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E1674"))) PPC_WEAK_FUNC(sub_824E1674);
PPC_FUNC_IMPL(__imp__sub_824E1674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1678"))) PPC_WEAK_FUNC(sub_824E1678);
PPC_FUNC_IMPL(__imp__sub_824E1678) {
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
	ctx.lr = 0x824E1680;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r30,2100
	r31.s64 = r30.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E16A0;
	sub_821C8FE0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E16AC;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e16c4
	if (cr6.lt) goto loc_824E16C4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r31,1
	r31.s64 = 1;
	// ble cr6,0x824e16c8
	if (!cr6.gt) goto loc_824E16C8;
loc_824E16C4:
	// li r31,0
	r31.s64 = 0;
loc_824E16C8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E16D0;
	sub_821C9030(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1764
	if (cr6.eq) goto loc_824E1764;
	// lwz r11,1800(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1800);
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// addi r29,r31,776
	r29.s64 = r31.s64 + 776;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E16F4;
	sub_824F0498(ctx, base);
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// bl 0x824f9230
	ctx.lr = 0x824E16FC;
	sub_824F9230(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,800(r31)
	PPC_STORE_U32(r31.u32 + 800, ctx.r10.u32);
	// bl 0x82502300
	ctx.lr = 0x824E170C;
	sub_82502300(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// ld r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// std r8,776(r31)
	PPC_STORE_U64(r31.u32 + 776, ctx.r8.u64);
	// bl 0x824e7110
	ctx.lr = 0x824E1720;
	sub_824E7110(ctx, base);
	// ld r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// std r7,784(r31)
	PPC_STORE_U64(r31.u32 + 784, ctx.r7.u64);
	// ld r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// std r6,792(r31)
	PPC_STORE_U64(r31.u32 + 792, ctx.r6.u64);
	// stw r27,800(r31)
	PPC_STORE_U32(r31.u32 + 800, r27.u32);
	// bne cr6,0x824e174c
	if (!cr6.eq) goto loc_824E174C;
	// lwz r11,1804(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1804);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1804(r30)
	PPC_STORE_U32(r30.u32 + 1804, r11.u32);
	// b 0x824e1758
	goto loc_824E1758;
loc_824E174C:
	// lwz r11,1808(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1808);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1808(r30)
	PPC_STORE_U32(r30.u32 + 1808, r11.u32);
loc_824E1758:
	// lwz r11,1800(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1800);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1800(r30)
	PPC_STORE_U32(r30.u32 + 1800, r11.u32);
loc_824E1764:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E176C;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E1774"))) PPC_WEAK_FUNC(sub_824E1774);
PPC_FUNC_IMPL(__imp__sub_824E1774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1778"))) PPC_WEAK_FUNC(sub_824E1778);
PPC_FUNC_IMPL(__imp__sub_824E1778) {
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
	ctx.lr = 0x824E1780;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r29,2100
	ctx.r4.s64 = r29.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1798;
	sub_821C8FE0(ctx, base);
	// lwz r11,1800(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1800);
	// li r27,-1
	r27.s64 = -1;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e17f4
	if (!cr6.gt) goto loc_824E17F4;
	// addi r30,r29,776
	r30.s64 = r29.s64 + 776;
loc_824E17B0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f0550
	ctx.lr = 0x824E17BC;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e17f0
	if (!cr6.eq) goto loc_824E17F0;
	// lwz r11,1800(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1800);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x824e17b0
	if (cr6.lt) goto loc_824E17B0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E17E4;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824E17F0:
	// mr r27,r31
	r27.u64 = r31.u64;
loc_824E17F4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E17FC;
	sub_821C9030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E1808"))) PPC_WEAK_FUNC(sub_824E1808);
PPC_FUNC_IMPL(__imp__sub_824E1808) {
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
	ctx.lr = 0x824E1810;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1824;
	sub_821C8FE0(ctx, base);
	// addi r30,r31,2036
	r30.s64 = r31.s64 + 2036;
	// li r28,0
	r28.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6a18
	ctx.lr = 0x824E1834;
	sub_824E6A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e18c0
	if (!cr6.eq) goto loc_824E18C0;
	// lwz r11,1968(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1968);
	// addi r29,r31,1816
	r29.s64 = r31.s64 + 1816;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,1812(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1812);
	// clrlwi r5,r11,16
	ctx.r5.u64 = r11.u32 & 0xFFFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824fb718
	ctx.lr = 0x824E185C;
	sub_824FB718(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e18c4
	if (cr6.eq) goto loc_824E18C4;
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,25924
	ctx.r4.s64 = r11.s64 + 25924;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b98
	ctx.lr = 0x824E1888;
	sub_824E6B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e18b8
	if (!cr6.eq) goto loc_824E18B8;
	// stw r28,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r28.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,1812(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1812);
	// bl 0x824fb6a0
	ctx.lr = 0x824E18A4;
	sub_824FB6A0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E18AC;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E18B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6a10
	ctx.lr = 0x824E18C0;
	sub_824E6A10(ctx, base);
loc_824E18C0:
	// li r28,1
	r28.s64 = 1;
loc_824E18C4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E18CC;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E18D8"))) PPC_WEAK_FUNC(sub_824E18D8);
PPC_FUNC_IMPL(__imp__sub_824E18D8) {
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
	ctx.lr = 0x824E18E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E18F4;
	sub_821C8FE0(ctx, base);
	// addi r30,r31,2036
	r30.s64 = r31.s64 + 2036;
	// li r29,0
	r29.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6a18
	ctx.lr = 0x824E1904;
	sub_824E6A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1934
	if (cr6.eq) goto loc_824E1934;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E1924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r31,1816
	ctx.r4.s64 = r31.s64 + 1816;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,1812(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1812);
	// bl 0x824fb6a0
	ctx.lr = 0x824E1934;
	sub_824FB6A0(ctx, base);
loc_824E1934:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E193C;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E1948"))) PPC_WEAK_FUNC(sub_824E1948);
PPC_FUNC_IMPL(__imp__sub_824E1948) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e1998
	if (cr6.eq) goto loc_824E1998;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E1980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E1998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E1998:
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

__attribute__((alias("__imp__sub_824E19B0"))) PPC_WEAK_FUNC(sub_824E19B0);
PPC_FUNC_IMPL(__imp__sub_824E19B0) {
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
	ctx.lr = 0x824E19B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r8,r10,25812
	ctx.r8.s64 = ctx.r10.s64 + 25812;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bne cr6,0x824e19e4
	if (!cr6.eq) goto loc_824E19E4;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_824E19E4:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r28,0
	r28.s64 = 0;
	// addi r9,r10,25960
	ctx.r9.s64 = ctx.r10.s64 + 25960;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// li r29,31
	r29.s64 = 31;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r27,-1
	r27.s64 = -1;
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
loc_824E1A14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E1A1C;
	sub_824F0498(ctx, base);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x824f9438
	ctx.lr = 0x824E1A24;
	sub_824F9438(ctx, base);
	// stw r27,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r27.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// bge 0x824e1a14
	if (!cr0.lt) goto loc_824E1A14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E1A44"))) PPC_WEAK_FUNC(sub_824E1A44);
PPC_FUNC_IMPL(__imp__sub_824E1A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E1A48"))) PPC_WEAK_FUNC(sub_824E1A48);
PPC_FUNC_IMPL(__imp__sub_824E1A48) {
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
	ctx.lr = 0x824E1A50;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r9,r11,25812
	ctx.r9.s64 = r11.s64 + 25812;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e1a84
	if (!cr6.eq) goto loc_824E1A84;
	// addi r7,r31,12
	ctx.r7.s64 = r31.s64 + 12;
loc_824E1A84:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// li r26,0
	r26.s64 = 0;
	// addi r10,r11,25968
	ctx.r10.s64 = r11.s64 + 25968;
	// addi r28,r31,24
	r28.s64 = r31.s64 + 24;
	// stw r26,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r26.u32);
	// stw r26,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r26.u32);
	// li r30,31
	r30.s64 = 31;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
	// stw r27,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r27.u32);
loc_824E1AB0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9438
	ctx.lr = 0x824E1AB8;
	sub_824F9438(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bge 0x824e1ab0
	if (!cr0.lt) goto loc_824E1AB0;
	// addi r11,r31,536
	r11.s64 = r31.s64 + 536;
	// li r10,127
	ctx.r10.s64 = 127;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r11,r25
	ctx.r9.s64 = r25.s64 - r11.s64;
loc_824E1AD4:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e1aec
	if (cr6.eq) goto loc_824E1AEC;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824e1ad4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E1AD4;
loc_824E1AEC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stb r26,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r26.u8);
	// beq cr6,0x824e1b24
	if (cr6.eq) goto loc_824E1B24;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// mr r11,r28
	r11.u64 = r28.u64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
loc_824E1B04:
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// std r8,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r8.u64);
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// std r7,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r7.u64);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x824e1b04
	if (!cr0.eq) goto loc_824E1B04;
loc_824E1B24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824E1B30"))) PPC_WEAK_FUNC(sub_824E1B30);
PPC_FUNC_IMPL(__imp__sub_824E1B30) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,25812
	ctx.r9.s64 = r11.s64 + 25812;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x824e1b64
	if (cr6.eq) goto loc_824E1B64;
	// bl 0x82130588
	ctx.lr = 0x824E1B60;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E1B64:
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

__attribute__((alias("__imp__sub_824E1B78"))) PPC_WEAK_FUNC(sub_824E1B78);
PPC_FUNC_IMPL(__imp__sub_824E1B78) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x824E1BAC;
	sub_823DA950(ctx, base);
	// addi r4,r30,104
	ctx.r4.s64 = r30.s64 + 104;
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E1BBC;
	sub_823DA950(ctx, base);
	// addi r11,r30,164
	r11.s64 = r30.s64 + 164;
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// li r9,9
	ctx.r9.s64 = 9;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E1BCC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824e1bcc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E1BCC;
	// addi r4,r30,200
	ctx.r4.s64 = r30.s64 + 200;
	// addi r3,r31,200
	ctx.r3.s64 = r31.s64 + 200;
	// bl 0x8226af08
	ctx.lr = 0x824E1BEC;
	sub_8226AF08(ctx, base);
	// lwz r11,760(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 760);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,760(r31)
	PPC_STORE_U32(r31.u32 + 760, r11.u32);
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

__attribute__((alias("__imp__sub_824E1C10"))) PPC_WEAK_FUNC(sub_824E1C10);
PPC_FUNC_IMPL(__imp__sub_824E1C10) {
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
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e8de8
	ctx.lr = 0x824E1C34;
	sub_824E8DE8(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x824e8e30
	ctx.lr = 0x824E1C50;
	sub_824E8E30(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,532(r31)
	PPC_STORE_U32(r31.u32 + 532, r11.u32);
	// stw r11,536(r31)
	PPC_STORE_U32(r31.u32 + 536, r11.u32);
	// std r11,544(r31)
	PPC_STORE_U64(r31.u32 + 544, r11.u64);
	// std r11,552(r31)
	PPC_STORE_U64(r31.u32 + 552, r11.u64);
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

__attribute__((alias("__imp__sub_824E1C80"))) PPC_WEAK_FUNC(sub_824E1C80);
PPC_FUNC_IMPL(__imp__sub_824E1C80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x824E1C88;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x824e9948
	ctx.lr = 0x824E1CA8;
	sub_824E9948(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dcc
	if (cr6.eq) goto loc_824E1DCC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824E1CBC;
	sub_82618750(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// subf r5,r11,r29
	ctx.r5.s64 = r29.s64 - r11.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x82618640
	ctx.lr = 0x824E1CD0;
	sub_82618640(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e6390
	ctx.lr = 0x824E1CE0;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dc4
	if (cr6.eq) goto loc_824E1DC4;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6390
	ctx.lr = 0x824E1CFC;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dc4
	if (cr6.eq) goto loc_824E1DC4;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6390
	ctx.lr = 0x824E1D18;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dc4
	if (cr6.eq) goto loc_824E1DC4;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r4,528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 528);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6390
	ctx.lr = 0x824E1D34;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dc4
	if (cr6.eq) goto loc_824E1DC4;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r4,532(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 532);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6390
	ctx.lr = 0x824E1D50;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dc4
	if (cr6.eq) goto loc_824E1DC4;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,536(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 536);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6390
	ctx.lr = 0x824E1D6C;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dc4
	if (cr6.eq) goto loc_824E1DC4;
	// li r5,64
	ctx.r5.s64 = 64;
	// ld r4,544(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 544);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618d38
	ctx.lr = 0x824E1D88;
	sub_82618D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dc4
	if (cr6.eq) goto loc_824E1DC4;
	// li r5,64
	ctx.r5.s64 = 64;
	// ld r4,552(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 552);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618d38
	ctx.lr = 0x824E1DA4;
	sub_82618D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1dc4
	if (cr6.eq) goto loc_824E1DC4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186a0
	ctx.lr = 0x824E1DB8;
	sub_826186A0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// b 0x824e1dd0
	goto loc_824E1DD0;
loc_824E1DC4:
	// li r11,0
	r11.s64 = 0;
	// b 0x824e1dd0
	goto loc_824E1DD0;
loc_824E1DCC:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_824E1DD0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e1ddc
	if (cr6.eq) goto loc_824E1DDC;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824E1DDC:
	// subfic r11,r11,0
	xer.ca = r11.u32 <= 0;
	r11.s64 = 0 - r11.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E1DF0"))) PPC_WEAK_FUNC(sub_824E1DF0);
PPC_FUNC_IMPL(__imp__sub_824E1DF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x824E1DF8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x824e9c48
	ctx.lr = 0x824E1E18;
	sub_824E9C48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f3c
	if (cr6.eq) goto loc_824E1F3C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824E1E2C;
	sub_82618750(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// subf r5,r11,r29
	ctx.r5.s64 = r29.s64 - r11.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x826185e0
	ctx.lr = 0x824E1E40;
	sub_826185E0(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E1E50;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f34
	if (cr6.eq) goto loc_824E1F34;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E1E6C;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f34
	if (cr6.eq) goto loc_824E1F34;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E1E88;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f34
	if (cr6.eq) goto loc_824E1F34;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,528
	ctx.r4.s64 = r31.s64 + 528;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E1EA4;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f34
	if (cr6.eq) goto loc_824E1F34;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,532
	ctx.r4.s64 = r31.s64 + 532;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E1EC0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f34
	if (cr6.eq) goto loc_824E1F34;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,536
	ctx.r4.s64 = r31.s64 + 536;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E1EDC;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f34
	if (cr6.eq) goto loc_824E1F34;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r31,544
	ctx.r4.s64 = r31.s64 + 544;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618c90
	ctx.lr = 0x824E1EF8;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f34
	if (cr6.eq) goto loc_824E1F34;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r31,552
	ctx.r4.s64 = r31.s64 + 552;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618c90
	ctx.lr = 0x824E1F14;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e1f34
	if (cr6.eq) goto loc_824E1F34;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E1F28;
	sub_826186B0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// b 0x824e1f40
	goto loc_824E1F40;
loc_824E1F34:
	// li r11,0
	r11.s64 = 0;
	// b 0x824e1f40
	goto loc_824E1F40;
loc_824E1F3C:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_824E1F40:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e1f4c
	if (cr6.eq) goto loc_824E1F4C;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824E1F4C:
	// subfic r11,r11,0
	xer.ca = r11.u32 <= 0;
	r11.s64 = 0 - r11.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E1F60"))) PPC_WEAK_FUNC(sub_824E1F60);
PPC_FUNC_IMPL(__imp__sub_824E1F60) {
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
	ctx.lr = 0x824E1F68;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r30,r31,2100
	r30.s64 = r31.s64 + 2100;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1F9C;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r28,0
	r28.s64 = 0;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1FAC;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r20,r9,27,31,31
	r20.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E1FC8;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x824e2074
	if (cr6.eq) goto loc_824E2074;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c8fe0
	ctx.lr = 0x824E1FDC;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1972);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E1FF8;
	sub_821C9030(ctx, base);
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e2074
	if (!cr6.eq) goto loc_824E2074;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E200C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2074
	if (cr6.eq) goto loc_824E2074;
	// cmpwi cr6,r26,1
	cr6.compare<int32_t>(r26.s32, 1, xer);
	// bne cr6,0x824e2038
	if (!cr6.eq) goto loc_824E2038;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821f8730
	ctx.lr = 0x824E2028;
	sub_821F8730(ctx, base);
	// bl 0x824e6d68
	ctx.lr = 0x824E202C;
	sub_824E6D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2074
	if (cr6.eq) goto loc_824E2074;
loc_824E2038:
	// stw r28,2096(r31)
	PPC_STORE_U32(r31.u32 + 2096, r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E2044;
	sub_824E0B08(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,248
	ctx.r4.s64 = 248;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824E2068;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e20a8
	if (!cr6.eq) goto loc_824E20A8;
loc_824E2074:
	// lwz r31,316(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e20ec
	if (cr6.eq) goto loc_824E20EC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E208C;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E209C;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9228
	return;
loc_824E20A8:
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// lwz r11,316(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e07f8
	ctx.lr = 0x824E20DC;
	sub_824E07F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E20E8;
	sub_824E1338(ctx, base);
	// li r28,1
	r28.s64 = 1;
loc_824E20EC:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x821c9030
	ctx.lr = 0x824E20F4;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824E2100"))) PPC_WEAK_FUNC(sub_824E2100);
PPC_FUNC_IMPL(__imp__sub_824E2100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x824E2108;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r31,r26,2100
	r31.s64 = r26.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E212C;
	sub_821C8FE0(ctx, base);
	// li r20,0
	r20.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r20
	r30.u64 = r20.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2140;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e2158
	if (cr6.lt) goto loc_824E2158;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r27,1
	r27.s64 = 1;
	// ble cr6,0x824e215c
	if (!cr6.gt) goto loc_824E215C;
loc_824E2158:
	// mr r27,r20
	r27.u64 = r20.u64;
loc_824E215C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E2164;
	sub_821C9030(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// lis r21,-32115
	r21.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e22bc
	if (cr6.eq) goto loc_824E22BC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2180;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r20,r11
	ctx.r10.s64 = r11.s64 - r20.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r31,r8,1
	r31.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E219C;
	sub_821C9030(ctx, base);
	// clrlwi r7,r31,24
	ctx.r7.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e22bc
	if (!cr6.eq) goto loc_824E22BC;
	// cmplwi cr6,r29,32
	cr6.compare<uint32_t>(r29.u32, 32, xer);
	// bgt cr6,0x824e22bc
	if (cr6.gt) goto loc_824E22BC;
	// lwz r3,32268(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 32268);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1064
	ctx.r4.s64 = 1064;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E21D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e22bc
	if (cr6.eq) goto loc_824E22BC;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x824e19b0
	ctx.lr = 0x824E21E4;
	sub_824E19B0(ctx, base);
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// mr r23,r20
	r23.u64 = r20.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r25,r20
	r25.u64 = r20.u64;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r10,1056(r30)
	PPC_STORE_U32(r30.u32 + 1056, ctx.r10.u32);
	// ble cr6,0x824e22bc
	if (!cr6.gt) goto loc_824E22BC;
	// addi r24,r30,32
	r24.s64 = r30.s64 + 32;
loc_824E2208:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82502300
	ctx.lr = 0x824E2210;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824e1778
	ctx.lr = 0x824E221C;
	sub_824E1778(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824e22a0
	if (cr6.lt) goto loc_824E22A0;
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// addi r27,r11,776
	r27.s64 = r11.s64 + 776;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e22a0
	if (cr6.eq) goto loc_824E22A0;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x824e7008
	ctx.lr = 0x824E2240;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e225c
	if (cr6.eq) goto loc_824E225C;
	// mr r31,r24
	r31.u64 = r24.u64;
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r24,r24,32
	r24.s64 = r24.s64 + 32;
	// b 0x824e226c
	goto loc_824E226C;
loc_824E225C:
	// lwz r11,1056(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1056);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r31,r11,-32
	r31.s64 = r11.s64 + -32;
	// stw r31,1056(r30)
	PPC_STORE_U32(r30.u32 + 1056, r31.u32);
loc_824E226C:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x821f8730
	ctx.lr = 0x824E2274;
	sub_821F8730(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x824e7110
	ctx.lr = 0x824E2280;
	sub_824E7110(ctx, base);
	// ld r11,0(r27)
	r11.u64 = PPC_LOAD_U64(r27.u32 + 0);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// std r11,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r11.u64);
	// ld r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// std r9,8(r31)
	PPC_STORE_U64(r31.u32 + 8, ctx.r9.u64);
	// ld r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// std r8,16(r31)
	PPC_STORE_U64(r31.u32 + 16, ctx.r8.u64);
	// stw r19,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r19.u32);
loc_824E22A0:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x824e2208
	if (!cr0.eq) goto loc_824E2208;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x824e2328
	if (!cr6.eq) goto loc_824E2328;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x824e2328
	if (!cr6.eq) goto loc_824E2328;
loc_824E22BC:
	// lwz r31,32268(r21)
	r31.u64 = PPC_LOAD_U32(r21.u32 + 32268);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e22f8
	if (cr6.eq) goto loc_824E22F8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E22E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E22F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E22F8:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824e2340
	if (cr6.eq) goto loc_824E2340;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E230C;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,4(r22)
	PPC_STORE_U32(r22.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E231C;
	sub_821C9030(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
loc_824E2328:
	// stw r23,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r23.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r25,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r25.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E233C;
	sub_824E1338(ctx, base);
	// li r20,1
	r20.s64 = 1;
loc_824E2340:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E2348;
	sub_821C9030(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_824E2354"))) PPC_WEAK_FUNC(sub_824E2354);
PPC_FUNC_IMPL(__imp__sub_824E2354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E2358"))) PPC_WEAK_FUNC(sub_824E2358);
PPC_FUNC_IMPL(__imp__sub_824E2358) {
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
	ctx.lr = 0x824E2360;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r27,2100
	r30.s64 = r27.s64 + 2100;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2380;
	sub_821C8FE0(ctx, base);
	// li r20,0
	r20.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r25,r20
	r25.u64 = r20.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2394;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e23ac
	if (cr6.lt) goto loc_824E23AC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r29,1
	r29.s64 = 1;
	// ble cr6,0x824e23b0
	if (!cr6.gt) goto loc_824E23B0;
loc_824E23AC:
	// mr r29,r20
	r29.u64 = r20.u64;
loc_824E23B0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E23B8;
	sub_821C9030(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// lis r21,-32115
	r21.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2598
	if (cr6.eq) goto loc_824E2598;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E23D4;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r20,r11
	ctx.r10.s64 = r11.s64 - r20.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E23F0;
	sub_821C9030(ctx, base);
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e2598
	if (!cr6.eq) goto loc_824E2598;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8e58
	ctx.lr = 0x824E2404;
	sub_824E8E58(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824e2598
	if (!cr6.gt) goto loc_824E2598;
	// lwz r3,32268(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 32268);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,536
	ctx.r4.s64 = 536;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E242C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824e2598
	if (cr6.eq) goto loc_824E2598;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x824e0900
	ctx.lr = 0x824E2440;
	sub_824E0900(ctx, base);
	// addi r26,r27,220
	r26.s64 = r27.s64 + 220;
	// addi r28,r25,20
	r28.s64 = r25.s64 + 20;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824ea350
	ctx.lr = 0x824E2454;
	sub_824EA350(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r30,r20
	r30.u64 = r20.u64;
	// bl 0x824e8e58
	ctx.lr = 0x824E2460;
	sub_824E8E58(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824e2574
	if (!cr6.gt) goto loc_824E2574;
	// lis r11,0
	r11.s64 = 0;
	// li r23,128
	r23.s64 = 128;
	// ori r24,r11,32779
	r24.u64 = r11.u64 | 32779;
loc_824E2474:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8f28
	ctx.lr = 0x824E2480;
	sub_824E8F28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e2560
	if (!cr6.eq) goto loc_824E2560;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e94f0
	ctx.lr = 0x824E2498;
	sub_824E94F0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,32779
	cr6.compare<uint32_t>(r29.u32, 32779, xer);
	// bne cr6,0x824e2518
	if (!cr6.eq) goto loc_824E2518;
	// stw r23,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r23.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r3,768(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 768);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x8274bec0
	ctx.lr = 0x824E24BC;
	sub_8274BEC0(ctx, base);
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824e2518
	if (cr6.eq) goto loc_824E2518;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E24D4;
	sub_824E9038(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824e9690
	ctx.lr = 0x824E24E8;
	sub_824E9690(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E24F4;
	sub_824E9038(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e9690
	ctx.lr = 0x824E2508;
	sub_824E9690(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x824e2598
	if (!cr6.eq) goto loc_824E2598;
loc_824E2518:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E2524;
	sub_824E9038(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x824e2598
	if (cr6.lt) goto loc_824E2598;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e9740
	ctx.lr = 0x824E253C;
	sub_824E9740(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E254C;
	sub_824E95F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// bl 0x824e9530
	ctx.lr = 0x824E2560;
	sub_824E9530(ctx, base);
loc_824E2560:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x824e8e58
	ctx.lr = 0x824E256C;
	sub_824E8E58(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x824e2474
	if (cr6.lt) goto loc_824E2474;
loc_824E2574:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E2580;
	sub_824E1338(ctx, base);
	// li r20,1
	r20.s64 = 1;
loc_824E2584:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824E258C;
	sub_821C9030(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9224
	return;
loc_824E2598:
	// lwz r31,32268(r21)
	r31.u64 = PPC_LOAD_U32(r21.u32 + 32268);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824e25d4
	if (cr6.eq) goto loc_824E25D4;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E25BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E25D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E25D4:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824e2584
	if (cr6.eq) goto loc_824E2584;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E25E8;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,4(r22)
	PPC_STORE_U32(r22.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E25F8;
	sub_821C9030(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_824E2604"))) PPC_WEAK_FUNC(sub_824E2604);
PPC_FUNC_IMPL(__imp__sub_824E2604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E2608"))) PPC_WEAK_FUNC(sub_824E2608);
PPC_FUNC_IMPL(__imp__sub_824E2608) {
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
	ctx.lr = 0x824E2610;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r30,r31,2100
	r30.s64 = r31.s64 + 2100;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2628;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2634;
	sub_821C8FE0(ctx, base);
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824e264c
	if (cr6.eq) goto loc_824E264C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r29,0
	r29.s64 = 0;
	// bne cr6,0x824e2650
	if (!cr6.eq) goto loc_824E2650;
loc_824E264C:
	// li r29,1
	r29.s64 = 1;
loc_824E2650:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E2658;
	sub_821C9030(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e26a4
	if (cr6.eq) goto loc_824E26A4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2670;
	sub_821C8FE0(ctx, base);
	// lwz r11,736(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,0
	ctx.r10.s64 = r11.s64 + 0;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E2688;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e26a4
	if (!cr6.eq) goto loc_824E26A4;
	// lwz r11,744(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// li r31,1
	r31.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e26a8
	if (!cr6.eq) goto loc_824E26A8;
loc_824E26A4:
	// li r31,0
	r31.s64 = 0;
loc_824E26A8:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E26B0;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E26BC"))) PPC_WEAK_FUNC(sub_824E26BC);
PPC_FUNC_IMPL(__imp__sub_824E26BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E26C0"))) PPC_WEAK_FUNC(sub_824E26C0);
PPC_FUNC_IMPL(__imp__sub_824E26C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x824E26C8;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// addi r30,r28,2100
	r30.s64 = r28.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r20,r7
	r20.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E26F0;
	sub_821C8FE0(ctx, base);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// bne cr6,0x824e2700
	if (!cr6.eq) goto loc_824E2700;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r22,r11,3998
	r22.s64 = r11.s64 + 3998;
loc_824E2700:
	// li r21,0
	r21.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r21
	r31.u64 = r21.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2714;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e272c
	if (cr6.lt) goto loc_824E272C;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r29,1
	r29.s64 = 1;
	// ble cr6,0x824e2730
	if (!cr6.gt) goto loc_824E2730;
loc_824E272C:
	// mr r29,r21
	r29.u64 = r21.u64;
loc_824E2730:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E2738;
	sub_821C9030(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// lis r23,-32115
	r23.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2884
	if (cr6.eq) goto loc_824E2884;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2754;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r21,r11
	ctx.r10.s64 = r11.s64 - r21.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E2770;
	sub_821C9030(ctx, base);
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e2884
	if (!cr6.eq) goto loc_824E2884;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e2608
	ctx.lr = 0x824E2784;
	sub_824E2608(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2884
	if (cr6.eq) goto loc_824E2884;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e2884
	if (cr6.eq) goto loc_824E2884;
	// cmplwi cr6,r26,32
	cr6.compare<uint32_t>(r26.u32, 32, xer);
	// bge cr6,0x824e2884
	if (!cr6.lt) goto loc_824E2884;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// li r31,31
	r31.s64 = 31;
loc_824E27A8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9438
	ctx.lr = 0x824E27B0;
	sub_824F9438(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bge 0x824e27a8
	if (!cr0.lt) goto loc_824E27A8;
	// mr r24,r21
	r24.u64 = r21.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x824e2914
	if (!cr6.gt) goto loc_824E2914;
	// mr r29,r25
	r29.u64 = r25.u64;
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// mr r25,r26
	r25.u64 = r26.u64;
loc_824E27D4:
	// lwz r11,1800(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1800);
	// mr r26,r21
	r26.u64 = r21.u64;
	// mr r30,r21
	r30.u64 = r21.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824e2820
	if (!cr6.gt) goto loc_824E2820;
	// addi r31,r28,784
	r31.s64 = r28.s64 + 784;
loc_824E27EC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f92f8
	ctx.lr = 0x824E27F8;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e281c
	if (!cr6.eq) goto loc_824E281C;
	// lwz r11,1800(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 1800);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x824e27ec
	if (cr6.lt) goto loc_824E27EC;
	// b 0x824e2820
	goto loc_824E2820;
loc_824E281C:
	// li r26,1
	r26.s64 = 1;
loc_824E2820:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e2844
	if (!cr6.eq) goto loc_824E2844;
	// ld r11,0(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 0);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// ld r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U64(r29.u32 + 8);
	// std r11,0(r27)
	PPC_STORE_U64(r27.u32 + 0, r11.u64);
	// std r10,8(r27)
	PPC_STORE_U64(r27.u32 + 8, ctx.r10.u64);
	// addi r27,r27,16
	r27.s64 = r27.s64 + 16;
loc_824E2844:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bne 0x824e27d4
	if (!cr0.eq) goto loc_824E27D4;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824e2914
	if (cr6.eq) goto loc_824E2914;
	// lwz r3,32268(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 32268);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,664
	ctx.r4.s64 = 664;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E2878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824e28f0
	if (!cr6.eq) goto loc_824E28F0;
loc_824E2884:
	// lwz r30,32268(r23)
	r30.u64 = PPC_LOAD_U32(r23.u32 + 32268);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e28c0
	if (cr6.eq) goto loc_824E28C0;
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
	ctx.lr = 0x824E28A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E28C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E28C0:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x824e2918
	if (cr6.eq) goto loc_824E2918;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E28D4;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,4(r20)
	PPC_STORE_U32(r20.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E28E4;
	sub_821C9030(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9228
	return;
loc_824E28F0:
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1a48
	ctx.lr = 0x824E2908;
	sub_824E1A48(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E2914;
	sub_824E1338(ctx, base);
loc_824E2914:
	// li r21,1
	r21.s64 = 1;
loc_824E2918:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E2920;
	sub_821C9030(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824E292C"))) PPC_WEAK_FUNC(sub_824E292C);
PPC_FUNC_IMPL(__imp__sub_824E292C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E2930"))) PPC_WEAK_FUNC(sub_824E2930);
PPC_FUNC_IMPL(__imp__sub_824E2930) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x824E2938;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r31,r29,2100
	r31.s64 = r29.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E295C;
	sub_821C8FE0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r24,r30
	r24.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2970;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E2978;
	sub_821C9030(ctx, base);
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x824E2980;
	sub_82130000(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f9950
	ctx.lr = 0x824E298C;
	sub_824F9950(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E299C;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e29b4
	if (cr6.lt) goto loc_824E29B4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r28,1
	r28.s64 = 1;
	// ble cr6,0x824e29b8
	if (!cr6.gt) goto loc_824E29B8;
loc_824E29B4:
	// mr r28,r30
	r28.u64 = r30.u64;
loc_824E29B8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E29C0;
	sub_821C9030(ctx, base);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// lis r28,-32115
	r28.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2ac8
	if (cr6.eq) goto loc_824E2AC8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E29DC;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r30,r11
	ctx.r10.s64 = r11.s64 - r30.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r31,r8,1
	r31.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E29F8;
	sub_821C9030(ctx, base);
	// clrlwi r7,r31,24
	ctx.r7.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e2ac8
	if (!cr6.eq) goto loc_824E2AC8;
	// lwz r3,32268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32268);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,136
	ctx.r4.s64 = 136;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E2A24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e2ac8
	if (cr6.eq) goto loc_824E2AC8;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r4,-6772(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -6772);
	// bl 0x824e0978
	ctx.lr = 0x824E2A40;
	sub_824E0978(ctx, base);
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e2a5c
	if (!cr6.eq) goto loc_824E2A5C;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x824e2a64
	if (!cr6.eq) goto loc_824E2A64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2ac8
	if (cr6.eq) goto loc_824E2AC8;
loc_824E2A5C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x824e2ac8
	if (!cr6.eq) goto loc_824E2AC8;
loc_824E2A64:
	// addi r10,r30,24
	ctx.r10.s64 = r30.s64 + 24;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E2A74:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824e2a74
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E2A74;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bne cr6,0x824e2a98
	if (!cr6.eq) goto loc_824E2A98;
	// addi r4,r29,112
	ctx.r4.s64 = r29.s64 + 112;
loc_824E2A98:
	// addi r3,r30,72
	ctx.r3.s64 = r30.s64 + 72;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E2AA4;
	sub_823DA950(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E2AB0;
	sub_824E1338(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// li r24,1
	r24.s64 = 1;
	// bl 0x821c9030
	ctx.lr = 0x824E2ABC;
	sub_821C9030(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
loc_824E2AC8:
	// lwz r31,32268(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 32268);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e2b04
	if (cr6.eq) goto loc_824E2B04;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E2AEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E2B04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E2B04:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824e2b20
	if (cr6.eq) goto loc_824E2B20;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E2B18;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r25)
	PPC_STORE_U32(r25.u32 + 4, r11.u32);
loc_824E2B20:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E2B28;
	sub_821C9030(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824E2B34"))) PPC_WEAK_FUNC(sub_824E2B34);
PPC_FUNC_IMPL(__imp__sub_824E2B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E2B38"))) PPC_WEAK_FUNC(sub_824E2B38);
PPC_FUNC_IMPL(__imp__sub_824E2B38) {
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
	ctx.lr = 0x824E2B40;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r29,r30,2100
	r29.s64 = r30.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2B64;
	sub_821C8FE0(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2B78;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e2b90
	if (cr6.lt) goto loc_824E2B90;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r26,1
	r26.s64 = 1;
	// ble cr6,0x824e2b94
	if (!cr6.gt) goto loc_824E2B94;
loc_824E2B90:
	// mr r26,r25
	r26.u64 = r25.u64;
loc_824E2B94:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E2B9C;
	sub_821C9030(ctx, base);
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// lis r26,-32115
	r26.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2c24
	if (cr6.eq) goto loc_824E2C24;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2BB8;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r25,r11
	ctx.r10.s64 = r11.s64 - r25.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r29,r8,1
	r29.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E2BD4;
	sub_821C9030(ctx, base);
	// clrlwi r7,r29,24
	ctx.r7.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e2c24
	if (!cr6.eq) goto loc_824E2C24;
	// add r11,r28,r27
	r11.u64 = r28.u64 + r27.u64;
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bgt cr6,0x824e2c24
	if (cr6.gt) goto loc_824E2C24;
	// lwz r10,1800(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1800);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x824e2c24
	if (cr6.lt) goto loc_824E2C24;
	// lwz r3,32268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 32268);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,36
	ctx.r4.s64 = 36;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E2C18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824e2c90
	if (!cr6.eq) goto loc_824E2C90;
loc_824E2C24:
	// lwz r30,32268(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 32268);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e2c60
	if (cr6.eq) goto loc_824E2C60;
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
	ctx.lr = 0x824E2C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E2C60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E2C60:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824e2cfc
	if (cr6.eq) goto loc_824E2CFC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E2C74;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E2C84;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_824E2C90:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r10,216(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// li r8,11
	ctx.r8.s64 = 11;
	// lwz r9,212(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// addi r7,r11,25812
	ctx.r7.s64 = r11.s64 + 25812;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r11,r24
	r11.u64 = r24.u64;
	// bne cr6,0x824e2cbc
	if (!cr6.eq) goto loc_824E2CBC;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_824E2CBC:
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r25,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r25.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r7,r8,25860
	ctx.r7.s64 = ctx.r8.s64 + 25860;
	// stw r25,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r25.u32);
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stw r27,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r27.u32);
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// stw r28,212(r30)
	PPC_STORE_U32(r30.u32 + 212, r28.u32);
	// stw r27,216(r30)
	PPC_STORE_U32(r30.u32 + 216, r27.u32);
	// bl 0x824e1338
	ctx.lr = 0x824E2CF8;
	sub_824E1338(ctx, base);
	// li r25,1
	r25.s64 = 1;
loc_824E2CFC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E2D04;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824E2D10"))) PPC_WEAK_FUNC(sub_824E2D10);
PPC_FUNC_IMPL(__imp__sub_824E2D10) {
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
	// bl 0x824e1778
	ctx.lr = 0x824E2D20;
	sub_824E1778(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
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

__attribute__((alias("__imp__sub_824E2D40"))) PPC_WEAK_FUNC(sub_824E2D40);
PPC_FUNC_IMPL(__imp__sub_824E2D40) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x824E2D74;
	sub_823DA950(ctx, base);
	// addi r4,r30,104
	ctx.r4.s64 = r30.s64 + 104;
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E2D84;
	sub_823DA950(ctx, base);
	// addi r11,r30,164
	r11.s64 = r30.s64 + 164;
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// li r9,9
	ctx.r9.s64 = 9;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E2D94:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824e2d94
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E2D94;
	// addi r4,r30,200
	ctx.r4.s64 = r30.s64 + 200;
	// addi r3,r31,200
	ctx.r3.s64 = r31.s64 + 200;
	// bl 0x82214f50
	ctx.lr = 0x824E2DB4;
	sub_82214F50(ctx, base);
	// lwz r11,760(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 760);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,760(r31)
	PPC_STORE_U32(r31.u32 + 760, r11.u32);
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

__attribute__((alias("__imp__sub_824E2DD8"))) PPC_WEAK_FUNC(sub_824E2DD8);
PPC_FUNC_IMPL(__imp__sub_824E2DD8) {
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
	ctx.lr = 0x824E2DE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824e1590
	ctx.lr = 0x824E2DF0;
	sub_824E1590(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e2e20
	if (cr6.eq) goto loc_824E2E20;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E2E0C;
	sub_821C8FE0(ctx, base);
	// addi r4,r29,20
	ctx.r4.s64 = r29.s64 + 20;
	// addi r3,r31,220
	ctx.r3.s64 = r31.s64 + 220;
	// bl 0x824ea1b0
	ctx.lr = 0x824E2E18;
	sub_824EA1B0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E2E20;
	sub_821C9030(ctx, base);
loc_824E2E20:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E2E2C"))) PPC_WEAK_FUNC(sub_824E2E2C);
PPC_FUNC_IMPL(__imp__sub_824E2E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E2E30"))) PPC_WEAK_FUNC(sub_824E2E30);
PPC_FUNC_IMPL(__imp__sub_824E2E30) {
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
	ctx.lr = 0x824E2E38;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r31,r4,24
	r31.s64 = ctx.r4.s64 + 24;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// stw r9,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r9.u32);
	// addi r11,r1,148
	r11.s64 = ctx.r1.s64 + 148;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E2E58:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e2e58
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E2E58;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E2E78;
	sub_8244EE40(ctx, base);
	// stw r3,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r3.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e2f70
	if (cr6.eq) goto loc_824E2F70;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// lwz r10,736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lwz r9,732(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 732);
	// addi r30,r31,104
	r30.s64 = r31.s64 + 104;
	// lwz r7,208(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r26,r31,760
	r26.s64 = r31.s64 + 760;
	// lwz r6,204(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// addi r25,r31,752
	r25.s64 = r31.s64 + 752;
	// lwz r5,728(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 728);
	// li r24,1
	r24.s64 = 1;
	// lwz r4,200(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// addi r8,r31,212
	ctx.r8.s64 = r31.s64 + 212;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r24,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r24.u8);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x824e1438
	ctx.lr = 0x824E2ED8;
	sub_824E1438(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e2ef4
	if (!cr6.eq) goto loc_824E2EF4;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,156(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x82135db8
	ctx.lr = 0x824E2EEC;
	sub_82135DB8(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82450030
	ctx.lr = 0x824E2EF4;
	sub_82450030(ctx, base);
loc_824E2EF4:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e2f68
	if (!cr6.eq) goto loc_824E2F68;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824e2f10
	if (cr6.eq) goto loc_824E2F10;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x824e2f38
	if (!cr6.eq) goto loc_824E2F38;
loc_824E2F10:
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// li r7,9
	ctx.r7.s64 = 9;
	// li r6,16384
	ctx.r6.s64 = 16384;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// bl 0x8244a5e0
	ctx.lr = 0x824E2F30;
	sub_8244A5E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824e2f68
	if (!cr6.eq) goto loc_824E2F68;
loc_824E2F38:
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x824e2f64
	if (!cr6.eq) goto loc_824E2F64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x824E2F4C;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x824E2F50;
	sub_82130000(ctx, base);
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823da950
	ctx.lr = 0x824E2F64;
	sub_823DA950(ctx, base);
loc_824E2F64:
	// li r28,1
	r28.s64 = 1;
loc_824E2F68:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E2F70;
	sub_8244EEE0(ctx, base);
loc_824E2F70:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824E2F7C"))) PPC_WEAK_FUNC(sub_824E2F7C);
PPC_FUNC_IMPL(__imp__sub_824E2F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E2F80"))) PPC_WEAK_FUNC(sub_824E2F80);
PPC_FUNC_IMPL(__imp__sub_824E2F80) {
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
	ctx.lr = 0x824E2F88;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r11,r1,148
	r11.s64 = ctx.r1.s64 + 148;
	// stw r29,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r29.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E2FA8:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e2fa8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E2FA8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E2FC8;
	sub_8244EE40(ctx, base);
	// stw r3,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r3.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e3088
	if (cr6.eq) goto loc_824E3088;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lwz r9,188(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r30,r31,120
	r30.s64 = r31.s64 + 120;
	// addi r27,r1,136
	r27.s64 = ctx.r1.s64 + 136;
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,180(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r29,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r29.u8);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x824e1438
	ctx.lr = 0x824E3020;
	sub_824E1438(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e303c
	if (!cr6.eq) goto loc_824E303C;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,156(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x82135db8
	ctx.lr = 0x824E3034;
	sub_82135DB8(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82450030
	ctx.lr = 0x824E303C;
	sub_82450030(ctx, base);
loc_824E303C:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e3080
	if (!cr6.eq) goto loc_824E3080;
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// li r7,9
	ctx.r7.s64 = 9;
	// li r6,16384
	ctx.r6.s64 = 16384;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// bl 0x8244a5e0
	ctx.lr = 0x824E3064;
	sub_8244A5E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824e3080
	if (!cr6.eq) goto loc_824E3080;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// addi r3,r31,204
	ctx.r3.s64 = r31.s64 + 204;
	// li r5,36
	ctx.r5.s64 = 36;
	// bl 0x823da950
	ctx.lr = 0x824E307C;
	sub_823DA950(ctx, base);
	// li r29,1
	r29.s64 = 1;
loc_824E3080:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E3088;
	sub_8244EEE0(ctx, base);
loc_824E3088:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E3094"))) PPC_WEAK_FUNC(sub_824E3094);
PPC_FUNC_IMPL(__imp__sub_824E3094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E3098"))) PPC_WEAK_FUNC(sub_824E3098);
PPC_FUNC_IMPL(__imp__sub_824E3098) {
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
	ctx.lr = 0x824E30A0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r31,r4,24
	r31.s64 = ctx.r4.s64 + 24;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E30C0:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e30c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E30C0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E30E0;
	sub_8244EE40(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e31d0
	if (cr6.eq) goto loc_824E31D0;
	// addi r30,r31,212
	r30.s64 = r31.s64 + 212;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e8e58
	ctx.lr = 0x824E30FC;
	sub_824E8E58(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824e3128
	if (cr6.eq) goto loc_824E3128;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821f8730
	ctx.lr = 0x824E310C;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x824e9240
	ctx.lr = 0x824E311C;
	sub_824E9240(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e31c8
	if (cr6.eq) goto loc_824E31C8;
loc_824E3128:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e70f0
	ctx.lr = 0x824E3130;
	sub_824E70F0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,736(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// lwz r5,732(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 732);
	// lwz r4,728(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 728);
	// lwz r3,200(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// bl 0x824e1398
	ctx.lr = 0x824E314C;
	sub_824E1398(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,208(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r5,204(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// lwz r3,760(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 760);
	// bl 0x8274b5f0
	ctx.lr = 0x824E3164;
	sub_8274B5F0(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e3180
	if (!cr6.eq) goto loc_824E3180;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82135db8
	ctx.lr = 0x824E3178;
	sub_82135DB8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82450030
	ctx.lr = 0x824E3180;
	sub_82450030(ctx, base);
loc_824E3180:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e31c8
	if (!cr6.eq) goto loc_824E31C8;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824e319c
	if (cr6.eq) goto loc_824E319C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x824e31c4
	if (!cr6.eq) goto loc_824E31C4;
loc_824E319C:
	// ld r11,104(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// li r7,9
	ctx.r7.s64 = 9;
	// li r6,16384
	ctx.r6.s64 = 16384;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x8244a5e0
	ctx.lr = 0x824E31BC;
	sub_8244A5E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824e31c8
	if (!cr6.eq) goto loc_824E31C8;
loc_824E31C4:
	// li r29,1
	r29.s64 = 1;
loc_824E31C8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E31D0;
	sub_8244EEE0(ctx, base);
loc_824E31D0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E31DC"))) PPC_WEAK_FUNC(sub_824E31DC);
PPC_FUNC_IMPL(__imp__sub_824E31DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E31E0"))) PPC_WEAK_FUNC(sub_824E31E0);
PPC_FUNC_IMPL(__imp__sub_824E31E0) {
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
	ctx.lr = 0x824E31E8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,784(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 784);
	// li r30,0
	r30.s64 = 0;
	// addi r31,r4,24
	r31.s64 = ctx.r4.s64 + 24;
	// mr r29,r30
	r29.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e3210
	if (!cr6.eq) goto loc_824E3210;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
loc_824E3210:
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E3224:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e3224
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E3224;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3244;
	sub_8244EE40(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e32b8
	if (cr6.eq) goto loc_824E32B8;
	// ld r11,104(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x8244a5e0
	ctx.lr = 0x824E3270;
	sub_8244A5E0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,760(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 760);
	// bl 0x8274b6a8
	ctx.lr = 0x824E327C;
	sub_8274B6A8(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e3298
	if (!cr6.eq) goto loc_824E3298;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82135db8
	ctx.lr = 0x824E3290;
	sub_82135DB8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82450030
	ctx.lr = 0x824E3298;
	sub_82450030(ctx, base);
loc_824E3298:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e32a4
	if (!cr6.eq) goto loc_824E32A4;
	// li r29,1
	r29.s64 = 1;
loc_824E32A4:
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x8244eee0
	ctx.lr = 0x824E32AC;
	sub_8244EEE0(ctx, base);
	// lwz r3,760(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 760);
	// bl 0x8275cc90
	ctx.lr = 0x824E32B4;
	sub_8275CC90(ctx, base);
	// stw r30,760(r31)
	PPC_STORE_U32(r31.u32 + 760, r30.u32);
loc_824E32B8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E32C4"))) PPC_WEAK_FUNC(sub_824E32C4);
PPC_FUNC_IMPL(__imp__sub_824E32C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E32C8"))) PPC_WEAK_FUNC(sub_824E32C8);
PPC_FUNC_IMPL(__imp__sub_824E32C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x824E32D0;
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r27,r24
	r27.u64 = r24.u64;
	// lwz r26,20(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// lwz r25,24(r28)
	r25.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x824e34d4
	if (cr6.lt) goto loc_824E34D4;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// blt cr6,0x824e34d4
	if (cr6.lt) goto loc_824E34D4;
	// add r11,r25,r26
	r11.u64 = r25.u64 + r26.u64;
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// bgt cr6,0x824e34d4
	if (cr6.gt) goto loc_824E34D4;
	// li r22,-1
	r22.s64 = -1;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x824e33d0
	if (cr6.eq) goto loc_824E33D0;
	// addi r31,r28,28
	r31.s64 = r28.s64 + 28;
	// ble cr6,0x824e3350
	if (!cr6.gt) goto loc_824E3350;
	// mr r30,r24
	r30.u64 = r24.u64;
	// mr r29,r26
	r29.u64 = r26.u64;
loc_824E3324:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821f8730
	ctx.lr = 0x824E332C;
	sub_821F8730(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// stwx r3,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, ctx.r3.u32);
	// stwx r11,r30,r9
	PPC_STORE_U32(r30.u32 + ctx.r9.u32, r11.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x824e3324
	if (!cr0.eq) goto loc_824E3324;
loc_824E3350:
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E3364:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e3364
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E3364;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3384;
	sub_8244EE40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e34d4
	if (cr6.eq) goto loc_824E34D4;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lwz r3,768(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 768);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8274b758
	ctx.lr = 0x824E33AC;
	sub_8274B758(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e33c8
	if (!cr6.eq) goto loc_824E33C8;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82135db8
	ctx.lr = 0x824E33C0;
	sub_82135DB8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82450030
	ctx.lr = 0x824E33C8;
	sub_82450030(ctx, base);
loc_824E33C8:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e34c4
	if (!cr6.eq) goto loc_824E34C4;
loc_824E33D0:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x824e34c0
	if (cr6.eq) goto loc_824E34C0;
	// lwz r31,284(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 284);
	// ble cr6,0x824e3418
	if (!cr6.gt) goto loc_824E3418;
	// addi r11,r1,400
	r11.s64 = ctx.r1.s64 + 400;
	// addi r29,r1,144
	r29.s64 = ctx.r1.s64 + 144;
	// subf r28,r31,r11
	r28.s64 = r11.s64 - r31.s64;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824E33F0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824e7110
	ctx.lr = 0x824E33F8;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x824E33FC;
	sub_824F92F0(ctx, base);
	// stdx r3,r28,r31
	PPC_STORE_U64(r28.u32 + r31.u32, ctx.r3.u64);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x824e33f0
	if (!cr0.eq) goto loc_824E33F0;
loc_824E3418:
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// stw r24,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r24.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E342C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e342c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E342C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x824e3460
	if (!cr6.eq) goto loc_824E3460;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3454;
	sub_8244EE40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e34d4
	if (cr6.eq) goto loc_824E34D4;
loc_824E3460:
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r27.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lwz r3,768(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 768);
	// addi r5,r1,400
	ctx.r5.s64 = ctx.r1.s64 + 400;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x8274b800
	ctx.lr = 0x824E347C;
	sub_8274B800(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e3498
	if (!cr6.eq) goto loc_824E3498;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x82135db8
	ctx.lr = 0x824E3490;
	sub_82135DB8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82450030
	ctx.lr = 0x824E3498;
	sub_82450030(ctx, base);
loc_824E3498:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e34c0
	if (cr6.eq) goto loc_824E34C0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x824e34c4
	if (cr6.eq) goto loc_824E34C4;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,768(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 768);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8274b8a8
	ctx.lr = 0x824E34BC;
	sub_8274B8A8(ctx, base);
	// b 0x824e34c4
	goto loc_824E34C4;
loc_824E34C0:
	// li r24,1
	r24.s64 = 1;
loc_824E34C4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e34d4
	if (cr6.eq) goto loc_824E34D4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E34D4;
	sub_8244EEE0(ctx, base);
loc_824E34D4:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E34E0"))) PPC_WEAK_FUNC(sub_824E34E0);
PPC_FUNC_IMPL(__imp__sub_824E34E0) {
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
	ctx.lr = 0x824E34E8;
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,20(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r26,0
	r26.s64 = 0;
	// lwz r27,24(r4)
	r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r30,1056(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1056);
	// li r24,-1
	r24.s64 = -1;
	// addi r11,r4,32
	r11.s64 = ctx.r4.s64 + 32;
	// mr r28,r26
	r28.u64 = r26.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x824e35b0
	if (cr6.eq) goto loc_824E35B0;
	// ble cr6,0x824e353c
	if (!cr6.gt) goto loc_824E353C;
	// addi r10,r11,24
	ctx.r10.s64 = r11.s64 + 24;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_824E3524:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x824e3524
	if (!cr0.eq) goto loc_824E3524;
loc_824E353C:
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r26.u32);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E3550:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e3550
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E3550;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3570;
	sub_8244EE40(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e3680
	if (cr6.eq) goto loc_824E3680;
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r28.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,768(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 768);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8274b8a8
	ctx.lr = 0x824E3594;
	sub_8274B8A8(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e35b0
	if (!cr6.eq) goto loc_824E35B0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x82135db8
	ctx.lr = 0x824E35A8;
	sub_82135DB8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82450030
	ctx.lr = 0x824E35B0;
	sub_82450030(ctx, base);
loc_824E35B0:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x824e3660
	if (cr6.eq) goto loc_824E3660;
	// ble cr6,0x824e35e4
	if (!cr6.gt) goto loc_824E35E4;
	// addi r29,r1,272
	r29.s64 = ctx.r1.s64 + 272;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824E35C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824E35D0;
	sub_824F92F0(ctx, base);
	// std r3,0(r29)
	PPC_STORE_U64(r29.u32 + 0, ctx.r3.u64);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bne 0x824e35c8
	if (!cr0.eq) goto loc_824E35C8;
loc_824E35E4:
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E35F8:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e35f8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E35F8;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x824e362c
	if (!cr6.eq) goto loc_824E362C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3620;
	sub_8244EE40(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e3680
	if (cr6.eq) goto loc_824E3680;
loc_824E362C:
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// lwz r3,768(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 768);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8274b950
	ctx.lr = 0x824E3644;
	sub_8274B950(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e3660
	if (!cr6.eq) goto loc_824E3660;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82135db8
	ctx.lr = 0x824E3658;
	sub_82135DB8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82450030
	ctx.lr = 0x824E3660;
	sub_82450030(ctx, base);
loc_824E3660:
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e3674
	if (cr6.eq) goto loc_824E3674;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E3674;
	sub_8244EEE0(ctx, base);
loc_824E3674:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// b 0x823d9238
	return;
loc_824E3680:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824E368C"))) PPC_WEAK_FUNC(sub_824E368C);
PPC_FUNC_IMPL(__imp__sub_824E368C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E3690"))) PPC_WEAK_FUNC(sub_824E3690);
PPC_FUNC_IMPL(__imp__sub_824E3690) {
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
	ctx.lr = 0x824E3698;
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	r26.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// li r10,6
	ctx.r10.s64 = 6;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E36BC:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e36bc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E36BC;
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmplwi cr6,r11,32
	cr6.compare<uint32_t>(r11.u32, 32, xer);
	// bgt cr6,0x824e37d4
	if (cr6.gt) goto loc_824E37D4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e37d4
	if (cr6.eq) goto loc_824E37D4;
	// mr r29,r26
	r29.u64 = r26.u64;
	// addi r30,r1,384
	r30.s64 = ctx.r1.s64 + 384;
	// addi r31,r28,24
	r31.s64 = r28.s64 + 24;
loc_824E36E8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824E36F0;
	sub_824F92F0(ctx, base);
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// std r3,0(r30)
	PPC_STORE_U64(r30.u32 + 0, ctx.r3.u64);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824e36e8
	if (cr6.lt) goto loc_824E36E8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3720;
	sub_8244EE40(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e37d4
	if (cr6.eq) goto loc_824E37D4;
	// addi r9,r28,536
	ctx.r9.s64 = r28.s64 + 536;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,127
	ctx.r10.s64 = 127;
loc_824E373C:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e3760
	if (cr6.eq) goto loc_824E3760;
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r8,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r8.u16);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bgt 0x824e373c
	if (cr0.gt) goto loc_824E373C;
loc_824E3760:
	// sth r26,0(r11)
	PPC_STORE_U16(r11.u32 + 0, r26.u16);
	// addi r4,r27,2100
	ctx.r4.s64 = r27.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E3770;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E3778;
	sub_821C9030(ctx, base);
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// addi r29,r1,128
	r29.s64 = ctx.r1.s64 + 128;
	// addi r27,r1,384
	r27.s64 = ctx.r1.s64 + 384;
	// lwz r28,20(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// bl 0x821f8730
	ctx.lr = 0x824E3790;
	sub_821F8730(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// bl 0x8244aaf0
	ctx.lr = 0x824E37A4;
	sub_8244AAF0(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e37c0
	if (!cr6.eq) goto loc_824E37C0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82135db8
	ctx.lr = 0x824E37B8;
	sub_82135DB8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82450030
	ctx.lr = 0x824E37C0;
	sub_82450030(ctx, base);
loc_824E37C0:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e37cc
	if (!cr6.eq) goto loc_824E37CC;
	// li r26,1
	r26.s64 = 1;
loc_824E37CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E37D4;
	sub_8244EEE0(ctx, base);
loc_824E37D4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E37E0"))) PPC_WEAK_FUNC(sub_824E37E0);
PPC_FUNC_IMPL(__imp__sub_824E37E0) {
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
	ctx.lr = 0x824E37E8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r31,2100
	r30.s64 = r31.s64 + 2100;
	// li r24,0
	r24.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r23,r24
	r23.u64 = r24.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E380C;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E3814;
	sub_821C9030(ctx, base);
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// addi r29,r26,24
	r29.s64 = r26.s64 + 24;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x824E3824;
	sub_82130000(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9950
	ctx.lr = 0x824E3830;
	sub_824F9950(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E3840;
	sub_821C8FE0(ctx, base);
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824e3858
	if (cr6.eq) goto loc_824E3858;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// mr r27,r24
	r27.u64 = r24.u64;
	// bne cr6,0x824e385c
	if (!cr6.eq) goto loc_824E385C;
loc_824E3858:
	// li r27,1
	r27.s64 = 1;
loc_824E385C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E3864;
	sub_821C9030(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e39e8
	if (cr6.eq) goto loc_824E39E8;
	// ld r11,112(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 112);
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// addi r27,r31,112
	r27.s64 = r31.s64 + 112;
	// bl 0x8244a5e0
	ctx.lr = 0x824E3894;
	sub_8244A5E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E38A0;
	sub_821C8FE0(ctx, base);
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r22,r8,27,31,31
	r22.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E38B8;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824e3974
	if (cr6.eq) goto loc_824E3974;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e38f0
	if (cr6.eq) goto loc_824E38F0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E38D8;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E38E0;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821f8730
	ctx.lr = 0x824E38E8;
	sub_821F8730(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x824e38f4
	goto loc_824E38F4;
loc_824E38F0:
	// li r30,254
	r30.s64 = 254;
loc_824E38F4:
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E3908:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e3908
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E3908;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3928;
	sub_8244EE40(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e39fc
	if (cr6.eq) goto loc_824E39FC;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,768(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 768);
	// addi r5,r26,72
	ctx.r5.s64 = r26.s64 + 72;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8274bff0
	ctx.lr = 0x824E394C;
	sub_8274BFF0(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e3968
	if (!cr6.eq) goto loc_824E3968;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82135db8
	ctx.lr = 0x824E3960;
	sub_82135DB8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82450030
	ctx.lr = 0x824E3968;
	sub_82450030(ctx, base);
loc_824E3968:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e39ec
	if (!cr6.eq) goto loc_824E39EC;
	// b 0x824e39c8
	goto loc_824E39C8;
loc_824E3974:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1050
	ctx.lr = 0x824E397C;
	sub_824E1050(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e39c8
	if (cr6.eq) goto loc_824E39C8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E3994;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E399C;
	sub_821C9030(ctx, base);
	// addi r3,r26,72
	ctx.r3.s64 = r26.s64 + 72;
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x824E39AC;
	sub_823DA950(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x824E39B4;
	sub_82130000(ctx, base);
	// addi r11,r26,80
	r11.s64 = r26.s64 + 80;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823da950
	ctx.lr = 0x824E39C8;
	sub_823DA950(ctx, base);
loc_824E39C8:
	// ld r11,72(r26)
	r11.u64 = PPC_LOAD_U64(r26.u32 + 72);
	// li r7,9
	ctx.r7.s64 = 9;
	// li r6,16384
	ctx.r6.s64 = 16384;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x8244a5e0
	ctx.lr = 0x824E39E8;
	sub_8244A5E0(ctx, base);
loc_824E39E8:
	// li r23,1
	r23.s64 = 1;
loc_824E39EC:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824e39fc
	if (cr6.eq) goto loc_824E39FC;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E39FC;
	sub_8244EEE0(ctx, base);
loc_824E39FC:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E3A08"))) PPC_WEAK_FUNC(sub_824E3A08);
PPC_FUNC_IMPL(__imp__sub_824E3A08) {
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
	ctx.lr = 0x824E3A10;
	// stwu r1,-944(r1)
	ea = -944 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// mr r28,r30
	r28.u64 = r30.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824E3A28;
	sub_824E71C8(ctx, base);
	// addi r3,r1,232
	ctx.r3.s64 = ctx.r1.s64 + 232;
	// bl 0x824e6400
	ctx.lr = 0x824E3A30;
	sub_824E6400(ctx, base);
	// addi r3,r1,292
	ctx.r3.s64 = ctx.r1.s64 + 292;
	// bl 0x82501b00
	ctx.lr = 0x824E3A38;
	sub_82501B00(ctx, base);
	// addi r3,r1,328
	ctx.r3.s64 = ctx.r1.s64 + 328;
	// bl 0x824e1c10
	ctx.lr = 0x824E3A40;
	sub_824E1C10(ctx, base);
	// stw r30,888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 888, r30.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e0b08
	ctx.lr = 0x824E3A4C;
	sub_824E0B08(ctx, base);
	// addi r31,r29,2100
	r31.s64 = r29.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E3A5C;
	sub_821C8FE0(ctx, base);
	// addi r4,r29,8
	ctx.r4.s64 = r29.s64 + 8;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e2d40
	ctx.lr = 0x824E3A68;
	sub_824E2D40(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E3A70;
	sub_821C9030(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E3A7C;
	sub_821C8FE0(ctx, base);
	// lwz r11,736(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 736);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r30,r11
	ctx.r10.s64 = r11.s64 - r30.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r31,r9,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E3A94;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824e3b48
	if (!cr6.eq) goto loc_824E3B48;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E3AAC:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e3aac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E3AAC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3ACC;
	sub_8244EE40(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e3b5c
	if (cr6.eq) goto loc_824E3B5C;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x824e70f0
	ctx.lr = 0x824E3AE4;
	sub_824E70F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e11c0
	ctx.lr = 0x824E3AF0;
	sub_824E11C0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// lwz r6,864(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 864);
	// lwz r5,860(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 860);
	// lwz r4,856(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 856);
	// lwz r3,328(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	// bl 0x824e1398
	ctx.lr = 0x824E3B0C;
	sub_824E1398(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,336(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r5,332(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// lwz r3,888(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 888);
	// bl 0x8274b5f0
	ctx.lr = 0x824E3B24;
	sub_8274B5F0(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e3b40
	if (!cr6.eq) goto loc_824E3B40;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82135db8
	ctx.lr = 0x824E3B38;
	sub_82135DB8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82450030
	ctx.lr = 0x824E3B40;
	sub_82450030(ctx, base);
loc_824E3B40:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e3b4c
	if (!cr6.eq) goto loc_824E3B4C;
loc_824E3B48:
	// li r28,1
	r28.s64 = 1;
loc_824E3B4C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e3b5c
	if (cr6.eq) goto loc_824E3B5C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E3B5C;
	sub_8244EEE0(ctx, base);
loc_824E3B5C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E3B68"))) PPC_WEAK_FUNC(sub_824E3B68);
PPC_FUNC_IMPL(__imp__sub_824E3B68) {
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
	ctx.lr = 0x824E3B70;
	// stwu r1,-944(r1)
	ea = -944 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// mr r28,r30
	r28.u64 = r30.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824E3B98:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e3b98
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E3B98;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E3BB8;
	sub_8244EE40(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e3cb4
	if (cr6.eq) goto loc_824E3CB4;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x824e71c8
	ctx.lr = 0x824E3BD0;
	sub_824E71C8(ctx, base);
	// addi r3,r1,232
	ctx.r3.s64 = ctx.r1.s64 + 232;
	// bl 0x824e6400
	ctx.lr = 0x824E3BD8;
	sub_824E6400(ctx, base);
	// addi r3,r1,292
	ctx.r3.s64 = ctx.r1.s64 + 292;
	// bl 0x82501b00
	ctx.lr = 0x824E3BE0;
	sub_82501B00(ctx, base);
	// addi r3,r1,328
	ctx.r3.s64 = ctx.r1.s64 + 328;
	// bl 0x824e1c10
	ctx.lr = 0x824E3BE8;
	sub_824E1C10(ctx, base);
	// stw r30,888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 888, r30.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e0b08
	ctx.lr = 0x824E3BF4;
	sub_824E0B08(ctx, base);
	// addi r30,r31,2100
	r30.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E3C04;
	sub_821C8FE0(ctx, base);
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e2d40
	ctx.lr = 0x824E3C10;
	sub_824E2D40(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E3C18;
	sub_821C9030(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E3C24;
	sub_821C8FE0(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r31,r31,172
	r31.s64 = r31.s64 + 172;
	// bl 0x82130000
	ctx.lr = 0x824E3C30;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x824E3C34;
	sub_82130000(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82501a88
	ctx.lr = 0x824E3C3C;
	sub_82501A88(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E3C48;
	sub_821C9030(ctx, base);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x824e70f0
	ctx.lr = 0x824E3C50;
	sub_824E70F0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r6,864(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 864);
	// lwz r5,860(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 860);
	// lwz r4,856(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 856);
	// lwz r3,328(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	// bl 0x824e1398
	ctx.lr = 0x824E3C6C;
	sub_824E1398(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,24(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r5,20(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r3,888(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 888);
	// bl 0x8274b5f0
	ctx.lr = 0x824E3C84;
	sub_8274B5F0(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e3ca0
	if (!cr6.eq) goto loc_824E3CA0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82135db8
	ctx.lr = 0x824E3C98;
	sub_82135DB8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82450030
	ctx.lr = 0x824E3CA0;
	sub_82450030(ctx, base);
loc_824E3CA0:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e3cac
	if (!cr6.eq) goto loc_824E3CAC;
	// li r28,1
	r28.s64 = 1;
loc_824E3CAC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244eee0
	ctx.lr = 0x824E3CB4;
	sub_8244EEE0(ctx, base);
loc_824E3CB4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E3CC0"))) PPC_WEAK_FUNC(sub_824E3CC0);
PPC_FUNC_IMPL(__imp__sub_824E3CC0) {
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
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E3CE8;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1778
	ctx.lr = 0x824E3CF4;
	sub_824E1778(ctx, base);
	// addi r11,r3,25
	r11.s64 = ctx.r3.s64 + 25;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x824e3d18
	if (!cr6.eq) goto loc_824E3D18;
	// lwz r11,1804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1804);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,1804(r31)
	PPC_STORE_U32(r31.u32 + 1804, r11.u32);
	// b 0x824e3d24
	goto loc_824E3D24;
loc_824E3D18:
	// lwz r11,1808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, r11.u32);
loc_824E3D24:
	// lwz r11,1800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// rlwinm r10,r3,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// add r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 + r31.u64;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r11,1800(r31)
	PPC_STORE_U32(r31.u32 + 1800, r11.u32);
	// addi r11,r9,776
	r11.s64 = ctx.r9.s64 + 776;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// addi r10,r11,776
	ctx.r10.s64 = r11.s64 + 776;
	// ld r8,776(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 776);
	// std r8,776(r9)
	PPC_STORE_U64(ctx.r9.u32 + 776, ctx.r8.u64);
	// ld r7,784(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 784);
	// std r7,784(r9)
	PPC_STORE_U64(ctx.r9.u32 + 784, ctx.r7.u64);
	// ld r6,792(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 792);
	// std r6,792(r9)
	PPC_STORE_U64(ctx.r9.u32 + 792, ctx.r6.u64);
	// ld r5,800(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 800);
	// std r5,800(r9)
	PPC_STORE_U64(ctx.r9.u32 + 800, ctx.r5.u64);
	// lwz r4,1800(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// addi r30,r31,776
	r30.s64 = r31.s64 + 776;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E3D80;
	sub_824F0498(ctx, base);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x824f9230
	ctx.lr = 0x824E3D88;
	sub_824F9230(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,800(r31)
	PPC_STORE_U32(r31.u32 + 800, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E3D98;
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

__attribute__((alias("__imp__sub_824E3DB0"))) PPC_WEAK_FUNC(sub_824E3DB0);
PPC_FUNC_IMPL(__imp__sub_824E3DB0) {
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
	// li r5,20
	ctx.r5.s64 = 20;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82257568
	ctx.lr = 0x824E3DD4;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e3e14
	if (cr6.eq) goto loc_824E3E14;
	// lis r11,8
	r11.s64 = 524288;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ori r9,r11,44613
	ctx.r9.u64 = r11.u64 | 44613;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x824e3e14
	if (!cr6.eq) goto loc_824E3E14;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618c90
	ctx.lr = 0x824E3E04;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e3e18
	if (!cr6.eq) goto loc_824E3E18;
loc_824E3E14:
	// li r11,0
	r11.s64 = 0;
loc_824E3E18:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E3E34"))) PPC_WEAK_FUNC(sub_824E3E34);
PPC_FUNC_IMPL(__imp__sub_824E3E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E3E38"))) PPC_WEAK_FUNC(sub_824E3E38);
PPC_FUNC_IMPL(__imp__sub_824E3E38) {
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
	ctx.lr = 0x824E3E40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x824E3E5C;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e3e94
	if (cr6.eq) goto loc_824E3E94;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,20
	ctx.r5.s64 = 20;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E3E84;
	sub_82618390(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x824E3E90;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_824E3E94:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e3ed4
	if (cr6.eq) goto loc_824E3ED4;
	// lis r11,8
	r11.s64 = 524288;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// ori r9,r11,44613
	ctx.r9.u64 = r11.u64 | 44613;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x824e3ed4
	if (!cr6.eq) goto loc_824E3ED4;
	// li r5,64
	ctx.r5.s64 = 64;
	// ld r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U64(r28.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618d38
	ctx.lr = 0x824E3EC4;
	sub_82618D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e3ed8
	if (!cr6.eq) goto loc_824E3ED8;
loc_824E3ED4:
	// li r11,0
	r11.s64 = 0;
loc_824E3ED8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E3EE4"))) PPC_WEAK_FUNC(sub_824E3EE4);
PPC_FUNC_IMPL(__imp__sub_824E3EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E3EE8"))) PPC_WEAK_FUNC(sub_824E3EE8);
PPC_FUNC_IMPL(__imp__sub_824E3EE8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x824E3EF0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// lwz r11,324(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// li r29,0
	r29.s64 = 0;
	// addi r9,r10,25812
	ctx.r9.s64 = ctx.r10.s64 + 25812;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r21,r8
	r21.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e3f38
	if (!cr6.eq) goto loc_824E3F38;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_824E3F38:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
	// addi r9,r10,25976
	ctx.r9.s64 = ctx.r10.s64 + 25976;
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x824e71c8
	ctx.lr = 0x824E3F5C;
	sub_824E71C8(ctx, base);
	// addi r3,r30,104
	ctx.r3.s64 = r30.s64 + 104;
	// bl 0x824e6400
	ctx.lr = 0x824E3F64;
	sub_824E6400(ctx, base);
	// addi r3,r30,164
	ctx.r3.s64 = r30.s64 + 164;
	// bl 0x82501b00
	ctx.lr = 0x824E3F6C;
	sub_82501B00(ctx, base);
	// addi r3,r30,200
	ctx.r3.s64 = r30.s64 + 200;
	// bl 0x824e1c10
	ctx.lr = 0x824E3F74;
	sub_824E1C10(ctx, base);
	// stw r29,784(r31)
	PPC_STORE_U32(r31.u32 + 784, r29.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E3F80;
	sub_824E0B08(ctx, base);
	// lwz r8,308(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r7,316(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// rlwinm r6,r28,0,29,29
	ctx.r6.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x4;
	// mr r26,r29
	r26.u64 = r29.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r8,792(r31)
	PPC_STORE_U32(r31.u32 + 792, ctx.r8.u32);
	// stw r7,796(r31)
	PPC_STORE_U32(r31.u32 + 796, ctx.r7.u32);
	// bne cr6,0x824e3fb8
	if (!cr6.eq) goto loc_824E3FB8;
	// rlwinm r11,r28,0,30,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e3fb8
	if (!cr6.eq) goto loc_824E3FB8;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x824e3fb8
	if (cr6.eq) goto loc_824E3FB8;
	// li r26,1
	r26.s64 = 1;
loc_824E3FB8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// rlwinm r28,r28,0,30,28
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// bl 0x82130000
	ctx.lr = 0x824E3FC4;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x824E3FC8;
	sub_82130000(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// std r29,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r29.u64);
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// std r29,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r29.u64);
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// bl 0x824e0b90
	ctx.lr = 0x824E4000;
	sub_824E0B90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824E400C"))) PPC_WEAK_FUNC(sub_824E400C);
PPC_FUNC_IMPL(__imp__sub_824E400C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4010"))) PPC_WEAK_FUNC(sub_824E4010);
PPC_FUNC_IMPL(__imp__sub_824E4010) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e3ee8
	ctx.lr = 0x824E4050;
	sub_824E3EE8(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,25984
	ctx.r10.s64 = r11.s64 + 25984;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_824E4074"))) PPC_WEAK_FUNC(sub_824E4074);
PPC_FUNC_IMPL(__imp__sub_824E4074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4078"))) PPC_WEAK_FUNC(sub_824E4078);
PPC_FUNC_IMPL(__imp__sub_824E4078) {
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
	ctx.lr = 0x824E4080;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r8,r10,25812
	ctx.r8.s64 = ctx.r10.s64 + 25812;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bne cr6,0x824e40ac
	if (!cr6.eq) goto loc_824E40AC;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_824E40AC:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r29,0
	r29.s64 = 0;
	// addi r9,r10,25992
	ctx.r9.s64 = ctx.r10.s64 + 25992;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x824e71c8
	ctx.lr = 0x824E40D4;
	sub_824E71C8(ctx, base);
	// addi r3,r30,104
	ctx.r3.s64 = r30.s64 + 104;
	// bl 0x824e6400
	ctx.lr = 0x824E40DC;
	sub_824E6400(ctx, base);
	// addi r3,r30,164
	ctx.r3.s64 = r30.s64 + 164;
	// bl 0x82501b00
	ctx.lr = 0x824E40E4;
	sub_82501B00(ctx, base);
	// addi r3,r30,200
	ctx.r3.s64 = r30.s64 + 200;
	// bl 0x824e1c10
	ctx.lr = 0x824E40EC;
	sub_824E1C10(ctx, base);
	// stw r29,784(r31)
	PPC_STORE_U32(r31.u32 + 784, r29.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E40F8;
	sub_824E0B08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E4104"))) PPC_WEAK_FUNC(sub_824E4104);
PPC_FUNC_IMPL(__imp__sub_824E4104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4108"))) PPC_WEAK_FUNC(sub_824E4108);
PPC_FUNC_IMPL(__imp__sub_824E4108) {
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
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r8,r10,25812
	ctx.r8.s64 = ctx.r10.s64 + 25812;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bne cr6,0x824e4140
	if (!cr6.eq) goto loc_824E4140;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
loc_824E4140:
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r9,26000
	ctx.r8.s64 = ctx.r9.s64 + 26000;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x824e1b78
	ctx.lr = 0x824E4164;
	sub_824E1B78(ctx, base);
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

__attribute__((alias("__imp__sub_824E417C"))) PPC_WEAK_FUNC(sub_824E417C);
PPC_FUNC_IMPL(__imp__sub_824E417C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4180"))) PPC_WEAK_FUNC(sub_824E4180);
PPC_FUNC_IMPL(__imp__sub_824E4180) {
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
	ctx.lr = 0x824E4188;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r30,r31,2100
	r30.s64 = r31.s64 + 2100;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E41BC;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r28,0
	r28.s64 = 0;
	// bl 0x821c8fe0
	ctx.lr = 0x824E41CC;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r20,r9,27,31,31
	r20.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E41E8;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x824e4294
	if (cr6.eq) goto loc_824E4294;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c8fe0
	ctx.lr = 0x824E41FC;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1972);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E4218;
	sub_821C9030(ctx, base);
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e4294
	if (!cr6.eq) goto loc_824E4294;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E422C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e4294
	if (cr6.eq) goto loc_824E4294;
	// cmpwi cr6,r26,1
	cr6.compare<int32_t>(r26.s32, 1, xer);
	// bne cr6,0x824e4258
	if (!cr6.eq) goto loc_824E4258;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821f8730
	ctx.lr = 0x824E4248;
	sub_821F8730(ctx, base);
	// bl 0x824e6d68
	ctx.lr = 0x824E424C;
	sub_824E6D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e4294
	if (cr6.eq) goto loc_824E4294;
loc_824E4258:
	// stw r28,2096(r31)
	PPC_STORE_U32(r31.u32 + 2096, r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E4264;
	sub_824E0B08(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,800
	ctx.r4.s64 = 800;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824E4288;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e42c8
	if (!cr6.eq) goto loc_824E42C8;
loc_824E4294:
	// lwz r31,340(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e4314
	if (cr6.eq) goto loc_824E4314;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E42AC;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E42BC;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9228
	return;
loc_824E42C8:
	// lwz r3,332(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// lwz r11,340(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// lwz r29,324(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bl 0x824e3ee8
	ctx.lr = 0x824E4304;
	sub_824E3EE8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E4310;
	sub_824E1338(ctx, base);
	// li r28,1
	r28.s64 = 1;
loc_824E4314:
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x821c9030
	ctx.lr = 0x824E431C;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824E4328"))) PPC_WEAK_FUNC(sub_824E4328);
PPC_FUNC_IMPL(__imp__sub_824E4328) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x824E4330;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r28,r31,2100
	r28.s64 = r31.s64 + 2100;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4350;
	sub_821C8FE0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// li r25,0
	r25.s64 = 0;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4360;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1972);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// subf r10,r25,r11
	ctx.r10.s64 = r11.s64 - r25.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E437C;
	sub_821C9030(ctx, base);
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e44f8
	if (!cr6.eq) goto loc_824E44F8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4394;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x824e43ac
	if (cr6.lt) goto loc_824E43AC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r30,1
	r30.s64 = 1;
	// ble cr6,0x824e43b0
	if (!cr6.gt) goto loc_824E43B0;
loc_824E43AC:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824E43B0:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c9030
	ctx.lr = 0x824E43B8;
	sub_821C9030(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e44f8
	if (cr6.eq) goto loc_824E44F8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c8fe0
	ctx.lr = 0x824E43D0;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e43e8
	if (cr6.lt) goto loc_824E43E8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r30,1
	r30.s64 = 1;
	// ble cr6,0x824e43ec
	if (!cr6.gt) goto loc_824E43EC;
loc_824E43E8:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824E43EC:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c9030
	ctx.lr = 0x824E43F4;
	sub_821C9030(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e44f8
	if (!cr6.eq) goto loc_824E44F8;
	// lwz r11,736(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// lwz r10,528(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 528);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x824e44f8
	if (!cr6.eq) goto loc_824E44F8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x824e44f8
	if (!cr6.eq) goto loc_824E44F8;
	// lis r27,-32115
	r27.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,792
	ctx.r4.s64 = 792;
	// lwz r3,32268(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E4444;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e44f8
	if (cr6.eq) goto loc_824E44F8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x824e4078
	ctx.lr = 0x824E4458;
	sub_824E4078(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4464;
	sub_821C8FE0(ctx, base);
	// ld r11,552(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 552);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addi r10,r29,12
	ctx.r10.s64 = r29.s64 + 12;
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r6,r31,172
	ctx.r6.s64 = r31.s64 + 172;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r31,112
	ctx.r5.s64 = r31.s64 + 112;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// ld r28,544(r29)
	r28.u64 = PPC_LOAD_U64(r29.u32 + 544);
	// lwz r24,536(r29)
	r24.u64 = PPC_LOAD_U32(r29.u32 + 536);
	// lwz r23,532(r29)
	r23.u64 = PPC_LOAD_U32(r29.u32 + 532);
	// lwz r29,528(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 528);
	// std r28,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r28.u64);
	// stw r24,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r24.u32);
	// stw r23,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r23.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// bl 0x824e0b90
	ctx.lr = 0x824E44B0;
	sub_824E0B90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e4528
	if (!cr6.eq) goto loc_824E4528;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c9030
	ctx.lr = 0x824E44C4;
	sub_821C9030(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,32268(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 32268);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E44E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E44F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E44F8:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e4548
	if (cr6.eq) goto loc_824E4548;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E450C;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E451C;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
loc_824E4528:
	// lwz r11,768(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 768);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,784(r30)
	PPC_STORE_U32(r30.u32 + 784, r11.u32);
	// bl 0x824e1338
	ctx.lr = 0x824E453C;
	sub_824E1338(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// li r25,1
	r25.s64 = 1;
	// bl 0x821c9030
	ctx.lr = 0x824E4548;
	sub_821C9030(ctx, base);
loc_824E4548:
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x821c9030
	ctx.lr = 0x824E4550;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824E455C"))) PPC_WEAK_FUNC(sub_824E455C);
PPC_FUNC_IMPL(__imp__sub_824E455C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4560"))) PPC_WEAK_FUNC(sub_824E4560);
PPC_FUNC_IMPL(__imp__sub_824E4560) {
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
	ctx.lr = 0x824E4568;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r31,2100
	r30.s64 = r31.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4594;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r28,0
	r28.s64 = 0;
	// bl 0x821c8fe0
	ctx.lr = 0x824E45A4;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r22,r9,27,31,31
	r22.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E45C0;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824e4638
	if (cr6.eq) goto loc_824E4638;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E45D4;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r28,r11
	ctx.r10.s64 = r11.s64 - r28.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E45F0;
	sub_821C9030(ctx, base);
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e4638
	if (!cr6.eq) goto loc_824E4638;
	// stw r28,2096(r31)
	PPC_STORE_U32(r31.u32 + 2096, r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E4608;
	sub_824E0B08(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,800
	ctx.r4.s64 = 800;
	// lwz r3,32268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824E462C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e4668
	if (!cr6.eq) goto loc_824E4668;
loc_824E4638:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e4694
	if (cr6.eq) goto loc_824E4694;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E464C;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E465C;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_824E4668:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e4010
	ctx.lr = 0x824E4684;
	sub_824E4010(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E4690;
	sub_824E1338(ctx, base);
	// li r28,1
	r28.s64 = 1;
loc_824E4694:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E469C;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E46A8"))) PPC_WEAK_FUNC(sub_824E46A8);
PPC_FUNC_IMPL(__imp__sub_824E46A8) {
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
	ctx.lr = 0x824E46B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r29,r31,2100
	r29.s64 = r31.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E46CC;
	sub_821C8FE0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r25,r30
	r25.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E46E0;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x824e46fc
	if (cr6.lt) goto loc_824E46FC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r27,1
	r27.s64 = 1;
	// ble cr6,0x824e4700
	if (!cr6.gt) goto loc_824E4700;
loc_824E46FC:
	// mr r27,r30
	r27.u64 = r30.u64;
loc_824E4700:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E4708;
	sub_821C9030(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// lis r27,-32115
	r27.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e4788
	if (cr6.eq) goto loc_824E4788;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4724;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r30,r11
	ctx.r10.s64 = r11.s64 - r30.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r29,r8,1
	r29.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E4740;
	sub_821C9030(ctx, base);
	// clrlwi r7,r29,24
	ctx.r7.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e4788
	if (!cr6.eq) goto loc_824E4788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e18d8
	ctx.lr = 0x824E4754;
	sub_824E18D8(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,32268(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 32268);
	// li r4,792
	ctx.r4.s64 = 792;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824E477C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e47f4
	if (!cr6.eq) goto loc_824E47F4;
loc_824E4788:
	// lwz r31,32268(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 32268);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e47c4
	if (cr6.eq) goto loc_824E47C4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E47AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E47C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E47C4:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e4814
	if (cr6.eq) goto loc_824E4814;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E47D8;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E47E8;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_824E47F4:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e4108
	ctx.lr = 0x824E4804;
	sub_824E4108(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E4810;
	sub_824E1338(ctx, base);
	// li r25,1
	r25.s64 = 1;
loc_824E4814:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E481C;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824E4828"))) PPC_WEAK_FUNC(sub_824E4828);
PPC_FUNC_IMPL(__imp__sub_824E4828) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x824E4830;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r19,r27,2100
	r19.s64 = r27.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r18,r7
	r18.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4858;
	sub_821C8FE0(ctx, base);
	// li r15,0
	r15.s64 = 0;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r15
	r31.u64 = r15.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E486C;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// li r16,1
	r16.s64 = 1;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e4888
	if (cr6.lt) goto loc_824E4888;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// mr r30,r16
	r30.u64 = r16.u64;
	// ble cr6,0x824e488c
	if (!cr6.gt) goto loc_824E488C;
loc_824E4888:
	// mr r30,r15
	r30.u64 = r15.u64;
loc_824E488C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E4894;
	sub_821C9030(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lis r17,-32115
	r17.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e4a88
	if (cr6.eq) goto loc_824E4A88;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E48B0;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r15,r11
	ctx.r10.s64 = r11.s64 - r15.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E48CC;
	sub_821C9030(ctx, base);
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e4a88
	if (!cr6.eq) goto loc_824E4A88;
	// cmplwi cr6,r24,32
	cr6.compare<uint32_t>(r24.u32, 32, xer);
	// bgt cr6,0x824e4a88
	if (cr6.gt) goto loc_824E4A88;
	// lwz r3,32268(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + 32268);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,288
	ctx.r4.s64 = 288;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E4900;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e4a88
	if (cr6.eq) goto loc_824E4A88;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x824e08b0
	ctx.lr = 0x824E4914;
	sub_824E08B0(ctx, base);
	// rlwinm r11,r24,3,0,28
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r21,r15
	r21.u64 = r15.u64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r26,r15
	r26.u64 = r15.u64;
	// addi r11,r11,28
	r11.s64 = r11.s64 + 28;
	// mr r20,r15
	r20.u64 = r15.u64;
	// stw r11,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r11.u32);
	// mr r23,r15
	r23.u64 = r15.u64;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x824e4a24
	if (!cr6.gt) goto loc_824E4A24;
	// addi r25,r31,28
	r25.s64 = r31.s64 + 28;
	// subf r22,r28,r29
	r22.s64 = r29.s64 - r28.s64;
loc_824E4944:
	// lwzx r30,r22,r28
	r30.u64 = PPC_LOAD_U32(r22.u32 + r28.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7008
	ctx.lr = 0x824E4950;
	sub_824E7008(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82502300
	ctx.lr = 0x824E495C;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e1778
	ctx.lr = 0x824E4968;
	sub_824E1778(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x824e4a14
	if (!cr6.lt) goto loc_824E4A14;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e49e0
	if (cr6.eq) goto loc_824E49E0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E4984;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e4a88
	if (cr6.eq) goto loc_824E4A88;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e10a0
	ctx.lr = 0x824E4998;
	sub_824E10A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e49d0
	if (cr6.eq) goto loc_824E49D0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e1050
	ctx.lr = 0x824E49AC;
	sub_824E1050(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e49d0
	if (!cr6.eq) goto loc_824E49D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f8730
	ctx.lr = 0x824E49C0;
	sub_821F8730(ctx, base);
	// bl 0x824e6d68
	ctx.lr = 0x824E49C4;
	sub_824E6D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e4a88
	if (cr6.eq) goto loc_824E4A88;
loc_824E49D0:
	// mr r11,r25
	r11.u64 = r25.u64;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// b 0x824e49f0
	goto loc_824E49F0;
loc_824E49E0:
	// lwz r11,284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// stw r11,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r11.u32);
loc_824E49F0:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// subf r9,r16,r10
	ctx.r9.s64 = ctx.r10.s64 - r16.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r7,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r7.u8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824e4a14
	if (cr6.eq) goto loc_824E4A14;
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
loc_824E4A14:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r23,r24
	cr6.compare<int32_t>(r23.s32, r24.s32, xer);
	// blt cr6,0x824e4944
	if (cr6.lt) goto loc_824E4944;
loc_824E4A24:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4A30;
	sub_821C8FE0(ctx, base);
	// lwz r11,212(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 212);
	// lwz r10,1804(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 1804);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r30,r10,r11
	r30.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x821c9030
	ctx.lr = 0x824E4A44;
	sub_821C9030(ctx, base);
	// subf r9,r20,r24
	ctx.r9.s64 = r24.s64 - r20.s64;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// blt cr6,0x824e4a88
	if (cr6.lt) goto loc_824E4A88;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4A5C;
	sub_821C8FE0(ctx, base);
	// lwz r11,216(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 216);
	// lwz r10,1808(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 1808);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r30,r10,r11
	r30.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x821c9030
	ctx.lr = 0x824E4A70;
	sub_821C9030(ctx, base);
	// cmplw cr6,r30,r20
	cr6.compare<uint32_t>(r30.u32, r20.u32, xer);
	// blt cr6,0x824e4a88
	if (cr6.lt) goto loc_824E4A88;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x824e4af4
	if (!cr6.eq) goto loc_824E4AF4;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x824e4af4
	if (!cr6.eq) goto loc_824E4AF4;
loc_824E4A88:
	// lwz r30,32268(r17)
	r30.u64 = PPC_LOAD_U32(r17.u32 + 32268);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e4ac4
	if (cr6.eq) goto loc_824E4AC4;
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
	ctx.lr = 0x824E4AAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E4AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E4AC4:
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x824e4b0c
	if (cr6.eq) goto loc_824E4B0C;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E4AD8;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,4(r18)
	PPC_STORE_U32(r18.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E4AE8;
	sub_821C9030(ctx, base);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9214
	return;
loc_824E4AF4:
	// stw r21,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r21.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E4B08;
	sub_824E1338(ctx, base);
	// mr r15,r16
	r15.u64 = r16.u64;
loc_824E4B0C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E4B14;
	sub_821C9030(ctx, base);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_824E4B20"))) PPC_WEAK_FUNC(sub_824E4B20);
PPC_FUNC_IMPL(__imp__sub_824E4B20) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x824E4B28;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r29,r31,2100
	r29.s64 = r31.s64 + 2100;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4B48;
	sub_821C8FE0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r24,r30
	r24.u64 = r30.u64;
	// clrlwi r25,r26,24
	r25.u64 = r26.u32 & 0xFF;
	// bl 0x824e2608
	ctx.lr = 0x824E4B5C;
	sub_824E2608(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bne cr6,0x824e4bac
	if (!cr6.eq) goto loc_824E4BAC;
	// li r24,1
	r24.s64 = 1;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e4d08
	if (cr6.eq) goto loc_824E4D08;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E4B80;
	sub_821CE080(ctx, base);
	// stw r30,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824E4B94;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E4BA0;
	sub_821C9030(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
loc_824E4BAC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4BB8;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x824e4bd0
	if (cr6.lt) goto loc_824E4BD0;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r28,1
	r28.s64 = 1;
	// ble cr6,0x824e4bd4
	if (!cr6.gt) goto loc_824E4BD4;
loc_824E4BD0:
	// mr r28,r30
	r28.u64 = r30.u64;
loc_824E4BD4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E4BDC;
	sub_821C9030(ctx, base);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// lis r28,-32115
	r28.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e4c88
	if (cr6.eq) goto loc_824E4C88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4BF8;
	sub_821C8FE0(ctx, base);
	// lwz r11,1972(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1972);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r30,r11
	ctx.r10.s64 = r11.s64 - r30.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r23,r8,1
	r23.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821c9030
	ctx.lr = 0x824E4C14;
	sub_821C9030(ctx, base);
	// clrlwi r7,r23,24
	ctx.r7.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e4c88
	if (!cr6.eq) goto loc_824E4C88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4C2C;
	sub_821C8FE0(ctx, base);
	// lwz r11,736(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r10,r30,r11
	ctx.r10.s64 = r11.s64 - r30.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r29,r9,27,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E4C44;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x824e4c88
	if (!cr6.eq) goto loc_824E4C88;
	// lwz r11,740(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 740);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e4c88
	if (!cr6.eq) goto loc_824E4C88;
	// lwz r3,32268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32268);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,24
	ctx.r4.s64 = 24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E4C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e4cc4
	if (!cr6.eq) goto loc_824E4CC4;
loc_824E4C88:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,32268(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 32268);
	// bl 0x824e1948
	ctx.lr = 0x824E4C94;
	sub_824E1948(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e4d08
	if (cr6.eq) goto loc_824E4D08;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E4CA8;
	sub_821CE080(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E4CB8;
	sub_821C9030(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
loc_824E4CC4:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e0a08
	ctx.lr = 0x824E4CD0;
	sub_824E0A08(ctx, base);
	// stb r26,20(r30)
	PPC_STORE_U8(r30.u32 + 20, r26.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e2608
	ctx.lr = 0x824E4CDC;
	sub_824E2608(ctx, base);
	// stb r3,21(r30)
	PPC_STORE_U8(r30.u32 + 21, ctx.r3.u8);
	// lwz r11,744(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// bne cr6,0x824e4cf4
	if (!cr6.eq) goto loc_824E4CF4;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_824E4CF4:
	// stw r10,744(r31)
	PPC_STORE_U32(r31.u32 + 744, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1338
	ctx.lr = 0x824E4D04;
	sub_824E1338(ctx, base);
	// li r24,1
	r24.s64 = 1;
loc_824E4D08:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824E4D10;
	sub_821C9030(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824E4D1C"))) PPC_WEAK_FUNC(sub_824E4D1C);
PPC_FUNC_IMPL(__imp__sub_824E4D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4D20"))) PPC_WEAK_FUNC(sub_824E4D20);
PPC_FUNC_IMPL(__imp__sub_824E4D20) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4D44;
	sub_821C8FE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e18d8
	ctx.lr = 0x824E4D4C;
	sub_824E18D8(ctx, base);
	// lwz r11,1800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e4d74
	if (!cr6.gt) goto loc_824E4D74;
	// addi r30,r31,776
	r30.s64 = r31.s64 + 776;
loc_824E4D5C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e3cc0
	ctx.lr = 0x824E4D68;
	sub_824E3CC0(ctx, base);
	// lwz r11,1800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bgt cr6,0x824e4d5c
	if (cr6.gt) goto loc_824E4D5C;
loc_824E4D74:
	// lwz r3,768(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 768);
	// li r30,0
	r30.s64 = 0;
	// stw r30,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,1804(r31)
	PPC_STORE_U32(r31.u32 + 1804, r30.u32);
	// beq cr6,0x824e4da0
	if (cr6.eq) goto loc_824E4DA0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8274b6a8
	ctx.lr = 0x824E4D94;
	sub_8274B6A8(ctx, base);
	// lwz r3,768(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 768);
	// bl 0x8275cc90
	ctx.lr = 0x824E4D9C;
	sub_8275CC90(ctx, base);
	// stw r30,768(r31)
	PPC_STORE_U32(r31.u32 + 768, r30.u32);
loc_824E4DA0:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e0b08
	ctx.lr = 0x824E4DA8;
	sub_824E0B08(ctx, base);
	// stw r30,1812(r31)
	PPC_STORE_U32(r31.u32 + 1812, r30.u32);
	// stw r30,1968(r31)
	PPC_STORE_U32(r31.u32 + 1968, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r30,2096(r31)
	PPC_STORE_U32(r31.u32 + 2096, r30.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E4DBC;
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

__attribute__((alias("__imp__sub_824E4DD4"))) PPC_WEAK_FUNC(sub_824E4DD4);
PPC_FUNC_IMPL(__imp__sub_824E4DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4DD8"))) PPC_WEAK_FUNC(sub_824E4DD8);
PPC_FUNC_IMPL(__imp__sub_824E4DD8) {
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
	ctx.lr = 0x824E4DE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,2100
	r29.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4E00;
	sub_821C8FE0(ctx, base);
	// addi r27,r31,8
	r27.s64 = r31.s64 + 8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E4E0C;
	sub_824E0B08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E4E14;
	sub_821C9030(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e2f80
	ctx.lr = 0x824E4E20;
	sub_824E2F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e4e40
	if (!cr6.eq) goto loc_824E4E40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E4E34;
	sub_824E4D20(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824E4E40:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4E4C;
	sub_821C8FE0(ctx, base);
	// addi r4,r30,24
	ctx.r4.s64 = r30.s64 + 24;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E4E5C;
	sub_823DA950(ctx, base);
	// addi r4,r30,120
	ctx.r4.s64 = r30.s64 + 120;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E4E6C;
	sub_823DA950(ctx, base);
	// lwz r8,180(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// addi r11,r30,204
	r11.s64 = r30.s64 + 204;
	// addi r10,r31,172
	ctx.r10.s64 = r31.s64 + 172;
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r8,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r8.u32);
	// lwz r7,184(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// stw r7,736(r31)
	PPC_STORE_U32(r31.u32 + 736, ctx.r7.u32);
	// lwz r6,188(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// stw r6,740(r31)
	PPC_STORE_U32(r31.u32 + 740, ctx.r6.u32);
	// lwz r5,192(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// stw r5,744(r31)
	PPC_STORE_U32(r31.u32 + 744, ctx.r5.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E4E9C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824e4e9c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E4E9C;
	// li r11,1
	r11.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// stw r10,1812(r31)
	PPC_STORE_U32(r31.u32 + 1812, ctx.r10.u32);
	// lwz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// stw r9,1968(r31)
	PPC_STORE_U32(r31.u32 + 1968, ctx.r9.u32);
	// lwz r8,240(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 240);
	// stw r8,768(r31)
	PPC_STORE_U32(r31.u32 + 768, ctx.r8.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E4ED8;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E4EE4"))) PPC_WEAK_FUNC(sub_824E4EE4);
PPC_FUNC_IMPL(__imp__sub_824E4EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4EE8"))) PPC_WEAK_FUNC(sub_824E4EE8);
PPC_FUNC_IMPL(__imp__sub_824E4EE8) {
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
	ctx.lr = 0x824E4EF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r30,236
	ctx.r3.s64 = r30.s64 + 236;
	// li r29,0
	r29.s64 = 0;
	// bl 0x824e8f88
	ctx.lr = 0x824E4F08;
	sub_824E8F88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e4f2c
	if (!cr6.eq) goto loc_824E4F2C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e3098
	ctx.lr = 0x824E4F20;
	sub_824E3098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e4f40
	if (!cr6.eq) goto loc_824E4F40;
loc_824E4F2C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E4F34;
	sub_824E4D20(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824E4F40:
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4F4C;
	sub_821C8FE0(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r4,r30,24
	ctx.r4.s64 = r30.s64 + 24;
	// bl 0x824e2d40
	ctx.lr = 0x824E4F58;
	sub_824E2D40(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E4F68;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E4F74"))) PPC_WEAK_FUNC(sub_824E4F74);
PPC_FUNC_IMPL(__imp__sub_824E4F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4F78"))) PPC_WEAK_FUNC(sub_824E4F78);
PPC_FUNC_IMPL(__imp__sub_824E4F78) {
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
	// bl 0x824e31e0
	ctx.lr = 0x824E4F98;
	sub_824E31E0(ctx, base);
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E4FA4;
	sub_821C8FE0(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r4,r30,24
	ctx.r4.s64 = r30.s64 + 24;
	// bl 0x824e2d40
	ctx.lr = 0x824E4FB0;
	sub_824E2D40(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E4FB8;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E4FC0;
	sub_824E4D20(ctx, base);
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

__attribute__((alias("__imp__sub_824E4FDC"))) PPC_WEAK_FUNC(sub_824E4FDC);
PPC_FUNC_IMPL(__imp__sub_824E4FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E4FE0"))) PPC_WEAK_FUNC(sub_824E4FE0);
PPC_FUNC_IMPL(__imp__sub_824E4FE0) {
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
	ctx.lr = 0x824E4FE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e506c
	if (!cr6.gt) goto loc_824E506C;
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
loc_824E500C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82502300
	ctx.lr = 0x824E5014;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1778
	ctx.lr = 0x824E5020;
	sub_824E1778(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824e5058
	if (cr6.lt) goto loc_824E5058;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// addi r30,r30,-8
	r30.s64 = r30.s64 + -8;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
loc_824E5058:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824e500c
	if (cr6.lt) goto loc_824E500C;
loc_824E506C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e50ec
	if (!cr6.gt) goto loc_824E50EC;
	// li r30,0
	r30.s64 = 0;
loc_824E5080:
	// lwz r11,284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82502300
	ctx.lr = 0x824E508C;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1778
	ctx.lr = 0x824E5098;
	sub_824E1778(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824e50d8
	if (cr6.lt) goto loc_824E50D8;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// lwz r11,284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r30,r30,-8
	r30.s64 = r30.s64 + -8;
	// lwz r8,-8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stw r7,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
loc_824E50D8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824e5080
	if (cr6.lt) goto loc_824E5080;
loc_824E50EC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e32c8
	ctx.lr = 0x824E50F8;
	sub_824E32C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e51a0
	if (cr6.eq) goto loc_824E51A0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e5148
	if (!cr6.gt) goto loc_824E5148;
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
loc_824E5118:
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x824e1678
	ctx.lr = 0x824E5134;
	sub_824E1678(ctx, base);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// blt cr6,0x824e5118
	if (cr6.lt) goto loc_824E5118;
loc_824E5148:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e5194
	if (!cr6.gt) goto loc_824E5194;
	// li r30,0
	r30.s64 = 0;
loc_824E515C:
	// lwz r11,284(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x824e1678
	ctx.lr = 0x824E5180;
	sub_824E1678(ctx, base);
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r7
	cr6.compare<uint32_t>(r29.u32, ctx.r7.u32, xer);
	// blt cr6,0x824e515c
	if (cr6.lt) goto loc_824E515C;
loc_824E5194:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824E51A0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E51AC"))) PPC_WEAK_FUNC(sub_824E51AC);
PPC_FUNC_IMPL(__imp__sub_824E51AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E51B0"))) PPC_WEAK_FUNC(sub_824E51B0);
PPC_FUNC_IMPL(__imp__sub_824E51B0) {
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
	ctx.lr = 0x824E51B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e5240
	if (!cr6.gt) goto loc_824E5240;
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
loc_824E51D8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e1778
	ctx.lr = 0x824E51E4;
	sub_824E1778(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x824e522c
	if (!cr6.lt) goto loc_824E522C;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// ldx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + r31.u32);
	// std r9,0(r30)
	PPC_STORE_U64(r30.u32 + 0, ctx.r9.u64);
	// ld r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// std r8,8(r30)
	PPC_STORE_U64(r30.u32 + 8, ctx.r8.u64);
	// ld r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 16);
	// std r7,16(r30)
	PPC_STORE_U64(r30.u32 + 16, ctx.r7.u64);
	// ld r6,24(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 24);
	// std r6,24(r30)
	PPC_STORE_U64(r30.u32 + 24, ctx.r6.u64);
	// addi r30,r30,-32
	r30.s64 = r30.s64 + -32;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// stw r5,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r5.u32);
loc_824E522C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824e51d8
	if (cr6.lt) goto loc_824E51D8;
loc_824E5240:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e52cc
	if (!cr6.gt) goto loc_824E52CC;
	// li r30,0
	r30.s64 = 0;
loc_824E5254:
	// lwz r11,1056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824e1778
	ctx.lr = 0x824E5264;
	sub_824E1778(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x824e52b8
	if (!cr6.lt) goto loc_824E52B8;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// lwz r11,1056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r30,r11
	ctx.r9.u64 = r30.u64 + r11.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r30,r30,-32
	r30.s64 = r30.s64 + -32;
	// addi r8,r11,-32
	ctx.r8.s64 = r11.s64 + -32;
	// ld r7,-32(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + -32);
	// std r7,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r7.u64);
	// ld r6,-24(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + -24);
	// std r6,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r6.u64);
	// ld r5,-16(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + -16);
	// std r5,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r5.u64);
	// ld r4,-8(r11)
	ctx.r4.u64 = PPC_LOAD_U64(r11.u32 + -8);
	// std r4,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r4.u64);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
loc_824E52B8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824e5254
	if (cr6.lt) goto loc_824E5254;
loc_824E52CC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e5300
	if (!cr6.gt) goto loc_824E5300;
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
loc_824E52E0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e3cc0
	ctx.lr = 0x824E52EC;
	sub_824E3CC0(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824e52e0
	if (cr6.lt) goto loc_824E52E0;
loc_824E5300:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824e5338
	if (!cr6.gt) goto loc_824E5338;
	// li r30,0
	r30.s64 = 0;
loc_824E5314:
	// lwz r11,1056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824e3cc0
	ctx.lr = 0x824E5324;
	sub_824E3CC0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x824e5314
	if (cr6.lt) goto loc_824E5314;
loc_824E5338:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e34e0
	ctx.lr = 0x824E5344;
	sub_824E34E0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E5350"))) PPC_WEAK_FUNC(sub_824E5350);
PPC_FUNC_IMPL(__imp__sub_824E5350) {
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
	ctx.lr = 0x824E5358;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x824e37e0
	ctx.lr = 0x824E536C;
	sub_824E37E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5430
	if (cr6.eq) goto loc_824E5430;
	// addi r29,r31,2100
	r29.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5388;
	sub_821C8FE0(ctx, base);
	// addi r4,r30,72
	ctx.r4.s64 = r30.s64 + 72;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E5398;
	sub_823DA950(ctx, base);
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// bl 0x82130000
	ctx.lr = 0x824E53A0;
	sub_82130000(ctx, base);
	// addi r30,r31,172
	r30.s64 = r31.s64 + 172;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,9
	ctx.r9.s64 = 9;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E53B4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824e53b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E53B4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E53D0;
	sub_821C9030(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E53DC;
	sub_821C8FE0(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x824E53E4;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x824E53E8;
	sub_82130000(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82501a88
	ctx.lr = 0x824E53F0;
	sub_82501A88(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E53FC;
	sub_821C9030(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5424
	if (cr6.eq) goto loc_824E5424;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1050
	ctx.lr = 0x824E5410;
	sub_824E1050(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5424
	if (cr6.eq) goto loc_824E5424;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1808
	ctx.lr = 0x824E5424;
	sub_824E1808(ctx, base);
loc_824E5424:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824E5430:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E543C"))) PPC_WEAK_FUNC(sub_824E543C);
PPC_FUNC_IMPL(__imp__sub_824E543C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5440"))) PPC_WEAK_FUNC(sub_824E5440);
PPC_FUNC_IMPL(__imp__sub_824E5440) {
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
	ctx.lr = 0x824E5448;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824e3a08
	ctx.lr = 0x824E5458;
	sub_824E3A08(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5498
	if (!cr6.eq) goto loc_824E5498;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5474;
	sub_821C8FE0(ctx, base);
	// lbz r11,21(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 21);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,744(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// bne cr6,0x824e548c
	if (!cr6.eq) goto loc_824E548C;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_824E548C:
	// stw r10,744(r31)
	PPC_STORE_U32(r31.u32 + 744, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E5498;
	sub_821C9030(ctx, base);
loc_824E5498:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E54A4"))) PPC_WEAK_FUNC(sub_824E54A4);
PPC_FUNC_IMPL(__imp__sub_824E54A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E54A8"))) PPC_WEAK_FUNC(sub_824E54A8);
PPC_FUNC_IMPL(__imp__sub_824E54A8) {
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
	ctx.lr = 0x824E54B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824e3b68
	ctx.lr = 0x824E54C0;
	sub_824E3B68(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E54D0;
	sub_821C8FE0(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e55ec
	if (cr6.eq) goto loc_824E55EC;
	// lwz r11,1804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1804);
	// lwz r10,212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x824e5564
	if (!cr6.lt) goto loc_824E5564;
	// lwz r11,1800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824e5548
	if (!cr6.gt) goto loc_824E5548;
	// addi r11,r31,800
	r11.s64 = r31.s64 + 800;
	// li r7,1
	ctx.r7.s64 = 1;
loc_824E5508:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x824e5534
	if (!cr6.eq) goto loc_824E5534;
	// lwz r10,212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// ble cr6,0x824e5534
	if (!cr6.gt) goto loc_824E5534;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r10,1808(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, ctx.r10.u32);
loc_824E5534:
	// lwz r10,1800(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x824e5508
	if (cr6.lt) goto loc_824E5508;
loc_824E5548:
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,1804(r31)
	PPC_STORE_U32(r31.u32 + 1804, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E5558;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824E5564:
	// lwz r11,1808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x824e55fc
	if (!cr6.lt) goto loc_824E55FC;
	// lwz r11,1800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824e55d0
	if (!cr6.gt) goto loc_824E55D0;
	// addi r11,r31,800
	r11.s64 = r31.s64 + 800;
loc_824E558C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x824e55bc
	if (!cr6.eq) goto loc_824E55BC;
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// ble cr6,0x824e55bc
	if (!cr6.gt) goto loc_824E55BC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r10,1804(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1804);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,1804(r31)
	PPC_STORE_U32(r31.u32 + 1804, ctx.r7.u32);
loc_824E55BC:
	// lwz r10,1800(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1800);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x824e558c
	if (cr6.lt) goto loc_824E558C;
loc_824E55D0:
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E55E0;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824E55EC:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// stw r10,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r10.u32);
loc_824E55FC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E5604;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E5610"))) PPC_WEAK_FUNC(sub_824E5610);
PPC_FUNC_IMPL(__imp__sub_824E5610) {
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
	ctx.lr = 0x824E5618;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x824e3db0
	ctx.lr = 0x824E5628;
	sub_824E3DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5684
	if (cr6.eq) goto loc_824E5684;
	// addi r29,r30,20
	r29.s64 = r30.s64 + 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82618f10
	ctx.lr = 0x824E5644;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5684
	if (cr6.eq) goto loc_824E5684;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e566c
	if (cr6.eq) goto loc_824E566C;
	// addi r4,r30,21
	ctx.r4.s64 = r30.s64 + 21;
	// bl 0x824fa458
	ctx.lr = 0x824E5668;
	sub_824FA458(ctx, base);
	// b 0x824e5674
	goto loc_824E5674;
loc_824E566C:
	// addi r4,r30,534
	ctx.r4.s64 = r30.s64 + 534;
	// bl 0x824fa548
	ctx.lr = 0x824E5674;
	sub_824FA548(ctx, base);
loc_824E5674:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e5688
	if (!cr6.eq) goto loc_824E5688;
loc_824E5684:
	// li r11,0
	r11.s64 = 0;
loc_824E5688:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E5694"))) PPC_WEAK_FUNC(sub_824E5694);
PPC_FUNC_IMPL(__imp__sub_824E5694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5698"))) PPC_WEAK_FUNC(sub_824E5698);
PPC_FUNC_IMPL(__imp__sub_824E5698) {
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
	// bl 0x824e3e38
	ctx.lr = 0x824E56B8;
	sub_824E3E38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e56e0
	if (cr6.eq) goto loc_824E56E0;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa558
	ctx.lr = 0x824E56D0;
	sub_824FA558(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e56e4
	if (!cr6.eq) goto loc_824E56E4;
loc_824E56E0:
	// li r11,0
	r11.s64 = 0;
loc_824E56E4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E5700"))) PPC_WEAK_FUNC(sub_824E5700);
PPC_FUNC_IMPL(__imp__sub_824E5700) {
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
	ctx.lr = 0x824E5708;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82257678
	ctx.lr = 0x824E5738;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824E5744;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824E5754;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e5784
	if (cr6.eq) goto loc_824E5784;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824e5784
	if (!cr6.eq) goto loc_824E5784;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e5610
	ctx.lr = 0x824E5774;
	sub_824E5610(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5788
	if (!cr6.eq) goto loc_824E5788;
loc_824E5784:
	// li r31,0
	r31.s64 = 0;
loc_824E5788:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e57b4
	if (cr6.eq) goto loc_824E57B4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e57ac
	if (cr6.eq) goto loc_824E57AC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E57A4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824e57b0
	goto loc_824E57B0;
loc_824E57AC:
	// li r11,0
	r11.s64 = 0;
loc_824E57B0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824E57B4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e57d8
	if (cr6.eq) goto loc_824E57D8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E57C8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e57dc
	if (cr6.eq) goto loc_824E57DC;
loc_824E57D8:
	// li r11,0
	r11.s64 = 0;
loc_824E57DC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E57E8"))) PPC_WEAK_FUNC(sub_824E57E8);
PPC_FUNC_IMPL(__imp__sub_824E57E8) {
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
	ctx.lr = 0x824E57F0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x822575e8
	ctx.lr = 0x824E5814;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824E5820;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824E5830;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e5854
	if (cr6.eq) goto loc_824E5854;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e5698
	ctx.lr = 0x824E5844;
	sub_824E5698(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5858
	if (!cr6.eq) goto loc_824E5858;
loc_824E5854:
	// li r30,0
	r30.s64 = 0;
loc_824E5858:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e5890
	if (cr6.eq) goto loc_824E5890;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5888
	if (cr6.eq) goto loc_824E5888;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824E5874;
	sub_826186A0(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_824E5888:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824E5890:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E589C"))) PPC_WEAK_FUNC(sub_824E589C);
PPC_FUNC_IMPL(__imp__sub_824E589C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E58A0"))) PPC_WEAK_FUNC(sub_824E58A0);
PPC_FUNC_IMPL(__imp__sub_824E58A0) {
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
	ctx.lr = 0x824E58A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// addi r10,r11,26008
	ctx.r10.s64 = r11.s64 + 26008;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e71c8
	ctx.lr = 0x824E58C8;
	sub_824E71C8(ctx, base);
	// addi r3,r30,104
	ctx.r3.s64 = r30.s64 + 104;
	// bl 0x824e6400
	ctx.lr = 0x824E58D0;
	sub_824E6400(ctx, base);
	// addi r3,r30,164
	ctx.r3.s64 = r30.s64 + 164;
	// bl 0x82501b00
	ctx.lr = 0x824E58D8;
	sub_82501B00(ctx, base);
	// addi r3,r30,200
	ctx.r3.s64 = r30.s64 + 200;
	// bl 0x824e1c10
	ctx.lr = 0x824E58E0;
	sub_824E1C10(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,768(r31)
	PPC_STORE_U32(r31.u32 + 768, r28.u32);
	// bl 0x824e0b08
	ctx.lr = 0x824E58F0;
	sub_824E0B08(ctx, base);
	// addi r29,r31,776
	r29.s64 = r31.s64 + 776;
	// li r27,31
	r27.s64 = 31;
	// addi r30,r29,8
	r30.s64 = r29.s64 + 8;
	// li r26,-1
	r26.s64 = -1;
loc_824E5900:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E5908;
	sub_824F0498(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9438
	ctx.lr = 0x824E5910;
	sub_824F9438(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E5918;
	sub_824F0498(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9230
	ctx.lr = 0x824E5920;
	sub_824F9230(ctx, base);
	// stw r26,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r26.u32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,32
	r29.s64 = r29.s64 + 32;
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// bge 0x824e5900
	if (!cr0.lt) goto loc_824E5900;
	// stw r28,1800(r31)
	PPC_STORE_U32(r31.u32 + 1800, r28.u32);
	// addi r3,r31,1816
	ctx.r3.s64 = r31.s64 + 1816;
	// stw r28,1804(r31)
	PPC_STORE_U32(r31.u32 + 1804, r28.u32);
	// stw r28,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, r28.u32);
	// stw r28,1812(r31)
	PPC_STORE_U32(r31.u32 + 1812, r28.u32);
	// bl 0x824f9150
	ctx.lr = 0x824E594C;
	sub_824F9150(ctx, base);
	// stw r28,1968(r31)
	PPC_STORE_U32(r31.u32 + 1968, r28.u32);
	// stw r28,1972(r31)
	PPC_STORE_U32(r31.u32 + 1972, r28.u32);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// bl 0x824e6928
	ctx.lr = 0x824E595C;
	sub_824E6928(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r28,2028(r31)
	PPC_STORE_U32(r31.u32 + 2028, r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,25868
	r30.s64 = r11.s64 + 25868;
	// stw r30,1976(r31)
	PPC_STORE_U32(r31.u32 + 1976, r30.u32);
	// bl 0x821c9060
	ctx.lr = 0x824E5974;
	sub_821C9060(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,2032(r31)
	PPC_STORE_U32(r31.u32 + 2032, ctx.r3.u32);
	// addi r3,r31,2036
	ctx.r3.s64 = r31.s64 + 2036;
	// addi r9,r10,25888
	ctx.r9.s64 = ctx.r10.s64 + 25888;
	// stw r9,1976(r31)
	PPC_STORE_U32(r31.u32 + 1976, ctx.r9.u32);
	// bl 0x824e6928
	ctx.lr = 0x824E598C;
	sub_824E6928(ctx, base);
	// stw r30,2036(r31)
	PPC_STORE_U32(r31.u32 + 2036, r30.u32);
	// stw r28,2088(r31)
	PPC_STORE_U32(r31.u32 + 2088, r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x824E599C;
	sub_821C9060(ctx, base);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// stw r3,2092(r31)
	PPC_STORE_U32(r31.u32 + 2092, ctx.r3.u32);
	// addi r3,r31,2100
	ctx.r3.s64 = r31.s64 + 2100;
	// addi r7,r8,25908
	ctx.r7.s64 = ctx.r8.s64 + 25908;
	// stw r7,2036(r31)
	PPC_STORE_U32(r31.u32 + 2036, ctx.r7.u32);
	// stw r28,2096(r31)
	PPC_STORE_U32(r31.u32 + 2096, r28.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824E59B8;
	sub_821C8ED8(ctx, base);
	// lbz r6,2132(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r5,r6,25
	ctx.r5.u64 = ctx.r6.u32 & 0x7F;
	// stb r5,2132(r31)
	PPC_STORE_U8(r31.u32 + 2132, ctx.r5.u8);
	// bl 0x824e4d20
	ctx.lr = 0x824E59CC;
	sub_824E4D20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E59D8"))) PPC_WEAK_FUNC(sub_824E59D8);
PPC_FUNC_IMPL(__imp__sub_824E59D8) {
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
	ctx.lr = 0x824E59E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r11,2132(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e5a54
	if (!cr6.eq) goto loc_824E5A54;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E5A08;
	sub_824E4D20(ctx, base);
	// stw r31,2028(r31)
	PPC_STORE_U32(r31.u32 + 2028, r31.u32);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,1976
	r30.s64 = r31.s64 + 1976;
	// lis r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,26012
	ctx.r4.s64 = r11.s64 + 26012;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b98
	ctx.lr = 0x824E5A2C;
	sub_824E6B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5a40
	if (!cr6.eq) goto loc_824E5A40;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,52(r30)
	PPC_STORE_U32(r30.u32 + 52, ctx.r10.u32);
loc_824E5A40:
	// lbz r10,2132(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// rlwimi r10,r11,7,0,24
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0xFFFFFF80) | (ctx.r10.u64 & 0xFFFFFFFF0000007F);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r3,r9,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1;
	// stb r9,2132(r31)
	PPC_STORE_U8(r31.u32 + 2132, ctx.r9.u8);
loc_824E5A54:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E5A5C"))) PPC_WEAK_FUNC(sub_824E5A5C);
PPC_FUNC_IMPL(__imp__sub_824E5A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5A60"))) PPC_WEAK_FUNC(sub_824E5A60);
PPC_FUNC_IMPL(__imp__sub_824E5A60) {
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
	// lbz r11,2132(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e5aac
	if (cr6.eq) goto loc_824E5AAC;
	// lwz r11,1976(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1976);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E5A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E5AA0;
	sub_824E4D20(ctx, base);
	// lbz r9,2132(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,2132(r31)
	PPC_STORE_U8(r31.u32 + 2132, ctx.r8.u8);
loc_824E5AAC:
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

__attribute__((alias("__imp__sub_824E5AC0"))) PPC_WEAK_FUNC(sub_824E5AC0);
PPC_FUNC_IMPL(__imp__sub_824E5AC0) {
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
	ctx.lr = 0x824E5AC8;
	// stwu r1,-944(r1)
	ea = -944 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r28,r31,2100
	r28.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5AE8;
	sub_821C8FE0(ctx, base);
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0b08
	ctx.lr = 0x824E5AF4;
	sub_824E0B08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E5AFC;
	sub_821C9030(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e2e30
	ctx.lr = 0x824E5B08;
	sub_824E2E30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5bc8
	if (cr6.eq) goto loc_824E5BC8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5B20;
	sub_821C8FE0(ctx, base);
	// addi r4,r30,24
	ctx.r4.s64 = r30.s64 + 24;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e2d40
	ctx.lr = 0x824E5B2C;
	sub_824E2D40(ctx, base);
	// li r27,2
	r27.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// lwz r11,792(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 792);
	// stw r11,1812(r31)
	PPC_STORE_U32(r31.u32 + 1812, r11.u32);
	// lwz r10,796(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 796);
	// stw r10,1968(r31)
	PPC_STORE_U32(r31.u32 + 1968, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x824E5B4C;
	sub_821C9030(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5B58;
	sub_821C8FE0(ctx, base);
	// lwz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r8,r27,r9
	ctx.r8.s64 = ctx.r9.s64 - r27.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r30,r7,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E5B70;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e5bd4
	if (cr6.eq) goto loc_824E5BD4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e1808
	ctx.lr = 0x824E5B80;
	sub_824E1808(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e5bd4
	if (!cr6.eq) goto loc_824E5BD4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r26.u32);
	// addi r9,r11,26000
	ctx.r9.s64 = r11.s64 + 26000;
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x824e1b78
	ctx.lr = 0x824E5BBC;
	sub_824E1B78(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4f78
	ctx.lr = 0x824E5BC8;
	sub_824E4F78(ctx, base);
loc_824E5BC8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9240
	return;
loc_824E5BD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E5BE0"))) PPC_WEAK_FUNC(sub_824E5BE0);
PPC_FUNC_IMPL(__imp__sub_824E5BE0) {
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
	ctx.lr = 0x824E5BE8;
	// stwu r1,-2592(r1)
	ea = -2592 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e6310
	ctx.lr = 0x824E5BF8;
	sub_824E6310(ctx, base);
	// lis r11,8
	r11.s64 = 524288;
	// li r21,0
	r21.s64 = 0;
	// ori r10,r11,44613
	ctx.r10.u64 = r11.u64 | 44613;
	// std r21,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, r21.u64);
	// addi r3,r1,213
	ctx.r3.s64 = ctx.r1.s64 + 213;
	// stw r10,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r10.u32);
	// bl 0x824e8de8
	ctx.lr = 0x824E5C14;
	sub_824E8DE8(ctx, base);
	// addi r3,r1,726
	ctx.r3.s64 = ctx.r1.s64 + 726;
	// bl 0x824e6400
	ctx.lr = 0x824E5C1C;
	sub_824E6400(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r25,-1
	r25.s64 = -1;
	// ori r24,r9,32779
	r24.u64 = ctx.r9.u64 | 32779;
	// addi r23,r11,32300
	r23.s64 = r11.s64 + 32300;
	// addi r20,r10,32332
	r20.s64 = ctx.r10.s64 + 32332;
loc_824E5C38:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// addi r5,r1,1440
	ctx.r5.s64 = ctx.r1.s64 + 1440;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r11,1816
	ctx.r3.s64 = r11.s64 + 1816;
	// bl 0x824f8f38
	ctx.lr = 0x824E5C54;
	sub_824F8F38(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmpwi cr6,r22,2
	cr6.compare<int32_t>(r22.s32, 2, xer);
	// blt cr6,0x824e5eb4
	if (cr6.lt) goto loc_824E5EB4;
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r30,2100
	ctx.r4.s64 = r30.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5C70;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// subf r10,r21,r11
	ctx.r10.s64 = r11.s64 - r21.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E5C88;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e5eb4
	if (!cr6.eq) goto loc_824E5EB4;
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// addi r4,r30,2100
	ctx.r4.s64 = r30.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5CA0;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// lwz r30,208(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// bl 0x821c9030
	ctx.lr = 0x824E5CAC;
	sub_821C9030(ctx, base);
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x824e5eb4
	if (!cr6.eq) goto loc_824E5EB4;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// lwz r4,8(r20)
	ctx.r4.u64 = PPC_LOAD_U32(r20.u32 + 8);
	// addi r6,r22,-2
	ctx.r6.s64 = r22.s64 + -2;
	// addi r5,r1,1442
	ctx.r5.s64 = ctx.r1.s64 + 1442;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x824e5700
	ctx.lr = 0x824E5CCC;
	sub_824E5700(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5eb4
	if (cr6.eq) goto loc_824E5EB4;
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// cmpw cr6,r10,r22
	cr6.compare<int32_t>(ctx.r10.s32, r22.s32, xer);
	// bne cr6,0x824e5eb4
	if (!cr6.eq) goto loc_824E5EB4;
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// addi r4,r30,2100
	ctx.r4.s64 = r30.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5CF8;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x821c9030
	ctx.lr = 0x824E5D00;
	sub_821C9030(ctx, base);
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// stw r25,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r25.u32);
	// addi r30,r30,208
	r30.s64 = r30.s64 + 208;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r29,r30,12
	r29.s64 = r30.s64 + 12;
	// mr r26,r21
	r26.u64 = r21.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E5D20;
	sub_824E9038(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,213
	ctx.r3.s64 = ctx.r1.s64 + 213;
	// bl 0x824e9038
	ctx.lr = 0x824E5D30;
	sub_824E9038(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x824e5d80
	if (cr6.lt) goto loc_824E5D80;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x824e5d80
	if (cr6.lt) goto loc_824E5D80;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9690
	ctx.lr = 0x824E5D58;
	sub_824E9690(ctx, base);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,213
	ctx.r3.s64 = ctx.r1.s64 + 213;
	// bl 0x824e9690
	ctx.lr = 0x824E5D6C;
	sub_824E9690(ctx, base);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r26,r8,27,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_824E5D80:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e5eb4
	if (cr6.eq) goto loc_824E5EB4;
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// bl 0x824e0d78
	ctx.lr = 0x824E5D94;
	sub_824E0D78(ctx, base);
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// lwz r28,52(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r28,2100
	ctx.r4.s64 = r28.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5DA4;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// lwz r26,1808(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + 1808);
	// bl 0x821c9030
	ctx.lr = 0x824E5DB0;
	sub_821C9030(ctx, base);
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// lwz r28,52(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r28,2100
	ctx.r4.s64 = r28.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5DC0;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// lwz r19,1804(r28)
	r19.u64 = PPC_LOAD_U32(r28.u32 + 1804);
	// bl 0x821c9030
	ctx.lr = 0x824E5DCC;
	sub_821C9030(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r28,52(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r28,2100
	ctx.r4.s64 = r28.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5DDC;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c9030
	ctx.lr = 0x824E5DE4;
	sub_821C9030(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r27,52(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r27,2100
	ctx.r4.s64 = r27.s64 + 2100;
	// bl 0x821c8fe0
	ctx.lr = 0x824E5DF4;
	sub_821C8FE0(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821c9030
	ctx.lr = 0x824E5DFC;
	sub_821C9030(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r28,r28,112
	r28.s64 = r28.s64 + 112;
	// addi r3,r11,1816
	ctx.r3.s64 = r11.s64 + 1816;
	// lwz r18,8(r30)
	r18.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824f8900
	ctx.lr = 0x824E5E14;
	sub_824F8900(ctx, base);
	// bl 0x82618670
	ctx.lr = 0x824E5E18;
	sub_82618670(ctx, base);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x824E5E24;
	sub_824E7118(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,816
	ctx.r3.s64 = ctx.r1.s64 + 816;
	// stw r19,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r19.u32);
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// stw r18,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r18.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// bl 0x824fc0b8
	ctx.lr = 0x824E5E54;
	sub_824FC0B8(ctx, base);
	// ld r11,200(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 200);
	// addi r7,r1,124
	ctx.r7.s64 = ctx.r1.s64 + 124;
	// lwz r4,8(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// li r6,1022
	ctx.r6.s64 = 1022;
	// addi r5,r1,1442
	ctx.r5.s64 = ctx.r1.s64 + 1442;
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// std r11,808(r1)
	PPC_STORE_U64(ctx.r1.u32 + 808, r11.u64);
	// bl 0x824e57e8
	ctx.lr = 0x824E5E74;
	sub_824E57E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e5eb4
	if (cr6.eq) goto loc_824E5EB4;
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r29,r1,1440
	r29.s64 = ctx.r1.s64 + 1440;
	// addi r30,r11,2
	r30.s64 = r11.s64 + 2;
	// sth r30,1440(r1)
	PPC_STORE_U16(ctx.r1.u32 + 1440, r30.u16);
	// bl 0x824e6270
	ctx.lr = 0x824E5E98;
	sub_824E6270(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,1816
	ctx.r3.s64 = r11.s64 + 1816;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x824f8ea0
	ctx.lr = 0x824E5EB4;
	sub_824F8EA0(ctx, base);
loc_824E5EB4:
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// bgt cr6,0x824e5c38
	if (cr6.gt) goto loc_824E5C38;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x824E5EC4;
	sub_821C91B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6a10
	ctx.lr = 0x824E5ECC;
	sub_824E6A10(ctx, base);
	// addi r1,r1,2592
	ctx.r1.s64 = ctx.r1.s64 + 2592;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_824E5ED4"))) PPC_WEAK_FUNC(sub_824E5ED4);
PPC_FUNC_IMPL(__imp__sub_824E5ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5ED8"))) PPC_WEAK_FUNC(sub_824E5ED8);
PPC_FUNC_IMPL(__imp__sub_824E5ED8) {
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
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r10,26008
	ctx.r9.s64 = ctx.r10.s64 + 26008;
	// lbz r11,2132(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// rlwinm r8,r11,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e5f30
	if (cr6.eq) goto loc_824E5F30;
	// lwz r11,1976(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1976);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E5F1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4d20
	ctx.lr = 0x824E5F24;
	sub_824E4D20(ctx, base);
	// lbz r9,2132(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 2132);
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stb r8,2132(r31)
	PPC_STORE_U8(r31.u32 + 2132, ctx.r8.u8);
loc_824E5F30:
	// addi r3,r31,2100
	ctx.r3.s64 = r31.s64 + 2100;
	// bl 0x82130000
	ctx.lr = 0x824E5F38;
	sub_82130000(ctx, base);
	// addi r3,r31,2036
	ctx.r3.s64 = r31.s64 + 2036;
	// bl 0x824e6b58
	ctx.lr = 0x824E5F40;
	sub_824E6B58(ctx, base);
	// addi r3,r31,1976
	ctx.r3.s64 = r31.s64 + 1976;
	// bl 0x824e6b58
	ctx.lr = 0x824E5F48;
	sub_824E6B58(ctx, base);
	// addi r3,r31,1816
	ctx.r3.s64 = r31.s64 + 1816;
	// bl 0x824f91e0
	ctx.lr = 0x824E5F50;
	sub_824F91E0(ctx, base);
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

__attribute__((alias("__imp__sub_824E5F64"))) PPC_WEAK_FUNC(sub_824E5F64);
PPC_FUNC_IMPL(__imp__sub_824E5F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E5F68"))) PPC_WEAK_FUNC(sub_824E5F68);
PPC_FUNC_IMPL(__imp__sub_824E5F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824E5F70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lwz r30,1972(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1972);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// bgt cr6,0x824e6088
	if (cr6.gt) goto loc_824E6088;
	// lis r12,-32178
	r12.s64 = -2108817408;
	// addi r12,r12,24488
	r12.s64 = r12.s64 + 24488;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E5FD8;
	case 1:
		goto loc_824E5FD8;
	case 2:
		goto loc_824E5FE8;
	case 3:
		goto loc_824E5FF8;
	case 4:
		goto loc_824E6008;
	case 5:
		goto loc_824E6018;
	case 6:
		goto loc_824E6028;
	case 7:
		goto loc_824E6038;
	case 8:
		goto loc_824E6048;
	case 9:
		goto loc_824E6058;
	case 10:
		goto loc_824E6068;
	case 11:
		goto loc_824E6078;
	default:
		__builtin_unreachable();
	}
	// lwz r18,24536(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24536);
	// lwz r18,24536(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24536);
	// lwz r18,24552(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24552);
	// lwz r18,24568(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24568);
	// lwz r18,24584(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24584);
	// lwz r18,24600(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24600);
	// lwz r18,24616(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24616);
	// lwz r18,24632(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24632);
	// lwz r18,24648(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24648);
	// lwz r18,24664(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24664);
	// lwz r18,24680(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24680);
	// lwz r18,24696(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + 24696);
loc_824E5FD8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e5ac0
	ctx.lr = 0x824E5FE4;
	sub_824E5AC0(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E5FE8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4dd8
	ctx.lr = 0x824E5FF4;
	sub_824E4DD8(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E5FF8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4ee8
	ctx.lr = 0x824E6004;
	sub_824E4EE8(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6008:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4f78
	ctx.lr = 0x824E6014;
	sub_824E4F78(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6018:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e4fe0
	ctx.lr = 0x824E6024;
	sub_824E4FE0(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6028:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e51b0
	ctx.lr = 0x824E6034;
	sub_824E51B0(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6038:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e2dd8
	ctx.lr = 0x824E6044;
	sub_824E2DD8(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6048:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e3690
	ctx.lr = 0x824E6054;
	sub_824E3690(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6058:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e5350
	ctx.lr = 0x824E6064;
	sub_824E5350(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6068:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e5440
	ctx.lr = 0x824E6074;
	sub_824E5440(ctx, base);
	// b 0x824e6084
	goto loc_824E6084;
loc_824E6078:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e54a8
	ctx.lr = 0x824E6084;
	sub_824E54A8(ctx, base);
loc_824E6084:
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_824E6088:
	// addi r4,r31,2100
	ctx.r4.s64 = r31.s64 + 2100;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E6094;
	sub_821C8FE0(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// stw r28,1972(r31)
	PPC_STORE_U32(r31.u32 + 1972, r28.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r31,8(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824e60c0
	if (cr6.eq) goto loc_824E60C0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824E60B8;
	sub_821CE0A0(ctx, base);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// b 0x824e60d0
	goto loc_824E60D0;
loc_824E60C0:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824E60C8;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_824E60D0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,32268(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// bl 0x824e1948
	ctx.lr = 0x824E60E0;
	sub_824E1948(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E60E8;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E60F0"))) PPC_WEAK_FUNC(sub_824E60F0);
PPC_FUNC_IMPL(__imp__sub_824E60F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// b 0x824e5f68
	sub_824E5F68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E60F8"))) PPC_WEAK_FUNC(sub_824E60F8);
PPC_FUNC_IMPL(__imp__sub_824E60F8) {
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
	// bl 0x824e5ed8
	ctx.lr = 0x824E6118;
	sub_824E5ED8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6130
	if (cr6.eq) goto loc_824E6130;
	// bl 0x82130588
	ctx.lr = 0x824E612C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E6130:
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

__attribute__((alias("__imp__sub_824E6148"))) PPC_WEAK_FUNC(sub_824E6148);
PPC_FUNC_IMPL(__imp__sub_824E6148) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,30108
	r31.s64 = r11.s64 + 30108;
	// lbz r11,6(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6188
	if (cr6.eq) goto loc_824E6188;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// bl 0x8244d5c0
	ctx.lr = 0x824E6180;
	sub_8244D5C0(ctx, base);
	// lbz r3,6(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// b 0x824e61d8
	goto loc_824E61D8;
loc_824E6188:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244a670
	ctx.lr = 0x824E6190;
	sub_8244A670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e61b0
	if (!cr6.eq) goto loc_824E61B0;
loc_824E6198:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fec0
	ctx.lr = 0x824E61A0;
	sub_8244FEC0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244a670
	ctx.lr = 0x824E61A8;
	sub_8244A670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e6198
	if (cr6.eq) goto loc_824E6198;
loc_824E61B0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,90
	ctx.r4.s64 = ctx.r1.s64 + 90;
	// bl 0x8244d5c0
	ctx.lr = 0x824E61C0;
	sub_8244D5C0(ctx, base);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,90
	ctx.r4.s64 = ctx.r1.s64 + 90;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824E61D0;
	sub_8244D5C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r3,6(r31)
	PPC_STORE_U8(r31.u32 + 6, ctx.r3.u8);
loc_824E61D8:
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

__attribute__((alias("__imp__sub_824E61F0"))) PPC_WEAK_FUNC(sub_824E61F0);
PPC_FUNC_IMPL(__imp__sub_824E61F0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r30,0
	r30.s64 = 0;
	// bl 0x8244a670
	ctx.lr = 0x824E6214;
	sub_8244A670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6234
	if (!cr6.eq) goto loc_824E6234;
loc_824E621C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fec0
	ctx.lr = 0x824E6224;
	sub_8244FEC0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8244a670
	ctx.lr = 0x824E622C;
	sub_8244A670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e621c
	if (cr6.eq) goto loc_824E621C;
loc_824E6234:
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// rlwinm r11,r11,0,31,16
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFF8001;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e6254
	if (!cr6.eq) goto loc_824E6254;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x824e6258
	goto loc_824E6258;
loc_824E6254:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824E6258:
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

__attribute__((alias("__imp__sub_824E6270"))) PPC_WEAK_FUNC(sub_824E6270);
PPC_FUNC_IMPL(__imp__sub_824E6270) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6278"))) PPC_WEAK_FUNC(sub_824E6278);
PPC_FUNC_IMPL(__imp__sub_824E6278) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6294
	if (cr6.eq) goto loc_824E6294;
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e6298
	if (!cr6.eq) goto loc_824E6298;
loc_824E6294:
	// li r11,0
	r11.s64 = 0;
loc_824E6298:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E62A0"))) PPC_WEAK_FUNC(sub_824E62A0);
PPC_FUNC_IMPL(__imp__sub_824E62A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x824e62d0
	if (cr6.lt) goto loc_824E62D0;
	// bne cr6,0x824e62c4
	if (!cr6.eq) goto loc_824E62C4;
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x824e62d0
	if (cr6.lt) goto loc_824E62D0;
loc_824E62C4:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_824E62D0:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E62DC"))) PPC_WEAK_FUNC(sub_824E62DC);
PPC_FUNC_IMPL(__imp__sub_824E62DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E62E0"))) PPC_WEAK_FUNC(sub_824E62E0);
PPC_FUNC_IMPL(__imp__sub_824E62E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824e6304
	if (!cr6.eq) goto loc_824E6304;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6308
	if (cr6.eq) goto loc_824E6308;
loc_824E6304:
	// li r11,0
	r11.s64 = 0;
loc_824E6308:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6310"))) PPC_WEAK_FUNC(sub_824E6310);
PPC_FUNC_IMPL(__imp__sub_824E6310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6320"))) PPC_WEAK_FUNC(sub_824E6320);
PPC_FUNC_IMPL(__imp__sub_824E6320) {
	PPC_FUNC_PROLOGUE();
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// sth r5,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r5.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E632C"))) PPC_WEAK_FUNC(sub_824E632C);
PPC_FUNC_IMPL(__imp__sub_824E632C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6330"))) PPC_WEAK_FUNC(sub_824E6330);
PPC_FUNC_IMPL(__imp__sub_824E6330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6344"))) PPC_WEAK_FUNC(sub_824E6344);
PPC_FUNC_IMPL(__imp__sub_824E6344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6348"))) PPC_WEAK_FUNC(sub_824E6348);
PPC_FUNC_IMPL(__imp__sub_824E6348) {
	PPC_FUNC_PROLOGUE();
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9890
	sub_823D9890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E6354"))) PPC_WEAK_FUNC(sub_824E6354);
PPC_FUNC_IMPL(__imp__sub_824E6354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6358"))) PPC_WEAK_FUNC(sub_824E6358);
PPC_FUNC_IMPL(__imp__sub_824E6358) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r11,60
	ctx.r9.s64 = r11.s64 + 60;
loc_824E6360:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// subf. r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x824e6380
	if (!cr0.eq) goto loc_824E6380;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x824e6360
	if (!cr6.eq) goto loc_824E6360;
loc_824E6380:
	// addi r11,r10,0
	r11.s64 = ctx.r10.s64 + 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6390"))) PPC_WEAK_FUNC(sub_824E6390);
PPC_FUNC_IMPL(__imp__sub_824E6390) {
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
	ctx.lr = 0x824E6398;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824E63B4;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e63f4
	if (cr6.eq) goto loc_824E63F4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E63DC;
	sub_82618390(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x824E63E8;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E63F4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E6400"))) PPC_WEAK_FUNC(sub_824E6400);
PPC_FUNC_IMPL(__imp__sub_824E6400) {
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
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823d9890
	ctx.lr = 0x824E6420;
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

__attribute__((alias("__imp__sub_824E6438"))) PPC_WEAK_FUNC(sub_824E6438);
PPC_FUNC_IMPL(__imp__sub_824E6438) {
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
	ctx.lr = 0x824E6440;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x824E6460;
	sub_82618750(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824E6470;
	sub_82618640(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r30,0
	r30.s64 = 0;
	// lwz r29,8(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x826186c0
	ctx.lr = 0x824E6484;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e64bc
	if (cr6.eq) goto loc_824E64BC;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618390
	ctx.lr = 0x824E64AC;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E64B8;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_824E64BC:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6678
	if (cr6.eq) goto loc_824E6678;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x824E64D8;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6678
	if (cr6.eq) goto loc_824E6678;
	// li r5,16
	ctx.r5.s64 = 16;
	// lhz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U16(r28.u32 + 16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82275660
	ctx.lr = 0x824E64F4;
	sub_82275660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6678
	if (cr6.eq) goto loc_824E6678;
	// li r31,1
	r31.s64 = 1;
	// li r30,0
	r30.s64 = 0;
loc_824E6508:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6538
	if (cr6.eq) goto loc_824E6538;
	// add r11,r30,r28
	r11.u64 = r30.u64 + r28.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lbz r4,18(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// bl 0x82251078
	ctx.lr = 0x824E6528;
	sub_82251078(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,6
	cr6.compare<uint32_t>(r30.u32, 6, xer);
	// blt cr6,0x824e6508
	if (cr6.lt) goto loc_824E6508;
loc_824E6538:
	// li r29,0
	r29.s64 = 0;
loc_824E653C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e65a4
	if (cr6.eq) goto loc_824E65A4;
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// lbz r30,24(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// bl 0x826186c0
	ctx.lr = 0x824E6560;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e6598
	if (cr6.eq) goto loc_824E6598;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E6588;
	sub_82618390(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E6594;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824E6598:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,20
	cr6.compare<uint32_t>(r29.u32, 20, xer);
	// blt cr6,0x824e653c
	if (cr6.lt) goto loc_824E653C;
loc_824E65A4:
	// li r29,0
	r29.s64 = 0;
loc_824E65A8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e660c
	if (cr6.eq) goto loc_824E660C;
	// li r4,8
	ctx.r4.s64 = 8;
	// lbzx r30,r29,r28
	r30.u64 = PPC_LOAD_U8(r29.u32 + r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824E65C8;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6600
	if (cr6.eq) goto loc_824E6600;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E65F0;
	sub_82618390(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E65FC;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824E6600:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,8
	cr6.compare<uint32_t>(r29.u32, 8, xer);
	// blt cr6,0x824e65a8
	if (cr6.lt) goto loc_824E65A8;
loc_824E660C:
	// li r29,0
	r29.s64 = 0;
loc_824E6610:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6678
	if (cr6.eq) goto loc_824E6678;
	// add r11,r29,r28
	r11.u64 = r29.u64 + r28.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// lbz r30,44(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 44);
	// bl 0x826186c0
	ctx.lr = 0x824E6634;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e666c
	if (cr6.eq) goto loc_824E666C;
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r30,24
	ctx.r4.u64 = r30.u32 & 0xFF;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824E665C;
	sub_82618390(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E6668;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824E666C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,16
	cr6.compare<uint32_t>(r29.u32, 16, xer);
	// blt cr6,0x824e6610
	if (cr6.lt) goto loc_824E6610;
loc_824E6678:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e66ac
	if (cr6.eq) goto loc_824E66AC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e66a4
	if (cr6.eq) goto loc_824E66A4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824E6694;
	sub_826186A0(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_824E66A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
loc_824E66AC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E66B8"))) PPC_WEAK_FUNC(sub_824E66B8);
PPC_FUNC_IMPL(__imp__sub_824E66B8) {
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
	ctx.lr = 0x824E66C0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x82618750
	ctx.lr = 0x824E66E4;
	sub_82618750(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824E66F4;
	sub_826185E0(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E6704;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68e4
	if (cr6.eq) goto loc_824E68E4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r28,12
	ctx.r4.s64 = r28.s64 + 12;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x824E6720;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68e4
	if (cr6.eq) goto loc_824E68E4;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r28,16
	ctx.r4.s64 = r28.s64 + 16;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822756d0
	ctx.lr = 0x824E673C;
	sub_822756D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68e4
	if (cr6.eq) goto loc_824E68E4;
	// li r31,1
	r31.s64 = 1;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_824E6750:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6780
	if (cr6.eq) goto loc_824E6780;
	// add r11,r30,r28
	r11.u64 = r30.u64 + r28.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,18
	ctx.r4.s64 = r11.s64 + 18;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x822510e8
	ctx.lr = 0x824E6770;
	sub_822510E8(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,6
	cr6.compare<uint32_t>(r30.u32, 6, xer);
	// blt cr6,0x824e6750
	if (cr6.lt) goto loc_824E6750;
loc_824E6780:
	// mr r29,r27
	r29.u64 = r27.u64;
loc_824E6784:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e67f8
	if (cr6.eq) goto loc_824E67F8;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r30,r29,r28
	r30.u64 = r29.u64 + r28.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x826187f0
	ctx.lr = 0x824E67A4;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e67e8
	if (cr6.eq) goto loc_824E67E8;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824E67CC;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r11,24(r30)
	PPC_STORE_U8(r30.u32 + 24, r11.u8);
	// bl 0x826188d8
	ctx.lr = 0x824E67E0;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824e67ec
	goto loc_824E67EC;
loc_824E67E8:
	// stb r27,24(r30)
	PPC_STORE_U8(r30.u32 + 24, r27.u8);
loc_824E67EC:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,20
	cr6.compare<uint32_t>(r29.u32, 20, xer);
	// blt cr6,0x824e6784
	if (cr6.lt) goto loc_824E6784;
loc_824E67F8:
	// mr r30,r27
	r30.u64 = r27.u64;
loc_824E67FC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e686c
	if (cr6.eq) goto loc_824E686C;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x826187f0
	ctx.lr = 0x824E6818;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e685c
	if (cr6.eq) goto loc_824E685C;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824E6840;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stbx r11,r30,r28
	PPC_STORE_U8(r30.u32 + r28.u32, r11.u8);
	// bl 0x826188d8
	ctx.lr = 0x824E6854;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824e6860
	goto loc_824E6860;
loc_824E685C:
	// stbx r27,r30,r28
	PPC_STORE_U8(r30.u32 + r28.u32, r27.u8);
loc_824E6860:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r30,8
	cr6.compare<uint32_t>(r30.u32, 8, xer);
	// blt cr6,0x824e67fc
	if (cr6.lt) goto loc_824E67FC;
loc_824E686C:
	// mr r29,r27
	r29.u64 = r27.u64;
loc_824E6870:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68e4
	if (cr6.eq) goto loc_824E68E4;
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r30,r29,r28
	r30.u64 = r29.u64 + r28.u64;
	// mr r31,r27
	r31.u64 = r27.u64;
	// bl 0x826187f0
	ctx.lr = 0x824E6890;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e68d4
	if (cr6.eq) goto loc_824E68D4;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x824E68B8;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r11,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r11.u8);
	// bl 0x826188d8
	ctx.lr = 0x824E68CC;
	sub_826188D8(ctx, base);
	// li r31,1
	r31.s64 = 1;
	// b 0x824e68d8
	goto loc_824E68D8;
loc_824E68D4:
	// stb r27,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r27.u8);
loc_824E68D8:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,16
	cr6.compare<uint32_t>(r29.u32, 16, xer);
	// blt cr6,0x824e6870
	if (cr6.lt) goto loc_824E6870;
loc_824E68E4:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e6918
	if (cr6.eq) goto loc_824E6918;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6910
	if (cr6.eq) goto loc_824E6910;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E6900;
	sub_826186B0(ctx, base);
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
loc_824E6910:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
loc_824E6918:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E6924"))) PPC_WEAK_FUNC(sub_824E6924);
PPC_FUNC_IMPL(__imp__sub_824E6924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6928"))) PPC_WEAK_FUNC(sub_824E6928);
PPC_FUNC_IMPL(__imp__sub_824E6928) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,26072
	ctx.r10.s64 = r11.s64 + 26072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824E6950;
	sub_821C8ED8(ctx, base);
	// lbz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// rlwimi r7,r9,7,0,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 7) & 0xFFFFFFC0) | (ctx.r7.u64 & 0xFFFFFFFF0000003F);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r8.u32);
	// stb r7,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_824E698C"))) PPC_WEAK_FUNC(sub_824E698C);
PPC_FUNC_IMPL(__imp__sub_824E698C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6990"))) PPC_WEAK_FUNC(sub_824E6990);
PPC_FUNC_IMPL(__imp__sub_824E6990) {
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
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x824e69f8
	if (cr6.eq) goto loc_824E69F8;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r10.u8);
	// bl 0x821c9108
	ctx.lr = 0x824E69C4;
	sub_821C9108(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c90c0
	ctx.lr = 0x824E69CC;
	sub_821C90C0(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x821c9168
	ctx.lr = 0x824E69D4;
	sub_821C9168(ctx, base);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
	// bl 0x821c9158
	ctx.lr = 0x824E69E4;
	sub_821C9158(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c9158
	ctx.lr = 0x824E69EC;
	sub_821C9158(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
loc_824E69F8:
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
}

__attribute__((alias("__imp__sub_824E6A10"))) PPC_WEAK_FUNC(sub_824E6A10);
PPC_FUNC_IMPL(__imp__sub_824E6A10) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// b 0x821c9108
	sub_821C9108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E6A18"))) PPC_WEAK_FUNC(sub_824E6A18);
PPC_FUNC_IMPL(__imp__sub_824E6A18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// li r10,-1
	ctx.r10.s64 = -1;
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6A34"))) PPC_WEAK_FUNC(sub_824E6A34);
PPC_FUNC_IMPL(__imp__sub_824E6A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6A38"))) PPC_WEAK_FUNC(sub_824E6A38);
PPC_FUNC_IMPL(__imp__sub_824E6A38) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x821c8fe0
	ctx.lr = 0x824E6A58;
	sub_821C8FE0(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r31,r11,26,31,31
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824E6A68;
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

__attribute__((alias("__imp__sub_824E6A80"))) PPC_WEAK_FUNC(sub_824E6A80);
PPC_FUNC_IMPL(__imp__sub_824E6A80) {
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
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c9108
	ctx.lr = 0x824E6AA0;
	sub_821C9108(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e6b34
	if (!cr6.eq) goto loc_824E6B34;
loc_824E6AB0:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x821c90c0
	ctx.lr = 0x824E6AB8;
	sub_821C90C0(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e6b34
	if (!cr6.eq) goto loc_824E6B34;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824E6AD8;
	sub_821C8FE0(ctx, base);
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stb r10,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r10.u8);
	// bl 0x821c9030
	ctx.lr = 0x824E6AEC;
	sub_821C9030(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824E6B00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x824E6B0C;
	sub_821C8FE0(ctx, base);
	// lbz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// rlwinm r6,r6,0,26,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r6,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r6.u8);
	// bl 0x821c9030
	ctx.lr = 0x824E6B24;
	sub_821C9030(ctx, base);
	// lbz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// rlwinm r4,r5,0,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824e6ab0
	if (cr6.eq) goto loc_824E6AB0;
loc_824E6B34:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c9108
	ctx.lr = 0x824E6B3C;
	sub_821C9108(ctx, base);
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

__attribute__((alias("__imp__sub_824E6B54"))) PPC_WEAK_FUNC(sub_824E6B54);
PPC_FUNC_IMPL(__imp__sub_824E6B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6B58"))) PPC_WEAK_FUNC(sub_824E6B58);
PPC_FUNC_IMPL(__imp__sub_824E6B58) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,26072
	ctx.r10.s64 = r11.s64 + 26072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e6990
	ctx.lr = 0x824E6B7C;
	sub_824E6990(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82130000
	ctx.lr = 0x824E6B84;
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
}

__attribute__((alias("__imp__sub_824E6B98"))) PPC_WEAK_FUNC(sub_824E6B98);
PPC_FUNC_IMPL(__imp__sub_824E6B98) {
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
	ctx.lr = 0x824E6BA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// bl 0x821c9060
	ctx.lr = 0x824E6BC4;
	sub_821C9060(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x824E6BD0;
	sub_821C9060(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6c30
	if (cr6.eq) goto loc_824E6C30;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e6c30
	if (cr6.eq) goto loc_824E6C30;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// lis r10,-32178
	ctx.r10.s64 = -2108817408;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// clrlwi r7,r11,25
	ctx.r7.u64 = r11.u32 & 0x7F;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r7,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r7.u8);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r10,27264
	ctx.r3.s64 = ctx.r10.s64 + 27264;
	// bl 0x821c9308
	ctx.lr = 0x824E6C18;
	sub_821C9308(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824e6c30
	if (cr6.eq) goto loc_824E6C30;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c90c0
	ctx.lr = 0x824E6C2C;
	sub_821C90C0(ctx, base);
	// li r27,1
	r27.s64 = 1;
loc_824E6C30:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e6c64
	if (!cr6.eq) goto loc_824E6C64;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e6c50
	if (cr6.eq) goto loc_824E6C50;
	// bl 0x821c9158
	ctx.lr = 0x824E6C4C;
	sub_821C9158(ctx, base);
	// stw r26,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r26.u32);
loc_824E6C50:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e6c64
	if (cr6.eq) goto loc_824E6C64;
	// bl 0x821c9158
	ctx.lr = 0x824E6C60;
	sub_821C9158(ctx, base);
	// stw r26,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r26.u32);
loc_824E6C64:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E6C70"))) PPC_WEAK_FUNC(sub_824E6C70);
PPC_FUNC_IMPL(__imp__sub_824E6C70) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,26072
	ctx.r10.s64 = r11.s64 + 26072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e6990
	ctx.lr = 0x824E6C9C;
	sub_824E6990(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82130000
	ctx.lr = 0x824E6CA4;
	sub_82130000(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824e6cbc
	if (cr6.eq) goto loc_824E6CBC;
	// bl 0x82130588
	ctx.lr = 0x824E6CB8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E6CBC:
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

__attribute__((alias("__imp__sub_824E6CD4"))) PPC_WEAK_FUNC(sub_824E6CD4);
PPC_FUNC_IMPL(__imp__sub_824E6CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E6CD8"))) PPC_WEAK_FUNC(sub_824E6CD8);
PPC_FUNC_IMPL(__imp__sub_824E6CD8) {
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
	// bl 0x824575f8
	ctx.lr = 0x824E6CE8;
	sub_824575F8(ctx, base);
	// addi r10,r3,0
	ctx.r10.s64 = ctx.r3.s64 + 0;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r3,r8,1
	ctx.r3.u64 = ctx.r8.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E6D08"))) PPC_WEAK_FUNC(sub_824E6D08);
PPC_FUNC_IMPL(__imp__sub_824E6D08) {
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
	// bl 0x825019b0
	ctx.lr = 0x824E6D28;
	sub_825019B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6d4c
	if (cr6.eq) goto loc_824E6D4C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824575f8
	ctx.lr = 0x824E6D3C;
	sub_824575F8(ctx, base);
	// addi r11,r3,-2
	r11.s64 = ctx.r3.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x824e6d50
	goto loc_824E6D50;
loc_824E6D4C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824E6D50:
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

__attribute__((alias("__imp__sub_824E6D68"))) PPC_WEAK_FUNC(sub_824E6D68);
PPC_FUNC_IMPL(__imp__sub_824E6D68) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,254
	ctx.r4.s64 = 254;
	// bl 0x82457608
	ctx.lr = 0x824E6D80;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6d98
	if (!cr6.eq) goto loc_824E6D98;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6d9c
	if (cr6.eq) goto loc_824E6D9C;
loc_824E6D98:
	// li r11,0
	r11.s64 = 0;
loc_824E6D9C:
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

__attribute__((alias("__imp__sub_824E6DB0"))) PPC_WEAK_FUNC(sub_824E6DB0);
PPC_FUNC_IMPL(__imp__sub_824E6DB0) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r4,251
	ctx.r4.s64 = 251;
	// bne cr6,0x824e6dd4
	if (!cr6.eq) goto loc_824E6DD4;
	// li r4,252
	ctx.r4.s64 = 252;
loc_824E6DD4:
	// bl 0x82457608
	ctx.lr = 0x824E6DD8;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6df0
	if (!cr6.eq) goto loc_824E6DF0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6df4
	if (cr6.eq) goto loc_824E6DF4;
loc_824E6DF0:
	// li r11,0
	r11.s64 = 0;
loc_824E6DF4:
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

__attribute__((alias("__imp__sub_824E6E08"))) PPC_WEAK_FUNC(sub_824E6E08);
PPC_FUNC_IMPL(__imp__sub_824E6E08) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,247
	ctx.r4.s64 = 247;
	// bl 0x82457608
	ctx.lr = 0x824E6E20;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6e38
	if (!cr6.eq) goto loc_824E6E38;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6e3c
	if (cr6.eq) goto loc_824E6E3C;
loc_824E6E38:
	// li r11,0
	r11.s64 = 0;
loc_824E6E3C:
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

__attribute__((alias("__imp__sub_824E6E50"))) PPC_WEAK_FUNC(sub_824E6E50);
PPC_FUNC_IMPL(__imp__sub_824E6E50) {
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
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,246
	ctx.r4.s64 = 246;
	// bl 0x82457608
	ctx.lr = 0x824E6E68;
	sub_82457608(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6e80
	if (!cr6.eq) goto loc_824E6E80;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6e84
	if (cr6.eq) goto loc_824E6E84;
loc_824E6E80:
	// li r11,0
	r11.s64 = 0;
loc_824E6E84:
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

__attribute__((alias("__imp__sub_824E6E98"))) PPC_WEAK_FUNC(sub_824E6E98);
PPC_FUNC_IMPL(__imp__sub_824E6E98) {
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
	ctx.lr = 0x824E6EA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x824f9270
	ctx.lr = 0x824E6EB8;
	sub_824F9270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6f14
	if (cr6.eq) goto loc_824E6F14;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824E6ED0;
	sub_824F92F0(ctx, base);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82457600
	ctx.lr = 0x824E6EEC;
	sub_82457600(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e6f04
	if (!cr6.eq) goto loc_824E6F04;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e6f08
	if (cr6.eq) goto loc_824E6F08;
loc_824E6F04:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_824E6F08:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824E6F14:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E6F20"))) PPC_WEAK_FUNC(sub_824E6F20);
PPC_FUNC_IMPL(__imp__sub_824E6F20) {
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
	// bl 0x824f9788
	ctx.lr = 0x824E6F38;
	sub_824F9788(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x824f0498
	ctx.lr = 0x824E6F40;
	sub_824F0498(ctx, base);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// bl 0x824f9230
	ctx.lr = 0x824E6F48;
	sub_824F9230(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,76
	ctx.r3.s64 = r31.s64 + 76;
	// bl 0x8244d150
	ctx.lr = 0x824E6F60;
	sub_8244D150(ctx, base);
	// lbz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// stb r9,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_824E6F80"))) PPC_WEAK_FUNC(sub_824E6F80);
PPC_FUNC_IMPL(__imp__sub_824E6F80) {
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
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x824f04a8
	ctx.lr = 0x824E6F9C;
	sub_824F04A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6fe8
	if (cr6.eq) goto loc_824E6FE8;
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// bl 0x824f9270
	ctx.lr = 0x824E6FB0;
	sub_824F9270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6fe8
	if (cr6.eq) goto loc_824E6FE8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9a00
	ctx.lr = 0x824E6FC4;
	sub_824F9A00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e6fe8
	if (cr6.eq) goto loc_824E6FE8;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x824e6fe8
	if (cr6.lt) goto loc_824E6FE8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824e6fec
	if (cr6.lt) goto loc_824E6FEC;
loc_824E6FE8:
	// li r11,0
	r11.s64 = 0;
loc_824E6FEC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E7004"))) PPC_WEAK_FUNC(sub_824E7004);
PPC_FUNC_IMPL(__imp__sub_824E7004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7008"))) PPC_WEAK_FUNC(sub_824E7008);
PPC_FUNC_IMPL(__imp__sub_824E7008) {
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
	// bl 0x824e6f80
	ctx.lr = 0x824E7020;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7044
	if (cr6.eq) goto loc_824E7044;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9a20
	ctx.lr = 0x824E7034;
	sub_824F9A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e7048
	if (!cr6.eq) goto loc_824E7048;
loc_824E7044:
	// li r11,0
	r11.s64 = 0;
loc_824E7048:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E7060"))) PPC_WEAK_FUNC(sub_824E7060);
PPC_FUNC_IMPL(__imp__sub_824E7060) {
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
	// bl 0x824e6f80
	ctx.lr = 0x824E7078;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e70c4
	if (cr6.eq) goto loc_824E70C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6f80
	ctx.lr = 0x824E708C;
	sub_824E6F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e70b0
	if (cr6.eq) goto loc_824E70B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9a20
	ctx.lr = 0x824E70A0;
	sub_824F9A20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e70b4
	if (!cr6.eq) goto loc_824E70B4;
loc_824E70B0:
	// li r11,0
	r11.s64 = 0;
loc_824E70B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e70c8
	if (cr6.eq) goto loc_824E70C8;
loc_824E70C4:
	// li r11,0
	r11.s64 = 0;
loc_824E70C8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824E70E0"))) PPC_WEAK_FUNC(sub_824E70E0);
PPC_FUNC_IMPL(__imp__sub_824E70E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r3,r11,25,7,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E70EC"))) PPC_WEAK_FUNC(sub_824E70EC);
PPC_FUNC_IMPL(__imp__sub_824E70EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E70F0"))) PPC_WEAK_FUNC(sub_824E70F0);
PPC_FUNC_IMPL(__imp__sub_824E70F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r3,r11,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// blr 
	return;
}

