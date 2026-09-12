#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8214D4B4"))) PPC_WEAK_FUNC(sub_8214D4B4);
PPC_FUNC_IMPL(__imp__sub_8214D4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214D4B8"))) PPC_WEAK_FUNC(sub_8214D4B8);
PPC_FUNC_IMPL(__imp__sub_8214D4B8) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_8214D4D0:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// stfsx f0,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
	// blt cr6,0x8214d4d0
	if (cr6.lt) goto loc_8214D4D0;
	// li r11,-1
	r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stb r10,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r10.u8);
	// beq cr6,0x8214d544
	if (cr6.eq) goto loc_8214D544;
	// cmpwi cr6,r6,2
	cr6.compare<int32_t>(ctx.r6.s32, 2, xer);
	// beq cr6,0x8214d53c
	if (cr6.eq) goto loc_8214D53C;
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r7,104(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// lwz r6,108(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// stb r8,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r8.u8);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// b 0x8214d550
	goto loc_8214D550;
loc_8214D53C:
	// addi r10,r3,116
	ctx.r10.s64 = ctx.r3.s64 + 116;
	// b 0x8214d548
	goto loc_8214D548;
loc_8214D544:
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
loc_8214D548:
	// li r11,1
	r11.s64 = 1;
	// stb r11,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r11.u8);
loc_8214D550:
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// bl 0x8214d0e0
	ctx.lr = 0x8214D55C;
	sub_8214D0E0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214D56C"))) PPC_WEAK_FUNC(sub_8214D56C);
PPC_FUNC_IMPL(__imp__sub_8214D56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214D570"))) PPC_WEAK_FUNC(sub_8214D570);
PPC_FUNC_IMPL(__imp__sub_8214D570) {
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
	// addi r3,r31,136
	ctx.r3.s64 = r31.s64 + 136;
	// bl 0x82162a10
	ctx.lr = 0x8214D58C;
	sub_82162A10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214d5b0
	if (!cr6.eq) goto loc_8214D5B0;
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
loc_8214D5B0:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r10,24
	ctx.r10.s64 = 24;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8214D5C0:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x8214d5c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8214D5C0;
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d218
	ctx.lr = 0x8214D5D8;
	sub_8214D218(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
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
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214D5FC"))) PPC_WEAK_FUNC(sub_8214D5FC);
PPC_FUNC_IMPL(__imp__sub_8214D5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214D600"))) PPC_WEAK_FUNC(sub_8214D600);
PPC_FUNC_IMPL(__imp__sub_8214D600) {
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
	ctx.lr = 0x8214D608;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8214d628
	if (!cr6.eq) goto loc_8214D628;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8214D628:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be250
	ctx.lr = 0x8214D638;
	sub_821BE250(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r28,r11,19856
	r28.s64 = r11.s64 + 19856;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82144a60
	ctx.lr = 0x8214D658;
	sub_82144A60(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214d670
	if (cr6.eq) goto loc_8214D670;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x823da950
	ctx.lr = 0x8214D670;
	sub_823DA950(ctx, base);
loc_8214D670:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x821be250
	ctx.lr = 0x8214D684;
	sub_821BE250(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// beq cr6,0x8214d6a8
	if (cr6.eq) goto loc_8214D6A8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214D6A8;
	sub_82144A78(ctx, base);
loc_8214D6A8:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214D6B8"))) PPC_WEAK_FUNC(sub_8214D6B8);
PPC_FUNC_IMPL(__imp__sub_8214D6B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lwz r9,60(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 60);
	// bne cr6,0x8214d6d4
	if (!cr6.eq) goto loc_8214D6D4;
	// blr 
	return;
loc_8214D6D4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r7,64(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
loc_8214D6E0:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x8214d708
	if (!cr6.gt) goto loc_8214D708;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x8214d710
	goto loc_8214D710;
loc_8214D708:
	// bge cr6,0x8214d71c
	if (!cr6.lt) goto loc_8214D71C;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_8214D710:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x8214d6e0
	if (!cr6.gt) goto loc_8214D6E0;
	// blr 
	return;
loc_8214D71C:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwzx r11,r11,r7
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214D730"))) PPC_WEAK_FUNC(sub_8214D730);
PPC_FUNC_IMPL(__imp__sub_8214D730) {
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
	// lwz r7,60(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8214d824
	if (cr6.eq) goto loc_8214D824;
	// li r4,13
	ctx.r4.s64 = 13;
loc_8214D748:
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// divwu r7,r10,r4
	ctx.r7.u32 = ctx.r10.u32 / ctx.r4.u32;
	// cmplwi cr6,r7,9
	cr6.compare<uint32_t>(ctx.r7.u32, 9, xer);
	// beq cr6,0x8214d768
	if (cr6.eq) goto loc_8214D768;
	// cmplwi cr6,r7,10
	cr6.compare<uint32_t>(ctx.r7.u32, 10, xer);
	// bne cr6,0x8214d770
	if (!cr6.eq) goto loc_8214D770;
loc_8214D768:
	// li r7,11
	ctx.r7.s64 = 11;
	// b 0x8214d77c
	goto loc_8214D77C;
loc_8214D770:
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bge cr6,0x8214d77c
	if (!cr6.lt) goto loc_8214D77C;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8214D77C:
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf. r10,r7,r11
	ctx.r10.s64 = r11.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8214d810
	if (cr0.eq) goto loc_8214D810;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
loc_8214D798:
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lwz r8,4(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// ble cr6,0x8214d7f4
	if (!cr6.gt) goto loc_8214D7F4;
	// lwz r8,64(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// li r5,1
	ctx.r5.s64 = 1;
	// add r31,r11,r8
	r31.u64 = r11.u64 + ctx.r8.u64;
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r8,r10,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r30,4(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r31.u32);
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// lwzx r31,r11,r9
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stwx r31,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r31.u32);
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// stwx r8,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r8.u32);
loc_8214D7F4:
	// lwz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// subf r8,r7,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r6,r8
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, xer);
	// blt cr6,0x8214d798
	if (cr6.lt) goto loc_8214D798;
loc_8214D810:
	// cmplwi cr6,r7,1
	cr6.compare<uint32_t>(ctx.r7.u32, 1, xer);
	// bne cr6,0x8214d748
	if (!cr6.eq) goto loc_8214D748;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214d748
	if (!cr6.eq) goto loc_8214D748;
loc_8214D824:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214D830"))) PPC_WEAK_FUNC(sub_8214D830);
PPC_FUNC_IMPL(__imp__sub_8214D830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x8214d840
	if (!cr6.eq) goto loc_8214D840;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8214D840:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214D84C"))) PPC_WEAK_FUNC(sub_8214D84C);
PPC_FUNC_IMPL(__imp__sub_8214D84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214D850"))) PPC_WEAK_FUNC(sub_8214D850);
PPC_FUNC_IMPL(__imp__sub_8214D850) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r3,r4,16
	ctx.r3.u64 = ctx.r4.u32 & 0xFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214D858"))) PPC_WEAK_FUNC(sub_8214D858);
PPC_FUNC_IMPL(__imp__sub_8214D858) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x8214d86c
	if (cr6.lt) goto loc_8214D86C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8214D86C:
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214D87C"))) PPC_WEAK_FUNC(sub_8214D87C);
PPC_FUNC_IMPL(__imp__sub_8214D87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214D880"))) PPC_WEAK_FUNC(sub_8214D880);
PPC_FUNC_IMPL(__imp__sub_8214D880) {
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
	ctx.lr = 0x8214D888;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8214d8dc
	if (!cr6.gt) goto loc_8214D8DC;
	// li r31,0
	r31.s64 = 0;
loc_8214D8A8:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x8214D8BC;
	sub_821C9790(ctx, base);
	// cmplw cr6,r28,r3
	cr6.compare<uint32_t>(r28.u32, ctx.r3.u32, xer);
	// beq cr6,0x8214d8e8
	if (cr6.eq) goto loc_8214D8E8;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// clrlwi r29,r11,16
	r29.u64 = r11.u32 & 0xFFFF;
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x8214d8a8
	if (cr6.lt) goto loc_8214D8A8;
loc_8214D8DC:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8214D8E8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214D8F4"))) PPC_WEAK_FUNC(sub_8214D8F4);
PPC_FUNC_IMPL(__imp__sub_8214D8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214D8F8"))) PPC_WEAK_FUNC(sub_8214D8F8);
PPC_FUNC_IMPL(__imp__sub_8214D8F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,68(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214d928
	if (cr6.eq) goto loc_8214D928;
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x8214d91c
	if (cr6.lt) goto loc_8214D91C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,13684
	ctx.r3.s64 = r11.s64 + 13684;
	// blr 
	return;
loc_8214D91C:
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// blr 
	return;
loc_8214D928:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214D930"))) PPC_WEAK_FUNC(sub_8214D930);
PPC_FUNC_IMPL(__imp__sub_8214D930) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8214D938;
	// addi r31,r1,-480
	r31.s64 = ctx.r1.s64 + -480;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r20,0
	r20.s64 = 0;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stb r20,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r20.u8);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// mr r27,r20
	r27.u64 = r20.u64;
	// mr r22,r20
	r22.u64 = r20.u64;
	// mr r21,r20
	r21.u64 = r20.u64;
	// mr r23,r20
	r23.u64 = r20.u64;
	// mr r28,r20
	r28.u64 = r20.u64;
	// bne cr6,0x8214d978
	if (!cr6.eq) goto loc_8214D978;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,480
	ctx.r1.s64 = r31.s64 + 480;
	// b 0x823d9228
	return;
loc_8214D978:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,92
	ctx.r4.s64 = r31.s64 + 92;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214D988;
	sub_821BE250(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214D998;
	sub_821BE250(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// lbz r11,68(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214d9f4
	if (cr6.eq) goto loc_8214D9F4;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// li r5,16
	ctx.r5.s64 = 16;
	// add r21,r11,r10
	r21.u64 = r11.u64 + ctx.r10.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x82144a60
	ctx.lr = 0x8214D9C8;
	sub_82144A60(ctx, base);
	// lwz r4,52(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214d9f4
	if (cr6.eq) goto loc_8214D9F4;
	// lwz r5,44(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x823da950
	ctx.lr = 0x8214D9E0;
	sub_823DA950(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,52(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lwz r22,44(r30)
	r22.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x82144a78
	ctx.lr = 0x8214D9F0;
	sub_82144A78(ctx, base);
	// stw r20,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r20.u32);
loc_8214D9F4:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// li r5,16
	ctx.r5.s64 = 16;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82144a60
	ctx.lr = 0x8214DA10;
	sub_82144A60(ctx, base);
	// lwz r4,64(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214da44
	if (cr6.eq) goto loc_8214DA44;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x823da950
	ctx.lr = 0x8214DA2C;
	sub_823DA950(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,64(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// lwz r27,60(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// bl 0x82144a78
	ctx.lr = 0x8214DA3C;
	sub_82144A78(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// stw r20,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r20.u32);
loc_8214DA44:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r29,r20
	r29.u64 = r20.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214db94
	if (cr6.eq) goto loc_8214DB94;
	// rlwinm r11,r27,3,0,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r25,r28,24
	r25.u64 = r28.u32 & 0xFF;
	// add r28,r11,r26
	r28.u64 = r11.u64 + r26.u64;
loc_8214DA60:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DA70;
	sub_821BE250(ctx, base);
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lbz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// bl 0x821be250
	ctx.lr = 0x8214DA80;
	sub_821BE250(ctx, base);
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// addi r10,r31,112
	ctx.r10.s64 = r31.s64 + 112;
	// lbz r8,68(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 68);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stbx r20,r11,r10
	PPC_STORE_U8(r11.u32 + ctx.r10.u32, r20.u8);
	// beq cr6,0x8214dab4
	if (cr6.eq) goto loc_8214DAB4;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// add r3,r23,r22
	ctx.r3.u64 = r23.u64 + r22.u64;
	// bl 0x823da950
	ctx.lr = 0x8214DAA8;
	sub_823DA950(ctx, base);
	// lbz r11,80(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 80);
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// addi r22,r11,1
	r22.s64 = r11.s64 + 1;
loc_8214DAB4:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DAC4;
	sub_821BE250(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x821c9790
	ctx.lr = 0x8214DAD0;
	sub_821C9790(ctx, base);
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8214db24
	if (cr6.eq) goto loc_8214DB24;
	// mr r11,r20
	r11.u64 = r20.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8214db24
	if (cr6.eq) goto loc_8214DB24;
	// addi r10,r26,4
	ctx.r10.s64 = r26.s64 + 4;
loc_8214DAEC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// beq cr6,0x8214db0c
	if (cr6.eq) goto loc_8214DB0C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x8214daec
	if (cr6.lt) goto loc_8214DAEC;
	// b 0x8214db24
	goto loc_8214DB24;
loc_8214DB0C:
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r9,1
	ctx.r9.s64 = 1;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stwx r7,r8,r26
	PPC_STORE_U32(ctx.r8.u32 + r26.u32, ctx.r7.u32);
loc_8214DB24:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214db4c
	if (!cr6.eq) goto loc_8214DB4C;
	// stw r3,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r3.u32);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
loc_8214DB4C:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,5
	ctx.r10.s64 = r11.s64 + 5;
	// lwz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 5);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,5(r11)
	PPC_STORE_U32(r11.u32 + 5, ctx.r10.u32);
	// bl 0x821be250
	ctx.lr = 0x8214DB84;
	sub_821BE250(ctx, base);
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8214da60
	if (cr6.lt) goto loc_8214DA60;
loc_8214DB94:
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r26.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r21,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r21.u32);
	// stw r23,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r23.u32);
	// stw r11,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r11.u32);
	// bl 0x8214d730
	ctx.lr = 0x8214DBB4;
	sub_8214D730(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DBC4;
	sub_821BE250(ctx, base);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// mr r25,r20
	r25.u64 = r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214dc34
	if (cr6.eq) goto loc_8214DC34;
	// li r26,-1
	r26.s64 = -1;
loc_8214DBD8:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DBE8;
	sub_821BE250(ctx, base);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r29,r10,-8
	r29.s64 = ctx.r10.s64 + -8;
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// lwz r27,0(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r28,r11,r27
	r28.u64 = r11.u64 + r27.u64;
	// lwzx r4,r28,r29
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// bl 0x8214d6b8
	ctx.lr = 0x8214DC0C;
	sub_8214D6B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8214dc1c
	if (!cr6.eq) goto loc_8214DC1C;
	// stwx r26,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, r26.u32);
	// b 0x8214dc24
	goto loc_8214DC24;
loc_8214DC1C:
	// subf r11,r27,r3
	r11.s64 = ctx.r3.s64 - r27.s64;
	// stwx r11,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, r11.u32);
loc_8214DC24:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// blt cr6,0x8214dbd8
	if (cr6.lt) goto loc_8214DBD8;
loc_8214DC34:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8214DC48;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// mr r28,r20
	r28.u64 = r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x8214dc8c
	if (cr6.eq) goto loc_8214DC8C;
	// mr r29,r20
	r29.u64 = r20.u64;
loc_8214DC64:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x8214DC74;
	sub_821C9790(ctx, base);
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stwx r3,r29,r27
	PPC_STORE_U32(r29.u32 + r27.u32, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// blt cr6,0x8214dc64
	if (cr6.lt) goto loc_8214DC64;
loc_8214DC8C:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DC9C;
	sub_821BE250(ctx, base);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// mr r29,r20
	r29.u64 = r20.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214dd30
	if (cr6.eq) goto loc_8214DD30;
loc_8214DCAC:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DCBC;
	sub_821BE250(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r10,r20
	ctx.r10.u64 = r20.u64;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r8,r11,-8
	ctx.r8.s64 = r11.s64 + -8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r8,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r8.u32);
	// ble cr6,0x8214dd14
	if (!cr6.gt) goto loc_8214DD14;
	// lwzx r9,r7,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// mr r11,r20
	r11.u64 = r20.u64;
loc_8214DCEC:
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r27.u32);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// beq cr6,0x8214dd18
	if (cr6.eq) goto loc_8214DD18;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r6,28(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r6
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, xer);
	// blt cr6,0x8214dcec
	if (cr6.lt) goto loc_8214DCEC;
loc_8214DD14:
	// li r10,-1
	ctx.r10.s64 = -1;
loc_8214DD18:
	// clrlwi r11,r10,16
	r11.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwx r11,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, r11.u32);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x8214dcac
	if (cr6.lt) goto loc_8214DCAC;
loc_8214DD30:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r31,480
	ctx.r1.s64 = r31.s64 + 480;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8214DD3C"))) PPC_WEAK_FUNC(sub_8214DD3C);
PPC_FUNC_IMPL(__imp__sub_8214DD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214DD40"))) PPC_WEAK_FUNC(sub_8214DD40);
PPC_FUNC_IMPL(__imp__sub_8214DD40) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8214DD60;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214d6b8
	ctx.lr = 0x8214DD6C;
	sub_8214D6B8(ctx, base);
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

__attribute__((alias("__imp__sub_8214DD80"))) PPC_WEAK_FUNC(sub_8214DD80);
PPC_FUNC_IMPL(__imp__sub_8214DD80) {
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
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82608de8
	ctx.lr = 0x8214DDA0;
	sub_82608DE8(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// addi r30,r11,19856
	r30.s64 = r11.s64 + 19856;
	// beq cr6,0x8214ddbc
	if (cr6.eq) goto loc_8214DDBC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214DDBC;
	sub_82144A78(ctx, base);
loc_8214DDBC:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214ddd0
	if (cr6.eq) goto loc_8214DDD0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214DDD0;
	sub_82144A78(ctx, base);
loc_8214DDD0:
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214dde4
	if (cr6.eq) goto loc_8214DDE4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214DDE4;
	sub_82144A78(ctx, base);
loc_8214DDE4:
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214ddf8
	if (cr6.eq) goto loc_8214DDF8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82144a78
	ctx.lr = 0x8214DDF8;
	sub_82144A78(ctx, base);
loc_8214DDF8:
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

__attribute__((alias("__imp__sub_8214DE10"))) PPC_WEAK_FUNC(sub_8214DE10);
PPC_FUNC_IMPL(__imp__sub_8214DE10) {
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
	ctx.lr = 0x8214DE18;
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
	// bne cr6,0x8214de40
	if (!cr6.eq) goto loc_8214DE40;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x8214DE40;
	sub_82608A98(ctx, base);
loc_8214DE40:
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
	// bne cr6,0x8214de70
	if (!cr6.eq) goto loc_8214DE70;
	// bl 0x821c9438
	ctx.lr = 0x8214DE64;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821bed68
	ctx.lr = 0x8214DE70;
	sub_821BED68(ctx, base);
loc_8214DE70:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x8214DE78;
	sub_821C9550(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,12
	ctx.r3.s64 = 12;
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// twllei r11,0
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r30,r6,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r30,r9
	r29.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x8214DEA4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214dec8
	if (cr6.eq) goto loc_8214DEC8;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lhz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// sth r9,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r9.u16);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// b 0x8214decc
	goto loc_8214DECC;
loc_8214DEC8:
	// li r11,0
	r11.s64 = 0;
loc_8214DECC:
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

__attribute__((alias("__imp__sub_8214DEE4"))) PPC_WEAK_FUNC(sub_8214DEE4);
PPC_FUNC_IMPL(__imp__sub_8214DEE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214DEE8"))) PPC_WEAK_FUNC(sub_8214DEE8);
PPC_FUNC_IMPL(__imp__sub_8214DEE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// sth r11,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, r11.u16);
	// sth r11,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, r11.u16);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stb r11,27(r3)
	PPC_STORE_U8(ctx.r3.u32 + 27, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214DF00"))) PPC_WEAK_FUNC(sub_8214DF00);
PPC_FUNC_IMPL(__imp__sub_8214DF00) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82608de8
	sub_82608DE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214DF08"))) PPC_WEAK_FUNC(sub_8214DF08);
PPC_FUNC_IMPL(__imp__sub_8214DF08) {
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
	ctx.lr = 0x8214DF10;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r22,0
	r22.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r22.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// addi r25,r11,19856
	r25.s64 = r11.s64 + 19856;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// add r4,r21,r11
	ctx.r4.u64 = r21.u64 + r11.u64;
	// bl 0x82144a60
	ctx.lr = 0x8214DF44;
	sub_82144A60(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DF58;
	sub_821BE250(ctx, base);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8214e108
	if (cr6.eq) goto loc_8214E108;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r30,r10,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// subf r27,r30,r9
	r27.s64 = ctx.r9.s64 - r30.s64;
	// add r24,r11,r26
	r24.u64 = r11.u64 + r26.u64;
	// bl 0x823da950
	ctx.lr = 0x8214DF90;
	sub_823DA950(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x8214DFA4;
	sub_823DA950(ctx, base);
	// addi r23,r31,16
	r23.s64 = r31.s64 + 16;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82608de8
	ctx.lr = 0x8214DFB0;
	sub_82608DE8(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82144a78
	ctx.lr = 0x8214DFBC;
	sub_82144A78(ctx, base);
	// stw r22,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r22.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r4,r30,r26
	ctx.r4.u64 = r30.u64 + r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DFD0;
	sub_821BE250(ctx, base);
	// add r11,r27,r29
	r11.u64 = r27.u64 + r29.u64;
	// subf r5,r29,r21
	ctx.r5.s64 = r21.s64 - r29.s64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r4,r11,r26
	ctx.r4.u64 = r11.u64 + r26.u64;
	// bl 0x821be250
	ctx.lr = 0x8214DFE8;
	sub_821BE250(ctx, base);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r11,r22
	r11.u64 = r22.u64;
	// stw r26,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r26.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// ble cr6,0x8214e030
	if (!cr6.gt) goto loc_8214E030;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
loc_8214E000:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// subf r8,r8,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r6,r8,r24
	ctx.r6.u64 = ctx.r8.u64 + r24.u64;
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// blt cr6,0x8214e000
	if (cr6.lt) goto loc_8214E000;
loc_8214E030:
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x8214e07c
	if (!cr6.lt) goto loc_8214E07C;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8214E04C:
	// lwzx r9,r11,r7
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 + r24.u64;
	// add r6,r9,r27
	ctx.r6.u64 = ctx.r9.u64 + r27.u64;
	// stwx r6,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r6.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// blt cr6,0x8214e04c
	if (cr6.lt) goto loc_8214E04C;
loc_8214E07C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r29,r22
	r29.u64 = r22.u64;
	// add. r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8214e0dc
	if (cr0.eq) goto loc_8214E0DC;
	// mr r30,r22
	r30.u64 = r22.u64;
loc_8214E090:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x825edac0
	ctx.lr = 0x8214E0A0;
	sub_825EDAC0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8214e0c0
	if (!cr6.eq) goto loc_8214E0C0;
	// sth r29,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r29.u16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x8214de10
	ctx.lr = 0x8214E0C0;
	sub_8214DE10(ctx, base);
loc_8214E0C0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8214e090
	if (cr6.lt) goto loc_8214E090;
loc_8214E0DC:
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r24,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r24.u32);
	// add r9,r21,r11
	ctx.r9.u64 = r21.u64 + r11.u64;
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r9,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
loc_8214E108:
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be250
	ctx.lr = 0x8214E118;
	sub_821BE250(ctx, base);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,28(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r11,r29,r10
	r11.u64 = r29.u64 + ctx.r10.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// add r11,r9,r26
	r11.u64 = ctx.r9.u64 + r26.u64;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// bge cr6,0x8214e184
	if (!cr6.lt) goto loc_8214E184;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
loc_8214E144:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// sth r29,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r29.u16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// bl 0x8214de10
	ctx.lr = 0x8214E168;
	sub_8214DE10(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r29,r7
	cr6.compare<uint32_t>(r29.u32, ctx.r7.u32, xer);
	// blt cr6,0x8214e144
	if (cr6.lt) goto loc_8214E144;
loc_8214E184:
	// stw r26,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r26.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r21,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r21.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8214E1A0"))) PPC_WEAK_FUNC(sub_8214E1A0);
PPC_FUNC_IMPL(__imp__sub_8214E1A0) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8214e1cc
	if (!cr6.eq) goto loc_8214E1CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8214e1f4
	goto loc_8214E1F4;
loc_8214E1CC:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x8214E1DC;
	sub_821BE250(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r11,-4
	ctx.r5.s64 = r11.s64 + -4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// bl 0x8214df08
	ctx.lr = 0x8214E1F4;
	sub_8214DF08(ctx, base);
loc_8214E1F4:
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

__attribute__((alias("__imp__sub_8214E20C"))) PPC_WEAK_FUNC(sub_8214E20C);
PPC_FUNC_IMPL(__imp__sub_8214E20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214E210"))) PPC_WEAK_FUNC(sub_8214E210);
PPC_FUNC_IMPL(__imp__sub_8214E210) {
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
	ctx.lr = 0x8214E218;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r29,r10,3998
	r29.s64 = ctx.r10.s64 + 3998;
	// lwz r6,56(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// beq cr6,0x8214e274
	if (cr6.eq) goto loc_8214E274;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,17852
	ctx.r4.s64 = r11.s64 + 17852;
	// bl 0x823dc018
	ctx.lr = 0x8214E254;
	sub_823DC018(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821ca778
	ctx.lr = 0x8214E264;
	sub_821CA778(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8214e280
	if (!cr6.eq) goto loc_8214E280;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
loc_8214E274:
	// li r5,255
	ctx.r5.s64 = 255;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823db670
	ctx.lr = 0x8214E280;
	sub_823DB670(ctx, base);
loc_8214E280:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x821ca6a8
	ctx.lr = 0x8214E298;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8214e2b0
	if (!cr6.eq) goto loc_8214E2B0;
loc_8214E2A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9248
	return;
loc_8214E2B0:
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x8214E2C0;
	sub_821BE250(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214d600
	ctx.lr = 0x8214E2CC;
	sub_8214D600(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e2a4
	if (cr6.eq) goto loc_8214E2A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e1a0
	ctx.lr = 0x8214E2E4;
	sub_8214E1A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e2a4
	if (cr6.eq) goto loc_8214E2A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214d930
	ctx.lr = 0x8214E2FC;
	sub_8214D930(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e2a4
	if (cr6.eq) goto loc_8214E2A4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x8214E310;
	sub_821BE610(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214E324"))) PPC_WEAK_FUNC(sub_8214E324);
PPC_FUNC_IMPL(__imp__sub_8214E324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214E328"))) PPC_WEAK_FUNC(sub_8214E328);
PPC_FUNC_IMPL(__imp__sub_8214E328) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r6,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r6.u32);
	// stb r5,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, ctx.r5.u8);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// b 0x8214e210
	sub_8214E210(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214E368"))) PPC_WEAK_FUNC(sub_8214E368);
PPC_FUNC_IMPL(__imp__sub_8214E368) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8214E37C"))) PPC_WEAK_FUNC(sub_8214E37C);
PPC_FUNC_IMPL(__imp__sub_8214E37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214E380"))) PPC_WEAK_FUNC(sub_8214E380);
PPC_FUNC_IMPL(__imp__sub_8214E380) {
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
	// bl 0x8213b968
	ctx.lr = 0x8214E398;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,255
	ctx.r10.s64 = 255;
	// addi r9,r11,18212
	ctx.r9.s64 = r11.s64 + 18212;
	// stb r10,169(r31)
	PPC_STORE_U8(r31.u32 + 169, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8214E3C4"))) PPC_WEAK_FUNC(sub_8214E3C4);
PPC_FUNC_IMPL(__imp__sub_8214E3C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214E3C8"))) PPC_WEAK_FUNC(sub_8214E3C8);
PPC_FUNC_IMPL(__imp__sub_8214E3C8) {
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
	ctx.lr = 0x8214E3D0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r6,r11,7216
	ctx.r6.s64 = r11.s64 + 7216;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r8,168(r30)
	PPC_STORE_U8(r30.u32 + 168, ctx.r8.u8);
	// lwz r10,196(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 196);
	// lbz r7,64(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r11,232(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 232);
	// mulli r9,r7,11488
	ctx.r9.s64 = ctx.r7.s64 * 11488;
	// lbz r5,169(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 169);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + r11.u64;
	// mullw r11,r5,r10
	r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11440(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11440);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// beq cr6,0x8214e5ac
	if (cr6.eq) goto loc_8214E5AC;
	// addi r31,r11,20
	r31.s64 = r11.s64 + 20;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r4,10
	r29.s64 = ctx.r4.s64 + 10;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_8214E42C:
	// lbz r11,-5(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + -5);
	// addi r28,r31,-16
	r28.s64 = r31.s64 + -16;
	// stw r11,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r11.u32);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8214e464
	if (!cr6.eq) goto loc_8214E464;
	// lwz r11,-4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -4);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,-20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + -20, temp.u32);
	// stb r9,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r9.u8);
	// b 0x8214e4a0
	goto loc_8214E4A0;
loc_8214E464:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214E478;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,-20(r31)
	PPC_STORE_U32(r31.u32 + -20, ctx.r3.u32);
	// bne cr6,0x8214e494
	if (!cr6.eq) goto loc_8214E494;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stfs f31,-20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -20, temp.u32);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// b 0x8214e49c
	goto loc_8214E49C;
loc_8214E494:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
loc_8214E49C:
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
loc_8214E4A0:
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8214e4cc
	if (!cr6.eq) goto loc_8214E4CC;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// stb r9,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r9.u8);
	// b 0x8214e50c
	goto loc_8214E50C;
loc_8214E4CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214E4E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8214e4fc
	if (!cr6.eq) goto loc_8214E4FC;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stfs f31,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// b 0x8214e508
	goto loc_8214E508;
loc_8214E4FC:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,26,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
loc_8214E508:
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
loc_8214E50C:
	// lwz r4,16(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8214e538
	if (!cr6.eq) goto loc_8214E538;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stb r9,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r9.u8);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 4, temp.u32);
	// b 0x8214e578
	goto loc_8214E578;
loc_8214E538:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214E54C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r3.u32);
	// bne cr6,0x8214e568
	if (!cr6.eq) goto loc_8214E568;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stfs f31,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 4, temp.u32);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// b 0x8214e574
	goto loc_8214E574;
loc_8214E568:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
loc_8214E574:
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
loc_8214E578:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214E590;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// stw r3,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, ctx.r3.u32);
	// addi r29,r29,29
	r29.s64 = r29.s64 + 29;
	// lbz r9,168(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 168);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// blt cr6,0x8214e42c
	if (cr6.lt) goto loc_8214E42C;
loc_8214E5AC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8214E5B8"))) PPC_WEAK_FUNC(sub_8214E5B8);
PPC_FUNC_IMPL(__imp__sub_8214E5B8) {
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
	// add r31,r4,r3
	r31.u64 = ctx.r4.u64 + ctx.r3.u64;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214e63c
	if (cr6.eq) goto loc_8214E63C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r10,196(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,11440(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8214e63c
	if (cr6.eq) goto loc_8214E63C;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214e634
	if (cr6.eq) goto loc_8214E634;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214e634
	if (cr6.eq) goto loc_8214E634;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214E634;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8214E634:
	// li r11,255
	r11.s64 = 255;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
loc_8214E63C:
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

__attribute__((alias("__imp__sub_8214E650"))) PPC_WEAK_FUNC(sub_8214E650);
PPC_FUNC_IMPL(__imp__sub_8214E650) {
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
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r8,r9,18212
	ctx.r8.s64 = ctx.r9.s64 + 18212;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// rlwinm r7,r10,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8214e6c8
	if (!cr6.eq) goto loc_8214E6C8;
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8214e6c8
	if (cr6.eq) goto loc_8214E6C8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e6c8
	if (cr6.eq) goto loc_8214E6C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x8214E6C8;
	sub_8214E5B8(ctx, base);
loc_8214E6C8:
	// lbz r9,169(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 169);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8214e704
	if (cr6.eq) goto loc_8214E704;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r5,11488
	r11.s64 = ctx.r5.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r9,r8
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213f7a8
	ctx.lr = 0x8214E6FC;
	sub_8213F7A8(ctx, base);
	// li r6,255
	ctx.r6.s64 = 255;
	// stb r6,169(r31)
	PPC_STORE_U8(r31.u32 + 169, ctx.r6.u8);
loc_8214E704:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x8214E70C;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_8214E724"))) PPC_WEAK_FUNC(sub_8214E724);
PPC_FUNC_IMPL(__imp__sub_8214E724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214E728"))) PPC_WEAK_FUNC(sub_8214E728);
PPC_FUNC_IMPL(__imp__sub_8214E728) {
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
	ctx.lr = 0x8214E730;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x8214E744;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e830
	if (cr6.eq) goto loc_8214E830;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r29,148(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82144720
	ctx.lr = 0x8214E774;
	sub_82144720(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// beq cr6,0x8214e7b0
	if (cr6.eq) goto loc_8214E7B0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// b 0x8214e7b4
	goto loc_8214E7B4;
loc_8214E7B0:
	// li r11,255
	r11.s64 = 255;
loc_8214E7B4:
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r4,r9,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// blt cr6,0x8214e830
	if (cr6.lt) goto loc_8214E830;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x8213e928
	ctx.lr = 0x8214E7E4;
	sub_8213E928(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214e830
	if (cr6.eq) goto loc_8214E830;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// twllei r9,0
	// lwz r7,11440(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// divwu r5,r6,r9
	ctx.r5.u32 = ctx.r6.u32 / ctx.r9.u32;
	// stb r5,169(r31)
	PPC_STORE_U8(r31.u32 + 169, ctx.r5.u8);
	// bl 0x8214e3c8
	ctx.lr = 0x8214E824;
	sub_8214E3C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8214E830:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214E83C"))) PPC_WEAK_FUNC(sub_8214E83C);
PPC_FUNC_IMPL(__imp__sub_8214E83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214E840"))) PPC_WEAK_FUNC(sub_8214E840);
PPC_FUNC_IMPL(__imp__sub_8214E840) {
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
	ctx.lr = 0x8214E848;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lbz r9,72(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8214e8c4
	if (cr6.eq) goto loc_8214E8C4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r11,r9
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8214e8c4
	if (cr6.eq) goto loc_8214E8C4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x8214E8A4;
	sub_8213B7B0(ctx, base);
	// lbz r11,57(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r5,r11,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// bl 0x8213da88
	ctx.lr = 0x8214E8BC;
	sub_8213DA88(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8214E8C4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214E8D0"))) PPC_WEAK_FUNC(sub_8214E8D0);
PPC_FUNC_IMPL(__imp__sub_8214E8D0) {
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
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8214e940
	if (cr6.eq) goto loc_8214E940;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8214e940
	if (cr6.eq) goto loc_8214E940;
	// lwz r4,84(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x8214E934;
	sub_8213B7B0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d890
	ctx.lr = 0x8214E940;
	sub_8213D890(ctx, base);
loc_8214E940:
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

__attribute__((alias("__imp__sub_8214E958"))) PPC_WEAK_FUNC(sub_8214E958);
PPC_FUNC_IMPL(__imp__sub_8214E958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r20{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8214E960;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9b8
	ctx.lr = 0x8214E968;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lbz r8,169(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 169);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lbz r6,168(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 168);
	// lwz r11,232(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r10,196(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// mullw r11,r8,r10
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11440(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// stw r4,164(r30)
	PPC_STORE_U32(r30.u32 + 164, ctx.r4.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8214ee6c
	if (cr6.eq) goto loc_8214EE6C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r31,r11,20
	r31.s64 = r11.s64 + 20;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f28,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f28.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f25,8884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f25.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f24,18204(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	f24.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f20,11328(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11328);
	f20.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f21,11332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11332);
	f21.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f26,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	f26.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f22,11324(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11324);
	f22.f64 = double(temp.f32);
	// lfs f23,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	f23.f64 = double(temp.f32);
	// lfs f27,14192(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14192);
	f27.f64 = double(temp.f32);
	// addi r28,r11,17888
	r28.s64 = r11.s64 + 17888;
	// lfs f29,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
loc_8214EA14:
	// lwz r11,-8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214ee58
	if (cr6.eq) goto loc_8214EE58;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214ea3c
	if (cr6.eq) goto loc_8214EA3C;
	// lfs f31,-20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -20);
	f31.f64 = double(temp.f32);
	// b 0x8214ea44
	goto loc_8214EA44;
loc_8214EA3C:
	// lwz r10,-20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -20);
	// lfs f31,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f31.f64 = double(temp.f32);
loc_8214EA44:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214ea5c
	if (cr6.eq) goto loc_8214EA5C;
	// lfs f2,-16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -16);
	ctx.f2.f64 = double(temp.f32);
	// b 0x8214ea64
	goto loc_8214EA64;
loc_8214EA5C:
	// lwz r10,-16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// lfs f2,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
loc_8214EA64:
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// stfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214ea7c
	if (cr6.eq) goto loc_8214EA7C;
	// lfs f0,-12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -12);
	f0.f64 = double(temp.f32);
	// b 0x8214ea84
	goto loc_8214EA84;
loc_8214EA7C:
	// lwz r11,-12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
loc_8214EA84:
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// cmplwi cr6,r11,31
	cr6.compare<uint32_t>(r11.u32, 31, xer);
	// bgt cr6,0x8214ee50
	if (cr6.gt) goto loc_8214EE50;
	// lis r12,-32235
	r12.s64 = -2112552960;
	// addi r12,r12,-5464
	r12.s64 = r12.s64 + -5464;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8214EB28;
	case 1:
		goto loc_8214EB30;
	case 2:
		goto loc_8214EB38;
	case 3:
		goto loc_8214EB40;
	case 4:
		goto loc_8214EB48;
	case 5:
		goto loc_8214EB50;
	case 6:
		goto loc_8214EB90;
	case 7:
		goto loc_8214EB9C;
	case 8:
		goto loc_8214EBA8;
	case 9:
		goto loc_8214EBB0;
	case 10:
		goto loc_8214EBC0;
	case 11:
		goto loc_8214EBD0;
	case 12:
		goto loc_8214EBE0;
	case 13:
		goto loc_8214EBEC;
	case 14:
		goto loc_8214EBFC;
	case 15:
		goto loc_8214EBA8;
	case 16:
		goto loc_8214EC0C;
	case 17:
		goto loc_8214EC18;
	case 18:
		goto loc_8214EC60;
	case 19:
		goto loc_8214ECB0;
	case 20:
		goto loc_8214ECE8;
	case 21:
		goto loc_8214ED04;
	case 22:
		goto loc_8214ED0C;
	case 23:
		goto loc_8214ED18;
	case 24:
		goto loc_8214ED2C;
	case 25:
		goto loc_8214ED50;
	case 26:
		goto loc_8214ED94;
	case 27:
		goto loc_8214EDAC;
	case 28:
		goto loc_8214EDD0;
	case 29:
		goto loc_8214EDE4;
	case 30:
		goto loc_8214EE00;
	case 31:
		goto loc_8214EE24;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-5336(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5336);
	// lwz r16,-5328(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5328);
	// lwz r16,-5320(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5320);
	// lwz r16,-5312(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5312);
	// lwz r16,-5304(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5304);
	// lwz r16,-5296(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5296);
	// lwz r16,-5232(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5232);
	// lwz r16,-5220(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5220);
	// lwz r16,-5208(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5208);
	// lwz r16,-5200(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5200);
	// lwz r16,-5184(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5184);
	// lwz r16,-5168(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5168);
	// lwz r16,-5152(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5152);
	// lwz r16,-5140(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5140);
	// lwz r16,-5124(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5124);
	// lwz r16,-5208(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5208);
	// lwz r16,-5108(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5108);
	// lwz r16,-5096(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5096);
	// lwz r16,-5024(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -5024);
	// lwz r16,-4944(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4944);
	// lwz r16,-4888(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4888);
	// lwz r16,-4860(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4860);
	// lwz r16,-4852(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4852);
	// lwz r16,-4840(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4840);
	// lwz r16,-4820(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4820);
	// lwz r16,-4784(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4784);
	// lwz r16,-4716(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4716);
	// lwz r16,-4692(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4692);
	// lwz r16,-4656(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4656);
	// lwz r16,-4636(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4636);
	// lwz r16,-4608(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4608);
	// lwz r16,-4572(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -4572);
loc_8214EB28:
	// fadds f1,f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f2.f64 + f31.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EB30:
	// fsubs f1,f31,f2
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f2.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EB38:
	// fmuls f1,f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f2.f64 * f31.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EB40:
	// fdivs f1,f31,f2
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 / ctx.f2.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EB48:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EB50:
	// fctidz f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = (f31.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f31.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctidz f0,f2
	f0.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// twllei r11,0
	// divwu r9,r10,r11
	ctx.r9.u32 = ctx.r10.u32 / r11.u32;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// clrldi r6,r7,32
	ctx.r6.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f1,f11
	ctx.f1.f64 = double(float(ctx.f11.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EB90:
	// fsubs f0,f31,f2
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - ctx.f2.f64));
	// fsel f1,f0,f2,f31
	ctx.f1.f64 = f0.f64 >= 0.0 ? ctx.f2.f64 : f31.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EB9C:
	// fsubs f0,f31,f2
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - ctx.f2.f64));
	// fsel f1,f0,f31,f2
	ctx.f1.f64 = f0.f64 >= 0.0 ? f31.f64 : ctx.f2.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EBA8:
	// fabs f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = f31.u64 & ~0x8000000000000000;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EBB0:
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// fsel f13,f0,f30,f29
	ctx.f13.f64 = f0.f64 >= 0.0 ? f30.f64 : f29.f64;
	// fsel f1,f31,f13,f27
	ctx.f1.f64 = f31.f64 >= 0.0 ? ctx.f13.f64 : f27.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EBC0:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823dba38
	ctx.lr = 0x8214EBC8;
	sub_823DBA38(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EBD0:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbaa8
	ctx.lr = 0x8214EBD8;
	sub_823DBAA8(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EBE0:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82145080
	ctx.lr = 0x8214EBE8;
	sub_82145080(ctx, base);
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EBEC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x8214EBF4;
	sub_823DBAE8(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EBFC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8214EC04;
	sub_823DBBC8(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EC0C:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x821493f8
	ctx.lr = 0x8214EC14;
	sub_821493F8(ctx, base);
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EC18:
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stfs f31,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f30,148(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stfs f30,152(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f0,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// lfs f12,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	v62.f32[0] = log2f(v63.f32[0]);
	v62.f32[1] = log2f(v63.f32[1]);
	v62.f32[2] = log2f(v63.f32[2]);
	v62.f32[3] = log2f(v63.f32[3]);
	// lvx128 v61,r28,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v62,v61
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f23
	ctx.f10.f64 = double(float(ctx.f11.f64 * f23.f64));
	// fsel f1,f13,f10,f12
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f10.f64 : ctx.f12.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EC60:
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// stfs f26,88(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx v1,0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f22
	ctx.f10.f64 = double(float(ctx.f11.f64 * f22.f64));
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx v2,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x8214ECA0;
	sub_821476B0(ctx, base);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214ECB0:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823db918
	ctx.lr = 0x8214ECB8;
	sub_823DB918(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fmuls f13,f0,f21
	ctx.f13.f64 = double(float(f0.f64 * f21.f64));
	// fmuls f12,f13,f20
	ctx.f12.f64 = double(float(ctx.f13.f64 * f20.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f10,112(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f1,f9
	ctx.f1.f64 = double(float(ctx.f9.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214ECE8:
	// lwz r10,164(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// std r10,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f0,120(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f25
	ctx.f1.f64 = double(float(ctx.f12.f64 * f25.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214ED04:
	// fsel f1,f31,f2,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214ED0C:
	// fsubs f0,f0,f2
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fmadds f1,f0,f31,f2
	ctx.f1.f64 = double(float(f0.f64 * f31.f64 + ctx.f2.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214ED18:
	// fsubs f13,f31,f2
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f2.f64));
	// fsel f12,f13,f31,f2
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : ctx.f2.f64;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f1,f11,f0,f12
	ctx.f1.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214ED2C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// lvlx v2,0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx v1,0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x8214ED40;
	sub_821476B0(ctx, base);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214ED50:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// bge cr6,0x8214ed6c
	if (!cr6.lt) goto loc_8214ED6C;
	// fsubs f0,f31,f28
	f0.f64 = double(float(f31.f64 - f28.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// b 0x8214ed7c
	goto loc_8214ED7C;
loc_8214ED6C:
	// fadds f0,f31,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 + f28.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_8214ED7C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214ED94:
	// fmuls f1,f31,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 * f24.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8214ED9C;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// fmuls f1,f13,f28
	ctx.f1.f64 = double(float(ctx.f13.f64 * f28.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EDAC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823dba38
	ctx.lr = 0x8214EDB4;
	sub_823DBA38(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// fsubs f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 - f28.f64));
	// fmuls f11,f13,f26
	ctx.f11.f64 = double(float(ctx.f13.f64 * f26.f64));
	// fnmsubs f10,f12,f26,f29
	ctx.f10.f64 = double(float(-(ctx.f12.f64 * f26.f64 - f29.f64)));
	// fsel f1,f12,f10,f11
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? ctx.f10.f64 : ctx.f11.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EDD0:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823dba38
	ctx.lr = 0x8214EDD8;
	sub_823DBA38(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fsubs f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 - f0.f64));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EDE4:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823dba38
	ctx.lr = 0x8214EDEC;
	sub_823DBA38(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// fsubs f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 - f28.f64));
	// fsel f1,f12,f30,f29
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f30.f64 : f29.f64;
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EE00:
	// fsubs f13,f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f2.f64 - f31.f64));
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f9,f11,f30,f29
	ctx.f9.f64 = ctx.f11.f64 >= 0.0 ? f30.f64 : f29.f64;
	// fsel f8,f10,f0,f12
	ctx.f8.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// fsel f7,f13,f9,f27
	ctx.f7.f64 = ctx.f13.f64 >= 0.0 ? ctx.f9.f64 : f27.f64;
	// fnmsubs f1,f7,f8,f2
	ctx.f1.f64 = double(float(-(ctx.f7.f64 * ctx.f8.f64 - ctx.f2.f64)));
	// b 0x8214ee50
	goto loc_8214EE50;
loc_8214EE24:
	// lwz r10,164(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// lfd f0,136(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 / f31.f64));
	// fmuls f31,f11,f25
	f31.f64 = double(float(ctx.f11.f64 * f25.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dba38
	ctx.lr = 0x8214EE48;
	sub_823DBA38(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// fsubs f1,f31,f10
	ctx.f1.f64 = double(float(f31.f64 - ctx.f10.f64));
loc_8214EE50:
	// lwz r11,-8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// stfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_8214EE58:
	// lbz r11,168(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 168);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8214ea14
	if (cr6.lt) goto loc_8214EA14;
loc_8214EE6C:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba04
	ctx.lr = 0x8214EE78;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214EE7C"))) PPC_WEAK_FUNC(sub_8214EE7C);
PPC_FUNC_IMPL(__imp__sub_8214EE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214EE80"))) PPC_WEAK_FUNC(sub_8214EE80);
PPC_FUNC_IMPL(__imp__sub_8214EE80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8213b5c0
	sub_8213B5C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214EEC0"))) PPC_WEAK_FUNC(sub_8214EEC0);
PPC_FUNC_IMPL(__imp__sub_8214EEC0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214EEC4"))) PPC_WEAK_FUNC(sub_8214EEC4);
PPC_FUNC_IMPL(__imp__sub_8214EEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214EEC8"))) PPC_WEAK_FUNC(sub_8214EEC8);
PPC_FUNC_IMPL(__imp__sub_8214EEC8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214e840
	sub_8214E840(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214EECC"))) PPC_WEAK_FUNC(sub_8214EECC);
PPC_FUNC_IMPL(__imp__sub_8214EECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214EED0"))) PPC_WEAK_FUNC(sub_8214EED0);
PPC_FUNC_IMPL(__imp__sub_8214EED0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214e8d0
	sub_8214E8D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214EED4"))) PPC_WEAK_FUNC(sub_8214EED4);
PPC_FUNC_IMPL(__imp__sub_8214EED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214EED8"))) PPC_WEAK_FUNC(sub_8214EED8);
PPC_FUNC_IMPL(__imp__sub_8214EED8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8214ef18
	if (cr6.eq) goto loc_8214EF18;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214ef18
	if (cr6.eq) goto loc_8214EF18;
	// b 0x8213dd40
	sub_8213DD40(ctx, base);
	return;
loc_8214EF18:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214EF20"))) PPC_WEAK_FUNC(sub_8214EF20);
PPC_FUNC_IMPL(__imp__sub_8214EF20) {
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
	// bl 0x8214e650
	ctx.lr = 0x8214EF40;
	sub_8214E650(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214ef68
	if (cr6.eq) goto loc_8214EF68;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8214ef68
	if (cr6.eq) goto loc_8214EF68;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x8214EF68;
	sub_8213F7A8(ctx, base);
loc_8214EF68:
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

__attribute__((alias("__imp__sub_8214EF84"))) PPC_WEAK_FUNC(sub_8214EF84);
PPC_FUNC_IMPL(__imp__sub_8214EF84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214EF88"))) PPC_WEAK_FUNC(sub_8214EF88);
PPC_FUNC_IMPL(__imp__sub_8214EF88) {
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
	// bl 0x8214e958
	ctx.lr = 0x8214EFA8;
	sub_8214E958(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8214eff0
	if (cr6.eq) goto loc_8214EFF0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214eff0
	if (cr6.eq) goto loc_8214EFF0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8213e040
	ctx.lr = 0x8214EFEC;
	sub_8213E040(ctx, base);
	// b 0x8214eff4
	goto loc_8214EFF4;
loc_8214EFF0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214EFF4:
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

__attribute__((alias("__imp__sub_8214F00C"))) PPC_WEAK_FUNC(sub_8214F00C);
PPC_FUNC_IMPL(__imp__sub_8214F00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F010"))) PPC_WEAK_FUNC(sub_8214F010);
PPC_FUNC_IMPL(__imp__sub_8214F010) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214ef88
	sub_8214EF88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214F014"))) PPC_WEAK_FUNC(sub_8214F014);
PPC_FUNC_IMPL(__imp__sub_8214F014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F018"))) PPC_WEAK_FUNC(sub_8214F018);
PPC_FUNC_IMPL(__imp__sub_8214F018) {
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
	// bl 0x8213b968
	ctx.lr = 0x8214F030;
	sub_8213B968(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,-1
	r11.s64 = -1;
	// addi r8,r10,18576
	ctx.r8.s64 = ctx.r10.s64 + 18576;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r11.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// addi r11,r31,164
	r11.s64 = r31.s64 + 164;
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stw r7,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r7.u32);
	// stw r10,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,184(r31)
	PPC_STORE_U8(r31.u32 + 184, ctx.r10.u8);
	// stb r10,185(r31)
	PPC_STORE_U8(r31.u32 + 185, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8214F088"))) PPC_WEAK_FUNC(sub_8214F088);
PPC_FUNC_IMPL(__imp__sub_8214F088) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214f09c
	if (!cr6.eq) goto loc_8214F09C;
	// lfs f0,212(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	f0.f64 = double(temp.f32);
	// b 0x8214f0a0
	goto loc_8214F0A0;
loc_8214F09C:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
loc_8214F0A0:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lwz r11,204(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214f0b8
	if (!cr6.eq) goto loc_8214F0B8;
	// lfs f0,208(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	f0.f64 = double(temp.f32);
	// b 0x8214f0bc
	goto loc_8214F0BC;
loc_8214F0B8:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
loc_8214F0BC:
	// stfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214f0dc
	if (!cr6.eq) goto loc_8214F0DC;
	// lfs f0,216(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
loc_8214F0DC:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214F0EC"))) PPC_WEAK_FUNC(sub_8214F0EC);
PPC_FUNC_IMPL(__imp__sub_8214F0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F0F0"))) PPC_WEAK_FUNC(sub_8214F0F0);
PPC_FUNC_IMPL(__imp__sub_8214F0F0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,18576
	ctx.r10.s64 = r11.s64 + 18576;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8214f154
	if (cr6.eq) goto loc_8214F154;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f154
	if (cr6.eq) goto loc_8214F154;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x8214F154;
	sub_8214E5B8(ctx, base);
loc_8214F154:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x8214F15C;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_8214F170"))) PPC_WEAK_FUNC(sub_8214F170);
PPC_FUNC_IMPL(__imp__sub_8214F170) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8214F178;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x8214F18C;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f310
	if (cr6.eq) goto loc_8214F310;
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8214F1A8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8214f1a8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8214F1A8;
	// lwz r28,148(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r10,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r10.u32);
	// lwz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8214F1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,20(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,216(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// lwz r4,24(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lwz r5,20(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8214F21C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r3.u32);
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,208(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214F248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,28(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8214F264;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214f310
	if (cr6.eq) goto loc_8214F310;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8214F290;
	sub_82144720(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r11,7216
	r11.s64 = r11.s64 + 7216;
	// beq cr6,0x8214f2cc
	if (cr6.eq) goto loc_8214F2CC;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,196(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// twllei r9,0
	// lwz r7,11440(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// subf r6,r7,r3
	ctx.r6.s64 = ctx.r3.s64 - ctx.r7.s64;
	// divwu r5,r6,r9
	ctx.r5.u32 = ctx.r6.u32 / ctx.r9.u32;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// b 0x8214f2d0
	goto loc_8214F2D0;
loc_8214F2CC:
	// li r10,255
	ctx.r10.s64 = 255;
loc_8214F2D0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,72(r31)
	PPC_STORE_U8(r31.u32 + 72, ctx.r10.u8);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8214f310
	if (cr6.eq) goto loc_8214F310;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214f314
	if (!cr6.eq) goto loc_8214F314;
loc_8214F310:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214F314:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214F31C"))) PPC_WEAK_FUNC(sub_8214F31C);
PPC_FUNC_IMPL(__imp__sub_8214F31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F320"))) PPC_WEAK_FUNC(sub_8214F320);
PPC_FUNC_IMPL(__imp__sub_8214F320) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r6,72(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 72);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r6,255
	cr6.compare<uint32_t>(ctx.r6.u32, 255, xer);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x8214f418
	if (cr6.eq) goto loc_8214F418;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 64);
	// addi r10,r11,7216
	ctx.r10.s64 = r11.s64 + 7216;
	// mulli r7,r8,11488
	ctx.r7.s64 = ctx.r8.s64 * 11488;
	// lwz r8,232(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// lwz r11,196(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mullw r8,r11,r6
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r6.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f418
	if (cr6.eq) goto loc_8214F418;
	// lwz r11,192(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f418
	if (cr6.eq) goto loc_8214F418;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8214f088
	ctx.lr = 0x8214F3A4;
	sub_8214F088(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f418
	if (cr6.eq) goto loc_8214F418;
	// lwz r11,192(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lwz r7,192(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// lfs f0,18612(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 18612);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f11,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// bge cr6,0x8214f418
	if (!cr6.lt) goto loc_8214F418;
	// lbz r7,72(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 72);
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// beq cr6,0x8214f40c
	if (cr6.eq) goto loc_8214F40C;
	// lbz r11,64(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 64);
	// lwz r9,232(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,196(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r11,r7
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r7.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8214f410
	goto loc_8214F410;
loc_8214F40C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214F410:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8213d890
	ctx.lr = 0x8214F418;
	sub_8213D890(ctx, base);
loc_8214F418:
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

__attribute__((alias("__imp__sub_8214F42C"))) PPC_WEAK_FUNC(sub_8214F42C);
PPC_FUNC_IMPL(__imp__sub_8214F42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F430"))) PPC_WEAK_FUNC(sub_8214F430);
PPC_FUNC_IMPL(__imp__sub_8214F430) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8214F438;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,72(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214f6f4
	if (cr6.eq) goto loc_8214F6F4;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8214f6f4
	if (cr6.eq) goto loc_8214F6F4;
	// lwz r8,204(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8214f49c
	if (!cr6.eq) goto loc_8214F49C;
	// lfs f30,208(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 208);
	f30.f64 = double(temp.f32);
	// b 0x8214f4a0
	goto loc_8214F4A0;
loc_8214F49C:
	// lfs f30,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f30.f64 = double(temp.f32);
loc_8214F4A0:
	// lwz r8,200(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8214f4b4
	if (!cr6.eq) goto loc_8214F4B4;
	// lfs f31,216(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 216);
	f31.f64 = double(temp.f32);
	// b 0x8214f4b8
	goto loc_8214F4B8;
loc_8214F4B4:
	// lfs f31,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f31.f64 = double(temp.f32);
loc_8214F4B8:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214f4cc
	if (cr6.eq) goto loc_8214F4CC;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// b 0x8214f4d0
	goto loc_8214F4D0;
loc_8214F4CC:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8214F4D0:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x8214f5b0
	if (!cr6.eq) goto loc_8214F5B0;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214f4f0
	if (cr6.eq) goto loc_8214F4F0;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8214f4f4
	goto loc_8214F4F4;
loc_8214F4F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214F4F4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213e040
	ctx.lr = 0x8214F4FC;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214f6c8
	if (!cr6.eq) goto loc_8214F6C8;
	// lwz r11,192(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 + f31.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lwz r10,192(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// lfs f0,18612(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8214f54c
	if (cr6.lt) goto loc_8214F54C;
	// fadds f0,f30,f0
	f0.f64 = double(float(f30.f64 + f0.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8214f55c
	if (cr6.lt) goto loc_8214F55C;
	// b 0x8214f558
	goto loc_8214F558;
loc_8214F54C:
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8214f55c
	if (cr6.gt) goto loc_8214F55C;
loc_8214F558:
	// li r11,0
	r11.s64 = 0;
loc_8214F55C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f6f4
	if (cr6.eq) goto loc_8214F6F4;
	// lbz r11,57(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8214f6f4
	if (!cr6.eq) goto loc_8214F6F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x8214F588;
	sub_8214E5B8(ctx, base);
	// addi r6,r30,164
	ctx.r6.s64 = r30.s64 + 164;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,188(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213b7d0
	ctx.lr = 0x8214F59C;
	sub_8213B7D0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8214F5B0:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214f600
	if (cr6.eq) goto loc_8214F600;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8214f5ec
	if (cr6.eq) goto loc_8214F5EC;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214f5dc
	if (cr6.eq) goto loc_8214F5DC;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// b 0x8214f5e0
	goto loc_8214F5E0;
loc_8214F5DC:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8214F5E0:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8214f610
	if (cr6.eq) goto loc_8214F610;
loc_8214F5EC:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214f600
	if (cr6.eq) goto loc_8214F600;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8214f604
	goto loc_8214F604;
loc_8214F600:
	// li r11,0
	r11.s64 = 0;
loc_8214F604:
	// lhz r11,6(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8214f6f4
	if (!cr6.eq) goto loc_8214F6F4;
loc_8214F610:
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// lbz r10,57(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x8214F624;
	sub_821374B0(ctx, base);
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8214f658
	if (cr6.eq) goto loc_8214F658;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8214f65c
	goto loc_8214F65C;
loc_8214F658:
	// li r11,0
	r11.s64 = 0;
loc_8214F65C:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x8214F66C;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8214f6dc
	if (!cr6.eq) goto loc_8214F6DC;
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8214f6bc
	if (cr6.eq) goto loc_8214F6BC;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213d890
	ctx.lr = 0x8214F6A8;
	sub_8213D890(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8214F6BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x8214F6C8;
	sub_8213D890(ctx, base);
loc_8214F6C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8214F6DC:
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8214F6F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214F708"))) PPC_WEAK_FUNC(sub_8214F708);
PPC_FUNC_IMPL(__imp__sub_8214F708) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8214F710;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// beq cr6,0x8214f810
	if (cr6.eq) goto loc_8214F810;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r10,196(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8214f810
	if (cr6.eq) goto loc_8214F810;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r29.u8);
	// beq cr6,0x8214f790
	if (cr6.eq) goto loc_8214F790;
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8214f794
	goto loc_8214F794;
loc_8214F790:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8214F794:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x8214F79C;
	sub_8213C758(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x8214f810
	if (cr6.eq) goto loc_8214F810;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214f088
	ctx.lr = 0x8214F7BC;
	sub_8214F088(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f810
	if (cr6.eq) goto loc_8214F810;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x8214f7e8
	if (!cr6.gt) goto loc_8214F7E8;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x8214f800
	if (cr6.lt) goto loc_8214F800;
loc_8214F7E8:
	// fcmpu cr6,f12,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f31.f64);
	// bge cr6,0x8214f7f8
	if (!cr6.lt) goto loc_8214F7F8;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8214f800
	if (cr6.gt) goto loc_8214F800;
loc_8214F7F8:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x8214f820
	if (!cr6.eq) goto loc_8214F820;
loc_8214F800:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8214f810
	if (cr6.eq) goto loc_8214F810;
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
loc_8214F810:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8214F820:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8214f82c
	if (cr6.eq) goto loc_8214F82C;
	// stb r29,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r29.u8);
loc_8214F82C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fdivs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 / f0.f64));
	// bl 0x823dba38
	ctx.lr = 0x8214F840;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mullw r3,r10,r30
	ctx.r3.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214F860"))) PPC_WEAK_FUNC(sub_8214F860);
PPC_FUNC_IMPL(__imp__sub_8214F860) {
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
	ctx.lr = 0x8214F868;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// add r29,r5,r30
	r29.u64 = ctx.r5.u64 + r30.u64;
	// lbz r8,72(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8214f90c
	if (cr6.eq) goto loc_8214F90C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f90c
	if (cr6.eq) goto loc_8214F90C;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// lbz r10,57(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r28,r10,30,31,31
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x8214F8C4;
	sub_821374B0(ctx, base);
	// lbz r11,72(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 72);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214f8f8
	if (cr6.eq) goto loc_8214F8F8;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8214f8fc
	goto loc_8214F8FC;
loc_8214F8F8:
	// li r11,0
	r11.s64 = 0;
loc_8214F8FC:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x8214F90C;
	sub_8213DA88(ctx, base);
loc_8214F90C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8214F914"))) PPC_WEAK_FUNC(sub_8214F914);
PPC_FUNC_IMPL(__imp__sub_8214F914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F918"))) PPC_WEAK_FUNC(sub_8214F918);
PPC_FUNC_IMPL(__imp__sub_8214F918) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214f430
	sub_8214F430(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214F91C"))) PPC_WEAK_FUNC(sub_8214F91C);
PPC_FUNC_IMPL(__imp__sub_8214F91C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F920"))) PPC_WEAK_FUNC(sub_8214F920);
PPC_FUNC_IMPL(__imp__sub_8214F920) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r10,57(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214f964
	if (cr6.eq) goto loc_8214F964;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r10,196(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8214f968
	goto loc_8214F968;
loc_8214F964:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214F968:
	// b 0x8213da88
	sub_8213DA88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214F96C"))) PPC_WEAK_FUNC(sub_8214F96C);
PPC_FUNC_IMPL(__imp__sub_8214F96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F970"))) PPC_WEAK_FUNC(sub_8214F970);
PPC_FUNC_IMPL(__imp__sub_8214F970) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214f320
	sub_8214F320(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214F974"))) PPC_WEAK_FUNC(sub_8214F974);
PPC_FUNC_IMPL(__imp__sub_8214F974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F978"))) PPC_WEAK_FUNC(sub_8214F978);
PPC_FUNC_IMPL(__imp__sub_8214F978) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214f708
	sub_8214F708(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8214F97C"))) PPC_WEAK_FUNC(sub_8214F97C);
PPC_FUNC_IMPL(__imp__sub_8214F97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F980"))) PPC_WEAK_FUNC(sub_8214F980);
PPC_FUNC_IMPL(__imp__sub_8214F980) {
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
	// bl 0x8214f0f0
	ctx.lr = 0x8214F9A0;
	sub_8214F0F0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214f9c8
	if (cr6.eq) goto loc_8214F9C8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8214f9c8
	if (cr6.eq) goto loc_8214F9C8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x8214F9C8;
	sub_8213F7A8(ctx, base);
loc_8214F9C8:
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

__attribute__((alias("__imp__sub_8214F9E4"))) PPC_WEAK_FUNC(sub_8214F9E4);
PPC_FUNC_IMPL(__imp__sub_8214F9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214F9E8"))) PPC_WEAK_FUNC(sub_8214F9E8);
PPC_FUNC_IMPL(__imp__sub_8214F9E8) {
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
	// bl 0x8213b968
	ctx.lr = 0x8214FA00;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,18944
	ctx.r9.s64 = r11.s64 + 18944;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r8,184(r31)
	PPC_STORE_U8(r31.u32 + 184, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_8214FA34"))) PPC_WEAK_FUNC(sub_8214FA34);
PPC_FUNC_IMPL(__imp__sub_8214FA34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214FA38"))) PPC_WEAK_FUNC(sub_8214FA38);
PPC_FUNC_IMPL(__imp__sub_8214FA38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r20{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,164(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8214fb7c
	if (cr6.eq) {
		sub_8214FB7C(ctx, base);
		return;
	}
	// lwz r11,172(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214fa5c
	if (!cr6.eq) goto loc_8214FA5C;
	// lfs f0,168(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	f0.f64 = double(temp.f32);
	// b 0x8214fa60
	goto loc_8214FA60;
loc_8214FA5C:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
loc_8214FA60:
	// lwz r11,176(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// stw r10,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r10.u32);
	// bgt cr6,0x8214fb7c
	if (cr6.gt) {
		sub_8214FB7C(ctx, base);
		return;
	}
	// lis r12,-32235
	r12.s64 = -2112552960;
	// addi r12,r12,-1396
	r12.s64 = r12.s64 + -1396;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8214FAA4;
	case 1:
		goto loc_8214FAC4;
	case 2:
		goto loc_8214FAE4;
	case 3:
		goto loc_8214FB04;
	case 4:
		goto loc_8214FB24;
	case 5:
		goto loc_8214FB50;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-1372(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -1372);
	// lwz r16,-1340(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -1340);
	// lwz r16,-1308(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -1308);
	// lwz r16,-1276(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -1276);
	// lwz r16,-1244(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -1244);
	// lwz r16,-1200(r20)
	r16.u64 = PPC_LOAD_U32(r20.u32 + -1200);
loc_8214FAA4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,18612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r11,0
	r11.s64 = 0;
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, r11.u32);
	// blr 
	return;
loc_8214FAC4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,18612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r11,0
	r11.s64 = 0;
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, r11.u32);
	// blr 
	return;
loc_8214FAE4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,18612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// li r11,0
	r11.s64 = 0;
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, r11.u32);
	// blr 
	return;
loc_8214FB04:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,18612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// li r11,0
	r11.s64 = 0;
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, r11.u32);
	// blr 
	return;
loc_8214FB24:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,18612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// bgelr cr6
	if (!cr6.lt) return;
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r11,0
	r11.s64 = 0;
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, r11.u32);
	// blr 
	return;
loc_8214FB50:
	// lis r11,-32256
	r11.s64 = -2113929216;
}

__attribute__((alias("__imp__sub_8214FB7C"))) PPC_WEAK_FUNC(sub_8214FB7C);
PPC_FUNC_IMPL(__imp__sub_8214FB7C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,2
	r11.s64 = 2;
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8214FB88"))) PPC_WEAK_FUNC(sub_8214FB88);
PPC_FUNC_IMPL(__imp__sub_8214FB88) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r10,18944
	ctx.r9.s64 = ctx.r10.s64 + 18944;
	// lbz r11,57(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8214fc40
	if (!cr6.eq) goto loc_8214FC40;
	// lbz r11,72(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// beq cr6,0x8214fc00
	if (cr6.eq) goto loc_8214FC00;
	// lbz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214fc00
	if (cr6.eq) goto loc_8214FC00;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x8214FC00;
	sub_8214E5B8(ctx, base);
loc_8214FC00:
	// lbz r9,73(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8214fc40
	if (cr6.eq) goto loc_8214FC40;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214fc40
	if (cr6.eq) goto loc_8214FC40;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x8214FC40;
	sub_8214E5B8(ctx, base);
loc_8214FC40:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213ba48
	ctx.lr = 0x8214FC48;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_8214FC60"))) PPC_WEAK_FUNC(sub_8214FC60);
PPC_FUNC_IMPL(__imp__sub_8214FC60) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8214FC68;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x8214FC7C;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8214fd80
	if (cr6.eq) goto loc_8214FD80;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,148(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// rlwinm r11,r11,0,20,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC00;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,-1024
	ctx.r9.s64 = r11.s64 + -1024;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r7,20(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r6,184(r31)
	PPC_STORE_U8(r31.u32 + 184, ctx.r6.u8);
	// lwz r5,13(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 13);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,168(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// lwz r4,17(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 17);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8214FCCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8214FCE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,184(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 184);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// lbz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r8,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r8.u32);
	// beq cr6,0x8214fe0c
	if (cr6.eq) goto loc_8214FE0C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214fa38
	ctx.lr = 0x8214FD08;
	sub_8214FA38(ctx, base);
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214fd8c
	if (!cr6.eq) goto loc_8214FD8C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8214FD34;
	sub_82144720(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b910
	ctx.lr = 0x8214FD44;
	sub_8213B910(ctx, base);
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214fd80
	if (cr6.eq) goto loc_8214FD80;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r10,196(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214ff58
	if (!cr6.eq) goto loc_8214FF58;
loc_8214FD80:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
loc_8214FD8C:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8214ff58
	if (!cr6.eq) goto loc_8214FF58;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8214FDB4;
	sub_82144720(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b910
	ctx.lr = 0x8214FDC4;
	sub_8213B910(ctx, base);
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214fe00
	if (cr6.eq) goto loc_8214FE00;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r10,196(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214ff58
	if (!cr6.eq) goto loc_8214FF58;
loc_8214FE00:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
loc_8214FE0C:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8214FE1C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8214fe1c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8214FE1C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r28,r11,19856
	r28.s64 = r11.s64 + 19856;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r28,608
	ctx.r3.s64 = r28.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8214FE50;
	sub_82144720(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// beq cr6,0x8214fe8c
	if (cr6.eq) goto loc_8214FE8C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// b 0x8214fe90
	goto loc_8214FE90;
loc_8214FE8C:
	// li r11,255
	r11.s64 = 255;
loc_8214FE90:
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r28,608
	ctx.r3.s64 = r28.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8214FEAC;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8214fee0
	if (cr6.eq) goto loc_8214FEE0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// b 0x8214fee4
	goto loc_8214FEE4;
loc_8214FEE0:
	// li r11,255
	r11.s64 = 255;
loc_8214FEE4:
	// clrlwi r7,r11,24
	ctx.r7.u64 = r11.u32 & 0xFF;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// stb r7,73(r31)
	PPC_STORE_U8(r31.u32 + 73, ctx.r7.u8);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// beq cr6,0x8214ff20
	if (cr6.eq) goto loc_8214FF20;
	// lbz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r11,r6,11488
	r11.s64 = ctx.r6.s64 * 11488;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,11440(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214ff58
	if (!cr6.eq) goto loc_8214FF58;
loc_8214FF20:
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8214ff4c
	if (cr6.eq) goto loc_8214FF4C;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8214ff58
	if (!cr6.eq) goto loc_8214FF58;
loc_8214FF4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
loc_8214FF58:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8214FF64"))) PPC_WEAK_FUNC(sub_8214FF64);
PPC_FUNC_IMPL(__imp__sub_8214FF64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8214FF68"))) PPC_WEAK_FUNC(sub_8214FF68);
PPC_FUNC_IMPL(__imp__sub_8214FF68) {
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
	ctx.lr = 0x8214FF70;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r27,0
	r27.s64 = 0;
	// lbz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// li r26,1
	r26.s64 = 1;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215004c
	if (cr6.eq) goto loc_8215004C;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82150050
	if (cr6.eq) goto loc_82150050;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8214ffdc
	if (cr6.eq) goto loc_8214FFDC;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8214ffe0
	goto loc_8214FFE0;
loc_8214FFDC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8214FFE0:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x8214FFE8;
	sub_8213B7B0(ctx, base);
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x82150020
	if (cr6.eq) goto loc_82150020;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150024
	goto loc_82150024;
loc_82150020:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150024:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213da88
	ctx.lr = 0x82150030;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82150040
	if (!cr6.eq) goto loc_82150040;
	// li r27,1
	r27.s64 = 1;
	// b 0x8215004c
	goto loc_8215004C;
loc_82150040:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8215004c
	if (!cr6.eq) goto loc_8215004C;
	// li r26,0
	r26.s64 = 0;
loc_8215004C:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82150050:
	// lbz r10,73(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82150108
	if (cr6.eq) goto loc_82150108;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82150108
	if (cr6.eq) goto loc_82150108;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82150098
	if (cr6.eq) goto loc_82150098;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8215009c
	goto loc_8215009C;
loc_82150098:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215009C:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x821500A4;
	sub_8213B7B0(ctx, base);
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x821500dc
	if (cr6.eq) goto loc_821500DC;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821500e0
	goto loc_821500E0;
loc_821500DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821500E0:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213da88
	ctx.lr = 0x821500EC;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x821500fc
	if (!cr6.eq) goto loc_821500FC;
	// li r27,1
	r27.s64 = 1;
	// b 0x82150108
	goto loc_82150108;
loc_821500FC:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82150108
	if (!cr6.eq) goto loc_82150108;
	// li r26,0
	r26.s64 = 0;
loc_82150108:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150120
	if (cr6.eq) goto loc_82150120;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82150120:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82150138"))) PPC_WEAK_FUNC(sub_82150138);
PPC_FUNC_IMPL(__imp__sub_82150138) {
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
	ctx.lr = 0x82150140;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,184(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215015c
	if (!cr6.eq) goto loc_8215015C;
	// bl 0x8214fa38
	ctx.lr = 0x8215015C;
	sub_8214FA38(ctx, base);
loc_8215015C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r6,180(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// bne cr6,0x82150254
	if (!cr6.eq) goto loc_82150254;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82150254
	if (cr6.eq) goto loc_82150254;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r9,11440(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82150254
	if (cr6.eq) goto loc_82150254;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821501bc
	if (cr6.eq) goto loc_821501BC;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821501c0
	goto loc_821501C0;
loc_821501BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821501C0:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x821501C8;
	sub_8213B7B0(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821501f8
	if (cr6.eq) goto loc_821501F8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821501fc
	goto loc_821501FC;
loc_821501F8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821501FC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x82150204;
	sub_8213D890(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82150244
	if (cr6.eq) goto loc_82150244;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150244
	if (cr6.eq) goto loc_82150244;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82150244;
	sub_8214E5B8(ctx, base);
loc_82150244:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e4d8
	ctx.lr = 0x8215024C;
	sub_8213E4D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82150254:
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// bne cr6,0x82150328
	if (!cr6.eq) goto loc_82150328;
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82150328
	if (cr6.eq) goto loc_82150328;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r9,11440(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r8,r7,r9
	ctx.r8.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82150328
	if (cr6.eq) goto loc_82150328;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821502a0
	if (cr6.eq) goto loc_821502A0;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821502a4
	goto loc_821502A4;
loc_821502A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821502A4:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x821502AC;
	sub_8213B7B0(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821502dc
	if (cr6.eq) goto loc_821502DC;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821502e0
	goto loc_821502E0;
loc_821502DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821502E0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x821502E8;
	sub_8213D890(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82150328
	if (cr6.eq) goto loc_82150328;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150328
	if (cr6.eq) goto loc_82150328;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82150328;
	sub_8214E5B8(ctx, base);
loc_82150328:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82150330"))) PPC_WEAK_FUNC(sub_82150330);
PPC_FUNC_IMPL(__imp__sub_82150330) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,180(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82150394
	if (!cr6.eq) goto loc_82150394;
	// lbz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821503f4
	if (cr6.eq) goto loc_821503F4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821503f4
	if (cr6.eq) goto loc_821503F4;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215038c
	if (cr6.eq) goto loc_8215038C;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150390
	goto loc_82150390;
loc_8215038C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150390:
	// b 0x8213e040
	sub_8213E040(ctx, base);
	return;
loc_82150394:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x821503f4
	if (!cr6.eq) goto loc_821503F4;
	// lbz r9,73(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821503f4
	if (cr6.eq) goto loc_821503F4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821503f4
	if (cr6.eq) goto loc_821503F4;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821503ec
	if (cr6.eq) goto loc_821503EC;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821503f0
	goto loc_821503F0;
loc_821503EC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821503F0:
	// b 0x8213e040
	sub_8213E040(ctx, base);
	return;
loc_821503F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821503FC"))) PPC_WEAK_FUNC(sub_821503FC);
PPC_FUNC_IMPL(__imp__sub_821503FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150400"))) PPC_WEAK_FUNC(sub_82150400);
PPC_FUNC_IMPL(__imp__sub_82150400) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r6,180(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// addi r10,r11,7216
	ctx.r10.s64 = r11.s64 + 7216;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lwz r7,232(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 232);
	// lwz r11,196(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// bne cr6,0x82150464
	if (!cr6.eq) goto loc_82150464;
	// lbz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82150464
	if (cr6.eq) goto loc_82150464;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82150464
	if (cr6.eq) goto loc_82150464;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215045c
	if (cr6.eq) goto loc_8215045C;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150460
	goto loc_82150460;
loc_8215045C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150460:
	// b 0x8213b5c0
	sub_8213B5C0(ctx, base);
	return;
loc_82150464:
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r9,73(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821504ac
	if (cr6.eq) goto loc_821504AC;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821504b0
	goto loc_821504B0;
loc_821504AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821504B0:
	// b 0x8213b5c0
	sub_8213B5C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821504B4"))) PPC_WEAK_FUNC(sub_821504B4);
PPC_FUNC_IMPL(__imp__sub_821504B4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821504B8"))) PPC_WEAK_FUNC(sub_821504B8);
PPC_FUNC_IMPL(__imp__sub_821504B8) {
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
	ctx.lr = 0x821504C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82150550
	if (!cr6.eq) goto loc_82150550;
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82150544
	if (cr6.eq) goto loc_82150544;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82150544
	if (cr6.eq) goto loc_82150544;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82150530
	if (cr6.eq) goto loc_82150530;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213c758
	ctx.lr = 0x82150528;
	sub_8213C758(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82150530:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213c758
	ctx.lr = 0x8215053C;
	sub_8213C758(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82150544:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82150550:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821505b4
	if (!cr6.eq) goto loc_821505B4;
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82150544
	if (cr6.eq) goto loc_82150544;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82150544
	if (cr6.eq) goto loc_82150544;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82150530
	if (cr6.eq) goto loc_82150530;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213c758
	ctx.lr = 0x821505AC;
	sub_8213C758(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821505B4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r29.u8);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// stb r29,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r29.u8);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// beq cr6,0x8215062c
	if (cr6.eq) goto loc_8215062C;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r8,11440(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8215062c
	if (cr6.eq) goto loc_8215062C;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82150610
	if (cr6.eq) goto loc_82150610;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// b 0x82150614
	goto loc_82150614;
loc_82150610:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82150614:
	// addi r4,r1,81
	ctx.r4.s64 = ctx.r1.s64 + 81;
	// bl 0x8213c758
	ctx.lr = 0x8215061C;
	sub_8213C758(ctx, base);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82150630
	goto loc_82150630;
loc_8215062C:
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82150630:
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82150688
	if (cr6.eq) goto loc_82150688;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r11,r8
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,11440(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82150688
	if (cr6.eq) goto loc_82150688;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82150678
	if (cr6.eq) goto loc_82150678;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x82150674;
	sub_8213C758(ctx, base);
	// b 0x8215068c
	goto loc_8215068C;
loc_82150678:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x82150684;
	sub_8213C758(ctx, base);
	// b 0x8215068c
	goto loc_8215068C;
loc_82150688:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8215068C:
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x821506dc
	if (!cr6.eq) goto loc_821506DC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x821506c4
	if (cr6.eq) goto loc_821506C4;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821506c4
	if (cr6.eq) goto loc_821506C4;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821506d0
	if (cr6.eq) goto loc_821506D0;
	// li r11,1
	r11.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821506C4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821506d0
	if (cr6.eq) goto loc_821506D0;
	// stb r29,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r29.u8);
loc_821506D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821506DC:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x821506e8
	if (cr6.eq) goto loc_821506E8;
	// stb r29,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r29.u8);
loc_821506E8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821506F4"))) PPC_WEAK_FUNC(sub_821506F4);
PPC_FUNC_IMPL(__imp__sub_821506F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821506F8"))) PPC_WEAK_FUNC(sub_821506F8);
PPC_FUNC_IMPL(__imp__sub_821506F8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82150330
	sub_82150330(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821506FC"))) PPC_WEAK_FUNC(sub_821506FC);
PPC_FUNC_IMPL(__imp__sub_821506FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150700"))) PPC_WEAK_FUNC(sub_82150700);
PPC_FUNC_IMPL(__imp__sub_82150700) {
	PPC_FUNC_PROLOGUE();
	// b 0x82150400
	sub_82150400(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82150704"))) PPC_WEAK_FUNC(sub_82150704);
PPC_FUNC_IMPL(__imp__sub_82150704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150708"))) PPC_WEAK_FUNC(sub_82150708);
PPC_FUNC_IMPL(__imp__sub_82150708) {
	PPC_FUNC_PROLOGUE();
	// b 0x8214ff68
	sub_8214FF68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215070C"))) PPC_WEAK_FUNC(sub_8215070C);
PPC_FUNC_IMPL(__imp__sub_8215070C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150710"))) PPC_WEAK_FUNC(sub_82150710);
PPC_FUNC_IMPL(__imp__sub_82150710) {
	PPC_FUNC_PROLOGUE();
	// b 0x82150138
	sub_82150138(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82150714"))) PPC_WEAK_FUNC(sub_82150714);
PPC_FUNC_IMPL(__imp__sub_82150714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150718"))) PPC_WEAK_FUNC(sub_82150718);
PPC_FUNC_IMPL(__imp__sub_82150718) {
	PPC_FUNC_PROLOGUE();
	// b 0x821504b8
	sub_821504B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215071C"))) PPC_WEAK_FUNC(sub_8215071C);
PPC_FUNC_IMPL(__imp__sub_8215071C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150720"))) PPC_WEAK_FUNC(sub_82150720);
PPC_FUNC_IMPL(__imp__sub_82150720) {
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
	// bl 0x8214fb88
	ctx.lr = 0x82150740;
	sub_8214FB88(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150768
	if (cr6.eq) goto loc_82150768;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82150768
	if (cr6.eq) goto loc_82150768;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82150768;
	sub_8213F7A8(ctx, base);
loc_82150768:
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

__attribute__((alias("__imp__sub_82150784"))) PPC_WEAK_FUNC(sub_82150784);
PPC_FUNC_IMPL(__imp__sub_82150784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150788"))) PPC_WEAK_FUNC(sub_82150788);
PPC_FUNC_IMPL(__imp__sub_82150788) {
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
	// bl 0x8213b968
	ctx.lr = 0x821507A0;
	sub_8213B968(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,255
	r11.s64 = 255;
	// addi r9,r10,19312
	ctx.r9.s64 = ctx.r10.s64 + 19312;
	// stb r11,172(r31)
	PPC_STORE_U8(r31.u32 + 172, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,173(r31)
	PPC_STORE_U8(r31.u32 + 173, r11.u8);
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

__attribute__((alias("__imp__sub_821507D0"))) PPC_WEAK_FUNC(sub_821507D0);
PPC_FUNC_IMPL(__imp__sub_821507D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,164(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// addi r8,r11,7216
	ctx.r8.s64 = r11.s64 + 7216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r6,232(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// beq cr6,0x82150838
	if (cr6.eq) goto loc_82150838;
	// lbz r7,64(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,196(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mulli r7,r7,11488
	ctx.r7.s64 = ctx.r7.s64 * 11488;
	// lbz r5,172(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 172);
	// add r31,r7,r6
	r31.u64 = ctx.r7.u64 + ctx.r6.u64;
	// mullw r7,r5,r9
	ctx.r7.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// lwz r9,11440(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 11440);
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// beq cr6,0x82150838
	if (cr6.eq) goto loc_82150838;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_8215081C:
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r5,r4
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, xer);
	// beq cr6,0x8215089c
	if (cr6.eq) goto loc_8215089C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8215081c
	if (cr6.lt) goto loc_8215081C;
loc_82150838:
	// lwz r7,168(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82150890
	if (cr6.eq) goto loc_82150890;
	// lbz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// li r11,0
	r11.s64 = 0;
	// lwz r10,200(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 200);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lbz r8,173(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 173);
	// add r6,r9,r6
	ctx.r6.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mullw r9,r8,r10
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq cr6,0x82150890
	if (cr6.eq) goto loc_82150890;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_82150874:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x821508b0
	if (cr6.eq) goto loc_821508B0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x82150874
	if (cr6.lt) goto loc_82150874;
loc_82150890:
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8215089C:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_821508B0:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821508C4"))) PPC_WEAK_FUNC(sub_821508C4);
PPC_FUNC_IMPL(__imp__sub_821508C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821508C8"))) PPC_WEAK_FUNC(sub_821508C8);
PPC_FUNC_IMPL(__imp__sub_821508C8) {
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
	ctx.lr = 0x821508D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r8,r9,19312
	ctx.r8.s64 = ctx.r9.s64 + 19312;
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82150928
	if (cr6.eq) goto loc_82150928;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150928
	if (cr6.eq) goto loc_82150928;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x82150928;
	sub_8214E5B8(ctx, base);
loc_82150928:
	// lbz r9,172(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 172);
	// li r29,255
	r29.s64 = 255;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82150964
	if (cr6.eq) goto loc_82150964;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r5,11488
	r11.s64 = ctx.r5.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r9,r8
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213f7a8
	ctx.lr = 0x82150960;
	sub_8213F7A8(ctx, base);
	// stb r29,172(r31)
	PPC_STORE_U8(r31.u32 + 172, r29.u8);
loc_82150964:
	// lbz r5,173(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 173);
	// cmplwi cr6,r5,255
	cr6.compare<uint32_t>(ctx.r5.u32, 255, xer);
	// beq cr6,0x82150980
	if (cr6.eq) goto loc_82150980;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213ec58
	ctx.lr = 0x8215097C;
	sub_8213EC58(ctx, base);
	// stb r29,173(r31)
	PPC_STORE_U8(r31.u32 + 173, r29.u8);
loc_82150980:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x82150988;
	sub_8213BA48(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82150990"))) PPC_WEAK_FUNC(sub_82150990);
PPC_FUNC_IMPL(__imp__sub_82150990) {
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
	ctx.lr = 0x82150998;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x821509AC;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821509c4
	if (!cr6.eq) goto loc_821509C4;
loc_821509B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821509C4:
	// lwz r29,148(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// li r28,0
	r28.s64 = 0;
	// stw r28,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r28.u32);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r28,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r28.u32);
	// lbz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82150a24
	if (cr6.eq) goto loc_82150A24;
	// addi r10,r29,13
	ctx.r10.s64 = r29.s64 + 13;
loc_821509E8:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x82150a04
	if (!cr6.eq) goto loc_82150A04;
	// lwz r9,168(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r9.u32);
	// b 0x82150a10
	goto loc_82150A10;
loc_82150A04:
	// lwz r9,164(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r9.u32);
loc_82150A10:
	// lbz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,9
	ctx.r10.s64 = ctx.r10.s64 + 9;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x821509e8
	if (cr6.lt) goto loc_821509E8;
loc_82150A24:
	// lwz r10,164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// ble cr6,0x82150ae0
	if (!cr6.gt) goto loc_82150AE0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,196(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213e928
	ctx.lr = 0x82150A4C;
	sub_8213E928(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821509b8
	if (cr6.eq) goto loc_821509B8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lwz r8,164(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r6,11440(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// subf r5,r6,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r6.s64;
	// divwu r4,r5,r10
	ctx.r4.u32 = ctx.r5.u32 / ctx.r10.u32;
	// stb r4,172(r31)
	PPC_STORE_U8(r31.u32 + 172, ctx.r4.u8);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// rlwinm r10,r11,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// bgt cr6,0x821509b8
	if (cr6.gt) goto loc_821509B8;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150ae0
	if (cr6.eq) goto loc_82150AE0;
	// addi r11,r29,5
	r11.s64 = r29.s64 + 5;
loc_82150AA4:
	// lbz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82150acc
	if (!cr6.eq) goto loc_82150ACC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
loc_82150ACC:
	// lbz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,9
	r11.s64 = r11.s64 + 9;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x82150aa4
	if (cr6.lt) goto loc_82150AA4;
loc_82150AE0:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150b7c
	if (cr6.eq) goto loc_82150B7C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8213eb00
	ctx.lr = 0x82150AFC;
	sub_8213EB00(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821509b8
	if (cr6.eq) goto loc_821509B8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,200(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r7,11444(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// subf r6,r7,r3
	ctx.r6.s64 = ctx.r3.s64 - ctx.r7.s64;
	// divwu r5,r6,r10
	ctx.r5.u32 = ctx.r6.u32 / ctx.r10.u32;
	// stb r5,173(r31)
	PPC_STORE_U8(r31.u32 + 173, ctx.r5.u8);
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150b7c
	if (cr6.eq) goto loc_82150B7C;
	// addi r11,r29,5
	r11.s64 = r29.s64 + 5;
loc_82150B40:
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x82150b68
	if (!cr6.eq) goto loc_82150B68;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
loc_82150B68:
	// lbz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,9
	r11.s64 = r11.s64 + 9;
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// blt cr6,0x82150b40
	if (cr6.lt) goto loc_82150B40;
loc_82150B7C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x82150B9C;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82150bd0
	if (cr6.eq) goto loc_82150BD0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// b 0x82150bd4
	goto loc_82150BD4;
loc_82150BD0:
	// li r11,255
	r11.s64 = 255;
loc_82150BD4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821509b8
	if (cr6.eq) goto loc_821509B8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821509b8
	if (cr6.eq) goto loc_821509B8;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82150C1C"))) PPC_WEAK_FUNC(sub_82150C1C);
PPC_FUNC_IMPL(__imp__sub_82150C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150C20"))) PPC_WEAK_FUNC(sub_82150C20);
PPC_FUNC_IMPL(__imp__sub_82150C20) {
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
	ctx.lr = 0x82150C28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82150c74
	if (cr6.eq) goto loc_82150C74;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150c78
	goto loc_82150C78;
loc_82150C74:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150C78:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82150C80;
	sub_8213B7B0(ctx, base);
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x82150cc8
	if (cr6.eq) goto loc_82150CC8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213da88
	ctx.lr = 0x82150CC0;
	sub_8213DA88(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82150CC8:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213da88
	ctx.lr = 0x82150CD8;
	sub_8213DA88(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82150CE0"))) PPC_WEAK_FUNC(sub_82150CE0);
PPC_FUNC_IMPL(__imp__sub_82150CE0) {
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
	ctx.lr = 0x82150CE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82150d30
	if (cr6.eq) goto loc_82150D30;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150d34
	goto loc_82150D34;
loc_82150D30:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150D34:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82150D3C;
	sub_8213B7B0(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82150d78
	if (cr6.eq) goto loc_82150D78;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213d890
	ctx.lr = 0x82150D70;
	sub_8213D890(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82150D78:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x82150D84;
	sub_8213D890(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82150D8C"))) PPC_WEAK_FUNC(sub_82150D8C);
PPC_FUNC_IMPL(__imp__sub_82150D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150D90"))) PPC_WEAK_FUNC(sub_82150D90);
PPC_FUNC_IMPL(__imp__sub_82150D90) {
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
	// bl 0x821507d0
	ctx.lr = 0x82150DA8;
	sub_821507D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82150db8
	if (!cr6.eq) goto loc_82150DB8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ca88
	ctx.lr = 0x82150DB8;
	sub_8213CA88(ctx, base);
loc_82150DB8:
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

__attribute__((alias("__imp__sub_82150DCC"))) PPC_WEAK_FUNC(sub_82150DCC);
PPC_FUNC_IMPL(__imp__sub_82150DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150DD0"))) PPC_WEAK_FUNC(sub_82150DD0);
PPC_FUNC_IMPL(__imp__sub_82150DD0) {
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
	// bl 0x821507d0
	ctx.lr = 0x82150DE8;
	sub_821507D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82150e78
	if (!cr6.eq) goto loc_82150E78;
	// lbz r9,5(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82150e2c
	if (cr6.eq) goto loc_82150E2C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82150e50
	if (!cr6.eq) goto loc_82150E50;
loc_82150E2C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// addi r3,r11,380
	ctx.r3.s64 = r11.s64 + 380;
	// bl 0x82149078
	ctx.lr = 0x82150E3C;
	sub_82149078(ctx, base);
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
loc_82150E50:
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82150e64
	if (cr6.eq) goto loc_82150E64;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150e68
	goto loc_82150E68;
loc_82150E64:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150E68:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82150E78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82150E78:
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

__attribute__((alias("__imp__sub_82150E8C"))) PPC_WEAK_FUNC(sub_82150E8C);
PPC_FUNC_IMPL(__imp__sub_82150E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150E90"))) PPC_WEAK_FUNC(sub_82150E90);
PPC_FUNC_IMPL(__imp__sub_82150E90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82150ec8
	if (cr6.eq) goto loc_82150EC8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150ecc
	goto loc_82150ECC;
loc_82150EC8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150ECC:
	// b 0x8213e040
	sub_8213E040(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82150ED0"))) PPC_WEAK_FUNC(sub_82150ED0);
PPC_FUNC_IMPL(__imp__sub_82150ED0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82150f08
	if (cr6.eq) goto loc_82150F08;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150f0c
	goto loc_82150F0C;
loc_82150F08:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150F0C:
	// b 0x8213b5c0
	sub_8213B5C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82150F10"))) PPC_WEAK_FUNC(sub_82150F10);
PPC_FUNC_IMPL(__imp__sub_82150F10) {
	PPC_FUNC_PROLOGUE();
	// b 0x82150c20
	sub_82150C20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82150F14"))) PPC_WEAK_FUNC(sub_82150F14);
PPC_FUNC_IMPL(__imp__sub_82150F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150F18"))) PPC_WEAK_FUNC(sub_82150F18);
PPC_FUNC_IMPL(__imp__sub_82150F18) {
	PPC_FUNC_PROLOGUE();
	// b 0x82150ce0
	sub_82150CE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82150F1C"))) PPC_WEAK_FUNC(sub_82150F1C);
PPC_FUNC_IMPL(__imp__sub_82150F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150F20"))) PPC_WEAK_FUNC(sub_82150F20);
PPC_FUNC_IMPL(__imp__sub_82150F20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82150f58
	if (cr6.eq) goto loc_82150F58;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82150f5c
	goto loc_82150F5C;
loc_82150F58:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82150F5C:
	// b 0x8213c758
	sub_8213C758(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82150F60"))) PPC_WEAK_FUNC(sub_82150F60);
PPC_FUNC_IMPL(__imp__sub_82150F60) {
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
	// bl 0x821508c8
	ctx.lr = 0x82150F80;
	sub_821508C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82150fa8
	if (cr6.eq) goto loc_82150FA8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82150fa8
	if (cr6.eq) goto loc_82150FA8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82150FA8;
	sub_8213F7A8(ctx, base);
loc_82150FA8:
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

__attribute__((alias("__imp__sub_82150FC4"))) PPC_WEAK_FUNC(sub_82150FC4);
PPC_FUNC_IMPL(__imp__sub_82150FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82150FC8"))) PPC_WEAK_FUNC(sub_82150FC8);
PPC_FUNC_IMPL(__imp__sub_82150FC8) {
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
	// bl 0x8213b968
	ctx.lr = 0x82150FE0;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,19680
	ctx.r10.s64 = r11.s64 + 19680;
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

__attribute__((alias("__imp__sub_82151004"))) PPC_WEAK_FUNC(sub_82151004);
PPC_FUNC_IMPL(__imp__sub_82151004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151008"))) PPC_WEAK_FUNC(sub_82151008);
PPC_FUNC_IMPL(__imp__sub_82151008) {
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
	// bl 0x8213e680
	ctx.lr = 0x82151020;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82151044
	if (!cr6.eq) goto loc_82151044;
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
loc_82151044:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82151060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r8,r3
	ctx.r8.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
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

__attribute__((alias("__imp__sub_82151084"))) PPC_WEAK_FUNC(sub_82151084);
PPC_FUNC_IMPL(__imp__sub_82151084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151088"))) PPC_WEAK_FUNC(sub_82151088);
PPC_FUNC_IMPL(__imp__sub_82151088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwz r9,164(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,0(r9)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821510B4"))) PPC_WEAK_FUNC(sub_821510B4);
PPC_FUNC_IMPL(__imp__sub_821510B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821510B8"))) PPC_WEAK_FUNC(sub_821510B8);
PPC_FUNC_IMPL(__imp__sub_821510B8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,19680
	ctx.r10.s64 = r11.s64 + 19680;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8213ba48
	ctx.lr = 0x821510E4;
	sub_8213BA48(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82151104
	if (cr6.eq) goto loc_82151104;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82151104;
	sub_8213F7A8(ctx, base);
loc_82151104:
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

__attribute__((alias("__imp__sub_82151120"))) PPC_WEAK_FUNC(sub_82151120);
PPC_FUNC_IMPL(__imp__sub_82151120) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82151134
	if (cr6.eq) goto loc_82151134;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8213d6b0
	sub_8213D6B0(ctx, base);
	return;
loc_82151134:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215113C"))) PPC_WEAK_FUNC(sub_8215113C);
PPC_FUNC_IMPL(__imp__sub_8215113C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151140"))) PPC_WEAK_FUNC(sub_82151140);
PPC_FUNC_IMPL(__imp__sub_82151140) {
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
	// bl 0x8213b968
	ctx.lr = 0x82151158;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,20048
	ctx.r10.s64 = r11.s64 + 20048;
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

__attribute__((alias("__imp__sub_8215117C"))) PPC_WEAK_FUNC(sub_8215117C);
PPC_FUNC_IMPL(__imp__sub_8215117C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151180"))) PPC_WEAK_FUNC(sub_82151180);
PPC_FUNC_IMPL(__imp__sub_82151180) {
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
	// bl 0x8213e680
	ctx.lr = 0x82151190;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_821511B0"))) PPC_WEAK_FUNC(sub_821511B0);
PPC_FUNC_IMPL(__imp__sub_821511B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r3,-1
	ctx.r3.s64 = -1;
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821511C8"))) PPC_WEAK_FUNC(sub_821511C8);
PPC_FUNC_IMPL(__imp__sub_821511C8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,20048
	ctx.r10.s64 = r11.s64 + 20048;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8213ba48
	ctx.lr = 0x821511F4;
	sub_8213BA48(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82151214
	if (cr6.eq) goto loc_82151214;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82151214;
	sub_8213F7A8(ctx, base);
loc_82151214:
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

__attribute__((alias("__imp__sub_82151230"))) PPC_WEAK_FUNC(sub_82151230);
PPC_FUNC_IMPL(__imp__sub_82151230) {
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
	// bl 0x8213b968
	ctx.lr = 0x82151248;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,20416
	ctx.r10.s64 = r11.s64 + 20416;
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

__attribute__((alias("__imp__sub_8215126C"))) PPC_WEAK_FUNC(sub_8215126C);
PPC_FUNC_IMPL(__imp__sub_8215126C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151270"))) PPC_WEAK_FUNC(sub_82151270);
PPC_FUNC_IMPL(__imp__sub_82151270) {
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
	// bl 0x8213e680
	ctx.lr = 0x82151288;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821512ac
	if (!cr6.eq) goto loc_821512AC;
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
loc_821512AC:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821512C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_821512E4"))) PPC_WEAK_FUNC(sub_821512E4);
PPC_FUNC_IMPL(__imp__sub_821512E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821512E8"))) PPC_WEAK_FUNC(sub_821512E8);
PPC_FUNC_IMPL(__imp__sub_821512E8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,20416
	ctx.r10.s64 = r11.s64 + 20416;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8213ba48
	ctx.lr = 0x82151314;
	sub_8213BA48(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82151334
	if (cr6.eq) goto loc_82151334;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82151334;
	sub_8213F7A8(ctx, base);
loc_82151334:
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

__attribute__((alias("__imp__sub_82151350"))) PPC_WEAK_FUNC(sub_82151350);
PPC_FUNC_IMPL(__imp__sub_82151350) {
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
	// bl 0x8213b968
	ctx.lr = 0x82151368;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// addi r10,r11,20784
	ctx.r10.s64 = r11.s64 + 20784;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82163ee8
	ctx.lr = 0x8215137C;
	sub_82163EE8(ctx, base);
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

__attribute__((alias("__imp__sub_82151394"))) PPC_WEAK_FUNC(sub_82151394);
PPC_FUNC_IMPL(__imp__sub_82151394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151398"))) PPC_WEAK_FUNC(sub_82151398);
PPC_FUNC_IMPL(__imp__sub_82151398) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,20784
	ctx.r10.s64 = r11.s64 + 20784;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821513fc
	if (cr6.eq) goto loc_821513FC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821513fc
	if (cr6.eq) goto loc_821513FC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x821513FC;
	sub_8214E5B8(ctx, base);
loc_821513FC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x82151404;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_82151418"))) PPC_WEAK_FUNC(sub_82151418);
PPC_FUNC_IMPL(__imp__sub_82151418) {
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
	ctx.lr = 0x82151420;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x82151434;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82151518
	if (cr6.eq) goto loc_82151518;
	// lwz r28,148(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x821514b0
	if (cr6.eq) goto loc_821514B0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8215146C;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821514a8
	if (cr6.eq) goto loc_821514A8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r8,r11,7216
	ctx.r8.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r11,232(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// lwz r10,196(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r6,11440(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// subf r5,r6,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r6.s64;
	// divwu r4,r5,r10
	ctx.r4.u32 = ctx.r5.u32 / ctx.r10.u32;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// b 0x821514ac
	goto loc_821514AC;
loc_821514A8:
	// li r11,255
	r11.s64 = 255;
loc_821514AC:
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
loc_821514B0:
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// bl 0x82164840
	ctx.lr = 0x821514BC;
	sub_82164840(ctx, base);
	// lbz r11,210(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 210);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82151518
	if (cr6.eq) goto loc_82151518;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821514E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821514FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82151518
	if (cr6.eq) goto loc_82151518;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215151c
	if (!cr6.eq) goto loc_8215151C;
loc_82151518:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215151C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82151524"))) PPC_WEAK_FUNC(sub_82151524);
PPC_FUNC_IMPL(__imp__sub_82151524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151528"))) PPC_WEAK_FUNC(sub_82151528);
PPC_FUNC_IMPL(__imp__sub_82151528) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x82151530;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82164db8
	ctx.lr = 0x8215154C;
	sub_82164DB8(ctx, base);
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821515fc
	if (cr6.eq) goto loc_821515FC;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821515fc
	if (cr6.eq) goto loc_821515FC;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821515a8
	if (cr6.eq) goto loc_821515A8;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821515ac
	goto loc_821515AC;
loc_821515A8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821515AC:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x821515B4;
	sub_8213B7B0(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821515f0
	if (cr6.eq) goto loc_821515F0;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213d890
	ctx.lr = 0x821515E8;
	sub_8213D890(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821515F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x821515FC;
	sub_8213D890(ctx, base);
loc_821515FC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82151604"))) PPC_WEAK_FUNC(sub_82151604);
PPC_FUNC_IMPL(__imp__sub_82151604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151608"))) PPC_WEAK_FUNC(sub_82151608);
PPC_FUNC_IMPL(__imp__sub_82151608) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x82151610;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821516c0
	if (cr6.eq) goto loc_821516C0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821516c0
	if (cr6.eq) goto loc_821516C0;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// addi r3,r30,172
	ctx.r3.s64 = r30.s64 + 172;
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82164db8
	ctx.lr = 0x82151668;
	sub_82164DB8(ctx, base);
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821516ac
	if (cr6.eq) goto loc_821516AC;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213e040
	ctx.lr = 0x821516A4;
	sub_8213E040(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821516AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213e040
	ctx.lr = 0x821516B8;
	sub_8213E040(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821516C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821516CC"))) PPC_WEAK_FUNC(sub_821516CC);
PPC_FUNC_IMPL(__imp__sub_821516CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821516D0"))) PPC_WEAK_FUNC(sub_821516D0);
PPC_FUNC_IMPL(__imp__sub_821516D0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82151608
	sub_82151608(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821516D4"))) PPC_WEAK_FUNC(sub_821516D4);
PPC_FUNC_IMPL(__imp__sub_821516D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821516D8"))) PPC_WEAK_FUNC(sub_821516D8);
PPC_FUNC_IMPL(__imp__sub_821516D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82151728
	if (cr6.eq) goto loc_82151728;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215172c
	goto loc_8215172C;
loc_82151728:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215172C:
	// b 0x8213b5c0
	sub_8213B5C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82151730"))) PPC_WEAK_FUNC(sub_82151730);
PPC_FUNC_IMPL(__imp__sub_82151730) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82151734"))) PPC_WEAK_FUNC(sub_82151734);
PPC_FUNC_IMPL(__imp__sub_82151734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151738"))) PPC_WEAK_FUNC(sub_82151738);
PPC_FUNC_IMPL(__imp__sub_82151738) {
	PPC_FUNC_PROLOGUE();
	// b 0x82151528
	sub_82151528(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215173C"))) PPC_WEAK_FUNC(sub_8215173C);
PPC_FUNC_IMPL(__imp__sub_8215173C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151740"))) PPC_WEAK_FUNC(sub_82151740);
PPC_FUNC_IMPL(__imp__sub_82151740) {
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
	// bl 0x82151398
	ctx.lr = 0x82151760;
	sub_82151398(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82151788
	if (cr6.eq) goto loc_82151788;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82151788
	if (cr6.eq) goto loc_82151788;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82151788;
	sub_8213F7A8(ctx, base);
loc_82151788:
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

__attribute__((alias("__imp__sub_821517A4"))) PPC_WEAK_FUNC(sub_821517A4);
PPC_FUNC_IMPL(__imp__sub_821517A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821517A8"))) PPC_WEAK_FUNC(sub_821517A8);
PPC_FUNC_IMPL(__imp__sub_821517A8) {
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
	// bl 0x8213b968
	ctx.lr = 0x821517C0;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,21152
	ctx.r8.s64 = r11.s64 + 21152;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r7,255
	ctx.r7.s64 = 255;
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r10,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r10.u32);
	// stw r10,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r10.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stb r11,184(r31)
	PPC_STORE_U8(r31.u32 + 184, r11.u8);
	// stb r11,185(r31)
	PPC_STORE_U8(r31.u32 + 185, r11.u8);
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// stb r11,229(r31)
	PPC_STORE_U8(r31.u32 + 229, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,230(r31)
	PPC_STORE_U8(r31.u32 + 230, r11.u8);
	// stb r7,228(r31)
	PPC_STORE_U8(r31.u32 + 228, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_82151824"))) PPC_WEAK_FUNC(sub_82151824);
PPC_FUNC_IMPL(__imp__sub_82151824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151828"))) PPC_WEAK_FUNC(sub_82151828);
PPC_FUNC_IMPL(__imp__sub_82151828) {
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
	ctx.lr = 0x82151830;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,231(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 231);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// beq cr6,0x821518a8
	if (cr6.eq) goto loc_821518A8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r7,192(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f12,f13,f13,f0
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fsubs f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 - f0.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fsel f7,f9,f0,f12
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// fmuls f1,f7,f8
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// bl 0x823dba38
	ctx.lr = 0x82151884;
	sub_823DBA38(ctx, base);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x821518c0
	if (cr6.lt) goto loc_821518C0;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// b 0x821518c0
	goto loc_821518C0;
loc_821518A8:
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dba38
	ctx.lr = 0x821518B0;
	sub_823DBA38(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_821518C0:
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x8215195c
	if (!cr6.lt) goto loc_8215195C;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bgt cr6,0x82151900
	if (cr6.gt) goto loc_82151900;
	// addi r11,r11,49
	r11.s64 = r11.s64 + 49;
	// addi r6,r31,164
	ctx.r6.s64 = r31.s64 + 164;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x8213b7d0
	ctx.lr = 0x821518F0;
	sub_8213B7D0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,230(r31)
	PPC_STORE_U8(r31.u32 + 230, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82151900:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r7,228(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 228);
	// addi r29,r10,7216
	r29.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r11,232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 232);
	// lwz r10,196(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 196);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// mullw r11,r7,r10
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// addi r6,r31,164
	ctx.r6.s64 = r31.s64 + 164;
	// lwzx r4,r8,r30
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// bl 0x8213b7d0
	ctx.lr = 0x8215193C;
	sub_8213B7D0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8213f7a8
	ctx.lr = 0x8215194C;
	sub_8213F7A8(ctx, base);
	// li r5,255
	ctx.r5.s64 = 255;
	// li r11,1
	r11.s64 = 1;
	// stb r5,228(r31)
	PPC_STORE_U8(r31.u32 + 228, ctx.r5.u8);
	// stb r11,230(r31)
	PPC_STORE_U8(r31.u32 + 230, r11.u8);
loc_8215195C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82151964"))) PPC_WEAK_FUNC(sub_82151964);
PPC_FUNC_IMPL(__imp__sub_82151964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151968"))) PPC_WEAK_FUNC(sub_82151968);
PPC_FUNC_IMPL(__imp__sub_82151968) {
	PPC_FUNC_PROLOGUE();
	// b 0x82151828
	sub_82151828(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215196C"))) PPC_WEAK_FUNC(sub_8215196C);
PPC_FUNC_IMPL(__imp__sub_8215196C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151970"))) PPC_WEAK_FUNC(sub_82151970);
PPC_FUNC_IMPL(__imp__sub_82151970) {
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
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r8,r9,21152
	ctx.r8.s64 = ctx.r9.s64 + 21152;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// rlwinm r7,r10,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x821519e8
	if (!cr6.eq) goto loc_821519E8;
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821519e8
	if (cr6.eq) goto loc_821519E8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821519e8
	if (cr6.eq) goto loc_821519E8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x821519E8;
	sub_8214E5B8(ctx, base);
loc_821519E8:
	// lbz r9,228(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 228);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82151a24
	if (cr6.eq) goto loc_82151A24;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r5,11488
	r11.s64 = ctx.r5.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r9,r8
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213f7a8
	ctx.lr = 0x82151A1C;
	sub_8213F7A8(ctx, base);
	// li r6,255
	ctx.r6.s64 = 255;
	// stb r6,228(r31)
	PPC_STORE_U8(r31.u32 + 228, ctx.r6.u8);
loc_82151A24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x82151A2C;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_82151A44"))) PPC_WEAK_FUNC(sub_82151A44);
PPC_FUNC_IMPL(__imp__sub_82151A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151A48"))) PPC_WEAK_FUNC(sub_82151A48);
PPC_FUNC_IMPL(__imp__sub_82151A48) {
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
	ctx.lr = 0x82151A50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x82151A60;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82151a78
	if (!cr6.eq) goto loc_82151A78;
loc_82151A6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82151A78:
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82151A88:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82151a88
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82151A88;
	// lwz r29,148(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82151AB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82151a6c
	if (cr6.eq) goto loc_82151A6C;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r11,r11,0,20,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC00;
	// addi r10,r11,-1024
	ctx.r10.s64 = r11.s64 + -1024;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,231(r31)
	PPC_STORE_U8(r31.u32 + 231, ctx.r8.u8);
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// bgt cr6,0x82151b2c
	if (cr6.gt) goto loc_82151B2C;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82151bc4
	if (cr6.eq) goto loc_82151BC4;
	// addi r10,r31,196
	ctx.r10.s64 = r31.s64 + 196;
	// addi r11,r29,5
	r11.s64 = r29.s64 + 5;
loc_82151B00:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r7,192(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x82151b00
	if (cr6.lt) goto loc_82151B00;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82151B2C:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,64
	cr6.compare<uint32_t>(r11.u32, 64, xer);
	// ble cr6,0x82151b3c
	if (!cr6.gt) goto loc_82151B3C;
	// li r11,64
	r11.s64 = 64;
loc_82151B3C:
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r6,1
	ctx.r6.s64 = 1;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// li r4,256
	ctx.r4.s64 = 256;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213e928
	ctx.lr = 0x82151B5C;
	sub_8213E928(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82151a6c
	if (cr6.eq) goto loc_82151A6C;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r7,r8,11488
	ctx.r7.s64 = ctx.r8.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// add r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 + r11.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// twllei r8,0
	// lwz r4,11440(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// subf r3,r4,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r4.s64;
	// divwu r11,r3,r8
	r11.u32 = ctx.r3.u32 / ctx.r8.u32;
	// stb r11,228(r31)
	PPC_STORE_U8(r31.u32 + 228, r11.u8);
	// ble cr6,0x82151bc4
	if (!cr6.gt) goto loc_82151BC4;
	// addi r11,r29,5
	r11.s64 = r29.s64 + 5;
loc_82151BA4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r7,192(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x82151ba4
	if (cr6.lt) goto loc_82151BA4;
loc_82151BC4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82151BD0"))) PPC_WEAK_FUNC(sub_82151BD0);
PPC_FUNC_IMPL(__imp__sub_82151BD0) {
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
	ctx.lr = 0x82151BD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// add r28,r5,r31
	r28.u64 = ctx.r5.u64 + r31.u64;
	// lbz r11,72(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82151d1c
	if (cr6.eq) goto loc_82151D1C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82151d1c
	if (cr6.eq) goto loc_82151D1C;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82151c40
	if (cr6.eq) goto loc_82151C40;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82151c44
	goto loc_82151C44;
loc_82151C40:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82151C44:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82151C4C;
	sub_8213B7B0(ctx, base);
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x82151C60;
	sub_821374B0(ctx, base);
	// lbz r11,72(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 72);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82151c94
	if (cr6.eq) goto loc_82151C94;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82151c98
	goto loc_82151C98;
loc_82151C94:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82151C98:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x82151CA8;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x82151cc4
	if (cr6.eq) goto loc_82151CC4;
	// li r11,1
	r11.s64 = 1;
	// stb r27,230(r31)
	PPC_STORE_U8(r31.u32 + 230, r27.u8);
	// stb r11,229(r31)
	PPC_STORE_U8(r31.u32 + 229, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82151CC4:
	// lbz r8,72(r28)
	ctx.r8.u64 = PPC_LOAD_U8(r28.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82151d04
	if (cr6.eq) goto loc_82151D04;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213d890
	ctx.lr = 0x82151CF8;
	sub_8213D890(ctx, base);
	// stb r27,230(r31)
	PPC_STORE_U8(r31.u32 + 230, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82151D04:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213d890
	ctx.lr = 0x82151D10;
	sub_8213D890(ctx, base);
	// stb r27,230(r31)
	PPC_STORE_U8(r31.u32 + 230, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82151D1C:
	// li r11,0
	r11.s64 = 0;
	// stb r11,230(r31)
	PPC_STORE_U8(r31.u32 + 230, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82151D2C"))) PPC_WEAK_FUNC(sub_82151D2C);
PPC_FUNC_IMPL(__imp__sub_82151D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151D30"))) PPC_WEAK_FUNC(sub_82151D30);
PPC_FUNC_IMPL(__imp__sub_82151D30) {
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
	ctx.lr = 0x82151D38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lbz r11,229(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 229);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82151e78
	if (cr6.eq) goto loc_82151E78;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x82151D64;
	sub_821374B0(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r28,0
	r28.s64 = 0;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82151da4
	if (cr6.eq) goto loc_82151DA4;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82151da8
	goto loc_82151DA8;
loc_82151DA4:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82151DA8:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x82151DB8;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82151ddc
	if (!cr6.eq) goto loc_82151DDC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82151DCC;
	sub_8214E5B8(ctx, base);
	// stb r28,229(r31)
	PPC_STORE_U8(r31.u32 + 229, r28.u8);
loc_82151DD0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82151DDC:
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82151e6c
	if (!cr6.eq) goto loc_82151E6C;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// stb r28,229(r31)
	PPC_STORE_U8(r31.u32 + 229, r28.u8);
	// beq cr6,0x82151e1c
	if (cr6.eq) goto loc_82151E1C;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82151e20
	goto loc_82151E20;
loc_82151E1C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82151E20:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82151E28;
	sub_8213B7B0(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82151e58
	if (cr6.eq) goto loc_82151E58;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82151e5c
	goto loc_82151E5C;
loc_82151E58:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82151E5C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213d890
	ctx.lr = 0x82151E64;
	sub_8213D890(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e4d8
	ctx.lr = 0x82151E6C;
	sub_8213E4D8(ctx, base);
loc_82151E6C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82151E78:
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82151ee0
	if (cr6.eq) goto loc_82151EE0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82151ee0
	if (cr6.eq) goto loc_82151EE0;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82151ec8
	if (cr6.eq) goto loc_82151EC8;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82151ecc
	goto loc_82151ECC;
loc_82151EC8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82151ECC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213e040
	ctx.lr = 0x82151ED4;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82151eec
	if (!cr6.eq) goto loc_82151EEC;
loc_82151EE0:
	// lbz r11,230(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 230);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82151dd0
	if (cr6.eq) goto loc_82151DD0;
loc_82151EEC:
	// lbz r11,230(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 230);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82151e6c
	if (!cr6.eq) goto loc_82151E6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e4d8
	ctx.lr = 0x82151F00;
	sub_8213E4D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82151F0C"))) PPC_WEAK_FUNC(sub_82151F0C);
PPC_FUNC_IMPL(__imp__sub_82151F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151F10"))) PPC_WEAK_FUNC(sub_82151F10);
PPC_FUNC_IMPL(__imp__sub_82151F10) {
	PPC_FUNC_PROLOGUE();
	// b 0x82151d30
	sub_82151D30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82151F14"))) PPC_WEAK_FUNC(sub_82151F14);
PPC_FUNC_IMPL(__imp__sub_82151F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151F18"))) PPC_WEAK_FUNC(sub_82151F18);
PPC_FUNC_IMPL(__imp__sub_82151F18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82151f70
	if (cr6.eq) goto loc_82151F70;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82151f70
	if (cr6.eq) goto loc_82151F70;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82151f68
	if (cr6.eq) goto loc_82151F68;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82151f6c
	goto loc_82151F6C;
loc_82151F68:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82151F6C:
	// b 0x8213c758
	sub_8213C758(ctx, base);
	return;
loc_82151F70:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82151F78"))) PPC_WEAK_FUNC(sub_82151F78);
PPC_FUNC_IMPL(__imp__sub_82151F78) {
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
	// bl 0x82151970
	ctx.lr = 0x82151F98;
	sub_82151970(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82151fc0
	if (cr6.eq) goto loc_82151FC0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82151fc0
	if (cr6.eq) goto loc_82151FC0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82151FC0;
	sub_8213F7A8(ctx, base);
loc_82151FC0:
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

__attribute__((alias("__imp__sub_82151FDC"))) PPC_WEAK_FUNC(sub_82151FDC);
PPC_FUNC_IMPL(__imp__sub_82151FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82151FE0"))) PPC_WEAK_FUNC(sub_82151FE0);
PPC_FUNC_IMPL(__imp__sub_82151FE0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// fmr f30,f3
	f30.f64 = ctx.f3.f64;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// blt cr6,0x82152050
	if (cr6.lt) goto loc_82152050;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// bne cr6,0x82152014
	if (!cr6.eq) goto loc_82152014;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// b 0x82152050
	goto loc_82152050;
loc_82152014:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82152034
	if (!cr6.lt) goto loc_82152034;
	// fsubs f2,f30,f31
	ctx.f2.f64 = double(float(f30.f64 - f31.f64));
	// fsubs f1,f31,f1
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// bl 0x823dc100
	ctx.lr = 0x82152028;
	sub_823DC100(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fsubs f1,f30,f0
	ctx.f1.f64 = double(float(f30.f64 - f0.f64));
	// b 0x82152050
	goto loc_82152050;
loc_82152034:
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// ble cr6,0x82152050
	if (!cr6.gt) goto loc_82152050;
	// fsubs f2,f30,f31
	ctx.f2.f64 = double(float(f30.f64 - f31.f64));
	// fsubs f1,f1,f30
	ctx.f1.f64 = double(float(ctx.f1.f64 - f30.f64));
	// bl 0x823dc100
	ctx.lr = 0x82152048;
	sub_823DC100(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 + f31.f64));
loc_82152050:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82152068"))) PPC_WEAK_FUNC(sub_82152068);
PPC_FUNC_IMPL(__imp__sub_82152068) {
	PPC_FUNC_PROLOGUE();
	// b 0x8213c5d0
	sub_8213C5D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215206C"))) PPC_WEAK_FUNC(sub_8215206C);
PPC_FUNC_IMPL(__imp__sub_8215206C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152070"))) PPC_WEAK_FUNC(sub_82152070);
PPC_FUNC_IMPL(__imp__sub_82152070) {
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
	// bl 0x8213b968
	ctx.lr = 0x82152088;
	sub_8213B968(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,255
	r11.s64 = 255;
	// addi r9,r10,21520
	ctx.r9.s64 = ctx.r10.s64 + 21520;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
	// stb r11,74(r31)
	PPC_STORE_U8(r31.u32 + 74, r11.u8);
	// stb r11,75(r31)
	PPC_STORE_U8(r31.u32 + 75, r11.u8);
	// stb r11,76(r31)
	PPC_STORE_U8(r31.u32 + 76, r11.u8);
	// stb r11,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r11.u8);
	// stb r11,78(r31)
	PPC_STORE_U8(r31.u32 + 78, r11.u8);
	// stb r11,79(r31)
	PPC_STORE_U8(r31.u32 + 79, r11.u8);
	// stb r8,176(r31)
	PPC_STORE_U8(r31.u32 + 176, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_821520D8"))) PPC_WEAK_FUNC(sub_821520D8);
PPC_FUNC_IMPL(__imp__sub_821520D8) {
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
	ctx.lr = 0x821520E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r9,r11,21520
	ctx.r9.s64 = r11.s64 + 21520;
	// lwz r10,164(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82152190
	if (!cr6.gt) goto loc_82152190;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// subfic r27,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r27.s64 = -72 - r30.s64;
	// li r28,255
	r28.s64 = 255;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82152118:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215217c
	if (cr6.eq) goto loc_8215217C;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8215217c
	if (cr6.eq) goto loc_8215217C;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82152174
	if (cr6.eq) goto loc_82152174;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82152174
	if (cr6.eq) goto loc_82152174;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82152174;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82152174:
	// stb r28,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r28.u8);
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_8215217C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// add r10,r27,r29
	ctx.r10.u64 = r27.u64 + r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82152118
	if (cr6.lt) goto loc_82152118;
loc_82152190:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213ba48
	ctx.lr = 0x82152198;
	sub_8213BA48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821521A0"))) PPC_WEAK_FUNC(sub_821521A0);
PPC_FUNC_IMPL(__imp__sub_821521A0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x821521A8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x821521BC;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821521d4
	if (!cr6.eq) goto loc_821521D4;
loc_821521C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_821521D4:
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r25,148(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r11,r11,0,20,21
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC00;
	// addi r8,r11,-1024
	ctx.r8.s64 = r11.s64 + -1024;
	// lfs f0,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lbz r7,4(r25)
	ctx.r7.u64 = PPC_LOAD_U8(r25.u32 + 4);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stb r5,177(r31)
	PPC_STORE_U8(r31.u32 + 177, ctx.r5.u8);
	// stw r7,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r7.u32);
	// lhz r4,9(r25)
	ctx.r4.u64 = PPC_LOAD_U16(r25.u32 + 9);
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f9,168(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// lwz r10,5(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 5);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f8,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,172(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// fcmpu cr6,f8,f13
	cr6.compare(ctx.f8.f64, ctx.f13.f64);
	// beq cr6,0x821521c8
	if (cr6.eq) goto loc_821521C8;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82152250:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82152250
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82152250;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// li r23,1
	r23.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82152350
	if (!cr6.gt) goto loc_82152350;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r26,r31,72
	r26.s64 = r31.s64 + 72;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// addi r27,r10,19856
	r27.s64 = ctx.r10.s64 + 19856;
loc_8215228C:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8215229C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8215229c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8215229C;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r27,608
	ctx.r3.s64 = r27.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x821522C8;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821522fc
	if (cr6.eq) goto loc_821522FC;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// b 0x82152300
	goto loc_82152300;
loc_821522FC:
	// li r11,255
	r11.s64 = 255;
loc_82152300:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stbx r11,r26,r28
	PPC_STORE_U8(r26.u32 + r28.u32, r11.u8);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215233c
	if (cr6.eq) goto loc_8215233C;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82152340
	if (!cr6.eq) goto loc_82152340;
loc_8215233C:
	// li r23,0
	r23.s64 = 0;
loc_82152340:
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x8215228c
	if (cr6.lt) goto loc_8215228C;
loc_82152350:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8215235C"))) PPC_WEAK_FUNC(sub_8215235C);
PPC_FUNC_IMPL(__imp__sub_8215235C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152360"))) PPC_WEAK_FUNC(sub_82152360);
PPC_FUNC_IMPL(__imp__sub_82152360) {
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
	ctx.lr = 0x82152368;
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
	// li r25,1
	r25.s64 = 1;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82152464
	if (!cr6.gt) goto loc_82152464;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r31,72
	r29.s64 = r31.s64 + 72;
	// subfic r26,r31,-72
	xer.ca = r31.u32 <= 4294967224;
	r26.s64 = -72 - r31.s64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
loc_82152398:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82152450
	if (cr6.eq) goto loc_82152450;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r10,11440(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82152450
	if (cr6.eq) goto loc_82152450;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821523e8
	if (cr6.eq) goto loc_821523E8;
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821523ec
	goto loc_821523EC;
loc_821523E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821523EC:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x821523F4;
	sub_8213B7B0(ctx, base);
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x8215242c
	if (cr6.eq) goto loc_8215242C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82152430
	goto loc_82152430;
loc_8215242C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152430:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213da88
	ctx.lr = 0x8215243C;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8215247c
	if (cr6.eq) goto loc_8215247C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82152450
	if (!cr6.eq) goto loc_82152450;
	// li r25,0
	r25.s64 = 0;
loc_82152450:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// add r10,r26,r29
	ctx.r10.u64 = r26.u64 + r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82152398
	if (cr6.lt) goto loc_82152398;
loc_82152464:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8215247C:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82152488"))) PPC_WEAK_FUNC(sub_82152488);
PPC_FUNC_IMPL(__imp__sub_82152488) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82152490;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9bc
	ctx.lr = 0x82152498;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrldi r11,r26,32
	r11.u64 = r26.u64 & 0xFFFFFFFF;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f11,172(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 172);
	ctx.f11.f64 = double(temp.f32);
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// li r25,0
	r25.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f29,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f1,f10,f11
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// bl 0x82151fe0
	ctx.lr = 0x821524F0;
	sub_82151FE0(ctx, base);
	// lwz r7,164(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// fmr f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = ctx.f1.f64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// fdivs f21,f30,f7
	f21.f64 = double(float(f30.f64 / ctx.f7.f64));
	// beq cr6,0x821527b4
	if (cr6.eq) goto loc_821527B4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f24,11368(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11368);
	f24.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfd f25,21576(r9)
	f25.u64 = PPC_LOAD_U64(ctx.r9.u32 + 21576);
	// lfs f26,21568(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21568);
	f26.f64 = double(temp.f32);
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// lfs f27,18204(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 18204);
	f27.f64 = double(temp.f32);
	// subfic r27,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r27.s64 = -72 - r30.s64;
	// lfs f28,14884(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	f28.f64 = double(temp.f32);
	// addi r28,r10,21232
	r28.s64 = ctx.r10.s64 + 21232;
	// lfd f23,21560(r5)
	f23.u64 = PPC_LOAD_U64(ctx.r5.u32 + 21560);
loc_82152564:
	// lbz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821527a0
	if (cr6.eq) goto loc_821527A0;
	// lbz r7,64(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r7,11488
	ctx.r9.s64 = ctx.r7.s64 * 11488;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821527a0
	if (cr6.eq) goto loc_821527A0;
	// add r11,r27,r29
	r11.u64 = r27.u64 + r29.u64;
	// clrldi r10,r11,32
	ctx.r10.u64 = r11.u64 & 0xFFFFFFFF;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmadds f31,f12,f21,f22
	f31.f64 = double(float(ctx.f12.f64 * f21.f64 + f22.f64));
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// bge cr6,0x821525d0
	if (!cr6.lt) goto loc_821525D0;
	// fmr f2,f23
	ctx.f2.f64 = f23.f64;
	// fneg f1,f31
	ctx.f1.u64 = f31.u64 ^ 0x8000000000000000;
	// bl 0x823dc100
	ctx.lr = 0x821525C4;
	sub_823DC100(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fsubs f31,f30,f0
	f31.f64 = double(float(f30.f64 - f0.f64));
	// b 0x821525e8
	goto loc_821525E8;
loc_821525D0:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x821525e8
	if (!cr6.gt) goto loc_821525E8;
	// fmr f2,f23
	ctx.f2.f64 = f23.f64;
	// fsubs f1,f31,f30
	ctx.f1.f64 = double(float(f31.f64 - f30.f64));
	// bl 0x823dc100
	ctx.lr = 0x821525E4;
	sub_823DC100(ctx, base);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
loc_821525E8:
	// fsubs f0,f31,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - f28.f64));
	// fmuls f1,f0,f27
	ctx.f1.f64 = double(float(f0.f64 * f27.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x821525F4;
	sub_823DBBC8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(f30.f64 - ctx.f13.f64));
	// fmuls f2,f12,f26
	ctx.f2.f64 = double(float(ctx.f12.f64 * f26.f64));
	// bl 0x823dc480
	ctx.lr = 0x82152608;
	sub_823DC480(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f29,100(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lbz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// stfs f29,104(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	v61.f32[0] = log2f(v62.f32[0]);
	v61.f32[1] = log2f(v62.f32[1]);
	v61.f32[2] = log2f(v62.f32[2]);
	v61.f32[3] = log2f(v62.f32[3]);
	// vmulfp128 v60,v61,v63
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f11,f24
	ctx.f13.f64 = double(float(ctx.f11.f64 * f24.f64));
	// beq cr6,0x8215266c
	if (cr6.eq) goto loc_8215266C;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82152670
	goto loc_82152670;
loc_8215266C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152670:
	// lfs f12,-24(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -24);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f0,-28(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -28);
	f0.f64 = double(temp.f32);
	// fsel f1,f12,f13,f0
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// bl 0x8213b768
	ctx.lr = 0x82152684;
	sub_8213B768(ctx, base);
	// lfs f11,168(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 168);
	ctx.f11.f64 = double(temp.f32);
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmadds f0,f9,f31,f10
	f0.f64 = double(float(ctx.f9.f64 * f31.f64 + ctx.f10.f64));
	// beq cr6,0x821526c4
	if (cr6.eq) goto loc_821526C4;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,11440(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821526c8
	goto loc_821526C8;
loc_821526C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821526C8:
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, f0.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x8213b770
	ctx.lr = 0x821526D8;
	sub_8213B770(ctx, base);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82152708
	if (cr6.eq) goto loc_82152708;
	// lbz r7,64(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r7,r7,11488
	ctx.r7.s64 = ctx.r7.s64 * 11488;
	// add r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r9,11440(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// b 0x8215270c
	goto loc_8215270C;
loc_82152708:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8215270C:
	// lhz r9,6(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x82152764
	if (!cr6.eq) goto loc_82152764;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82152740
	if (cr6.eq) goto loc_82152740;
	// lbz r8,64(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82152744
	goto loc_82152744;
loc_82152740:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152744:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213e040
	ctx.lr = 0x8215274C;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// beq cr6,0x821527a0
	if (cr6.eq) goto loc_821527A0;
	// li r25,1
	r25.s64 = 1;
	// b 0x821527a0
	goto loc_821527A0;
loc_82152764:
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215278c
	if (cr6.eq) goto loc_8215278C;
	// lbz r7,64(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r7,11488
	ctx.r10.s64 = ctx.r7.s64 * 11488;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// b 0x82152790
	goto loc_82152790;
loc_8215278C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82152790:
	// lhz r10,6(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bne cr6,0x821527a0
	if (!cr6.eq) goto loc_821527A0;
	// li r24,1
	r24.s64 = 1;
loc_821527A0:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r10,164(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// add r9,r27,r29
	ctx.r9.u64 = r27.u64 + r29.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x82152564
	if (cr6.lt) goto loc_82152564;
loc_821527B4:
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821527d4
	if (!cr6.eq) goto loc_821527D4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba08
	ctx.lr = 0x821527D0;
	// b 0x823d9238
	return;
loc_821527D4:
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821528a4
	if (cr6.eq) goto loc_821528A4;
	// lbz r10,177(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 177);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821528a4
	if (cr6.eq) goto loc_821528A4;
	// lbz r10,176(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 176);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x821528a4
	if (!cr6.eq) goto loc_821528A4;
	// lwz r10,164(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x8215289c
	if (!cr6.gt) goto loc_8215289C;
	// addi r6,r30,72
	ctx.r6.s64 = r30.s64 + 72;
	// subfic r5,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	ctx.r5.s64 = -72 - r30.s64;
loc_8215280C:
	// lbz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82152888
	if (cr6.eq) goto loc_82152888;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82152888
	if (cr6.eq) goto loc_82152888;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82152850
	if (cr6.eq) goto loc_82152850;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82152854
	goto loc_82152854;
loc_82152850:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82152854:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82152888
	if (!cr6.eq) goto loc_82152888;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82152874
	if (cr6.eq) goto loc_82152874;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82152878
	goto loc_82152878;
loc_82152874:
	// li r11,0
	r11.s64 = 0;
loc_82152878:
	// lbz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 56);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,56(r11)
	PPC_STORE_U8(r11.u32 + 56, ctx.r9.u8);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82152888:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lwz r10,164(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// add r9,r6,r5
	ctx.r9.u64 = ctx.r6.u64 + ctx.r5.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x8215280c
	if (cr6.lt) goto loc_8215280C;
loc_8215289C:
	// li r11,1
	r11.s64 = 1;
	// stb r11,176(r30)
	PPC_STORE_U8(r30.u32 + 176, r11.u8);
loc_821528A4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba08
	ctx.lr = 0x821528B4;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821528B8"))) PPC_WEAK_FUNC(sub_821528B8);
PPC_FUNC_IMPL(__imp__sub_821528B8) {
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
	ctx.lr = 0x821528C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8215294c
	if (!cr6.gt) goto loc_8215294C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// subfic r28,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r28.s64 = -72 - r30.s64;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_821528E8:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82152938
	if (cr6.eq) goto loc_82152938;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82152938
	if (cr6.eq) goto loc_82152938;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215292c
	if (cr6.eq) goto loc_8215292C;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82152930
	goto loc_82152930;
loc_8215292C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152930:
	// bl 0x8213b5c0
	ctx.lr = 0x82152934;
	sub_8213B5C0(ctx, base);
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82152938:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// add r10,r28,r29
	ctx.r10.u64 = r28.u64 + r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821528e8
	if (cr6.lt) goto loc_821528E8;
loc_8215294C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82152954"))) PPC_WEAK_FUNC(sub_82152954);
PPC_FUNC_IMPL(__imp__sub_82152954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152958"))) PPC_WEAK_FUNC(sub_82152958);
PPC_FUNC_IMPL(__imp__sub_82152958) {
	PPC_FUNC_PROLOGUE();
	// b 0x82152488
	sub_82152488(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215295C"))) PPC_WEAK_FUNC(sub_8215295C);
PPC_FUNC_IMPL(__imp__sub_8215295C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152960"))) PPC_WEAK_FUNC(sub_82152960);
PPC_FUNC_IMPL(__imp__sub_82152960) {
	PPC_FUNC_PROLOGUE();
	// b 0x821528b8
	sub_821528B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82152964"))) PPC_WEAK_FUNC(sub_82152964);
PPC_FUNC_IMPL(__imp__sub_82152964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152968"))) PPC_WEAK_FUNC(sub_82152968);
PPC_FUNC_IMPL(__imp__sub_82152968) {
	PPC_FUNC_PROLOGUE();
	// b 0x82152360
	sub_82152360(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215296C"))) PPC_WEAK_FUNC(sub_8215296C);
PPC_FUNC_IMPL(__imp__sub_8215296C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152970"))) PPC_WEAK_FUNC(sub_82152970);
PPC_FUNC_IMPL(__imp__sub_82152970) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821529ac
	if (cr6.eq) goto loc_821529AC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821529c0
	if (!cr6.eq) goto loc_821529C0;
loc_821529AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r3,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r3.u8);
	// blr 
	return;
loc_821529C0:
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821529d4
	if (cr6.eq) goto loc_821529D4;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821529d8
	goto loc_821529D8;
loc_821529D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821529D8:
	// b 0x8213c758
	sub_8213C758(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821529DC"))) PPC_WEAK_FUNC(sub_821529DC);
PPC_FUNC_IMPL(__imp__sub_821529DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821529E0"))) PPC_WEAK_FUNC(sub_821529E0);
PPC_FUNC_IMPL(__imp__sub_821529E0) {
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
	// bl 0x821520d8
	ctx.lr = 0x82152A00;
	sub_821520D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82152a28
	if (cr6.eq) goto loc_82152A28;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82152a28
	if (cr6.eq) goto loc_82152A28;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82152A28;
	sub_8213F7A8(ctx, base);
loc_82152A28:
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

__attribute__((alias("__imp__sub_82152A44"))) PPC_WEAK_FUNC(sub_82152A44);
PPC_FUNC_IMPL(__imp__sub_82152A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152A48"))) PPC_WEAK_FUNC(sub_82152A48);
PPC_FUNC_IMPL(__imp__sub_82152A48) {
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
	ctx.lr = 0x82152A50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r27,84(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// bl 0x82152488
	ctx.lr = 0x82152A64;
	sub_82152488(ctx, base);
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82152b2c
	if (!cr6.gt) goto loc_82152B2C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// subfic r26,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r26.s64 = -72 - r30.s64;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82152A84:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82152b18
	if (cr6.eq) goto loc_82152B18;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82152b18
	if (cr6.eq) goto loc_82152B18;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82152ac8
	if (cr6.eq) goto loc_82152AC8;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82152acc
	goto loc_82152ACC;
loc_82152AC8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152ACC:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x82152AD8;
	sub_8213B7B0(ctx, base);
	// lbz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82152b08
	if (cr6.eq) goto loc_82152B08;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82152b0c
	goto loc_82152B0C;
loc_82152B08:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152B0C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x82152B14;
	sub_8213D890(ctx, base);
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82152B18:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// add r10,r26,r29
	ctx.r10.u64 = r26.u64 + r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x82152a84
	if (cr6.lt) goto loc_82152A84;
loc_82152B2C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82152B34"))) PPC_WEAK_FUNC(sub_82152B34);
PPC_FUNC_IMPL(__imp__sub_82152B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152B38"))) PPC_WEAK_FUNC(sub_82152B38);
PPC_FUNC_IMPL(__imp__sub_82152B38) {
	PPC_FUNC_PROLOGUE();
	// b 0x82152a48
	sub_82152A48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82152B3C"))) PPC_WEAK_FUNC(sub_82152B3C);
PPC_FUNC_IMPL(__imp__sub_82152B3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152B40"))) PPC_WEAK_FUNC(sub_82152B40);
PPC_FUNC_IMPL(__imp__sub_82152B40) {
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
	// bl 0x8213b968
	ctx.lr = 0x82152B58;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,21904
	ctx.r10.s64 = r11.s64 + 21904;
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

__attribute__((alias("__imp__sub_82152B7C"))) PPC_WEAK_FUNC(sub_82152B7C);
PPC_FUNC_IMPL(__imp__sub_82152B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152B80"))) PPC_WEAK_FUNC(sub_82152B80);
PPC_FUNC_IMPL(__imp__sub_82152B80) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r10,21904
	ctx.r9.s64 = ctx.r10.s64 + 21904;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82152bf4
	if (!cr6.eq) goto loc_82152BF4;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82152bf4
	if (cr6.eq) goto loc_82152BF4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82152bf4
	if (cr6.eq) goto loc_82152BF4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x82152BF4;
	sub_8214E5B8(ctx, base);
loc_82152BF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x82152BFC;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_82152C10"))) PPC_WEAK_FUNC(sub_82152C10);
PPC_FUNC_IMPL(__imp__sub_82152C10) {
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
	ctx.lr = 0x82152C18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82152c60
	if (cr6.eq) goto loc_82152C60;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82152c64
	goto loc_82152C64;
loc_82152C60:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152C64:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82152C6C;
	sub_8213B7B0(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82152c9c
	if (cr6.eq) goto loc_82152C9C;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82152ca0
	goto loc_82152CA0;
loc_82152C9C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152CA0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x82152CA8;
	sub_8213D890(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e4d8
	ctx.lr = 0x82152CB0;
	sub_8213E4D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82152CB8"))) PPC_WEAK_FUNC(sub_82152CB8);
PPC_FUNC_IMPL(__imp__sub_82152CB8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82152CC0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// lbz r7,5(r29)
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// li r31,1
	r31.s64 = 1;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplw cr6,r7,r28
	cr6.compare<uint32_t>(ctx.r7.u32, r28.u32, xer);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// blt cr6,0x82152cf8
	if (cr6.lt) goto loc_82152CF8;
	// li r31,0
	r31.s64 = 0;
loc_82152CF8:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82152d74
	if (cr6.eq) goto loc_82152D74;
	// clrlwi r5,r31,24
	ctx.r5.u64 = r31.u32 & 0xFF;
	// addi r6,r30,4
	ctx.r6.s64 = r30.s64 + 4;
loc_82152D0C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82152d54
	if (cr6.eq) goto loc_82152D54;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82152d44
	if (!cr6.gt) goto loc_82152D44;
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// addi r9,r29,6
	ctx.r9.s64 = r29.s64 + 6;
loc_82152D28:
	// lbzx r4,r9,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// extsb r3,r4
	ctx.r3.s64 = ctx.r4.s8;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// beq cr6,0x82152e14
	if (cr6.eq) goto loc_82152E14;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82152d28
	if (cr6.lt) goto loc_82152D28;
loc_82152D44:
	// li r11,0
	r11.s64 = 0;
loc_82152D48:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82152d64
	if (!cr6.eq) goto loc_82152D64;
loc_82152D54:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fadds f2,f0,f2
	ctx.f2.f64 = double(float(f0.f64 + ctx.f2.f64));
loc_82152D64:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// cmplw cr6,r8,r28
	cr6.compare<uint32_t>(ctx.r8.u32, r28.u32, xer);
	// blt cr6,0x82152d0c
	if (cr6.lt) goto loc_82152D0C;
loc_82152D74:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82145080
	ctx.lr = 0x82152D7C;
	sub_82145080(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82152e04
	if (cr6.eq) goto loc_82152E04;
	// clrlwi r5,r31,24
	ctx.r5.u64 = r31.u32 & 0xFF;
	// addi r6,r30,4
	ctx.r6.s64 = r30.s64 + 4;
loc_82152D90:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82152ddc
	if (cr6.eq) goto loc_82152DDC;
	// lbz r8,5(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 5);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82152dcc
	if (!cr6.gt) goto loc_82152DCC;
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// addi r9,r29,6
	ctx.r9.s64 = r29.s64 + 6;
loc_82152DB0:
	// lbzx r4,r9,r11
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// extsb r3,r4
	ctx.r3.s64 = ctx.r4.s8;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// beq cr6,0x82152e1c
	if (cr6.eq) goto loc_82152E1C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x82152db0
	if (cr6.lt) goto loc_82152DB0;
loc_82152DCC:
	// li r11,0
	r11.s64 = 0;
loc_82152DD0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82152df4
	if (!cr6.eq) goto loc_82152DF4;
loc_82152DDC:
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fsubs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x82152e24
	if (!cr6.gt) goto loc_82152E24;
loc_82152DF4:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// cmplw cr6,r7,r28
	cr6.compare<uint32_t>(ctx.r7.u32, r28.u32, xer);
	// blt cr6,0x82152d90
	if (cr6.lt) goto loc_82152D90;
loc_82152E04:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82152E14:
	// li r11,1
	r11.s64 = 1;
	// b 0x82152d48
	goto loc_82152D48;
loc_82152E1C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82152dd0
	goto loc_82152DD0;
loc_82152E24:
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82152E34"))) PPC_WEAK_FUNC(sub_82152E34);
PPC_FUNC_IMPL(__imp__sub_82152E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152E38"))) PPC_WEAK_FUNC(sub_82152E38);
PPC_FUNC_IMPL(__imp__sub_82152E38) {
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
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82152e7c
	if (cr6.eq) goto loc_82152E7C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82152e80
	goto loc_82152E80;
loc_82152E7C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82152E80:
	// bl 0x8213e040
	ctx.lr = 0x82152E84;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_82152EA4"))) PPC_WEAK_FUNC(sub_82152EA4);
PPC_FUNC_IMPL(__imp__sub_82152EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152EA8"))) PPC_WEAK_FUNC(sub_82152EA8);
PPC_FUNC_IMPL(__imp__sub_82152EA8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82152c10
	sub_82152C10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82152EAC"))) PPC_WEAK_FUNC(sub_82152EAC);
PPC_FUNC_IMPL(__imp__sub_82152EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152EB0"))) PPC_WEAK_FUNC(sub_82152EB0);
PPC_FUNC_IMPL(__imp__sub_82152EB0) {
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
	// bl 0x82152b80
	ctx.lr = 0x82152ED0;
	sub_82152B80(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82152ef8
	if (cr6.eq) goto loc_82152EF8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82152ef8
	if (cr6.eq) goto loc_82152EF8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82152EF8;
	sub_8213F7A8(ctx, base);
loc_82152EF8:
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

__attribute__((alias("__imp__sub_82152F14"))) PPC_WEAK_FUNC(sub_82152F14);
PPC_FUNC_IMPL(__imp__sub_82152F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82152F18"))) PPC_WEAK_FUNC(sub_82152F18);
PPC_FUNC_IMPL(__imp__sub_82152F18) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82152F20;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x82152F34;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82152f4c
	if (!cr6.eq) goto loc_82152F4C;
loc_82152F40:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82152F4C:
	// lwz r31,148(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// lwz r11,112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// rlwinm r10,r11,0,20,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC00;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r10,1024
	cr6.compare<uint32_t>(ctx.r10.u32, 1024, xer);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r11,6
	ctx.r10.s64 = r11.s64 + 6;
	// addi r27,r10,1
	r27.s64 = ctx.r10.s64 + 1;
	// lbz r29,6(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// bne cr6,0x82153020
	if (!cr6.eq) goto loc_82153020;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82152fb8
	if (cr6.eq) goto loc_82152FB8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82152F98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82152fb8
	if (cr6.eq) goto loc_82152FB8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82152fb8
	if (!cr6.lt) goto loc_82152FB8;
	// li r28,1
	r28.s64 = 1;
loc_82152FB8:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// lbz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82152ff0
	if (!cr6.eq) goto loc_82152FF0;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// divw r8,r9,r10
	ctx.r8.s32 = ctx.r9.s32 / ctx.r10.s32;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// subf r5,r7,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r7.s64;
	// andc r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 & ~ctx.r6.u64;
	// b 0x82153070
	goto loc_82153070;
loc_82152FF0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// twllei r11,0
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// divw r8,r9,r11
	ctx.r8.s32 = ctx.r9.s32 / r11.s32;
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// subf r5,r7,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r7.s64;
	// andc r4,r11,r6
	ctx.r4.u64 = r11.u64 & ~ctx.r6.u64;
	// b 0x82153074
	goto loc_82153074;
loc_82153020:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// clrlwi r5,r29,24
	ctx.r5.u64 = r29.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82152cb8
	ctx.lr = 0x82153034;
	sub_82152CB8(ctx, base);
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215307c
	if (cr6.eq) goto loc_8215307C;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stb r3,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r3.u8);
	// lbz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r8,r9,r10
	ctx.r8.s32 = ctx.r9.s32 / ctx.r10.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// andc r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 & ~ctx.r7.u64;
loc_82153070:
	// twllei r10,0
loc_82153074:
	// twlgei r4,-1
	// stb r5,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r5.u8);
loc_8215307C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// rlwinm r10,r3,3,21,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0x7F8;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// lwzx r4,r10,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// bl 0x82144720
	ctx.lr = 0x821530A0;
	sub_82144720(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r11,7216
	r11.s64 = r11.s64 + 7216;
	// beq cr6,0x821530dc
	if (cr6.eq) goto loc_821530DC;
	// lbz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,196(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// twllei r9,0
	// lwz r7,11440(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// subf r6,r7,r3
	ctx.r6.s64 = ctx.r3.s64 - ctx.r7.s64;
	// divwu r5,r6,r9
	ctx.r5.u32 = ctx.r6.u32 / ctx.r9.u32;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// b 0x821530e0
	goto loc_821530E0;
loc_821530DC:
	// li r10,255
	ctx.r10.s64 = 255;
loc_821530E0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,72(r30)
	PPC_STORE_U8(r30.u32 + 72, ctx.r10.u8);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82152f40
	if (cr6.eq) goto loc_82152F40;
	// lbz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82152f40
	if (cr6.eq) goto loc_82152F40;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82153128"))) PPC_WEAK_FUNC(sub_82153128);
PPC_FUNC_IMPL(__imp__sub_82153128) {
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
	// bl 0x8213b968
	ctx.lr = 0x82153140;
	sub_8213B968(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,255
	r11.s64 = 255;
	// addi r9,r10,22272
	ctx.r9.s64 = ctx.r10.s64 + 22272;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
	// stb r11,74(r31)
	PPC_STORE_U8(r31.u32 + 74, r11.u8);
	// stb r11,75(r31)
	PPC_STORE_U8(r31.u32 + 75, r11.u8);
	// stb r11,76(r31)
	PPC_STORE_U8(r31.u32 + 76, r11.u8);
	// stb r11,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r11.u8);
	// stb r11,78(r31)
	PPC_STORE_U8(r31.u32 + 78, r11.u8);
	// stb r11,79(r31)
	PPC_STORE_U8(r31.u32 + 79, r11.u8);
	// stb r8,168(r31)
	PPC_STORE_U8(r31.u32 + 168, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_82153190"))) PPC_WEAK_FUNC(sub_82153190);
PPC_FUNC_IMPL(__imp__sub_82153190) {
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
	ctx.lr = 0x82153198;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// addi r9,r11,22272
	ctx.r9.s64 = r11.s64 + 22272;
	// lwz r10,164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x82153218
	if (!cr6.gt) goto loc_82153218;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r28,r31,72
	r28.s64 = r31.s64 + 72;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
loc_821531C8:
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82153208
	if (cr6.eq) goto loc_82153208;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82153208
	if (cr6.eq) goto loc_82153208;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82153208;
	sub_8214E5B8(ctx, base);
loc_82153208:
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x821531c8
	if (cr6.lt) goto loc_821531C8;
loc_82153218:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x82153220;
	sub_8213BA48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82153228"))) PPC_WEAK_FUNC(sub_82153228);
PPC_FUNC_IMPL(__imp__sub_82153228) {
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
	ctx.lr = 0x82153230;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x82153244;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821533b4
	if (cr6.eq) goto loc_821533B4;
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r8,148(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r11,r27
	r11.u64 = r27.u64;
	// rlwinm r9,r9,0,20,21
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC00;
	// addi r7,r9,-1024
	ctx.r7.s64 = ctx.r9.s64 + -1024;
	// li r9,6
	ctx.r9.s64 = 6;
	// lbz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stb r4,169(r31)
	PPC_STORE_U8(r31.u32 + 169, ctx.r4.u8);
	// stw r6,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r6.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82153284:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82153284
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82153284;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x821533b4
	if (cr6.gt) goto loc_821533B4;
	// li r23,1
	r23.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821533a8
	if (cr6.eq) goto loc_821533A8;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r26,r31,156
	r26.s64 = r31.s64 + 156;
	// addi r28,r8,5
	r28.s64 = ctx.r8.s64 + 5;
	// addi r24,r31,72
	r24.s64 = r31.s64 + 72;
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// addi r25,r11,19856
	r25.s64 = r11.s64 + 19856;
loc_821532D0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_821532E0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x821532e0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821532E0;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r4,-4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -4);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r25,608
	ctx.r3.s64 = r25.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8215330C;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82153340
	if (cr6.eq) goto loc_82153340;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// b 0x82153344
	goto loc_82153344;
loc_82153340:
	// li r11,255
	r11.s64 = 255;
loc_82153344:
	// cmplwi cr6,r29,2
	cr6.compare<uint32_t>(r29.u32, 2, xer);
	// stbx r11,r24,r29
	PPC_STORE_U8(r24.u32 + r29.u32, r11.u8);
	// bge cr6,0x82153358
	if (!cr6.lt) goto loc_82153358;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_82153358:
	// lbzx r8,r24,r29
	ctx.r8.u64 = PPC_LOAD_U8(r24.u32 + r29.u32);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215338c
	if (cr6.eq) goto loc_8215338C;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82153390
	if (!cr6.eq) goto loc_82153390;
loc_8215338C:
	// li r23,0
	r23.s64 = 0;
loc_82153390:
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x821532d0
	if (cr6.lt) goto loc_821532D0;
loc_821533A8:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_821533B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821533C0"))) PPC_WEAK_FUNC(sub_821533C0);
PPC_FUNC_IMPL(__imp__sub_821533C0) {
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
	ctx.lr = 0x821533C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// lwz r27,84(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821534a0
	if (!cr6.gt) goto loc_821534A0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// subfic r26,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r26.s64 = -72 - r30.s64;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_821533F8:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215348c
	if (cr6.eq) goto loc_8215348C;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8215348c
	if (cr6.eq) goto loc_8215348C;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215343c
	if (cr6.eq) goto loc_8215343C;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82153440
	goto loc_82153440;
loc_8215343C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82153440:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x8215344C;
	sub_8213B7B0(ctx, base);
	// lbz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215347c
	if (cr6.eq) goto loc_8215347C;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82153480
	goto loc_82153480;
loc_8215347C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82153480:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x82153488;
	sub_8213D890(ctx, base);
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_8215348C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// add r10,r26,r29
	ctx.r10.u64 = r26.u64 + r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821533f8
	if (cr6.lt) goto loc_821533F8;
loc_821534A0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821534A8"))) PPC_WEAK_FUNC(sub_821534A8);
PPC_FUNC_IMPL(__imp__sub_821534A8) {
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
	ctx.lr = 0x821534B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// li r28,0
	r28.s64 = 0;
	// lwz r10,164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// ble cr6,0x821535ac
	if (!cr6.gt) goto loc_821535AC;
	// addi r29,r31,72
	r29.s64 = r31.s64 + 72;
	// subfic r27,r31,-72
	xer.ca = r31.u32 <= 4294967224;
	r27.s64 = -72 - r31.s64;
loc_821534E4:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82153598
	if (cr6.eq) goto loc_82153598;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82153598
	if (cr6.eq) goto loc_82153598;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82153528
	if (cr6.eq) goto loc_82153528;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x8215352c
	goto loc_8215352C;
loc_82153528:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8215352C:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82153570
	if (!cr6.eq) goto loc_82153570;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215354c
	if (cr6.eq) goto loc_8215354C;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82153550
	goto loc_82153550;
loc_8215354C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82153550:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213e040
	ctx.lr = 0x82153558;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82153598
	if (cr6.eq) goto loc_82153598;
	// li r28,1
	r28.s64 = 1;
	// b 0x82153598
	goto loc_82153598;
loc_82153570:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82153584
	if (cr6.eq) goto loc_82153584;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82153588
	goto loc_82153588;
loc_82153584:
	// li r11,0
	r11.s64 = 0;
loc_82153588:
	// lhz r11,6(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82153598
	if (!cr6.eq) goto loc_82153598;
	// li r25,1
	r25.s64 = 1;
loc_82153598:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// add r10,r27,r29
	ctx.r10.u64 = r27.u64 + r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821534e4
	if (cr6.lt) goto loc_821534E4;
loc_821535AC:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821535c4
	if (!cr6.eq) goto loc_821535C4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_821535C4:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82153694
	if (cr6.eq) goto loc_82153694;
	// lbz r11,169(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 169);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82153694
	if (cr6.eq) goto loc_82153694;
	// lbz r11,168(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82153694
	if (!cr6.eq) goto loc_82153694;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8215368c
	if (!cr6.gt) goto loc_8215368C;
	// addi r6,r31,72
	ctx.r6.s64 = r31.s64 + 72;
	// subfic r5,r31,-72
	xer.ca = r31.u32 <= 4294967224;
	ctx.r5.s64 = -72 - r31.s64;
loc_821535FC:
	// lbz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82153678
	if (cr6.eq) goto loc_82153678;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r7,r11,r7
	ctx.r7.u64 = r11.u64 + ctx.r7.u64;
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82153678
	if (cr6.eq) goto loc_82153678;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82153640
	if (cr6.eq) goto loc_82153640;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// b 0x82153644
	goto loc_82153644;
loc_82153640:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82153644:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82153678
	if (!cr6.eq) goto loc_82153678;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82153664
	if (cr6.eq) goto loc_82153664;
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82153668
	goto loc_82153668;
loc_82153664:
	// li r11,0
	r11.s64 = 0;
loc_82153668:
	// lbz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 56);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,56(r11)
	PPC_STORE_U8(r11.u32 + 56, ctx.r9.u8);
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82153678:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// add r10,r6,r5
	ctx.r10.u64 = ctx.r6.u64 + ctx.r5.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821535fc
	if (cr6.lt) goto loc_821535FC;
loc_8215368C:
	// li r11,1
	r11.s64 = 1;
	// stb r11,168(r31)
	PPC_STORE_U8(r31.u32 + 168, r11.u8);
loc_82153694:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821536A0"))) PPC_WEAK_FUNC(sub_821536A0);
PPC_FUNC_IMPL(__imp__sub_821536A0) {
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
	ctx.lr = 0x821536A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r24
	r28.u64 = r24.u64;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82153774
	if (!cr6.gt) goto loc_82153774;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// subfic r27,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r27.s64 = -72 - r30.s64;
	// li r25,1
	r25.s64 = 1;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_821536DC:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82153760
	if (cr6.eq) goto loc_82153760;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mullw r9,r8,r10
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r8,11440(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82153760
	if (cr6.eq) goto loc_82153760;
	// stb r24,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r24.u8);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82153730
	if (cr6.eq) goto loc_82153730;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r9,11440(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// mullw r11,r8,r10
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82153734
	goto loc_82153734;
loc_82153730:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82153734:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x8215373C;
	sub_8213C758(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82153754
	if (cr6.eq) goto loc_82153754;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82153754
	if (cr6.eq) goto loc_82153754;
	// stb r25,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r25.u8);
loc_82153754:
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// ble cr6,0x82153760
	if (!cr6.gt) goto loc_82153760;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_82153760:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// add r10,r27,r29
	ctx.r10.u64 = r27.u64 + r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821536dc
	if (cr6.lt) goto loc_821536DC;
loc_82153774:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82153780"))) PPC_WEAK_FUNC(sub_82153780);
PPC_FUNC_IMPL(__imp__sub_82153780) {
	PPC_FUNC_PROLOGUE();
	// b 0x821534a8
	sub_821534A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82153784"))) PPC_WEAK_FUNC(sub_82153784);
PPC_FUNC_IMPL(__imp__sub_82153784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82153788"))) PPC_WEAK_FUNC(sub_82153788);
PPC_FUNC_IMPL(__imp__sub_82153788) {
	PPC_FUNC_PROLOGUE();
	// b 0x821533c0
	sub_821533C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215378C"))) PPC_WEAK_FUNC(sub_8215378C);
PPC_FUNC_IMPL(__imp__sub_8215378C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82153790"))) PPC_WEAK_FUNC(sub_82153790);
PPC_FUNC_IMPL(__imp__sub_82153790) {
	PPC_FUNC_PROLOGUE();
	// b 0x821536a0
	sub_821536A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82153794"))) PPC_WEAK_FUNC(sub_82153794);
PPC_FUNC_IMPL(__imp__sub_82153794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82153798"))) PPC_WEAK_FUNC(sub_82153798);
PPC_FUNC_IMPL(__imp__sub_82153798) {
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
	// bl 0x82153190
	ctx.lr = 0x821537B8;
	sub_82153190(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821537e0
	if (cr6.eq) goto loc_821537E0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821537e0
	if (cr6.eq) goto loc_821537E0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x821537E0;
	sub_8213F7A8(ctx, base);
loc_821537E0:
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

__attribute__((alias("__imp__sub_821537FC"))) PPC_WEAK_FUNC(sub_821537FC);
PPC_FUNC_IMPL(__imp__sub_821537FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82153800"))) PPC_WEAK_FUNC(sub_82153800);
PPC_FUNC_IMPL(__imp__sub_82153800) {
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
	// bl 0x8213b968
	ctx.lr = 0x82153818;
	sub_8213B968(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,-1
	r11.s64 = -1;
	// addi r9,r10,22640
	ctx.r9.s64 = ctx.r10.s64 + 22640;
	// sth r11,170(r31)
	PPC_STORE_U16(r31.u32 + 170, r11.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// sth r11,168(r31)
	PPC_STORE_U16(r31.u32 + 168, r11.u16);
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

__attribute__((alias("__imp__sub_82153848"))) PPC_WEAK_FUNC(sub_82153848);
PPC_FUNC_IMPL(__imp__sub_82153848) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r10,22640
	ctx.r9.s64 = ctx.r10.s64 + 22640;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821538bc
	if (!cr6.eq) goto loc_821538BC;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821538bc
	if (cr6.eq) goto loc_821538BC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821538bc
	if (cr6.eq) goto loc_821538BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x821538BC;
	sub_8214E5B8(ctx, base);
loc_821538BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x821538C4;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_821538D8"))) PPC_WEAK_FUNC(sub_821538D8);
PPC_FUNC_IMPL(__imp__sub_821538D8) {
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
	ctx.lr = 0x821538E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x821538F4;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215390c
	if (!cr6.eq) goto loc_8215390C;
loc_82153900:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8215390C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r28,148(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r29,608
	ctx.r3.s64 = r29.s64 + 608;
	// bl 0x82143580
	ctx.lr = 0x8215392C;
	sub_82143580(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// beq cr6,0x82153968
	if (cr6.eq) goto loc_82153968;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// b 0x8215396c
	goto loc_8215396C;
loc_82153968:
	// li r11,255
	r11.s64 = 255;
loc_8215396C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82153900
	if (cr6.eq) goto loc_82153900;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r11,r9
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82153900
	if (cr6.eq) goto loc_82153900;
	// addi r3,r29,608
	ctx.r3.s64 = r29.s64 + 608;
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x821436c8
	ctx.lr = 0x821539B4;
	sub_821436C8(ctx, base);
	// sth r3,172(r31)
	PPC_STORE_U16(r31.u32 + 172, ctx.r3.u16);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// stw r11,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r11.u32);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82153a14
	if (cr6.eq) goto loc_82153A14;
	// bl 0x82137488
	ctx.lr = 0x821539D0;
	sub_82137488(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,168(r31)
	PPC_STORE_U16(r31.u32 + 168, ctx.r3.u16);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bne cr6,0x82153a14
	if (!cr6.eq) goto loc_82153A14;
	// lhz r3,172(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 172);
	// bl 0x82138788
	ctx.lr = 0x821539E8;
	sub_82138788(ctx, base);
	// bl 0x82137488
	ctx.lr = 0x821539EC;
	sub_82137488(ctx, base);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// sth r3,168(r31)
	PPC_STORE_U16(r31.u32 + 168, ctx.r3.u16);
	// extsh r3,r10
	ctx.r3.s64 = ctx.r10.s16;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x82153a0c
	if (!cr6.eq) goto loc_82153A0C;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x82153a14
	goto loc_82153A14;
loc_82153A0C:
	// bl 0x821374b0
	ctx.lr = 0x82153A10;
	sub_821374B0(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
loc_82153A14:
	// lhz r11,168(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 168);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82153b40
	if (cr6.eq) goto loc_82153B40;
	// lwz r29,164(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// bl 0x821374b0
	ctx.lr = 0x82153A2C;
	sub_821374B0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821380c8
	ctx.lr = 0x82153A34;
	sub_821380C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82153a54
	if (!cr6.eq) goto loc_82153A54;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82153A54:
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82153a84
	if (cr6.eq) goto loc_82153A84;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82153a88
	goto loc_82153A88;
loc_82153A84:
	// li r11,0
	r11.s64 = 0;
loc_82153A88:
	// lhz r10,26(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 26);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,212
	ctx.r5.s64 = 212;
	// sth r10,216(r11)
	PPC_STORE_U16(r11.u32 + 216, ctx.r10.u16);
	// lfs f0,8884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f13,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// lfs f12,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f11,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// fsel f4,f5,f13,f12
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fadds f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// fsubs f1,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fsubs f0,f2,f11
	f0.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// fsel f13,f1,f2,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.f12.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82153b30
	if (cr6.lt) goto loc_82153B30;
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82153B30:
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
loc_82153B40:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82153B4C"))) PPC_WEAK_FUNC(sub_82153B4C);
PPC_FUNC_IMPL(__imp__sub_82153B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82153B50"))) PPC_WEAK_FUNC(sub_82153B50);
PPC_FUNC_IMPL(__imp__sub_82153B50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r21{};
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
	ctx.lr = 0x82153B58;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lhz r11,168(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 168);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82153b80
	if (cr6.eq) goto loc_82153B80;
	// mr r26,r11
	r26.u64 = r11.u64;
	// b 0x82153b8c
	goto loc_82153B8C;
loc_82153B80:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82137488
	ctx.lr = 0x82153B88;
	sub_82137488(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_82153B8C:
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// beq cr6,0x82153db0
	if (cr6.eq) goto loc_82153DB0;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82153db0
	if (cr6.eq) goto loc_82153DB0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82153db0
	if (cr6.eq) goto loc_82153DB0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821374b0
	ctx.lr = 0x82153BD8;
	sub_821374B0(ctx, base);
	// lwz r5,164(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// lhz r4,172(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 172);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x821382d0
	ctx.lr = 0x82153BE8;
	sub_821382D0(ctx, base);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82153c14
	if (cr6.eq) goto loc_82153C14;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82153d64
	if (cr6.eq) goto loc_82153D64;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,28,30,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x2;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82153C14:
	// sth r26,170(r31)
	PPC_STORE_U16(r31.u32 + 170, r26.u16);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// bl 0x8214aa70
	ctx.lr = 0x82153C28;
	sub_8214AA70(ctx, base);
	// cmplwi cr6,r28,3
	cr6.compare<uint32_t>(r28.u32, 3, xer);
	// bgt cr6,0x82153db0
	if (cr6.gt) goto loc_82153DB0;
	// lis r12,-32235
	r12.s64 = -2112552960;
	// addi r12,r12,15432
	r12.s64 = r12.s64 + 15432;
	// rlwinm r0,r28,2,0,29
	r0.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r28.u64) {
	case 0:
		goto loc_82153C58;
	case 1:
		goto loc_82153D70;
	case 2:
		goto loc_82153DB0;
	case 3:
		goto loc_82153D7C;
	default:
		__builtin_unreachable();
	}
	// lwz r16,15448(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + 15448);
	// lwz r16,15728(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + 15728);
	// lwz r16,15792(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + 15792);
	// lwz r16,15740(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + 15740);
loc_82153C58:
	// lhz r11,168(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 168);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x82153d64
	if (!cr6.eq) goto loc_82153D64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// bl 0x821380c8
	ctx.lr = 0x82153C70;
	sub_821380C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82153db0
	if (cr6.eq) goto loc_82153DB0;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82153ca8
	if (cr6.eq) goto loc_82153CA8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82153cac
	goto loc_82153CAC;
loc_82153CA8:
	// li r11,0
	r11.s64 = 0;
loc_82153CAC:
	// lhz r10,26(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 26);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,212
	ctx.r5.s64 = 212;
	// sth r10,216(r11)
	PPC_STORE_U16(r11.u32 + 216, ctx.r10.u16);
	// lfs f0,8884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f13,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lfs f12,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// lfs f11,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * f0.f64));
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fdivs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// fsel f4,f5,f13,f12
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fadds f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// fsubs f1,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fsubs f0,f2,f11
	f0.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// fsel f13,f1,f2,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.f12.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82153d54
	if (cr6.lt) goto loc_82153D54;
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82153D54:
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
loc_82153D64:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82153D70:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82153D7C:
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82153db0
	if (cr6.eq) goto loc_82153DB0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r5,164(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// lhz r4,172(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 172);
	// bl 0x821381e0
	ctx.lr = 0x82153D9C;
	sub_821381E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,28,30,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x2;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82153DB0:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82153DBC"))) PPC_WEAK_FUNC(sub_82153DBC);
PPC_FUNC_IMPL(__imp__sub_82153DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82153DC0"))) PPC_WEAK_FUNC(sub_82153DC0);
PPC_FUNC_IMPL(__imp__sub_82153DC0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82153DE0;
	sub_821374B0(ctx, base);
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// bl 0x821380c8
	ctx.lr = 0x82153DE8;
	sub_821380C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82153e10
	if (!cr6.eq) goto loc_82153E10;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r10.u8);
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
loc_82153E10:
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82153e48
	if (cr6.eq) goto loc_82153E48;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82153e4c
	goto loc_82153E4C;
loc_82153E48:
	// li r11,0
	r11.s64 = 0;
loc_82153E4C:
	// lhz r10,26(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 26);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,212
	ctx.r5.s64 = 212;
	// sth r10,216(r11)
	PPC_STORE_U16(r11.u32 + 216, ctx.r10.u16);
	// lfs f0,8884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f13,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// lfs f12,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f11,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// fsel f4,f5,f13,f12
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fadds f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// fsubs f1,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fsubs f0,f2,f11
	f0.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// fsel f13,f1,f2,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.f12.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82153ee8
	if (cr6.lt) goto loc_82153EE8;
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// b 0x82153ef4
	goto loc_82153EF4;
loc_82153EE8:
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
loc_82153EF4:
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_82153F0C"))) PPC_WEAK_FUNC(sub_82153F0C);
PPC_FUNC_IMPL(__imp__sub_82153F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82153F10"))) PPC_WEAK_FUNC(sub_82153F10);
PPC_FUNC_IMPL(__imp__sub_82153F10) {
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
	ctx.lr = 0x82153F18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r9,r10,7216
	ctx.r9.s64 = ctx.r10.s64 + 7216;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r10,232(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 232);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r9,196(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// beq cr6,0x82153f60
	if (cr6.eq) goto loc_82153F60;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,11440(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// b 0x82153f64
	goto loc_82153F64;
loc_82153F60:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82153F64:
	// lbz r7,227(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 227);
	// lwz r8,212(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 212);
	// rlwinm r6,r7,0,26,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82153ff0
	if (cr6.eq) goto loc_82153FF0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82153fa0
	if (!cr6.gt) goto loc_82153FA0;
	// rotlwi r7,r4,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// divw r6,r4,r8
	ctx.r6.s32 = ctx.r4.s32 / ctx.r8.s32;
	// addi r5,r7,-1
	ctx.r5.s64 = ctx.r7.s64 + -1;
	// mullw r3,r6,r8
	ctx.r3.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// twllei r8,0
	// andc r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ~ctx.r5.u64;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// twlgei r8,-1
loc_82153FA0:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82153fe8
	if (cr6.eq) goto loc_82153FE8;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r30,r11,r9
	r30.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82153fe8
	if (cr6.eq) goto loc_82153FE8;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x82153FD4;
	sub_8213B7B0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213d890
	ctx.lr = 0x82153FE0;
	sub_8213D890(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e4d8
	ctx.lr = 0x82153FE8;
	sub_8213E4D8(ctx, base);
loc_82153FE8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82153FF0:
	// cmpw cr6,r8,r4
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r4.s32, xer);
	// bge cr6,0x82153fa0
	if (!cr6.lt) goto loc_82153FA0;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82153fe8
	if (cr6.eq) goto loc_82153FE8;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,11440(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82153fa0
	if (cr6.eq) goto loc_82153FA0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x8215402C;
	sub_8214E5B8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82154034"))) PPC_WEAK_FUNC(sub_82154034);
PPC_FUNC_IMPL(__imp__sub_82154034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82154038"))) PPC_WEAK_FUNC(sub_82154038);
PPC_FUNC_IMPL(__imp__sub_82154038) {
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
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82154088
	if (cr6.eq) goto loc_82154088;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215408c
	goto loc_8215408C;
loc_82154088:
	// li r31,0
	r31.s64 = 0;
loc_8215408C:
	// lbz r11,57(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 57);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821540ac
	if (cr6.eq) goto loc_821540AC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821540b4
	if (cr6.eq) goto loc_821540B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b5a0
	ctx.lr = 0x821540AC;
	sub_8213B5A0(ctx, base);
loc_821540AC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821540bc
	if (!cr6.eq) goto loc_821540BC;
loc_821540B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821540c8
	goto loc_821540C8;
loc_821540BC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213e040
	ctx.lr = 0x821540C8;
	sub_8213E040(ctx, base);
loc_821540C8:
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

__attribute__((alias("__imp__sub_821540E0"))) PPC_WEAK_FUNC(sub_821540E0);
PPC_FUNC_IMPL(__imp__sub_821540E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82154038
	sub_82154038(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821540E4"))) PPC_WEAK_FUNC(sub_821540E4);
PPC_FUNC_IMPL(__imp__sub_821540E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821540E8"))) PPC_WEAK_FUNC(sub_821540E8);
PPC_FUNC_IMPL(__imp__sub_821540E8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82153b50
	sub_82153B50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821540EC"))) PPC_WEAK_FUNC(sub_821540EC);
PPC_FUNC_IMPL(__imp__sub_821540EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821540F0"))) PPC_WEAK_FUNC(sub_821540F0);
PPC_FUNC_IMPL(__imp__sub_821540F0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82153f10
	sub_82153F10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821540F4"))) PPC_WEAK_FUNC(sub_821540F4);
PPC_FUNC_IMPL(__imp__sub_821540F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821540F8"))) PPC_WEAK_FUNC(sub_821540F8);
PPC_FUNC_IMPL(__imp__sub_821540F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82154130
	if (cr6.eq) goto loc_82154130;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154134
	goto loc_82154134;
loc_82154130:
	// li r11,0
	r11.s64 = 0;
loc_82154134:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82154148
	if (cr6.eq) goto loc_82154148;
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r9.u8);
loc_82154148:
	// lwz r3,212(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82154150"))) PPC_WEAK_FUNC(sub_82154150);
PPC_FUNC_IMPL(__imp__sub_82154150) {
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
	// bl 0x82153848
	ctx.lr = 0x82154170;
	sub_82153848(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82154198
	if (cr6.eq) goto loc_82154198;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82154198
	if (cr6.eq) goto loc_82154198;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82154198;
	sub_8213F7A8(ctx, base);
loc_82154198:
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

__attribute__((alias("__imp__sub_821541B4"))) PPC_WEAK_FUNC(sub_821541B4);
PPC_FUNC_IMPL(__imp__sub_821541B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

