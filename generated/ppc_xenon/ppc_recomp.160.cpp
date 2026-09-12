#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8277108C"))) PPC_WEAK_FUNC(sub_8277108C);
PPC_FUNC_IMPL(__imp__sub_8277108C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771090"))) PPC_WEAK_FUNC(sub_82771090);
PPC_FUNC_IMPL(__imp__sub_82771090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827710A4"))) PPC_WEAK_FUNC(sub_827710A4);
PPC_FUNC_IMPL(__imp__sub_827710A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827710A8"))) PPC_WEAK_FUNC(sub_827710A8);
PPC_FUNC_IMPL(__imp__sub_827710A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// not r11,r4
	r11.u64 = ~ctx.r4.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827710cc
	if (cr6.eq) goto loc_827710CC;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_827710CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827710D4"))) PPC_WEAK_FUNC(sub_827710D4);
PPC_FUNC_IMPL(__imp__sub_827710D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827710D8"))) PPC_WEAK_FUNC(sub_827710D8);
PPC_FUNC_IMPL(__imp__sub_827710D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// not r11,r4
	r11.u64 = ~ctx.r4.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827710fc
	if (cr6.eq) goto loc_827710FC;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_827710FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82771104"))) PPC_WEAK_FUNC(sub_82771104);
PPC_FUNC_IMPL(__imp__sub_82771104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771108"))) PPC_WEAK_FUNC(sub_82771108);
PPC_FUNC_IMPL(__imp__sub_82771108) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// not r11,r5
	r11.u64 = ~ctx.r5.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277112c
	if (cr6.eq) goto loc_8277112C;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8277112C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82771134"))) PPC_WEAK_FUNC(sub_82771134);
PPC_FUNC_IMPL(__imp__sub_82771134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771138"))) PPC_WEAK_FUNC(sub_82771138);
PPC_FUNC_IMPL(__imp__sub_82771138) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8277114C"))) PPC_WEAK_FUNC(sub_8277114C);
PPC_FUNC_IMPL(__imp__sub_8277114C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771150"))) PPC_WEAK_FUNC(sub_82771150);
PPC_FUNC_IMPL(__imp__sub_82771150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
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

__attribute__((alias("__imp__sub_82771164"))) PPC_WEAK_FUNC(sub_82771164);
PPC_FUNC_IMPL(__imp__sub_82771164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771168"))) PPC_WEAK_FUNC(sub_82771168);
PPC_FUNC_IMPL(__imp__sub_82771168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// not r11,r6
	r11.u64 = ~ctx.r6.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277118c
	if (cr6.eq) goto loc_8277118C;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8277118C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82771194"))) PPC_WEAK_FUNC(sub_82771194);
PPC_FUNC_IMPL(__imp__sub_82771194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771198"))) PPC_WEAK_FUNC(sub_82771198);
PPC_FUNC_IMPL(__imp__sub_82771198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// not r11,r4
	r11.u64 = ~ctx.r4.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827711bc
	if (cr6.eq) goto loc_827711BC;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_827711BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827711C4"))) PPC_WEAK_FUNC(sub_827711C4);
PPC_FUNC_IMPL(__imp__sub_827711C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827711C8"))) PPC_WEAK_FUNC(sub_827711C8);
PPC_FUNC_IMPL(__imp__sub_827711C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827711DC"))) PPC_WEAK_FUNC(sub_827711DC);
PPC_FUNC_IMPL(__imp__sub_827711DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827711E0"))) PPC_WEAK_FUNC(sub_827711E0);
PPC_FUNC_IMPL(__imp__sub_827711E0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,26300
	ctx.r10.s64 = r11.s64 + 26300;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82761e08
	ctx.lr = 0x8277120C;
	sub_82761E08(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82771224
	if (cr6.eq) goto loc_82771224;
	// bl 0x82130588
	ctx.lr = 0x82771220;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82771224:
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

__attribute__((alias("__imp__sub_8277123C"))) PPC_WEAK_FUNC(sub_8277123C);
PPC_FUNC_IMPL(__imp__sub_8277123C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771240"))) PPC_WEAK_FUNC(sub_82771240);
PPC_FUNC_IMPL(__imp__sub_82771240) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82771248;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// rlwinm r10,r28,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0x1;
	// beq cr6,0x82771278
	if (cr6.eq) goto loc_82771278;
	// rlwinm r11,r30,0,0,0
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8277127c
	if (!cr6.eq) goto loc_8277127C;
loc_82771278:
	// li r11,1
	r11.s64 = 1;
loc_8277127C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// li r26,1
	r26.s64 = 1;
	// rlwinm r27,r9,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827712e0
	if (cr6.eq) goto loc_827712E0;
	// clrlwi r4,r28,16
	ctx.r4.u64 = r28.u32 & 0xFFFF;
	// lwz r3,40(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// bl 0x825517a8
	ctx.lr = 0x827712A4;
	sub_825517A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82771344
	if (cr6.eq) goto loc_82771344;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82771344
	if (cr6.eq) goto loc_82771344;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r5,r28,16,17,31
	ctx.r5.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 16) & 0x7FFF;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827712D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_827712E0:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82771324
	if (cr6.eq) goto loc_82771324;
	// rlwinm r4,r30,16,17,31
	ctx.r4.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0x7FFF;
	// lwz r3,40(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// bl 0x825517a8
	ctx.lr = 0x827712F8;
	sub_825517A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82771344
	if (cr6.eq) goto loc_82771344;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r5,r30,16
	ctx.r5.u64 = r30.u32 & 0xFFFF;
	// lwz r6,48(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277131C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82771324:
	// lwz r3,48(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277133C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82771344:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82771350"))) PPC_WEAK_FUNC(sub_82771350);
PPC_FUNC_IMPL(__imp__sub_82771350) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// not r11,r5
	r11.u64 = ~ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277139c
	if (cr6.eq) goto loc_8277139C;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82771388;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_8277139C:
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// bl 0x825517a8
	ctx.lr = 0x827713A8;
	sub_825517A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827713cc
	if (!cr6.eq) goto loc_827713CC;
loc_827713B0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
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
loc_827713CC:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827713E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827713b0
	if (cr6.eq) goto loc_827713B0;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
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

__attribute__((alias("__imp__sub_82771434"))) PPC_WEAK_FUNC(sub_82771434);
PPC_FUNC_IMPL(__imp__sub_82771434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771438"))) PPC_WEAK_FUNC(sub_82771438);
PPC_FUNC_IMPL(__imp__sub_82771438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// not r11,r4
	r11.u64 = ~ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82771484
	if (cr6.eq) goto loc_82771484;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82771470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_82771484:
	// clrlwi r4,r4,16
	ctx.r4.u64 = ctx.r4.u32 & 0xFFFF;
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// bl 0x825517a8
	ctx.lr = 0x82771490;
	sub_825517A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827714dc
	if (cr6.eq) goto loc_827714DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827714AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827714dc
	if (cr6.eq) goto loc_827714DC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_827714DC:
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

__attribute__((alias("__imp__sub_827714F4"))) PPC_WEAK_FUNC(sub_827714F4);
PPC_FUNC_IMPL(__imp__sub_827714F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827714F8"))) PPC_WEAK_FUNC(sub_827714F8);
PPC_FUNC_IMPL(__imp__sub_827714F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8277150C"))) PPC_WEAK_FUNC(sub_8277150C);
PPC_FUNC_IMPL(__imp__sub_8277150C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771510"))) PPC_WEAK_FUNC(sub_82771510);
PPC_FUNC_IMPL(__imp__sub_82771510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82771524"))) PPC_WEAK_FUNC(sub_82771524);
PPC_FUNC_IMPL(__imp__sub_82771524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771528"))) PPC_WEAK_FUNC(sub_82771528);
PPC_FUNC_IMPL(__imp__sub_82771528) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8277153C"))) PPC_WEAK_FUNC(sub_8277153C);
PPC_FUNC_IMPL(__imp__sub_8277153C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771540"))) PPC_WEAK_FUNC(sub_82771540);
PPC_FUNC_IMPL(__imp__sub_82771540) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,21288
	ctx.r9.s64 = r11.s64 + 21288;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82771574
	if (cr6.eq) goto loc_82771574;
	// bl 0x82130588
	ctx.lr = 0x82771570;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82771574:
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

__attribute__((alias("__imp__sub_82771588"))) PPC_WEAK_FUNC(sub_82771588);
PPC_FUNC_IMPL(__imp__sub_82771588) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8276c5a8
	ctx.lr = 0x827715A0;
	sub_8276C5A8(ctx, base);
	// addi r7,r31,68
	ctx.r7.s64 = r31.s64 + 68;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// li r10,15
	ctx.r10.s64 = 15;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r8,26412
	ctx.r8.s64 = ctx.r8.s64 + 26412;
loc_827715B8:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bge 0x827715b8
	if (!cr0.lt) goto loc_827715B8;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// li r11,16
	r11.s64 = 16;
loc_827715DC:
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x827715dc
	if (!cr0.eq) goto loc_827715DC;
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

__attribute__((alias("__imp__sub_82771608"))) PPC_WEAK_FUNC(sub_82771608);
PPC_FUNC_IMPL(__imp__sub_82771608) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82771610;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x8276c5a8
	ctx.lr = 0x8277161C;
	sub_8276C5A8(ctx, base);
	// addi r26,r25,68
	r26.s64 = r25.s64 + 68;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r29,15
	r29.s64 = 15;
	// mr r31,r26
	r31.u64 = r26.u64;
	// li r28,-1
	r28.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// addi r27,r11,26444
	r27.s64 = r11.s64 + 26444;
loc_82771638:
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// stb r30,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r30.u8);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// bl 0x827748c8
	ctx.lr = 0x82771650;
	sub_827748C8(ctx, base);
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// bl 0x827748c8
	ctx.lr = 0x82771658;
	sub_827748C8(ctx, base);
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// stw r30,676(r31)
	PPC_STORE_U32(r31.u32 + 676, r30.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stb r30,680(r31)
	PPC_STORE_U8(r31.u32 + 680, r30.u8);
	// stw r30,684(r31)
	PPC_STORE_U32(r31.u32 + 684, r30.u32);
	// stw r30,688(r31)
	PPC_STORE_U32(r31.u32 + 688, r30.u32);
	// stb r30,692(r31)
	PPC_STORE_U8(r31.u32 + 692, r30.u8);
	// stw r30,696(r31)
	PPC_STORE_U32(r31.u32 + 696, r30.u32);
	// stw r30,700(r31)
	PPC_STORE_U32(r31.u32 + 700, r30.u32);
	// stw r30,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r30.u32);
	// stw r30,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r30.u32);
	// addi r31,r31,712
	r31.s64 = r31.s64 + 712;
	// bge 0x82771638
	if (!cr0.lt) goto loc_82771638;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// li r11,16
	r11.s64 = 16;
loc_82771698:
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,712
	ctx.r10.s64 = ctx.r10.s64 + 712;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82771698
	if (!cr0.eq) goto loc_82771698;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_827716B8"))) PPC_WEAK_FUNC(sub_827716B8);
PPC_FUNC_IMPL(__imp__sub_827716B8) {
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
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r4,r11,8
	ctx.r4.u64 = r11.u64 | 8;
	// bl 0x82762430
	ctx.lr = 0x827716D8;
	sub_82762430(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r10,26300
	ctx.r7.s64 = ctx.r10.s64 + 26300;
	// addi r6,r9,-15532
	ctx.r6.s64 = ctx.r9.s64 + -15532;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// addi r5,r8,-15272
	ctx.r5.s64 = ctx.r8.s64 + -15272;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r5.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
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

__attribute__((alias("__imp__sub_82771724"))) PPC_WEAK_FUNC(sub_82771724);
PPC_FUNC_IMPL(__imp__sub_82771724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771728"))) PPC_WEAK_FUNC(sub_82771728);
PPC_FUNC_IMPL(__imp__sub_82771728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f31{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82771730;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82771768
	if (cr6.eq) goto loc_82771768;
	// addi r27,r5,16
	r27.s64 = ctx.r5.s64 + 16;
	// b 0x82771770
	goto loc_82771770;
loc_82771768:
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r27,r11,3780
	r27.s64 = r11.s64 + 3780;
loc_82771770:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,24(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 24);
	f31.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r5,32
	ctx.r5.s64 = 32;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82551600
	ctx.lr = 0x827717B8;
	sub_82551600(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827718ec
	if (cr6.eq) goto loc_827718EC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// mr r23,r28
	r23.u64 = r28.u64;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ble cr6,0x827718e8
	if (!cr6.gt) goto loc_827718E8;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r26,r1,208
	r26.s64 = ctx.r1.s64 + 208;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lis r29,-32768
	r29.s64 = -2147483648;
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r22,r11,26276
	r22.s64 = r11.s64 + 26276;
loc_82771800:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82774ba8
	ctx.lr = 0x8277180C;
	sub_82774BA8(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82771824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// vor128 v2,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82774bc8
	ctx.lr = 0x82771834;
	sub_82774BC8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827718d8
	if (cr6.eq) goto loc_827718D8;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x82771870
	if (cr6.eq) goto loc_82771870;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// b 0x82771874
	goto loc_82771874;
loc_82771870:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
loc_82771874:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277187C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x827718d8
	if (!cr6.gt) goto loc_827718D8;
	// li r23,1
	r23.s64 = 1;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
loc_8277188C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x827718cc
	if (!cr6.lt) goto loc_827718CC;
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// lhz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwimi r8,r9,16,1,15
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0x7FFF0000) | (ctx.r8.u64 & 0xFFFFFFFF8000FFFF);
	// or r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stwx r4,r6,r5
	PPC_STORE_U32(ctx.r6.u32 + ctx.r5.u32, ctx.r4.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r28,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r28.u8);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_827718CC:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bne 0x8277188c
	if (!cr0.eq) goto loc_8277188C;
loc_827718D8:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r22.u32);
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// bne 0x82771800
	if (!cr0.eq) goto loc_82771800;
loc_827718E8:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
loc_827718EC:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82771908"))) PPC_WEAK_FUNC(sub_82771908);
PPC_FUNC_IMPL(__imp__sub_82771908) {
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
	ctx.lr = 0x82771910;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lvx128 v1,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82771728
	ctx.lr = 0x82771938;
	sub_82771728(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82771984
	if (!cr6.eq) goto loc_82771984;
	// lwz r27,48(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82761e50
	ctx.lr = 0x82771950;
	sub_82761E50(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82771970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82762030
	ctx.lr = 0x8277197C;
	sub_82762030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82761e68
	ctx.lr = 0x82771984;
	sub_82761E68(ctx, base);
loc_82771984:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8277198C"))) PPC_WEAK_FUNC(sub_8277198C);
PPC_FUNC_IMPL(__imp__sub_8277198C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771990"))) PPC_WEAK_FUNC(sub_82771990);
PPC_FUNC_IMPL(__imp__sub_82771990) {
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
	ctx.lr = 0x82771998;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lvx128 v1,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82771728
	ctx.lr = 0x827719C0;
	sub_82771728(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82771a0c
	if (!cr6.eq) goto loc_82771A0C;
	// lwz r27,48(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82761e50
	ctx.lr = 0x827719D8;
	sub_82761E50(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827719F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82762030
	ctx.lr = 0x82771A04;
	sub_82762030(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82761e68
	ctx.lr = 0x82771A0C;
	sub_82761E68(ctx, base);
loc_82771A0C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82771A14"))) PPC_WEAK_FUNC(sub_82771A14);
PPC_FUNC_IMPL(__imp__sub_82771A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771A18"))) PPC_WEAK_FUNC(sub_82771A18);
PPC_FUNC_IMPL(__imp__sub_82771A18) {
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
	ctx.lr = 0x82771A20;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// bl 0x821d0898
	ctx.lr = 0x82771A3C;
	sub_821D0898(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r26,r11,18168
	r26.s64 = r11.s64 + 18168;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821cff40
	ctx.lr = 0x82771A5C;
	sub_821CFF40(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82771ae4
	if (cr6.eq) goto loc_82771AE4;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r27,-32114
	r27.s64 = -2104623104;
	// addi r29,r10,-20524
	r29.s64 = ctx.r10.s64 + -20524;
	// addi r28,r11,-20564
	r28.s64 = r11.s64 + -20564;
loc_82771A7C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82771A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-23464(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -23464);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// bl 0x823dedd8
	ctx.lr = 0x82771AB4;
	sub_823DEDD8(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x8258fd48
	ctx.lr = 0x82771ABC;
	sub_8258FD48(ctx, base);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// or r8,r3,r9
	ctx.r8.u64 = ctx.r3.u64 | ctx.r9.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x82771AD8;
	sub_821CFF40(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82771a7c
	if (!cr6.eq) goto loc_82771A7C;
loc_82771AE4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0260
	ctx.lr = 0x82771AEC;
	sub_821D0260(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82771AF4"))) PPC_WEAK_FUNC(sub_82771AF4);
PPC_FUNC_IMPL(__imp__sub_82771AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771AF8"))) PPC_WEAK_FUNC(sub_82771AF8);
PPC_FUNC_IMPL(__imp__sub_82771AF8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82771B00;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82771B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r11,0
	r11.s64 = 0;
	// addi r5,r7,-20524
	ctx.r5.s64 = ctx.r7.s64 + -20524;
	// addi r6,r8,-20564
	ctx.r6.s64 = ctx.r8.s64 + -20564;
	// lwz r3,-23464(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23464);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x823dedd8
	ctx.lr = 0x82771B50;
	sub_823DEDD8(ctx, base);
	// addi r6,r3,20
	ctx.r6.s64 = ctx.r3.s64 + 20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// bl 0x82237920
	ctx.lr = 0x82771B60;
	sub_82237920(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82771be8
	if (cr6.eq) goto loc_82771BE8;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r27,r11,26480
	r27.s64 = r11.s64 + 26480;
loc_82771B7C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,8(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82771ba0
	if (cr6.eq) goto loc_82771BA0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d03e0
	ctx.lr = 0x82771BA0;
	sub_821D03E0(ctx, base);
loc_82771BA0:
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82771b7c
	if (!cr6.eq) goto loc_82771B7C;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
loc_82771BB8:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82771be0
	if (!cr6.lt) goto loc_82771BE0;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r31,r11,r8
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82771bb8
	if (cr6.eq) goto loc_82771BB8;
	// b 0x82771b7c
	goto loc_82771B7C;
loc_82771BE0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82771b7c
	if (!cr6.eq) goto loc_82771B7C;
loc_82771BE8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82771BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82771C04"))) PPC_WEAK_FUNC(sub_82771C04);
PPC_FUNC_IMPL(__imp__sub_82771C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771C08"))) PPC_WEAK_FUNC(sub_82771C08);
PPC_FUNC_IMPL(__imp__sub_82771C08) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,26772
	ctx.r9.s64 = r11.s64 + 26772;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82771c3c
	if (cr6.eq) goto loc_82771C3C;
	// bl 0x82130588
	ctx.lr = 0x82771C38;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82771C3C:
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

__attribute__((alias("__imp__sub_82771C50"))) PPC_WEAK_FUNC(sub_82771C50);
PPC_FUNC_IMPL(__imp__sub_82771C50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82771C64"))) PPC_WEAK_FUNC(sub_82771C64);
PPC_FUNC_IMPL(__imp__sub_82771C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771C68"))) PPC_WEAK_FUNC(sub_82771C68);
PPC_FUNC_IMPL(__imp__sub_82771C68) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82771C70;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + r11.u64;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r6,r4,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + r11.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,8(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bgt cr6,0x82771cd4
	if (cr6.gt) goto loc_82771CD4;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r29,8(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r29,r8
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r10,r29
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x82771cd4
	if (!cr6.lt) goto loc_82771CD4;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_82771CD4:
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// bgt cr6,0x82771d0c
	if (cr6.gt) goto loc_82771D0C;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r9,r5,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r5,r8
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x82771d0c
	if (!cr6.lt) goto loc_82771D0C;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_82771D0C:
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x82771e34
	if (cr6.eq) goto loc_82771E34;
loc_82771D14:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r29,8(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// lfsx f13,r29,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stfsx f13,r29,r9
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + ctx.r9.u32, temp.u32);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r29,r8,r10
	r29.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stw r29,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r29.u32);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r29,r8,r10
	r29.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r29,8(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stw r29,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r29.u32);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stfsx f0,r10,r9
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r6,r9
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, xer);
	// bgt cr6,0x82771db8
	if (cr6.gt) goto loc_82771DB8;
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r29,8(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r29,r10
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r8,r29
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x82771db8
	if (!cr6.lt) goto loc_82771DB8;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_82771DB8:
	// cmplw cr6,r5,r9
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r9.u32, xer);
	// bgt cr6,0x82771df0
	if (cr6.gt) goto loc_82771DF0;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r5,r9
	ctx.r6.u64 = ctx.r5.u64 + ctx.r9.u64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r6,r8
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x82771df0
	if (!cr6.lt) goto loc_82771DF0;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_82771DF0:
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bne cr6,0x82771d14
	if (!cr6.eq) goto loc_82771D14;
	// cmplw cr6,r7,r4
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, xer);
	// beq cr6,0x82771e34
	if (cr6.eq) goto loc_82771E34;
	// rlwinm r11,r7,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// stw r30,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r30.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
loc_82771E34:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82771E38"))) PPC_WEAK_FUNC(sub_82771E38);
PPC_FUNC_IMPL(__imp__sub_82771E38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// add r8,r4,r10
	ctx.r8.u64 = ctx.r4.u64 + ctx.r10.u64;
	// rlwinm r9,r4,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// ble cr6,0x82771f30
	if (!cr6.gt) goto loc_82771F30;
loc_82771E70:
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r8,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82771eec
	if (!cr6.gt) goto loc_82771EEC;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// lfsx f13,r7,r8
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// stfsx f13,r10,r7
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, temp.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r31,r7,r8
	r31.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r31,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r31.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r8,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r8.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// bgt cr6,0x82771e70
	if (cr6.gt) goto loc_82771E70;
loc_82771EEC:
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// beq cr6,0x82771f30
	if (cr6.eq) goto loc_82771F30;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r8,r3,r10
	ctx.r8.u64 = ctx.r3.u64 + ctx.r10.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r5,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r5.u32);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
loc_82771F30:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82771F38"))) PPC_WEAK_FUNC(sub_82771F38);
PPC_FUNC_IMPL(__imp__sub_82771F38) {
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
	// addi r10,r11,26844
	ctx.r10.s64 = r11.s64 + 26844;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82130588
	ctx.lr = 0x82771F60;
	sub_82130588(ctx, base);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82130588
	ctx.lr = 0x82771F68;
	sub_82130588(ctx, base);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82771f84
	if (cr6.eq) goto loc_82771F84;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x82771F7C;
	sub_82130588(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x82771F84;
	sub_82130588(ctx, base);
loc_82771F84:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,26772
	ctx.r10.s64 = r11.s64 + 26772;
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

__attribute__((alias("__imp__sub_82771FA4"))) PPC_WEAK_FUNC(sub_82771FA4);
PPC_FUNC_IMPL(__imp__sub_82771FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82771FA8"))) PPC_WEAK_FUNC(sub_82771FA8);
PPC_FUNC_IMPL(__imp__sub_82771FA8) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r6,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r9.u32, temp.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// bne cr6,0x82772008
	if (!cr6.eq) goto loc_82772008;
	// addi r8,r31,12
	ctx.r8.s64 = r31.s64 + 12;
loc_82772008:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82771e38
	ctx.lr = 0x82772050;
	sub_82771E38(ctx, base);
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r7,r3,r11
	ctx.r7.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_82772080"))) PPC_WEAK_FUNC(sub_82772080);
PPC_FUNC_IMPL(__imp__sub_82772080) {
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
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bgt cr6,0x827720b0
	if (cr6.gt) goto loc_827720B0;
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
loc_827720B0:
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f0,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// stw r8,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r8
	ctx.r7.u64 = r11.u64 + ctx.r8.u64;
	// lfs f13,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lwz r6,16(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r9,r10,12
	ctx.r9.s64 = ctx.r10.s64 + 12;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,12(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r7.u32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r5,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r5.u32);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r6,20(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bl 0x82771c68
	ctx.lr = 0x82772138;
	sub_82771C68(ctx, base);
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

__attribute__((alias("__imp__sub_8277214C"))) PPC_WEAK_FUNC(sub_8277214C);
PPC_FUNC_IMPL(__imp__sub_8277214C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82772150"))) PPC_WEAK_FUNC(sub_82772150);
PPC_FUNC_IMPL(__imp__sub_82772150) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r6,r10,10,22,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0x3FF;
	// xor r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 ^ ctx.r10.u64;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r5,r10,23,9,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x7FFFFF;
	// xor r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r10.u64;
	// rlwinm r9,r10,10,0,21
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0xFFFFFC00;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r4,r10,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// xor r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 ^ ctx.r10.u64;
	// rlwinm r9,r10,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r3,r10,20,12,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFFFFF;
	// xor r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r10.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// and r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 & ctx.r7.u64;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r10,r4,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827721d8
	if (cr6.eq) goto loc_827721D8;
loc_827721C0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x827721e0
	if (cr6.eq) goto loc_827721E0;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827721c0
	if (!cr6.eq) goto loc_827721C0;
loc_827721D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_827721E0:
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827721E8"))) PPC_WEAK_FUNC(sub_827721E8);
PPC_FUNC_IMPL(__imp__sub_827721E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r7,r11,10,22,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x3FF;
	// xor r11,r7,r11
	r11.u64 = ctx.r7.u64 ^ r11.u64;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r6,r11,23,9,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 23) & 0x7FFFFF;
	// xor r11,r6,r11
	r11.u64 = ctx.r6.u64 ^ r11.u64;
	// rlwinm r9,r11,10,0,21
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// xor r11,r9,r11
	r11.u64 = ctx.r9.u64 ^ r11.u64;
	// rlwinm r9,r11,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r7,r11,20,12,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// xor r11,r7,r11
	r11.u64 = ctx.r7.u64 ^ r11.u64;
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r6,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// and r11,r11,r8
	r11.u64 = r11.u64 & ctx.r8.u64;
	// bne cr6,0x82772258
	if (!cr6.eq) goto loc_82772258;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82772268
	goto loc_82772268;
loc_82772258:
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
loc_82772268:
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x827722a8
	if (!cr6.eq) goto loc_827722A8;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
loc_827722A8:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827722B8"))) PPC_WEAK_FUNC(sub_827722B8);
PPC_FUNC_IMPL(__imp__sub_827722B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r8,r3,24
	ctx.r8.s64 = ctx.r3.s64 + 24;
	// li r9,0
	ctx.r9.s64 = 0;
loc_827722C0:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827722d4
	if (!cr6.eq) goto loc_827722D4;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// b 0x827722e4
	goto loc_827722E4;
loc_827722D4:
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_827722E4:
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// beq cr6,0x82772328
	if (cr6.eq) goto loc_82772328;
loc_827722EC:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827722c0
	if (cr6.eq) goto loc_827722C0;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// beq cr6,0x827722c0
	if (cr6.eq) goto loc_827722C0;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// b 0x827722ec
	goto loc_827722EC;
loc_82772328:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// stw r8,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82772338"))) PPC_WEAK_FUNC(sub_82772338);
PPC_FUNC_IMPL(__imp__sub_82772338) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_82772344:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82772360
	if (cr6.eq) goto loc_82772360;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bnelr cr6
	if (!cr6.eq) return;
loc_82772360:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// beq cr6,0x82772344
	if (cr6.eq) goto loc_82772344;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82772388"))) PPC_WEAK_FUNC(sub_82772388);
PPC_FUNC_IMPL(__imp__sub_82772388) {
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
	ctx.lr = 0x82772390;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r26,r31,24
	r26.s64 = r31.s64 + 24;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// bge cr6,0x82772404
	if (!cr6.lt) goto loc_82772404;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// rlwinm r8,r9,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r6,r7,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// rlwinm r4,r5,24,8,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFFFFFF;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r11,r3,16,16,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF;
	// or r11,r11,r3
	r11.u64 = r11.u64 | ctx.r3.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82772408
	goto loc_82772408;
loc_82772404:
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
loc_82772408:
	// lis r11,8191
	r11.s64 = 536805376;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r27,-1
	r27.s64 = -1;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// rlwinm r3,r29,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x82772428
	if (!cr6.gt) goto loc_82772428;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82772428:
	// bl 0x82130528
	ctx.lr = 0x8277242C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8277245c
	if (cr6.eq) goto loc_8277245C;
	// addic. r10,r29,-1
	xer.ca = r29.u32 > 0;
	ctx.r10.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// blt 0x82772454
	if (cr0.lt) goto loc_82772454;
loc_82772440:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bge 0x82772440
	if (!cr0.lt) goto loc_82772440;
loc_82772454:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82772460
	goto loc_82772460;
loc_8277245C:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82772460:
	// lis r10,5461
	ctx.r10.s64 = 357892096;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// ori r9,r10,21845
	ctx.r9.u64 = ctx.r10.u64 | 21845;
	// cmplw cr6,r28,r9
	cr6.compare<uint32_t>(r28.u32, ctx.r9.u32, xer);
	// bgt cr6,0x82772484
	if (cr6.gt) goto loc_82772484;
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x82772488
	goto loc_82772488;
loc_82772484:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82772488:
	// bl 0x82130528
	ctx.lr = 0x8277248C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827724b8
	if (cr6.eq) goto loc_827724B8;
	// addic. r11,r28,-1
	xer.ca = r28.u32 > 0;
	r11.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x827724b0
	if (cr0.lt) goto loc_827724B0;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
loc_827724A0:
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bge 0x827724a0
	if (!cr0.lt) goto loc_827724A0;
loc_827724B0:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x827724bc
	goto loc_827724BC;
loc_827724B8:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_827724BC:
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// ble cr6,0x827724f4
	if (!cr6.gt) goto loc_827724F4;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_827724D4:
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// bne 0x827724d4
	if (!cr0.eq) goto loc_827724D4;
loc_827724F4:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r26.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277250C"))) PPC_WEAK_FUNC(sub_8277250C);
PPC_FUNC_IMPL(__imp__sub_8277250C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82772510"))) PPC_WEAK_FUNC(sub_82772510);
PPC_FUNC_IMPL(__imp__sub_82772510) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,26844
	ctx.r10.s64 = r11.s64 + 26844;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82130588
	ctx.lr = 0x82772540;
	sub_82130588(ctx, base);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82130588
	ctx.lr = 0x82772548;
	sub_82130588(ctx, base);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82772564
	if (cr6.eq) goto loc_82772564;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x8277255C;
	sub_82130588(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x82772564;
	sub_82130588(ctx, base);
loc_82772564:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,26772
	ctx.r9.s64 = r11.s64 + 26772;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82772588
	if (cr6.eq) goto loc_82772588;
	// bl 0x82130588
	ctx.lr = 0x82772584;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82772588:
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

__attribute__((alias("__imp__sub_827725A0"))) PPC_WEAK_FUNC(sub_827725A0);
PPC_FUNC_IMPL(__imp__sub_827725A0) {
	PPC_FUNC_PROLOGUE();
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
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// stw r4,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r4.u32);
	// stw r6,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r6.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// bl 0x827722b8
	ctx.lr = 0x827725D4;
	sub_827722B8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
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

__attribute__((alias("__imp__sub_82772604"))) PPC_WEAK_FUNC(sub_82772604);
PPC_FUNC_IMPL(__imp__sub_82772604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82772608"))) PPC_WEAK_FUNC(sub_82772608);
PPC_FUNC_IMPL(__imp__sub_82772608) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r31,16
	ctx.r9.s64 = r31.s64 + 16;
	// li r30,-1
	r30.s64 = -1;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lfs f31,-31400(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x82772650
	if (cr6.eq) goto loc_82772650;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82772654
	goto loc_82772654;
loc_82772650:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82772654:
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827726f0
	if (cr6.eq) goto loc_827726F0;
loc_82772660:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x827726dc
	if (cr6.lt) goto loc_827726DC;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827726a0
	if (!cr6.eq) goto loc_827726A0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x827726a4
	if (!cr6.eq) goto loc_827726A4;
loc_827726A0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_827726A4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827726dc
	if (cr6.eq) goto loc_827726DC;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x827726dc
	if (cr6.eq) goto loc_827726DC;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// beq cr6,0x827726dc
	if (cr6.eq) goto loc_827726DC;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x827726dc
	if (!cr6.lt) goto loc_827726DC;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
loc_827726DC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82772338
	ctx.lr = 0x827726E4;
	sub_82772338(ctx, base);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82772660
	if (!cr6.eq) goto loc_82772660;
loc_827726F0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82772710"))) PPC_WEAK_FUNC(sub_82772710);
PPC_FUNC_IMPL(__imp__sub_82772710) {
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
	ctx.lr = 0x82772718;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r10,r31,16
	ctx.r10.s64 = r31.s64 + 16;
	// li r30,0
	r30.s64 = 0;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x82772748
	if (cr6.eq) goto loc_82772748;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8277274c
	goto loc_8277274C;
loc_82772748:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8277274C:
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827727d4
	if (cr6.eq) goto loc_827727D4;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
loc_8277275C:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x827727c0
	if (cr6.lt) goto loc_827727C0;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277279c
	if (!cr6.eq) goto loc_8277279C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x827727a0
	if (!cr6.eq) goto loc_827727A0;
loc_8277279C:
	// li r11,0
	r11.s64 = 0;
loc_827727A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827727c0
	if (cr6.eq) goto loc_827727C0;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// bge cr6,0x827727d4
	if (!cr6.lt) goto loc_827727D4;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
loc_827727C0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82772338
	ctx.lr = 0x827727C8;
	sub_82772338(ctx, base);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277275c
	if (!cr6.eq) goto loc_8277275C;
loc_827727D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827727E0"))) PPC_WEAK_FUNC(sub_827727E0);
PPC_FUNC_IMPL(__imp__sub_827727E0) {
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
	ctx.lr = 0x827727E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82772150
	ctx.lr = 0x82772804;
	sub_82772150(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82772818
	if (cr6.eq) goto loc_82772818;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82772818:
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r31,r30,56
	r31.s64 = r30.s64 + 56;
	// lwz r10,56(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82772838
	if (cr6.lt) goto loc_82772838;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82772838:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827721e8
	ctx.lr = 0x82772848;
	sub_827721E8(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,52(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lbz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// clrlwi r3,r4,27
	ctx.r3.u64 = ctx.r4.u32 & 0x1F;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// stw r7,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r7.u32);
	// stb r3,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r3.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827728AC"))) PPC_WEAK_FUNC(sub_827728AC);
PPC_FUNC_IMPL(__imp__sub_827728AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827728B0"))) PPC_WEAK_FUNC(sub_827728B0);
PPC_FUNC_IMPL(__imp__sub_827728B0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827728B8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r31,-1
	r31.s64 = -1;
	// addi r9,r10,26844
	ctx.r9.s64 = ctx.r10.s64 + 26844;
	// li r30,0
	r30.s64 = 0;
	// lfs f31,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// stfs f31,4(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 4, temp.u32);
	// stw r31,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r31.u32);
	// stw r30,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r30.u32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82772388
	ctx.lr = 0x827728FC;
	sub_82772388(ctx, base);
	// lis r8,5461
	ctx.r8.s64 = 357892096;
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// stw r30,56(r28)
	PPC_STORE_U32(r28.u32 + 56, r30.u32);
	// ori r7,r8,21845
	ctx.r7.u64 = ctx.r8.u64 | 21845;
	// stw r29,60(r28)
	PPC_STORE_U32(r28.u32 + 60, r29.u32);
	// stw r30,64(r28)
	PPC_STORE_U32(r28.u32 + 64, r30.u32);
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bgt cr6,0x8277292c
	if (cr6.gt) goto loc_8277292C;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x82772930
	goto loc_82772930;
loc_8277292C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82772930:
	// bl 0x82130528
	ctx.lr = 0x82772934;
	sub_82130528(ctx, base);
	// lis r11,2730
	r11.s64 = 178913280;
	// stw r3,68(r28)
	PPC_STORE_U32(r28.u32 + 68, ctx.r3.u32);
	// ori r10,r11,43690
	ctx.r10.u64 = r11.u64 | 43690;
	// stw r30,76(r28)
	PPC_STORE_U32(r28.u32 + 76, r30.u32);
	// stw r30,80(r28)
	PPC_STORE_U32(r28.u32 + 80, r30.u32);
	// stw r29,48(r28)
	PPC_STORE_U32(r28.u32 + 48, r29.u32);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bgt cr6,0x82772964
	if (cr6.gt) goto loc_82772964;
	// rlwinm r11,r29,1,0,30
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// b 0x82772968
	goto loc_82772968;
loc_82772964:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82772968:
	// bl 0x82130528
	ctx.lr = 0x8277296C;
	sub_82130528(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82772a74
	if (cr6.eq) goto loc_82772A74;
	// addi r10,r29,-1
	ctx.r10.s64 = r29.s64 + -1;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// blt cr6,0x82772a28
	if (cr6.lt) goto loc_82772A28;
	// rlwinm r8,r9,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
loc_82772998:
	// lbz r6,44(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 44);
	// addi r8,r11,20
	ctx.r8.s64 = r11.s64 + 20;
	// lbz r5,68(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// stfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lbz r4,92(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// clrlwi r3,r6,27
	ctx.r3.u64 = ctx.r6.u32 & 0x1F;
	// lbz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// clrlwi r5,r5,27
	ctx.r5.u64 = ctx.r5.u32 & 0x1F;
	// clrlwi r4,r4,27
	ctx.r4.u64 = ctx.r4.u32 & 0x1F;
	// stfs f31,8(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// clrlwi r6,r6,27
	ctx.r6.u64 = ctx.r6.u32 & 0x1F;
	// stfs f31,28(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// stfs f31,32(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// stfs f31,52(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// stfs f31,56(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
	// stfs f31,76(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 76, temp.u32);
	// stw r30,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r30.u32);
	// stfs f31,80(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 80, temp.u32);
	// stw r31,36(r11)
	PPC_STORE_U32(r11.u32 + 36, r31.u32);
	// stw r31,40(r11)
	PPC_STORE_U32(r11.u32 + 40, r31.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r3,44(r11)
	PPC_STORE_U8(r11.u32 + 44, ctx.r3.u8);
	// stw r30,48(r11)
	PPC_STORE_U32(r11.u32 + 48, r30.u32);
	// stw r31,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r31.u32);
	// stw r31,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r31.u32);
	// stb r5,68(r11)
	PPC_STORE_U8(r11.u32 + 68, ctx.r5.u8);
	// stw r30,72(r11)
	PPC_STORE_U32(r11.u32 + 72, r30.u32);
	// stw r31,84(r11)
	PPC_STORE_U32(r11.u32 + 84, r31.u32);
	// stw r31,88(r11)
	PPC_STORE_U32(r11.u32 + 88, r31.u32);
	// stb r4,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r4.u8);
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// stb r6,0(r8)
	PPC_STORE_U8(ctx.r8.u32 + 0, ctx.r6.u8);
	// bne 0x82772998
	if (!cr0.eq) goto loc_82772998;
loc_82772A28:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82772a60
	if (cr6.lt) goto loc_82772A60;
loc_82772A30:
	// lbz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// addi r9,r11,20
	ctx.r9.s64 = r11.s64 + 20;
	// stfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// clrlwi r6,r8,27
	ctx.r6.u64 = ctx.r8.u32 & 0x1F;
	// stfs f31,8(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// stb r6,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r6.u8);
	// bge 0x82772a30
	if (!cr0.lt) goto loc_82772A30;
loc_82772A60:
	// stw r7,52(r28)
	PPC_STORE_U32(r28.u32 + 52, ctx.r7.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82772A74:
	// stw r30,52(r28)
	PPC_STORE_U32(r28.u32 + 52, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82772A88"))) PPC_WEAK_FUNC(sub_82772A88);
PPC_FUNC_IMPL(__imp__sub_82772A88) {
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
	ctx.lr = 0x82772A90;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,-1
	r11.s64 = -1;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// li r24,1
	r24.s64 = 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lwz r31,8(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,80(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lwz r28,76(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stb r24,108(r1)
	PPC_STORE_U8(ctx.r1.u32 + 108, r24.u8);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x82772aec
	if (!cr6.eq) goto loc_82772AEC;
loc_82772AE0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82772AEC:
	// addi r26,r30,16
	r26.s64 = r30.s64 + 16;
loc_82772AF0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// bl 0x82772150
	ctx.lr = 0x82772B0C;
	sub_82772150(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82772b1c
	if (cr6.eq) goto loc_82772B1C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82772b20
	goto loc_82772B20;
loc_82772B1C:
	// li r11,-1
	r11.s64 = -1;
loc_82772B20:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x82772bbc
	if (cr6.eq) goto loc_82772BBC;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82772ae0
	if (cr6.eq) goto loc_82772AE0;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82772B70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82772af0
	if (!cr6.eq) goto loc_82772AF0;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82772bc8
	if (cr6.eq) goto loc_82772BC8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8276bc08
	ctx.lr = 0x82772B90;
	sub_8276BC08(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82772BA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82772bc8
	if (cr6.eq) goto loc_82772BC8;
	// li r24,0
	r24.s64 = 0;
	// b 0x82772af0
	goto loc_82772AF0;
loc_82772BBC:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82772BC8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82772BD4"))) PPC_WEAK_FUNC(sub_82772BD4);
PPC_FUNC_IMPL(__imp__sub_82772BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82772BD8"))) PPC_WEAK_FUNC(sub_82772BD8);
PPC_FUNC_IMPL(__imp__sub_82772BD8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82772BE0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x827727e0
	ctx.lr = 0x82772C04;
	sub_827727E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82772ce4
	if (cr6.lt) goto loc_82772CE4;
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82772C28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82772c90
	if (cr6.eq) goto loc_82772C90;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82772ce4
	if (!cr6.gt) goto loc_82772CE4;
	// lfs f0,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stfs f31,4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r27,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r27.u32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// li r8,12
	ctx.r8.s64 = 12;
	// addi r3,r30,60
	ctx.r3.s64 = r30.s64 + 60;
	// divw r4,r9,r8
	ctx.r4.s32 = ctx.r9.s32 / ctx.r8.s32;
	// bl 0x82771e38
	ctx.lr = 0x82772C84;
	sub_82771E38(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82772C90:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82772ca8
	if (cr6.eq) goto loc_82772CA8;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82772ce4
	if (!cr6.gt) goto loc_82772CE4;
loc_82772CA8:
	// stfs f31,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stw r27,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r27.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82772CCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// fadds f1,f1,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 + f31.f64));
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r30,60
	ctx.r3.s64 = r30.s64 + 60;
	// bl 0x82771fa8
	ctx.lr = 0x82772CE4;
	sub_82771FA8(ctx, base);
loc_82772CE4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82772CF0"))) PPC_WEAK_FUNC(sub_82772CF0);
PPC_FUNC_IMPL(__imp__sub_82772CF0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82772CF8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827727e0
	ctx.lr = 0x82772D18;
	sub_827727E0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82772d6c
	if (cr6.lt) goto loc_82772D6C;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82772D3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f31,4(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stw r28,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r28.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stw r7,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r7.u32);
loc_82772D6C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82772D78"))) PPC_WEAK_FUNC(sub_82772D78);
PPC_FUNC_IMPL(__imp__sub_82772D78) {
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
	ctx.lr = 0x82772D80;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// li r26,-1
	r26.s64 = -1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82772080
	ctx.lr = 0x82772DB8;
	sub_82772080(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82772dd0
	if (!cr6.eq) goto loc_82772DD0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82772DD0:
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x827727e0
	ctx.lr = 0x82772DE0;
	sub_827727E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82772df4
	if (!cr6.lt) goto loc_82772DF4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82772DF4:
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r9,0
	ctx.r9.s64 = 0;
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r7,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r7.u32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82772E34"))) PPC_WEAK_FUNC(sub_82772E34);
PPC_FUNC_IMPL(__imp__sub_82772E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82772E38"))) PPC_WEAK_FUNC(sub_82772E38);
PPC_FUNC_IMPL(__imp__sub_82772E38) {
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
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x82772e6c
	if (!cr6.eq) goto loc_82772E6C;
loc_82772E54:
	// li r3,-1
	ctx.r3.s64 = -1;
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
loc_82772E6C:
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82772150
	ctx.lr = 0x82772E7C;
	sub_82772150(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82772e54
	if (cr6.eq) goto loc_82772E54;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82772e54
	if (cr6.lt) goto loc_82772E54;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
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

__attribute__((alias("__imp__sub_82772EBC"))) PPC_WEAK_FUNC(sub_82772EBC);
PPC_FUNC_IMPL(__imp__sub_82772EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82772EC0"))) PPC_WEAK_FUNC(sub_82772EC0);
PPC_FUNC_IMPL(__imp__sub_82772EC0) {
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
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x82772ef4
	if (!cr6.eq) goto loc_82772EF4;
loc_82772EDC:
	// li r3,-1
	ctx.r3.s64 = -1;
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
loc_82772EF4:
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82772150
	ctx.lr = 0x82772F04;
	sub_82772150(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82772edc
	if (cr6.eq) goto loc_82772EDC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82772edc
	if (cr6.lt) goto loc_82772EDC;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
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

__attribute__((alias("__imp__sub_82772F44"))) PPC_WEAK_FUNC(sub_82772F44);
PPC_FUNC_IMPL(__imp__sub_82772F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82772F48"))) PPC_WEAK_FUNC(sub_82772F48);
PPC_FUNC_IMPL(__imp__sub_82772F48) {
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82772150
	ctx.lr = 0x82772F6C;
	sub_82772150(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82772f80
	if (cr6.eq) goto loc_82772F80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82772f98
	if (!cr6.lt) goto loc_82772F98;
loc_82772F80:
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
loc_82772F98:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lbz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20);
	// rlwinm r3,r9,25,7,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
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

__attribute__((alias("__imp__sub_82772FC8"))) PPC_WEAK_FUNC(sub_82772FC8);
PPC_FUNC_IMPL(__imp__sub_82772FC8) {
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82772150
	ctx.lr = 0x82772FEC;
	sub_82772150(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82773000
	if (cr6.eq) goto loc_82773000;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82773018
	if (!cr6.lt) goto loc_82773018;
loc_82773000:
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
loc_82773018:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lbz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20);
	// rlwinm r3,r9,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x1;
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

__attribute__((alias("__imp__sub_82773048"))) PPC_WEAK_FUNC(sub_82773048);
PPC_FUNC_IMPL(__imp__sub_82773048) {
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
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82772150
	ctx.lr = 0x8277306C;
	sub_82772150(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82773080
	if (cr6.eq) goto loc_82773080;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82773098
	if (!cr6.lt) goto loc_82773098;
loc_82773080:
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
loc_82773098:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lbz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
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

__attribute__((alias("__imp__sub_827730C8"))) PPC_WEAK_FUNC(sub_827730C8);
PPC_FUNC_IMPL(__imp__sub_827730C8) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x827727e0
	ctx.lr = 0x827730E8;
	sub_827727E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82773114
	if (cr6.lt) goto loc_82773114;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,20
	ctx.r10.s64 = r11.s64 + 20;
	// lbz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// rlwimi r10,r30,7,17,24
	ctx.r10.u64 = (__builtin_rotateleft32(r30.u32, 7) & 0x7F80) | (ctx.r10.u64 & 0xFFFFFFFFFFFF807F);
	// stb r10,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r10.u8);
loc_82773114:
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

__attribute__((alias("__imp__sub_8277312C"))) PPC_WEAK_FUNC(sub_8277312C);
PPC_FUNC_IMPL(__imp__sub_8277312C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82773130"))) PPC_WEAK_FUNC(sub_82773130);
PPC_FUNC_IMPL(__imp__sub_82773130) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x827727e0
	ctx.lr = 0x82773150;
	sub_827727E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82773180
	if (cr6.lt) goto loc_82773180;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,20
	ctx.r10.s64 = r11.s64 + 20;
	// lbz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// rlwimi r7,r9,6,25,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 6) & 0x40) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r7,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r7.u8);
loc_82773180:
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

__attribute__((alias("__imp__sub_82773198"))) PPC_WEAK_FUNC(sub_82773198);
PPC_FUNC_IMPL(__imp__sub_82773198) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x827727e0
	ctx.lr = 0x827731B8;
	sub_827727E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x827731e8
	if (cr6.lt) goto loc_827731E8;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,20
	ctx.r10.s64 = r11.s64 + 20;
	// lbz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// rlwimi r7,r9,5,26,26
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x20) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r7,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r7.u8);
loc_827731E8:
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

__attribute__((alias("__imp__sub_82773200"))) PPC_WEAK_FUNC(sub_82773200);
PPC_FUNC_IMPL(__imp__sub_82773200) {
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
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82773244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8276e868
	ctx.lr = 0x82773250;
	sub_8276E868(ctx, base);
	// lbz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r5,r31,12
	ctx.r5.s64 = r31.s64 + 12;
	// rlwimi r8,r7,6,25,25
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 6) & 0x40) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFBF);
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// clrlwi r6,r8,25
	ctx.r6.u64 = ctx.r8.u32 & 0x7F;
	// stb r6,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r6.u8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773280;
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

__attribute__((alias("__imp__sub_82773294"))) PPC_WEAK_FUNC(sub_82773294);
PPC_FUNC_IMPL(__imp__sub_82773294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82773298"))) PPC_WEAK_FUNC(sub_82773298);
PPC_FUNC_IMPL(__imp__sub_82773298) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8276e880
	ctx.lr = 0x827732B4;
	sub_8276E880(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827732C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
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

__attribute__((alias("__imp__sub_82773304"))) PPC_WEAK_FUNC(sub_82773304);
PPC_FUNC_IMPL(__imp__sub_82773304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82773308"))) PPC_WEAK_FUNC(sub_82773308);
PPC_FUNC_IMPL(__imp__sub_82773308) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82773310;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d4
	ctx.lr = 0x82773318;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// fmr f31,f2
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f2.f64;
	// fmr f27,f1
	f27.f64 = ctx.f1.f64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r23,4(r25)
	r23.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82773384
	if (cr6.eq) goto loc_82773384;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba20
	ctx.lr = 0x82773380;
	// b 0x823d9234
	return;
loc_82773384:
	// lwz r31,16(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
	// bl 0x827620b0
	ctx.lr = 0x827733A4;
	sub_827620B0(ctx, base);
	// lwz r10,20(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827733C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r30,r3,24
	r30.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82773400
	if (!cr6.eq) goto loc_82773400;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827733F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82773404
	if (cr6.eq) goto loc_82773404;
loc_82773400:
	// li r11,1
	r11.s64 = 1;
loc_82773404:
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82773440
	if (!cr6.eq) goto loc_82773440;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82773444
	if (cr6.eq) goto loc_82773444;
loc_82773440:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82773444:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8277345c
	if (cr6.eq) goto loc_8277345C;
	// lwz r29,48(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 48);
loc_8277345C:
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stb r27,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r27.u8);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82773498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x827735a4
	if (cr6.eq) goto loc_827735A4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f29,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lfs f28,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f28.f64 = double(temp.f32);
loc_827734B4:
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f30,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f30.f64 = double(temp.f32);
	// lwz r27,88(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// fmr f31,f28
	f31.f64 = f28.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82773530
	if (cr6.eq) goto loc_82773530;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827734E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82773530
	if (cr6.eq) goto loc_82773530;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773508;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82773580
	if (cr6.eq) goto loc_82773580;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277352C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
loc_82773530:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// blt cr6,0x82773580
	if (cr6.lt) goto loc_82773580;
	// lwz r3,20(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// fadds f1,f0,f27
	ctx.f1.f64 = double(float(f0.f64 + f27.f64));
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82773580:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82773598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827734b4
	if (!cr6.eq) goto loc_827734B4;
loc_827735A4:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827620f8
	ctx.lr = 0x827735B0;
	sub_827620F8(ctx, base);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba20
	ctx.lr = 0x827735CC;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_827735D0"))) PPC_WEAK_FUNC(sub_827735D0);
PPC_FUNC_IMPL(__imp__sub_827735D0) {
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
	ctx.lr = 0x827735D8;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d8
	ctx.lr = 0x827735E0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82773868
	if (!cr6.eq) goto loc_82773868;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82773868
	if (!cr6.eq) goto loc_82773868;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82773630
	if (!cr6.eq) goto loc_82773630;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba24
	ctx.lr = 0x8277362C;
	// b 0x823d923c
	return;
loc_82773630:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82773630
	if (cr6.eq) goto loc_82773630;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r29,4(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r27,0
	r27.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
	// lis r28,-32243
	r28.s64 = -2113077248;
	// lfs f28,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f28.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f29,-31400(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f29.f64 = double(temp.f32);
	// fmr f31,f28
	f31.f64 = f28.f64;
	// lfs f30,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f30.f64 = double(temp.f32);
loc_82773670:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82773684
	if (cr6.lt) goto loc_82773684;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// bge cr6,0x827737f8
	if (!cr6.lt) goto loc_827737F8;
loc_82773684:
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// blt cr6,0x82773698
	if (cr6.lt) goto loc_82773698;
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x827737f8
	if (!cr6.lt) goto loc_827737F8;
loc_82773698:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82773698
	if (cr6.eq) goto loc_82773698;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stfs f30,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827736D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f1,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lfs f2,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// li r11,0
	r11.s64 = 0;
	// bge cr6,0x8277370c
	if (!cr6.lt) goto loc_8277370C;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fmadds f12,f13,f2,f1
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f2.f64 + ctx.f1.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x82773708
	if (cr6.gt) goto loc_82773708;
	// li r11,0
	r11.s64 = 0;
loc_82773708:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8277370C:
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8277378c
	if (cr6.eq) goto loc_8277378C;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277378c
	if (!cr6.eq) goto loc_8277378C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82773308
	ctx.lr = 0x82773728;
	sub_82773308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277376c
	if (!cr6.eq) goto loc_8277376C;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_82773738:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82773738
	if (cr6.eq) goto loc_82773738;
	// ld r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f0,27184(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 27184);
	f0.f64 = double(temp.f32);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f31,f11,f0,f31
	f31.f64 = double(float(ctx.f11.f64 * f0.f64 + f31.f64));
	// b 0x82773670
	goto loc_82773670;
loc_8277376C:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
loc_82773778:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82773778
	if (cr6.eq) goto loc_82773778;
	// b 0x827737d8
	goto loc_827737D8;
loc_8277378C:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827737AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x827737c8
	if (cr6.eq) goto loc_827737C8;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,6,0,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0xFFFFFFC0) | (r11.u64 & 0xFFFFFFFF0000003F);
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
loc_827737C8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827737c8
	if (cr6.eq) goto loc_827737C8;
loc_827737D8:
	// ld r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f0,27184(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 27184);
	f0.f64 = double(temp.f32);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f31,f11,f0,f31
	f31.f64 = double(float(ctx.f11.f64 * f0.f64 + f31.f64));
loc_827737F8:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8277380c
	if (cr6.lt) goto loc_8277380C;
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8277380C:
	// lfs f0,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// blt cr6,0x8277382c
	if (cr6.lt) goto loc_8277382C;
	// fsubs f0,f0,f31
	f0.f64 = double(float(f0.f64 - f31.f64));
	// stfs f0,0(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8277382c
	if (!cr6.lt) goto loc_8277382C;
	// stfs f28,0(r25)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
loc_8277382C:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82773850
	if (!cr6.eq) goto loc_82773850;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82773854
	if (cr6.eq) goto loc_82773854;
loc_82773850:
	// li r11,1
	r11.s64 = 1;
loc_82773854:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba24
	ctx.lr = 0x82773864;
	// b 0x823d923c
	return;
loc_82773868:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba24
	ctx.lr = 0x82773878;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277387C"))) PPC_WEAK_FUNC(sub_8277387C);
PPC_FUNC_IMPL(__imp__sub_8277387C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82773880"))) PPC_WEAK_FUNC(sub_82773880);
PPC_FUNC_IMPL(__imp__sub_82773880) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r11,0
	r11.s64 = 0;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,44(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// lwz r6,32(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// stw r4,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r4.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827738D0"))) PPC_WEAK_FUNC(sub_827738D0);
PPC_FUNC_IMPL(__imp__sub_827738D0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827738D8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8276bf08
	ctx.lr = 0x827738F0;
	sub_8276BF08(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277390c
	if (cr6.eq) goto loc_8277390C;
loc_827738FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8277390C:
	// lhz r11,40(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 40);
	// lfs f31,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f31.f64 = double(temp.f32);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x827739a8
	if (!cr6.gt) goto loc_827739A8;
	// li r30,48
	r30.s64 = 48;
	// li r27,-1
	r27.s64 = -1;
loc_82773928:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82773994
	if (cr6.eq) goto loc_82773994;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bne cr6,0x82773970
	if (!cr6.eq) goto loc_82773970;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r6,32(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// bl 0x8276c058
	ctx.lr = 0x82773964;
	sub_8276C058(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// b 0x82773990
	goto loc_82773990;
loc_82773970:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r9,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x8276c1b8
	ctx.lr = 0x82773988;
	sub_8276C1B8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
loc_82773990:
	// beq cr6,0x827738fc
	if (cr6.eq) goto loc_827738FC;
loc_82773994:
	// lhz r11,40(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 40);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,48
	r30.s64 = r30.s64 + 48;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82773928
	if (cr6.lt) goto loc_82773928;
loc_827739A8:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827739d8
	if (cr6.eq) goto loc_827739D8;
loc_827739B8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8276bff0
	ctx.lr = 0x827739C4;
	sub_8276BFF0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827739d8
	if (cr6.eq) goto loc_827739D8;
	// lwz r31,48(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827739b8
	if (!cr6.eq) goto loc_827739B8;
loc_827739D8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827739E8"))) PPC_WEAK_FUNC(sub_827739E8);
PPC_FUNC_IMPL(__imp__sub_827739E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lhz r11,42(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 42);
	// lhz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 40);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82773a08
	if (cr6.lt) goto loc_82773A08;
	// li r11,1
	r11.s64 = 1;
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// blr 
	return;
loc_82773A08:
	// lhz r11,40(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 40);
	// addi r10,r3,36
	ctx.r10.s64 = ctx.r3.s64 + 36;
	// lwz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r8,0
	ctx.r8.s64 = 0;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// sth r31,40(r3)
	PPC_STORE_U16(ctx.r3.u32 + 40, r31.u16);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// stb r8,36(r11)
	PPC_STORE_U8(r11.u32 + 36, ctx.r8.u8);
	// stw r7,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r7.u32);
	// lbz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 52);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82773ab4
	if (cr6.eq) goto loc_82773AB4;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82773ab4
	if (cr6.eq) goto loc_82773AB4;
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r10,16
	ctx.r10.s64 = 16;
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f9,f9,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f8
	cr6.compare(ctx.f6.f64, ctx.f8.f64);
	// ble cr6,0x82773a98
	if (!cr6.gt) goto loc_82773A98;
	// stw r8,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r8.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_82773A98:
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_82773AB4:
	// stw r8,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r8.u32);
	// lvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// stvx128 v59,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r4
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82773AD4"))) PPC_WEAK_FUNC(sub_82773AD4);
PPC_FUNC_IMPL(__imp__sub_82773AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82773AD8"))) PPC_WEAK_FUNC(sub_82773AD8);
PPC_FUNC_IMPL(__imp__sub_82773AD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lbz r11,52(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82773c38
	if (cr6.eq) goto loc_82773C38;
	// lbz r11,53(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 53);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82773c38
	if (cr6.eq) goto loc_82773C38;
	// lhz r11,40(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 40);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f9,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// ble 0x82773c38
	if (!cr0.gt) goto loc_82773C38;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f10,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
loc_82773B1C:
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// lwz r8,40(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r7,88(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r6,r6,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// rlwinm r5,r5,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// beq cr6,0x82773c2c
	if (cr6.eq) goto loc_82773C2C;
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r7,32(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// bne cr6,0x82773c2c
	if (!cr6.eq) goto loc_82773C2C;
	// lfs f0,16(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	f0.f64 = double(temp.f32);
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f8,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// addi r7,r11,16
	ctx.r7.s64 = r11.s64 + 16;
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f12,f6,f6,f5
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// beq cr6,0x82773ba8
	if (cr6.eq) goto loc_82773BA8;
	// fmr f13,f9
	ctx.f13.f64 = ctx.f9.f64;
	// b 0x82773bac
	goto loc_82773BAC;
loc_82773BA8:
	// fmr f13,f11
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f11.f64;
loc_82773BAC:
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82773bc0
	if (cr6.eq) goto loc_82773BC0;
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f9.f64;
	// b 0x82773bc4
	goto loc_82773BC4;
loc_82773BC0:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f11.f64;
loc_82773BC4:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fadds f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 + ctx.f10.f64));
	// fmuls f8,f13,f13
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f8
	cr6.compare(ctx.f12.f64, ctx.f8.f64);
	// bgt cr6,0x82773c2c
	if (cr6.gt) goto loc_82773C2C;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82773c20
	if (cr6.eq) goto loc_82773C20;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82773bf8
	if (cr6.eq) goto loc_82773BF8;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82773c28
	goto loc_82773C28;
loc_82773BF8:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82773c20
	if (cr6.eq) goto loc_82773C20;
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r4.u32);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bgt cr6,0x82773c2c
	if (cr6.gt) goto loc_82773C2C;
	// li r9,-1
	ctx.r9.s64 = -1;
	// b 0x82773c2c
	goto loc_82773C2C;
loc_82773C20:
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82773C28:
	// stw r4,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r4.u32);
loc_82773C2C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r9,r31
	cr6.compare<int32_t>(ctx.r9.s32, r31.s32, xer);
	// blt cr6,0x82773b1c
	if (cr6.lt) goto loc_82773B1C;
loc_82773C38:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82773C40"))) PPC_WEAK_FUNC(sub_82773C40);
PPC_FUNC_IMPL(__imp__sub_82773C40) {
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
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x82773C64;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82773c8c
	if (!cr6.gt) goto loc_82773C8C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82773C74:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82773c80
	if (cr6.eq) goto loc_82773C80;
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
loc_82773C80:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// bne 0x82773c74
	if (!cr0.eq) goto loc_82773C74;
loc_82773C8C:
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

__attribute__((alias("__imp__sub_82773CA0"))) PPC_WEAK_FUNC(sub_82773CA0);
PPC_FUNC_IMPL(__imp__sub_82773CA0) {
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
	// addi r10,r11,27236
	ctx.r10.s64 = r11.s64 + 27236;
	// lwz r30,28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82773ce0
	if (cr6.eq) goto loc_82773CE0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82773CD8;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82773CE0;
	sub_82130588(ctx, base);
loc_82773CE0:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82773CE8;
	sub_82130588(ctx, base);
	// lhz r11,42(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82773cfc
	if (cr6.eq) goto loc_82773CFC;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x82130588
	ctx.lr = 0x82773CFC;
	sub_82130588(ctx, base);
loc_82773CFC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82773D04;
	sub_821D2028(ctx, base);
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

__attribute__((alias("__imp__sub_82773D1C"))) PPC_WEAK_FUNC(sub_82773D1C);
PPC_FUNC_IMPL(__imp__sub_82773D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82773D20"))) PPC_WEAK_FUNC(sub_82773D20);
PPC_FUNC_IMPL(__imp__sub_82773D20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82773D34"))) PPC_WEAK_FUNC(sub_82773D34);
PPC_FUNC_IMPL(__imp__sub_82773D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82773D38"))) PPC_WEAK_FUNC(sub_82773D38);
PPC_FUNC_IMPL(__imp__sub_82773D38) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82773D40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// addi r8,r10,27236
	ctx.r8.s64 = ctx.r10.s64 + 27236;
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// addi r29,r31,36
	r29.s64 = r31.s64 + 36;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// sth r30,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r30.u16);
	// sth r30,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r30.u16);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stb r30,52(r31)
	PPC_STORE_U8(r31.u32 + 52, r30.u8);
	// stb r7,53(r31)
	PPC_STORE_U8(r31.u32 + 53, ctx.r7.u8);
	// bl 0x82130528
	ctx.lr = 0x82773DAC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82773dc0
	if (cr6.eq) goto loc_82773DC0;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// b 0x82773dc4
	goto loc_82773DC4;
loc_82773DC0:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82773DC4:
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x82773DD0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82773de0
	if (cr6.eq) goto loc_82773DE0;
	// bl 0x82774c80
	ctx.lr = 0x82773DDC;
	sub_82774C80(ctx, base);
	// b 0x82773de4
	goto loc_82773DE4;
loc_82773DE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82773DE4:
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82773e10
	if (cr6.eq) goto loc_82773E10;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82773c40
	ctx.lr = 0x82773DFC;
	sub_82773C40(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r28,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r28.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82773E10:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r28,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r28.u16);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82773E28"))) PPC_WEAK_FUNC(sub_82773E28);
PPC_FUNC_IMPL(__imp__sub_82773E28) {
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
	// bl 0x82773ca0
	ctx.lr = 0x82773E48;
	sub_82773CA0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82773e60
	if (cr6.eq) goto loc_82773E60;
	// bl 0x82130588
	ctx.lr = 0x82773E5C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82773E60:
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

__attribute__((alias("__imp__sub_82773E78"))) PPC_WEAK_FUNC(sub_82773E78);
PPC_FUNC_IMPL(__imp__sub_82773E78) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82773E80;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r27,16(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lfs f0,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f13,14196(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14196);
	ctx.f13.f64 = double(temp.f32);
	// stw r27,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r27.u32);
	// lfs f1,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4(r27)
	PPC_STORE_U32(r27.u32 + 4, ctx.r6.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// stw r4,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r4.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f12,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r11,16
	ctx.r5.s64 = r11.s64 + 16;
	// fmadds f10,f12,f0,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f11.f64));
	// stfs f10,44(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// fadds f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// fmuls f8,f9,f9
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// stfs f8,48(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// bl 0x82774ca0
	ctx.lr = 0x82773F0C;
	sub_82774CA0(ctx, base);
	// lhz r11,42(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// addi r29,r31,36
	r29.s64 = r31.s64 + 36;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82773f24
	if (!cr6.eq) goto loc_82773F24;
	// sth r28,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r28.u16);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
loc_82773F24:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// lhz r10,42(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// li r26,1
	r26.s64 = 1;
	// lhz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 40);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// lwz r8,-1768(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -1768);
	// blt cr6,0x82773f4c
	if (cr6.lt) goto loc_82773F4C;
	// stb r26,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r26.u8);
	// b 0x82773f8c
	goto loc_82773F8C;
loc_82773F4C:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// sth r6,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r6.u16);
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// stb r28,36(r11)
	PPC_STORE_U8(r11.u32 + 36, r28.u8);
	// stw r28,40(r11)
	PPC_STORE_U32(r11.u32 + 40, r28.u32);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82773F8C:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82761858
	ctx.lr = 0x82773F94;
	sub_82761858(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82761878
	ctx.lr = 0x82773FA0;
	sub_82761878(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82761858
	ctx.lr = 0x82773FA8;
	sub_82761858(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82774c68
	ctx.lr = 0x82773FB0;
	sub_82774C68(ctx, base);
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// addi r10,r1,108
	ctx.r10.s64 = ctx.r1.s64 + 108;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// bl 0x82774d60
	ctx.lr = 0x82773FEC;
	sub_82774D60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827740b0
	if (cr6.eq) goto loc_827740B0;
loc_82773FF8:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lwz r7,140(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x827739e8
	ctx.lr = 0x82774020;
	sub_827739E8(ctx, base);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827740b0
	if (!cr6.eq) goto loc_827740B0;
	// lbz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827740a8
	if (!cr6.eq) goto loc_827740A8;
	// lbz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827740a8
	if (!cr6.eq) goto loc_827740A8;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x827740a8
	if (cr6.eq) goto loc_827740A8;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,108
	ctx.r10.s64 = ctx.r1.s64 + 108;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82774d60
	ctx.lr = 0x82774098;
	sub_82774D60(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82773ff8
	if (!cr6.eq) goto loc_82773FF8;
	// b 0x827740b0
	goto loc_827740B0;
loc_827740A8:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_827740B0:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82774cc8
	ctx.lr = 0x827740B8;
	sub_82774CC8(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r11,2
	r11.s64 = 2;
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r26,36(r10)
	PPC_STORE_U8(ctx.r10.u32 + 36, r26.u8);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// bl 0x82773ad8
	ctx.lr = 0x827740D8;
	sub_82773AD8(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827740E0"))) PPC_WEAK_FUNC(sub_827740E0);
PPC_FUNC_IMPL(__imp__sub_827740E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x827740E8;
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -176, f29.u64);
	// stfd f30,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r14,r4
	r14.u64 = ctx.r4.u64;
	// mr r17,r5
	r17.u64 = ctx.r5.u64;
loc_82774104:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82774104
	if (cr6.eq) goto loc_82774104;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,0(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r20,1
	r20.s64 = 1;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r21,0
	r21.s64 = 0;
	// mr r15,r20
	r15.u64 = r20.u64;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8277413c
	if (!cr6.lt) goto loc_8277413C;
	// mr r15,r21
	r15.u64 = r21.u64;
loc_8277413C:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lfs f29,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 44);
	f29.f64 = double(temp.f32);
	// lwz r24,88(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r23,r21
	r23.u64 = r21.u64;
	// lis r18,-32243
	r18.s64 = -2113077248;
	// li r19,16
	r19.s64 = 16;
	// li r16,2
	r16.s64 = 2;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r22,48(r10)
	r22.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lfs f30,-31408(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31408);
	f30.f64 = double(temp.f32);
loc_82774168:
	// lhz r11,40(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 40);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x827746cc
	if (!cr6.lt) goto loc_827746CC;
loc_82774178:
	// cmpw cr6,r23,r14
	cr6.compare<int32_t>(r23.s32, r14.s32, xer);
	// bge cr6,0x827747e0
	if (!cr6.lt) goto loc_827747E0;
	// clrlwi r11,r15,24
	r11.u64 = r15.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827741d0
	if (cr6.eq) goto loc_827741D0;
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// blt cr6,0x827741d0
	if (cr6.lt) goto loc_827741D0;
loc_82774194:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82774194
	if (cr6.eq) goto loc_82774194;
	// ld r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f0,27216(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r18.u32 + 27216);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bge cr6,0x827747e0
	if (!cr6.lt) goto loc_827747E0;
loc_827741D0:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r31,0(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r9,r7,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r27,r9,r11
	r27.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,32(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// lwz r28,32(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplw cr6,r28,r5
	cr6.compare<uint32_t>(r28.u32, ctx.r5.u32, xer);
	// bne cr6,0x82774664
	if (!cr6.eq) goto loc_82774664;
	// addi r26,r29,16
	r26.s64 = r29.s64 + 16;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82761a18
	ctx.lr = 0x82774224;
	sub_82761A18(ctx, base);
	// addi r11,r1,256
	r11.s64 = ctx.r1.s64 + 256;
	// addi r25,r27,16
	r25.s64 = r27.s64 + 16;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82761a18
	ctx.lr = 0x8277423C;
	sub_82761A18(ctx, base);
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,24(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 24);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fsubs f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f8,f10,f10
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f30
	cr6.compare(ctx.f7.f64, f30.f64);
	// bge cr6,0x82774274
	if (!cr6.lt) goto loc_82774274;
	// mr r26,r20
	r26.u64 = r20.u64;
	// b 0x82774480
	goto loc_82774480;
loc_82774274:
	// lbz r11,52(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277444c
	if (cr6.eq) goto loc_8277444C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,32(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// bl 0x82761a18
	ctx.lr = 0x8277428C;
	sub_82761A18(ctx, base);
	// addi r11,r1,304
	r11.s64 = ctx.r1.s64 + 304;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,32(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// bl 0x82761a18
	ctx.lr = 0x827742A0;
	sub_82761A18(ctx, base);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827742bc
	if (cr6.eq) goto loc_827742BC;
	// stfs f29,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// b 0x827742c0
	goto loc_827742C0;
loc_827742BC:
	// stfs f31,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
loc_827742C0:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r9.u8);
	// bl 0x8276b388
	ctx.lr = 0x827742DC;
	sub_8276B388(ctx, base);
	// lwz r11,40(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827742f0
	if (cr6.eq) goto loc_827742F0;
	// stfs f29,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// b 0x827742f4
	goto loc_827742F4;
loc_827742F0:
	// stfs f31,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
loc_827742F4:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r9.u8);
	// bl 0x8276b388
	ctx.lr = 0x82774310;
	sub_8276B388(ctx, base);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8276b618
	ctx.lr = 0x82774324;
	sub_8276B618(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// clrlwi r8,r26,24
	ctx.r8.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82774390
	if (cr6.eq) goto loc_82774390;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmuls f8,f12,f12
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f30
	cr6.compare(ctx.f7.f64, f30.f64);
	// ble cr6,0x82774390
	if (!cr6.gt) goto loc_82774390;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277438C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_82774390:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827743f0
	if (cr6.eq) goto loc_827743F0;
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827743f0
	if (cr6.eq) goto loc_827743F0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,32(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// bl 0x82761a18
	ctx.lr = 0x827743B8;
	sub_82761A18(ctx, base);
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,72(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827743EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_827743F0:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82774480
	if (cr6.eq) goto loc_82774480;
	// lwz r11,40(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82774480
	if (cr6.eq) goto loc_82774480;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,32(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// bl 0x82761a18
	ctx.lr = 0x82774418;
	sub_82761A18(ctx, base);
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,72(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r11
	ctr.u64 = r11.u64;
	// b 0x82774478
	goto loc_82774478;
loc_8277444C:
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82774478:
	// bctrl 
	ctx.lr = 0x8277447C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_82774480:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82774668
	if (cr6.eq) goto loc_82774668;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x82774668
	if (cr6.eq) goto loc_82774668;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r21
	r29.u64 = r21.u64;
	// bl 0x82761f20
	ctx.lr = 0x827744A0;
	sub_82761F20(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// mr r28,r21
	r28.u64 = r21.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r27,r21
	r27.u64 = r21.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r3,r11,-48
	ctx.r3.s64 = r11.s64 + -48;
	// lwz r4,-16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -16);
	// bl 0x82761a18
	ctx.lr = 0x827744CC;
	sub_82761A18(ctx, base);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82761e50
	ctx.lr = 0x827744DC;
	sub_82761E50(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,32(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82774500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82774500:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bne cr6,0x82774514
	if (!cr6.eq) goto loc_82774514;
	// mr r11,r21
	r11.u64 = r21.u64;
	// b 0x82774528
	goto loc_82774528;
loc_82774514:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r9,r29,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// mr r11,r20
	r11.u64 = r20.u64;
	// lwzx r24,r9,r10
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_82774528:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82774574
	if (cr6.eq) goto loc_82774574;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r28,0(r22)
	r28.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82774550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82774564;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82774500
	if (cr6.eq) goto loc_82774500;
loc_82774574:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82761e68
	ctx.lr = 0x8277457C;
	sub_82761E68(ctx, base);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// mr r28,r21
	r28.u64 = r21.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82774668
	if (cr6.eq) goto loc_82774668;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82761e50
	ctx.lr = 0x82774594;
	sub_82761E50(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// lwz r4,32(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// bl 0x82761a18
	ctx.lr = 0x827745B4;
	sub_82761A18(ctx, base);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827745E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827745E0:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bne cr6,0x827745f4
	if (!cr6.eq) goto loc_827745F4;
	// mr r11,r21
	r11.u64 = r21.u64;
	// b 0x82774608
	goto loc_82774608;
loc_827745F4:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r9,r28,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// mr r11,r20
	r11.u64 = r20.u64;
	// lwzx r24,r9,r10
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_82774608:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82774654
	if (cr6.eq) goto loc_82774654;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r29,0(r22)
	r29.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82774630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82774644;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827745e0
	if (cr6.eq) goto loc_827745E0;
loc_82774654:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82761e68
	ctx.lr = 0x8277465C;
	sub_82761E68(ctx, base);
	// mr r26,r27
	r26.u64 = r27.u64;
	// b 0x82774668
	goto loc_82774668;
loc_82774664:
	// mr r26,r21
	r26.u64 = r21.u64;
loc_82774668:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// beq cr6,0x82774690
	if (cr6.eq) goto loc_82774690;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r10,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r10.u32);
	// stw r9,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r9.u32);
	// b 0x827746bc
	goto loc_827746BC;
loc_82774690:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stb r20,36(r10)
	PPC_STORE_U8(ctx.r10.u32 + 36, r20.u8);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r9.u32);
loc_827746BC:
	// lhz r11,40(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 40);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82774178
	if (cr6.lt) goto loc_82774178;
loc_827746CC:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lhz r10,40(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 40);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x827746f4
	if (cr6.gt) goto loc_827746F4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stb r20,-12(r10)
	PPC_STORE_U8(ctx.r10.u32 + -12, r20.u8);
loc_827746F4:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82774848
	if (cr6.eq) goto loc_82774848;
	// lhz r11,40(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 40);
	// mr r29,r21
	r29.u64 = r21.u64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277478c
	if (cr6.eq) goto loc_8277478C;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
loc_8277471C:
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// add r11,r10,r8
	r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbz r6,36(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82774778
	if (cr6.eq) goto loc_82774778;
	// cmpw cr6,r7,r29
	cr6.compare<int32_t>(ctx.r7.s32, r29.s32, xer);
	// beq cr6,0x82774764
	if (cr6.eq) goto loc_82774764;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r19
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r19
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,32(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// stw r6,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r6.u32);
	// lbz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// stb r5,36(r10)
	PPC_STORE_U8(ctx.r10.u32 + 36, ctx.r5.u8);
	// lwz r4,40(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// stw r4,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r4.u32);
loc_82774764:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// stb r21,36(r11)
	PPC_STORE_U8(r11.u32 + 36, r21.u8);
loc_82774778:
	// lhz r11,40(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 40);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x8277471c
	if (cr6.lt) goto loc_8277471C;
loc_8277478C:
	// lhz r11,42(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 42);
	// addi r31,r30,36
	r31.s64 = r30.s64 + 36;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827747c0
	if (!cr6.eq) goto loc_827747C0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// beq cr6,0x827747b8
	if (cr6.eq) goto loc_827747B8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82773c40
	ctx.lr = 0x827747B4;
	sub_82773C40(ctx, base);
	// b 0x827747bc
	goto loc_827747BC;
loc_827747B8:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
loc_827747BC:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_827747C0:
	// clrlwi r11,r29,16
	r11.u64 = r29.u32 & 0xFFFF;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r21,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r21.u32);
	// stw r16,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r16.u32);
	// stb r20,36(r10)
	PPC_STORE_U8(ctx.r10.u32 + 36, r20.u8);
	// stw r21,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r21.u32);
	// b 0x82774168
	goto loc_82774168;
loc_827747E0:
	// clrlwi r11,r15,24
	r11.u64 = r15.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82774830
	if (cr6.eq) goto loc_82774830;
loc_827747EC:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827747ec
	if (cr6.eq) goto loc_827747EC;
	// ld r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f0,0(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,27216(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + 27216);
	ctx.f13.f64 = double(temp.f32);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fnmsubs f9,f10,f13,f0
	ctx.f9.f64 = double(float(-(ctx.f10.f64 * ctx.f13.f64 - f0.f64)));
	// stfs f9,0(r17)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// bge cr6,0x82774830
	if (!cr6.lt) goto loc_82774830;
	// stfs f31,0(r17)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
loc_82774830:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
loc_82774848:
	// clrlwi r11,r15,24
	r11.u64 = r15.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82774898
	if (cr6.eq) goto loc_82774898;
loc_82774854:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82774854
	if (cr6.eq) goto loc_82774854;
	// ld r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f0,0(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,27216(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + 27216);
	ctx.f13.f64 = double(temp.f32);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fnmsubs f9,f10,f13,f0
	ctx.f9.f64 = double(float(-(ctx.f10.f64 * ctx.f13.f64 - f0.f64)));
	// stfs f9,0(r17)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// bge cr6,0x82774898
	if (!cr6.lt) goto loc_82774898;
	// stfs f31,0(r17)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r17.u32 + 0, temp.u32);
loc_82774898:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_827748B0"))) PPC_WEAK_FUNC(sub_827748B0);
PPC_FUNC_IMPL(__imp__sub_827748B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827748C8"))) PPC_WEAK_FUNC(sub_827748C8);
PPC_FUNC_IMPL(__imp__sub_827748C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,-1
	r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827748DC"))) PPC_WEAK_FUNC(sub_827748DC);
PPC_FUNC_IMPL(__imp__sub_827748DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827748E0"))) PPC_WEAK_FUNC(sub_827748E0);
PPC_FUNC_IMPL(__imp__sub_827748E0) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r5,r31,4
	ctx.r5.s64 = r31.s64 + 4;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277491C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_8277493C"))) PPC_WEAK_FUNC(sub_8277493C);
PPC_FUNC_IMPL(__imp__sub_8277493C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82774940"))) PPC_WEAK_FUNC(sub_82774940);
PPC_FUNC_IMPL(__imp__sub_82774940) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,4
	ctx.r6.s64 = r31.s64 + 4;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82774980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_827749A0"))) PPC_WEAK_FUNC(sub_827749A0);
PPC_FUNC_IMPL(__imp__sub_827749A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827749d0
	if (cr6.eq) goto loc_827749D0;
loc_827749AC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// ble cr6,0x827749c0
	if (!cr6.gt) goto loc_827749C0;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x827749c8
	goto loc_827749C8;
loc_827749C0:
	// bge cr6,0x827749dc
	if (!cr6.lt) goto loc_827749DC;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
loc_827749C8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827749ac
	if (!cr6.eq) goto loc_827749AC;
loc_827749D0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
loc_827749DC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827749d0
	if (cr6.eq) goto loc_827749D0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827749F0"))) PPC_WEAK_FUNC(sub_827749F0);
PPC_FUNC_IMPL(__imp__sub_827749F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// li r11,80
	r11.s64 = 80;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// stfs f8,0(r5)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774A20"))) PPC_WEAK_FUNC(sub_82774A20);
PPC_FUNC_IMPL(__imp__sub_82774A20) {
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
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,-32
	ctx.r5.s64 = ctx.r1.s64 + -32;
	// vsubfp128 v61,v1,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r10,-3808
	r11.s64 = ctx.r10.s64 + -3808;
	// lwz r10,-3792(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3792);
	// clrlwi r4,r10,31
	ctx.r4.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// vmsum3fp128 v58,v60,v61
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmsum3fp128 v57,v59,v61
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmsum3fp128 v56,v63,v61
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmrghw128 v55,v58,v58
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v54,v56,v57
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v62,v54,v55
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82774a9c
	if (!cr6.eq) goto loc_82774A9C;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,-3792(r9)
	PPC_STORE_U32(ctx.r9.u32 + -3792, ctx.r10.u32);
	// lfs f0,14196(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14196);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
loc_82774A9C:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v53,-1
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v52,r3,r8
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// vaddfp128 v51,v52,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v63.f32)));
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// vslw128 v50,v53,v53
	v50.u32[0] = v53.u32[0] << (v53.u8[0] & 0x1F);
	v50.u32[1] = v53.u32[1] << (v53.u8[4] & 0x1F);
	v50.u32[2] = v53.u32[2] << (v53.u8[8] & 0x1F);
	v50.u32[3] = v53.u32[3] << (v53.u8[12] & 0x1F);
	// vandc128 v49,v62,v50
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-32(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	f0.f64 = double(temp.f32);
	// stvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82774af8
	if (!cr6.lt) goto loc_82774AF8;
	// lfs f0,-28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	f0.f64 = double(temp.f32);
	// lfs f13,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82774af8
	if (!cr6.lt) goto loc_82774AF8;
	// lfs f0,-24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bltlr cr6
	if (cr6.lt) return;
loc_82774AF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774B00"))) PPC_WEAK_FUNC(sub_82774B00);
PPC_FUNC_IMPL(__imp__sub_82774B00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v54,v63,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vsubfp128 v60,v1,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v58,r11,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r3,16
	ctx.r5.s64 = ctx.r3.s64 + 16;
	// lvx128 v57,r11,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v56,v58,v58
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vor128 v55,v57,v57
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v59,v2,v61
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v61.f32)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vmsum3fp128 v53,v58,v60
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v52,v57,v60
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v51,v63,v60
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v50,v56,v59
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v49,v55,v59
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v48,v54,v59
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmrghw128 v47,v53,v53
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v46,v51,v52
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v45,v50,v50
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v44,v48,v49
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v43,v46,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v42,v44,v45
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stvx128 v43,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8261a6a8
	ctx.lr = 0x82774B94;
	sub_8261A6A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774BA4"))) PPC_WEAK_FUNC(sub_82774BA4);
PPC_FUNC_IMPL(__imp__sub_82774BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82774BA8"))) PPC_WEAK_FUNC(sub_82774BA8);
PPC_FUNC_IMPL(__imp__sub_82774BA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,27556
	ctx.r9.s64 = r11.s64 + 27556;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r8,96(r3)
	PPC_STORE_U8(ctx.r3.u32 + 96, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774BC8"))) PPC_WEAK_FUNC(sub_82774BC8);
PPC_FUNC_IMPL(__imp__sub_82774BC8) {
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82774BD0;
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// li r31,0
	r31.s64 = 0;
	// lbz r11,96(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 96);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r30,r9,1
	r30.u64 = ctx.r9.u64 ^ 1;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82774c40
	if (!cr6.gt) goto loc_82774C40;
loc_82774C0C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// vor128 v2,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82774C28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82774c5c
	if (!cr6.eq) goto loc_82774C5C;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x82774c0c
	if (cr6.lt) goto loc_82774C0C;
loc_82774C40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82774C44:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d924c
	return;
loc_82774C5C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82774c44
	goto loc_82774C44;
}

__attribute__((alias("__imp__sub_82774C64"))) PPC_WEAK_FUNC(sub_82774C64);
PPC_FUNC_IMPL(__imp__sub_82774C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82774C68"))) PPC_WEAK_FUNC(sub_82774C68);
PPC_FUNC_IMPL(__imp__sub_82774C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774C7C"))) PPC_WEAK_FUNC(sub_82774C7C);
PPC_FUNC_IMPL(__imp__sub_82774C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82774C80"))) PPC_WEAK_FUNC(sub_82774C80);
PPC_FUNC_IMPL(__imp__sub_82774C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774C9C"))) PPC_WEAK_FUNC(sub_82774C9C);
PPC_FUNC_IMPL(__imp__sub_82774C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82774CA0"))) PPC_WEAK_FUNC(sub_82774CA0);
PPC_FUNC_IMPL(__imp__sub_82774CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// stfs f1,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774CC8"))) PPC_WEAK_FUNC(sub_82774CC8);
PPC_FUNC_IMPL(__imp__sub_82774CC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774CF8"))) PPC_WEAK_FUNC(sub_82774CF8);
PPC_FUNC_IMPL(__imp__sub_82774CF8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f10,f0,f0
	ctx.f10.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f13,-8(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lfs f11,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,-12(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// fmadds f0,f13,f13,f10
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// fsqrts f0,f0
	f0.f64 = double(float(sqrt(f0.f64)));
	// addi r11,r1,-32
	r11.s64 = ctx.r1.s64 + -32;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 / f0.f64));
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82774D5C"))) PPC_WEAK_FUNC(sub_82774D5C);
PPC_FUNC_IMPL(__imp__sub_82774D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82774D60"))) PPC_WEAK_FUNC(sub_82774D60);
PPC_FUNC_IMPL(__imp__sub_82774D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f0{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
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
	// bl 0x823d91c0
	ctx.lr = 0x82774D68;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9c8
	ctx.lr = 0x82774D70;
	// addi r12,r1,-224
	r12.s64 = ctx.r1.s64 + -224;
	// bl 0x823dd51c
	ctx.lr = 0x82774D78;
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// stw r3,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r3.u32);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// li r22,0
	r22.s64 = 0;
	// stw r29,812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 812, r29.u32);
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// stw r30,788(r1)
	PPC_STORE_U32(ctx.r1.u32 + 788, r30.u32);
	// mr r15,r5
	r15.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r14,r8
	r14.u64 = ctx.r8.u64;
	// mr r16,r9
	r16.u64 = ctx.r9.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// mr r17,r22
	r17.u64 = r22.u64;
	// beq cr6,0x82774db8
	if (cr6.eq) goto loc_82774DB8;
	// stw r22,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r22.u32);
loc_82774DB8:
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// stb r22,0(r14)
	PPC_STORE_U8(r14.u32 + 0, r22.u8);
	// beq cr6,0x82774dd0
	if (cr6.eq) goto loc_82774DD0;
	// stb r22,0(r16)
	PPC_STORE_U8(r16.u32 + 0, r22.u8);
	// stw r22,4(r16)
	PPC_STORE_U32(r16.u32 + 4, r22.u32);
	// sth r22,8(r16)
	PPC_STORE_U16(r16.u32 + 8, r22.u16);
loc_82774DD0:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r31,0(r23)
	r31.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82761940
	ctx.lr = 0x82774DE0;
	sub_82761940(ctx, base);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v10,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,2272
	ctx.r9.s64 = r11.s64 + 2272;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// mr r26,r22
	r26.u64 = r22.u64;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r25,r22
	r25.u64 = r22.u64;
	// vor128 v124,v63,v63
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// mr r24,r22
	r24.u64 = r22.u64;
	// vor128 v123,v63,v63
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v10,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r21,r31
	r21.u64 = r31.u64;
	// vor128 v122,v63,v63
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// mr r20,r31
	r20.u64 = r31.u64;
	// stvx128 v124,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v121,v63,v63
	simde_mm_store_si128((simde__m128i*)v121.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v123,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v127,v63,v63
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lfs f28,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f28.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lfs f27,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f27.f64 = double(temp.f32);
	// vor128 v126,v63,v63
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f30.f64 = double(temp.f32);
	// lfs f29,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f29.f64 = double(temp.f32);
	// beq cr6,0x82775528
	if (cr6.eq) goto loc_82775528;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfd f25,32224(r10)
	f25.u64 = PPC_LOAD_U64(ctx.r10.u32 + 32224);
	// addi r18,r11,760
	r18.s64 = r11.s64 + 760;
	// lfd f26,21560(r9)
	f26.u64 = PPC_LOAD_U64(ctx.r9.u32 + 21560);
	// lfs f24,14196(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14196);
	f24.f64 = double(temp.f32);
loc_82774E74:
	// mr r28,r31
	r28.u64 = r31.u64;
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82774e88
	if (cr6.eq) goto loc_82774E88;
	// lwz r31,48(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 48);
loc_82774E88:
	// lwz r27,0(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x827754e8
	if (cr6.eq) goto loc_827754E8;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// beq cr6,0x827754e8
	if (cr6.eq) goto loc_827754E8;
	// cmpwi cr6,r27,3
	cr6.compare<int32_t>(r27.s32, 3, xer);
	// beq cr6,0x827752e8
	if (cr6.eq) goto loc_827752E8;
	// cmpwi cr6,r27,5
	cr6.compare<int32_t>(r27.s32, 5, xer);
	// beq cr6,0x82775274
	if (cr6.eq) goto loc_82775274;
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// beq cr6,0x82775274
	if (cr6.eq) goto loc_82775274;
	// addi r30,r29,4
	r30.s64 = r29.s64 + 4;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8276b2c8
	ctx.lr = 0x82774EC4;
	sub_8276B2C8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// lvx128 v125,r0,r11
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8276b328
	ctx.lr = 0x82774ED8;
	sub_8276B328(ctx, base);
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r29,820(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 820);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lfs f11,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,16(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f11,208(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f10,212(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f9,216(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// beq cr6,0x82774fb8
	if (cr6.eq) goto loc_82774FB8;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v0,v126,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	f0.f64 = double(temp.f32);
	// fmadds f0,f0,f0,f13
	f0.f64 = double(float(f0.f64 * f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// ble cr6,0x82774fb8
	if (!cr6.gt) goto loc_82774FB8;
	// frsqrte f13,f0
	// lfs f11,28(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = f0.u64 ^ 0x8000000000000000;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f10,32(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// vor128 v63,v0,v0
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// fmul f9,f13,f13
	ctx.f9.f64 = ctx.f13.f64 * ctx.f13.f64;
	// fmul f8,f13,f25
	ctx.f8.f64 = ctx.f13.f64 * f25.f64;
	// fnmsub f7,f9,f0,f26
	ctx.f7.f64 = -(ctx.f9.f64 * f0.f64 - f26.f64);
	// fmadd f6,f7,f8,f13
	ctx.f6.f64 = ctx.f7.f64 * ctx.f8.f64 + ctx.f13.f64;
	// fmul f5,f6,f6
	ctx.f5.f64 = ctx.f6.f64 * ctx.f6.f64;
	// fmul f4,f6,f25
	ctx.f4.f64 = ctx.f6.f64 * f25.f64;
	// fnmsub f3,f5,f0,f26
	ctx.f3.f64 = -(ctx.f5.f64 * f0.f64 - f26.f64);
	// fmadd f2,f3,f4,f6
	ctx.f2.f64 = ctx.f3.f64 * ctx.f4.f64 + ctx.f6.f64;
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fsel f0,f12,f31,f1
	f0.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f1.f64;
	// fmuls f13,f11,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f12,f10,f0
	ctx.f12.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lvlx128 v61,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmaddfp128 v126,v0,v59,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v126.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)), simde_mm_load_ps(v126.f32)));
	// vnmsubfp128 v127,v63,v58,v127
	simde_mm_store_ps(v127.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)), simde_mm_load_ps(v127.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
loc_82774FB8:
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v10,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82775024
	if (!cr6.eq) goto loc_82775024;
	// vsubfp128 v124,v125,v10
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v124.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(ctx.v10.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// vsubfp128 v123,v62,v10
	simde_mm_store_ps(v123.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v10.f32)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vor128 v122,v127,v127
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// li r26,1
	r26.s64 = 1;
	// vor128 v121,v126,v126
	simde_mm_store_si128((simde__m128i*)v121.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// mr r24,r11
	r24.u64 = r11.u64;
	// mr r25,r11
	r25.u64 = r11.u64;
	// mr r21,r31
	r21.u64 = r31.u64;
	// mr r20,r31
	r20.u64 = r31.u64;
	// stvx128 v124,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v123,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f28,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f28.f64 = double(temp.f32);
	// lfs f27,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f27.f64 = double(temp.f32);
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f30.f64 = double(temp.f32);
	// lfs f29,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f29.f64 = double(temp.f32);
loc_82775014:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82774e74
	if (!cr6.eq) goto loc_82774E74;
	// lwz r30,788(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 788);
	// b 0x82775524
	goto loc_82775524;
loc_82775024:
	// vsubfp128 v63,v125,v10
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(ctx.v10.f32)));
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// vsubfp128 v62,v62,v10
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v10.f32)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,232(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,224(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,200(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f0,f10,f12
	f0.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// lfs f9,192(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f9.f64 = double(temp.f32);
	// fmsubs f13,f11,f9,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 - f0.f64));
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// blt cr6,0x827750a0
	if (cr6.lt) goto loc_827750A0;
	// fmuls f0,f28,f9
	f0.f64 = double(float(f28.f64 * ctx.f9.f64));
	// mr r30,r22
	r30.u64 = r22.u64;
	// fmsubs f13,f10,f27,f0
	ctx.f13.f64 = double(float(ctx.f10.f64 * f27.f64 - f0.f64));
	// fmuls f0,f30,f12
	f0.f64 = double(float(f30.f64 * ctx.f12.f64));
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// fmsubs f13,f11,f29,f0
	ctx.f13.f64 = double(float(ctx.f11.f64 * f29.f64 - f0.f64));
	// bgt cr6,0x8277508c
	if (cr6.gt) goto loc_8277508C;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x8277530c
	if (!cr6.gt) goto loc_8277530C;
	// mr r26,r22
	r26.u64 = r22.u64;
	// stw r31,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r31.u32);
	// b 0x82775014
	goto loc_82775014;
loc_8277508C:
	// fcmpu cr6,f13,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x82775320
	if (!cr6.lt) goto loc_82775320;
	// mr r26,r22
	r26.u64 = r22.u64;
	// stw r31,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r31.u32);
	// b 0x82775014
	goto loc_82775014;
loc_827750A0:
	// fmuls f0,f30,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 * f27.f64));
	// fmsubs f13,f28,f29,f0
	ctx.f13.f64 = double(float(f28.f64 * f29.f64 - f0.f64));
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x82775118
	if (!cr6.gt) goto loc_82775118;
	// lfs f8,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f0,f30,f30
	f0.f64 = double(float(f30.f64 * f30.f64));
	// lfs f5,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// fmr f6,f8
	ctx.f6.f64 = ctx.f8.f64;
	// fmuls f7,f28,f28
	ctx.f7.f64 = double(float(f28.f64 * f28.f64));
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// fmadds f3,f8,f6,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f6.f64 + f0.f64));
	// fmadds f2,f5,f4,f7
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f4.f64 + ctx.f7.f64));
	// fmadds f1,f29,f29,f3
	ctx.f1.f64 = double(float(f29.f64 * f29.f64 + ctx.f3.f64));
	// fmadds f0,f27,f27,f2
	f0.f64 = double(float(f27.f64 * f27.f64 + ctx.f2.f64));
	// fmuls f8,f1,f0
	ctx.f8.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fsqrts f0,f8
	f0.f64 = double(float(sqrt(ctx.f8.f64)));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x827750f0
	if (cr6.gt) goto loc_827750F0;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x827750f4
	goto loc_827750F4;
loc_827750F0:
	// fdivs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
loc_827750F4:
	// lfs f13,12(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r18.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82775118
	if (!cr6.gt) goto loc_82775118;
	// mr r26,r22
	r26.u64 = r22.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82775110
	if (cr6.eq) goto loc_82775110;
	// lwz r31,52(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 52);
loc_82775110:
	// stw r31,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r31.u32);
	// b 0x82775014
	goto loc_82775014;
loc_82775118:
	// fmuls f0,f11,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fmuls f13,f10,f27
	ctx.f13.f64 = double(float(ctx.f10.f64 * f27.f64));
	// fmsubs f0,f30,f12,f0
	f0.f64 = double(float(f30.f64 * ctx.f12.f64 - f0.f64));
	// fmsubs f13,f28,f9,f13
	ctx.f13.f64 = double(float(f28.f64 * ctx.f9.f64 - ctx.f13.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x82775144
	if (cr6.lt) goto loc_82775144;
	// fmuls f11,f11,f27
	ctx.f11.f64 = double(float(ctx.f11.f64 * f27.f64));
	// li r10,1
	ctx.r10.s64 = 1;
	// fmsubs f8,f28,f12,f11
	ctx.f8.f64 = double(float(f28.f64 * ctx.f12.f64 - ctx.f11.f64));
	// fcmpu cr6,f8,f31
	cr6.compare(ctx.f8.f64, f31.f64);
	// ble cr6,0x82775148
	if (!cr6.gt) goto loc_82775148;
loc_82775144:
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
loc_82775148:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// fcmpu cr6,f13,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x82775168
	if (cr6.gt) goto loc_82775168;
	// fmuls f12,f10,f29
	ctx.f12.f64 = double(float(ctx.f10.f64 * f29.f64));
	// li r9,1
	ctx.r9.s64 = 1;
	// fmsubs f11,f30,f9,f12
	ctx.f11.f64 = double(float(f30.f64 * ctx.f9.f64 - ctx.f12.f64));
	// fcmpu cr6,f11,f31
	cr6.compare(ctx.f11.f64, f31.f64);
	// bge cr6,0x8277516c
	if (!cr6.lt) goto loc_8277516C;
loc_82775168:
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
loc_8277516C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277521c
	if (!cr6.eq) goto loc_8277521C;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x827751f0
	if (!cr6.eq) goto loc_827751F0;
	// mr r30,r22
	r30.u64 = r22.u64;
	// fcmpu cr6,f13,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x827753b4
	if (cr6.gt) goto loc_827753B4;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82775014
	if (!cr6.lt) goto loc_82775014;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// stvx128 v123,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827751A8:
	// lwz r3,756(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f1,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82774cf8
	ctx.lr = 0x827751B8;
	sub_82774CF8(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v54,v55,v10
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82761890
	ctx.lr = 0x827751D8;
	sub_82761890(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lwz r10,788(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 788);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775374
	if (cr6.eq) goto loc_82775374;
	// stw r21,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r21.u32);
	// b 0x82775378
	goto loc_82775378;
loc_827751F0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277521c
	if (!cr6.eq) goto loc_8277521C;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vor128 v123,v62,v62
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// mr r24,r11
	r24.u64 = r11.u64;
	// vor128 v121,v126,v126
	simde_mm_store_si128((simde__m128i*)v121.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// mr r20,r31
	r20.u64 = r31.u64;
	// stvx128 v123,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f29.f64 = double(temp.f32);
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f30.f64 = double(temp.f32);
	// b 0x82775014
	goto loc_82775014;
loc_8277521C:
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// vor128 v124,v63,v63
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vor128 v122,v127,v127
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r21,r31
	r21.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stvx128 v124,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f27,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f27.f64 = double(temp.f32);
	// lfs f28,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f28.f64 = double(temp.f32);
	// bne cr6,0x8277524c
	if (!cr6.eq) goto loc_8277524C;
	// mr r25,r11
	r25.u64 = r11.u64;
	// b 0x82775014
	goto loc_82775014;
loc_8277524C:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// vor128 v123,v62,v62
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// mr r24,r11
	r24.u64 = r11.u64;
	// vor128 v121,v126,v126
	simde_mm_store_si128((simde__m128i*)v121.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// mr r25,r11
	r25.u64 = r11.u64;
	// mr r20,r31
	r20.u64 = r31.u64;
	// stvx128 v123,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f29.f64 = double(temp.f32);
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f30.f64 = double(temp.f32);
	// b 0x82775014
	goto loc_82775014;
loc_82775274:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8277528c
	if (cr6.eq) goto loc_8277528C;
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82775290
	if (cr6.eq) goto loc_82775290;
loc_8277528C:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82775290:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277549c
	if (!cr6.eq) goto loc_8277549C;
	// mr r30,r28
	r30.u64 = r28.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x827752ac
	if (cr6.eq) goto loc_827752AC;
	// lwz r30,52(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 52);
loc_827752AC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x827754a4
	if (cr6.gt) goto loc_827754A4;
	// lis r12,-32137
	r12.s64 = -2106130432;
	// addi r12,r12,21200
	r12.s64 = r12.s64 + 21200;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_827753C8;
	case 1:
		goto loc_827753C8;
	case 2:
		goto loc_827753FC;
	case 3:
		goto loc_827753D8;
	case 4:
		goto loc_827754A4;
	case 5:
		goto loc_82775014;
	default:
		__builtin_unreachable();
	}
	// lwz r19,21448(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 21448);
	// lwz r19,21448(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 21448);
	// lwz r19,21500(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 21500);
	// lwz r19,21464(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 21464);
	// lwz r19,21668(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 21668);
	// lwz r19,20500(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 20500);
loc_827752E8:
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x8276b3b0
	ctx.lr = 0x827752F8;
	sub_8276B3B0(ctx, base);
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x82761890
	ctx.lr = 0x82775308;
	sub_82761890(ctx, base);
	// b 0x82775510
	goto loc_82775510;
loc_8277530C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r30,1
	r30.s64 = 1;
	// stvx128 v124,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8277532c
	goto loc_8277532C;
loc_82775320:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// stvx128 v123,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8277532C:
	// lwz r3,756(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f1,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82774cf8
	ctx.lr = 0x8277533C;
	sub_82774CF8(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v57,v10
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82761890
	ctx.lr = 0x8277535C;
	sub_82761890(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lwz r10,788(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 788);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775374
	if (cr6.eq) goto loc_82775374;
	// stw r21,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r21.u32);
	// b 0x82775378
	goto loc_82775378;
loc_82775374:
	// stw r20,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r20.u32);
loc_82775378:
	// lwz r9,812(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 812);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82775394
	if (cr6.eq) goto loc_82775394;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
loc_82775394:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827756b4
	if (cr6.eq) goto loc_827756B4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827753ac
	if (cr6.eq) goto loc_827753AC;
	// stvx128 v122,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x827756b4
	goto loc_827756B4;
loc_827753AC:
	// stvx128 v121,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v121.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x827756b4
	goto loc_827756B4;
loc_827753B4:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r30,1
	r30.s64 = 1;
	// stvx128 v124,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x827751a8
	goto loc_827751A8;
loc_827753C8:
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x8276b280
	ctx.lr = 0x827753D4;
	sub_8276B280(ctx, base);
	// b 0x827754a4
	goto loc_827754A4;
loc_827753D8:
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x8276b3b0
	ctx.lr = 0x827753E8;
	sub_8276B3B0(ctx, base);
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x82761890
	ctx.lr = 0x827753F8;
	sub_82761890(ctx, base);
	// b 0x827754a4
	goto loc_827754A4;
loc_827753FC:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f13,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// lvlx128 v53,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// vmulfp128 v0,v51,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32)));
	// stfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v50,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// stvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,16(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f11,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v12,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,28(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82761868
	ctx.lr = 0x82775498;
	sub_82761868(ctx, base);
	// b 0x827754a4
	goto loc_827754A4;
loc_8277549C:
	// lvx128 v49,r0,r19
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827754A4:
	// lwz r11,788(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 788);
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// stw r28,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r28.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// bne cr6,0x827754dc
	if (!cr6.eq) goto loc_827754DC;
	// cmplwi cr6,r16,0
	cr6.compare<uint32_t>(r16.u32, 0, xer);
	// beq cr6,0x827756b4
	if (cr6.eq) goto loc_827756B4;
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r16)
	PPC_STORE_U8(r16.u32 + 0, r11.u8);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stw r10,4(r16)
	PPC_STORE_U32(r16.u32 + 4, ctx.r10.u32);
	// lhz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// sth r9,8(r16)
	PPC_STORE_U16(r16.u32 + 8, ctx.r9.u16);
	// b 0x827756b4
	goto loc_827756B4;
loc_827754DC:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// stb r11,0(r14)
	PPC_STORE_U8(r14.u32 + 0, r11.u8);
	// b 0x827756b4
	goto loc_827756B4;
loc_827754E8:
	// lfs f0,12(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	f0.f64 = double(temp.f32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lfs f13,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lfs f12,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,184(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x82761868
	ctx.lr = 0x82775510;
	sub_82761868(ctx, base);
loc_82775510:
	// lwz r30,788(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 788);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r17,1
	r17.s64 = 1;
	// lvx128 v10,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
loc_82775524:
	// lwz r29,812(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 812);
loc_82775528:
	// clrlwi r11,r17,24
	r11.u64 = r17.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82775590
	if (!cr6.eq) goto loc_82775590;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775590
	if (cr6.eq) goto loc_82775590;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lvlx128 v48,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v46,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v45,v46,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vmaddfp128 v10,v124,v45,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v45.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vmaddfp128 v10,v123,v47,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v123.f32), simde_mm_load_ps(v47.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v10,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82761890
	ctx.lr = 0x82775588;
	sub_82761890(ctx, base);
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// b 0x827756b4
	goto loc_827756B4;
loc_82775590:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827755a4
	if (!cr6.eq) goto loc_827755A4;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// b 0x827756b8
	goto loc_827756B8;
loc_827755A4:
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x82761940
	ctx.lr = 0x827755B0;
	sub_82761940(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v44,r0,r3
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r11,r22
	r11.u64 = r22.u64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v43,v44,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v43,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f12,f28,f0
	ctx.f12.f64 = double(float(f28.f64 * f0.f64));
	// fmsubs f11,f13,f27,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f27.f64 - ctx.f12.f64));
	// fcmpu cr6,f11,f31
	cr6.compare(ctx.f11.f64, f31.f64);
	// bge cr6,0x82775600
	if (!cr6.lt) goto loc_82775600;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r11,1
	r11.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stvx128 v124,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82775628
	goto loc_82775628;
loc_82775600:
	// fmuls f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 * f0.f64));
	// fmsubs f13,f13,f29,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f29.f64 - f0.f64));
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x82775624
	if (!cr6.gt) goto loc_82775624;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r11,1
	r11.s64 = 1;
	// stvx128 v123,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82775628
	goto loc_82775628;
loc_82775624:
	// lwz r5,12(r15)
	ctx.r5.u64 = PPC_LOAD_U32(r15.u32 + 12);
loc_82775628:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827756b4
	if (cr6.eq) goto loc_827756B4;
	// lwz r3,756(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f1,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82774cf8
	ctx.lr = 0x82775644;
	sub_82774CF8(ctx, base);
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775658
	if (cr6.eq) goto loc_82775658;
	// stw r21,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r21.u32);
	// b 0x8277565c
	goto loc_8277565C;
loc_82775658:
	// stw r20,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r20.u32);
loc_8277565C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82775674
	if (cr6.eq) goto loc_82775674;
	// cntlzw r11,r10
	r11.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
loc_82775674:
	// lwz r11,820(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 820);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775694
	if (cr6.eq) goto loc_82775694;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775690
	if (cr6.eq) goto loc_82775690;
	// stvx128 v122,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82775694
	goto loc_82775694;
loc_82775690:
	// stvx128 v121,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v121.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82775694:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v41,v42,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82761890
	ctx.lr = 0x827756B4;
	sub_82761890(ctx, base);
loc_827756B4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827756B8:
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// addi r12,r1,-224
	r12.s64 = ctx.r1.s64 + -224;
	// bl 0x823dd7b4
	ctx.lr = 0x827756C4;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba14
	ctx.lr = 0x827756CC;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_827756D0"))) PPC_WEAK_FUNC(sub_827756D0);
PPC_FUNC_IMPL(__imp__sub_827756D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,36(r11)
	PPC_STORE_U8(r11.u32 + 36, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827756E0"))) PPC_WEAK_FUNC(sub_827756E0);
PPC_FUNC_IMPL(__imp__sub_827756E0) {
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
	// li r5,4096
	ctx.r5.s64 = 4096;
	// lwz r31,24(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x821be250
	ctx.lr = 0x8277570C;
	sub_821BE250(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82775780
	if (!cr6.eq) goto loc_82775780;
	// lbz r11,36(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775740
	if (cr6.eq) goto loc_82775740;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,42
	ctx.r10.s64 = 42;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82775740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82775740:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,120
	ctx.r10.s64 = 120;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82775764;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r7,255
	ctx.r7.s64 = 255;
	// li r6,217
	ctx.r6.s64 = 217;
	// li r3,2
	ctx.r3.s64 = 2;
	// stb r7,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r7.u8);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stb r6,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r6.u8);
loc_82775780:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r10.u8);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_827757B0"))) PPC_WEAK_FUNC(sub_827757B0);
PPC_FUNC_IMPL(__imp__sub_827757B0) {
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
	ctx.lr = 0x827757B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// lwz r30,24(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// ble cr6,0x82775810
	if (!cr6.gt) goto loc_82775810;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// ble cr6,0x827757f8
	if (!cr6.gt) goto loc_827757F8;
loc_827757DC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
	// bl 0x827756e0
	ctx.lr = 0x827757EC;
	sub_827756E0(ctx, base);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bgt cr6,0x827757dc
	if (cr6.gt) goto loc_827757DC;
loc_827757F8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// subf r8,r31,r10
	ctx.r8.s64 = ctx.r10.s64 - r31.s64;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// stw r8,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r8.u32);
loc_82775810:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82775818"))) PPC_WEAK_FUNC(sub_82775818);
PPC_FUNC_IMPL(__imp__sub_82775818) {
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
	ctx.lr = 0x82775820;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82775878
	if (!cr6.eq) goto loc_82775878;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,40
	ctx.r5.s64 = 40;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82775850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82775874;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r29)
	PPC_STORE_U32(r29.u32 + 32, ctx.r3.u32);
loc_82775878:
	// lis r9,-32137
	ctx.r9.s64 = -2106130432;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r8,-32137
	ctx.r8.s64 = -2106130432;
	// lis r7,-32137
	ctx.r7.s64 = -2106130432;
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// addi r4,r9,22224
	ctx.r4.s64 = ctx.r9.s64 + 22224;
	// stw r30,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, r30.u32);
	// addi r3,r8,22240
	ctx.r3.s64 = ctx.r8.s64 + 22240;
	// addi r9,r7,22448
	ctx.r9.s64 = ctx.r7.s64 + 22448;
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r3,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r3.u32);
	// addi r8,r6,-32624
	ctx.r8.s64 = ctx.r6.s64 + -32624;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// addi r7,r5,0
	ctx.r7.s64 = ctx.r5.s64 + 0;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// stw r8,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r8.u32);
	// stw r7,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r7.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827758D0"))) PPC_WEAK_FUNC(sub_827758D0);
PPC_FUNC_IMPL(__imp__sub_827758D0) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// lwz r31,24(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827758FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,4096
	ctx.r9.s64 = 4096;
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82775920"))) PPC_WEAK_FUNC(sub_82775920);
PPC_FUNC_IMPL(__imp__sub_82775920) {
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
	// li r5,4096
	ctx.r5.s64 = 4096;
	// lwz r31,24(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821be3d8
	ctx.lr = 0x8277594C;
	sub_821BE3D8(ctx, base);
	// cmplwi cr6,r3,4096
	cr6.compare<uint32_t>(ctx.r3.u32, 4096, xer);
	// beq cr6,0x82775974
	if (cr6.eq) goto loc_82775974;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,37
	ctx.r10.s64 = 37;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82775974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82775974:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,4096
	ctx.r10.s64 = 4096;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_827759A0"))) PPC_WEAK_FUNC(sub_827759A0);
PPC_FUNC_IMPL(__imp__sub_827759A0) {
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
	ctx.lr = 0x827759A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,24(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// subfic r30,r11,4096
	xer.ca = r11.u32 <= 4096;
	r30.s64 = 4096 - r11.s64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827759fc
	if (cr6.eq) goto loc_827759FC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821be3d8
	ctx.lr = 0x827759D4;
	sub_821BE3D8(ctx, base);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// beq cr6,0x827759fc
	if (cr6.eq) goto loc_827759FC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,37
	ctx.r10.s64 = 37;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827759FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827759FC:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821bdd28
	ctx.lr = 0x82775A04;
	sub_821BDD28(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82775A0C"))) PPC_WEAK_FUNC(sub_82775A0C);
PPC_FUNC_IMPL(__imp__sub_82775A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82775A10"))) PPC_WEAK_FUNC(sub_82775A10);
PPC_FUNC_IMPL(__imp__sub_82775A10) {
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
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82775a54
	if (!cr6.eq) goto loc_82775A54;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82775A50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
loc_82775A54:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r10,-32137
	ctx.r10.s64 = -2106130432;
	// lis r9,-32137
	ctx.r9.s64 = -2106130432;
	// lis r8,-32137
	ctx.r8.s64 = -2106130432;
	// addi r7,r10,22736
	ctx.r7.s64 = ctx.r10.s64 + 22736;
	// addi r6,r9,22816
	ctx.r6.s64 = ctx.r9.s64 + 22816;
	// addi r5,r8,22944
	ctx.r5.s64 = ctx.r8.s64 + 22944;
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
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

__attribute__((alias("__imp__sub_82775A98"))) PPC_WEAK_FUNC(sub_82775A98);
PPC_FUNC_IMPL(__imp__sub_82775A98) {
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
	ctx.lr = 0x82775AA0;
	// addi r31,r1,-720
	r31.s64 = ctx.r1.s64 + -720;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82775ac8
	if (!cr6.eq) goto loc_82775AC8;
	// addi r1,r31,720
	ctx.r1.s64 = r31.s64 + 720;
	// b 0x823d9244
	return;
loc_82775AC8:
	// addi r3,r31,528
	ctx.r3.s64 = r31.s64 + 528;
	// bl 0x82778fc0
	ctx.lr = 0x82775AD0;
	sub_82778FC0(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// li r5,432
	ctx.r5.s64 = 432;
	// li r4,62
	ctx.r4.s64 = 62;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x827782e8
	ctx.lr = 0x82775AE4;
	sub_827782E8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82775818
	ctx.lr = 0x82775AF0;
	sub_82775818(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x827788d0
	ctx.lr = 0x82775AFC;
	sub_827788D0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82775b30
	if (!cr6.eq) goto loc_82775B30;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r4,128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218de38
	ctx.lr = 0x82775B28;
	sub_8218DE38(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82775b6c
	goto loc_82775B6C;
loc_82775B30:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775b6c
	if (cr6.eq) goto loc_82775B6C;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775b58
	if (cr6.eq) goto loc_82775B58;
	// addi r11,r4,63
	r11.s64 = ctx.r4.s64 + 63;
	// rlwinm r11,r11,2,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFF00;
	// b 0x82775b5c
	goto loc_82775B5C;
loc_82775B58:
	// li r11,0
	r11.s64 = 0;
loc_82775B5C:
	// clrlwi r6,r11,16
	ctx.r6.u64 = r11.u32 & 0xFFFF;
	// lwz r5,128(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218e060
	ctx.lr = 0x82775B6C;
	sub_8218E060(ctx, base);
loc_82775B6C:
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82778bd8
	ctx.lr = 0x82775B74;
	sub_82778BD8(ctx, base);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x82775B8C;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r8,216(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r7,192(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r6,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r6.u32);
	// lwz r28,16(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bge cr6,0x82775c3c
	if (!cr6.lt) goto loc_82775C3C;
	// li r29,255
	r29.s64 = 255;
loc_82775BB4:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82778ad8
	ctx.lr = 0x82775BC4;
	sub_82778AD8(ctx, base);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775c24
	if (cr6.eq) goto loc_82775C24;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r28,2
	r11.s64 = r28.s64 + 2;
loc_82775BDC:
	// stb r29,-2(r11)
	PPC_STORE_U8(r11.u32 + -2, r29.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stb r7,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, ctx.r7.u8);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbz r5,1(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 1);
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lbz r3,2(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// stb r3,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r3.u8);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x82775bdc
	if (cr6.lt) goto loc_82775BDC;
loc_82775C24:
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// lwz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x82775bb4
	if (cr6.lt) goto loc_82775BB4;
loc_82775C3C:
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82778778
	ctx.lr = 0x82775C44;
	sub_82778778(ctx, base);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82778408
	ctx.lr = 0x82775C4C;
	sub_82778408(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821be610
	ctx.lr = 0x82775C54;
	sub_821BE610(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r31,720
	ctx.r1.s64 = r31.s64 + 720;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82775C60"))) PPC_WEAK_FUNC(sub_82775C60);
PPC_FUNC_IMPL(__imp__sub_82775C60) {
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
	ctx.lr = 0x82775C68;
	// addi r31,r1,-640
	r31.s64 = ctx.r1.s64 + -640;
	// stwu r1,-640(r1)
	ea = -640 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82775c90
	if (!cr6.eq) goto loc_82775C90;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,640
	ctx.r1.s64 = r31.s64 + 640;
	// b 0x823d9248
	return;
loc_82775C90:
	// addi r3,r31,464
	ctx.r3.s64 = r31.s64 + 464;
	// bl 0x82778fc0
	ctx.lr = 0x82775C98;
	sub_82778FC0(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// li r5,360
	ctx.r5.s64 = 360;
	// li r4,62
	ctx.r4.s64 = 62;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82779030
	ctx.lr = 0x82775CAC;
	sub_82779030(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82775a10
	ctx.lr = 0x82775CB8;
	sub_82775A10(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// bl 0x8277a048
	ctx.lr = 0x82775CC8;
	sub_8277A048(ctx, base);
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// lhz r7,2(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r10,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r9,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r9.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r8,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r8.u32);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// stw r7,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r7.u32);
	// bl 0x82779788
	ctx.lr = 0x82775CF8;
	sub_82779788(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82779370
	ctx.lr = 0x82775D04;
	sub_82779370(ctx, base);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// neg r5,r6
	ctx.r5.s64 = -ctx.r6.s64;
	// rlwinm r12,r5,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// lwz r29,16(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x823dbff4
	ctx.lr = 0x82775D20;
	sub_823DBFF4(ctx, base);
	// lwz r4,0(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r3,304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// stwux r4,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// bge cr6,0x82775dc4
	if (!cr6.lt) goto loc_82775DC4;
loc_82775D40:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82775d9c
	if (cr6.eq) goto loc_82775D9C;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r29,2
	r11.s64 = r29.s64 + 2;
loc_82775D58:
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stbx r8,r10,r7
	PPC_STORE_U8(ctx.r10.u32 + ctx.r7.u32, ctx.r8.u8);
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stb r6,1(r5)
	PPC_STORE_U8(ctx.r5.u32 + 1, ctx.r6.u8);
	// lbz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stb r4,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, ctx.r4.u8);
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// lhz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x82775d58
	if (cr6.lt) goto loc_82775D58;
loc_82775D9C:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82779458
	ctx.lr = 0x82775DAC;
	sub_82779458(ctx, base);
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82775d40
	if (cr6.lt) goto loc_82775D40;
loc_82775DC4:
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x827791c0
	ctx.lr = 0x82775DCC;
	sub_827791C0(ctx, base);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x82778408
	ctx.lr = 0x82775DD4;
	sub_82778408(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r31,640
	ctx.r1.s64 = r31.s64 + 640;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82775DE0"))) PPC_WEAK_FUNC(sub_82775DE0);
PPC_FUNC_IMPL(__imp__sub_82775DE0) {
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
	ctx.lr = 0x82775DE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// addi r5,r10,1444
	ctx.r5.s64 = ctx.r10.s64 + 1444;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x82775E1C;
	sub_821CA6A8(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82775a98
	ctx.lr = 0x82775E2C;
	sub_82775A98(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82775E34"))) PPC_WEAK_FUNC(sub_82775E34);
PPC_FUNC_IMPL(__imp__sub_82775E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82775E38"))) PPC_WEAK_FUNC(sub_82775E38);
PPC_FUNC_IMPL(__imp__sub_82775E38) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,102
	ctx.r10.s64 = 102;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82775E6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,404(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lbz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 12);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82775e9c
	if (cr6.eq) goto loc_82775E9C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,61
	ctx.r10.s64 = 61;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82775E9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82775E9C:
	// addi r11,r31,218
	r11.s64 = r31.s64 + 218;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,5
	ctx.r7.s64 = 5;
loc_82775EB0:
	// stb r10,-16(r11)
	PPC_STORE_U8(r11.u32 + -16, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// stb r7,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x82775eb0
	if (!cr0.eq) goto loc_82775EB0;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r10.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// stb r10,266(r31)
	PPC_STORE_U8(r31.u32 + 266, ctx.r10.u8);
	// stb r10,256(r31)
	PPC_STORE_U8(r31.u32 + 256, ctx.r10.u8);
	// stb r8,257(r31)
	PPC_STORE_U8(r31.u32 + 257, ctx.r8.u8);
	// stb r8,258(r31)
	PPC_STORE_U8(r31.u32 + 258, ctx.r8.u8);
	// stb r10,259(r31)
	PPC_STORE_U8(r31.u32 + 259, ctx.r10.u8);
	// sth r8,260(r31)
	PPC_STORE_U16(r31.u32 + 260, ctx.r8.u16);
	// sth r8,262(r31)
	PPC_STORE_U16(r31.u32 + 262, ctx.r8.u16);
	// stb r10,264(r31)
	PPC_STORE_U8(r31.u32 + 264, ctx.r10.u8);
	// stb r10,265(r31)
	PPC_STORE_U8(r31.u32 + 265, ctx.r10.u8);
	// stb r8,12(r11)
	PPC_STORE_U8(r11.u32 + 12, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_82775F14"))) PPC_WEAK_FUNC(sub_82775F14);
PPC_FUNC_IMPL(__imp__sub_82775F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82775F18"))) PPC_WEAK_FUNC(sub_82775F18);
PPC_FUNC_IMPL(__imp__sub_82775F18) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82775F20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r27,24(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stb r4,200(r31)
	PPC_STORE_U8(r31.u32 + 200, ctx.r4.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r5,201(r31)
	PPC_STORE_U8(r31.u32 + 201, ctx.r5.u8);
	// bne cr6,0x82775f70
	if (!cr6.eq) goto loc_82775F70;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82775F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82775f68
	if (!cr6.eq) goto loc_82775F68;
loc_82775F5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82775F68:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82775F70:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rotlwi r30,r9,8
	r30.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82775fa8
	if (!cr0.eq) goto loc_82775FA8;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82775F94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82775FA8:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
	// bne 0x82775fe0
	if (!cr0.eq) goto loc_82775FE0;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82775FCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82775FE0:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r9,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r9.u32);
	// bne 0x82776018
	if (!cr0.eq) goto loc_82776018;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82776018:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rotlwi r8,r9,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// bne 0x82776054
	if (!cr0.eq) goto loc_82776054;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82776054:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// bne 0x82776094
	if (!cr0.eq) goto loc_82776094;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776080;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82776094:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// addic. r10,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r10.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// rotlwi r7,r8,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// bne 0x827760d0
	if (!cr0.eq) goto loc_827760D0;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827760BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_827760D0:
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r9,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// add r11,r7,r8
	r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// bne 0x82776110
	if (!cr0.eq) goto loc_82776110;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827760FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82776110:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r28,r10,1
	r28.s64 = ctx.r10.s64 + 1;
	// lwz r6,380(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// addi r29,r9,-1
	r29.s64 = ctx.r9.s64 + -1;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,100
	ctx.r7.s64 = 100;
	// addi r30,r30,-8
	r30.s64 = r30.s64 + -8;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r8,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r6.u32);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r7,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r7.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277616C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,404(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lbz r4,13(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 13);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8277619c
	if (cr6.eq) goto loc_8277619C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,58
	ctx.r10.s64 = 58;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277619C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277619C:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827761c0
	if (!cr6.gt) goto loc_827761C0;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x827761c0
	if (!cr6.gt) goto loc_827761C0;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x827761e0
	if (cr6.gt) goto loc_827761E0;
loc_827761C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,32
	ctx.r10.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827761E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827761E0:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x82776214
	if (cr6.eq) goto loc_82776214;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776214:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82776244
	if (!cr6.eq) goto loc_82776244;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mulli r5,r10,84
	ctx.r5.s64 = ctx.r10.s64 * 84;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82776240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
loc_82776244:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r26,0
	r26.s64 = 0;
	// lwz r30,196(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82776374
	if (!cr6.gt) goto loc_82776374;
	// li r25,101
	r25.s64 = 101;
loc_8277625C:
	// stw r26,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r26.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8277628c
	if (!cr6.eq) goto loc_8277628C;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r28,0(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r29,4(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_8277628C:
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addic. r10,r29,-1
	xer.ca = r29.u32 > 0;
	ctx.r10.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// bne 0x827762c4
	if (!cr0.eq) goto loc_827762C4;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827762B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_827762C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r8,r9,4
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 4;
	// clrlwi r7,r9,28
	ctx.r7.u64 = ctx.r9.u32 & 0xF;
	// clrlwi r6,r8,28
	ctx.r6.u64 = ctx.r8.u32 & 0xF;
	// stw r7,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r7.u32);
	// stw r6,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r6.u32);
	// bne 0x8277630c
	if (!cr0.eq) goto loc_8277630C;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827762F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82775f5c
	if (cr6.eq) goto loc_82775F5C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_8277630C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r29,r10,-1
	r29.s64 = ctx.r10.s64 + -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r9.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// lwz r6,12(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r6,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r6.u32);
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r5,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r5.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r25,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r25.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82776360;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r26,r8
	cr6.compare<int32_t>(r26.s32, ctx.r8.s32, xer);
	// blt cr6,0x8277625c
	if (cr6.lt) goto loc_8277625C;
loc_82776374:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,13(r11)
	PPC_STORE_U8(r11.u32 + 13, ctx.r10.u8);
	// stw r28,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r28.u32);
	// stw r29,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82776394"))) PPC_WEAK_FUNC(sub_82776394);
PPC_FUNC_IMPL(__imp__sub_82776394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82776398"))) PPC_WEAK_FUNC(sub_82776398);
PPC_FUNC_IMPL(__imp__sub_82776398) {
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
	ctx.lr = 0x827763A0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r25,24(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r29,4(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827763e0
	if (!cr6.eq) goto loc_827763E0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,62
	ctx.r10.s64 = 62;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827763E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827763E0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82776418
	if (!cr6.eq) goto loc_82776418;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827763F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776410
	if (!cr6.eq) goto loc_82776410;
loc_82776404:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
loc_82776410:
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r29,4(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_82776418:
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// addic. r10,r29,-1
	xer.ca = r29.u32 > 0;
	ctx.r10.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rotlwi r30,r9,8
	r30.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82776450
	if (!cr0.eq) goto loc_82776450;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277643C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_82776450:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
	// bne 0x82776488
	if (!cr0.eq) goto loc_82776488;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_82776488:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,103
	ctx.r8.s64 = 103;
	// lbz r22,0(r11)
	r22.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r26,r10,-1
	r26.s64 = ctx.r10.s64 + -1;
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r22,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, r22.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827764C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r22,3
	ctx.r4.s64 = r22.s64 + 3;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x827764e0
	if (!cr6.eq) goto loc_827764E0;
	// cmpwi cr6,r22,1
	cr6.compare<int32_t>(r22.s32, 1, xer);
	// blt cr6,0x827764e0
	if (cr6.lt) goto loc_827764E0;
	// cmpwi cr6,r22,4
	cr6.compare<int32_t>(r22.s32, 4, xer);
	// ble cr6,0x82776500
	if (!cr6.gt) goto loc_82776500;
loc_827764E0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776500:
	// stw r22,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r22.u32);
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x82776640
	if (!cr6.gt) goto loc_82776640;
	// addi r23,r31,296
	r23.s64 = r31.s64 + 296;
	// li r20,5
	r20.s64 = 5;
	// li r21,104
	r21.s64 = 104;
loc_8277651C:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x82776548
	if (!cr6.eq) goto loc_82776548;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r28,0(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r26,4(r25)
	r26.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_82776548:
	// lbz r27,0(r28)
	r27.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addic. r10,r26,-1
	xer.ca = r26.u32 > 0;
	ctx.r10.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// bne 0x8277657c
	if (!cr0.eq) goto loc_8277657C;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_8277657C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// lbz r29,0(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r26,r10,-1
	r26.s64 = ctx.r10.s64 + -1;
	// lwz r30,196(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827765bc
	if (!cr6.gt) goto loc_827765BC;
loc_8277659C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// beq cr6,0x827765e0
	if (cr6.eq) goto loc_827765E0;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277659c
	if (cr6.lt) goto loc_8277659C;
loc_827765BC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r20,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r20.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r27.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827765E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827765E0:
	// srawi r11,r29,4
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0xF) != 0);
	r11.s64 = r29.s32 >> 4;
	// stw r30,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r30.u32);
	// clrlwi r10,r29,28
	ctx.r10.u64 = r29.u32 & 0xF;
	// clrlwi r9,r11,28
	ctx.r9.u64 = r11.u32 & 0xF;
	// stw r10,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r10.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r27.u32);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r8,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r8.u32);
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stw r7,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r21,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r21.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r23,r23,4
	r23.s64 = r23.s64 + 4;
	// cmpw cr6,r24,r22
	cr6.compare<int32_t>(r24.s32, r22.s32, xer);
	// blt cr6,0x8277651c
	if (cr6.lt) goto loc_8277651C;
loc_82776640:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x8277666c
	if (!cr6.eq) goto loc_8277666C;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r28,0(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r26,4(r25)
	r26.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_8277666C:
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// addic. r10,r26,-1
	xer.ca = r26.u32 > 0;
	ctx.r10.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// stw r9,364(r31)
	PPC_STORE_U32(r31.u32 + 364, ctx.r9.u32);
	// bne 0x827766a4
	if (!cr0.eq) goto loc_827766A4;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_827766A4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r29,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r29.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// stw r9,368(r31)
	PPC_STORE_U32(r31.u32 + 368, ctx.r9.u32);
	// bne 0x827766dc
	if (!cr0.eq) goto loc_827766DC;
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827766C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776404
	if (cr6.eq) goto loc_82776404;
	// lwz r30,0(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r29,4(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 4);
loc_827766DC:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// li r9,105
	ctx.r9.s64 = 105;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// srawi r8,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 4;
	// lwz r7,364(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 364);
	// clrlwi r6,r10,28
	ctx.r6.u64 = ctx.r10.u32 & 0xF;
	// clrlwi r5,r8,28
	ctx.r5.u64 = ctx.r8.u32 & 0xF;
	// stw r6,376(r31)
	PPC_STORE_U32(r31.u32 + 376, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,372(r31)
	PPC_STORE_U32(r31.u32 + 372, ctx.r5.u32);
	// stw r7,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r7.u32);
	// lwz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// lwz r8,372(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// lwz r7,376(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// stw r7,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277673C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,404(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r30,1
	ctx.r9.s64 = r30.s64 + 1;
	// addi r8,r29,-1
	ctx.r8.s64 = r29.s64 + -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r10.u32);
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r6.u32);
	// stw r9,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r9.u32);
	// stw r8,4(r25)
	PPC_STORE_U32(r25.u32 + 4, ctx.r8.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82776770"))) PPC_WEAK_FUNC(sub_82776770);
PPC_FUNC_IMPL(__imp__sub_82776770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82776778;
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r24,24(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827767c0
	if (!cr6.eq) goto loc_827767C0;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827767A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827767b8
	if (!cr6.eq) goto loc_827767B8;
loc_827767AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x823d9220
	return;
loc_827767B8:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_827767C0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r29,r9,8
	r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x827767f8
	if (!cr0.eq) goto loc_827767F8;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827767E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827767ac
	if (cr6.eq) goto loc_827767AC;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_827767F8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// addi r28,r10,-1
	r28.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r29
	r11.u64 = ctx.r9.u64 + r29.u64;
	// addi r26,r11,-2
	r26.s64 = r11.s64 + -2;
	// cmpwi cr6,r26,16
	cr6.compare<int32_t>(r26.s32, 16, xer);
	// ble cr6,0x82776ae4
	if (!cr6.gt) goto loc_82776AE4;
	// li r21,80
	r21.s64 = 80;
	// li r22,0
	r22.s64 = 0;
	// li r23,86
	r23.s64 = 86;
	// li r19,8
	r19.s64 = 8;
	// li r20,30
	r20.s64 = 30;
loc_82776828:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82776854
	if (!cr6.eq) goto loc_82776854;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827767ac
	if (cr6.eq) goto loc_827767AC;
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r28,4(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_82776854:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// lbz r25,0(r31)
	r25.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r21,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r21.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r22
	r27.u64 = r22.u64;
	// stb r22,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r22.u8);
	// li r29,1
	r29.s64 = 1;
loc_82776894:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x827768c0
	if (!cr6.eq) goto loc_827768C0;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827768AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827767ac
	if (cr6.eq) goto loc_827767AC;
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r28,4(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_827768C0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r29,16
	cr6.compare<int32_t>(r29.s32, 16, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// add r27,r11,r27
	r27.u64 = r11.u64 + r27.u64;
	// ble cr6,0x82776894
	if (!cr6.gt) goto loc_82776894;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r26,r26,-17
	r26.s64 = r26.s64 + -17;
	// lbz r7,81(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// li r4,2
	ctx.r4.s64 = 2;
	// lbz r5,82(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r9,83(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// lbz r8,86(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r29,87(r1)
	r29.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// lbz r18,88(r1)
	r18.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// stw r7,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r7.u32);
	// mr r7,r18
	ctx.r7.u64 = r18.u64;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// stw r9,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r9.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r6.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// stw r8,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r8.u32);
	// stw r29,48(r11)
	PPC_STORE_U32(r11.u32 + 48, r29.u32);
	// stw r7,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r7.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r23,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r23.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r7,89(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// li r4,2
	ctx.r4.s64 = 2;
	// lbz r5,90(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 90);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 92);
	// lbz r9,91(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 91);
	// lbz r10,93(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 93);
	// lbz r8,94(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 94);
	// lbz r29,95(r1)
	r29.u64 = PPC_LOAD_U8(ctx.r1.u32 + 95);
	// lbz r18,96(r1)
	r18.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// stw r7,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r7.u32);
	// mr r7,r18
	ctx.r7.u64 = r18.u64;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// stw r9,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r9.u32);
	// stw r6,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r6.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// stw r8,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r8.u32);
	// stw r29,48(r11)
	PPC_STORE_U32(r11.u32 + 48, r29.u32);
	// stw r7,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r7.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r23,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r23.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827769C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r27,256
	cr6.compare<int32_t>(r27.s32, 256, xer);
	// bgt cr6,0x827769d0
	if (cr6.gt) goto loc_827769D0;
	// cmpw cr6,r27,r26
	cr6.compare<int32_t>(r27.s32, r26.s32, xer);
	// ble cr6,0x827769ec
	if (!cr6.gt) goto loc_827769EC;
loc_827769D0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r19,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r19.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827769EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827769EC:
	// mr r29,r22
	r29.u64 = r22.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82776a44
	if (!cr6.gt) goto loc_82776A44;
loc_827769F8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82776a24
	if (!cr6.eq) goto loc_82776A24;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827767ac
	if (cr6.eq) goto loc_827767AC;
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r28,4(r24)
	r28.u64 = PPC_LOAD_U32(r24.u32 + 4);
loc_82776A24:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stbx r11,r29,r10
	PPC_STORE_U8(r29.u32 + ctx.r10.u32, r11.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x827769f8
	if (cr6.lt) goto loc_827769F8;
loc_82776A44:
	// rlwinm r11,r25,0,27,27
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x10;
	// subf r26,r27,r26
	r26.s64 = r26.s64 - r27.s64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82776a60
	if (cr6.eq) goto loc_82776A60;
	// addi r25,r25,-16
	r25.s64 = r25.s64 + -16;
	// addi r11,r25,44
	r11.s64 = r25.s64 + 44;
	// b 0x82776a64
	goto loc_82776A64;
loc_82776A60:
	// addi r11,r25,40
	r11.s64 = r25.s64 + 40;
loc_82776A64:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// add r29,r11,r30
	r29.u64 = r11.u64 + r30.u64;
	// blt cr6,0x82776a7c
	if (cr6.lt) goto loc_82776A7C;
	// cmpwi cr6,r25,4
	cr6.compare<int32_t>(r25.s32, 4, xer);
	// blt cr6,0x82776aa0
	if (cr6.lt) goto loc_82776AA0;
loc_82776A7C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r20,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r20.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r25,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r25.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776AA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776AA0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82776ab8
	if (!cr6.eq) goto loc_82776AB8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277a2e0
	ctx.lr = 0x82776AB4;
	sub_8277A2E0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_82776AB8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,17
	ctx.r5.s64 = 17;
	// bl 0x823da950
	ctx.lr = 0x82776AC8;
	sub_823DA950(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r11,17
	ctx.r3.s64 = r11.s64 + 17;
	// li r5,256
	ctx.r5.s64 = 256;
	// bl 0x823da950
	ctx.lr = 0x82776ADC;
	sub_823DA950(ctx, base);
	// cmpwi cr6,r26,16
	cr6.compare<int32_t>(r26.s32, 16, xer);
	// bgt cr6,0x82776828
	if (cr6.gt) goto loc_82776828;
loc_82776AE4:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x82776b0c
	if (cr6.eq) goto loc_82776B0C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776B0C:
	// stw r31,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r28,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r28.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82776B20"))) PPC_WEAK_FUNC(sub_82776B20);
PPC_FUNC_IMPL(__imp__sub_82776B20) {
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
	ctx.lr = 0x82776B28;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r26,24(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776b70
	if (!cr6.eq) goto loc_82776B70;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776B50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776b68
	if (!cr6.eq) goto loc_82776B68;
loc_82776B5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
loc_82776B68:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776B70:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r31,r9,8
	r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82776ba8
	if (!cr0.eq) goto loc_82776BA8;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776BA8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// addi r27,r10,-1
	r27.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// addic. r21,r11,-2
	xer.ca = r11.u32 > 1;
	r21.s64 = r11.s64 + -2;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// ble 0x82776e0c
	if (!cr0.gt) goto loc_82776E0C;
	// lis r11,-32242
	r11.s64 = -2113011712;
	// li r20,81
	r20.s64 = 81;
	// li r19,31
	r19.s64 = 31;
	// li r22,93
	r22.s64 = 93;
	// addi r23,r11,-31424
	r23.s64 = r11.s64 + -31424;
loc_82776BD4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82776c00
	if (!cr6.eq) goto loc_82776C00;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776BEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r27,4(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776C00:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// clrlwi r31,r10,28
	r31.u64 = ctx.r10.u32 & 0xF;
	// srawi r24,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	r24.s64 = ctx.r10.s32 >> 4;
	// stw r20,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r20.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r31.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r24,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, r24.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82776C44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x82776c70
	if (cr6.lt) goto loc_82776C70;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r19,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r19.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776C70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776C70:
	// addi r11,r31,36
	r11.s64 = r31.s64 + 36;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776c90
	if (!cr6.eq) goto loc_82776C90;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8277a2a0
	ctx.lr = 0x82776C8C;
	sub_8277A2A0(ctx, base);
	// stwx r3,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, ctx.r3.u32);
loc_82776C90:
	// lwzx r25,r31,r28
	r25.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// mr r29,r23
	r29.u64 = r23.u64;
loc_82776C98:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x82776d18
	if (cr6.eq) goto loc_82776D18;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82776ccc
	if (!cr6.eq) goto loc_82776CCC;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776CB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r27,4(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776CCC:
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addic. r10,r27,-1
	xer.ca = r27.u32 > 0;
	ctx.r10.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// rotlwi r31,r9,8
	r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82776d04
	if (!cr0.eq) goto loc_82776D04;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776D04:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// addi r27,r10,-1
	r27.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// b 0x82776d50
	goto loc_82776D50;
loc_82776D18:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82776d44
	if (!cr6.eq) goto loc_82776D44;
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776D30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776b5c
	if (cr6.eq) goto loc_82776B5C;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r27,4(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_82776D44:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82776D50:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r7,r23,256
	ctx.r7.s64 = r23.s64 + 256;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r29,r7
	cr6.compare<int32_t>(r29.s32, ctx.r7.s32, xer);
	// sthx r11,r8,r25
	PPC_STORE_U16(ctx.r8.u32 + r25.u32, r11.u16);
	// blt cr6,0x82776c98
	if (cr6.lt) goto loc_82776C98;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x82776df4
	if (cr6.lt) goto loc_82776DF4;
	// addi r31,r25,4
	r31.s64 = r25.s64 + 4;
	// li r29,8
	r29.s64 = 8;
loc_82776D84:
	// lhz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + -4);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// lhz r9,-2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + -2);
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lhz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// lhz r7,2(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// stw r7,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r7.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// stw r6,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r6.u32);
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// stw r5,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r5.u32);
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// lhz r9,10(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// stw r9,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r9.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r22,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r22.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82776DE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x82776d84
	if (!cr0.eq) goto loc_82776D84;
loc_82776DF4:
	// addi r21,r21,-65
	r21.s64 = r21.s64 + -65;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x82776e04
	if (cr6.eq) goto loc_82776E04;
	// addi r21,r21,-64
	r21.s64 = r21.s64 + -64;
loc_82776E04:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bgt cr6,0x82776bd4
	if (cr6.gt) goto loc_82776BD4;
loc_82776E0C:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x82776e34
	if (cr6.eq) goto loc_82776E34;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776E34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776E34:
	// stw r30,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r27,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r27.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82776E48"))) PPC_WEAK_FUNC(sub_82776E48);
PPC_FUNC_IMPL(__imp__sub_82776E48) {
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
	ctx.lr = 0x82776E50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,24(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776e98
	if (!cr6.eq) goto loc_82776E98;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776E78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82776e90
	if (!cr6.eq) goto loc_82776E90;
loc_82776E84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82776E90:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82776E98:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r27,r9,8
	r27.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82776ed0
	if (!cr0.eq) goto loc_82776ED0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776EBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776e84
	if (cr6.eq) goto loc_82776E84;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82776ED0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// addi r28,r10,-1
	r28.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r27
	r11.u64 = ctx.r9.u64 + r27.u64;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82776f08
	if (cr6.eq) goto loc_82776F08;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,11
	ctx.r10.s64 = 11;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82776F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82776F08:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82776f34
	if (!cr6.eq) goto loc_82776F34;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776F20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776e84
	if (cr6.eq) goto loc_82776E84;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82776F34:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addic. r27,r28,-1
	xer.ca = r28.u32 > 0;
	r27.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// rotlwi r28,r11,8
	r28.u64 = __builtin_rotateleft32(r11.u32, 8);
	// bne 0x82776f6c
	if (!cr0.eq) goto loc_82776F6C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82776F58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82776e84
	if (cr6.eq) goto loc_82776E84;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r27,4(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82776F6C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r9,82
	ctx.r9.s64 = 82;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r28,r11,r28
	r28.u64 = r11.u64 + r28.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r28,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, r28.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82776FA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r29,1
	ctx.r5.s64 = r29.s64 + 1;
	// addi r4,r27,-1
	ctx.r4.s64 = r27.s64 + -1;
	// stw r28,252(r30)
	PPC_STORE_U32(r30.u32 + 252, r28.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82776FC0"))) PPC_WEAK_FUNC(sub_82776FC0);
PPC_FUNC_IMPL(__imp__sub_82776FC0) {
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
	ctx.lr = 0x82776FC8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// add r29,r5,r6
	r29.u64 = ctx.r5.u64 + ctx.r6.u64;
	// cmplwi cr6,r5,14
	cr6.compare<uint32_t>(ctx.r5.u32, 14, xer);
	// blt cr6,0x827771a0
	if (cr6.lt) goto loc_827771A0;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,74
	cr6.compare<uint32_t>(r11.u32, 74, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// cmplwi cr6,r11,70
	cr6.compare<uint32_t>(r11.u32, 70, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// cmplwi cr6,r11,73
	cr6.compare<uint32_t>(r11.u32, 73, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// lbz r11,3(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// cmplwi cr6,r11,70
	cr6.compare<uint32_t>(r11.u32, 70, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827771a0
	if (!cr6.eq) goto loc_827771A0;
	// li r11,1
	r11.s64 = 1;
	// stb r11,256(r31)
	PPC_STORE_U8(r31.u32 + 256, r11.u8);
	// lbz r10,5(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// stb r10,257(r31)
	PPC_STORE_U8(r31.u32 + 257, ctx.r10.u8);
	// lbz r9,6(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// stb r9,258(r31)
	PPC_STORE_U8(r31.u32 + 258, ctx.r9.u8);
	// lbz r8,7(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 7);
	// stb r8,259(r31)
	PPC_STORE_U8(r31.u32 + 259, ctx.r8.u8);
	// lbz r11,9(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 9);
	// lbz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// rotlwi r10,r7,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lbz r5,257(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 257);
	// sth r6,260(r31)
	PPC_STORE_U16(r31.u32 + 260, ctx.r6.u16);
	// lbz r10,11(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 11);
	// lbz r3,10(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// rotlwi r11,r3,8
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 8);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// sth r11,262(r31)
	PPC_STORE_U16(r31.u32 + 262, r11.u16);
	// beq cr6,0x827770ac
	if (cr6.eq) goto loc_827770AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,119
	ctx.r10.s64 = 119;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lbz r9,257(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 257);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r6,258(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 258);
	// stw r6,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827770AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827770AC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,87
	ctx.r10.s64 = 87;
	// lbz r9,257(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 257);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r9.u32);
	// lbz r8,258(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 258);
	// stw r8,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r8.u32);
	// lhz r7,260(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 260);
	// stw r7,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r7.u32);
	// lhz r6,262(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 262);
	// stw r6,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r6.u32);
	// lbz r5,259(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 259);
	// stw r5,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r5.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827770FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,13(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// lbz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8277714c
	if (cr6.eq) goto loc_8277714C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,90
	ctx.r10.s64 = 90;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r6,13(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// stw r6,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r6.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277714C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277714C:
	// lbz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// addi r10,r29,-14
	ctx.r10.s64 = r29.s64 + -14;
	// lbz r11,13(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r9
	ctx.r8.u64 = r11.u64 + ctx.r9.u64;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// beq cr6,0x82777284
	if (cr6.eq) goto loc_82777284;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,88
	ctx.r9.s64 = 88;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82777198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_827771A0:
	// cmplwi cr6,r5,6
	cr6.compare<uint32_t>(ctx.r5.u32, 6, xer);
	// blt cr6,0x82777258
	if (cr6.lt) goto loc_82777258;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,74
	cr6.compare<uint32_t>(r11.u32, 74, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// cmplwi cr6,r11,70
	cr6.compare<uint32_t>(r11.u32, 70, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,2(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2);
	// cmplwi cr6,r11,88
	cr6.compare<uint32_t>(r11.u32, 88, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,3(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 3);
	// cmplwi cr6,r11,88
	cr6.compare<uint32_t>(r11.u32, 88, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82777258
	if (!cr6.eq) goto loc_82777258;
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// beq cr6,0x82777250
	if (cr6.eq) goto loc_82777250;
	// cmpwi cr6,r11,17
	cr6.compare<int32_t>(r11.s32, 17, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82777248
	if (cr6.eq) goto loc_82777248;
	// cmpwi cr6,r11,19
	cr6.compare<int32_t>(r11.s32, 19, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// beq cr6,0x82777240
	if (cr6.eq) goto loc_82777240;
	// li r10,89
	ctx.r10.s64 = 89;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lbz r8,5(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82777238;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82777240:
	// li r10,110
	ctx.r10.s64 = 110;
	// b 0x82777268
	goto loc_82777268;
loc_82777248:
	// li r10,109
	ctx.r10.s64 = 109;
	// b 0x82777264
	goto loc_82777264;
loc_82777250:
	// li r10,108
	ctx.r10.s64 = 108;
	// b 0x8277725c
	goto loc_8277725C;
loc_82777258:
	// li r10,77
	ctx.r10.s64 = 77;
loc_8277725C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
loc_82777264:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_82777268:
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82777284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82777284:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8277728C"))) PPC_WEAK_FUNC(sub_8277728C);
PPC_FUNC_IMPL(__imp__sub_8277728C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82777290"))) PPC_WEAK_FUNC(sub_82777290);
PPC_FUNC_IMPL(__imp__sub_82777290) {
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
	ctx.lr = 0x82777298;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,12
	cr6.compare<uint32_t>(ctx.r5.u32, 12, xer);
	// blt cr6,0x82777368
	if (cr6.lt) goto loc_82777368;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,65
	cr6.compare<uint32_t>(ctx.r10.u32, 65, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi cr6,r10,100
	cr6.compare<uint32_t>(ctx.r10.u32, 100, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// cmplwi cr6,r10,111
	cr6.compare<uint32_t>(ctx.r10.u32, 111, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// cmplwi cr6,r10,98
	cr6.compare<uint32_t>(ctx.r10.u32, 98, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,101
	cr6.compare<uint32_t>(ctx.r10.u32, 101, xer);
	// bne cr6,0x82777368
	if (!cr6.eq) goto loc_82777368;
	// lbz r8,9(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// li r30,76
	r30.s64 = 76;
	// lbz r10,7(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 7);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// rotlwi r6,r8,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// rotlwi r9,r10,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// rotlwi r8,r5,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// lbz r7,6(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// lbz r5,10(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lbz r29,11(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r6,r5
	r11.u64 = ctx.r6.u64 + ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,28(r10)
	PPC_STORE_U32(ctx.r10.u32 + 28, ctx.r9.u32);
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// stw r11,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, r11.u32);
	// stw r29,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, r29.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, r30.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82777354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r29,265(r31)
	PPC_STORE_U8(r31.u32 + 265, r29.u8);
	// stb r4,264(r31)
	PPC_STORE_U8(r31.u32 + 264, ctx.r4.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82777368:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,78
	ctx.r10.s64 = 78;
	// add r9,r5,r6
	ctx.r9.u64 = ctx.r5.u64 + ctx.r6.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82777398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827773A0"))) PPC_WEAK_FUNC(sub_827773A0);
PPC_FUNC_IMPL(__imp__sub_827773A0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x827773A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,24(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827773f0
	if (!cr6.eq) goto loc_827773F0;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827773D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827773e8
	if (!cr6.eq) goto loc_827773E8;
loc_827773DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_827773E8:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_827773F0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r31,r9,8
	r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x82777428
	if (!cr0.eq) goto loc_82777428;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827773dc
	if (cr6.eq) goto loc_827773DC;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82777428:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// addi r29,r10,-1
	r29.s64 = ctx.r10.s64 + -1;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// addi r26,r11,-2
	r26.s64 = r11.s64 + -2;
	// cmpwi cr6,r26,14
	cr6.compare<int32_t>(r26.s32, 14, xer);
	// blt cr6,0x8277744c
	if (cr6.lt) goto loc_8277744C;
	// li r28,14
	r28.s64 = 14;
	// b 0x8277745c
	goto loc_8277745C;
loc_8277744C:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// mr r28,r26
	r28.u64 = r26.u64;
	// bgt cr6,0x8277745c
	if (cr6.gt) goto loc_8277745C;
	// li r28,0
	r28.s64 = 0;
loc_8277745C:
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x827774b4
	if (cr6.eq) goto loc_827774B4;
loc_82777468:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82777494
	if (!cr6.eq) goto loc_82777494;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827773dc
	if (cr6.eq) goto loc_827773DC;
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r29,4(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 4);
loc_82777494:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stbx r11,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r11.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// blt cr6,0x82777468
	if (cr6.lt) goto loc_82777468;
loc_827774B4:
	// lwz r11,380(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 380);
	// subf r31,r28,r26
	r31.s64 = r26.s64 - r28.s64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// cmpwi cr6,r11,224
	cr6.compare<int32_t>(r11.s32, 224, xer);
	// beq cr6,0x82777510
	if (cr6.eq) goto loc_82777510;
	// cmpwi cr6,r11,238
	cr6.compare<int32_t>(r11.s32, 238, xer);
	// beq cr6,0x827774fc
	if (cr6.eq) goto loc_827774FC;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r10,68
	ctx.r10.s64 = 68;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r8,380(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 380);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827774F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82777520
	goto loc_82777520;
loc_827774FC:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82777290
	ctx.lr = 0x8277750C;
	sub_82777290(ctx, base);
	// b 0x82777520
	goto loc_82777520;
loc_82777510:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82776fc0
	ctx.lr = 0x82777520;
	sub_82776FC0(ctx, base);
loc_82777520:
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// stw r29,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r29.u32);
	// ble cr6,0x82777548
	if (!cr6.gt) goto loc_82777548;
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82777548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82777548:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82777554"))) PPC_WEAK_FUNC(sub_82777554);
PPC_FUNC_IMPL(__imp__sub_82777554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82777558"))) PPC_WEAK_FUNC(sub_82777558);
PPC_FUNC_IMPL(__imp__sub_82777558) {
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
	ctx.lr = 0x82777560;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,24(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827775a8
	if (!cr6.eq) goto loc_827775A8;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827775a0
	if (!cr6.eq) goto loc_827775A0;
loc_82777594:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827775A0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_827775A8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r27,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r27.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// rotlwi r29,r9,8
	r29.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// bne 0x827775e0
	if (!cr0.eq) goto loc_827775E0;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827775CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82777594
	if (cr6.eq) goto loc_82777594;
	// lwz r28,0(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r27,4(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_827775E0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,91
	ctx.r9.s64 = 91;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// addi r29,r11,-2
	r29.s64 = r11.s64 + -2;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,380(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, r29.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// addi r9,r27,-1
	ctx.r9.s64 = r27.s64 + -1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// ble cr6,0x82777654
	if (!cr6.gt) goto loc_82777654;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82777654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82777654:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82777660"))) PPC_WEAK_FUNC(sub_82777660);
PPC_FUNC_IMPL(__imp__sub_82777660) {
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
	ctx.lr = 0x82777668;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r30,24(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_8277767C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827776a8
	if (!cr6.eq) goto loc_827776A8;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777694;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82777778
	if (cr6.eq) goto loc_82777778;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_827776A8:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// beq cr6,0x82777714
	if (cr6.eq) goto loc_82777714;
loc_827776BC:
	// lwz r11,404(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// bne cr6,0x82777700
	if (!cr6.eq) goto loc_82777700;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827776EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82777778
	if (cr6.eq) goto loc_82777778;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_82777700:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// bne cr6,0x827776bc
	if (!cr6.eq) goto loc_827776BC;
loc_82777714:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82777740
	if (!cr6.eq) goto loc_82777740;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277772C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82777778
	if (cr6.eq) goto loc_82777778;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_82777740:
	// lbz r28,0(r29)
	r28.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r28,255
	cr6.compare<int32_t>(r28.s32, 255, xer);
	// beq cr6,0x82777714
	if (cr6.eq) goto loc_82777714;
	// lwz r11,404(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bne cr6,0x82777784
	if (!cr6.eq) goto loc_82777784;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// b 0x8277767c
	goto loc_8277767C;
loc_82777778:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82777784:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827777d4
	if (cr6.eq) goto loc_827777D4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r10,116
	ctx.r10.s64 = 116;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,404(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r7,20(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r28,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, r28.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827777C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,404(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 404);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
loc_827777D4:
	// stw r28,380(r27)
	PPC_STORE_U32(r27.u32 + 380, r28.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827777EC"))) PPC_WEAK_FUNC(sub_827777EC);
PPC_FUNC_IMPL(__imp__sub_827777EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827777F0"))) PPC_WEAK_FUNC(sub_827777F0);
PPC_FUNC_IMPL(__imp__sub_827777F0) {
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
	ctx.lr = 0x827777F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,24(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82777840
	if (!cr6.eq) goto loc_82777840;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82777838
	if (!cr6.eq) goto loc_82777838;
loc_8277782C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82777838:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82777840:
	// lbz r28,0(r11)
	r28.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x82777874
	if (!cr0.eq) goto loc_82777874;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82777860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277782c
	if (cr6.eq) goto loc_8277782C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82777874:
	// lbz r30,0(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r27,r10,-1
	r27.s64 = ctx.r10.s64 + -1;
	// addi r26,r11,1
	r26.s64 = r11.s64 + 1;
	// cmpwi cr6,r28,255
	cr6.compare<int32_t>(r28.s32, 255, xer);
	// bne cr6,0x82777890
	if (!cr6.eq) goto loc_82777890;
	// cmpwi cr6,r30,216
	cr6.compare<int32_t>(r30.s32, 216, xer);
	// beq cr6,0x827778c0
	if (cr6.eq) goto loc_827778C0;
loc_82777890:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,53
	ctx.r10.s64 = 53;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r28,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r28.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, r30.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827778C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827778C0:
	// stw r30,380(r29)
	PPC_STORE_U32(r29.u32 + 380, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827778D8"))) PPC_WEAK_FUNC(sub_827778D8);
PPC_FUNC_IMPL(__imp__sub_827778D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827778E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,60
	r27.s64 = 60;
	// li r28,92
	r28.s64 = 92;
	// li r29,68
	r29.s64 = 68;
	// li r30,0
	r30.s64 = 0;
loc_827778F8:
	// lwz r11,380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82777930
	if (!cr6.eq) goto loc_82777930;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82777920
	if (!cr6.eq) goto loc_82777920;
	// bl 0x827777f0
	ctx.lr = 0x8277791C;
	sub_827777F0(ctx, base);
	// b 0x82777924
	goto loc_82777924;
loc_82777920:
	// bl 0x82777660
	ctx.lr = 0x82777924;
	sub_82777660(ctx, base);
loc_82777924:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
loc_82777930:
	// lwz r11,380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmplwi cr6,r10,253
	cr6.compare<uint32_t>(ctx.r10.u32, 253, xer);
	// bgt cr6,0x82777f14
	if (cr6.gt) goto loc_82777F14;
	// lis r12,-32137
	r12.s64 = -2106130432;
	// addi r12,r12,31064
	r12.s64 = r12.s64 + 31064;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_82777EE0;
	case 1:
		goto loc_82777F14;
	case 2:
		goto loc_82777F14;
	case 3:
		goto loc_82777F14;
	case 4:
		goto loc_82777F14;
	case 5:
		goto loc_82777F14;
	case 6:
		goto loc_82777F14;
	case 7:
		goto loc_82777F14;
	case 8:
		goto loc_82777F14;
	case 9:
		goto loc_82777F14;
	case 10:
		goto loc_82777F14;
	case 11:
		goto loc_82777F14;
	case 12:
		goto loc_82777F14;
	case 13:
		goto loc_82777F14;
	case 14:
		goto loc_82777F14;
	case 15:
		goto loc_82777F14;
	case 16:
		goto loc_82777F14;
	case 17:
		goto loc_82777F14;
	case 18:
		goto loc_82777F14;
	case 19:
		goto loc_82777F14;
	case 20:
		goto loc_82777F14;
	case 21:
		goto loc_82777F14;
	case 22:
		goto loc_82777F14;
	case 23:
		goto loc_82777F14;
	case 24:
		goto loc_82777F14;
	case 25:
		goto loc_82777F14;
	case 26:
		goto loc_82777F14;
	case 27:
		goto loc_82777F14;
	case 28:
		goto loc_82777F14;
	case 29:
		goto loc_82777F14;
	case 30:
		goto loc_82777F14;
	case 31:
		goto loc_82777F14;
	case 32:
		goto loc_82777F14;
	case 33:
		goto loc_82777F14;
	case 34:
		goto loc_82777F14;
	case 35:
		goto loc_82777F14;
	case 36:
		goto loc_82777F14;
	case 37:
		goto loc_82777F14;
	case 38:
		goto loc_82777F14;
	case 39:
		goto loc_82777F14;
	case 40:
		goto loc_82777F14;
	case 41:
		goto loc_82777F14;
	case 42:
		goto loc_82777F14;
	case 43:
		goto loc_82777F14;
	case 44:
		goto loc_82777F14;
	case 45:
		goto loc_82777F14;
	case 46:
		goto loc_82777F14;
	case 47:
		goto loc_82777F14;
	case 48:
		goto loc_82777F14;
	case 49:
		goto loc_82777F14;
	case 50:
		goto loc_82777F14;
	case 51:
		goto loc_82777F14;
	case 52:
		goto loc_82777F14;
	case 53:
		goto loc_82777F14;
	case 54:
		goto loc_82777F14;
	case 55:
		goto loc_82777F14;
	case 56:
		goto loc_82777F14;
	case 57:
		goto loc_82777F14;
	case 58:
		goto loc_82777F14;
	case 59:
		goto loc_82777F14;
	case 60:
		goto loc_82777F14;
	case 61:
		goto loc_82777F14;
	case 62:
		goto loc_82777F14;
	case 63:
		goto loc_82777F14;
	case 64:
		goto loc_82777F14;
	case 65:
		goto loc_82777F14;
	case 66:
		goto loc_82777F14;
	case 67:
		goto loc_82777F14;
	case 68:
		goto loc_82777F14;
	case 69:
		goto loc_82777F14;
	case 70:
		goto loc_82777F14;
	case 71:
		goto loc_82777F14;
	case 72:
		goto loc_82777F14;
	case 73:
		goto loc_82777F14;
	case 74:
		goto loc_82777F14;
	case 75:
		goto loc_82777F14;
	case 76:
		goto loc_82777F14;
	case 77:
		goto loc_82777F14;
	case 78:
		goto loc_82777F14;
	case 79:
		goto loc_82777F14;
	case 80:
		goto loc_82777F14;
	case 81:
		goto loc_82777F14;
	case 82:
		goto loc_82777F14;
	case 83:
		goto loc_82777F14;
	case 84:
		goto loc_82777F14;
	case 85:
		goto loc_82777F14;
	case 86:
		goto loc_82777F14;
	case 87:
		goto loc_82777F14;
	case 88:
		goto loc_82777F14;
	case 89:
		goto loc_82777F14;
	case 90:
		goto loc_82777F14;
	case 91:
		goto loc_82777F14;
	case 92:
		goto loc_82777F14;
	case 93:
		goto loc_82777F14;
	case 94:
		goto loc_82777F14;
	case 95:
		goto loc_82777F14;
	case 96:
		goto loc_82777F14;
	case 97:
		goto loc_82777F14;
	case 98:
		goto loc_82777F14;
	case 99:
		goto loc_82777F14;
	case 100:
		goto loc_82777F14;
	case 101:
		goto loc_82777F14;
	case 102:
		goto loc_82777F14;
	case 103:
		goto loc_82777F14;
	case 104:
		goto loc_82777F14;
	case 105:
		goto loc_82777F14;
	case 106:
		goto loc_82777F14;
	case 107:
		goto loc_82777F14;
	case 108:
		goto loc_82777F14;
	case 109:
		goto loc_82777F14;
	case 110:
		goto loc_82777F14;
	case 111:
		goto loc_82777F14;
	case 112:
		goto loc_82777F14;
	case 113:
		goto loc_82777F14;
	case 114:
		goto loc_82777F14;
	case 115:
		goto loc_82777F14;
	case 116:
		goto loc_82777F14;
	case 117:
		goto loc_82777F14;
	case 118:
		goto loc_82777F14;
	case 119:
		goto loc_82777F14;
	case 120:
		goto loc_82777F14;
	case 121:
		goto loc_82777F14;
	case 122:
		goto loc_82777F14;
	case 123:
		goto loc_82777F14;
	case 124:
		goto loc_82777F14;
	case 125:
		goto loc_82777F14;
	case 126:
		goto loc_82777F14;
	case 127:
		goto loc_82777F14;
	case 128:
		goto loc_82777F14;
	case 129:
		goto loc_82777F14;
	case 130:
		goto loc_82777F14;
	case 131:
		goto loc_82777F14;
	case 132:
		goto loc_82777F14;
	case 133:
		goto loc_82777F14;
	case 134:
		goto loc_82777F14;
	case 135:
		goto loc_82777F14;
	case 136:
		goto loc_82777F14;
	case 137:
		goto loc_82777F14;
	case 138:
		goto loc_82777F14;
	case 139:
		goto loc_82777F14;
	case 140:
		goto loc_82777F14;
	case 141:
		goto loc_82777F14;
	case 142:
		goto loc_82777F14;
	case 143:
		goto loc_82777F14;
	case 144:
		goto loc_82777F14;
	case 145:
		goto loc_82777F14;
	case 146:
		goto loc_82777F14;
	case 147:
		goto loc_82777F14;
	case 148:
		goto loc_82777F14;
	case 149:
		goto loc_82777F14;
	case 150:
		goto loc_82777F14;
	case 151:
		goto loc_82777F14;
	case 152:
		goto loc_82777F14;
	case 153:
		goto loc_82777F14;
	case 154:
		goto loc_82777F14;
	case 155:
		goto loc_82777F14;
	case 156:
		goto loc_82777F14;
	case 157:
		goto loc_82777F14;
	case 158:
		goto loc_82777F14;
	case 159:
		goto loc_82777F14;
	case 160:
		goto loc_82777F14;
	case 161:
		goto loc_82777F14;
	case 162:
		goto loc_82777F14;
	case 163:
		goto loc_82777F14;
	case 164:
		goto loc_82777F14;
	case 165:
		goto loc_82777F14;
	case 166:
		goto loc_82777F14;
	case 167:
		goto loc_82777F14;
	case 168:
		goto loc_82777F14;
	case 169:
		goto loc_82777F14;
	case 170:
		goto loc_82777F14;
	case 171:
		goto loc_82777F14;
	case 172:
		goto loc_82777F14;
	case 173:
		goto loc_82777F14;
	case 174:
		goto loc_82777F14;
	case 175:
		goto loc_82777F14;
	case 176:
		goto loc_82777F14;
	case 177:
		goto loc_82777F14;
	case 178:
		goto loc_82777F14;
	case 179:
		goto loc_82777F14;
	case 180:
		goto loc_82777F14;
	case 181:
		goto loc_82777F14;
	case 182:
		goto loc_82777F14;
	case 183:
		goto loc_82777F14;
	case 184:
		goto loc_82777F14;
	case 185:
		goto loc_82777F14;
	case 186:
		goto loc_82777F14;
	case 187:
		goto loc_82777F14;
	case 188:
		goto loc_82777F14;
	case 189:
		goto loc_82777F14;
	case 190:
		goto loc_82777F14;
	case 191:
		goto loc_82777D70;
	case 192:
		goto loc_82777D70;
	case 193:
		goto loc_82777D94;
	case 194:
		goto loc_82777E00;
	case 195:
		goto loc_82777E34;
	case 196:
		goto loc_82777E00;
	case 197:
		goto loc_82777E00;
	case 198:
		goto loc_82777E00;
	case 199:
		goto loc_82777E00;
	case 200:
		goto loc_82777DB8;
	case 201:
		goto loc_82777DDC;
	case 202:
		goto loc_82777E00;
	case 203:
		goto loc_82777E18;
	case 204:
		goto loc_82777E00;
	case 205:
		goto loc_82777E00;
	case 206:
		goto loc_82777E00;
	case 207:
		goto loc_82777EE0;
	case 208:
		goto loc_82777EE0;
	case 209:
		goto loc_82777EE0;
	case 210:
		goto loc_82777EE0;
	case 211:
		goto loc_82777EE0;
	case 212:
		goto loc_82777EE0;
	case 213:
		goto loc_82777EE0;
	case 214:
		goto loc_82777EE0;
	case 215:
		goto loc_82777D50;
	case 216:
		goto loc_82777F68;
	case 217:
		goto loc_82777F44;
	case 218:
		goto loc_82777E50;
	case 219:
		goto loc_82777E18;
	case 220:
		goto loc_82777E6C;
	case 221:
		goto loc_82777F14;
	case 222:
		goto loc_82777F14;
	case 223:
		goto loc_82777E88;
	case 224:
		goto loc_82777E88;
	case 225:
		goto loc_82777E88;
	case 226:
		goto loc_82777E88;
	case 227:
		goto loc_82777E88;
	case 228:
		goto loc_82777E88;
	case 229:
		goto loc_82777E88;
	case 230:
		goto loc_82777E88;
	case 231:
		goto loc_82777E88;
	case 232:
		goto loc_82777E88;
	case 233:
		goto loc_82777E88;
	case 234:
		goto loc_82777E88;
	case 235:
		goto loc_82777E88;
	case 236:
		goto loc_82777E88;
	case 237:
		goto loc_82777E88;
	case 238:
		goto loc_82777E88;
	case 239:
		goto loc_82777F14;
	case 240:
		goto loc_82777F14;
	case 241:
		goto loc_82777F14;
	case 242:
		goto loc_82777F14;
	case 243:
		goto loc_82777F14;
	case 244:
		goto loc_82777F14;
	case 245:
		goto loc_82777F14;
	case 246:
		goto loc_82777F14;
	case 247:
		goto loc_82777F14;
	case 248:
		goto loc_82777F14;
	case 249:
		goto loc_82777F14;
	case 250:
		goto loc_82777F14;
	case 251:
		goto loc_82777F14;
	case 252:
		goto loc_82777F14;
	case 253:
		goto loc_82777EB8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32112(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32112);
	// lwz r19,32112(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32112);
	// lwz r19,32148(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32148);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32308(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32308);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32184(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32184);
	// lwz r19,32220(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32220);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32280(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32280);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32256(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32256);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32480(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32480);
	// lwz r19,32080(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32080);
	// lwz r19,32616(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32616);
	// lwz r19,32580(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32580);
	// lwz r19,32336(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32336);
	// lwz r19,32280(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32280);
	// lwz r19,32364(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32364);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32392(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32392);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32532(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32532);
	// lwz r19,32440(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 32440);
loc_82777D50:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775e38
	ctx.lr = 0x82777D58;
	sub_82775E38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82777f3c
	if (!cr6.eq) goto loc_82777F3C;
loc_82777D64:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82777D70:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775f18
	ctx.lr = 0x82777D80;
	sub_82775F18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777D94:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775f18
	ctx.lr = 0x82777DA4;
	sub_82775F18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777DB8:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775f18
	ctx.lr = 0x82777DC8;
	sub_82775F18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777DDC:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82775f18
	ctx.lr = 0x82777DEC;
	sub_82775F18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777E00:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,380(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// b 0x82777f28
	goto loc_82777F28;
loc_82777E18:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82777558
	ctx.lr = 0x82777E20;
	sub_82777558(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777E34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82776770
	ctx.lr = 0x82777E3C;
	sub_82776770(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777E50:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82776b20
	ctx.lr = 0x82777E58;
	sub_82776B20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777E6C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82776e48
	ctx.lr = 0x82777E74;
	sub_82776E48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777E88:
	// addi r11,r11,-217
	r11.s64 = r11.s64 + -217;
	// lwz r10,404(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82777EA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777EB8:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82777ECC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777EE0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r9,380(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82777F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777F14:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r29.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
loc_82777F28:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82777F3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82777F3C:
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// b 0x827778f8
	goto loc_827778F8;
loc_82777F44:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82776398
	ctx.lr = 0x82777F4C;
	sub_82776398(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82777d64
	if (cr6.eq) goto loc_82777D64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82777F68:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,85
	ctx.r10.s64 = 85;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82777F8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r30,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82777F9C"))) PPC_WEAK_FUNC(sub_82777F9C);
PPC_FUNC_IMPL(__imp__sub_82777F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82777FA0"))) PPC_WEAK_FUNC(sub_82777FA0);
PPC_FUNC_IMPL(__imp__sub_82777FA0) {
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
	// lwz r11,380(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82777fe8
	if (!cr6.eq) goto loc_82777FE8;
	// bl 0x82777660
	ctx.lr = 0x82777FC4;
	sub_82777660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82777fe8
	if (!cr6.eq) goto loc_82777FE8;
loc_82777FD0:
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
loc_82777FE8:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r10,380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 380);
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r9,r4,208
	ctx.r9.s64 = ctx.r4.s64 + 208;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x82778040
	if (!cr6.eq) goto loc_82778040;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,98
	ctx.r10.s64 = 98;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,404(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82778034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r4,380(r31)
	PPC_STORE_U32(r31.u32 + 380, ctx.r4.u32);
	// b 0x82778060
	goto loc_82778060;
loc_82778040:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778054;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82777fd0
	if (cr6.eq) goto loc_82777FD0;
loc_82778060:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r9,r10,29
	ctx.r9.u64 = ctx.r10.u32 & 0x7;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8277808C"))) PPC_WEAK_FUNC(sub_8277808C);
PPC_FUNC_IMPL(__imp__sub_8277808C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778090"))) PPC_WEAK_FUNC(sub_82778090);
PPC_FUNC_IMPL(__imp__sub_82778090) {
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
	ctx.lr = 0x82778098;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r10,121
	ctx.r10.s64 = 121;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r30,380(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 380);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r30.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r28,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, r28.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827780D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r27,97
	r27.s64 = 97;
loc_827780DC:
	// cmpwi cr6,r30,192
	cr6.compare<int32_t>(r30.s32, 192, xer);
	// bge cr6,0x827780ec
	if (!cr6.lt) goto loc_827780EC;
loc_827780E4:
	// li r31,2
	r31.s64 = 2;
	// b 0x82778158
	goto loc_82778158;
loc_827780EC:
	// cmpwi cr6,r30,208
	cr6.compare<int32_t>(r30.s32, 208, xer);
	// blt cr6,0x82778154
	if (cr6.lt) goto loc_82778154;
	// cmpwi cr6,r30,215
	cr6.compare<int32_t>(r30.s32, 215, xer);
	// bgt cr6,0x82778154
	if (cr6.gt) goto loc_82778154;
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x82778154
	if (cr6.eq) goto loc_82778154;
	// addi r11,r28,2
	r11.s64 = r28.s64 + 2;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x82778154
	if (cr6.eq) goto loc_82778154;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x827780e4
	if (cr6.eq) goto loc_827780E4;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x827780e4
	if (cr6.eq) goto loc_827780E4;
	// li r31,1
	r31.s64 = 1;
	// b 0x82778158
	goto loc_82778158;
loc_82778154:
	// li r31,3
	r31.s64 = 3;
loc_82778158:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r30,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r30.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r31,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, r31.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82778188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// beq cr6,0x827781d4
	if (cr6.eq) goto loc_827781D4;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// beq cr6,0x827781ac
	if (cr6.eq) goto loc_827781AC;
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// bne cr6,0x827780dc
	if (!cr6.eq) goto loc_827780DC;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827781AC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82777660
	ctx.lr = 0x827781B4;
	sub_82777660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827781c8
	if (cr6.eq) goto loc_827781C8;
	// lwz r30,380(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 380);
	// b 0x827780dc
	goto loc_827780DC;
loc_827781C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_827781D4:
	// li r11,0
	r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,380(r29)
	PPC_STORE_U32(r29.u32 + 380, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827781E8"))) PPC_WEAK_FUNC(sub_827781E8);
PPC_FUNC_IMPL(__imp__sub_827781E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,404(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// li r11,0
	r11.s64 = 0;
	// stw r11,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, r11.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r11.u32);
	// stw r11,380(r3)
	PPC_STORE_U32(ctx.r3.u32 + 380, r11.u32);
	// stb r11,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, r11.u8);
	// stb r11,13(r10)
	PPC_STORE_U8(ctx.r10.u32 + 13, r11.u8);
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r11.u32);
	// stw r11,160(r10)
	PPC_STORE_U32(ctx.r10.u32 + 160, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82778210"))) PPC_WEAK_FUNC(sub_82778210);
PPC_FUNC_IMPL(__imp__sub_82778210) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,168
	ctx.r5.s64 = 168;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277823C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r7,-32137
	ctx.r7.s64 = -2106130432;
	// stw r3,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r3.u32);
	// lis r6,-32137
	ctx.r6.s64 = -2106130432;
	// lis r8,-32137
	ctx.r8.s64 = -2106130432;
	// addi r5,r9,-32280
	ctx.r5.s64 = ctx.r9.s64 + -32280;
	// addi r10,r7,32672
	ctx.r10.s64 = ctx.r7.s64 + 32672;
	// addi r9,r6,30040
	ctx.r9.s64 = ctx.r6.s64 + 30040;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// addi r4,r8,30936
	ctx.r4.s64 = ctx.r8.s64 + 30936;
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// addi r10,r3,96
	ctx.r10.s64 = ctx.r3.s64 + 96;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r9,16
	ctx.r9.s64 = 16;
loc_82778280:
	// lis r8,-32137
	ctx.r8.s64 = -2106130432;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r7,r8,30040
	ctx.r7.s64 = ctx.r8.s64 + 30040;
	// stw r7,-68(r10)
	PPC_STORE_U32(ctx.r10.u32 + -68, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82778280
	if (!cr0.eq) goto loc_82778280;
	// lis r10,-32137
	ctx.r10.s64 = -2106130432;
	// lis r9,-32137
	ctx.r9.s64 = -2106130432;
	// addi r8,r10,29600
	ctx.r8.s64 = ctx.r10.s64 + 29600;
	// addi r7,r9,29600
	ctx.r7.s64 = ctx.r9.s64 + 29600;
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// stw r7,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r7.u32);
	// lwz r6,404(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// stw r11,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r11.u32);
	// stb r11,12(r6)
	PPC_STORE_U8(ctx.r6.u32 + 12, r11.u8);
	// stb r11,13(r6)
	PPC_STORE_U8(ctx.r6.u32 + 13, r11.u8);
	// stw r11,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r11.u32);
	// stw r11,160(r6)
	PPC_STORE_U32(ctx.r6.u32 + 160, r11.u32);
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

__attribute__((alias("__imp__sub_827782E8"))) PPC_WEAK_FUNC(sub_827782E8);
PPC_FUNC_IMPL(__imp__sub_827782E8) {
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
	ctx.lr = 0x827782F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// beq cr6,0x8277833c
	if (cr6.eq) goto loc_8277833C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r9,62
	ctx.r9.s64 = 62;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r4,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r4.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8277833C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277833C:
	// cmplwi cr6,r29,432
	cr6.compare<uint32_t>(r29.u32, 432, xer);
	// beq cr6,0x82778378
	if (cr6.eq) goto loc_82778378;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,21
	ctx.r10.s64 = 21;
	// li r9,432
	ctx.r9.s64 = 432;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82778378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778378:
	// li r5,432
	ctx.r5.s64 = 432;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x82778390;
	sub_823D9890(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x8277bbd8
	ctx.lr = 0x827783A8;
	sub_8277BBD8(ctx, base);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// stw r30,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r30.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
loc_827783CC:
	// stw r30,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827783cc
	if (!cr0.eq) goto loc_827783CC;
	// stw r30,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82778210
	ctx.lr = 0x827783EC;
	sub_82778210(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277ab78
	ctx.lr = 0x827783F4;
	sub_8277AB78(ctx, base);
	// li r11,200
	r11.s64 = 200;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82778404"))) PPC_WEAK_FUNC(sub_82778404);
PPC_FUNC_IMPL(__imp__sub_82778404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778408"))) PPC_WEAK_FUNC(sub_82778408);
PPC_FUNC_IMPL(__imp__sub_82778408) {
	PPC_FUNC_PROLOGUE();
	// b 0x8277a250
	sub_8277A250(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8277840C"))) PPC_WEAK_FUNC(sub_8277840C);
PPC_FUNC_IMPL(__imp__sub_8277840C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778410"))) PPC_WEAK_FUNC(sub_82778410);
PPC_FUNC_IMPL(__imp__sub_82778410) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82778418;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// li r27,2
	r27.s64 = 2;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x827785dc
	if (cr6.eq) goto loc_827785DC;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x827784d4
	if (cr6.eq) goto loc_827784D4;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82778454
	if (cr6.eq) goto loc_82778454;
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// stw r29,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r29.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_82778454:
	// lbz r11,264(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 264);
	// li r30,4
	r30.s64 = 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827784c8
	if (cr6.eq) goto loc_827784C8;
	// lbz r11,265(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827784c8
	if (cr6.eq) goto loc_827784C8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x827784b8
	if (cr6.eq) goto loc_827784B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,114
	ctx.r10.s64 = 114;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lbz r9,265(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827784A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_827784B8:
	// li r11,5
	r11.s64 = 5;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_827784C8:
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_827784D4:
	// lbz r11,256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82778564
	if (!cr6.eq) goto loc_82778564;
	// lbz r11,264(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 264);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277853c
	if (cr6.eq) goto loc_8277853C;
	// lbz r11,265(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8277858c
	if (cr6.lt) goto loc_8277858C;
	// beq cr6,0x82778564
	if (cr6.eq) goto loc_82778564;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,114
	ctx.r10.s64 = 114;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lbz r9,265(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 265);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277852C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_8277853C:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// lwz r8,168(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82778574
	if (!cr6.eq) goto loc_82778574;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
loc_82778564:
	// li r11,3
	r11.s64 = 3;
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_82778574:
	// cmpwi cr6,r10,82
	cr6.compare<int32_t>(ctx.r10.s32, 82, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
	// cmpwi cr6,r9,71
	cr6.compare<int32_t>(ctx.r9.s32, 71, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
	// cmpwi cr6,r8,66
	cr6.compare<int32_t>(ctx.r8.s32, 66, xer);
	// bne cr6,0x82778598
	if (!cr6.eq) goto loc_82778598;
loc_8277858C:
	// stw r27,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r27.u32);
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_82778598:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,111
	ctx.r7.s64 = 111;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r7,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r7.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827785CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// b 0x827785e4
	goto loc_827785E4;
loc_827785DC:
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// stw r28,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r28.u32);
loc_827785E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r28,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r28.u32);
	// li r10,256
	ctx.r10.s64 = 256;
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
	// stb r29,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r29.u8);
	// stb r29,65(r31)
	PPC_STORE_U8(r31.u32 + 65, r29.u8);
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// lfd f0,21560(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 21560);
	// stb r28,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r28.u8);
	// stfd f0,56(r31)
	PPC_STORE_U64(r31.u32 + 56, f0.u64);
	// stb r28,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r28.u8);
	// stb r29,74(r31)
	PPC_STORE_U8(r31.u32 + 74, r29.u8);
	// stw r27,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r27.u32);
	// stb r28,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r28.u8);
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// stw r29,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r29.u32);
	// stb r29,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r29.u8);
	// stb r29,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r29.u8);
	// stb r29,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r29.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82778638"))) PPC_WEAK_FUNC(sub_82778638);
PPC_FUNC_IMPL(__imp__sub_82778638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r11,-200
	r11.s64 = r11.s64 + -200;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// bgt cr6,0x8277872c
	if (cr6.gt) goto loc_8277872C;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,-31108
	r12.s64 = r12.s64 + -31108;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_827786A8;
	case 1:
		goto loc_827786D8;
	case 2:
		goto loc_8277870C;
	case 3:
		goto loc_82778714;
	case 4:
		goto loc_82778714;
	case 5:
		goto loc_82778714;
	case 6:
		goto loc_82778714;
	case 7:
		goto loc_82778714;
	case 8:
		goto loc_82778714;
	case 9:
		goto loc_8277872C;
	case 10:
		goto loc_82778714;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-31064(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -31064);
	// lwz r19,-31016(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -31016);
	// lwz r19,-30964(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30964);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
	// lwz r19,-30932(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30932);
	// lwz r19,-30956(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -30956);
loc_827786A8:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827786BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827786D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r7,201
	ctx.r7.s64 = 201;
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
loc_827786D8:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827786EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x82778758
	if (!cr6.eq) goto loc_82778758;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82778410
	ctx.lr = 0x82778700;
	sub_82778410(ctx, base);
	// li r11,202
	r11.s64 = 202;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// b 0x82778758
	goto loc_82778758;
loc_8277870C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8277875c
	goto loc_8277875C;
loc_82778714:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8277875c
	goto loc_8277875C;
loc_8277872C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778758;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778758:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8277875C:
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

__attribute__((alias("__imp__sub_82778774"))) PPC_WEAK_FUNC(sub_82778774);
PPC_FUNC_IMPL(__imp__sub_82778774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778778"))) PPC_WEAK_FUNC(sub_82778778);
PPC_FUNC_IMPL(__imp__sub_82778778) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,205
	cr6.compare<int32_t>(r11.s32, 205, xer);
	// beq cr6,0x827787a0
	if (cr6.eq) goto loc_827787A0;
	// cmpwi cr6,r11,206
	cr6.compare<int32_t>(r11.s32, 206, xer);
	// bne cr6,0x827787fc
	if (!cr6.eq) goto loc_827787FC;
loc_827787A0:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827787fc
	if (!cr6.eq) goto loc_827787FC;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x827787dc
	if (!cr6.lt) goto loc_827787DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,67
	ctx.r10.s64 = 67;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827787DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827787DC:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827787F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,210
	ctx.r9.s64 = 210;
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// b 0x82778844
	goto loc_82778844;
loc_827787FC:
	// cmpwi cr6,r11,207
	cr6.compare<int32_t>(r11.s32, 207, xer);
	// bne cr6,0x82778810
	if (!cr6.eq) goto loc_82778810;
	// li r11,210
	r11.s64 = 210;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// b 0x82778844
	goto loc_82778844;
loc_82778810:
	// cmpwi cr6,r11,210
	cr6.compare<int32_t>(r11.s32, 210, xer);
	// beq cr6,0x82778844
	if (cr6.eq) goto loc_82778844;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778844:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,17(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82778880
	if (!cr6.eq) goto loc_82778880;
loc_82778854:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827788b4
	if (cr6.eq) goto loc_827788B4;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,17(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778854
	if (cr6.eq) goto loc_82778854;
loc_82778880:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a1e8
	ctx.lr = 0x8277889C;
	sub_8277A1E8(ctx, base);
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
loc_827788B4:
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

__attribute__((alias("__imp__sub_827788CC"))) PPC_WEAK_FUNC(sub_827788CC);
PPC_FUNC_IMPL(__imp__sub_827788CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827788D0"))) PPC_WEAK_FUNC(sub_827788D0);
PPC_FUNC_IMPL(__imp__sub_827788D0) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,200
	cr6.compare<int32_t>(r11.s32, 200, xer);
	// beq cr6,0x82778928
	if (cr6.eq) goto loc_82778928;
	// cmpwi cr6,r11,201
	cr6.compare<int32_t>(r11.s32, 201, xer);
	// beq cr6,0x82778928
	if (cr6.eq) goto loc_82778928;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778928;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778928:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82778638
	ctx.lr = 0x82778930;
	sub_82778638(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8277897c
	if (cr6.eq) goto loc_8277897C;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82778980
	if (!cr6.eq) goto loc_82778980;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277896c
	if (cr6.eq) goto loc_8277896C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,51
	ctx.r10.s64 = 51;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277896C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277896C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a1e8
	ctx.lr = 0x82778974;
	sub_8277A1E8(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x82778980
	goto loc_82778980;
loc_8277897C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82778980:
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

__attribute__((alias("__imp__sub_82778998"))) PPC_WEAK_FUNC(sub_82778998);
PPC_FUNC_IMPL(__imp__sub_82778998) {
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
	ctx.lr = 0x827789A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,204
	cr6.compare<int32_t>(r11.s32, 204, xer);
	// beq cr6,0x827789d4
	if (cr6.eq) goto loc_827789D4;
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827789C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,204
	ctx.r9.s64 = 204;
	// stw r29,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r29.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
loc_827789D4:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778aa4
	if (cr6.eq) goto loc_82778AA4;
	// addi r30,r31,120
	r30.s64 = r31.s64 + 120;
loc_827789E8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x82778a68
	if (!cr6.lt) goto loc_82778A68;
loc_827789F8:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778a28
	if (cr6.eq) goto loc_82778A28;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82778A28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778A28:
	// lwz r11,388(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r28,0(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778A4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// beq cr6,0x82778ac8
	if (cr6.eq) goto loc_82778AC8;
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x827789f8
	if (cr6.lt) goto loc_827789F8;
loc_82778A68:
	// lwz r11,384(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778A7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,384(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82778A90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lwz r7,384(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// lbz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x827789e8
	if (!cr6.eq) goto loc_827789E8;
loc_82778AA4:
	// lbz r11,65(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// li r3,1
	ctx.r3.s64 = 1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r8,r11,205
	ctx.r8.s64 = r11.s64 + 205;
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82778AC8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82778AD4"))) PPC_WEAK_FUNC(sub_82778AD4);
PPC_FUNC_IMPL(__imp__sub_82778AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778AD8"))) PPC_WEAK_FUNC(sub_82778AD8);
PPC_FUNC_IMPL(__imp__sub_82778AD8) {
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
	ctx.lr = 0x82778AE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,205
	cr6.compare<int32_t>(r11.s32, 205, xer);
	// beq cr6,0x82778b24
	if (cr6.eq) goto loc_82778B24;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778B24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778B24:
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82778b64
	if (cr6.lt) goto loc_82778B64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,123
	ctx.r10.s64 = 123;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82778B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82778B64:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82778b94
	if (cr6.eq) goto loc_82778B94;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82778B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778B94:
	// li r11,0
	r11.s64 = 0;
	// lwz r10,388(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82778BBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// stw r8,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82778BD4"))) PPC_WEAK_FUNC(sub_82778BD4);
PPC_FUNC_IMPL(__imp__sub_82778BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778BD8"))) PPC_WEAK_FUNC(sub_82778BD8);
PPC_FUNC_IMPL(__imp__sub_82778BD8) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,202
	cr6.compare<int32_t>(r11.s32, 202, xer);
	// bne cr6,0x82778c30
	if (!cr6.eq) goto loc_82778C30;
	// bl 0x8277c628
	ctx.lr = 0x82778BFC;
	sub_8277C628(ctx, base);
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82778c28
	if (cr6.eq) goto loc_82778C28;
	// li r11,207
	r11.s64 = 207;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
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
loc_82778C28:
	// li r11,203
	r11.s64 = 203;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_82778C30:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,203
	cr6.compare<int32_t>(r11.s32, 203, xer);
	// bne cr6,0x82778d00
	if (!cr6.eq) goto loc_82778D00;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778cf4
	if (cr6.eq) goto loc_82778CF4;
loc_82778C4C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82778c68
	if (cr6.eq) goto loc_82778C68;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82778C68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778C68:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82778cdc
	if (cr6.eq) goto loc_82778CDC;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82778cf4
	if (cr6.eq) goto loc_82778CF4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82778c4c
	if (cr6.eq) goto loc_82778C4C;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x82778ca8
	if (cr6.eq) goto loc_82778CA8;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82778c4c
	if (!cr6.eq) goto loc_82778C4C;
loc_82778CA8:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x82778c4c
	if (cr6.lt) goto loc_82778C4C;
	// lwz r10,284(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 284);
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// b 0x82778c4c
	goto loc_82778C4C;
loc_82778CDC:
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
loc_82778CF4:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// b 0x82778d34
	goto loc_82778D34;
loc_82778D00:
	// cmpwi cr6,r11,204
	cr6.compare<int32_t>(r11.s32, 204, xer);
	// beq cr6,0x82778d34
	if (cr6.eq) goto loc_82778D34;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82778D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778D34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82778998
	ctx.lr = 0x82778D3C;
	sub_82778998(ctx, base);
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

__attribute__((alias("__imp__sub_82778D50"))) PPC_WEAK_FUNC(sub_82778D50);
PPC_FUNC_IMPL(__imp__sub_82778D50) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778D74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a250
	ctx.lr = 0x82778D7C;
	sub_8277A250(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823db0a0
	ctx.lr = 0x82778D84;
	sub_823DB0A0(ctx, base);
}

__attribute__((alias("__imp__sub_82778D84"))) PPC_WEAK_FUNC(sub_82778D84);
PPC_FUNC_IMPL(__imp__sub_82778D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778D88"))) PPC_WEAK_FUNC(sub_82778D88);
PPC_FUNC_IMPL(__imp__sub_82778D88) {
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
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82778DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// addi r30,r9,9028
	r30.s64 = ctx.r9.s64 + 9028;
	// bl 0x823e1160
	ctx.lr = 0x82778DC0;
	sub_823E1160(ctx, base);
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x827a7460
	ctx.lr = 0x82778DD0;
	sub_827A7460(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
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

__attribute__((alias("__imp__sub_82778DE8"))) PPC_WEAK_FUNC(sub_82778DE8);
PPC_FUNC_IMPL(__imp__sub_82778DE8) {
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
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x82778e48
	if (!cr6.lt) goto loc_82778E48;
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82778e1c
	if (cr6.eq) goto loc_82778E1C;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x82778e28
	if (cr6.lt) goto loc_82778E28;
loc_82778E1C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82778E28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778E28:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
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
loc_82778E48:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// blt cr6,0x82778e60
	if (cr6.lt) goto loc_82778E60;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82778E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82778E60:
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

__attribute__((alias("__imp__sub_82778E74"))) PPC_WEAK_FUNC(sub_82778E74);
PPC_FUNC_IMPL(__imp__sub_82778E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778E78"))) PPC_WEAK_FUNC(sub_82778E78);
PPC_FUNC_IMPL(__imp__sub_82778E78) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82778ebc
	if (!cr6.gt) goto loc_82778EBC;
	// lwz r9,116(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bgt cr6,0x82778ebc
	if (cr6.gt) goto loc_82778EBC;
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// b 0x82778eec
	goto loc_82778EEC;
loc_82778EBC:
	// lwz r8,120(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82778ef4
	if (cr6.eq) goto loc_82778EF4;
	// lwz r9,124(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82778ef4
	if (cr6.lt) goto loc_82778EF4;
	// lwz r6,128(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bgt cr6,0x82778ef4
	if (cr6.gt) goto loc_82778EF4;
	// subf r9,r9,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
loc_82778EEC:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82778f00
	if (!cr6.eq) goto loc_82778F00;
loc_82778EF4:
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
loc_82778F00:
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82778f44
	if (cr6.eq) goto loc_82778F44;
loc_82778F18:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r10,37
	cr6.compare<int32_t>(ctx.r10.s32, 37, xer);
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// beq cr6,0x82778f38
	if (cr6.eq) goto loc_82778F38;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82778f18
	if (!cr6.eq) goto loc_82778F18;
	// b 0x82778f44
	goto loc_82778F44;
loc_82778F38:
	// cmplwi cr6,r10,115
	cr6.compare<uint32_t>(ctx.r10.u32, 115, xer);
	// bne cr6,0x82778f44
	if (!cr6.eq) goto loc_82778F44;
	// li r8,1
	ctx.r8.s64 = 1;
loc_82778F44:
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82778f60
	if (cr6.eq) goto loc_82778F60;
	// addi r5,r11,24
	ctx.r5.s64 = r11.s64 + 24;
	// bl 0x823dc018
	ctx.lr = 0x82778F5C;
	sub_823DC018(ctx, base);
	// b 0x82778f8c
	goto loc_82778F8C;
loc_82778F60:
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r30,48(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r7,32(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// bl 0x823dc018
	ctx.lr = 0x82778F8C;
	sub_823DC018(ctx, base);
loc_82778F8C:
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

__attribute__((alias("__imp__sub_82778FA4"))) PPC_WEAK_FUNC(sub_82778FA4);
PPC_FUNC_IMPL(__imp__sub_82778FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82778FA8"))) PPC_WEAK_FUNC(sub_82778FA8);
PPC_FUNC_IMPL(__imp__sub_82778FA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82778FC0"))) PPC_WEAK_FUNC(sub_82778FC0);
PPC_FUNC_IMPL(__imp__sub_82778FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// addi r4,r10,-29360
	ctx.r4.s64 = ctx.r10.s64 + -29360;
	// addi r10,r5,32656
	ctx.r10.s64 = ctx.r5.s64 + 32656;
	// li r11,0
	r11.s64 = 0;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// addi r9,r9,-29208
	ctx.r9.s64 = ctx.r9.s64 + -29208;
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
	// addi r8,r8,-29304
	ctx.r8.s64 = ctx.r8.s64 + -29304;
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// addi r7,r7,-29064
	ctx.r7.s64 = ctx.r7.s64 + -29064;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// addi r6,r6,-28760
	ctx.r6.s64 = ctx.r6.s64 + -28760;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// li r5,123
	ctx.r5.s64 = 123;
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r5,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r5.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r11.u32);
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82779030"))) PPC_WEAK_FUNC(sub_82779030);
PPC_FUNC_IMPL(__imp__sub_82779030) {
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
	PPCRegister f0{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82779038;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// beq cr6,0x82779084
	if (cr6.eq) goto loc_82779084;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// li r9,62
	ctx.r9.s64 = 62;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r4,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, ctx.r4.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82779084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779084:
	// cmplwi cr6,r29,360
	cr6.compare<uint32_t>(r29.u32, 360, xer);
	// beq cr6,0x827790c0
	if (cr6.eq) goto loc_827790C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,21
	ctx.r10.s64 = 21;
	// li r9,360
	ctx.r9.s64 = 360;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,28(r7)
	PPC_STORE_U32(ctx.r7.u32 + 28, r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827790C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827790C0:
	// li r5,360
	ctx.r5.s64 = 360;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r28,12(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x827790D8;
	sub_823D9890(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// bl 0x8277bbd8
	ctx.lr = 0x827790EC;
	sub_8277BBD8(ctx, base);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// addi r11,r31,104
	r11.s64 = r31.s64 + 104;
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
loc_82779114:
	// stw r30,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82779114
	if (!cr0.eq) goto loc_82779114;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r30,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r30.u32);
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// lfd f0,21560(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 21560);
	// stfd f0,48(r31)
	PPC_STORE_U64(r31.u32 + 48, f0.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82779148"))) PPC_WEAK_FUNC(sub_82779148);
PPC_FUNC_IMPL(__imp__sub_82779148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82779158
	if (cr6.eq) goto loc_82779158;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
loc_82779158:
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82779168
	if (cr6.eq) goto loc_82779168;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
loc_82779168:
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82779178
	if (cr6.eq) goto loc_82779178;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
loc_82779178:
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82779188
	if (cr6.eq) goto loc_82779188;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
loc_82779188:
	// addi r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 + 104;
	// li r9,4
	ctx.r9.s64 = 4;
loc_82779190:
	// lwz r11,-16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827791a0
	if (cr6.eq) goto loc_827791A0;
	// stb r4,273(r11)
	PPC_STORE_U8(r11.u32 + 273, ctx.r4.u8);
loc_827791A0:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827791b0
	if (cr6.eq) goto loc_827791B0;
	// stb r4,273(r11)
	PPC_STORE_U8(r11.u32 + 273, ctx.r4.u8);
loc_827791B0:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82779190
	if (!cr0.eq) goto loc_82779190;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827791C0"))) PPC_WEAK_FUNC(sub_827791C0);
PPC_FUNC_IMPL(__imp__sub_827791C0) {
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
	ctx.lr = 0x827791C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,101
	cr6.compare<int32_t>(r11.s32, 101, xer);
	// beq cr6,0x82779214
	if (cr6.eq) goto loc_82779214;
	// cmpwi cr6,r11,102
	cr6.compare<int32_t>(r11.s32, 102, xer);
	// beq cr6,0x82779214
	if (cr6.eq) goto loc_82779214;
	// cmpwi cr6,r11,103
	cr6.compare<int32_t>(r11.s32, 103, xer);
	// beq cr6,0x82779258
	if (cr6.eq) goto loc_82779258;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// b 0x82779254
	goto loc_82779254;
loc_82779214:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x82779244
	if (!cr6.lt) goto loc_82779244;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,67
	ctx.r10.s64 = 67;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82779244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779244:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82779254:
	// bctrl 
	ctx.lr = 0x82779258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779258:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82779334
	if (!cr6.eq) goto loc_82779334;
	// li r29,24
	r29.s64 = 24;
loc_8277926C:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277927C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,224(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82779310
	if (!cr6.gt) goto loc_82779310;
loc_8277928C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827792c0
	if (cr6.eq) goto loc_827792C0;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,224(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827792C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827792C0:
	// lwz r11,328(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 328);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827792D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82779300
	if (!cr6.eq) goto loc_82779300;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r29.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82779300;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779300:
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8277928c
	if (cr6.lt) goto loc_8277928C;
loc_82779310:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82779324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lbz r9,13(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277926c
	if (cr6.eq) goto loc_8277926C;
loc_82779334:
	// lwz r11,332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 332);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82779348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277935C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a1e8
	ctx.lr = 0x82779364;
	sub_8277A1E8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8277936C"))) PPC_WEAK_FUNC(sub_8277936C);
PPC_FUNC_IMPL(__imp__sub_8277936C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82779370"))) PPC_WEAK_FUNC(sub_82779370);
PPC_FUNC_IMPL(__imp__sub_82779370) {
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
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x827793c0
	if (cr6.eq) goto loc_827793C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827793C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827793C0:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827793d8
	if (cr6.eq) goto loc_827793D8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779148
	ctx.lr = 0x827793D8;
	sub_82779148(ctx, base);
loc_827793D8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827793EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82779400;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277db10
	ctx.lr = 0x82779408;
	sub_8277DB10(ctx, base);
	// lwz r7,316(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277941C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r4,176(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// li r5,0
	ctx.r5.s64 = 0;
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// stw r5,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r5.u32);
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// addi r10,r11,101
	ctx.r10.s64 = r11.s64 + 101;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82779454"))) PPC_WEAK_FUNC(sub_82779454);
PPC_FUNC_IMPL(__imp__sub_82779454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82779458"))) PPC_WEAK_FUNC(sub_82779458);
PPC_FUNC_IMPL(__imp__sub_82779458) {
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
	ctx.lr = 0x82779460;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,101
	cr6.compare<int32_t>(r11.s32, 101, xer);
	// beq cr6,0x827794a4
	if (cr6.eq) goto loc_827794A4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827794A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827794A4:
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x827794d8
	if (cr6.lt) goto loc_827794D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,123
	ctx.r10.s64 = 123;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827794D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827794D8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277950c
	if (cr6.eq) goto loc_8277950C;
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277950C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277950C:
	// lwz r11,316(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 316);
	// lbz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277952c
	if (cr6.eq) goto loc_8277952C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277952C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277952C:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x82779544
	if (!cr6.gt) goto loc_82779544;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82779544:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277956C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + r11.u64;
	// stw r8,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82779584"))) PPC_WEAK_FUNC(sub_82779584);
PPC_FUNC_IMPL(__imp__sub_82779584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82779588"))) PPC_WEAK_FUNC(sub_82779588);
PPC_FUNC_IMPL(__imp__sub_82779588) {
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
	ctx.lr = 0x82779590;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x827795dc
	if (cr6.eq) goto loc_827795DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827795DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827795DC:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x827795ec
	if (cr6.lt) goto loc_827795EC;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x82779614
	if (cr6.lt) goto loc_82779614;
loc_827795EC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,31
	ctx.r10.s64 = 31;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r30.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82779614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779614:
	// addi r11,r30,18
	r11.s64 = r30.s64 + 18;
	// rlwinm r30,r11,2,0,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82779634
	if (!cr6.eq) goto loc_82779634;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a2a0
	ctx.lr = 0x82779630;
	sub_8277A2A0(ctx, base);
	// stwx r3,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r3.u32);
loc_82779634:
	// clrlwi r5,r28,24
	ctx.r5.u64 = r28.u32 & 0xFF;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r29,8
	ctx.r8.s64 = r29.s64 + 8;
	// li r6,100
	ctx.r6.s64 = 100;
loc_82779644:
	// lwz r11,-8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// mullw r11,r11,r27
	r11.s64 = int64_t(r11.s32) * int64_t(r27.s32);
	// addi r10,r11,50
	ctx.r10.s64 = r11.s64 + 50;
	// divw. r11,r10,r6
	r11.s32 = ctx.r10.s32 / ctx.r6.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x82779660
	if (cr0.gt) goto loc_82779660;
	// li r11,1
	r11.s64 = 1;
	// b 0x8277966c
	goto loc_8277966C;
loc_82779660:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x8277966c
	if (!cr6.gt) goto loc_8277966C;
	// li r11,32767
	r11.s64 = 32767;
loc_8277966C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82779680
	if (cr6.eq) goto loc_82779680;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x82779680
	if (!cr6.gt) goto loc_82779680;
	// li r11,255
	r11.s64 = 255;
loc_82779680:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// sthx r11,r10,r7
	PPC_STORE_U16(ctx.r10.u32 + ctx.r7.u32, r11.u16);
	// lwz r4,-4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// mullw r11,r4,r27
	r11.s64 = int64_t(ctx.r4.s32) * int64_t(r27.s32);
	// addi r3,r11,50
	ctx.r3.s64 = r11.s64 + 50;
	// divw. r11,r3,r6
	r11.s32 = ctx.r3.s32 / ctx.r6.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x827796a4
	if (cr0.gt) goto loc_827796A4;
	// li r11,1
	r11.s64 = 1;
	// b 0x827796b0
	goto loc_827796B0;
loc_827796A4:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x827796b0
	if (!cr6.gt) goto loc_827796B0;
	// li r11,32767
	r11.s64 = 32767;
loc_827796B0:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x827796c4
	if (cr6.eq) goto loc_827796C4;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x827796c4
	if (!cr6.gt) goto loc_827796C4;
	// li r11,255
	r11.s64 = 255;
loc_827796C4:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// sth r11,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, r11.u16);
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mullw r11,r9,r27
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r27.s32);
	// addi r4,r11,50
	ctx.r4.s64 = r11.s64 + 50;
	// divw. r11,r4,r6
	r11.s32 = ctx.r4.s32 / ctx.r6.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x827796ec
	if (cr0.gt) goto loc_827796EC;
	// li r11,1
	r11.s64 = 1;
	// b 0x827796f8
	goto loc_827796F8;
loc_827796EC:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x827796f8
	if (!cr6.gt) goto loc_827796F8;
	// li r11,32767
	r11.s64 = 32767;
loc_827796F8:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8277970c
	if (cr6.eq) goto loc_8277970C;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x8277970c
	if (!cr6.gt) goto loc_8277970C;
	// li r11,255
	r11.s64 = 255;
loc_8277970C:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r9,r7,6
	ctx.r9.s64 = ctx.r7.s64 + 6;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,-2(r10)
	PPC_STORE_U16(ctx.r10.u32 + -2, r11.u16);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mullw r11,r4,r27
	r11.s64 = int64_t(ctx.r4.s32) * int64_t(r27.s32);
	// addi r3,r11,50
	ctx.r3.s64 = r11.s64 + 50;
	// divw. r11,r3,r6
	r11.s32 = ctx.r3.s32 / ctx.r6.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x82779738
	if (cr0.gt) goto loc_82779738;
	// li r11,1
	r11.s64 = 1;
	// b 0x82779744
	goto loc_82779744;
loc_82779738:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x82779744
	if (!cr6.gt) goto loc_82779744;
	// li r11,32767
	r11.s64 = 32767;
loc_82779744:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82779758
	if (cr6.eq) goto loc_82779758;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x82779758
	if (!cr6.gt) goto loc_82779758;
	// li r11,255
	r11.s64 = 255;
loc_82779758:
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// cmpwi cr6,r7,128
	cr6.compare<int32_t>(ctx.r7.s32, 128, xer);
	// sthx r11,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, r11.u16);
	// blt cr6,0x82779644
	if (cr6.lt) goto loc_82779644;
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82779784"))) PPC_WEAK_FUNC(sub_82779784);
PPC_FUNC_IMPL(__imp__sub_82779784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82779788"))) PPC_WEAK_FUNC(sub_82779788);
PPC_FUNC_IMPL(__imp__sub_82779788) {
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
	ctx.lr = 0x82779790;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bgt cr6,0x827797bc
	if (cr6.gt) goto loc_827797BC;
	// li r11,1
	r11.s64 = 1;
	// li r10,5000
	ctx.r10.s64 = 5000;
	// twllei r11,0
	// divw r31,r10,r11
	r31.s32 = ctx.r10.s32 / r11.s32;
	// b 0x827797d0
	goto loc_827797D0;
loc_827797BC:
	// cmpwi cr6,r4,100
	cr6.compare<int32_t>(ctx.r4.s32, 100, xer);
	// ble cr6,0x82779810
	if (!cr6.gt) goto loc_82779810;
	// li r11,100
	r11.s64 = 100;
loc_827797C8:
	// subfic r11,r11,100
	xer.ca = r11.u32 <= 100;
	r11.s64 = 100 - r11.s64;
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_827797D0:
	// lis r11,-32242
	r11.s64 = -2113011712;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r30,r11,-32376
	r30.s64 = r11.s64 + -32376;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82779588
	ctx.lr = 0x827797F0;
	sub_82779588(ctx, base);
	// addi r5,r30,256
	ctx.r5.s64 = r30.s64 + 256;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82779588
	ctx.lr = 0x82779808;
	sub_82779588(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82779810:
	// cmpwi cr6,r4,50
	cr6.compare<int32_t>(ctx.r4.s32, 50, xer);
	// bge cr6,0x827797c8
	if (!cr6.lt) goto loc_827797C8;
	// li r10,5000
	ctx.r10.s64 = 5000;
	// twllei r11,0
	// divw r31,r10,r11
	r31.s32 = ctx.r10.s32 / r11.s32;
	// b 0x827797d0
	goto loc_827797D0;
}

__attribute__((alias("__imp__sub_82779828"))) PPC_WEAK_FUNC(sub_82779828);
PPC_FUNC_IMPL(__imp__sub_82779828) {
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
	ctx.lr = 0x82779830;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82779858
	if (!cr6.eq) goto loc_82779858;
	// bl 0x8277a2e0
	ctx.lr = 0x82779854;
	sub_8277A2E0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_82779858:
	// li r5,17
	ctx.r5.s64 = 17;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82779868;
	sub_823DA950(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// addi r11,r30,3
	r11.s64 = r30.s64 + 3;
	// li r10,4
	ctx.r10.s64 = 4;
loc_82779874:
	// lbz r8,-1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lbz r9,-2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -2);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// bne 0x82779874
	if (!cr0.eq) goto loc_82779874;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// blt cr6,0x827798b0
	if (cr6.lt) goto loc_827798B0;
	// cmpwi cr6,r31,256
	cr6.compare<int32_t>(r31.s32, 256, xer);
	// ble cr6,0x827798d0
	if (!cr6.gt) goto loc_827798D0;
loc_827798B0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,8
	ctx.r10.s64 = 8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827798D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827798D0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,17
	ctx.r3.s64 = r11.s64 + 17;
	// bl 0x823da950
	ctx.lr = 0x827798E4;
	sub_823DA950(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stb r11,273(r10)
	PPC_STORE_U8(ctx.r10.u32 + 273, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827798F8"))) PPC_WEAK_FUNC(sub_827798F8);
PPC_FUNC_IMPL(__imp__sub_827798F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82779900;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779940
	if (cr6.eq) goto loc_82779940;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779940;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779940:
	// li r31,0
	r31.s64 = 0;
	// stw r29,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r29.u32);
	// cmplwi cr6,r29,5
	cr6.compare<uint32_t>(r29.u32, 5, xer);
	// stb r31,196(r30)
	PPC_STORE_U8(r30.u32 + 196, r31.u8);
	// stb r31,204(r30)
	PPC_STORE_U8(r30.u32 + 204, r31.u8);
	// bgt cr6,0x82779c6c
	if (cr6.gt) goto loc_82779C6C;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,-26256
	r12.s64 = r12.s64 + -26256;
	// rlwinm r0,r29,2,0,29
	r0.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r29.u64) {
	case 0:
		goto loc_82779BC8;
	case 1:
		goto loc_82779988;
	case 2:
		goto loc_827799B8;
	case 3:
		goto loc_82779A30;
	case 4:
		goto loc_82779AA0;
	case 5:
		goto loc_82779B38;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-25656(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25656);
	// lwz r19,-26232(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -26232);
	// lwz r19,-26184(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -26184);
	// lwz r19,-26064(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -26064);
	// lwz r19,-25952(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25952);
	// lwz r19,-25800(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25800);
loc_82779988:
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// stb r11,196(r30)
	PPC_STORE_U8(r30.u32 + 196, r11.u8);
	// stw r11,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r11.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// stw r31,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r31.u32);
	// stw r31,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r31.u32);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_827799B8:
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,82
	ctx.r8.s64 = 82;
	// stb r11,204(r30)
	PPC_STORE_U8(r30.u32 + 204, r11.u8);
	// stw r9,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r9.u32);
	// li r7,71
	ctx.r7.s64 = 71;
	// li r6,66
	ctx.r6.s64 = 66;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// stw r31,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r31.u32);
	// stw r31,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r31.u32);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r7,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r7.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
	// stw r11,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, r11.u32);
	// stw r31,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, r31.u32);
	// stw r31,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r31.u32);
	// stw r31,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r6,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, ctx.r6.u32);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// stw r31,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r31.u32);
	// stw r31,188(r10)
	PPC_STORE_U32(ctx.r10.u32 + 188, r31.u32);
	// stw r31,192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 192, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82779A30:
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,196(r30)
	PPC_STORE_U8(r30.u32 + 196, r11.u8);
	// stw r8,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r8.u32);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// stw r31,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r31.u32);
	// stw r31,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r31.u32);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r31.u32);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r10,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, ctx.r10.u32);
	// stw r11,92(r9)
	PPC_STORE_U32(ctx.r9.u32 + 92, r11.u32);
	// stw r11,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, r11.u32);
	// stw r11,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, r11.u32);
	// stw r11,104(r9)
	PPC_STORE_U32(ctx.r9.u32 + 104, r11.u32);
	// stw r11,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, r11.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r8,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, ctx.r8.u32);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// stw r11,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r11.u32);
	// stw r11,188(r10)
	PPC_STORE_U32(ctx.r10.u32 + 188, r11.u32);
	// stw r11,192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 192, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82779AA0:
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,67
	ctx.r8.s64 = 67;
	// stb r11,204(r30)
	PPC_STORE_U8(r30.u32 + 204, r11.u8);
	// stw r9,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r9.u32);
	// li r7,77
	ctx.r7.s64 = 77;
	// li r6,89
	ctx.r6.s64 = 89;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// li r5,75
	ctx.r5.s64 = 75;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r31,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r31.u32);
	// stw r31,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r31.u32);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r7,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r7.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
	// stw r11,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, r11.u32);
	// stw r31,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, r31.u32);
	// stw r31,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r31.u32);
	// stw r31,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r6,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, ctx.r6.u32);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// stw r31,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r31.u32);
	// stw r31,188(r10)
	PPC_STORE_U32(ctx.r10.u32 + 188, r31.u32);
	// stw r31,192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 192, r31.u32);
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r5,252(r10)
	PPC_STORE_U32(ctx.r10.u32 + 252, ctx.r5.u32);
	// stw r11,260(r10)
	PPC_STORE_U32(ctx.r10.u32 + 260, r11.u32);
	// stw r11,264(r10)
	PPC_STORE_U32(ctx.r10.u32 + 264, r11.u32);
	// stw r31,268(r10)
	PPC_STORE_U32(ctx.r10.u32 + 268, r31.u32);
	// stw r31,272(r10)
	PPC_STORE_U32(ctx.r10.u32 + 272, r31.u32);
	// stw r31,276(r10)
	PPC_STORE_U32(ctx.r10.u32 + 276, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82779B38:
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,204(r30)
	PPC_STORE_U8(r30.u32 + 204, r11.u8);
	// stw r8,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// stw r31,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r31.u32);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r31.u32);
	// stw r31,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, r31.u32);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r10,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, ctx.r10.u32);
	// stw r11,92(r9)
	PPC_STORE_U32(ctx.r9.u32 + 92, r11.u32);
	// stw r11,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, r11.u32);
	// stw r11,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, r11.u32);
	// stw r11,104(r9)
	PPC_STORE_U32(ctx.r9.u32 + 104, r11.u32);
	// stw r11,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, r11.u32);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r7,168(r9)
	PPC_STORE_U32(ctx.r9.u32 + 168, ctx.r7.u32);
	// stw r11,176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 176, r11.u32);
	// stw r11,180(r9)
	PPC_STORE_U32(ctx.r9.u32 + 180, r11.u32);
	// stw r11,184(r9)
	PPC_STORE_U32(ctx.r9.u32 + 184, r11.u32);
	// stw r11,188(r9)
	PPC_STORE_U32(ctx.r9.u32 + 188, r11.u32);
	// stw r11,192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 192, r11.u32);
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r8,252(r11)
	PPC_STORE_U32(r11.u32 + 252, ctx.r8.u32);
	// stw r10,260(r11)
	PPC_STORE_U32(r11.u32 + 260, ctx.r10.u32);
	// stw r10,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r10.u32);
	// stw r31,268(r11)
	PPC_STORE_U32(r11.u32 + 268, r31.u32);
	// stw r31,272(r11)
	PPC_STORE_U32(r11.u32 + 272, r31.u32);
	// stw r31,276(r11)
	PPC_STORE_U32(r11.u32 + 276, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82779BC8:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// stw r11,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r11.u32);
	// blt cr6,0x82779be0
	if (cr6.lt) goto loc_82779BE0;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// ble cr6,0x82779c18
	if (!cr6.gt) goto loc_82779C18;
loc_82779BE0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r9,10
	ctx.r9.s64 = 10;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,60(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r9,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r9.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82779C18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779C18:
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82779c8c
	if (!cr6.gt) goto loc_82779C8C;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r11,1
	r11.s64 = 1;
loc_82779C30:
	// lwz r10,68(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r8,r8,84
	ctx.r8.s64 = ctx.r8.s64 + 84;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// stw r31,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r31.u32);
	// stw r31,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r31.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x82779c30
	if (cr6.lt) goto loc_82779C30;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82779C6C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,10
	ctx.r10.s64 = 10;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82779C8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779C8C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82779C94"))) PPC_WEAK_FUNC(sub_82779C94);
PPC_FUNC_IMPL(__imp__sub_82779C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82779C98"))) PPC_WEAK_FUNC(sub_82779C98);
PPC_FUNC_IMPL(__imp__sub_82779C98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r23{};
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
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8277a014
	if (cr6.gt) goto loc_8277A014;
	// lis r12,-32136
	r12.s64 = -2106064896;
	// addi r12,r12,-25392
	r12.s64 = r12.s64 + -25392;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82779FF4;
	case 1:
		goto loc_82779CE8;
	case 2:
		goto loc_82779D68;
	case 3:
		goto loc_82779D68;
	case 4:
		goto loc_82779E28;
	case 5:
		goto loc_82779F10;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-24588(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -24588);
	// lwz r19,-25368(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25368);
	// lwz r19,-25240(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25240);
	// lwz r19,-25240(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25240);
	// lwz r19,-25048(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -25048);
	// lwz r19,-24816(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + -24816);
loc_82779CE8:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779d20
	if (cr6.eq) goto loc_82779D20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779D20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779D20:
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stb r10,204(r31)
	PPC_STORE_U8(r31.u32 + 204, ctx.r10.u8);
	// stb r11,196(r31)
	PPC_STORE_U8(r31.u32 + 196, r11.u8);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// stw r10,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r10.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
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
loc_82779D68:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779da0
	if (cr6.eq) goto loc_82779DA0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779DA0:
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,3
	ctx.r8.s64 = 3;
	// stb r11,196(r31)
	PPC_STORE_U8(r31.u32 + 196, r11.u8);
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r10,204(r31)
	PPC_STORE_U8(r31.u32 + 204, ctx.r10.u8);
	// stw r8,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r8.u32);
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// stw r9,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r9.u32);
	// stw r10,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r10.u32);
	// stw r10,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r10.u32);
	// stw r10,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, ctx.r10.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r9,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r9.u32);
	// stw r11,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r11.u32);
	// stw r11,96(r10)
	PPC_STORE_U32(ctx.r10.u32 + 96, r11.u32);
	// stw r11,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, r11.u32);
	// stw r11,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r11.u32);
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r11.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r8,168(r10)
	PPC_STORE_U32(ctx.r10.u32 + 168, ctx.r8.u32);
	// stw r11,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, r11.u32);
	// stw r11,180(r10)
	PPC_STORE_U32(ctx.r10.u32 + 180, r11.u32);
	// stw r11,184(r10)
	PPC_STORE_U32(ctx.r10.u32 + 184, r11.u32);
	// stw r11,188(r10)
	PPC_STORE_U32(ctx.r10.u32 + 188, r11.u32);
	// stw r11,192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 192, r11.u32);
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
loc_82779E28:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779e60
	if (cr6.eq) goto loc_82779E60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779E60:
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// stb r10,196(r31)
	PPC_STORE_U8(r31.u32 + 196, ctx.r10.u8);
	// li r8,67
	ctx.r8.s64 = 67;
	// stb r11,204(r31)
	PPC_STORE_U8(r31.u32 + 204, r11.u8);
	// stw r7,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r7.u32);
	// li r6,77
	ctx.r6.s64 = 77;
	// stw r7,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r7.u32);
	// li r5,89
	ctx.r5.s64 = 89;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// li r4,75
	ctx.r4.s64 = 75;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// stw r10,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r10.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r6,84(r9)
	PPC_STORE_U32(ctx.r9.u32 + 84, ctx.r6.u32);
	// stw r11,92(r9)
	PPC_STORE_U32(ctx.r9.u32 + 92, r11.u32);
	// stw r11,96(r9)
	PPC_STORE_U32(ctx.r9.u32 + 96, r11.u32);
	// stw r10,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, ctx.r10.u32);
	// stw r10,104(r9)
	PPC_STORE_U32(ctx.r9.u32 + 104, ctx.r10.u32);
	// stw r10,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, ctx.r10.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r5,168(r9)
	PPC_STORE_U32(ctx.r9.u32 + 168, ctx.r5.u32);
	// stw r11,176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 176, r11.u32);
	// stw r11,180(r9)
	PPC_STORE_U32(ctx.r9.u32 + 180, r11.u32);
	// stw r10,184(r9)
	PPC_STORE_U32(ctx.r9.u32 + 184, ctx.r10.u32);
	// stw r10,188(r9)
	PPC_STORE_U32(ctx.r9.u32 + 188, ctx.r10.u32);
	// stw r10,192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 192, ctx.r10.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r4,252(r9)
	PPC_STORE_U32(ctx.r9.u32 + 252, ctx.r4.u32);
	// stw r11,260(r9)
	PPC_STORE_U32(ctx.r9.u32 + 260, r11.u32);
	// stw r11,264(r9)
	PPC_STORE_U32(ctx.r9.u32 + 264, r11.u32);
	// stw r10,268(r9)
	PPC_STORE_U32(ctx.r9.u32 + 268, ctx.r10.u32);
	// stw r10,272(r9)
	PPC_STORE_U32(ctx.r9.u32 + 272, ctx.r10.u32);
	// stw r10,276(r9)
	PPC_STORE_U32(ctx.r9.u32 + 276, ctx.r10.u32);
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
loc_82779F10:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x82779f48
	if (cr6.eq) goto loc_82779F48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82779F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82779F48:
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// stb r11,204(r31)
	PPC_STORE_U8(r31.u32 + 204, r11.u8);
	// li r6,5
	ctx.r6.s64 = 5;
	// stb r10,196(r31)
	PPC_STORE_U8(r31.u32 + 196, ctx.r10.u8);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r7,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r7.u32);
	// stw r6,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r6.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// stw r10,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r10.u32);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r9,84(r8)
	PPC_STORE_U32(ctx.r8.u32 + 84, ctx.r9.u32);
	// stw r11,92(r8)
	PPC_STORE_U32(ctx.r8.u32 + 92, r11.u32);
	// stw r11,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, r11.u32);
	// stw r11,100(r8)
	PPC_STORE_U32(ctx.r8.u32 + 100, r11.u32);
	// stw r11,104(r8)
	PPC_STORE_U32(ctx.r8.u32 + 104, r11.u32);
	// stw r11,108(r8)
	PPC_STORE_U32(ctx.r8.u32 + 108, r11.u32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r5,168(r8)
	PPC_STORE_U32(ctx.r8.u32 + 168, ctx.r5.u32);
	// stw r11,176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 176, r11.u32);
	// stw r11,180(r8)
	PPC_STORE_U32(ctx.r8.u32 + 180, r11.u32);
	// stw r11,184(r8)
	PPC_STORE_U32(ctx.r8.u32 + 184, r11.u32);
	// stw r11,188(r8)
	PPC_STORE_U32(ctx.r8.u32 + 188, r11.u32);
	// stw r11,192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 192, r11.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r7,252(r11)
	PPC_STORE_U32(r11.u32 + 252, ctx.r7.u32);
	// stw r9,260(r11)
	PPC_STORE_U32(r11.u32 + 260, ctx.r9.u32);
	// stw r9,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r9.u32);
	// stw r10,268(r11)
	PPC_STORE_U32(r11.u32 + 268, ctx.r10.u32);
	// stw r10,272(r11)
	PPC_STORE_U32(r11.u32 + 272, ctx.r10.u32);
	// stw r10,276(r11)
	PPC_STORE_U32(r11.u32 + 276, ctx.r10.u32);
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
loc_82779FF4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827798f8
	ctx.lr = 0x8277A000;
	sub_827798F8(ctx, base);
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
loc_8277A014:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,9
	ctx.r10.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277A034;
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

__attribute__((alias("__imp__sub_8277A048"))) PPC_WEAK_FUNC(sub_8277A048);
PPC_FUNC_IMPL(__imp__sub_8277A048) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x8277a094
	if (cr6.eq) goto loc_8277A094;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r8,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277A094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A094:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277a0c0
	if (!cr6.eq) goto loc_8277A0C0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,840
	ctx.r5.s64 = 840;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A0BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
loc_8277A0C0:
	// li r11,8
	r11.s64 = 8;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r30,r10,-32376
	r30.s64 = ctx.r10.s64 + -32376;
	// li r6,50
	ctx.r6.s64 = 50;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779588
	ctx.lr = 0x8277A0E8;
	sub_82779588(ctx, base);
	// addi r5,r30,256
	ctx.r5.s64 = r30.s64 + 256;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,50
	ctx.r6.s64 = 50;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779588
	ctx.lr = 0x8277A100;
	sub_82779588(ctx, base);
	// addi r6,r30,532
	ctx.r6.s64 = r30.s64 + 532;
	// addi r5,r30,512
	ctx.r5.s64 = r30.s64 + 512;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779828
	ctx.lr = 0x8277A114;
	sub_82779828(ctx, base);
	// addi r6,r30,600
	ctx.r6.s64 = r30.s64 + 600;
	// addi r5,r30,576
	ctx.r5.s64 = r30.s64 + 576;
	// addi r4,r31,104
	ctx.r4.s64 = r31.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779828
	ctx.lr = 0x8277A128;
	sub_82779828(ctx, base);
	// addi r6,r30,564
	ctx.r6.s64 = r30.s64 + 564;
	// addi r5,r30,544
	ctx.r5.s64 = r30.s64 + 544;
	// addi r4,r31,92
	ctx.r4.s64 = r31.s64 + 92;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779828
	ctx.lr = 0x8277A13C;
	sub_82779828(ctx, base);
	// addi r6,r30,784
	ctx.r6.s64 = r30.s64 + 784;
	// addi r5,r30,764
	ctx.r5.s64 = r30.s64 + 764;
	// addi r4,r31,108
	ctx.r4.s64 = r31.s64 + 108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82779828
	ctx.lr = 0x8277A150;
	sub_82779828(ctx, base);
	// addi r11,r31,136
	r11.s64 = r31.s64 + 136;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,5
	ctx.r7.s64 = 5;
loc_8277A164:
	// stb r10,-16(r11)
	PPC_STORE_U8(r11.u32 + -16, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// stb r7,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r7.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x8277a164
	if (!cr0.eq) goto loc_8277A164;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// stw r10,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r10.u32);
	// stw r10,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r10.u32);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// stb r10,176(r31)
	PPC_STORE_U8(r31.u32 + 176, ctx.r10.u8);
	// stb r10,177(r31)
	PPC_STORE_U8(r31.u32 + 177, ctx.r10.u8);
	// stb r10,178(r31)
	PPC_STORE_U8(r31.u32 + 178, ctx.r10.u8);
	// ble cr6,0x8277a1a0
	if (!cr6.gt) goto loc_8277A1A0;
	// stb r8,178(r31)
	PPC_STORE_U8(r31.u32 + 178, ctx.r8.u8);
loc_8277A1A0:
	// stb r10,179(r31)
	PPC_STORE_U8(r31.u32 + 179, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r10.u32);
	// stw r10,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r10.u32);
	// stw r10,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r10.u32);
	// stw r10,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r10.u32);
	// stb r8,197(r31)
	PPC_STORE_U8(r31.u32 + 197, ctx.r8.u8);
	// stb r8,198(r31)
	PPC_STORE_U8(r31.u32 + 198, ctx.r8.u8);
	// stb r10,199(r31)
	PPC_STORE_U8(r31.u32 + 199, ctx.r10.u8);
	// sth r8,200(r31)
	PPC_STORE_U16(r31.u32 + 200, ctx.r8.u16);
	// sth r8,202(r31)
	PPC_STORE_U16(r31.u32 + 202, ctx.r8.u16);
	// bl 0x82779c98
	ctx.lr = 0x8277A1D0;
	sub_82779C98(ctx, base);
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

__attribute__((alias("__imp__sub_8277A1E8"))) PPC_WEAK_FUNC(sub_8277A1E8);
PPC_FUNC_IMPL(__imp__sub_8277A1E8) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277a23c
	if (cr6.eq) goto loc_8277A23C;
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277A218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277a234
	if (cr6.eq) goto loc_8277A234;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,200
	r11.s64 = 200;
	// stw r10,268(r31)
	PPC_STORE_U32(r31.u32 + 268, ctx.r10.u32);
	// b 0x8277a238
	goto loc_8277A238;
loc_8277A234:
	// li r11,100
	r11.s64 = 100;
loc_8277A238:
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_8277A23C:
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

__attribute__((alias("__imp__sub_8277A250"))) PPC_WEAK_FUNC(sub_8277A250);
PPC_FUNC_IMPL(__imp__sub_8277A250) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277a27c
	if (cr6.eq) goto loc_8277A27C;
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277A27C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A27C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
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

__attribute__((alias("__imp__sub_8277A29C"))) PPC_WEAK_FUNC(sub_8277A29C);
PPC_FUNC_IMPL(__imp__sub_8277A29C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A2A0"))) PPC_WEAK_FUNC(sub_8277A2A0);
PPC_FUNC_IMPL(__imp__sub_8277A2A0) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,130
	ctx.r5.s64 = 130;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A2C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,128(r3)
	PPC_STORE_U8(ctx.r3.u32 + 128, ctx.r9.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277A2DC"))) PPC_WEAK_FUNC(sub_8277A2DC);
PPC_FUNC_IMPL(__imp__sub_8277A2DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A2E0"))) PPC_WEAK_FUNC(sub_8277A2E0);
PPC_FUNC_IMPL(__imp__sub_8277A2E0) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,274
	ctx.r5.s64 = 274;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,273(r3)
	PPC_STORE_U8(ctx.r3.u32 + 273, ctx.r9.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277A31C"))) PPC_WEAK_FUNC(sub_8277A31C);
PPC_FUNC_IMPL(__imp__sub_8277A31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A320"))) PPC_WEAK_FUNC(sub_8277A320);
PPC_FUNC_IMPL(__imp__sub_8277A320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// twllei r4,0
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r3,r10,r4
	ctx.r3.s32 = ctx.r10.s32 / ctx.r4.s32;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// andc r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 & ~ctx.r9.u64;
	// twlgei r8,-1
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277A344"))) PPC_WEAK_FUNC(sub_8277A344);
PPC_FUNC_IMPL(__imp__sub_8277A344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A348"))) PPC_WEAK_FUNC(sub_8277A348);
PPC_FUNC_IMPL(__imp__sub_8277A348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// twllei r4,0
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// divw r9,r11,r4
	ctx.r9.s32 = r11.s32 / ctx.r4.s32;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// mullw r8,r9,r4
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// subf r6,r8,r11
	ctx.r6.s64 = r11.s64 - ctx.r8.s64;
	// andc r5,r4,r7
	ctx.r5.u64 = ctx.r4.u64 & ~ctx.r7.u64;
	// subf r3,r6,r11
	ctx.r3.s64 = r11.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277A378"))) PPC_WEAK_FUNC(sub_8277A378);
PPC_FUNC_IMPL(__imp__sub_8277A378) {
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
	ctx.lr = 0x8277A380;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// add r31,r11,r3
	r31.u64 = r11.u64 + ctx.r3.u64;
	// add r30,r10,r5
	r30.u64 = ctx.r10.u64 + ctx.r5.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8277a3c4
	if (!cr6.gt) goto loc_8277A3C4;
loc_8277A3A4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x8277A3BC;
	sub_823DA950(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bgt 0x8277a3a4
	if (cr0.gt) goto loc_8277A3A4;
loc_8277A3C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8277A3CC"))) PPC_WEAK_FUNC(sub_8277A3CC);
PPC_FUNC_IMPL(__imp__sub_8277A3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A3D0"))) PPC_WEAK_FUNC(sub_8277A3D0);
PPC_FUNC_IMPL(__imp__sub_8277A3D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rlwinm r5,r5,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x823da950
	sub_823DA950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8277A3E4"))) PPC_WEAK_FUNC(sub_8277A3E4);
PPC_FUNC_IMPL(__imp__sub_8277A3E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A3E8"))) PPC_WEAK_FUNC(sub_8277A3E8);
PPC_FUNC_IMPL(__imp__sub_8277A3E8) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9890
	sub_823D9890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8277A3F4"))) PPC_WEAK_FUNC(sub_8277A3F4);
PPC_FUNC_IMPL(__imp__sub_8277A3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A3F8"))) PPC_WEAK_FUNC(sub_8277A3F8);
PPC_FUNC_IMPL(__imp__sub_8277A3F8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8277A400;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,0
	r11.s64 = 0;
	// ori r11,r11,65500
	r11.u64 = r11.u64 | 65500;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x8277a428
	if (cr6.gt) goto loc_8277A428;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8277a450
	if (!cr6.gt) goto loc_8277A450;
loc_8277A428:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,41
	ctx.r9.s64 = 41;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, r11.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277A450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A450:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x8277a488
	if (cr6.eq) goto loc_8277A488;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,15
	ctx.r10.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,192(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stw r9,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277A488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A488:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// ble cr6,0x8277a4cc
	if (!cr6.gt) goto loc_8277A4CC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r9,10
	ctx.r9.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r8,24(r7)
	PPC_STORE_U32(ctx.r7.u32 + 24, ctx.r8.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8277A4CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A4CC:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r27,1
	r27.s64 = 1;
	// li r26,0
	r26.s64 = 0;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// stw r27,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r27.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r29,r26
	r29.u64 = r26.u64;
	// stw r27,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r27.u32);
	// ble cr6,0x8277a580
	if (!cr6.gt) goto loc_8277A580;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// li r28,18
	r28.s64 = 18;
loc_8277A4F8:
	// lwz r11,-4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277a520
	if (!cr6.gt) goto loc_8277A520;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bgt cr6,0x8277a520
	if (cr6.gt) goto loc_8277A520;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277a520
	if (!cr6.gt) goto loc_8277A520;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// ble cr6,0x8277a53c
	if (!cr6.gt) goto loc_8277A53C;
loc_8277A520:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277A53C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A53C:
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8277a550
	if (cr6.gt) goto loc_8277A550;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277A550:
	// stw r11,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r11.u32);
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8277a568
	if (cr6.gt) goto loc_8277A568;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277A568:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r11,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r11.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277a4f8
	if (cr6.lt) goto loc_8277A4F8;
loc_8277A580:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r28,8
	r28.s64 = 8;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mr r29,r26
	r29.u64 = r26.u64;
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8277a628
	if (!cr6.gt) goto loc_8277A628;
	// addi r30,r11,28
	r30.s64 = r11.s64 + 28;
loc_8277A5A0:
	// stw r28,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r28.u32);
	// lwz r11,-20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -20);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,272(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// mullw r3,r11,r10
	ctx.r3.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r4,r9,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277A5BC;
	sub_8277A320(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// lwz r8,-16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// lwz r7,276(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// rlwinm r4,r7,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mullw r3,r8,r6
	ctx.r3.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r6.s32);
	// bl 0x8277a320
	ctx.lr = 0x8277A5D8;
	sub_8277A320(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// lwz r4,272(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r5,-20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -20);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mullw r3,r5,r3
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32);
	// bl 0x8277a320
	ctx.lr = 0x8277A5F0;
	sub_8277A320(ctx, base);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// lwz r4,276(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r11,-16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mullw r3,r11,r10
	ctx.r3.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// bl 0x8277a320
	ctx.lr = 0x8277A608;
	sub_8277A320(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// stb r27,20(r30)
	PPC_STORE_U8(r30.u32 + 20, r27.u8);
	// stw r26,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r26.u32);
	// addi r30,r30,84
	r30.s64 = r30.s64 + 84;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277a5a0
	if (cr6.lt) goto loc_8277A5A0;
loc_8277A628:
	// lwz r11,276(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277A638;
	sub_8277A320(ctx, base);
	// lwz r10,292(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r3,284(r31)
	PPC_STORE_U32(r31.u32 + 284, ctx.r3.u32);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277a668
	if (cr6.lt) goto loc_8277A668;
	// lbz r11,200(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277a668
	if (!cr6.eq) goto loc_8277A668;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stb r26,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r26.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8277A668:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stb r27,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277A678"))) PPC_WEAK_FUNC(sub_8277A678);
PPC_FUNC_IMPL(__imp__sub_8277A678) {
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
	ctx.lr = 0x8277A680;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8277a6fc
	if (!cr6.eq) goto loc_8277A6FC;
	// lwz r11,296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r9,312(r31)
	PPC_STORE_U32(r31.u32 + 312, ctx.r9.u32);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// stw r8,316(r31)
	PPC_STORE_U32(r31.u32 + 316, ctx.r8.u32);
	// lwz r6,32(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// twllei r9,0
	// divwu r5,r6,r9
	ctx.r5.u32 = ctx.r6.u32 / ctx.r9.u32;
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r10,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r10.u32);
	// mullw r4,r5,r9
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// stw r10,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r10.u32);
	// stw r7,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r7.u32);
	// stw r10,68(r11)
	PPC_STORE_U32(r11.u32 + 68, ctx.r10.u32);
	// subf. r8,r4,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r4.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x8277a6e4
	if (!cr0.eq) goto loc_8277A6E4;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_8277A6E4:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r8.u32);
	// stw r10,320(r31)
	PPC_STORE_U32(r31.u32 + 320, ctx.r10.u32);
	// stw r9,324(r31)
	PPC_STORE_U32(r31.u32 + 324, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8277A6FC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277a70c
	if (!cr6.gt) goto loc_8277A70C;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// ble cr6,0x8277a744
	if (!cr6.gt) goto loc_8277A744;
loc_8277A70C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,26
	ctx.r10.s64 = 26;
	// li r9,4
	ctx.r9.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r7,292(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,28(r6)
	PPC_STORE_U32(ctx.r6.u32 + 28, ctx.r9.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8277A744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A744:
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277A754;
	sub_8277A320(ctx, base);
	// stw r3,312(r31)
	PPC_STORE_U32(r31.u32 + 312, ctx.r3.u32);
	// lwz r10,276(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r4,r10,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8277a320
	ctx.lr = 0x8277A768;
	sub_8277A320(ctx, base);
	// lwz r9,292(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// li r29,0
	r29.s64 = 0;
	// stw r3,316(r31)
	PPC_STORE_U32(r31.u32 + 316, ctx.r3.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r29,320(r31)
	PPC_STORE_U32(r31.u32 + 320, r29.u32);
	// ble cr6,0x8277a85c
	if (!cr6.gt) goto loc_8277A85C;
	// addi r28,r31,296
	r28.s64 = r31.s64 + 296;
	// li r27,13
	r27.s64 = 13;
loc_8277A788:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// twllei r10,0
	// lwz r6,36(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// divwu r7,r8,r10
	ctx.r7.u32 = ctx.r8.u32 / ctx.r10.u32;
	// mullw r30,r9,r10
	r30.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
	// stw r30,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r30.u32);
	// stw r9,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r9.u32);
	// mullw r5,r7,r10
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// mullw r4,r6,r10
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// stw r4,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r4.u32);
	// subf. r8,r5,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x8277a7cc
	if (!cr0.eq) goto loc_8277A7CC;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_8277A7CC:
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// twllei r9,0
	// stw r8,68(r11)
	PPC_STORE_U32(r11.u32 + 68, ctx.r8.u32);
	// divwu r8,r10,r9
	ctx.r8.u32 = ctx.r10.u32 / ctx.r9.u32;
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// subf. r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8277a7ec
	if (!cr0.eq) goto loc_8277A7EC;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8277A7EC:
	// stw r10,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r10.u32);
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// ble cr6,0x8277a81c
	if (!cr6.gt) goto loc_8277A81C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r27.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277A81C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A81C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8277a848
	if (!cr6.gt) goto loc_8277A848;
loc_8277A824:
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r11,r11,81
	r11.s64 = r11.s64 + 81;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r29.u32);
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,320(r31)
	PPC_STORE_U32(r31.u32 + 320, ctx.r9.u32);
	// bgt 0x8277a824
	if (cr0.gt) goto loc_8277A824;
loc_8277A848:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8277a788
	if (cr6.lt) goto loc_8277A788;
loc_8277A85C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8277A864"))) PPC_WEAK_FUNC(sub_8277A864);
PPC_FUNC_IMPL(__imp__sub_8277A864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A868"))) PPC_WEAK_FUNC(sub_8277A868);
PPC_FUNC_IMPL(__imp__sub_8277A868) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8277A870;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277a938
	if (!cr6.gt) goto loc_8277A938;
	// addi r28,r31,296
	r28.s64 = r31.s64 + 296;
	// li r26,52
	r26.s64 = 52;
loc_8277A890:
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277a924
	if (!cr6.eq) goto loc_8277A924;
	// lwz r30,16(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8277a8c8
	if (cr6.lt) goto loc_8277A8C8;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bge cr6,0x8277a8c8
	if (!cr6.lt) goto loc_8277A8C8;
	// addi r11,r30,36
	r11.s64 = r30.s64 + 36;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8277a8ec
	if (!cr6.eq) goto loc_8277A8EC;
loc_8277A8C8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r30.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277A8EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277A8EC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,130
	ctx.r5.s64 = 130;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r30,36
	ctx.r9.s64 = r30.s64 + 36;
	// li r5,130
	ctx.r5.s64 = 130;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// bl 0x823da950
	ctx.lr = 0x8277A920;
	sub_823DA950(ctx, base);
	// stw r30,76(r29)
	PPC_STORE_U32(r29.u32 + 76, r30.u32);
loc_8277A924:
	// lwz r11,292(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8277a890
	if (cr6.lt) goto loc_8277A890;
loc_8277A938:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277A940"))) PPC_WEAK_FUNC(sub_8277A940);
PPC_FUNC_IMPL(__imp__sub_8277A940) {
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
	// bl 0x8277a678
	ctx.lr = 0x8277A958;
	sub_8277A678(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a868
	ctx.lr = 0x8277A960;
	sub_8277A868(ctx, base);
	// lwz r11,408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,392(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277A988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,392(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r6,400(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_8277A9AC"))) PPC_WEAK_FUNC(sub_8277A9AC);
PPC_FUNC_IMPL(__imp__sub_8277A9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277A9B0"))) PPC_WEAK_FUNC(sub_8277A9B0);
PPC_FUNC_IMPL(__imp__sub_8277A9B0) {
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
	ctx.lr = 0x8277A9B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,400(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lbz r11,17(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277a9dc
	if (cr6.eq) goto loc_8277A9DC;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277A9DC:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277A9F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x8277aa74
	if (cr6.eq) goto loc_8277AA74;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x8277aad0
	if (!cr6.eq) goto loc_8277AAD0;
	// lbz r11,20(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 20);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r10,17(r30)
	PPC_STORE_U8(r30.u32 + 17, ctx.r10.u8);
	// beq cr6,0x8277aa54
	if (cr6.eq) goto loc_8277AA54;
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277aad0
	if (cr6.eq) goto loc_8277AAD0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,59
	ctx.r10.s64 = 59;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277AA48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277AA54:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8277aad0
	if (!cr6.gt) goto loc_8277AAD0;
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277AA74:
	// lbz r11,20(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277aa9c
	if (cr6.eq) goto loc_8277AA9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a3f8
	ctx.lr = 0x8277AA88;
	sub_8277A3F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r11,20(r30)
	PPC_STORE_U8(r30.u32 + 20, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8277AA9C:
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277aac8
	if (!cr6.eq) goto loc_8277AAC8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,35
	ctx.r10.s64 = 35;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277AAC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AAC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277a940
	ctx.lr = 0x8277AAD0;
	sub_8277A940(ctx, base);
loc_8277AAD0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8277AADC"))) PPC_WEAK_FUNC(sub_8277AADC);
PPC_FUNC_IMPL(__imp__sub_8277AADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277AAE0"))) PPC_WEAK_FUNC(sub_8277AAE0);
PPC_FUNC_IMPL(__imp__sub_8277AAE0) {
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
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// li r31,0
	r31.s64 = 0;
	// addi r9,r10,-22096
	ctx.r9.s64 = ctx.r10.s64 + -22096;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r11,400(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 400);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stb r31,16(r11)
	PPC_STORE_U8(r11.u32 + 16, r31.u8);
	// stb r31,17(r11)
	PPC_STORE_U8(r11.u32 + 17, r31.u8);
	// stb r8,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r8.u8);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8277AB2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,404(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 404);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8277AB40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r31,140(r30)
	PPC_STORE_U32(r30.u32 + 140, r31.u32);
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

__attribute__((alias("__imp__sub_8277AB5C"))) PPC_WEAK_FUNC(sub_8277AB5C);
PPC_FUNC_IMPL(__imp__sub_8277AB5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277AB60"))) PPC_WEAK_FUNC(sub_8277AB60);
PPC_FUNC_IMPL(__imp__sub_8277AB60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,400(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 400);
	// lis r10,-32136
	ctx.r10.s64 = -2106064896;
	// addi r9,r10,-22096
	ctx.r9.s64 = ctx.r10.s64 + -22096;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8277AB74"))) PPC_WEAK_FUNC(sub_8277AB74);
PPC_FUNC_IMPL(__imp__sub_8277AB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277AB78"))) PPC_WEAK_FUNC(sub_8277AB78);
PPC_FUNC_IMPL(__imp__sub_8277AB78) {
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
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8277ABA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32136
	ctx.r9.s64 = -2106064896;
	// lis r8,-32136
	ctx.r8.s64 = -2106064896;
	// stw r3,400(r31)
	PPC_STORE_U32(r31.u32 + 400, ctx.r3.u32);
	// lis r7,-32136
	ctx.r7.s64 = -2106064896;
	// lis r6,-32136
	ctx.r6.s64 = -2106064896;
	// addi r5,r9,-22096
	ctx.r5.s64 = ctx.r9.s64 + -22096;
	// addi r4,r8,-21792
	ctx.r4.s64 = ctx.r8.s64 + -21792;
	// li r11,0
	r11.s64 = 0;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// addi r10,r7,-22208
	ctx.r10.s64 = ctx.r7.s64 + -22208;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// addi r9,r6,-21664
	ctx.r9.s64 = ctx.r6.s64 + -21664;
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stb r11,17(r3)
	PPC_STORE_U8(ctx.r3.u32 + 17, r11.u8);
	// stb r8,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_8277AC00"))) PPC_WEAK_FUNC(sub_8277AC00);
PPC_FUNC_IMPL(__imp__sub_8277AC00) {
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
	ctx.lr = 0x8277AC08;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,15258
	r11.s64 = 999948288;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = r11.u64 | 51696;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r25,4(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r22,54
	r22.s64 = 54;
	// cmplw cr6,r26,r10
	cr6.compare<uint32_t>(r26.u32, ctx.r10.u32, xer);
	// ble cr6,0x8277ac54
	if (!cr6.gt) goto loc_8277AC54;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r22,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r22.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277AC54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AC54:
	// clrlwi r11,r26,29
	r11.u64 = r26.u32 & 0x7;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ac68
	if (cr6.eq) goto loc_8277AC68;
	// subf r11,r11,r26
	r11.s64 = r26.s64 - r11.s64;
	// addi r26,r11,8
	r26.s64 = r11.s64 + 8;
loc_8277AC68:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8277ac78
	if (cr6.lt) goto loc_8277AC78;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// blt cr6,0x8277aca0
	if (cr6.lt) goto loc_8277ACA0;
loc_8277AC78:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r31,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r31.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277ACA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277ACA0:
	// addi r11,r31,13
	r11.s64 = r31.s64 + 13;
	// li r24,0
	r24.s64 = 0;
	// rlwinm r23,r11,2,0,29
	r23.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r24
	r27.u64 = r24.u64;
	// lwzx r11,r23,r25
	r11.u64 = PPC_LOAD_U32(r23.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277acd8
	if (cr6.eq) goto loc_8277ACD8;
loc_8277ACBC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r26
	cr6.compare<uint32_t>(ctx.r10.u32, r26.u32, xer);
	// bge cr6,0x8277adb0
	if (!cr6.lt) goto loc_8277ADB0;
	// mr r27,r11
	r27.u64 = r11.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277acbc
	if (!cr6.eq) goto loc_8277ACBC;
loc_8277ACD8:
	// addi r29,r26,16
	r29.s64 = r26.s64 + 16;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lis r11,-32242
	r11.s64 = -2113011712;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bne cr6,0x8277acf4
	if (!cr6.eq) goto loc_8277ACF4;
	// addi r9,r11,-31104
	ctx.r9.s64 = r11.s64 + -31104;
	// b 0x8277acfc
	goto loc_8277ACFC;
loc_8277ACF4:
	// addi r11,r11,-31104
	r11.s64 = r11.s64 + -31104;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
loc_8277ACFC:
	// lis r11,15258
	r11.s64 = 999948288;
	// lwzx r31,r10,r9
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// ori r10,r11,51712
	ctx.r10.u64 = r11.u64 | 51712;
	// subf r11,r29,r10
	r11.s64 = ctx.r10.s64 - r29.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// ble cr6,0x8277ad18
	if (!cr6.gt) goto loc_8277AD18;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8277AD18:
	// add r4,r31,r29
	ctx.r4.u64 = r31.u64 + r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277dc20
	ctx.lr = 0x8277AD24;
	sub_8277DC20(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277ad7c
	if (!cr6.eq) goto loc_8277AD7C;
	// li r28,2
	r28.s64 = 2;
loc_8277AD34:
	// rlwinm r31,r31,31,1,31
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r31,50
	cr6.compare<uint32_t>(r31.u32, 50, xer);
	// bge cr6,0x8277ad64
	if (!cr6.lt) goto loc_8277AD64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r22,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r22.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r28,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r28.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277AD64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AD64:
	// add r4,r31,r29
	ctx.r4.u64 = r31.u64 + r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277dc20
	ctx.lr = 0x8277AD70;
	sub_8277DC20(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ad34
	if (cr6.eq) goto loc_8277AD34;
loc_8277AD7C:
	// lwz r10,76(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// add r9,r31,r26
	ctx.r9.u64 = r31.u64 + r26.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + r29.u64;
	// stw r8,76(r25)
	PPC_STORE_U32(r25.u32 + 76, ctx.r8.u32);
	// stw r24,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r24.u32);
	// stw r24,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r24.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// bne cr6,0x8277adac
	if (!cr6.eq) goto loc_8277ADAC;
	// stwx r11,r23,r25
	PPC_STORE_U32(r23.u32 + r25.u32, r11.u32);
	// b 0x8277adb0
	goto loc_8277ADB0;
loc_8277ADAC:
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_8277ADB0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// add r7,r10,r26
	ctx.r7.u64 = ctx.r10.u64 + r26.u64;
	// subf r6,r26,r8
	ctx.r6.s64 = ctx.r8.s64 - r26.s64;
	// addi r3,r9,16
	ctx.r3.s64 = ctx.r9.s64 + 16;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8277ADD8"))) PPC_WEAK_FUNC(sub_8277ADD8);
PPC_FUNC_IMPL(__imp__sub_8277ADD8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8277ADE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,15258
	r11.s64 = 999948288;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = r11.u64 | 51696;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r28,4(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r26,54
	r26.s64 = 54;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x8277ae2c
	if (!cr6.gt) goto loc_8277AE2C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277AE2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AE2C:
	// clrlwi r11,r29,29
	r11.u64 = r29.u32 & 0x7;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ae40
	if (cr6.eq) goto loc_8277AE40;
	// subf r11,r11,r29
	r11.s64 = r29.s64 - r11.s64;
	// addi r29,r11,8
	r29.s64 = r11.s64 + 8;
loc_8277AE40:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x8277ae50
	if (cr6.lt) goto loc_8277AE50;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// blt cr6,0x8277ae78
	if (cr6.lt) goto loc_8277AE78;
loc_8277AE50:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r27,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r27.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277AE78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AE78:
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8277dc20
	ctx.lr = 0x8277AE84;
	sub_8277DC20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8277aeb8
	if (!cr6.eq) goto loc_8277AEB8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r26.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, ctx.r10.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277AEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AEB8:
	// lwz r11,76(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// addi r9,r27,15
	ctx.r9.s64 = r27.s64 + 15;
	// li r8,0
	ctx.r8.s64 = 0;
	// add r10,r29,r11
	ctx.r10.u64 = r29.u64 + r11.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r7,76(r28)
	PPC_STORE_U32(r28.u32 + 76, ctx.r7.u32);
	// lwzx r6,r11,r28
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stwx r31,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277AEF4"))) PPC_WEAK_FUNC(sub_8277AEF4);
PPC_FUNC_IMPL(__imp__sub_8277AEF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277AEF8"))) PPC_WEAK_FUNC(sub_8277AEF8);
PPC_FUNC_IMPL(__imp__sub_8277AEF8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8277AF00;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,15258
	r11.s64 = 999948288;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// ori r10,r11,51696
	ctx.r10.u64 = r11.u64 | 51696;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lwz r30,4(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// divwu. r31,r10,r28
	r31.u32 = ctx.r10.u32 / r28.u32;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// twllei r28,0
	// bgt 0x8277af48
	if (cr0.gt) goto loc_8277AF48;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r10,70
	ctx.r10.s64 = 70;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277AF48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277AF48:
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x8277af54
	if (cr6.lt) goto loc_8277AF54;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8277AF54:
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// rlwinm r5,r29,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8277ac00
	ctx.lr = 0x8277AF68;
	sub_8277AC00(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8277afc8
	if (cr6.eq) goto loc_8277AFC8;
loc_8277AF78:
	// subf r11,r30,r29
	r11.s64 = r29.s64 - r30.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x8277af88
	if (cr6.lt) goto loc_8277AF88;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8277AF88:
	// mullw r5,r31,r28
	ctx.r5.s64 = int64_t(r31.s32) * int64_t(r28.s32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8277add8
	ctx.lr = 0x8277AF98;
	sub_8277ADD8(ctx, base);
	// mtctr r31
	ctr.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277afc0
	if (cr6.eq) goto loc_8277AFC0;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r30,r31
	r30.u64 = r30.u64 + r31.u64;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
loc_8277AFB0:
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 + r28.u64;
	// bdnz 0x8277afb0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8277AFB0;
loc_8277AFC0:
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x8277af78
	if (cr6.lt) goto loc_8277AF78;
loc_8277AFC8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277AFD4"))) PPC_WEAK_FUNC(sub_8277AFD4);
PPC_FUNC_IMPL(__imp__sub_8277AFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277AFD8"))) PPC_WEAK_FUNC(sub_8277AFD8);
PPC_FUNC_IMPL(__imp__sub_8277AFD8) {
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
	ctx.lr = 0x8277AFE0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lis r11,15258
	r11.s64 = 999948288;
	// rlwinm r25,r24,7,0,24
	r25.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 7) & 0xFFFFFF80;
	// ori r10,r11,51696
	ctx.r10.u64 = r11.u64 | 51696;
	// lwz r30,4(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// divwu. r31,r10,r25
	r31.u32 = ctx.r10.u32 / r25.u32;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// twllei r25,0
	// bgt 0x8277b02c
	if (cr0.gt) goto loc_8277B02C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,70
	ctx.r10.s64 = 70;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277B02C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B02C:
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x8277b038
	if (cr6.lt) goto loc_8277B038;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8277B038:
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// rlwinm r5,r29,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8277ac00
	ctx.lr = 0x8277B04C;
	sub_8277AC00(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8277b0b0
	if (cr6.eq) goto loc_8277B0B0;
loc_8277B05C:
	// subf r11,r30,r29
	r11.s64 = r29.s64 - r30.s64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x8277b06c
	if (cr6.lt) goto loc_8277B06C;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8277B06C:
	// mullw r11,r31,r24
	r11.s64 = int64_t(r31.s32) * int64_t(r24.s32);
	// rlwinm r5,r11,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8277add8
	ctx.lr = 0x8277B080;
	sub_8277ADD8(ctx, base);
	// mtctr r31
	ctr.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277b0a8
	if (cr6.eq) goto loc_8277B0A8;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r30,r31
	r30.u64 = r30.u64 + r31.u64;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
loc_8277B098:
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// add r3,r25,r3
	ctx.r3.u64 = r25.u64 + ctx.r3.u64;
	// bdnz 0x8277b098
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8277B098;
loc_8277B0A8:
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x8277b05c
	if (cr6.lt) goto loc_8277B05C;
loc_8277B0B0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8277B0BC"))) PPC_WEAK_FUNC(sub_8277B0BC);
PPC_FUNC_IMPL(__imp__sub_8277B0BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277B0C0"))) PPC_WEAK_FUNC(sub_8277B0C0);
PPC_FUNC_IMPL(__imp__sub_8277B0C0) {
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
	ctx.lr = 0x8277B0C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x8277b114
	if (cr6.eq) goto loc_8277B114;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277B114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B114:
	// li r5,120
	ctx.r5.s64 = 120;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277ac00
	ctx.lr = 0x8277B124;
	sub_8277AC00(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r27.u32);
	// stw r25,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r25.u32);
	// stb r28,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r28.u8);
	// stb r11,34(r3)
	PPC_STORE_U8(ctx.r3.u32 + 34, r11.u8);
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r3,68(r30)
	PPC_STORE_U32(r30.u32 + 68, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277B154"))) PPC_WEAK_FUNC(sub_8277B154);
PPC_FUNC_IMPL(__imp__sub_8277B154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277B158"))) PPC_WEAK_FUNC(sub_8277B158);
PPC_FUNC_IMPL(__imp__sub_8277B158) {
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
	ctx.lr = 0x8277B160;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// beq cr6,0x8277b1ac
	if (cr6.eq) goto loc_8277B1AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r29.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277B1AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B1AC:
	// li r5,120
	ctx.r5.s64 = 120;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8277ac00
	ctx.lr = 0x8277B1BC;
	sub_8277AC00(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r27,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r27.u32);
	// stw r25,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r25.u32);
	// stb r28,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r28.u8);
	// stb r11,34(r3)
	PPC_STORE_U8(ctx.r3.u32 + 34, r11.u8);
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r3,72(r30)
	PPC_STORE_U32(r30.u32 + 72, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277B1EC"))) PPC_WEAK_FUNC(sub_8277B1EC);
PPC_FUNC_IMPL(__imp__sub_8277B1EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277B1F0"))) PPC_WEAK_FUNC(sub_8277B1F0);
PPC_FUNC_IMPL(__imp__sub_8277B1F0) {
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
	ctx.lr = 0x8277B1F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r31,r26
	r31.u64 = r26.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// lwz r27,4(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r11,68(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b250
	if (cr6.eq) goto loc_8277B250;
loc_8277B21C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277b244
	if (!cr6.eq) goto loc_8277B244;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// mullw r9,r7,r9
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// add r31,r10,r31
	r31.u64 = ctx.r10.u64 + r31.u64;
	// add r30,r9,r30
	r30.u64 = ctx.r9.u64 + r30.u64;
loc_8277B244:
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b21c
	if (!cr6.eq) goto loc_8277B21C;
loc_8277B250:
	// lwz r11,72(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b298
	if (cr6.eq) goto loc_8277B298;
loc_8277B25C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277b28c
	if (!cr6.eq) goto loc_8277B28C;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// rlwinm r9,r7,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// rlwinm r10,r6,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
loc_8277B28C:
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b25c
	if (!cr6.eq) goto loc_8277B25C;
loc_8277B298:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8277b420
	if (!cr6.gt) goto loc_8277B420;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r6,76(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277dc28
	ctx.lr = 0x8277B2B4;
	sub_8277DC28(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// blt cr6,0x8277b2cc
	if (cr6.lt) goto loc_8277B2CC;
	// lis r30,15258
	r30.s64 = 999948288;
	// ori r30,r30,51712
	r30.u64 = r30.u64 | 51712;
	// b 0x8277b2ec
	goto loc_8277B2EC;
loc_8277B2CC:
	// rotlwi r11,r3,1
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// divw. r30,r3,r31
	r30.s32 = ctx.r3.s32 / r31.s32;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// twllei r31,0
	// andc r10,r31,r11
	ctx.r10.u64 = r31.u64 & ~r11.u64;
	// twlgei r10,-1
	// bgt 0x8277b2ec
	if (cr0.gt) goto loc_8277B2EC;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8277B2EC:
	// lwz r31,68(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277b384
	if (cr6.eq) goto loc_8277B384;
loc_8277B2F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b378
	if (!cr6.eq) goto loc_8277B378;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// twllei r10,0
	// divwu r9,r9,r10
	ctx.r9.u32 = ctx.r9.u32 / ctx.r10.u32;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// bgt cr6,0x8277b32c
	if (cr6.gt) goto loc_8277B32C;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x8277b34c
	goto loc_8277B34C;
loc_8277B32C:
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// mullw r5,r9,r11
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277dc30
	ctx.lr = 0x8277B348;
	sub_8277DC30(ctx, base);
	// stb r28,34(r31)
	PPC_STORE_U8(r31.u32 + 34, r28.u8);
loc_8277B34C:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8277aef8
	ctx.lr = 0x8277B360;
	sub_8277AEF8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwz r11,80(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// stb r26,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r26.u8);
loc_8277B378:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8277b2f8
	if (!cr6.eq) goto loc_8277B2F8;
loc_8277B384:
	// lwz r31,72(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 72);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8277b420
	if (cr6.eq) goto loc_8277B420;
loc_8277B390:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b414
	if (!cr6.eq) goto loc_8277B414;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// twllei r10,0
	// divwu r9,r9,r10
	ctx.r9.u32 = ctx.r9.u32 / ctx.r10.u32;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// bgt cr6,0x8277b3c4
	if (cr6.gt) goto loc_8277B3C4;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x8277b3e8
	goto loc_8277B3E8;
loc_8277B3C4:
	// mullw r10,r10,r30
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// rlwinm r5,r8,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277dc30
	ctx.lr = 0x8277B3E4;
	sub_8277DC30(ctx, base);
	// stb r28,34(r31)
	PPC_STORE_U8(r31.u32 + 34, r28.u8);
loc_8277B3E8:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8277afd8
	ctx.lr = 0x8277B3FC;
	sub_8277AFD8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwz r11,80(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// stb r26,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r26.u8);
loc_8277B414:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8277b390
	if (!cr6.eq) goto loc_8277B390;
loc_8277B420:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277B428"))) PPC_WEAK_FUNC(sub_8277B428);
PPC_FUNC_IMPL(__imp__sub_8277B428) {
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
	ctx.lr = 0x8277B430;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r26,8(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mullw r28,r10,r26
	r28.s64 = int64_t(ctx.r10.s32) * int64_t(r26.s32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277b500
	if (!cr6.gt) goto loc_8277B500;
loc_8277B45C:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x8277b470
	if (!cr6.lt) goto loc_8277B470;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277B470:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277b48c
	if (cr6.lt) goto loc_8277B48C;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8277B48C:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277b4a0
	if (cr6.lt) goto loc_8277B4A0;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277B4A0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277b500
	if (!cr6.gt) goto loc_8277B500;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// mullw r29,r11,r26
	r29.s64 = int64_t(r11.s32) * int64_t(r26.s32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// beq cr6,0x8277b4dc
	if (cr6.eq) goto loc_8277B4DC;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// b 0x8277b4e0
	goto loc_8277B4E0;
loc_8277B4DC:
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_8277B4E0:
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r28,r29,r28
	r28.u64 = r29.u64 + r28.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r30,r30,r10
	r30.u64 = r30.u64 + ctx.r10.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8277b45c
	if (cr6.lt) goto loc_8277B45C;
loc_8277B500:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277B508"))) PPC_WEAK_FUNC(sub_8277B508);
PPC_FUNC_IMPL(__imp__sub_8277B508) {
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
	ctx.lr = 0x8277B510;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r26,r10,7,0,24
	r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// mullw r28,r26,r9
	r28.s64 = int64_t(r26.s32) * int64_t(ctx.r9.s32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277b5e4
	if (!cr6.gt) goto loc_8277B5E4;
loc_8277B540:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x8277b554
	if (!cr6.lt) goto loc_8277B554;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277B554:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r10,r30,r10
	ctx.r10.u64 = r30.u64 + ctx.r10.u64;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8277b570
	if (cr6.lt) goto loc_8277B570;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8277B570:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8277b584
	if (cr6.lt) goto loc_8277B584;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8277B584:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8277b5e4
	if (!cr6.gt) goto loc_8277B5E4;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// mullw r29,r11,r26
	r29.s64 = int64_t(r11.s32) * int64_t(r26.s32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// beq cr6,0x8277b5c0
	if (cr6.eq) goto loc_8277B5C0;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// b 0x8277b5c4
	goto loc_8277B5C4;
loc_8277B5C0:
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_8277B5C4:
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B5CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r28,r29,r28
	r28.u64 = r29.u64 + r28.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r30,r10,r30
	r30.u64 = ctx.r10.u64 + r30.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8277b540
	if (cr6.lt) goto loc_8277B540;
loc_8277B5E4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8277B5EC"))) PPC_WEAK_FUNC(sub_8277B5EC);
PPC_FUNC_IMPL(__imp__sub_8277B5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277B5F0"))) PPC_WEAK_FUNC(sub_8277B5F0);
PPC_FUNC_IMPL(__imp__sub_8277B5F0) {
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
	ctx.lr = 0x8277B5F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// add r30,r27,r6
	r30.u64 = r27.u64 + ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r28,22
	r28.s64 = 22;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bgt cr6,0x8277b638
	if (cr6.gt) goto loc_8277B638;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// bgt cr6,0x8277b638
	if (cr6.gt) goto loc_8277B638;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b654
	if (!cr6.eq) goto loc_8277B654;
loc_8277B638:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B654:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8277b670
	if (cr6.lt) goto loc_8277B670;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8277b6f8
	if (!cr6.gt) goto loc_8277B6F8;
loc_8277B670:
	// lbz r11,34(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b69c
	if (!cr6.eq) goto loc_8277B69C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,69
	ctx.r10.s64 = 69;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277B69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B69C:
	// lbz r11,33(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 33);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b6c0
	if (cr6.eq) goto loc_8277B6C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277b428
	ctx.lr = 0x8277B6B8;
	sub_8277B428(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
loc_8277B6C0:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// ble cr6,0x8277b6d4
	if (!cr6.gt) goto loc_8277B6D4;
	// stw r27,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r27.u32);
	// b 0x8277b6e8
	goto loc_8277B6E8;
loc_8277B6D4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x8277b6e4
	if (!cr0.lt) goto loc_8277B6E4;
	// li r11,0
	r11.s64 = 0;
loc_8277B6E4:
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
loc_8277B6E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277b428
	ctx.lr = 0x8277B6F8;
	sub_8277B428(ctx, base);
loc_8277B6F8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bge cr6,0x8277b7b8
	if (!cr6.lt) goto loc_8277B7B8;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bge cr6,0x8277b738
	if (!cr6.lt) goto loc_8277B738;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b734
	if (cr6.eq) goto loc_8277B734;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B734:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8277B738:
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277b748
	if (cr6.eq) goto loc_8277B748;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
loc_8277B748:
	// lbz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277b794
	if (cr6.eq) goto loc_8277B794;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r28,8(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// subf r10,r10,r30
	ctx.r10.s64 = r30.s64 - ctx.r10.s64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8277b7b8
	if (!cr6.lt) goto loc_8277B7B8;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r11,r10
	r30.s64 = ctx.r10.s64 - r11.s64;
loc_8277B774:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8277a3e8
	ctx.lr = 0x8277B784;
	sub_8277A3E8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8277b774
	if (!cr0.eq) goto loc_8277B774;
	// b 0x8277b7b8
	goto loc_8277B7B8;
loc_8277B794:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277b7b8
	if (!cr6.eq) goto loc_8277B7B8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B7B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B7B8:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b7cc
	if (cr6.eq) goto loc_8277B7CC;
	// li r11,1
	r11.s64 = 1;
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
loc_8277B7CC:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277B7E8"))) PPC_WEAK_FUNC(sub_8277B7E8);
PPC_FUNC_IMPL(__imp__sub_8277B7E8) {
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
	ctx.lr = 0x8277B7F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// add r30,r27,r6
	r30.u64 = r27.u64 + ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r28,22
	r28.s64 = 22;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bgt cr6,0x8277b830
	if (cr6.gt) goto loc_8277B830;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// bgt cr6,0x8277b830
	if (cr6.gt) goto loc_8277B830;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b84c
	if (!cr6.eq) goto loc_8277B84C;
loc_8277B830:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B84C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B84C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x8277b868
	if (cr6.lt) goto loc_8277B868;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// ble cr6,0x8277b8f0
	if (!cr6.gt) goto loc_8277B8F0;
loc_8277B868:
	// lbz r11,34(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8277b894
	if (!cr6.eq) goto loc_8277B894;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,69
	ctx.r10.s64 = 69;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8277B894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B894:
	// lbz r11,33(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 33);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b8b8
	if (cr6.eq) goto loc_8277B8B8;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277b508
	ctx.lr = 0x8277B8B0;
	sub_8277B508(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
loc_8277B8B8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// ble cr6,0x8277b8cc
	if (!cr6.gt) goto loc_8277B8CC;
	// stw r27,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r27.u32);
	// b 0x8277b8e0
	goto loc_8277B8E0;
loc_8277B8CC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// subf. r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x8277b8dc
	if (!cr0.lt) goto loc_8277B8DC;
	// li r11,0
	r11.s64 = 0;
loc_8277B8DC:
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
loc_8277B8E0:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8277b508
	ctx.lr = 0x8277B8F0;
	sub_8277B508(ctx, base);
loc_8277B8F0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bge cr6,0x8277b9b4
	if (!cr6.lt) goto loc_8277B9B4;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bge cr6,0x8277b930
	if (!cr6.lt) goto loc_8277B930;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b92c
	if (cr6.eq) goto loc_8277B92C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B92C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B92C:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8277B930:
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8277b940
	if (cr6.eq) goto loc_8277B940;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
loc_8277B940:
	// lbz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8277b990
	if (cr6.eq) goto loc_8277B990;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// subf r10,r10,r30
	ctx.r10.s64 = r30.s64 - ctx.r10.s64;
	// rlwinm r28,r9,7,0,24
	r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8277b9b4
	if (!cr6.lt) goto loc_8277B9B4;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r30,r11,r10
	r30.s64 = ctx.r10.s64 - r11.s64;
loc_8277B970:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8277a3e8
	ctx.lr = 0x8277B980;
	sub_8277A3E8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8277b970
	if (!cr0.eq) goto loc_8277B970;
	// b 0x8277b9b4
	goto loc_8277B9B4;
loc_8277B990:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8277b9b4
	if (!cr6.eq) goto loc_8277B9B4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r28,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r28.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8277B9B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277B9B4:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277b9c8
	if (cr6.eq) goto loc_8277B9C8;
	// li r11,1
	r11.s64 = 1;
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
loc_8277B9C8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8277B9E4"))) PPC_WEAK_FUNC(sub_8277B9E4);
PPC_FUNC_IMPL(__imp__sub_8277B9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8277B9E8"))) PPC_WEAK_FUNC(sub_8277B9E8);
PPC_FUNC_IMPL(__imp__sub_8277B9E8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8277B9F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// blt cr6,0x8277ba10
	if (cr6.lt) goto loc_8277BA10;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// blt cr6,0x8277ba38
	if (cr6.lt) goto loc_8277BA38;
loc_8277BA10:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r10,14
	ctx.r10.s64 = 14;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r26,24(r9)
	PPC_STORE_U32(ctx.r9.u32 + 24, r26.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8277BA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BA38:
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r26,1
	cr6.compare<int32_t>(r26.s32, 1, xer);
	// bne cr6,0x8277bac4
	if (!cr6.eq) goto loc_8277BAC4;
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8277ba80
	if (cr6.eq) goto loc_8277BA80;
loc_8277BA50:
	// lbz r11,34(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277ba74
	if (cr6.eq) goto loc_8277BA74;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r4,r30,40
	ctx.r4.s64 = r30.s64 + 40;
	// stb r27,34(r30)
	PPC_STORE_U8(r30.u32 + 34, r27.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277BA74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BA74:
	// lwz r30,36(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8277ba50
	if (!cr6.eq) goto loc_8277BA50;
loc_8277BA80:
	// lwz r30,72(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stw r27,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8277bac0
	if (cr6.eq) goto loc_8277BAC0;
loc_8277BA90:
	// lbz r11,34(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 34);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8277bab4
	if (cr6.eq) goto loc_8277BAB4;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r4,r30,40
	ctx.r4.s64 = r30.s64 + 40;
	// stb r27,34(r30)
	PPC_STORE_U8(r30.u32 + 34, r27.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8277BAB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8277BAB4:
	// lwz r30,36(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8277ba90
	if (!cr6.eq) goto loc_8277BA90;
loc_8277BAC0:
	// stw r27,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r27.u32);
loc_8277BAC4:
	// addi r11,r26,15
	r11.s64 = r26.s64 + 15;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stwx r27,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r27.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8277bb14
	if (cr6.eq) goto loc_8277BB14;
loc_8277BADC:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r30,0(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821e4b18
	ctx.lr = 0x8277BAFC;
	sub_821E4B18(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// subf r10,r29,r11
	ctx.r10.s64 = r11.s64 - r29.s64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// bne cr6,0x8277badc
	if (!cr6.eq) goto loc_8277BADC;
loc_8277BB14:
	// addi r11,r26,13
	r11.s64 = r26.s64 + 13;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stwx r27,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r27.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8277bb64
	if (cr6.eq) goto loc_8277BB64;
loc_8277BB2C:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r30,0(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821e4b18
	ctx.lr = 0x8277BB4C;
	sub_821E4B18(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// subf r10,r29,r11
	ctx.r10.s64 = r11.s64 - r29.s64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// bne cr6,0x8277bb2c
	if (!cr6.eq) goto loc_8277BB2C;
loc_8277BB64:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

