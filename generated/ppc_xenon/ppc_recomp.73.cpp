#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_823EE8B0"))) PPC_WEAK_FUNC(sub_823EE8B0);
PPC_FUNC_IMPL(__imp__sub_823EE8B0) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EE8D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ee900
	if (cr6.lt) goto loc_823EE900;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ee900
	if (cr6.eq) goto loc_823EE900;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EE900;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EE900:
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

__attribute__((alias("__imp__sub_823EE914"))) PPC_WEAK_FUNC(sub_823EE914);
PPC_FUNC_IMPL(__imp__sub_823EE914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EE918"))) PPC_WEAK_FUNC(sub_823EE918);
PPC_FUNC_IMPL(__imp__sub_823EE918) {
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
	ctx.lr = 0x823EE920;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EE930;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ee958
	if (cr6.eq) goto loc_823EE958;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ee96c
	if (cr6.eq) goto loc_823EE96C;
loc_823EE958:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EE960;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EE96C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r3,76(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EE98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823ee9a8
	if (cr6.lt) goto loc_823EE9A8;
	// lbz r10,61(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stb r8,0(r27)
	PPC_STORE_U8(r27.u32 + 0, ctx.r8.u8);
loc_823EE9A8:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823ee9f4
	if (cr6.eq) goto loc_823EE9F4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823ee9f4
	if (!cr6.eq) goto loc_823EE9F4;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ee9f4
	if (!cr0.eq) goto loc_823EE9F4;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EE9EC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EE9F4;
	__imp__KfLowerIrql(ctx, base);
loc_823EE9F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EEA00"))) PPC_WEAK_FUNC(sub_823EEA00);
PPC_FUNC_IMPL(__imp__sub_823EEA00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r10,268(r13)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EEA1C"))) PPC_WEAK_FUNC(sub_823EEA1C);
PPC_FUNC_IMPL(__imp__sub_823EEA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEA20"))) PPC_WEAK_FUNC(sub_823EEA20);
PPC_FUNC_IMPL(__imp__sub_823EEA20) {
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
	ctx.lr = 0x823EEA28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// lbz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// slw r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// lwz r7,140(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x823eea70
	if (cr6.eq) goto loc_823EEA70;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EEA68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eeb08
	if (cr6.lt) goto loc_823EEB08;
loc_823EEA70:
	// addi r29,r31,76
	r29.s64 = r31.s64 + 76;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f7120
	ctx.lr = 0x823EEA84;
	sub_823F7120(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eeb08
	if (cr6.lt) goto loc_823EEB08;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f67b8
	ctx.lr = 0x823EEA98;
	sub_823F67B8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eeb08
	if (cr6.lt) goto loc_823EEB08;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EEAB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823eeb04
	if (cr6.lt) goto loc_823EEB04;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823efd30
	ctx.lr = 0x823EEAD0;
	sub_823EFD30(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823eeb04
	if (!cr6.eq) goto loc_823EEB04;
	// lbz r11,61(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 61);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823eeb04
	if (!cr6.eq) goto loc_823EEB04;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f7468
	ctx.lr = 0x823EEAFC;
	sub_823F7468(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823EEB04:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823EEB08:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EEB10"))) PPC_WEAK_FUNC(sub_823EEB10);
PPC_FUNC_IMPL(__imp__sub_823EEB10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,144(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bge cr6,0x823eeb34
	if (!cr6.lt) goto loc_823EEB34;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r11,33
	ctx.r9.s64 = r11.s64 + 33;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-9796(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -9796);
	// lfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// b 0x823eeb3c
	goto loc_823EEB3C;
loc_823EEB34:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_823EEB3C:
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lfs f13,140(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,88(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823EEB5C"))) PPC_WEAK_FUNC(sub_823EEB5C);
PPC_FUNC_IMPL(__imp__sub_823EEB5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEB60"))) PPC_WEAK_FUNC(sub_823EEB60);
PPC_FUNC_IMPL(__imp__sub_823EEB60) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823EEB7C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x823eeb7c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823EEB7C;
	// bl 0x823ee848
	ctx.lr = 0x823EEB8C;
	sub_823EE848(ctx, base);
	// lwz r9,68(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lwz r9,-9796(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -9796);
	// addi r10,r9,12
	ctx.r10.s64 = ctx.r9.s64 + 12;
loc_823EEBA4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823eec18
	if (!cr6.eq) goto loc_823EEC18;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// blt cr6,0x823eeba4
	if (cr6.lt) goto loc_823EEBA4;
	// li r11,0
	r11.s64 = 0;
loc_823EEBC4:
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, r11.u32);
	// lwz r10,88(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// stw r10,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r10.u32);
	// lbz r11,57(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823eebe8
	if (!cr6.eq) goto loc_823EEBE8;
	// li r11,1
	r11.s64 = 1;
loc_823EEBE8:
	// stb r11,24(r4)
	PPC_STORE_U8(ctx.r4.u32 + 24, r11.u8);
	// lbz r11,58(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 58);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823eebfc
	if (!cr6.eq) goto loc_823EEBFC;
	// li r11,6
	r11.s64 = 6;
loc_823EEBFC:
	// stb r11,25(r4)
	PPC_STORE_U8(ctx.r4.u32 + 25, r11.u8);
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// stw r10,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823EEC18:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// b 0x823eebc4
	goto loc_823EEBC4;
}

__attribute__((alias("__imp__sub_823EEC28"))) PPC_WEAK_FUNC(sub_823EEC28);
PPC_FUNC_IMPL(__imp__sub_823EEC28) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823EEC30;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// lwz r30,60(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// bl 0x823eeb60
	ctx.lr = 0x823EEC50;
	sub_823EEB60(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823f62c8
	ctx.lr = 0x823EEC5C;
	sub_823F62C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eecf8
	if (cr6.lt) goto loc_823EECF8;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823EEC74:
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x823eec74
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823EEC74;
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// li r5,56
	ctx.r5.s64 = 56;
	// stb r10,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r10.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x823EEC9C;
	sub_823DA950(ctx, base);
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f0.f64 = double(temp.f32);
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r10,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, ctx.r10.u8);
	// stb r9,197(r1)
	PPC_STORE_U8(ctx.r1.u32 + 197, ctx.r9.u8);
	// stw r8,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r8.u32);
	// stw r7,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r7.u32);
	// bl 0x823ee170
	ctx.lr = 0x823EECD4;
	sub_823EE170(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// blt cr6,0x823eecfc
	if (cr6.lt) goto loc_823EECFC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
loc_823EECF8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EECFC:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EED04"))) PPC_WEAK_FUNC(sub_823EED04);
PPC_FUNC_IMPL(__imp__sub_823EED04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EED08"))) PPC_WEAK_FUNC(sub_823EED08);
PPC_FUNC_IMPL(__imp__sub_823EED08) {
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
	ctx.lr = 0x823EED10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r10,r11,-4240
	ctx.r10.s64 = r11.s64 + -4240;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823EED34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eed58
	if (cr6.lt) goto loc_823EED58;
	// lwz r3,76(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823eed58
	if (cr6.eq) goto loc_823EED58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EED58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EED58:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r28,-9796(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// bl 0x827bd514
	ctx.lr = 0x823EED64;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eed8c
	if (cr6.eq) goto loc_823EED8C;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823eeda4
	if (cr6.eq) goto loc_823EEDA4;
loc_823EED8C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EED94;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
loc_823EEDA4:
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r11,88(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 88);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x823eede4
	if (cr6.eq) goto loc_823EEDE4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EEDE4:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823eee28
	if (cr6.eq) goto loc_823EEE28;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823eee28
	if (!cr6.eq) goto loc_823EEE28;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823eee28
	if (!cr0.eq) goto loc_823EEE28;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EEE20;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EEE28;
	__imp__KfLowerIrql(ctx, base);
loc_823EEE28:
	// lwz r3,76(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823eee4c
	if (cr6.eq) goto loc_823EEE4C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EEE44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,76(r27)
	PPC_STORE_U32(r27.u32 + 76, ctx.r9.u32);
loc_823EEE4C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823f6650
	ctx.lr = 0x823EEE54;
	sub_823F6650(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EEE5C"))) PPC_WEAK_FUNC(sub_823EEE5C);
PPC_FUNC_IMPL(__imp__sub_823EEE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEE60"))) PPC_WEAK_FUNC(sub_823EEE60);
PPC_FUNC_IMPL(__imp__sub_823EEE60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EEE70"))) PPC_WEAK_FUNC(sub_823EEE70);
PPC_FUNC_IMPL(__imp__sub_823EEE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,12(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EEE80"))) PPC_WEAK_FUNC(sub_823EEE80);
PPC_FUNC_IMPL(__imp__sub_823EEE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r3,52
	r11.s64 = ctx.r3.s64 + 52;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EEE9C"))) PPC_WEAK_FUNC(sub_823EEE9C);
PPC_FUNC_IMPL(__imp__sub_823EEE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEEA0"))) PPC_WEAK_FUNC(sub_823EEEA0);
PPC_FUNC_IMPL(__imp__sub_823EEEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// addi r3,r30,84
	ctx.r3.s64 = r30.s64 + 84;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x823da950
	ctx.lr = 0x823EEEC8;
	sub_823DA950(ctx, base);
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,144(r30)
	PPC_STORE_U8(r30.u32 + 144, r11.u8);
	// bl 0x823eeb60
	ctx.lr = 0x823EEEDC;
	sub_823EEB60(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823f6380
	ctx.lr = 0x823EEEE8;
	sub_823F6380(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823eef64
	if (cr6.lt) goto loc_823EEF64;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823EEF00:
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x823eef00
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823EEF00;
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// li r5,56
	ctx.r5.s64 = 56;
	// stb r10,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, ctx.r10.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x823EEF28;
	sub_823DA950(ctx, base);
	// lbz r10,59(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 59);
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f0.f64 = double(temp.f32);
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r6,255
	ctx.r6.s64 = 255;
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r30,76
	ctx.r4.s64 = r30.s64 + 76;
	// stb r10,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r10.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r9,181(r1)
	PPC_STORE_U8(ctx.r1.u32 + 181, ctx.r9.u8);
	// stw r8,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r8.u32);
	// stw r7,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r7.u32);
	// bl 0x823f6e18
	ctx.lr = 0x823EEF64;
	sub_823F6E18(ctx, base);
loc_823EEF64:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

__attribute__((alias("__imp__sub_823EEF7C"))) PPC_WEAK_FUNC(sub_823EEF7C);
PPC_FUNC_IMPL(__imp__sub_823EEF7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EEF80"))) PPC_WEAK_FUNC(sub_823EEF80);
PPC_FUNC_IMPL(__imp__sub_823EEF80) {
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
	ctx.lr = 0x823EEF88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EEF94;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823eefbc
	if (cr6.eq) goto loc_823EEFBC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823eefd8
	if (cr6.eq) goto loc_823EEFD8;
loc_823EEFBC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EEFC4;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// b 0x823eefdc
	goto loc_823EEFDC;
loc_823EEFD8:
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EEFDC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r9,61(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 61);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823ef044
	if (!cr6.eq) goto loc_823EF044;
	// mr r9,r13
	ctx.r9.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef034
	if (cr6.eq) goto loc_823EF034;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823ef034
	if (!cr6.eq) goto loc_823EF034;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef034
	if (!cr0.eq) goto loc_823EF034;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EF02C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF034;
	__imp__KfLowerIrql(ctx, base);
loc_823EF034:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16388
	ctx.r3.u64 = ctx.r3.u64 | 16388;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823EF044:
	// lis r30,-32115
	r30.s64 = -2104688640;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-9796(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -9796);
	// bl 0x823eb8e0
	ctx.lr = 0x823EF054;
	sub_823EB8E0(ctx, base);
	// lwz r28,-9796(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -9796);
	// bl 0x827bd514
	ctx.lr = 0x823EF05C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef07c
	if (cr6.eq) goto loc_823EF07C;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823ef094
	if (cr6.eq) goto loc_823EF094;
loc_823EF07C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF084;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
loc_823EF094:
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r11,76(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x823ef0d4
	if (cr6.eq) goto loc_823EF0D4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EF0D4:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823ef118
	if (cr6.eq) goto loc_823EF118;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823ef118
	if (!cr6.eq) goto loc_823EF118;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef118
	if (!cr0.eq) goto loc_823EF118;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EF110;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF118;
	__imp__KfLowerIrql(ctx, base);
loc_823EF118:
	// bl 0x827bd514
	ctx.lr = 0x823EF11C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef13c
	if (cr6.eq) goto loc_823EF13C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ef150
	if (cr6.eq) goto loc_823EF150;
loc_823EF13C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF144;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EF150:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,61(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 61);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwinm r9,r9,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r9,61(r27)
	PPC_STORE_U8(r27.u32 + 61, ctx.r9.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef1b8
	if (cr6.eq) goto loc_823EF1B8;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ef1b8
	if (!cr6.eq) goto loc_823EF1B8;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef1b8
	if (!cr0.eq) goto loc_823EF1B8;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EF1AC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF1B4;
	__imp__KfLowerIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EF1B8:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef200
	if (cr6.eq) goto loc_823EF200;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ef200
	if (!cr6.eq) goto loc_823EF200;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef200
	if (!cr0.eq) goto loc_823EF200;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EF1F8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF200;
	__imp__KfLowerIrql(ctx, base);
loc_823EF200:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EF20C"))) PPC_WEAK_FUNC(sub_823EF20C);
PPC_FUNC_IMPL(__imp__sub_823EF20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EF210"))) PPC_WEAK_FUNC(sub_823EF210);
PPC_FUNC_IMPL(__imp__sub_823EF210) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823EF218;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823f6238
	ctx.lr = 0x823EF224;
	sub_823F6238(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r8,r10,-4240
	ctx.r8.s64 = ctx.r10.s64 + -4240;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// stfs f0,140(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 140, temp.u32);
	// lwz r11,-9796(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -9796);
	// addi r30,r11,80
	r30.s64 = r11.s64 + 80;
	// bl 0x827bd514
	ctx.lr = 0x823EF24C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r28,r13
	r28.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef274
	if (cr6.eq) goto loc_823EF274;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ef288
	if (cr6.eq) goto loc_823EF288;
loc_823EF274:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF27C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
loc_823EF288:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef2fc
	if (cr6.eq) goto loc_823EF2FC;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ef2fc
	if (!cr6.eq) goto loc_823EF2FC;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef2fc
	if (!cr0.eq) goto loc_823EF2FC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EF2F4;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF2FC;
	__imp__KfLowerIrql(ctx, base);
loc_823EF2FC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EF308"))) PPC_WEAK_FUNC(sub_823EF308);
PPC_FUNC_IMPL(__imp__sub_823EF308) {
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
	// bl 0x823eed08
	ctx.lr = 0x823EF320;
	sub_823EED08(ctx, base);
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

__attribute__((alias("__imp__sub_823EF338"))) PPC_WEAK_FUNC(sub_823EF338);
PPC_FUNC_IMPL(__imp__sub_823EF338) {
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
	ctx.lr = 0x823EF340;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x827bd514
	ctx.lr = 0x823EF350;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef378
	if (cr6.eq) goto loc_823EF378;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ef38c
	if (cr6.eq) goto loc_823EF38C;
loc_823EF378:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF380;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EF38C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r10,61(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 61);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ef3b0
	if (cr6.eq) goto loc_823EF3B0;
	// lis r26,-32768
	r26.s64 = -2147483648;
	// ori r26,r26,65535
	r26.u64 = r26.u64 | 65535;
	// b 0x823ef510
	goto loc_823EF510;
loc_823EF3B0:
	// rlwinm r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ef510
	if (!cr6.eq) goto loc_823EF510;
	// bl 0x827bd514
	ctx.lr = 0x823EF3C0;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef3e0
	if (cr6.eq) goto loc_823EF3E0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ef3f4
	if (cr6.eq) goto loc_823EF3F4;
loc_823EF3E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF3E8;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EF3F4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,61(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 61);
	// ori r9,r11,64
	ctx.r9.u64 = r11.u64 | 64;
	// stb r9,61(r27)
	PPC_STORE_U8(r27.u32 + 61, ctx.r9.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef454
	if (cr6.eq) goto loc_823EF454;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ef454
	if (!cr6.eq) goto loc_823EF454;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef454
	if (!cr0.eq) goto loc_823EF454;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EF44C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF454;
	__imp__KfLowerIrql(ctx, base);
loc_823EF454:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r30,-9796(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// bl 0x827bd514
	ctx.lr = 0x823EF460;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef480
	if (cr6.eq) goto loc_823EF480;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823ef494
	if (cr6.eq) goto loc_823EF494;
loc_823EF480:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF488;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823EF494:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r30,68
	ctx.r10.s64 = r30.s64 + 68;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r9,r13
	ctx.r9.u64 = ctx.r13.u64;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r11,72(r30)
	PPC_STORE_U32(r30.u32 + 72, r11.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef510
	if (cr6.eq) goto loc_823EF510;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823ef510
	if (!cr6.eq) goto loc_823EF510;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef510
	if (!cr0.eq) goto loc_823EF510;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EF504;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF50C;
	__imp__KfLowerIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EF510:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef558
	if (cr6.eq) goto loc_823EF558;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823ef558
	if (!cr6.eq) goto loc_823EF558;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823ef558
	if (!cr0.eq) goto loc_823EF558;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EF550;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EF558;
	__imp__KfLowerIrql(ctx, base);
loc_823EF558:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823EF564"))) PPC_WEAK_FUNC(sub_823EF564);
PPC_FUNC_IMPL(__imp__sub_823EF564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EF568"))) PPC_WEAK_FUNC(sub_823EF568);
PPC_FUNC_IMPL(__imp__sub_823EF568) {
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
	ctx.lr = 0x823EF570;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x823eef80
	ctx.lr = 0x823EF580;
	sub_823EEF80(ctx, base);
	// lis r11,-32768
	r11.s64 = -2147483648;
	// ori r10,r11,16388
	ctx.r10.u64 = r11.u64 | 16388;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// bne cr6,0x823ef60c
	if (!cr6.eq) goto loc_823EF60C;
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ef600
	if (cr6.eq) goto loc_823EF600;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EF5B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ef60c
	if (cr6.lt) goto loc_823EF60C;
	// clrlwi r11,r31,31
	r11.u64 = r31.u32 & 0x1;
	// clrlwi r29,r31,24
	r29.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ef600
	if (!cr6.eq) goto loc_823EF600;
	// lwz r3,76(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EF5E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ef60c
	if (cr6.lt) goto loc_823EF60C;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ef600
	if (!cr6.eq) goto loc_823EF600;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// ori r31,r11,1
	r31.u64 = r11.u64 | 1;
loc_823EF600:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823f7468
	ctx.lr = 0x823EF60C;
	sub_823F7468(ctx, base);
loc_823EF60C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823EF614"))) PPC_WEAK_FUNC(sub_823EF614);
PPC_FUNC_IMPL(__imp__sub_823EF614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EF618"))) PPC_WEAK_FUNC(sub_823EF618);
PPC_FUNC_IMPL(__imp__sub_823EF618) {
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
	ctx.lr = 0x823EF620;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x823eec28
	ctx.lr = 0x823EF638;
	sub_823EEC28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ef64c
	if (cr6.lt) goto loc_823EF64C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r11,148
	ctx.r4.s64 = r11.s64 + 148;
	// b 0x823ef650
	goto loc_823EF650;
loc_823EF64C:
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823EF650:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ef6f0
	if (cr6.lt) goto loc_823EF6F0;
	// lis r3,24962
	ctx.r3.s64 = 1635909632;
	// addi r5,r1,156
	ctx.r5.s64 = ctx.r1.s64 + 156;
	// ori r3,r3,6
	ctx.r3.u64 = ctx.r3.u64 | 6;
	// bl 0x823f6188
	ctx.lr = 0x823EF66C;
	sub_823F6188(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x823ef6f0
	if (cr6.lt) goto loc_823EF6F0;
	// lwz r3,156(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// li r4,148
	ctx.r4.s64 = 148;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EF690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ef6b0
	if (cr6.eq) goto loc_823EF6B0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,156(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x823ef210
	ctx.lr = 0x823EF6A4;
	sub_823EF210(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823ef6bc
	if (!cr6.eq) goto loc_823EF6BC;
loc_823EF6B0:
	// lis r31,-32761
	r31.s64 = -2147024896;
	// ori r31,r31,14
	r31.u64 = r31.u64 | 14;
	// b 0x823ef6f0
	goto loc_823EF6F0;
loc_823EF6BC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823eeea0
	ctx.lr = 0x823EF6C8;
	sub_823EEEA0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x823ef6dc
	if (cr6.lt) goto loc_823EF6DC;
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// b 0x823ef6f0
	goto loc_823EF6F0;
loc_823EF6DC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EF6F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EF6F0:
	// lwz r3,156(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ef70c
	if (cr6.eq) goto loc_823EF70C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EF70C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EF70C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823EF718"))) PPC_WEAK_FUNC(sub_823EF718);
PPC_FUNC_IMPL(__imp__sub_823EF718) {
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
	// clrlwi r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ef750
	if (cr6.eq) goto loc_823EF750;
	// bl 0x823ef338
	ctx.lr = 0x823EF73C;
	sub_823EF338(ctx, base);
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
loc_823EF750:
	// bl 0x823eef80
	ctx.lr = 0x823EF754;
	sub_823EEF80(ctx, base);
	// lis r11,-32768
	r11.s64 = -2147483648;
	// ori r10,r11,16388
	ctx.r10.u64 = r11.u64 | 16388;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// beq cr6,0x823ef76c
	if (cr6.eq) goto loc_823EF76C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ef7a4
	if (cr6.lt) goto loc_823EF7A4;
loc_823EF76C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EF780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823EF794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823ef7a4
	if (cr6.lt) goto loc_823EF7A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f7240
	ctx.lr = 0x823EF7A4;
	sub_823F7240(ctx, base);
loc_823EF7A4:
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

__attribute__((alias("__imp__sub_823EF7B8"))) PPC_WEAK_FUNC(sub_823EF7B8);
PPC_FUNC_IMPL(__imp__sub_823EF7B8) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x82130b50
	sub_82130B50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823EF7C4"))) PPC_WEAK_FUNC(sub_823EF7C4);
PPC_FUNC_IMPL(__imp__sub_823EF7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EF7C8"))) PPC_WEAK_FUNC(sub_823EF7C8);
PPC_FUNC_IMPL(__imp__sub_823EF7C8) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// b 0x821310f8
	sub_821310F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823EF7D4"))) PPC_WEAK_FUNC(sub_823EF7D4);
PPC_FUNC_IMPL(__imp__sub_823EF7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EF7D8"))) PPC_WEAK_FUNC(sub_823EF7D8);
PPC_FUNC_IMPL(__imp__sub_823EF7D8) {
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
	// bl 0x823f6b78
	ctx.lr = 0x823EF7F4;
	sub_823F6B78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823ef82c
	if (cr6.lt) goto loc_823EF82C;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-8
	ctx.r3.s64 = r11.s64 + -8;
	// bne cr6,0x823ef814
	if (!cr6.eq) goto loc_823EF814;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823EF814:
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r31,52
	ctx.r4.s64 = r31.s64 + 52;
	// bl 0x823eb050
	ctx.lr = 0x823EF820;
	sub_823EB050(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823efd30
	ctx.lr = 0x823EF82C;
	sub_823EFD30(ctx, base);
loc_823EF82C:
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

__attribute__((alias("__imp__sub_823EF848"))) PPC_WEAK_FUNC(sub_823EF848);
PPC_FUNC_IMPL(__imp__sub_823EF848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823EF858:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x823ef858
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823EF858;
	// stb r9,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r9.u8);
	// lis r11,0
	r11.s64 = 0;
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// stb r10,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r10.u8);
	// ori r9,r11,48000
	ctx.r9.u64 = r11.u64 | 48000;
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r7,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r7.u32);
	// lwz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// stw r6,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r6.u32);
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ef8a4
	if (!cr6.eq) goto loc_823EF8A4;
	// li r11,1
	r11.s64 = 1;
loc_823EF8A4:
	// stb r11,24(r4)
	PPC_STORE_U8(ctx.r4.u32 + 24, r11.u8);
	// lbz r11,9(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ef8b8
	if (!cr6.eq) goto loc_823EF8B8;
	// li r11,6
	r11.s64 = 6;
loc_823EF8B8:
	// stb r11,25(r4)
	PPC_STORE_U8(ctx.r4.u32 + 25, r11.u8);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r10,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EF8C8"))) PPC_WEAK_FUNC(sub_823EF8C8);
PPC_FUNC_IMPL(__imp__sub_823EF8C8) {
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
	// lbz r11,1(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r10,48000
	ctx.r8.u64 = ctx.r10.u64 | 48000;
	// stb r9,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
	// bl 0x823f6278
	ctx.lr = 0x823EF904;
	sub_823F6278(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823ef920
	if (cr6.lt) goto loc_823EF920;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r31,52
	ctx.r4.s64 = r31.s64 + 52;
	// bl 0x823eb1d0
	ctx.lr = 0x823EF920;
	sub_823EB1D0(ctx, base);
loc_823EF920:
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

__attribute__((alias("__imp__sub_823EF93C"))) PPC_WEAK_FUNC(sub_823EF93C);
PPC_FUNC_IMPL(__imp__sub_823EF93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EF940"))) PPC_WEAK_FUNC(sub_823EF940);
PPC_FUNC_IMPL(__imp__sub_823EF940) {
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
	ctx.lr = 0x823EF948;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r10,r11,-4144
	ctx.r10.s64 = r11.s64 + -4144;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x823f7468
	ctx.lr = 0x823EF964;
	sub_823F7468(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lbz r8,76(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 76);
	// mulli r10,r8,44
	ctx.r10.s64 = ctx.r8.s64 * 44;
	// lwz r11,-9796(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -9796);
	// lwz r11,124(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// add r27,r10,r11
	r27.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EF980;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ef9a8
	if (cr6.eq) goto loc_823EF9A8;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// beq cr6,0x823ef9c0
	if (cr6.eq) goto loc_823EF9C0;
loc_823EF9A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EF9B0;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
loc_823EF9C0:
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x823efa00
	if (cr6.eq) goto loc_823EFA00;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823EFA00:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823efa44
	if (cr6.eq) goto loc_823EFA44;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823efa44
	if (!cr6.eq) goto loc_823EFA44;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823efa44
	if (!cr0.eq) goto loc_823EFA44;
	// li r11,0
	r11.s64 = 0;
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823EFA3C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EFA44;
	__imp__KfLowerIrql(ctx, base);
loc_823EFA44:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823f6650
	ctx.lr = 0x823EFA4C;
	sub_823F6650(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EFA54"))) PPC_WEAK_FUNC(sub_823EFA54);
PPC_FUNC_IMPL(__imp__sub_823EFA54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EFA58"))) PPC_WEAK_FUNC(sub_823EFA58);
PPC_FUNC_IMPL(__imp__sub_823EFA58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,61(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 61);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EFA68"))) PPC_WEAK_FUNC(sub_823EFA68);
PPC_FUNC_IMPL(__imp__sub_823EFA68) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EFA70"))) PPC_WEAK_FUNC(sub_823EFA70);
PPC_FUNC_IMPL(__imp__sub_823EFA70) {
	PPC_FUNC_PROLOGUE();
	// b 0x823f66f0
	sub_823F66F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823EFA74"))) PPC_WEAK_FUNC(sub_823EFA74);
PPC_FUNC_IMPL(__imp__sub_823EFA74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EFA78"))) PPC_WEAK_FUNC(sub_823EFA78);
PPC_FUNC_IMPL(__imp__sub_823EFA78) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823ef848
	ctx.lr = 0x823EFA9C;
	sub_823EF848(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823f6380
	ctx.lr = 0x823EFAA8;
	sub_823F6380(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x823efac4
	if (cr6.lt) goto loc_823EFAC4;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823eb1d0
	ctx.lr = 0x823EFAC4;
	sub_823EB1D0(ctx, base);
loc_823EFAC4:
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

__attribute__((alias("__imp__sub_823EFAE0"))) PPC_WEAK_FUNC(sub_823EFAE0);
PPC_FUNC_IMPL(__imp__sub_823EFAE0) {
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
	ctx.lr = 0x823EFAE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823f6238
	ctx.lr = 0x823EFB00;
	sub_823F6238(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r8,r11,-4144
	ctx.r8.s64 = r11.s64 + -4144;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// lbz r7,10(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stb r7,76(r29)
	PPC_STORE_U8(r29.u32 + 76, ctx.r7.u8);
	// mulli r10,r6,44
	ctx.r10.s64 = ctx.r6.s64 * 44;
	// lwz r11,-9796(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -9796);
	// lwz r11,124(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x827bd514
	ctx.lr = 0x823EFB30;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r28,r13
	r28.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823efb58
	if (cr6.eq) goto loc_823EFB58;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// beq cr6,0x823efb6c
	if (cr6.eq) goto loc_823EFB6C;
loc_823EFB58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EFB60;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
loc_823EFB6C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823efbe0
	if (cr6.eq) goto loc_823EFBE0;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823efbe0
	if (!cr6.eq) goto loc_823EFBE0;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823efbe0
	if (!cr0.eq) goto loc_823EFBE0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EFBD8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EFBE0;
	__imp__KfLowerIrql(ctx, base);
loc_823EFBE0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823EFBEC"))) PPC_WEAK_FUNC(sub_823EFBEC);
PPC_FUNC_IMPL(__imp__sub_823EFBEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EFBF0"))) PPC_WEAK_FUNC(sub_823EFBF0);
PPC_FUNC_IMPL(__imp__sub_823EFBF0) {
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
	// bl 0x823ef940
	ctx.lr = 0x823EFC08;
	sub_823EF940(ctx, base);
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

__attribute__((alias("__imp__sub_823EFC20"))) PPC_WEAK_FUNC(sub_823EFC20);
PPC_FUNC_IMPL(__imp__sub_823EFC20) {
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
	ctx.lr = 0x823EFC28;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r4.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x823ef848
	ctx.lr = 0x823EFC40;
	sub_823EF848(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823f62c8
	ctx.lr = 0x823EFC4C;
	sub_823F62C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823efc60
	if (cr6.lt) goto loc_823EFC60;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,80
	ctx.r10.s64 = r11.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_823EFC60:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823efd04
	if (cr6.lt) goto loc_823EFD04;
	// lis r3,24962
	ctx.r3.s64 = 1635909632;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r1,204
	ctx.r5.s64 = ctx.r1.s64 + 204;
	// ori r3,r3,6
	ctx.r3.u64 = ctx.r3.u64 | 6;
	// bl 0x823f6188
	ctx.lr = 0x823EFC80;
	sub_823F6188(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823efd04
	if (cr6.lt) goto loc_823EFD04;
	// lwz r3,204(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// li r4,80
	ctx.r4.s64 = 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EFCA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823efcc4
	if (cr6.eq) goto loc_823EFCC4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,204(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// bl 0x823efae0
	ctx.lr = 0x823EFCB8;
	sub_823EFAE0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823efcd0
	if (!cr6.eq) goto loc_823EFCD0;
loc_823EFCC4:
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x823efd04
	goto loc_823EFD04;
loc_823EFCD0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823efa78
	ctx.lr = 0x823EFCDC;
	sub_823EFA78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823efcf0
	if (cr6.lt) goto loc_823EFCF0;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// b 0x823efd04
	goto loc_823EFD04;
loc_823EFCF0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EFD04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EFD04:
	// lwz r3,204(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823efd20
	if (cr6.eq) goto loc_823EFD20;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823EFD20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823EFD20:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823EFD2C"))) PPC_WEAK_FUNC(sub_823EFD2C);
PPC_FUNC_IMPL(__imp__sub_823EFD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EFD30"))) PPC_WEAK_FUNC(sub_823EFD30);
PPC_FUNC_IMPL(__imp__sub_823EFD30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-9784
	r11.s64 = r11.s64 + -9784;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
loc_823EFD40:
	// mfmsr r7
	ctx.r7.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r9,0,r6
	reserved.u32 = *(uint32_t*)(base + ctx.r6.u32);
	ctx.r9.u64 = __builtin_bswap32(reserved.u32);
	// add r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 + ctx.r9.u64;
	// stwcx. r8,0,r6
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r6.u32), reserved.s32, __builtin_bswap32(ctx.r8.s32));
	cr0.so = xer.so;
	// mtmsrd r7,1
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x823efd40
	if (!cr0.eq) goto loc_823EFD40;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EFD64"))) PPC_WEAK_FUNC(sub_823EFD64);
PPC_FUNC_IMPL(__imp__sub_823EFD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823EFD68"))) PPC_WEAK_FUNC(sub_823EFD68);
PPC_FUNC_IMPL(__imp__sub_823EFD68) {
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
	ctx.lr = 0x823EFD70;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mftb r10
	ctx.r10.u64 = __rdtsc();
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// addi r31,r11,-9784
	r31.s64 = r11.s64 + -9784;
	// li r30,0
	r30.s64 = 0;
	// sradi r26,r10,32
	xer.ca = (ctx.r10.s64 < 0) & ((ctx.r10.u64 & 0xFFFFFFFF) != 0);
	r26.s64 = ctx.r10.s64 >> 32;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// lwz r11,-9784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9784);
	// std r30,0(r28)
	PPC_STORE_U64(r28.u32 + 0, r30.u64);
	// lis r3,22593
	ctx.r3.s64 = 1480654848;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,40
	ctx.r5.s64 = 40;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// ori r3,r3,30052
	ctx.r3.u64 = ctx.r3.u64 | 30052;
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r29,24(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// std r30,8(r28)
	PPC_STORE_U64(r28.u32 + 8, r30.u64);
	// std r30,16(r28)
	PPC_STORE_U64(r28.u32 + 16, r30.u64);
	// std r30,24(r28)
	PPC_STORE_U64(r28.u32 + 24, r30.u64);
	// std r30,32(r28)
	PPC_STORE_U64(r28.u32 + 32, r30.u64);
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// bl 0x82457f10
	ctx.lr = 0x823EFDF8;
	sub_82457F10(ctx, base);
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823EFDFC:
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r8,r31,28
	ctx.r8.s64 = r31.s64 + 28;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// stwx r30,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r30.u32);
	// stwx r9,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,28
	cr6.compare<int32_t>(r11.s32, 28, xer);
	// blt cr6,0x823efdfc
	if (cr6.lt) goto loc_823EFDFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823EFE28"))) PPC_WEAK_FUNC(sub_823EFE28);
PPC_FUNC_IMPL(__imp__sub_823EFE28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,6
	r11.s64 = 6;
	// li r10,3750
	ctx.r10.s64 = 3750;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r10,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823EFE40"))) PPC_WEAK_FUNC(sub_823EFE40);
PPC_FUNC_IMPL(__imp__sub_823EFE40) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823EFE48;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823eff7c
	if (cr6.eq) goto loc_823EFF7C;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x823efe84
	if (cr6.eq) goto loc_823EFE84;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_823EFE84:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82458060
	ctx.lr = 0x823EFE8C;
	sub_82458060(ctx, base);
	// bl 0x827bd514
	ctx.lr = 0x823EFE90;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823efeb8
	if (cr6.eq) goto loc_823EFEB8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823efecc
	if (cr6.eq) goto loc_823EFECC;
loc_823EFEB8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EFEC0;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823EFECC:
	// addis r8,r28,5
	ctx.r8.s64 = r28.s64 + 327680;
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r8,r8,-17760
	ctx.r8.s64 = ctx.r8.s64 + -17760;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addis r9,r28,5
	ctx.r9.s64 = r28.s64 + 327680;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// addi r9,r9,-17752
	ctx.r9.s64 = ctx.r9.s64 + -17752;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// lfd f11,0(r8)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// lfd f0,-4016(r7)
	f0.u64 = PPC_LOAD_U64(ctx.r7.u32 + -4016);
	// lfd f12,0(r9)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fmul f7,f9,f0
	ctx.f7.f64 = ctx.f9.f64 * f0.f64;
	// fdiv f8,f10,f13
	ctx.f8.f64 = ctx.f10.f64 / ctx.f13.f64;
	// fdiv f6,f8,f7
	ctx.f6.f64 = ctx.f8.f64 / ctx.f7.f64;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,0(r27)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// std r26,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, r26.u64);
	// std r26,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, r26.u64);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f0040
	if (cr6.eq) goto loc_823F0040;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f0040
	if (!cr6.eq) goto loc_823F0040;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f0040
	if (!cr0.eq) goto loc_823F0040;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// mr r11,r26
	r11.u64 = r26.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823EFF64;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823EFF6C;
	__imp__KfLowerIrql(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_823EFF7C:
	// bl 0x827bd514
	ctx.lr = 0x823EFF80;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823effa8
	if (cr6.eq) goto loc_823EFFA8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823effc8
	if (cr6.eq) goto loc_823EFFC8;
loc_823EFFA8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823EFFB0;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stb r7,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r7.u8);
	// b 0x823effcc
	goto loc_823EFFCC;
loc_823EFFC8:
	// lbz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823EFFCC:
	// addic. r11,r11,1
	xer.ca = r11.u32 > 4294967294;
	r11.s64 = r11.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r8,r13
	ctx.r8.u64 = ctx.r13.u64;
	// lwz r6,16(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lfs f0,31016(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lwz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// add r5,r9,r28
	ctx.r5.u64 = ctx.r9.u64 + r28.u64;
	// lfs f13,108(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 * f0.f64));
	// beq 0x823f0030
	if (cr0.eq) goto loc_823F0030;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bne cr6,0x823f0030
	if (!cr6.eq) goto loc_823F0030;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f0030
	if (!cr0.eq) goto loc_823F0030;
	// mr r11,r26
	r11.u64 = r26.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// bl 0x827bd544
	ctx.lr = 0x823F0028;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F0030;
	__imp__KfLowerIrql(ctx, base);
loc_823F0030:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// stfs f0,0(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
loc_823F0040:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823F0050"))) PPC_WEAK_FUNC(sub_823F0050);
PPC_FUNC_IMPL(__imp__sub_823F0050) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823F0058;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x823f01ec
	if (cr6.lt) goto loc_823F01EC;
	// beq cr6,0x823f0140
	if (cr6.eq) goto loc_823F0140;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x823f0098
	if (cr6.lt) goto loc_823F0098;
	// lis r26,-32761
	r26.s64 = -2147024896;
	// ori r26,r26,87
	r26.u64 = r26.u64 | 87;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_823F0098:
	// lfs f31,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	f31.f64 = double(temp.f32);
	// bl 0x827bd514
	ctx.lr = 0x823F00A0;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f00c8
	if (cr6.eq) goto loc_823F00C8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f00dc
	if (cr6.eq) goto loc_823F00DC;
loc_823F00C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F00D0;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F00DC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x827bd514
	ctx.lr = 0x823F00E8;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f0108
	if (cr6.eq) goto loc_823F0108;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f011c
	if (cr6.eq) goto loc_823F011C;
loc_823F0108:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F0110;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F011C:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stb r8,204(r28)
	PPC_STORE_U8(r28.u32 + 204, ctx.r8.u8);
	// lfs f0,31016(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// stfs f0,200(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 200, temp.u32);
	// b 0x823f035c
	goto loc_823F035C;
loc_823F0140:
	// lwz r27,0(r6)
	r27.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// bl 0x827bd514
	ctx.lr = 0x823F0148;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f0170
	if (cr6.eq) goto loc_823F0170;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f0184
	if (cr6.eq) goto loc_823F0184;
loc_823F0170:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F0178;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F0184:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r30,r28,16
	r30.s64 = r28.s64 + 16;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x827bd514
	ctx.lr = 0x823F0194;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f01b4
	if (cr6.eq) goto loc_823F01B4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f01c8
	if (cr6.eq) goto loc_823F01C8;
loc_823F01B4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F01BC;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823F01C8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r3,r30,136
	ctx.r3.s64 = r30.s64 + 136;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823da950
	ctx.lr = 0x823F01E0;
	sub_823DA950(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,190(r30)
	PPC_STORE_U8(r30.u32 + 190, r11.u8);
	// b 0x823f035c
	goto loc_823F035C;
loc_823F01EC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,0(r6)
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// bl 0x823f79c8
	ctx.lr = 0x823F01F8;
	sub_823F79C8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lfs f13,-4008(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4008);
	ctx.f13.f64 = double(temp.f32);
	// lbz r7,6(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lbz r6,7(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 7);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// lbz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// lbz r4,9(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 9);
	// stw r4,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// lbz r3,10(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 10);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// lbz r11,11(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 11);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// lbz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lbz r9,13(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 13);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// lbz r8,14(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 14);
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// lbz r7,15(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 15);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// lbz r6,5(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// stw r6,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f11,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lfs f10,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,140(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f9,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,144(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f8,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,148(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f7,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,152(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lfs f6,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f5,156(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f4,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// stfs f3,160(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bl 0x827bd514
	ctx.lr = 0x823F02BC;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f02e4
	if (cr6.eq) goto loc_823F02E4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f02f8
	if (cr6.eq) goto loc_823F02F8;
loc_823F02E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F02EC;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F02F8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r29,r28,16
	r29.s64 = r28.s64 + 16;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x827bd514
	ctx.lr = 0x823F0308;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f0328
	if (cr6.eq) goto loc_823F0328;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f033c
	if (cr6.eq) goto loc_823F033C;
loc_823F0328:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F0330;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823F033C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r3,r29,52
	ctx.r3.s64 = r29.s64 + 52;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// li r5,84
	ctx.r5.s64 = 84;
	// bl 0x823da950
	ctx.lr = 0x823F0354;
	sub_823DA950(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,189(r29)
	PPC_STORE_U8(r29.u32 + 189, r11.u8);
loc_823F035C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f03ac
	if (cr6.eq) goto loc_823F03AC;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f03ac
	if (!cr6.eq) goto loc_823F03AC;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f03ac
	if (!cr0.eq) goto loc_823F03AC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F03A0;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F03A8;
	__imp__KfLowerIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F03AC:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f03f4
	if (cr6.eq) goto loc_823F03F4;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f03f4
	if (!cr6.eq) goto loc_823F03F4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f03f4
	if (!cr0.eq) goto loc_823F03F4;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F03EC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F03F4;
	__imp__KfLowerIrql(ctx, base);
loc_823F03F4:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823F0404"))) PPC_WEAK_FUNC(sub_823F0404);
PPC_FUNC_IMPL(__imp__sub_823F0404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F0408"))) PPC_WEAK_FUNC(sub_823F0408);
PPC_FUNC_IMPL(__imp__sub_823F0408) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91c8
	ctx.lr = 0x823F0410;
	// stfd f30,-152(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -152, f30.u64);
	// stfd f31,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, f31.u64);
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lfs f0,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// addi r21,r3,20
	r21.s64 = ctx.r3.s64 + 20;
	// subf r25,r8,r9
	r25.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmplwi cr6,r25,4
	cr6.compare<uint32_t>(r25.u32, 4, xer);
	// bgt cr6,0x823f0448
	if (cr6.gt) goto loc_823F0448;
	// subf r11,r9,r8
	r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// ble cr6,0x823f044c
	if (!cr6.gt) goto loc_823F044C;
loc_823F0448:
	// li r6,1
	ctx.r6.s64 = 1;
loc_823F044C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r23,r3,4
	r23.s64 = ctx.r3.s64 + 4;
	// addi r22,r3,24
	r22.s64 = ctx.r3.s64 + 24;
	// lfs f0,29500(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29500);
	f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, ctx.f13.u64);
	// lwz r7,-156(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -156);
	// rlwinm r7,r7,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r7,256
	cr6.compare<uint32_t>(ctx.r7.u32, 256, xer);
	// bge cr6,0x823f0864
	if (!cr6.lt) goto loc_823F0864;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r31,-32250
	r31.s64 = -2113536000;
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// li r27,1
	r27.s64 = 1;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-4000(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4000);
	f0.f64 = double(temp.f32);
	// fsubs f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// blt cr6,0x823f05c4
	if (cr6.lt) goto loc_823F05C4;
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// subf r29,r9,r10
	r29.s64 = ctx.r10.s64 - ctx.r9.s64;
	// subf r9,r8,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r8.s64;
	// rlwinm r27,r7,0,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r9,2
	ctx.r6.s64 = ctx.r9.s64 + 2;
	// add r10,r27,r10
	ctx.r10.u64 = r27.u64 + ctx.r10.u64;
	// addi r31,r29,2
	r31.s64 = r29.s64 + 2;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// addi r30,r4,8
	r30.s64 = ctx.r4.s64 + 8;
	// addi r9,r5,12
	ctx.r9.s64 = ctx.r5.s64 + 12;
	// subf r26,r5,r4
	r26.s64 = ctx.r4.s64 - ctx.r5.s64;
	// rlwinm r28,r7,30,2,31
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_823F04DC:
	// fsubs f10,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// add r24,r29,r25
	r24.u64 = r29.u64 + r25.u64;
	// fadds f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 + f0.f64));
	// addi r20,r6,-1
	r20.s64 = ctx.r6.s64 + -1;
	// rlwinm r18,r29,2,16,29
	r18.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFC;
	// lfs f8,-8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r24,r24,2,16,29
	r24.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFC;
	// lfs f7,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r20,r20,2,16,29
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFC;
	// lfs f6,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// addi r19,r31,-1
	r19.s64 = r31.s64 + -1;
	// lfsx f5,r26,r9
	temp.u32 = PPC_LOAD_U32(r26.u32 + ctx.r9.u32);
	ctx.f5.f64 = double(temp.f32);
	// addi r17,r6,1
	r17.s64 = ctx.r6.s64 + 1;
	// lfsx f4,r18,r11
	temp.u32 = PPC_LOAD_U32(r18.u32 + r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r19,r19,2,16,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFC;
	// lfsx f3,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r16,r6,2,16,29
	r16.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFC;
	// stfs f8,-8(r8)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r8.u32 + -8, temp.u32);
	// rlwinm r18,r31,2,16,29
	r18.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFC;
	// fsubs f2,f10,f0
	ctx.f2.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfsx f8,r20,r11
	temp.u32 = PPC_LOAD_U32(r20.u32 + r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f10,f8,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// rlwinm r24,r17,2,16,29
	r24.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFC;
	// fsubs f8,f2,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 - f0.f64));
	// addi r20,r31,1
	r20.s64 = r31.s64 + 1;
	// fadds f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 + f0.f64));
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// fmuls f4,f4,f13
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfsx f13,r19,r11
	temp.u32 = PPC_LOAD_U32(r19.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f7,-4(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + -4, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lfsx f7,r16,r11
	temp.u32 = PPC_LOAD_U32(r16.u32 + r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f2,f7,f2
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f2.f64));
	// lfsx f30,r18,r11
	temp.u32 = PPC_LOAD_U32(r18.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// fadds f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f6,0(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmadds f4,f3,f12,f4
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 + ctx.f4.f64));
	// lfsx f7,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// rlwinm r24,r20,2,16,29
	r24.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFC;
	// fmadds f2,f30,f1,f2
	ctx.f2.f64 = double(float(f30.f64 * ctx.f1.f64 + ctx.f2.f64));
	// fmadds f3,f13,f9,f10
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// stfs f4,-8(r9)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// stfs f3,-4(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// stfs f2,0(r9)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// fsubs f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfsx f1,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f13,f1,f31,f6
	ctx.f13.f64 = double(float(ctx.f1.f64 * f31.f64 + ctx.f6.f64));
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// stfs f5,4(r8)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x823f04dc
	if (!cr0.eq) goto loc_823F04DC;
	// stfs f12,0(r23)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
loc_823F05C4:
	// cmplw cr6,r27,r7
	cr6.compare<uint32_t>(r27.u32, ctx.r7.u32, xer);
	// bgt cr6,0x823f0650
	if (cr6.gt) goto loc_823F0650;
	// rlwinm r6,r27,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r28,8(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// subf r9,r27,r7
	ctx.r9.s64 = ctx.r7.s64 - r27.s64;
	// lwz r27,12(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r29,r6,r4
	r29.u64 = ctx.r6.u64 + ctx.r4.u64;
	// lfs f12,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r31,r10,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r30,r6,r5
	r30.u64 = ctx.r6.u64 + ctx.r5.u64;
	// subf r8,r28,r10
	ctx.r8.s64 = ctx.r10.s64 - r28.s64;
	// addi r6,r29,-4
	ctx.r6.s64 = r29.s64 + -4;
	// add r31,r31,r11
	r31.u64 = r31.u64 + r11.u64;
	// subf r29,r27,r28
	r29.s64 = r28.s64 - r27.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823F0604:
	// rlwinm r28,r8,2,16,29
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFC;
	// lfs f10,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// add r27,r29,r8
	r27.u64 = r29.u64 + ctx.r8.u64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r27,r27,2,16,29
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lfsx f9,r28,r11
	temp.u32 = PPC_LOAD_U32(r28.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfsx f7,r27,r11
	temp.u32 = PPC_LOAD_U32(r27.u32 + r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// stfs f10,0(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// fmadds f6,f7,f12,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f8.f64));
	// stfs f6,0(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x823f0604
	if (!cr0.eq) goto loc_823F0604;
	// stfs f12,0(r23)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
loc_823F0650:
	// lwz r26,16(r3)
	r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// beq cr6,0x823f0668
	if (cr6.eq) goto loc_823F0668;
	// fmr f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f11.f64;
	// b 0x823f0670
	goto loc_823F0670;
loc_823F0668:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
loc_823F0670:
	// subfic r8,r7,256
	xer.ca = ctx.r7.u32 <= 256;
	ctx.r8.s64 = 256 - ctx.r7.s64;
	// stfs f12,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// fsubs f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// blt cr6,0x823f07d0
	if (cr6.lt) goto loc_823F07D0;
	// subfic r9,r7,252
	xer.ca = ctx.r7.u32 <= 252;
	ctx.r9.s64 = 252 - ctx.r7.s64;
	// lwz r20,12(r3)
	r20.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r8,r7,3
	ctx.r8.s64 = ctx.r7.s64 + 3;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// addi r29,r9,1
	r29.s64 = ctx.r9.s64 + 1;
	// addi r31,r7,2
	r31.s64 = ctx.r7.s64 + 2;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r20,r10
	ctx.r9.s64 = ctx.r10.s64 - r20.s64;
	// rlwinm r25,r6,2,0,29
	r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r28,r26,r10
	r28.s64 = ctx.r10.s64 - r26.s64;
	// rlwinm r24,r31,2,0,29
	r24.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r8,r4
	r30.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r6,r9,2
	ctx.r6.s64 = ctx.r9.s64 + 2;
	// add r8,r25,r11
	ctx.r8.u64 = r25.u64 + r11.u64;
	// add r10,r27,r10
	ctx.r10.u64 = r27.u64 + ctx.r10.u64;
	// addi r31,r28,2
	r31.s64 = r28.s64 + 2;
	// add r9,r24,r5
	ctx.r9.u64 = r24.u64 + ctx.r5.u64;
	// subf r25,r5,r4
	r25.s64 = ctx.r4.s64 - ctx.r5.s64;
	// subf r26,r20,r26
	r26.s64 = r26.s64 - r20.s64;
	// add r27,r27,r7
	r27.u64 = r27.u64 + ctx.r7.u64;
loc_823F06E8:
	// add r7,r26,r28
	ctx.r7.u64 = r26.u64 + r28.u64;
	// lfs f10,-12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -12);
	ctx.f10.f64 = double(temp.f32);
	// addi r24,r31,-1
	r24.s64 = r31.s64 + -1;
	// lfs f9,-8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// addi r20,r6,-1
	r20.s64 = ctx.r6.s64 + -1;
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// rlwinm r7,r7,2,16,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFC;
	// fsubs f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 - f0.f64));
	// rlwinm r19,r28,2,16,29
	r19.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFC;
	// lfsx f7,r9,r25
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r25.u32);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r20,r20,2,16,29
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFC;
	// lfs f6,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// rlwinm r24,r24,2,16,29
	r24.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFC;
	// addi r18,r31,1
	r18.s64 = r31.s64 + 1;
	// lfsx f4,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r7,r6,2,16,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFC;
	// lfsx f5,r19,r11
	temp.u32 = PPC_LOAD_U32(r19.u32 + r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// rlwinm r19,r31,2,16,29
	r19.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFC;
	// stfs f10,-8(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + -8, temp.u32);
	// fmuls f13,f5,f13
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// lfsx f2,r20,r11
	temp.u32 = PPC_LOAD_U32(r20.u32 + r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r20,r18,2,16,29
	r20.u64 = __builtin_rotateleft64(r18.u32 | (r18.u64 << 32), 2) & 0xFFFC;
	// lfsx f1,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fadds f3,f11,f0
	ctx.f3.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f9,-4(r8)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r8.u32 + -4, temp.u32);
	// fsubs f10,f8,f0
	ctx.f10.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfsx f31,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f31.f64 = double(temp.f32);
	// fadds f9,f3,f0
	ctx.f9.f64 = double(float(ctx.f3.f64 + f0.f64));
	// lfsx f5,r19,r11
	temp.u32 = PPC_LOAD_U32(r19.u32 + r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f1,f1,f11
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// stfs f7,0(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f7,f5,f3
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f3.f64));
	// lfsx f11,r20,r11
	temp.u32 = PPC_LOAD_U32(r20.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f30,f10,f0
	f30.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fmuls f5,f11,f9
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// addi r7,r6,1
	ctx.r7.s64 = ctx.r6.s64 + 1;
	// rlwinm r7,r7,2,16,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFC;
	// fmadds f3,f2,f8,f1
	ctx.f3.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + ctx.f1.f64));
	// fmadds f4,f4,f12,f13
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 + ctx.f13.f64));
	// stfs f4,-4(r9)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// fmadds f2,f31,f10,f7
	ctx.f2.f64 = double(float(f31.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f3,0(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f2,4(r9)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fsubs f12,f30,f0
	ctx.f12.f64 = double(float(f30.f64 - f0.f64));
	// lfsx f1,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f13,f1,f30,f5
	ctx.f13.f64 = double(float(ctx.f1.f64 * f30.f64 + ctx.f5.f64));
	// stfs f13,8(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// stfs f6,4(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// fadds f13,f9,f0
	ctx.f13.f64 = double(float(ctx.f9.f64 + f0.f64));
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x823f06e8
	if (!cr0.eq) goto loc_823F06E8;
	// stfs f12,0(r23)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
loc_823F07D0:
	// cmplwi cr6,r27,256
	cr6.compare<uint32_t>(r27.u32, 256, xer);
	// bge cr6,0x823f0858
	if (!cr6.lt) goto loc_823F0858;
	// rlwinm r7,r27,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r31,8(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r30,12(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r7,r5
	ctx.r3.u64 = ctx.r7.u64 + ctx.r5.u64;
	// lfs f12,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// subfic r9,r27,256
	xer.ca = r27.u32 <= 256;
	ctx.r9.s64 = 256 - r27.s64;
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// subf r8,r31,r10
	ctx.r8.s64 = ctx.r10.s64 - r31.s64;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + r11.u64;
	// subf r3,r30,r31
	ctx.r3.s64 = r31.s64 - r30.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823F080C:
	// rlwinm r31,r8,2,16,29
	r31.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFC;
	// lfs f11,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r30,r3,r8
	r30.u64 = ctx.r3.u64 + ctx.r8.u64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r30,r30,2,16,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lfsx f10,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfsx f8,r30,r11
	temp.u32 = PPC_LOAD_U32(r30.u32 + r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f11,0(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fmadds f7,f8,f12,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f7,0(r4)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x823f080c
	if (!cr0.eq) goto loc_823F080C;
	// stfs f12,0(r23)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
loc_823F0858:
	// clrlwi r11,r10,18
	r11.u64 = ctx.r10.u32 & 0x3FFF;
	// stw r11,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r11.u32);
	// b 0x823f0a38
	goto loc_823F0A38;
loc_823F0864:
	// addi r31,r10,256
	r31.s64 = ctx.r10.s64 + 256;
	// cmplwi cr6,r31,16384
	cr6.compare<uint32_t>(r31.u32, 16384, xer);
	// bge cr6,0x823f09b8
	if (!cr6.lt) goto loc_823F09B8;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// addi r11,r7,256
	r11.s64 = ctx.r7.s64 + 256;
	// cmplwi cr6,r11,16384
	cr6.compare<uint32_t>(r11.u32, 16384, xer);
	// bge cr6,0x823f09b8
	if (!cr6.lt) goto loc_823F09B8;
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r30,r11,256
	r30.s64 = r11.s64 + 256;
	// cmplwi cr6,r30,16384
	cr6.compare<uint32_t>(r30.u32, 16384, xer);
	// bge cr6,0x823f09b8
	if (!cr6.lt) goto loc_823F09B8;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x823f09b8
	if (cr6.lt) goto loc_823F09B8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823f09b8
	if (cr6.lt) goto loc_823F09B8;
	// addi r11,r10,8
	r11.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// bne cr6,0x823f0930
	if (!cr6.eq) goto loc_823F0930;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r5,4
	ctx.r9.s64 = ctx.r5.s64 + 4;
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// li r7,65
	ctx.r7.s64 = 65;
	// li r8,16
	ctx.r8.s64 = 16;
loc_823F08C8:
	// lvlx128 v63,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lvrx128 v62,r8,r4
	temp.u32 = ctx.r8.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v60,v63,v62
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvrx128 v59,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vor128 v58,v61,v59
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// stvlx128 v60,r0,r11
	ea = r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v60.u8[15 - i]);
	// stvrx128 v60,r11,r8
	ea = r11.u32 + ctx.r8.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v60.u8[i]);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stvlx128 v58,r0,r9
	ea = ctx.r9.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		PPC_STORE_U8(ea + i, v58.u8[15 - i]);
	// stvrx128 v58,r9,r8
	ea = ctx.r9.u32 + ctx.r8.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		PPC_STORE_U8(ea - i - 1, v58.u8[i]);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x823f08c8
	if (!cr0.eq) goto loc_823F08C8;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r31,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r31.u32);
	// lfs f0,-4004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4004);
	f0.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 - f0.f64));
	// stfs f0,0(r23)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// lfs f0,1024(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 1024);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r21)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + 0, temp.u32);
	// lfd f30,-152(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
loc_823F0930:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r6,r11
	ctx.r10.s64 = r11.s64 - ctx.r6.s64;
	// addi r8,r5,4
	ctx.r8.s64 = ctx.r5.s64 + 4;
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// subf r7,r3,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r3.s64;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// li r9,256
	ctx.r9.s64 = 256;
	// lfs f12,-4000(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4000);
	ctx.f12.f64 = double(temp.f32);
loc_823F0960:
	// lfs f11,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfsx f9,r7,r10
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f8,0(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmadds f7,f9,f0,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f10.f64));
	// stfs f7,0(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x823f0960
	if (!cr0.eq) goto loc_823F0960;
	// stfs f0,0(r23)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// stw r31,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r31.u32);
	// lfs f0,1024(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 1024);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r21)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + 0, temp.u32);
	// lfd f30,-152(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
loc_823F09B8:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
	// addi r6,r3,32
	ctx.r6.s64 = ctx.r3.s64 + 32;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// addi r7,r5,4
	ctx.r7.s64 = ctx.r5.s64 + 4;
	// lfs f12,-4000(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -4000);
	ctx.f12.f64 = double(temp.f32);
	// li r9,256
	ctx.r9.s64 = 256;
	// addi r10,r10,256
	ctx.r10.s64 = ctx.r10.s64 + 256;
loc_823F09EC:
	// rlwinm r3,r11,2,16,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFC;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r31,r11,r25
	r31.u64 = r11.u64 + r25.u64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r31,r31,2,16,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfsx f10,r3,r6
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// lfsx f8,r31,r6
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f11,0(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// fmadds f7,f8,f0,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f9.f64));
	// stfs f7,0(r7)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x823f09ec
	if (!cr0.eq) goto loc_823F09EC;
	// stfs f0,0(r23)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
loc_823F0A38:
	// clrlwi r11,r10,18
	r11.u64 = ctx.r10.u32 & 0x3FFF;
	// lfs f0,1024(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 1024);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r21)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r21.u32 + 0, temp.u32);
	// stw r11,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r11.u32);
	// lfd f30,-152(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_823F0A54"))) PPC_WEAK_FUNC(sub_823F0A54);
PPC_FUNC_IMPL(__imp__sub_823F0A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F0A58"))) PPC_WEAK_FUNC(sub_823F0A58);
PPC_FUNC_IMPL(__imp__sub_823F0A58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f9,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stfs f9,0(r5)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// addi r11,r5,4
	r11.s64 = ctx.r5.s64 + 4;
	// lfs f8,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f8.f64 = double(temp.f32);
	// blt cr6,0x823f0b14
	if (cr6.lt) goto loc_823F0B14;
	// lfs f0,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r6,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFC;
	// fsubs f11,f8,f0
	ctx.f11.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f10,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r10,r6,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// fmuls f13,f10,f11
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
loc_823F0A98:
	// lfs f7,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f9,f0,f9
	ctx.f9.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// lfs f5,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f10
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f10.f64));
	// lfs f3,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f2,f3,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// fmuls f7,f1,f10
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f10.f64));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// fmadds f5,f13,f12,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f5,0(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmadds f12,f0,f12,f6
	ctx.f12.f64 = double(float(f0.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fmuls f3,f0,f5
	ctx.f3.f64 = double(float(f0.f64 * ctx.f5.f64));
	// fmuls f1,f0,f12
	ctx.f1.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fmadds f9,f13,f12,f3
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f3.f64));
	// stfs f9,4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fmadds f12,f4,f11,f1
	ctx.f12.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f1.f64));
	// fmuls f6,f0,f9
	ctx.f6.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmuls f5,f0,f12
	ctx.f5.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fmadds f4,f13,f12,f6
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f6.f64));
	// stfs f4,8(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fmadds f12,f2,f11,f5
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f5.f64));
	// fmuls f3,f0,f4
	ctx.f3.f64 = double(float(f0.f64 * ctx.f4.f64));
	// fmuls f2,f0,f12
	ctx.f2.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fmadds f9,f13,f12,f3
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f3.f64));
	// stfs f9,12(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// fmadds f12,f7,f11,f2
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f2.f64));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x823f0a98
	if (!cr0.eq) goto loc_823F0A98;
loc_823F0B14:
	// cmplw cr6,r9,r6
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, xer);
	// bgt cr6,0x823f0b5c
	if (cr6.gt) goto loc_823F0B5C;
	// lfs f0,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	f0.f64 = double(temp.f32);
	// subf r10,r9,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r9.s64;
	// fsubs f13,f8,f0
	ctx.f13.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f11,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// fmuls f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
loc_823F0B34:
	// fmuls f11,f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f0.f64 * ctx.f9.f64));
	// lfs f8,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 * ctx.f12.f64));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmadds f9,f13,f12,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f11.f64));
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmadds f12,f13,f8,f10
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f10.f64));
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x823f0b34
	if (!cr0.eq) goto loc_823F0B34;
loc_823F0B5C:
	// stfs f9,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f12,16(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F0B68"))) PPC_WEAK_FUNC(sub_823F0B68);
PPC_FUNC_IMPL(__imp__sub_823F0B68) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823F0B70;
	// lwz r7,36(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f11,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r29,24(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lfs f10,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// subf r11,r30,r7
	r11.s64 = ctx.r7.s64 - r30.s64;
	// lfs f0,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r31,r31,r30
	r31.s64 = r30.s64 - r31.s64;
	// lfs f12,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// stfs f11,0(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// subf r30,r29,r30
	r30.s64 = r30.s64 - r29.s64;
	// stfs f10,0(r6)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// li r9,256
	ctx.r9.s64 = 256;
	// addi r7,r7,256
	ctx.r7.s64 = ctx.r7.s64 + 256;
loc_823F0BBC:
	// rlwinm r29,r11,2,21,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x7FC;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r28,r31,r11
	r28.u64 = r31.u64 + r11.u64;
	// add r27,r30,r11
	r27.u64 = r30.u64 + r11.u64;
	// rlwinm r28,r28,2,21,29
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x7FC;
	// rlwinm r27,r27,2,21,29
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0x7FC;
	// lfsx f10,r29,r10
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfsx f8,r28,r10
	temp.u32 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	ctx.f8.f64 = double(temp.f32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// lfsx f7,r27,r10
	temp.u32 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stfs f11,0(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stfs f6,0(r6)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// fmadds f5,f8,f0,f9
	ctx.f5.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f9.f64));
	// stfs f5,0(r5)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// bne 0x823f0bbc
	if (!cr0.eq) goto loc_823F0BBC;
	// clrlwi r11,r7,23
	r11.u64 = ctx.r7.u32 & 0x1FF;
	// fmr f0,f5
	f0.f64 = ctx.f5.f64;
	// fmr f13,f6
	ctx.f13.f64 = ctx.f6.f64;
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f13,32(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F0C30"))) PPC_WEAK_FUNC(sub_823F0C30);
PPC_FUNC_IMPL(__imp__sub_823F0C30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x823F0C38;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9d4
	ctx.lr = 0x823F0C40;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r3,24
	r11.s64 = ctx.r3.s64 + 24;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r10,r6,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r6.s64;
	// lfs f12,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
loc_823F0C70:
	// addi r7,r10,-2
	ctx.r7.s64 = ctx.r10.s64 + -2;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r7,r7,2,23,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x1FC;
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r5,r5,2,23,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// lfs f8,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r31,r10,2,23,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x1FC;
	// lfs f7,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// addi r30,r10,1
	r30.s64 = ctx.r10.s64 + 1;
	// lfs f6,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// addi r29,r10,2
	r29.s64 = ctx.r10.s64 + 2;
	// lfs f5,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r7,r30,2,23,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x1FC;
	// fmadds f3,f0,f4,f11
	ctx.f3.f64 = double(float(f0.f64 * ctx.f4.f64 + ctx.f11.f64));
	// stfs f3,-8(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// lfsx f2,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f0,f2,f10
	ctx.f1.f64 = double(float(f0.f64 * ctx.f2.f64 + ctx.f10.f64));
	// stfs f1,-4(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// lfsx f11,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r31,r29,2,23,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x1FC;
	// fmadds f10,f0,f11,f9
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f10,0(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lfsx f9,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r5,r5,2,23,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// fmadds f8,f0,f9,f8
	ctx.f8.f64 = double(float(f0.f64 * ctx.f9.f64 + ctx.f8.f64));
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// stfs f8,4(r9)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addi r30,r10,5
	r30.s64 = ctx.r10.s64 + 5;
	// lfsx f31,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	f31.f64 = double(temp.f32);
	// rlwinm r7,r7,2,23,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x1FC;
	// fmadds f7,f0,f31,f7
	ctx.f7.f64 = double(float(f0.f64 * f31.f64 + ctx.f7.f64));
	// stfs f7,8(r9)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// lfsx f30,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// rlwinm r5,r30,2,23,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x1FC;
	// fmadds f6,f0,f30,f6
	ctx.f6.f64 = double(float(f0.f64 * f30.f64 + ctx.f6.f64));
	// stfs f6,12(r9)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// lfsx f29,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f29.f64 = double(temp.f32);
	// fmadds f5,f0,f29,f5
	ctx.f5.f64 = double(float(f0.f64 * f29.f64 + ctx.f5.f64));
	// lfs f28,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	f28.f64 = double(temp.f32);
	// addi r7,r4,28
	ctx.r7.s64 = ctx.r4.s64 + 28;
	// stfs f5,16(r9)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// fmadds f4,f13,f3,f4
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + ctx.f4.f64));
	// lfsx f27,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	f27.f64 = double(temp.f32);
	// fmadds f28,f0,f27,f28
	f28.f64 = double(float(f0.f64 * f27.f64 + f28.f64));
	// fmadds f3,f13,f1,f2
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f2.f64));
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmadds f2,f13,f10,f11
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f11.f64));
	// stfs f28,20(r9)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r9.u32 + 20, temp.u32);
	// fmadds f1,f13,f8,f9
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f9.f64));
	// stfs f4,4(r4)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fmadds f11,f13,f7,f31
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + f31.f64));
	// stfs f3,8(r4)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// fmadds f10,f13,f6,f30
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + f30.f64));
	// stfs f2,12(r4)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// stfs f1,16(r4)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// fmadds f9,f13,f5,f29
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + f29.f64));
	// stfs f11,20(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stfs f10,24(r4)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// fmadds f12,f13,f28,f27
	ctx.f12.f64 = double(float(ctx.f13.f64 * f28.f64 + f27.f64));
	// stfs f9,0(r7)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// bne 0x823f0c70
	if (!cr0.eq) goto loc_823F0C70;
	// neg r7,r6
	ctx.r7.s64 = -ctx.r6.s64;
	// subfic r9,r6,2
	xer.ca = ctx.r6.u32 <= 2;
	ctx.r9.s64 = 2 - ctx.r6.s64;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// li r8,16
	ctx.r8.s64 = 16;
loc_823F0D94:
	// rlwinm r6,r7,2,23,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x1FC;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// rlwinm r27,r9,2,23,29
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x1FC;
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r26,r5,2,23,29
	r26.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// lfs f8,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// lfsx f6,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// addi r6,r9,2
	ctx.r6.s64 = ctx.r9.s64 + 2;
	// fmadds f5,f0,f6,f11
	ctx.f5.f64 = double(float(f0.f64 * ctx.f6.f64 + ctx.f11.f64));
	// stfs f5,-8(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8, temp.u32);
	// rlwinm r25,r5,2,23,29
	r25.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// lfs f7,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r24,r6,2,23,29
	r24.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x1FC;
	// lfs f4,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// lfs f3,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// addi r5,r9,3
	ctx.r5.s64 = ctx.r9.s64 + 3;
	// rlwinm r22,r6,2,23,29
	r22.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x1FC;
	// addi r6,r4,8
	ctx.r6.s64 = ctx.r4.s64 + 8;
	// rlwinm r23,r5,2,23,29
	r23.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// addi r5,r9,5
	ctx.r5.s64 = ctx.r9.s64 + 5;
	// addi r28,r4,28
	r28.s64 = ctx.r4.s64 + 28;
	// fmadds f2,f13,f5,f6
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + ctx.f6.f64));
	// stfs f2,4(r4)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// rlwinm r21,r5,2,23,29
	r21.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x1FC;
	// addi r5,r4,12
	ctx.r5.s64 = ctx.r4.s64 + 12;
	// addi r31,r4,16
	r31.s64 = ctx.r4.s64 + 16;
	// lfs f1,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r30,r4,20
	r30.s64 = ctx.r4.s64 + 20;
	// addi r29,r4,24
	r29.s64 = ctx.r4.s64 + 24;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// addi r7,r7,8
	ctx.r7.s64 = ctx.r7.s64 + 8;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lfsx f12,r26,r11
	temp.u32 = PPC_LOAD_U32(r26.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f0,f12,f10
	ctx.f11.f64 = double(float(f0.f64 * ctx.f12.f64 + ctx.f10.f64));
	// stfs f11,-4(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// lfsx f6,r27,r11
	temp.u32 = PPC_LOAD_U32(r27.u32 + r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f0,f6,f9
	ctx.f5.f64 = double(float(f0.f64 * ctx.f6.f64 + ctx.f9.f64));
	// stfs f5,0(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fmadds f10,f13,f11,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f10,0(r6)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmadds f11,f13,f5,f6
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + ctx.f6.f64));
	// stfs f11,0(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lfsx f2,r25,r11
	temp.u32 = PPC_LOAD_U32(r25.u32 + r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f12,f0,f2,f8
	ctx.f12.f64 = double(float(f0.f64 * ctx.f2.f64 + ctx.f8.f64));
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fmadds f8,f13,f12,f2
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f2.f64));
	// stfs f8,0(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lfsx f10,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f0,f10,f7
	ctx.f9.f64 = double(float(f0.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f9,8(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfsx f6,r23,r11
	temp.u32 = PPC_LOAD_U32(r23.u32 + r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f0,f6,f4
	ctx.f5.f64 = double(float(f0.f64 * ctx.f6.f64 + ctx.f4.f64));
	// stfs f5,12(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// fmadds f7,f13,f9,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// lfsx f4,r22,r11
	temp.u32 = PPC_LOAD_U32(r22.u32 + r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f0,f4,f3
	ctx.f3.f64 = double(float(f0.f64 * ctx.f4.f64 + ctx.f3.f64));
	// stfs f3,16(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// fmadds f2,f13,f5,f6
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + ctx.f6.f64));
	// lfsx f12,r21,r11
	temp.u32 = PPC_LOAD_U32(r21.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f0,f12,f1
	ctx.f11.f64 = double(float(f0.f64 * ctx.f12.f64 + ctx.f1.f64));
	// stfs f11,20(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// fmadds f10,f13,f3,f4
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + ctx.f4.f64));
	// stfs f7,0(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// fmadds f12,f13,f11,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f2,0(r29)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stfs f10,0(r28)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// bne 0x823f0d94
	if (!cr0.eq) goto loc_823F0D94;
	// li r11,0
	r11.s64 = 0;
	// stfs f12,12(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba20
	ctx.lr = 0x823F0ED4;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_823F0ED8"))) PPC_WEAK_FUNC(sub_823F0ED8);
PPC_FUNC_IMPL(__imp__sub_823F0ED8) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823F0EE0;
	// lwz r7,36(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f11,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r29,24(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lfs f10,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// subf r11,r30,r7
	r11.s64 = ctx.r7.s64 - r30.s64;
	// lfs f0,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r31,r31,r30
	r31.s64 = r30.s64 - r31.s64;
	// lfs f12,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// stfs f11,0(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// subf r30,r29,r30
	r30.s64 = r30.s64 - r29.s64;
	// stfs f10,0(r6)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// li r9,256
	ctx.r9.s64 = 256;
	// addi r7,r7,256
	ctx.r7.s64 = ctx.r7.s64 + 256;
loc_823F0F2C:
	// rlwinm r29,r11,2,19,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x1FFC;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r28,r31,r11
	r28.u64 = r31.u64 + r11.u64;
	// add r27,r30,r11
	r27.u64 = r30.u64 + r11.u64;
	// rlwinm r28,r28,2,19,29
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x1FFC;
	// rlwinm r27,r27,2,19,29
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0x1FFC;
	// lfsx f10,r29,r10
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfsx f8,r28,r10
	temp.u32 = PPC_LOAD_U32(r28.u32 + ctx.r10.u32);
	ctx.f8.f64 = double(temp.f32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// lfsx f7,r27,r10
	temp.u32 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stfs f11,0(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stfs f6,0(r6)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// fmadds f5,f8,f0,f9
	ctx.f5.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f9.f64));
	// stfs f5,0(r5)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// bne 0x823f0f2c
	if (!cr0.eq) goto loc_823F0F2C;
	// clrlwi r11,r7,21
	r11.u64 = ctx.r7.u32 & 0x7FF;
	// fmr f0,f5
	f0.f64 = ctx.f5.f64;
	// fmr f13,f6
	ctx.f13.f64 = ctx.f6.f64;
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f13,32(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F0FA0"))) PPC_WEAK_FUNC(sub_823F0FA0);
PPC_FUNC_IMPL(__imp__sub_823F0FA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823F0FA8;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d4
	ctx.lr = 0x823F0FB0;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r3,24
	ctx.r9.s64 = ctx.r3.s64 + 24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r10,r7,2
	ctx.r10.s64 = ctx.r7.s64 + 2;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r11,r11,r7
	r11.s64 = ctx.r7.s64 - r11.s64;
	// lfs f12,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// li r8,32
	ctx.r8.s64 = 32;
	// add r11,r6,r9
	r11.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r7,r7,256
	ctx.r7.s64 = ctx.r7.s64 + 256;
loc_823F0FE4:
	// addi r6,r10,-2
	ctx.r6.s64 = ctx.r10.s64 + -2;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r5,r5,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// lfs f8,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r31,r10,2,22,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FC;
	// lfs f7,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// addi r30,r10,1
	r30.s64 = ctx.r10.s64 + 1;
	// lfs f6,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// addi r29,r10,2
	r29.s64 = ctx.r10.s64 + 2;
	// lfs f5,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r6,r30,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x3FC;
	// fmadds f3,f0,f4,f11
	ctx.f3.f64 = double(float(f0.f64 * ctx.f4.f64 + ctx.f11.f64));
	// stfs f3,-8(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// lfsx f2,r5,r9
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f0,f2,f10
	ctx.f1.f64 = double(float(f0.f64 * ctx.f2.f64 + ctx.f10.f64));
	// stfs f1,-4(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// lfsx f10,r31,r9
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r31,r29,2,22,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x3FC;
	// fmadds f9,f0,f10,f9
	ctx.f9.f64 = double(float(f0.f64 * ctx.f10.f64 + ctx.f9.f64));
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfsx f31,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	f31.f64 = double(temp.f32);
	// rlwinm r5,r5,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x3FC;
	// fmadds f8,f0,f31,f8
	ctx.f8.f64 = double(float(f0.f64 * f31.f64 + ctx.f8.f64));
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// stfs f8,4(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// addi r30,r10,5
	r30.s64 = ctx.r10.s64 + 5;
	// lfsx f30,r31,r9
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	f30.f64 = double(temp.f32);
	// fmadds f7,f0,f30,f7
	ctx.f7.f64 = double(float(f0.f64 * f30.f64 + ctx.f7.f64));
	// rlwinm r6,r6,2,22,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// stfs f7,8(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lfsx f29,r5,r9
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	f29.f64 = double(temp.f32);
	// rlwinm r5,r30,2,22,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x3FC;
	// fmadds f6,f0,f29,f6
	ctx.f6.f64 = double(float(f0.f64 * f29.f64 + ctx.f6.f64));
	// stfs f6,12(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// lfsx f28,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	f28.f64 = double(temp.f32);
	// fmadds f5,f0,f28,f5
	ctx.f5.f64 = double(float(f0.f64 * f28.f64 + ctx.f5.f64));
	// lfs f11,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f4,f13,f3,f4
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + ctx.f4.f64));
	// stfs f5,16(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// fmadds f2,f13,f1,f2
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f2.f64));
	// lfsx f3,r5,r9
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f27,f0,f3,f11
	f27.f64 = double(float(f0.f64 * ctx.f3.f64 + ctx.f11.f64));
	// fmadds f11,f13,f27,f3
	ctx.f11.f64 = double(float(ctx.f13.f64 * f27.f64 + ctx.f3.f64));
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmadds f1,f13,f9,f10
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// stfs f4,4(r4)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fmadds f12,f13,f8,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + f31.f64));
	// stfs f12,16(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// fmadds f10,f13,f7,f30
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + f30.f64));
	// stfs f2,8(r4)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// fmadds f9,f13,f6,f29
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + f29.f64));
	// stfs f1,12(r4)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// fmadds f8,f13,f5,f28
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + f28.f64));
	// stfs f10,20(r4)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// stfs f9,24(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stfs f8,28(r4)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + 28, temp.u32);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// stfs f27,20(r11)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
	// bne 0x823f0fe4
	if (!cr0.eq) goto loc_823F0FE4;
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// stfs f11,12(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f11,0(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba20
	ctx.lr = 0x823F1110;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F1114"))) PPC_WEAK_FUNC(sub_823F1114);
PPC_FUNC_IMPL(__imp__sub_823F1114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F1118"))) PPC_WEAK_FUNC(sub_823F1118);
PPC_FUNC_IMPL(__imp__sub_823F1118) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823F1120;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d4
	ctx.lr = 0x823F1128;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r3,24
	ctx.r9.s64 = ctx.r3.s64 + 24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r10,r7,2
	ctx.r10.s64 = ctx.r7.s64 + 2;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r11,r11,r7
	r11.s64 = ctx.r7.s64 - r11.s64;
	// lfs f12,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// li r8,32
	ctx.r8.s64 = 32;
	// add r11,r6,r9
	r11.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r7,r7,256
	ctx.r7.s64 = ctx.r7.s64 + 256;
loc_823F115C:
	// addi r6,r10,-2
	ctx.r6.s64 = ctx.r10.s64 + -2;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r6,r6,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r5,r5,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// lfs f8,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r31,r10,2,21,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lfs f7,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// addi r30,r10,1
	r30.s64 = ctx.r10.s64 + 1;
	// lfs f6,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// addi r29,r10,2
	r29.s64 = ctx.r10.s64 + 2;
	// lfs f5,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r6,r30,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x7FC;
	// fmadds f3,f0,f4,f11
	ctx.f3.f64 = double(float(f0.f64 * ctx.f4.f64 + ctx.f11.f64));
	// stfs f3,-8(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// lfsx f2,r5,r9
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f0,f2,f10
	ctx.f1.f64 = double(float(f0.f64 * ctx.f2.f64 + ctx.f10.f64));
	// stfs f1,-4(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// lfsx f10,r31,r9
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r31,r29,2,21,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x7FC;
	// fmadds f9,f0,f10,f9
	ctx.f9.f64 = double(float(f0.f64 * ctx.f10.f64 + ctx.f9.f64));
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfsx f31,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	f31.f64 = double(temp.f32);
	// rlwinm r5,r5,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x7FC;
	// fmadds f8,f0,f31,f8
	ctx.f8.f64 = double(float(f0.f64 * f31.f64 + ctx.f8.f64));
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// stfs f8,4(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// addi r30,r10,5
	r30.s64 = ctx.r10.s64 + 5;
	// lfsx f30,r31,r9
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	f30.f64 = double(temp.f32);
	// fmadds f7,f0,f30,f7
	ctx.f7.f64 = double(float(f0.f64 * f30.f64 + ctx.f7.f64));
	// rlwinm r6,r6,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// stfs f7,8(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lfsx f29,r5,r9
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	f29.f64 = double(temp.f32);
	// rlwinm r5,r30,2,21,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0x7FC;
	// fmadds f6,f0,f29,f6
	ctx.f6.f64 = double(float(f0.f64 * f29.f64 + ctx.f6.f64));
	// stfs f6,12(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// lfsx f28,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	f28.f64 = double(temp.f32);
	// fmadds f5,f0,f28,f5
	ctx.f5.f64 = double(float(f0.f64 * f28.f64 + ctx.f5.f64));
	// lfs f11,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f4,f13,f3,f4
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + ctx.f4.f64));
	// stfs f5,16(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// fmadds f2,f13,f1,f2
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f2.f64));
	// lfsx f3,r5,r9
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f27,f0,f3,f11
	f27.f64 = double(float(f0.f64 * ctx.f3.f64 + ctx.f11.f64));
	// fmadds f11,f13,f27,f3
	ctx.f11.f64 = double(float(ctx.f13.f64 * f27.f64 + ctx.f3.f64));
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmadds f1,f13,f9,f10
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// stfs f4,4(r4)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fmadds f12,f13,f8,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + f31.f64));
	// stfs f12,16(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// fmadds f10,f13,f7,f30
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + f30.f64));
	// stfs f2,8(r4)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// fmadds f9,f13,f6,f29
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + f29.f64));
	// stfs f1,12(r4)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// fmadds f8,f13,f5,f28
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + f28.f64));
	// stfs f10,20(r4)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// stfs f9,24(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stfs f8,28(r4)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + 28, temp.u32);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// stfs f27,20(r11)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
	// bne 0x823f115c
	if (!cr0.eq) goto loc_823F115C;
	// clrlwi r11,r7,23
	r11.u64 = ctx.r7.u32 & 0x1FF;
	// stfs f11,12(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f11,0(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba20
	ctx.lr = 0x823F1288;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F128C"))) PPC_WEAK_FUNC(sub_823F128C);
PPC_FUNC_IMPL(__imp__sub_823F128C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F1290"))) PPC_WEAK_FUNC(sub_823F1290);
PPC_FUNC_IMPL(__imp__sub_823F1290) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823F1298;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d4
	ctx.lr = 0x823F12A0;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r3,24
	ctx.r9.s64 = ctx.r3.s64 + 24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r10,r7,2
	ctx.r10.s64 = ctx.r7.s64 + 2;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// subf r11,r11,r7
	r11.s64 = ctx.r7.s64 - r11.s64;
	// lfs f12,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r7,r7,256
	ctx.r7.s64 = ctx.r7.s64 + 256;
loc_823F12D4:
	// addi r6,r11,-2
	ctx.r6.s64 = r11.s64 + -2;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r31,r11,-1
	r31.s64 = r11.s64 + -1;
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r6,r6,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r31,r31,2,21,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0x7FC;
	// lfs f8,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r30,r11,2,21,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x7FC;
	// lfs f7,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// lfs f6,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// addi r28,r11,2
	r28.s64 = r11.s64 + 2;
	// lfs f5,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r6,r29,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x7FC;
	// fmadds f3,f0,f4,f11
	ctx.f3.f64 = double(float(f0.f64 * ctx.f4.f64 + ctx.f11.f64));
	// stfs f3,-8(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8, temp.u32);
	// lfsx f2,r31,r9
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f0,f2,f10
	ctx.f1.f64 = double(float(f0.f64 * ctx.f2.f64 + ctx.f10.f64));
	// stfs f1,-4(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// addi r31,r11,3
	r31.s64 = r11.s64 + 3;
	// lfsx f10,r30,r9
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r30,r28,2,21,29
	r30.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x7FC;
	// fmadds f9,f0,f10,f9
	ctx.f9.f64 = double(float(f0.f64 * ctx.f10.f64 + ctx.f9.f64));
	// stfs f9,0(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfsx f31,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	f31.f64 = double(temp.f32);
	// rlwinm r31,r31,2,21,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0x7FC;
	// fmadds f8,f0,f31,f8
	ctx.f8.f64 = double(float(f0.f64 * f31.f64 + ctx.f8.f64));
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// stfs f8,4(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// addi r29,r11,5
	r29.s64 = r11.s64 + 5;
	// lfsx f30,r30,r9
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	f30.f64 = double(temp.f32);
	// fmadds f7,f0,f30,f7
	ctx.f7.f64 = double(float(f0.f64 * f30.f64 + ctx.f7.f64));
	// rlwinm r6,r6,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// stfs f7,8(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfsx f29,r31,r9
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	f29.f64 = double(temp.f32);
	// rlwinm r31,r29,2,21,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x7FC;
	// fmadds f6,f0,f29,f6
	ctx.f6.f64 = double(float(f0.f64 * f29.f64 + ctx.f6.f64));
	// stfs f6,12(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lfsx f28,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	f28.f64 = double(temp.f32);
	// fmadds f5,f0,f28,f5
	ctx.f5.f64 = double(float(f0.f64 * f28.f64 + ctx.f5.f64));
	// lfs f11,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f4,f13,f3,f4
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + ctx.f4.f64));
	// stfs f5,16(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// fmadds f2,f13,f1,f2
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f2.f64));
	// lfsx f3,r31,r9
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f27,f0,f3,f11
	f27.f64 = double(float(f0.f64 * ctx.f3.f64 + ctx.f11.f64));
	// fmadds f11,f13,f27,f3
	ctx.f11.f64 = double(float(ctx.f13.f64 * f27.f64 + ctx.f3.f64));
	// stfs f12,0(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// fmadds f1,f13,f9,f10
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// stfs f4,4(r5)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// fmadds f12,f13,f8,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + f31.f64));
	// stfs f12,16(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 16, temp.u32);
	// fmadds f10,f13,f7,f30
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + f30.f64));
	// stfs f2,8(r5)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// fmadds f9,f13,f6,f29
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + f29.f64));
	// stfs f1,12(r5)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r5.u32 + 12, temp.u32);
	// fmadds f8,f13,f5,f28
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + f28.f64));
	// stfs f10,20(r5)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r5.u32 + 20, temp.u32);
	// stfs f9,24(r5)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r5.u32 + 24, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stfs f8,28(r5)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r5.u32 + 28, temp.u32);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// stfs f27,20(r10)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// addi r5,r5,32
	ctx.r5.s64 = ctx.r5.s64 + 32;
	// fmr f12,f11
	ctx.f12.f64 = ctx.f11.f64;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bne 0x823f12d4
	if (!cr0.eq) goto loc_823F12D4;
	// clrlwi r11,r7,23
	r11.u64 = ctx.r7.u32 & 0x1FF;
	// stfs f11,12(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f11,0(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x823F1404;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F1408"))) PPC_WEAK_FUNC(sub_823F1408);
PPC_FUNC_IMPL(__imp__sub_823F1408) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x823F1410;
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r31,r3,32
	r31.s64 = ctx.r3.s64 + 32;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// subf r9,r11,r7
	ctx.r9.s64 = ctx.r7.s64 - r11.s64;
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// lfs f12,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// li r11,256
	r11.s64 = 256;
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + r31.u64;
	// stfs f13,0(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r7,r7,256
	ctx.r7.s64 = ctx.r7.s64 + 256;
loc_823F1450:
	// rlwinm r30,r10,2,20,29
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFC;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r29,r9,2,20,29
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFC;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lfsx f10,r30,r31
	temp.u32 = PPC_LOAD_U32(r30.u32 + r31.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// lfsx f9,r29,r31
	temp.u32 = PPC_LOAD_U32(r29.u32 + r31.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f0,f10,f12
	f0.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f13,f9,f11
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stfs f13,0(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x823f1450
	if (!cr0.eq) goto loc_823F1450;
	// clrlwi r11,r7,22
	r11.u64 = ctx.r7.u32 & 0x3FF;
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F14AC"))) PPC_WEAK_FUNC(sub_823F14AC);
PPC_FUNC_IMPL(__imp__sub_823F14AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F14B0"))) PPC_WEAK_FUNC(sub_823F14B0);
PPC_FUNC_IMPL(__imp__sub_823F14B0) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x823F14B8;
	// stfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f30.u64);
	// stfd f31,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lfs f12,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,29500(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29500);
	f0.f64 = double(temp.f32);
	// fmuls f13,f12,f0
	ctx.f13.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctidz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.f11.u64);
	// lwz r9,-140(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -140);
	// rlwinm r7,r9,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r7,256
	cr6.compare<uint32_t>(ctx.r7.u32, 256, xer);
	// bge cr6,0x823f18e4
	if (!cr6.lt) goto loc_823F18E4;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// li r27,1
	r27.s64 = 1;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-4000(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -4000);
	f0.f64 = double(temp.f32);
	// fsubs f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// blt cr6,0x823f1644
	if (cr6.lt) goto loc_823F1644;
	// lwz r25,12(r3)
	r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// lwz r28,8(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r27,r7,0,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r9,r25,r10
	ctx.r9.s64 = ctx.r10.s64 - r25.s64;
	// subf r29,r28,r10
	r29.s64 = ctx.r10.s64 - r28.s64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r9,2
	ctx.r6.s64 = ctx.r9.s64 + 2;
	// add r10,r27,r10
	ctx.r10.u64 = r27.u64 + ctx.r10.u64;
	// subf r25,r25,r28
	r25.s64 = r28.s64 - r25.s64;
	// addi r31,r29,2
	r31.s64 = r29.s64 + 2;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// addi r30,r4,8
	r30.s64 = ctx.r4.s64 + 8;
	// addi r9,r5,12
	ctx.r9.s64 = ctx.r5.s64 + 12;
	// subf r26,r5,r4
	r26.s64 = ctx.r4.s64 - ctx.r5.s64;
	// rlwinm r28,r7,30,2,31
	r28.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_823F155C:
	// fsubs f10,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// add r24,r29,r25
	r24.u64 = r29.u64 + r25.u64;
	// fadds f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 + f0.f64));
	// addi r23,r6,-1
	r23.s64 = ctx.r6.s64 + -1;
	// rlwinm r21,r29,2,22,29
	r21.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x3FC;
	// lfs f8,-8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r24,r24,2,22,29
	r24.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0x3FC;
	// lfs f7,-4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r23,r23,2,22,29
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0x3FC;
	// lfs f6,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// addi r22,r31,-1
	r22.s64 = r31.s64 + -1;
	// lfsx f5,r26,r9
	temp.u32 = PPC_LOAD_U32(r26.u32 + ctx.r9.u32);
	ctx.f5.f64 = double(temp.f32);
	// addi r20,r6,1
	r20.s64 = ctx.r6.s64 + 1;
	// lfsx f4,r21,r11
	temp.u32 = PPC_LOAD_U32(r21.u32 + r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r22,r22,2,22,29
	r22.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0x3FC;
	// lfsx f3,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r19,r6,2,22,29
	r19.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// stfs f8,-8(r8)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r8.u32 + -8, temp.u32);
	// rlwinm r21,r31,2,22,29
	r21.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0x3FC;
	// fsubs f2,f10,f0
	ctx.f2.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfsx f8,r23,r11
	temp.u32 = PPC_LOAD_U32(r23.u32 + r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f10,f8,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// rlwinm r24,r20,2,22,29
	r24.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0x3FC;
	// fsubs f8,f2,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 - f0.f64));
	// addi r23,r31,1
	r23.s64 = r31.s64 + 1;
	// fadds f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 + f0.f64));
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// fmuls f4,f4,f13
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfsx f13,r22,r11
	temp.u32 = PPC_LOAD_U32(r22.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f7,-4(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + -4, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lfsx f7,r19,r11
	temp.u32 = PPC_LOAD_U32(r19.u32 + r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f2,f7,f2
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f2.f64));
	// lfsx f30,r21,r11
	temp.u32 = PPC_LOAD_U32(r21.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// fadds f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f6,0(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmadds f4,f3,f12,f4
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 + ctx.f4.f64));
	// lfsx f7,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// rlwinm r24,r23,2,22,29
	r24.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0x3FC;
	// fmadds f2,f30,f1,f2
	ctx.f2.f64 = double(float(f30.f64 * ctx.f1.f64 + ctx.f2.f64));
	// fmadds f3,f13,f9,f10
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// stfs f4,-8(r9)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r9.u32 + -8, temp.u32);
	// stfs f3,-4(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// stfs f2,0(r9)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// fsubs f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfsx f1,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f13,f1,f31,f6
	ctx.f13.f64 = double(float(ctx.f1.f64 * f31.f64 + ctx.f6.f64));
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// stfs f5,4(r8)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x823f155c
	if (!cr0.eq) goto loc_823F155C;
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
loc_823F1644:
	// cmplw cr6,r27,r7
	cr6.compare<uint32_t>(r27.u32, ctx.r7.u32, xer);
	// bgt cr6,0x823f16d0
	if (cr6.gt) goto loc_823F16D0;
	// rlwinm r6,r27,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r28,8(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// subf r9,r27,r7
	ctx.r9.s64 = ctx.r7.s64 - r27.s64;
	// lwz r27,12(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// add r29,r6,r4
	r29.u64 = ctx.r6.u64 + ctx.r4.u64;
	// lfs f12,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r31,r10,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r30,r6,r5
	r30.u64 = ctx.r6.u64 + ctx.r5.u64;
	// subf r8,r28,r10
	ctx.r8.s64 = ctx.r10.s64 - r28.s64;
	// addi r6,r29,-4
	ctx.r6.s64 = r29.s64 + -4;
	// add r31,r31,r11
	r31.u64 = r31.u64 + r11.u64;
	// subf r29,r27,r28
	r29.s64 = r28.s64 - r27.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823F1684:
	// rlwinm r28,r8,2,22,29
	r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FC;
	// lfs f10,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// add r27,r29,r8
	r27.u64 = r29.u64 + ctx.r8.u64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r27,r27,2,22,29
	r27.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0x3FC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lfsx f9,r28,r11
	temp.u32 = PPC_LOAD_U32(r28.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfsx f7,r27,r11
	temp.u32 = PPC_LOAD_U32(r27.u32 + r11.u32);
	ctx.f7.f64 = double(temp.f32);
	// stfs f10,0(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// fmadds f6,f7,f12,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f8.f64));
	// stfs f6,0(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x823f1684
	if (!cr0.eq) goto loc_823F1684;
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
loc_823F16D0:
	// lwz r26,16(r3)
	r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// beq cr6,0x823f16e8
	if (cr6.eq) goto loc_823F16E8;
	// fmr f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f11.f64;
	// b 0x823f16f0
	goto loc_823F16F0;
loc_823F16E8:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
loc_823F16F0:
	// subfic r8,r7,256
	xer.ca = ctx.r7.u32 <= 256;
	ctx.r8.s64 = 256 - ctx.r7.s64;
	// stfs f12,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fsubs f13,f11,f12
	ctx.f13.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// blt cr6,0x823f1850
	if (cr6.lt) goto loc_823F1850;
	// subfic r9,r7,252
	xer.ca = ctx.r7.u32 <= 252;
	ctx.r9.s64 = 252 - ctx.r7.s64;
	// lwz r23,12(r3)
	r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r8,r7,3
	ctx.r8.s64 = ctx.r7.s64 + 3;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// addi r29,r9,1
	r29.s64 = ctx.r9.s64 + 1;
	// addi r31,r7,2
	r31.s64 = ctx.r7.s64 + 2;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r23,r10
	ctx.r9.s64 = ctx.r10.s64 - r23.s64;
	// rlwinm r25,r6,2,0,29
	r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r29,2,0,29
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r28,r26,r10
	r28.s64 = ctx.r10.s64 - r26.s64;
	// rlwinm r24,r31,2,0,29
	r24.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r8,r4
	r30.u64 = ctx.r8.u64 + ctx.r4.u64;
	// addi r6,r9,2
	ctx.r6.s64 = ctx.r9.s64 + 2;
	// add r8,r25,r11
	ctx.r8.u64 = r25.u64 + r11.u64;
	// add r10,r27,r10
	ctx.r10.u64 = r27.u64 + ctx.r10.u64;
	// addi r31,r28,2
	r31.s64 = r28.s64 + 2;
	// add r9,r24,r5
	ctx.r9.u64 = r24.u64 + ctx.r5.u64;
	// subf r25,r5,r4
	r25.s64 = ctx.r4.s64 - ctx.r5.s64;
	// subf r26,r23,r26
	r26.s64 = r26.s64 - r23.s64;
	// add r27,r27,r7
	r27.u64 = r27.u64 + ctx.r7.u64;
loc_823F1768:
	// add r7,r26,r28
	ctx.r7.u64 = r26.u64 + r28.u64;
	// lfs f10,-12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -12);
	ctx.f10.f64 = double(temp.f32);
	// addi r24,r31,-1
	r24.s64 = r31.s64 + -1;
	// lfs f9,-8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -8);
	ctx.f9.f64 = double(temp.f32);
	// addi r23,r6,-1
	r23.s64 = ctx.r6.s64 + -1;
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// rlwinm r7,r7,2,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// fsubs f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 - f0.f64));
	// rlwinm r22,r28,2,22,29
	r22.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x3FC;
	// lfsx f7,r25,r9
	temp.u32 = PPC_LOAD_U32(r25.u32 + ctx.r9.u32);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r23,r23,2,22,29
	r23.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0x3FC;
	// lfs f6,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// rlwinm r24,r24,2,22,29
	r24.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0x3FC;
	// addi r21,r31,1
	r21.s64 = r31.s64 + 1;
	// lfsx f4,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r7,r6,2,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lfsx f5,r22,r11
	temp.u32 = PPC_LOAD_U32(r22.u32 + r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// rlwinm r22,r31,2,22,29
	r22.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0x3FC;
	// stfs f10,-8(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + -8, temp.u32);
	// fmuls f13,f5,f13
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// lfsx f2,r23,r11
	temp.u32 = PPC_LOAD_U32(r23.u32 + r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r23,r21,2,22,29
	r23.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0x3FC;
	// lfsx f1,r24,r11
	temp.u32 = PPC_LOAD_U32(r24.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fadds f3,f11,f0
	ctx.f3.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f9,-4(r8)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r8.u32 + -4, temp.u32);
	// fsubs f10,f8,f0
	ctx.f10.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfsx f31,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f31.f64 = double(temp.f32);
	// fadds f9,f3,f0
	ctx.f9.f64 = double(float(ctx.f3.f64 + f0.f64));
	// lfsx f5,r22,r11
	temp.u32 = PPC_LOAD_U32(r22.u32 + r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f1,f1,f11
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// stfs f7,0(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f7,f5,f3
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f3.f64));
	// lfsx f11,r23,r11
	temp.u32 = PPC_LOAD_U32(r23.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f30,f10,f0
	f30.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fmuls f5,f11,f9
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// addi r7,r6,1
	ctx.r7.s64 = ctx.r6.s64 + 1;
	// rlwinm r7,r7,2,22,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FC;
	// fmadds f3,f2,f8,f1
	ctx.f3.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + ctx.f1.f64));
	// fmadds f4,f4,f12,f13
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 + ctx.f13.f64));
	// stfs f4,-4(r9)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// fmadds f2,f31,f10,f7
	ctx.f2.f64 = double(float(f31.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f3,0(r9)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f2,4(r9)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fsubs f12,f30,f0
	ctx.f12.f64 = double(float(f30.f64 - f0.f64));
	// lfsx f1,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f13,f1,f30,f5
	ctx.f13.f64 = double(float(ctx.f1.f64 * f30.f64 + ctx.f5.f64));
	// stfs f13,8(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// stfs f6,4(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// fadds f13,f9,f0
	ctx.f13.f64 = double(float(ctx.f9.f64 + f0.f64));
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x823f1768
	if (!cr0.eq) goto loc_823F1768;
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
loc_823F1850:
	// cmplwi cr6,r27,256
	cr6.compare<uint32_t>(r27.u32, 256, xer);
	// bge cr6,0x823f18d8
	if (!cr6.lt) goto loc_823F18D8;
	// rlwinm r7,r27,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r30,8(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r29,12(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r7,r5
	r31.u64 = ctx.r7.u64 + ctx.r5.u64;
	// lfs f12,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// subfic r9,r27,256
	xer.ca = r27.u32 <= 256;
	ctx.r9.s64 = 256 - r27.s64;
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// subf r8,r30,r10
	ctx.r8.s64 = ctx.r10.s64 - r30.s64;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + r11.u64;
	// subf r31,r29,r30
	r31.s64 = r30.s64 - r29.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_823F188C:
	// rlwinm r30,r8,2,22,29
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FC;
	// lfs f11,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r29,r31,r8
	r29.u64 = r31.u64 + ctx.r8.u64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r29,r29,2,22,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x3FC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lfsx f10,r30,r11
	temp.u32 = PPC_LOAD_U32(r30.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfsx f8,r29,r11
	temp.u32 = PPC_LOAD_U32(r29.u32 + r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f11,0(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fmadds f7,f8,f12,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f7,0(r4)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x823f188c
	if (!cr0.eq) goto loc_823F188C;
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
loc_823F18D8:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// b 0x823f197c
	goto loc_823F197C;
loc_823F18E4:
	// subf r11,r10,r10
	r11.s64 = ctx.r10.s64 - ctx.r10.s64;
	// lwz r31,8(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r30,12(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
	// subf r11,r31,r10
	r11.s64 = ctx.r10.s64 - r31.s64;
	// subf r31,r30,r31
	r31.s64 = r31.s64 - r30.s64;
	// lis r30,-32250
	r30.s64 = -2113536000;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r3,32
	ctx.r6.s64 = ctx.r3.s64 + 32;
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 + ctx.r6.u64;
	// lfs f12,-4000(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -4000);
	ctx.f12.f64 = double(temp.f32);
	// add r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 + ctx.r5.u64;
	// li r9,256
	ctx.r9.s64 = 256;
	// addi r10,r10,256
	ctx.r10.s64 = ctx.r10.s64 + 256;
loc_823F1930:
	// rlwinm r30,r11,2,22,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FC;
	// lfs f11,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r29,r31,r11
	r29.u64 = r31.u64 + r11.u64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r29,r29,2,22,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0x3FC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfsx f10,r30,r6
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r6.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// lfsx f8,r29,r6
	temp.u32 = PPC_LOAD_U32(r29.u32 + ctx.r6.u32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f11,0(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// fmadds f7,f8,f0,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f9.f64));
	// stfs f7,0(r7)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x823f1930
	if (!cr0.eq) goto loc_823F1930;
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
loc_823F197C:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// lfs f0,1024(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 1024);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfd f30,-128(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_823F1998"))) PPC_WEAK_FUNC(sub_823F1998);
PPC_FUNC_IMPL(__imp__sub_823F1998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,4
	r11.s64 = 262144;
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r11,r11,47792
	r11.u64 = r11.u64 | 47792;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F19AC"))) PPC_WEAK_FUNC(sub_823F19AC);
PPC_FUNC_IMPL(__imp__sub_823F19AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F19B0"))) PPC_WEAK_FUNC(sub_823F19B0);
PPC_FUNC_IMPL(__imp__sub_823F19B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x823F19B8;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9a0
	ctx.lr = 0x823F19C0;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// ld r12,-8192(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8192);
	// ld r12,-12288(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -12288);
	// ld r12,-16384(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16384);
	// stwu r1,-17968(r1)
	ea = -17968 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,17988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 17988, r30.u32);
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823f1a08
	if (cr6.eq) goto loc_823F1A08;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823f1a00
	if (cr6.eq) goto loc_823F1A00;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r29,4(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r11.u32);
	// b 0x823f1a14
	goto loc_823F1A14;
loc_823F1A00:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x823f1a0c
	goto loc_823F1A0C;
loc_823F1A08:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
loc_823F1A0C:
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r11.u32);
	// mr r29,r11
	r29.u64 = r11.u64;
loc_823F1A14:
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r8,12(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r7,16(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r29.u32);
	// stw r10,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r10.u32);
	// stw r9,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r9.u32);
	// stw r8,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r8.u32);
	// stw r7,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r7.u32);
	// dcbt r0,r11
	// dcbt r0,r29
	// li r6,128
	ctx.r6.s64 = 128;
	// dcbt r6,r11
	// li r5,128
	ctx.r5.s64 = 128;
	// dcbt r5,r29
	// addi r5,r1,7744
	ctx.r5.s64 = ctx.r1.s64 + 7744;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r3,r30,104
	ctx.r3.s64 = r30.s64 + 104;
	// bl 0x823f0408
	ctx.lr = 0x823F1A60;
	sub_823F0408(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// li r6,256
	ctx.r6.s64 = 256;
	// addi r5,r1,9920
	ctx.r5.s64 = ctx.r1.s64 + 9920;
	// addi r4,r1,7744
	ctx.r4.s64 = ctx.r1.s64 + 7744;
	// addi r3,r3,168
	ctx.r3.s64 = ctx.r3.s64 + 168;
	// bl 0x823f0a58
	ctx.lr = 0x823F1A78;
	sub_823F0A58(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,6704
	ctx.r6.s64 = ctx.r1.s64 + 6704;
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// addi r4,r1,9920
	ctx.r4.s64 = ctx.r1.s64 + 9920;
	// addi r3,r3,240
	ctx.r3.s64 = ctx.r3.s64 + 240;
	// bl 0x823f0b68
	ctx.lr = 0x823F1A94;
	sub_823F0B68(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r3,2332
	ctx.r3.s64 = ctx.r3.s64 + 2332;
	// bl 0x823f0c30
	ctx.lr = 0x823F1AA4;
	sub_823F0C30(ctx, base);
	// addi r4,r1,16639
	ctx.r4.s64 = ctx.r1.s64 + 16639;
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// rlwinm r31,r4,0,0,24
	r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFF80;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,12096
	ctx.r6.s64 = ctx.r1.s64 + 12096;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// addi r3,r3,2868
	ctx.r3.s64 = ctx.r3.s64 + 2868;
	// bl 0x823f0ed8
	ctx.lr = 0x823F1AC8;
	sub_823F0ED8(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,11104
	ctx.r3.s64 = ctx.r3.s64 + 11104;
	// bl 0x823f0fa0
	ctx.lr = 0x823F1AD8;
	sub_823F0FA0(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// addi r5,r1,4640
	ctx.r5.s64 = ctx.r1.s64 + 4640;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,12152
	ctx.r3.s64 = ctx.r3.s64 + 12152;
	// bl 0x823f1290
	ctx.lr = 0x823F1AEC;
	sub_823F1290(ctx, base);
	// addi r3,r1,14303
	ctx.r3.s64 = ctx.r1.s64 + 14303;
	// addi r10,r1,15471
	ctx.r10.s64 = ctx.r1.s64 + 15471;
	// rlwinm r11,r3,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFF80;
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// rlwinm r5,r10,0,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// addi r6,r11,8
	ctx.r6.s64 = r11.s64 + 8;
	// addi r4,r1,4640
	ctx.r4.s64 = ctx.r1.s64 + 4640;
	// stw r5,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r5.u32);
	// addi r3,r3,14224
	ctx.r3.s64 = ctx.r3.s64 + 14224;
	// stw r6,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r6.u32);
	// bl 0x823f1408
	ctx.lr = 0x823F1B18;
	sub_823F1408(ctx, base);
	// addis r3,r30,1
	ctx.r3.s64 = r30.s64 + 65536;
	// addi r5,r1,7744
	ctx.r5.s64 = ctx.r1.s64 + 7744;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r3,136
	ctx.r3.s64 = ctx.r3.s64 + 136;
	// bl 0x823f0408
	ctx.lr = 0x823F1B2C;
	sub_823F0408(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// li r6,256
	ctx.r6.s64 = 256;
	// addi r5,r1,9920
	ctx.r5.s64 = ctx.r1.s64 + 9920;
	// addi r4,r1,7744
	ctx.r4.s64 = ctx.r1.s64 + 7744;
	// addi r3,r3,200
	ctx.r3.s64 = ctx.r3.s64 + 200;
	// bl 0x823f0a58
	ctx.lr = 0x823F1B44;
	sub_823F0A58(ctx, base);
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,4640
	ctx.r6.s64 = ctx.r1.s64 + 4640;
	// addi r5,r1,2560
	ctx.r5.s64 = ctx.r1.s64 + 2560;
	// addi r4,r1,9920
	ctx.r4.s64 = ctx.r1.s64 + 9920;
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// addi r3,r3,18360
	ctx.r3.s64 = ctx.r3.s64 + 18360;
	// bl 0x823f0b68
	ctx.lr = 0x823F1B60;
	sub_823F0B68(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// addi r4,r1,2560
	ctx.r4.s64 = ctx.r1.s64 + 2560;
	// addi r3,r3,20452
	ctx.r3.s64 = ctx.r3.s64 + 20452;
	// bl 0x823f0c30
	ctx.lr = 0x823F1B70;
	sub_823F0C30(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,13136
	ctx.r6.s64 = ctx.r1.s64 + 13136;
	// addi r5,r1,1520
	ctx.r5.s64 = ctx.r1.s64 + 1520;
	// addi r4,r1,2560
	ctx.r4.s64 = ctx.r1.s64 + 2560;
	// addi r3,r3,20988
	ctx.r3.s64 = ctx.r3.s64 + 20988;
	// bl 0x823f0ed8
	ctx.lr = 0x823F1B8C;
	sub_823F0ED8(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// addi r4,r1,1520
	ctx.r4.s64 = ctx.r1.s64 + 1520;
	// addi r3,r3,29224
	ctx.r3.s64 = ctx.r3.s64 + 29224;
	// bl 0x823f0fa0
	ctx.lr = 0x823F1B9C;
	sub_823F0FA0(ctx, base);
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// addi r5,r1,3600
	ctx.r5.s64 = ctx.r1.s64 + 3600;
	// addi r4,r1,1520
	ctx.r4.s64 = ctx.r1.s64 + 1520;
	// addi r3,r3,30272
	ctx.r3.s64 = ctx.r3.s64 + 30272;
	// bl 0x823f1290
	ctx.lr = 0x823F1BB0;
	sub_823F1290(ctx, base);
	// addi r9,r1,7871
	ctx.r9.s64 = ctx.r1.s64 + 7871;
	// addi r8,r1,10047
	ctx.r8.s64 = ctx.r1.s64 + 10047;
	// rlwinm r11,r9,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// addis r3,r30,2
	ctx.r3.s64 = r30.s64 + 131072;
	// rlwinm r5,r8,0,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// addi r6,r11,8
	ctx.r6.s64 = r11.s64 + 8;
	// addi r4,r1,3600
	ctx.r4.s64 = ctx.r1.s64 + 3600;
	// stw r5,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r5.u32);
	// addi r3,r3,32344
	ctx.r3.s64 = ctx.r3.s64 + 32344;
	// stw r6,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r6.u32);
	// stw r5,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r5.u32);
	// bl 0x823f1408
	ctx.lr = 0x823F1BE0;
	sub_823F1408(ctx, base);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// lis r6,2
	ctx.r6.s64 = 131072;
	// lfs f0,96(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 96);
	f0.f64 = double(temp.f32);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// ori r3,r7,18352
	ctx.r3.u64 = ctx.r7.u64 | 18352;
	// ori r11,r6,236
	r11.u64 = ctx.r6.u64 | 236;
	// ori r10,r5,18356
	ctx.r10.u64 = ctx.r5.u64 | 18356;
	// ori r9,r4,232
	ctx.r9.u64 = ctx.r4.u64 | 232;
	// addi r8,r1,2560
	ctx.r8.s64 = ctx.r1.s64 + 2560;
	// lfsx f13,r30,r3
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r3.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,6704
	ctx.r7.s64 = ctx.r1.s64 + 6704;
	// lfsx f12,r30,r11
	temp.u32 = PPC_LOAD_U32(r30.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,1520
	ctx.r6.s64 = ctx.r1.s64 + 1520;
	// lfsx f11,r30,r10
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// lfsx f10,r30,r9
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,4640
	ctx.r4.s64 = ctx.r1.s64 + 4640;
	// addi r3,r1,2564
	ctx.r3.s64 = ctx.r1.s64 + 2564;
	// addi r11,r1,6708
	r11.s64 = ctx.r1.s64 + 6708;
	// addi r10,r1,1524
	ctx.r10.s64 = ctx.r1.s64 + 1524;
	// addi r9,r1,484
	ctx.r9.s64 = ctx.r1.s64 + 484;
	// subf r8,r31,r8
	ctx.r8.s64 = ctx.r8.s64 - r31.s64;
	// subf r7,r31,r7
	ctx.r7.s64 = ctx.r7.s64 - r31.s64;
	// subf r6,r31,r6
	ctx.r6.s64 = ctx.r6.s64 - r31.s64;
	// stw r8,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// addi r30,r1,4644
	r30.s64 = ctx.r1.s64 + 4644;
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// addi r29,r1,2568
	r29.s64 = ctx.r1.s64 + 2568;
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// addi r28,r31,4
	r28.s64 = r31.s64 + 4;
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// subf r4,r31,r4
	ctx.r4.s64 = ctx.r4.s64 - r31.s64;
	// stw r28,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r28.u32);
	// subf r3,r31,r3
	ctx.r3.s64 = ctx.r3.s64 - r31.s64;
	// stw r5,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// stw r4,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r4.u32);
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - r31.s64;
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - r31.s64;
	// stw r11,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r11.u32);
	// subf r8,r31,r30
	ctx.r8.s64 = r30.s64 - r31.s64;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// subf r7,r31,r29
	ctx.r7.s64 = r29.s64 - r31.s64;
	// stw r9,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r9.u32);
	// addi r6,r1,6712
	ctx.r6.s64 = ctx.r1.s64 + 6712;
	// stw r7,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r7.u32);
	// addi r7,r1,6720
	ctx.r7.s64 = ctx.r1.s64 + 6720;
	// addi r9,r1,1532
	ctx.r9.s64 = ctx.r1.s64 + 1532;
	// stw r8,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r8.u32);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r30,r1,1536
	r30.s64 = ctx.r1.s64 + 1536;
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - r31.s64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// addi r7,r1,496
	ctx.r7.s64 = ctx.r1.s64 + 496;
	// addi r28,r1,4652
	r28.s64 = ctx.r1.s64 + 4652;
	// stw r9,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r9.u32);
	// addi r30,r1,2576
	r30.s64 = ctx.r1.s64 + 2576;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r8,r1,492
	ctx.r8.s64 = ctx.r1.s64 + 492;
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r9,r31,r28
	ctx.r9.s64 = r28.s64 - r31.s64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// subf r8,r31,r8
	ctx.r8.s64 = ctx.r8.s64 - r31.s64;
	// rotlwi r30,r30,0
	r30.u64 = __builtin_rotateleft32(r30.u32, 0);
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// addi r5,r1,1528
	ctx.r5.s64 = ctx.r1.s64 + 1528;
	// stw r8,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r8.u32);
	// subf r9,r31,r27
	ctx.r9.s64 = r27.s64 - r31.s64;
	// addi r4,r1,488
	ctx.r4.s64 = ctx.r1.s64 + 488;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r3,r1,4648
	ctx.r3.s64 = ctx.r1.s64 + 4648;
	// subf r8,r31,r30
	ctx.r8.s64 = r30.s64 - r31.s64;
	// addi r11,r1,2572
	r11.s64 = ctx.r1.s64 + 2572;
	// addi r10,r1,6716
	ctx.r10.s64 = ctx.r1.s64 + 6716;
	// stw r8,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// subf r6,r31,r6
	ctx.r6.s64 = ctx.r6.s64 - r31.s64;
	// subf r5,r31,r5
	ctx.r5.s64 = ctx.r5.s64 - r31.s64;
	// subf r4,r31,r4
	ctx.r4.s64 = ctx.r4.s64 - r31.s64;
	// stw r6,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r6.u32);
	// subf r3,r31,r3
	ctx.r3.s64 = ctx.r3.s64 - r31.s64;
	// stw r5,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// subf r30,r31,r29
	r30.s64 = r29.s64 - r31.s64;
	// stw r4,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r4.u32);
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// stw r3,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r3.u32);
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - r31.s64;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// addi r9,r1,3616
	ctx.r9.s64 = ctx.r1.s64 + 3616;
	// stw r11,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r11.u32);
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r10,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r10.u32);
	// addi r8,r1,5696
	ctx.r8.s64 = ctx.r1.s64 + 5696;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r6,r1,4656
	ctx.r6.s64 = ctx.r1.s64 + 4656;
	// addi r5,r1,2580
	ctx.r5.s64 = ctx.r1.s64 + 2580;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// addi r4,r1,6724
	ctx.r4.s64 = ctx.r1.s64 + 6724;
	// addi r3,r1,1540
	ctx.r3.s64 = ctx.r1.s64 + 1540;
	// addi r11,r1,500
	r11.s64 = ctx.r1.s64 + 500;
	// addi r10,r1,4660
	ctx.r10.s64 = ctx.r1.s64 + 4660;
	// addi r30,r1,5700
	r30.s64 = ctx.r1.s64 + 5700;
	// subf r9,r31,r7
	ctx.r9.s64 = ctx.r7.s64 - r31.s64;
	// subf r8,r31,r6
	ctx.r8.s64 = ctx.r6.s64 - r31.s64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// subf r7,r31,r5
	ctx.r7.s64 = ctx.r5.s64 - r31.s64;
	// subf r6,r31,r4
	ctx.r6.s64 = ctx.r4.s64 - r31.s64;
	// subf r5,r31,r3
	ctx.r5.s64 = ctx.r3.s64 - r31.s64;
	// addi r26,r1,2584
	r26.s64 = ctx.r1.s64 + 2584;
	// addi r25,r1,6728
	r25.s64 = ctx.r1.s64 + 6728;
	// addi r24,r1,1544
	r24.s64 = ctx.r1.s64 + 1544;
	// addi r23,r1,504
	r23.s64 = ctx.r1.s64 + 504;
	// addi r22,r1,4664
	r22.s64 = ctx.r1.s64 + 4664;
	// addi r21,r1,5680
	r21.s64 = ctx.r1.s64 + 5680;
	// addi r20,r1,3600
	r20.s64 = ctx.r1.s64 + 3600;
	// addi r19,r1,5684
	r19.s64 = ctx.r1.s64 + 5684;
	// addi r18,r1,3604
	r18.s64 = ctx.r1.s64 + 3604;
	// addi r17,r1,5688
	r17.s64 = ctx.r1.s64 + 5688;
	// addi r16,r1,3608
	r16.s64 = ctx.r1.s64 + 3608;
	// addi r15,r1,5692
	r15.s64 = ctx.r1.s64 + 5692;
	// addi r14,r1,3612
	r14.s64 = ctx.r1.s64 + 3612;
	// addi r29,r1,3620
	r29.s64 = ctx.r1.s64 + 3620;
	// addi r28,r1,5704
	r28.s64 = ctx.r1.s64 + 5704;
	// addi r27,r1,3624
	r27.s64 = ctx.r1.s64 + 3624;
	// subf r4,r31,r11
	ctx.r4.s64 = r11.s64 - r31.s64;
	// subf r3,r31,r10
	ctx.r3.s64 = ctx.r10.s64 - r31.s64;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r30,r31,r26
	r30.s64 = r26.s64 - r31.s64;
	// subf r26,r31,r22
	r26.s64 = r22.s64 - r31.s64;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// subf r10,r31,r11
	ctx.r10.s64 = r11.s64 - r31.s64;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r22,r31,r18
	r22.s64 = r18.s64 - r31.s64;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// lwz r18,100(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// subf r29,r31,r25
	r29.s64 = r25.s64 - r31.s64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// subf r25,r31,r21
	r25.s64 = r21.s64 - r31.s64;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// subf r27,r31,r23
	r27.s64 = r23.s64 - r31.s64;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
	// subf r28,r31,r24
	r28.s64 = r24.s64 - r31.s64;
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - r31.s64;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// subf r18,r31,r18
	r18.s64 = r18.s64 - r31.s64;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// subf r21,r31,r17
	r21.s64 = r17.s64 - r31.s64;
	// stw r18,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r18.u32);
	// subf r24,r31,r20
	r24.s64 = r20.s64 - r31.s64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// subf r23,r31,r19
	r23.s64 = r19.s64 - r31.s64;
	// lwz r11,156(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// subf r17,r31,r10
	r17.s64 = ctx.r10.s64 - r31.s64;
	// subf r20,r31,r16
	r20.s64 = r16.s64 - r31.s64;
	// subf r19,r31,r15
	r19.s64 = r15.s64 - r31.s64;
	// subf r18,r31,r14
	r18.s64 = r14.s64 - r31.s64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_823F1E6C:
	// lwz r31,136(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r16,r1,1520
	r16.s64 = ctx.r1.s64 + 1520;
	// lwz r15,120(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lfs f9,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lwz r14,128(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lfs f7,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// std r17,240(r1)
	PPC_STORE_U64(ctx.r1.u32 + 240, r17.u64);
	// lfsx f3,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f7,f12
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// lfsx f1,r15,r11
	temp.u32 = PPC_LOAD_U32(r15.u32 + r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f9,f3,f11
	ctx.f9.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// lfsx f8,r10,r16
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r16.u32);
	ctx.f8.f64 = double(temp.f32);
	// lwz r31,144(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r16,104(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// fmuls f7,f1,f11
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// lwz r15,116(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fmuls f1,f8,f11
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// lwz r17,164(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// lfsx f3,r14,r11
	temp.u32 = PPC_LOAD_U32(r14.u32 + r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// std r19,264(r1)
	PPC_STORE_U64(ctx.r1.u32 + 264, r19.u64);
	// fmuls f8,f3,f11
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// std r18,248(r1)
	PPC_STORE_U64(ctx.r1.u32 + 248, r18.u64);
	// addi r18,r1,480
	r18.s64 = ctx.r1.s64 + 480;
	// lwz r19,208(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// lfsx f31,r16,r11
	temp.u32 = PPC_LOAD_U32(r16.u32 + r11.u32);
	f31.f64 = double(temp.f32);
	// lfsx f3,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	ctx.f3.f64 = double(temp.f32);
	// lwz r31,172(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lfs f5,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// lwz r16,184(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lfsx f30,r15,r11
	temp.u32 = PPC_LOAD_U32(r15.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// addi r14,r1,2560
	r14.s64 = ctx.r1.s64 + 2560;
	// lfsx f29,r17,r11
	temp.u32 = PPC_LOAD_U32(r17.u32 + r11.u32);
	f29.f64 = double(temp.f32);
	// fmuls f5,f5,f12
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// fmadds f9,f30,f10,f9
	ctx.f9.f64 = double(float(f30.f64 * ctx.f10.f64 + ctx.f9.f64));
	// lfsx f30,r10,r18
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r18.u32);
	f30.f64 = double(temp.f32);
	// fmadds f4,f29,f13,f4
	ctx.f4.f64 = double(float(f29.f64 * ctx.f13.f64 + ctx.f4.f64));
	// lfsx f29,r19,r11
	temp.u32 = PPC_LOAD_U32(r19.u32 + r11.u32);
	f29.f64 = double(temp.f32);
	// std r21,296(r1)
	PPC_STORE_U64(ctx.r1.u32 + 296, r21.u64);
	// fmadds f3,f3,f13,f31
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f13.f64 + f31.f64));
	// lwz r21,188(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// fmadds f1,f30,f10,f1
	ctx.f1.f64 = double(float(f30.f64 * ctx.f10.f64 + ctx.f1.f64));
	// fmadds f7,f29,f10,f7
	ctx.f7.f64 = double(float(f29.f64 * ctx.f10.f64 + ctx.f7.f64));
	// lfsx f30,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// lfsx f29,r16,r11
	temp.u32 = PPC_LOAD_U32(r16.u32 + r11.u32);
	f29.f64 = double(temp.f32);
	// std r20,280(r1)
	PPC_STORE_U64(ctx.r1.u32 + 280, r20.u64);
	// lfsx f31,r10,r14
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r14.u32);
	f31.f64 = double(temp.f32);
	// lwz r31,180(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r16,192(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// addi r20,r1,6704
	r20.s64 = ctx.r1.s64 + 6704;
	// fmadds f6,f31,f13,f6
	ctx.f6.f64 = double(float(f31.f64 * ctx.f13.f64 + ctx.f6.f64));
	// lfsx f31,r21,r11
	temp.u32 = PPC_LOAD_U32(r21.u32 + r11.u32);
	f31.f64 = double(temp.f32);
	// fmadds f2,f31,f13,f2
	ctx.f2.f64 = double(float(f31.f64 * ctx.f13.f64 + ctx.f2.f64));
	// addi r14,r1,4640
	r14.s64 = ctx.r1.s64 + 4640;
	// fmadds f5,f29,f13,f5
	ctx.f5.f64 = double(float(f29.f64 * ctx.f13.f64 + ctx.f5.f64));
	// lwz r15,200(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lfsx f29,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	f29.f64 = double(temp.f32);
	// lwz r21,204(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lfsx f31,r10,r20
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r20.u32);
	f31.f64 = double(temp.f32);
	// lwz r20,196(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// lfsx f28,r16,r11
	temp.u32 = PPC_LOAD_U32(r16.u32 + r11.u32);
	f28.f64 = double(temp.f32);
	// lwz r19,212(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// lwz r31,168(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// fmadds f8,f30,f10,f8
	ctx.f8.f64 = double(float(f30.f64 * ctx.f10.f64 + ctx.f8.f64));
	// lwz r16,176(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lfs f30,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f30.f64 = double(temp.f32);
	// lfsx f27,r10,r14
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r14.u32);
	f27.f64 = double(temp.f32);
	// fmadds f3,f12,f30,f3
	ctx.f3.f64 = double(float(ctx.f12.f64 * f30.f64 + ctx.f3.f64));
	// lfsx f26,r15,r11
	temp.u32 = PPC_LOAD_U32(r15.u32 + r11.u32);
	f26.f64 = double(temp.f32);
	// fadds f9,f9,f29
	ctx.f9.f64 = double(float(ctx.f9.f64 + f29.f64));
	// fadds f6,f6,f31
	ctx.f6.f64 = double(float(ctx.f6.f64 + f31.f64));
	// lfsx f25,r21,r11
	temp.u32 = PPC_LOAD_U32(r21.u32 + r11.u32);
	f25.f64 = double(temp.f32);
	// fadds f4,f4,f28
	ctx.f4.f64 = double(float(ctx.f4.f64 + f28.f64));
	// lfsx f30,r20,r11
	temp.u32 = PPC_LOAD_U32(r20.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// lfsx f29,r19,r11
	temp.u32 = PPC_LOAD_U32(r19.u32 + r11.u32);
	f29.f64 = double(temp.f32);
	// addi r15,r1,5680
	r15.s64 = ctx.r1.s64 + 5680;
	// lfsx f31,r31,r11
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	f31.f64 = double(temp.f32);
	// fadds f1,f1,f27
	ctx.f1.f64 = double(float(ctx.f1.f64 + f27.f64));
	// lfsx f28,r16,r11
	temp.u32 = PPC_LOAD_U32(r16.u32 + r11.u32);
	f28.f64 = double(temp.f32);
	// lwz r16,92(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fadds f8,f8,f30
	ctx.f8.f64 = double(float(ctx.f8.f64 + f30.f64));
	// lfs f30,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f30.f64 = double(temp.f32);
	// fmuls f31,f31,f11
	f31.f64 = double(float(f31.f64 * ctx.f11.f64));
	// fmuls f30,f30,f12
	f30.f64 = double(float(f30.f64 * ctx.f12.f64));
	// lfsx f27,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	f27.f64 = double(temp.f32);
	// fadds f5,f5,f29
	ctx.f5.f64 = double(float(ctx.f5.f64 + f29.f64));
	// lfs f29,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f29.f64 = double(temp.f32);
	// fadds f7,f7,f26
	ctx.f7.f64 = double(float(ctx.f7.f64 + f26.f64));
	// lfs f26,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f26.f64 = double(temp.f32);
	// lfsx f24,r16,r11
	temp.u32 = PPC_LOAD_U32(r16.u32 + r11.u32);
	f24.f64 = double(temp.f32);
	// lwz r16,132(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// fmuls f29,f29,f12
	f29.f64 = double(float(f29.f64 * ctx.f12.f64));
	// lwz r14,140(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// fmuls f27,f27,f11
	f27.f64 = double(float(f27.f64 * ctx.f11.f64));
	// lwz r21,148(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// fadds f2,f2,f25
	ctx.f2.f64 = double(float(ctx.f2.f64 + f25.f64));
	// lfsx f25,r28,r11
	temp.u32 = PPC_LOAD_U32(r28.u32 + r11.u32);
	f25.f64 = double(temp.f32);
	// fmuls f26,f26,f12
	f26.f64 = double(float(f26.f64 * ctx.f12.f64));
	// lfsx f22,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f22.f64 = double(temp.f32);
	// lfsx f19,r16,r11
	temp.u32 = PPC_LOAD_U32(r16.u32 + r11.u32);
	f19.f64 = double(temp.f32);
	// fmuls f25,f25,f11
	f25.f64 = double(float(f25.f64 * ctx.f11.f64));
	// fmadds f31,f28,f10,f31
	f31.f64 = double(float(f28.f64 * ctx.f10.f64 + f31.f64));
	// lfsx f21,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	f21.f64 = double(temp.f32);
	// fmadds f30,f19,f13,f30
	f30.f64 = double(float(f19.f64 * ctx.f13.f64 + f30.f64));
	// lfsx f20,r30,r11
	temp.u32 = PPC_LOAD_U32(r30.u32 + r11.u32);
	f20.f64 = double(temp.f32);
	// fmuls f24,f24,f11
	f24.f64 = double(float(f24.f64 * ctx.f11.f64));
	// lfsx f23,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	f23.f64 = double(temp.f32);
	// lwz r20,80(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lfsx f28,r27,r11
	temp.u32 = PPC_LOAD_U32(r27.u32 + r11.u32);
	f28.f64 = double(temp.f32);
	// fmuls f6,f6,f0
	ctx.f6.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfsx f6,r10,r15
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + r15.u32, temp.u32);
	// fmadds f29,f22,f13,f29
	f29.f64 = double(float(f22.f64 * ctx.f13.f64 + f29.f64));
	// lfsx f22,r14,r11
	temp.u32 = PPC_LOAD_U32(r14.u32 + r11.u32);
	f22.f64 = double(temp.f32);
	// fmadds f27,f21,f10,f27
	f27.f64 = double(float(f21.f64 * ctx.f10.f64 + f27.f64));
	// lfsx f21,r21,r11
	temp.u32 = PPC_LOAD_U32(r21.u32 + r11.u32);
	f21.f64 = double(temp.f32);
	// lwz r21,112(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r31,r1,3600
	r31.s64 = ctx.r1.s64 + 3600;
	// fmadds f26,f20,f13,f26
	f26.f64 = double(float(f20.f64 * ctx.f13.f64 + f26.f64));
	// stw r20,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r20.u32);
	// fmadds f28,f28,f10,f25
	f28.f64 = double(float(f28.f64 * ctx.f10.f64 + f25.f64));
	// ld r20,280(r1)
	r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + 280);
	// fadds f31,f31,f22
	f31.f64 = double(float(f31.f64 + f22.f64));
	// ld r19,264(r1)
	r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + 264);
	// fadds f6,f30,f21
	ctx.f6.f64 = double(float(f30.f64 + f21.f64));
	// ld r18,248(r1)
	r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + 248);
	// fmadds f24,f23,f10,f24
	f24.f64 = double(float(f23.f64 * ctx.f10.f64 + f24.f64));
	// stw r21,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r21.u32);
	// ld r21,296(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + 296);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfsx f23,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	f23.f64 = double(temp.f32);
	// fmuls f3,f3,f0
	ctx.f3.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfsx f1,r10,r31
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// lfsx f25,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	f25.f64 = double(temp.f32);
	// fmuls f9,f4,f0
	ctx.f9.f64 = double(float(ctx.f4.f64 * f0.f64));
	// lfsx f19,r29,r11
	temp.u32 = PPC_LOAD_U32(r29.u32 + r11.u32);
	f19.f64 = double(temp.f32);
	// fadds f30,f29,f23
	f30.f64 = double(float(f29.f64 + f23.f64));
	// lfsx f20,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f20.f64 = double(temp.f32);
	// fmuls f4,f2,f0
	ctx.f4.f64 = double(float(ctx.f2.f64 * f0.f64));
	// lfsx f18,r26,r11
	temp.u32 = PPC_LOAD_U32(r26.u32 + r11.u32);
	f18.f64 = double(temp.f32);
	// fadds f29,f27,f25
	f29.f64 = double(float(f27.f64 + f25.f64));
	// stfsx f3,r25,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r25.u32 + r11.u32, temp.u32);
	// fadds f27,f26,f19
	f27.f64 = double(float(f26.f64 + f19.f64));
	// stfsx f1,r24,r11
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r24.u32 + r11.u32, temp.u32);
	// fmuls f7,f7,f0
	ctx.f7.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfsx f9,r23,r11
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r23.u32 + r11.u32, temp.u32);
	// fmuls f3,f8,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64));
	// lwz r16,84(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmuls f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 * f0.f64));
	// lwz r14,100(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stfsx f7,r22,r11
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r22.u32 + r11.u32, temp.u32);
	// fadds f26,f24,f20
	f26.f64 = double(float(f24.f64 + f20.f64));
	// stfsx f4,r21,r11
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r21.u32 + r11.u32, temp.u32);
	// fadds f28,f28,f18
	f28.f64 = double(float(f28.f64 + f18.f64));
	// stfsx f3,r20,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r20.u32 + r11.u32, temp.u32);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// stfsx f2,r19,r11
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r19.u32 + r11.u32, temp.u32);
	// fmuls f9,f6,f0
	ctx.f9.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfsx f1,r18,r11
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r18.u32 + r11.u32, temp.u32);
	// lwz r31,96(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// fmuls f8,f26,f0
	ctx.f8.f64 = double(float(f26.f64 * f0.f64));
	// fmuls f5,f27,f0
	ctx.f5.f64 = double(float(f27.f64 * f0.f64));
	// ld r17,240(r1)
	r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + 240);
	// fmuls f7,f30,f0
	ctx.f7.f64 = double(float(f30.f64 * f0.f64));
	// stfsx f7,r16,r11
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r16.u32 + r11.u32, temp.u32);
	// fmuls f6,f29,f0
	ctx.f6.f64 = double(float(f29.f64 * f0.f64));
	// stfsx f6,r14,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r14.u32 + r11.u32, temp.u32);
	// fmuls f4,f28,f0
	ctx.f4.f64 = double(float(f28.f64 * f0.f64));
	// cmpwi cr6,r10,1024
	cr6.compare<int32_t>(ctx.r10.s32, 1024, xer);
	// stfsx f8,r31,r11
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// lwz r31,108(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stfsx f9,r17,r11
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r17.u32 + r11.u32, temp.u32);
	// stfsx f5,r31,r11
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// lwz r31,88(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stfsx f4,r31,r11
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// blt cr6,0x823f1e6c
	if (cr6.lt) goto loc_823F1E6C;
	// lwz r11,17988(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 17988);
	// lis r10,2
	ctx.r10.s64 = 131072;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// addis r6,r11,3
	ctx.r6.s64 = r11.s64 + 196608;
	// ori r5,r10,38556
	ctx.r5.u64 = ctx.r10.u64 | 38556;
	// addi r6,r6,-26992
	ctx.r6.s64 = ctx.r6.s64 + -26992;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// ori r4,r9,40624
	ctx.r4.u64 = ctx.r9.u64 | 40624;
	// ori r3,r8,40656
	ctx.r3.u64 = ctx.r8.u64 | 40656;
	// ori r9,r7,40676
	ctx.r9.u64 = ctx.r7.u64 | 40676;
	// stw r4,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r4.u32);
	// stw r3,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// mr r31,r11
	r31.u64 = r11.u64;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// addis r10,r11,3
	ctx.r10.s64 = r11.s64 + 196608;
	// addis r8,r11,3
	ctx.r8.s64 = r11.s64 + 196608;
	// addi r10,r10,-29064
	ctx.r10.s64 = ctx.r10.s64 + -29064;
	// addis r5,r31,3
	ctx.r5.s64 = r31.s64 + 196608;
	// addi r8,r8,-24920
	ctx.r8.s64 = ctx.r8.s64 + -24920;
	// stw r10,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r10.u32);
	// addis r4,r31,3
	ctx.r4.s64 = r31.s64 + 196608;
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// stw r8,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r8.u32);
	// addi r5,r5,-29052
	ctx.r5.s64 = ctx.r5.s64 + -29052;
	// addis r10,r31,3
	ctx.r10.s64 = r31.s64 + 196608;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// addi r4,r4,-24828
	ctx.r4.s64 = ctx.r4.s64 + -24828;
	// stw r5,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r5.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addis r8,r31,3
	ctx.r8.s64 = r31.s64 + 196608;
	// stw r4,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r4.u32);
	// addi r10,r10,-8384
	ctx.r10.s64 = ctx.r10.s64 + -8384;
	// stw r6,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// addis r5,r31,3
	ctx.r5.s64 = r31.s64 + 196608;
	// addi r8,r8,-4244
	ctx.r8.s64 = ctx.r8.s64 + -4244;
	// stw r10,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// stw r8,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r8.u32);
	// addis r9,r31,3
	ctx.r9.s64 = r31.s64 + 196608;
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addis r7,r31,3
	ctx.r7.s64 = r31.s64 + 196608;
	// addis r6,r31,3
	ctx.r6.s64 = r31.s64 + 196608;
	// addis r4,r31,3
	ctx.r4.s64 = r31.s64 + 196608;
	// addi r5,r5,-4160
	ctx.r5.s64 = ctx.r5.s64 + -4160;
	// addi r3,r3,-8412
	ctx.r3.s64 = ctx.r3.s64 + -8412;
	// addi r11,r11,-24816
	r11.s64 = r11.s64 + -24816;
	// stw r5,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r5.u32);
	// addi r9,r9,-6312
	ctx.r9.s64 = ctx.r9.s64 + -6312;
	// stw r3,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// addi r7,r7,-4212
	ctx.r7.s64 = ctx.r7.s64 + -4212;
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r11.u32);
	// addi r6,r6,-4192
	ctx.r6.s64 = ctx.r6.s64 + -4192;
	// stw r9,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r9.u32);
	// addi r4,r4,12256
	ctx.r4.s64 = ctx.r4.s64 + 12256;
	// stw r7,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r7.u32);
	// addi r5,r10,16
	ctx.r5.s64 = ctx.r10.s64 + 16;
	// stw r6,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r6.u32);
	// add r10,r31,r8
	ctx.r10.u64 = r31.u64 + ctx.r8.u64;
	// stw r4,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r4.u32);
	// lwz r6,148(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// addis r3,r31,3
	ctx.r3.s64 = r31.s64 + 196608;
	// lwz r4,140(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// addis r11,r31,3
	r11.s64 = r31.s64 + 196608;
	// lwz r8,132(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addis r9,r31,3
	ctx.r9.s64 = r31.s64 + 196608;
	// addis r7,r31,3
	ctx.r7.s64 = r31.s64 + 196608;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r3,r3,-4148
	ctx.r3.s64 = ctx.r3.s64 + -4148;
	// stw r10,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r10.u32);
	// addi r11,r11,12284
	r11.s64 = r11.s64 + 12284;
	// addi r9,r9,20504
	ctx.r9.s64 = ctx.r9.s64 + 20504;
	// addi r7,r7,28720
	ctx.r7.s64 = ctx.r7.s64 + 28720;
	// add r6,r31,r6
	ctx.r6.u64 = r31.u64 + ctx.r6.u64;
	// add r4,r31,r4
	ctx.r4.u64 = r31.u64 + ctx.r4.u64;
	// add r8,r31,r8
	ctx.r8.u64 = r31.u64 + ctx.r8.u64;
	// addis r5,r31,4
	ctx.r5.s64 = r31.s64 + 262144;
	// addis r28,r31,4
	r28.s64 = r31.s64 + 262144;
	// stw r6,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r6.u32);
	// stw r4,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r4.u32);
	// addis r10,r31,4
	ctx.r10.s64 = r31.s64 + 262144;
	// addi r28,r28,16616
	r28.s64 = r28.s64 + 16616;
	// stw r9,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r9.u32);
	// addis r6,r31,4
	ctx.r6.s64 = r31.s64 + 262144;
	// stw r3,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// addis r4,r31,4
	ctx.r4.s64 = r31.s64 + 262144;
	// stw r28,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, r28.u32);
	// addis r9,r31,3
	ctx.r9.s64 = r31.s64 + 196608;
	// stw r7,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r7.u32);
	// addi r5,r5,-28600
	ctx.r5.s64 = ctx.r5.s64 + -28600;
	// lwz r24,216(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// addi r9,r9,-6324
	ctx.r9.s64 = ctx.r9.s64 + -6324;
	// stw r8,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r8.u32);
	// addi r10,r10,-24484
	ctx.r10.s64 = ctx.r10.s64 + -24484;
	// stw r5,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r5.u32);
	// addi r6,r6,-8072
	ctx.r6.s64 = ctx.r6.s64 + -8072;
	// stw r9,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r9.u32);
	// addi r4,r4,-8036
	ctx.r4.s64 = ctx.r4.s64 + -8036;
	// stw r10,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r10.u32);
	// addis r30,r31,4
	r30.s64 = r31.s64 + 262144;
	// stw r6,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r6.u32);
	// addis r27,r31,4
	r27.s64 = r31.s64 + 262144;
	// stw r4,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r4.u32);
	// addis r26,r31,5
	r26.s64 = r31.s64 + 327680;
	// stw r11,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, r11.u32);
	// addis r25,r31,4
	r25.s64 = r31.s64 + 262144;
	// lwz r11,232(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// addis r23,r31,4
	r23.s64 = r31.s64 + 262144;
	// lwz r8,220(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// addis r28,r31,3
	r28.s64 = r31.s64 + 196608;
	// lwz r29,228(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// addi r30,r30,8400
	r30.s64 = r30.s64 + 8400;
	// addi r27,r27,20732
	r27.s64 = r27.s64 + 20732;
	// addi r26,r26,-28392
	r26.s64 = r26.s64 + -28392;
	// stw r30,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, r30.u32);
	// addi r25,r25,20744
	r25.s64 = r25.s64 + 20744;
	// stw r27,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r27.u32);
	// addi r23,r23,-24472
	r23.s64 = r23.s64 + -24472;
	// stw r26,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r26.u32);
	// addi r28,r28,-8420
	r28.s64 = r28.s64 + -8420;
	// stw r25,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, r25.u32);
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// stw r23,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, r23.u32);
	// addis r3,r31,4
	ctx.r3.s64 = r31.s64 + 262144;
	// stw r28,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, r28.u32);
	// addis r10,r31,3
	ctx.r10.s64 = r31.s64 + 196608;
	// addis r6,r31,3
	ctx.r6.s64 = r31.s64 + 196608;
	// addis r5,r31,3
	ctx.r5.s64 = r31.s64 + 196608;
	// addis r9,r31,3
	ctx.r9.s64 = r31.s64 + 196608;
	// addis r4,r31,4
	ctx.r4.s64 = r31.s64 + 262144;
	// addis r22,r31,3
	r22.s64 = r31.s64 + 196608;
	// addi r3,r3,184
	ctx.r3.s64 = ctx.r3.s64 + 184;
	// addi r10,r10,-8396
	ctx.r10.s64 = ctx.r10.s64 + -8396;
	// addi r6,r6,12272
	ctx.r6.s64 = ctx.r6.s64 + 12272;
	// stw r3,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// addi r5,r5,28708
	ctx.r5.s64 = ctx.r5.s64 + 28708;
	// lwz r3,224(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// addi r9,r9,20488
	ctx.r9.s64 = ctx.r9.s64 + 20488;
	// stw r10,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r10.u32);
	// addi r4,r4,-28612
	ctx.r4.s64 = ctx.r4.s64 + -28612;
	// stw r6,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r6.u32);
	// addis r30,r31,3
	r30.s64 = r31.s64 + 196608;
	// stw r9,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r9.u32);
	// addi r22,r22,-4252
	r22.s64 = r22.s64 + -4252;
	// stw r5,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r5.u32);
	// addis r27,r31,3
	r27.s64 = r31.s64 + 196608;
	// stw r4,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r4.u32);
	// addis r26,r31,4
	r26.s64 = r31.s64 + 262144;
	// stw r22,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, r22.u32);
	// addis r28,r31,4
	r28.s64 = r31.s64 + 262144;
	// addis r25,r31,4
	r25.s64 = r31.s64 + 262144;
	// addis r23,r31,4
	r23.s64 = r31.s64 + 262144;
	// addi r30,r30,-24836
	r30.s64 = r30.s64 + -24836;
	// addi r27,r27,-4168
	r27.s64 = r27.s64 + -4168;
	// addi r26,r26,-24492
	r26.s64 = r26.s64 + -24492;
	// addi r28,r28,168
	r28.s64 = r28.s64 + 168;
	// addi r25,r25,-8076
	r25.s64 = r25.s64 + -8076;
	// addi r23,r23,-8048
	r23.s64 = r23.s64 + -8048;
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r28.u32);
	// addis r28,r31,4
	r28.s64 = r31.s64 + 262144;
	// stw r25,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, r25.u32);
	// addis r25,r31,3
	r25.s64 = r31.s64 + 196608;
	// addi r28,r28,8388
	r28.s64 = r28.s64 + 8388;
	// stw r23,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r23.u32);
	// addi r25,r25,12248
	r25.s64 = r25.s64 + 12248;
	// lwz r18,156(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// addis r28,r31,4
	r28.s64 = r31.s64 + 262144;
	// stw r25,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, r25.u32);
	// addis r25,r31,5
	r25.s64 = r31.s64 + 327680;
	// addi r28,r28,20724
	r28.s64 = r28.s64 + 20724;
	// addi r25,r25,-28396
	r25.s64 = r25.s64 + -28396;
	// stw r28,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r28.u32);
	// li r28,0
	r28.s64 = 0;
	// stw r25,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r25.u32);
	// addis r23,r31,4
	r23.s64 = r31.s64 + 262144;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// subf r28,r3,r8
	r28.s64 = ctx.r8.s64 - ctx.r3.s64;
	// subf r25,r3,r24
	r25.s64 = r24.s64 - ctx.r3.s64;
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// subf r3,r3,r29
	ctx.r3.s64 = r29.s64 - ctx.r3.s64;
	// stw r25,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r25.u32);
	// addi r23,r23,16604
	r23.s64 = r23.s64 + 16604;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r3,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r3.u32);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// stw r23,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r23.u32);
	// lis r23,-32252
	r23.s64 = -2113667072;
	// li r20,256
	r20.s64 = 256;
	// addis r29,r31,3
	r29.s64 = r31.s64 + 196608;
	// addis r28,r31,3
	r28.s64 = r31.s64 + 196608;
	// stw r20,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r20.u32);
	// addis r22,r31,3
	r22.s64 = r31.s64 + 196608;
	// lfs f0,-17876(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -17876);
	f0.f64 = double(temp.f32);
	// addis r21,r31,3
	r21.s64 = r31.s64 + 196608;
	// lfs f13,3732(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// addi r25,r9,20
	r25.s64 = ctx.r9.s64 + 20;
	// lwz r23,92(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stfs f0,400(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// addi r29,r29,-24896
	r29.s64 = r29.s64 + -24896;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r28,r28,-4228
	r28.s64 = r28.s64 + -4228;
	// addi r22,r22,-24864
	r22.s64 = r22.s64 + -24864;
	// addi r21,r21,-4196
	r21.s64 = r21.s64 + -4196;
	// addi r11,r30,24
	r11.s64 = r30.s64 + 24;
	// addi r10,r27,24
	ctx.r10.s64 = r27.s64 + 24;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// addi r9,r26,24
	ctx.r9.s64 = r26.s64 + 24;
	// b 0x823f24a8
	goto loc_823F24A8;
loc_823F24A4:
	// lwz r20,144(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
loc_823F24A8:
	// lwz r19,116(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// clrlwi r19,r19,27
	r19.u64 = r19.u32 & 0x1F;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// bne cr6,0x823f24c8
	if (!cr6.eq) goto loc_823F24C8;
	// lwz r19,160(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// dcbt r20,r19
	// lwz r19,152(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// dcbt r20,r19
loc_823F24C8:
	// lfs f0,8(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r18.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r19,0(r23)
	r19.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwz r18,0(r18)
	r18.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// addi r17,r1,5680
	r17.s64 = ctx.r1.s64 + 5680;
	// mr r20,r19
	r20.u64 = r19.u64;
	// std r31,384(r1)
	PPC_STORE_U64(ctx.r1.u32 + 384, r31.u64);
	// subf r19,r18,r19
	r19.s64 = r19.s64 - r18.s64;
	// std r26,448(r1)
	PPC_STORE_U64(ctx.r1.u32 + 448, r26.u64);
	// addi r15,r20,2
	r15.s64 = r20.s64 + 2;
	// lwz r14,216(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// clrlwi r20,r19,23
	r20.u64 = r19.u32 & 0x1FF;
	// lwz r19,148(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r31,140(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// addi r16,r1,3600
	r16.s64 = ctx.r1.s64 + 3600;
	// addi r20,r20,2
	r20.s64 = r20.s64 + 2;
	// lwz r26,132(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// std r25,440(r1)
	PPC_STORE_U64(ctx.r1.u32 + 440, r25.u64);
	// rlwinm r15,r15,2,0,29
	r15.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 2) & 0xFFFFFFFC;
	// std r9,456(r1)
	PPC_STORE_U64(ctx.r1.u32 + 456, ctx.r9.u64);
	// rlwinm r20,r20,2,0,29
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r18,100(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f8,0(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r25,168(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// lfs f7,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r9,212(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// lfs f6,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// std r4,464(r1)
	PPC_STORE_U64(ctx.r1.u32 + 464, ctx.r4.u64);
	// lfsx f3,r20,r23
	temp.u32 = PPC_LOAD_U32(r20.u32 + r23.u32);
	ctx.f3.f64 = double(temp.f32);
	// lwz r14,196(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// lfsx f13,r24,r18
	temp.u32 = PPC_LOAD_U32(r24.u32 + r18.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwz r19,204(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r31,200(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lfs f11,0(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r26,180(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfs f1,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,184(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// fmadds f2,f0,f3,f13
	ctx.f2.f64 = double(float(f0.f64 * ctx.f3.f64 + ctx.f13.f64));
	// std r5,432(r1)
	PPC_STORE_U64(ctx.r1.u32 + 432, ctx.r5.u64);
	// lfs f0,0(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r18,176(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lfs f31,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	f31.f64 = double(temp.f32);
	// lwz r20,192(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r25,188(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lfs f29,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f29.f64 = double(temp.f32);
	// lwz r9,208(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// lfs f28,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f28.f64 = double(temp.f32);
	// lwz r5,164(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// lfs f12,0(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lwz r14,304(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	// lwz r19,340(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// lfs f30,0(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 0);
	f30.f64 = double(temp.f32);
	// lwz r31,344(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 344);
	// lfs f27,0(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	f27.f64 = double(temp.f32);
	// lwz r26,352(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// lfs f10,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lwz r4,272(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// lfs f26,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f26.f64 = double(temp.f32);
	// lwz r18,172(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lfs f25,0(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	f25.f64 = double(temp.f32);
	// lwz r20,256(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// lfs f24,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	f24.f64 = double(temp.f32);
	// lwz r25,360(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 360);
	// add r18,r18,r24
	r18.u64 = r18.u64 + r24.u64;
	// lwz r9,288(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// lfs f23,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f23.f64 = double(temp.f32);
	// lwz r5,368(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// lfs f21,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	f21.f64 = double(temp.f32);
	// lfs f9,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fadds f5,f2,f8
	ctx.f5.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// lwz r14,236(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// lfs f22,0(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 0);
	f22.f64 = double(temp.f32);
	// lwz r19,376(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 376);
	// lfs f20,0(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	f20.f64 = double(temp.f32);
	// lwz r31,312(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 312);
	// lfs f19,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f19.f64 = double(temp.f32);
	// lfs f2,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// addi r26,r1,12096
	r26.s64 = ctx.r1.s64 + 12096;
	// addi r4,r1,13136
	ctx.r4.s64 = ctx.r1.s64 + 13136;
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r18.u32);
	// lfs f18,0(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	f18.f64 = double(temp.f32);
	// lwz r18,156(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r20,392(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 392);
	// lfs f16,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f16.f64 = double(temp.f32);
	// lwz r14,320(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	// stfs f7,404(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f16,240(r1)
	temp.f32 = float(f16.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// fadds f7,f5,f4
	ctx.f7.f64 = double(float(ctx.f5.f64 + ctx.f4.f64));
	// lfs f17,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	f17.f64 = double(temp.f32);
	// fsubs f4,f8,f4
	ctx.f4.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// lfs f16,4(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + 4);
	f16.f64 = double(temp.f32);
	// lwz r19,104(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f15,0(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 0);
	f15.f64 = double(temp.f32);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f14,0(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	f14.f64 = double(temp.f32);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfsx f7,r15,r23
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r15.u32 + r23.u32, temp.u32);
	// lwz r20,0(r23)
	r20.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r15,r20,1
	r15.s64 = r20.s64 + 1;
	// lwz r20,136(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lfsx f8,r20,r26
	temp.u32 = PPC_LOAD_U32(r20.u32 + r26.u32);
	ctx.f8.f64 = double(temp.f32);
	// clrlwi r15,r15,23
	r15.u64 = r15.u32 & 0x1FF;
	// stfs f8,92(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmadds f3,f16,f7,f3
	ctx.f3.f64 = double(float(f16.f64 * ctx.f7.f64 + ctx.f3.f64));
	// lfsx f8,r20,r4
	temp.u32 = PPC_LOAD_U32(r20.u32 + ctx.r4.u32);
	ctx.f8.f64 = double(temp.f32);
	// lwz r20,108(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stw r15,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r15.u32);
	// stfs f3,12(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r18.u32 + 12, temp.u32);
	// lfsx f7,r19,r17
	temp.u32 = PPC_LOAD_U32(r19.u32 + r17.u32);
	ctx.f7.f64 = double(temp.f32);
	// lwz r15,0(r3)
	r15.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfsx f3,r19,r16
	temp.u32 = PPC_LOAD_U32(r19.u32 + r16.u32);
	ctx.f3.f64 = double(temp.f32);
	// fadds f1,f7,f1
	ctx.f1.f64 = double(float(ctx.f7.f64 + ctx.f1.f64));
	// stfs f17,372(r1)
	temp.f32 = float(f17.f64);
	PPC_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// fadds f7,f3,f0
	ctx.f7.f64 = double(float(ctx.f3.f64 + f0.f64));
	// lwz r19,0(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lfs f16,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	f16.f64 = double(temp.f32);
	// lfs f17,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	f17.f64 = double(temp.f32);
	// stfs f15,248(r1)
	temp.f32 = float(f15.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f6,124(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f6,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f3.f64 = double(temp.f32);
	// fadds f0,f3,f13
	f0.f64 = double(float(ctx.f3.f64 + ctx.f13.f64));
	// subf r19,r19,r15
	r19.s64 = r15.s64 - r19.s64;
	// fadds f1,f1,f12
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f12.f64));
	// mr r17,r15
	r17.u64 = r15.u64;
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// clrlwi r19,r19,23
	r19.u64 = r19.u32 & 0x1FF;
	// lfs f5,400(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f5.f64 = double(temp.f32);
	// addi r17,r17,2
	r17.s64 = r17.s64 + 2;
	// lfsx f0,r9,r24
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r24.u32);
	f0.f64 = double(temp.f32);
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// lfs f13,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f14,296(r1)
	temp.f32 = float(f14.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f28,f28,f5
	f28.f64 = double(float(f28.f64 * ctx.f5.f64));
	// lfsx f15,r19,r3
	temp.u32 = PPC_LOAD_U32(r19.u32 + ctx.r3.u32);
	f15.f64 = double(temp.f32);
	// fmadds f31,f16,f15,f31
	f31.f64 = double(float(f16.f64 * f15.f64 + f31.f64));
	// stfsx f31,r17,r3
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r17.u32 + ctx.r3.u32, temp.u32);
	// lwz r19,0(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// fmadds f31,f31,f17,f15
	f31.f64 = double(float(f31.f64 * f17.f64 + f15.f64));
	// fadds f17,f7,f11
	f17.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// clrlwi r19,r19,23
	r19.u64 = r19.u32 & 0x1FF;
	// fmuls f7,f1,f6
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f6.f64));
	// stw r19,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r19.u32);
	// stfs f31,12(r20)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r20.u32 + 12, temp.u32);
	// lwz r20,328(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	// addi r19,r20,12
	r19.s64 = r20.s64 + 12;
	// lfs f31,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	f31.f64 = double(temp.f32);
	// lwz r17,0(r20)
	r17.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lfs f16,16(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 16);
	f16.f64 = double(temp.f32);
	// clrlwi r17,r17,31
	r17.u64 = r17.u32 & 0x1;
	// fmuls f6,f17,f6
	ctx.f6.f64 = double(float(f17.f64 * ctx.f6.f64));
	// lfs f17,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f17.f64 = double(temp.f32);
	// addi r17,r17,4
	r17.s64 = r17.s64 + 4;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r20
	temp.u32 = PPC_LOAD_U32(r17.u32 + r20.u32);
	ctx.f1.f64 = double(temp.f32);
	// stfs f16,20(r20)
	temp.f32 = float(f16.f64);
	PPC_STORE_U32(r20.u32 + 20, temp.u32);
	// stfs f17,16(r20)
	temp.f32 = float(f17.f64);
	PPC_STORE_U32(r20.u32 + 16, temp.u32);
	// fmadds f1,f1,f31,f17
	ctx.f1.f64 = double(float(ctx.f1.f64 * f31.f64 + f17.f64));
	// stfs f1,8(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 8, temp.u32);
	// lwz r20,0(r29)
	r20.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f1,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// clrlwi r20,r20,31
	r20.u64 = r20.u32 & 0x1;
	// lfs f31,12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	f31.f64 = double(temp.f32);
	// addi r17,r20,6
	r17.s64 = r20.s64 + 6;
	// lfs f17,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f17.f64 = double(temp.f32);
	// addi r20,r29,20
	r20.s64 = r29.s64 + 20;
	// lfs f16,24(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 24);
	f16.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r20,r22,16
	r20.s64 = r22.s64 + 16;
	// lfs f15,0(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	f15.f64 = double(temp.f32);
	// fadds f25,f8,f25
	f25.f64 = double(float(ctx.f8.f64 + f25.f64));
	// lfsx f14,r17,r29
	temp.u32 = PPC_LOAD_U32(r17.u32 + r29.u32);
	f14.f64 = double(temp.f32);
	// fmadds f1,f1,f14,f30
	ctx.f1.f64 = double(float(ctx.f1.f64 * f14.f64 + f30.f64));
	// fmuls f31,f31,f14
	f31.f64 = double(float(f31.f64 * f14.f64));
	// stfs f1,24(r29)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 24, temp.u32);
	// stfs f16,28(r29)
	temp.f32 = float(f16.f64);
	PPC_STORE_U32(r29.u32 + 28, temp.u32);
	// fmadds f1,f1,f17,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 * f17.f64 + f31.f64));
	// stfs f1,16(r29)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 16, temp.u32);
	// lfs f1,12(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lwz r17,0(r22)
	r17.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lfs f31,20(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 20);
	f31.f64 = double(temp.f32);
	// clrlwi r19,r17,31
	r19.u64 = r17.u32 & 0x1;
	// addi r19,r19,5
	r19.s64 = r19.s64 + 5;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r19,r22
	temp.u32 = PPC_LOAD_U32(r19.u32 + r22.u32);
	f30.f64 = double(temp.f32);
	// fmadds f1,f30,f1,f29
	ctx.f1.f64 = double(float(f30.f64 * ctx.f1.f64 + f29.f64));
	// stfs f1,20(r22)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r22.u32 + 20, temp.u32);
	// stfs f31,24(r22)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r22.u32 + 24, temp.u32);
	// lfs f31,8(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 8);
	f31.f64 = double(temp.f32);
	// fmuls f1,f31,f1
	ctx.f1.f64 = double(float(f31.f64 * ctx.f1.f64));
	// stfs f1,4(r22)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r22.u32 + 4, temp.u32);
	// lwz r17,12(r30)
	r17.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lfs f1,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r19,0(r11)
	r19.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f31,16(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f31.f64 = double(temp.f32);
	// mr r16,r19
	r16.u64 = r19.u64;
	// lwz r15,0(r30)
	r15.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r16,r15,r16
	r16.s64 = r16.s64 - r15.s64;
	// subf r19,r17,r19
	r19.s64 = r19.s64 - r17.s64;
	// clrlwi r20,r16,20
	r20.u64 = r16.u32 & 0xFFF;
	// clrlwi r19,r19,20
	r19.u64 = r19.u32 & 0xFFF;
	// addi r20,r20,2
	r20.s64 = r20.s64 + 2;
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// rlwinm r20,r20,2,0,29
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r20,r11
	temp.u32 = PPC_LOAD_U32(r20.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// fmuls f1,f30,f1
	ctx.f1.f64 = double(float(f30.f64 * ctx.f1.f64));
	// lfsx f30,r19,r11
	temp.u32 = PPC_LOAD_U32(r19.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// fmuls f31,f30,f31
	f31.f64 = double(float(f30.f64 * f31.f64));
	// stfs f1,8(r30)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f31,20(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 20, temp.u32);
	// lwz r20,0(r11)
	r20.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r20,r20,2
	r20.s64 = r20.s64 + 2;
	// rlwinm r20,r20,2,0,29
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f28,r20,r11
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r20.u32 + r11.u32, temp.u32);
	// lwz r20,0(r11)
	r20.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r19,r20,1
	r19.s64 = r20.s64 + 1;
	// lwz r20,408(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 408);
	// clrlwi r19,r19,20
	r19.u64 = r19.u32 & 0xFFF;
	// stw r19,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r19.u32);
	// lfs f1,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r19,0(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// clrlwi r19,r19,31
	r19.u64 = r19.u32 & 0x1;
	// addi r19,r19,4
	r19.s64 = r19.s64 + 4;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r19,r20
	temp.u32 = PPC_LOAD_U32(r19.u32 + r20.u32);
	f31.f64 = double(temp.f32);
	// fmuls f1,f31,f1
	ctx.f1.f64 = double(float(f31.f64 * ctx.f1.f64));
	// stfs f1,8(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 8, temp.u32);
	// addi r20,r20,12
	r20.s64 = r20.s64 + 12;
	// lfs f1,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,8(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 8, temp.u32);
	// stfs f27,4(r20)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r20.u32 + 4, temp.u32);
	// lwz r20,336(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	// lwz r19,0(r8)
	r19.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r17,r19
	r17.u64 = r19.u64;
	// lwz r16,0(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lfs f1,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	f31.f64 = double(temp.f32);
	// subf r17,r16,r17
	r17.s64 = r17.s64 - r16.s64;
	// clrlwi r17,r17,23
	r17.u64 = r17.u32 & 0x1FF;
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// addi r17,r17,2
	r17.s64 = r17.s64 + 2;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r17,r8
	temp.u32 = PPC_LOAD_U32(r17.u32 + ctx.r8.u32);
	f30.f64 = double(temp.f32);
	// fmadds f4,f1,f30,f4
	ctx.f4.f64 = double(float(ctx.f1.f64 * f30.f64 + ctx.f4.f64));
	// fadds f1,f4,f15
	ctx.f1.f64 = double(float(ctx.f4.f64 + f15.f64));
	// stfsx f1,r19,r8
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r19.u32 + ctx.r8.u32, temp.u32);
	// lwz r19,0(r8)
	r19.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// clrlwi r19,r19,23
	r19.u64 = r19.u32 & 0x1FF;
	// fmadds f4,f1,f31,f30
	ctx.f4.f64 = double(float(ctx.f1.f64 * f31.f64 + f30.f64));
	// fmuls f1,f22,f5
	ctx.f1.f64 = double(float(f22.f64 * ctx.f5.f64));
	// stw r19,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r19.u32);
	// stfs f4,12(r20)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r20.u32 + 12, temp.u32);
	// lwz r20,416(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 416);
	// lwz r19,0(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mr r17,r19
	r17.u64 = r19.u64;
	// lfs f4,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lwz r16,0(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lfs f5,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// subf r17,r16,r17
	r17.s64 = r17.s64 - r16.s64;
	// clrlwi r17,r17,23
	r17.u64 = r17.u32 & 0x1FF;
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// addi r17,r17,2
	r17.s64 = r17.s64 + 2;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r17,r7
	temp.u32 = PPC_LOAD_U32(r17.u32 + ctx.r7.u32);
	f31.f64 = double(temp.f32);
	// fmadds f4,f4,f31,f26
	ctx.f4.f64 = double(float(ctx.f4.f64 * f31.f64 + f26.f64));
	// stfsx f4,r19,r7
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r19.u32 + ctx.r7.u32, temp.u32);
	// lwz r19,0(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// fmadds f5,f4,f5,f31
	ctx.f5.f64 = double(float(ctx.f4.f64 * ctx.f5.f64 + f31.f64));
	// clrlwi r19,r19,23
	r19.u64 = r19.u32 & 0x1FF;
	// stw r19,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r19.u32);
	// stfs f5,12(r20)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r20.u32 + 12, temp.u32);
	// lwz r20,424(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 424);
	// addi r19,r20,12
	r19.s64 = r20.s64 + 12;
	// lwz r17,0(r20)
	r17.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// clrlwi r17,r17,31
	r17.u64 = r17.u32 & 0x1;
	// addi r17,r17,4
	r17.s64 = r17.s64 + 4;
	// lfs f5,16(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r17,r20
	temp.u32 = PPC_LOAD_U32(r17.u32 + r20.u32);
	f31.f64 = double(temp.f32);
	// fmadds f4,f31,f4,f25
	ctx.f4.f64 = double(float(f31.f64 * ctx.f4.f64 + f25.f64));
	// stfs f5,20(r20)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r20.u32 + 20, temp.u32);
	// stfs f25,16(r20)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r20.u32 + 16, temp.u32);
	// stfs f4,8(r20)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r20.u32 + 8, temp.u32);
	// lwz r20,0(r28)
	r20.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lfs f4,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// clrlwi r20,r20,31
	r20.u64 = r20.u32 & 0x1;
	// lfs f31,12(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f31.f64 = double(temp.f32);
	// addi r17,r20,6
	r17.s64 = r20.s64 + 6;
	// lfs f30,24(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 24);
	f30.f64 = double(temp.f32);
	// addi r20,r28,20
	r20.s64 = r28.s64 + 20;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f5,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// addi r20,r21,16
	r20.s64 = r21.s64 + 16;
	// lfsx f29,r17,r28
	temp.u32 = PPC_LOAD_U32(r17.u32 + r28.u32);
	f29.f64 = double(temp.f32);
	// fmadds f5,f5,f29,f24
	ctx.f5.f64 = double(float(ctx.f5.f64 * f29.f64 + f24.f64));
	// fmuls f4,f5,f4
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f5,24(r28)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r28.u32 + 24, temp.u32);
	// stfs f30,28(r28)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r28.u32 + 28, temp.u32);
	// fmadds f5,f29,f31,f4
	ctx.f5.f64 = double(float(f29.f64 * f31.f64 + ctx.f4.f64));
	// stfs f5,16(r28)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r28.u32 + 16, temp.u32);
	// lfs f4,12(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lwz r17,0(r21)
	r17.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lfs f5,20(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// clrlwi r19,r17,31
	r19.u64 = r17.u32 & 0x1;
	// addi r19,r19,5
	r19.s64 = r19.s64 + 5;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f31,r19,r21
	temp.u32 = PPC_LOAD_U32(r19.u32 + r21.u32);
	f31.f64 = double(temp.f32);
	// fmadds f4,f31,f4,f23
	ctx.f4.f64 = double(float(f31.f64 * ctx.f4.f64 + f23.f64));
	// stfs f4,20(r21)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r21.u32 + 20, temp.u32);
	// stfs f5,24(r21)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r21.u32 + 24, temp.u32);
	// lfs f5,8(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f4,f5
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f5.f64));
	// stfs f4,4(r21)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r21.u32 + 4, temp.u32);
	// lwz r19,0(r10)
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r17,12(r27)
	r17.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lfs f4,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// lwz r16,0(r27)
	r16.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lfs f5,16(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// subf r19,r17,r19
	r19.s64 = r19.s64 - r17.s64;
	// lwz r17,0(r10)
	r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// ld r25,440(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + 440);
	// fadds f31,f0,f20
	f31.f64 = double(float(f0.f64 + f20.f64));
	// subf r17,r16,r17
	r17.s64 = r17.s64 - r16.s64;
	// ld r5,432(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 432);
	// clrlwi r19,r19,20
	r19.u64 = r19.u32 & 0xFFF;
	// ld r4,464(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 464);
	// clrlwi r20,r17,20
	r20.u64 = r17.u32 & 0xFFF;
	// ld r9,456(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 456);
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// fadds f3,f3,f18
	ctx.f3.f64 = double(float(ctx.f3.f64 + f18.f64));
	// addi r20,r20,2
	r20.s64 = r20.s64 + 2;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r20,r20,2,0,29
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r19,r10
	temp.u32 = PPC_LOAD_U32(r19.u32 + ctx.r10.u32);
	f30.f64 = double(temp.f32);
	// lfsx f29,r20,r10
	temp.u32 = PPC_LOAD_U32(r20.u32 + ctx.r10.u32);
	f29.f64 = double(temp.f32);
	// fmuls f5,f5,f30
	ctx.f5.f64 = double(float(ctx.f5.f64 * f30.f64));
	// fmuls f4,f29,f4
	ctx.f4.f64 = double(float(f29.f64 * ctx.f4.f64));
	// stfs f4,8(r27)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// stfs f5,20(r27)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r27.u32 + 20, temp.u32);
	// lwz r20,0(r10)
	r20.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r20,r20,2
	r20.s64 = r20.s64 + 2;
	// rlwinm r20,r20,2,0,29
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r20,r10
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + ctx.r10.u32, temp.u32);
	// lwz r20,0(r10)
	r20.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// clrlwi r19,r20,20
	r19.u64 = r20.u32 & 0xFFF;
	// lwz r20,348(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// stw r19,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r19.u32);
	// lwz r19,0(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// clrlwi r19,r19,31
	r19.u64 = r19.u32 & 0x1;
	// addi r19,r19,4
	r19.s64 = r19.s64 + 4;
	// lfs f1,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f5,r19,r20
	temp.u32 = PPC_LOAD_U32(r19.u32 + r20.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f1
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f1.f64));
	// stfs f4,8(r20)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r20.u32 + 8, temp.u32);
	// addi r20,r20,12
	r20.s64 = r20.s64 + 12;
	// lfs f1,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,8(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 8, temp.u32);
	// stfs f21,4(r20)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(r20.u32 + 4, temp.u32);
	// lwz r20,420(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 420);
	// lfs f4,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lwz r17,0(r20)
	r17.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r19,0(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lfs f5,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// subf r19,r17,r19
	r19.s64 = r19.s64 - r17.s64;
	// clrlwi r17,r19,21
	r17.u64 = r19.u32 & 0x7FF;
	// lwz r19,0(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// addi r17,r17,2
	r17.s64 = r17.s64 + 2;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r6
	temp.u32 = PPC_LOAD_U32(r17.u32 + ctx.r6.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f4,f1,f4,f13
	ctx.f4.f64 = double(float(ctx.f1.f64 * ctx.f4.f64 + ctx.f13.f64));
	// fadds f4,f4,f9
	ctx.f4.f64 = double(float(ctx.f4.f64 + ctx.f9.f64));
	// fadds f4,f4,f10
	ctx.f4.f64 = double(float(ctx.f4.f64 + ctx.f10.f64));
	// stfsx f4,r19,r6
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r19.u32 + ctx.r6.u32, temp.u32);
	// lwz r19,0(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// clrlwi r19,r19,21
	r19.u64 = r19.u32 & 0x7FF;
	// fmadds f1,f4,f5,f1
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f5.f64 + ctx.f1.f64));
	// stw r19,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r19.u32);
	// stfs f1,12(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 12, temp.u32);
	// lwz r20,356(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// lwz r19,0(r25)
	r19.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r17,r19
	r17.u64 = r19.u64;
	// lwz r16,0(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// subf r17,r16,r17
	r17.s64 = r17.s64 - r16.s64;
	// addi r16,r19,2
	r16.s64 = r19.s64 + 2;
	// lfs f5,12(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// clrlwi r19,r17,21
	r19.u64 = r17.u32 & 0x7FF;
	// lfs f4,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lfs f1,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r17,r16,2,0,29
	r17.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// ld r26,448(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + 448);
	// lwz r16,116(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lfsx f30,r19,r25
	temp.u32 = PPC_LOAD_U32(r19.u32 + r25.u32);
	f30.f64 = double(temp.f32);
	// fmadds f4,f30,f4,f31
	ctx.f4.f64 = double(float(f30.f64 * ctx.f4.f64 + f31.f64));
	// stfsx f4,r17,r25
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r17.u32 + r25.u32, temp.u32);
	// fmuls f5,f30,f5
	ctx.f5.f64 = double(float(f30.f64 * ctx.f5.f64));
	// fmadds f1,f1,f31,f5
	ctx.f1.f64 = double(float(ctx.f1.f64 * f31.f64 + ctx.f5.f64));
	// lwz r19,0(r25)
	r19.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// clrlwi r19,r19,21
	r19.u64 = r19.u32 & 0x7FF;
	// stw r19,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r19.u32);
	// stfs f1,16(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 16, temp.u32);
	// lwz r20,396(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lwz r17,0(r20)
	r17.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lfs f4,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// lwz r15,0(r5)
	r15.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lfs f5,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// subf r17,r17,r15
	r17.s64 = r15.s64 - r17.s64;
	// clrlwi r17,r17,21
	r17.u64 = r17.u32 & 0x7FF;
	// mr r19,r15
	r19.u64 = r15.u64;
	// addi r17,r17,2
	r17.s64 = r17.s64 + 2;
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r5
	temp.u32 = PPC_LOAD_U32(r17.u32 + ctx.r5.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f4,f1,f4,f19
	ctx.f4.f64 = double(float(ctx.f1.f64 * ctx.f4.f64 + f19.f64));
	// stfsx f4,r19,r5
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r19.u32 + ctx.r5.u32, temp.u32);
	// lwz r19,0(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// fmadds f1,f4,f5,f1
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f5.f64 + ctx.f1.f64));
	// clrlwi r19,r19,21
	r19.u64 = r19.u32 & 0x7FF;
	// stw r19,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r19.u32);
	// stfs f1,12(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 12, temp.u32);
	// lwz r20,364(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// lfs f5,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// lwz r15,0(r4)
	r15.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r17,0(r20)
	r17.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// subf r17,r17,r15
	r17.s64 = r15.s64 - r17.s64;
	// clrlwi r17,r17,22
	r17.u64 = r17.u32 & 0x3FF;
	// mr r19,r15
	r19.u64 = r15.u64;
	// addi r17,r17,2
	r17.s64 = r17.s64 + 2;
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r4
	temp.u32 = PPC_LOAD_U32(r17.u32 + ctx.r4.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f5,f1,f5,f0
	ctx.f5.f64 = double(float(ctx.f1.f64 * ctx.f5.f64 + f0.f64));
	// fadds f2,f5,f2
	ctx.f2.f64 = double(float(ctx.f5.f64 + ctx.f2.f64));
	// stfsx f2,r19,r4
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r19.u32 + ctx.r4.u32, temp.u32);
	// fmadds f1,f2,f4,f1
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f4.f64 + ctx.f1.f64));
	// lwz r19,0(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// clrlwi r19,r19,22
	r19.u64 = r19.u32 & 0x3FF;
	// stw r19,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r19.u32);
	// stfs f1,12(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 12, temp.u32);
	// lwz r19,12(r26)
	r19.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// lfs f5,16(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lwz r20,0(r9)
	r20.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f4,4(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// mr r17,r20
	r17.u64 = r20.u64;
	// subf r20,r19,r20
	r20.s64 = r20.s64 - r19.s64;
	// lwz r19,0(r26)
	r19.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// clrlwi r20,r20,20
	r20.u64 = r20.u32 & 0xFFF;
	// subf r19,r19,r17
	r19.s64 = r17.s64 - r19.s64;
	// addi r17,r20,2
	r17.s64 = r20.s64 + 2;
	// clrlwi r20,r19,20
	r20.u64 = r19.u32 & 0xFFF;
	// rlwinm r19,r17,2,0,29
	r19.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r17,r20,2
	r17.s64 = r20.s64 + 2;
	// clrlwi r20,r16,27
	r20.u64 = r16.u32 & 0x1F;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// lfsx f2,r19,r9
	temp.u32 = PPC_LOAD_U32(r19.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f2,f5
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f5.f64));
	// lfsx f5,r17,r9
	temp.u32 = PPC_LOAD_U32(r17.u32 + ctx.r9.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f4
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f4,8(r26)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r26.u32 + 8, temp.u32);
	// stfs f1,20(r26)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r26.u32 + 20, temp.u32);
	// lwz r20,0(r9)
	r20.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r20,r20,2
	r20.s64 = r20.s64 + 2;
	// rlwinm r20,r20,2,0,29
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f3,r20,r9
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r20.u32 + ctx.r9.u32, temp.u32);
	// ld r31,384(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 384);
	// lfs f2,372(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	ctx.f2.f64 = double(temp.f32);
	// lwz r20,0(r9)
	r20.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r19,r20,1
	r19.s64 = r20.s64 + 1;
	// lwz r20,412(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
	// clrlwi r17,r19,20
	r17.u64 = r19.u32 & 0xFFF;
	// addi r19,r20,16
	r19.s64 = r20.s64 + 16;
	// stw r17,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r17.u32);
	// lwz r17,0(r20)
	r17.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lfs f3,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// clrlwi r17,r17,31
	r17.u64 = r17.u32 & 0x1;
	// lfs f5,12(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,20(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// addi r17,r17,5
	r17.s64 = r17.s64 + 5;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f3,r17,r20
	temp.u32 = PPC_LOAD_U32(r17.u32 + r20.u32);
	ctx.f3.f64 = double(temp.f32);
	// stfs f4,24(r20)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r20.u32 + 24, temp.u32);
	// fmadds f1,f3,f5,f1
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f5.f64 + ctx.f1.f64));
	// stfs f2,20(r20)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r20.u32 + 20, temp.u32);
	// stfs f1,4(r20)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r20.u32 + 4, temp.u32);
	// bne cr6,0x823f2cc8
	if (!cr6.eq) goto loc_823F2CC8;
	// lwz r20,144(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// addi r20,r20,128
	r20.s64 = r20.s64 + 128;
	// stw r20,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r20.u32);
loc_823F2CC8:
	// lwz r16,128(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lfs f4,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f4.f64 = double(temp.f32);
	// lwz r19,120(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// fsubs f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// mr r17,r16
	r17.u64 = r16.u64;
	// lwz r15,96(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r14,r16
	r14.u64 = r16.u64;
	// std r11,384(r1)
	PPC_STORE_U64(ctx.r1.u32 + 384, r11.u64);
	// addi r20,r17,16
	r20.s64 = r17.s64 + 16;
	// lfs f9,404(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	ctx.f9.f64 = double(temp.f32);
	// addi r20,r19,20
	r20.s64 = r19.s64 + 20;
	// lfs f3,4(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// addi r19,r15,16
	r19.s64 = r15.s64 + 16;
	// lwz r15,112(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r16,r16,16
	r16.s64 = r16.s64 + 16;
	// lwz r11,16(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 16);
	// lfs f2,8(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lwz r17,0(r17)
	r17.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// fadds f5,f13,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 + ctx.f9.f64));
	// subf r11,r17,r11
	r11.s64 = r11.s64 - r17.s64;
	// stw r15,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r15.u32);
	// lwz r15,0(r16)
	r15.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// addi r15,r15,2
	r15.s64 = r15.s64 + 2;
	// lwz r17,124(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// stw r15,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r15.u32);
	// clrlwi r15,r11,21
	r15.u64 = r11.u32 & 0x7FF;
	// addi r17,r17,16
	r17.s64 = r17.s64 + 16;
	// addi r15,r15,2
	r15.s64 = r15.s64 + 2;
	// rlwinm r15,r15,2,0,29
	r15.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r15,r16
	temp.u32 = PPC_LOAD_U32(r15.u32 + r16.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f10,f1,f2,f10
	ctx.f10.f64 = double(float(ctx.f1.f64 * ctx.f2.f64 + ctx.f10.f64));
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + f0.f64));
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f9,r11,r16
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + r16.u32, temp.u32);
	// lwz r15,0(r16)
	r15.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// clrlwi r15,r15,21
	r15.u64 = r15.u32 & 0x7FF;
	// fmadds f3,f9,f3,f1
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f3.f64 + ctx.f1.f64));
	// stw r15,0(r16)
	PPC_STORE_U32(r16.u32 + 0, r15.u32);
	// stfs f3,12(r14)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r14.u32 + 12, temp.u32);
	// lwz r16,120(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lfs f0,12(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f2,8(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lwz r14,0(r16)
	r14.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r15,r11
	r15.u64 = r11.u64;
	// subf r14,r14,r11
	r14.s64 = r11.s64 - r14.s64;
	// lfs f1,4(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// addi r11,r15,2
	r11.s64 = r15.s64 + 2;
	// clrlwi r15,r14,21
	r15.u64 = r14.u32 & 0x7FF;
	// rlwinm r14,r11,2,0,29
	r14.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r15,r15,2
	r15.s64 = r15.s64 + 2;
	// rlwinm r15,r15,2,0,29
	r15.u64 = __builtin_rotateleft64(r15.u32 | (r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f10,r15,r20
	temp.u32 = PPC_LOAD_U32(r15.u32 + r20.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f3,f10,f0
	ctx.f3.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmadds f9,f10,f2,f5
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f2.f64 + ctx.f5.f64));
	// stfsx f9,r14,r20
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r14.u32 + r20.u32, temp.u32);
	// lwz r15,0(r20)
	r15.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// clrlwi r15,r15,21
	r15.u64 = r15.u32 & 0x7FF;
	// fmadds f2,f5,f1,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f1.f64 + ctx.f3.f64));
	// stw r15,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r15.u32);
	// stfs f2,16(r16)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r16.u32 + 16, temp.u32);
	// lwz r20,96(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f1,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r15,0(r19)
	r15.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwz r14,0(r20)
	r14.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lfs f0,4(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r16,r15
	r16.u64 = r15.u64;
	// subf r15,r14,r15
	r15.s64 = r15.s64 - r14.s64;
	// addi r14,r16,2
	r14.s64 = r16.s64 + 2;
	// clrlwi r16,r15,21
	r16.u64 = r15.u32 & 0x7FF;
	// rlwinm r15,r14,2,0,29
	r15.u64 = __builtin_rotateleft64(r14.u32 | (r14.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r16,r16,2
	r16.s64 = r16.s64 + 2;
	// rlwinm r16,r16,2,0,29
	r16.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f10,r16,r19
	temp.u32 = PPC_LOAD_U32(r16.u32 + r19.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f1,f10,f4
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfsx f9,r15,r19
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r15.u32 + r19.u32, temp.u32);
	// lwz r16,0(r19)
	r16.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// addi r16,r16,1
	r16.s64 = r16.s64 + 1;
	// clrlwi r15,r16,21
	r15.u64 = r16.u32 & 0x7FF;
	// fmadds f5,f9,f0,f10
	ctx.f5.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f10.f64));
	// lwz r14,104(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lfs f4,240(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f4.f64 = double(temp.f32);
	// stw r15,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r15.u32);
	// stfs f5,12(r20)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r20.u32 + 12, temp.u32);
	// addi r20,r14,4
	r20.s64 = r14.s64 + 4;
	// lwz r19,100(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r16,112(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stfs f6,0(r24)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r24.u32 + 0, temp.u32);
	// stw r20,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r20.u32);
	// lfs f3,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f3.f64 = double(temp.f32);
	// lwz r20,84(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fadds f2,f8,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 + ctx.f3.f64));
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfsx f7,r24,r19
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r24.u32 + r19.u32, temp.u32);
	// lwz r14,116(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lfs f1,8(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r15,136(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r14,r14,1
	r14.s64 = r14.s64 + 1;
	// stfsx f12,r20,r24
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r20.u32 + r24.u32, temp.u32);
	// addi r15,r15,4
	r15.s64 = r15.s64 + 4;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stw r14,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r14.u32);
	// stw r15,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r15.u32);
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// lwz r19,0(r17)
	r19.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lfs f0,4(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r20,0(r16)
	r20.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// addi r14,r19,2
	r14.s64 = r19.s64 + 2;
	// subf r20,r20,r19
	r20.s64 = r19.s64 - r20.s64;
	// lwz r15,104(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r14,r14,2,0,29
	r14.u64 = __builtin_rotateleft64(r14.u32 | (r14.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r19,264(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// clrlwi r20,r20,22
	r20.u64 = r20.u32 & 0x3FF;
	// cmpwi cr6,r15,1024
	cr6.compare<int32_t>(r15.s32, 1024, xer);
	// addi r20,r20,2
	r20.s64 = r20.s64 + 2;
	// rlwinm r11,r20,2,0,29
	r11.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r20,r19,24
	r20.s64 = r19.s64 + 24;
	// lfsx f12,r11,r17
	temp.u32 = PPC_LOAD_U32(r11.u32 + r17.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f1,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + ctx.f13.f64));
	// fadds f10,f11,f4
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f4.f64));
	// stfsx f10,r14,r17
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r14.u32 + r17.u32, temp.u32);
	// fmadds f9,f10,f0,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f12.f64));
	// lwz r15,0(r17)
	r15.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// clrlwi r15,r15,22
	r15.u64 = r15.u32 & 0x3FF;
	// stw r15,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r15.u32);
	// stfs f9,12(r16)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r16.u32 + 12, temp.u32);
	// lwz r16,0(r19)
	r16.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lfs f8,16(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lwz r17,24(r19)
	r17.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// lfs f7,4(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// subf r17,r16,r17
	r17.s64 = r17.s64 - r16.s64;
	// lwz r16,24(r19)
	r16.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// clrlwi r17,r17,20
	r17.u64 = r17.u32 & 0xFFF;
	// lwz r15,12(r19)
	r15.u64 = PPC_LOAD_U32(r19.u32 + 12);
	// subf r16,r15,r16
	r16.s64 = r16.s64 - r15.s64;
	// addi r17,r17,2
	r17.s64 = r17.s64 + 2;
	// clrlwi r16,r16,20
	r16.u64 = r16.u32 & 0xFFF;
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r16,r16,2
	r16.s64 = r16.s64 + 2;
	// rlwinm r16,r16,2,0,29
	r16.u64 = __builtin_rotateleft64(r16.u32 | (r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f6,r17,r20
	temp.u32 = PPC_LOAD_U32(r17.u32 + r20.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f5,r16,r20
	temp.u32 = PPC_LOAD_U32(r16.u32 + r20.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// fmuls f3,f6,f7
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// stfs f3,8(r19)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r19.u32 + 8, temp.u32);
	// stfs f4,20(r19)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r19.u32 + 20, temp.u32);
	// lwz r19,24(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 24);
	// addi r19,r19,2
	r19.s64 = r19.s64 + 2;
	// rlwinm r19,r19,2,0,29
	r19.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f2,r19,r20
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r19.u32 + r20.u32, temp.u32);
	// lwz r19,0(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// clrlwi r19,r19,20
	r19.u64 = r19.u32 & 0xFFF;
	// stw r19,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r19.u32);
	// lwz r20,280(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// lwz r19,0(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lfs f2,8(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// clrlwi r19,r19,31
	r19.u64 = r19.u32 & 0x1;
	// lfs f0,296(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	f0.f64 = double(temp.f32);
	// addi r17,r19,5
	r17.s64 = r19.s64 + 5;
	// fmuls f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * f0.f64));
	// lfs f13,12(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	r17.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,20(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// ld r11,384(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 384);
	// addi r19,r20,16
	r19.s64 = r20.s64 + 16;
	// lfsx f11,r17,r20
	temp.u32 = PPC_LOAD_U32(r17.u32 + r20.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,24(r20)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r20.u32 + 24, temp.u32);
	// stfs f0,20(r20)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r20.u32 + 20, temp.u32);
	// fmadds f10,f11,f13,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f1.f64));
	// stfs f10,4(r20)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r20.u32 + 4, temp.u32);
	// blt cr6,0x823f24a4
	if (cr6.lt) goto loc_823F24A4;
	// lwz r27,232(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// lwz r28,220(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// addi r3,r3,-28368
	ctx.r3.s64 = ctx.r3.s64 + -28368;
	// lwz r26,228(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823f1118
	ctx.lr = 0x823F2FA4;
	sub_823F1118(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r3,-26296
	ctx.r3.s64 = ctx.r3.s64 + -26296;
	// bl 0x823f1118
	ctx.lr = 0x823F2FB4;
	sub_823F1118(ctx, base);
	// lwz r30,224(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r3,-24224
	ctx.r3.s64 = ctx.r3.s64 + -24224;
	// bl 0x823f1118
	ctx.lr = 0x823F2FC8;
	sub_823F1118(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r3,-22152
	ctx.r3.s64 = ctx.r3.s64 + -22152;
	// bl 0x823f1118
	ctx.lr = 0x823F2FD8;
	sub_823F1118(ctx, base);
	// addi r29,r28,-8
	r29.s64 = r28.s64 + -8;
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r3,-20080
	ctx.r3.s64 = ctx.r3.s64 + -20080;
	// bl 0x823f14b0
	ctx.lr = 0x823F2FF0;
	sub_823F14B0(ctx, base);
	// addi r28,r26,-8
	r28.s64 = r26.s64 + -8;
	// addis r3,r31,5
	ctx.r3.s64 = r31.s64 + 327680;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r3,-19024
	ctx.r3.s64 = ctx.r3.s64 + -19024;
	// bl 0x823f14b0
	ctx.lr = 0x823F3008;
	sub_823F14B0(ctx, base);
	// li r7,92
	ctx.r7.s64 = 92;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// lwz r9,160(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r8,152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r5,r6,-15568
	ctx.r5.s64 = ctx.r6.s64 + -15568;
	// lwz r6,324(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// subf r3,r9,r27
	ctx.r3.s64 = r27.s64 - ctx.r9.s64;
	// lvlx128 v63,r31,r7
	temp.u32 = r31.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r24,r9,r29
	r24.s64 = r29.s64 - ctx.r9.s64;
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// subf r26,r9,r30
	r26.s64 = r30.s64 - ctx.r9.s64;
	// subf r22,r30,r8
	r22.s64 = ctx.r8.s64 - r30.s64;
	// lwz r7,332(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r25,r9,r8
	r25.s64 = ctx.r8.s64 - ctx.r9.s64;
	// subf r27,r30,r27
	r27.s64 = r27.s64 - r30.s64;
	// lwz r8,308(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// subf r29,r30,r29
	r29.s64 = r29.s64 - r30.s64;
	// vsubfp128 v0,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r9,16
	r11.s64 = ctx.r9.s64 + 16;
	// vaddfp128 v62,v63,v63
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32)));
	// subf r23,r9,r28
	r23.s64 = r28.s64 - ctx.r9.s64;
	// lwz r9,316(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// subf r30,r30,r28
	r30.s64 = r28.s64 - r30.s64;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r31,-16
	r31.s64 = -16;
	// li r5,16
	ctx.r5.s64 = 16;
loc_823F3078:
	// lvx128 v61,r27,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lvx128 v60,r3,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v12,v63,v60
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v58,r26,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v63,v59
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32)));
	// vmulfp128 v10,v63,v58
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v9,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r11,r31
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r22,r10
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r25,r11
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r29,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r24,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v55,v62,v57
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32)));
	// lvx128 v54,r30,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v53,v62,v56
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v56.f32)));
	// lvx128 v52,r23,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v51,v62,v54
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v54.f32)));
	// vmulfp128 v50,v62,v52
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v52.f32)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vmaddfp v5,v0,v8,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// vmaddfp v4,v0,v9,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v3,v0,v7,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v2,v0,v6,v10
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// stvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r8,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// stvx128 v5,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v4,r7,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// stvx128 v3,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v2,r6,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r6,32
	ctx.r6.s64 = ctx.r6.s64 + 32;
	// bne 0x823f3078
	if (!cr0.eq) goto loc_823F3078;
	// addi r1,r1,17968
	ctx.r1.s64 = ctx.r1.s64 + 17968;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9ec
	ctx.lr = 0x823F3124;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_823F3128"))) PPC_WEAK_FUNC(sub_823F3128);
PPC_FUNC_IMPL(__imp__sub_823F3128) {
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
	ctx.lr = 0x823F3130;
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
	// bl 0x827bd514
	ctx.lr = 0x823F3144;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f316c
	if (cr6.eq) goto loc_823F316C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f3180
	if (cr6.eq) goto loc_823F3180;
loc_823F316C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F3174;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823F3180:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,188(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f31a8
	if (cr6.eq) goto loc_823F31A8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lfs f1,184(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 184);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x823f7e60
	ctx.lr = 0x823F31A8;
	sub_823F7E60(ctx, base);
loc_823F31A8:
	// lbz r11,189(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 189);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f31cc
	if (cr6.eq) goto loc_823F31CC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r30,52
	ctx.r4.s64 = r30.s64 + 52;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x823f7e78
	ctx.lr = 0x823F31C8;
	sub_823F7E78(ctx, base);
	// b 0x823f31e8
	goto loc_823F31E8;
loc_823F31CC:
	// lbz r11,190(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 190);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f31e8
	if (cr6.eq) goto loc_823F31E8;
	// addi r5,r30,136
	ctx.r5.s64 = r30.s64 + 136;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823f9a80
	ctx.lr = 0x823F31E8;
	sub_823F9A80(ctx, base);
loc_823F31E8:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r13
	ctx.r9.u64 = ctx.r13.u64;
	// stb r10,190(r30)
	PPC_STORE_U8(r30.u32 + 190, ctx.r10.u8);
	// stb r10,188(r30)
	PPC_STORE_U8(r30.u32 + 188, ctx.r10.u8);
	// stb r10,189(r30)
	PPC_STORE_U8(r30.u32 + 189, ctx.r10.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f3240
	if (cr6.eq) goto loc_823F3240;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x823f3240
	if (!cr6.eq) goto loc_823F3240;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f3240
	if (!cr0.eq) goto loc_823F3240;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F3238;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F3240;
	__imp__KfLowerIrql(ctx, base);
loc_823F3240:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,256
	ctx.r6.s64 = 256;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x823f19b0
	ctx.lr = 0x823F325C;
	sub_823F19B0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823F3264"))) PPC_WEAK_FUNC(sub_823F3264);
PPC_FUNC_IMPL(__imp__sub_823F3264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F3268"))) PPC_WEAK_FUNC(sub_823F3268);
PPC_FUNC_IMPL(__imp__sub_823F3268) {
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
	// lwz r10,-192(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + -192);
	// addi r31,r3,-192
	r31.s64 = ctx.r3.s64 + -192;
	// clrlwi r5,r4,31
	ctx.r5.u64 = ctx.r4.u32 & 0x1;
	// addi r11,r31,52
	r11.s64 = r31.s64 + 52;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r7,r9,-4024
	ctx.r7.s64 = ctx.r9.s64 + -4024;
	// addi r6,r8,-4368
	ctx.r6.s64 = ctx.r8.s64 + -4368;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r7,-52(r4)
	PPC_STORE_U32(ctx.r4.u32 + -52, ctx.r7.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// beq cr6,0x823f32c4
	if (cr6.eq) goto loc_823F32C4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823F32C4;
	sub_823EF7C8(ctx, base);
loc_823F32C4:
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

__attribute__((alias("__imp__sub_823F32DC"))) PPC_WEAK_FUNC(sub_823F32DC);
PPC_FUNC_IMPL(__imp__sub_823F32DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F32E0"))) PPC_WEAK_FUNC(sub_823F32E0);
PPC_FUNC_IMPL(__imp__sub_823F32E0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x823f35e8
	sub_823F35E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F32E8"))) PPC_WEAK_FUNC(sub_823F32E8);
PPC_FUNC_IMPL(__imp__sub_823F32E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// stw r3,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3300"))) PPC_WEAK_FUNC(sub_823F3300);
PPC_FUNC_IMPL(__imp__sub_823F3300) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// addic. r3,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r3.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// bne 0x823f3338
	if (!cr0.eq) goto loc_823F3338;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823F3334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_823F3338:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3348"))) PPC_WEAK_FUNC(sub_823F3348);
PPC_FUNC_IMPL(__imp__sub_823F3348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3358"))) PPC_WEAK_FUNC(sub_823F3358);
PPC_FUNC_IMPL(__imp__sub_823F3358) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x823eaf00
	ctx.lr = 0x823F3380;
	sub_823EAF00(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f34a8
	if (cr6.lt) goto loc_823F34A8;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823eaf00
	ctx.lr = 0x823F3394;
	sub_823EAF00(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f34a8
	if (cr6.lt) goto loc_823F34A8;
	// lis r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,6
	ctx.r9.s64 = 6;
	// ori r8,r11,48000
	ctx.r8.u64 = r11.u64 | 48000;
	// stb r10,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r10.u8);
	// stb r9,105(r1)
	PPC_STORE_U8(ctx.r1.u32 + 105, ctx.r9.u8);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823eb1d0
	ctx.lr = 0x823F33C8;
	sub_823EB1D0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f34a8
	if (cr6.lt) goto loc_823F34A8;
	// lbz r11,121(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 121);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x823f34a4
	if (cr6.lt) goto loc_823F34A4;
	// beq cr6,0x823f33fc
	if (cr6.eq) goto loc_823F33FC;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x823f33f4
	if (cr6.lt) goto loc_823F33F4;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x823f34a8
	goto loc_823F34A8;
loc_823F33F4:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823f3400
	goto loc_823F3400;
loc_823F33FC:
	// li r4,1
	ctx.r4.s64 = 1;
loc_823F3400:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x823f7e58
	ctx.lr = 0x823F3418;
	sub_823F7E58(ctx, base);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r9,r11,1024
	ctx.r9.s64 = r11.s64 + 1024;
	// addi r8,r10,1024
	ctx.r8.s64 = ctx.r10.s64 + 1024;
	// addi r7,r11,2048
	ctx.r7.s64 = r11.s64 + 2048;
	// stw r9,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r9.u32);
	// addi r6,r11,4096
	ctx.r6.s64 = r11.s64 + 4096;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// addi r5,r11,5120
	ctx.r5.s64 = r11.s64 + 5120;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r7,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r7.u32);
	// stw r6,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r6.u32);
	// stw r5,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// bl 0x82458098
	ctx.lr = 0x823F3458;
	sub_82458098(ctx, base);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823f3128
	ctx.lr = 0x823F3468;
	sub_823F3128(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82458098
	ctx.lr = 0x823F3470;
	sub_82458098(ctx, base);
	// addis r11,r31,5
	r11.s64 = r31.s64 + 327680;
	// addis r4,r31,5
	ctx.r4.s64 = r31.s64 + 327680;
	// ld r7,96(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r11,-17752
	r11.s64 = r11.s64 + -17752;
	// ld r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r4,r4,-17760
	ctx.r4.s64 = ctx.r4.s64 + -17760;
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// ld r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// subf r11,r7,r8
	r11.s64 = ctx.r8.s64 - ctx.r7.s64;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// std r6,0(r4)
	PPC_STORE_U64(ctx.r4.u32 + 0, ctx.r6.u64);
loc_823F34A4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823F34A8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

__attribute__((alias("__imp__sub_823F34C0"))) PPC_WEAK_FUNC(sub_823F34C0);
PPC_FUNC_IMPL(__imp__sub_823F34C0) {
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
	// lwz r10,-52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + -52);
	// addi r31,r3,-52
	r31.s64 = ctx.r3.s64 + -52;
	// clrlwi r5,r4,31
	ctx.r5.u64 = ctx.r4.u32 & 0x1;
	// addi r11,r31,52
	r11.s64 = r31.s64 + 52;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r7,r9,-4024
	ctx.r7.s64 = ctx.r9.s64 + -4024;
	// addi r6,r8,-4368
	ctx.r6.s64 = ctx.r8.s64 + -4368;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r7,-52(r4)
	PPC_STORE_U32(ctx.r4.u32 + -52, ctx.r7.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// beq cr6,0x823f351c
	if (cr6.eq) goto loc_823F351C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823F351C;
	sub_823EF7C8(ctx, base);
loc_823F351C:
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

__attribute__((alias("__imp__sub_823F3534"))) PPC_WEAK_FUNC(sub_823F3534);
PPC_FUNC_IMPL(__imp__sub_823F3534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F3538"))) PPC_WEAK_FUNC(sub_823F3538);
PPC_FUNC_IMPL(__imp__sub_823F3538) {
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
	ctx.lr = 0x823F3540;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-4052
	ctx.r9.s64 = r11.s64 + -4052;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lwz r5,4(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r3,r7,-3984
	ctx.r3.s64 = ctx.r7.s64 + -3984;
	// addi r4,r8,-3956
	ctx.r4.s64 = ctx.r8.s64 + -3956;
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// addi r11,r6,-3992
	r11.s64 = ctx.r6.s64 + -3992;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// addi r3,r30,192
	ctx.r3.s64 = r30.s64 + 192;
	// li r29,0
	r29.s64 = 0;
	// bl 0x823f8c10
	ctx.lr = 0x823F359C;
	sub_823F8C10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823f9bd8
	ctx.lr = 0x823F35A8;
	sub_823F9BD8(ctx, base);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r3,r30,52
	ctx.r3.s64 = r30.s64 + 52;
	// addi r9,r10,-3996
	ctx.r9.s64 = ctx.r10.s64 + -3996;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stwx r9,r7,r30
	PPC_STORE_U32(ctx.r7.u32 + r30.u32, ctx.r9.u32);
	// bl 0x823f79c8
	ctx.lr = 0x823F35C4;
	sub_823F79C8(ctx, base);
	// lis r5,4
	ctx.r5.s64 = 262144;
	// lis r6,4
	ctx.r6.s64 = 262144;
	// ori r3,r5,47784
	ctx.r3.u64 = ctx.r5.u64 | 47784;
	// ori r4,r6,47776
	ctx.r4.u64 = ctx.r6.u64 | 47776;
	// stdx r29,r31,r3
	PPC_STORE_U64(r31.u32 + ctx.r3.u32, r29.u64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stdx r29,r31,r4
	PPC_STORE_U64(r31.u32 + ctx.r4.u32, r29.u64);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F35E8"))) PPC_WEAK_FUNC(sub_823F35E8);
PPC_FUNC_IMPL(__imp__sub_823F35E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,-3956
	ctx.r9.s64 = r11.s64 + -3956;
	// addi r8,r10,-3984
	ctx.r8.s64 = ctx.r10.s64 + -3984;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r11,52
	r11.s64 = r11.s64 + 52;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r8,r5,-4368
	ctx.r8.s64 = ctx.r5.s64 + -4368;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// addi r9,r6,-4024
	ctx.r9.s64 = ctx.r6.s64 + -4024;
	// addi r6,r4,-4364
	ctx.r6.s64 = ctx.r4.s64 + -4364;
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,-52(r5)
	PPC_STORE_U32(ctx.r5.u32 + -52, ctx.r9.u32);
	// stw r8,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r8.u32);
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3640"))) PPC_WEAK_FUNC(sub_823F3640);
PPC_FUNC_IMPL(__imp__sub_823F3640) {
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
	ctx.lr = 0x823F3648;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r4,4
	ctx.r4.s64 = 262144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// ori r4,r4,47792
	ctx.r4.u64 = ctx.r4.u64 | 47792;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3674;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f3694
	if (cr6.eq) goto loc_823F3694;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823f3538
	ctx.lr = 0x823F3688;
	sub_823F3538(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823f36a4
	if (!cr6.eq) goto loc_823F36A4;
loc_823F3694:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823F36A4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F36C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823f36d8
	if (cr6.lt) goto loc_823F36D8;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823F36D8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F36EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F36F8"))) PPC_WEAK_FUNC(sub_823F36F8);
PPC_FUNC_IMPL(__imp__sub_823F36F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-22012(r10)
	PPC_STORE_U32(ctx.r10.u32 + -22012, r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,8(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823F3718"))) PPC_WEAK_FUNC(sub_823F3718);
PPC_FUNC_IMPL(__imp__sub_823F3718) {
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
	ctx.lr = 0x823F3720;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r31,r30,24
	r31.s64 = r30.s64 + 24;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f3758
	if (cr6.eq) goto loc_823F3758;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x827bd654
	ctx.lr = 0x823F3748;
	__imp__XAudioUnregisterRenderDriverClient(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f3778
	if (cr6.lt) goto loc_823F3778;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823F3758:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823f3778
	if (cr6.eq) goto loc_823F3778;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x827bd644
	ctx.lr = 0x823F3778;
	__imp__XAudioRegisterRenderDriverClient(ctx, base);
loc_823F3778:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F3780"))) PPC_WEAK_FUNC(sub_823F3780);
PPC_FUNC_IMPL(__imp__sub_823F3780) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
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
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r10,-15552
	ctx.r10.s64 = ctx.r10.s64 + -15552;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,6144
	cr6.compare<uint32_t>(ctx.r9.u32, 6144, xer);
	// beq cr6,0x823f3830
	if (cr6.eq) goto loc_823F3830;
	// li r9,6144
	ctx.r9.s64 = 6144;
loc_823F37A8:
	// mfmsr r6
	ctx.r6.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r8,0,r10
	reserved.u32 = *(uint32_t*)(base + ctx.r10.u32);
	ctx.r8.u64 = __builtin_bswap32(reserved.u32);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stwcx. r7,0,r10
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r10.u32), reserved.s32, __builtin_bswap32(ctx.r7.s32));
	cr0.so = xer.so;
	// mtmsrd r6,1
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x823f37a8
	if (!cr0.eq) goto loc_823F37A8;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f3824
	if (cr6.eq) goto loc_823F3824;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// subf r9,r10,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r10.s64;
	// cmplwi cr6,r9,6144
	cr6.compare<uint32_t>(ctx.r9.u32, 6144, xer);
	// bne cr6,0x823f37ec
	if (!cr6.eq) goto loc_823F37EC;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// b 0x823f37f0
	goto loc_823F37F0;
loc_823F37EC:
	// li r10,1
	ctx.r10.s64 = 1;
loc_823F37F0:
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r3,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r3.u32);
	// cmplwi cr6,r10,14
	cr6.compare<uint32_t>(ctx.r10.u32, 14, xer);
	// bgt cr6,0x823f3830
	if (cr6.gt) goto loc_823F3830;
	// li r5,6144
	ctx.r5.s64 = 6144;
	// lwz r4,8(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x823F3810;
	sub_823DA950(ctx, base);
	// lwsync 
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823F3824:
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// lwz r10,-22012(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22012);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
loc_823F3830:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3840"))) PPC_WEAK_FUNC(sub_823F3840);
PPC_FUNC_IMPL(__imp__sub_823F3840) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
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
	ctx.lr = 0x823F3848;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lis r6,-32107
	ctx.r6.s64 = -2104164352;
	// addi r5,r10,-3896
	ctx.r5.s64 = ctx.r10.s64 + -3896;
	// addi r4,r7,-3924
	ctx.r4.s64 = ctx.r7.s64 + -3924;
	// li r11,6144
	r11.s64 = 6144;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// lis r3,-32129
	ctx.r3.s64 = -2105606144;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// li r29,0
	r29.s64 = 0;
	// stw r11,-22012(r6)
	PPC_STORE_U32(ctx.r6.u32 + -22012, r11.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// addi r10,r3,-15552
	ctx.r10.s64 = ctx.r3.s64 + -15552;
loc_823F3884:
	// mfmsr r8
	ctx.r8.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r9,0,r10
	reserved.u32 = *(uint32_t*)(base + ctx.r10.u32);
	ctx.r9.u64 = __builtin_bswap32(reserved.u32);
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// bne cr6,0x823f38a8
	if (!cr6.eq) goto loc_823F38A8;
	// stwcx. r11,0,r10
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r10.u32), reserved.s32, __builtin_bswap32(r11.s32));
	cr0.so = xer.so;
	// mtmsrd r8,1
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x823f3884
	if (!cr0.eq) goto loc_823F3884;
	// b 0x823f38b0
	goto loc_823F38B0;
loc_823F38A8:
	// stwcx. r9,0,r10
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r10.u32), reserved.s32, __builtin_bswap32(ctx.r9.s32));
	cr0.so = xer.so;
	// mtmsrd r8,1
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_823F38B0:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f38cc
	if (cr6.eq) goto loc_823F38CC;
	// bl 0x827bd654
	ctx.lr = 0x823F38C0;
	__imp__XAudioUnregisterRenderDriverClient(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f38cc
	if (cr6.lt) goto loc_823F38CC;
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
loc_823F38CC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4364
	ctx.r10.s64 = r11.s64 + -4364;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F38E0"))) PPC_WEAK_FUNC(sub_823F38E0);
PPC_FUNC_IMPL(__imp__sub_823F38E0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x823f3978
	sub_823F3978(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F38E8"))) PPC_WEAK_FUNC(sub_823F38E8);
PPC_FUNC_IMPL(__imp__sub_823F38E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,2
	r11.s64 = 2;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r10,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3900"))) PPC_WEAK_FUNC(sub_823F3900);
PPC_FUNC_IMPL(__imp__sub_823F3900) {
	PPC_FUNC_PROLOGUE();
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3908"))) PPC_WEAK_FUNC(sub_823F3908);
PPC_FUNC_IMPL(__imp__sub_823F3908) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823eaf00
	ctx.lr = 0x823F3928;
	sub_823EAF00(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f3954
	if (cr6.lt) goto loc_823F3954;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x827bd664
	ctx.lr = 0x823F3954;
	__imp__XAudioSubmitRenderDriverFrame(ctx, base);
loc_823F3954:
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

__attribute__((alias("__imp__sub_823F3968"))) PPC_WEAK_FUNC(sub_823F3968);
PPC_FUNC_IMPL(__imp__sub_823F3968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,28
	r11.s64 = 28;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3978"))) PPC_WEAK_FUNC(sub_823F3978);
PPC_FUNC_IMPL(__imp__sub_823F3978) {
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
	// bl 0x823f3840
	ctx.lr = 0x823F3990;
	sub_823F3840(ctx, base);
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

__attribute__((alias("__imp__sub_823F39A8"))) PPC_WEAK_FUNC(sub_823F39A8);
PPC_FUNC_IMPL(__imp__sub_823F39A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-4052
	ctx.r9.s64 = r11.s64 + -4052;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r6,4(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r8,-3896
	ctx.r5.s64 = ctx.r8.s64 + -3896;
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// addi r4,r7,-3924
	ctx.r4.s64 = ctx.r7.s64 + -3924;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F39F0"))) PPC_WEAK_FUNC(sub_823F39F0);
PPC_FUNC_IMPL(__imp__sub_823F39F0) {
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
	ctx.lr = 0x823F39F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r4,28
	ctx.r4.s64 = 28;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3A20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823f3aa0
	if (cr6.eq) goto loc_823F3AA0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-4052
	ctx.r9.s64 = r11.s64 + -4052;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// li r11,0
	r11.s64 = 0;
	// lwz r6,4(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r5,r8,-3896
	ctx.r5.s64 = ctx.r8.s64 + -3896;
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r4,r7,-3924
	ctx.r4.s64 = ctx.r7.s64 + -3924;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// rotlwi r11,r5,0
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3A88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x823f3ab0
	if (cr6.lt) goto loc_823F3AB0;
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823F3AA0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823F3AB0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F3AD0"))) PPC_WEAK_FUNC(sub_823F3AD0);
PPC_FUNC_IMPL(__imp__sub_823F3AD0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x823f3b2c
	if (!cr6.eq) goto loc_823F3B2C;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x823f3b2c
	if (!cr6.eq) goto loc_823F3B2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r6,r31,4
	ctx.r6.s64 = r31.s64 + 4;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3B18;
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
loc_823F3B2C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f3b78
	if (!cr6.eq) goto loc_823F3B78;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x823f3b78
	if (!cr6.eq) goto loc_823F3B78;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f3bbc
	if (cr6.lt) goto loc_823F3BBC;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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
loc_823F3B78:
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x823f3bb4
	if (!cr6.eq) goto loc_823F3BB4;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x823f3bb4
	if (!cr6.eq) goto loc_823F3BB4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3BA0;
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
loc_823F3BB4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
loc_823F3BBC:
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

__attribute__((alias("__imp__sub_823F3BD0"))) PPC_WEAK_FUNC(sub_823F3BD0);
PPC_FUNC_IMPL(__imp__sub_823F3BD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x823f3bfc
	if (!cr6.eq) goto loc_823F3BFC;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x823f3bfc
	if (!cr6.eq) goto loc_823F3BFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F3BFC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f3c28
	if (!cr6.eq) goto loc_823F3C28;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x823f3c28
	if (!cr6.eq) goto loc_823F3C28;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F3C28:
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x823f3c50
	if (!cr6.eq) goto loc_823F3C50;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x823f3c50
	if (!cr6.eq) goto loc_823F3C50;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F3C50:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3C5C"))) PPC_WEAK_FUNC(sub_823F3C5C);
PPC_FUNC_IMPL(__imp__sub_823F3C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F3C60"))) PPC_WEAK_FUNC(sub_823F3C60);
PPC_FUNC_IMPL(__imp__sub_823F3C60) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x823f4540
	sub_823F4540(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F3C68"))) PPC_WEAK_FUNC(sub_823F3C68);
PPC_FUNC_IMPL(__imp__sub_823F3C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,6
	r11.s64 = 6;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r10,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3C80"))) PPC_WEAK_FUNC(sub_823F3C80);
PPC_FUNC_IMPL(__imp__sub_823F3C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,26(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 26);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3C90"))) PPC_WEAK_FUNC(sub_823F3C90);
PPC_FUNC_IMPL(__imp__sub_823F3C90) {
	PPC_FUNC_PROLOGUE();
	// stb r4,26(r3)
	PPC_STORE_U8(ctx.r3.u32 + 26, ctx.r4.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F3C9C"))) PPC_WEAK_FUNC(sub_823F3C9C);
PPC_FUNC_IMPL(__imp__sub_823F3C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F3CA0"))) PPC_WEAK_FUNC(sub_823F3CA0);
PPC_FUNC_IMPL(__imp__sub_823F3CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823F3CB4"))) PPC_WEAK_FUNC(sub_823F3CB4);
PPC_FUNC_IMPL(__imp__sub_823F3CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F3CB8"))) PPC_WEAK_FUNC(sub_823F3CB8);
PPC_FUNC_IMPL(__imp__sub_823F3CB8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lbz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f3cfc
	if (cr6.eq) goto loc_823F3CFC;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bgt cr6,0x823f3cfc
	if (cr6.gt) goto loc_823F3CFC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823F3CFC:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r10.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f3d30
	if (cr6.eq) goto loc_823F3D30;
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,20(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823F3D2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_823F3D30:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f3d68
	if (cr6.lt) goto loc_823F3D68;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,9(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 9);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F3D68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F3D68:
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

__attribute__((alias("__imp__sub_823F3D80"))) PPC_WEAK_FUNC(sub_823F3D80);
PPC_FUNC_IMPL(__imp__sub_823F3D80) {
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
	ctx.lr = 0x823F3D88;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F3DA0;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r29,r11,-9904
	r29.s64 = r11.s64 + -9904;
	// mr r28,r13
	r28.u64 = ctx.r13.u64;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f3dc8
	if (cr6.eq) goto loc_823F3DC8;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f3ddc
	if (cr6.eq) goto loc_823F3DDC;
loc_823F3DC8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F3DD0;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stw r28,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r28.u32);
	// stb r26,12(r29)
	PPC_STORE_U8(r29.u32 + 12, r26.u8);
loc_823F3DDC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// beq cr6,0x823f3e7c
	if (cr6.eq) goto loc_823F3E7C;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// stb r11,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r11.u8);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// lbz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823f3e80
	if (cr6.eq) goto loc_823F3E80;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	r11.s64 = 0;
loc_823F3E20:
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// stbx r6,r10,r7
	PPC_STORE_U8(ctx.r10.u32 + ctx.r7.u32, ctx.r6.u8);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r4,r11,r8
	ctx.r4.u64 = r11.u64 + ctx.r8.u64;
	// lbz r3,1(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r3,1(r5)
	PPC_STORE_U8(ctx.r5.u32 + 1, ctx.r3.u8);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stfs f0,4(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lbz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// blt cr6,0x823f3e20
	if (cr6.lt) goto loc_823F3E20;
	// b 0x823f3e80
	goto loc_823F3E80;
loc_823F3E7C:
	// stw r10,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r10.u32);
loc_823F3E80:
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823f3ecc
	if (cr6.eq) goto loc_823F3ECC;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823f3ecc
	if (!cr6.eq) goto loc_823F3ECC;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// bne 0x823f3ecc
	if (!cr0.eq) goto loc_823F3ECC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r31,12(r29)
	r31.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r11,12(r29)
	PPC_STORE_U8(r29.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F3EC4;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F3ECC;
	__imp__KfLowerIrql(ctx, base);
loc_823F3ECC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823F3ED8"))) PPC_WEAK_FUNC(sub_823F3ED8);
PPC_FUNC_IMPL(__imp__sub_823F3ED8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823F3EE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F3EF0;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r29,r11,-9904
	r29.s64 = r11.s64 + -9904;
	// mr r28,r13
	r28.u64 = ctx.r13.u64;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f3f18
	if (cr6.eq) goto loc_823F3F18;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r28,r9
	cr6.compare<uint32_t>(r28.u32, ctx.r9.u32, xer);
	// beq cr6,0x823f3f38
	if (cr6.eq) goto loc_823F3F38;
loc_823F3F18:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F3F20;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stw r9,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r9.u32);
	// stb r8,12(r29)
	PPC_STORE_U8(r29.u32 + 12, ctx.r8.u8);
	// b 0x823f3f3c
	goto loc_823F3F3C;
loc_823F3F38:
	// lbz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 12);
loc_823F3F3C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// beq cr6,0x823f40d4
	if (cr6.eq) goto loc_823F40D4;
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// ble cr6,0x823f4004
	if (!cr6.gt) goto loc_823F4004;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f3fb0
	if (cr6.eq) goto loc_823F3FB0;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f3fb0
	if (!cr6.eq) goto loc_823F3FB0;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// bne 0x823f3fb0
	if (!cr0.eq) goto loc_823F3FB0;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r29)
	PPC_STORE_U8(r29.u32 + 12, r11.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// bl 0x827bd544
	ctx.lr = 0x823F3F9C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F3FA4;
	__imp__KfLowerIrql(ctx, base);
	// lbz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
loc_823F3FB0:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f3ff4
	if (cr6.eq) goto loc_823F3FF4;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f3ff4
	if (!cr6.eq) goto loc_823F3FF4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// bne 0x823f3ff4
	if (!cr0.eq) goto loc_823F3FF4;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r29)
	PPC_STORE_U8(r29.u32 + 12, r11.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// bl 0x827bd544
	ctx.lr = 0x823F3FEC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F3FF4;
	__imp__KfLowerIrql(ctx, base);
loc_823F3FF4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823F4004:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f4090
	if (cr6.eq) goto loc_823F4090;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	r11.s64 = 0;
loc_823F4020:
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lbzx r6,r8,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// stbx r6,r10,r7
	PPC_STORE_U8(ctx.r10.u32 + ctx.r7.u32, ctx.r6.u8);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + r11.u64;
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lbz r3,1(r5)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// stb r3,1(r4)
	PPC_STORE_U8(ctx.r4.u32 + 1, ctx.r3.u8);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// add r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 + r11.u64;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stfs f13,8(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// lbz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// blt cr6,0x823f4020
	if (cr6.lt) goto loc_823F4020;
loc_823F4090:
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f40cc
	if (cr6.eq) goto loc_823F40CC;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lbz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
loc_823F40AC:
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x823f40c0
	if (!cr6.gt) goto loc_823F40C0;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_823F40C0:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bne 0x823f40ac
	if (!cr0.eq) goto loc_823F40AC;
loc_823F40CC:
	// stb r9,25(r31)
	PPC_STORE_U8(r31.u32 + 25, ctx.r9.u8);
	// b 0x823f40e4
	goto loc_823F40E4;
loc_823F40D4:
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// stb r10,25(r31)
	PPC_STORE_U8(r31.u32 + 25, ctx.r10.u8);
loc_823F40E4:
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823f4130
	if (cr6.eq) goto loc_823F4130;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823f4130
	if (!cr6.eq) goto loc_823F4130;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// bne 0x823f4130
	if (!cr0.eq) goto loc_823F4130;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r31,12(r29)
	r31.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r11,12(r29)
	PPC_STORE_U8(r29.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F4128;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F4130;
	__imp__KfLowerIrql(ctx, base);
loc_823F4130:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F413C"))) PPC_WEAK_FUNC(sub_823F413C);
PPC_FUNC_IMPL(__imp__sub_823F413C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4140"))) PPC_WEAK_FUNC(sub_823F4140);
PPC_FUNC_IMPL(__imp__sub_823F4140) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823F4148;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F4158;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r30,r11,-9904
	r30.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f4180
	if (cr6.eq) goto loc_823F4180;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f4198
	if (cr6.eq) goto loc_823F4198;
loc_823F4180:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F4188;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stb r27,12(r30)
	PPC_STORE_U8(r30.u32 + 12, r27.u8);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
loc_823F4198:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lbz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823f4220
	if (cr6.eq) goto loc_823F4220;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_823F41BC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lbz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 16);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bge cr6,0x823f4200
	if (!cr6.lt) goto loc_823F4200;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r8,20(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r7,r10,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lfs f13,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// b 0x823f4204
	goto loc_823F4204;
loc_823F4200:
	// stfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
loc_823F4204:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// blt cr6,0x823f41bc
	if (cr6.lt) goto loc_823F41BC;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_823F4220:
	// mr r9,r13
	ctx.r9.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f4264
	if (cr6.eq) goto loc_823F4264;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823f4264
	if (!cr6.eq) goto loc_823F4264;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// bne 0x823f4264
	if (!cr0.eq) goto loc_823F4264;
	// li r11,0
	r11.s64 = 0;
	// lbz r31,12(r30)
	r31.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r30)
	PPC_STORE_U8(r30.u32 + 12, r11.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F425C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F4264;
	__imp__KfLowerIrql(ctx, base);
loc_823F4264:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F4270"))) PPC_WEAK_FUNC(sub_823F4270);
PPC_FUNC_IMPL(__imp__sub_823F4270) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823F4278;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F428C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f42b4
	if (cr6.eq) goto loc_823F42B4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f42cc
	if (cr6.eq) goto loc_823F42CC;
loc_823F42B4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F42BC;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_823F42CC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823f4354
	if (cr6.eq) goto loc_823F4354;
	// li r8,0
	ctx.r8.s64 = 0;
loc_823F42E4:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 16);
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplw cr6,r7,r9
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, xer);
	// bge cr6,0x823f43a4
	if (!cr6.lt) goto loc_823F43A4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r9,20(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// clrlwi r7,r26,24
	ctx.r7.u64 = r26.u32 & 0xFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// beq cr6,0x823f4334
	if (cr6.eq) goto loc_823F4334;
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
loc_823F4334:
	// addi r11,r8,1
	r11.s64 = ctx.r8.s64 + 1;
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f42e4
	if (cr6.lt) goto loc_823F42E4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F4354:
	// mr r9,r13
	ctx.r9.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f4398
	if (cr6.eq) goto loc_823F4398;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823f4398
	if (!cr6.eq) goto loc_823F4398;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f4398
	if (!cr0.eq) goto loc_823F4398;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F4390;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F4398;
	__imp__KfLowerIrql(ctx, base);
loc_823F4398:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823F43A4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f43f4
	if (cr6.eq) goto loc_823F43F4;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f43f4
	if (!cr6.eq) goto loc_823F43F4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f43f4
	if (!cr0.eq) goto loc_823F43F4;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F43E8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F43F0;
	__imp__KfLowerIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F43F4:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f443c
	if (cr6.eq) goto loc_823F443C;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f443c
	if (!cr6.eq) goto loc_823F443C;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f443c
	if (!cr0.eq) goto loc_823F443C;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F4434;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F443C;
	__imp__KfLowerIrql(ctx, base);
loc_823F443C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823F444C"))) PPC_WEAK_FUNC(sub_823F444C);
PPC_FUNC_IMPL(__imp__sub_823F444C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4450"))) PPC_WEAK_FUNC(sub_823F4450);
PPC_FUNC_IMPL(__imp__sub_823F4450) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCVRegister v30{};
	PPCVRegister v31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// rlwinm r10,r7,27,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1FFFFFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f4478
	if (cr6.eq) goto loc_823F4478;
loc_823F4464:
	// rlwinm r9,r11,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r9,r3
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f4464
	if (cr6.lt) goto loc_823F4464;
loc_823F4478:
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r7,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// vaddfp128 v62,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v12,v0,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// vaddfp128 v61,v62,v63
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v63,v62,v62
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v11,v0,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v13,v0,v61
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// beq cr6,0x823f4534
	if (cr6.eq) goto loc_823F4534;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// subf r5,r4,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r4.s64;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// addi r11,r4,32
	r11.s64 = ctx.r4.s64 + 32;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// li r31,16
	r31.s64 = 16;
	// li r3,-32
	ctx.r3.s64 = -32;
	// li r4,-16
	ctx.r4.s64 = -16;
loc_823F44C8:
	// addi r8,r10,-48
	ctx.r8.s64 = ctx.r10.s64 + -48;
	// lvx128 v10,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r10,-32
	ctx.r7.s64 = ctx.r10.s64 + -32;
	// lvx128 v9,r11,r31
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r5,r11
	ctx.r6.u64 = ctx.r5.u64 + r11.u64;
	// lvx128 v8,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r11,r3
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v6,v9,v13,v10
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// lvx128 v5,r11,r4
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lvx128 v4,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v13,v13,v63
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v3,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v2,v7,v0,v4
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// lvx128 v1,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v31,v5,v12,v3
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v30,v8,v11,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// vaddfp128 v0,v0,v63
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v12,v12,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v11,v11,v63
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v6,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// stvx128 v2,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v31,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x823f44c8
	if (!cr0.eq) goto loc_823F44C8;
loc_823F4534:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F453C"))) PPC_WEAK_FUNC(sub_823F453C);
PPC_FUNC_IMPL(__imp__sub_823F453C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4540"))) PPC_WEAK_FUNC(sub_823F4540);
PPC_FUNC_IMPL(__imp__sub_823F4540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r11,-3792
	ctx.r8.s64 = r11.s64 + -3792;
	// addi r7,r10,-3824
	ctx.r7.s64 = ctx.r10.s64 + -3824;
	// addi r6,r9,-4364
	ctx.r6.s64 = ctx.r9.s64 + -4364;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F456C"))) PPC_WEAK_FUNC(sub_823F456C);
PPC_FUNC_IMPL(__imp__sub_823F456C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4570"))) PPC_WEAK_FUNC(sub_823F4570);
PPC_FUNC_IMPL(__imp__sub_823F4570) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823F4578;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r3,r29,-8
	ctx.r3.s64 = r29.s64 + -8;
	// bne cr6,0x823f45a0
	if (!cr6.eq) goto loc_823F45A0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823F45A0:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x823eaed0
	ctx.lr = 0x823F45A8;
	sub_823EAED0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f48e0
	if (cr6.lt) goto loc_823F48E0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// addi r31,r28,-8
	r31.s64 = r28.s64 + -8;
	// bne cr6,0x823f45c0
	if (!cr6.eq) goto loc_823F45C0;
	// li r31,0
	r31.s64 = 0;
loc_823F45C0:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaed0
	ctx.lr = 0x823F45CC;
	sub_823EAED0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f48e0
	if (cr6.lt) goto loc_823F48E0;
	// lbz r11,26(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 26);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x823f45f8
	if (!cr6.eq) goto loc_823F45F8;
	// lbz r11,25(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 25);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r11.u8);
	// bl 0x823eb050
	ctx.lr = 0x823F45F8;
	sub_823EB050(ctx, base);
loc_823F45F8:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f48e0
	if (cr6.lt) goto loc_823F48E0;
	// bl 0x827bd514
	ctx.lr = 0x823F4604;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r26,r11,-9904
	r26.s64 = r11.s64 + -9904;
	// mr r31,r13
	r31.u64 = ctx.r13.u64;
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f462c
	if (cr6.eq) goto loc_823F462C;
	// lwz r10,8(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f4640
	if (cr6.eq) goto loc_823F4640;
loc_823F462C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F4634;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// stw r31,8(r26)
	PPC_STORE_U32(r26.u32 + 8, r31.u32);
	// stb r30,12(r26)
	PPC_STORE_U8(r26.u32 + 12, r30.u8);
loc_823F4640:
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4(r26)
	PPC_STORE_U32(r26.u32 + 4, ctx.r10.u32);
	// lbz r11,16(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f4798
	if (cr6.eq) goto loc_823F4798;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lfs f30,12428(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	f30.f64 = double(temp.f32);
	// addi r29,r11,-3840
	r29.s64 = r11.s64 + -3840;
	// lfs f31,-32720(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -32720);
	f31.f64 = double(temp.f32);
loc_823F4674:
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r6,97(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// lwz r7,120(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lbz r5,1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lfs f13,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r10,r5,10
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 10);
	// rotlwi r9,r11,10
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 10);
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 + ctx.r7.u64;
	// cmplw cr6,r5,r6
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, xer);
	// bge cr6,0x823f4780
	if (!cr6.lt) goto loc_823F4780;
	// lbz r8,113(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 113);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bge cr6,0x823f4768
	if (!cr6.lt) goto loc_823F4768;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lvlx128 v63,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v0,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lbz r8,26(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 26);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// fmuls f0,f12,f31
	f0.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// fmuls f11,f0,f30
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(f0.f64 * f30.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x823f4734
	if (!cr6.eq) goto loc_823F4734;
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x823f4450
	ctx.lr = 0x823F472C;
	sub_823F4450(ctx, base);
	// stfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// b 0x823f4780
	goto loc_823F4780;
loc_823F4734:
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,64
	r11.s64 = 64;
loc_823F473C:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v60,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vaddfp128 v0,v0,v63
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x823f473c
	if (!cr0.eq) goto loc_823F473C;
	// stfs f13,0(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// b 0x823f4780
	goto loc_823F4780;
loc_823F4768:
	// lbz r11,26(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 26);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f4780
	if (cr6.eq) goto loc_823F4780;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x823F4780;
	sub_8244D150(ctx, base);
loc_823F4780:
	// lbz r11,16(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 16);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x823f4674
	if (cr6.lt) goto loc_823F4674;
	// b 0x823f4890
	goto loc_823F4890;
loc_823F4798:
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// beq cr6,0x823f4894
	if (cr6.eq) goto loc_823F4894;
	// lbz r8,97(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// li r30,0
	r30.s64 = 0;
	// lbz r9,113(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 113);
	// lwz r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// beq cr6,0x823f4894
	if (cr6.eq) goto loc_823F4894;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r11,-3840
	r29.s64 = r11.s64 + -3840;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
loc_823F47D8:
	// lbz r11,26(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 26);
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// bge cr6,0x823f4854
	if (!cr6.lt) goto loc_823F4854;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f4848
	if (!cr6.eq) goto loc_823F4848;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f30,80(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v0,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
	// lvlx128 v57,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r7,256
	ctx.r7.s64 = 256;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvlx128 v58,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvlx128 v56,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v55,v57,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v13,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// vmaddfp v11,v13,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823f4450
	ctx.lr = 0x823F4844;
	sub_823F4450(ctx, base);
	// b 0x823f4868
	goto loc_823F4868;
loc_823F4848:
	// li r5,1024
	ctx.r5.s64 = 1024;
	// bl 0x8244d5c0
	ctx.lr = 0x823F4850;
	sub_8244D5C0(ctx, base);
	// b 0x823f4868
	goto loc_823F4868;
loc_823F4854:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f4890
	if (cr6.eq) goto loc_823F4890;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x823F4868;
	sub_8244D150(ctx, base);
loc_823F4868:
	// lbz r8,97(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// addi r31,r31,1024
	r31.s64 = r31.s64 + 1024;
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lbz r9,113(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 113);
	// add r4,r31,r11
	ctx.r4.u64 = r31.u64 + r11.u64;
	// add r3,r31,r10
	ctx.r3.u64 = r31.u64 + ctx.r10.u64;
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// blt cr6,0x823f47d8
	if (cr6.lt) goto loc_823F47D8;
loc_823F4890:
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
loc_823F4894:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f48dc
	if (cr6.eq) goto loc_823F48DC;
	// lwz r9,8(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f48dc
	if (!cr6.eq) goto loc_823F48DC;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r11.u32);
	// bne 0x823f48dc
	if (!cr0.eq) goto loc_823F48DC;
	// li r11,0
	r11.s64 = 0;
	// lbz r31,12(r26)
	r31.u64 = PPC_LOAD_U8(r26.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r26)
	PPC_STORE_U8(r26.u32 + 12, r11.u8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r10,8(r26)
	PPC_STORE_U32(r26.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F48D4;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F48DC;
	__imp__KfLowerIrql(ctx, base);
loc_823F48DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823F48E0:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823F48F0"))) PPC_WEAK_FUNC(sub_823F48F0);
PPC_FUNC_IMPL(__imp__sub_823F48F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f4918
	if (cr6.eq) goto loc_823F4918;
	// lbz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bgt cr6,0x823f4918
	if (cr6.gt) goto loc_823F4918;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_823F4918:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r11,r11,1,23,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1FE;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,28
	ctx.r10.s64 = r11.s64 + 28;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4938"))) PPC_WEAK_FUNC(sub_823F4938);
PPC_FUNC_IMPL(__imp__sub_823F4938) {
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
	ctx.lr = 0x823F4940;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r4,28
	ctx.r4.s64 = 28;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F4968;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823f49dc
	if (cr6.eq) goto loc_823F49DC;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r6,r8,-3792
	ctx.r6.s64 = ctx.r8.s64 + -3792;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-4052
	ctx.r9.s64 = r11.s64 + -4052;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// rotlwi r11,r6,0
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// addi r4,r7,-3824
	ctx.r4.s64 = ctx.r7.s64 + -3824;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F49C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x823f49ec
	if (cr6.lt) goto loc_823F49EC;
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823F49DC:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823F49EC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F4A00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F4A0C"))) PPC_WEAK_FUNC(sub_823F4A0C);
PPC_FUNC_IMPL(__imp__sub_823F4A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4A10"))) PPC_WEAK_FUNC(sub_823F4A10);
PPC_FUNC_IMPL(__imp__sub_823F4A10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// addi r3,r10,12
	ctx.r3.s64 = ctx.r10.s64 + 12;
	// lwz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// stw r9,172(r10)
	PPC_STORE_U32(ctx.r10.u32 + 172, ctx.r9.u32);
	// lwz r8,76(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stw r8,176(r10)
	PPC_STORE_U32(ctx.r10.u32 + 176, ctx.r8.u32);
	// lbz r6,69(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 69);
	// lbz r5,68(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 68);
	// b 0x823f9d08
	sub_823F9D08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F4A40"))) PPC_WEAK_FUNC(sub_823F4A40);
PPC_FUNC_IMPL(__imp__sub_823F4A40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x823f4aa4
	if (!cr6.eq) goto loc_823F4AA4;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x823f4aa4
	if (!cr6.eq) goto loc_823F4AA4;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,56
	cr6.compare<uint32_t>(r11.u32, 56, xer);
	// bne cr6,0x823f4a80
	if (!cr6.eq) goto loc_823F4A80;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4A80:
	// cmplwi cr6,r11,60
	cr6.compare<uint32_t>(r11.u32, 60, xer);
	// bne cr6,0x823f4b28
	if (!cr6.eq) goto loc_823F4B28;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r5,r4,56
	ctx.r5.s64 = ctx.r4.s64 + 56;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4AA4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f4ad0
	if (!cr6.eq) goto loc_823F4AD0;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x823f4ad0
	if (!cr6.eq) goto loc_823F4AD0;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4AD0:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x823f4afc
	if (!cr6.eq) goto loc_823F4AFC;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x823f4afc
	if (!cr6.eq) goto loc_823F4AFC;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4AFC:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x823f4b28
	if (!cr6.eq) goto loc_823F4B28;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x823f4b28
	if (!cr6.eq) goto loc_823F4B28;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4B28:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4B34"))) PPC_WEAK_FUNC(sub_823F4B34);
PPC_FUNC_IMPL(__imp__sub_823F4B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4B38"))) PPC_WEAK_FUNC(sub_823F4B38);
PPC_FUNC_IMPL(__imp__sub_823F4B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x823f4b9c
	if (!cr6.eq) goto loc_823F4B9C;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x823f4b9c
	if (!cr6.eq) goto loc_823F4B9C;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,56
	cr6.compare<uint32_t>(r11.u32, 56, xer);
	// bne cr6,0x823f4b78
	if (!cr6.eq) goto loc_823F4B78;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4B78:
	// cmplwi cr6,r11,60
	cr6.compare<uint32_t>(r11.u32, 60, xer);
	// bne cr6,0x823f4c20
	if (!cr6.eq) goto loc_823F4C20;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r5,56(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 56);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4B9C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f4bc8
	if (!cr6.eq) goto loc_823F4BC8;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x823f4bc8
	if (!cr6.eq) goto loc_823F4BC8;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lfs f1,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4BC8:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x823f4bf4
	if (!cr6.eq) goto loc_823F4BF4;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x823f4bf4
	if (!cr6.eq) goto loc_823F4BF4;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lfs f1,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4BF4:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x823f4c20
	if (!cr6.eq) goto loc_823F4C20;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x823f4c20
	if (!cr6.eq) goto loc_823F4C20;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// lfs f1,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_823F4C20:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4C2C"))) PPC_WEAK_FUNC(sub_823F4C2C);
PPC_FUNC_IMPL(__imp__sub_823F4C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4C30"))) PPC_WEAK_FUNC(sub_823F4C30);
PPC_FUNC_IMPL(__imp__sub_823F4C30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x823f4c40
	if (cr6.gt) goto loc_823F4C40;
	// b 0x823fde30
	sub_823FDE30(ctx, base);
	return;
loc_823F4C40:
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x823f4c4c
	if (!cr6.eq) goto loc_823F4C4C;
	// b 0x823fb938
	sub_823FB938(ctx, base);
	return;
loc_823F4C4C:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4C58"))) PPC_WEAK_FUNC(sub_823F4C58);
PPC_FUNC_IMPL(__imp__sub_823F4C58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x823f4c68
	if (cr6.gt) goto loc_823F4C68;
	// b 0x823fe678
	sub_823FE678(ctx, base);
	return;
loc_823F4C68:
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x823f4c74
	if (!cr6.eq) goto loc_823F4C74;
	// b 0x823fd4c0
	sub_823FD4C0(ctx, base);
	return;
loc_823F4C74:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4C80"))) PPC_WEAK_FUNC(sub_823F4C80);
PPC_FUNC_IMPL(__imp__sub_823F4C80) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-4052
	ctx.r9.s64 = r11.s64 + -4052;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// bl 0x823f9cb0
	ctx.lr = 0x823F4CB8;
	sub_823F9CB0(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r5,r7,-3632
	ctx.r5.s64 = ctx.r7.s64 + -3632;
	// addi r4,r6,-3728
	ctx.r4.s64 = ctx.r6.s64 + -3728;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r4.u32);
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

__attribute__((alias("__imp__sub_823F4CE8"))) PPC_WEAK_FUNC(sub_823F4CE8);
PPC_FUNC_IMPL(__imp__sub_823F4CE8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x823f5518
	sub_823F5518(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F4CF0"))) PPC_WEAK_FUNC(sub_823F4CF0);
PPC_FUNC_IMPL(__imp__sub_823F4CF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,156(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 156);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4D00"))) PPC_WEAK_FUNC(sub_823F4D00);
PPC_FUNC_IMPL(__imp__sub_823F4D00) {
	PPC_FUNC_PROLOGUE();
	// b 0x823f9d70
	sub_823F9D70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F4D04"))) PPC_WEAK_FUNC(sub_823F4D04);
PPC_FUNC_IMPL(__imp__sub_823F4D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4D08"))) PPC_WEAK_FUNC(sub_823F4D08);
PPC_FUNC_IMPL(__imp__sub_823F4D08) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F4D30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f4d44
	if (cr6.lt) goto loc_823F4D44;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823F4D44:
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

__attribute__((alias("__imp__sub_823F4D58"))) PPC_WEAK_FUNC(sub_823F4D58);
PPC_FUNC_IMPL(__imp__sub_823F4D58) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F4D80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f4d90
	if (cr6.lt) goto loc_823F4D90;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
loc_823F4D90:
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

__attribute__((alias("__imp__sub_823F4DA4"))) PPC_WEAK_FUNC(sub_823F4DA4);
PPC_FUNC_IMPL(__imp__sub_823F4DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4DA8"))) PPC_WEAK_FUNC(sub_823F4DA8);
PPC_FUNC_IMPL(__imp__sub_823F4DA8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F4DD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f4de4
	if (cr6.lt) goto loc_823F4DE4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823F4DE4:
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

__attribute__((alias("__imp__sub_823F4DF8"))) PPC_WEAK_FUNC(sub_823F4DF8);
PPC_FUNC_IMPL(__imp__sub_823F4DF8) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f4e2c
	if (cr6.eq) goto loc_823F4E2C;
	// addi r4,r31,36
	ctx.r4.s64 = r31.s64 + 36;
	// li r5,56
	ctx.r5.s64 = 56;
	// bl 0x823da950
	ctx.lr = 0x823F4E2C;
	sub_823DA950(ctx, base);
loc_823F4E2C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq cr6,0x823f4e40
	if (cr6.eq) goto loc_823F4E40;
	// lbz r11,157(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 157);
	// stb r11,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r11.u8);
loc_823F4E40:
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

__attribute__((alias("__imp__sub_823F4E58"))) PPC_WEAK_FUNC(sub_823F4E58);
PPC_FUNC_IMPL(__imp__sub_823F4E58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,96(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4E68"))) PPC_WEAK_FUNC(sub_823F4E68);
PPC_FUNC_IMPL(__imp__sub_823F4E68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,96(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4E74"))) PPC_WEAK_FUNC(sub_823F4E74);
PPC_FUNC_IMPL(__imp__sub_823F4E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4E78"))) PPC_WEAK_FUNC(sub_823F4E78);
PPC_FUNC_IMPL(__imp__sub_823F4E78) {
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
	// lfs f1,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x823db788
	ctx.lr = 0x823F4E94;
	sub_823DB788(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,-22768(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -22768);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,0(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_823F4EC0"))) PPC_WEAK_FUNC(sub_823F4EC0);
PPC_FUNC_IMPL(__imp__sub_823F4EC0) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfd f1,-32664(r11)
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + -32664);
	// bl 0x823dc480
	ctx.lr = 0x823F4EE4;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
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

__attribute__((alias("__imp__sub_823F4F04"))) PPC_WEAK_FUNC(sub_823F4F04);
PPC_FUNC_IMPL(__imp__sub_823F4F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4F08"))) PPC_WEAK_FUNC(sub_823F4F08);
PPC_FUNC_IMPL(__imp__sub_823F4F08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4F18"))) PPC_WEAK_FUNC(sub_823F4F18);
PPC_FUNC_IMPL(__imp__sub_823F4F18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4F24"))) PPC_WEAK_FUNC(sub_823F4F24);
PPC_FUNC_IMPL(__imp__sub_823F4F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4F28"))) PPC_WEAK_FUNC(sub_823F4F28);
PPC_FUNC_IMPL(__imp__sub_823F4F28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r10,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r10.u8);
	// lhz r11,168(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 168);
	// sth r11,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4F44"))) PPC_WEAK_FUNC(sub_823F4F44);
PPC_FUNC_IMPL(__imp__sub_823F4F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4F48"))) PPC_WEAK_FUNC(sub_823F4F48);
PPC_FUNC_IMPL(__imp__sub_823F4F48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823f4f5c
	if (cr6.eq) goto loc_823F4F5C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// b 0x823f4f60
	goto loc_823F4F60;
loc_823F4F5C:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_823F4F60:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823f4f70
	if (cr6.eq) goto loc_823F4F70;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823f4f74
	goto loc_823F4F74;
loc_823F4F70:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_823F4F74:
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x823f4f88
	if (cr6.eq) goto loc_823F4F88;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// blr 
	return;
loc_823F4F88:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F4F90"))) PPC_WEAK_FUNC(sub_823F4F90);
PPC_FUNC_IMPL(__imp__sub_823F4F90) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,-3632
	ctx.r9.s64 = r11.s64 + -3632;
	// addi r8,r10,-3728
	ctx.r8.s64 = ctx.r10.s64 + -3728;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// bl 0x823f9cf0
	ctx.lr = 0x823F4FC4;
	sub_823F9CF0(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// addi r6,r7,-4364
	ctx.r6.s64 = ctx.r7.s64 + -4364;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_823F4FE4"))) PPC_WEAK_FUNC(sub_823F4FE4);
PPC_FUNC_IMPL(__imp__sub_823F4FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F4FE8"))) PPC_WEAK_FUNC(sub_823F4FE8);
PPC_FUNC_IMPL(__imp__sub_823F4FE8) {
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
	ctx.lr = 0x823F4FF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F5000;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f5028
	if (cr6.eq) goto loc_823F5028;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823f5044
	if (cr6.eq) goto loc_823F5044;
loc_823F5028:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F5030;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// b 0x823f5048
	goto loc_823F5048;
loc_823F5044:
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823F5048:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r28,4
	r11.s64 = r28.s64 + 4;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x823f5070
	if (cr6.eq) goto loc_823F5070;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f50c0
	if (!cr6.eq) goto loc_823F50C0;
loc_823F5070:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f50b0
	if (cr6.eq) goto loc_823F50B0;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823f50b0
	if (!cr6.eq) goto loc_823F50B0;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f50b0
	if (!cr0.eq) goto loc_823F50B0;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F50A8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F50B0;
	__imp__KfLowerIrql(ctx, base);
loc_823F50B0:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823F50C0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823f50d8
	if (cr6.eq) goto loc_823F50D8;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lbz r29,12(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
loc_823F50D8:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f5118
	if (cr6.eq) goto loc_823F5118;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823f5118
	if (!cr6.eq) goto loc_823F5118;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f5118
	if (!cr0.eq) goto loc_823F5118;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F5110;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F5118;
	__imp__KfLowerIrql(ctx, base);
loc_823F5118:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F5124"))) PPC_WEAK_FUNC(sub_823F5124);
PPC_FUNC_IMPL(__imp__sub_823F5124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5128"))) PPC_WEAK_FUNC(sub_823F5128);
PPC_FUNC_IMPL(__imp__sub_823F5128) {
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
	ctx.lr = 0x823F5130;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F5144;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f516c
	if (cr6.eq) goto loc_823F516C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f5180
	if (cr6.eq) goto loc_823F5180;
loc_823F516C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F5174;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r26,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r26.u8);
loc_823F5180:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// clrlwi r9,r27,24
	ctx.r9.u64 = r27.u32 & 0xFF;
	// lbz r8,156(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 156);
	// andc r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 & ~ctx.r10.u64;
	// or r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 | ctx.r9.u64;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stb r6,156(r30)
	PPC_STORE_U8(r30.u32 + 156, ctx.r6.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f51ec
	if (cr6.eq) goto loc_823F51EC;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f51ec
	if (!cr6.eq) goto loc_823F51EC;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f51ec
	if (!cr0.eq) goto loc_823F51EC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F51E4;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F51EC;
	__imp__KfLowerIrql(ctx, base);
loc_823F51EC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823F51F4"))) PPC_WEAK_FUNC(sub_823F51F4);
PPC_FUNC_IMPL(__imp__sub_823F51F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F51F8"))) PPC_WEAK_FUNC(sub_823F51F8);
PPC_FUNC_IMPL(__imp__sub_823F51F8) {
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
	ctx.lr = 0x823F5200;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F520C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f5234
	if (cr6.eq) goto loc_823F5234;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f5248
	if (cr6.eq) goto loc_823F5248;
loc_823F5234:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F523C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823F5248:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r10,156(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 156);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823f526c
	if (!cr6.eq) goto loc_823F526C;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x823f5280
	goto loc_823F5280;
loc_823F526C:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f5298
	if (cr6.eq) goto loc_823F5298;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,6
	ctx.r4.s64 = 6;
loc_823F5280:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F5294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F5298:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f52e0
	if (cr6.eq) goto loc_823F52E0;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f52e0
	if (!cr6.eq) goto loc_823F52E0;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f52e0
	if (!cr0.eq) goto loc_823F52E0;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F52D8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F52E0;
	__imp__KfLowerIrql(ctx, base);
loc_823F52E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F52EC"))) PPC_WEAK_FUNC(sub_823F52EC);
PPC_FUNC_IMPL(__imp__sub_823F52EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F52F0"))) PPC_WEAK_FUNC(sub_823F52F0);
PPC_FUNC_IMPL(__imp__sub_823F52F0) {
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
	ctx.lr = 0x823F52F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F5308;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r29,r13
	r29.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f5330
	if (cr6.eq) goto loc_823F5330;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f5344
	if (cr6.eq) goto loc_823F5344;
loc_823F5330:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F5338;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823F5344:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r10,156(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 156);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823f53d0
	if (cr6.eq) goto loc_823F53D0;
	// clrlwi r9,r27,31
	ctx.r9.u64 = r27.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823f53b0
	if (!cr6.eq) goto loc_823F53B0;
	// rlwinm r9,r10,0,27,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1E;
	// rlwinm r9,r9,0,30,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823f53b0
	if (!cr6.eq) goto loc_823F53B0;
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823f53d0
	if (!cr6.eq) goto loc_823F53D0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F53A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lhz r11,168(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 168);
	// sth r11,158(r30)
	PPC_STORE_U16(r30.u32 + 158, r11.u16);
	// b 0x823f53cc
	goto loc_823F53CC;
loc_823F53B0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,87
	ctx.r4.s64 = 87;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F53CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F53CC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F53D0:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f5418
	if (cr6.eq) goto loc_823F5418;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f5418
	if (!cr6.eq) goto loc_823F5418;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f5418
	if (!cr0.eq) goto loc_823F5418;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F5410;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F5418;
	__imp__KfLowerIrql(ctx, base);
loc_823F5418:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F5424"))) PPC_WEAK_FUNC(sub_823F5424);
PPC_FUNC_IMPL(__imp__sub_823F5424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5428"))) PPC_WEAK_FUNC(sub_823F5428);
PPC_FUNC_IMPL(__imp__sub_823F5428) {
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
	ctx.lr = 0x823F5430;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F543C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f5464
	if (cr6.eq) goto loc_823F5464;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823f547c
	if (cr6.eq) goto loc_823F547C;
loc_823F5464:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F546C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
loc_823F547C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r29,4
	r11.s64 = r29.s64 + 4;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x823f54c8
	if (cr6.eq) goto loc_823F54C8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823f54c8
	if (cr6.eq) goto loc_823F54C8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F54C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F54C8:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f550c
	if (cr6.eq) goto loc_823F550C;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823f550c
	if (!cr6.eq) goto loc_823F550C;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f550c
	if (!cr0.eq) goto loc_823F550C;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F5504;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F550C;
	__imp__KfLowerIrql(ctx, base);
loc_823F550C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F5518"))) PPC_WEAK_FUNC(sub_823F5518);
PPC_FUNC_IMPL(__imp__sub_823F5518) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,-3632
	ctx.r9.s64 = r11.s64 + -3632;
	// addi r8,r10,-3728
	ctx.r8.s64 = ctx.r10.s64 + -3728;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823f9cf0
	ctx.lr = 0x823F5554;
	sub_823F9CF0(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// clrlwi r6,r30,31
	ctx.r6.u64 = r30.u32 & 0x1;
	// addi r5,r7,-4364
	ctx.r5.s64 = ctx.r7.s64 + -4364;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// beq cr6,0x823f5580
	if (cr6.eq) goto loc_823F5580;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823F5580;
	sub_823EF7C8(ctx, base);
loc_823F5580:
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

__attribute__((alias("__imp__sub_823F559C"))) PPC_WEAK_FUNC(sub_823F559C);
PPC_FUNC_IMPL(__imp__sub_823F559C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F55A0"))) PPC_WEAK_FUNC(sub_823F55A0);
PPC_FUNC_IMPL(__imp__sub_823F55A0) {
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
	ctx.lr = 0x823F55A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x823fa7c0
	ctx.lr = 0x823F55B8;
	sub_823FA7C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823f55f0
	if (cr6.eq) goto loc_823F55F0;
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f55f0
	if (cr6.eq) goto loc_823F55F0;
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823F55F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F55F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F55FC"))) PPC_WEAK_FUNC(sub_823F55FC);
PPC_FUNC_IMPL(__imp__sub_823F55FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5600"))) PPC_WEAK_FUNC(sub_823F5600);
PPC_FUNC_IMPL(__imp__sub_823F5600) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r10,r11,-3592
	ctx.r10.s64 = r11.s64 + -3592;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823f7468
	ctx.lr = 0x823F5628;
	sub_823F7468(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f5654
	if (cr6.eq) goto loc_823F5654;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823F564C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r8.u32);
loc_823F5654:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f6d48
	ctx.lr = 0x823F565C;
	sub_823F6D48(ctx, base);
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

__attribute__((alias("__imp__sub_823F5670"))) PPC_WEAK_FUNC(sub_823F5670);
PPC_FUNC_IMPL(__imp__sub_823F5670) {
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
	// bl 0x823f7960
	ctx.lr = 0x823F5690;
	sub_823F7960(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f56b4
	if (cr6.lt) goto loc_823F56B4;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F56B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F56B4:
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

__attribute__((alias("__imp__sub_823F56CC"))) PPC_WEAK_FUNC(sub_823F56CC);
PPC_FUNC_IMPL(__imp__sub_823F56CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F56D0"))) PPC_WEAK_FUNC(sub_823F56D0);
PPC_FUNC_IMPL(__imp__sub_823F56D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-9796(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// b 0x823eca40
	sub_823ECA40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F56DC"))) PPC_WEAK_FUNC(sub_823F56DC);
PPC_FUNC_IMPL(__imp__sub_823F56DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F56E0"))) PPC_WEAK_FUNC(sub_823F56E0);
PPC_FUNC_IMPL(__imp__sub_823F56E0) {
	PPC_FUNC_PROLOGUE();
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16385
	ctx.r3.u64 = ctx.r3.u64 | 16385;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F56EC"))) PPC_WEAK_FUNC(sub_823F56EC);
PPC_FUNC_IMPL(__imp__sub_823F56EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F56F0"))) PPC_WEAK_FUNC(sub_823F56F0);
PPC_FUNC_IMPL(__imp__sub_823F56F0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F5724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x823f5754
	if (cr6.lt) goto loc_823F5754;
	// beq cr6,0x823f5740
	if (cr6.eq) goto loc_823F5740;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823f5758
	goto loc_823F5758;
loc_823F5740:
	// lbz r11,76(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// lwz r10,124(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// mulli r11,r11,44
	r11.s64 = r11.s64 * 44;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x823f5758
	goto loc_823F5758;
loc_823F5754:
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
loc_823F5758:
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

__attribute__((alias("__imp__sub_823F5770"))) PPC_WEAK_FUNC(sub_823F5770);
PPC_FUNC_IMPL(__imp__sub_823F5770) {
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
	// bl 0x823f5600
	ctx.lr = 0x823F5788;
	sub_823F5600(ctx, base);
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

__attribute__((alias("__imp__sub_823F57A0"))) PPC_WEAK_FUNC(sub_823F57A0);
PPC_FUNC_IMPL(__imp__sub_823F57A0) {
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
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r30,0
	r30.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r9,6
	ctx.r9.s64 = 6;
	// ori r8,r10,48000
	ctx.r8.u64 = ctx.r10.u64 | 48000;
	// std r30,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r30.u64);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r30,8(r11)
	PPC_STORE_U64(r11.u32 + 8, r30.u64);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// std r30,16(r11)
	PPC_STORE_U64(r11.u32 + 16, r30.u64);
	// stb r30,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r30.u8);
	// stb r9,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r9.u8);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// beq cr6,0x823f5804
	if (cr6.eq) goto loc_823F5804;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
loc_823F5804:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f7828
	ctx.lr = 0x823F5810;
	sub_823F7828(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f58b0
	if (cr6.lt) goto loc_823F58B0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r4,28
	ctx.r4.s64 = 28;
	// std r30,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r30.u64);
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823F5848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f5860
	if (cr6.eq) goto loc_823F5860;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x823f39a8
	ctx.lr = 0x823F585C;
	sub_823F39A8(ctx, base);
	// b 0x823f5864
	goto loc_823F5864;
loc_823F5860:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823F5864:
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823f587c
	if (!cr6.eq) goto loc_823F587C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x823f58b0
	goto loc_823F58B0;
loc_823F587C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F5894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f58b0
	if (cr6.lt) goto loc_823F58B0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F58B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F58B0:
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

__attribute__((alias("__imp__sub_823F58C8"))) PPC_WEAK_FUNC(sub_823F58C8);
PPC_FUNC_IMPL(__imp__sub_823F58C8) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823f6b78
	ctx.lr = 0x823F58E4;
	sub_823F6B78(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x823f5900
	if (cr6.lt) goto loc_823F5900;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823eb1d0
	ctx.lr = 0x823F5900;
	sub_823EB1D0(ctx, base);
loc_823F5900:
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

__attribute__((alias("__imp__sub_823F591C"))) PPC_WEAK_FUNC(sub_823F591C);
PPC_FUNC_IMPL(__imp__sub_823F591C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5920"))) PPC_WEAK_FUNC(sub_823F5920);
PPC_FUNC_IMPL(__imp__sub_823F5920) {
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
	// lbz r11,61(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 61);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f595c
	if (cr6.eq) goto loc_823F595C;
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
loc_823F595C:
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823eb1d0
	ctx.lr = 0x823F596C;
	sub_823EB1D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f7240
	ctx.lr = 0x823F5974;
	sub_823F7240(ctx, base);
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

__attribute__((alias("__imp__sub_823F5988"))) PPC_WEAK_FUNC(sub_823F5988);
PPC_FUNC_IMPL(__imp__sub_823F5988) {
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
	ctx.lr = 0x823F5990;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F599C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f59c4
	if (cr6.eq) goto loc_823F59C4;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823f59dc
	if (cr6.eq) goto loc_823F59DC;
loc_823F59C4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F59CC;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
loc_823F59DC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r28,24
	r11.s64 = r28.s64 + 24;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x823f5a18
	if (cr6.eq) goto loc_823F5A18;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F5A18:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f5a5c
	if (cr6.eq) goto loc_823F5A5C;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823f5a5c
	if (!cr6.eq) goto loc_823F5A5C;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f5a5c
	if (!cr0.eq) goto loc_823F5A5C;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F5A54;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F5A5C;
	__imp__KfLowerIrql(ctx, base);
loc_823F5A5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F5A68"))) PPC_WEAK_FUNC(sub_823F5A68);
PPC_FUNC_IMPL(__imp__sub_823F5A68) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r11,0
	r11.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r8,6
	ctx.r8.s64 = 6;
	// ori r7,r9,48000
	ctx.r7.u64 = ctx.r9.u64 | 48000;
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// std r11,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r11.u64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// std r11,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, r11.u64);
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r11.u8);
	// stb r8,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r8.u8);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// beq cr6,0x823f5ac8
	if (cr6.eq) goto loc_823F5AC8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
loc_823F5AC8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823f6c60
	ctx.lr = 0x823F5AD4;
	sub_823F6C60(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f5ae8
	if (cr6.lt) goto loc_823F5AE8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,28
	ctx.r10.s64 = r11.s64 + 28;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823F5AE8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F5AFC"))) PPC_WEAK_FUNC(sub_823F5AFC);
PPC_FUNC_IMPL(__imp__sub_823F5AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5B00"))) PPC_WEAK_FUNC(sub_823F5B00);
PPC_FUNC_IMPL(__imp__sub_823F5B00) {
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
	ctx.lr = 0x823F5B08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-9796(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// bl 0x823f56f0
	ctx.lr = 0x823F5B20;
	sub_823F56F0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823f5be4
	if (cr6.eq) goto loc_823F5BE4;
	// bl 0x827bd514
	ctx.lr = 0x823F5B30;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f5b58
	if (cr6.eq) goto loc_823F5B58;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f5b6c
	if (cr6.eq) goto loc_823F5B6C;
loc_823F5B58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F5B60;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F5B6C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r9,40(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f5be4
	if (cr6.eq) goto loc_823F5BE4;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f5be4
	if (!cr6.eq) goto loc_823F5BE4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f5be4
	if (!cr0.eq) goto loc_823F5BE4;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F5BDC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F5BE4;
	__imp__KfLowerIrql(ctx, base);
loc_823F5BE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F5BF0"))) PPC_WEAK_FUNC(sub_823F5BF0);
PPC_FUNC_IMPL(__imp__sub_823F5BF0) {
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
	ctx.lr = 0x823F5BF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823f5a68
	ctx.lr = 0x823F5C14;
	sub_823F5A68(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f5c28
	if (cr6.lt) goto loc_823F5C28;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r4,r11,72
	ctx.r4.s64 = r11.s64 + 72;
	// b 0x823f5c2c
	goto loc_823F5C2C;
loc_823F5C28:
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_823F5C2C:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f5cd0
	if (cr6.lt) goto loc_823F5CD0;
	// lis r3,24962
	ctx.r3.s64 = 1635909632;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r3,r3,6
	ctx.r3.u64 = ctx.r3.u64 | 6;
	// bl 0x823f6188
	ctx.lr = 0x823F5C48;
	sub_823F6188(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823f5cd0
	if (cr6.lt) goto loc_823F5CD0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,72
	ctx.r4.s64 = 72;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F5C6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823f5cb0
	if (cr6.eq) goto loc_823F5CB0;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x823f6fb0
	ctx.lr = 0x823F5C84;
	sub_823F6FB0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r10,r11,-3592
	ctx.r10.s64 = r11.s64 + -3592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823f57a0
	ctx.lr = 0x823F5C9C;
	sub_823F57A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x823f5cbc
	if (cr6.lt) goto loc_823F5CBC;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// b 0x823f5cd0
	goto loc_823F5CD0;
loc_823F5CB0:
	// lis r30,-32761
	r30.s64 = -2147024896;
	// ori r30,r30,14
	r30.u64 = r30.u64 | 14;
	// b 0x823f5cd0
	goto loc_823F5CD0;
loc_823F5CBC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F5CD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F5CD0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f5cec
	if (cr6.eq) goto loc_823F5CEC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F5CEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F5CEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F5CF8"))) PPC_WEAK_FUNC(sub_823F5CF8);
PPC_FUNC_IMPL(__imp__sub_823F5CF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,3
	r11.s64 = ctx.r4.s64 + 3;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F5D10"))) PPC_WEAK_FUNC(sub_823F5D10);
PPC_FUNC_IMPL(__imp__sub_823F5D10) {
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
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x823f5d4c
	if (!cr6.eq) goto loc_823F5D4C;
loc_823F5D34:
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
loc_823F5D4C:
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// bl 0x823ef7b8
	ctx.lr = 0x823F5D5C;
	sub_823EF7B8(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823f5d34
	if (!cr6.eq) goto loc_823F5D34;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
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

__attribute__((alias("__imp__sub_823F5D84"))) PPC_WEAK_FUNC(sub_823F5D84);
PPC_FUNC_IMPL(__imp__sub_823F5D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5D88"))) PPC_WEAK_FUNC(sub_823F5D88);
PPC_FUNC_IMPL(__imp__sub_823F5D88) {
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
	// addi r10,r4,3
	ctx.r10.s64 = ctx.r4.s64 + 3;
	// rlwinm r30,r10,0,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823F5DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// ble cr6,0x823f5dc8
	if (!cr6.gt) goto loc_823F5DC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823f5ddc
	goto loc_823F5DDC;
loc_823F5DC8:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
loc_823F5DDC:
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

__attribute__((alias("__imp__sub_823F5DF4"))) PPC_WEAK_FUNC(sub_823F5DF4);
PPC_FUNC_IMPL(__imp__sub_823F5DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5DF8"))) PPC_WEAK_FUNC(sub_823F5DF8);
PPC_FUNC_IMPL(__imp__sub_823F5DF8) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,-3484
	ctx.r9.s64 = r11.s64 + -3484;
	// addi r8,r10,-3504
	ctx.r8.s64 = ctx.r10.s64 + -3504;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823f5e50
	if (cr6.eq) goto loc_823F5E50;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// bl 0x823ef7c8
	ctx.lr = 0x823F5E48;
	sub_823EF7C8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
loc_823F5E50:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4364
	ctx.r10.s64 = r11.s64 + -4364;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_823F5E74"))) PPC_WEAK_FUNC(sub_823F5E74);
PPC_FUNC_IMPL(__imp__sub_823F5E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5E78"))) PPC_WEAK_FUNC(sub_823F5E78);
PPC_FUNC_IMPL(__imp__sub_823F5E78) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x823f5f10
	sub_823F5F10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F5E80"))) PPC_WEAK_FUNC(sub_823F5E80);
PPC_FUNC_IMPL(__imp__sub_823F5E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F5E90"))) PPC_WEAK_FUNC(sub_823F5E90);
PPC_FUNC_IMPL(__imp__sub_823F5E90) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x823f5f70
	sub_823F5F70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F5E98"))) PPC_WEAK_FUNC(sub_823F5E98);
PPC_FUNC_IMPL(__imp__sub_823F5E98) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x823f5fe8
	sub_823F5FE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F5EA0"))) PPC_WEAK_FUNC(sub_823F5EA0);
PPC_FUNC_IMPL(__imp__sub_823F5EA0) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r3,-4
	r31.s64 = ctx.r3.s64 + -4;
	// lwz r30,8(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F5ED0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823f5eec
	if (cr6.eq) goto loc_823F5EEC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823F5EEC;
	sub_823EF7C8(ctx, base);
loc_823F5EEC:
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

__attribute__((alias("__imp__sub_823F5F04"))) PPC_WEAK_FUNC(sub_823F5F04);
PPC_FUNC_IMPL(__imp__sub_823F5F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5F08"))) PPC_WEAK_FUNC(sub_823F5F08);
PPC_FUNC_IMPL(__imp__sub_823F5F08) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x823f3300
	sub_823F3300(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823F5F10"))) PPC_WEAK_FUNC(sub_823F5F10);
PPC_FUNC_IMPL(__imp__sub_823F5F10) {
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
	// bl 0x823f5df8
	ctx.lr = 0x823F5F30;
	sub_823F5DF8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f5f50
	if (cr6.eq) goto loc_823F5F50;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823F5F50;
	sub_823EF7C8(ctx, base);
loc_823F5F50:
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

__attribute__((alias("__imp__sub_823F5F6C"))) PPC_WEAK_FUNC(sub_823F5F6C);
PPC_FUNC_IMPL(__imp__sub_823F5F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5F70"))) PPC_WEAK_FUNC(sub_823F5F70);
PPC_FUNC_IMPL(__imp__sub_823F5F70) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,-3484
	ctx.r9.s64 = r11.s64 + -3484;
	// addi r8,r10,-3460
	ctx.r8.s64 = ctx.r10.s64 + -3460;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// bl 0x823f5df8
	ctx.lr = 0x823F5FA8;
	sub_823F5DF8(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823f5fc8
	if (cr6.eq) goto loc_823F5FC8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823F5FC8;
	sub_823EF7C8(ctx, base);
loc_823F5FC8:
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

__attribute__((alias("__imp__sub_823F5FE4"))) PPC_WEAK_FUNC(sub_823F5FE4);
PPC_FUNC_IMPL(__imp__sub_823F5FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F5FE8"))) PPC_WEAK_FUNC(sub_823F5FE8);
PPC_FUNC_IMPL(__imp__sub_823F5FE8) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,-3484
	ctx.r9.s64 = r11.s64 + -3484;
	// addi r8,r10,-3440
	ctx.r8.s64 = ctx.r10.s64 + -3440;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r7,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r7.u32);
	// bl 0x823f5df8
	ctx.lr = 0x823F6020;
	sub_823F5DF8(ctx, base);
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

__attribute__((alias("__imp__sub_823F6038"))) PPC_WEAK_FUNC(sub_823F6038);
PPC_FUNC_IMPL(__imp__sub_823F6038) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// li r4,28
	ctx.r4.s64 = 28;
	// bl 0x823ef7b8
	ctx.lr = 0x823F6060;
	sub_823EF7B8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f60cc
	if (cr6.eq) goto loc_823F60CC;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r7,r10,-4364
	ctx.r7.s64 = ctx.r10.s64 + -4364;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// addi r5,r9,-3484
	ctx.r5.s64 = ctx.r9.s64 + -3484;
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// addi r4,r8,-3460
	ctx.r4.s64 = ctx.r8.s64 + -3460;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
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
loc_823F60CC:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
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

__attribute__((alias("__imp__sub_823F60E8"))) PPC_WEAK_FUNC(sub_823F60E8);
PPC_FUNC_IMPL(__imp__sub_823F60E8) {
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
	ctx.lr = 0x823F60F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// addi r4,r30,28
	ctx.r4.s64 = r30.s64 + 28;
	// bl 0x823ef7b8
	ctx.lr = 0x823F6114;
	sub_823EF7B8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f6130
	if (!cr6.eq) goto loc_823F6130;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823F6130:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r7,r10,-4364
	ctx.r7.s64 = ctx.r10.s64 + -4364;
	// addi r5,r9,-3484
	ctx.r5.s64 = ctx.r9.s64 + -3484;
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r4,r8,-3440
	ctx.r4.s64 = ctx.r8.s64 + -3440;
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// addi r9,r11,28
	ctx.r9.s64 = r11.s64 + 28;
	// stw r3,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r3.u32);
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// stw r30,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r30.u32);
	// stw r9,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r9.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F6184"))) PPC_WEAK_FUNC(sub_823F6184);
PPC_FUNC_IMPL(__imp__sub_823F6184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6188"))) PPC_WEAK_FUNC(sub_823F6188);
PPC_FUNC_IMPL(__imp__sub_823F6188) {
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
	ctx.lr = 0x823F6190;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823f61e8
	if (!cr6.eq) goto loc_823F61E8;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x823f61c8
	if (cr6.eq) goto loc_823F61C8;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823f60e8
	ctx.lr = 0x823F61C4;
	sub_823F60E8(ctx, base);
	// b 0x823f61d0
	goto loc_823F61D0;
loc_823F61C8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823f6038
	ctx.lr = 0x823F61D0;
	sub_823F6038(ctx, base);
loc_823F61D0:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f622c
	if (cr6.lt) goto loc_823F622C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823F61E8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F61FC;
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
	ctx.lr = 0x823F6214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x823F622C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F622C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F6234"))) PPC_WEAK_FUNC(sub_823F6234);
PPC_FUNC_IMPL(__imp__sub_823F6234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6238"))) PPC_WEAK_FUNC(sub_823F6238);
PPC_FUNC_IMPL(__imp__sub_823F6238) {
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
	// bl 0x823f6fb0
	ctx.lr = 0x823F6250;
	sub_823F6FB0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-3416
	ctx.r10.s64 = r11.s64 + -3416;
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

__attribute__((alias("__imp__sub_823F6274"))) PPC_WEAK_FUNC(sub_823F6274);
PPC_FUNC_IMPL(__imp__sub_823F6274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6278"))) PPC_WEAK_FUNC(sub_823F6278);
PPC_FUNC_IMPL(__imp__sub_823F6278) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x823f6c48
	ctx.lr = 0x823F6298;
	sub_823F6C48(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F62B0;
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

__attribute__((alias("__imp__sub_823F62C8"))) PPC_WEAK_FUNC(sub_823F62C8);
PPC_FUNC_IMPL(__imp__sub_823F62C8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823f6c60
	ctx.lr = 0x823F62EC;
	sub_823F6C60(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6364
	if (cr6.lt) goto loc_823F6364;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lbz r9,25(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// li r11,0
	r11.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// std r11,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r11.u64);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// std r11,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r11.u64);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stb r11,105(r1)
	PPC_STORE_U8(ctx.r1.u32 + 105, r11.u8);
	// stb r9,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r9.u8);
	// stb r8,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r8.u8);
	// lwz r11,-9796(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9796);
	// lwz r3,60(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// bl 0x823ee170
	ctx.lr = 0x823F6334;
	sub_823EE170(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6364
	if (cr6.lt) goto loc_823F6364;
	// lbz r11,24(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// stw r6,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r6.u32);
loc_823F6364:
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

__attribute__((alias("__imp__sub_823F637C"))) PPC_WEAK_FUNC(sub_823F637C);
PPC_FUNC_IMPL(__imp__sub_823F637C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6380"))) PPC_WEAK_FUNC(sub_823F6380);
PPC_FUNC_IMPL(__imp__sub_823F6380) {
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
	ctx.lr = 0x823F6388;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,24(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 24);
	// stb r11,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r11.u8);
	// bl 0x823f7828
	ctx.lr = 0x823F63A0;
	sub_823F7828(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f647c
	if (cr6.lt) goto loc_823F647C;
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f63e8
	if (cr6.eq) goto loc_823F63E8;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823F63D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f6484
	if (cr6.eq) goto loc_823F6484;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823F63E8:
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f645c
	if (cr6.eq) goto loc_823F645C;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lbz r9,25(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 25);
	// li r8,1
	ctx.r8.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// std r30,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r30.u64);
	// std r30,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r30.u64);
	// stb r9,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r9.u8);
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stb r30,89(r1)
	PPC_STORE_U8(ctx.r1.u32 + 89, r30.u8);
	// beq cr6,0x823f645c
	if (cr6.eq) goto loc_823F645C;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_823F6424:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f647c
	if (cr6.lt) goto loc_823F647C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r6,255
	ctx.r6.s64 = 255;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bl 0x823f6e18
	ctx.lr = 0x823F6448;
	sub_823F6E18(ctx, base);
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,12
	r29.s64 = r29.s64 + 12;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823f6424
	if (cr6.lt) goto loc_823F6424;
loc_823F645C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f647c
	if (cr6.lt) goto loc_823F647C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,28(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F647C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F647C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_823F6484:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F6494"))) PPC_WEAK_FUNC(sub_823F6494);
PPC_FUNC_IMPL(__imp__sub_823F6494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6498"))) PPC_WEAK_FUNC(sub_823F6498);
PPC_FUNC_IMPL(__imp__sub_823F6498) {
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
	ctx.lr = 0x823F64A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823f64c0
	if (!cr6.eq) goto loc_823F64C0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r31,r11,-3324
	r31.s64 = r11.s64 + -3324;
loc_823F64C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f64d4
	if (cr6.eq) goto loc_823F64D4;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x823f64e4
	goto loc_823F64E4;
loc_823F64D4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
loc_823F64E4:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F64F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f6538
	if (!cr6.eq) goto loc_823F6538;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F651C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6550
	if (cr6.lt) goto loc_823F6550;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// lbz r4,81(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r3,53(r29)
	ctx.r3.u64 = PPC_LOAD_U8(r29.u32 + 53);
	// bl 0x823eab50
	ctx.lr = 0x823F6534;
	sub_823EAB50(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_823F6538:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F6550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F6550:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F6558"))) PPC_WEAK_FUNC(sub_823F6558);
PPC_FUNC_IMPL(__imp__sub_823F6558) {
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
	ctx.lr = 0x823F6560;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lbz r11,69(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 69);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f65ac
	if (cr6.eq) goto loc_823F65AC;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_823F6580:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823F6598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,69(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 69);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// blt cr6,0x823f6580
	if (cr6.lt) goto loc_823F6580;
loc_823F65AC:
	// stb r28,69(r30)
	PPC_STORE_U8(r30.u32 + 69, r28.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F65B8"))) PPC_WEAK_FUNC(sub_823F65B8);
PPC_FUNC_IMPL(__imp__sub_823F65B8) {
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
	ctx.lr = 0x823F65C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r31,0
	r31.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r11,61(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// not r9,r11
	ctx.r9.u64 = ~r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// clrlwi r27,r9,31
	r27.u64 = ctx.r9.u32 & 0x1;
	// beq cr6,0x823f6648
	if (cr6.eq) goto loc_823F6648;
	// li r30,0
	r30.s64 = 0;
loc_823F65F0:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6648
	if (cr6.lt) goto loc_823F6648;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r9,72(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823F6634;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// blt cr6,0x823f65f0
	if (cr6.lt) goto loc_823F65F0;
loc_823F6648:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F6650"))) PPC_WEAK_FUNC(sub_823F6650);
PPC_FUNC_IMPL(__imp__sub_823F6650) {
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
	ctx.lr = 0x823F6658;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r10,r11,-3416
	ctx.r10.s64 = r11.s64 + -3416;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823f7468
	ctx.lr = 0x823F6674;
	sub_823F7468(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f6558
	ctx.lr = 0x823F667C;
	sub_823F6558(ctx, base);
	// lbz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r29,r28
	r29.u64 = r28.u64;
	// beq cr6,0x823f66dc
	if (cr6.eq) goto loc_823F66DC;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_823F6694:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f66c8
	if (cr6.eq) goto loc_823F66C8;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F66BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// stw r28,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r28.u32);
loc_823F66C8:
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x823f6694
	if (cr6.lt) goto loc_823F6694;
loc_823F66DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823f6d48
	ctx.lr = 0x823F66E4;
	sub_823F6D48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F66EC"))) PPC_WEAK_FUNC(sub_823F66EC);
PPC_FUNC_IMPL(__imp__sub_823F66EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F66F0"))) PPC_WEAK_FUNC(sub_823F66F0);
PPC_FUNC_IMPL(__imp__sub_823F66F0) {
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
	ctx.lr = 0x823F66F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x823f6558
	ctx.lr = 0x823F670C;
	sub_823F6558(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823f6784
	if (cr6.eq) goto loc_823F6784;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6770
	if (cr6.eq) goto loc_823F6770;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
loc_823F672C:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x823f6778
	if (cr6.lt) goto loc_823F6778;
	// lwz r10,72(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// add r5,r10,r31
	ctx.r5.u64 = ctx.r10.u64 + r31.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x823f6498
	ctx.lr = 0x823F674C;
	sub_823F6498(ctx, base);
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x823f672c
	if (cr6.lt) goto loc_823F672C;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x823f6778
	if (cr6.lt) goto loc_823F6778;
loc_823F6770:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// stb r11,69(r28)
	PPC_STORE_U8(r28.u32 + 69, r11.u8);
loc_823F6778:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_823F677C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823F6784:
	// lbz r11,68(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6778
	if (cr6.eq) goto loc_823F6778;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,72(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823f6498
	ctx.lr = 0x823F67A0;
	sub_823F6498(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f677c
	if (cr6.lt) goto loc_823F677C;
	// li r11,1
	r11.s64 = 1;
	// stb r11,69(r28)
	PPC_STORE_U8(r28.u32 + 69, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823F67B8"))) PPC_WEAK_FUNC(sub_823F67B8);
PPC_FUNC_IMPL(__imp__sub_823F67B8) {
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
	ctx.lr = 0x823F67C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x823f7960
	ctx.lr = 0x823F67D0;
	sub_823F7960(ctx, base);
	// lbz r11,69(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 69);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6840
	if (cr6.eq) goto loc_823F6840;
	// li r31,0
	r31.s64 = 0;
loc_823F67E4:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6840
	if (cr6.lt) goto loc_823F6840;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823F6808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823F682C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r10,69(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 69);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f67e4
	if (cr6.lt) goto loc_823F67E4;
loc_823F6840:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F6848"))) PPC_WEAK_FUNC(sub_823F6848);
PPC_FUNC_IMPL(__imp__sub_823F6848) {
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
	ctx.lr = 0x823F6850;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x827bd514
	ctx.lr = 0x823F685C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f6884
	if (cr6.eq) goto loc_823F6884;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// beq cr6,0x823f689c
	if (cr6.eq) goto loc_823F689C;
loc_823F6884:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F688C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
loc_823F689C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r28,24
	r11.s64 = r28.s64 + 24;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lwz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x823f68d8
	if (cr6.eq) goto loc_823F68D8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F68D8:
	// mr r11,r13
	r11.u64 = ctx.r13.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823f691c
	if (cr6.eq) goto loc_823F691C;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x823f691c
	if (!cr6.eq) goto loc_823F691C;
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f691c
	if (!cr0.eq) goto loc_823F691C;
	// li r11,0
	r11.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x827bd544
	ctx.lr = 0x823F6914;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F691C;
	__imp__KfLowerIrql(ctx, base);
loc_823F691C:
	// lbz r11,69(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 69);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6984
	if (cr6.eq) goto loc_823F6984;
	// li r31,0
	r31.s64 = 0;
loc_823F6934:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6984
	if (cr6.lt) goto loc_823F6984;
	// lwz r11,72(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// beq 0x823f695c
	if (cr0.eq) goto loc_823F695C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823f6970
	goto loc_823F6970;
loc_823F695C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F6970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F6970:
	// lbz r11,69(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 69);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x823f6934
	if (cr6.lt) goto loc_823F6934;
loc_823F6984:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F698C"))) PPC_WEAK_FUNC(sub_823F698C);
PPC_FUNC_IMPL(__imp__sub_823F698C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6990"))) PPC_WEAK_FUNC(sub_823F6990);
PPC_FUNC_IMPL(__imp__sub_823F6990) {
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
	// bl 0x823f6650
	ctx.lr = 0x823F69B0;
	sub_823F6650(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f69d0
	if (cr6.eq) goto loc_823F69D0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823F69D0;
	sub_823EF7C8(ctx, base);
loc_823F69D0:
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

__attribute__((alias("__imp__sub_823F69EC"))) PPC_WEAK_FUNC(sub_823F69EC);
PPC_FUNC_IMPL(__imp__sub_823F69EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F69F0"))) PPC_WEAK_FUNC(sub_823F69F0);
PPC_FUNC_IMPL(__imp__sub_823F69F0) {
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
	ctx.lr = 0x823F69F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lbz r11,69(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 69);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6a60
	if (cr6.eq) goto loc_823F6A60;
	// li r30,0
	r30.s64 = 0;
loc_823F6A18:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6b6c
	if (cr6.lt) goto loc_823F6B6C;
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823F6A44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,69(r29)
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + 69);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// blt cr6,0x823f6a18
	if (cr6.lt) goto loc_823F6A18;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6b6c
	if (cr6.lt) goto loc_823F6B6C;
loc_823F6A60:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r31,-9796(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -9796);
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823F6A80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x823f6aa4
	if (cr6.lt) goto loc_823F6AA4;
	// bne cr6,0x823f6b68
	if (!cr6.eq) goto loc_823F6B68;
	// lbz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 76);
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mulli r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 * 44;
	// add r27,r10,r11
	r27.u64 = ctx.r10.u64 + r11.u64;
	// b 0x823f6aa8
	goto loc_823F6AA8;
loc_823F6AA4:
	// addi r27,r31,80
	r27.s64 = r31.s64 + 80;
loc_823F6AA8:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823f6b68
	if (cr6.eq) goto loc_823F6B68;
	// bl 0x827bd514
	ctx.lr = 0x823F6AB4;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f6adc
	if (cr6.eq) goto loc_823F6ADC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f6af0
	if (cr6.eq) goto loc_823F6AF0;
loc_823F6ADC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F6AE4;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r28,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r28.u8);
loc_823F6AF0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r9,40(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f6b68
	if (cr6.eq) goto loc_823F6B68;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f6b68
	if (!cr6.eq) goto loc_823F6B68;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f6b68
	if (!cr0.eq) goto loc_823F6B68;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F6B60;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F6B68;
	__imp__KfLowerIrql(ctx, base);
loc_823F6B68:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823F6B6C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823F6B74"))) PPC_WEAK_FUNC(sub_823F6B74);
PPC_FUNC_IMPL(__imp__sub_823F6B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6B78"))) PPC_WEAK_FUNC(sub_823F6B78);
PPC_FUNC_IMPL(__imp__sub_823F6B78) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F6B9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821a5cc0
	ctx.lr = 0x823F6BA8;
	sub_821A5CC0(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6bc8
	if (cr6.eq) goto loc_823F6BC8;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823F6BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F6BC8:
	// lbz r11,61(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 61);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f6bf0
	if (cr6.eq) goto loc_823F6BF0;
	// lhz r11,64(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6c2c
	if (cr6.eq) goto loc_823F6C2C;
	// addis r11,r11,1
	r11.s64 = r11.s64 + 65536;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sth r11,64(r31)
	PPC_STORE_U16(r31.u32 + 64, r11.u16);
loc_823F6BF0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F6C08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F6C08:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821a5cc0
	ctx.lr = 0x823F6C14;
	sub_821A5CC0(ctx, base);
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
loc_823F6C2C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F6C44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823f6c08
	goto loc_823F6C08;
}

__attribute__((alias("__imp__sub_823F6C48"))) PPC_WEAK_FUNC(sub_823F6C48);
PPC_FUNC_IMPL(__imp__sub_823F6C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F6C5C"))) PPC_WEAK_FUNC(sub_823F6C5C);
PPC_FUNC_IMPL(__imp__sub_823F6C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6C60"))) PPC_WEAK_FUNC(sub_823F6C60);
PPC_FUNC_IMPL(__imp__sub_823F6C60) {
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
	ctx.lr = 0x823F6C68;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r31
	r29.u64 = r31.u64;
	// mr r30,r31
	r30.u64 = r31.u64;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823f6cd4
	if (!cr6.eq) goto loc_823F6CD4;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lbz r10,1(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1);
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ori r8,r9,48000
	ctx.r8.u64 = ctx.r9.u64 | 48000;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// std r31,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r31.u64);
	// std r31,8(r11)
	PPC_STORE_U64(r11.u32 + 8, r31.u64);
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
	// stb r31,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r31.u8);
	// stb r10,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, ctx.r10.u8);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// stb r31,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r31.u8);
	// bl 0x823eb1e8
	ctx.lr = 0x823F6CC8;
	sub_823EB1E8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6d3c
	if (cr6.lt) goto loc_823F6D3C;
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823F6CD4:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6d30
	if (cr6.eq) goto loc_823F6D30;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f6d30
	if (cr6.eq) goto loc_823F6D30;
	// lis r27,-32115
	r27.s64 = -2104688640;
loc_823F6CF0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-9796(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -9796);
	// lwzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r3,60(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// bl 0x823ee170
	ctx.lr = 0x823F6D08;
	sub_823EE170(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6d3c
	if (cr6.lt) goto loc_823F6D3C;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// add r29,r10,r29
	r29.u64 = ctx.r10.u64 + r29.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f6cf0
	if (cr6.lt) goto loc_823F6CF0;
loc_823F6D30:
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_823F6D3C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823F6D44"))) PPC_WEAK_FUNC(sub_823F6D44);
PPC_FUNC_IMPL(__imp__sub_823F6D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6D48"))) PPC_WEAK_FUNC(sub_823F6D48);
PPC_FUNC_IMPL(__imp__sub_823F6D48) {
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
	ctx.lr = 0x823F6D50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r28,0
	r28.s64 = 0;
	// addi r9,r11,-3312
	ctx.r9.s64 = r11.s64 + -3312;
	// lbz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f6dc0
	if (cr6.eq) goto loc_823F6DC0;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_823F6D78:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r30,r29,3,0,28
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r11,r30,r10
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f6da8
	if (cr6.eq) goto loc_823F6DA8;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r3,r30,r10
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F6DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stwx r28,r30,r9
	PPC_STORE_U32(r30.u32 + ctx.r9.u32, r28.u32);
loc_823F6DA8:
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// lbz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f6d78
	if (cr6.lt) goto loc_823F6D78;
loc_823F6DC0:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f6dd4
	if (cr6.eq) goto loc_823F6DD4;
	// bl 0x823eaeb0
	ctx.lr = 0x823F6DD0;
	sub_823EAEB0(ctx, base);
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
loc_823F6DD4:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r11,-4320
	ctx.r10.s64 = r11.s64 + -4320;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x823f6e00
	if (cr6.eq) goto loc_823F6E00;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F6DFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
loc_823F6E00:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-4364
	ctx.r10.s64 = r11.s64 + -4364;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F6E14"))) PPC_WEAK_FUNC(sub_823F6E14);
PPC_FUNC_IMPL(__imp__sub_823F6E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6E18"))) PPC_WEAK_FUNC(sub_823F6E18);
PPC_FUNC_IMPL(__imp__sub_823F6E18) {
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
	ctx.lr = 0x823F6E20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,-9796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r3,60(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x823ee190
	ctx.lr = 0x823F6E54;
	sub_823EE190(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6ea8
	if (cr6.lt) goto loc_823F6EA8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F6E74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f6ea8
	if (cr6.lt) goto loc_823F6EA8;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// li r9,1
	ctx.r9.s64 = 1;
	// lhz r11,82(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// stb r29,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r29.u8);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stb r9,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r9.u8);
	// stb r10,6(r31)
	PPC_STORE_U8(r31.u32 + 6, ctx.r10.u8);
	// lhz r7,62(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 62);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// ble cr6,0x823f6ea8
	if (!cr6.gt) goto loc_823F6EA8;
	// sth r11,62(r30)
	PPC_STORE_U16(r30.u32 + 62, r11.u16);
loc_823F6EA8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F6EB0"))) PPC_WEAK_FUNC(sub_823F6EB0);
PPC_FUNC_IMPL(__imp__sub_823F6EB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,60(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f6ed4
	if (cr6.lt) goto loc_823F6ED4;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
loc_823F6ED4:
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823F6EF8"))) PPC_WEAK_FUNC(sub_823F6EF8);
PPC_FUNC_IMPL(__imp__sub_823F6EF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,60(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f6f1c
	if (cr6.lt) goto loc_823F6F1C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
loc_823F6F1C:
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823F6F40"))) PPC_WEAK_FUNC(sub_823F6F40);
PPC_FUNC_IMPL(__imp__sub_823F6F40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,60(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f6f5c
	if (cr6.lt) goto loc_823F6F5C;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
loc_823F6F5C:
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r11,5(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F6F78"))) PPC_WEAK_FUNC(sub_823F6F78);
PPC_FUNC_IMPL(__imp__sub_823F6F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,60(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f6f94
	if (cr6.lt) goto loc_823F6F94;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// blr 
	return;
loc_823F6F94:
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stb r5,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F6FAC"))) PPC_WEAK_FUNC(sub_823F6FAC);
PPC_FUNC_IMPL(__imp__sub_823F6FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F6FB0"))) PPC_WEAK_FUNC(sub_823F6FB0);
PPC_FUNC_IMPL(__imp__sub_823F6FB0) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-4320
	ctx.r9.s64 = r11.s64 + -4320;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r4,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823f7000
	if (cr6.eq) goto loc_823F7000;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F7000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F7000:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stb r30,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r30.u8);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r9,r10,-3312
	ctx.r9.s64 = ctx.r10.s64 + -3312;
	// addi r10,r31,24
	ctx.r10.s64 = r31.s64 + 24;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r8,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_823F704C"))) PPC_WEAK_FUNC(sub_823F704C);
PPC_FUNC_IMPL(__imp__sub_823F704C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F7050"))) PPC_WEAK_FUNC(sub_823F7050);
PPC_FUNC_IMPL(__imp__sub_823F7050) {
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
	// bl 0x823f6d48
	ctx.lr = 0x823F7070;
	sub_823F6D48(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f7090
	if (cr6.eq) goto loc_823F7090;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r3,r11,-9788
	ctx.r3.s64 = r11.s64 + -9788;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823ef7c8
	ctx.lr = 0x823F7090;
	sub_823EF7C8(ctx, base);
loc_823F7090:
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

__attribute__((alias("__imp__sub_823F70AC"))) PPC_WEAK_FUNC(sub_823F70AC);
PPC_FUNC_IMPL(__imp__sub_823F70AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F70B0"))) PPC_WEAK_FUNC(sub_823F70B0);
PPC_FUNC_IMPL(__imp__sub_823F70B0) {
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
	ctx.lr = 0x823F70B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f7118
	if (cr6.eq) goto loc_823F7118;
loc_823F70D8:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f7118
	if (cr6.lt) goto loc_823F7118;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r8,r6,2,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x3FC;
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// rlwinm r11,r6,3,21,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0x7F8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r29,r6,24
	r29.u64 = ctx.r6.u32 & 0xFF;
	// lwzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x823f6e18
	ctx.lr = 0x823F7104;
	sub_823F6E18(ctx, base);
	// addi r7,r29,1
	ctx.r7.s64 = r29.s64 + 1;
	// lbz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// blt cr6,0x823f70d8
	if (cr6.lt) goto loc_823F70D8;
loc_823F7118:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F7120"))) PPC_WEAK_FUNC(sub_823F7120);
PPC_FUNC_IMPL(__imp__sub_823F7120) {
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
	// lbz r11,5(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823f7150
	if (!cr6.eq) goto loc_823F7150;
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
loc_823F7150:
	// lbz r11,6(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// rlwinm r10,r11,0,29,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x6;
	// cmplwi cr6,r10,6
	cr6.compare<uint32_t>(ctx.r10.u32, 6, xer);
	// bne cr6,0x823f71dc
	if (!cr6.eq) goto loc_823F71DC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lbz r9,268(r13)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lwz r8,-9796(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -9796);
	// beq cr6,0x823f71a4
	if (cr6.eq) goto loc_823F71A4;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r11,0
	r11.s64 = 0;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
loc_823F7188:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// beq cr6,0x823f71b8
	if (cr6.eq) goto loc_823F71B8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// blt cr6,0x823f7188
	if (cr6.lt) goto loc_823F7188;
loc_823F71A4:
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// b 0x823f7214
	goto loc_823F7214;
loc_823F71B8:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,3
	ctx.r10.s64 = r11.s64 + 3;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// b 0x823f7214
	goto loc_823F7214;
loc_823F71DC:
	// clrlwi r10,r11,30
	ctx.r10.u64 = r11.u32 & 0x3;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f71f4
	if (cr6.eq) goto loc_823F71F4;
	// lwz r7,0(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// b 0x823f7214
	goto loc_823F7214;
loc_823F71F4:
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f720c
	if (cr6.eq) goto loc_823F720C;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x823f7214
	goto loc_823F7214;
loc_823F720C:
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_823F7214:
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F7230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823F7240"))) PPC_WEAK_FUNC(sub_823F7240);
PPC_FUNC_IMPL(__imp__sub_823F7240) {
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
	ctx.lr = 0x823F7248;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821a5cc0
	ctx.lr = 0x823F7258;
	sub_821A5CC0(ctx, base);
	// bl 0x827bd514
	ctx.lr = 0x823F725C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f7284
	if (cr6.eq) goto loc_823F7284;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f7298
	if (cr6.eq) goto loc_823F7298;
loc_823F7284:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F728C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F7298:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,61(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f7350
	if (cr6.eq) goto loc_823F7350;
	// bl 0x827bd514
	ctx.lr = 0x823F72B4;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f72d4
	if (cr6.eq) goto loc_823F72D4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f72e8
	if (cr6.eq) goto loc_823F72E8;
loc_823F72D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F72DC;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F72E8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,61(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwinm r9,r9,0,30,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stb r9,61(r28)
	PPC_STORE_U8(r28.u32 + 61, ctx.r9.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f7408
	if (cr6.eq) goto loc_823F7408;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f7408
	if (!cr6.eq) goto loc_823F7408;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f7408
	if (!cr0.eq) goto loc_823F7408;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F7344;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F734C;
	__imp__KfLowerIrql(ctx, base);
	// b 0x823f7404
	goto loc_823F7404;
loc_823F7350:
	// bl 0x827bd514
	ctx.lr = 0x823F7354;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f7374
	if (cr6.eq) goto loc_823F7374;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f7388
	if (cr6.eq) goto loc_823F7388;
loc_823F7374:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F737C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F7388:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,61(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// rlwinm r9,r11,0,24,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFE;
	// rlwinm r9,r9,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stb r8,61(r28)
	PPC_STORE_U8(r28.u32 + 61, ctx.r8.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f73f0
	if (cr6.eq) goto loc_823F73F0;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f73f0
	if (!cr6.eq) goto loc_823F73F0;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f73f0
	if (!cr0.eq) goto loc_823F73F0;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F73E8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F73F0;
	__imp__KfLowerIrql(ctx, base);
loc_823F73F0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F7404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823F7404:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F7408:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// beq cr6,0x823f7450
	if (cr6.eq) goto loc_823F7450;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f7450
	if (!cr6.eq) goto loc_823F7450;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f7450
	if (!cr0.eq) goto loc_823F7450;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F7448;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F7450;
	__imp__KfLowerIrql(ctx, base);
loc_823F7450:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821a5cc0
	ctx.lr = 0x823F7458;
	sub_821A5CC0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F7464"))) PPC_WEAK_FUNC(sub_823F7464);
PPC_FUNC_IMPL(__imp__sub_823F7464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F7468"))) PPC_WEAK_FUNC(sub_823F7468);
PPC_FUNC_IMPL(__imp__sub_823F7468) {
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
	ctx.lr = 0x823F7470;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x823F7484;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r31,31
	r11.u64 = r31.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f7668
	if (cr6.eq) goto loc_823F7668;
	// bl 0x827bd514
	ctx.lr = 0x823F7494;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f74bc
	if (cr6.eq) goto loc_823F74BC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f74d0
	if (cr6.eq) goto loc_823F74D0;
loc_823F74BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F74C4;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F74D0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-9796(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -9796);
	// bl 0x823eb8e0
	ctx.lr = 0x823F74E8;
	sub_823EB8E0(ctx, base);
	// lbz r9,61(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823f7558
	if (!cr6.eq) goto loc_823F7558;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823f7814
	if (cr6.eq) goto loc_823F7814;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x823f7814
	if (!cr6.eq) goto loc_823F7814;
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f7814
	if (!cr0.eq) goto loc_823F7814;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F753C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F7544;
	__imp__KfLowerIrql(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821a5cc0
	ctx.lr = 0x823F754C;
	sub_821A5CC0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823F7558:
	// bl 0x827bd514
	ctx.lr = 0x823F755C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f757c
	if (cr6.eq) goto loc_823F757C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f7590
	if (cr6.eq) goto loc_823F7590;
loc_823F757C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F7584;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F7590:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r12,186
	r12.s64 = 186;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// lbz r11,61(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// and r9,r11,r12
	ctx.r9.u64 = r11.u64 & r12.u64;
	// stb r9,61(r28)
	PPC_STORE_U8(r28.u32 + 61, ctx.r9.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f75f4
	if (cr6.eq) goto loc_823F75F4;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f75f4
	if (!cr6.eq) goto loc_823F75F4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f75f4
	if (!cr0.eq) goto loc_823F75F4;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F75EC;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F75F4;
	__imp__KfLowerIrql(ctx, base);
loc_823F75F4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F7608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f7814
	if (cr6.eq) goto loc_823F7814;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f7814
	if (!cr6.eq) goto loc_823F7814;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f7814
	if (!cr0.eq) goto loc_823F7814;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F764C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F7654;
	__imp__KfLowerIrql(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821a5cc0
	ctx.lr = 0x823F765C;
	sub_821A5CC0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823F7668:
	// bl 0x827bd514
	ctx.lr = 0x823F766C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r11,-9904
	r31.s64 = r11.s64 + -9904;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f7694
	if (cr6.eq) goto loc_823F7694;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f76b4
	if (cr6.eq) goto loc_823F76B4;
loc_823F7694:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F769C;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// stb r9,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r9.u8);
	// b 0x823f76b8
	goto loc_823F76B8;
loc_823F76B4:
	// lbz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 12);
loc_823F76B8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r8,61(r28)
	ctx.r8.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x823f7728
	if (!cr6.eq) goto loc_823F7728;
	// mr r8,r13
	ctx.r8.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f7814
	if (cr6.eq) goto loc_823F7814;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bne cr6,0x823f7814
	if (!cr6.eq) goto loc_823F7814;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f7814
	if (!cr0.eq) goto loc_823F7814;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r31,r9
	r31.u64 = ctx.r9.u64;
	// bl 0x827bd544
	ctx.lr = 0x823F770C;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F7714;
	__imp__KfLowerIrql(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821a5cc0
	ctx.lr = 0x823F771C;
	sub_821A5CC0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823F7728:
	// bl 0x827bd514
	ctx.lr = 0x823F772C;
	__imp__KeRaiseIrqlToDpcLevel(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r13
	r30.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f774c
	if (cr6.eq) goto loc_823F774C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x823f7760
	if (cr6.eq) goto loc_823F7760;
loc_823F774C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827bd504
	ctx.lr = 0x823F7754;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
loc_823F7760:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,61(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 61);
	// ori r9,r11,4
	ctx.r9.u64 = r11.u64 | 4;
	// stb r9,61(r28)
	PPC_STORE_U8(r28.u32 + 61, ctx.r9.u8);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f77c4
	if (cr6.eq) goto loc_823F77C4;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f77c4
	if (!cr6.eq) goto loc_823F77C4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f77c4
	if (!cr0.eq) goto loc_823F77C4;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F77B8;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F77C0;
	__imp__KfLowerIrql(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_823F77C4:
	// mr r10,r13
	ctx.r10.u64 = ctx.r13.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823f780c
	if (cr6.eq) goto loc_823F780C;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x823f780c
	if (!cr6.eq) goto loc_823F780C;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x823f780c
	if (!cr0.eq) goto loc_823F780C;
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r30,12(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// bl 0x827bd544
	ctx.lr = 0x823F7804;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bd524
	ctx.lr = 0x823F780C;
	__imp__KfLowerIrql(ctx, base);
loc_823F780C:
	// lhz r11,62(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 62);
	// sth r11,64(r28)
	PPC_STORE_U16(r28.u32 + 64, r11.u16);
loc_823F7814:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x821a5cc0
	ctx.lr = 0x823F781C;
	sub_821A5CC0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F7828"))) PPC_WEAK_FUNC(sub_823F7828);
PPC_FUNC_IMPL(__imp__sub_823F7828) {
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
	ctx.lr = 0x823F7830;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r28,r29
	r28.u64 = r29.u64;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r9,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r9.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r8,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r8.u32);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f7878
	if (cr6.eq) goto loc_823F7878;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// b 0x823f787c
	goto loc_823F787C;
loc_823F7878:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823F787C:
	// stb r11,60(r31)
	PPC_STORE_U8(r31.u32 + 60, r11.u8);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f78a4
	if (cr6.eq) goto loc_823F78A4;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f78ec
	if (cr6.eq) goto loc_823F78EC;
	// bl 0x823eae90
	ctx.lr = 0x823F78A0;
	sub_823EAE90(ctx, base);
	// b 0x823f78ec
	goto loc_823F78EC;
loc_823F78A4:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lbz r10,1(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r31,32
	ctx.r5.s64 = r31.s64 + 32;
	// ori r8,r9,48000
	ctx.r8.u64 = ctx.r9.u64 | 48000;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r29,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r29.u64);
	// std r29,8(r11)
	PPC_STORE_U64(r11.u32 + 8, r29.u64);
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r29.u8);
	// stb r10,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r10.u8);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r29.u8);
	// bl 0x823eb240
	ctx.lr = 0x823F78E0;
	sub_823EB240(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x823f7950
	if (cr6.lt) goto loc_823F7950;
loc_823F78EC:
	// lbz r11,60(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f7920
	if (cr6.eq) goto loc_823F7920;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F7910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823f7940
	if (cr6.eq) goto loc_823F7940;
	// mr r28,r29
	r28.u64 = r29.u64;
loc_823F7920:
	// lbz r11,60(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823f7950
	if (cr6.eq) goto loc_823F7950;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x823f70b0
	ctx.lr = 0x823F7938;
	sub_823F70B0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_823F7940:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_823F7950:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823F795C"))) PPC_WEAK_FUNC(sub_823F795C);
PPC_FUNC_IMPL(__imp__sub_823F795C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823F7960"))) PPC_WEAK_FUNC(sub_823F7960);
PPC_FUNC_IMPL(__imp__sub_823F7960) {
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
	ctx.lr = 0x823F7968;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823f79c0
	if (cr6.eq) goto loc_823F79C0;
loc_823F7988:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823f79c0
	if (cr6.lt) goto loc_823F79C0;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r10,r11,3,21,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x7F8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// bl 0x823f7120
	ctx.lr = 0x823F79AC;
	sub_823F7120(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lbz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 60);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x823f7988
	if (cr6.lt) goto loc_823F7988;
loc_823F79C0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823F79C8"))) PPC_WEAK_FUNC(sub_823F79C8);
PPC_FUNC_IMPL(__imp__sub_823F79C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// li r11,8
	r11.s64 = 8;
	// lfs f0,-3200(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3200);
	f0.f64 = double(temp.f32);
	// li r10,5
	ctx.r10.s64 = 5;
	// lfs f13,-3192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -3192);
	ctx.f13.f64 = double(temp.f32);
	// li r8,6
	ctx.r8.s64 = 6;
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f0,56(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f0,60(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stfs f13,76(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// lfs f0,-3204(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -3204);
	f0.f64 = double(temp.f32);
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// lfs f13,-3200(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3200);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f12,-3196(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -3196);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// lfs f11,-3192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -3192);
	ctx.f11.f64 = double(temp.f32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stfs f12,72(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// stfs f11,80(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
	// blr 
	return;
}

